# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.cpp"
# 1 "tests/convolutionFFT2D/convolutionFFT2D.cu"
# 61 "/usr/local/cuda4.1/cuda/include/device_types.h"
# 149 "/usr/lib/x86_64-linux-gnu/gcc/x86_64-linux-gnu/4.5.2/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/x86_64-linux-gnu/gcc/x86_64-linux-gnu/4.5.2/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda4.1/cuda/include/crt/host_runtime.h" 1 3
# 69 "/usr/local/cuda4.1/cuda/include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 1 3
# 56 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/device_types.h" 1 3
# 53 "/usr/local/cuda4.1/cuda/include/device_types.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/host_defines.h" 1 3
# 54 "/usr/local/cuda4.1/cuda/include/device_types.h" 2 3







enum cudaRoundMode
{
    cudaRoundNearest,
    cudaRoundZero,
    cudaRoundPosInf,
    cudaRoundMinInf
};
# 57 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda4.1/cuda/include/driver_types.h" 1 3
# 125 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
enum cudaError
{





    cudaSuccess = 0,





    cudaErrorMissingConfiguration = 1,





    cudaErrorMemoryAllocation = 2,





    cudaErrorInitializationError = 3,
# 160 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorLaunchFailure = 4,
# 169 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorPriorLaunchFailure = 5,
# 179 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorLaunchTimeout = 6,
# 188 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorLaunchOutOfResources = 7,





    cudaErrorInvalidDeviceFunction = 8,
# 203 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
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
# 284 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorAddressOfConstant = 22,
# 293 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorTextureFetchFailed = 23,
# 302 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorTextureNotBound = 24,
# 311 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorSynchronizationError = 25,





    cudaErrorInvalidFilterSetting = 26,





    cudaErrorInvalidNormSetting = 27,







    cudaErrorMixedDeviceExecution = 28,






    cudaErrorCudartUnloading = 29,




    cudaErrorUnknown = 30,







    cudaErrorNotYetImplemented = 31,
# 360 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorMemoryValueTooLarge = 32,






    cudaErrorInvalidResourceHandle = 33,







    cudaErrorNotReady = 34,






    cudaErrorInsufficientDriver = 35,
# 395 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
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
# 457 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorDevicesUnavailable = 46,




    cudaErrorInvalidKernelImage = 47,







    cudaErrorNoKernelImageForDevice = 48,
# 483 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
    cudaErrorIncompatibleDriverContext = 49,






    cudaErrorPeerAccessAlreadyEnabled = 50,






    cudaErrorPeerAccessNotEnabled = 51,





    cudaErrorDeviceAlreadyInUse = 54,







    cudaErrorProfilerDisabled = 55,






    cudaErrorProfilerNotInitialized = 56,






    cudaErrorProfilerAlreadyStarted = 57,





     cudaErrorProfilerAlreadyStopped = 58,







    cudaErrorAssert = 59,






    cudaErrorTooManyPeers = 60,





    cudaErrorHostMemoryAlreadyRegistered = 61,





    cudaErrorHostMemoryNotRegistered = 62,




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
    cudaMemoryTypeDevice = 2
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
    cudaGraphicsRegisterFlagsSurfaceLoadStore = 4,
    cudaGraphicsRegisterFlagsTextureGather = 8
};




enum cudaGraphicsMapFlags
{
    cudaGraphicsMapFlagsNone = 0,
    cudaGraphicsMapFlagsReadOnly = 1,
    cudaGraphicsMapFlagsWriteDiscard = 2
};




enum cudaGraphicsCubeFace
{
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
# 752 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
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
    cudaFuncCachePreferL1 = 2,
    cudaFuncCachePreferEqual = 3
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
    size_t texturePitchAlignment;
    int deviceOverlap;
    int multiProcessorCount;
    int kernelExecTimeoutEnabled;
    int integrated;
    int canMapHostMemory;
    int computeMode;
    int maxTexture1D;
    int maxTexture1DLinear;
    int maxTexture2D[2];
    int maxTexture2DLinear[3];
    int maxTexture2DGather[2];
    int maxTexture3D[3];
    int maxTextureCubemap;
    int maxTexture1DLayered[2];
    int maxTexture2DLayered[3];
    int maxTextureCubemapLayered[2];
    int maxSurface1D;
    int maxSurface2D[2];
    int maxSurface3D[3];
    int maxSurface1DLayered[2];
    int maxSurface2DLayered[3];
    int maxSurfaceCubemap;
    int maxSurfaceCubemapLayered[2];
    size_t surfaceAlignment;
    int concurrentKernels;
    int ECCEnabled;
    int pciBusID;
    int pciDeviceID;
    int pciDomainID;
    int tccDriver;
    int asyncEngineCount;
    int unifiedAddressing;
    int memoryClockRate;
    int memoryBusWidth;
    int l2CacheSize;
    int maxThreadsPerMultiProcessor;
};
# 976 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
struct cudaIpcEventHandle_st
{
    char reserved[64];
};

struct cudaIpcMemHandle_st
{
    char reserved[64];
};
# 995 "/usr/local/cuda4.1/cuda/include/driver_types.h" 3
typedef enum cudaError cudaError_t;




typedef struct CUstream_st *cudaStream_t;




typedef struct CUevent_st *cudaEvent_t;




typedef struct cudaGraphicsResource *cudaGraphicsResource_t;




typedef struct CUuuid_st cudaUUID_t;




typedef struct cudaIpcEventHandle_st cudaIpcEventHandle_t;
typedef struct cudaIpcMemHandle_st cudaIpcMemHandle_t;




typedef enum cudaOutputMode cudaOutputMode_t;
# 58 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda4.1/cuda/include/surface_types.h" 1 3
# 84 "/usr/local/cuda4.1/cuda/include/surface_types.h" 3
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
# 59 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda4.1/cuda/include/texture_types.h" 1 3
# 84 "/usr/local/cuda4.1/cuda/include/texture_types.h" 3
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
# 60 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda4.1/cuda/include/vector_types.h" 1 3
# 59 "/usr/local/cuda4.1/cuda/include/vector_types.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 1 3
# 60 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/vector_types.h" 1 3
# 60 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 2 3
# 60 "/usr/local/cuda4.1/cuda/include/vector_types.h" 2 3
# 94 "/usr/local/cuda4.1/cuda/include/vector_types.h" 3
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
# 338 "/usr/local/cuda4.1/cuda/include/vector_types.h" 3
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







struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int vx = 1, unsigned int vy = 1, unsigned int vz = 1) : x(vx), y(vy), z(vz) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};

typedef struct dim3 dim3;
# 60 "/usr/local/cuda4.1/cuda/include/builtin_types.h" 2 3
# 70 "/usr/local/cuda4.1/cuda/include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda4.1/cuda/include/crt/storage_class.h" 1 3
# 71 "/usr/local/cuda4.1/cuda/include/crt/host_runtime.h" 2 3
# 213 "/usr/lib/x86_64-linux-gnu/gcc/x86_64-linux-gnu/4.5.2/include/stddef.h" 2 3
# 125 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 577 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 588 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 600 "/usr/local/cuda4.1/cuda/include/driver_types.h"
struct cudaArray;
# 605 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 614 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 627 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 639 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 650 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 660 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 677 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 695 "/usr/local/cuda4.1/cuda/include/driver_types.h"
struct cudaGraphicsResource;
# 700 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 712 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 722 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 735 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 770 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 820 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 831 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 842 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 852 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 861 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 976 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 981 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 995 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 1000 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 1005 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 1010 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 1015 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 1020 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 1021 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 1026 "/usr/local/cuda4.1/cuda/include/driver_types.h"
# 84 "/usr/local/cuda4.1/cuda/include/surface_types.h"
# 94 "/usr/local/cuda4.1/cuda/include/surface_types.h"
# 103 "/usr/local/cuda4.1/cuda/include/surface_types.h"
# 84 "/usr/local/cuda4.1/cuda/include/texture_types.h"
# 95 "/usr/local/cuda4.1/cuda/include/texture_types.h"
# 104 "/usr/local/cuda4.1/cuda/include/texture_types.h"
# 113 "/usr/local/cuda4.1/cuda/include/texture_types.h"
# 94 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 99 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 105 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 110 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 115 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 120 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 125 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 130 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 135 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 140 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 145 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 150 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 155 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 160 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 165 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 166 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 168 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 173 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 178 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 179 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 181 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 186 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 191 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 196 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 201 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 206 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 216 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 221 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 228 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 233 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 238 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 243 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 248 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 253 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 255 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 260 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 265 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 270 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 275 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 280 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 285 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 290 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 295 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 300 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 305 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 310 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 315 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 320 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 338 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 339 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 340 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 341 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 342 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 343 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 344 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 345 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 346 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 347 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 348 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 349 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 350 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 351 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 352 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 353 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 354 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 355 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 356 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 357 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 358 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 359 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 360 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 361 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 362 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 363 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 364 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 365 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 366 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 367 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 368 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 369 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 370 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 371 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 372 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 373 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 374 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 375 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 376 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 377 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 378 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 379 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 380 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 381 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 382 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 383 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 384 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 385 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 393 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 403 "/usr/local/cuda4.1/cuda/include/vector_types.h"
# 134 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceReset();
# 151 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceSynchronize();
# 203 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceSetLimit(cudaLimit , size_t );
# 227 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceGetLimit(size_t * , cudaLimit );
# 257 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceGetCacheConfig(cudaFuncCache * );
# 298 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceSetCacheConfig(cudaFuncCache );
# 321 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceGetByPCIBusId(int * , char * );
# 348 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceGetPCIBusId(char * , int , int );
# 387 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaIpcGetEventHandle(cudaIpcEventHandle_t * , cudaEvent_t );
# 419 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaIpcOpenEventHandle(cudaEvent_t * , cudaIpcEventHandle_t );
# 454 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaIpcGetMemHandle(cudaIpcMemHandle_t * , void * );
# 492 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaIpcOpenMemHandle(void ** , cudaIpcMemHandle_t );
# 519 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaIpcCloseMemHandle(void * );
# 553 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 577 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 636 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetLimit(cudaLimit , size_t );
# 667 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetLimit(size_t * , cudaLimit );
# 702 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetCacheConfig(cudaFuncCache * );
# 748 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetCacheConfig(cudaFuncCache );
# 800 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 841 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeekAtLastError();
# 855 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t );
# 885 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int * );
# 1088 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp * , int );
# 1107 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int * , const cudaDeviceProp * );
# 1140 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int );
# 1157 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int * );
# 1186 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int * , int );
# 1246 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(unsigned );
# 1272 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t * );
# 1293 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t );
# 1329 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamWaitEvent(cudaStream_t , cudaEvent_t , unsigned );
# 1348 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t );
# 1366 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t );
# 1398 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t * );
# 1429 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t * , unsigned );
# 1462 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t , cudaStream_t = 0);
# 1491 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t );
# 1523 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t );
# 1548 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t );
# 1589 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float * , cudaEvent_t , cudaEvent_t );
# 1628 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3 , dim3 , size_t = (0), cudaStream_t = 0);
# 1655 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void * , size_t , size_t );
# 1701 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncSetCacheConfig(const char * , cudaFuncCache );
# 1736 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char * );
# 1769 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * , const char * );
# 1791 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double * );
# 1813 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double * );
# 1845 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void ** , size_t );
# 1874 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void ** , size_t );
# 1913 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void ** , size_t * , size_t , size_t );
# 1955 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray ** , const cudaChannelFormatDesc * , size_t , size_t = (0), unsigned = (0));
# 1979 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void * );
# 1999 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void * );
# 2021 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray * );
# 2080 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void ** , size_t , unsigned );
# 2136 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostRegister(void * , size_t , unsigned );
# 2155 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostUnregister(void * );
# 2182 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void ** , void * , unsigned );
# 2201 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned * , void * );
# 2236 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr * , cudaExtent );
# 2336 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray ** , const cudaChannelFormatDesc * , cudaExtent , unsigned = (0));
# 2433 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms * );
# 2460 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DPeer(const cudaMemcpy3DPeerParms * );
# 2565 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms * , cudaStream_t = 0);
# 2586 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DPeerAsync(const cudaMemcpy3DPeerParms * , cudaStream_t = 0);
# 2605 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t * , size_t * );
# 2638 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void * , const void * , size_t , cudaMemcpyKind );
# 2669 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyPeer(void * , int , const void * , int , size_t );
# 2702 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray * , size_t , size_t , const void * , size_t , cudaMemcpyKind );
# 2735 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void * , const cudaArray * , size_t , size_t , size_t , cudaMemcpyKind );
# 2770 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray * , size_t , size_t , const cudaArray * , size_t , size_t , size_t , cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2812 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void * , size_t , const void * , size_t , size_t , size_t , cudaMemcpyKind );
# 2853 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray * , size_t , size_t , const void * , size_t , size_t , size_t , cudaMemcpyKind );
# 2894 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void * , size_t , const cudaArray * , size_t , size_t , size_t , size_t , cudaMemcpyKind );
# 2933 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray * , size_t , size_t , const cudaArray * , size_t , size_t , size_t , size_t , cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2968 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char * , const void * , size_t , size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 3002 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void * , const char * , size_t , size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 3045 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void * , const void * , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3075 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyPeerAsync(void * , int , const void * , int , size_t , cudaStream_t = 0);
# 3117 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray * , size_t , size_t , const void * , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3159 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void * , const cudaArray * , size_t , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3210 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void * , size_t , const void * , size_t , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3260 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray * , size_t , size_t , const void * , size_t , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3310 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void * , size_t , const cudaArray * , size_t , size_t , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3354 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char * , const void * , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3397 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void * , const char * , size_t , size_t , cudaMemcpyKind , cudaStream_t = 0);
# 3419 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void * , int , size_t );
# 3445 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void * , size_t , int , size_t , size_t );
# 3484 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr , int , cudaExtent );
# 3511 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemsetAsync(void * , int , size_t , cudaStream_t = 0);
# 3543 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2DAsync(void * , size_t , int , size_t , size_t , cudaStream_t = 0);
# 3588 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3DAsync(cudaPitchedPtr , int , cudaExtent , cudaStream_t = 0);
# 3615 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void ** , const char * );
# 3638 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t * , const char * );
# 3783 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPointerGetAttributes(cudaPointerAttributes * , void * );
# 3817 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceCanAccessPeer(int * , int , int );
# 3858 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceEnablePeerAccess(int , unsigned );
# 3883 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDeviceDisablePeerAccess(int );
# 3929 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t );
# 3961 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t , unsigned );
# 3996 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int , cudaGraphicsResource_t * , cudaStream_t = 0);
# 4027 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int , cudaGraphicsResource_t * , cudaStream_t = 0);
# 4056 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void ** , size_t * , cudaGraphicsResource_t );
# 4090 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray ** , cudaGraphicsResource_t , unsigned , unsigned );
# 4123 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc * , const cudaArray * );
# 4158 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int , int , int , int , cudaChannelFormatKind );
# 4205 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t * , const textureReference * , const void * , const cudaChannelFormatDesc * , size_t = (((2147483647) * 2U) + 1U));
# 4256 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t * , const textureReference * , const void * , const cudaChannelFormatDesc * , size_t , size_t , size_t );
# 4284 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference * , const cudaArray * , const cudaChannelFormatDesc * );
# 4305 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference * );
# 4330 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t * , const textureReference * );
# 4354 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference ** , const char * );
# 4387 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference * , const cudaArray * , const cudaChannelFormatDesc * );
# 4405 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference ** , const char * );
# 4432 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int * );
# 4449 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int * );
# 4454 "/usr/local/cuda4.1/cuda/include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetExportTable(const void ** , const cudaUUID_t * );
# 107 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template< class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 108 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 109 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 110 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 112 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf()
# 113 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 114 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 116 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 117 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 119 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1()
# 120 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 121 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 123 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 124 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 126 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2()
# 127 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 128 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 130 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 131 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 133 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4()
# 134 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 135 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 137 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 138 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 140 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 141 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 142 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(char)) * 8);
# 147 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 149 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 151 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 152 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 153 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 155 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 156 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 158 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 159 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 160 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 162 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 163 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 165 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 166 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 167 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 169 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 170 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 172 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 173 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 174 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 176 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 177 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 179 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 180 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 181 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 183 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 184 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 186 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 187 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 188 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 190 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 191 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 193 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 194 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 195 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 197 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 198 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 200 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 201 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 202 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 204 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 205 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 207 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 208 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 209 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 211 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 212 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 214 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 215 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 216 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 218 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 219 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 221 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 222 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 223 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 225 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 226 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 228 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 229 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 230 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 232 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 233 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 235 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 236 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 237 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 239 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 240 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 242 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 243 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 244 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 246 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 247 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 249 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 250 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 251 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 253 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 254 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 256 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 257 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 258 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 260 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 261 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 263 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 264 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 265 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 267 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 268 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 270 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 271 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 272 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 274 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 275 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 277 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 278 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 279 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 281 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 282 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 284 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 285 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 286 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 288 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 289 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 291 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 292 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 293 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 295 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 296 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 298 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 299 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 300 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 302 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 303 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 305 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 306 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 307 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 309 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 310 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 312 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 313 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 314 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 316 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 317 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 379 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 380 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 381 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 383 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 384 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 386 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 387 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 388 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 390 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 391 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 393 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 394 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 395 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 397 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 398 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 400 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 401 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
{
# 402 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 404 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 405 "/usr/local/cuda4.1/cuda/include/channel_descriptor.h"
}
# 79 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 80 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
{
# 81 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
cudaPitchedPtr s;
# 83 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(s.ptr) = d;
# 84 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(s.pitch) = p;
# 85 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(s.xsize) = xsz;
# 86 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(s.ysize) = ysz;
# 88 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
return s;
# 89 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
}
# 106 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 107 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
{
# 108 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
cudaPos p;
# 110 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(p.x) = x;
# 111 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(p.y) = y;
# 112 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(p.z) = z;
# 114 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
return p;
# 115 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
}
# 132 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 133 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
{
# 134 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
cudaExtent e;
# 136 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(e.width) = w;
# 137 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(e.height) = h;
# 138 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
(e.depth) = d;
# 140 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
return e;
# 141 "/usr/local/cuda4.1/cuda/include/driver_functions.h"
}
# 69 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 70 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 71 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
char1 t; (t.x) = x; return t;
# 72 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 74 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 75 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 76 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
uchar1 t; (t.x) = x; return t;
# 77 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 79 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 80 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 81 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
char2 t; (t.x) = x; (t.y) = y; return t;
# 82 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 84 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 85 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 86 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
uchar2 t; (t.x) = x; (t.y) = y; return t;
# 87 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 89 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 90 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 91 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 92 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 94 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 95 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 96 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 97 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 99 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 100 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 101 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 102 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 104 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 105 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 106 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 107 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 109 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline short1 make_short1(short x)
# 110 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 111 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
short1 t; (t.x) = x; return t;
# 112 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 114 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 115 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 116 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ushort1 t; (t.x) = x; return t;
# 117 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 119 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 120 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 121 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
short2 t; (t.x) = x; (t.y) = y; return t;
# 122 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 124 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 125 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 126 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ushort2 t; (t.x) = x; (t.y) = y; return t;
# 127 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 129 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 130 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 131 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 132 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 134 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 135 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 136 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 137 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 139 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 140 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 141 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 142 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 144 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 145 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 146 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 147 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 149 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline int1 make_int1(int x)
# 150 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 151 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
int1 t; (t.x) = x; return t;
# 152 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 154 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 155 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 156 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
uint1 t; (t.x) = x; return t;
# 157 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 159 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 160 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 161 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
int2 t; (t.x) = x; (t.y) = y; return t;
# 162 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 164 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 165 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 166 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
uint2 t; (t.x) = x; (t.y) = y; return t;
# 167 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 169 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 170 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 171 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 172 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 174 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 175 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 176 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 177 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 179 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 180 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 181 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 182 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 184 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 185 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 186 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 187 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 189 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline long1 make_long1(long x)
# 190 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 191 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
long1 t; (t.x) = x; return t;
# 192 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 194 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 195 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 196 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ulong1 t; (t.x) = x; return t;
# 197 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 199 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 200 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 201 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
long2 t; (t.x) = x; (t.y) = y; return t;
# 202 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 204 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 205 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 206 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ulong2 t; (t.x) = x; (t.y) = y; return t;
# 207 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 209 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline long3 make_long3(long x, long y, long z)
# 210 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 211 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 212 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 214 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z)
# 215 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 216 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 217 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 219 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline long4 make_long4(long x, long y, long z, long w)
# 220 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 221 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 222 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 224 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w)
# 225 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 226 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 227 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 229 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline float1 make_float1(float x)
# 230 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 231 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
float1 t; (t.x) = x; return t;
# 232 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 234 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 235 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 236 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
float2 t; (t.x) = x; (t.y) = y; return t;
# 237 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 239 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 240 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 241 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 242 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 244 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 245 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 246 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 247 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 249 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 250 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 251 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
longlong1 t; (t.x) = x; return t;
# 252 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 254 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 255 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 256 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ulonglong1 t; (t.x) = x; return t;
# 257 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 259 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 260 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 261 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
longlong2 t; (t.x) = x; (t.y) = y; return t;
# 262 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 264 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 265 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 266 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 267 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 269 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline longlong3 make_longlong3(long long x, long long y, long long z)
# 270 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 271 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 272 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 274 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z)
# 275 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 276 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 277 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 279 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w)
# 280 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 281 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 282 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 284 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w)
# 285 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 286 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 287 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 289 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline double1 make_double1(double x)
# 290 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 291 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
double1 t; (t.x) = x; return t;
# 292 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 294 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 295 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 296 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
double2 t; (t.x) = x; (t.y) = y; return t;
# 297 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 299 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline double3 make_double3(double x, double y, double z)
# 300 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 301 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 302 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
}
# 304 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
static inline double4 make_double4(double x, double y, double z, double w)
# 305 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
{
# 306 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 307 "/usr/local/cuda4.1/cuda/include/vector_functions.h"
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
# 69 "/usr/local/cuda4.1/cuda/include/common_functions.h"
extern "C" clock_t clock() throw();
# 70 "/usr/local/cuda4.1/cuda/include/common_functions.h"
extern "C" void *memset(void *, int, size_t) throw();
# 71 "/usr/local/cuda4.1/cuda/include/common_functions.h"
extern "C" void *memcpy(void *, const void *, size_t) throw();
# 160 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int abs(int) throw();
# 161 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long labs(long) throw();
# 162 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long long llabs(long long) throw();
# 175 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double fabs(double ) throw();
# 188 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float fabsf(float ) throw();
# 189 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int min(int, int);
# 190 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" unsigned umin(unsigned, unsigned);
# 191 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long long llmin(long long, long long);
# 192 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" unsigned long long ullmin(unsigned long long, unsigned long long);
# 208 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float fminf(float , float ) throw();
# 224 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double fmin(double , double ) throw();
# 225 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int max(int, int);
# 226 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" unsigned umax(unsigned, unsigned);
# 227 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long long llmax(long long, long long);
# 228 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" unsigned long long ullmax(unsigned long long, unsigned long long);
# 244 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float fmaxf(float , float ) throw();
# 260 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double fmax(double, double) throw();
# 273 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double sin(double ) throw();
# 286 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double cos(double ) throw();
# 301 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" void sincos(double , double * , double * ) throw();
# 317 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" void sincosf(float , float * , float * ) throw();
# 330 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double tan(double ) throw();
# 345 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double sqrt(double ) throw();
# 360 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double rsqrt(double );
# 375 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float rsqrtf(float );
# 390 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double log2(double ) throw();
# 401 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double exp2(double ) throw();
# 412 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float exp2f(float ) throw();
# 423 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double exp10(double ) throw();
# 435 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float exp10f(float ) throw();
# 446 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double expm1(double ) throw();
# 457 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float expm1f(float ) throw();
# 472 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float log2f(float ) throw();
# 487 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double log10(double ) throw();
# 502 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double log(double ) throw();
# 517 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double log1p(double ) throw();
# 532 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float log1pf(float ) throw();
# 546 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double floor(double ) throw();
# 557 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double exp(double ) throw();
# 570 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double cosh(double ) throw();
# 582 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double sinh(double ) throw();
# 594 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double tanh(double ) throw();
# 608 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double acosh(double ) throw();
# 622 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float acoshf(float ) throw();
# 634 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double asinh(double ) throw();
# 646 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float asinhf(float ) throw();
# 660 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double atanh(double ) throw();
# 674 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float atanhf(float ) throw();
# 686 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double ldexp(double , int ) throw();
# 698 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float ldexpf(float , int ) throw();
# 711 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double logb(double ) throw();
# 724 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float logbf(float ) throw();
# 742 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int ilogb(double ) throw();
# 760 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int ilogbf(float ) throw();
# 774 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double scalbn(double , int ) throw();
# 788 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float scalbnf(float , int ) throw();
# 802 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double scalbln(double , long ) throw();
# 816 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float scalblnf(float , long ) throw();
# 837 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double frexp(double , int * ) throw();
# 858 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float frexpf(float , int * ) throw();
# 871 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double round(double ) throw();
# 884 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float roundf(float ) throw();
# 898 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long lround(double ) throw();
# 912 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long lroundf(float ) throw();
# 926 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long long llround(double ) throw();
# 940 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long long llroundf(float ) throw();
# 951 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double rint(double ) throw();
# 962 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float rintf(float ) throw();
# 974 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long lrint(double ) throw();
# 986 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long lrintf(float ) throw();
# 998 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long long llrint(double ) throw();
# 1010 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" long long llrintf(float ) throw();
# 1023 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double nearbyint(double ) throw();
# 1036 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float nearbyintf(float ) throw();
# 1048 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double ceil(double ) throw();
# 1059 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double trunc(double ) throw();
# 1070 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float truncf(float ) throw();
# 1084 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double fdim(double , double ) throw();
# 1098 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float fdimf(float , float ) throw();
# 1113 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double atan2(double , double ) throw();
# 1126 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double atan(double ) throw();
# 1140 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double acos(double ) throw();
# 1154 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double asin(double ) throw();
# 1169 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double hypot(double , double ) throw();
# 1186 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float hypotf(float , float ) throw();
# 1200 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double cbrt(double ) throw();
# 1214 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float cbrtf(float ) throw();
# 1227 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double rcbrt(double );
# 1240 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float rcbrtf(float );
# 1254 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double sinpi(double );
# 1268 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float sinpif(float );
# 1282 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double cospi(double );
# 1296 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float cospif(float );
# 1324 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double pow(double , double ) throw();
# 1341 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double modf(double , double * ) throw();
# 1361 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double fmod(double , double ) throw();
# 1379 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double remainder(double , double ) throw();
# 1398 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float remainderf(float , float ) throw();
# 1417 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double remquo(double , double , int * ) throw();
# 1436 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float remquof(float , float , int * ) throw();
# 1451 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double j0(double ) throw();
# 1466 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float j0f(float ) throw();
# 1482 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double j1(double ) throw();
# 1498 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float j1f(float ) throw();
# 1514 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double jn(int , double ) throw();
# 1530 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float jnf(int , float ) throw();
# 1547 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double y0(double ) throw();
# 1564 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float y0f(float ) throw();
# 1581 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double y1(double ) throw();
# 1598 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float y1f(float ) throw();
# 1616 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double yn(int , double ) throw();
# 1634 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float ynf(int , float ) throw();
# 1648 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double erf(double ) throw();
# 1662 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float erff(float ) throw();
# 1677 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double erfinv(double );
# 1692 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float erfinvf(float );
# 1706 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double erfc(double ) throw();
# 1720 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float erfcf(float ) throw();
# 1738 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double lgamma(double ) throw();
# 1753 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double erfcinv(double );
# 1768 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float erfcinvf(float );
# 1778 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double erfcx(double );
# 1788 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float erfcxf(float );
# 1806 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float lgammaf(float ) throw();
# 1824 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double tgamma(double ) throw();
# 1842 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float tgammaf(float ) throw();
# 1851 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double copysign(double , double ) throw();
# 1860 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float copysignf(float , float ) throw();
# 1875 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double nextafter(double , double ) throw();
# 1890 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float nextafterf(float , float ) throw();
# 1902 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double nan(const char * ) throw();
# 1914 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float nanf(const char * ) throw();
# 1915 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __isinff(float) throw();
# 1916 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __isnanf(float) throw();
# 1925 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __finite(double) throw();
# 1926 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __finitef(float) throw();
# 1927 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __signbit(double) throw();
# 1928 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __isnan(double) throw();
# 1929 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __isinf(double) throw();
# 1932 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __signbitf(float) throw();
# 1949 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" double fma(double , double , double ) throw();
# 1966 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float fmaf(float , float , float ) throw();
# 1971 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __signbitl(long double) throw();
# 1977 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __finitel(long double) throw();
# 1978 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __isinfl(long double) throw();
# 1979 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" int __isnanl(long double) throw();
# 2017 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float acosf(float ) throw();
# 2031 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float asinf(float ) throw();
# 2045 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float atanf(float ) throw();
# 2060 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float atan2f(float , float ) throw();
# 2074 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float cosf(float ) throw();
# 2088 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float sinf(float ) throw();
# 2102 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float tanf(float ) throw();
# 2116 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float coshf(float ) throw();
# 2129 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float sinhf(float ) throw();
# 2141 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float tanhf(float ) throw();
# 2156 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float logf(float ) throw();
# 2168 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float expf(float ) throw();
# 2183 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float log10f(float ) throw();
# 2199 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float modff(float , float * ) throw();
# 2227 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float powf(float , float ) throw();
# 2242 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float sqrtf(float ) throw();
# 2254 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float ceilf(float ) throw();
# 2268 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float floorf(float ) throw();
# 2288 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern "C" float fmodf(float , float ) throw();
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
# 83 "/usr/include/bits/mathcalls.h" 3
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
# 83 "/usr/include/bits/mathcalls.h" 3
extern "C" void sincosl(long double , long double * , long double * ) throw();
# 83 "/usr/include/bits/mathcalls.h" 3
extern "C" void __sincosl(long double , long double * , long double * ) throw();
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
# 69 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) {
# 71 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Iterator, class _Container> class __normal_iterator;
# 74 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
}
# 76 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
namespace std __attribute((__visibility__("default"))) {
# 78 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __true_type { };
# 79 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __false_type { };
# 81 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< bool __T0>
# 82 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __truth_type {
# 83 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type; };
# 86 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __truth_type< true> {
# 87 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type; };
# 91 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Sp, class _Tp>
# 92 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __traitor {
# 94 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = ((bool)_Sp::__value) || ((bool)_Tp::__value)};
# 95 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef typename __truth_type< __value> ::__type __type;
# 96 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 99 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class , class >
# 100 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __are_same {
# 102 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 103 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 104 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 106 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 107 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __are_same< _Tp, _Tp> {
# 109 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 110 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 111 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 114 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 115 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_void {
# 117 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 118 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 119 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 122 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_void< void> {
# 124 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 125 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 126 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 131 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 132 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_integer {
# 134 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 135 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 136 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 142 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< bool> {
# 144 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 145 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 146 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 149 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< char> {
# 151 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 152 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 153 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 156 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< signed char> {
# 158 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 159 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 160 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 163 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned char> {
# 165 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 166 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 167 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 171 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< wchar_t> {
# 173 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 174 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 175 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 195 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< short> {
# 197 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 198 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 199 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 202 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned short> {
# 204 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 205 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 206 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 209 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< int> {
# 211 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 212 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 213 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 216 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned> {
# 218 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 219 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 220 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 223 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< long> {
# 225 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 226 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 227 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 230 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned long> {
# 232 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 233 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 234 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 237 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< long long> {
# 239 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 240 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 241 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 244 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned long long> {
# 246 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 247 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 248 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 253 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 254 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_floating {
# 256 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 257 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 258 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 262 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_floating< float> {
# 264 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 265 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 266 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 269 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_floating< double> {
# 271 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 272 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 273 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 276 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_floating< long double> {
# 278 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 279 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 280 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 285 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 286 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_pointer {
# 288 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 289 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 290 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 292 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 293 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_pointer< _Tp *> {
# 295 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 296 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 297 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 302 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 303 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_normal_iterator {
# 305 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 306 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 307 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 309 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Iterator, class _Container>
# 310 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> > {
# 313 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 314 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 315 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 320 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 321 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> > {
# 323 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 328 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 329 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> > {
# 331 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 336 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 337 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> > {
# 339 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 344 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 345 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_char {
# 347 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 348 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 349 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 352 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_char< char> {
# 354 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 355 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 356 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 360 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_char< wchar_t> {
# 362 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 363 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 364 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 367 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 368 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_byte {
# 370 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 371 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 372 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 375 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_byte< char> {
# 377 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 378 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 379 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 382 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_byte< signed char> {
# 384 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 385 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 386 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 389 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template<> struct __is_byte< unsigned char> {
# 391 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 392 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 393 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 398 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 399 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_move_iterator {
# 401 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value};
# 402 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 403 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 417 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 418 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
class __is_iterator_helper {
# 420 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef char __one;
# 421 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef struct { char __arr[2]; } __two;
# 423 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Up>
# 424 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct _Wrap_type {
# 425 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 427 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Up> static __one __test(_Wrap_type< typename _Up::iterator_category> *);
# 430 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Up> static __two __test(...);
# 434 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
public: static const bool __value = ((sizeof(__test< _Tp> (0)) == (1)) || __is_pointer< _Tp> ::__value);
# 436 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 438 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
template< class _Tp>
# 439 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
struct __is_iterator {
# 441 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
enum { __value = __is_iterator_helper< _Tp> ::__value};
# 442 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
typedef typename __truth_type< __value> ::__type __type;
# 443 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
};
# 445 "/usr/include/c++/4.5/bits/cpp_type_traits.h" 3
}
# 37 "/usr/include/c++/4.5/ext/type_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) {
# 40 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< bool __T1, class >
# 41 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __enable_if {
# 42 "/usr/include/c++/4.5/ext/type_traits.h" 3
};
# 44 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Tp>
# 45 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __enable_if< true, _Tp> {
# 46 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef _Tp __type; };
# 50 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< bool _Cond, class _Iftrue, class _Iffalse>
# 51 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __conditional_type {
# 52 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef _Iftrue __type; };
# 54 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Iftrue, class _Iffalse>
# 55 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __conditional_type< false, _Iftrue, _Iffalse> {
# 56 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef _Iffalse __type; };
# 60 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Tp>
# 61 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __add_unsigned {
# 64 "/usr/include/c++/4.5/ext/type_traits.h" 3
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;
# 67 "/usr/include/c++/4.5/ext/type_traits.h" 3
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
# 68 "/usr/include/c++/4.5/ext/type_traits.h" 3
};
# 71 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __add_unsigned< char> {
# 72 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef unsigned char __type; };
# 75 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __add_unsigned< signed char> {
# 76 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef unsigned char __type; };
# 79 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __add_unsigned< short> {
# 80 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef unsigned short __type; };
# 83 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __add_unsigned< int> {
# 84 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef unsigned __type; };
# 87 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __add_unsigned< long> {
# 88 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef unsigned long __type; };
# 91 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __add_unsigned< long long> {
# 92 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef unsigned long long __type; };
# 96 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __add_unsigned< bool> ;
# 99 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __add_unsigned< wchar_t> ;
# 103 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Tp>
# 104 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __remove_unsigned {
# 107 "/usr/include/c++/4.5/ext/type_traits.h" 3
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;
# 110 "/usr/include/c++/4.5/ext/type_traits.h" 3
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
# 111 "/usr/include/c++/4.5/ext/type_traits.h" 3
};
# 114 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __remove_unsigned< char> {
# 115 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef signed char __type; };
# 118 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned char> {
# 119 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef signed char __type; };
# 122 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned short> {
# 123 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef short __type; };
# 126 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned> {
# 127 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef int __type; };
# 130 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned long> {
# 131 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef long __type; };
# 134 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned long long> {
# 135 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef long long __type; };
# 139 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __remove_unsigned< bool> ;
# 142 "/usr/include/c++/4.5/ext/type_traits.h" 3
template<> struct __remove_unsigned< wchar_t> ;
# 146 "/usr/include/c++/4.5/ext/type_traits.h" 3
template < typename _Type >
    inline bool
    __is_null_pointer ( _Type * __ptr )
    { return __ptr == 0; }
# 151 "/usr/include/c++/4.5/ext/type_traits.h" 3
template < typename _Type >
    inline bool
    __is_null_pointer ( _Type )
    { return false; }
# 158 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Tp, bool __T2 = std::__is_integer< _Tp> ::__value>
# 159 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __promote {
# 160 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef double __type; };
# 162 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Tp>
# 163 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __promote< _Tp, false> {
# 164 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef _Tp __type; };
# 166 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Tp, class _Up>
# 167 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __promote_2 {
# 170 "/usr/include/c++/4.5/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 171 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 174 "/usr/include/c++/4.5/ext/type_traits.h" 3
public: typedef __typeof__(__type1() + __type2()) __type;
# 175 "/usr/include/c++/4.5/ext/type_traits.h" 3
};
# 177 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Tp, class _Up, class _Vp>
# 178 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __promote_3 {
# 181 "/usr/include/c++/4.5/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 182 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 183 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;
# 186 "/usr/include/c++/4.5/ext/type_traits.h" 3
public: typedef __typeof__((__type1() + __type2()) + __type3()) __type;
# 187 "/usr/include/c++/4.5/ext/type_traits.h" 3
};
# 189 "/usr/include/c++/4.5/ext/type_traits.h" 3
template< class _Tp, class _Up, class _Vp, class _Wp>
# 190 "/usr/include/c++/4.5/ext/type_traits.h" 3
struct __promote_4 {
# 193 "/usr/include/c++/4.5/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 194 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 195 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;
# 196 "/usr/include/c++/4.5/ext/type_traits.h" 3
typedef typename __promote< _Wp, std::__is_integer< _Wp> ::__value> ::__type __type4;
# 199 "/usr/include/c++/4.5/ext/type_traits.h" 3
public: typedef __typeof__(((__type1() + __type2()) + __type3()) + __type4()) __type;
# 200 "/usr/include/c++/4.5/ext/type_traits.h" 3
};
# 202 "/usr/include/c++/4.5/ext/type_traits.h" 3
}
# 77 "/usr/include/c++/4.5/cmath" 3
namespace std __attribute((__visibility__("default"))) {
# 81 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    _Tp __cmath_power ( _Tp, unsigned int );
# 84 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline _Tp
    __pow_helper ( _Tp __x, int __n )
    {
      return __n < 0
        ? _Tp ( 1 ) / __cmath_power ( __x, - __n )
        : __cmath_power ( __x, __n );
    }
# 94 "/usr/include/c++/4.5/cmath" 3
inline double abs(double __x)
# 95 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_fabs(__x); }
# 98 "/usr/include/c++/4.5/cmath" 3
inline float abs(float __x)
# 99 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_fabsf(__x); }
# 102 "/usr/include/c++/4.5/cmath" 3
inline long double abs(long double __x)
# 103 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_fabsl(__x); }
# 105 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    abs ( _Tp __x )
    { return __builtin_fabs ( __x ); }
# 111 "/usr/include/c++/4.5/cmath" 3
using ::acos;
# 114 "/usr/include/c++/4.5/cmath" 3
inline float acos(float __x)
# 115 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_acosf(__x); }
# 118 "/usr/include/c++/4.5/cmath" 3
inline long double acos(long double __x)
# 119 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_acosl(__x); }
# 121 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    acos ( _Tp __x )
    { return __builtin_acos ( __x ); }
# 127 "/usr/include/c++/4.5/cmath" 3
using ::asin;
# 130 "/usr/include/c++/4.5/cmath" 3
inline float asin(float __x)
# 131 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_asinf(__x); }
# 134 "/usr/include/c++/4.5/cmath" 3
inline long double asin(long double __x)
# 135 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_asinl(__x); }
# 137 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    asin ( _Tp __x )
    { return __builtin_asin ( __x ); }
# 143 "/usr/include/c++/4.5/cmath" 3
using ::atan;
# 146 "/usr/include/c++/4.5/cmath" 3
inline float atan(float __x)
# 147 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_atanf(__x); }
# 150 "/usr/include/c++/4.5/cmath" 3
inline long double atan(long double __x)
# 151 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_atanl(__x); }
# 153 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    atan ( _Tp __x )
    { return __builtin_atan ( __x ); }
# 159 "/usr/include/c++/4.5/cmath" 3
using ::atan2;
# 162 "/usr/include/c++/4.5/cmath" 3
inline float atan2(float __y, float __x)
# 163 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_atan2f(__y, __x); }
# 166 "/usr/include/c++/4.5/cmath" 3
inline long double atan2(long double __y, long double __x)
# 167 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_atan2l(__y, __x); }
# 169 "/usr/include/c++/4.5/cmath" 3
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
# 181 "/usr/include/c++/4.5/cmath" 3
using ::ceil;
# 184 "/usr/include/c++/4.5/cmath" 3
inline float ceil(float __x)
# 185 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_ceilf(__x); }
# 188 "/usr/include/c++/4.5/cmath" 3
inline long double ceil(long double __x)
# 189 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_ceill(__x); }
# 191 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    ceil ( _Tp __x )
    { return __builtin_ceil ( __x ); }
# 197 "/usr/include/c++/4.5/cmath" 3
using ::cos;
# 200 "/usr/include/c++/4.5/cmath" 3
inline float cos(float __x)
# 201 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_cosf(__x); }
# 204 "/usr/include/c++/4.5/cmath" 3
inline long double cos(long double __x)
# 205 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_cosl(__x); }
# 207 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cos ( _Tp __x )
    { return __builtin_cos ( __x ); }
# 213 "/usr/include/c++/4.5/cmath" 3
using ::cosh;
# 216 "/usr/include/c++/4.5/cmath" 3
inline float cosh(float __x)
# 217 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_coshf(__x); }
# 220 "/usr/include/c++/4.5/cmath" 3
inline long double cosh(long double __x)
# 221 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_coshl(__x); }
# 223 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cosh ( _Tp __x )
    { return __builtin_cosh ( __x ); }
# 229 "/usr/include/c++/4.5/cmath" 3
using ::exp;
# 232 "/usr/include/c++/4.5/cmath" 3
inline float exp(float __x)
# 233 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_expf(__x); }
# 236 "/usr/include/c++/4.5/cmath" 3
inline long double exp(long double __x)
# 237 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_expl(__x); }
# 239 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    exp ( _Tp __x )
    { return __builtin_exp ( __x ); }
# 245 "/usr/include/c++/4.5/cmath" 3
using ::fabs;
# 248 "/usr/include/c++/4.5/cmath" 3
inline float fabs(float __x)
# 249 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_fabsf(__x); }
# 252 "/usr/include/c++/4.5/cmath" 3
inline long double fabs(long double __x)
# 253 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_fabsl(__x); }
# 255 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    fabs ( _Tp __x )
    { return __builtin_fabs ( __x ); }
# 261 "/usr/include/c++/4.5/cmath" 3
using ::floor;
# 264 "/usr/include/c++/4.5/cmath" 3
inline float floor(float __x)
# 265 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_floorf(__x); }
# 268 "/usr/include/c++/4.5/cmath" 3
inline long double floor(long double __x)
# 269 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_floorl(__x); }
# 271 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    floor ( _Tp __x )
    { return __builtin_floor ( __x ); }
# 277 "/usr/include/c++/4.5/cmath" 3
using ::fmod;
# 280 "/usr/include/c++/4.5/cmath" 3
inline float fmod(float __x, float __y)
# 281 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_fmodf(__x, __y); }
# 284 "/usr/include/c++/4.5/cmath" 3
inline long double fmod(long double __x, long double __y)
# 285 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_fmodl(__x, __y); }
# 287 "/usr/include/c++/4.5/cmath" 3
using ::frexp;
# 290 "/usr/include/c++/4.5/cmath" 3
inline float frexp(float __x, int *__exp)
# 291 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_frexpf(__x, __exp); }
# 294 "/usr/include/c++/4.5/cmath" 3
inline long double frexp(long double __x, int *__exp)
# 295 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_frexpl(__x, __exp); }
# 297 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    frexp ( _Tp __x, int * __exp )
    { return __builtin_frexp ( __x, __exp ); }
# 303 "/usr/include/c++/4.5/cmath" 3
using ::ldexp;
# 306 "/usr/include/c++/4.5/cmath" 3
inline float ldexp(float __x, int __exp)
# 307 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_ldexpf(__x, __exp); }
# 310 "/usr/include/c++/4.5/cmath" 3
inline long double ldexp(long double __x, int __exp)
# 311 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_ldexpl(__x, __exp); }
# 313 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
  ldexp ( _Tp __x, int __exp )
  { return __builtin_ldexp ( __x, __exp ); }
# 319 "/usr/include/c++/4.5/cmath" 3
using ::log;
# 322 "/usr/include/c++/4.5/cmath" 3
inline float log(float __x)
# 323 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_logf(__x); }
# 326 "/usr/include/c++/4.5/cmath" 3
inline long double log(long double __x)
# 327 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_logl(__x); }
# 329 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log ( _Tp __x )
    { return __builtin_log ( __x ); }
# 335 "/usr/include/c++/4.5/cmath" 3
using ::log10;
# 338 "/usr/include/c++/4.5/cmath" 3
inline float log10(float __x)
# 339 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_log10f(__x); }
# 342 "/usr/include/c++/4.5/cmath" 3
inline long double log10(long double __x)
# 343 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_log10l(__x); }
# 345 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log10 ( _Tp __x )
    { return __builtin_log10 ( __x ); }
# 351 "/usr/include/c++/4.5/cmath" 3
using ::modf;
# 354 "/usr/include/c++/4.5/cmath" 3
inline float modf(float __x, float *__iptr)
# 355 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_modff(__x, __iptr); }
# 358 "/usr/include/c++/4.5/cmath" 3
inline long double modf(long double __x, long double *__iptr)
# 359 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_modfl(__x, __iptr); }
# 361 "/usr/include/c++/4.5/cmath" 3
using ::pow;
# 364 "/usr/include/c++/4.5/cmath" 3
inline float pow(float __x, float __y)
# 365 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_powf(__x, __y); }
# 368 "/usr/include/c++/4.5/cmath" 3
inline long double pow(long double __x, long double __y)
# 369 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_powl(__x, __y); }
# 375 "/usr/include/c++/4.5/cmath" 3
inline double pow(double __x, int __i)
# 376 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_powi(__x, __i); }
# 379 "/usr/include/c++/4.5/cmath" 3
inline float pow(float __x, int __n)
# 380 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_powif(__x, __n); }
# 383 "/usr/include/c++/4.5/cmath" 3
inline long double pow(long double __x, int __n)
# 384 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_powil(__x, __n); }
# 387 "/usr/include/c++/4.5/cmath" 3
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
# 399 "/usr/include/c++/4.5/cmath" 3
using ::sin;
# 402 "/usr/include/c++/4.5/cmath" 3
inline float sin(float __x)
# 403 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_sinf(__x); }
# 406 "/usr/include/c++/4.5/cmath" 3
inline long double sin(long double __x)
# 407 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_sinl(__x); }
# 409 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sin ( _Tp __x )
    { return __builtin_sin ( __x ); }
# 415 "/usr/include/c++/4.5/cmath" 3
using ::sinh;
# 418 "/usr/include/c++/4.5/cmath" 3
inline float sinh(float __x)
# 419 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_sinhf(__x); }
# 422 "/usr/include/c++/4.5/cmath" 3
inline long double sinh(long double __x)
# 423 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_sinhl(__x); }
# 425 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sinh ( _Tp __x )
    { return __builtin_sinh ( __x ); }
# 431 "/usr/include/c++/4.5/cmath" 3
using ::sqrt;
# 434 "/usr/include/c++/4.5/cmath" 3
inline float sqrt(float __x)
# 435 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_sqrtf(__x); }
# 438 "/usr/include/c++/4.5/cmath" 3
inline long double sqrt(long double __x)
# 439 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_sqrtl(__x); }
# 441 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sqrt ( _Tp __x )
    { return __builtin_sqrt ( __x ); }
# 447 "/usr/include/c++/4.5/cmath" 3
using ::tan;
# 450 "/usr/include/c++/4.5/cmath" 3
inline float tan(float __x)
# 451 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_tanf(__x); }
# 454 "/usr/include/c++/4.5/cmath" 3
inline long double tan(long double __x)
# 455 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_tanl(__x); }
# 457 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tan ( _Tp __x )
    { return __builtin_tan ( __x ); }
# 463 "/usr/include/c++/4.5/cmath" 3
using ::tanh;
# 466 "/usr/include/c++/4.5/cmath" 3
inline float tanh(float __x)
# 467 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_tanhf(__x); }
# 470 "/usr/include/c++/4.5/cmath" 3
inline long double tanh(long double __x)
# 471 "/usr/include/c++/4.5/cmath" 3
{ return __builtin_tanhl(__x); }
# 473 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tanh ( _Tp __x )
    { return __builtin_tanh ( __x ); }
# 479 "/usr/include/c++/4.5/cmath" 3
}
# 498 "/usr/include/c++/4.5/cmath" 3
namespace std __attribute((__visibility__("default"))) {
# 500 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    fpclassify ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_fpclassify ( FP_NAN, FP_INFINITE, FP_NORMAL,
      FP_SUBNORMAL, FP_ZERO, __type ( __f ) );
    }
# 510 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isfinite ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isfinite ( __type ( __f ) );
    }
# 519 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isinf ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isinf ( __type ( __f ) );
    }
# 528 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isnan ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isnan ( __type ( __f ) );
    }
# 537 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isnormal ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isnormal ( __type ( __f ) );
    }
# 546 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    signbit ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_signbit ( __type ( __f ) );
    }
# 555 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isgreater ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isgreater ( __type ( __f1 ), __type ( __f2 ) );
    }
# 564 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isgreaterequal ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isgreaterequal ( __type ( __f1 ), __type ( __f2 ) );
    }
# 573 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isless ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isless ( __type ( __f1 ), __type ( __f2 ) );
    }
# 582 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    islessequal ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_islessequal ( __type ( __f1 ), __type ( __f2 ) );
    }
# 591 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    islessgreater ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_islessgreater ( __type ( __f1 ), __type ( __f2 ) );
    }
# 600 "/usr/include/c++/4.5/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isunordered ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isunordered ( __type ( __f1 ), __type ( __f2 ) );
    }
# 609 "/usr/include/c++/4.5/cmath" 3
}
# 35 "/usr/include/c++/4.5/bits/cmath.tcc" 3
namespace std __attribute((__visibility__("default"))) {
# 37 "/usr/include/c++/4.5/bits/cmath.tcc" 3
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
# 53 "/usr/include/c++/4.5/bits/cmath.tcc" 3
}
# 49 "/usr/include/c++/4.5/cstddef" 3
namespace std __attribute((__visibility__("default"))) {
# 51 "/usr/include/c++/4.5/cstddef" 3
using ::ptrdiff_t;
# 52 "/usr/include/c++/4.5/cstddef" 3
using ::size_t;
# 54 "/usr/include/c++/4.5/cstddef" 3
}
# 100 "/usr/include/c++/4.5/cstdlib" 3
namespace std __attribute((__visibility__("default"))) {
# 102 "/usr/include/c++/4.5/cstdlib" 3
using ::div_t;
# 103 "/usr/include/c++/4.5/cstdlib" 3
using ::ldiv_t;
# 105 "/usr/include/c++/4.5/cstdlib" 3
using ::abort;
# 106 "/usr/include/c++/4.5/cstdlib" 3
using ::abs;
# 107 "/usr/include/c++/4.5/cstdlib" 3
using ::atexit;
# 108 "/usr/include/c++/4.5/cstdlib" 3
using ::atof;
# 109 "/usr/include/c++/4.5/cstdlib" 3
using ::atoi;
# 110 "/usr/include/c++/4.5/cstdlib" 3
using ::atol;
# 111 "/usr/include/c++/4.5/cstdlib" 3
using ::bsearch;
# 112 "/usr/include/c++/4.5/cstdlib" 3
using ::calloc;
# 113 "/usr/include/c++/4.5/cstdlib" 3
using ::div;
# 114 "/usr/include/c++/4.5/cstdlib" 3
using ::exit;
# 115 "/usr/include/c++/4.5/cstdlib" 3
using ::free;
# 116 "/usr/include/c++/4.5/cstdlib" 3
using ::getenv;
# 117 "/usr/include/c++/4.5/cstdlib" 3
using ::labs;
# 118 "/usr/include/c++/4.5/cstdlib" 3
using ::ldiv;
# 119 "/usr/include/c++/4.5/cstdlib" 3
using ::malloc;
# 121 "/usr/include/c++/4.5/cstdlib" 3
using ::mblen;
# 122 "/usr/include/c++/4.5/cstdlib" 3
using ::mbstowcs;
# 123 "/usr/include/c++/4.5/cstdlib" 3
using ::mbtowc;
# 125 "/usr/include/c++/4.5/cstdlib" 3
using ::qsort;
# 126 "/usr/include/c++/4.5/cstdlib" 3
using ::rand;
# 127 "/usr/include/c++/4.5/cstdlib" 3
using ::realloc;
# 128 "/usr/include/c++/4.5/cstdlib" 3
using ::srand;
# 129 "/usr/include/c++/4.5/cstdlib" 3
using ::strtod;
# 130 "/usr/include/c++/4.5/cstdlib" 3
using ::strtol;
# 131 "/usr/include/c++/4.5/cstdlib" 3
using ::strtoul;
# 132 "/usr/include/c++/4.5/cstdlib" 3
using ::system;
# 134 "/usr/include/c++/4.5/cstdlib" 3
using ::wcstombs;
# 135 "/usr/include/c++/4.5/cstdlib" 3
using ::wctomb;
# 139 "/usr/include/c++/4.5/cstdlib" 3
inline long abs(long __i) { return labs(__i); }
# 142 "/usr/include/c++/4.5/cstdlib" 3
inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); }
# 144 "/usr/include/c++/4.5/cstdlib" 3
}
# 157 "/usr/include/c++/4.5/cstdlib" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) {
# 160 "/usr/include/c++/4.5/cstdlib" 3
using ::lldiv_t;
# 166 "/usr/include/c++/4.5/cstdlib" 3
using ::_Exit;
# 170 "/usr/include/c++/4.5/cstdlib" 3
inline long long abs(long long __x) { return (__x >= (0)) ? __x : (-__x); }
# 173 "/usr/include/c++/4.5/cstdlib" 3
using ::llabs;
# 176 "/usr/include/c++/4.5/cstdlib" 3
inline lldiv_t div(long long __n, long long __d)
# 177 "/usr/include/c++/4.5/cstdlib" 3
{ lldiv_t __q; (__q.quot) = (__n / __d); (__q.rem) = (__n % __d); return __q; }
# 179 "/usr/include/c++/4.5/cstdlib" 3
using ::lldiv;
# 190 "/usr/include/c++/4.5/cstdlib" 3
using ::atoll;
# 191 "/usr/include/c++/4.5/cstdlib" 3
using ::strtoll;
# 192 "/usr/include/c++/4.5/cstdlib" 3
using ::strtoull;
# 194 "/usr/include/c++/4.5/cstdlib" 3
using ::strtof;
# 195 "/usr/include/c++/4.5/cstdlib" 3
using ::strtold;
# 197 "/usr/include/c++/4.5/cstdlib" 3
}
# 199 "/usr/include/c++/4.5/cstdlib" 3
namespace std __attribute((__visibility__("default"))) {
# 202 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::lldiv_t;
# 204 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::_Exit;
# 205 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::abs;
# 207 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::llabs;
# 208 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::div;
# 209 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::lldiv;
# 211 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::atoll;
# 212 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::strtof;
# 213 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::strtoll;
# 214 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::strtoull;
# 215 "/usr/include/c++/4.5/cstdlib" 3
using __gnu_cxx::strtold;
# 217 "/usr/include/c++/4.5/cstdlib" 3
}
# 2335 "/usr/local/cuda4.1/cuda/include/math_functions.h"
namespace __gnu_cxx {
# 2337 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline long long abs(long long);
# 2338 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2340 "/usr/local/cuda4.1/cuda/include/math_functions.h"
namespace std {
# 2342 "/usr/local/cuda4.1/cuda/include/math_functions.h"
template< class T> extern inline T __pow_helper(T, int);
# 2343 "/usr/local/cuda4.1/cuda/include/math_functions.h"
template< class T> extern inline T __cmath_power(T, unsigned);
# 2344 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2346 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::abs;
# 2347 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::fabs;
# 2348 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::ceil;
# 2349 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::floor;
# 2350 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::sqrt;
# 2351 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::pow;
# 2352 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::log;
# 2353 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::log10;
# 2354 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::fmod;
# 2355 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::modf;
# 2356 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::exp;
# 2357 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::frexp;
# 2358 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::ldexp;
# 2359 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::asin;
# 2360 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::sin;
# 2361 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::sinh;
# 2362 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::acos;
# 2363 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::cos;
# 2364 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::cosh;
# 2365 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::atan;
# 2366 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::atan2;
# 2367 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::tan;
# 2368 "/usr/local/cuda4.1/cuda/include/math_functions.h"
using std::tanh;
# 2531 "/usr/local/cuda4.1/cuda/include/math_functions.h"
namespace std {
# 2534 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline long abs(long);
# 2535 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float abs(float);
# 2536 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline double abs(double);
# 2537 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float fabs(float);
# 2538 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float ceil(float);
# 2539 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float floor(float);
# 2540 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float sqrt(float);
# 2541 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float pow(float, float);
# 2542 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float pow(float, int);
# 2543 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline double pow(double, int);
# 2544 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float log(float);
# 2545 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float log10(float);
# 2546 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float fmod(float, float);
# 2547 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float modf(float, float *);
# 2548 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float exp(float);
# 2549 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float frexp(float, int *);
# 2550 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float ldexp(float, int);
# 2551 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float asin(float);
# 2552 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float sin(float);
# 2553 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float sinh(float);
# 2554 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float acos(float);
# 2555 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float cos(float);
# 2556 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float cosh(float);
# 2557 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float atan(float);
# 2558 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float atan2(float, float);
# 2559 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float tan(float);
# 2560 "/usr/local/cuda4.1/cuda/include/math_functions.h"
extern inline float tanh(float);
# 2563 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2566 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float logb(float a)
# 2567 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2568 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return logbf(a);
# 2569 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2571 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline int ilogb(float a)
# 2572 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2573 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return ilogbf(a);
# 2574 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2576 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float scalbn(float a, int b)
# 2577 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2578 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return scalbnf(a, b);
# 2579 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2581 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float scalbln(float a, long b)
# 2582 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2583 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return scalblnf(a, b);
# 2584 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2586 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float exp2(float a)
# 2587 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2588 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return exp2f(a);
# 2589 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2591 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float exp10(float a)
# 2592 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2593 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return exp10f(a);
# 2594 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2596 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float expm1(float a)
# 2597 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2598 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return expm1f(a);
# 2599 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2601 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float log2(float a)
# 2602 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2603 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return log2f(a);
# 2604 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2606 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float log1p(float a)
# 2607 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2608 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return log1pf(a);
# 2609 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2611 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float rsqrt(float a)
# 2612 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2613 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return rsqrtf(a);
# 2614 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2616 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float acosh(float a)
# 2617 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2618 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return acoshf(a);
# 2619 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2621 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float asinh(float a)
# 2622 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2623 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return asinhf(a);
# 2624 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2626 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float atanh(float a)
# 2627 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2628 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return atanhf(a);
# 2629 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2631 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float hypot(float a, float b)
# 2632 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2633 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return hypotf(a, b);
# 2634 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2636 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float cbrt(float a)
# 2637 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2638 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return cbrtf(a);
# 2639 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2641 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float rcbrt(float a)
# 2642 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2643 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return rcbrtf(a);
# 2644 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2646 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float sinpi(float a)
# 2647 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2648 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return sinpif(a);
# 2649 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2651 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float cospi(float a)
# 2652 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2653 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return cospif(a);
# 2654 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2656 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 2657 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2658 "/usr/local/cuda4.1/cuda/include/math_functions.h"
sincosf(a, sptr, cptr);
# 2659 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2661 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float j0(float a)
# 2662 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2663 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return j0f(a);
# 2664 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2666 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float j1(float a)
# 2667 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2668 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return j1f(a);
# 2669 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2671 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float jn(int n, float a)
# 2672 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2673 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return jnf(n, a);
# 2674 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2676 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float y0(float a)
# 2677 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2678 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return y0f(a);
# 2679 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2681 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float y1(float a)
# 2682 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2683 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return y1f(a);
# 2684 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2686 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float yn(int n, float a)
# 2687 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2688 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return ynf(n, a);
# 2689 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2691 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float erf(float a)
# 2692 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2693 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return erff(a);
# 2694 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2696 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float erfinv(float a)
# 2697 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2698 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return erfinvf(a);
# 2699 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2701 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float erfc(float a)
# 2702 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2703 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return erfcf(a);
# 2704 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2706 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float erfcinv(float a)
# 2707 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2708 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return erfcinvf(a);
# 2709 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2711 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float erfcx(float a)
# 2712 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2713 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return erfcxf(a);
# 2714 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2716 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float lgamma(float a)
# 2717 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2718 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return lgammaf(a);
# 2719 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2721 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float tgamma(float a)
# 2722 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2723 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return tgammaf(a);
# 2724 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2726 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float copysign(float a, float b)
# 2727 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2728 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return copysignf(a, b);
# 2729 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2731 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline double copysign(double a, float b)
# 2732 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2733 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return copysign(a, (double)b);
# 2734 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2736 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float copysign(float a, double b)
# 2737 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2738 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return copysignf(a, (float)b);
# 2739 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2741 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float nextafter(float a, float b)
# 2742 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2743 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return nextafterf(a, b);
# 2744 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2746 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float remainder(float a, float b)
# 2747 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2748 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return remainderf(a, b);
# 2749 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2751 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 2752 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2753 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return remquof(a, b, quo);
# 2754 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2756 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float round(float a)
# 2757 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2758 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return roundf(a);
# 2759 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2761 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline long lround(float a)
# 2762 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2763 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return lroundf(a);
# 2764 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2766 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline long long llround(float a)
# 2767 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2768 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return llroundf(a);
# 2769 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2771 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float trunc(float a)
# 2772 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2773 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return truncf(a);
# 2774 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2776 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float rint(float a)
# 2777 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2778 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return rintf(a);
# 2779 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2781 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline long lrint(float a)
# 2782 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2783 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return lrintf(a);
# 2784 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2786 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline long long llrint(float a)
# 2787 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2788 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return llrintf(a);
# 2789 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2791 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float nearbyint(float a)
# 2792 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2793 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return nearbyintf(a);
# 2794 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2796 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float fdim(float a, float b)
# 2797 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2798 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fdimf(a, b);
# 2799 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2801 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float fma(float a, float b, float c)
# 2802 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2803 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmaf(a, b, c);
# 2804 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2806 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float fmax(float a, float b)
# 2807 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2808 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmaxf(a, b);
# 2809 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2811 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float fmin(float a, float b)
# 2812 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2813 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fminf(a, b);
# 2814 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2816 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 2817 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2818 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return umin(a, b);
# 2819 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2821 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 2822 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2823 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return umin((unsigned)a, b);
# 2824 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2826 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 2827 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2828 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return umin(a, (unsigned)b);
# 2829 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2831 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline long long min(long long a, long long b)
# 2832 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2833 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return llmin(a, b);
# 2834 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2836 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned long long min(unsigned long long a, unsigned long long b)
# 2837 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2838 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return ullmin(a, b);
# 2839 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2841 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned long long min(long long a, unsigned long long b)
# 2842 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2843 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return ullmin((unsigned long long)a, b);
# 2844 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2846 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned long long min(unsigned long long a, long long b)
# 2847 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2848 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return ullmin(a, (unsigned long long)b);
# 2849 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2851 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float min(float a, float b)
# 2852 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2853 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fminf(a, b);
# 2854 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2856 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline double min(double a, double b)
# 2857 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2858 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmin(a, b);
# 2859 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2861 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline double min(float a, double b)
# 2862 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2863 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmin((double)a, b);
# 2864 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2866 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline double min(double a, float b)
# 2867 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2868 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmin(a, (double)b);
# 2869 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2871 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 2872 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2873 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return umax(a, b);
# 2874 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2876 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 2877 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2878 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return umax((unsigned)a, b);
# 2879 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2881 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 2882 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2883 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return umax(a, (unsigned)b);
# 2884 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2886 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline long long max(long long a, long long b)
# 2887 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2888 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return llmax(a, b);
# 2889 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2891 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned long long max(unsigned long long a, unsigned long long b)
# 2892 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2893 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return ullmax(a, b);
# 2894 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2896 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned long long max(long long a, unsigned long long b)
# 2897 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2898 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return ullmax((unsigned long long)a, b);
# 2899 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2901 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline unsigned long long max(unsigned long long a, long long b)
# 2902 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2903 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return ullmax(a, (unsigned long long)b);
# 2904 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2906 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline float max(float a, float b)
# 2907 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2908 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmaxf(a, b);
# 2909 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2911 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline double max(double a, double b)
# 2912 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2913 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmax(a, b);
# 2914 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2916 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline double max(float a, double b)
# 2917 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2918 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmax((double)a, b);
# 2919 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 2921 "/usr/local/cuda4.1/cuda/include/math_functions.h"
static inline double max(double a, float b)
# 2922 "/usr/local/cuda4.1/cuda/include/math_functions.h"
{
# 2923 "/usr/local/cuda4.1/cuda/include/math_functions.h"
return fmax(a, (double)b);
# 2924 "/usr/local/cuda4.1/cuda/include/math_functions.h"
}
# 73 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
template< class T, int dim = 1>
# 74 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
struct surface : public surfaceReference {
# 76 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
surface()
# 77 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
{
# 78 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 79 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
}
# 81 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
surface(cudaChannelFormatDesc desc)
# 82 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
{
# 83 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
(channelDesc) = desc;
# 84 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
}
# 85 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
};
# 87 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
template< int dim>
# 88 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
struct surface< void, dim> : public surfaceReference {
# 90 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
surface()
# 91 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
{
# 92 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< void> ();
# 93 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
}
# 94 "/usr/local/cuda4.1/cuda/include/cuda_surface_types.h"
};
# 73 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
template< class T, int texType = 1, cudaTextureReadMode mode = cudaReadModeElementType>
# 74 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
struct texture : public textureReference {
# 76 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 77 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 78 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 79 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
{
# 80 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
(normalized) = norm;
# 81 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
(filterMode) = fMode;
# 82 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 83 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 84 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 85 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 86 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
(sRGB) = 0;
# 87 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
}
# 89 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 90 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 91 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 92 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
desc)
# 93 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
{
# 94 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
(normalized) = norm;
# 95 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
(filterMode) = fMode;
# 96 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 97 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 98 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 99 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
(channelDesc) = desc;
# 100 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
(sRGB) = 0;
# 101 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
}
# 102 "/usr/local/cuda4.1/cuda/include/cuda_texture_types.h"
};
# 1103 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline int mulhi(int a, int b)
# 1104 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1106 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1108 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, unsigned b)
# 1109 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1111 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1113 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(int a, unsigned b)
# 1114 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1116 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1118 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, int b)
# 1119 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1121 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1123 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline long long mul64hi(long long a, long long b)
# 1124 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1126 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1128 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 1129 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1131 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1133 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(long long a, unsigned long long b)
# 1134 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1136 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1138 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, long long b)
# 1139 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1141 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1143 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline int float_as_int(float a)
# 1144 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;
# 1146 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1148 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline float int_as_float(int a)
# 1149 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;
# 1151 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1153 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline float saturate(float a)
# 1154 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;
# 1156 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1158 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline int mul24(int a, int b)
# 1159 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1161 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1163 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline unsigned umul24(unsigned a, unsigned b)
# 1164 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)b;
# 1166 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1168 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline void trap()
# 1169 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;
# 1171 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1174 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline void brkpt(int c = 0)
# 1175 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)c;
# 1177 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1179 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline void syncthreads()
# 1180 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;
# 1182 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1184 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline void prof_trigger(int e)
# 1185 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)e;
# 1202 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1204 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline void threadfence(bool global = true)
# 1205 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)global;
# 1207 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1209 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero)
# 1210 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 1215 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1217 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero)
# 1218 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 1223 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1225 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest)
# 1226 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 1231 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 1233 "/usr/local/cuda4.1/cuda/include/device_functions.h"
__attribute__((unused)) static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 1234 "/usr/local/cuda4.1/cuda/include/device_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 1239 "/usr/local/cuda4.1/cuda/include/device_functions.h"
exit(___);}
# 96 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd(int *address, int val)
# 97 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 99 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 101 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd(unsigned *address, unsigned val)
# 102 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 104 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 106 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub(int *address, int val)
# 107 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 109 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 111 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub(unsigned *address, unsigned val)
# 112 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 114 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 116 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch(int *address, int val)
# 117 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 119 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 121 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch(unsigned *address, unsigned val)
# 122 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 124 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 126 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch(float *address, float val)
# 127 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 129 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 131 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin(int *address, int val)
# 132 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 134 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 136 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin(unsigned *address, unsigned val)
# 137 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 139 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 141 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax(int *address, int val)
# 142 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 144 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 146 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax(unsigned *address, unsigned val)
# 147 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 149 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 151 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc(unsigned *address, unsigned val)
# 152 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 154 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 156 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec(unsigned *address, unsigned val)
# 157 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 159 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 161 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd(int *address, int val)
# 162 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 164 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 166 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd(unsigned *address, unsigned val)
# 167 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 169 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 171 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr(int *address, int val)
# 172 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 174 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 176 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr(unsigned *address, unsigned val)
# 177 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 179 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 181 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor(int *address, int val)
# 182 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 184 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 186 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor(unsigned *address, unsigned val)
# 187 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 189 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 191 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS(int *address, int compare, int val)
# 192 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)compare;(void)val;
# 194 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 196 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 197 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)compare;(void)val;
# 199 "/usr/local/cuda4.1/cuda/include/sm_11_atomic_functions.h"
exit(___);}
# 81 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 82 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 84 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
exit(___);}
# 86 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 87 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 89 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
exit(___);}
# 91 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 92 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)compare;(void)val;
# 94 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
exit(___);}
# 96 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool any(bool cond)
# 97 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)cond;
# 99 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
exit(___);}
# 101 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool all(bool cond)
# 102 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
{int volatile ___ = 1;(void)cond;
# 104 "/usr/local/cuda4.1/cuda/include/sm_12_atomic_functions.h"
exit(___);}
# 521 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode)
# 522 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)b;(void)c;(void)mode;
# 527 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 529 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 530 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 535 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 537 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 538 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 543 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 545 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero)
# 546 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 551 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 553 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero)
# 554 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 559 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 561 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero)
# 562 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 567 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 569 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero)
# 570 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 575 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 577 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest)
# 578 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 583 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 585 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest)
# 586 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 591 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 593 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest)
# 594 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 596 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 598 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 599 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 601 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 603 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest)
# 604 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
{int volatile ___ = 1;(void)a;(void)mode;
# 606 "/usr/local/cuda4.1/cuda/include/sm_13_double_functions.h"
exit(___);}
# 77 "/usr/local/cuda4.1/cuda/include/sm_20_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd(float *address, float val)
# 78 "/usr/local/cuda4.1/cuda/include/sm_20_atomic_functions.h"
{int volatile ___ = 1;(void)address;(void)val;
# 80 "/usr/local/cuda4.1/cuda/include/sm_20_atomic_functions.h"
exit(___);}
# 239 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned ballot(bool pred)
# 240 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
{int volatile ___ = 1;(void)pred;
# 242 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
exit(___);}
# 244 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline int syncthreads_count(bool pred)
# 245 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
{int volatile ___ = 1;(void)pred;
# 247 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
exit(___);}
# 249 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_and(bool pred)
# 250 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
{int volatile ___ = 1;(void)pred;
# 252 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
exit(___);}
# 254 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_or(bool pred)
# 255 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
{int volatile ___ = 1;(void)pred;
# 257 "/usr/local/cuda4.1/cuda/include/sm_20_intrinsics.h"
exit(___);}
# 99 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 100 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 101 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)s;(void)mode;
# 108 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 110 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 111 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 112 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 118 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 120 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 121 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 122 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)mode;
# 124 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 127 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 128 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 130 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 133 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 134 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 136 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 139 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 140 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 142 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 145 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 146 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 148 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 151 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 152 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 154 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 157 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 158 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 162 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 165 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 166 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 168 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 171 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 172 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 176 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 179 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 180 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 182 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 185 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 186 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 188 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 191 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 192 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 194 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 197 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 198 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 200 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 203 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 204 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 206 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 209 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 210 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 214 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 217 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 218 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 220 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 223 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 224 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 228 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 231 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 232 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 234 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 237 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 238 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 240 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 243 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 244 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 246 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 249 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 250 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 252 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 255 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 256 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 258 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 261 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 262 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 266 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 269 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 270 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 272 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 275 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 276 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 280 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 283 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 284 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 286 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 289 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 290 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 292 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 295 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 296 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 298 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 301 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 302 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 304 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 307 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 308 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 310 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 313 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 314 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 318 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 321 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 322 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 324 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 387 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 388 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 390 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 393 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 394 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 396 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 399 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 400 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 404 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 407 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 408 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 412 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 447 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 448 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 449 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)s;(void)mode;
# 456 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 458 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 459 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 460 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 466 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 468 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 469 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 470 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)mode;
# 472 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 475 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 476 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 478 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 481 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 482 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 484 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 487 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 488 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 490 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 493 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 494 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 496 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 499 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 500 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 502 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 505 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 506 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 510 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 513 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 514 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 516 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 519 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 520 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 524 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 527 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 528 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 530 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 533 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 534 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 536 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 539 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 540 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 542 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 545 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 546 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 548 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 551 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 552 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 554 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 557 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 558 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 562 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 565 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 566 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 568 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 571 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 572 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 576 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 579 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 580 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 582 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 585 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 586 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 588 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 591 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 592 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 594 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 597 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 598 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 600 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 603 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 604 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 606 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 609 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 610 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 614 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 617 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 618 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 620 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 623 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 624 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 628 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 631 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 632 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 634 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 637 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 638 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 640 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 643 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 644 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 646 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 649 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 650 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 652 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 655 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 656 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 658 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 661 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 662 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 666 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 669 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 670 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 672 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 735 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 736 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 738 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 741 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 742 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 744 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 747 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 748 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 752 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 755 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 756 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 760 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 795 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 796 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf3Dread(T *res, surface< void, 3> surf, int x, int y, int z, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 797 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)z;(void)s;(void)mode;
# 804 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 806 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 807 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 808 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 814 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 816 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 817 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf3Dread(T *res, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 818 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 820 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 823 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 824 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 826 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 829 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 830 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 832 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 835 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 836 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 838 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 841 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 842 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 844 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 847 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 848 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 850 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 853 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 854 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 858 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 861 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 862 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 864 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 867 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 868 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 872 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 875 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 876 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 878 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 881 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 882 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 884 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 887 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 888 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 890 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 893 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 894 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 896 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 899 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 900 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 902 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 905 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 906 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 910 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 913 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 914 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 916 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 919 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 920 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 924 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 927 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 928 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 930 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 933 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 934 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 936 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 939 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 940 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 942 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 945 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 946 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 948 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 951 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 952 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 954 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 957 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 958 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 962 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 965 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 966 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 968 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 971 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 972 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 976 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 979 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 980 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 982 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 985 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 986 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 988 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 991 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 992 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 994 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 997 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 998 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1000 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1003 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 1004 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1006 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1009 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 1010 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1014 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1017 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 1018 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1020 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1083 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 1084 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1086 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1089 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 1090 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1092 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1095 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 1096 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1100 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1103 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf3Dread(surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode)
# 1104 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1108 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1143 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1144 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1DLayeredread(T *res, surface< void, 241> surf, int x, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1145 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)layer;(void)s;(void)mode;
# 1152 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1154 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 1155 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1156 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1162 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1164 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1165 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1DLayeredread(T *res, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1166 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)layer;(void)mode;
# 1168 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1171 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1172 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1174 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1177 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1178 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1180 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1183 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1184 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1186 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1189 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1190 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1192 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1195 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1196 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1198 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1201 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1202 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1206 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1209 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1210 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1212 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1215 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1216 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1220 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1223 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1224 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1226 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1229 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1230 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1232 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1235 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1236 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1238 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1241 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1242 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1244 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1247 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1248 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1250 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1253 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1254 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1258 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1261 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1262 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1264 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1267 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1268 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1272 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1275 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1276 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1278 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1281 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1282 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1284 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1287 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1288 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1290 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1293 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1294 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1296 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1299 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1300 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1302 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1305 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1306 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1310 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1313 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1314 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1316 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1319 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1320 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1324 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1327 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1328 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1330 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1333 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1334 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1336 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1339 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1340 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1342 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1345 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1346 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1348 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1351 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1352 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1354 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1357 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1358 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1362 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1365 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1366 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1368 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1431 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1432 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1434 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1437 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1438 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1440 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1443 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1444 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1448 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1451 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf1DLayeredread(surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode)
# 1452 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 1456 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1491 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1492 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2DLayeredread(T *res, surface< void, 242> surf, int x, int y, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1493 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layer;(void)s;(void)mode;
# 1500 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1502 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 1503 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1504 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1510 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1512 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1513 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2DLayeredread(T *res, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1514 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1516 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1519 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1520 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1522 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1525 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1526 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1528 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1531 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1532 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1534 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1537 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1538 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1540 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1543 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1544 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1546 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1549 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1550 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1554 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1557 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1558 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1560 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1563 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1564 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1568 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1571 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1572 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1574 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1577 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1578 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1580 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1583 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1584 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1586 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1589 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1590 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1592 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1595 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1596 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1598 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1601 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1602 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1606 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1609 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1610 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1612 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1615 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1616 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1620 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1623 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1624 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1626 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1629 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1630 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1632 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1635 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1636 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1638 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1641 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1642 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1644 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1647 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1648 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1650 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1653 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1654 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1658 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1661 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1662 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1664 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1667 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1668 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1672 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1675 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1676 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1678 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1681 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1682 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1684 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1687 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1688 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1690 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1693 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1694 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1696 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1699 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1700 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1702 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1705 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1706 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1710 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1713 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1714 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1716 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1779 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1780 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1782 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1785 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1786 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1788 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1791 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1792 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1796 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1799 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf2DLayeredread(surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode)
# 1800 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1804 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1839 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1840 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapread(T *res, surface< void, 12> surf, int x, int y, int face, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1841 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)face;(void)s;(void)mode;
# 1848 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1850 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 1851 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1852 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1858 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1860 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1861 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapread(T *res, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1862 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1864 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1867 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1868 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1870 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1873 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1874 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1876 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1879 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1880 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1882 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1885 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1886 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1888 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1891 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1892 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1894 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1897 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1898 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1902 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1905 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1906 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1908 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1911 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1912 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1916 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1919 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1920 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1922 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1925 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1926 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1928 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1931 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1932 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1934 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1937 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1938 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1940 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1943 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1944 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1946 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1949 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1950 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1954 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1957 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1958 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1960 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1963 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1964 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1968 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1971 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1972 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1974 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1977 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1978 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1980 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1983 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1984 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1986 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1989 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1990 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1992 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 1995 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 1996 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1998 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2001 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2002 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2006 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2009 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2010 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2012 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2015 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2016 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2020 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2023 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2024 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2026 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2029 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline long long surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2030 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2032 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2035 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2036 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2038 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2041 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2042 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2044 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2047 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2048 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2050 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2053 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2054 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2058 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2061 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2062 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2064 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2127 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2128 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2130 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2133 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2134 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2136 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2139 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2140 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2144 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2147 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surfCubemapread(surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode)
# 2148 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 2152 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2188 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 2189 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapLayeredread(T *res, surface< void, 252> surf, int x, int y, int layerFace, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2190 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layerFace;(void)s;(void)mode;
# 2197 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2199 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 2200 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2201 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2207 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2209 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 2210 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapLayeredread(T *res, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2211 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2213 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2216 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2217 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2219 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2222 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2223 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2225 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2228 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2229 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2231 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2234 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2235 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2237 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2240 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2241 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2243 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2246 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2247 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2251 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2254 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2255 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2257 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2260 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2261 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2265 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2268 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2269 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2271 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2274 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2275 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2277 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2280 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2281 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2283 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2286 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2287 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2289 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2292 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2293 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2295 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2298 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2299 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2303 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2306 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2307 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2309 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2312 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2313 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2317 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2320 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2321 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2323 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2326 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2327 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2329 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2332 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2333 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2335 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2338 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2339 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2341 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2344 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2345 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2347 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2350 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2351 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2355 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2358 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2359 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2361 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2364 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2365 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2369 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2372 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2373 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2375 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2378 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline long long surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2379 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2381 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2384 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2385 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2387 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2390 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2391 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2393 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2396 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2397 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2399 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2402 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2403 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2407 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2410 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2411 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2413 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2476 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2477 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2479 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2482 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2483 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2485 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2488 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2489 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2493 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2496 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surfCubemapLayeredread(surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode)
# 2497 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2501 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2537 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 2538 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2539 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)s;(void)mode;
# 2557 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2559 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 2560 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2561 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2563 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2566 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2567 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2569 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2571 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2572 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2574 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2576 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2577 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2579 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2581 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2582 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2584 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2586 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2587 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2589 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2591 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2592 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2594 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2596 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2597 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2599 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2601 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2602 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2604 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2606 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2607 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2609 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2611 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2612 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2614 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2616 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2617 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2619 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2621 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2622 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2624 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2626 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2627 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2629 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2631 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2632 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2634 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2636 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2637 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2639 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2641 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2642 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2644 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2646 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2647 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2649 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2651 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2652 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2654 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2656 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2657 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2659 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2661 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2662 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2664 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2666 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2667 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2669 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2671 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2672 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2674 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2676 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2677 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2679 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2681 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2682 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2684 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2686 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2687 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2689 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2691 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2692 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2694 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2696 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2697 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2699 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2701 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2702 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2704 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2706 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2707 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2709 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2711 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2712 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2714 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2716 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2717 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2719 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2765 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2766 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2768 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2770 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2771 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2773 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2775 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2776 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2778 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2780 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2781 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 2783 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2819 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 2820 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2821 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)s;(void)mode;
# 2839 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2841 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 2842 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2843 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2845 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2848 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2849 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2851 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2853 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2854 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2856 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2858 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2859 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2861 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2863 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2864 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2866 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2868 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2869 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2871 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2873 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2874 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2876 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2878 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2879 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2881 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2883 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2884 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2886 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2888 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2889 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2891 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2893 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2894 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2896 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2898 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2899 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2901 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2903 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2904 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2906 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2908 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2909 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2911 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2913 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2914 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2916 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2918 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2919 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2921 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2923 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2924 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2926 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2928 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2929 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2931 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2933 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2934 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2936 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2938 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2939 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2941 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2943 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2944 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2946 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2948 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2949 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2951 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2953 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2954 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2956 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2958 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2959 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2961 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2963 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2964 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2966 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2968 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2969 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2971 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2973 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2974 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2976 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2978 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2979 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2981 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2983 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2984 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2986 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2988 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2989 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2991 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2993 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2994 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 2996 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 2998 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 2999 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 3001 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3047 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3048 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 3050 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3052 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3053 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 3055 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3057 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3058 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 3060 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3062 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3063 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 3065 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3101 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 3102 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf3Dwrite(T val, surface< void, 3> surf, int x, int y, int z, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3103 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)s;(void)mode;
# 3121 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3123 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 3124 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf3Dwrite(T val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3125 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3127 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3130 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(char val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3131 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3133 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3135 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(signed char val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3136 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3138 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3140 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(unsigned char val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3141 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3143 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3145 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(char1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3146 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3148 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3150 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(uchar1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3151 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3153 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3155 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(char2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3156 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3158 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3160 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(uchar2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3161 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3163 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3165 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(char4 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3166 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3168 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3170 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(uchar4 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3171 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3173 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3175 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(short val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3176 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3178 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3180 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(unsigned short val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3181 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3183 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3185 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(short1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3186 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3188 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3190 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(ushort1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3191 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3193 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3195 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(short2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3196 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3198 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3200 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(ushort2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3201 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3203 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3205 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(short4 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3206 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3208 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3210 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(ushort4 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3211 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3213 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3215 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(int val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3216 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3218 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3220 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(unsigned val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3221 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3223 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3225 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(int1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3226 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3228 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3230 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(uint1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3231 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3233 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3235 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(int2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3236 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3238 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3240 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(uint2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3241 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3243 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3245 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(int4 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3246 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3248 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3250 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(uint4 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3251 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3253 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3255 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(long long val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3256 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3258 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3260 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(unsigned long long val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3261 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3263 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3265 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(longlong1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3266 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3268 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3270 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(ulonglong1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3271 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3273 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3275 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(longlong2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3276 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3278 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3280 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(ulonglong2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3281 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3283 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3329 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(float val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3330 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3332 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3334 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(float1 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3335 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3337 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3339 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(float2 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3340 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3342 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3344 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf3Dwrite(float4 val, surface< void, 3> surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3345 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 3347 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3383 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 3384 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1DLayeredwrite(T val, surface< void, 241> surf, int x, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3385 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)s;(void)mode;
# 3403 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3405 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 3406 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf1DLayeredwrite(T val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3407 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3409 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3412 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(char val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3413 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3415 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3417 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(signed char val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3418 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3420 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3422 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(unsigned char val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3423 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3425 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3427 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(char1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3428 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3430 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3432 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(uchar1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3433 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3435 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3437 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(char2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3438 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3440 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3442 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(uchar2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3443 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3445 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3447 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(char4 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3448 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3450 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3452 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(uchar4 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3453 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3455 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3457 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(short val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3458 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3460 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3462 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(unsigned short val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3463 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3465 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3467 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(short1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3468 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3470 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3472 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(ushort1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3473 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3475 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3477 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(short2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3478 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3480 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3482 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(ushort2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3483 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3485 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3487 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(short4 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3488 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3490 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3492 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(ushort4 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3493 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3495 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3497 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(int val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3498 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3500 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3502 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(unsigned val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3503 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3505 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3507 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(int1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3508 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3510 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3512 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(uint1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3513 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3515 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3517 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(int2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3518 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3520 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3522 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(uint2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3523 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3525 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3527 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(int4 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3528 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3530 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3532 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(uint4 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3533 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3535 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3537 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(long long val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3538 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3540 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3542 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(unsigned long long val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3543 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3545 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3547 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(longlong1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3548 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3550 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3552 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(ulonglong1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3553 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3555 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3557 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(longlong2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3558 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3560 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3562 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(ulonglong2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3563 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3565 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3611 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(float val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3612 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3614 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3616 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(float1 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3617 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3619 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3621 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(float2 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3622 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3624 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3626 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf1DLayeredwrite(float4 val, surface< void, 241> surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3627 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 3629 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3665 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 3666 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2DLayeredwrite(T val, surface< void, 242> surf, int x, int y, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3667 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)s;(void)mode;
# 3685 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3687 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 3688 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surf2DLayeredwrite(T val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3689 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3691 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3694 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(char val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3695 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3697 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3699 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(signed char val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3700 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3702 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3704 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(unsigned char val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3705 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3707 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3709 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(char1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3710 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3712 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3714 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(uchar1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3715 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3717 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3719 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(char2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3720 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3722 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3724 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(uchar2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3725 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3727 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3729 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(char4 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3730 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3732 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3734 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(uchar4 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3735 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3737 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3739 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(short val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3740 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3742 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3744 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(unsigned short val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3745 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3747 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3749 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(short1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3750 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3752 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3754 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(ushort1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3755 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3757 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3759 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(short2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3760 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3762 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3764 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(ushort2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3765 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3767 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3769 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(short4 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3770 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3772 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3774 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(ushort4 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3775 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3777 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3779 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(int val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3780 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3782 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3784 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(unsigned val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3785 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3787 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3789 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(int1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3790 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3792 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3794 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(uint1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3795 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3797 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3799 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(int2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3800 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3802 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3804 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(uint2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3805 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3807 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3809 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(int4 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3810 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3812 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3814 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(uint4 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3815 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3817 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3819 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(long long val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3820 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3822 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3824 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(unsigned long long val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3825 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3827 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3829 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(longlong1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3830 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3832 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3834 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(ulonglong1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3835 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3837 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3839 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(longlong2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3840 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3842 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3844 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(ulonglong2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3845 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3847 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3893 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(float val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3894 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3896 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3898 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(float1 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3899 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3901 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3903 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(float2 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3904 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3906 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3908 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surf2DLayeredwrite(float4 val, surface< void, 242> surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3909 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 3911 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3947 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 3948 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapwrite(T val, surface< void, 12> surf, int x, int y, int face, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3949 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)s;(void)mode;
# 3967 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3969 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 3970 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapwrite(T val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3971 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 3973 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3976 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(char val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3977 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 3979 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3981 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(signed char val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3982 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 3984 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3986 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(unsigned char val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3987 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 3989 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3991 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(char1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3992 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 3994 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 3996 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(uchar1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 3997 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 3999 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4001 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(char2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4002 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4004 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4006 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(uchar2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4007 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4009 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4011 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(char4 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4012 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4014 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4016 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(uchar4 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4017 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4019 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4021 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(short val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4022 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4024 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4026 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(unsigned short val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4027 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4029 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4031 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(short1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4032 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4034 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4036 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(ushort1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4037 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4039 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4041 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(short2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4042 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4044 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4046 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(ushort2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4047 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4049 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4051 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(short4 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4052 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4054 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4056 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(ushort4 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4057 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4059 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4061 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(int val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4062 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4064 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4066 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(unsigned val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4067 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4069 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4071 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(int1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4072 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4074 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4076 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(uint1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4077 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4079 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4081 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(int2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4082 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4084 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4086 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(uint2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4087 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4089 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4091 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(int4 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4092 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4094 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4096 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(uint4 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4097 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4099 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4101 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(long long val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4102 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4104 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4106 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(unsigned long long val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4107 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4109 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4111 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(longlong1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4112 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4114 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4116 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(ulonglong1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4117 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4119 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4121 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(longlong2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4122 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4124 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4126 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(ulonglong2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4127 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4129 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4175 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(float val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4176 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4178 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4180 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(float1 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4181 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4183 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4185 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(float2 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4186 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4188 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4190 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapwrite(float4 val, surface< void, 12> surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4191 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 4193 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4229 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 4230 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapLayeredwrite(T val, surface< void, 252> surf, int x, int y, int layerFace, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4231 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)s;(void)mode;
# 4249 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4251 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 4252 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
surfCubemapLayeredwrite(T val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4253 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4255 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4258 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(char val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4259 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4261 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4263 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(signed char val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4264 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4266 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4268 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(unsigned char val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4269 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4271 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4273 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(char1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4274 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4276 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4278 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(uchar1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4279 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4281 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4283 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(char2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4284 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4286 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4288 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(uchar2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4289 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4291 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4293 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(char4 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4294 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4296 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4298 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(uchar4 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4299 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4301 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4303 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(short val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4304 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4306 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4308 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(unsigned short val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4309 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4311 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4313 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(short1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4314 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4316 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4318 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(ushort1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4319 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4321 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4323 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(short2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4324 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4326 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4328 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(ushort2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4329 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4331 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4333 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(short4 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4334 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4336 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4338 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(ushort4 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4339 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4341 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4343 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(int val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4344 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4346 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4348 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(unsigned val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4349 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4351 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4353 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(int1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4354 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4356 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4358 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(uint1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4359 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4361 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4363 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(int2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4364 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4366 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4368 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(uint2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4369 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4371 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4373 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(int4 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4374 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4376 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4378 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(uint4 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4379 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4381 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4383 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(long long val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4384 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4386 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4388 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(unsigned long long val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4389 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4391 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4393 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(longlong1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4394 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4396 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4398 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(ulonglong1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4399 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4401 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4403 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(longlong2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4404 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4406 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4408 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(ulonglong2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4409 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4411 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4457 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(float val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4458 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4460 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4462 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(float1 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4463 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4465 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4467 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(float2 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4468 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4470 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 4472 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
__attribute__((unused)) static inline void surfCubemapLayeredwrite(float4 val, surface< void, 252> surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 4473 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 4475 "/usr/local/cuda4.1/cuda/include/surface_functions.h"
exit(___);}
# 96 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 97 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 105 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 107 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 108 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 112 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 114 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 115 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 119 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 121 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 122 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 126 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 128 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 129 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 133 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 135 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 136 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 140 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 142 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 143 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 147 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 149 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 150 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 154 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 156 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 157 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 161 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 169 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 170 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 174 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 176 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 177 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 181 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 183 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 184 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 188 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 190 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 191 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 195 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 197 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 198 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 202 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 204 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 205 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 209 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 211 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 212 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 216 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 218 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 219 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 223 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 231 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 232 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 236 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 238 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 239 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 243 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 245 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 246 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 250 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 252 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 253 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 257 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 259 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 260 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 264 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 266 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 267 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 271 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 273 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 274 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 278 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 280 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 281 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 285 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 359 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 360 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 364 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 366 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 367 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 371 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 373 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 374 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 378 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 380 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 381 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 385 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 393 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 394 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 403 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 405 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 406 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 411 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 413 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 414 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 419 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 421 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 422 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 427 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 429 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 430 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 435 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 437 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 438 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 443 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 445 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 446 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 451 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 453 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 454 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 459 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 461 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 462 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 467 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 475 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 476 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 481 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 483 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 484 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 489 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 491 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 492 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 497 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 499 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 500 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 505 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 507 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 508 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 513 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 515 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 516 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 521 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 523 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 524 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 529 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 531 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 532 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 537 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 545 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 546 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 554 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 556 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 557 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 561 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 563 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 564 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 568 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 570 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 571 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 575 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 577 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 578 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 582 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 584 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 585 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 589 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 591 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 592 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 596 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 598 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 599 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 603 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 605 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 606 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 610 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 618 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 619 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 623 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 625 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 626 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 630 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 632 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 633 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 637 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 639 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 640 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 644 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 646 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 647 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 651 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 653 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 654 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 658 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 660 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 661 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 665 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 667 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 668 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 672 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 680 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 681 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 685 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 687 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 688 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 692 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 694 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 695 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 699 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 701 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 702 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 706 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 708 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 709 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 713 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 715 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 716 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 720 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 722 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 723 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 727 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 729 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 730 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 734 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 814 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 815 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 819 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 821 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 822 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 826 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 828 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 829 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 833 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 835 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 836 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 840 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 848 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 849 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 858 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 860 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 861 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 866 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 868 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 869 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 874 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 876 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 877 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 882 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 884 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 885 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 890 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 892 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 893 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 898 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 900 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 901 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 906 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 908 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 909 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 914 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 916 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 917 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 922 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 930 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 931 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 936 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 938 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 939 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 944 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 946 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 947 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 952 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 954 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 955 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 960 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 962 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 963 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 968 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 970 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 971 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 976 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 978 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 979 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 984 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 986 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 987 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;
# 992 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1000 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 1001 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1009 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1011 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 1012 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1016 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1018 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1019 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1023 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1025 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1026 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1030 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1032 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1033 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1037 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1039 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1040 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1044 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1046 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1047 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1051 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1053 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1054 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1058 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1060 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1061 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1065 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1073 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1074 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1078 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1080 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1081 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1085 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1087 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1088 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1092 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1094 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1095 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1099 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1101 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1102 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1106 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1108 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1109 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1113 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1115 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1116 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1120 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1122 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1123 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1127 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1135 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1136 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1140 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1142 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1143 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1147 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1149 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1150 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1154 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1156 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1157 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1161 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1163 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1164 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1168 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1170 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1171 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1175 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1177 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1178 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1182 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1184 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1185 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1189 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1263 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1264 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1268 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1270 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1271 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1275 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1277 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1278 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1282 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1284 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1285 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1289 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1297 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1298 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1307 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1309 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1310 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1315 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1317 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1318 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1323 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1325 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1326 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1331 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1333 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1334 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1339 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1341 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1342 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1347 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1349 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1350 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1355 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1357 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1358 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1363 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1365 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1366 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1371 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1379 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1380 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1385 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1387 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1388 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1393 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1395 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1396 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1401 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1403 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1404 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1409 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1411 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1412 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1417 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1419 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1420 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1425 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1427 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1428 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1433 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1435 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1436 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;
# 1441 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1449 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1DLayered(texture< char, 241, cudaReadModeElementType> t, float x, int layer)
# 1450 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1458 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1460 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1DLayered(texture< signed char, 241, cudaReadModeElementType> t, float x, int layer)
# 1461 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1465 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1467 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1DLayered(texture< unsigned char, 241, cudaReadModeElementType> t, float x, int layer)
# 1468 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1472 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1474 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1DLayered(texture< char1, 241, cudaReadModeElementType> t, float x, int layer)
# 1475 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1479 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1481 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1DLayered(texture< uchar1, 241, cudaReadModeElementType> t, float x, int layer)
# 1482 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1486 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1488 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1DLayered(texture< char2, 241, cudaReadModeElementType> t, float x, int layer)
# 1489 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1493 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1495 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1DLayered(texture< uchar2, 241, cudaReadModeElementType> t, float x, int layer)
# 1496 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1500 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1502 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1DLayered(texture< char4, 241, cudaReadModeElementType> t, float x, int layer)
# 1503 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1507 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1509 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1DLayered(texture< uchar4, 241, cudaReadModeElementType> t, float x, int layer)
# 1510 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1514 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1522 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1DLayered(texture< short, 241, cudaReadModeElementType> t, float x, int layer)
# 1523 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1527 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1529 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1DLayered(texture< unsigned short, 241, cudaReadModeElementType> t, float x, int layer)
# 1530 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1534 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1536 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1DLayered(texture< short1, 241, cudaReadModeElementType> t, float x, int layer)
# 1537 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1541 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1543 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1DLayered(texture< ushort1, 241, cudaReadModeElementType> t, float x, int layer)
# 1544 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1548 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1550 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1DLayered(texture< short2, 241, cudaReadModeElementType> t, float x, int layer)
# 1551 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1555 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1557 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1DLayered(texture< ushort2, 241, cudaReadModeElementType> t, float x, int layer)
# 1558 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1562 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1564 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1DLayered(texture< short4, 241, cudaReadModeElementType> t, float x, int layer)
# 1565 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1569 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1571 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1DLayered(texture< ushort4, 241, cudaReadModeElementType> t, float x, int layer)
# 1572 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1576 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1584 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1DLayered(texture< int, 241, cudaReadModeElementType> t, float x, int layer)
# 1585 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1589 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1591 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1DLayered(texture< unsigned, 241, cudaReadModeElementType> t, float x, int layer)
# 1592 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1596 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1598 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1DLayered(texture< int1, 241, cudaReadModeElementType> t, float x, int layer)
# 1599 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1603 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1605 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1DLayered(texture< uint1, 241, cudaReadModeElementType> t, float x, int layer)
# 1606 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1610 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1612 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1DLayered(texture< int2, 241, cudaReadModeElementType> t, float x, int layer)
# 1613 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1617 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1619 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1DLayered(texture< uint2, 241, cudaReadModeElementType> t, float x, int layer)
# 1620 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1624 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1626 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1DLayered(texture< int4, 241, cudaReadModeElementType> t, float x, int layer)
# 1627 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1631 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1633 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1DLayered(texture< uint4, 241, cudaReadModeElementType> t, float x, int layer)
# 1634 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1638 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1712 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< float, 241, cudaReadModeElementType> t, float x, int layer)
# 1713 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1717 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1719 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< float1, 241, cudaReadModeElementType> t, float x, int layer)
# 1720 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1724 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1726 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< float2, 241, cudaReadModeElementType> t, float x, int layer)
# 1727 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1731 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1733 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< float4, 241, cudaReadModeElementType> t, float x, int layer)
# 1734 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1738 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1746 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< char, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1747 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1756 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1758 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< signed char, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1759 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1764 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1766 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< unsigned char, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1767 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1772 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1774 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< char1, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1775 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1780 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1782 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< uchar1, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1783 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1788 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1790 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< char2, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1791 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1796 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1798 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< uchar2, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1799 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1804 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1806 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< char4, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1807 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1812 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1814 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< uchar4, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1815 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1820 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1828 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< short, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1829 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1834 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1836 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1DLayered(texture< unsigned short, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1837 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1842 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1844 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< short1, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1845 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1850 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1852 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1DLayered(texture< ushort1, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1853 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1858 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1860 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< short2, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1861 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1866 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1868 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1DLayered(texture< ushort2, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1869 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1874 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1876 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< short4, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1877 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1882 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1884 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1DLayered(texture< ushort4, 241, cudaReadModeNormalizedFloat> t, float x, int layer)
# 1885 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)layer;
# 1890 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1898 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex2DLayered(texture< char, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1899 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1907 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1909 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex2DLayered(texture< signed char, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1910 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1914 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1916 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex2DLayered(texture< unsigned char, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1917 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1921 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1923 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex2DLayered(texture< char1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1924 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1928 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1930 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex2DLayered(texture< uchar1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1931 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1935 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1937 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex2DLayered(texture< char2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1938 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1942 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1944 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex2DLayered(texture< uchar2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1945 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1949 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1951 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2DLayered(texture< char4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1952 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1956 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1958 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2DLayered(texture< uchar4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1959 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1963 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1971 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex2DLayered(texture< short, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1972 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1976 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1978 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex2DLayered(texture< unsigned short, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1979 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1983 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1985 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex2DLayered(texture< short1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1986 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1990 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1992 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex2DLayered(texture< ushort1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 1993 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 1997 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 1999 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex2DLayered(texture< short2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2000 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2004 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2006 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex2DLayered(texture< ushort2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2007 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2011 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2013 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2DLayered(texture< short4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2014 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2018 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2020 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2DLayered(texture< ushort4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2021 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2025 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2033 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex2DLayered(texture< int, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2034 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2038 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2040 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex2DLayered(texture< unsigned, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2041 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2045 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2047 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex2DLayered(texture< int1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2048 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2052 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2054 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex2DLayered(texture< uint1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2055 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2059 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2061 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex2DLayered(texture< int2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2062 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2066 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2068 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex2DLayered(texture< uint2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2069 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2073 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2075 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2DLayered(texture< int4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2076 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2080 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2082 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2DLayered(texture< uint4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2083 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2087 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2161 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< float, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2162 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2166 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2168 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< float1, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2169 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2173 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2175 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< float2, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2176 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2180 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2182 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< float4, 242, cudaReadModeElementType> t, float x, float y, int layer)
# 2183 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2187 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2195 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< char, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2196 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2205 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2207 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< signed char, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2208 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2213 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2215 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< unsigned char, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2216 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2221 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2223 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< char1, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2224 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2229 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2231 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< uchar1, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2232 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2237 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2239 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< char2, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2240 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2245 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2247 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< uchar2, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2248 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2253 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2255 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< char4, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2256 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2261 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2263 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< uchar4, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2264 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2269 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2277 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< short, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2278 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2283 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2285 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2DLayered(texture< unsigned short, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2286 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2291 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2293 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< short1, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2294 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2299 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2301 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2DLayered(texture< ushort1, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2302 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2307 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2309 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< short2, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2310 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2315 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2317 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2DLayered(texture< ushort2, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2318 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2323 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2325 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< short4, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2326 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2331 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2333 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2DLayered(texture< ushort4, 242, cudaReadModeNormalizedFloat> t, float x, float y, int layer)
# 2334 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)layer;
# 2339 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2347 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2348 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2356 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2358 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2359 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2363 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2365 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2366 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2370 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2372 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2373 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2377 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2379 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2380 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2384 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2386 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2387 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2391 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2393 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2394 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2398 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2400 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2401 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2405 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2407 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2408 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2412 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2420 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2421 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2425 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2427 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2428 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2432 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2434 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2435 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2439 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2441 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2442 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2446 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2448 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2449 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2453 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2455 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2456 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2460 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2462 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2463 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2467 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2469 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2470 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2474 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2482 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2483 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2487 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2489 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2490 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2494 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2496 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2497 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2501 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2503 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2504 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2508 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2510 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2511 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2515 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2517 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2518 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2522 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2524 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2525 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2529 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2531 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2532 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2536 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2610 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2611 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2615 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2617 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2618 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2622 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2624 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2625 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2629 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2631 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 2632 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2636 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2644 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2645 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2654 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2656 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2657 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2662 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2664 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2665 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2670 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2672 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2673 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2678 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2680 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2681 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2686 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2688 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2689 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2694 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2696 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2697 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2702 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2704 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2705 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2710 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2712 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2713 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2718 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2726 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2727 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2732 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2734 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2735 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2740 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2742 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2743 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2748 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2750 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2751 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2756 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2758 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2759 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2764 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2766 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2767 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2772 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2774 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2775 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2780 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2782 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 2783 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2788 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2796 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char texCubemap(texture< char, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2797 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2805 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2807 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char texCubemap(texture< signed char, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2808 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2812 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2814 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char texCubemap(texture< unsigned char, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2815 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2819 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2821 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 texCubemap(texture< char1, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2822 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2826 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2828 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 texCubemap(texture< uchar1, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2829 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2833 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2835 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 texCubemap(texture< char2, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2836 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2840 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2842 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 texCubemap(texture< uchar2, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2843 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2847 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2849 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 texCubemap(texture< char4, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2850 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2854 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2856 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 texCubemap(texture< uchar4, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2857 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2861 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2869 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short texCubemap(texture< short, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2870 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2874 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2876 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short texCubemap(texture< unsigned short, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2877 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2881 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2883 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 texCubemap(texture< short1, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2884 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2888 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2890 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 texCubemap(texture< ushort1, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2891 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2895 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2897 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 texCubemap(texture< short2, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2898 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2902 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2904 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 texCubemap(texture< ushort2, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2905 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2909 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2911 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 texCubemap(texture< short4, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2912 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2916 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2918 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 texCubemap(texture< ushort4, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2919 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2923 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2931 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int texCubemap(texture< int, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2932 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2936 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2938 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned texCubemap(texture< unsigned, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2939 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2943 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2945 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 texCubemap(texture< int1, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2946 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2950 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2952 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 texCubemap(texture< uint1, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2953 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2957 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2959 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 texCubemap(texture< int2, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2960 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2964 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2966 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 texCubemap(texture< uint2, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2967 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2971 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2973 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 texCubemap(texture< int4, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2974 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2978 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 2980 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 texCubemap(texture< uint4, 12, cudaReadModeElementType> t, float x, float y, float z)
# 2981 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 2985 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3059 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemap(texture< float, 12, cudaReadModeElementType> t, float x, float y, float z)
# 3060 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3064 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3066 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemap(texture< float1, 12, cudaReadModeElementType> t, float x, float y, float z)
# 3067 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3071 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3073 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemap(texture< float2, 12, cudaReadModeElementType> t, float x, float y, float z)
# 3074 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3078 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3080 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemap(texture< float4, 12, cudaReadModeElementType> t, float x, float y, float z)
# 3081 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3085 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3093 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemap(texture< char, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3094 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3103 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3105 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemap(texture< signed char, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3106 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3111 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3113 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemap(texture< unsigned char, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3114 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3119 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3121 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemap(texture< char1, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3122 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3127 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3129 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemap(texture< uchar1, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3130 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3135 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3137 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemap(texture< char2, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3138 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3143 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3145 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemap(texture< uchar2, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3146 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3151 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3153 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemap(texture< char4, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3154 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3159 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3161 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemap(texture< uchar4, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3162 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3167 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3175 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemap(texture< short, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3176 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3181 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3183 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemap(texture< unsigned short, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3184 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3189 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3191 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemap(texture< short1, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3192 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3197 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3199 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemap(texture< ushort1, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3200 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3205 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3207 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemap(texture< short2, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3208 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3213 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3215 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemap(texture< ushort2, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3216 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3221 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3223 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemap(texture< short4, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3224 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3229 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3231 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemap(texture< ushort4, 12, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 3232 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;
# 3237 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3245 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char texCubemapLayered(texture< char, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3246 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3254 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3256 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char texCubemapLayered(texture< signed char, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3257 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3261 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3263 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char texCubemapLayered(texture< unsigned char, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3264 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3268 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3270 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 texCubemapLayered(texture< char1, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3271 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3275 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3277 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 texCubemapLayered(texture< uchar1, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3278 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3282 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3284 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 texCubemapLayered(texture< char2, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3285 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3289 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3291 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 texCubemapLayered(texture< uchar2, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3292 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3296 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3298 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 texCubemapLayered(texture< char4, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3299 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3303 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3305 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 texCubemapLayered(texture< uchar4, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3306 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3310 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3318 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short texCubemapLayered(texture< short, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3319 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3323 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3325 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short texCubemapLayered(texture< unsigned short, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3326 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3330 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3332 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 texCubemapLayered(texture< short1, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3333 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3337 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3339 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 texCubemapLayered(texture< ushort1, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3340 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3344 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3346 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 texCubemapLayered(texture< short2, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3347 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3351 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3353 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 texCubemapLayered(texture< ushort2, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3354 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3358 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3360 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 texCubemapLayered(texture< short4, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3361 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3365 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3367 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 texCubemapLayered(texture< ushort4, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3368 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3372 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3380 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int texCubemapLayered(texture< int, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3381 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3385 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3387 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned texCubemapLayered(texture< unsigned, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3388 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3392 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3394 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 texCubemapLayered(texture< int1, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3395 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3399 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3401 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 texCubemapLayered(texture< uint1, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3402 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3406 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3408 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 texCubemapLayered(texture< int2, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3409 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3413 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3415 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 texCubemapLayered(texture< uint2, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3416 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3420 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3422 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 texCubemapLayered(texture< int4, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3423 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3427 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3429 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 texCubemapLayered(texture< uint4, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3430 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3434 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3508 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemapLayered(texture< float, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3509 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3513 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3515 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemapLayered(texture< float1, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3516 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3520 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3522 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemapLayered(texture< float2, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3523 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3527 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3529 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemapLayered(texture< float4, 252, cudaReadModeElementType> t, float x, float y, float z, int layer)
# 3530 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3534 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3542 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemapLayered(texture< char, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3543 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3552 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3554 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemapLayered(texture< signed char, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3555 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3560 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3562 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemapLayered(texture< unsigned char, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3563 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3568 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3570 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemapLayered(texture< char1, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3571 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3576 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3578 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemapLayered(texture< uchar1, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3579 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3584 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3586 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemapLayered(texture< char2, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3587 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3592 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3594 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemapLayered(texture< uchar2, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3595 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3600 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3602 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemapLayered(texture< char4, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3603 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3608 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3610 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemapLayered(texture< uchar4, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3611 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3616 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3624 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemapLayered(texture< short, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3625 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3630 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3632 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float texCubemapLayered(texture< unsigned short, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3633 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3638 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3640 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemapLayered(texture< short1, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3641 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3646 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3648 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 texCubemapLayered(texture< ushort1, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3649 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3654 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3656 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemapLayered(texture< short2, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3657 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3662 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3664 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 texCubemapLayered(texture< ushort2, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3665 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3670 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3672 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemapLayered(texture< short4, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3673 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3678 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3680 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 texCubemapLayered(texture< ushort4, 252, cudaReadModeNormalizedFloat> t, float x, float y, float z, int layer)
# 3681 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)z;(void)layer;
# 3686 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3780 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3781 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3783 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3785 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< signed char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3786 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3788 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3790 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3791 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3793 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3795 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3796 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3798 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3800 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3801 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3803 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3805 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3806 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3808 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3810 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3811 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3813 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3815 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3816 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3818 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3820 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3821 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3823 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3825 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3826 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3828 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3830 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3831 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3833 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3835 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3836 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3838 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3840 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3841 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3843 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3845 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3846 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3848 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3850 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3851 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3853 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3855 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3856 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3858 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3860 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3861 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3863 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3865 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3866 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3868 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3870 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3871 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3873 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3875 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3876 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3878 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3880 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3881 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3883 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3885 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3886 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3888 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3890 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3891 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3893 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3895 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3896 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3898 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3900 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3901 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3903 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3905 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3906 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3908 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3910 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3911 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3913 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3915 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3916 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3918 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3920 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3921 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3923 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3925 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3926 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3928 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3930 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3931 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3933 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3935 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3936 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3938 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3940 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3941 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3943 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3945 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3946 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3948 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3950 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3951 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3953 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3955 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 3956 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3958 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3967 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 3968 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3970 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3972 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 3973 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3975 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3977 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 3978 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3980 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3982 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 3983 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3985 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3987 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 3988 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3990 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3992 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 3993 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 3995 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 3997 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 3998 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4000 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4002 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< char3, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4003 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4005 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4007 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< uchar3, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4008 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4010 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4012 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4013 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4015 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4017 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4018 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4020 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4022 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4023 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4025 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4027 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4028 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4030 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4032 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4033 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4035 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4037 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4038 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4040 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4042 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4043 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4045 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4047 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4048 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4050 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4052 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< short3, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4053 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4055 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4057 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< ushort3, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4058 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4060 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4062 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4063 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4065 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 4067 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y, int comp = 0)
# 4068 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
{int volatile ___ = 1;(void)t;(void)x;(void)y;(void)comp;
# 4070 "/usr/local/cuda4.1/cuda/include/texture_fetch_functions.h"
exit(___);}
# 66 "/usr/local/cuda4.1/cuda/include/device_launch_parameters.h"
extern "C" { extern const uint3 threadIdx; }
# 67 "/usr/local/cuda4.1/cuda/include/device_launch_parameters.h"
extern "C" { extern const uint3 blockIdx; }
# 68 "/usr/local/cuda4.1/cuda/include/device_launch_parameters.h"
extern "C" { extern const dim3 blockDim; }
# 69 "/usr/local/cuda4.1/cuda/include/device_launch_parameters.h"
extern "C" { extern const dim3 gridDim; }
# 70 "/usr/local/cuda4.1/cuda/include/device_launch_parameters.h"
extern "C" { extern const int warpSize; }
# 120 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 121 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaSetupArgument(T
# 122 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
arg, size_t
# 123 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset)
# 125 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 126 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 127 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 159 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
static inline cudaError_t cudaEventCreate(cudaEvent_t *
# 160 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
event, unsigned
# 161 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
flags)
# 163 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 164 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaEventCreateWithFlags(event, flags);
# 165 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 222 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
static inline cudaError_t cudaMallocHost(void **
# 223 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
ptr, size_t
# 224 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
size, unsigned
# 225 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
flags)
# 227 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 228 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaHostAlloc(ptr, size, flags);
# 229 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 231 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 232 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaHostAlloc(T **
# 233 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
ptr, size_t
# 234 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
size, unsigned
# 235 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
flags)
# 237 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 238 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 239 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 241 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 242 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 243 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
pDevice, void *
# 244 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
pHost, unsigned
# 245 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
flags)
# 247 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 248 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 249 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 251 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 252 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaMalloc(T **
# 253 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
devPtr, size_t
# 254 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
size)
# 256 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 257 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 258 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 260 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 261 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaMallocHost(T **
# 262 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
ptr, size_t
# 263 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
size, unsigned
# 264 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
flags = (0))
# 266 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 267 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size, flags);
# 268 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 270 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 271 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaMallocPitch(T **
# 272 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
devPtr, size_t *
# 273 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
pitch, size_t
# 274 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
width, size_t
# 275 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
height)
# 277 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 278 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 279 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 289 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 290 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol, const void *
# 291 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
src, size_t
# 292 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
count, size_t
# 293 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 294 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 296 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 297 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 298 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 300 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 301 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 302 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol, const void *
# 303 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
src, size_t
# 304 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
count, size_t
# 305 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 306 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 308 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 309 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 310 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 312 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 313 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol, const void *
# 314 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
src, size_t
# 315 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
count, size_t
# 316 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 317 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 318 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
stream = 0)
# 320 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 321 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 322 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 324 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 325 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 326 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol, const void *
# 327 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
src, size_t
# 328 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
count, size_t
# 329 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 330 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 331 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
stream = 0)
# 333 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 334 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 335 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 343 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 344 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
dst, char *
# 345 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol, size_t
# 346 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
count, size_t
# 347 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 348 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 350 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 351 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 352 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 354 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 355 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 356 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
dst, const T &
# 357 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol, size_t
# 358 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
count, size_t
# 359 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 360 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 362 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 363 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 364 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 366 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 367 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
dst, char *
# 368 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol, size_t
# 369 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
count, size_t
# 370 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 371 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 372 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
stream = 0)
# 374 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 375 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 376 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 378 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 379 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 380 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
dst, const T &
# 381 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol, size_t
# 382 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
count, size_t
# 383 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 384 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 385 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
stream = 0)
# 387 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 388 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 389 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 391 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 392 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
devPtr, char *
# 393 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol)
# 395 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 396 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 397 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 424 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 425 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 426 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
devPtr, const T &
# 427 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol)
# 429 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 430 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 431 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 439 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 440 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
size, char *
# 441 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol)
# 443 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 444 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 445 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 472 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 473 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 474 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
size, const T &
# 475 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
symbol)
# 477 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 478 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 479 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 521 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 522 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaBindTexture(size_t *
# 523 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 524 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
tex, const void *
# 525 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 526 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
desc, size_t
# 527 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 529 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 530 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 531 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 566 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 567 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaBindTexture(size_t *
# 568 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 569 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
tex, const void *
# 570 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
devPtr, size_t
# 571 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 573 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 574 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
# 575 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 622 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 623 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 624 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 625 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
tex, const void *
# 626 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 627 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
desc, size_t
# 628 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
width, size_t
# 629 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
height, size_t
# 630 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
pitch)
# 632 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 633 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 634 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 680 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 681 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 682 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 683 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
tex, const void *
# 684 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
devPtr, size_t
# 685 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
width, size_t
# 686 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
height, size_t
# 687 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
pitch)
# 689 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 690 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &(tex.texture< T, dim, readMode> ::channelDesc), width, height, pitch);
# 691 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 722 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 723 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 724 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
tex, const cudaArray *
# 725 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 726 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
desc)
# 728 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 729 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 730 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 760 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 761 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 762 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
tex, const cudaArray *
# 763 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
array)
# 765 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 766 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 767 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 769 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 770 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 799 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 800 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 801 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
tex)
# 803 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 804 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 805 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 839 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 840 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 841 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 842 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
tex)
# 844 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 845 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 846 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 900 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 901 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaFuncSetCacheConfig(T *
# 902 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
func, cudaFuncCache
# 903 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cacheConfig)
# 905 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 906 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaFuncSetCacheConfig((const char *)func, cacheConfig);
# 907 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 944 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 945 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaLaunch(T *
# 946 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
entry)
# 948 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 949 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 950 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 984 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T> inline cudaError_t
# 985 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 986 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
attr, T *
# 987 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
entry)
# 989 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 990 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 991 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 1013 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1014 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1015 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
surf, const cudaArray *
# 1016 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 1017 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
desc)
# 1019 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 1020 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return cudaBindSurfaceToArray(&surf, array, &desc);
# 1021 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
# 1042 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1043 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1044 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
surf, const cudaArray *
# 1045 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
array)
# 1047 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
{
# 1048 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 1049 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 1051 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err;
# 1052 "/usr/local/cuda4.1/cuda/include/cuda_runtime.h"
}
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
# 40 "/usr/lib/x86_64-linux-gnu/gcc/x86_64-linux-gnu/4.5.2/include/stdarg.h" 3
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
# 157 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef unsigned long long CUdeviceptr; }
# 164 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef int CUdevice; }
# 165 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 166 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 167 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 168 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 169 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 170 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef struct CUsurfref_st *CUsurfref; }
# 171 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef CUevent_st *CUevent; }
# 172 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef CUstream_st *CUstream; }
# 173 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef struct CUgraphicsResource_st *CUgraphicsResource; }
# 177 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 175 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUuuid_st {
# 176 "/usr/local/cuda4.1/cuda/include/cuda.h"
char bytes[16];
# 177 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUuuid; }
# 189 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 187 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUipcEventHandle_st {
# 188 "/usr/local/cuda4.1/cuda/include/cuda.h"
char reserved[64];
# 189 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUipcEventHandle; }
# 193 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 191 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUipcMemHandle_st {
# 192 "/usr/local/cuda4.1/cuda/include/cuda.h"
char reserved[64];
# 193 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUipcMemHandle; }
# 212 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 200 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUctx_flags_enum {
# 201 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_SCHED_AUTO,
# 202 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_SCHED_SPIN,
# 203 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_SCHED_YIELD,
# 204 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_SCHED_BLOCKING_SYNC = 4,
# 205 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_BLOCKING_SYNC = 4,
# 208 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_SCHED_MASK = 7,
# 209 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_MAP_HOST,
# 210 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 211 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CTX_FLAGS_MASK = 31
# 212 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUctx_flags; }
# 222 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 217 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUevent_flags_enum {
# 218 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_EVENT_DEFAULT,
# 219 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_EVENT_BLOCKING_SYNC,
# 220 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_EVENT_DISABLE_TIMING,
# 221 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_EVENT_INTERPROCESS = 4
# 222 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUevent_flags; }
# 236 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 227 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUarray_format_enum {
# 228 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 229 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 230 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 231 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 232 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 233 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 234 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 235 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 236 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUarray_format; }
# 246 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 241 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUaddress_mode_enum {
# 242 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 243 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 244 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR,
# 245 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TR_ADDRESS_MODE_BORDER
# 246 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUaddress_mode; }
# 254 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 251 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUfilter_mode_enum {
# 252 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 253 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 254 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUfilter_mode; }
# 337 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 259 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUdevice_attribute_enum {
# 260 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 261 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 262 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 263 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 264 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 265 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 266 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 267 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 268 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 269 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 270 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 271 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 272 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 273 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 274 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 275 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 276 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 277 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 278 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 279 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 280 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 281 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 282 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 283 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 284 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 285 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 286 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 287 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 288 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH,
# 289 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT,
# 290 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS,
# 291 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH = 27,
# 292 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 293 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES,
# 294 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT,
# 295 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS,
# 296 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_ECC_ENABLED,
# 297 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_BUS_ID,
# 298 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID,
# 299 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_TCC_DRIVER,
# 300 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE,
# 301 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH,
# 302 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE,
# 303 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR,
# 304 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT,
# 305 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING,
# 306 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH,
# 307 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS,
# 308 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_TEX2D_GATHER,
# 309 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH,
# 310 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT,
# 311 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE,
# 312 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE,
# 313 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE,
# 314 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID,
# 315 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT,
# 316 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH,
# 317 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH,
# 318 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS,
# 319 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH,
# 320 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH,
# 321 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT,
# 322 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH,
# 323 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT,
# 324 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH,
# 325 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH,
# 326 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS,
# 327 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH,
# 328 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT,
# 329 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LAYERS,
# 330 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH,
# 331 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH,
# 332 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS,
# 333 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH,
# 334 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH,
# 335 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT,
# 336 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH
# 337 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUdevice_attribute; }
# 353 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 342 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUdevprop_st {
# 343 "/usr/local/cuda4.1/cuda/include/cuda.h"
int maxThreadsPerBlock;
# 344 "/usr/local/cuda4.1/cuda/include/cuda.h"
int maxThreadsDim[3];
# 345 "/usr/local/cuda4.1/cuda/include/cuda.h"
int maxGridSize[3];
# 346 "/usr/local/cuda4.1/cuda/include/cuda.h"
int sharedMemPerBlock;
# 347 "/usr/local/cuda4.1/cuda/include/cuda.h"
int totalConstantMemory;
# 348 "/usr/local/cuda4.1/cuda/include/cuda.h"
int SIMDWidth;
# 349 "/usr/local/cuda4.1/cuda/include/cuda.h"
int memPitch;
# 350 "/usr/local/cuda4.1/cuda/include/cuda.h"
int regsPerBlock;
# 351 "/usr/local/cuda4.1/cuda/include/cuda.h"
int clockRate;
# 352 "/usr/local/cuda4.1/cuda/include/cuda.h"
int textureAlign;
# 353 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUdevprop; }
# 363 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 358 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUpointer_attribute_enum {
# 359 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_POINTER_ATTRIBUTE_CONTEXT = 1,
# 360 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_POINTER_ATTRIBUTE_MEMORY_TYPE,
# 361 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_POINTER_ATTRIBUTE_DEVICE_POINTER,
# 362 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_POINTER_ATTRIBUTE_HOST_POINTER
# 363 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUpointer_attribute; }
# 418 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 368 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUfunction_attribute_enum {
# 374 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 381 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 387 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 392 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 397 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 406 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_ATTRIBUTE_PTX_VERSION,
# 415 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_ATTRIBUTE_BINARY_VERSION,
# 417 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 418 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUfunction_attribute; }
# 428 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 423 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUfunc_cache_enum {
# 424 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_CACHE_PREFER_NONE,
# 425 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_CACHE_PREFER_SHARED,
# 426 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_CACHE_PREFER_L1,
# 427 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_FUNC_CACHE_PREFER_EQUAL
# 428 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUfunc_cache; }
# 438 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 433 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUmemorytype_enum {
# 434 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 435 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 436 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_MEMORYTYPE_ARRAY,
# 437 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_MEMORYTYPE_UNIFIED
# 438 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUmemorytype; }
# 448 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 443 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUcomputemode_enum {
# 444 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 445 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 446 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_COMPUTEMODE_PROHIBITED,
# 447 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE_PROCESS
# 448 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUcomputemode; }
# 540 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 453 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUjit_option_enum {
# 459 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 472 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 479 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_WALL_TIME,
# 487 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 495 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 503 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 511 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 518 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 525 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 531 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_TARGET,
# 538 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 540 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUjit_option; }
# 553 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 545 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUjit_target_enum {
# 547 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TARGET_COMPUTE_10,
# 548 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TARGET_COMPUTE_11,
# 549 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TARGET_COMPUTE_12,
# 550 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TARGET_COMPUTE_13,
# 551 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TARGET_COMPUTE_20,
# 552 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_TARGET_COMPUTE_21
# 553 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUjit_target; }
# 564 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 558 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUjit_fallback_enum {
# 560 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_PREFER_PTX,
# 562 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_PREFER_BINARY
# 564 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUjit_fallback; }
# 575 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 569 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 570 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE,
# 571 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY,
# 572 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD,
# 573 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST = 4,
# 574 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER = 8
# 575 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUgraphicsRegisterFlags; }
# 584 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 580 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 581 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 582 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 583 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 584 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 596 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 589 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUarray_cubemap_face_enum {
# 590 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 591 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 592 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 593 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 594 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 595 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 596 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUarray_cubemap_face; }
# 605 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 601 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum CUlimit_enum {
# 602 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_LIMIT_STACK_SIZE,
# 603 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_LIMIT_PRINTF_FIFO_SIZE,
# 604 "/usr/local/cuda4.1/cuda/include/cuda.h"
CU_LIMIT_MALLOC_HEAP_SIZE
# 605 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUlimit; }
# 914 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 610 "/usr/local/cuda4.1/cuda/include/cuda.h"
enum cudaError_enum {
# 616 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_SUCCESS,
# 622 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 628 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 634 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 639 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 645 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_PROFILER_DISABLED,
# 650 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_PROFILER_NOT_INITIALIZED,
# 655 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_PROFILER_ALREADY_STARTED,
# 660 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_PROFILER_ALREADY_STOPPED,
# 665 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 671 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 678 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 688 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 697 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 702 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 707 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 713 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 718 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 726 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 731 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 736 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 742 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 748 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 754 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_ECC_UNCORRECTABLE,
# 760 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_UNSUPPORTED_LIMIT,
# 767 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_IN_USE,
# 772 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 777 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 782 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
# 787 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
# 792 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_OPERATING_SYSTEM,
# 799 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 806 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 815 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 826 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 837 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 848 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 854 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 861 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED,
# 868 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_PEER_ACCESS_NOT_ENABLED,
# 874 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE = 708,
# 881 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_CONTEXT_IS_DESTROYED,
# 889 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_ASSERT,
# 896 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_TOO_MANY_PEERS,
# 902 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED,
# 908 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED,
# 913 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 914 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUresult; }
# 976 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 955 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 956 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcXInBytes;
# 957 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcY;
# 959 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUmemorytype srcMemoryType;
# 960 "/usr/local/cuda4.1/cuda/include/cuda.h"
const void *srcHost;
# 961 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUdeviceptr srcDevice;
# 962 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUarray srcArray;
# 963 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcPitch;
# 965 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstXInBytes;
# 966 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstY;
# 968 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUmemorytype dstMemoryType;
# 969 "/usr/local/cuda4.1/cuda/include/cuda.h"
void *dstHost;
# 970 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUdeviceptr dstDevice;
# 971 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUarray dstArray;
# 972 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstPitch;
# 974 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t WidthInBytes;
# 975 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Height;
# 976 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUDA_MEMCPY2D; }
# 1009 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 981 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 982 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcXInBytes;
# 983 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcY;
# 984 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcZ;
# 985 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcLOD;
# 986 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUmemorytype srcMemoryType;
# 987 "/usr/local/cuda4.1/cuda/include/cuda.h"
const void *srcHost;
# 988 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUdeviceptr srcDevice;
# 989 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUarray srcArray;
# 990 "/usr/local/cuda4.1/cuda/include/cuda.h"
void *reserved0;
# 991 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcPitch;
# 992 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcHeight;
# 994 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstXInBytes;
# 995 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstY;
# 996 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstZ;
# 997 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstLOD;
# 998 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUmemorytype dstMemoryType;
# 999 "/usr/local/cuda4.1/cuda/include/cuda.h"
void *dstHost;
# 1000 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUdeviceptr dstDevice;
# 1001 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUarray dstArray;
# 1002 "/usr/local/cuda4.1/cuda/include/cuda.h"
void *reserved1;
# 1003 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstPitch;
# 1004 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstHeight;
# 1006 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t WidthInBytes;
# 1007 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Height;
# 1008 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Depth;
# 1009 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUDA_MEMCPY3D; }
# 1042 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 1014 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUDA_MEMCPY3D_PEER_st {
# 1015 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcXInBytes;
# 1016 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcY;
# 1017 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcZ;
# 1018 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcLOD;
# 1019 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUmemorytype srcMemoryType;
# 1020 "/usr/local/cuda4.1/cuda/include/cuda.h"
const void *srcHost;
# 1021 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUdeviceptr srcDevice;
# 1022 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUarray srcArray;
# 1023 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUcontext srcContext;
# 1024 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcPitch;
# 1025 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t srcHeight;
# 1027 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstXInBytes;
# 1028 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstY;
# 1029 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstZ;
# 1030 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstLOD;
# 1031 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUmemorytype dstMemoryType;
# 1032 "/usr/local/cuda4.1/cuda/include/cuda.h"
void *dstHost;
# 1033 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUdeviceptr dstDevice;
# 1034 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUarray dstArray;
# 1035 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUcontext dstContext;
# 1036 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstPitch;
# 1037 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t dstHeight;
# 1039 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t WidthInBytes;
# 1040 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Height;
# 1041 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Depth;
# 1042 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUDA_MEMCPY3D_PEER; }
# 1054 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 1047 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR_st {
# 1049 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Width;
# 1050 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Height;
# 1052 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUarray_format Format;
# 1053 "/usr/local/cuda4.1/cuda/include/cuda.h"
unsigned NumChannels;
# 1054 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 1068 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" { typedef
# 1059 "/usr/local/cuda4.1/cuda/include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR_st {
# 1061 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Width;
# 1062 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Height;
# 1063 "/usr/local/cuda4.1/cuda/include/cuda.h"
size_t Depth;
# 1065 "/usr/local/cuda4.1/cuda/include/cuda.h"
CUarray_format Format;
# 1066 "/usr/local/cuda4.1/cuda/include/cuda.h"
unsigned NumChannels;
# 1067 "/usr/local/cuda4.1/cuda/include/cuda.h"
unsigned Flags;
# 1068 "/usr/local/cuda4.1/cuda/include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 1195 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuInit(unsigned );
# 1222 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int * );
# 1260 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice * , int );
# 1286 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int * );
# 1315 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceGetName(char * , int , CUdevice );
# 1344 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int * , int * , CUdevice );
# 1372 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceTotalMem_v2(size_t * , CUdevice );
# 1432 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop * , CUdevice );
# 1597 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int * , CUdevice_attribute , CUdevice );
# 1697 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxCreate_v2(CUcontext * , unsigned , CUdevice );
# 1736 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxDestroy_v2(CUcontext );
# 1786 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext * , unsigned );
# 1821 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext );
# 1857 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxPushCurrent_v2(CUcontext );
# 1890 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxPopCurrent_v2(CUcontext * );
# 1916 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxSetCurrent(CUcontext );
# 1935 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxGetCurrent(CUcontext * );
# 1964 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice * );
# 1992 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 2053 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxSetLimit(CUlimit , size_t );
# 2086 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxGetLimit(size_t * , CUlimit );
# 2128 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxGetCacheConfig(CUfunc_cache * );
# 2177 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxSetCacheConfig(CUfunc_cache );
# 2212 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxGetApiVersion(CUcontext , unsigned * );
# 2261 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule * , const char * );
# 2295 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule * , const void * );
# 2374 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule * , const void * , unsigned , CUjit_option * , void ** );
# 2414 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule * , const void * );
# 2439 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule );
# 2469 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction * , CUmodule , const char * );
# 2503 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleGetGlobal_v2(CUdeviceptr * , size_t * , CUmodule , const char * );
# 2537 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref * , CUmodule , const char * );
# 2568 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuModuleGetSurfRef(CUsurfref * , CUmodule , const char * );
# 2611 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemGetInfo_v2(size_t * , size_t * );
# 2644 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemAlloc_v2(CUdeviceptr * , size_t );
# 2705 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemAllocPitch_v2(CUdeviceptr * , size_t * , size_t , size_t , unsigned );
# 2734 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemFree_v2(CUdeviceptr );
# 2767 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemGetAddressRange_v2(CUdeviceptr * , size_t * , CUdeviceptr );
# 2813 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemAllocHost_v2(void ** , size_t );
# 2843 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemFreeHost(void * );
# 2925 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void ** , size_t , unsigned );
# 2963 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr * , void * , unsigned );
# 2988 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned * , void * );
# 3015 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceGetByPCIBusId(CUdevice * , char * );
# 3043 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceGetPCIBusId(char * , int , CUdevice );
# 3082 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuIpcGetEventHandle(CUipcEventHandle * , CUevent );
# 3115 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuIpcOpenEventHandle(CUevent * , CUipcEventHandle );
# 3149 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuIpcGetMemHandle(CUipcMemHandle * , CUdeviceptr );
# 3188 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuIpcOpenMemHandle(CUdeviceptr * , CUipcMemHandle );
# 3216 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuIpcCloseMemHandle(CUdeviceptr );
# 3278 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemHostRegister(void * , size_t , unsigned );
# 3301 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemHostUnregister(void * );
# 3337 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpy(CUdeviceptr , CUdeviceptr , size_t );
# 3370 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyPeer(CUdeviceptr , CUcontext , CUdeviceptr , CUcontext , size_t );
# 3406 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyHtoD_v2(CUdeviceptr , const void * , size_t );
# 3439 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyDtoH_v2(void * , CUdeviceptr , size_t );
# 3472 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyDtoD_v2(CUdeviceptr , CUdeviceptr , size_t );
# 3506 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyDtoA_v2(CUarray , size_t , CUdeviceptr , size_t );
# 3542 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyAtoD_v2(CUdeviceptr , CUarray , size_t , size_t );
# 3576 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyHtoA_v2(CUarray , size_t , const void * , size_t );
# 3610 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyAtoH_v2(void * , CUarray , size_t , size_t );
# 3648 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyAtoA_v2(CUarray , size_t , CUarray , size_t , size_t );
# 3808 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D * );
# 3966 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D * );
# 4133 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D * );
# 4164 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER * );
# 4204 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyAsync(CUdeviceptr , CUdeviceptr , size_t , CUstream );
# 4235 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyPeerAsync(CUdeviceptr , CUcontext , CUdeviceptr , CUcontext , size_t , CUstream );
# 4277 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr , const void * , size_t , CUstream );
# 4317 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync_v2(void * , CUdeviceptr , size_t , CUstream );
# 4354 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr , CUdeviceptr , size_t , CUstream );
# 4396 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync_v2(CUarray , size_t , const void * , size_t , CUstream );
# 4438 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync_v2(void * , CUarray , size_t , size_t , CUstream );
# 4609 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D * , CUstream );
# 4784 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D * , CUstream );
# 4809 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER * , CUstream );
# 4844 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD8_v2(CUdeviceptr , unsigned char , size_t );
# 4877 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD16_v2(CUdeviceptr , unsigned short , size_t );
# 4910 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD32_v2(CUdeviceptr , unsigned , size_t );
# 4948 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD2D8_v2(CUdeviceptr , size_t , unsigned char , size_t , size_t );
# 4987 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD2D16_v2(CUdeviceptr , size_t , unsigned short , size_t , size_t );
# 5026 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD2D32_v2(CUdeviceptr , size_t , unsigned , size_t , size_t );
# 5063 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD8Async(CUdeviceptr , unsigned char , size_t , CUstream );
# 5100 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD16Async(CUdeviceptr , unsigned short , size_t , CUstream );
# 5136 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD32Async(CUdeviceptr , unsigned , size_t , CUstream );
# 5178 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD2D8Async(CUdeviceptr , size_t , unsigned char , size_t , size_t , CUstream );
# 5221 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD2D16Async(CUdeviceptr , size_t , unsigned short , size_t , size_t , CUstream );
# 5264 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuMemsetD2D32Async(CUdeviceptr , size_t , unsigned , size_t , size_t , CUstream );
# 5367 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuArrayCreate_v2(CUarray * , const CUDA_ARRAY_DESCRIPTOR * );
# 5400 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR * , CUarray );
# 5431 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray );
# 5611 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuArray3DCreate_v2(CUarray * , const CUDA_ARRAY3D_DESCRIPTOR * );
# 5647 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR * , CUarray );
# 5854 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuPointerGetAttribute(void * , CUpointer_attribute , CUdeviceptr );
# 5891 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream * , unsigned );
# 5933 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuStreamWaitEvent(CUstream , CUevent , unsigned );
# 5957 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream );
# 5982 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream );
# 6010 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuStreamDestroy_v2(CUstream );
# 6059 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent * , unsigned );
# 6097 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent , CUstream );
# 6128 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent );
# 6162 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent );
# 6191 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuEventDestroy_v2(CUevent );
# 6235 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float * , CUevent , CUevent );
# 6298 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int * , CUfunction_attribute , CUfunction );
# 6340 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuFuncSetCacheConfig(CUfunction , CUfunc_cache );
# 6456 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuLaunchKernel(CUfunction , unsigned , unsigned , unsigned , unsigned , unsigned , unsigned , unsigned , CUstream , void ** , void ** );
# 6512 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction , int , int , int );
# 6546 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction , unsigned );
# 6578 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction , unsigned );
# 6611 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction , int , unsigned );
# 6644 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction , int , float );
# 6679 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction , int , void * , unsigned );
# 6716 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction );
# 6755 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction , int , int );
# 6799 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction , int , int , CUstream );
# 6824 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction , int , CUtexref );
# 6865 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref , CUarray , unsigned );
# 6909 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefSetAddress_v2(size_t * , CUtexref , CUdeviceptr , size_t );
# 6961 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D_v3(CUtexref , const CUDA_ARRAY_DESCRIPTOR * , CUdeviceptr , size_t );
# 6990 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref , CUarray_format , int );
# 7030 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref , int , CUaddress_mode );
# 7063 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref , CUfilter_mode );
# 7098 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref , unsigned );
# 7124 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefGetAddress_v2(CUdeviceptr * , CUtexref );
# 7150 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray * , CUtexref );
# 7176 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode * , CUtexref , int );
# 7200 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode * , CUtexref );
# 7226 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format * , int * , CUtexref );
# 7249 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned * , CUtexref );
# 7283 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref * );
# 7303 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref );
# 7341 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuSurfRefSetArray(CUsurfref , CUarray , unsigned );
# 7362 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuSurfRefGetArray(CUarray * , CUsurfref );
# 7400 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuDeviceCanAccessPeer(int * , CUdevice , CUdevice );
# 7447 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxEnablePeerAccess(CUcontext , unsigned );
# 7472 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuCtxDisablePeerAccess(CUcontext );
# 7513 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource );
# 7551 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray * , CUgraphicsResource , unsigned , unsigned );
# 7585 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr * , size_t * , CUgraphicsResource );
# 7626 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource , unsigned );
# 7664 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned , CUgraphicsResource * , CUstream );
# 7699 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned , CUgraphicsResource * , CUstream );
# 7703 "/usr/local/cuda4.1/cuda/include/cuda.h"
extern "C" CUresult cuGetExportTable(const void ** , const CUuuid * );
# 60 "./sdk/cutil.h"
enum CUTBoolean {
# 62 "./sdk/cutil.h"
CUTFalse,
# 63 "./sdk/cutil.h"
CUTTrue
# 64 "./sdk/cutil.h"
};
# 72 "./sdk/cutil.h"
extern "C" void cutFree(void * );
# 90 "./sdk/cutil.h"
extern "C" void cutCheckBankAccess(unsigned , unsigned , unsigned , unsigned , unsigned , unsigned , const char * , const int , const char * , const int );
# 103 "./sdk/cutil.h"
extern "C" char *cutFindFilePath(const char * , const char * );
# 118 "./sdk/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char * , float ** , unsigned * , bool = false);
# 134 "./sdk/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char * , double ** , unsigned * , bool = false);
# 150 "./sdk/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char * , int ** , unsigned * , bool = false);
# 165 "./sdk/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char * , unsigned ** , unsigned * , bool = false);
# 181 "./sdk/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char * , char ** , unsigned * , bool = false);
# 197 "./sdk/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char * , unsigned char ** , unsigned * , bool = false);
# 211 "./sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char * , const float * , unsigned , const float , bool = false);
# 225 "./sdk/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char * , const float * , unsigned , const double , bool = false);
# 237 "./sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char * , const int * , unsigned , bool = false);
# 249 "./sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char * , const unsigned * , unsigned , bool = false);
# 261 "./sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char * , const char * , unsigned , bool = false);
# 273 "./sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char * , const unsigned char * , unsigned , bool = false);
# 289 "./sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char * , unsigned char ** , unsigned * , unsigned * );
# 302 "./sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char * , unsigned char ** , unsigned * , unsigned * );
# 316 "./sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char * , unsigned char ** , unsigned * , unsigned * );
# 332 "./sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char * , unsigned ** , unsigned * , unsigned * );
# 348 "./sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char * , unsigned short ** , unsigned * , unsigned * );
# 363 "./sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char * , float ** , unsigned * , unsigned * );
# 375 "./sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char * , unsigned char * , unsigned , unsigned );
# 387 "./sdk/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char * , unsigned char * , unsigned , unsigned );
# 400 "./sdk/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char * , unsigned char * , unsigned , unsigned );
# 412 "./sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char * , unsigned * , unsigned , unsigned );
# 424 "./sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char * , unsigned short * , unsigned , unsigned );
# 436 "./sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char * , float * , unsigned , unsigned );
# 457 "./sdk/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int , const char ** , const char * );
# 471 "./sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int , const char ** , const char * , int * );
# 485 "./sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int , const char ** , const char * , float * );
# 499 "./sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int , const char ** , const char * , char ** );
# 514 "./sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int , const char ** , const char * , char ** , unsigned * );
# 528 "./sdk/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int , const char * , const int );
# 540 "./sdk/cutil.h"
extern "C" CUTBoolean cutComparef(const float * , const float * , const unsigned );
# 553 "./sdk/cutil.h"
extern "C" CUTBoolean cutComparei(const int * , const int * , const unsigned );
# 567 "./sdk/cutil.h"
extern "C" CUTBoolean cutCompareuit(const unsigned * , const unsigned * , const unsigned , const float , const float );
# 580 "./sdk/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char * , const unsigned char * , const unsigned );
# 595 "./sdk/cutil.h"
extern "C" CUTBoolean cutCompareubt(const unsigned char * , const unsigned char * , const unsigned , const float , const float );
# 609 "./sdk/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char * , const unsigned char * , const unsigned , const float );
# 623 "./sdk/cutil.h"
extern "C" CUTBoolean cutComparefe(const float * , const float * , const unsigned , const float );
# 638 "./sdk/cutil.h"
extern "C" CUTBoolean cutComparefet(const float * , const float * , const unsigned , const float , const float );
# 653 "./sdk/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float * , const float * , const unsigned , const float );
# 668 "./sdk/cutil.h"
extern "C" CUTBoolean cutComparePPM(const char * , const char * , const float , const float , bool = false);
# 681 "./sdk/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned * );
# 690 "./sdk/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned );
# 698 "./sdk/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned );
# 706 "./sdk/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned );
# 714 "./sdk/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned );
# 723 "./sdk/cutil.h"
extern "C" float cutGetTimerValue(const unsigned );
# 734 "./sdk/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned );
# 30 "./sdk/cutil_inline_bankchecker.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
# 31 "./sdk/cutil_inline_bankchecker.h"
bdimx, unsigned bdimy, unsigned bdimz, char *
# 32 "./sdk/cutil_inline_bankchecker.h"
aname, int index, char *file, int line)
# 33 "./sdk/cutil_inline_bankchecker.h"
{
# 34 "./sdk/cutil_inline_bankchecker.h"
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
# 35 "./sdk/cutil_inline_bankchecker.h"
}
# 60 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { typedef float2 cuFloatComplex; }
# 62 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline float cuCrealf(cuFloatComplex x)
# 63 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 64 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return x.x;
# 65 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 67 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline float cuCimagf(cuFloatComplex x)
# 68 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 69 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return x.y;
# 70 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 72 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuFloatComplex make_cuFloatComplex(float
# 73 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
r, float i)
# 74 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 75 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
cuFloatComplex res;
# 76 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
(res.x) = r;
# 77 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
(res.y) = i;
# 78 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return res;
# 79 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 81 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuConjf(cuFloatComplex x)
# 82 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 83 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x), -cuCimagf(x));
# 84 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 85 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCaddf(cuFloatComplex x, cuFloatComplex
# 86 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 87 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 88 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) + cuCrealf(y), cuCimagf(x) + cuCimagf(y));
# 90 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 92 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCsubf(cuFloatComplex x, cuFloatComplex
# 93 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 94 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 95 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) - cuCrealf(y), cuCimagf(x) - cuCimagf(y));
# 97 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 104 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
# 105 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 106 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 107 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
cuFloatComplex prod;
# 108 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
prod = make_cuFloatComplex((cuCrealf(x) * cuCrealf(y)) - (cuCimagf(x) * cuCimagf(y)), (cuCrealf(x) * cuCimagf(y)) + (cuCimagf(x) * cuCrealf(y)));
# 112 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return prod;
# 113 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 120 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCdivf(cuFloatComplex x, cuFloatComplex
# 121 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 122 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 123 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
cuFloatComplex quot;
# 124 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float s = (fabsf(cuCrealf(y)) + fabsf(cuCimagf(y)));
# 125 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float oos = ((1.0F) / s);
# 126 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float ars = (cuCrealf(x) * oos);
# 127 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float ais = (cuCimagf(x) * oos);
# 128 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float brs = (cuCrealf(y) * oos);
# 129 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float bis = (cuCimagf(y) * oos);
# 130 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 131 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
oos = ((1.0F) / s);
# 132 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
quot = make_cuFloatComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 134 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return quot;
# 135 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 145 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline float cuCabsf(cuFloatComplex x)
# 146 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 147 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float a = cuCrealf(x);
# 148 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float b = cuCimagf(x);
# 149 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float v, w, t;
# 150 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
a = fabsf(a);
# 151 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
b = fabsf(b);
# 152 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
if (a > b) {
# 153 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
v = a;
# 154 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
w = b;
# 155 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} else {
# 156 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
v = b;
# 157 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
w = a;
# 158 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 159 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
t = (w / v);
# 160 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
t = ((1.0F) + (t * t));
# 161 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
t = (v * sqrtf(t));
# 162 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
if (((v == (0.0F)) || (v > (3.402823466e+38F))) || (w > (3.402823466e+38F))) {
# 163 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
t = (v + w);
# 164 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 165 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return t;
# 166 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 169 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { typedef double2 cuDoubleComplex; }
# 171 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline double cuCreal(cuDoubleComplex x)
# 172 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 173 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return x.x;
# 174 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 176 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline double cuCimag(cuDoubleComplex x)
# 177 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 178 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return x.y;
# 179 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 181 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuDoubleComplex make_cuDoubleComplex(double
# 182 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
r, double i)
# 183 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 184 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
cuDoubleComplex res;
# 185 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
(res.x) = r;
# 186 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
(res.y) = i;
# 187 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return res;
# 188 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 190 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuConj(cuDoubleComplex x)
# 191 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 192 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x), -cuCimag(x));
# 193 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 195 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCadd(cuDoubleComplex x, cuDoubleComplex
# 196 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 197 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 198 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) + cuCreal(y), cuCimag(x) + cuCimag(y));
# 200 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 202 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCsub(cuDoubleComplex x, cuDoubleComplex
# 203 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 204 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 205 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) - cuCreal(y), cuCimag(x) - cuCimag(y));
# 207 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 214 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
# 215 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 216 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 217 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
cuDoubleComplex prod;
# 218 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
prod = make_cuDoubleComplex((cuCreal(x) * cuCreal(y)) - (cuCimag(x) * cuCimag(y)), (cuCreal(x) * cuCimag(y)) + (cuCimag(x) * cuCreal(y)));
# 222 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return prod;
# 223 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 230 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCdiv(cuDoubleComplex x, cuDoubleComplex
# 231 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 232 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 233 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
cuDoubleComplex quot;
# 234 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double s = (fabs(cuCreal(y)) + fabs(cuCimag(y)));
# 235 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double oos = ((1.0) / s);
# 236 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double ars = (cuCreal(x) * oos);
# 237 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double ais = (cuCimag(x) * oos);
# 238 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double brs = (cuCreal(y) * oos);
# 239 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double bis = (cuCimag(y) * oos);
# 240 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 241 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
oos = ((1.0) / s);
# 242 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
quot = make_cuDoubleComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 244 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return quot;
# 245 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 253 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
extern "C" { static inline double cuCabs(cuDoubleComplex x)
# 254 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 255 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double a = cuCreal(x);
# 256 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double b = cuCimag(x);
# 257 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double v, w, t;
# 258 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
a = fabs(a);
# 259 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
b = fabs(b);
# 260 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
if (a > b) {
# 261 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
v = a;
# 262 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
w = b;
# 263 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} else {
# 264 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
v = b;
# 265 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
w = a;
# 266 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 267 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
t = (w / v);
# 268 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
t = ((1.0) + (t * t));
# 269 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
t = (v * sqrt(t));
# 270 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
if (((v == (0.0)) || (v > (1.797693134862315708e+308))) || (w > (1.797693134862315708e+308)))
# 271 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 272 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
t = (v + w);
# 273 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 274 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return t;
# 275 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
} }
# 282 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
typedef cuFloatComplex cuComplex;
# 283 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
static inline cuComplex make_cuComplex(float x, float
# 284 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
y)
# 285 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 286 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuFloatComplex(x, y);
# 287 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 290 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
static inline cuDoubleComplex cuComplexFloatToDouble(cuFloatComplex
# 291 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
c)
# 292 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 293 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuDoubleComplex((double)cuCrealf(c), (double)cuCimagf(c));
# 294 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 296 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
static inline cuFloatComplex cuComplexDoubleToFloat(cuDoubleComplex
# 297 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
c)
# 298 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 299 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuFloatComplex((float)cuCreal(c), (float)cuCimag(c));
# 300 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 303 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
static inline cuComplex cuCfmaf(cuComplex x, cuComplex y, cuComplex d)
# 304 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 305 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float real_res;
# 306 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
float imag_res;
# 308 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
real_res = ((cuCrealf(x) * cuCrealf(y)) + cuCrealf(d));
# 309 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
imag_res = ((cuCrealf(x) * cuCimagf(y)) + cuCimagf(d));
# 311 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
real_res = ((-(cuCimagf(x) * cuCimagf(y))) + real_res);
# 312 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
imag_res = ((cuCimagf(x) * cuCrealf(y)) + imag_res);
# 314 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuComplex(real_res, imag_res);
# 315 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 317 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
static inline cuDoubleComplex cuCfma(cuDoubleComplex x, cuDoubleComplex y, cuDoubleComplex d)
# 318 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
{
# 319 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double real_res;
# 320 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
double imag_res;
# 322 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
real_res = ((cuCreal(x) * cuCreal(y)) + cuCreal(d));
# 323 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
imag_res = ((cuCreal(x) * cuCimag(y)) + cuCimag(d));
# 325 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
real_res = ((-(cuCimag(x) * cuCimag(y))) + real_res);
# 326 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
imag_res = ((cuCimag(x) * cuCreal(y)) + imag_res);
# 328 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
return make_cuDoubleComplex(real_res, imag_res);
# 329 "/usr/local/cuda4.1/cuda/include/cuComplex.h"
}
# 86 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" { typedef
# 75 "/usr/local/cuda4.1/cuda/include/cufft.h"
enum cufftResult_t {
# 76 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_SUCCESS,
# 77 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_INVALID_PLAN,
# 78 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_ALLOC_FAILED,
# 79 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_INVALID_TYPE,
# 80 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_INVALID_VALUE,
# 81 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_INTERNAL_ERROR,
# 82 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_EXEC_FAILED,
# 83 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_SETUP_FAILED,
# 84 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_INVALID_SIZE,
# 85 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_UNALIGNED_DATA
# 86 "/usr/local/cuda4.1/cuda/include/cufft.h"
} cufftResult; }
# 91 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" { typedef unsigned cufftHandle; }
# 95 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" { typedef float cufftReal; }
# 96 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" { typedef double cufftDoubleReal; }
# 101 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" { typedef cuComplex cufftComplex; }
# 102 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" { typedef cuDoubleComplex cufftDoubleComplex; }
# 116 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" { typedef
# 109 "/usr/local/cuda4.1/cuda/include/cufft.h"
enum cufftType_t {
# 110 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_R2C = 42,
# 111 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_C2R = 44,
# 112 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_C2C = 41,
# 113 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_D2Z = 106,
# 114 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_Z2D = 108,
# 115 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_Z2Z = 105
# 116 "/usr/local/cuda4.1/cuda/include/cufft.h"
} cufftType; }
# 145 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" { typedef
# 140 "/usr/local/cuda4.1/cuda/include/cufft.h"
enum cufftCompatibility_t {
# 141 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_COMPATIBILITY_NATIVE,
# 142 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_PADDING,
# 143 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_ASYMMETRIC,
# 144 "/usr/local/cuda4.1/cuda/include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_ALL
# 145 "/usr/local/cuda4.1/cuda/include/cufft.h"
} cufftCompatibility; }
# 149 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftPlan1d(cufftHandle * , int , cufftType , int );
# 154 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftPlan2d(cufftHandle * , int , int , cufftType );
# 158 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftPlan3d(cufftHandle * , int , int , int , cufftType );
# 162 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftPlanMany(cufftHandle * , int , int * , int * , int , int , int * , int , int , cufftType , int );
# 170 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftDestroy(cufftHandle );
# 172 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftExecC2C(cufftHandle , cufftComplex * , cufftComplex * , int );
# 177 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftExecR2C(cufftHandle , cufftReal * , cufftComplex * );
# 181 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftExecC2R(cufftHandle , cufftComplex * , cufftReal * );
# 185 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftExecZ2Z(cufftHandle , cufftDoubleComplex * , cufftDoubleComplex * , int );
# 190 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftExecD2Z(cufftHandle , cufftDoubleReal * , cufftDoubleComplex * );
# 194 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftExecZ2D(cufftHandle , cufftDoubleComplex * , cufftDoubleReal * );
# 198 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftSetStream(cufftHandle , cudaStream_t );
# 201 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftSetCompatibilityMode(cufftHandle , cufftCompatibility );
# 204 "/usr/local/cuda4.1/cuda/include/cufft.h"
extern "C" cufftResult cufftGetVersion(int * );
# 43 "./sdk/cutil_inline_runtime.h"
inline void __cutilCondition(int val, char *file, int line)
# 44 "./sdk/cutil_inline_runtime.h"
{
# 45 "./sdk/cutil_inline_runtime.h"
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
# 46 "./sdk/cutil_inline_runtime.h"
exit(1);
# 47 "./sdk/cutil_inline_runtime.h"
}
# 48 "./sdk/cutil_inline_runtime.h"
}
# 50 "./sdk/cutil_inline_runtime.h"
inline void __cutilExit(int argc, char **argv)
# 51 "./sdk/cutil_inline_runtime.h"
{
# 52 "./sdk/cutil_inline_runtime.h"
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
# 53 "./sdk/cutil_inline_runtime.h"
printf("\nPress ENTER to exit...\n");
# 54 "./sdk/cutil_inline_runtime.h"
fflush(stdout);
# 55 "./sdk/cutil_inline_runtime.h"
fflush(stderr);
# 56 "./sdk/cutil_inline_runtime.h"
getchar();
# 57 "./sdk/cutil_inline_runtime.h"
}
# 58 "./sdk/cutil_inline_runtime.h"
exit(0);
# 59 "./sdk/cutil_inline_runtime.h"
}
# 65 "./sdk/cutil_inline_runtime.h"
inline int _ConvertSMVer2Cores(int major, int minor)
# 66 "./sdk/cutil_inline_runtime.h"
{
# 71 "./sdk/cutil_inline_runtime.h"
typedef
# 68 "./sdk/cutil_inline_runtime.h"
struct {
# 69 "./sdk/cutil_inline_runtime.h"
int SM;
# 70 "./sdk/cutil_inline_runtime.h"
int Cores;
# 71 "./sdk/cutil_inline_runtime.h"
} sSMtoCores;
# 73 "./sdk/cutil_inline_runtime.h"
sSMtoCores nGpuArchCoresPerSM[] = {{16, 8}, {17, 8}, {18, 8}, {19, 8}, {32, 32}, {33, 48}, {(-1), (-1)}};
# 83 "./sdk/cutil_inline_runtime.h"
int index = 0;
# 84 "./sdk/cutil_inline_runtime.h"
while ((((nGpuArchCoresPerSM)[index]).SM) != (-1)) {
# 85 "./sdk/cutil_inline_runtime.h"
if ((((nGpuArchCoresPerSM)[index]).SM) == ((major << 4) + minor)) {
# 86 "./sdk/cutil_inline_runtime.h"
return ((nGpuArchCoresPerSM)[index]).Cores;
# 87 "./sdk/cutil_inline_runtime.h"
}
# 88 "./sdk/cutil_inline_runtime.h"
index++;
# 89 "./sdk/cutil_inline_runtime.h"
}
# 90 "./sdk/cutil_inline_runtime.h"
printf("MapSMtoCores undefined SMversion %d.%d!\n", major, minor);
# 91 "./sdk/cutil_inline_runtime.h"
return -1;
# 92 "./sdk/cutil_inline_runtime.h"
}
# 96 "./sdk/cutil_inline_runtime.h"
inline int cutGetMaxGflopsDeviceId()
# 97 "./sdk/cutil_inline_runtime.h"
{
# 98 "./sdk/cutil_inline_runtime.h"
int current_device = 0, sm_per_multiproc = 0;
# 99 "./sdk/cutil_inline_runtime.h"
int max_compute_perf = 0, max_perf_device = 0;
# 100 "./sdk/cutil_inline_runtime.h"
int device_count = 0, best_SM_arch = 0;
# 101 "./sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 103 "./sdk/cutil_inline_runtime.h"
cudaGetDeviceCount(&device_count);
# 105 "./sdk/cutil_inline_runtime.h"
while (current_device < device_count) {
# 106 "./sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&deviceProp, current_device);
# 107 "./sdk/cutil_inline_runtime.h"
if (((deviceProp.major) > 0) && ((deviceProp.major) < 9999)) {
# 108 "./sdk/cutil_inline_runtime.h"
best_SM_arch = ((best_SM_arch > (deviceProp.major)) ? best_SM_arch : (deviceProp.major));
# 109 "./sdk/cutil_inline_runtime.h"
}
# 110 "./sdk/cutil_inline_runtime.h"
current_device++;
# 111 "./sdk/cutil_inline_runtime.h"
}
# 114 "./sdk/cutil_inline_runtime.h"
current_device = 0;
# 115 "./sdk/cutil_inline_runtime.h"
while (current_device < device_count) {
# 116 "./sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&deviceProp, current_device);
# 117 "./sdk/cutil_inline_runtime.h"
if (((deviceProp.major) == 9999) && ((deviceProp.minor) == 9999)) {
# 118 "./sdk/cutil_inline_runtime.h"
sm_per_multiproc = 1;
# 119 "./sdk/cutil_inline_runtime.h"
} else {
# 120 "./sdk/cutil_inline_runtime.h"
sm_per_multiproc = _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor);
# 121 "./sdk/cutil_inline_runtime.h"
}
# 123 "./sdk/cutil_inline_runtime.h"
int compute_perf = (((deviceProp.multiProcessorCount) * sm_per_multiproc) * (deviceProp.clockRate));
# 124 "./sdk/cutil_inline_runtime.h"
if (compute_perf > max_compute_perf) {
# 126 "./sdk/cutil_inline_runtime.h"
if (best_SM_arch > 2) {
# 128 "./sdk/cutil_inline_runtime.h"
if ((deviceProp.major) == best_SM_arch) {
# 129 "./sdk/cutil_inline_runtime.h"
max_compute_perf = compute_perf;
# 130 "./sdk/cutil_inline_runtime.h"
max_perf_device = current_device;
# 131 "./sdk/cutil_inline_runtime.h"
}
# 132 "./sdk/cutil_inline_runtime.h"
} else {
# 133 "./sdk/cutil_inline_runtime.h"
max_compute_perf = compute_perf;
# 134 "./sdk/cutil_inline_runtime.h"
max_perf_device = current_device;
# 135 "./sdk/cutil_inline_runtime.h"
}
# 136 "./sdk/cutil_inline_runtime.h"
}
# 137 "./sdk/cutil_inline_runtime.h"
++current_device;
# 138 "./sdk/cutil_inline_runtime.h"
}
# 139 "./sdk/cutil_inline_runtime.h"
return max_perf_device;
# 140 "./sdk/cutil_inline_runtime.h"
}
# 178 "./sdk/cutil_inline_runtime.h"
inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
# 179 "./sdk/cutil_inline_runtime.h"
{
# 180 "./sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 181 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cudaSafeCallNoSync() Runtime API error : %s.\n", file, line, cudaGetErrorString(err));
# 183 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 184 "./sdk/cutil_inline_runtime.h"
}
# 185 "./sdk/cutil_inline_runtime.h"
}
# 187 "./sdk/cutil_inline_runtime.h"
inline void __cudaSafeCall(cudaError err, const char *file, const int line)
# 188 "./sdk/cutil_inline_runtime.h"
{
# 189 "./sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 190 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cudaSafeCall() Runtime API error : %s.\n", file, line, cudaGetErrorString(err));
# 192 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 193 "./sdk/cutil_inline_runtime.h"
}
# 194 "./sdk/cutil_inline_runtime.h"
}
# 196 "./sdk/cutil_inline_runtime.h"
inline void __cudaSafeThreadSync(const char *file, const int line)
# 197 "./sdk/cutil_inline_runtime.h"
{
# 198 "./sdk/cutil_inline_runtime.h"
cudaError err = cudaThreadSynchronize();
# 199 "./sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 200 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cudaThreadSynchronize() Driver API error : %s.\n", file, line, cudaGetErrorString(err));
# 202 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 203 "./sdk/cutil_inline_runtime.h"
}
# 204 "./sdk/cutil_inline_runtime.h"
}
# 206 "./sdk/cutil_inline_runtime.h"
inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
# 207 "./sdk/cutil_inline_runtime.h"
{
# 208 "./sdk/cutil_inline_runtime.h"
if ((CUFFT_SUCCESS) != err) {
# 209 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cufftSafeCall() CUFFT error.\n", file, line);
# 211 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 212 "./sdk/cutil_inline_runtime.h"
}
# 213 "./sdk/cutil_inline_runtime.h"
}
# 215 "./sdk/cutil_inline_runtime.h"
inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
# 216 "./sdk/cutil_inline_runtime.h"
{
# 217 "./sdk/cutil_inline_runtime.h"
if ((CUTTrue) != err) {
# 218 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : CUTIL CUDA error.\n", file, line);
# 220 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 221 "./sdk/cutil_inline_runtime.h"
}
# 222 "./sdk/cutil_inline_runtime.h"
}
# 224 "./sdk/cutil_inline_runtime.h"
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
# 225 "./sdk/cutil_inline_runtime.h"
{
# 226 "./sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 227 "./sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 228 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cutilCheckMsg() CUTIL CUDA error : %s : %s.\n", file, line, errorMessage, cudaGetErrorString(err));
# 230 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 231 "./sdk/cutil_inline_runtime.h"
}
# 240 "./sdk/cutil_inline_runtime.h"
}
# 241 "./sdk/cutil_inline_runtime.h"
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
# 242 "./sdk/cutil_inline_runtime.h"
{
# 243 "./sdk/cutil_inline_runtime.h"
if (!(pointer)) {
# 244 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : cutilSafeMalloc host malloc failure\n", file, line);
# 246 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 247 "./sdk/cutil_inline_runtime.h"
}
# 248 "./sdk/cutil_inline_runtime.h"
}
# 254 "./sdk/cutil_inline_runtime.h"
inline int cutilDeviceInit(int ARGC, char **ARGV)
# 255 "./sdk/cutil_inline_runtime.h"
{
# 256 "./sdk/cutil_inline_runtime.h"
int deviceCount;
# 257 "./sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "./sdk/cutil_inline_runtime.h", 257);
# 258 "./sdk/cutil_inline_runtime.h"
if (deviceCount == 0) {
# 259 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
# 260 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 261 "./sdk/cutil_inline_runtime.h"
}
# 262 "./sdk/cutil_inline_runtime.h"
int dev = 0;
# 263 "./sdk/cutil_inline_runtime.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 264 "./sdk/cutil_inline_runtime.h"
if (dev < 0) {
# 265 "./sdk/cutil_inline_runtime.h"
dev = 0; }
# 266 "./sdk/cutil_inline_runtime.h"
if (dev > (deviceCount - 1)) {
# 267 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilDeviceInit (Device=%d) invalid GPU device.  %d GPU device(s) detected.\n\n", dev, deviceCount);
# 268 "./sdk/cutil_inline_runtime.h"
return -dev;
# 269 "./sdk/cutil_inline_runtime.h"
}
# 270 "./sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 271 "./sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "./sdk/cutil_inline_runtime.h", 271);
# 272 "./sdk/cutil_inline_runtime.h"
if ((deviceProp.major) < 1) {
# 273 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutil error: GPU device does not support CUDA.\n");
# 274 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 275 "./sdk/cutil_inline_runtime.h"
}
# 276 "./sdk/cutil_inline_runtime.h"
printf("> Using CUDA device [%d]: %s\n", dev, deviceProp.name);
# 277 "./sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaSetDevice(dev), "./sdk/cutil_inline_runtime.h", 277);
# 279 "./sdk/cutil_inline_runtime.h"
return dev;
# 280 "./sdk/cutil_inline_runtime.h"
}
# 283 "./sdk/cutil_inline_runtime.h"
inline int cutilChooseCudaDevice(int argc, char **argv)
# 284 "./sdk/cutil_inline_runtime.h"
{
# 285 "./sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 286 "./sdk/cutil_inline_runtime.h"
int devID = 0;
# 288 "./sdk/cutil_inline_runtime.h"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 289 "./sdk/cutil_inline_runtime.h"
devID = cutilDeviceInit(argc, argv);
# 290 "./sdk/cutil_inline_runtime.h"
if (devID < 0) {
# 291 "./sdk/cutil_inline_runtime.h"
printf("exiting...\n");
# 292 "./sdk/cutil_inline_runtime.h"
__cutilExit(argc, argv);
# 293 "./sdk/cutil_inline_runtime.h"
exit(0);
# 294 "./sdk/cutil_inline_runtime.h"
}
# 295 "./sdk/cutil_inline_runtime.h"
} else {
# 297 "./sdk/cutil_inline_runtime.h"
devID = cutGetMaxGflopsDeviceId();
# 298 "./sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaSetDevice(devID), "./sdk/cutil_inline_runtime.h", 298);
# 299 "./sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, devID), "./sdk/cutil_inline_runtime.h", 299);
# 300 "./sdk/cutil_inline_runtime.h"
printf("> Using CUDA device [%d]: %s\n", devID, deviceProp.name);
# 301 "./sdk/cutil_inline_runtime.h"
}
# 302 "./sdk/cutil_inline_runtime.h"
return devID;
# 303 "./sdk/cutil_inline_runtime.h"
}
# 308 "./sdk/cutil_inline_runtime.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 309 "./sdk/cutil_inline_runtime.h"
{
# 310 "./sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 311 "./sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 312 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : CUDA error: %s : %s.\n", file, line, errorMessage, cudaGetErrorString(err));
# 314 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 315 "./sdk/cutil_inline_runtime.h"
}
# 316 "./sdk/cutil_inline_runtime.h"
err = cudaThreadSynchronize();
# 317 "./sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 318 "./sdk/cutil_inline_runtime.h"
fprintf(stderr, "%s(%i) : CCUDA error: %s : %s.\n", file, line, errorMessage, cudaGetErrorString(err));
# 320 "./sdk/cutil_inline_runtime.h"
exit(-1);
# 321 "./sdk/cutil_inline_runtime.h"
}
# 322 "./sdk/cutil_inline_runtime.h"
}
# 325 "./sdk/cutil_inline_runtime.h"
inline bool cutilCudaCapabilities(int major_version, int minor_version)
# 326 "./sdk/cutil_inline_runtime.h"
{
# 327 "./sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 328 "./sdk/cutil_inline_runtime.h"
(deviceProp.major) = 0;
# 329 "./sdk/cutil_inline_runtime.h"
(deviceProp.minor) = 0;
# 330 "./sdk/cutil_inline_runtime.h"
int dev;
# 336 "./sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaGetDevice(&dev), "./sdk/cutil_inline_runtime.h", 336);
# 337 "./sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaGetDeviceProperties(&deviceProp, dev), "./sdk/cutil_inline_runtime.h", 337);
# 339 "./sdk/cutil_inline_runtime.h"
if (((deviceProp.major) > major_version) || (((deviceProp.major) == major_version) && ((deviceProp.minor) >= minor_version)))
# 341 "./sdk/cutil_inline_runtime.h"
{
# 342 "./sdk/cutil_inline_runtime.h"
printf("> Device %d: <%16s >, Compute SM %d.%d detected\n", dev, deviceProp.name, deviceProp.major, deviceProp.minor);
# 343 "./sdk/cutil_inline_runtime.h"
return true;
# 344 "./sdk/cutil_inline_runtime.h"
} else
# 346 "./sdk/cutil_inline_runtime.h"
{
# 347 "./sdk/cutil_inline_runtime.h"
printf("There is no device supporting CUDA compute capability %d.%d.\n", major_version, minor_version);
# 348 "./sdk/cutil_inline_runtime.h"
printf("PASSED\n");
# 349 "./sdk/cutil_inline_runtime.h"
return false;
# 350 "./sdk/cutil_inline_runtime.h"
}
# 351 "./sdk/cutil_inline_runtime.h"
}
# 32 "./sdk/cutil_inline_drvapi.h"
inline int _ConvertSMVer2CoresDrvApi(int major, int minor)
# 33 "./sdk/cutil_inline_drvapi.h"
{
# 38 "./sdk/cutil_inline_drvapi.h"
typedef
# 35 "./sdk/cutil_inline_drvapi.h"
struct {
# 36 "./sdk/cutil_inline_drvapi.h"
int SM;
# 37 "./sdk/cutil_inline_drvapi.h"
int Cores;
# 38 "./sdk/cutil_inline_drvapi.h"
} sSMtoCores;
# 40 "./sdk/cutil_inline_drvapi.h"
sSMtoCores nGpuArchCoresPerSM[] = {{16, 8}, {17, 8}, {18, 8}, {19, 8}, {32, 32}, {33, 48}, {(-1), (-1)}};
# 50 "./sdk/cutil_inline_drvapi.h"
int index = 0;
# 51 "./sdk/cutil_inline_drvapi.h"
while ((((nGpuArchCoresPerSM)[index]).SM) != (-1)) {
# 52 "./sdk/cutil_inline_drvapi.h"
if ((((nGpuArchCoresPerSM)[index]).SM) == ((major << 4) + minor)) {
# 53 "./sdk/cutil_inline_drvapi.h"
return ((nGpuArchCoresPerSM)[index]).Cores;
# 54 "./sdk/cutil_inline_drvapi.h"
}
# 55 "./sdk/cutil_inline_drvapi.h"
index++;
# 56 "./sdk/cutil_inline_drvapi.h"
}
# 57 "./sdk/cutil_inline_drvapi.h"
printf("MapSMtoCores undefined SMversion %d.%d!\n", major, minor);
# 58 "./sdk/cutil_inline_drvapi.h"
return -1;
# 59 "./sdk/cutil_inline_drvapi.h"
}
# 63 "./sdk/cutil_inline_drvapi.h"
inline int cutilDrvGetMaxGflopsDeviceId()
# 64 "./sdk/cutil_inline_drvapi.h"
{
# 65 "./sdk/cutil_inline_drvapi.h"
CUdevice current_device = 0, max_perf_device = 0;
# 66 "./sdk/cutil_inline_drvapi.h"
int device_count = 0, sm_per_multiproc = 0;
# 67 "./sdk/cutil_inline_drvapi.h"
int max_compute_perf = 0, best_SM_arch = 0;
# 68 "./sdk/cutil_inline_drvapi.h"
int major = 0, minor = 0, multiProcessorCount, clockRate;
# 70 "./sdk/cutil_inline_drvapi.h"
cuInit(0);
# 71 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetCount(&device_count); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 71); exit(1); } } ;
# 74 "./sdk/cutil_inline_drvapi.h"
while (current_device < device_count) {
# 75 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceComputeCapability(&major, &minor, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 75); exit(1); } } ;
# 76 "./sdk/cutil_inline_drvapi.h"
if ((major > 0) && (major < 9999)) {
# 77 "./sdk/cutil_inline_drvapi.h"
best_SM_arch = ((best_SM_arch > major) ? best_SM_arch : major);
# 78 "./sdk/cutil_inline_drvapi.h"
}
# 79 "./sdk/cutil_inline_drvapi.h"
current_device++;
# 80 "./sdk/cutil_inline_drvapi.h"
}
# 83 "./sdk/cutil_inline_drvapi.h"
current_device = 0;
# 84 "./sdk/cutil_inline_drvapi.h"
while (current_device < device_count) {
# 85 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&multiProcessorCount, CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 87);
# 85 "./sdk/cutil_inline_drvapi.h"
exit(1); } }
# 87 "./sdk/cutil_inline_drvapi.h"
;
# 88 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&clockRate, CU_DEVICE_ATTRIBUTE_CLOCK_RATE, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 90);
# 88 "./sdk/cutil_inline_drvapi.h"
exit(1); } }
# 90 "./sdk/cutil_inline_drvapi.h"
;
# 91 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceComputeCapability(&major, &minor, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 91); exit(1); } } ;
# 93 "./sdk/cutil_inline_drvapi.h"
if ((major == 9999) && (minor == 9999)) {
# 94 "./sdk/cutil_inline_drvapi.h"
sm_per_multiproc = 1;
# 95 "./sdk/cutil_inline_drvapi.h"
} else {
# 96 "./sdk/cutil_inline_drvapi.h"
sm_per_multiproc = _ConvertSMVer2CoresDrvApi(major, minor);
# 97 "./sdk/cutil_inline_drvapi.h"
}
# 99 "./sdk/cutil_inline_drvapi.h"
int compute_perf = ((multiProcessorCount * sm_per_multiproc) * clockRate);
# 100 "./sdk/cutil_inline_drvapi.h"
if (compute_perf > max_compute_perf) {
# 102 "./sdk/cutil_inline_drvapi.h"
if (best_SM_arch > 2) {
# 104 "./sdk/cutil_inline_drvapi.h"
if (major == best_SM_arch) {
# 105 "./sdk/cutil_inline_drvapi.h"
max_compute_perf = compute_perf;
# 106 "./sdk/cutil_inline_drvapi.h"
max_perf_device = current_device;
# 107 "./sdk/cutil_inline_drvapi.h"
}
# 108 "./sdk/cutil_inline_drvapi.h"
} else {
# 109 "./sdk/cutil_inline_drvapi.h"
max_compute_perf = compute_perf;
# 110 "./sdk/cutil_inline_drvapi.h"
max_perf_device = current_device;
# 111 "./sdk/cutil_inline_drvapi.h"
}
# 112 "./sdk/cutil_inline_drvapi.h"
}
# 113 "./sdk/cutil_inline_drvapi.h"
++current_device;
# 114 "./sdk/cutil_inline_drvapi.h"
}
# 115 "./sdk/cutil_inline_drvapi.h"
return max_perf_device;
# 116 "./sdk/cutil_inline_drvapi.h"
}
# 119 "./sdk/cutil_inline_drvapi.h"
inline int cutilDrvGetMaxGflopsGraphicsDeviceId()
# 120 "./sdk/cutil_inline_drvapi.h"
{
# 121 "./sdk/cutil_inline_drvapi.h"
CUdevice current_device = 0, max_perf_device = 0;
# 122 "./sdk/cutil_inline_drvapi.h"
int device_count = 0, sm_per_multiproc = 0;
# 123 "./sdk/cutil_inline_drvapi.h"
int max_compute_perf = 0, best_SM_arch = 0;
# 124 "./sdk/cutil_inline_drvapi.h"
int major = 0, minor = 0, multiProcessorCount, clockRate;
# 125 "./sdk/cutil_inline_drvapi.h"
int bTCC = 0;
# 126 "./sdk/cutil_inline_drvapi.h"
char deviceName[256];
# 128 "./sdk/cutil_inline_drvapi.h"
cuInit(0);
# 129 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetCount(&device_count); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 129); exit(1); } } ;
# 132 "./sdk/cutil_inline_drvapi.h"
while (current_device < device_count) {
# 133 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetName(deviceName, 256, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 133); exit(1); } } ;
# 134 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceComputeCapability(&major, &minor, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 134); exit(1); } } ;
# 136 "./sdk/cutil_inline_drvapi.h"
if ((major > 0) && (major < 9999)) {
# 137 "./sdk/cutil_inline_drvapi.h"
best_SM_arch = ((best_SM_arch > major) ? best_SM_arch : major);
# 138 "./sdk/cutil_inline_drvapi.h"
}
# 139 "./sdk/cutil_inline_drvapi.h"
current_device++;
# 140 "./sdk/cutil_inline_drvapi.h"
}
# 143 "./sdk/cutil_inline_drvapi.h"
current_device = 0;
# 144 "./sdk/cutil_inline_drvapi.h"
while (current_device < device_count) {
# 145 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&multiProcessorCount, CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 147);
# 145 "./sdk/cutil_inline_drvapi.h"
exit(1); } }
# 147 "./sdk/cutil_inline_drvapi.h"
;
# 148 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&clockRate, CU_DEVICE_ATTRIBUTE_CLOCK_RATE, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 150);
# 148 "./sdk/cutil_inline_drvapi.h"
exit(1); } }
# 150 "./sdk/cutil_inline_drvapi.h"
;
# 151 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceComputeCapability(&major, &minor, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 151); exit(1); } } ;
# 154 "./sdk/cutil_inline_drvapi.h"
{ CUresult err = cuDeviceGetAttribute(&bTCC, CU_DEVICE_ATTRIBUTE_TCC_DRIVER, current_device); if ((CUDA_SUCCESS) != err) { fprintf(stderr, "Cuda driver error %x in file \'%s\' in line %i.\n", err, "./sdk/cutil_inline_drvapi.h", 154); exit(1); } } ;
# 160 "./sdk/cutil_inline_drvapi.h"
if ((major == 9999) && (minor == 9999)) {
# 161 "./sdk/cutil_inline_drvapi.h"
sm_per_multiproc = 1;
# 162 "./sdk/cutil_inline_drvapi.h"
} else {
# 163 "./sdk/cutil_inline_drvapi.h"
sm_per_multiproc = _ConvertSMVer2CoresDrvApi(major, minor);
# 164 "./sdk/cutil_inline_drvapi.h"
}
# 167 "./sdk/cutil_inline_drvapi.h"
if ((major >= 2) && (!(bTCC)))
# 168 "./sdk/cutil_inline_drvapi.h"
{
# 169 "./sdk/cutil_inline_drvapi.h"
int compute_perf = ((multiProcessorCount * sm_per_multiproc) * clockRate);
# 170 "./sdk/cutil_inline_drvapi.h"
if (compute_perf > max_compute_perf) {
# 172 "./sdk/cutil_inline_drvapi.h"
if (best_SM_arch > 2) {
# 174 "./sdk/cutil_inline_drvapi.h"
if (major == best_SM_arch) {
# 175 "./sdk/cutil_inline_drvapi.h"
max_compute_perf = compute_perf;
# 176 "./sdk/cutil_inline_drvapi.h"
max_perf_device = current_device;
# 177 "./sdk/cutil_inline_drvapi.h"
}
# 178 "./sdk/cutil_inline_drvapi.h"
} else {
# 179 "./sdk/cutil_inline_drvapi.h"
max_compute_perf = compute_perf;
# 180 "./sdk/cutil_inline_drvapi.h"
max_perf_device = current_device;
# 181 "./sdk/cutil_inline_drvapi.h"
}
# 182 "./sdk/cutil_inline_drvapi.h"
}
# 183 "./sdk/cutil_inline_drvapi.h"
}
# 184 "./sdk/cutil_inline_drvapi.h"
++current_device;
# 185 "./sdk/cutil_inline_drvapi.h"
}
# 186 "./sdk/cutil_inline_drvapi.h"
return max_perf_device;
# 187 "./sdk/cutil_inline_drvapi.h"
}
# 190 "./sdk/cutil_inline_drvapi.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
# 191 "./sdk/cutil_inline_drvapi.h"
{
# 192 "./sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 193 "./sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
# 195 "./sdk/cutil_inline_drvapi.h"
exit(-1);
# 196 "./sdk/cutil_inline_drvapi.h"
}
# 197 "./sdk/cutil_inline_drvapi.h"
}
# 198 "./sdk/cutil_inline_drvapi.h"
inline void __cuSafeCall(CUresult err, const char *file, const int line)
# 199 "./sdk/cutil_inline_drvapi.h"
{
# 200 "./sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(err, file, line);
# 201 "./sdk/cutil_inline_drvapi.h"
}
# 203 "./sdk/cutil_inline_drvapi.h"
inline void __cuCtxSync(const char *file, const int line)
# 204 "./sdk/cutil_inline_drvapi.h"
{
# 205 "./sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 206 "./sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 207 "./sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);
# 209 "./sdk/cutil_inline_drvapi.h"
exit(-1);
# 210 "./sdk/cutil_inline_drvapi.h"
}
# 211 "./sdk/cutil_inline_drvapi.h"
}
# 213 "./sdk/cutil_inline_drvapi.h"
inline void __cuCheckMsg(const char *msg, const char *file, const int line)
# 214 "./sdk/cutil_inline_drvapi.h"
{
# 215 "./sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 216 "./sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 217 "./sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> %s", msg);
# 218 "./sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> cuCtxSynchronize API error = %04d in file <%s>, line %i.\n", err, file, line);
# 220 "./sdk/cutil_inline_drvapi.h"
exit(-1);
# 221 "./sdk/cutil_inline_drvapi.h"
}
# 222 "./sdk/cutil_inline_drvapi.h"
}
# 228 "./sdk/cutil_inline_drvapi.h"
inline int cutilDeviceInitDrv(int ARGC, char **ARGV)
# 229 "./sdk/cutil_inline_drvapi.h"
{
# 230 "./sdk/cutil_inline_drvapi.h"
int cuDevice = 0;
# 231 "./sdk/cutil_inline_drvapi.h"
int deviceCount = 0;
# 232 "./sdk/cutil_inline_drvapi.h"
CUresult err = cuInit(0);
# 233 "./sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) == err) {
# 234 "./sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "./sdk/cutil_inline_drvapi.h", 234); }
# 235 "./sdk/cutil_inline_drvapi.h"
if (deviceCount == 0) {
# 236 "./sdk/cutil_inline_drvapi.h"
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
# 237 "./sdk/cutil_inline_drvapi.h"
exit(-1);
# 238 "./sdk/cutil_inline_drvapi.h"
}
# 239 "./sdk/cutil_inline_drvapi.h"
int dev = 0;
# 240 "./sdk/cutil_inline_drvapi.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 241 "./sdk/cutil_inline_drvapi.h"
if (dev < 0) { dev = 0; }
# 242 "./sdk/cutil_inline_drvapi.h"
if (dev > (deviceCount - 1)) {
# 243 "./sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDeviceInitDrv (Device=%d) invalid GPU device.  %d GPU device(s) detected.\n\n", dev, deviceCount);
# 244 "./sdk/cutil_inline_drvapi.h"
return -dev;
# 245 "./sdk/cutil_inline_drvapi.h"
}
# 246 "./sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "./sdk/cutil_inline_drvapi.h", 246);
# 247 "./sdk/cutil_inline_drvapi.h"
char name[100];
# 248 "./sdk/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 249 "./sdk/cutil_inline_drvapi.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 250 "./sdk/cutil_inline_drvapi.h"
printf("> Using CUDA Device [%d]: %s\n", dev, name);
# 251 "./sdk/cutil_inline_drvapi.h"
}
# 252 "./sdk/cutil_inline_drvapi.h"
return dev;
# 253 "./sdk/cutil_inline_drvapi.h"
}
# 260 "./sdk/cutil_inline_drvapi.h"
inline CUdevice cutilChooseCudaDeviceDrv(int argc, char **argv, int *p_devID)
# 261 "./sdk/cutil_inline_drvapi.h"
{
# 262 "./sdk/cutil_inline_drvapi.h"
CUdevice cuDevice;
# 263 "./sdk/cutil_inline_drvapi.h"
int devID = 0;
# 265 "./sdk/cutil_inline_drvapi.h"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 266 "./sdk/cutil_inline_drvapi.h"
devID = cutilDeviceInitDrv(argc, argv);
# 267 "./sdk/cutil_inline_drvapi.h"
if (devID < 0) {
# 268 "./sdk/cutil_inline_drvapi.h"
printf("exiting...\n");
# 269 "./sdk/cutil_inline_drvapi.h"
exit(0);
# 270 "./sdk/cutil_inline_drvapi.h"
}
# 271 "./sdk/cutil_inline_drvapi.h"
} else {
# 273 "./sdk/cutil_inline_drvapi.h"
char name[100];
# 274 "./sdk/cutil_inline_drvapi.h"
devID = cutilDrvGetMaxGflopsDeviceId();
# 275 "./sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, devID), "./sdk/cutil_inline_drvapi.h", 275);
# 276 "./sdk/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 277 "./sdk/cutil_inline_drvapi.h"
printf("> Using CUDA Device [%d]: %s\n", devID, name);
# 278 "./sdk/cutil_inline_drvapi.h"
}
# 279 "./sdk/cutil_inline_drvapi.h"
cuDeviceGet(&cuDevice, devID);
# 280 "./sdk/cutil_inline_drvapi.h"
if (p_devID) { (*p_devID) = devID; }
# 281 "./sdk/cutil_inline_drvapi.h"
return cuDevice;
# 282 "./sdk/cutil_inline_drvapi.h"
}
# 287 "./sdk/cutil_inline_drvapi.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 288 "./sdk/cutil_inline_drvapi.h"
{
# 289 "./sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 290 "./sdk/cutil_inline_drvapi.h"
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
# 291 "./sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 293 "./sdk/cutil_inline_drvapi.h"
exit(-1);
# 294 "./sdk/cutil_inline_drvapi.h"
}
# 295 "./sdk/cutil_inline_drvapi.h"
err = cuCtxSynchronize();
# 296 "./sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 297 "./sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 299 "./sdk/cutil_inline_drvapi.h"
exit(-1);
# 300 "./sdk/cutil_inline_drvapi.h"
}
# 301 "./sdk/cutil_inline_drvapi.h"
}
# 304 "./sdk/cutil_inline_drvapi.h"
inline bool cutilDrvCudaDevCapabilities(int major_version, int minor_version, int deviceNum)
# 305 "./sdk/cutil_inline_drvapi.h"
{
# 306 "./sdk/cutil_inline_drvapi.h"
int major, minor, dev;
# 307 "./sdk/cutil_inline_drvapi.h"
char device_name[256];
# 313 "./sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&dev, deviceNum), "./sdk/cutil_inline_drvapi.h", 313);
# 314 "./sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceComputeCapability(&major, &minor, dev), "./sdk/cutil_inline_drvapi.h", 314);
# 315 "./sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetName(device_name, 256, dev), "./sdk/cutil_inline_drvapi.h", 315);
# 317 "./sdk/cutil_inline_drvapi.h"
if ((major > major_version) || ((major == major_version) && (minor >= minor_version)))
# 319 "./sdk/cutil_inline_drvapi.h"
{
# 320 "./sdk/cutil_inline_drvapi.h"
printf("> Device %d: < %s >, Compute SM %d.%d detected\n", dev, device_name, major, minor);
# 321 "./sdk/cutil_inline_drvapi.h"
return true;
# 322 "./sdk/cutil_inline_drvapi.h"
} else
# 324 "./sdk/cutil_inline_drvapi.h"
{
# 325 "./sdk/cutil_inline_drvapi.h"
printf("There is no device supporting CUDA compute capability %d.%d.\n", major_version, minor_version);
# 326 "./sdk/cutil_inline_drvapi.h"
printf("PASSED\n");
# 327 "./sdk/cutil_inline_drvapi.h"
return false;
# 328 "./sdk/cutil_inline_drvapi.h"
}
# 329 "./sdk/cutil_inline_drvapi.h"
}
# 332 "./sdk/cutil_inline_drvapi.h"
inline bool cutilDrvCudaCapabilities(int major_version, int minor_version)
# 333 "./sdk/cutil_inline_drvapi.h"
{
# 334 "./sdk/cutil_inline_drvapi.h"
return cutilDrvCudaDevCapabilities(major_version, minor_version, 0);
# 335 "./sdk/cutil_inline_drvapi.h"
}
# 23 "./sdk/cutil_inline.h"
inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
# 24 "./sdk/cutil_inline.h"
{
# 25 "./sdk/cutil_inline.h"
printf("CUDA %d.%02d Toolkit built this project.\n", 4010 / 1000, 4010 % 100);
# 26 "./sdk/cutil_inline.h"
printf("  [ %s ] requirements:\n", sSDKsample);
# 27 "./sdk/cutil_inline.h"
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
# 28 "./sdk/cutil_inline.h"
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
# 29 "./sdk/cutil_inline.h"
}
# 19 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
extern "C" { typedef unsigned uint; }
# 22 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
typedef float2 fComplex;
# 35 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
inline int iDivUp(int a, int b) {
# 36 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
return ((a % b) != 0) ? ((a / b) + 1) : (a / b);
# 37 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
}
# 40 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
inline int iAlignUp(int a, int b) {
# 41 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
return ((a % b) != 0) ? ((a - (a % b)) + b) : a;
# 42 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
}
# 44 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
extern "C" void convolutionClampToBorderCPU(float * , float * , float * , int , int , int , int , int , int );
# 56 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
extern "C" void padKernel(float * , float * , int , int , int , int , int , int );
# 67 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
extern "C" void padDataClampToBorder(float * , float * , int , int , int , int , int , int , int , int );
# 80 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
extern "C" void modulateAndNormalize(fComplex * , fComplex * , int , int , int );
# 88 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
extern "C" void spPostprocess2D(void * , void * , uint , uint , uint , int );
# 97 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
extern "C" void spPreprocess2D(void * , void * , uint , uint , uint , int );
# 106 "tests/convolutionFFT2D/convolutionFFT2D_common.h"
extern "C" void spProcess2D(void * , void * , void * , uint , uint , int );
# 18 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
static texture< float, 1, cudaReadModeElementType> texFloat;
# 31 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void padKernel_kernel(float *
# 32 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Dst, float *
# 33 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Src, int
# 34 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
fftH, int
# 35 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
fftW, int
# 36 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
kernelH, int
# 37 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
kernelW, int
# 38 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
kernelY, int
# 39 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
kernelX) ;
# 56 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void padDataClampToBorder_kernel(float *
# 57 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Dst, float *
# 58 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Src, int
# 59 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
fftH, int
# 60 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
fftW, int
# 61 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
dataH, int
# 62 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
dataW, int
# 63 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
kernelH, int
# 64 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
kernelW, int
# 65 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
kernelY, int
# 66 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
kernelX) ;
# 93 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
__attribute__((unused)) inline void mulAndScale(fComplex &a, const fComplex &b, const float &c) {int volatile ___ = 1;(void)a;(void)b;(void)c;
# 96 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
exit(___);}
# 98 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void modulateAndNormalize_kernel(fComplex *
# 99 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Dst, fComplex *
# 100 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Src, int
# 101 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
dataSize, float
# 102 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
c) ;
# 122 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
static texture< float2, 1, cudaReadModeElementType> texComplexA;
# 123 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
static texture< float2, 1, cudaReadModeElementType> texComplexB;
# 141 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
__attribute__((unused)) inline void spPostprocessC2C(fComplex &D1, fComplex &D2, const fComplex &twiddle) {int volatile ___ = 1;(void)D1;(void)D2;(void)twiddle;
# 151 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
exit(___);}
# 154 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
__attribute__((unused)) inline void spPreprocessC2C(fComplex &D1, fComplex &D2, const fComplex &twiddle) {int volatile ___ = 1;(void)D1;(void)D2;(void)twiddle;
# 164 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
exit(___);}
# 166 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
__attribute__((unused)) inline void getTwiddle(fComplex &twiddle, float phase) {int volatile ___ = 1;(void)twiddle;(void)phase;
# 168 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
exit(___);}
# 170 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
__attribute__((unused)) inline uint mod(uint a, uint DA) {int volatile ___ = 1;(void)a;(void)DA;
# 173 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
exit(___);}
# 175 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
static inline uint factorRadix2(uint &log2N, uint n) {
# 176 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
if (!(n)) {
# 177 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
log2N = (0);
# 178 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
return 0;
# 179 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
} else {
# 180 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
for (log2N = (0); (n % (2)) == (0); (n /= (2)), (log2N++)) { ; }
# 181 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
return n;
# 182 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
}
# 183 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
}
# 185 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
__attribute__((unused)) inline void udivmod(uint &dividend, uint divisor, uint &rem) {int volatile ___ = 1;(void)dividend;(void)divisor;(void)rem;
# 193 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
exit(___);}
# 195 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void spPostprocess2D_kernel(fComplex *
# 196 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Dst, fComplex *
# 197 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Src, uint
# 198 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
DY, uint
# 199 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
DX, uint
# 200 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
threadCount, uint
# 201 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
padding, float
# 202 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
phaseBase) ;
# 252 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void spPreprocess2D_kernel(fComplex *
# 253 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Dst, fComplex *
# 254 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Src, uint
# 255 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
DY, uint
# 256 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
DX, uint
# 257 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
threadCount, uint
# 258 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
padding, float
# 259 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
phaseBase) ;
# 318 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void spProcess2D_kernel(fComplex *
# 319 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_Dst, fComplex *
# 320 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_SrcA, fComplex *
# 321 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
d_SrcB, uint
# 322 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
DY, uint
# 323 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
DX, uint
# 324 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
threadCount, float
# 325 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
phaseBase, float
# 326 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
c) ;
# 26 "tests/convolutionFFT2D/convolutionFFT2D.cu"
extern "C" void padKernel(float *
# 27 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Dst, float *
# 28 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Src, int
# 29 "tests/convolutionFFT2D/convolutionFFT2D.cu"
fftH, int
# 30 "tests/convolutionFFT2D/convolutionFFT2D.cu"
fftW, int
# 31 "tests/convolutionFFT2D/convolutionFFT2D.cu"
kernelH, int
# 32 "tests/convolutionFFT2D/convolutionFFT2D.cu"
kernelW, int
# 33 "tests/convolutionFFT2D/convolutionFFT2D.cu"
kernelY, int
# 34 "tests/convolutionFFT2D/convolutionFFT2D.cu"
kernelX)
# 35 "tests/convolutionFFT2D/convolutionFFT2D.cu"
{
# 36 "tests/convolutionFFT2D/convolutionFFT2D.cu"
(d_Src != d_Dst) ? (static_cast< void>(0)) : __assert_fail("d_Src != d_Dst", "tests/convolutionFFT2D/convolutionFFT2D.cu", 36, __PRETTY_FUNCTION__);
# 37 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dim3 threads(32, 8);
# 38 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dim3 grid(iDivUp(kernelW, threads.x), iDivUp(kernelH, threads.y));
# 40 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cudaSafeCall(cudaBindTexture(0, texFloat, d_Src), "tests/convolutionFFT2D/convolutionFFT2D.cu", 40);
# 41 "tests/convolutionFFT2D/convolutionFFT2D.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : padKernel_kernel(d_Dst, d_Src, fftH, fftW, kernelH, kernelW, kernelY, kernelX);
# 51 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cutilCheckMsg("padKernel_kernel<<<>>> execution failed\n", "tests/convolutionFFT2D/convolutionFFT2D.cu", 51);
# 52 "tests/convolutionFFT2D/convolutionFFT2D.cu"
}
# 59 "tests/convolutionFFT2D/convolutionFFT2D.cu"
extern "C" void padDataClampToBorder(float *
# 60 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Dst, float *
# 61 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Src, int
# 62 "tests/convolutionFFT2D/convolutionFFT2D.cu"
fftH, int
# 63 "tests/convolutionFFT2D/convolutionFFT2D.cu"
fftW, int
# 64 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dataH, int
# 65 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dataW, int
# 66 "tests/convolutionFFT2D/convolutionFFT2D.cu"
kernelW, int
# 67 "tests/convolutionFFT2D/convolutionFFT2D.cu"
kernelH, int
# 68 "tests/convolutionFFT2D/convolutionFFT2D.cu"
kernelY, int
# 69 "tests/convolutionFFT2D/convolutionFFT2D.cu"
kernelX)
# 70 "tests/convolutionFFT2D/convolutionFFT2D.cu"
{
# 71 "tests/convolutionFFT2D/convolutionFFT2D.cu"
(d_Src != d_Dst) ? (static_cast< void>(0)) : __assert_fail("d_Src != d_Dst", "tests/convolutionFFT2D/convolutionFFT2D.cu", 71, __PRETTY_FUNCTION__);
# 72 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dim3 threads(32, 8);
# 73 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dim3 grid(iDivUp(fftW, threads.x), iDivUp(fftH, threads.y));
# 75 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cudaSafeCall(cudaBindTexture(0, texFloat, d_Src), "tests/convolutionFFT2D/convolutionFFT2D.cu", 75);
# 76 "tests/convolutionFFT2D/convolutionFFT2D.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : padDataClampToBorder_kernel(d_Dst, d_Src, fftH, fftW, dataH, dataW, kernelH, kernelW, kernelY, kernelX);
# 88 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cutilCheckMsg("padDataClampToBorder_kernel<<<>>> execution failed\n", "tests/convolutionFFT2D/convolutionFFT2D.cu", 88);
# 89 "tests/convolutionFFT2D/convolutionFFT2D.cu"
}
# 97 "tests/convolutionFFT2D/convolutionFFT2D.cu"
extern "C" void modulateAndNormalize(fComplex *
# 98 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Dst, fComplex *
# 99 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Src, int
# 100 "tests/convolutionFFT2D/convolutionFFT2D.cu"
fftH, int
# 101 "tests/convolutionFFT2D/convolutionFFT2D.cu"
fftW, int
# 102 "tests/convolutionFFT2D/convolutionFFT2D.cu"
padding)
# 103 "tests/convolutionFFT2D/convolutionFFT2D.cu"
{
# 104 "tests/convolutionFFT2D/convolutionFFT2D.cu"
((fftW % 2) == 0) ? (static_cast< void>(0)) : __assert_fail("fftW % 2 == 0", "tests/convolutionFFT2D/convolutionFFT2D.cu", 104, __PRETTY_FUNCTION__);
# 105 "tests/convolutionFFT2D/convolutionFFT2D.cu"
const int dataSize = (fftH * ((fftW / 2) + padding));
# 107 "tests/convolutionFFT2D/convolutionFFT2D.cu"
cudaConfigureCall(iDivUp(dataSize, 256), 256) ? ((void)0) : modulateAndNormalize_kernel(d_Dst, d_Src, dataSize, (1.0F) / ((float)(fftW * fftH)));
# 113 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cutilCheckMsg("modulateAndNormalize() execution failed\n", "tests/convolutionFFT2D/convolutionFFT2D.cu", 113);
# 114 "tests/convolutionFFT2D/convolutionFFT2D.cu"
}
# 121 "tests/convolutionFFT2D/convolutionFFT2D.cu"
static const double PI = (3.141592653589793116);
# 122 "tests/convolutionFFT2D/convolutionFFT2D.cu"
static const uint BLOCKDIM = (256);
# 124 "tests/convolutionFFT2D/convolutionFFT2D.cu"
extern "C" void spPostprocess2D(void *
# 125 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Dst, void *
# 126 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Src, uint
# 127 "tests/convolutionFFT2D/convolutionFFT2D.cu"
DY, uint
# 128 "tests/convolutionFFT2D/convolutionFFT2D.cu"
DX, uint
# 129 "tests/convolutionFFT2D/convolutionFFT2D.cu"
padding, int
# 130 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dir)
# 131 "tests/convolutionFFT2D/convolutionFFT2D.cu"
{
# 132 "tests/convolutionFFT2D/convolutionFFT2D.cu"
(d_Src != d_Dst) ? (static_cast< void>(0)) : __assert_fail("d_Src != d_Dst", "tests/convolutionFFT2D/convolutionFFT2D.cu", 132, __PRETTY_FUNCTION__);
# 133 "tests/convolutionFFT2D/convolutionFFT2D.cu"
((DX % (2)) == (0)) ? (static_cast< void>(0)) : __assert_fail("DX % 2 == 0", "tests/convolutionFFT2D/convolutionFFT2D.cu", 133, __PRETTY_FUNCTION__);
# 136 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint log2DX, log2DY;
# 137 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint factorizationRemX = factorRadix2(log2DX, DX);
# 138 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint factorizationRemY = factorRadix2(log2DY, DY);
# 139 "tests/convolutionFFT2D/convolutionFFT2D.cu"
((factorizationRemX == (1)) && (factorizationRemY == (1))) ? (static_cast< void>(0)) : __assert_fail("factorizationRemX == 1 && factorizationRemY == 1", "tests/convolutionFFT2D/convolutionFFT2D.cu", 139, __PRETTY_FUNCTION__);
# 142 "tests/convolutionFFT2D/convolutionFFT2D.cu"
const uint threadCount = (DY * (DX / (2)));
# 143 "tests/convolutionFFT2D/convolutionFFT2D.cu"
const double phaseBase = ((dir * PI) / ((double)DX));
# 145 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cudaSafeCall(cudaBindTexture(0, texComplexA, d_Src), "tests/convolutionFFT2D/convolutionFFT2D.cu", 145);
# 146 "tests/convolutionFFT2D/convolutionFFT2D.cu"
cudaConfigureCall(iDivUp(threadCount, BLOCKDIM), BLOCKDIM) ? ((void)0) : spPostprocess2D_kernel((fComplex *)d_Dst, (fComplex *)d_Src, DY, DX, threadCount, padding, (float)phaseBase);
# 152 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cutilCheckMsg("spPostprocess2D_kernel<<<>>> execution failed\n", "tests/convolutionFFT2D/convolutionFFT2D.cu", 152);
# 153 "tests/convolutionFFT2D/convolutionFFT2D.cu"
}
# 155 "tests/convolutionFFT2D/convolutionFFT2D.cu"
extern "C" void spPreprocess2D(void *
# 156 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Dst, void *
# 157 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Src, uint
# 158 "tests/convolutionFFT2D/convolutionFFT2D.cu"
DY, uint
# 159 "tests/convolutionFFT2D/convolutionFFT2D.cu"
DX, uint
# 160 "tests/convolutionFFT2D/convolutionFFT2D.cu"
padding, int
# 161 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dir)
# 162 "tests/convolutionFFT2D/convolutionFFT2D.cu"
{
# 163 "tests/convolutionFFT2D/convolutionFFT2D.cu"
(d_Src != d_Dst) ? (static_cast< void>(0)) : __assert_fail("d_Src != d_Dst", "tests/convolutionFFT2D/convolutionFFT2D.cu", 163, __PRETTY_FUNCTION__);
# 164 "tests/convolutionFFT2D/convolutionFFT2D.cu"
((DX % (2)) == (0)) ? (static_cast< void>(0)) : __assert_fail("DX % 2 == 0", "tests/convolutionFFT2D/convolutionFFT2D.cu", 164, __PRETTY_FUNCTION__);
# 167 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint log2DX, log2DY;
# 168 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint factorizationRemX = factorRadix2(log2DX, DX);
# 169 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint factorizationRemY = factorRadix2(log2DY, DY);
# 170 "tests/convolutionFFT2D/convolutionFFT2D.cu"
((factorizationRemX == (1)) && (factorizationRemY == (1))) ? (static_cast< void>(0)) : __assert_fail("factorizationRemX == 1 && factorizationRemY == 1", "tests/convolutionFFT2D/convolutionFFT2D.cu", 170, __PRETTY_FUNCTION__);
# 173 "tests/convolutionFFT2D/convolutionFFT2D.cu"
const uint threadCount = (DY * (DX / (2)));
# 174 "tests/convolutionFFT2D/convolutionFFT2D.cu"
const double phaseBase = (((-dir) * PI) / ((double)DX));
# 176 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cudaSafeCall(cudaBindTexture(0, texComplexA, d_Src), "tests/convolutionFFT2D/convolutionFFT2D.cu", 176);
# 177 "tests/convolutionFFT2D/convolutionFFT2D.cu"
cudaConfigureCall(iDivUp(threadCount, BLOCKDIM), BLOCKDIM) ? ((void)0) : spPreprocess2D_kernel((fComplex *)d_Dst, (fComplex *)d_Src, DY, DX, threadCount, padding, (float)phaseBase);
# 183 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cutilCheckMsg("spPreprocess2D_kernel<<<>>> execution failed\n", "tests/convolutionFFT2D/convolutionFFT2D.cu", 183);
# 184 "tests/convolutionFFT2D/convolutionFFT2D.cu"
}
# 191 "tests/convolutionFFT2D/convolutionFFT2D.cu"
extern "C" void spProcess2D(void *
# 192 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_Dst, void *
# 193 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_SrcA, void *
# 194 "tests/convolutionFFT2D/convolutionFFT2D.cu"
d_SrcB, uint
# 195 "tests/convolutionFFT2D/convolutionFFT2D.cu"
DY, uint
# 196 "tests/convolutionFFT2D/convolutionFFT2D.cu"
DX, int
# 197 "tests/convolutionFFT2D/convolutionFFT2D.cu"
dir)
# 198 "tests/convolutionFFT2D/convolutionFFT2D.cu"
{
# 199 "tests/convolutionFFT2D/convolutionFFT2D.cu"
((DY % (2)) == (0)) ? (static_cast< void>(0)) : __assert_fail("DY % 2 == 0", "tests/convolutionFFT2D/convolutionFFT2D.cu", 199, __PRETTY_FUNCTION__);
# 202 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint log2DX, log2DY;
# 203 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint factorizationRemX = factorRadix2(log2DX, DX);
# 204 "tests/convolutionFFT2D/convolutionFFT2D.cu"
uint factorizationRemY = factorRadix2(log2DY, DY);
# 205 "tests/convolutionFFT2D/convolutionFFT2D.cu"
((factorizationRemX == (1)) && (factorizationRemY == (1))) ? (static_cast< void>(0)) : __assert_fail("factorizationRemX == 1 && factorizationRemY == 1", "tests/convolutionFFT2D/convolutionFFT2D.cu", 205, __PRETTY_FUNCTION__);
# 208 "tests/convolutionFFT2D/convolutionFFT2D.cu"
const uint threadCount = ((DY / (2)) * DX);
# 209 "tests/convolutionFFT2D/convolutionFFT2D.cu"
const double phaseBase = ((dir * PI) / ((double)DX));
# 211 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cudaSafeCall(cudaBindTexture(0, texComplexA, d_SrcA), "tests/convolutionFFT2D/convolutionFFT2D.cu", 211);
# 212 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cudaSafeCall(cudaBindTexture(0, texComplexB, d_SrcB), "tests/convolutionFFT2D/convolutionFFT2D.cu", 212);
# 213 "tests/convolutionFFT2D/convolutionFFT2D.cu"
cudaConfigureCall(iDivUp(threadCount, BLOCKDIM), BLOCKDIM) ? ((void)0) : spProcess2D_kernel((fComplex *)d_Dst, (fComplex *)d_SrcA, (fComplex *)d_SrcB, DY, DX, threadCount, (float)phaseBase, (0.5F) / ((float)(DY * DX)));
# 221 "tests/convolutionFFT2D/convolutionFFT2D.cu"
__cutilCheckMsg("spProcess2D_kernel<<<>>> execution failed\n", "tests/convolutionFFT2D/convolutionFFT2D.cu", 221);
# 222 "tests/convolutionFFT2D/convolutionFFT2D.cu"
}
# 1 "tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"
# 1 "tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c" 1 3
# 1 "/usr/local/cuda4.1/cuda/include/crt/host_runtime.h" 1 3
# 74 "/usr/local/cuda4.1/cuda/include/crt/host_runtime.h" 3
template <typename T>
static inline void *__cudaAddressOf(T &val)
{
    return (void *)(&(const_cast<char &>(reinterpret_cast<const volatile char &>(val))));
}
# 103 "/usr/local/cuda4.1/cuda/include/crt/host_runtime.h" 3
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

# 1 "/usr/local/cuda4.1/cuda/include/common_functions.h" 1 3
# 159 "/usr/local/cuda4.1/cuda/include/common_functions.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/math_functions.h" 1 3
# 2935 "/usr/local/cuda4.1/cuda/include/math_functions.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/math_constants.h" 1 3
# 2936 "/usr/local/cuda4.1/cuda/include/math_functions.h" 2 3
# 5550 "/usr/local/cuda4.1/cuda/include/math_functions.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/crt/func_macro.h" 1 3
# 5551 "/usr/local/cuda4.1/cuda/include/math_functions.h" 2 3
# 7292 "/usr/local/cuda4.1/cuda/include/math_functions.h" 3
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

inline double erfcx(double a)
{
  double x, t1, t2, t3;

  if (__isnan(a)) {
    return a + a;
  }
  x = fabs(a);
  if (x < 32.0) {
# 7577 "/usr/local/cuda4.1/cuda/include/math_functions.h" 3
    t1 = x - 4.0;
    t2 = x + 4.0;
    t2 = t1 / t2;

    t1 = - 3.5602694826817400E-010;
    t1 = t1 * t2 - 9.7239122591447274E-009;
    t1 = t1 * t2 - 8.9350224851649119E-009;
    t1 = t1 * t2 + 1.0404430921625484E-007;
    t1 = t1 * t2 + 5.8806698585341259E-008;
    t1 = t1 * t2 - 8.2147414929116908E-007;
    t1 = t1 * t2 + 3.0956409853306241E-007;
    t1 = t1 * t2 + 5.7087871844325649E-006;
    t1 = t1 * t2 - 1.1231787437600085E-005;
    t1 = t1 * t2 - 2.4399558857200190E-005;
    t1 = t1 * t2 + 1.5062557169571788E-004;
    t1 = t1 * t2 - 1.9925637684786154E-004;
    t1 = t1 * t2 - 7.5777429182785833E-004;
    t1 = t1 * t2 + 5.0319698792599572E-003;
    t1 = t1 * t2 - 1.6197733895953217E-002;
    t1 = t1 * t2 + 3.7167515553018733E-002;
    t1 = t1 * t2 - 6.6330365827532434E-002;
    t1 = t1 * t2 + 9.3732834997115544E-002;
    t1 = t1 * t2 - 1.0103906603555676E-001;
    t1 = t1 * t2 + 6.8097054254735140E-002;
    t1 = t1 * t2 + 1.5379652102605428E-002;
    t1 = t1 * t2 - 1.3962111684056291E-001;
    t1 = t1 * t2 + 1.2329951186255526E+000;

    t2 = 2.0 * x + 1.0;
    t1 = t1 / t2;
  } else {

    t2 = 1.0 / x;
    t3 = t2 * t2;
    t1 = -29.53125;
    t1 = t1 * t3 + 6.5625;
    t1 = t1 * t3 - 1.875;
    t1 = t1 * t3 + 0.75;
    t1 = t1 * t3 - 0.5;
    t1 = t1 * t3 + 1.0;
    t2 = t2 * 5.6418958354775628e-001;
    t1 = t1 * t2;
  }
  if (a < 0.0) {

    t2 = ((int)(x * 16.0)) * 0.0625;
    t3 = (x - t2) * (x + t2);
    t3 = exp(t2 * t2) * exp(t3);
    t3 = t3 + t3;
    t1 = t3 - t1;
  }
  return t1;
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

inline float erfcxf(float a)
{
  return (float)erfcx((double)a);
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
# 7730 "/usr/local/cuda4.1/cuda/include/math_functions.h" 3
# 1 "/usr/local/cuda4.1/cuda/include/math_functions_dbl_ptx3.h" 1 3
# 7731 "/usr/local/cuda4.1/cuda/include/math_functions.h" 2 3
# 160 "/usr/local/cuda4.1/cuda/include/common_functions.h" 2 3
# 176 "/usr/local/cuda4.1/cuda/include/crt/host_runtime.h" 2 3







#pragma pack()
# 2 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c" 2 3
# 1 "/tmp/tmpxft_00006c6a_00000000-3_convolutionFFT2D.fatbin.c" 1 3


asm(
".section .nv_fatbin, \"a\"\n"
".align 8\n"
"fatbinData:\n"
".quad 0x00100001ba55ed50,0x0000000000008257,0x0000007001000001,0x0000000000005d13\n"
".quad 0x0000003800000000,0x0000001400030000,0x0000002a00000040,0x0000000000000015\n"
".quad 0x0000000000000000,0x0000000000000000,0x6f632f7374736574,0x6f6974756c6f766e\n"
".quad 0x632f44325446466e,0x6974756c6f766e6f,0x2e44325446466e6f,0x0000000000007563\n"
".quad 0x762e0a0a0a0a0a0a,0x33206e6f69737265,0x677261742e0a302e,0x30325f6d73207465\n"
".quad 0x7365726464612e0a,0x3620657a69735f73,0x656c69662e0a0a34,0x706d742f22203109\n"
".quad 0x5f746678706d742f,0x6136633630303030,0x303030303030305f,0x766e6f635f372d30\n"
".quad 0x466e6f6974756c6f,0x7070632e44325446,0x69662e0a22692e33,0x657422203209656c\n"
".quad 0x766e6f632f737473,0x466e6f6974756c6f,0x6e6f632f44325446,0x6e6f6974756c6f76\n"
".quad 0x75632e4432544646,0x656c69662e0a2268,0x7273752f22203309,0x632f6c61636f6c2f\n"
".quad 0x632f312e34616475,0x6c636e692f616475,0x697665642f656475,0x74636e75665f6563\n"
".quad 0x0a22682e736e6f69,0x203409656c69662e,0x6f6c2f7273752f22,0x616475632f6c6163\n"
".quad 0x616475632f312e34,0x69632f6d76766e2f,0x6564756c636e695f,0x6f6c672e0a22682e\n"
".quad 0x7865742e206c6162,0x4678657420666572,0x672e0a3b74616f6c,0x742e206c61626f6c\n"
".quad 0x6574206665727865,0x78656c706d6f4378,0x626f6c672e0a3b41,0x727865742e206c61\n"
".quad 0x6f43786574206665,0x0a3b4278656c706d,0x207972746e652e0a,0x4b64617036315a5f\n"
".quad 0x656b5f6c656e7265,0x5f5366506c656e72,0x0a28696969696969,0x2e206d617261702e\n"
".quad 0x36315a5f20343675,0x656e72654b646170,0x6c656e72656b5f6c,0x696969695f536650\n"
".quad 0x6d617261705f6969,0x7261702e0a2c305f,0x203436752e206d61,0x4b64617036315a5f\n"
".quad 0x656b5f6c656e7265,0x5f5366506c656e72,0x705f696969696969,0x0a2c315f6d617261\n"
".quad 0x2e206d617261702e,0x36315a5f20323375,0x656e72654b646170,0x6c656e72656b5f6c\n"
".quad 0x696969695f536650,0x6d617261705f6969,0x7261702e0a2c325f,0x203233752e206d61\n"
".quad 0x4b64617036315a5f,0x656b5f6c656e7265,0x5f5366506c656e72,0x705f696969696969\n"
".quad 0x0a2c335f6d617261,0x2e206d617261702e,0x36315a5f20323375,0x656e72654b646170\n"
".quad 0x6c656e72656b5f6c,0x696969695f536650,0x6d617261705f6969,0x7261702e0a2c345f\n"
".quad 0x203233752e206d61,0x4b64617036315a5f,0x656b5f6c656e7265,0x5f5366506c656e72\n"
".quad 0x705f696969696969,0x0a2c355f6d617261,0x2e206d617261702e,0x36315a5f20323375\n"
".quad 0x656e72654b646170,0x6c656e72656b5f6c,0x696969695f536650,0x6d617261705f6969\n"
".quad 0x7261702e0a2c365f,0x203233752e206d61,0x4b64617036315a5f,0x656b5f6c656e7265\n"
".quad 0x5f5366506c656e72,0x705f696969696969,0x290a375f6d617261,0x206765722e0a7b0a\n"
".quad 0x3c6625203233662e,0x6765722e0a3b3e35,0x2520646572702e20,0x722e0a3b3e343c70\n"
".quad 0x203233732e206765,0x0a3b3e32333c7225,0x36732e206765722e,0x3e353c6c72252034\n"
".quad 0x702e646c0a0a0a3b,0x3436752e6d617261,0x5b202c326c722520,0x4b64617036315a5f\n"
".quad 0x656b5f6c656e7265,0x5f5366506c656e72,0x705f696969696969,0x3b5d305f6d617261\n"
".quad 0x617261702e646c0a,0x7225203233752e6d,0x36315a5f5b202c38,0x656e72654b646170\n"
".quad 0x6c656e72656b5f6c,0x696969695f536650,0x6d617261705f6969,0x2e646c0a3b5d345f\n"
".quad 0x33752e6d61726170,0x5b202c3372252032,0x4b64617036315a5f,0x656b5f6c656e7265\n"
".quad 0x5f5366506c656e72,0x705f696969696969,0x3b5d355f6d617261,0x6f742e617476630a\n"
".quad 0x2e6c61626f6c672e,0x316c722520343675,0x0a3b326c7225202c,0x34203220636f6c2e\n"
".quad 0x2e766f6d0a312031,0x2c39722520323375,0x2e64696174632520,0x752e766f6d0a3b79\n"
".quad 0x2c30317225203233,0x792e6469746e2520,0x33752e766f6d0a3b,0x202c313172252032\n"
".quad 0x0a3b792e64697425,0x732e6f6c2e64616d,0x202c367225203233,0x317225202c397225\n"
".quad 0x3b31317225202c30,0x203220636f6c2e0a,0x766f6d0a31203234,0x317225203233752e\n"
".quad 0x6961746325202c32,0x766f6d0a3b782e64,0x317225203233752e,0x6469746e25202c33\n"
".quad 0x2e766f6d0a3b782e,0x3431722520323375,0x782e64697425202c,0x6f6c2e64616d0a3b\n"
".quad 0x377225203233732e,0x202c32317225202c,0x7225202c33317225,0x636f6c2e0a3b3431\n"
".quad 0x0a31203434203220,0x2e746c2e70746573,0x2c31702520323373,0x7225202c36722520\n"
".quad 0x2e707465730a3b38,0x25203233732e746c,0x2c377225202c3270,0x6e610a3b33722520\n"
".quad 0x2520646572702e64,0x2c317025202c3370,0x6c2e0a3b32702520,0x203434203220636f\n"
".quad 0x6220337025400a31,0x325f304242206172,0x20636f6c2e0a0a3b,0x720a322039342032\n"
".quad 0x3042420a0a3b7465,0x702e646c0a3a325f,0x3233752e6d617261,0x5b202c3033722520\n"
".quad 0x4b64617036315a5f,0x656b5f6c656e7265,0x5f5366506c656e72,0x705f696969696969\n"
".quad 0x3b5d365f6d617261,0x203220636f6c2e0a,0x6275730a31203534,0x317225203233732e\n"
".quad 0x202c367225202c36,0x6f6d0a3b30337225,0x7225203233752e76,0x2e0a3b30202c3731\n"
".quad 0x3534203220636f6c,0x732e7268730a3120,0x2c38317225203233,0x33202c3631722520\n"
".quad 0x61702e646c0a3b31,0x203233752e6d6172,0x5f5b202c37327225,0x654b64617036315a\n"
".quad 0x72656b5f6c656e72,0x695f5366506c656e,0x61705f6969696969,0x0a3b5d325f6d6172\n"
".quad 0x203233622e646e61,0x7225202c39317225,0x37327225202c3831,0x33732e6464610a3b\n"
".quad 0x202c303272252032,0x7225202c39317225,0x702e646c0a3b3631,0x3233752e6d617261\n"
".quad 0x5b202c3133722520,0x4b64617036315a5f,0x656b5f6c656e7265,0x5f5366506c656e72\n"
".quad 0x705f696969696969,0x3b5d375f6d617261,0x203220636f6c2e0a,0x6275730a31203634\n"
".quad 0x327225203233732e,0x202c377225202c31,0x68730a3b31337225,0x7225203233732e72\n"
".quad 0x31327225202c3232,0x646c0a3b3133202c,0x752e6d617261702e,0x2c38327225203233\n"
".quad 0x617036315a5f5b20,0x5f6c656e72654b64,0x66506c656e72656b,0x6969696969695f53\n"
".quad 0x335f6d617261705f,0x622e646e610a3b5d,0x2c33327225203233,0x25202c3232722520\n"
".quad 0x2e646c0a3b383272,0x33752e6d61726170,0x202c393272252032,0x64617036315a5f5b\n"
".quad 0x6b5f6c656e72654b,0x5366506c656e7265,0x5f6969696969695f,0x5d355f6d61726170\n"
".quad 0x3220636f6c2e0a3b,0x616d0a3120373420,0x3233732e6f6c2e64,0x25202c3531722520\n"
".quad 0x39327225202c3672,0x0a0a3b377225202c,0x2e64312e78657409,0x732e3233662e3476\n"
".quad 0x2c3166257b203233,0x6625202c32662520,0x2c7d346625202c33,0x6f6c467865745b20\n"
".quad 0x3172257b202c7461,0x6d090a0a3b5d7d35,0x33732e6f6c2e6461,0x202c343272252032\n"
".quad 0x7225202c30327225,0x31327225202c3832,0x3220636f6c2e0a3b,0x64610a3120373420\n"
".quad 0x7225203233732e64,0x34327225202c3532,0x0a3b33327225202c,0x656469772e6c756d\n"
".quad 0x6c7225203233732e,0x2c35327225202c33,0x2e6464610a3b3420,0x346c722520343673\n"
".quad 0x202c316c7225202c,0x74730a3b336c7225,0x2e6c61626f6c672e,0x6c72255b20323366\n"
".quad 0x3b316625202c5d34,0x203220636f6c2e0a,0x7465720a32203934,0x6e652e0a0a7d0a3b\n"
".quad 0x37325a5f20797274,0x4361746144646170,0x6f426f54706d616c,0x72656b5f72656472\n"
".quad 0x695f5366506c656e,0x2869696969696969,0x206d617261702e0a,0x325a5f203436752e\n"
".quad 0x6174614464617037,0x426f54706d616c43,0x656b5f726564726f,0x5f5366506c656e72\n"
".quad 0x6969696969696969,0x305f6d617261705f,0x6d617261702e0a2c,0x5a5f203436752e20\n"
".quad 0x7461446461703732,0x6f54706d616c4361,0x6b5f726564726f42,0x5366506c656e7265\n"
".quad 0x696969696969695f,0x5f6d617261705f69,0x617261702e0a2c31,0x5f203233752e206d\n"
".quad 0x614464617037325a,0x54706d616c436174,0x5f726564726f426f,0x66506c656e72656b\n"
".quad 0x6969696969695f53,0x6d617261705f6969,0x7261702e0a2c325f,0x203233752e206d61\n"
".quad 0x4464617037325a5f,0x706d616c43617461,0x726564726f426f54,0x506c656e72656b5f\n"
".quad 0x69696969695f5366,0x617261705f696969,0x61702e0a2c335f6d,0x3233752e206d6172\n"
".quad 0x64617037325a5f20,0x6d616c4361746144,0x6564726f426f5470,0x6c656e72656b5f72\n"
".quad 0x696969695f536650,0x7261705f69696969,0x702e0a2c345f6d61,0x33752e206d617261\n"
".quad 0x617037325a5f2032,0x616c436174614464,0x64726f426f54706d,0x656e72656b5f7265\n"
".quad 0x6969695f5366506c,0x61705f6969696969,0x2e0a2c355f6d6172,0x752e206d61726170\n"
".quad 0x7037325a5f203233,0x6c43617461446461,0x726f426f54706d61,0x6e72656b5f726564\n"
".quad 0x69695f5366506c65,0x705f696969696969,0x0a2c365f6d617261,0x2e206d617261702e\n"
".quad 0x37325a5f20323375,0x4361746144646170,0x6f426f54706d616c,0x72656b5f72656472\n"
".quad 0x695f5366506c656e,0x5f69696969696969,0x2c375f6d61726170,0x206d617261702e0a\n"
".quad 0x325a5f203233752e,0x6174614464617037,0x426f54706d616c43,0x656b5f726564726f\n"
".quad 0x5f5366506c656e72,0x6969696969696969,0x385f6d617261705f,0x6d617261702e0a2c\n"
".quad 0x5a5f203233752e20,0x7461446461703732,0x6f54706d616c4361,0x6b5f726564726f42\n"
".quad 0x5366506c656e7265,0x696969696969695f,0x5f6d617261705f69,0x722e0a7b0a290a39\n"
".quad 0x203233662e206765,0x2e0a3b3e353c6625,0x6572702e20676572,0x3e30313c70252064\n"
".quad 0x2e206765722e0a3b,0x333c722520323373,0x6765722e0a3b3e30,0x7225203436732e20\n"
".quad 0x0a0a0a3b3e353c6c,0x6d617261702e646c,0x6c7225203436752e,0x37325a5f5b202c32\n"
".quad 0x4361746144646170,0x6f426f54706d616c,0x72656b5f72656472,0x695f5366506c656e\n"
".quad 0x5f69696969696969,0x5d305f6d61726170,0x7261702e646c0a3b,0x25203233752e6d61\n"
".quad 0x325a5f5b202c3872,0x6174614464617037,0x426f54706d616c43,0x656b5f726564726f\n"
".quad 0x5f5366506c656e72,0x6969696969696969,0x325f6d617261705f,0x61702e646c0a3b5d\n"
".quad 0x203233752e6d6172,0x5a5f5b202c317225,0x7461446461703732,0x6f54706d616c4361\n"
".quad 0x6b5f726564726f42,0x5366506c656e7265,0x696969696969695f,0x5f6d617261705f69\n"
".quad 0x702e646c0a3b5d33,0x3233752e6d617261,0x5f5b202c32722520,0x614464617037325a\n"
".quad 0x54706d616c436174,0x5f726564726f426f,0x66506c656e72656b,0x6969696969695f53\n"
".quad 0x6d617261705f6969,0x2e646c0a3b5d345f,0x33752e6d61726170,0x5b202c3372252032\n"
".quad 0x4464617037325a5f,0x706d616c43617461,0x726564726f426f54,0x506c656e72656b5f\n"
".quad 0x69696969695f5366,0x617261705f696969,0x646c0a3b5d355f6d,0x752e6d617261702e\n"
".quad 0x202c397225203233,0x64617037325a5f5b,0x6d616c4361746144,0x6564726f426f5470\n"
".quad 0x6c656e72656b5f72,0x696969695f536650,0x7261705f69696969,0x6c0a3b5d385f6d61\n"
".quad 0x2e6d617261702e64,0x3031722520323375,0x7037325a5f5b202c,0x6c43617461446461\n"
".quad 0x726f426f54706d61,0x6e72656b5f726564,0x69695f5366506c65,0x705f696969696969\n"
".quad 0x3b5d395f6d617261,0x6f742e617476630a,0x2e6c61626f6c672e,0x316c722520343675\n"
".quad 0x0a3b326c7225202c,0x36203220636f6c2e,0x2e766f6d0a312038,0x3131722520323375\n"
".quad 0x646961746325202c,0x2e766f6d0a3b792e,0x3231722520323375,0x2e6469746e25202c\n"
".quad 0x752e766f6d0a3b79,0x2c33317225203233,0x3b792e6469742520,0x2e6f6c2e64616d0a\n"
".quad 0x2c34722520323373,0x25202c3131722520,0x317225202c323172,0x20636f6c2e0a3b33\n"
".quad 0x6d0a312039362032,0x25203233752e766f,0x746325202c343172,0x6d0a3b782e646961\n"
".quad 0x25203233752e766f,0x746e25202c353172,0x6f6d0a3b782e6469,0x7225203233752e76\n"
".quad 0x64697425202c3631,0x2e64616d0a3b782e,0x25203233732e6f6c,0x34317225202c3572\n"
".quad 0x202c35317225202c,0x6c2e0a3b36317225,0x203037203220636f,0x33732e6464610a31\n"
".quad 0x25202c3672252032,0x3b327225202c3972,0x203220636f6c2e0a,0x6464610a31203137\n"
".quad 0x377225203233732e,0x202c30317225202c,0x6f6c2e0a3b337225,0x3120333720322063\n"
".quad 0x746c2e707465730a,0x317025203233732e,0x25202c347225202c,0x707465730a3b3872\n"
".quad 0x203233732e746c2e,0x357225202c327025,0x610a3b317225202c,0x20646572702e646e\n"
".quad 0x317025202c337025,0x2e0a3b327025202c,0x3337203220636f6c,0x20337025400a3120\n"
".quad 0x5f31424220617262,0x636f6c2e0a0a3b32,0x0a32203538203220,0x42420a0a3b746572\n"
".quad 0x6f6c2e0a3a325f31,0x3120383720322063,0x746c2e707465730a,0x347025203233732e\n"
".quad 0x25202c347225202c,0x702e646c0a3b3672,0x3233752e6d617261,0x5b202c3832722520\n"
".quad 0x4464617037325a5f,0x706d616c43617461,0x726564726f426f54,0x506c656e72656b5f\n"
".quad 0x69696969695f5366,0x617261705f696969,0x65730a3b5d345f6d,0x33732e65672e7074\n"
".quad 0x25202c3570252032,0x38327225202c3472,0x72702e646e610a3b,0x202c367025206465\n"
".quad 0x357025202c347025,0x33732e6464610a3b,0x202c383172252032,0x312d202c38327225\n"
".quad 0x622e706c65730a3b,0x2c39317225203233,0x25202c3831722520,0x3b367025202c3472\n"
".quad 0x617261702e646c0a,0x7225203233752e6d,0x325a5f5b202c3932,0x6174614464617037\n"
".quad 0x426f54706d616c43,0x656b5f726564726f,0x5f5366506c656e72,0x6969696969696969\n"
".quad 0x355f6d617261705f,0x2e707465730a3b5d,0x25203233732e6567,0x2c357225202c3770\n"
".quad 0x2e0a3b3932722520,0x3937203220636f6c,0x2e707465730a3120,0x25203233732e746c\n"
".quad 0x2c357225202c3870,0x6e610a3b37722520,0x2520646572702e64,0x2c387025202c3970\n"
".quad 0x64610a3b37702520,0x7225203233732e64,0x39327225202c3032,0x65730a3b312d202c\n"
".quad 0x25203233622e706c,0x327225202c313272,0x202c357225202c30,0x6c65730a3b397025\n"
".quad 0x7225203233622e70,0x39317225202c3232,0x347025202c30202c,0x33752e766f6d0a3b\n"
".quad 0x202c333272252032,0x2e706c65730a3b30,0x3432722520323362,0x202c31327225202c\n"
".quad 0x0a3b387025202c30,0x38203220636f6c2e,0x2e64616d0a312033,0x25203233732e6f6c\n"
".quad 0x327225202c373172,0x2c39327225202c32,0x0a0a3b3432722520,0x2e64312e78657409\n"
".quad 0x732e3233662e3476,0x2c3166257b203233,0x6625202c32662520,0x2c7d346625202c33\n"
".quad 0x6f6c467865745b20,0x3172257b202c7461,0x6c090a0a3b5d7d37,0x2e6d617261702e64\n"
".quad 0x3732722520323375,0x7037325a5f5b202c,0x6c43617461446461,0x726f426f54706d61\n"
".quad 0x6e72656b5f726564,0x69695f5366506c65,0x705f696969696969,0x3b5d335f6d617261\n"
".quad 0x203220636f6c2e0a,0x64616d0a31203338,0x203233732e6f6c2e,0x7225202c35327225\n"
".quad 0x2c37327225202c34,0x756d0a3b35722520,0x732e656469772e6c,0x2c336c7225203233\n"
".quad 0x34202c3532722520,0x36732e6464610a3b,0x202c346c72252034,0x7225202c316c7225\n"
".quad 0x672e74730a3b336c,0x33662e6c61626f6c,0x5d346c72255b2032,0x2e0a3b316625202c\n"
".quad 0x3538203220636f6c,0x0a3b7465720a3220,0x72746e652e0a0a7d,0x6f6d37325a5f2079\n"
".quad 0x6e416574616c7564,0x696c616d726f4e64,0x656e72656b5f657a,0x74616f6c6636506c\n"
".quad 0x0a2866695f305332,0x2e206d617261702e,0x37325a5f20343675,0x6574616c75646f6d\n"
".quad 0x616d726f4e646e41,0x72656b5f657a696c,0x6f6c6636506c656e,0x66695f3053327461\n"
".quad 0x305f6d617261705f,0x6d617261702e0a2c,0x5a5f203436752e20,0x616c75646f6d3732\n"
".quad 0x726f4e646e416574,0x6b5f657a696c616d,0x6636506c656e7265,0x5f30533274616f6c\n"
".quad 0x6d617261705f6669,0x7261702e0a2c315f,0x203233752e206d61,0x75646f6d37325a5f\n"
".quad 0x4e646e416574616c,0x657a696c616d726f,0x506c656e72656b5f,0x533274616f6c6636\n"
".quad 0x7261705f66695f30,0x702e0a2c325f6d61,0x33662e206d617261,0x6f6d37325a5f2032\n"
".quad 0x6e416574616c7564,0x696c616d726f4e64,0x656e72656b5f657a,0x74616f6c6636506c\n"
".quad 0x705f66695f305332,0x290a335f6d617261,0x206765722e0a7b0a,0x3c6625203233662e\n"
".quad 0x65722e0a3b3e3432,0x20646572702e2067,0x2e0a3b3e323c7025,0x3233732e20676572\n"
".quad 0x0a3b3e393c722520,0x36732e206765722e,0x3e383c6c72252034,0x702e646c0a0a0a3b\n"
".quad 0x3436752e6d617261,0x5b202c336c722520,0x75646f6d37325a5f,0x4e646e416574616c\n"
".quad 0x657a696c616d726f,0x506c656e72656b5f,0x533274616f6c6636,0x7261705f66695f30\n"
".quad 0x6c0a3b5d305f6d61,0x2e6d617261702e64,0x346c722520343675,0x6d37325a5f5b202c\n"
".quad 0x416574616c75646f,0x6c616d726f4e646e,0x6e72656b5f657a69,0x616f6c6636506c65\n"
".quad 0x5f66695f30533274,0x5d315f6d61726170,0x7261702e646c0a3b,0x25203233752e6d61\n"
".quad 0x325a5f5b202c3272,0x74616c75646f6d37,0x6d726f4e646e4165,0x656b5f657a696c61\n"
".quad 0x6c6636506c656e72,0x695f30533274616f,0x5f6d617261705f66,0x617476630a3b5d32\n"
".quad 0x626f6c672e6f742e,0x25203436752e6c61,0x6c7225202c316c72,0x2e617476630a3b33\n"
".quad 0x61626f6c672e6f74,0x7225203436752e6c,0x346c7225202c326c,0x3220636f6c2e0a3b\n"
".quad 0x6d0a312034303120,0x25203233752e766f,0x61746325202c3372,0x6f6d0a3b782e6469\n"
".quad 0x7225203233752e76,0x6469746e25202c34,0x2e766f6d0a3b782e,0x2c35722520323375\n"
".quad 0x3b782e6469742520,0x2e6f6c2e64616d0a,0x2c31722520323373,0x7225202c33722520\n"
".quad 0x0a3b357225202c34,0x31203220636f6c2e,0x7465730a31203530,0x3233732e746c2e70\n"
".quad 0x7225202c31702520,0x0a3b327225202c31,0x6172622031702540,0x0a3b325f32424220\n"
".quad 0x203220636f6c2e0a,0x65720a3220343131,0x5f3242420a0a3b74,0x20636f6c2e0a3a32\n"
".quad 0x0a31203830312032,0x656469772e6c756d,0x6c7225203233732e,0x202c317225202c35\n"
".quad 0x732e6464610a3b38,0x2c366c7225203436,0x25202c326c722520,0x6f6c2e0a3b356c72\n"
".quad 0x2039303120322063,0x36732e6464610a31,0x202c376c72252034,0x7225202c316c7225\n"
".quad 0x672e646c0a3b356c,0x32762e6c61626f6c,0x66257b203233662e,0x34316625202c3331\n"
".quad 0x376c72255b202c7d,0x20636f6c2e0a3b5d,0x0a31203830312032,0x61626f6c672e646c\n"
".quad 0x3233662e32762e6c,0x202c353166257b20,0x5b202c7d36316625,0x2e0a3b5d366c7225\n"
".quad 0x3131203220636f6c,0x2e6c756d0a312031,0x2c34662520323366,0x25202c3531662520\n"
".quad 0x67656e0a3b333166,0x376625203233662e,0x0a3b36316625202c,0x662e6e722e616d66\n"
".quad 0x202c386625203233,0x316625202c376625,0x0a3b346625202c34,0x6d617261702e646c\n"
".quad 0x326625203233662e,0x37325a5f5b202c33,0x6574616c75646f6d,0x616d726f4e646e41\n"
".quad 0x72656b5f657a696c,0x6f6c6636506c656e,0x66695f3053327461,0x335f6d617261705f\n"
".quad 0x20636f6c2e0a3b5d,0x0a31203131312032,0x203233662e6c756d,0x386625202c396625\n"
".quad 0x0a3b33326625202c,0x203233662e6c756d,0x6625202c30316625,0x34316625202c3531\n"
".quad 0x6e722e616d660a3b,0x316625203233662e,0x2c36316625202c31,0x25202c3331662520\n"
".quad 0x6c756d0a3b303166,0x316625203233662e,0x2c31316625202c32,0x2e0a3b3332662520\n"
".quad 0x3131203220636f6c,0x672e74730a312033,0x32762e6c61626f6c,0x72255b203233662e\n"
".quad 0x66257b202c5d376c,0x7d32316625202c39,0x3220636f6c2e0a3b,0x720a322034313120\n"
".quad 0x2e0a0a7d0a3b7465,0x5a5f207972746e65,0x74736f5070733232,0x32737365636f7270\n"
".quad 0x6c656e72656b5f44,0x3274616f6c663650,0x666a6a6a6a5f3053,0x6d617261702e0a28\n"
".quad 0x5a5f203436752e20,0x74736f5070733232,0x32737365636f7270,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x666a6a6a6a5f3053,0x305f6d617261705f,0x6d617261702e0a2c\n"
".quad 0x5a5f203436752e20,0x74736f5070733232,0x32737365636f7270,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x666a6a6a6a5f3053,0x315f6d617261705f,0x6d617261702e0a2c\n"
".quad 0x5a5f203233752e20,0x74736f5070733232,0x32737365636f7270,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x666a6a6a6a5f3053,0x325f6d617261705f,0x6d617261702e0a2c\n"
".quad 0x5a5f203233752e20,0x74736f5070733232,0x32737365636f7270,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x666a6a6a6a5f3053,0x335f6d617261705f,0x6d617261702e0a2c\n"
".quad 0x5a5f203233752e20,0x74736f5070733232,0x32737365636f7270,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x666a6a6a6a5f3053,0x345f6d617261705f,0x6d617261702e0a2c\n"
".quad 0x5a5f203233752e20,0x74736f5070733232,0x32737365636f7270,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x666a6a6a6a5f3053,0x355f6d617261705f,0x6d617261702e0a2c\n"
".quad 0x5a5f203233662e20,0x74736f5070733232,0x32737365636f7270,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x666a6a6a6a5f3053,0x365f6d617261705f,0x65722e0a7b0a290a\n"
".quad 0x25203233662e2067,0x2e0a3b3e36383c66,0x6572702e20676572,0x3b3e353c70252064\n"
".quad 0x732e206765722e0a,0x39353c7225203233,0x206765722e0a3b3e,0x6c7225203436732e\n"
".quad 0x0a0a0a3b3e31313c,0x6d617261702e646c,0x6c7225203436752e,0x32325a5f5b202c32\n"
".quad 0x727074736f507073,0x5f4432737365636f,0x36506c656e72656b,0x30533274616f6c66\n"
".quad 0x705f666a6a6a6a5f,0x3b5d305f6d617261,0x617261702e646c0a,0x7225203233752e6d\n"
".quad 0x325a5f5b202c3131,0x7074736f50707332,0x4432737365636f72,0x506c656e72656b5f\n"
".quad 0x533274616f6c6636,0x5f666a6a6a6a5f30,0x5d345f6d61726170,0x742e617476630a3b\n"
".quad 0x6c61626f6c672e6f,0x6c7225203436752e,0x3b326c7225202c31,0x203220636f6c2e0a\n"
".quad 0x6f6d0a3120343032,0x7225203233752e76,0x69746e25202c3231,0x766f6d0a3b782e64\n"
".quad 0x317225203233752e,0x6961746325202c33,0x766f6d0a3b782e64,0x317225203233752e\n"
".quad 0x2e64697425202c34,0x6c2e64616d0a3b78,0x7225203233732e6f,0x2c32317225202c34\n"
".quad 0x25202c3331722520,0x6f6c2e0a3b343172,0x2035303220322063,0x672e707465730a31\n"
".quad 0x7025203233752e65,0x202c347225202c31,0x25400a3b31317225,0x4220617262203170\n"
".quad 0x6c0a0a3b325f3342,0x2e6d617261702e64,0x3735722520323375,0x7332325a5f5b202c\n"
".quad 0x6f727074736f5070,0x6b5f443273736563,0x6636506c656e7265,0x5f30533274616f6c\n"
".quad 0x61705f666a6a6a6a,0x0a3b5d335f6d6172,0x203233752e726873,0x357225202c357225\n"
".quad 0x64610a3b31202c37,0x7225203233732e64,0x2c357225202c3731,0x6f6c2e0a3b312d20\n"
".quad 0x2039303220322063,0x33622e646e610a31,0x202c383172252032,0x317225202c347225\n"
".quad 0x20636f6c2e0a3b37,0x3320323034332033,0x3233732e67656e0a,0x25202c3931722520\n"
".quad 0x2e766f6d0a3b3572,0x3032722520323375,0x6f6c2e0a3b30202c,0x3230343320332063\n"
".quad 0x622e646e610a3320,0x2c31327225203233,0x7225202c35722520,0x636f6c2e0a3b3931\n"
".quad 0x3520353431203420,0x3233622e7a6c630a,0x25202c3232722520,0x766f6d0a3b313272\n"
".quad 0x327225203233752e,0x730a3b3133202c33,0x25203233732e6275,0x327225202c343272\n"
".quad 0x3b32327225202c33,0x203220636f6c2e0a,0x68730a3120393032,0x7225203233752e72\n"
".quad 0x2c347225202c3532,0x6c0a3b3432722520,0x2e6d617261702e64,0x3635722520323375\n"
".quad 0x7332325a5f5b202c,0x6f727074736f5070,0x6b5f443273736563,0x6636506c656e7265\n"
".quad 0x5f30533274616f6c,0x61705f666a6a6a6a,0x0a3b5d325f6d6172,0x203233732e646461\n"
".quad 0x7225202c36327225,0x0a3b312d202c3635,0x32203220636f6c2e,0x646e610a31203031\n"
".quad 0x327225203233622e,0x2c35327225202c37,0x2e0a3b3632722520,0x3433203320636f6c\n"
".quad 0x67656e0a33203230,0x327225203233732e,0x3b36357225202c38,0x3233622e646e610a\n"
".quad 0x25202c3932722520,0x327225202c363572,0x20636f6c2e0a3b38,0x0a35203534312034\n"
".quad 0x203233622e7a6c63,0x7225202c30337225,0x2e6275730a3b3932,0x3133722520323373\n"
".quad 0x202c33327225202c,0x6c2e0a3b30337225,0x303132203220636f,0x752e7268730a3120\n"
".quad 0x2c32337225203233,0x25202c3532722520,0x2e646c0a3b313372,0x33752e6d61726170\n"
".quad 0x202c383572252032,0x50707332325a5f5b,0x65636f727074736f,0x72656b5f44327373\n"
".quad 0x6f6c6636506c656e,0x6a6a5f3053327461,0x617261705f666a6a,0x6c2e0a3b5d355f6d\n"
".quad 0x333132203220636f,0x732e6464610a3120,0x2c33337225203233,0x25202c3835722520\n"
".quad 0x6c756d0a3b373572,0x203233732e6f6c2e,0x7225202c34337225,0x36357225202c3333\n"
".quad 0x6f6c2e6c756d0a3b,0x367225203233732e,0x202c34337225202c,0x616d0a3b32337225\n"
".quad 0x3233732e6f6c2e64,0x25202c3533722520,0x357225202c323372,0x3b37327225202c36\n"
".quad 0x2e6f6c2e6c756d0a,0x2c37722520323373,0x25202c3533722520,0x6f6c2e0a3b373572\n"
".quad 0x2037313220322063,0x6f6c2e64616d0a31,0x317225203233732e,0x2c35337225202c35\n"
".quad 0x25202c3735722520,0x6f6c2e0a3b383172,0x2038313220322063,0x652e707465730a31\n"
".quad 0x7025203233732e71,0x2c37327225202c32,0x2e6275730a3b3020,0x3633722520323373\n"
".quad 0x202c36357225202c,0x65730a3b37327225,0x25203233622e706c,0x327225202c373372\n"
".quad 0x2c36337225202c37,0x616d0a3b32702520,0x3233732e6f6c2e64,0x25202c3833722520\n"
".quad 0x357225202c323372,0x3b37337225202c36,0x2e6f6c2e6c756d0a,0x2c38722520323373\n"
".quad 0x25202c3833722520,0x6f6c2e0a3b373572,0x2038313220322063,0x652e707465730a31\n"
".quad 0x7025203233732e71,0x2c38317225202c33,0x2e6275730a3b3020,0x3933722520323373\n"
".quad 0x202c37357225202c,0x65730a3b38317225,0x25203233622e706c,0x317225202c303472\n"
".quad 0x2c39337225202c38,0x6c2e0a3b33702520,0x383132203220636f,0x6c2e64616d0a3120\n"
".quad 0x7225203233732e6f,0x38337225202c3631,0x202c37357225202c,0x6c2e0a3b30347225\n"
".quad 0x393132203220636f,0x6c2e6c756d0a3120,0x7225203233732e6f,0x2c37327225202c39\n"
".quad 0x6d0a3b3333722520,0x33732e6f6c2e6461,0x202c313472252032,0x7225202c37327225\n"
".quad 0x38317225202c3333,0x6f6c2e64616d0a3b,0x347225203233732e,0x2c34337225202c32\n"
".quad 0x25202c3233722520,0x6f6c2e0a3b313472,0x2030323220322063,0x6f6c2e6c756d0a31\n"
".quad 0x317225203233732e,0x2c37337225202c30,0x6d0a3b3333722520,0x33732e6f6c2e6461\n"
".quad 0x202c333472252032,0x7225202c34337225,0x39337225202c3233,0x3220636f6c2e0a3b\n"
".quad 0x6d0a312030323220,0x33732e6f6c2e6461,0x202c343472252032,0x7225202c37337225\n"
".quad 0x33347225202c3333,0x2e786574090a0a3b,0x33662e34762e6431,0x257b203233732e32\n"
".quad 0x2c336625202c3266,0x6625202c34662520,0x7865745b202c7d35,0x4178656c706d6f43\n"
".quad 0x7d353172257b202c,0x74090a090a0a3b5d,0x34762e64312e7865,0x3233732e3233662e\n"
".quad 0x25202c3666257b20,0x2c386625202c3766,0x5b202c7d39662520,0x6c706d6f43786574\n"
".quad 0x72257b202c417865,0x090a0a3b5d7d3631,0x32203220636f6c2e,0x7476630a31203632\n"
".quad 0x2e3233662e6e722e,0x3031662520323375,0x0a3b38317225202c,0x6d617261702e646c\n"
".quad 0x386625203233662e,0x32325a5f5b202c35,0x727074736f507073,0x5f4432737365636f\n"
".quad 0x36506c656e72656b,0x30533274616f6c66,0x705f666a6a6a6a5f,0x3b5d365f6d617261\n"
".quad 0x203220636f6c2e0a,0x756d0a3120363232,0x6625203233662e6c,0x30316625202c3131\n"
".quad 0x0a3b35386625202c,0x35203420636f6c2e,0x6e69730a35203036,0x2e786f727070612e\n"
".quad 0x3231662520323366,0x0a3b31316625202c,0x35203420636f6c2e,0x736f630a35203237\n"
".quad 0x2e786f727070612e,0x3331662520323366,0x0a3b31316625202c,0x32203220636f6c2e\n"
".quad 0x6464610a31203732,0x316625203233662e,0x202c326625202c34,0x766f6d0a3b366625\n"
".quad 0x316625203233662e,0x3046336630202c35,0x2e0a3b3030303030,0x3232203220636f6c\n"
".quad 0x2e6275730a312037,0x3631662520323366,0x25202c336625202c,0x2e6464610a3b3766\n"
".quad 0x3731662520323366,0x25202c336625202c,0x2e6c756d0a3b3766,0x3831662520323366\n"
".quad 0x202c37316625202c,0x3030303046336630,0x2e6275730a3b3030,0x3931662520323366\n"
".quad 0x25202c326625202c,0x2e6c756d0a3b3666,0x3032662520323366,0x202c39316625202c\n"
".quad 0x3030303046336630,0x2e6c756d0a3b3030,0x3132662520323366,0x202c30326625202c\n"
".quad 0x6d660a3b32316625,0x3233662e6e722e61,0x25202c3232662520,0x316625202c383166\n"
".quad 0x3b31326625202c33,0x2e6e722e616d660a,0x3332662520323366,0x202c34316625202c\n"
".quad 0x3030303046336630,0x32326625202c3030,0x33662e6c756d0a3b,0x202c343266252032\n"
".quad 0x6625202c38316625,0x2e67656e0a3b3231,0x3532662520323366,0x0a3b30326625202c\n"
".quad 0x662e6e722e616d66,0x2c36326625203233,0x25202c3532662520,0x326625202c333166\n"
".quad 0x722e616d660a3b34,0x6625203233662e6e,0x36316625202c3732,0x303046336630202c\n"
".quad 0x6625202c30303030,0x2e67656e0a3b3632,0x3832662520323366,0x0a3b32326625202c\n"
".quad 0x662e6e722e616d66,0x2c39326625203233,0x25202c3431662520,0x326625202c353166\n"
".quad 0x662e67656e0a3b38,0x2c30336625203233,0x660a3b3631662520,0x33662e6e722e616d\n"
".quad 0x202c313366252032,0x6625202c30336625,0x36326625202c3531,0x3220636f6c2e0a3b\n"
".quad 0x6d0a312039323220,0x2e656469772e6c75,0x336c722520323375,0x202c32347225202c\n"
".quad 0x732e6464610a3b38,0x2c346c7225203436,0x25202c316c722520,0x2e74730a3b336c72\n"
".quad 0x762e6c61626f6c67,0x255b203233662e32,0x257b202c5d346c72,0x326625202c333266\n"
".quad 0x636f6c2e0a3b7d37,0x3120303332203220,0x6469772e6c756d0a,0x7225203233752e65\n"
".quad 0x34347225202c356c,0x6464610a3b38202c,0x6c7225203436732e,0x2c316c7225202c36\n"
".quad 0x730a3b356c722520,0x6c61626f6c672e74,0x203233662e32762e,0x202c5d366c72255b\n"
".quad 0x25202c393266257b,0x6c2e0a3b7d313366,0x343332203220636f,0x20337025400a3120\n"
".quad 0x5f33424220617262,0x5f3342420a0a3b33,0x20636f6c2e0a3a32,0x0a32203035322032\n"
".quad 0x42420a0a3b746572,0x6f6c2e0a3a335f33,0x2037333220322063,0x33732e6464610a31\n"
".quad 0x202c393472252032,0x357225202c397225,0x33732e6464610a3b,0x202c303572252032\n"
".quad 0x7225202c39347225,0x20636f6c2e0a3b36,0x0a31203833322032,0x203233732e646461\n"
".quad 0x7225202c31357225,0x0a3b357225202c36,0x203233732e646461,0x7225202c32357225\n"
".quad 0x30317225202c3135,0x3220636f6c2e0a3b,0x610a312035333220,0x25203233732e6464\n"
".quad 0x377225202c373472,0x0a0a3b357225202c,0x2e64312e78657409,0x732e3233662e3476\n"
".quad 0x323366257b203233,0x202c33336625202c,0x6625202c34336625,0x65745b202c7d3533\n"
".quad 0x78656c706d6f4378,0x373472257b202c41,0x6c2e090a0a3b5d7d,0x363332203220636f\n"
".quad 0x732e6464610a3120,0x2c38347225203233,0x7225202c38722520,0x786574090a0a3b35\n"
".quad 0x662e34762e64312e,0x7b203233732e3233,0x6625202c36336625,0x38336625202c3733\n"
".quad 0x2c7d39336625202c,0x6d6f437865745b20,0x7b202c4178656c70,0x0a3b5d7d38347225\n"
".quad 0x3220636f6c2e090a,0x610a312035343220,0x25203233662e6464,0x336625202c303466\n"
".quad 0x3b36336625202c32,0x3233662e6275730a,0x25202c3234662520,0x336625202c333366\n"
".quad 0x662e6464610a3b37,0x2c33346625203233,0x25202c3333662520,0x6c756d0a3b373366\n"
".quad 0x346625203233662e,0x2c33346625202c34,0x3030304633663020,0x6275730a3b303030\n"
".quad 0x346625203233662e,0x2c32336625202c35,0x6d0a3b3633662520,0x25203233662e6c75\n"
".quad 0x346625202c363466,0x3046336630202c35,0x6d0a3b3030303030,0x25203233662e766f\n"
".quad 0x306630202c373466,0x3b30303030303030,0x617261702e646c0a,0x6625203233662e6d\n"
".quad 0x325a5f5b202c3438,0x7074736f50707332,0x4432737365636f72,0x506c656e72656b5f\n"
".quad 0x533274616f6c6636,0x5f666a6a6a6a5f30,0x5d365f6d61726170,0x3220636f6c2e0a3b\n"
".quad 0x730a312034343220,0x662e74672e707465,0x202c347025203233,0x6630202c34386625\n"
".quad 0x3030303030303030,0x662e706c65730a3b,0x2c38346625203233,0x3030384633663020\n"
".quad 0x426630202c303030,0x2c30303030303846,0x6c2e0a3b34702520,0x353432203220636f\n"
".quad 0x662e6c756d0a3120,0x2c39346625203233,0x25202c3634662520,0x616d660a3b383466\n"
".quad 0x203233662e6e722e,0x6625202c30356625,0x30306630202c3434,0x202c303030303030\n"
".quad 0x6d660a3b39346625,0x3233662e6e722e61,0x25202c3135662520,0x336630202c303466\n"
".quad 0x2c30303030303046,0x6d0a3b3035662520,0x25203233662e6c75,0x346625202c323566\n"
".quad 0x3b38346625202c34,0x3233662e67656e0a,0x25202c3335662520,0x616d660a3b363466\n"
".quad 0x203233662e6e722e,0x6625202c34356625,0x37346625202c3335,0x0a3b32356625202c\n"
".quad 0x662e6e722e616d66,0x2c35356625203233,0x30202c3234662520,0x3030303030463366\n"
".quad 0x3b34356625202c30,0x3233662e67656e0a,0x25202c3635662520,0x616d660a3b303566\n"
".quad 0x203233662e6e722e,0x6625202c37356625,0x35316625202c3034,0x0a3b36356625202c\n"
".quad 0x203233662e67656e,0x6625202c38356625,0x2e616d660a3b3234,0x25203233662e6e72\n"
".quad 0x356625202c393566,0x2c35316625202c38,0x2e0a3b3435662520,0x3432203220636f6c\n"
".quad 0x2e6c756d0a312037,0x3233752e65646977,0x25202c376c722520,0x0a3b38202c303572\n"
".quad 0x203436732e646461,0x7225202c386c7225,0x376c7225202c316c,0x6f6c672e74730a3b\n"
".quad 0x662e32762e6c6162,0x386c72255b203233,0x313566257b202c5d,0x3b7d35356625202c\n"
".quad 0x203220636f6c2e0a,0x756d0a3120383432,0x752e656469772e6c,0x2c396c7225203233\n"
".quad 0x38202c3235722520,0x36732e6464610a3b,0x2c30316c72252034,0x25202c316c722520\n"
".quad 0x2e74730a3b396c72,0x762e6c61626f6c67,0x255b203233662e32,0x7b202c5d30316c72\n"
".quad 0x6625202c37356625,0x6f6c2e0a3b7d3935,0x2030353220322063,0x7d0a3b7465720a32\n"
".quad 0x7972746e652e0a0a,0x50707331325a5f20,0x7365636f72706572,0x6e72656b5f443273\n"
".quad 0x616f6c6636506c65,0x6a6a6a5f30533274,0x7261702e0a28666a,0x203436752e206d61\n"
".quad 0x7250707331325a5f,0x737365636f727065,0x656e72656b5f4432,0x74616f6c6636506c\n"
".quad 0x6a6a6a6a5f305332,0x5f6d617261705f66,0x617261702e0a2c30,0x5f203436752e206d\n"
".quad 0x657250707331325a,0x32737365636f7270,0x6c656e72656b5f44,0x3274616f6c663650\n"
".quad 0x666a6a6a6a5f3053,0x315f6d617261705f,0x6d617261702e0a2c,0x5a5f203233752e20\n"
".quad 0x7065725070733132,0x4432737365636f72,0x506c656e72656b5f,0x533274616f6c6636\n"
".quad 0x5f666a6a6a6a5f30,0x2c325f6d61726170,0x206d617261702e0a,0x325a5f203233752e\n"
".quad 0x7270657250707331,0x5f4432737365636f,0x36506c656e72656b,0x30533274616f6c66\n"
".quad 0x705f666a6a6a6a5f,0x0a2c335f6d617261,0x2e206d617261702e,0x31325a5f20323375\n"
".quad 0x6f72706572507073,0x6b5f443273736563,0x6636506c656e7265,0x5f30533274616f6c\n"
".quad 0x61705f666a6a6a6a,0x2e0a2c345f6d6172,0x752e206d61726170,0x7331325a5f203233\n"
".quad 0x636f727065725070,0x656b5f4432737365,0x6c6636506c656e72,0x6a5f30533274616f\n"
".quad 0x7261705f666a6a6a,0x702e0a2c355f6d61,0x33662e206d617261,0x707331325a5f2032\n"
".quad 0x65636f7270657250,0x72656b5f44327373,0x6f6c6636506c656e,0x6a6a5f3053327461\n"
".quad 0x617261705f666a6a,0x0a7b0a290a365f6d,0x33662e206765722e,0x3e35373c66252032\n"
".quad 0x2e206765722e0a3b,0x3c70252064657270,0x6765722e0a3b3e37,0x7225203233732e20\n"
".quad 0x722e0a3b3e32363c,0x203436732e206765,0x3b3e31313c6c7225,0x61702e646c0a0a0a\n"
".quad 0x203436752e6d6172,0x5f5b202c326c7225,0x657250707331325a,0x32737365636f7270\n"
".quad 0x6c656e72656b5f44,0x3274616f6c663650,0x666a6a6a6a5f3053,0x305f6d617261705f\n"
".quad 0x61702e646c0a3b5d,0x203233752e6d6172,0x5f5b202c34317225,0x657250707331325a\n"
".quad 0x32737365636f7270,0x6c656e72656b5f44,0x3274616f6c663650,0x666a6a6a6a5f3053\n"
".quad 0x345f6d617261705f,0x2e617476630a3b5d,0x61626f6c672e6f74,0x7225203436752e6c\n"
".quad 0x326c7225202c316c,0x3220636f6c2e0a3b,0x6d0a312031363220,0x25203233752e766f\n"
".quad 0x746e25202c353172,0x6f6d0a3b782e6469,0x7225203233752e76,0x61746325202c3631\n"
".quad 0x6f6d0a3b782e6469,0x7225203233752e76,0x64697425202c3731,0x2e64616d0a3b782e\n"
".quad 0x25203233732e6f6c,0x35317225202c3472,0x202c36317225202c,0x6c2e0a3b37317225\n"
".quad 0x323632203220636f,0x2e707465730a3120,0x25203233752e6567,0x2c347225202c3270\n"
".quad 0x400a3b3431722520,0x2061726220327025,0x0a0a3b345f344242,0x6d617261702e646c\n"
".quad 0x367225203233752e,0x31325a5f5b202c30,0x6f72706572507073,0x6b5f443273736563\n"
".quad 0x6636506c656e7265,0x5f30533274616f6c,0x61705f666a6a6a6a,0x0a3b5d335f6d6172\n"
".quad 0x203233752e726873,0x367225202c357225,0x64610a3b31202c30,0x7225203233732e64\n"
".quad 0x2c357225202c3831,0x6f6c2e0a3b312d20,0x2036363220322063,0x33622e646e610a31\n"
".quad 0x25202c3672252032,0x38317225202c3472,0x3320636f6c2e0a3b,0x0a33203230343320\n"
".quad 0x203233732e67656e,0x7225202c39317225,0x622e646e610a3b35,0x2c30327225203233\n"
".quad 0x7225202c35722520,0x636f6c2e0a3b3931,0x3520353431203420,0x3233622e7a6c630a\n"
".quad 0x25202c3132722520,0x766f6d0a3b303272,0x327225203233752e,0x730a3b3133202c32\n"
".quad 0x25203233732e6275,0x327225202c333272,0x3b31327225202c32,0x203220636f6c2e0a\n"
".quad 0x68730a3120363632,0x7225203233752e72,0x2c347225202c3432,0x6c0a3b3332722520\n"
".quad 0x2e6d617261702e64,0x3835722520323375,0x7331325a5f5b202c,0x636f727065725070\n"
".quad 0x656b5f4432737365,0x6c6636506c656e72,0x6a5f30533274616f,0x7261705f666a6a6a\n"
".quad 0x610a3b5d325f6d61,0x25203233732e6464,0x357225202c353272,0x2e0a3b312d202c38\n"
".quad 0x3632203220636f6c,0x2e646e610a312037,0x2c37722520323362,0x25202c3432722520\n"
".quad 0x6f6c2e0a3b353272,0x3230343320332063,0x732e67656e0a3320,0x2c36327225203233\n"
".quad 0x610a3b3835722520,0x25203233622e646e,0x357225202c373272,0x3b36327225202c38\n"
".quad 0x203420636f6c2e0a,0x6c630a3520353431,0x7225203233622e7a,0x37327225202c3832\n"
".quad 0x33732e6275730a3b,0x202c393272252032,0x7225202c32327225,0x636f6c2e0a3b3832\n"
".quad 0x3120373632203220,0x3233752e7268730a,0x7225202c38722520,0x39327225202c3432\n"
".quad 0x3220636f6c2e0a3b,0x730a312030373220,0x732e71652e707465,0x202c317025203233\n"
".quad 0x0a3b30202c367225,0x203233752e726873,0x7225202c30337225,0x2e0a3b31202c3835\n"
".quad 0x3732203220636f6c,0x707465730a312030,0x203233752e74672e,0x377225202c337025\n"
".quad 0x0a3b30337225202c,0x646572702e646e61,0x7025202c34702520,0x0a3b337025202c31\n"
".quad 0x32203220636f6c2e,0x7025400a31203037,0x4242206172622034,0x646c0a0a3b345f34\n"
".quad 0x752e6d617261702e,0x2c39357225203233,0x707331325a5f5b20,0x65636f7270657250\n"
".quad 0x72656b5f44327373,0x6f6c6636506c656e,0x6a6a5f3053327461,0x617261705f666a6a\n"
".quad 0x646c0a3b5d335f6d,0x752e6d617261702e,0x2c31367225203233,0x707331325a5f5b20\n"
".quad 0x65636f7270657250,0x72656b5f44327373,0x6f6c6636506c656e,0x6a6a5f3053327461\n"
".quad 0x617261705f666a6a,0x6c2e0a3b5d355f6d,0x333732203220636f,0x732e6464610a3120\n"
".quad 0x2c33337225203233,0x25202c3136722520,0x2e646c0a3b393572,0x33752e6d61726170\n"
".quad 0x202c373572252032,0x50707331325a5f5b,0x7365636f72706572,0x6e72656b5f443273\n"
".quad 0x616f6c6636506c65,0x6a6a6a5f30533274,0x6d617261705f666a,0x6f6c2e0a3b5d325f\n"
".quad 0x2033373220322063,0x6f6c2e6c756d0a31,0x337225203233732e,0x2c33337225202c34\n"
".quad 0x6d0a3b3735722520,0x33732e6f6c2e6c75,0x25202c3972252032,0x387225202c343372\n"
".quad 0x3220636f6c2e0a3b,0x6d0a312038373220,0x33732e6f6c2e6c75,0x202c303172252032\n"
".quad 0x337225202c377225,0x6c2e64616d0a3b33,0x7225203233732e6f,0x2c377225202c3533\n"
".quad 0x25202c3333722520,0x2e64616d0a3b3672,0x25203233732e6f6c,0x337225202c313372\n"
".quad 0x202c387225202c34,0x6c2e0a3b35337225,0x393732203220636f,0x732e6275730a3120\n"
".quad 0x2c36337225203233,0x25202c3735722520,0x707465730a3b3772,0x203233732e71652e\n"
".quad 0x377225202c357025,0x766f6d0a3b30202c,0x337225203233752e,0x65730a3b30202c37\n"
".quad 0x25203233622e706c,0x377225202c383372,0x202c36337225202c,0x6f6c2e0a3b357025\n"
".quad 0x2039373220322063,0x6f6c2e6c756d0a31,0x317225203233732e,0x2c38337225202c31\n"
".quad 0x730a3b3333722520,0x25203233732e6275,0x357225202c393372,0x0a3b367225202c39\n"
".quad 0x732e6f6c2e64616d,0x2c30347225203233,0x25202c3433722520,0x39337225202c3872\n"
".quad 0x3220636f6c2e0a3b,0x6d0a312039373220,0x33732e6f6c2e6461,0x202c323372252032\n"
".quad 0x7225202c38337225,0x30347225202c3333,0x6f6c2e64616d0a3b,0x347225203233732e\n"
".quad 0x202c387225202c31,0x7225202c37357225,0x6c2e6c756d0a3b37,0x7225203233732e6f\n"
".quad 0x31347225202c3231,0x0a3b39357225202c,0x32203220636f6c2e,0x64616d0a31203038\n"
".quad 0x203233732e6f6c2e,0x7225202c32347225,0x39357225202c3134,0x6d0a3b367225202c\n"
".quad 0x33732e6f6c2e6461,0x202c333472252032,0x357225202c387225,0x3b38337225202c37\n"
".quad 0x2e6f6c2e6c756d0a,0x3331722520323373,0x202c33347225202c,0x65730a3b39357225\n"
".quad 0x25203233622e706c,0x367225202c343472,0x202c39337225202c,0x6f6c2e0a3b317025\n"
".quad 0x2031383220322063,0x6f6c2e64616d0a31,0x347225203233732e,0x2c33347225202c35\n"
".quad 0x25202c3935722520,0x74090a0a3b343472,0x34762e64312e7865,0x3233732e3233662e\n"
".quad 0x25202c3266257b20,0x2c346625202c3366,0x5b202c7d35662520,0x6c706d6f43786574\n"
".quad 0x72257b202c417865,0x090a0a3b5d7d3133,0x64312e786574090a,0x2e3233662e34762e\n"
".quad 0x3666257b20323373,0x25202c376625202c,0x7d396625202c3866,0x6f437865745b202c\n"
".quad 0x202c4178656c706d,0x3b5d7d323372257b,0x20636f6c2e090a0a,0x0a31203738322032\n"
".quad 0x662e6e722e747663,0x25203233752e3233,0x367225202c303166,0x7261702e646c0a3b\n"
".quad 0x25203233662e6d61,0x5a5f5b202c343766,0x7065725070733132,0x4432737365636f72\n"
".quad 0x506c656e72656b5f,0x533274616f6c6636,0x5f666a6a6a6a5f30,0x5d365f6d61726170\n"
".quad 0x3220636f6c2e0a3b,0x6d0a312037383220,0x25203233662e6c75,0x316625202c313166\n"
".quad 0x3b34376625202c30,0x203420636f6c2e0a,0x69730a3520303635,0x786f727070612e6e\n"
".quad 0x316625203233662e,0x3b31316625202c32,0x203420636f6c2e0a,0x6f630a3520323735\n"
".quad 0x786f727070612e73,0x316625203233662e,0x3b31316625202c33,0x203220636f6c2e0a\n"
".quad 0x64610a3120383832,0x6625203233662e64,0x2c326625202c3431,0x75730a3b36662520\n"
".quad 0x6625203233662e62,0x2c336625202c3531,0x64610a3b37662520,0x6625203233662e64\n"
".quad 0x2c336625202c3631,0x75730a3b37662520,0x6625203233662e62,0x2c326625202c3731\n"
".quad 0x756d0a3b36662520,0x6625203233662e6c,0x36316625202c3831,0x0a3b33316625202c\n"
".quad 0x203233662e67656e,0x6625202c39316625,0x2e616d660a3b3731,0x25203233662e6e72\n"
".quad 0x316625202c303266,0x2c32316625202c39,0x730a3b3831662520,0x25203233662e6275\n"
".quad 0x316625202c313266,0x3b30326625202c34,0x3233662e6c756d0a,0x25202c3232662520\n"
".quad 0x316625202c363166,0x722e616d660a3b32,0x6625203233662e6e,0x37316625202c3332\n"
".quad 0x202c33316625202c,0x64610a3b32326625,0x6625203233662e64,0x33326625202c3432\n"
".quad 0x0a3b35316625202c,0x203233662e646461,0x6625202c35326625,0x30326625202c3431\n"
".quad 0x33662e6275730a3b,0x202c363266252032,0x6625202c33326625,0x636f6c2e0a3b3531\n"
".quad 0x3120303932203220,0x6469772e6c756d0a,0x7225203233752e65,0x32347225202c336c\n"
".quad 0x6464610a3b38202c,0x6c7225203436732e,0x2c316c7225202c34,0x730a3b336c722520\n"
".quad 0x6c61626f6c672e74,0x203233662e32762e,0x202c5d346c72255b,0x25202c313266257b\n"
".quad 0x6c2e0a3b7d343266,0x313932203220636f,0x772e6c756d0a3120,0x203233752e656469\n"
".quad 0x7225202c356c7225,0x610a3b38202c3534,0x25203436732e6464,0x6c7225202c366c72\n"
".quad 0x3b356c7225202c31,0x626f6c672e74730a,0x33662e32762e6c61,0x5d366c72255b2032\n"
".quad 0x2c353266257b202c,0x0a3b7d3632662520,0x32203220636f6c2e,0x2521400a31203539\n"
".quad 0x4220617262203170,0x2e0a0a3b345f3442,0x3932203220636f6c,0x2e6464610a312036\n"
".quad 0x3035722520323373,0x202c30317225202c,0x6464610a3b357225,0x347225203233732e\n"
".quad 0x2c30357225202c38,0x6c2e0a3b39722520,0x373932203220636f,0x732e6464610a3120\n"
".quad 0x2c31357225203233,0x7225202c39722520,0x732e6464610a3b35,0x2c39347225203233\n"
".quad 0x25202c3135722520,0x74090a0a3b313172,0x34762e64312e7865,0x3233732e3233662e\n"
".quad 0x202c373266257b20,0x6625202c38326625,0x30336625202c3932,0x437865745b202c7d\n"
".quad 0x2c4178656c706d6f,0x5d7d383472257b20,0x6574090a090a0a3b,0x2e34762e64312e78\n"
".quad 0x203233732e323366,0x25202c313366257b,0x336625202c323366,0x7d34336625202c33\n"
".quad 0x6f437865745b202c,0x202c4178656c706d,0x3b5d7d393472257b,0x20636f6c2e090a0a\n"
".quad 0x0a31203630332032,0x203233662e646461,0x6625202c35336625,0x31336625202c3732\n"
".quad 0x33662e6275730a3b,0x202c363366252032,0x6625202c38326625,0x2e6464610a3b3233\n"
".quad 0x3733662520323366,0x202c38326625202c,0x75730a3b32336625,0x6625203233662e62\n"
".quad 0x37326625202c3833,0x0a3b31336625202c,0x203233662e6c756d,0x6625202c39336625\n"
".quad 0x30306630202c3733,0x0a3b303030303030,0x6d617261702e646c,0x376625203233662e\n"
".quad 0x31325a5f5b202c33,0x6f72706572507073,0x6b5f443273736563,0x6636506c656e7265\n"
".quad 0x5f30533274616f6c,0x61705f666a6a6a6a,0x0a3b5d365f6d6172,0x33203220636f6c2e\n"
".quad 0x7465730a31203530,0x3233662e74672e70,0x6625202c36702520,0x30306630202c3337\n"
".quad 0x0a3b303030303030,0x3233662e706c6573,0x30202c3034662520,0x3030303038463366\n"
".quad 0x3846426630202c30,0x25202c3030303030,0x636f6c2e0a3b3670,0x3120363033203220\n"
".quad 0x3233662e67656e0a,0x25202c3134662520,0x616d660a3b383366,0x203233662e6e722e\n"
".quad 0x6625202c32346625,0x30346625202c3134,0x0a3b39336625202c,0x203233662e627573\n"
".quad 0x6625202c33346625,0x32346625202c3533,0x33662e6c756d0a3b,0x202c343466252032\n"
".quad 0x6625202c37336625,0x2e616d660a3b3034,0x25203233662e6e72,0x336625202c353466\n"
".quad 0x3030306630202c38,0x25202c3030303030,0x6464610a3b343466,0x346625203233662e\n"
".quad 0x2c35346625202c36,0x610a3b3633662520,0x25203233662e6464,0x336625202c373466\n"
".quad 0x3b32346625202c35,0x3233662e6275730a,0x25202c3834662520,0x336625202c353466\n"
".quad 0x20636f6c2e0a3b36,0x0a31203839322032,0x203233732e646461,0x7225202c33357225\n"
".quad 0x3b357225202c3231,0x203220636f6c2e0a,0x756d0a3120383033,0x752e656469772e6c\n"
".quad 0x2c376c7225203233,0x38202c3335722520,0x36732e6464610a3b,0x202c386c72252034\n"
".quad 0x7225202c316c7225,0x672e74730a3b376c,0x32762e6c61626f6c,0x72255b203233662e\n"
".quad 0x66257b202c5d386c,0x36346625202c3334,0x20636f6c2e0a3b7d,0x0a31203939322032\n"
".quad 0x203233732e646461,0x7225202c35357225,0x3b357225202c3331,0x203220636f6c2e0a\n"
".quad 0x756d0a3120393033,0x752e656469772e6c,0x2c396c7225203233,0x38202c3535722520\n"
".quad 0x36732e6464610a3b,0x2c30316c72252034,0x25202c316c722520,0x2e74730a3b396c72\n"
".quad 0x762e6c61626f6c67,0x255b203233662e32,0x7b202c5d30316c72,0x6625202c37346625\n"
".quad 0x42420a0a3b7d3834,0x6f6c2e0a3a345f34,0x2031313320322063,0x7d0a3b7465720a32\n"
".quad 0x7972746e652e0a0a,0x50707338315a5f20,0x4432737365636f72,0x506c656e72656b5f\n"
".quad 0x533274616f6c6636,0x6a6a6a5f30535f30,0x7261702e0a286666,0x203436752e206d61\n"
".quad 0x7250707338315a5f,0x5f4432737365636f,0x36506c656e72656b,0x30533274616f6c66\n"
".quad 0x666a6a6a5f30535f,0x5f6d617261705f66,0x617261702e0a2c30,0x5f203436752e206d\n"
".quad 0x6f7250707338315a,0x6b5f443273736563,0x6636506c656e7265,0x5f30533274616f6c\n"
".quad 0x66666a6a6a5f3053,0x315f6d617261705f,0x6d617261702e0a2c,0x5a5f203436752e20\n"
".quad 0x636f725070733831,0x656b5f4432737365,0x6c6636506c656e72,0x535f30533274616f\n"
".quad 0x5f66666a6a6a5f30,0x2c325f6d61726170,0x206d617261702e0a,0x315a5f203233752e\n"
".quad 0x65636f7250707338,0x72656b5f44327373,0x6f6c6636506c656e,0x30535f3053327461\n"
".quad 0x705f66666a6a6a5f,0x0a2c335f6d617261,0x2e206d617261702e,0x38315a5f20323375\n"
".quad 0x7365636f72507073,0x6e72656b5f443273,0x616f6c6636506c65,0x5f30535f30533274\n"
".quad 0x61705f66666a6a6a,0x2e0a2c345f6d6172,0x752e206d61726170,0x7338315a5f203233\n"
".quad 0x737365636f725070,0x656e72656b5f4432,0x74616f6c6636506c,0x6a5f30535f305332\n"
".quad 0x7261705f66666a6a,0x702e0a2c355f6d61,0x33662e206d617261,0x707338315a5f2032\n"
".quad 0x32737365636f7250,0x6c656e72656b5f44,0x3274616f6c663650,0x6a6a5f30535f3053\n"
".quad 0x617261705f66666a,0x61702e0a2c365f6d,0x3233662e206d6172,0x50707338315a5f20\n"
".quad 0x4432737365636f72,0x506c656e72656b5f,0x533274616f6c6636,0x6a6a6a5f30535f30\n"
".quad 0x6d617261705f6666,0x2e0a7b0a290a375f,0x3233662e20676572,0x3e3439313c662520\n"
".quad 0x2e206765722e0a3b,0x3c70252064657270,0x6765722e0a3b3e36,0x7225203233732e20\n"
".quad 0x722e0a3b3e32353c,0x203436732e206765,0x3b3e31313c6c7225,0x61702e646c0a0a0a\n"
".quad 0x203436752e6d6172,0x5f5b202c326c7225,0x6f7250707338315a,0x6b5f443273736563\n"
".quad 0x6636506c656e7265,0x5f30533274616f6c,0x66666a6a6a5f3053,0x305f6d617261705f\n"
".quad 0x61702e646c0a3b5d,0x203233752e6d6172,0x5a5f5b202c397225,0x636f725070733831\n"
".quad 0x656b5f4432737365,0x6c6636506c656e72,0x535f30533274616f,0x5f66666a6a6a5f30\n"
".quad 0x5d355f6d61726170,0x742e617476630a3b,0x6c61626f6c672e6f,0x6c7225203436752e\n"
".quad 0x3b326c7225202c31,0x203220636f6c2e0a,0x6f6d0a3120383233,0x7225203233752e76\n"
".quad 0x69746e25202c3031,0x766f6d0a3b782e64,0x317225203233752e,0x6961746325202c31\n"
".quad 0x766f6d0a3b782e64,0x317225203233752e,0x2e64697425202c32,0x6c2e64616d0a3b78\n"
".quad 0x7225203233732e6f,0x2c30317225202c33,0x25202c3131722520,0x6f6c2e0a3b323172\n"
".quad 0x2039323320322063,0x672e707465730a31,0x7025203233752e65,0x202c337225202c32\n"
".quad 0x7025400a3b397225,0x4242206172622032,0x646c0a0a3b345f35,0x752e6d617261702e\n"
".quad 0x2c31357225203233,0x707338315a5f5b20,0x32737365636f7250,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x6a6a5f30535f3053,0x617261705f66666a,0x64610a3b5d345f6d\n"
".quad 0x7225203233732e64,0x31357225202c3331,0x6c2e0a3b312d202c,0x333333203220636f\n"
".quad 0x622e646e610a3120,0x202c347225203233,0x317225202c337225,0x20636f6c2e0a3b33\n"
".quad 0x3320323034332033,0x3233732e67656e0a,0x25202c3431722520,0x646e610a3b313572\n"
".quad 0x317225203233622e,0x2c31357225202c35,0x2e0a3b3431722520,0x3431203420636f6c\n"
".quad 0x2e7a6c630a352035,0x3631722520323362,0x0a3b35317225202c,0x203233752e766f6d\n"
".quad 0x3133202c37317225,0x33732e6275730a3b,0x202c383172252032,0x7225202c37317225\n"
".quad 0x636f6c2e0a3b3631,0x3120333333203220,0x3233752e7268730a,0x25202c3931722520\n"
".quad 0x38317225202c3372,0x7261702e646c0a3b,0x25203233752e6d61,0x5a5f5b202c383472\n"
".quad 0x636f725070733831,0x656b5f4432737365,0x6c6636506c656e72,0x535f30533274616f\n"
".quad 0x5f66666a6a6a5f30,0x5d335f6d61726170,0x33752e7268730a3b,0x25202c3572252032\n"
".quad 0x0a3b31202c383472,0x203233732e646461,0x7225202c30327225,0x2e0a3b312d202c35\n"
".quad 0x3333203220636f6c,0x2e646e610a312034,0x2c36722520323362,0x25202c3931722520\n"
".quad 0x6f6c2e0a3b303272,0x3230343320332063,0x732e67656e0a3320,0x2c31327225203233\n"
".quad 0x6e610a3b35722520,0x7225203233622e64,0x2c357225202c3232,0x2e0a3b3132722520\n"
".quad 0x3431203420636f6c,0x2e7a6c630a352035,0x3332722520323362,0x0a3b32327225202c\n"
".quad 0x203233732e627573,0x7225202c34327225,0x33327225202c3731,0x3220636f6c2e0a3b\n"
".quad 0x730a312034333320,0x25203233752e7268,0x317225202c353272,0x3b34327225202c39\n"
".quad 0x203220636f6c2e0a,0x756d0a3120363333,0x3233732e6f6c2e6c,0x7225202c37722520\n"
".quad 0x38347225202c3532,0x3220636f6c2e0a3b,0x730a312030343320,0x732e71652e707465\n"
".quad 0x202c317025203233,0x0a3b30202c367225,0x203233752e726873,0x7225202c36327225\n"
".quad 0x2e0a3b31202c3135,0x3433203220636f6c,0x707465730a312030,0x203233752e74672e\n"
".quad 0x347225202c337025,0x0a3b36327225202c,0x646572702e646e61,0x7025202c34702520\n"
".quad 0x0a3b337025202c31,0x33203220636f6c2e,0x7025400a31203034,0x4242206172622034\n"
".quad 0x64610a0a3b345f35,0x7225203233732e64,0x2c377225202c3133,0x646c0a3b36722520\n"
".quad 0x752e6d617261702e,0x2c30357225203233,0x707338315a5f5b20,0x32737365636f7250\n"
".quad 0x6c656e72656b5f44,0x3274616f6c663650,0x6a6a5f30535f3053,0x617261705f66666a\n"
".quad 0x6c2e0a3b5d345f6d,0x373433203220636f,0x6c2e64616d0a3120,0x7225203233732e6f\n"
".quad 0x31337225202c3932,0x202c30357225202c,0x2e646c0a3b347225,0x33752e6d61726170\n"
".quad 0x202c373472252032,0x50707338315a5f5b,0x4432737365636f72,0x506c656e72656b5f\n"
".quad 0x533274616f6c6636,0x6a6a6a5f30535f30,0x6d617261705f6666,0x6f6c2e0a3b5d335f\n"
".quad 0x2038343320322063,0x33732e6275730a31,0x202c323372252032,0x7225202c37347225\n"
".quad 0x2e706c65730a3b36,0x3333722520323362,0x25202c367225202c,0x317025202c323372\n"
".quad 0x33732e6464610a3b,0x202c343372252032,0x7225202c33337225,0x20636f6c2e0a3b37\n"
".quad 0x0a31203834332032,0x203233732e627573,0x7225202c35337225,0x3b347225202c3035\n"
".quad 0x71652e707465730a,0x357025203233732e,0x30202c347225202c,0x33752e766f6d0a3b\n"
".quad 0x202c363372252032,0x2e706c65730a3b30,0x2c38722520323362,0x7225202c34722520\n"
".quad 0x3b357025202c3533,0x203220636f6c2e0a,0x616d0a3120383433,0x3233732e6f6c2e64\n"
".quad 0x25202c3033722520,0x357225202c343372,0x0a3b387225202c30,0x64312e786574090a\n"
".quad 0x2e3233662e34762e,0x3566257b20323373,0x25202c366625202c,0x7d386625202c3766\n"
".quad 0x6f437865745b202c,0x202c4178656c706d,0x3b5d7d393272257b,0x786574090a090a0a\n"
".quad 0x662e34762e64312e,0x7b203233732e3233,0x316625202c396625,0x2c31316625202c30\n"
".quad 0x202c7d3231662520,0x706d6f437865745b,0x257b202c4178656c,0x0a0a3b5d7d303372\n"
".quad 0x312e786574090a09,0x3233662e34762e64,0x66257b203233732e,0x34316625202c3331\n"
".quad 0x202c35316625202c,0x5b202c7d36316625,0x6c706d6f43786574,0x72257b202c427865\n"
".quad 0x090a0a3b5d7d3932,0x64312e786574090a,0x2e3233662e34762e,0x3166257b20323373\n"
".quad 0x2c38316625202c37,0x25202c3931662520,0x745b202c7d303266,0x656c706d6f437865\n"
".quad 0x3372257b202c4278,0x2e090a0a3b5d7d30,0x3533203220636f6c,0x2e7476630a312034\n"
".quad 0x752e3233662e6e72,0x2c31326625203233,0x646c0a3b34722520,0x662e6d617261702e\n"
".quad 0x3139316625203233,0x7338315a5f5b202c,0x737365636f725070,0x656e72656b5f4432\n"
".quad 0x74616f6c6636506c,0x6a5f30535f305332,0x7261705f66666a6a,0x2e0a3b5d365f6d61\n"
".quad 0x3533203220636f6c,0x2e6c756d0a312034,0x3232662520323366,0x202c31326625202c\n"
".quad 0x2e0a3b3139316625,0x3635203420636f6c,0x2e6e69730a352030,0x662e786f72707061\n"
".quad 0x202c336625203233,0x6c2e0a3b32326625,0x323735203420636f,0x612e736f630a3520\n"
".quad 0x33662e786f727070,0x25202c3466252032,0x6f6c2e0a3b323266,0x2036353320322063\n"
".quad 0x33662e6464610a31,0x202c333266252032,0x396625202c356625,0x33662e766f6d0a3b\n"
".quad 0x202c343266252032,0x3030303046336630,0x636f6c2e0a3b3030,0x3120363533203220\n"
".quad 0x3233662e6275730a,0x25202c3532662520,0x30316625202c3666,0x33662e6464610a3b\n"
".quad 0x202c363266252032,0x316625202c366625,0x662e6c756d0a3b30,0x2c37326625203233\n"
".quad 0x30202c3632662520,0x3030303030463366,0x662e6275730a3b30,0x2c38326625203233\n"
".quad 0x6625202c35662520,0x662e6c756d0a3b39,0x2c39326625203233,0x30202c3832662520\n"
".quad 0x3030303030463366,0x662e6c756d0a3b30,0x2c30336625203233,0x25202c3932662520\n"
".quad 0x2e616d660a3b3366,0x25203233662e6e72,0x326625202c313366,0x202c346625202c37\n"
".quad 0x6d660a3b30336625,0x3233662e6e722e61,0x25202c3233662520,0x336630202c333266\n"
".quad 0x2c30303030303046,0x6d0a3b3133662520,0x25203233662e6c75,0x326625202c333366\n"
".quad 0x0a3b336625202c37,0x203233662e67656e,0x6625202c34336625,0x2e616d660a3b3932\n"
".quad 0x25203233662e6e72,0x336625202c353366,0x202c346625202c34,0x6d660a3b33336625\n"
".quad 0x3233662e6e722e61,0x25202c3633662520,0x336630202c353266,0x2c30303030303046\n"
".quad 0x6e0a3b3533662520,0x25203233662e6765,0x336625202c373366,0x722e616d660a3b31\n"
".quad 0x6625203233662e6e,0x33326625202c3833,0x202c34326625202c,0x656e0a3b37336625\n"
".quad 0x6625203233662e67,0x35326625202c3933,0x6e722e616d660a3b,0x346625203233662e\n"
".quad 0x2c39336625202c30,0x25202c3432662520,0x6f6c2e0a3b353366,0x2037353320322063\n"
".quad 0x33662e6464610a31,0x202c313466252032,0x6625202c33316625,0x2e6275730a3b3731\n"
".quad 0x3234662520323366,0x202c34316625202c,0x64610a3b38316625,0x6625203233662e64\n"
".quad 0x34316625202c3334,0x0a3b38316625202c,0x203233662e6c756d,0x6625202c34346625\n"
".quad 0x46336630202c3334,0x0a3b303030303030,0x203233662e627573,0x6625202c35346625\n"
".quad 0x37316625202c3331,0x33662e6c756d0a3b,0x202c363466252032,0x6630202c35346625\n"
".quad 0x3030303030304633,0x33662e6c756d0a3b,0x202c373466252032,0x6625202c36346625\n"
".quad 0x722e616d660a3b33,0x6625203233662e6e,0x34346625202c3834,0x25202c346625202c\n"
".quad 0x616d660a3b373466,0x203233662e6e722e,0x6625202c39346625,0x46336630202c3134\n"
".quad 0x202c303030303030,0x756d0a3b38346625,0x6625203233662e6c,0x34346625202c3035\n"
".quad 0x6e0a3b336625202c,0x25203233662e6765,0x346625202c313566,0x722e616d660a3b36\n"
".quad 0x6625203233662e6e,0x31356625202c3235,0x25202c346625202c,0x616d660a3b303566\n"
".quad 0x203233662e6e722e,0x6625202c33356625,0x46336630202c3234,0x202c303030303030\n"
".quad 0x656e0a3b32356625,0x6625203233662e67,0x38346625202c3435,0x6e722e616d660a3b\n"
".quad 0x356625203233662e,0x2c31346625202c35,0x25202c3432662520,0x67656e0a3b343566\n"
".quad 0x356625203233662e,0x3b32346625202c36,0x2e6e722e616d660a,0x3735662520323366\n"
".quad 0x202c36356625202c,0x6625202c34326625,0x636f6c2e0a3b3235,0x3120383533203220\n"
".quad 0x3233662e6c756d0a,0x25202c3835662520,0x346625202c323366,0x662e67656e0a3b39\n"
".quad 0x2c39356625203233,0x660a3b3633662520,0x33662e6e722e616d,0x202c303666252032\n"
".quad 0x6625202c39356625,0x38356625202c3335,0x7261702e646c0a3b,0x25203233662e6d61\n"
".quad 0x5f5b202c33393166,0x6f7250707338315a,0x6b5f443273736563,0x6636506c656e7265\n"
".quad 0x5f30533274616f6c,0x66666a6a6a5f3053,0x375f6d617261705f,0x20636f6c2e0a3b5d\n"
".quad 0x0a31203835332032,0x203233662e6c756d,0x6625202c31366625,0x39316625202c3036\n"
".quad 0x662e6c756d0a3b33,0x2c32366625203233,0x25202c3233662520,0x616d660a3b333566\n"
".quad 0x203233662e6e722e,0x6625202c33366625,0x39346625202c3633,0x0a3b32366625202c\n"
".quad 0x203233662e6c756d,0x6625202c34366625,0x39316625202c3336,0x20636f6c2e0a3b33\n"
".quad 0x0a31203935332032,0x203233662e6c756d,0x6625202c35366625,0x35356625202c3833\n"
".quad 0x33662e67656e0a3b,0x202c363666252032,0x6d660a3b30346625,0x3233662e6e722e61\n"
".quad 0x25202c3736662520,0x356625202c363666,0x3b35366625202c37,0x3233662e6c756d0a\n"
".quad 0x25202c3836662520,0x316625202c373666,0x2e6c756d0a3b3339,0x3936662520323366\n"
".quad 0x202c38336625202c,0x6d660a3b37356625,0x3233662e6e722e61,0x25202c3037662520\n"
".quad 0x356625202c303466,0x3b39366625202c35,0x3233662e6c756d0a,0x25202c3137662520\n"
".quad 0x316625202c303766,0x636f6c2e0a3b3339,0x3120303633203220,0x2e6e722e616d660a\n"
".quad 0x3237662520323366,0x202c30366625202c,0x25202c3339316625,0x67656e0a3b383666\n"
".quad 0x376625203233662e,0x3b30376625202c33,0x2e6e722e616d660a,0x3437662520323366\n"
".quad 0x202c33376625202c,0x25202c3339316625,0x616d660a3b343666,0x203233662e6e722e\n"
".quad 0x6625202c35376625,0x39316625202c3336,0x3b31376625202c33,0x3233662e67656e0a\n"
".quad 0x25202c3637662520,0x616d660a3b373666,0x203233662e6e722e,0x6625202c37376625\n"
".quad 0x39316625202c3637,0x3b31366625202c33,0x3233662e6c756d0a,0x25202c3837662520\n"
".quad 0x346625202c353766,0x33662e67656e0a3b,0x202c393766252032,0x6d660a3b37376625\n"
".quad 0x3233662e6e722e61,0x25202c3038662520,0x336625202c393766,0x0a3b38376625202c\n"
".quad 0x203233662e627573,0x6625202c31386625,0x30386625202c3237,0x33662e6c756d0a3b\n"
".quad 0x202c323866252032,0x6625202c35376625,0x722e616d660a3b33,0x6625203233662e6e\n"
".quad 0x37376625202c3338,0x25202c346625202c,0x6464610a3b323866,0x386625203233662e\n"
".quad 0x2c33386625202c34,0x610a3b3437662520,0x25203233662e6464,0x376625202c353866\n"
".quad 0x3b30386625202c32,0x3233662e6275730a,0x25202c3638662520,0x376625202c333866\n"
".quad 0x20636f6c2e0a3b34,0x0a31203236332032,0x656469772e6c756d,0x6c7225203233752e\n"
".quad 0x2c39327225202c33,0x2e6464610a3b3820,0x346c722520343673,0x202c316c7225202c\n"
".quad 0x74730a3b336c7225,0x2e6c61626f6c672e,0x5b203233662e3276,0x7b202c5d346c7225\n"
".quad 0x6625202c31386625,0x6f6c2e0a3b7d3438,0x2033363320322063,0x69772e6c756d0a31\n"
".quad 0x25203233752e6564,0x337225202c356c72,0x64610a3b38202c30,0x7225203436732e64\n"
".quad 0x316c7225202c366c,0x0a3b356c7225202c,0x61626f6c672e7473,0x3233662e32762e6c\n"
".quad 0x2c5d366c72255b20,0x202c353866257b20,0x2e0a3b7d36386625,0x3633203220636f6c\n"
".quad 0x702521400a312036,0x4242206172622031,0x64610a0a3b345f35,0x7225203233732e64\n"
".quad 0x2c377225202c3334,0x646c0a3b35722520,0x752e6d617261702e,0x2c39347225203233\n"
".quad 0x707338315a5f5b20,0x32737365636f7250,0x6c656e72656b5f44,0x3274616f6c663650\n"
".quad 0x6a6a5f30535f3053,0x617261705f66666a,0x6c2e0a3b5d345f6d,0x373633203220636f\n"
".quad 0x6c2e64616d0a3120,0x7225203233732e6f,0x33347225202c3134,0x202c39347225202c\n"
".quad 0x6f6c2e0a3b347225,0x2038363320322063,0x6f6c2e64616d0a31,0x347225203233732e\n"
".quad 0x2c33347225202c32,0x25202c3934722520,0x6574090a0a3b3872,0x2e34762e64312e78\n"
".quad 0x203233732e323366,0x25202c373866257b,0x386625202c383866,0x7d30396625202c39\n"
".quad 0x6f437865745b202c,0x202c4178656c706d,0x3b5d7d313472257b,0x786574090a090a0a\n"
".quad 0x662e34762e64312e,0x7b203233732e3233,0x6625202c31396625,0x33396625202c3239\n"
".quad 0x2c7d34396625202c,0x6d6f437865745b20,0x7b202c4178656c70,0x0a3b5d7d32347225\n"
".quad 0x2e786574090a090a,0x33662e34762e6431,0x257b203233732e32,0x396625202c353966\n"
".quad 0x2c37396625202c36,0x202c7d3839662520,0x706d6f437865745b,0x257b202c4278656c\n"
".quad 0x0a0a3b5d7d313472,0x312e786574090a09,0x3233662e34762e64,0x66257b203233732e\n"
".quad 0x30316625202c3939,0x3130316625202c30,0x7d3230316625202c,0x6f437865745b202c\n"
".quad 0x202c4278656c706d,0x3b5d7d323472257b,0x20636f6c2e090a0a,0x0a31203537332032\n"
".quad 0x203233662e646461,0x25202c3330316625,0x396625202c373866,0x662e6275730a3b31\n"
".quad 0x3530316625203233,0x202c38386625202c,0x64610a3b32396625,0x6625203233662e64\n"
".quad 0x386625202c363031,0x3b32396625202c38,0x3233662e6c756d0a,0x202c373031662520\n"
".quad 0x30202c3630316625,0x3030303030463366,0x662e6275730a3b30,0x3830316625203233\n"
".quad 0x202c37386625202c,0x756d0a3b31396625,0x6625203233662e6c,0x316625202c393031\n"
".quad 0x46336630202c3830,0x0a3b303030303030,0x203233662e6c756d,0x25202c3031316625\n"
".quad 0x6625202c39303166,0x722e616d660a3b33,0x6625203233662e6e,0x316625202c313131\n"
".quad 0x2c346625202c3730,0x0a3b303131662520,0x662e6e722e616d66,0x3231316625203233\n"
".quad 0x2c3330316625202c,0x3030304633663020,0x316625202c303030,0x2e6c756d0a3b3131\n"
".quad 0x3131662520323366,0x3730316625202c33,0x6e0a3b336625202c,0x25203233662e6765\n"
".quad 0x6625202c34313166,0x616d660a3b393031,0x203233662e6e722e,0x25202c3531316625\n"
".quad 0x6625202c34313166,0x3331316625202c34,0x6e722e616d660a3b,0x316625203233662e\n"
".quad 0x30316625202c3631,0x3046336630202c35,0x25202c3030303030,0x656e0a3b35313166\n"
".quad 0x6625203233662e67,0x316625202c373131,0x2e616d660a3b3131,0x25203233662e6e72\n"
".quad 0x6625202c38313166,0x326625202c333031,0x3731316625202c34,0x33662e67656e0a3b\n"
".quad 0x2c39313166252032,0x0a3b353031662520,0x662e6e722e616d66,0x3032316625203233\n"
".quad 0x2c3931316625202c,0x25202c3432662520,0x6c2e0a3b35313166,0x363733203220636f\n"
".quad 0x662e6464610a3120,0x3132316625203233,0x202c35396625202c,0x75730a3b39396625\n"
".quad 0x6625203233662e62,0x396625202c323231,0x3030316625202c36,0x33662e6464610a3b\n"
".quad 0x2c33323166252032,0x25202c3639662520,0x756d0a3b30303166,0x6625203233662e6c\n"
".quad 0x316625202c343231,0x46336630202c3332,0x0a3b303030303030,0x203233662e627573\n"
".quad 0x25202c3532316625,0x396625202c353966,0x662e6c756d0a3b39,0x3632316625203233\n"
".quad 0x2c3532316625202c,0x3030304633663020,0x6c756d0a3b303030,0x316625203233662e\n"
".quad 0x32316625202c3732,0x0a3b336625202c36,0x662e6e722e616d66,0x3832316625203233\n"
".quad 0x2c3432316625202c,0x6625202c34662520,0x616d660a3b373231,0x203233662e6e722e\n"
".quad 0x25202c3932316625,0x6630202c31323166,0x3030303030304633,0x3b3832316625202c\n"
".quad 0x3233662e6c756d0a,0x202c303331662520,0x25202c3432316625,0x2e67656e0a3b3366\n"
".quad 0x3331662520323366,0x3632316625202c31,0x6e722e616d660a3b,0x316625203233662e\n"
".quad 0x33316625202c3233,0x202c346625202c31,0x660a3b3033316625,0x33662e6e722e616d\n"
".quad 0x2c33333166252032,0x202c323231662520,0x3030303046336630,0x33316625202c3030\n"
".quad 0x662e67656e0a3b32,0x3433316625203233,0x3b3832316625202c,0x2e6e722e616d660a\n"
".quad 0x3331662520323366,0x3132316625202c35,0x202c34326625202c,0x6e0a3b3433316625\n"
".quad 0x25203233662e6765,0x6625202c36333166,0x616d660a3b323231,0x203233662e6e722e\n"
".quad 0x25202c3733316625,0x6625202c36333166,0x33316625202c3432,0x20636f6c2e0a3b32\n"
".quad 0x0a31203737332032,0x203233662e6c756d,0x25202c3833316625,0x6625202c32313166\n"
".quad 0x67656e0a3b393231,0x316625203233662e,0x31316625202c3933,0x722e616d660a3b36\n"
".quad 0x6625203233662e6e,0x316625202c303431,0x33316625202c3933,0x3833316625202c33\n"
".quad 0x7261702e646c0a3b,0x25203233662e6d61,0x5f5b202c32393166,0x6f7250707338315a\n"
".quad 0x6b5f443273736563,0x6636506c656e7265,0x5f30533274616f6c,0x66666a6a6a5f3053\n"
".quad 0x375f6d617261705f,0x20636f6c2e0a3b5d,0x0a31203737332032,0x203233662e6c756d\n"
".quad 0x25202c3134316625,0x6625202c30343166,0x6c756d0a3b323931,0x316625203233662e\n"
".quad 0x31316625202c3234,0x3333316625202c32,0x6e722e616d660a3b,0x316625203233662e\n"
".quad 0x31316625202c3334,0x3932316625202c36,0x3b3234316625202c,0x3233662e6c756d0a\n"
".quad 0x202c343431662520,0x25202c3334316625,0x6c2e0a3b32393166,0x383733203220636f\n"
".quad 0x662e6c756d0a3120,0x3534316625203233,0x2c3831316625202c,0x0a3b353331662520\n"
".quad 0x203233662e67656e,0x25202c3634316625,0x6d660a3b30323166,0x3233662e6e722e61\n"
".quad 0x202c373431662520,0x25202c3634316625,0x6625202c37333166,0x6c756d0a3b353431\n"
".quad 0x316625203233662e,0x34316625202c3834,0x3239316625202c37,0x33662e6c756d0a3b\n"
".quad 0x2c39343166252032,0x202c383131662520,0x660a3b3733316625,0x33662e6e722e616d\n"
".quad 0x2c30353166252032,0x202c303231662520,0x25202c3533316625,0x756d0a3b39343166\n"
".quad 0x6625203233662e6c,0x316625202c313531,0x39316625202c3035,0x20636f6c2e0a3b32\n"
".quad 0x0a31203937332032,0x662e6e722e616d66,0x3235316625203233,0x2c3034316625202c\n"
".quad 0x202c323931662520,0x6e0a3b3834316625,0x25203233662e6765,0x6625202c33353166\n"
".quad 0x616d660a3b303531,0x203233662e6e722e,0x25202c3435316625,0x6625202c33353166\n"
".quad 0x316625202c323931,0x2e616d660a3b3434,0x25203233662e6e72,0x6625202c35353166\n"
".quad 0x316625202c333431,0x35316625202c3239,0x662e67656e0a3b31,0x3635316625203233\n"
".quad 0x3b3734316625202c,0x2e6e722e616d660a,0x3531662520323366,0x3635316625202c37\n"
".quad 0x2c3239316625202c,0x0a3b313431662520,0x203233662e6c756d,0x25202c3835316625\n"
".quad 0x6625202c35353166,0x662e67656e0a3b34,0x3935316625203233,0x3b3735316625202c\n"
".quad 0x2e6e722e616d660a,0x3631662520323366,0x3935316625202c30,0x25202c336625202c\n"
".quad 0x75730a3b38353166,0x6625203233662e62,0x316625202c313631,0x36316625202c3235\n"
".quad 0x662e6c756d0a3b30,0x3236316625203233,0x2c3535316625202c,0x6d660a3b33662520\n"
".quad 0x3233662e6e722e61,0x202c333631662520,0x25202c3735316625,0x36316625202c3466\n"
".quad 0x662e6464610a3b32,0x3436316625203233,0x2c3336316625202c,0x0a3b343531662520\n"
".quad 0x203233662e646461,0x25202c3536316625,0x6625202c32353166,0x6275730a3b303631\n"
".quad 0x316625203233662e,0x36316625202c3636,0x3435316625202c33,0x3220636f6c2e0a3b\n"
".quad 0x6d0a312031383320,0x2e656469772e6c75,0x376c722520323375,0x202c31347225202c\n"
".quad 0x732e6464610a3b38,0x2c386c7225203436,0x25202c316c722520,0x2e74730a3b376c72\n"
".quad 0x762e6c61626f6c67,0x255b203233662e32,0x257b202c5d386c72,0x6625202c31363166\n"
".quad 0x6c2e0a3b7d343631,0x323833203220636f,0x772e6c756d0a3120,0x203233752e656469\n"
".quad 0x7225202c396c7225,0x610a3b38202c3234,0x25203436732e6464,0x7225202c30316c72\n"
".quad 0x396c7225202c316c,0x6f6c672e74730a3b,0x662e32762e6c6162,0x316c72255b203233\n"
".quad 0x3166257b202c5d30,0x36316625202c3536,0x3542420a0a3b7d36,0x636f6c2e0a3a345f\n"
".quad 0x3220343833203220,0x0a7d0a3b7465720a,0x6801000002000a0a,0x000000246c000000\n"
".quad 0x0000000000000000,0x1400010004000000,0x2a00000038000000,0x0000000015000000\n"
".quad 0x0000000000000000,0x7374736574000000,0x756c6f766e6f632f,0x325446466e6f6974\n"
".quad 0x6c6f766e6f632f44,0x5446466e6f697475,0x00000075632e4432,0x02464c457f000000\n"
".quad 0x0000000004330101,0x0100be0002000000,0x0000000000000000,0x00000022e4000000\n"
".quad 0x0000000040000000,0x4000140514000000,0x1700400007003800,0x0000000000000100\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0300000001000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000600000000,0x00000003d2000000\n"
".quad 0x0000000000000000,0x0000000004000000,0x0000000000000000,0x030000000b000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x00000009d2000000,0x0000000119000000\n"
".quad 0x0000000000000000,0x0000000001000000,0x0000000000000000,0x0200000013000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000aeb000000,0x0000000330000000\n"
".quad 0x1900000002000000,0x0000000001000000,0x0000000018000000,0x0100000224000000\n"
".quad 0x0000000006000000,0x0000000000000000,0x0000000e1b000000,0x0000000570000000\n"
".quad 0x1100000003000000,0x0000000004140000,0x0000000000000000,0x0100000361000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x000000138b000000,0x000000004c000000\n"
".quad 0x0400000000000000,0x0000000004000000,0x0000000000000000,0x0100000254000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x00000013d7000000,0x00000000b4000000\n"
".quad 0x0400000000000000,0x0000000001000000,0x0000000000000000,0x01000001bd000000\n"
".quad 0x0000000006000000,0x0000000000000000,0x000000148b000000,0x0000000108000000\n"
".quad 0x0f00000003000000,0x0000000004060000,0x0000000000000000,0x01000002b4000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x0000001593000000,0x0000000050000000\n"
".quad 0x0700000000000000,0x0000000004000000,0x0000000000000000,0x01000001ef000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x00000015e3000000,0x00000000c8000000\n"
".quad 0x0700000000000000,0x0000000001000000,0x0000000000000000,0x0100000158000000\n"
".quad 0x0000000006000000,0x0000000000000000,0x00000016ab000000,0x0000000358000000\n"
".quad 0x0d00000003000000,0x0000000004130000,0x0000000000000000,0x0100000399000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x0000001a03000000,0x0000000044000000\n"
".quad 0x0a00000000000000,0x0000000004000000,0x0000000000000000,0x0100000189000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x0000001a47000000,0x0000000098000000\n"
".quad 0x0a00000000000000,0x0000000001000000,0x0000000000000000,0x01000000f5000000\n"
".quad 0x0000000006000000,0x0000000000000000,0x0000001adf000000,0x0000000358000000\n"
".quad 0x0b00000003000000,0x0000000004130000,0x0000000000000000,0x01000002ee000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x0000001e37000000,0x0000000044000000\n"
".quad 0x0d00000000000000,0x0000000004000000,0x0000000000000000,0x0100000125000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x0000001e7b000000,0x0000000098000000\n"
".quad 0x0d00000000000000,0x0000000001000000,0x0000000000000000,0x01000000a8000000\n"
".quad 0x0000000006000000,0x0000000000000000,0x0000001f13000000,0x00000000d0000000\n"
".quad 0x0900000003000000,0x0000000004060000,0x0000000000000000,0x0100000287000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x0000001fe3000000,0x0000000048000000\n"
".quad 0x1000000000000000,0x0000000004000000,0x0000000000000000,0x01000000cd000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x000000202b000000,0x00000000a8000000\n"
".quad 0x1000000000000000,0x0000000001000000,0x0000000000000000,0x0100000036000000\n"
".quad 0x0000000006000000,0x0000000000000000,0x00000020d3000000,0x00000000b0000000\n"
".quad 0x0600000003000000,0x00000000040a0000,0x0000000000000000,0x0100000326000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x0000002183000000,0x0000000038000000\n"
".quad 0x1300000000000000,0x0000000004000000,0x0000000000000000,0x0100000069000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x00000021bb000000,0x000000005c000000\n"
".quad 0x1300000000000000,0x0000000001000000,0x0000000000000000,0x010000009f000000\n"
".quad 0x0000000002000000,0x0000000000000000,0x0000002217000000,0x00000000cc000000\n"
".quad 0x0000000000000000,0x0000000001000000,0x0000000000000000,0x7368732e00000000\n"
".quad 0x732e006261747274,0x732e006261747274,0x6e2e006261746d79,0x6c61626f6c672e76\n"
".quad 0x6e2e0074696e692e,0x6c61626f6c672e76,0x5f2e747865742e00,0x6c75646f6d37325a\n"
".quad 0x6f4e646e41657461,0x5f657a696c616d72,0x36506c656e72656b,0x30533274616f6c66\n"
".quad 0x2e766e2e0066695f,0x325a5f2e6f666e69,0x74616c75646f6d37,0x6d726f4e646e4165\n"
".quad 0x656b5f657a696c61,0x6c6636506c656e72,0x695f30533274616f,0x6e692e766e2e0066\n"
".quad 0x747865742e006f66,0x64617036315a5f2e,0x6b5f6c656e72654b,0x5366506c656e7265\n"
".quad 0x006969696969695f,0x6f666e692e766e2e,0x64617036315a5f2e,0x6b5f6c656e72654b\n"
".quad 0x5366506c656e7265,0x006969696969695f,0x5a5f2e747865742e,0x7065725070733132\n"
".quad 0x4432737365636f72,0x506c656e72656b5f,0x533274616f6c6636,0x00666a6a6a6a5f30\n"
".quad 0x6f666e692e766e2e,0x50707331325a5f2e,0x7365636f72706572,0x6e72656b5f443273\n"
".quad 0x616f6c6636506c65,0x6a6a6a5f30533274,0x747865742e00666a,0x50707332325a5f2e\n"
".quad 0x65636f727074736f,0x72656b5f44327373,0x6f6c6636506c656e,0x6a6a5f3053327461\n"
".quad 0x2e766e2e00666a6a,0x325a5f2e6f666e69,0x7074736f50707332,0x4432737365636f72\n"
".quad 0x506c656e72656b5f,0x533274616f6c6636,0x00666a6a6a6a5f30,0x5a5f2e747865742e\n"
".quad 0x7461446461703732,0x6f54706d616c4361,0x6b5f726564726f42,0x5366506c656e7265\n"
".quad 0x696969696969695f,0x6e692e766e2e0069,0x7037325a5f2e6f66,0x6c43617461446461\n"
".quad 0x726f426f54706d61,0x6e72656b5f726564,0x69695f5366506c65,0x2e00696969696969\n"
".quad 0x315a5f2e74786574,0x65636f7250707338,0x72656b5f44327373,0x6f6c6636506c656e\n"
".quad 0x30535f3053327461,0x2e0066666a6a6a5f,0x2e6f666e692e766e,0x7250707338315a5f\n"
".quad 0x5f4432737365636f,0x36506c656e72656b,0x30533274616f6c66,0x666a6a6a5f30535f\n"
".quad 0x6f632e766e2e0066,0x2e30746e6174736e,0x4b64617036315a5f,0x656b5f6c656e7265\n"
".quad 0x5f5366506c656e72,0x2e00696969696969,0x74736e6f632e766e,0x325a5f2e30746e61\n"
".quad 0x6174614464617037,0x426f54706d616c43,0x656b5f726564726f,0x5f5366506c656e72\n"
".quad 0x6969696969696969,0x6e6f632e766e2e00,0x5f2e30746e617473,0x657250707331325a\n"
".quad 0x32737365636f7270,0x6c656e72656b5f44,0x3274616f6c663650,0x666a6a6a6a5f3053\n"
".quad 0x6e6f632e766e2e00,0x5f2e30746e617473,0x6c75646f6d37325a,0x6f4e646e41657461\n"
".quad 0x5f657a696c616d72,0x36506c656e72656b,0x30533274616f6c66,0x2e766e2e0066695f\n"
".quad 0x746e6174736e6f63,0x707338315a5f2e30,0x32737365636f7250,0x6c656e72656b5f44\n"
".quad 0x3274616f6c663650,0x6a6a5f30535f3053,0x2e766e2e0066666a,0x746e6174736e6f63\n"
".quad 0x707332325a5f2e30,0x636f727074736f50,0x656b5f4432737365,0x6c6636506c656e72\n"
".quad 0x6a5f30533274616f,0x5a5f0000666a6a6a,0x616c75646f6d3732,0x726f4e646e416574\n"
".quad 0x6b5f657a696c616d,0x6636506c656e7265,0x5f30533274616f6c,0x7036315a5f006669\n"
".quad 0x6c656e72654b6461,0x506c656e72656b5f,0x69696969695f5366,0x707331325a5f0069\n"
".quad 0x65636f7270657250,0x72656b5f44327373,0x6f6c6636506c656e,0x6a6a5f3053327461\n"
".quad 0x32325a5f00666a6a,0x727074736f507073,0x5f4432737365636f,0x36506c656e72656b\n"
".quad 0x30533274616f6c66,0x5f00666a6a6a6a5f,0x614464617037325a,0x54706d616c436174\n"
".quad 0x5f726564726f426f,0x66506c656e72656b,0x6969696969695f53,0x7338315a5f006969\n"
".quad 0x737365636f725070,0x656e72656b5f4432,0x74616f6c6636506c,0x6a5f30535f305332\n"
".quad 0x7865740066666a6a,0x65740074616f6c46,0x78656c706d6f4378,0x6d6f437865740041\n"
".quad 0x0000004278656c70,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000100030000,0x0000000000000000,0x0000000000000000,0x0000000200030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000300030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000030000,0x0000000000000000,0x0000000000000000,0x0000001300030000\n"
".quad 0x00b0000000000000,0x0000000000000000,0x0000001500030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000001600030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000001000030000,0x00d0000000000000,0x0000000000000000,0x0000001200030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000d00030000,0x0358000000000000\n"
".quad 0x0000000000000000,0x0000000f00030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000a00030000,0x0358000000000000,0x0000000000000000,0x0000000c00030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000700030000,0x0108000000000000\n"
".quad 0x0000000000000000,0x0000000900030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000400030000,0x0570000000000000,0x0000000000000000,0x0000000600030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000001100030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000800030000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000e00030000,0x0000000000000000,0x0000000000000000,0x0000001400030000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000500030000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000b00030000,0x0000000000000000,0x0001000000000000\n"
".quad 0x0000001310120000,0x00b0000000000000,0x002e000000000000,0x0000001010120000\n"
".quad 0x00d0000000000000,0x004d000000000000,0x0000000d10120000,0x0358000000000000\n"
".quad 0x0077000000000000,0x0000000a10120000,0x0358000000000000,0x00a2000000000000\n"
".quad 0x0000000710120000,0x0108000000000000,0x00ce000000000000,0x0000000410120000\n"
".quad 0x0570000000000000,0x00f8000000000000,0x00000000001a0000,0x0000000000000000\n"
".quad 0x0101000000000000,0x00000000001a0000,0x0000000000000000,0x010d000000000000\n"
".quad 0x00000000001a0000,0x0000000000000000,0x5de4000000000000,0x1c04280044040000\n"
".quad 0x9c042c0000009400,0x1ca32c0000008400,0xdc03200440002000,0x01e71b0e40010001\n"
".quad 0x9f84800000000000,0x1de41c004000f120,0x9de428004000e001,0xdc0328004000f001\n"
".quad 0xdc0368004000f020,0x9c035800c0000442,0xdc034800fffffc60,0x1c03780000000c00\n"
".quad 0x5f844800fffffcb1,0xdc031c0000002d21,0x9c03580000000c00,0x5c03680000000802\n"
".quad 0x1c036800000014b1,0x9c03680000001031,0x1c035800c0000461,0xdc23780000001400\n"
".quad 0x1c03190e0000fc41,0xdc03580000000030,0x1ca31a00000018a3,0x05e750004000e000\n"
".quad 0x9c03800000000000,0x9e03480000001000,0x5e0348004000e041,0x1ca348004000f0a1\n"
".quad 0x9c8620144000f024,0x1c049000c000fd00,0x1c23200000001841,0x1c033114000014a3\n"
".quad 0xdca3480000000041,0x1c8620184000f043,0x9c869000c000fcf1,0x1c869000c101fd01\n"
".quad 0x5c049000c101fcf2,0x5c00180000002923,0x9c005800400110d3,0x5c00600000003403\n"
".quad 0x9c00c800000004e3,0x5d00c800000000e3,0x9c00500000001024,0x9c00500000001434\n"
".quad 0x5c00500000001020,0x9c005800cfc00114,0x5d005800cfc00124,0xdc00500000001431\n"
".quad 0x1c00580000003514,0x9c00580000003521,0x1e00302600003924,0xdc00300800003911\n"
".quad 0x9d003024cfc00020,0xdd003024cfc00024,0x5c00500000002064,0x9c00500000002474\n"
".quad 0xdc00500000002061,0x5c005800cfc00134,0xdd005800cfc00114,0x1c00500000002471\n"
".quad 0x9c00580000003532,0x5c00580000003510,0x1c003008cfc00052,0x9e00301000003912\n"
".quad 0x1e00300400003930,0x5c003008cfc00051,0x5c003010cfc00061,0x1d003004cfc00074\n"
".quad 0x9c003010cfc00062,0xdc00580000001431,0x9e00580000004430,0x5e003004cfc00070\n"
".quad 0x5c00300c00004494,0xdc00300600001492,0xdc00580000002120,0x5de4580000000921\n"
".quad 0x9e00280040008001,0x1c00300600000840,0xdc43300e00002041,0x9c035000c0002100\n"
".quad 0x1c00200bc0002101,0x1c00580040012094,0xdc43580040012042,0xde00480040009031\n"
".quad 0x1c00302040012040,0x5c00301040012091,0x1c00580040012112,0x1c03580040012024\n"
".quad 0x9e00200bc00020f2,0x5c00301240012020,0x5c00302040012111,0x1c43580000003842\n"
".quad 0x1c005000c00020f4,0xde00580000003441,0x5c43301200003423,0x1c00480040009102\n"
".quad 0x1d00300800003824,0x9c00500000003c51,0x5c00500000003c50,0xdd00500000000d01\n"
".quad 0x1ca5500000000d00,0x9ca5940000000061,0xa1e7940000000080,0x0003400000088000\n"
".quad 0xc0a3480000002c00,0x808620144000f002,0x00a39000c000fcb0,0x008620184000f000\n"
".quad 0x80869000c000fc02,0x00869000c101fcb1,0x81009000c101fc01,0x0000500000002022\n"
".quad 0x8000500000002433,0xc000500000002020,0x00005800cfc000a3,0xc1005800cfc000c3\n"
".quad 0x0000500000002430,0x00005800000034f4,0x81e45800000034c2,0x4000280040008002\n"
".quad 0x42003020000038c4,0x00433010000038f2,0x00005000c00020b3,0xc1003022cfc00024\n"
".quad 0x00003022cfc00023,0x42003012cfc00032,0x81003012cfc00032,0xc000500000001060\n"
".quad 0x8000500000001470,0x4000500000001061,0x80035800cfc00024,0x80002015c00020b0\n"
".quad 0xc0005800cfc00034,0xc043580000003512,0x00004800400090c0,0xc000580000003523\n"
".quad 0x0003301600003922,0x41002015c0002001,0x8200500000001471,0xc000301800003912\n"
".quad 0x81003016cfc00061,0x00003016cfc00061,0x82003014cfc00053,0x40003014cfc00052\n"
".quad 0xc000580000001d01,0x4043580000003102,0x00005000c0002004,0x02005800000028f4\n"
".quad 0x0000300a00003080,0x80005800000018f3,0xc000302000001891,0x0200301600001c82\n"
".quad 0x4000301800002892,0xc000580040012062,0x80005800400120b1,0xc000580040012002\n"
".quad 0x40003012400120b2,0x0200580040012082,0x8000301440012082,0xc0005800000038b2\n"
".quad 0x00005800000034b2,0x4200301240012000,0x8200301400003482,0x0000300e40012062\n"
".quad 0x8100301600003882,0x4043500000002401,0xc000480040009111,0x0000500000002881\n"
".quad 0x4100500000002403,0x80a5500000002883,0x00a5940000000021,0x1de7940000000043\n"
".quad 0x0000800000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0020000802040000,0x0204000000000000\n"
".quad 0x0001000000210008,0x001700080a040000,0x1903002c00200000,0x0000000c1704002c\n"
".quad 0xf000002800070000,0x0000000c17040011,0xf000002400060000,0x0000000c17040011\n"
".quad 0xf000002000050000,0x0000000c17040011,0xf000001c00040000,0x0000000c17040011\n"
".quad 0xf000001800030000,0x0000000c17040011,0xf000001000020000,0x0000000c17040021\n"
".quad 0xf000000800010000,0x0000000c17040021,0xf000000000000000,0x002400080d040021\n"
".quad 0x5de4000000030003,0xdc04280044040000,0x1c042c0000009400,0x1c042c0000008401\n"
".quad 0x9c042c0000009800,0x1ca32c0000008800,0xdde4200840002031,0x5ca3280040012000\n"
".quad 0xdc23200440003001,0x1de4188e4000d041,0xdc03280040013000,0xdc2348004000e030\n"
".quad 0x1c0318804000c059,0xd02348004000f000,0x91e2188e00000c51,0xd0231bfffffffc00\n"
".quad 0xd023188e00000045,0x10031b004000e053,0xd02348004000e020,0x90031b044000f047\n"
".quad 0x100448004000f020,0xd004200200001400,0x9004200600001020,0x100420000000fc00\n"
".quad 0x10a320040000fc30,0x908620004000f020,0x10a390004000fc00,0xd1e420084000d050\n"
".quad 0x10a3280040008000,0x10e32007c0001001,0x50435000c0001000,0x9085480040009001\n"
".quad 0x1de7940000000040,0x0000800000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0204000000000000\n"
".quad 0x00000000001f0008,0x001400080a040000,0x1903003000200000,0x0000000c17040030\n"
".quad 0xf000002c00090000,0x0000000c17040011,0xf000002800080000,0x0000000c17040011\n"
".quad 0xf000002400070000,0x0000000c17040011,0xf000002000060000,0x0000000c17040011\n"
".quad 0xf000001c00050000,0x0000000c17040011,0xf000001800040000,0x0000000c17040011\n"
".quad 0xf000001400030000,0x0000000c17040011,0xf000001000020000,0x0000000c17040011\n"
".quad 0xf000000800010000,0x0000000c17040021,0xf000000000000000,0x000c00080d040021\n"
".quad 0x5de4000000010001,0x1c04280044040000,0x9c042c0000009400,0x9ca32c0000008400\n"
".quad 0xdc03200440002000,0x01e71b0e4000e021,0x5de4800000000000,0x1f8428004000d003\n"
".quad 0x5de41c004000c121,0x1c0328004000c001,0x1c035800c00004d0,0x5c0368004000c041\n"
".quad 0xdf844800fffffc51,0x1c031c0000000120,0x9c03780000001001,0xdc034800fffffc01\n"
".quad 0xdc03680000000c00,0xdc03680000001821,0x9e03780000000c00,0xdc0348004000d071\n"
".quad 0x1c03580000000c20,0x1c03680000001433,0x1e03580000001032,0x5ca348004000c0c1\n"
".quad 0x9ca320184000c082,0x9c86200e4000d090,0x9c239000c000fc20,0x1c233118000010c2\n"
".quad 0xdca3310e00001871,0x1ca320144000c082,0x1c8620084000d0b1,0x9c049000c000fc41\n"
".quad 0x5c03180000001d23,0xdc2348004000f0d3,0x9c00190e0000fc71,0xdca35800400100e3\n"
".quad 0x1ca3200e000034c1,0x1c005000000034c3,0x9c00600000003804,0xdd00c80000000503\n"
".quad 0x5c00500000001023,0x9c00500000001024,0xdc00500000001430,0x1c005800cfc000f3\n"
".quad 0x9c00c80000000101,0x1d005800cfc00024,0x9c00500000001434,0xdc005800000038f0\n"
".quad 0x9ca3580000003920,0x9c0050004000c0d3,0xde00300400001120,0x9ca33006000010f0\n"
".quad 0x9ca3200c000020e4,0xdde4200e000020e1,0x9ca3280040008003,0xdc432024000034a4\n"
".quad 0x9c035000c0002061,0x5c00201fc0002061,0x1c003006cfc00101,0xde003004cfc00111\n"
".quad 0xdc433006cfc00100,0x9ca3480040009071,0x1c035000000020e3,0x1c43201fc0002122\n"
".quad 0x1ca55000c0002124,0xdca3940000000061,0x9d0050004000d093,0x5c433004cfc00110\n"
".quad 0xdca3480040009102,0x1ca35000000034a1,0x9ca550004000d0b1,0x21e7940000000080\n"
".quad 0x9c03800000000000,0x9c864800000000f0,0x1c039000c000fc20,0x1c86480000000041\n"
".quad 0x9c039000c000fc41,0xdde44800000000c1,0x5c03280040008002,0x9c034800000000e2\n"
".quad 0xdc00480000003861,0x9c03208e400103f1,0x1c43480000001c92,0x9c035000c0002062\n"
".quad 0x1c432017c0002061,0x1de25000c00020a3,0xdc431afe00000000,0x1c03480040009081\n"
".quad 0x01e22017c00020a2,0x5d0018fe00000000,0x9c00500000001022,0x1c00500000001432\n"
".quad 0xdc00500000001021,0x9c005800cfc00092,0x5c435800cfc000a2,0x1c004800400090c2\n"
".quad 0x9c005800000000b3,0x5d005800000000a0,0x1c00500000001431,0x9e0030180000fca0\n"
".quad 0x9c0030040000fcb2,0xdc003000cfc00040,0x1d003014cfc00050,0x5e003000cfc00041\n"
".quad 0x9ca53014cfc00051,0x1ca5940000000060,0x1de7940000000081,0x0000800000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0020000802040000,0x0a04000000000000,0x0020000000180008,0x1704002419030024\n"
".quad 0x000600000000000c,0x17040011f0000020,0x000500000000000c,0x17040011f000001c\n"
".quad 0x000400000000000c,0x17040011f0000018,0x000300000000000c,0x17040011f0000014\n"
".quad 0x000200000000000c,0x17040011f0000010,0x000100000000000c,0x17040021f0000008\n"
".quad 0x000000000000000c,0x0d040021f0000000,0x0002000200180008,0x440400005de40000\n"
".quad 0x000094001c042800,0x000084009c042c00,0x400020001ca32c00,0x4000e001dc032004\n"
".quad 0x0000000001e71b0e,0x4000d0009de48000,0x4000c001dde42800,0x4000c1219f842800\n"
".quad 0xc00004221c031c00,0xfffffc715c035800,0xc0000471dc034800,0x000021209f845800\n"
".quad 0x00000880dc031c00,0xfffffc809c036800,0x00000c011c034800,0x00000800dc037800\n"
".quad 0x4000c0609c036800,0x000010001c036800,0x0000fc31dc235800,0x000008009c03190e\n"
".quad 0x000014031c037800,0x000008001c036800,0x00001cc3dc035800,0x0000000005e71a00\n"
".quad 0x4000f0009de48000,0x4000c0c19e032800,0x4000d0229c034800,0x4000c0a25ca34800\n"
".quad 0x000028c09ca35000,0x000000909ca32006,0xc000fc211c862004,0x4000d033de039000\n"
".quad 0x000018c2dc234800,0x000000909ca33118,0x000028b09ca3201e,0xc000fc219c862004\n"
".quad 0x00000d209c049000,0x4000c0045ca31800,0x400080049de42018,0x400100209c002800\n"
".quad 0x00003c33dc045800,0x000028c31ca32000,0x000008009c005000,0x000004241c006000\n"
".quad 0x000000209c00c800,0x00001c535c00c800,0x000018439c005000,0x000018411d005000\n"
".quad 0x000008d19c005000,0x000040d35c005800,0x00001c51dd005800,0x000040419e005000\n"
".quad 0x4000d1141ca3300c,0x000008435c002006,0x000018e11d00301a,0xc0002100dc435000\n"
".quad 0xc00021009c035000,0x4000c0041ca32025,0x00001cd15c002016,0x40009030dc435000\n"
".quad 0x4000d103dca34800,0x000018e19c00201e,0x000000211ca55000,0xc00020f39c039400\n"
".quad 0xc00020f3dc432025,0x00001cd1dd005000,0x000000915ca35000,0x400090f3dc435000\n"
".quad 0x4000d1145ca34800,0x000028b11ca35000,0x4000d1001ca35000,0x000000e19ca55000\n"
".quad 0x0000000021e79400,0x000020c09c038000,0x000014209c034800,0xc000fc209c864800\n"
".quad 0x000020515c039000,0x000010511c034800,0xc000fc411c864800,0x000021119c039000\n"
".quad 0x400080029de44800,0x000020025c032800,0xc00020601c434800,0xc00020619c035000\n"
".quad 0x400103f1dc002015,0x00000002dde2208e,0x40009001dc431afe,0xc00020921c034800\n"
".quad 0xc00020901c432015,0x00000002c1e25000,0x400090025c4318fe,0x000014331c004800\n"
".quad 0x000010229d005000,0x000010201c005000,0x0000fcc35c005000,0x00002cc09c005800\n"
".quad 0x00002ca11e005800,0x00001432dd00301a,0x0000fca15c005000,0x000010009d003004\n"
".quad 0x000010011c005000,0x00002c50dc005000,0x00002c515d005000,0x000000609ca55000\n"
".quad 0x000000811ca59400,0x000000001de79400,0x0000000000008000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0204000000000000,0x0000000000200008\n"
".quad 0x001500080a040000,0x1903002400200000,0x0000000c17040024,0xf000002000060000\n"
".quad 0x0000000c17040011,0xf000001c00050000,0x0000000c17040011,0xf000001800040000\n"
".quad 0x0000000c17040011,0xf000001400030000,0x0000000c17040011,0xf000001000020000\n"
".quad 0x0000000c17040011,0xf000000800010000,0x0000000c17040021,0xf000000000000000\n"
".quad 0x002400080d040021,0x5de4000000030003,0xdc04280044040000,0x1c042c0000009400\n"
".quad 0x1c042c0000008401,0x9c042c0000009800,0xdca32c0000008800,0x9ca3200840002030\n"
".quad 0xdc23200440003000,0xdc23188e4000f031,0x00a318804000e021,0x408620064000f020\n"
".quad 0x010390004000fc01,0xc103480040010020,0x8023480040011030,0x00235800c0007c00\n"
".quad 0x80035800c0007c31,0x000368004000c020,0x8003480000000020,0x00a368004000d040\n"
".quad 0xc1e420064000d000,0x0003280040008000,0x80a3480000000800,0x00e32007c0001000\n"
".quad 0xc0435000c0001000,0x4085480040009000,0x1de7940000000021,0x0000800000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0204000000000000,0x00000000001f0008,0x001300080a040000,0x1903002800200000\n"
".quad 0x0000000c17040028,0xf000002400070000,0x0000000c17040011,0xf000002000060000\n"
".quad 0x0000000c17040011,0xf000001c00050000,0x0000000c17040011,0xf000001800040000\n"
".quad 0x0000000c17040011,0xf000001400030000,0x0000000c17040011,0xf000001000020000\n"
".quad 0x0000000c17040011,0xf000000800010000,0x0000000c17040021,0xf000000000000000\n"
".quad 0x000c00080d040021,0x5de4000000010001,0x1c04280044040000,0x9c042c0000009400\n"
".quad 0x1ca32c0000008400,0xdc23200440002000,0xa1e7188e4000c001,0x81e240000001e000\n"
".quad 0xc0e3180000002000,0x00a35000c0002000,0x404320058000a002,0x80a348004000b032\n"
".quad 0x00a5200580008000,0xc043840000000081,0x80a5480040009030,0x0000840000000021\n"
".quad 0x0000580000001840,0x0200580000001c41,0x0000300000001c50,0x8000300800001851\n"
".quad 0xc00058004000d001,0x80a558004000d041,0x1de7940000000021,0x0000800000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0a04000000000000,0x0020000000160008\n"
".quad 0x1704001819030018,0x000300000000000c,0x17040011f0000014,0x000200000000000c\n"
".quad 0x17040011f0000010,0x000100000000000c,0x17040021f0000008,0x000000000000000c\n"
".quad 0x0d040021f0000000,0x00010001000c0008,0x0021001007040000,0xffffffffffff0000\n"
".quad 0x0704ffffffffffff,0xffff000000200010,0xffffffffffffffff,0x001f00100704ffff\n"
".quad 0xffffffffffff0000,0x1204ffffffffffff,0x00000000001e0008,0x001e000811040000\n"
".quad 0x1204000000000000,0x00000000001d0008,0x001d000811040000,0x1204000000000000\n"
".quad 0x00000000001c0008,0x001c000811040000,0x1204000000000000,0x00000000001b0008\n"
".quad 0x001b000811040000,0x1204000000000000,0x00000000001a0008,0x001a000811040000\n"
".quad 0x1204000000000000,0x0000000000190008,0x0019000811040000,0x0600000000000000\n"
".quad 0xe400000005000000,0x0000000000000022,0x0000000000000000,0x8800000000000000\n"
".quad 0x8800000000000001,0x0400000000000001,0x0000000000000000,0x1b00001e05600000\n"
".quad 0x000000000000000e,0x0000000000000000,0x7000000000000000,0x7000000000000006\n"
".quad 0x0400000000000006,0x0000000000000000,0x8b00001d05600000,0x0000000000000014\n"
".quad 0x0000000000000000,0x2000000000000000,0x2000000000000002,0x0400000000000002\n"
".quad 0x0000000000000000,0xab00001c05600000,0x0000000000000016,0x0000000000000000\n"
".quad 0x3400000000000000,0x3400000000000004,0x0400000000000004,0x0000000000000000\n"
".quad 0xdf00001b05600000,0x000000000000001a,0x0000000000000000,0x3400000000000000\n"
".quad 0x3400000000000004,0x0400000000000004,0x0000000000000000,0x1300001a05600000\n"
".quad 0x000000000000001f,0x0000000000000000,0xc000000000000000,0xc000000000000001\n"
".quad 0x0400000000000001,0x0000000000000000,0xd300001905600000,0x0000000000000020\n"
".quad 0x0000000000000000,0x4400000000000000,0x4400000000000001,0x0400000000000001\n"
".quad 0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long fatbinData[4173];

}


extern "C" {

static const struct {int m; int v; const unsigned long long* d; char* f;} __fatDeviceText __attribute__ ((aligned (8))) __attribute__ ((section (".nvFatBinSegment")))=
 { 0x466243b1, 1, fatbinData, 0 };

}
# 3 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c" 2 3
extern void __device_stub__Z16padKernel_kernelPfS_iiiiii(float *, float *, int, int, int, int, int, int);
extern void __device_stub__Z27padDataClampToBorder_kernelPfS_iiiiiiii(float *, float *, int, int, int, int, int, int, int, int);
extern void __device_stub__Z27modulateAndNormalize_kernelP6float2S0_if(fComplex *, fComplex *, int, float);
extern void __device_stub__Z22spPostprocess2D_kernelP6float2S0_jjjjf(fComplex *, fComplex *, uint, uint, uint, uint, float);
extern void __device_stub__Z21spPreprocess2D_kernelP6float2S0_jjjjf(fComplex *, fComplex *, uint, uint, uint, uint, float);
extern void __device_stub__Z18spProcess2D_kernelP6float2S0_S0_jjjff(fComplex *, fComplex *, fComplex *, uint, uint, uint, float, float);
static void __sti____cudaRegisterAll_51_tmpxft_00006c6a_00000000_4_convolutionFFT2D_cpp1_ii_texFloat(void) __attribute__((__constructor__));
void __device_stub__Z16padKernel_kernelPfS_iiiiii(float *__par0, float *__par1, int __par2, int __par3, int __par4, int __par5, int __par6, int __par7){if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)20UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par4, sizeof(__par4), (size_t)24UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par5, sizeof(__par5), (size_t)28UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par6, sizeof(__par6), (size_t)32UL) != cudaSuccess) return;if (cudaSetupArgument((void *)(char *)&__par7, sizeof(__par7), (size_t)36UL) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, int, int, int, int, int, int))padKernel_kernel)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, int, int, int, int, int, int))padKernel_kernel))); };}
# 31 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void padKernel_kernel( float *__cuda_0,float *__cuda_1,int __cuda_2,int __cuda_3,int __cuda_4,int __cuda_5,int __cuda_6,int __cuda_7)
# 40 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
{__device_stub__Z16padKernel_kernelPfS_iiiiii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);
# 49 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
}
# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"
void __device_stub__Z27padDataClampToBorder_kernelPfS_iiiiiiii( float *__par0, float *__par1, int __par2, int __par3, int __par4, int __par5, int __par6, int __par7, int __par8, int __par9) { if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)20UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par4, sizeof(__par4), (size_t)24UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par5, sizeof(__par5), (size_t)28UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par6, sizeof(__par6), (size_t)32UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par7, sizeof(__par7), (size_t)36UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par8, sizeof(__par8), (size_t)40UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par9, sizeof(__par9), (size_t)44UL) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, int, int, int, int, int, int, int, int))padDataClampToBorder_kernel)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, int, int, int, int, int, int, int, int))padDataClampToBorder_kernel))); }; }
# 56 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void padDataClampToBorder_kernel( float *__cuda_0,float *__cuda_1,int __cuda_2,int __cuda_3,int __cuda_4,int __cuda_5,int __cuda_6,int __cuda_7,int __cuda_8,int __cuda_9)
# 67 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
{__device_stub__Z27padDataClampToBorder_kernelPfS_iiiiiiii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9);
# 85 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
}
# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"
void __device_stub__Z27modulateAndNormalize_kernelP6float2S0_if( fComplex *__par0, fComplex *__par1, int __par2, float __par3) { if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)20UL) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(fComplex *, fComplex *, int, float))modulateAndNormalize_kernel)); (void)cudaLaunch(((char *)((void ( *)(fComplex *, fComplex *, int, float))modulateAndNormalize_kernel))); }; }
# 98 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void modulateAndNormalize_kernel( fComplex *__cuda_0,fComplex *__cuda_1,int __cuda_2,float __cuda_3)
# 103 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
{__device_stub__Z27modulateAndNormalize_kernelP6float2S0_if( __cuda_0,__cuda_1,__cuda_2,__cuda_3);
# 114 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
}
# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"
void __device_stub__Z22spPostprocess2D_kernelP6float2S0_jjjjf( fComplex *__par0, fComplex *__par1, uint __par2, uint __par3, uint __par4, uint __par5, float __par6) { if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)20UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par4, sizeof(__par4), (size_t)24UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par5, sizeof(__par5), (size_t)28UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par6, sizeof(__par6), (size_t)32UL) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(fComplex *, fComplex *, uint, uint, uint, uint, float))spPostprocess2D_kernel)); (void)cudaLaunch(((char *)((void ( *)(fComplex *, fComplex *, uint, uint, uint, uint, float))spPostprocess2D_kernel))); }; }
# 195 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void spPostprocess2D_kernel( fComplex *__cuda_0,fComplex *__cuda_1,uint __cuda_2,uint __cuda_3,uint __cuda_4,uint __cuda_5,float __cuda_6)
# 203 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
{__device_stub__Z22spPostprocess2D_kernelP6float2S0_jjjjf( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 250 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
}
# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"
void __device_stub__Z21spPreprocess2D_kernelP6float2S0_jjjjf( fComplex *__par0, fComplex *__par1, uint __par2, uint __par3, uint __par4, uint __par5, float __par6) { if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)20UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par4, sizeof(__par4), (size_t)24UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par5, sizeof(__par5), (size_t)28UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par6, sizeof(__par6), (size_t)32UL) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(fComplex *, fComplex *, uint, uint, uint, uint, float))spPreprocess2D_kernel)); (void)cudaLaunch(((char *)((void ( *)(fComplex *, fComplex *, uint, uint, uint, uint, float))spPreprocess2D_kernel))); }; }
# 252 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void spPreprocess2D_kernel( fComplex *__cuda_0,fComplex *__cuda_1,uint __cuda_2,uint __cuda_3,uint __cuda_4,uint __cuda_5,float __cuda_6)
# 260 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
{__device_stub__Z21spPreprocess2D_kernelP6float2S0_jjjjf( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 311 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
}
# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"
void __device_stub__Z18spProcess2D_kernelP6float2S0_S0_jjjff( fComplex *__par0, fComplex *__par1, fComplex *__par2, uint __par3, uint __par4, uint __par5, float __par6, float __par7) { if (cudaSetupArgument((void *)(char *)&__par0, sizeof(__par0), (size_t)0UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par1, sizeof(__par1), (size_t)8UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par2, sizeof(__par2), (size_t)16UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par3, sizeof(__par3), (size_t)24UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par4, sizeof(__par4), (size_t)28UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par5, sizeof(__par5), (size_t)32UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par6, sizeof(__par6), (size_t)36UL) != cudaSuccess) return; if (cudaSetupArgument((void *)(char *)&__par7, sizeof(__par7), (size_t)40UL) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(fComplex *, fComplex *, fComplex *, uint, uint, uint, float, float))spProcess2D_kernel)); (void)cudaLaunch(((char *)((void ( *)(fComplex *, fComplex *, fComplex *, uint, uint, uint, float, float))spProcess2D_kernel))); }; }
# 318 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
void spProcess2D_kernel( fComplex *__cuda_0,fComplex *__cuda_1,fComplex *__cuda_2,uint __cuda_3,uint __cuda_4,uint __cuda_5,float __cuda_6,float __cuda_7)
# 327 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
{__device_stub__Z18spProcess2D_kernelP6float2S0_S0_jjjff( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);
# 384 "tests/convolutionFFT2D/convolutionFFT2D.cuh"
}
# 1 "/tmp/tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"
static void __sti____cudaRegisterAll_51_tmpxft_00006c6a_00000000_4_convolutionFFT2D_cpp1_ii_texFloat(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(fComplex *, fComplex *, fComplex *, uint, uint, uint, float, float))spProcess2D_kernel), (char*)"_Z18spProcess2D_kernelP6float2S0_S0_jjjff", "_Z18spProcess2D_kernelP6float2S0_S0_jjjff", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(fComplex *, fComplex *, uint, uint, uint, uint, float))spPreprocess2D_kernel), (char*)"_Z21spPreprocess2D_kernelP6float2S0_jjjjf", "_Z21spPreprocess2D_kernelP6float2S0_jjjjf", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(fComplex *, fComplex *, uint, uint, uint, uint, float))spPostprocess2D_kernel), (char*)"_Z22spPostprocess2D_kernelP6float2S0_jjjjf", "_Z22spPostprocess2D_kernelP6float2S0_jjjjf", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(fComplex *, fComplex *, int, float))modulateAndNormalize_kernel), (char*)"_Z27modulateAndNormalize_kernelP6float2S0_if", "_Z27modulateAndNormalize_kernelP6float2S0_if", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, int, int, int, int, int, int, int, int))padDataClampToBorder_kernel), (char*)"_Z27padDataClampToBorder_kernelPfS_iiiiiiii", "_Z27padDataClampToBorder_kernelPfS_iiiiiiii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, int, int, int, int, int, int))padKernel_kernel), (char*)"_Z16padKernel_kernelPfS_iiiiii", "_Z16padKernel_kernelPfS_iiiiii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&texFloat, (const void**)"texFloat", "texFloat", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&texComplexA, (const void**)"texComplexA", "texComplexA", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&texComplexB, (const void**)"texComplexB", "texComplexB", 1, 0, 0); }
# 2 "tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c" 2
# 1 "tmpxft_00006c6a_00000000-1_convolutionFFT2D.cudafe1.stub.c"

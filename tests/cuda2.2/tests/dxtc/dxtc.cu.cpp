# 1 "/tmp/tmpxft_00003c13_00000000-1_dxtc.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00003c13_00000000-1_dxtc.cudafe1.cpp"
# 1 "dxtc.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1 3
# 108 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 1 3
# 53 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 54 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 2 3
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
# 91 "/usr/local/cuda/bin/../include/driver_types.h" 3
enum cudaError
{
  cudaSuccess = 0,
  cudaErrorMissingConfiguration = 1,
  cudaErrorMemoryAllocation = 2,
  cudaErrorInitializationError = 3,
  cudaErrorLaunchFailure = 4,
  cudaErrorPriorLaunchFailure = 5,
  cudaErrorLaunchTimeout = 6,
  cudaErrorLaunchOutOfResources = 7,
  cudaErrorInvalidDeviceFunction = 8,
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
  cudaErrorAddressOfConstant = 22,
  cudaErrorTextureFetchFailed = 23,
  cudaErrorTextureNotBound = 24,
  cudaErrorSynchronizationError = 25,
  cudaErrorInvalidFilterSetting = 26,
  cudaErrorInvalidNormSetting = 27,
  cudaErrorMixedDeviceExecution = 28,
  cudaErrorCudartUnloading = 29,
  cudaErrorUnknown = 30,
  cudaErrorNotYetImplemented = 31,
  cudaErrorMemoryValueTooLarge = 32,
  cudaErrorInvalidResourceHandle = 33,
  cudaErrorNotReady = 34,
  cudaErrorInsufficientDriver = 35,
  cudaErrorSetOnActiveProcess = 36,
  cudaErrorInvalidSurface = 37,
  cudaErrorNoDevice = 38,
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
  cudaGraphicsRegisterFlagsNone = 0,
};





enum cudaGraphicsMapFlags
{
  cudaGraphicsMapFlagsNone = 0,
  cudaGraphicsMapFlagsReadOnly = 1,
  cudaGraphicsMapFlagsWriteDiscard = 2,
};





enum cudaGraphicsCubeFace {
  cudaGraphicsCubeFacePositiveX = 0x00,
  cudaGraphicsCubeFaceNegativeX = 0x01,
  cudaGraphicsCubeFacePositiveY = 0x02,
  cudaGraphicsCubeFaceNegativeY = 0x03,
  cudaGraphicsCubeFacePositiveZ = 0x04,
  cudaGraphicsCubeFaceNegativeZ = 0x05,
};





struct cudaFuncAttributes
{
   size_t sharedSizeBytes;
   size_t constSizeBytes;
   size_t localSizeBytes;
   int maxThreadsPerBlock;
   int numRegs;
   int __cudaReserved[8];
};





enum cudaComputeMode
{
  cudaComputeModeDefault = 0,
  cudaComputeModeExclusive = 1,
  cudaComputeModeProhibited = 2
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
  int __cudaReserved[36];
};
# 361 "/usr/local/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef int cudaStream_t;





typedef int cudaEvent_t;
# 44 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/surface_types.h" 1 3
# 54 "/usr/local/cuda/bin/../include/surface_types.h" 3
enum cudaSurfaceBounderyMode
{
  cudaBounderyModeZero = 0,
  cudaBounderyModeClamp = 1,
  cudaBounderyModeTrap = 2
};


enum cudaSurfaceFormatMode
{
  cudaFormatModeForced,
  cudaFormatModeAuto
};


struct surfaceReference
{
  struct cudaChannelFormatDesc channelDesc;
};
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_types.h" 1 3
# 54 "/usr/local/cuda/bin/../include/texture_types.h" 3
enum cudaTextureAddressMode
{
  cudaAddressModeWrap,
  cudaAddressModeClamp
};


enum cudaTextureFilterMode
{
  cudaFilterModePoint,
  cudaFilterModeLinear
};


enum cudaTextureReadMode
{
  cudaReadModeElementType,
  cudaReadModeNormalizedFloat
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
# 82 "/usr/local/cuda/bin/../include/vector_types.h" 3
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


struct __attribute__((aligned(8))) short4 { short x, y, z, w; };


struct __attribute__((aligned(8))) ushort4 { unsigned short x, y, z, w; };


struct int1
{
  int x;
 
};


struct uint1
{
  unsigned int x;
 
};


struct __attribute__((aligned(8))) int2 { int x, y; };


struct __attribute__((aligned(8))) uint2 { unsigned int x, y; };


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
# 258 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct __attribute__((aligned(2*sizeof(long int)))) long2
{
  long int x, y;
 
};


struct __attribute__((aligned(2*sizeof(unsigned long int)))) ulong2
{
  unsigned long int x, y;
 
};
# 306 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct float1
{
  float x;
 
};


struct __attribute__((aligned(8))) float2 { float x, y; };


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


struct double1
{
  double x;
 
};


struct __attribute__((aligned(16))) double2
{
  double x, y;
 
};
# 378 "/usr/local/cuda/bin/../include/vector_types.h" 3
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
# 448 "/usr/local/cuda/bin/../include/vector_types.h" 3
typedef struct float1 float1;

typedef struct float2 float2;

typedef struct float3 float3;

typedef struct float4 float4;

typedef struct longlong1 longlong1;

typedef struct ulonglong1 ulonglong1;

typedef struct longlong2 longlong2;

typedef struct ulonglong2 ulonglong2;

typedef struct double1 double1;

typedef struct double2 double2;
# 475 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 55 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 80 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern "C" {
# 89 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc3D(struct cudaPitchedPtr* pitchedDevPtr, struct cudaExtent extent);
extern cudaError_t cudaMalloc3DArray(struct cudaArray** arrayPtr, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent);
extern cudaError_t cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent);
extern cudaError_t cudaMemcpy3D(const struct cudaMemcpy3DParms *p);
extern cudaError_t cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream);







extern cudaError_t cudaMalloc(void **devPtr, size_t size);
extern cudaError_t cudaMallocHost(void **ptr, size_t size);
extern cudaError_t cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);
extern cudaError_t cudaMallocArray(struct cudaArray **array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height );
extern cudaError_t cudaFree(void *devPtr);
extern cudaError_t cudaFreeHost(void *ptr);
extern cudaError_t cudaFreeArray(struct cudaArray *array);

extern cudaError_t cudaHostAlloc(void **pHost, size_t bytes, unsigned int flags);
extern cudaError_t cudaHostGetDevicePointer(void **pDevice, void *pHost, unsigned int flags);
extern cudaError_t cudaHostGetFlags(unsigned int *pFlags, void *pHost);







extern cudaError_t cudaMemGetInfo(size_t *free, size_t *total);
extern cudaError_t cudaMemcpy(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyFromArray(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpy2D(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DFromArray(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpyToSymbol(const char *symbol, const void *src, size_t count, size_t offset , enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpyFromSymbol(void *dst, const char *symbol, size_t count, size_t offset , enum cudaMemcpyKind kind );







extern cudaError_t cudaMemcpyAsync(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyFromArrayAsync(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DAsync(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DFromArrayAsync(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyToSymbolAsync(const char *symbol, const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyFromSymbolAsync(void *dst, const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream);







extern cudaError_t cudaMemset(void *devPtr, int value, size_t count);
extern cudaError_t cudaMemset2D(void *devPtr, size_t pitch, int value, size_t width, size_t height);







extern cudaError_t cudaGetSymbolAddress(void **devPtr, const char *symbol);
extern cudaError_t cudaGetSymbolSize(size_t *size, const char *symbol);







extern cudaError_t cudaGetDeviceCount(int *count);
extern cudaError_t cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device);
extern cudaError_t cudaChooseDevice(int *device, const struct cudaDeviceProp *prop);
extern cudaError_t cudaSetDevice(int device);
extern cudaError_t cudaGetDevice(int *device);
extern cudaError_t cudaSetValidDevices(int *device_arr, int len);
extern cudaError_t cudaSetDeviceFlags( int flags );







extern cudaError_t cudaBindTexture(size_t *offset, const struct textureReference *texref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size );
extern cudaError_t cudaBindTexture2D(size_t *offset,const struct textureReference *texref,const void *devPtr, const struct cudaChannelFormatDesc *desc,size_t width, size_t height, size_t pitch);
extern cudaError_t cudaBindTextureToArray(const struct textureReference *texref, const struct cudaArray *array, const struct cudaChannelFormatDesc *desc);
extern cudaError_t cudaUnbindTexture(const struct textureReference *texref);
extern cudaError_t cudaGetTextureAlignmentOffset(size_t *offset, const struct textureReference *texref);
extern cudaError_t cudaGetTextureReference(const struct textureReference **texref, const char *symbol);







extern cudaError_t cudaBindSurfaceToAddr(size_t *offset, const struct surfaceReference *surfref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size );
extern cudaError_t cudaBindSurfaceToArray(const struct surfaceReference *surfref, const struct cudaArray *array, const struct cudaChannelFormatDesc *desc);
extern cudaError_t cudaGetSurfaceAlignmentOffset(size_t *offset, const struct surfaceReference *surfref);
extern cudaError_t cudaGetSurfaceReference(const struct surfaceReference **surfref, const char *symbol);







extern cudaError_t cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, const struct cudaArray *array);
extern struct cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, enum cudaChannelFormatKind f);







extern cudaError_t cudaGetLastError(void);
extern const char* cudaGetErrorString(cudaError_t error);







extern cudaError_t cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem , cudaStream_t stream );
extern cudaError_t cudaSetupArgument(const void *arg, size_t size, size_t offset);
extern cudaError_t cudaLaunch(const char *entry);
extern cudaError_t cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const char *func);







extern cudaError_t cudaStreamCreate(cudaStream_t *pStream);
extern cudaError_t cudaStreamDestroy(cudaStream_t stream);
extern cudaError_t cudaStreamSynchronize(cudaStream_t stream);
extern cudaError_t cudaStreamQuery(cudaStream_t stream);







extern cudaError_t cudaEventCreate(cudaEvent_t *event);
extern cudaError_t cudaEventCreateWithFlags(cudaEvent_t *event, int flags);
extern cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream);
extern cudaError_t cudaEventQuery(cudaEvent_t event);
extern cudaError_t cudaEventSynchronize(cudaEvent_t event);
extern cudaError_t cudaEventDestroy(cudaEvent_t event);
extern cudaError_t cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end);







extern cudaError_t cudaSetDoubleForDevice(double *d);
extern cudaError_t cudaSetDoubleForHost(double *d);







extern cudaError_t cudaThreadExit(void);
extern cudaError_t cudaThreadSynchronize(void);







extern cudaError_t cudaDriverGetVersion(int *driverVersion);
extern cudaError_t cudaRuntimeGetVersion(int *runtimeVersion);







extern cudaError_t cudaGraphicsUnregisterResource(struct cudaGraphicsResource *resource);
extern cudaError_t cudaGraphicsResourceSetMapFlags(struct cudaGraphicsResource *resource, unsigned int flags);
extern cudaError_t cudaGraphicsMapResources(int count, struct cudaGraphicsResource **resources, cudaStream_t stream);
extern cudaError_t cudaGraphicsUnmapResources(int count, struct cudaGraphicsResource **resources, cudaStream_t stream);
extern cudaError_t cudaGraphicsResourceGetMappedPointer(void **devPtr, size_t *size, struct cudaGraphicsResource *resource);
extern cudaError_t cudaGraphicsSubResourceGetMappedArray(struct cudaArray **arrayPtr, struct cudaGraphicsResource *resource, unsigned int arrayIndex, unsigned int mipLevel);


}
# 109 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/storage_class.h" 1 3
# 110 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 213 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 2 3
# 91 "/usr/local/cuda/bin/../include/driver_types.h"
# 140 "/usr/local/cuda/bin/../include/driver_types.h"
# 152 "/usr/local/cuda/bin/../include/driver_types.h"
# 165 "/usr/local/cuda/bin/../include/driver_types.h"
# 171 "/usr/local/cuda/bin/../include/driver_types.h"
# 184 "/usr/local/cuda/bin/../include/driver_types.h"
# 197 "/usr/local/cuda/bin/../include/driver_types.h"
# 209 "/usr/local/cuda/bin/../include/driver_types.h"
# 220 "/usr/local/cuda/bin/../include/driver_types.h"
# 238 "/usr/local/cuda/bin/../include/driver_types.h"
# 244 "/usr/local/cuda/bin/../include/driver_types.h"
# 253 "/usr/local/cuda/bin/../include/driver_types.h"
# 264 "/usr/local/cuda/bin/../include/driver_types.h"
# 277 "/usr/local/cuda/bin/../include/driver_types.h"
# 291 "/usr/local/cuda/bin/../include/driver_types.h"
# 302 "/usr/local/cuda/bin/../include/driver_types.h"
# 361 "/usr/local/cuda/bin/../include/driver_types.h"
# 367 "/usr/local/cuda/bin/../include/driver_types.h"
# 373 "/usr/local/cuda/bin/../include/driver_types.h"
# 54 "/usr/local/cuda/bin/../include/surface_types.h"
# 62 "/usr/local/cuda/bin/../include/surface_types.h"
# 69 "/usr/local/cuda/bin/../include/surface_types.h"
# 54 "/usr/local/cuda/bin/../include/texture_types.h"
# 61 "/usr/local/cuda/bin/../include/texture_types.h"
# 68 "/usr/local/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda/bin/../include/texture_types.h"
# 82 "/usr/local/cuda/bin/../include/vector_types.h"
# 89 "/usr/local/cuda/bin/../include/vector_types.h"
# 96 "/usr/local/cuda/bin/../include/vector_types.h"
# 103 "/usr/local/cuda/bin/../include/vector_types.h"
# 110 "/usr/local/cuda/bin/../include/vector_types.h"
# 117 "/usr/local/cuda/bin/../include/vector_types.h"
# 124 "/usr/local/cuda/bin/../include/vector_types.h"
# 131 "/usr/local/cuda/bin/../include/vector_types.h"
# 138 "/usr/local/cuda/bin/../include/vector_types.h"
# 145 "/usr/local/cuda/bin/../include/vector_types.h"
# 152 "/usr/local/cuda/bin/../include/vector_types.h"
# 159 "/usr/local/cuda/bin/../include/vector_types.h"
# 166 "/usr/local/cuda/bin/../include/vector_types.h"
# 173 "/usr/local/cuda/bin/../include/vector_types.h"
# 180 "/usr/local/cuda/bin/../include/vector_types.h"
# 183 "/usr/local/cuda/bin/../include/vector_types.h"
# 186 "/usr/local/cuda/bin/../include/vector_types.h"
# 193 "/usr/local/cuda/bin/../include/vector_types.h"
# 200 "/usr/local/cuda/bin/../include/vector_types.h"
# 203 "/usr/local/cuda/bin/../include/vector_types.h"
# 206 "/usr/local/cuda/bin/../include/vector_types.h"
# 213 "/usr/local/cuda/bin/../include/vector_types.h"
# 220 "/usr/local/cuda/bin/../include/vector_types.h"
# 227 "/usr/local/cuda/bin/../include/vector_types.h"
# 234 "/usr/local/cuda/bin/../include/vector_types.h"
# 241 "/usr/local/cuda/bin/../include/vector_types.h"
# 258 "/usr/local/cuda/bin/../include/vector_types.h"
# 265 "/usr/local/cuda/bin/../include/vector_types.h"
# 306 "/usr/local/cuda/bin/../include/vector_types.h"
# 313 "/usr/local/cuda/bin/../include/vector_types.h"
# 316 "/usr/local/cuda/bin/../include/vector_types.h"
# 323 "/usr/local/cuda/bin/../include/vector_types.h"
# 330 "/usr/local/cuda/bin/../include/vector_types.h"
# 337 "/usr/local/cuda/bin/../include/vector_types.h"
# 344 "/usr/local/cuda/bin/../include/vector_types.h"
# 351 "/usr/local/cuda/bin/../include/vector_types.h"
# 358 "/usr/local/cuda/bin/../include/vector_types.h"
# 365 "/usr/local/cuda/bin/../include/vector_types.h"
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
# 475 "/usr/local/cuda/bin/../include/vector_types.h"
# 486 "/usr/local/cuda/bin/../include/vector_types.h"
# 89 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
# 90 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent);
# 91 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 92 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 93 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t);
# 101 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 102 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 103 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 104 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (1));
# 105 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 106 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 107 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 109 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
# 110 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
# 111 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 119 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t *, size_t *);
# 120 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 121 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 122 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 123 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 124 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 125 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 126 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 127 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 128 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 129 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 137 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t);
# 138 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t);
# 139 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 140 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 141 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 142 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 143 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 144 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 152 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 153 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 161 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 162 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 170 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 171 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 172 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 173 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 174 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 175 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int *, int);
# 176 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(int);
# 184 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 185 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
# 186 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 187 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 188 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 189 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 197 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToAddr(size_t *, const surfaceReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 198 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 199 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceAlignmentOffset(size_t *, const surfaceReference *);
# 200 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference **, const char *);
# 208 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 209 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 217 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 218 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 226 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = 0);
# 227 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 228 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 229 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 237 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 238 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 239 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 240 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 248 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 249 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int);
# 250 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t);
# 251 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 252 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 253 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 254 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 262 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 263 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 271 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 272 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 280 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
# 281 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 289 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource *);
# 290 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource *, unsigned);
# 291 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int, cudaGraphicsResource **, cudaStream_t);
# 292 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int, cudaGraphicsResource **, cudaStream_t);
# 293 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void **, size_t *, cudaGraphicsResource *);
# 294 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray **, cudaGraphicsResource *, unsigned, unsigned);
# 93 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
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
# 54 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 55 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 56 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPitchedPtr s;
# 58 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 59 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 60 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 61 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 63 "/usr/local/cuda/bin/../include/driver_functions.h"
return s;
# 64 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 66 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 67 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 68 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPos p;
# 70 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 71 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 72 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 74 "/usr/local/cuda/bin/../include/driver_functions.h"
return p;
# 75 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 77 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 78 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 79 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaExtent e;
# 81 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 82 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 83 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 85 "/usr/local/cuda/bin/../include/driver_functions.h"
return e;
# 86 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 54 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 55 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 56 "/usr/local/cuda/bin/../include/vector_functions.h"
char1 t; (t.x) = x; return t;
# 57 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 59 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 60 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 61 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar1 t; (t.x) = x; return t;
# 62 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 64 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 65 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 66 "/usr/local/cuda/bin/../include/vector_functions.h"
char2 t; (t.x) = x; (t.y) = y; return t;
# 67 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 69 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 70 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 71 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar2 t; (t.x) = x; (t.y) = y; return t;
# 72 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 74 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 75 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 76 "/usr/local/cuda/bin/../include/vector_functions.h"
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 77 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 79 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 80 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 81 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 82 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 84 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 85 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 86 "/usr/local/cuda/bin/../include/vector_functions.h"
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 87 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 89 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 90 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 91 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 92 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 94 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short1 make_short1(short x)
# 95 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 96 "/usr/local/cuda/bin/../include/vector_functions.h"
short1 t; (t.x) = x; return t;
# 97 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 99 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 100 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 101 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort1 t; (t.x) = x; return t;
# 102 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 104 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 105 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 106 "/usr/local/cuda/bin/../include/vector_functions.h"
short2 t; (t.x) = x; (t.y) = y; return t;
# 107 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 109 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 110 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 111 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort2 t; (t.x) = x; (t.y) = y; return t;
# 112 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 114 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 115 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 116 "/usr/local/cuda/bin/../include/vector_functions.h"
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 117 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 119 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 120 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 121 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 122 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 124 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 125 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 126 "/usr/local/cuda/bin/../include/vector_functions.h"
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 127 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 129 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 130 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 131 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 132 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 134 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int1 make_int1(int x)
# 135 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 136 "/usr/local/cuda/bin/../include/vector_functions.h"
int1 t; (t.x) = x; return t;
# 137 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 139 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 140 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 141 "/usr/local/cuda/bin/../include/vector_functions.h"
uint1 t; (t.x) = x; return t;
# 142 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 144 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 145 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 146 "/usr/local/cuda/bin/../include/vector_functions.h"
int2 t; (t.x) = x; (t.y) = y; return t;
# 147 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 149 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 150 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 151 "/usr/local/cuda/bin/../include/vector_functions.h"
uint2 t; (t.x) = x; (t.y) = y; return t;
# 152 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 154 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 155 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 156 "/usr/local/cuda/bin/../include/vector_functions.h"
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 157 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 159 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 160 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 161 "/usr/local/cuda/bin/../include/vector_functions.h"
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 162 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 164 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 165 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 166 "/usr/local/cuda/bin/../include/vector_functions.h"
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 167 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 169 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 170 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 171 "/usr/local/cuda/bin/../include/vector_functions.h"
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 172 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 174 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long1 make_long1(long x)
# 175 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 176 "/usr/local/cuda/bin/../include/vector_functions.h"
long1 t; (t.x) = x; return t;
# 177 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 179 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 180 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 181 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong1 t; (t.x) = x; return t;
# 182 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 184 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 185 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 186 "/usr/local/cuda/bin/../include/vector_functions.h"
long2 t; (t.x) = x; (t.y) = y; return t;
# 187 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 189 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 190 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 191 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong2 t; (t.x) = x; (t.y) = y; return t;
# 192 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 218 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
# 219 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 220 "/usr/local/cuda/bin/../include/vector_functions.h"
float1 t; (t.x) = x; return t;
# 221 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 223 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 224 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 225 "/usr/local/cuda/bin/../include/vector_functions.h"
float2 t; (t.x) = x; (t.y) = y; return t;
# 226 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 228 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 229 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 230 "/usr/local/cuda/bin/../include/vector_functions.h"
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 231 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 233 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 234 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 235 "/usr/local/cuda/bin/../include/vector_functions.h"
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 236 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 238 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 239 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 240 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong1 t; (t.x) = x; return t;
# 241 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 243 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 244 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 245 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong1 t; (t.x) = x; return t;
# 246 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 248 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 249 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 250 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong2 t; (t.x) = x; (t.y) = y; return t;
# 251 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 253 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 254 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 255 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 256 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 258 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double1 make_double1(double x)
# 259 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 260 "/usr/local/cuda/bin/../include/vector_functions.h"
double1 t; (t.x) = x; return t;
# 261 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 263 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 264 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 265 "/usr/local/cuda/bin/../include/vector_functions.h"
double2 t; (t.x) = x; (t.y) = y; return t;
# 266 "/usr/local/cuda/bin/../include/vector_functions.h"
}
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
extern "C" __attribute__((__weak__)) clock_t clock() throw();
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
# 43 "/usr/include/string.h" 3
extern "C" void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 48 "/usr/include/string.h" 3
extern "C" void *memmove(void *, const void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 56 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 64 "/usr/include/string.h" 3
extern "C" void *memset(void *, int, size_t) throw() __attribute__((nonnull(1)));
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
# 56 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((__weak__)) clock_t clock() throw();
# 65 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
# 67 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));
# 69 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 71 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__));
# 73 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__));
# 76 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int min(int, int);
# 78 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned umin(unsigned, unsigned);
# 80 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llmin(long long, long long);
# 82 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned long long ullmin(unsigned long long, unsigned long long);
# 84 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fminf(float, float) throw();
# 86 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmin(double, double) throw();
# 89 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int max(int, int);
# 91 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned umax(unsigned, unsigned);
# 93 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llmax(long long, long long);
# 95 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned long long ullmax(unsigned long long, unsigned long long);
# 97 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw();
# 99 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmax(double, double) throw();
# 102 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sin(double) throw();
# 104 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinf(float) throw();
# 107 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cos(double) throw();
# 109 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float cosf(float) throw();
# 112 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw();
# 114 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();
# 117 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tan(double) throw();
# 119 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tanf(float) throw();
# 122 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sqrt(double) throw();
# 124 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sqrtf(float) throw();
# 127 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rsqrt(double);
# 129 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rsqrtf(float);
# 132 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp2(double) throw();
# 134 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float exp2f(float) throw();
# 137 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp10(double) throw();
# 139 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float exp10f(float) throw();
# 142 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double expm1(double) throw();
# 144 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float expm1f(float) throw();
# 147 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log2(double) throw();
# 149 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log2f(float) throw();
# 152 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log10(double) throw();
# 154 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log10f(float) throw();
# 157 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log(double) throw();
# 159 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float logf(float) throw();
# 162 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log1p(double) throw();
# 164 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log1pf(float) throw();
# 167 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__));
# 169 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__));
# 172 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp(double) throw();
# 174 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float expf(float) throw();
# 177 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cosh(double) throw();
# 179 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float coshf(float) throw();
# 182 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sinh(double) throw();
# 184 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinhf(float) throw();
# 187 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tanh(double) throw();
# 189 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tanhf(float) throw();
# 192 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double acosh(double) throw();
# 194 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float acoshf(float) throw();
# 197 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double asinh(double) throw();
# 199 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float asinhf(float) throw();
# 202 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atanh(double) throw();
# 204 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atanhf(float) throw();
# 207 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double ldexp(double, int) throw();
# 209 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw();
# 212 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double logb(double) throw();
# 214 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float logbf(float) throw();
# 217 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int ilogb(double) throw();
# 219 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int ilogbf(float) throw();
# 222 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double scalbn(double, int) throw();
# 224 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw();
# 227 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double scalbln(double, long) throw();
# 229 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw();
# 232 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double frexp(double, int *) throw();
# 234 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw();
# 237 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__));
# 239 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__));
# 242 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lround(double) throw();
# 244 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lroundf(float) throw();
# 247 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llround(double) throw();
# 249 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llroundf(float) throw();
# 252 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rint(double) throw();
# 254 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rintf(float) throw();
# 257 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lrint(double) throw();
# 259 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lrintf(float) throw();
# 262 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llrint(double) throw();
# 264 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llrintf(float) throw();
# 267 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nearbyint(double) throw();
# 269 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nearbyintf(float) throw();
# 272 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__));
# 274 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__));
# 277 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__));
# 279 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__));
# 282 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fdim(double, double) throw();
# 284 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fdimf(float, float) throw();
# 287 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atan2(double, double) throw();
# 289 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atan2f(float, float) throw();
# 292 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atan(double) throw();
# 294 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atanf(float) throw();
# 297 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double asin(double) throw();
# 299 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float asinf(float) throw();
# 302 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double acos(double) throw();
# 304 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float acosf(float) throw();
# 307 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double hypot(double, double) throw();
# 309 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float hypotf(float, float) throw();
# 312 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cbrt(double) throw();
# 314 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float cbrtf(float) throw();
# 317 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rcbrt(double);
# 319 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rcbrtf(float);
# 322 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sinpi(double);
# 324 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinpif(float);
# 327 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double pow(double, double) throw();
# 329 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float powf(float, float) throw();
# 332 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double modf(double, double *) throw();
# 334 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float modff(float, float *) throw();
# 337 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmod(double, double) throw();
# 339 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmodf(float, float) throw();
# 342 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double remainder(double, double) throw();
# 344 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float remainderf(float, float) throw();
# 347 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw();
# 349 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw();
# 352 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erf(double) throw();
# 354 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erff(float) throw();
# 357 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erfinv(double);
# 359 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erfinvf(float);
# 362 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erfc(double) throw();
# 364 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erfcf(float) throw();
# 367 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erfcinv(double);
# 369 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erfcinvf(float);
# 372 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double lgamma(double) throw();
# 374 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float lgammaf(float) throw();
# 377 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tgamma(double) throw();
# 379 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tgammaf(float) throw();
# 382 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__));
# 384 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__));
# 387 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__));
# 389 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__));
# 392 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__));
# 394 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__));
# 397 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));
# 399 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));
# 402 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));
# 404 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));
# 418 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));
# 420 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));
# 425 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fma(double, double, double) throw();
# 427 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw();
# 435 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));
# 437 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 447 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 31 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef float float_t; }
# 32 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double acos(double) throw(); extern "C" double __acos(double) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double asin(double) throw(); extern "C" double __asin(double) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double atan(double) throw(); extern "C" double __atan(double) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double atan2(double, double) throw(); extern "C" double __atan2(double, double) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double cos(double) throw(); extern "C" double __cos(double) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double sin(double) throw(); extern "C" double __sin(double) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double tan(double) throw(); extern "C" double __tan(double) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double cosh(double) throw(); extern "C" double __cosh(double) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double sinh(double) throw(); extern "C" double __sinh(double) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double tanh(double) throw(); extern "C" double __tanh(double) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw(); extern "C" void __sincos(double, double *, double *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double acosh(double) throw(); extern "C" double __acosh(double) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double asinh(double) throw(); extern "C" double __asinh(double) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double atanh(double) throw(); extern "C" double __atanh(double) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp(double) throw(); extern "C" double __exp(double) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double frexp(double, int *) throw(); extern "C" double __frexp(double, int *) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double ldexp(double, int) throw(); extern "C" double __ldexp(double, int) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double log(double) throw(); extern "C" double __log(double) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double log10(double) throw(); extern "C" double __log10(double) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double modf(double, double *) throw(); extern "C" double __modf(double, double *) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp10(double) throw(); extern "C" double __exp10(double) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" double pow10(double) throw(); extern "C" double __pow10(double) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double expm1(double) throw(); extern "C" double __expm1(double) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double log1p(double) throw(); extern "C" double __log1p(double) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double logb(double) throw(); extern "C" double __logb(double) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp2(double) throw(); extern "C" double __exp2(double) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double log2(double) throw(); extern "C" double __log2(double) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double pow(double, double) throw(); extern "C" double __pow(double, double) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double sqrt(double) throw(); extern "C" double __sqrt(double) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double hypot(double, double) throw(); extern "C" double __hypot(double, double) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double cbrt(double) throw(); extern "C" double __cbrt(double) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__)); extern "C" double __ceil(double) throw() __attribute__((__const__));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__)); extern "C" double __fabs(double) throw() __attribute__((__const__));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__)); extern "C" double __floor(double) throw() __attribute__((__const__));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fmod(double, double) throw(); extern "C" double __fmod(double, double) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinf(double) throw() __attribute__((__const__));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finite(double) throw() __attribute__((__const__));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" double drem(double, double) throw(); extern "C" double __drem(double, double) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" double significand(double) throw(); extern "C" double __significand(double) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__)); extern "C" double __copysign(double, double) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__)); extern "C" double __nan(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));
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
extern "C" __attribute__((__weak__)) double erf(double) throw(); extern "C" double __erf(double) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double erfc(double) throw(); extern "C" double __erfc(double) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double lgamma(double) throw(); extern "C" double __lgamma(double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double tgamma(double) throw(); extern "C" double __tgamma(double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" double lgamma_r(double, int *) throw(); extern "C" double __lgamma_r(double, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double rint(double) throw(); extern "C" double __rint(double) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__)); extern "C" double __nextafter(double, double) throw() __attribute__((__const__));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" double nexttoward(double, long double) throw() __attribute__((__const__)); extern "C" double __nexttoward(double, long double) throw() __attribute__((__const__));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double remainder(double, double) throw(); extern "C" double __remainder(double, double) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double scalbn(double, int) throw(); extern "C" double __scalbn(double, int) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int ilogb(double) throw(); extern "C" int __ilogb(double) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double scalbln(double, long) throw(); extern "C" double __scalbln(double, long) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double nearbyint(double) throw(); extern "C" double __nearbyint(double) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__)); extern "C" double __round(double) throw() __attribute__((__const__));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__)); extern "C" double __trunc(double) throw() __attribute__((__const__));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw(); extern "C" double __remquo(double, double, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lrint(double) throw(); extern "C" long __lrint(double) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long long llrint(double) throw(); extern "C" long long __llrint(double) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lround(double) throw(); extern "C" long __lround(double) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long long llround(double) throw(); extern "C" long long __llround(double) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fdim(double, double) throw(); extern "C" double __fdim(double, double) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fmax(double, double) throw(); extern "C" double __fmax(double, double) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fmin(double, double) throw(); extern "C" double __fmin(double, double) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassify(double) throw() __attribute__((__const__));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" int __signbit(double) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fma(double, double, double) throw(); extern "C" double __fma(double, double, double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" double scalb(double, double) throw(); extern "C" double __scalb(double, double) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float acosf(float) throw(); extern "C" float __acosf(float) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float asinf(float) throw(); extern "C" float __asinf(float) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float atanf(float) throw(); extern "C" float __atanf(float) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float atan2f(float, float) throw(); extern "C" float __atan2f(float, float) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float cosf(float) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float sinf(float) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float tanf(float) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float coshf(float) throw(); extern "C" float __coshf(float) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float sinhf(float) throw(); extern "C" float __sinhf(float) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float tanhf(float) throw(); extern "C" float __tanhf(float) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float acoshf(float) throw(); extern "C" float __acoshf(float) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float asinhf(float) throw(); extern "C" float __asinhf(float) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float atanhf(float) throw(); extern "C" float __atanhf(float) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float expf(float) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw(); extern "C" float __frexpf(float, int *) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw(); extern "C" float __ldexpf(float, int) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float logf(float) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float log10f(float) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float modff(float, float *) throw(); extern "C" float __modff(float, float *) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float exp10f(float) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" float pow10f(float) throw(); extern "C" float __pow10f(float) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float expm1f(float) throw(); extern "C" float __expm1f(float) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float log1pf(float) throw(); extern "C" float __log1pf(float) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float logbf(float) throw(); extern "C" float __logbf(float) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float exp2f(float) throw(); extern "C" float __exp2f(float) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float log2f(float) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float powf(float, float) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float sqrtf(float) throw(); extern "C" float __sqrtf(float) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float hypotf(float, float) throw(); extern "C" float __hypotf(float, float) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float cbrtf(float) throw(); extern "C" float __cbrtf(float) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__)); extern "C" float __ceilf(float) throw() __attribute__((__const__));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__)); extern "C" float __fabsf(float) throw() __attribute__((__const__));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__)); extern "C" float __floorf(float) throw() __attribute__((__const__));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fmodf(float, float) throw(); extern "C" float __fmodf(float, float) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinff(float) throw() __attribute__((__const__));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finitef(float) throw() __attribute__((__const__));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" float dremf(float, float) throw(); extern "C" float __dremf(float, float) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" float significandf(float) throw(); extern "C" float __significandf(float) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__)); extern "C" float __copysignf(float, float) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__)); extern "C" float __nanf(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));
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
extern "C" __attribute__((__weak__)) float erff(float) throw(); extern "C" float __erff(float) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float erfcf(float) throw(); extern "C" float __erfcf(float) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" float lgammaf_r(float, int *) throw(); extern "C" float __lgammaf_r(float, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float rintf(float) throw(); extern "C" float __rintf(float) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__)); extern "C" float __nextafterf(float, float) throw() __attribute__((__const__));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" float nexttowardf(float, long double) throw() __attribute__((__const__)); extern "C" float __nexttowardf(float, long double) throw() __attribute__((__const__));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float remainderf(float, float) throw(); extern "C" float __remainderf(float, float) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw(); extern "C" float __scalbnf(float, int) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int ilogbf(float) throw(); extern "C" int __ilogbf(float) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw(); extern "C" float __scalblnf(float, long) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float nearbyintf(float) throw(); extern "C" float __nearbyintf(float) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__)); extern "C" float __roundf(float) throw() __attribute__((__const__));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__)); extern "C" float __truncf(float) throw() __attribute__((__const__));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw(); extern "C" float __remquof(float, float, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lrintf(float) throw(); extern "C" long __lrintf(float) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long long llrintf(float) throw(); extern "C" long long __llrintf(float) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lroundf(float) throw(); extern "C" long __lroundf(float) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long long llroundf(float) throw(); extern "C" long long __llroundf(float) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fdimf(float, float) throw(); extern "C" float __fdimf(float, float) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw(); extern "C" float __fmaxf(float, float) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fminf(float, float) throw(); extern "C" float __fminf(float, float) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassifyf(float) throw() __attribute__((__const__));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" int __signbitf(float) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw(); extern "C" float __fmaf(float, float, float) throw();
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
extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
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
extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
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
extern "C" int __signbitl(long double) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fmal(long double, long double, long double) throw(); extern "C" long double __fmal(long double, long double, long double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalbl(long double, long double) throw(); extern "C" long double __scalbl(long double, long double) throw();
# 157 "/usr/include/math.h" 3
extern "C" { extern int signgam; }
# 199 "/usr/include/math.h" 3
enum {
# 200 "/usr/include/math.h" 3
FP_NAN,
# 202 "/usr/include/math.h" 3
FP_INFINITE,
# 204 "/usr/include/math.h" 3
FP_ZERO,
# 206 "/usr/include/math.h" 3
FP_SUBNORMAL,
# 208 "/usr/include/math.h" 3
FP_NORMAL
# 210 "/usr/include/math.h" 3
};
# 291 "/usr/include/math.h" 3
extern "C" { typedef
# 285 "/usr/include/math.h" 3
enum {
# 286 "/usr/include/math.h" 3
_IEEE_ = (-1),
# 287 "/usr/include/math.h" 3
_SVID_,
# 288 "/usr/include/math.h" 3
_XOPEN_,
# 289 "/usr/include/math.h" 3
_POSIX_,
# 290 "/usr/include/math.h" 3
_ISOC_
# 291 "/usr/include/math.h" 3
} _LIB_VERSION_TYPE; }
# 296 "/usr/include/math.h" 3
extern "C" { extern _LIB_VERSION_TYPE _LIB_VERSION; }
# 307 "/usr/include/math.h" 3
extern "C" { struct __exception {
# 312 "/usr/include/math.h" 3
int type;
# 313 "/usr/include/math.h" 3
char *name;
# 314 "/usr/include/math.h" 3
double arg1;
# 315 "/usr/include/math.h" 3
double arg2;
# 316 "/usr/include/math.h" 3
double retval;
# 317 "/usr/include/math.h" 3
}; }
# 320 "/usr/include/math.h" 3
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
__fd_mask fds_bits[((1024) / ((8) * sizeof(__fd_mask)))];
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
# 635 "/usr/include/stdlib.h" 3
extern "C" char *mkdtemp(char *) throw() __attribute__((nonnull(1)));
# 646 "/usr/include/stdlib.h" 3
extern "C" int mkostemp(char *, int) __attribute__((nonnull(1)));
# 656 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int) __attribute__((nonnull(1)));
# 666 "/usr/include/stdlib.h" 3
extern "C" int system(const char *);
# 673 "/usr/include/stdlib.h" 3
extern "C" char *canonicalize_file_name(const char *) throw() __attribute__((nonnull(1)));
# 683 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw();
# 691 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }
# 694 "/usr/include/stdlib.h" 3
extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 698 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 704 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(5)));
# 710 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 713 "/usr/include/stdlib.h" 3
extern "C" void qsort_r(void *, size_t, size_t, __compar_d_fn_t, void *) __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 720 "/usr/include/stdlib.h" 3
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
# 721 "/usr/include/stdlib.h" 3
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));
# 725 "/usr/include/stdlib.h" 3
extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 734 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) throw() __attribute__((__const__));
# 736 "/usr/include/stdlib.h" 3
extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__));
# 742 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__));
# 756 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 762 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 768 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double, int, char *) throw() __attribute__((nonnull(3)));
# 774 "/usr/include/stdlib.h" 3
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 777 "/usr/include/stdlib.h" 3
extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 780 "/usr/include/stdlib.h" 3
extern "C" char *qgcvt(long double, int, char *) throw() __attribute__((nonnull(3)));
# 786 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 789 "/usr/include/stdlib.h" 3
extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 793 "/usr/include/stdlib.h" 3
extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 797 "/usr/include/stdlib.h" 3
extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 808 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t) throw();
# 811 "/usr/include/stdlib.h" 3
extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 815 "/usr/include/stdlib.h" 3
extern "C" int wctomb(char *, wchar_t) throw();
# 819 "/usr/include/stdlib.h" 3
extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 822 "/usr/include/stdlib.h" 3
extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw();
# 833 "/usr/include/stdlib.h" 3
extern "C" int rpmatch(const char *) throw() __attribute__((nonnull(1)));
# 844 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 853 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char *) throw() __attribute__((nonnull(1)));
# 861 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int);
# 869 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int) throw();
# 873 "/usr/include/stdlib.h" 3
extern "C" int unlockpt(int) throw();
# 878 "/usr/include/stdlib.h" 3
extern "C" char *ptsname(int) throw();
# 885 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int, char *, size_t) throw() __attribute__((nonnull(2)));
# 889 "/usr/include/stdlib.h" 3
extern "C" int getpt();
# 896 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int) throw() __attribute__((nonnull(1)));
# 69 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 71 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Iterator, class _Container> class __normal_iterator;
# 74 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
}
# 76 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
namespace std __attribute__((visibility("default"))) {
# 78 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __true_type { };
# 79 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __false_type { };
# 81 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<bool __T0>
# 82 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __truth_type {
# 83 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type; };
# 86 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __truth_type< true> {
# 87 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type; };
# 91 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Sp, class _Tp>
# 92 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __traitor {
# 94 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = (((bool)_Sp::__value) || ((bool)_Tp::__value))};
# 95 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef typename __truth_type< __value> ::__type __type;
# 96 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 99 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class , class >
# 100 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __are_same {
# 102 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 103 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 104 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 106 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 107 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __are_same< _Tp, _Tp> {
# 109 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 110 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 111 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 114 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
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
template<class _Tp>
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
template<class _Tp>
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
template<class _Tp>
# 286 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_pointer {
# 288 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 289 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 290 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 292 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 293 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_pointer< _Tp *> {
# 295 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 296 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 297 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 302 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 303 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_normal_iterator {
# 305 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 306 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 307 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 309 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Iterator, class _Container>
# 310 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> > {
# 313 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 314 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 315 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 320 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 321 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> > {
# 323 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 328 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 329 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> > {
# 331 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 336 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 337 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> > {
# 339 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 344 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
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
template<class _Tp>
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
template<class _Tp>
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
template<bool __T1, class >
# 41 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __enable_if {
# 42 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 44 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp>
# 45 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __enable_if< true, _Tp> {
# 46 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Tp __type; };
# 50 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<bool _Cond, class _Iftrue, class _Iffalse>
# 51 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __conditional_type {
# 52 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Iftrue __type; };
# 54 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Iftrue, class _Iffalse>
# 55 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __conditional_type< false, _Iftrue, _Iffalse> {
# 56 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Iffalse __type; };
# 60 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp>
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
template<class _Tp>
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
template<class _Tp, bool __T2 = std::__is_integer< _Tp> ::__value>
# 159 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote {
# 160 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef double __type; };
# 162 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp>
# 163 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote< _Tp, false> {
# 164 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Tp __type; };
# 166 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp, class _Up>
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
template<class _Tp, class _Up, class _Vp>
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
template<class _Tp, class _Up, class _Vp, class _Wp>
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
# 489 "/usr/local/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {
# 491 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline long long abs(long long) __attribute__((visibility("default")));
# 492 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 494 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {
# 496 "/usr/local/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __pow_helper(T, int);
# 497 "/usr/local/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __cmath_power(T, unsigned);
# 498 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 500 "/usr/local/cuda/bin/../include/math_functions.h"
using std::abs;
# 501 "/usr/local/cuda/bin/../include/math_functions.h"
using std::fabs;
# 502 "/usr/local/cuda/bin/../include/math_functions.h"
using std::ceil;
# 503 "/usr/local/cuda/bin/../include/math_functions.h"
using std::floor;
# 504 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sqrt;
# 505 "/usr/local/cuda/bin/../include/math_functions.h"
using std::pow;
# 506 "/usr/local/cuda/bin/../include/math_functions.h"
using std::log;
# 507 "/usr/local/cuda/bin/../include/math_functions.h"
using std::log10;
# 508 "/usr/local/cuda/bin/../include/math_functions.h"
using std::fmod;
# 509 "/usr/local/cuda/bin/../include/math_functions.h"
using std::modf;
# 510 "/usr/local/cuda/bin/../include/math_functions.h"
using std::exp;
# 511 "/usr/local/cuda/bin/../include/math_functions.h"
using std::frexp;
# 512 "/usr/local/cuda/bin/../include/math_functions.h"
using std::ldexp;
# 513 "/usr/local/cuda/bin/../include/math_functions.h"
using std::asin;
# 514 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sin;
# 515 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sinh;
# 516 "/usr/local/cuda/bin/../include/math_functions.h"
using std::acos;
# 517 "/usr/local/cuda/bin/../include/math_functions.h"
using std::cos;
# 518 "/usr/local/cuda/bin/../include/math_functions.h"
using std::cosh;
# 519 "/usr/local/cuda/bin/../include/math_functions.h"
using std::atan;
# 520 "/usr/local/cuda/bin/../include/math_functions.h"
using std::atan2;
# 521 "/usr/local/cuda/bin/../include/math_functions.h"
using std::tan;
# 522 "/usr/local/cuda/bin/../include/math_functions.h"
using std::tanh;
# 576 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {
# 579 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline long abs(long) __attribute__((visibility("default")));
# 580 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float abs(float) __attribute__((visibility("default")));
# 581 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline double abs(double) __attribute__((visibility("default")));
# 582 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float fabs(float) __attribute__((visibility("default")));
# 583 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float ceil(float) __attribute__((visibility("default")));
# 584 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float floor(float) __attribute__((visibility("default")));
# 585 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sqrt(float) __attribute__((visibility("default")));
# 586 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float pow(float, float) __attribute__((visibility("default")));
# 587 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float pow(float, int) __attribute__((visibility("default")));
# 588 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline double pow(double, int) __attribute__((visibility("default")));
# 589 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float log(float) __attribute__((visibility("default")));
# 590 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float log10(float) __attribute__((visibility("default")));
# 591 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float fmod(float, float) __attribute__((visibility("default")));
# 592 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float modf(float, float *) __attribute__((visibility("default")));
# 593 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float exp(float) __attribute__((visibility("default")));
# 594 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float frexp(float, int *) __attribute__((visibility("default")));
# 595 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float ldexp(float, int) __attribute__((visibility("default")));
# 596 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float asin(float) __attribute__((visibility("default")));
# 597 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sin(float) __attribute__((visibility("default")));
# 598 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sinh(float) __attribute__((visibility("default")));
# 599 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float acos(float) __attribute__((visibility("default")));
# 600 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float cos(float) __attribute__((visibility("default")));
# 601 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float cosh(float) __attribute__((visibility("default")));
# 602 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float atan(float) __attribute__((visibility("default")));
# 603 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float atan2(float, float) __attribute__((visibility("default")));
# 604 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float tan(float) __attribute__((visibility("default")));
# 605 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float tanh(float) __attribute__((visibility("default")));
# 608 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 611 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float logb(float a)
# 612 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 613 "/usr/local/cuda/bin/../include/math_functions.h"
return logbf(a);
# 614 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 616 "/usr/local/cuda/bin/../include/math_functions.h"
static inline int ilogb(float a)
# 617 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 618 "/usr/local/cuda/bin/../include/math_functions.h"
return ilogbf(a);
# 619 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 621 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float scalbn(float a, int b)
# 622 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 623 "/usr/local/cuda/bin/../include/math_functions.h"
return scalbnf(a, b);
# 624 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 626 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float scalbln(float a, long b)
# 627 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 628 "/usr/local/cuda/bin/../include/math_functions.h"
return scalblnf(a, b);
# 629 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 631 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float exp2(float a)
# 632 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 633 "/usr/local/cuda/bin/../include/math_functions.h"
return exp2f(a);
# 634 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 636 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float exp10(float a)
# 637 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 638 "/usr/local/cuda/bin/../include/math_functions.h"
return exp10f(a);
# 639 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 641 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float expm1(float a)
# 642 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 643 "/usr/local/cuda/bin/../include/math_functions.h"
return expm1f(a);
# 644 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 646 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float log2(float a)
# 647 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 648 "/usr/local/cuda/bin/../include/math_functions.h"
return log2f(a);
# 649 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 651 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float log1p(float a)
# 652 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 653 "/usr/local/cuda/bin/../include/math_functions.h"
return log1pf(a);
# 654 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 656 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rsqrt(float a)
# 657 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 658 "/usr/local/cuda/bin/../include/math_functions.h"
return rsqrtf(a);
# 659 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 661 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float acosh(float a)
# 662 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 663 "/usr/local/cuda/bin/../include/math_functions.h"
return acoshf(a);
# 664 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 666 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float asinh(float a)
# 667 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 668 "/usr/local/cuda/bin/../include/math_functions.h"
return asinhf(a);
# 669 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 671 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float atanh(float a)
# 672 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 673 "/usr/local/cuda/bin/../include/math_functions.h"
return atanhf(a);
# 674 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 676 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float hypot(float a, float b)
# 677 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 678 "/usr/local/cuda/bin/../include/math_functions.h"
return hypotf(a, b);
# 679 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 681 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float cbrt(float a)
# 682 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 683 "/usr/local/cuda/bin/../include/math_functions.h"
return cbrtf(a);
# 684 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 686 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rcbrt(float a)
# 687 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 688 "/usr/local/cuda/bin/../include/math_functions.h"
return rcbrtf(a);
# 689 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 691 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float sinpi(float a)
# 692 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 693 "/usr/local/cuda/bin/../include/math_functions.h"
return sinpif(a);
# 694 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 696 "/usr/local/cuda/bin/../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 697 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 698 "/usr/local/cuda/bin/../include/math_functions.h"
sincosf(a, sptr, cptr);
# 699 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 701 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erf(float a)
# 702 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 703 "/usr/local/cuda/bin/../include/math_functions.h"
return erff(a);
# 704 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 706 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfinv(float a)
# 707 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 708 "/usr/local/cuda/bin/../include/math_functions.h"
return erfinvf(a);
# 709 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 711 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfc(float a)
# 712 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 713 "/usr/local/cuda/bin/../include/math_functions.h"
return erfcf(a);
# 714 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 716 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfcinv(float a)
# 717 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 718 "/usr/local/cuda/bin/../include/math_functions.h"
return erfcinvf(a);
# 719 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 721 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float lgamma(float a)
# 722 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 723 "/usr/local/cuda/bin/../include/math_functions.h"
return lgammaf(a);
# 724 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 726 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float tgamma(float a)
# 727 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 728 "/usr/local/cuda/bin/../include/math_functions.h"
return tgammaf(a);
# 729 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 731 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, float b)
# 732 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 733 "/usr/local/cuda/bin/../include/math_functions.h"
return copysignf(a, b);
# 734 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 736 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double copysign(double a, float b)
# 737 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 738 "/usr/local/cuda/bin/../include/math_functions.h"
return copysign(a, (double)b);
# 739 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 741 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, double b)
# 742 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 743 "/usr/local/cuda/bin/../include/math_functions.h"
return copysignf(a, (float)b);
# 744 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 746 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float nextafter(float a, float b)
# 747 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 748 "/usr/local/cuda/bin/../include/math_functions.h"
return nextafterf(a, b);
# 749 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 751 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float remainder(float a, float b)
# 752 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 753 "/usr/local/cuda/bin/../include/math_functions.h"
return remainderf(a, b);
# 754 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 756 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 757 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 758 "/usr/local/cuda/bin/../include/math_functions.h"
return remquof(a, b, quo);
# 759 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 761 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float round(float a)
# 762 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 763 "/usr/local/cuda/bin/../include/math_functions.h"
return roundf(a);
# 764 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 766 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long lround(float a)
# 767 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 768 "/usr/local/cuda/bin/../include/math_functions.h"
return lroundf(a);
# 769 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 771 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long llround(float a)
# 772 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 773 "/usr/local/cuda/bin/../include/math_functions.h"
return llroundf(a);
# 774 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 776 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float trunc(float a)
# 777 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 778 "/usr/local/cuda/bin/../include/math_functions.h"
return truncf(a);
# 779 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 781 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rint(float a)
# 782 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 783 "/usr/local/cuda/bin/../include/math_functions.h"
return rintf(a);
# 784 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 786 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long lrint(float a)
# 787 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 788 "/usr/local/cuda/bin/../include/math_functions.h"
return lrintf(a);
# 789 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 791 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long llrint(float a)
# 792 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 793 "/usr/local/cuda/bin/../include/math_functions.h"
return llrintf(a);
# 794 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 796 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float nearbyint(float a)
# 797 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 798 "/usr/local/cuda/bin/../include/math_functions.h"
return nearbyintf(a);
# 799 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 801 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fdim(float a, float b)
# 802 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 803 "/usr/local/cuda/bin/../include/math_functions.h"
return fdimf(a, b);
# 804 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 806 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 807 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 808 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaf(a, b, c);
# 809 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 811 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fmax(float a, float b)
# 812 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 813 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 814 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 816 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fmin(float a, float b)
# 817 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 818 "/usr/local/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 819 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 821 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 822 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 823 "/usr/local/cuda/bin/../include/math_functions.h"
return umin(a, b);
# 824 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 826 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 827 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 828 "/usr/local/cuda/bin/../include/math_functions.h"
return umin((unsigned)a, b);
# 829 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 831 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 832 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 833 "/usr/local/cuda/bin/../include/math_functions.h"
return umin(a, (unsigned)b);
# 834 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 836 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long min(long long a, long long b)
# 837 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 838 "/usr/local/cuda/bin/../include/math_functions.h"
return llmin(a, b);
# 839 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 841 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, unsigned long long b)
# 842 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 843 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin(a, b);
# 844 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 846 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(long long a, unsigned long long b)
# 847 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 848 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin((unsigned long long)a, b);
# 849 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 851 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, long long b)
# 852 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 853 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin(a, (unsigned long long)b);
# 854 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 856 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float min(float a, float b)
# 857 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 858 "/usr/local/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 859 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 861 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(double a, double b)
# 862 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 863 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin(a, b);
# 864 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 866 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(float a, double b)
# 867 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 868 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin((double)a, b);
# 869 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 871 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(double a, float b)
# 872 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 873 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin(a, (double)b);
# 874 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 876 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 877 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 878 "/usr/local/cuda/bin/../include/math_functions.h"
return umax(a, b);
# 879 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 881 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 882 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 883 "/usr/local/cuda/bin/../include/math_functions.h"
return umax((unsigned)a, b);
# 884 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 886 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 887 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 888 "/usr/local/cuda/bin/../include/math_functions.h"
return umax(a, (unsigned)b);
# 889 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 891 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long max(long long a, long long b)
# 892 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 893 "/usr/local/cuda/bin/../include/math_functions.h"
return llmax(a, b);
# 894 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 896 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, unsigned long long b)
# 897 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 898 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax(a, b);
# 899 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 901 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(long long a, unsigned long long b)
# 902 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 903 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax((unsigned long long)a, b);
# 904 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 906 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, long long b)
# 907 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 908 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax(a, (unsigned long long)b);
# 909 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 911 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float max(float a, float b)
# 912 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 913 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 914 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 916 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(double a, double b)
# 917 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 918 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax(a, b);
# 919 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 921 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(float a, double b)
# 922 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 923 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax((double)a, b);
# 924 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 926 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(double a, float b)
# 927 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 928 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax(a, (double)b);
# 929 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 59 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template<class T, int dim = 1>
# 60 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
struct surface : public surfaceReference {
# 62 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface()
# 63 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 64 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 65 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 67 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface(cudaChannelFormatDesc desc)
# 68 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 69 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = desc;
# 70 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 71 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
};
# 74 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template<int dim>
# 75 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
struct surface< void, dim> : public surfaceReference {
# 77 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface()
# 78 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 79 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< void> ();
# 80 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 81 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
};
# 59 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
# 60 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
struct texture : public textureReference {
# 62 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 63 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 64 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 65 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
{
# 66 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 67 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 68 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 69 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 70 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 71 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 72 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
}
# 74 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 75 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 76 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 77 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
desc)
# 78 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
{
# 79 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 80 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 81 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 82 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 83 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 84 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = desc;
# 85 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
}
# 86 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
};
# 316 "/usr/local/cuda/bin/../include/device_functions.h"
static inline int mulhi(int a, int b)
# 317 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 319 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 321 "/usr/local/cuda/bin/../include/device_functions.h"
static inline unsigned mulhi(unsigned a, unsigned b)
# 322 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 324 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 326 "/usr/local/cuda/bin/../include/device_functions.h"
static inline unsigned mulhi(int a, unsigned b)
# 327 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 329 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 331 "/usr/local/cuda/bin/../include/device_functions.h"
static inline unsigned mulhi(unsigned a, int b)
# 332 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 334 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 336 "/usr/local/cuda/bin/../include/device_functions.h"
static inline long long mul64hi(long long a, long long b)
# 337 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 339 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 341 "/usr/local/cuda/bin/../include/device_functions.h"
static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 342 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 344 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 346 "/usr/local/cuda/bin/../include/device_functions.h"
static inline unsigned long long mul64hi(long long a, unsigned long long b)
# 347 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 349 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 351 "/usr/local/cuda/bin/../include/device_functions.h"
static inline unsigned long long mul64hi(unsigned long long a, long long b)
# 352 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 354 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 356 "/usr/local/cuda/bin/../include/device_functions.h"
static inline int float_as_int(float a)
# 357 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 359 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 361 "/usr/local/cuda/bin/../include/device_functions.h"
static inline float int_as_float(int a)
# 362 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 364 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 366 "/usr/local/cuda/bin/../include/device_functions.h"
static inline float saturate(float a)
# 367 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 369 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 371 "/usr/local/cuda/bin/../include/device_functions.h"
static inline int mul24(int a, int b)
# 372 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 374 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 376 "/usr/local/cuda/bin/../include/device_functions.h"
static inline unsigned umul24(unsigned a, unsigned b)
# 377 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 379 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 381 "/usr/local/cuda/bin/../include/device_functions.h"
static inline void trap()
# 382 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 384 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 386 "/usr/local/cuda/bin/../include/device_functions.h"
static inline void brkpt(int c)
# 387 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 389 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 391 "/usr/local/cuda/bin/../include/device_functions.h"
static inline void syncthreads()
# 392 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 394 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 396 "/usr/local/cuda/bin/../include/device_functions.h"
static inline void prof_trigger(int e)
# 397 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 414 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 416 "/usr/local/cuda/bin/../include/device_functions.h"
static inline void threadfence(bool global = true)
# 417 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 419 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 421 "/usr/local/cuda/bin/../include/device_functions.h"
static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero)
# 422 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 427 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 429 "/usr/local/cuda/bin/../include/device_functions.h"
static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero)
# 430 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 435 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 437 "/usr/local/cuda/bin/../include/device_functions.h"
static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest)
# 438 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 443 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 445 "/usr/local/cuda/bin/../include/device_functions.h"
static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 446 "/usr/local/cuda/bin/../include/device_functions.h"
{exit(1);
# 451 "/usr/local/cuda/bin/../include/device_functions.h"
}
# 101 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicAdd(int *address, int val)
# 102 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 104 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 106 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicAdd(unsigned *address, unsigned val)
# 107 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 109 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 111 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicSub(int *address, int val)
# 112 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 114 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 116 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicSub(unsigned *address, unsigned val)
# 117 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 119 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 121 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicExch(int *address, int val)
# 122 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 124 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 126 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicExch(unsigned *address, unsigned val)
# 127 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 129 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 131 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline float atomicExch(float *address, float val)
# 132 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 134 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 136 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicMin(int *address, int val)
# 137 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 139 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 141 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicMin(unsigned *address, unsigned val)
# 142 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 144 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 146 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicMax(int *address, int val)
# 147 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 149 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 151 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicMax(unsigned *address, unsigned val)
# 152 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 154 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 156 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicInc(unsigned *address, unsigned val)
# 157 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 159 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 161 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicDec(unsigned *address, unsigned val)
# 162 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 164 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 166 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicAnd(int *address, int val)
# 167 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 169 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 171 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicAnd(unsigned *address, unsigned val)
# 172 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 174 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 176 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicOr(int *address, int val)
# 177 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 179 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 181 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicOr(unsigned *address, unsigned val)
# 182 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 184 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 186 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicXor(int *address, int val)
# 187 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 189 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 191 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicXor(unsigned *address, unsigned val)
# 192 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 194 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 196 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicCAS(int *address, int compare, int val)
# 197 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 199 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 201 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 202 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 204 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 74 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 75 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 77 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 79 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 80 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 82 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 84 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 85 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 87 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 89 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static inline bool any(bool cond)
# 90 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 92 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 94 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static inline bool all(bool cond)
# 95 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 97 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 169 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline double fma(double a, double b, double c, cudaRoundMode mode)
# 170 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 175 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 177 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 178 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 183 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 185 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 186 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 191 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 193 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero)
# 194 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 199 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 201 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero)
# 202 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 207 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 209 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero)
# 210 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 215 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 217 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero)
# 218 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 223 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 225 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest)
# 226 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 231 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 233 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest)
# 234 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 239 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 241 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest)
# 242 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 244 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 246 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 247 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 249 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 251 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest)
# 252 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 254 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
}
# 65 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
static inline float atomicAdd(float *address, float val)
# 66 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
{exit(1);
# 68 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
}
# 120 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static inline unsigned ballot(bool pred)
# 121 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{exit(1);
# 123 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
}
# 125 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static inline int syncthreads_count(bool pred)
# 126 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{exit(1);
# 128 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
}
# 130 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static inline bool syncthreads_and(bool pred)
# 131 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{exit(1);
# 133 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
}
# 135 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static inline bool syncthreads_or(bool pred)
# 136 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{exit(1);
# 138 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
}
# 96 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 97 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 98 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 105 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 107 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline T
# 108 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 109 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 115 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 117 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 118 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 119 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 121 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 124 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 125 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 127 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 130 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 131 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 133 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 136 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 137 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 139 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 142 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 143 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 145 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 148 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 149 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 151 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 154 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 155 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 159 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 162 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 163 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 165 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 168 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 169 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 173 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 176 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 177 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 179 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 182 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 183 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 185 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 188 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 189 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 191 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 194 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 195 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 197 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 200 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 201 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 203 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 206 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 207 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 211 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 214 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 215 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 217 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 220 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 221 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 225 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 228 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 229 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 231 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 234 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 235 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 237 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 240 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 241 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 243 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 246 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 247 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 249 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 252 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 253 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 255 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 258 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 259 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 263 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 266 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 267 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 269 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 272 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 273 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 277 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 280 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 281 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 283 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 286 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 287 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 289 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 292 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 293 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 295 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 298 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 299 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 301 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 304 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 305 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 307 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 310 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 311 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 315 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 318 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 319 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 321 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 384 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 385 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 387 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 390 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 391 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 393 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 396 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 397 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 401 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 404 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 405 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 409 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 456 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 457 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 458 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 465 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 467 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline T
# 468 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 469 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 475 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 477 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 478 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 479 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 481 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 484 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 485 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 487 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 490 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 491 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 493 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 496 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 497 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 499 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 502 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 503 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 505 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 508 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 509 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 511 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 514 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 515 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 519 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 522 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 523 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 525 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 528 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 529 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 533 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 536 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 537 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 539 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 542 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 543 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 545 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 548 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 549 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 551 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 554 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 555 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 557 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 560 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 561 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 563 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 566 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 567 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 571 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 574 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 575 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 577 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 580 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 581 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 585 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 588 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 589 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 591 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 594 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 595 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 597 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 600 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 601 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 603 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 606 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 607 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 609 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 612 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 613 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 615 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 618 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 619 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 623 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 626 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 627 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 629 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 632 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 633 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 637 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 640 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 641 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 643 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 646 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 647 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 649 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 652 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 653 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 655 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 658 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 659 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 661 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 664 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 665 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 667 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 670 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 671 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 675 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 678 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 679 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 681 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 744 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 745 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 747 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 750 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 751 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 753 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 756 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 757 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 761 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 764 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 765 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 769 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 816 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 817 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 818 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 836 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 838 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 839 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 840 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 842 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 845 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 846 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 848 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 850 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 851 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 853 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 855 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 856 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 858 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 860 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 861 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 863 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 865 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 866 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 868 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 870 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 871 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 873 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 875 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 876 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 878 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 880 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 881 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 883 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 885 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 886 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 888 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 890 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 891 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 893 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 895 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 896 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 898 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 900 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 901 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 903 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 905 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 906 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 908 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 910 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 911 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 913 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 915 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 916 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 918 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 920 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 921 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 923 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 925 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 926 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 928 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 930 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 931 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 933 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 935 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 936 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 938 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 940 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 941 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 943 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 945 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 946 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 948 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 950 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 951 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 953 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 955 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 956 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 958 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 960 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 961 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 963 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 965 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 966 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 968 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 970 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 971 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 973 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 975 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 976 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 978 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 980 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 981 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 983 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 985 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 986 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 988 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 990 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 991 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 993 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 995 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 996 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 998 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1044 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1045 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1047 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1049 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1050 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1052 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1054 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1055 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1057 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1059 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1060 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1062 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1109 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 1110 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1111 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1129 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1131 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 1132 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1133 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1135 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1138 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1139 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1141 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1143 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1144 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1146 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1148 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1149 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1151 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1153 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1154 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1156 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1158 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1159 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1161 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1163 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1164 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1166 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1168 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1169 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1171 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1173 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1174 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1176 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1178 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1179 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1181 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1183 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1184 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1186 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1188 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1189 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1191 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1193 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1194 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1196 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1198 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1199 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1201 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1203 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1204 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1206 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1208 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1209 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1211 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1213 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1214 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1216 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1218 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1219 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1221 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1223 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1224 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1226 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1228 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1229 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1231 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1233 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1234 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1236 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1238 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1239 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1241 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1243 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1244 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1246 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1248 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1249 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1251 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1253 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1254 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1256 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1258 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1259 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1261 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1263 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1264 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1266 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1268 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1269 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1271 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1273 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1274 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1276 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1278 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1279 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1281 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1283 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1284 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1286 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1288 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1289 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1291 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1337 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1338 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1340 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1342 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1343 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1345 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1347 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1348 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1350 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 1352 "/usr/local/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1353 "/usr/local/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1355 "/usr/local/cuda/bin/../include/surface_functions.h"
}
# 60 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> static uint4 __utexfetchi(texture< T, 1, readMode> , int4);
# 62 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> static int4 __itexfetchi(texture< T, 1, readMode> , int4);
# 64 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> static float4 __ftexfetchi(texture< T, 1, readMode> , int4);
# 67 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> static uint4 __utexfetch(texture< T, dim, readMode> , float4, int = dim);
# 69 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> static int4 __itexfetch(texture< T, dim, readMode> , float4, int = dim);
# 71 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> static float4 __ftexfetch(texture< T, dim, readMode> , float4, int = dim);
# 79 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 80 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 88 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 90 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 91 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 95 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 97 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 98 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 102 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 104 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 105 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 109 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 111 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 112 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 116 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 118 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 123 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 125 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 130 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 132 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 137 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 139 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 144 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 152 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 153 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 157 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 159 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 160 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 164 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 166 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 167 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 171 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 173 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 174 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 178 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 180 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 181 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 185 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 187 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 192 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 194 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 199 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 201 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 206 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 214 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 215 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 219 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 221 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 222 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 226 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 228 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 229 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 233 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 235 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 236 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 240 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 242 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 243 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 247 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 249 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 250 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 254 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 256 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 257 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 261 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 263 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 264 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 268 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 342 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 343 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 347 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 349 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 350 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 354 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 356 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 357 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 361 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 363 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 368 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 376 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 386 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 388 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 389 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 394 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 396 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 397 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 402 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 404 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 405 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 410 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 412 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 413 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 418 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 420 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 421 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 426 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 428 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 429 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 434 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 436 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 437 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 442 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 444 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 445 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 450 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 458 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 464 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 466 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 467 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 474 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 475 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 480 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 482 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 483 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 488 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 490 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 496 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 498 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 499 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 504 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 506 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 512 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 514 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 515 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 520 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 528 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 529 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 537 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 539 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 540 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 544 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 546 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 547 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 551 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 553 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 554 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 558 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 560 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 561 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 565 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 567 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 572 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 574 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 579 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 581 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 586 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 588 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 593 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 601 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 602 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 606 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 608 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 609 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 613 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 615 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 616 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 620 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 622 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 623 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 627 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 629 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 630 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 634 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 636 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 641 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 643 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 648 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 650 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 655 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 663 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 664 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 668 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 670 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 671 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 675 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 677 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 678 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 682 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 684 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 685 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 689 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 691 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 692 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 696 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 698 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 699 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 703 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 705 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 706 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 710 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 712 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 713 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 717 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 797 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 802 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 804 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 805 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 809 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 811 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 816 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 818 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 819 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 823 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 831 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 832 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 841 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 843 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 849 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 851 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 857 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 859 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 865 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 867 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 873 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 875 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 876 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 881 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 883 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 884 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 889 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 891 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 892 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 897 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 899 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 900 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 905 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 913 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 914 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 919 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 921 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 922 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 927 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 929 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 930 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 935 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 937 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 938 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 943 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 945 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 946 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 951 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 953 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 954 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 959 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 961 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 962 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 967 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 969 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 970 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 975 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 983 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 992 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 994 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 995 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 999 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1001 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1002 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1006 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1008 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1009 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1013 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1015 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1016 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1020 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1022 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1023 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1027 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1029 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1034 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1036 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1037 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1041 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1043 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1044 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1048 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1056 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1057 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1061 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1063 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1064 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1068 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1070 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1071 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1075 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1077 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1078 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1082 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1084 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1089 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1091 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1096 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1098 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1099 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1103 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1105 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1110 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1118 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1123 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1125 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1130 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1132 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1137 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1139 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1144 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1146 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1147 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1151 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1153 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1158 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1160 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1165 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1167 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1172 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1246 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1247 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1251 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1253 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1254 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1258 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1260 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1261 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1265 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1267 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1268 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1272 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1280 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1281 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1290 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1292 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1293 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1298 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1300 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1301 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1306 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1308 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1309 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1314 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1316 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1317 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1322 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1324 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1325 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1330 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1332 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1333 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1338 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1340 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1341 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1346 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1348 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1349 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1354 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1362 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1363 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1368 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1370 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1371 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1376 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1378 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1379 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1384 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1386 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1387 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1392 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1394 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1395 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1400 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1402 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1408 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1410 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1416 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1418 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1424 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1432 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1433 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1441 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1443 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1444 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1448 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1450 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1455 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1457 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1458 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1462 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1464 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1469 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1471 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1476 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1478 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1479 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1483 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1485 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1486 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1490 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1492 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1493 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1497 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1505 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1506 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1510 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1512 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1517 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1519 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1520 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1524 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1526 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1527 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1531 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1533 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1534 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1538 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1540 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1545 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1547 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1552 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1554 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1559 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1567 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1572 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1574 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1579 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1581 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1586 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1588 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1593 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1595 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1596 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1600 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1602 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1607 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1609 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1614 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1616 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1621 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1695 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1696 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1700 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1702 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1703 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1707 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1709 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1710 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1714 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1716 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1717 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1721 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1729 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1730 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1739 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1741 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1742 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1747 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1749 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1750 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1755 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1757 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1758 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1763 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1765 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1766 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1771 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1773 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1774 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1779 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1781 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1782 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1787 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1789 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1790 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1795 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1797 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1803 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1811 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1817 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1819 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1825 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1827 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1828 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1833 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1835 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1836 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1841 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1843 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1849 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1851 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1857 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1859 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1865 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 1867 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1873 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
}
# 53 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 55 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 57 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 59 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 61 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 102 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 103 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 104 "/usr/local/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 105 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset)
# 107 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 108 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 109 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 111 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 112 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostAlloc(T **
# 113 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 114 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 115 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 117 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 118 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 119 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 121 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 122 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 123 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pDevice, void *
# 124 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pHost, unsigned
# 125 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 127 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 128 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 129 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 131 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 132 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMalloc(T **
# 133 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 134 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size)
# 136 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 137 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 138 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 140 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 141 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocHost(T **
# 142 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 143 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size)
# 145 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 146 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size);
# 147 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 149 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 150 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocPitch(T **
# 151 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t *
# 152 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch, size_t
# 153 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 154 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height)
# 156 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 157 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 158 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 173 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 174 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 175 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 176 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 177 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 178 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 180 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 181 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 182 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 184 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 185 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 186 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 187 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 188 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 189 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 190 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 192 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 193 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 194 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 196 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 197 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 198 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 199 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 200 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 201 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 202 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream)
# 204 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 205 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 206 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 208 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 209 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 210 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 211 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 212 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 213 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 214 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 215 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream)
# 217 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 218 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 219 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 227 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 228 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 229 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 230 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 231 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 232 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 234 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 235 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 236 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 238 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 239 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 240 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 241 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 242 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 243 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 244 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 246 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 247 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 248 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 250 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 251 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 252 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 253 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 254 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 255 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 256 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream)
# 258 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 259 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 260 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 262 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 263 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 264 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 265 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 266 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 267 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 268 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 269 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream)
# 271 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 272 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 273 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 275 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 276 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 277 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 279 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 280 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 281 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 305 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 306 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 307 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 308 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 310 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 311 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 312 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 320 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 321 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, char *
# 322 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 324 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 325 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 326 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 349 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 350 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 351 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 352 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 354 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 355 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 356 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 405 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 406 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 407 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 408 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 409 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 410 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 411 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 413 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 414 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 415 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 449 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 450 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 451 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 452 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 453 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 454 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 456 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 457 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.texture< T, dim, readMode> ::channelDesc), size);
# 458 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 504 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 505 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 506 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 507 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 508 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 509 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 510 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 511 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 512 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch)
# 514 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 515 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 516 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 546 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 547 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 548 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 549 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 550 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 552 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 553 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 554 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 583 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 584 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 585 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 586 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 588 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 589 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 590 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 592 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 593 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 621 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 622 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 623 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 625 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 626 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 627 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 660 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 661 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 662 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 663 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 665 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 666 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 667 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 709 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 710 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 711 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 713 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 714 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 715 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 745 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 746 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 747 "/usr/local/cuda/bin/../include/cuda_runtime.h"
attr, T *
# 748 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 750 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 751 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 752 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 760 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim> inline cudaError_t
# 761 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToAddr(size_t *
# 762 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const surface< T, dim> &
# 763 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const void *
# 764 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 765 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 767 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 768 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindSurfaceToAddr(offset, &surf, devPtr, &(surf.surface< T, dim> ::channelDesc), size);
# 769 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 771 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim> inline cudaError_t
# 772 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 773 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 774 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 776 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 777 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 778 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 780 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(&surf, array, &desc) : err;
# 781 "/usr/local/cuda/bin/../include/cuda_runtime.h"
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
# 40 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stdarg.h" 3
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
# 458 "/usr/include/libio.h" 3
extern "C" int _IO_getc(_IO_FILE *);
# 459 "/usr/include/libio.h" 3
extern "C" int _IO_putc(int, _IO_FILE *);
# 460 "/usr/include/libio.h" 3
extern "C" int _IO_feof(_IO_FILE *) throw();
# 461 "/usr/include/libio.h" 3
extern "C" int _IO_ferror(_IO_FILE *) throw();
# 463 "/usr/include/libio.h" 3
extern "C" int _IO_peekc_locked(_IO_FILE *);
# 469 "/usr/include/libio.h" 3
extern "C" void _IO_flockfile(_IO_FILE *) throw();
# 470 "/usr/include/libio.h" 3
extern "C" void _IO_funlockfile(_IO_FILE *) throw();
# 471 "/usr/include/libio.h" 3
extern "C" int _IO_ftrylockfile(_IO_FILE *) throw();
# 488 "/usr/include/libio.h" 3
extern "C" int _IO_vfscanf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list, int *__restrict__);
# 490 "/usr/include/libio.h" 3
extern "C" int _IO_vfprintf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 492 "/usr/include/libio.h" 3
extern "C" __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t);
# 493 "/usr/include/libio.h" 3
extern "C" size_t _IO_sgetn(_IO_FILE *, void *, size_t);
# 495 "/usr/include/libio.h" 3
extern "C" __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int);
# 496 "/usr/include/libio.h" 3
extern "C" __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int);
# 498 "/usr/include/libio.h" 3
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
# 62 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }
# 64 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 65 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 66 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 67 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 68 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 69 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 70 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUevent_st *CUevent; }
# 71 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUstream_st *CUstream; }
# 72 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUgraphicsResource_st *CUgraphicsResource; }
# 92 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 83 "/usr/local/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
# 84 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 85 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 86 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 87 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_MASK,
# 88 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_BLOCKING_SYNC,
# 89 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_MAP_HOST = 8,
# 90 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 91 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_FLAGS_MASK = 31
# 92 "/usr/local/cuda/bin/../include/cuda.h"
} CUctx_flags; }
# 100 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 97 "/usr/local/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
# 98 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_DEFAULT,
# 99 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_BLOCKING_SYNC
# 100 "/usr/local/cuda/bin/../include/cuda.h"
} CUevent_flags; }
# 114 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 105 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
# 106 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 107 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 108 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 109 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 110 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 111 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 112 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 113 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 114 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_format; }
# 123 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 119 "/usr/local/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
# 120 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 121 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 122 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR
# 123 "/usr/local/cuda/bin/../include/cuda.h"
} CUaddress_mode; }
# 131 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 128 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
# 129 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 130 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 131 "/usr/local/cuda/bin/../include/cuda.h"
} CUfilter_mode; }
# 169 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 136 "/usr/local/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
# 137 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 138 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 139 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 140 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 141 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 142 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 143 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 144 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 145 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 146 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 147 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 148 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 149 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 150 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 151 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 152 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 154 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 155 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 156 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 157 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 158 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 159 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 160 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 161 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 162 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 163 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 164 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 165 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 166 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH,
# 167 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 168 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES
# 169 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 185 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 174 "/usr/local/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 175 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 176 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 177 "/usr/local/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 178 "/usr/local/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 179 "/usr/local/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 180 "/usr/local/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 181 "/usr/local/cuda/bin/../include/cuda.h"
int memPitch;
# 182 "/usr/local/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 183 "/usr/local/cuda/bin/../include/cuda.h"
int clockRate;
# 184 "/usr/local/cuda/bin/../include/cuda.h"
int textureAlign;
# 185 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 222 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 190 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 196 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 203 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 209 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 214 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 219 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 221 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 222 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunction_attribute; }
# 231 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 227 "/usr/local/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 228 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 229 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 230 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 231 "/usr/local/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 240 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 236 "/usr/local/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
# 237 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 238 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 239 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_PROHIBITED
# 240 "/usr/local/cuda/bin/../include/cuda.h"
} CUcomputemode; }
# 319 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 245 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 250 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 262 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 268 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 274 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 281 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 287 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 294 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 300 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 306 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 311 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 317 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 319 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 331 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 324 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 326 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 327 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 328 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 329 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13,
# 330 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_20
# 331 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 344 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 336 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 339 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 342 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 344 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 351 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 349 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 350 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE
# 351 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsRegisterFlags; }
# 360 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 356 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 357 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 358 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 359 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 360 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 372 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 365 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_cubemap_face_enum {
# 366 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 367 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 368 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 369 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 370 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 371 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 372 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_cubemap_face; }
# 425 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 383 "/usr/local/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 385 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 386 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 387 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 388 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 389 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 391 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 392 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 394 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 395 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 396 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 397 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 398 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 399 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 400 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 401 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 402 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 403 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 404 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 405 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 407 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 408 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 410 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 412 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 414 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 416 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 417 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 418 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 419 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 421 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_POINTER_IS_64BIT = 800,
# 422 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SIZE_IS_64BIT,
# 424 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 425 "/usr/local/cuda/bin/../include/cuda.h"
} CUresult; }
# 471 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 451 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 453 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcXInBytes,
# 454 "/usr/local/cuda/bin/../include/cuda.h"
srcY;
# 455 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 456 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 457 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 458 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 459 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 461 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstXInBytes,
# 462 "/usr/local/cuda/bin/../include/cuda.h"
dstY;
# 463 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 464 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 465 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 466 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 467 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 469 "/usr/local/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 470 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 471 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 505 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 476 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 478 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcXInBytes,
# 479 "/usr/local/cuda/bin/../include/cuda.h"
srcY,
# 480 "/usr/local/cuda/bin/../include/cuda.h"
srcZ;
# 481 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcLOD;
# 482 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 483 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 484 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 485 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 486 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved0;
# 487 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 488 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcHeight;
# 490 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstXInBytes,
# 491 "/usr/local/cuda/bin/../include/cuda.h"
dstY,
# 492 "/usr/local/cuda/bin/../include/cuda.h"
dstZ;
# 493 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstLOD;
# 494 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 495 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 496 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 497 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 498 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved1;
# 499 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 500 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstHeight;
# 502 "/usr/local/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 503 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 504 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Depth;
# 505 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 538 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 507 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA64_MEMCPY3D_st {
# 509 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcXInBytes,
# 510 "/usr/local/cuda/bin/../include/cuda.h"
srcY,
# 511 "/usr/local/cuda/bin/../include/cuda.h"
srcZ;
# 512 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcLOD;
# 513 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 514 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 515 "/usr/local/cuda/bin/../include/cuda.h"
void *srcDevice;
# 516 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 517 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved0;
# 518 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 519 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcHeight;
# 521 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstXInBytes,
# 522 "/usr/local/cuda/bin/../include/cuda.h"
dstY,
# 523 "/usr/local/cuda/bin/../include/cuda.h"
dstZ;
# 524 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstLOD;
# 525 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 526 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 527 "/usr/local/cuda/bin/../include/cuda.h"
void *dstDevice;
# 528 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 529 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved1;
# 530 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 531 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstHeight;
# 533 "/usr/local/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 534 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 535 "/usr/local/cuda/bin/../include/cuda.h"
size_t Depth;
# 537 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Flags;
# 538 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA64_MEMCPY3D; }
# 551 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 544 "/usr/local/cuda/bin/../include/cuda.h"
struct {
# 545 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Width;
# 546 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 548 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 550 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 551 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 567 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 557 "/usr/local/cuda/bin/../include/cuda.h"
struct {
# 558 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Width;
# 559 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 560 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Depth;
# 562 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 564 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 566 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Flags;
# 567 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 611 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 616 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int *);
# 624 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 625 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 626 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 627 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 628 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
# 629 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 630 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 638 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
# 639 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 640 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 641 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 642 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 643 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 644 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 645 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 654 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 655 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 656 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 657 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 658 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 659 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 660 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
# 661 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 669 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);
# 671 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
# 672 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 680 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
# 681 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);
# 683 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost(void **, unsigned);
# 684 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 686 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);
# 688 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer(CUdeviceptr *, void *, unsigned);
# 689 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned *, void *);
# 702 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD(CUdeviceptr, const void *, unsigned);
# 703 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH(void *, CUdeviceptr, unsigned);
# 706 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD(CUdeviceptr, CUdeviceptr, unsigned);
# 709 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA(CUarray, unsigned, CUdeviceptr, unsigned);
# 710 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD(CUdeviceptr, CUarray, unsigned, unsigned);
# 713 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA(CUarray, unsigned, const void *, unsigned);
# 714 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH(void *, CUarray, unsigned, unsigned);
# 717 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA(CUarray, unsigned, CUarray, unsigned, unsigned);
# 721 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D(const CUDA_MEMCPY2D *);
# 722 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *);
# 726 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D(const CUDA_MEMCPY3D *);
# 741 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);
# 743 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);
# 747 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync(CUdeviceptr, CUdeviceptr, unsigned, CUstream);
# 751 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);
# 753 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);
# 757 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);
# 760 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 767 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
# 768 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
# 769 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);
# 771 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
# 772 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
# 773 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 782 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 783 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 784 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 792 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 793 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 794 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 796 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 797 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 805 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 806 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 808 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 809 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress(unsigned *, CUtexref, CUdeviceptr, unsigned);
# 810 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, unsigned);
# 811 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 812 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 813 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 814 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 816 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress(CUdeviceptr *, CUtexref);
# 817 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 818 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 819 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 820 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 821 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 829 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 830 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 831 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 832 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 833 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 841 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 842 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 843 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 850 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 851 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 852 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 853 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 854 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 855 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 862 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 863 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 864 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 865 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamDestroy(CUstream);
# 872 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource);
# 873 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray *, CUgraphicsResource, unsigned, unsigned);
# 874 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer(CUdeviceptr *, unsigned *, CUgraphicsResource);
# 875 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource, unsigned);
# 876 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned, CUgraphicsResource *, CUstream);
# 877 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned, CUgraphicsResource *, CUstream);
# 64 "../../sdk/cutil.h"
enum CUTBoolean {
# 66 "../../sdk/cutil.h"
CUTFalse,
# 67 "../../sdk/cutil.h"
CUTTrue
# 68 "../../sdk/cutil.h"
};
# 76 "../../sdk/cutil.h"
extern "C" void cutFree(void *);
# 94 "../../sdk/cutil.h"
extern "C" void cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int);
# 107 "../../sdk/cutil.h"
extern "C" char *cutFindFilePath(const char *, const char *);
# 122 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char *, float **, unsigned *, bool = false);
# 138 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char *, double **, unsigned *, bool = false);
# 154 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char *, int **, unsigned *, bool = false);
# 169 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char *, unsigned **, unsigned *, bool = false);
# 185 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char *, char **, unsigned *, bool = false);
# 201 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char *, unsigned char **, unsigned *, bool = false);
# 215 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char *, const float *, unsigned, const float, bool = false);
# 229 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char *, const float *, unsigned, const double, bool = false);
# 241 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char *, const int *, unsigned, bool = false);
# 253 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char *, const unsigned *, unsigned, bool = false);
# 265 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char *, const char *, unsigned, bool = false);
# 277 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false);
# 293 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *);
# 306 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *);
# 320 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *);
# 336 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *);
# 352 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *);
# 367 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char *, float **, unsigned *, unsigned *);
# 379 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char *, unsigned char *, unsigned, unsigned);
# 391 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char *, unsigned char *, unsigned, unsigned);
# 404 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned);
# 416 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char *, unsigned *, unsigned, unsigned);
# 428 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char *, unsigned short *, unsigned, unsigned);
# 440 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char *, float *, unsigned, unsigned);
# 461 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int, const char **, const char *);
# 475 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int, const char **, const char *, int *);
# 489 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int, const char **, const char *, float *);
# 503 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int, const char **, const char *, char **);
# 518 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *);
# 532 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int, const char *, const int);
# 544 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparef(const float *, const float *, const unsigned);
# 557 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparei(const int *, const int *, const unsigned);
# 571 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareuit(const unsigned *, const unsigned *, const unsigned, const float, const float);
# 584 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char *, const unsigned char *, const unsigned);
# 599 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareubt(const unsigned char *, const unsigned char *, const unsigned, const float, const float);
# 613 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char *, const unsigned char *, const unsigned, const float);
# 627 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparefe(const float *, const float *, const unsigned, const float);
# 642 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparefet(const float *, const float *, const unsigned, const float, const float);
# 657 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float *, const float *, const unsigned, const float);
# 672 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparePPM(const char *, const char *, const float, const float, bool = false);
# 685 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned *);
# 694 "../../sdk/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned);
# 702 "../../sdk/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned);
# 710 "../../sdk/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned);
# 718 "../../sdk/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned);
# 727 "../../sdk/cutil.h"
extern "C" float cutGetTimerValue(const unsigned);
# 738 "../../sdk/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned);
# 19 "../../sdk/cutil_inline_bankchecker.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
# 20 "../../sdk/cutil_inline_bankchecker.h"
bdimx, unsigned bdimy, unsigned bdimz, char *
# 21 "../../sdk/cutil_inline_bankchecker.h"
aname, int index, char *file, int line)
# 22 "../../sdk/cutil_inline_bankchecker.h"
{
# 23 "../../sdk/cutil_inline_bankchecker.h"
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
# 24 "../../sdk/cutil_inline_bankchecker.h"
}
# 162 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { typedef float2 cuFloatComplex; }
# 164 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCrealf(cuFloatComplex x)
# 165 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 166 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.x;
# 167 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 169 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCimagf(cuFloatComplex x)
# 170 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 171 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.y;
# 172 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 174 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex make_cuFloatComplex(float
# 175 "/usr/local/cuda/bin/../include/cuComplex.h"
r, float i)
# 176 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 177 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex res;
# 178 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 179 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 180 "/usr/local/cuda/bin/../include/cuComplex.h"
return res;
# 181 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 183 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuConjf(cuFloatComplex x)
# 184 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 185 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x), -cuCimagf(x));
# 186 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 187 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCaddf(cuFloatComplex x, cuFloatComplex
# 188 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 189 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 190 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) + cuCrealf(y), cuCimagf(x) + cuCimagf(y));
# 192 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 194 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCsubf(cuFloatComplex x, cuFloatComplex
# 195 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 196 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 197 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) - cuCrealf(y), cuCimagf(x) - cuCimagf(y));
# 199 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 206 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
# 207 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 208 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 209 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex prod;
# 210 "/usr/local/cuda/bin/../include/cuComplex.h"
prod = make_cuFloatComplex((cuCrealf(x) * cuCrealf(y)) - (cuCimagf(x) * cuCimagf(y)), (cuCrealf(x) * cuCimagf(y)) + (cuCimagf(x) * cuCrealf(y)));
# 214 "/usr/local/cuda/bin/../include/cuComplex.h"
return prod;
# 215 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 222 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCdivf(cuFloatComplex x, cuFloatComplex
# 223 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 224 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 225 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex quot;
# 226 "/usr/local/cuda/bin/../include/cuComplex.h"
float s = (((float)fabs((double)cuCrealf(y))) + ((float)fabs((double)cuCimagf(y))));
# 228 "/usr/local/cuda/bin/../include/cuComplex.h"
float oos = ((1.0F) / s);
# 229 "/usr/local/cuda/bin/../include/cuComplex.h"
float ars = (cuCrealf(x) * oos);
# 230 "/usr/local/cuda/bin/../include/cuComplex.h"
float ais = (cuCimagf(x) * oos);
# 231 "/usr/local/cuda/bin/../include/cuComplex.h"
float brs = (cuCrealf(y) * oos);
# 232 "/usr/local/cuda/bin/../include/cuComplex.h"
float bis = (cuCimagf(y) * oos);
# 233 "/usr/local/cuda/bin/../include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 234 "/usr/local/cuda/bin/../include/cuComplex.h"
oos = ((1.0F) / s);
# 235 "/usr/local/cuda/bin/../include/cuComplex.h"
quot = make_cuFloatComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 237 "/usr/local/cuda/bin/../include/cuComplex.h"
return quot;
# 238 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 248 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCabsf(cuFloatComplex x)
# 249 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 250 "/usr/local/cuda/bin/../include/cuComplex.h"
float a = cuCrealf(x);
# 251 "/usr/local/cuda/bin/../include/cuComplex.h"
float b = cuCimagf(x);
# 252 "/usr/local/cuda/bin/../include/cuComplex.h"
float v, w, t;
# 253 "/usr/local/cuda/bin/../include/cuComplex.h"
a = ((float)fabs(a));
# 254 "/usr/local/cuda/bin/../include/cuComplex.h"
b = ((float)fabs(b));
# 255 "/usr/local/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 256 "/usr/local/cuda/bin/../include/cuComplex.h"
v = a;
# 257 "/usr/local/cuda/bin/../include/cuComplex.h"
w = b;
# 258 "/usr/local/cuda/bin/../include/cuComplex.h"
} else {
# 259 "/usr/local/cuda/bin/../include/cuComplex.h"
v = b;
# 260 "/usr/local/cuda/bin/../include/cuComplex.h"
w = a;
# 261 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 262 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (w / v);
# 263 "/usr/local/cuda/bin/../include/cuComplex.h"
t = ((1.0F) + (t * t));
# 264 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v * ((float)sqrt(t)));
# 265 "/usr/local/cuda/bin/../include/cuComplex.h"
if (((v == (0.0F)) || (v > (3.402823466e+38F))) || (w > (3.402823466e+38F))) {
# 266 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v + w);
# 267 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 268 "/usr/local/cuda/bin/../include/cuComplex.h"
return t;
# 269 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 272 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { typedef double2 cuDoubleComplex; }
# 274 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCreal(cuDoubleComplex x)
# 275 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 276 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.x;
# 277 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 279 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCimag(cuDoubleComplex x)
# 280 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 281 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.y;
# 282 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 284 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex make_cuDoubleComplex(double
# 285 "/usr/local/cuda/bin/../include/cuComplex.h"
r, double i)
# 286 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 287 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex res;
# 288 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 289 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 290 "/usr/local/cuda/bin/../include/cuComplex.h"
return res;
# 291 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 293 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuConj(cuDoubleComplex x)
# 294 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 295 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x), -cuCimag(x));
# 296 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 298 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCadd(cuDoubleComplex x, cuDoubleComplex
# 299 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 300 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 301 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) + cuCreal(y), cuCimag(x) + cuCimag(y));
# 303 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 305 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCsub(cuDoubleComplex x, cuDoubleComplex
# 306 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 307 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 308 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) - cuCreal(y), cuCimag(x) - cuCimag(y));
# 310 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 317 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
# 318 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 319 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 320 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex prod;
# 321 "/usr/local/cuda/bin/../include/cuComplex.h"
prod = make_cuDoubleComplex((cuCreal(x) * cuCreal(y)) - (cuCimag(x) * cuCimag(y)), (cuCreal(x) * cuCimag(y)) + (cuCimag(x) * cuCreal(y)));
# 325 "/usr/local/cuda/bin/../include/cuComplex.h"
return prod;
# 326 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 333 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCdiv(cuDoubleComplex x, cuDoubleComplex
# 334 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 335 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 336 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex quot;
# 337 "/usr/local/cuda/bin/../include/cuComplex.h"
double s = (fabs(cuCreal(y)) + fabs(cuCimag(y)));
# 338 "/usr/local/cuda/bin/../include/cuComplex.h"
double oos = ((1.0) / s);
# 339 "/usr/local/cuda/bin/../include/cuComplex.h"
double ars = (cuCreal(x) * oos);
# 340 "/usr/local/cuda/bin/../include/cuComplex.h"
double ais = (cuCimag(x) * oos);
# 341 "/usr/local/cuda/bin/../include/cuComplex.h"
double brs = (cuCreal(y) * oos);
# 342 "/usr/local/cuda/bin/../include/cuComplex.h"
double bis = (cuCimag(y) * oos);
# 343 "/usr/local/cuda/bin/../include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 344 "/usr/local/cuda/bin/../include/cuComplex.h"
oos = ((1.0) / s);
# 345 "/usr/local/cuda/bin/../include/cuComplex.h"
quot = make_cuDoubleComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 347 "/usr/local/cuda/bin/../include/cuComplex.h"
return quot;
# 348 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 356 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCabs(cuDoubleComplex x)
# 357 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 358 "/usr/local/cuda/bin/../include/cuComplex.h"
double a = cuCreal(x);
# 359 "/usr/local/cuda/bin/../include/cuComplex.h"
double b = cuCimag(x);
# 360 "/usr/local/cuda/bin/../include/cuComplex.h"
double v, w, t;
# 361 "/usr/local/cuda/bin/../include/cuComplex.h"
a = fabs(a);
# 362 "/usr/local/cuda/bin/../include/cuComplex.h"
b = fabs(b);
# 363 "/usr/local/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 364 "/usr/local/cuda/bin/../include/cuComplex.h"
v = a;
# 365 "/usr/local/cuda/bin/../include/cuComplex.h"
w = b;
# 366 "/usr/local/cuda/bin/../include/cuComplex.h"
} else {
# 367 "/usr/local/cuda/bin/../include/cuComplex.h"
v = b;
# 368 "/usr/local/cuda/bin/../include/cuComplex.h"
w = a;
# 369 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 370 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (w / v);
# 371 "/usr/local/cuda/bin/../include/cuComplex.h"
t = ((1.0) + (t * t));
# 372 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v * sqrt(t));
# 373 "/usr/local/cuda/bin/../include/cuComplex.h"
if (((v == (0.0)) || (v > (1.797693134862315708e+308))) || (w > (1.797693134862315708e+308)))
# 374 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 375 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v + w);
# 376 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 377 "/usr/local/cuda/bin/../include/cuComplex.h"
return t;
# 378 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 387 "/usr/local/cuda/bin/../include/cuComplex.h"
typedef cuFloatComplex cuComplex;
# 388 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuComplex make_cuComplex(float x, float
# 389 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 390 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 391 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(x, y);
# 392 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 395 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuDoubleComplex cuComplexFloatToDouble(cuFloatComplex
# 396 "/usr/local/cuda/bin/../include/cuComplex.h"
c)
# 397 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 398 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex((double)cuCrealf(c), (double)cuCimagf(c));
# 399 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 401 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuFloatComplex cuComplexDoubleToFloat(cuDoubleComplex
# 402 "/usr/local/cuda/bin/../include/cuComplex.h"
c)
# 403 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 404 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex((float)cuCreal(c), (float)cuCimag(c));
# 405 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 71 "/usr/local/cuda/bin/../include/cufft.h"
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
CUFFT_INVALID_SIZE
# 71 "/usr/local/cuda/bin/../include/cufft.h"
} cufftResult; }
# 76 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef unsigned cufftHandle; }
# 80 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef float cufftReal; }
# 81 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef double cufftDoubleReal; }
# 86 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef cuComplex cufftComplex; }
# 87 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef cuDoubleComplex cufftDoubleComplex; }
# 101 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 94 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftType_t {
# 95 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_R2C = 42,
# 96 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_C2R = 44,
# 97 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_C2C = 41,
# 98 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_D2Z = 106,
# 99 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_Z2D = 108,
# 100 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_Z2Z = 105
# 101 "/usr/local/cuda/bin/../include/cufft.h"
} cufftType; }
# 103 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);
# 108 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);
# 112 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);
# 116 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlanMany(cufftHandle *, int, int *, int *, int, int, int *, int, int, cufftType, int);
# 124 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftDestroy(cufftHandle);
# 126 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);
# 131 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);
# 135 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2R(cufftHandle, cufftComplex *, cufftReal *);
# 139 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2Z(cufftHandle, cufftDoubleComplex *, cufftDoubleComplex *, int);
# 144 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecD2Z(cufftHandle, cufftDoubleReal *, cufftDoubleComplex *);
# 148 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2D(cufftHandle, cufftDoubleComplex *, cufftDoubleReal *);
# 152 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftSetStream(cufftHandle, cudaStream_t);
# 22 "../../sdk/cutil_inline_runtime.h"
inline void __cutilCondition(int val, char *file, int line)
# 23 "../../sdk/cutil_inline_runtime.h"
{
# 24 "../../sdk/cutil_inline_runtime.h"
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
# 25 "../../sdk/cutil_inline_runtime.h"
exit(1);
# 26 "../../sdk/cutil_inline_runtime.h"
}
# 27 "../../sdk/cutil_inline_runtime.h"
}
# 29 "../../sdk/cutil_inline_runtime.h"
inline void __cutilExit(int argc, char **argv)
# 30 "../../sdk/cutil_inline_runtime.h"
{
# 31 "../../sdk/cutil_inline_runtime.h"
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
# 32 "../../sdk/cutil_inline_runtime.h"
printf("\nPress ENTER to exit...\n");
# 33 "../../sdk/cutil_inline_runtime.h"
fflush(stdout);
# 34 "../../sdk/cutil_inline_runtime.h"
fflush(stderr);
# 35 "../../sdk/cutil_inline_runtime.h"
getchar();
# 36 "../../sdk/cutil_inline_runtime.h"
}
# 37 "../../sdk/cutil_inline_runtime.h"
exit(0);
# 38 "../../sdk/cutil_inline_runtime.h"
}
# 41 "../../sdk/cutil_inline_runtime.h"
inline int cutGetMaxGflopsDeviceId()
# 42 "../../sdk/cutil_inline_runtime.h"
{
# 43 "../../sdk/cutil_inline_runtime.h"
int device_count = 0;
# 44 "../../sdk/cutil_inline_runtime.h"
cudaGetDeviceCount(&device_count);
# 46 "../../sdk/cutil_inline_runtime.h"
cudaDeviceProp device_properties;
# 47 "../../sdk/cutil_inline_runtime.h"
int max_gflops_device = 0;
# 48 "../../sdk/cutil_inline_runtime.h"
int max_gflops = 0;
# 50 "../../sdk/cutil_inline_runtime.h"
int current_device = 0;
# 51 "../../sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 52 "../../sdk/cutil_inline_runtime.h"
max_gflops = ((device_properties.multiProcessorCount) * (device_properties.clockRate));
# 53 "../../sdk/cutil_inline_runtime.h"
++current_device;
# 55 "../../sdk/cutil_inline_runtime.h"
while (current_device < device_count)
# 56 "../../sdk/cutil_inline_runtime.h"
{
# 57 "../../sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 58 "../../sdk/cutil_inline_runtime.h"
int gflops = ((device_properties.multiProcessorCount) * (device_properties.clockRate));
# 59 "../../sdk/cutil_inline_runtime.h"
if (gflops > max_gflops)
# 60 "../../sdk/cutil_inline_runtime.h"
{
# 61 "../../sdk/cutil_inline_runtime.h"
max_gflops = gflops;
# 62 "../../sdk/cutil_inline_runtime.h"
max_gflops_device = current_device;
# 63 "../../sdk/cutil_inline_runtime.h"
}
# 64 "../../sdk/cutil_inline_runtime.h"
++current_device;
# 65 "../../sdk/cutil_inline_runtime.h"
}
# 67 "../../sdk/cutil_inline_runtime.h"
return max_gflops_device;
# 68 "../../sdk/cutil_inline_runtime.h"
}
# 70 "../../sdk/cutil_inline_runtime.h"
inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
# 71 "../../sdk/cutil_inline_runtime.h"
{
# 72 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 73 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 75 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 76 "../../sdk/cutil_inline_runtime.h"
}
# 77 "../../sdk/cutil_inline_runtime.h"
}
# 79 "../../sdk/cutil_inline_runtime.h"
inline void __cudaSafeCall(cudaError err, const char *file, const int line)
# 80 "../../sdk/cutil_inline_runtime.h"
{
# 81 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 82 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 84 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 85 "../../sdk/cutil_inline_runtime.h"
}
# 86 "../../sdk/cutil_inline_runtime.h"
}
# 88 "../../sdk/cutil_inline_runtime.h"
inline void __cudaSafeThreadSync(const char *file, const int line)
# 89 "../../sdk/cutil_inline_runtime.h"
{
# 90 "../../sdk/cutil_inline_runtime.h"
cudaError err = cudaThreadSynchronize();
# 91 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 92 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaThreadSynchronize() Driver API error in file \'%s\' in line %i : %s.\n", file, line, cudaGetErrorString(err));
# 94 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 95 "../../sdk/cutil_inline_runtime.h"
}
# 96 "../../sdk/cutil_inline_runtime.h"
}
# 98 "../../sdk/cutil_inline_runtime.h"
inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
# 99 "../../sdk/cutil_inline_runtime.h"
{
# 100 "../../sdk/cutil_inline_runtime.h"
if ((CUFFT_SUCCESS) != err) {
# 101 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n", file, line);
# 103 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 104 "../../sdk/cutil_inline_runtime.h"
}
# 105 "../../sdk/cutil_inline_runtime.h"
}
# 107 "../../sdk/cutil_inline_runtime.h"
inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
# 108 "../../sdk/cutil_inline_runtime.h"
{
# 109 "../../sdk/cutil_inline_runtime.h"
if ((CUTTrue) != err) {
# 110 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n", file, line);
# 112 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 113 "../../sdk/cutil_inline_runtime.h"
}
# 114 "../../sdk/cutil_inline_runtime.h"
}
# 116 "../../sdk/cutil_inline_runtime.h"
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
# 117 "../../sdk/cutil_inline_runtime.h"
{
# 118 "../../sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 119 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 120 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 122 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 123 "../../sdk/cutil_inline_runtime.h"
}
# 132 "../../sdk/cutil_inline_runtime.h"
}
# 133 "../../sdk/cutil_inline_runtime.h"
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
# 134 "../../sdk/cutil_inline_runtime.h"
{
# 135 "../../sdk/cutil_inline_runtime.h"
if (!(pointer)) {
# 136 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n", file, line);
# 138 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 139 "../../sdk/cutil_inline_runtime.h"
}
# 140 "../../sdk/cutil_inline_runtime.h"
}
# 145 "../../sdk/cutil_inline_runtime.h"
inline void cutilDeviceInit(int ARGC, char **ARGV)
# 146 "../../sdk/cutil_inline_runtime.h"
{
# 147 "../../sdk/cutil_inline_runtime.h"
int deviceCount;
# 148 "../../sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "../../sdk/cutil_inline_runtime.h", 148);
# 149 "../../sdk/cutil_inline_runtime.h"
if (deviceCount == 0) {
# 150 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
# 151 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 152 "../../sdk/cutil_inline_runtime.h"
}
# 153 "../../sdk/cutil_inline_runtime.h"
int dev = 0;
# 154 "../../sdk/cutil_inline_runtime.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 155 "../../sdk/cutil_inline_runtime.h"
if (dev < 0) { dev = 0; } if (dev > (deviceCount - 1)) { dev = (deviceCount - 1); }
# 157 "../../sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 158 "../../sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "../../sdk/cutil_inline_runtime.h", 158);
# 159 "../../sdk/cutil_inline_runtime.h"
if ((deviceProp.major) < 1) {
# 160 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutil error: device does not support CUDA.\n");
# 161 "../../sdk/cutil_inline_runtime.h"
exit(-1); }
# 163 "../../sdk/cutil_inline_runtime.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 164 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name); }
# 165 "../../sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaSetDevice(dev), "../../sdk/cutil_inline_runtime.h", 165);
# 166 "../../sdk/cutil_inline_runtime.h"
}
# 171 "../../sdk/cutil_inline_runtime.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 172 "../../sdk/cutil_inline_runtime.h"
{
# 173 "../../sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 174 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 175 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 177 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 178 "../../sdk/cutil_inline_runtime.h"
}
# 179 "../../sdk/cutil_inline_runtime.h"
err = cudaThreadSynchronize();
# 180 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 181 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "CCUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 183 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 184 "../../sdk/cutil_inline_runtime.h"
}
# 185 "../../sdk/cutil_inline_runtime.h"
}
# 16 "../../sdk/cutil_inline_drvapi.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
# 17 "../../sdk/cutil_inline_drvapi.h"
{
# 18 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 19 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
# 21 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 22 "../../sdk/cutil_inline_drvapi.h"
}
# 23 "../../sdk/cutil_inline_drvapi.h"
}
# 24 "../../sdk/cutil_inline_drvapi.h"
inline void __cuSafeCall(CUresult err, const char *file, const int line)
# 25 "../../sdk/cutil_inline_drvapi.h"
{
# 26 "../../sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(err, file, line);
# 27 "../../sdk/cutil_inline_drvapi.h"
}
# 29 "../../sdk/cutil_inline_drvapi.h"
inline void __cuCtxSync(const char *file, const int line)
# 30 "../../sdk/cutil_inline_drvapi.h"
{
# 31 "../../sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 32 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 33 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);
# 35 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 36 "../../sdk/cutil_inline_drvapi.h"
}
# 37 "../../sdk/cutil_inline_drvapi.h"
}
# 39 "../../sdk/cutil_inline_drvapi.h"
inline void __cuCheckMsg(const char *msg, const char *file, const int line)
# 40 "../../sdk/cutil_inline_drvapi.h"
{
# 41 "../../sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 42 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 43 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> %s", msg);
# 44 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> cuCtxSynchronize API error = %04d in file <%s>, line %i.\n", err, file, line);
# 46 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 47 "../../sdk/cutil_inline_drvapi.h"
}
# 48 "../../sdk/cutil_inline_drvapi.h"
}
# 54 "../../sdk/cutil_inline_drvapi.h"
inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV)
# 55 "../../sdk/cutil_inline_drvapi.h"
{
# 56 "../../sdk/cutil_inline_drvapi.h"
cuDevice = 0;
# 57 "../../sdk/cutil_inline_drvapi.h"
int deviceCount = 0;
# 58 "../../sdk/cutil_inline_drvapi.h"
CUresult err = cuInit(0);
# 59 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) == err) {
# 60 "../../sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "../../sdk/cutil_inline_drvapi.h", 60); }
# 61 "../../sdk/cutil_inline_drvapi.h"
if (deviceCount == 0) {
# 62 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
# 63 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 64 "../../sdk/cutil_inline_drvapi.h"
}
# 65 "../../sdk/cutil_inline_drvapi.h"
int dev = 0;
# 66 "../../sdk/cutil_inline_drvapi.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 67 "../../sdk/cutil_inline_drvapi.h"
if (dev < 0) { dev = 0; }
# 68 "../../sdk/cutil_inline_drvapi.h"
if (dev > (deviceCount - 1)) { dev = (deviceCount - 1); }
# 69 "../../sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "../../sdk/cutil_inline_drvapi.h", 69);
# 70 "../../sdk/cutil_inline_drvapi.h"
char name[100];
# 71 "../../sdk/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 72 "../../sdk/cutil_inline_drvapi.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 73 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Using device %d: %s\n", dev, name); }
# 74 "../../sdk/cutil_inline_drvapi.h"
}
# 78 "../../sdk/cutil_inline_drvapi.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 79 "../../sdk/cutil_inline_drvapi.h"
{
# 80 "../../sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 81 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
# 82 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 84 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 85 "../../sdk/cutil_inline_drvapi.h"
}
# 86 "../../sdk/cutil_inline_drvapi.h"
err = cuCtxSynchronize();
# 87 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 88 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 90 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 91 "../../sdk/cutil_inline_drvapi.h"
}
# 92 "../../sdk/cutil_inline_drvapi.h"
}
# 12 "../../sdk/cutil_inline.h"
inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
# 13 "../../sdk/cutil_inline.h"
{
# 14 "../../sdk/cutil_inline.h"
printf("CUDA %d.%02d Toolkit built this project.\n", 3000 / 1000, 3000 % 100);
# 15 "../../sdk/cutil_inline.h"
printf("  [ %s ] requirements:\n", sSDKsample);
# 16 "../../sdk/cutil_inline.h"
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
# 17 "../../sdk/cutil_inline.h"
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
# 18 "../../sdk/cutil_inline.h"
}
# 49 "../../sdk/cutil_math.h"
extern "C" { typedef unsigned uint; }
# 50 "../../sdk/cutil_math.h"
extern "C" { typedef unsigned short ushort; }
# 85 "../../sdk/cutil_math.h"
inline float lerp(float a, float b, float t)
# 86 "../../sdk/cutil_math.h"
{
# 87 "../../sdk/cutil_math.h"
return a + (t * (b - a));
# 88 "../../sdk/cutil_math.h"
}
# 91 "../../sdk/cutil_math.h"
inline float clamp(float f, float a, float b)
# 92 "../../sdk/cutil_math.h"
{
# 93 "../../sdk/cutil_math.h"
return fmaxf(a, fminf(f, b));
# 94 "../../sdk/cutil_math.h"
}
# 100 "../../sdk/cutil_math.h"
inline int2 operator-(int2 &a)
# 101 "../../sdk/cutil_math.h"
{
# 102 "../../sdk/cutil_math.h"
return make_int2(-(a.x), -(a.y));
# 103 "../../sdk/cutil_math.h"
}
# 106 "../../sdk/cutil_math.h"
inline int2 operator+(int2 a, int2 b)
# 107 "../../sdk/cutil_math.h"
{
# 108 "../../sdk/cutil_math.h"
return make_int2((a.x) + (b.x), (a.y) + (b.y));
# 109 "../../sdk/cutil_math.h"
}
# 110 "../../sdk/cutil_math.h"
inline void operator+=(int2 &a, int2 b)
# 111 "../../sdk/cutil_math.h"
{
# 112 "../../sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 113 "../../sdk/cutil_math.h"
}
# 116 "../../sdk/cutil_math.h"
inline int2 operator-(int2 a, int2 b)
# 117 "../../sdk/cutil_math.h"
{
# 118 "../../sdk/cutil_math.h"
return make_int2((a.x) - (b.x), (a.y) - (b.y));
# 119 "../../sdk/cutil_math.h"
}
# 120 "../../sdk/cutil_math.h"
inline void operator-=(int2 &a, int2 b)
# 121 "../../sdk/cutil_math.h"
{
# 122 "../../sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 123 "../../sdk/cutil_math.h"
}
# 126 "../../sdk/cutil_math.h"
inline int2 operator*(int2 a, int2 b)
# 127 "../../sdk/cutil_math.h"
{
# 128 "../../sdk/cutil_math.h"
return make_int2((a.x) * (b.x), (a.y) * (b.y));
# 129 "../../sdk/cutil_math.h"
}
# 130 "../../sdk/cutil_math.h"
inline int2 operator*(int2 a, int s)
# 131 "../../sdk/cutil_math.h"
{
# 132 "../../sdk/cutil_math.h"
return make_int2((a.x) * s, (a.y) * s);
# 133 "../../sdk/cutil_math.h"
}
# 134 "../../sdk/cutil_math.h"
inline int2 operator*(int s, int2 a)
# 135 "../../sdk/cutil_math.h"
{
# 136 "../../sdk/cutil_math.h"
return make_int2((a.x) * s, (a.y) * s);
# 137 "../../sdk/cutil_math.h"
}
# 138 "../../sdk/cutil_math.h"
inline void operator*=(int2 &a, int s)
# 139 "../../sdk/cutil_math.h"
{
# 140 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 141 "../../sdk/cutil_math.h"
}
# 147 "../../sdk/cutil_math.h"
inline float2 make_float2(float s)
# 148 "../../sdk/cutil_math.h"
{
# 149 "../../sdk/cutil_math.h"
return make_float2(s, s);
# 150 "../../sdk/cutil_math.h"
}
# 151 "../../sdk/cutil_math.h"
inline float2 make_float2(int2 a)
# 152 "../../sdk/cutil_math.h"
{
# 153 "../../sdk/cutil_math.h"
return make_float2((float)(a.x), (float)(a.y));
# 154 "../../sdk/cutil_math.h"
}
# 157 "../../sdk/cutil_math.h"
inline float2 operator-(float2 &a)
# 158 "../../sdk/cutil_math.h"
{
# 159 "../../sdk/cutil_math.h"
return make_float2(-(a.x), -(a.y));
# 160 "../../sdk/cutil_math.h"
}
# 163 "../../sdk/cutil_math.h"
inline float2 operator+(float2 a, float2 b)
# 164 "../../sdk/cutil_math.h"
{
# 165 "../../sdk/cutil_math.h"
return make_float2((a.x) + (b.x), (a.y) + (b.y));
# 166 "../../sdk/cutil_math.h"
}
# 167 "../../sdk/cutil_math.h"
inline void operator+=(float2 &a, float2 b)
# 168 "../../sdk/cutil_math.h"
{
# 169 "../../sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y);
# 170 "../../sdk/cutil_math.h"
}
# 173 "../../sdk/cutil_math.h"
inline float2 operator-(float2 a, float2 b)
# 174 "../../sdk/cutil_math.h"
{
# 175 "../../sdk/cutil_math.h"
return make_float2((a.x) - (b.x), (a.y) - (b.y));
# 176 "../../sdk/cutil_math.h"
}
# 177 "../../sdk/cutil_math.h"
inline void operator-=(float2 &a, float2 b)
# 178 "../../sdk/cutil_math.h"
{
# 179 "../../sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y);
# 180 "../../sdk/cutil_math.h"
}
# 183 "../../sdk/cutil_math.h"
inline float2 operator*(float2 a, float2 b)
# 184 "../../sdk/cutil_math.h"
{
# 185 "../../sdk/cutil_math.h"
return make_float2((a.x) * (b.x), (a.y) * (b.y));
# 186 "../../sdk/cutil_math.h"
}
# 187 "../../sdk/cutil_math.h"
inline float2 operator*(float2 a, float s)
# 188 "../../sdk/cutil_math.h"
{
# 189 "../../sdk/cutil_math.h"
return make_float2((a.x) * s, (a.y) * s);
# 190 "../../sdk/cutil_math.h"
}
# 191 "../../sdk/cutil_math.h"
inline float2 operator*(float s, float2 a)
# 192 "../../sdk/cutil_math.h"
{
# 193 "../../sdk/cutil_math.h"
return make_float2((a.x) * s, (a.y) * s);
# 194 "../../sdk/cutil_math.h"
}
# 195 "../../sdk/cutil_math.h"
inline void operator*=(float2 &a, float s)
# 196 "../../sdk/cutil_math.h"
{
# 197 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 198 "../../sdk/cutil_math.h"
}
# 201 "../../sdk/cutil_math.h"
inline float2 operator/(float2 a, float2 b)
# 202 "../../sdk/cutil_math.h"
{
# 203 "../../sdk/cutil_math.h"
return make_float2((a.x) / (b.x), (a.y) / (b.y));
# 204 "../../sdk/cutil_math.h"
}
# 205 "../../sdk/cutil_math.h"
inline float2 operator/(float2 a, float s)
# 206 "../../sdk/cutil_math.h"
{
# 207 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 208 "../../sdk/cutil_math.h"
return (a * inv);
# 209 "../../sdk/cutil_math.h"
}
# 210 "../../sdk/cutil_math.h"
inline float2 operator/(float s, float2 a)
# 211 "../../sdk/cutil_math.h"
{
# 212 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 213 "../../sdk/cutil_math.h"
return (a * inv);
# 214 "../../sdk/cutil_math.h"
}
# 215 "../../sdk/cutil_math.h"
inline void operator/=(float2 &a, float s)
# 216 "../../sdk/cutil_math.h"
{
# 217 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 218 "../../sdk/cutil_math.h"
((a) *= inv);
# 219 "../../sdk/cutil_math.h"
}
# 222 "../../sdk/cutil_math.h"
inline float2 lerp(float2 a, float2 b, float t)
# 223 "../../sdk/cutil_math.h"
{
# 224 "../../sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 225 "../../sdk/cutil_math.h"
}
# 228 "../../sdk/cutil_math.h"
inline float2 clamp(float2 v, float a, float b)
# 229 "../../sdk/cutil_math.h"
{
# 230 "../../sdk/cutil_math.h"
return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
# 231 "../../sdk/cutil_math.h"
}
# 233 "../../sdk/cutil_math.h"
inline float2 clamp(float2 v, float2 a, float2 b)
# 234 "../../sdk/cutil_math.h"
{
# 235 "../../sdk/cutil_math.h"
return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
# 236 "../../sdk/cutil_math.h"
}
# 239 "../../sdk/cutil_math.h"
inline float dot(float2 a, float2 b)
# 240 "../../sdk/cutil_math.h"
{
# 241 "../../sdk/cutil_math.h"
return ((a.x) * (b.x)) + ((a.y) * (b.y));
# 242 "../../sdk/cutil_math.h"
}
# 245 "../../sdk/cutil_math.h"
inline float length(float2 v)
# 246 "../../sdk/cutil_math.h"
{
# 247 "../../sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 248 "../../sdk/cutil_math.h"
}
# 251 "../../sdk/cutil_math.h"
inline float2 normalize(float2 v)
# 252 "../../sdk/cutil_math.h"
{
# 253 "../../sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 254 "../../sdk/cutil_math.h"
return (v * invLen);
# 255 "../../sdk/cutil_math.h"
}
# 258 "../../sdk/cutil_math.h"
inline float2 floor(const float2 v)
# 259 "../../sdk/cutil_math.h"
{
# 260 "../../sdk/cutil_math.h"
return make_float2(floor(v.x), floor(v.y));
# 261 "../../sdk/cutil_math.h"
}
# 264 "../../sdk/cutil_math.h"
inline float2 reflect(float2 i, float2 n)
# 265 "../../sdk/cutil_math.h"
{
# 266 "../../sdk/cutil_math.h"
return (i - ((((((2.0F)) * n)) * (dot(n, i)))));
# 267 "../../sdk/cutil_math.h"
}
# 270 "../../sdk/cutil_math.h"
inline float2 fabs(float2 v)
# 271 "../../sdk/cutil_math.h"
{
# 272 "../../sdk/cutil_math.h"
return make_float2(fabs(v.x), fabs(v.y));
# 273 "../../sdk/cutil_math.h"
}
# 279 "../../sdk/cutil_math.h"
inline float3 make_float3(float s)
# 280 "../../sdk/cutil_math.h"
{
# 281 "../../sdk/cutil_math.h"
return make_float3(s, s, s);
# 282 "../../sdk/cutil_math.h"
}
# 283 "../../sdk/cutil_math.h"
inline float3 make_float3(float2 a)
# 284 "../../sdk/cutil_math.h"
{
# 285 "../../sdk/cutil_math.h"
return make_float3(a.x, a.y, (0.0F));
# 286 "../../sdk/cutil_math.h"
}
# 287 "../../sdk/cutil_math.h"
inline float3 make_float3(float2 a, float s)
# 288 "../../sdk/cutil_math.h"
{
# 289 "../../sdk/cutil_math.h"
return make_float3(a.x, a.y, s);
# 290 "../../sdk/cutil_math.h"
}
# 291 "../../sdk/cutil_math.h"
inline float3 make_float3(float4 a)
# 292 "../../sdk/cutil_math.h"
{
# 293 "../../sdk/cutil_math.h"
return make_float3(a.x, a.y, a.z);
# 294 "../../sdk/cutil_math.h"
}
# 295 "../../sdk/cutil_math.h"
inline float3 make_float3(int3 a)
# 296 "../../sdk/cutil_math.h"
{
# 297 "../../sdk/cutil_math.h"
return make_float3((float)(a.x), (float)(a.y), (float)(a.z));
# 298 "../../sdk/cutil_math.h"
}
# 301 "../../sdk/cutil_math.h"
inline float3 operator-(float3 &a)
# 302 "../../sdk/cutil_math.h"
{
# 303 "../../sdk/cutil_math.h"
return make_float3(-(a.x), -(a.y), -(a.z));
# 304 "../../sdk/cutil_math.h"
}
# 307 "../../sdk/cutil_math.h"
static inline float3 fminf(float3 a, float3 b)
# 308 "../../sdk/cutil_math.h"
{
# 309 "../../sdk/cutil_math.h"
return make_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
# 310 "../../sdk/cutil_math.h"
}
# 313 "../../sdk/cutil_math.h"
static inline float3 fmaxf(float3 a, float3 b)
# 314 "../../sdk/cutil_math.h"
{
# 315 "../../sdk/cutil_math.h"
return make_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
# 316 "../../sdk/cutil_math.h"
}
# 319 "../../sdk/cutil_math.h"
inline float3 operator+(float3 a, float3 b)
# 320 "../../sdk/cutil_math.h"
{
# 321 "../../sdk/cutil_math.h"
return make_float3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 322 "../../sdk/cutil_math.h"
}
# 323 "../../sdk/cutil_math.h"
inline float3 operator+(float3 a, float b)
# 324 "../../sdk/cutil_math.h"
{
# 325 "../../sdk/cutil_math.h"
return make_float3((a.x) + b, (a.y) + b, (a.z) + b);
# 326 "../../sdk/cutil_math.h"
}
# 327 "../../sdk/cutil_math.h"
inline void operator+=(float3 &a, float3 b)
# 328 "../../sdk/cutil_math.h"
{
# 329 "../../sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 330 "../../sdk/cutil_math.h"
}
# 333 "../../sdk/cutil_math.h"
inline float3 operator-(float3 a, float3 b)
# 334 "../../sdk/cutil_math.h"
{
# 335 "../../sdk/cutil_math.h"
return make_float3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 336 "../../sdk/cutil_math.h"
}
# 337 "../../sdk/cutil_math.h"
inline float3 operator-(float3 a, float b)
# 338 "../../sdk/cutil_math.h"
{
# 339 "../../sdk/cutil_math.h"
return make_float3((a.x) - b, (a.y) - b, (a.z) - b);
# 340 "../../sdk/cutil_math.h"
}
# 341 "../../sdk/cutil_math.h"
inline void operator-=(float3 &a, float3 b)
# 342 "../../sdk/cutil_math.h"
{
# 343 "../../sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 344 "../../sdk/cutil_math.h"
}
# 347 "../../sdk/cutil_math.h"
inline float3 operator*(float3 a, float3 b)
# 348 "../../sdk/cutil_math.h"
{
# 349 "../../sdk/cutil_math.h"
return make_float3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 350 "../../sdk/cutil_math.h"
}
# 351 "../../sdk/cutil_math.h"
inline float3 operator*(float3 a, float s)
# 352 "../../sdk/cutil_math.h"
{
# 353 "../../sdk/cutil_math.h"
return make_float3((a.x) * s, (a.y) * s, (a.z) * s);
# 354 "../../sdk/cutil_math.h"
}
# 355 "../../sdk/cutil_math.h"
inline float3 operator*(float s, float3 a)
# 356 "../../sdk/cutil_math.h"
{
# 357 "../../sdk/cutil_math.h"
return make_float3((a.x) * s, (a.y) * s, (a.z) * s);
# 358 "../../sdk/cutil_math.h"
}
# 359 "../../sdk/cutil_math.h"
inline void operator*=(float3 &a, float s)
# 360 "../../sdk/cutil_math.h"
{
# 361 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 362 "../../sdk/cutil_math.h"
}
# 365 "../../sdk/cutil_math.h"
inline float3 operator/(float3 a, float3 b)
# 366 "../../sdk/cutil_math.h"
{
# 367 "../../sdk/cutil_math.h"
return make_float3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 368 "../../sdk/cutil_math.h"
}
# 369 "../../sdk/cutil_math.h"
inline float3 operator/(float3 a, float s)
# 370 "../../sdk/cutil_math.h"
{
# 371 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 372 "../../sdk/cutil_math.h"
return (a * inv);
# 373 "../../sdk/cutil_math.h"
}
# 374 "../../sdk/cutil_math.h"
inline float3 operator/(float s, float3 a)
# 375 "../../sdk/cutil_math.h"
{
# 376 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 377 "../../sdk/cutil_math.h"
return (a * inv);
# 378 "../../sdk/cutil_math.h"
}
# 379 "../../sdk/cutil_math.h"
inline void operator/=(float3 &a, float s)
# 380 "../../sdk/cutil_math.h"
{
# 381 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 382 "../../sdk/cutil_math.h"
((a) *= inv);
# 383 "../../sdk/cutil_math.h"
}
# 386 "../../sdk/cutil_math.h"
inline float3 lerp(float3 a, float3 b, float t)
# 387 "../../sdk/cutil_math.h"
{
# 388 "../../sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 389 "../../sdk/cutil_math.h"
}
# 392 "../../sdk/cutil_math.h"
inline float3 clamp(float3 v, float a, float b)
# 393 "../../sdk/cutil_math.h"
{
# 394 "../../sdk/cutil_math.h"
return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 395 "../../sdk/cutil_math.h"
}
# 397 "../../sdk/cutil_math.h"
inline float3 clamp(float3 v, float3 a, float3 b)
# 398 "../../sdk/cutil_math.h"
{
# 399 "../../sdk/cutil_math.h"
return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 400 "../../sdk/cutil_math.h"
}
# 403 "../../sdk/cutil_math.h"
inline float dot(float3 a, float3 b)
# 404 "../../sdk/cutil_math.h"
{
# 405 "../../sdk/cutil_math.h"
return (((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z));
# 406 "../../sdk/cutil_math.h"
}
# 409 "../../sdk/cutil_math.h"
inline float3 cross(float3 a, float3 b)
# 410 "../../sdk/cutil_math.h"
{
# 411 "../../sdk/cutil_math.h"
return make_float3(((a.y) * (b.z)) - ((a.z) * (b.y)), ((a.z) * (b.x)) - ((a.x) * (b.z)), ((a.x) * (b.y)) - ((a.y) * (b.x)));
# 412 "../../sdk/cutil_math.h"
}
# 415 "../../sdk/cutil_math.h"
inline float length(float3 v)
# 416 "../../sdk/cutil_math.h"
{
# 417 "../../sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 418 "../../sdk/cutil_math.h"
}
# 421 "../../sdk/cutil_math.h"
inline float3 normalize(float3 v)
# 422 "../../sdk/cutil_math.h"
{
# 423 "../../sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 424 "../../sdk/cutil_math.h"
return (v * invLen);
# 425 "../../sdk/cutil_math.h"
}
# 428 "../../sdk/cutil_math.h"
inline float3 floor(const float3 v)
# 429 "../../sdk/cutil_math.h"
{
# 430 "../../sdk/cutil_math.h"
return make_float3(floor(v.x), floor(v.y), floor(v.z));
# 431 "../../sdk/cutil_math.h"
}
# 434 "../../sdk/cutil_math.h"
inline float3 reflect(float3 i, float3 n)
# 435 "../../sdk/cutil_math.h"
{
# 436 "../../sdk/cutil_math.h"
return (i - ((((((2.0F)) * n)) * (dot(n, i)))));
# 437 "../../sdk/cutil_math.h"
}
# 440 "../../sdk/cutil_math.h"
inline float3 fabs(float3 v)
# 441 "../../sdk/cutil_math.h"
{
# 442 "../../sdk/cutil_math.h"
return make_float3(fabs(v.x), fabs(v.y), fabs(v.z));
# 443 "../../sdk/cutil_math.h"
}
# 449 "../../sdk/cutil_math.h"
inline float4 make_float4(float s)
# 450 "../../sdk/cutil_math.h"
{
# 451 "../../sdk/cutil_math.h"
return make_float4(s, s, s, s);
# 452 "../../sdk/cutil_math.h"
}
# 453 "../../sdk/cutil_math.h"
inline float4 make_float4(float3 a)
# 454 "../../sdk/cutil_math.h"
{
# 455 "../../sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, (0.0F));
# 456 "../../sdk/cutil_math.h"
}
# 457 "../../sdk/cutil_math.h"
inline float4 make_float4(float3 a, float w)
# 458 "../../sdk/cutil_math.h"
{
# 459 "../../sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, w);
# 460 "../../sdk/cutil_math.h"
}
# 461 "../../sdk/cutil_math.h"
inline float4 make_float4(int4 a)
# 462 "../../sdk/cutil_math.h"
{
# 463 "../../sdk/cutil_math.h"
return make_float4((float)(a.x), (float)(a.y), (float)(a.z), (float)(a.w));
# 464 "../../sdk/cutil_math.h"
}
# 467 "../../sdk/cutil_math.h"
inline float4 operator-(float4 &a)
# 468 "../../sdk/cutil_math.h"
{
# 469 "../../sdk/cutil_math.h"
return make_float4(-(a.x), -(a.y), -(a.z), -(a.w));
# 470 "../../sdk/cutil_math.h"
}
# 473 "../../sdk/cutil_math.h"
static inline float4 fminf(float4 a, float4 b)
# 474 "../../sdk/cutil_math.h"
{
# 475 "../../sdk/cutil_math.h"
return make_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
# 476 "../../sdk/cutil_math.h"
}
# 479 "../../sdk/cutil_math.h"
static inline float4 fmaxf(float4 a, float4 b)
# 480 "../../sdk/cutil_math.h"
{
# 481 "../../sdk/cutil_math.h"
return make_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
# 482 "../../sdk/cutil_math.h"
}
# 485 "../../sdk/cutil_math.h"
inline float4 operator+(float4 a, float4 b)
# 486 "../../sdk/cutil_math.h"
{
# 487 "../../sdk/cutil_math.h"
return make_float4((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z), (a.w) + (b.w));
# 488 "../../sdk/cutil_math.h"
}
# 489 "../../sdk/cutil_math.h"
inline void operator+=(float4 &a, float4 b)
# 490 "../../sdk/cutil_math.h"
{
# 491 "../../sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z); (a.w) += (b.w);
# 492 "../../sdk/cutil_math.h"
}
# 495 "../../sdk/cutil_math.h"
inline float4 operator-(float4 a, float4 b)
# 496 "../../sdk/cutil_math.h"
{
# 497 "../../sdk/cutil_math.h"
return make_float4((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z), (a.w) - (b.w));
# 498 "../../sdk/cutil_math.h"
}
# 499 "../../sdk/cutil_math.h"
inline void operator-=(float4 &a, float4 b)
# 500 "../../sdk/cutil_math.h"
{
# 501 "../../sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z); (a.w) -= (b.w);
# 502 "../../sdk/cutil_math.h"
}
# 505 "../../sdk/cutil_math.h"
inline float4 operator*(float4 a, float s)
# 506 "../../sdk/cutil_math.h"
{
# 507 "../../sdk/cutil_math.h"
return make_float4((a.x) * s, (a.y) * s, (a.z) * s, (a.w) * s);
# 508 "../../sdk/cutil_math.h"
}
# 509 "../../sdk/cutil_math.h"
inline float4 operator*(float s, float4 a)
# 510 "../../sdk/cutil_math.h"
{
# 511 "../../sdk/cutil_math.h"
return make_float4((a.x) * s, (a.y) * s, (a.z) * s, (a.w) * s);
# 512 "../../sdk/cutil_math.h"
}
# 513 "../../sdk/cutil_math.h"
inline void operator*=(float4 &a, float s)
# 514 "../../sdk/cutil_math.h"
{
# 515 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s; (a.w) *= s;
# 516 "../../sdk/cutil_math.h"
}
# 519 "../../sdk/cutil_math.h"
inline float4 operator/(float4 a, float4 b)
# 520 "../../sdk/cutil_math.h"
{
# 521 "../../sdk/cutil_math.h"
return make_float4((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z), (a.w) / (b.w));
# 522 "../../sdk/cutil_math.h"
}
# 523 "../../sdk/cutil_math.h"
inline float4 operator/(float4 a, float s)
# 524 "../../sdk/cutil_math.h"
{
# 525 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 526 "../../sdk/cutil_math.h"
return (a * inv);
# 527 "../../sdk/cutil_math.h"
}
# 528 "../../sdk/cutil_math.h"
inline float4 operator/(float s, float4 a)
# 529 "../../sdk/cutil_math.h"
{
# 530 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 531 "../../sdk/cutil_math.h"
return (a * inv);
# 532 "../../sdk/cutil_math.h"
}
# 533 "../../sdk/cutil_math.h"
inline void operator/=(float4 &a, float s)
# 534 "../../sdk/cutil_math.h"
{
# 535 "../../sdk/cutil_math.h"
float inv = ((1.0F) / s);
# 536 "../../sdk/cutil_math.h"
((a) *= inv);
# 537 "../../sdk/cutil_math.h"
}
# 540 "../../sdk/cutil_math.h"
inline float4 lerp(float4 a, float4 b, float t)
# 541 "../../sdk/cutil_math.h"
{
# 542 "../../sdk/cutil_math.h"
return (a + ((t * ((b - a)))));
# 543 "../../sdk/cutil_math.h"
}
# 546 "../../sdk/cutil_math.h"
inline float4 clamp(float4 v, float a, float b)
# 547 "../../sdk/cutil_math.h"
{
# 548 "../../sdk/cutil_math.h"
return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
# 549 "../../sdk/cutil_math.h"
}
# 551 "../../sdk/cutil_math.h"
inline float4 clamp(float4 v, float4 a, float4 b)
# 552 "../../sdk/cutil_math.h"
{
# 553 "../../sdk/cutil_math.h"
return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
# 554 "../../sdk/cutil_math.h"
}
# 557 "../../sdk/cutil_math.h"
inline float dot(float4 a, float4 b)
# 558 "../../sdk/cutil_math.h"
{
# 559 "../../sdk/cutil_math.h"
return ((((a.x) * (b.x)) + ((a.y) * (b.y))) + ((a.z) * (b.z))) + ((a.w) * (b.w));
# 560 "../../sdk/cutil_math.h"
}
# 563 "../../sdk/cutil_math.h"
inline float length(float4 r)
# 564 "../../sdk/cutil_math.h"
{
# 565 "../../sdk/cutil_math.h"
return sqrtf(dot(r, r));
# 566 "../../sdk/cutil_math.h"
}
# 569 "../../sdk/cutil_math.h"
inline float4 normalize(float4 v)
# 570 "../../sdk/cutil_math.h"
{
# 571 "../../sdk/cutil_math.h"
float invLen = rsqrtf(dot(v, v));
# 572 "../../sdk/cutil_math.h"
return (v * invLen);
# 573 "../../sdk/cutil_math.h"
}
# 576 "../../sdk/cutil_math.h"
inline float4 floor(const float4 v)
# 577 "../../sdk/cutil_math.h"
{
# 578 "../../sdk/cutil_math.h"
return make_float4(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
# 579 "../../sdk/cutil_math.h"
}
# 582 "../../sdk/cutil_math.h"
inline float4 fabs(float4 v)
# 583 "../../sdk/cutil_math.h"
{
# 584 "../../sdk/cutil_math.h"
return make_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
# 585 "../../sdk/cutil_math.h"
}
# 591 "../../sdk/cutil_math.h"
inline int3 make_int3(int s)
# 592 "../../sdk/cutil_math.h"
{
# 593 "../../sdk/cutil_math.h"
return make_int3(s, s, s);
# 594 "../../sdk/cutil_math.h"
}
# 595 "../../sdk/cutil_math.h"
inline int3 make_int3(float3 a)
# 596 "../../sdk/cutil_math.h"
{
# 597 "../../sdk/cutil_math.h"
return make_int3((int)(a.x), (int)(a.y), (int)(a.z));
# 598 "../../sdk/cutil_math.h"
}
# 601 "../../sdk/cutil_math.h"
inline int3 operator-(int3 &a)
# 602 "../../sdk/cutil_math.h"
{
# 603 "../../sdk/cutil_math.h"
return make_int3(-(a.x), -(a.y), -(a.z));
# 604 "../../sdk/cutil_math.h"
}
# 607 "../../sdk/cutil_math.h"
inline int3 min(int3 a, int3 b)
# 608 "../../sdk/cutil_math.h"
{
# 609 "../../sdk/cutil_math.h"
return make_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 610 "../../sdk/cutil_math.h"
}
# 613 "../../sdk/cutil_math.h"
inline int3 max(int3 a, int3 b)
# 614 "../../sdk/cutil_math.h"
{
# 615 "../../sdk/cutil_math.h"
return make_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 616 "../../sdk/cutil_math.h"
}
# 619 "../../sdk/cutil_math.h"
inline int3 operator+(int3 a, int3 b)
# 620 "../../sdk/cutil_math.h"
{
# 621 "../../sdk/cutil_math.h"
return make_int3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 622 "../../sdk/cutil_math.h"
}
# 623 "../../sdk/cutil_math.h"
inline void operator+=(int3 &a, int3 b)
# 624 "../../sdk/cutil_math.h"
{
# 625 "../../sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 626 "../../sdk/cutil_math.h"
}
# 629 "../../sdk/cutil_math.h"
inline int3 operator-(int3 a, int3 b)
# 630 "../../sdk/cutil_math.h"
{
# 631 "../../sdk/cutil_math.h"
return make_int3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 632 "../../sdk/cutil_math.h"
}
# 634 "../../sdk/cutil_math.h"
inline void operator-=(int3 &a, int3 b)
# 635 "../../sdk/cutil_math.h"
{
# 636 "../../sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 637 "../../sdk/cutil_math.h"
}
# 640 "../../sdk/cutil_math.h"
inline int3 operator*(int3 a, int3 b)
# 641 "../../sdk/cutil_math.h"
{
# 642 "../../sdk/cutil_math.h"
return make_int3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 643 "../../sdk/cutil_math.h"
}
# 644 "../../sdk/cutil_math.h"
inline int3 operator*(int3 a, int s)
# 645 "../../sdk/cutil_math.h"
{
# 646 "../../sdk/cutil_math.h"
return make_int3((a.x) * s, (a.y) * s, (a.z) * s);
# 647 "../../sdk/cutil_math.h"
}
# 648 "../../sdk/cutil_math.h"
inline int3 operator*(int s, int3 a)
# 649 "../../sdk/cutil_math.h"
{
# 650 "../../sdk/cutil_math.h"
return make_int3((a.x) * s, (a.y) * s, (a.z) * s);
# 651 "../../sdk/cutil_math.h"
}
# 652 "../../sdk/cutil_math.h"
inline void operator*=(int3 &a, int s)
# 653 "../../sdk/cutil_math.h"
{
# 654 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 655 "../../sdk/cutil_math.h"
}
# 658 "../../sdk/cutil_math.h"
inline int3 operator/(int3 a, int3 b)
# 659 "../../sdk/cutil_math.h"
{
# 660 "../../sdk/cutil_math.h"
return make_int3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 661 "../../sdk/cutil_math.h"
}
# 662 "../../sdk/cutil_math.h"
inline int3 operator/(int3 a, int s)
# 663 "../../sdk/cutil_math.h"
{
# 664 "../../sdk/cutil_math.h"
return make_int3((a.x) / s, (a.y) / s, (a.z) / s);
# 665 "../../sdk/cutil_math.h"
}
# 666 "../../sdk/cutil_math.h"
inline int3 operator/(int s, int3 a)
# 667 "../../sdk/cutil_math.h"
{
# 668 "../../sdk/cutil_math.h"
return make_int3((a.x) / s, (a.y) / s, (a.z) / s);
# 669 "../../sdk/cutil_math.h"
}
# 670 "../../sdk/cutil_math.h"
inline void operator/=(int3 &a, int s)
# 671 "../../sdk/cutil_math.h"
{
# 672 "../../sdk/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 673 "../../sdk/cutil_math.h"
}
# 676 "../../sdk/cutil_math.h"
inline int clamp(int f, int a, int b)
# 677 "../../sdk/cutil_math.h"
{
# 678 "../../sdk/cutil_math.h"
return max(a, min(f, b));
# 679 "../../sdk/cutil_math.h"
}
# 681 "../../sdk/cutil_math.h"
inline int3 clamp(int3 v, int a, int b)
# 682 "../../sdk/cutil_math.h"
{
# 683 "../../sdk/cutil_math.h"
return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 684 "../../sdk/cutil_math.h"
}
# 686 "../../sdk/cutil_math.h"
inline int3 clamp(int3 v, int3 a, int3 b)
# 687 "../../sdk/cutil_math.h"
{
# 688 "../../sdk/cutil_math.h"
return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 689 "../../sdk/cutil_math.h"
}
# 696 "../../sdk/cutil_math.h"
inline uint3 make_uint3(uint s)
# 697 "../../sdk/cutil_math.h"
{
# 698 "../../sdk/cutil_math.h"
return make_uint3(s, s, s);
# 699 "../../sdk/cutil_math.h"
}
# 700 "../../sdk/cutil_math.h"
inline uint3 make_uint3(float3 a)
# 701 "../../sdk/cutil_math.h"
{
# 702 "../../sdk/cutil_math.h"
return make_uint3((uint)(a.x), (uint)(a.y), (uint)(a.z));
# 703 "../../sdk/cutil_math.h"
}
# 706 "../../sdk/cutil_math.h"
inline uint3 min(uint3 a, uint3 b)
# 707 "../../sdk/cutil_math.h"
{
# 708 "../../sdk/cutil_math.h"
return make_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 709 "../../sdk/cutil_math.h"
}
# 712 "../../sdk/cutil_math.h"
inline uint3 max(uint3 a, uint3 b)
# 713 "../../sdk/cutil_math.h"
{
# 714 "../../sdk/cutil_math.h"
return make_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 715 "../../sdk/cutil_math.h"
}
# 718 "../../sdk/cutil_math.h"
inline uint3 operator+(uint3 a, uint3 b)
# 719 "../../sdk/cutil_math.h"
{
# 720 "../../sdk/cutil_math.h"
return make_uint3((a.x) + (b.x), (a.y) + (b.y), (a.z) + (b.z));
# 721 "../../sdk/cutil_math.h"
}
# 722 "../../sdk/cutil_math.h"
inline void operator+=(uint3 &a, uint3 b)
# 723 "../../sdk/cutil_math.h"
{
# 724 "../../sdk/cutil_math.h"
(a.x) += (b.x); (a.y) += (b.y); (a.z) += (b.z);
# 725 "../../sdk/cutil_math.h"
}
# 728 "../../sdk/cutil_math.h"
inline uint3 operator-(uint3 a, uint3 b)
# 729 "../../sdk/cutil_math.h"
{
# 730 "../../sdk/cutil_math.h"
return make_uint3((a.x) - (b.x), (a.y) - (b.y), (a.z) - (b.z));
# 731 "../../sdk/cutil_math.h"
}
# 733 "../../sdk/cutil_math.h"
inline void operator-=(uint3 &a, uint3 b)
# 734 "../../sdk/cutil_math.h"
{
# 735 "../../sdk/cutil_math.h"
(a.x) -= (b.x); (a.y) -= (b.y); (a.z) -= (b.z);
# 736 "../../sdk/cutil_math.h"
}
# 739 "../../sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint3 b)
# 740 "../../sdk/cutil_math.h"
{
# 741 "../../sdk/cutil_math.h"
return make_uint3((a.x) * (b.x), (a.y) * (b.y), (a.z) * (b.z));
# 742 "../../sdk/cutil_math.h"
}
# 743 "../../sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint s)
# 744 "../../sdk/cutil_math.h"
{
# 745 "../../sdk/cutil_math.h"
return make_uint3((a.x) * s, (a.y) * s, (a.z) * s);
# 746 "../../sdk/cutil_math.h"
}
# 747 "../../sdk/cutil_math.h"
inline uint3 operator*(uint s, uint3 a)
# 748 "../../sdk/cutil_math.h"
{
# 749 "../../sdk/cutil_math.h"
return make_uint3((a.x) * s, (a.y) * s, (a.z) * s);
# 750 "../../sdk/cutil_math.h"
}
# 751 "../../sdk/cutil_math.h"
inline void operator*=(uint3 &a, uint s)
# 752 "../../sdk/cutil_math.h"
{
# 753 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 754 "../../sdk/cutil_math.h"
}
# 757 "../../sdk/cutil_math.h"
inline uint3 operator/(uint3 a, uint3 b)
# 758 "../../sdk/cutil_math.h"
{
# 759 "../../sdk/cutil_math.h"
return make_uint3((a.x) / (b.x), (a.y) / (b.y), (a.z) / (b.z));
# 760 "../../sdk/cutil_math.h"
}
# 761 "../../sdk/cutil_math.h"
inline uint3 operator/(uint3 a, uint s)
# 762 "../../sdk/cutil_math.h"
{
# 763 "../../sdk/cutil_math.h"
return make_uint3((a.x) / s, (a.y) / s, (a.z) / s);
# 764 "../../sdk/cutil_math.h"
}
# 765 "../../sdk/cutil_math.h"
inline uint3 operator/(uint s, uint3 a)
# 766 "../../sdk/cutil_math.h"
{
# 767 "../../sdk/cutil_math.h"
return make_uint3((a.x) / s, (a.y) / s, (a.z) / s);
# 768 "../../sdk/cutil_math.h"
}
# 769 "../../sdk/cutil_math.h"
inline void operator/=(uint3 &a, uint s)
# 770 "../../sdk/cutil_math.h"
{
# 771 "../../sdk/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 772 "../../sdk/cutil_math.h"
}
# 775 "../../sdk/cutil_math.h"
inline uint clamp(uint f, uint a, uint b)
# 776 "../../sdk/cutil_math.h"
{
# 777 "../../sdk/cutil_math.h"
return max(a, min(f, b));
# 778 "../../sdk/cutil_math.h"
}
# 780 "../../sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint a, uint b)
# 781 "../../sdk/cutil_math.h"
{
# 782 "../../sdk/cutil_math.h"
return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 783 "../../sdk/cutil_math.h"
}
# 785 "../../sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint3 a, uint3 b)
# 786 "../../sdk/cutil_math.h"
{
# 787 "../../sdk/cutil_math.h"
return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 788 "../../sdk/cutil_math.h"
}
# 44 "CudaMath.h"
inline float3 firstEigenVector(float matrix[6])
# 45 "CudaMath.h"
{
# 48 "CudaMath.h"
float3 v = make_float3((1.0F), (1.0F), (1.0F));
# 49 "CudaMath.h"
for (int i = 0; i < 8; i++) {
# 50 "CudaMath.h"
float x = ((((v.x) * (matrix[0])) + ((v.y) * (matrix[1]))) + ((v.z) * (matrix[2])));
# 51 "CudaMath.h"
float y = ((((v.x) * (matrix[1])) + ((v.y) * (matrix[3]))) + ((v.z) * (matrix[4])));
# 52 "CudaMath.h"
float z = ((((v.x) * (matrix[2])) + ((v.y) * (matrix[4]))) + ((v.z) * (matrix[5])));
# 53 "CudaMath.h"
float m = max(max(x, y), z);
# 54 "CudaMath.h"
float iv = ((1.0F) / m);
# 58 "CudaMath.h"
v = make_float3(x * iv, y * iv, z * iv);
# 59 "CudaMath.h"
}
# 61 "CudaMath.h"
return v;
# 62 "CudaMath.h"
}
# 64 "CudaMath.h"
static inline void colorSums(const float3 *colors, float3 *sums)
# 65 "CudaMath.h"
{exit(1);
# 88 "CudaMath.h"
}
# 91 "CudaMath.h"
static inline float3 bestFitLine(const float3 *colors, float3 color_sum)
# 92 "CudaMath.h"
{exit(1);
# 142 "CudaMath.h"
}
# 45 "dds.h"
extern "C" { typedef unsigned uint; }
# 46 "dds.h"
extern "C" { typedef unsigned short ushort; }
# 48 "dds.h"
struct DDSPixelFormat {
# 49 "dds.h"
uint size;
# 50 "dds.h"
uint flags;
# 51 "dds.h"
uint fourcc;
# 52 "dds.h"
uint bitcount;
# 53 "dds.h"
uint rmask;
# 54 "dds.h"
uint gmask;
# 55 "dds.h"
uint bmask;
# 56 "dds.h"
uint amask;
# 57 "dds.h"
};
# 59 "dds.h"
struct DDSCaps {
# 60 "dds.h"
uint caps1;
# 61 "dds.h"
uint caps2;
# 62 "dds.h"
uint caps3;
# 63 "dds.h"
uint caps4;
# 64 "dds.h"
};
# 67 "dds.h"
struct DDSHeader {
# 68 "dds.h"
uint fourcc;
# 69 "dds.h"
uint size;
# 70 "dds.h"
uint flags;
# 71 "dds.h"
uint height;
# 72 "dds.h"
uint width;
# 73 "dds.h"
uint pitch;
# 74 "dds.h"
uint depth;
# 75 "dds.h"
uint mipmapcount;
# 76 "dds.h"
uint reserved[11];
# 77 "dds.h"
DDSPixelFormat pf;
# 78 "dds.h"
DDSCaps caps;
# 79 "dds.h"
uint notused;
# 80 "dds.h"
};
# 82 "dds.h"
static const uint FOURCC_DDS = (((((unsigned)'D') | (((unsigned)'D') << 8)) | (((unsigned)'S') << 16)) | (((unsigned)' ') << 24));
# 83 "dds.h"
static const uint FOURCC_DXT1 = (((((unsigned)'D') | (((unsigned)'X') << 8)) | (((unsigned)'T') << 16)) | (((unsigned)'1') << 24));
# 84 "dds.h"
static const uint DDSD_WIDTH = 4U;
# 85 "dds.h"
static const uint DDSD_HEIGHT = 2U;
# 86 "dds.h"
static const uint DDSD_CAPS = 1U;
# 87 "dds.h"
static const uint DDSD_PIXELFORMAT = 4096U;
# 88 "dds.h"
static const uint DDSCAPS_TEXTURE = 4096U;
# 89 "dds.h"
static const uint DDPF_FOURCC = 4U;
# 90 "dds.h"
static const uint DDSD_LINEARSIZE = 524288U;
# 42 "permutations.h"
static void computePermutations(uint permutations[1024])
# 43 "permutations.h"
{
# 44 "permutations.h"
int indices[16];
# 45 "permutations.h"
int num = 0;
# 50 "permutations.h"
for (int m = 0; m < 16; ++m)
# 51 "permutations.h"
{
# 52 "permutations.h"
((indices)[m]) = 0;
# 53 "permutations.h"
}
# 54 "permutations.h"
const int imax = 15;
# 55 "permutations.h"
for (int i = imax; i >= 0; --i)
# 56 "permutations.h"
{
# 58 "permutations.h"
for (int m = i; m < 16; ++m)
# 59 "permutations.h"
{
# 60 "permutations.h"
((indices)[m]) = 2;
# 61 "permutations.h"
}
# 62 "permutations.h"
const int jmax = ((i == 0) ? 15 : 16);
# 63 "permutations.h"
for (int j = jmax; j >= i; --j)
# 64 "permutations.h"
{
# 66 "permutations.h"
if (j < 16)
# 67 "permutations.h"
{
# 68 "permutations.h"
((indices)[j]) = 1;
# 69 "permutations.h"
}
# 71 "permutations.h"
uint permutation = (0);
# 73 "permutations.h"
for (int p = 0; p < 16; p++) {
# 74 "permutations.h"
permutation |= (((indices)[p]) << (p * 2));
# 76 "permutations.h"
}
# 78 "permutations.h"
(permutations[num]) = permutation;
# 80 "permutations.h"
num++;
# 81 "permutations.h"
}
# 82 "permutations.h"
}
# 83 "permutations.h"
__cutilCondition(num == 151, (char *)("permutations.h"), 83);
# 85 "permutations.h"
for (int i = 0; i < 9; i++)
# 86 "permutations.h"
{
# 87 "permutations.h"
(permutations[num]) = (697685);
# 88 "permutations.h"
num++;
# 89 "permutations.h"
}
# 90 "permutations.h"
__cutilCondition(num == 160, (char *)("permutations.h"), 90);
# 95 "permutations.h"
for (int m = 0; m < 16; ++m)
# 96 "permutations.h"
{
# 97 "permutations.h"
((indices)[m]) = 0;
# 98 "permutations.h"
}
# 100 "permutations.h"
for (int i = imax; i >= 0; --i)
# 101 "permutations.h"
{
# 103 "permutations.h"
for (int m = i; m < 16; ++m)
# 104 "permutations.h"
{
# 105 "permutations.h"
((indices)[m]) = 2;
# 106 "permutations.h"
}
# 107 "permutations.h"
const int jmax = ((i == 0) ? 15 : 16);
# 108 "permutations.h"
for (int j = jmax; j >= i; --j)
# 109 "permutations.h"
{
# 111 "permutations.h"
for (int m = j; m < 16; ++m)
# 112 "permutations.h"
{
# 113 "permutations.h"
((indices)[m]) = 3;
# 114 "permutations.h"
}
# 116 "permutations.h"
int kmax = ((j == 0) ? 15 : 16);
# 117 "permutations.h"
for (int k = kmax; k >= j; --k)
# 118 "permutations.h"
{
# 120 "permutations.h"
if (k < 16)
# 121 "permutations.h"
{
# 122 "permutations.h"
((indices)[k]) = 1;
# 123 "permutations.h"
}
# 125 "permutations.h"
uint permutation = (0);
# 127 "permutations.h"
bool hasThree = false;
# 128 "permutations.h"
for (int p = 0; p < 16; p++) {
# 129 "permutations.h"
permutation |= (((indices)[p]) << (p * 2));
# 132 "permutations.h"
if (((indices)[p]) == 3) { hasThree = true; }
# 133 "permutations.h"
}
# 135 "permutations.h"
if (hasThree) {
# 136 "permutations.h"
(permutations[num]) = permutation;
# 137 "permutations.h"
num++;
# 138 "permutations.h"
}
# 139 "permutations.h"
}
# 140 "permutations.h"
}
# 141 "permutations.h"
}
# 142 "permutations.h"
__cutilCondition(num == 975, (char *)("permutations.h"), 142);
# 147 "permutations.h"
for (int i = 0; i < 49; i++)
# 148 "permutations.h"
{
# 149 "permutations.h"
(permutations[num]) = (11206485);
# 150 "permutations.h"
num++;
# 151 "permutations.h"
}
# 153 "permutations.h"
__cutilCondition(num == 1024, (char *)("permutations.h"), 153);
# 154 "permutations.h"
}
# 69 "dxtc.cu"
template<class T> static inline void
# 70 "dxtc.cu"
swap(T &a, T &b)
# 71 "dxtc.cu"
{exit(1);
# 75 "dxtc.cu"
}
# 79 "dxtc.cu"
static float3 kColorMetric__cuda_shadow_variable__;
# 85 "dxtc.cu"
static void sortColors(const float *values, int *ranks)
# 86 "dxtc.cu"
{exit(1);
# 130 "dxtc.cu"
}
# 136 "dxtc.cu"
static void loadColorBlock(const uint *image, float3 colors[16], float3 sums[16], int xrefs[16])
# 137 "dxtc.cu"
{exit(1);
# 180 "dxtc.cu"
}
# 187 "dxtc.cu"
static inline float3 roundAndExpand(float3 v, ushort *w)
# 188 "dxtc.cu"
{exit(1);
# 198 "dxtc.cu"
}
# 201 "dxtc.cu"
static float alphaTable4__cuda_shadow_variable__[4];
# 202 "dxtc.cu"
static float alphaTable3__cuda_shadow_variable__[4];
# 203 "dxtc.cu"
static int prods4__cuda_shadow_variable__[4];
# 204 "dxtc.cu"
static int prods3__cuda_shadow_variable__[4];
# 211 "dxtc.cu"
static float evalPermutation4(const float3 *colors, uint permutation, ushort *start, ushort *end, float3 color_sum)
# 212 "dxtc.cu"
{exit(1);
# 270 "dxtc.cu"
}
# 272 "dxtc.cu"
static float evalPermutation3(const float3 *colors, uint permutation, ushort *start, ushort *end, float3 color_sum)
# 273 "dxtc.cu"
{exit(1);
# 330 "dxtc.cu"
}
# 334 "dxtc.cu"
static void evalAllPermutations(const float3 *colors, const uint *permutations, ushort &bestStart, ushort &bestEnd, uint &bestPermutation, float *errors, float3 color_sum)
# 335 "dxtc.cu"
{exit(1);
# 393 "dxtc.cu"
}
# 399 "dxtc.cu"
static int findMinError(float *errors)
# 400 "dxtc.cu"
{exit(1);
# 475 "dxtc.cu"
}
# 481 "dxtc.cu"
static void saveBlockDXT1(ushort start, ushort end, uint permutation, int xrefs[16], uint2 *result)
# 482 "dxtc.cu"
{exit(1);
# 503 "dxtc.cu"
}
# 509 "dxtc.cu"
void compress__entry(const uint *permutations, const uint *image, uint2 *result);
# 545 "dxtc.cu"
union Color32 {
# 546 "dxtc.cu"
struct {
# 547 "dxtc.cu"
unsigned char b, g, r, a;
# 548 "dxtc.cu"
};
# 549 "dxtc.cu"
unsigned u;
# 550 "dxtc.cu"
};
# 552 "dxtc.cu"
union Color16 {
# 553 "dxtc.cu"
struct {
# 554 "dxtc.cu"
unsigned short b:5;
# 555 "dxtc.cu"
unsigned short g:6;
# 556 "dxtc.cu"
unsigned short r:5;
# 557 "dxtc.cu"
};
# 558 "dxtc.cu"
unsigned short u;
# 559 "dxtc.cu"
};
# 561 "dxtc.cu"
struct BlockDXT1 {
# 563 "dxtc.cu"
Color16 col0;
# 564 "dxtc.cu"
Color16 col1;
# 565 "dxtc.cu"
union {
# 566 "dxtc.cu"
unsigned char row[4];
# 567 "dxtc.cu"
unsigned indices;
# 568 "dxtc.cu"
};
# 570 "dxtc.cu"
void decompress(Color32 [16]) const;
# 571 "dxtc.cu"
};
# 573 "dxtc.cu"
void BlockDXT1::decompress(Color32 *colors) const
# 574 "dxtc.cu"
{
# 575 "dxtc.cu"
Color32 palette[4];
# 578 "dxtc.cu"
(((palette)[0]).b) = ((((col0).b) << 3) | (((col0).b) >> 2));
# 579 "dxtc.cu"
(((palette)[0]).g) = ((((col0).g) << 2) | (((col0).g) >> 4));
# 580 "dxtc.cu"
(((palette)[0]).r) = ((((col0).r) << 3) | (((col0).r) >> 2));
# 581 "dxtc.cu"
(((palette)[0]).a) = (255);
# 583 "dxtc.cu"
(((palette)[1]).r) = ((((col1).r) << 3) | (((col1).r) >> 2));
# 584 "dxtc.cu"
(((palette)[1]).g) = ((((col1).g) << 2) | (((col1).g) >> 4));
# 585 "dxtc.cu"
(((palette)[1]).b) = ((((col1).b) << 3) | (((col1).b) >> 2));
# 586 "dxtc.cu"
(((palette)[1]).a) = (255);
# 588 "dxtc.cu"
if (((col0).u) > ((col1).u)) {
# 590 "dxtc.cu"
(((palette)[2]).r) = (((2 * (((palette)[0]).r)) + (((palette)[1]).r)) / 3);
# 591 "dxtc.cu"
(((palette)[2]).g) = (((2 * (((palette)[0]).g)) + (((palette)[1]).g)) / 3);
# 592 "dxtc.cu"
(((palette)[2]).b) = (((2 * (((palette)[0]).b)) + (((palette)[1]).b)) / 3);
# 593 "dxtc.cu"
(((palette)[2]).a) = (255);
# 595 "dxtc.cu"
(((palette)[3]).r) = (((2 * (((palette)[1]).r)) + (((palette)[0]).r)) / 3);
# 596 "dxtc.cu"
(((palette)[3]).g) = (((2 * (((palette)[1]).g)) + (((palette)[0]).g)) / 3);
# 597 "dxtc.cu"
(((palette)[3]).b) = (((2 * (((palette)[1]).b)) + (((palette)[0]).b)) / 3);
# 598 "dxtc.cu"
(((palette)[3]).a) = (255);
# 599 "dxtc.cu"
} else
# 600 "dxtc.cu"
{
# 602 "dxtc.cu"
(((palette)[2]).r) = (((((palette)[0]).r) + (((palette)[1]).r)) / 2);
# 603 "dxtc.cu"
(((palette)[2]).g) = (((((palette)[0]).g) + (((palette)[1]).g)) / 2);
# 604 "dxtc.cu"
(((palette)[2]).b) = (((((palette)[0]).b) + (((palette)[1]).b)) / 2);
# 605 "dxtc.cu"
(((palette)[2]).a) = (255);
# 607 "dxtc.cu"
(((palette)[3]).r) = (0);
# 608 "dxtc.cu"
(((palette)[3]).g) = (0);
# 609 "dxtc.cu"
(((palette)[3]).b) = (0);
# 610 "dxtc.cu"
(((palette)[3]).a) = (0);
# 611 "dxtc.cu"
}
# 613 "dxtc.cu"
for (int i = 0; i < 16; i++)
# 614 "dxtc.cu"
{
# 615 "dxtc.cu"
(colors[i]) = ((palette)[((indices) >> (2 * i)) & (3)]);
# 616 "dxtc.cu"
}
# 617 "dxtc.cu"
}
# 619 "dxtc.cu"
static int compareColors(const Color32 *b0, const Color32 *b1)
# 620 "dxtc.cu"
{
# 621 "dxtc.cu"
int sum = 0;
# 622 "dxtc.cu"
for (int i = 0; i < 16; i++)
# 623 "dxtc.cu"
{
# 624 "dxtc.cu"
int r = (((b0[i]).r) - ((b1[i]).r));
# 625 "dxtc.cu"
int g = (((b0[i]).g) - ((b1[i]).g));
# 626 "dxtc.cu"
int b = (((b0[i]).b) - ((b1[i]).b));
# 627 "dxtc.cu"
sum += (((r * r) + (g * g)) + (b * b));
# 628 "dxtc.cu"
}
# 629 "dxtc.cu"
return sum;
# 630 "dxtc.cu"
}
# 632 "dxtc.cu"
static int compareBlock(const BlockDXT1 *b0, const BlockDXT1 *b1)
# 633 "dxtc.cu"
{
# 634 "dxtc.cu"
Color32 colors0[16];
# 635 "dxtc.cu"
Color32 colors1[16];
# 637 "dxtc.cu"
if (memcmp(b0, b1, sizeof(BlockDXT1)) == 0)
# 638 "dxtc.cu"
{
# 639 "dxtc.cu"
return 0;
# 640 "dxtc.cu"
} else
# 642 "dxtc.cu"
{
# 643 "dxtc.cu"
b0->decompress(colors0);
# 644 "dxtc.cu"
b1->decompress(colors1);
# 646 "dxtc.cu"
return compareColors(colors0, colors1);
# 647 "dxtc.cu"
}
# 648 "dxtc.cu"
}
# 654 "dxtc.cu"
int main(int argc, char **argv)
# 655 "dxtc.cu"
{
# 657 "dxtc.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 658 "dxtc.cu"
cutilDeviceInit(argc, argv); } else {
# 660 "dxtc.cu"
cudaSetDevice(cutGetMaxGflopsDeviceId()); }
# 663 "dxtc.cu"
unsigned char *data = (__null);
# 664 "dxtc.cu"
uint W, H;
# 666 "dxtc.cu"
char *image_path = cutFindFilePath("lena_std.ppm", argv[0]);
# 667 "dxtc.cu"
if (image_path == (0)) {
# 668 "dxtc.cu"
printf("Error, unable to find source image\n");
# 669 "dxtc.cu"
cudaThreadExit();
# 670 "dxtc.cu"
exit(1);
# 671 "dxtc.cu"
}
# 673 "dxtc.cu"
if (!(cutLoadPPM4ub(image_path, &data, &W, &H))) {
# 674 "dxtc.cu"
printf("Error, unable to open source image\n");
# 675 "dxtc.cu"
cudaThreadExit();
# 676 "dxtc.cu"
exit(1);
# 677 "dxtc.cu"
}
# 679 "dxtc.cu"
uint w, h;
# 682 "dxtc.cu"
w = (W >> 4);
# 683 "dxtc.cu"
h = (H >> 4);
# 690 "dxtc.cu"
const uint memSize = ((w * h) * (4));
# 691 "dxtc.cu"
__cutilCondition((0) != memSize, (char *)("dxtc.cu"), 691);
# 693 "dxtc.cu"
uint *image = ((uint *)malloc(memSize));
# 696 "dxtc.cu"
for (uint by = (0); by < (h / (4)); by++) {
# 697 "dxtc.cu"
for (uint bx = (0); bx < (w / (4)); bx++) {
# 698 "dxtc.cu"
for (int i = 0; i < 16; i++) {
# 699 "dxtc.cu"
const int x = (i & 3);
# 700 "dxtc.cu"
const int y = (i / 4);
# 701 "dxtc.cu"
(image[((((by * w) / (4)) + bx) * (16)) + i]) = (((uint *)data)[(((((by * (4)) + y) * (4)) * (W / (4))) + (bx * (4))) + x]);
# 703 "dxtc.cu"
}
# 704 "dxtc.cu"
}
# 705 "dxtc.cu"
}
# 708 "dxtc.cu"
uint *d_data = (__null);
# 709 "dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_data), memSize), "dxtc.cu", 709);
# 712 "dxtc.cu"
uint *d_result = (__null);
# 713 "dxtc.cu"
const uint compressedSize = (((w / (4)) * (h / (4))) * (8));
# 714 "dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_result), compressedSize), "dxtc.cu", 714);
# 715 "dxtc.cu"
uint *result = ((uint *)malloc(compressedSize));
# 718 "dxtc.cu"
uint permutations[1024];
# 719 "dxtc.cu"
computePermutations(permutations);
# 722 "dxtc.cu"
uint *d_permutations = (__null);
# 723 "dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_permutations), (1024) * sizeof(uint)), "dxtc.cu", 723);
# 724 "dxtc.cu"
__cudaSafeCall(cudaMemcpy(d_permutations, permutations, (1024) * sizeof(uint), cudaMemcpyHostToDevice), "dxtc.cu", 725);
# 728 "dxtc.cu"
uint timer;
# 729 "dxtc.cu"
__cutilCheckError(cutCreateTimer(&timer), "dxtc.cu", 729);
# 731 "dxtc.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dxtc.cu", 731);
# 732 "dxtc.cu"
__cutilCheckError(cutStartTimer(timer), "dxtc.cu", 732);
# 735 "dxtc.cu"
__cudaSafeCall(cudaMemcpy(d_data, image, memSize, cudaMemcpyHostToDevice), "dxtc.cu", 735);
# 737 "dxtc.cu"
uint blocks = (((w + (3)) / (4)) * ((h + (3)) / (4)));
# 738 "dxtc.cu"
cudaConfigureCall(blocks, 64) ? ((void)0) : compress__entry(d_permutations, d_data, (uint2 *)d_result);
# 740 "dxtc.cu"
__cutilCheckMsg("compress", "dxtc.cu", 740);
# 742 "dxtc.cu"
__cudaSafeCall(cudaMemcpy(result, d_result, compressedSize, cudaMemcpyDeviceToHost), "dxtc.cu", 742);
# 744 "dxtc.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dxtc.cu", 744);
# 745 "dxtc.cu"
__cutilCheckError(cutStopTimer(timer), "dxtc.cu", 745);
# 747 "dxtc.cu"
float time = cutGetTimerValue(timer);
# 748 "dxtc.cu"
printf("Time %f msec\n", time);
# 750 "dxtc.cu"
char output_filename[1024];
# 751 "dxtc.cu"
strcpy(output_filename, image_path);
# 752 "dxtc.cu"
strcpy(((output_filename) + strlen(image_path)) - 3, "dds");
# 755 "dxtc.cu"
FILE *fp = fopen(output_filename, "wb");
# 756 "dxtc.cu"
if (fp == (0)) {
# 757 "dxtc.cu"
printf("Error, unable to open output image\n");
# 758 "dxtc.cu"
cudaThreadExit();
# 759 "dxtc.cu"
exit(1);
# 760 "dxtc.cu"
}
# 762 "dxtc.cu"
DDSHeader header;
# 763 "dxtc.cu"
(header.fourcc) = FOURCC_DDS;
# 764 "dxtc.cu"
(header.size) = (124);
# 765 "dxtc.cu"
(header.flags) = ((((DDSD_WIDTH | DDSD_HEIGHT) | DDSD_CAPS) | DDSD_PIXELFORMAT) | DDSD_LINEARSIZE);
# 766 "dxtc.cu"
(header.height) = h;
# 767 "dxtc.cu"
(header.width) = w;
# 768 "dxtc.cu"
(header.pitch) = compressedSize;
# 769 "dxtc.cu"
(header.depth) = (0);
# 770 "dxtc.cu"
(header.mipmapcount) = (0);
# 771 "dxtc.cu"
memset(header.reserved, 0, sizeof(header.reserved));
# 772 "dxtc.cu"
((header.pf).size) = (32);
# 773 "dxtc.cu"
((header.pf).flags) = DDPF_FOURCC;
# 774 "dxtc.cu"
((header.pf).fourcc) = FOURCC_DXT1;
# 775 "dxtc.cu"
((header.pf).bitcount) = (0);
# 776 "dxtc.cu"
((header.pf).rmask) = (0);
# 777 "dxtc.cu"
((header.pf).gmask) = (0);
# 778 "dxtc.cu"
((header.pf).bmask) = (0);
# 779 "dxtc.cu"
((header.pf).amask) = (0);
# 780 "dxtc.cu"
((header.caps).caps1) = DDSCAPS_TEXTURE;
# 781 "dxtc.cu"
((header.caps).caps2) = (0);
# 782 "dxtc.cu"
((header.caps).caps3) = (0);
# 783 "dxtc.cu"
((header.caps).caps4) = (0);
# 784 "dxtc.cu"
(header.notused) = (0);
# 786 "dxtc.cu"
fwrite(&header, sizeof(DDSHeader), 1, fp);
# 787 "dxtc.cu"
fwrite(result, compressedSize, 1, fp);
# 789 "dxtc.cu"
fclose(fp);
# 792 "dxtc.cu"
const char *reference_image_path = (cutFindFilePath("lena_ref.dds", argv[0]));
# 793 "dxtc.cu"
if (reference_image_path == (0)) {
# 794 "dxtc.cu"
printf("Error, unable to find reference image\n");
# 795 "dxtc.cu"
cudaThreadExit();
# 796 "dxtc.cu"
exit(1);
# 797 "dxtc.cu"
}
# 799 "dxtc.cu"
fp = fopen(reference_image_path, "rb");
# 800 "dxtc.cu"
if (fp == (0)) {
# 801 "dxtc.cu"
printf("Error, unable to open reference image\n");
# 802 "dxtc.cu"
cudaThreadExit();
# 803 "dxtc.cu"
exit(1);
# 804 "dxtc.cu"
}
# 806 "dxtc.cu"
fseek(fp, sizeof(DDSHeader), 0);
# 808 "dxtc.cu"
uint referenceSize = (((W / (4)) * (H / (4))) * (8));
# 809 "dxtc.cu"
uint *reference = ((uint *)malloc(referenceSize));
# 810 "dxtc.cu"
fread(reference, referenceSize, 1, fp);
# 812 "dxtc.cu"
fclose(fp);
# 814 "dxtc.cu"
float rms = (0);
# 816 "dxtc.cu"
for (uint y = (0); y < h; y += (4))
# 817 "dxtc.cu"
{
# 818 "dxtc.cu"
for (uint x = (0); x < w; x += (4))
# 819 "dxtc.cu"
{
# 820 "dxtc.cu"
uint referenceBlockIdx = (((y / (4)) * (W / (4))) + (x / (4)));
# 821 "dxtc.cu"
uint resultBlockIdx = (((y / (4)) * (w / (4))) + (x / (4)));
# 823 "dxtc.cu"
int cmp = compareBlock(((BlockDXT1 *)result) + resultBlockIdx, ((BlockDXT1 *)reference) + referenceBlockIdx);
# 824 "dxtc.cu"
if (cmp != (0.0F)) {
# 825 "dxtc.cu"
printf("Error at (%d, %d):\t%f rms\n", x / (4), y / (4), (((float)cmp) / (16)) / (3));
# 826 "dxtc.cu"
}
# 827 "dxtc.cu"
rms += cmp;
# 828 "dxtc.cu"
}
# 829 "dxtc.cu"
}
# 830 "dxtc.cu"
rms /= ((w * h) * (3));
# 832 "dxtc.cu"
printf("RMS(reference, result) = %f\n", rms);
# 834 "dxtc.cu"
if (rms <= (0.1000000015F))
# 835 "dxtc.cu"
{
# 836 "dxtc.cu"
printf("Test PASSED\n");
# 837 "dxtc.cu"
} else
# 839 "dxtc.cu"
{
# 840 "dxtc.cu"
printf("Test FAILED\n");
# 841 "dxtc.cu"
}
# 844 "dxtc.cu"
cutFree(image_path);
# 845 "dxtc.cu"
cutFree(data);
# 846 "dxtc.cu"
free(image);
# 847 "dxtc.cu"
__cudaSafeCall(cudaFree(d_permutations), "dxtc.cu", 847);
# 848 "dxtc.cu"
__cudaSafeCall(cudaFree(d_data), "dxtc.cu", 848);
# 849 "dxtc.cu"
__cudaSafeCall(cudaFree(d_result), "dxtc.cu", 849);
# 850 "dxtc.cu"
free(result);
# 852 "dxtc.cu"
__cutilCheckError(cutDeleteTimer(timer), "dxtc.cu", 852);
# 854 "dxtc.cu"
cudaThreadExit();
# 856 "dxtc.cu"
__cutilExit(argc, argv); return 0;
# 857 "dxtc.cu"
}
# 1 "/tmp/tmpxft_00003c13_00000000-1_dxtc.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00003c13_00000000-1_dxtc.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_00003c13_00000000-3_dxtc.fatbin.c" 1
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
        __cudaFatPreferBestCode
    } __cudaFatCompilationPolicy;
# 226 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 237 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );


}
# 2 "/tmp/tmpxft_00003c13_00000000-3_dxtc.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$compute_13$[] = {
0x6f69737265762e09ull,0x2e090a342e31206eull,0x7320746567726174ull,0x2f2f090a33315f6dull,
0x656c69706d6f6320ull,0x2f20687469772064ull,0x61636f6c2f727375ull,0x6f2f616475632f6cull,
0x696c2f34366e6570ull,0x2f090a65622f2f62ull,0x6e65706f766e202full,0x6220302e33206363ull,
0x206e6f20746c6975ull,0x2d30312d39303032ull,0x2d2f2f090a0a3632ull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x43202f2f090a2d2dull,0x676e696c69706d6full,
0x6d742f706d742f20ull,0x3030305f74667870ull,0x30305f3331633330ull,0x372d303030303030ull,
0x70632e637478645full,0x742f2820692e3370ull,0x23494263632f706dull,0x29564a6f5144682eull,
0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,
0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,
0x6974704f202f2f09ull,0x2f2f090a3a736e6full,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x202f2f090a2d2d2dull,0x3a74656772615420ull,0x415349202c787470ull,
0x202c33315f6d733aull,0x6c3a6e6169646e45ull,0x50202c656c747469ull,0x53207265746e696full,
0x090a34363a657a69ull,0x09334f2d20202f2full,0x7a696d6974704f28ull,0x656c206e6f697461ull,
0x2f2f090a296c6576ull,0x44280930672d2020ull,0x76656c2067756265ull,0x202f2f090a296c65ull,
0x65522809326d2d20ull,0x7664612074726f70ull,0x29736569726f7369ull,0x2d2d2d2d2f2f090aull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x09656c69662e090aull,
0x6d6d6f633c220931ull,0x656e696c2d646e61ull,0x6c69662e090a223eull,0x6d742f2209320965ull,
0x746678706d742f70ull,0x316333303030305full,0x3030303030305f33ull,0x7478645f362d3030ull,
0x6566616475632e63ull,0x090a227570672e32ull,0x093309656c69662eull,0x696c2f7273752f22ull,
0x34692f6363672f62ull,0x78756e696c2d3638ull,0x342e342f756e672dull,0x756c636e692f312eull,
0x65646474732f6564ull,0x662e090a22682e66ull,0x2f22093409656c69ull,0x61636f6c2f727375ull,
0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x72632f6564756c63ull,0x6563697665642f74ull,
0x656d69746e75725full,0x69662e090a22682eull,0x752f22093509656cull,0x6c61636f6c2f7273ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x736f682f6564756cull,0x656e696665645f74ull,
0x662e090a22682e73ull,0x2f22093609656c69ull,0x61636f6c2f727375ull,0x622f616475632f6cull,
0x6e692f2e2e2f6e69ull,0x75622f6564756c63ull,0x79745f6e69746c69ull,0x090a22682e736570ull,
0x093709656c69662eull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x745f656369766564ull,0x0a22682e73657079ull,0x3809656c69662e09ull,
0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,
0x5f7265766972642full,0x22682e7365707974ull,0x09656c69662e090aull,0x2f7273752f220939ull,
0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x6361667275732f65ull,
0x2e73657079745f65ull,0x6c69662e090a2268ull,0x752f220930310965ull,0x6c61636f6c2f7273ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x7865742f6564756cull,0x7079745f65727574ull,
0x2e090a22682e7365ull,0x09313109656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x745f726f74636576ull,0x0a22682e73657079ull,
0x3109656c69662e09ull,0x2f7273752f220932ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,
0x64756c636e692f2eull,0x6563697665642f65ull,0x5f68636e75616c5full,0x6574656d61726170ull,
0x2e090a22682e7372ull,0x09333109656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x726f74732f747263ull,0x73616c635f656761ull,
0x662e090a22682e73ull,0x2209343109656c69ull,0x636e692f7273752full,0x7469622f6564756cull,
0x2e73657079742f73ull,0x6c69662e090a2268ull,0x752f220935310965ull,0x756c636e692f7273ull,
0x2e656d69742f6564ull,0x6c69662e090a2268ull,0x7543220936310965ull,0x682e6874614d6164ull,
0x656c69662e090a22ull,0x7478642209373109ull,0x2e090a2275632e63ull,0x09383109656c6966ull,
0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x665f6e6f6d6d6f63ull,0x736e6f6974636e75ull,0x69662e090a22682eull,0x2f2209393109656cull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x72632f6564756c63ull,
0x6d5f636e75662f74ull,0x0a22682e6f726361ull,0x3209656c69662e09ull,0x2f7273752f220930ull,
0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x665f6874616d2f65ull,
0x736e6f6974636e75ull,0x69662e090a22682eull,0x2f2209313209656cull,0x61636f6c2f727375ull,
0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65642f6564756c63ull,0x6e75665f65636976ull,
0x682e736e6f697463ull,0x656c69662e090a22ull,0x73752f2209323209ull,0x2f6c61636f6c2f72ull,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x6874616d2f656475ull,0x6e6174736e6f635full,
0x2e090a22682e7374ull,0x09333209656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x74615f31315f6d73ull,0x6e75665f63696d6full,
0x682e736e6f697463ull,0x656c69662e090a22ull,0x73752f2209343209ull,0x2f6c61636f6c2f72ull,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x315f6d732f656475ull,0x63696d6f74615f32ull,
0x6f6974636e75665full,0x2e090a22682e736eull,0x09353209656c6966ull,0x6f6c2f7273752f22ull,
0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x6f645f33315f6d73ull,
0x6e75665f656c6275ull,0x682e736e6f697463ull,0x656c69662e090a22ull,0x73752f2209363209ull,
0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x325f6d732f656475ull,
0x63696d6f74615f30ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09373209656c6966ull,
0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x6e695f30325f6d73ull,0x736369736e697274ull,0x69662e090a22682eull,0x2f2209383209656cull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x75732f6564756c63ull,
0x75665f6563616672ull,0x2e736e6f6974636eull,0x6c69662e090a2268ull,0x752f220939320965ull,
0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,0x7865742f6564756cull,
0x7465665f65727574ull,0x74636e75665f6863ull,0x0a22682e736e6f69ull,0x3309656c69662e09ull,
0x2f7273752f220930ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x665f6874616d2f65ull,0x736e6f6974636e75ull,0x7874705f6c62645full,0x2e090a0a22682e33ull,
0x2e20646572616873ull,0x2034206e67696c61ull,0x61766f632038622eull,0x5f5f65636e616972ull,
0x0a3b5d3438335b30ull,0x6465726168732e09ull,0x206e67696c612e20ull,0x6e692038622e2034ull,
0x315f5f7365636964ull,0x090a3b5d3635325bull,0x206465726168732eull,0x34206e67696c612eull,
0x705f732038622e20ull,0x69746174756d7265ull,0x365b325f5f736e6full,0x732e090a3b5d3034ull,
0x612e206465726168ull,0x2e2034206e67696cull,0x5f5f737064203862ull,0x090a3b5d34365b33ull,
0x2e2074736e6f632eull,0x2034206e67696c61ull,0x6c6f436b2038622eull,0x63697274654d726full,
0x7b203d205d32315bull,0x2c3832312c302c30ull,0x312c302c302c3336ull,0x2c302c33362c3832ull,
0x33362c3832312c30ull,0x6e6f632e090a3b7dull,0x67696c612e207473ull,0x2038622e2034206eull,
0x6261546168706c61ull,0x205d36315b34656cull,0x312c302c307b203dull,0x302c302c35362c36ull,
0x302c302c302c302cull,0x2c34362c3239312cull,0x362c34362c302c30ull,0x6f632e090a3b7d34ull,
0x696c612e2074736eull,0x38622e2034206e67ull,0x61546168706c6120ull,0x5d36315b33656c62ull,
0x2c302c307b203d20ull,0x302c34362c383231ull,0x302c302c302c302cull,0x2c34362c302c302cull,
0x34362c302c302c30ull,0x6e6f632e090a3b7dull,0x67696c612e207473ull,0x2038622e2034206eull,
0x315b3473646f7270ull,0x2c307b203d205d36ull,0x2c302c302c392c30ull,0x2c322c302c302c39ull,
0x2c322c302c342c31ull,0x0a3b7d302c312c34ull,0x2074736e6f632e09ull,0x34206e67696c612eull,
0x6f72702038622e20ull,0x205d36315b337364ull,0x342c302c307b203dull,0x302c342c302c302cull,
0x342c312c312c302cull,0x312c342c312c302cull,0x2e090a0a3b7d302cull,0x5a5f207972746e65ull,
0x736572706d6f6338ull,0x505f30536a4b5073ull,0x282032746e697535ull,0x617261702e09090aull,
0x5f203436752e206dull,0x726170616475635full,0x6d6f63385a5f5f6dull,0x6a4b507373657270ull,
0x6e697535505f3053ull,0x756d7265705f3274ull,0x2c736e6f69746174ull,0x617261702e09090aull,
0x5f203436752e206dull,0x726170616475635full,0x6d6f63385a5f5f6dull,0x6a4b507373657270ull,
0x6e697535505f3053ull,0x6567616d695f3274ull,0x7261702e09090a2cull,0x203436752e206d61ull,
0x6170616475635f5full,0x6f63385a5f5f6d72ull,0x4b5073736572706dull,0x697535505f30536aull,
0x757365725f32746eull,0x090a7b090a29746cull,0x31752e206765722eull,0x3e363c6872252036ull,
0x206765722e090a3bull,0x3c7225203233752eull,0x2e090a3b3e373832ull,0x3436752e20676572ull,
0x3131313c64722520ull,0x6765722e090a3b3eull,0x6625203233662e20ull,0x090a3b3e3239343cull,
0x72702e206765722eull,0x37323c7025206465ull,0x6168732e090a3b3eull,0x696c612e20646572ull,
0x38622e2034206e67ull,0x5f616475635f5f20ull,0x333173726f6c6f63ull,0x3b5d3239315b3836ull,
0x65726168732e090aull,0x6e67696c612e2064ull,0x5f2038622e203420ull,0x75735f616475635full,
0x315b30363531736dull,0x732e090a3b5d3239ull,0x612e206465726168ull,0x2e2034206e67696cull,
0x6475635f5f203862ull,0x3173666572785f61ull,0x3b5d34365b323537ull,0x65726168732e090aull,
0x6e67696c612e2064ull,0x5f2038622e203420ull,0x72655f616475635full,0x3631383173726f72ull,
0x090a3b5d3635325bull,0x09373109636f6c2eull,0x4c240a3009393035ull,0x63385a5f5f314242ull,
0x5073736572706d6full,0x7535505f30536a4bull,0x2e090a3a32746e69ull,0x3509373109636f6cull,
0x7663090a30093731ull,0x31752e3233732e74ull,0x202c317225092036ull,0x0a3b782e64697425ull,
0x3233732e766f6d09ull,0x31202c3272250920ull,0x70746573090a3b35ull,0x203233732e656c2eull,
0x7225202c31702509ull,0x0a3b327225202c31ull,0x6220317025214009ull,0x5f744c2409206172ull,
0x3b34353336335f30ull,0x3109636f6c2e090aull,0x0a30093834310937ull,0x3436752e766f6d09ull,
0x202c316472250920ull,0x635f616475635f5full,0x36333173726f6c6full,0x2e747663090a3b38ull,
0x203631752e323373ull,0x6325202c33722509ull,0x0a3b782e64696174ull,0x3631752e74766309ull,
0x722509203233752eull,0x3b337225202c3168ull,0x69772e6c756d090aull,0x09203631752e6564ull,
0x687225202c347225ull,0x090a3b3631202c31ull,0x203233732e646461ull,0x7225202c35722509ull,
0x0a3b347225202c31ull,0x2e6f6c2e6c756d09ull,0x3672250920323375ull,0x34202c357225202cull,
0x752e747663090a3bull,0x09203233752e3436ull,0x7225202c32647225ull,0x702e646c090a3b36ull,
0x3436752e6d617261ull,0x202c336472250920ull,0x70616475635f5f5bull,0x63385a5f5f6d7261ull,
0x5073736572706d6full,0x7535505f30536a4bull,0x616d695f32746e69ull,0x6461090a3b5d6567ull,
0x2509203436752e64ull,0x647225202c346472ull,0x3b33647225202c32ull,0x6f6c672e646c090aull,
0x203233752e6c6162ull,0x255b202c37722509ull,0x0a3b5d302b346472ull,0x373109636f6c2e09ull,
0x090a300930353109ull,0x752e6f6c2e6c756dull,0x2c38722509203233ull,0x3231202c31722520ull,
0x752e747663090a3bull,0x09203233752e3436ull,0x7225202c35647225ull,0x2e646461090a3b38ull,
0x6472250920343675ull,0x2c35647225202c36ull,0x090a3b3164722520ull,0x203233622e646e61ull,
0x7225202c39722509ull,0x0a3b353532202c37ull,0x2e6e722e74766309ull,0x203233752e323366ull,
0x7225202c31662509ull,0x2e766f6d090a3b39ull,0x3266250920323366ull,0x303862336630202cull,
0x2020203b31383038ull,0x2e30202f2f092020ull,0x3735313239333030ull,0x33662e6c756d090aull,
0x202c336625092032ull,0x326625202c316625ull,0x68732e7473090a3bull,0x3233662e64657261ull,
0x2b366472255b0920ull,0x3b336625202c5d30ull,0x3109636f6c2e090aull,0x0a30093135310937ull,
0x3233622e6c687309ull,0x202c303172250920ull,0x3b3631202c377225ull,0x33752e726873090aull,
0x2c31317225092032ull,0x32202c3031722520ull,0x2e747663090a3b34ull,0x752e3233662e6e72ull,
0x2c34662509203233ull,0x090a3b3131722520ull,0x203233662e766f6dull,0x6630202c35662509ull,
0x3138303830386233ull,0x2f0920202020203bull,0x393330302e30202full,0x756d090a37353132ull,
0x2509203233662e6cull,0x2c346625202c3666ull,0x73090a3b35662520ull,0x6465726168732e74ull,
0x255b09203233662eull,0x202c5d342b366472ull,0x6c2e090a3b366625ull,0x353109373109636full,
0x6c6873090a300932ull,0x722509203233622eull,0x2c377225202c3231ull,0x726873090a3b3820ull,
0x722509203233752eull,0x32317225202c3331ull,0x63090a3b3432202cull,0x33662e6e722e7476ull,
0x2509203233752e32ull,0x33317225202c3766ull,0x662e766f6d090a3bull,0x2c38662509203233ull,
0x3830386233663020ull,0x202020203b313830ull,0x302e30202f2f0920ull,0x0a37353132393330ull,
0x3233662e6c756d09ull,0x25202c3966250920ull,0x3b386625202c3766ull,0x6168732e7473090aull,
0x203233662e646572ull,0x382b366472255b09ull,0x0a3b396625202c5dull,0x36335f305f744c24ull,
0x6f6d090a3a343533ull,0x2509203436752e76ull,0x635f5f202c316472ull,0x6f6c6f635f616475ull,
0x0a3b383633317372ull,0x373109636f6c2e09ull,0x090a300936353109ull,0x636e79732e726162ull,
0x2140090a3b300920ull,0x2061726220317025ull,0x335f305f744c2409ull,0x2e090a3b36363836ull,
0x3109373109636f6cull,0x6f6d090a30093036ull,0x2509203436752e76ull,0x635f5f202c376472ull,
0x736d75735f616475ull,0x6d090a3b30363531ull,0x33752e6f6c2e6c75ull,0x2c34317225092032ull,
0x3231202c31722520ull,0x752e747663090a3bull,0x09203233752e3436ull,0x7225202c38647225ull,
0x646461090a3b3431ull,0x722509203436752eull,0x38647225202c3664ull,0x0a3b31647225202cull,
0x3436752e64646109ull,0x202c396472250920ull,0x7225202c38647225ull,0x2e646c090a3b3764ull,
0x662e646572616873ull,0x3031662509203233ull,0x2b366472255b202cull,0x2e7473090a3b5d30ull,
0x662e646572616873ull,0x6472255b09203233ull,0x6625202c5d302b39ull,0x2e646c090a3b3031ull,
0x662e646572616873ull,0x3131662509203233ull,0x2b366472255b202cull,0x2e7473090a3b5d34ull,
0x662e646572616873ull,0x6472255b09203233ull,0x6625202c5d342b39ull,0x2e646c090a3b3131ull,
0x662e646572616873ull,0x3231662509203233ull,0x2b366472255b202cull,0x2e7473090a3b5d38ull,
0x662e646572616873ull,0x6472255b09203233ull,0x6625202c5d382b39ull,0x5f744c240a3b3231ull,
0x3a36363836335f30ull,0x36752e766f6d090aull,0x2c37647225092034ull,0x5f616475635f5f20ull,
0x30363531736d7573ull,0x732e726162090a3bull,0x0a3b300920636e79ull,0x6220317025214009ull,
0x5f744c2409206172ull,0x3b38373337335f30ull,0x33622e726f78090aull,0x2c35317225092032ull,
0x3b38202c31722520ull,0x6f6c2e6c756d090aull,0x722509203233752eull,0x35317225202c3631ull,
0x63090a3b3231202cull,0x752e3436752e7476ull,0x3164722509203233ull,0x3b36317225202c30ull,
0x36752e646461090aull,0x3131647225092034ull,0x2c3031647225202cull,0x090a3b3764722520ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c333166ull,0x0a3b5d302b313164ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c34316625ull,0x3b5d342b31316472ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3531662509ull,0x5d382b3131647225ull,
0x6c2e6c756d090a3bull,0x2509203233752e6full,0x317225202c373172ull,0x63090a3b3231202cull,
0x752e3436752e7476ull,0x3164722509203233ull,0x3b37317225202c32ull,0x36752e646461090aull,
0x2c39647225092034ull,0x202c323164722520ull,0x6c090a3b37647225ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3631ull,0x61090a3b5d302b39ull,0x09203233662e6464ull,
0x6625202c37316625ull,0x33316625202c3631ull,0x68732e7473090a3bull,0x3233662e64657261ull,
0x2b396472255b0920ull,0x37316625202c5d30ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x202c383166250920ull,0x5d342b396472255bull,0x662e646461090a3bull,0x3931662509203233ull,
0x202c38316625202cull,0x73090a3b34316625ull,0x6465726168732e74ull,0x255b09203233662eull,
0x202c5d342b396472ull,0x6c090a3b39316625ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3032ull,0x61090a3b5d382b39ull,0x09203233662e6464ull,0x6625202c31326625ull,
0x35316625202c3032ull,0x68732e7473090a3bull,0x3233662e64657261ull,0x2b396472255b0920ull,
0x31326625202c5d38ull,0x5f305f744c240a3bull,0x090a3a3837333733ull,0x636e79732e726162ull,
0x2140090a3b300920ull,0x2061726220317025ull,0x335f305f744c2409ull,0x78090a3b30393837ull,
0x09203233622e726full,0x7225202c38317225ull,0x6d090a3b34202c31ull,0x33752e6f6c2e6c75ull,
0x2c39317225092032ull,0x31202c3831722520ull,0x2e747663090a3b32ull,0x203233752e343675ull,
0x202c333164722509ull,0x61090a3b39317225ull,0x09203436752e6464ull,0x25202c3431647225ull,
0x7225202c33316472ull,0x2e646c090a3b3764ull,0x662e646572616873ull,0x3232662509203233ull,
0x34316472255b202cull,0x646c090a3b5d302bull,0x2e6465726168732eull,0x3266250920323366ull,
0x316472255b202c33ull,0x6c090a3b5d342b34ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3432ull,0x090a3b5d382b3431ull,0x752e6f6c2e6c756dull,0x3032722509203233ull,
0x31202c317225202cull,0x2e747663090a3b32ull,0x203233752e343675ull,0x202c353164722509ull,
0x61090a3b30327225ull,0x09203436752e6464ull,0x7225202c39647225ull,0x647225202c353164ull,
0x732e646c090a3b37ull,0x33662e6465726168ull,0x2c35326625092032ull,0x302b396472255b20ull,
0x2e646461090a3b5dull,0x3266250920323366ull,0x2c35326625202c36ull,0x090a3b3232662520ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x2c5d302b39647225ull,0x090a3b3632662520ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c373266ull,0x090a3b5d342b3964ull,
0x203233662e646461ull,0x25202c3832662509ull,0x326625202c373266ull,0x732e7473090a3b33ull,
0x33662e6465726168ull,0x396472255b092032ull,0x326625202c5d342bull,0x732e646c090a3b38ull,
0x33662e6465726168ull,0x2c39326625092032ull,0x382b396472255b20ull,0x2e646461090a3b5dull,
0x3366250920323366ull,0x2c39326625202c30ull,0x090a3b3432662520ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x2c5d382b39647225ull,0x240a3b3033662520ull,0x3837335f305f744cull,
0x726162090a3a3039ull,0x300920636e79732eull,0x3170252140090a3bull,0x4c24092061726220ull,
0x303438335f305f74ull,0x2e726f78090a3b32ull,0x3272250920323362ull,0x202c317225202c31ull,
0x2e6c756d090a3b32ull,0x09203233752e6f6cull,0x7225202c32327225ull,0x0a3b3231202c3132ull,
0x3436752e74766309ull,0x722509203233752eull,0x327225202c363164ull,0x2e646461090a3b32ull,
0x6472250920343675ull,0x31647225202c3731ull,0x3b37647225202c36ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3133662509ull,0x5d302b3731647225ull,0x68732e646c090a3bull,
0x3233662e64657261ull,0x202c323366250920ull,0x342b37316472255bull,0x732e646c090a3b5dull,
0x33662e6465726168ull,0x2c33336625092032ull,0x2b37316472255b20ull,0x6c756d090a3b5d38ull,
0x203233752e6f6c2eull,0x25202c3332722509ull,0x0a3b3231202c3172ull,0x3436752e74766309ull,
0x722509203233752eull,0x327225202c383164ull,0x2e646461090a3b33ull,0x6472250920343675ull,
0x3831647225202c39ull,0x0a3b37647225202cull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c34336625ull,0x0a3b5d302b396472ull,0x3233662e64646109ull,0x202c353366250920ull,
0x6625202c34336625ull,0x2e7473090a3b3133ull,0x662e646572616873ull,0x6472255b09203233ull,
0x6625202c5d302b39ull,0x2e646c090a3b3533ull,0x662e646572616873ull,0x3633662509203233ull,
0x2b396472255b202cull,0x646461090a3b5d34ull,0x662509203233662eull,0x36336625202c3733ull,
0x0a3b32336625202cull,0x726168732e747309ull,0x09203233662e6465ull,0x5d342b396472255bull,
0x0a3b37336625202cull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c38336625ull,
0x0a3b5d382b396472ull,0x3233662e64646109ull,0x202c393366250920ull,0x6625202c38336625ull,
0x2e7473090a3b3333ull,0x662e646572616873ull,0x6472255b09203233ull,0x6625202c5d382b39ull,
0x5f744c240a3b3933ull,0x3a32303438335f30ull,0x79732e726162090aull,0x090a3b300920636eull,
0x7262203170252140ull,0x305f744c24092061ull,0x0a3b34313938335full,0x3233622e726f7809ull,
0x202c343272250920ull,0x0a3b31202c317225ull,0x2e6f6c2e6c756d09ull,0x3272250920323375ull,
0x2c34327225202c35ull,0x7663090a3b323120ull,0x33752e3436752e74ull,0x3931647225092032ull,
0x0a3b35327225202cull,0x3436752e64646109ull,0x2c30326472250920ull,0x202c393164722520ull,
0x6c090a3b37647225ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3034ull,
0x090a3b5d302b3032ull,0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c313466ull,
0x0a3b5d342b303264ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c32346625ull,
0x3b5d382b30326472ull,0x6f6c2e6c756d090aull,0x722509203233752eull,0x2c317225202c3632ull,
0x7663090a3b323120ull,0x33752e3436752e74ull,0x3132647225092032ull,0x0a3b36327225202cull,
0x3436752e64646109ull,0x202c396472250920ull,0x25202c3132647225ull,0x646c090a3b376472ull,
0x2e6465726168732eull,0x3466250920323366ull,0x396472255b202c33ull,0x6461090a3b5d302bull,
0x2509203233662e64ull,0x346625202c343466ull,0x3b30346625202c33ull,0x6168732e7473090aull,
0x203233662e646572ull,0x302b396472255b09ull,0x3b34346625202c5dull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3534662509ull,0x3b5d342b39647225ull,0x33662e646461090aull,
0x2c36346625092032ull,0x25202c3534662520ull,0x7473090a3b313466ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x25202c5d342b3964ull,0x646c090a3b363466ull,0x2e6465726168732eull,
0x3466250920323366ull,0x396472255b202c37ull,0x6461090a3b5d382bull,0x2509203233662e64ull,
0x346625202c383466ull,0x3b32346625202c37ull,0x6168732e7473090aull,0x203233662e646572ull,
0x382b396472255b09ull,0x3b38346625202c5dull,0x335f305f744c240aull,0x62090a3a34313938ull,
0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x3136310937310963ull,0x70252140090a3009ull,
0x2409206172622031ull,0x3939335f305f744cull,0x6f6c2e090a3b3833ull,0x3231310936310963ull,
0x2e6c756d090a3009ull,0x09203233752e6f6cull,0x7225202c37327225ull,0x090a3b3231202c31ull,
0x2e3436752e747663ull,0x6472250920323375ull,0x37327225202c3232ull,0x752e646461090a3bull,
0x3664722509203436ull,0x2c3232647225202cull,0x090a3b3164722520ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c393466ull,0x090a3b5d302b3664ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c303566ull,0x090a3b5d342b3664ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c313566ull,0x090a3b5d382b3664ull,0x203233662e766f6dull,
0x30202c3235662509ull,0x3030303038643366ull,0x2f09202020203b30ull,0x353236302e30202full,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3335662509ull,0x735f616475635f5full,
0x2b30363531736d75ull,0x6c756d090a3b5d30ull,0x662509203233662eull,0x32356625202c3435ull,
0x0a3b33356625202cull,0x3233662e62757309ull,0x202c353566250920ull,0x6625202c39346625ull,
0x766f6d090a3b3435ull,0x662509203233662eull,0x35356625202c3635ull,0x662e766f6d090a3bull,
0x3735662509203233ull,0x303864336630202cull,0x2020203b30303030ull,0x302e30202f2f0920ull,
0x2e646c090a353236ull,0x662e646572616873ull,0x3835662509203233ull,0x6475635f5f5b202cull,
0x3531736d75735f61ull,0x090a3b5d342b3036ull,0x203233662e6c756dull,0x25202c3935662509ull,
0x356625202c373566ull,0x2e627573090a3b38ull,0x3666250920323366ull,0x2c30356625202c30ull,
0x090a3b3935662520ull,0x203233662e766f6dull,0x25202c3136662509ull,0x6f6d090a3b303666ull,
0x2509203233662e76ull,0x336630202c323666ull,0x3b30303030303864ull,0x202f2f0920202020ull,
0x090a353236302e30ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5f5b202c333666ull,
0x6d75735f61647563ull,0x5d382b3036353173ull,0x662e6c756d090a3bull,0x3436662509203233ull,
0x202c32366625202cull,0x73090a3b33366625ull,0x09203233662e6275ull,0x6625202c35366625ull,
0x34366625202c3135ull,0x662e766f6d090a3bull,0x3636662509203233ull,0x0a3b35366625202cull,
0x39335f305f744c24ull,0x2140090a3a363234ull,0x2061726220317025ull,0x335f305f744c2409ull,
0x2e090a3b38333939ull,0x3109363109636f6cull,0x6f6d090a30093931ull,0x2509203436752e76ull,
0x6f63202c33326472ull,0x65636e6169726176ull,0x756d090a3b305f5full,0x3233732e6f6c2e6cull,
0x202c383272250920ull,0x0a3b36202c317225ull,0x3436732e74766309ull,0x722509203233732eull,
0x327225202c343264ull,0x2e6c756d090a3b38ull,0x09203436752e6f6cull,0x25202c3532647225ull,
0x3b34202c34326472ull,0x36752e646461090aull,0x3632647225092034ull,0x2c3332647225202cull,
0x0a3b353264722520ull,0x3233662e766f6d09ull,0x202c373666250920ull,0x6d090a3b36356625ull,
0x09203233662e6c75ull,0x6625202c38366625ull,0x37366625202c3736ull,0x68732e7473090a3bull,
0x3233662e64657261ull,0x36326472255b0920ull,0x366625202c5d302bull,0x636f6c2e090a3b38ull,
0x0930323109363109ull,0x662e766f6d090a30ull,0x3936662509203233ull,0x0a3b31366625202cull,
0x3233662e6c756d09ull,0x202c303766250920ull,0x6625202c39366625ull,0x2e7473090a3b3736ull,
0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d342b3632ull,0x6c2e090a3b303766ull,
0x323109363109636full,0x766f6d090a300931ull,0x662509203233662eull,0x36366625202c3137ull,
0x662e6c756d090a3bull,0x3237662509203233ull,0x202c31376625202cull,0x73090a3b37366625ull,
0x6465726168732e74ull,0x255b09203233662eull,0x2c5d382b36326472ull,0x090a3b3237662520ull,
0x09363109636f6c2eull,0x6d090a3009323231ull,0x09203233662e6c75ull,0x6625202c33376625ull,
0x39366625202c3936ull,0x68732e7473090a3bull,0x3233662e64657261ull,0x36326472255b0920ull,
0x6625202c5d32312bull,0x6f6c2e090a3b3337ull,0x3332310936310963ull,0x2e6c756d090a3009ull,
0x3766250920323366ull,0x2c31376625202c34ull,0x090a3b3936662520ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x36312b3632647225ull,0x3b34376625202c5dull,0x3109636f6c2e090aull,
0x0a30093432310936ull,0x3233662e6c756d09ull,0x202c353766250920ull,0x6625202c31376625ull,
0x2e7473090a3b3137ull,0x662e646572616873ull,0x6472255b09203233ull,0x202c5d30322b3632ull,
0x4c240a3b35376625ull,0x333939335f305f74ull,0x2e766f6d090a3a38ull,0x6472250920343675ull,
0x61766f63202c3332ull,0x5f5f65636e616972ull,0x636f6c2e090a3b30ull,0x0936323109363109ull,
0x732e726162090a30ull,0x0a3b300920636e79ull,0x3233732e766f6d09ull,0x202c393272250920ull,
0x305f744c240a3b38ull,0x0a3a32363930345full,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,
0x656e696c2079646full,0x656e202c36323120ull,0x656420676e697473ull,0x202c31203a687470ull,
0x6574616d69747365ull,0x7461726574692064ull,0x6e75203a736e6f69ull,0x73090a6e776f6e6bull,
0x732e74672e707465ull,0x2c32702509203233ull,0x25202c3932722520ull,0x252140090a3b3172ull,
0x0920617262203270ull,0x31345f305f744c24ull,0x2f2f200a3b383132ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x323120656e696c20ull,0x2064616568202c36ull,
0x2064656c6562616cull,0x30345f305f744c24ull,0x6f6c2e090a323639ull,0x3033310936310963ull,
0x2e6c756d090a3009ull,0x09203233732e6f6cull,0x7225202c30337225ull,0x63090a3b36202c31ull,
0x732e3436732e7476ull,0x3264722509203233ull,0x3b30337225202c37ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c383264ull,0x090a3b34202c3732ull,0x203436752e646461ull,
0x202c363264722509ull,0x25202c3332647225ull,0x6c090a3b38326472ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3637ull,0x090a3b5d302b3632ull,0x203233732e646461ull,
0x25202c3133722509ull,0x317225202c393272ull,0x6c2e6c756d090a3bull,0x2509203233732e6full,
0x337225202c323372ull,0x63090a3b36202c31ull,0x732e3436732e7476ull,0x3264722509203233ull,
0x3b32337225202c39ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c303364ull,
0x090a3b34202c3932ull,0x203436752e646461ull,0x202c313364722509ull,0x25202c3332647225ull,
0x6c090a3b30336472ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3737ull,
0x090a3b5d302b3133ull,0x203233662e646461ull,0x25202c3837662509ull,0x376625202c363766ull,
0x732e7473090a3b37ull,0x33662e6465726168ull,0x326472255b092032ull,0x6625202c5d302b36ull,
0x5f744c240a3b3837ull,0x3a38313231345f30ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3632312065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a32363930345f30ull,0x6e79732e72616209ull,0x40090a3b30092063ull,
0x6172622032702521ull,0x5f305f744c240920ull,0x200a3b3033373134ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363231ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x2e090a3236393034ull,0x3109363109636f6cull,
0x756d090a30093133ull,0x3233732e6f6c2e6cull,0x202c333372250920ull,0x0a3b36202c317225ull,
0x3436732e74766309ull,0x722509203233732eull,0x337225202c323364ull,0x2e6c756d090a3b33ull,
0x09203436752e6f6cull,0x25202c3333647225ull,0x3b34202c32336472ull,0x36752e646461090aull,
0x3632647225092034ull,0x2c3332647225202cull,0x0a3b333364722520ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c39376625ull,0x3b5d342b36326472ull,0x33732e646461090aull,
0x2c34337225092032ull,0x25202c3932722520ull,0x6c756d090a3b3172ull,0x203233732e6f6c2eull,
0x25202c3533722509ull,0x0a3b36202c343372ull,0x3436732e74766309ull,0x722509203233732eull,
0x337225202c343364ull,0x2e6c756d090a3b35ull,0x09203436752e6f6cull,0x25202c3533647225ull,
0x3b34202c34336472ull,0x36752e646461090aull,0x3633647225092034ull,0x2c3332647225202cull,
0x0a3b353364722520ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c30386625ull,
0x3b5d342b36336472ull,0x33662e646461090aull,0x2c31386625092032ull,0x25202c3937662520ull,
0x7473090a3b303866ull,0x2e6465726168732eull,0x72255b0920323366ull,0x202c5d342b363264ull,
0x4c240a3b31386625ull,0x333731345f305f74ull,0x6c3c2f2f200a3a30ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c36323120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x363930345f305f74ull,0x732e726162090a32ull,0x0a3b300920636e79ull,
0x6220327025214009ull,0x5f744c2409206172ull,0x3b32343232345f30ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3632312065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a32363930345f30ull,0x363109636f6c2e09ull,
0x090a300932333109ull,0x732e6f6c2e6c756dull,0x3633722509203233ull,0x36202c317225202cull,
0x732e747663090a3bull,0x09203233732e3436ull,0x25202c3733647225ull,0x756d090a3b363372ull,
0x3436752e6f6c2e6cull,0x2c38336472250920ull,0x202c373364722520ull,0x2e646461090a3b34ull,
0x6472250920343675ull,0x32647225202c3632ull,0x3833647225202c33ull,0x68732e646c090a3bull,
0x3233662e64657261ull,0x202c323866250920ull,0x382b36326472255bull,0x2e646461090a3b5dull,
0x3372250920323373ull,0x2c39327225202c37ull,0x6d090a3b31722520ull,0x33732e6f6c2e6c75ull,
0x2c38337225092032ull,0x36202c3733722520ull,0x732e747663090a3bull,0x09203233732e3436ull,
0x25202c3933647225ull,0x756d090a3b383372ull,0x3436752e6f6c2e6cull,0x2c30346472250920ull,
0x202c393364722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x32647225202c3134ull,
0x3034647225202c33ull,0x68732e646c090a3bull,0x3233662e64657261ull,0x202c333866250920ull,
0x382b31346472255bull,0x2e646461090a3b5dull,0x3866250920323366ull,0x2c32386625202c34ull,
0x090a3b3338662520ull,0x65726168732e7473ull,0x5b09203233662e64ull,0x5d382b3632647225ull,
0x0a3b34386625202cull,0x32345f305f744c24ull,0x2f2f200a3a323432ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x323120656e696c20ull,0x2064616568202c36ull,
0x2064656c6562616cull,0x30345f305f744c24ull,0x726162090a323639ull,0x300920636e79732eull,
0x3270252140090a3bull,0x4c24092061726220ull,0x353732345f305f74ull,0x6c3c2f2f200a3b34ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c36323120656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x363930345f305f74ull,0x09636f6c2e090a32ull,
0x3009333331093631ull,0x6f6c2e6c756d090aull,0x722509203233732eull,0x2c317225202c3933ull,
0x747663090a3b3620ull,0x3233732e3436732eull,0x2c32346472250920ull,0x090a3b3933722520ull,
0x752e6f6c2e6c756dull,0x3464722509203436ull,0x3234647225202c33ull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x7225202c36326472ull,0x647225202c333264ull,0x2e646c090a3b3334ull,
0x662e646572616873ull,0x3538662509203233ull,0x36326472255b202cull,0x61090a3b5d32312bull,
0x09203233732e6464ull,0x7225202c30347225ull,0x3b317225202c3932ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x30347225202c3134ull,0x7663090a3b36202cull,0x33732e3436732e74ull,
0x3434647225092032ull,0x0a3b31347225202cull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x34647225202c3534ull,0x61090a3b34202c34ull,0x09203436752e6464ull,0x25202c3634647225ull,
0x7225202c33326472ull,0x646c090a3b353464ull,0x2e6465726168732eull,0x3866250920323366ull,
0x346472255b202c36ull,0x090a3b5d32312b36ull,0x203233662e646461ull,0x25202c3738662509ull,
0x386625202c353866ull,0x732e7473090a3b36ull,0x33662e6465726168ull,0x326472255b092032ull,
0x25202c5d32312b36ull,0x744c240a3b373866ull,0x34353732345f305full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36323120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x32363930345f305full,0x79732e726162090aull,
0x090a3b300920636eull,0x7262203270252140ull,0x305f744c24092061ull,0x0a3b36363233345full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c36323120ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x090a32363930345full,
0x09363109636f6c2eull,0x6d090a3009343331ull,0x33732e6f6c2e6c75ull,0x2c32347225092032ull,
0x3b36202c31722520ull,0x36732e747663090aull,0x2509203233732e34ull,0x7225202c37346472ull,
0x6c756d090a3b3234ull,0x203436752e6f6c2eull,0x202c383464722509ull,0x34202c3734647225ull,
0x752e646461090a3bull,0x3264722509203436ull,0x3332647225202c36ull,0x3b3834647225202cull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3838662509ull,0x36312b3632647225ull,
0x2e646461090a3b5dull,0x3472250920323373ull,0x2c39327225202c33ull,0x6d090a3b31722520ull,
0x33732e6f6c2e6c75ull,0x2c34347225092032ull,0x36202c3334722520ull,0x732e747663090a3bull,
0x09203233732e3436ull,0x25202c3934647225ull,0x756d090a3b343472ull,0x3436752e6f6c2e6cull,
0x2c30356472250920ull,0x202c393464722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x32647225202c3135ull,0x3035647225202c33ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x202c393866250920ull,0x312b31356472255bull,0x646461090a3b5d36ull,0x662509203233662eull,
0x38386625202c3039ull,0x0a3b39386625202cull,0x726168732e747309ull,0x09203233662e6465ull,
0x312b36326472255bull,0x30396625202c5d36ull,0x5f305f744c240a3bull,0x200a3a3636323334ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c363231ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x62090a3236393034ull,
0x20636e79732e7261ull,0x252140090a3b3009ull,0x0920617262203270ull,0x33345f305f744c24ull,
0x2f2f200a3b383737ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x323120656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,0x30345f305f744c24ull,
0x6f6c2e090a323639ull,0x3533310936310963ull,0x2e6c756d090a3009ull,0x09203233732e6f6cull,
0x7225202c35347225ull,0x63090a3b36202c31ull,0x732e3436732e7476ull,0x3564722509203233ull,
0x3b35347225202c32ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c333564ull,
0x090a3b34202c3235ull,0x203436752e646461ull,0x202c363264722509ull,0x25202c3332647225ull,
0x6c090a3b33356472ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3139ull,
0x0a3b5d30322b3632ull,0x3233732e64646109ull,0x202c363472250920ull,0x7225202c39327225ull,
0x2e6c756d090a3b31ull,0x09203233732e6f6cull,0x7225202c37347225ull,0x090a3b36202c3634ull,
0x2e3436732e747663ull,0x6472250920323373ull,0x37347225202c3435ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x7225202c35356472ull,0x0a3b34202c343564ull,0x3436752e64646109ull,
0x2c36356472250920ull,0x202c333264722520ull,0x090a3b3535647225ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c323966ull,0x3b5d30322b363564ull,0x33662e646461090aull,
0x2c33396625092032ull,0x25202c3139662520ull,0x7473090a3b323966ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x2c5d30322b363264ull,0x240a3b3339662520ull,0x3733345f305f744cull,
0x3c2f2f200a3a3837ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x36323120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3930345f305f744cull,
0x2e726162090a3236ull,0x3b300920636e7973ull,0x3109636f6c2e090aull,0x0a30093832310936ull,
0x3233732e72687309ull,0x202c393272250920ull,0x3b31202c39327225ull,0x33752e766f6d090aull,
0x2c38347225092032ull,0x746573090a3b3020ull,0x3233732e74672e70ull,0x25202c3370250920ull,
0x347225202c393272ull,0x33702540090a3b38ull,0x4c24092061726220ull,0x363930345f305f74ull,
0x636f6c2e090a3b32ull,0x3009343509363109ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3439662509ull,0x6e61697261766f63ull,0x5d342b305f5f6563ull,0x68732e646c090a3bull,
0x3233662e64657261ull,0x202c353966250920ull,0x61697261766f635bull,0x312b305f5f65636eull,
0x766f6d090a3b5d32ull,0x662509203233662eull,0x66336630202c3639ull,0x203b303030303038ull,
0x31202f2f09202020ull,0x33662e64616d090aull,0x2c37396625092032ull,0x25202c3639662520ull,
0x396625202c343966ull,0x732e646c090a3b35ull,0x33662e6465726168ull,0x2c38396625092032ull,
0x697261766f635b20ull,0x2b305f5f65636e61ull,0x2e646c090a3b5d38ull,0x662e646572616873ull,
0x3939662509203233ull,0x7261766f635b202cull,0x305f5f65636e6169ull,0x6d090a3b5d36312bull,
0x09203233662e766full,0x30202c3030316625ull,0x3030303038663366ull,0x2f2f092020203b30ull,
0x2e64616d090a3120ull,0x3166250920323366ull,0x30316625202c3130ull,0x2c38396625202c30ull,
0x090a3b3939662520ull,0x65726168732e646cull,0x2509203233662e64ull,0x635b202c32303166ull,
0x636e61697261766full,0x3b5d302b305f5f65ull,0x33662e766f6d090aull,0x3330316625092032ull,
0x303866336630202cull,0x2020203b30303030ull,0x6d090a31202f2f09ull,0x09203233662e6461ull,
0x25202c3430316625ull,0x6625202c32303166ull,0x396625202c333031ull,0x2e766f6d090a3b34ull,
0x3166250920323366ull,0x66336630202c3530ull,0x203b303030303038ull,0x0a31202f2f092020ull,
0x3233662e64616d09ull,0x2c36303166250920ull,0x202c353031662520ull,0x6625202c39396625ull,
0x2e646c090a3b3739ull,0x662e646572616873ull,0x3031662509203233ull,0x61766f635b202c37ull,
0x5f5f65636e616972ull,0x090a3b5d30322b30ull,0x203233662e766f6dull,0x202c383031662509ull,
0x3030303866336630ull,0x2f092020203b3030ull,0x64616d090a31202full,0x662509203233662eull,
0x316625202c393031ull,0x30316625202c3830ull,0x3130316625202c37ull,0x662e766f6d090a3bull,
0x3131662509203233ull,0x3866336630202c30ull,0x20203b3030303030ull,0x090a31202f2f0920ull,
0x203233662e64616dull,0x202c313131662509ull,0x6625202c38396625ull,0x316625202c303131ull,
0x78616d090a3b3430ull,0x662509203233662eull,0x316625202c323131ull,0x31316625202c3630ull,
0x2e78616d090a3b31ull,0x3166250920323366ull,0x30316625202c3331ull,0x3231316625202c39ull,
0x612e706372090a3bull,0x33662e786f727070ull,0x3431316625092032ull,0x3b3331316625202cull,
0x33662e6c756d090aull,0x3531316625092032ull,0x2c3630316625202cull,0x0a3b343131662520ull,
0x3233662e6c756d09ull,0x2c36313166250920ull,0x202c313131662520ull,0x090a3b3431316625ull,
0x203233662e6c756dull,0x202c373131662509ull,0x25202c3930316625ull,0x6d090a3b34313166ull,
0x09203233662e6c75ull,0x25202c3831316625ull,0x6625202c35313166ull,0x6c756d090a3b3939ull,
0x662509203233662eull,0x316625202c393131ull,0x34396625202c3531ull,0x662e6c756d090a3bull,
0x3231662509203233ull,0x3531316625202c30ull,0x0a3b35396625202cull,0x3233662e64616d09ull,
0x2c31323166250920ull,0x202c363131662520ull,0x6625202c38396625ull,0x616d090a3b383131ull,
0x2509203233662e64ull,0x6625202c32323166ull,0x316625202c323031ull,0x31316625202c3631ull,
0x2e64616d090a3b39ull,0x3166250920323366ull,0x31316625202c3332ull,0x2c34396625202c36ull,
0x0a3b303231662520ull,0x3233662e64616d09ull,0x2c34323166250920ull,0x202c373131662520ull,
0x25202c3730316625ull,0x6d090a3b31323166ull,0x09203233662e6461ull,0x25202c3532316625ull,
0x316625202c383966ull,0x32316625202c3731ull,0x2e64616d090a3b32ull,0x3166250920323366ull,
0x31316625202c3632ull,0x2c39396625202c37ull,0x0a3b333231662520ull,0x3233662e78616d09ull,
0x2c37323166250920ull,0x202c353231662520ull,0x090a3b3632316625ull,0x203233662e78616dull,
0x202c383231662509ull,0x25202c3432316625ull,0x72090a3b37323166ull,0x6f727070612e7063ull,
0x2509203233662e78ull,0x6625202c39323166ull,0x6c2e090a3b383231ull,0x303509363109636full,
0x2e6c756d090a3009ull,0x3166250920323366ull,0x32316625202c3033ull,0x3932316625202c34ull,
0x662e6c756d090a3bull,0x3331662509203233ull,0x3532316625202c31ull,0x3b3932316625202cull,
0x33662e6c756d090aull,0x3233316625092032ull,0x2c3632316625202cull,0x0a3b393231662520ull,
0x3233662e6c756d09ull,0x2c33333166250920ull,0x202c323331662520ull,0x6d090a3b34396625ull,
0x09203233662e6461ull,0x25202c3433316625ull,0x6625202c32303166ull,0x316625202c313331ull,
0x64616d090a3b3333ull,0x662509203233662eull,0x396625202c353331ull,0x3033316625202c38ull,
0x3b3433316625202cull,0x3109636f6c2e090aull,0x090a300931350936ull,0x203233662e6c756dull,
0x202c363331662509ull,0x25202c3233316625ull,0x616d090a3b353966ull,0x2509203233662e64ull,
0x6625202c37333166ull,0x396625202c313331ull,0x3633316625202c34ull,0x662e64616d090a3bull,
0x3331662509203233ull,0x3033316625202c38ull,0x202c39396625202cull,0x090a3b3733316625ull,
0x09363109636f6c2eull,0x756d090a30093235ull,0x2509203233662e6cull,0x6625202c39333166ull,
0x396625202c323331ull,0x2e64616d090a3b39ull,0x3166250920323366ull,0x33316625202c3034ull,
0x2c38396625202c31ull,0x0a3b393331662520ull,0x3233662e64616d09ull,0x2c31343166250920ull,
0x202c303331662520ull,0x25202c3730316625ull,0x2e090a3b30343166ull,0x3509363109636f6cull,
0x78616d090a300938ull,0x662509203233662eull,0x316625202c323431ull,0x33316625202c3533ull,
0x2e78616d090a3b38ull,0x3166250920323366ull,0x34316625202c3334ull,0x3134316625202c32ull,
0x612e706372090a3bull,0x33662e786f727070ull,0x3434316625092032ull,0x3b3334316625202cull,
0x33662e6c756d090aull,0x3534316625092032ull,0x2c3434316625202cull,0x0a3b353331662520ull,
0x3233662e6c756d09ull,0x2c36343166250920ull,0x202c343431662520ull,0x090a3b3833316625ull,
0x203233662e6c756dull,0x202c373431662509ull,0x25202c3434316625ull,0x2e090a3b31343166ull,
0x3509363109636f6cull,0x6c756d090a300930ull,0x662509203233662eull,0x316625202c383431ull,
0x34396625202c3634ull,0x662e64616d090a3bull,0x3431662509203233ull,0x3230316625202c39ull,
0x2c3534316625202cull,0x0a3b383431662520ull,0x3233662e64616d09ull,0x2c35333166250920ull,
0x25202c3839662520ull,0x6625202c37343166ull,0x6c2e090a3b393431ull,0x383509363109636full,
0x2e6c756d090a3009ull,0x3166250920323366ull,0x34316625202c3035ull,0x3b35396625202c36ull,
0x33662e6c756d090aull,0x3135316625092032ull,0x2c3634316625202cull,0x090a3b3939662520ull,
0x203233662e64616dull,0x202c323531662509ull,0x25202c3534316625ull,0x316625202c343966ull,
0x64616d090a3b3035ull,0x662509203233662eull,0x316625202c333531ull,0x38396625202c3534ull,
0x3b3135316625202cull,0x33662e64616d090aull,0x3435316625092032ull,0x2c3734316625202cull,
0x25202c3939662520ull,0x6d090a3b32353166ull,0x09203233662e6461ull,0x25202c3535316625ull,
0x6625202c37343166ull,0x316625202c373031ull,0x78616d090a3b3335ull,0x662509203233662eull,
0x316625202c363531ull,0x33316625202c3435ull,0x2e78616d090a3b35ull,0x3166250920323366ull,
0x35316625202c3735ull,0x3635316625202c35ull,0x612e706372090a3bull,0x33662e786f727070ull,
0x3835316625092032ull,0x3b3735316625202cull,0x33662e6c756d090aull,0x3935316625092032ull,
0x2c3435316625202cull,0x0a3b383531662520ull,0x3233662e6c756d09ull,0x2c30363166250920ull,
0x202c353531662520ull,0x090a3b3835316625ull,0x203233662e6c756dull,0x202c313631662509ull,
0x25202c3835316625ull,0x2e090a3b35333166ull,0x3509363109636f6cull,0x6c756d090a300932ull,
0x662509203233662eull,0x316625202c323631ull,0x39396625202c3935ull,0x662e64616d090a3bull,
0x3631662509203233ull,0x3136316625202c33ull,0x202c38396625202cull,0x090a3b3236316625ull,
0x203233662e64616dull,0x202c343631662509ull,0x25202c3036316625ull,0x6625202c37303166ull,
0x6c2e090a3b333631ull,0x343509363109636full,0x2e6c756d090a3009ull,0x3166250920323366ull,
0x35316625202c3536ull,0x3b34396625202c39ull,0x33662e6c756d090aull,0x3636316625092032ull,
0x2c3935316625202cull,0x090a3b3539662520ull,0x203233662e64616dull,0x202c373631662509ull,
0x25202c3230316625ull,0x6625202c31363166ull,0x616d090a3b353631ull,0x2509203233662e64ull,
0x6625202c38363166ull,0x396625202c313631ull,0x3636316625202c34ull,0x662e64616d090a3bull,
0x3631662509203233ull,0x2c38396625202c39ull,0x202c303631662520ull,0x090a3b3736316625ull,
0x203233662e64616dull,0x202c303731662509ull,0x25202c3036316625ull,0x316625202c393966ull,
0x78616d090a3b3836ull,0x662509203233662eull,0x316625202c313731ull,0x37316625202c3936ull,
0x2e78616d090a3b30ull,0x3166250920323366ull,0x37316625202c3237ull,0x3436316625202c31ull,
0x612e706372090a3bull,0x33662e786f727070ull,0x3337316625092032ull,0x3b3237316625202cull,
0x3109636f6c2e090aull,0x090a300938350936ull,0x203233662e6c756dull,0x202c343731662509ull,
0x25202c3936316625ull,0x6d090a3b33373166ull,0x09203233662e6c75ull,0x25202c3935316625ull,
0x6625202c30373166ull,0x6c2e090a3b333731ull,0x303509363109636full,0x2e6c756d090a3009ull,
0x3166250920323366ull,0x37316625202c3537ull,0x3436316625202c33ull,0x662e6c756d090a3bull,
0x3731662509203233ull,0x3935316625202c36ull,0x0a3b34396625202cull,0x3233662e64616d09ull,
0x2c37373166250920ull,0x202c323031662520ull,0x25202c3437316625ull,0x6d090a3b36373166ull,
0x09203233662e6461ull,0x25202c3533316625ull,0x316625202c383966ull,0x37316625202c3537ull,
0x636f6c2e090a3b37ull,0x3009313509363109ull,0x33662e6c756d090aull,0x3837316625092032ull,
0x2c3935316625202cull,0x090a3b3539662520ull,0x203233662e64616dull,0x202c393731662509ull,
0x25202c3437316625ull,0x316625202c343966ull,0x64616d090a3b3837ull,0x662509203233662eull,
0x316625202c383331ull,0x39396625202c3537ull,0x3b3937316625202cull,0x3109636f6c2e090aull,
0x090a300932350936ull,0x203233662e6c756dull,0x202c303831662509ull,0x25202c3935316625ull,
0x616d090a3b393966ull,0x2509203233662e64ull,0x6625202c31383166ull,0x396625202c343731ull,
0x3038316625202c38ull,0x662e64616d090a3bull,0x3431662509203233ull,0x3537316625202c31ull,
0x2c3730316625202cull,0x0a3b313831662520ull,0x363109636f6c2e09ull,0x6d090a3009383509ull,
0x09203233662e7861ull,0x25202c3234316625ull,0x6625202c35333166ull,0x616d090a3b383331ull,
0x2509203233662e78ull,0x6625202c33343166ull,0x316625202c323431ull,0x706372090a3b3134ull,
0x2e786f727070612eull,0x3166250920323366ull,0x34316625202c3434ull,0x2e6c756d090a3b33ull,
0x3166250920323366ull,0x34316625202c3238ull,0x3533316625202c34ull,0x662e6c756d090a3bull,
0x3831662509203233ull,0x3434316625202c33ull,0x3b3833316625202cull,0x33662e6c756d090aull,
0x3438316625092032ull,0x2c3434316625202cull,0x0a3b313431662520ull,0x363109636f6c2e09ull,
0x6d090a3009303509ull,0x09203233662e6c75ull,0x25202c3538316625ull,0x6625202c33383166ull,
0x64616d090a3b3439ull,0x662509203233662eull,0x316625202c363831ull,0x38316625202c3230ull,
0x3538316625202c32ull,0x662e64616d090a3bull,0x3331662509203233ull,0x2c38396625202c35ull,
0x202c343831662520ull,0x090a3b3638316625ull,0x09363109636f6c2eull,0x756d090a30093835ull,
0x2509203233662e6cull,0x6625202c30353166ull,0x396625202c333831ull,0x2e6c756d090a3b35ull,
0x3166250920323366ull,0x38316625202c3135ull,0x3b39396625202c33ull,0x33662e64616d090aull,
0x3235316625092032ull,0x2c3238316625202cull,0x25202c3439662520ull,0x6d090a3b30353166ull,
0x09203233662e6461ull,0x25202c3335316625ull,0x6625202c32383166ull,0x35316625202c3839ull,
0x2e64616d090a3b31ull,0x3166250920323366ull,0x38316625202c3435ull,0x2c39396625202c34ull,
0x0a3b323531662520ull,0x3233662e64616d09ull,0x2c35353166250920ull,0x202c343831662520ull,
0x25202c3730316625ull,0x6d090a3b33353166ull,0x09203233662e7861ull,0x25202c3635316625ull,
0x6625202c34353166ull,0x616d090a3b353331ull,0x2509203233662e78ull,0x6625202c37353166ull,
0x316625202c353531ull,0x706372090a3b3635ull,0x2e786f727070612eull,0x3166250920323366ull,
0x35316625202c3835ull,0x2e6c756d090a3b37ull,0x3166250920323366ull,0x35316625202c3935ull,
0x3835316625202c34ull,0x662e6c756d090a3bull,0x3631662509203233ull,0x3535316625202c30ull,
0x3b3835316625202cull,0x33662e6c756d090aull,0x3136316625092032ull,0x2c3835316625202cull,
0x0a3b353331662520ull,0x363109636f6c2e09ull,0x6d090a3009323509ull,0x09203233662e6c75ull,
0x25202c3236316625ull,0x6625202c39353166ull,0x64616d090a3b3939ull,0x662509203233662eull,
0x316625202c333631ull,0x38396625202c3136ull,0x3b3236316625202cull,0x33662e64616d090aull,
0x3738316625092032ull,0x2c3036316625202cull,0x202c373031662520ull,0x090a3b3336316625ull,
0x09363109636f6c2eull,0x756d090a30093435ull,0x2509203233662e6cull,0x6625202c35363166ull,
0x396625202c393531ull,0x2e6c756d090a3b34ull,0x3166250920323366ull,0x35316625202c3636ull,
0x3b35396625202c39ull,0x33662e64616d090aull,0x3736316625092032ull,0x2c3230316625202cull,
0x202c313631662520ull,0x090a3b3536316625ull,0x203233662e64616dull,0x202c383631662509ull,
0x25202c3136316625ull,0x316625202c343966ull,0x64616d090a3b3636ull,0x662509203233662eull,
0x396625202c393631ull,0x3036316625202c38ull,0x3b3736316625202cull,0x33662e64616d090aull,
0x3037316625092032ull,0x2c3036316625202cull,0x25202c3939662520ull,0x6d090a3b38363166ull,
0x09203233662e7861ull,0x25202c3137316625ull,0x6625202c39363166ull,0x616d090a3b303731ull,
0x2509203233662e78ull,0x6625202c32373166ull,0x316625202c313731ull,0x706372090a3b3738ull,
0x2e786f727070612eull,0x3166250920323366ull,0x37316625202c3838ull,0x636f6c2e090a3b32ull,
0x3009383509363109ull,0x33662e6c756d090aull,0x3437316625092032ull,0x2c3936316625202cull,
0x0a3b383831662520ull,0x3233662e6c756d09ull,0x2c39353166250920ull,0x202c303731662520ull,
0x090a3b3838316625ull,0x09373109636f6c2eull,0x63090a3009313631ull,0x732e3436732e7476ull,
0x3564722509203233ull,0x0a3b317225202c37ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x35647225202c3835ull,0x40090a3b34202c37ull,0x6172622031702521ull,0x5f305f744c240920ull,
0x090a3b3634353434ull,0x09373109636f6c2eull,0x6d090a3009343631ull,0x09203436752e766full,
0x64202c3935647225ull,0x090a3b335f5f7370ull,0x752e6f6c2e6c756dull,0x3934722509203233ull,
0x31202c317225202cull,0x2e747663090a3b32ull,0x203233752e343675ull,0x202c303664722509ull,
0x61090a3b39347225ull,0x09203436752e6464ull,0x7225202c36647225ull,0x647225202c303664ull,
0x732e646c090a3b31ull,0x33662e6465726168ull,0x3938316625092032ull,0x2b366472255b202cull,
0x2e646c090a3b5d30ull,0x662e646572616873ull,0x3931662509203233ull,0x366472255b202c30ull,
0x646c090a3b5d342bull,0x2e6465726168732eull,0x3166250920323366ull,0x6472255b202c3139ull,
0x6d090a3b5d382b36ull,0x09203233662e6c75ull,0x25202c3239316625ull,0x6625202c39353166ull,
0x616d090a3b303931ull,0x2509203233662e64ull,0x6625202c33393166ull,0x316625202c393831ull,
0x39316625202c3437ull,0x2e6c756d090a3b32ull,0x3166250920323366ull,0x38316625202c3439ull,
0x3738316625202c38ull,0x662e64616d090a3bull,0x3931662509203233ull,0x3139316625202c35ull,
0x2c3439316625202cull,0x0a3b333931662520ull,0x3436752e64646109ull,0x2c31366472250920ull,
0x202c383564722520ull,0x090a3b3935647225ull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x5d302b3136647225ull,0x3b3539316625202cull,0x345f305f744c240aull,0x6d090a3a36343534ull,
0x09203436752e766full,0x64202c3935647225ull,0x090a3b335f5f7370ull,0x09373109636f6c2eull,
0x62090a3009373631ull,0x20636e79732e7261ull,0x252140090a3b3009ull,0x0920617262203170ull,
0x35345f305f744c24ull,0x6c2e090a3b383530ull,0x373109373109636full,0x766f6d090a300930ull,
0x722509203233752eull,0x090a3b30202c3035ull,0x2e656e2e70746573ull,0x3470250920323375ull,
0x25202c317225202cull,0x2540090a3b303572ull,0x0920617262203470ull,0x35345f305f744c24ull,
0x6f6d090a3b303735ull,0x2509203436752e76ull,0x5f5f202c32366472ull,0x6572785f61647563ull,
0x0a3b323537317366ull,0x3233752e766f6d09ull,0x202c313572250920ull,0x2e766f6d090a3b30ull,
0x6472250920343673ull,0x35647225202c3336ull,0x2e766f6d090a3b39ull,0x6472250920343673ull,
0x36647225202c3436ull,0x732e646c090a3b32ull,0x33662e6465726168ull,0x3639316625092032ull,
0x5f5f7370645b202cull,0x6c090a3b5d342b33ull,0x6465726168732e64ull,0x662509203233662eull,
0x70645b202c373931ull,0x3b5d302b335f5f73ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c383931662509ull,0x2b335f5f7370645bull,0x2e646c090a3b5d38ull,0x662e646572616873ull,
0x3931662509203233ull,0x5f7370645b202c39ull,0x0a3b5d32312b335full,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3030326625ull,0x312b335f5f737064ull,0x2e646c090a3b5d36ull,
0x662e646572616873ull,0x3032662509203233ull,0x5f7370645b202c31ull,0x0a3b5d30322b335full,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3230326625ull,0x322b335f5f737064ull,
0x2e646c090a3b5d34ull,0x662e646572616873ull,0x3032662509203233ull,0x5f7370645b202c33ull,
0x0a3b5d38322b335full,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3430326625ull,
0x332b335f5f737064ull,0x2e646c090a3b5d32ull,0x662e646572616873ull,0x3032662509203233ull,
0x5f7370645b202c35ull,0x0a3b5d36332b335full,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3630326625ull,0x342b335f5f737064ull,0x2e646c090a3b5d30ull,0x662e646572616873ull,
0x3032662509203233ull,0x5f7370645b202c37ull,0x0a3b5d34342b335full,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3830326625ull,0x342b335f5f737064ull,0x2e646c090a3b5d38ull,
0x662e646572616873ull,0x3032662509203233ull,0x5f7370645b202c39ull,0x0a3b5d32352b335full,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3031326625ull,0x352b335f5f737064ull,
0x2e646c090a3b5d36ull,0x662e646572616873ull,0x3132662509203233ull,0x5f7370645b202c31ull,
0x0a3b5d30362b335full,0x36345f305f744c24ull,0x2f2f200a3a343935ull,0x4c203e706f6f6c3cull,
0x79646f6220706f6full,0x373120656e696c20ull,0x697473656e202c30ull,0x687470656420676eull,
0x657469202c31203aull,0x3a736e6f69746172ull,0x6f6c2e090a363120ull,0x0938390937310963ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x2c32313266250920ull,0x2b33366472255b20ull,
0x6f6c2e090a3b5d30ull,0x3037310937310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x3031326625092032ull,0x5f5f7370645b202cull,0x090a3b5d36352b33ull,0x09373109636f6c2eull,
0x6573090a30093839ull,0x3233752e74672e74ull,0x722509203233662eull,0x31326625202c3235ull,
0x3031326625202c32ull,0x732e67656e090a3bull,0x3335722509203233ull,0x0a3b32357225202cull,
0x373109636f6c2e09ull,0x090a300930373109ull,0x65726168732e646cull,0x2509203233662e64ull,
0x645b202c31313266ull,0x30362b335f5f7370ull,0x636f6c2e090a3b5dull,0x3009383909373109ull,
0x74672e746573090aull,0x3233662e3233752eull,0x202c343572250920ull,0x25202c3231326625ull,
0x6e090a3b31313266ull,0x09203233732e6765ull,0x7225202c35357225ull,0x646461090a3b3435ull,
0x722509203233732eull,0x33357225202c3635ull,0x0a3b35357225202cull,0x373109636f6c2e09ull,
0x090a300930373109ull,0x65726168732e646cull,0x2509203233662e64ull,0x645b202c38303266ull,
0x38342b335f5f7370ull,0x636f6c2e090a3b5dull,0x3009383909373109ull,0x74672e746573090aull,
0x3233662e3233752eull,0x202c373572250920ull,0x25202c3231326625ull,0x6e090a3b38303266ull,
0x09203233732e6765ull,0x7225202c38357225ull,0x6f6c2e090a3b3735ull,0x3037310937310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x3930326625092032ull,0x5f5f7370645b202cull,
0x090a3b5d32352b33ull,0x09373109636f6c2eull,0x6573090a30093839ull,0x3233752e74672e74ull,
0x722509203233662eull,0x31326625202c3935ull,0x3930326625202c32ull,0x732e67656e090a3bull,
0x3036722509203233ull,0x0a3b39357225202cull,0x3233732e64646109ull,0x202c313672250920ull,
0x7225202c38357225ull,0x6f6c2e090a3b3036ull,0x3037310937310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x3630326625092032ull,0x5f5f7370645b202cull,0x090a3b5d30342b33ull,
0x09373109636f6c2eull,0x6573090a30093839ull,0x3233752e74672e74ull,0x722509203233662eull,
0x31326625202c3236ull,0x3630326625202c32ull,0x732e67656e090a3bull,0x3336722509203233ull,
0x0a3b32367225202cull,0x373109636f6c2e09ull,0x090a300930373109ull,0x65726168732e646cull,
0x2509203233662e64ull,0x645b202c37303266ull,0x34342b335f5f7370ull,0x636f6c2e090a3b5dull,
0x3009383909373109ull,0x74672e746573090aull,0x3233662e3233752eull,0x202c343672250920ull,
0x25202c3231326625ull,0x6e090a3b37303266ull,0x09203233732e6765ull,0x7225202c35367225ull,
0x646461090a3b3436ull,0x722509203233732eull,0x33367225202c3636ull,0x0a3b35367225202cull,
0x373109636f6c2e09ull,0x090a300930373109ull,0x65726168732e646cull,0x2509203233662e64ull,
0x645b202c36393166ull,0x5d342b335f5f7370ull,0x09636f6c2e090a3bull,0x0a30093839093731ull,
0x2e74672e74657309ull,0x203233662e323375ull,0x25202c3736722509ull,0x6625202c32313266ull,
0x656e090a3b363931ull,0x2509203233732e67ull,0x367225202c383672ull,0x636f6c2e090a3b37ull,
0x0930373109373109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c37393166250920ull,
0x335f5f7370645b20ull,0x6c2e090a3b5d302bull,0x383909373109636full,0x2e746573090a3009ull,
0x662e3233752e7467ull,0x3936722509203233ull,0x2c3231326625202cull,0x0a3b373931662520ull,
0x3233732e67656e09ull,0x202c303772250920ull,0x61090a3b39367225ull,0x09203233732e6464ull,
0x7225202c31377225ull,0x30377225202c3836ull,0x09636f6c2e090a3bull,0x3009303731093731ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c383931662509ull,0x2b335f5f7370645bull,
0x6f6c2e090a3b5d38ull,0x0938390937310963ull,0x672e746573090a30ull,0x33662e3233752e74ull,
0x2c32377225092032ull,0x202c323132662520ull,0x090a3b3839316625ull,0x203233732e67656eull,
0x25202c3337722509ull,0x6c2e090a3b323772ull,0x373109373109636full,0x2e646c090a300930ull,
0x662e646572616873ull,0x3931662509203233ull,0x5f7370645b202c39ull,0x0a3b5d32312b335full,
0x373109636f6c2e09ull,0x73090a3009383909ull,0x33752e74672e7465ull,0x2509203233662e32ull,
0x326625202c343772ull,0x39316625202c3231ull,0x2e67656e090a3b39ull,0x3772250920323373ull,
0x3b34377225202c35ull,0x33732e646461090aull,0x2c36377225092032ull,0x25202c3337722520ull,
0x6c2e090a3b353772ull,0x373109373109636full,0x2e646c090a300930ull,0x662e646572616873ull,
0x3032662509203233ull,0x5f7370645b202c30ull,0x0a3b5d36312b335full,0x373109636f6c2e09ull,
0x73090a3009383909ull,0x33752e74672e7465ull,0x2509203233662e32ull,0x326625202c373772ull,
0x30326625202c3231ull,0x2e67656e090a3b30ull,0x3772250920323373ull,0x3b37377225202c38ull,
0x3109636f6c2e090aull,0x0a30093037310937ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3130326625ull,0x322b335f5f737064ull,0x6f6c2e090a3b5d30ull,0x0938390937310963ull,
0x672e746573090a30ull,0x33662e3233752e74ull,0x2c39377225092032ull,0x202c323132662520ull,
0x090a3b3130326625ull,0x203233732e67656eull,0x25202c3038722509ull,0x6461090a3b393772ull,
0x2509203233732e64ull,0x377225202c313872ull,0x3b30387225202c38ull,0x3109636f6c2e090aull,
0x0a30093037310937ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3230326625ull,
0x322b335f5f737064ull,0x6f6c2e090a3b5d34ull,0x0938390937310963ull,0x672e746573090a30ull,
0x33662e3233752e74ull,0x2c32387225092032ull,0x202c323132662520ull,0x090a3b3230326625ull,
0x203233732e67656eull,0x25202c3338722509ull,0x6c2e090a3b323872ull,0x373109373109636full,
0x2e646c090a300930ull,0x662e646572616873ull,0x3032662509203233ull,0x5f7370645b202c33ull,
0x0a3b5d38322b335full,0x373109636f6c2e09ull,0x73090a3009383909ull,0x33752e74672e7465ull,
0x2509203233662e32ull,0x326625202c343872ull,0x30326625202c3231ull,0x2e67656e090a3b33ull,
0x3872250920323373ull,0x3b34387225202c35ull,0x33732e646461090aull,0x2c36387225092032ull,
0x25202c3338722520ull,0x6c2e090a3b353872ull,0x373109373109636full,0x2e646c090a300930ull,
0x662e646572616873ull,0x3032662509203233ull,0x5f7370645b202c34ull,0x0a3b5d32332b335full,
0x373109636f6c2e09ull,0x73090a3009383909ull,0x33752e74672e7465ull,0x2509203233662e32ull,
0x326625202c373872ull,0x30326625202c3231ull,0x2e67656e090a3b34ull,0x3872250920323373ull,
0x3b37387225202c38ull,0x3109636f6c2e090aull,0x0a30093037310937ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3530326625ull,0x332b335f5f737064ull,0x6f6c2e090a3b5d36ull,
0x0938390937310963ull,0x672e746573090a30ull,0x33662e3233752e74ull,0x2c39387225092032ull,
0x202c323132662520ull,0x090a3b3530326625ull,0x203233732e67656eull,0x25202c3039722509ull,
0x6461090a3b393872ull,0x2509203233732e64ull,0x387225202c313972ull,0x3b30397225202c38ull,
0x33732e646461090aull,0x2c32397225092032ull,0x25202c3638722520ull,0x6461090a3b313972ull,
0x2509203233732e64ull,0x387225202c333972ull,0x3b32397225202c31ull,0x33732e646461090aull,
0x2c34397225092032ull,0x25202c3637722520ull,0x6461090a3b333972ull,0x2509203233732e64ull,
0x377225202c353972ull,0x3b34397225202c31ull,0x33732e646461090aull,0x2c36397225092032ull,
0x25202c3636722520ull,0x6461090a3b353972ull,0x2509203233732e64ull,0x367225202c373972ull,
0x3b36397225202c31ull,0x33732e646461090aull,0x2c38397225092032ull,0x25202c3635722520ull,
0x7473090a3b373972ull,0x2e6465726168732eull,0x72255b0920323373ull,0x202c5d302b343664ull,
0x61090a3b38397225ull,0x09203233752e6464ull,0x7225202c31357225ull,0x090a3b34202c3135ull,
0x203436752e646461ull,0x202c343664722509ull,0x34202c3436647225ull,0x752e646461090a3bull,
0x3664722509203436ull,0x3336647225202c33ull,0x6f6d090a3b34202cull,0x2509203233752e76ull,
0x3b3436202c393972ull,0x6e2e70746573090aull,0x2509203233732e65ull,0x31357225202c3570ull,
0x0a3b39397225202cull,0x7262203570254009ull,0x305f744c24092061ull,0x0a3b34393536345full,
0x3233732e766f6d09ull,0x2c30303172250920ull,0x5f744c240a3b3020ull,0x3a38313637345f30ull,
0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,0x656e202c38392065ull,
0x656420676e697473ull,0x202c31203a687470ull,0x6f69746172657469ull,0x090a3531203a736eull,
0x203233732e766f6dull,0x202c313031722509ull,0x305f744c240a3b30ull,0x0a3a36383338345full,
0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,0x73656e202c383920ull,
0x70656420676e6974ull,0x69202c32203a6874ull,0x6e6f697461726574ull,0x2e090a3631203a73ull,
0x3109373109636f6cull,0x6573090a30093630ull,0x33732e656c2e7074ull,0x202c367025092032ull,
0x25202c3130317225ull,0x40090a3b30303172ull,0x2061726220367025ull,0x355f305f744c2409ull,
0x2f200a3b38333139ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3920656e696c2079ull,0x2064616568202c38ull,0x2064656c6562616cull,0x38345f305f744c24ull,
0x6c756d090a363833ull,0x203233752e6f6c2eull,0x202c323031722509ull,0x34202c3130317225ull,
0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3536647225ull,0x61090a3b32303172ull,
0x09203436752e6464ull,0x25202c3636647225ull,0x7225202c35366472ull,0x646c090a3b323664ull,
0x2e6465726168732eull,0x3172250920323373ull,0x6472255b202c3330ull,0x090a3b5d302b3636ull,
0x752e6f6c2e6c756dull,0x3031722509203233ull,0x3030317225202c34ull,0x7663090a3b34202cull,
0x33752e3436752e74ull,0x3736647225092032ull,0x3b3430317225202cull,0x36752e646461090aull,
0x3836647225092034ull,0x2c3736647225202cull,0x0a3b323664722520ull,0x726168732e646c09ull,
0x09203233732e6465ull,0x5b202c3530317225ull,0x5d302b3836647225ull,0x2e70746573090a3bull,
0x09203233732e656eull,0x317225202c377025ull,0x30317225202c3530ull,0x37702540090a3b33ull,
0x4c24092061726220ull,0x333139355f305f74ull,0x6c3c2f2f200a3b38ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x202c383920656e69ull,0x62616c2064616568ull,
0x744c242064656c65ull,0x36383338345f305full,0x6168732e646c090aull,0x203233732e646572ull,
0x202c333031722509ull,0x302b36366472255bull,0x2e646461090a3b5dull,0x3172250920323373ull,
0x30317225202c3630ull,0x73090a3b31202c33ull,0x6465726168732e74ull,0x255b09203233732eull,
0x2c5d302b36366472ull,0x0a3b363031722520ull,0x39355f305f744c24ull,0x5f4c240a3a383331ull,
0x3a32343835335f30ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x6568202c38392065ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x090a36383338345full,0x203233732e646461ull,0x202c313031722509ull,0x31202c3130317225ull,
0x752e766f6d090a3bull,0x3031722509203233ull,0x090a3b3631202c37ull,0x2e656e2e70746573ull,
0x3870250920323373ull,0x2c3130317225202cull,0x0a3b373031722520ull,0x7262203870254009ull,
0x305f744c24092061ull,0x0a3b36383338345full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x616568202c383920ull,0x656c6562616c2064ull,
0x5f305f744c242064ull,0x61090a3831363734ull,0x09203233732e6464ull,0x25202c3030317225ull,
0x3b31202c30303172ull,0x33752e766f6d090aull,0x3830317225092032ull,0x73090a3b3531202cull,
0x732e656e2e707465ull,0x2c39702509203233ull,0x202c303031722520ull,0x090a3b3830317225ull,
0x6172622039702540ull,0x5f305f744c240920ull,0x240a3b3831363734ull,0x3535345f305f744cull,
0x6f6c2e090a3a3037ull,0x3037310937310963ull,0x2e766f6d090a3009ull,0x6472250920343675ull,
0x75635f5f202c3236ull,0x73666572785f6164ull,0x2e090a3b32353731ull,0x3109373109636f6cull,
0x756d090a30093237ull,0x3233752e6f6c2e6cull,0x2c39303172250920ull,0x3231202c31722520ull,
0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3936647225ull,0x61090a3b39303172ull,
0x09203436752e6464ull,0x7225202c36647225ull,0x647225202c393664ull,0x732e646c090a3b31ull,
0x33662e6465726168ull,0x3331326625092032ull,0x2b366472255b202cull,0x766f6d090a3b5d30ull,
0x662509203233662eull,0x326625202c343132ull,0x2e646c090a3b3331ull,0x662e646572616873ull,
0x3132662509203233ull,0x366472255b202c35ull,0x6f6d090a3b5d342bull,0x2509203233662e76ull,
0x6625202c36313266ull,0x646c090a3b353132ull,0x2e6465726168732eull,0x3266250920323366ull,
0x6472255b202c3731ull,0x6d090a3b5d382b36ull,0x09203233662e766full,0x25202c3831326625ull,
0x4c240a3b37313266ull,0x353035345f305f74ull,0x2e766f6d090a3a38ull,0x6472250920343675ull,
0x75635f5f202c3236ull,0x73666572785f6164ull,0x2e090a3b32353731ull,0x3109373109636f6cull,
0x6162090a30093537ull,0x0920636e79732e72ull,0x2e6c756d090a3b30ull,0x09203233752e6f6cull,
0x25202c3031317225ull,0x090a3b34202c3172ull,0x2e3436752e747663ull,0x6472250920323375ull,
0x31317225202c3037ull,0x70252140090a3b30ull,0x2409206172622031ull,0x3139345f305f744cull,
0x6f6c2e090a3b3435ull,0x3837310937310963ull,0x2e646461090a3009ull,0x6472250920343675ull,
0x37647225202c3137ull,0x3236647225202c30ull,0x68732e646c090a3bull,0x3233752e64657261ull,
0x2c31313172250920ull,0x2b31376472255b20ull,0x6c756d090a3b5d30ull,0x203233752e6f6c2eull,
0x202c323131722509ull,0x31202c3131317225ull,0x2e747663090a3b32ull,0x203233752e343675ull,
0x202c323764722509ull,0x090a3b3231317225ull,0x203436752e646461ull,0x202c333764722509ull,
0x25202c3237647225ull,0x6f6d090a3b316472ull,0x2509203233662e76ull,0x6625202c39313266ull,
0x7473090a3b343132ull,0x2e6465726168732eull,0x72255b0920323366ull,0x202c5d302b333764ull,
0x090a3b3931326625ull,0x203233662e766f6dull,0x202c303232662509ull,0x090a3b3631326625ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x5d342b3337647225ull,0x3b3032326625202cull,
0x33662e766f6d090aull,0x3132326625092032ull,0x3b3831326625202cull,0x6168732e7473090aull,
0x203233662e646572ull,0x2b33376472255b09ull,0x32326625202c5d38ull,0x305f744c240a3b31ull,
0x0a3a34353139345full,0x373109636f6c2e09ull,0x090a300939313509ull,0x636e79732e726162ull,
0x6c2e090a3b300920ull,0x323509373109636full,0x766f6d090a300936ull,0x722509203233732eull,
0x0a3b30202c333131ull,0x3233662e766f6d09ull,0x2c32323266250920ull,0x6666376637663020ull,
0x092020203b666666ull,0x3230342e33202f2full,0x090a38332b653238ull,0x203436752e766f6dull,
0x202c343764722509ull,0x0a3b3473646f7270ull,0x3436752e766f6d09ull,0x2c35376472250920ull,
0x61546168706c6120ull,0x6d090a3b34656c62ull,0x09203436752e766full,0x73202c3637647225ull,
0x6174756d7265705full,0x325f5f736e6f6974ull,0x5f305f744c240a3bull,0x200a3a3837313035ull,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c363235ull,
0x70656420676e6974ull,0x65202c31203a6874ull,0x646574616d697473ull,0x6974617265746920ull,
0x0a3631203a736e6full,0x373109636f6c2e09ull,0x090a300935343309ull,0x203233732e646461ull,
0x202c343131722509ull,0x25202c3331317225ull,0x766f6d090a3b3172ull,0x722509203233752eull,
0x313939202c353131ull,0x2e70746573090a3bull,0x09203233732e7467ull,0x7225202c30317025ull,
0x317225202c343131ull,0x702540090a3b3531ull,0x0920617262203031ull,0x35325f305f744c24ull,
0x6c3c2f2f200a3b38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c36323520656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x373130355f305f74ull,
0x09636f6c2e090a38ull,0x3009383433093731ull,0x6f6c2e6c756d090aull,0x722509203233752eull,
0x317225202c363131ull,0x090a3b34202c3431ull,0x2e3436752e747663ull,0x6472250920323375ull,
0x31317225202c3737ull,0x702e646c090a3b36ull,0x3436752e6d617261ull,0x2c38376472250920ull,
0x616475635f5f5b20ull,0x385a5f5f6d726170ull,0x73736572706d6f63ull,0x35505f30536a4b50ull,
0x65705f32746e6975ull,0x6f69746174756d72ull,0x6461090a3b5d736eull,0x2509203436752e64ull,
0x7225202c39376472ull,0x647225202c373764ull,0x2e646c090a3b3837ull,0x752e6c61626f6c67ull,
0x3131722509203233ull,0x376472255b202c37ull,0x6d090a3b5d302b39ull,0x09203233752e766full,
0x31202c3831317225ull,0x746573090a3b3935ull,0x3233732e74672e70ull,0x202c313170250920ull,
0x25202c3431317225ull,0x40090a3b38313172ull,0x6172622031317025ull,0x5f305f744c240920ull,
0x200a3b3433343035ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c363235ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x2e090a3837313035ull,0x3309373109636f6cull,0x7663090a30093934ull,0x33732e3436732e74ull,
0x3038647225092032ull,0x3b3431317225202cull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c313864ull,0x090a3b34202c3038ull,0x203436752e646461ull,0x202c323864722509ull,
0x25202c3637647225ull,0x73090a3b31386472ull,0x6465726168732e74ull,0x255b09203233752eull,
0x2c5d302b32386472ull,0x0a3b373131722520ull,0x30355f305f744c24ull,0x2f2f200a3a343334ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x323520656e696c20ull,
0x2064616568202c36ull,0x2064656c6562616cull,0x30355f305f744c24ull,0x6f6c2e090a383731ull,
0x3135330937310963ull,0x2e766f6d090a3009ull,0x3172250920323373ull,0x090a3b30202c3931ull,
0x203436732e766f6dull,0x202c333864722509ull,0x6d090a3b31647225ull,0x09203233732e766full,
0x30202c3032317225ull,0x662e766f6d090a3bull,0x3232662509203233ull,0x3030306630202c33ull,
0x20203b3030303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,0x202c343232662509ull,
0x3030303030306630ull,0x2f092020203b3030ull,0x766f6d090a30202full,0x662509203233662eull,
0x306630202c353232ull,0x3b30303030303030ull,0x30202f2f09202020ull,0x355f305f744c240aull,
0x2f200a3a38353431ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3320656e696c2079ull,
0x7473656e202c3135ull,0x7470656420676e69ull,0x7469202c31203a68ull,0x736e6f6974617265ull,
0x6c2e090a3631203aull,0x323209373109636full,0x726873090a300934ull,0x722509203233752eull,
0x317225202c313231ull,0x31317225202c3731ull,0x2e646e61090a3b39ull,0x3172250920323362ull,
0x32317225202c3232ull,0x63090a3b33202c31ull,0x752e3436752e7476ull,0x3864722509203233ull,
0x3232317225202c34ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c35386472ull,
0x0a3b34202c343864ull,0x3436752e64646109ull,0x2c36386472250920ull,0x202c353864722520ull,
0x090a3b3537647225ull,0x74736e6f632e646cull,0x662509203233662eull,0x72255b202c363232ull,
0x0a3b5d302b363864ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3732326625ull,
0x5d302b3338647225ull,0x68732e646c090a3bull,0x3233662e64657261ull,0x2c38323266250920ull,
0x2b33386472255b20ull,0x2e646c090a3b5d34ull,0x662e646572616873ull,0x3232662509203233ull,
0x386472255b202c39ull,0x6d090a3b5d382b33ull,0x09203233662e6461ull,0x25202c3532326625ull,
0x6625202c36323266ull,0x326625202c373232ull,0x64616d090a3b3532ull,0x662509203233662eull,
0x326625202c343232ull,0x32326625202c3632ull,0x3432326625202c38ull,0x662e64616d090a3bull,
0x3232662509203233ull,0x3632326625202c33ull,0x2c3932326625202cull,0x0a3b333232662520ull,
0x373109636f6c2e09ull,0x090a300935323209ull,0x203436752e646461ull,0x202c373864722509ull,
0x25202c3538647225ull,0x6c090a3b34376472ull,0x2e74736e6f632e64ull,0x3172250920323373ull,
0x6472255b202c3332ull,0x090a3b5d302b3738ull,0x203233732e646461ull,0x202c303231722509ull,
0x25202c3332317225ull,0x61090a3b30323172ull,0x09203436752e6464ull,0x25202c3338647225ull,
0x3231202c33386472ull,0x732e646461090a3bull,0x3131722509203233ull,0x3931317225202c39ull,
0x6f6d090a3b32202cull,0x2509203233752e76ull,0x3233202c34323172ull,0x2e70746573090a3bull,
0x09203233732e656eull,0x7225202c32317025ull,0x317225202c393131ull,0x702540090a3b3432ull,
0x0920617262203231ull,0x31355f305f744c24ull,0x2f2f200a3b383534ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x323520656e696c20ull,0x2064616568202c36ull,
0x2064656c6562616cull,0x30355f305f744c24ull,0x6f6c2e090a383731ull,0x3336320937310963ull,
0x2e646e61090a3009ull,0x3172250920323362ull,0x32317225202c3532ull,0x0a3b353532202c30ull,
0x3233732e72687309ull,0x2c36323172250920ull,0x202c303231722520ull,0x726873090a3b3631ull,
0x722509203233732eull,0x317225202c373231ull,0x090a3b38202c3032ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c30333266ull,0x75735f616475635full,0x302b30363531736dull,
0x2e766f6d090a3b5dull,0x3266250920323366ull,0x31346630202c3133ull,0x203b303030303031ull,
0x0a39202f2f092020ull,0x3233662e6c756d09ull,0x2c32333266250920ull,0x202c303332662520ull,
0x090a3b3133326625ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c33333266ull,
0x75735f616475635full,0x342b30363531736dull,0x2e766f6d090a3b5dull,0x3266250920323366ull,
0x31346630202c3433ull,0x203b303030303031ull,0x0a39202f2f092020ull,0x3233662e6c756d09ull,
0x2c35333266250920ull,0x202c333332662520ull,0x090a3b3433326625ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c36333266ull,0x75735f616475635full,0x382b30363531736dull,
0x2e766f6d090a3b5dull,0x3266250920323366ull,0x31346630202c3733ull,0x203b303030303031ull,
0x0a39202f2f092020ull,0x3233662e6c756d09ull,0x2c38333266250920ull,0x202c363332662520ull,
0x090a3b3733326625ull,0x662e6e722e747663ull,0x09203233732e3233ull,0x25202c3933326625ull,
0x63090a3b35323172ull,0x33662e6e722e7476ull,0x2509203233732e32ull,0x7225202c30343266ull,
0x6e61090a3b363231ull,0x2509203233622e64ull,0x7225202c38323172ull,0x353532202c373231ull,
0x662e627573090a3bull,0x3432662509203233ull,0x3233326625202c31ull,0x3b3532326625202cull,
0x33662e627573090aull,0x3234326625092032ull,0x2c3533326625202cull,0x0a3b343232662520ull,
0x3233662e62757309ull,0x2c33343266250920ull,0x202c383332662520ull,0x090a3b3332326625ull,
0x203233662e6c756dull,0x202c343432662509ull,0x25202c3933326625ull,0x63090a3b39333266ull,
0x33662e6e722e7476ull,0x2509203233732e32ull,0x7225202c35343266ull,0x756d090a3b383231ull,
0x2509203233662e6cull,0x6625202c36343266ull,0x326625202c393332ull,0x6c756d090a3b3134ull,
0x662509203233662eull,0x326625202c373432ull,0x34326625202c3933ull,0x2e6c756d090a3b32ull,
0x3266250920323366ull,0x33326625202c3834ull,0x3334326625202c39ull,0x662e6c756d090a3bull,
0x3432662509203233ull,0x3034326625202c39ull,0x3b3534326625202cull,0x33662e627573090aull,
0x3035326625092032ull,0x2c3934326625202cull,0x0a3b343432662520ull,0x3233662e6c756d09ull,
0x2c31353266250920ull,0x202c353432662520ull,0x090a3b3532326625ull,0x203233662e6c756dull,
0x202c323532662509ull,0x25202c3534326625ull,0x6d090a3b34323266ull,0x09203233662e6c75ull,
0x25202c3335326625ull,0x6625202c35343266ull,0x6372090a3b333232ull,0x786f727070612e70ull,
0x662509203233662eull,0x326625202c343532ull,0x627573090a3b3035ull,0x662509203233662eull,
0x326625202c353532ull,0x34326625202c3135ull,0x2e627573090a3b36ull,0x3266250920323366ull,
0x35326625202c3635ull,0x3734326625202c32ull,0x662e627573090a3bull,0x3532662509203233ull,
0x3335326625202c37ull,0x3b3834326625202cull,0x33662e6c756d090aull,0x3835326625092032ull,
0x2c3435326625202cull,0x0a3b353532662520ull,0x3233662e6c756d09ull,0x2c39353266250920ull,
0x202c343532662520ull,0x090a3b3635326625ull,0x203233662e6c756dull,0x202c303632662509ull,
0x25202c3435326625ull,0x63090a3b37353266ull,0x662e7461732e7476ull,0x09203233662e3233ull,
0x25202c3136326625ull,0x63090a3b38353266ull,0x662e7461732e7476ull,0x09203233662e3233ull,
0x25202c3236326625ull,0x63090a3b39353266ull,0x662e7461732e7476ull,0x09203233662e3233ull,
0x25202c3336326625ull,0x6d090a3b30363266ull,0x09203233662e766full,0x30202c3436326625ull,
0x3030303866313466ull,0x2f2f092020203b30ull,0x6c756d090a313320ull,0x662509203233662eull,
0x326625202c353632ull,0x36326625202c3136ull,0x2e766f6d090a3b34ull,0x3266250920323366ull,
0x32346630202c3636ull,0x203b303030306337ull,0x3336202f2f092020ull,0x33662e6c756d090aull,
0x3736326625092032ull,0x2c3236326625202cull,0x0a3b363632662520ull,0x3233662e766f6d09ull,
0x2c38363266250920ull,0x3038663134663020ull,0x092020203b303030ull,0x6d090a3133202f2full,
0x09203233662e6c75ull,0x25202c3936326625ull,0x6625202c33363266ull,0x7663090a3b383632ull,
0x33662e696e722e74ull,0x2509203233662e32ull,0x6625202c30373266ull,0x7663090a3b353632ull,
0x33662e696e722e74ull,0x2509203233662e32ull,0x6625202c31373266ull,0x7663090a3b373632ull,
0x33662e696e722e74ull,0x2509203233662e32ull,0x6625202c32373266ull,0x7663090a3b393632ull,
0x33752e697a722e74ull,0x2509203233662e32ull,0x6625202c39323172ull,0x6873090a3b303732ull,
0x2509203233622e6cull,0x7225202c30333172ull,0x3b3131202c393231ull,0x7a722e747663090aull,
0x33662e3233752e69ull,0x3133317225092032ull,0x3b3137326625202cull,0x33622e6c6873090aull,
0x3233317225092032ull,0x2c3133317225202cull,0x2e726f090a3b3520ull,0x3172250920323362ull,
0x33317225202c3333ull,0x3233317225202c30ull,0x722e747663090a3bull,0x662e3233752e697aull,
0x3331722509203233ull,0x3237326625202c34ull,0x33622e726f090a3bull,0x3533317225092032ull,
0x2c3333317225202cull,0x0a3b343331722520ull,0x373109636f6c2e09ull,0x090a300934363209ull,
0x203233662e6c756dull,0x202c333732662509ull,0x25202c3933326625ull,0x6d090a3b35323266ull,
0x09203233662e6c75ull,0x25202c3437326625ull,0x6625202c39333266ull,0x756d090a3b343232ull,
0x2509203233662e6cull,0x6625202c35373266ull,0x326625202c393332ull,0x6c756d090a3b3332ull,
0x662509203233662eull,0x326625202c363732ull,0x34326625202c3034ull,0x2e6c756d090a3b31ull,
0x3266250920323366ull,0x34326625202c3737ull,0x3234326625202c30ull,0x662e6c756d090a3bull,
0x3732662509203233ull,0x3034326625202c38ull,0x3b3334326625202cull,0x33662e627573090aull,
0x3937326625092032ull,0x2c3637326625202cull,0x0a3b333732662520ull,0x3233662e62757309ull,
0x2c30383266250920ull,0x202c373732662520ull,0x090a3b3437326625ull,0x203233662e627573ull,
0x202c313832662509ull,0x25202c3837326625ull,0x6d090a3b35373266ull,0x09203233662e6c75ull,
0x25202c3238326625ull,0x6625202c39373266ull,0x756d090a3b343532ull,0x2509203233662e6cull,
0x6625202c33383266ull,0x326625202c303832ull,0x6c756d090a3b3435ull,0x662509203233662eull,
0x326625202c343832ull,0x35326625202c3138ull,0x2e747663090a3b34ull,0x2e3233662e746173ull,
0x3266250920323366ull,0x38326625202c3538ull,0x2e747663090a3b32ull,0x2e3233662e746173ull,
0x3266250920323366ull,0x38326625202c3638ull,0x2e747663090a3b33ull,0x2e3233662e746173ull,
0x3266250920323366ull,0x38326625202c3738ull,0x2e766f6d090a3b34ull,0x3266250920323366ull,
0x31346630202c3838ull,0x203b303030303866ull,0x3133202f2f092020ull,0x33662e6c756d090aull,
0x3938326625092032ull,0x2c3538326625202cull,0x0a3b383832662520ull,0x3233662e766f6d09ull,
0x2c30393266250920ull,0x3063373234663020ull,0x092020203b303030ull,0x6d090a3336202f2full,
0x09203233662e6c75ull,0x25202c3139326625ull,0x6625202c36383266ull,0x6f6d090a3b303932ull,
0x2509203233662e76ull,0x6630202c32393266ull,0x3030303038663134ull,0x202f2f092020203bull,
0x2e6c756d090a3133ull,0x3266250920323366ull,0x38326625202c3339ull,0x3239326625202c37ull,
0x722e747663090a3bull,0x662e3233662e696eull,0x3932662509203233ull,0x3938326625202c34ull,
0x722e747663090a3bull,0x662e3233662e696eull,0x3932662509203233ull,0x3139326625202c35ull,
0x722e747663090a3bull,0x662e3233662e696eull,0x3932662509203233ull,0x3339326625202c36ull,
0x722e747663090a3bull,0x662e3233752e697aull,0x3331722509203233ull,0x3439326625202c36ull,
0x622e6c6873090a3bull,0x3331722509203233ull,0x3633317225202c37ull,0x63090a3b3131202cull,
0x752e697a722e7476ull,0x09203233662e3233ull,0x25202c3833317225ull,0x73090a3b35393266ull,
0x09203233622e6c68ull,0x25202c3933317225ull,0x3b35202c38333172ull,0x3233622e726f090aull,
0x2c30343172250920ull,0x202c373331722520ull,0x090a3b3933317225ull,0x2e697a722e747663ull,
0x203233662e323375ull,0x202c313431722509ull,0x090a3b3639326625ull,0x09203233622e726full,
0x25202c3234317225ull,0x7225202c30343172ull,0x6c2e090a3b313431ull,0x363209373109636full,
0x766f6d090a300937ull,0x662509203233662eull,0x336630202c373932ull,0x3b31373533343064ull,
0x30202f2f09202020ull,0x353737323233302eull,0x33662e6c756d090aull,0x3839326625092032ull,
0x2c3037326625202cull,0x0a3b373932662520ull,0x3233662e6c756d09ull,0x2c39393266250920ull,
0x202c383932662520ull,0x090a3b3839326625ull,0x203233662e766f6dull,0x202c303033662509ull,
0x3162313863336630ull,0x2f092020203b3931ull,0x383531302e30202full,0x6c756d090a353133ull,
0x662509203233662eull,0x326625202c313033ull,0x30336625202c3137ull,0x2e6c756d090a3b30ull,
0x3366250920323366ull,0x30336625202c3230ull,0x3130336625202c31ull,0x662e766f6d090a3bull,
0x3033662509203233ull,0x3064336630202c33ull,0x20203b3137353334ull,0x302e30202f2f0920ull,
0x090a353737323233ull,0x203233662e6c756dull,0x202c343033662509ull,0x25202c3237326625ull,
0x6d090a3b33303366ull,0x09203233662e6c75ull,0x25202c3530336625ull,0x6625202c34303366ull,
0x6f6d090a3b343033ull,0x2509203233662e76ull,0x6630202c36303366ull,0x3137353334306433ull,
0x202f2f092020203bull,0x3737323233302e30ull,0x662e6c756d090a35ull,0x3033662509203233ull,
0x3439326625202c37ull,0x3b3630336625202cull,0x33662e6c756d090aull,0x3830336625092032ull,
0x2c3730336625202cull,0x0a3b373033662520ull,0x3233662e766f6d09ull,0x2c39303366250920ull,
0x6231386333663020ull,0x092020203b393131ull,0x3531302e30202f2full,0x756d090a35313338ull,
0x2509203233662e6cull,0x6625202c30313366ull,0x336625202c353932ull,0x6c756d090a3b3930ull,
0x662509203233662eull,0x336625202c313133ull,0x31336625202c3031ull,0x2e766f6d090a3b30ull,
0x3366250920323366ull,0x64336630202c3231ull,0x203b313735333430ull,0x2e30202f2f092020ull,
0x0a35373732323330ull,0x3233662e6c756d09ull,0x2c33313366250920ull,0x202c363932662520ull,
0x090a3b3231336625ull,0x203233662e6c756dull,0x202c343133662509ull,0x25202c3331336625ull,
0x6d090a3b33313366ull,0x09203233662e6c75ull,0x25202c3531336625ull,0x6625202c37303366ull,
0x756d090a3b383932ull,0x2509203233662e6cull,0x6625202c36313366ull,0x336625202c303133ull,
0x6c756d090a3b3130ull,0x662509203233662eull,0x336625202c373133ull,0x30336625202c3331ull,
0x2e6c756d090a3b34ull,0x3366250920323366ull,0x39326625202c3831ull,0x3532326625202c38ull,
0x662e6c756d090a3bull,0x3133662509203233ull,0x3130336625202c39ull,0x3b3432326625202cull,
0x33662e6c756d090aull,0x3032336625092032ull,0x2c3430336625202cull,0x0a3b333232662520ull,
0x3233662e6c756d09ull,0x2c31323366250920ull,0x202c313432662520ull,0x090a3b3730336625ull,
0x203233662e6c756dull,0x202c323233662509ull,0x25202c3234326625ull,0x6d090a3b30313366ull,
0x09203233662e6c75ull,0x25202c3332336625ull,0x6625202c33343266ull,0x6c2e090a3b333133ull,
0x353309373109636full,0x6c756d090a300931ull,0x662509203233662eull,0x326625202c343233ull,
0x31336625202c3933ull,0x2e6c756d090a3b36ull,0x3366250920323366ull,0x33326625202c3532ull,
0x3531336625202c39ull,0x662e6c756d090a3bull,0x3233662509203233ull,0x3933326625202c36ull,
0x3b3731336625202cull,0x33662e6c756d090aull,0x3732336625092032ull,0x2c3034326625202cull,
0x0a3b323033662520ull,0x3233662e6c756d09ull,0x2c38323366250920ull,0x202c303432662520ull,
0x090a3b3939326625ull,0x203233662e6c756dull,0x202c393233662509ull,0x25202c3034326625ull,
0x73090a3b35303366ull,0x09203233662e6275ull,0x25202c3033336625ull,0x6625202c34323366ull,
0x7573090a3b393133ull,0x2509203233662e62ull,0x6625202c31333366ull,0x336625202c353233ull,
0x627573090a3b3831ull,0x662509203233662eull,0x336625202c323333ull,0x32336625202c3632ull,
0x2e6c756d090a3b30ull,0x3366250920323366ull,0x34326625202c3333ull,0x3131336625202c35ull,
0x662e6c756d090a3bull,0x3333662509203233ull,0x3534326625202c34ull,0x3b3830336625202cull,
0x33662e6c756d090aull,0x3533336625092032ull,0x2c3534326625202cull,0x0a3b343133662520ull,
0x3233662e62757309ull,0x2c36333366250920ull,0x202c303333662520ull,0x090a3b3232336625ull,
0x203233662e627573ull,0x202c373333662509ull,0x25202c3133336625ull,0x73090a3b31323366ull,
0x09203233662e6275ull,0x25202c3833336625ull,0x6625202c32333366ull,0x6461090a3b333233ull,
0x2509203233662e64ull,0x6625202c39333366ull,0x336625202c373233ull,0x646461090a3b3333ull,
0x662509203233662eull,0x336625202c303433ull,0x33336625202c3832ull,0x2e646461090a3b34ull,
0x3366250920323366ull,0x32336625202c3134ull,0x3533336625202c39ull,0x662e646461090a3bull,
0x3433662509203233ull,0x3633336625202c32ull,0x3b3633336625202cull,0x33662e646461090aull,
0x3334336625092032ull,0x2c3733336625202cull,0x0a3b373333662520ull,0x3233662e64646109ull,
0x2c34343366250920ull,0x202c383333662520ull,0x090a3b3833336625ull,0x203233662e646461ull,
0x202c353433662509ull,0x25202c3933336625ull,0x61090a3b32343366ull,0x09203233662e6464ull,
0x25202c3634336625ull,0x6625202c30343366ull,0x6461090a3b333433ull,0x2509203233662e64ull,
0x6625202c37343366ull,0x336625202c313433ull,0x2e646c090a3b3434ull,0x33662e74736e6f63ull,
0x3834336625092032ull,0x6f6c6f436b5b202cull,0x2b63697274654d72ull,0x6c756d090a3b5d34ull,
0x662509203233662eull,0x336625202c393433ull,0x34336625202c3834ull,0x632e646c090a3b35ull,
0x3233662e74736e6full,0x2c30353366250920ull,0x726f6c6f436b5b20ull,0x302b63697274654dull,
0x2e64616d090a3b5dull,0x3366250920323366ull,0x34336625202c3135ull,0x3035336625202c36ull,
0x3b3934336625202cull,0x6e6f632e646c090aull,0x09203233662e7473ull,0x5b202c3235336625ull,
0x654d726f6c6f436bull,0x3b5d382b63697274ull,0x33662e64616d090aull,0x3335336625092032ull,
0x2c3734336625202cull,0x202c323533662520ull,0x090a3b3135336625ull,0x203233662e766f6dull,
0x202c343533662509ull,0x6538336564336630ull,0x2f092020203b3933ull,0x313131312e30202full,
0x2e6c756d090a3131ull,0x3366250920323366ull,0x35336625202c3535ull,0x3435336625202c33ull,
0x2e70746573090a3bull,0x09203233662e746cull,0x6625202c33317025ull,0x326625202c353533ull,
0x252140090a3b3232ull,0x2061726220333170ull,0x355f305f744c2409ull,0x2f200a3b30373931ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3520656e696c2079ull,
0x64616568202c3632ull,0x64656c6562616c20ull,0x355f305f744c2420ull,0x6c2e090a38373130ull,
0x353309373109636full,0x766f6d090a300935ull,0x662509203233662eull,0x336625202c323232ull,
0x6f6c2e090a3b3535ull,0x3635330937310963ull,0x2e766f6d090a3009ull,0x3172250920323373ull,
0x31317225202c3334ull,0x636f6c2e090a3b37ull,0x0937353309373109ull,0x752e747663090a30ull,
0x09203233752e3631ull,0x7225202c32687225ull,0x6c2e090a3b353331ull,0x353309373109636full,
0x747663090a300938ull,0x3233752e3631752eull,0x202c336872250920ull,0x240a3b3234317225ull,
0x3931355f305f744cull,0x3c2f2f200a3a3037ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x36323520656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3130355f305f744cull,0x636f6c2e090a3837ull,0x0932343309373109ull,0x732e646461090a30ull,
0x3131722509203233ull,0x3331317225202c33ull,0x6d090a3b3436202cull,0x09203233752e766full,
0x31202c3434317225ull,0x6573090a3b343230ull,0x33732e656e2e7074ull,0x2c34317025092032ull,
0x202c333131722520ull,0x090a3b3434317225ull,0x7262203431702540ull,0x305f744c24092061ull,
0x0a3b38373130355full,0x35325f305f744c24ull,0x636f6c2e090a3a38ull,0x0930363309373109ull,
0x752e747663090a30ull,0x09203631752e3233ull,0x25202c3534317225ull,0x7663090a3b336872ull,
0x31752e3233752e74ull,0x3634317225092036ull,0x0a3b32687225202cull,0x656c2e7074657309ull,
0x702509203233752eull,0x34317225202c3531ull,0x3634317225202c35ull,0x3531702540090a3bull,
0x4c24092061726220ull,0x333732355f305f74ull,0x636f6c2e090a3b38ull,0x3009323709373109ull,
0x33732e766f6d090aull,0x3734317225092032ull,0x3b3534317225202cull,0x3109636f6c2e090aull,
0x090a300933370937ull,0x203233732e766f6dull,0x202c353431722509ull,0x090a3b3634317225ull,
0x09373109636f6c2eull,0x6f6d090a30093437ull,0x2509203233732e76ull,0x7225202c36343172ull,
0x6c2e090a3b373431ull,0x363309373109636full,0x766f6d090a300935ull,0x722509203233732eull,
0x317225202c383431ull,0x726f78090a3b3334ull,0x722509203233622eull,0x317225202c393431ull,
0x31333431202c3834ull,0x0a3b353637353536ull,0x3233732e766f6d09ull,0x2c33343172250920ull,
0x0a3b393431722520ull,0x32355f305f744c24ull,0x6f6d090a3a383337ull,0x2509203233732e76ull,
0x3b30202c30353172ull,0x36752e766f6d090aull,0x3838647225092034ull,0x3373646f7270202cull,
0x752e766f6d090a3bull,0x3864722509203436ull,0x6168706c61202c39ull,0x0a3b33656c626154ull,
0x33355f305f744c24ull,0x2f2f200a3a323637ull,0x4c203e706f6f6c3cull,0x79646f6220706f6full,
0x363320656e696c20ull,0x697473656e202c35ull,0x687470656420676eull,0x747365202c31203aull,
0x6920646574616d69ull,0x6e6f697461726574ull,0x6c2e090a33203a73ull,0x373309373109636full,
0x6c756d090a300931ull,0x203233732e6f6c2eull,0x202c313531722509ull,0x36202c3035317225ull,
0x2e646461090a3b34ull,0x3172250920323373ull,0x35317225202c3235ull,0x0a3b317225202c31ull,
0x3233752e766f6d09ull,0x2c33353172250920ull,0x73090a3b39353120ull,0x732e74672e707465ull,
0x3631702509203233ull,0x2c3235317225202cull,0x0a3b333531722520ull,0x6220363170254009ull,
0x5f744c2409206172ull,0x200a3b3431355f30ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c353633ull,0x656c6562616c2064ull,
0x5f305f744c242064ull,0x2e090a3236373335ull,0x3309373109636f6cull,0x7663090a30093437ull,
0x33732e3436732e74ull,0x3039647225092032ull,0x3b3235317225202cull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c313964ull,0x090a3b34202c3039ull,0x203436752e646461ull,
0x202c323964722509ull,0x25202c3637647225ull,0x6c090a3b31396472ull,0x6465726168732e64ull,
0x722509203233752eull,0x72255b202c343531ull,0x0a3b5d302b323964ull,0x373109636f6c2e09ull,
0x090a300935373309ull,0x203233732e766f6dull,0x202c353531722509ull,0x2e766f6d090a3b30ull,
0x6472250920343673ull,0x31647225202c3339ull,0x732e766f6d090a3bull,0x3531722509203233ull,
0x6d090a3b30202c36ull,0x09203233662e766full,0x30202c3635336625ull,0x3030303030303066ull,
0x2f2f092020203b30ull,0x2e766f6d090a3020ull,0x3366250920323366ull,0x30306630202c3735ull,
0x203b303030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,0x2c38353366250920ull,
0x3030303030663020ull,0x092020203b303030ull,0x744c240a30202f2full,0x30333534355f305full,
0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,0x202c35373320656eull,
0x20676e697473656eull,0x31203a6874706564ull,0x746172657469202cull,0x3631203a736e6f69ull,
0x3109636f6c2e090aull,0x0a30093437330937ull,0x726168732e646c09ull,0x09203233752e6465ull,
0x5b202c3435317225ull,0x5d302b3239647225ull,0x09636f6c2e090a3bull,0x3009353832093731ull,
0x33752e726873090aull,0x3735317225092032ull,0x2c3435317225202cull,0x0a3b353531722520ull,
0x3233622e646e6109ull,0x2c38353172250920ull,0x202c373531722520ull,0x2e747663090a3b33ull,
0x203233752e343675ull,0x202c343964722509ull,0x090a3b3835317225ull,0x752e6f6c2e6c756dull,
0x3964722509203436ull,0x3439647225202c35ull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x7225202c36396472ull,0x647225202c353964ull,0x2e646c090a3b3938ull,0x33662e74736e6f63ull,
0x3935336625092032ull,0x36396472255b202cull,0x646c090a3b5d302bull,0x2e6465726168732eull,
0x3366250920323366ull,0x6472255b202c3036ull,0x090a3b5d302b3339ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c31363366ull,0x3b5d342b33396472ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c323633662509ull,0x382b33396472255bull,0x2e64616d090a3b5dull,
0x3366250920323366ull,0x35336625202c3835ull,0x3036336625202c39ull,0x3b3835336625202cull,
0x33662e64616d090aull,0x3735336625092032ull,0x2c3935336625202cull,0x202c313633662520ull,
0x090a3b3735336625ull,0x203233662e64616dull,0x202c363533662509ull,0x25202c3935336625ull,
0x6625202c32363366ull,0x6c2e090a3b363533ull,0x383209373109636full,0x646461090a300936ull,
0x722509203436752eull,0x647225202c373964ull,0x38647225202c3539ull,0x632e646c090a3b38ull,
0x3233732e74736e6full,0x2c39353172250920ull,0x2b37396472255b20ull,0x646461090a3b5d30ull,
0x722509203233732eull,0x317225202c363531ull,0x35317225202c3935ull,0x2e646461090a3b36ull,
0x6472250920343675ull,0x39647225202c3339ull,0x090a3b3231202c33ull,0x203233732e646461ull,
0x202c353531722509ull,0x32202c3535317225ull,0x752e766f6d090a3bull,0x3631722509203233ull,
0x090a3b3233202c30ull,0x2e656e2e70746573ull,0x3170250920323373ull,0x3535317225202c37ull,
0x3b3036317225202cull,0x203731702540090aull,0x744c240920617262ull,0x30333534355f305full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c35363320656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x32363733355f305full,
0x3109636f6c2e090aull,0x0a30093332330937ull,0x3233622e646e6109ull,0x2c31363172250920ull,
0x202c363531722520ull,0x6873090a3b353532ull,0x2509203233732e72ull,0x7225202c32363172ull,
0x3b3631202c363531ull,0x33732e726873090aull,0x3336317225092032ull,0x2c3635317225202cull,
0x2e646c090a3b3820ull,0x662e646572616873ull,0x3633662509203233ull,0x75635f5f5b202c33ull,
0x31736d75735f6164ull,0x0a3b5d302b303635ull,0x3233662e766f6d09ull,0x2c34363366250920ull,
0x3030383034663020ull,0x092020203b303030ull,0x756d090a34202f2full,0x2509203233662e6cull,
0x6625202c35363366ull,0x336625202c333633ull,0x2e646c090a3b3436ull,0x662e646572616873ull,
0x3633662509203233ull,0x75635f5f5b202c36ull,0x31736d75735f6164ull,0x0a3b5d342b303635ull,
0x3233662e766f6d09ull,0x2c37363366250920ull,0x3030383034663020ull,0x092020203b303030ull,
0x756d090a34202f2full,0x2509203233662e6cull,0x6625202c38363366ull,0x336625202c363633ull,
0x2e646c090a3b3736ull,0x662e646572616873ull,0x3633662509203233ull,0x75635f5f5b202c39ull,
0x31736d75735f6164ull,0x0a3b5d382b303635ull,0x3233662e766f6d09ull,0x2c30373366250920ull,
0x3030383034663020ull,0x092020203b303030ull,0x756d090a34202f2full,0x2509203233662e6cull,
0x6625202c31373366ull,0x336625202c393633ull,0x747663090a3b3037ull,0x2e3233662e6e722eull,
0x3366250920323373ull,0x36317225202c3237ull,0x2e747663090a3b31ull,0x732e3233662e6e72ull,
0x3733662509203233ull,0x3236317225202c33ull,0x622e646e61090a3bull,0x3631722509203233ull,
0x3336317225202c34ull,0x090a3b353532202cull,0x203233662e627573ull,0x202c343733662509ull,
0x25202c3536336625ull,0x73090a3b38353366ull,0x09203233662e6275ull,0x25202c3537336625ull,
0x6625202c38363366ull,0x7573090a3b373533ull,0x2509203233662e62ull,0x6625202c36373366ull,
0x336625202c313733ull,0x6c756d090a3b3635ull,0x662509203233662eull,0x336625202c373733ull,
0x37336625202c3237ull,0x2e747663090a3b32ull,0x732e3233662e6e72ull,0x3733662509203233ull,
0x3436317225202c38ull,0x662e6c756d090a3bull,0x3733662509203233ull,0x3237336625202c39ull,
0x3b3437336625202cull,0x33662e6c756d090aull,0x3038336625092032ull,0x2c3237336625202cull,
0x0a3b353733662520ull,0x3233662e6c756d09ull,0x2c31383366250920ull,0x202c323733662520ull,
0x090a3b3637336625ull,0x203233662e6c756dull,0x202c323833662509ull,0x25202c3337336625ull,
0x73090a3b38373366ull,0x09203233662e6275ull,0x25202c3338336625ull,0x6625202c32383366ull,
0x756d090a3b373733ull,0x2509203233662e6cull,0x6625202c34383366ull,0x336625202c383733ull,
0x6c756d090a3b3835ull,0x662509203233662eull,0x336625202c353833ull,0x35336625202c3837ull,
0x2e6c756d090a3b37ull,0x3366250920323366ull,0x37336625202c3638ull,0x3635336625202c38ull,
0x612e706372090a3bull,0x33662e786f727070ull,0x3738336625092032ull,0x3b3338336625202cull,
0x33662e627573090aull,0x3838336625092032ull,0x2c3438336625202cull,0x0a3b393733662520ull,
0x3233662e62757309ull,0x2c39383366250920ull,0x202c353833662520ull,0x090a3b3038336625ull,
0x203233662e627573ull,0x202c303933662509ull,0x25202c3638336625ull,0x6d090a3b31383366ull,
0x09203233662e6c75ull,0x25202c3139336625ull,0x6625202c37383366ull,0x756d090a3b383833ull,
0x2509203233662e6cull,0x6625202c32393366ull,0x336625202c373833ull,0x6c756d090a3b3938ull,
0x662509203233662eull,0x336625202c333933ull,0x39336625202c3738ull,0x2e747663090a3b30ull,
0x2e3233662e746173ull,0x3366250920323366ull,0x39336625202c3439ull,0x2e747663090a3b31ull,
0x2e3233662e746173ull,0x3366250920323366ull,0x39336625202c3539ull,0x2e747663090a3b32ull,
0x2e3233662e746173ull,0x3366250920323366ull,0x39336625202c3639ull,0x2e766f6d090a3b33ull,
0x3366250920323366ull,0x31346630202c3739ull,0x203b303030303866ull,0x3133202f2f092020ull,
0x33662e6c756d090aull,0x3839336625092032ull,0x2c3439336625202cull,0x0a3b373933662520ull,
0x3233662e766f6d09ull,0x2c39393366250920ull,0x3063373234663020ull,0x092020203b303030ull,
0x6d090a3336202f2full,0x09203233662e6c75ull,0x25202c3030346625ull,0x6625202c35393366ull,
0x6f6d090a3b393933ull,0x2509203233662e76ull,0x6630202c31303466ull,0x3030303038663134ull,
0x202f2f092020203bull,0x2e6c756d090a3133ull,0x3466250920323366ull,0x39336625202c3230ull,
0x3130346625202c36ull,0x722e747663090a3bull,0x662e3233662e696eull,0x3034662509203233ull,
0x3839336625202c33ull,0x722e747663090a3bull,0x662e3233662e696eull,0x3034662509203233ull,
0x3030346625202c34ull,0x722e747663090a3bull,0x662e3233662e696eull,0x3034662509203233ull,
0x3230346625202c35ull,0x722e747663090a3bull,0x662e3233752e697aull,0x3631722509203233ull,
0x3330346625202c35ull,0x622e6c6873090a3bull,0x3631722509203233ull,0x3536317225202c36ull,
0x63090a3b3131202cull,0x752e697a722e7476ull,0x09203233662e3233ull,0x25202c3736317225ull,
0x73090a3b34303466ull,0x09203233622e6c68ull,0x25202c3836317225ull,0x3b35202c37363172ull,
0x3233622e726f090aull,0x2c39363172250920ull,0x202c363631722520ull,0x090a3b3836317225ull,
0x2e697a722e747663ull,0x203233662e323375ull,0x202c303731722509ull,0x090a3b3530346625ull,
0x09203233622e726full,0x25202c3137317225ull,0x7225202c39363172ull,0x7663090a3b303731ull,
0x33752e3631752e74ull,0x3237317225092032ull,0x3b3137317225202cull,0x3109636f6c2e090aull,
0x0a30093432330937ull,0x3233662e6c756d09ull,0x2c36303466250920ull,0x202c323733662520ull,
0x090a3b3835336625ull,0x203233662e6c756dull,0x202c373034662509ull,0x25202c3237336625ull,
0x6d090a3b37353366ull,0x09203233662e6c75ull,0x25202c3830346625ull,0x6625202c32373366ull,
0x756d090a3b363533ull,0x2509203233662e6cull,0x6625202c39303466ull,0x336625202c333733ull,
0x6c756d090a3b3437ull,0x662509203233662eull,0x336625202c303134ull,0x37336625202c3337ull,
0x2e6c756d090a3b35ull,0x3466250920323366ull,0x37336625202c3131ull,0x3637336625202c33ull,
0x662e627573090a3bull,0x3134662509203233ull,0x3930346625202c32ull,0x3b3630346625202cull,
0x33662e627573090aull,0x3331346625092032ull,0x2c3031346625202cull,0x0a3b373034662520ull,
0x3233662e62757309ull,0x2c34313466250920ull,0x202c313134662520ull,0x090a3b3830346625ull,
0x203233662e6c756dull,0x202c353134662509ull,0x25202c3231346625ull,0x6d090a3b37383366ull,
0x09203233662e6c75ull,0x25202c3631346625ull,0x6625202c33313466ull,0x756d090a3b373833ull,
0x2509203233662e6cull,0x6625202c37313466ull,0x336625202c343134ull,0x747663090a3b3738ull,
0x3233662e7461732eull,0x662509203233662eull,0x346625202c383134ull,0x747663090a3b3531ull,
0x3233662e7461732eull,0x662509203233662eull,0x346625202c393134ull,0x747663090a3b3631ull,
0x3233662e7461732eull,0x662509203233662eull,0x346625202c303234ull,0x766f6d090a3b3731ull,
0x662509203233662eull,0x346630202c313234ull,0x3b30303030386631ull,0x33202f2f09202020ull,
0x662e6c756d090a31ull,0x3234662509203233ull,0x3831346625202c32ull,0x3b3132346625202cull,
0x33662e766f6d090aull,0x3332346625092032ull,0x633732346630202cull,0x2020203b30303030ull,
0x090a3336202f2f09ull,0x203233662e6c756dull,0x202c343234662509ull,0x25202c3931346625ull,
0x6d090a3b33323466ull,0x09203233662e766full,0x30202c3532346625ull,0x3030303866313466ull,
0x2f2f092020203b30ull,0x6c756d090a313320ull,0x662509203233662eull,0x346625202c363234ull,
0x32346625202c3032ull,0x2e747663090a3b35ull,0x2e3233662e696e72ull,0x3466250920323366ull,
0x32346625202c3732ull,0x2e747663090a3b32ull,0x2e3233662e696e72ull,0x3466250920323366ull,
0x32346625202c3832ull,0x2e747663090a3b34ull,0x2e3233662e696e72ull,0x3466250920323366ull,
0x32346625202c3932ull,0x2e747663090a3b36ull,0x2e3233752e697a72ull,0x3172250920323366ull,
0x32346625202c3337ull,0x2e6c6873090a3b37ull,0x3172250920323362ull,0x37317225202c3437ull,
0x090a3b3131202c33ull,0x2e697a722e747663ull,0x203233662e323375ull,0x202c353731722509ull,
0x090a3b3832346625ull,0x203233622e6c6873ull,0x202c363731722509ull,0x35202c3537317225ull,
0x33622e726f090a3bull,0x3737317225092032ull,0x2c3437317225202cull,0x0a3b363731722520ull,
0x697a722e74766309ull,0x3233662e3233752eull,0x2c38373172250920ull,0x0a3b393234662520ull,
0x203233622e726f09ull,0x202c393731722509ull,0x25202c3737317225ull,0x63090a3b38373172ull,
0x752e3631752e7476ull,0x3831722509203233ull,0x3937317225202c30ull,0x09636f6c2e090a3bull,
0x3009373233093731ull,0x33662e766f6d090aull,0x3033346625092032ull,0x343064336630202cull,
0x2020203b31373533ull,0x33302e30202f2f09ull,0x6d090a3537373232ull,0x09203233662e6c75ull,
0x25202c3133346625ull,0x6625202c33303466ull,0x756d090a3b303334ull,0x2509203233662e6cull,
0x6625202c32333466ull,0x346625202c313334ull,0x766f6d090a3b3133ull,0x662509203233662eull,
0x336630202c333334ull,0x3b39313162313863ull,0x30202f2f09202020ull,0x353133383531302eull,
0x33662e6c756d090aull,0x3433346625092032ull,0x2c3430346625202cull,0x0a3b333334662520ull,
0x3233662e6c756d09ull,0x2c35333466250920ull,0x202c343334662520ull,0x090a3b3433346625ull,
0x203233662e766f6dull,0x202c363334662509ull,0x3533343064336630ull,0x2f092020203b3137ull,
0x323233302e30202full,0x6c756d090a353737ull,0x662509203233662eull,0x346625202c373334ull,
0x33346625202c3530ull,0x2e6c756d090a3b36ull,0x3466250920323366ull,0x33346625202c3833ull,
0x3733346625202c37ull,0x662e766f6d090a3bull,0x3334662509203233ull,0x3064336630202c39ull,
0x20203b3137353334ull,0x302e30202f2f0920ull,0x090a353737323233ull,0x203233662e6c756dull,
0x202c303434662509ull,0x25202c3732346625ull,0x6d090a3b39333466ull,0x09203233662e6c75ull,
0x25202c3134346625ull,0x6625202c30343466ull,0x6f6d090a3b303434ull,0x2509203233662e76ull,
0x6630202c32343466ull,0x3931316231386333ull,0x202f2f092020203bull,0x3133383531302e30ull,
0x662e6c756d090a35ull,0x3434662509203233ull,0x3832346625202c33ull,0x3b3234346625202cull,
0x33662e6c756d090aull,0x3434346625092032ull,0x2c3334346625202cull,0x0a3b333434662520ull,
0x3233662e766f6d09ull,0x2c35343466250920ull,0x3334306433663020ull,0x092020203b313735ull,
0x3233302e30202f2full,0x756d090a35373732ull,0x2509203233662e6cull,0x6625202c36343466ull,
0x346625202c393234ull,0x6c756d090a3b3534ull,0x662509203233662eull,0x346625202c373434ull,
0x34346625202c3634ull,0x2e6c756d090a3b36ull,0x3466250920323366ull,0x34346625202c3834ull,
0x3133346625202c30ull,0x662e6c756d090a3bull,0x3434662509203233ull,0x3334346625202c39ull,
0x3b3433346625202cull,0x33662e6c756d090aull,0x3035346625092032ull,0x2c3634346625202cull,
0x0a3b373334662520ull,0x3233662e6c756d09ull,0x2c31353466250920ull,0x202c313334662520ull,
0x090a3b3835336625ull,0x203233662e6c756dull,0x202c323534662509ull,0x25202c3433346625ull,
0x6d090a3b37353366ull,0x09203233662e6c75ull,0x25202c3335346625ull,0x6625202c37333466ull,
0x756d090a3b363533ull,0x2509203233662e6cull,0x6625202c34353466ull,0x346625202c343733ull,
0x6c756d090a3b3034ull,0x662509203233662eull,0x336625202c353534ull,0x34346625202c3537ull,
0x2e6c756d090a3b33ull,0x3466250920323366ull,0x37336625202c3635ull,0x3634346625202c36ull,
0x09636f6c2e090a3bull,0x3009353733093731ull,0x33662e6c756d090aull,0x3735346625092032ull,
0x2c3237336625202cull,0x0a3b393434662520ull,0x3233662e6c756d09ull,0x2c38353466250920ull,
0x202c323733662520ull,0x090a3b3834346625ull,0x203233662e6c756dull,0x202c393534662509ull,
0x25202c3237336625ull,0x6d090a3b30353466ull,0x09203233662e6c75ull,0x25202c3036346625ull,
0x6625202c33373366ull,0x756d090a3b353334ull,0x2509203233662e6cull,0x6625202c31363466ull,
0x346625202c333733ull,0x6c756d090a3b3233ull,0x662509203233662eull,0x336625202c323634ull,
0x33346625202c3337ull,0x2e627573090a3b38ull,0x3466250920323366ull,0x35346625202c3336ull,
0x3235346625202c37ull,0x662e627573090a3bull,0x3634662509203233ull,0x3835346625202c34ull,
0x3b3135346625202cull,0x33662e627573090aull,0x3536346625092032ull,0x2c3935346625202cull,
0x0a3b333534662520ull,0x3233662e6c756d09ull,0x2c36363466250920ull,0x202c383733662520ull,
0x090a3b3434346625ull,0x203233662e6c756dull,0x202c373634662509ull,0x25202c3837336625ull,
0x6d090a3b31343466ull,0x09203233662e6c75ull,0x25202c3836346625ull,0x6625202c38373366ull,
0x7573090a3b373434ull,0x2509203233662e62ull,0x6625202c39363466ull,0x346625202c333634ull,
0x627573090a3b3535ull,0x662509203233662eull,0x346625202c303734ull,0x35346625202c3436ull,
0x2e627573090a3b34ull,0x3466250920323366ull,0x36346625202c3137ull,0x3635346625202c35ull,
0x662e646461090a3bull,0x3734662509203233ull,0x3036346625202c32ull,0x3b3636346625202cull,
0x33662e646461090aull,0x3337346625092032ull,0x2c3136346625202cull,0x0a3b373634662520ull,
0x3233662e64646109ull,0x2c34373466250920ull,0x202c323634662520ull,0x090a3b3836346625ull,
0x203233662e646461ull,0x202c353734662509ull,0x25202c3936346625ull,0x61090a3b39363466ull,
0x09203233662e6464ull,0x25202c3637346625ull,0x6625202c30373466ull,0x6461090a3b303734ull,
0x2509203233662e64ull,0x6625202c37373466ull,0x346625202c313734ull,0x646461090a3b3137ull,
0x662509203233662eull,0x346625202c383734ull,0x37346625202c3237ull,0x2e646461090a3b35ull,
0x3466250920323366ull,0x37346625202c3937ull,0x3637346625202c33ull,0x662e646461090a3bull,
0x3834662509203233ull,0x3437346625202c30ull,0x3b3737346625202cull,0x6e6f632e646c090aull,
0x09203233662e7473ull,0x5b202c3138346625ull,0x654d726f6c6f436bull,0x3b5d342b63697274ull,
0x33662e6c756d090aull,0x3238346625092032ull,0x2c3138346625202cull,0x0a3b383734662520ull,
0x736e6f632e646c09ull,0x2509203233662e74ull,0x6b5b202c33383466ull,0x74654d726f6c6f43ull,
0x0a3b5d302b636972ull,0x3233662e64616d09ull,0x2c34383466250920ull,0x202c393734662520ull,
0x25202c3338346625ull,0x6c090a3b32383466ull,0x2e74736e6f632e64ull,0x3466250920323366ull,
0x6f436b5b202c3538ull,0x697274654d726f6cull,0x6d090a3b5d382b63ull,0x09203233662e6461ull,
0x25202c3638346625ull,0x6625202c30383466ull,0x346625202c353834ull,0x766f6d090a3b3438ull,
0x662509203233662eull,0x336630202c373834ull,0x3b30303030303865ull,0x30202f2f09202020ull,
0x6c756d090a35322eull,0x662509203233662eull,0x346625202c383834ull,0x38346625202c3638ull,
0x70746573090a3b37ull,0x203233662e746c2eull,0x25202c3831702509ull,0x6625202c38383466ull,
0x2140090a3b323232ull,0x6172622038317025ull,0x5f305f744c240920ull,0x200a3b3435353535ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c353633ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x2e090a3236373335ull,
0x3309373109636f6cull,0x6f6d090a30093937ull,0x2509203233662e76ull,0x6625202c32323266ull,
0x6c2e090a3b383834ull,0x373309373109636full,0x2e646c090a300934ull,0x752e646572616873ull,
0x3531722509203233ull,0x396472255b202c34ull,0x2e090a3b5d302b32ull,0x3309373109636f6cull,
0x6f6d090a30093038ull,0x2509203233732e76ull,0x7225202c31383172ull,0x6c2e090a3b343531ull,
0x383309373109636full,0x766f6d090a300931ull,0x722509203233732eull,0x317225202c363431ull,
0x6f6c2e090a3b3237ull,0x3238330937310963ull,0x2e766f6d090a3009ull,0x3172250920323373ull,
0x38317225202c3534ull,0x70746573090a3b30ull,0x203233752e656c2eull,0x25202c3931702509ull,
0x7225202c32373172ull,0x2540090a3b303831ull,0x2061726220393170ull,0x355f305f744c2409ull,
0x2f200a3b30313835ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3320656e696c2079ull,0x64616568202c3536ull,0x64656c6562616c20ull,0x355f305f744c2420ull,
0x6c2e090a32363733ull,0x323709373109636full,0x2e766f6d090a3009ull,0x3172250920323373ull,
0x34317225202c3238ull,0x636f6c2e090a3b35ull,0x3009333709373109ull,0x33732e766f6d090aull,
0x3534317225092032ull,0x3b3634317225202cull,0x3109636f6c2e090aull,0x090a300934370937ull,
0x203233732e766f6dull,0x202c363431722509ull,0x090a3b3238317225ull,0x09373109636f6c2eull,
0x6c090a3009343733ull,0x6465726168732e64ull,0x722509203233752eull,0x72255b202c343531ull,
0x0a3b5d302b323964ull,0x373109636f6c2e09ull,0x090a300937383309ull,0x203233622e746f6eull,
0x202c333831722509ull,0x090a3b3435317225ull,0x203233752e726873ull,0x202c343831722509ull,
0x31202c3338317225ull,0x622e646e61090a3bull,0x3831722509203233ull,0x3438317225202c35ull,
0x353631333431202cull,0x78090a3b35363735ull,0x09203233622e726full,0x25202c3638317225ull,
0x7225202c34353172ull,0x6f6d090a3b353831ull,0x2509203233732e76ull,0x7225202c33343172ull,
0x7262090a3b363831ull,0x240920696e752e61ull,0x3535355f305f744cull,0x5f744c240a3b3435ull,
0x3a30313835355f30ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3536332065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a32363733355f30ull,0x3233732e766f6d09ull,0x2c33343172250920ull,0x0a3b313831722520ull,
0x35355f305f744c24ull,0x744c240a3a343535ull,0x32343035355f305full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35363320656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x32363733355f305full,0x3109636f6c2e090aull,
0x0a30093836330937ull,0x3233732e64646109ull,0x2c30353172250920ull,0x202c303531722520ull,
0x2e766f6d090a3b31ull,0x3172250920323375ull,0x090a3b33202c3738ull,0x2e656e2e70746573ull,
0x3270250920323373ull,0x3035317225202c30ull,0x3b3738317225202cull,0x203032702540090aull,
0x744c240920617262ull,0x32363733355f305full,0x5f305f744c240a3bull,0x6c2e090a3a343135ull,
0x393309373109636full,0x766f6d090a300930ull,0x722509203436752eull,0x635f5f202c383964ull,
0x6f7272655f616475ull,0x0a3b363138317372ull,0x3436752e766f6d09ull,0x2c39396472250920ull,
0x73656369646e6920ull,0x6c2e090a3b315f5full,0x393309373109636full,0x646461090a300932ull,
0x722509203436752eull,0x7225202c30303164ull,0x647225202c303764ull,0x2e7473090a3b3839ull,
0x662e646572616873ull,0x6472255b09203233ull,0x202c5d302b303031ull,0x090a3b3232326625ull,
0x09373109636f6c2eull,0x61090a3009343034ull,0x09203436752e6464ull,0x202c313031647225ull,
0x25202c3835647225ull,0x73090a3b39396472ull,0x6465726168732e74ull,0x255b09203233732eull,
0x5d302b3130316472ull,0x090a3b317225202cull,0x203233732e766f6dull,0x202c383831722509ull,
0x5f744c240a3b3233ull,0x3a34333836355f30ull,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,
0x6e696c2079646f62ull,0x6e202c3430342065ull,0x6420676e69747365ull,0x2c31203a68747065ull,
0x74616d6974736520ull,0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,
0x09373109636f6c2eull,0x62090a3009393034ull,0x20636e79732e7261ull,0x746573090a3b3009ull,
0x3233732e656c2e70ull,0x202c313270250920ull,0x25202c3838317225ull,0x702540090a3b3172ull,
0x0920617262203132ull,0x37355f305f744c24ull,0x2f2f200a3b323036ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x303420656e696c20ull,0x2064616568202c34ull,
0x2064656c6562616cull,0x36355f305f744c24ull,0x6f6c2e090a343338ull,0x3331340937310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x3938346625092032ull,0x30316472255b202cull,
0x2e090a3b5d302b30ull,0x3409373109636f6cull,0x6461090a30093431ull,0x2509203233732e64ull,
0x7225202c39383172ull,0x317225202c383831ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,
0x7225202c30393172ull,0x0a3b34202c393831ull,0x3436752e74766309ull,0x722509203233752eull,
0x7225202c32303164ull,0x6461090a3b303931ull,0x2509203436752e64ull,0x25202c3330316472ull,
0x25202c3230316472ull,0x6c090a3b38396472ull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c303934ull,0x3b5d302b33303164ull,0x672e70746573090aull,0x2509203233662e74ull,
0x346625202c323270ull,0x39346625202c3938ull,0x70252140090a3b30ull,0x0920617262203232ull,
0x37355f305f744c24ull,0x2f2f200a3b323036ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x303420656e696c20ull,0x2064616568202c34ull,0x2064656c6562616cull,
0x36355f305f744c24ull,0x6f6c2e090a343338ull,0x3731340937310963ull,0x732e7473090a3009ull,
0x33662e6465726168ull,0x316472255b092032ull,0x25202c5d302b3030ull,0x2e090a3b30393466ull,
0x3409373109636f6cull,0x7663090a30093831ull,0x33732e3436732e74ull,0x3031647225092032ull,
0x3938317225202c34ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x25202c3530316472ull,
0x34202c3430316472ull,0x752e646461090a3bull,0x3164722509203436ull,0x39647225202c3630ull,
0x3031647225202c39ull,0x732e646c090a3b35ull,0x33732e6465726168ull,0x3139317225092032ull,
0x30316472255b202cull,0x73090a3b5d302b36ull,0x6465726168732e74ull,0x255b09203233732eull,
0x5d302b3130316472ull,0x3b3139317225202cull,0x355f305f744c240aull,0x4c240a3a32303637ull,
0x393037355f305f74ull,0x6c3c2f2f200a3a30ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c34303420656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x333836355f305f74ull,0x09636f6c2e090a34ull,0x3009373034093731ull,0x33732e726873090aull,
0x3838317225092032ull,0x2c3838317225202cull,0x766f6d090a3b3120ull,0x722509203233752eull,
0x0a3b30202c323931ull,0x74672e7074657309ull,0x702509203233732eull,0x38317225202c3332ull,
0x3239317225202c38ull,0x3332702540090a3bull,0x4c24092061726220ull,0x333836355f305f74ull,
0x636f6c2e090a3b34ull,0x0932373409373109ull,0x732e726162090a30ull,0x0a3b300920636e79ull,
0x726168732e646c09ull,0x09203233732e6465ull,0x5b202c3339317225ull,0x5f73656369646e69ull,
0x090a3b5d302b315full,0x09373109636f6c2eull,0x62090a3009313335ull,0x20636e79732e7261ull,
0x746573090a3b3009ull,0x3233732e656e2e70ull,0x202c343270250920ull,0x25202c3339317225ull,
0x702540090a3b3172ull,0x0920617262203432ull,0x38355f305f744c24ull,0x6c2e090a3b303733ull,
0x393409373109636full,0x746573090a300935ull,0x3233752e71652e70ull,0x202c353270250920ull,
0x25202c3534317225ull,0x6d090a3b36343172ull,0x09203233752e766full,0x30202c3439317225ull,
0x732e766f6d090a3bull,0x3931722509203233ull,0x3334317225202c35ull,0x2e706c6573090a3bull,
0x3172250920323375ull,0x39317225202c3639ull,0x3539317225202c34ull,0x0a3b35327025202cull,
0x726168732e646c09ull,0x09203233732e6465ull,0x5b202c3739317225ull,0x785f616475635f5full,
0x3235373173666572ull,0x756d090a3b5d302bull,0x3233732e6f6c2e6cull,0x2c38393172250920ull,
0x202c373931722520ull,0x2e726873090a3b32ull,0x3172250920323375ull,0x39317225202c3939ull,
0x3839317225202c36ull,0x622e646e61090a3bull,0x3032722509203233ull,0x3939317225202c30ull,
0x646c090a3b33202cull,0x2e6465726168732eull,0x3272250920323373ull,0x635f5f5b202c3130ull,
0x666572785f616475ull,0x5d342b3235373173ull,0x6c2e6c756d090a3bull,0x2509203233732e6full,
0x7225202c32303272ull,0x0a3b32202c313032ull,0x3233752e72687309ull,0x2c33303272250920ull,
0x202c363931722520ull,0x090a3b3230327225ull,0x203233622e646e61ull,0x202c343032722509ull,
0x33202c3330327225ull,0x622e6c6873090a3bull,0x3032722509203233ull,0x3430327225202c35ull,
0x726f090a3b32202cull,0x722509203233622eull,0x327225202c363032ull,0x30327225202c3030ull,
0x732e646c090a3b35ull,0x33732e6465726168ull,0x3730327225092032ull,0x6475635f5f5b202cull,
0x3173666572785f61ull,0x0a3b5d382b323537ull,0x2e6f6c2e6c756d09ull,0x3272250920323373ull,
0x30327225202c3830ull,0x73090a3b32202c37ull,0x09203233752e7268ull,0x25202c3930327225ull,
0x7225202c36393172ull,0x6e61090a3b383032ull,0x2509203233622e64ull,0x7225202c30313272ull,
0x0a3b33202c393032ull,0x3233622e6c687309ull,0x2c31313272250920ull,0x202c303132722520ull,
0x732e646c090a3b34ull,0x33732e6465726168ull,0x3231327225092032ull,0x6475635f5f5b202cull,
0x3173666572785f61ull,0x3b5d32312b323537ull,0x6f6c2e6c756d090aull,0x722509203233732eull,
0x327225202c333132ull,0x090a3b32202c3231ull,0x203233752e726873ull,0x202c343132722509ull,
0x25202c3639317225ull,0x61090a3b33313272ull,0x09203233622e646eull,0x25202c3531327225ull,
0x3b33202c34313272ull,0x33622e6c6873090aull,0x3631327225092032ull,0x2c3531327225202cull,
0x2e726f090a3b3620ull,0x3272250920323362ull,0x31327225202c3731ull,0x3631327225202c31ull,
0x33622e726f090a3bull,0x3831327225092032ull,0x2c3630327225202cull,0x0a3b373132722520ull,
0x726168732e646c09ull,0x09203233732e6465ull,0x5b202c3931327225ull,0x785f616475635f5full,
0x3235373173666572ull,0x6d090a3b5d36312bull,0x33732e6f6c2e6c75ull,0x3032327225092032ull,
0x2c3931327225202cull,0x726873090a3b3220ull,0x722509203233752eull,0x317225202c313232ull,
0x32327225202c3639ull,0x2e646e61090a3b30ull,0x3272250920323362ull,0x32327225202c3232ull,
0x73090a3b33202c31ull,0x09203233622e6c68ull,0x25202c3332327225ull,0x3b38202c32323272ull,
0x6168732e646c090aull,0x203233732e646572ull,0x202c343232722509ull,0x5f616475635f5f5bull,
0x3537317366657278ull,0x090a3b5d30322b32ull,0x732e6f6c2e6c756dull,0x3232722509203233ull,
0x3432327225202c35ull,0x6873090a3b32202cull,0x2509203233752e72ull,0x7225202c36323272ull,
0x327225202c363931ull,0x646e61090a3b3532ull,0x722509203233622eull,0x327225202c373232ull,
0x090a3b33202c3632ull,0x203233622e6c6873ull,0x202c383232722509ull,0x31202c3732327225ull,
0x622e726f090a3b30ull,0x3232722509203233ull,0x3332327225202c39ull,0x3b3832327225202cull,
0x3233622e726f090aull,0x2c30333272250920ull,0x202c383132722520ull,0x090a3b3932327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c31333272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3432ull,0x3233732e6f6c2e6cull,0x2c32333272250920ull,
0x202c313332722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3333ull,
0x3233327225202c36ull,0x622e646e61090a3bull,0x3332722509203233ull,0x3333327225202c34ull,
0x6873090a3b33202cull,0x2509203233622e6cull,0x7225202c35333272ull,0x3b3231202c343332ull,
0x6168732e646c090aull,0x203233732e646572ull,0x202c363332722509ull,0x5f616475635f5f5bull,
0x3537317366657278ull,0x090a3b5d38322b32ull,0x732e6f6c2e6c756dull,0x3332722509203233ull,
0x3633327225202c37ull,0x6873090a3b32202cull,0x2509203233752e72ull,0x7225202c38333272ull,
0x327225202c363931ull,0x646e61090a3b3733ull,0x722509203233622eull,0x327225202c393332ull,
0x090a3b33202c3833ull,0x203233622e6c6873ull,0x202c303432722509ull,0x31202c3933327225ull,
0x622e726f090a3b34ull,0x3432722509203233ull,0x3533327225202c31ull,0x3b3034327225202cull,
0x3233622e726f090aull,0x2c32343272250920ull,0x202c303332722520ull,0x090a3b3134327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c33343272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3233ull,0x3233732e6f6c2e6cull,0x2c34343272250920ull,
0x202c333432722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3534ull,
0x3434327225202c36ull,0x622e646e61090a3bull,0x3432722509203233ull,0x3534327225202c36ull,
0x6873090a3b33202cull,0x2509203233622e6cull,0x7225202c37343272ull,0x3b3631202c363432ull,
0x3233622e726f090aull,0x2c32343272250920ull,0x202c323432722520ull,0x090a3b3734327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c38343272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3633ull,0x3233732e6f6c2e6cull,0x2c39343272250920ull,
0x202c383432722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3035ull,
0x3934327225202c36ull,0x622e646e61090a3bull,0x3532722509203233ull,0x3035327225202c31ull,
0x6873090a3b33202cull,0x2509203233622e6cull,0x7225202c32353272ull,0x3b3831202c313532ull,
0x3233622e726f090aull,0x2c32343272250920ull,0x202c323432722520ull,0x090a3b3235327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c33353272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3034ull,0x3233732e6f6c2e6cull,0x2c34353272250920ull,
0x202c333532722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3535ull,
0x3435327225202c36ull,0x622e646e61090a3bull,0x3532722509203233ull,0x3535327225202c36ull,
0x6873090a3b33202cull,0x2509203233622e6cull,0x7225202c37353272ull,0x3b3032202c363532ull,
0x3233622e726f090aull,0x2c32343272250920ull,0x202c323432722520ull,0x090a3b3735327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c38353272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3434ull,0x3233732e6f6c2e6cull,0x2c39353272250920ull,
0x202c383532722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3036ull,
0x3935327225202c36ull,0x622e646e61090a3bull,0x3632722509203233ull,0x3036327225202c31ull,
0x6873090a3b33202cull,0x2509203233622e6cull,0x7225202c32363272ull,0x3b3232202c313632ull,
0x3233622e726f090aull,0x2c32343272250920ull,0x202c323432722520ull,0x090a3b3236327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c33363272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3834ull,0x3233732e6f6c2e6cull,0x2c34363272250920ull,
0x202c333632722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3536ull,
0x3436327225202c36ull,0x622e646e61090a3bull,0x3632722509203233ull,0x3536327225202c36ull,
0x6873090a3b33202cull,0x2509203233622e6cull,0x7225202c37363272ull,0x3b3432202c363632ull,
0x3233622e726f090aull,0x2c32343272250920ull,0x202c323432722520ull,0x090a3b3736327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c38363272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3235ull,0x3233732e6f6c2e6cull,0x2c39363272250920ull,
0x202c383632722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3037ull,
0x3936327225202c36ull,0x622e646e61090a3bull,0x3732722509203233ull,0x3037327225202c31ull,
0x6873090a3b33202cull,0x2509203233622e6cull,0x7225202c32373272ull,0x3b3632202c313732ull,
0x3233622e726f090aull,0x2c32343272250920ull,0x202c323432722520ull,0x090a3b3237327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c33373272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3635ull,0x3233732e6f6c2e6cull,0x2c34373272250920ull,
0x202c333732722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3537ull,
0x3437327225202c36ull,0x622e646e61090a3bull,0x3732722509203233ull,0x3537327225202c36ull,
0x6873090a3b33202cull,0x2509203233622e6cull,0x7225202c37373272ull,0x3b3832202c363732ull,
0x3233622e726f090aull,0x2c32343272250920ull,0x202c323432722520ull,0x090a3b3737327225ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c38373272ull,0x72785f616475635full,
0x2b32353731736665ull,0x756d090a3b5d3036ull,0x3233732e6f6c2e6cull,0x2c39373272250920ull,
0x202c383732722520ull,0x2e726873090a3b32ull,0x3272250920323375ull,0x39317225202c3038ull,
0x3937327225202c36ull,0x622e6c6873090a3bull,0x3832722509203233ull,0x3038327225202c31ull,
0x6f090a3b3033202cull,0x2509203233622e72ull,0x7225202c32343272ull,0x327225202c323432ull,
0x6f6c2e090a3b3138ull,0x3939340937310963ull,0x2e747663090a3009ull,0x203631752e323373ull,
0x202c323832722509ull,0x782e646961746325ull,0x752e747663090a3bull,0x09203233752e3631ull,
0x7225202c34687225ull,0x756d090a3b323832ull,0x752e656469772e6cull,0x3832722509203631ull,
0x2c34687225202c33ull,0x747663090a3b3820ull,0x3233752e3436752eull,0x3730316472250920ull,
0x3b3338327225202cull,0x7261702e646c090aull,0x09203436752e6d61ull,0x202c383031647225ull,
0x70616475635f5f5bull,0x63385a5f5f6d7261ull,0x5073736572706d6full,0x7535505f30536a4bull,
0x7365725f32746e69ull,0x61090a3b5d746c75ull,0x09203436752e6464ull,0x202c393031647225ull,
0x202c373031647225ull,0x0a3b383031647225ull,0x3233622e6c687309ull,0x2c34383272250920ull,
0x202c353431722520ull,0x2e726f090a3b3631ull,0x3272250920323362ull,0x34317225202c3538ull,
0x3438327225202c36ull,0x6c672e7473090a3bull,0x2e32762e6c61626full,0x72255b0920323375ull,
0x2c5d302b39303164ull,0x2c35383272257b20ull,0x0a3b7d3234327225ull,0x38355f305f744c24ull,
0x6c2e090a3a303733ull,0x333509373109636full,0x697865090a300938ull,0x6557444c240a3b74ull,
0x6f63385a5f5f646eull,0x4b5073736572706dull,0x697535505f30536aull,0x207d090a3a32746eull,
0x6f63385a5f202f2full,0x4b5073736572706dull,0x697535505f30536aull,0x0000000a0a32746eull
};


}



extern "C" {


static const unsigned long long __deviceText_$sm_13$[] = {
0x33010102464c457full,0x0000000000000000ull,0x0000000100be0002ull,0x0000000000000000ull,
0x0000000000001f88ull,0x0000000000000040ull,0x003800400000000dull,0x0001000800400004ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000300000001ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000240ull,
0x00000000000000aeull,0x0000000000000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000030000000bull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000002eeull,
0x000000000000004dull,0x0000000000000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x0000000200000013ull,0x0000000000000000ull,0x0000000000000000ull,0x000000000000033bull,
0x0000000000000180ull,0x0000000a00000002ull,0x0000000000000001ull,0x0000000000000018ull,
0x0000000100000036ull,0x0000000000100006ull,0x0000000000000000ull,0x00000000000004bbull,
0x0000000000001a38ull,0x1c00000600000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000079ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001ef3ull,
0x0000000000000048ull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000800000055ull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000001f3bull,
0x0000000000000828ull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000000a0ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001f3bull,
0x000000000000004cull,0x0000000000000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x7472747368732e00ull,0x747274732e006261ull,0x746d79732e006261ull,0x672e766e2e006261ull,
0x6e692e6c61626f6cull,0x672e766e2e007469ull,0x742e006c61626f6cull,0x63385a5f2e747865ull,
0x5073736572706d6full,0x7535505f30536a4bull,0x766e2e0032746e69ull,0x2e6465726168732eull,
0x72706d6f63385a5full,0x30536a4b50737365ull,0x32746e697535505full,0x6e6f632e766e2e00ull,
0x5f2e31746e617473ull,0x6572706d6f63385aull,0x5f30536a4b507373ull,0x0032746e69753550ull,
0x736e6f632e766e2eull,0x5f000030746e6174ull,0x6572706d6f63385aull,0x5f30536a4b507373ull,
0x0032746e69753550ull,0x654d726f6c6f436bull,0x6f72700063697274ull,0x646f727000347364ull,
0x6168706c61003373ull,0x610034656c626154ull,0x6c6261546168706cull,0x0000000000003365ull,
0x0000000000000000ull,0x0000000000000000ull,0x0300000000000000ull,0x0000000000000100ull,
0x0000000000000000ull,0x0300000000000000ull,0x0000000000000200ull,0x0000000000000000ull,
0x0300000000000000ull,0x0000000000000300ull,0x0000000000000000ull,0x0300000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0300000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0300000000000000ull,0x0000000000000400ull,0x0000001a38000000ull,
0x0300000000000000ull,0x0000000000000600ull,0x0000000000000000ull,0x0300000000000000ull,
0x0000000000000500ull,0x0000000000000000ull,0x0300000000000000ull,0x0000000000000700ull,
0x0000000000000000ull,0x1200000001000000ull,0x0000000000000410ull,0x0000000000000000ull,
0x110000001a000000ull,0x0000000000000700ull,0x000000000c000000ull,0x1100000027000000ull,
0x000000002c000700ull,0x0000000010000000ull,0x110000002e000000ull,0x000000003c000700ull,
0x0000000010000000ull,0x1100000035000000ull,0x000000000c000700ull,0x0000000010000000ull,
0x1100000041000000ull,0x000000001c000700ull,0x0000000010000000ull,0x8010000015000000ull,
0x80a00014290403c7ull,0xd030801415040007ull,0xc8a0000bfd6c40c7ull,0x00a001b0030c0147ull,
0x001001b003000000ull,0x0341102c15000011ull,0x8020001415000000ull,0x8030020a15040147ull,
0x03404c1419c41007ull,0x802000cc15000000ull,0x80d00e0a15042147ull,0x8000000c0580c007ull,
0x80d0810a19c00007ull,0x8030100a1d044007ull,0x80a0000c19c41007ull,0x8030180e1d440047ull,
0x8030080a21e41007ull,0x0bc0010c15c41007ull,0x80a0000e1903b808ull,0x803018101d440047ull,
0x8004001401e41007ull,0x0bc0010c15e42147ull,0x80a0000e1903b808ull,0x8004001601440047ull,
0x0bc0010c15e42147ull,0x800400180103b808ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,
0x00a0027003000000ull,0x0010027003000000ull,0x03404c1415000001ull,0x8000000a05000000ull,
0x8014001415c00007ull,0x80040074014400c7ull,0x8014001615e42147ull,0x80040076014400c7ull,
0x8014001815e42147ull,0x80040078014400c7ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,
0x00a0039003000000ull,0x0010039003000000ull,0x80d0821415000001ull,0x03404c0a19044087ull,
0x03404c1415000000ull,0x8000000c09000000ull,0x8000000a05c00007ull,0x80d801d00dc00007ull,
0x80d401d009200007ull,0x181d00e014200007ull,0x141d00e41c1d00e2ull,0x8004007401b90560ull,
0x80b800c215e42147ull,0x8004007601002187ull,0x80b800c415e42147ull,0x80040078010021c7ull,
0x02f0000001e42147ull,0x00861ffe03e00000ull,0x00a004b003000000ull,0x001004b003000000ull,
0x80d0831415000001ull,0x03404c0a19044087ull,0x03404c1415000000ull,0x8000000c09000000ull,
0x8000000a05c00007ull,0x80d801d00dc00007ull,0x80d401d009200007ull,0x181d00e014200007ull,
0x141d00e41c1d00e2ull,0x8004007401b90560ull,0x80b800c215e42147ull,0x8004007601002187ull,
0x80b800c415e42147ull,0x80040078010021c7ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,
0x00a005d003000000ull,0x001005d003000000ull,0x80d0841415000001ull,0x03404c0a19044087ull,
0x03404c1415000000ull,0x8000000c09000000ull,0x8000000a05c00007ull,0x80d801d00dc00007ull,
0x80d401d009200007ull,0x181d00e014200007ull,0x141d00e41c1d00e2ull,0x8004007401b90560ull,
0x80b800c215e42147ull,0x8004007601002187ull,0x80b800c415e42147ull,0x80040078010021c7ull,
0x02f0000001e42147ull,0x00861ffe03e00000ull,0x00a006f003000000ull,0x001006f003000000ull,
0x80d0851415000001ull,0x03404c0a19044087ull,0x03404c1415000000ull,0x8000000c09000000ull,
0x8000000a05c00007ull,0x80d801d00dc00007ull,0x80d401d009200007ull,0x181d00e014200007ull,
0x141d00e41c1d00e2ull,0x8004007401b90560ull,0x80b800c215e42147ull,0x8004007601002187ull,
0x80b800c415e42147ull,0x80040078010021c7ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,
0x00a008a003000000ull,0x001008a003000000ull,0x03404c1415000001ull,0x8000000a09000000ull,
0x80d001d005c00007ull,0x181900f414200007ull,0x801800181d1900f6ull,0x03e500e0154400c7ull,
0x03e500e21903d800ull,0x03e500e41d03d800ull,0x001008a00303d800ull,0x0340469421000001ull,
0x8000021005000000ull,0x80c0050a21c00007ull,0x8004017401000007ull,0x80c0060a21e42207ull,
0x8004017601000007ull,0x80c0070a15e42207ull,0x8004017801000007ull,0x80c0060c15e42147ull,
0x8004017a01000007ull,0x80c0070c15e42147ull,0x8004017c01000007ull,0x80c0070e15e42147ull,
0x8004017e01000007ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,0x0310088019000000ull,
0xe0300a0c15000000ull,0xd8a0000bfd6c0107ull,0x00a009a0030c0147ull,0x001009a003000000ull,
0x8020001415000021ull,0x0340468a15040187ull,0x034046941d000000ull,0x8000020a05000000ull,
0x8000020e09c00007ull,0x80d405d00dc00007ull,0x80d805d005200007ull,0x141d00e014200007ull,
0x8008017401b50560ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,0x00a00a7003000000ull,
0x00100a7003000000ull,0x8020001415000011ull,0x0340468a15040187ull,0x034046941d000000ull,
0x8000020a05000000ull,0x8000020e09c00007ull,0x80d405d80dc00007ull,0x80d805d805200007ull,
0x141d00e014200007ull,0x8008017601b50560ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,
0x00a00b4003000000ull,0x00100b4003000000ull,0x8020001415000011ull,0x0340468a15040187ull,
0x034046941d000000ull,0x8000020a05000000ull,0x8000020e09c00007ull,0x80d405e00dc00007ull,
0x80d805e005200007ull,0x141d00e014200007ull,0x8008017801b50560ull,0x02f0000001e42147ull,
0x00861ffe03e00000ull,0x00a00c1003000000ull,0x00100c1003000000ull,0x8020001415000011ull,
0x0340468a15040187ull,0x034046941d000000ull,0x8000020a05000000ull,0x8000020e09c00007ull,
0x80d405e80dc00007ull,0x80d805e805200007ull,0x141d00e014200007ull,0x8008017a01b50560ull,
0x02f0000001e42147ull,0x00861ffe03e00000ull,0x00a00ce003000000ull,0x00100ce003000000ull,
0x8020001415000011ull,0x0340468a15040187ull,0x034046941d000000ull,0x8000020a05000000ull,
0x8000020e09c00007ull,0x80d405f00dc00007ull,0x80d805f005200007ull,0x141d00e014200007ull,
0x8008017c01b50560ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,0x00a00db003000000ull,
0x00100db003000000ull,0x8020001415000011ull,0x0340468a15040187ull,0x034046941d000000ull,
0x8000020a05000000ull,0x8000020e09c00007ull,0x80d405f80dc00007ull,0x80d805f805200007ull,
0x141d00e014200007ull,0x8008017e01b50560ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,
0x8030010c19000000ull,0xd8307c0dfdec1007ull,0x801008d0036c0107ull,0x80d005d005000012ull,
0x1c1500e618200007ull,0x80140008151500e2ull,0x03e50062194400c7ull,0x03e500601d03f800ull,
0x03e500641503f800ull,0x03e500681903f800ull,0x03e500641d03f800ull,0x03e5006a1503f800ull,
0x80b0070c2103f800ull,0x80b0080a21800007ull,0x2490001020800007ull,0x2cc0071018c00610ull,
0x14c5096630c50962ull,0x80c409c81dc0080aull,0x80e406c021002007ull,0x80e406c2250022c7ull,
0x80e406c419002307ull,0x80e405c41d0021c7ull,0x80e405c821002207ull,0x80e405ca15002247ull,
0x80b0080e19002187ull,0x80b0060a19800007ull,0x2090000c18800007ull,0x24c0070c1cc0080cull,
0x14c508662cc50862ull,0x80c408c831c0060aull,0x80e407c019002007ull,0x80e407c221002247ull,
0x80e407c4250022c7ull,0x80e405c419002307ull,0x80e405c81d002187ull,0x80e405ca21002207ull,
0x80b0070c15002247ull,0x80b0080a15800007ull,0x1c90000a14800007ull,0x2cc0060a18c0070aull,
0x14c5076624c50762ull,0x80c407c81dc0080aull,0x80e406c02d002007ull,0x80e406c2210022c7ull,
0x80e406c419002247ull,0x80e405c4250021c7ull,0x80e405c81d0022c7ull,0x80e405ca15002207ull,
0x80b0090e19002187ull,0x80b0060a19800007ull,0x2090000c18800007ull,0x24c0090c1cc0070cull,
0x14c508662cc50862ull,0x80c408c831c0060aull,0x80e407c019002007ull,0x80e407c221002247ull,
0x80e407c4250022c7ull,0x80e405c419002307ull,0x80e405c81d002187ull,0x80e405ca21002207ull,
0x80b0070c15002247ull,0x80b0080a15800007ull,0x1c90000a14800007ull,0x24c0060a18c0070aull,
0x14c507662cc50762ull,0x80c407c831c0080aull,0x80e406c01d002007ull,0x80e406c221002247ull,
0x80e406c4250022c7ull,0x80e405c419002307ull,0x80e405c81d0021c7ull,0x80e405ca21002207ull,
0x80b0070c15002247ull,0x80b0080a15800007ull,0x1c90000a14800007ull,0x2cc0060a18c0070aull,
0x14c5076624c50762ull,0x80c407c81dc0080aull,0x80e406c02d002007ull,0x80e406c2210022c7ull,
0x80e406c419002247ull,0x80e405c4250021c7ull,0x80e405c81d0022c7ull,0x80e405ca15002207ull,
0x80b0090e19002187ull,0x80b0060a19800007ull,0x2090000c18800007ull,0x2cc0090c1cc0070cull,
0x14c5086624c50862ull,0x80c408c831c0060aull,0x80e407c021002007ull,0x80e407c2190022c7ull,
0x80e407c41d002247ull,0x80e405c42d002307ull,0x80e405c825002207ull,0x80e405ca1d002187ull,
0x80b00b12150021c7ull,0x80b0070a15800007ull,0x8090000a21800007ull,0x00a014a003000007ull,
0x8000021405000000ull,0x14c00b1018c00007ull,0x001014a003c00812ull,0x03404c1425000001ull,
0x8000001209000000ull,0x14c9057624c00007ull,0x80e806d419c00710ull,0x80e805d815002247ull,
0x800403f401002187ull,0x02f0000001e42147ull,0x00861ffe03e00000ull,0x00a01a6003000000ull,
0x00101a6003000000ull,0xd8307c15fd000001ull,0x00a01a1003640147ull,0x80101a1003000000ull,
0x1b1028800d000012ull,0x7f10288009000000ull,0x8000000609000000ull,0x800000040dc00007ull,
0x801000f821c00007ull,0x80d00fd0110603c7ull,0x841000160d200007ull,0x84100014094400c7ull,
0x80bc03c00d4400c7ull,0x80bc02c009602107ull,0x80a000060d602107ull,0x80300004252c0147ull,
0x84100008090400c7ull,0x8410000a0d4400c7ull,0x8410000c114400c7ull,0x8410000e154400c7ull,
0x84100010194400c7ull,0x841000121d4400c7ull,0x80bc02c0094400c7ull,0x80bc03c00d602107ull,
0x80bc05c015602107ull,0x80bc04c011602107ull,0x80bc07c01d602107ull,0x80a000060d602107ull,
0x80a0000a152c0147ull,0x80bc06c0192c0147ull,0x80a0000e31602107ull,0x1c3003842c2c0147ull,
0x8410000609300588ull,0x8030000c314400c7ull,0x841000000d040307ull,0x84100004114400c7ull,
0x80bc02c0194400c7ull,0x8410000209602107ull,0x80bc03c00d4400c7ull,0x80bc04c015602107ull,
0x80a0000c19602107ull,0x8020000e312c0147ull,0x80bc02c009040307ull,0x80a0000611602107ull,
0x8030000a1d2c0147ull,0x8410001a0d040187ull,0x18200c962c4400c7ull,0x8410001809300484ull,
0x80bc03c0154400c7ull,0x8020000e1d602107ull,0x8410001e0d0402c7ull,0x80bc02c0114400c7ull,
0x80a0000a15602107ull,0x8410001c092c0147ull,0x80bc03c00d4400c7ull,0x1020078c18602107ull,
0x80be02c209300588ull,0x80a000060d602107ull,0x08200692142c0147ull,0x082005880c300384ull,
0x0320049021200384ull,0x800a000201000000ull,0xd8308811fde42087ull,0x80101560036c4147ull,
0x801000f80d000012ull,0x801000f8110403c7ull,0xd8300309fd0603c7ull,0x801019b0036c00c7ull,
0x800002080d000012ull,0x8000020609c00007ull,0x80dc03500dc00007ull,0x80d8035009200007ull,
0x801c000009200007ull,0x07202a88154400c7ull,0xd83802c1fd000000ull,0x8000020a096c2147ull,
0x002900c009c00007ull,0x0008000001046155ull,0x0320018811e42095ull,0xd8308909fd000000ull,
0x801018f0036c4147ull,0x032001860d000012ull,0xd8308007fd000000ull,0x801018e0036c4147ull,
0x02f0000001000012ull,0x03404c1409e00000ull,0x8000000409000000ull,0x0c1900f408c00007ull,
0x80180018111900f6ull,0x02f00000014400c7ull,0x00861ffe03e00000ull,0x00a01b1003000000ull,
0x00101b1003000000ull,0x8000021409000001ull,0x80d8035009c00007ull,0x03494c6015200007ull,
0x8000000a09000000ull,0x8008001401c00007ull,0x8008001601e42087ull,0x8008001801e420c7ull,
0x02f0000001e42107ull,0x00861ffe03e00000ull,0x004023d003000000ull,0x801000f82d000000ull,
0xff103f80090403c7ull,0x802000161107f7ffull,0xc8308a09fd040287ull,0x80500000036c4107ull,
0x803002080d000002ull,0x802000c80dc41007ull,0x80d00e060d0420c7ull,0xc8308b09fd80c007ull,
0x00000208096c4107ull,0x000802b401c00005ull,0x801000f819e420c5ull,0x03102880110603c7ull,
0x8000000809000000ull,0x801000f821c00007ull,0x801000f8150403c7ull,0x801000f81d0603c7ull,
0x801000f8110403c7ull,0x80300606250603c7ull,0x80d08c1225e40007ull,0x800002120d044007ull,
0x801c000625c00007ull,0x0320028c192400c7ull,0x80ea09c211000000ull,0x80ea09c21d002107ull,
0x80ea09c2150021c7ull,0xc8308d0dfd002147ull,0x802d0010216c4147ull,0x80101c60030402c7ull,
0x8030081025000002ull,0x80d0811031ec1007ull,0x80d001d009044007ull,0x8030101019200007ull,
0x80d0811225ec1007ull,0x80a000183d044007ull,0x80e88ec021440147ull,0x80a0000c41086107ull,
0x80a000125d440147ull,0x80c00f1e19440147ull,0x80e88ec225000007ull,0x80c0081e310861c7ull,
0x80e0172019000007ull,0x80c0091e39080187ull,0x80e0042e31000007ull,0x8090000c35080307ull,
0x80e0072e39000007ull,0x30c00c1a18080387ull,0x80a0000c19c00e1aull,0x80a0001831c40847ull,
0x80b07c0c19c40847ull,0x80b07c1831800007ull,0x44c0041e38800007ull,0x03c0000c19c0071eull,
0x03c0001831041f80ull,0x80e00820390427c0ull,0x80e0092049080387ull,0x80a0000c45080447ull,
0x80a0001851cc0047ull,0x4cc00e1a30cc0047ull,0x80a0002219c0121aull,0x80a0002839840647ull,
0x80a0001849840647ull,0x80a000264dc40847ull,0x80300b0c31c40847ull,0x8030051c39c41007ull,
0x80e88ec419c41007ull,0x80b07c2449086147ull,0x80b07c264d800007ull,0x80d00e1831800007ull,
0x80c0061e39040047ull,0x03c0002449000007ull,0x03c000264d041f80ull,0x80c0051e550427c0ull,
0x80e0052e39000007ull,0x80a0002449080387ull,0x80a000264dcc0047ull,0x80e0062065cc0047ull,
0x80c00e1a61080547ull,0x80a0002455000007ull,0x80a0002659840647ull,0x80c0191a39840647ull,
0x57c0312449000007ull,0x80300b2a3503d043ull,0x8030052c55c41007ull,0x57c0312245c41007ull,
0x80c012246503d043ull,0x80d0151a35000007ull,0x64c0112258040047ull,0x13c0192655c0192eull,
0x80e016204d03c81bull,0x13c0192851000647ull,0x58c0152a6403c81bull,0x80c0192e65c01428ull,
0x80e0162059000007ull,0x80a0001c39000647ull,0x80b07c1c39c40847ull,0x03c0001c39800007ull,
0x80a0001c39041f80ull,0x57c0311c65cc0047ull,0x68c019326803d043ull,0x80a000305dc01a2eull,
0x80b07c2e5dc40847ull,0x03c0002e5d800007ull,0x80a0002e5d041f80ull,0x57c0312e61cc0047ull,
0x80c018306d03d043ull,0x80e01b2041000007ull,0x10c0110868000687ull,0x80e0041e11c01222ull,
0x1cc0140e44080687ull,0x80e0071e1dc01528ull,0x80e0151225080447ull,0x14c0180a1c0401c7ull,
0x80e0121021c01930ull,0x80b0001225040107ull,0x80e0051e11000247ull,0x1cb00810140801c7ull,
0x80e0190c11b0092cull,0x18b0052614040107ull,0x80b0000811c0810eull,0x80e0800a15000107ull,
0x80b0002011000187ull,0x80e0820811000107ull,0xe3c0390811000147ull,0x80a0001c1903de38ull,
0x80a0002e15840647ull,0xc8b00209fd840647ull,0x80d0061a19600047ull,0x80d0051815040047ull,
0x801000180d040047ull,0x80100014090003c6ull,0x80100006010203c6ull,0x80100008090403c6ull,
0x072000962d0603c6ull,0xc8308f17fd000000ull,0x80101b60036c4147ull,0x8050000003000002ull,
0x80a000060d000007ull,0x80a0000405040007ull,0xc8300107fd040007ull,0x00d09000016400c7ull,
0x0010000211044085ull,0x00100006050403c5ull,0x001000080d0603c5ull,0x00402d60030403c5ull,
0x801000f82d000000ull,0x80300616110603c7ull,0x8020000811c41007ull,0xc8308b09fd040287ull,
0x80500000036c4107ull,0x17201a8815000002ull,0x0310288011000000ull,0x8000020a0d000000ull,
0x8000000809c00007ull,0x801000f819c00007ull,0x801000f8210403c7ull,0x801000f8150603c7ull,
0x801000f81d0403c7ull,0x801000f8110603c7ull,0x803c06c0250403c7ull,0x80d08c1225e42007ull,
0x8000021211044007ull,0x8410000e25c00007ull,0x84210010212400c7ull,0x0320028c190403c7ull,
0x80ea09c211000000ull,0x80ea09c21d002107ull,0x80ea09c2150021c7ull,0xc8308d0dfd002147ull,
0x80102530036c4147ull,0x8030081025000002ull,0x80d0811031ec1007ull,0x80d001d009044007ull,
0x8030101019200007ull,0x80d0811225ec1007ull,0x80a0001839044007ull,0x80e891c021440147ull,
0x80a0000c3d086107ull,0x80a0001259440147ull,0x80c00e1c19440147ull,0x80e891c225000007ull,
0x80c0081c310861c7ull,0x80e0161e19000007ull,0x80c0091c41080187ull,0x80e0042c31000007ull,
0x8090000c35080307ull,0x80e0072c41000007ull,0x30c00c1a18080407ull,0x80a0000c19c0101aull,
0x80a0001831c40847ull,0x80b07c0c19c40847ull,0x80b07c1831800007ull,0x48c0041c40800007ull,
0x03c0000c19c0071cull,0x03c0001831041f80ull,0x80e0081e450427c0ull,0x80e0091e49080407ull,
0x80a0000c41080487ull,0x80a000184dcc0047ull,0x50c0111a30cc0047ull,0x80a0002019c0121aull,
0x80a0002645840647ull,0x80a0001849840647ull,0x80a0002851c40847ull,0x80300b0c31c40847ull,
0x8030052245c41007ull,0x80e891c419c41007ull,0x80b07c2449086147ull,0x80b07c2851800007ull,
0x80d0111831800007ull,0x80c0061c45040047ull,0x03c0002449000007ull,0x03c0002855041f80ull,
0x80c0051c5d0427c0ull,0x80e0052c51000007ull,0x80a0002445080447ull,0x80a0002a49cc0047ull,
0x80e0061e61cc0047ull,0x80c0141a5d0805c7ull,0x80a0002251000007ull,0x80a0002455840647ull,
0x80c0181a61840647ull,0x57c0312245000007ull,0x80300b283503d043ull,0x8030052a51c41007ull,
0x57c0312041c41007ull,0x80c011226503d043ull,0x80d0141a35000007ull,0x64c0102054040047ull,
0x13c0192451c0192cull,0x80e0151e4903c81bull,0x13c019264d000647ull,0x54c014286403c81bull,
0x80c0192c65c01326ull,0x80e0151e55000007ull,0x80a0003061000647ull,0x80b07c3061c40847ull,
0x03c0003061800007ull,0x80a0003061041f80ull,0x57c0313065cc0047ull,0x68c019326803d043ull,
0x80a0002e59c01a2cull,0x80b07c2c59c40847ull,0x03c0002c59800007ull,0x80a0002c59041f80ull,
0x57c0312c5dcc0047ull,0x80c0172e6d03d043ull,0x80e01b1e3d000007ull,0x10c0100868000687ull,
0x80e0041c11c01120ull,0x1cc0130e40080687ull,0x80e0071c1dc01426ull,0x80e0141225080407ull,
0x14c0170a1c0401c7ull,0x80e0111021c0192eull,0x80b0001225040107ull,0x80e0051c11000247ull,
0x1cb00810140801c7ull,0x80e0190c11b0092aull,0x18b0052414040107ull,0x80b0000811c0810eull,
0x80e0800a19000107ull,0x80b0001e11000187ull,0x80a0003015000107ull,0x80e0820819840647ull,
0x80a0002c11000187ull,0x80d0051a15840647ull,0x03c0000c19040047ull,0x80d004181103e800ull,
0xc8b0020dfd040047ull,0x00a02d1003600047ull,0x80a0001011000000ull,0x80a0001415040007ull,
0x00102d1003040007ull,0xc8300509fd000001ull,0x041d00e0006400c7ull,0x0810008a0c100288ull,
0x80102d100310028cull,0x801c000001000002ull,0x80d00000014400c7ull,0x80300100010402c7ull,
0x80d0900001e41007ull,0x80dc00c001044007ull,0x0410008210042087ull,0x801000080d100286ull,
0x02f00000010403c7ull,0x032001962de00000ull,0xc8308c17fd000000ull,0x80102460036c4147ull,
0x8050000003000002ull,0x8000021409000007ull,0x800800f401c00007ull,0x80d803d009e42087ull,
0x0310208011200007ull,0x8004023401000000ull,0x00861ffe03e42287ull,0xc8300a09fd000000ull,
0x00a02e90036c00c7ull,0x80102e9003000000ull,0x8020000809000002ull,0x800002040d040287ull,
0x80dc03d011c00007ull,0x8410000009200007ull,0xc8b802c1fd4400c7ull,0x8410000009602107ull,
0x80080000014400c7ull,0x80dc08d00de42086ull,0x801c000009200006ull,0x80040234014400c6ull,
0x8230010811e42086ull,0xc8307c09fdec1007ull,0x80102db0036c0107ull,0x00861ffe03000002ull,
0x80d008d005000000ull,0x8014000009200007ull,0x00861ffe034400c7ull,0xc8300a05fd000000ull,
0x80300000036c0147ull,0x8030010609000002ull,0x80d0035005640087ull,0x80d0020001200007ull,
0x803401c211040207ull,0x803401c415c43007ull,0x803401c619c43007ull,0x803401c009c43007ull,
0x8030040011c43007ull,0x8030050015e40007ull,0x8030060019e40007ull,0x8030020009e40007ull,
0x80d08c0811e40007ull,0x80d08c0a15044007ull,0x80d08c0c19044007ull,0x80d08c0409044007ull,
0x8030020811044007ull,0x8030040a15c41007ull,0x8030060c19c41007ull,0x80d0040409c41007ull,
0x80d0060a11040047ull,0x803401c815040047ull,0x803401ca19c43007ull,0x80d0040409c43007ull,
0x8030050011040047ull,0x8030060015e40007ull,0x803401cc19e40007ull,0x803401ce1dc43007ull,
0x80d08c0811c43007ull,0x80d08c0a15044007ull,0x8030060019044007ull,0x803007001de40007ull,
0x8030080811e40007ull,0x80300a0a15c41007ull,0x80d08c0c19c41007ull,0x80d08c0e1d044007ull,
0x803401d021044007ull,0x80d0050811c43007ull,0x80300c0c15040047ull,0x80300e0e19c41007ull,
0x803008001dc41007ull,0x803401d221e40007ull,0x80d0040409c43007ull,0x80d0060a11040047ull,
0x80d08c0e15040047ull,0x8030080019044007ull,0x803401d41de40007ull,0x80d0040409c43007ull,
0x8030100a11040047ull,0x80d08c0c15c41007ull,0x8030070019044007ull,0x803401d61de40007ull,
0x80d0040409c43007ull,0x8030120a11040047ull,0x80d08c0c15c41007ull,0x8030070019044007ull,
0x803401d81de40007ull,0x80d0040409c43007ull,0x8030140a11040047ull,0x80d08c0c15c41007ull,
0x8030070019044007ull,0x803401da1de40007ull,0x80d0040409c43007ull,0x8030160a11040047ull,
0x80d08c0c15c41007ull,0x8030070019044007ull,0x803401dc1de40007ull,0x80d0040409c43007ull,
0x8030180a11040047ull,0x80d08c0c15c41007ull,0x8030070019044007ull,0x80d0040409e40007ull,
0x80301a0a11040047ull,0x80d08c0c15c41007ull,0x803401de19044007ull,0x80d0040409c43007ull,
0x80301c0a11040047ull,0x8030060001c41007ull,0x80d0040411e40007ull,0x8030100609040047ull,
0x80301e000dc41007ull,0x8010001001c41007ull,0x80d00202094400c7ull,0x80d003080d040047ull,
0x0361082c01040047ull,0x81d00e0009000000ull,0xff0000000fa08007ull,0x0400000008000000ull,
0x0100000002000000ull,0x003d800000000000ull,0x10000000403f8000ull,0x9f000003df000000ull,
0x2000000003000000ull,0x0041100000000000ull,0x0055555555000004ull,0x003f800000408000ull,
0x003f8000003f8000ull,0x0000000000411000ull,0x004040000040c000ull,0x0000000000408000ull,
0x0040000000400000ull,0x0200000900000900ull,0x0000010402000401ull,0x0100000400000400ull,
0x0000010401000401ull,0x0000000500000006ull,0x0000000000001f88ull,0x0000000000000000ull,
0x0000000000000000ull,0x00000000000000e0ull,0x00000000000000e0ull,0x0000000000000004ull,
0x00000a0560000000ull,0x00000000000004bbull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000001a80ull,0x0000000000001a80ull,0x0000000000000004ull,0x00000a0660000000ull,
0x0000000000001f3bull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000828ull,0x0000000000000004ull,0x0000000500000001ull,0x0000000000001f3bull,
0x0000000000000000ull,0x0000000000000000ull,0x000000000000004cull,0x000000000000004cull,
0x0000000000000004ull,0x0000000000000000ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_13", (char*)__deviceText_$sm_13$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_13$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0x2e00b786,(char*)"e4cd67aa65f4e4a9",(char*)"dxtc.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x907f5709,&__elfEntries1};
# 2 "/tmp/tmpxft_00003c13_00000000-1_dxtc.cudafe1.stub.c" 2
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1
# 113 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1
# 114 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 140 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
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

extern void __cudaRegisterShared(
  void **fatCubinHandle,
  void **devicePtr
);

extern void __cudaRegisterSharedVar(
  void **fatCubinHandle,
  void **devicePtr,
  size_t size,
  size_t alignment,
  int storage
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


}




extern int atexit(void(*)(void)) throw();







static void **__cudaFatCubinHandle;

static void __cudaUnregisterBinaryUtil(void)
{
  __cudaUnregisterFatBinary(__cudaFatCubinHandle);
}
# 279 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
# 1 "/usr/local/cuda/bin/../include/common_functions.h" 1
# 63 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 64 "/usr/local/cuda/bin/../include/common_functions.h" 2

static __attribute__((__unused__)) clock_t __cuda_clock(void)
{
  return clock();
}

static __attribute__((__unused__)) void *__cuda_memset(void *s, int c, size_t n)
{
  return memset(s, c, n);
}

static __attribute__((__unused__)) void *__cuda_memcpy(void *d, const void *s, size_t n)
{
  return memcpy(d, s, n);
}
# 88 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 940 "/usr/local/cuda/bin/../include/math_functions.h" 3
int __cuda_error_not_implememted(void);
# 963 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) int __cuda_abs(int a)
{
  return abs(a);
}

static __attribute__((__unused__)) float __cuda_fabsf(float a)
{
  return fabsf(a);
}

static __attribute__((__unused__)) long long int __cuda_llabs(long long int a)
{

  return ::llabs(a);



}

static __attribute__((__unused__)) float __cuda_exp2f(float a)
{
  return exp2f(a);
}

# 1 "/usr/local/cuda/bin/../include/device_functions.h" 1 3
# 458 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 459 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 2404 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/common_types.h" 1 3
# 37 "/usr/local/cuda/bin/../include/common_types.h" 3
union __cudart_FloatUintCvt {
    float f;
    unsigned int i;
};

union __cudart_FloatIntCvt {
    float f;
    int i;
};

union __cudart_DoubleUlonglongCvt {
    double d;
    unsigned long long int i;
};

union __cudart_DoubleLonglongCvt {
    double d;
    long long int i;
};

union __cudart_DoubleInthiloCvt {
    double d;
    signed int i[2];
};

struct __cudart_UintUint {
    unsigned int lo;
    unsigned int hi;
};
# 2405 "/usr/local/cuda/bin/../include/device_functions.h" 2 3

static const unsigned char __internal_rcpTab[128] =
{
  0xff, 0xfd, 0xfb, 0xf9, 0xf7, 0xf5, 0xf4, 0xf2,
  0xf0, 0xee, 0xed, 0xeb, 0xe9, 0xe8, 0xe6, 0xe4,
  0xe3, 0xe1, 0xe0, 0xde, 0xdd, 0xdb, 0xda, 0xd8,
  0xd7, 0xd5, 0xd4, 0xd3, 0xd1, 0xd0, 0xcf, 0xcd,
  0xcc, 0xcb, 0xca, 0xc8, 0xc7, 0xc6, 0xc5, 0xc4,
  0xc2, 0xc1, 0xc0, 0xbf, 0xbe, 0xbd, 0xbc, 0xbb,
  0xba, 0xb9, 0xb8, 0xb7, 0xb6, 0xb5, 0xb4, 0xb3,
  0xb2, 0xb1, 0xb0, 0xaf, 0xae, 0xad, 0xac, 0xab,
  0xaa, 0xa9, 0xa8, 0xa8, 0xa7, 0xa6, 0xa5, 0xa4,
  0xa3, 0xa3, 0xa2, 0xa1, 0xa0, 0x9f, 0x9f, 0x9e,
  0x9d, 0x9c, 0x9c, 0x9b, 0x9a, 0x99, 0x99, 0x98,
  0x97, 0x97, 0x96, 0x95, 0x95, 0x94, 0x93, 0x93,
  0x92, 0x91, 0x91, 0x90, 0x8f, 0x8f, 0x8e, 0x8e,
  0x8d, 0x8c, 0x8c, 0x8b, 0x8b, 0x8a, 0x89, 0x89,
  0x88, 0x88, 0x87, 0x87, 0x86, 0x85, 0x85, 0x84,
  0x84, 0x83, 0x83, 0x82, 0x82, 0x81, 0x81, 0x80
};

static const unsigned int __internal_invSqrtCubeTab[96] =
{
  0xfa0bf8fe, 0xee6b28fa, 0xe5f024f7, 0xdaf268f3,
  0xd2f000f0, 0xc890c0ec, 0xc10378e9, 0xb9a758e6,
  0xb4da40e4, 0xadcea0e1, 0xa6f278de, 0xa279c0dc,
  0x9beb48d9, 0x97a5c4d7, 0x916340d4, 0x8d4fc8d2,
  0x895000d0, 0x8563b8ce, 0x818ac0cc, 0x7dc4e8ca,
  0x7a1200c8, 0x7671d8c6, 0x72e440c4, 0x6f6908c2,
  0x6db240c1, 0x6a523cbf, 0x670424bd, 0x6563c0bc,
  0x623028ba, 0x609ce8b9, 0x5d8364b7, 0x5bfd18b6,
  0x58fd40b4, 0x5783a8b3, 0x560e48b2, 0x533000b0,
  0x51c70caf, 0x506238ae, 0x4da4c0ac, 0x4c4c10ab,
  0x4af768aa, 0x49a6b8a9, 0x485a00a8, 0x471134a7,
  0x45cc58a6, 0x434e40a4, 0x4214f8a3, 0x40df88a2,
  0x3fade0a1, 0x3e8000a0, 0x3d55dc9f, 0x3c2f789e,
  0x3c2f789e, 0x3b0cc49d, 0x39edc09c, 0x38d2609b,
  0x37baa89a, 0x36a68899, 0x35960098, 0x34890497,
  0x34890497, 0x337f9896, 0x3279ac95, 0x31774094,
  0x30784893, 0x30784893, 0x2f7cc892, 0x2e84b091,
  0x2d900090, 0x2d900090, 0x2c9eac8f, 0x2bb0b88e,
  0x2bb0b88e, 0x2ac6148d, 0x29dec08c, 0x29dec08c,
  0x28fab08b, 0x2819e88a, 0x2819e88a, 0x273c5889,
  0x273c5889, 0x26620088, 0x258ad487, 0x258ad487,
  0x24b6d886, 0x24b6d886, 0x23e5fc85, 0x23184084,
  0x23184084, 0x224d9883, 0x224d9883, 0x21860882,
  0x21860882, 0x20c18081, 0x20c18081, 0x20000080
};

static __attribute__((__unused__)) float __internal_frcp_kernel (float x,enum cudaRoundMode mode)
{
  unsigned long long prod;
  volatile union __cudart_FloatUintCvt arg;
  unsigned int expo;
  unsigned int sign;
  unsigned f, y;

  arg.f = x;
  sign = arg.i & 0x80000000;
  expo = (arg.i >> 23);
  expo = expo & 0xff;
  f = expo - 1;

  if (f <= 0xFD) {
    y = (arg.i << 8);
    y = y | 0x80000000;

    arg.i = __internal_rcpTab[(y >> 24) - 128];

    f = arg.i * arg.i;
    f = f << 16;
    prod = ((unsigned long long)y) * f;
    arg.i = (arg.i << 24) - (unsigned)(prod >> 32);

    f = arg.i + arg.i;
    prod = ((unsigned long long)y) * f;
    f = (unsigned)(-(int)(prod >> 32));
    prod = ((unsigned long long)arg.i) * f;
    y = y >> 8;

    expo = (2 * 127) - expo - 2;
    arg.i = (unsigned)(prod >> 32);
    if (mode == cudaRoundNearest) {
      arg.i = arg.i >> 6;
    } else {
      arg.i = (arg.i + 32) >> 6;
    }
    if ((int)expo >= 0) {
      f = y * arg.i;
      arg.i = ((expo << 23) + arg.i) | sign;
    } else {

      expo = -(int)expo;
      arg.i = arg.i >> expo;
      f = y * arg.i;
      arg.i = arg.i | sign;
    }
    if (mode == cudaRoundNearest) {
      expo = f + y;
      if ((int)f < 0) f = (unsigned)(-(int)f);
      if ((int)expo < 0) expo = (unsigned)(-(int)expo);
      if (expo < f) arg.i++;
    } else if (mode == cudaRoundZero) {
      if ((int)f > 0) arg.i = arg.i - 1;
    } else if (mode == cudaRoundPosInf) {
      if (((int)f > 0) && sign) arg.i = arg.i - 1;
      if (((int)f < 0) && !sign) arg.i = arg.i + 1;
    } else {
      if (((int)f > 0) && !sign) arg.i = arg.i - 1;
      if (((int)f < 0) && sign) arg.i = arg.i + 1;
    }
    return arg.f;
  } else {

    if (!(arg.i << 1)) {
      arg.i = 0x7F800000 | arg.i;
      return arg.f;
    }

    if ((arg.i << 1) == 0xff000000) {
      arg.i &= 0x80000000;
      return arg.f;
    }

    if ((arg.i << 1) > 0xff000000) {
      arg.i |= 0x00400000;
      return arg.f;
    }

    f = 0;
    arg.i <<= 8;
    do {
      f++;
      arg.i <<= 1;
    } while ((int)arg.i > 0);
    arg.i >>= 8;
    arg.i |= sign;
    arg.f = __internal_frcp_kernel (arg.f, mode);
    expo = ((arg.i << 1) >> 24);
    if ((expo + f) < 255) {
      arg.i = (arg.i + (f << 23));
      return arg.f;
    }
    if (mode == cudaRoundNearest) {
      arg.i = (arg.i & 0x80000000) | 0x7f800000;
    } else if (mode == cudaRoundZero) {
      arg.i = (arg.i & 0x80000000) | 0x7f7fffff;
    } else if (mode == cudaRoundPosInf) {
      arg.i = (arg.i & 0x80000000) | ((sign) ? 0x7f7fffff : 0x7f800000);
    } else {
      arg.i = (arg.i & 0x80000000) | ((sign) ? 0x7f800000 : 0x7f7fffff);
    }
    return arg.f;
  }
}

static __attribute__((__unused__)) float __internal_fsqrt_kernel (float radicand, enum cudaRoundMode mode)

{
  unsigned long long prod;
  volatile union __cudart_FloatUintCvt arg;
  unsigned int expo;
  unsigned int s, f, x;

  arg.f = radicand;
  expo = arg.i >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((arg.i <= 0x80000000) && (f <= 0xFD)) {

    x = (arg.i << 8) | 0x80000000;
    x = x >> (expo & 1);

    arg.i = f = __internal_invSqrtCubeTab[((unsigned)x >> 25) - 32];

    prod = ((unsigned long long)x) * f;
    arg.i = ((arg.i * 3) << 22) - (unsigned)(prod >> 32);

    prod = ((unsigned long long)arg.i) * arg.i;
    s = (unsigned)(prod >> 32);
    prod = ((unsigned long long)x) * s;
    f = 0x30000000 - (unsigned)(prod >> 32);
    prod = ((unsigned long long)f) * arg.i;
    arg.i = (unsigned)(prod >> 32);

    prod = ((unsigned long long)x) * arg.i;
    arg.i = (unsigned)(prod >> 32);
    if (mode == cudaRoundNearest) {
      arg.i = arg.i >> 3;
    } else {
      arg.i = (arg.i + 4) >> 3;
    }
    x = (x << 16) - (arg.i * arg.i);

    if (mode == cudaRoundNearest) {
      f = x - (2 * arg.i + 1);
      if ((int)f < 0) f = (unsigned)(-(int)f);
      if ((int)x < 0) x = (unsigned)(-(int)x);
      if (f < x) arg.i ++;
    } else if ((mode == cudaRoundZero) || (mode == cudaRoundMinInf)) {
      if ((int)x < 0) arg.i--;
    } else if (mode == cudaRoundPosInf) {
      if ((int)x > 0) arg.i++;
    }
    arg.i = arg.i + (((expo + 125) & ~0x1) << 22);
    return arg.f;
  } else {

    if (!(arg.i << 1) || (arg.i == 0x7F800000)) {
      return arg.f;
    }

    if ((arg.i << 1) > 0xFF000000) {
      arg.i |= 0x00400000;
      return arg.f;
    }

    if (arg.i & 0x80000000) {
      arg.i = 0xFFC00000;
      return arg.f;
    }

    x = 0;
    arg.i <<= 8;
    do {
      x++;
      arg.i <<= 1;
    } while ((int)arg.i > 0);
    arg.i >>= 8;
    arg.i += (x & 1) << 23;
    x += (x & 1);
    arg.f = __internal_fsqrt_kernel (arg.f, mode);
    arg.i -= ((x >> 1) << 23);
    return arg.f;
  }
}

static __attribute__((__unused__)) float __internal_fdiv_kernel (float dividend, float divisor, enum cudaRoundMode mode)

{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  volatile union __cudart_FloatUintCvt cvtx, cvty, res;

  cvtx.f = dividend;
  cvty.f = divisor;
  expox = ((cvtx.i >> 23) & 0xff) - 1;
  expoy = ((cvty.i >> 23) & 0xff) - 1;
  sign = ((cvtx.i ^ cvty.i) & 0x80000000);

  if ((expox <= 0xFD) && (expoy <= 0xFD)) {
divide:
    expox = expox - expoy + 127 - 1;
    expoy = expox;

    y = (cvty.i << 8) | 0x80000000;
    x = (cvtx.i & 0x00ffffff) | 0x00800000;

    r = __internal_rcpTab[(y >> 24) - 128];

    f = r * r;
    prod = ((unsigned long long)y) * (f << 16);
    r = (r << 24) - (unsigned)(prod >> 32);

    prod = ((unsigned long long)y) * (r << 1);
    f = (unsigned)-(int)(prod >> 32);
    prod = ((unsigned long long)f) * (r << 1);
    r = (unsigned)(prod >> 32);

    prod = ((unsigned long long)x) * (r << 1);

    if (((int)((prod >> 32) << 8)) > 0) {
      expox--;
      prod = prod + prod;
    }
    if (mode == cudaRoundNearest) {

      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem0, rem1, inc;

        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        rem0 = rem1 - y;
        inc = abs(rem0) < abs(rem1);

        res.i = sign | ((expox << 23) + r + inc);
        return res.f;
      } else if ((int)expox >= 254) {

        res.i = sign | 0x7f800000;
        return res.f;
      } else {

        int shift = -(int)expox;
        if (shift > 23) {

          r = (shift < 25) && ((x != y) || (r > 0x00ff0000));
          res.i = sign | r;
          return res.f;
        }
        if (x == y) {

          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          remhi = remlo - y;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if ((remhi < remlo) || ((remhi == remlo) && (r & 1))) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundZero) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if (rem1 < 0) r--;
        r = (expox << 23) + r;
        if (r == 0x7f800000) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        res.i = sign | 0x7f7fffff;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift < 31)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = 0;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) & (r != 0)) r--;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundPosInf) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if ((rem1 < 0) && (sign)) r--;
        if ((rem1 > 0) && (!sign)) r++;
        r = (expox << 23) + r;
        if ((r == 0x7f800000) && (sign)) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        r = sign ? 0x7f7fffff : 0x7f800000;
        res.i = sign | r;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift <= 24)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          if (r == 0) r = !sign;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = !sign;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) && (r != 0) && (sign)) r--;
          if ((remlo > 0) && (!sign)) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundMinInf) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if ((rem1 < 0) && (!sign)) r--;
        if ((rem1 > 0) && (sign)) r++;
        r = (expox << 23) + r;
        if ((r == 0x7f800000) && (!sign)) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        r = sign ? 0x7f800000 : 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift <= 24)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          if (r == 0) r = !!sign;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = !!sign;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) && (r != 0) && (!sign)) r--;
          if ((remlo > 0) && (sign)) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    }
  }
  {
    int xzero, yzero, xinf, yinf, xnan, ynan;

    xnan = (cvtx.i << 1) > 0xff000000;
    ynan = (cvty.i << 1) > 0xff000000;

    if (xnan) {
      res.i = cvtx.i | 0x00400000;
      return res.f;
    }
    if (ynan) {
      res.i = cvty.i | 0x00400000;
      return res.f;
    }
    xzero = (cvtx.i << 1) == 0x00000000;
    yzero = (cvty.i << 1) == 0x00000000;
    xinf = (cvtx.i << 1) == 0xff000000;
    yinf = (cvty.i << 1) == 0xff000000;

    if ((xzero & yzero) | (xinf & yinf)) {
      res.i = 0xffc00000;
      return res.f;
    }

    if (xzero | yinf) {
      res.i = sign;
      return res.f;
    }

    if (yzero | xinf) {
      res.i = sign | 0x7f800000;
      return res.f;
    }

    if ((int)expox < 0) {
      cvtx.i = cvtx.i << 9;
      while ((int)cvtx.i >= 0) {
        expox--;
        cvtx.i = cvtx.i + cvtx.i;
      }
      cvtx.i = cvtx.i >> 8;
    }
    if ((int)expoy < 0) {
      cvty.i = cvty.i << 9;
      while ((int)cvty.i >= 0) {
        expoy--;
        cvty.i = cvty.i + cvty.i;
      }
      cvty.i = cvty.i >> 8;
    }
    goto divide;
  }
}

static __attribute__((__unused__)) float __internal_fmul_kernel (float a, float b, enum cudaRoundMode mode)

{
  unsigned long long product;
  volatile union __cudart_FloatUintCvt xx, yy;
  unsigned expo_x, expo_y;

  xx.f = a;
  yy.f = b;

  expo_y = 0xFF;
  expo_x = expo_y & (xx.i >> 23);
  expo_x = expo_x - 1;
  expo_y = expo_y & (yy.i >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {
multiply:
    expo_x = expo_x + expo_y;
    expo_y = xx.i ^ yy.i;
    xx.i = xx.i & 0x00ffffff;
    yy.i = yy.i << 8;
    xx.i = xx.i | 0x00800000;
    yy.i = yy.i | 0x80000000;

    product = ((unsigned long long)xx.i) * yy.i;
    expo_x = expo_x - 127 + 2;
    expo_y = expo_y & 0x80000000;
    xx.i = (unsigned int)(product >> 32);
    yy.i = (unsigned int)(product & 0xffffffff);

    if (xx.i < 0x00800000) {
      xx.i = (xx.i << 1) | (yy.i >> 31);
      yy.i = (yy.i << 1);
      expo_x--;
    }
    if (expo_x <= 0xFD) {
      xx.i = xx.i | expo_y;
      xx.i = xx.i + (expo_x << 23);

      if (mode == cudaRoundNearest) {
        if (yy.i < 0x80000000) return xx.f;
        xx.i += ((yy.i == 0x80000000) ? (xx.i & 1) : (yy.i >> 31));
      } else if (mode == cudaRoundZero) {
      } else if (mode == cudaRoundPosInf) {
        xx.i += (yy.i && !expo_y);
      } else if (mode == cudaRoundMinInf) {
        xx.i += (yy.i && expo_y);
      }
      return xx.f;
    } else if ((int)expo_x >= 254) {

      if (mode == cudaRoundNearest) {
         xx.i = expo_y | 0x7F800000;
      } else if (mode == cudaRoundZero) {
         xx.i = expo_y | 0x7F7FFFFF;
      } else if (mode == cudaRoundPosInf) {
         xx.i = (expo_y ? 0xff7fffff : 0x7F800000);
      } else {
         xx.i = (expo_y ? 0xFF800000 : 0x7f7fffff);
      }
      return xx.f;
    } else {

      expo_x = ((unsigned int)-((int)expo_x));
      if (mode == cudaRoundNearest) {
        if (expo_x > 25) {

          xx.i = expo_y;
          return xx.f;
        } else {
          yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
          xx.i = expo_y + (xx.i >> expo_x);
          xx.i += ((yy.i == 0x80000000) ? (xx.i & 1) : (yy.i >> 31));
          return xx.f;
        }
      } else if (mode == cudaRoundZero) {
        if (expo_x > 25) expo_x = 25;
        xx.i = expo_y + (xx.i >> expo_x);
        return xx.f;
      } else if (mode == cudaRoundPosInf) {
        if (expo_x > 25) expo_x = 25;
        yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
        xx.i = expo_y + (xx.i >> expo_x);
        xx.i += (yy.i && !expo_y);
        return xx.f;
      } else {
        if (expo_x > 25) expo_x = 25;
        yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
        xx.i = expo_y + (xx.i >> expo_x);
        xx.i += (yy.i && expo_y);
        return xx.f;
      }
    }
  } else {
    product = xx.i ^ yy.i;
    product = product & 0x80000000;
    if (!(xx.i & 0x7fffffff)) {
      if (expo_y != 254) {
        xx.i = (unsigned int)product;
        return xx.f;
      }
      expo_y = yy.i << 1;
      if (expo_y == 0xFF000000) {
        xx.i = expo_y | 0x00C00000;
      } else {
        xx.i = yy.i | 0x00400000;
      }
      return xx.f;
    }
    if (!(yy.i & 0x7fffffff)) {
      if (expo_x != 254) {
        xx.i = (unsigned int)product;
        return xx.f;
      }
      expo_x = xx.i << 1;
      if (expo_x == 0xFF000000) {
        xx.i = expo_x | 0x00C00000;
      } else {
        xx.i = xx.i | 0x00400000;
      }
      return xx.f;
    }
    if ((expo_y != 254) && (expo_x != 254)) {
      expo_y++;
      expo_x++;
      if (expo_x == 0) {
        expo_y |= xx.i & 0x80000000;




        xx.i = xx.i << 8;
        while (!(xx.i & 0x80000000)) {
          xx.i <<= 1;
          expo_x--;
        }
        xx.i = (xx.i >> 8) | (expo_y & 0x80000000);
        expo_y &= ~0x80000000;
        expo_y--;
        goto multiply;
      }
      if (expo_y == 0) {
        expo_x |= yy.i & 0x80000000;
        yy.i = yy.i << 8;
        while (!(yy.i & 0x80000000)) {
          yy.i <<= 1;
          expo_y--;
        }
        yy.i = (yy.i >> 8) | (expo_x & 0x80000000);
        expo_x &= ~0x80000000;
        expo_x--;
        goto multiply;
      }
    }
    expo_x = xx.i << 1;
    expo_y = yy.i << 1;

    if (expo_x > 0xFF000000) {

      xx.i = xx.i | 0x00400000;
      return xx.f;
    }

    if (expo_y > 0xFF000000) {

      xx.i = yy.i | 0x00400000;
      return xx.f;
    }
    xx.i = (unsigned int)product | 0x7f800000;
    return xx.f;
  }
}

static __attribute__((__unused__)) float __internal_fmaf_kernel (float a, float b, float c, enum cudaRoundMode mode)

{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;
  volatile union __cudart_FloatUintCvt cvt;

  cvt.f = a;
  xx = cvt.i;
  cvt.f = b;
  yy = cvt.i;
  cvt.f = c;
  zz = cvt.i;

  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) &&
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {




    if ((yy << 1) > 0xff000000) {
      return b + b;
    }
    if ((zz << 1) > 0xff000000) {
      return c + c;
    }
    if ((xx << 1) > 0xff000000) {
      return a + a;
    }
# 3184 "/usr/local/cuda/bin/../include/device_functions.h" 3
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      cvt.i = 0xffc00000;
      return cvt.f;
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          cvt.i = 0xffc00000;
          return cvt.f;
        }
      }
    }




    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      cvt.i = xx;
      return cvt.f;
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      cvt.i = yy;
      return cvt.f;
    }
    if ((zz << 1) == 0xff000000) {
      cvt.i = zz;
      return cvt.f;
    }





    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          cvt.i = zz;
          return cvt.f;
        }
      }
    }



    if (((zz << 1) == 0) &&
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      if (mode == cudaRoundMinInf) {
        zz = 0x80000000 & (xx ^ yy ^ zz);
      } else {
        zz &= 0x7fffffff;
      }
      cvt.i = zz;
      return cvt.f;
    }



    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      cvt.i = zz;
      return cvt.f;
    }

    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }

    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }

    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;

  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) {
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;

    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }


    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {

      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) |
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }

    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }
    if ((int)u < 0) {

      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {

        if (mode == cudaRoundMinInf) {
          xx = 0x80000000;
        }
        cvt.i = xx;
        return cvt.f;
      }
      if ((int)xx < 0) {


        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }

      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {

      yy = yy + ww;
      s = yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {

    xx |= expo_y;
    if (mode == cudaRoundNearest) {
      s = xx & 1;
      xx += (temp == 0x80000000) ? s : (temp >> 31);
    } else if (mode == cudaRoundPosInf) {
      xx += temp && !expo_y;
    } else if (mode == cudaRoundMinInf) {
      xx += temp && expo_y;
    }
    xx = xx + (expo_x << 23);
    cvt.i = xx;
    return cvt.f;
  } else if ((int)expo_x >= 126) {

    if (mode == cudaRoundNearest) {
      xx = expo_y | 0x7f800000;
    } else if (mode == cudaRoundZero) {
      xx = expo_y | 0x7F7FFFFF;
    } else if (mode == cudaRoundPosInf) {
      xx = expo_y ? 0xFF7FFFFF : 0x7f800000;
    } else if (mode == cudaRoundMinInf) {
      xx = expo_y ? 0xff800000 : 0x7f7fffff;
    }
    cvt.i = xx;
    return cvt.f;
  }

  expo_x = (unsigned int)(-(int)expo_x);
  if (expo_x > 25) {

    xx = 0;
    if (mode == cudaRoundPosInf) {
      xx += !expo_y;
    } else if (mode == cudaRoundMinInf) {
      xx += !!expo_y;
    }
    cvt.i = expo_y | xx;
    return cvt.f;
  }
  temp = (xx << (32 - expo_x)) | ((temp) ? 1 : 0);
  xx = xx >> expo_x;
  if (mode == cudaRoundNearest) {
    xx = xx + ((temp == 0x80000000) ? (xx & 1) : (temp >> 31));
  } else if (mode == cudaRoundPosInf) {
    xx = xx + (!expo_y && temp);
  } else if (mode == cudaRoundMinInf) {
    xx = xx + (expo_y && temp);
  }
  xx = expo_y + xx;
  cvt.i = xx;
  return cvt.f;
}

static __attribute__((__unused__)) float __internal_fadd_kernel (float a, float b, enum cudaRoundMode mode)

{
  volatile union __cudart_FloatUintCvt xx, yy;
  unsigned int expo_x;
  unsigned int expo_y;
  unsigned int temp;

  xx.f = a;
  yy.f = b;


  expo_y = yy.i << 1;
  if (expo_y > (xx.i << 1)) {
    expo_y = xx.i;
    xx.i = yy.i;
    yy.i = expo_y;
  }

  temp = 0xff;
  expo_x = temp & (xx.i >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy.i >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {
add:
    expo_y = expo_x - expo_y;
    if (expo_y > 25) {
      expo_y = 31;
    }
    temp = xx.i ^ yy.i;
    xx.i = xx.i & ~0x7f000000;
    xx.i = xx.i | 0x00800000;
    yy.i = yy.i & ~0xff000000;
    yy.i = yy.i | 0x00800000;

    if ((int)temp < 0) {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yy.i << temp) : 0;
      temp = (unsigned)(-((int)temp));
      xx.i = xx.i - (yy.i >> expo_y) - (temp ? 1 : 0);
      if (xx.i & 0x00800000) {
        if (expo_x <= 0xFD) {
          xx.i = xx.i + (expo_x << 23);
          if (mode == cudaRoundNearest) {
            if (temp < 0x80000000) return xx.f;
            xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
          } else if (mode == cudaRoundZero) {
          } else if (mode == cudaRoundPosInf) {
            xx.i += (temp && !(xx.i & 0x80000000));
          } else if (mode == cudaRoundMinInf) {
            xx.i += (temp && (xx.i & 0x80000000));
          }
          return xx.f;
        }
      } else {
        if ((temp | (xx.i << 1)) == 0) {

          if (mode == cudaRoundMinInf) {
            xx.i = 0x80000000;
          } else {
            xx.i = 0;
          }
          return xx.f;
        }

        yy.i = xx.i & 0x80000000;
        do {
          xx.i = (xx.i << 1) | (temp >> 31);
          temp <<= 1;
          expo_x--;
        } while (!(xx.i & 0x00800000));
        xx.i = xx.i | yy.i;
      }
    } else {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yy.i << temp) : 0;
      xx.i = xx.i + (yy.i >> expo_y);
      if (!(xx.i & 0x01000000)) {
        if (expo_x <= 0xFD) {
          xx.i = xx.i + (expo_x << 23);
          if (mode == cudaRoundNearest) {
            if (temp < 0x80000000) return xx.f;
            xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
          } else if (mode == cudaRoundZero) {
          } else if (mode == cudaRoundPosInf) {
            xx.i += (temp && !(xx.i & 0x80000000));
          } else if (mode == cudaRoundMinInf) {
            xx.i += (temp && (xx.i & 0x80000000));
          }
          return xx.f;
        }
      } else {

        temp = (xx.i << 31) | (temp >> 1);
        xx.i = ((xx.i & 0x80000000) | (xx.i >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
    if (expo_x <= 0xFD) {
      xx.i = xx.i + (expo_x << 23);
      if (mode == cudaRoundNearest) {
        if (temp < 0x80000000) return xx.f;
        xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
      } else if (mode == cudaRoundZero) {
      } else if (mode == cudaRoundPosInf) {
        xx.i += (temp && !(xx.i & 0x80000000));
      } else if (mode == cudaRoundMinInf) {
        xx.i += (temp && (xx.i & 0x80000000));
      }
      return xx.f;
    }
    if ((int)expo_x >= 254) {

      temp = xx.i & 0x80000000;
      if (mode == cudaRoundNearest) {
        xx.i = (temp) | 0x7f800000;
      } else if (mode == cudaRoundZero) {
        xx.i = (temp) | 0x7f7fffff;
      } else if (mode == cudaRoundMinInf) {
        xx.i = (temp ? 0xFF800000 : 0x7f7fffff);
      } else if (mode == cudaRoundPosInf) {
        xx.i = (temp ? 0xff7fffff : 0x7F800000);
      }
      return xx.f;
    }

    expo_y = expo_x + 32;
    yy.i = xx.i & 0x80000000;
    xx.i = xx.i & ~0xff000000;
    expo_x = (unsigned)(-((int)expo_x));
    temp = xx.i << expo_y | ((temp) ? 1 : 0);
    xx.i = yy.i | (xx.i >> expo_x);
    if (mode == cudaRoundNearest) {
      xx.i += (temp == 0x80000000) ? (xx.i & 1) : (temp >> 31);
    } else if (mode == cudaRoundZero) {
    } else if (mode == cudaRoundPosInf) {
      xx.i += (temp && !yy.i);
    } else if (mode == cudaRoundMinInf) {
      xx.i += (temp && yy.i);
    }
    return xx.f;
  } else {

    if (!(yy.i << 1)) {
      if (mode == cudaRoundMinInf) {
        if (!(xx.i << 1)) {
          xx.i = xx.i | yy.i;
        }
      } else {
        if (xx.i == 0x80000000) {
          xx.i = yy.i;
        }
      }
      if ((xx.i << 1) > 0xff000000) {
        xx.i |= 0x00400000;
      }
      return xx.f;
    }
    if ((expo_y != 254) && (expo_x != 254)) {

      if (expo_x == (unsigned int) -1) {
        temp = xx.i & 0x80000000;
        xx.i = xx.i << 8;
        while (!(xx.i & 0x80000000)) {
          xx.i <<= 1;
          expo_x--;
        }
        expo_x++;
        xx.i = (xx.i >> 8) | temp;
      }
      if (expo_y == (unsigned int) -1) {
        temp = yy.i & 0x80000000;
        yy.i = yy.i << 8;
        while (!(yy.i & 0x80000000)) {
          yy.i <<= 1;
          expo_y--;
        }
        expo_y++;
        yy.i = (yy.i >> 8) | temp;
      }
      goto add;
    }
    expo_x = xx.i << 1;
    expo_y = yy.i << 1;

    if (expo_x > 0xff000000) {

      xx.i = xx.i | 0x00400000;
      return xx.f;
    }

    if (expo_y > 0xff000000) {

      xx.i = yy.i | 0x00400000;
      return xx.f;
    }
    if ((expo_x == 0xff000000) && (expo_y == 0xff000000)) {




      expo_x = xx.i ^ yy.i;
      xx.i = xx.i | ((expo_x) ? 0xffc00000 : 0);
      return xx.f;
    }

    if (expo_y == 0xff000000) {
      xx.i = yy.i;
    }
    return xx.f;
  }
}

static __attribute__((__unused__)) float __frcp_rn (float a)
{
  return __internal_frcp_kernel (a, cudaRoundNearest);
}

static __attribute__((__unused__)) float __frcp_rz (float a)
{
  return __internal_frcp_kernel (a, cudaRoundZero);
}

static __attribute__((__unused__)) float __frcp_rd (float a)
{
  return __internal_frcp_kernel (a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __frcp_ru (float a)
{
  return __internal_frcp_kernel (a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fsqrt_rn (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fsqrt_rz (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundZero);
}

static __attribute__((__unused__)) float __fsqrt_rd (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fsqrt_ru (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fdiv_rn (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fdiv_rz (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fdiv_rd (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fdiv_ru (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fadd_rd (float a, float b)
{
  return __internal_fadd_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fadd_ru (float a, float b)
{
  return __internal_fadd_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmul_rd (float a, float b)
{
  return __internal_fmul_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fmul_ru (float a, float b)
{
  return __internal_fmul_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmaf_rn (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fmaf_rz (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundZero);
}

static __attribute__((__unused__)) float __fmaf_ru (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmaf_rd (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundMinInf);
}

static __attribute__((__unused__)) int __cuda___isnan(double a);
static __attribute__((__unused__)) int __cuda___isnanf(float a);
static __attribute__((__unused__)) int __double2int_rz(double);
static __attribute__((__unused__)) unsigned int __double2uint_rz(double);
static __attribute__((__unused__)) long long int __double2ll_rz(double);
static __attribute__((__unused__)) unsigned long long int __double2ull_rz(double);
# 3791 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) int __mulhi(int a, int b)
{
  long long int c = (long long int)a * (long long int)b;

  return (int)(c >> 32);
}

static __attribute__((__unused__)) unsigned int __umulhi(unsigned int a, unsigned int b)
{
  unsigned long long int c = (unsigned long long int)a * (unsigned long long int)b;

  return (unsigned int)(c >> 32);
}

static __attribute__((__unused__)) unsigned long long int __umul64hi(unsigned long long int a, unsigned long long int b)
{
  unsigned int a_lo = (unsigned int)a;
  unsigned long long int a_hi = a >> 32;
  unsigned int b_lo = (unsigned int)b;
  unsigned long long int b_hi = b >> 32;
  unsigned long long int m1 = a_lo * b_hi;
  unsigned long long int m2 = a_hi * b_lo;
  unsigned int carry;

  carry = (0ULL + __umulhi(a_lo, b_lo) + (unsigned int)m1 + (unsigned int)m2) >> 32;

  return a_hi * b_hi + (m1 >> 32) + (m2 >> 32) + carry;
}

static __attribute__((__unused__)) long long int __mul64hi(long long int a, long long int b)
{
  long long int res;
  res = __umul64hi(a, b);
  if (a < 0LL) res = res - b;
  if (b < 0LL) res = res - a;
  return res;
}

static __attribute__((__unused__)) float __saturatef(float a)
{
  if (__cuda___isnanf(a)) return 0.0f;
  return a >= 1.0f ? 1.0f : a <= 0.0f ? 0.0f : a;
}

static __attribute__((__unused__)) unsigned int __sad(int a, int b, unsigned int c)
{
  long long int diff = (long long int)a - (long long int)b;

  return (unsigned int)(__cuda_llabs(diff) + (long long int)c);
}

static __attribute__((__unused__)) unsigned int __usad(unsigned int a, unsigned int b, unsigned int c)
{
  long long int diff = (long long int)a - (long long int)b;

  return (unsigned int)(__cuda_llabs(diff) + (long long int)c);
}

static __attribute__((__unused__)) int __mul24(int a, int b)
{

  a &= 0xffffff;
  a = (a & 0x800000) != 0 ? a | ~0xffffff : a;
  b &= 0xffffff;
  b = (b & 0x800000) != 0 ? b | ~0xffffff : b;


  return a * b;
}

static __attribute__((__unused__)) unsigned int __umul24(unsigned int a, unsigned int b)
{

  a &= 0xffffff;
  b &= 0xffffff;


  return a * b;
}

static __attribute__((__unused__)) float __int_as_float(int a)
{
  volatile union __cudart_FloatIntCvt u;

  u.i = a;
  return u.f;
}

static __attribute__((__unused__)) int __float_as_int(float a)
{
  volatile union __cudart_FloatIntCvt u;

  u.f = a;
  return u.i;
}

static __attribute__((__unused__)) long long int __internal_float2ll_kernel(float a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
{
  unsigned long long int res, t = 0ULL;
  int shift;
  unsigned int ia;

  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= min) return min;
  ia = __float_as_int(a);
  shift = 189 - ((ia >> 23) & 0xff);
  res = (unsigned long long int)(((ia << 8) | 0x80000000) >> 1) << 32;
  if (shift >= 64) {
    t = res;
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (rndMode == cudaRoundNearest && (long long int)t < 0LL) {
    res += t == 0x8000000000000000ULL ? res & 1ULL : 1ULL;
  }
  else if (rndMode == cudaRoundMinInf && t != 0ULL && ia > 0x80000000) {
    res++;
  }
  else if (rndMode == cudaRoundPosInf && t != 0ULL && (int)ia > 0) {
    res++;
  }
  if ((int)ia < 0) res = (unsigned long long int)-(long long int)res;
  return (long long int)res;
}

static __attribute__((__unused__)) int __internal_float2int(float a, enum cudaRoundMode rndMode)
{
  return (int)__internal_float2ll_kernel(a, 2147483647LL, -2147483648LL, 0LL, rndMode);
}

static __attribute__((__unused__)) int __float2int_rz(float a)
{



  return __internal_float2int(a, cudaRoundZero);

}

static __attribute__((__unused__)) int __float2int_ru(float a)
{
  return __internal_float2int(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) int __float2int_rd(float a)
{
  return __internal_float2int(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) int __float2int_rn(float a)
{
  return __internal_float2int(a, cudaRoundNearest);
}

static __attribute__((__unused__)) long long int __internal_float2ll(float a, enum cudaRoundMode rndMode)
{
  return __internal_float2ll_kernel(a, 9223372036854775807LL, -9223372036854775807LL -1LL, -9223372036854775807LL -1LL, rndMode);
}

static __attribute__((__unused__)) long long int __float2ll_rz(float a)
{



  return __internal_float2ll(a, cudaRoundZero);

}

static __attribute__((__unused__)) long long int __float2ll_ru(float a)
{
  return __internal_float2ll(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) long long int __float2ll_rd(float a)
{
  return __internal_float2ll(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) long long int __float2ll_rn(float a)
{
  return __internal_float2ll(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __internal_float2ull_kernel(float a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
{
  unsigned long long int res, t = 0ULL;
  int shift;
  unsigned int ia;

  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= 0LL) return 0LL;
  ia = __float_as_int(a);
  shift = 190 - ((ia >> 23) & 0xff);
  res = (unsigned long long int)((ia << 8) | 0x80000000) << 32;
  if (shift >= 64) {
    t = res >> (int)(shift > 64);
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (rndMode == cudaRoundNearest && (long long int)t < 0LL) {
    res += t == 0x8000000000000000ULL ? res & 1ULL : 1ULL;
  }
  else if (rndMode == cudaRoundPosInf && t != 0ULL) {
    res++;
  }
  return res;
}

static __attribute__((__unused__)) unsigned int __internal_float2uint(float a, enum cudaRoundMode rndMode)
{
  return (unsigned int)__internal_float2ull_kernel(a, 4294967295U, 0U, rndMode);
}

static __attribute__((__unused__)) unsigned int __float2uint_rz(float a)
{



  return __internal_float2uint(a, cudaRoundZero);

}

static __attribute__((__unused__)) unsigned int __float2uint_ru(float a)
{
  return __internal_float2uint(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned int __float2uint_rd(float a)
{
  return __internal_float2uint(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned int __float2uint_rn(float a)
{
  return __internal_float2uint(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __internal_float2ull(float a, enum cudaRoundMode rndMode)
{
  return __internal_float2ull_kernel(a, 18446744073709551615ULL, 9223372036854775808ULL, rndMode);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rz(float a)
{



  return __internal_float2ull(a, cudaRoundZero);

}

static __attribute__((__unused__)) unsigned long long int __float2ull_ru(float a)
{
  return __internal_float2ull(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rd(float a)
{
  return __internal_float2ull(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rn(float a)
{
  return __internal_float2ull(a, cudaRoundNearest);
}

static __attribute__((__unused__)) int __internal_normalize64(unsigned long long int *a)
{
  int lz = 0;

  if ((*a & 0xffffffff00000000ULL) == 0ULL) {
    *a <<= 32;
    lz += 32;
  }
  if ((*a & 0xffff000000000000ULL) == 0ULL) {
    *a <<= 16;
    lz += 16;
  }
  if ((*a & 0xff00000000000000ULL) == 0ULL) {
    *a <<= 8;
    lz += 8;
  }
  if ((*a & 0xf000000000000000ULL) == 0ULL) {
    *a <<= 4;
    lz += 4;
  }
  if ((*a & 0xC000000000000000ULL) == 0ULL) {
    *a <<= 2;
    lz += 2;
  }
  if ((*a & 0x8000000000000000ULL) == 0ULL) {
    *a <<= 1;
    lz += 1;
  }
  return lz;
}

static __attribute__((__unused__)) int __internal_normalize(unsigned int *a)
{
  unsigned long long int t = (unsigned long long int)*a;
  int lz = __internal_normalize64(&t);

  *a = (unsigned int)(t >> 32);

  return lz - 32;
}

static __attribute__((__unused__)) float __internal_int2float_kernel(int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_FloatUintCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.f;
  if (a < 0) res.i = (unsigned int)-a;
  shift = __internal_normalize((unsigned int*)&res.i);
  t = res.i << 24;
  res.i = (res.i >> 8);
  res.i += (127 + 30 - shift) << 23;
  if (a < 0) res.i |= 0x80000000;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : (t >> 31);
  }
  else if ((rndMode == cudaRoundMinInf) && t && (a < 0)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && (a > 0)) {
    res.i++;
  }
  return res.f;
}

static __attribute__((__unused__)) float __int2float_rz(int a)
{
  return __internal_int2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __int2float_ru(int a)
{
  return __internal_int2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __int2float_rd(int a)
{
  return __internal_int2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __int2float_rn(int a)
{



  return __internal_int2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) float __internal_uint2float_kernel(unsigned int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_FloatUintCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.f;
  shift = __internal_normalize((unsigned int*)&res.i);
  t = res.i << 24;
  res.i = (res.i >> 8);
  res.i += (127 + 30 - shift) << 23;
  if (rndMode == cudaRoundNearest) {
    res.i += (t == 0x80000000) ? (res.i & 1) : (t >> 31);
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.f;
}

static __attribute__((__unused__)) float __uint2float_rz(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __uint2float_ru(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __uint2float_rd(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __uint2float_rn(unsigned int a)
{



  return __internal_uint2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) float __internal_ull2float_kernel(unsigned long long int a, enum cudaRoundMode rndMode)
{
  unsigned long long int temp;
  unsigned int res, t;
  int shift;
  if (a == 0ULL) return 0.0f;
  temp = a;
  shift = __internal_normalize64(&temp);
  temp = (temp >> 8) | ((temp & 0xffULL) ? 1ULL : 0ULL);
  res = (unsigned int)(temp >> 32);
  t = (unsigned int)temp;
  res += (127 + 62 - shift) << 23;
  if (rndMode == cudaRoundNearest) {
    res += (t == 0x80000000) ? (res & 1) : (t >> 31);
  } else if (rndMode == cudaRoundPosInf) {
    res += (t != 0);
  }
  return __int_as_float(res);
}

static __attribute__((__unused__)) float __internal_ll2float_kernel(long long int a, enum cudaRoundMode rndMode)
{
  unsigned long long int temp;
  volatile float res = 0.0f;

  if (a < 0LL) {
    temp = (~((unsigned long long int)a)) + 1ULL;
    if (rndMode == cudaRoundPosInf) {
      rndMode = cudaRoundMinInf;
    } else if (rndMode == cudaRoundMinInf) {
      rndMode = cudaRoundPosInf;
    }
  } else {
    temp = (unsigned long long int)a;
  }
  res = __internal_ull2float_kernel (temp, rndMode);
  if (a < 0LL) {
    res = -res;
  }
  return res;
}

static __attribute__((__unused__)) float __ll2float_rn(long long int a)
{



  return __internal_ll2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) float __ll2float_rz(long long int a)
{
  return __internal_ll2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __ll2float_ru(long long int a)
{
  return __internal_ll2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __ll2float_rd(long long int a)
{
  return __internal_ll2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __ull2float_rn(unsigned long long int a)
{



  return __internal_ull2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) float __ull2float_rz(unsigned long long int a)
{
  return __internal_ull2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __ull2float_ru(unsigned long long int a)
{
  return __internal_ull2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __ull2float_rd(unsigned long long int a)
{
  return __internal_ull2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned short __float2half_rn(float f)
{
  unsigned int x = __float_as_int (f);
  unsigned int u = (x & 0x7fffffff), remainder, shift, lsb, lsb_s1, lsb_m1;
  unsigned int sign, exponent, mantissa;


  if (u > 0x7f800000) {
    return 0x7fff;
  }

  sign = ((x >> 16) & 0x8000);


  if (u > 0x477fefff) {
    return sign | 0x7c00;
  }
  if (u < 0x33000001) {
    return sign | 0x0000;
  }

  exponent = ((u >> 23) & 0xff);
  mantissa = (u & 0x7fffff);

  if (exponent > 0x70) {
    shift = 13;
    exponent -= 0x70;
  } else {
    shift = 0x7e - exponent;
    exponent = 0;
    mantissa |= 0x800000;
  }
  lsb = (1 << shift);
  lsb_s1 = (lsb >> 1);
  lsb_m1 = (lsb - 1);


  remainder = (mantissa & lsb_m1);
  mantissa >>= shift;
  if (remainder > lsb_s1 || (remainder == lsb_s1 && (mantissa & 0x1))) {
    ++mantissa;
    if (!(mantissa & 0x3ff)) {
      ++exponent;
      mantissa = 0;
    }
  }

  return sign | (exponent << 10) | mantissa;
}

static __attribute__((__unused__)) float __half2float(unsigned short h)
{
  unsigned int sign = ((h >> 15) & 1);
  unsigned int exponent = ((h >> 10) & 0x1f);
  unsigned int mantissa = ((h & 0x3ff) << 13);

  if (exponent == 0x1f) {
    mantissa = (mantissa
                ? (sign = 0, 0x7fffff)
                : 0);
    exponent = 0xff;
  } else if (!exponent) {
    if (mantissa) {
      unsigned int msb;
      exponent = 0x71;
      do {
        msb = (mantissa & 0x400000);
        mantissa <<= 1;
        --exponent;
      } while (!msb);
      mantissa &= 0x7fffff;
    }
  } else {
    exponent += 0x70;
  }

  return __int_as_float ((sign << 31) | (exponent << 23) | mantissa);
}

static __attribute__((__unused__)) float __fadd_rz(float a, float b)
{
  return __internal_fadd_kernel(a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fmul_rz(float a, float b)
{
  return __internal_fmul_kernel(a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fadd_rn(float a, float b)
{
  return __internal_fadd_kernel(a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fmul_rn(float a, float b)
{
  return __internal_fmul_kernel(a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) void __brkpt(int c)
{

}
# 4395 "/usr/local/cuda/bin/../include/device_functions.h" 3
extern "C" {


extern int __cudaSynchronizeThreads(void**, void*);


}




static __attribute__((__unused__)) inline __attribute__((always_inline)) void __syncthreads(void)
{
  volatile int _ = 0;
  L: if (__cudaSynchronizeThreads((void**)&&L, (void*)&_)) goto L;
}
# 4421 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) void __prof_trigger(int a)
{
}

static __attribute__((__unused__)) void __threadfence(void)
{
  __syncthreads();
}

static __attribute__((__unused__)) void __threadfence_block(void)
{
  __syncthreads();
}

static __attribute__((__unused__)) void __synchronous_start(int s)
{

}

static __attribute__((__unused__)) void __synchronous_end(void)
{

}



static __attribute__((__unused__)) void __trap(void)
{
  __builtin_trap();
}
# 4469 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) float __fdividef(float a, float b)
{



  volatile float aa = a;
  volatile float bb = b;

  if (__cuda_fabsf(bb) > 8.507059173e37f) {
    if (__cuda_fabsf(aa) <= 3.402823466e38f) {
      return ((aa / bb) / 3.402823466e38f) / 3.402823466e38f;
    } else {
      bb = 1.0f / bb;
      bb = bb / 3.402823466e38f;
      return aa * bb;
    }
  } else {
    return aa / bb;
  }

}


static __attribute__((__unused__)) float __sinf(float a)
{

  if ((__float_as_int(a) << 1) == 0xff000000) {
    return __fadd_rn (a, -a);
  }

  return sinf(a);
}

static __attribute__((__unused__)) float __cosf(float a)
{

  if ((__float_as_int(a) << 1) == 0xff000000) {
    return __fadd_rn (a, -a);
  }

  return cosf(a);
}

static __attribute__((__unused__)) float __log2f(float a)
{
  return log2f(a);
}






static __attribute__((__unused__)) float __tanf(float a)
{



  return __fdividef (__sinf(a), __cosf(a));

}

static __attribute__((__unused__)) void __sincosf(float a, float *sptr, float *cptr)
{



  *sptr = __sinf(a);
  *cptr = __cosf(a);

}

static __attribute__((__unused__)) float __expf(float a)
{



  return __cuda_exp2f(a * 1.442695041f);

}

static __attribute__((__unused__)) float __exp10f(float a)
{



  return __cuda_exp2f(a * 3.321928094f);

}

static __attribute__((__unused__)) float __log10f(float a)
{



  return 0.301029996f * __log2f(a);

}

static __attribute__((__unused__)) float __logf(float a)
{



  return 0.693147181f * __log2f(a);

}

static __attribute__((__unused__)) float __powf(float a, float b)
{



  return __cuda_exp2f(b * __log2f(a));

}

static __attribute__((__unused__)) float fdividef(float a, float b)
{



  return a / b;

}



static __attribute__((__unused__)) int __clz(int a)
{
  return (a)?(158-(__float_as_int(__uint2float_rz((unsigned int)a))>>23)):32;
}

static __attribute__((__unused__)) int __clzll(long long int a)
{
  int ahi = ((int)((unsigned long long)a >> 32));
  int alo = ((int)((unsigned long long)a & 0xffffffffULL));
  int res;
  if (ahi) {
    res = 0;
  } else {
    res = 32;
    ahi = alo;
  }
  res = res + __clz(ahi);
  return res;
}

static __attribute__((__unused__)) int __popc(unsigned int a)
{
  a = a - ((a >> 1) & 0x55555555);
  a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
  a = (a + (a >> 4)) & 0x0f0f0f0f;
  a = ((__umul24(a, 0x808080) << 1) + a) >> 24;
  return a;
}

static __attribute__((__unused__)) int __popcll(unsigned long long int a)
{
  unsigned int ahi = ((unsigned int)(a >> 32));
  unsigned int alo = ((unsigned int)(a & 0xffffffffULL));
  alo = alo - ((alo >> 1) & 0x55555555);
  alo = (alo & 0x33333333) + ((alo >> 2) & 0x33333333);
  ahi = ahi - ((ahi >> 1) & 0x55555555);
  ahi = (ahi & 0x33333333) + ((ahi >> 2) & 0x33333333);
  alo = alo + ahi;
  alo = (alo & 0x0f0f0f0f) + ((alo >> 4) & 0x0f0f0f0f);
  alo = ((__umul24(alo, 0x808080) << 1) + alo) >> 24;
  return alo;
}

static __attribute__((__unused__)) unsigned int __brev(unsigned int a)
{

  unsigned int t;
  a = (a << 15) | (a >> 17);
  t = (a ^ (a >> 10)) & 0x003f801f;
  a = (t + (t << 10)) ^ a;
  t = (a ^ (a >> 4)) & 0x0e038421;
  a = (t + (t << 4)) ^ a;
  t = (a ^ (a >> 2)) & 0x22488842;
  a = (t + (t << 2)) ^ a;
  return a;
}

static __attribute__((__unused__)) unsigned long long int __brevll(unsigned long long int a)
{
  unsigned int hi = (unsigned int)(a >> 32);
  unsigned int lo = (unsigned int)(a & 0xffffffffULL);
  unsigned int t;
  t = __brev(lo);
  lo = __brev(hi);
  return ((unsigned long long int)t << 32) + (unsigned long long int)lo;
}



static __attribute__((__unused__)) int __ffs(int a)
{
  return 32 - __clz (a & -a);
}

static __attribute__((__unused__)) int __ffsll(long long int a)
{
  return 64 - __clzll (a & -a);
}
# 4717 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) double fdivide(double a, double b)
{
  return a / b;
}



static __attribute__((__unused__)) int __internal_double2int(double a, enum cudaRoundMode rndMode);
static __attribute__((__unused__)) unsigned int __internal_double2uint(double a, enum cudaRoundMode rndMode);
static __attribute__((__unused__)) long long int __internal_double2ll(double a, enum cudaRoundMode rndMode);
static __attribute__((__unused__)) unsigned long long int __internal_double2ull(double a, enum cudaRoundMode rndMode);

static __attribute__((__unused__)) int __double2int_rz(double a)
{
  return __internal_double2int(a, cudaRoundZero);
}

static __attribute__((__unused__)) unsigned int __double2uint_rz(double a)
{
  return __internal_double2uint(a, cudaRoundZero);
}

static __attribute__((__unused__)) long long int __double2ll_rz(double a)
{
  return __internal_double2ll(a, cudaRoundZero);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rz(double a)
{
  return __internal_double2ull(a, cudaRoundZero);
}
# 4761 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 1 3
# 258 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 3
extern "C" {


extern void __cudaMutexOperation(int lock);


}







static __attribute__((__unused__)) int __iAtomicAdd(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicAdd(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicExch(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicExch(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) float __fAtomicExch(float *address, float val)
{
  float old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicMin(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old < val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicMin(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old < val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicMax(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old > val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicMax(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old > val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicInc(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = (old >= val) ? 0 : old + 1; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicDec(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = ((old == 0) | (old > val)) ? val : (old - 1); __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicAnd(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old & val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicAnd(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old & val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicOr(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old | val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicOr(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old | val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicXor(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old ^ val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicXor(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old ^ val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicCAS(int *address, int compare, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicCAS(unsigned int *address, unsigned int compare, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);




  return old;
}
# 4762 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 1 3
# 119 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 3
extern "C" {


extern void __cudaMutexOperation(int lock);


}







static __attribute__((__unused__)) unsigned long long int __ullAtomicAdd(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned long long int __ullAtomicExch(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned long long int __ullAtomicCAS(unsigned long long int *address, unsigned long long int compare, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);



  return old;
}





static __attribute__((__unused__)) int __any(int cond)
{
  return cond;
}

static __attribute__((__unused__)) int __all(int cond)
{
  return cond;
}
# 4763 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 1 3
# 272 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
static __attribute__((__unused__)) double __longlong_as_double(long long int a)
{
  volatile union __cudart_DoubleLonglongCvt u;
  u.i = a;
  return u.d;
}

static __attribute__((__unused__)) long long int __double_as_longlong(double a)
{
  volatile union __cudart_DoubleLonglongCvt u;
  u.d = a;
  return u.i;
}


static __attribute__((__unused__)) float __internal_double2float_kernel(double a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt xx;
  volatile union __cudart_FloatUintCvt res;

  unsigned long long sticky;
  int shift;
  xx.d = a;
  res.i = (((unsigned int) (xx.i >> 32)) & 0x80000000);
  if (a == 0.0) {

    return res.f;
  }
  if ((xx.i & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) {
    if ((xx.i & 0x7fffffffffffffffULL) > 0x7ff0000000000000ULL) {

      res.i = ((unsigned int)((xx.i >> 32) & 0x80000000) |
               (255U << 23) | 0x00400000 |
               (unsigned int)((xx.i >> (53 - 24)) & 0x007fffff));
    } else {

      res.i |= 0x7f800000;
    }
    return res.f;
  }
  shift = ((int) ((xx.i >> 52) & 0x7ff)) - 1023;

  xx.i = (xx.i & 0x000fffffffffffffULL);
  if (shift >= 128) {
    if ((rndMode == cudaRoundZero) ||
        ((rndMode == cudaRoundMinInf) && !res.i) ||
        ((rndMode == cudaRoundPosInf) && res.i)) {
      res.i |= 0x7f7fffff;
    } else {
      res.i |= 0x7f800000;
    }
    return res.f;
  }
  if (shift <= -127) {

    xx.i |= 0x0010000000000000ULL;
    if (shift < -180) {
      sticky = xx.i;
      xx.i = 0;
    } else {
      sticky = xx.i << (64 - (-126 - shift));
      xx.i >>= (-126 - shift);
    }
    sticky |= xx.i << (64 - 29);
    if ((((rndMode == cudaRoundPosInf) && !res.i) ||
         ((rndMode == cudaRoundMinInf) && res.i)) &&
        sticky) {
      res.i += 1;
    }
    res.i += ((unsigned int) (xx.i >> 29)) & 0x007fffff;
    return res.f;
  }
  sticky = xx.i << (64 - 29);
  if ((((rndMode == cudaRoundPosInf) && !res.i) ||
       ((rndMode == cudaRoundMinInf) && res.i)) &&
      sticky) {
    res.i += 1;
  }
  res.i += ((unsigned int) (xx.i >> 29)) & 0x007fffff;
  res.i += (unsigned int) (127 + shift) << 23;
  return res.f;
}

static __attribute__((__unused__)) double __internal_ll2double_kernel(long long int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.d;
  if (a < 0) res.i = (unsigned long long int)-a;
  shift = __internal_normalize64((unsigned long long int*)&res.i);
  t = ((unsigned int) res.i) << 21;
  res.i >>= 11;
  res.i += ((unsigned long long int)(1023 + 62 - shift)) << 52;
  if (a < 0) res.i |= 0x8000000000000000ULL;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundMinInf) && t && (a < 0)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && (a > 0)) {
    res.i++;
  }
  return res.d;
}

static __attribute__((__unused__)) double __internal_ull2double_kernel(unsigned long long int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.d;
  shift = __internal_normalize64((unsigned long long int *)&res.i);
  t = ((unsigned int) res.i) << 21;
  res.i >>= 11;
  res.i += ((unsigned long long int)(1023 + 62 - shift)) << 52;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.d;
}

static __attribute__((__unused__)) long long int __internal_double2ll_kernel(double a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt xx, res;
  unsigned long long int t = 0;
  int shift;

  xx.d = a;
  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= min) return min;
  shift = (int) (1023 + 62 - ((xx.i >> 52) & 0x7ff));
  res.i = ((xx.i << 11) | 0x8000000000000000ULL) >> 1;
  if (shift >= 64) {
    t = res.i;
    res.i = 0;
  } else if (shift) {
    t = res.i << (64 - shift);
    res.i = res.i >> shift;
  }
  if ((rndMode == cudaRoundNearest) && (t >= 0x8000000000000000ULL)) {
    res.i += (t == 0x8000000000000000ULL) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundMinInf) && t &&
          (xx.i > 0x8000000000000000ULL)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && ((long long int)xx.i > 0)) {
    res.i++;
  }
  if ((long long int)xx.i < 0) {
    res.i = (unsigned long long int)(-(long long int)res.i);
  }
  return res.i;
}

static __attribute__((__unused__)) unsigned long long int __internal_double2ull_kernel(double a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt xx, res;
  unsigned long long int t = 0;
  int shift;

  xx.d = a;
  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= 0LL) return 0LL;

  if (a == 0.0) return 0LL;
  shift = (int) (1023 + 63 - ((xx.i >> 52) & 0x7ff));
  res.i = ((xx.i << 11) | 0x8000000000000000ULL);
  if (shift >= 64) {
    t = res.i >> (int)(shift > 64);
    res.i = 0;
  } else if (shift) {
    t = res.i << (64 - shift);
    res.i = res.i >> shift;
  }
  if ((rndMode == cudaRoundNearest) && (t >= 0x8000000000000000ULL)) {
    res.i += (t == 0x8000000000000000ULL) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.i;
}

static __attribute__((__unused__)) int __double2hiint(double a)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.d = a;
  return cvt.i[1];
}

static __attribute__((__unused__)) int __double2loint(double a)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.d = a;
  return cvt.i[0];
}

static __attribute__((__unused__)) double __hiloint2double(int a, int b)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.i[0] = b;
  cvt.i[1] = a;
  return cvt.d;
}

static __attribute__((__unused__)) float __double2float_rn(double a)
{
  return (float)a;
}

static __attribute__((__unused__)) float __double2float_rz(double a)
{
  return __internal_double2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __double2float_ru(double a)
{
  return __internal_double2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __double2float_rd(double a)
{
  return __internal_double2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) int __internal_double2int(double a, enum cudaRoundMode rndMode)
{
  return (int)__internal_double2ll_kernel(a, 2147483647LL, -2147483648LL, -2147483648LL, rndMode);
}

static __attribute__((__unused__)) int __double2int_rn(double a)
{
  return __internal_double2int(a, cudaRoundNearest);
}

static __attribute__((__unused__)) int __double2int_ru(double a)
{
  return __internal_double2int(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) int __double2int_rd(double a)
{
  return __internal_double2int(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned int __internal_double2uint(double a, enum cudaRoundMode rndMode)
{
  return (unsigned int)__internal_double2ull_kernel(a, 4294967295ULL, 2147483648ULL, rndMode);
}

static __attribute__((__unused__)) unsigned int __double2uint_rn(double a)
{
  return __internal_double2uint(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned int __double2uint_ru(double a)
{
  return __internal_double2uint(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned int __double2uint_rd(double a)
{
  return __internal_double2uint(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) long long int __internal_double2ll(double a, enum cudaRoundMode rndMode)
{
  return __internal_double2ll_kernel(a, 9223372036854775807LL, -9223372036854775807LL -1LL, -9223372036854775807LL -1LL, rndMode);
}

static __attribute__((__unused__)) long long int __double2ll_rn(double a)
{
  return __internal_double2ll(a, cudaRoundNearest);
}

static __attribute__((__unused__)) long long int __double2ll_ru(double a)
{
  return __internal_double2ll(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) long long int __double2ll_rd(double a)
{
  return __internal_double2ll(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned long long int __internal_double2ull(double a, enum cudaRoundMode rndMode)
{
  return __internal_double2ull_kernel(a, 18446744073709551615ULL, 9223372036854775808ULL, rndMode);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rn(double a)
{
  return __internal_double2ull(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_ru(double a)
{
  return __internal_double2ull(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rd(double a)
{
  return __internal_double2ull(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __int2double_rn(int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __uint2double_rn(unsigned int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __ll2double_rn(long long int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __ll2double_rz(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) double __ll2double_rd(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __ll2double_ru(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __ull2double_rn(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundNearest);
}

static __attribute__((__unused__)) double __ull2double_rz(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) double __ull2double_rd(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __ull2double_ru(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundPosInf);
}







static __attribute__((__unused__)) double __internal_fma_kernel(double x, double y, double z, enum cudaRoundMode rndMode)
{



  struct __cudart_UintUint xx, yy, zz, ww;
  unsigned int s, t, u, prod0, prod1, prod2, prod3, expo_x, expo_y, expo_z;

  xx.hi = __double2hiint(x);
  xx.lo = __double2loint(x);
  yy.hi = __double2hiint(y);
  yy.lo = __double2loint(y);
  zz.hi = __double2hiint(z);
  zz.lo = __double2loint(z);

  expo_z = 0x7FF;
  t = xx.hi >> 20;
  expo_x = expo_z & t;
  expo_x = expo_x - 1;
  t = yy.hi >> 20;
  expo_y = expo_z & t;
  expo_y = expo_y - 1;
  t = zz.hi >> 20;
  expo_z = expo_z & t;
  expo_z = expo_z - 1;

  if (!((expo_x <= 0x7FD) &&
        (expo_y <= 0x7FD) &&
        (expo_z <= 0x7FD))) {





    if (((yy.hi << 1) | (yy.lo != 0)) > 0xffe00000) {
      yy.hi |= 0x00080000;
      return __hiloint2double(yy.hi, yy.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) > 0xffe00000) {
      zz.hi |= 0x00080000;
      return __hiloint2double(zz.hi, zz.lo);
    }
    if (((xx.hi << 1) | (xx.lo != 0)) > 0xffe00000) {
      xx.hi |= 0x00080000;
      return __hiloint2double(xx.hi, xx.lo);
    }
# 700 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
    if (((((xx.hi << 1) | xx.lo) == 0) &&
         (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000)) ||
        ((((yy.hi << 1) | yy.lo) == 0) &&
         (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000))) {
      xx.hi = 0xfff80000;
      xx.lo = 0x00000000;
      return __hiloint2double(xx.hi, xx.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      if ((((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) ||
          (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000)) {
        if ((int)(xx.hi ^ yy.hi ^ zz.hi) < 0) {
          xx.hi = 0xfff80000;
          xx.lo = 0x00000000;
          return __hiloint2double(xx.hi, xx.lo);
        }
      }
    }




    if (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000) {
      xx.hi = xx.hi ^ (yy.hi & 0x80000000);
      return __hiloint2double(xx.hi, xx.lo);
    }
    if (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) {
      yy.hi = yy.hi ^ (xx.hi & 0x80000000);
      return __hiloint2double(yy.hi, yy.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      return __hiloint2double(zz.hi, zz.lo);
    }





    if ((zz.hi == 0x80000000) && (zz.lo == 0)) {
      if ((((xx.hi << 1) | xx.lo) == 0) ||
          (((yy.hi << 1) | yy.lo) == 0)) {
        if ((int)(xx.hi ^ yy.hi) < 0) {
          return __hiloint2double(zz.hi, zz.lo);
        }
      }
    }



    if ((((zz.hi << 1) | zz.lo) == 0) &&
        ((((xx.hi << 1) | xx.lo) == 0) ||
         (((yy.hi << 1) | yy.lo) == 0))) {
      if (rndMode == cudaRoundMinInf) {
        return __hiloint2double((xx.hi ^ yy.hi ^ zz.hi) & 0x80000000, zz.lo);
      } else {
        zz.hi &= 0x7fffffff;
        return __hiloint2double(zz.hi, zz.lo);
      }
    }




    if ((((xx.hi << 1) | xx.lo) == 0) ||
        (((yy.hi << 1) | yy.lo) == 0)) {
      return __hiloint2double(zz.hi, zz.lo);
    }

    if (expo_x == 0xffffffff) {
      expo_x++;
      t = xx.hi & 0x80000000;
      s = xx.lo >> 21;
      xx.lo = xx.lo << 11;
      xx.hi = xx.hi << 11;
      xx.hi = xx.hi | s;
      if (!xx.hi) {
        xx.hi = xx.lo;
        xx.lo = 0;
        expo_x -= 32;
      }
      while ((int)xx.hi > 0) {
        s = xx.lo >> 31;
        xx.lo = xx.lo + xx.lo;
        xx.hi = xx.hi + xx.hi;
        xx.hi = xx.hi | s;
        expo_x--;
      }
      xx.lo = (xx.lo >> 11);
      xx.lo |= (xx.hi << 21);
      xx.hi = (xx.hi >> 11) | t;
    }
    if (expo_y == 0xffffffff) {
      expo_y++;
      t = yy.hi & 0x80000000;
      s = yy.lo >> 21;
      yy.lo = yy.lo << 11;
      yy.hi = yy.hi << 11;
      yy.hi = yy.hi | s;
      if (!yy.hi) {
        yy.hi = yy.lo;
        yy.lo = 0;
        expo_y -= 32;
      }
      while ((int)yy.hi > 0) {
        s = yy.lo >> 31;
        yy.lo = yy.lo + yy.lo;
        yy.hi = yy.hi + yy.hi;
        yy.hi = yy.hi | s;
        expo_y--;
      }
      yy.lo = (yy.lo >> 11);
      yy.lo |= (yy.hi << 21);
      yy.hi = (yy.hi >> 11) | t;
    }
    if (expo_z == 0xffffffff) {
      expo_z++;
      t = zz.hi & 0x80000000;
      s = zz.lo >> 21;
      zz.lo = zz.lo << 11;
      zz.hi = zz.hi << 11;
      zz.hi = zz.hi | s;
      if (!zz.hi) {
        zz.hi = zz.lo;
        zz.lo = 0;
        expo_z -= 32;
      }
      while ((int)zz.hi > 0) {
        s = zz.lo >> 31;
        zz.lo = zz.lo + zz.lo;
        zz.hi = zz.hi + zz.hi;
        zz.hi = zz.hi | s;
        expo_z--;
      }
      zz.lo = (zz.lo >> 11);
      zz.lo |= (zz.hi << 21);
      zz.hi = (zz.hi >> 11) | t;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx.hi ^ yy.hi;
  t = xx.lo >> 21;
  xx.lo = xx.lo << 11;
  xx.hi = xx.hi << 11;
  xx.hi = xx.hi | t;
  yy.hi = yy.hi & 0x000fffff;
  xx.hi = xx.hi | 0x80000000;
  yy.hi = yy.hi | 0x00100000;

  prod0 = xx.lo * yy.lo;
  prod1 = __umulhi (xx.lo, yy.lo);
  prod2 = xx.hi * yy.lo;
  prod3 = xx.lo * yy.hi;
  prod1 += prod2;
  t = prod1 < prod2;
  prod1 += prod3;
  t += prod1 < prod3;
  prod2 = __umulhi (xx.hi, yy.lo);
  prod3 = __umulhi (xx.lo, yy.hi);
  prod2 += prod3;
  s = prod2 < prod3;
  prod3 = xx.hi * yy.hi;
  prod2 += prod3;
  s += prod2 < prod3;
  prod2 += t;
  s += prod2 < t;
  prod3 = __umulhi (xx.hi, yy.hi) + s;

  yy.lo = prod0;
  yy.hi = prod1;
  xx.lo = prod2;
  xx.hi = prod3;
  expo_x = expo_x - (1023 - 2);
  expo_y = expo_y & 0x80000000;

  if (xx.hi < 0x00100000) {
    s = xx.lo >> 31;
    s = (xx.hi << 1) + s;
    xx.hi = s;
    s = yy.hi >> 31;
    s = (xx.lo << 1) + s;
    xx.lo = s;
    s = yy.lo >> 31;
    s = (yy.hi << 1) + s;
    yy.hi = s;
    s = yy.lo << 1;
    yy.lo = s;
    expo_x--;
  }

  t = 0;
  if (((zz.hi << 1) | zz.lo) != 0) {

    s = zz.hi & 0x80000000;

    zz.hi &= 0x000fffff;
    zz.hi |= 0x00100000;
    ww.hi = 0;
    ww.lo = 0;


    if ((int)expo_z > (int)expo_x) {
      t = expo_z;
      expo_z = expo_x;
      expo_x = t;
      t = zz.hi;
      zz.hi = xx.hi;
      xx.hi = t;
      t = zz.lo;
      zz.lo = xx.lo;
      xx.lo = t;
      t = ww.hi;
      ww.hi = yy.hi;
      yy.hi = t;
      t = ww.lo;
      ww.lo = yy.lo;
      yy.lo = t;
      t = expo_y;
      expo_y = s;
      s = t;
    }



    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 107) {

      t = 0;
      while (expo_z >= 32) {
        t = ww.lo | (t != 0);
        ww.lo = ww.hi;
        ww.hi = zz.lo;
        zz.lo = zz.hi;
        zz.hi = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        t = (t >> expo_z) | (ww.lo << (32 - expo_z)) |
                ((t << (32 - expo_z)) != 0);
        ww.lo = (ww.lo >> expo_z) | (ww.hi << (32 - expo_z));
        ww.hi = (ww.hi >> expo_z) | (zz.lo << (32 - expo_z));
        zz.lo = (zz.lo >> expo_z) | (zz.hi << (32 - expo_z));
        zz.hi = (zz.hi >> expo_z);
      }
    } else {
      t = 1;
      ww.lo = 0;
      ww.hi = 0;
      zz.lo = 0;
      zz.hi = 0;
    }
    if ((int)u < 0) {

      t = (unsigned)(-(int)t);
      s = (t != 0);
      u = yy.lo - s;
      s = u > yy.lo;
      yy.lo = u - ww.lo;
      s += yy.lo > u;
      u = yy.hi - s;
      s = u > yy.hi;
      yy.hi = u - ww.hi;
      s += yy.hi > u;
      u = xx.lo - s;
      s = u > xx.lo;
      xx.lo = u - zz.lo;
      s += xx.lo > u;
      xx.hi = (xx.hi - zz.hi) - s;
      if (!(xx.hi | xx.lo | yy.hi | yy.lo | t)) {

        if (rndMode == cudaRoundMinInf) {
          return __hiloint2double(0x80000000, xx.lo);
        } else {
          return __hiloint2double(xx.hi, xx.lo);
        }
      }
      if ((int)xx.hi < 0) {



        t = ~t;
        yy.lo = ~yy.lo;
        yy.hi = ~yy.hi;
        xx.lo = ~xx.lo;
        xx.hi = ~xx.hi;
        if (++t == 0) {
          if (++yy.lo == 0) {
            if (++yy.hi == 0) {
              if (++xx.lo == 0) {
              ++xx.hi;
              }
            }
          }
        }
        expo_y ^= 0x80000000;
      }


      while (!(xx.hi & 0x00100000)) {
        xx.hi = (xx.hi << 1) | (xx.lo >> 31);
        xx.lo = (xx.lo << 1) | (yy.hi >> 31);
        yy.hi = (yy.hi << 1) | (yy.lo >> 31);
        yy.lo = (yy.lo << 1);
        expo_x--;
      }
    } else {

      yy.lo = yy.lo + ww.lo;
      s = yy.lo < ww.lo;
      yy.hi = yy.hi + s;
      u = yy.hi < s;
      yy.hi = yy.hi + ww.hi;
      u += yy.hi < ww.hi;
      xx.lo = xx.lo + u;
      s = xx.lo < u;
      xx.lo = xx.lo + zz.lo;
      s += xx.lo < zz.lo;
      xx.hi = xx.hi + zz.hi + s;
      if (xx.hi & 0x00200000) {
        t = t | (yy.lo << 31);
        yy.lo = (yy.lo >> 1) | (yy.hi << 31);
        yy.hi = (yy.hi >> 1) | (xx.lo << 31);
        xx.lo = (xx.lo >> 1) | (xx.hi << 31);
        xx.hi = ((xx.hi & 0x80000000) | (xx.hi >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  t = yy.lo | (t != 0);
  t = yy.hi | (t != 0);

  xx.hi |= expo_y;
  if (expo_x <= 0x7FD) {

    xx.hi = xx.hi & ~0x00100000;
    s = xx.lo & 1;
    u = xx.lo;
    if (rndMode == cudaRoundNearest) {
      xx.lo += (t == 0x80000000) ? s : (t >> 31);
    } else if (((rndMode == cudaRoundPosInf) && t && (!expo_y)) ||
               ((rndMode == cudaRoundMinInf) && t && expo_y)) {
      xx.lo += 1;
    }
    xx.hi += (u > xx.lo);
    xx.hi += ((expo_x + 1) << 20);
    return __hiloint2double(xx.hi, xx.lo);
  } else if ((int)expo_x >= 2046) {

    if ((rndMode == cudaRoundNearest) ||
        ((rndMode == cudaRoundPosInf) && (!expo_y)) ||
        ((rndMode == cudaRoundMinInf) && expo_y)) {
      xx.hi = (xx.hi & 0x80000000) | 0x7ff00000;
      xx.lo = 0;
    } else {
      xx.hi = (xx.hi & 0x80000000) | 0x7fefffff;
      xx.lo = 0xffffffff;
    }
    return __hiloint2double(xx.hi, xx.lo);
  }

  expo_x = (unsigned)(-(int)expo_x);
  if (expo_x > 54) {

    if (((rndMode == cudaRoundPosInf) && (!expo_y)) ||
        ((rndMode == cudaRoundMinInf) && expo_y)) {
      return __hiloint2double(xx.hi & 0x80000000, 1);
    } else {
      return __hiloint2double(xx.hi & 0x80000000, 0);
    }
  }
  yy.hi = xx.hi & 0x80000000;
  xx.hi = xx.hi & ~0xffe00000;
  if (expo_x >= 32) {
    t = xx.lo | (t != 0);
    xx.lo = xx.hi;
    xx.hi = 0;
    expo_x -= 32;
  }
  if (expo_x) {
    t = (t >> expo_x) | (xx.lo << (32 - expo_x)) | (t != 0);
    xx.lo = (xx.lo >> expo_x) | (xx.hi << (32 - expo_x));
    xx.hi = (xx.hi >> expo_x);
  }
  expo_x = xx.lo & 1;
  u = xx.lo;
  if (rndMode == cudaRoundNearest) {
    xx.lo += (t == 0x80000000) ? expo_x : (t >> 31);
  } else if (((rndMode == cudaRoundPosInf) && t && (!expo_y)) ||
             ((rndMode == cudaRoundMinInf) && t && expo_y)) {
    xx.lo += 1;
  }
  xx.hi += (u > xx.lo);
  xx.hi |= yy.hi;
  return __hiloint2double(xx.hi, xx.lo);
}

static __attribute__((__unused__)) double __fma_rn(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundNearest);
}

static __attribute__((__unused__)) double __fma_rd(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __fma_ru(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __fma_rz(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundZero);
}

static __attribute__((__unused__)) double __dadd_rz(double a, double b)
{
  return __fma_rz(a, 1.0, b);
}

static __attribute__((__unused__)) double __dadd_ru(double a, double b)
{
  return __fma_ru(a, 1.0, b);
}

static __attribute__((__unused__)) double __dadd_rd(double a, double b)
{
  return __fma_rd(a, 1.0, b);
}

static __attribute__((__unused__)) double __dmul_rz(double a, double b)
{
  return __fma_rz(a, b, __longlong_as_double(0x8000000000000000ULL));
}

static __attribute__((__unused__)) double __dmul_ru(double a, double b)
{
  return __fma_ru(a, b, __longlong_as_double(0x8000000000000000ULL));
}

static __attribute__((__unused__)) double __dmul_rd(double a, double b)
{
  return __fma_rd(a, b, 0.0);
}

static __attribute__((__unused__)) double __dadd_rn(double a, double b)
{
  return __fma_rn(a, 1.0, b);
}

static __attribute__((__unused__)) double __dmul_rn(double a, double b)
{
  return __fma_rn(a, b, __longlong_as_double(0x8000000000000000ULL));
}
# 4764 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h" 1 3
# 86 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h" 3
extern "C" {


extern void __cudaMutexOperation(int lock);


}







static __attribute__((__unused__)) float __fAtomicAdd(float *address, float val)
{
  float old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}
# 4765 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h" 1 3
# 156 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h" 3
static __attribute__((__unused__)) void __threadfence_system(void)
{
  __syncthreads();
}

static __attribute__((__unused__)) unsigned int __ballot(int pred)
{
  return (unsigned int)1;
}

static __attribute__((__unused__)) int __syncthreads_count(int pred)
{
  return 1;
}

static __attribute__((__unused__)) int __syncthreads_and(int pred)
{
  return pred;
}

static __attribute__((__unused__)) int __syncthreads_or(int pred)
{
  return pred;
}

static __attribute__((__unused__)) long long int clock64(void)
{
  return (long long int)__cuda_clock();
}

static __attribute__((__unused__)) double __internal_ddiv_kernel (double x, double y, enum cudaRoundMode mode)

{
  volatile union __cudart_DoubleLonglongCvt cvt;
  unsigned long long a, b, q, sign;
  int expoa, expob, normalize, i;

  cvt.d = x;
  a = cvt.i;
  cvt.d = y;
  b = cvt.i;

  sign = (a ^ b) & 0x8000000000000000ULL;

  expoa = ((int)(a >> 52) & 0x7ff) - 1;
  expob = ((int)(b >> 52) & 0x7ff) - 1;

  if (((unsigned)expoa >= 0x7fe) || ((unsigned)expob >= 0x7fe)) {

    if ((a << 1) > 0xffe0000000000000ULL) {
      cvt.i = a | 0x0008000000000000ULL;
      return cvt.d;
    }
    if ((b << 1) > 0xffe0000000000000ULL) {
      cvt.i = b | 0x0008000000000000ULL;
      return cvt.d;
    }

    if ((((a << 1) == 0x0000000000000000ULL) &&
         ((b << 1) == 0x0000000000000000ULL)) ||
        (((a << 1) == 0xffe0000000000000ULL) &&
         ((b << 1) == 0xffe0000000000000ULL))) {
      cvt.i = 0xfff8000000000000ULL;
      return cvt.d;
    }

    if (((a << 1) == 0x0000000000000000ULL) ||
        ((b << 1) == 0xffe0000000000000ULL)) {
      cvt.i = sign;
      return cvt.d;
    }

    if (((b << 1) == 0x0000000000000000ULL) ||
        ((a << 1) == 0xffe0000000000000ULL)) {
      cvt.i = sign | 0x7ff0000000000000ULL;
      return cvt.d;
    }
    if (expoa < 0) {
      a = a << 12;
      while ((long long)a > 0) {
        a = a + a;
        expoa--;
      }
      a = a >> 11;
    }
    if (expob < 0) {
      b = b << 12;
      while ((long long)b > 0) {
        b = b + b;
        expob--;
      }
      b = b >> 11;
    }
  }
  a = (a & 0x000fffffffffffffULL) | 0x0010000000000000ULL;
  b = (b & 0x000fffffffffffffULL) | 0x0010000000000000ULL;

  q = 0ULL;
  a = a - b;
  normalize = (long long)a < 0;
  for (i = 0; i < (54 + normalize); i++) {
    if ((long long)a < 0) {
      q = q + q;
      a = a + a;
      a = a + b;
    } else {
      q = q + q + 1;
      a = a + a;
      a = a - b;
    }
  }
  expoa = (expoa - expob) - normalize + 1022;
  if ((unsigned)expoa < 0x7fe) {

    if (mode == cudaRoundNearest) {
      q++;
    } else if ((mode == cudaRoundPosInf) && (!sign)) {
      if ((q & 1) || (a != (unsigned long long)-(long long)b)) q += 2;
    } else if ((mode == cudaRoundMinInf) && (sign)) {
      if ((q & 1) || (a != (unsigned long long)-(long long)b)) q += 2;
    }
    q = (q >> 1) & 0x000fffffffffffffULL;
    q = sign | (((long long)(expoa+1) << 52) + q);
  } else if (expoa >= 0x7fe) {

    if ((mode == cudaRoundNearest) ||
        ((mode == cudaRoundPosInf) && !sign) ||
        ((mode == cudaRoundMinInf) && sign)) {
      q = sign | 0x7ff0000000000000ULL;
    } else {
      q = sign | 0x7fefffffffffffffULL;
    }
  } else {

    unsigned long long sticky;
    expoa = -expoa;
    if (expoa > 63) expoa = 63;

    sticky = (q << (64 - expoa)) | (a!=(unsigned long long)-(long long)b);
    q = q >> expoa;
    if (mode == cudaRoundNearest) {
      if ((q & 1) && (sticky || (q & 2))) q++;
    } else if ((mode == cudaRoundPosInf) && (!sign)) {
      if ((q & 1) || (sticky)) q += 2;
    } else if ((mode == cudaRoundMinInf) && (sign)) {
      if ((q & 1) || (sticky)) q += 2;
    }
    q = q >> 1;
    q = q | sign;
  }
  cvt.i = q;
  return cvt.d;
}

static __attribute__((__unused__)) double __ddiv_rn(double a, double b)
{
  return __internal_ddiv_kernel (a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) double __ddiv_rz(double a, double b)
{
  return __internal_ddiv_kernel (a, b, cudaRoundZero);
}

static __attribute__((__unused__)) double __ddiv_ru(double a, double b)
{
  return __internal_ddiv_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __ddiv_rd(double a, double b)
{
  return __internal_ddiv_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __drcp_rn(double a)
{
  return __internal_ddiv_kernel (1.0, a, cudaRoundNearest);
}

static __attribute__((__unused__)) double __drcp_rz(double a)
{
  return __internal_ddiv_kernel (1.0, a, cudaRoundZero);
}

static __attribute__((__unused__)) double __drcp_ru(double a)
{
  return __internal_ddiv_kernel (1.0, a, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __drcp_rd(double a)
{
  return __internal_ddiv_kernel (1.0, a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __internal_dsqrt_kernel (double a, enum cudaRoundMode mode)

{
  volatile union __cudart_DoubleLonglongCvt cvt;
  unsigned long long ia, manthi, mantlo;
  unsigned long long t, q, r, s;
  int expoa;
  int round, sticky, odd;
  int sign;

  cvt.d = a;
  ia = cvt.i;
  expoa = ((int)(ia >> 52) & 0x7ff) - 1;
  sign = (int)(ia >> 63);


  if (((unsigned)expoa >= 0x7fe) || sign) {

    if ((ia << 1) > 0xffe0000000000000ULL) {
      cvt.i |= 0x0008000000000000ULL;
      return cvt.d;
    }

    if (ia > 0x8000000000000000ULL) {
      cvt.i = 0xfff8000000000000ULL;
      return cvt.d;
    }

    if ((ia << 1) == 0xffe0000000000000ULL) {
      return cvt.d;
    }

    if ((ia << 1) == 0x0000000000000000ULL) {
      return cvt.d;
    }

    if (expoa < 0) {
      ia = ia << 12;
      while ((long long)ia > 0) {
        ia = ia + ia;
        expoa--;
      }
      ia = ia >> 11;
    }
  }


  ia = (ia << 11) | 0x8000000000000000ULL;
  if (!(expoa & 1)) {

    ia >>= 1;
  }

  manthi = ia >> 32;
  mantlo = ia & 0xffffffffULL;


  t = ((manthi >> 24) | 0x100) >> 1;
  t = (expoa & 1) ? (t - 10) : t;
  q = ((manthi >> 16) / t);
  t = (((q + t) >> 1) << 8) | 0xff;
  q = manthi / t;
  t = (q + t) >> 1;
  if (t > 0xffff) t = 0xffff;


  r = manthi - t * t;
  while ((long long)r < 0) {
    t--;
    r += 2 * t + 1;
  }


  s = ((r << 15) + (mantlo >> 17)) / t;
  if (s > 0xffff) s = 0xffff;


  r = (r << 32) + mantlo;
  r = r - (t << 17) * s;
  r = r - s * s;
  t = (t << 16) + s;
  while ((long long)r < 0) {
    t--;
    r += 2 * t + 1;
  }


  s = (r << 15) / t;
  if (s > 0xffff) s = 0xffff;


  r = r << 32;
  r = r - (t << 17) * s;
  r = r - s * s;
  t = (t << 16) + s;
  while ((long long)r < 0) {
    t--;
    r += 2 * t + 1;
  }


  s = (r << 5) / t;
  if (s > 0x3f) s = 0x3f;


  r = r << 12;
  r = r - ((t << 7) + s) * s;
  t = (t << 6) + s;
  while ((long long)r < 0) {
    t--;
    r += 2 * t + 1;
  }


  round = (int)(t & 1);
  sticky = (r != 0ULL);
  t = t >> 1;
  odd = (int)(t & 1);


  if (mode == cudaRoundNearest) {
    t += round && (sticky || odd);
  } else if (mode == cudaRoundPosInf) {
    t += round || sticky;
  }


  expoa = (expoa >> 1) + 0x1ff;
  q = (((unsigned long long int)expoa) << 52) + t;
  cvt.i = q;
  return cvt.d;
}

static __attribute__((__unused__)) double __dsqrt_rn(double a)
{
  return __internal_dsqrt_kernel (a, cudaRoundNearest);
}

static __attribute__((__unused__)) double __dsqrt_rz(double a)
{
  return __internal_dsqrt_kernel (a, cudaRoundZero);
}

static __attribute__((__unused__)) double __dsqrt_ru(double a)
{
  return __internal_dsqrt_kernel (a, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __dsqrt_rd(double a)
{
  return __internal_dsqrt_kernel (a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fmaf_ieee_rn(float a, float b, float c)
{
  return __fmaf_rn(a, b, c);
}

static __attribute__((__unused__)) float __fmaf_ieee_ru(float a, float b, float c)
{
  return __fmaf_ru(a, b, c);
}

static __attribute__((__unused__)) float __fmaf_ieee_rd(float a, float b, float c)
{
  return __fmaf_rd(a, b, c);
}

static __attribute__((__unused__)) float __fmaf_ieee_rz(float a, float b, float c)
{
  return __fmaf_rz(a, b, c);
}
# 4766 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/surface_functions.h" 1 3
# 4767 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 1 3
# 1911 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 3
extern "C" {


extern void __cudaTextureFetch(const void *tex, void *index, int integer, void *val);


}


static __attribute__((__unused__)) int4 __itexfetchi(const void *tex, int4 index)
{
  int4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) uint4 __utexfetchi(const void *tex, int4 index)
{
  uint4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) float4 __ftexfetchi(const void *tex, int4 index)
{
  float4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) int4 __itexfetch(const void *tex, float4 index, int dim)
{
  int4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}

static __attribute__((__unused__)) uint4 __utexfetch(const void *tex, float4 index, int dim)
{
  uint4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}

static __attribute__((__unused__)) float4 __ftexfetch(const void *tex, float4 index, int dim)
{
  float4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}
# 4768 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 988 "/usr/local/cuda/bin/../include/math_functions.h" 2 3


static __attribute__((__unused__)) int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static __attribute__((__unused__)) float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 1012 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) float __internal_nearbyintf(float a)
{
  float fa = fabsf(a);

  if (fa >= 8388608.0f) {
    return a;
  } else {
    volatile float u = 8388608.0f + fa;

    u = u - 8388608.0f;
    return copysignf(u, a);
  }
}

static __attribute__((__unused__)) float __internal_fminf(float a, float b)
{
  volatile union {
    float f;
    unsigned int i;
  } cvta, cvtb;
  int nana, nanb;

  cvta.f = a;
  cvtb.f = b;
  nana = ((cvta.i << 1) > 0xff000000);
  nanb = ((cvtb.i << 1) > 0xff000000);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.i | cvtb.i) == 0x80000000) {
    return __int_as_float(0x80000000);
  }
  return a < b ? a : b;
}

static __attribute__((__unused__)) float __internal_fmaxf(float a, float b)
{
  volatile union {
    float f;
    unsigned int i;
  } cvta, cvtb;
  int nana, nanb;

  cvta.f = a;
  cvtb.f = b;
  nana = ((cvta.i << 1) > 0xff000000);
  nanb = ((cvtb.i << 1) > 0xff000000);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.f == 0.0f) && (cvtb.f == 0.0f)) {
    cvta.i &= cvtb.i;
    return cvta.f;
  }
  return a > b ? a : b;
}
# 1077 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) long int __cuda_labs(long int a)
{



  return a < 0ll ? -a : a;

}

static __attribute__((__unused__)) float __cuda_ceilf(float a)
{
  return ceilf(a);
}

static __attribute__((__unused__)) float __cuda_floorf(float a)
{
  return floorf(a);
}

static __attribute__((__unused__)) float __cuda_sqrtf(float a)
{
  return sqrtf(a);
}

static __attribute__((__unused__)) float __cuda_rsqrtf(float a)
{
  return rsqrtf(a);
}

static __attribute__((__unused__)) float __cuda_truncf(float a)
{
  return truncf(a);
}

static __attribute__((__unused__)) int __cuda_max(int a, int b)
{



  return a > b ? a : b;

}

static __attribute__((__unused__)) int __cuda_min(int a, int b)
{



  return a < b ? a : b;

}

static __attribute__((__unused__)) unsigned int __cuda_umax(unsigned int a, unsigned int b)
{



  return a > b ? a : b;

}

static __attribute__((__unused__)) unsigned int __cuda_umin(unsigned int a, unsigned int b)
{



  return a < b ? a : b;

}

static __attribute__((__unused__)) long long int __cuda_llmax(long long int a, long long int b)
{



  return a > b ? a : b;

}

static __attribute__((__unused__)) long long int __cuda_llmin(long long int a, long long int b)
{



  return a < b ? a : b;

}

static __attribute__((__unused__)) unsigned long long int __cuda_ullmax(unsigned long long int a, unsigned long long int b)
{



  return a > b ? a : b;

}

static __attribute__((__unused__)) unsigned long long int __cuda_ullmin(unsigned long long int a, unsigned long long int b)
{



  return a < b ? a : b;

}

static __attribute__((__unused__)) long long int __cuda_llrintf(float a)
{



  return __float2ll_rn(a);

}

static __attribute__((__unused__)) long int __cuda_lrintf(float a)
{




  return (long int)__cuda_llrintf(a);




}

static __attribute__((__unused__)) float __cuda_nearbyintf(float a)
{





  return __internal_nearbyintf(a);

}

static __attribute__((__unused__)) float __cuda_fmaxf(float a, float b)
{





  return __internal_fmaxf(a, b);

}

static __attribute__((__unused__)) float __cuda_fminf(float a, float b)
{





  return __internal_fminf(a, b);

}






static __attribute__((__unused__)) int __cuda___finitef(float a)
{
  return __cuda_fabsf(a) < __int_as_float(0x7f800000);
}
# 1257 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) int __cuda___isinff(float a)
{
  return __cuda_fabsf(a) == __int_as_float(0x7f800000);
}

static __attribute__((__unused__)) int __cuda___isnanf(float a)
{
  return !(__cuda_fabsf(a) <= __int_as_float(0x7f800000));
}

static __attribute__((__unused__)) float __cuda_nextafterf(float a, float b)
{
  unsigned int ia;
  unsigned int ib;
  ia = __float_as_int(a);
  ib = __float_as_int(b);




  if (__cuda___isnanf(a) || __cuda___isnanf(b)) return a + b;
  if (__int_as_float (ia | ib) == 0.0f) return __int_as_float(ib);





  if (__int_as_float(ia) == 0.0f) {
    return __int_as_float (0x00000001 | (__float_as_int(b) & 0x80000000));
  }

  if ((a < b) && (a < 0.0f)) ia--;
  if ((a < b) && (a > 0.0f)) ia++;
  if ((a > b) && (a < 0.0f)) ia++;
  if ((a > b) && (a > 0.0f)) ia--;
  a = __int_as_float(ia);





  return a;
}

static __attribute__((__unused__)) unsigned long long int __internal_nan_kernel(const char *s)
{
  unsigned long long i = 0;
  int c;
  int ovfl = 0;
  int invld = 0;
  if (s && (*s == '0')) {
    s++;
    if ((*s == 'x') || (*s == 'X')) {
      s++;
      while (*s == '0') s++;
      while (*s) {
        if (i > 0x0fffffffffffffffULL) {
          ovfl = 1;
        }
        c = (((*s) >= 'A') && ((*s) <= 'F')) ? (*s + 'a' - 'A') : (*s);
        if ((c >= 'a') && (c <= 'f')) {
          c = c - 'a' + 10;
          i = i * 16 + c;
        } else if ((c >= '0') && (c <= '9')) {
          c = c - '0';
          i = i * 16 + c;
        } else {
          invld = 1;
        }
        s++;
      }
    } else {
      while (*s == '0') s++;
      while (*s) {
        if (i > 0x1fffffffffffffffULL) {
          ovfl = 1;
        }
        c = *s;
        if ((c >= '0') && (c <= '7')) {
          c = c - '0';
          i = i * 8 + c;
        } else {
          invld = 1;
        }
        s++;
      }
    }
  } else if (s) {
    while (*s) {
      c = *s;
      if ((i > 1844674407370955161ULL) ||
          ((i == 1844674407370955161ULL) && (c > '5'))) {
        ovfl = 1;
      }
      if ((c >= '0') && (c <= '9')) {
        c = c - '0';
        i = i * 10 + c;
      } else {
        invld = 1;
      }
      s++;
    }
  }
  if (ovfl) {
    i = ~0ULL;
  }
  if (invld) {
    i = 0ULL;
  }
  i = (i & 0x000fffffffffffffULL) | 0x7ff8000000000000ULL;
  return i;
}

static __attribute__((__unused__)) float __cuda_nanf(const char *tagp)
{




  unsigned int i;

  i = (unsigned int)__internal_nan_kernel (tagp);
  return __int_as_float((i & 0x007fffff) | 0x7fc00000);

}

static __attribute__((__unused__)) float __internal_fmad(float a, float b, float c)
{

  return __fmaf_rn (a, b, c);



}


static __attribute__((__unused__)) float __internal_atanhf_kernel(float a_1, float a_2)
{
  float a, a2, t;

  a = a_1 + a_2;
  a2 = a * a;
  t = 1.566305595598990E-001f/64.0f;
  t = __internal_fmad (t, a2, 1.995081856004762E-001f/16.0f);
  t = __internal_fmad (t, a2, 3.333382699617026E-001f/4.0f);
  t = t * a2;
  t = __internal_fmad (t, a, a_2);
  t = t + a_1;
  return t;
}




static __attribute__((__unused__)) float __internal_atanf_kernel(float a)
{
  float t4, t0, t1;

  t4 = a * a;
  t0 = -5.674867153f;
  t0 = __internal_fmad (t4, -0.823362947f, t0);
  t0 = __internal_fmad (t0, t4, -6.565555096f);
  t0 = t0 * t4;
  t0 = t0 * a;
  t1 = t4 + 11.33538818f;
  t1 = __internal_fmad (t1, t4, 28.84246826f);
  t1 = __internal_fmad (t1, t4, 19.69667053f);
  t1 = 1.0f / t1;
  a = __internal_fmad (t0, t1, a);
  return a;
}


static __attribute__((__unused__)) float __internal_tan_kernel(float a)
{
  float a2, s, t;

  a2 = a * a;
  t = __internal_fmad (4.114678393115178E-003f, a2, -8.231194034909670E-001f);
  s = a2 - 2.469348886157666E+000f;
  s = 1.0f / s;
  t = t * s;
  t = t * a2;
  t = __internal_fmad (t, a, a);
  return t;
}

static __attribute__((__unused__)) float __internal_accurate_logf(float a)
{
  float t;
  float z;
  float m;
  int ia;
  ia = __float_as_int(a);

  if ((a > 0.0f) && (a < __int_as_float(0x7f800000))) {
    int e = -127;


    if ((unsigned)ia < (unsigned)0x00800000) {
      a = a * 16777216.0f;
      e -= 24;
      ia = __float_as_int(a);
    }


    m = __int_as_float((ia & 0x807fffff) | 0x3f800000);
    e += ((unsigned)ia >> 23);
    if (m > 1.414213562f) {
      m = m * 0.5f;
      e = e + 1;
    }
    t = m - 1.0f;
    z = m + 1.0f;
    z = __fdividef (t, z);
    z = -t * z;
    z = __internal_atanhf_kernel(t, z);
    z = __internal_fmad ((float)e, 0.693147181f, z);
    return z;
  } else {

    return __logf(a);
  }
}

static __attribute__((__unused__)) float2 __internal_log_ep(float a)
{
  float2 res;
  int expo;
  float m;
  float log_hi, log_lo;
  float t_hi, t_lo;
  float f, g, u, v, q;



  float r, s, e;
  expo = (__float_as_int(a) >> 23) & 0xff;


  if (expo == 0) {
    a *= 16777216.0f;
    expo = (__float_as_int(a) >> 23) & 0xff;
    expo -= 24;
  }

  expo -= 127;
  m = __int_as_float((__float_as_int(a) & 0x807fffff) | 0x3f800000);
  if (m > 1.414213562f) {
    m = m * 0.5f;
    expo = expo + 1;
  }






  f = m - 1.0f;
  g = m + 1.0f;
  g = 1.0f / g;
  u = 2.0f * f * g;
  v = u * u;
  q = 1.49356810919559350E-001f/64.0f;
  q = __internal_fmad (q, v, 1.99887797540072460E-001f/16.0f);
  q = __internal_fmad (q, v, 3.33333880955515580E-001f/4.0f);
  q = q * v;
  q = q * u;
  log_hi = __int_as_float(__float_as_int(u) & 0xfffff000);
  v = __int_as_float(__float_as_int(f) & 0xfffff000);
  u = 2.0f * (f - log_hi);
  f = f - v;
  u = __internal_fmad (-log_hi, v, u);
  u = __internal_fmad (-log_hi, f, u);
  u = g * u;



  r = log_hi + u;
  s = u - (r - log_hi);
  log_hi = r;
  log_lo = s;

  r = log_hi + q;
  s = ((log_hi - r) + q) + log_lo;
  log_hi = e = r + s;
  log_lo = (r - e) + s;


  t_hi = expo * 0.6931457519f;
  t_lo = expo * 1.4286067653e-6f;


  r = t_hi + log_hi;
  s = (((t_hi - r) + log_hi) + log_lo) + t_lo;
  res.y = e = r + s;
  res.x = (r - e) + s;
  return res;
}

static __attribute__((__unused__)) float __internal_accurate_log2f(float a)
{
  return 1.442695041f * __internal_accurate_logf(a);
}




static __attribute__((__unused__)) float2 __internal_dsmul (float2 x, float2 y)
{
    float2 z;


    volatile

    float up, vp, u1, u2, v1, v2, mh, ml;
    up = x.y * 4097.0f;
    u1 = (x.y - up) + up;
    u2 = x.y - u1;
    vp = y.y * 4097.0f;
    v1 = (y.y - vp) + vp;
    v2 = y.y - v1;
    mh = __fmul_rn(x.y,y.y);
    ml = (((u1 * v1 - mh) + u1 * v2) + u2 * v1) + u2 * v2;
    ml = (__fmul_rn(x.y,y.x) + __fmul_rn(x.x,y.y)) + ml;
    z.y = up = mh + ml;
    z.x = (mh - up) + ml;
# 1597 "/usr/local/cuda/bin/../include/math_functions.h" 3
    return z;
}


static unsigned int __cudart_i2opi_f [] = {
  0x3c439041,
  0xdb629599,
  0xf534ddc0,
  0xfc2757d1,
  0x4e441529,
  0xa2f9836e,
};


static __attribute__((__unused__)) float __internal_trig_reduction_kernel(float a, int *quadrant)
{
  float j;
  int q;
  if (__cuda_fabsf(a) > 48039.0f) {

    unsigned int ia = __float_as_int(a);
    unsigned int s = ia & 0x80000000;
    unsigned int result[7];
    unsigned int phi, plo;
    unsigned int hi, lo;
    unsigned int e;
    int idx;
    e = ((ia >> 23) & 0xff) - 128;
    ia = (ia << 8) | 0x80000000;

    idx = 4 - (e >> 5);
    hi = 0;



    for (q = 0; q < 6; q++) {
      plo = __cudart_i2opi_f[q] * ia;
      phi = __umulhi (__cudart_i2opi_f[q], ia);
      lo = hi + plo;
      hi = phi + (lo < plo);
      result[q] = lo;
    }
    result[q] = hi;
    e = e & 31;



    hi = result[idx+2];
    lo = result[idx+1];
    if (e) {
      q = 32 - e;
      hi = (hi << e) + (lo >> q);
      lo = (lo << e) + (result[idx] >> q);
    }
    q = hi >> 30;

    hi = (hi << 2) + (lo >> 30);
    lo = (lo << 2);
    e = (hi + (lo > 0)) > 0x80000000;
    q += e;
    if (s) q = -q;
    if (e) {
      unsigned int t;
      hi = ~hi;
      lo = -(int)lo;
      t = (lo == 0);
      hi += t;
      s = s ^ 0x80000000;
    }
    *quadrant = q;

    e = 0;
    while ((int)hi > 0) {
      hi = (hi << 1) + (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    lo = hi * 0xc90fdaa2;
    hi = __umulhi(hi, 0xc90fdaa2);
    if ((int)hi > 0) {
      hi = (hi << 1) + (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    hi = hi + (lo > 0);
    ia = s | (((e + 126) << 23) + (hi >> 8) + ((hi << 24) >= 0x80000000));
    return __int_as_float(ia);
  }
  q = __float2int_rn (a * 0.636619772f);
  j = (float)q;
  a = __internal_fmad (-j, 1.5703125000000000e+000f, a);


  a = __fmaf_rn (-j, 4.8382673412561417e-004f, a);




  a = __internal_fmad (-j, 6.0771005065061922e-011f, a);
  *quadrant = q;
  return a;
}
# 1709 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) float __internal_expf_kernel(float a, float scale)
{
  float j, z;

  j = __cuda_truncf(a * 1.442695041f);
  z = __internal_fmad (j, -0.6931457519f, a);
  z = __internal_fmad (j, -1.4286067653e-6f, z);
  z = z * 1.442695041f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j + scale);
  return z;
}

static __attribute__((__unused__)) float __internal_accurate_expf(float a)
{
  float z;

  z = __internal_expf_kernel(a, 0.0f);
  if (a < -105.0f) z = 0.0f;
  if (a > 105.0f) z = __int_as_float(0x7f800000);
  return z;
}

static __attribute__((__unused__)) float __internal_accurate_exp10f(float a)
{
  float j, z;

  j = __cuda_truncf(a * 3.321928094f);
  z = __internal_fmad (j, -3.0102920532226563e-001f, a);
  z = __internal_fmad (j, -7.9034171557301747e-007f, z);
  z = z * 3.321928094f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j);
  if (a < -46.0f) z = 0.0f;
  if (a > 46.0f) z = __int_as_float(0x7f800000);
  return z;
}

static __attribute__((__unused__)) float __internal_lgammaf_pos(float a)
{
  float sum;
  float s, t;

  if (a == __int_as_float(0x7f800000)) {
    return a;
  }
  if (a >= 3.0f) {
    if (a >= 7.8f) {



      s = __fdividef (1.0f, a);
      t = s * s;
      sum = 0.77783067e-3f;
      sum = __internal_fmad (sum, t, -0.2777655457e-2f);
      sum = __internal_fmad (sum, t, 0.83333273853e-1f);
      sum = __internal_fmad (sum, s, 0.918938533204672f);
      s = 0.5f * __internal_accurate_logf(a);
      t = a - 0.5f;
      s = s * t;
      t = s - a;
      s = __fadd_rn(s, sum);
      t = t + s;
      return t;
    } else {
      a = a - 3.0f;
      s = -7.488903254816711E+002f;
      s = __internal_fmad (s, a, -1.234974215949363E+004f);
      s = __internal_fmad (s, a, -4.106137688064877E+004f);
      s = __internal_fmad (s, a, -4.831066242492429E+004f);
      s = __internal_fmad (s, a, -1.430333998207429E+005f);
      t = a - 2.592509840117874E+002f;
      t = __internal_fmad (t, a, -1.077717972228532E+004f);
      t = __internal_fmad (t, a, -9.268505031444956E+004f);
      t = __internal_fmad (t, a, -2.063535768623558E+005f);
      t = __fdividef (s, t);
      t = t + a;
      return t;
    }
  } else if (a >= 1.5f) {
    a = a - 2.0f;
    t = 4.959849168282574E-005f;
    t = __internal_fmad (t, a, -2.208948403848352E-004f);
    t = __internal_fmad (t, a, 5.413142447864599E-004f);
    t = __internal_fmad (t, a, -1.204516976842832E-003f);
    t = __internal_fmad (t, a, 2.884251838546602E-003f);
    t = __internal_fmad (t, a, -7.382757963931180E-003f);
    t = __internal_fmad (t, a, 2.058131963026755E-002f);
    t = __internal_fmad (t, a, -6.735248600734503E-002f);
    t = __internal_fmad (t, a, 3.224670187176319E-001f);
    t = __internal_fmad (t, a, 4.227843368636472E-001f);
    t = t * a;
    return t;
  } else if (a >= 0.7f) {
    a = 1.0f - a;
    t = 4.588266515364258E-002f;
    t = __internal_fmad (t, a, 1.037396712740616E-001f);
    t = __internal_fmad (t, a, 1.228036339653591E-001f);
    t = __internal_fmad (t, a, 1.275242157462838E-001f);
    t = __internal_fmad (t, a, 1.432166835245778E-001f);
    t = __internal_fmad (t, a, 1.693435824224152E-001f);
    t = __internal_fmad (t, a, 2.074079329483975E-001f);
    t = __internal_fmad (t, a, 2.705875136435339E-001f);
    t = __internal_fmad (t, a, 4.006854436743395E-001f);
    t = __internal_fmad (t, a, 8.224669796332661E-001f);
    t = __internal_fmad (t, a, 5.772156651487230E-001f);
    t = t * a;
    return t;
  } else {
    t = 3.587515669447039E-003f;
    t = __internal_fmad (t, a, -5.471285428060787E-003f);
    t = __internal_fmad (t, a, -4.462712795343244E-002f);
    t = __internal_fmad (t, a, 1.673177015593242E-001f);
    t = __internal_fmad (t, a, -4.213597883575600E-002f);
    t = __internal_fmad (t, a, -6.558672843439567E-001f);
    t = __internal_fmad (t, a, 5.772153712885004E-001f);
    t = t * a;
    t = __internal_fmad (t, a, a);
    return -__internal_accurate_logf(t);
  }
}


static __attribute__((__unused__)) float __internal_sin_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z = -1.95152959e-4f;
  z = __internal_fmad (z, x2, 8.33216087e-3f);
  z = __internal_fmad (z, x2, -1.66666546e-1f);
  z = z * x2;
  z = __internal_fmad (z, x, x);
  return z;
}


static __attribute__((__unused__)) float __internal_cos_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z = 2.44331571e-5f;
  z = __internal_fmad (z, x2, -1.38873163e-3f);
  z = __internal_fmad (z, x2, 4.16666457e-2f);
  z = __internal_fmad (z, x2, -5.00000000e-1f);
  z = __internal_fmad (z, x2, 1.00000000e+0f);
  return z;
}

static __attribute__((__unused__)) float __internal_accurate_sinf(float a)
{
  float z;
  int i;

  if ((__cuda___isinff(a)) || (a == 0.0f)) {
    return __fmul_rn (a, 0.0f);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}







static __attribute__((__unused__)) float __cuda_rintf(float a)
{



  return __cuda_nearbyintf(a);

}

static __attribute__((__unused__)) float __cuda_sinf(float a)
{





  return __internal_accurate_sinf(a);

}

static __attribute__((__unused__)) float __cuda_sinpif(float a)
{
  float z;
  int i;

  if ((__cuda___isinff(a)) || (a == 0.0f)) {
    return __fmul_rn (a, 0.0f);
  }
  if (a == __cuda_floorf(a)) {
    return __int_as_float(__float_as_int(a) & 0x80000000);
  }
  i = (int)__cuda_rintf (a * 2.0f);
  z = __internal_fmad ((float)i, -0.5f, a);
  z = z * 3.141592654f;
  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}

static __attribute__((__unused__)) float __cuda_cosf(float a)
{





  float z;
  int i;

  if (__cuda___isinff(a)) {
    return __fadd_rn (a, -a);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  i++;
  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;

}

static __attribute__((__unused__)) float __cuda_tanf(float a)
{





  float z;
  int i;

  if (__cuda___isinff(a)) {
    return __fadd_rn (a, -a);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  z = __internal_tan_kernel(z);
  if (i & 1) {
    z = - (1.0f / z);
  }
  return z;

}

static __attribute__((__unused__)) float __cuda_log2f(float a)
{





  return __internal_accurate_log2f(a);

}

static __attribute__((__unused__)) float __cuda_expf(float a)
{





  return __internal_accurate_expf(a);

}

static __attribute__((__unused__)) float __cuda_exp10f(float a)
{





  return __internal_accurate_exp10f(a);

}

static __attribute__((__unused__)) float __cuda_coshf(float a)
{
  float z;


  if (__cuda___isnanf(a)) return a + a;

  a = __cuda_fabsf(a);
  z = __internal_expf_kernel(a, -2.0f);
  z = __internal_fmad (2.0f, z, __fdividef (0.125f, z));
  if (a >= 90.0f) {
    z = __int_as_float(0x7f800000);
  }
  return z;
}

static __attribute__((__unused__)) float __cuda_sinhf(float a)
{
  float s, z;

  s = a;
  a = __cuda_fabsf(a);
  if (a >= 1.0f) {
    z = __internal_expf_kernel(a, -2.0f);
    z = __internal_fmad (2.0f, z, -__fdividef (0.125f, z));
    if (a >= 90.0f) {
      z = __int_as_float(0x7f800000);
    }
    z = __int_as_float(__float_as_int(z) | (__float_as_int(s) & 0x80000000));
  } else {
    float a2 = s * s;

    z = 2.816951222e-6f;
    z = __internal_fmad (z, a2, 1.983615978e-4f);
    z = __internal_fmad (z, a2, 8.333350058e-3f);
    z = __internal_fmad (z, a2, 1.666666650e-1f);
    z = z * a2;
    z = __internal_fmad (z, s, s);
  }
  return z;
}

static __attribute__((__unused__)) float __cuda_tanhf(float a)
{
  float s, t;

  t = __cuda_fabsf(a);
  if (t >= 0.55f) {
    s = 1.0f - __fdividef(2.0f,(__internal_expf_kernel(2.0f * t, 0.0f)+1.0f));
    if (t >= 88.0f) {
      s = 1.0f;
    }
    s = __int_as_float(__float_as_int(s) | (__float_as_int(a) & 0x80000000));
  } else {
    float z2;
    z2 = a * a;
    t = 1.643758066599993e-2f;
    t = __internal_fmad (t, z2, -5.267181327760551e-2f);
    t = __internal_fmad (t, z2, 1.332072505223051e-1f);
    t = __internal_fmad (t, z2, -3.333294663641083e-1f);
    t = t * z2;
    s = __internal_fmad (t, a, a);
    if (a == 0.0f) {
      s = a + a;
    }
  }
  return s;
}

static __attribute__((__unused__)) float __cuda_atan2f(float a, float b)
{



  float t0, t1, fa, fb;

  fb = __cuda_fabsf(b);
  fa = __cuda_fabsf(a);
  if ((fa == 0.0f) && (fb == 0.0f)) {
    t0 = __cuda___signbitf(b) ? 3.141592654f : 0.0f;
    t0 = __int_as_float(__float_as_int(t0) | (__float_as_int(a) & 0x80000000));
  } else if ((fa == __int_as_float(0x7f800000)) && (fb == __int_as_float(0x7f800000))) {
    t0 = __cuda___signbitf(b) ? 2.356194490f : 0.785398163f;
    t0 = __int_as_float(__float_as_int(t0) | (__float_as_int(a) & 0x80000000));
  } else {


    t0 = __cuda_fminf(fa, fb);
    t1 = __cuda_fmaxf(fa, fb);
    t0 = t0 / t1;
    t0 = __internal_atanf_kernel(t0);

    if (fa > fb) t0 = 1.570796327f - t0;
    if (b < 0.0f) t0 = 3.141592654f - t0;
    t0 = __int_as_float(__float_as_int(t0) | (__float_as_int(a) & 0x80000000));
    t1 = a + b;
    if (!(t1 <= __int_as_float(0x7f800000))) {

        t0 = t1;
    }
  }
  return t0;

}

static __attribute__((__unused__)) float __cuda_atanf(float a)
{
  float t0, t1;


  t0 = __cuda_fabsf(a);
  t1 = t0;
  if (t0 > 1.0f) {
    t1 = 1.0f / t1;
  }

  t1 = __internal_atanf_kernel(t1);

  if (t0 > 1.0f) {
    t1 = 1.570796327f - t1;
  }



  {
    t1 = __int_as_float(__float_as_int(t1) | (__float_as_int(a) & 0x80000000));
  }
  return t1;
}


static __attribute__((__unused__)) float __internal_asinf_kernel(float a)
{
  float a2, t;
  a2 = a * a;
  t = 5.175137819e-002f;
  t = __internal_fmad (t, a2, 1.816697683e-002f);
  t = __internal_fmad (t, a2, 4.675685871e-002f);
  t = __internal_fmad (t, a2, 7.484657646e-002f);
  t = __internal_fmad (t, a2, 1.666701424e-001f);
  t = t * a2;
  a = __internal_fmad (t, a, a);
  return a;
}

static __attribute__((__unused__)) float __cuda_asinf(float a)
{
  float t0, t1, t2;

  t0 = __cuda_fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = __cuda_sqrtf(t2);
  t1 = t0 > 0.57f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t2 = __internal_fmad (-2.0f, t1, 1.570796327f);
  if (t0 > 0.57f) {
    t1 = t2;
  }



  {
    t1 = __int_as_float(__float_as_int(t1) | (__float_as_int(a) & 0x80000000));
  }
  return t1;
}

static __attribute__((__unused__)) float __cuda_acosf(float a)
{
  float t0, t1, t2;

  t0 = __cuda_fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = __cuda_sqrtf(t2);
  t1 = t0 > 0.57f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t1 = t0 > 0.57f ? 2.0f * t1 : 1.570796327f - t1;
  if (__cuda___signbitf(a)) {
    t1 = 3.141592654f - t1;
  }

  if (__cuda___isnanf(a)) {
    t1 = a + a;
  }

  return t1;
}

static __attribute__((__unused__)) float __cuda_logf(float a)
{





  return __internal_accurate_logf(a);

}

static __attribute__((__unused__)) float __cuda_log10f(float a)
{





  return 0.434294482f * __internal_accurate_logf(a);

}

static __attribute__((__unused__)) float __cuda_log1pf(float a)
{



  float t;






  if (a < -1.0f) return __int_as_float(0xffc00000);

  if (a >= -0.394f && a <= 0.65f) {

    t = a + 2.0f;
    t = __fdividef (a, t);
    t = -a * t;
    t = __internal_atanhf_kernel (a, t);
  } else {
    t = __internal_accurate_logf (1.0f + a);
  }
  return t;

}

static __attribute__((__unused__)) float __cuda_acoshf(float a)
{



  float t;



  if (a < 1.0f) return __int_as_float(0xffc00000);

  t = a - 1.0f;
  if (__cuda_fabsf(t) > 8388608.0f) {

    return 0.693147181f + __internal_accurate_logf(a);
  } else {
    t = t + __cuda_sqrtf(__fadd_rn(__fmul_rz(a, t), t));
    return __cuda_log1pf(t);
  }

}

static __attribute__((__unused__)) float __cuda_asinhf(float a)
{



  float fa, oofa, t;

  fa = __cuda_fabsf(a);
  if (fa > 8.507059173e37f) {
    t = 0.693147181f + __logf(fa);
  } else {
    oofa = 1.0f / fa;
    t =fa+__fdividef (fa,(oofa+__cuda_sqrtf(__internal_fmad(oofa,oofa,1.0f))));
    t = __cuda_log1pf(t);
  }



  {
    t = __int_as_float(__float_as_int(t) | (__float_as_int(a) & 0x80000000));
  }
  return t;

}

static __attribute__((__unused__)) float __cuda_atanhf(float a)
{



  float fa, t;

  fa = __cuda_fabsf(a);
  t = __fdividef ((2.0f * fa), (1.0f - fa));
  t = 0.5f * __cuda_log1pf(t);



  {
    t = __int_as_float(__float_as_int(t) | (__float_as_int(a) & 0x80000000));
  }
  return t;

}

static __attribute__((__unused__)) float __cuda_expm1f(float a)
{
  float t, z, j, u;

  t = __cuda_rintf (a * 1.442695041f);

  if (__cuda_fabsf(a) < 0.41f) {
    t = 0.0f;
  }
  z = __internal_fmad (-t, 0.6931457519f, a);
  z = __internal_fmad (-t, 1.4286067653e-6f, z);

  j = t;
  if (t == 128.0f) j = j - 1.0f;

  u = 1.38795078474044430E-003f;
  u = __internal_fmad (u, z, 8.38241261853264930E-003f);
  u = __internal_fmad (u, z, 4.16678317762833940E-002f);
  u = __internal_fmad (u, z, 1.66663978874356580E-001f);
  u = __internal_fmad (u, z, 4.99999940395997040E-001f);
  u = u * z;
  u = __internal_fmad (u, z, z);

  z = __cuda_exp2f (j);
  u = __internal_fmad (u, z, z - 1.0f);
  if (t == 128.0f) u = u + u;

  if (j > 128.0f) u = __int_as_float(0x7f800000);
  if (j < -25.0f) u = -1.0f;

  if (a == 0.0f) {
    u = __int_as_float(__float_as_int(a) & 0x80000000);
  }
  return u;
}

static __attribute__((__unused__)) float __cuda_hypotf(float a, float b)
{



  float v, w, s, t, fa, fb;

  fa = __cuda_fabsf(a);
  fb = __cuda_fabsf(b);
  v = s = __cuda_fmaxf(fa, fb);
  w = t = __cuda_fminf(fa, fb);
  if (v > 8.507059173e37f) {
    s = s * 0.25f;
    t = t * 0.25f;
  }
  t = __fdividef(t, s);
  t = __internal_fmad (t, t, 1.0f);
  t = v * __cuda_sqrtf(t);
  if (v == 0.0f) {
    t = v + w;
  }
  if ((!(fa <= __int_as_float(0x7f800000))) || (!(fb <= __int_as_float(0x7f800000)))) {
    t = a + b;
  }
  if (v == __int_as_float(0x7f800000)) {
    t = v + w;
  }
  return t;

}

static __attribute__((__unused__)) float __cuda_cbrtf(float a)
{



  float s, t;



  if (__cuda___isnanf(a)) return a + a;

  s = __cuda_fabsf(a);
  t = __cuda_exp2f(0.333333333f * __log2f(s));
  t = t - (t - (__fdividef (s, t * t))) * 0.333333333f;
  if (__cuda___signbitf(a)) {
    t = -t;
  }
  s = a + a;
  if (s == a) t = s;
  return t;

}

static __attribute__((__unused__)) float __cuda_rcbrtf(float a)
{
  float s, t;



  if (__cuda___isnanf(a)) return a + a;

  s = __cuda_fabsf(a);
  t = __cuda_exp2f(-0.333333333f * __log2f(s));
  t = __internal_fmad(__internal_fmad(t*t, -s*t, 1.0f), 0.333333333f*t, t);
  if (__cuda___signbitf(a)) {
    t = -t;
  }
  s = a + a;
  if (s == a) t = __fdividef (1.0f, a);
  return t;
}

static __attribute__((__unused__)) float __cuda_erff(float a)
{
  float t, r, q;

  t = __cuda_fabsf(a);
  if (t >= 1.0f) {



    q = __internal_fmad (t, 0.3275911f, 1.0f);
    q = 1.0f / q;
    r = 1.061405429f;
    r = __internal_fmad (r, q, -1.453152027f);
    r = __internal_fmad (r, q, 1.421413741f);
    r = __internal_fmad (r, q, -0.284496736f);
    r = __internal_fmad (r, q, 0.254829592f);
    r = r * q;
    q = __internal_expf_kernel(-a * a, 0.0f);
    r = __internal_fmad (-q, r, 1.0f);
    if (t >= 5.5f) {
      r = 1.0f;
    }
    a = __int_as_float (__float_as_int(r) | (__float_as_int(a) & 0x80000000));
  } else {
    t = a * a;
    r = -5.58510127926029810E-004f;
    r = __internal_fmad (r, t, 4.90688891415893070E-003f);
    r = __internal_fmad (r, t, -2.67027980930150640E-002f);
    r = __internal_fmad (r, t, 1.12799056505903940E-001f);
    r = __internal_fmad (r, t, -3.76122956138427440E-001f);
    r = __internal_fmad (r, t, 1.12837911712623450E+000f);
    a = a * r;
  }
  return a;
}

static __attribute__((__unused__)) float __cuda_erfinvf (float a)
{
  float fa, t;

  fa = __cuda_fabsf(a);
  if (fa >= 1.0f) {
    t = __cuda_rsqrtf (__int_as_float (0xffc00000));
    if (fa == 1.0f) {
      t = a * __int_as_float(0x7f800000);
    }
  } else if (fa > 0.9375f) {




    float p, q;

    t = __cuda_log1pf(-fa);
    t = __cuda_rsqrtf(-t);
    p = -1.64441567910e-1f;
    p = __internal_fmad (p, t, 6.80544246825e-1f);
    p = __internal_fmad (p, t, -1.12808139162e+0f);
    p = __internal_fmad (p, t, 6.90969348887e-1f);
    p = __internal_fmad (p, t, 1.38271964963e+0f);
    p = __internal_fmad (p, t, 1.55047000312e-1f);
    q = t + 1.38522814199e+0f;
    q = __internal_fmad (q, t, 1.55024849822e-1f);
    q = q * t;
    t = __fdividef (p, q);
    if (a < 0.0f) t = -t;
  } else if (fa > 0.75f) {




    float p, q;

    t = __internal_fmad (a, a, -0.87890625f);
    p = -7.1986748896e+0f;
    p = __internal_fmad (p, t, +1.3411974175e+1f);
    p = __internal_fmad (p, t, -5.1381573203e+0f);
    p = __internal_fmad (p, t, 4.9633374831e-1f);
    q = t -1.1436535838e+1f;
    q = __internal_fmad (q, t, 1.3568885572e+1f);
    q = __internal_fmad (q, t, -4.1747509256e+0f);
    q = __internal_fmad (q, t, 3.5327242323e-1f);
    p = __fdividef (p, q);
    t = a * p;
  } else {
    float a2;

    a2 = a * a;
    t = 6.1046168794766742E-001f;
    t = __internal_fmad (t, a2, -8.9504882462753121E-001f);
    t = __internal_fmad (t, a2, 7.0224162369928511E-001f);
    t = __internal_fmad (t, a2, -1.9993784895823222E-001f);
    t = __internal_fmad (t, a2, 1.1920613463949599E-001f);
    t = __internal_fmad (t, a2, 8.0131492246997685E-002f);
    t = __internal_fmad (t, a2, 1.2793154958377403E-001f);
    t = __internal_fmad (t, a2, 2.3200529172828793E-001f);
    t = __internal_fmad (t, a2, 8.8622695604694379E-001f);
    t = t * a;
  }
  return t;
}

static __attribute__((__unused__)) float __cuda_erfcf(float a)
{

  if (__cuda___isnanf(a)) return a + a;

  if (a <= 0.813f) {
    return 1.0f - __cuda_erff(a);
  } else {
    float p;
    float q;
    float h;
    float l;
    float t;
# 2553 "/usr/local/cuda/bin/../include/math_functions.h" 3
    t = __fdividef(1.0f, a);

    p = - 9.9910025099425892E-001f;
    p = __internal_fmad (p, t, - 2.6108451215634448E-001f);
    p = __internal_fmad (p, t, + 1.2460347155371844E-001f);
    p = __internal_fmad (p, t, + 1.3243909814778765E-001f);
    p = __internal_fmad (p, t, + 3.3477599162629441E-002f);
    q = t + 2.2542670016875404E+000f;
    q = __internal_fmad (q, t, + 2.1514433559696009E+000f);
    q = __internal_fmad (q, t, + 1.0284106806050302E+000f);
    q = __internal_fmad (q, t, + 2.6094298761636442E-001f);
    q = __internal_fmad (q, t, - 3.9951461024063317E-006f);

    p = __fdividef(p, q);
    p = p * t;


    h = __int_as_float(__float_as_int(a) & 0xfffff000);
    l = a - h;
    q = -h * h;
    q = __internal_expf_kernel(q, 0.0f);
    h = a + h;
    l = l * h;
    h = __internal_expf_kernel(-l, -1.0f);
    q = q * h;






    p = __internal_fmad (p, q, q);
    p = p * t;
    if (a > 10.055f) {
      p = 0.0f;
    }
    return p;
  }
}

static __attribute__((__unused__)) float __cuda_erfcinvf (float a)
{
  float t;

  if (__cuda___isnanf(a)) return a + a;

  if (a <= 0.0f) {
    t = __cuda_rsqrtf (__int_as_float (0xffc00000));
    if (a == 0.0f) {
      t = (1.0f - a) * __int_as_float(0x7f800000);
    }
  }
  else if (a >= 0.0625f) {
    t = __cuda_erfinvf (1.0f - a);
  }
  else {
    float p, q;
    t = __cuda_logf(a);
    t = __cuda_rsqrtf(-t);
    p = -1.64441567910e-1f;
    p = __internal_fmad (p, t, 6.80544246825e-1f);
    p = __internal_fmad (p, t, -1.12808139162e+0f);
    p = __internal_fmad (p, t, 6.90969348887e-1f);
    p = __internal_fmad (p, t, 1.38271964963e+0f);
    p = __internal_fmad (p, t, 1.55047000312e-1f);
    q = t + 1.38522814199e+0f;
    q = __internal_fmad (q, t, 1.55024849822e-1f);
    q = q * t;
    t = __fdividef (p, q);
  }
  return t;
}

static __attribute__((__unused__)) float __cuda_lgammaf(float a)
{
  float t;
  float i;
  int quot;

  if (__cuda___isnanf(a)) return a + a;

  t = __internal_lgammaf_pos(__cuda_fabsf(a));
  if (a >= 0.0f) return t;
  a = __cuda_fabsf(a);
  i = __cuda_floorf(a);
  if (a == i) return __int_as_float(0x7f800000);
  if (a < 1e-19f) return -__internal_accurate_logf(a);
  i = __cuda_rintf (2.0f * a);
  quot = (int)i;
  i = __internal_fmad (-i, 0.5f, a);
  i = i * 3.141592654f;
  if (quot & 1) {
    i = __internal_cos_kernel(i);
  } else {
    i = __internal_sin_kernel(i);
  }
  i = __cuda_fabsf(i);
  t = 1.144729886f - __internal_accurate_logf(i * a) - t;
  return t;
}

static __attribute__((__unused__)) float __cuda_ldexpf(float a, int b)
{



  float fa = __cuda_fabsf(a);

  if ((fa == 0.0f) || (fa == __int_as_float(0x7f800000)) || (b == 0)) {
    if (!(fa > 0.0f)) a = a + a;
    return a;
  } else if (__cuda_abs(b) < 126) {
    return a * __cuda_exp2f((float)b);
  } else if (__cuda_abs(b) < 252) {
    int bhalf = b / 2;
    return a * __cuda_exp2f((float)bhalf) * __cuda_exp2f((float)(b - bhalf));
  } else {
    int bquarter = b / 4;
    float t = __cuda_exp2f((float)bquarter);
    return a * t * t * t * __cuda_exp2f((float)(b - 3 * bquarter));
  }

}

static __attribute__((__unused__)) float __cuda_scalbnf(float a, int b)
{




  return __cuda_ldexpf(a, b);

}

static __attribute__((__unused__)) float __cuda_scalblnf(float a, long int b)
{



  int t;
  if (b > 2147483647L) {
    t = 2147483647;
  } else if (b < (-2147483647 - 1)) {
    t = (-2147483647 - 1);
  } else {
    t = (int)b;
  }
  return __cuda_scalbnf(a, t);

}

static __attribute__((__unused__)) float __cuda_frexpf(float a, int *b)
{
  float fa = __cuda_fabsf(a);
  unsigned int expo;
  unsigned int denorm;

  if (fa < 1.175494351e-38f) {
    a *= 16777216.0f;
    denorm = 24;
  } else {
    denorm = 0;
  }
  expo = ((__float_as_int(a) >> 23) & 0xff);
  if ((fa == 0.0f) || (expo == 0xff)) {
    expo = 0;
    a = a + a;
  } else {
    expo = expo - denorm - 126;
    a = __int_as_float(((__float_as_int(a) & 0x807fffff) | 0x3f000000));
  }
  *b = expo;
  return a;
}

static __attribute__((__unused__)) float __cuda_modff(float a, float *b)
{



  float t;
  if (__cuda___finitef(a)) {
    t = __cuda_truncf(a);
    *b = t;
    t = a - t;
    t = __int_as_float(__float_as_int(t) | (__float_as_int(a) & 0x80000000));
    return t;
  } else if (__cuda___isinff(a)) {
    *b = a;
    return __int_as_float(__float_as_int(a) & 0x80000000);
  } else {
    *b = a + a;
    return a + a;
  }

}

static __attribute__((__unused__)) float __cuda_fmodf(float a, float b)
{



  float orig_a = a;
  float orig_b = b;
  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {


    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }







    while (scaled_b >= b) {
      if (a >= scaled_b) {
        a -= scaled_b;
      }
      scaled_b *= 0.5f;
    }
    return __int_as_float (__float_as_int(a) |
                           (__float_as_int(orig_a) & 0x80000000));
  } else {
    if (!(a > 0.0f)) orig_a = orig_a + orig_a;
    return orig_a;
  }

}

static __attribute__((__unused__)) float __cuda_remainderf(float a, float b)
{

  float twoa = 0.0f;
  unsigned int quot0 = 0;
  float orig_a = a;
  float orig_b = b;

  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {

    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
# 2835 "/usr/local/cuda/bin/../include/math_functions.h" 3
    while (scaled_b >= b) {
      quot0 = 0;
      if (a >= scaled_b) {
        twoa = __internal_fmad (a, 2.0f, -scaled_b) - scaled_b;
        a = a - scaled_b;
        quot0 = 1;
      }
      scaled_b *= 0.5f;
    }
  }


  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && quot0)) {
    a -= b;
    a = __int_as_float(__float_as_int(a) | 0x80000000);
  }
# 2867 "/usr/local/cuda/bin/../include/math_functions.h" 3
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  return a;
}

static __attribute__((__unused__)) float __cuda_remquof(float a, float b, int* quo)
{
  float twoa = 0.0f;
  unsigned int quot = 0;
  unsigned int sign;
  float orig_a = a;
  float orig_b = b;


  sign = 0 - (__cuda___signbitf(a) != __cuda___signbitf(b));
  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    *quo = quot;
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    *quo = quot;
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {


    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
# 2923 "/usr/local/cuda/bin/../include/math_functions.h" 3
    while (scaled_b >= b) {
      quot <<= 1;
      if (a >= scaled_b) {
        twoa = (2.0f * a - scaled_b) - scaled_b;
        a -= scaled_b;
        quot += 1;
      }
      scaled_b *= 0.5f;
    }
  }


  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && (quot & 1))) {
    quot++;
    a -= b;
    a = __int_as_float(__float_as_int(a) | 0x80000000);
  }
# 2958 "/usr/local/cuda/bin/../include/math_functions.h" 3
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  quot = quot & (~((~0)<<3));
  quot = quot ^ sign;
  quot = quot - sign;
  *quo = quot;
  return a;
}

static __attribute__((__unused__)) float __cuda_fmaf(float a, float b, float c)
{
  return __fmaf_rn(a, b, c);
}

static __attribute__((__unused__)) float __internal_accurate_powf(float a, float b)
{
  float2 loga, prod;



  float t;


  loga = __internal_log_ep(a);


  if (__cuda_fabsf(b) > 1.0e34f) b *= 1.220703125e-4f;
  prod.y = b;
  prod.x = 0.0f;
  prod = __internal_dsmul (prod, loga);


  if (__float_as_int(prod.y) == 0x42b17218) {
    prod.y = __int_as_float(__float_as_int(prod.y) - 1);
    prod.x = prod.x + __int_as_float(0x37000000);
  }


  t = __cuda_expf(prod.y);

  if (t != __int_as_float(0x7f800000)) {



    t = __internal_fmad (t, prod.x, t);
  }
  return t;
}

static __attribute__((__unused__)) float __cuda_powif(float a, int b)
{
  unsigned int e = __cuda_abs(b);

  volatile

  float r = 1.0f;

  while (1) {
    if ((e & 1) != 0) {
      r = __fmul_rn (r, a);
    }
    e = e >> 1;
    if (e == 0) {
      r = (b < 0) ? 1.0f / r : r;
      return r;
    }
    a = __fmul_rn (a, a);
  }
}

static __attribute__((__unused__)) double __cuda_powi(double a, int b)
{
  unsigned int e = __cuda_abs(b);
  double r = 1.0;

  while (1) {
    if ((e & 1) != 0) {
      r = r * a;
    }
    e = e >> 1;
    if (e == 0) {
      return b < 0 ? 1.0 / r : r;
    }
    a = a * a;
  }
}

static __attribute__((__unused__)) float __cuda_powf(float a, float b)
{





  int bIsOddInteger;
  float t;
  if (a == 1.0f || b == 0.0f) {
    return 1.0f;
  }
  if (__cuda___isnanf(a) || __cuda___isnanf(b)) {
    return a + b;
  }
  if (a == __int_as_float(0x7f800000)) {
    return __cuda___signbitf(b) ? 0.0f : __int_as_float(0x7f800000);
  }
  if (__cuda___isinff(b)) {
    if (a == -1.0f) {
      return 1.0f;
    }
    t = (__cuda_fabsf(a) > 1.0f) ? __int_as_float(0x7f800000) : 0.0f;
    if (b < 0.0f) {
      t = 1.0f / t;
    }
    return t + t;
  }
  bIsOddInteger = __cuda_fabsf(b - (2.0f * __cuda_truncf(0.5f * b))) == 1.0f;
  if (a == 0.0f) {
    t = bIsOddInteger ? a : 0.0f;
    if (b < 0.0f) {
      t = 1.0f / t;
    }
    return t + t;
  }
  if (a == -__int_as_float(0x7f800000)) {
    t = - ((b < 0.0f) ? (1.0f / a) : a);
    if (bIsOddInteger) {
      t = __int_as_float(__float_as_int(t) ^ 0x80000000);
    }
    return t;
  }
  if ((a < 0.0f) && (b != __cuda_truncf(b))) {
    return __cuda_rsqrtf(__int_as_float(0xffc00000));
  }
  t = __cuda_fabsf(a);
  t = __internal_accurate_powf(t, b);
  if ((a < 0.0f) && bIsOddInteger) {
    t = __int_as_float(__float_as_int(t) ^ 0x80000000);
  }
  return t;

}


static __attribute__((__unused__)) float __internal_tgammaf_kernel(float a)
{
  float t;
  t = -1.05767296987211380E-003f;
  t = __internal_fmad (t, a, 7.09279059435508670E-003f);
  t = __internal_fmad (t, a, -9.65347121958557050E-003f);
  t = __internal_fmad (t, a, -4.21736613253687960E-002f);
  t = __internal_fmad (t, a, 1.66542401247154280E-001f);
  t = __internal_fmad (t, a, -4.20043267827838460E-002f);
  t = __internal_fmad (t, a, -6.55878234051332940E-001f);
  t = __internal_fmad (t, a, 5.77215696929794240E-001f);
  t = __internal_fmad (t, a, 1.00000000000000000E+000f);
  return t;
}





static __attribute__((__unused__)) float __cuda_tgammaf(float a)
{
  float s, xx, x=a;
  if (x >= 0.0f) {
    if (x > 36.0f) x = 36.0f;
    s = 1.0f;
    xx = x;
    if (x > 34.03f) {
      xx -= 1.0f;
    }
    while (xx > 1.5f) {
      xx = xx - 1.0f;
      s = s * xx;
    }
    if (x >= 0.5f) {
      xx = xx - 1.0f;
    }
    xx = __internal_tgammaf_kernel(xx);
    if (x < 0.5f) {
      xx = xx * x;
    }
    s = __fdividef(s, xx);
    if (x > 34.03f) {

      xx = x - 1.0f;
      s = s * xx;
    }
    return s;
  } else {
    if (x == __cuda_floorf(x)) {
      x = __cuda_rsqrtf (__int_as_float (0xffc00000));

      return x;

    }
    if (x < -41.1f) x = -41.1f;
    xx = x;
    if (x < -34.03f) {
      xx += 6.0f;
    }
    s = xx;
    while (xx < -0.5f) {
      xx = xx + 1.0f;
      s = s * xx;
    }
    xx = __internal_tgammaf_kernel(xx);
    s = s * xx;
    s = 1.0f / s;
    if (x < -34.03f) {
      xx = x;
      xx *= (x + 1.0f);
      xx *= (x + 2.0f);
      xx *= (x + 3.0f);
      xx *= (x + 4.0f);
      xx *= (x + 5.0f);
      xx = 1.0f / xx;
      s = s * xx;
      if ((a < -42.0f) && !(((int)a)&1)) {
        s = __int_as_float(0x80000000);
      }
    }
    return s;
  }
}

static __attribute__((__unused__)) float __cuda_roundf(float a)
{



  float fa = __cuda_fabsf(a);
  float u = __int_as_float (0x3f000000 | (__float_as_int(a) & 0x80000000));
  u = __cuda_truncf (a + u);
  if (fa > 8388608.0f) u = a;
  if (fa < 0.5f) u = __cuda_truncf (a);
  return u;

}

static __attribute__((__unused__)) long long int __internal_llroundf_kernel(float a)
{
  unsigned long long int res, t = 0LL;
  int shift;
  unsigned int ia = __float_as_int(a);

  if ((ia << 1) > 0xff000000) return 0x8000000000000000LL;
  if ((int)ia >= 0x5f000000) return 0x7fffffffffffffffLL;
  if (ia >= 0xdf000000) return 0x8000000000000000LL;
  shift = 189 - ((ia >> 23) & 0xff);
  res = ((long long int)(((ia << 8) | 0x80000000) >> 1)) << 32;
  if (shift >= 64) {
    t = res;
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (t >= 0x8000000000000000LL) {
    res++;
  }
  if ((int)ia < 0) res = (unsigned long long int)(-(long long int)res);
  return (long long int)res;
}

static __attribute__((__unused__)) long long int __cuda_llroundf(float a)
{



  return __internal_llroundf_kernel(a);

}

static __attribute__((__unused__)) long int __cuda_lroundf(float a)
{




  return (long int)__cuda_llroundf(a);
# 3249 "/usr/local/cuda/bin/../include/math_functions.h" 3
}

static __attribute__((__unused__)) float __cuda_fdimf(float a, float b)
{
  float t;
  t = a - b;
  if (a <= b) {
    t = 0.0f;
  }
  return t;
}

static __attribute__((__unused__)) int __cuda_ilogbf(float a)
{
  unsigned int i;
  int expo;
  float fa;
  fa = __cuda_fabsf(a);
  i = __float_as_int(fa);
  if (i < 0x00800000) {

    expo = -118 - __clz(i);
    if (i == 0x00000000) {
      expo = -((int)((unsigned int)-1 >> 1))-1;
    }
  } else {
    expo = ((int)((i >> 23) & 0xff)) - 127;
    if ((i == 0x7f800000)) {
      expo = ((int)((unsigned int)-1 >> 1));
    }
    if ((i > 0x7f800000)) {
      expo = -((int)((unsigned int)-1 >> 1))-1;
    }
  }
  return expo;
}

static __attribute__((__unused__)) float __cuda_logbf(float a)
{



  unsigned int i;
  int expo;
  float fa, res;
  fa = __cuda_fabsf(a);
  i = __float_as_int(fa);
  if (i < 0x00800000) {

    expo = -118 - __clz(i);
    res = (float)expo;
    if (a == 0.0f) {
      res = -__int_as_float(0x7f800000);
    }
  } else {
    expo = ((int)((i >> 23) & 0xff)) - 127;
    res = (float)expo;
    if ((i >= 0x7f800000)) {

      res = a * a;
    }
  }
  return res;

}

static __attribute__((__unused__)) void __cuda_sincosf(float a, float *sptr, float *cptr)
{





  float t, u, s, c;
  int quadrant;
  t = __cuda_fabsf(a);
  if ((t == __int_as_float(0x7f800000)) || (t == 0.0f)) {
    s = __fmul_rn (a, 0.0f);
    c = 1.0f + s;
    *sptr = s;
    *cptr = c;
    return;
  }
  t = __internal_trig_reduction_kernel(a, &quadrant);
  u = __internal_cos_kernel(t);
  t = __internal_sin_kernel(t);
  if (quadrant & 1) {
    s = u;
    c = t;
  } else {
    s = t;
    c = u;
  }
  if (quadrant & 2) {
    s = -s;
  }
  quadrant++;
  if (quadrant & 2) {
    c = -c;
  }
  *sptr = s;
  *cptr = c;

}
# 4998 "/usr/local/cuda/bin/../include/math_functions.h" 3


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



  if (__signbit(a)) {

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







extern __attribute__((__weak__)) long long int llabs(long long int a); long long int llabs(long long int a)
{
  return a < 0ll ? -a : a;
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


# 5329 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 1 3
# 61 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
static __attribute__((__unused__)) double __cuda_fabs(double a)
{
  return fabs(a);
}

static __attribute__((__unused__)) double __cuda_fmax(double a, double b)
{

  volatile union __cudart_DoubleUlonglongCvt cvta, cvtb;
  int nana, nanb;

  cvta.d = a;
  cvtb.d = b;
  nana = ((cvta.i << 1) > 0xffe0000000000000ULL);
  nanb = ((cvtb.i << 1) > 0xffe0000000000000ULL);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.d == 0.0) && (cvtb.d == 0.0)) {
    cvta.i &= cvtb.i;
    return cvta.d;
  }
  return a > b ? a : b;



}

static __attribute__((__unused__)) double __cuda_fmin(double a, double b)
{

  volatile union __cudart_DoubleUlonglongCvt cvta, cvtb;
  int nana, nanb;

  cvta.d = a;
  cvtb.d = b;
  nana = ((cvta.i << 1) > 0xffe0000000000000ULL);
  nanb = ((cvtb.i << 1) > 0xffe0000000000000ULL);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.i | cvtb.i) == 0x8000000000000000ULL) {
    return __longlong_as_double(0x8000000000000000ULL) ;
  }
  return a < b ? a : b;



}

static __attribute__((__unused__)) double __cuda_ceil(double a)
{
  return ceil(a);
}

static __attribute__((__unused__)) double __cuda_floor(double a)
{
  return floor(a);
}

static __attribute__((__unused__)) double __cuda_trunc(double a)
{
  return trunc(a);
}

static __attribute__((__unused__)) double __cuda_nearbyint(double a)
{



  double res = nearbyint(a);





  return res;

}







static __attribute__((__unused__)) double __cuda_rint(double a)
{
  return __cuda_nearbyint(a);
}

static __attribute__((__unused__)) long int __cuda_lrint(double a)
{

  return (long int)__double2ll_rn(a);



}

static __attribute__((__unused__)) long long int __cuda_llrint(double a)
{
  return __double2ll_rn(a);
}

static __attribute__((__unused__)) int __cuda___signbit(double a)
{
  return (int)((unsigned int)__double2hiint(a) >> 31);
}

static __attribute__((__unused__)) int __cuda___finite(double a)
{
  return __cuda_fabs(a) < __longlong_as_double(0x7ff0000000000000ULL);
}

static __attribute__((__unused__)) int __cuda___isinf(double a)
{
  return __cuda_fabs(a) == __longlong_as_double(0x7ff0000000000000ULL);
}

static __attribute__((__unused__)) int __cuda___isnan(double a)
{
  return !(__cuda_fabs(a) <= __longlong_as_double(0x7ff0000000000000ULL));
}

static __attribute__((__unused__)) double __cuda_copysign(double a, double b)
{
  int alo, ahi, bhi;

  bhi = __double2hiint(b);
  alo = __double2loint(a);
  ahi = __double2hiint(a);
  ahi = (bhi & 0x80000000) | (ahi & ~0x80000000);
  return __hiloint2double(ahi, alo);
}


static __attribute__((__unused__)) double __internal_copysign_pos(double a, double b)
{
  int alo, ahi, bhi;

  bhi = __double2hiint(b);
  alo = __double2loint(a);
  ahi = __double2hiint(a);
  ahi = (bhi & 0x80000000) | ahi;
  return __hiloint2double(ahi, alo);
}


static unsigned long long int __cudart_i2opi_d [] = {
  0x6bfb5fb11f8d5d08ULL,
  0x3d0739f78a5292eaULL,
  0x7527bac7ebe5f17bULL,
  0x4f463f669e5fea2dULL,
  0x6d367ecf27cb09b7ULL,
  0xef2f118b5a0a6d1fULL,
  0x1ff897ffde05980fULL,
  0x9c845f8bbdf9283bULL,
  0x3991d639835339f4ULL,
  0xe99c7026b45f7e41ULL,
  0xe88235f52ebb4484ULL,
  0xfe1deb1cb129a73eULL,
  0x06492eea09d1921cULL,
  0xb7246e3a424dd2e0ULL,
  0xfe5163abdebbc561ULL,
  0xdb6295993c439041ULL,
  0xfc2757d1f534ddc0ULL,
  0xa2f9836e4e441529ULL,
};

static __attribute__((__unused__)) double __internal_trig_reduction_kerneld(double a, int *quadrant)
{
  double j;
  int q;
  if (__cuda_fabs(a) > 2147483648.0) {

    unsigned long long int ia;
    unsigned long long int s;
    unsigned long long int result[5];
    unsigned long long int phi, plo;
    unsigned long long int hi, lo;
    unsigned int e;
    int idx;

    ia = __double_as_longlong(a);
    s = ia & 0x8000000000000000ULL;
    e = (unsigned int)(((ia >> 52) & 0x7ff) - 1024);
    ia = (ia << 11) | 0x8000000000000000ULL;

    idx = 16 - (e >> 6);
    hi = 0;



    for (q = (idx-1); q < min(18,idx+3); q++) {
      plo = __cudart_i2opi_d[q] * ia;
      phi = __umul64hi (__cudart_i2opi_d[q], ia);
      lo = hi + plo;
      hi = phi + (lo < plo);
      result[q-(idx-1)] = lo;
    }
    result[q-(idx-1)] = hi;
    e = e & 63;



    hi = result[3];
    lo = result[2];
    if (e) {
      q = 64 - e;
      hi = (hi << e) | (lo >> q);
      lo = (lo << e) | (result[1] >> q);
    }
    q = (int)(hi >> 62);

    hi = (hi << 2) | (lo >> 62);
    lo = (lo << 2);
    e = (hi | (lo > 0)) > 0x8000000000000000ULL;
    q += e;
    if (s) q = -q;
    if (e) {
      unsigned long long int t;
      hi = ~hi;
      lo = -(long long int)lo;
      t = (lo == 0ULL);
      hi += t;
      s = s ^ 0x8000000000000000ULL;
    }
    *quadrant = q;

    e = 0;
    while ((long long int)hi > 0) {
      hi = (hi << 1) | (lo >> 63);
      lo = (lo << 1);
      e--;
    }
    lo = hi * 0xC90FDAA22168C235ULL;
    hi = __umul64hi (hi, 0xC90FDAA22168C235ULL);
    if ((long long int)hi > 0) {
      hi = (hi << 1) | (lo >> 63);
      lo = (lo << 1);
      e--;
    }
    hi = hi + (lo > 0);
    ia = s | ((((unsigned long long int)(e + 1022)) << 52) + (hi >> 11) +
              ((hi << 53) >= 0x8000000000000000ULL));
    return __longlong_as_double(ia);
  }

  q = __double2int_rn (a * 6.3661977236758138e-1);
  j = (double)q;




  a = __fma_rn (-j, 1.5707963267948966e+000, a);
  a = __fma_rn (-j, 6.1232339957367574e-017, a);
  a = __fma_rn (-j, 8.4784276603688985e-032, a);
  *quadrant = q;
  return a;
}


static __attribute__((__unused__)) double __internal_sin_kerneld(double x)
{
  double x2, z;
  x2 = x * x;
  z = 1.5896230157221844E-010;
  z = __fma_rn (z, x2, -2.5050747762850355E-008);
  z = __fma_rn (z, x2, 2.7557313621385676E-006);
  z = __fma_rn (z, x2, -1.9841269829589539E-004);
  z = __fma_rn (z, x2, 8.3333333333221182E-003);
  z = __fma_rn (z, x2, -1.6666666666666630E-001);
  z = z * x2;
  z = __fma_rn (z, x, x);
  return z;
}


static __attribute__((__unused__)) double __internal_cos_kerneld(double x)
{
  double x2, z;
  x2 = x * x;
  z = -1.136788825395985E-011;
  z = __fma_rn (z, x2, 2.087588480545065E-009);
  z = __fma_rn (z, x2, -2.755731555403950E-007);
  z = __fma_rn (z, x2, 2.480158729365970E-005);
  z = __fma_rn (z, x2, -1.388888888888074E-003);
  z = __fma_rn (z, x2, 4.166666666666664E-002);
  z = __fma_rn (z, x2, -5.000000000000000E-001);
  z = __fma_rn (z, x2, 1.000000000000000E+000);
  return z;
}


static __attribute__((__unused__)) double __internal_tan_kerneld(double x, int i)
{
  double x2, z, q;
  x2 = x * x;
  z = 9.8006287203286300E-006;
  z = __fma_rn (z, x2, -2.4279526494179897E-005);
  z = __fma_rn (z, x2, 4.8644173130937162E-005);
  z = __fma_rn (z, x2, -2.5640012693782273E-005);
  z = __fma_rn (z, x2, 6.7223984330880073E-005);
  z = __fma_rn (z, x2, 8.3559287318211639E-005);
  z = __fma_rn (z, x2, 2.4375039850848564E-004);
  z = __fma_rn (z, x2, 5.8886487754856672E-004);
  z = __fma_rn (z, x2, 1.4560454844672040E-003);
  z = __fma_rn (z, x2, 3.5921008885857180E-003);
  z = __fma_rn (z, x2, 8.8632379218613715E-003);
  z = __fma_rn (z, x2, 2.1869488399337889E-002);
  z = __fma_rn (z, x2, 5.3968253972902704E-002);
  z = __fma_rn (z, x2, 1.3333333333325342E-001);
  z = __fma_rn (z, x2, 3.3333333333333381E-001);
  z = z * x2;
  q = __fma_rn (z, x, x);
  if (i) {
    double s = q - x;
    double w = __fma_rn (z, x, -s);
    z = 1.0 / q;
    z = -z;
    s = __fma_rn (q, z, 1.0);
    q = __fma_rn (z, __fma_rn (z, w, s), z);
  }
  return q;
}

static __attribute__((__unused__)) double __cuda_sqrt(double a)
{
  return sqrt(a);
}

static __attribute__((__unused__)) double __cuda_rsqrt(double a)
{

    return 1.0 / sqrt(a);



}


static __attribute__((__unused__)) double __internal_expm1_kernel (double a)
{
  double t;
  t = 2.08842685477913050E-009;
  t = __fma_rn (t, a, 2.51366409033551950E-008);
  t = __fma_rn (t, a, 2.75574612072447230E-007);
  t = __fma_rn (t, a, 2.75571539284473460E-006);
  t = __fma_rn (t, a, 2.48015869443077950E-005);
  t = __fma_rn (t, a, 1.98412699878799470E-004);
  t = __fma_rn (t, a, 1.38888888892029890E-003);
  t = __fma_rn (t, a, 8.33333333327662860E-003);
  t = __fma_rn (t, a, 4.16666666666656370E-002);
  t = __fma_rn (t, a, 1.66666666666667380E-001);
  t = __fma_rn (t, a, 5.00000000000000000E-001);
  t = t * a;
  t = __fma_rn (t, a, a);
  return t;
}


static __attribute__((__unused__)) double __internal_atanh_kernel (double a_1, double a_2)
{
  double a, a2, t;

  a = a_1 + a_2;
  a2 = a * a;
  t = 7.597322383488143E-002/65536.0;
  t = __fma_rn (t, a2, 6.457518383364042E-002/16384.0);
  t = __fma_rn (t, a2, 7.705685707267146E-002/4096.0);
  t = __fma_rn (t, a2, 9.090417561104036E-002/1024.0);
  t = __fma_rn (t, a2, 1.111112158368149E-001/256.0);
  t = __fma_rn (t, a2, 1.428571416261528E-001/64.0);
  t = __fma_rn (t, a2, 2.000000000069858E-001/16.0);
  t = __fma_rn (t, a2, 3.333333333333198E-001/4.0);
  t = t * a2;
  t = __fma_rn (t, a, a_2);
  t = t + a_1;
  return t;
}

static __attribute__((__unused__)) double __internal_exp2i_kernel(int b)
{
  return __hiloint2double((b + 1023) << 20, 0);
}

static __attribute__((__unused__)) double __internal_half(double a)
{
  unsigned int ihi, ilo;
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  return __hiloint2double(ihi - 0x00100000, ilo);
}

static __attribute__((__unused__)) double __internal_twice(double a)
{
  unsigned int ihi, ilo;
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  return __hiloint2double(ihi + 0x00100000, ilo);
}

static __attribute__((__unused__)) double __cuda_sin(double a)
{
  double z;
  int i;
  if (__cuda___isinf(a) || (a == 0.0)) {
    return __dmul_rn(a, 0.0);
  }
  z = __internal_trig_reduction_kerneld(a, &i);

  if (i & 1) {
    z = __internal_cos_kerneld(z);
  } else {
    z = __internal_sin_kerneld(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}

static __attribute__((__unused__)) double __cuda_sinpi(double a)
{
  double z;
  double fi;
  int i;

  if (__cuda___isinf(a) || (a == 0.0)) {
    return __dmul_rn(a, 0.0);
  }

  if (a == __cuda_trunc(a)) {
    return __longlong_as_double(__double_as_longlong(a)&0x8000000000000000ULL);
  }
  fi = __cuda_rint (a * 2.0);
  z = __fma_rn (fi, -0.5, a);
  z = __fma_rn (z, 3.1415926535897931e+0, z * 1.2246467991473532e-16);
  i = (int)(((long long)fi) & 3);
  if (i & 1) {
    z = __internal_cos_kerneld(z);
  } else {
    z = __internal_sin_kerneld(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}

static __attribute__((__unused__)) double __cuda_cos(double a)
{
  double z;
  int i;
  if (__cuda___isinf(a)) {
    return __longlong_as_double(0xfff8000000000000ULL);
  }
  z = __internal_trig_reduction_kerneld(a, &i);

  i++;
  if (i & 1) {
    z = __internal_cos_kerneld(z);
  } else {
    z = __internal_sin_kerneld(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}

static __attribute__((__unused__)) void __cuda_sincos(double a, double *sptr, double *cptr)
{
  double t, u, s, c;
  int i;
  t = __cuda_fabs(a);
  if ((t == __longlong_as_double(0x7ff0000000000000ULL)) || (t == 0.0)) {
    s = __dmul_rn (a, 0.0);
    c = 1.0 + s;
    *sptr = s;
    *cptr = c;
    return;
  }
  t = __internal_trig_reduction_kerneld(a, &i);
  u = __internal_cos_kerneld(t);
  t = __internal_sin_kerneld(t);
  if (i & 1) {
    s = u;
    c = t;
  } else {
    s = t;
    c = u;
  }
  if (i & 2) {
    s = -s;
  }
  i++;
  if (i & 2) {
    c = -c;
  }
  *sptr = s;
  *cptr = c;
}

static __attribute__((__unused__)) double __cuda_tan(double a)
{
  double z;
  int i;
  if (__cuda___isinf(a)) {
    return __dadd_rn (a, -a);
  }
  z = __internal_trig_reduction_kerneld(a, &i);

  z = __internal_tan_kerneld(z, i & 1);
  return z;
}

static __attribute__((__unused__)) double __cuda_log(double a)
{
  double m, f, g, u, v, tmp, q, ulo, log_lo, log_hi;
  int ihi, ilo;

  ihi = __double2hiint(a);
  ilo = __double2loint(a);

  if ((a > 0.0) && (a < __longlong_as_double(0x7ff0000000000000ULL))) {
    int e = -1023;

    if ((unsigned)ihi < (unsigned)0x00100000) {
      a = a * 18014398509481984.0;
      e -= 54;
      ihi = __double2hiint(a);
      ilo = __double2loint(a);
    }



    e += (ihi >> 20);
    ihi = (ihi & 0x800fffff) | 0x3ff00000;
    m = __hiloint2double (ihi, ilo);
    if ((unsigned)ihi > (unsigned)0x3ff6a09e) {
      m = __internal_half(m);
      e = e + 1;
    }

    f = m - 1.0;
    g = m + 1.0;
    g = 1.0 / g;
    u = f * g;
    u = u + u;

    v = u * u;
    q = 6.7261411553826339E-2/65536.0;
    q = __fma_rn (q, v, 6.6133829643643394E-2/16384.0);
    q = __fma_rn (q, v, 7.6940931149150890E-2/4096.0);
    q = __fma_rn (q, v, 9.0908745692137444E-2/1024.0);
    q = __fma_rn (q, v, 1.1111111499059706E-1/256.0);
    q = __fma_rn (q, v, 1.4285714283305975E-1/64.0);
    q = __fma_rn (q, v, 2.0000000000007223E-1/16.0);
    q = __fma_rn (q, v, 3.3333333333333326E-1/4.0);
    tmp = 2.0 * (f - u);
    tmp = __fma_rn (-u, f, tmp);
    ulo = g * tmp;

    q = q * v;
    q = q * u;

    log_hi = u;
    log_lo = ulo + q;

    q = __fma_rn ( e, 6.9314718055994529e-1, log_hi);
    tmp = __fma_rn (-e, 6.9314718055994529e-1, q);
    tmp = tmp - log_hi;
    log_hi = q;
    log_lo = log_lo - tmp;
    log_lo = __fma_rn (e, 2.3190468138462996e-17, log_lo);
    return log_hi + log_lo;
  } else {
    if (__cuda___isnan(a)) {
      return a + a;
    }

    if (a == 0) {
      return -__longlong_as_double(0x7ff0000000000000ULL);
    }

    if (a == __longlong_as_double(0x7ff0000000000000ULL)) {
      return a;
    }

    return __longlong_as_double(0xfff8000000000000ULL);
  }
}


static __attribute__((__unused__)) double2 __internal_ddadd_xgty (double2 x, double2 y)
{
  double2 z;

  volatile

  double r, s, e;
  r = x.y + y.y;
  e = x.y - r;
  s = ((e + y.y) + y.x) + x.x;
  z.y = e = r + s;
  z.x = (r - e) + s;
  return z;
}


static __attribute__((__unused__)) double2 __internal_ddmul (double2 x, double2 y)
{

  volatile

  double e;
  double2 t, z;
  t.y = x.y * y.y;
  t.x = __fma_rn (x.y, y.y, -t.y);
  t.x = __fma_rn (x.x, y.x, t.x);
  t.x = __fma_rn (x.y, y.x, t.x);
  t.x = __fma_rn (x.x, y.y, t.x);
  z.y = e = t.y + t.x;
  z.x = (t.y - e) + t.x;
  return z;
}

static __attribute__((__unused__)) double2 __internal_log_ext_prec(double a)
{
  double2 res;
  double2 qq, cc, uu, tt;
  double f, g, u, v, q, ulo, tmp, m;
  int ilo, ihi, expo;

  ihi = __double2hiint(a);
  ilo = __double2loint(a);
  expo = (ihi >> 20) & 0x7ff;

  if (expo == 0) {
    a *= 18014398509481984.0;
    ihi = __double2hiint(a);
    ilo = __double2loint(a);
    expo = (ihi >> 20) & 0x7ff;
    expo -= 54;
  }
  expo -= 1023;




  ihi = (ihi & 0x800fffff) | 0x3ff00000;
  m = __hiloint2double (ihi, ilo);
  if ((unsigned)ihi > (unsigned)0x3ff6a09e) {
    m = __internal_half(m);
    expo = expo + 1;
  }





  f = m - 1.0;
  g = m + 1.0;
  g = 1.0 / g;
  u = f * g;
  u = u + u;

  v = u * u;
  q = 6.6253631649203309E-2/65536.0;
  q = __fma_rn (q, v, 6.6250935587260612E-2/16384.0);
  q = __fma_rn (q, v, 7.6935437806732829E-2/4096.0);
  q = __fma_rn (q, v, 9.0908878711093280E-2/1024.0);
  q = __fma_rn (q, v, 1.1111111322892790E-1/256.0);
  q = __fma_rn (q, v, 1.4285714284546502E-1/64.0);
  q = __fma_rn (q, v, 2.0000000000003113E-1/16.0);
  q = q * v;

  tmp = 2.0 * (f - u);
  tmp = __fma_rn (-u, f, tmp);
  ulo = g * tmp;

  qq.y = q;
  qq.x = 0.0;
  uu.y = u;
  uu.x = ulo;
  cc.y = 3.3333333333333331E-1/4.0;
  cc.x = -9.8201492846582465E-18/4.0;
  qq = __internal_ddadd_xgty (cc, qq);

  qq = __internal_ddmul(qq, uu);
  qq = __internal_ddmul(qq, uu);
  qq = __internal_ddmul(qq, uu);
  uu = __internal_ddadd_xgty (uu, qq);
  u = uu.y;
  ulo = uu.x;

  tt.y = expo * 6.9314718055966296e-001;
  tt.x = expo * 2.8235290563031577e-013;

  res = __internal_ddadd_xgty (tt, uu);
  return res;
}

static __attribute__((__unused__)) double __cuda_log2(double a)
{
  double t;
  t = __cuda_log(a);
  return __fma_rn (t, 1.4426950408889634e+0, t * 2.0355273740931033e-17);
}

static __attribute__((__unused__)) double __cuda_log10(double a)
{
  double t;
  t = __cuda_log(a);
  return __fma_rn (t, 4.3429448190325182e-1, t * 1.09831965021676510e-17);
}

static __attribute__((__unused__)) double __cuda_log1p(double a)
{
  double t;
  int i;

  i = __double2hiint(a);
  if (((unsigned)i < (unsigned)0x3fe55555) || ((int)i < (int)0xbfd99999)) {

    t = a + 2.0;
    t = a / t;
    t = -a * t;
    t = __internal_atanh_kernel(a, t);
    return t;
  }
  return __cuda_log (a + 1.0);
}

static __attribute__((__unused__)) double __internal_exp_kernel(double a, int scale)
{
  double t, fac, z;
  int i;

  t = __cuda_rint (a * 1.4426950408889634e+0);
  i = (int)t;
  z = __fma_rn (t, -6.9314718055994529e-1, a);
  z = __fma_rn (t, -2.3190468138462996e-17, z);
  fac = 2.0;
  if (i <= -1021) {
    i += 55;
    fac = 5.5511151231257827e-17;
  }

  t = __internal_expm1_kernel(z);
  z = __internal_exp2i_kernel(i + scale - 1);
  t = __fma_rn (t, z, z);
  t = t * fac;
  return t;
}

static __attribute__((__unused__)) double __cuda_exp(double a)
{
  double t;
  int i;
  i = __double2hiint(a);
  if (((unsigned)i < (unsigned)0x40862e43) || ((int)i < (int)0xC0874911)) {
    t = __internal_exp_kernel(a, 0);
    return t;
  }
  t = ((unsigned int)i >> 31) ? 0.0 : __longlong_as_double(0x7ff0000000000000ULL);
  if (__cuda___isnan(a)) {
    t = a + a;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_exp2(double a)
{
  double z;
  double t;
  double fac;
  int i;

  i = __double2hiint(a);
  if (((unsigned)i < (unsigned)0x40900000) || ((int)i < (int)0xc090cc00)) {
    t = __cuda_rint (a);
    z = a - t;
    i = (int)t;
    fac = 2.0;
    if (i <= -1021) {
      i += 55;
      fac = 5.5511151231257827e-17;
    }

    z = __fma_rn (z, 6.9314718055994529e-1, z * 2.3190468138462996e-17);
    t = __internal_expm1_kernel(z);
    z = __internal_exp2i_kernel(i - 1);
    t = __fma_rn (t, z, z);
    t = t * fac;
    return t;
  }
  t = ((unsigned int)i >> 31) ? 0.0 : __longlong_as_double(0x7ff0000000000000ULL);
  if (__cuda___isnan(a)) {
    t = a + a;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_exp10(double a)
{
  double z;
  double t;
  double fac;
  int i;

  i = __double2hiint(a);
  if (((unsigned)i < (unsigned)0x40734414) || ((int)i < (int)0xc07439b8)) {
    t = __cuda_rint (a * 3.3219280948873622e+0);
    i = (int)t;
    z = __fma_rn (t, -3.0102999566398120e-1, a);
    z = __fma_rn (t, -(-2.8037281277851704e-18), z);
    fac = 2.0;
    if (i <= -1021) {
      i += 55;
      fac = 5.5511151231257827e-17;
    }

    z = __fma_rn (z, 2.3025850929940459e+0, z * (-2.1707562233822494e-16));
    t = __internal_expm1_kernel(z);
    z = __internal_exp2i_kernel(i - 1);
    t = __fma_rn (t, z, z);
    t = t * fac;
    return t;
  }
  t = ((unsigned int)i >> 31) ? 0.0 : __longlong_as_double(0x7ff0000000000000ULL);
  if (__cuda___isnan(a)) {
    t = a + a;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_expm1(double a)
{
  double t, z, u;
  int i, j, k;

  k = __double2hiint(a);
  if (((unsigned)k < (unsigned)0x40862e43) || ((int)k < (int)0xc04a8000)) {
    t = __cuda_rint (a * 1.4426950408889634e+0);
    i = (int)t;
    z = __fma_rn (t, -6.9314718055994529e-1, a);
    z = __fma_rn (t, -2.3190468138462996e-17, z);
    k = k + k;
    if ((unsigned)k < (unsigned)0x7fb3e647) {
      z = a;
      i = 0;
    }
    t = __internal_expm1_kernel(z);
    j = i;
    if (i == 1024) j--;
    u = __internal_exp2i_kernel(j);
    a = u - 1.0;
    t = __fma_rn (t, u, a);
    if (i == 1024) t = t + t;
    if (k == 0) t = z;
    return t;
  }
  t = ((unsigned int)k >> 31) ? -1.0 : __longlong_as_double(0x7ff0000000000000ULL);
  if (__cuda___isnan(a)) {
    t = a + a;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_cosh(double a)
{
  double z;
  int i;

  z = __cuda_fabs(a);
  i = __double2hiint(z);
  if ((unsigned)i < (unsigned)0x408633cf) {
    z = __internal_exp_kernel(z, -2);
    z = __fma_rn(2.0, z, 0.125 / z);
    return z;
  } else {
    if (z > 0.0) a = __int_as_float(0x7f800000);
    return a + a;
  }
}

static __attribute__((__unused__)) double __cuda_sinh(double a)
{
  double s, z;
  s = a;
  a = __cuda_fabs(a);
  if (a < 1.0) {
    double a2 = a * a;

    z = 1.632386098183803E-010;
    z = __fma_rn (z, a2, 2.504854501385687E-008);
    z = __fma_rn (z, a2, 2.755734274788706E-006);
    z = __fma_rn (z, a2, 1.984126976294102E-004);
    z = __fma_rn (z, a2, 8.333333333452911E-003);
    z = __fma_rn (z, a2, 1.666666666666606E-001);
    z = z * a2;
    z = __fma_rn (z, a, a);
  } else if (a < 2.0) {
    z = __cuda_expm1(a);
    z = __internal_half (z + z / (z + 1.0));
  } else {
    z = __internal_exp_kernel(a, -1);
    z = z + (1.0 / (-4.0 * z));
    if (a >= 7.1047586007394398e+2) {
      z = __longlong_as_double(0x7ff0000000000000ULL);
    }
  }
  z = __internal_copysign_pos(z, s);
  return z;
}

static __attribute__((__unused__)) double __cuda_tanh(double a)
{
  double t;
  t = __cuda_fabs(a);
  if (t >= 0.55) {
    double s;
    s = 1.0 - 2.0 / (__internal_exp_kernel(2.0 * t, 0) + 1.0);
    if (t > 350.0) {
      s = 1.0;
    }
    a = __internal_copysign_pos(s, a);
  } else {
    double a2;
    a2 = a * a;
    t = 5.102147717274194E-005;
    t = __fma_rn (t, a2, -2.103023983278533E-004);
    t = __fma_rn (t, a2, 5.791370145050539E-004);
    t = __fma_rn (t, a2, -1.453216755611004E-003);
    t = __fma_rn (t, a2, 3.591719696944118E-003);
    t = __fma_rn (t, a2, -8.863194503940334E-003);
    t = __fma_rn (t, a2, 2.186948597477980E-002);
    t = __fma_rn (t, a2, -5.396825387607743E-002);
    t = __fma_rn (t, a2, 1.333333333316870E-001);
    t = __fma_rn (t, a2, -3.333333333333232E-001);
    t = t * a2;
    t = __fma_rn (t, a, a);
    a = __internal_copysign_pos(t, a);
  }
  return a;
}

static __attribute__((__unused__)) double __internal_atan_kernel(double a)
{
  double t, a2;
  a2 = a * a;
  t = -2.0258553044438358E-005 ;
  t = __fma_rn (t, a2, 2.2302240345758510E-004);
  t = __fma_rn (t, a2, -1.1640717779930576E-003);
  t = __fma_rn (t, a2, 3.8559749383629918E-003);
  t = __fma_rn (t, a2, -9.1845592187165485E-003);
  t = __fma_rn (t, a2, 1.6978035834597331E-002);
  t = __fma_rn (t, a2, -2.5826796814495994E-002);
  t = __fma_rn (t, a2, 3.4067811082715123E-002);
  t = __fma_rn (t, a2, -4.0926382420509971E-002);
  t = __fma_rn (t, a2, 4.6739496199157994E-002);
  t = __fma_rn (t, a2, -5.2392330054601317E-002);
  t = __fma_rn (t, a2, 5.8773077721790849E-002);
  t = __fma_rn (t, a2, -6.6658603633512573E-002);
  t = __fma_rn (t, a2, 7.6922129305867837E-002);
  t = __fma_rn (t, a2, -9.0909012354005225E-002);
  t = __fma_rn (t, a2, 1.1111110678749424E-001);
  t = __fma_rn (t, a2, -1.4285714271334815E-001);
  t = __fma_rn (t, a2, 1.9999999999755019E-001);
  t = __fma_rn (t, a2, -3.3333333333331860E-001);
  t = t * a2;
  t = __fma_rn (t, a, a);
  return t;
}

static __attribute__((__unused__)) double __cuda_atan2(double a, double b)
{
  double t0, t1, t3;
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    return a + b;
  }


  t3 = __cuda_fabs(b);
  t1 = __cuda_fabs(a);
  if (t3 == 0.0 && t1 == 0.0) {
    t3 = __cuda___signbit(b) ? 3.1415926535897931e+0 : 0;
  } else if (__cuda___isinf(t3) && __cuda___isinf(t1)) {
    t3 = __cuda___signbit(b) ? 2.3561944901923448e+0 : 7.8539816339744828e-1;
  } else {
    t0 = __cuda_fmax (t1, t3);
    t1 = __cuda_fmin (t1, t3);
    t3 = t1 / t0;
    t3 = __internal_atan_kernel(t3);

    if (__cuda_fabs(a) > __cuda_fabs(b)) t3 = 1.5707963267948966e+0 - t3;
    if (b < 0.0) t3 = 3.1415926535897931e+0 - t3;
  }
  t3 = __internal_copysign_pos(t3, a);
  return t3;
}

static __attribute__((__unused__)) double __cuda_atan(double a)
{
  double t0, t1;

  t0 = __cuda_fabs(a);
  t1 = t0;
  if (t0 > 1.0) {
    t1 = 1.0 / t1;
  }

  t1 = __internal_atan_kernel(t1);

  if (t0 > 1.0) {
    t1 = 1.5707963267948966e+0 - t1;
  }
  return __internal_copysign_pos(t1, a);
}


static __attribute__((__unused__)) double __internal_asin_kernel(double a, double b)
{
  double r;
  r = 6.259798167646803E-002;
  r = __fma_rn (r, b, -7.620591484676952E-002);
  r = __fma_rn (r, b, 6.686894879337643E-002);
  r = __fma_rn (r, b, -1.787828218369301E-002);
  r = __fma_rn (r, b, 1.745227928732326E-002);
  r = __fma_rn (r, b, 1.000422754245580E-002);
  r = __fma_rn (r, b, 1.418108777515123E-002);
  r = __fma_rn (r, b, 1.733194598980628E-002);
  r = __fma_rn (r, b, 2.237350511593569E-002);
  r = __fma_rn (r, b, 3.038188875134962E-002);
  r = __fma_rn (r, b, 4.464285849810986E-002);
  r = __fma_rn (r, b, 7.499999998342270E-002);
  r = __fma_rn (r, b, 1.666666666667375E-001);
  r = r * b;
  return r;
}

static __attribute__((__unused__)) double __cuda_asin(double a)
{
  double fa, t0, t1;
  int ihi, ahi;
  ahi = __double2hiint(a);
  fa = __cuda_fabs(a);
  ihi = __double2hiint(fa);
  if (ihi < 0x3fe26666) {
    t1 = fa * fa;
    t1 = __internal_asin_kernel (fa, t1);
    t1 = __fma_rn (t1, fa, fa);
    t1 = __internal_copysign_pos(t1, a);
  } else {
    t1 = __fma_rn (-0.5, fa, 0.5);
    t0 = __cuda_sqrt (t1);
    t1 = __internal_asin_kernel (t0, t1);
    t0 = -2.0 * t0;
    t1 = __fma_rn (t0, t1, 6.1232339957367660e-17);
    t0 = t0 + 7.8539816339744828e-1;
    t1 = t0 + t1;
    t1 = t1 + 7.8539816339744828e-1;
    if (ahi < 0x3ff00000) {
      t1 = __internal_copysign_pos(t1, a);
    }
  }
  return t1;
}

static __attribute__((__unused__)) double __cuda_acos(double a)
{
  double t0, t1;
  int ihi, ahi;


  if (__cuda___isnan(a)) {
    return a + a;
  }

  ahi = __double2hiint(a);
  t0 = __cuda_fabs (a);
  ihi = __double2hiint(t0);
  if (ihi < 0x3fe26666) {
    t1 = t0 * t0;
    t1 = __internal_asin_kernel (t0, t1);
    t0 = __fma_rn (t1, t0, t0);
    if ((unsigned)ahi >= (unsigned)0x80000000) {
      t0 = __fma_rn (1.0, t0, +6.1232339957367660e-17);
      t0 = 1.5707963267948966e+0 + t0;
    } else {
      t0 = __fma_rn (1.0, t0, -6.1232339957367660e-17);
      t0 = 1.5707963267948966e+0 - t0;
    }
  } else {
    t1 = __fma_rn (-0.5, t0, 0.5);
    t0 = __cuda_sqrt(t1);
    t1 = __internal_asin_kernel (t0, t1);
    t0 = __fma_rn (t1, t0, t0);
    t0 = 2.0 * t0;
    if ((unsigned)ahi >= (unsigned)0x80000000) {
      t0 = __fma_rn (1.0, t0, -1.2246467991473532e-16);
      t0 = 3.1415926535897931e+0 - t0;
    }
  }
  return t0;
}

static __attribute__((__unused__)) double __cuda_acosh(double a)
{
  double t;

  if (__cuda___isnan(a)) {
    return a + a;
  }

  t = a - 1.0;
  if (__cuda_fabs(t) > 4503599627370496.0) {

    return 6.9314718055994529e-1 + __cuda_log(a);
  } else {
    t = t + __cuda_sqrt(__fma_rn(a, t, t));
    return __cuda_log1p(t);
  }
}

static __attribute__((__unused__)) double __cuda_asinh(double a)
{
  double fa, t;
  fa = __cuda_fabs(a);
  if (__double2hiint(fa) >= 0x5ff00000) {
    t = 6.9314718055994529e-1 + __cuda_log(fa);
  } else {
    t = fa * fa;
    t = __cuda_log1p (fa + t / (1.0 + __cuda_sqrt(1.0 + t)));
  }
  return __internal_copysign_pos(t, a);
}

static __attribute__((__unused__)) double __cuda_atanh(double a)
{
  double fa, t;

  if (__cuda___isnan(a)) {
    return a + a;
  }

  fa = __cuda_fabs(a);
  t = (2.0 * fa) / (1.0 - fa);
  t = 0.5 * __cuda_log1p(t);

  if (__cuda___isnan(t)) {
    return t;
  }

  if (__cuda___signbit(a)) {
    t = -t;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_hypot(double a, double b)
{
  double v, w, t, fa, fb;

  fa = __cuda_fabs(a);
  fb = __cuda_fabs(b);
  v = __cuda_fmax(fa, fb);
  w = __cuda_fmin(fa, fb);
  t = w / v;
  t = __fma_rn (t, t, 1.0);
  t = v * __cuda_sqrt(t);
  if (v == 0.0) {
    t = v + w;
  }
  if ((!(fa <= __longlong_as_double(0x7ff0000000000000ULL))) || (!(fb <= __longlong_as_double(0x7ff0000000000000ULL)))) {
    t = a + b;
  }
  if (v == __longlong_as_double(0x7ff0000000000000ULL)) {
    t = v + w;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_cbrt(double a)
{
  float s;
  double t, r;
  int ilo, ihi, expo, nexpo, denorm;
  if ((a == 0.0) || !(__cuda___finite(a))) {
    return a + a;
  }
  t = __cuda_fabs(a);
  ilo = __double2loint(t);
  ihi = __double2hiint(t);
  expo = ((int)((unsigned int)ihi >> 20) & 0x7ff);
  denorm = 0;
  if (expo == 0) {

    t = t * 18014398509481984.0;
    denorm = 18;
    ilo = __double2loint(t);
    ihi = __double2hiint(t);
    expo = ((int)((unsigned int)ihi >> 20) & 0x7ff);
  }

  nexpo = __float2int_rn(0.333333333f * (float)(expo - 1022));
  ihi -= (3 * nexpo) << 20;
  r = __hiloint2double(ihi, ilo);

  s = (float)r;
  t = __cuda_exp2f(-0.333333333f * __log2f(s));
  t = __fma_rn(__fma_rn(t*t,-r*t,1.0), 3.3333333333333333e-1*t, t);
  t = r * t * t;
  t = __fma_rn(t - (r / (t * t)), -3.3333333333333333e-1, t);

  ilo = __double2loint(t);
  ihi = __double2hiint(t);
  ihi += (nexpo - denorm) << 20;
  t = __hiloint2double(ihi, ilo);
  if (__cuda___signbit(a)) {
    t = -t;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_rcbrt(double a)
{
  float s;
  double t, r;
  int ilo, ihi, expo, nexpo, denorm;
  if ((a == 0.0) || !(__cuda___finite(a))) {
    return 1.0 / a;
  }
  t = __cuda_fabs(a);
  ilo = __double2loint(t);
  ihi = __double2hiint(t);
  expo = ((int)((unsigned int)ihi >> 20) & 0x7ff);
  denorm = 0;
  if (expo == 0) {

    t = t * 18014398509481984.0;
    denorm = 18;
    ilo = __double2loint(t);
    ihi = __double2hiint(t);
    expo = ((int)((unsigned int)ihi >> 20) & 0x7ff);
  }

  nexpo = __float2int_rn(0.333333333f * (float)(expo - 1022));
  ihi -= (3 * nexpo) << 20;
  r = __hiloint2double(ihi, ilo);

  s = (float)r;
  t = __cuda_exp2f(-0.333333333f * __log2f(s));
  t = __fma_rn(__fma_rn(t*t,-r*t,1.0), 3.3333333333333333e-1*t, t);
  t = __fma_rn(__fma_rn(t*t,-r*t,1.0), 3.3333333333333333e-1*t, t);

  ilo = __double2loint(t);
  ihi = __double2hiint(t);
  ihi += (-(nexpo - denorm)) << 20;
  t = __hiloint2double(ihi, ilo);
  if (__cuda___signbit(a)) {
    t = -t;
  }
  return t;
}

static __attribute__((__unused__)) double __internal_accurate_pow(double a, double b)
{
  double2 loga;
  double2 prod;
  double t_hi, t_lo;
  double tmp;



  double e;


  loga = __internal_log_ext_prec(a);


  if (__cuda_fabs(b) > 1e304) b *= 1.220703125e-4;

  t_hi = loga.y * b;
  t_lo = __fma_rn (loga.y, b, -t_hi);
  t_lo = __fma_rn (loga.x, b, t_lo);
  prod.y = e = t_hi + t_lo;
  prod.x = (t_hi - e) + t_lo;


  tmp = __cuda_exp(prod.y);

  if (!__cuda___isinf(tmp)) {



    tmp = __fma_rn (tmp, prod.x, tmp);
  }
  return tmp;
}

static __attribute__((__unused__)) double __cuda_pow(double a, double b)
{
  int bIsOddInteger;
  double t;

  if (a == 1.0 || b == 0.0) {
    return 1.0;
  }
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    return a + b;
  }
  if (a == __longlong_as_double(0x7ff0000000000000ULL)) {
    return __cuda___signbit(b) ? 0.0 : __longlong_as_double(0x7ff0000000000000ULL);
  }
  if (__cuda___isinf(b)) {
    if (a == -1.0) {
      return 1.0;
    }
    t = __cuda_fabs(a) > 1.0 ? __longlong_as_double(0x7ff0000000000000ULL) : 0.0;
    if (b < 0.0) {
      t = 1.0 / t;
    }
    return t;
  }
  bIsOddInteger = __cuda_fabs(b - (2.0f * __cuda_trunc(0.5 * b))) == 1.0;
  if (a == 0.0) {
    t = bIsOddInteger ? a : 0.0;
    if (b < 0.0) {
      t = 1.0 / t;
    }
    return t;
  }
  if (a == -__longlong_as_double(0x7ff0000000000000ULL)) {
    t = (b < 0.0) ? -1.0/a : -a;
    if (bIsOddInteger) {
      t = __longlong_as_double(__double_as_longlong(t)^0x8000000000000000ULL);
    }
    return t;
  }
  if ((a < 0.0) && (b != __cuda_trunc(b))) {
    return __longlong_as_double(0xfff8000000000000ULL);
  }
  t = __cuda_fabs(a);
  t = __internal_accurate_pow(t, b);
  if ((a < 0.0) && bIsOddInteger) {
    t = __longlong_as_double(__double_as_longlong(t) ^ 0x8000000000000000ULL);
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_erf(double a)
{
  double t, r, q;

  t = __cuda_fabs(a);
  if (t >= 1.0) {
    r = -1.28836351230756500E-019;
    r = __fma_rn (r, t, 1.30597472161093370E-017);
    r = __fma_rn (r, t, -6.33924401259620500E-016);
    r = __fma_rn (r, t, 1.96231865908940140E-014);
    r = __fma_rn (r, t, -4.35272243559990750E-013);
    r = __fma_rn (r, t, 7.37083927929352150E-012);
    r = __fma_rn (r, t, -9.91402142550461630E-011);
    r = __fma_rn (r, t, 1.08817017167760820E-009);
    r = __fma_rn (r, t, -9.93918713097634620E-009);
    r = __fma_rn (r, t, 7.66739923255145500E-008);
    r = __fma_rn (r, t, -5.05440278302806720E-007);
    r = __fma_rn (r, t, 2.87474157099000620E-006);
    r = __fma_rn (r, t, -1.42246725399722510E-005);
    r = __fma_rn (r, t, 6.16994555079419460E-005);
    r = __fma_rn (r, t, -2.36305221938908790E-004);
    r = __fma_rn (r, t, 8.05032844055371070E-004);
    r = __fma_rn (r, t, -2.45833366629108140E-003);
    r = __fma_rn (r, t, 6.78340988296706120E-003);
    r = __fma_rn (r, t, -1.70509103597554640E-002);
    r = __fma_rn (r, t, 3.93322852515666300E-002);
    r = __fma_rn (r, t, -8.37271292613764040E-002);
    r = __fma_rn (r, t, 1.64870423707623280E-001);
    r = __fma_rn (r, t, -2.99729521787681470E-001);
    r = __fma_rn (r, t, 4.99394435612628580E-001);
    r = __fma_rn (r, t, -7.52014596480123030E-001);
    r = __fma_rn (r, t, 9.99933138314926250E-001);
    r = __fma_rn (r, t, -1.12836725321102670E+000);
    r = __fma_rn (r, t, 9.99998988715182450E-001);
    q = __internal_exp_kernel(-t * t, 0);
    r = __fma_rn (r, -q, 1.0);
    if (t >= 6.5) {
      r = 1.0;
    }
    a = __internal_copysign_pos(r, a);
  } else {
    q = a * a;
    r = -7.77946848895991420E-010;
    r = __fma_rn (r, q, 1.37109803980285950E-008);
    r = __fma_rn (r, q, -1.62063137584932240E-007);
    r = __fma_rn (r, q, 1.64471315712790040E-006);
    r = __fma_rn (r, q, -1.49247123020098620E-005);
    r = __fma_rn (r, q, 1.20552935769006260E-004);
    r = __fma_rn (r, q, -8.54832592931448980E-004);
    r = __fma_rn (r, q, 5.22397760611847340E-003);
    r = __fma_rn (r, q, -2.68661706431114690E-002);
    r = __fma_rn (r, q, 1.12837916709441850E-001);
    r = __fma_rn (r, q, -3.76126389031835210E-001);
    r = __fma_rn (r, q, 1.12837916709551260E+000);
    a = r * a;
  }
  return a;
}

static __attribute__((__unused__)) double __cuda_erfinv(double a)
{
  double fa, t;

  fa = __cuda_fabs(a);
  if (fa >= 1.0) {
    t = __longlong_as_double(0xfff8000000000000ULL);
    if (fa == 1.0) {
      t = a * __longlong_as_double(0x7ff0000000000000ULL);
    }
  } else if (fa >= 0.9375) {




    double p, q;

    t = __cuda_log1p(-fa);
    t = __cuda_rsqrt(-t);
    p = 2.7834010353747001060e-3;
    p = __fma_rn (p, t, 8.6030097526280260580e-1);
    p = __fma_rn (p, t, 2.1371214997265515515e+0);
    p = __fma_rn (p, t, 3.1598519601132090206e+0);
    p = __fma_rn (p, t, 3.5780402569085996758e+0);
    p = __fma_rn (p, t, 1.5335297523989890804e+0);
    p = __fma_rn (p, t, 3.4839207139657522572e-1);
    p = __fma_rn (p, t, 5.3644861147153648366e-2);
    p = __fma_rn (p, t, 4.3836709877126095665e-3);
    p = __fma_rn (p, t, 1.3858518113496718808e-4);
    p = __fma_rn (p, t, 1.1738352509991666680e-6);
    q = t+ 2.2859981272422905412e+0;
    q = __fma_rn (q, t, 4.3859045256449554654e+0);
    q = __fma_rn (q, t, 4.6632960348736635331e+0);
    q = __fma_rn (q, t, 3.9846608184671757296e+0);
    q = __fma_rn (q, t, 1.6068377709719017609e+0);
    q = __fma_rn (q, t, 3.5609087305900265560e-1);
    q = __fma_rn (q, t, 5.3963550303200816744e-2);
    q = __fma_rn (q, t, 4.3873424022706935023e-3);
    q = __fma_rn (q, t, 1.3858762165532246059e-4);
    q = __fma_rn (q, t, 1.1738313872397777529e-6);
    t = p / (q * t);
    if (a < 0.0) t = -t;
  } else if (fa >= 0.75) {




    double p, q;

    t = __fma_rn (a, a, -.87890625);
    p = .21489185007307062000e+0;
    p = __fma_rn (p, t, -.64200071507209448655e+1);
    p = __fma_rn (p, t, .29631331505876308123e+2);
    p = __fma_rn (p, t, -.47644367129787181803e+2);
    p = __fma_rn (p, t, .34810057749357500873e+2);
    p = __fma_rn (p, t, -.12954198980646771502e+2);
    p = __fma_rn (p, t, .25349389220714893917e+1);
    p = __fma_rn (p, t, -.24758242362823355486e+0);
    p = __fma_rn (p, t, .94897362808681080020e-2);
    q = t -.12831383833953226499e+2;
    q = __fma_rn (q, t, .41409991778428888716e+2);
    q = __fma_rn (q, t, -.53715373448862143349e+2);
    q = __fma_rn (q, t, .33880176779595142685e+2);
    q = __fma_rn (q, t, -.11315360624238054876e+2);
    q = __fma_rn (q, t, .20369295047216351160e+1);
    q = __fma_rn (q, t, -.18611650627372178511e+0);
    q = __fma_rn (q, t, .67544512778850945940e-2);
    p = p / q;
    t = a * p;
  } else {




    double p, q;

    t = __fma_rn (a, a, -.5625);
    p = -.23886240104308755900e+2;
    p = __fma_rn (p, t, .45560204272689128170e+3);
    p = __fma_rn (p, t, -.22977467176607144887e+4);
    p = __fma_rn (p, t, .46631433533434331287e+4);
    p = __fma_rn (p, t, -.43799652308386926161e+4);
    p = __fma_rn (p, t, .19007153590528134753e+4);
    p = __fma_rn (p, t, -.30786872642313695280e+3);
    q = t -.83288327901936570000e+2;
    q = __fma_rn (q, t, .92741319160935318800e+3);
    q = __fma_rn (q, t, -.35088976383877264098e+4);
    q = __fma_rn (q, t, .59039348134843665626e+4);
    q = __fma_rn (q, t, -.48481635430048872102e+4);
    q = __fma_rn (q, t, .18997769186453057810e+4);
    q = __fma_rn (q, t, -.28386514725366621129e+3);
    p = p / q;
    t = a * p;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_erfcinv(double a)
{
  double t;

  if (__cuda___isnan(a)) return a + a;

  if (a <= 0.0) {
    t = __longlong_as_double(0xfff8000000000000ULL);
    if (a == 0.0) {
      t = (1.0 - a) * __longlong_as_double(0x7ff0000000000000ULL);
    }
  }
  else if (a >= 0.0625) {
    t = __cuda_erfinv (1.0 - a);
  }
  else if (a >= 1e-100) {




    double p, q;
    t = __cuda_log(a);
    t = __cuda_rsqrt(-t);
    p = 2.7834010353747001060e-3;
    p = __fma_rn (p, t, 8.6030097526280260580e-1);
    p = __fma_rn (p, t, 2.1371214997265515515e+0);
    p = __fma_rn (p, t, 3.1598519601132090206e+0);
    p = __fma_rn (p, t, 3.5780402569085996758e+0);
    p = __fma_rn (p, t, 1.5335297523989890804e+0);
    p = __fma_rn (p, t, 3.4839207139657522572e-1);
    p = __fma_rn (p, t, 5.3644861147153648366e-2);
    p = __fma_rn (p, t, 4.3836709877126095665e-3);
    p = __fma_rn (p, t, 1.3858518113496718808e-4);
    p = __fma_rn (p, t, 1.1738352509991666680e-6);
    q = t+ 2.2859981272422905412e+0;
    q = __fma_rn (q, t, 4.3859045256449554654e+0);
    q = __fma_rn (q, t, 4.6632960348736635331e+0);
    q = __fma_rn (q, t, 3.9846608184671757296e+0);
    q = __fma_rn (q, t, 1.6068377709719017609e+0);
    q = __fma_rn (q, t, 3.5609087305900265560e-1);
    q = __fma_rn (q, t, 5.3963550303200816744e-2);
    q = __fma_rn (q, t, 4.3873424022706935023e-3);
    q = __fma_rn (q, t, 1.3858762165532246059e-4);
    q = __fma_rn (q, t, 1.1738313872397777529e-6);
    t = p / (q * t);
  }
  else {




    double p, q;
    t = __cuda_log(a);
    t = __cuda_rsqrt(-t);
    p = 6.9952990607058154858e-1;
    p = __fma_rn (p, t, 1.9507620287580568829e+0);
    p = __fma_rn (p, t, 8.2810030904462690216e-1);
    p = __fma_rn (p, t, 1.1279046353630280005e-1);
    p = __fma_rn (p, t, 6.0537914739162189689e-3);
    p = __fma_rn (p, t, 1.3714329569665128933e-4);
    p = __fma_rn (p, t, 1.2964481560643197452e-6);
    p = __fma_rn (p, t, 4.6156006321345332510e-9);
    p = __fma_rn (p, t, 4.5344689563209398450e-12);
    q = t+ 1.5771922386662040546e+0;
    q = __fma_rn (q, t, 2.1238242087454993542e+0);
    q = __fma_rn (q, t, 8.4001814918178042919e-1);
    q = __fma_rn (q, t, 1.1311889334355782065e-1);
    q = __fma_rn (q, t, 6.0574830550097140404e-3);
    q = __fma_rn (q, t, 1.3715891988350205065e-4);
    q = __fma_rn (q, t, 1.2964671850944981713e-6);
    q = __fma_rn (q, t, 4.6156017600933592558e-9);
    q = __fma_rn (q, t, 4.5344687377088206783e-12);
    t = p / (q * t);
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_erfc(double a)
{
  double p, q, h, l;
  int ahi;

  ahi = __double2hiint(a);
  if (ahi < (int)0x3fea0400) {
    return 1.0 - __cuda_erf(a);
  }
  if (ahi < (int)0x40140000) {





    double t;

    t = 1.0 / a;
    p = -1.0000000252849461E+000;
    p = __fma_rn (p, t, -7.3398971987771156E-001);
    p = __fma_rn (p, t, -1.4685633784433072E-001);
    p = __fma_rn (p, t, 1.2963557011001836E-001);
    p = __fma_rn (p, t, 1.0901177826674287E-001);
    p = __fma_rn (p, t, 3.9250612663155882E-002);
    p = __fma_rn (p, t, 7.5883167167654269E-003);
    p = __fma_rn (p, t, 6.6438196820856965E-004);
    q = t + 2.7339900293714838E+000;
    q = __fma_rn (q, t, 3.3580762542361291E+000);
    q = __fma_rn (q, t, 2.4165688909166021E+000);
    q = __fma_rn (q, t, 1.1092158770004934E+000);
    q = __fma_rn (q, t, 3.2845571970789467E-001);
    q = __fma_rn (q, t, 5.9110343116276186E-002);
    q = __fma_rn (q, t, 5.1750858802842702E-003);
    q = __fma_rn (q, t, 1.2937416364002241E-009);
    q = 1.0 / q;
    p = p * q;
    p = p * t;
    h = a * a;
    l = __fma_rn (a, a, -h);
    q = __internal_exp_kernel(-h, -1);
    q = __fma_rn (l, -q, q);
    p = __fma_rn (p, q, q);
    p = p * t;
  } else {

    double ooa, ooasq;

    ooa = 1.0 / a;
    ooasq = ooa * ooa;
    p = -4.0025406686930527E+005;
    p = __fma_rn (p, ooasq, 1.4420582543942123E+005);
    p = __fma_rn (p, ooasq, -2.7664185780951841E+004);
    p = __fma_rn (p, ooasq, 4.1144611644767283E+003);
    p = __fma_rn (p, ooasq, -5.8706000519209351E+002);
    p = __fma_rn (p, ooasq, 9.1490086446323375E+001);
    p = __fma_rn (p, ooasq, -1.6659491387740221E+001);
    p = __fma_rn (p, ooasq, 3.7024804085481784E+000);
    p = __fma_rn (p, ooasq, -1.0578553994424316E+000);
    p = __fma_rn (p, ooasq, 4.2314218745087778E-001);
    p = __fma_rn (p, ooasq, -2.8209479177354962E-001);
    p = __fma_rn (p, ooasq, 5.6418958354775606E-001);
    h = a * a;
    l = __fma_rn (a, a, -h);
    q = __internal_exp_kernel(-h, 0);
    q = __fma_rn (l, -q, q);
    p = p * ooa;
    p = p * q;
    if (a > 27.3) {
      p = 0.0;
    }
  }
  return p;
}


static __attribute__((__unused__)) double __internal_tgamma_kernel(double a)
{
  double t;
  t = -4.42689340712524750E-010;
  t = __fma_rn (t, a, -2.02665918466589540E-007);
  t = __fma_rn (t, a, 1.13812117211195270E-006);
  t = __fma_rn (t, a, -1.25077348166307480E-006);
  t = __fma_rn (t, a, -2.01365017404087710E-005);
  t = __fma_rn (t, a, 1.28050126073544860E-004);
  t = __fma_rn (t, a, -2.15241408115274180E-004);
  t = __fma_rn (t, a, -1.16516754597046040E-003);
  t = __fma_rn (t, a, 7.21894322484663810E-003);
  t = __fma_rn (t, a, -9.62197153268626320E-003);
  t = __fma_rn (t, a, -4.21977345547223940E-002);
  t = __fma_rn (t, a, 1.66538611382503560E-001);
  t = __fma_rn (t, a, -4.20026350341054440E-002);
  t = __fma_rn (t, a, -6.55878071520257120E-001);
  t = __fma_rn (t, a, 5.77215664901532870E-001);
  t = __fma_rn (t, a, 1.00000000000000000E+000);
  return t;
}


static __attribute__((__unused__)) double __internal_stirling_poly(double a)
{
  double x = 1.0 / a;
  double z = 0.0;
  z = __fma_rn (z, x, 8.3949872067208726e-004);
  z = __fma_rn (z, x, -5.1717909082605919e-005);
  z = __fma_rn (z, x, -5.9216643735369393e-004);
  z = __fma_rn (z, x, 6.9728137583658571e-005);
  z = __fma_rn (z, x, 7.8403922172006662e-004);
  z = __fma_rn (z, x, -2.2947209362139917e-004);
  z = __fma_rn (z, x, -2.6813271604938273e-003);
  z = __fma_rn (z, x, 3.4722222222222220e-003);
  z = __fma_rn (z, x, 8.3333333333333329e-002);
  z = __fma_rn (z, x, 1.0000000000000000e+000);
  return z;
}

static __attribute__((__unused__)) double __internal_tgamma_stirling(double a)
{
  if (a < 1.7162437695630274e+002) {

    volatile

    double t_hi, t_lo, e;

    double2 loga, prod;
    double z = __internal_stirling_poly (a);
    double b = a - 0.5;


    loga = __internal_log_ext_prec(a);


    t_hi = loga.y * b;
    t_lo = __fma_rn (loga.y, b, -t_hi);
    t_lo = __fma_rn (loga.x, b, t_lo);
    prod.y = e = t_hi + t_lo;
    prod.x = (t_hi - e) + t_lo;


    loga.y = -a;
    loga.x = 0.0;
    prod = __internal_ddadd_xgty (prod, loga);


    a = __cuda_exp(prod.y);

    if (!__cuda___isinf(a)) {



      a = __fma_rn (a, prod.x, a);
    }
    a = __fma_rn (a, 2.5066282746310007e+0, a * (-1.8328579980459167e-16));
    return a * z;
  } else {
    return __longlong_as_double(0x7ff0000000000000ULL);
  }
}

static __attribute__((__unused__)) double __cuda_tgamma(double a)
{
  double s, xx, x = a;
  if (__cuda___isnan(a)) {
    return a + a;
  }
  if (__cuda_fabs(x) < 15.0) {




    if (x >= 0.0) {
      s = 1.0;
      xx = x;
      while (xx > 1.5) {
        s = __fma_rn(s, xx, -s);
        xx = xx - 1.0;
      }
      if (x >= 0.5) {
        xx = xx - 1.0;
      }
      xx = __internal_tgamma_kernel (xx);
      if (x < 0.5) {
        xx = xx * x;
      }
      s = s / xx;
    } else {
      xx = x;
      s = xx;
      if (x == __cuda_trunc(x)) {
        return __longlong_as_double(0xfff8000000000000ULL);
      }
      while (xx < -0.5) {
        s = __fma_rn (s, xx, s);
        xx = xx + 1.0;
      }
      xx = __internal_tgamma_kernel (xx);
      s = s * xx;
      s = 1.0 / s;
    }
    return s;
  } else {
    if (x >= 0.0) {
      return __internal_tgamma_stirling (x);
    } else {
      double t;
      int quot;
      if (x == __cuda_trunc(x)) {
        return __longlong_as_double(0xfff8000000000000ULL);
      }
      if (x < -185.0) {
        int negative;
        x = __cuda_floor(x);
        negative = ((x - (2.0 * __cuda_floor(0.5 * x))) == 1.0);
        return negative ? __longlong_as_double(0x8000000000000000ULL) : 0.0;
      }

      xx = __cuda_rint (__internal_twice(x));
      quot = (int)xx;
      xx = __fma_rn (-0.5, xx, x);
      xx = xx * 3.1415926535897931e+0;
      if (quot & 1) {
        xx = __internal_cos_kerneld (xx);
      } else {
        xx = __internal_sin_kerneld (xx);
      }
      if (quot & 2) {
        xx = -xx;
      }
      x = __cuda_fabs (x);
      s = __cuda_exp (-x);
      t = x - 0.5;
      if (x > 140.0) t = __internal_half(t);
      t = __cuda_pow (x, t);
      if (x > 140.0) s = s * t;
      s = s * __internal_stirling_poly (x);
      s = s * x;
      s = s * xx;
      s = 1.0 / s;
      s = __fma_rn (s, 1.2533141373155003e+0, (-9.1642899902295834e-17) * s);
      s = s / t;
      return s;
    }
  }
}

static __attribute__((__unused__)) double __internal_lgamma_pos(double a)
{
  double sum;
  double s, t;

  if (a == __longlong_as_double(0x7ff0000000000000ULL)) {
    return a;
  }
  if (a >= 3.0) {
    if (a >= 8.0) {



      s = 1.0 / a;
      t = s * s;
      sum = -0.1633436431e-2;
      sum = __fma_rn (sum, t, 0.83645878922e-3);
      sum = __fma_rn (sum, t, -0.5951896861197e-3);
      sum = __fma_rn (sum, t, 0.793650576493454e-3);
      sum = __fma_rn (sum, t, -0.277777777735865004e-2);
      sum = __fma_rn (sum, t, 0.833333333333331018375e-1);
      sum = __fma_rn (sum, s, 0.918938533204672);
      s = __internal_half(__cuda_log (a));
      t = a - 0.5;
      s = s * t;
      t = s - a;
      s = s + sum;
      t = t + s;
      return t;
    } else {
      a = a - 3.0;
      s = -4.02412642744125560E+003;
      s = __fma_rn (s, a, -2.97693796998962000E+005);
      s = __fma_rn (s, a, -6.38367087682528790E+006);
      s = __fma_rn (s, a, -5.57807214576539320E+007);
      s = __fma_rn (s, a, -2.24585140671479230E+008);
      s = __fma_rn (s, a, -4.70690608529125090E+008);
      s = __fma_rn (s, a, -7.62587065363263010E+008);
      s = __fma_rn (s, a, -9.71405112477113250E+008);
      t = a -1.02277248359873170E+003;
      t = __fma_rn (t, a, -1.34815350617954480E+005);
      t = __fma_rn (t, a, -4.64321188814343610E+006);
      t = __fma_rn (t, a, -6.48011106025542540E+007);
      t = __fma_rn (t, a, -4.19763847787431360E+008);
      t = __fma_rn (t, a, -1.25629926018000720E+009);
      t = __fma_rn (t, a, -1.40144133846491690E+009);
      t = s / t;
      t = t + a;
      return t;
    }
  } else if (a >= 1.5) {
    a = a - 2.0;
    t = 9.84839283076310610E-009;
    t = __fma_rn (t, a, -6.69743850483466500E-008);
    t = __fma_rn (t, a, 2.16565148880011450E-007);
    t = __fma_rn (t, a, -4.86170275781575260E-007);
    t = __fma_rn (t, a, 9.77962097401114400E-007);
    t = __fma_rn (t, a, -2.03041287574791810E-006);
    t = __fma_rn (t, a, 4.36119725805364580E-006);
    t = __fma_rn (t, a, -9.43829310866446590E-006);
    t = __fma_rn (t, a, 2.05106878496644220E-005);
    t = __fma_rn (t, a, -4.49271383742108440E-005);
    t = __fma_rn (t, a, 9.94570466342226000E-005);
    t = __fma_rn (t, a, -2.23154589559238440E-004);
    t = __fma_rn (t, a, 5.09669559149637430E-004);
    t = __fma_rn (t, a, -1.19275392649162300E-003);
    t = __fma_rn (t, a, 2.89051032936815490E-003);
    t = __fma_rn (t, a, -7.38555102806811700E-003);
    t = __fma_rn (t, a, 2.05808084278121250E-002);
    t = __fma_rn (t, a, -6.73523010532073720E-002);
    t = __fma_rn (t, a, 3.22467033424113040E-001);
    t = __fma_rn (t, a, 4.22784335098467190E-001);
    t = t * a;
    return t;
  } else if (a >= 0.7) {
    a = 1.0 - a;
    t = 1.17786911519331130E-002;
    t = __fma_rn (t, a, 3.89046747413522300E-002);
    t = __fma_rn (t, a, 5.90045711362049900E-002);
    t = __fma_rn (t, a, 6.02143305254344420E-002);
    t = __fma_rn (t, a, 5.61652708964839180E-002);
    t = __fma_rn (t, a, 5.75052755193461370E-002);
    t = __fma_rn (t, a, 6.21061973447320710E-002);
    t = __fma_rn (t, a, 6.67614724532521880E-002);
    t = __fma_rn (t, a, 7.14856037245421020E-002);
    t = __fma_rn (t, a, 7.69311251313347100E-002);
    t = __fma_rn (t, a, 8.33503129714946310E-002);
    t = __fma_rn (t, a, 9.09538288991182800E-002);
    t = __fma_rn (t, a, 1.00099591546322310E-001);
    t = __fma_rn (t, a, 1.11334278141734510E-001);
    t = __fma_rn (t, a, 1.25509666613462880E-001);
    t = __fma_rn (t, a, 1.44049896457704160E-001);
    t = __fma_rn (t, a, 1.69557177031481600E-001);
    t = __fma_rn (t, a, 2.07385551032182120E-001);
    t = __fma_rn (t, a, 2.70580808427600350E-001);
    t = __fma_rn (t, a, 4.00685634386517050E-001);
    t = __fma_rn (t, a, 8.22467033424113540E-001);
    t = __fma_rn (t, a, 5.77215664901532870E-001);
    t = t * a;
    return t;
  } else {
    t= -9.04051686831357990E-008;
    t = __fma_rn (t, a, 7.06814224969349250E-007);
    t = __fma_rn (t, a, -3.80702154637902830E-007);
    t = __fma_rn (t, a, -2.12880892189316100E-005);
    t = __fma_rn (t, a, 1.29108470307156190E-004);
    t = __fma_rn (t, a, -2.15932815215386580E-004);
    t = __fma_rn (t, a, -1.16484324388538480E-003);
    t = __fma_rn (t, a, 7.21883433044470670E-003);
    t = __fma_rn (t, a, -9.62194579514229560E-003);
    t = __fma_rn (t, a, -4.21977386992884450E-002);
    t = __fma_rn (t, a, 1.66538611813682460E-001);
    t = __fma_rn (t, a, -4.20026350606819980E-002);
    t = __fma_rn (t, a, -6.55878071519427450E-001);
    t = __fma_rn (t, a, 5.77215664901523870E-001);
    t = t * a;
    t = __fma_rn (t, a, a);
    return -__cuda_log (t);
  }
}

static __attribute__((__unused__)) double __cuda_lgamma(double a)
{
  double t;
  double i;
  long long int quot;
  if (__cuda___isnan(a)) {
    return a + a;
  }
  t = __internal_lgamma_pos(__cuda_fabs(a));
  if (a >= 0.0) return t;
  a = __cuda_fabs(a);
  i = __cuda_trunc(a);
  if (a == i) return __longlong_as_double(0x7ff0000000000000ULL);
  if (a < 1e-19) return -__cuda_log(a);
  i = __cuda_rint (2.0 * a);
  quot = (long long int)i;
  i = __fma_rn (-0.5, i, a);
  i = i * 3.1415926535897931e+0;
  if (quot & 1) {
    i = __internal_cos_kerneld(i);
  } else {
    i = __internal_sin_kerneld(i);
  }
  i = __cuda_fabs(i);
  t = __cuda_log(3.1415926535897931e+0 / (i * a)) - t;
  return t;
}

static __attribute__((__unused__)) double __cuda_ldexp(double a, int b)
{
  double fa = __cuda_fabs (a);
  if ((fa == 0.0) || (fa == __longlong_as_double(0x7ff0000000000000ULL)) || (!(fa <= __longlong_as_double(0x7ff0000000000000ULL)))) {
    return a + a;
  }
  if (b == 0) {
    return a;
  }
  if (b > 2200) b = 2200;
  if (b < -2200) b = -2200;
  if (__cuda_abs (b) < 1022) {
    return a * __internal_exp2i_kernel(b);
  }
  if (__cuda_abs (b) < 2044) {
    int bhalf = b / 2;
    return a * __internal_exp2i_kernel (bhalf) *
           __internal_exp2i_kernel (b - bhalf);
  } else {
    int bquarter = b / 4;
    double t = __internal_exp2i_kernel(bquarter);
    return a * t * t * t *__internal_exp2i_kernel (b - 3 * bquarter);
  }
}

static __attribute__((__unused__)) double __cuda_scalbn(double a, int b)
{

  return __cuda_ldexp(a, b);
}

static __attribute__((__unused__)) double __cuda_scalbln(double a, long int b)
{


  if (b < -2147483648L) b = -2147483648L;
  if (b > 2147483647L) b = 2147483647L;

  return __cuda_scalbn(a, (int)b);
}

static __attribute__((__unused__)) double __cuda_frexp(double a, int *b)
{
  double fa = __cuda_fabs(a);
  unsigned int expo;
  unsigned int denorm;

  if (fa < 2.22507385850720140e-308) {
    a *= 18014398509481984.0;
    denorm = 54;
  } else {
    denorm = 0;
  }
  expo = (__double2hiint(a) >> 20) & 0x7ff;
  if ((fa == 0.0) || (expo == 0x7ff)) {
    expo = 0;
    a = a + a;
  } else {
    expo = expo - denorm - 1022;
    a = __longlong_as_double((__double_as_longlong(a) & 0x800fffffffffffffULL)|
                              0x3fe0000000000000ULL);
  }
  *b = expo;
  return a;
}

static __attribute__((__unused__)) double __cuda_modf(double a, double *b)
{
  double t;
  if (__cuda___finite(a)) {
    t = __cuda_trunc(a);
    *b = t;
    t = a - t;
    return __internal_copysign_pos(t, a);
  } else if (__cuda___isinf(a)) {
    t = 0.0;
    *b = a;
    return __internal_copysign_pos(t, a);
  } else {
    *b = a + a;
    return a + a;
  }
}

static __attribute__((__unused__)) double __cuda_fmod(double a, double b)
{
  double orig_a = a;
  double orig_b = b;
  a = __cuda_fabs(a);
  b = __cuda_fabs(b);
  if (!((a <= __longlong_as_double(0x7ff0000000000000ULL)) && (b <= __longlong_as_double(0x7ff0000000000000ULL)))) {
      return orig_a + orig_b;
  }
  if (a == __longlong_as_double(0x7ff0000000000000ULL) || b == 0.0) {
    return __longlong_as_double(0xfff8000000000000ULL);
  } else if (a >= b) {
    int bhi = __double2hiint(b);
    int blo = __double2loint(b);
    int ahi = __double2hiint(a);
    double scaled_b = 0.0;
    if (b < 2.22507385850720140e-308) {
      double t = b;
      while ((t < a) && (t < 2.22507385850720140e-308)) {
        t = t + t;
      }
      bhi = __double2hiint(t);
      blo = __double2loint(t);
      scaled_b = t;
    }
    if (a >= 2.22507385850720140e-308) {
      scaled_b = __hiloint2double ((bhi & 0x000fffff)|(ahi & 0x7ff00000), blo);
    }
    if (scaled_b > a) {
      scaled_b *= 0.5;
    }
    while (scaled_b >= b) {
      if (a >= scaled_b) {
        a -= scaled_b;
      }
      scaled_b *= 0.5;
    }
    return __internal_copysign_pos(a, orig_a);
  } else {
    return orig_a;
  }
}

static __attribute__((__unused__)) double __cuda_remainder(double a, double b)
{
  double orig_a;
  double twoa = 0.0;
  unsigned int quot0 = 0;
  int bhi;
  int blo;
  int ahi;
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    return a + b;
  }
  orig_a = a;
  a = __cuda_fabs(a);
  b = __cuda_fabs(b);
  if (a == __longlong_as_double(0x7ff0000000000000ULL) || b == 0.0) {
    return __longlong_as_double(0xfff8000000000000ULL);
  } else if (a >= b) {
    double scaled_b = 0.0;
    bhi = __double2hiint(b);
    blo = __double2loint(b);
    ahi = __double2hiint(a);
    if (b < 2.22507385850720140e-308) {
      double t = b;
      while ((t < a) && (t < 2.22507385850720140e-308)) {
        t = t + t;
      }
      bhi = __double2hiint(t);
      blo = __double2loint(t);
      scaled_b = t;
    }
    if (a >= 2.22507385850720140e-308) {
      scaled_b = __hiloint2double ((bhi & 0x000fffff)|(ahi & 0x7ff00000), blo);
    }
    if (scaled_b > a) {
      scaled_b *= 0.5;
    }
    while (scaled_b >= b) {
      quot0 = 0;
      if (a >= scaled_b) {
        a -= scaled_b;
        quot0 = 1;
      }
      scaled_b *= 0.5;
    }
  }

  twoa = a + a;
  if ((twoa > b) || ((twoa == b) && quot0)) {
    a -= b;
  }
  bhi = __double2hiint(a);
  blo = __double2loint(a);
  ahi = __double2hiint(orig_a);
  a = __hiloint2double((ahi & 0x80000000) ^ bhi, blo);
  return a;
}

static __attribute__((__unused__)) double __cuda_remquo(double a, double b, int *c)
{
  double orig_a;
  double twoa = 0.0;
  unsigned int quot = 0;
  unsigned int sign;
  int bhi;
  int blo;
  int ahi;
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    *c = quot;
    return a + b;
  }
  orig_a = a;
  sign = 0 - (__cuda___signbit(a) != __cuda___signbit(b));
  a = __cuda_fabs(a);
  b = __cuda_fabs(b);
  if (a == __longlong_as_double(0x7ff0000000000000ULL) || b == 0.0) {
    *c = quot;
    return __longlong_as_double(0xfff8000000000000ULL);
  } else if (a >= b) {
    double scaled_b = 0.0;
    bhi = __double2hiint(b);
    blo = __double2loint(b);
    ahi = __double2hiint(a);
    if (b < 2.22507385850720140e-308) {
      double t = b;
      while ((t < a) && (t < 2.22507385850720140e-308)) {
        t = t + t;
      }
      bhi = __double2hiint(t);
      blo = __double2loint(t);
      scaled_b = t;
    }
    if (a >= 2.22507385850720140e-308) {
      scaled_b = __hiloint2double ((bhi & 0x000fffff)|(ahi & 0x7ff00000), blo);
    }
    if (scaled_b > a) {
      scaled_b *= 0.5;
    }
    while (scaled_b >= b) {
      quot <<= 1;
      if (a >= scaled_b) {
        a -= scaled_b;
        quot += 1;
      }
      scaled_b *= 0.5;
    }
  }

  twoa = a + a;
  if ((twoa > b) || ((twoa == b) && (quot & 1))) {
    quot++;
    a -= b;
  }
  bhi = __double2hiint(a);
  blo = __double2loint(a);
  ahi = __double2hiint(orig_a);
  a = __hiloint2double((ahi & 0x80000000) ^ bhi, blo);
  quot = quot & (~((~0)<<3));
  quot = quot ^ sign;
  quot = quot - sign;
  *c = quot;
  return a;
}

static __attribute__((__unused__)) double __cuda_nextafter(double a, double b)
{
  unsigned long long int ia;
  unsigned long long int ib;
  ia = __double_as_longlong(a);
  ib = __double_as_longlong(b);
  if (__cuda___isnan(a) || __cuda___isnan(b)) return a + b;
  if (((ia | ib) << 1) == 0ULL) return b;
  if ((ia + ia) == 0ULL) {
    return __internal_copysign_pos(__longlong_as_double(0x0000000000000001ULL), b);
  }
  if ((a < b) && (a < 0.0)) ia--;
  if ((a < b) && (a > 0.0)) ia++;
  if ((a > b) && (a < 0.0)) ia++;
  if ((a > b) && (a > 0.0)) ia--;
  a = __longlong_as_double(ia);
  return a;
}

static __attribute__((__unused__)) double __cuda_nan(const char *tagp)
{
  unsigned long long int i;

  i = __internal_nan_kernel (tagp);
  i = (i & 0x000fffffffffffffULL) | 0x7ff8000000000000ULL;
  return __longlong_as_double(i);
}

static __attribute__((__unused__)) double __cuda_round(double a)
{
  double fa = __cuda_fabs(a);
  if (fa >= 4503599627370496.0) {
    return a;
  } else {
    double u;
    u = __cuda_trunc(fa + 0.5);
    if (fa < 0.5) u = 0;
    u = __internal_copysign_pos(u, a);
    return u;
  }
}

static __attribute__((__unused__)) long long int __cuda_llround(double a)
{

  if (a >= 9223372036854775807.0) return 0x7fffffffffffffffLL;
  if (a <= -9223372036854775808.0) return 0x8000000000000000LL;

  return (long long int)(__cuda_round(a));
}

static __attribute__((__unused__)) long int __cuda_lround(double a)
{

  return (long int)(__cuda_llround(a));
# 2354 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
}

static __attribute__((__unused__)) double __cuda_fdim(double a, double b)
{
  double t;
  t = a - b;
  if (a <= b) {
    t = 0.0;
  }
  return t;
}

static __attribute__((__unused__)) int __cuda_ilogb(double a)
{
  unsigned long long int i;
  unsigned int ihi;
  unsigned int ilo;
  if (__cuda___isnan(a)) return -((int)((unsigned int)-1 >> 1))-1;
  if (__cuda___isinf(a)) return ((int)((unsigned int)-1 >> 1));
  if (a == 0.0) return -((int)((unsigned int)-1 >> 1))-1;
  a = __cuda_fabs(a);
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  i = ((unsigned long long int)ihi) << 32 | (unsigned long long int)ilo;
  if (a >= 2.22507385850720140e-308) {
    return ((int)((ihi >> 20) & 0x7ff)) - 1023;
  } else {
    return -1011 - __clzll(i);
  }
}

static __attribute__((__unused__)) double __cuda_logb(double a)
{
  unsigned long long int i;
  unsigned int ihi;
  unsigned int ilo;
  if (__cuda___isnan(a)) return a + a;
  a = __cuda_fabs(a);
  if (a == __longlong_as_double(0x7ff0000000000000ULL)) return a;
  if (a == 0.0) return -__longlong_as_double(0x7ff0000000000000ULL);
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  i = ((unsigned long long int)ihi) << 32 | (unsigned long long int)ilo;
  if (a >= 2.22507385850720140e-308) {
    return (double)((int)((ihi >> 20) & 0x7ff)) - 1023;
  } else {
    int expo = -1011 - __clzll(i);
    return (double)expo;
  }
}

static __attribute__((__unused__)) double __cuda_fma(double a, double b, double c)
{
  return __fma_rn(a, b, c);
}
# 5330 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 89 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 280 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 3 "/tmp/tmpxft_00003c13_00000000-1_dxtc.cudafe1.stub.c" 2




struct __T20 {const uint *__par0;const uint *__par1;uint2 *__par2;int __dummy_field;};
static void __sti____cudaRegisterAll_39_tmpxft_00003c13_00000000_4_dxtc_cpp1_ii_b480a5a9(void) __attribute__((__constructor__));
void __device_stub__Z8compressPKjS0_P5uint2(const uint *__par0, const uint *__par1, uint2 *__par2){auto struct __T20 *__T2324;
*(void**)(void*)&__T2324 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2324->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2324->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2324->__par2) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(const uint *, const uint *, uint2 *))compress__entry)); (void)cudaLaunch(((char *)((void ( *)(const uint *, const uint *, uint2 *))compress__entry))); };}
void compress__entry( const uint *__cuda_0,const uint *__cuda_1,uint2 *__cuda_2)
# 510 "dxtc.cu"
{__device_stub__Z8compressPKjS0_P5uint2( __cuda_0,__cuda_1,__cuda_2);
# 538 "dxtc.cu"
}
# 1 "/tmp/tmpxft_00003c13_00000000-1_dxtc.cudafe1.stub.c"



static void __sti____cudaRegisterAll_39_tmpxft_00003c13_00000000_4_dxtc_cpp1_ii_b480a5a9(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(const uint *, const uint *, uint2 *))compress__entry), (char*)"_Z8compressPKjS0_P5uint2", "_Z8compressPKjS0_P5uint2", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&kColorMetric__cuda_shadow_variable__, (char*)"kColorMetric", "kColorMetric", 0, 12, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&alphaTable4__cuda_shadow_variable__, (char*)"alphaTable4", "alphaTable4", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&alphaTable3__cuda_shadow_variable__, (char*)"alphaTable3", "alphaTable3", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&prods4__cuda_shadow_variable__, (char*)"prods4", "prods4", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&prods3__cuda_shadow_variable__, (char*)"prods3", "prods3", 0, 16, 1, 0); }
# 1 "/tmp/tmpxft_00003c13_00000000-1_dxtc.cudafe1.stub.c" 2

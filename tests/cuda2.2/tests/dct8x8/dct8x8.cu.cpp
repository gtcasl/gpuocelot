# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.cpp"
# 1 "dct8x8.cu"
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
# 51 "BmpUtil.h"
#pragma pack ( 1 )
# 53 "BmpUtil.h"
typedef char int8;
# 54 "BmpUtil.h"
typedef short int16;
# 55 "BmpUtil.h"
typedef int int32;
# 56 "BmpUtil.h"
typedef unsigned char uint8;
# 57 "BmpUtil.h"
typedef unsigned short uint16;
# 58 "BmpUtil.h"
typedef unsigned uint32;
# 71 "BmpUtil.h"
typedef
# 66 "BmpUtil.h"
struct {
# 67 "BmpUtil.h"
uint16 _bm_signature;
# 68 "BmpUtil.h"
uint32 _bm_file_size;
# 69 "BmpUtil.h"
uint32 _bm_reserved;
# 70 "BmpUtil.h"
uint32 _bm_bitmap_data;
# 71 "BmpUtil.h"
} BMPFileHeader;
# 92 "BmpUtil.h"
typedef
# 80 "BmpUtil.h"
struct {
# 81 "BmpUtil.h"
uint32 _bm_info_header_size;
# 82 "BmpUtil.h"
uint32 _bm_image_width;
# 83 "BmpUtil.h"
uint32 _bm_image_height;
# 84 "BmpUtil.h"
uint16 _bm_num_of_planes;
# 85 "BmpUtil.h"
uint16 _bm_color_depth;
# 86 "BmpUtil.h"
uint32 _bm_compressed;
# 87 "BmpUtil.h"
uint32 _bm_bitmap_size;
# 88 "BmpUtil.h"
uint32 _bm_hor_resolution;
# 89 "BmpUtil.h"
uint32 _bm_ver_resolution;
# 90 "BmpUtil.h"
uint32 _bm_num_colors_used;
# 91 "BmpUtil.h"
uint32 _bm_num_important_colors;
# 92 "BmpUtil.h"
} BMPInfoHeader;
# 109 "BmpUtil.h"
typedef
# 106 "BmpUtil.h"
struct {
# 107 "BmpUtil.h"
int width;
# 108 "BmpUtil.h"
int height;
# 109 "BmpUtil.h"
} ROI;
# 115 "BmpUtil.h"
typedef unsigned char byte;
# 120 "BmpUtil.h"
extern "C" int clamp_0_255(int);
# 121 "BmpUtil.h"
extern "C" float round_f(float);
# 122 "BmpUtil.h"
extern "C" byte *MallocPlaneByte(int, int, int *);
# 123 "BmpUtil.h"
extern "C" short *MallocPlaneShort(int, int, int *);
# 124 "BmpUtil.h"
extern "C" float *MallocPlaneFloat(int, int, int *);
# 125 "BmpUtil.h"
extern "C" void CopyByte2Float(byte *, int, float *, int, ROI);
# 126 "BmpUtil.h"
extern "C" void CopyFloat2Byte(float *, int, byte *, int, ROI);
# 127 "BmpUtil.h"
extern "C" void FreePlane(void *);
# 128 "BmpUtil.h"
extern "C" void AddFloatPlane(float, float *, int, ROI);
# 129 "BmpUtil.h"
extern "C" void MulFloatPlane(float, float *, int, ROI);
# 130 "BmpUtil.h"
extern "C" int PreLoadBmp(char *, int *, int *);
# 131 "BmpUtil.h"
extern "C" void LoadBmpAsGray(char *, int, ROI, byte *);
# 132 "BmpUtil.h"
extern "C" void DumpBmpAsGray(char *, byte *, int, ROI);
# 133 "BmpUtil.h"
extern "C" void DumpBlockF(float *, int, char *);
# 134 "BmpUtil.h"
extern "C" void DumpBlock(byte *, int, char *);
# 135 "BmpUtil.h"
extern "C" float CalculateMSE(byte *, byte *, int, ROI);
# 136 "BmpUtil.h"
extern "C" float CalculatePSNR(byte *, byte *, int, ROI);
# 53 "DCT8x8_Gold.h"
extern "C" void computeDCT8x8Gold1(const float *, float *, int, ROI);
# 54 "DCT8x8_Gold.h"
extern "C" void computeIDCT8x8Gold1(const float *, float *, int, ROI);
# 55 "DCT8x8_Gold.h"
extern "C" void quantizeGoldFloat(float *, int, ROI);
# 56 "DCT8x8_Gold.h"
extern "C" void quantizeGoldShort(short *, int, ROI);
# 57 "DCT8x8_Gold.h"
extern "C" void computeDCT8x8Gold2(const float *, float *, int, ROI);
# 58 "DCT8x8_Gold.h"
extern "C" void computeIDCT8x8Gold2(const float *, float *, int, ROI);
# 73 "dct8x8.cu"
static texture< float, 2, cudaReadModeElementType> TexSrc;
# 56 "dct8x8_kernel1.cu"
static float DCTv8matrix__cuda_shadow_variable__[64];
# 69 "dct8x8_kernel1.cu"
# 70 "dct8x8_kernel1.cu"
# 85 "dct8x8_kernel1.cu"
void CUDAkernel1DCT__entry(float *Dst, int ImgWidth, int OffsetXBlocks, int OffsetYBlocks);
# 154 "dct8x8_kernel1.cu"
void CUDAkernel1IDCT__entry(float *Dst, int ImgWidth, int OffsetXBlocks, int OffsetYBlocks);
# 54 "dct8x8_kernel2.cu"
static float C_a__cuda_shadow_variable__;
# 55 "dct8x8_kernel2.cu"
static float C_b__cuda_shadow_variable__;
# 56 "dct8x8_kernel2.cu"
static float C_c__cuda_shadow_variable__;
# 57 "dct8x8_kernel2.cu"
static float C_d__cuda_shadow_variable__;
# 58 "dct8x8_kernel2.cu"
static float C_e__cuda_shadow_variable__;
# 59 "dct8x8_kernel2.cu"
static float C_f__cuda_shadow_variable__;
# 65 "dct8x8_kernel2.cu"
static float C_norm__cuda_shadow_variable__;
# 107 "dct8x8_kernel2.cu"
static void CUDAsubroutineInplaceDCTvector(float *Vect0, int Step)
# 108 "dct8x8_kernel2.cu"
{exit(1);
# 141 "dct8x8_kernel2.cu"
}
# 153 "dct8x8_kernel2.cu"
static void CUDAsubroutineInplaceIDCTvector(float *Vect0, int Step)
# 154 "dct8x8_kernel2.cu"
{exit(1);
# 188 "dct8x8_kernel2.cu"
}
# 204 "dct8x8_kernel2.cu"
void CUDAkernel2DCT__entry(float *SrcDst, int ImgStride);
# 334 "dct8x8_kernel2.cu"
void CUDAkernel2IDCT__entry(float *SrcDst, int ImgStride);
# 109 "dct8x8_kernel_short.cu"
union PackedShorts {
# 112 "dct8x8_kernel_short.cu"
struct __attribute__((__aligned__(8))) {
# 113 "dct8x8_kernel_short.cu"
short hShort1;
# 114 "dct8x8_kernel_short.cu"
short hShort2;
# 115 "dct8x8_kernel_short.cu"
};
# 116 "dct8x8_kernel_short.cu"
unsigned hInt;
# 117 "dct8x8_kernel_short.cu"
};
# 123 "dct8x8_kernel_short.cu"
static inline short unfixh(int x)
# 124 "dct8x8_kernel_short.cu"
{exit(1);
# 126 "dct8x8_kernel_short.cu"
}
# 132 "dct8x8_kernel_short.cu"
static inline int unfixo(int x)
# 133 "dct8x8_kernel_short.cu"
{exit(1);
# 135 "dct8x8_kernel_short.cu"
}
# 147 "dct8x8_kernel_short.cu"
static void CUDAshortInplaceDCT(short *SrcDst, int Stride)
# 148 "dct8x8_kernel_short.cu"
{exit(1);
# 216 "dct8x8_kernel_short.cu"
}
# 227 "dct8x8_kernel_short.cu"
static void CUDAshortInplaceDCT(unsigned *V8)
# 228 "dct8x8_kernel_short.cu"
{exit(1);
# 289 "dct8x8_kernel_short.cu"
}
# 301 "dct8x8_kernel_short.cu"
static void CUDAshortInplaceIDCT(short *SrcDst, int Stride)
# 302 "dct8x8_kernel_short.cu"
{exit(1);
# 369 "dct8x8_kernel_short.cu"
}
# 380 "dct8x8_kernel_short.cu"
static void CUDAshortInplaceIDCT(unsigned *V8)
# 381 "dct8x8_kernel_short.cu"
{exit(1);
# 442 "dct8x8_kernel_short.cu"
}
# 459 "dct8x8_kernel_short.cu"
void CUDAkernelShortDCT__entry(short *SrcDst, int ImgStride);
# 601 "dct8x8_kernel_short.cu"
void CUDAkernelShortIDCT__entry(short *SrcDst, int ImgStride);
# 53 "dct8x8_kernel_quantization.cu"
static short Q__cuda_shadow_variable__[64];
# 75 "dct8x8_kernel_quantization.cu"
void CUDAkernelQuantizationFloat__entry(float *SrcDst, int Stride);
# 108 "dct8x8_kernel_quantization.cu"
void CUDAkernelQuantizationShort__entry(short *SrcDst, int Stride);
# 94 "dct8x8.cu"
float WrapperGold1(byte *ImgSrc, byte *ImgDst, int Stride, ROI Size)
# 95 "dct8x8.cu"
{
# 97 "dct8x8.cu"
int StrideF;
# 98 "dct8x8.cu"
float *ImgF1 = MallocPlaneFloat(Size.width, Size.height, &StrideF);
# 99 "dct8x8.cu"
float *ImgF2 = MallocPlaneFloat(Size.width, Size.height, &StrideF);
# 102 "dct8x8.cu"
CopyByte2Float(ImgSrc, Stride, ImgF1, StrideF, Size);
# 103 "dct8x8.cu"
AddFloatPlane(-(128.0F), ImgF1, StrideF, Size);
# 106 "dct8x8.cu"
unsigned timerGold = (0);
# 107 "dct8x8.cu"
__cutilCheckError(cutCreateTimer(&timerGold), "dct8x8.cu", 107);
# 108 "dct8x8.cu"
__cutilCheckError(cutResetTimer(timerGold), "dct8x8.cu", 108);
# 111 "dct8x8.cu"
for (int i = 0; i < 1; i++)
# 112 "dct8x8.cu"
{
# 113 "dct8x8.cu"
__cutilCheckError(cutStartTimer(timerGold), "dct8x8.cu", 113);
# 114 "dct8x8.cu"
computeDCT8x8Gold1(ImgF1, ImgF2, StrideF, Size);
# 115 "dct8x8.cu"
__cutilCheckError(cutStopTimer(timerGold), "dct8x8.cu", 115);
# 116 "dct8x8.cu"
}
# 119 "dct8x8.cu"
float TimerGoldSpan = cutGetAverageTimerValue(timerGold);
# 120 "dct8x8.cu"
__cutilCheckError(cutDeleteTimer(timerGold), "dct8x8.cu", 120);
# 123 "dct8x8.cu"
quantizeGoldFloat(ImgF2, StrideF, Size);
# 126 "dct8x8.cu"
computeIDCT8x8Gold1(ImgF2, ImgF1, StrideF, Size);
# 129 "dct8x8.cu"
AddFloatPlane((128.0F), ImgF1, StrideF, Size);
# 130 "dct8x8.cu"
CopyFloat2Byte(ImgF1, StrideF, ImgDst, Stride, Size);
# 133 "dct8x8.cu"
FreePlane(ImgF1);
# 134 "dct8x8.cu"
FreePlane(ImgF2);
# 137 "dct8x8.cu"
return TimerGoldSpan;
# 138 "dct8x8.cu"
}
# 152 "dct8x8.cu"
float WrapperGold2(byte *ImgSrc, byte *ImgDst, int Stride, ROI Size)
# 153 "dct8x8.cu"
{
# 155 "dct8x8.cu"
int StrideF;
# 156 "dct8x8.cu"
float *ImgF1 = MallocPlaneFloat(Size.width, Size.height, &StrideF);
# 157 "dct8x8.cu"
float *ImgF2 = MallocPlaneFloat(Size.width, Size.height, &StrideF);
# 160 "dct8x8.cu"
CopyByte2Float(ImgSrc, Stride, ImgF1, StrideF, Size);
# 161 "dct8x8.cu"
AddFloatPlane(-(128.0F), ImgF1, StrideF, Size);
# 164 "dct8x8.cu"
unsigned timerGold = (0);
# 165 "dct8x8.cu"
__cutilCheckError(cutCreateTimer(&timerGold), "dct8x8.cu", 165);
# 166 "dct8x8.cu"
__cutilCheckError(cutResetTimer(timerGold), "dct8x8.cu", 166);
# 169 "dct8x8.cu"
for (int i = 0; i < 1; i++)
# 170 "dct8x8.cu"
{
# 171 "dct8x8.cu"
__cutilCheckError(cutStartTimer(timerGold), "dct8x8.cu", 171);
# 172 "dct8x8.cu"
computeDCT8x8Gold2(ImgF1, ImgF2, StrideF, Size);
# 173 "dct8x8.cu"
__cutilCheckError(cutStopTimer(timerGold), "dct8x8.cu", 173);
# 174 "dct8x8.cu"
}
# 177 "dct8x8.cu"
float TimerGoldSpan = cutGetAverageTimerValue(timerGold);
# 178 "dct8x8.cu"
__cutilCheckError(cutDeleteTimer(timerGold), "dct8x8.cu", 178);
# 181 "dct8x8.cu"
quantizeGoldFloat(ImgF2, StrideF, Size);
# 184 "dct8x8.cu"
computeIDCT8x8Gold2(ImgF2, ImgF1, StrideF, Size);
# 187 "dct8x8.cu"
AddFloatPlane((128.0F), ImgF1, StrideF, Size);
# 188 "dct8x8.cu"
CopyFloat2Byte(ImgF1, StrideF, ImgDst, Stride, Size);
# 191 "dct8x8.cu"
FreePlane(ImgF1);
# 192 "dct8x8.cu"
FreePlane(ImgF2);
# 195 "dct8x8.cu"
return TimerGoldSpan;
# 196 "dct8x8.cu"
}
# 210 "dct8x8.cu"
float WrapperCUDA1(byte *ImgSrc, byte *ImgDst, int Stride, ROI Size)
# 211 "dct8x8.cu"
{
# 213 "dct8x8.cu"
cudaChannelFormatDesc floattex = cudaCreateChannelDesc< float> ();
# 216 "dct8x8.cu"
cudaArray *Src;
# 217 "dct8x8.cu"
float *Dst;
# 218 "dct8x8.cu"
size_t DstStride;
# 219 "dct8x8.cu"
__cudaSafeCall(cudaMallocArray(&Src, &floattex, Size.width, Size.height), "dct8x8.cu", 219);
# 220 "dct8x8.cu"
__cudaSafeCall(cudaMallocPitch((void **)(&Dst), &DstStride, (Size.width) * sizeof(float), Size.height), "dct8x8.cu", 220);
# 221 "dct8x8.cu"
DstStride /= sizeof(float);
# 224 "dct8x8.cu"
int ImgSrcFStride;
# 225 "dct8x8.cu"
float *ImgSrcF = MallocPlaneFloat(Size.width, Size.height, &ImgSrcFStride);
# 226 "dct8x8.cu"
CopyByte2Float(ImgSrc, Stride, ImgSrcF, ImgSrcFStride, Size);
# 227 "dct8x8.cu"
AddFloatPlane(-(128.0F), ImgSrcF, ImgSrcFStride, Size);
# 230 "dct8x8.cu"
__cudaSafeCall(cudaMemcpy2DToArray(Src, 0, 0, ImgSrcF, ImgSrcFStride * sizeof(float), (Size.width) * sizeof(float), Size.height, cudaMemcpyHostToDevice), "dct8x8.cu", 233);
# 236 "dct8x8.cu"
dim3 threads(8, 8);
# 237 "dct8x8.cu"
dim3 grid((Size.width) / 8, (Size.height) / 8);
# 240 "dct8x8.cu"
unsigned timerCUDA = (0);
# 241 "dct8x8.cu"
__cutilCheckError(cutCreateTimer(&timerCUDA), "dct8x8.cu", 241);
# 242 "dct8x8.cu"
__cutilCheckError(cutResetTimer(timerCUDA), "dct8x8.cu", 242);
# 245 "dct8x8.cu"
__cudaSafeCall(cudaBindTextureToArray(TexSrc, Src), "dct8x8.cu", 245);
# 246 "dct8x8.cu"
for (int i = 0; i < 1; i++)
# 247 "dct8x8.cu"
{
# 248 "dct8x8.cu"
__cutilCheckError(cutStartTimer(timerCUDA), "dct8x8.cu", 248);
# 249 "dct8x8.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : CUDAkernel1DCT__entry(Dst, (int)DstStride, 0, 0);
# 250 "dct8x8.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dct8x8.cu", 250);
# 251 "dct8x8.cu"
__cutilCheckError(cutStopTimer(timerCUDA), "dct8x8.cu", 251);
# 252 "dct8x8.cu"
}
# 253 "dct8x8.cu"
__cudaSafeCall(cudaUnbindTexture(TexSrc), "dct8x8.cu", 253);
# 254 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 254);
# 257 "dct8x8.cu"
float TimerCUDASpan = cutGetAverageTimerValue(timerCUDA);
# 258 "dct8x8.cu"
__cutilCheckError(cutDeleteTimer(timerCUDA), "dct8x8.cu", 258);
# 261 "dct8x8.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : CUDAkernelQuantizationFloat__entry(Dst, (int)DstStride);
# 262 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 262);
# 265 "dct8x8.cu"
__cudaSafeCall(cudaMemcpy2DToArray(Src, 0, 0, Dst, DstStride * sizeof(float), (Size.width) * sizeof(float), Size.height, cudaMemcpyDeviceToDevice), "dct8x8.cu", 268);
# 271 "dct8x8.cu"
__cudaSafeCall(cudaBindTextureToArray(TexSrc, Src), "dct8x8.cu", 271);
# 272 "dct8x8.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : CUDAkernel1IDCT__entry(Dst, (int)DstStride, 0, 0);
# 273 "dct8x8.cu"
__cudaSafeCall(cudaUnbindTexture(TexSrc), "dct8x8.cu", 273);
# 274 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 274);
# 277 "dct8x8.cu"
__cudaSafeCall(cudaMemcpy2D(ImgSrcF, ImgSrcFStride * sizeof(float), Dst, DstStride * sizeof(float), (Size.width) * sizeof(float), Size.height, cudaMemcpyDeviceToHost), "dct8x8.cu", 280);
# 283 "dct8x8.cu"
AddFloatPlane((128.0F), ImgSrcF, ImgSrcFStride, Size);
# 284 "dct8x8.cu"
CopyFloat2Byte(ImgSrcF, ImgSrcFStride, ImgDst, Stride, Size);
# 287 "dct8x8.cu"
__cudaSafeCall(cudaFreeArray(Src), "dct8x8.cu", 287);
# 288 "dct8x8.cu"
__cudaSafeCall(cudaFree(Dst), "dct8x8.cu", 288);
# 289 "dct8x8.cu"
FreePlane(ImgSrcF);
# 292 "dct8x8.cu"
return TimerCUDASpan;
# 293 "dct8x8.cu"
}
# 307 "dct8x8.cu"
float WrapperCUDA2(byte *ImgSrc, byte *ImgDst, int Stride, ROI Size)
# 308 "dct8x8.cu"
{
# 310 "dct8x8.cu"
int StrideF;
# 311 "dct8x8.cu"
float *ImgF1 = MallocPlaneFloat(Size.width, Size.height, &StrideF);
# 314 "dct8x8.cu"
CopyByte2Float(ImgSrc, Stride, ImgF1, StrideF, Size);
# 315 "dct8x8.cu"
AddFloatPlane(-(128.0F), ImgF1, StrideF, Size);
# 318 "dct8x8.cu"
float *SrcDst;
# 319 "dct8x8.cu"
size_t DeviceStride;
# 320 "dct8x8.cu"
__cudaSafeCall(cudaMallocPitch((void **)(&SrcDst), &DeviceStride, (Size.width) * sizeof(float), Size.height), "dct8x8.cu", 320);
# 321 "dct8x8.cu"
DeviceStride /= sizeof(float);
# 324 "dct8x8.cu"
__cudaSafeCall(cudaMemcpy2D(SrcDst, DeviceStride * sizeof(float), ImgF1, StrideF * sizeof(float), (Size.width) * sizeof(float), Size.height, cudaMemcpyHostToDevice), "dct8x8.cu", 327);
# 330 "dct8x8.cu"
unsigned timerCUDA = (0);
# 331 "dct8x8.cu"
__cutilCheckError(cutCreateTimer(&timerCUDA), "dct8x8.cu", 331);
# 332 "dct8x8.cu"
__cutilCheckError(cutResetTimer(timerCUDA), "dct8x8.cu", 332);
# 335 "dct8x8.cu"
dim3 GridFullWarps((Size.width) / 32, (Size.height) / 16, 1);
# 336 "dct8x8.cu"
dim3 ThreadsFullWarps(8, 32 / 8, 16 / 8);
# 339 "dct8x8.cu"
__cutilCheckError(cutStartTimer(timerCUDA), "dct8x8.cu", 339);
# 340 "dct8x8.cu"
cudaConfigureCall(GridFullWarps, ThreadsFullWarps) ? ((void)0) : CUDAkernel2DCT__entry(SrcDst, (int)DeviceStride);
# 341 "dct8x8.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dct8x8.cu", 341);
# 342 "dct8x8.cu"
__cutilCheckError(cutStopTimer(timerCUDA), "dct8x8.cu", 342);
# 343 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 343);
# 346 "dct8x8.cu"
float TimerCUDASpan = cutGetAverageTimerValue(timerCUDA);
# 347 "dct8x8.cu"
__cutilCheckError(cutDeleteTimer(timerCUDA), "dct8x8.cu", 347);
# 350 "dct8x8.cu"
dim3 ThreadsSmallBlocks(8, 8);
# 351 "dct8x8.cu"
dim3 GridSmallBlocks((Size.width) / 8, (Size.height) / 8);
# 354 "dct8x8.cu"
cudaConfigureCall(GridSmallBlocks, ThreadsSmallBlocks) ? ((void)0) : CUDAkernelQuantizationFloat__entry(SrcDst, (int)DeviceStride);
# 355 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 355);
# 358 "dct8x8.cu"
cudaConfigureCall(GridFullWarps, ThreadsFullWarps) ? ((void)0) : CUDAkernel2IDCT__entry(SrcDst, (int)DeviceStride);
# 359 "dct8x8.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dct8x8.cu", 359);
# 360 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 360);
# 363 "dct8x8.cu"
__cudaSafeCall(cudaMemcpy2D(ImgF1, StrideF * sizeof(float), SrcDst, DeviceStride * sizeof(float), (Size.width) * sizeof(float), Size.height, cudaMemcpyDeviceToHost), "dct8x8.cu", 366);
# 369 "dct8x8.cu"
AddFloatPlane((128.0F), ImgF1, StrideF, Size);
# 370 "dct8x8.cu"
CopyFloat2Byte(ImgF1, StrideF, ImgDst, Stride, Size);
# 373 "dct8x8.cu"
__cudaSafeCall(cudaFree(SrcDst), "dct8x8.cu", 373);
# 374 "dct8x8.cu"
FreePlane(ImgF1);
# 377 "dct8x8.cu"
return TimerCUDASpan;
# 378 "dct8x8.cu"
}
# 392 "dct8x8.cu"
float WrapperCUDAshort(byte *ImgSrc, byte *ImgDst, int Stride, ROI Size)
# 393 "dct8x8.cu"
{
# 395 "dct8x8.cu"
int StrideS;
# 396 "dct8x8.cu"
short *ImgS1 = MallocPlaneShort(Size.width, Size.height, &StrideS);
# 399 "dct8x8.cu"
for (int i = 0; i < (Size.height); i++)
# 400 "dct8x8.cu"
{
# 401 "dct8x8.cu"
for (int j = 0; j < (Size.width); j++)
# 402 "dct8x8.cu"
{
# 403 "dct8x8.cu"
(ImgS1[(i * StrideS) + j]) = (((short)(ImgSrc[(i * Stride) + j])) - 128);
# 404 "dct8x8.cu"
}
# 405 "dct8x8.cu"
}
# 408 "dct8x8.cu"
short *SrcDst;
# 409 "dct8x8.cu"
size_t DeviceStride;
# 410 "dct8x8.cu"
__cudaSafeCall(cudaMallocPitch((void **)(&SrcDst), &DeviceStride, (Size.width) * sizeof(short), Size.height), "dct8x8.cu", 410);
# 411 "dct8x8.cu"
DeviceStride /= sizeof(short);
# 414 "dct8x8.cu"
__cudaSafeCall(cudaMemcpy2D(SrcDst, DeviceStride * sizeof(short), ImgS1, StrideS * sizeof(short), (Size.width) * sizeof(short), Size.height, cudaMemcpyHostToDevice), "dct8x8.cu", 417);
# 420 "dct8x8.cu"
unsigned timerLibJpeg = (0);
# 421 "dct8x8.cu"
__cutilCheckError(cutCreateTimer(&timerLibJpeg), "dct8x8.cu", 421);
# 422 "dct8x8.cu"
__cutilCheckError(cutResetTimer(timerLibJpeg), "dct8x8.cu", 422);
# 425 "dct8x8.cu"
dim3 GridShort((Size.width) / 32, (Size.height) / 32, 1);
# 426 "dct8x8.cu"
dim3 ThreadsShort(8, 32 / 8, 32 / 8);
# 429 "dct8x8.cu"
__cutilCheckError(cutStartTimer(timerLibJpeg), "dct8x8.cu", 429);
# 430 "dct8x8.cu"
cudaConfigureCall(GridShort, ThreadsShort) ? ((void)0) : CUDAkernelShortDCT__entry(SrcDst, (int)DeviceStride);
# 431 "dct8x8.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dct8x8.cu", 431);
# 432 "dct8x8.cu"
__cutilCheckError(cutStopTimer(timerLibJpeg), "dct8x8.cu", 432);
# 433 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 433);
# 436 "dct8x8.cu"
float TimerLibJpegSpan16b = cutGetAverageTimerValue(timerLibJpeg);
# 437 "dct8x8.cu"
__cutilCheckError(cutDeleteTimer(timerLibJpeg), "dct8x8.cu", 437);
# 440 "dct8x8.cu"
dim3 ThreadsSmallBlocks(8, 8);
# 441 "dct8x8.cu"
dim3 GridSmallBlocks((Size.width) / 8, (Size.height) / 8);
# 444 "dct8x8.cu"
cudaConfigureCall(GridSmallBlocks, ThreadsSmallBlocks) ? ((void)0) : CUDAkernelQuantizationShort__entry(SrcDst, (int)DeviceStride);
# 445 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 445);
# 448 "dct8x8.cu"
cudaConfigureCall(GridShort, ThreadsShort) ? ((void)0) : CUDAkernelShortIDCT__entry(SrcDst, (int)DeviceStride);
# 449 "dct8x8.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dct8x8.cu", 449);
# 450 "dct8x8.cu"
__cutilCheckMsg("Kernel execution failed", "dct8x8.cu", 450);
# 453 "dct8x8.cu"
__cudaSafeCall(cudaMemcpy2D(ImgS1, StrideS * sizeof(short), SrcDst, DeviceStride * sizeof(short), (Size.width) * sizeof(short), Size.height, cudaMemcpyDeviceToHost), "dct8x8.cu", 456);
# 459 "dct8x8.cu"
for (int i = 0; i < (Size.height); i++)
# 460 "dct8x8.cu"
{
# 461 "dct8x8.cu"
for (int j = 0; j < (Size.width); j++)
# 462 "dct8x8.cu"
{
# 463 "dct8x8.cu"
(ImgDst[(i * Stride) + j]) = (clamp_0_255((ImgS1[(i * StrideS) + j]) + 128));
# 464 "dct8x8.cu"
}
# 465 "dct8x8.cu"
}
# 468 "dct8x8.cu"
__cudaSafeCall(cudaFree(SrcDst), "dct8x8.cu", 468);
# 469 "dct8x8.cu"
FreePlane(ImgS1);
# 472 "dct8x8.cu"
return TimerLibJpegSpan16b;
# 473 "dct8x8.cu"
}
# 485 "dct8x8.cu"
int main(int argc, char **argv)
# 486 "dct8x8.cu"
{
# 492 "dct8x8.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 493 "dct8x8.cu"
cutilDeviceInit(argc, argv); } else {
# 495 "dct8x8.cu"
cudaSetDevice(cutGetMaxGflopsDeviceId()); }
# 498 "dct8x8.cu"
char SampleImageFname[] = "barbara.bmp";
# 499 "dct8x8.cu"
char SampleImageFnameResGold1[] = "barbara_gold1.bmp";
# 500 "dct8x8.cu"
char SampleImageFnameResGold2[] = "barbara_gold2.bmp";
# 501 "dct8x8.cu"
char SampleImageFnameResCUDA1[] = "barbara_cuda1.bmp";
# 502 "dct8x8.cu"
char SampleImageFnameResCUDA2[] = "barbara_cuda2.bmp";
# 503 "dct8x8.cu"
char SampleImageFnameResCUDAshort[] = "barbara_cuda_short.bmp";
# 505 "dct8x8.cu"
char *pSampleImageFpath = cutFindFilePath(SampleImageFname, argv[0]);
# 508 "dct8x8.cu"
int ImgWidth, ImgHeight;
# 509 "dct8x8.cu"
ROI ImgSize;
# 510 "dct8x8.cu"
int res = PreLoadBmp(pSampleImageFpath, &ImgWidth, &ImgHeight);
# 511 "dct8x8.cu"
(ImgSize.width) = ImgWidth;
# 512 "dct8x8.cu"
(ImgSize.height) = ImgHeight;
# 515 "dct8x8.cu"
printf("CUDA sample DCT/IDCT implementation\n");
# 516 "dct8x8.cu"
printf("===================================\n");
# 517 "dct8x8.cu"
printf("Loading test image: %s... ", SampleImageFname);
# 519 "dct8x8.cu"
if (res)
# 520 "dct8x8.cu"
{
# 521 "dct8x8.cu"
printf("\nError: Image file not found or invalid!\n");
# 522 "dct8x8.cu"
printf("Press ENTER to exit...\n");
# 523 "dct8x8.cu"
getchar();
# 526 "dct8x8.cu"
__cutilExit(argc, argv);
# 527 "dct8x8.cu"
return 1;
# 528 "dct8x8.cu"
}
# 531 "dct8x8.cu"
if (((ImgWidth % 8) != 0) || ((ImgHeight % 8) != 0))
# 532 "dct8x8.cu"
{
# 533 "dct8x8.cu"
printf("\nError: Input image dimensions must be multiples of 8!\n");
# 534 "dct8x8.cu"
printf("Press ENTER to exit...\n");
# 535 "dct8x8.cu"
getchar();
# 538 "dct8x8.cu"
__cutilExit(argc, argv);
# 539 "dct8x8.cu"
return 1;
# 540 "dct8x8.cu"
}
# 541 "dct8x8.cu"
printf("[%d x %d]... ", ImgWidth, ImgHeight);
# 544 "dct8x8.cu"
int ImgStride;
# 545 "dct8x8.cu"
byte *ImgSrc = MallocPlaneByte(ImgWidth, ImgHeight, &ImgStride);
# 546 "dct8x8.cu"
byte *ImgDstGold1 = MallocPlaneByte(ImgWidth, ImgHeight, &ImgStride);
# 547 "dct8x8.cu"
byte *ImgDstGold2 = MallocPlaneByte(ImgWidth, ImgHeight, &ImgStride);
# 548 "dct8x8.cu"
byte *ImgDstCUDA1 = MallocPlaneByte(ImgWidth, ImgHeight, &ImgStride);
# 549 "dct8x8.cu"
byte *ImgDstCUDA2 = MallocPlaneByte(ImgWidth, ImgHeight, &ImgStride);
# 550 "dct8x8.cu"
byte *ImgDstCUDAshort = MallocPlaneByte(ImgWidth, ImgHeight, &ImgStride);
# 553 "dct8x8.cu"
LoadBmpAsGray(pSampleImageFpath, ImgStride, ImgSize, ImgSrc);
# 560 "dct8x8.cu"
printf("Success\nRunning Gold 1 (CPU) version... ");
# 561 "dct8x8.cu"
float TimeGold1 = WrapperGold1(ImgSrc, ImgDstGold1, ImgStride, ImgSize);
# 564 "dct8x8.cu"
printf("Success\nRunning Gold 2 (CPU) version... ");
# 565 "dct8x8.cu"
float TimeGold2 = WrapperGold2(ImgSrc, ImgDstGold2, ImgStride, ImgSize);
# 568 "dct8x8.cu"
printf("Success\nRunning CUDA 1 (GPU) version... ");
# 569 "dct8x8.cu"
float TimeCUDA1 = WrapperCUDA1(ImgSrc, ImgDstCUDA1, ImgStride, ImgSize);
# 572 "dct8x8.cu"
printf("Success\nRunning CUDA 2 (GPU) version... ");
# 573 "dct8x8.cu"
float TimeCUDA2 = WrapperCUDA2(ImgSrc, ImgDstCUDA2, ImgStride, ImgSize);
# 576 "dct8x8.cu"
printf("Success\nRunning CUDA short (GPU) version... ");
# 577 "dct8x8.cu"
float TimeCUDAshort = WrapperCUDAshort(ImgSrc, ImgDstCUDAshort, ImgStride, ImgSize);
# 583 "dct8x8.cu"
printf("Success\nDumping result to %s... ", SampleImageFnameResGold1);
# 584 "dct8x8.cu"
DumpBmpAsGray(SampleImageFnameResGold1, ImgDstGold1, ImgStride, ImgSize);
# 587 "dct8x8.cu"
printf("Success\nDumping result to %s... ", SampleImageFnameResGold2);
# 588 "dct8x8.cu"
DumpBmpAsGray(SampleImageFnameResGold2, ImgDstGold2, ImgStride, ImgSize);
# 591 "dct8x8.cu"
printf("Success\nDumping result to %s... ", SampleImageFnameResCUDA1);
# 592 "dct8x8.cu"
DumpBmpAsGray(SampleImageFnameResCUDA1, ImgDstCUDA1, ImgStride, ImgSize);
# 595 "dct8x8.cu"
printf("Success\nDumping result to %s... ", SampleImageFnameResCUDA2);
# 596 "dct8x8.cu"
DumpBmpAsGray(SampleImageFnameResCUDA2, ImgDstCUDA2, ImgStride, ImgSize);
# 599 "dct8x8.cu"
printf("Success\nDumping result to %s... ", SampleImageFnameResCUDAshort);
# 600 "dct8x8.cu"
DumpBmpAsGray(SampleImageFnameResCUDAshort, ImgDstCUDAshort, ImgStride, ImgSize);
# 602 "dct8x8.cu"
printf("Success\n");
# 607 "dct8x8.cu"
printf("Processing time (CUDA 1)    : %f ms \n", TimeCUDA1);
# 608 "dct8x8.cu"
printf("Processing time (CUDA 2)    : %f ms \n", TimeCUDA2);
# 609 "dct8x8.cu"
printf("Processing time (CUDA short): %f ms \n", TimeCUDAshort);
# 613 "dct8x8.cu"
float PSNR_Src_DstGold1 = CalculatePSNR(ImgSrc, ImgDstGold1, ImgStride, ImgSize);
# 614 "dct8x8.cu"
float PSNR_Src_DstGold2 = CalculatePSNR(ImgSrc, ImgDstGold2, ImgStride, ImgSize);
# 615 "dct8x8.cu"
float PSNR_Src_DstCUDA1 = CalculatePSNR(ImgSrc, ImgDstCUDA1, ImgStride, ImgSize);
# 616 "dct8x8.cu"
float PSNR_Src_DstCUDA2 = CalculatePSNR(ImgSrc, ImgDstCUDA2, ImgStride, ImgSize);
# 617 "dct8x8.cu"
float PSNR_Src_DstCUDAshort = CalculatePSNR(ImgSrc, ImgDstCUDAshort, ImgStride, ImgSize);
# 618 "dct8x8.cu"
float PSNR_DstGold1_DstCUDA1 = CalculatePSNR(ImgDstGold1, ImgDstCUDA1, ImgStride, ImgSize);
# 619 "dct8x8.cu"
float PSNR_DstGold2_DstCUDA2 = CalculatePSNR(ImgDstGold2, ImgDstCUDA2, ImgStride, ImgSize);
# 620 "dct8x8.cu"
float PSNR_DstGold2_DstCUDA16b = CalculatePSNR(ImgDstGold2, ImgDstCUDAshort, ImgStride, ImgSize);
# 622 "dct8x8.cu"
printf("PSNR Original    <---> CPU(Gold 1)    : %f\n", PSNR_Src_DstGold1);
# 623 "dct8x8.cu"
printf("PSNR Original    <---> CPU(Gold 2)    : %f\n", PSNR_Src_DstGold2);
# 624 "dct8x8.cu"
printf("PSNR Original    <---> GPU(CUDA 1)    : %f\n", PSNR_Src_DstCUDA1);
# 625 "dct8x8.cu"
printf("PSNR Original    <---> GPU(CUDA 2)    : %f\n", PSNR_Src_DstCUDA2);
# 626 "dct8x8.cu"
printf("PSNR Original    <---> GPU(CUDA short): %f\n", PSNR_Src_DstCUDAshort);
# 627 "dct8x8.cu"
printf("PSNR CPU(Gold 1) <---> GPU(CUDA 1)    : %f\n", PSNR_DstGold1_DstCUDA1);
# 628 "dct8x8.cu"
printf("PSNR CPU(Gold 2) <---> GPU(CUDA 2)    : %f\n", PSNR_DstGold2_DstCUDA2);
# 629 "dct8x8.cu"
printf("PSNR CPU(Gold 2) <---> GPU(CUDA short): %f\n", PSNR_DstGold2_DstCUDA16b);
# 631 "dct8x8.cu"
if (((PSNR_DstGold1_DstCUDA1 > (30)) && (PSNR_DstGold2_DstCUDA2 > (30))) && (PSNR_DstGold2_DstCUDA16b > (30)))
# 632 "dct8x8.cu"
{
# 633 "dct8x8.cu"
printf("\nTEST PASSED!\n");
# 634 "dct8x8.cu"
} else
# 636 "dct8x8.cu"
{
# 637 "dct8x8.cu"
printf("\nTEST FAILED! (CPU and GPU results differ too much)\n");
# 638 "dct8x8.cu"
}
# 645 "dct8x8.cu"
FreePlane(ImgSrc);
# 646 "dct8x8.cu"
FreePlane(ImgDstGold1);
# 647 "dct8x8.cu"
FreePlane(ImgDstGold2);
# 648 "dct8x8.cu"
FreePlane(ImgDstCUDA1);
# 649 "dct8x8.cu"
FreePlane(ImgDstCUDA2);
# 650 "dct8x8.cu"
FreePlane(ImgDstCUDAshort);
# 653 "dct8x8.cu"
cudaThreadExit();
# 655 "dct8x8.cu"
__cutilExit(argc, argv);
# 656 "dct8x8.cu"
return 0;
# 657 "dct8x8.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_0000307e_00000000-3_dct8x8.fatbin.c" 1
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
# 2 "/tmp/tmpxft_0000307e_00000000-3_dct8x8.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_10$[] = {
0x33010102464c457full,0x0000000000000000ull,0x0000000100be0002ull,0x0000000000000000ull,
0x00000000000039a0ull,0x0000000000000040ull,0x003800400000000aull,0x0001002100400012ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000300000001ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000880ull,
0x0000000000000451ull,0x0000000000000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000030000000bull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000cd1ull,
0x000000000000010eull,0x0000000000000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x0000000200000013ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000ddfull,
0x00000000000004f8ull,0x0000002300000002ull,0x0000000000000001ull,0x0000000000000018ull,
0x00000001000003dfull,0x0000000000100006ull,0x0000000000000000ull,0x00000000000012d7ull,
0x00000000000005c0ull,0x0e00001f00000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000041eull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001897ull,
0x000000000000000cull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000008000003fcull,0x0000000000000003ull,0x0000000000000000ull,0x00000000000018a3ull,
0x000000000000085cull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000032full,0x0000000000100006ull,0x0000000000000000ull,0x00000000000018a3ull,
0x0000000000000200ull,0x0800001a00000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000372ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001aa3ull,
0x0000000000000004ull,0x0000000700000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000399ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001aa7ull,
0x0000000000000008ull,0x0000000700000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x00000001000003bdull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001aafull,
0x000000000000000cull,0x0000000700000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x000000080000034eull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000001abbull,
0x0000000000000224ull,0x0000000700000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000002a7ull,0x0000000000000006ull,0x0000000000000000ull,0x0000000000001abbull,
0x0000000000000120ull,0x0500001700000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000002feull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001bdbull,
0x0000000000000018ull,0x0000000c00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000008000002d0ull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000001bf3ull,
0x000000000000001cull,0x0000000c00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000001fcull,0x0000000000100006ull,0x0000000000000000ull,0x0000000000001bf3ull,
0x0000000000000200ull,0x0a00001200000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000023dull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001df3ull,
0x0000000000000004ull,0x0000000f00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000263ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001df7ull,
0x0000000000000008ull,0x0000000f00000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x0000000100000286ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001dffull,
0x000000000000000cull,0x0000000f00000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x000000080000021aull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000001e0bull,
0x0000000000000224ull,0x0000000f00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000019bull,0x0000000000100006ull,0x0000000000000000ull,0x0000000000001e0bull,
0x00000000000005d0ull,0x0e00000f00000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000001d8ull,0x0000000000000002ull,0x0000000000000000ull,0x00000000000023dbull,
0x000000000000000cull,0x0000001400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000008000001b7ull,0x0000000000000003ull,0x0000000000000000ull,0x00000000000023e7ull,
0x000000000000085cull,0x0000001400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000113ull,0x0000000000100006ull,0x0000000000000000ull,0x00000000000023e7ull,
0x0000000000000260ull,0x0900000c00000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000016aull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000002647ull,
0x0000000000000004ull,0x0000001700000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000080000013cull,0x0000000000000003ull,0x0000000000000000ull,0x000000000000264bull,
0x000000000000001cull,0x0000001700000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000000a3ull,0x0000000000100006ull,0x0000000000000000ull,0x000000000000264bull,
0x0000000000000898ull,0x0e00000900000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000000eaull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000002ee3ull,
0x0000000000000040ull,0x0000001a00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000008000000c4ull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000002f23ull,
0x000000000000089cull,0x0000001a00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000036ull,0x0000000000100006ull,0x0000000000000000ull,0x0000000000002f23ull,
0x00000000000008a0ull,0x0e00000600000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000007bull,0x0000000000000002ull,0x0000000000000000ull,0x00000000000037c3ull,
0x0000000000000040ull,0x0000001d00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000800000056ull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000003803ull,
0x000000000000089cull,0x0000001d00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000443ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000003803ull,
0x000000000000019cull,0x0000000000000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x7472747368732e00ull,0x747274732e006261ull,0x746d79732e006261ull,0x672e766e2e006261ull,
0x6e692e6c61626f6cull,0x672e766e2e007469ull,0x742e006c61626f6cull,0x38315a5f2e747865ull,
0x6e72656b41445543ull,0x4474726f68536c65ull,0x6e2e006973505443ull,0x6465726168732e76ull,
0x44554338315a5f2eull,0x536c656e72656b41ull,0x5054434474726f68ull,0x632e766e2e006973ull,
0x31746e6174736e6full,0x44554338315a5f2eull,0x536c656e72656b41ull,0x5054434474726f68ull,
0x747865742e006973ull,0x44554339315a5f2eull,0x536c656e72656b41ull,0x5443444974726f68ull,
0x2e766e2e00697350ull,0x5f2e646572616873ull,0x6b4144554339315aull,0x6f68536c656e7265ull,
0x7350544344497472ull,0x6f632e766e2e0069ull,0x2e31746e6174736eull,0x4144554339315a5full,
0x68536c656e72656bull,0x505443444974726full,0x747865742e006973ull,0x44554337325a5f2eull,
0x516c656e72656b41ull,0x74617a69746e6175ull,0x74726f68536e6f69ull,0x2e766e2e00697350ull,
0x5f2e646572616873ull,0x6b4144554337325aull,0x6175516c656e7265ull,0x6f6974617a69746eull,
0x735074726f68536eull,0x6f632e766e2e0069ull,0x2e31746e6174736eull,0x4144554337325a5full,
0x75516c656e72656bull,0x6974617a69746e61ull,0x5074726f68536e6full,0x747865742e006973ull,
0x44554334315a5f2eull,0x326c656e72656b41ull,0x2e00696650544344ull,0x65726168732e766eull,
0x554334315a5f2e64ull,0x6c656e72656b4144ull,0x0069665054434432ull,0x736e6f632e766e2eull,
0x5a5f2e31746e6174ull,0x656b414455433431ull,0x544344326c656e72ull,0x7865742e00696650ull,
0x554334315a5f2e74ull,0x6c656e72656b4144ull,0x6969665054434431ull,0x68732e766e2e0069ull,
0x315a5f2e64657261ull,0x72656b4144554334ull,0x50544344316c656eull,0x766e2e0069696966ull,
0x6e6174736e6f632eull,0x4334315a5f2e3174ull,0x656e72656b414455ull,0x696650544344316cull,
0x692e766e2e006969ull,0x5a5f2e736567616dull,0x656b414455433431ull,0x544344316c656e72ull,
0x6e2e006969696650ull,0x5f2e6f666e692e76ull,0x6b4144554334315aull,0x4344316c656e7265ull,
0x2e00696969665054ull,0x325a5f2e74786574ull,0x72656b4144554337ull,0x746e6175516c656eull,
0x466e6f6974617a69ull,0x0069665074616f6cull,0x726168732e766e2eull,0x4337325a5f2e6465ull,
0x656e72656b414455ull,0x7a69746e6175516cull,0x6f6c466e6f697461ull,0x6e2e006966507461ull,
0x6174736e6f632e76ull,0x37325a5f2e31746eull,0x6e72656b41445543ull,0x69746e6175516c65ull,
0x6c466e6f6974617aull,0x2e0069665074616full,0x315a5f2e74786574ull,0x72656b4144554335ull,
0x54434449316c656eull,0x6e2e006969696650ull,0x6465726168732e76ull,0x44554335315a5f2eull,
0x316c656e72656b41ull,0x6969665054434449ull,0x6f632e766e2e0069ull,0x2e31746e6174736eull,
0x4144554335315a5full,0x49316c656e72656bull,0x6969696650544344ull,0x616d692e766e2e00ull,
0x35315a5f2e736567ull,0x6e72656b41445543ull,0x5054434449316c65ull,0x766e2e0069696966ull,
0x5a5f2e6f666e692eull,0x656b414455433531ull,0x434449316c656e72ull,0x2e00696969665054ull,
0x315a5f2e74786574ull,0x72656b4144554335ull,0x54434449326c656eull,0x2e766e2e00696650ull,
0x5f2e646572616873ull,0x6b4144554335315aull,0x4449326c656e7265ull,0x6e2e006966505443ull,
0x6174736e6f632e76ull,0x35315a5f2e31746eull,0x6e72656b41445543ull,0x5054434449326c65ull,
0x632e766e2e006966ull,0x30746e6174736e6full,0x6372537865540000ull,0x44554338315a5f00ull,
0x536c656e72656b41ull,0x5054434474726f68ull,0x4339315a5f006973ull,0x656e72656b414455ull,
0x444974726f68536cull,0x5a5f006973505443ull,0x656b414455433732ull,0x6e6175516c656e72ull,
0x6e6f6974617a6974ull,0x69735074726f6853ull,0x44554334315a5f00ull,0x326c656e72656b41ull,
0x5f00696650544344ull,0x6b4144554334315aull,0x4344316c656e7265ull,0x5f00696969665054ull,
0x6b4144554337325aull,0x6175516c656e7265ull,0x6f6974617a69746eull,0x665074616f6c466eull,
0x554335315a5f0069ull,0x6c656e72656b4144ull,0x6966505443444931ull,0x4335315a5f006969ull,
0x656e72656b414455ull,0x665054434449326cull,0x5f4300665f430069ull,0x6d38765443440065ull,
0x5f43007869727461ull,0x6d726f6e5f430064ull,0x625f4300635f4300ull,0x00005100615f4300ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000010003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000020003000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000030003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x00001d0003000000ull,0xa000000000000000ull,
0x0000000000000008ull,0x00001f0003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x00001e0003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x00001a0003000000ull,
0x9800000000000000ull,0x0000000000000008ull,0x00001c0003000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x00001b0003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000170003000000ull,0x6000000000000000ull,0x0000000000000002ull,0x0000190003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000180003000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000140003000000ull,0xd000000000000000ull,0x0000000000000005ull,
0x0000160003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000150003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x00000f0003000000ull,0x0000000000000000ull,
0x0000000000000002ull,0x0000130003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000100003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000110003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000120003000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x00000c0003000000ull,0x2000000000000000ull,0x0000000000000001ull,
0x00000e0003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x00000d0003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000070003000000ull,0x0000000000000000ull,
0x0000000000000002ull,0x00000b0003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000080003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000090003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x00000a0003000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000040003000000ull,0xc000000000000000ull,0x0000000000000005ull,
0x0000060003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000050003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000200003000000ull,0x0000000000000000ull,
0x0100000000000000ull,0x000000001a000000ull,0x0000000000000000ull,0x0800000000000000ull,
0x00001d1012000000ull,0x0000000000000000ull,0x2200000000000000ull,0x00001a1012000000ull,
0x0000000000000000ull,0x3d00000000000000ull,0x0000171012000000ull,0x0000000000000000ull,
0x6000000000000000ull,0x0000141012000000ull,0x0000000000000000ull,0x7600000000000000ull,
0x00000f1012000000ull,0x0000000000000000ull,0x8e00000000000000ull,0x00000c1012000000ull,
0x0000000000000000ull,0xb100000000000000ull,0x0000071012000000ull,0x0000000000000000ull,
0xca00000000000000ull,0x0000041012000000ull,0x0000000000000000ull,0xe100000000000000ull,
0x9400200011000000ull,0x0400000000000001ull,0xe500000000000000ull,0x9000200011000000ull,
0x0400000000000001ull,0xe900000000000000ull,0x0000200011000000ull,0x0000000000000000ull,
0xf500000000000001ull,0x8c00200011000000ull,0x0400000000000001ull,0xf900000000000000ull,
0x9800200011000000ull,0x0400000000000001ull,0x0000000000000000ull,0x8800200011000001ull,
0x0400000000000001ull,0x0400000000000000ull,0x8400200011000001ull,0x0400000000000001ull,
0x0800000000000000ull,0x8000200011000001ull,0x0400000000000001ull,0x0c00000000000000ull,
0x0000200011000001ull,0x8000000000000001ull,0x1100000000000000ull,0x05e0100780300a02ull,
0x0904200780a0004eull,0x0504000780a00008ull,0x0d00400780d08002ull,0x0504200780a0004cull,
0x19c4100780300402ull,0x11c4100780300304ull,0x0904000780a00002ull,0x15c4100780300506ull,
0x0104000780a00000ull,0x0d0400478020000cull,0x05c4100780300308ull,0x00802087806000ccull,
0x0520018004200586ull,0x0dc4100780300202ull,0x05c43007803002ccull,0x21042047802000c8ull,
0x0980c00780d00e02ull,0x1d04004780200006ull,0x0580c00780d00e04ull,0x118040078060810cull,
0x0904008780200006ull,0x0580c00780d00e08ull,0x05c0000780000202ull,0x1104010780200006ull,
0x0180c00780d00e02ull,0x21e422078004000eull,0x0504004780200006ull,0x0180c00780d00e10ull,
0x1de421c780040050ull,0x2104020780200006ull,0x0180c00780d00e0eull,0x09e4208780040092ull,
0x1d0401c780200006ull,0x0180c00780d00e04ull,0x11e42107800400d4ull,0x0904008780200006ull,
0x0180c00780d00e08ull,0x01e4204780040116ull,0x01e4220780040158ull,0x01e421c78004019aull,
0x03e42087800401dcull,0x0100000000861ffeull,0x05c4100780300200ull,0x096040078060820cull,
0x0dc0000780000002ull,0x1120000780d80668ull,0x1d20000780d80458ull,0x2100200780cce4c0ull,
0x0d00200780cce1c0ull,0x0920000780d80248ull,0x050423c7841000c0ull,0x110423c7841000c0ull,
0x3520000780d80140ull,0x210021c780ece1c0ull,0x0d08220780ece4c0ull,0x1d20000780d80770ull,
0x2500200784c0e5c0ull,0x2900200780cce5c0ull,0x2d00200780cce3c0ull,0x1d00200780cce2c0ull,
0x0d0821c780ece0c0ull,0x0920000780d80350ull,0x2500208780b800ceull,0x2900224784e0e0c0ull,
0x2d08228784e0e2c0ull,0x110022c784e0e3c0ull,0x3120000780d80560ull,0x2400224780ece2c0ull,
0x05b04d0408b00d04ull,0x3108204780b800ceull,0x1d00230784e0e3c0ull,0x290021c780ece3c0ull,
0x3504228780ece5c0ull,0x2d0422c780ece0c0ull,0x1d00030780b00012ull,0x290421c784e0e2c0ull,
0x3504228784e0e0c0ull,0x2d00234784e0e5c0ull,0x2500000780c0e616ull,0x0108030780b00012ull,
0x25e422c78008000eull,0x2d00000780c0e612ull,0x010001c780b00004ull,0x25e42247800801dcull,
0x1c00000780c0e616ull,0x01b0080208b04704ull,0x1de4224780080116ull,0x2400000780c0e60eull,
0x01b0480220b00a04ull,0x05e421c7800800d4ull,0x1d00000780c0e612ull,0x0108034780b00010ull,
0x05e4204780080050ull,0x1d00000780c0e60eull,0x0100034780b00010ull,0x05e4204780080158ull,
0x0900000780c0e60eull,0x0108028780b00004ull,0x05e4204780080092ull,0x0100000780c0e604ull,
0x03e420478008019aull,0x0500000000861ffeull,0x010401478020000cull,0x0560400780608202ull,
0x01c410078030020aull,0x0904004780204000ull,0x01c0000780000000ull,0x210423c7801800d6ull,
0x2500200780c8e4daull,0x2900200780c8e5dcull,0x0500200780c8e5d0ull,0x150423c7801800d6ull,
0x1900200780c8e1daull,0x1d00200780c8e3dcull,0x0900200780c8e2dcull,0x0100200780b800ceull,
0x2500220780e8e1d2ull,0x2100224780e8e0d0ull,0x0508228780e8e0dcull,0x1508204780b800ceull,
0x2508214780e8e4d2ull,0x2d00224780e8e2d4ull,0x3108218780e8e2d0ull,0x190021c780e8e3d0ull,
0x2900000780b00004ull,0x1d00224780e8e3d8ull,0x2100220780e8e3d4ull,0x310422c780e8e5d4ull,
0x2d04230780e8e0d4ull,0x2500028780b0000cull,0x1d0421c780e8e2d8ull,0x2104220780e8e0d8ull,
0x2d00230780e8e5d8ull,0x1800000780c0e616ull,0x01b0400408b04a0cull,0x01e422c78008000eull,
0x1900000780c0e60cull,0x0100024780b00004ull,0x19e420078008001cull,0x0800000780c0e60cull,
0x01b0050200b04904ull,0x09e4218780080016ull,0x1800000780c0e604ull,0x01b0450214b00700ull,
0x05e4208780080014ull,0x0900000780c0e60cull,0x0108020780b0000aull,0x05e4204780080010ull,
0x0900000780c0e604ull,0x0100020780b0000aull,0x05e4204780080018ull,0x0100000780c0e604ull,
0x010801c780b00000ull,0x01e4204780080012ull,0x0100000780c0e600ull,0x03e420078008001aull,
0x0100000000861ffeull,0x01000000034147ecull,0x04c4100780300200ull,0x091500ee00204088ull,
0x0120000780d40140ull,0x00a0c00780d00e02ull,0x09200382041900e0ull,0x0120000780d40248ull,
0x00a0c00780d00e02ull,0x09200382041900e0ull,0x0120000780d40350ull,0x00a0c00780d00e02ull,
0x09200186041900e0ull,0x0120000780d40458ull,0x00a0c00780d00e02ull,0x09200186041900e0ull,
0x0120000780d40560ull,0x00a0c00780d00e02ull,0x09200186041900e0ull,0x0120000780d40668ull,
0x04a0c00780d00e02ull,0x051900e000200186ull,0x0920000780d40770ull,0x0104004780200006ull,
0x01a0c00780d00e02ull,0x010423c7801400c0ull,0xffa0c00781d00e04ull,0x8400000021000003ull,
0x80a0004e09000000ull,0x80a0004c05042007ull,0x042102f00c042007ull,0x80d08002052101eeull,
0x80a0000009004007ull,0x8030030611040007ull,0x8030030205c41007ull,0x80a0000215c41007ull,
0x102001840c040007ull,0x8030030a0120048aull,0x80a0000605c41007ull,0x80a000081d440147ull,
0x8020000019440147ull,0x03b0000201040087ull,0x03b0000e0503f000ull,0x8000050a0503f000ull,
0x8000020c09c00007ull,0x84f2400001c00007ull,0x8008001201000007ull,0x00861ffe03e42007ull,
0x800002040d000000ull,0x801c00d205c00007ull,0x801c00e2010423c7ull,0x80e48002050423c7ull,
0x80e4810005001f07ull,0x801c00f201000047ull,0x80dc0108110423c7ull,0x80e4820005200007ull,
0x841000c001000047ull,0x80e48300050423c7ull,0x841000d001000047ull,0x80e48400050423c7ull,
0x841000e001000047ull,0x80e48500050423c7ull,0x841000f001000047ull,0x80dc02080d0423c7ull,
0x80e4860005200007ull,0x801c00c001000047ull,0x80e48700010423c7ull,0x8008009201000047ull,
0x00861ffe03e42007ull,0x80d4024805000000ull,0x800005040d200007ull,0x001500e004c00007ull,
0x80ec8002051500e2ull,0x80ec810005001f07ull,0x801400c401000047ull,0x80ec8200050423c7ull,
0x801400c601000047ull,0x80ec8300050423c7ull,0x801400c801000047ull,0x80ec8400050423c7ull,
0x801400ca01000047ull,0x80ec8500050423c7ull,0x801400cc01000047ull,0x80ec8600050423c7ull,
0x801400ce01000047ull,0x80ec8700010423c7ull,0x8008001201000047ull,0x00861ffe03e42007ull,
0x806004cc01000000ull,0x80300200058020c7ull,0x041900f200c41007ull,0x81d00e02012101e8ull,
0x23000003ffa0c007ull,0x0400000000000000ull,0x0000000023000802ull,0x8010000005000000ull,
0x80d08006010403c7ull,0x0341082e09004007ull,0x80a000000d000000ull,0x801000cc01040007ull,
0x80200004090423c7ull,0x80400500110400c7ull,0x8060040211000007ull,0x8030100811000107ull,
0x80a0000405c41007ull,0x803003060d040007ull,0x8060040011c41007ull,0x0341082c09000107ull,
0x0820038200000000ull,0x8000010005200288ull,0x8020000401c00007ull,0x8014010009040047ull,
0x8030020001200087ull,0x80a0000405c41007ull,0x802000c809440107ull,0xc8b08103fd042007ull,
0x8010000201605107ull,0x80d00e040d0403c7ull,0x80c085060d80c007ull,0x80c0850205004006ull,
0x0490000204004006ull,0x80d082020dc00106ull,0x80d083060d044007ull,0x80b000020d044047ull,
0xc8b08403fd0000c7ull,0x80a000060d605107ull,0xd8b08303fdcc0647ull,0x801000020d605047ull,
0x80a000020d0403c2ull,0x80c0030001cc0656ull,0x81d00e0401000007ull,0x00000003ffa0c007ull,
0x00800000007e8000ull,0x004b0000003f0000ull,0x80a0004c053e8000ull,0x80a0004e0d042007ull,
0x0c2101ee08042007ull,0x80d08002092103f0ull,0x80a0000001004007ull,0x8030030409040007ull,
0x803003060dc41007ull,0x80a000041dc41007ull,0x1820028014040007ull,0x8030030e0520038eull,
0x80a0000a0dc41007ull,0x80a0000c11440147ull,0x8000020005440147ull,0x8020000209c00007ull,
0x03b0000601040007ull,0x03b000080503f000ull,0x8000020e0d03f000ull,0x8000020409c00007ull,
0x84f2400001c00007ull,0x8008001201000007ull,0x00861ffe03e42007ull,0x80d4010811000000ull,
0x841000c011200007ull,0x841000d00d0423c7ull,0x841000e0090423c7ull,0x841000f0050423c7ull,
0x80d40208110423c7ull,0x841000c001200007ull,0x801400d2250423c7ull,0x801400e2210423c7ull,
0x80ec8012250423c7ull,0x80ec881025001f07ull,0x801400f221000247ull,0x80ec9010210423c7ull,
0x80ec980811000247ull,0x80eca0060d000207ull,0x80eca80409000107ull,0x80ecb002050000c7ull,
0x80ecb80001000087ull,0x8008009201000047ull,0x00861ffe03e42007ull,0x8000050e0d000000ull,
0x80dc02480dc00007ull,0x001d00e004200007ull,0x80e48002051d00e2ull,0x80e4880005001f07ull,
0x801c00c401000047ull,0x80e49000050423c7ull,0x801c00c601000047ull,0x80e49800050423c7ull,
0x801c00c801000047ull,0x80e4a000050423c7ull,0x801c00ca01000047ull,0x80e4a800050423c7ull,
0x801c00cc01000047ull,0x80e4b000050423c7ull,0x801c00ce01000047ull,0x80e4b800010423c7ull,
0x8008001201000047ull,0x00861ffe03e42007ull,0x806006cc01000000ull,0x8030020005802147ull,
0x041900f200c41007ull,0x81d00e02012101e8ull,0x23000003ffa0c007ull,0x0400000000000000ull,
0x0000000023000802ull,0x80300a0211000000ull,0x80a0004e05e01007ull,0x80a0000809042007ull,
0x80d0800205040007ull,0x80a0004c0d004007ull,0x8030040205042007ull,0x8030030425c41007ull,
0x80a0000211c41007ull,0x8030050609040007ull,0x80a0000029c41007ull,0x8020001201040007ull,
0x803003080d040047ull,0x806000cc05c41007ull,0x04200a8600802087ull,0x8030020205200180ull,
0x803002cc1dc41007ull,0x802000c805c43007ull,0x80d00e0215042047ull,0x8020000e0980c007ull,
0x80d00e0411040047ull,0x806081120580c007ull,0x8020000e0d804007ull,0x80d00e0609040087ull,
0x800002020580c007ull,0x8020000e05c00007ull,0x80d00e020d0400c7ull,0x8004000e0180c007ull,
0x8020000e15e42147ull,0x80d00e0a05040047ull,0x800400500180c007ull,0x8020000e11e42107ull,
0x80d00e0815040147ull,0x800400920180c007ull,0x8020000e09e42087ull,0x80d00e0411040107ull,
0x800400d40180c007ull,0x8020000e21e420c7ull,0x80d00e1009040087ull,0x800401160180c007ull,
0x8004015801e42047ull,0x8004019a01e42147ull,0x800401dc01e42107ull,0x00861ffe03e42087ull,
0x8030020001000000ull,0x8060821205c41007ull,0x8000000209604007ull,0x80d8077011c00007ull,
0x80d806680d200007ull,0x841000c015200007ull,0x841000c0050423c7ull,0x80d80560110423c7ull,
0x301d00e02c200007ull,0x80d804580d1d00e0ull,0x841000c019200007ull,0x841000c0110423c7ull,
0x80d80140110423c7ull,0x0c1d00e008200007ull,0x80d803500d1d00e0ull,0x84b000c02d200007ull,
0x84b000c0310022c7ull,0x80d8024811042307ull,0x08b9056e14200007ull,0x84b000c035bd0260ull,
0x14b0020a18002187ull,0x34b00d1608b0420aull,0x04b0020c2cb04d16ull,0x84b000c011b9416eull,
0x80bc00c00d082107ull,0x80c0e6162d0420c7ull,0x80b0000c09000007ull,0x8008000e01080087ull,
0x80c0e41a19e422c7ull,0x80e0e10a19000007ull,0x80c0e60c19000187ull,0x8008009201000007ull,
0x80c0e11a2de42187ull,0x80c0e21819000007ull,0x80c0e60409000007ull,0x80e0e40a2d000007ull,
0x80e0e002190802c7ull,0x80c0e51815080187ull,0x8008011601000007ull,0x80c0e61609e42087ull,
0x80e0e3082d000007ull,0x80e0e20235000187ull,0x80c0e30219000147ull,0x8008019a01000007ull,
0x80e0e50615e42087ull,0x80e0e008090402c7ull,0x80e0e01819040347ull,0x80c0e50205000187ull,
0x80c0e60a15000007ull,0x80e0e30609000007ull,0x80e0e50819000087ull,0x80e0e3182d000187ull,
0x8008005001000047ull,0x80c0e60405e42147ull,0x80e0e20609000007ull,0x80e0e20811040187ull,
0x800800d4010002c7ull,0x80c0e60405e42047ull,0x80e0e00609000007ull,0x8008015801000107ull,
0x80c0e60405e42047ull,0x800801dc01000007ull,0x00861ffe03e42047ull,0x8020001205000000ull,
0x8060820201040287ull,0x8030021405604007ull,0x8020400001c41007ull,0x8000000009040047ull,
0x0c1900fc00c00007ull,0x081900fa041900f6ull,0x0cb9006e001900f8ull,0x08b9017004b90374ull,
0x24b0030010b90272ull,0x18b0020214b04300ull,0x081900fc04b04202ull,0x001900f80c1900faull,
0x08b9416e041900f6ull,0x80b000082db902f0ull,0x80c0e40c29000147ull,0x00b943720c000007ull,
0x80c0e6162db900f4ull,0x80e0e11229000007ull,0x8008000e01000287ull,0x80c0e61429e422c7ull,
0x80b0000811000007ull,0x80c0e10c15080147ull,0x80c0e20419000007ull,0x8008001201000007ull,
0x80c0e60811e42287ull,0x80e0e41215000007ull,0x80e0e00219080147ull,0x80c0e50425080187ull,
0x8008001601000007ull,0x80c0e60a11e42107ull,0x80e0e30615000007ull,0x80e0e20219000187ull,
0x80c0e30225000247ull,0x8008001a01000007ull,0x80e0e50011e42107ull,0x80e0e00615040147ull,
0x80e0e00419040187ull,0x80c0e50225000247ull,0x80c0e60805000007ull,0x80e0e30011000007ull,
0x80e0e50615000147ull,0x80e0e30419000187ull,0x8008001001000247ull,0x80c0e60805e42047ull,
0x80e0e20009000007ull,0x80e0e2060d040147ull,0x8008001401000187ull,0x80c0e60405e42047ull,
0x80e0e00001000007ull,0x80080018010000c7ull,0x80c0e60001e42047ull,0x8008001c01000007ull,
0x00861ffe03e42007ull,0x034147ec01000000ull,0x8030020001000000ull,0x0020409004c41007ull,
0x80d40140091500eeull,0x80d00e0201200007ull,0x041900e000a0c007ull,0x80d4024809200782ull,
0x80d00e0201200007ull,0x041900e000a0c007ull,0x80d4035009200782ull,0x80d00e0201200007ull,
0x041900e000a0c007ull,0x80d404580920018eull,0x80d00e0201200007ull,0x041900e000a0c007ull,
0x80d405600920018eull,0x80d00e0201200007ull,0x041900e000a0c007ull,0x80d406680920018eull,
0x80d00e0201200007ull,0x0020018e04a0c007ull,0x80d40770051900e0ull,0x8020000e09200007ull,
0x80d00e0201040047ull,0x801400c001a0c007ull,0x81d00e04010423c7ull,0x21000003ffa0c007ull,
0x0500000084000000ull,0x010403c780100000ull,0x0d00400780d08006ull,0x090000000341082eull,
0x0104000780a00000ull,0x0d0423c7801000ccull,0x1104008780200006ull,0x1100000780400700ull,
0x1100010780600602ull,0x0dc4100780301008ull,0x0100010780600600ull,0x0d0000000341082cull,
0x0104000780200006ull,0x0504000780a00004ull,0x08c4100780300304ull,0x0520018000200086ull,
0x05c4100780300104ull,0x0dc0000780000100ull,0x03042047802000c8ull,0x0900000000a00230ull,
0x0120008780140100ull,0x0580600780d00e06ull,0xfd0c010780a00004ull,0x096c0187c8307c01ull,
0x03ec100780300102ull,0x01000002801001f0ull,0x0904000780204004ull,0x010403c780100002ull,
0x030c010780a00000ull,0x01000007802002b0ull,0x0300000003300080ull,0x0100000780100230ull,
0x0904008780200000ull,0x010403c780100002ull,0x030c010780a00000ull,0x01000007802002b0ull,
0x03e0000002f00000ull,0x0900000000861ffeull,0x0900000780400300ull,0x0900008780600202ull,
0x01c4100780301004ull,0x0100008780600200ull,0x03a0600780d00e06ull,0x1100000780300000ull,
0x1504114780a00004ull,0x1944004780a00008ull,0x1d04114780a00000ull,0x150000078090000aull,
0x1d44064780a0000cull,0x150fffffff203e8eull,0x150000c7c0c0070aull,0x2184064780a0000aull,
0x2100000780400b10ull,0x2100020780600a12ull,0x21c4100780301010ull,0x2100020780600a10ull,
0x210402078020400cull,0x1d44064780a00010ull,0x1d0000c7c0c00710ull,0x1584064780a0000eull,
0x1d0401c78020000aull,0x1d00000780400816ull,0x1d0001c780600914ull,0x1dc410078030100eull,
0x190001c780600814ull,0x110401878030000eull,0x016400c780300608ull,0x0104008780d00004ull,
0x15e4100780301f00ull,0x1104014780300008ull,0x112c014780a00000ull,0xfd04008780d00508ull,
0x016c0147c8307c05ull,0x0104010780200000ull,0x030402c500d00200ull,0x0100000780300000ull,
0xffe0000001f00000ull,0x80d0820209000003ull,0x80300a0205004007ull,0x80a0000405e01007ull,
0x80a0004e0d040007ull,0x80a0000009042007ull,0x80a0000201040007ull,0x8030030205040007ull,
0x80a0004c11c41007ull,0x803005060d042007ull,0x8030030025c41007ull,0x8020000229c41007ull,
0x8030050809040087ull,0x8020001205c41007ull,0x80300114010400c7ull,0x806001cc09c41007ull,
0x8060801205802087ull,0x8020000009804007ull,0x03200e8205040087ull,0xd03082140d000000ull,
0x80300104096c40c7ull,0x8000010205c41007ull,0xc8a00007fdc00007ull,0x00a00320030c0147ull,
0x802000c81d000000ull,0x0010032003042087ull,0x80d00e0e09000011ull,0x803001cc0580c007ull,
0x802000020dc43007ull,0x80d00e06150401c7ull,0x802000020d80c007ull,0x80d00e06110400c7ull,
0x802000021980c007ull,0x80d00e0c0d0400c7ull,0x800400000180c007ull,0x8020000219e42087ull,
0x80d00e0c09040187ull,0x800400220180c007ull,0x8020000219e42147ull,0x80d00e0c15040187ull,
0x800400440180c007ull,0x8020000219e42107ull,0x80d00e0c11040187ull,0x800400660180c007ull,
0x802000021de420c7ull,0x80d00e0e05040187ull,0x800400880180c007ull,0x800400aa01e42087ull,
0x800400cc01e42147ull,0x800400ee01e42107ull,0x80d403b805e42047ull,0x02f0000001200007ull,
0x00861ffe03e00000ull,0x8030041405000000ull,0x80d0840205ec1007ull,0x80d0010005044007ull,
0x80d0831401040047ull,0x80d0850205044007ull,0x80d0010001044007ull,0x8030010001040047ull,
0x8060861201c41007ull,0x8000000009604007ull,0x80d801480dc00007ull,0x80d801d011200007ull,
0x80ac00800d200007ull,0x80d803680d0c2107ull,0x84a0008001200007ull,0x80d80258110c2107ull,
0x80ac008009200007ull,0x84a00080190c2107ull,0x80d802e00d0c2107ull,0x0f407c8405200007ull,
0x6740428415000003ull,0x80a8009c11000007ull,0x80ac0080090c2107ull,0x80608706050c2107ull,
0x80608a0615804047ull,0x182006880c844147ull,0x0820028020204688ull,0x80d803f011204280ull,
0x0310008001200007ull,0x80d800c00d000001ull,0x84a000802d200007ull,0x80608804090c2107ull,
0x80ac008011804007ull,0x80608810010c2107ull,0x8030021621804007ull,0x80300d0431c41007ull,
0x8030020809ec1007ull,0x80300d002dc41007ull,0x8060880601ec1007ull,0x8020001011804047ull,
0x8060880605040307ull,0x2c200b840c844047ull,0x63407e8809204b84ull,0xf740638811000000ull,
0x8020401021000001ull,0x8060890609040307ull,0x80608d0611804087ull,0x8060880c0d844107ull,
0x8060880c19804147ull,0x1f40479035844147ull,0x8020000031000001ull,0xab405b9015040087ull,
0x80608b1621000001ull,0x0320009831844347ull,0x80608c162d000008ull,0x8020000635804147ull,
0x8030101815040207ull,0x0320009a35ec1007ull,0x8008001c01000008ull,0x8020000c31e00287ull,
0x8030101a150402c7ull,0x8020400009ec1007ull,0x0320009801040087ull,0x802040060d000008ull,
0x8008006001040207ull,0x8020000215e00287ull,0x8030100001040107ull,0x8020400211ec1007ull,
0x0320008a05040107ull,0x8020400c15000008ull,0x800800a4010402c7ull,0x0320008811e00007ull,
0x8030100201000008ull,0x0320008a15ec1007ull,0x8030100805000008ull,0x800800e801ec1007ull,
0x032000860de00007ull,0x8030100a01000008ull,0x8008012c01ec1007ull,0x0320008409e00087ull,
0x8030100605000008ull,0x8008017001ec1007ull,0x8030100401e00007ull,0x800801b401ec1007ull,
0x800801f801e00087ull,0x00861ffe03e00007ull,0x8030011201000000ull,0x8060861401c41007ull,
0x8000000009604007ull,0x803810d001c00007ull,0x803810d205ec3007ull,0x042001800cec3007ull,
0x0310008009204180ull,0x8060880601000001ull,0x8060880209804087ull,0x803810d011804087ull,
0x803810d421c43007ull,0x803810ce05c43007ull,0x803810d219c43007ull,0x803810d40dc43007ull,
0x803810ce15ec3007ull,0x8030100829ec3007ull,0x8030101011ec1007ull,0x8030100205ec1007ull,
0x8030100c31ec1007ull,0x803002062dec1007ull,0x0f407c880dc41007ull,0x8030020a15000003ull,
0x80300d0425c41007ull,0x6740428819ec1007ull,0x806087140d000007ull,0x80300d00118040c7ull,
0x8020001621ec1007ull,0x80608a1419040247ull,0x28200c8208844187ull,0x63407e900120048aull,
0x8020400231000000ull,0x8060880405040307ull,0x80608914018040c7ull,0x806088040d804007ull,
0x80608818098440c7ull,0x8060881819804187ull,0x8020000031844187ull,0x0320009831040047ull,
0x8030101831000008ull,0x8020401635ec1007ull,0x80d88ece25040247ull,0x80d08f182d046007ull,
0x80d00b122d044007ull,0x8030101625040047ull,0x8030021225ec1007ull,0x1420448a30c41007ull,
0x1f40479a11300988ull,0x80608b0a15000001ull,0xf740639025844107ull,0xab405b9a21000001ull,
0x8020000415000001ull,0x80608d1425040147ull,0x80608c1821844247ull,0x80608b1811804207ull,
0x0320008a15844107ull,0x2830018000000008ull,0x802040040520088cull,0x8030100a11040107ull,
0x8020000631ec1007ull,0x0320009415040247ull,0x8020400609000008ull,0x80d08f080d040247ull,
0x0320009829044007ull,0x8030100a25000008ull,0x80d08f1611ec1007ull,0x8030100615044007ull,
0x80d88ed00dc41007ull,0x8030101429046007ull,0x80d08f1225ec1007ull,0x80d0050811044007ull,
0x032000842d040047ull,0x80d08f1415000008ull,0x80d0090609044007ull,0x8020400c21040047ull,
0x8030101619040207ull,0x8030100a0dec1007ull,0x80d08f0409c41007ull,0x80d88ed215044007ull,
0x0320009021046007ull,0x80d08f0c19000008ull,0x80d0030409044007ull,0x0320008225040047ull,
0x803010100d000008ull,0x80d0060a05ec1007ull,0x0320008021040047ull,0x8030101219000008ull,
0x80d08f0601ec1007ull,0x80d88ed415044007ull,0x8030101021046007ull,0x80d08f0c19ec1007ull,
0x803010000d044007ull,0x80d08f0201c41007ull,0x80d08f1021044007ull,0x80d0060a05044007ull,
0x8008000e01040047ull,0x80d0030001e42107ull,0x803010100d040047ull,0x80d08f0205c41007ull,
0x8008001001044007ull,0x80d0030205e42087ull,0x8008001201040047ull,0x8008001401e42007ull,
0x00861ffe03e42047ull,0x0030000003000000ull,0x8004000001000001ull,0xfb203c8009400007ull,
0x801400c0010fffffull,0x803001cc050423c7ull,0x800400000dc43007ull,0x8000000409400007ull,
0x80d00e0e01c00007ull,0x8020400e09a0c007ull,0xf32034860d040047ull,0x801800c0010fffffull,
0x80000006090423c7ull,0x80d00e0401c00007ull,0x800400000da0c007ull,0x8020400409400007ull,
0x801800e201040047ull,0xeb202c860d0423c7ull,0x80d00e04010fffffull,0x0030028208a0c007ull,
0x80000006091900e0ull,0x80d00e0401c00007ull,0x801800e201a0c007ull,0x80300002090423c7ull,
0x800400000d040087ull,0x80d00e0401400007ull,0xe32024860da0c007ull,0x081900e0000fffffull,
0x8000000605300282ull,0x80d00e0401c00007ull,0x8030000209a0c007ull,0x801400e201040087ull,
0x80300002050423c7ull,0x80d00e0401040087ull,0x801400c001a0c007ull,0x81d00e02010423c7ull,
0xff00000022a0c007ull,0xe00000000f000003ull,0x1f00000001ffffffull,0x4200000044000000ull,
0x6300005a82000076ull,0x9b000030fc00001full,0x3e000011c700001aull,0xffffff0000000006ull,
0x80300a02090000ffull,0x80a0004e09e01007ull,0x80a0000405042007ull,0x8030050409040007ull,
0x8030030215c41007ull,0x801000cc05c41007ull,0x8020000a090423c7ull,0x80d0820205040087ull,
0x8040050411004007ull,0x80a000020d000007ull,0x8060040619040007ull,0x80a0000011000107ull,
0x8030030601040007ull,0x8030100c0dc41007ull,0x80a0004c1dc41007ull,0x8020000019042007ull,
0x8060040405040107ull,0x8030050e090000c7ull,0x8030010c01c41007ull,0x8020000209c41007ull,
0x8060800a05040087ull,0x8020000009804007ull,0x03200e8205040087ull,0xd030820c0d000000ull,
0x80300104096c40c7ull,0x8000010205c41007ull,0xc8a00007fdc00007ull,0x00a00370030c0147ull,
0x802000c811000000ull,0x0010037003042087ull,0x80d00e0809000011ull,0x803001cc0580c007ull,
0x802000020dc43007ull,0x80d00e061d040107ull,0x802000020d80c007ull,0x80d00e06110400c7ull,
0x802000022180c007ull,0x80d00e100d0400c7ull,0x800400000180c007ull,0x8020000221e42087ull,
0x80d00e1009040207ull,0x800400220180c007ull,0x802000021de421c7ull,0x80d00e0e21040207ull,
0x800400440180c007ull,0x8020000211e42107ull,0x80d00e081d0401c7ull,0x800400660180c007ull,
0x8020000211e420c7ull,0x80d00e0805040107ull,0x800400880180c007ull,0x800400aa01e42087ull,
0x800400cc01e42207ull,0x800400ee01e421c7ull,0x80d403b805e42047ull,0x02f0000001200007ull,
0x00861ffe03e00000ull,0x8030040c05000000ull,0x80d0840205ec1007ull,0x80d0010005044007ull,
0x80d0830c01040047ull,0x80d0850205044007ull,0x80d0010001044007ull,0x8030010001040047ull,
0x8060860a01c41007ull,0x8000000009604007ull,0x80d800c00dc00007ull,0x80d8014811200007ull,
0x80ac00801d200007ull,0x80d801d00d0c2107ull,0x84a0008021200007ull,0x80d80258110c2107ull,
0x80ac008005200007ull,0x80d803f00d0c2107ull,0x84a0008025200007ull,0x80d80368110c2107ull,
0x80a8009c01200007ull,0x80ac00800d0c2107ull,0x84a00080310c2107ull,0x80d802e00d0c2107ull,
0x2820038008200007ull,0x80ac00802d204380ull,0x242009820c0c2107ull,0x04200c8e00204982ull,
0x20204c8e1c200b90ull,0x2c20038430204b90ull,0x0c20438434200180ull,0x0310008001204180ull,
0x8020001805000008ull,0x80608702090402c7ull,0x0f407c8605804007ull,0x674042860d000003ull,
0x8060881a05000007ull,0x8060891a0d804047ull,0x80301004098440c7ull,0x0320008205ec1007ull,
0x802040182d000008ull,0x032000860d0402c7ull,0x8008001c01000008ull,0x8030100205e00107ull,
0x8030100609ec1007ull,0x031000800dec1007ull,0x1c20088e30000001ull,0x800800a40120488eull,
0x8060871805e00087ull,0x8060870e0d8040c7ull,0x80300214218040c7ull,0x80300d0229c41007ull,
0x8060871601ec1007ull,0x8030021225804007ull,0x80300d062dc41007ull,0x802000101dec1007ull,
0x8030100005040287ull,0x802000120dec1007ull,0xf740638e010402c7ull,0x8020401225000001ull,
0x8008012c010402c7ull,0x8020401029e00087ull,0x80608a0601040287ull,0x1f40479205804007ull,
0x800801b401000001ull,0x0320008021e00107ull,0x80608b1405000008ull,0x1f40479401844047ull,
0xf740638609000001ull,0x803010100d000001ull,0x80608b1201ec1007ull,0x0320008205804007ull,
0x80608a0e09000008ull,0x8008006001844087ull,0x032000800de00187ull,0x8030100201000008ull,
0x0320008409ec1007ull,0x8030100605000008ull,0x800800e801ec1007ull,0x8030100401e00007ull,
0x8008017001ec1007ull,0x800801f801e00087ull,0x00861ffe03e00007ull,0x8030010a01000000ull,
0x8060860c01c41007ull,0x8000000009604007ull,0x803810d00dc00007ull,0x803810d201ec3007ull,
0x803810ce05c43007ull,0x803810d409c43007ull,0x803810d01dec3007ull,0x803810d225c43007ull,
0x803810ce35ec3007ull,0x803810d429ec3007ull,0x8030100019c43007ull,0x8030100215ec1007ull,
0x8030100e21ec1007ull,0x8030101431ec1007ull,0x0420068600ec1007ull,0x282009901c20028aull,
0x1420468618200c9aull,0x082001800c20428aull,0x8030000005200a8eull,0x0310008001040047ull,
0x8020000609000008ull,0x8060870409040087ull,0x803010042d804007ull,0x80d88cce09ec1007ull,
0x80d08d162d046007ull,0x80d00b0409044007ull,0x803010042d040047ull,0x30200b982cec1007ull,
0x0c200b8e34204c9aull,0x8060870601204d86ull,0x803010000d804007ull,0x80d88cd201ec1007ull,
0x80d08d060d046007ull,0x80d003000d044007ull,0x8030100601040047ull,0x0020009000ec1007ull,
0x0f407c8001204096ull,0x8060880201000003ull,0x8020401021804007ull,0x0320008001040247ull,
0x24300a8e1c000008ull,0x8030100001200c90ull,0x8030001029ec1007ull,0x80d88cd021040307ull,
0x6740428e1d046007ull,0x80d08d002d000007ull,0x0310008001044007ull,0x8060890205000001ull,
0x80d00b10218441c7ull,0x806087141d040047ull,0x8060871201804007ull,0x8030020c19804007ull,
0x0320008225c41007ull,0x80300d0e29000008ull,0x8030020a05ec1007ull,0x80300d0015c41007ull,
0x8030101201ec1007ull,0x8020000c25ec1007ull,0x80d88cd42d040287ull,0x802000021d046007ull,
0x80d08d0031040147ull,0x63407e9201044007ull,0x8020400c29000000ull,0x80d00c1619040287ull,
0x80608e0e01040047ull,0x802040022d804007ull,0xab405b9415040147ull,0x1f40479405000001ull,
0x0320008029000001ull,0xf740639201000008ull,0x80608f1615000001ull,0x80608b1605804147ull,
0x8030101425844047ull,0x80608a0e01ec1007ull,0x0320008a29844007ull,0x032000821d000008ull,
0x80d08d1215000008ull,0x80d08d0405044007ull,0x8030101425044007ull,0x8030100e1dec1007ull,
0x8030100a09ec1007ull,0x0320008029c41007ull,0x80d08d1225000008ull,0x80d08d0e15044007ull,
0x80d0020201044007ull,0x8030101429040047ull,0x803010121dec1007ull,0x8030100a09c41007ull,
0x80d08d1005c41007ull,0x80d08d060d044007ull,0x8008000e01044007ull,0x80d08d1415e42007ull,
0x80d0020201044007ull,0x80d0070605040047ull,0x80d08d0c09040047ull,0x8030100a0d044007ull,
0x8008001001c41007ull,0x80d0030401e42007ull,0x8008001201040047ull,0x8008001401e42047ull,
0x00861ffe03e42007ull,0x0030000003000000ull,0x8004000001000001ull,0xfb203c8009400007ull,
0x801400c0010fffffull,0x803001cc050423c7ull,0x800400000dc43007ull,0x8000000409400007ull,
0x80d00e0801c00007ull,0x8020400809a0c007ull,0xf32034860d040047ull,0x801800c0010fffffull,
0x80000006090423c7ull,0x80d00e0401c00007ull,0x800400000da0c007ull,0x8020400409400007ull,
0x801800e201040047ull,0xeb202c860d0423c7ull,0x80d00e04010fffffull,0x0030028208a0c007ull,
0x80000006091900e0ull,0x80d00e0401c00007ull,0x801800e201a0c007ull,0x80300002090423c7ull,
0x800400000d040087ull,0x80d00e0401400007ull,0xe32024860da0c007ull,0x081900e0000fffffull,
0x8000000605300282ull,0x80d00e0401c00007ull,0x8030000209a0c007ull,0x801400e201040087ull,
0x80300002050423c7ull,0x80d00e0401040087ull,0x801400c001a0c007ull,0x81d00e02010423c7ull,
0xff00000022a0c007ull,0xe00000000f000003ull,0x1f00000001ffffffull,0x8200000044000000ull,
0xfc0000764200005aull,0x9b0000063e000030ull,0xffffff000000001aull,0xc700001f630000ffull,
0xbe3eb504f3000011ull,0x313eec835e3efb14ull,0xda3eb504f33ed4dbull,0xc23e43ef153e8e39ull,
0x313eb504f33dc7c5ull,0xc23e43ef153ed4dbull,0xbebeb504f3bdc7c5ull,0xdabeec835ebefb14ull,
0xda3eb504f3be8e39ull,0xbebe43ef153e8e39ull,0xc2beb504f3befb14ull,0x313eec835e3dc7c5ull,
0xc23eb504f33ed4dbull,0xdabeec835e3dc7c5ull,0x313eb504f3be8e39ull,0xbebe43ef153ed4dbull,
0xc23eb504f3befb14ull,0xdabeec835ebdc7c5ull,0x313eb504f33e8e39ull,0xbebe43ef15bed4dbull,
0xda3eb504f33efb14ull,0xbebe43ef15be8e39ull,0xc2beb504f33efb14ull,0x313eec835ebdc7c5ull,
0x313eb504f3bed4dbull,0xc23e43ef15bed4dbull,0xbebeb504f33dc7c5ull,0xdabeec835e3efb14ull,
0xbe3eb504f33e8e39ull,0x313eec835ebefb14ull,0xda3eb504f3bed4dbull,0xc23e43ef15be8e39ull,
0x3300210020bdc7c5ull,0x2200270042005100ull,0x3000240021001100ull,0x0c0017001c002f00ull,
0x2f00300033000c00ull,0x0c000c0017001c00ull,0x1c002f0051000c00ull,0x0c000c000c001700ull,
0x17001c0042000c00ull,0x0c000c000c000c00ull,0x0c00170027000c00ull,0x0c000c000c000c00ull,
0x0c000c0022000c00ull,0x0c000c000c000c00ull,0x0c000c0011000c00ull,0x0c000c000c000c00ull,
0x753fb18a86000c00ull,0x4e3f9683173fa73dull,0xaf3f0a8bd43f4923ull,0x003eb504f33e8d42ull,
0x0000000500000006ull,0x00000000000039a0ull,0x0000000000000000ull,0x0000000000000000ull,
0x00000000000003f0ull,0x00000000000003f0ull,0x0000000000000004ull,0x00002b0560000000ull,
0x00000000000012d7ull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000005ccull,
0x00000000000005ccull,0x0000000000000004ull,0x00002b0660000000ull,0x00000000000018a3ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x000000000000085cull,
0x0000000000000004ull,0x00002a0560000000ull,0x00000000000018a3ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000218ull,0x0000000000000218ull,0x0000000000000004ull,
0x00002a0660000000ull,0x0000000000001abbull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000224ull,0x0000000000000004ull,0x0000290560000000ull,
0x0000000000001abbull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000138ull,
0x0000000000000138ull,0x0000000000000004ull,0x0000290660000000ull,0x0000000000001bf3ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x000000000000001cull,
0x0000000000000004ull,0x0000280560000000ull,0x0000000000001bf3ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000218ull,0x0000000000000218ull,0x0000000000000004ull,
0x0000280660000000ull,0x0000000000001e0bull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000224ull,0x0000000000000004ull,0x0000270560000000ull,
0x0000000000001e0bull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000005dcull,
0x00000000000005dcull,0x0000000000000004ull,0x0000270660000000ull,0x00000000000023e7ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x000000000000085cull,
0x0000000000000004ull,0x0000260560000000ull,0x00000000000023e7ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000264ull,0x0000000000000264ull,0x0000000000000004ull,
0x0000260660000000ull,0x000000000000264bull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x000000000000001cull,0x0000000000000004ull,0x0000250560000000ull,
0x000000000000264bull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000008d8ull,
0x00000000000008d8ull,0x0000000000000004ull,0x0000250660000000ull,0x0000000000002f23ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x000000000000089cull,
0x0000000000000004ull,0x0000240560000000ull,0x0000000000002f23ull,0x0000000000000000ull,
0x0000000000000000ull,0x00000000000008e0ull,0x00000000000008e0ull,0x0000000000000004ull,
0x0000240660000000ull,0x0000000000003803ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x000000000000089cull,0x0000000000000004ull,0x0000000500000001ull,
0x0000000000003803ull,0x0000000000000000ull,0x0000000000000000ull,0x000000000000019cull,
0x000000000000019cull,0x0000000000000004ull,0x0000000000000000ull
};


}



extern "C" {


static const unsigned long long __deviceText_$compute_10$[] = {
0x6f69737265762e09ull,0x2e090a342e31206eull,0x7320746567726174ull,0x616d202c30315f6dull,
0x6f745f3436665f70ull,0x2f2f090a3233665full,0x656c69706d6f6320ull,0x2f20687469772064ull,
0x61636f6c2f727375ull,0x6f2f616475632f6cull,0x696c2f34366e6570ull,0x2f090a65622f2f62ull,
0x6e65706f766e202full,0x6220302e33206363ull,0x206e6f20746c6975ull,0x2d30312d39303032ull,
0x2d2f2f090a0a3632ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x43202f2f090a2d2dull,0x676e696c69706d6full,0x6d742f706d742f20ull,0x3030305f74667870ull,
0x30305f6537303330ull,0x372d303030303030ull,0x2e3878387463645full,0x2820692e33707063ull,
0x4263632f706d742full,0x554248794b2e2349ull,0x2d2d2f2f090a2963ull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2f2f090a0a2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x704f202f2f090a2dull,0x090a3a736e6f6974ull,
0x2d2d2d2d2d2d2f2full,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2f090a2d2d2d2d2dull,
0x656772615420202full,0x49202c7874703a74ull,0x30315f6d733a4153ull,0x6e6169646e45202cull,
0x2c656c7474696c3aull,0x7265746e696f5020ull,0x34363a657a695320ull,0x4f2d20202f2f090aull,
0x6d6974704f280933ull,0x206e6f6974617a69ull,0x090a296c6576656cull,0x0930672d20202f2full,
0x6c20677562654428ull,0x2f090a296c657665ull,0x2809326d2d20202full,0x612074726f706552ull,
0x6569726f73697664ull,0x2d2d2f2f090a2973ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x6c69662e090a0a2dull,0x6f633c2209310965ull,0x696c2d646e616d6dull,
0x662e090a223e656eull,0x2f22093209656c69ull,0x78706d742f706d74ull,0x33303030305f7466ull,
0x303030305f653730ull,0x645f362d30303030ull,0x75632e3878387463ull,0x70672e3265666164ull,
0x6c69662e090a2275ull,0x7463642209330965ull,0x6e72656b5f387838ull,0x74726f68735f6c65ull,
0x662e090a2275632eull,0x2f22093409656c69ull,0x2f62696c2f727375ull,0x363834692f636367ull,
0x672d78756e696c2dull,0x312e342e342f756eull,0x6564756c636e692full,0x2e6665646474732full,
0x6c69662e090a2268ull,0x73752f2209350965ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x2f7472632f656475ull,0x725f656369766564ull,0x682e656d69746e75ull,
0x656c69662e090a22ull,0x7273752f22093609ull,0x632f6c61636f6c2full,0x2f6e69622f616475ull,
0x756c636e692f2e2eull,0x5f74736f682f6564ull,0x2e73656e69666564ull,0x6c69662e090a2268ull,
0x73752f2209370965ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x6c6975622f656475ull,0x657079745f6e6974ull,0x662e090a22682e73ull,0x2f22093809656c69ull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65642f6564756c63ull,
0x7079745f65636976ull,0x2e090a22682e7365ull,0x22093909656c6966ull,0x636f6c2f7273752full,
0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x642f6564756c636eull,0x79745f7265766972ull,
0x090a22682e736570ull,0x303109656c69662eull,0x6c2f7273752f2209ull,0x6475632f6c61636full,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x656361667275732full,0x682e73657079745full,
0x656c69662e090a22ull,0x73752f2209313109ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x747865742f656475ull,0x657079745f657275ull,0x662e090a22682e73ull,
0x2209323109656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x762f6564756c636eull,0x79745f726f746365ull,0x090a22682e736570ull,0x333109656c69662eull,
0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,
0x5f6563697665642full,0x705f68636e75616cull,0x726574656d617261ull,0x662e090a22682e73ull,
0x2209343109656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x632f6564756c636eull,0x61726f74732f7472ull,0x7373616c635f6567ull,0x69662e090a22682eull,
0x2f2209353109656cull,0x6c636e692f727375ull,0x737469622f656475ull,0x682e73657079742full,
0x656c69662e090a22ull,0x73752f2209363109ull,0x64756c636e692f72ull,0x682e656d69742f65ull,
0x656c69662e090a22ull,0x7463642209373109ull,0x6e72656b5f387838ull,0x0a2275632e326c65ull,
0x3109656c69662e09ull,0x7838746364220938ull,0x6c656e72656b5f38ull,0x2e090a2275632e31ull,
0x09393109656c6966ull,0x5f38783874636422ull,0x715f6c656e72656bull,0x74617a69746e6175ull,
0x0a2275632e6e6f69ull,0x3209656c69662e09ull,0x7838746364220930ull,0x2e090a2275632e38ull,
0x09313209656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x665f6e6f6d6d6f63ull,0x736e6f6974636e75ull,0x69662e090a22682eull,
0x2f2209323209656cull,0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x72632f6564756c63ull,0x6d5f636e75662f74ull,0x0a22682e6f726361ull,0x3209656c69662e09ull,
0x2f7273752f220933ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x665f6874616d2f65ull,0x736e6f6974636e75ull,0x69662e090a22682eull,0x2f2209343209656cull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65642f6564756c63ull,
0x6e75665f65636976ull,0x682e736e6f697463ull,0x656c69662e090a22ull,0x73752f2209353209ull,
0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x6874616d2f656475ull,
0x6e6174736e6f635full,0x2e090a22682e7374ull,0x09363209656c6966ull,0x6f6c2f7273752f22ull,
0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x74615f31315f6d73ull,
0x6e75665f63696d6full,0x682e736e6f697463ull,0x656c69662e090a22ull,0x73752f2209373209ull,
0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x315f6d732f656475ull,
0x63696d6f74615f32ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09383209656c6966ull,
0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x6f645f33315f6d73ull,0x6e75665f656c6275ull,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x73752f2209393209ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x6d6d6f632f656475ull,0x73657079745f6e6full,0x69662e090a22682eull,0x2f2209303309656cull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x6d732f6564756c63ull,
0x6d6f74615f30325full,0x74636e75665f6369ull,0x0a22682e736e6f69ull,0x3309656c69662e09ull,
0x2f7273752f220931ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x5f30325f6d732f65ull,0x69736e6972746e69ull,0x2e090a22682e7363ull,0x09323309656c6966ull,
0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x5f65636166727573ull,0x6e6f6974636e7566ull,0x662e090a22682e73ull,0x2209333309656c69ull,
0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x742f6564756c636eull,
0x665f657275747865ull,0x6e75665f68637465ull,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x73752f2209343309ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x6874616d2f656475ull,0x6f6974636e75665full,0x705f6c62645f736eull,0x0a0a22682e317874ull,
0x752e207865742e09ull,0x7253786554203436ull,0x6168732e090a3b63ull,0x696c612e20646572ull,
0x38622e2034206e67ull,0x636f6c4272754320ull,0x5b316c61636f4c6bull,0x2e090a3b5d363532ull,
0x2e20646572616873ull,0x2034206e67696c61ull,0x427275432038622eull,0x61636f4c6b636f6cull,
0x3b5d3635325b326cull,0x74736e6f632e090aull,0x206e67696c612e20ull,0x43442038622e2034ull,
0x697274616d387654ull,0x3d205d3635325b78ull,0x2c342c3334327b20ull,0x312c32362c313831ull,
0x35322c30322c3039ull,0x2c34392c32362c31ull,0x2c3633322c313331ull,0x31322c39342c3236ull,
0x32362c3231322c39ull,0x312c342c3334322cull,0x31322c32362c3138ull,0x3234312c37352c38ull,
0x322c31322c32362cull,0x32362c37362c3933ull,0x3739312c3439312cull,0x2c31362c3939312cull,
0x38312c342c333432ull,0x2c39342c32362c31ull,0x2c3231322c393132ull,0x33322c31322c3236ull,
0x2c32362c37362c39ull,0x2c3739312c343931ull,0x2c3938312c393931ull,0x38312c342c333432ull,
0x39312c3039312c31ull,0x3135322c30322c30ull,0x2c34392c3039312cull,0x2c3633322c313331ull,
0x2c3831322c303931ull,0x312c3234312c3735ull,0x342c3334322c3039ull,0x2c32362c3138312cull,
0x312c37352c383132ull,0x31322c32362c3234ull,0x2c37362c3933322cull,0x2c3039312c303931ull,
0x312c3135322c3032ull,0x342c3334322c3039ull,0x3039312c3138312cull,0x3739312c3439312cull,
0x2c31362c3939312cull,0x322c3133312c3439ull,0x39342c32362c3633ull,0x3231322c3931322cull,
0x2c3334322c32362cull,0x32362c3138312c34ull,0x3739312c3439312cull,0x2c31362c3939312cull,
0x322c3133312c3439ull,0x322c3039312c3633ull,0x34312c37352c3831ull,0x34322c3039312c32ull,
0x2c3138312c342c33ull,0x31322c39342c3236ull,0x32362c3231322c39ull,0x2c3933322c31322cull,
0x312c3039312c3736ull,0x35322c30322c3039ull,0x34322c3039312c31ull,0x2c3138312c342c33ull,
0x312c3439312c3236ull,0x312c3939312c3739ull,0x33312c34392c3938ull,0x39312c3633322c31ull,
0x37352c3831322c30ull,0x2c32362c3234312cull,0x38312c342c333432ull,0x2c39342c32362c31ull,
0x2c3231322c393132ull,0x322c31322c303931ull,0x39312c37362c3933ull,0x30322c3039312c30ull,
0x2c32362c3135322cull,0x38312c342c333432ull,0x3831322c32362c31ull,0x2c3234312c37352cull,
0x322c31322c303931ull,0x39312c37362c3933ull,0x30322c3039312c30ull,0x2c32362c3135322cull,
0x38312c342c333432ull,0x39312c3039312c31ull,0x39312c3739312c34ull,0x34392c3938312c39ull,
0x3633322c3133312cull,0x322c39342c32362cull,0x312c3231322c3931ull,0x342c3334322c3039ull,
0x2c32362c3138312cull,0x322c3931322c3934ull,0x322c3039312c3231ull,0x37362c3933322c31ull,
0x2c3439312c32362cull,0x2c3939312c373931ull,0x342c3334322c3136ull,0x3039312c3138312cull,
0x2c30322c3039312cull,0x392c32362c313532ull,0x33322c3133312c34ull,0x31322c3039312c36ull,
0x3234312c37352c38ull,0x2c3334322c32362cull,0x32362c3138312c34ull,0x2c30322c3039312cull,
0x2c3039312c313532ull,0x322c3133312c3439ull,0x39342c32362c3633ull,0x3231322c3931322cull,
0x3334322c3039312cull,0x362c3138312c342cull,0x37352c3831322c32ull,0x3039312c3234312cull,
0x2c3933322c31322cull,0x39312c32362c3736ull,0x39312c3739312c34ull,0x0a3b7d3938312c39ull,
0x2074736e6f632e09ull,0x32206e67696c612eull,0x315b512038622e20ull,0x337b203d205d3832ull,
0x302c33332c302c32ull,0x31382c302c31352cull,0x2c302c36362c302cull,0x2c34332c302c3933ull,
0x332c302c37312c30ull,0x302c36332c302c33ull,0x37342c302c38342cull,0x2c302c38322c302cull,
0x2c32312c302c3332ull,0x352c302c32312c30ull,0x302c38342c302c31ull,0x38322c302c37342cull,
0x2c302c33322c302cull,0x2c32312c302c3231ull,0x382c302c32312c30ull,0x302c37342c302c31ull,
0x33322c302c38322cull,0x2c302c32312c302cull,0x2c32312c302c3231ull,0x362c302c32312c30ull,
0x302c38322c302c36ull,0x32312c302c33322cull,0x2c302c32312c302cull,0x2c32312c302c3231ull,
0x332c302c32312c30ull,0x302c33322c302c39ull,0x32312c302c32312cull,0x2c302c32312c302cull,
0x2c32312c302c3231ull,0x332c302c32312c30ull,0x302c32312c302c34ull,0x32312c302c32312cull,
0x2c302c32312c302cull,0x2c32312c302c3231ull,0x312c302c32312c30ull,0x302c32312c302c37ull,
0x32312c302c32312cull,0x2c302c32312c302cull,0x2c32312c302c3231ull,0x3b7d302c32312c30ull,
0x74736e6f632e090aull,0x5f43203233662e20ull,0x66336630203d2061ull,0x2f20363861383162ull,
0x303738332e31202aull,0x2e090a3b2f2a2034ull,0x662e2074736e6f63ull,0x3d20625f43203233ull,
0x3337616633663020ull,0x31202a2f20353764ull,0x2a2036353630332eull,0x6e6f632e090a3b2full,
0x203233662e207473ull,0x6630203d20635f43ull,0x3731333836396633ull,0x37312e31202a2f20ull,
0x0a3b2f2a20383835ull,0x2074736e6f632e09ull,0x645f43203233662eull,0x3466336630203d20ull,
0x2a2f206534333239ull,0x39363538372e3020ull,0x2e090a3b2f2a2035ull,0x662e2074736e6f63ull,
0x3d20655f43203233ull,0x3861306633663020ull,0x30202a2f20346462ull,0x203639313134352eull,
0x6f632e090a3b2f2aull,0x3233662e2074736eull,0x30203d20665f4320ull,0x6132346438653366ull,
0x322e30202a2f2066ull,0x2f2a203939383537ull,0x736e6f632e090a3bull,0x43203233662e2074ull,
0x203d206d726f6e5full,0x3430356265336630ull,0x2e30202a2f203366ull,0x2a20333535333533ull,
0x6e652e090a0a3b2full,0x34315a5f20797274ull,0x6e72656b41445543ull,0x6650544344316c65ull,
0x09090a2820696969ull,0x2e206d617261702eull,0x75635f5f20343675ull,0x5f5f6d7261706164ull,
0x6b4144554334315aull,0x4344316c656e7265ull,0x445f696969665054ull,0x702e09090a2c7473ull,
0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x72656b4144554334ull,
0x50544344316c656eull,0x676d495f69696966ull,0x090a2c6874646957ull,0x206d617261702e09ull,
0x635f5f203233732eull,0x5f6d726170616475ull,0x4144554334315a5full,0x44316c656e72656bull,
0x5f69696966505443ull,0x425874657366664full,0x090a2c736b636f6cull,0x206d617261702e09ull,
0x635f5f203233732eull,0x5f6d726170616475ull,0x4144554334315a5full,0x44316c656e72656bull,
0x5f69696966505443ull,0x425974657366664full,0x090a29736b636f6cull,0x206765722e090a7bull,
0x3c7225203233752eull,0x722e090a3b3e3032ull,0x203436752e206765ull,0x3b3e32323c647225ull,
0x2e206765722e090aull,0x363c662520323366ull,0x6f6c2e090a3b3e34ull,0x0935380938310963ull,
0x5f3142424c240a30ull,0x4144554334315a5full,0x44316c656e72656bull,0x3a69696966505443ull,
0x36752e766f6d090aull,0x2c31647225092034ull,0x636f6c4272754320ull,0x3b316c61636f4c6bull,
0x7261702e646c090aull,0x09203233752e6d61ull,0x5f5f5b202c317225ull,0x6d72617061647563ull,
0x44554334315a5f5full,0x316c656e72656b41ull,0x6969696650544344ull,0x5874657366664f5full,
0x3b5d736b636f6c42ull,0x33752e747663090aull,0x2509203631752e32ull,0x61746325202c3272ull,
0x61090a3b782e6469ull,0x09203233752e6464ull,0x317225202c337225ull,0x090a3b327225202cull,
0x6d617261702e646cull,0x722509203233752eull,0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,
0x6b4144554334315aull,0x4344316c656e7265ull,0x4f5f696969665054ull,0x6c42597465736666ull,
0x090a3b5d736b636full,0x2e3233752e747663ull,0x3572250920363175ull,0x646961746325202cull,
0x646461090a3b792eull,0x722509203233752eull,0x202c347225202c36ull,0x6873090a3b357225ull,
0x2509203233622e6cull,0x2c337225202c3772ull,0x6c6873090a3b3320ull,0x722509203233622eull,
0x202c367225202c38ull,0x2e747663090a3b33ull,0x203631752e323373ull,0x7425202c39722509ull,
0x61090a3b782e6469ull,0x09203233732e6464ull,0x7225202c30317225ull,0x0a3b397225202c37ull,
0x3233732e74766309ull,0x722509203631752eull,0x64697425202c3131ull,0x646461090a3b792eull,
0x722509203233732eull,0x2c387225202c3231ull,0x090a3b3131722520ull,0x662e6e722e747663ull,
0x09203233732e3233ull,0x317225202c316625ull,0x2e766f6d090a3b30ull,0x3266250920323366ull,
0x303066336630202cull,0x2020203b30303030ull,0x2e30202f2f092020ull,0x662e646461090a35ull,
0x2c33662509203233ull,0x6625202c31662520ull,0x2e747663090a3b32ull,0x732e3233662e6e72ull,
0x2c34662509203233ull,0x090a3b3231722520ull,0x203233662e766f6dull,0x6630202c35662509ull,
0x3030303030306633ull,0x2f0920202020203bull,0x61090a352e30202full,0x09203233662e6464ull,
0x346625202c366625ull,0x090a3b356625202cull,0x203233662e766f6dull,0x6630202c37662509ull,
0x3030303030303030ull,0x2f0920202020203bull,0x766f6d090a30202full,0x662509203233662eull,
0x3030306630202c38ull,0x20203b3030303030ull,0x30202f2f09202020ull,0x64322e786574090aull,
0x2e3233662e34762eull,0x3966257b20323366ull,0x66252c303166252cull,0x7d323166252c3131ull,
0x6372537865545b2cull,0x66252c3366257b2cull,0x66252c3766252c36ull,0x6c2e090a3b5d7d38ull,
0x303109383109636full,0x766f6d090a300930ull,0x662509203233662eull,0x3b396625202c3331ull,
0x33622e6c6873090aull,0x2c33317225092032ull,0x33202c3131722520ull,0x732e646461090a3bull,
0x3431722509203233ull,0x202c33317225202cull,0x7663090a3b397225ull,0x33732e3436732e74ull,
0x2c32647225092032ull,0x090a3b3431722520ull,0x752e6f6c2e6c756dull,0x3364722509203436ull,
0x202c32647225202cull,0x2e646461090a3b34ull,0x6472250920343675ull,0x2c33647225202c34ull,
0x090a3b3164722520ull,0x65726168732e7473ull,0x5b09203233662e64ull,0x2c5d302b34647225ull,
0x090a3b3331662520ull,0x09383109636f6c2eull,0x62090a3009333031ull,0x20636e79732e7261ull,
0x766f6d090a3b3009ull,0x722509203436752eull,0x42727543202c3564ull,0x61636f4c6b636f6cull,
0x766f6d090a3b326cull,0x722509203436752eull,0x76544344202c3664ull,0x3b78697274616d38ull,
0x3109636f6c2e090aull,0x0a30093231310938ull,0x3436732e74766309ull,0x722509203233732eull,
0x3b397225202c3764ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x37647225202c3864ull,
0x6461090a3b34202cull,0x2509203436752e64ull,0x647225202c396472ull,0x3b31647225202c38ull,
0x36732e747663090aull,0x2509203233732e34ull,0x7225202c30316472ull,0x6c756d090a3b3131ull,
0x203436752e6f6c2eull,0x202c313164722509ull,0x34202c3031647225ull,0x752e646461090a3bull,
0x3164722509203436ull,0x2c36647225202c32ull,0x0a3b313164722520ull,0x3233662e766f6d09ull,
0x202c343166250920ull,0x3030303030306630ull,0x09202020203b3030ull,0x646c090a30202f2full,
0x2e6465726168732eull,0x3166250920323366ull,0x396472255b202c35ull,0x646c090a3b5d302bull,
0x662e74736e6f632eull,0x3631662509203233ull,0x32316472255b202cull,0x616d090a3b5d302bull,
0x2509203233662e64ull,0x316625202c373166ull,0x2c36316625202c35ull,0x090a3b3431662520ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c383166ull,0x0a3b5d32332b3964ull,
0x736e6f632e646c09ull,0x2509203233662e74ull,0x72255b202c393166ull,0x3b5d32332b323164ull,
0x33662e64616d090aull,0x2c30326625092032ull,0x25202c3831662520ull,0x316625202c393166ull,
0x732e646c090a3b37ull,0x33662e6465726168ull,0x2c31326625092032ull,0x362b396472255b20ull,
0x2e646c090a3b5d34ull,0x33662e74736e6f63ull,0x2c32326625092032ull,0x2b32316472255b20ull,
0x616d090a3b5d3436ull,0x2509203233662e64ull,0x326625202c333266ull,0x2c32326625202c31ull,
0x090a3b3032662520ull,0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c343266ull,
0x0a3b5d36392b3964ull,0x736e6f632e646c09ull,0x2509203233662e74ull,0x72255b202c353266ull,
0x3b5d36392b323164ull,0x33662e64616d090aull,0x2c36326625092032ull,0x25202c3432662520ull,
0x326625202c353266ull,0x732e646c090a3b33ull,0x33662e6465726168ull,0x2c37326625092032ull,
0x312b396472255b20ull,0x646c090a3b5d3832ull,0x662e74736e6f632eull,0x3832662509203233ull,
0x32316472255b202cull,0x090a3b5d3832312bull,0x203233662e64616dull,0x25202c3932662509ull,
0x326625202c373266ull,0x3b36326625202c38ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3033662509ull,0x3036312b39647225ull,0x632e646c090a3b5dull,0x3233662e74736e6full,
0x202c313366250920ull,0x312b32316472255bull,0x616d090a3b5d3036ull,0x2509203233662e64ull,
0x336625202c323366ull,0x2c31336625202c30ull,0x090a3b3932662520ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c333366ull,0x3b5d3239312b3964ull,0x6e6f632e646c090aull,
0x09203233662e7473ull,0x255b202c34336625ull,0x3239312b32316472ull,0x2e64616d090a3b5dull,
0x3366250920323366ull,0x2c33336625202c35ull,0x25202c3433662520ull,0x646c090a3b323366ull,
0x2e6465726168732eull,0x3366250920323366ull,0x396472255b202c36ull,0x090a3b5d3432322bull,
0x74736e6f632e646cull,0x662509203233662eull,0x6472255b202c3733ull,0x3b5d3432322b3231ull,
0x33662e64616d090aull,0x2c38336625092032ull,0x25202c3633662520ull,0x336625202c373366ull,
0x636f6c2e090a3b35ull,0x0936313109383109ull,0x752e646461090a30ull,0x3164722509203436ull,
0x2c33647225202c33ull,0x090a3b3564722520ull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x5d302b3331647225ull,0x0a3b38336625202cull,0x383109636f6c2e09ull,0x090a300939313109ull,
0x636e79732e726162ull,0x6c2e090a3b300920ull,0x323109383109636full,0x646461090a300938ull,
0x722509203436752eull,0x647225202c343164ull,0x3b36647225202c38ull,0x36732e747663090aull,
0x2509203233732e34ull,0x7225202c35316472ull,0x6c756d090a3b3331ull,0x203436752e6f6c2eull,
0x202c363164722509ull,0x34202c3531647225ull,0x752e646461090a3bull,0x3164722509203436ull,
0x2c35647225202c37ull,0x0a3b363164722520ull,0x3233662e766f6d09ull,0x202c393366250920ull,
0x3030303030306630ull,0x09202020203b3030ull,0x646c090a30202f2full,0x2e6465726168732eull,
0x3466250920323366ull,0x316472255b202c30ull,0x6c090a3b5d302b37ull,0x2e74736e6f632e64ull,
0x3466250920323366ull,0x316472255b202c31ull,0x6d090a3b5d302b34ull,0x09203233662e6461ull,
0x6625202c32346625ull,0x31346625202c3034ull,0x0a3b39336625202cull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c33346625ull,0x3b5d342b37316472ull,0x6e6f632e646c090aull,
0x09203233662e7473ull,0x255b202c34346625ull,0x5d32332b34316472ull,0x662e64616d090a3bull,
0x3534662509203233ull,0x202c33346625202cull,0x6625202c34346625ull,0x2e646c090a3b3234ull,
0x662e646572616873ull,0x3634662509203233ull,0x37316472255b202cull,0x646c090a3b5d382bull,
0x662e74736e6f632eull,0x3734662509203233ull,0x34316472255b202cull,0x6d090a3b5d34362bull,
0x09203233662e6461ull,0x6625202c38346625ull,0x37346625202c3634ull,0x0a3b35346625202cull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c39346625ull,0x5d32312b37316472ull,
0x6f632e646c090a3bull,0x203233662e74736eull,0x5b202c3035662509ull,0x36392b3431647225ull,
0x2e64616d090a3b5dull,0x3566250920323366ull,0x2c39346625202c31ull,0x25202c3035662520ull,
0x646c090a3b383466ull,0x2e6465726168732eull,0x3566250920323366ull,0x316472255b202c32ull,
0x090a3b5d36312b37ull,0x74736e6f632e646cull,0x662509203233662eull,0x6472255b202c3335ull,
0x3b5d3832312b3431ull,0x33662e64616d090aull,0x2c34356625092032ull,0x25202c3235662520ull,
0x356625202c333566ull,0x732e646c090a3b31ull,0x33662e6465726168ull,0x2c35356625092032ull,
0x2b37316472255b20ull,0x646c090a3b5d3032ull,0x662e74736e6f632eull,0x3635662509203233ull,
0x34316472255b202cull,0x090a3b5d3036312bull,0x203233662e64616dull,0x25202c3735662509ull,
0x356625202c353566ull,0x3b34356625202c36ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3835662509ull,0x34322b3731647225ull,0x632e646c090a3b5dull,0x3233662e74736e6full,
0x202c393566250920ull,0x312b34316472255bull,0x616d090a3b5d3239ull,0x2509203233662e64ull,
0x356625202c383366ull,0x2c39356625202c38ull,0x090a3b3735662520ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c303666ull,0x3b5d38322b373164ull,0x6e6f632e646c090aull,
0x09203233662e7473ull,0x255b202c31366625ull,0x3432322b34316472ull,0x2e64616d090a3b5dull,
0x3366250920323366ull,0x2c30366625202c38ull,0x25202c3136662520ull,0x6c2e090a3b383366ull,
0x333109383109636full,0x2e7473090a300932ull,0x662e646572616873ull,0x6472255b09203233ull,
0x6625202c5d302b34ull,0x6f6c2e090a3b3833ull,0x3533310938310963ull,0x2e726162090a3009ull,
0x3b300920636e7973ull,0x3109636f6c2e090aull,0x0a30093833310938ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c32366625ull,0x0a3b5d302b346472ull,0x617261702e646c09ull,
0x2509203233732e6dull,0x5f5f5b202c353172ull,0x6d72617061647563ull,0x44554334315a5f5full,
0x316c656e72656b41ull,0x6969696650544344ull,0x74646957676d495full,0x6c756d090a3b5d68ull,
0x33732e6f6c2e3432ull,0x2c36317225092032ull,0x25202c3231722520ull,0x6461090a3b353172ull,
0x2509203233732e64ull,0x317225202c373172ull,0x3b36317225202c30ull,0x6f6c2e6c756d090aull,
0x722509203233752eull,0x37317225202c3831ull,0x7663090a3b34202cull,0x33752e3436752e74ull,
0x3831647225092032ull,0x0a3b38317225202cull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5f5b202c39316472ull,0x726170616475635full,0x554334315a5f5f6dull,0x6c656e72656b4144ull,
0x6969665054434431ull,0x0a3b5d7473445f69ull,0x3436752e64646109ull,0x2c30326472250920ull,
0x202c383164722520ull,0x090a3b3931647225ull,0x61626f6c672e7473ull,0x5b09203233662e6cull,
0x5d302b3032647225ull,0x0a3b32366625202cull,0x383109636f6c2e09ull,0x090a300939333109ull,
0x4c240a3b74697865ull,0x5a5f5f646e655744ull,0x656b414455433431ull,0x544344316c656e72ull,
0x090a3a6969696650ull,0x315a5f202f2f207dull,0x72656b4144554334ull,0x50544344316c656eull,
0x2e090a0a69696966ull,0x5a5f207972746e65ull,0x656b414455433531ull,0x434449316c656e72ull,
0x2820696969665054ull,0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,
0x554335315a5f5f6dull,0x6c656e72656b4144ull,0x6966505443444931ull,0x0a2c7473445f6969ull,
0x6d617261702e0909ull,0x5f5f203233732e20ull,0x6d72617061647563ull,0x44554335315a5f5full,
0x316c656e72656b41ull,0x6969665054434449ull,0x646957676d495f69ull,0x702e09090a2c6874ull,
0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x72656b4144554335ull,
0x54434449316c656eull,0x664f5f6969696650ull,0x6f6c425874657366ull,0x2e09090a2c736b63ull,
0x732e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,0x656b414455433531ull,
0x434449316c656e72ull,0x4f5f696969665054ull,0x6c42597465736666ull,0x7b090a29736b636full,
0x2e206765722e090aull,0x323c722520323375ull,0x65722e090a3b3e31ull,0x25203436752e2067ull,
0x0a3b3e32323c6472ull,0x662e206765722e09ull,0x33363c6625203233ull,0x636f6c2e090a3b3eull,
0x0934353109383109ull,0x5f3142424c240a30ull,0x4144554335315a5full,0x49316c656e72656bull,
0x6969696650544344ull,0x752e766f6d090a3aull,0x3164722509203436ull,0x6f6c42727543202cull,
0x316c61636f4c6b63ull,0x61702e646c090a3bull,0x203233752e6d6172ull,0x5f5b202c31722509ull,
0x726170616475635full,0x554335315a5f5f6dull,0x6c656e72656b4144ull,0x6966505443444931ull,
0x657366664f5f6969ull,0x736b636f6c425874ull,0x2e747663090a3b5dull,0x203631752e323375ull,
0x6325202c32722509ull,0x0a3b782e64696174ull,0x3233752e64646109ull,0x25202c3372250920ull,
0x3b327225202c3172ull,0x7261702e646c090aull,0x09203233752e6d61ull,0x5f5f5b202c347225ull,
0x6d72617061647563ull,0x44554335315a5f5full,0x316c656e72656b41ull,0x6969665054434449ull,
0x74657366664f5f69ull,0x5d736b636f6c4259ull,0x752e747663090a3bull,0x09203631752e3233ull,
0x746325202c357225ull,0x090a3b792e646961ull,0x203233752e646461ull,0x7225202c36722509ull,
0x0a3b357225202c34ull,0x3233622e6c687309ull,0x25202c3772250920ull,0x090a3b33202c3372ull,
0x203233622e6c6873ull,0x7225202c38722509ull,0x63090a3b33202c36ull,0x752e3233732e7476ull,
0x2c39722509203631ull,0x3b782e6469742520ull,0x33732e646461090aull,0x2c30317225092032ull,
0x7225202c37722520ull,0x2e747663090a3b39ull,0x203631752e323373ull,0x25202c3131722509ull,
0x090a3b792e646974ull,0x203233732e646461ull,0x25202c3231722509ull,0x31317225202c3872ull,
0x722e747663090a3bull,0x33732e3233662e6eull,0x202c316625092032ull,0x6d090a3b30317225ull,
0x09203233662e766full,0x336630202c326625ull,0x3b30303030303066ull,0x2f2f092020202020ull,
0x6461090a352e3020ull,0x2509203233662e64ull,0x2c316625202c3366ull,0x63090a3b32662520ull,
0x33662e6e722e7476ull,0x2509203233732e32ull,0x32317225202c3466ull,0x662e766f6d090a3bull,
0x2c35662509203233ull,0x3030306633663020ull,0x202020203b303030ull,0x352e30202f2f0920ull,
0x33662e646461090aull,0x202c366625092032ull,0x356625202c346625ull,0x662e766f6d090a3bull,
0x2c37662509203233ull,0x3030303030663020ull,0x202020203b303030ull,0x090a30202f2f0920ull,
0x203233662e766f6dull,0x6630202c38662509ull,0x3030303030303030ull,0x2f0920202020203bull,
0x786574090a30202full,0x662e34762e64322eull,0x7b203233662e3233ull,0x303166252c396625ull,
0x66252c313166252cull,0x7865545b2c7d3231ull,0x3366257b2c637253ull,0x3766252c3666252cull,
0x0a3b5d7d3866252cull,0x383109636f6c2e09ull,0x090a300939363109ull,0x203233662e766f6dull,
0x25202c3331662509ull,0x6c6873090a3b3966ull,0x722509203233622eull,0x31317225202c3331ull,
0x6461090a3b33202cull,0x2509203233732e64ull,0x317225202c343172ull,0x0a3b397225202c33ull,
0x3436732e74766309ull,0x722509203233732eull,0x34317225202c3264ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x647225202c336472ull,0x61090a3b34202c32ull,0x09203436752e6464ull,
0x7225202c34647225ull,0x31647225202c3364ull,0x68732e7473090a3bull,0x3233662e64657261ull,
0x2b346472255b0920ull,0x33316625202c5d30ull,0x09636f6c2e090a3bull,0x3009323731093831ull,
0x79732e726162090aull,0x090a3b300920636eull,0x203436752e766f6dull,0x43202c3564722509ull,
0x4c6b636f6c427275ull,0x090a3b326c61636full,0x203436752e766f6dull,0x44202c3664722509ull,
0x7274616d38765443ull,0x6f6c2e090a3b7869ull,0x3138310938310963ull,0x2e747663090a3009ull,
0x203233732e343673ull,0x25202c3764722509ull,0x756d090a3b333172ull,0x3436752e6f6c2e6cull,
0x202c386472250920ull,0x3b34202c37647225ull,0x36732e747663090aull,0x2509203233732e34ull,
0x397225202c396472ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c30316472ull,
0x090a3b34202c3964ull,0x203436752e646461ull,0x202c313164722509ull,0x7225202c31647225ull,
0x6461090a3b303164ull,0x2509203436752e64ull,0x7225202c32316472ull,0x36647225202c3864ull,
0x662e766f6d090a3bull,0x3431662509203233ull,0x303030306630202cull,0x2020203b30303030ull,
0x090a30202f2f0920ull,0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c353166ull,
0x0a3b5d302b313164ull,0x736e6f632e646c09ull,0x2509203233662e74ull,0x72255b202c363166ull,
0x0a3b5d302b323164ull,0x3233662e64616d09ull,0x202c373166250920ull,0x6625202c35316625ull,
0x34316625202c3631ull,0x68732e646c090a3bull,0x3233662e64657261ull,0x202c383166250920ull,
0x332b31316472255bull,0x2e646c090a3b5d32ull,0x33662e74736e6f63ull,0x2c39316625092032ull,
0x2b32316472255b20ull,0x64616d090a3b5d34ull,0x662509203233662eull,0x38316625202c3032ull,
0x202c39316625202cull,0x6c090a3b37316625ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3132ull,0x0a3b5d34362b3131ull,0x736e6f632e646c09ull,0x2509203233662e74ull,
0x72255b202c323266ull,0x0a3b5d382b323164ull,0x3233662e64616d09ull,0x202c333266250920ull,
0x6625202c31326625ull,0x30326625202c3232ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x202c343266250920ull,0x392b31316472255bull,0x2e646c090a3b5d36ull,0x33662e74736e6f63ull,
0x2c35326625092032ull,0x2b32316472255b20ull,0x616d090a3b5d3231ull,0x2509203233662e64ull,
0x326625202c363266ull,0x2c35326625202c34ull,0x090a3b3332662520ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c373266ull,0x5d3832312b313164ull,0x6f632e646c090a3bull,
0x203233662e74736eull,0x5b202c3832662509ull,0x36312b3231647225ull,0x2e64616d090a3b5dull,
0x3266250920323366ull,0x2c37326625202c39ull,0x25202c3832662520ull,0x646c090a3b363266ull,
0x2e6465726168732eull,0x3366250920323366ull,0x316472255b202c30ull,0x0a3b5d3036312b31ull,
0x736e6f632e646c09ull,0x2509203233662e74ull,0x72255b202c313366ull,0x3b5d30322b323164ull,
0x33662e64616d090aull,0x2c32336625092032ull,0x25202c3033662520ull,0x326625202c313366ull,
0x732e646c090a3b39ull,0x33662e6465726168ull,0x2c33336625092032ull,0x2b31316472255b20ull,
0x6c090a3b5d323931ull,0x2e74736e6f632e64ull,0x3366250920323366ull,0x316472255b202c34ull,
0x090a3b5d34322b32ull,0x203233662e64616dull,0x25202c3533662509ull,0x336625202c333366ull,
0x3b32336625202c34ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3633662509ull,
0x32322b3131647225ull,0x2e646c090a3b5d34ull,0x33662e74736e6f63ull,0x2c37336625092032ull,
0x2b32316472255b20ull,0x616d090a3b5d3832ull,0x2509203233662e64ull,0x336625202c353366ull,
0x2c37336625202c36ull,0x090a3b3533662520ull,0x09383109636f6c2eull,0x61090a3009353831ull,
0x09203436752e6464ull,0x25202c3331647225ull,0x647225202c336472ull,0x732e7473090a3b35ull,
0x33662e6465726168ull,0x316472255b092032ull,0x6625202c5d302b33ull,0x6f6c2e090a3b3533ull,
0x3838310938310963ull,0x2e726162090a3009ull,0x3b300920636e7973ull,0x3109636f6c2e090aull,
0x0a30093739310938ull,0x3436752e64646109ull,0x2c34316472250920ull,0x25202c3864722520ull,
0x6873090a3b356472ull,0x2509203233622e6cull,0x397225202c353172ull,0x7663090a3b33202cull,
0x33732e3436732e74ull,0x3531647225092032ull,0x0a3b35317225202cull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x31647225202c3631ull,0x61090a3b34202c35ull,0x09203436752e6464ull,
0x25202c3731647225ull,0x647225202c366472ull,0x766f6d090a3b3631ull,0x662509203233662eull,
0x30306630202c3833ull,0x203b303030303030ull,0x30202f2f09202020ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3933662509ull,0x5d302b3431647225ull,0x6f632e646c090a3bull,
0x203233662e74736eull,0x5b202c3034662509ull,0x5d302b3731647225ull,0x662e64616d090a3bull,
0x3134662509203233ull,0x202c39336625202cull,0x6625202c30346625ull,0x2e646c090a3b3833ull,
0x662e646572616873ull,0x3234662509203233ull,0x34316472255b202cull,0x646c090a3b5d342bull,
0x662e74736e6f632eull,0x3334662509203233ull,0x37316472255b202cull,0x616d090a3b5d342bull,
0x2509203233662e64ull,0x346625202c343466ull,0x2c33346625202c32ull,0x090a3b3134662520ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c353466ull,0x0a3b5d382b343164ull,
0x736e6f632e646c09ull,0x2509203233662e74ull,0x72255b202c363466ull,0x0a3b5d382b373164ull,
0x3233662e64616d09ull,0x202c373466250920ull,0x6625202c35346625ull,0x34346625202c3634ull,
0x68732e646c090a3bull,0x3233662e64657261ull,0x202c383466250920ull,0x312b34316472255bull,
0x2e646c090a3b5d32ull,0x33662e74736e6f63ull,0x2c39346625092032ull,0x2b37316472255b20ull,
0x616d090a3b5d3231ull,0x2509203233662e64ull,0x346625202c303566ull,0x2c39346625202c38ull,
0x090a3b3734662520ull,0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c313566ull,
0x3b5d36312b343164ull,0x6e6f632e646c090aull,0x09203233662e7473ull,0x255b202c32356625ull,
0x5d36312b37316472ull,0x662e64616d090a3bull,0x3335662509203233ull,0x202c31356625202cull,
0x6625202c32356625ull,0x2e646c090a3b3035ull,0x662e646572616873ull,0x3435662509203233ull,
0x34316472255b202cull,0x6c090a3b5d30322bull,0x2e74736e6f632e64ull,0x3566250920323366ull,
0x316472255b202c35ull,0x090a3b5d30322b37ull,0x203233662e64616dull,0x25202c3635662509ull,
0x356625202c343566ull,0x3b33356625202c35ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3735662509ull,0x34322b3431647225ull,0x632e646c090a3b5dull,0x3233662e74736e6full,
0x202c383566250920ull,0x322b37316472255bull,0x64616d090a3b5d34ull,0x662509203233662eull,
0x37356625202c3533ull,0x202c38356625202cull,0x6c090a3b36356625ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3935ull,0x0a3b5d38322b3431ull,0x736e6f632e646c09ull,
0x2509203233662e74ull,0x72255b202c303666ull,0x3b5d38322b373164ull,0x33662e64616d090aull,
0x2c35336625092032ull,0x25202c3935662520ull,0x336625202c303666ull,0x636f6c2e090a3b35ull,
0x0931303209383109ull,0x68732e7473090a30ull,0x3233662e64657261ull,0x2b346472255b0920ull,
0x35336625202c5d30ull,0x09636f6c2e090a3bull,0x3009343032093831ull,0x79732e726162090aull,
0x090a3b300920636eull,0x09383109636f6c2eull,0x6c090a3009373032ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3136ull,0x6c090a3b5d302b34ull,0x2e6d617261702e64ull,
0x3172250920323373ull,0x75635f5f5b202c36ull,0x5f5f6d7261706164ull,0x6b4144554335315aull,
0x4449316c656e7265ull,0x5f69696966505443ull,0x6874646957676d49ull,0x326c756d090a3b5dull,
0x3233732e6f6c2e34ull,0x202c373172250920ull,0x7225202c32317225ull,0x646461090a3b3631ull,
0x722509203233732eull,0x30317225202c3831ull,0x0a3b37317225202cull,0x2e6f6c2e6c756d09ull,
0x3172250920323375ull,0x2c38317225202c39ull,0x747663090a3b3420ull,0x3233752e3436752eull,
0x2c38316472250920ull,0x090a3b3931722520ull,0x6d617261702e646cull,0x722509203436752eull,
0x5f5f5b202c393164ull,0x6d72617061647563ull,0x44554335315a5f5full,0x316c656e72656b41ull,
0x6969665054434449ull,0x0a3b5d7473445f69ull,0x3436752e64646109ull,0x2c30326472250920ull,
0x202c383164722520ull,0x090a3b3931647225ull,0x61626f6c672e7473ull,0x5b09203233662e6cull,
0x5d302b3032647225ull,0x0a3b31366625202cull,0x383109636f6c2e09ull,0x090a300938303209ull,
0x4c240a3b74697865ull,0x5a5f5f646e655744ull,0x656b414455433531ull,0x434449316c656e72ull,
0x0a3a696969665054ull,0x5a5f202f2f207d09ull,0x656b414455433531ull,0x434449316c656e72ull,
0x0a0a696969665054ull,0x207972746e652e09ull,0x4144554334315a5full,0x44326c656e72656bull,
0x0a28206966505443ull,0x6d617261702e0909ull,0x5f5f203436752e20ull,0x6d72617061647563ull,
0x44554334315a5f5full,0x326c656e72656b41ull,0x5f5f696650544344ull,0x7261705f6c61765full,
0x7473446372536d61ull,0x7261702e09090a2cull,0x203233732e206d61ull,0x6170616475635f5full,
0x4334315a5f5f6d72ull,0x656e72656b414455ull,0x696650544344326cull,0x69727453676d495full,
0x090a7b090a296564ull,0x33752e206765722eull,0x3e31333c72252032ull,0x206765722e090a3bull,
0x647225203436752eull,0x2e090a3b3e33323cull,0x3233662e20676572ull,0x3e3332313c662520ull,
0x726168732e090a3bull,0x67696c612e206465ull,0x2038622e2034206eull,0x625f616475635f5full,
0x5b3237356b636f6cull,0x090a3b5d32313132ull,0x09373109636f6c2eull,0x4c240a3009343032ull,
0x34315a5f5f314242ull,0x6e72656b41445543ull,0x6650544344326c65ull,0x2e766f6d090a3a69ull,
0x6472250920343675ull,0x6475635f5f202c31ull,0x356b636f6c625f61ull,0x6f6c2e090a3b3237ull,
0x3833320937310963ull,0x2e747663090a3009ull,0x203631752e323373ull,0x6325202c31722509ull,
0x0a3b792e64696174ull,0x3233622e6c687309ull,0x25202c3272250920ull,0x090a3b34202c3172ull,
0x2e3233732e747663ull,0x3372250920363175ull,0x7a2e64697425202cull,0x622e6c6873090a3bull,
0x2c34722509203233ull,0x3b33202c33722520ull,0x33732e747663090aull,0x2509203631752e32ull,
0x61746325202c3572ull,0x73090a3b782e6469ull,0x09203233622e6c68ull,0x357225202c367225ull,
0x7663090a3b35202cull,0x31752e3233732e74ull,0x202c377225092036ull,0x0a3b792e64697425ull,
0x3233622e6c687309ull,0x25202c3872250920ull,0x090a3b33202c3772ull,0x203233732e646461ull,
0x7225202c39722509ull,0x0a3b347225202c32ull,0x3233732e766f6d09ull,0x202c303172250920ull,
0x6c756d090a3b3333ull,0x33732e6f6c2e3432ull,0x2c31317225092032ull,0x7225202c34722520ull,
0x747663090a3b3031ull,0x3631752e3233752eull,0x202c323172250920ull,0x0a3b782e64697425ull,
0x3233752e64646109ull,0x202c333172250920ull,0x317225202c387225ull,0x702e646c090a3b32ull,
0x3233732e6d617261ull,0x202c343172250920ull,0x70616475635f5f5bull,0x34315a5f5f6d7261ull,
0x6e72656b41445543ull,0x6650544344326c65ull,0x727453676d495f69ull,0x6d090a3b5d656469ull,
0x2e6f6c2e34326c75ull,0x3172250920323373ull,0x202c397225202c35ull,0x61090a3b34317225ull,
0x09203233732e6464ull,0x7225202c36317225ull,0x33317225202c3131ull,0x732e646461090a3bull,
0x3731722509203233ull,0x25202c367225202cull,0x6461090a3b353172ull,0x2509203233732e64ull,
0x317225202c383172ull,0x3b33317225202c37ull,0x6f6c2e6c756d090aull,0x722509203233752eull,
0x36317225202c3931ull,0x7663090a3b34202cull,0x33752e3436752e74ull,0x2c32647225092032ull,
0x090a3b3931722520ull,0x203436752e646461ull,0x25202c3364722509ull,0x647225202c326472ull,
0x2e6c756d090a3b31ull,0x09203233752e6f6cull,0x7225202c30327225ull,0x090a3b34202c3831ull,
0x2e3436752e747663ull,0x6472250920323375ull,0x3b30327225202c34ull,0x7261702e646c090aull,
0x09203436752e6d61ull,0x5f5b202c35647225ull,0x726170616475635full,0x554334315a5f5f6dull,
0x6c656e72656b4144ull,0x5f69665054434432ull,0x61705f6c61765f5full,0x73446372536d6172ull,
0x646461090a3b5d74ull,0x722509203436752eull,0x34647225202c3664ull,0x0a3b35647225202cull,
0x626f6c672e646c09ull,0x09203233662e6c61ull,0x72255b202c316625ull,0x090a3b5d302b3664ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x2c5d302b33647225ull,0x2e090a3b31662520ull,
0x3209373109636f6cull,0x756d090a30093234ull,0x3233752e6f6c2e6cull,0x202c313272250920ull,
0x3b34202c34317225ull,0x36752e747663090aull,0x2509203233752e34ull,0x327225202c376472ull,
0x2e646461090a3b31ull,0x6472250920343675ull,0x2c37647225202c38ull,0x090a3b3664722520ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x6472255b202c3266ull,0x73090a3b5d302b38ull,
0x6465726168732e74ull,0x255b09203233662eull,0x5d3233312b336472ull,0x090a3b326625202cull,
0x09373109636f6c2eull,0x61090a3009363432ull,0x09203436752e6464ull,0x7225202c39647225ull,
0x38647225202c3764ull,0x6c672e646c090a3bull,0x3233662e6c61626full,0x5b202c3366250920ull,
0x3b5d302b39647225ull,0x6168732e7473090aull,0x203233662e646572ull,0x322b336472255b09ull,
0x336625202c5d3436ull,0x09636f6c2e090a3bull,0x3009373432093731ull,0x36752e646461090aull,
0x3031647225092034ull,0x202c37647225202cull,0x2e090a3b39647225ull,0x3209373109636f6cull,
0x646c090a30093035ull,0x2e6c61626f6c672eull,0x3466250920323366ull,0x30316472255b202cull,
0x7473090a3b5d302bull,0x2e6465726168732eull,0x72255b0920323366ull,0x2c5d3639332b3364ull,
0x2e090a3b34662520ull,0x3209373109636f6cull,0x6461090a30093135ull,0x2509203436752e64ull,
0x7225202c30316472ull,0x31647225202c3764ull,0x636f6c2e090a3b30ull,0x0934353209373109ull,
0x6c672e646c090a30ull,0x3233662e6c61626full,0x5b202c3566250920ull,0x5d302b3031647225ull,
0x68732e7473090a3bull,0x3233662e64657261ull,0x2b336472255b0920ull,0x6625202c5d383235ull,
0x636f6c2e090a3b35ull,0x0935353209373109ull,0x752e646461090a30ull,0x3164722509203436ull,
0x2c37647225202c30ull,0x0a3b303164722520ull,0x373109636f6c2e09ull,0x090a300938353209ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x6472255b202c3666ull,0x090a3b5d302b3031ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x3036362b33647225ull,0x0a3b366625202c5dull,
0x373109636f6c2e09ull,0x090a300939353209ull,0x203436752e646461ull,0x202c303164722509ull,
0x7225202c37647225ull,0x6c2e090a3b303164ull,0x363209373109636full,0x2e646c090a300932ull,
0x662e6c61626f6c67ull,0x2c37662509203233ull,0x2b30316472255b20ull,0x2e7473090a3b5d30ull,
0x662e646572616873ull,0x6472255b09203233ull,0x202c5d3239372b33ull,0x6c2e090a3b376625ull,
0x363209373109636full,0x646461090a300933ull,0x722509203436752eull,0x647225202c303164ull,
0x3031647225202c37ull,0x09636f6c2e090a3bull,0x3009363632093731ull,0x6f6c672e646c090aull,
0x203233662e6c6162ull,0x255b202c38662509ull,0x3b5d302b30316472ull,0x6168732e7473090aull,
0x203233662e646572ull,0x392b336472255b09ull,0x386625202c5d3432ull,0x09636f6c2e090a3bull,
0x3009393632093731ull,0x79732e726162090aull,0x090a3b300920636eull,0x09373109636f6c2eull,
0x6d090a3009373131ull,0x33752e6f6c2e6c75ull,0x2c32327225092032ull,0x34202c3331722520ull,
0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3131647225ull,0x756d090a3b323272ull,
0x3233752e6f6c2e6cull,0x202c333272250920ull,0x323331202c347225ull,0x752e747663090a3bull,
0x09203233752e3436ull,0x25202c3231647225ull,0x6461090a3b333272ull,0x2509203436752e64ull,
0x7225202c33316472ull,0x647225202c323164ull,0x646461090a3b3131ull,0x722509203436752eull,
0x647225202c343164ull,0x3331647225202c31ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x5b202c3966250920ull,0x5d302b3431647225ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x202c303166250920ull,0x392b34316472255bull,0x6461090a3b5d3432ull,0x2509203233662e64ull,
0x396625202c313166ull,0x0a3b30316625202cull,0x373109636f6c2e09ull,0x090a300938313109ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c323166ull,0x5d3233312b343164ull,
0x68732e646c090a3bull,0x3233662e64657261ull,0x202c333166250920ull,0x372b34316472255bull,
0x6461090a3b5d3239ull,0x2509203233662e64ull,0x316625202c343166ull,0x3b33316625202c32ull,
0x3109636f6c2e090aull,0x0a30093931310937ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c35316625ull,0x3436322b34316472ull,0x732e646c090a3b5dull,0x33662e6465726168ull,
0x2c36316625092032ull,0x2b34316472255b20ull,0x61090a3b5d303636ull,0x09203233662e6464ull,
0x6625202c37316625ull,0x36316625202c3531ull,0x09636f6c2e090a3bull,0x3009303231093731ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3831662509ull,0x39332b3431647225ull,
0x2e646c090a3b5d36ull,0x662e646572616873ull,0x3931662509203233ull,0x34316472255b202cull,
0x090a3b5d3832352bull,0x203233662e646461ull,0x25202c3032662509ull,0x316625202c383166ull,
0x636f6c2e090a3b39ull,0x0932323109373109ull,0x662e627573090a30ull,0x3132662509203233ull,
0x25202c396625202cull,0x6c2e090a3b303166ull,0x323109373109636full,0x627573090a300933ull,
0x662509203233662eull,0x33316625202c3232ull,0x0a3b32316625202cull,0x373109636f6c2e09ull,
0x090a300934323109ull,0x203233662e627573ull,0x25202c3332662509ull,0x316625202c353166ull,
0x636f6c2e090a3b36ull,0x0935323109373109ull,0x662e627573090a30ull,0x3432662509203233ull,
0x202c39316625202cull,0x2e090a3b38316625ull,0x3109373109636f6cull,0x6461090a30093233ull,
0x2509203233662e64ull,0x316625202c353266ull,0x3b30326625202c31ull,0x33662e646461090aull,
0x2c36326625092032ull,0x25202c3431662520ull,0x646c090a3b373166ull,0x662e74736e6f632eull,
0x3732662509203233ull,0x726f6e5f435b202cull,0x646461090a3b5d6dull,0x662509203233662eull,
0x35326625202c3832ull,0x0a3b36326625202cull,0x3233662e6c756d09ull,0x202c393266250920ull,
0x6625202c37326625ull,0x2e7473090a3b3832ull,0x662e646572616873ull,0x6472255b09203233ull,
0x25202c5d302b3431ull,0x6c2e090a3b393266ull,0x333109373109636full,0x627573090a300933ull,
0x662509203233662eull,0x34316625202c3033ull,0x0a3b37316625202cull,0x3233662e62757309ull,
0x202c313366250920ull,0x6625202c31316625ull,0x2e646c090a3b3032ull,0x33662e74736e6f63ull,
0x2c32336625092032ull,0x0a3b5d625f435b20ull,0x736e6f632e646c09ull,0x2509203233662e74ull,
0x5f435b202c333366ull,0x6c756d090a3b5d65ull,0x662509203233662eull,0x30336625202c3433ull,
0x0a3b33336625202cull,0x3233662e64616d09ull,0x202c353366250920ull,0x6625202c32336625ull,
0x34336625202c3133ull,0x662e6c756d090a3bull,0x3633662509203233ull,0x202c37326625202cull,
0x73090a3b35336625ull,0x6465726168732e74ull,0x255b09203233662eull,0x3436322b34316472ull,
0x3b36336625202c5dull,0x3109636f6c2e090aull,0x0a30093433310937ull,0x3233662e62757309ull,
0x202c373366250920ull,0x6625202c35326625ull,0x6c756d090a3b3632ull,0x662509203233662eull,
0x37326625202c3833ull,0x0a3b37336625202cull,0x726168732e747309ull,0x09203233662e6465ull,
0x352b34316472255bull,0x336625202c5d3832ull,0x636f6c2e090a3b38ull,0x0935333109373109ull,
0x662e6c756d090a30ull,0x3933662509203233ull,0x202c30336625202cull,0x6d090a3b32336625ull,
0x09203233662e6c75ull,0x6625202c30346625ull,0x31336625202c3333ull,0x662e627573090a3bull,
0x3134662509203233ull,0x202c30346625202cull,0x6d090a3b39336625ull,0x09203233662e6c75ull,
0x6625202c32346625ull,0x31346625202c3732ull,0x68732e7473090a3bull,0x3233662e64657261ull,
0x34316472255b0920ull,0x25202c5d3239372bull,0x6c2e090a3b323466ull,0x333109373109636full,
0x2e646c090a300937ull,0x33662e74736e6f63ull,0x2c33346625092032ull,0x0a3b5d665f435b20ull,
0x736e6f632e646c09ull,0x2509203233662e74ull,0x5f435b202c343466ull,0x2e646c090a3b5d64ull,
0x33662e74736e6f63ull,0x2c35346625092032ull,0x0a3b5d615f435b20ull,0x736e6f632e646c09ull,
0x2509203233662e74ull,0x5f435b202c363466ull,0x6c756d090a3b5d63ull,0x662509203233662eull,
0x32326625202c3734ull,0x0a3b36346625202cull,0x3233662e6c756d09ull,0x202c383466250920ull,
0x6625202c35346625ull,0x627573090a3b3132ull,0x662509203233662eull,0x38346625202c3934ull,
0x0a3b37346625202cull,0x3233662e64616d09ull,0x202c303566250920ull,0x6625202c34346625ull,
0x39346625202c3332ull,0x662e6c756d090a3bull,0x3135662509203233ull,0x202c33346625202cull,
0x73090a3b34326625ull,0x09203233662e6275ull,0x6625202c32356625ull,0x31356625202c3035ull,
0x662e6c756d090a3bull,0x3335662509203233ull,0x202c37326625202cull,0x73090a3b32356625ull,
0x6465726168732e74ull,0x255b09203233662eull,0x3233312b34316472ull,0x3b33356625202c5dull,
0x3109636f6c2e090aull,0x0a30093833310937ull,0x3233662e6c756d09ull,0x202c343566250920ull,
0x6625202c32326625ull,0x64616d090a3b3334ull,0x662509203233662eull,0x36346625202c3535ull,
0x202c31326625202cull,0x6d090a3b34356625ull,0x09203233662e6c75ull,0x6625202c36356625ull,
0x33326625202c3534ull,0x662e627573090a3bull,0x3735662509203233ull,0x202c35356625202cull,
0x6d090a3b36356625ull,0x09203233662e6461ull,0x6625202c38356625ull,0x34326625202c3434ull,
0x0a3b37356625202cull,0x3233662e6c756d09ull,0x202c393566250920ull,0x6625202c37326625ull,
0x2e7473090a3b3835ull,0x662e646572616873ull,0x6472255b09203233ull,0x2c5d3639332b3431ull,
0x090a3b3935662520ull,0x09373109636f6c2eull,0x6d090a3009393331ull,0x09203233662e6c75ull,
0x6625202c30366625ull,0x34346625202c3132ull,0x662e64616d090a3bull,0x3136662509203233ull,
0x202c35346625202cull,0x6625202c32326625ull,0x64616d090a3b3036ull,0x662509203233662eull,
0x33346625202c3236ull,0x202c33326625202cull,0x6d090a3b31366625ull,0x09203233662e6c75ull,
0x6625202c33366625ull,0x34326625202c3634ull,0x662e627573090a3bull,0x3436662509203233ull,
0x202c32366625202cull,0x6d090a3b33366625ull,0x09203233662e6c75ull,0x6625202c35366625ull,
0x34366625202c3732ull,0x68732e7473090a3bull,0x3233662e64657261ull,0x34316472255b0920ull,
0x25202c5d3036362bull,0x6c2e090a3b353666ull,0x343109373109636full,0x6c756d090a300930ull,
0x662509203233662eull,0x31326625202c3636ull,0x0a3b33346625202cull,0x3233662e64616d09ull,
0x202c373666250920ull,0x6625202c34346625ull,0x36366625202c3232ull,0x662e64616d090a3bull,
0x3836662509203233ull,0x202c36346625202cull,0x6625202c33326625ull,0x64616d090a3b3736ull,
0x662509203233662eull,0x35346625202c3936ull,0x202c34326625202cull,0x6d090a3b38366625ull,
0x09203233662e6c75ull,0x6625202c30376625ull,0x39366625202c3732ull,0x68732e7473090a3bull,
0x3233662e64657261ull,0x34316472255b0920ull,0x25202c5d3432392bull,0x6c2e090a3b303766ull,
0x373209373109636full,0x726162090a300936ull,0x300920636e79732eull,0x09636f6c2e090a3bull,
0x3009373131093731ull,0x33752e646461090aull,0x2c34327225092032ull,0x7225202c34722520ull,
0x6c756d090a3b3231ull,0x203233752e6f6c2eull,0x25202c3532722509ull,0x323331202c343272ull,
0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3531647225ull,0x6461090a3b353272ull,
0x2509203436752e64ull,0x7225202c36316472ull,0x647225202c353164ull,0x6c756d090a3b3131ull,
0x33752e6f6c2e3432ull,0x2c36327225092032ull,0x34202c3231722520ull,0x752e747663090a3bull,
0x09203233752e3436ull,0x25202c3731647225ull,0x7573090a3b363272ull,0x2509203436752e62ull,
0x7225202c38316472ull,0x647225202c363164ull,0x646461090a3b3731ull,0x722509203436752eull,
0x647225202c393164ull,0x3831647225202c31ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x202c313766250920ull,0x302b39316472255bull,0x732e646c090a3b5dull,0x33662e6465726168ull,
0x2c32376625092032ull,0x2b39316472255b20ull,0x6461090a3b5d3832ull,0x2509203233662e64ull,
0x376625202c313166ull,0x3b32376625202c31ull,0x3109636f6c2e090aull,0x0a30093831310937ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c33376625ull,0x3b5d342b39316472ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3437662509ull,0x34322b3931647225ull,
0x2e646461090a3b5dull,0x3166250920323366ull,0x2c33376625202c34ull,0x090a3b3437662520ull,
0x09373109636f6c2eull,0x6c090a3009393131ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3537ull,0x090a3b5d382b3931ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c363766ull,0x3b5d30322b393164ull,0x33662e646461090aull,0x2c37316625092032ull,
0x25202c3537662520ull,0x6c2e090a3b363766ull,0x323109373109636full,0x2e646c090a300930ull,
0x662e646572616873ull,0x3737662509203233ull,0x39316472255b202cull,0x6c090a3b5d32312bull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3837ull,0x0a3b5d36312b3931ull,
0x3233662e64646109ull,0x202c303266250920ull,0x6625202c37376625ull,0x6f6c2e090a3b3837ull,
0x3232310937310963ull,0x2e627573090a3009ull,0x3266250920323366ull,0x2c31376625202c31ull,
0x090a3b3237662520ull,0x09373109636f6c2eull,0x73090a3009333231ull,0x09203233662e6275ull,
0x6625202c32326625ull,0x33376625202c3437ull,0x09636f6c2e090a3bull,0x3009343231093731ull,
0x33662e627573090aull,0x2c33326625092032ull,0x25202c3537662520ull,0x6c2e090a3b363766ull,
0x323109373109636full,0x627573090a300935ull,0x662509203233662eull,0x38376625202c3432ull,
0x0a3b37376625202cull,0x373109636f6c2e09ull,0x090a300932333109ull,0x203233662e646461ull,
0x25202c3532662509ull,0x326625202c313166ull,0x2e646461090a3b30ull,0x3266250920323366ull,
0x2c34316625202c36ull,0x090a3b3731662520ull,0x203233662e646461ull,0x25202c3937662509ull,
0x326625202c353266ull,0x2e6c756d090a3b36ull,0x3866250920323366ull,0x2c37326625202c30ull,
0x090a3b3937662520ull,0x65726168732e7473ull,0x5b09203233662e64ull,0x5d302b3931647225ull,
0x0a3b30386625202cull,0x373109636f6c2e09ull,0x090a300933333109ull,0x203233662e627573ull,
0x25202c3033662509ull,0x316625202c343166ull,0x2e627573090a3b37ull,0x3366250920323366ull,
0x2c31316625202c31ull,0x090a3b3032662520ull,0x203233662e6c756dull,0x25202c3138662509ull,
0x336625202c303366ull,0x2e64616d090a3b33ull,0x3866250920323366ull,0x2c32336625202c32ull,
0x25202c3133662520ull,0x756d090a3b313866ull,0x2509203233662e6cull,0x326625202c333866ull,
0x3b32386625202c37ull,0x6168732e7473090aull,0x203233662e646572ull,0x2b39316472255b09ull,
0x33386625202c5d38ull,0x09636f6c2e090a3bull,0x3009343331093731ull,0x33662e627573090aull,
0x2c34386625092032ull,0x25202c3532662520ull,0x756d090a3b363266ull,0x2509203233662e6cull,
0x326625202c353866ull,0x3b34386625202c37ull,0x6168732e7473090aull,0x203233662e646572ull,
0x2b39316472255b09ull,0x386625202c5d3631ull,0x636f6c2e090a3b35ull,0x0935333109373109ull,
0x662e6c756d090a30ull,0x3638662509203233ull,0x202c30336625202cull,0x6d090a3b32336625ull,
0x09203233662e6c75ull,0x6625202c37386625ull,0x31336625202c3333ull,0x662e627573090a3bull,
0x3838662509203233ull,0x202c37386625202cull,0x6d090a3b36386625ull,0x09203233662e6c75ull,
0x6625202c39386625ull,0x38386625202c3732ull,0x68732e7473090a3bull,0x3233662e64657261ull,
0x39316472255b0920ull,0x6625202c5d34322bull,0x6f6c2e090a3b3938ull,0x3733310937310963ull,
0x2e6c756d090a3009ull,0x3966250920323366ull,0x2c32326625202c30ull,0x090a3b3634662520ull,
0x203233662e6c756dull,0x25202c3139662509ull,0x326625202c353466ull,0x2e627573090a3b31ull,
0x3966250920323366ull,0x2c31396625202c32ull,0x090a3b3039662520ull,0x203233662e64616dull,
0x25202c3339662509ull,0x326625202c343466ull,0x3b32396625202c33ull,0x33662e6c756d090aull,
0x2c34396625092032ull,0x25202c3334662520ull,0x7573090a3b343266ull,0x2509203233662e62ull,
0x396625202c353966ull,0x3b34396625202c33ull,0x33662e6c756d090aull,0x2c36396625092032ull,
0x25202c3732662520ull,0x7473090a3b353966ull,0x2e6465726168732eull,0x72255b0920323366ull,
0x202c5d342b393164ull,0x2e090a3b36396625ull,0x3109373109636f6cull,0x756d090a30093833ull,
0x2509203233662e6cull,0x326625202c373966ull,0x3b33346625202c32ull,0x33662e64616d090aull,
0x2c38396625092032ull,0x25202c3634662520ull,0x396625202c313266ull,0x2e6c756d090a3b37ull,
0x3966250920323366ull,0x2c35346625202c39ull,0x090a3b3332662520ull,0x203233662e627573ull,
0x202c303031662509ull,0x6625202c38396625ull,0x64616d090a3b3939ull,0x662509203233662eull,
0x346625202c313031ull,0x2c34326625202c34ull,0x0a3b303031662520ull,0x3233662e6c756d09ull,
0x2c32303166250920ull,0x25202c3732662520ull,0x73090a3b31303166ull,0x6465726168732e74ull,
0x255b09203233662eull,0x5d32312b39316472ull,0x3b3230316625202cull,0x3109636f6c2e090aull,
0x0a30093933310937ull,0x3233662e6c756d09ull,0x2c33303166250920ull,0x25202c3132662520ull,
0x616d090a3b343466ull,0x2509203233662e64ull,0x6625202c34303166ull,0x32326625202c3534ull,
0x3b3330316625202cull,0x33662e64616d090aull,0x3530316625092032ull,0x202c33346625202cull,
0x6625202c33326625ull,0x756d090a3b343031ull,0x2509203233662e6cull,0x6625202c36303166ull,
0x34326625202c3634ull,0x662e627573090a3bull,0x3031662509203233ull,0x3530316625202c37ull,
0x3b3630316625202cull,0x33662e6c756d090aull,0x3830316625092032ull,0x202c37326625202cull,
0x090a3b3730316625ull,0x65726168732e7473ull,0x5b09203233662e64ull,0x30322b3931647225ull,
0x3830316625202c5dull,0x09636f6c2e090a3bull,0x3009303431093731ull,0x33662e6c756d090aull,
0x3930316625092032ull,0x202c31326625202cull,0x6d090a3b33346625ull,0x09203233662e6461ull,
0x25202c3031316625ull,0x326625202c343466ull,0x3930316625202c32ull,0x662e64616d090a3bull,
0x3131662509203233ull,0x2c36346625202c31ull,0x25202c3332662520ull,0x6d090a3b30313166ull,
0x09203233662e6461ull,0x25202c3231316625ull,0x326625202c353466ull,0x3131316625202c34ull,
0x662e6c756d090a3bull,0x3131662509203233ull,0x2c37326625202c33ull,0x0a3b323131662520ull,
0x726168732e747309ull,0x09203233662e6465ull,0x322b39316472255bull,0x31316625202c5d38ull,
0x636f6c2e090a3b33ull,0x0933383209373109ull,0x732e726162090a30ull,0x0a3b300920636e79ull,
0x373109636f6c2e09ull,0x090a300937383209ull,0x203233732e766f6dull,0x37202c3732722509ull,
0x34326c756d090a3bull,0x203233732e6f6c2eull,0x25202c3832722509ull,0x327225202c343172ull,
0x2e6c756d090a3b37ull,0x09203233752e6f6cull,0x7225202c39327225ull,0x090a3b34202c3832ull,
0x2e3436752e747663ull,0x6472250920323375ull,0x39327225202c3032ull,0x752e627573090a3bull,
0x3164722509203436ull,0x3031647225202c30ull,0x3b3032647225202cull,0x3109636f6c2e090aull,
0x0a30093938320937ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3431316625ull,
0x3b5d302b33647225ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b30316472255b09ull,
0x31316625202c5d30ull,0x636f6c2e090a3b34ull,0x0930393209373109ull,0x752e646461090a30ull,
0x3164722509203436ull,0x2c37647225202c30ull,0x0a3b303164722520ull,0x373109636f6c2e09ull,
0x090a300933393209ull,0x65726168732e646cull,0x2509203233662e64ull,0x255b202c35313166ull,
0x5d3233312b336472ull,0x6c672e7473090a3bull,0x3233662e6c61626full,0x30316472255b0920ull,
0x316625202c5d302bull,0x6f6c2e090a3b3531ull,0x3439320937310963ull,0x2e646461090a3009ull,
0x6472250920343675ull,0x37647225202c3031ull,0x3b3031647225202cull,0x3109636f6c2e090aull,
0x0a30093739320937ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3631316625ull,
0x3436322b33647225ull,0x672e7473090a3b5dull,0x33662e6c61626f6cull,0x316472255b092032ull,
0x6625202c5d302b30ull,0x6c2e090a3b363131ull,0x393209373109636full,0x646461090a300938ull,
0x722509203436752eull,0x647225202c303164ull,0x3031647225202c37ull,0x09636f6c2e090a3bull,
0x3009313033093731ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c373131662509ull,
0x39332b336472255bull,0x2e7473090a3b5d36ull,0x662e6c61626f6c67ull,0x6472255b09203233ull,
0x25202c5d302b3031ull,0x2e090a3b37313166ull,0x3309373109636f6cull,0x6461090a30093230ull,
0x2509203436752e64ull,0x7225202c30316472ull,0x31647225202c3764ull,0x636f6c2e090a3b30ull,
0x0935303309373109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c38313166250920ull,
0x352b336472255b20ull,0x7473090a3b5d3832ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,
0x202c5d302b303164ull,0x090a3b3831316625ull,0x09373109636f6c2eull,0x61090a3009363033ull,
0x09203436752e6464ull,0x25202c3031647225ull,0x647225202c376472ull,0x6f6c2e090a3b3031ull,
0x3930330937310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3931316625092032ull,
0x2b336472255b202cull,0x73090a3b5d303636ull,0x6c61626f6c672e74ull,0x255b09203233662eull,
0x2c5d302b30316472ull,0x0a3b393131662520ull,0x373109636f6c2e09ull,0x090a300930313309ull,
0x203436752e646461ull,0x202c303164722509ull,0x7225202c37647225ull,0x6c2e090a3b303164ull,
0x313309373109636full,0x2e646c090a300933ull,0x662e646572616873ull,0x3231662509203233ull,
0x336472255b202c30ull,0x090a3b5d3239372bull,0x61626f6c672e7473ull,0x5b09203233662e6cull,
0x5d302b3031647225ull,0x3b3032316625202cull,0x3109636f6c2e090aull,0x0a30093731330937ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3132316625ull,0x3432392b33647225ull,
0x2e646461090a3b5dull,0x6472250920343675ull,0x37647225202c3132ull,0x3b3031647225202cull,
0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b31326472255b09ull,0x32316625202c5d30ull,
0x636f6c2e090a3b31ull,0x0938313309373109ull,0x3b74697865090a30ull,0x646e6557444c240aull,
0x44554334315a5f5full,0x326c656e72656b41ull,0x0a3a696650544344ull,0x5a5f202f2f207d09ull,
0x656b414455433431ull,0x544344326c656e72ull,0x652e090a0a696650ull,0x315a5f207972746eull,
0x72656b4144554335ull,0x54434449326c656eull,0x09090a2820696650ull,0x2e206d617261702eull,
0x75635f5f20343675ull,0x5f5f6d7261706164ull,0x6b4144554335315aull,0x4449326c656e7265ull,
0x5f5f5f6966505443ull,0x617261705f6c6176ull,0x2c7473446372536dull,0x617261702e09090aull,
0x5f203233732e206dull,0x726170616475635full,0x554335315a5f5f6dull,0x6c656e72656b4144ull,
0x6966505443444932ull,0x69727453676d495full,0x090a7b090a296564ull,0x33752e206765722eull,
0x3e31333c72252032ull,0x206765722e090a3bull,0x647225203436752eull,0x2e090a3b3e33323cull,
0x3233662e20676572ull,0x3e3732313c662520ull,0x726168732e090a3bull,0x67696c612e206465ull,
0x2038622e2034206eull,0x625f616475635f5full,0x303037326b636f6cull,0x0a3b5d323131325bull,
0x373109636f6c2e09ull,0x240a300934333309ull,0x315a5f5f3142424cull,0x72656b4144554335ull,
0x54434449326c656eull,0x6f6d090a3a696650ull,0x2509203436752e76ull,0x635f5f202c316472ull,
0x636f6c625f616475ull,0x090a3b303037326bull,0x09373109636f6c2eull,0x63090a3009383633ull,
0x752e3233732e7476ull,0x2c31722509203631ull,0x2e64696174632520ull,0x2e6c6873090a3b79ull,
0x3272250920323362ull,0x34202c317225202cull,0x732e747663090a3bull,0x09203631752e3233ull,
0x697425202c337225ull,0x6873090a3b7a2e64ull,0x2509203233622e6cull,0x2c337225202c3472ull,
0x747663090a3b3320ull,0x3631752e3233732eull,0x25202c3572250920ull,0x3b782e6469617463ull,
0x33622e6c6873090aull,0x202c367225092032ull,0x0a3b35202c357225ull,0x3233732e74766309ull,
0x722509203631752eull,0x2e64697425202c37ull,0x2e6c6873090a3b79ull,0x3872250920323362ull,
0x33202c377225202cull,0x732e646461090a3bull,0x2c39722509203233ull,0x7225202c32722520ull,
0x2e766f6d090a3b34ull,0x3172250920323373ull,0x090a3b3333202c30ull,0x6f6c2e34326c756dull,
0x722509203233732eull,0x2c347225202c3131ull,0x090a3b3031722520ull,0x2e3233752e747663ull,
0x3172250920363175ull,0x2e64697425202c32ull,0x2e646461090a3b78ull,0x3172250920323375ull,
0x202c387225202c33ull,0x6c090a3b32317225ull,0x2e6d617261702e64ull,0x3172250920323373ull,
0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,0x6b4144554335315aull,0x4449326c656e7265ull,
0x6d495f6966505443ull,0x5d65646972745367ull,0x34326c756d090a3bull,0x203233732e6f6c2eull,
0x25202c3531722509ull,0x34317225202c3972ull,0x732e646461090a3bull,0x3631722509203233ull,
0x202c31317225202cull,0x61090a3b33317225ull,0x09203233732e6464ull,0x7225202c37317225ull,
0x3b35317225202c36ull,0x33732e646461090aull,0x2c38317225092032ull,0x25202c3731722520ull,
0x756d090a3b333172ull,0x3233752e6f6c2e6cull,0x202c393172250920ull,0x3b34202c36317225ull,
0x36752e747663090aull,0x2509203233752e34ull,0x317225202c326472ull,0x2e646461090a3b39ull,
0x6472250920343675ull,0x2c32647225202c33ull,0x090a3b3164722520ull,0x752e6f6c2e6c756dull,
0x3032722509203233ull,0x202c38317225202cull,0x2e747663090a3b34ull,0x203233752e343675ull,
0x25202c3464722509ull,0x646c090a3b303272ull,0x752e6d617261702eull,0x3564722509203436ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x656b414455433531ull,0x434449326c656e72ull,
0x765f5f5f69665054ull,0x6d617261705f6c61ull,0x3b5d747344637253ull,0x36752e646461090aull,
0x2c36647225092034ull,0x25202c3464722520ull,0x646c090a3b356472ull,0x2e6c61626f6c672eull,
0x3166250920323366ull,0x2b366472255b202cull,0x2e7473090a3b5d30ull,0x662e646572616873ull,
0x6472255b09203233ull,0x6625202c5d302b33ull,0x636f6c2e090a3b31ull,0x0932373309373109ull,
0x6c2e6c756d090a30ull,0x2509203233752e6full,0x317225202c313272ull,0x63090a3b34202c34ull,
0x752e3436752e7476ull,0x3764722509203233ull,0x0a3b31327225202cull,0x3436752e64646109ull,
0x202c386472250920ull,0x7225202c37647225ull,0x2e646c090a3b3664ull,0x662e6c61626f6c67ull,
0x2c32662509203233ull,0x302b386472255b20ull,0x732e7473090a3b5dull,0x33662e6465726168ull,
0x336472255b092032ull,0x25202c5d3233312bull,0x6f6c2e090a3b3266ull,0x3637330937310963ull,
0x2e646461090a3009ull,0x6472250920343675ull,0x2c37647225202c39ull,0x090a3b3864722520ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x6472255b202c3366ull,0x73090a3b5d302b39ull,
0x6465726168732e74ull,0x255b09203233662eull,0x5d3436322b336472ull,0x090a3b336625202cull,
0x09373109636f6c2eull,0x61090a3009373733ull,0x09203436752e6464ull,0x25202c3031647225ull,
0x647225202c376472ull,0x636f6c2e090a3b39ull,0x0930383309373109ull,0x6c672e646c090a30ull,
0x3233662e6c61626full,0x5b202c3466250920ull,0x5d302b3031647225ull,0x68732e7473090a3bull,
0x3233662e64657261ull,0x2b336472255b0920ull,0x6625202c5d363933ull,0x636f6c2e090a3b34ull,
0x0931383309373109ull,0x752e646461090a30ull,0x3164722509203436ull,0x2c37647225202c30ull,
0x0a3b303164722520ull,0x373109636f6c2e09ull,0x090a300934383309ull,0x61626f6c672e646cull,
0x2509203233662e6cull,0x6472255b202c3566ull,0x090a3b5d302b3031ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x3832352b33647225ull,0x0a3b356625202c5dull,0x373109636f6c2e09ull,
0x090a300935383309ull,0x203436752e646461ull,0x202c303164722509ull,0x7225202c37647225ull,
0x6c2e090a3b303164ull,0x383309373109636full,0x2e646c090a300938ull,0x662e6c61626f6c67ull,
0x2c36662509203233ull,0x2b30316472255b20ull,0x2e7473090a3b5d30ull,0x662e646572616873ull,
0x6472255b09203233ull,0x202c5d3036362b33ull,0x6c2e090a3b366625ull,0x383309373109636full,
0x646461090a300939ull,0x722509203436752eull,0x647225202c303164ull,0x3031647225202c37ull,
0x09636f6c2e090a3bull,0x3009323933093731ull,0x6f6c672e646c090aull,0x203233662e6c6162ull,
0x255b202c37662509ull,0x3b5d302b30316472ull,0x6168732e7473090aull,0x203233662e646572ull,
0x372b336472255b09ull,0x376625202c5d3239ull,0x09636f6c2e090a3bull,0x3009333933093731ull,
0x36752e646461090aull,0x3031647225092034ull,0x202c37647225202cull,0x090a3b3031647225ull,
0x09373109636f6c2eull,0x6c090a3009363933ull,0x6c61626f6c672e64ull,0x662509203233662eull,
0x316472255b202c38ull,0x73090a3b5d302b30ull,0x6465726168732e74ull,0x255b09203233662eull,
0x5d3432392b336472ull,0x090a3b386625202cull,0x09373109636f6c2eull,0x62090a3009393933ull,
0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x3336310937310963ull,0x2e6c756d090a3009ull,
0x09203233752e6f6cull,0x7225202c32327225ull,0x090a3b34202c3331ull,0x2e3436752e747663ull,
0x6472250920323375ull,0x32327225202c3131ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,
0x347225202c333272ull,0x090a3b323331202cull,0x2e3436752e747663ull,0x6472250920323375ull,
0x33327225202c3231ull,0x752e646461090a3bull,0x3164722509203436ull,0x3231647225202c33ull,
0x3b3131647225202cull,0x36752e646461090aull,0x3431647225092034ull,0x202c31647225202cull,
0x090a3b3331647225ull,0x65726168732e646cull,0x2509203233662e64ull,0x6472255b202c3966ull,
0x090a3b5d302b3431ull,0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c303166ull,
0x5d3832352b343164ull,0x662e646461090a3bull,0x3131662509203233ull,0x25202c396625202cull,
0x6c2e090a3b303166ull,0x363109373109636full,0x2e646c090a300934ull,0x662e646572616873ull,
0x3231662509203233ull,0x34316472255b202cull,0x090a3b5d3239372bull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c333166ull,0x5d3436322b343164ull,0x6f632e646c090a3bull,
0x203233662e74736eull,0x5b202c3431662509ull,0x6c090a3b5d625f43ull,0x2e74736e6f632e64ull,
0x3166250920323366ull,0x5d655f435b202c35ull,0x662e6c756d090a3bull,0x3631662509203233ull,
0x202c32316625202cull,0x6d090a3b35316625ull,0x09203233662e6461ull,0x6625202c37316625ull,
0x34316625202c3331ull,0x0a3b36316625202cull,0x373109636f6c2e09ull,0x090a300938363109ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c383166ull,0x5d3432392b343164ull,
0x68732e646c090a3bull,0x3233662e64657261ull,0x202c393166250920ull,0x312b34316472255bull,
0x646c090a3b5d3233ull,0x2e6465726168732eull,0x3266250920323366ull,0x316472255b202c30ull,
0x0a3b5d3639332b34ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c31326625ull,
0x3036362b34316472ull,0x632e646c090a3b5dull,0x3233662e74736e6full,0x202c323266250920ull,
0x090a3b5d645f435bull,0x74736e6f632e646cull,0x662509203233662eull,0x635f435b202c3332ull,
0x632e646c090a3b5dull,0x3233662e74736e6full,0x202c343266250920ull,0x090a3b5d615f435bull,
0x74736e6f632e646cull,0x662509203233662eull,0x665f435b202c3532ull,0x2e6c756d090a3b5dull,
0x3266250920323366ull,0x2c38316625202c36ull,0x090a3b3532662520ull,0x203233662e64616dull,
0x25202c3732662509ull,0x326625202c393166ull,0x3b36326625202c34ull,0x33662e64616d090aull,
0x2c38326625092032ull,0x25202c3032662520ull,0x326625202c333266ull,0x2e64616d090a3b37ull,
0x3266250920323366ull,0x2c31326625202c39ull,0x25202c3232662520ull,0x6c2e090a3b383266ull,
0x363109373109636full,0x6c756d090a300939ull,0x662509203233662eull,0x39316625202c3033ull,
0x0a3b35326625202cull,0x3233662e6c756d09ull,0x202c313366250920ull,0x6625202c38316625ull,
0x627573090a3b3432ull,0x662509203233662eull,0x31336625202c3233ull,0x0a3b30336625202cull,
0x3233662e64616d09ull,0x202c333366250920ull,0x6625202c30326625ull,0x32336625202c3232ull,
0x662e6c756d090a3bull,0x3433662509203233ull,0x202c31326625202cull,0x73090a3b33326625ull,
0x09203233662e6275ull,0x6625202c35336625ull,0x34336625202c3333ull,0x09636f6c2e090a3bull,
0x3009313731093731ull,0x33662e627573090aull,0x2c36336625092032ull,0x6625202c39662520ull,
0x6f6c2e090a3b3031ull,0x3237310937310963ull,0x2e6c756d090a3009ull,0x3366250920323366ull,
0x2c32316625202c37ull,0x090a3b3431662520ull,0x203233662e6c756dull,0x25202c3833662509ull,
0x316625202c333166ull,0x2e627573090a3b35ull,0x3366250920323366ull,0x2c38336625202c39ull,
0x090a3b3733662520ull,0x09373109636f6c2eull,0x6d090a3009363731ull,0x09203233662e6c75ull,
0x6625202c30346625ull,0x32326625202c3831ull,0x662e6c756d090a3bull,0x3134662509203233ull,
0x202c39316625202cull,0x73090a3b33326625ull,0x09203233662e6275ull,0x6625202c32346625ull,
0x30346625202c3134ull,0x662e6c756d090a3bull,0x3334662509203233ull,0x202c30326625202cull,
0x73090a3b35326625ull,0x09203233662e6275ull,0x6625202c34346625ull,0x33346625202c3234ull,
0x662e6c756d090a3bull,0x3534662509203233ull,0x202c31326625202cull,0x73090a3b34326625ull,
0x09203233662e6275ull,0x6625202c36346625ull,0x35346625202c3434ull,0x09636f6c2e090a3bull,
0x3009373731093731ull,0x33662e6c756d090aull,0x2c37346625092032ull,0x25202c3831662520ull,
0x616d090a3b333266ull,0x2509203233662e64ull,0x316625202c383466ull,0x2c32326625202c39ull,
0x090a3b3734662520ull,0x203233662e6c756dull,0x25202c3934662509ull,0x326625202c303266ull,
0x2e627573090a3b34ull,0x3566250920323366ull,0x2c38346625202c30ull,0x090a3b3934662520ull,
0x203233662e64616dull,0x25202c3135662509ull,0x326625202c313266ull,0x3b30356625202c35ull,
0x3109636f6c2e090aull,0x0a30093937310937ull,0x3233662e64646109ull,0x202c323566250920ull,
0x6625202c31316625ull,0x2e646c090a3b3731ull,0x33662e74736e6f63ull,0x2c33356625092032ull,
0x6d726f6e5f435b20ull,0x2e646461090a3b5dull,0x3566250920323366ull,0x2c32356625202c34ull,
0x090a3b3932662520ull,0x203233662e6c756dull,0x25202c3535662509ull,0x356625202c333566ull,
0x732e7473090a3b34ull,0x33662e6465726168ull,0x316472255b092032ull,0x6625202c5d302b34ull,
0x6f6c2e090a3b3535ull,0x3038310937310963ull,0x2e627573090a3009ull,0x3566250920323366ull,
0x2c32356625202c36ull,0x090a3b3932662520ull,0x203233662e6c756dull,0x25202c3735662509ull,
0x356625202c333566ull,0x732e7473090a3b36ull,0x33662e6465726168ull,0x316472255b092032ull,
0x202c5d3432392b34ull,0x2e090a3b37356625ull,0x3109373109636f6cull,0x7573090a30093138ull,
0x2509203233662e62ull,0x316625202c383566ull,0x3b37316625202c31ull,0x33662e646461090aull,
0x2c39356625092032ull,0x25202c3835662520ull,0x756d090a3b353366ull,0x2509203233662e6cull,
0x356625202c303666ull,0x3b39356625202c33ull,0x6168732e7473090aull,0x203233662e646572ull,
0x2b34316472255b09ull,0x6625202c5d383235ull,0x6f6c2e090a3b3036ull,0x3238310937310963ull,
0x2e627573090a3009ull,0x3666250920323366ull,0x2c38356625202c31ull,0x090a3b3533662520ull,
0x203233662e6c756dull,0x25202c3236662509ull,0x366625202c333566ull,0x732e7473090a3b31ull,
0x33662e6465726168ull,0x316472255b092032ull,0x202c5d3639332b34ull,0x2e090a3b32366625ull,
0x3109373109636f6cull,0x6461090a30093438ull,0x2509203233662e64ull,0x336625202c333666ull,
0x3b39336625202c36ull,0x33662e646461090aull,0x2c34366625092032ull,0x25202c3336662520ull,
0x756d090a3b363466ull,0x2509203233662e6cull,0x356625202c353666ull,0x3b34366625202c33ull,
0x6168732e7473090aull,0x203233662e646572ull,0x2b34316472255b09ull,0x6625202c5d323331ull,
0x6f6c2e090a3b3536ull,0x3538310937310963ull,0x2e627573090a3009ull,0x3666250920323366ull,
0x2c36336625202c36ull,0x090a3b3933662520ull,0x203233662e627573ull,0x25202c3736662509ull,
0x356625202c363666ull,0x2e6c756d090a3b31ull,0x3666250920323366ull,0x2c33356625202c38ull,
0x090a3b3736662520ull,0x65726168732e7473ull,0x5b09203233662e64ull,0x36362b3431647225ull,
0x38366625202c5d30ull,0x09636f6c2e090a3bull,0x3009363831093731ull,0x33662e646461090aull,
0x2c39366625092032ull,0x25202c3636662520ull,0x756d090a3b313566ull,0x2509203233662e6cull,
0x356625202c303766ull,0x3b39366625202c33ull,0x6168732e7473090aull,0x203233662e646572ull,
0x2b34316472255b09ull,0x6625202c5d343632ull,0x6f6c2e090a3b3037ull,0x3738310937310963ull,
0x2e627573090a3009ull,0x3766250920323366ull,0x2c33366625202c31ull,0x090a3b3634662520ull,
0x203233662e6c756dull,0x25202c3237662509ull,0x376625202c333566ull,0x732e7473090a3b31ull,
0x33662e6465726168ull,0x316472255b092032ull,0x202c5d3239372b34ull,0x2e090a3b32376625ull,
0x3409373109636f6cull,0x6162090a30093630ull,0x0920636e79732e72ull,0x636f6c2e090a3b30ull,
0x0933363109373109ull,0x752e646461090a30ull,0x3432722509203233ull,0x25202c347225202cull,
0x756d090a3b323172ull,0x3233752e6f6c2e6cull,0x202c353272250920ull,0x3331202c34327225ull,
0x2e747663090a3b32ull,0x203233752e343675ull,0x202c353164722509ull,0x61090a3b35327225ull,
0x09203436752e6464ull,0x25202c3631647225ull,0x7225202c35316472ull,0x756d090a3b313164ull,
0x752e6f6c2e34326cull,0x3632722509203233ull,0x202c32317225202cull,0x2e747663090a3b34ull,
0x203233752e343675ull,0x202c373164722509ull,0x73090a3b36327225ull,0x09203436752e6275ull,
0x25202c3831647225ull,0x7225202c36316472ull,0x6461090a3b373164ull,0x2509203436752e64ull,
0x7225202c39316472ull,0x31647225202c3164ull,0x732e646c090a3b38ull,0x33662e6465726168ull,
0x2c33376625092032ull,0x2b39316472255b20ull,0x2e646c090a3b5d30ull,0x662e646572616873ull,
0x3437662509203233ull,0x39316472255b202cull,0x61090a3b5d36312bull,0x09203233662e6464ull,
0x6625202c31316625ull,0x34376625202c3337ull,0x09636f6c2e090a3bull,0x3009343631093731ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3537662509ull,0x34322b3931647225ull,
0x732e646c090a3b5dull,0x33662e6465726168ull,0x2c36376625092032ull,0x2b39316472255b20ull,
0x6c756d090a3b5d38ull,0x662509203233662eull,0x35376625202c3737ull,0x0a3b35316625202cull,
0x3233662e64616d09ull,0x202c373166250920ull,0x6625202c36376625ull,0x37376625202c3431ull,
0x09636f6c2e090a3bull,0x3009383631093731ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3837662509ull,0x38322b3931647225ull,0x732e646c090a3b5dull,0x33662e6465726168ull,
0x2c39376625092032ull,0x2b39316472255b20ull,0x2e646c090a3b5d34ull,0x662e646572616873ull,
0x3038662509203233ull,0x39316472255b202cull,0x6c090a3b5d32312bull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3138ull,0x0a3b5d30322b3931ull,0x3233662e6c756d09ull,
0x202c323866250920ull,0x6625202c38376625ull,0x64616d090a3b3532ull,0x662509203233662eull,
0x39376625202c3338ull,0x202c34326625202cull,0x6d090a3b32386625ull,0x09203233662e6461ull,
0x6625202c34386625ull,0x33326625202c3038ull,0x0a3b33386625202cull,0x3233662e64616d09ull,
0x202c393266250920ull,0x6625202c31386625ull,0x34386625202c3232ull,0x09636f6c2e090a3bull,
0x3009393631093731ull,0x33662e6c756d090aull,0x2c35386625092032ull,0x25202c3937662520ull,
0x756d090a3b353266ull,0x2509203233662e6cull,0x376625202c363866ull,0x3b34326625202c38ull,
0x33662e627573090aull,0x2c37386625092032ull,0x25202c3638662520ull,0x616d090a3b353866ull,
0x2509203233662e64ull,0x386625202c383866ull,0x2c32326625202c30ull,0x090a3b3738662520ull,
0x203233662e6c756dull,0x25202c3938662509ull,0x326625202c313866ull,0x2e627573090a3b33ull,
0x3366250920323366ull,0x2c38386625202c35ull,0x090a3b3938662520ull,0x09373109636f6c2eull,
0x73090a3009313731ull,0x09203233662e6275ull,0x6625202c36336625ull,0x34376625202c3337ull,
0x09636f6c2e090a3bull,0x3009323731093731ull,0x33662e6c756d090aull,0x2c30396625092032ull,
0x25202c3537662520ull,0x756d090a3b343166ull,0x2509203233662e6cull,0x376625202c313966ull,
0x3b35316625202c36ull,0x33662e627573090aull,0x2c39336625092032ull,0x25202c3139662520ull,
0x6c2e090a3b303966ull,0x373109373109636full,0x6c756d090a300936ull,0x662509203233662eull,
0x38376625202c3239ull,0x0a3b32326625202cull,0x3233662e6c756d09ull,0x202c333966250920ull,
0x6625202c39376625ull,0x627573090a3b3332ull,0x662509203233662eull,0x33396625202c3439ull,
0x0a3b32396625202cull,0x3233662e6c756d09ull,0x202c353966250920ull,0x6625202c30386625ull,
0x627573090a3b3532ull,0x662509203233662eull,0x34396625202c3639ull,0x0a3b35396625202cull,
0x3233662e6c756d09ull,0x202c373966250920ull,0x6625202c31386625ull,0x627573090a3b3432ull,
0x662509203233662eull,0x36396625202c3634ull,0x0a3b37396625202cull,0x373109636f6c2e09ull,
0x090a300937373109ull,0x203233662e6c756dull,0x25202c3839662509ull,0x326625202c383766ull,
0x2e64616d090a3b33ull,0x3966250920323366ull,0x2c39376625202c39ull,0x25202c3232662520ull,
0x756d090a3b383966ull,0x2509203233662e6cull,0x6625202c30303166ull,0x34326625202c3038ull,
0x662e627573090a3bull,0x3031662509203233ull,0x2c39396625202c31ull,0x0a3b303031662520ull,
0x3233662e64616d09ull,0x202c313566250920ull,0x6625202c31386625ull,0x30316625202c3532ull,
0x636f6c2e090a3b31ull,0x0939373109373109ull,0x662e646461090a30ull,0x3235662509203233ull,
0x202c31316625202cull,0x61090a3b37316625ull,0x09203233662e6464ull,0x25202c3230316625ull,
0x326625202c323566ull,0x2e6c756d090a3b39ull,0x3166250920323366ull,0x33356625202c3330ull,
0x3b3230316625202cull,0x6168732e7473090aull,0x203233662e646572ull,0x2b39316472255b09ull,
0x30316625202c5d30ull,0x636f6c2e090a3b33ull,0x0930383109373109ull,0x662e627573090a30ull,
0x3031662509203233ull,0x2c32356625202c34ull,0x090a3b3932662520ull,0x203233662e6c756dull,
0x202c353031662509ull,0x6625202c33356625ull,0x7473090a3b343031ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x2c5d38322b393164ull,0x0a3b353031662520ull,0x373109636f6c2e09ull,
0x090a300931383109ull,0x203233662e627573ull,0x25202c3835662509ull,0x316625202c313166ull,
0x2e646461090a3b37ull,0x3166250920323366ull,0x38356625202c3630ull,0x0a3b35336625202cull,
0x3233662e6c756d09ull,0x2c37303166250920ull,0x25202c3335662520ull,0x73090a3b36303166ull,
0x6465726168732e74ull,0x255b09203233662eull,0x5d36312b39316472ull,0x3b3730316625202cull,
0x3109636f6c2e090aull,0x0a30093238310937ull,0x3233662e62757309ull,0x2c38303166250920ull,
0x25202c3835662520ull,0x756d090a3b353366ull,0x2509203233662e6cull,0x6625202c39303166ull,
0x30316625202c3335ull,0x732e7473090a3b38ull,0x33662e6465726168ull,0x316472255b092032ull,
0x25202c5d32312b39ull,0x2e090a3b39303166ull,0x3109373109636f6cull,0x6461090a30093438ull,
0x2509203233662e64ull,0x336625202c333666ull,0x3b39336625202c36ull,0x33662e646461090aull,
0x3031316625092032ull,0x202c33366625202cull,0x6d090a3b36346625ull,0x09203233662e6c75ull,
0x25202c3131316625ull,0x316625202c333566ull,0x2e7473090a3b3031ull,0x662e646572616873ull,
0x6472255b09203233ull,0x25202c5d342b3931ull,0x2e090a3b31313166ull,0x3109373109636f6cull,
0x7573090a30093538ull,0x2509203233662e62ull,0x336625202c363666ull,0x3b39336625202c36ull,
0x33662e627573090aull,0x3231316625092032ull,0x202c36366625202cull,0x6d090a3b31356625ull,
0x09203233662e6c75ull,0x25202c3331316625ull,0x316625202c333566ull,0x2e7473090a3b3231ull,
0x662e646572616873ull,0x6472255b09203233ull,0x202c5d30322b3931ull,0x090a3b3331316625ull,
0x09373109636f6c2eull,0x61090a3009363831ull,0x09203233662e6464ull,0x25202c3431316625ull,
0x356625202c363666ull,0x2e6c756d090a3b31ull,0x3166250920323366ull,0x33356625202c3531ull,
0x3b3431316625202cull,0x6168732e7473090aull,0x203233662e646572ull,0x2b39316472255b09ull,
0x31316625202c5d38ull,0x636f6c2e090a3b35ull,0x0937383109373109ull,0x662e627573090a30ull,
0x3131662509203233ull,0x2c33366625202c36ull,0x090a3b3634662520ull,0x203233662e6c756dull,
0x202c373131662509ull,0x6625202c33356625ull,0x7473090a3b363131ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x2c5d34322b393164ull,0x0a3b373131662520ull,0x373109636f6c2e09ull,
0x090a300933313409ull,0x636e79732e726162ull,0x6c2e090a3b300920ull,0x313409373109636full,
0x766f6d090a300937ull,0x722509203233732eull,0x090a3b37202c3732ull,0x6f6c2e34326c756dull,
0x722509203233732eull,0x34317225202c3832ull,0x0a3b37327225202cull,0x2e6f6c2e6c756d09ull,
0x3272250920323375ull,0x2c38327225202c39ull,0x747663090a3b3420ull,0x3233752e3436752eull,
0x2c30326472250920ull,0x090a3b3932722520ull,0x203436752e627573ull,0x202c303164722509ull,
0x25202c3031647225ull,0x2e090a3b30326472ull,0x3409373109636f6cull,0x646c090a30093931ull,
0x2e6465726168732eull,0x3166250920323366ull,0x6472255b202c3831ull,0x73090a3b5d302b33ull,
0x6c61626f6c672e74ull,0x255b09203233662eull,0x2c5d302b30316472ull,0x0a3b383131662520ull,
0x373109636f6c2e09ull,0x090a300930323409ull,0x203436752e646461ull,0x202c303164722509ull,
0x7225202c37647225ull,0x6c2e090a3b303164ull,0x323409373109636full,0x2e646c090a300933ull,
0x662e646572616873ull,0x3131662509203233ull,0x336472255b202c39ull,0x090a3b5d3233312bull,
0x61626f6c672e7473ull,0x5b09203233662e6cull,0x5d302b3031647225ull,0x3b3931316625202cull,
0x3109636f6c2e090aull,0x0a30093432340937ull,0x3436752e64646109ull,0x2c30316472250920ull,
0x25202c3764722520ull,0x2e090a3b30316472ull,0x3409373109636f6cull,0x646c090a30093732ull,
0x2e6465726168732eull,0x3166250920323366ull,0x6472255b202c3032ull,0x0a3b5d3436322b33ull,
0x626f6c672e747309ull,0x09203233662e6c61ull,0x302b30316472255bull,0x3032316625202c5dull,
0x09636f6c2e090a3bull,0x3009383234093731ull,0x36752e646461090aull,0x3031647225092034ull,
0x202c37647225202cull,0x090a3b3031647225ull,0x09373109636f6c2eull,0x6c090a3009313334ull,
0x6465726168732e64ull,0x662509203233662eull,0x72255b202c313231ull,0x3b5d3639332b3364ull,
0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b30316472255b09ull,0x32316625202c5d30ull,
0x636f6c2e090a3b31ull,0x0932333409373109ull,0x752e646461090a30ull,0x3164722509203436ull,
0x2c37647225202c30ull,0x0a3b303164722520ull,0x373109636f6c2e09ull,0x090a300935333409ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c32323166ull,0x5d3832352b336472ull,
0x6c672e7473090a3bull,0x3233662e6c61626full,0x30316472255b0920ull,0x316625202c5d302bull,
0x6f6c2e090a3b3232ull,0x3633340937310963ull,0x2e646461090a3009ull,0x6472250920343675ull,
0x37647225202c3031ull,0x3b3031647225202cull,0x3109636f6c2e090aull,0x0a30093933340937ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3332316625ull,0x3036362b33647225ull,
0x672e7473090a3b5dull,0x33662e6c61626f6cull,0x316472255b092032ull,0x6625202c5d302b30ull,
0x6c2e090a3b333231ull,0x343409373109636full,0x646461090a300930ull,0x722509203436752eull,
0x647225202c303164ull,0x3031647225202c37ull,0x09636f6c2e090a3bull,0x3009333434093731ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c343231662509ull,0x39372b336472255bull,
0x2e7473090a3b5d32ull,0x662e6c61626f6c67ull,0x6472255b09203233ull,0x25202c5d302b3031ull,
0x2e090a3b34323166ull,0x3409373109636f6cull,0x646c090a30093734ull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3532ull,0x0a3b5d3432392b33ull,0x3436752e64646109ull,
0x2c31326472250920ull,0x25202c3764722520ull,0x73090a3b30316472ull,0x6c61626f6c672e74ull,
0x255b09203233662eull,0x2c5d302b31326472ull,0x0a3b353231662520ull,0x373109636f6c2e09ull,
0x090a300938343409ull,0x4c240a3b74697865ull,0x5a5f5f646e655744ull,0x656b414455433531ull,
0x434449326c656e72ull,0x7d090a3a69665054ull,0x35315a5f202f2f20ull,0x6e72656b41445543ull,
0x5054434449326c65ull,0x6e652e090a0a6966ull,0x38315a5f20797274ull,0x6e72656b41445543ull,
0x4474726f68536c65ull,0x0a28206973505443ull,0x6d617261702e0909ull,0x5f5f203436752e20ull,
0x6d72617061647563ull,0x44554338315a5f5full,0x536c656e72656b41ull,0x5054434474726f68ull,
0x6c61765f5f5f6973ull,0x72536d617261705full,0x09090a2c74734463ull,0x2e206d617261702eull,
0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x6b4144554338315aull,0x6f68536c656e7265ull,
0x6973505443447472ull,0x69727453676d495full,0x090a7b090a296564ull,0x33752e206765722eull,
0x3236323c72252032ull,0x6765722e090a3b3eull,0x7225203436752e20ull,0x090a3b3e39313c64ull,
0x72702e206765722eull,0x3e333c7025206465ull,0x726168732e090a3bull,0x67696c612e206465ull,
0x2038622e2032206eull,0x625f616475635f5full,0x383238346b636f6cull,0x0a3b5d363731325bull,
0x093309636f6c2e09ull,0x4c240a3009393534ull,0x38315a5f5f314242ull,0x6e72656b41445543ull,
0x4474726f68536c65ull,0x090a3a6973505443ull,0x203436752e766f6dull,0x5f202c3164722509ull,
0x6c625f616475635full,0x3b383238346b636full,0x3309636f6c2e090aull,0x090a300932303509ull,
0x2e3233732e747663ull,0x3172250920363175ull,0x7a2e64697425202cull,0x622e6c6873090a3bull,
0x2c32722509203233ull,0x3b33202c31722520ull,0x33732e747663090aull,0x2509203631752e32ull,
0x64697425202c3372ull,0x6c6873090a3b792eull,0x722509203233622eull,0x202c337225202c34ull,
0x2e747663090a3b33ull,0x203631752e323375ull,0x7425202c35722509ull,0x61090a3b782e6469ull,
0x09203233752e6464ull,0x347225202c367225ull,0x090a3b357225202cull,0x203233622e6c6873ull,
0x7225202c37722509ull,0x6c090a3b31202c36ull,0x2e6d617261702e64ull,0x3872250920323373ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x656b414455433831ull,0x726f68536c656e72ull,
0x5f69735054434474ull,0x6469727453676d49ull,0x747663090a3b5d65ull,0x3631752e3233732eull,
0x25202c3972250920ull,0x3b792e6469617463ull,0x33622e6c6873090aull,0x2c30317225092032ull,
0x3b35202c39722520ull,0x33732e646461090aull,0x2c31317225092032ull,0x7225202c32722520ull,
0x6c756d090a3b3031ull,0x203233732e6f6c2eull,0x25202c3231722509ull,0x31317225202c3872ull,
0x732e747663090a3bull,0x09203631752e3233ull,0x6325202c33317225ull,0x0a3b782e64696174ull,
0x3233622e6c687309ull,0x202c343172250920ull,0x3b35202c33317225ull,0x33732e646461090aull,
0x2c35317225092032ull,0x25202c3231722520ull,0x6461090a3b343172ull,0x2509203233732e64ull,
0x377225202c363172ull,0x0a3b35317225202cull,0x2e6f6c2e6c756d09ull,0x3172250920323375ull,
0x2c36317225202c37ull,0x747663090a3b3220ull,0x3233752e3436752eull,0x202c326472250920ull,
0x6c090a3b37317225ull,0x2e6d617261702e64ull,0x6472250920343675ull,0x75635f5f5b202c33ull,
0x5f5f6d7261706164ull,0x6b4144554338315aull,0x6f68536c656e7265ull,0x6973505443447472ull,
0x705f6c61765f5f5full,0x446372536d617261ull,0x6461090a3b5d7473ull,0x2509203436752e64ull,
0x647225202c346472ull,0x3b33647225202c32ull,0x3309636f6c2e090aull,0x090a300930313509ull,
0x203233732e766f6dull,0x33202c3831722509ull,0x326c756d090a3b34ull,0x3233732e6f6c2e34ull,
0x202c393172250920ull,0x317225202c327225ull,0x2e646461090a3b38ull,0x3272250920323373ull,
0x202c377225202c30ull,0x6d090a3b39317225ull,0x33752e6f6c2e6c75ull,0x2c31327225092032ull,
0x32202c3032722520ull,0x752e747663090a3bull,0x09203233752e3436ull,0x7225202c35647225ull,
0x646461090a3b3132ull,0x722509203436752eull,0x35647225202c3664ull,0x0a3b31647225202cull,
0x3233732e766f6d09ull,0x202c323272250920ull,0x746573090a3b3531ull,0x3233732e656c2e70ull,
0x25202c3170250920ull,0x32327225202c3672ull,0x3170252140090a3bull,0x4c24092061726220ull,
0x343937315f345f74ull,0x09636f6c2e090a3bull,0x0a30093531350933ull,0x626f6c672e646c09ull,
0x09203233732e6c61ull,0x255b202c33327225ull,0x0a3b5d302b346472ull,0x726168732e747309ull,
0x09203233732e6465ull,0x5d302b366472255bull,0x0a3b33327225202cull,0x093309636f6c2e09ull,
0x6c090a3009323035ull,0x2e6d617261702e64ull,0x3872250920323373ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x656b414455433831ull,0x726f68536c656e72ull,0x5f69735054434474ull,
0x6469727453676d49ull,0x6f6c2e090a3b5d65ull,0x0936313509330963ull,0x6c2e6c756d090a30ull,
0x2509203233752e6full,0x387225202c343272ull,0x7663090a3b32202cull,0x33752e3436752e74ull,
0x2c37647225092032ull,0x090a3b3432722520ull,0x203436752e646461ull,0x25202c3464722509ull,
0x647225202c376472ull,0x636f6c2e090a3b34ull,0x3009393135093309ull,0x6f6c672e646c090aull,
0x203233732e6c6162ull,0x5b202c3532722509ull,0x3b5d302b34647225ull,0x6168732e7473090aull,
0x203233732e646572ull,0x362b366472255b09ull,0x35327225202c5d38ull,0x09636f6c2e090a3bull,
0x0a30093032350933ull,0x3436752e64646109ull,0x202c346472250920ull,0x7225202c37647225ull,
0x6f6c2e090a3b3464ull,0x0933323509330963ull,0x6c672e646c090a30ull,0x3233732e6c61626full,
0x202c363272250920ull,0x5d302b346472255bull,0x68732e7473090a3bull,0x3233732e64657261ull,
0x2b366472255b0920ull,0x7225202c5d363331ull,0x6f6c2e090a3b3632ull,0x0934323509330963ull,
0x752e646461090a30ull,0x3464722509203436ull,0x202c37647225202cull,0x2e090a3b34647225ull,
0x3235093309636f6cull,0x2e646c090a300937ull,0x732e6c61626f6c67ull,0x3732722509203233ull,
0x2b346472255b202cull,0x2e7473090a3b5d30ull,0x732e646572616873ull,0x6472255b09203233ull,
0x202c5d3430322b36ull,0x2e090a3b37327225ull,0x3235093309636f6cull,0x646461090a300938ull,
0x722509203436752eull,0x37647225202c3464ull,0x0a3b34647225202cull,0x093309636f6c2e09ull,
0x6c090a3009313335ull,0x6c61626f6c672e64ull,0x722509203233732eull,0x6472255b202c3832ull,
0x73090a3b5d302b34ull,0x6465726168732e74ull,0x255b09203233732eull,0x5d3237322b366472ull,
0x0a3b38327225202cull,0x093309636f6c2e09ull,0x61090a3009323335ull,0x09203436752e6464ull,
0x7225202c34647225ull,0x34647225202c3764ull,0x09636f6c2e090a3bull,0x0a30093533350933ull,
0x626f6c672e646c09ull,0x09203233732e6c61ull,0x255b202c39327225ull,0x0a3b5d302b346472ull,
0x726168732e747309ull,0x09203233732e6465ull,0x34332b366472255bull,0x39327225202c5d30ull,
0x09636f6c2e090a3bull,0x0a30093633350933ull,0x3436752e64646109ull,0x202c346472250920ull,
0x7225202c37647225ull,0x6f6c2e090a3b3464ull,0x0939333509330963ull,0x6c672e646c090a30ull,
0x3233732e6c61626full,0x202c303372250920ull,0x5d302b346472255bull,0x68732e7473090a3bull,
0x3233732e64657261ull,0x2b366472255b0920ull,0x7225202c5d383034ull,0x6f6c2e090a3b3033ull,
0x0930343509330963ull,0x752e646461090a30ull,0x3464722509203436ull,0x202c37647225202cull,
0x2e090a3b34647225ull,0x3435093309636f6cull,0x646461090a300931ull,0x722509203436752eull,
0x36647225202c3664ull,0x090a3b363734202cull,0x35093309636f6c2eull,0x646c090a30093334ull,
0x2e6c61626f6c672eull,0x3372250920323373ull,0x346472255b202c31ull,0x7473090a3b5d302bull,
0x2e6465726168732eull,0x72255b0920323373ull,0x25202c5d302b3664ull,0x744c240a3b313372ull,
0x3a343937315f345full,0x3309636f6c2e090aull,0x090a300936343509ull,0x636e79732e726162ull,
0x6c2e090a3b300920ull,0x383531093309636full,0x2e726873090a3009ull,0x3372250920323373ull,
0x202c367225202c32ull,0x2e646e61090a3b34ull,0x3372250920323362ull,0x202c367225202c33ull,
0x6e61090a3b32332dull,0x2509203233622e64ull,0x337225202c343372ull,0x6f090a3b31202c32ull,
0x2509203233622e72ull,0x377225202c353372ull,0x0a3b34337225202cull,0x3233622e646e6109ull,
0x202c363372250920ull,0x3133202c35337225ull,0x33622e726f090a3bull,0x2c37337225092032ull,
0x25202c3333722520ull,0x756d090a3b363372ull,0x3233752e6f6c2e6cull,0x202c383372250920ull,
0x3b3836202c327225ull,0x36752e747663090aull,0x2509203233752e34ull,0x337225202c386472ull,
0x2e6c756d090a3b38ull,0x09203233752e6f6cull,0x7225202c39337225ull,0x090a3b32202c3733ull,
0x2e3436752e747663ull,0x6472250920323375ull,0x3b39337225202c39ull,0x36752e646461090aull,
0x3031647225092034ull,0x202c38647225202cull,0x61090a3b39647225ull,0x09203436752e6464ull,
0x25202c3131647225ull,0x647225202c316472ull,0x2e646c090a3b3031ull,0x732e646572616873ull,
0x3034722509203631ull,0x31316472255b202cull,0x6c2e090a3b5d302bull,0x303631093309636full,
0x732e646c090a3009ull,0x31732e6465726168ull,0x2c31347225092036ull,0x2b31316472255b20ull,
0x6c2e090a3b5d3836ull,0x323631093309636full,0x732e646c090a3009ull,0x31732e6465726168ull,
0x2c32347225092036ull,0x2b31316472255b20ull,0x2e090a3b5d363331ull,0x3631093309636f6cull,
0x2e646c090a300934ull,0x732e646572616873ull,0x3334722509203631ull,0x31316472255b202cull,
0x090a3b5d3430322bull,0x31093309636f6c2eull,0x646c090a30093636ull,0x2e6465726168732eull,
0x3472250920363173ull,0x316472255b202c34ull,0x0a3b5d3237322b31ull,0x093309636f6c2e09ull,
0x6c090a3009383631ull,0x6465726168732e64ull,0x722509203631732eull,0x6472255b202c3534ull,
0x3b5d3034332b3131ull,0x3309636f6c2e090aull,0x090a300930373109ull,0x65726168732e646cull,
0x2509203631732e64ull,0x72255b202c363472ull,0x5d3830342b313164ull,0x09636f6c2e090a3bull,
0x0a30093237310933ull,0x726168732e646c09ull,0x09203631732e6465ull,0x255b202c37347225ull,
0x3637342b31316472ull,0x636f6c2e090a3b5dull,0x3009303032093309ull,0x33732e646461090aull,
0x2c38347225092032ull,0x25202c3034722520ull,0x6461090a3b373472ull,0x2509203233732e64ull,
0x347225202c393472ull,0x3b34347225202c33ull,0x33732e646461090aull,0x2c30357225092032ull,
0x25202c3134722520ull,0x6461090a3b363472ull,0x2509203233732e64ull,0x347225202c313572ull,
0x3b35347225202c32ull,0x33732e646461090aull,0x2c32357225092032ull,0x25202c3834722520ull,
0x6461090a3b393472ull,0x2509203233732e64ull,0x357225202c333572ull,0x3b31357225202c30ull,
0x33732e646461090aull,0x2c34357225092032ull,0x25202c3235722520ull,0x6f6d090a3b333572ull,
0x2509203233732e76ull,0x313332202c353572ull,0x6c756d090a3b3037ull,0x33732e6f6c2e3432ull,
0x2c36357225092032ull,0x25202c3435722520ull,0x6461090a3b353572ull,0x2509203233732e64ull,
0x357225202c373572ull,0x3836373233202c36ull,0x732e726873090a3bull,0x3835722509203233ull,
0x202c37357225202cull,0x2e7473090a3b3631ull,0x732e646572616873ull,0x6472255b09203631ull,
0x25202c5d302b3131ull,0x6c2e090a3b383572ull,0x323032093309636full,0x2e627573090a3009ull,
0x3572250920323373ull,0x2c38347225202c39ull,0x090a3b3934722520ull,0x203233732e627573ull,
0x25202c3036722509ull,0x357225202c303572ull,0x2e766f6d090a3b31ull,0x3672250920323373ull,
0x3437323033202c31ull,0x34326c756d090a3bull,0x203233732e6f6c2eull,0x25202c3236722509ull,
0x367225202c393572ull,0x2e766f6d090a3b31ull,0x3672250920323373ull,0x3034353231202c33ull,
0x34326c756d090a3bull,0x203233732e6f6c2eull,0x25202c3436722509ull,0x367225202c303672ull,
0x2e646461090a3b33ull,0x3672250920323373ull,0x2c32367225202c35ull,0x090a3b3436722520ull,
0x203233732e646461ull,0x25202c3636722509ull,0x373233202c353672ull,0x726873090a3b3836ull,
0x722509203233732eull,0x36367225202c3736ull,0x73090a3b3631202cull,0x6465726168732e74ull,
0x255b09203631732eull,0x3633312b31316472ull,0x3b37367225202c5dull,0x3309636f6c2e090aull,
0x090a300934303209ull,0x203233732e627573ull,0x25202c3836722509ull,0x357225202c323572ull,
0x2e766f6d090a3b33ull,0x3672250920323373ull,0x3037313332202c39ull,0x34326c756d090a3bull,
0x203233732e6f6c2eull,0x25202c3037722509ull,0x367225202c383672ull,0x2e646461090a3b39ull,
0x3772250920323373ull,0x2c30377225202c31ull,0x0a3b383637323320ull,0x3233732e72687309ull,
0x202c323772250920ull,0x3631202c31377225ull,0x68732e7473090a3bull,0x3631732e64657261ull,
0x31316472255b0920ull,0x25202c5d3237322bull,0x6c2e090a3b323772ull,0x363032093309636full,
0x2e766f6d090a3009ull,0x3772250920323373ull,0x3034353231202c33ull,0x34326c756d090a3bull,
0x203233732e6f6c2eull,0x25202c3437722509ull,0x377225202c393572ull,0x2e766f6d090a3b33ull,
0x3772250920323373ull,0x3437323033202c35ull,0x34326c756d090a3bull,0x203233732e6f6c2eull,
0x25202c3637722509ull,0x377225202c303672ull,0x2e627573090a3b35ull,0x3772250920323373ull,
0x2c34377225202c37ull,0x090a3b3637722520ull,0x203233732e646461ull,0x25202c3837722509ull,
0x373233202c373772ull,0x726873090a3b3836ull,0x722509203233732eull,0x38377225202c3937ull,
0x73090a3b3631202cull,0x6465726168732e74ull,0x255b09203631732eull,0x3830342b31316472ull,
0x3b39377225202c5dull,0x3309636f6c2e090aull,0x090a300939303209ull,0x203233732e627573ull,
0x25202c3038722509ull,0x347225202c313472ull,0x2e627573090a3b36ull,0x3872250920323373ull,
0x2c32347225202c31ull,0x090a3b3534722520ull,0x203233732e627573ull,0x25202c3238722509ull,
0x347225202c333472ull,0x2e627573090a3b34ull,0x3872250920323373ull,0x2c30347225202c33ull,
0x090a3b3734722520ull,0x203233732e627573ull,0x25202c3438722509ull,0x387225202c303872ull,
0x2e646461090a3b31ull,0x3872250920323373ull,0x2c30387225202c35ull,0x090a3b3138722520ull,
0x203233622e6c6873ull,0x25202c3638722509ull,0x0a3b32202c323872ull,0x3233622e6c687309ull,
0x202c373872250920ull,0x3b32202c33387225ull,0x33732e766f6d090aull,0x2c38387225092032ull,
0x0a3b303731333220ull,0x6c2e34326c756d09ull,0x2509203233732e6full,0x387225202c393872ull,
0x3b38387225202c34ull,0x33732e766f6d090aull,0x2c30397225092032ull,0x0a3b303731333220ull,
0x6c2e34326c756d09ull,0x2509203233732e6full,0x387225202c313972ull,0x3b30397225202c35ull,
0x33732e646461090aull,0x2c32397225092032ull,0x34202c3938722520ull,0x6461090a3b363930ull,
0x2509203233732e64ull,0x397225202c333972ull,0x3b36393034202c31ull,0x33732e726873090aull,
0x2c34397225092032ull,0x31202c3239722520ull,0x2e726873090a3b33ull,0x3972250920323373ull,
0x2c33397225202c35ull,0x6461090a3b333120ull,0x2509203233732e64ull,0x387225202c363972ull,
0x3b34397225202c36ull,0x33732e646461090aull,0x2c37397225092032ull,0x25202c3738722520ull,
0x6f6d090a3b353972ull,0x2509203233732e76ull,0x393531202c383972ull,0x326c756d090a3b38ull,
0x3233732e6f6c2e34ull,0x202c393972250920ull,0x7225202c36397225ull,0x766f6d090a3b3839ull,
0x722509203233732eull,0x333038202c303031ull,0x326c756d090a3b35ull,0x3233732e6f6c2e34ull,
0x2c31303172250920ull,0x25202c3739722520ull,0x61090a3b30303172ull,0x09203233732e6464ull,
0x25202c3230317225ull,0x317225202c393972ull,0x646461090a3b3130ull,0x722509203233732eull,
0x317225202c333031ull,0x36373233202c3230ull,0x2e726873090a3b38ull,0x3172250920323373ull,
0x30317225202c3430ull,0x090a3b3631202c33ull,0x65726168732e7473ull,0x5b09203631732e64ull,
0x38362b3131647225ull,0x3430317225202c5dull,0x09636f6c2e090a3bull,0x0a30093131320933ull,
0x3233732e62757309ull,0x2c35303172250920ull,0x25202c3638722520ull,0x7573090a3b343972ull,
0x2509203233732e62ull,0x7225202c36303172ull,0x35397225202c3738ull,0x732e766f6d090a3bull,
0x3031722509203233ull,0x3b31313836202c37ull,0x2e34326c756d090aull,0x09203233732e6f6cull,
0x25202c3830317225ull,0x7225202c36303172ull,0x6f6d090a3b373031ull,0x2509203233732e76ull,
0x3534202c39303172ull,0x6c756d090a3b3135ull,0x33732e6f6c2e3432ull,0x3031317225092032ull,
0x2c3530317225202cull,0x0a3b393031722520ull,0x3233732e62757309ull,0x2c31313172250920ull,
0x202c383031722520ull,0x090a3b3031317225ull,0x203233732e646461ull,0x202c323131722509ull,
0x33202c3131317225ull,0x73090a3b38363732ull,0x09203233732e7268ull,0x25202c3331317225ull,
0x3631202c32313172ull,0x68732e7473090a3bull,0x3631732e64657261ull,0x31316472255b0920ull,
0x25202c5d3430322bull,0x2e090a3b33313172ull,0x3132093309636f6cull,0x766f6d090a300933ull,
0x722509203233732eull,0x313836202c343131ull,0x326c756d090a3b31ull,0x3233732e6f6c2e34ull,
0x2c35313172250920ull,0x202c353031722520ull,0x090a3b3431317225ull,0x203233732e766f6dull,
0x202c363131722509ull,0x6d090a3b31353534ull,0x2e6f6c2e34326c75ull,0x3172250920323373ull,
0x30317225202c3731ull,0x3631317225202c36ull,0x732e646461090a3bull,0x3131722509203233ull,
0x3531317225202c38ull,0x3b3731317225202cull,0x33732e646461090aull,0x3931317225092032ull,
0x2c3831317225202cull,0x0a3b383637323320ull,0x3233732e72687309ull,0x2c30323172250920ull,
0x202c393131722520ull,0x2e7473090a3b3631ull,0x732e646572616873ull,0x6472255b09203631ull,
0x2c5d3034332b3131ull,0x0a3b303231722520ull,0x093309636f6c2e09ull,0x6d090a3009353132ull,
0x09203233732e766full,0x31202c3132317225ull,0x756d090a3b383935ull,0x732e6f6c2e34326cull,
0x3231722509203233ull,0x2c37397225202c32ull,0x0a3b313231722520ull,0x3233732e766f6d09ull,
0x2c33323172250920ull,0x090a3b3533303820ull,0x6f6c2e34326c756dull,0x722509203233732eull,
0x397225202c343231ull,0x3332317225202c36ull,0x732e627573090a3bull,0x3231722509203233ull,
0x3232317225202c35ull,0x3b3432317225202cull,0x33732e646461090aull,0x3632317225092032ull,
0x2c3532317225202cull,0x0a3b383637323320ull,0x3233732e72687309ull,0x2c37323172250920ull,
0x202c363231722520ull,0x2e7473090a3b3631ull,0x732e646572616873ull,0x6472255b09203631ull,
0x2c5d3637342b3131ull,0x0a3b373231722520ull,0x093309636f6c2e09ull,0x62090a3009383435ull,
0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x0936333209330963ull,0x6c2e6c756d090a30ull,
0x2509203233752e6full,0x7225202c38323172ull,0x63090a3b32202c32ull,0x752e3436752e7476ull,
0x3164722509203233ull,0x3832317225202c32ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,
0x7225202c39323172ull,0x090a3b3836202c36ull,0x2e3436752e747663ull,0x6472250920323375ull,
0x32317225202c3331ull,0x2e646461090a3b39ull,0x6472250920343675ull,0x31647225202c3431ull,
0x3331647225202c32ull,0x752e646461090a3bull,0x3164722509203436ull,0x2c31647225202c35ull,
0x0a3b343164722520ull,0x726168732e646c09ull,0x09203233752e6465ull,0x5b202c3033317225ull,
0x5d302b3531647225ull,0x09636f6c2e090a3bull,0x0a30093733320933ull,0x726168732e646c09ull,
0x09203233752e6465ull,0x5b202c3133317225ull,0x5d342b3531647225ull,0x09636f6c2e090a3bull,
0x0a30093833320933ull,0x726168732e646c09ull,0x09203233752e6465ull,0x5b202c3233317225ull,
0x5d382b3531647225ull,0x09636f6c2e090a3bull,0x0a30093933320933ull,0x726168732e646c09ull,
0x09203233752e6465ull,0x5b202c3333317225ull,0x32312b3531647225ull,0x636f6c2e090a3b5dull,
0x3009333532093309ull,0x33732e766f6d090aull,0x3433317225092032ull,0x3b3133317225202cull,
0x33732e726873090aull,0x3533317225092032ull,0x2c3433317225202cull,0x6873090a3b363120ull,
0x2509203233622e6cull,0x7225202c36333172ull,0x3b3631202c323331ull,0x33732e726873090aull,
0x3733317225092032ull,0x2c3633317225202cull,0x7573090a3b363120ull,0x2509203233732e62ull,
0x7225202c38333172ull,0x317225202c353331ull,0x6f6c2e090a3b3733ull,0x0934353209330963ull,
0x622e6c6873090a30ull,0x3331722509203233ull,0x3133317225202c39ull,0x73090a3b3631202cull,
0x09203233732e7268ull,0x25202c3034317225ull,0x3631202c39333172ull,0x732e766f6d090a3bull,
0x3431722509203233ull,0x3233317225202c31ull,0x732e726873090a3bull,0x3431722509203233ull,
0x3134317225202c32ull,0x73090a3b3631202cull,0x09203233732e6275ull,0x25202c3334317225ull,
0x7225202c30343172ull,0x6c2e090a3b323431ull,0x353532093309636full,0x2e766f6d090a3009ull,
0x3172250920323373ull,0x33317225202c3434ull,0x2e726873090a3b30ull,0x3172250920323373ull,
0x34317225202c3534ull,0x090a3b3631202c34ull,0x203233622e6c6873ull,0x202c363431722509ull,
0x31202c3333317225ull,0x2e726873090a3b36ull,0x3172250920323373ull,0x34317225202c3734ull,
0x090a3b3631202c36ull,0x203233732e627573ull,0x202c383431722509ull,0x25202c3534317225ull,
0x2e090a3b37343172ull,0x3532093309636f6cull,0x6c6873090a300936ull,0x722509203233622eull,
0x317225202c393431ull,0x0a3b3631202c3033ull,0x3233732e72687309ull,0x2c30353172250920ull,
0x202c393431722520ull,0x766f6d090a3b3631ull,0x722509203233732eull,0x317225202c313531ull,
0x726873090a3b3333ull,0x722509203233732eull,0x317225202c323531ull,0x0a3b3631202c3135ull,
0x3233732e62757309ull,0x2c33353172250920ull,0x202c303531722520ull,0x090a3b3235317225ull,
0x32093309636f6c2eull,0x6461090a30093835ull,0x2509203233732e64ull,0x7225202c34353172ull,
0x317225202c353331ull,0x646461090a3b3733ull,0x722509203233732eull,0x317225202c353531ull,
0x35317225202c3035ull,0x2e646461090a3b32ull,0x3172250920323373ull,0x35317225202c3635ull,
0x3535317225202c34ull,0x09636f6c2e090a3bull,0x0a30093036320933ull,0x3233732e64646109ull,
0x2c37353172250920ull,0x202c303431722520ull,0x090a3b3234317225ull,0x203233732e646461ull,
0x202c383531722509ull,0x25202c3534317225ull,0x73090a3b37343172ull,0x09203233732e6275ull,
0x25202c3935317225ull,0x7225202c38353172ull,0x6c2e090a3b373531ull,0x313632093309636full,
0x2e627573090a3009ull,0x3172250920323373ull,0x35317225202c3036ull,0x3435317225202c35ull,
0x09636f6c2e090a3bull,0x0a30093336320933ull,0x3233732e64646109ull,0x2c31363172250920ull,
0x202c373531722520ull,0x090a3b3835317225ull,0x203233732e646461ull,0x202c323631722509ull,
0x25202c3635317225ull,0x6d090a3b31363172ull,0x09203233732e766full,0x32202c3336317225ull,
0x6d090a3b30373133ull,0x2e6f6c2e34326c75ull,0x3172250920323373ull,0x36317225202c3436ull,
0x3336317225202c32ull,0x732e646461090a3bull,0x3631722509203233ull,0x3436317225202c35ull,
0x3b3836373233202cull,0x33732e726873090aull,0x3636317225092032ull,0x2c3536317225202cull,
0x6e61090a3b363120ull,0x2509203233622e64ull,0x7225202c37363172ull,0x35362d202c303331ull,
0x6e61090a3b363335ull,0x2509203233622e64ull,0x7225202c38363172ull,0x353536202c363631ull,
0x766f6d090a3b3533ull,0x722509203233732eull,0x317225202c383631ull,0x2e726f090a3b3836ull,
0x3172250920323362ull,0x36317225202c3033ull,0x3836317225202c37ull,0x09636f6c2e090a3bull,
0x0a30093436320933ull,0x3233732e766f6d09ull,0x2c39363172250920ull,0x0a3b303331722520ull,
0x3233732e72687309ull,0x2c35343172250920ull,0x202c393631722520ull,0x646461090a3b3631ull,
0x722509203233732eull,0x317225202c383531ull,0x34317225202c3534ull,0x2e646461090a3b37ull,
0x3172250920323373ull,0x35317225202c3037ull,0x3835317225202c37ull,0x732e627573090a3bull,
0x3731722509203233ull,0x3635317225202c31ull,0x3b3037317225202cull,0x33732e766f6d090aull,
0x3237317225092032ull,0x3b3037313332202cull,0x2e34326c756d090aull,0x09203233732e6f6cull,
0x25202c3337317225ull,0x7225202c31373172ull,0x6461090a3b323731ull,0x2509203233732e64ull,
0x7225202c34373172ull,0x373233202c333731ull,0x726873090a3b3836ull,0x722509203233732eull,
0x317225202c353731ull,0x0a3b3631202c3437ull,0x3233622e646e6109ull,0x2c36373172250920ull,
0x202c323331722520ull,0x0a3b36333535362dull,0x3233622e646e6109ull,0x2c37373172250920ull,
0x202c353731722520ull,0x090a3b3533353536ull,0x203233732e766f6dull,0x202c373731722509ull,
0x090a3b3737317225ull,0x09203233622e726full,0x25202c3233317225ull,0x7225202c36373172ull,
0x6c2e090a3b373731ull,0x363632093309636full,0x2e766f6d090a3009ull,0x3172250920323373ull,
0x37323033202c3837ull,0x326c756d090a3b34ull,0x3233732e6f6c2e34ull,0x2c39373172250920ull,
0x202c303631722520ull,0x090a3b3837317225ull,0x203233732e766f6dull,0x202c303831722509ull,
0x090a3b3233317225ull,0x203233732e726873ull,0x202c313831722509ull,0x31202c3038317225ull,
0x2e646461090a3b36ull,0x3172250920323373ull,0x34317225202c3238ull,0x3138317225202c30ull,
0x732e627573090a3bull,0x3831722509203233ull,0x3835317225202c33ull,0x3b3238317225202cull,
0x33732e766f6d090aull,0x3438317225092032ull,0x3b3034353231202cull,0x2e34326c756d090aull,
0x09203233732e6f6cull,0x25202c3538317225ull,0x7225202c33383172ull,0x6461090a3b343831ull,
0x2509203233732e64ull,0x7225202c36383172ull,0x317225202c393731ull,0x646461090a3b3538ull,
0x722509203233732eull,0x317225202c373831ull,0x36373233202c3638ull,0x2e726873090a3b38ull,
0x3172250920323373ull,0x38317225202c3838ull,0x090a3b3631202c37ull,0x203233622e646e61ull,
0x202c393831722509ull,0x2d202c3133317225ull,0x090a3b3633353536ull,0x203233622e646e61ull,
0x202c303931722509ull,0x36202c3838317225ull,0x6d090a3b35333535ull,0x09203233732e766full,
0x25202c3039317225ull,0x6f090a3b30393172ull,0x2509203233622e72ull,0x7225202c31333172ull,
0x317225202c393831ull,0x6f6c2e090a3b3039ull,0x0937363209330963ull,0x732e766f6d090a30ull,
0x3931722509203233ull,0x3034353231202c31ull,0x34326c756d090a3bull,0x203233732e6f6c2eull,
0x202c323931722509ull,0x25202c3036317225ull,0x6d090a3b31393172ull,0x09203233732e766full,
0x33202c3339317225ull,0x6d090a3b34373230ull,0x2e6f6c2e34326c75ull,0x3172250920323373ull,
0x35317225202c3439ull,0x3339317225202c39ull,0x732e627573090a3bull,0x3931722509203233ull,
0x3239317225202c35ull,0x3b3439317225202cull,0x33732e646461090aull,0x3639317225092032ull,
0x2c3539317225202cull,0x0a3b383637323320ull,0x3233732e72687309ull,0x2c37393172250920ull,
0x202c363931722520ull,0x646e61090a3b3631ull,0x722509203233622eull,0x317225202c383931ull,
0x3535362d202c3333ull,0x646e61090a3b3633ull,0x722509203233622eull,0x317225202c393931ull,
0x33353536202c3739ull,0x2e766f6d090a3b35ull,0x3172250920323373ull,0x39317225202c3939ull,
0x622e726f090a3b39ull,0x3331722509203233ull,0x3839317225202c33ull,0x3b3939317225202cull,
0x3309636f6c2e090aull,0x090a300930383209ull,0x203233732e646461ull,0x202c303032722509ull,
0x25202c3334317225ull,0x73090a3b38343172ull,0x09203233622e6c68ull,0x25202c3130327225ull,
0x3b32202c33353172ull,0x33732e627573090aull,0x3230327225092032ull,0x2c3834317225202cull,
0x0a3b333431722520ull,0x3233622e6c687309ull,0x2c33303272250920ull,0x202c383331722520ull,
0x2e766f6d090a3b32ull,0x3272250920323373ull,0x37313332202c3430ull,0x326c756d090a3b30ull,
0x3233732e6f6c2e34ull,0x2c35303272250920ull,0x202c303032722520ull,0x090a3b3430327225ull,
0x203233732e766f6dull,0x202c363032722509ull,0x090a3b3037313332ull,0x6f6c2e34326c756dull,
0x722509203233732eull,0x327225202c373032ull,0x30327225202c3230ull,0x2e646461090a3b36ull,
0x3272250920323373ull,0x30327225202c3830ull,0x3b36393034202c35ull,0x33732e646461090aull,
0x3930327225092032ull,0x2c3730327225202cull,0x090a3b3639303420ull,0x203233732e726873ull,
0x202c303132722509ull,0x31202c3830327225ull,0x2e726873090a3b33ull,0x3272250920323373ull,
0x30327225202c3131ull,0x090a3b3331202c39ull,0x203233732e646461ull,0x202c323132722509ull,
0x25202c3130327225ull,0x61090a3b30313272ull,0x09203233732e6464ull,0x25202c3331327225ull,
0x7225202c33303272ull,0x6f6d090a3b313132ull,0x2509203233732e76ull,0x3038202c34313272ull,
0x6c756d090a3b3533ull,0x33732e6f6c2e3432ull,0x3531327225092032ull,0x2c3231327225202cull,
0x0a3b343132722520ull,0x3233732e766f6d09ull,0x2c36313272250920ull,0x090a3b3839353120ull,
0x6f6c2e34326c756dull,0x722509203233732eull,0x327225202c373132ull,0x31327225202c3331ull,
0x2e646461090a3b36ull,0x3272250920323373ull,0x31327225202c3831ull,0x3731327225202c35ull,
0x732e646461090a3bull,0x3132722509203233ull,0x3831327225202c39ull,0x3b3836373233202cull,
0x33732e726873090aull,0x3032327225092032ull,0x2c3931327225202cull,0x6e61090a3b363120ull,
0x2509203233622e64ull,0x7225202c31323272ull,0x353536202c303331ull,0x646e61090a3b3533ull,
0x722509203233622eull,0x327225202c323232ull,0x33353536202c3032ull,0x2e6c6873090a3b35ull,
0x3272250920323362ull,0x32327225202c3232ull,0x090a3b3631202c32ull,0x09203233622e726full,
0x25202c3033317225ull,0x7225202c31323272ull,0x6c2e090a3b323232ull,0x313832093309636full,
0x2e766f6d090a3009ull,0x3272250920323373ull,0x38393531202c3332ull,0x34326c756d090a3bull,
0x203233732e6f6c2eull,0x202c343232722509ull,0x25202c3231327225ull,0x6d090a3b33323272ull,
0x09203233732e766full,0x38202c3532327225ull,0x756d090a3b353330ull,0x732e6f6c2e34326cull,
0x3232722509203233ull,0x3331327225202c36ull,0x3b3532327225202cull,0x33732e627573090aull,
0x3732327225092032ull,0x2c3432327225202cull,0x0a3b363232722520ull,0x3233732e64646109ull,
0x2c38323272250920ull,0x202c373232722520ull,0x090a3b3836373233ull,0x203233732e726873ull,
0x202c393232722509ull,0x31202c3832327225ull,0x2e646e61090a3b36ull,0x3272250920323362ull,
0x33317225202c3033ull,0x3533353536202c33ull,0x622e646e61090a3bull,0x3332722509203233ull,
0x3932327225202c31ull,0x3b3533353536202cull,0x33622e6c6873090aull,0x3133327225092032ull,
0x2c3133327225202cull,0x726f090a3b363120ull,0x722509203233622eull,0x327225202c333331ull,
0x33327225202c3033ull,0x636f6c2e090a3b31ull,0x3009323832093309ull,0x33732e627573090aull,
0x3233327225092032ull,0x2c3130327225202cull,0x0a3b303132722520ull,0x3233732e62757309ull,
0x2c33333272250920ull,0x202c333032722520ull,0x090a3b3131327225ull,0x203233732e766f6dull,
0x202c343332722509ull,0x6d090a3b31353534ull,0x2e6f6c2e34326c75ull,0x3272250920323373ull,
0x33327225202c3533ull,0x3433327225202c32ull,0x732e766f6d090a3bull,0x3332722509203233ull,
0x3b31313836202c36ull,0x2e34326c756d090aull,0x09203233732e6f6cull,0x25202c3733327225ull,
0x7225202c33333272ull,0x6461090a3b363332ull,0x2509203233732e64ull,0x7225202c38333272ull,
0x327225202c353332ull,0x646461090a3b3733ull,0x722509203233732eull,0x327225202c393332ull,
0x36373233202c3833ull,0x2e726873090a3b38ull,0x3272250920323373ull,0x33327225202c3034ull,
0x090a3b3631202c39ull,0x203233622e646e61ull,0x202c313432722509ull,0x36202c3233317225ull,
0x61090a3b35333535ull,0x09203233622e646eull,0x25202c3234327225ull,0x3536202c30343272ull,
0x6873090a3b353335ull,0x2509203233622e6cull,0x7225202c32343272ull,0x3b3631202c323432ull,
0x3233622e726f090aull,0x2c32333172250920ull,0x202c313432722520ull,0x090a3b3234327225ull,
0x32093309636f6c2eull,0x6f6d090a30093338ull,0x2509203233732e76ull,0x3836202c33343272ull,
0x6c756d090a3b3131ull,0x33732e6f6c2e3432ull,0x3434327225092032ull,0x2c3233327225202cull,
0x0a3b333432722520ull,0x3233732e766f6d09ull,0x2c35343272250920ull,0x090a3b3135353420ull,
0x6f6c2e34326c756dull,0x722509203233732eull,0x327225202c363432ull,0x34327225202c3333ull,
0x2e627573090a3b35ull,0x3272250920323373ull,0x34327225202c3734ull,0x3634327225202c34ull,
0x732e646461090a3bull,0x3432722509203233ull,0x3734327225202c38ull,0x3b3836373233202cull,
0x33732e726873090aull,0x3934327225092032ull,0x2c3834327225202cull,0x6e61090a3b363120ull,
0x2509203233622e64ull,0x7225202c30353272ull,0x353536202c313331ull,0x646e61090a3b3533ull,
0x722509203233622eull,0x327225202c313532ull,0x33353536202c3934ull,0x2e6c6873090a3b35ull,
0x3272250920323362ull,0x35327225202c3135ull,0x090a3b3631202c31ull,0x09203233622e726full,
0x25202c3133317225ull,0x7225202c30353272ull,0x6c2e090a3b313532ull,0x353832093309636full,
0x732e7473090a3009ull,0x33752e6465726168ull,0x316472255b092032ull,0x7225202c5d302b35ull,
0x6c2e090a3b303331ull,0x363832093309636full,0x732e7473090a3009ull,0x33752e6465726168ull,
0x316472255b092032ull,0x7225202c5d342b35ull,0x6c2e090a3b313331ull,0x373832093309636full,
0x732e7473090a3009ull,0x33752e6465726168ull,0x316472255b092032ull,0x7225202c5d382b35ull,
0x6c2e090a3b323331ull,0x383832093309636full,0x732e7473090a3009ull,0x33752e6465726168ull,
0x316472255b092032ull,0x25202c5d32312b35ull,0x2e090a3b33333172ull,0x3535093309636f6cull,
0x726162090a300930ull,0x300920636e79732eull,0x3170252140090a3bull,0x4c24092061726220ull,
0x363033325f345f74ull,0x09636f6c2e090a3bull,0x0a30093535350933ull,0x726168732e646c09ull,
0x09203233732e6465ull,0x5b202c3235327225ull,0x3b5d302b36647225ull,0x6f6c672e7473090aull,
0x203233732e6c6162ull,0x302b346472255b09ull,0x3235327225202c5dull,0x09636f6c2e090a3bull,
0x0a30093230350933ull,0x617261702e646c09ull,0x2509203233732e6dull,0x635f5f5b202c3872ull,
0x5f6d726170616475ull,0x4144554338315a5full,0x68536c656e72656bull,0x735054434474726full,
0x727453676d495f69ull,0x2e090a3b5d656469ull,0x3535093309636f6cull,0x6c756d090a300936ull,
0x203233752e6f6c2eull,0x202c333532722509ull,0x0a3b32202c387225ull,0x3436752e74766309ull,
0x722509203233752eull,0x327225202c363164ull,0x627573090a3b3335ull,0x722509203436752eull,
0x34647225202c3464ull,0x3b3631647225202cull,0x3309636f6c2e090aull,0x090a300939353509ull,
0x65726168732e646cull,0x2509203233732e64ull,0x255b202c34353272ull,0x5d38362d2b366472ull,
0x6c672e7473090a3bull,0x3233732e6c61626full,0x2b346472255b0920ull,0x35327225202c5d30ull,
0x636f6c2e090a3b34ull,0x3009303635093309ull,0x36752e627573090aull,0x2c34647225092034ull,
0x25202c3464722520ull,0x2e090a3b36316472ull,0x3635093309636f6cull,0x2e646c090a300933ull,
0x732e646572616873ull,0x3532722509203233ull,0x366472255b202c35ull,0x0a3b5d3633312d2bull,
0x626f6c672e747309ull,0x09203233732e6c61ull,0x5d302b346472255bull,0x3b3535327225202cull,
0x3309636f6c2e090aull,0x090a300934363509ull,0x203436752e627573ull,0x25202c3464722509ull,
0x647225202c346472ull,0x6f6c2e090a3b3631ull,0x0937363509330963ull,0x68732e646c090a30ull,
0x3233732e64657261ull,0x2c36353272250920ull,0x2d2b366472255b20ull,0x73090a3b5d343032ull,
0x6c61626f6c672e74ull,0x255b09203233732eull,0x202c5d302b346472ull,0x090a3b3635327225ull,
0x35093309636f6c2eull,0x7573090a30093836ull,0x2509203436752e62ull,0x647225202c346472ull,
0x3631647225202c34ull,0x09636f6c2e090a3bull,0x0a30093137350933ull,0x726168732e646c09ull,
0x09203233732e6465ull,0x5b202c3735327225ull,0x37322d2b36647225ull,0x2e7473090a3b5d32ull,
0x732e6c61626f6c67ull,0x6472255b09203233ull,0x7225202c5d302b34ull,0x6c2e090a3b373532ull,
0x323735093309636full,0x2e627573090a3009ull,0x6472250920343675ull,0x2c34647225202c34ull,
0x0a3b363164722520ull,0x093309636f6c2e09ull,0x6c090a3009353735ull,0x6465726168732e64ull,
0x722509203233732eull,0x72255b202c383532ull,0x5d3034332d2b3664ull,0x6c672e7473090a3bull,
0x3233732e6c61626full,0x2b346472255b0920ull,0x35327225202c5d30ull,0x636f6c2e090a3b38ull,
0x3009363735093309ull,0x36752e627573090aull,0x2c34647225092034ull,0x25202c3464722520ull,
0x2e090a3b36316472ull,0x3735093309636f6cull,0x2e646c090a300939ull,0x732e646572616873ull,
0x3532722509203233ull,0x366472255b202c39ull,0x0a3b5d3830342d2bull,0x626f6c672e747309ull,
0x09203233732e6c61ull,0x5d302b346472255bull,0x3b3935327225202cull,0x3309636f6c2e090aull,
0x090a300933383509ull,0x65726168732e646cull,0x2509203233732e64ull,0x255b202c30363272ull,
0x3637342d2b366472ull,0x2e627573090a3b5dull,0x6472250920343675ull,0x34647225202c3731ull,
0x3b3631647225202cull,0x6f6c672e7473090aull,0x203233732e6c6162ull,0x2b37316472255b09ull,
0x36327225202c5d30ull,0x345f744c240a3b30ull,0x090a3a363033325full,0x35093309636f6c2eull,
0x7865090a30093538ull,0x57444c240a3b7469ull,0x38315a5f5f646e65ull,0x6e72656b41445543ull,
0x4474726f68536c65ull,0x090a3a6973505443ull,0x315a5f202f2f207dull,0x72656b4144554338ull,
0x74726f68536c656eull,0x0a0a697350544344ull,0x207972746e652e09ull,0x4144554339315a5full,
0x68536c656e72656bull,0x505443444974726full,0x2e09090a28206973ull,0x752e206d61726170ull,
0x6475635f5f203436ull,0x5a5f5f6d72617061ull,0x656b414455433931ull,0x726f68536c656e72ull,
0x6973505443444974ull,0x705f6c61765f5f5full,0x446372536d617261ull,0x702e09090a2c7473ull,
0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x72656b4144554339ull,
0x74726f68536c656eull,0x5f69735054434449ull,0x6469727453676d49ull,0x2e090a7b090a2965ull,
0x3233752e20676572ull,0x3e3336323c722520ull,0x206765722e090a3bull,0x647225203436752eull,
0x2e090a3b3e39313cull,0x6572702e20676572ull,0x3b3e333c70252064ull,0x65726168732e090aull,
0x6e67696c612e2064ull,0x5f2038622e203220ull,0x6c625f616475635full,0x5b303230376b636full,
0x090a3b5d36373132ull,0x36093309636f6c2eull,0x424c240a30093130ull,0x4339315a5f5f3142ull,
0x656e72656b414455ull,0x444974726f68536cull,0x090a3a6973505443ull,0x203436752e766f6dull,
0x5f202c3164722509ull,0x6c625f616475635full,0x3b303230376b636full,0x3309636f6c2e090aull,
0x090a300934343609ull,0x2e3233732e747663ull,0x3172250920363175ull,0x7a2e64697425202cull,
0x622e6c6873090a3bull,0x2c32722509203233ull,0x3b33202c31722520ull,0x33732e747663090aull,
0x2509203631752e32ull,0x64697425202c3372ull,0x6c6873090a3b792eull,0x722509203233622eull,
0x202c337225202c34ull,0x2e747663090a3b33ull,0x203631752e323375ull,0x7425202c35722509ull,
0x61090a3b782e6469ull,0x09203233752e6464ull,0x347225202c367225ull,0x090a3b357225202cull,
0x203233622e6c6873ull,0x7225202c37722509ull,0x6c090a3b31202c36ull,0x2e6d617261702e64ull,
0x3872250920323373ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x656b414455433931ull,
0x726f68536c656e72ull,0x6973505443444974ull,0x69727453676d495full,0x7663090a3b5d6564ull,
0x31752e3233732e74ull,0x202c397225092036ull,0x792e646961746325ull,0x622e6c6873090a3bull,
0x3031722509203233ull,0x35202c397225202cull,0x732e646461090a3bull,0x3131722509203233ull,
0x25202c327225202cull,0x756d090a3b303172ull,0x732e6f6c2e34326cull,0x3231722509203233ull,
0x202c31317225202cull,0x7663090a3b387225ull,0x31752e3233732e74ull,0x2c33317225092036ull,
0x2e64696174632520ull,0x2e6c6873090a3b78ull,0x3172250920323362ull,0x2c33317225202c34ull,
0x646461090a3b3520ull,0x722509203233732eull,0x32317225202c3531ull,0x0a3b34317225202cull,
0x3233732e64646109ull,0x202c363172250920ull,0x317225202c377225ull,0x2e6c756d090a3b35ull,
0x09203233752e6f6cull,0x7225202c37317225ull,0x090a3b32202c3631ull,0x2e3436752e747663ull,
0x6472250920323375ull,0x3b37317225202c32ull,0x7261702e646c090aull,0x09203436752e6d61ull,
0x5f5b202c33647225ull,0x726170616475635full,0x554339315a5f5f6dull,0x6c656e72656b4144ull,
0x43444974726f6853ull,0x765f5f5f69735054ull,0x6d617261705f6c61ull,0x3b5d747344637253ull,
0x36752e646461090aull,0x2c34647225092034ull,0x25202c3264722520ull,0x6c2e090a3b336472ull,
0x323536093309636full,0x2e766f6d090a3009ull,0x3172250920323373ull,0x090a3b3433202c38ull,
0x6f6c2e34326c756dull,0x722509203233732eull,0x2c327225202c3931ull,0x090a3b3831722520ull,
0x203233732e646461ull,0x25202c3032722509ull,0x39317225202c3772ull,0x6c2e6c756d090a3bull,
0x2509203233752e6full,0x327225202c313272ull,0x63090a3b32202c30ull,0x752e3436752e7476ull,
0x3564722509203233ull,0x0a3b31327225202cull,0x3436752e64646109ull,0x202c366472250920ull,
0x7225202c35647225ull,0x766f6d090a3b3164ull,0x722509203233732eull,0x0a3b3531202c3232ull,
0x656c2e7074657309ull,0x702509203233732eull,0x202c367225202c31ull,0x40090a3b32327225ull,
0x6172622031702521ull,0x5f355f744c240920ull,0x2e090a3b34393731ull,0x3536093309636f6cull,
0x2e646c090a300937ull,0x732e6c61626f6c67ull,0x3332722509203233ull,0x2b346472255b202cull,
0x2e7473090a3b5d30ull,0x732e646572616873ull,0x6472255b09203233ull,0x7225202c5d302b36ull,
0x6f6c2e090a3b3332ull,0x0934343609330963ull,0x61702e646c090a30ull,0x203233732e6d6172ull,
0x5f5b202c38722509ull,0x726170616475635full,0x554339315a5f5f6dull,0x6c656e72656b4144ull,
0x43444974726f6853ull,0x676d495f69735054ull,0x3b5d656469727453ull,0x3309636f6c2e090aull,
0x090a300938353609ull,0x752e6f6c2e6c756dull,0x3432722509203233ull,0x32202c387225202cull,
0x752e747663090a3bull,0x09203233752e3436ull,0x7225202c37647225ull,0x646461090a3b3432ull,
0x722509203436752eull,0x37647225202c3464ull,0x0a3b34647225202cull,0x093309636f6c2e09ull,
0x6c090a3009313636ull,0x6c61626f6c672e64ull,0x722509203233732eull,0x6472255b202c3532ull,
0x73090a3b5d302b34ull,0x6465726168732e74ull,0x255b09203233732eull,0x2c5d38362b366472ull,
0x090a3b3532722520ull,0x36093309636f6c2eull,0x6461090a30093236ull,0x2509203436752e64ull,
0x647225202c346472ull,0x3b34647225202c37ull,0x3309636f6c2e090aull,0x090a300935363609ull,
0x61626f6c672e646cull,0x2509203233732e6cull,0x72255b202c363272ull,0x090a3b5d302b3464ull,
0x65726168732e7473ull,0x5b09203233732e64ull,0x3633312b36647225ull,0x3b36327225202c5dull,
0x3309636f6c2e090aull,0x090a300936363609ull,0x203436752e646461ull,0x25202c3464722509ull,
0x647225202c376472ull,0x636f6c2e090a3b34ull,0x3009393636093309ull,0x6f6c672e646c090aull,
0x203233732e6c6162ull,0x5b202c3732722509ull,0x3b5d302b34647225ull,0x6168732e7473090aull,
0x203233732e646572ull,0x322b366472255b09ull,0x327225202c5d3430ull,0x636f6c2e090a3b37ull,
0x3009303736093309ull,0x36752e646461090aull,0x2c34647225092034ull,0x25202c3764722520ull,
0x6c2e090a3b346472ull,0x333736093309636full,0x672e646c090a3009ull,0x33732e6c61626f6cull,
0x2c38327225092032ull,0x302b346472255b20ull,0x732e7473090a3b5dull,0x33732e6465726168ull,
0x366472255b092032ull,0x25202c5d3237322bull,0x6c2e090a3b383272ull,0x343736093309636full,
0x2e646461090a3009ull,0x6472250920343675ull,0x2c37647225202c34ull,0x090a3b3464722520ull,
0x36093309636f6c2eull,0x646c090a30093737ull,0x2e6c61626f6c672eull,0x3272250920323373ull,
0x346472255b202c39ull,0x7473090a3b5d302bull,0x2e6465726168732eull,0x72255b0920323373ull,
0x2c5d3034332b3664ull,0x090a3b3932722520ull,0x36093309636f6c2eull,0x6461090a30093837ull,
0x2509203436752e64ull,0x647225202c346472ull,0x3b34647225202c37ull,0x3309636f6c2e090aull,
0x090a300931383609ull,0x61626f6c672e646cull,0x2509203233732e6cull,0x72255b202c303372ull,
0x090a3b5d302b3464ull,0x65726168732e7473ull,0x5b09203233732e64ull,0x3830342b36647225ull,
0x3b30337225202c5dull,0x3309636f6c2e090aull,0x090a300932383609ull,0x203436752e646461ull,
0x25202c3464722509ull,0x647225202c376472ull,0x636f6c2e090a3b34ull,0x3009333836093309ull,
0x36752e646461090aull,0x2c36647225092034ull,0x34202c3664722520ull,0x6f6c2e090a3b3637ull,
0x0935383609330963ull,0x6c672e646c090a30ull,0x3233732e6c61626full,0x202c313372250920ull,
0x5d302b346472255bull,0x68732e7473090a3bull,0x3233732e64657261ull,0x2b366472255b0920ull,
0x31337225202c5d30ull,0x5f355f744c240a3bull,0x2e090a3a34393731ull,0x3836093309636f6cull,
0x726162090a300938ull,0x300920636e79732eull,0x09636f6c2e090a3bull,0x0a30093131330933ull,
0x3233732e72687309ull,0x202c323372250920ull,0x0a3b34202c367225ull,0x3233622e646e6109ull,
0x202c333372250920ull,0x32332d202c367225ull,0x622e646e61090a3bull,0x3433722509203233ull,
0x202c32337225202cull,0x622e726f090a3b31ull,0x3533722509203233ull,0x25202c377225202cull,
0x6e61090a3b343372ull,0x2509203233622e64ull,0x337225202c363372ull,0x090a3b3133202c35ull,
0x09203233622e726full,0x7225202c37337225ull,0x36337225202c3333ull,0x6c2e6c756d090a3bull,
0x2509203233752e6full,0x327225202c383372ull,0x63090a3b3836202cull,0x752e3436752e7476ull,
0x3864722509203233ull,0x0a3b38337225202cull,0x2e6f6c2e6c756d09ull,0x3372250920323375ull,
0x2c37337225202c39ull,0x747663090a3b3220ull,0x3233752e3436752eull,0x202c396472250920ull,
0x61090a3b39337225ull,0x09203436752e6464ull,0x25202c3031647225ull,0x647225202c386472ull,
0x2e646461090a3b39ull,0x6472250920343675ull,0x31647225202c3131ull,0x3b3031647225202cull,
0x6168732e646c090aull,0x203631732e646572ull,0x5b202c3034722509ull,0x5d302b3131647225ull,
0x09636f6c2e090a3bull,0x0a30093331330933ull,0x726168732e646c09ull,0x09203631732e6465ull,
0x255b202c31347225ull,0x5d38362b31316472ull,0x09636f6c2e090a3bull,0x0a30093531330933ull,
0x726168732e646c09ull,0x09203631732e6465ull,0x255b202c32347225ull,0x3633312b31316472ull,
0x636f6c2e090a3b5dull,0x3009373133093309ull,0x6168732e646c090aull,0x203631732e646572ull,
0x5b202c3334722509ull,0x30322b3131647225ull,0x6f6c2e090a3b5d34ull,0x0939313309330963ull,
0x68732e646c090a30ull,0x3631732e64657261ull,0x202c343472250920ull,0x322b31316472255bull,
0x6c2e090a3b5d3237ull,0x313233093309636full,0x732e646c090a3009ull,0x31732e6465726168ull,
0x2c35347225092036ull,0x2b31316472255b20ull,0x2e090a3b5d303433ull,0x3233093309636f6cull,
0x2e646c090a300933ull,0x732e646572616873ull,0x3634722509203631ull,0x31316472255b202cull,
0x090a3b5d3830342bull,0x33093309636f6c2eull,0x646c090a30093532ull,0x2e6465726168732eull,
0x3472250920363173ull,0x316472255b202c37ull,0x0a3b5d3637342b31ull,0x093309636f6c2e09ull,
0x6d090a3009343533ull,0x09203233732e766full,0x3033202c38347225ull,0x756d090a3b343732ull,
0x732e6f6c2e34326cull,0x3934722509203233ull,0x202c32347225202cull,0x6d090a3b38347225ull,
0x09203233732e766full,0x3231202c30357225ull,0x756d090a3b303435ull,0x732e6f6c2e34326cull,
0x3135722509203233ull,0x202c36347225202cull,0x61090a3b30357225ull,0x09203233732e6464ull,
0x7225202c32357225ull,0x34347225202c3034ull,0x732e646461090a3bull,0x3335722509203233ull,
0x202c33347225202cull,0x73090a3b35347225ull,0x09203233622e6c68ull,0x7225202c34357225ull,
0x090a3b32202c3134ull,0x203233732e627573ull,0x25202c3535722509ull,0x347225202c333472ull,
0x2e6c6873090a3b35ull,0x3572250920323362ull,0x2c37347225202c36ull,0x646461090a3b3220ull,
0x722509203233732eull,0x39347225202c3735ull,0x0a3b31357225202cull,0x3233732e766f6d09ull,
0x202c383572250920ull,0x090a3b3037313332ull,0x6f6c2e34326c756dull,0x722509203233732eull,
0x32357225202c3935ull,0x0a3b38357225202cull,0x3233732e766f6d09ull,0x202c303672250920ull,
0x090a3b3037313332ull,0x6f6c2e34326c756dull,0x722509203233732eull,0x33357225202c3136ull,
0x0a3b30367225202cull,0x3233732e766f6d09ull,0x202c323672250920ull,0x090a3b3037313332ull,
0x6f6c2e34326c756dull,0x722509203233732eull,0x35357225202c3336ull,0x0a3b32367225202cull,
0x3233732e64646109ull,0x202c343672250920ull,0x7225202c37357225ull,0x646461090a3b3935ull,
0x722509203233732eull,0x31367225202c3536ull,0x0a3b36393034202cull,0x3233732e64646109ull,
0x202c363672250920ull,0x3034202c33367225ull,0x726873090a3b3639ull,0x722509203233732eull,
0x35367225202c3736ull,0x73090a3b3331202cull,0x09203233732e7268ull,0x7225202c38367225ull,
0x0a3b3331202c3636ull,0x3233732e64646109ull,0x202c393672250920ull,0x7225202c34357225ull,
0x646461090a3b3736ull,0x722509203233732eull,0x36357225202c3037ull,0x0a3b38367225202cull,
0x3233732e766f6d09ull,0x202c313772250920ull,0x6d090a3b35333038ull,0x2e6f6c2e34326c75ull,
0x3772250920323373ull,0x2c39367225202c32ull,0x090a3b3137722520ull,0x203233732e766f6dull,
0x31202c3337722509ull,0x756d090a3b383935ull,0x732e6f6c2e34326cull,0x3437722509203233ull,
0x202c30377225202cull,0x61090a3b33377225ull,0x09203233732e6464ull,0x7225202c35377225ull,
0x34377225202c3237ull,0x732e646461090a3bull,0x3637722509203233ull,0x202c34367225202cull,
0x61090a3b35377225ull,0x09203233732e6464ull,0x7225202c37377225ull,0x36373233202c3637ull,
0x2e726873090a3b38ull,0x3772250920323373ull,0x2c37377225202c38ull,0x7473090a3b363120ull,
0x2e6465726168732eull,0x72255b0920363173ull,0x202c5d302b313164ull,0x2e090a3b38377225ull,
0x3533093309636f6cull,0x627573090a300936ull,0x722509203233732eull,0x30347225202c3937ull,
0x0a3b34347225202cull,0x3233732e766f6d09ull,0x202c303872250920ull,0x090a3b3034353231ull,
0x6f6c2e34326c756dull,0x722509203233732eull,0x32347225202c3138ull,0x0a3b30387225202cull,
0x3233732e766f6d09ull,0x202c323872250920ull,0x090a3b3437323033ull,0x6f6c2e34326c756dull,
0x722509203233732eull,0x36347225202c3338ull,0x0a3b32387225202cull,0x3233732e766f6d09ull,
0x202c343872250920ull,0x090a3b3037313332ull,0x6f6c2e34326c756dull,0x722509203233732eull,
0x39377225202c3538ull,0x0a3b34387225202cull,0x3233732e62757309ull,0x202c363872250920ull,
0x7225202c31387225ull,0x646461090a3b3338ull,0x722509203233732eull,0x35387225202c3738ull,
0x0a3b36387225202cull,0x3233732e62757309ull,0x202c383872250920ull,0x7225202c34357225ull,
0x627573090a3b3736ull,0x722509203233732eull,0x36357225202c3938ull,0x0a3b38367225202cull,
0x3233732e766f6d09ull,0x202c303972250920ull,0x6d090a3b31313836ull,0x2e6f6c2e34326c75ull,
0x3972250920323373ull,0x2c38387225202c31ull,0x090a3b3039722520ull,0x203233732e766f6dull,
0x34202c3239722509ull,0x756d090a3b313535ull,0x732e6f6c2e34326cull,0x3339722509203233ull,
0x202c39387225202cull,0x73090a3b32397225ull,0x09203233732e6275ull,0x7225202c34397225ull,
0x33397225202c3139ull,0x732e646461090a3bull,0x3539722509203233ull,0x202c37387225202cull,
0x61090a3b34397225ull,0x09203233732e6464ull,0x7225202c36397225ull,0x36373233202c3539ull,
0x2e726873090a3b38ull,0x3972250920323373ull,0x2c36397225202c37ull,0x7473090a3b363120ull,
0x2e6465726168732eull,0x72255b0920363173ull,0x2c5d38362b313164ull,0x090a3b3739722520ull,
0x33093309636f6c2eull,0x7573090a30093835ull,0x2509203233732e62ull,0x387225202c383972ull,
0x3b36387225202c35ull,0x33732e766f6d090aull,0x2c39397225092032ull,0x090a3b3135353420ull,
0x6f6c2e34326c756dull,0x722509203233732eull,0x387225202c303031ull,0x3b39397225202c38ull,
0x33732e766f6d090aull,0x3130317225092032ull,0x0a3b31313836202cull,0x6c2e34326c756d09ull,
0x2509203233732e6full,0x7225202c32303172ull,0x30317225202c3938ull,0x2e646461090a3b31ull,
0x3172250920323373ull,0x30317225202c3330ull,0x3230317225202c30ull,0x732e646461090a3bull,
0x3031722509203233ull,0x2c38397225202c34ull,0x0a3b333031722520ull,0x3233732e64646109ull,
0x2c35303172250920ull,0x202c343031722520ull,0x090a3b3836373233ull,0x203233732e726873ull,
0x202c363031722509ull,0x31202c3530317225ull,0x732e7473090a3b36ull,0x31732e6465726168ull,
0x316472255b092036ull,0x202c5d3633312b31ull,0x090a3b3630317225ull,0x33093309636f6c2eull,
0x7573090a30093036ull,0x2509203233732e62ull,0x7225202c37303172ull,0x37357225202c3935ull,
0x732e766f6d090a3bull,0x3031722509203233ull,0x3b38393531202c38ull,0x2e34326c756d090aull,
0x09203233732e6f6cull,0x25202c3930317225ull,0x317225202c393672ull,0x766f6d090a3b3830ull,
0x722509203233732eull,0x333038202c303131ull,0x326c756d090a3b35ull,0x3233732e6f6c2e34ull,
0x2c31313172250920ull,0x25202c3037722520ull,0x73090a3b30313172ull,0x09203233732e6275ull,
0x25202c3231317225ull,0x7225202c39303172ull,0x6461090a3b313131ull,0x2509203233732e64ull,
0x7225202c33313172ull,0x317225202c373031ull,0x646461090a3b3231ull,0x722509203233732eull,
0x317225202c343131ull,0x36373233202c3331ull,0x2e726873090a3b38ull,0x3172250920323373ull,
0x31317225202c3531ull,0x090a3b3631202c34ull,0x65726168732e7473ull,0x5b09203631732e64ull,
0x30322b3131647225ull,0x31317225202c5d34ull,0x636f6c2e090a3b35ull,0x3009323633093309ull,
0x33732e627573090aull,0x3631317225092032ull,0x2c3730317225202cull,0x0a3b323131722520ull,
0x3233732e64646109ull,0x2c37313172250920ull,0x202c363131722520ull,0x090a3b3836373233ull,
0x203233732e726873ull,0x202c383131722509ull,0x31202c3731317225ull,0x732e7473090a3b36ull,
0x31732e6465726168ull,0x316472255b092036ull,0x202c5d3237322b31ull,0x090a3b3831317225ull,
0x33093309636f6c2eull,0x7573090a30093436ull,0x2509203233732e62ull,0x7225202c39313172ull,
0x30317225202c3839ull,0x2e646461090a3b33ull,0x3172250920323373ull,0x31317225202c3032ull,
0x3836373233202c39ull,0x732e726873090a3bull,0x3231722509203233ull,0x3032317225202c31ull,
0x73090a3b3631202cull,0x6465726168732e74ull,0x255b09203631732eull,0x3034332b31316472ull,
0x3132317225202c5dull,0x09636f6c2e090a3bull,0x0a30093636330933ull,0x3233732e62757309ull,
0x2c32323172250920ull,0x25202c3738722520ull,0x6461090a3b343972ull,0x2509203233732e64ull,
0x7225202c33323172ull,0x373233202c323231ull,0x726873090a3b3836ull,0x722509203233732eull,
0x317225202c343231ull,0x0a3b3631202c3332ull,0x726168732e747309ull,0x09203631732e6465ull,
0x342b31316472255bull,0x317225202c5d3830ull,0x6f6c2e090a3b3432ull,0x0938363309330963ull,
0x732e627573090a30ull,0x3231722509203233ull,0x2c34367225202c35ull,0x090a3b3537722520ull,
0x203233732e646461ull,0x202c363231722509ull,0x33202c3532317225ull,0x73090a3b38363732ull,
0x09203233732e7268ull,0x25202c3732317225ull,0x3631202c36323172ull,0x68732e7473090a3bull,
0x3631732e64657261ull,0x31316472255b0920ull,0x25202c5d3637342bull,0x2e090a3b37323172ull,
0x3936093309636f6cull,0x726162090a300930ull,0x300920636e79732eull,0x09636f6c2e090a3bull,
0x0a30093039330933ull,0x2e6f6c2e6c756d09ull,0x3172250920323375ull,0x2c327225202c3832ull,
0x747663090a3b3220ull,0x3233752e3436752eull,0x2c32316472250920ull,0x0a3b383231722520ull,
0x2e6f6c2e6c756d09ull,0x3172250920323375ull,0x2c367225202c3932ull,0x7663090a3b383620ull,
0x33752e3436752e74ull,0x3331647225092032ull,0x3b3932317225202cull,0x36752e646461090aull,
0x3431647225092034ull,0x2c3231647225202cull,0x0a3b333164722520ull,0x3436752e64646109ull,
0x2c35316472250920ull,0x25202c3164722520ull,0x6c090a3b34316472ull,0x6465726168732e64ull,
0x722509203233752eull,0x72255b202c303331ull,0x0a3b5d302b353164ull,0x093309636f6c2e09ull,
0x6c090a3009313933ull,0x6465726168732e64ull,0x722509203233752eull,0x72255b202c313331ull,
0x0a3b5d342b353164ull,0x093309636f6c2e09ull,0x6c090a3009323933ull,0x6465726168732e64ull,
0x722509203233752eull,0x72255b202c323331ull,0x0a3b5d382b353164ull,0x093309636f6c2e09ull,
0x6c090a3009333933ull,0x6465726168732e64ull,0x722509203233752eull,0x72255b202c333331ull,
0x3b5d32312b353164ull,0x3309636f6c2e090aull,0x090a300938303409ull,0x203233622e6c6873ull,
0x202c343331722509ull,0x31202c3133317225ull,0x2e726873090a3b36ull,0x3172250920323373ull,
0x33317225202c3533ull,0x090a3b3631202c34ull,0x203233622e6c6873ull,0x202c363331722509ull,
0x31202c3333317225ull,0x2e726873090a3b36ull,0x3172250920323373ull,0x33317225202c3733ull,
0x090a3b3631202c36ull,0x203233622e6c6873ull,0x202c383331722509ull,0x31202c3033317225ull,
0x2e726873090a3b36ull,0x3172250920323373ull,0x33317225202c3933ull,0x090a3b3631202c38ull,
0x203233622e6c6873ull,0x202c303431722509ull,0x31202c3233317225ull,0x2e726873090a3b36ull,
0x3172250920323373ull,0x34317225202c3134ull,0x090a3b3631202c30ull,0x203233732e766f6dull,
0x202c323431722509ull,0x090a3b3437323033ull,0x6f6c2e34326c756dull,0x722509203233732eull,
0x317225202c333431ull,0x34317225202c3533ull,0x2e766f6d090a3b32ull,0x3172250920323373ull,
0x34353231202c3434ull,0x326c756d090a3b30ull,0x3233732e6f6c2e34ull,0x2c35343172250920ull,
0x202c373331722520ull,0x090a3b3434317225ull,0x203233732e646461ull,0x202c363431722509ull,
0x25202c3933317225ull,0x61090a3b31343172ull,0x09203233732e6464ull,0x25202c3734317225ull,
0x7225202c33343172ull,0x6f6d090a3b353431ull,0x2509203233732e76ull,0x3332202c38343172ull,
0x756d090a3b303731ull,0x732e6f6c2e34326cull,0x3431722509203233ull,0x3634317225202c39ull,
0x3b3834317225202cull,0x33732e646461090aull,0x3035317225092032ull,0x2c3734317225202cull,
0x0a3b393431722520ull,0x093309636f6c2e09ull,0x6d090a3009393034ull,0x09203233732e766full,
0x31202c3135317225ull,0x6d090a3b30343532ull,0x2e6f6c2e34326c75ull,0x3172250920323373ull,
0x33317225202c3235ull,0x3135317225202c35ull,0x732e766f6d090a3bull,0x3531722509203233ull,
0x3437323033202c33ull,0x34326c756d090a3bull,0x203233732e6f6c2eull,0x202c343531722509ull,
0x25202c3733317225ull,0x73090a3b33353172ull,0x09203233732e6275ull,0x25202c3535317225ull,
0x7225202c39333172ull,0x7573090a3b313431ull,0x2509203233732e62ull,0x7225202c36353172ull,
0x317225202c323531ull,0x766f6d090a3b3435ull,0x722509203233732eull,0x313332202c373531ull,
0x6c756d090a3b3037ull,0x33732e6f6c2e3432ull,0x3835317225092032ull,0x2c3535317225202cull,
0x0a3b373531722520ull,0x3233732e64646109ull,0x2c39353172250920ull,0x202c363531722520ull,
0x090a3b3835317225ull,0x34093309636f6c2eull,0x7573090a30093031ull,0x2509203233732e62ull,
0x7225202c30363172ull,0x317225202c383531ull,0x6f6c2e090a3b3635ull,0x0931313409330963ull,
0x732e627573090a30ull,0x3631722509203233ull,0x3934317225202c31ull,0x3b3734317225202cull,
0x3309636f6c2e090aull,0x090a300934323409ull,0x203233732e766f6dull,0x202c323631722509ull,
0x090a3b3133317225ull,0x203233732e726873ull,0x202c333631722509ull,0x31202c3236317225ull,
0x2e766f6d090a3b36ull,0x3172250920323373ull,0x33317225202c3436ull,0x2e726873090a3b32ull,
0x3172250920323373ull,0x36317225202c3536ull,0x090a3b3631202c34ull,0x203233732e766f6dull,
0x202c363631722509ull,0x090a3b3033317225ull,0x203233732e726873ull,0x202c373631722509ull,
0x31202c3636317225ull,0x2e766f6d090a3b36ull,0x3172250920323373ull,0x33317225202c3836ull,
0x2e726873090a3b33ull,0x3172250920323373ull,0x36317225202c3936ull,0x090a3b3631202c38ull,
0x203233732e646461ull,0x202c303731722509ull,0x25202c3336317225ull,0x73090a3b35363172ull,
0x09203233732e6275ull,0x25202c3137317225ull,0x7225202c33363172ull,0x6873090a3b353631ull,
0x2509203233622e6cull,0x7225202c32373172ull,0x0a3b32202c373631ull,0x3233622e6c687309ull,
0x2c33373172250920ull,0x202c393631722520ull,0x2e766f6d090a3b32ull,0x3172250920323373ull,
0x37313332202c3437ull,0x326c756d090a3b30ull,0x3233732e6f6c2e34ull,0x2c35373172250920ull,
0x202c303731722520ull,0x090a3b3437317225ull,0x203233732e766f6dull,0x202c363731722509ull,
0x090a3b3037313332ull,0x6f6c2e34326c756dull,0x722509203233732eull,0x317225202c373731ull,
0x37317225202c3137ull,0x2e646461090a3b36ull,0x3172250920323373ull,0x37317225202c3837ull,
0x3b36393034202c35ull,0x33732e646461090aull,0x3937317225092032ull,0x2c3737317225202cull,
0x090a3b3639303420ull,0x203233732e726873ull,0x202c303831722509ull,0x31202c3837317225ull,
0x2e726873090a3b33ull,0x3172250920323373ull,0x37317225202c3138ull,0x090a3b3331202c39ull,
0x203233732e646461ull,0x202c323831722509ull,0x25202c3237317225ull,0x61090a3b30383172ull,
0x09203233732e6464ull,0x25202c3338317225ull,0x7225202c33373172ull,0x6f6d090a3b313831ull,
0x2509203233732e76ull,0x3038202c34383172ull,0x6c756d090a3b3533ull,0x33732e6f6c2e3432ull,
0x3538317225092032ull,0x2c3238317225202cull,0x0a3b343831722520ull,0x3233732e766f6d09ull,
0x2c36383172250920ull,0x090a3b3839353120ull,0x6f6c2e34326c756dull,0x722509203233732eull,
0x317225202c373831ull,0x38317225202c3338ull,0x2e646461090a3b36ull,0x3172250920323373ull,
0x38317225202c3838ull,0x3738317225202c35ull,0x09636f6c2e090a3bull,0x0a30093532340933ull,
0x3233732e766f6d09ull,0x2c39383172250920ull,0x090a3b3839353120ull,0x6f6c2e34326c756dull,
0x722509203233732eull,0x317225202c303931ull,0x38317225202c3238ull,0x2e766f6d090a3b39ull,
0x3172250920323373ull,0x35333038202c3139ull,0x34326c756d090a3bull,0x203233732e6f6c2eull,
0x202c323931722509ull,0x25202c3338317225ull,0x73090a3b31393172ull,0x09203233732e6275ull,
0x25202c3339317225ull,0x7225202c30393172ull,0x6c2e090a3b323931ull,0x363234093309636full,
0x2e627573090a3009ull,0x3172250920323373ull,0x37317225202c3439ull,0x3038317225202c32ull,
0x732e627573090a3bull,0x3931722509203233ull,0x3337317225202c35ull,0x3b3138317225202cull,
0x33732e766f6d090aull,0x3639317225092032ull,0x0a3b31353534202cull,0x6c2e34326c756d09ull,
0x2509203233732e6full,0x7225202c37393172ull,0x317225202c343931ull,0x766f6d090a3b3639ull,
0x722509203233732eull,0x313836202c383931ull,0x326c756d090a3b31ull,0x3233732e6f6c2e34ull,
0x2c39393172250920ull,0x202c353931722520ull,0x090a3b3839317225ull,0x203233732e646461ull,
0x202c303032722509ull,0x25202c3739317225ull,0x2e090a3b39393172ull,0x3234093309636f6cull,
0x766f6d090a300937ull,0x722509203233732eull,0x353534202c313032ull,0x326c756d090a3b31ull,
0x3233732e6f6c2e34ull,0x2c32303272250920ull,0x202c353931722520ull,0x090a3b3130327225ull,
0x203233732e766f6dull,0x202c333032722509ull,0x6d090a3b31313836ull,0x2e6f6c2e34326c75ull,
0x3272250920323373ull,0x39317225202c3430ull,0x3330327225202c34ull,0x732e627573090a3bull,
0x3032722509203233ull,0x3430327225202c35ull,0x3b3230327225202cull,0x3309636f6c2e090aull,
0x090a300939323409ull,0x203233732e646461ull,0x202c363032722509ull,0x25202c3838317225ull,
0x61090a3b30353172ull,0x09203233732e6464ull,0x25202c3730327225ull,0x3233202c36303272ull,
0x6873090a3b383637ull,0x2509203233732e72ull,0x7225202c38303272ull,0x3b3631202c373032ull,
0x33622e646e61090aull,0x3930327225092032ull,0x2c3033317225202cull,0x3b36333535362d20ull,
0x33622e646e61090aull,0x3031327225092032ull,0x2c3830327225202cull,0x0a3b353335353620ull,
0x3233732e766f6d09ull,0x2c30313272250920ull,0x0a3b303132722520ull,0x203233622e726f09ull,
0x202c303331722509ull,0x25202c3930327225ull,0x2e090a3b30313272ull,0x3334093309636f6cull,
0x766f6d090a300930ull,0x722509203233732eull,0x317225202c313132ull,0x726873090a3b3033ull,
0x722509203233732eull,0x327225202c323132ull,0x0a3b3631202c3131ull,0x3233622e6c687309ull,
0x2c33313272250920ull,0x202c323132722520ull,0x2e627573090a3b32ull,0x3272250920323373ull,
0x31327225202c3431ull,0x3038317225202c33ull,0x732e766f6d090a3bull,0x3132722509203233ull,
0x3b31313836202c35ull,0x2e34326c756d090aull,0x09203233732e6f6cull,0x25202c3631327225ull,
0x7225202c34313272ull,0x7573090a3b353132ull,0x2509203233732e62ull,0x7225202c37313272ull,
0x327225202c363132ull,0x646461090a3b3230ull,0x722509203233732eull,0x317225202c383132ull,
0x31327225202c3935ull,0x2e646461090a3b37ull,0x3272250920323373ull,0x31327225202c3931ull,
0x3836373233202c38ull,0x732e726873090a3bull,0x3232722509203233ull,0x3931327225202c30ull,
0x61090a3b3631202cull,0x09203233622e646eull,0x25202c3132327225ull,0x3536202c30333172ull,
0x6e61090a3b353335ull,0x2509203233622e64ull,0x7225202c32323272ull,0x353536202c303232ull,
0x6c6873090a3b3533ull,0x722509203233622eull,0x327225202c323232ull,0x0a3b3631202c3232ull,
0x203233622e726f09ull,0x202c303331722509ull,0x25202c3132327225ull,0x2e090a3b32323272ull,
0x3334093309636f6cull,0x646461090a300931ull,0x722509203233732eull,0x317225202c333232ull,
0x30327225202c3036ull,0x2e646461090a3b30ull,0x3272250920323373ull,0x32327225202c3432ull,
0x3836373233202c33ull,0x732e726873090a3bull,0x3232722509203233ull,0x3432327225202c35ull,
0x61090a3b3631202cull,0x09203233622e646eull,0x25202c3632327225ull,0x362d202c31333172ull,
0x61090a3b36333535ull,0x09203233622e646eull,0x25202c3732327225ull,0x3536202c35323272ull,
0x6f6d090a3b353335ull,0x2509203233732e76ull,0x7225202c37323272ull,0x726f090a3b373232ull,
0x722509203233622eull,0x327225202c313331ull,0x32327225202c3632ull,0x636f6c2e090a3b37ull,
0x3009323334093309ull,0x33732e646461090aull,0x3832327225092032ull,0x2c3136317225202cull,
0x0a3b333931722520ull,0x3233732e64646109ull,0x2c39323272250920ull,0x202c383232722520ull,
0x090a3b3836373233ull,0x203233732e726873ull,0x202c303332722509ull,0x31202c3932327225ull,
0x2e646e61090a3b36ull,0x3272250920323362ull,0x33317225202c3133ull,0x3533353536202c31ull,
0x622e646e61090a3bull,0x3332722509203233ull,0x3033327225202c32ull,0x3b3533353536202cull,
0x33622e6c6873090aull,0x3233327225092032ull,0x2c3233327225202cull,0x726f090a3b363120ull,
0x722509203233622eull,0x327225202c313331ull,0x33327225202c3133ull,0x636f6c2e090a3b32ull,
0x3009333334093309ull,0x33732e627573090aull,0x3333327225092032ull,0x2c3136317225202cull,
0x0a3b333931722520ull,0x3233732e64646109ull,0x2c34333272250920ull,0x202c333332722520ull,
0x090a3b3836373233ull,0x203233732e726873ull,0x202c353332722509ull,0x31202c3433327225ull,
0x2e646e61090a3b36ull,0x3272250920323362ull,0x33317225202c3633ull,0x333535362d202c32ull,
0x2e646e61090a3b36ull,0x3272250920323362ull,0x33327225202c3733ull,0x3533353536202c35ull,
0x732e766f6d090a3bull,0x3332722509203233ull,0x3733327225202c37ull,0x33622e726f090a3bull,
0x3233317225092032ull,0x2c3633327225202cull,0x0a3b373332722520ull,0x093309636f6c2e09ull,
0x73090a3009343334ull,0x09203233732e6275ull,0x25202c3833327225ull,0x7225202c30363172ull,
0x6461090a3b303032ull,0x2509203233732e64ull,0x7225202c39333272ull,0x373233202c383332ull,
0x726873090a3b3836ull,0x722509203233732eull,0x327225202c303432ull,0x0a3b3631202c3933ull,
0x3233622e646e6109ull,0x2c31343272250920ull,0x202c323331722520ull,0x090a3b3533353536ull,
0x203233622e646e61ull,0x202c323432722509ull,0x36202c3034327225ull,0x73090a3b35333535ull,
0x09203233622e6c68ull,0x25202c3234327225ull,0x3631202c32343272ull,0x33622e726f090a3bull,
0x3233317225092032ull,0x2c3134327225202cull,0x0a3b323432722520ull,0x093309636f6c2e09ull,
0x73090a3009353334ull,0x09203233732e6275ull,0x25202c3334327225ull,0x7225202c39353172ull,
0x6461090a3b353032ull,0x2509203233732e64ull,0x7225202c34343272ull,0x373233202c333432ull,
0x726873090a3b3836ull,0x722509203233732eull,0x327225202c353432ull,0x0a3b3631202c3434ull,
0x3233622e646e6109ull,0x2c36343272250920ull,0x202c333331722520ull,0x0a3b36333535362dull,
0x3233622e646e6109ull,0x2c37343272250920ull,0x202c353432722520ull,0x090a3b3533353536ull,
0x203233732e766f6dull,0x202c373432722509ull,0x090a3b3734327225ull,0x09203233622e726full,
0x25202c3333317225ull,0x7225202c36343272ull,0x6c2e090a3b373432ull,0x363334093309636full,
0x2e627573090a3009ull,0x3272250920323373ull,0x35317225202c3834ull,0x3838317225202c30ull,
0x732e646461090a3bull,0x3432722509203233ull,0x3834327225202c39ull,0x3b3836373233202cull,
0x33732e726873090aull,0x3035327225092032ull,0x2c3934327225202cull,0x6e61090a3b363120ull,
0x2509203233622e64ull,0x7225202c31353272ull,0x353536202c333331ull,0x646e61090a3b3533ull,
0x722509203233622eull,0x327225202c323532ull,0x33353536202c3035ull,0x2e6c6873090a3b35ull,
0x3272250920323362ull,0x35327225202c3235ull,0x090a3b3631202c32ull,0x09203233622e726full,
0x25202c3333317225ull,0x7225202c31353272ull,0x6c2e090a3b323532ull,0x383334093309636full,
0x732e7473090a3009ull,0x33752e6465726168ull,0x316472255b092032ull,0x7225202c5d302b35ull,
0x6c2e090a3b303331ull,0x393334093309636full,0x732e7473090a3009ull,0x33752e6465726168ull,
0x316472255b092032ull,0x7225202c5d342b35ull,0x6c2e090a3b313331ull,0x303434093309636full,
0x732e7473090a3009ull,0x33752e6465726168ull,0x316472255b092032ull,0x7225202c5d382b35ull,
0x6c2e090a3b323331ull,0x313434093309636full,0x732e7473090a3009ull,0x33752e6465726168ull,
0x316472255b092032ull,0x25202c5d32312b35ull,0x2e090a3b33333172ull,0x3936093309636f6cull,
0x726162090a300932ull,0x300920636e79732eull,0x3170252140090a3bull,0x4c24092061726220ull,
0x363033325f355f74ull,0x09636f6c2e090a3bull,0x0a30093739360933ull,0x726168732e646c09ull,
0x09203233732e6465ull,0x5b202c3335327225ull,0x3b5d302b36647225ull,0x6f6c672e7473090aull,
0x203233732e6c6162ull,0x302b346472255b09ull,0x3335327225202c5dull,0x09636f6c2e090a3bull,
0x0a30093434360933ull,0x617261702e646c09ull,0x2509203233732e6dull,0x635f5f5b202c3872ull,
0x5f6d726170616475ull,0x4144554339315a5full,0x68536c656e72656bull,0x505443444974726full,
0x7453676d495f6973ull,0x090a3b5d65646972ull,0x36093309636f6c2eull,0x756d090a30093839ull,
0x3233752e6f6c2e6cull,0x2c34353272250920ull,0x3b32202c38722520ull,0x36752e747663090aull,
0x2509203233752e34ull,0x7225202c36316472ull,0x7573090a3b343532ull,0x2509203436752e62ull,
0x647225202c346472ull,0x3631647225202c34ull,0x09636f6c2e090a3bull,0x0a30093130370933ull,
0x726168732e646c09ull,0x09203233732e6465ull,0x5b202c3535327225ull,0x38362d2b36647225ull,
0x672e7473090a3b5dull,0x33732e6c61626f6cull,0x346472255b092032ull,0x327225202c5d302bull,
0x6f6c2e090a3b3535ull,0x0932303709330963ull,0x752e627573090a30ull,0x3464722509203436ull,
0x202c34647225202cull,0x090a3b3631647225ull,0x37093309636f6c2eull,0x646c090a30093530ull,
0x2e6465726168732eull,0x3272250920323373ull,0x6472255b202c3635ull,0x3b5d3633312d2b36ull,
0x6f6c672e7473090aull,0x203233732e6c6162ull,0x302b346472255b09ull,0x3635327225202c5dull,
0x09636f6c2e090a3bull,0x0a30093630370933ull,0x3436752e62757309ull,0x202c346472250920ull,
0x7225202c34647225ull,0x6c2e090a3b363164ull,0x393037093309636full,0x732e646c090a3009ull,
0x33732e6465726168ull,0x3735327225092032ull,0x2b366472255b202cull,0x090a3b5d3430322dull,
0x61626f6c672e7473ull,0x5b09203233732e6cull,0x2c5d302b34647225ull,0x0a3b373532722520ull,
0x093309636f6c2e09ull,0x73090a3009303137ull,0x09203436752e6275ull,0x7225202c34647225ull,
0x31647225202c3464ull,0x636f6c2e090a3b36ull,0x3009333137093309ull,0x6168732e646c090aull,
0x203233732e646572ull,0x202c383532722509ull,0x322d2b366472255bull,0x7473090a3b5d3237ull,
0x2e6c61626f6c672eull,0x72255b0920323373ull,0x25202c5d302b3464ull,0x2e090a3b38353272ull,
0x3137093309636f6cull,0x627573090a300934ull,0x722509203436752eull,0x34647225202c3464ull,
0x3b3631647225202cull,0x3309636f6c2e090aull,0x090a300937313709ull,0x65726168732e646cull,
0x2509203233732e64ull,0x255b202c39353272ull,0x3034332d2b366472ull,0x672e7473090a3b5dull,
0x33732e6c61626f6cull,0x346472255b092032ull,0x327225202c5d302bull,0x6f6c2e090a3b3935ull,
0x0938313709330963ull,0x752e627573090a30ull,0x3464722509203436ull,0x202c34647225202cull,
0x090a3b3631647225ull,0x37093309636f6c2eull,0x646c090a30093132ull,0x2e6465726168732eull,
0x3272250920323373ull,0x6472255b202c3036ull,0x3b5d3830342d2b36ull,0x6f6c672e7473090aull,
0x203233732e6c6162ull,0x302b346472255b09ull,0x3036327225202c5dull,0x09636f6c2e090a3bull,
0x0a30093532370933ull,0x726168732e646c09ull,0x09203233732e6465ull,0x5b202c3136327225ull,
0x37342d2b36647225ull,0x627573090a3b5d36ull,0x722509203436752eull,0x647225202c373164ull,
0x3631647225202c34ull,0x6c672e7473090a3bull,0x3233732e6c61626full,0x37316472255b0920ull,
0x327225202c5d302bull,0x5f744c240a3b3136ull,0x0a3a363033325f35ull,0x093309636f6c2e09ull,
0x65090a3009373237ull,0x444c240a3b746978ull,0x315a5f5f646e6557ull,0x72656b4144554339ull,
0x74726f68536c656eull,0x3a69735054434449ull,0x5f202f2f207d090aull,0x6b4144554339315aull,
0x6f68536c656e7265ull,0x7350544344497472ull,0x746e652e090a0a69ull,0x4337325a5f207972ull,
0x656e72656b414455ull,0x7a69746e6175516cull,0x6f6c466e6f697461ull,0x0a28206966507461ull,
0x6d617261702e0909ull,0x5f5f203436752e20ull,0x6d72617061647563ull,0x44554337325a5f5full,
0x516c656e72656b41ull,0x74617a69746e6175ull,0x74616f6c466e6f69ull,0x446372535f696650ull,
0x702e09090a2c7473ull,0x33732e206d617261ull,0x616475635f5f2032ull,0x325a5f5f6d726170ull,
0x72656b4144554337ull,0x746e6175516c656eull,0x466e6f6974617a69ull,0x5f69665074616f6cull,
0x0a29656469727453ull,0x6765722e090a7b09ull,0x7225203631752e20ull,0x2e090a3b3e343c68ull,
0x3233752e20676572ull,0x3b3e30323c722520ull,0x2e206765722e090aull,0x3c64722520343675ull,
0x65722e090a3b3e39ull,0x25203233662e2067ull,0x090a3b3e31313c66ull,0x72702e206765722eull,
0x3e343c7025206465ull,0x09636f6c2e090a3bull,0x0a30093537093931ull,0x5a5f5f3142424c24ull,
0x656b414455433732ull,0x6e6175516c656e72ull,0x6e6f6974617a6974ull,0x69665074616f6c46ull,
0x09636f6c2e090a3aull,0x0a30093638093931ull,0x3233732e74766309ull,0x722509203631752eull,
0x6961746325202c31ull,0x7663090a3b782e64ull,0x33752e3631752e74ull,0x2c31687225092032ull,
0x6d090a3b31722520ull,0x2e656469772e6c75ull,0x3272250920363175ull,0x202c31687225202cull,
0x2e747663090a3b38ull,0x203631752e323373ull,0x6325202c33722509ull,0x0a3b792e64696174ull,
0x3631752e74766309ull,0x722509203233752eull,0x3b337225202c3268ull,0x69772e6c756d090aull,
0x09203631752e6564ull,0x687225202c347225ull,0x63090a3b38202c32ull,0x752e3233732e7476ull,
0x2c35722509203631ull,0x3b792e6469742520ull,0x33732e646461090aull,0x202c367225092032ull,
0x357225202c347225ull,0x61702e646c090a3bull,0x203233732e6d6172ull,0x5f5b202c37722509ull,
0x726170616475635full,0x554337325a5f5f6dull,0x6c656e72656b4144ull,0x617a69746e617551ull,
0x616f6c466e6f6974ull,0x7274535f69665074ull,0x6d090a3b5d656469ull,0x33732e6f6c2e6c75ull,
0x202c387225092032ull,0x367225202c377225ull,0x732e646461090a3bull,0x2c39722509203233ull,
0x7225202c32722520ull,0x2e747663090a3b38ull,0x203631752e323373ull,0x25202c3031722509ull,
0x090a3b782e646974ull,0x203233732e646461ull,0x25202c3131722509ull,0x30317225202c3972ull,
0x6c2e6c756d090a3bull,0x2509203233752e6full,0x317225202c323172ull,0x63090a3b34202c31ull,
0x752e3436752e7476ull,0x3164722509203233ull,0x0a3b32317225202cull,0x617261702e646c09ull,
0x2509203436752e6dull,0x5f5f5b202c326472ull,0x6d72617061647563ull,0x44554337325a5f5full,
0x516c656e72656b41ull,0x74617a69746e6175ull,0x74616f6c466e6f69ull,0x446372535f696650ull,
0x6461090a3b5d7473ull,0x2509203436752e64ull,0x647225202c336472ull,0x3b32647225202c31ull,
0x6f6c672e646c090aull,0x203233662e6c6162ull,0x255b202c31662509ull,0x0a3b5d302b336472ull,
0x333209636f6c2e09ull,0x0a30093139313309ull,0x3436752e766f6d09ull,0x202c346472250920ull,
0x326c756d090a3b51ull,0x3233732e6f6c2e34ull,0x202c333172250920ull,0x0a3b38202c357225ull,
0x3233732e64646109ull,0x202c343172250920ull,0x7225202c30317225ull,0x747663090a3b3331ull,
0x3233732e3436732eull,0x202c356472250920ull,0x6d090a3b34317225ull,0x36752e6f6c2e6c75ull,
0x2c36647225092034ull,0x32202c3564722520ull,0x752e646461090a3bull,0x3764722509203436ull,
0x202c34647225202cull,0x6c090a3b36647225ull,0x2e74736e6f632e64ull,0x3172250920363173ull,
0x376472255b202c35ull,0x7663090a3b5d302bull,0x3233662e6e722e74ull,0x662509203233732eull,
0x3b35317225202c32ull,0x75662e766964090aull,0x09203233662e6c6cull,0x316625202c336625ull,
0x090a3b326625202cull,0x203233622e766f6dull,0x25202c3631722509ull,0x646e61090a3b3366ull,
0x722509203233622eull,0x36317225202c3731ull,0x34373431322d202cull,0x090a3b3834363338ull,
0x09203233622e726full,0x7225202c38317225ull,0x36353031202c3731ull,0x0a3b383036343639ull,
0x3233622e766f6d09ull,0x25202c3466250920ull,0x6c2e090a3b383172ull,0x313309333209636full,
0x6461090a30093239ull,0x2509203233662e64ull,0x2c336625202c3566ull,0x63090a3b34662520ull,
0x662e697a722e7476ull,0x09203233662e3233ull,0x356625202c346625ull,0x09636f6c2e090a3bull,
0x0a30093537093931ull,0x3233662e73626109ull,0x25202c3666250920ull,0x766f6d090a3b3366ull,
0x662509203233662eull,0x3062346630202c37ull,0x20203b3030303030ull,0x38202f2f09202020ull,
0x2b6531363838332eull,0x70746573090a3630ull,0x203233662e74672eull,0x6625202c31702509ull,
0x0a3b376625202c36ull,0x33662e706c657309ull,0x202c346625092032ull,0x346625202c336625ull,
0x090a3b317025202cull,0x203233662e766f6dull,0x6630202c38662509ull,0x3030303030306633ull,
0x2f0920202020203bull,0x73090a352e30202full,0x662e746c2e707465ull,0x2c32702509203233ull,
0x6625202c36662520ull,0x70252140090a3b38ull,0x2409206172622032ull,0x3937315f365f744cull,
0x636f6c2e090a3b34ull,0x3439313309333209ull,0x2e747663090a3009ull,0x2e3233662e697a72ull,
0x3466250920323366ull,0x240a3b336625202cull,0x3937315f365f744cull,0x636f6c2e090a3a34ull,
0x3009343909393109ull,0x33662e6c756d090aull,0x202c396625092032ull,0x346625202c326625ull,
0x6c672e7473090a3bull,0x3233662e6c61626full,0x2b336472255b0920ull,0x3b396625202c5d30ull,
0x3109636f6c2e090aull,0x090a300935390939ull,0x4c240a3b74697865ull,0x5a5f5f646e655744ull,
0x656b414455433732ull,0x6e6175516c656e72ull,0x6e6f6974617a6974ull,0x69665074616f6c46ull,
0x202f2f207d090a3aull,0x4144554337325a5full,0x75516c656e72656bull,0x6974617a69746e61ull,
0x5074616f6c466e6full,0x6e652e090a0a6966ull,0x37325a5f20797274ull,0x6e72656b41445543ull,
0x69746e6175516c65ull,0x68536e6f6974617aull,0x282069735074726full,0x617261702e09090aull,
0x5f203436752e206dull,0x726170616475635full,0x554337325a5f5f6dull,0x6c656e72656b4144ull,
0x617a69746e617551ull,0x726f68536e6f6974ull,0x6372535f69735074ull,0x2e09090a2c747344ull,
0x732e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,0x656b414455433732ull,
0x6e6175516c656e72ull,0x6e6f6974617a6974ull,0x69735074726f6853ull,0x296564697274535full,
0x65722e090a7b090aull,0x25203631752e2067ull,0x090a3b3e343c6872ull,0x33752e206765722eull,
0x3e33323c72252032ull,0x206765722e090a3bull,0x647225203436752eull,0x722e090a3b3e393cull,
0x646572702e206765ull,0x0a3b3e333c702520ull,0x393109636f6c2e09ull,0x240a300938303109ull,
0x325a5f5f3142424cull,0x72656b4144554337ull,0x746e6175516c656eull,0x536e6f6974617a69ull,
0x3a69735074726f68ull,0x3109636f6c2e090aull,0x0a30093931310939ull,0x3233732e74766309ull,
0x722509203631752eull,0x6961746325202c31ull,0x7663090a3b782e64ull,0x33752e3631752e74ull,
0x2c31687225092032ull,0x6d090a3b31722520ull,0x2e656469772e6c75ull,0x3272250920363175ull,
0x202c31687225202cull,0x2e747663090a3b38ull,0x203631752e323373ull,0x6325202c33722509ull,
0x0a3b792e64696174ull,0x3631752e74766309ull,0x722509203233752eull,0x3b337225202c3268ull,
0x69772e6c756d090aull,0x09203631752e6564ull,0x687225202c347225ull,0x63090a3b38202c32ull,
0x752e3233732e7476ull,0x2c35722509203631ull,0x3b792e6469742520ull,0x33732e646461090aull,
0x202c367225092032ull,0x357225202c347225ull,0x61702e646c090a3bull,0x203233732e6d6172ull,
0x5f5b202c37722509ull,0x726170616475635full,0x554337325a5f5f6dull,0x6c656e72656b4144ull,
0x617a69746e617551ull,0x726f68536e6f6974ull,0x7274535f69735074ull,0x6d090a3b5d656469ull,
0x33732e6f6c2e6c75ull,0x202c387225092032ull,0x367225202c377225ull,0x732e646461090a3bull,
0x2c39722509203233ull,0x7225202c32722520ull,0x2e747663090a3b38ull,0x203631752e323373ull,
0x25202c3031722509ull,0x090a3b782e646974ull,0x203233732e646461ull,0x25202c3131722509ull,
0x30317225202c3972ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,0x317225202c323172ull,
0x63090a3b32202c31ull,0x752e3436752e7476ull,0x3164722509203233ull,0x0a3b32317225202cull,
0x617261702e646c09ull,0x2509203436752e6dull,0x5f5f5b202c326472ull,0x6d72617061647563ull,
0x44554337325a5f5full,0x516c656e72656b41ull,0x74617a69746e6175ull,0x74726f68536e6f69ull,
0x446372535f697350ull,0x6461090a3b5d7473ull,0x2509203436752e64ull,0x647225202c336472ull,
0x3b32647225202c31ull,0x6f6c672e646c090aull,0x203631732e6c6162ull,0x5b202c3331722509ull,
0x3b5d302b33647225ull,0x3109636f6c2e090aull,0x0a30093032310939ull,0x3436752e766f6d09ull,
0x202c346472250920ull,0x326c756d090a3b51ull,0x3233732e6f6c2e34ull,0x202c343172250920ull,
0x0a3b38202c357225ull,0x3233732e64646109ull,0x202c353172250920ull,0x7225202c30317225ull,
0x747663090a3b3431ull,0x3233732e3436732eull,0x202c356472250920ull,0x6d090a3b35317225ull,
0x36752e6f6c2e6c75ull,0x2c36647225092034ull,0x32202c3564722520ull,0x752e646461090a3bull,
0x3764722509203436ull,0x202c34647225202cull,0x6c090a3b36647225ull,0x2e74736e6f632e64ull,
0x3172250920363173ull,0x376472255b202c36ull,0x6873090a3b5d302bull,0x2509203233732e72ull,
0x317225202c373172ull,0x6d090a3b31202c36ull,0x09203233752e766full,0x3b30202c38317225ull,
0x672e70746573090aull,0x2509203233732e65ull,0x33317225202c3170ull,0x0a3b38317225202cull,
0x7262203170254009ull,0x375f744c24092061ull,0x090a3b323832315full,0x09393109636f6c2eull,
0x73090a3009363231ull,0x09203233732e6275ull,0x7225202c39317225ull,0x33317225202c3731ull,
0x732e747663090a3bull,0x09203233732e3631ull,0x7225202c33317225ull,0x6f6c2e090a3b3931ull,
0x3732310939310963ull,0x2e766964090a3009ull,0x3172250920323373ull,0x2c33317225202c33ull,
0x090a3b3631722520ull,0x09393109636f6c2eull,0x6e090a3009383231ull,0x09203233732e6765ull,
0x7225202c33317225ull,0x617262090a3b3331ull,0x4c240920696e752eull,0x363230315f375f74ull,
0x5f375f744c240a3bull,0x2e090a3a32383231ull,0x3109393109636f6cull,0x6461090a30093233ull,
0x2509203233732e64ull,0x317225202c303272ull,0x3b37317225202c33ull,0x31732e747663090aull,
0x2509203233732e36ull,0x327225202c333172ull,0x636f6c2e090a3b30ull,0x0933333109393109ull,
0x732e766964090a30ull,0x3331722509203233ull,0x202c33317225202cull,0x4c240a3b36317225ull,
0x363230315f375f74ull,0x09636f6c2e090a3aull,0x3009353331093931ull,0x79732e726162090aull,
0x090a3b300920636eull,0x09393109636f6c2eull,0x6d090a3009303431ull,0x33732e6f6c2e6c75ull,
0x2c31327225092032ull,0x25202c3331722520ull,0x7473090a3b363172ull,0x2e6c61626f6c672eull,
0x72255b0920363173ull,0x25202c5d302b3364ull,0x6c2e090a3b313272ull,0x343109393109636full,
0x697865090a300931ull,0x6557444c240a3b74ull,0x4337325a5f5f646eull,0x656e72656b414455ull,
0x7a69746e6175516cull,0x6f68536e6f697461ull,0x090a3a6973507472ull,0x325a5f202f2f207dull,
0x72656b4144554337ull,0x746e6175516c656eull,0x536e6f6974617a69ull,0x0a69735074726f68ull,
0x000000000000000aull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_10",(char*)__deviceText_$compute_10$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_10", (char*)__deviceText_$sm_10$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_10$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0x2e00b786,(char*)"4805b62219027a28",(char*)"dct8x8.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x75878765,&__elfEntries1};
# 2 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c" 2
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
# 4684 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) double fdivide(double a, double b)
{
  return (double)fdividef((float)a, (float)b);
}



static __attribute__((__unused__)) int __double2int_rz(double a)
{
  return __float2int_rz((float)a);
}

static __attribute__((__unused__)) unsigned int __double2uint_rz(double a)
{
  return __float2uint_rz((float)a);
}

static __attribute__((__unused__)) long long int __double2ll_rz(double a)
{
  return __float2ll_rz((float)a);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rz(double a)
{
  return __float2ull_rz((float)a);
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
  return __fma_rz(a, b, __hiloint2double(0x80000000, 0x00000000));
}

static __attribute__((__unused__)) double __dmul_ru(double a, double b)
{
  return __fma_ru(a, b, __hiloint2double(0x80000000, 0x00000000));
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
  return __fma_rn(a, b, __hiloint2double(0x80000000, 0x00000000));
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


# 5323 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 45 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 3
static __attribute__((__unused__)) double __cuda_fabs(double a)
{
  return (float)__cuda_fabsf((float)a);
}

static __attribute__((__unused__)) double __cuda_fmax(double a, double b)
{
  return (float)__cuda_fmaxf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_fmin(double a, double b)
{
  return (float)__cuda_fminf((float)a, (float)b);
}

static __attribute__((__unused__)) int __cuda___finite(double a)
{
  return __cuda___finitef((float)a);
}

static __attribute__((__unused__)) int __cuda___isinf(double a)
{
  return __cuda___isinff((float)a);
}

static __attribute__((__unused__)) int __cuda___isnan(double a)
{
  return __cuda___isnanf((float)a);
}

static __attribute__((__unused__)) int __cuda___signbit(double a)
{
  return __cuda___signbitf((float)a);
}

static __attribute__((__unused__)) double __cuda_sqrt(double a)
{
  return (double)__cuda_sqrtf((float)a);
}

static __attribute__((__unused__)) double __cuda_rsqrt(double a)
{
  return (double)__cuda_rsqrtf((float)a);
}

static __attribute__((__unused__)) double __cuda_ceil(double a)
{
  return (double)__cuda_ceilf((float)a);
}

static __attribute__((__unused__)) double __cuda_trunc(double a)
{
  return (double)__cuda_truncf((float)a);
}

static __attribute__((__unused__)) double __cuda_floor(double a)
{
  return (double)__cuda_floorf((float)a);
}

static __attribute__((__unused__)) double __cuda_copysign(double a, double b)
{
  return (double)__cuda_copysignf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_sin(double a)
{
  return (double)__cuda_sinf((float)a);
}

static __attribute__((__unused__)) double __cuda_sinpi(double a)
{
  return (double)__cuda_sinpif((float)a);
}

static __attribute__((__unused__)) double __cuda_cos(double a)
{
  return (double)__cuda_cosf((float)a);
}

static __attribute__((__unused__)) void __cuda_sincos(double a, double *sptr, double *cptr)
{
  float fs, fc;

  __cuda_sincosf((float)a, &fs, &fc);

  *sptr = (double)fs;
  *cptr = (double)fc;
}

static __attribute__((__unused__)) double __cuda_tan(double a)
{
  return (double)__cuda_tanf((float)a);
}

static __attribute__((__unused__)) double __cuda_exp(double a)
{
  return (double)__cuda_expf((float)a);
}

static __attribute__((__unused__)) double __cuda_exp2(double a)
{
  return (double)__cuda_exp2f((float)a);
}

static __attribute__((__unused__)) double __cuda_exp10(double a)
{
  return (double)__cuda_exp10f((float)a);
}

static __attribute__((__unused__)) double __cuda_expm1(double a)
{
  return (double)__cuda_expm1f((float)a);
}

static __attribute__((__unused__)) double __cuda_cosh(double a)
{
  return (double)__cuda_coshf((float)a);
}

static __attribute__((__unused__)) double __cuda_sinh(double a)
{
  return (double)__cuda_sinhf((float)a);
}

static __attribute__((__unused__)) double __cuda_tanh(double a)
{
  return (double)__cuda_tanhf((float)a);
}

static __attribute__((__unused__)) double __cuda_asin(double a)
{
  return (double)__cuda_asinf((float)a);
}

static __attribute__((__unused__)) double __cuda_acos(double a)
{
  return (double)__cuda_acosf((float)a);
}

static __attribute__((__unused__)) double __cuda_atan(double a)
{
  return (double)__cuda_atanf((float)a);
}

static __attribute__((__unused__)) double __cuda_atan2(double a, double b)
{
  return (double)__cuda_atan2f((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_log(double a)
{
  return (double)__cuda_logf((float)a);
}

static __attribute__((__unused__)) double __cuda_log2(double a)
{
  return (double)__cuda_log2f((float)a);
}

static __attribute__((__unused__)) double __cuda_log10(double a)
{
  return (double)__cuda_log10f((float)a);
}

static __attribute__((__unused__)) double __cuda_log1p(double a)
{
  return (double)__cuda_log1pf((float)a);
}

static __attribute__((__unused__)) double __cuda_acosh(double a)
{
  return (double)__cuda_acoshf((float)a);
}

static __attribute__((__unused__)) double __cuda_asinh(double a)
{
  return (double)__cuda_asinhf((float)a);
}

static __attribute__((__unused__)) double __cuda_atanh(double a)
{
  return (double)__cuda_atanhf((float)a);
}

static __attribute__((__unused__)) double __cuda_hypot(double a, double b)
{
  return (double)__cuda_hypotf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_cbrt(double a)
{
  return (double)__cuda_cbrtf((float)a);
}

static __attribute__((__unused__)) double __cuda_rcbrt(double a)
{
  return (double)__cuda_rcbrtf((float)a);
}

static __attribute__((__unused__)) double __cuda_erf(double a)
{
  return (double)__cuda_erff((float)a);
}

static __attribute__((__unused__)) double __cuda_erfinv(double a)
{
  return (double)__cuda_erfinvf((float)a);
}

static __attribute__((__unused__)) double __cuda_erfc(double a)
{
  return (double)__cuda_erfcf((float)a);
}

static __attribute__((__unused__)) double __cuda_erfcinv(double a)
{
  return (double)__cuda_erfcinvf((float)a);
}

static __attribute__((__unused__)) double __cuda_lgamma(double a)
{
  return (double)__cuda_lgammaf((float)a);
}

static __attribute__((__unused__)) double __cuda_tgamma(double a)
{
  return (double)__cuda_tgammaf((float)a);
}

static __attribute__((__unused__)) double __cuda_ldexp(double a, int b)
{
  return (double)__cuda_ldexpf((float)a, b);
}

static __attribute__((__unused__)) double __cuda_scalbn(double a, int b)
{
  return (double)__cuda_scalbnf((float)a, b);
}

static __attribute__((__unused__)) double __cuda_scalbln(double a, long b)
{
  return (double)__cuda_scalblnf((float)a, b);
}

static __attribute__((__unused__)) double __cuda_frexp(double a, int *b)
{
  return (double)__cuda_frexpf((float)a, b);
}

static __attribute__((__unused__)) double __cuda_modf(double a, double *b)
{
  float fb;
  float fa = __cuda_modff((float)a, &fb);

  *b = (double)fb;

  return (double)fa;
}

static __attribute__((__unused__)) double __cuda_fmod(double a, double b)
{
  return (double)__cuda_fmodf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_remainder(double a, double b)
{
  return (double)__cuda_remainderf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_remquo(double a, double b, int *c)
{
  return (double)__cuda_remquof((float)a, (float)b, c);
}

static __attribute__((__unused__)) double __cuda_nextafter(double a, double b)
{
  return (double)__cuda_nextafterf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_nan(const char *tagp)
{
  return (double)__cuda_nanf(tagp);
}

static __attribute__((__unused__)) double __cuda_pow(double a, double b)
{
  return (double)__cuda_powf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_round(double a)
{
  return (double)__cuda_roundf((float)a);
}

static __attribute__((__unused__)) long __cuda_lround(double a)
{
  return __cuda_lroundf((float)a);
}

static __attribute__((__unused__)) long long __cuda_llround(double a)
{
  return __cuda_llroundf((float)a);
}

static __attribute__((__unused__)) double __cuda_rint(double a)
{
  return (double)__cuda_rintf((float)a);
}

static __attribute__((__unused__)) long __cuda_lrint(double a)
{
  return __cuda_lrintf((float)a);
}

static __attribute__((__unused__)) long long __cuda_llrint(double a)
{
  return __cuda_llrintf((float)a);
}

static __attribute__((__unused__)) double __cuda_nearbyint(double a)
{
  return (double)__cuda_nearbyintf((float)a);
}

static __attribute__((__unused__)) double __cuda_fdim(double a, double b)
{
  return (double)__cuda_fdimf((float)a, (float)b);
}

static __attribute__((__unused__)) int __cuda_ilogb(double a)
{
  return __cuda_ilogbf((float)a);
}

static __attribute__((__unused__)) double __cuda_logb(double a)
{
  return (double)__cuda_logbf((float)a);
}

static __attribute__((__unused__)) double __cuda_fma(double a, double b, double c)
{
  return (double)__cuda_fmaf((float)a, (float)b, (float)c);
}
# 5324 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 89 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 280 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 3 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c" 2




struct __T20 {float *__par0;int __par1;int __par2;int __par3;int __dummy_field;};




struct __T21 {float *__par0;int __par1;int __par2;int __par3;int __dummy_field;};




struct __T22 {float *__par0;int __par1;int __dummy_field;};




struct __T23 {float *__par0;int __par1;int __dummy_field;};




struct __T24 {short *__par0;int __par1;int __dummy_field;};




struct __T25 {short *__par0;int __par1;int __dummy_field;};




struct __T26 {float *__par0;int __par1;int __dummy_field;};




struct __T27 {short *__par0;int __par1;int __dummy_field;};
static void __sti____cudaRegisterAll_41_tmpxft_0000307e_00000000_4_dct8x8_cpp1_ii_TexSrc(void) __attribute__((__constructor__));
void __device_stub__Z14CUDAkernel1DCTPfiii(float *__par0, int __par1, int __par2, int __par3){auto struct __T20 *__T28;
*(void**)(void*)&__T28 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T28->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T28->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T28->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T28->__par3) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float *, int, int, int))CUDAkernel1DCT__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int, int, int))CUDAkernel1DCT__entry))); };}
void CUDAkernel1DCT__entry( float *__cuda_0,int __cuda_1,int __cuda_2,int __cuda_3)
# 86 "dct8x8_kernel1.cu"
{__device_stub__Z14CUDAkernel1DCTPfiii( __cuda_0,__cuda_1,__cuda_2,__cuda_3);
# 139 "dct8x8_kernel1.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
void __device_stub__Z15CUDAkernel1IDCTPfiii( float *__par0, int __par1, int __par2, int __par3) { auto struct __T21 *__T29;
*(void**)(void*)&__T29 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T29->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T29->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T29->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T29->__par3) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, int, int, int))CUDAkernel1IDCT__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int, int, int))CUDAkernel1IDCT__entry))); }; }
void CUDAkernel1IDCT__entry( float *__cuda_0,int __cuda_1,int __cuda_2,int __cuda_3)
# 155 "dct8x8_kernel1.cu"
{__device_stub__Z15CUDAkernel1IDCTPfiii( __cuda_0,__cuda_1,__cuda_2,__cuda_3);
# 208 "dct8x8_kernel1.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
void __device_stub__Z14CUDAkernel2DCTPfi( float *__par0, int __par1) { auto struct __T22 *__T210;
*(void**)(void*)&__T210 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T210->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T210->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, int))CUDAkernel2DCT__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int))CUDAkernel2DCT__entry))); }; }
void CUDAkernel2DCT__entry( float *__cuda_0,int __cuda_1)
# 205 "dct8x8_kernel2.cu"
{__device_stub__Z14CUDAkernel2DCTPfi( __cuda_0,__cuda_1);
# 318 "dct8x8_kernel2.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
void __device_stub__Z15CUDAkernel2IDCTPfi( float *__par0, int __par1) { auto struct __T23 *__T211;
*(void**)(void*)&__T211 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T211->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T211->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, int))CUDAkernel2IDCT__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int))CUDAkernel2IDCT__entry))); }; }
void CUDAkernel2IDCT__entry( float *__cuda_0,int __cuda_1)
# 335 "dct8x8_kernel2.cu"
{__device_stub__Z15CUDAkernel2IDCTPfi( __cuda_0,__cuda_1);
# 448 "dct8x8_kernel2.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
void __device_stub__Z18CUDAkernelShortDCTPsi( short *__par0, int __par1) { auto struct __T24 *__T236;
*(void**)(void*)&__T236 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T236->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T236->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(short *, int))CUDAkernelShortDCT__entry)); (void)cudaLaunch(((char *)((void ( *)(short *, int))CUDAkernelShortDCT__entry))); }; }
void CUDAkernelShortDCT__entry( short *__cuda_0,int __cuda_1)
# 460 "dct8x8_kernel_short.cu"
{__device_stub__Z18CUDAkernelShortDCTPsi( __cuda_0,__cuda_1);
# 585 "dct8x8_kernel_short.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
void __device_stub__Z19CUDAkernelShortIDCTPsi( short *__par0, int __par1) { auto struct __T25 *__T237;
*(void**)(void*)&__T237 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T237->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T237->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(short *, int))CUDAkernelShortIDCT__entry)); (void)cudaLaunch(((char *)((void ( *)(short *, int))CUDAkernelShortIDCT__entry))); }; }
void CUDAkernelShortIDCT__entry( short *__cuda_0,int __cuda_1)
# 602 "dct8x8_kernel_short.cu"
{__device_stub__Z19CUDAkernelShortIDCTPsi( __cuda_0,__cuda_1);
# 727 "dct8x8_kernel_short.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
void __device_stub__Z27CUDAkernelQuantizationFloatPfi( float *__par0, int __par1) { auto struct __T26 *__T238;
*(void**)(void*)&__T238 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T238->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T238->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, int))CUDAkernelQuantizationFloat__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int))CUDAkernelQuantizationFloat__entry))); }; }
void CUDAkernelQuantizationFloat__entry( float *__cuda_0,int __cuda_1)
# 76 "dct8x8_kernel_quantization.cu"
{__device_stub__Z27CUDAkernelQuantizationFloatPfi( __cuda_0,__cuda_1);
# 95 "dct8x8_kernel_quantization.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
void __device_stub__Z27CUDAkernelQuantizationShortPsi( short *__par0, int __par1) { auto struct __T27 *__T239;
*(void**)(void*)&__T239 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T239->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T239->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(short *, int))CUDAkernelQuantizationShort__entry)); (void)cudaLaunch(((char *)((void ( *)(short *, int))CUDAkernelQuantizationShort__entry))); }; }
void CUDAkernelQuantizationShort__entry( short *__cuda_0,int __cuda_1)
# 109 "dct8x8_kernel_quantization.cu"
{__device_stub__Z27CUDAkernelQuantizationShortPsi( __cuda_0,__cuda_1);
# 141 "dct8x8_kernel_quantization.cu"
}
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
# 25 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c"
static void __sti____cudaRegisterAll_41_tmpxft_0000307e_00000000_4_dct8x8_cpp1_ii_TexSrc(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(short *, int))CUDAkernelQuantizationShort__entry), (char*)"_Z27CUDAkernelQuantizationShortPsi", "_Z27CUDAkernelQuantizationShortPsi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int))CUDAkernelQuantizationFloat__entry), (char*)"_Z27CUDAkernelQuantizationFloatPfi", "_Z27CUDAkernelQuantizationFloatPfi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(short *, int))CUDAkernelShortIDCT__entry), (char*)"_Z19CUDAkernelShortIDCTPsi", "_Z19CUDAkernelShortIDCTPsi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(short *, int))CUDAkernelShortDCT__entry), (char*)"_Z18CUDAkernelShortDCTPsi", "_Z18CUDAkernelShortDCTPsi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int))CUDAkernel2IDCT__entry), (char*)"_Z15CUDAkernel2IDCTPfi", "_Z15CUDAkernel2IDCTPfi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int))CUDAkernel2DCT__entry), (char*)"_Z14CUDAkernel2DCTPfi", "_Z14CUDAkernel2DCTPfi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int, int, int))CUDAkernel1IDCT__entry), (char*)"_Z15CUDAkernel1IDCTPfiii", "_Z15CUDAkernel1IDCTPfiii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int, int, int))CUDAkernel1DCT__entry), (char*)"_Z14CUDAkernel1DCTPfiii", "_Z14CUDAkernel1DCTPfiii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&TexSrc, 0, "TexSrc", 2, 0, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&DCTv8matrix__cuda_shadow_variable__, (char*)"DCTv8matrix", "DCTv8matrix", 0, 256, 1, 0); __cudaRegisterSharedVar(__cudaFatCubinHandle, (void**)"CurBlockLocal1", 256, 4, 0); __cudaRegisterSharedVar(__cudaFatCubinHandle, (void**)"CurBlockLocal2", 256, 4, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&C_a__cuda_shadow_variable__, (char*)"C_a", "C_a", 0, 4, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&C_b__cuda_shadow_variable__, (char*)"C_b", "C_b", 0, 4, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&C_c__cuda_shadow_variable__, (char*)"C_c", "C_c", 0, 4, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&C_d__cuda_shadow_variable__, (char*)"C_d", "C_d", 0, 4, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&C_e__cuda_shadow_variable__, (char*)"C_e", "C_e", 0, 4, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&C_f__cuda_shadow_variable__, (char*)"C_f", "C_f", 0, 4, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&C_norm__cuda_shadow_variable__, (char*)"C_norm", "C_norm", 0, 4, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&Q__cuda_shadow_variable__, (char*)"Q", "Q", 0, 128, 1, 0); }
# 1 "/tmp/tmpxft_0000307e_00000000-1_dct8x8.cudafe1.stub.c" 2

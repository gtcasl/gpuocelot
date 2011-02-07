# 1 "/tmp/tmpxft_00002c28_00000000-1_main.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00002c28_00000000-1_main.cudafe1.cpp"
# 1 "main.cu"
# 46 "/home/normal/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 1 3
# 108 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 1 3
# 53 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 3
# 1 "/home/normal/cuda/bin/../include/host_defines.h" 1 3
# 54 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 1 "/home/normal/cuda/bin/../include/builtin_types.h" 1 3
# 42 "/home/normal/cuda/bin/../include/builtin_types.h" 3
# 1 "/home/normal/cuda/bin/../include/device_types.h" 1 3
# 46 "/home/normal/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/cuda/bin/../include/driver_types.h" 1 3
# 91 "/home/normal/cuda/bin/../include/driver_types.h" 3
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
# 361 "/home/normal/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef int cudaStream_t;





typedef int cudaEvent_t;
# 44 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/cuda/bin/../include/surface_types.h" 1 3
# 54 "/home/normal/cuda/bin/../include/surface_types.h" 3
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
# 45 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/cuda/bin/../include/texture_types.h" 1 3
# 54 "/home/normal/cuda/bin/../include/texture_types.h" 3
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
# 46 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/cuda/bin/../include/vector_types.h" 1 3
# 82 "/home/normal/cuda/bin/../include/vector_types.h" 3
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
# 258 "/home/normal/cuda/bin/../include/vector_types.h" 3
struct __attribute__((aligned(2*sizeof(long int)))) long2
{
  long int x, y;
 
};


struct __attribute__((aligned(2*sizeof(unsigned long int)))) ulong2
{
  unsigned long int x, y;
 
};
# 306 "/home/normal/cuda/bin/../include/vector_types.h" 3
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
# 378 "/home/normal/cuda/bin/../include/vector_types.h" 3
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
# 448 "/home/normal/cuda/bin/../include/vector_types.h" 3
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
# 475 "/home/normal/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 46 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 55 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 80 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 3
extern "C" {
# 89 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 3
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
# 109 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/home/normal/cuda/bin/../include/crt/storage_class.h" 1 3
# 110 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2 3
# 213 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 2 3
# 91 "/home/normal/cuda/bin/../include/driver_types.h"
# 140 "/home/normal/cuda/bin/../include/driver_types.h"
# 152 "/home/normal/cuda/bin/../include/driver_types.h"
# 165 "/home/normal/cuda/bin/../include/driver_types.h"
# 171 "/home/normal/cuda/bin/../include/driver_types.h"
# 184 "/home/normal/cuda/bin/../include/driver_types.h"
# 197 "/home/normal/cuda/bin/../include/driver_types.h"
# 209 "/home/normal/cuda/bin/../include/driver_types.h"
# 220 "/home/normal/cuda/bin/../include/driver_types.h"
# 238 "/home/normal/cuda/bin/../include/driver_types.h"
# 244 "/home/normal/cuda/bin/../include/driver_types.h"
# 253 "/home/normal/cuda/bin/../include/driver_types.h"
# 264 "/home/normal/cuda/bin/../include/driver_types.h"
# 277 "/home/normal/cuda/bin/../include/driver_types.h"
# 291 "/home/normal/cuda/bin/../include/driver_types.h"
# 302 "/home/normal/cuda/bin/../include/driver_types.h"
# 361 "/home/normal/cuda/bin/../include/driver_types.h"
# 367 "/home/normal/cuda/bin/../include/driver_types.h"
# 373 "/home/normal/cuda/bin/../include/driver_types.h"
# 54 "/home/normal/cuda/bin/../include/surface_types.h"
# 62 "/home/normal/cuda/bin/../include/surface_types.h"
# 69 "/home/normal/cuda/bin/../include/surface_types.h"
# 54 "/home/normal/cuda/bin/../include/texture_types.h"
# 61 "/home/normal/cuda/bin/../include/texture_types.h"
# 68 "/home/normal/cuda/bin/../include/texture_types.h"
# 75 "/home/normal/cuda/bin/../include/texture_types.h"
# 82 "/home/normal/cuda/bin/../include/vector_types.h"
# 89 "/home/normal/cuda/bin/../include/vector_types.h"
# 96 "/home/normal/cuda/bin/../include/vector_types.h"
# 103 "/home/normal/cuda/bin/../include/vector_types.h"
# 110 "/home/normal/cuda/bin/../include/vector_types.h"
# 117 "/home/normal/cuda/bin/../include/vector_types.h"
# 124 "/home/normal/cuda/bin/../include/vector_types.h"
# 131 "/home/normal/cuda/bin/../include/vector_types.h"
# 138 "/home/normal/cuda/bin/../include/vector_types.h"
# 145 "/home/normal/cuda/bin/../include/vector_types.h"
# 152 "/home/normal/cuda/bin/../include/vector_types.h"
# 159 "/home/normal/cuda/bin/../include/vector_types.h"
# 166 "/home/normal/cuda/bin/../include/vector_types.h"
# 173 "/home/normal/cuda/bin/../include/vector_types.h"
# 180 "/home/normal/cuda/bin/../include/vector_types.h"
# 183 "/home/normal/cuda/bin/../include/vector_types.h"
# 186 "/home/normal/cuda/bin/../include/vector_types.h"
# 193 "/home/normal/cuda/bin/../include/vector_types.h"
# 200 "/home/normal/cuda/bin/../include/vector_types.h"
# 203 "/home/normal/cuda/bin/../include/vector_types.h"
# 206 "/home/normal/cuda/bin/../include/vector_types.h"
# 213 "/home/normal/cuda/bin/../include/vector_types.h"
# 220 "/home/normal/cuda/bin/../include/vector_types.h"
# 227 "/home/normal/cuda/bin/../include/vector_types.h"
# 234 "/home/normal/cuda/bin/../include/vector_types.h"
# 241 "/home/normal/cuda/bin/../include/vector_types.h"
# 258 "/home/normal/cuda/bin/../include/vector_types.h"
# 265 "/home/normal/cuda/bin/../include/vector_types.h"
# 306 "/home/normal/cuda/bin/../include/vector_types.h"
# 313 "/home/normal/cuda/bin/../include/vector_types.h"
# 316 "/home/normal/cuda/bin/../include/vector_types.h"
# 323 "/home/normal/cuda/bin/../include/vector_types.h"
# 330 "/home/normal/cuda/bin/../include/vector_types.h"
# 337 "/home/normal/cuda/bin/../include/vector_types.h"
# 344 "/home/normal/cuda/bin/../include/vector_types.h"
# 351 "/home/normal/cuda/bin/../include/vector_types.h"
# 358 "/home/normal/cuda/bin/../include/vector_types.h"
# 365 "/home/normal/cuda/bin/../include/vector_types.h"
# 378 "/home/normal/cuda/bin/../include/vector_types.h"
# 380 "/home/normal/cuda/bin/../include/vector_types.h"
# 382 "/home/normal/cuda/bin/../include/vector_types.h"
# 384 "/home/normal/cuda/bin/../include/vector_types.h"
# 386 "/home/normal/cuda/bin/../include/vector_types.h"
# 388 "/home/normal/cuda/bin/../include/vector_types.h"
# 390 "/home/normal/cuda/bin/../include/vector_types.h"
# 392 "/home/normal/cuda/bin/../include/vector_types.h"
# 394 "/home/normal/cuda/bin/../include/vector_types.h"
# 396 "/home/normal/cuda/bin/../include/vector_types.h"
# 398 "/home/normal/cuda/bin/../include/vector_types.h"
# 400 "/home/normal/cuda/bin/../include/vector_types.h"
# 402 "/home/normal/cuda/bin/../include/vector_types.h"
# 404 "/home/normal/cuda/bin/../include/vector_types.h"
# 406 "/home/normal/cuda/bin/../include/vector_types.h"
# 408 "/home/normal/cuda/bin/../include/vector_types.h"
# 410 "/home/normal/cuda/bin/../include/vector_types.h"
# 412 "/home/normal/cuda/bin/../include/vector_types.h"
# 414 "/home/normal/cuda/bin/../include/vector_types.h"
# 416 "/home/normal/cuda/bin/../include/vector_types.h"
# 418 "/home/normal/cuda/bin/../include/vector_types.h"
# 420 "/home/normal/cuda/bin/../include/vector_types.h"
# 422 "/home/normal/cuda/bin/../include/vector_types.h"
# 424 "/home/normal/cuda/bin/../include/vector_types.h"
# 426 "/home/normal/cuda/bin/../include/vector_types.h"
# 428 "/home/normal/cuda/bin/../include/vector_types.h"
# 430 "/home/normal/cuda/bin/../include/vector_types.h"
# 432 "/home/normal/cuda/bin/../include/vector_types.h"
# 448 "/home/normal/cuda/bin/../include/vector_types.h"
# 450 "/home/normal/cuda/bin/../include/vector_types.h"
# 452 "/home/normal/cuda/bin/../include/vector_types.h"
# 454 "/home/normal/cuda/bin/../include/vector_types.h"
# 456 "/home/normal/cuda/bin/../include/vector_types.h"
# 458 "/home/normal/cuda/bin/../include/vector_types.h"
# 460 "/home/normal/cuda/bin/../include/vector_types.h"
# 462 "/home/normal/cuda/bin/../include/vector_types.h"
# 464 "/home/normal/cuda/bin/../include/vector_types.h"
# 466 "/home/normal/cuda/bin/../include/vector_types.h"
# 475 "/home/normal/cuda/bin/../include/vector_types.h"
# 486 "/home/normal/cuda/bin/../include/vector_types.h"
# 89 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
# 90 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent);
# 91 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 92 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 93 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t);
# 101 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 102 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 103 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 104 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (1));
# 105 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 106 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 107 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 109 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
# 110 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
# 111 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 119 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t *, size_t *);
# 120 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 121 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 122 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 123 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 124 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 125 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 126 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 127 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 128 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 129 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 137 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t);
# 138 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t);
# 139 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 140 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 141 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 142 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 143 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 144 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 152 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 153 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 161 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 162 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 170 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 171 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 172 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 173 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 174 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 175 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int *, int);
# 176 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(int);
# 184 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 185 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
# 186 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 187 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 188 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 189 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 197 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToAddr(size_t *, const surfaceReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 198 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 199 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceAlignmentOffset(size_t *, const surfaceReference *);
# 200 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference **, const char *);
# 208 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 209 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 217 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 218 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 226 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = 0);
# 227 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 228 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 229 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 237 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 238 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 239 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 240 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 248 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 249 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int);
# 250 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t);
# 251 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 252 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 253 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 254 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 262 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 263 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 271 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 272 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 280 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
# 281 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 289 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource *);
# 290 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource *, unsigned);
# 291 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int, cudaGraphicsResource **, cudaStream_t);
# 292 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int, cudaGraphicsResource **, cudaStream_t);
# 293 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void **, size_t *, cudaGraphicsResource *);
# 294 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray **, cudaGraphicsResource *, unsigned, unsigned);
# 93 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 94 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 95 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 96 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 98 "/home/normal/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf()
# 99 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 100 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 102 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 103 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 105 "/home/normal/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1()
# 106 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 107 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 109 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 110 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 112 "/home/normal/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2()
# 113 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 114 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 116 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 117 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 119 "/home/normal/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4()
# 120 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 121 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 123 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 124 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 126 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 127 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 128 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(char)) * 8);
# 133 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 135 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 137 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 138 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 139 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 141 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 142 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 144 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 145 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 146 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 148 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 149 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 151 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 152 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 153 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 155 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 156 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 158 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 159 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 160 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 162 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 163 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 165 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 166 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 167 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 169 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 170 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 172 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 173 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 174 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 176 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 177 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 179 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 180 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 181 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 183 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 184 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 186 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 187 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 188 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 190 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 191 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 193 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 194 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 195 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 197 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 198 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 200 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 201 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 202 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 204 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 205 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 207 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 208 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 209 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 211 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 212 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 214 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 215 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 216 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 218 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 219 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 221 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 222 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 223 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 225 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 226 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 228 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 229 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 230 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 232 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 233 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 235 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 236 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 237 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 239 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 240 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 242 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 243 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 244 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 246 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 247 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 249 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 250 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 251 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 253 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 254 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 256 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 257 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 258 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 260 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 261 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 263 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 264 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 265 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 267 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 268 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 270 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 271 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 272 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 274 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 275 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 277 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 278 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 279 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 281 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 282 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 284 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 285 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 286 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 288 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 289 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 291 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 292 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 293 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 295 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 296 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 298 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 299 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 300 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 302 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 303 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 365 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 366 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 367 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 369 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 370 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 372 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 373 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 374 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 376 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 377 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 379 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 380 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 381 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 383 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 384 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 386 "/home/normal/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 387 "/home/normal/cuda/bin/../include/channel_descriptor.h"
{
# 388 "/home/normal/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 390 "/home/normal/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 391 "/home/normal/cuda/bin/../include/channel_descriptor.h"
}
# 54 "/home/normal/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 55 "/home/normal/cuda/bin/../include/driver_functions.h"
{
# 56 "/home/normal/cuda/bin/../include/driver_functions.h"
cudaPitchedPtr s;
# 58 "/home/normal/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 59 "/home/normal/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 60 "/home/normal/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 61 "/home/normal/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 63 "/home/normal/cuda/bin/../include/driver_functions.h"
return s;
# 64 "/home/normal/cuda/bin/../include/driver_functions.h"
}
# 66 "/home/normal/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 67 "/home/normal/cuda/bin/../include/driver_functions.h"
{
# 68 "/home/normal/cuda/bin/../include/driver_functions.h"
cudaPos p;
# 70 "/home/normal/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 71 "/home/normal/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 72 "/home/normal/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 74 "/home/normal/cuda/bin/../include/driver_functions.h"
return p;
# 75 "/home/normal/cuda/bin/../include/driver_functions.h"
}
# 77 "/home/normal/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 78 "/home/normal/cuda/bin/../include/driver_functions.h"
{
# 79 "/home/normal/cuda/bin/../include/driver_functions.h"
cudaExtent e;
# 81 "/home/normal/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 82 "/home/normal/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 83 "/home/normal/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 85 "/home/normal/cuda/bin/../include/driver_functions.h"
return e;
# 86 "/home/normal/cuda/bin/../include/driver_functions.h"
}
# 54 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 55 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 56 "/home/normal/cuda/bin/../include/vector_functions.h"
char1 t; (t.x) = x; return t;
# 57 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 59 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 60 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 61 "/home/normal/cuda/bin/../include/vector_functions.h"
uchar1 t; (t.x) = x; return t;
# 62 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 64 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 65 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 66 "/home/normal/cuda/bin/../include/vector_functions.h"
char2 t; (t.x) = x; (t.y) = y; return t;
# 67 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 69 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 70 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 71 "/home/normal/cuda/bin/../include/vector_functions.h"
uchar2 t; (t.x) = x; (t.y) = y; return t;
# 72 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 74 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 75 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 76 "/home/normal/cuda/bin/../include/vector_functions.h"
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 77 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 79 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 80 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 81 "/home/normal/cuda/bin/../include/vector_functions.h"
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 82 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 84 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 85 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 86 "/home/normal/cuda/bin/../include/vector_functions.h"
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 87 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 89 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 90 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 91 "/home/normal/cuda/bin/../include/vector_functions.h"
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 92 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 94 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline short1 make_short1(short x)
# 95 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 96 "/home/normal/cuda/bin/../include/vector_functions.h"
short1 t; (t.x) = x; return t;
# 97 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 99 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 100 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 101 "/home/normal/cuda/bin/../include/vector_functions.h"
ushort1 t; (t.x) = x; return t;
# 102 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 104 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 105 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 106 "/home/normal/cuda/bin/../include/vector_functions.h"
short2 t; (t.x) = x; (t.y) = y; return t;
# 107 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 109 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 110 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 111 "/home/normal/cuda/bin/../include/vector_functions.h"
ushort2 t; (t.x) = x; (t.y) = y; return t;
# 112 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 114 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 115 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 116 "/home/normal/cuda/bin/../include/vector_functions.h"
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 117 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 119 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 120 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 121 "/home/normal/cuda/bin/../include/vector_functions.h"
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 122 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 124 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 125 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 126 "/home/normal/cuda/bin/../include/vector_functions.h"
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 127 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 129 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 130 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 131 "/home/normal/cuda/bin/../include/vector_functions.h"
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 132 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 134 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline int1 make_int1(int x)
# 135 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 136 "/home/normal/cuda/bin/../include/vector_functions.h"
int1 t; (t.x) = x; return t;
# 137 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 139 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 140 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 141 "/home/normal/cuda/bin/../include/vector_functions.h"
uint1 t; (t.x) = x; return t;
# 142 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 144 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 145 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 146 "/home/normal/cuda/bin/../include/vector_functions.h"
int2 t; (t.x) = x; (t.y) = y; return t;
# 147 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 149 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 150 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 151 "/home/normal/cuda/bin/../include/vector_functions.h"
uint2 t; (t.x) = x; (t.y) = y; return t;
# 152 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 154 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 155 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 156 "/home/normal/cuda/bin/../include/vector_functions.h"
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 157 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 159 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 160 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 161 "/home/normal/cuda/bin/../include/vector_functions.h"
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 162 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 164 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 165 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 166 "/home/normal/cuda/bin/../include/vector_functions.h"
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 167 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 169 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 170 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 171 "/home/normal/cuda/bin/../include/vector_functions.h"
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 172 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 174 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline long1 make_long1(long x)
# 175 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 176 "/home/normal/cuda/bin/../include/vector_functions.h"
long1 t; (t.x) = x; return t;
# 177 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 179 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 180 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 181 "/home/normal/cuda/bin/../include/vector_functions.h"
ulong1 t; (t.x) = x; return t;
# 182 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 184 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 185 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 186 "/home/normal/cuda/bin/../include/vector_functions.h"
long2 t; (t.x) = x; (t.y) = y; return t;
# 187 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 189 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 190 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 191 "/home/normal/cuda/bin/../include/vector_functions.h"
ulong2 t; (t.x) = x; (t.y) = y; return t;
# 192 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 218 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
# 219 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 220 "/home/normal/cuda/bin/../include/vector_functions.h"
float1 t; (t.x) = x; return t;
# 221 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 223 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 224 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 225 "/home/normal/cuda/bin/../include/vector_functions.h"
float2 t; (t.x) = x; (t.y) = y; return t;
# 226 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 228 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 229 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 230 "/home/normal/cuda/bin/../include/vector_functions.h"
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 231 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 233 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 234 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 235 "/home/normal/cuda/bin/../include/vector_functions.h"
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 236 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 238 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 239 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 240 "/home/normal/cuda/bin/../include/vector_functions.h"
longlong1 t; (t.x) = x; return t;
# 241 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 243 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 244 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 245 "/home/normal/cuda/bin/../include/vector_functions.h"
ulonglong1 t; (t.x) = x; return t;
# 246 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 248 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 249 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 250 "/home/normal/cuda/bin/../include/vector_functions.h"
longlong2 t; (t.x) = x; (t.y) = y; return t;
# 251 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 253 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 254 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 255 "/home/normal/cuda/bin/../include/vector_functions.h"
ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 256 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 258 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline double1 make_double1(double x)
# 259 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 260 "/home/normal/cuda/bin/../include/vector_functions.h"
double1 t; (t.x) = x; return t;
# 261 "/home/normal/cuda/bin/../include/vector_functions.h"
}
# 263 "/home/normal/cuda/bin/../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 264 "/home/normal/cuda/bin/../include/vector_functions.h"
{
# 265 "/home/normal/cuda/bin/../include/vector_functions.h"
double2 t; (t.x) = x; (t.y) = y; return t;
# 266 "/home/normal/cuda/bin/../include/vector_functions.h"
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
# 56 "/home/normal/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((__weak__)) clock_t clock() throw();
# 65 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
# 67 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));
# 69 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 71 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__));
# 73 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__));
# 76 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int min(int, int);
# 78 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned umin(unsigned, unsigned);
# 80 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llmin(long long, long long);
# 82 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned long long ullmin(unsigned long long, unsigned long long);
# 84 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fminf(float, float) throw();
# 86 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmin(double, double) throw();
# 89 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int max(int, int);
# 91 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned umax(unsigned, unsigned);
# 93 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llmax(long long, long long);
# 95 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned long long ullmax(unsigned long long, unsigned long long);
# 97 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw();
# 99 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmax(double, double) throw();
# 102 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sin(double) throw();
# 104 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinf(float) throw();
# 107 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cos(double) throw();
# 109 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float cosf(float) throw();
# 112 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw();
# 114 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();
# 117 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tan(double) throw();
# 119 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tanf(float) throw();
# 122 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sqrt(double) throw();
# 124 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sqrtf(float) throw();
# 127 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rsqrt(double);
# 129 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rsqrtf(float);
# 132 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp2(double) throw();
# 134 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float exp2f(float) throw();
# 137 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp10(double) throw();
# 139 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float exp10f(float) throw();
# 142 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double expm1(double) throw();
# 144 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float expm1f(float) throw();
# 147 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log2(double) throw();
# 149 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log2f(float) throw();
# 152 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log10(double) throw();
# 154 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log10f(float) throw();
# 157 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log(double) throw();
# 159 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float logf(float) throw();
# 162 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log1p(double) throw();
# 164 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log1pf(float) throw();
# 167 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__));
# 169 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__));
# 172 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp(double) throw();
# 174 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float expf(float) throw();
# 177 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cosh(double) throw();
# 179 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float coshf(float) throw();
# 182 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sinh(double) throw();
# 184 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinhf(float) throw();
# 187 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tanh(double) throw();
# 189 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tanhf(float) throw();
# 192 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double acosh(double) throw();
# 194 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float acoshf(float) throw();
# 197 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double asinh(double) throw();
# 199 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float asinhf(float) throw();
# 202 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atanh(double) throw();
# 204 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atanhf(float) throw();
# 207 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double ldexp(double, int) throw();
# 209 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw();
# 212 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double logb(double) throw();
# 214 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float logbf(float) throw();
# 217 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int ilogb(double) throw();
# 219 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int ilogbf(float) throw();
# 222 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double scalbn(double, int) throw();
# 224 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw();
# 227 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double scalbln(double, long) throw();
# 229 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw();
# 232 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double frexp(double, int *) throw();
# 234 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw();
# 237 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__));
# 239 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__));
# 242 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lround(double) throw();
# 244 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lroundf(float) throw();
# 247 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llround(double) throw();
# 249 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llroundf(float) throw();
# 252 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rint(double) throw();
# 254 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rintf(float) throw();
# 257 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lrint(double) throw();
# 259 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lrintf(float) throw();
# 262 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llrint(double) throw();
# 264 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llrintf(float) throw();
# 267 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nearbyint(double) throw();
# 269 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nearbyintf(float) throw();
# 272 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__));
# 274 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__));
# 277 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__));
# 279 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__));
# 282 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fdim(double, double) throw();
# 284 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fdimf(float, float) throw();
# 287 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atan2(double, double) throw();
# 289 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atan2f(float, float) throw();
# 292 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atan(double) throw();
# 294 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atanf(float) throw();
# 297 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double asin(double) throw();
# 299 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float asinf(float) throw();
# 302 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double acos(double) throw();
# 304 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float acosf(float) throw();
# 307 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double hypot(double, double) throw();
# 309 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float hypotf(float, float) throw();
# 312 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cbrt(double) throw();
# 314 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float cbrtf(float) throw();
# 317 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rcbrt(double);
# 319 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rcbrtf(float);
# 322 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sinpi(double);
# 324 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinpif(float);
# 327 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double pow(double, double) throw();
# 329 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float powf(float, float) throw();
# 332 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double modf(double, double *) throw();
# 334 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float modff(float, float *) throw();
# 337 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmod(double, double) throw();
# 339 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmodf(float, float) throw();
# 342 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double remainder(double, double) throw();
# 344 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float remainderf(float, float) throw();
# 347 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw();
# 349 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw();
# 352 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erf(double) throw();
# 354 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erff(float) throw();
# 357 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erfinv(double);
# 359 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erfinvf(float);
# 362 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erfc(double) throw();
# 364 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erfcf(float) throw();
# 367 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erfcinv(double);
# 369 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erfcinvf(float);
# 372 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double lgamma(double) throw();
# 374 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float lgammaf(float) throw();
# 377 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tgamma(double) throw();
# 379 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tgammaf(float) throw();
# 382 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__));
# 384 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__));
# 387 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__));
# 389 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__));
# 392 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__));
# 394 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__));
# 397 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));
# 399 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));
# 402 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));
# 404 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));
# 418 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));
# 420 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));
# 430 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fma(double, double, double) throw();
# 432 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw();
# 442 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));
# 444 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 454 "/home/normal/cuda/bin/../include/math_functions.h"
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
# 496 "/home/normal/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {
# 498 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline long long abs(long long) __attribute__((visibility("default")));
# 499 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 501 "/home/normal/cuda/bin/../include/math_functions.h"
namespace std {
# 503 "/home/normal/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __pow_helper(T, int);
# 504 "/home/normal/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __cmath_power(T, unsigned);
# 505 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 507 "/home/normal/cuda/bin/../include/math_functions.h"
using std::abs;
# 508 "/home/normal/cuda/bin/../include/math_functions.h"
using std::fabs;
# 509 "/home/normal/cuda/bin/../include/math_functions.h"
using std::ceil;
# 510 "/home/normal/cuda/bin/../include/math_functions.h"
using std::floor;
# 511 "/home/normal/cuda/bin/../include/math_functions.h"
using std::sqrt;
# 512 "/home/normal/cuda/bin/../include/math_functions.h"
using std::pow;
# 513 "/home/normal/cuda/bin/../include/math_functions.h"
using std::log;
# 514 "/home/normal/cuda/bin/../include/math_functions.h"
using std::log10;
# 515 "/home/normal/cuda/bin/../include/math_functions.h"
using std::fmod;
# 516 "/home/normal/cuda/bin/../include/math_functions.h"
using std::modf;
# 517 "/home/normal/cuda/bin/../include/math_functions.h"
using std::exp;
# 518 "/home/normal/cuda/bin/../include/math_functions.h"
using std::frexp;
# 519 "/home/normal/cuda/bin/../include/math_functions.h"
using std::ldexp;
# 520 "/home/normal/cuda/bin/../include/math_functions.h"
using std::asin;
# 521 "/home/normal/cuda/bin/../include/math_functions.h"
using std::sin;
# 522 "/home/normal/cuda/bin/../include/math_functions.h"
using std::sinh;
# 523 "/home/normal/cuda/bin/../include/math_functions.h"
using std::acos;
# 524 "/home/normal/cuda/bin/../include/math_functions.h"
using std::cos;
# 525 "/home/normal/cuda/bin/../include/math_functions.h"
using std::cosh;
# 526 "/home/normal/cuda/bin/../include/math_functions.h"
using std::atan;
# 527 "/home/normal/cuda/bin/../include/math_functions.h"
using std::atan2;
# 528 "/home/normal/cuda/bin/../include/math_functions.h"
using std::tan;
# 529 "/home/normal/cuda/bin/../include/math_functions.h"
using std::tanh;
# 583 "/home/normal/cuda/bin/../include/math_functions.h"
namespace std {
# 586 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline long abs(long) __attribute__((visibility("default")));
# 587 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float abs(float) __attribute__((visibility("default")));
# 588 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline double abs(double) __attribute__((visibility("default")));
# 589 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float fabs(float) __attribute__((visibility("default")));
# 590 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float ceil(float) __attribute__((visibility("default")));
# 591 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float floor(float) __attribute__((visibility("default")));
# 592 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float sqrt(float) __attribute__((visibility("default")));
# 593 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float pow(float, float) __attribute__((visibility("default")));
# 594 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float pow(float, int) __attribute__((visibility("default")));
# 595 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline double pow(double, int) __attribute__((visibility("default")));
# 596 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float log(float) __attribute__((visibility("default")));
# 597 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float log10(float) __attribute__((visibility("default")));
# 598 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float fmod(float, float) __attribute__((visibility("default")));
# 599 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float modf(float, float *) __attribute__((visibility("default")));
# 600 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float exp(float) __attribute__((visibility("default")));
# 601 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float frexp(float, int *) __attribute__((visibility("default")));
# 602 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float ldexp(float, int) __attribute__((visibility("default")));
# 603 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float asin(float) __attribute__((visibility("default")));
# 604 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float sin(float) __attribute__((visibility("default")));
# 605 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float sinh(float) __attribute__((visibility("default")));
# 606 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float acos(float) __attribute__((visibility("default")));
# 607 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float cos(float) __attribute__((visibility("default")));
# 608 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float cosh(float) __attribute__((visibility("default")));
# 609 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float atan(float) __attribute__((visibility("default")));
# 610 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float atan2(float, float) __attribute__((visibility("default")));
# 611 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float tan(float) __attribute__((visibility("default")));
# 612 "/home/normal/cuda/bin/../include/math_functions.h"
extern inline float tanh(float) __attribute__((visibility("default")));
# 615 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 618 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float logb(float a)
# 619 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 620 "/home/normal/cuda/bin/../include/math_functions.h"
return logbf(a);
# 621 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 623 "/home/normal/cuda/bin/../include/math_functions.h"
static inline int ilogb(float a)
# 624 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 625 "/home/normal/cuda/bin/../include/math_functions.h"
return ilogbf(a);
# 626 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 628 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float scalbn(float a, int b)
# 629 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 630 "/home/normal/cuda/bin/../include/math_functions.h"
return scalbnf(a, b);
# 631 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 633 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float scalbln(float a, long b)
# 634 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 635 "/home/normal/cuda/bin/../include/math_functions.h"
return scalblnf(a, b);
# 636 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 638 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float exp2(float a)
# 639 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 640 "/home/normal/cuda/bin/../include/math_functions.h"
return exp2f(a);
# 641 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 643 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float exp10(float a)
# 644 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 645 "/home/normal/cuda/bin/../include/math_functions.h"
return exp10f(a);
# 646 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 648 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float expm1(float a)
# 649 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 650 "/home/normal/cuda/bin/../include/math_functions.h"
return expm1f(a);
# 651 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 653 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float log2(float a)
# 654 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 655 "/home/normal/cuda/bin/../include/math_functions.h"
return log2f(a);
# 656 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 658 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float log1p(float a)
# 659 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 660 "/home/normal/cuda/bin/../include/math_functions.h"
return log1pf(a);
# 661 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 663 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float rsqrt(float a)
# 664 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 665 "/home/normal/cuda/bin/../include/math_functions.h"
return rsqrtf(a);
# 666 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 668 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float acosh(float a)
# 669 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 670 "/home/normal/cuda/bin/../include/math_functions.h"
return acoshf(a);
# 671 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 673 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float asinh(float a)
# 674 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 675 "/home/normal/cuda/bin/../include/math_functions.h"
return asinhf(a);
# 676 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 678 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float atanh(float a)
# 679 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 680 "/home/normal/cuda/bin/../include/math_functions.h"
return atanhf(a);
# 681 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 683 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float hypot(float a, float b)
# 684 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 685 "/home/normal/cuda/bin/../include/math_functions.h"
return hypotf(a, b);
# 686 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 688 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float cbrt(float a)
# 689 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 690 "/home/normal/cuda/bin/../include/math_functions.h"
return cbrtf(a);
# 691 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 693 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float rcbrt(float a)
# 694 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 695 "/home/normal/cuda/bin/../include/math_functions.h"
return rcbrtf(a);
# 696 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 698 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float sinpi(float a)
# 699 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 700 "/home/normal/cuda/bin/../include/math_functions.h"
return sinpif(a);
# 701 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 703 "/home/normal/cuda/bin/../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 704 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 705 "/home/normal/cuda/bin/../include/math_functions.h"
sincosf(a, sptr, cptr);
# 706 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 708 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float erf(float a)
# 709 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 710 "/home/normal/cuda/bin/../include/math_functions.h"
return erff(a);
# 711 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 713 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float erfinv(float a)
# 714 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 715 "/home/normal/cuda/bin/../include/math_functions.h"
return erfinvf(a);
# 716 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 718 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float erfc(float a)
# 719 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 720 "/home/normal/cuda/bin/../include/math_functions.h"
return erfcf(a);
# 721 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 723 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float erfcinv(float a)
# 724 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 725 "/home/normal/cuda/bin/../include/math_functions.h"
return erfcinvf(a);
# 726 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 728 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float lgamma(float a)
# 729 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 730 "/home/normal/cuda/bin/../include/math_functions.h"
return lgammaf(a);
# 731 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 733 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float tgamma(float a)
# 734 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 735 "/home/normal/cuda/bin/../include/math_functions.h"
return tgammaf(a);
# 736 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 738 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, float b)
# 739 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 740 "/home/normal/cuda/bin/../include/math_functions.h"
return copysignf(a, b);
# 741 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 743 "/home/normal/cuda/bin/../include/math_functions.h"
static inline double copysign(double a, float b)
# 744 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 745 "/home/normal/cuda/bin/../include/math_functions.h"
return copysign(a, (double)b);
# 746 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 748 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, double b)
# 749 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 750 "/home/normal/cuda/bin/../include/math_functions.h"
return copysignf(a, (float)b);
# 751 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 753 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float nextafter(float a, float b)
# 754 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 755 "/home/normal/cuda/bin/../include/math_functions.h"
return nextafterf(a, b);
# 756 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 758 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float remainder(float a, float b)
# 759 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 760 "/home/normal/cuda/bin/../include/math_functions.h"
return remainderf(a, b);
# 761 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 763 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 764 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 765 "/home/normal/cuda/bin/../include/math_functions.h"
return remquof(a, b, quo);
# 766 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 768 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float round(float a)
# 769 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 770 "/home/normal/cuda/bin/../include/math_functions.h"
return roundf(a);
# 771 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 773 "/home/normal/cuda/bin/../include/math_functions.h"
static inline long lround(float a)
# 774 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 775 "/home/normal/cuda/bin/../include/math_functions.h"
return lroundf(a);
# 776 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 778 "/home/normal/cuda/bin/../include/math_functions.h"
static inline long long llround(float a)
# 779 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 780 "/home/normal/cuda/bin/../include/math_functions.h"
return llroundf(a);
# 781 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 783 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float trunc(float a)
# 784 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 785 "/home/normal/cuda/bin/../include/math_functions.h"
return truncf(a);
# 786 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 788 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float rint(float a)
# 789 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 790 "/home/normal/cuda/bin/../include/math_functions.h"
return rintf(a);
# 791 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 793 "/home/normal/cuda/bin/../include/math_functions.h"
static inline long lrint(float a)
# 794 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 795 "/home/normal/cuda/bin/../include/math_functions.h"
return lrintf(a);
# 796 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 798 "/home/normal/cuda/bin/../include/math_functions.h"
static inline long long llrint(float a)
# 799 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 800 "/home/normal/cuda/bin/../include/math_functions.h"
return llrintf(a);
# 801 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 803 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float nearbyint(float a)
# 804 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 805 "/home/normal/cuda/bin/../include/math_functions.h"
return nearbyintf(a);
# 806 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 808 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float fdim(float a, float b)
# 809 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 810 "/home/normal/cuda/bin/../include/math_functions.h"
return fdimf(a, b);
# 811 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 813 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 814 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 815 "/home/normal/cuda/bin/../include/math_functions.h"
return fmaf(a, b, c);
# 816 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 818 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float fmax(float a, float b)
# 819 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 820 "/home/normal/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 821 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 823 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float fmin(float a, float b)
# 824 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 825 "/home/normal/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 826 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 828 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 829 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 830 "/home/normal/cuda/bin/../include/math_functions.h"
return umin(a, b);
# 831 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 833 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 834 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 835 "/home/normal/cuda/bin/../include/math_functions.h"
return umin((unsigned)a, b);
# 836 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 838 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 839 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 840 "/home/normal/cuda/bin/../include/math_functions.h"
return umin(a, (unsigned)b);
# 841 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 843 "/home/normal/cuda/bin/../include/math_functions.h"
static inline long long min(long long a, long long b)
# 844 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 845 "/home/normal/cuda/bin/../include/math_functions.h"
return llmin(a, b);
# 846 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 848 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, unsigned long long b)
# 849 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 850 "/home/normal/cuda/bin/../include/math_functions.h"
return ullmin(a, b);
# 851 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 853 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(long long a, unsigned long long b)
# 854 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 855 "/home/normal/cuda/bin/../include/math_functions.h"
return ullmin((unsigned long long)a, b);
# 856 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 858 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, long long b)
# 859 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 860 "/home/normal/cuda/bin/../include/math_functions.h"
return ullmin(a, (unsigned long long)b);
# 861 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 863 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float min(float a, float b)
# 864 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 865 "/home/normal/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 866 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 868 "/home/normal/cuda/bin/../include/math_functions.h"
static inline double min(double a, double b)
# 869 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 870 "/home/normal/cuda/bin/../include/math_functions.h"
return fmin(a, b);
# 871 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 873 "/home/normal/cuda/bin/../include/math_functions.h"
static inline double min(float a, double b)
# 874 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 875 "/home/normal/cuda/bin/../include/math_functions.h"
return fmin((double)a, b);
# 876 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 878 "/home/normal/cuda/bin/../include/math_functions.h"
static inline double min(double a, float b)
# 879 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 880 "/home/normal/cuda/bin/../include/math_functions.h"
return fmin(a, (double)b);
# 881 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 883 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 884 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 885 "/home/normal/cuda/bin/../include/math_functions.h"
return umax(a, b);
# 886 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 888 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 889 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 890 "/home/normal/cuda/bin/../include/math_functions.h"
return umax((unsigned)a, b);
# 891 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 893 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 894 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 895 "/home/normal/cuda/bin/../include/math_functions.h"
return umax(a, (unsigned)b);
# 896 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 898 "/home/normal/cuda/bin/../include/math_functions.h"
static inline long long max(long long a, long long b)
# 899 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 900 "/home/normal/cuda/bin/../include/math_functions.h"
return llmax(a, b);
# 901 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 903 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, unsigned long long b)
# 904 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 905 "/home/normal/cuda/bin/../include/math_functions.h"
return ullmax(a, b);
# 906 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 908 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(long long a, unsigned long long b)
# 909 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 910 "/home/normal/cuda/bin/../include/math_functions.h"
return ullmax((unsigned long long)a, b);
# 911 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 913 "/home/normal/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, long long b)
# 914 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 915 "/home/normal/cuda/bin/../include/math_functions.h"
return ullmax(a, (unsigned long long)b);
# 916 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 918 "/home/normal/cuda/bin/../include/math_functions.h"
static inline float max(float a, float b)
# 919 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 920 "/home/normal/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 921 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 923 "/home/normal/cuda/bin/../include/math_functions.h"
static inline double max(double a, double b)
# 924 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 925 "/home/normal/cuda/bin/../include/math_functions.h"
return fmax(a, b);
# 926 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 928 "/home/normal/cuda/bin/../include/math_functions.h"
static inline double max(float a, double b)
# 929 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 930 "/home/normal/cuda/bin/../include/math_functions.h"
return fmax((double)a, b);
# 931 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 933 "/home/normal/cuda/bin/../include/math_functions.h"
static inline double max(double a, float b)
# 934 "/home/normal/cuda/bin/../include/math_functions.h"
{
# 935 "/home/normal/cuda/bin/../include/math_functions.h"
return fmax(a, (double)b);
# 936 "/home/normal/cuda/bin/../include/math_functions.h"
}
# 59 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
template<class T, int dim = 1>
# 60 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
struct surface : public surfaceReference {
# 62 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
surface()
# 63 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
{
# 64 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 65 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
}
# 67 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
surface(cudaChannelFormatDesc desc)
# 68 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
{
# 69 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = desc;
# 70 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
}
# 71 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
};
# 74 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
template<int dim>
# 75 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
struct surface< void, dim> : public surfaceReference {
# 77 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
surface()
# 78 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
{
# 79 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< void> ();
# 80 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
}
# 81 "/home/normal/cuda/bin/../include/cuda_surface_types.h"
};
# 59 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
# 60 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
struct texture : public textureReference {
# 62 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 63 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 64 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 65 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
{
# 66 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 67 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 68 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 69 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 70 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 71 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 72 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
}
# 74 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 75 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 76 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 77 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
desc)
# 78 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
{
# 79 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 80 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 81 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 82 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 83 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 84 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = desc;
# 85 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
}
# 86 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
};
# 316 "/home/normal/cuda/bin/../include/device_functions.h"
static inline int mulhi(int a, int b)
# 317 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 319 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 321 "/home/normal/cuda/bin/../include/device_functions.h"
static inline unsigned mulhi(unsigned a, unsigned b)
# 322 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 324 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 326 "/home/normal/cuda/bin/../include/device_functions.h"
static inline unsigned mulhi(int a, unsigned b)
# 327 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 329 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 331 "/home/normal/cuda/bin/../include/device_functions.h"
static inline unsigned mulhi(unsigned a, int b)
# 332 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 334 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 336 "/home/normal/cuda/bin/../include/device_functions.h"
static inline long long mul64hi(long long a, long long b)
# 337 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 339 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 341 "/home/normal/cuda/bin/../include/device_functions.h"
static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 342 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 344 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 346 "/home/normal/cuda/bin/../include/device_functions.h"
static inline unsigned long long mul64hi(long long a, unsigned long long b)
# 347 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 349 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 351 "/home/normal/cuda/bin/../include/device_functions.h"
static inline unsigned long long mul64hi(unsigned long long a, long long b)
# 352 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 354 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 356 "/home/normal/cuda/bin/../include/device_functions.h"
static inline int float_as_int(float a)
# 357 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 359 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 361 "/home/normal/cuda/bin/../include/device_functions.h"
static inline float int_as_float(int a)
# 362 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 364 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 366 "/home/normal/cuda/bin/../include/device_functions.h"
static inline float saturate(float a)
# 367 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 369 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 371 "/home/normal/cuda/bin/../include/device_functions.h"
static inline int mul24(int a, int b)
# 372 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 374 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 376 "/home/normal/cuda/bin/../include/device_functions.h"
static inline unsigned umul24(unsigned a, unsigned b)
# 377 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 379 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 381 "/home/normal/cuda/bin/../include/device_functions.h"
static inline void trap()
# 382 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 384 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 386 "/home/normal/cuda/bin/../include/device_functions.h"
static inline void brkpt(int c)
# 387 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 389 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 391 "/home/normal/cuda/bin/../include/device_functions.h"
static inline void syncthreads()
# 392 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 394 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 396 "/home/normal/cuda/bin/../include/device_functions.h"
static inline void prof_trigger(int e)
# 397 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 414 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 416 "/home/normal/cuda/bin/../include/device_functions.h"
static inline void threadfence(bool global = true)
# 417 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 419 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 421 "/home/normal/cuda/bin/../include/device_functions.h"
static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero)
# 422 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 427 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 429 "/home/normal/cuda/bin/../include/device_functions.h"
static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero)
# 430 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 435 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 437 "/home/normal/cuda/bin/../include/device_functions.h"
static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest)
# 438 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 443 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 445 "/home/normal/cuda/bin/../include/device_functions.h"
static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 446 "/home/normal/cuda/bin/../include/device_functions.h"
{exit(1);
# 451 "/home/normal/cuda/bin/../include/device_functions.h"
}
# 101 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicAdd(int *address, int val)
# 102 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 104 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 106 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicAdd(unsigned *address, unsigned val)
# 107 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 109 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 111 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicSub(int *address, int val)
# 112 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 114 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 116 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicSub(unsigned *address, unsigned val)
# 117 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 119 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 121 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicExch(int *address, int val)
# 122 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 124 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 126 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicExch(unsigned *address, unsigned val)
# 127 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 129 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 131 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline float atomicExch(float *address, float val)
# 132 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 134 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 136 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicMin(int *address, int val)
# 137 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 139 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 141 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicMin(unsigned *address, unsigned val)
# 142 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 144 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 146 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicMax(int *address, int val)
# 147 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 149 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 151 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicMax(unsigned *address, unsigned val)
# 152 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 154 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 156 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicInc(unsigned *address, unsigned val)
# 157 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 159 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 161 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicDec(unsigned *address, unsigned val)
# 162 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 164 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 166 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicAnd(int *address, int val)
# 167 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 169 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 171 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicAnd(unsigned *address, unsigned val)
# 172 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 174 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 176 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicOr(int *address, int val)
# 177 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 179 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 181 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicOr(unsigned *address, unsigned val)
# 182 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 184 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 186 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicXor(int *address, int val)
# 187 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 189 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 191 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicXor(unsigned *address, unsigned val)
# 192 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 194 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 196 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline int atomicCAS(int *address, int compare, int val)
# 197 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 199 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 201 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 202 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
{exit(1);
# 204 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h"
}
# 74 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 75 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 77 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 79 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 80 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 82 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 84 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 85 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 87 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 89 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
static inline bool any(bool cond)
# 90 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 92 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 94 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
static inline bool all(bool cond)
# 95 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
{exit(1);
# 97 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h"
}
# 169 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline double fma(double a, double b, double c, cudaRoundMode mode)
# 170 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 175 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 177 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 178 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 183 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 185 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 186 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 191 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 193 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero)
# 194 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 199 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 201 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero)
# 202 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 207 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 209 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero)
# 210 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 215 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 217 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero)
# 218 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 223 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 225 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest)
# 226 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 231 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 233 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest)
# 234 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 239 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 241 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest)
# 242 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 244 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 246 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 247 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 249 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 251 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest)
# 252 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
{exit(1);
# 254 "/home/normal/cuda/bin/../include/sm_13_double_functions.h"
}
# 65 "/home/normal/cuda/bin/../include/sm_20_atomic_functions.h"
static inline float atomicAdd(float *address, float val)
# 66 "/home/normal/cuda/bin/../include/sm_20_atomic_functions.h"
{exit(1);
# 68 "/home/normal/cuda/bin/../include/sm_20_atomic_functions.h"
}
# 120 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
static inline unsigned ballot(bool pred)
# 121 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
{exit(1);
# 123 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
}
# 125 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
static inline int syncthreads_count(bool pred)
# 126 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
{exit(1);
# 128 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
}
# 130 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
static inline bool syncthreads_and(bool pred)
# 131 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
{exit(1);
# 133 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
}
# 135 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
static inline bool syncthreads_or(bool pred)
# 136 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
{exit(1);
# 138 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h"
}
# 96 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 97 "/home/normal/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 98 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 105 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 107 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline T
# 108 "/home/normal/cuda/bin/../include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 109 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 115 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 117 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 118 "/home/normal/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 119 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 121 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 124 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 125 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 127 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 130 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 131 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 133 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 136 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 137 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 139 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 142 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 143 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 145 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 148 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 149 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 151 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 154 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 155 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 159 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 162 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 163 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 165 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 168 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 169 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 173 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 176 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 177 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 179 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 182 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 183 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 185 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 188 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 189 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 191 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 194 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 195 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 197 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 200 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 201 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 203 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 206 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 207 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 211 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 214 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 215 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 217 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 220 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 221 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 225 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 228 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 229 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 231 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 234 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 235 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 237 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 240 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 241 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 243 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 246 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 247 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 249 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 252 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 253 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 255 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 258 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 259 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 263 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 266 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 267 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 269 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 272 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 273 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 277 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 280 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 281 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 283 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 286 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 287 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 289 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 292 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 293 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 295 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 298 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 299 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 301 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 304 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 305 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 307 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 310 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 311 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 315 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 318 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 319 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 321 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 384 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 385 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 387 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 390 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 391 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 393 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 396 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 397 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 401 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 404 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode)
# 405 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 409 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 456 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 457 "/home/normal/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 458 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 465 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 467 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline T
# 468 "/home/normal/cuda/bin/../include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 469 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 475 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 477 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 478 "/home/normal/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 479 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 481 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 484 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 485 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 487 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 490 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 491 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 493 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 496 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 497 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 499 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 502 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 503 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 505 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 508 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 509 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 511 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 514 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 515 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 519 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 522 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 523 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 525 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 528 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 529 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 533 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 536 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 537 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 539 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 542 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 543 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 545 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 548 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 549 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 551 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 554 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 555 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 557 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 560 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 561 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 563 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 566 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 567 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 571 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 574 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 575 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 577 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 580 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 581 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 585 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 588 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 589 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 591 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 594 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 595 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 597 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 600 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 601 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 603 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 606 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 607 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 609 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 612 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 613 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 615 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 618 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 619 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 623 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 626 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 627 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 629 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 632 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 633 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 637 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 640 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 641 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 643 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 646 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 647 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 649 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 652 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 653 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 655 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 658 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 659 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 661 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 664 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 665 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 667 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 670 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 671 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 675 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 678 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 679 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 681 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 744 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 745 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 747 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 750 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 751 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 753 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 756 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 757 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 761 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 764 "/home/normal/cuda/bin/../include/surface_functions.h"
template<> inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode)
# 765 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 769 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 816 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 817 "/home/normal/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 818 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 836 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 838 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 839 "/home/normal/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 840 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 842 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 845 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 846 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 848 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 850 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 851 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 853 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 855 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 856 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 858 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 860 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 861 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 863 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 865 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 866 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 868 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 870 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 871 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 873 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 875 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 876 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 878 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 880 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 881 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 883 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 885 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 886 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 888 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 890 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 891 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 893 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 895 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 896 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 898 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 900 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 901 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 903 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 905 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 906 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 908 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 910 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 911 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 913 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 915 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 916 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 918 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 920 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 921 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 923 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 925 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 926 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 928 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 930 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 931 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 933 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 935 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 936 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 938 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 940 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 941 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 943 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 945 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 946 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 948 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 950 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 951 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 953 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 955 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 956 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 958 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 960 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 961 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 963 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 965 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 966 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 968 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 970 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 971 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 973 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 975 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 976 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 978 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 980 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 981 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 983 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 985 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 986 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 988 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 990 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 991 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 993 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 995 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 996 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 998 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1044 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1045 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1047 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1049 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1050 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1052 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1054 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1055 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1057 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1059 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1060 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1062 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1109 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 1110 "/home/normal/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1111 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1129 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1131 "/home/normal/cuda/bin/../include/surface_functions.h"
template<class T> static inline void
# 1132 "/home/normal/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1133 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1135 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1138 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1139 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1141 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1143 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1144 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1146 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1148 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1149 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1151 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1153 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1154 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1156 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1158 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1159 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1161 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1163 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1164 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1166 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1168 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1169 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1171 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1173 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1174 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1176 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1178 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1179 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1181 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1183 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1184 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1186 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1188 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1189 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1191 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1193 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1194 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1196 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1198 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1199 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1201 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1203 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1204 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1206 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1208 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1209 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1211 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1213 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1214 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1216 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1218 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1219 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1221 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1223 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1224 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1226 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1228 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1229 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1231 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1233 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1234 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1236 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1238 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1239 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1241 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1243 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1244 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1246 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1248 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1249 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1251 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1253 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1254 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1256 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1258 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1259 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1261 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1263 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1264 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1266 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1268 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1269 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1271 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1273 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1274 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1276 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1278 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1279 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1281 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1283 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1284 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1286 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1288 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1289 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1291 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1337 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1338 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1340 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1342 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1343 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1345 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1347 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1348 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1350 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 1352 "/home/normal/cuda/bin/../include/surface_functions.h"
static inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBounderyMode mode = cudaBounderyModeTrap)
# 1353 "/home/normal/cuda/bin/../include/surface_functions.h"
{exit(1);
# 1355 "/home/normal/cuda/bin/../include/surface_functions.h"
}
# 60 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> static uint4 __utexfetchi(texture< T, 1, readMode> , int4);
# 62 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> static int4 __itexfetchi(texture< T, 1, readMode> , int4);
# 64 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> static float4 __ftexfetchi(texture< T, 1, readMode> , int4);
# 67 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> static uint4 __utexfetch(texture< T, dim, readMode> , float4, int = dim);
# 69 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> static int4 __itexfetch(texture< T, dim, readMode> , float4, int = dim);
# 71 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> static float4 __ftexfetch(texture< T, dim, readMode> , float4, int = dim);
# 79 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 80 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 88 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 90 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 91 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 95 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 97 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 98 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 102 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 104 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 105 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 109 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 111 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 112 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 116 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 118 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 119 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 123 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 125 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 126 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 130 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 132 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 133 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 137 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 139 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 140 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 144 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 152 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 153 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 157 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 159 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 160 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 164 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 166 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 167 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 171 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 173 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 174 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 178 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 180 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 181 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 185 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 187 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 188 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 192 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 194 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 195 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 199 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 201 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 202 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 206 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 214 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 215 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 219 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 221 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 222 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 226 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 228 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 229 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 233 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 235 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 236 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 240 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 242 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 243 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 247 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 249 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 250 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 254 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 256 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 257 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 261 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 263 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 264 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 268 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 342 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 343 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 347 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 349 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 350 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 354 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 356 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 357 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 361 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 363 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 364 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 368 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 376 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 377 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 386 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 388 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 389 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 394 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 396 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 397 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 402 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 404 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 405 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 410 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 412 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 413 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 418 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 420 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 421 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 426 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 428 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 429 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 434 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 436 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 437 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 442 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 444 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 445 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 450 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 458 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 459 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 464 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 466 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 467 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 472 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 474 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 475 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 480 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 482 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 483 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 488 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 490 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 491 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 496 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 498 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 499 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 504 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 506 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 507 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 512 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 514 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 515 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 520 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 528 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 529 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 537 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 539 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 540 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 544 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 546 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 547 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 551 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 553 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 554 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 558 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 560 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 561 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 565 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 567 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 568 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 572 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 574 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 575 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 579 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 581 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 582 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 586 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 588 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 589 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 593 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 601 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 602 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 606 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 608 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 609 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 613 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 615 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 616 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 620 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 622 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 623 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 627 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 629 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 630 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 634 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 636 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 637 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 641 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 643 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 644 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 648 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 650 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 651 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 655 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 663 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 664 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 668 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 670 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 671 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 675 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 677 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 678 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 682 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 684 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 685 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 689 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 691 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 692 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 696 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 698 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 699 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 703 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 705 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 706 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 710 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 712 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 713 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 717 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 797 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 798 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 802 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 804 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 805 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 809 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 811 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 812 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 816 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 818 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 819 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 823 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 831 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 832 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 841 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 843 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 844 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 849 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 851 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 852 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 857 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 859 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 860 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 865 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 867 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 868 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 873 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 875 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 876 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 881 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 883 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 884 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 889 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 891 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 892 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 897 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 899 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 900 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 905 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 913 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 914 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 919 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 921 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 922 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 927 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 929 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 930 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 935 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 937 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 938 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 943 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 945 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 946 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 951 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 953 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 954 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 959 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 961 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 962 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 967 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 969 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 970 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 975 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 983 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 984 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 992 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 994 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 995 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 999 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1001 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1002 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1006 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1008 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1009 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1013 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1015 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1016 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1020 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1022 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1023 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1027 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1029 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1030 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1034 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1036 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1037 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1041 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1043 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1044 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1048 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1056 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1057 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1061 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1063 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1064 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1068 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1070 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1071 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1075 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1077 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1078 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1082 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1084 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1085 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1089 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1091 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1092 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1096 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1098 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1099 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1103 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1105 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1106 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1110 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1118 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1119 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1123 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1125 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1126 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1130 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1132 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1133 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1137 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1139 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1140 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1144 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1146 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1147 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1151 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1153 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1154 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1158 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1160 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1161 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1165 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1167 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1168 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1172 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1246 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1247 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1251 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1253 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1254 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1258 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1260 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1261 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1265 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1267 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1268 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1272 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1280 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1281 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1290 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1292 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1293 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1298 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1300 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1301 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1306 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1308 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1309 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1314 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1316 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1317 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1322 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1324 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1325 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1330 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1332 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1333 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1338 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1340 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1341 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1346 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1348 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1349 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1354 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1362 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1363 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1368 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1370 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1371 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1376 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1378 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1379 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1384 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1386 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1387 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1392 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1394 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1395 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1400 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1402 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1403 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1408 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1410 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1411 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1416 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1418 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1419 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1424 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1432 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1433 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1441 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1443 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1444 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1448 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1450 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1451 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1455 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1457 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1458 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1462 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1464 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1465 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1469 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1471 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1472 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1476 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1478 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1479 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1483 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1485 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1486 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1490 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1492 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1493 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1497 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1505 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1506 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1510 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1512 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1513 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1517 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1519 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1520 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1524 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1526 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1527 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1531 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1533 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1534 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1538 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1540 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1541 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1545 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1547 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1548 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1552 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1554 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1555 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1559 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1567 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1568 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1572 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1574 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1575 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1579 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1581 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1582 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1586 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1588 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1589 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1593 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1595 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1596 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1600 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1602 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1603 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1607 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1609 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1610 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1614 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1616 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1617 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1621 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1695 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1696 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1700 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1702 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1703 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1707 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1709 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1710 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1714 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1716 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1717 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1721 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1729 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1730 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1739 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1741 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1742 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1747 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1749 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1750 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1755 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1757 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1758 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1763 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1765 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1766 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1771 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1773 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1774 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1779 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1781 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1782 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1787 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1789 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1790 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1795 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1797 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1798 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1803 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1811 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1812 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1817 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1819 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1820 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1825 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1827 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1828 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1833 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1835 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1836 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1841 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1843 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1844 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1849 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1851 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1852 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1857 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1859 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1860 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1865 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 1867 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
static inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1868 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
{exit(1);
# 1873 "/home/normal/cuda/bin/../include/texture_fetch_functions.h"
}
# 53 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 55 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 57 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 59 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 61 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 102 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 103 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 104 "/home/normal/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 105 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset)
# 107 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 108 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 109 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 111 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 112 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaHostAlloc(T **
# 113 "/home/normal/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 114 "/home/normal/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 115 "/home/normal/cuda/bin/../include/cuda_runtime.h"
flags)
# 117 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 118 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 119 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 121 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 122 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 123 "/home/normal/cuda/bin/../include/cuda_runtime.h"
pDevice, void *
# 124 "/home/normal/cuda/bin/../include/cuda_runtime.h"
pHost, unsigned
# 125 "/home/normal/cuda/bin/../include/cuda_runtime.h"
flags)
# 127 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 128 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 129 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 131 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 132 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaMalloc(T **
# 133 "/home/normal/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 134 "/home/normal/cuda/bin/../include/cuda_runtime.h"
size)
# 136 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 137 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 138 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 140 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 141 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaMallocHost(T **
# 142 "/home/normal/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 143 "/home/normal/cuda/bin/../include/cuda_runtime.h"
size)
# 145 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 146 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size);
# 147 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 149 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 150 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaMallocPitch(T **
# 151 "/home/normal/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t *
# 152 "/home/normal/cuda/bin/../include/cuda_runtime.h"
pitch, size_t
# 153 "/home/normal/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 154 "/home/normal/cuda/bin/../include/cuda_runtime.h"
height)
# 156 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 157 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 158 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 173 "/home/normal/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 174 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 175 "/home/normal/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 176 "/home/normal/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 177 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 178 "/home/normal/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 180 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 181 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 182 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 184 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 185 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 186 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 187 "/home/normal/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 188 "/home/normal/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 189 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 190 "/home/normal/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 192 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 193 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 194 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 196 "/home/normal/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 197 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 198 "/home/normal/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 199 "/home/normal/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 200 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 201 "/home/normal/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 202 "/home/normal/cuda/bin/../include/cuda_runtime.h"
stream)
# 204 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 205 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 206 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 208 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 209 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 210 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 211 "/home/normal/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 212 "/home/normal/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 213 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 214 "/home/normal/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 215 "/home/normal/cuda/bin/../include/cuda_runtime.h"
stream)
# 217 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 218 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 219 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 227 "/home/normal/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 228 "/home/normal/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 229 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 230 "/home/normal/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 231 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 232 "/home/normal/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 234 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 235 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 236 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 238 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 239 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 240 "/home/normal/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 241 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 242 "/home/normal/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 243 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 244 "/home/normal/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 246 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 247 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 248 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 250 "/home/normal/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 251 "/home/normal/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 252 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 253 "/home/normal/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 254 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 255 "/home/normal/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 256 "/home/normal/cuda/bin/../include/cuda_runtime.h"
stream)
# 258 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 259 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 260 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 262 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 263 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 264 "/home/normal/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 265 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 266 "/home/normal/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 267 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 268 "/home/normal/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 269 "/home/normal/cuda/bin/../include/cuda_runtime.h"
stream)
# 271 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 272 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 273 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 275 "/home/normal/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 276 "/home/normal/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 277 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol)
# 279 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 280 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 281 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 305 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 306 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 307 "/home/normal/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 308 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol)
# 310 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 311 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 312 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 320 "/home/normal/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 321 "/home/normal/cuda/bin/../include/cuda_runtime.h"
size, char *
# 322 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol)
# 324 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 325 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 326 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 349 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 350 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 351 "/home/normal/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 352 "/home/normal/cuda/bin/../include/cuda_runtime.h"
symbol)
# 354 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 355 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 356 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 405 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 406 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 407 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 408 "/home/normal/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 409 "/home/normal/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 410 "/home/normal/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 411 "/home/normal/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 413 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 414 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 415 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 449 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 450 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 451 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 452 "/home/normal/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 453 "/home/normal/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 454 "/home/normal/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 456 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 457 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.texture< T, dim, readMode> ::channelDesc), size);
# 458 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 504 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 505 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 506 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 507 "/home/normal/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 508 "/home/normal/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 509 "/home/normal/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 510 "/home/normal/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 511 "/home/normal/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 512 "/home/normal/cuda/bin/../include/cuda_runtime.h"
pitch)
# 514 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 515 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 516 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 546 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 547 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 548 "/home/normal/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 549 "/home/normal/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 550 "/home/normal/cuda/bin/../include/cuda_runtime.h"
desc)
# 552 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 553 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 554 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 583 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 584 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 585 "/home/normal/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 586 "/home/normal/cuda/bin/../include/cuda_runtime.h"
array)
# 588 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 589 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 590 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 592 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 593 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 621 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 622 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 623 "/home/normal/cuda/bin/../include/cuda_runtime.h"
tex)
# 625 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 626 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 627 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 660 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 661 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 662 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 663 "/home/normal/cuda/bin/../include/cuda_runtime.h"
tex)
# 665 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 666 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 667 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 709 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 710 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 711 "/home/normal/cuda/bin/../include/cuda_runtime.h"
entry)
# 713 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 714 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 715 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 745 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 746 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 747 "/home/normal/cuda/bin/../include/cuda_runtime.h"
attr, T *
# 748 "/home/normal/cuda/bin/../include/cuda_runtime.h"
entry)
# 750 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 751 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 752 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 760 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim> inline cudaError_t
# 761 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToAddr(size_t *
# 762 "/home/normal/cuda/bin/../include/cuda_runtime.h"
offset, const surface< T, dim> &
# 763 "/home/normal/cuda/bin/../include/cuda_runtime.h"
surf, const void *
# 764 "/home/normal/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 765 "/home/normal/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 767 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 768 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return cudaBindSurfaceToAddr(offset, &surf, devPtr, &(surf.surface< T, dim> ::channelDesc), size);
# 769 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 771 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim> inline cudaError_t
# 772 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 773 "/home/normal/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 774 "/home/normal/cuda/bin/../include/cuda_runtime.h"
array)
# 776 "/home/normal/cuda/bin/../include/cuda_runtime.h"
{
# 777 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 778 "/home/normal/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 780 "/home/normal/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(&surf, array, &desc) : err;
# 781 "/home/normal/cuda/bin/../include/cuda_runtime.h"
}
# 43 "/usr/include/bits/stat.h" 3
extern "C" { struct stat {
# 45 "/usr/include/bits/stat.h" 3
__dev_t st_dev;
# 50 "/usr/include/bits/stat.h" 3
__ino_t st_ino;
# 58 "/usr/include/bits/stat.h" 3
__nlink_t st_nlink;
# 59 "/usr/include/bits/stat.h" 3
__mode_t st_mode;
# 61 "/usr/include/bits/stat.h" 3
__uid_t st_uid;
# 62 "/usr/include/bits/stat.h" 3
__gid_t st_gid;
# 64 "/usr/include/bits/stat.h" 3
int __pad0;
# 66 "/usr/include/bits/stat.h" 3
__dev_t st_rdev;
# 71 "/usr/include/bits/stat.h" 3
__off_t st_size;
# 75 "/usr/include/bits/stat.h" 3
__blksize_t st_blksize;
# 77 "/usr/include/bits/stat.h" 3
__blkcnt_t st_blocks;
# 88 "/usr/include/bits/stat.h" 3
timespec st_atim;
# 89 "/usr/include/bits/stat.h" 3
timespec st_mtim;
# 90 "/usr/include/bits/stat.h" 3
timespec st_ctim;
# 103 "/usr/include/bits/stat.h" 3
long __unused[3];
# 112 "/usr/include/bits/stat.h" 3
}; }
# 116 "/usr/include/bits/stat.h" 3
extern "C" { struct stat64 {
# 118 "/usr/include/bits/stat.h" 3
__dev_t st_dev;
# 120 "/usr/include/bits/stat.h" 3
__ino64_t st_ino;
# 121 "/usr/include/bits/stat.h" 3
__nlink_t st_nlink;
# 122 "/usr/include/bits/stat.h" 3
__mode_t st_mode;
# 129 "/usr/include/bits/stat.h" 3
__uid_t st_uid;
# 130 "/usr/include/bits/stat.h" 3
__gid_t st_gid;
# 132 "/usr/include/bits/stat.h" 3
int __pad0;
# 133 "/usr/include/bits/stat.h" 3
__dev_t st_rdev;
# 134 "/usr/include/bits/stat.h" 3
__off_t st_size;
# 140 "/usr/include/bits/stat.h" 3
__blksize_t st_blksize;
# 141 "/usr/include/bits/stat.h" 3
__blkcnt64_t st_blocks;
# 149 "/usr/include/bits/stat.h" 3
timespec st_atim;
# 150 "/usr/include/bits/stat.h" 3
timespec st_mtim;
# 151 "/usr/include/bits/stat.h" 3
timespec st_ctim;
# 164 "/usr/include/bits/stat.h" 3
long __unused[3];
# 168 "/usr/include/bits/stat.h" 3
}; }
# 209 "/usr/include/sys/stat.h" 3
extern "C" int stat(const char *__restrict__, struct stat *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 214 "/usr/include/sys/stat.h" 3
extern "C" int fstat(int, struct stat *) throw() __attribute__((nonnull(2)));
# 228 "/usr/include/sys/stat.h" 3
extern "C" int stat64(const char *__restrict__, struct stat64 *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 230 "/usr/include/sys/stat.h" 3
extern "C" int fstat64(int, struct stat64 *) throw() __attribute__((nonnull(2)));
# 238 "/usr/include/sys/stat.h" 3
extern "C" int fstatat(int, const char *__restrict__, struct stat *__restrict__, int) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 253 "/usr/include/sys/stat.h" 3
extern "C" int fstatat64(int, const char *__restrict__, struct stat64 *__restrict__, int) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 263 "/usr/include/sys/stat.h" 3
extern "C" int lstat(const char *__restrict__, struct stat *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 276 "/usr/include/sys/stat.h" 3
extern "C" int lstat64(const char *__restrict__, struct stat64 *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 284 "/usr/include/sys/stat.h" 3
extern "C" int chmod(const char *, __mode_t) throw() __attribute__((nonnull(1)));
# 291 "/usr/include/sys/stat.h" 3
extern "C" int lchmod(const char *, __mode_t) throw() __attribute__((nonnull(1)));
# 297 "/usr/include/sys/stat.h" 3
extern "C" int fchmod(int, __mode_t) throw();
# 303 "/usr/include/sys/stat.h" 3
extern "C" int fchmodat(int, const char *, __mode_t, int) throw() __attribute__((nonnull(2)));
# 312 "/usr/include/sys/stat.h" 3
extern "C" __mode_t umask(__mode_t) throw();
# 317 "/usr/include/sys/stat.h" 3
extern "C" __mode_t getumask() throw();
# 321 "/usr/include/sys/stat.h" 3
extern "C" int mkdir(const char *, __mode_t) throw() __attribute__((nonnull(1)));
# 328 "/usr/include/sys/stat.h" 3
extern "C" int mkdirat(int, const char *, __mode_t) throw() __attribute__((nonnull(2)));
# 336 "/usr/include/sys/stat.h" 3
extern "C" int mknod(const char *, __mode_t, __dev_t) throw() __attribute__((nonnull(1)));
# 343 "/usr/include/sys/stat.h" 3
extern "C" int mknodat(int, const char *, __mode_t, __dev_t) throw() __attribute__((nonnull(2)));
# 350 "/usr/include/sys/stat.h" 3
extern "C" int mkfifo(const char *, __mode_t) throw() __attribute__((nonnull(1)));
# 357 "/usr/include/sys/stat.h" 3
extern "C" int mkfifoat(int, const char *, __mode_t) throw() __attribute__((nonnull(2)));
# 364 "/usr/include/sys/stat.h" 3
extern "C" int utimensat(int, const char *, const timespec [2], int) throw() __attribute__((nonnull(2)));
# 372 "/usr/include/sys/stat.h" 3
extern "C" int futimens(int, const timespec [2]) throw();
# 399 "/usr/include/sys/stat.h" 3
extern "C" int __fxstat(int, int, struct stat *) throw() __attribute__((nonnull(3)));
# 401 "/usr/include/sys/stat.h" 3
extern "C" int __xstat(int, const char *, struct stat *) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 403 "/usr/include/sys/stat.h" 3
extern "C" int __lxstat(int, const char *, struct stat *) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 405 "/usr/include/sys/stat.h" 3
extern "C" int __fxstatat(int, int, const char *, struct stat *, int) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 432 "/usr/include/sys/stat.h" 3
extern "C" int __fxstat64(int, int, struct stat64 *) throw() __attribute__((nonnull(3)));
# 434 "/usr/include/sys/stat.h" 3
extern "C" int __xstat64(int, const char *, struct stat64 *) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 436 "/usr/include/sys/stat.h" 3
extern "C" int __lxstat64(int, const char *, struct stat64 *) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 438 "/usr/include/sys/stat.h" 3
extern "C" int __fxstatat64(int, int, const char *, struct stat64 *, int) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 442 "/usr/include/sys/stat.h" 3
extern "C" int __xmknod(int, const char *, __mode_t, __dev_t *) throw() __attribute__((nonnull(2))) __attribute__((nonnull(4)));
# 445 "/usr/include/sys/stat.h" 3
extern "C" int __xmknodat(int, int, const char *, __mode_t, __dev_t *) throw() __attribute__((nonnull(3))) __attribute__((nonnull(5)));
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
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stdarg.h" 3
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
# 44 "/usr/include/bits/uio.h" 3
extern "C" { struct iovec {
# 46 "/usr/include/bits/uio.h" 3
void *iov_base;
# 47 "/usr/include/bits/uio.h" 3
size_t iov_len;
# 48 "/usr/include/bits/uio.h" 3
}; }
# 158 "/usr/include/bits/fcntl.h" 3
extern "C" { struct flock {
# 160 "/usr/include/bits/fcntl.h" 3
short l_type;
# 161 "/usr/include/bits/fcntl.h" 3
short l_whence;
# 163 "/usr/include/bits/fcntl.h" 3
__off_t l_start;
# 164 "/usr/include/bits/fcntl.h" 3
__off_t l_len;
# 169 "/usr/include/bits/fcntl.h" 3
__pid_t l_pid;
# 170 "/usr/include/bits/fcntl.h" 3
}; }
# 173 "/usr/include/bits/fcntl.h" 3
extern "C" { struct flock64 {
# 175 "/usr/include/bits/fcntl.h" 3
short l_type;
# 176 "/usr/include/bits/fcntl.h" 3
short l_whence;
# 177 "/usr/include/bits/fcntl.h" 3
__off64_t l_start;
# 178 "/usr/include/bits/fcntl.h" 3
__off64_t l_len;
# 179 "/usr/include/bits/fcntl.h" 3
__pid_t l_pid;
# 180 "/usr/include/bits/fcntl.h" 3
}; }
# 230 "/usr/include/bits/fcntl.h" 3
extern "C" ssize_t readahead(int, __off64_t, size_t) throw();
# 235 "/usr/include/bits/fcntl.h" 3
extern "C" int sync_file_range(int, __off64_t, __off64_t, unsigned);
# 240 "/usr/include/bits/fcntl.h" 3
extern "C" ssize_t vmsplice(int, const iovec *, size_t, unsigned);
# 244 "/usr/include/bits/fcntl.h" 3
extern "C" ssize_t splice(int, __off64_t *, int, __off64_t *, size_t, unsigned);
# 249 "/usr/include/bits/fcntl.h" 3
extern "C" ssize_t tee(int, int, size_t, unsigned);
# 254 "/usr/include/bits/fcntl.h" 3
extern "C" int fallocate(int, int, __off_t, __off_t);
# 265 "/usr/include/bits/fcntl.h" 3
extern "C" int fallocate64(int, int, __off64_t, __off64_t);
# 76 "/usr/include/fcntl.h" 3
extern "C" int fcntl(int, int, ...);
# 85 "/usr/include/fcntl.h" 3
extern "C" int open(const char *, int, ...) __attribute__((nonnull(1)));
# 95 "/usr/include/fcntl.h" 3
extern "C" int open64(const char *, int, ...) __attribute__((nonnull(1)));
# 109 "/usr/include/fcntl.h" 3
extern "C" int openat(int, const char *, int, ...) __attribute__((nonnull(2)));
# 120 "/usr/include/fcntl.h" 3
extern "C" int openat64(int, const char *, int, ...) __attribute__((nonnull(2)));
# 130 "/usr/include/fcntl.h" 3
extern "C" int creat(const char *, __mode_t) __attribute__((nonnull(1)));
# 140 "/usr/include/fcntl.h" 3
extern "C" int creat64(const char *, __mode_t) __attribute__((nonnull(1)));
# 159 "/usr/include/fcntl.h" 3
extern "C" int lockf(int, int, __off_t);
# 168 "/usr/include/fcntl.h" 3
extern "C" int lockf64(int, int, __off64_t);
# 176 "/usr/include/fcntl.h" 3
extern "C" int posix_fadvise(int, __off_t, __off_t, int) throw();
# 188 "/usr/include/fcntl.h" 3
extern "C" int posix_fadvise64(int, __off64_t, __off64_t, int) throw();
# 198 "/usr/include/fcntl.h" 3
extern "C" int posix_fallocate(int, __off_t, __off_t);
# 209 "/usr/include/fcntl.h" 3
extern "C" int posix_fallocate64(int, __off64_t, __off64_t);
# 240 "/usr/include/unistd.h" 3
extern "C" { typedef __intptr_t intptr_t; }
# 247 "/usr/include/unistd.h" 3
extern "C" { typedef __socklen_t socklen_t; }
# 260 "/usr/include/unistd.h" 3
extern "C" int access(const char *, int) throw() __attribute__((nonnull(1)));
# 265 "/usr/include/unistd.h" 3
extern "C" int euidaccess(const char *, int) throw() __attribute__((nonnull(1)));
# 269 "/usr/include/unistd.h" 3
extern "C" int eaccess(const char *, int) throw() __attribute__((nonnull(1)));
# 277 "/usr/include/unistd.h" 3
extern "C" int faccessat(int, const char *, int, int) throw() __attribute__((nonnull(2)));
# 303 "/usr/include/unistd.h" 3
extern "C" __off_t lseek(int, __off_t, int) throw();
# 314 "/usr/include/unistd.h" 3
extern "C" __off64_t lseek64(int, __off64_t, int) throw();
# 322 "/usr/include/unistd.h" 3
extern "C" int close(int);
# 329 "/usr/include/unistd.h" 3
extern "C" ssize_t read(int, void *, size_t);
# 335 "/usr/include/unistd.h" 3
extern "C" ssize_t write(int, const void *, size_t);
# 345 "/usr/include/unistd.h" 3
extern "C" ssize_t pread(int, void *, size_t, __off_t);
# 353 "/usr/include/unistd.h" 3
extern "C" ssize_t pwrite(int, const void *, size_t, __off_t);
# 373 "/usr/include/unistd.h" 3
extern "C" ssize_t pread64(int, void *, size_t, __off64_t);
# 377 "/usr/include/unistd.h" 3
extern "C" ssize_t pwrite64(int, const void *, size_t, __off64_t);
# 386 "/usr/include/unistd.h" 3
extern "C" int pipe(int [2]) throw();
# 391 "/usr/include/unistd.h" 3
extern "C" int pipe2(int [2], int) throw();
# 401 "/usr/include/unistd.h" 3
extern "C" unsigned alarm(unsigned) throw();
# 413 "/usr/include/unistd.h" 3
extern "C" unsigned sleep(unsigned);
# 420 "/usr/include/unistd.h" 3
extern "C" __useconds_t ualarm(__useconds_t, __useconds_t) throw();
# 428 "/usr/include/unistd.h" 3
extern "C" int usleep(__useconds_t);
# 437 "/usr/include/unistd.h" 3
extern "C" int pause();
# 441 "/usr/include/unistd.h" 3
extern "C" int chown(const char *, __uid_t, __gid_t) throw() __attribute__((nonnull(1)));
# 446 "/usr/include/unistd.h" 3
extern "C" int fchown(int, __uid_t, __gid_t) throw();
# 451 "/usr/include/unistd.h" 3
extern "C" int lchown(const char *, __uid_t, __gid_t) throw() __attribute__((nonnull(1)));
# 459 "/usr/include/unistd.h" 3
extern "C" int fchownat(int, const char *, __uid_t, __gid_t, int) throw() __attribute__((nonnull(2)));
# 465 "/usr/include/unistd.h" 3
extern "C" int chdir(const char *) throw() __attribute__((nonnull(1)));
# 469 "/usr/include/unistd.h" 3
extern "C" int fchdir(int) throw();
# 479 "/usr/include/unistd.h" 3
extern "C" char *getcwd(char *, size_t) throw();
# 485 "/usr/include/unistd.h" 3
extern "C" char *get_current_dir_name() throw();
# 492 "/usr/include/unistd.h" 3
extern "C" char *getwd(char *) throw() __attribute__((__deprecated__)) __attribute__((nonnull(1)));
# 498 "/usr/include/unistd.h" 3
extern "C" int dup(int) throw();
# 501 "/usr/include/unistd.h" 3
extern "C" int dup2(int, int) throw();
# 506 "/usr/include/unistd.h" 3
extern "C" int dup3(int, int, int) throw();
# 510 "/usr/include/unistd.h" 3
extern "C" { extern char **__environ; }
# 512 "/usr/include/unistd.h" 3
extern "C" { extern char **environ; }
# 518 "/usr/include/unistd.h" 3
extern "C" int execve(const char *, char *const [], char *const []) throw() __attribute__((nonnull(1)));
# 524 "/usr/include/unistd.h" 3
extern "C" int fexecve(int, char *const [], char *const []) throw();
# 530 "/usr/include/unistd.h" 3
extern "C" int execv(const char *, char *const []) throw() __attribute__((nonnull(1)));
# 535 "/usr/include/unistd.h" 3
extern "C" int execle(const char *, const char *, ...) throw() __attribute__((nonnull(1)));
# 540 "/usr/include/unistd.h" 3
extern "C" int execl(const char *, const char *, ...) throw() __attribute__((nonnull(1)));
# 545 "/usr/include/unistd.h" 3
extern "C" int execvp(const char *, char *const []) throw() __attribute__((nonnull(1)));
# 551 "/usr/include/unistd.h" 3
extern "C" int execlp(const char *, const char *, ...) throw() __attribute__((nonnull(1)));
# 557 "/usr/include/unistd.h" 3
extern "C" int nice(int) throw();
# 562 "/usr/include/unistd.h" 3
extern "C" void _exit(int) __attribute__((__noreturn__));
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
_CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS
# 672 "/usr/include/bits/confname.h" 3
};
# 571 "/usr/include/unistd.h" 3
extern "C" long pathconf(const char *, int) throw() __attribute__((nonnull(1)));
# 575 "/usr/include/unistd.h" 3
extern "C" long fpathconf(int, int) throw();
# 578 "/usr/include/unistd.h" 3
extern "C" long sysconf(int) throw();
# 582 "/usr/include/unistd.h" 3
extern "C" size_t confstr(int, char *, size_t) throw();
# 587 "/usr/include/unistd.h" 3
extern "C" __pid_t getpid() throw();
# 590 "/usr/include/unistd.h" 3
extern "C" __pid_t getppid() throw();
# 595 "/usr/include/unistd.h" 3
extern "C" __pid_t getpgrp() throw();
# 605 "/usr/include/unistd.h" 3
extern "C" __pid_t __getpgid(__pid_t) throw();
# 607 "/usr/include/unistd.h" 3
extern "C" __pid_t getpgid(__pid_t) throw();
# 614 "/usr/include/unistd.h" 3
extern "C" int setpgid(__pid_t, __pid_t) throw();
# 631 "/usr/include/unistd.h" 3
extern "C" int setpgrp() throw();
# 648 "/usr/include/unistd.h" 3
extern "C" __pid_t setsid() throw();
# 652 "/usr/include/unistd.h" 3
extern "C" __pid_t getsid(__pid_t) throw();
# 656 "/usr/include/unistd.h" 3
extern "C" __uid_t getuid() throw();
# 659 "/usr/include/unistd.h" 3
extern "C" __uid_t geteuid() throw();
# 662 "/usr/include/unistd.h" 3
extern "C" __gid_t getgid() throw();
# 665 "/usr/include/unistd.h" 3
extern "C" __gid_t getegid() throw();
# 670 "/usr/include/unistd.h" 3
extern "C" int getgroups(int, __gid_t []) throw();
# 674 "/usr/include/unistd.h" 3
extern "C" int group_member(__gid_t) throw();
# 681 "/usr/include/unistd.h" 3
extern "C" int setuid(__uid_t) throw();
# 686 "/usr/include/unistd.h" 3
extern "C" int setreuid(__uid_t, __uid_t) throw();
# 691 "/usr/include/unistd.h" 3
extern "C" int seteuid(__uid_t) throw();
# 698 "/usr/include/unistd.h" 3
extern "C" int setgid(__gid_t) throw();
# 703 "/usr/include/unistd.h" 3
extern "C" int setregid(__gid_t, __gid_t) throw();
# 708 "/usr/include/unistd.h" 3
extern "C" int setegid(__gid_t) throw();
# 714 "/usr/include/unistd.h" 3
extern "C" int getresuid(__uid_t *, __uid_t *, __uid_t *) throw();
# 719 "/usr/include/unistd.h" 3
extern "C" int getresgid(__gid_t *, __gid_t *, __gid_t *) throw();
# 724 "/usr/include/unistd.h" 3
extern "C" int setresuid(__uid_t, __uid_t, __uid_t) throw();
# 729 "/usr/include/unistd.h" 3
extern "C" int setresgid(__gid_t, __gid_t, __gid_t) throw();
# 737 "/usr/include/unistd.h" 3
extern "C" __pid_t fork() throw();
# 744 "/usr/include/unistd.h" 3
extern "C" __pid_t vfork() throw();
# 750 "/usr/include/unistd.h" 3
extern "C" char *ttyname(int) throw();
# 754 "/usr/include/unistd.h" 3
extern "C" int ttyname_r(int, char *, size_t) throw() __attribute__((nonnull(2)));
# 759 "/usr/include/unistd.h" 3
extern "C" int isatty(int) throw();
# 765 "/usr/include/unistd.h" 3
extern "C" int ttyslot() throw();
# 770 "/usr/include/unistd.h" 3
extern "C" int link(const char *, const char *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 776 "/usr/include/unistd.h" 3
extern "C" int linkat(int, const char *, int, const char *, int) throw() __attribute__((nonnull(2))) __attribute__((nonnull(4)));
# 783 "/usr/include/unistd.h" 3
extern "C" int symlink(const char *, const char *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 789 "/usr/include/unistd.h" 3
extern "C" ssize_t readlink(const char *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 796 "/usr/include/unistd.h" 3
extern "C" int symlinkat(const char *, int, const char *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(3)));
# 800 "/usr/include/unistd.h" 3
extern "C" ssize_t readlinkat(int, const char *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 806 "/usr/include/unistd.h" 3
extern "C" int unlink(const char *) throw() __attribute__((nonnull(1)));
# 810 "/usr/include/unistd.h" 3
extern "C" int unlinkat(int, const char *, int) throw() __attribute__((nonnull(2)));
# 815 "/usr/include/unistd.h" 3
extern "C" int rmdir(const char *) throw() __attribute__((nonnull(1)));
# 819 "/usr/include/unistd.h" 3
extern "C" __pid_t tcgetpgrp(int) throw();
# 822 "/usr/include/unistd.h" 3
extern "C" int tcsetpgrp(int, __pid_t) throw();
# 829 "/usr/include/unistd.h" 3
extern "C" char *getlogin();
# 837 "/usr/include/unistd.h" 3
extern "C" int getlogin_r(char *, size_t) __attribute__((nonnull(1)));
# 842 "/usr/include/unistd.h" 3
extern "C" int setlogin(const char *) throw() __attribute__((nonnull(1)));
# 59 "/usr/include/getopt.h" 3
extern "C" { extern char *optarg; }
# 73 "/usr/include/getopt.h" 3
extern "C" { extern int optind; }
# 78 "/usr/include/getopt.h" 3
extern "C" { extern int opterr; }
# 82 "/usr/include/getopt.h" 3
extern "C" { extern int optopt; }
# 152 "/usr/include/getopt.h" 3
extern "C" int getopt(int, char *const *, const char *) throw();
# 859 "/usr/include/unistd.h" 3
extern "C" int gethostname(char *, size_t) throw() __attribute__((nonnull(1)));
# 866 "/usr/include/unistd.h" 3
extern "C" int sethostname(const char *, size_t) throw() __attribute__((nonnull(1)));
# 871 "/usr/include/unistd.h" 3
extern "C" int sethostid(long) throw();
# 877 "/usr/include/unistd.h" 3
extern "C" int getdomainname(char *, size_t) throw() __attribute__((nonnull(1)));
# 879 "/usr/include/unistd.h" 3
extern "C" int setdomainname(const char *, size_t) throw() __attribute__((nonnull(1)));
# 886 "/usr/include/unistd.h" 3
extern "C" int vhangup() throw();
# 889 "/usr/include/unistd.h" 3
extern "C" int revoke(const char *) throw() __attribute__((nonnull(1)));
# 897 "/usr/include/unistd.h" 3
extern "C" int profil(unsigned short *, size_t, size_t, unsigned) throw() __attribute__((nonnull(1)));
# 905 "/usr/include/unistd.h" 3
extern "C" int acct(const char *) throw();
# 909 "/usr/include/unistd.h" 3
extern "C" char *getusershell() throw();
# 910 "/usr/include/unistd.h" 3
extern "C" void endusershell() throw();
# 911 "/usr/include/unistd.h" 3
extern "C" void setusershell() throw();
# 917 "/usr/include/unistd.h" 3
extern "C" int daemon(int, int) throw();
# 924 "/usr/include/unistd.h" 3
extern "C" int chroot(const char *) throw() __attribute__((nonnull(1)));
# 928 "/usr/include/unistd.h" 3
extern "C" char *getpass(const char *) __attribute__((nonnull(1)));
# 937 "/usr/include/unistd.h" 3
extern "C" int fsync(int);
# 944 "/usr/include/unistd.h" 3
extern "C" long gethostid();
# 947 "/usr/include/unistd.h" 3
extern "C" void sync() throw();
# 952 "/usr/include/unistd.h" 3
extern "C" int getpagesize() throw() __attribute__((__const__));
# 957 "/usr/include/unistd.h" 3
extern "C" int getdtablesize() throw();
# 962 "/usr/include/unistd.h" 3
extern "C" int truncate(const char *, __off_t) throw() __attribute__((nonnull(1)));
# 974 "/usr/include/unistd.h" 3
extern "C" int truncate64(const char *, __off64_t) throw() __attribute__((nonnull(1)));
# 984 "/usr/include/unistd.h" 3
extern "C" int ftruncate(int, __off_t) throw();
# 994 "/usr/include/unistd.h" 3
extern "C" int ftruncate64(int, __off64_t) throw();
# 1004 "/usr/include/unistd.h" 3
extern "C" int brk(void *) throw();
# 1010 "/usr/include/unistd.h" 3
extern "C" void *sbrk(intptr_t) throw();
# 1025 "/usr/include/unistd.h" 3
extern "C" long syscall(long, ...) throw();
# 1079 "/usr/include/unistd.h" 3
extern "C" int fdatasync(int);
# 1087 "/usr/include/unistd.h" 3
extern "C" char *crypt(const char *, const char *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 1092 "/usr/include/unistd.h" 3
extern "C" void encrypt(char *, int) throw() __attribute__((nonnull(1)));
# 1099 "/usr/include/unistd.h" 3
extern "C" void swab(const void *__restrict__, void *__restrict__, ssize_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 1108 "/usr/include/unistd.h" 3
extern "C" char *ctermid(char *) throw();
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
extern "C" intmax_t imaxabs(intmax_t) throw() __attribute__((__const__));
# 301 "/usr/include/inttypes.h" 3
extern "C" imaxdiv_t imaxdiv(intmax_t, intmax_t) throw() __attribute__((__const__));
# 305 "/usr/include/inttypes.h" 3
extern "C" intmax_t strtoimax(const char *__restrict__, char **__restrict__, int) throw();
# 309 "/usr/include/inttypes.h" 3
extern "C" uintmax_t strtoumax(const char *__restrict__, char **__restrict__, int) throw();
# 313 "/usr/include/inttypes.h" 3
extern "C" intmax_t wcstoimax(const wchar_t *__restrict__, wchar_t **__restrict__, int) throw();
# 318 "/usr/include/inttypes.h" 3
extern "C" uintmax_t wcstoumax(const wchar_t *__restrict__, wchar_t **__restrict__, int) throw();
# 43 "/usr/include/bits/errno.h" 3
extern "C" int *__errno_location() throw() __attribute__((__const__));
# 55 "/usr/include/errno.h" 3
extern "C" { extern char *program_invocation_name, *program_invocation_short_name; }
# 69 "/usr/include/errno.h" 3
extern "C" { typedef int error_t; }
# 54 "./avilib.h"
extern "C" { typedef
# 50 "./avilib.h"
struct {
# 51 "./avilib.h"
unsigned long key;
# 52 "./avilib.h"
unsigned long pos;
# 53 "./avilib.h"
unsigned long len;
# 54 "./avilib.h"
} video_index_entry; }
# 61 "./avilib.h"
extern "C" { typedef
# 57 "./avilib.h"
struct {
# 58 "./avilib.h"
unsigned long pos;
# 59 "./avilib.h"
unsigned long len;
# 60 "./avilib.h"
unsigned long tot;
# 61 "./avilib.h"
} audio_index_entry; }
# 85 "./avilib.h"
extern "C" { typedef
# 63 "./avilib.h"
struct track_s {
# 66 "./avilib.h"
long a_fmt;
# 67 "./avilib.h"
long a_chans;
# 68 "./avilib.h"
long a_rate;
# 69 "./avilib.h"
long a_bits;
# 70 "./avilib.h"
long mp3rate;
# 72 "./avilib.h"
long audio_strn;
# 73 "./avilib.h"
long audio_bytes;
# 74 "./avilib.h"
long audio_chunks;
# 76 "./avilib.h"
char audio_tag[4];
# 77 "./avilib.h"
long audio_posc;
# 78 "./avilib.h"
long audio_posb;
# 80 "./avilib.h"
long a_codech_off;
# 81 "./avilib.h"
long a_codecf_off;
# 83 "./avilib.h"
audio_index_entry *audio_index;
# 85 "./avilib.h"
} track_t; }
# 126 "./avilib.h"
extern "C" { typedef
# 88 "./avilib.h"
struct {
# 90 "./avilib.h"
long fdes;
# 91 "./avilib.h"
long mode;
# 93 "./avilib.h"
long width;
# 94 "./avilib.h"
long height;
# 95 "./avilib.h"
double fps;
# 96 "./avilib.h"
char compressor[8];
# 97 "./avilib.h"
char compressor2[8];
# 98 "./avilib.h"
long video_strn;
# 99 "./avilib.h"
long video_frames;
# 100 "./avilib.h"
char video_tag[4];
# 101 "./avilib.h"
long video_pos;
# 104 "./avilib.h"
unsigned long max_len;
# 106 "./avilib.h"
track_t track[8];
# 108 "./avilib.h"
unsigned long pos;
# 109 "./avilib.h"
long n_idx;
# 110 "./avilib.h"
long max_idx;
# 112 "./avilib.h"
long v_codech_off;
# 113 "./avilib.h"
long v_codecf_off;
# 115 "./avilib.h"
unsigned char (*idx)[16];
# 116 "./avilib.h"
video_index_entry *video_index;
# 118 "./avilib.h"
unsigned long last_pos;
# 119 "./avilib.h"
unsigned long last_len;
# 120 "./avilib.h"
int must_use_index;
# 121 "./avilib.h"
unsigned long movi_start;
# 123 "./avilib.h"
int anum;
# 124 "./avilib.h"
int aptr;
# 126 "./avilib.h"
} avi_t; }
# 195 "./avilib.h"
extern "C" avi_t *AVI_open_output_file(char *);
# 196 "./avilib.h"
extern "C" void AVI_set_video(avi_t *, int, int, double, char *);
# 197 "./avilib.h"
extern "C" void AVI_set_audio(avi_t *, int, long, int, int, long);
# 198 "./avilib.h"
extern "C" int AVI_write_frame(avi_t *, char *, long, int);
# 199 "./avilib.h"
extern "C" int AVI_dup_frame(avi_t *);
# 200 "./avilib.h"
extern "C" int AVI_write_audio(avi_t *, char *, long);
# 201 "./avilib.h"
extern "C" int AVI_append_audio(avi_t *, char *, long);
# 202 "./avilib.h"
extern "C" long AVI_bytes_remain(avi_t *);
# 203 "./avilib.h"
extern "C" int AVI_close(avi_t *);
# 204 "./avilib.h"
extern "C" long AVI_bytes_written(avi_t *);
# 206 "./avilib.h"
extern "C" avi_t *AVI_open_input_file(char *, int);
# 207 "./avilib.h"
extern "C" avi_t *AVI_open_fd(int, int);
# 208 "./avilib.h"
extern "C" int avi_parse_input_file(avi_t *, int);
# 209 "./avilib.h"
extern "C" long AVI_audio_mp3rate(avi_t *);
# 210 "./avilib.h"
extern "C" long AVI_video_frames(avi_t *);
# 211 "./avilib.h"
extern "C" int AVI_video_width(avi_t *);
# 212 "./avilib.h"
extern "C" int AVI_video_height(avi_t *);
# 213 "./avilib.h"
extern "C" double AVI_frame_rate(avi_t *);
# 214 "./avilib.h"
extern "C" char *AVI_video_compressor(avi_t *);
# 216 "./avilib.h"
extern "C" int AVI_audio_channels(avi_t *);
# 217 "./avilib.h"
extern "C" int AVI_audio_bits(avi_t *);
# 218 "./avilib.h"
extern "C" int AVI_audio_format(avi_t *);
# 219 "./avilib.h"
extern "C" long AVI_audio_rate(avi_t *);
# 220 "./avilib.h"
extern "C" long AVI_audio_bytes(avi_t *);
# 221 "./avilib.h"
extern "C" long AVI_audio_chunks(avi_t *);
# 223 "./avilib.h"
extern "C" long AVI_max_video_chunk(avi_t *);
# 225 "./avilib.h"
extern "C" long AVI_frame_size(avi_t *, long);
# 226 "./avilib.h"
extern "C" long AVI_audio_size(avi_t *, long);
# 227 "./avilib.h"
extern "C" int AVI_seek_start(avi_t *);
# 228 "./avilib.h"
extern "C" int AVI_set_video_position(avi_t *, long);
# 229 "./avilib.h"
extern "C" long AVI_get_video_position(avi_t *, long);
# 230 "./avilib.h"
extern "C" long AVI_read_frame(avi_t *, char *, int *);
# 232 "./avilib.h"
extern "C" int AVI_set_audio_position(avi_t *, long);
# 233 "./avilib.h"
extern "C" int AVI_set_audio_bitrate(avi_t *, long);
# 235 "./avilib.h"
extern "C" long AVI_read_audio(avi_t *, char *, long);
# 237 "./avilib.h"
extern "C" long AVI_audio_codech_offset(avi_t *);
# 238 "./avilib.h"
extern "C" long AVI_audio_codecf_offset(avi_t *);
# 239 "./avilib.h"
extern "C" long AVI_video_codech_offset(avi_t *);
# 240 "./avilib.h"
extern "C" long AVI_video_codecf_offset(avi_t *);
# 242 "./avilib.h"
extern "C" int AVI_read_data(avi_t *, char *, long, char *, long, long *);
# 246 "./avilib.h"
extern "C" void AVI_print_error(char *);
# 247 "./avilib.h"
extern "C" char *AVI_strerror();
# 248 "./avilib.h"
extern "C" char *AVI_syserror();
# 250 "./avilib.h"
extern "C" int AVI_scan(char *);
# 251 "./avilib.h"
extern "C" int AVI_dump(char *, int);
# 253 "./avilib.h"
extern "C" char *AVI_codec2str(short);
# 254 "./avilib.h"
extern "C" int AVI_file_check(char *);
# 256 "./avilib.h"
extern "C" void AVI_info(avi_t *);
# 257 "./avilib.h"
extern "C" uint64_t AVI_max_size();
# 258 "./avilib.h"
extern "C" int avi_update_header(avi_t *);
# 260 "./avilib.h"
extern "C" int AVI_set_audio_track(avi_t *, int);
# 261 "./avilib.h"
extern "C" int AVI_get_audio_track(avi_t *);
# 262 "./avilib.h"
extern "C" int AVI_audio_tracks(avi_t *);
# 264 "./avilib.h"
extern "C" { struct riff_struct {
# 266 "./avilib.h"
unsigned char id[4];
# 267 "./avilib.h"
unsigned long len;
# 268 "./avilib.h"
unsigned char wave_id[4];
# 269 "./avilib.h"
}; }
# 272 "./avilib.h"
extern "C" { struct chunk_struct {
# 274 "./avilib.h"
unsigned char id[4];
# 275 "./avilib.h"
unsigned long len;
# 276 "./avilib.h"
}; }
# 278 "./avilib.h"
extern "C" { struct common_struct {
# 280 "./avilib.h"
unsigned short wFormatTag;
# 281 "./avilib.h"
unsigned short wChannels;
# 282 "./avilib.h"
unsigned long dwSamplesPerSec;
# 283 "./avilib.h"
unsigned long dwAvgBytesPerSec;
# 284 "./avilib.h"
unsigned short wBlockAlign;
# 285 "./avilib.h"
unsigned short wBitsPerSample;
# 286 "./avilib.h"
}; }
# 288 "./avilib.h"
extern "C" { struct wave_header {
# 290 "./avilib.h"
riff_struct riff;
# 291 "./avilib.h"
chunk_struct format;
# 292 "./avilib.h"
common_struct common;
# 293 "./avilib.h"
chunk_struct data;
# 294 "./avilib.h"
}; }
# 298 "./avilib.h"
extern "C" { struct AVIStreamHeader {
# 299 "./avilib.h"
long fccType;
# 300 "./avilib.h"
long fccHandler;
# 301 "./avilib.h"
long dwFlags;
# 302 "./avilib.h"
long dwPriority;
# 303 "./avilib.h"
long dwInitialFrames;
# 304 "./avilib.h"
long dwScale;
# 305 "./avilib.h"
long dwRate;
# 306 "./avilib.h"
long dwStart;
# 307 "./avilib.h"
long dwLength;
# 308 "./avilib.h"
long dwSuggestedBufferSize;
# 309 "./avilib.h"
long dwQuality;
# 310 "./avilib.h"
long dwSampleSize;
# 311 "./avilib.h"
}; }
# 16 "./avimod.h"
extern "C" float *chop_flip_image(char *, int, int, int, int, int);
# 23 "./avimod.h"
extern "C" float *get_frame(avi_t *, int, int, int, int);
# 62 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }
# 64 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 65 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 66 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 67 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 68 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 69 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 70 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUevent_st *CUevent; }
# 71 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUstream_st *CUstream; }
# 72 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUgraphicsResource_st *CUgraphicsResource; }
# 92 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 83 "/home/normal/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
# 84 "/home/normal/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 85 "/home/normal/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 86 "/home/normal/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 87 "/home/normal/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_MASK,
# 88 "/home/normal/cuda/bin/../include/cuda.h"
CU_CTX_BLOCKING_SYNC,
# 89 "/home/normal/cuda/bin/../include/cuda.h"
CU_CTX_MAP_HOST = 8,
# 90 "/home/normal/cuda/bin/../include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 91 "/home/normal/cuda/bin/../include/cuda.h"
CU_CTX_FLAGS_MASK = 31
# 92 "/home/normal/cuda/bin/../include/cuda.h"
} CUctx_flags; }
# 100 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 97 "/home/normal/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
# 98 "/home/normal/cuda/bin/../include/cuda.h"
CU_EVENT_DEFAULT,
# 99 "/home/normal/cuda/bin/../include/cuda.h"
CU_EVENT_BLOCKING_SYNC
# 100 "/home/normal/cuda/bin/../include/cuda.h"
} CUevent_flags; }
# 114 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 105 "/home/normal/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
# 106 "/home/normal/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 107 "/home/normal/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 108 "/home/normal/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 109 "/home/normal/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 110 "/home/normal/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 111 "/home/normal/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 112 "/home/normal/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 113 "/home/normal/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 114 "/home/normal/cuda/bin/../include/cuda.h"
} CUarray_format; }
# 123 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 119 "/home/normal/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
# 120 "/home/normal/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 121 "/home/normal/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 122 "/home/normal/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR
# 123 "/home/normal/cuda/bin/../include/cuda.h"
} CUaddress_mode; }
# 131 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 128 "/home/normal/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
# 129 "/home/normal/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 130 "/home/normal/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 131 "/home/normal/cuda/bin/../include/cuda.h"
} CUfilter_mode; }
# 169 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 136 "/home/normal/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
# 137 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 138 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 139 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 140 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 141 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 142 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 143 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 144 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 145 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 146 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 147 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 148 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 149 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 150 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 151 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 152 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 154 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 155 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 156 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 157 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 158 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 159 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 160 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 161 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 162 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 163 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 164 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 165 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 166 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH,
# 167 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 168 "/home/normal/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES
# 169 "/home/normal/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 185 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 174 "/home/normal/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 175 "/home/normal/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 176 "/home/normal/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 177 "/home/normal/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 178 "/home/normal/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 179 "/home/normal/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 180 "/home/normal/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 181 "/home/normal/cuda/bin/../include/cuda.h"
int memPitch;
# 182 "/home/normal/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 183 "/home/normal/cuda/bin/../include/cuda.h"
int clockRate;
# 184 "/home/normal/cuda/bin/../include/cuda.h"
int textureAlign;
# 185 "/home/normal/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 222 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 190 "/home/normal/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 196 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 203 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 209 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 214 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 219 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 221 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 222 "/home/normal/cuda/bin/../include/cuda.h"
} CUfunction_attribute; }
# 231 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 227 "/home/normal/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 228 "/home/normal/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 229 "/home/normal/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 230 "/home/normal/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 231 "/home/normal/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 240 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 236 "/home/normal/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
# 237 "/home/normal/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 238 "/home/normal/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 239 "/home/normal/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_PROHIBITED
# 240 "/home/normal/cuda/bin/../include/cuda.h"
} CUcomputemode; }
# 319 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 245 "/home/normal/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 250 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 262 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 268 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 274 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 281 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 287 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 294 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 300 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 306 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 311 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 317 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 319 "/home/normal/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 331 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 324 "/home/normal/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 326 "/home/normal/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 327 "/home/normal/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 328 "/home/normal/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 329 "/home/normal/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13,
# 330 "/home/normal/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_20
# 331 "/home/normal/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 344 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 336 "/home/normal/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 339 "/home/normal/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 342 "/home/normal/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 344 "/home/normal/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 351 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 349 "/home/normal/cuda/bin/../include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 350 "/home/normal/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE
# 351 "/home/normal/cuda/bin/../include/cuda.h"
} CUgraphicsRegisterFlags; }
# 360 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 356 "/home/normal/cuda/bin/../include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 357 "/home/normal/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 358 "/home/normal/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 359 "/home/normal/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 360 "/home/normal/cuda/bin/../include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 372 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 365 "/home/normal/cuda/bin/../include/cuda.h"
enum CUarray_cubemap_face_enum {
# 366 "/home/normal/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 367 "/home/normal/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 368 "/home/normal/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 369 "/home/normal/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 370 "/home/normal/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 371 "/home/normal/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 372 "/home/normal/cuda/bin/../include/cuda.h"
} CUarray_cubemap_face; }
# 425 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 383 "/home/normal/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 385 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 386 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 387 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 388 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 389 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 391 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 392 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 394 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 395 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 396 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 397 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 398 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 399 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 400 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 401 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 402 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 403 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 404 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 405 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 407 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 408 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 410 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 412 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 414 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 416 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 417 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 418 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 419 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 421 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_POINTER_IS_64BIT = 800,
# 422 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_SIZE_IS_64BIT,
# 424 "/home/normal/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 425 "/home/normal/cuda/bin/../include/cuda.h"
} CUresult; }
# 471 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 451 "/home/normal/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 453 "/home/normal/cuda/bin/../include/cuda.h"
unsigned srcXInBytes,
# 454 "/home/normal/cuda/bin/../include/cuda.h"
srcY;
# 455 "/home/normal/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 456 "/home/normal/cuda/bin/../include/cuda.h"
const void *srcHost;
# 457 "/home/normal/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 458 "/home/normal/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 459 "/home/normal/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 461 "/home/normal/cuda/bin/../include/cuda.h"
unsigned dstXInBytes,
# 462 "/home/normal/cuda/bin/../include/cuda.h"
dstY;
# 463 "/home/normal/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 464 "/home/normal/cuda/bin/../include/cuda.h"
void *dstHost;
# 465 "/home/normal/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 466 "/home/normal/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 467 "/home/normal/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 469 "/home/normal/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 470 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Height;
# 471 "/home/normal/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 505 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 476 "/home/normal/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 478 "/home/normal/cuda/bin/../include/cuda.h"
unsigned srcXInBytes,
# 479 "/home/normal/cuda/bin/../include/cuda.h"
srcY,
# 480 "/home/normal/cuda/bin/../include/cuda.h"
srcZ;
# 481 "/home/normal/cuda/bin/../include/cuda.h"
unsigned srcLOD;
# 482 "/home/normal/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 483 "/home/normal/cuda/bin/../include/cuda.h"
const void *srcHost;
# 484 "/home/normal/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 485 "/home/normal/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 486 "/home/normal/cuda/bin/../include/cuda.h"
void *reserved0;
# 487 "/home/normal/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 488 "/home/normal/cuda/bin/../include/cuda.h"
unsigned srcHeight;
# 490 "/home/normal/cuda/bin/../include/cuda.h"
unsigned dstXInBytes,
# 491 "/home/normal/cuda/bin/../include/cuda.h"
dstY,
# 492 "/home/normal/cuda/bin/../include/cuda.h"
dstZ;
# 493 "/home/normal/cuda/bin/../include/cuda.h"
unsigned dstLOD;
# 494 "/home/normal/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 495 "/home/normal/cuda/bin/../include/cuda.h"
void *dstHost;
# 496 "/home/normal/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 497 "/home/normal/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 498 "/home/normal/cuda/bin/../include/cuda.h"
void *reserved1;
# 499 "/home/normal/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 500 "/home/normal/cuda/bin/../include/cuda.h"
unsigned dstHeight;
# 502 "/home/normal/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 503 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Height;
# 504 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Depth;
# 505 "/home/normal/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 538 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 507 "/home/normal/cuda/bin/../include/cuda.h"
struct CUDA64_MEMCPY3D_st {
# 509 "/home/normal/cuda/bin/../include/cuda.h"
size_t srcXInBytes,
# 510 "/home/normal/cuda/bin/../include/cuda.h"
srcY,
# 511 "/home/normal/cuda/bin/../include/cuda.h"
srcZ;
# 512 "/home/normal/cuda/bin/../include/cuda.h"
unsigned srcLOD;
# 513 "/home/normal/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 514 "/home/normal/cuda/bin/../include/cuda.h"
const void *srcHost;
# 515 "/home/normal/cuda/bin/../include/cuda.h"
void *srcDevice;
# 516 "/home/normal/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 517 "/home/normal/cuda/bin/../include/cuda.h"
void *reserved0;
# 518 "/home/normal/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 519 "/home/normal/cuda/bin/../include/cuda.h"
size_t srcHeight;
# 521 "/home/normal/cuda/bin/../include/cuda.h"
size_t dstXInBytes,
# 522 "/home/normal/cuda/bin/../include/cuda.h"
dstY,
# 523 "/home/normal/cuda/bin/../include/cuda.h"
dstZ;
# 524 "/home/normal/cuda/bin/../include/cuda.h"
unsigned dstLOD;
# 525 "/home/normal/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 526 "/home/normal/cuda/bin/../include/cuda.h"
void *dstHost;
# 527 "/home/normal/cuda/bin/../include/cuda.h"
void *dstDevice;
# 528 "/home/normal/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 529 "/home/normal/cuda/bin/../include/cuda.h"
void *reserved1;
# 530 "/home/normal/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 531 "/home/normal/cuda/bin/../include/cuda.h"
size_t dstHeight;
# 533 "/home/normal/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 534 "/home/normal/cuda/bin/../include/cuda.h"
size_t Height;
# 535 "/home/normal/cuda/bin/../include/cuda.h"
size_t Depth;
# 537 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Flags;
# 538 "/home/normal/cuda/bin/../include/cuda.h"
} CUDA64_MEMCPY3D; }
# 551 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 544 "/home/normal/cuda/bin/../include/cuda.h"
struct {
# 545 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Width;
# 546 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Height;
# 548 "/home/normal/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 550 "/home/normal/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 551 "/home/normal/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 567 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 557 "/home/normal/cuda/bin/../include/cuda.h"
struct {
# 558 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Width;
# 559 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Height;
# 560 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Depth;
# 562 "/home/normal/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 564 "/home/normal/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 566 "/home/normal/cuda/bin/../include/cuda.h"
unsigned Flags;
# 567 "/home/normal/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 611 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 616 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int *);
# 624 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 625 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 626 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 627 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 628 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
# 629 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 630 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 638 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
# 639 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 640 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 641 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 642 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 643 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 644 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 645 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 654 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 655 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 656 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 657 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 658 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 659 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 660 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
# 661 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 669 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);
# 671 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
# 672 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 680 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
# 681 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);
# 683 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost(void **, unsigned);
# 684 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 686 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);
# 688 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer(CUdeviceptr *, void *, unsigned);
# 689 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned *, void *);
# 702 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD(CUdeviceptr, const void *, unsigned);
# 703 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH(void *, CUdeviceptr, unsigned);
# 706 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD(CUdeviceptr, CUdeviceptr, unsigned);
# 709 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA(CUarray, unsigned, CUdeviceptr, unsigned);
# 710 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD(CUdeviceptr, CUarray, unsigned, unsigned);
# 713 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA(CUarray, unsigned, const void *, unsigned);
# 714 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH(void *, CUarray, unsigned, unsigned);
# 717 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA(CUarray, unsigned, CUarray, unsigned, unsigned);
# 721 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D(const CUDA_MEMCPY2D *);
# 722 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *);
# 726 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D(const CUDA_MEMCPY3D *);
# 741 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);
# 743 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);
# 747 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync(CUdeviceptr, CUdeviceptr, unsigned, CUstream);
# 751 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);
# 753 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);
# 757 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);
# 760 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 767 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
# 768 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
# 769 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);
# 771 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
# 772 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
# 773 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 782 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 783 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 784 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 792 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 793 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 794 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 796 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 797 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 805 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 806 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 808 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 809 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress(unsigned *, CUtexref, CUdeviceptr, unsigned);
# 810 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, unsigned);
# 811 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 812 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 813 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 814 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 816 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress(CUdeviceptr *, CUtexref);
# 817 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 818 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 819 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 820 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 821 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 829 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 830 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 831 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 832 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 833 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 841 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 842 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 843 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 850 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 851 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 852 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 853 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 854 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 855 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 862 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 863 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 864 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 865 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamDestroy(CUstream);
# 872 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource);
# 873 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray *, CUgraphicsResource, unsigned, unsigned);
# 874 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer(CUdeviceptr *, unsigned *, CUgraphicsResource);
# 875 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource, unsigned);
# 876 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned, CUgraphicsResource *, CUstream);
# 877 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned, CUgraphicsResource *, CUstream);
# 30 "define.c"
typedef
# 21 "define.c"
struct params_common_change {
# 27 "define.c"
float *d_frame;
# 28 "define.c"
int frame_no;
# 30 "define.c"
} params_common_change;
# 262 "define.c"
typedef
# 38 "define.c"
struct params_common {
# 48 "define.c"
int sSize;
# 49 "define.c"
int tSize;
# 50 "define.c"
int maxMove;
# 51 "define.c"
float alpha;
# 57 "define.c"
int no_frames;
# 58 "define.c"
int frame_rows;
# 59 "define.c"
int frame_cols;
# 60 "define.c"
int frame_elem;
# 61 "define.c"
int frame_mem;
# 67 "define.c"
int endoPoints;
# 68 "define.c"
int endo_mem;
# 70 "define.c"
int *endoRow;
# 71 "define.c"
int *endoCol;
# 72 "define.c"
int *tEndoRowLoc;
# 73 "define.c"
int *tEndoColLoc;
# 75 "define.c"
int *d_endoRow;
# 76 "define.c"
int *d_endoCol;
# 77 "define.c"
int *d_tEndoRowLoc;
# 78 "define.c"
int *d_tEndoColLoc;
# 80 "define.c"
float *d_endoT;
# 85 "define.c"
int epiPoints;
# 86 "define.c"
int epi_mem;
# 88 "define.c"
int *epiRow;
# 89 "define.c"
int *epiCol;
# 90 "define.c"
int *tEpiRowLoc;
# 91 "define.c"
int *tEpiColLoc;
# 93 "define.c"
int *d_epiRow;
# 94 "define.c"
int *d_epiCol;
# 95 "define.c"
int *d_tEpiRowLoc;
# 96 "define.c"
int *d_tEpiColLoc;
# 98 "define.c"
float *d_epiT;
# 104 "define.c"
int allPoints;
# 110 "define.c"
int in_rows;
# 111 "define.c"
int in_cols;
# 112 "define.c"
int in_elem;
# 113 "define.c"
int in_mem;
# 119 "define.c"
int in2_rows;
# 120 "define.c"
int in2_cols;
# 121 "define.c"
int in2_elem;
# 122 "define.c"
int in2_mem;
# 128 "define.c"
int conv_rows;
# 129 "define.c"
int conv_cols;
# 130 "define.c"
int conv_elem;
# 131 "define.c"
int conv_mem;
# 132 "define.c"
int ioffset;
# 133 "define.c"
int joffset;
# 143 "define.c"
int in2_pad_add_rows;
# 144 "define.c"
int in2_pad_add_cols;
# 145 "define.c"
int in2_pad_cumv_rows;
# 146 "define.c"
int in2_pad_cumv_cols;
# 147 "define.c"
int in2_pad_cumv_elem;
# 148 "define.c"
int in2_pad_cumv_mem;
# 154 "define.c"
int in2_pad_cumv_sel_rows;
# 155 "define.c"
int in2_pad_cumv_sel_cols;
# 156 "define.c"
int in2_pad_cumv_sel_elem;
# 157 "define.c"
int in2_pad_cumv_sel_mem;
# 158 "define.c"
int in2_pad_cumv_sel_rowlow;
# 159 "define.c"
int in2_pad_cumv_sel_rowhig;
# 160 "define.c"
int in2_pad_cumv_sel_collow;
# 161 "define.c"
int in2_pad_cumv_sel_colhig;
# 167 "define.c"
int in2_pad_cumv_sel2_rowlow;
# 168 "define.c"
int in2_pad_cumv_sel2_rowhig;
# 169 "define.c"
int in2_pad_cumv_sel2_collow;
# 170 "define.c"
int in2_pad_cumv_sel2_colhig;
# 171 "define.c"
int in2_sub_cumh_rows;
# 172 "define.c"
int in2_sub_cumh_cols;
# 173 "define.c"
int in2_sub_cumh_elem;
# 174 "define.c"
int in2_sub_cumh_mem;
# 180 "define.c"
int in2_sub_cumh_sel_rows;
# 181 "define.c"
int in2_sub_cumh_sel_cols;
# 182 "define.c"
int in2_sub_cumh_sel_elem;
# 183 "define.c"
int in2_sub_cumh_sel_mem;
# 184 "define.c"
int in2_sub_cumh_sel_rowlow;
# 185 "define.c"
int in2_sub_cumh_sel_rowhig;
# 186 "define.c"
int in2_sub_cumh_sel_collow;
# 187 "define.c"
int in2_sub_cumh_sel_colhig;
# 193 "define.c"
int in2_sub_cumh_sel2_rowlow;
# 194 "define.c"
int in2_sub_cumh_sel2_rowhig;
# 195 "define.c"
int in2_sub_cumh_sel2_collow;
# 196 "define.c"
int in2_sub_cumh_sel2_colhig;
# 197 "define.c"
int in2_sub2_rows;
# 198 "define.c"
int in2_sub2_cols;
# 199 "define.c"
int in2_sub2_elem;
# 200 "define.c"
int in2_sub2_mem;
# 210 "define.c"
int in2_sqr_rows;
# 211 "define.c"
int in2_sqr_cols;
# 212 "define.c"
int in2_sqr_elem;
# 213 "define.c"
int in2_sqr_mem;
# 219 "define.c"
int in2_sqr_sub2_rows;
# 220 "define.c"
int in2_sqr_sub2_cols;
# 221 "define.c"
int in2_sqr_sub2_elem;
# 222 "define.c"
int in2_sqr_sub2_mem;
# 228 "define.c"
int in_sqr_rows;
# 229 "define.c"
int in_sqr_cols;
# 230 "define.c"
int in_sqr_elem;
# 231 "define.c"
int in_sqr_mem;
# 237 "define.c"
int tMask_rows;
# 238 "define.c"
int tMask_cols;
# 239 "define.c"
int tMask_elem;
# 240 "define.c"
int tMask_mem;
# 246 "define.c"
int mask_rows;
# 247 "define.c"
int mask_cols;
# 248 "define.c"
int mask_elem;
# 249 "define.c"
int mask_mem;
# 255 "define.c"
int mask_conv_rows;
# 256 "define.c"
int mask_conv_cols;
# 257 "define.c"
int mask_conv_elem;
# 258 "define.c"
int mask_conv_mem;
# 259 "define.c"
int mask_conv_ioffset;
# 260 "define.c"
int mask_conv_joffset;
# 262 "define.c"
} params_common;
# 381 "define.c"
typedef
# 270 "define.c"
struct params_unique {
# 276 "define.c"
int *d_Row;
# 277 "define.c"
int *d_Col;
# 278 "define.c"
int *d_tRowLoc;
# 279 "define.c"
int *d_tColLoc;
# 280 "define.c"
float *d_T;
# 286 "define.c"
int point_no;
# 292 "define.c"
int in_pointer;
# 298 "define.c"
float *d_in2;
# 304 "define.c"
float *d_conv;
# 305 "define.c"
float *d_in_mod;
# 315 "define.c"
float *d_in2_pad_cumv;
# 321 "define.c"
float *d_in2_pad_cumv_sel;
# 327 "define.c"
float *d_in2_sub_cumh;
# 333 "define.c"
float *d_in2_sub_cumh_sel;
# 339 "define.c"
float *d_in2_sub2;
# 349 "define.c"
float *d_in2_sqr;
# 355 "define.c"
float *d_in2_sqr_sub2;
# 361 "define.c"
float *d_in_sqr;
# 367 "define.c"
float *d_tMask;
# 373 "define.c"
float *d_mask;
# 379 "define.c"
float *d_mask_conv;
# 381 "define.c"
} params_unique;
# 25 "main.cu"
params_common_change common_change;
# 26 "main.cu"
static params_common_change d_common_change__cuda_shadow_variable__;
# 28 "main.cu"
params_common common;
# 29 "main.cu"
static params_common d_common__cuda_shadow_variable__;
# 31 "main.cu"
params_unique unique[51];
# 32 "main.cu"
static params_unique d_unique__cuda_shadow_variable__[51];
# 7 "kernel.cu"
void kernel__entry();
# 46 "main.cu"
int main(int argc, char *argv[]) {
# 53 "main.cu"
dim3 threads;
# 54 "main.cu"
dim3 blocks;
# 57 "main.cu"
int i;
# 58 "main.cu"
int frames_processed;
# 61 "main.cu"
char *video_file_name;
# 62 "main.cu"
avi_t *frames;
# 63 "main.cu"
float *frame;
# 70 "main.cu"
video_file_name = ((char *)("data/hwt.avi"));
# 71 "main.cu"
frames = ((avi_t *)AVI_open_input_file(video_file_name, 1));
# 72 "main.cu"
if (frames == (__null)) {
# 73 "main.cu"
AVI_print_error((char *)("Error with AVI_open_input_file"));
# 74 "main.cu"
return -1;
# 75 "main.cu"
}
# 78 "main.cu"
(common.no_frames) = (AVI_video_frames(frames));
# 79 "main.cu"
(common.frame_rows) = AVI_video_height(frames);
# 80 "main.cu"
(common.frame_cols) = AVI_video_width(frames);
# 81 "main.cu"
(common.frame_elem) = ((common.frame_rows) * (common.frame_cols));
# 82 "main.cu"
(common.frame_mem) = (sizeof(float) * (common.frame_elem));
# 85 "main.cu"
cudaMalloc((void **)(&(common_change.d_frame)), common.frame_mem);
# 91 "main.cu"
if (argc != 2) {
# 92 "main.cu"
printf("ERROR: missing argument (number of frames to processed) or too many arguments\n");
# 93 "main.cu"
return 0;
# 94 "main.cu"
} else
# 95 "main.cu"
{
# 96 "main.cu"
frames_processed = atoi(argv[1]);
# 97 "main.cu"
if ((frames_processed < 0) || (frames_processed > (common.no_frames))) {
# 98 "main.cu"
printf("ERROR: %d is an incorrect number of frames specified, select in the range of 0-%d\n", frames_processed, common.no_frames);
# 99 "main.cu"
return 0;
# 100 "main.cu"
}
# 101 "main.cu"
}
# 111 "main.cu"
(common.sSize) = 40;
# 112 "main.cu"
(common.tSize) = 25;
# 113 "main.cu"
(common.maxMove) = 10;
# 114 "main.cu"
(common.alpha) = ((0.8699999999999999956));
# 120 "main.cu"
(common.endoPoints) = 20;
# 121 "main.cu"
(common.endo_mem) = (sizeof(int) * (common.endoPoints));
# 123 "main.cu"
(common.endoRow) = ((int *)malloc(common.endo_mem));
# 124 "main.cu"
((common.endoRow)[0]) = 369;
# 125 "main.cu"
((common.endoRow)[1]) = 400;
# 126 "main.cu"
((common.endoRow)[2]) = 429;
# 127 "main.cu"
((common.endoRow)[3]) = 452;
# 128 "main.cu"
((common.endoRow)[4]) = 476;
# 129 "main.cu"
((common.endoRow)[5]) = 486;
# 130 "main.cu"
((common.endoRow)[6]) = 479;
# 131 "main.cu"
((common.endoRow)[7]) = 458;
# 132 "main.cu"
((common.endoRow)[8]) = 433;
# 133 "main.cu"
((common.endoRow)[9]) = 404;
# 134 "main.cu"
((common.endoRow)[10]) = 374;
# 135 "main.cu"
((common.endoRow)[11]) = 346;
# 136 "main.cu"
((common.endoRow)[12]) = 318;
# 137 "main.cu"
((common.endoRow)[13]) = 294;
# 138 "main.cu"
((common.endoRow)[14]) = 277;
# 139 "main.cu"
((common.endoRow)[15]) = 269;
# 140 "main.cu"
((common.endoRow)[16]) = 275;
# 141 "main.cu"
((common.endoRow)[17]) = 287;
# 142 "main.cu"
((common.endoRow)[18]) = 311;
# 143 "main.cu"
((common.endoRow)[19]) = 339;
# 144 "main.cu"
cudaMalloc((void **)(&(common.d_endoRow)), common.endo_mem);
# 145 "main.cu"
cudaMemcpy(common.d_endoRow, common.endoRow, common.endo_mem, cudaMemcpyHostToDevice);
# 147 "main.cu"
(common.endoCol) = ((int *)malloc(common.endo_mem));
# 148 "main.cu"
((common.endoCol)[0]) = 408;
# 149 "main.cu"
((common.endoCol)[1]) = 406;
# 150 "main.cu"
((common.endoCol)[2]) = 397;
# 151 "main.cu"
((common.endoCol)[3]) = 383;
# 152 "main.cu"
((common.endoCol)[4]) = 354;
# 153 "main.cu"
((common.endoCol)[5]) = 322;
# 154 "main.cu"
((common.endoCol)[6]) = 294;
# 155 "main.cu"
((common.endoCol)[7]) = 270;
# 156 "main.cu"
((common.endoCol)[8]) = 250;
# 157 "main.cu"
((common.endoCol)[9]) = 237;
# 158 "main.cu"
((common.endoCol)[10]) = 235;
# 159 "main.cu"
((common.endoCol)[11]) = 241;
# 160 "main.cu"
((common.endoCol)[12]) = 254;
# 161 "main.cu"
((common.endoCol)[13]) = 273;
# 162 "main.cu"
((common.endoCol)[14]) = 300;
# 163 "main.cu"
((common.endoCol)[15]) = 328;
# 164 "main.cu"
((common.endoCol)[16]) = 356;
# 165 "main.cu"
((common.endoCol)[17]) = 383;
# 166 "main.cu"
((common.endoCol)[18]) = 401;
# 167 "main.cu"
((common.endoCol)[19]) = 411;
# 168 "main.cu"
cudaMalloc((void **)(&(common.d_endoCol)), common.endo_mem);
# 169 "main.cu"
cudaMemcpy(common.d_endoCol, common.endoCol, common.endo_mem, cudaMemcpyHostToDevice);
# 171 "main.cu"
(common.tEndoRowLoc) = ((int *)malloc((common.endo_mem) * (common.no_frames)));
# 172 "main.cu"
cudaMalloc((void **)(&(common.d_tEndoRowLoc)), (common.endo_mem) * (common.no_frames));
# 174 "main.cu"
(common.tEndoColLoc) = ((int *)malloc((common.endo_mem) * (common.no_frames)));
# 175 "main.cu"
cudaMalloc((void **)(&(common.d_tEndoColLoc)), (common.endo_mem) * (common.no_frames));
# 181 "main.cu"
(common.epiPoints) = 31;
# 182 "main.cu"
(common.epi_mem) = (sizeof(int) * (common.epiPoints));
# 184 "main.cu"
(common.epiRow) = ((int *)malloc(common.epi_mem));
# 185 "main.cu"
((common.epiRow)[0]) = 390;
# 186 "main.cu"
((common.epiRow)[1]) = 419;
# 187 "main.cu"
((common.epiRow)[2]) = 448;
# 188 "main.cu"
((common.epiRow)[3]) = 474;
# 189 "main.cu"
((common.epiRow)[4]) = 501;
# 190 "main.cu"
((common.epiRow)[5]) = 519;
# 191 "main.cu"
((common.epiRow)[6]) = 535;
# 192 "main.cu"
((common.epiRow)[7]) = 542;
# 193 "main.cu"
((common.epiRow)[8]) = 543;
# 194 "main.cu"
((common.epiRow)[9]) = 538;
# 195 "main.cu"
((common.epiRow)[10]) = 528;
# 196 "main.cu"
((common.epiRow)[11]) = 511;
# 197 "main.cu"
((common.epiRow)[12]) = 491;
# 198 "main.cu"
((common.epiRow)[13]) = 466;
# 199 "main.cu"
((common.epiRow)[14]) = 438;
# 200 "main.cu"
((common.epiRow)[15]) = 406;
# 201 "main.cu"
((common.epiRow)[16]) = 376;
# 202 "main.cu"
((common.epiRow)[17]) = 347;
# 203 "main.cu"
((common.epiRow)[18]) = 318;
# 204 "main.cu"
((common.epiRow)[19]) = 291;
# 205 "main.cu"
((common.epiRow)[20]) = 275;
# 206 "main.cu"
((common.epiRow)[21]) = 259;
# 207 "main.cu"
((common.epiRow)[22]) = 256;
# 208 "main.cu"
((common.epiRow)[23]) = 252;
# 209 "main.cu"
((common.epiRow)[24]) = 252;
# 210 "main.cu"
((common.epiRow)[25]) = 257;
# 211 "main.cu"
((common.epiRow)[26]) = 266;
# 212 "main.cu"
((common.epiRow)[27]) = 283;
# 213 "main.cu"
((common.epiRow)[28]) = 305;
# 214 "main.cu"
((common.epiRow)[29]) = 331;
# 215 "main.cu"
((common.epiRow)[30]) = 360;
# 216 "main.cu"
cudaMalloc((void **)(&(common.d_epiRow)), common.epi_mem);
# 217 "main.cu"
cudaMemcpy(common.d_epiRow, common.epiRow, common.epi_mem, cudaMemcpyHostToDevice);
# 219 "main.cu"
(common.epiCol) = ((int *)malloc(common.epi_mem));
# 220 "main.cu"
((common.epiCol)[0]) = 457;
# 221 "main.cu"
((common.epiCol)[1]) = 454;
# 222 "main.cu"
((common.epiCol)[2]) = 446;
# 223 "main.cu"
((common.epiCol)[3]) = 431;
# 224 "main.cu"
((common.epiCol)[4]) = 411;
# 225 "main.cu"
((common.epiCol)[5]) = 388;
# 226 "main.cu"
((common.epiCol)[6]) = 361;
# 227 "main.cu"
((common.epiCol)[7]) = 331;
# 228 "main.cu"
((common.epiCol)[8]) = 301;
# 229 "main.cu"
((common.epiCol)[9]) = 273;
# 230 "main.cu"
((common.epiCol)[10]) = 243;
# 231 "main.cu"
((common.epiCol)[11]) = 218;
# 232 "main.cu"
((common.epiCol)[12]) = 196;
# 233 "main.cu"
((common.epiCol)[13]) = 178;
# 234 "main.cu"
((common.epiCol)[14]) = 166;
# 235 "main.cu"
((common.epiCol)[15]) = 157;
# 236 "main.cu"
((common.epiCol)[16]) = 155;
# 237 "main.cu"
((common.epiCol)[17]) = 165;
# 238 "main.cu"
((common.epiCol)[18]) = 177;
# 239 "main.cu"
((common.epiCol)[19]) = 197;
# 240 "main.cu"
((common.epiCol)[20]) = 218;
# 241 "main.cu"
((common.epiCol)[21]) = 248;
# 242 "main.cu"
((common.epiCol)[22]) = 276;
# 243 "main.cu"
((common.epiCol)[23]) = 304;
# 244 "main.cu"
((common.epiCol)[24]) = 333;
# 245 "main.cu"
((common.epiCol)[25]) = 361;
# 246 "main.cu"
((common.epiCol)[26]) = 391;
# 247 "main.cu"
((common.epiCol)[27]) = 415;
# 248 "main.cu"
((common.epiCol)[28]) = 434;
# 249 "main.cu"
((common.epiCol)[29]) = 448;
# 250 "main.cu"
((common.epiCol)[30]) = 455;
# 251 "main.cu"
cudaMalloc((void **)(&(common.d_epiCol)), common.epi_mem);
# 252 "main.cu"
cudaMemcpy(common.d_epiCol, common.epiCol, common.epi_mem, cudaMemcpyHostToDevice);
# 254 "main.cu"
(common.tEpiRowLoc) = ((int *)malloc((common.epi_mem) * (common.no_frames)));
# 255 "main.cu"
cudaMalloc((void **)(&(common.d_tEpiRowLoc)), (common.epi_mem) * (common.no_frames));
# 257 "main.cu"
(common.tEpiColLoc) = ((int *)malloc((common.epi_mem) * (common.no_frames)));
# 258 "main.cu"
cudaMalloc((void **)(&(common.d_tEpiColLoc)), (common.epi_mem) * (common.no_frames));
# 264 "main.cu"
(common.allPoints) = 51;
# 271 "main.cu"
(common.in_rows) = (((common.tSize) + 1) + (common.tSize));
# 272 "main.cu"
(common.in_cols) = (common.in_rows);
# 273 "main.cu"
(common.in_elem) = ((common.in_rows) * (common.in_cols));
# 274 "main.cu"
(common.in_mem) = (sizeof(float) * (common.in_elem));
# 281 "main.cu"
cudaMalloc((void **)(&(common.d_endoT)), (common.in_mem) * (common.endoPoints));
# 282 "main.cu"
cudaMalloc((void **)(&(common.d_epiT)), (common.in_mem) * (common.epiPoints));
# 288 "main.cu"
for (i = 0; i < (common.endoPoints); i++) {
# 289 "main.cu"
(((unique)[i]).point_no) = i;
# 290 "main.cu"
(((unique)[i]).d_Row) = (common.d_endoRow);
# 291 "main.cu"
(((unique)[i]).d_Col) = (common.d_endoCol);
# 292 "main.cu"
(((unique)[i]).d_tRowLoc) = (common.d_tEndoRowLoc);
# 293 "main.cu"
(((unique)[i]).d_tColLoc) = (common.d_tEndoColLoc);
# 294 "main.cu"
(((unique)[i]).d_T) = (common.d_endoT);
# 295 "main.cu"
}
# 296 "main.cu"
for (i = (common.endoPoints); i < (common.allPoints); i++) {
# 297 "main.cu"
(((unique)[i]).point_no) = (i - (common.endoPoints));
# 298 "main.cu"
(((unique)[i]).d_Row) = (common.d_epiRow);
# 299 "main.cu"
(((unique)[i]).d_Col) = (common.d_epiCol);
# 300 "main.cu"
(((unique)[i]).d_tRowLoc) = (common.d_tEpiRowLoc);
# 301 "main.cu"
(((unique)[i]).d_tColLoc) = (common.d_tEpiColLoc);
# 302 "main.cu"
(((unique)[i]).d_T) = (common.d_epiT);
# 303 "main.cu"
}
# 310 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 311 "main.cu"
(((unique)[i]).in_pointer) = ((((unique)[i]).point_no) * (common.in_elem));
# 312 "main.cu"
}
# 319 "main.cu"
(common.in2_rows) = ((2 * (common.sSize)) + 1);
# 320 "main.cu"
(common.in2_cols) = ((2 * (common.sSize)) + 1);
# 321 "main.cu"
(common.in2_elem) = ((common.in2_rows) * (common.in2_cols));
# 322 "main.cu"
(common.in2_mem) = (sizeof(float) * (common.in2_elem));
# 325 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 326 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2)), common.in2_mem);
# 327 "main.cu"
}
# 334 "main.cu"
(common.conv_rows) = (((common.in_rows) + (common.in2_rows)) - 1);
# 335 "main.cu"
(common.conv_cols) = (((common.in_cols) + (common.in2_cols)) - 1);
# 336 "main.cu"
(common.conv_elem) = ((common.conv_rows) * (common.conv_cols));
# 337 "main.cu"
(common.conv_mem) = (sizeof(float) * (common.conv_elem));
# 338 "main.cu"
(common.ioffset) = 0;
# 339 "main.cu"
(common.joffset) = 0;
# 342 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 343 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_conv)), common.conv_mem);
# 344 "main.cu"
}
# 355 "main.cu"
(common.in2_pad_add_rows) = (common.in_rows);
# 356 "main.cu"
(common.in2_pad_add_cols) = (common.in_cols);
# 358 "main.cu"
(common.in2_pad_cumv_rows) = ((common.in2_rows) + (2 * (common.in2_pad_add_rows)));
# 359 "main.cu"
(common.in2_pad_cumv_cols) = ((common.in2_cols) + (2 * (common.in2_pad_add_cols)));
# 360 "main.cu"
(common.in2_pad_cumv_elem) = ((common.in2_pad_cumv_rows) * (common.in2_pad_cumv_cols));
# 361 "main.cu"
(common.in2_pad_cumv_mem) = (sizeof(float) * (common.in2_pad_cumv_elem));
# 364 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 365 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_pad_cumv)), common.in2_pad_cumv_mem);
# 366 "main.cu"
}
# 373 "main.cu"
(common.in2_pad_cumv_sel_rowlow) = (1 + (common.in_rows));
# 374 "main.cu"
(common.in2_pad_cumv_sel_rowhig) = ((common.in2_pad_cumv_rows) - 1);
# 375 "main.cu"
(common.in2_pad_cumv_sel_collow) = 1;
# 376 "main.cu"
(common.in2_pad_cumv_sel_colhig) = (common.in2_pad_cumv_cols);
# 377 "main.cu"
(common.in2_pad_cumv_sel_rows) = (((common.in2_pad_cumv_sel_rowhig) - (common.in2_pad_cumv_sel_rowlow)) + 1);
# 378 "main.cu"
(common.in2_pad_cumv_sel_cols) = (((common.in2_pad_cumv_sel_colhig) - (common.in2_pad_cumv_sel_collow)) + 1);
# 379 "main.cu"
(common.in2_pad_cumv_sel_elem) = ((common.in2_pad_cumv_sel_rows) * (common.in2_pad_cumv_sel_cols));
# 380 "main.cu"
(common.in2_pad_cumv_sel_mem) = (sizeof(float) * (common.in2_pad_cumv_sel_elem));
# 383 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 384 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_pad_cumv_sel)), common.in2_pad_cumv_sel_mem);
# 385 "main.cu"
}
# 392 "main.cu"
(common.in2_pad_cumv_sel2_rowlow) = 1;
# 393 "main.cu"
(common.in2_pad_cumv_sel2_rowhig) = (((common.in2_pad_cumv_rows) - (common.in_rows)) - 1);
# 394 "main.cu"
(common.in2_pad_cumv_sel2_collow) = 1;
# 395 "main.cu"
(common.in2_pad_cumv_sel2_colhig) = (common.in2_pad_cumv_cols);
# 396 "main.cu"
(common.in2_sub_cumh_rows) = (((common.in2_pad_cumv_sel2_rowhig) - (common.in2_pad_cumv_sel2_rowlow)) + 1);
# 397 "main.cu"
(common.in2_sub_cumh_cols) = (((common.in2_pad_cumv_sel2_colhig) - (common.in2_pad_cumv_sel2_collow)) + 1);
# 398 "main.cu"
(common.in2_sub_cumh_elem) = ((common.in2_sub_cumh_rows) * (common.in2_sub_cumh_cols));
# 399 "main.cu"
(common.in2_sub_cumh_mem) = (sizeof(float) * (common.in2_sub_cumh_elem));
# 402 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 403 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sub_cumh)), common.in2_sub_cumh_mem);
# 404 "main.cu"
}
# 411 "main.cu"
(common.in2_sub_cumh_sel_rowlow) = 1;
# 412 "main.cu"
(common.in2_sub_cumh_sel_rowhig) = (common.in2_sub_cumh_rows);
# 413 "main.cu"
(common.in2_sub_cumh_sel_collow) = (1 + (common.in_cols));
# 414 "main.cu"
(common.in2_sub_cumh_sel_colhig) = ((common.in2_sub_cumh_cols) - 1);
# 415 "main.cu"
(common.in2_sub_cumh_sel_rows) = (((common.in2_sub_cumh_sel_rowhig) - (common.in2_sub_cumh_sel_rowlow)) + 1);
# 416 "main.cu"
(common.in2_sub_cumh_sel_cols) = (((common.in2_sub_cumh_sel_colhig) - (common.in2_sub_cumh_sel_collow)) + 1);
# 417 "main.cu"
(common.in2_sub_cumh_sel_elem) = ((common.in2_sub_cumh_sel_rows) * (common.in2_sub_cumh_sel_cols));
# 418 "main.cu"
(common.in2_sub_cumh_sel_mem) = (sizeof(float) * (common.in2_sub_cumh_sel_elem));
# 421 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 422 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sub_cumh_sel)), common.in2_sub_cumh_sel_mem);
# 423 "main.cu"
}
# 430 "main.cu"
(common.in2_sub_cumh_sel2_rowlow) = 1;
# 431 "main.cu"
(common.in2_sub_cumh_sel2_rowhig) = (common.in2_sub_cumh_rows);
# 432 "main.cu"
(common.in2_sub_cumh_sel2_collow) = 1;
# 433 "main.cu"
(common.in2_sub_cumh_sel2_colhig) = (((common.in2_sub_cumh_cols) - (common.in_cols)) - 1);
# 434 "main.cu"
(common.in2_sub2_rows) = (((common.in2_sub_cumh_sel2_rowhig) - (common.in2_sub_cumh_sel2_rowlow)) + 1);
# 435 "main.cu"
(common.in2_sub2_cols) = (((common.in2_sub_cumh_sel2_colhig) - (common.in2_sub_cumh_sel2_collow)) + 1);
# 436 "main.cu"
(common.in2_sub2_elem) = ((common.in2_sub2_rows) * (common.in2_sub2_cols));
# 437 "main.cu"
(common.in2_sub2_mem) = (sizeof(float) * (common.in2_sub2_elem));
# 440 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 441 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sub2)), common.in2_sub2_mem);
# 442 "main.cu"
}
# 453 "main.cu"
(common.in2_sqr_rows) = (common.in2_rows);
# 454 "main.cu"
(common.in2_sqr_cols) = (common.in2_cols);
# 455 "main.cu"
(common.in2_sqr_elem) = (common.in2_elem);
# 456 "main.cu"
(common.in2_sqr_mem) = (common.in2_mem);
# 459 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 460 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sqr)), common.in2_sqr_mem);
# 461 "main.cu"
}
# 468 "main.cu"
(common.in2_sqr_sub2_rows) = (common.in2_sub2_rows);
# 469 "main.cu"
(common.in2_sqr_sub2_cols) = (common.in2_sub2_cols);
# 470 "main.cu"
(common.in2_sqr_sub2_elem) = (common.in2_sub2_elem);
# 471 "main.cu"
(common.in2_sqr_sub2_mem) = (common.in2_sub2_mem);
# 474 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 475 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in2_sqr_sub2)), common.in2_sqr_sub2_mem);
# 476 "main.cu"
}
# 483 "main.cu"
(common.in_sqr_rows) = (common.in_rows);
# 484 "main.cu"
(common.in_sqr_cols) = (common.in_cols);
# 485 "main.cu"
(common.in_sqr_elem) = (common.in_elem);
# 486 "main.cu"
(common.in_sqr_mem) = (common.in_mem);
# 489 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 490 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_in_sqr)), common.in_sqr_mem);
# 491 "main.cu"
}
# 498 "main.cu"
(common.tMask_rows) = (((common.in_rows) + (((common.sSize) + 1) + (common.sSize))) - 1);
# 499 "main.cu"
(common.tMask_cols) = (common.tMask_rows);
# 500 "main.cu"
(common.tMask_elem) = ((common.tMask_rows) * (common.tMask_cols));
# 501 "main.cu"
(common.tMask_mem) = (sizeof(float) * (common.tMask_elem));
# 504 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 505 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_tMask)), common.tMask_mem);
# 506 "main.cu"
}
# 513 "main.cu"
(common.mask_rows) = (common.maxMove);
# 514 "main.cu"
(common.mask_cols) = (common.mask_rows);
# 515 "main.cu"
(common.mask_elem) = ((common.mask_rows) * (common.mask_cols));
# 516 "main.cu"
(common.mask_mem) = (sizeof(float) * (common.mask_elem));
# 523 "main.cu"
(common.mask_conv_rows) = (common.tMask_rows);
# 524 "main.cu"
(common.mask_conv_cols) = (common.tMask_cols);
# 525 "main.cu"
(common.mask_conv_elem) = ((common.mask_conv_rows) * (common.mask_conv_cols));
# 526 "main.cu"
(common.mask_conv_mem) = (sizeof(float) * (common.mask_conv_elem));
# 527 "main.cu"
(common.mask_conv_ioffset) = (((common.mask_rows) - 1) / 2);
# 528 "main.cu"
if ((((common.mask_rows) - 1) % 2) > (0.5)) {
# 529 "main.cu"
(common.mask_conv_ioffset) = ((common.mask_conv_ioffset) + 1);
# 530 "main.cu"
}
# 531 "main.cu"
(common.mask_conv_joffset) = (((common.mask_cols) - 1) / 2);
# 532 "main.cu"
if ((((common.mask_cols) - 1) % 2) > (0.5)) {
# 533 "main.cu"
(common.mask_conv_joffset) = ((common.mask_conv_joffset) + 1);
# 534 "main.cu"
}
# 537 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 538 "main.cu"
cudaMalloc((void **)(&(((unique)[i]).d_mask_conv)), common.mask_conv_mem);
# 539 "main.cu"
}
# 550 "main.cu"
(threads.x) = (512);
# 551 "main.cu"
(threads.y) = (1);
# 552 "main.cu"
(blocks.x) = (common.allPoints);
# 553 "main.cu"
(blocks.y) = (1);
# 559 "main.cu"
cudaMemcpyToSymbol(d_common__cuda_shadow_variable__, &common, sizeof(params_common));
# 560 "main.cu"
cudaMemcpyToSymbol(d_unique__cuda_shadow_variable__, &unique, sizeof(params_unique) * (51));
# 566 "main.cu"
printf("frame progress: ");
# 567 "main.cu"
fflush(__null);
# 573 "main.cu"
for ((common_change.frame_no) = 0; (common_change.frame_no) < frames_processed; (common_change.frame_no)++) {
# 576 "main.cu"
frame = get_frame(frames, common_change.frame_no, 0, 0, 1);
# 583 "main.cu"
cudaMemcpy(common_change.d_frame, frame, common.frame_mem, cudaMemcpyHostToDevice);
# 584 "main.cu"
cudaMemcpyToSymbol(d_common_change__cuda_shadow_variable__, &common_change, sizeof(params_common_change));
# 587 "main.cu"
cudaConfigureCall(blocks, threads) ? ((void)0) : kernel__entry();
# 590 "main.cu"
free(frame);
# 593 "main.cu"
printf("%d ", common_change.frame_no);
# 594 "main.cu"
fflush(__null);
# 596 "main.cu"
}
# 602 "main.cu"
printf("\n");
# 603 "main.cu"
fflush(__null);
# 609 "main.cu"
cudaMemcpy(common.tEndoRowLoc, common.d_tEndoRowLoc, (common.endo_mem) * (common.no_frames), cudaMemcpyDeviceToHost);
# 610 "main.cu"
cudaMemcpy(common.tEndoColLoc, common.d_tEndoColLoc, (common.endo_mem) * (common.no_frames), cudaMemcpyDeviceToHost);
# 612 "main.cu"
cudaMemcpy(common.tEpiRowLoc, common.d_tEpiRowLoc, (common.epi_mem) * (common.no_frames), cudaMemcpyDeviceToHost);
# 613 "main.cu"
cudaMemcpy(common.tEpiColLoc, common.d_tEpiColLoc, (common.epi_mem) * (common.no_frames), cudaMemcpyDeviceToHost);
# 624 "main.cu"
cudaFree(common_change.d_frame);
# 627 "main.cu"
free(common.endoRow);
# 628 "main.cu"
free(common.endoCol);
# 629 "main.cu"
free(common.tEndoRowLoc);
# 630 "main.cu"
free(common.tEndoColLoc);
# 632 "main.cu"
cudaFree(common.d_endoRow);
# 633 "main.cu"
cudaFree(common.d_endoCol);
# 634 "main.cu"
cudaFree(common.d_tEndoRowLoc);
# 635 "main.cu"
cudaFree(common.d_tEndoColLoc);
# 637 "main.cu"
cudaFree(common.d_endoT);
# 640 "main.cu"
free(common.epiRow);
# 641 "main.cu"
free(common.epiCol);
# 642 "main.cu"
free(common.tEpiRowLoc);
# 643 "main.cu"
free(common.tEpiColLoc);
# 645 "main.cu"
cudaFree(common.d_epiRow);
# 646 "main.cu"
cudaFree(common.d_epiCol);
# 647 "main.cu"
cudaFree(common.d_tEpiRowLoc);
# 648 "main.cu"
cudaFree(common.d_tEpiColLoc);
# 650 "main.cu"
cudaFree(common.d_epiT);
# 656 "main.cu"
for (i = 0; i < (common.allPoints); i++) {
# 657 "main.cu"
cudaFree(((unique)[i]).d_in2);
# 659 "main.cu"
cudaFree(((unique)[i]).d_conv);
# 660 "main.cu"
cudaFree(((unique)[i]).d_in2_pad_cumv);
# 661 "main.cu"
cudaFree(((unique)[i]).d_in2_pad_cumv_sel);
# 662 "main.cu"
cudaFree(((unique)[i]).d_in2_sub_cumh);
# 663 "main.cu"
cudaFree(((unique)[i]).d_in2_sub_cumh_sel);
# 664 "main.cu"
cudaFree(((unique)[i]).d_in2_sub2);
# 665 "main.cu"
cudaFree(((unique)[i]).d_in2_sqr);
# 666 "main.cu"
cudaFree(((unique)[i]).d_in2_sqr_sub2);
# 667 "main.cu"
cudaFree(((unique)[i]).d_in_sqr);
# 669 "main.cu"
cudaFree(((unique)[i]).d_tMask);
# 670 "main.cu"
cudaFree(((unique)[i]).d_mask_conv);
# 671 "main.cu"
}
# 673 "main.cu"
printf("TEST PASSED\n"); return 0;
# 675 "main.cu"
}
# 1 "/tmp/tmpxft_00002c28_00000000-1_main.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00002c28_00000000-1_main.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_00002c28_00000000-3_main.fatbin.c" 1
# 1 "/home/normal/cuda/bin/../include/__cudaFatFormat.h" 1
# 83 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
extern "C" {
# 97 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
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
# 152 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 166 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
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
# 203 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode
    } __cudaFatCompilationPolicy;
# 226 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 237 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );


}
# 2 "/tmp/tmpxft_00002c28_00000000-3_main.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_10$[] = {
0x33010102464c457full,0x0000000000000000ull,0x0000000100be0002ull,0x0000000000000000ull,
0x00000000000055c4ull,0x0000000000000040ull,0x003800400000000aull,0x0001000800400004ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000300000001ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000240ull,
0x0000000000000084ull,0x0000000000000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000030000000bull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000002c4ull,
0x000000000000002eull,0x0000000000000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x0000000200000013ull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000002f2ull,
0x0000000000000150ull,0x0000000a00000002ull,0x0000000000000001ull,0x0000000000000018ull,
0x0000000100000036ull,0x0000000000100006ull,0x0000000000000000ull,0x0000000000000442ull,
0x0000000000002f70ull,0x1900000600000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000005dull,0x0000000000000002ull,0x0000000000000000ull,0x00000000000033b2ull,
0x0000000000000018ull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000800000047ull,0x0000000000000003ull,0x0000000000000000ull,0x00000000000033caull,
0x0000000000002e70ull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000076ull,0x0000000000000002ull,0x0000000000000000ull,0x00000000000033caull,
0x00000000000021f8ull,0x0000000000000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x7472747368732e00ull,0x747274732e006261ull,0x746d79732e006261ull,0x672e766e2e006261ull,
0x6e692e6c61626f6cull,0x672e766e2e007469ull,0x742e006c61626f6cull,0x6b365a5f2e747865ull,
0x2e00766c656e7265ull,0x65726168732e766eull,0x72656b365a5f2e64ull,0x766e2e00766c656eull,
0x6e6174736e6f632eull,0x656b365a5f2e3174ull,0x6e2e00766c656e72ull,0x6174736e6f632e76ull,
0x365a5f000030746eull,0x00766c656e72656bull,0x657571696e755f64ull,0x6f6d6d6f635f6400ull,
0x65676e6168635f6eull,0x6f6d6d6f635f6400ull,0x000000000000006eull,0x0000000000000000ull,
0x0000000000000000ull,0x0003000000000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x0003000000000000ull,0x0000000000000002ull,0x0000000000000000ull,0x0003000000000000ull,
0x0000000000000003ull,0x0000000000000000ull,0x0003000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0003000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0003000000000000ull,0x0000000000000004ull,0x000000002f700000ull,0x0003000000000000ull,
0x0000000000000006ull,0x0000000000000000ull,0x0003000000000000ull,0x0000000000000005ull,
0x0000000000000000ull,0x0003000000000000ull,0x0000000000000007ull,0x0000000000000000ull,
0x1012000000010000ull,0x0000000000000004ull,0x0000000000000000ull,0x00110000000c0000ull,
0x0000000002180007ull,0x000000001fe00000ull,0x0011000000150000ull,0x0000000000000007ull,
0x0000000000100000ull,0x0011000000250000ull,0x0000000000100007ull,0x0000000002080000ull,
0x47c83082f9fd0000ull,0xc780100000056c01ull,0x0280100520030403ull,0x0780a0004c010000ull,
0x0780300700090420ull,0x078030050001c410ull,0x078020000401c410ull,0x0780000000050400ull,
0xc7801401220dc000ull,0xc78014011c092400ull,0x07803002060d2400ull,0x002320188001c410ull,
0xc780200004090000ull,0x07c0a00004110400ull,0x0780000000050400ull,0x0000a0024003c000ull,
0xc7801000040d0000ull,0x0280100240030403ull,0xc780100010010000ull,0xc780140014152400ull,
0x0780400b00192400ull,0x8780600a02190000ull,0x078030100c190001ull,0x8780600a0015c410ull,
0xc780140014010001ull,0x878021000a152400ull,0x07803002001d0400ull,0x078030020a15c410ull,
0x078025000e01c410ull,0x0780d00e00010400ull,0x078025000a1980c0ull,0x0780d00e0c010401ull,
0x878025000e01a0c0ull,0x0780d00e00010400ull,0x878025000a1580c0ull,0x0780d00e0a010401ull,
0x87ca30b909fda0c0ull,0x0000a00510036c01ull,0x0280100510030000ull,0xc780140014010000ull,
0x0780300200012400ull,0x801424808018c410ull,0x0003200188212482ull,0xc78010006e1d0000ull,
0xc780100010012400ull,0x0780205a80030403ull,0xc780100000250000ull,0xc78010006e1d0403ull,
0xc780100010012400ull,0x0780205cd0030403ull,0x47c8307c13fd0000ull,0xffff203f92296c01ull,
0xc5001000081d0fffull,0x0500210000012440ull,0xc50021000e290441ull,0x0780d00e0a1d040dull,
0x0780d00e0c2d80c0ull,0xc7802000002180c0ull,0xc7801000121d0401ull,0xffff202690212400ull,
0x078040111c250fffull,0x478060101e310000ull,0xc78010006e250002ull,0x0780301018352400ull,
0x078040130031c410ull,0x478060101c350000ull,0x07806012021d0003ull,0xc780200014210003ull,
0x078030100e1d0402ull,0x078020001a21c410ull,0xc780601200010402ull,0x07803002101d0001ull,
0x8e20200a8000c410ull,0x07803002001d2080ull,0xfffb20189001c410ull,0x0780d00e00010fffull,
0xc7802000041d80c0ull,0x0023200088110401ull,0x47c830b909fd0000ull,0x0780d00e0e016c00ull,
0x02801002a003a0c0ull,0x0002f00000010000ull,0x47d03082f801e000ull,0x47c8a00001fd6c01ull,
0x0780000000290c01ull,0x11001054b0032000ull,0x0780a0004c010000ull,0x0780300700090420ull,
0x078030050001c410ull,0x078020000401c410ull,0x0780000000090400ull,0xc78018012009c000ull,
0x0023201880012400ull,0xc78018010c0d0000ull,0x0780300204112400ull,0xc78018011009c410ull,
0x0780000000052400ull,0xc78020000825c000ull,0x0780d00e120d0400ull,0x07802000042180c0ull,
0x0780d00e10010401ull,0x0000a008c00380c0ull,0xc780180120190000ull,0x0780a00004152400ull,
0x87c830bd0bfd0400ull,0x860c10008a086c01ull,0x07802140001120c4ull,0x02801008c0030401ull,
0x0780300204010000ull,0x07802500002dc410ull,0x000320018a310403ull,0xc7801000761d0000ull,
0xc780100018012400ull,0x0780205a80030403ull,0xc780100000350000ull,0xc7801000761d0403ull,
0xc780100018012400ull,0x0780205cd0030403ull,0x47c8307c1bfd0000ull,0xffff203f9a316c01ull,
0xc5001000081d0fffull,0x0500210000012440ull,0xc50021000e310441ull,0x07802000001d040eull,
0xc780100012010401ull,0xffff203f8e1d2400ull,0x0780400f00350fffull,0x4780600e02350000ull,
0x078030101a350003ull,0x4780600e001dc410ull,0x8e00200398000003ull,0x0780300200012000ull,
0x078021000001c410ull,0xffff203c80010400ull,0x0780d00e00010fffull,0x002320008a1580c0ull,
0x0780d00e16010000ull,0x47c830bd0bfda0c0ull,0x00832000962d6c00ull,0x02801006e0030000ull,
0x0002f00000010000ull,0x0000861ffe03e000ull,0xc780140016010000ull,0x0780300200012400ull,
0x078025000011c410ull,0x87c830b905fd0402ull,0x0000a00b50036c01ull,0x880c100084140000ull,
0x0280100b50031000ull,0x0003200484010000ull,0x0780000200090000ull,0x000320018a2dc000ull,
0xc78010006e1d0000ull,0xc780100016012400ull,0x0780205a80030403ull,0xc780100000310000ull,
0xc78010006e1d0403ull,0xc780100016012400ull,0x0780205cd0030403ull,0x47c8307c19fd0000ull,
0xffff203f982d6c01ull,0xc5001000081d0fffull,0x0500210000012440ull,0xc50021000e2d0441ull,
0xc7803100001d040dull,0xc78010006e01040dull,0xffff203f8e1d2400ull,0x0780400f00310fffull,
0x0780600e02310000ull,0x0780301018310003ull,0x0780600e001dc410ull,0xc780310016010003ull,
0x078020000e01040dull,0x0780300200010400ull,0x078020000801c410ull,0xffff203c80010400ull,
0x0780d00e00010fffull,0x002320008a1580c0ull,0x07800a0400010000ull,0x47c830b90bfde420ull,
0x0280100970036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x47c030c104010000ull,
0x47e8a00001fd6c00ull,0x27800000002d0c01ull,0x0000a01160032000ull,0xc780100004150000ull,
0x0100101160030403ull,0x0780300204010000ull,0x878025000031c410ull,0x000320018a390403ull,
0xc78010007e1d0000ull,0xc78010001c012400ull,0x0780205a80030403ull,0xc780100000350000ull,
0xc78010007e1d0403ull,0xc78010001c012400ull,0x0780205cd0030403ull,0xc7801000001d0000ull,
0x47c8307c1bfd0403ull,0x000320018e016c01ull,0xc50010007e350000ull,0xc50010000e012400ull,
0x0780210000390403ull,0x000320019c1d0411ull,0x07c830bc0ffd0000ull,0x00031001801d6c01ull,
0x078021401c3d0000ull,0x028021001e1d040full,0x07c830b81dfd0440ull,0xc280100070396c01ull,
0x0000a01110032400ull,0x47c830071dfd0000ull,0xc7801000f8416c00ull,0x0280101110030403ull,
0xc78021001a3d0000ull,0x000320019e350410ull,0x07d830bb1bfd0000ull,0x0003100180356c01ull,
0xc78021401e490000ull,0xc78010001e45040eull,0x07c830b71ffd0403ull,0x1280210024356c01ull,
0xc28010006e450440ull,0x000320019c492400ull,0x87c8300d23fd0000ull,0xc78010001a4d6c01ull,
0x0000a010d0030403ull,0x01001010d0030000ull,0xc78010006e350000ull,0x0780401b1c392400ull,
0x8780601a1e390000ull,0x078030101c390003ull,0x8780601a1c35c410ull,0xc78021401a350003ull,
0x478020002635040dull,0x000320049a350403ull,0x078000021a090000ull,0xc78010007635c000ull,
0xc780100088392400ull,0x0780401c36512400ull,0x0780601d34510000ull,0x0780301028510005ull,
0x0780601c3439c410ull,0x0780401b00510005ull,0x0780601a02510000ull,0x0780301028510005ull,
0x0780601a0051c410ull,0x1c50200ea8380005ull,0x0780601a1e51401bull,0x0780301028510005ull,
0x0780601a1c35c410ull,0x878030001a390005ull,0x00032001a2510403ull,0x9e5020539e340000ull,
0x9c50200e9a342054ull,0x078030021a392014ull,0x078025001c39c410ull,0x0780d00e1c550403ull,
0x07800800005980c0ull,0xffff203cac594000ull,0x078000002c0d0fffull,0x0780ec15c041c000ull,
0xffff203f9a350024ull,0x0780d80008090fffull,0xffff203c9c392000ull,0x47d830141bfd0fffull,
0x1280101030036c01ull,0x0002f00000010000ull,0x000320018e1de000ull,0x47d8300725fd0000ull,
0x1280100e40036c01ull,0x0782d00e18410000ull,0x002320008a15a0c0ull,0x47c830c10bfd0000ull,
0x0083200098316c00ull,0x0280100bf0030000ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x47c030c904010000ull,0x0000a01520036c00ull,0xc780100004150000ull,0x47f8a00001fd0403ull,
0x3780000000310c01ull,0x0100101520032000ull,0xffff103f80010000ull,0x07803002041d0fffull,
0x478021000039c410ull,0x878025000e350411ull,0x00004014e0030404ull,0x000320018a3d0000ull,
0xc78010008e1d0000ull,0xc78010001e012400ull,0x0780205a80030403ull,0xc780100000410000ull,
0xc78010008e1d0403ull,0xc78010001e012400ull,0x0780205cd0030403ull,0xffff203fa03d0000ull,
0x47c8307c21fd0fffull,0xc5001000081d6c01ull,0x0500210000012440ull,0xc50021000e3d0441ull,
0x87c8300f1dfd0411ull,0x02801014b0036c01ull,0xc7801000761d0000ull,0x478021000e1d2400ull,
0x87c830071ffd0411ull,0x02801014b0036c01ull,0xffff103f801d0000ull,0x878021000e1d0fffull,
0xc7c8300701fd0411ull,0x02801014b0036c00ull,0xc7801000781d0000ull,0x878021000e1d2400ull,
0x87c8300701fd0411ull,0x02801014b0036c01ull,0x87802140001d0000ull,0xc780100076010411ull,
0x0780400f00412400ull,0x0780600e02410000ull,0x0780301020410004ull,0x0780600e001dc410ull,
0x478021401e010004ull,0x078020000e010411ull,0x0780300200010400ull,0x078025000001c410ull,
0x0780d00e00010403ull,0x0780d00e1a0180c0ull,0x078050000003a0c0ull,0x0003100080010000ull,
0x0780d00e1a010000ull,0x078050000003a0c0ull,0x002320008a150000ull,0x008320009a350000ull,
0x47c830c90bfd0000ull,0x0280101220036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a01730030000ull,0xc780100004150000ull,0x47c030c804010403ull,0x47f8a00001fd6c00ull,
0x3780000000350c01ull,0x0100101730032000ull,0xc78010008e010000ull,0x07804001081d2400ull,
0xc78060000a1d0000ull,0x078030100e1d0001ull,0xc7806000081dc410ull,0x0780300900390001ull,
0xc78021000e3dc410ull,0x0000a016f0030411ull,0xc78010000e010000ull,0xc7c830071ffd0403ull,
0x02801016f0036c00ull,0x078030020e410000ull,0xc7801000f845c410ull,0x8780250020410403ull,
0x0780d00e20490404ull,0x4780b000244580c0ull,0x0780d00e20450004ull,0x000320018001a0c0ull,
0x00032004a0410000ull,0x47c830001ffd0000ull,0x0280101680036c01ull,0x878220000e1d0000ull,
0x002320008a150403ull,0x47c830c80bfd0000ull,0x0280101600036c00ull,0x0002f00000010000ull,
0x0000861ffe03e000ull,0x0000a019d0030000ull,0xc7801000043d0000ull,0x47c030cd04010403ull,
0x47f8a00001fd6c00ull,0x3780000000390c01ull,0x01001019d0032000ull,0x0780300204010000ull,
0xc78014002445c410ull,0x0780250000412400ull,0x000320019e150405ull,0xc7801000961d0000ull,
0xc78010000a012400ull,0x0780205a80030403ull,0xc7801000005d0000ull,0xc7801000961d0403ull,
0xc78010000a012400ull,0x0780205cd0030403ull,0xffff203fae1d0000ull,0x47c8307c2ffd0fffull,
0xc500100008156c01ull,0x0500210000012440ull,0xc50021000a1d0441ull,0x4780210000010412ull,
0xc78010008e150414ull,0xffff203f80012400ull,0x0780400114490fffull,0x8780600016490000ull,
0x0780301024490004ull,0x878060001415c410ull,0xc78021000e010004ull,0x078020000a010413ull,
0x0780300200010400ull,0x078020002201c410ull,0xffff203c80010400ull,0x0780d00e00010fffull,
0x0780d00e200180c0ull,0x002320009e3da0c0ull,0x00832000a0410000ull,0x47c830cd1ffd0000ull,
0x02801017e0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a01c60030000ull,
0xc780100004150000ull,0x47c030d904010403ull,0x47d8a00001fd6c00ull,0x0100101c60030c01ull,
0x0780300204010000ull,0xc78014002441c410ull,0x87802500003d2400ull,0x000320018a450405ull,
0xc7801000ae1d0000ull,0xc780100022012400ull,0x0780205a80030403ull,0xc7801000005d0000ull,
0xc7801000ae1d0403ull,0xc780100022012400ull,0x0780205cd0030403ull,0xffff203fae450000ull,
0x47c8307c2ffd0fffull,0xc5001000081d6c01ull,0x0500210000012440ull,0xc50021000e450441ull,
0x47802100001d0415ull,0xc78010008e010415ull,0xffff203f8e1d2400ull,0x0780400f00490fffull,
0x8780600e02490000ull,0x0780301024490004ull,0x8780600e001dc410ull,0xc780210022010004ull,
0x078020000e010414ull,0x0780300200010400ull,0x078020002001c410ull,0xffff203c80010400ull,
0x0780d00e00010fffull,0x0780d00e1e0180c0ull,0x002320008a15a0c0ull,0x008320009e3d0000ull,
0x47c830d90bfd0000ull,0x0280101a70036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a01d60030000ull,0xc780100004010000ull,0x1100101d60030403ull,0x0780300204150000ull,
0x8a1424968a1cc410ull,0x0780d00e0a412494ull,0x0780d00e0e3d80c0ull,0xc780b000203d80c0ull,
0x0780d00e0e3d0803ull,0x002320008001a0c0ull,0x008320008a150000ull,0x008320008e1d0000ull,
0x47c830d901fd0000ull,0x0280101cd0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a01f30030000ull,0xc780100004010000ull,0x47c030d704150403ull,0x47f8a0000bfd6c00ull,
0x37800000003d0c01ull,0x0100101f30032000ull,0x47802100001d0000ull,0x0000a01ef0030416ull,
0xc780100000150000ull,0xc7c830000ffd0403ull,0x0280101ef0036c00ull,0xc7801000ae450000ull,
0x07803002004d2400ull,0xc7801000f841c410ull,0x0780300222490403ull,0x878025002645c410ull,
0x0780d00e224d0405ull,0x0780b000264180c0ull,0x0780d00e22410004ull,0xc78021000a15a0c0ull,
0x8780200022450415ull,0x07c830050ffd0404ull,0x0280101e80036c01ull,0x0002f00000010000ull,
0x002320008001e000ull,0x47c830d701fd0000ull,0x0280101de0036c00ull,0x0002f00000010000ull,
0x0000861ffe03e000ull,0x0000a021c0030000ull,0xc780100004150000ull,0x47c030dd04010403ull,
0x47e8a00001fd6c00ull,0x01001021c0030c01ull,0x0780300204010000ull,0xc78014002c45c410ull,
0x0780250000412400ull,0x000320018a5d0406ull,0xc7801000b61d0000ull,0xc78010002e012400ull,
0x0780205a80030403ull,0xc780100000610000ull,0xc7801000b61d0403ull,0xc78010002e012400ull,
0x0780205cd0030403ull,0xffff203fb0490000ull,0x47c8307c31fd0fffull,0xc5001000081d6c01ull,
0x0500210000012440ull,0xc50021000e490441ull,0x4780210000010416ull,0xc7801000ae1d0418ull,
0xffff203f80012400ull,0x078040011c4d0fffull,0xc78060001e4d0000ull,0x07803010264d0004ull,
0xc78060001c1dc410ull,0xc780210024010004ull,0x078020000e010417ull,0x0780300200010400ull,
0x078020002201c410ull,0xffff203c80010400ull,0x0780d00e00010fffull,0x0780d00e200180c0ull,
0x002320008a15a0c0ull,0x00832000a0410000ull,0x47c830dd0bfd0000ull,0x0280101fd0036c00ull,
0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a02450030000ull,0xc780100004410000ull,
0x47f030e904010403ull,0x47c8a00001fd6c00ull,0x3100102450030c01ull,0x0780300204010000ull,
0xc78014002c5dc410ull,0x8780250000452400ull,0x00032001a0150406ull,0xc7801000ce1d0000ull,
0xc78010000a012400ull,0x0780205a80030403ull,0xc780100000610000ull,0xc7801000ce1d0403ull,
0xc78010000a012400ull,0x0780205cd0030403ull,0xffff203fb01d0000ull,0x47f8307c31fd0fffull,
0xf500100008156c01ull,0x3500210000012440ull,0xf50021000a1d0441ull,0x4780210000010419ull,
0xc7801000ae150419ull,0xffff203f80012400ull,0x0780400114490fffull,0x8780600016490000ull,
0x0780301024490004ull,0x878060001415c410ull,0xc78021000e010004ull,0x078020000a010418ull,
0x0780300200010400ull,0x078020002e01c410ull,0xffff203c80010400ull,0x0780d00e00010fffull,
0x0780d00e220180c0ull,0x00232000a041a0c0ull,0x00832000a2450000ull,0x47f830e921fd0000ull,
0x3280102260036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a02550030000ull,
0xc780100004010000ull,0x0100102550030403ull,0x0780300204150000ull,0x8a14249a8a1cc410ull,
0x0780d00e0a452498ull,0x0780d00e0e4180c0ull,0x0780b000224180c0ull,0x0780d00e0e410804ull,
0x002320008001a0c0ull,0x008320008a150000ull,0x008320008e1d0000ull,0x47f830e901fd0000ull,
0x32801024c0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a02650030000ull,
0xc780100004010000ull,0x87f830ed05fd0403ull,0x3280102650036c01ull,0x0780300204150000ull,
0x8a14249c8a1cc410ull,0x0780d00e0a41248cull,0x0780c010204180c0ull,0x0780d00e0e410000ull,
0x002320008001a0c0ull,0x008320008a150000ull,0x008320008e1d0000ull,0x47f830ed01fd0000ull,
0x32801025d0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a029f0030000ull,
0xc780100004150000ull,0x07f0000018010403ull,0x31001029f003a000ull,0xffff103f80010000ull,
0x07803002041d0fffull,0x478021000041c410ull,0x878025000e310411ull,0x00004029b0030404ull,
0x000320018a450000ull,0xc78010008e1d0000ull,0xc780100022012400ull,0x0780205a80030403ull,
0xc7801000005d0000ull,0xc78010008e1d0403ull,0xc780100022012400ull,0x0780205cd0030403ull,
0xffff203fae450000ull,0x47f8307c2ffd0fffull,0xf5001000081d6c01ull,0x3500210000012440ull,
0xf50021000e450441ull,0x87f8301121fd0411ull,0x3280102980036c01ull,0xc7801000d61d0000ull,
0x478021000e1d2400ull,0x87f8300723fd0411ull,0x3280102980036c01ull,0xffff103f801d0000ull,
0x878021000e1d0fffull,0xc7f8300701fd0411ull,0x3280102980036c00ull,0xc7801000d81d0000ull,
0x878021000e1d2400ull,0x87f8300701fd0411ull,0x3280102980036c01ull,0x87802140001d0000ull,
0xc7801000d6010411ull,0x0780400f00492400ull,0x8780600e02490000ull,0x0780301024490004ull,
0x8780600e001dc410ull,0x4780214022010004ull,0x078020000e010411ull,0x0780300200010400ull,
0x078025000001c410ull,0x0780d00e00010407ull,0x0780d00e180180c0ull,0x078050000003a0c0ull,
0x0003100080010000ull,0x0780d00e18010000ull,0x078050000003a0c0ull,0x002320008a150000ull,
0x0083200098310000ull,0x47f830c90bfd0000ull,0x32801026f0036c00ull,0x0002f00000010000ull,
0x0000861ffe03e000ull,0x0000a02be0030000ull,0xc780100004150000ull,0x07f000001a010403ull,
0x3100102be003a000ull,0xc78010008e010000ull,0x07804001081d2400ull,0xc78060000a1d0000ull,
0x078030100e1d0001ull,0xc7806000081dc410ull,0x0780300900310001ull,0xc78021000e35c410ull,
0x0000a02ba0030411ull,0xc78010000e010000ull,0xc7f830071bfd0403ull,0x3280102ba0036c00ull,
0x078030020e410000ull,0xc7801000f845c410ull,0x8780250020410403ull,0x0780d00e20490404ull,
0x4780b000244580c0ull,0x0780d00e20450004ull,0x000320018001a0c0ull,0x00032004a0410000ull,
0x47f830001bfd0000ull,0x3280102b30036c01ull,0x078220000e1d0000ull,0x002320008a150403ull,
0x47f830c80bfd0000ull,0x3280102ab0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a02e60030000ull,0xc780100004150000ull,0x07f000001c010403ull,0x3100102e6003a000ull,
0x0780300204010000ull,0xc78014002435c410ull,0x0780250000312400ull,0x000320018a390405ull,
0xc7801000961d0000ull,0xc78010001c012400ull,0x0780205a80030403ull,0xc780100000410000ull,
0xc7801000961d0403ull,0xc78010001c012400ull,0x0780205cd0030403ull,0xffff203fa0390000ull,
0x47f8307c21fd0fffull,0xf5001000081d6c01ull,0x3500210000012440ull,0xf50021000e390441ull,
0x47802100001d0412ull,0xc78010008e010414ull,0xffff203f8e1d2400ull,0x0780400f00410fffull,
0x0780600e02410000ull,0x0780301020410004ull,0x0780600e001dc410ull,0xc78021001c010004ull,
0x078020000e010413ull,0x0780300200010400ull,0x078020001a01c410ull,0xffff203c80010400ull,
0x0780d00e00010fffull,0x0780d00e180180c0ull,0x002320008a15a0c0ull,0x0083200098310000ull,
0x47f830cd0bfd0000ull,0x3280102c70036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a030d0030000ull,0xc780100004150000ull,0x11001030d0030403ull,0x0780300204010000ull,
0xc78014002435c410ull,0x8780250000312400ull,0x000320018a390405ull,0xc7801000ae1d0000ull,
0xc78010001c012400ull,0x0780205a80030403ull,0xc780100000410000ull,0xc7801000ae1d0403ull,
0xc78010001c012400ull,0x0780205cd0030403ull,0xffff203fa0390000ull,0x47f8307c21fd0fffull,
0xf5001000081d6c01ull,0x3500210000012440ull,0xf50021000e390441ull,0x47802100001d0415ull,
0xc78010008e010415ull,0xffff203f8e1d2400ull,0x0780400f00410fffull,0x0780600e02410000ull,
0x0780301020410004ull,0x0780600e001dc410ull,0xc78021001c010004ull,0x078020000e010414ull,
0x0780300200010400ull,0x078020001a01c410ull,0xffff203c80010400ull,0x0780d00e00010fffull,
0x0780d00e180180c0ull,0x002320008a15a0c0ull,0x0083200098310000ull,0x47f830d90bfd0000ull,
0x3280102ee0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a031d0030000ull,
0xc780100004010000ull,0x11001031d0030403ull,0x0780300204150000ull,0x8a1424968a1cc410ull,
0x0780d00e0a352494ull,0x0780d00e0e3180c0ull,0x0780b0001a3180c0ull,0x0780d00e0e310803ull,
0x002320008001a0c0ull,0x008320008a150000ull,0x008320008e1d0000ull,0x47d830d901fd0000ull,
0x1280103140036c00ull,0x0002f00000010000ull,0x0000a0337003e000ull,0xc780100004010000ull,
0x07f000001e010403ull,0x310010337003a000ull,0x47802100001d0000ull,0x0000a03330030416ull,
0xc780100000150000ull,0xc7d830000ffd0403ull,0x1280103330036c00ull,0xc7801000ae310000ull,
0x07803002003d2400ull,0xc7801000f839c410ull,0x0780300218350403ull,0x878025001e31c410ull,
0x0780d00e183d0405ull,0x8780b0001e3980c0ull,0x0780d00e18390003ull,0xc78021000a15a0c0ull,
0x4780200018310415ull,0x07d830050ffd0403ull,0x12801032c0036c01ull,0x0002f00000010000ull,
0x002320008001e000ull,0x47d830d701fd0000ull,0x1280103220036c00ull,0x0002f00000010000ull,
0x0000861ffe03e000ull,0x0000a035e0030000ull,0xc780100004150000ull,0x21001035e0030403ull,
0x0780300204010000ull,0xc78014002c35c410ull,0x0780250000312400ull,0x000320018a390406ull,
0xc7801000b61d0000ull,0xc78010001c012400ull,0x0780205a80030403ull,0xc7801000003d0000ull,
0xc7801000b61d0403ull,0xc78010001c012400ull,0x0780205cd0030403ull,0xffff203f9e390000ull,
0x47d8307c1ffd0fffull,0xd5001000081d6c01ull,0x1500210000012440ull,0xd50021000e390441ull,
0x47802100001d0416ull,0xc7801000ae010418ull,0xffff203f8e1d2400ull,0x0780400f003d0fffull,
0xc780600e023d0000ull,0x078030101e3d0003ull,0xc780600e001dc410ull,0xc78021001c010003ull,
0x078020000e010417ull,0x0780300200010400ull,0x078020001a01c410ull,0xffff203c80010400ull,
0x0780d00e00010fffull,0x0780d00e180180c0ull,0x002320008a15a0c0ull,0x0083200098310000ull,
0x47d830dd0bfd0000ull,0x12801033f0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a03850030000ull,0xc780100004150000ull,0x0100103850030403ull,0x0780300204010000ull,
0xc78014002c35c410ull,0x8780250000312400ull,0x000320018a390407ull,0xc7801000ce1d0000ull,
0xc78010001c012400ull,0x0780205a80030403ull,0xc7801000003d0000ull,0xc7801000ce1d0403ull,
0xc78010001c012400ull,0x0780205cd0030403ull,0xffff203f9e390000ull,0x47d8307c1ffd0fffull,
0xd5001000081d6c01ull,0x1500210000012440ull,0xd50021000e390441ull,0x47802100001d0419ull,
0xc7801000ae010419ull,0xffff203f8e1d2400ull,0x0780400f003d0fffull,0xc780600e023d0000ull,
0x078030101e3d0003ull,0xc780600e001dc410ull,0xc78021001c010003ull,0x078020000e010418ull,
0x0780300200010400ull,0x078020001a01c410ull,0xffff203c80010400ull,0x0780d00e00010fffull,
0x0780d00e180180c0ull,0x002320008a15a0c0ull,0x0083200098310000ull,0x47d830e90bfd0000ull,
0x1280103660036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a03950030000ull,
0xc780100004010000ull,0x0100103950030403ull,0x0780300204150000ull,0x8a14249e8a1cc410ull,
0x0780d00e0a352498ull,0x0780d00e0e3180c0ull,0x0780b0001a3180c0ull,0x0780d00e0e310803ull,
0x002320008001a0c0ull,0x008320008a150000ull,0x008320008e1d0000ull,0x47d830e901fd0000ull,
0x12801038c0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a03b10030000ull,
0xc780100004010000ull,0x0100103b10030403ull,0xc780100072150000ull,0x07803002041d2400ull,
0x4780a0000a15c410ull,0x8e38249e8e344401ull,0x0780d00e1c3d249aull,0x0780d00e1a3180c0ull,
0x1e3c10008a1c80c0ull,0x07d8b0810bfdc00full,0x1680c0851e3d6051ull,0x1680c0850e1d0040ull,
0x078090000e1d0040ull,0x0780e0071e310000ull,0xc7801000181d0403ull,0x47d8b07c19fd0403ull,
0xd2801000f81d6000ull,0x078090000e1d0403ull,0x078090000e1d4000ull,0x0780d00e1a1d0000ull,
0x002320008001a0c0ull,0x008320009c390000ull,0x008320009a350000ull,0x47d830e901fd0000ull,
0x12801039e0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a03c20030000ull,
0xc780100004010000ull,0x87d830f505fd0403ull,0x1280103c20036c01ull,0x0780300204150000ull,
0x078020000a1dc410ull,0x078025000a150401ull,0x0780d00e0e310408ull,0x0780c00c183180c0ull,
0x0780d00e0a310000ull,0x002320008001a0c0ull,0x008320008e1d0000ull,0x008320008a150000ull,
0x47d830f501fd0000ull,0x1280103ba0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a03e10030000ull,0xc780100004010000ull,0x87d830b805fd0403ull,0x1280103e10036c01ull,
0x00a3202d84150000ull,0x078000020a090000ull,0x47d830b7f9fdc000ull,0xc7801000f81d6c00ull,
0x1100103dd0030403ull,0xc78010006e150000ull,0x0780400b00312400ull,0x0780600a02310000ull,
0x0780301018310003ull,0x0780600a0031c410ull,0x0780300218150003ull,0x0000a03dc003c410ull,
0xc780210018350000ull,0x478020000815040dull,0x0780d00e0a390401ull,0x00032001983180c0ull,
0xc780b0001c1d0000ull,0x000320048a150001ull,0x47e8300d19fd0000ull,0x2280103d60036c01ull,
0x0002f00000010000ull,0xc7800a040001e000ull,0x002320008001e421ull,0x47e830b801fd0000ull,
0x2280103cb0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a03fe0030000ull,
0xc780100004010000ull,0x87d830f305fd0403ull,0x1280103fe0036c01ull,0x00a7202084110000ull,
0x0780000208090000ull,0xc78010000411c000ull,0x47d830f4f9fd0403ull,0x1100103f80036c00ull,
0xc7801000e6150000ull,0x0780300208392400ull,0xc7801000f831c410ull,0xc7801000f8350403ull,
0x078030020a1d0403ull,0x078025001c15c410ull,0x0780d00e0a390408ull,0x000320019a3580c0ull,
0x8e14b00c1c300000ull,0x47e830f41bfd2005ull,0x2280103f20036c01ull,0x0780103f90030000ull,
0xc7801000f8310000ull,0x07800a0400010403ull,0x002320008001e423ull,0x0023200088110000ull,
0x47e830f301fd0000ull,0x2280103eb0036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a04210030000ull,0x87e0307c04010000ull,0x47d8a00001fd6c00ull,0x2100104120030c01ull,
0xc7801000f8010000ull,0x87e830b8f9fd0403ull,0x2280104100036c01ull,0x028b103480110000ull,
0x0780000008090000ull,0xc7801000f811c000ull,0x0780ba00c2010403ull,0x0003200188110020ull,
0x47e830b809fd0000ull,0x22801040a0036c01ull,0x0780001732010000ull,0x078010421003e420ull,
0x0780001732010000ull,0x078010421003e43full,0x47e8308005fd0000ull,0x2280104210036c41ull,
0xc7801000f8010000ull,0x87e830f4f9fd0403ull,0x2280104200036c01ull,0x029b100080110000ull,
0x0780000008090000ull,0xc7801000f811c000ull,0x0780ba00c2010403ull,0x0003200188110020ull,
0x47e830f409fd0000ull,0x22801041a0036c01ull,0x0780001734010000ull,0x078010421003e420ull,
0x0780001734010000ull,0x0002f0000001e43full,0x0000861ffe03e000ull,0x0000a043c0030000ull,
0x11001043c0030000ull,0xc780100072010000ull,0x0780d05cc8092400ull,0x4780a00000152000ull,
0x8a001900e0104401ull,0x07e8b0810bfd1000ull,0x2680c08508116051ull,0x2680c0850a150040ull,
0xffff103f801d0040ull,0x478021000e1d0fffull,0x4780a0000e1d040eull,0x078090000a154401ull,
0x0780d05cd0090000ull,0x078090000e312000ull,0x8014c005081c4000ull,0x18301900e0101000ull,
0x07e8b08101fd9000ull,0x2680c08508116051ull,0x2680c0850a150040ull,0x0e1490000a000040ull,
0x4780e0000801c007ull,0x0780900000010801ull,0x1800900000004000ull,0x078000173601c000ull,
0x0002f0000001e420ull,0x0000861ffe03e000ull,0x0000a044b0030000ull,0xc780100004010000ull,
0x01001044b0030403ull,0x0780300204110000ull,0x878025000811c410ull,0x0780d00e08150407ull,
0x0780d05cd80980c0ull,0x0780c805c0152000ull,0x0780d00e08150020ull,0x002320008001a0c0ull,
0x0083200088110000ull,0x47e830e901fd0000ull,0x2280104430036c00ull,0x0002f00000010000ull,
0x0000861ffe03e000ull,0x0000a04640030000ull,0xc780100004010000ull,0x07e0000016010403ull,
0x210010464003a000ull,0xc780100072110000ull,0x0780300204152400ull,0x4780a0000811c410ull,
0x8a1c248e8a2c4401ull,0x0780d00e0e35249aull,0x0780d00e163180c0ull,0x0780d05cc80980c0ull,
0x6034100088142000ull,0x07e8b08109fdc90dull,0x2680c0851a356051ull,0x2680c0850a150040ull,
0x078090000a150040ull,0x0780e0051a150000ull,0x0780d00e16150403ull,0x002320008001a0c0ull,
0x008320008e1d0000ull,0x00832000962d0000ull,0x47e830c101fd0000ull,0x2280104550036c00ull,
0x0002f00000010000ull,0x0000861ffe03e000ull,0x0000a04770030000ull,0xc780100004010000ull,
0x0100104770030403ull,0x0780300204110000ull,0x8810249e8814c410ull,0x0780d00e0a2d248eull,
0x0780d00e081d80c0ull,0x07c8b08117fd80c0ull,0x0680c0850e1d6051ull,0x0680c085162d0040ull,
0x0e1c9000162c0040ull,0x002320008001c00bull,0x0780d00e0a1d0000ull,0x47c830e901fda0c0ull,
0x0083200088116c00ull,0x008320008a150000ull,0x02801046b0030000ull,0x0002f00000010000ull,
0x0000861ffe03e000ull,0x0780d00e12010000ull,0xc7801000101180c0ull,0x0780400d10152400ull,
0x4780600c12150000ull,0x078030100a150001ull,0x4780600c1011c410ull,0x8780210008110001ull,
0x0780300208110400ull,0x078025000815c410ull,0xc78010000a190401ull,0x8780250008112400ull,
0xffff203c8a1d0401ull,0x0780d00e0e2d0fffull,0x078021000c3180c0ull,0xffff203c88190401ull,
0x0780d00e0c1d0fffull,0x0780d00e101980c0ull,0x981c200c962c80c0ull,0x07802040162d2007ull,
0x87c830f905fd0400ull,0x878020400e1d6c01ull,0x0000a04a10030401ull,0xc780100004010000ull,
0x0280104a10030403ull,0xc7801000ee190000ull,0x0780400f18312400ull,0x0780600e1a310000ull,
0x0780301018310003ull,0x0780600e181dc410ull,0x0780300204190003ull,0xc78020000e1dc410ull,
0x878025000c190402ull,0x878030000e2d0408ull,0x4780307c162d6c00ull,0x4780a000162d6c01ull,
0x0023200080014411ull,0x0780d00e0c2d0000ull,0x47c830f901fda0c0ull,0x008320008c196c00ull,
0x0280104990030000ull,0x0002f00000010000ull,0x0000861ffe03e000ull,0x0780d00408090000ull,
0x87c8388005fd2000ull,0x0000a04f20036c01ull,0xc780100004190000ull,0x0280104f20030403ull,
0x0780300204010000ull,0x878025000031c410ull,0x87802500002d0409ull,0x000320018c390407ull,
0xc7801000fe1d0000ull,0xc78010001c012400ull,0x0780205a80030403ull,0xc780100000350000ull,
0xc7801000fe1d0403ull,0xc78010001c012400ull,0x0780205cd0030403ull,0x47c8307c1bfd0000ull,
0x00032001801d6c01ull,0xc5001000fe350000ull,0xc5001000001d2400ull,0x0780d00420090403ull,
0x078029000e392000ull,0x000320019c010400ull,0x07c830fc01fd0000ull,0x00031001801d6c01ull,
0x078021401c010000ull,0x02802100001d041full,0x07c830f81dfd0440ull,0xc2801000f0396c01ull,
0x47c830071dfd2400ull,0x0000a04e90036c00ull,0x0280104e80030000ull,0x0780d00418090000ull,
0x078029001a352000ull,0x000320019a010400ull,0x07c830fb01fd0000ull,0x0003100180016c01ull,
0xc78021401a3d0000ull,0x028021001e01041eull,0x07c830f71bfd0440ull,0xc2801000ee356c01ull,
0x000320019c3d2400ull,0xc7801000f8410000ull,0x87c830001bfd0403ull,0xc780100000396c01ull,
0x0000a04e30030403ull,0x0100104e30030000ull,0xc7801000ee010000ull,0x078040011c452400ull,
0x478060001e450000ull,0x0780301022450004ull,0x478060001c01c410ull,0x000320019a490004ull,
0xc780214000450000ull,0xa2442012a200041dull,0x078030022249200eull,0x878025002449c410ull,
0xffff203ca44d0408ull,0x0780d00e264d0fffull,0x0780b000264180c0ull,0x00032001a2450004ull,
0x00032004a4490000ull,0x47e8300023fd0000ull,0x2280104dc0036c01ull,0x0002f00000010000ull,
0x000320018e1de000ull,0x47e830071ffd0000ull,0x2280104d00036c01ull,0x0780104e90030000ull,
0xc7801000f8410000ull,0x0782d00e16010403ull,0x0780d004080980c0ull,0x002320008c192000ull,
0x47c838800dfd0000ull,0x0780c01000016c00ull,0x0780d00e18010000ull,0x00832000962da0c0ull,
0x0083200098310000ull,0x0280104ab0030000ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x87c830ff05fd0000ull,0x0000a051a0036c01ull,0xc780100004010000ull,0x02801051a0030403ull,
0x00b3201684190000ull,0x00ab201384090000ull,0x078000020c090000ull,0x0780d0040011c000ull,
0x07800002040d2000ull,0xc7801000f809c000ull,0xc7801000f8190403ull,0x47cc3080f9fd0403ull,
0x0100105150036c00ull,0xc7801000fe1d0000ull,0x0780400f002d2400ull,0xc780600e022d0000ull,
0x07803010162d0002ull,0xc780600e001dc410ull,0x0780d00400110002ull,0x078030020e2d2000ull,
0x0000a0514003c410ull,0x078421000e350000ull,0x8780250016310400ull,0x0780d00e18390409ull,
0x4780a0001c2d80c0ull,0x07e8b0061dfdc410ull,0xe68010000e096011ull,0xe680100016190403ull,
0x000320018e1d0403ull,0x0003200498310000ull,0x47e8300d0ffd0000ull,0x22801050b0036c01ull,
0x0002f00000010000ull,0x87800e040001e000ull,0x87800a040001e420ull,0x002320008001e421ull,
0x47e830ff01fd0000ull,0x2280105000036c00ull,0x0002f00000010000ull,0x0000861ffe03e000ull,
0x0000a05490030000ull,0x1100105490030000ull,0x87c830fff9fd0000ull,0xc7801000f8016c01ull,
0x0280105300030403ull,0x02c7101880090000ull,0x0780000004050000ull,0x07800000f809c000ull,
0xc7801000f81dc000ull,0xc7801000f8090403ull,0x07c8b402c1fd0403ull,0xc7801400c0196021ull,
0x0680d854980d0423ull,0xc6801c00c0012000ull,0xc68010000c090423ull,0x000320018e1d0403ull,
0x47c830ff0ffd0000ull,0x0780d40008056c01ull,0x0780d80008092000ull,0x0280105260032000ull,
0x0003200180090000ull,0xc7801000fe1d0000ull,0xc780100004012400ull,0x0780205a80030403ull,
0xc780100000190000ull,0xc7801000fe1d0403ull,0xc780100004012400ull,0x0780205cd0030403ull,
0x47c8307c0dfd0000ull,0xffff203f8c096c01ull,0xc500100008090fffull,0x0500210000012440ull,
0xc500210004090441ull,0x0780d00e1219041full,0xc7801000081d80c0ull,0xc780214004252400ull,
0x921c20c58e08040dull,0xc78020000c192042ull,0x000320018c190401ull,0x07802140001d0000ull,
0x0780d00e0a19040eull,0x0780d00e1001a0c0ull,0x80003007840880c0ull,0x0003200180012002ull,
0x0780d00e08010000ull,0x0002f0000001a0c0ull,0x0000861ffe03e000ull,0xc780100004010000ull,
0xcccf100d80112400ull,0x4780a00000090cccull,0x0780400908010411ull,0x07c060080a010000ull,
0x0780301000150000ull,0x078030100001c410ull,0x47d8600809fde410ull,0x8880210000010001ull,
0x178060090a010440ull,0x0780300300010c00ull,0x07c83082f9fdec10ull,0x0003300080096c01ull,
0xc280100004010000ull,0x0780300300090403ull,0x078030010001c410ull,0x800820008400c410ull,
0xc7801000f8013082ull,0x8780307c04090403ull,0x07c0000014016c00ull,0xc28010000001a000ull,
0x4780a00004092440ull,0x07c8d00201fd2c01ull,0x0100300000030400ull,0x0780a0004c090000ull,
0x0023101880010420ull,0x0780608304010000ull,0x0780000000056040ull,0xc78010001009c000ull,
0xc780140014012400ull,0x0780400108112400ull,0x078060000a110000ull,0x0780301008110001ull,
0x078060000801c410ull,0x8780210000090001ull,0xc780140014010400ull,0x0780300204112400ull,
0x078030020009c410ull,0x078025000801c410ull,0x0780d00e00010401ull,0x07802500041580c0ull,
0x0780d00e0a010400ull,0x878025000801a0c0ull,0x0780d00e00010401ull,0x87802500041180c0ull,
0x0780a00004050400ull,0x87c830b903fd0400ull,0x0780d00e08016c01ull,0x028030000003a0c0ull,
0xc78010000e010000ull,0x0780300202092400ull,0x4780a0000001c410ull,0x87802000060dc400ull,
0x0003b00080190400ull,0x00032001820903f8ull,0xc78010006e1d0000ull,0xc780100004012400ull,
0x0780205a80030403ull,0xc780100000210000ull,0xc78010006e1d0403ull,0xc780100004012400ull,
0x0780205cd0030403ull,0x47c8307c11fd0000ull,0xffff203f90216c01ull,0xc500100008090fffull,
0x0500210000012440ull,0xc500210004210441ull,0x0780d00e0809040dull,0x0780d00e0a2580c0ull,
0x0780d00e061d80c0ull,0x07802000040980c0ull,0xc780100012010400ull,0xffff202684092400ull,
0x0780400500290fffull,0x8780600402290000ull,0x0780301014290002ull,0x078020001221c410ull,
0x8780600400010402ull,0x0780200000010002ull,0x0780300200010402ull,0x078021000001c410ull,
0xfffb201880010400ull,0x0780d00e00010fffull,0x0780c0870e0980c0ull,0x4780a00004090000ull,
0x4780a0000001c400ull,0x8780e0060001c400ull,0x0023200082050000ull,0x0780d00e06010000ull,
0x47c830b903fda0c0ull,0x00832000860d6c00ull,0x0280105810030000ull,0x0780300000030000ull,
0x4780a0000e490000ull,0x4780a000244d0411ull,0x4780a00000514400ull,0x0780900026550411ull,
0x4780a000284d0000ull,0xffff203eaa554406ull,0xc7f0c015264d0fffull,0x4780a000264d0000ull,
0x0780402748598406ull,0x878060264a590000ull,0x078030102c590005ull,0x878060264859c410ull,
0x8780204028590005ull,0x4780a0002c590405ull,0xc7f0c0152c554406ull,0x4780a0002a550000ull,
0x47802000264d8406ull,0x078040244e550405ull,0x478060254c550000ull,0x078030102a550005ull,
0x478060244c55c410ull,0x078030002a550005ull,0xc780301524550405ull,0xc78030002a4d6400ull,
0x078040244e550404ull,0x478060254c550000ull,0x078030102a550005ull,0x478060244c49c410ull,
0x0780301f00010005ull,0x07803000244de410ull,0x4780a00000490405ull,0x8780d01324492c01ull,
0x47f8307c0ffd0400ull,0x8780200000016c01ull,0xf500d00700010404ull,0x3780300000030402ull,
0x0000f00000010000ull,0x4780a0000e49e000ull,0x4780a000244d0411ull,0x4780a00000514400ull,
0x0780900026550411ull,0x4780a000284d0000ull,0xffff203eaa554406ull,0xc7f0c015264d0fffull,
0x4780a000264d0000ull,0x0780402748598406ull,0x878060264a590000ull,0x078030102c590005ull,
0x878060264859c410ull,0x8780204028590005ull,0x4780a0002c590405ull,0xc7f0c0152c554406ull,
0x4780a0002a550000ull,0x47802000264d8406ull,0x078040244e550405ull,0x478060254c550000ull,
0x078030102a550005ull,0x478060244c55c410ull,0x078030002a510005ull,0xc780301424490405ull,
0x8780d0000e016400ull,0x0780301f00010400ull,0xc7803000244de410ull,0x4780a00000490404ull,
0x8780d01324492c01ull,0x47f8307c0ffd0400ull,0x8780200000016c01ull,0xf500d00700010404ull,
0x3780300000030402ull,0x0001f00000010000ull,0x000000000001e000ull,0x00a0000100007e80ull,
0x0000ffffffff0000ull,0x0000000000003e80ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000600000000ull,0x000055c400000005ull,0x0000000000000000ull,0x0000000000000000ull,
0x000000e000000000ull,0x000000e000000000ull,0x0000000400000000ull,0x6000000000000000ull,
0x0000044200000a05ull,0x0000000000000000ull,0x0000000000000000ull,0x00002f8800000000ull,
0x00002f8800000000ull,0x0000000400000000ull,0x6000000000000000ull,0x000033ca00000a06ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x00002e7000000000ull,
0x0000000400000000ull,0x0000000100000000ull,0x000033ca00000005ull,0x0000000000000000ull,
0x0000000000000000ull,0x000021f800000000ull,0x000021f800000000ull,0x0000000400000000ull,
0x0000000000000000ull
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
0x30305f3832633230ull,0x372d303030303030ull,0x70632e6e69616d5full,0x742f2820692e3370ull,
0x23494263632f706dull,0x29776b697a43462eull,0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x6974704f202f2f09ull,0x2f2f090a3a736e6full,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x202f2f090a2d2d2dull,
0x3a74656772615420ull,0x415349202c787470ull,0x202c30315f6d733aull,0x6c3a6e6169646e45ull,
0x50202c656c747469ull,0x53207265746e696full,0x090a34363a657a69ull,0x09334f2d20202f2full,
0x7a696d6974704f28ull,0x656c206e6f697461ull,0x2f2f090a296c6576ull,0x44280930672d2020ull,
0x76656c2067756265ull,0x202f2f090a296c65ull,0x65522809326d2d20ull,0x7664612074726f70ull,
0x29736569726f7369ull,0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x0a2d2d2d2d2d2d2dull,0x09656c69662e090aull,0x6d6d6f633c220931ull,0x656e696c2d646e61ull,
0x6c69662e090a223eull,0x6d742f2209320965ull,0x746678706d742f70ull,0x326332303030305full,
0x3030303030305f38ull,0x69616d5f362d3030ull,0x6566616475632e6eull,0x090a227570672e32ull,
0x093309656c69662eull,0x2e656e6966656422ull,0x6c69662e090a2263ull,0x73752f2209340965ull,
0x63672f62696c2f72ull,0x34365f3638782f63ull,0x672d78756e696c2dull,0x312e342e342f756eull,
0x6564756c636e692full,0x2e6665646474732full,0x6c69662e090a2268ull,0x6f682f2209350965ull,
0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x72632f6564756c63ull,
0x6563697665642f74ull,0x656d69746e75725full,0x69662e090a22682eull,0x682f22093609656cull,
0x6d726f6e2f656d6full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x682f6564756c636eull,
0x696665645f74736full,0x090a22682e73656eull,0x093709656c69662eull,0x6e2f656d6f682f22ull,
0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x69746c6975622f65ull,
0x2e73657079745f6eull,0x6c69662e090a2268ull,0x6f682f2209380965ull,0x616d726f6e2f656dull,
0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65642f6564756c63ull,0x7079745f65636976ull,
0x2e090a22682e7365ull,0x22093909656c6966ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x5f7265766972642full,0x22682e7365707974ull,
0x09656c69662e090aull,0x6d6f682f22093031ull,0x6c616d726f6e2f65ull,0x69622f616475632full,
0x636e692f2e2e2f6eull,0x7275732f6564756cull,0x7079745f65636166ull,0x2e090a22682e7365ull,
0x09313109656c6966ull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,
0x64756c636e692f2eull,0x7275747865742f65ull,0x2e73657079745f65ull,0x6c69662e090a2268ull,
0x682f220932310965ull,0x6d726f6e2f656d6full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x762f6564756c636eull,0x79745f726f746365ull,0x090a22682e736570ull,0x333109656c69662eull,
0x2f656d6f682f2209ull,0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,
0x63697665642f6564ull,0x68636e75616c5f65ull,0x74656d617261705full,0x090a22682e737265ull,
0x343109656c69662eull,0x2f656d6f682f2209ull,0x632f6c616d726f6eull,0x2f6e69622f616475ull,
0x756c636e692f2e2eull,0x732f7472632f6564ull,0x635f656761726f74ull,0x0a22682e7373616cull,
0x3109656c69662e09ull,0x2f7273752f220935ull,0x2f6564756c636e69ull,0x7079742f73746962ull,
0x2e090a22682e7365ull,0x09363109656c6966ull,0x6e692f7273752f22ull,0x69742f6564756c63ull,
0x2e090a22682e656dull,0x09373109656c6966ull,0x75632e6e69616d22ull,0x656c69662e090a22ull,
0x6f682f2209383109ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x6f632f6564756c63ull,0x6e75665f6e6f6d6dull,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x6f682f2209393109ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x72632f6564756c63ull,0x6d5f636e75662f74ull,0x0a22682e6f726361ull,0x3209656c69662e09ull,
0x656d6f682f220930ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x6874616d2f656475ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09313209656c6966ull,
0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x6563697665642f65ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09323209656c6966ull,
0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x635f6874616d2f65ull,0x73746e6174736e6full,0x69662e090a22682eull,0x2f2209333209656cull,
0x726f6e2f656d6f68ull,0x616475632f6c616dull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x74615f31315f6d73ull,0x6e75665f63696d6full,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x6f682f2209343209ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x6d732f6564756c63ull,0x6d6f74615f32315full,0x74636e75665f6369ull,0x0a22682e736e6f69ull,
0x3209656c69662e09ull,0x656d6f682f220935ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x315f6d732f656475ull,0x656c62756f645f33ull,0x6f6974636e75665full,
0x2e090a22682e736eull,0x09363209656c6966ull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x6e6f6d6d6f632f65ull,0x682e73657079745full,
0x656c69662e090a22ull,0x6f682f2209373209ull,0x616d726f6e2f656dull,0x622f616475632f6cull,
0x6e692f2e2e2f6e69ull,0x6d732f6564756c63ull,0x6d6f74615f30325full,0x74636e75665f6369ull,
0x0a22682e736e6f69ull,0x3209656c69662e09ull,0x656d6f682f220938ull,0x2f6c616d726f6e2full,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x325f6d732f656475ull,0x6e6972746e695f30ull,
0x0a22682e73636973ull,0x3209656c69662e09ull,0x656d6f682f220939ull,0x2f6c616d726f6e2full,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x667275732f656475ull,0x636e75665f656361ull,
0x22682e736e6f6974ull,0x09656c69662e090aull,0x6d6f682f22093033ull,0x6c616d726f6e2f65ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x7865742f6564756cull,0x7465665f65727574ull,
0x74636e75665f6863ull,0x0a22682e736e6f69ull,0x3309656c69662e09ull,0x656d6f682f220931ull,
0x2f6c616d726f6e2full,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x6874616d2f656475ull,
0x6f6974636e75665full,0x705f6c62645f736eull,0x090a22682e317874ull,0x323309656c69662eull,
0x6c656e72656b2209ull,0x2e090a0a2275632eull,0x612e2074736e6f63ull,0x2e2038206e67696cull,
0x6d6f635f64203862ull,0x6e6168635f6e6f6dull,0x0a3b5d36315b6567ull,0x2074736e6f632e09ull,
0x38206e67696c612eull,0x635f642038622e20ull,0x32355b6e6f6d6d6full,0x6f632e090a3b5d30ull,
0x696c612e2074736eull,0x38622e2038206e67ull,0x7571696e755f6420ull,0x3b5d303631385b65ull,
0x72746e652e090a0aull,0x72656b365a5f2079ull,0x0a7b090a766c656eull,0x752e206765722e09ull,
0x31363c7225203233ull,0x65722e090a3b3e39ull,0x25203436752e2067ull,0x3b3e3230323c6472ull,
0x2e206765722e090aull,0x393c662520323366ull,0x65722e090a3b3e36ull,0x25203436662e2067ull,
0x090a3b3e383c6466ull,0x72702e206765722eull,0x32313c7025206465ull,0x68732e090a3b3e37ull,
0x6c612e2064657261ull,0x622e2034206e6769ull,0x616475635f5f2038ull,0x6f6d5f6e695f645full,
0x3638706d65745f64ull,0x34303430315b3639ull,0x6168732e090a3b5dull,0x696c612e20646572ull,
0x38622e2034206e67ull,0x5f616475635f5f20ull,0x69747261705f6e69ull,0x39316d75735f6c61ull,
0x5d3430325b303031ull,0x726168732e090a3bull,0x67696c612e206465ull,0x2038622e2034206eull,
0x695f616475635f5full,0x61705f7271735f6eull,0x75735f6c61697472ull,0x325b34303339316dull,
0x732e090a3b5d3430ull,0x612e206465726168ull,0x2e2034206e67696cull,0x6475635f5f203862ull,
0x616d5f7261705f61ull,0x3539316f6f635f78ull,0x3b5d3432355b3830ull,0x65726168732e090aull,
0x6e67696c612e2064ull,0x5f2038622e203420ull,0x61705f616475635full,0x61765f78616d5f72ull,
0x355b32333030326cull,0x732e090a3b5d3432ull,0x662e206465726168ull,0x69665f6e69203233ull,
0x3b6d75735f6c616eull,0x65726168732e090aull,0x69203233662e2064ull,0x69665f7271735f6eull,
0x3b6d75735f6c616eull,0x65726168732e090aull,0x64203233662e2064ull,0x090a3b546d6f6e65ull,
0x09373109636f6c2eull,0x240a300933333631ull,0x365a5f5f3142424cull,0x3a766c656e72656bull,
0x6e6f632e646c090aull,0x09203233732e7473ull,0x5f645b202c317225ull,0x635f6e6f6d6d6f63ull,
0x5d382b65676e6168ull,0x752e766f6d090a3bull,0x2c32722509203233ull,0x746573090a3b3020ull,
0x3233732e656e2e70ull,0x25202c3170250920ull,0x3b327225202c3172ull,0x622031702540090aull,
0x5f744c2409206172ull,0x3b36303535385f30ull,0x3309636f6c2e090aull,0x090a300930390932ull,
0x203436752e766f6dull,0x64202c3164722509ull,0x3b657571696e755full,0x33732e747663090aull,
0x2509203631752e32ull,0x61746325202c3372ull,0x63090a3b782e6469ull,0x732e3436732e7476ull,
0x3264722509203233ull,0x090a3b337225202cull,0x752e6f6c2e6c756dull,0x3364722509203436ull,
0x202c32647225202cull,0x6461090a3b303631ull,0x2509203436752e64ull,0x647225202c346472ull,
0x3b33647225202c31ull,0x6e6f632e646c090aull,0x09203436752e7473ull,0x255b202c35647225ull,
0x3b5d32332b346472ull,0x6e6f632e646c090aull,0x09203233732e7473ull,0x72255b202c347225ull,
0x0a3b5d34342b3464ull,0x3436752e74766309ull,0x722509203233732eull,0x3b347225202c3664ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x36647225202c3764ull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x647225202c386472ull,0x3b37647225202c35ull,0x36732e766f6d090aull,
0x2c39647225092034ull,0x090a3b3864722520ull,0x2e3233732e747663ull,0x3572250920363175ull,
0x782e64697425202cull,0x752e766f6d090a3bull,0x2c36722509203233ull,0x746573090a3b3020ull,
0x3233732e656e2e70ull,0x25202c3270250920ull,0x3b367225202c3572ull,0x622032702540090aull,
0x5f744c2409206172ull,0x3b34393934385f30ull,0x3309636f6c2e090aull,0x0a30093230310932ull,
0x736e6f632e646c09ull,0x2509203233732e74ull,0x6472255b202c3772ull,0x090a3b5d30342b34ull,
0x74736e6f632e646cull,0x722509203233732eull,0x6f635f645b202c38ull,0x5d36312b6e6f6d6dull,
0x6c2e6c756d090a3bull,0x2509203233732e6full,0x2c387225202c3972ull,0x63090a3b37722520ull,
0x732e3436752e7476ull,0x3164722509203233ull,0x0a3b377225202c30ull,0x3233732e64646109ull,
0x202c303172250920ull,0x317225202c397225ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x7225202c31316472ull,0x0a3b34202c303164ull,0x3436752e74766309ull,0x722509203233732eull,
0x317225202c323164ull,0x2e6c756d090a3b30ull,0x09203436752e6f6cull,0x25202c3331647225ull,
0x3b34202c32316472ull,0x6e6f632e646c090aull,0x09203436752e7473ull,0x5b202c3431647225ull,
0x3b5d302b34647225ull,0x36752e646461090aull,0x3531647225092034ull,0x2c3431647225202cull,
0x0a3b313164722520ull,0x626f6c672e646c09ull,0x09203233732e6c61ull,0x255b202c31317225ull,
0x3b5d302b35316472ull,0x6e6f632e646c090aull,0x09203436752e7473ull,0x5b202c3631647225ull,
0x5d36312b34647225ull,0x752e646461090a3bull,0x3164722509203436ull,0x3631647225202c37ull,
0x3b3331647225202cull,0x6f6c672e7473090aull,0x203233732e6c6162ull,0x2b37316472255b09ull,
0x31317225202c5d30ull,0x09636f6c2e090a3bull,0x3009333031093233ull,0x6e6f632e646c090aull,
0x09203436752e7473ull,0x5b202c3831647225ull,0x3b5d382b34647225ull,0x36752e646461090aull,
0x3931647225092034ull,0x2c3831647225202cull,0x0a3b313164722520ull,0x626f6c672e646c09ull,
0x09203233732e6c61ull,0x255b202c32317225ull,0x3b5d302b39316472ull,0x6e6f632e646c090aull,
0x09203436752e7473ull,0x5b202c3032647225ull,0x5d34322b34647225ull,0x752e646461090a3bull,
0x3264722509203436ull,0x3032647225202c31ull,0x3b3331647225202cull,0x6f6c672e7473090aull,
0x203233732e6c6162ull,0x2b31326472255b09ull,0x32317225202c5d30ull,0x5f305f744c240a3bull,
0x090a3a3439393438ull,0x09323309636f6c2eull,0x6d090a3009323131ull,0x09203233732e766full,
0x7225202c33317225ull,0x632e646c090a3b35ull,0x3233732e74736e6full,0x202c343172250920ull,
0x6f6d6d6f635f645bull,0x0a3b5d3231322b6eull,0x65672e7074657309ull,0x702509203233732eull,
0x202c357225202c33ull,0x40090a3b34317225ull,0x2061726220337025ull,0x385f305f744c2409ull,
0x73090a3b36303535ull,0x09203233732e6275ull,0x7225202c35317225ull,0x3b357225202c3431ull,
0x33732e646461090aull,0x2c36317225092032ull,0x35202c3531722520ull,0x726873090a3b3131ull,
0x722509203233732eull,0x36317225202c3731ull,0x6d090a3b3133202cull,0x09203233732e766full,
0x3135202c38317225ull,0x2e646e61090a3b31ull,0x3172250920323362ull,0x2c37317225202c39ull,
0x090a3b3831722520ull,0x203233732e646461ull,0x25202c3032722509ull,0x317225202c393172ull,
0x2e726873090a3b36ull,0x3272250920323373ull,0x2c30327225202c31ull,0x2e646c090a3b3920ull,
0x33732e74736e6f63ull,0x202c377225092032ull,0x30342b346472255bull,0x632e646c090a3b5dull,
0x3436752e74736e6full,0x2c32326472250920ull,0x302b346472255b20ull,0x632e646c090a3b5dull,
0x3436752e74736e6full,0x2c33326472250920ull,0x382b346472255b20ull,0x2e747663090a3b5dull,
0x203233732e343675ull,0x202c343264722509ull,0x756d090a3b377225ull,0x3436752e6f6c2e6cull,
0x2c31316472250920ull,0x202c343264722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x32647225202c3532ull,0x3131647225202c32ull,0x752e646461090a3bull,0x3264722509203436ull,
0x3332647225202c36ull,0x3b3131647225202cull,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x645b202c32327225ull,0x2b6e6f6d6d6f635full,0x646c090a3b5d3032ull,0x752e74736e6f632eull,
0x3264722509203436ull,0x6f635f645b202c37ull,0x6168635f6e6f6d6dull,0x0a3b5d302b65676eull,
0x736e6f632e646c09ull,0x2509203233732e74ull,0x5f645b202c333272ull,0x322b6e6f6d6d6f63ull,
0x6f6d090a3b5d3430ull,0x2509203233732e76ull,0x327225202c343272ull,0x305f744c240a3b31ull,
0x0a3a38313036385full,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x656e202c32313120ull,0x656420676e697473ull,0x202c31203a687470ull,0x6574616d69747365ull,
0x7461726574692064ull,0x6e75203a736e6f69ull,0x2e090a6e776f6e6bull,0x3109323309636f6cull,
0x6461090a30093631ull,0x2509203233732e64ull,0x317225202c353272ull,0x72090a3b31202c33ull,
0x09203233732e6d65ull,0x7225202c36327225ull,0x33327225202c3532ull,0x732e627573090a3bull,
0x3732722509203233ull,0x202c36327225202cull,0x636f6c2e090a3b31ull,0x0937313109323309ull,
0x732e766964090a30ull,0x3832722509203233ull,0x202c35327225202cull,0x6d090a3b33327225ull,
0x09203233752e766full,0x3b30202c39327225ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x36327225202c3470ull,0x0a3b39327225202cull,0x7262203470254009ull,0x305f744c24092061ull,
0x0a3b34373236385full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c32313120ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x090a38313036385full,0x09323309636f6c2eull,0x73090a3009393131ull,0x09203233732e6275ull,
0x7225202c37327225ull,0x090a3b31202c3332ull,0x09323309636f6c2eull,0x73090a3009303231ull,
0x09203233732e6275ull,0x7225202c38327225ull,0x240a3b31202c3832ull,0x3236385f305f744cull,
0x3c2f2f200a3a3437ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x32313120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3036385f305f744cull,
0x636f6c2e090a3831ull,0x0939323109323309ull,0x6c672e646c090a30ull,0x3233732e6c61626full,
0x202c303372250920ull,0x302b35326472255bull,0x2e646461090a3b5dull,0x3372250920323373ull,
0x2c30337225202c31ull,0x090a3b3732722520ull,0x61626f6c672e646cull,0x2509203233732e6cull,
0x72255b202c323372ull,0x0a3b5d302b363264ull,0x3233732e64646109ull,0x202c333372250920ull,
0x7225202c32337225ull,0x627573090a3b3832ull,0x722509203233732eull,0x33337225202c3433ull,
0x6d090a3b3632202cull,0x33732e6f6c2e6c75ull,0x2c35337225092032ull,0x25202c3232722520ull,
0x6461090a3b343372ull,0x2509203233732e64ull,0x337225202c363372ull,0x3b35337225202c31ull,
0x36752e747663090aull,0x2509203233732e34ull,0x7225202c38326472ull,0x6c756d090a3b3633ull,
0x203436752e6f6c2eull,0x202c393264722509ull,0x34202c3832647225ull,0x752e646461090a3bull,
0x3364722509203436ull,0x3732647225202c30ull,0x3b3932647225202cull,0x6f6c672e646c090aull,
0x203233662e6c6162ull,0x255b202c31662509ull,0x30312d2b30336472ull,0x6c756d090a3b5d34ull,
0x203233732e6f6c2eull,0x25202c3733722509ull,0x327225202c383272ull,0x2e646461090a3b33ull,
0x3372250920323373ull,0x2c37327225202c38ull,0x090a3b3733722520ull,0x2e3436732e747663ull,
0x6472250920323373ull,0x38337225202c3133ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x7225202c32336472ull,0x0a3b34202c313364ull,0x3436752e64646109ull,0x2c33336472250920ull,
0x25202c3864722520ull,0x73090a3b32336472ull,0x6c61626f6c672e74ull,0x255b09203233662eull,
0x2c5d302b33336472ull,0x61090a3b31662520ull,0x09203233732e6464ull,0x7225202c33317225ull,
0x3b323135202c3331ull,0x6c2e70746573090aull,0x2509203233732e74ull,0x33317225202c3570ull,
0x0a3b34317225202cull,0x7262203570254009ull,0x305f744c24092061ull,0x0a3b38313036385full,
0x35385f305f744c24ull,0x744c240a3a363035ull,0x32383434385f305full,0x752e766f6d090a3aull,
0x3164722509203436ull,0x71696e755f64202cull,0x766f6d090a3b6575ull,0x722509203233732eull,
0x090a3b30202c3933ull,0x2e656e2e70746573ull,0x3670250920323373ull,0x25202c317225202cull,
0x2140090a3b393372ull,0x2061726220367025ull,0x385f305f744c2409ull,0x2e090a3b32343037ull,
0x3109323309636f6cull,0x7663090a30093135ull,0x31752e3233732e74ull,0x2c30347225092036ull,
0x2e64696174632520ull,0x2e747663090a3b78ull,0x203233732e343673ull,0x202c343364722509ull,
0x6d090a3b30347225ull,0x36752e6f6c2e6c75ull,0x3533647225092034ull,0x2c3433647225202cull,
0x61090a3b30363120ull,0x09203436752e6464ull,0x7225202c34647225ull,0x33647225202c3164ull,
0x632e646c090a3b35ull,0x3233732e74736e6full,0x5b202c3772250920ull,0x5d30342b34647225ull,
0x6f632e646c090a3bull,0x203436752e74736eull,0x202c323264722509ull,0x5d302b346472255bull,
0x752e747663090a3bull,0x09203233732e3436ull,0x25202c3633647225ull,0x6c756d090a3b3772ull,
0x203436752e6f6c2eull,0x202c313164722509ull,0x34202c3633647225ull,0x752e646461090a3bull,
0x3264722509203436ull,0x3232647225202c35ull,0x3b3131647225202cull,0x6e6f632e646c090aull,
0x09203233732e7473ull,0x645b202c31347225ull,0x2b6e6f6d6d6f635full,0x2e646c090a3b5d30ull,
0x732e6c61626f6c67ull,0x3234722509203233ull,0x35326472255b202cull,0x7573090a3b5d302bull,
0x2509203233732e62ull,0x347225202c333472ull,0x3b31347225202c32ull,0x3309636f6c2e090aull,
0x0a30093235310932ull,0x736e6f632e646c09ull,0x2509203436752e74ull,0x255b202c33326472ull,
0x0a3b5d382b346472ull,0x3436752e64646109ull,0x2c36326472250920ull,0x202c333264722520ull,
0x090a3b3131647225ull,0x61626f6c672e646cull,0x2509203233732e6cull,0x72255b202c343472ull,
0x0a3b5d302b363264ull,0x3233732e62757309ull,0x202c353472250920ull,0x7225202c34347225ull,
0x6f6c2e090a3b3134ull,0x3535310932330963ull,0x2e747663090a3009ull,0x203631752e323373ull,
0x7425202c35722509ull,0x6d090a3b782e6469ull,0x09203233732e766full,0x7225202c33317225ull,
0x632e646c090a3b35ull,0x3233732e74736e6full,0x202c363472250920ull,0x6f6d6d6f635f645bull,
0x0a3b5d3832322b6eull,0x65672e7074657309ull,0x702509203233732eull,0x202c357225202c37ull,
0x40090a3b36347225ull,0x2061726220377025ull,0x385f305f744c2409ull,0x73090a3b34353537ull,
0x09203233732e6275ull,0x7225202c37347225ull,0x3b357225202c3634ull,0x33732e646461090aull,
0x2c38347225092032ull,0x35202c3734722520ull,0x726873090a3b3131ull,0x722509203233732eull,
0x38347225202c3934ull,0x6d090a3b3133202cull,0x09203233732e766full,0x3135202c30357225ull,
0x2e646e61090a3b31ull,0x3572250920323362ull,0x2c39347225202c31ull,0x090a3b3035722520ull,
0x203233732e646461ull,0x25202c3235722509ull,0x347225202c313572ull,0x2e726873090a3b38ull,
0x3572250920323373ull,0x2c32357225202c33ull,0x747663090a3b3920ull,0x3233732e3436752eull,
0x2c37336472250920ull,0x6d090a3b35722520ull,0x36752e6f6c2e6c75ull,0x3833647225092034ull,
0x2c3733647225202cull,0x2e646c090a3b3420ull,0x36752e74736e6f63ull,0x3933647225092034ull,
0x2b346472255b202cull,0x6461090a3b5d3834ull,0x2509203436752e64ull,0x7225202c30346472ull,
0x647225202c393364ull,0x2e646c090a3b3833ull,0x33732e74736e6f63ull,0x2c34357225092032ull,
0x6d6d6f635f645b20ull,0x3b5d3032322b6e6full,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x645b202c32327225ull,0x2b6e6f6d6d6f635full,0x646c090a3b5d3032ull,0x752e74736e6f632eull,
0x3264722509203436ull,0x6f635f645b202c37ull,0x6168635f6e6f6d6dull,0x0a3b5d302b65676eull,
0x3233732e766f6d09ull,0x202c353572250920ull,0x4c240a3b33357225ull,0x363038385f305f74ull,
0x6c3c2f2f200a3a36ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,0x2c35353120656e69ull,
0x676e697473656e20ull,0x203a687470656420ull,0x6d69747365202c31ull,0x6574692064657461ull,
0x3a736e6f69746172ull,0x6e776f6e6b6e7520ull,0x3309636f6c2e090aull,0x0a30093935310932ull,
0x3233732e64646109ull,0x202c353272250920ull,0x3b31202c33317225ull,0x33732e6d6572090aull,
0x2c36357225092032ull,0x25202c3532722520ull,0x7573090a3b343572ull,0x2509203233732e62ull,
0x357225202c373272ull,0x2e090a3b31202c36ull,0x3109323309636f6cull,0x6964090a30093036ull,
0x2509203233732e76ull,0x327225202c383272ull,0x3b34357225202c35ull,0x33752e766f6d090aull,
0x2c37357225092032ull,0x746573090a3b3020ull,0x3233732e656e2e70ull,0x25202c3870250920ull,
0x357225202c363572ull,0x38702540090a3b37ull,0x4c24092061726220ull,0x323338385f305f74ull,
0x6c3c2f2f200a3b32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x363038385f305f74ull,
0x09636f6c2e090a36ull,0x3009323631093233ull,0x33732e627573090aull,0x2c37327225092032ull,
0x31202c3435722520ull,0x09636f6c2e090a3bull,0x3009333631093233ull,0x33732e627573090aull,
0x2c38327225092032ull,0x31202c3832722520ull,0x5f305f744c240a3bull,0x200a3a3232333838ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c353531ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x2e090a3636303838ull,
0x3109323309636f6cull,0x6461090a30093936ull,0x2509203233732e64ull,0x327225202c383572ull,
0x3b33347225202c37ull,0x33732e646461090aull,0x2c39357225092032ull,0x25202c3832722520ull,
0x7573090a3b353472ull,0x2509203233732e62ull,0x357225202c303672ull,0x6d090a3b31202c39ull,
0x33732e6f6c2e6c75ull,0x2c31367225092032ull,0x25202c3232722520ull,0x6461090a3b303672ull,
0x2509203233732e64ull,0x357225202c323672ull,0x3b31367225202c38ull,0x36732e747663090aull,
0x2509203233732e34ull,0x7225202c31346472ull,0x6c756d090a3b3236ull,0x203436752e6f6c2eull,
0x202c323464722509ull,0x34202c3134647225ull,0x752e646461090a3bull,0x3464722509203436ull,
0x3732647225202c33ull,0x3b3234647225202cull,0x6f6c672e646c090aull,0x203233662e6c6162ull,
0x255b202c32662509ull,0x5d342d2b33346472ull,0x6c672e7473090a3bull,0x3233662e6c61626full,
0x30346472255b0920ull,0x326625202c5d302bull,0x732e646461090a3bull,0x3331722509203233ull,
0x202c33317225202cull,0x6461090a3b323135ull,0x2509203436752e64ull,0x7225202c30346472ull,
0x343032202c303464ull,0x70746573090a3b38ull,0x203233732e746c2eull,0x7225202c39702509ull,
0x36347225202c3331ull,0x2039702540090a3bull,0x744c240920617262ull,0x36363038385f305full,
0x5f305f744c240a3bull,0x090a3a3435353738ull,0x09323309636f6c2eull,0x62090a3009303831ull,
0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x3139310932330963ull,0x632e646c090a3009ull,
0x3436752e74736e6full,0x2c34346472250920ull,0x332b346472255b20ull,0x2e646c090a3b5d32ull,
0x33732e74736e6f63ull,0x2c33367225092032ull,0x342b346472255b20ull,0x747663090a3b5d34ull,
0x3233732e3436752eull,0x2c35346472250920ull,0x090a3b3336722520ull,0x752e6f6c2e6c756dull,
0x3464722509203436ull,0x3534647225202c36ull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x647225202c386472ull,0x34647225202c3434ull,0x2e766f6d090a3b36ull,0x6472250920343673ull,
0x3b38647225202c39ull,0x3309636f6c2e090aull,0x0a30093439310932ull,0x3233732e766f6d09ull,
0x202c333172250920ull,0x646c090a3b357225ull,0x732e74736e6f632eull,0x3431722509203233ull,
0x6d6f635f645b202cull,0x5d3231322b6e6f6dull,0x2e70746573090a3bull,0x09203233732e6567ull,
0x7225202c30317025ull,0x3b34317225202c35ull,0x203031702540090aull,0x744c240920617262ull,
0x30393039385f305full,0x752e766f6d090a3bull,0x3464722509203436ull,0x6475635f5f202c37ull,
0x6d5f6e695f645f61ull,0x38706d65745f646full,0x7573090a3b363936ull,0x2509203233732e62ull,
0x317225202c343672ull,0x0a3b357225202c34ull,0x3233732e64646109ull,0x202c353672250920ull,
0x3135202c34367225ull,0x2e726873090a3b31ull,0x3672250920323373ull,0x2c35367225202c36ull,
0x6f6d090a3b313320ull,0x2509203233732e76ull,0x313135202c373672ull,0x622e646e61090a3bull,
0x3836722509203233ull,0x202c36367225202cull,0x61090a3b37367225ull,0x09203233732e6464ull,
0x7225202c39367225ull,0x35367225202c3836ull,0x732e726873090a3bull,0x3037722509203233ull,
0x202c39367225202cull,0x2e747663090a3b39ull,0x203233732e343673ull,0x202c383464722509ull,
0x756d090a3b357225ull,0x3436752e6f6c2e6cull,0x2c39346472250920ull,0x202c383464722520ull,
0x2e646461090a3b34ull,0x6472250920343675ull,0x34647225202c3035ull,0x3934647225202c37ull,
0x6f632e646c090a3bull,0x203233732e74736eull,0x5b202c3332722509ull,0x6e6f6d6d6f635f64ull,
0x090a3b5d3430322bull,0x203233732e766f6dull,0x25202c3137722509ull,0x744c240a3b303772ull,
0x32303639385f305full,0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,
0x202c34393120656eull,0x20676e697473656eull,0x31203a6874706564ull,0x616d69747365202cull,
0x7265746920646574ull,0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,0x323309636f6c2e09ull,
0x090a300938393109ull,0x203233732e646461ull,0x25202c3532722509ull,0x0a3b31202c333172ull,
0x3233732e6d657209ull,0x202c363272250920ull,0x7225202c35327225ull,0x627573090a3b3332ull,
0x722509203233732eull,0x36327225202c3732ull,0x6c2e090a3b31202cull,0x393109323309636full,
0x766964090a300939ull,0x722509203233732eull,0x35327225202c3832ull,0x0a3b33327225202cull,
0x3233752e766f6d09ull,0x202c323772250920ull,0x70746573090a3b30ull,0x203233732e656e2eull,
0x25202c3131702509ull,0x377225202c363272ull,0x31702540090a3b32ull,0x2409206172622031ull,
0x3839385f305f744cull,0x3c2f2f200a3b3835ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x34393120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3639385f305f744cull,0x636f6c2e090a3230ull,0x0931303209323309ull,0x732e627573090a30ull,
0x3732722509203233ull,0x202c33327225202cull,0x636f6c2e090a3b31ull,0x0932303209323309ull,
0x732e627573090a30ull,0x3832722509203233ull,0x202c38327225202cull,0x305f744c240a3b31ull,
0x0a3a38353839385full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c34393120ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x090a32303639385full,0x09323309636f6c2eull,0x73090a3009383032ull,0x09203233732e6275ull,
0x7225202c33377225ull,0x38327225202c3332ull,0x732e627573090a3bull,0x3437722509203233ull,
0x202c33377225202cull,0x2e6c756d090a3b31ull,0x09203233732e6f6cull,0x7225202c35377225ull,
0x34377225202c3332ull,0x732e627573090a3bull,0x3637722509203233ull,0x202c33327225202cull,
0x61090a3b37327225ull,0x09203233732e6464ull,0x7225202c37377225ull,0x36377225202c3537ull,
0x732e747663090a3bull,0x09203233732e3436ull,0x25202c3135647225ull,0x756d090a3b373772ull,
0x3436752e6f6c2e6cull,0x2c32356472250920ull,0x202c313564722520ull,0x2e646461090a3b34ull,
0x6472250920343675ull,0x38647225202c3335ull,0x3b3235647225202cull,0x6f6c672e646c090aull,
0x203233662e6c6162ull,0x255b202c33662509ull,0x5d342d2b33356472ull,0x68732e7473090a3bull,
0x3233662e64657261ull,0x30356472255b0920ull,0x336625202c5d302bull,0x732e646461090a3bull,
0x3331722509203233ull,0x202c33317225202cull,0x6461090a3b323135ull,0x2509203436752e64ull,
0x7225202c30356472ull,0x343032202c303564ull,0x70746573090a3b38ull,0x203233732e746c2eull,
0x25202c3231702509ull,0x317225202c333172ull,0x31702540090a3b34ull,0x2409206172622032ull,
0x3639385f305f744cull,0x5f744c240a3b3230ull,0x3a30393039385f30ull,0x36752e766f6d090aull,
0x3734647225092034ull,0x616475635f5f202cull,0x6f6d5f6e695f645full,0x3638706d65745f64ull,
0x6f6c2e090a3b3639ull,0x3931320932330963ull,0x2e726162090a3009ull,0x3b300920636e7973ull,
0x3309636f6c2e090aull,0x0a30093632320932ull,0x3233732e766f6d09ull,0x202c333172250920ull,
0x646c090a3b357225ull,0x732e74736e6f632eull,0x3837722509203233ull,0x6d6f635f645b202cull,
0x5d3434322b6e6f6dull,0x2e70746573090a3bull,0x09203233732e746cull,0x7225202c33317025ull,
0x3b38377225202c35ull,0x6e6f632e646c090aull,0x09203233732e7473ull,0x645b202c39377225ull,
0x2b6e6f6d6d6f635full,0x40090a3b5d383032ull,0x7262203331702521ull,0x305f744c24092061ull,
0x3b3632323834315full,0x33732e627573090aull,0x2c30387225092032ull,0x25202c3837722520ull,
0x646461090a3b3572ull,0x722509203233732eull,0x30387225202c3138ull,0x090a3b313135202cull,
0x203233732e726873ull,0x25202c3238722509ull,0x3b3133202c313872ull,0x33732e766f6d090aull,
0x2c33387225092032ull,0x61090a3b31313520ull,0x09203233622e646eull,0x7225202c34387225ull,
0x33387225202c3238ull,0x732e646461090a3bull,0x3538722509203233ull,0x202c34387225202cull,
0x73090a3b31387225ull,0x09203233732e7268ull,0x7225202c36387225ull,0x090a3b39202c3538ull,
0x2e3436752e747663ull,0x6472250920323373ull,0x3b357225202c3435ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c383364ull,0x090a3b34202c3435ull,0x74736e6f632e646cull,
0x722509203436752eull,0x72255b202c353564ull,0x0a3b5d36352b3464ull,0x3436752e64646109ull,
0x2c36356472250920ull,0x202c353564722520ull,0x090a3b3833647225ull,0x74736e6f632e646cull,
0x722509203233732eull,0x635f645b202c3738ull,0x35322b6e6f6d6d6full,0x2e646c090a3b5d36ull,
0x33732e74736e6f63ull,0x2c38387225092032ull,0x6d6d6f635f645b20ull,0x3b5d3633322b6e6full,
0x6e6f632e646c090aull,0x09203233732e7473ull,0x645b202c39387225ull,0x2b6e6f6d6d6f635full,
0x6d090a3b5d343232ull,0x09203233732e766full,0x7225202c30397225ull,0x5f744c240a3b3638ull,
0x3a38333131395f30ull,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,
0x6e202c3632322065ull,0x6420676e69747365ull,0x2c31203a68747065ull,0x74616d6974736520ull,
0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,0x09323309636f6c2eull,
0x61090a3009303332ull,0x09203233732e6464ull,0x7225202c35327225ull,0x090a3b31202c3331ull,
0x203233732e6d6572ull,0x25202c3139722509ull,0x387225202c353272ull,0x2e766f6d090a3b38ull,
0x3972250920323373ull,0x3b31397225202c32ull,0x3309636f6c2e090aull,0x0a30093133320932ull,
0x3233732e76696409ull,0x202c333972250920ull,0x7225202c35327225ull,0x646461090a3b3838ull,
0x722509203233732eull,0x33397225202c3439ull,0x6f6d090a3b31202cull,0x2509203233752e76ull,
0x0a3b30202c353972ull,0x656e2e7074657309ull,0x702509203233732eull,0x31397225202c3431ull,
0x0a3b35397225202cull,0x6220343170254009ull,0x5f744c2409206172ull,0x3b34393331395f30ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3632322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a38333131395f30ull,
0x323309636f6c2e09ull,0x090a300933333209ull,0x203233732e766f6dull,0x25202c3239722509ull,
0x6c2e090a3b383872ull,0x333209323309636full,0x766f6d090a300934ull,0x722509203233732eull,
0x33397225202c3439ull,0x5f305f744c240a3bull,0x200a3a3439333139ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363232ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x2e090a3833313139ull,0x3209323309636f6cull,
0x6461090a30093137ull,0x2509203233732e64ull,0x397225202c363972ull,0x3b37387225202c34ull,
0x33732e646461090aull,0x2c37397225092032ull,0x31202c3639722520ull,0x732e627573090a3bull,
0x3839722509203233ull,0x202c36397225202cull,0x73090a3b39387225ull,0x732e74672e707465ull,
0x3531702509203233ull,0x202c37397225202cull,0x61090a3b39387225ull,0x09203233732e6464ull,
0x7225202c39397225ull,0x090a3b31202c3839ull,0x203233732e766f6dull,0x202c303031722509ull,
0x706c6573090a3b31ull,0x722509203233732eull,0x397225202c313031ull,0x3030317225202c39ull,
0x0a3b35317025202cull,0x3233732e766f6d09ull,0x2c32303172250920ull,0x0a3b313031722520ull,
0x74672e7074657309ull,0x702509203233732eull,0x36397225202c3631ull,0x0a3b39377225202cull,
0x33732e706c657309ull,0x3330317225092032ull,0x202c39377225202cull,0x7025202c36397225ull,
0x746573090a3b3631ull,0x3233732e746c2e70ull,0x202c373170250920ull,0x25202c3330317225ull,
0x6d090a3b31303172ull,0x09203233662e766full,0x306630202c346625ull,0x3b30303030303030ull,
0x2f2f092020202020ull,0x31702540090a3020ull,0x2409206172622037ull,0x3834315f305f744cull,
0x2f2f200a3b323834ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x323220656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,0x31395f305f744c24ull,
0x2e646c090a383331ull,0x33732e74736e6f63ull,0x3430317225092032ull,0x6d6f635f645b202cull,
0x5d3235322b6e6f6dull,0x732e646461090a3bull,0x3031722509203233ull,0x3430317225202c35ull,
0x0a3b32397225202cull,0x3233732e64646109ull,0x2c36303172250920ull,0x202c353031722520ull,
0x632e646c090a3b31ull,0x3233732e74736e6full,0x202c333272250920ull,0x6f6d6d6f635f645bull,
0x0a3b5d3430322b6eull,0x74672e7074657309ull,0x702509203233732eull,0x30317225202c3831ull,
0x3b33327225202c35ull,0x732e706c6573090aull,0x3031722509203233ull,0x2c33327225202c37ull,
0x202c353031722520ull,0x73090a3b38317025ull,0x09203233732e6275ull,0x25202c3830317225ull,
0x7225202c33303172ull,0x6461090a3b313031ull,0x2509203233732e64ull,0x7225202c39303172ull,
0x0a3b31202c383031ull,0x736e6f632e646c09ull,0x2509203233732e74ull,0x5f645b202c343572ull,
0x322b6e6f6d6d6f63ull,0x7573090a3b5d3032ull,0x2509203233732e62ull,0x7225202c30313172ull,
0x357225202c353031ull,0x70746573090a3b34ull,0x203233732e74672eull,0x25202c3931702509ull,
0x7225202c36303172ull,0x646461090a3b3435ull,0x722509203233732eull,0x317225202c313131ull,
0x090a3b31202c3031ull,0x203233732e646461ull,0x202c323131722509ull,0x31202c3330317225ull,
0x732e766f6d090a3bull,0x3131722509203233ull,0x73090a3b31202c33ull,0x203233732e706c65ull,
0x202c343131722509ull,0x25202c3131317225ull,0x7025202c33313172ull,0x746573090a3b3931ull,
0x3233732e65672e70ull,0x202c303270250920ull,0x25202c3730317225ull,0x2f200a3b34313172ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3632ull,0x64656c6562616c20ull,0x395f305f744c2420ull,0x6f6d090a38333131ull,
0x2509203233732e76ull,0x7225202c35313172ull,0x744c240a3b393031ull,0x38313432395f305full,
0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,0x202c31373220656eull,
0x20676e697473656eull,0x32203a6874706564ull,0x616d69747365202cull,0x7265746920646574ull,
0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,0x2030327025214009ull,0x744c240920617262ull,
0x34373632395f305full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c31373220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x38313432395f305full,0x33732e627573090aull,0x3631317225092032ull,0x2c3730317225202cull,
0x0a3b343131722520ull,0x3233732e64646109ull,0x2c37313172250920ull,0x202c363131722520ull,
0x2e6c756d090a3b31ull,0x09203233732e6f6cull,0x25202c3831317225ull,0x357225202c343972ull,
0x2e6c756d090a3b34ull,0x09203233732e6f6cull,0x25202c3931317225ull,0x357225202c373872ull,
0x2e6c756d090a3b34ull,0x09203233732e6f6cull,0x25202c3032317225ull,0x7225202c32303172ull,
0x6c756d090a3b3435ull,0x203233732e6f6c2eull,0x202c313231722509ull,0x25202c3230317225ull,
0x656e090a3b333272ull,0x2509203233732e67ull,0x7225202c32323172ull,0x627573090a3b3332ull,
0x722509203233732eull,0x317225202c333231ull,0x31317225202c3530ull,0x2e646461090a3b34ull,
0x3172250920323373ull,0x31317225202c3432ull,0x3931317225202c38ull,0x732e627573090a3bull,
0x3231722509203233ull,0x3432317225202c35ull,0x3b3032317225202cull,0x6e6f632e646c090aull,
0x09203436752e7473ull,0x5b202c3933647225ull,0x5d38342b34647225ull,0x732e646461090a3bull,
0x3231722509203233ull,0x3730317225202c36ull,0x6461090a3b31202cull,0x2509203233732e64ull,
0x7225202c37323172ull,0x317225202c333231ull,0x627573090a3b3532ull,0x722509203233732eull,
0x317225202c383231ull,0x32317225202c3530ull,0x2e646461090a3b36ull,0x3172250920323373ull,
0x32317225202c3932ull,0x3832317225202c35ull,0x732e646461090a3bull,0x3331722509203233ull,
0x3132317225202c30ull,0x3b3232317225202cull,0x33732e646461090aull,0x3133317225092032ull,
0x2c3431317225202cull,0x0a3b303331722520ull,0x3436732e74766309ull,0x722509203233732eull,
0x317225202c373564ull,0x6c756d090a3b3133ull,0x203436752e6f6c2eull,0x202c383564722509ull,
0x34202c3735647225ull,0x752e646461090a3bull,0x3564722509203436ull,0x3734647225202c39ull,
0x3b3835647225202cull,0x36732e747663090aull,0x2509203233732e34ull,0x7225202c30366472ull,
0x756d090a3b373231ull,0x3436752e6f6c2e6cull,0x2c31366472250920ull,0x202c303664722520ull,
0x2e646461090a3b34ull,0x6472250920343675ull,0x33647225202c3236ull,0x3136647225202c39ull,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c31373220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x38313432395f305full,
0x33732e766f6d090aull,0x3233317225092032ull,0x3b3731317225202cull,0x395f305f744c240aull,
0x2f200a3a36383133ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3220656e696c2079ull,
0x7473656e202c3137ull,0x7470656420676e69ull,0x7365202c33203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x3537320932330963ull,
0x672e646c090a3009ull,0x33662e6c61626f6cull,0x202c356625092032ull,0x302b32366472255bull,
0x732e646c090a3b5dull,0x33662e6465726168ull,0x202c366625092032ull,0x2d2b39356472255bull,
0x64616d090a3b5d34ull,0x662509203233662eull,0x202c356625202c34ull,0x346625202c366625ull,
0x752e646461090a3bull,0x3564722509203436ull,0x3935647225202c39ull,0x7573090a3b34202cull,
0x2509203233732e62ull,0x7225202c37323172ull,0x0a3b31202c373231ull,0x3436752e62757309ull,
0x2c32366472250920ull,0x202c323664722520ull,0x70746573090a3b34ull,0x203233732e656e2eull,
0x25202c3132702509ull,0x7225202c37323172ull,0x2540090a3b393231ull,0x2061726220313270ull,
0x395f305f744c2409ull,0x4c240a3b36383133ull,0x373632395f305f74ull,0x6c3c2f2f200a3a34ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c31373220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x313432395f305f74ull,0x732e646461090a38ull,
0x3031722509203233ull,0x3230317225202c32ull,0x6573090a3b31202cull,0x33732e656e2e7074ull,
0x2c32327025092032ull,0x202c323131722520ull,0x090a3b3230317225ull,0x7262203232702540ull,
0x305f744c24092061ull,0x0a3b38313432395full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36323220ull,0x6c6562616c206461ull,
0x305f744c24206465ull,0x090a38333131395full,0x20696e752e617262ull,0x395f305f744c2409ull,
0x4c240a3b36303931ull,0x343834315f305f74ull,0x3c2f2f200a3a3238ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x36323220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3131395f305f744cull,0x305f744c240a3833ull,0x0a3a36303931395full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c36323220ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x090a38333131395full,
0x09323309636f6c2eull,0x73090a3009303832ull,0x6c61626f6c672e74ull,0x255b09203233662eull,
0x2c5d302b36356472ull,0x61090a3b34662520ull,0x09203233732e6464ull,0x7225202c33317225ull,
0x3b323135202c3331ull,0x36752e646461090aull,0x3635647225092034ull,0x2c3635647225202cull,
0x090a3b3834303220ull,0x2e746c2e70746573ull,0x3270250920323373ull,0x2c33317225202c33ull,
0x090a3b3837722520ull,0x7262203332702540ull,0x305f744c24092061ull,0x0a3b38333131395full,
0x696e752e61726209ull,0x5f305f744c240920ull,0x240a3b3632363039ull,0x3834315f305f744cull,
0x744c240a3a363232ull,0x36323630395f305full,0x09636f6c2e090a3aull,0x3009313932093233ull,
0x79732e726162090aull,0x090a3b300920636eull,0x09323309636f6c2eull,0x6d090a3009363033ull,
0x09203233732e766full,0x7225202c33317225ull,0x632e646c090a3b35ull,0x3233732e74736e6full,
0x2c33333172250920ull,0x6d6d6f635f645b20ull,0x3b5d3637322b6e6full,0x6c2e70746573090aull,
0x2509203233732e74ull,0x357225202c343270ull,0x3b3333317225202cull,0x343270252140090aull,
0x4c24092061726220ull,0x313234395f305f74ull,0x2e627573090a3b30ull,0x3172250920323373ull,
0x33317225202c3433ull,0x0a3b357225202c33ull,0x3233732e64646109ull,0x2c35333172250920ull,
0x202c343331722520ull,0x6873090a3b313135ull,0x2509203233732e72ull,0x7225202c36333172ull,
0x3b3133202c353331ull,0x33732e766f6d090aull,0x3733317225092032ull,0x090a3b313135202cull,
0x203233622e646e61ull,0x202c383331722509ull,0x25202c3633317225ull,0x61090a3b37333172ull,
0x09203233732e6464ull,0x25202c3933317225ull,0x7225202c38333172ull,0x6873090a3b353331ull,
0x2509203233732e72ull,0x7225202c30343172ull,0x0a3b39202c393331ull,0x3436752e74766309ull,
0x722509203233732eull,0x357225202c333664ull,0x6f632e646c090a3bull,0x203233732e74736eull,
0x202c313431722509ull,0x6f6d6d6f635f645bull,0x0a3b5d3036322b6eull,0x3233732e62757309ull,
0x2c32343172250920ull,0x202c313431722520ull,0x2e6c756d090a3b31ull,0x09203436752e6f6cull,
0x25202c3833647225ull,0x3b34202c33366472ull,0x6e6f632e646c090aull,0x09203436752e7473ull,
0x5b202c3436647225ull,0x5d32372b34647225ull,0x752e646461090a3bull,0x3664722509203436ull,
0x3436647225202c35ull,0x3b3833647225202cull,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x5b202c3334317225ull,0x6e6f6d6d6f635f64ull,0x090a3b5d3836322bull,0x203233732e766f6dull,
0x202c343431722509ull,0x240a3b3034317225ull,0x3734395f305f744cull,0x3c2f2f200a3a3232ull,
0x6f4c203e706f6f6cull,0x2079646f6220706full,0x36303320656e696cull,0x6e697473656e202cull,
0x3a68747065642067ull,0x69747365202c3120ull,0x746920646574616dull,0x736e6f6974617265ull,
0x776f6e6b6e75203aull,0x09636f6c2e090a6eull,0x3009303133093233ull,0x33732e646461090aull,
0x2c35327225092032ull,0x31202c3331722520ull,0x732e6d6572090a3bull,0x3431722509203233ull,
0x2c35327225202c35ull,0x0a3b333431722520ull,0x3233732e62757309ull,0x202c373272250920ull,
0x31202c3534317225ull,0x09636f6c2e090a3bull,0x3009313133093233ull,0x33732e766964090aull,
0x2c38327225092032ull,0x25202c3532722520ull,0x6d090a3b33343172ull,0x09203233752e766full,
0x30202c3634317225ull,0x2e70746573090a3bull,0x09203233732e656eull,0x7225202c35327025ull,
0x317225202c353431ull,0x702540090a3b3634ull,0x0920617262203532ull,0x34395f305f744c24ull,
0x2f2f200a3b383739ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x303320656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,0x34395f305f744c24ull,
0x6f6c2e090a323237ull,0x3331330932330963ull,0x2e627573090a3009ull,0x3272250920323373ull,
0x3334317225202c37ull,0x6c2e090a3b31202cull,0x313309323309636full,0x627573090a300934ull,
0x722509203233732eull,0x38327225202c3832ull,0x744c240a3b31202cull,0x38373934395f305full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36303320656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x32323734395f305full,
0x3309636f6c2e090aull,0x0a30093831330932ull,0x65672e7074657309ull,0x702509203233732eull,
0x34317225202c3632ull,0x3b37327225202c32ull,0x203632702540090aull,0x744c240920617262ull,
0x36373934315f305full,0x6c3c2f2f200a3b32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c36303320656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x323734395f305f74ull,0x6f632e646c090a32ull,0x203233732e74736eull,0x5b202c3435722509ull,
0x6e6f6d6d6f635f64ull,0x090a3b5d3032322bull,0x203233732e646461ull,0x202c373431722509ull,
0x7225202c34357225ull,0x6573090a3b313431ull,0x33732e65672e7074ull,0x2c37327025092032ull,
0x25202c3732722520ull,0x40090a3b37343172ull,0x6172622037327025ull,0x5f305f744c240920ull,
0x0a3b323637393431ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c36303320ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x090a32323734395full,0x74736e6f632e646cull,0x722509203233732eull,0x5f645b202c383431ull,
0x322b6e6f6d6d6f63ull,0x7573090a3b5d3436ull,0x2509203233732e62ull,0x7225202c39343172ull,
0x0a3b31202c383431ull,0x656c2e7074657309ull,0x702509203233732eull,0x38327225202c3832ull,
0x3b3934317225202cull,0x203832702540090aull,0x744c240920617262ull,0x36373934315f305full,
0x6c3c2f2f200a3b32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c36303320656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x323734395f305f74ull,
0x6f632e646c090a32ull,0x203233732e74736eull,0x202c303531722509ull,0x6f6d6d6f635f645bull,
0x0a3b5d3432322b6eull,0x3233732e64646109ull,0x2c31353172250920ull,0x202c303531722520ull,
0x090a3b3834317225ull,0x2e65672e70746573ull,0x3270250920323373ull,0x2c38327225202c39ull,
0x0a3b313531722520ull,0x6220393270254009ull,0x5f744c2409206172ull,0x3236373934315f30ull,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36303320656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x32323734395f305full,
0x3309636f6c2e090aull,0x0a30093432330932ull,0x736e6f632e646c09ull,0x2509203436752e74ull,
0x255b202c36366472ull,0x3b5d38342b346472ull,0x33732e627573090aull,0x3235317225092032ull,
0x202c38327225202cull,0x090a3b3834317225ull,0x732e6f6c2e6c756dull,0x3531722509203233ull,
0x2c34357225202c33ull,0x0a3b323531722520ull,0x3233732e62757309ull,0x2c34353172250920ull,
0x25202c3732722520ull,0x61090a3b31343172ull,0x09203233732e6464ull,0x25202c3535317225ull,
0x7225202c33353172ull,0x7663090a3b343531ull,0x33732e3436732e74ull,0x3736647225092032ull,
0x3b3535317225202cull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c383664ull,
0x090a3b34202c3736ull,0x203436752e646461ull,0x202c393664722509ull,0x25202c3636647225ull,
0x6c090a3b38366472ull,0x6c61626f6c672e64ull,0x662509203233662eull,0x366472255b202c37ull,
0x73090a3b5d302b39ull,0x6c61626f6c672e74ull,0x255b09203233662eull,0x2c5d302b35366472ull,
0x62090a3b37662520ull,0x0920696e752e6172ull,0x3931385f305f4c24ull,0x5f744c240a3b3232ull,
0x3236373934315f30ull,0x385f305f4c240a3aull,0x2f200a3a38373132ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,0x64616568202c3630ull,
0x64656c6562616c20ull,0x395f305f744c2420ull,0x6c2e090a32323734ull,0x323309323309636full,
0x766f6d090a300937ull,0x662509203233662eull,0x3030306630202c38ull,0x20203b3030303030ull,
0x30202f2f09202020ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b35366472255b09ull,
0x3b386625202c5d30ull,0x31385f305f4c240aull,0x2f2f200a3a323239ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x303320656e696c20ull,0x2064616568202c36ull,
0x2064656c6562616cull,0x34395f305f744c24ull,0x646461090a323237ull,0x722509203233732eull,
0x33317225202c3331ull,0x090a3b323135202cull,0x203436752e646461ull,0x202c353664722509ull,
0x32202c3536647225ull,0x6573090a3b383430ull,0x33732e746c2e7074ull,0x2c30337025092032ull,
0x25202c3331722520ull,0x40090a3b33333172ull,0x6172622030337025ull,0x5f305f744c240920ull,
0x240a3b3232373439ull,0x3234395f305f744cull,0x6f6c2e090a3a3031ull,0x3933330932330963ull,
0x2e726162090a3009ull,0x3b300920636e7973ull,0x3309636f6c2e090aull,0x0a30093634330932ull,
0x3233732e766f6d09ull,0x202c333172250920ull,0x646c090a3b357225ull,0x732e74736e6f632eull,
0x3531722509203233ull,0x6f635f645b202c36ull,0x3237322b6e6f6d6dull,0x70746573090a3b5dull,
0x203233732e746c2eull,0x25202c3133702509ull,0x35317225202c3572ull,0x70252140090a3b36ull,
0x0920617262203133ull,0x35395f305f744c24ull,0x7573090a3b363437ull,0x2509203233732e62ull,
0x7225202c37353172ull,0x357225202c363531ull,0x732e646461090a3bull,0x3531722509203233ull,
0x3735317225202c38ull,0x090a3b313135202cull,0x203233732e726873ull,0x202c393531722509ull,
0x33202c3835317225ull,0x2e766f6d090a3b31ull,0x3172250920323373ull,0x3b313135202c3036ull,
0x33622e646e61090aull,0x3136317225092032ull,0x2c3935317225202cull,0x0a3b303631722520ull,
0x3233732e64646109ull,0x2c32363172250920ull,0x202c313631722520ull,0x090a3b3835317225ull,
0x203233732e726873ull,0x202c333631722509ull,0x39202c3236317225ull,0x6f632e646c090a3bull,
0x203233732e74736eull,0x202c333431722509ull,0x6f6d6d6f635f645bull,0x0a3b5d3836322b6eull,
0x2e6f6c2e6c756d09ull,0x3172250920323373ull,0x2c357225202c3436ull,0x0a3b333431722520ull,
0x2e6f6c2e6c756d09ull,0x3172250920323373ull,0x34317225202c3536ull,0x0a3b323135202c33ull,
0x3233732e766f6d09ull,0x2c36363172250920ull,0x0a3b333631722520ull,0x36395f305f744c24ull,
0x2f2f200a3a383532ull,0x4c203e706f6f6c3cull,0x79646f6220706f6full,0x343320656e696c20ull,
0x697473656e202c36ull,0x687470656420676eull,0x747365202c31203aull,0x6920646574616d69ull,
0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,0x0936353309323309ull,
0x732e766f6d090a30ull,0x3631722509203233ull,0x3436317225202c37ull,0x732e766f6d090a3bull,
0x3631722509203233ull,0x3736317225202c38ull,0x732e646461090a3bull,0x3631722509203233ull,
0x3736317225202c39ull,0x3b3334317225202cull,0x6c2e70746573090aull,0x2509203233732e65ull,
0x317225202c323370ull,0x36317225202c3936ull,0x33702540090a3b37ull,0x2409206172622032ull,
0x3536395f305f744cull,0x3c2f2f200a3b3431ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x36343320656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3236395f305f744cull,0x2e766f6d090a3835ull,0x3172250920323373ull,0x34317225202c3037ull,
0x632e646c090a3b33ull,0x3436752e74736e6full,0x2c34366472250920ull,0x372b346472255b20ull,
0x747663090a3b5d32ull,0x3233732e3436752eull,0x2c30376472250920ull,0x0a3b373631722520ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x37647225202c3137ull,0x61090a3b34202c30ull,
0x09203436752e6464ull,0x25202c3237647225ull,0x7225202c34366472ull,0x6f6d090a3b313764ull,
0x2509203233662e76ull,0x30306630202c3966ull,0x203b303030303030ull,0x202f2f0920202020ull,
0x6f6c3c2f2f200a30ull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36343320656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x38353236395f305full,
0x33732e766f6d090aull,0x3137317225092032ull,0x3b3037317225202cull,0x395f305f744c240aull,
0x2f200a3a36323037ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3320656e696c2079ull,
0x7473656e202c3635ull,0x7470656420676e69ull,0x7365202c32203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x3735330932330963ull,
0x672e646c090a3009ull,0x33662e6c61626f6cull,0x2c30316625092032ull,0x2b32376472255b20ull,
0x646461090a3b5d30ull,0x662509203233662eull,0x30316625202c3131ull,0x090a3b396625202cull,
0x61626f6c672e7473ull,0x5b09203233662e6cull,0x5d302b3237647225ull,0x0a3b31316625202cull,
0x323309636f6c2e09ull,0x090a300938353309ull,0x203233662e766f6dull,0x6625202c39662509ull,
0x646461090a3b3131ull,0x722509203233732eull,0x317225202c383631ull,0x090a3b31202c3836ull,
0x203436752e646461ull,0x202c323764722509ull,0x34202c3237647225ull,0x2e70746573090a3bull,
0x09203233732e656eull,0x7225202c33337025ull,0x317225202c393631ull,0x702540090a3b3836ull,
0x0920617262203333ull,0x37395f305f744c24ull,0x744c240a3b363230ull,0x34313536395f305full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36343320656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x38353236395f305full,
0x33732e646461090aull,0x2c33317225092032ull,0x35202c3331722520ull,0x646461090a3b3231ull,
0x722509203233732eull,0x317225202c343631ull,0x36317225202c3736ull,0x70746573090a3b35ull,
0x203233732e746c2eull,0x25202c3433702509ull,0x317225202c333172ull,0x702540090a3b3635ull,
0x0920617262203433ull,0x36395f305f744c24ull,0x744c240a3b383532ull,0x36343735395f305full,
0x09636f6c2e090a3aull,0x3009303733093233ull,0x79732e726162090aull,0x090a3b300920636eull,
0x09323309636f6c2eull,0x6d090a3009373733ull,0x09203233732e766full,0x7225202c33317225ull,
0x632e646c090a3b35ull,0x3233732e74736e6full,0x2c32373172250920ull,0x6d6d6f635f645b20ull,
0x3b5d3239322b6e6full,0x6c2e70746573090aull,0x2509203233732e74ull,0x357225202c353370ull,
0x3b3237317225202cull,0x353370252140090aull,0x4c24092061726220ull,0x393737395f305f74ull,
0x2e627573090a3b34ull,0x3172250920323373ull,0x37317225202c3337ull,0x0a3b357225202c32ull,
0x3233732e64646109ull,0x2c34373172250920ull,0x202c333731722520ull,0x6873090a3b313135ull,
0x2509203233732e72ull,0x7225202c35373172ull,0x3b3133202c343731ull,0x33732e766f6d090aull,
0x3637317225092032ull,0x090a3b313135202cull,0x203233622e646e61ull,0x202c373731722509ull,
0x25202c3537317225ull,0x61090a3b36373172ull,0x09203233732e6464ull,0x25202c3837317225ull,
0x7225202c37373172ull,0x6873090a3b343731ull,0x2509203233732e72ull,0x7225202c39373172ull,
0x0a3b39202c383731ull,0x3436752e74766309ull,0x722509203233732eull,0x357225202c333764ull,
0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c38336472ull,0x0a3b34202c333764ull,
0x736e6f632e646c09ull,0x2509203436752e74ull,0x255b202c34376472ull,0x3b5d30382b346472ull,
0x6e6f632e646c090aull,0x09203436752e7473ull,0x5b202c3436647225ull,0x5d32372b34647225ull,
0x752e646461090a3bull,0x3764722509203436ull,0x3437647225202c35ull,0x3b3833647225202cull,
0x6e6f632e646c090aull,0x09203233732e7473ull,0x5b202c3038317225ull,0x6e6f6d6d6f635f64ull,
0x090a3b5d3830332bull,0x74736e6f632e646cull,0x722509203233732eull,0x5f645b202c313831ull,
0x332b6e6f6d6d6f63ull,0x646c090a3b5d3030ull,0x732e74736e6f632eull,0x3831722509203233ull,
0x6f635f645b202c32ull,0x3438322b6e6f6d6dull,0x632e646c090a3b5dull,0x3233732e74736e6full,
0x2c33343172250920ull,0x6d6d6f635f645b20ull,0x3b5d3836322b6e6full,0x33732e766f6d090aull,
0x3338317225092032ull,0x3b3937317225202cull,0x395f305f744c240aull,0x2f200a3a36303338ull,
0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3320656e696c2079ull,0x7473656e202c3737ull,
0x7470656420676e69ull,0x7365202c31203a68ull,0x20646574616d6974ull,0x6f69746172657469ull,
0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x3138330932330963ull,0x2e646461090a3009ull,
0x3272250920323373ull,0x2c33317225202c35ull,0x6d6572090a3b3120ull,0x722509203233732eull,
0x327225202c343831ull,0x3238317225202c35ull,0x732e627573090a3bull,0x3732722509203233ull,
0x2c3438317225202cull,0x6f6c2e090a3b3120ull,0x3238330932330963ull,0x2e766964090a3009ull,
0x3272250920323373ull,0x2c35327225202c38ull,0x0a3b323831722520ull,0x3233752e766f6d09ull,
0x2c35383172250920ull,0x746573090a3b3020ull,0x3233732e656e2e70ull,0x202c363370250920ull,
0x25202c3438317225ull,0x40090a3b35383172ull,0x6172622036337025ull,0x5f305f744c240920ull,
0x200a3b3236353839ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c373733ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x2e090a3630333839ull,0x3309323309636f6cull,0x7573090a30093438ull,0x2509203233732e62ull,
0x317225202c373272ull,0x090a3b31202c3238ull,0x09323309636f6c2eull,0x73090a3009353833ull,
0x09203233732e6275ull,0x7225202c38327225ull,0x240a3b31202c3832ull,0x3538395f305f744cull,
0x3c2f2f200a3a3236ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x37373320656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3338395f305f744cull,
0x636f6c2e090a3630ull,0x0931393309323309ull,0x732e646461090a30ull,0x3831722509203233ull,
0x2c37327225202c36ull,0x0a3b313831722520ull,0x3233732e64646109ull,0x2c37383172250920ull,
0x25202c3832722520ull,0x73090a3b30383172ull,0x09203233732e6275ull,0x25202c3838317225ull,
0x3b31202c37383172ull,0x6f6c2e6c756d090aull,0x722509203233732eull,0x317225202c393831ull,
0x38317225202c3334ull,0x2e646461090a3b38ull,0x3172250920323373ull,0x38317225202c3039ull,
0x3938317225202c36ull,0x732e747663090a3bull,0x09203233732e3436ull,0x25202c3637647225ull,
0x6d090a3b30393172ull,0x36752e6f6c2e6c75ull,0x3737647225092034ull,0x2c3637647225202cull,
0x646461090a3b3420ull,0x722509203436752eull,0x647225202c383764ull,0x37647225202c3436ull,
0x672e646c090a3b37ull,0x33662e6c61626f6cull,0x2c32316625092032ull,0x2b38376472255b20ull,
0x7473090a3b5d342dull,0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b353764ull,
0x61090a3b32316625ull,0x09203233732e6464ull,0x7225202c33317225ull,0x3b323135202c3331ull,
0x36752e646461090aull,0x3537647225092034ull,0x2c3537647225202cull,0x090a3b3834303220ull,
0x2e746c2e70746573ull,0x3370250920323373ull,0x2c33317225202c37ull,0x0a3b323731722520ull,
0x6220373370254009ull,0x5f744c2409206172ull,0x3b36303338395f30ull,0x395f305f744c240aull,
0x2e090a3a34393737ull,0x3409323309636f6cull,0x6162090a30093230ull,0x0920636e79732e72ull,
0x636f6c2e090a3b30ull,0x0933313409323309ull,0x732e766f6d090a30ull,0x3331722509203233ull,
0x090a3b357225202cull,0x74736e6f632e646cull,0x722509203233732eull,0x5f645b202c313931ull,
0x332b6e6f6d6d6f63ull,0x6573090a3b5d3034ull,0x33732e746c2e7074ull,0x2c38337025092032ull,
0x7225202c35722520ull,0x646c090a3b313931ull,0x732e74736e6f632eull,0x3931722509203233ull,
0x6f635f645b202c32ull,0x3233332b6e6f6d6dull,0x70252140090a3b5dull,0x0920617262203833ull,
0x35315f305f744c24ull,0x73090a3b32343031ull,0x09203233732e6275ull,0x25202c3339317225ull,
0x7225202c31393172ull,0x2e646461090a3b35ull,0x3172250920323373ull,0x39317225202c3439ull,
0x0a3b313135202c33ull,0x3233732e72687309ull,0x2c35393172250920ull,0x202c343931722520ull,
0x766f6d090a3b3133ull,0x722509203233732eull,0x313135202c363931ull,0x622e646e61090a3bull,
0x3931722509203233ull,0x3539317225202c37ull,0x3b3639317225202cull,0x33732e646461090aull,
0x3839317225092032ull,0x2c3739317225202cull,0x0a3b343931722520ull,0x3233732e72687309ull,
0x2c39393172250920ull,0x202c383931722520ull,0x2e747663090a3b39ull,0x203233732e343675ull,
0x202c393764722509ull,0x756d090a3b357225ull,0x3436752e6f6c2e6cull,0x2c38336472250920ull,
0x202c393764722520ull,0x632e646c090a3b34ull,0x3436752e74736e6full,0x2c30386472250920ull,
0x382b346472255b20ull,0x2e646c090a3b5d38ull,0x36752e74736e6f63ull,0x3436647225092034ull,
0x2b346472255b202cull,0x6461090a3b5d3237ull,0x2509203436752e64ull,0x7225202c31386472ull,
0x647225202c303864ull,0x2e646c090a3b3833ull,0x33732e74736e6f63ull,0x3030327225092032ull,
0x6d6f635f645b202cull,0x5d3432332b6e6f6dull,0x6f632e646c090a3bull,0x203233732e74736eull,
0x202c333431722509ull,0x6f6d6d6f635f645bull,0x0a3b5d3836322b6eull,0x736e6f632e646c09ull,
0x2509203233732e74ull,0x645b202c31303272ull,0x2b6e6f6d6d6f635full,0x6d090a3b5d363133ull,
0x09203233732e766full,0x25202c3230327225ull,0x4c240a3b39393172ull,0x343839395f305f74ull,
0x6c3c2f2f200a3a32ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,0x2c33313420656e69ull,
0x676e697473656e20ull,0x203a687470656420ull,0x6d69747365202c31ull,0x6574692064657461ull,
0x3a736e6f69746172ull,0x6e776f6e6b6e7520ull,0x3309636f6c2e090aull,0x0a30093731340932ull,
0x3233732e64646109ull,0x202c353272250920ull,0x3b31202c33317225ull,0x33732e6d6572090aull,
0x3330327225092032ull,0x202c35327225202cull,0x090a3b3239317225ull,0x203233732e627573ull,
0x25202c3732722509ull,0x3b31202c33303272ull,0x3309636f6c2e090aull,0x0a30093831340932ull,
0x3233732e76696409ull,0x202c383272250920ull,0x7225202c35327225ull,0x6f6d090a3b323931ull,
0x2509203233752e76ull,0x3b30202c34303272ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x327225202c393370ull,0x30327225202c3330ull,0x33702540090a3b34ull,0x2409206172622039ull,
0x3030315f305f744cull,0x2f2f200a3b383930ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x313420656e696c20ull,0x2064616568202c33ull,0x2064656c6562616cull,
0x39395f305f744c24ull,0x6f6c2e090a323438ull,0x3032340932330963ull,0x2e627573090a3009ull,
0x3272250920323373ull,0x3239317225202c37ull,0x6c2e090a3b31202cull,0x323409323309636full,
0x627573090a300931ull,0x722509203233732eull,0x38327225202c3832ull,0x744c240a3b31202cull,
0x39303030315f305full,0x6c3c2f2f200a3a38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c33313420656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x343839395f305f74ull,0x09636f6c2e090a32ull,0x3009373234093233ull,0x33732e646461090aull,
0x3530327225092032ull,0x202c37327225202cull,0x090a3b3130327225ull,0x203233732e646461ull,
0x202c363032722509ull,0x7225202c38327225ull,0x7573090a3b303032ull,0x2509203233732e62ull,
0x7225202c37303272ull,0x0a3b31202c363032ull,0x2e6f6c2e6c756d09ull,0x3272250920323373ull,
0x34317225202c3830ull,0x3730327225202c33ull,0x732e646461090a3bull,0x3032722509203233ull,
0x3530327225202c39ull,0x3b3830327225202cull,0x36732e747663090aull,0x2509203233732e34ull,
0x7225202c32386472ull,0x756d090a3b393032ull,0x3436752e6f6c2e6cull,0x2c33386472250920ull,
0x202c323864722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x36647225202c3438ull,
0x3338647225202c34ull,0x6c672e646c090a3bull,0x3233662e6c61626full,0x202c333166250920ull,
0x2d2b34386472255bull,0x2e7473090a3b5d34ull,0x662e6c61626f6c67ull,0x6472255b09203233ull,
0x25202c5d302b3138ull,0x6461090a3b333166ull,0x2509203233732e64ull,0x317225202c333172ull,
0x0a3b323135202c33ull,0x3436752e64646109ull,0x2c31386472250920ull,0x202c313864722520ull,
0x73090a3b38343032ull,0x732e746c2e707465ull,0x3034702509203233ull,0x202c33317225202cull,
0x090a3b3139317225ull,0x7262203034702540ull,0x305f744c24092061ull,0x0a3b32343839395full,
0x696e752e61726209ull,0x5f305f744c240920ull,0x240a3b3033333939ull,0x3135315f305f744cull,
0x744c240a3a323430ull,0x30333339395f305full,0x09636f6c2e090a3aull,0x3009383334093233ull,
0x79732e726162090aull,0x090a3b300920636eull,0x09323309636f6c2eull,0x6d090a3009353434ull,
0x09203233732e766full,0x7225202c33317225ull,0x70252140090a3b35ull,0x0920617262203833ull,
0x30315f305f744c24ull,0x73090a3b36363830ull,0x09203233732e6275ull,0x25202c3031327225ull,
0x7225202c31393172ull,0x2e646461090a3b35ull,0x3272250920323373ull,0x31327225202c3131ull,
0x0a3b313135202c30ull,0x3233732e72687309ull,0x2c32313272250920ull,0x202c313132722520ull,
0x766f6d090a3b3133ull,0x722509203233732eull,0x313135202c333132ull,0x622e646e61090a3bull,
0x3132722509203233ull,0x3231327225202c34ull,0x3b3331327225202cull,0x33732e646461090aull,
0x3531327225092032ull,0x2c3431327225202cull,0x0a3b313132722520ull,0x3233732e72687309ull,
0x2c36313272250920ull,0x202c353132722520ull,0x2e747663090a3b39ull,0x203233732e343675ull,
0x202c353864722509ull,0x756d090a3b357225ull,0x3436752e6f6c2e6cull,0x2c38336472250920ull,
0x202c353864722520ull,0x632e646c090a3b34ull,0x3436752e74736e6full,0x2c30386472250920ull,
0x382b346472255b20ull,0x2e646c090a3b5d38ull,0x36752e74736e6f63ull,0x3437647225092034ull,
0x2b346472255b202cull,0x6461090a3b5d3038ull,0x2509203436752e64ull,0x7225202c31386472ull,
0x647225202c303864ull,0x646461090a3b3833ull,0x722509203436752eull,0x647225202c353764ull,
0x33647225202c3437ull,0x2e766f6d090a3b38ull,0x3272250920323373ull,0x31327225202c3731ull,
0x305f744c240a3b36ull,0x3a3837333130315full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,
0x6e696c2079646f62ull,0x6e202c3534342065ull,0x6420676e69747365ull,0x2c31203a68747065ull,
0x74616d6974736520ull,0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,
0x09323309636f6c2eull,0x6c090a3009393434ull,0x6c61626f6c672e64ull,0x662509203233662eull,
0x6472255b202c3431ull,0x090a3b5d302b3537ull,0x61626f6c672e646cull,0x2509203233662e6cull,
0x72255b202c353166ull,0x0a3b5d302b313864ull,0x3233662e62757309ull,0x202c363166250920ull,
0x6625202c34316625ull,0x2e7473090a3b3531ull,0x662e6c61626f6c67ull,0x6472255b09203233ull,
0x25202c5d302b3138ull,0x6461090a3b363166ull,0x2509203233732e64ull,0x317225202c333172ull,
0x0a3b323135202c33ull,0x3436752e64646109ull,0x2c35376472250920ull,0x202c353764722520ull,
0x61090a3b38343032ull,0x09203436752e6464ull,0x25202c3138647225ull,0x3032202c31386472ull,
0x746573090a3b3834ull,0x3233732e746c2e70ull,0x202c313470250920ull,0x7225202c33317225ull,
0x2540090a3b313931ull,0x2061726220313470ull,0x315f305f744c2409ull,0x240a3b3837333130ull,
0x3030315f305f744cull,0x6c2e090a3a363638ull,0x363409323309636full,0x726162090a300930ull,
0x300920636e79732eull,0x09636f6c2e090a3bull,0x3009373634093233ull,0x33732e766f6d090aull,
0x2c33317225092032ull,0x73090a3b35722520ull,0x732e746c2e707465ull,0x3234702509203233ull,
0x25202c357225202cull,0x40090a3b32393172ull,0x7262203234702521ull,0x305f744c24092061ull,
0x3b3039383130315full,0x33732e627573090aull,0x3831327225092032ull,0x2c3239317225202cull,
0x61090a3b35722520ull,0x09203233732e6464ull,0x25202c3931327225ull,0x3135202c38313272ull,
0x2e726873090a3b31ull,0x3272250920323373ull,0x31327225202c3032ull,0x090a3b3133202c39ull,
0x203233732e766f6dull,0x202c313232722509ull,0x6e61090a3b313135ull,0x2509203233622e64ull,
0x7225202c32323272ull,0x327225202c303232ull,0x646461090a3b3132ull,0x722509203233732eull,
0x327225202c333232ull,0x31327225202c3232ull,0x2e726873090a3b39ull,0x3272250920323373ull,
0x32327225202c3432ull,0x6d090a3b39202c33ull,0x09203233732e766full,0x25202c3532327225ull,
0x4c240a3b34323272ull,0x343230315f305f74ull,0x3c2f2f200a3a3230ull,0x6f4c203e706f6f6cull,
0x2079646f6220706full,0x37363420656e696cull,0x6e697473656e202cull,0x3a68747065642067ull,
0x69747365202c3120ull,0x746920646574616dull,0x736e6f6974617265ull,0x776f6e6b6e75203aull,
0x09636f6c2e090a6eull,0x3009373734093233ull,0x33732e766f6d090aull,0x3836317225092032ull,
0x0a3b33317225202cull,0x3233732e64646109ull,0x2c36323272250920ull,0x25202c3331722520ull,
0x73090a3b31393172ull,0x732e656c2e707465ull,0x3334702509203233ull,0x2c3632327225202cull,
0x090a3b3331722520ull,0x7262203334702540ull,0x305f744c24092061ull,0x3b3835363230315full,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3736342065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x3230343230315f30ull,
0x36732e747663090aull,0x2509203233732e34ull,0x7225202c36386472ull,0x756d090a3b323931ull,
0x3436752e6f6c2e6cull,0x2c37386472250920ull,0x202c363864722520ull,0x632e646c090a3b34ull,
0x3436752e74736e6full,0x2c30386472250920ull,0x382b346472255b20ull,0x747663090a3b5d38ull,
0x3233732e3436752eull,0x2c38386472250920ull,0x090a3b3331722520ull,0x752e6f6c2e6c756dull,
0x3864722509203436ull,0x3838647225202c39ull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x7225202c30396472ull,0x647225202c303864ull,0x766f6d090a3b3938ull,0x662509203233662eull,
0x3030306630202c39ull,0x20203b3030303030ull,0x30202f2f09202020ull,0x315f305f744c240aull,
0x200a3a3037313330ull,0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,
0x73656e202c373734ull,0x70656420676e6974ull,0x65202c32203a6874ull,0x646574616d697473ull,
0x6974617265746920ull,0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,0x373409323309636full,
0x2e646c090a300938ull,0x662e6c61626f6c67ull,0x3731662509203233ull,0x30396472255b202cull,
0x6461090a3b5d302bull,0x2509203233662e64ull,0x316625202c383166ull,0x0a3b396625202c37ull,
0x626f6c672e747309ull,0x09203233662e6c61ull,0x302b30396472255bull,0x3b38316625202c5dull,
0x3309636f6c2e090aull,0x0a30093937340932ull,0x3233662e766f6d09ull,0x25202c3966250920ull,
0x6461090a3b383166ull,0x2509203233732e64ull,0x7225202c38363172ull,0x317225202c383631ull,
0x646461090a3b3239ull,0x722509203436752eull,0x647225202c303964ull,0x38647225202c3039ull,
0x70746573090a3b37ull,0x203233732e74672eull,0x25202c3434702509ull,0x7225202c36323272ull,
0x2540090a3b383631ull,0x2061726220343470ull,0x315f305f744c2409ull,0x240a3b3037313330ull,
0x3230315f305f744cull,0x2f2f200a3a383536ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363420656e696c20ull,0x2064616568202c37ull,0x2064656c6562616cull,
0x30315f305f744c24ull,0x6461090a32303432ull,0x2509203233732e64ull,0x317225202c333172ull,
0x0a3b323135202c33ull,0x746c2e7074657309ull,0x702509203233732eull,0x33317225202c3534ull,
0x3b3239317225202cull,0x203534702540090aull,0x744c240920617262ull,0x30343230315f305full,
0x305f744c240a3b32ull,0x3a3039383130315full,0x3309636f6c2e090aull,0x0a30093139340932ull,
0x6e79732e72616209ull,0x2e090a3b30092063ull,0x3409323309636f6cull,0x6f6d090a30093839ull,
0x2509203233732e76ull,0x357225202c333172ull,0x6f632e646c090a3bull,0x203233732e74736eull,
0x202c373232722509ull,0x6f6d6d6f635f645bull,0x0a3b5d3635332b6eull,0x746c2e7074657309ull,
0x702509203233732eull,0x2c357225202c3634ull,0x0a3b373232722520ull,0x2036347025214009ull,
0x744c240920617262ull,0x33393330315f305full,0x2e627573090a3b38ull,0x3272250920323373ull,
0x32327225202c3832ull,0x0a3b357225202c37ull,0x3233732e64646109ull,0x2c39323272250920ull,
0x202c383232722520ull,0x6873090a3b313135ull,0x2509203233732e72ull,0x7225202c30333272ull,
0x3b3133202c393232ull,0x33732e766f6d090aull,0x3133327225092032ull,0x090a3b313135202cull,
0x203233622e646e61ull,0x202c323332722509ull,0x25202c3033327225ull,0x61090a3b31333272ull,
0x09203233732e6464ull,0x25202c3333327225ull,0x7225202c32333272ull,0x6873090a3b393232ull,
0x2509203233732e72ull,0x7225202c34333272ull,0x0a3b39202c333332ull,0x3436752e74766309ull,
0x722509203233732eull,0x357225202c313964ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x7225202c38336472ull,0x0a3b34202c313964ull,0x736e6f632e646c09ull,0x2509203436752e74ull,
0x255b202c32396472ull,0x3b5d36392b346472ull,0x6e6f632e646c090aull,0x09203436752e7473ull,
0x5b202c3038647225ull,0x5d38382b34647225ull,0x752e646461090a3bull,0x3964722509203436ull,
0x3239647225202c33ull,0x3b3833647225202cull,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x5b202c3533327225ull,0x6e6f6d6d6f635f64ull,0x090a3b5d3237332bull,0x74736e6f632e646cull,
0x722509203233732eull,0x5f645b202c363332ull,0x332b6e6f6d6d6f63ull,0x646c090a3b5d3436ull,
0x732e74736e6f632eull,0x3332722509203233ull,0x6f635f645b202c37ull,0x3834332b6e6f6d6dull,
0x2e766f6d090a3b5dull,0x3272250920323373ull,0x33327225202c3833ull,0x305f744c240a3b34ull,
0x3a3035343430315full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,
0x6e202c3839342065ull,0x6420676e69747365ull,0x2c31203a68747065ull,0x74616d6974736520ull,
0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,0x09323309636f6c2eull,
0x61090a3009323035ull,0x09203233732e6464ull,0x7225202c35327225ull,0x090a3b31202c3331ull,
0x203233732e6d6572ull,0x202c393332722509ull,0x7225202c35327225ull,0x7573090a3b373332ull,
0x2509203233732e62ull,0x327225202c373272ull,0x090a3b31202c3933ull,0x09323309636f6c2eull,
0x64090a3009333035ull,0x09203233732e7669ull,0x7225202c38327225ull,0x33327225202c3532ull,
0x2e766f6d090a3b37ull,0x3272250920323375ull,0x090a3b30202c3034ull,0x2e656e2e70746573ull,
0x3470250920323373ull,0x3933327225202c37ull,0x3b3034327225202cull,0x203734702540090aull,
0x744c240920617262ull,0x30373430315f305full,0x6c3c2f2f200a3b36ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c38393420656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x343430315f305f74ull,0x636f6c2e090a3035ull,0x0935303509323309ull,
0x732e627573090a30ull,0x3732722509203233ull,0x2c3733327225202cull,0x6f6c2e090a3b3120ull,
0x3630350932330963ull,0x2e627573090a3009ull,0x3272250920323373ull,0x2c38327225202c38ull,
0x5f744c240a3b3120ull,0x3630373430315f30ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c38393420656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x35343430315f305full,0x09636f6c2e090a30ull,0x3009323135093233ull,
0x33732e646461090aull,0x3134327225092032ull,0x202c37327225202cull,0x090a3b3633327225ull,
0x203233732e646461ull,0x202c323432722509ull,0x7225202c38327225ull,0x7573090a3b353332ull,
0x2509203233732e62ull,0x7225202c33343272ull,0x0a3b31202c323432ull,0x2e6f6c2e6c756d09ull,
0x3272250920323373ull,0x39317225202c3434ull,0x3334327225202c32ull,0x732e646461090a3bull,
0x3432722509203233ull,0x3134327225202c35ull,0x3b3434327225202cull,0x36732e747663090aull,
0x2509203233732e34ull,0x7225202c34396472ull,0x756d090a3b353432ull,0x3436752e6f6c2e6cull,
0x2c35396472250920ull,0x202c343964722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x38647225202c3639ull,0x3539647225202c30ull,0x6c672e646c090a3bull,0x3233662e6c61626full,
0x202c393166250920ull,0x2d2b36396472255bull,0x2e7473090a3b5d34ull,0x662e6c61626f6c67ull,
0x6472255b09203233ull,0x25202c5d302b3339ull,0x6461090a3b393166ull,0x2509203233732e64ull,
0x317225202c333172ull,0x0a3b323135202c33ull,0x3436752e64646109ull,0x2c33396472250920ull,
0x202c333964722520ull,0x73090a3b38343032ull,0x732e746c2e707465ull,0x3834702509203233ull,
0x202c33317225202cull,0x090a3b3732327225ull,0x7262203834702540ull,0x305f744c24092061ull,
0x3b3035343430315full,0x315f305f744c240aull,0x090a3a3833393330ull,0x09323309636f6c2eull,
0x62090a3009333235ull,0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x3433350932330963ull,
0x2e766f6d090a3009ull,0x3172250920323373ull,0x0a3b357225202c33ull,0x736e6f632e646c09ull,
0x2509203233732e74ull,0x645b202c36343272ull,0x2b6e6f6d6d6f635full,0x73090a3b5d343034ull,
0x732e746c2e707465ull,0x3934702509203233ull,0x25202c357225202cull,0x40090a3b36343272ull,
0x7262203934702521ull,0x305f744c24092061ull,0x3b3437343530315full,0x33732e627573090aull,
0x3734327225092032ull,0x2c3634327225202cull,0x61090a3b35722520ull,0x09203233732e6464ull,
0x25202c3834327225ull,0x3135202c37343272ull,0x2e726873090a3b31ull,0x3272250920323373ull,
0x34327225202c3934ull,0x090a3b3133202c38ull,0x203233732e766f6dull,0x202c303532722509ull,
0x6e61090a3b313135ull,0x2509203233622e64ull,0x7225202c31353272ull,0x327225202c393432ull,
0x646461090a3b3035ull,0x722509203233732eull,0x327225202c323532ull,0x34327225202c3135ull,
0x2e726873090a3b38ull,0x3272250920323373ull,0x35327225202c3335ull,0x63090a3b39202c32ull,
0x732e3436752e7476ull,0x3964722509203233ull,0x0a3b357225202c37ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x39647225202c3833ull,0x6c090a3b34202c37ull,0x2e74736e6f632e64ull,
0x6472250920343675ull,0x6472255b202c3839ull,0x0a3b5d3430312b34ull,0x736e6f632e646c09ull,
0x2509203436752e74ull,0x255b202c30386472ull,0x3b5d38382b346472ull,0x36752e646461090aull,
0x3939647225092034ull,0x2c3839647225202cull,0x0a3b383364722520ull,0x736e6f632e646c09ull,
0x2509203233732e74ull,0x645b202c34353272ull,0x2b6e6f6d6d6f635full,0x6c090a3b5d383833ull,
0x2e74736e6f632e64ull,0x3272250920323373ull,0x635f645b202c3535ull,0x38332b6e6f6d6d6full,
0x2e646c090a3b5d30ull,0x33732e74736e6f63ull,0x3635327225092032ull,0x6d6f635f645b202cull,
0x5d3639332b6e6f6dull,0x732e766f6d090a3bull,0x3532722509203233ull,0x3335327225202c37ull,
0x5f305f744c240a3bull,0x0a3a363839353031ull,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,
0x656e696c2079646full,0x656e202c34333520ull,0x656420676e697473ull,0x202c31203a687470ull,
0x6574616d69747365ull,0x7461726574692064ull,0x6e75203a736e6f69ull,0x2e090a6e776f6e6bull,
0x3509323309636f6cull,0x6461090a30093833ull,0x2509203233732e64ull,0x317225202c353272ull,
0x72090a3b31202c33ull,0x09203233732e6d65ull,0x25202c3835327225ull,0x327225202c353272ull,
0x627573090a3b3635ull,0x722509203233732eull,0x35327225202c3732ull,0x2e090a3b31202c38ull,
0x3509323309636f6cull,0x6964090a30093933ull,0x2509203233732e76ull,0x327225202c383272ull,
0x3635327225202c35ull,0x752e766f6d090a3bull,0x3532722509203233ull,0x73090a3b30202c39ull,
0x732e656e2e707465ull,0x3035702509203233ull,0x2c3835327225202cull,0x0a3b393532722520ull,
0x6220303570254009ull,0x5f744c2409206172ull,0x3234323630315f30ull,0x6f6c3c2f2f200a3bull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c34333520656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x38393530315f305full,0x09636f6c2e090a36ull,
0x3009313435093233ull,0x33732e627573090aull,0x2c37327225092032ull,0x202c363532722520ull,
0x636f6c2e090a3b31ull,0x0932343509323309ull,0x732e627573090a30ull,0x3832722509203233ull,
0x202c38327225202cull,0x305f744c240a3b31ull,0x3a3234323630315full,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3433352065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x3638393530315f30ull,0x3309636f6c2e090aull,
0x0a30093834350932ull,0x3233732e64646109ull,0x2c30363272250920ull,0x25202c3732722520ull,
0x61090a3b35353272ull,0x09203233732e6464ull,0x25202c3136327225ull,0x327225202c383272ull,
0x627573090a3b3435ull,0x722509203233732eull,0x327225202c323632ull,0x090a3b31202c3136ull,
0x732e6f6c2e6c756dull,0x3632722509203233ull,0x3239317225202c33ull,0x3b3236327225202cull,
0x33732e646461090aull,0x3436327225092032ull,0x2c3036327225202cull,0x0a3b333632722520ull,
0x3436732e74766309ull,0x722509203233732eull,0x7225202c30303164ull,0x756d090a3b343632ull,
0x3436752e6f6c2e6cull,0x3130316472250920ull,0x303031647225202cull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x25202c3230316472ull,0x7225202c30386472ull,0x6c090a3b31303164ull,
0x6c61626f6c672e64ull,0x662509203233662eull,0x6472255b202c3032ull,0x3b5d342d2b323031ull,
0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b39396472255b09ull,0x30326625202c5d30ull,
0x732e646461090a3bull,0x3331722509203233ull,0x202c33317225202cull,0x6461090a3b323135ull,
0x2509203436752e64ull,0x7225202c39396472ull,0x343032202c393964ull,0x70746573090a3b38ull,
0x203233732e746c2eull,0x25202c3135702509ull,0x327225202c333172ull,0x702540090a3b3634ull,
0x0920617262203135ull,0x30315f305f744c24ull,0x4c240a3b36383935ull,0x343530315f305f74ull,
0x6f6c2e090a3a3437ull,0x3935350932330963ull,0x2e726162090a3009ull,0x3b300920636e7973ull,
0x3309636f6c2e090aull,0x0a30093636350932ull,0x3233732e766f6d09ull,0x202c333172250920ull,
0x2140090a3b357225ull,0x6172622039347025ull,0x5f305f744c240920ull,0x0a3b303130373031ull,
0x3233732e62757309ull,0x2c35363272250920ull,0x202c363432722520ull,0x6461090a3b357225ull,
0x2509203233732e64ull,0x7225202c36363272ull,0x313135202c353632ull,0x732e726873090a3bull,
0x3632722509203233ull,0x3636327225202c37ull,0x6d090a3b3133202cull,0x09203233732e766full,
0x35202c3836327225ull,0x646e61090a3b3131ull,0x722509203233622eull,0x327225202c393632ull,
0x36327225202c3736ull,0x2e646461090a3b38ull,0x3272250920323373ull,0x36327225202c3037ull,
0x3636327225202c39ull,0x732e726873090a3bull,0x3732722509203233ull,0x3037327225202c31ull,
0x7663090a3b39202cull,0x33732e3436752e74ull,0x3031647225092032ull,0x0a3b357225202c33ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x31647225202c3833ull,0x090a3b34202c3330ull,
0x74736e6f632e646cull,0x722509203436752eull,0x72255b202c383964ull,0x3b5d3430312b3464ull,
0x6e6f632e646c090aull,0x09203436752e7473ull,0x5b202c3239647225ull,0x5d36392b34647225ull,
0x752e646461090a3bull,0x3964722509203436ull,0x3839647225202c39ull,0x3b3833647225202cull,
0x36752e646461090aull,0x3339647225092034ull,0x2c3239647225202cull,0x0a3b383364722520ull,
0x3233732e766f6d09ull,0x2c32373272250920ull,0x0a3b313732722520ull,0x30315f305f744c24ull,
0x2f200a3a32323537ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3520656e696c2079ull,
0x7473656e202c3636ull,0x7470656420676e69ull,0x7365202c31203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x3037350932330963ull,
0x672e646c090a3009ull,0x33662e6c61626f6cull,0x2c31326625092032ull,0x2b33396472255b20ull,
0x2e646c090a3b5d30ull,0x662e6c61626f6c67ull,0x3232662509203233ull,0x39396472255b202cull,
0x7573090a3b5d302bull,0x2509203233662e62ull,0x326625202c333266ull,0x3b32326625202c31ull,
0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b39396472255b09ull,0x33326625202c5d30ull,
0x732e646461090a3bull,0x3331722509203233ull,0x202c33317225202cull,0x6461090a3b323135ull,
0x2509203436752e64ull,0x7225202c33396472ull,0x343032202c333964ull,0x2e646461090a3b38ull,
0x6472250920343675ull,0x39647225202c3939ull,0x3b38343032202c39ull,0x6c2e70746573090aull,
0x2509203233732e74ull,0x317225202c323570ull,0x3634327225202c33ull,0x3235702540090a3bull,
0x4c24092061726220ull,0x353730315f305f74ull,0x5f744c240a3b3232ull,0x3031303730315f30ull,
0x09636f6c2e090a3aull,0x3009313835093233ull,0x79732e726162090aull,0x090a3b300920636eull,
0x09323309636f6c2eull,0x6d090a3009323935ull,0x09203233732e766full,0x7225202c33317225ull,
0x632e646c090a3b35ull,0x3233732e74736e6full,0x2c33373272250920ull,0x6d6d6f635f645b20ull,
0x3b5d3032342b6e6full,0x672e70746573090aull,0x2509203233732e65ull,0x357225202c333570ull,
0x3b3337327225202cull,0x203335702540090aull,0x744c240920617262ull,0x33303830315f305full,
0x2e627573090a3b34ull,0x3272250920323373ull,0x37327225202c3437ull,0x0a3b357225202c33ull,
0x3233732e64646109ull,0x2c35373272250920ull,0x202c343732722520ull,0x6873090a3b313135ull,
0x2509203233732e72ull,0x7225202c36373272ull,0x3b3133202c353732ull,0x33732e766f6d090aull,
0x3737327225092032ull,0x090a3b313135202cull,0x203233622e646e61ull,0x202c383732722509ull,
0x25202c3637327225ull,0x61090a3b37373272ull,0x09203233732e6464ull,0x25202c3937327225ull,
0x7225202c38373272ull,0x6873090a3b353732ull,0x2509203233732e72ull,0x7225202c30383272ull,
0x0a3b39202c393732ull,0x3436752e74766309ull,0x722509203233732eull,0x7225202c34303164ull,
0x2e6c756d090a3b35ull,0x09203436752e6f6cull,0x25202c3833647225ull,0x34202c3430316472ull,
0x6f632e646c090a3bull,0x203436752e74736eull,0x2c35303164722509ull,0x312b346472255b20ull,
0x646c090a3b5d3231ull,0x752e74736e6f632eull,0x3364722509203436ull,0x346472255b202c39ull,
0x61090a3b5d38342bull,0x09203436752e6464ull,0x202c363031647225ull,0x202c353031647225ull,
0x090a3b3833647225ull,0x203436752e646461ull,0x202c303464722509ull,0x25202c3933647225ull,
0x6d090a3b38336472ull,0x09203233732e766full,0x25202c3138327225ull,0x4c240a3b30383272ull,
0x353830315f305f74ull,0x3c2f2f200a3a3634ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,
0x32393520656e696cull,0x6e697473656e202cull,0x3a68747065642067ull,0x69747365202c3120ull,
0x746920646574616dull,0x736e6f6974617265ull,0x776f6e6b6e75203aull,0x09636f6c2e090a6eull,
0x3009353935093233ull,0x6f6c672e646c090aull,0x203233662e6c6162ull,0x5b202c3432662509ull,
0x5d302b3034647225ull,0x09636f6c2e090a3bull,0x3009363935093233ull,0x33662e6c756d090aull,
0x2c35326625092032ull,0x25202c3432662520ull,0x7473090a3b343266ull,0x2e6c61626f6c672eull,
0x72255b0920323366ull,0x2c5d302b36303164ull,0x090a3b3532662520ull,0x203233732e646461ull,
0x25202c3331722509ull,0x323135202c333172ull,0x752e646461090a3bull,0x3464722509203436ull,
0x3034647225202c30ull,0x0a3b38343032202cull,0x3436752e64646109ull,0x3630316472250920ull,
0x363031647225202cull,0x0a3b38343032202cull,0x746c2e7074657309ull,0x702509203233732eull,
0x33317225202c3435ull,0x3b3337327225202cull,0x203435702540090aull,0x744c240920617262ull,
0x34353830315f305full,0x305f744c240a3b36ull,0x3a3433303830315full,0x3309636f6c2e090aull,
0x0a30093730360932ull,0x6e79732e72616209ull,0x2e090a3b30092063ull,0x3609323309636f6cull,
0x6f6d090a30093831ull,0x2509203233732e76ull,0x357225202c333172ull,0x3270252140090a3bull,
0x2409206172622034ull,0x3930315f305f744cull,0x7573090a3b383530ull,0x2509203233732e62ull,
0x7225202c32383272ull,0x357225202c333331ull,0x732e646461090a3bull,0x3832722509203233ull,
0x3238327225202c33ull,0x090a3b313135202cull,0x203233732e726873ull,0x202c343832722509ull,
0x33202c3338327225ull,0x2e766f6d090a3b31ull,0x3272250920323373ull,0x3b313135202c3538ull,
0x33622e646e61090aull,0x3638327225092032ull,0x2c3438327225202cull,0x0a3b353832722520ull,
0x3233732e64646109ull,0x2c37383272250920ull,0x202c363832722520ull,0x090a3b3338327225ull,
0x203233732e726873ull,0x202c383832722509ull,0x39202c3738327225ull,0x752e747663090a3bull,
0x09203233732e3436ull,0x25202c3336647225ull,0x2e646c090a3b3572ull,0x33732e74736e6f63ull,
0x3134317225092032ull,0x6d6f635f645b202cull,0x5d3036322b6e6f6dull,0x732e627573090a3bull,
0x3431722509203233ull,0x3134317225202c32ull,0x756d090a3b31202cull,0x3436752e6f6c2e6cull,
0x2c38336472250920ull,0x202c333664722520ull,0x632e646c090a3b34ull,0x3436752e74736e6full,
0x2c34366472250920ull,0x372b346472255b20ull,0x646461090a3b5d32ull,0x722509203436752eull,
0x647225202c353664ull,0x33647225202c3436ull,0x632e646c090a3b38ull,0x3233732e74736e6full,
0x2c33343172250920ull,0x6d6d6f635f645b20ull,0x3b5d3836322b6e6full,0x33732e766f6d090aull,
0x3938327225092032ull,0x3b3838327225202cull,0x315f305f744c240aull,0x200a3a3037353930ull,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c383136ull,
0x70656420676e6974ull,0x65202c31203a6874ull,0x646574616d697473ull,0x6974617265746920ull,
0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,0x323609323309636full,0x646461090a300932ull,
0x722509203233732eull,0x33317225202c3532ull,0x6572090a3b31202cull,0x2509203233732e6dull,
0x7225202c30393272ull,0x34317225202c3532ull,0x2e627573090a3b33ull,0x3272250920323373ull,
0x3039327225202c37ull,0x6c2e090a3b31202cull,0x323609323309636full,0x766964090a300933ull,
0x722509203233732eull,0x35327225202c3832ull,0x3b3334317225202cull,0x33752e766f6d090aull,
0x3139327225092032ull,0x6573090a3b30202cull,0x33732e656e2e7074ull,0x2c35357025092032ull,
0x202c303932722520ull,0x090a3b3139327225ull,0x7262203535702540ull,0x305f744c24092061ull,
0x3b3632383930315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3831362065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x3037353930315f30ull,0x3309636f6c2e090aull,0x0a30093532360932ull,0x3233732e62757309ull,
0x202c373272250920ull,0x31202c3334317225ull,0x09636f6c2e090a3bull,0x3009363236093233ull,
0x33732e627573090aull,0x2c38327225092032ull,0x31202c3832722520ull,0x5f305f744c240a3bull,
0x0a3a363238393031ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c38313620ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x0a3037353930315full,0x323309636f6c2e09ull,0x090a300930333609ull,0x2e65672e70746573ull,
0x3570250920323373ull,0x3234317225202c36ull,0x0a3b37327225202cull,0x6220363570254009ull,
0x5f744c2409206172ull,0x3835383335315f30ull,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c38313620656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x37353930315f305full,0x6f632e646c090a30ull,0x203233732e74736eull,
0x202c323932722509ull,0x6f6d6d6f635f645bull,0x0a3b5d3231342b6eull,0x3233732e64646109ull,
0x2c33393272250920ull,0x202c323932722520ull,0x090a3b3134317225ull,0x2e65672e70746573ull,
0x3570250920323373ull,0x2c37327225202c37ull,0x0a3b333932722520ull,0x6220373570254009ull,
0x5f744c2409206172ull,0x3835383335315f30ull,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c38313620656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x37353930315f305full,0x6f632e646c090a30ull,0x203233732e74736eull,
0x202c383431722509ull,0x6f6d6d6f635f645bull,0x0a3b5d3436322b6eull,0x3233732e62757309ull,
0x2c34393272250920ull,0x202c383431722520ull,0x70746573090a3b31ull,0x203233732e656c2eull,
0x25202c3835702509ull,0x327225202c383272ull,0x702540090a3b3439ull,0x0920617262203835ull,
0x35315f305f744c24ull,0x2f200a3b38353833ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3620656e696c2079ull,0x64616568202c3831ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x6c090a3037353930ull,0x2e74736e6f632e64ull,0x3272250920323373ull,
0x635f645b202c3539ull,0x31342b6e6f6d6d6full,0x646461090a3b5d36ull,0x722509203233732eull,
0x327225202c363932ull,0x34317225202c3539ull,0x70746573090a3b38ull,0x203233732e65672eull,
0x25202c3935702509ull,0x327225202c383272ull,0x702540090a3b3639ull,0x0920617262203935ull,
0x35315f305f744c24ull,0x2f200a3b38353833ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3620656e696c2079ull,0x64616568202c3831ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x2e090a3037353930ull,0x3609323309636f6cull,0x646c090a30093633ull,
0x752e74736e6f632eull,0x3164722509203436ull,0x6472255b202c3730ull,0x0a3b5d3231312b34ull,
0x3233732e62757309ull,0x2c37393272250920ull,0x25202c3832722520ull,0x6d090a3b38343172ull,
0x33732e6f6c2e6c75ull,0x3839327225092032ull,0x2c3239327225202cull,0x0a3b373932722520ull,
0x3233732e62757309ull,0x2c39393272250920ull,0x25202c3732722520ull,0x61090a3b31343172ull,
0x09203233732e6464ull,0x25202c3030337225ull,0x7225202c38393272ull,0x7663090a3b393932ull,
0x33732e3436732e74ull,0x3031647225092032ull,0x3030337225202c38ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x25202c3930316472ull,0x34202c3830316472ull,0x752e646461090a3bull,
0x3164722509203436ull,0x31647225202c3031ull,0x31647225202c3730ull,0x2e646c090a3b3930ull,
0x662e6c61626f6c67ull,0x3632662509203233ull,0x31316472255b202cull,0x73090a3b5d302b30ull,
0x6c61626f6c672e74ull,0x255b09203233662eull,0x2c5d302b35366472ull,0x090a3b3632662520ull,
0x20696e752e617262ull,0x33385f305f4c2409ull,0x744c240a3b323032ull,0x35383335315f305full,
0x5f305f4c240a3a38ull,0x200a3a3835343338ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c383136ull,0x656c6562616c2064ull,
0x5f305f744c242064ull,0x090a303735393031ull,0x09323309636f6c2eull,0x6d090a3009393336ull,
0x09203233662e766full,0x6630202c37326625ull,0x3030303030303030ull,0x2f2f09202020203bull,
0x672e7473090a3020ull,0x33662e6c61626f6cull,0x366472255b092032ull,0x6625202c5d302b35ull,
0x305f4c240a3b3732ull,0x0a3a32303233385full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c38313620ull,0x6c6562616c206461ull,
0x305f744c24206465ull,0x0a3037353930315full,0x3233732e64646109ull,0x202c333172250920ull,
0x3135202c33317225ull,0x2e646461090a3b32ull,0x6472250920343675ull,0x36647225202c3536ull,
0x3b38343032202c35ull,0x6c2e70746573090aull,0x2509203233732e74ull,0x317225202c303670ull,
0x3333317225202c33ull,0x3036702540090a3bull,0x4c24092061726220ull,0x353930315f305f74ull,
0x5f744c240a3b3037ull,0x3835303930315f30ull,0x09636f6c2e090a3aull,0x3009313536093233ull,
0x79732e726162090aull,0x090a3b300920636eull,0x09323309636f6c2eull,0x6d090a3009383536ull,
0x09203233732e766full,0x7225202c33317225ull,0x70252140090a3b35ull,0x0920617262203133ull,
0x31315f305f744c24ull,0x73090a3b34393530ull,0x09203233732e6275ull,0x25202c3130337225ull,
0x7225202c36353172ull,0x2e646461090a3b35ull,0x3372250920323373ull,0x30337225202c3230ull,
0x0a3b313135202c31ull,0x3233732e72687309ull,0x2c33303372250920ull,0x202c323033722520ull,
0x766f6d090a3b3133ull,0x722509203233732eull,0x313135202c343033ull,0x622e646e61090a3bull,
0x3033722509203233ull,0x3330337225202c35ull,0x3b3430337225202cull,0x33732e646461090aull,
0x3630337225092032ull,0x2c3530337225202cull,0x0a3b323033722520ull,0x3233732e72687309ull,
0x2c37303372250920ull,0x202c363033722520ull,0x632e646c090a3b39ull,0x3233732e74736e6full,
0x2c33343172250920ull,0x6d6d6f635f645b20ull,0x3b5d3836322b6e6full,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x357225202c343631ull,0x3b3334317225202cull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x317225202c353631ull,0x3b323135202c3334ull,0x33732e766f6d090aull,
0x3830337225092032ull,0x3b3730337225202cull,0x315f305f744c240aull,0x200a3a3630313131ull,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c383536ull,
0x70656420676e6974ull,0x65202c31203a6874ull,0x646574616d697473ull,0x6974617265746920ull,
0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,0x363609323309636full,0x766f6d090a300938ull,
0x722509203233732eull,0x317225202c393033ull,0x766f6d090a3b3436ull,0x722509203233732eull,
0x337225202c383631ull,0x646461090a3b3930ull,0x722509203233732eull,0x337225202c393631ull,
0x34317225202c3930ull,0x70746573090a3b33ull,0x203233732e656c2eull,0x25202c3136702509ull,
0x7225202c39363172ull,0x2540090a3b393033ull,0x2061726220313670ull,0x315f305f744c2409ull,
0x200a3b3236333131ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c383536ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x090a363031313131ull,0x203233732e766f6dull,0x202c303133722509ull,0x090a3b3334317225ull,
0x74736e6f632e646cull,0x722509203436752eull,0x72255b202c343664ull,0x0a3b5d32372b3464ull,
0x3436752e74766309ull,0x722509203233732eull,0x7225202c31313164ull,0x756d090a3b393033ull,
0x3436752e6f6c2e6cull,0x3231316472250920ull,0x313131647225202cull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x7225202c32376472ull,0x647225202c343664ull,0x6f6d090a3b323131ull,
0x2509203233662e76ull,0x30306630202c3966ull,0x203b303030303030ull,0x202f2f0920202020ull,
0x6f6c3c2f2f200a30ull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c38353620656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x30313131315f305full,
0x732e766f6d090a36ull,0x3133722509203233ull,0x3031337225202c31ull,0x5f305f744c240a3bull,
0x0a3a343738313131ull,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x656e202c38363620ull,0x656420676e697473ull,0x202c32203a687470ull,0x6574616d69747365ull,
0x7461726574692064ull,0x6e75203a736e6f69ull,0x2e090a6e776f6e6bull,0x3609323309636f6cull,
0x646c090a30093936ull,0x2e6c61626f6c672eull,0x3266250920323366ull,0x376472255b202c38ull,
0x61090a3b5d302b32ull,0x09203233662e6464ull,0x6625202c39326625ull,0x3b396625202c3832ull,
0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b32376472255b09ull,0x39326625202c5d30ull,
0x09636f6c2e090a3bull,0x3009303736093233ull,0x33662e766f6d090aull,0x202c396625092032ull,
0x61090a3b39326625ull,0x09203233732e6464ull,0x25202c3836317225ull,0x3b31202c38363172ull,
0x36752e646461090aull,0x3237647225092034ull,0x2c3237647225202cull,0x746573090a3b3420ull,
0x3233732e656e2e70ull,0x202c323670250920ull,0x25202c3936317225ull,0x40090a3b38363172ull,
0x6172622032367025ull,0x5f305f744c240920ull,0x0a3b343738313131ull,0x31315f305f744c24ull,
0x2f200a3a32363331ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3620656e696c2079ull,0x64616568202c3835ull,0x64656c6562616c20ull,0x315f305f744c2420ull,
0x61090a3630313131ull,0x09203233732e6464ull,0x7225202c33317225ull,0x3b323135202c3331ull,
0x33732e646461090aull,0x3436317225092032ull,0x2c3930337225202cull,0x0a3b353631722520ull,
0x746c2e7074657309ull,0x702509203233732eull,0x33317225202c3336ull,0x3b3635317225202cull,
0x203336702540090aull,0x744c240920617262ull,0x30313131315f305full,0x305f744c240a3b36ull,
0x3a3439353031315full,0x3309636f6c2e090aull,0x0a30093238360932ull,0x6e79732e72616209ull,
0x2e090a3b30092063ull,0x3609323309636f6cull,0x6f6d090a30093938ull,0x2509203233732e76ull,
0x357225202c333172ull,0x3370252140090a3bull,0x2409206172622035ull,0x3231315f305f744cull,
0x7573090a3b323436ull,0x2509203233732e62ull,0x7225202c32313372ull,0x357225202c323731ull,
0x732e646461090a3bull,0x3133722509203233ull,0x3231337225202c33ull,0x090a3b313135202cull,
0x203233732e726873ull,0x202c343133722509ull,0x33202c3331337225ull,0x2e766f6d090a3b31ull,
0x3372250920323373ull,0x3b313135202c3531ull,0x33622e646e61090aull,0x3631337225092032ull,
0x2c3431337225202cull,0x0a3b353133722520ull,0x3233732e64646109ull,0x2c37313372250920ull,
0x202c363133722520ull,0x090a3b3331337225ull,0x203233732e726873ull,0x202c383133722509ull,
0x39202c3731337225ull,0x752e747663090a3bull,0x09203233732e3436ull,0x202c333131647225ull,
0x756d090a3b357225ull,0x3436752e6f6c2e6cull,0x2c38336472250920ull,0x2c33313164722520ull,
0x2e646c090a3b3420ull,0x36752e74736e6f63ull,0x3437647225092034ull,0x2b346472255b202cull,
0x646c090a3b5d3038ull,0x752e74736e6f632eull,0x3664722509203436ull,0x346472255b202c34ull,
0x61090a3b5d32372bull,0x09203436752e6464ull,0x25202c3537647225ull,0x7225202c34376472ull,
0x646c090a3b383364ull,0x732e74736e6f632eull,0x3831722509203233ull,0x6f635f645b202c30ull,
0x3830332b6e6f6d6dull,0x632e646c090a3b5dull,0x3233732e74736e6full,0x2c31383172250920ull,
0x6d6d6f635f645b20ull,0x3b5d3030332b6e6full,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x5b202c3238317225ull,0x6e6f6d6d6f635f64ull,0x090a3b5d3438322bull,0x74736e6f632e646cull,
0x722509203233732eull,0x5f645b202c333431ull,0x322b6e6f6d6d6f63ull,0x6f6d090a3b5d3836ull,
0x2509203233732e76ull,0x7225202c39313372ull,0x744c240a3b383133ull,0x35313331315f305full,
0x6c3c2f2f200a3a34ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,0x2c39383620656e69ull,
0x676e697473656e20ull,0x203a687470656420ull,0x6d69747365202c31ull,0x6574692064657461ull,
0x3a736e6f69746172ull,0x6e776f6e6b6e7520ull,0x3309636f6c2e090aull,0x0a30093339360932ull,
0x3233732e64646109ull,0x202c353272250920ull,0x3b31202c33317225ull,0x33732e6d6572090aull,
0x3032337225092032ull,0x202c35327225202cull,0x090a3b3238317225ull,0x203233732e627573ull,
0x25202c3732722509ull,0x3b31202c30323372ull,0x3309636f6c2e090aull,0x0a30093439360932ull,
0x3233732e76696409ull,0x202c383272250920ull,0x7225202c35327225ull,0x6f6d090a3b323831ull,
0x2509203233752e76ull,0x3b30202c31323372ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x337225202c343670ull,0x32337225202c3032ull,0x36702540090a3b31ull,0x2409206172622034ull,
0x3331315f305f744cull,0x2f2f200a3b303134ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x383620656e696c20ull,0x2064616568202c39ull,0x2064656c6562616cull,
0x31315f305f744c24ull,0x6c2e090a34353133ull,0x393609323309636full,0x627573090a300936ull,
0x722509203233732eull,0x38317225202c3732ull,0x2e090a3b31202c32ull,0x3609323309636f6cull,
0x7573090a30093739ull,0x2509203233732e62ull,0x327225202c383272ull,0x4c240a3b31202c38ull,
0x343331315f305f74ull,0x3c2f2f200a3a3031ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x39383620656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3331315f305f744cull,0x6f6c2e090a343531ull,0x3330370932330963ull,0x2e646461090a3009ull,
0x3372250920323373ull,0x37327225202c3232ull,0x3b3138317225202cull,0x33732e646461090aull,
0x3332337225092032ull,0x202c38327225202cull,0x090a3b3038317225ull,0x203233732e627573ull,
0x202c343233722509ull,0x31202c3332337225ull,0x6c2e6c756d090a3bull,0x2509203233732e6full,
0x7225202c35323372ull,0x337225202c333431ull,0x646461090a3b3432ull,0x722509203233732eull,
0x337225202c363233ull,0x32337225202c3232ull,0x2e747663090a3b35ull,0x203233732e343673ull,
0x2c34313164722509ull,0x0a3b363233722520ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x647225202c353131ull,0x0a3b34202c343131ull,0x3436752e64646109ull,0x3631316472250920ull,
0x2c3436647225202cull,0x3b35313164722520ull,0x6f6c672e646c090aull,0x203233662e6c6162ull,
0x5b202c3033662509ull,0x2d2b363131647225ull,0x2e7473090a3b5d34ull,0x662e6c61626f6c67ull,
0x6472255b09203233ull,0x25202c5d302b3537ull,0x6461090a3b303366ull,0x2509203233732e64ull,
0x317225202c333172ull,0x0a3b323135202c33ull,0x3436752e64646109ull,0x2c35376472250920ull,
0x202c353764722520ull,0x73090a3b38343032ull,0x732e746c2e707465ull,0x3536702509203233ull,
0x202c33317225202cull,0x090a3b3237317225ull,0x7262203536702540ull,0x305f744c24092061ull,
0x3b3435313331315full,0x315f305f744c240aull,0x090a3a3234363231ull,0x09323309636f6c2eull,
0x62090a3009343137ull,0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x3532370932330963ull,
0x2e766f6d090a3009ull,0x3172250920323373ull,0x0a3b357225202c33ull,0x2038337025214009ull,
0x744c240920617262ull,0x37313431315f305full,0x2e627573090a3b38ull,0x3372250920323373ull,
0x39317225202c3732ull,0x0a3b357225202c31ull,0x3233732e64646109ull,0x2c38323372250920ull,
0x202c373233722520ull,0x6873090a3b313135ull,0x2509203233732e72ull,0x7225202c39323372ull,
0x3b3133202c383233ull,0x33732e766f6d090aull,0x3033337225092032ull,0x090a3b313135202cull,
0x203233622e646e61ull,0x202c313333722509ull,0x25202c3932337225ull,0x61090a3b30333372ull,
0x09203233732e6464ull,0x25202c3233337225ull,0x7225202c31333372ull,0x6873090a3b383233ull,
0x2509203233732e72ull,0x7225202c33333372ull,0x0a3b39202c323333ull,0x3436752e74766309ull,
0x722509203233732eull,0x7225202c37313164ull,0x2e6c756d090a3b35ull,0x09203436752e6f6cull,
0x25202c3833647225ull,0x34202c3731316472ull,0x6f632e646c090a3bull,0x203436752e74736eull,
0x202c303864722509ull,0x38382b346472255bull,0x632e646c090a3b5dull,0x3436752e74736e6full,
0x2c34366472250920ull,0x372b346472255b20ull,0x646461090a3b5d32ull,0x722509203436752eull,
0x647225202c313864ull,0x33647225202c3038ull,0x632e646c090a3b38ull,0x3233732e74736e6full,
0x2c30303272250920ull,0x6d6d6f635f645b20ull,0x3b5d3432332b6e6full,0x6e6f632e646c090aull,
0x09203233732e7473ull,0x5b202c3334317225ull,0x6e6f6d6d6f635f64ull,0x090a3b5d3836322bull,
0x74736e6f632e646cull,0x722509203233732eull,0x5f645b202c313032ull,0x332b6e6f6d6d6f63ull,
0x6f6d090a3b5d3631ull,0x2509203233732e76ull,0x7225202c34333372ull,0x744c240a3b333333ull,
0x39363431315f305full,0x6c3c2f2f200a3a30ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,
0x2c35323720656e69ull,0x676e697473656e20ull,0x203a687470656420ull,0x6d69747365202c31ull,
0x6574692064657461ull,0x3a736e6f69746172ull,0x6e776f6e6b6e7520ull,0x3309636f6c2e090aull,
0x0a30093932370932ull,0x3233732e64646109ull,0x202c353272250920ull,0x3b31202c33317225ull,
0x33732e6d6572090aull,0x3533337225092032ull,0x202c35327225202cull,0x090a3b3239317225ull,
0x203233732e627573ull,0x25202c3732722509ull,0x3b31202c35333372ull,0x3309636f6c2e090aull,
0x0a30093033370932ull,0x3233732e76696409ull,0x202c383272250920ull,0x7225202c35327225ull,
0x6f6d090a3b323931ull,0x2509203233752e76ull,0x3b30202c36333372ull,0x6e2e70746573090aull,
0x2509203233732e65ull,0x337225202c363670ull,0x33337225202c3533ull,0x36702540090a3b36ull,
0x2409206172622036ull,0x3431315f305f744cull,0x2f2f200a3b363439ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x323720656e696c20ull,0x2064616568202c35ull,
0x2064656c6562616cull,0x31315f305f744c24ull,0x6c2e090a30393634ull,0x333709323309636full,
0x627573090a300932ull,0x722509203233732eull,0x39317225202c3732ull,0x2e090a3b31202c32ull,
0x3709323309636f6cull,0x7573090a30093333ull,0x2509203233732e62ull,0x327225202c383272ull,
0x4c240a3b31202c38ull,0x393431315f305f74ull,0x3c2f2f200a3a3634ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x35323720656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3431315f305f744cull,0x6f6c2e090a303936ull,0x3933370932330963ull,
0x2e646461090a3009ull,0x3372250920323373ull,0x37327225202c3733ull,0x3b3130327225202cull,
0x33732e646461090aull,0x3833337225092032ull,0x202c38327225202cull,0x090a3b3030327225ull,
0x203233732e627573ull,0x202c393333722509ull,0x31202c3833337225ull,0x6c2e6c756d090a3bull,
0x2509203233732e6full,0x7225202c30343372ull,0x337225202c333431ull,0x646461090a3b3933ull,
0x722509203233732eull,0x337225202c313433ull,0x34337225202c3733ull,0x2e747663090a3b30ull,
0x203233732e343673ull,0x2c38313164722509ull,0x0a3b313433722520ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x647225202c393131ull,0x0a3b34202c383131ull,0x3436752e64646109ull,
0x3032316472250920ull,0x2c3436647225202cull,0x3b39313164722520ull,0x6f6c672e646c090aull,
0x203233662e6c6162ull,0x5b202c3133662509ull,0x2d2b303231647225ull,0x2e7473090a3b5d34ull,
0x662e6c61626f6c67ull,0x6472255b09203233ull,0x25202c5d302b3138ull,0x6461090a3b313366ull,
0x2509203233732e64ull,0x317225202c333172ull,0x0a3b323135202c33ull,0x3436752e64646109ull,
0x2c31386472250920ull,0x202c313864722520ull,0x73090a3b38343032ull,0x732e746c2e707465ull,
0x3736702509203233ull,0x202c33317225202cull,0x090a3b3139317225ull,0x7262203736702540ull,
0x305f744c24092061ull,0x3b3039363431315full,0x315f305f744c240aull,0x090a3a3837313431ull,
0x09323309636f6c2eull,0x62090a3009303537ull,0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,
0x3735370932330963ull,0x2e766f6d090a3009ull,0x3172250920323373ull,0x0a3b357225202c33ull,
0x2038337025214009ull,0x744c240920617262ull,0x31373531315f305full,0x2e627573090a3b34ull,
0x3372250920323373ull,0x39317225202c3234ull,0x0a3b357225202c31ull,0x3233732e64646109ull,
0x2c33343372250920ull,0x202c323433722520ull,0x6873090a3b313135ull,0x2509203233732e72ull,
0x7225202c34343372ull,0x3b3133202c333433ull,0x33732e766f6d090aull,0x3534337225092032ull,
0x090a3b313135202cull,0x203233622e646e61ull,0x202c363433722509ull,0x25202c3434337225ull,
0x61090a3b35343372ull,0x09203233732e6464ull,0x25202c3734337225ull,0x7225202c36343372ull,
0x6873090a3b333433ull,0x2509203233732e72ull,0x7225202c38343372ull,0x0a3b39202c373433ull,
0x3436752e74766309ull,0x722509203233732eull,0x7225202c31323164ull,0x2e6c756d090a3b35ull,
0x09203436752e6f6cull,0x25202c3833647225ull,0x34202c3132316472ull,0x6f632e646c090a3bull,
0x203436752e74736eull,0x202c303864722509ull,0x38382b346472255bull,0x632e646c090a3b5dull,
0x3436752e74736e6full,0x2c34376472250920ull,0x382b346472255b20ull,0x646461090a3b5d30ull,
0x722509203436752eull,0x647225202c313864ull,0x33647225202c3038ull,0x2e646461090a3b38ull,
0x6472250920343675ull,0x37647225202c3537ull,0x3833647225202c34ull,0x732e766f6d090a3bull,
0x3433722509203233ull,0x3834337225202c39ull,0x5f305f744c240a3bull,0x0a3a363232363131ull,
0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,0x656e202c37353720ull,
0x656420676e697473ull,0x202c31203a687470ull,0x6574616d69747365ull,0x7461726574692064ull,
0x6e75203a736e6f69ull,0x2e090a6e776f6e6bull,0x3709323309636f6cull,0x646c090a30093136ull,
0x2e6c61626f6c672eull,0x3366250920323366ull,0x376472255b202c32ull,0x6c090a3b5d302b35ull,
0x6c61626f6c672e64ull,0x662509203233662eull,0x6472255b202c3333ull,0x090a3b5d302b3138ull,
0x203233662e627573ull,0x25202c3433662509ull,0x336625202c323366ull,0x672e7473090a3b33ull,
0x33662e6c61626f6cull,0x386472255b092032ull,0x6625202c5d302b31ull,0x646461090a3b3433ull,
0x722509203233732eull,0x33317225202c3331ull,0x090a3b323135202cull,0x203436752e646461ull,
0x202c353764722509ull,0x32202c3537647225ull,0x6461090a3b383430ull,0x2509203436752e64ull,
0x7225202c31386472ull,0x343032202c313864ull,0x70746573090a3b38ull,0x203233732e746c2eull,
0x25202c3836702509ull,0x317225202c333172ull,0x702540090a3b3139ull,0x0920617262203836ull,
0x31315f305f744c24ull,0x4c240a3b36323236ull,0x373531315f305f74ull,0x6f6c2e090a3a3431ull,
0x3337370932330963ull,0x2e766f6d090a3009ull,0x3172250920323373ull,0x0a3b357225202c33ull,
0x2032347025214009ull,0x744c240920617262ull,0x33373631315f305full,0x2e627573090a3b38ull,
0x3372250920323373ull,0x39317225202c3035ull,0x0a3b357225202c32ull,0x3233732e64646109ull,
0x2c31353372250920ull,0x202c303533722520ull,0x6873090a3b313135ull,0x2509203233732e72ull,
0x7225202c32353372ull,0x3b3133202c313533ull,0x33732e766f6d090aull,0x3335337225092032ull,
0x090a3b313135202cull,0x203233622e646e61ull,0x202c343533722509ull,0x25202c3235337225ull,
0x61090a3b33353372ull,0x09203233732e6464ull,0x25202c3535337225ull,0x7225202c34353372ull,
0x6873090a3b313533ull,0x2509203233732e72ull,0x7225202c36353372ull,0x0a3b39202c353533ull,
0x3233732e766f6d09ull,0x2c37353372250920ull,0x0a3b363533722520ull,0x31315f305f744c24ull,
0x2f200a3a30353237ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3720656e696c2079ull,
0x7473656e202c3337ull,0x7470656420676e69ull,0x7365202c31203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x3338370932330963ull,
0x2e766f6d090a3009ull,0x3172250920323373ull,0x33317225202c3836ull,0x732e646461090a3bull,
0x3232722509203233ull,0x2c33317225202c36ull,0x0a3b313931722520ull,0x656c2e7074657309ull,
0x702509203233732eull,0x32327225202c3936ull,0x3b33317225202c36ull,0x203936702540090aull,
0x744c240920617262ull,0x30353731315f305full,0x6c3c2f2f200a3b36ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c33373720656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x323731315f305f74ull,0x2e747663090a3035ull,0x203233732e343673ull,
0x2c32323164722509ull,0x0a3b323931722520ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x31647225202c3738ull,0x090a3b34202c3232ull,0x74736e6f632e646cull,0x722509203436752eull,
0x72255b202c303864ull,0x0a3b5d38382b3464ull,0x3436752e74766309ull,0x722509203233732eull,
0x7225202c33323164ull,0x6c756d090a3b3331ull,0x203436752e6f6c2eull,0x2c34323164722509ull,
0x2c33323164722520ull,0x646461090a3b3420ull,0x722509203436752eull,0x647225202c303964ull,
0x31647225202c3038ull,0x766f6d090a3b3432ull,0x662509203233662eull,0x3030306630202c39ull,
0x20203b3030303030ull,0x30202f2f09202020ull,0x315f305f744c240aull,0x200a3a3831303831ull,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c333837ull,
0x70656420676e6974ull,0x65202c32203a6874ull,0x646574616d697473ull,0x6974617265746920ull,
0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,0x383709323309636full,0x2e646c090a300934ull,
0x662e6c61626f6c67ull,0x3533662509203233ull,0x30396472255b202cull,0x6461090a3b5d302bull,
0x2509203233662e64ull,0x336625202c363366ull,0x0a3b396625202c35ull,0x626f6c672e747309ull,
0x09203233662e6c61ull,0x302b30396472255bull,0x3b36336625202c5dull,0x3309636f6c2e090aull,
0x0a30093538370932ull,0x3233662e766f6d09ull,0x25202c3966250920ull,0x6461090a3b363366ull,
0x2509203233732e64ull,0x7225202c38363172ull,0x317225202c383631ull,0x646461090a3b3239ull,
0x722509203436752eull,0x647225202c303964ull,0x38647225202c3039ull,0x70746573090a3b37ull,
0x203233732e74672eull,0x25202c3037702509ull,0x7225202c36323272ull,0x2540090a3b383631ull,
0x2061726220303770ull,0x315f305f744c2409ull,0x240a3b3831303831ull,0x3731315f305f744cull,
0x2f2f200a3a363035ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x373720656e696c20ull,0x2064616568202c33ull,0x2064656c6562616cull,0x31315f305f744c24ull,
0x6461090a30353237ull,0x2509203233732e64ull,0x317225202c333172ull,0x0a3b323135202c33ull,
0x746c2e7074657309ull,0x702509203233732eull,0x33317225202c3137ull,0x3b3239317225202cull,
0x203137702540090aull,0x744c240920617262ull,0x35323731315f305full,0x305f744c240a3b30ull,
0x3a3833373631315full,0x3309636f6c2e090aull,0x0a30093739370932ull,0x6e79732e72616209ull,
0x2e090a3b30092063ull,0x3809323309636f6cull,0x6f6d090a30093430ull,0x2509203233732e76ull,
0x357225202c333172ull,0x3470252140090a3bull,0x2409206172622036ull,0x3831315f305f744cull,
0x7573090a3b363837ull,0x2509203233732e62ull,0x7225202c38353372ull,0x357225202c373232ull,
0x732e646461090a3bull,0x3533722509203233ull,0x3835337225202c39ull,0x090a3b313135202cull,
0x203233732e726873ull,0x202c303633722509ull,0x33202c3935337225ull,0x2e766f6d090a3b31ull,
0x3372250920323373ull,0x3b313135202c3136ull,0x33622e646e61090aull,0x3236337225092032ull,
0x2c3036337225202cull,0x0a3b313633722520ull,0x3233732e64646109ull,0x2c33363372250920ull,
0x202c323633722520ull,0x090a3b3935337225ull,0x203233732e726873ull,0x202c343633722509ull,
0x39202c3336337225ull,0x752e747663090a3bull,0x09203233732e3436ull,0x202c353231647225ull,
0x756d090a3b357225ull,0x3436752e6f6c2e6cull,0x2c38336472250920ull,0x2c35323164722520ull,
0x2e646c090a3b3420ull,0x36752e74736e6f63ull,0x3239647225092034ull,0x2b346472255b202cull,
0x646c090a3b5d3639ull,0x752e74736e6f632eull,0x3864722509203436ull,0x346472255b202c30ull,
0x61090a3b5d38382bull,0x09203436752e6464ull,0x25202c3339647225ull,0x7225202c32396472ull,
0x646c090a3b383364ull,0x732e74736e6f632eull,0x3332722509203233ull,0x6f635f645b202c35ull,
0x3237332b6e6f6d6dull,0x632e646c090a3b5dull,0x3233732e74736e6full,0x2c36333272250920ull,
0x6d6d6f635f645b20ull,0x3b5d3436332b6e6full,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x5b202c3733327225ull,0x6e6f6d6d6f635f64ull,0x090a3b5d3834332bull,0x203233732e766f6dull,
0x202c353633722509ull,0x240a3b3436337225ull,0x3931315f305f744cull,0x2f2f200a3a383932ull,
0x4c203e706f6f6c3cull,0x79646f6220706f6full,0x303820656e696c20ull,0x697473656e202c34ull,
0x687470656420676eull,0x747365202c31203aull,0x6920646574616d69ull,0x6e6f697461726574ull,
0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,0x0938303809323309ull,0x732e646461090a30ull,
0x3532722509203233ull,0x202c33317225202cull,0x2e6d6572090a3b31ull,0x3372250920323373ull,
0x35327225202c3636ull,0x3b3733327225202cull,0x33732e627573090aull,0x2c37327225092032ull,
0x202c363633722520ull,0x636f6c2e090a3b31ull,0x0939303809323309ull,0x732e766964090a30ull,
0x3832722509203233ull,0x202c35327225202cull,0x090a3b3733327225ull,0x203233752e766f6dull,
0x202c373633722509ull,0x70746573090a3b30ull,0x203233732e656e2eull,0x25202c3237702509ull,
0x7225202c36363372ull,0x2540090a3b373633ull,0x2061726220323770ull,0x315f305f744c2409ull,
0x200a3b3435353931ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c343038ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x090a383932393131ull,0x09323309636f6c2eull,0x73090a3009313138ull,0x09203233732e6275ull,
0x7225202c37327225ull,0x0a3b31202c373332ull,0x323309636f6c2e09ull,0x090a300932313809ull,
0x203233732e627573ull,0x25202c3832722509ull,0x0a3b31202c383272ull,0x31315f305f744c24ull,
0x2f200a3a34353539ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3820656e696c2079ull,0x64616568202c3430ull,0x64656c6562616c20ull,0x315f305f744c2420ull,
0x2e090a3839323931ull,0x3809323309636f6cull,0x6461090a30093831ull,0x2509203233732e64ull,
0x7225202c38363372ull,0x33327225202c3732ull,0x2e646461090a3b36ull,0x3372250920323373ull,
0x38327225202c3936ull,0x3b3533327225202cull,0x33732e627573090aull,0x3037337225092032ull,
0x2c3936337225202cull,0x6c756d090a3b3120ull,0x203233732e6f6c2eull,0x202c313733722509ull,
0x25202c3239317225ull,0x61090a3b30373372ull,0x09203233732e6464ull,0x25202c3237337225ull,
0x7225202c38363372ull,0x7663090a3b313733ull,0x33732e3436732e74ull,0x3231647225092032ull,
0x3237337225202c36ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x25202c3732316472ull,
0x34202c3632316472ull,0x752e646461090a3bull,0x3164722509203436ull,0x38647225202c3832ull,
0x3231647225202c30ull,0x672e646c090a3b37ull,0x33662e6c61626f6cull,0x2c37336625092032ull,
0x3832316472255b20ull,0x73090a3b5d342d2bull,0x6c61626f6c672e74ull,0x255b09203233662eull,
0x2c5d302b33396472ull,0x090a3b3733662520ull,0x203233732e646461ull,0x25202c3331722509ull,
0x323135202c333172ull,0x752e646461090a3bull,0x3964722509203436ull,0x3339647225202c33ull,
0x0a3b38343032202cull,0x746c2e7074657309ull,0x702509203233732eull,0x33317225202c3337ull,
0x3b3732327225202cull,0x203337702540090aull,0x744c240920617262ull,0x39323931315f305full,
0x305f744c240a3b38ull,0x3a3638373831315full,0x3309636f6c2e090aull,0x0a30093932380932ull,
0x6e79732e72616209ull,0x2e090a3b30092063ull,0x3809323309636f6cull,0x6f6d090a30093034ull,
0x2509203233732e76ull,0x357225202c333172ull,0x3470252140090a3bull,0x2409206172622039ull,
0x3032315f305f744cull,0x7573090a3b323233ull,0x2509203233732e62ull,0x7225202c33373372ull,
0x357225202c363432ull,0x732e646461090a3bull,0x3733722509203233ull,0x3337337225202c34ull,
0x090a3b313135202cull,0x203233732e726873ull,0x202c353733722509ull,0x33202c3437337225ull,
0x2e766f6d090a3b31ull,0x3372250920323373ull,0x3b313135202c3637ull,0x33622e646e61090aull,
0x3737337225092032ull,0x2c3537337225202cull,0x0a3b363733722520ull,0x3233732e64646109ull,
0x2c38373372250920ull,0x202c373733722520ull,0x090a3b3437337225ull,0x203233732e726873ull,
0x202c393733722509ull,0x39202c3837337225ull,0x752e747663090a3bull,0x09203233732e3436ull,
0x202c393231647225ull,0x756d090a3b357225ull,0x3436752e6f6c2e6cull,0x2c38336472250920ull,
0x2c39323164722520ull,0x2e646c090a3b3420ull,0x36752e74736e6f63ull,0x3331647225092034ull,
0x346472255b202c30ull,0x090a3b5d3032312bull,0x74736e6f632e646cull,0x722509203436752eull,
0x72255b202c303864ull,0x0a3b5d38382b3464ull,0x3436752e64646109ull,0x3133316472250920ull,
0x303331647225202cull,0x3b3833647225202cull,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x5b202c3435327225ull,0x6e6f6d6d6f635f64ull,0x090a3b5d3838332bull,0x74736e6f632e646cull,
0x722509203233732eull,0x5f645b202c353532ull,0x332b6e6f6d6d6f63ull,0x646c090a3b5d3038ull,
0x732e74736e6f632eull,0x3532722509203233ull,0x6f635f645b202c36ull,0x3639332b6e6f6d6dull,
0x2e766f6d090a3b5dull,0x3372250920323373ull,0x37337225202c3038ull,0x305f744c240a3b39ull,
0x3a3433383032315full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,
0x6e202c3034382065ull,0x6420676e69747365ull,0x2c31203a68747065ull,0x74616d6974736520ull,
0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,0x09323309636f6c2eull,
0x61090a3009343438ull,0x09203233732e6464ull,0x7225202c35327225ull,0x090a3b31202c3331ull,
0x203233732e6d6572ull,0x202c313833722509ull,0x7225202c35327225ull,0x7573090a3b363532ull,
0x2509203233732e62ull,0x337225202c373272ull,0x090a3b31202c3138ull,0x09323309636f6c2eull,
0x64090a3009353438ull,0x09203233732e7669ull,0x7225202c38327225ull,0x35327225202c3532ull,
0x2e766f6d090a3b36ull,0x3372250920323375ull,0x090a3b30202c3238ull,0x2e656e2e70746573ull,
0x3770250920323373ull,0x3138337225202c34ull,0x3b3238337225202cull,0x203437702540090aull,
0x744c240920617262ull,0x39303132315f305full,0x6c3c2f2f200a3b30ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30343820656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x383032315f305f74ull,0x636f6c2e090a3433ull,0x0937343809323309ull,
0x732e627573090a30ull,0x3732722509203233ull,0x2c3635327225202cull,0x6f6c2e090a3b3120ull,
0x3834380932330963ull,0x2e627573090a3009ull,0x3272250920323373ull,0x2c38327225202c38ull,
0x5f744c240a3b3120ull,0x3039303132315f30ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30343820656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x33383032315f305full,0x09636f6c2e090a34ull,0x3009343538093233ull,
0x33732e646461090aull,0x3338337225092032ull,0x202c37327225202cull,0x090a3b3535327225ull,
0x203233732e646461ull,0x202c343833722509ull,0x7225202c38327225ull,0x7573090a3b343532ull,
0x2509203233732e62ull,0x7225202c35383372ull,0x0a3b31202c343833ull,0x2e6f6c2e6c756d09ull,
0x3372250920323373ull,0x39317225202c3638ull,0x3538337225202c32ull,0x732e646461090a3bull,
0x3833722509203233ull,0x3338337225202c37ull,0x3b3638337225202cull,0x36732e747663090aull,
0x2509203233732e34ull,0x25202c3233316472ull,0x6d090a3b37383372ull,0x36752e6f6c2e6c75ull,
0x3331647225092034ull,0x3331647225202c33ull,0x61090a3b34202c32ull,0x09203436752e6464ull,
0x202c343331647225ull,0x25202c3038647225ull,0x090a3b3333316472ull,0x61626f6c672e646cull,
0x2509203233662e6cull,0x72255b202c383366ull,0x5d342d2b34333164ull,0x6c672e7473090a3bull,
0x3233662e6c61626full,0x33316472255b0920ull,0x6625202c5d302b31ull,0x646461090a3b3833ull,
0x722509203233732eull,0x33317225202c3331ull,0x090a3b323135202cull,0x203436752e646461ull,
0x2c31333164722509ull,0x2c31333164722520ull,0x090a3b3834303220ull,0x2e746c2e70746573ull,
0x3770250920323373ull,0x2c33317225202c35ull,0x0a3b363432722520ull,0x6220353770254009ull,
0x5f744c2409206172ull,0x3433383032315f30ull,0x5f305f744c240a3bull,0x0a3a323233303231ull,
0x323309636f6c2e09ull,0x090a300935363809ull,0x636e79732e726162ull,0x6c2e090a3b300920ull,
0x373809323309636full,0x766f6d090a300932ull,0x722509203233732eull,0x3b357225202c3331ull,
0x393470252140090aull,0x4c24092061726220ull,0x383132315f305f74ull,0x627573090a3b3835ull,
0x722509203233732eull,0x327225202c383833ull,0x3b357225202c3634ull,0x33732e646461090aull,
0x3938337225092032ull,0x2c3838337225202cull,0x73090a3b31313520ull,0x09203233732e7268ull,
0x25202c3039337225ull,0x3133202c39383372ull,0x732e766f6d090a3bull,0x3933722509203233ull,
0x0a3b313135202c31ull,0x3233622e646e6109ull,0x2c32393372250920ull,0x202c303933722520ull,
0x090a3b3139337225ull,0x203233732e646461ull,0x202c333933722509ull,0x25202c3239337225ull,
0x73090a3b39383372ull,0x09203233732e7268ull,0x25202c3439337225ull,0x3b39202c33393372ull,
0x36752e747663090aull,0x2509203233732e34ull,0x25202c3533316472ull,0x6c756d090a3b3572ull,
0x203436752e6f6c2eull,0x202c383364722509ull,0x202c353331647225ull,0x632e646c090a3b34ull,
0x3436752e74736e6full,0x3033316472250920ull,0x2b346472255b202cull,0x6c090a3b5d303231ull,
0x2e74736e6f632e64ull,0x6472250920343675ull,0x6472255b202c3239ull,0x090a3b5d36392b34ull,
0x203436752e646461ull,0x2c31333164722509ull,0x2c30333164722520ull,0x0a3b383364722520ull,
0x3436752e64646109ull,0x2c33396472250920ull,0x202c323964722520ull,0x090a3b3833647225ull,
0x203233732e766f6dull,0x202c353933722509ull,0x240a3b3439337225ull,0x3232315f305f744cull,
0x2f2f200a3a303733ull,0x4c203e706f6f6c3cull,0x79646f6220706f6full,0x373820656e696c20ull,
0x697473656e202c32ull,0x687470656420676eull,0x747365202c31203aull,0x6920646574616d69ull,
0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,0x0936373809323309ull,
0x6c672e646c090a30ull,0x3233662e6c61626full,0x202c393366250920ull,0x302b33396472255bull,
0x672e646c090a3b5dull,0x33662e6c61626f6cull,0x2c30346625092032ull,0x3133316472255b20ull,
0x7573090a3b5d302bull,0x2509203233662e62ull,0x336625202c313466ull,0x3b30346625202c39ull,
0x6f6c672e7473090aull,0x203233662e6c6162ull,0x3133316472255b09ull,0x346625202c5d302bull,
0x2e646461090a3b31ull,0x3172250920323373ull,0x2c33317225202c33ull,0x61090a3b32313520ull,
0x09203436752e6464ull,0x25202c3339647225ull,0x3032202c33396472ull,0x646461090a3b3834ull,
0x722509203436752eull,0x7225202c31333164ull,0x3032202c31333164ull,0x746573090a3b3834ull,
0x3233732e746c2e70ull,0x202c363770250920ull,0x7225202c33317225ull,0x2540090a3b363432ull,
0x2061726220363770ull,0x315f305f744c2409ull,0x240a3b3037333232ull,0x3132315f305f744cull,
0x6c2e090a3a383538ull,0x383809323309636full,0x726162090a300937ull,0x300920636e79732eull,
0x09636f6c2e090a3bull,0x3009383938093233ull,0x33732e766f6d090aull,0x2c33317225092032ull,
0x40090a3b35722520ull,0x7262203934702521ull,0x305f744c24092061ull,0x3b3238383232315full,
0x33732e627573090aull,0x3639337225092032ull,0x2c3634327225202cull,0x61090a3b35722520ull,
0x09203233732e6464ull,0x25202c3739337225ull,0x3135202c36393372ull,0x2e726873090a3b31ull,
0x3372250920323373ull,0x39337225202c3839ull,0x090a3b3133202c37ull,0x203233732e766f6dull,
0x202c393933722509ull,0x6e61090a3b313135ull,0x2509203233622e64ull,0x7225202c30303472ull,
0x337225202c383933ull,0x646461090a3b3939ull,0x722509203233732eull,0x347225202c313034ull,
0x39337225202c3030ull,0x2e726873090a3b37ull,0x3472250920323373ull,0x30347225202c3230ull,
0x63090a3b39202c31ull,0x732e3436752e7476ull,0x3664722509203233ull,0x0a3b357225202c33ull,
0x2e6e722e74766309ull,0x203233732e323366ull,0x25202c3234662509ull,0x756d090a3b343172ull,
0x3436752e6f6c2e6cull,0x2c38336472250920ull,0x202c333664722520ull,0x632e646c090a3b34ull,
0x3436752e74736e6full,0x3033316472250920ull,0x2b346472255b202cull,0x6c090a3b5d303231ull,
0x2e74736e6f632e64ull,0x6472250920343675ull,0x6472255b202c3839ull,0x0a3b5d3430312b34ull,
0x3436752e64646109ull,0x3133316472250920ull,0x303331647225202cull,0x3b3833647225202cull,
0x36752e646461090aull,0x3939647225092034ull,0x2c3839647225202cull,0x0a3b383364722520ull,
0x3233732e766f6d09ull,0x2c33303472250920ull,0x0a3b323034722520ull,0x32315f305f744c24ull,
0x2f200a3a34393333ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3820656e696c2079ull,
0x7473656e202c3839ull,0x7470656420676e69ull,0x7365202c31203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x3130390932330963ull,
0x672e646c090a3009ull,0x33662e6c61626f6cull,0x2c34326625092032ull,0x2b39396472255b20ull,
0x6f6c2e090a3b5d30ull,0x3230390932330963ull,0x672e646c090a3009ull,0x33662e6c61626f6cull,
0x2c33346625092032ull,0x3133316472255b20ull,0x756d090a3b5d302bull,0x2509203233662e6cull,
0x326625202c343466ull,0x3b34326625202c34ull,0x75662e766964090aull,0x09203233662e6c6cull,
0x6625202c35346625ull,0x32346625202c3434ull,0x662e627573090a3bull,0x3634662509203233ull,
0x202c33346625202cull,0x2e090a3b35346625ull,0x3909323309636f6cull,0x6f6d090a30093630ull,
0x2509203233662e76ull,0x306630202c373466ull,0x3b30303030303030ull,0x202f2f0920202020ull,
0x662e766f6d090a30ull,0x3834662509203233ull,0x303030306630202cull,0x2020203b30303030ull,
0x090a30202f2f0920ull,0x2e746c2e70746573ull,0x3770250920323366ull,0x2c36346625202c37ull,
0x090a3b3834662520ull,0x3233662e706c6573ull,0x202c393466250920ull,0x6625202c37346625ull,
0x37377025202c3634ull,0x2e74727173090a3bull,0x662e786f72707061ull,0x3035662509203233ull,
0x0a3b39346625202cull,0x626f6c672e747309ull,0x09203233662e6c61ull,0x2b3133316472255bull,
0x30356625202c5d30ull,0x732e646461090a3bull,0x3331722509203233ull,0x202c33317225202cull,
0x6461090a3b323135ull,0x2509203436752e64ull,0x7225202c39396472ull,0x343032202c393964ull,
0x2e646461090a3b38ull,0x6472250920343675ull,0x647225202c313331ull,0x343032202c313331ull,
0x70746573090a3b38ull,0x203233732e746c2eull,0x25202c3837702509ull,0x327225202c333172ull,
0x702540090a3b3634ull,0x0920617262203837ull,0x32315f305f744c24ull,0x4c240a3b34393333ull,
0x383232315f305f74ull,0x6f6c2e090a3a3238ull,0x3831390932330963ull,0x2e726162090a3009ull,
0x3b300920636e7973ull,0x3309636f6c2e090aull,0x0a30093532390932ull,0x3233732e766f6d09ull,
0x202c333172250920ull,0x646c090a3b357225ull,0x732e74736e6f632eull,0x3034722509203233ull,
0x6f635f645b202c34ull,0x3235342b6e6f6d6dull,0x70746573090a3b5dull,0x203233732e65672eull,
0x25202c3937702509ull,0x30347225202c3572ull,0x37702540090a3b34ull,0x2409206172622039ull,
0x3332315f305f744cull,0x7573090a3b363039ull,0x2509203233732e62ull,0x7225202c35303472ull,
0x357225202c343034ull,0x732e646461090a3bull,0x3034722509203233ull,0x3530347225202c36ull,
0x090a3b313135202cull,0x203233732e726873ull,0x202c373034722509ull,0x33202c3630347225ull,
0x2e766f6d090a3b31ull,0x3472250920323373ull,0x3b313135202c3830ull,0x33622e646e61090aull,
0x3930347225092032ull,0x2c3730347225202cull,0x0a3b383034722520ull,0x3233732e64646109ull,
0x2c30313472250920ull,0x202c393034722520ull,0x090a3b3630347225ull,0x203233732e726873ull,
0x202c313134722509ull,0x39202c3031347225ull,0x752e747663090a3bull,0x09203233732e3436ull,
0x202c363331647225ull,0x756d090a3b357225ull,0x3436752e6f6c2e6cull,0x2c38336472250920ull,
0x2c36333164722520ull,0x646461090a3b3420ull,0x722509203436752eull,0x7225202c37333164ull,
0x647225202c383364ull,0x632e646c090a3b38ull,0x3436752e74736e6full,0x3833316472250920ull,
0x2b346472255b202cull,0x61090a3b5d383231ull,0x09203436752e6464ull,0x202c393331647225ull,
0x202c383331647225ull,0x090a3b3833647225ull,0x203233732e766f6dull,0x202c323134722509ull,
0x240a3b3131347225ull,0x3432315f305f744cull,0x2f2f200a3a383134ull,0x4c203e706f6f6c3cull,
0x79646f6220706f6full,0x323920656e696c20ull,0x697473656e202c35ull,0x687470656420676eull,
0x747365202c31203aull,0x6920646574616d69ull,0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,
0x636f6c2e090a6e77ull,0x0938323909323309ull,0x6c672e646c090a30ull,0x3233662e6c61626full,
0x202c343266250920ull,0x2b3733316472255bull,0x6f6c2e090a3b5d30ull,0x3932390932330963ull,
0x2e6c756d090a3009ull,0x3566250920323366ull,0x2c34326625202c31ull,0x090a3b3432662520ull,
0x61626f6c672e7473ull,0x5b09203233662e6cull,0x302b393331647225ull,0x3b31356625202c5dull,
0x33732e646461090aull,0x2c33317225092032ull,0x35202c3331722520ull,0x646461090a3b3231ull,
0x722509203436752eull,0x7225202c39333164ull,0x3032202c39333164ull,0x646461090a3b3834ull,
0x722509203436752eull,0x7225202c37333164ull,0x3032202c37333164ull,0x746573090a3b3834ull,
0x3233732e746c2e70ull,0x202c303870250920ull,0x7225202c33317225ull,0x2540090a3b343034ull,
0x2061726220303870ull,0x315f305f744c2409ull,0x240a3b3831343432ull,0x3332315f305f744cull,
0x6c2e090a3a363039ull,0x343909323309636full,0x726162090a300930ull,0x300920636e79732eull,
0x09636f6c2e090a3bull,0x3009373439093233ull,0x33732e766f6d090aull,0x2c33317225092032ull,
0x73090a3b35722520ull,0x732e65672e707465ull,0x3138702509203233ull,0x25202c357225202cull,
0x2540090a3b393772ull,0x2061726220313870ull,0x315f305f744c2409ull,0x090a3b3033393432ull,
0x203436752e766f6dull,0x2c30343164722509ull,0x5f616475635f5f20ull,0x69747261705f6e69ull,
0x39316d75735f6c61ull,0x7573090a3b303031ull,0x2509203233732e62ull,0x7225202c33313472ull,
0x3b357225202c3937ull,0x33732e646461090aull,0x3431347225092032ull,0x2c3331347225202cull,
0x73090a3b31313520ull,0x09203233732e7268ull,0x25202c3531347225ull,0x3133202c34313472ull,
0x732e766f6d090a3bull,0x3134722509203233ull,0x0a3b313135202c36ull,0x3233622e646e6109ull,
0x2c37313472250920ull,0x202c353134722520ull,0x090a3b3631347225ull,0x203233732e646461ull,
0x202c383134722509ull,0x25202c3731347225ull,0x73090a3b34313472ull,0x09203233732e7268ull,
0x25202c3931347225ull,0x3b39202c38313472ull,0x36732e747663090aull,0x2509203233732e34ull,
0x25202c3134316472ull,0x2e646c090a3b3572ull,0x33732e74736e6f63ull,0x2c33327225092032ull,
0x6d6d6f635f645b20ull,0x3b5d3430322b6e6full,0x33732e766f6d090aull,0x3032347225092032ull,
0x6573090a3b30202cull,0x33732e74672e7074ull,0x2c32387025092032ull,0x25202c3332722520ull,
0x6d090a3b30323472ull,0x36752e6f6c2e6c75ull,0x3431647225092034ull,0x3431647225202c32ull,
0x61090a3b34202c31ull,0x09203436752e6464ull,0x202c333431647225ull,0x202c303431647225ull,
0x0a3b323431647225ull,0x3233732e766f6d09ull,0x2c31323472250920ull,0x0a3b393134722520ull,
0x32315f305f744c24ull,0x2f200a3a32343435ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,
0x3920656e696c2079ull,0x7473656e202c3734ull,0x7470656420676e69ull,0x7365202c31203a68ull,
0x20646574616d6974ull,0x6f69746172657469ull,0x6e6b6e75203a736eull,0x766f6d090a6e776full,
0x662509203233662eull,0x3030306630202c39ull,0x20203b3030303030ull,0x30202f2f09202020ull,
0x323870252140090aull,0x4c24092061726220ull,0x363735315f305f74ull,0x3c2f2f200a3b3839ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x37343920656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3532315f305f744cull,0x766f6d090a323434ull,
0x722509203233732eull,0x327225202c323234ull,0x2e6c756d090a3b33ull,0x09203233732e6f6cull,
0x25202c3332347225ull,0x327225202c333172ull,0x2e766f6d090a3b33ull,0x3472250920323373ull,
0x32347225202c3432ull,0x2e646461090a3b33ull,0x3472250920323373ull,0x32347225202c3532ull,
0x3b33327225202c33ull,0x36732e747663090aull,0x2509203233732e34ull,0x25202c3434316472ull,
0x6d090a3b33323472ull,0x36752e6f6c2e6c75ull,0x3431647225092034ull,0x3431647225202c35ull,
0x61090a3b34202c34ull,0x09203436752e6464ull,0x202c363431647225ull,0x7225202c38647225ull,
0x2f200a3b35343164ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3920656e696c2079ull,0x64616568202c3734ull,0x64656c6562616c20ull,0x315f305f744c2420ull,
0x6d090a3234343532ull,0x09203233732e766full,0x25202c3632347225ull,0x4c240a3b32323472ull,
0x323632315f305f74ull,0x3c2f2f200a3a3031ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,
0x37343920656e696cull,0x6e697473656e202cull,0x3a68747065642067ull,0x69747365202c3220ull,
0x746920646574616dull,0x736e6f6974617265ull,0x776f6e6b6e75203aull,0x09636f6c2e090a6eull,
0x3009333539093233ull,0x6f6c672e646c090aull,0x203233662e6c6162ull,0x5b202c3235662509ull,
0x302b363431647225ull,0x2e646461090a3b5dull,0x3966250920323366ull,0x202c32356625202cull,
0x6461090a3b396625ull,0x2509203233732e64ull,0x7225202c34323472ull,0x0a3b31202c343234ull,
0x3436752e64646109ull,0x3634316472250920ull,0x363431647225202cull,0x6573090a3b34202cull,
0x33732e656e2e7074ull,0x2c33387025092032ull,0x202c343234722520ull,0x090a3b3532347225ull,
0x7262203338702540ull,0x305f744c24092061ull,0x3b3031323632315full,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3734392065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x3234343532315f30ull,0x6e752e617262090aull,
0x305f744c24092069ull,0x3b3839363532315full,0x315f305f744c240aull,0x200a3a3839363735ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c373439ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x240a323434353231ull,
0x3532315f305f744cull,0x2f2f200a3a383936ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x343920656e696c20ull,0x2064616568202c37ull,0x2064656c6562616cull,
0x32315f305f744c24ull,0x6c2e090a32343435ull,0x353909323309636full,0x2e7473090a300936ull,
0x662e646572616873ull,0x6472255b09203233ull,0x202c5d302b333431ull,0x6461090a3b396625ull,
0x2509203233732e64ull,0x317225202c333172ull,0x0a3b323135202c33ull,0x3436752e64646109ull,
0x3334316472250920ull,0x333431647225202cull,0x0a3b38343032202cull,0x746c2e7074657309ull,
0x702509203233732eull,0x33317225202c3438ull,0x0a3b39377225202cull,0x6220343870254009ull,
0x5f744c2409206172ull,0x3234343532315f30ull,0x5f305f744c240a3bull,0x0a3a303339343231ull,
0x3436752e766f6d09ull,0x3034316472250920ull,0x616475635f5f202cull,0x747261705f6e695full,
0x316d75735f6c6169ull,0x2e090a3b30303139ull,0x3909323309636f6cull,0x6162090a30093736ull,
0x0920636e79732e72ull,0x636f6c2e090a3b30ull,0x0933373909323309ull,0x732e766f6d090a30ull,
0x3331722509203233ull,0x090a3b357225202cull,0x74736e6f632e646cull,0x722509203233732eull,
0x5f645b202c373234ull,0x342b6e6f6d6d6f63ull,0x6573090a3b5d3434ull,0x33732e65672e7074ull,
0x2c35387025092032ull,0x7225202c35722520ull,0x2540090a3b373234ull,0x2061726220353870ull,
0x315f305f744c2409ull,0x090a3b3837393632ull,0x203436752e766f6dull,0x2c37343164722509ull,
0x5f616475635f5f20ull,0x705f7271735f6e69ull,0x735f6c6169747261ull,0x3b34303339316d75ull,
0x33732e627573090aull,0x3832347225092032ull,0x2c3732347225202cull,0x61090a3b35722520ull,
0x09203233732e6464ull,0x25202c3932347225ull,0x3135202c38323472ull,0x2e726873090a3b31ull,
0x3472250920323373ull,0x32347225202c3033ull,0x090a3b3133202c39ull,0x203233732e766f6dull,
0x202c313334722509ull,0x6e61090a3b313135ull,0x2509203233622e64ull,0x7225202c32333472ull,
0x347225202c303334ull,0x646461090a3b3133ull,0x722509203233732eull,0x347225202c333334ull,
0x32347225202c3233ull,0x2e726873090a3b39ull,0x3472250920323373ull,0x33347225202c3433ull,
0x6c090a3b39202c33ull,0x2e74736e6f632e64ull,0x3472250920323373ull,0x635f645b202c3533ull,
0x34342b6e6f6d6d6full,0x766f6d090a3b5d38ull,0x722509203233732eull,0x0a3b30202c363334ull,
0x74672e7074657309ull,0x702509203233732eull,0x33347225202c3638ull,0x3633347225202c35ull,
0x732e747663090a3bull,0x09203233732e3436ull,0x202c383431647225ull,0x6f6d090a3b357225ull,
0x2509203436732e76ull,0x25202c3934316472ull,0x090a3b3834316472ull,0x752e6f6c2e6c756dull,
0x3164722509203436ull,0x31647225202c3035ull,0x090a3b34202c3834ull,0x203436752e646461ull,
0x2c31353164722509ull,0x2c37343164722520ull,0x3b30353164722520ull,0x33732e766f6d090aull,
0x3733347225092032ull,0x3b3433347225202cull,0x315f305f744c240aull,0x200a3a3039343732ull,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c333739ull,
0x70656420676e6974ull,0x65202c31203a6874ull,0x646574616d697473ull,0x6974617265746920ull,
0x6b6e75203a736e6full,0x2140090a6e776f6eull,0x6172622036387025ull,0x5f305f744c240920ull,
0x0a3b303132383531ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c33373920ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x0a3039343732315full,0x3233732e766f6d09ull,0x2c38333472250920ull,0x0a3b353334722520ull,
0x3436732e766f6d09ull,0x3235316472250920ull,0x393431647225202cull,0x6f632e646c090a3bull,
0x203436752e74736eull,0x2c33353164722509ull,0x312b346472255b20ull,0x7663090a3b5d3832ull,
0x33732e3436732e74ull,0x3531647225092032ull,0x3732347225202c34ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x25202c3535316472ull,0x34202c3435316472ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x25202c3635316472ull,0x34202c3235316472ull,0x752e646461090a3bull,
0x3164722509203436ull,0x31647225202c3735ull,0x31647225202c3335ull,0x766f6d090a3b3635ull,
0x662509203233662eull,0x3030306630202c39ull,0x20203b3030303030ull,0x30202f2f09202020ull,
0x33732e766f6d090aull,0x3933347225092032ull,0x2f2f200a3b30202cull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x373920656e696c20ull,0x2064616568202c33ull,
0x2064656c6562616cull,0x32315f305f744c24ull,0x6f6d090a30393437ull,0x2509203233732e76ull,
0x7225202c30343472ull,0x744c240a3b383334ull,0x35323832315f305full,0x6c3c2f2f200a3a38ull,
0x6f6f4c203e706f6full,0x6c2079646f622070ull,0x2c33373920656e69ull,0x676e697473656e20ull,
0x203a687470656420ull,0x6d69747365202c32ull,0x6574692064657461ull,0x3a736e6f69746172ull,
0x6e776f6e6b6e7520ull,0x3309636f6c2e090aull,0x0a30093937390932ull,0x626f6c672e646c09ull,
0x09203233662e6c61ull,0x255b202c33356625ull,0x5d302b3735316472ull,0x662e646461090a3bull,
0x2c39662509203233ull,0x25202c3335662520ull,0x646461090a3b3966ull,0x722509203233732eull,
0x347225202c393334ull,0x090a3b31202c3933ull,0x203436752e646461ull,0x2c37353164722509ull,
0x2c35353164722520ull,0x3b37353164722520ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x347225202c373870ull,0x33347225202c3533ull,0x38702540090a3b39ull,0x2409206172622037ull,
0x3832315f305f744cull,0x2f2f200a3b383532ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x373920656e696c20ull,0x2064616568202c33ull,0x2064656c6562616cull,
0x32315f305f744c24ull,0x7262090a30393437ull,0x240920696e752e61ull,0x3732315f305f744cull,
0x744c240a3b363437ull,0x31323835315f305full,0x6c3c2f2f200a3a30ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c33373920656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x343732315f305f74ull,0x2e766f6d090a3039ull,0x3966250920323366ull,
0x303030306630202cull,0x2020203b30303030ull,0x0a30202f2f092020ull,0x32315f305f744c24ull,
0x2f200a3a36343737ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3920656e696c2079ull,0x64616568202c3337ull,0x64656c6562616c20ull,0x315f305f744c2420ull,
0x2e090a3039343732ull,0x3909323309636f6cull,0x7473090a30093238ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x2c5d302b31353164ull,0x61090a3b39662520ull,0x09203233732e6464ull,
0x7225202c33317225ull,0x3b323135202c3331ull,0x36732e646461090aull,0x3431647225092034ull,
0x3431647225202c39ull,0x0a3b323135202c39ull,0x3436752e64646109ull,0x3135316472250920ull,
0x313531647225202cull,0x0a3b38343032202cull,0x746c2e7074657309ull,0x702509203233732eull,
0x33317225202c3838ull,0x3b3732347225202cull,0x203838702540090aull,0x744c240920617262ull,
0x39343732315f305full,0x305f744c240a3b30ull,0x3a3837393632315full,0x36752e766f6d090aull,
0x3431647225092034ull,0x6475635f5f202c37ull,0x7271735f6e695f61ull,0x6c6169747261705full,
0x303339316d75735full,0x636f6c2e090a3b34ull,0x0933393909323309ull,0x732e726162090a30ull,
0x0a3b300920636e79ull,0x3233732e766f6d09ull,0x2c31343472250920ull,0x746573090a3b3020ull,
0x3233732e71652e70ull,0x202c393870250920ull,0x347225202c357225ull,0x252140090a3b3134ull,
0x2061726220393870ull,0x315f305f744c2409ull,0x090a3b3238323932ull,0x09323309636f6c2eull,
0x090a300931303031ull,0x203233662e766f6dull,0x30202c3435662509ull,0x3030303030303066ull,
0x2f09202020203b30ull,0x766f6d090a30202full,0x722509203233752eull,0x0a3b30202c323434ull,
0x656c2e7074657309ull,0x702509203233732eull,0x39377225202c3039ull,0x3b3234347225202cull,
0x203039702540090aull,0x744c240920617262ull,0x36343835315f305full,0x2e766f6d090a3b36ull,
0x3472250920323373ull,0x39377225202c3334ull,0x732e766f6d090a3bull,0x3164722509203436ull,
0x31647225202c3835ull,0x766f6d090a3b3034ull,0x722509203233732eull,0x0a3b30202c393334ull,
0x3233732e766f6d09ull,0x2c34343472250920ull,0x0a3b333434722520ull,0x33315f305f744c24ull,
0x2f200a3a30353030ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3120656e696c2079ull,
0x73656e202c313030ull,0x70656420676e6974ull,0x65202c31203a6874ull,0x646574616d697473ull,
0x6974617265746920ull,0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,0x303109323309636full,
0x646c090a30093330ull,0x2e6465726168732eull,0x3566250920323366ull,0x316472255b202c35ull,
0x090a3b5d302b3835ull,0x203233662e646461ull,0x25202c3435662509ull,0x356625202c353566ull,
0x2e646461090a3b34ull,0x3472250920323373ull,0x33347225202c3933ull,0x61090a3b31202c39ull,
0x09203436752e6464ull,0x202c383531647225ull,0x202c383531647225ull,0x70746573090a3b34ull,
0x203233732e656e2eull,0x25202c3139702509ull,0x7225202c39333472ull,0x702540090a3b3937ull,
0x0920617262203139ull,0x33315f305f744c24ull,0x73090a3b30353030ull,0x6465726168732e74ull,
0x695b09203233662eull,0x5f6c616e69665f6eull,0x6625202c5d6d7573ull,0x617262090a3b3435ull,
0x4c240920696e752eull,0x303133315f305f74ull,0x5f744c240a3b3437ull,0x3636343835315f30ull,
0x68732e7473090a3aull,0x3233662e64657261ull,0x69665f6e695b0920ull,0x5d6d75735f6c616eull,
0x0a3b34356625202cull,0x696e752e61726209ull,0x5f305f744c240920ull,0x0a3b343730313331ull,
0x32315f305f744c24ull,0x6d090a3a32383239ull,0x09203233752e766full,0x31202c3534347225ull,
0x2e70746573090a3bull,0x09203233732e656eull,0x7225202c32397025ull,0x3534347225202c35ull,
0x3239702540090a3bull,0x4c24092061726220ull,0x303133315f305f74ull,0x6f6c2e090a3b3437ull,
0x3030310932330963ull,0x766f6d090a300938ull,0x662509203233662eull,0x30306630202c3635ull,
0x203b303030303030ull,0x30202f2f09202020ull,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x5b202c3533347225ull,0x6e6f6d6d6f635f64ull,0x090a3b5d3834342bull,0x203233752e766f6dull,
0x202c363434722509ull,0x70746573090a3b30ull,0x203233732e656c2eull,0x25202c3339702509ull,
0x7225202c35333472ull,0x2540090a3b363434ull,0x2061726220333970ull,0x315f305f744c2409ull,
0x090a3b3232373835ull,0x203233732e766f6dull,0x202c373434722509ull,0x090a3b3533347225ull,
0x203436732e766f6dull,0x2c39353164722509ull,0x3b37343164722520ull,0x33732e766f6d090aull,
0x3933347225092032ull,0x6f6d090a3b30202cull,0x2509203233732e76ull,0x7225202c38343472ull,
0x744c240a3b373434ull,0x38353133315f305full,0x6c3c2f2f200a3a36ull,0x6f6f4c203e706f6full,
0x6c2079646f622070ull,0x3830303120656e69ull,0x6e697473656e202cull,0x3a68747065642067ull,
0x69747365202c3120ull,0x746920646574616dull,0x736e6f6974617265ull,0x776f6e6b6e75203aull,
0x09636f6c2e090a6eull,0x0930313031093233ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c373566250920ull,0x2b3935316472255bull,0x646461090a3b5d30ull,0x662509203233662eull,
0x37356625202c3635ull,0x0a3b36356625202cull,0x3233732e64646109ull,0x2c39333472250920ull,
0x202c393334722520ull,0x2e646461090a3b31ull,0x6472250920343675ull,0x647225202c393531ull,
0x0a3b34202c393531ull,0x656e2e7074657309ull,0x702509203233732eull,0x33347225202c3439ull,
0x3933347225202c35ull,0x3439702540090a3bull,0x4c24092061726220ull,0x353133315f305f74ull,
0x2e7473090a3b3638ull,0x662e646572616873ull,0x5f6e695b09203233ull,0x616e69665f727173ull,
0x202c5d6d75735f6cull,0x62090a3b36356625ull,0x0920696e752e6172ull,0x33315f305f744c24ull,
0x4c240a3b34373031ull,0x373835315f305f74ull,0x2e7473090a3a3232ull,0x662e646572616873ull,
0x5f6e695b09203233ull,0x616e69665f727173ull,0x202c5d6d75735f6cull,0x4c240a3b36356625ull,
0x303133315f305f74ull,0x5f744c240a3a3437ull,0x3236353033315f30ull,0x5f305f744c240a3aull,
0x0a3a363230393231ull,0x323309636f6c2e09ull,0x0a30093931303109ull,0x6e79732e72616209ull,
0x40090a3b30092063ull,0x7262203938702521ull,0x305f744c24092061ull,0x3b3839303233315full,
0x3309636f6c2e090aull,0x3009323330310932ull,0x6e722e747663090aull,0x3233732e3233662eull,
0x202c323466250920ull,0x6c090a3b34317225ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f6e695b202c3835ull,0x75735f6c616e6966ull,0x766964090a3b5d6dull,0x33662e6c6c75662eull,
0x2c39356625092032ull,0x25202c3835662520ull,0x7573090a3b323466ull,0x2509203233732e62ull,
0x7225202c39343472ull,0x090a3b31202c3431ull,0x662e6e722e747663ull,0x09203233732e3233ull,
0x7225202c30366625ull,0x7173090a3b393434ull,0x6f727070612e7472ull,0x2509203233662e78ull,
0x366625202c313666ull,0x732e646c090a3b30ull,0x33662e6465726168ull,0x2c32366625092032ull,
0x7271735f6e695b20ull,0x735f6c616e69665full,0x6964090a3b5d6d75ull,0x662e6c6c75662e76ull,
0x3336662509203233ull,0x202c32366625202cull,0x6d090a3b32346625ull,0x09203233662e6c75ull,
0x6625202c34366625ull,0x39356625202c3935ull,0x662e627573090a3bull,0x3536662509203233ull,
0x202c33366625202cull,0x73090a3b34366625ull,0x727070612e747271ull,0x09203233662e786full,
0x6625202c36366625ull,0x6c756d090a3b3536ull,0x662509203233662eull,0x31366625202c3736ull,
0x0a3b36366625202cull,0x726168732e747309ull,0x09203233662e6465ull,0x5d546d6f6e65645bull,
0x0a3b37366625202cull,0x33315f305f744c24ull,0x2e090a3a38393032ull,0x3109323309636f6cull,
0x62090a3009303430ull,0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x3430310932330963ull,
0x766f6d090a300937ull,0x722509203233732eull,0x3b357225202c3331ull,0x393470252140090aull,
0x4c24092061726220ull,0x363233315f305f74ull,0x627573090a3b3031ull,0x722509203233732eull,
0x327225202c303534ull,0x3b357225202c3634ull,0x33732e646461090aull,0x3135347225092032ull,
0x2c3035347225202cull,0x73090a3b31313520ull,0x09203233732e7268ull,0x25202c3235347225ull,
0x3133202c31353472ull,0x732e766f6d090a3bull,0x3534722509203233ull,0x0a3b313135202c33ull,
0x3233622e646e6109ull,0x2c34353472250920ull,0x202c323534722520ull,0x090a3b3335347225ull,
0x203233732e646461ull,0x202c353534722509ull,0x25202c3435347225ull,0x73090a3b31353472ull,
0x09203233732e7268ull,0x25202c3635347225ull,0x3b39202c35353472ull,0x36752e747663090aull,
0x2509203233732e34ull,0x25202c3036316472ull,0x6c756d090a3b3572ull,0x203436752e6f6c2eull,
0x202c383364722509ull,0x202c303631647225ull,0x632e646c090a3b34ull,0x3436752e74736e6full,
0x3033316472250920ull,0x2b346472255b202cull,0x61090a3b5d303231ull,0x09203436752e6464ull,
0x202c313331647225ull,0x202c303331647225ull,0x090a3b3833647225ull,0x65726168732e646cull,
0x2509203233662e64ull,0x65645b202c383666ull,0x090a3b5d546d6f6eull,0x203233732e766f6dull,
0x202c373534722509ull,0x240a3b3635347225ull,0x3333315f305f744cull,0x2f2f200a3a323231ull,
0x4c203e706f6f6c3cull,0x79646f6220706f6full,0x303120656e696c20ull,0x7473656e202c3734ull,
0x7470656420676e69ull,0x7365202c31203a68ull,0x20646574616d6974ull,0x6f69746172657469ull,
0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x3530310932330963ull,0x2e646c090a300930ull,
0x662e6c61626f6c67ull,0x3936662509203233ull,0x33316472255b202cull,0x2e090a3b5d302b31ull,
0x3109323309636f6cull,0x6c090a3009373430ull,0x6465726168732e64ull,0x662509203233662eull,
0x6e65645b202c3836ull,0x2e090a3b5d546d6full,0x3109323309636f6cull,0x6d090a3009303530ull,
0x09203233662e6c75ull,0x6625202c30376625ull,0x38366625202c3936ull,0x6c672e7473090a3bull,
0x3233662e6c61626full,0x33316472255b0920ull,0x6625202c5d302b31ull,0x646461090a3b3037ull,
0x722509203233732eull,0x33317225202c3331ull,0x090a3b323135202cull,0x203436752e646461ull,
0x2c31333164722509ull,0x2c31333164722520ull,0x090a3b3834303220ull,0x2e746c2e70746573ull,
0x3970250920323373ull,0x2c33317225202c35ull,0x0a3b363432722520ull,0x6220353970254009ull,
0x5f744c2409206172ull,0x3232313333315f30ull,0x5f305f744c240a3bull,0x0a3a303136323331ull,
0x323309636f6c2e09ull,0x0a30093136303109ull,0x6e79732e72616209ull,0x2e090a3b30092063ull,
0x3109323309636f6cull,0x6d090a3009383630ull,0x09203233732e766full,0x7225202c33317225ull,
0x70252140090a3b35ull,0x0920617262203331ull,0x33315f305f744c24ull,0x73090a3b34333633ull,
0x09203233732e6275ull,0x25202c3835347225ull,0x357225202c383772ull,0x732e646461090a3bull,
0x3534722509203233ull,0x3835347225202c39ull,0x090a3b313135202cull,0x203233732e726873ull,
0x202c303634722509ull,0x33202c3935347225ull,0x2e766f6d090a3b31ull,0x3472250920323373ull,
0x3b313135202c3136ull,0x33622e646e61090aull,0x3236347225092032ull,0x2c3036347225202cull,
0x0a3b313634722520ull,0x3233732e64646109ull,0x2c33363472250920ull,0x202c323634722520ull,
0x090a3b3935347225ull,0x203233732e726873ull,0x202c343634722509ull,0x39202c3336347225ull,
0x752e747663090a3bull,0x09203233732e3436ull,0x25202c3336647225ull,0x747663090a3b3572ull,
0x2e3233662e6e722eull,0x3466250920323373ull,0x3b34317225202c32ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c383364ull,0x090a3b34202c3336ull,0x74736e6f632e646cull,
0x722509203436752eull,0x72255b202c353564ull,0x0a3b5d36352b3464ull,0x736e6f632e646c09ull,
0x2509203436752e74ull,0x255b202c38396472ull,0x5d3430312b346472ull,0x752e646461090a3bull,
0x3564722509203436ull,0x3535647225202c36ull,0x3b3833647225202cull,0x36752e646461090aull,
0x3939647225092034ull,0x2c3839647225202cull,0x0a3b383364722520ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x695b202c34356625ull,0x5f6c616e69665f6eull,0x6d090a3b5d6d7573ull,
0x09203233732e766full,0x25202c3536347225ull,0x4c240a3b34363472ull,0x313433315f305f74ull,
0x3c2f2f200a3a3634ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,0x36303120656e696cull,
0x697473656e202c38ull,0x687470656420676eull,0x747365202c31203aull,0x6920646574616d69ull,
0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,0x3137303109323309ull,
0x672e646c090a3009ull,0x33662e6c61626f6cull,0x2c31376625092032ull,0x2b36356472255b20ull,
0x2e646c090a3b5d30ull,0x662e6c61626f6c67ull,0x3237662509203233ull,0x39396472255b202cull,
0x6c2e090a3b5d302bull,0x303109323309636full,0x646c090a30093836ull,0x2e6465726168732eull,
0x3566250920323366ull,0x665f6e695b202c34ull,0x6d75735f6c616e69ull,0x636f6c2e090a3b5dull,
0x3137303109323309ull,0x2e6c756d090a3009ull,0x3766250920323366ull,0x2c32376625202c33ull,
0x090a3b3435662520ull,0x6c6c75662e766964ull,0x662509203233662eull,0x33376625202c3437ull,
0x0a3b32346625202cull,0x3233662e62757309ull,0x202c353766250920ull,0x6625202c31376625ull,
0x2e7473090a3b3437ull,0x662e6c61626f6c67ull,0x6472255b09203233ull,0x25202c5d302b3635ull,
0x6461090a3b353766ull,0x2509203233732e64ull,0x317225202c333172ull,0x0a3b323135202c33ull,
0x3436752e64646109ull,0x2c39396472250920ull,0x202c393964722520ull,0x61090a3b38343032ull,
0x09203436752e6464ull,0x25202c3635647225ull,0x3032202c36356472ull,0x746573090a3b3834ull,
0x3233732e746c2e70ull,0x202c363970250920ull,0x7225202c33317225ull,0x702540090a3b3837ull,
0x0920617262203639ull,0x33315f305f744c24ull,0x4c240a3b36343134ull,0x363333315f305f74ull,
0x6f6c2e090a3a3433ull,0x3830310932330963ull,0x726162090a300932ull,0x300920636e79732eull,
0x09636f6c2e090a3bull,0x0939383031093233ull,0x732e766f6d090a30ull,0x3331722509203233ull,
0x090a3b357225202cull,0x6220393470252140ull,0x5f744c2409206172ull,0x3835363433315f30ull,
0x732e627573090a3bull,0x3634722509203233ull,0x3634327225202c36ull,0x090a3b357225202cull,
0x203233732e646461ull,0x202c373634722509ull,0x35202c3636347225ull,0x726873090a3b3131ull,
0x722509203233732eull,0x347225202c383634ull,0x0a3b3133202c3736ull,0x3233732e766f6d09ull,
0x2c39363472250920ull,0x61090a3b31313520ull,0x09203233622e646eull,0x25202c3037347225ull,
0x7225202c38363472ull,0x6461090a3b393634ull,0x2509203233732e64ull,0x7225202c31373472ull,
0x347225202c303734ull,0x726873090a3b3736ull,0x722509203233732eull,0x347225202c323734ull,
0x090a3b39202c3137ull,0x2e3436752e747663ull,0x6472250920323373ull,0x357225202c313631ull,
0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c38336472ull,0x3b34202c31363164ull,
0x6e6f632e646c090aull,0x09203436752e7473ull,0x202c303331647225ull,0x32312b346472255bull,
0x2e646c090a3b5d30ull,0x36752e74736e6f63ull,0x3535647225092034ull,0x2b346472255b202cull,
0x6461090a3b5d3635ull,0x2509203436752e64ull,0x25202c3133316472ull,0x25202c3033316472ull,
0x61090a3b38336472ull,0x09203436752e6464ull,0x25202c3635647225ull,0x7225202c35356472ull,
0x6f6d090a3b383364ull,0x2509203233732e76ull,0x7225202c33373472ull,0x744c240a3b323734ull,
0x37313533315f305full,0x6c3c2f2f200a3a30ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,
0x3938303120656e69ull,0x6e697473656e202cull,0x3a68747065642067ull,0x69747365202c3120ull,
0x746920646574616dull,0x736e6f6974617265ull,0x776f6e6b6e75203aull,0x09636f6c2e090a6eull,
0x0932393031093233ull,0x6c672e646c090a30ull,0x3233662e6c61626full,0x202c363766250920ull,
0x302b36356472255bull,0x672e646c090a3b5dull,0x33662e6c61626f6cull,0x2c37376625092032ull,
0x3133316472255b20ull,0x6964090a3b5d302bull,0x662e6c6c75662e76ull,0x3837662509203233ull,
0x202c36376625202cull,0x73090a3b37376625ull,0x6c61626f6c672e74ull,0x255b09203233662eull,
0x5d302b3133316472ull,0x0a3b38376625202cull,0x3233732e64646109ull,0x202c333172250920ull,
0x3135202c33317225ull,0x2e646461090a3b32ull,0x6472250920343675ull,0x35647225202c3635ull,
0x3b38343032202c36ull,0x36752e646461090aull,0x3331647225092034ull,0x3331647225202c31ull,
0x3b38343032202c31ull,0x6c2e70746573090aull,0x2509203233732e74ull,0x317225202c373970ull,
0x3634327225202c33ull,0x3739702540090a3bull,0x4c24092061726220ull,0x313533315f305f74ull,
0x5f744c240a3b3037ull,0x3835363433315f30ull,0x09636f6c2e090a3aull,0x0933303131093233ull,
0x732e726162090a30ull,0x0a3b300920636e79ull,0x323309636f6c2e09ull,0x0a30093631313109ull,
0x736e6f632e646c09ull,0x2509203233732e74ull,0x645b202c34373472ull,0x2b6e6f6d6d6f635full,
0x646461090a3b5d34ull,0x722509203233732eull,0x347225202c353734ull,0x31347225202c3437ull,
0x6f632e646c090a3bull,0x203436752e74736eull,0x2c32363164722509ull,0x312b346472255b20ull,
0x2e646c090a3b5d36ull,0x33732e74736e6f63ull,0x3637347225092032ull,0x6d6f635f645b202cull,
0x3b5d36312b6e6f6dull,0x6f6c2e6c756d090aull,0x722509203233732eull,0x347225202c373734ull,
0x3b377225202c3637ull,0x33732e646461090aull,0x3837347225092032ull,0x25202c317225202cull,
0x63090a3b37373472ull,0x732e3436752e7476ull,0x3164722509203233ull,0x37347225202c3336ull,
0x2e6c756d090a3b38ull,0x09203436752e6f6cull,0x25202c3331647225ull,0x34202c3336316472ull,
0x752e646461090a3bull,0x3164722509203436ull,0x31647225202c3436ull,0x31647225202c3236ull,
0x672e646c090a3b33ull,0x33732e6c61626f6cull,0x3937347225092032ull,0x36316472255b202cull,
0x090a3b5d342d2b34ull,0x203233732e646461ull,0x202c303834722509ull,0x25202c3937347225ull,
0x6c090a3b35373472ull,0x6c61626f6c672e64ull,0x722509203233732eull,0x72255b202c313834ull,
0x0a3b5d302b353264ull,0x3233732e62757309ull,0x2c32383472250920ull,0x202c303834722520ull,
0x090a3b3138347225ull,0x09323309636f6c2eull,0x090a300937313131ull,0x74736e6f632e646cull,
0x722509203436752eull,0x255b202c35363164ull,0x3b5d34322b346472ull,0x36752e646461090aull,
0x3631647225092034ull,0x3631647225202c36ull,0x3331647225202c35ull,0x6c672e646c090a3bull,
0x3233732e6c61626full,0x2c33383472250920ull,0x3636316472255b20ull,0x61090a3b5d342d2bull,
0x09203233732e6464ull,0x25202c3438347225ull,0x7225202c33383472ull,0x646c090a3b353734ull,
0x2e6c61626f6c672eull,0x3472250920323373ull,0x6472255b202c3538ull,0x090a3b5d302b3632ull,
0x203233732e627573ull,0x202c363834722509ull,0x25202c3438347225ull,0x2e090a3b35383472ull,
0x3109323309636f6cull,0x6d090a3009323231ull,0x09203233732e766full,0x7225202c33317225ull,
0x632e646c090a3b35ull,0x3233732e74736e6full,0x2c37383472250920ull,0x6d6d6f635f645b20ull,
0x3b5d3836342b6e6full,0x672e70746573090aull,0x2509203233732e65ull,0x357225202c383970ull,
0x3b3738347225202cull,0x203839702540090aull,0x744c240920617262ull,0x38363533315f305full,
0x2e627573090a3b32ull,0x3472250920323373ull,0x38347225202c3838ull,0x0a3b357225202c37ull,
0x3233732e64646109ull,0x2c39383472250920ull,0x202c383834722520ull,0x6873090a3b313135ull,
0x2509203233732e72ull,0x7225202c30393472ull,0x3b3133202c393834ull,0x33732e766f6d090aull,
0x3139347225092032ull,0x090a3b313135202cull,0x203233622e646e61ull,0x202c323934722509ull,
0x25202c3039347225ull,0x61090a3b31393472ull,0x09203233732e6464ull,0x25202c3339347225ull,
0x7225202c32393472ull,0x6873090a3b393834ull,0x2509203233732e72ull,0x7225202c34393472ull,
0x0a3b39202c333934ull,0x3436752e74766309ull,0x722509203233732eull,0x357225202c333664ull,
0x6f632e646c090a3bull,0x203233732e74736eull,0x202c353934722509ull,0x6f6d6d6f635f645bull,
0x0a3b5d3036342b6eull,0x2e6f6c2e6c756d09ull,0x3472250920323373ull,0x39347225202c3639ull,
0x3638347225202c35ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c38336472ull,
0x0a3b34202c333664ull,0x3233732e64646109ull,0x2c37393472250920ull,0x202c363934722520ull,
0x090a3b3238347225ull,0x74736e6f632e646cull,0x722509203436752eull,0x255b202c37363164ull,
0x5d3633312b346472ull,0x752e646461090a3bull,0x3164722509203436ull,0x31647225202c3836ull,
0x33647225202c3736ull,0x2e766f6d090a3b38ull,0x3472250920323373ull,0x39347225202c3839ull,
0x305f744c240a3b34ull,0x3a3439313633315full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,
0x6e696c2079646f62ull,0x202c323231312065ull,0x20676e697473656eull,0x31203a6874706564ull,
0x616d69747365202cull,0x7265746920646574ull,0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,
0x323309636f6c2e09ull,0x0a30093532313109ull,0x3233662e766f6d09ull,0x202c393766250920ull,
0x3030303866336630ull,0x09202020203b3030ull,0x6f6d090a31202f2full,0x2509203233662e76ull,
0x306630202c303866ull,0x3b30303030303030ull,0x202f2f0920202020ull,0x2e70746573090a30ull,
0x09203233732e7165ull,0x7225202c39397025ull,0x317225202c373934ull,0x706c6573090a3b33ull,
0x662509203233662eull,0x39376625202c3138ull,0x202c30386625202cull,0x73090a3b39397025ull,
0x6c61626f6c672e74ull,0x255b09203233662eull,0x5d302b3836316472ull,0x0a3b31386625202cull,
0x3233732e64646109ull,0x202c333172250920ull,0x3135202c33317225ull,0x2e646461090a3b32ull,
0x6472250920343675ull,0x647225202c383631ull,0x343032202c383631ull,0x70746573090a3b38ull,
0x203233732e746c2eull,0x202c303031702509ull,0x7225202c33317225ull,0x2540090a3b373834ull,
0x6172622030303170ull,0x5f305f744c240920ull,0x0a3b343931363331ull,0x33315f305f744c24ull,
0x2e090a3a32383635ull,0x3109323309636f6cull,0x62090a3009333431ull,0x20636e79732e7261ull,
0x6f6c2e090a3b3009ull,0x3531310932330963ull,0x766f6d090a300930ull,0x722509203233732eull,
0x3b357225202c3331ull,0x6e6f632e646c090aull,0x09203233732e7473ull,0x5b202c3939347225ull,
0x6e6f6d6d6f635f64ull,0x090a3b5d3030352bull,0x2e65672e70746573ull,0x3170250920323373ull,
0x2c357225202c3130ull,0x0a3b393934722520ull,0x736e6f632e646c09ull,0x2509203233732e74ull,
0x645b202c30303572ull,0x2b6e6f6d6d6f635full,0x40090a3b5d323934ull,0x7262203130317025ull,
0x305f744c24092061ull,0x3b3230303036315full,0x33732e627573090aull,0x3130357225092032ull,
0x2c3939347225202cull,0x61090a3b35722520ull,0x09203233732e6464ull,0x25202c3230357225ull,
0x3135202c31303572ull,0x2e726873090a3b31ull,0x3572250920323373ull,0x30357225202c3330ull,
0x090a3b3133202c32ull,0x203233732e766f6dull,0x202c343035722509ull,0x6e61090a3b313135ull,
0x2509203233622e64ull,0x7225202c35303572ull,0x357225202c333035ull,0x646461090a3b3430ull,
0x722509203233732eull,0x357225202c363035ull,0x30357225202c3530ull,0x2e726873090a3b32ull,
0x3572250920323373ull,0x30357225202c3730ull,0x63090a3b39202c36ull,0x732e3436752e7476ull,
0x3164722509203233ull,0x3b357225202c3936ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c383364ull,0x0a3b34202c393631ull,0x736e6f632e646c09ull,0x2509203436752e74ull,
0x5b202c3037316472ull,0x3235312b34647225ull,0x632e646c090a3b5dull,0x3436752e74736e6full,
0x3033316472250920ull,0x2b346472255b202cull,0x61090a3b5d303231ull,0x09203436752e6464ull,
0x202c313731647225ull,0x202c303731647225ull,0x090a3b3833647225ull,0x203436752e646461ull,
0x2c31333164722509ull,0x2c30333164722520ull,0x0a3b383364722520ull,0x736e6f632e646c09ull,
0x2509203233732e74ull,0x645b202c38303572ull,0x2b6e6f6d6d6f635full,0x6c090a3b5d343634ull,
0x2e74736e6f632e64ull,0x3572250920323373ull,0x635f645b202c3930ull,0x38342b6e6f6d6d6full,
0x2e646c090a3b5d30ull,0x33732e74736e6f63ull,0x3031357225092032ull,0x6d6f635f645b202cull,
0x5d3231352b6e6f6dull,0x732e766f6d090a3bull,0x3135722509203233ull,0x3730357225202c31ull,
0x5f305f744c240a3bull,0x0a3a383132373331ull,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,
0x656e696c2079646full,0x6e202c3035313120ull,0x6420676e69747365ull,0x2c31203a68747065ull,
0x74616d6974736520ull,0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,
0x09323309636f6c2eull,0x090a300934353131ull,0x203233732e646461ull,0x25202c3532722509ull,
0x0a3b31202c333172ull,0x3233732e6d657209ull,0x2c32313572250920ull,0x25202c3532722520ull,
0x6d090a3b30303572ull,0x09203233732e766full,0x7225202c32397225ull,0x6c2e090a3b323135ull,
0x313109323309636full,0x6964090a30093535ull,0x2509203233732e76ull,0x7225202c33313572ull,
0x30357225202c3532ull,0x2e646461090a3b30ull,0x3972250920323373ull,0x3331357225202c34ull,
0x6f6d090a3b31202cull,0x2509203233752e76ull,0x3b30202c34313572ull,0x6e2e70746573090aull,
0x2509203233732e65ull,0x7225202c32303170ull,0x357225202c323135ull,0x702540090a3b3431ull,
0x2061726220323031ull,0x315f305f744c2409ull,0x200a3b3437343733ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x6568202c30353131ull,
0x6c6562616c206461ull,0x305f744c24206465ull,0x0a3831323733315full,0x323309636f6c2e09ull,
0x0a30093735313109ull,0x3233732e766f6d09ull,0x202c323972250920ull,0x090a3b3030357225ull,
0x09323309636f6c2eull,0x090a300938353131ull,0x203233732e766f6dull,0x25202c3439722509ull,
0x4c240a3b33313572ull,0x343733315f305f74ull,0x3c2f2f200a3a3437ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x35313120656e696cull,0x2064616568202c30ull,
0x2064656c6562616cull,0x33315f305f744c24ull,0x6c2e090a38313237ull,0x313109323309636full,
0x6461090a30093539ull,0x2509203233732e64ull,0x7225202c35313572ull,0x31357225202c3439ull,
0x2e646461090a3b30ull,0x3572250920323373ull,0x31357225202c3631ull,0x73090a3b31202c35ull,
0x09203233732e6275ull,0x25202c3731357225ull,0x7225202c35313572ull,0x6573090a3b393035ull,
0x33732e74672e7074ull,0x3330317025092032ull,0x2c3631357225202cull,0x0a3b393035722520ull,
0x3233732e64646109ull,0x2c38313572250920ull,0x202c373135722520ull,0x2e766f6d090a3b31ull,
0x3572250920323373ull,0x090a3b31202c3931ull,0x3233732e706c6573ull,0x2c30323572250920ull,
0x202c383135722520ull,0x25202c3931357225ull,0x6d090a3b33303170ull,0x09203233732e766full,
0x25202c3230317225ull,0x73090a3b30323572ull,0x732e74672e707465ull,0x3031702509203233ull,
0x3531357225202c34ull,0x3b3830357225202cull,0x732e706c6573090aull,0x3235722509203233ull,
0x3830357225202c31ull,0x2c3531357225202cull,0x0a3b343031702520ull,0x746c2e7074657309ull,
0x702509203233732eull,0x357225202c353031ull,0x32357225202c3132ull,0x31702540090a3b30ull,
0x0920617262203530ull,0x36315f305f744c24ull,0x2f200a3b38353230ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x616568202c303531ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x090a383132373331ull,0x74736e6f632e646cull,
0x722509203233732eull,0x5f645b202c323235ull,0x352b6e6f6d6d6f63ull,0x6461090a3b5d3830ull,
0x2509203233732e64ull,0x7225202c33323572ull,0x32357225202c3239ull,0x632e646c090a3b32ull,
0x3233732e74736e6full,0x2c34323572250920ull,0x6d6d6f635f645b20ull,0x3b5d3036342b6e6full,
0x672e70746573090aull,0x2509203233732e74ull,0x7225202c36303170ull,0x357225202c333235ull,
0x6c6573090a3b3432ull,0x2509203233732e70ull,0x7225202c35323572ull,0x357225202c343235ull,
0x30317025202c3332ull,0x2e627573090a3b36ull,0x3572250920323373ull,0x32357225202c3632ull,
0x3032357225202c31ull,0x732e646461090a3bull,0x3235722509203233ull,0x3632357225202c37ull,
0x6461090a3b31202cull,0x2509203233732e64ull,0x7225202c38323572ull,0x0a3b31202c333235ull,
0x736e6f632e646c09ull,0x2509203233732e74ull,0x645b202c39323572ull,0x2b6e6f6d6d6f635full,
0x73090a3b5d363734ull,0x09203233732e6275ull,0x25202c3033357225ull,0x7225202c33323572ull,
0x6573090a3b393235ull,0x33732e74672e7074ull,0x3730317025092032ull,0x2c3832357225202cull,
0x0a3b393235722520ull,0x3233732e64646109ull,0x2c31333572250920ull,0x202c303335722520ull,
0x2e646461090a3b31ull,0x3572250920323373ull,0x32357225202c3233ull,0x6d090a3b31202c31ull,
0x09203233732e766full,0x31202c3333357225ull,0x2e706c6573090a3bull,0x3572250920323373ull,
0x33357225202c3433ull,0x3333357225202c31ull,0x3b3730317025202cull,0x672e70746573090aull,
0x2509203233732e65ull,0x7225202c38303170ull,0x357225202c353235ull,0x766f6d090a3b3433ull,
0x662509203233662eull,0x3030306630202c34ull,0x20203b3030303030ull,0x30202f2f09202020ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x202c303531312065ull,0x62616c2064616568ull,0x744c242064656c65ull,0x31323733315f305full,
0x732e766f6d090a38ull,0x3335722509203233ull,0x3732357225202c35ull,0x5f305f744c240a3bull,
0x0a3a383934383331ull,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x6e202c3539313120ull,0x6420676e69747365ull,0x2c32203a68747065ull,0x74616d6974736520ull,
0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,0x2038303170252140ull,
0x744c240920617262ull,0x35373833315f305full,0x6c3c2f2f200a3b34ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x3539313120656e69ull,0x6c2064616568202cull,
0x242064656c656261ull,0x3833315f305f744cull,0x627573090a383934ull,0x722509203233732eull,
0x357225202c363335ull,0x33357225202c3532ull,0x2e646461090a3b34ull,0x3572250920323373ull,
0x33357225202c3733ull,0x6d090a3b31202c36ull,0x33732e6f6c2e6c75ull,0x3833357225092032ull,
0x2c3230317225202cull,0x0a3b343235722520ull,0x3233732e67656e09ull,0x2c39333572250920ull,
0x0a3b343235722520ull,0x3233732e64646109ull,0x2c30343572250920ull,0x202c383335722520ull,
0x090a3b3933357225ull,0x203233732e646461ull,0x202c313435722509ull,0x25202c3034357225ull,
0x6c090a3b34333572ull,0x2e74736e6f632e64ull,0x6472250920343675ull,0x72255b202c323731ull,
0x3b5d3633312b3464ull,0x33732e646461090aull,0x3234357225092032ull,0x2c3532357225202cull,
0x646461090a3b3120ull,0x722509203233732eull,0x357225202c333435ull,0x34357225202c3034ull,
0x2e747663090a3b32ull,0x203233732e343673ull,0x2c33373164722509ull,0x0a3b313435722520ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x647225202c343731ull,0x0a3b34202c333731ull,
0x3436752e64646109ull,0x3537316472250920ull,0x323731647225202cull,0x343731647225202cull,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x2c3539313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,0x343833315f305f74ull,
0x2e766f6d090a3839ull,0x3572250920323373ull,0x33357225202c3434ull,0x305f744c240a3b37ull,
0x3a3636323933315full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,
0x202c353931312065ull,0x20676e697473656eull,0x33203a6874706564ull,0x616d69747365202cull,
0x7265746920646574ull,0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,0x323309636f6c2e09ull,
0x0a30093939313109ull,0x626f6c672e646c09ull,0x09203233662e6c61ull,0x255b202c32386625ull,
0x342d2b3537316472ull,0x2e646461090a3b5dull,0x3466250920323366ull,0x202c32386625202cull,
0x6461090a3b346625ull,0x2509203233732e64ull,0x7225202c31343572ull,0x0a3b31202c313435ull,
0x3436752e64646109ull,0x3537316472250920ull,0x353731647225202cull,0x6573090a3b34202cull,
0x33732e656e2e7074ull,0x3930317025092032ull,0x2c3134357225202cull,0x0a3b333435722520ull,
0x2039303170254009ull,0x744c240920617262ull,0x36323933315f305full,0x305f744c240a3b36ull,
0x3a3435373833315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x202c353931312065ull,0x62616c2064616568ull,0x744c242064656c65ull,
0x39343833315f305full,0x732e646461090a38ull,0x3031722509203233ull,0x3230317225202c32ull,
0x6573090a3b31202cull,0x33732e656e2e7074ull,0x3031317025092032ull,0x2c3233357225202cull,
0x0a3b323031722520ull,0x2030313170254009ull,0x744c240920617262ull,0x39343833315f305full,
0x6c3c2f2f200a3b38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x3035313120656e69ull,0x6c2064616568202cull,0x242064656c656261ull,0x3733315f305f744cull,
0x617262090a383132ull,0x4c240920696e752eull,0x393733315f305f74ull,0x5f744c240a3b3638ull,
0x3835323036315f30ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x2c3035313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,
0x323733315f305f74ull,0x2e766f6d090a3831ull,0x3466250920323366ull,0x303030306630202cull,
0x2020203b30303030ull,0x0a30202f2f092020ull,0x33315f305f744c24ull,0x2f200a3a36383937ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x616568202c303531ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x090a383132373331ull,
0x09323309636f6c2eull,0x090a300934303231ull,0x61626f6c672e646cull,0x2509203233662e6cull,
0x72255b202c333866ull,0x3b5d302b31333164ull,0x33662e6c756d090aull,0x2c34386625092032ull,
0x25202c3338662520ull,0x2e7473090a3b3466ull,0x662e6c61626f6c67ull,0x6472255b09203233ull,
0x202c5d302b313731ull,0x61090a3b34386625ull,0x09203233732e6464ull,0x7225202c33317225ull,
0x3b323135202c3331ull,0x36752e646461090aull,0x3331647225092034ull,0x3331647225202c31ull,
0x3b38343032202c31ull,0x36752e646461090aull,0x3731647225092034ull,0x3731647225202c31ull,
0x3b38343032202c31ull,0x6c2e70746573090aull,0x2509203233732e74ull,0x7225202c31313170ull,
0x39347225202c3331ull,0x31702540090a3b39ull,0x0920617262203131ull,0x33315f305f744c24ull,
0x62090a3b38313237ull,0x0920696e752e6172ull,0x33315f305f744c24ull,0x4c240a3b36303736ull,
0x303036315f305f74ull,0x5f744c240a3a3230ull,0x3630373633315f30ull,0x09636f6c2e090a3aull,
0x0935313231093233ull,0x732e726162090a30ull,0x0a3b300920636e79ull,0x323309636f6c2e09ull,
0x0a30093532323109ull,0x3233732e766f6d09ull,0x202c333172250920ull,0x6573090a3b357225ull,
0x33732e65672e7074ull,0x3231317025092032ull,0x25202c357225202cull,0x40090a3b30303572ull,
0x7262203231317025ull,0x305f744c24092061ull,0x3b3039323034315full,0x36752e766f6d090aull,
0x3731647225092034ull,0x6475635f5f202c36ull,0x616d5f7261705f61ull,0x3539316f6f635f78ull,
0x766f6d090a3b3830ull,0x722509203436752eull,0x5f5f202c37373164ull,0x7261705f61647563ull,
0x6c61765f78616d5full,0x090a3b3233303032ull,0x203233732e627573ull,0x202c353435722509ull,
0x25202c3030357225ull,0x646461090a3b3572ull,0x722509203233732eull,0x357225202c363435ull,
0x3b313135202c3534ull,0x33732e726873090aull,0x3734357225092032ull,0x2c3634357225202cull,
0x6f6d090a3b313320ull,0x2509203233732e76ull,0x3135202c38343572ull,0x2e646e61090a3b31ull,
0x3572250920323362ull,0x34357225202c3934ull,0x3834357225202c37ull,0x732e646461090a3bull,
0x3535722509203233ull,0x3934357225202c30ull,0x3b3634357225202cull,0x33732e726873090aull,
0x3135357225092032ull,0x2c3035357225202cull,0x2e646c090a3b3920ull,0x33732e74736e6f63ull,
0x3235357225092032ull,0x6d6f635f645b202cull,0x5d3639342b6e6f6dull,0x732e766f6d090a3bull,
0x3535722509203233ull,0x73090a3b30202c33ull,0x732e74672e707465ull,0x3131702509203233ull,
0x3235357225202c33ull,0x3b3335357225202cull,0x36732e747663090aull,0x2509203233732e34ull,
0x25202c3837316472ull,0x6c756d090a3b3572ull,0x203436752e6f6c2eull,0x2c39373164722509ull,
0x2c38373164722520ull,0x646461090a3b3420ull,0x722509203436752eull,0x7225202c30383164ull,
0x7225202c39373164ull,0x61090a3b36373164ull,0x09203436752e6464ull,0x202c313831647225ull,
0x202c393731647225ull,0x0a3b373731647225ull,0x3233732e766f6d09ull,0x2c34353572250920ull,
0x766f6d090a3b3020ull,0x662509203233662eull,0x30306630202c3538ull,0x203b303030303030ull,
0x30202f2f09202020ull,0x33732e766f6d090aull,0x3535357225092032ull,0x3b3135357225202cull,
0x315f305f744c240aull,0x200a3a3230383034ull,0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,
0x20656e696c207964ull,0x656e202c35323231ull,0x656420676e697473ull,0x202c31203a687470ull,
0x6574616d69747365ull,0x7461726574692064ull,0x6e75203a736e6f69ull,0x40090a6e776f6e6bull,
0x6220333131702521ull,0x5f744c2409206172ull,0x3835303134315f30ull,0x6f6c3c2f2f200a3bull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x2c3532323120656eull,
0x616c206461656820ull,0x4c242064656c6562ull,0x383034315f305f74ull,0x2e766f6d090a3230ull,
0x3572250920323373ull,0x35357225202c3635ull,0x2e6c756d090a3b32ull,0x09203233732e6f6cull,
0x25202c3735357225ull,0x357225202c333172ull,0x766f6d090a3b3030ull,0x722509203233732eull,
0x357225202c383535ull,0x646461090a3b3735ull,0x722509203233732eull,0x357225202c393535ull,
0x35357225202c3735ull,0x632e646c090a3b32ull,0x3436752e74736e6full,0x3238316472250920ull,
0x2b346472255b202cull,0x63090a3b5d323531ull,0x732e3436752e7476ull,0x3164722509203233ull,
0x35357225202c3338ull,0x2e6c756d090a3b37ull,0x09203436752e6f6cull,0x202c343831647225ull,
0x202c333831647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x647225202c353831ull,
0x647225202c323831ull,0x2f2f200a3b343831ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x323120656e696c20ull,0x64616568202c3532ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x6d090a3230383034ull,0x09203233732e766full,0x25202c3036357225ull,
0x4c240a3b36353572ull,0x353134315f305f74ull,0x3c2f2f200a3a3037ull,0x6f4c203e706f6f6cull,
0x2079646f6220706full,0x32323120656e696cull,0x697473656e202c35ull,0x687470656420676eull,
0x747365202c32203aull,0x6920646574616d69ull,0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,
0x636f6c2e090a6e77ull,0x3033323109323309ull,0x672e646c090a3009ull,0x33662e6c61626f6cull,
0x2c36386625092032ull,0x3538316472255b20ull,0x6261090a3b5d302bull,0x2509203233662e73ull,
0x386625202c373866ull,0x70746573090a3b36ull,0x203233662e74672eull,0x202c343131702509ull,
0x6625202c37386625ull,0x252140090a3b3538ull,0x6172622034313170ull,0x5f305f744c240920ull,
0x0a3b363238313431ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x68202c3532323120ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x3037353134315f30ull,0x3309636f6c2e090aull,0x3009323332310932ull,0x33732e766f6d090aull,
0x3435357225092032ull,0x3b3835357225202cull,0x3309636f6c2e090aull,0x3009333332310932ull,
0x33662e766f6d090aull,0x2c35386625092032ull,0x240a3b3738662520ull,0x3134315f305f744cull,
0x2f2f200a3a363238ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x323120656e696c20ull,0x64616568202c3532ull,0x64656c6562616c20ull,0x315f305f744c2420ull,
0x61090a3037353134ull,0x09203233732e6464ull,0x25202c3835357225ull,0x3b31202c38353572ull,
0x36752e646461090aull,0x3831647225092034ull,0x3831647225202c35ull,0x73090a3b34202c35ull,
0x732e656e2e707465ull,0x3131702509203233ull,0x3835357225202c35ull,0x3b3935357225202cull,
0x353131702540090aull,0x4c24092061726220ull,0x353134315f305f74ull,0x5f744c240a3b3037ull,
0x3835303134315f30ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x2c3532323120656eull,0x616c206461656820ull,0x4c242064656c6562ull,
0x383034315f305f74ull,0x636f6c2e090a3230ull,0x3633323109323309ull,0x732e7473090a3009ull,
0x33732e6465726168ull,0x316472255b092032ull,0x25202c5d302b3038ull,0x2e090a3b34353572ull,
0x3109323309636f6cull,0x73090a3009373332ull,0x6465726168732e74ull,0x255b09203233662eull,
0x5d302b3138316472ull,0x0a3b35386625202cull,0x3233732e64646109ull,0x202c333172250920ull,
0x3135202c33317225ull,0x2e646461090a3b32ull,0x6472250920343675ull,0x647225202c313831ull,
0x343032202c313831ull,0x2e646461090a3b38ull,0x6472250920343675ull,0x647225202c303831ull,
0x343032202c303831ull,0x70746573090a3b38ull,0x203233732e746c2eull,0x202c363131702509ull,
0x7225202c33317225ull,0x2540090a3b303035ull,0x6172622036313170ull,0x5f305f744c240920ull,
0x0a3b323038303431ull,0x34315f305f744c24ull,0x6d090a3a30393230ull,0x09203436752e766full,
0x202c363731647225ull,0x705f616475635f5full,0x635f78616d5f7261ull,0x3b38303539316f6full,
0x36752e766f6d090aull,0x3731647225092034ull,0x6475635f5f202c37ull,0x616d5f7261705f61ull,
0x3030326c61765f78ull,0x6f6c2e090a3b3233ull,0x3432310932330963ull,0x726162090a300938ull,
0x300920636e79732eull,0x3870252140090a3bull,0x2409206172622039ull,0x3234315f305f744cull,
0x6f6d090a3b303538ull,0x2509203233752e76ull,0x3b30202c31363572ull,0x6c2e70746573090aull,
0x2509203233732e65ull,0x7225202c37313170ull,0x357225202c303035ull,0x766f6d090a3b3136ull,
0x722509203233732eull,0x0a3b30202c323635ull,0x2037313170254009ull,0x744c240920617262ull,
0x38323136315f305full,0x2e766f6d090a3b32ull,0x3572250920323373ull,0x30357225202c3336ull,
0x2e766f6d090a3b30ull,0x6472250920343675ull,0x0a3b30202c363831ull,0x3436732e766f6d09ull,
0x3738316472250920ull,0x373731647225202cull,0x732e766f6d090a3bull,0x3334722509203233ull,
0x6d090a3b30202c39ull,0x09203233662e766full,0x6630202c38386625ull,0x3030303030303030ull,
0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3572250920323373ull,0x36357225202c3436ull,
0x305f744c240a3b33ull,0x3a3437383334315full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,
0x6e696c2079646f62ull,0x202c383432312065ull,0x20676e697473656eull,0x31203a6874706564ull,
0x616d69747365202cull,0x7265746920646574ull,0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c39386625ull,0x5d302b3738316472ull,
0x2e70746573090a3bull,0x09203233662e7467ull,0x25202c3831317025ull,0x386625202c393866ull,
0x70252140090a3b38ull,0x2061726220383131ull,0x315f305f744c2409ull,0x200a3b3033313434ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x6568202c38343231ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x0a3437383334315full,
0x323309636f6c2e09ull,0x0a30093835323109ull,0x3233662e766f6d09ull,0x202c383866250920ull,
0x2e090a3b39386625ull,0x3109323309636f6cull,0x61090a3009393532ull,0x09203436752e6464ull,
0x202c383831647225ull,0x202c363831647225ull,0x0a3b363731647225ull,0x726168732e646c09ull,
0x09203233732e6465ull,0x5b202c3236357225ull,0x302b383831647225ull,0x305f744c240a3b5dull,
0x3a3033313434315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x202c383432312065ull,0x62616c2064616568ull,0x744c242064656c65ull,
0x37383334315f305full,0x732e646461090a34ull,0x3334722509203233ull,0x3933347225202c39ull,
0x6461090a3b31202cull,0x2509203436752e64ull,0x25202c3638316472ull,0x34202c3638316472ull,
0x752e646461090a3bull,0x3164722509203436ull,0x31647225202c3738ull,0x090a3b34202c3738ull,
0x2e656e2e70746573ull,0x3170250920323373ull,0x30357225202c3931ull,0x3933347225202c30ull,
0x3131702540090a3bull,0x2409206172622039ull,0x3334315f305f744cull,0x7262090a3b343738ull,
0x240920696e752e61ull,0x3334315f305f744cull,0x744c240a3b323633ull,0x38323136315f305full,
0x305f744c240a3a32ull,0x3a3236333334315full,0x3309636f6c2e090aull,0x3009343632310932ull,
0x33732e646461090aull,0x3536357225092032ull,0x2c3236357225202cull,0x6d6572090a3b3120ull,
0x722509203233732eull,0x357225202c363635ull,0x30357225202c3536ull,0x2e627573090a3b30ull,
0x3572250920323373ull,0x36357225202c3736ull,0x2e090a3b31202c36ull,0x3109323309636f6cull,
0x64090a3009353632ull,0x09203233732e7669ull,0x25202c3836357225ull,0x7225202c35363572ull,
0x6f6d090a3b303035ull,0x2509203233752e76ull,0x3b30202c39363572ull,0x6e2e70746573090aull,
0x2509203233732e65ull,0x7225202c30323170ull,0x357225202c363635ull,0x702540090a3b3936ull,
0x2061726220303231ull,0x315f305f744c2409ull,0x090a3b3839383434ull,0x09323309636f6c2eull,
0x090a300937363231ull,0x203233732e627573ull,0x202c373635722509ull,0x31202c3030357225ull,
0x09636f6c2e090a3bull,0x0938363231093233ull,0x732e627573090a30ull,0x3635722509203233ull,
0x3836357225202c38ull,0x744c240a3b31202cull,0x39383434315f305full,0x636f6c2e090a3a38ull,
0x3737323109323309ull,0x2e627573090a3009ull,0x3572250920323373ull,0x31347225202c3037ull,
0x3b3437347225202cull,0x6f6c672e646c090aull,0x203233732e6c6162ull,0x202c313735722509ull,
0x302b35326472255bull,0x632e646c090a3b5dull,0x3233732e74736e6full,0x2c32373572250920ull,
0x6d6d6f635f645b20ull,0x3b5d3430322b6e6full,0x33732e627573090aull,0x3337357225092032ull,
0x2c3736357225202cull,0x0a3b323735722520ull,0x3233732e62757309ull,0x2c34373572250920ull,
0x202c333735722520ull,0x090a3b3037357225ull,0x203233732e646461ull,0x202c353735722509ull,
0x25202c3137357225ull,0x61090a3b34373572ull,0x09203233732e6464ull,0x25202c3637357225ull,
0x3b31202c35373572ull,0x6f6c672e7473090aull,0x203233732e6c6162ull,0x3436316472255b09ull,
0x357225202c5d302bull,0x6f6c2e090a3b3637ull,0x3732310932330963ull,0x2e646c090a300938ull,
0x732e6c61626f6c67ull,0x3735722509203233ull,0x326472255b202c37ull,0x73090a3b5d302b36ull,
0x09203233732e6275ull,0x25202c3837357225ull,0x7225202c38363572ull,0x627573090a3b3937ull,
0x722509203233732eull,0x357225202c393735ull,0x37357225202c3837ull,0x2e646461090a3b30ull,
0x3572250920323373ull,0x37357225202c3038ull,0x3937357225202c37ull,0x732e646461090a3bull,
0x3835722509203233ull,0x3038357225202c31ull,0x7473090a3b31202cull,0x2e6c61626f6c672eull,
0x72255b0920323373ull,0x2c5d302b36363164ull,0x0a3b313835722520ull,0x34315f305f744c24ull,
0x2e090a3a30353832ull,0x3109323309636f6cull,0x62090a3009363832ull,0x20636e79732e7261ull,
0x5f744c240a3b3009ull,0x3a32343037385f30ull,0x732e706c6573090aull,0x3835722509203233ull,
0x2c30202c31202c32ull,0x6d090a3b36702520ull,0x09203233732e766full,0x2d202c3338357225ull,
0x3534333939383538ull,0x2e766f6d090a3b39ull,0x3572250920323373ull,0x090a3b30202c3438ull,
0x2e746c2e70746573ull,0x3170250920323373ull,0x2c317225202c3132ull,0x0a3b343835722520ull,
0x3233732e73626109ull,0x2c35383572250920ull,0x6d090a3b31722520ull,0x33752e69682e6c75ull,
0x3638357225092032ull,0x2c3538357225202cull,0x0a3b333835722520ull,0x3233732e72687309ull,
0x2c37383572250920ull,0x202c363835722520ull,0x31702540090a3b33ull,0x732e627573203132ull,
0x3835722509203233ull,0x3438357225202c37ull,0x3b3738357225202cull,0x33732e766f6d090aull,
0x3838357225092032ull,0x3b3738357225202cull,0x6f6c2e6c756d090aull,0x722509203233732eull,
0x357225202c393835ull,0x0a3b3031202c3838ull,0x3233732e62757309ull,0x2c30393572250920ull,
0x7225202c31722520ull,0x6f6d090a3b393835ull,0x2509203233732e76ull,0x3b30202c31393572ull,
0x71652e746573090aull,0x3233732e3233752eull,0x2c32393572250920ull,0x202c303935722520ull,
0x090a3b3139357225ull,0x203233732e67656eull,0x202c333935722509ull,0x090a3b3239357225ull,
0x203233622e646e61ull,0x202c343935722509ull,0x25202c3238357225ull,0x6d090a3b33393572ull,
0x09203233752e766full,0x30202c3539357225ull,0x2e70746573090a3bull,0x09203233732e7165ull,
0x25202c3232317025ull,0x7225202c34393572ull,0x2540090a3b353935ull,0x6172622032323170ull,
0x5f305f744c240920ull,0x0a3b323239353431ull,0x323309636f6c2e09ull,0x0a30093330333109ull,
0x3233732e74766309ull,0x722509203631752eull,0x746325202c363935ull,0x090a3b782e646961ull,
0x2e3436732e747663ull,0x6472250920323373ull,0x357225202c393831ull,0x6c756d090a3b3639ull,
0x203436752e6f6c2eull,0x2c30393164722509ull,0x2c39383164722520ull,0x61090a3b30363120ull,
0x09203436752e6464ull,0x7225202c34647225ull,0x31647225202c3164ull,0x2e646c090a3b3039ull,
0x33732e74736e6f63ull,0x202c377225092032ull,0x30342b346472255bull,0x632e646c090a3b5dull,
0x3436752e74736e6full,0x2c32326472250920ull,0x302b346472255b20ull,0x632e646c090a3b5dull,
0x3233732e74736e6full,0x2c37393572250920ull,0x6d6d6f635f645b20ull,0x0a3b5d36312b6e6full,
0x2e6f6c2e6c756d09ull,0x3572250920323373ull,0x39357225202c3839ull,0x0a3b377225202c37ull,
0x3436752e74766309ull,0x722509203233732eull,0x7225202c31393164ull,0x2e646461090a3b37ull,
0x3572250920323373ull,0x39357225202c3939ull,0x0a3b317225202c38ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x31647225202c3131ull,0x090a3b34202c3139ull,0x2e3436752e747663ull,
0x6472250920323373ull,0x357225202c323931ull,0x646461090a3b3939ull,0x722509203436752eull,
0x647225202c353264ull,0x31647225202c3232ull,0x2e6c756d090a3b31ull,0x09203436752e6f6cull,
0x25202c3331647225ull,0x34202c3239316472ull,0x6f632e646c090a3bull,0x203436752e74736eull,
0x2c33393164722509ull,0x312b346472255b20ull,0x646461090a3b5d36ull,0x722509203436752eull,
0x7225202c34393164ull,0x7225202c33393164ull,0x646c090a3b333164ull,0x2e6c61626f6c672eull,
0x3672250920323373ull,0x6472255b202c3030ull,0x0a3b5d302b343931ull,0x626f6c672e747309ull,
0x09203233732e6c61ull,0x302b35326472255bull,0x3030367225202c5dull,0x09636f6c2e090a3bull,
0x0934303331093233ull,0x6f632e646c090a30ull,0x203436752e74736eull,0x202c333264722509ull,
0x5d382b346472255bull,0x752e646461090a3bull,0x3264722509203436ull,0x3332647225202c36ull,
0x3b3131647225202cull,0x6e6f632e646c090aull,0x09203436752e7473ull,0x202c353931647225ull,
0x34322b346472255bull,0x2e646461090a3b5dull,0x6472250920343675ull,0x647225202c363931ull,
0x647225202c353931ull,0x2e646c090a3b3331ull,0x732e6c61626f6c67ull,0x3036722509203233ull,
0x316472255b202c31ull,0x090a3b5d302b3639ull,0x61626f6c672e7473ull,0x5b09203233732e6cull,
0x5d302b3632647225ull,0x3b3130367225202cull,0x3309636f6c2e090aull,0x3009373033310932ull,
0x33732e747663090aull,0x2509203631752e32ull,0x64697425202c3572ull,0x766f6d090a3b782eull,
0x722509203233732eull,0x3b357225202c3331ull,0x6e6f632e646c090aull,0x09203233732e7473ull,
0x645b202c34317225ull,0x2b6e6f6d6d6f635full,0x73090a3b5d323132ull,0x732e65672e707465ull,
0x3231702509203233ull,0x202c357225202c33ull,0x40090a3b34317225ull,0x7262203332317025ull,
0x305f744c24092061ull,0x3b3232393534315full,0x33732e627573090aull,0x3230367225092032ull,
0x202c34317225202cull,0x6461090a3b357225ull,0x2509203233732e64ull,0x7225202c33303672ull,
0x313135202c323036ull,0x732e726873090a3bull,0x3036722509203233ull,0x3330367225202c34ull,
0x6d090a3b3133202cull,0x09203233732e766full,0x35202c3530367225ull,0x646e61090a3b3131ull,
0x722509203233622eull,0x367225202c363036ull,0x30367225202c3430ull,0x2e646461090a3b35ull,
0x3672250920323373ull,0x30367225202c3730ull,0x3330367225202c36ull,0x732e726873090a3bull,
0x3036722509203233ull,0x3730367225202c38ull,0x7663090a3b39202cull,0x33732e3436752e74ull,
0x3336647225092032ull,0x090a3b357225202cull,0x74736e6f632e646cull,0x662509203233662eull,
0x635f645b202c3039ull,0x32312b6e6f6d6d6full,0x2e6c756d090a3b5dull,0x09203436752e6f6cull,
0x25202c3833647225ull,0x3b34202c33366472ull,0x36662e766f6d090aull,0x2c31646625092034ull,
0x3030666633643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x662e747663090a31ull,
0x09203233662e3436ull,0x6625202c32646625ull,0x627573090a3b3039ull,0x662509203436662eull,
0x31646625202c3364ull,0x0a3b32646625202cull,0x3436732e766f6d09ull,0x3739316472250920ull,
0x0a3b39647225202cull,0x3436752e64646109ull,0x3733316472250920ull,0x373931647225202cull,
0x3b3833647225202cull,0x6e6f632e646c090aull,0x09203233732e7473ull,0x645b202c32327225ull,
0x2b6e6f6d6d6f635full,0x646c090a3b5d3032ull,0x752e74736e6f632eull,0x3264722509203436ull,
0x6f635f645b202c37ull,0x6168635f6e6f6d6dull,0x0a3b5d302b65676eull,0x736e6f632e646c09ull,
0x2509203233732e74ull,0x5f645b202c333272ull,0x322b6e6f6d6d6f63ull,0x6f6d090a3b5d3430ull,
0x2509203233732e76ull,0x7225202c39303672ull,0x744c240a3b383036ull,0x33343634315f305full,
0x6c3c2f2f200a3a34ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,0x3730333120656e69ull,
0x6e697473656e202cull,0x3a68747065642067ull,0x69747365202c3120ull,0x746920646574616dull,
0x736e6f6974617265ull,0x776f6e6b6e75203aull,0x09636f6c2e090a6eull,0x0931313331093233ull,
0x732e646461090a30ull,0x3532722509203233ull,0x202c33317225202cull,0x2e6d6572090a3b31ull,
0x3272250920323373ull,0x2c35327225202c36ull,0x090a3b3332722520ull,0x203233732e627573ull,
0x25202c3732722509ull,0x0a3b31202c363272ull,0x323309636f6c2e09ull,0x0a30093231333109ull,
0x3233732e76696409ull,0x202c383272250920ull,0x7225202c35327225ull,0x766f6d090a3b3332ull,
0x722509203233752eull,0x0a3b30202c303136ull,0x656e2e7074657309ull,0x702509203233732eull,
0x327225202c343231ull,0x3031367225202c36ull,0x3231702540090a3bull,0x2409206172622034ull,
0x3634315f305f744cull,0x2f2f200a3b303936ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x333120656e696c20ull,0x64616568202c3730ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x2e090a3433343634ull,0x3109323309636f6cull,0x73090a3009343133ull,
0x09203233732e6275ull,0x7225202c37327225ull,0x090a3b31202c3332ull,0x09323309636f6c2eull,
0x090a300935313331ull,0x203233732e627573ull,0x25202c3832722509ull,0x0a3b31202c383272ull,
0x34315f305f744c24ull,0x2f200a3a30393636ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x616568202c373033ull,0x656c6562616c2064ull,
0x5f305f744c242064ull,0x090a343334363431ull,0x09323309636f6c2eull,0x090a300934323331ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x72255b202c313966ull,0x3b5d302b37333164ull,
0x33662e6c756d090aull,0x2c32396625092032ull,0x25202c3139662520ull,0x7663090a3b303966ull,
0x33662e3436662e74ull,0x2c34646625092032ull,0x090a3b3239662520ull,0x61626f6c672e646cull,
0x2509203233732e6cull,0x255b202c31313672ull,0x3b5d302b35326472ull,0x33732e646461090aull,
0x3231367225092032ull,0x2c3131367225202cull,0x090a3b3732722520ull,0x61626f6c672e646cull,
0x2509203233732e6cull,0x255b202c33313672ull,0x3b5d302b36326472ull,0x33732e646461090aull,
0x3431367225092032ull,0x2c3331367225202cull,0x090a3b3832722520ull,0x203233732e627573ull,
0x202c353136722509ull,0x32202c3431367225ull,0x2e6c756d090a3b36ull,0x09203233732e6f6cull,
0x25202c3631367225ull,0x367225202c323272ull,0x646461090a3b3531ull,0x722509203233732eull,
0x367225202c373136ull,0x31367225202c3231ull,0x2e747663090a3b36ull,0x203233732e343675ull,
0x2c38393164722509ull,0x0a3b373136722520ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x647225202c393931ull,0x0a3b34202c383931ull,0x3436752e64646109ull,0x3030326472250920ull,
0x2c3732647225202cull,0x3b39393164722520ull,0x6f6c672e646c090aull,0x203233662e6c6162ull,
0x5b202c3339662509ull,0x2d2b303032647225ull,0x63090a3b5d343031ull,0x662e3436662e7476ull,
0x3564662509203233ull,0x0a3b33396625202cull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x2c35646625202c36ull,0x25202c3364662520ull,0x7663090a3b346466ull,0x3233662e6e722e74ull,
0x662509203436662eull,0x36646625202c3439ull,0x6c672e7473090a3bull,0x3233662e6c61626full,
0x33316472255b0920ull,0x6625202c5d302b37ull,0x646461090a3b3439ull,0x722509203233732eull,
0x33317225202c3331ull,0x090a3b323135202cull,0x203436752e646461ull,0x2c37333164722509ull,
0x2c37333164722520ull,0x090a3b3834303220ull,0x2e746c2e70746573ull,0x3170250920323373ull,
0x33317225202c3532ull,0x0a3b34317225202cull,0x2035323170254009ull,0x744c240920617262ull,
0x33343634315f305full,0x305f744c240a3b34ull,0x3a3232393534315full,0x315f305f744c240aull,
0x090a3a3031343534ull,0x09323309636f6c2eull,0x090a300933333331ull,0x4c240a3b74697865ull,
0x5a5f5f646e655744ull,0x766c656e72656b36ull,0x202f2f207d090a3aull,0x656e72656b365a5full,
0x000000000a0a766cull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_10",(char*)__deviceText_$compute_10$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_10", (char*)__deviceText_$sm_10$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_10$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0x2e00b786,(char*)"3e8e456dfea46b13",(char*)"main.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x22cb13a8,&__elfEntries1};
# 2 "/tmp/tmpxft_00002c28_00000000-1_main.cudafe1.stub.c" 2
# 1 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 1
# 113 "/home/normal/cuda/bin/../include/crt/host_runtime.h"
# 1 "/home/normal/cuda/bin/../include/host_defines.h" 1
# 114 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2
# 140 "/home/normal/cuda/bin/../include/crt/host_runtime.h"
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
# 279 "/home/normal/cuda/bin/../include/crt/host_runtime.h"
# 1 "/home/normal/cuda/bin/../include/common_functions.h" 1
# 68 "/home/normal/cuda/bin/../include/common_functions.h"
# 1 "/home/normal/cuda/bin/../include/crt/func_macro.h" 1 3
# 69 "/home/normal/cuda/bin/../include/common_functions.h" 2

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
# 93 "/home/normal/cuda/bin/../include/common_functions.h"
# 1 "/home/normal/cuda/bin/../include/math_functions.h" 1 3
# 947 "/home/normal/cuda/bin/../include/math_functions.h" 3
int __cuda_error_not_implememted(void);
# 970 "/home/normal/cuda/bin/../include/math_functions.h" 3
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

# 1 "/home/normal/cuda/bin/../include/device_functions.h" 1 3
# 458 "/home/normal/cuda/bin/../include/device_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/math_constants.h" 1 3
# 459 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 2404 "/home/normal/cuda/bin/../include/device_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/common_types.h" 1 3
# 37 "/home/normal/cuda/bin/../include/common_types.h" 3
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
# 2405 "/home/normal/cuda/bin/../include/device_functions.h" 2 3

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
# 3184 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 3791 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 4395 "/home/normal/cuda/bin/../include/device_functions.h" 3
extern "C" {


extern int __cudaSynchronizeThreads(void**, void*);


}




static __attribute__((__unused__)) inline __attribute__((always_inline)) void __syncthreads(void)
{
  volatile int _ = 0;
  L: if (__cudaSynchronizeThreads((void**)&&L, (void*)&_)) goto L;
}
# 4421 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 4469 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 4684 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 4761 "/home/normal/cuda/bin/../include/device_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h" 1 3
# 258 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h" 3
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
# 4762 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h" 1 3
# 119 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h" 3
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
# 4763 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/sm_13_double_functions.h" 1 3
# 272 "/home/normal/cuda/bin/../include/sm_13_double_functions.h" 3
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
# 700 "/home/normal/cuda/bin/../include/sm_13_double_functions.h" 3
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
# 4764 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/sm_20_atomic_functions.h" 1 3
# 86 "/home/normal/cuda/bin/../include/sm_20_atomic_functions.h" 3
extern "C" {


extern void __cudaMutexOperation(int lock);


}







static __attribute__((__unused__)) float __fAtomicAdd(float *address, float val)
{
  float old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}
# 4765 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h" 1 3
# 156 "/home/normal/cuda/bin/../include/sm_20_intrinsics.h" 3
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
# 4766 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/surface_functions.h" 1 3
# 4767 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/texture_fetch_functions.h" 1 3
# 1911 "/home/normal/cuda/bin/../include/texture_fetch_functions.h" 3
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
# 4768 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 995 "/home/normal/cuda/bin/../include/math_functions.h" 2 3


static __attribute__((__unused__)) int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static __attribute__((__unused__)) float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 1019 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 1084 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 1264 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 1604 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 1716 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2560 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2842 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2874 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2930 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2965 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 3256 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 5005 "/home/normal/cuda/bin/../include/math_functions.h" 3


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


# 5330 "/home/normal/cuda/bin/../include/math_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 45 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx1.h" 3
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
# 5331 "/home/normal/cuda/bin/../include/math_functions.h" 2 3
# 94 "/home/normal/cuda/bin/../include/common_functions.h" 2
# 280 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2
# 3 "/tmp/tmpxft_00002c28_00000000-1_main.cudafe1.stub.c" 2




static void __sti____cudaRegisterAll_39_tmpxft_00002c28_00000000_4_main_cpp1_ii_b81a68a1(void) __attribute__((__constructor__));
void __device_stub__Z6kernelv(void){auto struct __T20 *__T21;
*(void**)(void*)&__T21 = (void*)0;{ volatile static char *__f; __f = ((char *)((void ( *)(void))kernel__entry)); (void)cudaLaunch(((char *)((void ( *)(void))kernel__entry))); };}
void kernel__entry(void)
# 7 "kernel.cu"
{__device_stub__Z6kernelv();
# 1333 "kernel.cu"
}
# 1 "/tmp/tmpxft_00002c28_00000000-1_main.cudafe1.stub.c"



static void __sti____cudaRegisterAll_39_tmpxft_00002c28_00000000_4_main_cpp1_ii_b81a68a1(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(void))kernel__entry), (char*)"_Z6kernelv", "_Z6kernelv", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_common_change__cuda_shadow_variable__, (char*)"d_common_change", "d_common_change", 0, 16, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_common__cuda_shadow_variable__, (char*)"d_common", "d_common", 0, 520, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_unique__cuda_shadow_variable__, (char*)"d_unique", "d_unique", 0, 8160, 1, 0); }
# 1 "/tmp/tmpxft_00002c28_00000000-1_main.cudafe1.stub.c" 2

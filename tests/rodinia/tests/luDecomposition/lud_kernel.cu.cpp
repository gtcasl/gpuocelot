# 1 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.cpp"
# 1 "lud_kernel.cu"
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
# 7 "lud_kernel.cu"
void lud_diagonal__entry(float *m, int matrix_dim, int offset);
# 49 "lud_kernel.cu"
void lud_perimeter__entry(float *m, int matrix_dim, int offset);
# 123 "lud_kernel.cu"
void lud_internal__entry(float *m, int matrix_dim, int offset);
# 148 "lud_kernel.cu"
void lud_cuda(float *m, int matrix_dim)
# 149 "lud_kernel.cu"
{
# 150 "lud_kernel.cu"
int i = 0;
# 151 "lud_kernel.cu"
dim3 dimBlock(16, 16);
# 152 "lud_kernel.cu"
float *m_debug = ((float *)malloc((matrix_dim * matrix_dim) * sizeof(float)));
# 154 "lud_kernel.cu"
for (i = 0; i < (matrix_dim - 16); i += 16) {
# 155 "lud_kernel.cu"
cudaConfigureCall(1, 16) ? ((void)0) : lud_diagonal__entry(m, matrix_dim, i);
# 156 "lud_kernel.cu"
cudaConfigureCall(((matrix_dim - i) / 16) - 1, 16 * 2) ? ((void)0) : lud_perimeter__entry(m, matrix_dim, i);
# 157 "lud_kernel.cu"
dim3 dimGrid(((matrix_dim - i) / 16) - 1, ((matrix_dim - i) / 16) - 1);
# 158 "lud_kernel.cu"
cudaConfigureCall(dimGrid, dimBlock) ? ((void)0) : lud_internal__entry(m, matrix_dim, i);
# 159 "lud_kernel.cu"
}
# 160 "lud_kernel.cu"
cudaConfigureCall(1, 16) ? ((void)0) : lud_diagonal__entry(m, matrix_dim, i);
# 161 "lud_kernel.cu"
}
# 1 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_00005b58_00000000-3_lud_kernel.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00005b58_00000000-3_lud_kernel.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_13$[] = {
0x33010102464c457full,0x0000000000000000ull,0x0000000100be0002ull,0x0000000000000000ull,
0x0000000000002478ull,0x0000000000000040ull,0x003800400000000dull,0x0001000d00400007ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000300000001ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000380ull,
0x0000000000000153ull,0x0000000000000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000030000000bull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000004d3ull,
0x0000000000000041ull,0x0000000000000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x0000000200000013ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000514ull,
0x00000000000001b0ull,0x0000000f00000002ull,0x0000000000000001ull,0x0000000000000018ull,
0x00000001000000f2ull,0x0000000000100006ull,0x0000000000000000ull,0x00000000000006c4ull,
0x0000000000001340ull,0x0f00000c00000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000012full,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001a04ull,
0x0000000000000008ull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000080000010eull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000001a0cull,
0x0000000000000c20ull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000094ull,0x0000000000100006ull,0x0000000000000000ull,0x0000000000001a0cull,
0x0000000000000290ull,0x0800000900000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000000cfull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000001c9cull,
0x0000000000000008ull,0x0000000700000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000008000000afull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000001ca4ull,
0x0000000000000820ull,0x0000000700000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000036ull,0x0000000000100006ull,0x0000000000000000ull,0x0000000000001ca4ull,
0x00000000000007d0ull,0x0900000600000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000071ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000002474ull,
0x0000000000000004ull,0x0000000a00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000800000051ull,0x0000000000000003ull,0x0000000000000000ull,0x0000000000002478ull,
0x0000000000000420ull,0x0000000a00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x7472747368732e00ull,0x747274732e006261ull,0x746d79732e006261ull,0x672e766e2e006261ull,
0x6e692e6c61626f6cull,0x672e766e2e007469ull,0x742e006c61626f6cull,0x32315a5f2e747865ull,
0x676169645f64756cull,0x696966506c616e6full,0x6168732e766e2e00ull,0x32315a5f2e646572ull,
0x676169645f64756cull,0x696966506c616e6full,0x6e6f632e766e2e00ull,0x5f2e31746e617473ull,
0x645f64756c32315aull,0x506c616e6f676169ull,0x7865742e00696966ull,0x756c32315a5f2e74ull,
0x6e7265746e695f64ull,0x2e00696966506c61ull,0x65726168732e766eull,0x756c32315a5f2e64ull,
0x6e7265746e695f64ull,0x2e00696966506c61ull,0x74736e6f632e766eull,0x315a5f2e31746e61ull,
0x746e695f64756c32ull,0x6966506c616e7265ull,0x2e747865742e0069ull,0x5f64756c33315a5full,
0x6574656d69726570ull,0x6e2e006969665072ull,0x6465726168732e76ull,0x64756c33315a5f2eull,
0x74656d697265705full,0x2e00696966507265ull,0x74736e6f632e766eull,0x315a5f2e31746e61ull,
0x7265705f64756c33ull,0x6650726574656d69ull,0x32315a5f00006969ull,0x676169645f64756cull,
0x696966506c616e6full,0x64756c32315a5f00ull,0x616e7265746e695full,0x5a5f00696966506cull,
0x65705f64756c3331ull,0x50726574656d6972ull,0x0000000000696966ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000010003ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000020003ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000030003ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000003ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000003ull,0x0000000000000000ull,
0x0000000000000000ull,0x00000000000a0003ull,0x000007d000000000ull,0x0000000000000000ull,
0x00000000000c0003ull,0x0000000000000000ull,0x0000000000000000ull,0x00000000000b0003ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000070003ull,0x0000029000000000ull,
0x0000000000000000ull,0x0000000000090003ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000080003ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000040003ull,
0x0000134000000000ull,0x0000000000000000ull,0x0000000000060003ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000050003ull,0x0000000000000000ull,0x0000000100000000ull,
0x00000000000a1012ull,0x0000000000000000ull,0x0000001600000000ull,0x0000000000071012ull,
0x0000000000000000ull,0x0000002b00000000ull,0x0000000000041012ull,0x0000000000000000ull,
0xa000000100000000ull,0x3080000504000780ull,0xa00003fd6440c7d0ull,0xa01330030c0147c8ull,
0x41102c0d00000000ull,0x1009800300000003ull,0x1100ec0400001100ull,0x400504111100ee08ull,
0x6004061100000780ull,0x3010081100010780ull,0x60040405c4100780ull,0x2101ee0400010780ull,
0x2000cc112101ec08ull,0x0002000504208780ull,0x2104ec14c0000780ull,0x2002801c20018018ull,
0x2000002520048020ull,0x30020c1904014780ull,0x30020e1dc4100780ull,0x30021021c4100780ull,
0x30021225c4100780ull,0x2000c819c4100780ull,0xd00e0c1904218780ull,0x2000c81d80c00780ull,
0xd00e0e1d0421c780ull,0x2000c82180c00780ull,0xd00e102104220780ull,0x2000c82580c00780ull,
0xd00e122504224780ull,0x0402100180c00780ull,0x2000cc19e4218780ull,0x0402300104214780ull,
0x2000cc1de421c780ull,0x0402500104218780ull,0x2000cc21e4220780ull,0x040270010421c780ull,
0x2108ec28e4224780ull,0x2007803420068024ull,0x2000003120088038ull,0x3002122d04028780ull,
0x30021a35c4100780ull,0x30021c25c4100780ull,0x30021831c4100780ull,0x2000c82dc4100780ull,
0xd00e162d0422c780ull,0x2000c83580c00780ull,0xd00e1a3504234780ull,0x2000c82580c00780ull,
0xd00e123904224780ull,0x2000c82580c00780ull,0xd00e122504230780ull,0x0402900180c00780ull,
0x0402b001e422c780ull,0x0402d001e4234780ull,0x0402f001e4238780ull,0x20038204e4224780ull,
0x2003881020038408ull,0x2001800420038a14ull,0x2004801020028008ull,0x3002020520058014ull,
0x30020409c4100780ull,0x30020811c4100780ull,0x30020a15c4100780ull,0x2101e804c4100780ull,
0x2104e8242102e808ull,0x200082052105e82cull,0xd00e021500000007ull,0x2000840580c00780ull,
0xd00e021100000007ull,0x2000920580c00780ull,0xd00e020900000007ull,0x2000960580c00780ull,
0xd00e020500000007ull,0x0400100180c00780ull,0x04003001e4214780ull,0x04005001e4210780ull,
0x04007001e4208780ull,0x20038c04e4204780ull,0x2003901020038e08ull,0x2001800420039414ull,
0x2004801020028008ull,0x3002020520058014ull,0x30020409c4100780ull,0x30020811c4100780ull,
0x30020a15c4100780ull,0x2101e804c4100780ull,0x2104e8182102e808ull,0x200082052105e81cull,
0xd00e021500000007ull,0x2000840580c00780ull,0xd00e021100000007ull,0x20008c0580c00780ull,
0xd00e020900000007ull,0x20008e0580c00780ull,0xd00e020500000007ull,0x0400900180c00780ull,
0x2000cc15e4214780ull,0x0400b00104228780ull,0x2000cc11e4210780ull,0x0400d00104214780ull,
0x2000cc19e4208780ull,0x0400f00104210780ull,0x2106ec04e4204780ull,0x2004861020058608ull,
0x2001861820068614ull,0x2004801020028008ull,0x2000001920058014ull,0x3002040904018780ull,
0x30020811c4100780ull,0x30020a15c4100780ull,0x30020c19c4100780ull,0x2102e808c4100780ull,
0x2105e81c2104e810ull,0x200084092106e820ull,0xd00e041900000007ull,0x2000880980c00780ull,
0xd00e041500000007ull,0x20008e0980c00780ull,0xd00e041100000007ull,0x2000900980c00780ull,
0xd00e040900000007ull,0x0401100180c00780ull,0x2000cc05e4218780ull,0x0401300104204780ull,
0x2000cc15e4214780ull,0x0401500104204780ull,0x2000cc11e4210780ull,0x0401700104214780ull,
0x2104ec18e4208780ull,0x2005860820018604ull,0x2006861420048610ull,0x2002800820018004ull,
0x2000001520048010ull,0x3002020504014780ull,0x30020409c4100780ull,0x30020811c4100780ull,
0x30020a15c4100780ull,0x2101e804c4100780ull,0x2104e8182102e808ull,0x200082052105e81cull,
0xd00e021500000007ull,0x2000840580c00780ull,0xd00e021100000007ull,0x20008c0580c00780ull,
0xd00e020900000007ull,0x20008e0580c00780ull,0xd00e020500000007ull,0x0401900180c00780ull,
0x0401b001e4214780ull,0x0401d001e4210780ull,0x0401f001e4208780ull,0x10133003e4204780ull,
0x2108ee0900000780ull,0x10000c0500000003ull,0x400308114400c780ull,0x60020a1100000780ull,
0x3010081100010780ull,0x60020805c4100780ull,0x2101ee0800010780ull,0x2000cc152102ec10ull,
0x0002000504210780ull,0x2105ec04c0000780ull,0x2004801020028008ull,0x2000001920058014ull,
0x3002040904004780ull,0x30020811c4100780ull,0x30020a15c4100780ull,0x30020c19c4100780ull,
0x2102e808c4100780ull,0x2105e81c2104e810ull,0x200084092106e820ull,0xd00e04190fffffffull,
0x2000880980c00780ull,0xd00e04150fffffffull,0x20008e0980c00780ull,0xd00e04110fffffffull,
0x2000900980c00780ull,0xd00e04090fffffffull,0x0402f00180c00780ull,0x04031001e4218780ull,
0x2000cc15e4214780ull,0x0403300104204780ull,0x2105ec18e4210780ull,0x040350012103ee10ull,
0x1100ec04e4208780ull,0x201088092106ec1cull,0x2107ec2000000003ull,0x2006801420058010ull,
0x2000001d20078018ull,0x3002081104020780ull,0x30020a15c4100780ull,0x30020c19c4100780ull,
0x30020e1dc4100780ull,0x2104e810c4100780ull,0x2106e8182105e814ull,0x200088112107e820ull,
0xd00e08110fffffffull,0x20008a1580c00780ull,0xd00e0a150fffffffull,0x20008c1980c00780ull,
0xd00e0c1d0fffffffull,0x2000901980c00780ull,0xd00e0c190fffffffull,0x4005042180c00780ull,
0x6004062100000780ull,0x3010102100020780ull,0x60040405c4100780ull,0x0403700100020780ull,
0x2000ce09e4210780ull,0x0403900104204780ull,0x2000cc11e4214780ull,0x0403b00104208780ull,
0x2000cc15e421c780ull,0x0403d00104210780ull,0x2105ec04e4218780ull,0x2004801020028008ull,
0x2000001920058014ull,0x3002040904004780ull,0x30020811c4100780ull,0x30020a15c4100780ull,
0x30020c19c4100780ull,0x2102e808c4100780ull,0x2105e81c2104e810ull,0x200084092106e820ull,
0xd00e04190fffffffull,0x2000880980c00780ull,0xd00e04150fffffffull,0x20008e0980c00780ull,
0xd00e04110fffffffull,0x2000900980c00780ull,0xd00e04090fffffffull,0x0403f00180c00780ull,
0x2000cc19e4218780ull,0x0404100104204780ull,0x2000cc15e4214780ull,0x0404300104218780ull,
0x2000cc1de4210780ull,0x0404500104214780ull,0x2107ec04e4208780ull,0x2005801020068008ull,
0x2000001920078014ull,0x3002040904004780ull,0x30020811c4100780ull,0x30020a15c4100780ull,
0x30020c19c4100780ull,0x2102e808c4100780ull,0x2105e81c2104e810ull,0x200084092106e820ull,
0xd00e04190fffffffull,0x2000880980c00780ull,0xd00e04150fffffffull,0x20008e0980c00780ull,
0xd00e04110fffffffull,0x2000900980c00780ull,0xd00e04090fffffffull,0x0404700180c00780ull,
0x2000cc19e4218780ull,0x0404900104204780ull,0x2000cc15e4214780ull,0x0404b00104218780ull,
0x2000cc1de4210780ull,0x0404d00104214780ull,0x2107ec04e4208780ull,0x2005801020068008ull,
0x2000001920078014ull,0x3002040904004780ull,0x30020811c4100780ull,0x30020a15c4100780ull,
0x30020c19c4100780ull,0x2102e808c4100780ull,0x2105e81c2104e810ull,0x200084092106e820ull,
0xd00e04190fffffffull,0x2000880980c00780ull,0xd00e04150fffffffull,0x20008e0980c00780ull,
0xd00e04110fffffffull,0x2000900980c00780ull,0xd00e04090fffffffull,0x0404f00180c00780ull,
0x2000cc05e4218780ull,0x0405100104204780ull,0x2000cc15e4214780ull,0x0405300104204780ull,
0x2000cc11e4210780ull,0x0405500104214780ull,0x2104ec18e4208780ull,0x2005800820018004ull,
0x2000001520048010ull,0x3002020504018780ull,0x30020409c4100780ull,0x30020811c4100780ull,
0x30020a15c4100780ull,0x2101e804c4100780ull,0x2104e8182102e808ull,0x200082052105e81cull,
0xd00e02150fffffffull,0x2000840580c00780ull,0xd00e02110fffffffull,0x20008c0580c00780ull,
0xd00e02090fffffffull,0x20008e0580c00780ull,0xd00e02050fffffffull,0x0405700180c00780ull,
0x04059001e4214780ull,0x0405b001e4210780ull,0x0405d001e4208780ull,0xf0000001e4204780ull,
0x861ffe03e0000002ull,0x101bd00300000000ull,0x1001801100000100ull,0x307c09fd00000003ull,
0x101490036c00c7c8ull,0x3004080500000280ull,0x30060809c4100780ull,0x20000215c4100780ull,
0x2008800504000780ull,0x2020840900000003ull,0x00020a0500000043ull,0x00020209c0000780ull,
0x0000040dc0000780ull,0x1000f815c0000780ull,0x140010050603c780ull,0x1a0020094400c780ull,
0x20018a154400c780ull,0xee02c20500000003ull,0x30040bfd04204780ull,0x040010016c0147c8ull,
0x10143003e4204780ull,0x2001881100000280ull,0x308109fd00000003ull,0x101370036c4147c8ull,
0x2101ee0900000280ull,0x10000c0500000003ull,0x400308114400c780ull,0x60020a1100000780ull,
0x3010081100010780ull,0x60020805c4100780ull,0x2101ee0400010780ull,0x2002800820038208ull,
0x300204052101ec10ull,0x00020005c4100780ull,0x20048614c0000780ull,0x140030052101e808ull,
0x200580144400c780ull,0x200084092104ec18ull,0x30020a1100000007ull,0x20000615c4100780ull,
0xd00e040504018780ull,0xd4014009a0c00780ull,0x2104e80820000780ull,0x2106ec1420058010ull,
0x200084091900e004ull,0x3002081100000007ull,0x20000619c4100780ull,0xd00e040504014780ull,
0x2104e808a0c00780ull,0x2000cc1520068010ull,0x1800200504214780ull,0x200084094400c780ull,
0x3002081100000007ull,0x20000619c4100780ull,0xd402400904014780ull,0xd00e040520000780ull,
0x2104e808a0c00780ull,0x1900e00420068010ull,0x200084092105ec14ull,0x3002081100000007ull,
0x20000619c4100780ull,0xd00e040504014780ull,0x2000c809a0c00780ull,0x1800200504210780ull,
0x200680104400c780ull,0x200084092105ec14ull,0x3002081100000007ull,0x20000619c4100780ull,
0xd00e040504014780ull,0xd4034009a0c00780ull,0x2104e80820000780ull,0x2105ec1420068010ull,
0x200084091900e004ull,0x3002081100000007ull,0x20000619c4100780ull,0xd00e040504014780ull,
0x2104e808a0c00780ull,0x2000cc1520068010ull,0x1800200504214780ull,0x200084094400c780ull,
0x3002081100000007ull,0x20000619c4100780ull,0xd404400904014780ull,0xd00e040520000780ull,
0x2104e808a0c00780ull,0x1900e00420068010ull,0x200084092105ec14ull,0x3002081100000007ull,
0x20000619c4100780ull,0xd00e040504014780ull,0x2104e808a0c00780ull,0x200000112105ec14ull,
0x1800200504018780ull,0x200084094400c780ull,0x2000061900000007ull,0x3002081104014780ull,
0xd4054009c4100780ull,0xd00e040520000780ull,0x20068018a0c00780ull,0x1900e0042104e808ull,
0x30020c112105ec14ull,0x20008409c4100780ull,0x2005861800000007ull,0xd00e04052104e810ull,
0x18002005a0c00780ull,0x200000194400c780ull,0x2000880904018780ull,0x2000cc1500000007ull,
0x30020c1104214780ull,0xd00e0405c4100780ull,0x20000605a0c00780ull,0xd406400904014780ull,
0x2104e80820000780ull,0x200180102105ec14ull,0x200084091900e004ull,0x2000061900000007ull,
0x3002081104014780ull,0x2000cc1dc4100780ull,0xd00e040504214780ull,0x20068014a0c00780ull,
0x200006112104e808ull,0x180020050401c780ull,0x30020a0d4400c780ull,0x20008409c4100780ull,
0x2000000100000007ull,0xd407400504010780ull,0x2000c80d20000780ull,0xd00e04050420c780ull,
0x30020009a0c00780ull,0x14000001c4100780ull,0x200086054400c780ull,0x2000c80900000007ull,
0xd00e020104208780ull,0x14002001a0c00780ull,0x200084054400c780ull,0xd00e020100000007ull,
0x30000003a0c00780ull,0x1020800500000780ull,0x0000020500000043ull,0x0400001dc0000780ull,
0x3004001540000780ull,0x1000f805c4100780ull,0x1000f8190403c780ull,0x307c0dfd0603c780ull,
0x101df0036c00c7c8ull,0x2000022100000280ull,0x0002100504014780ull,0x20088209c0000780ull,
0x20088a1100000013ull,0x2008902100000023ull,0xd408401100000023ull,0x0002040520000780ull,
0x00020809c0000780ull,0x0002100dc0000780ull,0x10000009c0000780ull,0x1000f8214400c784ull,
0x080000110403c780ull,0x2000881140000780ull,0x000008110fffffc3ull,0x10000011c0000780ull,
0x0c0000254400c784ull,0x2000922540000780ull,0xe404c0090fffffc3ull,0x0000121104208780ull,
0x00000001c0000780ull,0x20019021e4208784ull,0x300611fd00000003ull,0xd80008096c0147c8ull,
0xd400800520000780ull,0x101d000320000780ull,0x101e500300000280ull,0x2000020900000780ull,
0x0002040504014780ull,0x20088409c0000780ull,0xd408400500000023ull,0x0002040d20000780ull,
0x14000009c0000780ull,0x00000e054400c780ull,0x16002211c0000780ull,0x0c00001d4400c780ull,
0x9000081140000780ull,0x20008e1d00000780ull,0xc00404090fffffc3ull,0x20018c1900000780ull,
0x00000e0900000003ull,0x30810dfdc0000780ull,0x080000016c4147c8ull,0x20018205e4208780ull,
0x0400001d00000003ull,0x101c300340000780ull,0x861ffe0300000280ull,0x2103ee0800000000ull,
0x201084091100ec04ull,0x4005040d00000003ull,0x6004060d00000780ull,0x3010060d0000c780ull,
0x60040405c4100780ull,0x2101ee040000c780ull,0x3002040920008208ull,0x2000cc0dc4100780ull,
0x0002000504204780ull,0xd40fc005c0000780ull,0x2102e80820000780ull,0x1400000520038010ull,
0x200084094400c780ull,0x2000cc150fffffffull,0x3002080d0420c780ull,0xd00e0405c4100780ull,
0x20058010a0c00780ull,0x140020052103e808ull,0x2000cc154400c780ull,0x3002080d04214780ull,
0x20008409c4100780ull,0x000200050fffffffull,0xd410c005c0000780ull,0x2005801020000780ull,
0xd00e04052103e80cull,0x14000005a0c00780ull,0x300208114400c780ull,0x20008609c4100780ull,
0x2105ec140fffffffull,0xd00e04052104e80cull,0x20000011a0c00780ull,0x1400200504014780ull,
0x200086094400c780ull,0x2000cc150fffffffull,0x3002080d04214780ull,0x00020005c4100780ull,
0xd411c005c0000780ull,0xd00e040520000780ull,0x20058010a0c00780ull,0x1500e0042103e808ull,
0x3002080d2105ec14ull,0x20008409c4100780ull,0x200580100fffffffull,0xd00e04052103e80cull,
0x14002005a0c00780ull,0x300208114400c780ull,0x20008609c4100780ull,0x2000cc150fffffffull,
0x0002000504214780ull,0xd412c005c0000780ull,0x2000c80d20000780ull,0xd00e040504210780ull,
0x20058010a0c00780ull,0x200086091500e004ull,0x2000cc150fffffffull,0x3002080d04214780ull,
0xd00e0405c4100780ull,0x20058010a0c00780ull,0x140020052103e808ull,0x2000cc154400c780ull,
0x3002080d04214780ull,0x20008409c4100780ull,0x000200050fffffffull,0xd413c005c0000780ull,
0x2005801020000780ull,0xd00e04052103e80cull,0x14000005a0c00780ull,0x300208114400c780ull,
0x20008609c4100780ull,0x2105ec140fffffffull,0xd00e04052104e80cull,0x20000011a0c00780ull,
0x1400200504014780ull,0x200086094400c780ull,0x2000cc150fffffffull,0x3002080d04214780ull,
0x00020005c4100780ull,0xd414c005c0000780ull,0xd00e040520000780ull,0x20058010a0c00780ull,
0x1500e0042103e808ull,0x3002080d2105ec14ull,0x20008409c4100780ull,0x200580100fffffffull,
0xd00e04052103e80cull,0x14002005a0c00780ull,0x300208114400c780ull,0x20008609c4100780ull,
0x2000cc150fffffffull,0x0002000504214780ull,0xd415c005c0000780ull,0x2000c80d20000780ull,
0xd00e040504210780ull,0x20058010a0c00780ull,0x200086091500e004ull,0x2000cc150fffffffull,
0x3002080d04214780ull,0xd00e0405c4100780ull,0x20058010a0c00780ull,0x2000cc152103e808ull,
0x1400200504214780ull,0x3002080d4400c780ull,0x20008409c4100780ull,0x200000110fffffffull,
0x0002000504014780ull,0xd416c005c0000780ull,0x2000c80d20000780ull,0xd00e04050420c780ull,
0x30020809a0c00780ull,0x14000001c4100780ull,0x200086054400c780ull,0x2000c8090fffffffull,
0xd00e020104208780ull,0x14002001a0c00780ull,0x200084054400c780ull,0xd00e02010fffffffull,
0x0000000fa0c00781ull,0x1000000900000010ull,0xd0800a090403c780ull,0x10000e0100400780ull,
0xa00004154400c780ull,0x10000c0504000780ull,0x60824e0d4400c780ull,0x2000ce1900600780ull,
0x20038a1004214780ull,0x20108811400d040cull,0x600c060d00000003ull,0x3010060d0000c780ull,
0x4008061dc4100780ull,0x600c041900000780ull,0x6009041d0000c780ull,0x61102c010001c780ull,
0xa000080d00000003ull,0x30100e1d04000780ull,0x20000009c4100780ull,0x6008041104018780ull,
0x200286040001c780ull,0x300202092104ee18ull,0x30040a05c4100780ull,0x20068618c4100780ull,
0x200006052102e808ull,0x30020c1904004780ull,0x20008409c4100780ull,0x00060a0500000007ull,
0x00020209c0000780ull,0x2000c805c0000780ull,0xd00e040904218780ull,0xd00e020580c00780ull,
0x0802100180c00780ull,0x08001001e4208780ull,0x00020609e4204780ull,0x861ffe03c0000780ull,
0xd808400d00000000ull,0x1500f00820000780ull,0xec02c0091500f204ull,0xec01e009003f0780ull,
0xd809400d00208780ull,0x1400140520000780ull,0xec01c0094400c780ull,0x1400160500208780ull,
0xec01e0094400c780ull,0xd80a400d00208780ull,0x1400180520000780ull,0xec01c0094400c780ull,
0x14001a0500208780ull,0xec01e0094400c780ull,0xd80b400d00208780ull,0x14001c0520000780ull,
0xec01c0094400c780ull,0x14001e0500208780ull,0xec01e0094400c780ull,0xd80c400d00208780ull,
0x1400200520000780ull,0xec01c0094400c780ull,0x1400220500208780ull,0xec01e0094400c780ull,
0xd80d400d00208780ull,0x1400240520000780ull,0xec01c0094400c780ull,0x1400260500208780ull,
0xec01e0154400c780ull,0xd80e400d00208780ull,0x1400280520000780ull,0x200000094400c780ull,
0xec01c01104010780ull,0x14002a0100214780ull,0x200004054400c780ull,0xec00e0090400c780ull,
0x3002020500210780ull,0xd80f4009c4100780ull,0x14002c0120000780ull,0x2000c8054400c780ull,
0xe800c00904204780ull,0x14002e0100208780ull,0x200082054400c780ull,0xe800e00900000007ull,
0xd00e020100208780ull,0xb000000180c00780ull,0xd00e020108008780ull,0x000003ffa0c00781ull,
0x1100ee0400000010ull,0x4005040d1100ec08ull,0x6004060d00000780ull,0x3010060d0000c780ull,
0x60040405c4100780ull,0x2000ce090000c780ull,0xa000000104204780ull,0x2000cc0d04000780ull,
0x2008801504208780ull,0x2000cc1100000003ull,0x000200050420c780ull,0x2104ec04c0000780ull,
0x2003800c20028008ull,0x2000001920048010ull,0x3002040904004780ull,0x3002060dc4100780ull,
0x3002081dc4100780ull,0x30020c21c4100780ull,0x2000c809c4100780ull,0xd00e041904208780ull,
0x2000c80980c00780ull,0xd00e04110420c780ull,0x2000c80980c00780ull,0xd00e040d0421c780ull,
0x2000c80980c00780ull,0xd00e040904220780ull,0x0400100180c00780ull,0x2000cc19e4218780ull,
0x0400300104204780ull,0x2000cc11e4210780ull,0x0400500104218780ull,0x2000cc1de420c780ull,
0x0400700104210780ull,0x2107ec04e4208780ull,0x2004800c20068008ull,0x2000001920078010ull,
0x3002040904004780ull,0x3002060dc4100780ull,0x3002081dc4100780ull,0x30020c21c4100780ull,
0x2000c809c4100780ull,0xd00e041904208780ull,0x2000c80980c00780ull,0xd00e04110420c780ull,
0x2000c80980c00780ull,0xd00e040d0421c780ull,0x2000c80980c00780ull,0xd00e040904220780ull,
0x0400900180c00780ull,0x2000cc19e4218780ull,0x0400b00104204780ull,0x2000cc11e4210780ull,
0x0400d00104218780ull,0x2000cc1de420c780ull,0x0400f00104210780ull,0x2107ec04e4208780ull,
0x2004800c20068008ull,0x2000001920078010ull,0x3002040904004780ull,0x3002060dc4100780ull,
0x3002081dc4100780ull,0x30020c21c4100780ull,0x2000c809c4100780ull,0xd00e041904208780ull,
0x2000c80980c00780ull,0xd00e04110420c780ull,0x2000c80980c00780ull,0xd00e040d0421c780ull,
0x2000c80980c00780ull,0xd00e040904220780ull,0x0401100180c00780ull,0x2000cc05e4218780ull,
0x0401300104204780ull,0x2000cc11e4210780ull,0x0401500104204780ull,0x2000cc0de420c780ull,
0x0401700104210780ull,0x2103ec18e4208780ull,0x2004800820018004ull,0x200000112003800cull,
0x3002020504018780ull,0x30020409c4100780ull,0x30020619c4100780ull,0x3002081dc4100780ull,
0x2000c805c4100780ull,0xd00e021104204780ull,0x2000c80580c00780ull,0xd00e020d04208780ull,
0x2000c80580c00780ull,0xd00e020904218780ull,0x2000c80580c00780ull,0xd00e02050421c780ull,
0x0401900180c00780ull,0x0401b001e4210780ull,0x0401d001e420c780ull,0x0401f001e4208780ull,
0x861ffe03e4204780ull,0x1000f80500000000ull,0x300003fd0603c780ull,0xa009d003640187c8ull,
0x1009d00300000000ull,0x307c03fd00000280ull,0x1007c0036c00c7c8ull,0x3004000900000280ull,
0x3006000dc4100780ull,0x20000211c4100780ull,0x2008820904008780ull,0x2020860d00000003ull,
0x2008881900000003ull,0x0002040500000003ull,0x00000609c0000780ull,0x00020c0dc0000780ull,
0x00020811c0000780ull,0x1000100dc0000780ull,0x100002094400c784ull,0x1000f8190403c780ull,
0x1a0002110603c780ull,0x20018c194400c780ull,0xe404c00d00000003ull,0x30010dfd0420c780ull,
0xd40080056c0147c8ull,0x0c00000120000780ull,0x10074003e420c780ull,0x1008200300000280ull,
0x3004000900000780ull,0x20000209c4100780ull,0x2008840d04008780ull,0x0002040500000003ull,
0x0002060dc0000780ull,0x10008208c0000780ull,0x404404111500f00cull,0x0000080500000007ull,
0x1500f010c0000780ull,0xc004060d90000810ull,0x0c00000100000780ull,0x861ffe03e420c780ull,
0x2001821100000000ull,0x307c09fd00000003ull,0x1009c0036c00c7c8ull,0x3004040d00000280ull,
0x30060409c4100780ull,0x2000000dc4100780ull,0x202084090400c780ull,0x0002060900000003ull,
0x0000040dc0000780ull,0x1000f819c0000780ull,0x180030090403c780ull,0x00020a054400c780ull,
0x1c00200dc0000780ull,0x20018c194400c780ull,0xe403c00900000003ull,0x300609fd04208780ull,
0xdc00080d6c0147c8ull,0xd400800520000780ull,0x0800300120000780ull,0x10094003e4208780ull,
0x861ffe0300000280ull,0xf000000100000000ull,0x20018205e0000002ull,0x308003fd00000003ull,
0x100620036c4147c8ull,0x2101ee0900000280ull,0x10000c0500000003ull,0x4003080d4400c780ull,
0x60020a0d00000780ull,0x3010060d0000c780ull,0x60020805c4100780ull,0x2101ee040000c780ull,
0x2000cc0d20008208ull,0x3002040904204780ull,0x00020a05c4100780ull,0x14002005c0000780ull,
0x200380104400c780ull,0xd40100052102e808ull,0x2000cc1920000780ull,0x3002080d0420c780ull,
0xd00e0405c4100780ull,0x1500e004a0c00780ull,0x2103e80820068010ull,0x3002080d2106ec18ull,
0xd00e0405c4100780ull,0x14002005a0c00780ull,0x200680104400c780ull,0x00020a052103e808ull,
0xd4020005c0000780ull,0x2000cc1920000780ull,0x3002080d04218780ull,0xd00e0405c4100780ull,
0x1500e004a0c00780ull,0x2103e80820068010ull,0x3002080d2106ec18ull,0xd00e0405c4100780ull,
0x14002005a0c00780ull,0x200680104400c780ull,0x00020a052103e808ull,0xd4030005c0000780ull,
0x2000cc1920000780ull,0x3002080d04218780ull,0xd00e0405c4100780ull,0x1500e004a0c00780ull,
0x2103e80820068010ull,0x3002080d2106ec18ull,0xd00e0405c4100780ull,0x14002005a0c00780ull,
0x200680104400c780ull,0x00020a052103e808ull,0xd4040005c0000780ull,0x2000cc1920000780ull,
0x3002080d04218780ull,0xd00e0405c4100780ull,0x1500e004a0c00780ull,0x2103e80820068010ull,
0x3002080d2106ec18ull,0xd00e0405c4100780ull,0x14002005a0c00780ull,0x200680104400c780ull,
0x00020a052103e808ull,0xd4050005c0000780ull,0x2000cc1920000780ull,0x3002080d04218780ull,
0xd00e0405c4100780ull,0x1500e004a0c00780ull,0x2103e80820068010ull,0x3002080d2106ec18ull,
0xd00e0405c4100780ull,0x14002005a0c00780ull,0x200680104400c780ull,0x00020a052103e808ull,
0xd4060005c0000780ull,0x2000cc1920000780ull,0x3002080d04218780ull,0xd00e0405c4100780ull,
0x1500e004a0c00780ull,0x2103e80820068010ull,0x3002080d2106ec18ull,0xd00e0405c4100780ull,
0x14002005a0c00780ull,0x200680104400c780ull,0x2000cc192103e808ull,0x00020a0504218780ull,
0xd4070005c0000780ull,0x3002080d20000780ull,0xd00e0405c4100780ull,0x20068008a0c00780ull,
0x2000c8051500e000ull,0x300204090420c780ull,0xd00e0201c4100780ull,0x14002001a0c00780ull,
0x2000c8054400c780ull,0xd00e020104208780ull,0x0000000fa0c00781ull,0x0000000500000006ull,
0x0000000000002478ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000188ull,
0x0000000000000188ull,0x0000000000000004ull,0x0000110560000000ull,0x00000000000006c4ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000001348ull,0x0000000000001348ull,
0x0000000000000004ull,0x0000110660000000ull,0x0000000000001a0cull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000c20ull,0x0000000000000004ull,
0x0000100560000000ull,0x0000000000001a0cull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000298ull,0x0000000000000298ull,0x0000000000000004ull,0x0000100660000000ull,
0x0000000000001ca4ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000820ull,0x0000000000000004ull,0x00000f0560000000ull,0x0000000000001ca4ull,
0x0000000000000000ull,0x0000000000000000ull,0x00000000000007d4ull,0x00000000000007d4ull,
0x0000000000000004ull,0x00000f0660000000ull,0x0000000000002478ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000420ull,0x0000000000000004ull,
0x0000000000000000ull
};


}



extern "C" {


static const unsigned long long __deviceText_$compute_13$[] = {
0x6f69737265762e09ull,0x2e090a342e31206eull,0x7320746567726174ull,0x2f2f090a33315f6dull,
0x656c69706d6f6320ull,0x2f20687469772064ull,0x61636f6c2f727375ull,0x6f2f616475632f6cull,
0x696c2f34366e6570ull,0x2f090a65622f2f62ull,0x6e65706f766e202full,0x6220302e33206363ull,
0x206e6f20746c6975ull,0x2d30312d39303032ull,0x2d2f2f090a0a3632ull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x43202f2f090a2d2dull,0x676e696c69706d6full,
0x6d742f706d742f20ull,0x3030305f74667870ull,0x30305f3835623530ull,0x372d303030303030ull,
0x72656b5f64756c5full,0x337070632e6c656eull,0x706d742f2820692eull,0x762e23494263632full,
0x090a295653766636ull,0x2d2d2d2d2d2d2f2full,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x090a0a2d2d2d2d2dull,0x2d2d2d2d2d2d2f2full,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2f090a2d2d2d2d2dull,0x6e6f6974704f202full,0x2d2d2f2f090a3a73ull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x5420202f2f090a2dull,0x74703a7465677261ull,
0x733a415349202c78ull,0x6e45202c33315f6dull,0x74696c3a6e616964ull,0x696f50202c656c74ull,
0x7a6953207265746eull,0x2f2f090a34363a65ull,0x4f2809334f2d2020ull,0x74617a696d697470ull,
0x6576656c206e6f69ull,0x20202f2f090a296cull,0x626544280930672dull,0x6c6576656c206775ull,
0x2d20202f2f090a29ull,0x6f7065522809326dull,0x7369766461207472ull,0x090a29736569726full,
0x2d2d2d2d2d2d2f2full,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x090a0a2d2d2d2d2dull,
0x093109656c69662eull,0x6e616d6d6f633c22ull,0x223e656e696c2d64ull,0x09656c69662e090aull,
0x2f706d742f220932ull,0x305f746678706d74ull,0x5f38356235303030ull,0x3030303030303030ull,
0x6b5f64756c5f362dull,0x75632e6c656e7265ull,0x70672e3265666164ull,0x6c69662e090a2275ull,
0x73752f2209330965ull,0x63672f62696c2f72ull,0x34365f3638782f63ull,0x672d78756e696c2dull,
0x312e342e342f756eull,0x6564756c636e692full,0x2e6665646474732full,0x6c69662e090a2268ull,
0x6f682f2209340965ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x72632f6564756c63ull,0x6563697665642f74ull,0x656d69746e75725full,0x69662e090a22682eull,
0x682f22093509656cull,0x6d726f6e2f656d6full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x682f6564756c636eull,0x696665645f74736full,0x090a22682e73656eull,0x093609656c69662eull,
0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x69746c6975622f65ull,0x2e73657079745f6eull,0x6c69662e090a2268ull,0x6f682f2209370965ull,
0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65642f6564756c63ull,
0x7079745f65636976ull,0x2e090a22682e7365ull,0x22093809656c6966ull,0x6f6e2f656d6f682full,
0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x5f7265766972642full,
0x22682e7365707974ull,0x09656c69662e090aull,0x656d6f682f220939ull,0x2f6c616d726f6e2full,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x667275732f656475ull,0x657079745f656361ull,
0x662e090a22682e73ull,0x2209303109656c69ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x657275747865742full,0x682e73657079745full,
0x656c69662e090a22ull,0x6f682f2209313109ull,0x616d726f6e2f656dull,0x622f616475632f6cull,
0x6e692f2e2e2f6e69ull,0x65762f6564756c63ull,0x7079745f726f7463ull,0x2e090a22682e7365ull,
0x09323109656c6966ull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,
0x64756c636e692f2eull,0x6563697665642f65ull,0x5f68636e75616c5full,0x6574656d61726170ull,
0x2e090a22682e7372ull,0x09333109656c6966ull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x74732f7472632f65ull,0x6c635f656761726full,
0x090a22682e737361ull,0x343109656c69662eull,0x692f7273752f2209ull,0x622f6564756c636eull,
0x657079742f737469ull,0x662e090a22682e73ull,0x2209353109656c69ull,0x636e692f7273752full,
0x6d69742f6564756cull,0x662e090a22682e65ull,0x2209363109656c69ull,0x6f6e2f656d6f682full,
0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x657275747865742full,
0x665f68637465665full,0x736e6f6974636e75ull,0x69662e090a22682eull,0x6c2209373109656cull,
0x656e72656b5f6475ull,0x2e090a2275632e6cull,0x09383109656c6966ull,0x6e2f656d6f682f22ull,
0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x6e6f6d6d6f632f65ull,
0x6f6974636e75665full,0x2e090a22682e736eull,0x09393109656c6966ull,0x6e2f656d6f682f22ull,
0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x75662f7472632f65ull,
0x6f7263616d5f636eull,0x69662e090a22682eull,0x2f2209303209656cull,0x726f6e2f656d6f68ull,
0x616475632f6c616dull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x6e75665f6874616dull,
0x682e736e6f697463ull,0x656c69662e090a22ull,0x6f682f2209313209ull,0x616d726f6e2f656dull,
0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65642f6564756c63ull,0x6e75665f65636976ull,
0x682e736e6f697463ull,0x656c69662e090a22ull,0x6f682f2209323209ull,0x616d726f6e2f656dull,
0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x616d2f6564756c63ull,0x74736e6f635f6874ull,
0x0a22682e73746e61ull,0x3209656c69662e09ull,0x656d6f682f220933ull,0x2f6c616d726f6e2full,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x315f6d732f656475ull,0x63696d6f74615f31ull,
0x6f6974636e75665full,0x2e090a22682e736eull,0x09343209656c6966ull,0x6e2f656d6f682f22ull,
0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x5f32315f6d732f65ull,
0x665f63696d6f7461ull,0x736e6f6974636e75ull,0x69662e090a22682eull,0x2f2209353209656cull,
0x726f6e2f656d6f68ull,0x616475632f6c616dull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x6f645f33315f6d73ull,0x6e75665f656c6275ull,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x6f682f2209363209ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x6d732f6564756c63ull,0x6d6f74615f30325full,0x74636e75665f6369ull,0x0a22682e736e6f69ull,
0x3209656c69662e09ull,0x656d6f682f220937ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x325f6d732f656475ull,0x6e6972746e695f30ull,0x0a22682e73636973ull,
0x3209656c69662e09ull,0x656d6f682f220938ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x667275732f656475ull,0x636e75665f656361ull,0x22682e736e6f6974ull,
0x09656c69662e090aull,0x6d6f682f22093932ull,0x6c616d726f6e2f65ull,0x69622f616475632full,
0x636e692f2e2e2f6eull,0x74616d2f6564756cull,0x6974636e75665f68ull,0x5f6c62645f736e6full,
0x0a22682e33787470ull,0x72746e652e090a0aull,0x756c32315a5f2079ull,0x6e6f676169645f64ull,
0x2820696966506c61ull,0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,
0x756c32315a5f5f6dull,0x6e6f676169645f64ull,0x6d5f696966506c61ull,0x7261702e09090a2cull,
0x203233732e206d61ull,0x6170616475635f5full,0x6c32315a5f5f6d72ull,0x6f676169645f6475ull,
0x5f696966506c616eull,0x645f78697274616dull,0x702e09090a2c6d69ull,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x6169645f64756c32ull,0x6966506c616e6f67ull,
0x74657366666f5f69ull,0x722e090a7b090a29ull,0x203233752e206765ull,0x0a3b3e31373c7225ull,
0x752e206765722e09ull,0x313c647225203436ull,0x722e090a3b3e3132ull,0x203233662e206765ull,
0x0a3b3e34343c6625ull,0x702e206765722e09ull,0x383c702520646572ull,0x6168732e090a3b3eull,
0x696c612e20646572ull,0x38622e2034206e67ull,0x5f616475635f5f20ull,0x3631776f64616873ull,
0x0a3b5d343230315bull,0x373109636f6c2e09ull,0x424c240a30093709ull,0x6c32315a5f5f3142ull,
0x6f676169645f6475ull,0x3a696966506c616eull,0x36752e766f6d090aull,0x2c31647225092034ull,
0x5f616475635f5f20ull,0x3631776f64616873ull,0x09636f6c2e090a3bull,0x0a30093431093731ull,
0x617261702e646c09ull,0x2509203233732e6dull,0x635f5f5b202c3172ull,0x5f6d726170616475ull,
0x5f64756c32315a5full,0x6c616e6f67616964ull,0x66666f5f69696650ull,0x6c090a3b5d746573ull,
0x2e6d617261702e64ull,0x3272250920323373ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x69645f64756c3231ull,0x66506c616e6f6761ull,0x697274616d5f6969ull,0x0a3b5d6d69645f78ull,
0x2e6f6c2e6c756d09ull,0x3372250920323373ull,0x25202c317225202cull,0x747663090a3b3272ull,
0x3631752e3233752eull,0x25202c3472250920ull,0x090a3b782e646974ull,0x2e3436752e747663ull,
0x6472250920323375ull,0x0a3b347225202c32ull,0x3233732e64646109ull,0x25202c3572250920ull,
0x3b317225202c3372ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x32647225202c3364ull,
0x6461090a3b34202cull,0x2509203436752e64ull,0x647225202c346472ull,0x3b33647225202c31ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5f5b202c35647225ull,0x726170616475635full,
0x756c32315a5f5f6dull,0x6e6f676169645f64ull,0x6d5f696966506c61ull,0x2e646461090a3b5dull,
0x3672250920323375ull,0x25202c357225202cull,0x747663090a3b3472ull,0x3233752e3436752eull,
0x202c366472250920ull,0x756d090a3b367225ull,0x3436752e6f6c2e6cull,0x202c376472250920ull,
0x3b34202c36647225ull,0x36752e646461090aull,0x2c38647225092034ull,0x25202c3564722520ull,
0x646c090a3b376472ull,0x2e6c61626f6c672eull,0x3166250920323366ull,0x2b386472255b202cull,
0x2e7473090a3b5d30ull,0x662e646572616873ull,0x6472255b09203233ull,0x6625202c5d302b34ull,
0x2e646461090a3b31ull,0x3772250920323373ull,0x25202c357225202cull,0x646461090a3b3272ull,
0x722509203233752eull,0x202c377225202c38ull,0x7663090a3b347225ull,0x33752e3436752e74ull,
0x2c39647225092032ull,0x6d090a3b38722520ull,0x36752e6f6c2e6c75ull,0x3031647225092034ull,
0x202c39647225202cull,0x2e646461090a3b34ull,0x6472250920343675ull,0x35647225202c3131ull,
0x3b3031647225202cull,0x6f6c672e646c090aull,0x203233662e6c6162ull,0x255b202c32662509ull,
0x3b5d302b31316472ull,0x6168732e7473090aull,0x203233662e646572ull,0x362b346472255b09ull,
0x3b326625202c5d34ull,0x33732e646461090aull,0x202c397225092032ull,0x327225202c377225ull,
0x752e646461090a3bull,0x3031722509203233ull,0x25202c397225202cull,0x747663090a3b3472ull,
0x3233752e3436752eull,0x2c32316472250920ull,0x090a3b3031722520ull,0x752e6f6c2e6c756dull,
0x3164722509203436ull,0x3231647225202c33ull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x7225202c34316472ull,0x31647225202c3564ull,0x672e646c090a3b33ull,0x33662e6c61626f6cull,
0x202c336625092032ull,0x302b34316472255bull,0x732e7473090a3b5dull,0x33662e6465726168ull,
0x346472255b092032ull,0x25202c5d3832312bull,0x646461090a3b3366ull,0x722509203233732eull,
0x2c397225202c3131ull,0x61090a3b32722520ull,0x09203233752e6464ull,0x7225202c32317225ull,
0x3b347225202c3131ull,0x36752e747663090aull,0x2509203233752e34ull,0x7225202c35316472ull,
0x6c756d090a3b3231ull,0x203436752e6f6c2eull,0x202c363164722509ull,0x34202c3531647225ull,
0x752e646461090a3bull,0x3164722509203436ull,0x2c35647225202c37ull,0x0a3b363164722520ull,
0x626f6c672e646c09ull,0x09203233662e6c61ull,0x72255b202c346625ull,0x0a3b5d302b373164ull,
0x726168732e747309ull,0x09203233662e6465ull,0x39312b346472255bull,0x3b346625202c5d32ull,
0x33732e646461090aull,0x2c33317225092032ull,0x25202c3131722520ull,0x646461090a3b3272ull,
0x722509203233752eull,0x33317225202c3431ull,0x090a3b347225202cull,0x2e3436752e747663ull,
0x6472250920323375ull,0x34317225202c3831ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x7225202c39316472ull,0x0a3b34202c383164ull,0x3436752e64646109ull,0x2c30326472250920ull,
0x25202c3564722520ull,0x6c090a3b39316472ull,0x6c61626f6c672e64ull,0x662509203233662eull,
0x326472255b202c35ull,0x73090a3b5d302b30ull,0x6465726168732e74ull,0x255b09203233662eull,
0x5d3635322b346472ull,0x090a3b356625202cull,0x203233732e646461ull,0x25202c3531722509ull,
0x327225202c333172ull,0x752e646461090a3bull,0x3631722509203233ull,0x202c35317225202cull,
0x7663090a3b347225ull,0x33752e3436752e74ull,0x3132647225092032ull,0x0a3b36317225202cull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x32647225202c3232ull,0x61090a3b34202c31ull,
0x09203436752e6464ull,0x25202c3332647225ull,0x647225202c356472ull,0x2e646c090a3b3232ull,
0x662e6c61626f6c67ull,0x2c36662509203233ull,0x2b33326472255b20ull,0x2e7473090a3b5d30ull,
0x662e646572616873ull,0x6472255b09203233ull,0x202c5d3032332b34ull,0x6461090a3b366625ull,
0x2509203233732e64ull,0x317225202c373172ull,0x0a3b327225202c35ull,0x3233752e64646109ull,
0x202c383172250920ull,0x7225202c37317225ull,0x2e747663090a3b34ull,0x203233752e343675ull,
0x202c343264722509ull,0x6d090a3b38317225ull,0x36752e6f6c2e6c75ull,0x3532647225092034ull,
0x2c3432647225202cull,0x646461090a3b3420ull,0x722509203436752eull,0x647225202c363264ull,
0x3532647225202c35ull,0x6c672e646c090a3bull,0x3233662e6c61626full,0x5b202c3766250920ull,
0x5d302b3632647225ull,0x68732e7473090a3bull,0x3233662e64657261ull,0x2b346472255b0920ull,
0x6625202c5d343833ull,0x2e646461090a3b37ull,0x3172250920323373ull,0x2c37317225202c39ull,
0x61090a3b32722520ull,0x09203233752e6464ull,0x7225202c30327225ull,0x3b347225202c3931ull,
0x36752e747663090aull,0x2509203233752e34ull,0x7225202c37326472ull,0x6c756d090a3b3032ull,
0x203436752e6f6c2eull,0x202c383264722509ull,0x34202c3732647225ull,0x752e646461090a3bull,
0x3264722509203436ull,0x2c35647225202c39ull,0x0a3b383264722520ull,0x626f6c672e646c09ull,
0x09203233662e6c61ull,0x72255b202c386625ull,0x0a3b5d302b393264ull,0x726168732e747309ull,
0x09203233662e6465ull,0x34342b346472255bull,0x3b386625202c5d38ull,0x33732e646461090aull,
0x2c31327225092032ull,0x25202c3931722520ull,0x646461090a3b3272ull,0x722509203233752eull,
0x31327225202c3232ull,0x090a3b347225202cull,0x2e3436752e747663ull,0x6472250920323375ull,
0x32327225202c3033ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c31336472ull,
0x0a3b34202c303364ull,0x3436752e64646109ull,0x2c32336472250920ull,0x25202c3564722520ull,
0x6c090a3b31336472ull,0x6c61626f6c672e64ull,0x662509203233662eull,0x336472255b202c39ull,
0x73090a3b5d302b32ull,0x6465726168732e74ull,0x255b09203233662eull,0x5d3231352b346472ull,
0x090a3b396625202cull,0x203233732e646461ull,0x25202c3332722509ull,0x327225202c313272ull,
0x752e646461090a3bull,0x3432722509203233ull,0x202c33327225202cull,0x7663090a3b347225ull,
0x33752e3436752e74ull,0x3333647225092032ull,0x0a3b34327225202cull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x33647225202c3433ull,0x61090a3b34202c33ull,0x09203436752e6464ull,
0x25202c3533647225ull,0x647225202c356472ull,0x2e646c090a3b3433ull,0x662e6c61626f6c67ull,
0x3031662509203233ull,0x35336472255b202cull,0x7473090a3b5d302bull,0x2e6465726168732eull,
0x72255b0920323366ull,0x2c5d3637352b3464ull,0x090a3b3031662520ull,0x09373109636f6c2eull,
0x6461090a30093531ull,0x2509203233732e64ull,0x327225202c353272ull,0x0a3b327225202c33ull,
0x373109636f6c2e09ull,0x61090a3009343109ull,0x09203233752e6464ull,0x7225202c36327225ull,
0x3b347225202c3532ull,0x36752e747663090aull,0x2509203233752e34ull,0x7225202c36336472ull,
0x6c756d090a3b3632ull,0x203436752e6f6c2eull,0x202c373364722509ull,0x34202c3633647225ull,
0x752e646461090a3bull,0x3364722509203436ull,0x2c35647225202c38ull,0x0a3b373364722520ull,
0x626f6c672e646c09ull,0x09203233662e6c61ull,0x255b202c31316625ull,0x3b5d302b38336472ull,
0x6168732e7473090aull,0x203233662e646572ull,0x362b346472255b09ull,0x316625202c5d3034ull,
0x636f6c2e090a3b31ull,0x3009353109373109ull,0x33732e646461090aull,0x2c35327225092032ull,
0x25202c3532722520ull,0x6f6c2e090a3b3272ull,0x0934310937310963ull,0x752e646461090a30ull,
0x3732722509203233ull,0x202c35327225202cull,0x7663090a3b347225ull,0x33752e3436752e74ull,
0x3933647225092032ull,0x0a3b37327225202cull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x33647225202c3034ull,0x61090a3b34202c39ull,0x09203436752e6464ull,0x25202c3134647225ull,
0x647225202c356472ull,0x2e646c090a3b3034ull,0x662e6c61626f6c67ull,0x3231662509203233ull,
0x31346472255b202cull,0x7473090a3b5d302bull,0x2e6465726168732eull,0x72255b0920323366ull,
0x2c5d3430372b3464ull,0x090a3b3231662520ull,0x09373109636f6c2eull,0x6461090a30093531ull,
0x2509203233732e64ull,0x327225202c353272ull,0x0a3b327225202c35ull,0x373109636f6c2e09ull,
0x61090a3009343109ull,0x09203233752e6464ull,0x7225202c38327225ull,0x3b347225202c3532ull,
0x36752e747663090aull,0x2509203233752e34ull,0x7225202c32346472ull,0x6c756d090a3b3832ull,
0x203436752e6f6c2eull,0x202c333464722509ull,0x34202c3234647225ull,0x752e646461090a3bull,
0x3464722509203436ull,0x2c35647225202c34ull,0x0a3b333464722520ull,0x626f6c672e646c09ull,
0x09203233662e6c61ull,0x255b202c33316625ull,0x3b5d302b34346472ull,0x6168732e7473090aull,
0x203233662e646572ull,0x372b346472255b09ull,0x316625202c5d3836ull,0x636f6c2e090a3b33ull,
0x3009353109373109ull,0x33732e646461090aull,0x2c35327225092032ull,0x25202c3532722520ull,
0x6f6c2e090a3b3272ull,0x0934310937310963ull,0x752e646461090a30ull,0x3932722509203233ull,
0x202c35327225202cull,0x7663090a3b347225ull,0x33752e3436752e74ull,0x3534647225092032ull,
0x0a3b39327225202cull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x34647225202c3634ull,
0x61090a3b34202c35ull,0x09203436752e6464ull,0x25202c3734647225ull,0x647225202c356472ull,
0x2e646c090a3b3634ull,0x662e6c61626f6c67ull,0x3431662509203233ull,0x37346472255b202cull,
0x7473090a3b5d302bull,0x2e6465726168732eull,0x72255b0920323366ull,0x2c5d3233382b3464ull,
0x090a3b3431662520ull,0x09373109636f6c2eull,0x6461090a30093531ull,0x2509203233732e64ull,
0x327225202c353272ull,0x0a3b327225202c35ull,0x373109636f6c2e09ull,0x61090a3009343109ull,
0x09203233752e6464ull,0x7225202c30337225ull,0x3b347225202c3532ull,0x36752e747663090aull,
0x2509203233752e34ull,0x7225202c38346472ull,0x6c756d090a3b3033ull,0x203436752e6f6c2eull,
0x202c393464722509ull,0x34202c3834647225ull,0x752e646461090a3bull,0x3564722509203436ull,
0x2c35647225202c30ull,0x0a3b393464722520ull,0x626f6c672e646c09ull,0x09203233662e6c61ull,
0x255b202c35316625ull,0x3b5d302b30356472ull,0x6168732e7473090aull,0x203233662e646572ull,
0x382b346472255b09ull,0x316625202c5d3639ull,0x2e646461090a3b35ull,0x3372250920323373ull,
0x2c35327225202c31ull,0x61090a3b32722520ull,0x09203233752e6464ull,0x7225202c32337225ull,
0x3b31337225202c34ull,0x36752e747663090aull,0x2509203233752e34ull,0x7225202c31356472ull,
0x6c756d090a3b3233ull,0x203436752e6f6c2eull,0x202c323564722509ull,0x34202c3135647225ull,
0x752e646461090a3bull,0x3564722509203436ull,0x2c35647225202c33ull,0x0a3b323564722520ull,
0x626f6c672e646c09ull,0x09203233662e6c61ull,0x255b202c36316625ull,0x3b5d302b33356472ull,
0x6168732e7473090aull,0x203233662e646572ull,0x392b346472255b09ull,0x316625202c5d3036ull,
0x636f6c2e090a3b36ull,0x3009373109373109ull,0x79732e726162090aull,0x090a3b300920636eull,
0x203233732e766f6dull,0x30202c3333722509ull,0x5f305f744c240a3bull,0x2f200a3a38353636ull,
0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3120656e696c2079ull,0x697473656e202c37ull,
0x687470656420676eull,0x657469202c31203aull,0x3a736e6f69746172ull,0x746573090a353120ull,
0x3233752e65672e70ull,0x25202c3170250920ull,0x347225202c333372ull,0x2031702540090a3bull,
0x744c240920617262ull,0x3b343139365f305full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x6568202c37312065ull,0x6c6562616c206461ull,
0x305f744c24206465ull,0x6d090a383536365full,0x09203233752e766full,0x3b30202c34337225ull,
0x6c2e70746573090aull,0x2509203233732e65ull,0x33337225202c3270ull,0x0a3b34337225202cull,
0x7262203270254009ull,0x305f744c24092061ull,0x200a3b303337395full,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x64616568202c3731ull,
0x64656c6562616c20ull,0x365f305f744c2420ull,0x766f6d090a383536ull,0x722509203233732eull,
0x33337225202c3533ull,0x732e747663090a3bull,0x09203233732e3436ull,0x25202c3435647225ull,
0x756d090a3b333372ull,0x3436752e6f6c2e6cull,0x2c35356472250920ull,0x31202c3264722520ull,
0x2e646461090a3b36ull,0x6472250920343675ull,0x35647225202c3635ull,0x3535647225202c34ull,
0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c37356472ull,0x0a3b34202c363564ull,
0x3436752e64646109ull,0x2c38356472250920ull,0x202c373564722520ull,0x6d090a3b31647225ull,
0x36752e6f6c2e6c75ull,0x3935647225092034ull,0x2c3535647225202cull,0x646461090a3b3420ull,
0x722509203436752eull,0x647225202c303664ull,0x3935647225202c31ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x7225202c31366472ull,0x0a3b34202c343564ull,0x3436752e64646109ull,
0x2c32366472250920ull,0x25202c3164722520ull,0x6c090a3b31366472ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3731ull,0x090a3b5d302b3835ull,0x203233732e766f6dull,
0x30202c3633722509ull,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x68202c373120656eull,0x6562616c20646165ull,0x5f744c242064656cull,
0x090a383536365f30ull,0x203233732e766f6dull,0x25202c3733722509ull,0x744c240a3b353372ull,
0x3a383339375f305full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,
0x656e202c37312065ull,0x656420676e697473ull,0x202c32203a687470ull,0x6574616d69747365ull,
0x7461726574692064ull,0x6e75203a736e6f69ull,0x2e090a6e776f6e6bull,0x3209373109636f6cull,
0x2e646c090a300933ull,0x662e646572616873ull,0x3831662509203233ull,0x32366472255b202cull,
0x646c090a3b5d302bull,0x2e6465726168732eull,0x3166250920323366ull,0x366472255b202c39ull,
0x6d090a3b5d302b30ull,0x09203233662e6c75ull,0x6625202c30326625ull,0x39316625202c3831ull,
0x662e627573090a3bull,0x3731662509203233ull,0x202c37316625202cull,0x73090a3b30326625ull,
0x6465726168732e74ull,0x255b09203233662eull,0x2c5d302b38356472ull,0x090a3b3731662520ull,
0x203233732e646461ull,0x25202c3633722509ull,0x0a3b31202c363372ull,0x3436752e64646109ull,
0x2c30366472250920ull,0x202c303664722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x36647225202c3236ull,0x090a3b3436202c32ull,0x2e656e2e70746573ull,0x3370250920323373ull,
0x202c36337225202cull,0x40090a3b33337225ull,0x2061726220337025ull,0x375f305f744c2409ull,
0x2f2f200a3b383339ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x373120656e696c20ull,0x6c2064616568202cull,0x242064656c656261ull,0x3536365f305f744cull,
0x752e617262090a38ull,0x5f744c240920696eull,0x0a3b363234375f30ull,0x37395f305f744c24ull,
0x3c2f2f200a3a3033ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x2c373120656e696cull,0x616c206461656820ull,0x4c242064656c6562ull,0x383536365f305f74ull,
0x36732e747663090aull,0x2509203233732e34ull,0x7225202c34356472ull,0x6c756d090a3b3333ull,
0x203436752e6f6c2eull,0x202c333664722509ull,0x3631202c32647225ull,0x752e646461090a3bull,
0x3664722509203436ull,0x3435647225202c34ull,0x3b3336647225202cull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c353664ull,0x090a3b34202c3436ull,0x203436752e646461ull,
0x202c383564722509ull,0x7225202c31647225ull,0x646c090a3b353664ull,0x2e6465726168732eull,
0x3166250920323366ull,0x356472255b202c37ull,0x4c240a3b5d302b38ull,0x363234375f305f74ull,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x68202c373120656eull,0x6562616c20646165ull,0x5f744c242064656cull,0x090a383536365f30ull,
0x09373109636f6c2eull,0x6f6d090a30093432ull,0x2509203233662e76ull,0x316625202c313266ull,
0x2e6c756d090a3b37ull,0x09203436752e6f6cull,0x25202c3636647225ull,0x3836202c34356472ull,
0x752e646461090a3bull,0x3664722509203436ull,0x2c31647225202c37ull,0x0a3b363664722520ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c32326625ull,0x3b5d302b37366472ull,
0x70612e766964090aull,0x3233662e786f7270ull,0x202c333266250920ull,0x6625202c31326625ull,
0x2e7473090a3b3232ull,0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d302b3835ull,
0x6c2e090a3b333266ull,0x363209373109636full,0x2e726162090a3009ull,0x3b300920636e7973ull,
0x33732e646461090aull,0x2c38337225092032ull,0x31202c3333722520ull,0x752e766f6d090a3bull,
0x3933722509203233ull,0x6573090a3b30202cull,0x33732e656c2e7074ull,0x202c347025092032ull,
0x7225202c38337225ull,0x702540090a3b3933ull,0x2409206172622034ull,0x3534385f305f744cull,
0x6c3c2f2f200a3b30ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x202c373120656e69ull,0x62616c2064616568ull,0x744c242064656c65ull,0x0a383536365f305full,
0x3233732e766f6d09ull,0x202c303472250920ull,0x6d090a3b38337225ull,0x36752e6f6c2e6c75ull,
0x3836647225092034ull,0x2c3435647225202cull,0x6461090a3b363120ull,0x2509203436752e64ull,
0x7225202c39366472ull,0x36647225202c3264ull,0x2e6c756d090a3b38ull,0x09203436752e6f6cull,
0x25202c3037647225ull,0x3b34202c39366472ull,0x36752e646461090aull,0x3137647225092034ull,
0x202c31647225202cull,0x090a3b3037647225ull,0x752e6f6c2e6c756dull,0x3764722509203436ull,
0x3836647225202c32ull,0x6461090a3b34202cull,0x2509203436752e64ull,0x7225202c33376472ull,
0x37647225202c3164ull,0x2e766f6d090a3b32ull,0x6472250920343673ull,0x34647225202c3437ull,
0x68732e646c090a3bull,0x3233662e64657261ull,0x202c343266250920ull,0x362b31376472255bull,
0x766f6d090a3b5d34ull,0x722509203233732eull,0x200a3b30202c3633ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x64616568202c3731ull,
0x64656c6562616c20ull,0x365f305f744c2420ull,0x766f6d090a383536ull,0x722509203233732eull,
0x30347225202c3134ull,0x5f305f744c240a3bull,0x2f200a3a32363938ull,0x203e706f6f6c3c2full,
0x646f6220706f6f4cull,0x3220656e696c2079ull,0x697473656e202c36ull,0x687470656420676eull,
0x747365202c32203aull,0x6920646574616d69ull,0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,
0x636f6c2e090a6e77ull,0x3009393209373109ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3532662509ull,0x5d302b3437647225ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x202c363266250920ull,0x362b33376472255bull,0x6c756d090a3b5d34ull,0x662509203233662eull,
0x35326625202c3732ull,0x0a3b36326625202cull,0x3233662e62757309ull,0x202c343266250920ull,
0x6625202c34326625ull,0x2e7473090a3b3732ull,0x662e646572616873ull,0x6472255b09203233ull,
0x202c5d34362b3137ull,0x61090a3b34326625ull,0x09203233732e6464ull,0x7225202c36337225ull,
0x090a3b31202c3633ull,0x203436752e646461ull,0x202c333764722509ull,0x34202c3337647225ull,
0x752e646461090a3bull,0x3764722509203436ull,0x3437647225202c34ull,0x73090a3b3436202cull,
0x732e656e2e707465ull,0x2c35702509203233ull,0x25202c3833722520ull,0x2540090a3b363372ull,
0x0920617262203570ull,0x39385f305f744c24ull,0x5f744c240a3b3236ull,0x0a3a303534385f30ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x616568202c373120ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x6c2e090a38353636ull,
0x313309373109636full,0x2e726162090a3009ull,0x3b300920636e7973ull,0x365f305f744c240aull,
0x2f2f200a3a343139ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x373120656e696c20ull,0x6c2064616568202cull,0x242064656c656261ull,0x3536365f305f744cull,
0x732e646461090a38ull,0x3833722509203233ull,0x202c33337225202cull,0x2e766f6d090a3b31ull,
0x3372250920323373ull,0x3b38337225202c33ull,0x33752e766f6d090aull,0x2c32347225092032ull,
0x6573090a3b353120ull,0x33732e656e2e7074ull,0x202c367025092032ull,0x7225202c38337225ull,
0x702540090a3b3234ull,0x2409206172622036ull,0x3536365f305f744cull,0x636f6c2e090a3b38ull,
0x3009343109373109ull,0x7261702e646c090aull,0x09203233732e6d61ull,0x5f5f5b202c317225ull,
0x6d72617061647563ull,0x64756c32315a5f5full,0x616e6f676169645full,0x666f5f696966506cull,
0x090a3b5d74657366ull,0x09373109636f6c2eull,0x6461090a30093334ull,0x2509203233732e64ull,
0x317225202c333472ull,0x6c2e090a3b31202cull,0x343109373109636full,0x702e646c090a3009ull,
0x3233732e6d617261ull,0x5b202c3272250920ull,0x6170616475635f5full,0x6c32315a5f5f6d72ull,
0x6f676169645f6475ull,0x5f696966506c616eull,0x645f78697274616dull,0x6c2e090a3b5d6d69ull,
0x333409373109636full,0x2e6c756d090a3009ull,0x09203233732e6f6cull,0x7225202c34347225ull,
0x3b327225202c3334ull,0x33732e646461090aull,0x2c35347225092032ull,0x25202c3434722520ull,
0x2e646c090a3b3172ull,0x662e646572616873ull,0x3832662509203233ull,0x2b346472255b202cull,
0x6461090a3b5d3436ull,0x2509203233752e64ull,0x347225202c363472ull,0x0a3b347225202c35ull,
0x3436752e74766309ull,0x722509203233752eull,0x347225202c353764ull,0x2e6c756d090a3b36ull,
0x09203436752e6f6cull,0x25202c3637647225ull,0x3b34202c35376472ull,0x3109636f6c2e090aull,
0x090a300934310937ull,0x6d617261702e646cull,0x722509203436752eull,0x635f5f5b202c3564ull,
0x5f6d726170616475ull,0x5f64756c32315a5full,0x6c616e6f67616964ull,0x3b5d6d5f69696650ull,
0x3109636f6c2e090aull,0x090a300933340937ull,0x203436752e646461ull,0x202c373764722509ull,
0x7225202c35647225ull,0x7473090a3b363764ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,
0x202c5d302b373764ull,0x61090a3b38326625ull,0x09203233732e6464ull,0x7225202c37347225ull,
0x3b327225202c3534ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3932662509ull,
0x3832312b34647225ull,0x2e646461090a3b5dull,0x3472250920323375ull,0x2c37347225202c38ull,
0x63090a3b34722520ull,0x752e3436752e7476ull,0x3764722509203233ull,0x3b38347225202c38ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c393764ull,0x090a3b34202c3837ull,
0x203436752e646461ull,0x202c303864722509ull,0x7225202c35647225ull,0x7473090a3b393764ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b303864ull,0x61090a3b39326625ull,
0x09203233732e6464ull,0x7225202c39347225ull,0x3b327225202c3734ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3033662509ull,0x3239312b34647225ull,0x2e646461090a3b5dull,
0x3572250920323375ull,0x2c39347225202c30ull,0x63090a3b34722520ull,0x752e3436752e7476ull,
0x3864722509203233ull,0x3b30357225202c31ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c323864ull,0x090a3b34202c3138ull,0x203436752e646461ull,0x202c333864722509ull,
0x7225202c35647225ull,0x7473090a3b323864ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,
0x202c5d302b333864ull,0x61090a3b30336625ull,0x09203233732e6464ull,0x7225202c31357225ull,
0x3b327225202c3934ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3133662509ull,
0x3635322b34647225ull,0x2e646461090a3b5dull,0x3572250920323375ull,0x2c31357225202c32ull,
0x63090a3b34722520ull,0x752e3436752e7476ull,0x3864722509203233ull,0x3b32357225202c34ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c353864ull,0x090a3b34202c3438ull,
0x203436752e646461ull,0x202c363864722509ull,0x7225202c35647225ull,0x7473090a3b353864ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b363864ull,0x61090a3b31336625ull,
0x09203233732e6464ull,0x7225202c33357225ull,0x3b327225202c3135ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3233662509ull,0x3032332b34647225ull,0x2e646461090a3b5dull,
0x3572250920323375ull,0x2c33357225202c34ull,0x63090a3b34722520ull,0x752e3436752e7476ull,
0x3864722509203233ull,0x3b34357225202c37ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c383864ull,0x090a3b34202c3738ull,0x203436752e646461ull,0x202c393864722509ull,
0x7225202c35647225ull,0x7473090a3b383864ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,
0x202c5d302b393864ull,0x61090a3b32336625ull,0x09203233732e6464ull,0x7225202c35357225ull,
0x3b327225202c3335ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3333662509ull,
0x3438332b34647225ull,0x2e646461090a3b5dull,0x3572250920323375ull,0x2c35357225202c36ull,
0x63090a3b34722520ull,0x752e3436752e7476ull,0x3964722509203233ull,0x3b36357225202c30ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c313964ull,0x090a3b34202c3039ull,
0x203436752e646461ull,0x202c323964722509ull,0x7225202c35647225ull,0x7473090a3b313964ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b323964ull,0x61090a3b33336625ull,
0x09203233732e6464ull,0x7225202c37357225ull,0x3b327225202c3535ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3433662509ull,0x3834342b34647225ull,0x2e646461090a3b5dull,
0x3572250920323375ull,0x2c37357225202c38ull,0x63090a3b34722520ull,0x752e3436752e7476ull,
0x3964722509203233ull,0x3b38357225202c33ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c343964ull,0x090a3b34202c3339ull,0x203436752e646461ull,0x202c353964722509ull,
0x7225202c35647225ull,0x7473090a3b343964ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,
0x202c5d302b353964ull,0x61090a3b34336625ull,0x09203233732e6464ull,0x7225202c39357225ull,
0x3b327225202c3735ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3533662509ull,
0x3231352b34647225ull,0x2e646461090a3b5dull,0x3672250920323375ull,0x2c39357225202c30ull,
0x63090a3b34722520ull,0x752e3436752e7476ull,0x3964722509203233ull,0x3b30367225202c36ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c373964ull,0x090a3b34202c3639ull,
0x203436752e646461ull,0x202c383964722509ull,0x7225202c35647225ull,0x7473090a3b373964ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b383964ull,0x61090a3b35336625ull,
0x09203233732e6464ull,0x7225202c31367225ull,0x3b327225202c3935ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3633662509ull,0x3637352b34647225ull,0x2e646461090a3b5dull,
0x3672250920323375ull,0x2c31367225202c32ull,0x63090a3b34722520ull,0x752e3436752e7476ull,
0x3964722509203233ull,0x3b32367225202c39ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x7225202c30303164ull,0x0a3b34202c393964ull,0x3436752e64646109ull,0x3130316472250920ull,
0x202c35647225202cull,0x0a3b303031647225ull,0x626f6c672e747309ull,0x09203233662e6c61ull,
0x2b3130316472255bull,0x36336625202c5d30ull,0x09636f6c2e090a3bull,0x0a30093434093731ull,
0x3233732e64646109ull,0x202c353272250920ull,0x7225202c31367225ull,0x636f6c2e090a3b32ull,
0x3009333409373109ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3733662509ull,
0x3034362b34647225ull,0x2e646461090a3b5dull,0x3672250920323375ull,0x2c35327225202c33ull,
0x63090a3b34722520ull,0x752e3436752e7476ull,0x3164722509203233ull,0x33367225202c3230ull,
0x6c2e6c756d090a3bull,0x2509203436752e6full,0x25202c3330316472ull,0x34202c3230316472ull,
0x752e646461090a3bull,0x3164722509203436ull,0x35647225202c3430ull,0x333031647225202cull,
0x6c672e7473090a3bull,0x3233662e6c61626full,0x30316472255b0920ull,0x6625202c5d302b34ull,
0x6f6c2e090a3b3733ull,0x0934340937310963ull,0x732e646461090a30ull,0x3532722509203233ull,
0x202c35327225202cull,0x6c2e090a3b327225ull,0x333409373109636full,0x732e646c090a3009ull,
0x33662e6465726168ull,0x2c38336625092032ull,0x372b346472255b20ull,0x6461090a3b5d3430ull,
0x2509203233752e64ull,0x327225202c343672ull,0x0a3b347225202c35ull,0x3436752e74766309ull,
0x722509203233752eull,0x7225202c35303164ull,0x6c756d090a3b3436ull,0x203436752e6f6c2eull,
0x2c36303164722509ull,0x2c35303164722520ull,0x646461090a3b3420ull,0x722509203436752eull,
0x7225202c37303164ull,0x31647225202c3564ull,0x2e7473090a3b3630ull,0x662e6c61626f6c67ull,
0x6472255b09203233ull,0x202c5d302b373031ull,0x2e090a3b38336625ull,0x3409373109636f6cull,
0x646461090a300934ull,0x722509203233732eull,0x35327225202c3532ull,0x090a3b327225202cull,
0x09373109636f6c2eull,0x646c090a30093334ull,0x2e6465726168732eull,0x3366250920323366ull,
0x346472255b202c39ull,0x090a3b5d3836372bull,0x203233752e646461ull,0x25202c3536722509ull,
0x347225202c353272ull,0x752e747663090a3bull,0x09203233752e3436ull,0x202c383031647225ull,
0x6d090a3b35367225ull,0x36752e6f6c2e6c75ull,0x3031647225092034ull,0x3031647225202c39ull,
0x61090a3b34202c38ull,0x09203436752e6464ull,0x202c303131647225ull,0x7225202c35647225ull,
0x73090a3b39303164ull,0x6c61626f6c672e74ull,0x255b09203233662eull,0x5d302b3031316472ull,
0x0a3b39336625202cull,0x373109636f6c2e09ull,0x61090a3009343409ull,0x09203233732e6464ull,
0x7225202c35327225ull,0x3b327225202c3532ull,0x3109636f6c2e090aull,0x090a300933340937ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c303466ull,0x3b5d3233382b3464ull,
0x33752e646461090aull,0x2c36367225092032ull,0x25202c3532722520ull,0x747663090a3b3472ull,
0x3233752e3436752eull,0x3131316472250920ull,0x0a3b36367225202cull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x647225202c323131ull,0x0a3b34202c313131ull,0x3436752e64646109ull,
0x3331316472250920ull,0x202c35647225202cull,0x0a3b323131647225ull,0x626f6c672e747309ull,
0x09203233662e6c61ull,0x2b3331316472255bull,0x30346625202c5d30ull,0x09636f6c2e090a3bull,
0x0a30093434093731ull,0x3233732e64646109ull,0x202c353272250920ull,0x7225202c35327225ull,
0x636f6c2e090a3b32ull,0x3009333409373109ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3134662509ull,0x3639382b34647225ull,0x2e646461090a3b5dull,0x3672250920323375ull,
0x2c35327225202c37ull,0x63090a3b34722520ull,0x752e3436752e7476ull,0x3164722509203233ull,
0x37367225202c3431ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x25202c3531316472ull,
0x34202c3431316472ull,0x752e646461090a3bull,0x3164722509203436ull,0x35647225202c3631ull,
0x353131647225202cull,0x6c672e7473090a3bull,0x3233662e6c61626full,0x31316472255b0920ull,
0x6625202c5d302b36ull,0x2e646c090a3b3134ull,0x662e646572616873ull,0x3234662509203233ull,
0x2b346472255b202cull,0x61090a3b5d303639ull,0x09203233732e6464ull,0x7225202c38367225ull,
0x3b327225202c3532ull,0x33752e646461090aull,0x2c39367225092032ull,0x7225202c34722520ull,
0x747663090a3b3836ull,0x3233752e3436752eull,0x3731316472250920ull,0x0a3b39367225202cull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x647225202c383131ull,0x0a3b34202c373131ull,
0x3436752e64646109ull,0x3931316472250920ull,0x202c35647225202cull,0x0a3b383131647225ull,
0x626f6c672e747309ull,0x09203233662e6c61ull,0x2b3931316472255bull,0x32346625202c5d30ull,
0x09636f6c2e090a3bull,0x0a30093634093731ull,0x240a3b7469786509ull,0x5f5f646e6557444cull,
0x645f64756c32315aull,0x506c616e6f676169ull,0x207d090a3a696966ull,0x6c32315a5f202f2full,
0x6f676169645f6475ull,0x0a696966506c616eull,0x7972746e652e090aull,0x64756c33315a5f20ull,
0x74656d697265705full,0x2820696966507265ull,0x617261702e09090aull,0x5f203436752e206dull,
0x726170616475635full,0x756c33315a5f5f6dull,0x656d697265705f64ull,0x5f69696650726574ull,
0x61702e09090a2c6dull,0x3233732e206d6172ull,0x70616475635f5f20ull,0x33315a5f5f6d7261ull,
0x697265705f64756cull,0x696650726574656dull,0x78697274616d5f69ull,0x09090a2c6d69645full,
0x2e206d617261702eull,0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x705f64756c33315aull,
0x726574656d697265ull,0x66666f5f69696650ull,0x0a7b090a29746573ull,0x752e206765722e09ull,
0x333c687225203631ull,0x6765722e090a3b3eull,0x7225203233752e20ull,0x090a3b3e3130323cull,
0x36752e206765722eull,0x37323c6472252034ull,0x65722e090a3b3e35ull,0x25203233662e2067ull,
0x090a3b3e32393c66ull,0x72702e206765722eull,0x3e393c7025206465ull,0x726168732e090a3bull,
0x67696c612e206465ull,0x2038622e2034206eull,0x705f616475635f5full,0x31776f725f697265ull,
0x343230315b363530ull,0x6168732e090a3b5dull,0x696c612e20646572ull,0x38622e2034206e67ull,
0x5f616475635f5f20ull,0x5b30383032616964ull,0x090a3b5d34323031ull,0x206465726168732eull,
0x34206e67696c612eull,0x635f5f2038622e20ull,0x697265705f616475ull,0x343031336c6f635full,
0x0a3b5d343230315bull,0x373109636f6c2e09ull,0x4c240a3009393409ull,0x33315a5f5f314242ull,
0x697265705f64756cull,0x696650726574656dull,0x2e747663090a3a69ull,0x203631752e323375ull,
0x7425202c31722509ull,0x6d090a3b782e6469ull,0x09203233752e766full,0x3b3531202c327225ull,
0x6c2e70746573090aull,0x2509203233752e65ull,0x2c317225202c3170ull,0x6d090a3b32722520ull,
0x09203631752e766full,0x6325202c31687225ull,0x0a3b782e64696174ull,0x6469772e6c756d09ull,
0x2509203631752e65ull,0x31687225202c3372ull,0x6c090a3b3631202cull,0x2e6d617261702e64ull,
0x6472250920343675ull,0x75635f5f5b202c31ull,0x5f5f6d7261706164ull,0x705f64756c33315aull,
0x726574656d697265ull,0x3b5d6d5f69696650ull,0x7261702e646c090aull,0x09203233732e6d61ull,
0x5f5f5b202c347225ull,0x6d72617061647563ull,0x64756c33315a5f5full,0x74656d697265705full,
0x6d5f696966507265ull,0x69645f7869727461ull,0x2e646c090a3b5d6dull,0x33732e6d61726170ull,
0x202c357225092032ull,0x70616475635f5f5bull,0x33315a5f5f6d7261ull,0x697265705f64756cull,
0x696650726574656dull,0x74657366666f5f69ull,0x636f6c2e090a3b5dull,0x3009333609373109ull,
0x36752e766f6d090aull,0x2c32647225092034ull,0x5f616475635f5f20ull,0x776f725f69726570ull,
0x6d090a3b36353031ull,0x09203436752e766full,0x5f5f202c33647225ull,0x6169645f61647563ull,
0x2e090a3b30383032ull,0x3609373109636f6cull,0x766f6d090a300939ull,0x722509203436752eull,
0x75635f5f202c3464ull,0x5f697265705f6164ull,0x3b343031336c6f63ull,0x3109636f6c2e090aull,
0x090a300939340937ull,0x7262203170252140ull,0x315f744c24092061ull,0x0a3b30393232315full,
0x373109636f6c2e09ull,0x63090a3009333609ull,0x752e3436752e7476ull,0x3564722509203233ull,
0x090a3b317225202cull,0x09373109636f6c2eull,0x646c090a30093934ull,0x732e6d617261702eull,
0x2c34722509203233ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x7265705f64756c33ull,
0x6650726574656d69ull,0x697274616d5f6969ull,0x0a3b5d6d69645f78ull,0x617261702e646c09ull,
0x2509203233732e6dull,0x635f5f5b202c3572ull,0x5f6d726170616475ull,0x5f64756c33315a5full,
0x6574656d69726570ull,0x666f5f6969665072ull,0x090a3b5d74657366ull,0x09373109636f6c2eull,
0x756d090a30093336ull,0x3233732e6f6c2e6cull,0x25202c3672250920ull,0x3b357225202c3472ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x35647225202c3664ull,0x6461090a3b34202cull,
0x2509203233732e64ull,0x2c367225202c3772ull,0x61090a3b35722520ull,0x09203436752e6464ull,
0x7225202c37647225ull,0x33647225202c3664ull,0x732e646461090a3bull,0x2c38722509203233ull,
0x7225202c37722520ull,0x2e747663090a3b31ull,0x203233732e343673ull,0x25202c3864722509ull,
0x6c756d090a3b3872ull,0x203436752e6f6c2eull,0x25202c3964722509ull,0x0a3b34202c386472ull,
0x373109636f6c2e09ull,0x6c090a3009393409ull,0x2e6d617261702e64ull,0x6472250920343675ull,
0x75635f5f5b202c31ull,0x5f5f6d7261706164ull,0x705f64756c33315aull,0x726574656d697265ull,
0x3b5d6d5f69696650ull,0x3109636f6c2e090aull,0x090a300933360937ull,0x203436752e646461ull,
0x202c303164722509ull,0x7225202c31647225ull,0x2e646c090a3b3964ull,0x662e6c61626f6c67ull,
0x2c31662509203233ull,0x2b30316472255b20ull,0x2e7473090a3b5d30ull,0x662e646572616873ull,
0x6472255b09203233ull,0x6625202c5d302b37ull,0x2e646461090a3b31ull,0x3972250920323373ull,
0x25202c377225202cull,0x646461090a3b3472ull,0x722509203233732eull,0x2c397225202c3031ull,
0x63090a3b31722520ull,0x732e3436732e7476ull,0x3164722509203233ull,0x3b30317225202c31ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c323164ull,0x090a3b34202c3131ull,
0x203436752e646461ull,0x202c333164722509ull,0x7225202c31647225ull,0x646c090a3b323164ull,
0x2e6c61626f6c672eull,0x3266250920323366ull,0x33316472255b202cull,0x7473090a3b5d302bull,
0x2e6465726168732eull,0x72255b0920323366ull,0x202c5d34362b3764ull,0x6461090a3b326625ull,
0x2509203233732e64ull,0x397225202c313172ull,0x090a3b347225202cull,0x203233732e646461ull,
0x25202c3231722509ull,0x317225202c313172ull,0x732e747663090a3bull,0x09203233732e3436ull,
0x25202c3431647225ull,0x756d090a3b323172ull,0x3436752e6f6c2e6cull,0x2c35316472250920ull,
0x202c343164722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x31647225202c3631ull,
0x3b3531647225202cull,0x6f6c672e646c090aull,0x203233662e6c6162ull,0x255b202c33662509ull,
0x3b5d302b36316472ull,0x6168732e7473090aull,0x203233662e646572ull,0x312b376472255b09ull,
0x336625202c5d3832ull,0x732e646461090a3bull,0x3331722509203233ull,0x202c31317225202cull,
0x6461090a3b347225ull,0x2509203233732e64ull,0x317225202c343172ull,0x0a3b317225202c33ull,
0x3436732e74766309ull,0x722509203233732eull,0x317225202c373164ull,0x2e6c756d090a3b34ull,
0x09203436752e6f6cull,0x25202c3831647225ull,0x3b34202c37316472ull,0x36752e646461090aull,
0x3931647225092034ull,0x202c31647225202cull,0x090a3b3831647225ull,0x61626f6c672e646cull,
0x2509203233662e6cull,0x6472255b202c3466ull,0x090a3b5d302b3931ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x3239312b37647225ull,0x0a3b346625202c5dull,0x3233732e64646109ull,
0x202c353172250920ull,0x7225202c33317225ull,0x2e646461090a3b34ull,0x3172250920323373ull,
0x2c35317225202c36ull,0x63090a3b31722520ull,0x732e3436732e7476ull,0x3264722509203233ull,
0x3b36317225202c30ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c313264ull,
0x090a3b34202c3032ull,0x203436752e646461ull,0x202c323264722509ull,0x7225202c31647225ull,
0x646c090a3b313264ull,0x2e6c61626f6c672eull,0x3566250920323366ull,0x32326472255b202cull,
0x7473090a3b5d302bull,0x2e6465726168732eull,0x72255b0920323366ull,0x2c5d3635322b3764ull,
0x61090a3b35662520ull,0x09203233732e6464ull,0x7225202c37317225ull,0x3b347225202c3531ull,
0x33732e646461090aull,0x2c38317225092032ull,0x25202c3731722520ull,0x747663090a3b3172ull,
0x3233732e3436732eull,0x2c33326472250920ull,0x090a3b3831722520ull,0x752e6f6c2e6c756dull,
0x3264722509203436ull,0x3332647225202c34ull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x7225202c35326472ull,0x32647225202c3164ull,0x672e646c090a3b34ull,0x33662e6c61626f6cull,
0x202c366625092032ull,0x302b35326472255bull,0x732e7473090a3b5dull,0x33662e6465726168ull,
0x376472255b092032ull,0x25202c5d3032332bull,0x646461090a3b3666ull,0x722509203233732eull,
0x37317225202c3931ull,0x090a3b347225202cull,0x203233732e646461ull,0x25202c3032722509ull,
0x317225202c393172ull,0x732e747663090a3bull,0x09203233732e3436ull,0x25202c3632647225ull,
0x756d090a3b303272ull,0x3436752e6f6c2e6cull,0x2c37326472250920ull,0x202c363264722520ull,
0x2e646461090a3b34ull,0x6472250920343675ull,0x31647225202c3832ull,0x3b3732647225202cull,
0x6f6c672e646c090aull,0x203233662e6c6162ull,0x255b202c37662509ull,0x3b5d302b38326472ull,
0x6168732e7473090aull,0x203233662e646572ull,0x332b376472255b09ull,0x376625202c5d3438ull,
0x732e646461090a3bull,0x3132722509203233ull,0x202c39317225202cull,0x6461090a3b347225ull,
0x2509203233732e64ull,0x327225202c323272ull,0x0a3b317225202c31ull,0x3436732e74766309ull,
0x722509203233732eull,0x327225202c393264ull,0x2e6c756d090a3b32ull,0x09203436752e6f6cull,
0x25202c3033647225ull,0x3b34202c39326472ull,0x36752e646461090aull,0x3133647225092034ull,
0x202c31647225202cull,0x090a3b3033647225ull,0x61626f6c672e646cull,0x2509203233662e6cull,
0x6472255b202c3866ull,0x090a3b5d302b3133ull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x3834342b37647225ull,0x0a3b386625202c5dull,0x373109636f6c2e09ull,0x61090a3009393609ull,
0x09203436752e6464ull,0x25202c3233647225ull,0x647225202c366472ull,0x2e646461090a3b32ull,
0x3272250920323375ull,0x202c377225202c33ull,0x6461090a3b337225ull,0x2509203233752e64ull,
0x317225202c343272ull,0x0a3b33327225202cull,0x3436752e74766309ull,0x722509203233752eull,
0x327225202c333364ull,0x2e6c756d090a3b34ull,0x09203436752e6f6cull,0x25202c3433647225ull,
0x3b34202c33336472ull,0x36752e646461090aull,0x3533647225092034ull,0x202c31647225202cull,
0x090a3b3433647225ull,0x61626f6c672e646cull,0x2509203233662e6cull,0x6472255b202c3966ull,
0x0a3b5d34362b3533ull,0x726168732e747309ull,0x09203233662e6465ull,0x302b32336472255bull,
0x0a3b396625202c5dull,0x3233752e64646109ull,0x202c353272250920ull,0x337225202c397225ull,
0x752e646461090a3bull,0x3632722509203233ull,0x25202c317225202cull,0x7663090a3b353272ull,
0x33752e3436752e74ull,0x3633647225092032ull,0x0a3b36327225202cull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x33647225202c3733ull,0x61090a3b34202c36ull,0x09203436752e6464ull,
0x25202c3833647225ull,0x647225202c316472ull,0x2e646c090a3b3733ull,0x662e6c61626f6c67ull,
0x3031662509203233ull,0x38336472255b202cull,0x73090a3b5d34362bull,0x6465726168732e74ull,
0x255b09203233662eull,0x5d34362b32336472ull,0x0a3b30316625202cull,0x3233752e64646109ull,
0x202c373272250920ull,0x7225202c31317225ull,0x2e646461090a3b33ull,0x3272250920323375ull,
0x202c317225202c38ull,0x63090a3b37327225ull,0x752e3436752e7476ull,0x3364722509203233ull,
0x3b38327225202c39ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c303464ull,
0x090a3b34202c3933ull,0x203436752e646461ull,0x202c313464722509ull,0x7225202c31647225ull,
0x646c090a3b303464ull,0x2e6c61626f6c672eull,0x3166250920323366ull,0x346472255b202c31ull,
0x090a3b5d34362b31ull,0x65726168732e7473ull,0x5b09203233662e64ull,0x32312b3233647225ull,
0x31316625202c5d38ull,0x752e646461090a3bull,0x3932722509203233ull,0x202c33317225202cull,
0x6461090a3b337225ull,0x2509203233752e64ull,0x317225202c303372ull,0x0a3b39327225202cull,
0x3436752e74766309ull,0x722509203233752eull,0x337225202c323464ull,0x2e6c756d090a3b30ull,
0x09203436752e6f6cull,0x25202c3334647225ull,0x3b34202c32346472ull,0x36752e646461090aull,
0x3434647225092034ull,0x202c31647225202cull,0x090a3b3334647225ull,0x61626f6c672e646cull,
0x2509203233662e6cull,0x72255b202c323166ull,0x3b5d34362b343464ull,0x6168732e7473090aull,
0x203233662e646572ull,0x2b32336472255b09ull,0x6625202c5d323931ull,0x646461090a3b3231ull,
0x722509203233752eull,0x35317225202c3133ull,0x090a3b337225202cull,0x203233752e646461ull,
0x25202c3233722509ull,0x31337225202c3172ull,0x752e747663090a3bull,0x09203233752e3436ull,
0x25202c3534647225ull,0x756d090a3b323372ull,0x3436752e6f6c2e6cull,0x2c36346472250920ull,
0x202c353464722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x31647225202c3734ull,
0x3b3634647225202cull,0x6f6c672e646c090aull,0x203233662e6c6162ull,0x5b202c3331662509ull,
0x34362b3734647225ull,0x732e7473090a3b5dull,0x33662e6465726168ull,0x336472255b092032ull,
0x202c5d3635322b32ull,0x61090a3b33316625ull,0x09203233752e6464ull,0x7225202c33337225ull,
0x3b337225202c3731ull,0x33752e646461090aull,0x2c34337225092032ull,0x7225202c31722520ull,
0x747663090a3b3333ull,0x3233752e3436752eull,0x2c38346472250920ull,0x090a3b3433722520ull,
0x752e6f6c2e6c756dull,0x3464722509203436ull,0x3834647225202c39ull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x7225202c30356472ull,0x34647225202c3164ull,0x672e646c090a3b39ull,
0x33662e6c61626f6cull,0x2c34316625092032ull,0x2b30356472255b20ull,0x7473090a3b5d3436ull,
0x2e6465726168732eull,0x72255b0920323366ull,0x5d3032332b323364ull,0x0a3b34316625202cull,
0x3233752e64646109ull,0x202c353372250920ull,0x7225202c39317225ull,0x2e646461090a3b33ull,
0x3372250920323375ull,0x202c317225202c36ull,0x63090a3b35337225ull,0x752e3436752e7476ull,
0x3564722509203233ull,0x3b36337225202c31ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c323564ull,0x090a3b34202c3135ull,0x203436752e646461ull,0x202c333564722509ull,
0x7225202c31647225ull,0x646c090a3b323564ull,0x2e6c61626f6c672eull,0x3166250920323366ull,
0x356472255b202c35ull,0x090a3b5d34362b33ull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x38332b3233647225ull,0x35316625202c5d34ull,0x752e646461090a3bull,0x3733722509203233ull,
0x202c31327225202cull,0x6461090a3b337225ull,0x2509203233752e64ull,0x317225202c383372ull,
0x0a3b37337225202cull,0x3436752e74766309ull,0x722509203233752eull,0x337225202c343564ull,
0x2e6c756d090a3b38ull,0x09203436752e6f6cull,0x25202c3535647225ull,0x3b34202c34356472ull,
0x36752e646461090aull,0x3635647225092034ull,0x202c31647225202cull,0x090a3b3535647225ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x72255b202c363166ull,0x3b5d34362b363564ull,
0x6168732e7473090aull,0x203233662e646572ull,0x2b32336472255b09ull,0x6625202c5d383434ull,
0x646461090a3b3631ull,0x722509203233732eull,0x31327225202c3933ull,0x090a3b347225202cull,
0x203233752e646461ull,0x25202c3034722509ull,0x337225202c393372ull,0x752e646461090a3bull,
0x3134722509203233ull,0x25202c317225202cull,0x7663090a3b303472ull,0x33752e3436752e74ull,
0x3735647225092032ull,0x0a3b31347225202cull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x35647225202c3835ull,0x61090a3b34202c37ull,0x09203436752e6464ull,0x25202c3935647225ull,
0x647225202c316472ull,0x2e646c090a3b3835ull,0x662e6c61626f6c67ull,0x3731662509203233ull,
0x39356472255b202cull,0x73090a3b5d34362bull,0x6465726168732e74ull,0x255b09203233662eull,
0x3231352b32336472ull,0x3b37316625202c5dull,0x33732e646461090aull,0x2c32347225092032ull,
0x25202c3933722520ull,0x646461090a3b3472ull,0x722509203233752eull,0x32347225202c3334ull,
0x090a3b337225202cull,0x203233752e646461ull,0x25202c3434722509ull,0x33347225202c3172ull,
0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3036647225ull,0x756d090a3b343472ull,
0x3436752e6f6c2e6cull,0x2c31366472250920ull,0x202c303664722520ull,0x2e646461090a3b34ull,
0x6472250920343675ull,0x31647225202c3236ull,0x3b3136647225202cull,0x6f6c672e646c090aull,
0x203233662e6c6162ull,0x5b202c3831662509ull,0x34362b3236647225ull,0x732e7473090a3b5dull,
0x33662e6465726168ull,0x336472255b092032ull,0x202c5d3637352b32ull,0x2e090a3b38316625ull,
0x3709373109636f6cull,0x646461090a300930ull,0x722509203233732eull,0x32347225202c3534ull,
0x090a3b347225202cull,0x09373109636f6c2eull,0x6461090a30093936ull,0x2509203233752e64ull,
0x347225202c363472ull,0x0a3b337225202c35ull,0x3233752e64646109ull,0x202c373472250920ull,
0x347225202c317225ull,0x2e747663090a3b36ull,0x203233752e343675ull,0x202c333664722509ull,
0x6d090a3b37347225ull,0x36752e6f6c2e6c75ull,0x3436647225092034ull,0x2c3336647225202cull,
0x646461090a3b3420ull,0x722509203436752eull,0x647225202c353664ull,0x3436647225202c31ull,
0x6c672e646c090a3bull,0x3233662e6c61626full,0x202c393166250920ull,0x362b35366472255bull,
0x2e7473090a3b5d34ull,0x662e646572616873ull,0x6472255b09203233ull,0x2c5d3034362b3233ull,
0x090a3b3931662520ull,0x09373109636f6c2eull,0x6461090a30093037ull,0x2509203233732e64ull,
0x347225202c353472ull,0x0a3b347225202c35ull,0x373109636f6c2e09ull,0x61090a3009393609ull,
0x09203233752e6464ull,0x7225202c38347225ull,0x3b337225202c3534ull,0x33752e646461090aull,
0x2c39347225092032ull,0x7225202c31722520ull,0x747663090a3b3834ull,0x3233752e3436752eull,
0x2c36366472250920ull,0x090a3b3934722520ull,0x752e6f6c2e6c756dull,0x3664722509203436ull,
0x3636647225202c37ull,0x6461090a3b34202cull,0x2509203436752e64ull,0x7225202c38366472ull,
0x36647225202c3164ull,0x672e646c090a3b37ull,0x33662e6c61626f6cull,0x2c30326625092032ull,
0x2b38366472255b20ull,0x7473090a3b5d3436ull,0x2e6465726168732eull,0x72255b0920323366ull,
0x5d3430372b323364ull,0x0a3b30326625202cull,0x373109636f6c2e09ull,0x61090a3009303709ull,
0x09203233732e6464ull,0x7225202c35347225ull,0x3b347225202c3534ull,0x3109636f6c2e090aull,
0x090a300939360937ull,0x203233752e646461ull,0x25202c3035722509ull,0x337225202c353472ull,
0x752e646461090a3bull,0x3135722509203233ull,0x25202c317225202cull,0x7663090a3b303572ull,
0x33752e3436752e74ull,0x3936647225092032ull,0x0a3b31357225202cull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x36647225202c3037ull,0x61090a3b34202c39ull,0x09203436752e6464ull,
0x25202c3137647225ull,0x647225202c316472ull,0x2e646c090a3b3037ull,0x662e6c61626f6c67ull,
0x3132662509203233ull,0x31376472255b202cull,0x73090a3b5d34362bull,0x6465726168732e74ull,
0x255b09203233662eull,0x3836372b32336472ull,0x3b31326625202c5dull,0x3109636f6c2e090aull,
0x090a300930370937ull,0x203233732e646461ull,0x25202c3534722509ull,0x347225202c353472ull,
0x09636f6c2e090a3bull,0x0a30093936093731ull,0x3233752e64646109ull,0x202c323572250920ull,
0x7225202c35347225ull,0x2e646461090a3b33ull,0x3572250920323375ull,0x202c317225202c33ull,
0x63090a3b32357225ull,0x752e3436752e7476ull,0x3764722509203233ull,0x3b33357225202c32ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c333764ull,0x090a3b34202c3237ull,
0x203436752e646461ull,0x202c343764722509ull,0x7225202c31647225ull,0x646c090a3b333764ull,
0x2e6c61626f6c672eull,0x3266250920323366ull,0x376472255b202c32ull,0x090a3b5d34362b34ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x33382b3233647225ull,0x32326625202c5d32ull,
0x09636f6c2e090a3bull,0x0a30093037093731ull,0x3233732e64646109ull,0x202c353472250920ull,
0x7225202c35347225ull,0x636f6c2e090a3b34ull,0x3009393609373109ull,0x33752e646461090aull,
0x2c34357225092032ull,0x25202c3534722520ull,0x646461090a3b3372ull,0x722509203233752eull,
0x2c317225202c3535ull,0x090a3b3435722520ull,0x2e3436752e747663ull,0x6472250920323375ull,
0x35357225202c3537ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c36376472ull,
0x0a3b34202c353764ull,0x3436752e64646109ull,0x2c37376472250920ull,0x25202c3164722520ull,
0x6c090a3b36376472ull,0x6c61626f6c672e64ull,0x662509203233662eull,0x6472255b202c3332ull,
0x0a3b5d34362b3737ull,0x726168732e747309ull,0x09203233662e6465ull,0x382b32336472255bull,
0x326625202c5d3639ull,0x2e646461090a3b33ull,0x3572250920323373ull,0x2c35347225202c36ull,
0x61090a3b34722520ull,0x09203233752e6464ull,0x7225202c37357225ull,0x3b36357225202c33ull,
0x33752e646461090aull,0x2c38357225092032ull,0x7225202c31722520ull,0x747663090a3b3735ull,
0x3233752e3436752eull,0x2c38376472250920ull,0x090a3b3835722520ull,0x752e6f6c2e6c756dull,
0x3764722509203436ull,0x3837647225202c39ull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x7225202c30386472ull,0x37647225202c3164ull,0x672e646c090a3b39ull,0x33662e6c61626f6cull,
0x2c34326625092032ull,0x2b30386472255b20ull,0x7473090a3b5d3436ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x5d3036392b323364ull,0x0a3b34326625202cull,0x696e752e61726209ull,
0x5f315f744c240920ull,0x240a3b3433303231ull,0x3232315f315f744cull,0x6f6c2e090a3a3039ull,
0x0939340937310963ull,0x61702e646c090a30ull,0x203233732e6d6172ull,0x5f5b202c35722509ull,
0x726170616475635full,0x756c33315a5f5f6dull,0x656d697265705f64ull,0x5f69696650726574ull,
0x3b5d74657366666full,0x3109636f6c2e090aull,0x090a300938370937ull,0x203233732e646461ull,
0x25202c3935722509ull,0x090a3b38202c3572ull,0x2e3436732e747663ull,0x6472250920323373ull,
0x3b317225202c3138ull,0x3109636f6c2e090aull,0x090a300939340937ull,0x6d617261702e646cull,
0x722509203233732eull,0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,0x705f64756c33315aull,
0x726574656d697265ull,0x74616d5f69696650ull,0x5d6d69645f786972ull,0x09636f6c2e090a3bull,
0x0a30093837093731ull,0x2e6f6c2e6c756d09ull,0x3672250920323373ull,0x2c39357225202c30ull,
0x6d090a3b34722520ull,0x36752e6f6c2e6c75ull,0x3238647225092034ull,0x2c3138647225202cull,
0x646461090a3b3420ull,0x722509203233732eull,0x30367225202c3136ull,0x090a3b357225202cull,
0x203436752e646461ull,0x202c333864722509ull,0x25202c3238647225ull,0x6461090a3b336472ull,
0x2509203233732e64ull,0x367225202c323672ull,0x0a3b317225202c31ull,0x3436732e74766309ull,
0x722509203233732eull,0x367225202c343864ull,0x2e6c756d090a3b32ull,0x09203436752e6f6cull,
0x25202c3538647225ull,0x3b34202c34386472ull,0x3109636f6c2e090aull,0x090a300939340937ull,
0x6d617261702e646cull,0x722509203436752eull,0x635f5f5b202c3164ull,0x5f6d726170616475ull,
0x5f64756c33315a5full,0x6574656d69726570ull,0x5d6d5f6969665072ull,0x09636f6c2e090a3bull,
0x0a30093837093731ull,0x3436752e64646109ull,0x2c36386472250920ull,0x25202c3164722520ull,
0x6c090a3b35386472ull,0x6c61626f6c672e64ull,0x662509203233662eull,0x6472255b202c3532ull,
0x3b5d34362d2b3638ull,0x6168732e7473090aull,0x203233662e646572ull,0x2b33386472255b09ull,
0x6625202c5d383434ull,0x646461090a3b3532ull,0x722509203233732eull,0x31367225202c3336ull,
0x090a3b347225202cull,0x203233732e646461ull,0x25202c3436722509ull,0x317225202c333672ull,
0x732e747663090a3bull,0x09203233732e3436ull,0x25202c3738647225ull,0x756d090a3b343672ull,
0x3436752e6f6c2e6cull,0x2c38386472250920ull,0x202c373864722520ull,0x2e646461090a3b34ull,
0x6472250920343675ull,0x31647225202c3938ull,0x3b3838647225202cull,0x6f6c672e646c090aull,
0x203233662e6c6162ull,0x5b202c3632662509ull,0x362d2b3938647225ull,0x2e7473090a3b5d34ull,
0x662e646572616873ull,0x6472255b09203233ull,0x2c5d3231352b3338ull,0x090a3b3632662520ull,
0x203233732e646461ull,0x25202c3536722509ull,0x347225202c333672ull,0x732e646461090a3bull,
0x3636722509203233ull,0x202c35367225202cull,0x7663090a3b317225ull,0x33732e3436732e74ull,
0x3039647225092032ull,0x0a3b36367225202cull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x39647225202c3139ull,0x61090a3b34202c30ull,0x09203436752e6464ull,0x25202c3239647225ull,
0x647225202c316472ull,0x2e646c090a3b3139ull,0x662e6c61626f6c67ull,0x3732662509203233ull,
0x32396472255b202cull,0x090a3b5d34362d2bull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x37352b3338647225ull,0x37326625202c5d36ull,0x732e646461090a3bull,0x3736722509203233ull,
0x202c35367225202cull,0x6461090a3b347225ull,0x2509203233732e64ull,0x367225202c383672ull,
0x0a3b317225202c37ull,0x3436732e74766309ull,0x722509203233732eull,0x367225202c333964ull,
0x2e6c756d090a3b38ull,0x09203436752e6f6cull,0x25202c3439647225ull,0x3b34202c33396472ull,
0x36752e646461090aull,0x3539647225092034ull,0x202c31647225202cull,0x090a3b3439647225ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x72255b202c383266ull,0x5d34362d2b353964ull,
0x68732e7473090a3bull,0x3233662e64657261ull,0x33386472255b0920ull,0x25202c5d3034362bull,
0x6461090a3b383266ull,0x2509203233732e64ull,0x367225202c393672ull,0x0a3b347225202c37ull,
0x3233732e64646109ull,0x202c303772250920ull,0x7225202c39367225ull,0x2e747663090a3b31ull,
0x203233732e343673ull,0x202c363964722509ull,0x6d090a3b30377225ull,0x36752e6f6c2e6c75ull,
0x3739647225092034ull,0x2c3639647225202cull,0x646461090a3b3420ull,0x722509203436752eull,
0x647225202c383964ull,0x3739647225202c31ull,0x6c672e646c090a3bull,0x3233662e6c61626full,
0x202c393266250920ull,0x2d2b38396472255bull,0x7473090a3b5d3436ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x5d3430372b333864ull,0x0a3b39326625202cull,0x3233732e64646109ull,
0x202c313772250920ull,0x7225202c39367225ull,0x2e646461090a3b34ull,0x3772250920323373ull,
0x2c31377225202c32ull,0x63090a3b31722520ull,0x732e3436732e7476ull,0x3964722509203233ull,
0x3b32377225202c39ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x7225202c30303164ull,
0x0a3b34202c393964ull,0x3436752e64646109ull,0x3130316472250920ull,0x202c31647225202cull,
0x0a3b303031647225ull,0x626f6c672e646c09ull,0x09203233662e6c61ull,0x255b202c30336625ull,
0x362d2b3130316472ull,0x2e7473090a3b5d34ull,0x662e646572616873ull,0x6472255b09203233ull,
0x2c5d3836372b3338ull,0x090a3b3033662520ull,0x203233732e646461ull,0x25202c3337722509ull,
0x347225202c313772ull,0x732e646461090a3bull,0x3437722509203233ull,0x202c33377225202cull,
0x7663090a3b317225ull,0x33732e3436732e74ull,0x3031647225092032ull,0x3b34377225202c32ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x7225202c33303164ull,0x3b34202c32303164ull,
0x36752e646461090aull,0x3031647225092034ull,0x2c31647225202c34ull,0x3b33303164722520ull,
0x6f6c672e646c090aull,0x203233662e6c6162ull,0x5b202c3133662509ull,0x2d2b343031647225ull,
0x7473090a3b5d3436ull,0x2e6465726168732eull,0x72255b0920323366ull,0x5d3233382b333864ull,
0x0a3b31336625202cull,0x3233732e64646109ull,0x202c353772250920ull,0x7225202c33377225ull,
0x2e646461090a3b34ull,0x3772250920323373ull,0x202c317225202c36ull,0x63090a3b35377225ull,
0x732e3436732e7476ull,0x3164722509203233ull,0x36377225202c3530ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x25202c3630316472ull,0x34202c3530316472ull,0x752e646461090a3bull,
0x3164722509203436ull,0x31647225202c3730ull,0x363031647225202cull,0x6c672e646c090a3bull,
0x3233662e6c61626full,0x202c323366250920ull,0x2b3730316472255bull,0x73090a3b5d34362dull,
0x6465726168732e74ull,0x255b09203233662eull,0x3639382b33386472ull,0x3b32336625202c5dull,
0x3109636f6c2e090aull,0x090a300934380937ull,0x203233752e646461ull,0x25202c3737722509ull,
0x3b337225202c3572ull,0x36752e646461090aull,0x3031647225092034ull,0x3238647225202c38ull,
0x0a3b34647225202cull,0x3233752e64646109ull,0x202c383772250920ull,0x3631202c37377225ull,
0x6c2e6c756d090a3bull,0x2509203233752e6full,0x347225202c393772ull,0x0a3b38377225202cull,
0x3233752e64646109ull,0x202c303872250920ull,0x377225202c357225ull,0x2e646461090a3b39ull,
0x3872250920323373ull,0x2c30387225202c31ull,0x63090a3b31722520ull,0x732e3436732e7476ull,
0x3164722509203233ull,0x31387225202c3930ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x25202c3031316472ull,0x34202c3930316472ull,0x752e646461090a3bull,0x3164722509203436ull,
0x31647225202c3131ull,0x303131647225202cull,0x6c672e646c090a3bull,0x3233662e6c61626full,
0x202c333366250920ull,0x2b3131316472255bull,0x73090a3b5d34362dull,0x6465726168732e74ull,
0x255b09203233662eull,0x362d2b3830316472ull,0x33336625202c5d34ull,0x732e646461090a3bull,
0x3238722509203233ull,0x25202c347225202cull,0x6461090a3b303872ull,0x2509203233732e64ull,
0x387225202c333872ull,0x0a3b317225202c32ull,0x3436732e74766309ull,0x722509203233732eull,
0x7225202c32313164ull,0x6c756d090a3b3338ull,0x203436752e6f6c2eull,0x2c33313164722509ull,
0x2c32313164722520ull,0x646461090a3b3420ull,0x722509203436752eull,0x7225202c34313164ull,
0x31647225202c3164ull,0x2e646c090a3b3331ull,0x662e6c61626f6c67ull,0x3433662509203233ull,
0x31316472255b202cull,0x0a3b5d34362d2b34ull,0x726168732e747309ull,0x09203233662e6465ull,
0x2b3830316472255bull,0x34336625202c5d30ull,0x732e646461090a3bull,0x3438722509203233ull,
0x202c32387225202cull,0x6461090a3b347225ull,0x2509203233732e64ull,0x387225202c353872ull,
0x0a3b317225202c34ull,0x3436732e74766309ull,0x722509203233732eull,0x7225202c35313164ull,
0x6c756d090a3b3538ull,0x203436752e6f6c2eull,0x2c36313164722509ull,0x2c35313164722520ull,
0x646461090a3b3420ull,0x722509203436752eull,0x7225202c37313164ull,0x31647225202c3164ull,
0x2e646c090a3b3631ull,0x662e6c61626f6c67ull,0x3533662509203233ull,0x31316472255b202cull,
0x0a3b5d34362d2b37ull,0x726168732e747309ull,0x09203233662e6465ull,0x2b3830316472255bull,
0x336625202c5d3436ull,0x2e646461090a3b35ull,0x3872250920323373ull,0x2c34387225202c36ull,
0x61090a3b34722520ull,0x09203233732e6464ull,0x7225202c37387225ull,0x3b317225202c3638ull,
0x36732e747663090aull,0x2509203233732e34ull,0x25202c3831316472ull,0x756d090a3b373872ull,
0x3436752e6f6c2e6cull,0x3931316472250920ull,0x383131647225202cull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x25202c3032316472ull,0x647225202c316472ull,0x646c090a3b393131ull,
0x2e6c61626f6c672eull,0x3366250920323366ull,0x316472255b202c36ull,0x3b5d34362d2b3032ull,
0x6168732e7473090aull,0x203233662e646572ull,0x3830316472255b09ull,0x25202c5d3832312bull,
0x6461090a3b363366ull,0x2509203233732e64ull,0x387225202c383872ull,0x0a3b347225202c36ull,
0x3233732e64646109ull,0x202c393872250920ull,0x7225202c38387225ull,0x2e747663090a3b31ull,
0x203233732e343673ull,0x2c31323164722509ull,0x090a3b3938722520ull,0x752e6f6c2e6c756dull,
0x3164722509203436ull,0x31647225202c3232ull,0x090a3b34202c3132ull,0x203436752e646461ull,
0x2c33323164722509ull,0x25202c3164722520ull,0x090a3b3232316472ull,0x61626f6c672e646cull,
0x2509203233662e6cull,0x72255b202c373366ull,0x34362d2b33323164ull,0x732e7473090a3b5dull,
0x33662e6465726168ull,0x316472255b092032ull,0x2c5d3239312b3830ull,0x090a3b3733662520ull,
0x203233732e646461ull,0x25202c3039722509ull,0x347225202c383872ull,0x732e646461090a3bull,
0x3139722509203233ull,0x202c30397225202cull,0x7663090a3b317225ull,0x33732e3436732e74ull,
0x3231647225092032ull,0x3b31397225202c34ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x7225202c35323164ull,0x3b34202c34323164ull,0x36752e646461090aull,0x3231647225092034ull,
0x2c31647225202c36ull,0x3b35323164722520ull,0x6f6c672e646c090aull,0x203233662e6c6162ull,
0x5b202c3833662509ull,0x2d2b363231647225ull,0x7473090a3b5d3436ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x3635322b38303164ull,0x3b38336625202c5dull,0x33732e646461090aull,
0x2c32397225092032ull,0x25202c3039722520ull,0x646461090a3b3472ull,0x722509203233732eull,
0x32397225202c3339ull,0x090a3b317225202cull,0x2e3436732e747663ull,0x6472250920323373ull,
0x397225202c373231ull,0x2e6c756d090a3b33ull,0x09203436752e6f6cull,0x202c383231647225ull,
0x202c373231647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x647225202c393231ull,
0x3231647225202c31ull,0x672e646c090a3b38ull,0x33662e6c61626f6cull,0x2c39336625092032ull,
0x3932316472255b20ull,0x090a3b5d34362d2bull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x332b383031647225ull,0x336625202c5d3032ull,0x636f6c2e090a3b39ull,0x3009353809373109ull,
0x33732e646461090aull,0x2c34397225092032ull,0x25202c3239722520ull,0x6f6c2e090a3b3472ull,
0x0934380937310963ull,0x732e646461090a30ull,0x3539722509203233ull,0x202c34397225202cull,
0x7663090a3b317225ull,0x33732e3436732e74ull,0x3331647225092032ull,0x3b35397225202c30ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x7225202c31333164ull,0x3b34202c30333164ull,
0x36752e646461090aull,0x3331647225092034ull,0x2c31647225202c32ull,0x3b31333164722520ull,
0x6f6c672e646c090aull,0x203233662e6c6162ull,0x5b202c3034662509ull,0x2d2b323331647225ull,
0x7473090a3b5d3436ull,0x2e6465726168732eull,0x72255b0920323366ull,0x3438332b38303164ull,
0x3b30346625202c5dull,0x3109636f6c2e090aull,0x090a300935380937ull,0x203233732e646461ull,
0x25202c3639722509ull,0x347225202c343972ull,0x09636f6c2e090a3bull,0x0a30093438093731ull,
0x3233732e64646109ull,0x202c373972250920ull,0x7225202c36397225ull,0x2e747663090a3b31ull,
0x203233732e343673ull,0x2c33333164722509ull,0x090a3b3739722520ull,0x752e6f6c2e6c756dull,
0x3164722509203436ull,0x31647225202c3433ull,0x090a3b34202c3333ull,0x203436752e646461ull,
0x2c35333164722509ull,0x25202c3164722520ull,0x090a3b3433316472ull,0x61626f6c672e646cull,
0x2509203233662e6cull,0x72255b202c313466ull,0x34362d2b35333164ull,0x732e7473090a3b5dull,
0x33662e6465726168ull,0x316472255b092032ull,0x2c5d3834342b3830ull,0x090a3b3134662520ull,
0x09373109636f6c2eull,0x6461090a30093538ull,0x2509203233732e64ull,0x397225202c383972ull,
0x0a3b347225202c36ull,0x373109636f6c2e09ull,0x61090a3009343809ull,0x09203233732e6464ull,
0x7225202c39397225ull,0x3b317225202c3839ull,0x36732e747663090aull,0x2509203233732e34ull,
0x25202c3633316472ull,0x756d090a3b393972ull,0x3436752e6f6c2e6cull,0x3733316472250920ull,
0x363331647225202cull,0x6461090a3b34202cull,0x2509203436752e64ull,0x25202c3833316472ull,
0x647225202c316472ull,0x646c090a3b373331ull,0x2e6c61626f6c672eull,0x3466250920323366ull,
0x316472255b202c32ull,0x3b5d34362d2b3833ull,0x6168732e7473090aull,0x203233662e646572ull,
0x3830316472255b09ull,0x25202c5d3231352bull,0x6c2e090a3b323466ull,0x353809373109636full,
0x2e646461090a3009ull,0x3172250920323373ull,0x38397225202c3030ull,0x090a3b347225202cull,
0x09373109636f6c2eull,0x6461090a30093438ull,0x2509203233732e64ull,0x7225202c31303172ull,
0x317225202c303031ull,0x732e747663090a3bull,0x09203233732e3436ull,0x202c393331647225ull,
0x090a3b3130317225ull,0x752e6f6c2e6c756dull,0x3164722509203436ull,0x31647225202c3034ull,
0x090a3b34202c3933ull,0x203436752e646461ull,0x2c31343164722509ull,0x25202c3164722520ull,
0x090a3b3034316472ull,0x61626f6c672e646cull,0x2509203233662e6cull,0x72255b202c333466ull,
0x34362d2b31343164ull,0x732e7473090a3b5dull,0x33662e6465726168ull,0x316472255b092032ull,
0x2c5d3637352b3830ull,0x090a3b3334662520ull,0x09373109636f6c2eull,0x6461090a30093538ull,
0x2509203233732e64ull,0x7225202c32303172ull,0x347225202c303031ull,0x09636f6c2e090a3bull,
0x0a30093438093731ull,0x3233732e64646109ull,0x2c33303172250920ull,0x202c323031722520ull,
0x7663090a3b317225ull,0x33732e3436732e74ull,0x3431647225092032ull,0x3330317225202c32ull,
0x6c2e6c756d090a3bull,0x2509203436752e6full,0x25202c3334316472ull,0x34202c3234316472ull,
0x752e646461090a3bull,0x3164722509203436ull,0x31647225202c3434ull,0x333431647225202cull,
0x6c672e646c090a3bull,0x3233662e6c61626full,0x202c343466250920ull,0x2b3434316472255bull,
0x73090a3b5d34362dull,0x6465726168732e74ull,0x255b09203233662eull,0x34362b3830316472ull,
0x34346625202c5d30ull,0x09636f6c2e090a3bull,0x0a30093538093731ull,0x3233732e64646109ull,
0x2c34303172250920ull,0x202c323031722520ull,0x6c2e090a3b347225ull,0x343809373109636full,
0x2e646461090a3009ull,0x3172250920323373ull,0x30317225202c3530ull,0x0a3b317225202c34ull,
0x3436732e74766309ull,0x722509203233732eull,0x7225202c35343164ull,0x756d090a3b353031ull,
0x3436752e6f6c2e6cull,0x3634316472250920ull,0x353431647225202cull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x25202c3734316472ull,0x647225202c316472ull,0x646c090a3b363431ull,
0x2e6c61626f6c672eull,0x3466250920323366ull,0x316472255b202c35ull,0x3b5d34362d2b3734ull,
0x6168732e7473090aull,0x203233662e646572ull,0x3830316472255b09ull,0x25202c5d3430372bull,
0x6c2e090a3b353466ull,0x353809373109636full,0x2e646461090a3009ull,0x3172250920323373ull,
0x30317225202c3630ull,0x0a3b347225202c34ull,0x373109636f6c2e09ull,0x61090a3009343809ull,
0x09203233732e6464ull,0x25202c3730317225ull,0x7225202c36303172ull,0x2e747663090a3b31ull,
0x203233732e343673ull,0x2c38343164722509ull,0x0a3b373031722520ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x647225202c393431ull,0x0a3b34202c383431ull,0x3436752e64646109ull,
0x3035316472250920ull,0x202c31647225202cull,0x0a3b393431647225ull,0x626f6c672e646c09ull,
0x09203233662e6c61ull,0x255b202c36346625ull,0x362d2b3035316472ull,0x2e7473090a3b5d34ull,
0x662e646572616873ull,0x6472255b09203233ull,0x5d3836372b383031ull,0x0a3b36346625202cull,
0x373109636f6c2e09ull,0x61090a3009353809ull,0x09203233732e6464ull,0x25202c3830317225ull,
0x7225202c36303172ull,0x636f6c2e090a3b34ull,0x3009343809373109ull,0x33732e646461090aull,
0x3930317225092032ull,0x2c3830317225202cull,0x63090a3b31722520ull,0x732e3436732e7476ull,
0x3164722509203233ull,0x30317225202c3135ull,0x2e6c756d090a3b39ull,0x09203436752e6f6cull,
0x202c323531647225ull,0x202c313531647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x647225202c333531ull,0x3531647225202c31ull,0x672e646c090a3b32ull,0x33662e6c61626f6cull,
0x2c37346625092032ull,0x3335316472255b20ull,0x090a3b5d34362d2bull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x382b383031647225ull,0x346625202c5d3233ull,0x2e646461090a3b37ull,
0x3172250920323373ull,0x30317225202c3031ull,0x0a3b347225202c38ull,0x3233732e64646109ull,
0x2c31313172250920ull,0x7225202c31722520ull,0x7663090a3b303131ull,0x33732e3436732e74ull,
0x3531647225092032ull,0x3131317225202c34ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x25202c3535316472ull,0x34202c3435316472ull,0x752e646461090a3bull,0x3164722509203436ull,
0x31647225202c3635ull,0x353531647225202cull,0x6c672e646c090a3bull,0x3233662e6c61626full,
0x202c383466250920ull,0x2b3635316472255bull,0x73090a3b5d34362dull,0x6465726168732e74ull,
0x255b09203233662eull,0x39382b3830316472ull,0x38346625202c5d36ull,0x5f315f744c240a3bull,
0x090a3a3433303231ull,0x09373109636f6c2eull,0x6162090a30093938ull,0x0920636e79732e72ull,
0x70252140090a3b30ull,0x2409206172622031ull,0x3832315f315f744cull,0x747663090a3b3230ull,
0x3233752e3436752eull,0x202c356472250920ull,0x6f6d090a3b317225ull,0x2509203233732e76ull,
0x3b31202c32313172ull,0x315f315f744c240aull,0x2f200a3a30373533ull,0x203e706f6f6c3c2full,
0x646f6220706f6f4cull,0x3820656e696c2079ull,0x697473656e202c39ull,0x687470656420676eull,
0x657469202c31203aull,0x3a736e6f69746172ull,0x766f6d090a353120ull,0x722509203233752eull,
0x0a3b30202c333131ull,0x656c2e7074657309ull,0x702509203233732eull,0x3231317225202c32ull,
0x3b3331317225202cull,0x622032702540090aull,0x5f744c2409206172ull,0x3b36323833315f31ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x6568202c39382065ull,0x6c6562616c206461ull,0x315f744c24206465ull,0x090a30373533315full,
0x203233732e766f6dull,0x202c343131722509ull,0x090a3b3231317225ull,0x2e3436732e747663ull,
0x6472250920323373ull,0x317225202c373531ull,0x6c756d090a3b3231ull,0x203436752e6f6c2eull,
0x2c38353164722509ull,0x2c37353164722520ull,0x756d090a3b363120ull,0x3436752e6f6c2e6cull,
0x202c366472250920ull,0x3b34202c35647225ull,0x36752e646461090aull,0x3531647225092034ull,
0x3531647225202c39ull,0x3b35647225202c38ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x7225202c30363164ull,0x3b34202c39353164ull,0x36752e646461090aull,0x3631647225092034ull,
0x2c32647225202c31ull,0x3b30363164722520ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x7225202c32363164ull,0x3b34202c38353164ull,0x36752e646461090aull,0x3631647225092034ull,
0x2c33647225202c33ull,0x3b32363164722520ull,0x36752e646461090aull,0x3631647225092034ull,
0x2c36647225202c34ull,0x090a3b3264722520ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c393466ull,0x3b5d302b31363164ull,0x33732e766f6d090aull,0x3531317225092032ull,
0x2f2f200a3b30202cull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x393820656e696c20ull,0x6c2064616568202cull,0x242064656c656261ull,0x3533315f315f744cull,
0x2e766f6d090a3037ull,0x3172250920323373ull,0x31317225202c3631ull,0x315f744c240a3b34ull,
0x0a3a38333334315full,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x73656e202c393820ull,0x70656420676e6974ull,0x65202c32203a6874ull,0x646574616d697473ull,
0x6974617265746920ull,0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,0x353909373109636full,
0x732e646c090a3009ull,0x33662e6465726168ull,0x2c30356625092032ull,0x3336316472255b20ull,
0x646c090a3b5d302bull,0x2e6465726168732eull,0x3566250920323366ull,0x316472255b202c31ull,
0x090a3b5d302b3436ull,0x203233662e6c756dull,0x25202c3235662509ull,0x356625202c303566ull,
0x2e627573090a3b31ull,0x3466250920323366ull,0x2c39346625202c39ull,0x090a3b3235662520ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x302b313631647225ull,0x3b39346625202c5dull,
0x33732e646461090aull,0x3531317225092032ull,0x2c3531317225202cull,0x646461090a3b3120ull,
0x722509203436752eull,0x7225202c33363164ull,0x3b34202c33363164ull,0x36752e646461090aull,
0x3631647225092034ull,0x3631647225202c34ull,0x090a3b3436202c34ull,0x2e656e2e70746573ull,
0x3370250920323373ull,0x2c3531317225202cull,0x0a3b323131722520ull,0x7262203370254009ull,
0x315f744c24092061ull,0x0a3b38333334315full,0x33315f315f744c24ull,0x2f2f200a3a363238ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x393820656e696c20ull,
0x6c2064616568202cull,0x242064656c656261ull,0x3533315f315f744cull,0x2e646461090a3037ull,
0x3172250920323373ull,0x31317225202c3231ull,0x6d090a3b31202c32ull,0x09203233752e766full,
0x31202c3731317225ull,0x70746573090a3b36ull,0x203233732e656e2eull,0x7225202c34702509ull,
0x317225202c323131ull,0x702540090a3b3731ull,0x2409206172622034ull,0x3533315f315f744cull,
0x6f6c2e090a3b3037ull,0x0939340937310963ull,0x61702e646c090a30ull,0x203233732e6d6172ull,
0x5f5b202c35722509ull,0x726170616475635full,0x756c33315a5f5f6dull,0x656d697265705f64ull,
0x5f69696650726574ull,0x3b5d74657366666full,0x3109636f6c2e090aull,0x0a30093030310937ull,
0x3233732e64646109ull,0x2c38313172250920ull,0x3b31202c35722520ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x35647225202c3664ull,0x6c2e090a3b34202cull,0x393409373109636full,
0x702e646c090a3009ull,0x3233732e6d617261ull,0x5b202c3472250920ull,0x6170616475635f5full,
0x6c33315a5f5f6d72ull,0x6d697265705f6475ull,0x6969665072657465ull,0x5f78697274616d5full,
0x2e090a3b5d6d6964ull,0x3109373109636f6cull,0x756d090a30093030ull,0x3233732e6f6c2e6cull,
0x2c39313172250920ull,0x202c383131722520ull,0x6461090a3b347225ull,0x2509203436752e64ull,
0x25202c3536316472ull,0x647225202c366472ull,0x2e646461090a3b32ull,0x3172250920323373ull,
0x31317225202c3032ull,0x0a3b357225202c39ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c33356625ull,0x34362b3536316472ull,0x2e646461090a3b5dull,0x3172250920323375ull,
0x32317225202c3132ull,0x0a3b337225202c30ull,0x3233752e64646109ull,0x2c32323172250920ull,
0x7225202c31722520ull,0x7663090a3b313231ull,0x33752e3436752e74ull,0x3631647225092032ull,
0x3232317225202c36ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x25202c3736316472ull,
0x34202c3636316472ull,0x09636f6c2e090a3bull,0x0a30093934093731ull,0x617261702e646c09ull,
0x2509203436752e6dull,0x5f5f5b202c316472ull,0x6d72617061647563ull,0x64756c33315a5f5full,
0x74656d697265705full,0x6d5f696966507265ull,0x636f6c2e090a3b5dull,0x0930303109373109ull,
0x752e646461090a30ull,0x3164722509203436ull,0x31647225202c3836ull,0x373631647225202cull,
0x6c672e7473090a3bull,0x3233662e6c61626full,0x36316472255b0920ull,0x25202c5d34362b38ull,
0x6461090a3b333566ull,0x2509203233732e64ull,0x7225202c33323172ull,0x347225202c303231ull,
0x68732e646c090a3bull,0x3233662e64657261ull,0x202c343566250920ull,0x2b3536316472255bull,
0x61090a3b5d383231ull,0x09203233752e6464ull,0x25202c3432317225ull,0x7225202c33323172ull,
0x2e646461090a3b33ull,0x3172250920323375ull,0x2c317225202c3532ull,0x0a3b343231722520ull,
0x3436752e74766309ull,0x722509203233752eull,0x7225202c39363164ull,0x756d090a3b353231ull,
0x3436752e6f6c2e6cull,0x3037316472250920ull,0x393631647225202cull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x25202c3137316472ull,0x647225202c316472ull,0x7473090a3b303731ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x5d34362b31373164ull,0x0a3b34356625202cull,
0x3233732e64646109ull,0x2c36323172250920ull,0x202c333231722520ull,0x646c090a3b347225ull,
0x2e6465726168732eull,0x3566250920323366ull,0x316472255b202c35ull,0x3b5d3239312b3536ull,
0x33752e646461090aull,0x3732317225092032ull,0x2c3632317225202cull,0x61090a3b33722520ull,
0x09203233752e6464ull,0x25202c3832317225ull,0x32317225202c3172ull,0x2e747663090a3b37ull,
0x203233752e343675ull,0x2c32373164722509ull,0x0a3b383231722520ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x647225202c333731ull,0x0a3b34202c323731ull,0x3436752e64646109ull,
0x3437316472250920ull,0x202c31647225202cull,0x0a3b333731647225ull,0x626f6c672e747309ull,
0x09203233662e6c61ull,0x2b3437316472255bull,0x356625202c5d3436ull,0x2e646461090a3b35ull,
0x3172250920323373ull,0x32317225202c3932ull,0x0a3b347225202c36ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c36356625ull,0x35322b3536316472ull,0x646461090a3b5d36ull,
0x722509203233752eull,0x317225202c303331ull,0x3b337225202c3932ull,0x33752e646461090aull,
0x3133317225092032ull,0x25202c317225202cull,0x63090a3b30333172ull,0x752e3436752e7476ull,
0x3164722509203233ull,0x33317225202c3537ull,0x2e6c756d090a3b31ull,0x09203436752e6f6cull,
0x202c363731647225ull,0x202c353731647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x647225202c373731ull,0x3731647225202c31ull,0x672e7473090a3b36ull,0x33662e6c61626f6cull,
0x316472255b092032ull,0x202c5d34362b3737ull,0x61090a3b36356625ull,0x09203233732e6464ull,
0x25202c3233317225ull,0x7225202c39323172ull,0x732e646c090a3b34ull,0x33662e6465726168ull,
0x2c37356625092032ull,0x3536316472255b20ull,0x090a3b5d3032332bull,0x203233752e646461ull,
0x202c333331722509ull,0x25202c3233317225ull,0x646461090a3b3372ull,0x722509203233752eull,
0x317225202c343331ull,0x3b3333317225202cull,0x36752e747663090aull,0x2509203233752e34ull,
0x25202c3837316472ull,0x6d090a3b34333172ull,0x36752e6f6c2e6c75ull,0x3731647225092034ull,
0x3731647225202c39ull,0x61090a3b34202c38ull,0x09203436752e6464ull,0x202c303831647225ull,
0x7225202c31647225ull,0x73090a3b39373164ull,0x6c61626f6c672e74ull,0x255b09203233662eull,
0x34362b3038316472ull,0x3b37356625202c5dull,0x33732e646461090aull,0x3533317225092032ull,
0x2c3233317225202cull,0x6c090a3b34722520ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3835ull,0x5d3438332b353631ull,0x752e646461090a3bull,0x3331722509203233ull,
0x3533317225202c36ull,0x090a3b337225202cull,0x203233752e646461ull,0x202c373331722509ull,
0x317225202c317225ull,0x747663090a3b3633ull,0x3233752e3436752eull,0x3138316472250920ull,
0x3b3733317225202cull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x7225202c32383164ull,
0x3b34202c31383164ull,0x36752e646461090aull,0x3831647225092034ull,0x2c31647225202c33ull,
0x3b32383164722520ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,0x3338316472255b09ull,
0x6625202c5d34362bull,0x646461090a3b3835ull,0x722509203233732eull,0x317225202c383331ull,
0x3b347225202c3533ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3935662509ull,
0x342b353631647225ull,0x6461090a3b5d3834ull,0x2509203233752e64ull,0x7225202c39333172ull,
0x337225202c383331ull,0x752e646461090a3bull,0x3431722509203233ull,0x202c317225202c30ull,
0x090a3b3933317225ull,0x2e3436752e747663ull,0x6472250920323375ull,0x317225202c343831ull,
0x6c756d090a3b3034ull,0x203436752e6f6c2eull,0x2c35383164722509ull,0x2c34383164722520ull,
0x646461090a3b3420ull,0x722509203436752eull,0x7225202c36383164ull,0x31647225202c3164ull,
0x2e7473090a3b3538ull,0x662e6c61626f6c67ull,0x6472255b09203233ull,0x2c5d34362b363831ull,
0x090a3b3935662520ull,0x203233732e646461ull,0x202c313431722509ull,0x25202c3833317225ull,
0x2e646c090a3b3472ull,0x662e646572616873ull,0x3036662509203233ull,0x36316472255b202cull,
0x0a3b5d3231352b35ull,0x3233752e64646109ull,0x2c32343172250920ull,0x202c313431722520ull,
0x6461090a3b337225ull,0x2509203233752e64ull,0x7225202c33343172ull,0x3234317225202c31ull,
0x752e747663090a3bull,0x09203233752e3436ull,0x202c373831647225ull,0x090a3b3334317225ull,
0x752e6f6c2e6c756dull,0x3164722509203436ull,0x31647225202c3838ull,0x090a3b34202c3738ull,
0x203436752e646461ull,0x2c39383164722509ull,0x25202c3164722520ull,0x090a3b3838316472ull,
0x61626f6c672e7473ull,0x5b09203233662e6cull,0x362b393831647225ull,0x30366625202c5d34ull,
0x732e646461090a3bull,0x3431722509203233ull,0x3134317225202c34ull,0x090a3b347225202cull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c313666ull,0x3637352b35363164ull,
0x2e646461090a3b5dull,0x3172250920323375ull,0x34317225202c3534ull,0x0a3b337225202c34ull,
0x3233752e64646109ull,0x2c36343172250920ull,0x7225202c31722520ull,0x7663090a3b353431ull,
0x33752e3436752e74ull,0x3931647225092032ull,0x3634317225202c30ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x25202c3139316472ull,0x34202c3039316472ull,0x752e646461090a3bull,
0x3164722509203436ull,0x31647225202c3239ull,0x313931647225202cull,0x6c672e7473090a3bull,
0x3233662e6c61626full,0x39316472255b0920ull,0x25202c5d34362b32ull,0x6c2e090a3b313666ull,
0x303109373109636full,0x646461090a300931ull,0x722509203233732eull,0x34317225202c3534ull,
0x0a3b347225202c34ull,0x373109636f6c2e09ull,0x090a300930303109ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c323666ull,0x3034362b35363164ull,0x2e646461090a3b5dull,
0x3172250920323375ull,0x35347225202c3734ull,0x090a3b337225202cull,0x203233752e646461ull,
0x202c383431722509ull,0x317225202c317225ull,0x747663090a3b3734ull,0x3233752e3436752eull,
0x3339316472250920ull,0x3b3834317225202cull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x7225202c34393164ull,0x3b34202c33393164ull,0x36752e646461090aull,0x3931647225092034ull,
0x2c31647225202c35ull,0x3b34393164722520ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,
0x3539316472255b09ull,0x6625202c5d34362bull,0x6f6c2e090a3b3236ull,0x3130310937310963ull,
0x2e646461090a3009ull,0x3472250920323373ull,0x2c35347225202c35ull,0x2e090a3b34722520ull,
0x3109373109636f6cull,0x646c090a30093030ull,0x2e6465726168732eull,0x3666250920323366ull,
0x316472255b202c33ull,0x3b5d3430372b3536ull,0x33752e646461090aull,0x3934317225092032ull,
0x202c35347225202cull,0x6461090a3b337225ull,0x2509203233752e64ull,0x7225202c30353172ull,
0x3934317225202c31ull,0x752e747663090a3bull,0x09203233752e3436ull,0x202c363931647225ull,
0x090a3b3035317225ull,0x752e6f6c2e6c756dull,0x3164722509203436ull,0x31647225202c3739ull,
0x090a3b34202c3639ull,0x203436752e646461ull,0x2c38393164722509ull,0x25202c3164722520ull,
0x090a3b3739316472ull,0x61626f6c672e7473ull,0x5b09203233662e6cull,0x362b383931647225ull,
0x33366625202c5d34ull,0x09636f6c2e090a3bull,0x3009313031093731ull,0x33732e646461090aull,
0x2c35347225092032ull,0x25202c3534722520ull,0x6f6c2e090a3b3472ull,0x3030310937310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x2c34366625092032ull,0x3536316472255b20ull,
0x090a3b5d3836372bull,0x203233752e646461ull,0x202c313531722509ull,0x7225202c35347225ull,
0x2e646461090a3b33ull,0x3172250920323375ull,0x2c317225202c3235ull,0x0a3b313531722520ull,
0x3436752e74766309ull,0x722509203233752eull,0x7225202c39393164ull,0x756d090a3b323531ull,
0x3436752e6f6c2e6cull,0x3030326472250920ull,0x393931647225202cull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x25202c3130326472ull,0x647225202c316472ull,0x7473090a3b303032ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x5d34362b31303264ull,0x0a3b34366625202cull,
0x373109636f6c2e09ull,0x090a300931303109ull,0x203233732e646461ull,0x25202c3534722509ull,
0x347225202c353472ull,0x09636f6c2e090a3bull,0x3009303031093731ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3536662509ull,0x382b353631647225ull,0x6461090a3b5d3233ull,
0x2509203233752e64ull,0x7225202c33353172ull,0x3b337225202c3534ull,0x33752e646461090aull,
0x3435317225092032ull,0x25202c317225202cull,0x63090a3b33353172ull,0x752e3436752e7476ull,
0x3264722509203233ull,0x35317225202c3230ull,0x2e6c756d090a3b34ull,0x09203436752e6f6cull,
0x202c333032647225ull,0x202c323032647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x647225202c343032ull,0x3032647225202c31ull,0x672e7473090a3b33ull,0x33662e6c61626f6cull,
0x326472255b092032ull,0x202c5d34362b3430ull,0x2e090a3b35366625ull,0x3109373109636f6cull,
0x6461090a30093130ull,0x2509203233732e64ull,0x347225202c353472ull,0x0a3b347225202c35ull,
0x373109636f6c2e09ull,0x090a300930303109ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c363666ull,0x3639382b35363164ull,0x2e646461090a3b5dull,0x3172250920323375ull,
0x35347225202c3535ull,0x090a3b337225202cull,0x203233752e646461ull,0x202c363531722509ull,
0x317225202c317225ull,0x747663090a3b3535ull,0x3233752e3436752eull,0x3530326472250920ull,
0x3b3635317225202cull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x7225202c36303264ull,
0x3b34202c35303264ull,0x36752e646461090aull,0x3032647225092034ull,0x2c31647225202c37ull,
0x3b36303264722520ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,0x3730326472255b09ull,
0x6625202c5d34362bull,0x2e646c090a3b3636ull,0x662e646572616873ull,0x3736662509203233ull,
0x36316472255b202cull,0x0a3b5d3036392b35ull,0x3233732e64646109ull,0x2c37353172250920ull,
0x25202c3534722520ull,0x646461090a3b3472ull,0x722509203233752eull,0x337225202c383531ull,
0x3b3735317225202cull,0x33752e646461090aull,0x3935317225092032ull,0x25202c317225202cull,
0x63090a3b38353172ull,0x752e3436752e7476ull,0x3264722509203233ull,0x35317225202c3830ull,
0x2e6c756d090a3b39ull,0x09203436752e6f6cull,0x202c393032647225ull,0x202c383032647225ull,
0x2e646461090a3b34ull,0x6472250920343675ull,0x647225202c303132ull,0x3032647225202c31ull,
0x672e7473090a3b39ull,0x33662e6c61626f6cull,0x326472255b092032ull,0x202c5d34362b3031ull,
0x62090a3b37366625ull,0x0920696e752e6172ull,0x32315f315f744c24ull,0x744c240a3b363435ull,
0x32303832315f315full,0x732e627573090a3aull,0x3631722509203233ull,0x202c317225202c30ull,
0x747663090a3b3631ull,0x3233732e3436732eull,0x2c31386472250920ull,0x6d090a3b31722520ull,
0x09203436732e766full,0x202c313132647225ull,0x2e6c756d090a3b30ull,0x09203436752e6f6cull,
0x202c323132647225ull,0x31202c3138647225ull,0x2e766f6d090a3b36ull,0x6472250920343673ull,
0x647225202c333132ull,0x2e766f6d090a3b33ull,0x3172250920323373ull,0x240a3b30202c3231ull,
0x3635315f315f744cull,0x3c2f2f200a3a3831ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,
0x30303120656e696cull,0x6e697473656e202cull,0x3a68747065642067ull,0x72657469202c3120ull,
0x203a736e6f697461ull,0x2e766f6d090a3631ull,0x3172250920323375ull,0x090a3b30202c3136ull,
0x2e656c2e70746573ull,0x3570250920323373ull,0x2c3231317225202cull,0x0a3b313631722520ull,
0x7262203570254009ull,0x315f744c24092061ull,0x0a3b30313437315full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30303120ull,
0x6c6562616c206461ull,0x315f744c24206465ull,0x090a38313635315full,0x203233732e766f6dull,
0x202c323631722509ull,0x090a3b3231317225ull,0x203436732e766f6dull,0x2c34313264722509ull,
0x3b31313264722520ull,0x36752e646461090aull,0x3132647225092034ull,0x3132647225202c35ull,
0x3132647225202c34ull,0x2e6c756d090a3b32ull,0x09203436752e6f6cull,0x202c363132647225ull,
0x202c353132647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x647225202c373132ull,
0x647225202c363132ull,0x2e6c756d090a3b34ull,0x09203436752e6f6cull,0x202c383132647225ull,
0x202c323132647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x647225202c393132ull,
0x3132647225202c34ull,0x2e6c756d090a3b38ull,0x09203436752e6f6cull,0x202c303232647225ull,
0x202c343132647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x647225202c313232ull,
0x3232647225202c33ull,0x732e646c090a3b30ull,0x33662e6465726168ull,0x2c38366625092032ull,
0x3731326472255b20ull,0x3b5d343230312d2bull,0x33732e766f6d090aull,0x3531317225092032ull,
0x2f2f200a3b30202cull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x303120656e696c20ull,0x2064616568202c30ull,0x2064656c6562616cull,0x35315f315f744c24ull,
0x766f6d090a383136ull,0x722509203233732eull,0x317225202c333631ull,0x5f744c240a3b3236ull,
0x3a36383336315f31ull,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,
0x6e202c3030312065ull,0x6420676e69747365ull,0x2c32203a68747065ull,0x74616d6974736520ull,
0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,0x09373109636f6c2eull,
0x6c090a3009373031ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3936ull,
0x0a3b5d302b313232ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c30376625ull,
0x312d2b3931326472ull,0x6d090a3b5d343230ull,0x09203233662e6c75ull,0x6625202c31376625ull,
0x30376625202c3936ull,0x662e627573090a3bull,0x3836662509203233ull,0x202c38366625202cull,
0x73090a3b31376625ull,0x6465726168732e74ull,0x255b09203233662eull,0x312d2b3731326472ull,
0x6625202c5d343230ull,0x646461090a3b3836ull,0x722509203233732eull,0x317225202c353131ull,
0x090a3b31202c3531ull,0x203436752e646461ull,0x2c39313264722509ull,0x2c39313264722520ull,
0x646461090a3b3420ull,0x722509203436752eull,0x7225202c31323264ull,0x3436202c31323264ull,
0x2e70746573090a3bull,0x09203233732e656eull,0x317225202c367025ull,0x31317225202c3531ull,
0x36702540090a3b32ull,0x4c24092061726220ull,0x383336315f315f74ull,0x6c3c2f2f200a3b36ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30303120656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x313635315f315f74ull,0x752e617262090a38ull,
0x5f744c240920696eull,0x3b34373835315f31ull,0x315f315f744c240aull,0x2f200a3a30313437ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3030ull,0x64656c6562616c20ull,0x315f315f744c2420ull,0x6f6d090a38313635ull,
0x2509203436732e76ull,0x25202c3431326472ull,0x090a3b3131326472ull,0x203436752e646461ull,
0x2c32323264722509ull,0x2c34313264722520ull,0x3b32313264722520ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x7225202c33323264ull,0x3b34202c32323264ull,0x36752e646461090aull,
0x3132647225092034ull,0x2c34647225202c37ull,0x3b33323264722520ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3836662509ull,0x2d2b373132647225ull,0x240a3b5d34323031ull,
0x3835315f315f744cull,0x3c2f2f200a3a3437ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x30303120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3635315f315f744cull,0x636f6c2e090a3831ull,0x0938303109373109ull,0x662e766f6d090a30ull,
0x3237662509203233ull,0x0a3b38366625202cull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c33376625ull,0x5d302b3331326472ull,0x612e766964090a3bull,0x33662e786f727070ull,
0x2c34376625092032ull,0x25202c3237662520ull,0x7473090a3b333766ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x30312d2b37313264ull,0x376625202c5d3432ull,0x2e646461090a3b34ull,
0x3172250920323373ull,0x31317225202c3231ull,0x61090a3b31202c32ull,0x09203436732e6464ull,
0x202c313132647225ull,0x202c343132647225ull,0x2e646461090a3b31ull,0x6472250920343675ull,
0x647225202c333132ull,0x3b3836202c333132ull,0x33752e766f6d090aull,0x3436317225092032ull,
0x73090a3b3631202cull,0x732e656e2e707465ull,0x2c37702509203233ull,0x202c323131722520ull,
0x090a3b3436317225ull,0x6172622037702540ull,0x5f315f744c240920ull,0x090a3b3831363531ull,
0x09373109636f6c2eull,0x62090a3009313131ull,0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,
0x3531310937310963ull,0x2e6c756d090a3009ull,0x09203436752e6f6cull,0x202c343232647225ull,
0x34202c3138647225ull,0x09636f6c2e090a3bull,0x0a30093934093731ull,0x617261702e646c09ull,
0x2509203233732e6dull,0x635f5f5b202c3572ull,0x5f6d726170616475ull,0x5f64756c33315a5full,
0x6574656d69726570ull,0x666f5f6969665072ull,0x090a3b5d74657366ull,0x09373109636f6c2eull,
0x61090a3009353131ull,0x09203233752e6464ull,0x25202c3536317225ull,0x3b337225202c3572ull,
0x36752e646461090aull,0x3232647225092034ull,0x3232647225202c35ull,0x3b34647225202c34ull,
0x33752e646461090aull,0x3636317225092032ull,0x2c3536317225202cull,0x6c2e090a3b363120ull,
0x393409373109636full,0x702e646c090a3009ull,0x3233732e6d617261ull,0x5b202c3472250920ull,
0x6170616475635f5full,0x6c33315a5f5f6d72ull,0x6d697265705f6475ull,0x6969665072657465ull,
0x5f78697274616d5full,0x2e090a3b5d6d6964ull,0x3109373109636f6cull,0x756d090a30093531ull,
0x3233752e6f6c2e6cull,0x2c37363172250920ull,0x7225202c34722520ull,0x6461090a3b363631ull,
0x2509203233752e64ull,0x7225202c38363172ull,0x3736317225202c35ull,0x68732e646c090a3bull,
0x3233662e64657261ull,0x202c353766250920ull,0x2b3532326472255bull,0x61090a3b5d34362dull,
0x09203233732e6464ull,0x25202c3936317225ull,0x7225202c38363172ull,0x2e747663090a3b31ull,
0x203233732e343673ull,0x2c36323264722509ull,0x0a3b393631722520ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x647225202c373232ull,0x0a3b34202c363232ull,0x373109636f6c2e09ull,
0x6c090a3009393409ull,0x2e6d617261702e64ull,0x6472250920343675ull,0x75635f5f5b202c31ull,
0x5f5f6d7261706164ull,0x705f64756c33315aull,0x726574656d697265ull,0x3b5d6d5f69696650ull,
0x3109636f6c2e090aull,0x0a30093531310937ull,0x3436752e64646109ull,0x3832326472250920ull,
0x202c31647225202cull,0x0a3b373232647225ull,0x626f6c672e747309ull,0x09203233662e6c61ull,
0x2b3832326472255bull,0x6625202c5d34362dull,0x646461090a3b3537ull,0x722509203233732eull,
0x347225202c303731ull,0x3b3836317225202cull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3637662509ull,0x302b353232647225ull,0x2e646461090a3b5dull,0x3172250920323373ull,
0x37317225202c3137ull,0x0a3b317225202c30ull,0x3436732e74766309ull,0x722509203233732eull,
0x7225202c39323264ull,0x756d090a3b313731ull,0x3436752e6f6c2e6cull,0x3033326472250920ull,
0x393232647225202cull,0x6461090a3b34202cull,0x2509203436752e64ull,0x25202c3133326472ull,
0x647225202c316472ull,0x7473090a3b303332ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,
0x34362d2b31333264ull,0x3b36376625202c5dull,0x33732e646461090aull,0x3237317225092032ull,
0x2c3037317225202cull,0x6c090a3b34722520ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3737ull,0x3b5d34362b353232ull,0x33732e646461090aull,0x3337317225092032ull,
0x2c3237317225202cull,0x63090a3b31722520ull,0x732e3436732e7476ull,0x3264722509203233ull,
0x37317225202c3233ull,0x2e6c756d090a3b33ull,0x09203436752e6f6cull,0x202c333332647225ull,
0x202c323332647225ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x647225202c343332ull,
0x3332647225202c31ull,0x672e7473090a3b33ull,0x33662e6c61626f6cull,0x326472255b092032ull,
0x2c5d34362d2b3433ull,0x090a3b3737662520ull,0x203233732e646461ull,0x202c343731722509ull,
0x25202c3237317225ull,0x2e646c090a3b3472ull,0x662e646572616873ull,0x3837662509203233ull,
0x32326472255b202cull,0x0a3b5d3832312b35ull,0x3233732e64646109ull,0x2c35373172250920ull,
0x202c343731722520ull,0x7663090a3b317225ull,0x33732e3436732e74ull,0x3332647225092032ull,
0x3537317225202c35ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x25202c3633326472ull,
0x34202c3533326472ull,0x752e646461090a3bull,0x3264722509203436ull,0x31647225202c3733ull,
0x363332647225202cull,0x6c672e7473090a3bull,0x3233662e6c61626full,0x33326472255b0920ull,
0x202c5d34362d2b37ull,0x61090a3b38376625ull,0x09203233732e6464ull,0x25202c3637317225ull,
0x7225202c34373172ull,0x732e646c090a3b34ull,0x33662e6465726168ull,0x2c39376625092032ull,
0x3532326472255b20ull,0x090a3b5d3239312bull,0x203233732e646461ull,0x202c373731722509ull,
0x25202c3637317225ull,0x747663090a3b3172ull,0x3233732e3436732eull,0x3833326472250920ull,
0x3b3737317225202cull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x7225202c39333264ull,
0x3b34202c38333264ull,0x36752e646461090aull,0x3432647225092034ull,0x2c31647225202c30ull,
0x3b39333264722520ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,0x3034326472255b09ull,
0x25202c5d34362d2bull,0x6461090a3b393766ull,0x2509203233732e64ull,0x7225202c38373172ull,
0x347225202c363731ull,0x68732e646c090a3bull,0x3233662e64657261ull,0x202c303866250920ull,
0x2b3532326472255bull,0x61090a3b5d363532ull,0x09203233732e6464ull,0x25202c3937317225ull,
0x7225202c38373172ull,0x2e747663090a3b31ull,0x203233732e343673ull,0x2c31343264722509ull,
0x0a3b393731722520ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x647225202c323432ull,
0x0a3b34202c313432ull,0x3436752e64646109ull,0x3334326472250920ull,0x202c31647225202cull,
0x0a3b323432647225ull,0x626f6c672e747309ull,0x09203233662e6c61ull,0x2b3334326472255bull,
0x6625202c5d34362dull,0x646461090a3b3038ull,0x722509203233732eull,0x317225202c303831ull,
0x3b347225202c3837ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3138662509ull,
0x332b353232647225ull,0x6461090a3b5d3032ull,0x2509203233732e64ull,0x7225202c31383172ull,
0x317225202c303831ull,0x732e747663090a3bull,0x09203233732e3436ull,0x202c343432647225ull,
0x090a3b3138317225ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,0x32647225202c3534ull,
0x090a3b34202c3434ull,0x203436752e646461ull,0x2c36343264722509ull,0x25202c3164722520ull,
0x090a3b3534326472ull,0x61626f6c672e7473ull,0x5b09203233662e6cull,0x2d2b363432647225ull,
0x386625202c5d3436ull,0x636f6c2e090a3b31ull,0x0936313109373109ull,0x732e646461090a30ull,
0x3831722509203233ull,0x3038317225202c32ull,0x090a3b347225202cull,0x09373109636f6c2eull,
0x6c090a3009353131ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3238ull,
0x5d3438332b353232ull,0x732e646461090a3bull,0x3831722509203233ull,0x3238317225202c33ull,
0x090a3b317225202cull,0x2e3436732e747663ull,0x6472250920323373ull,0x317225202c373432ull,
0x6c756d090a3b3338ull,0x203436752e6f6c2eull,0x2c38343264722509ull,0x2c37343264722520ull,
0x646461090a3b3420ull,0x722509203436752eull,0x7225202c39343264ull,0x32647225202c3164ull,
0x2e7473090a3b3834ull,0x662e6c61626f6c67ull,0x6472255b09203233ull,0x5d34362d2b393432ull,
0x0a3b32386625202cull,0x373109636f6c2e09ull,0x090a300936313109ull,0x203233732e646461ull,
0x202c343831722509ull,0x25202c3238317225ull,0x6f6c2e090a3b3472ull,0x3531310937310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x2c33386625092032ull,0x3532326472255b20ull,
0x090a3b5d3834342bull,0x203233732e646461ull,0x202c353831722509ull,0x25202c3438317225ull,
0x747663090a3b3172ull,0x3233732e3436732eull,0x3035326472250920ull,0x3b3538317225202cull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x7225202c31353264ull,0x3b34202c30353264ull,
0x36752e646461090aull,0x3532647225092034ull,0x2c31647225202c32ull,0x3b31353264722520ull,
0x6f6c672e7473090aull,0x203233662e6c6162ull,0x3235326472255b09ull,0x25202c5d34362d2bull,
0x6c2e090a3b333866ull,0x313109373109636full,0x646461090a300936ull,0x722509203233732eull,
0x317225202c363831ull,0x3b347225202c3438ull,0x3109636f6c2e090aull,0x0a30093531310937ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c34386625ull,0x31352b3532326472ull,
0x646461090a3b5d32ull,0x722509203233732eull,0x317225202c373831ull,0x3b317225202c3638ull,
0x36732e747663090aull,0x2509203233732e34ull,0x25202c3335326472ull,0x6d090a3b37383172ull,
0x36752e6f6c2e6c75ull,0x3532647225092034ull,0x3532647225202c34ull,0x61090a3b34202c33ull,
0x09203436752e6464ull,0x202c353532647225ull,0x7225202c31647225ull,0x73090a3b34353264ull,
0x6c61626f6c672e74ull,0x255b09203233662eull,0x362d2b3535326472ull,0x34386625202c5d34ull,
0x09636f6c2e090a3bull,0x3009363131093731ull,0x33732e646461090aull,0x3838317225092032ull,
0x2c3638317225202cull,0x2e090a3b34722520ull,0x3109373109636f6cull,0x646c090a30093531ull,
0x2e6465726168732eull,0x3866250920323366ull,0x326472255b202c35ull,0x3b5d3637352b3532ull,
0x33732e646461090aull,0x3938317225092032ull,0x2c3838317225202cull,0x63090a3b31722520ull,
0x732e3436732e7476ull,0x3264722509203233ull,0x38317225202c3635ull,0x2e6c756d090a3b39ull,
0x09203436752e6f6cull,0x202c373532647225ull,0x202c363532647225ull,0x2e646461090a3b34ull,
0x6472250920343675ull,0x647225202c383532ull,0x3532647225202c31ull,0x672e7473090a3b37ull,
0x33662e6c61626f6cull,0x326472255b092032ull,0x2c5d34362d2b3835ull,0x090a3b3538662520ull,
0x09373109636f6c2eull,0x61090a3009363131ull,0x09203233732e6464ull,0x25202c3039317225ull,
0x7225202c38383172ull,0x636f6c2e090a3b34ull,0x0935313109373109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x202c363866250920ull,0x2b3532326472255bull,0x61090a3b5d303436ull,
0x09203233732e6464ull,0x25202c3139317225ull,0x7225202c30393172ull,0x2e747663090a3b31ull,
0x203233732e343673ull,0x2c39353264722509ull,0x0a3b313931722520ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x647225202c303632ull,0x0a3b34202c393532ull,0x3436752e64646109ull,
0x3136326472250920ull,0x202c31647225202cull,0x0a3b303632647225ull,0x626f6c672e747309ull,
0x09203233662e6c61ull,0x2b3136326472255bull,0x6625202c5d34362dull,0x6f6c2e090a3b3638ull,
0x3631310937310963ull,0x2e646461090a3009ull,0x3172250920323373ull,0x39317225202c3239ull,
0x0a3b347225202c30ull,0x373109636f6c2e09ull,0x090a300935313109ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c373866ull,0x3430372b35323264ull,0x2e646461090a3b5dull,
0x3172250920323373ull,0x39317225202c3339ull,0x0a3b317225202c32ull,0x3436732e74766309ull,
0x722509203233732eull,0x7225202c32363264ull,0x756d090a3b333931ull,0x3436752e6f6c2e6cull,
0x3336326472250920ull,0x323632647225202cull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x25202c3436326472ull,0x647225202c316472ull,0x7473090a3b333632ull,0x2e6c61626f6c672eull,
0x72255b0920323366ull,0x34362d2b34363264ull,0x3b37386625202c5dull,0x3109636f6c2e090aull,
0x0a30093631310937ull,0x3233732e64646109ull,0x2c34393172250920ull,0x202c323931722520ull,
0x6c2e090a3b347225ull,0x313109373109636full,0x2e646c090a300935ull,0x662e646572616873ull,
0x3838662509203233ull,0x32326472255b202cull,0x0a3b5d3836372b35ull,0x3233732e64646109ull,
0x2c35393172250920ull,0x202c343931722520ull,0x7663090a3b317225ull,0x33732e3436732e74ull,
0x3632647225092032ull,0x3539317225202c35ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x25202c3636326472ull,0x34202c3536326472ull,0x752e646461090a3bull,0x3264722509203436ull,
0x31647225202c3736ull,0x363632647225202cull,0x6c672e7473090a3bull,0x3233662e6c61626full,
0x36326472255b0920ull,0x202c5d34362d2b37ull,0x2e090a3b38386625ull,0x3109373109636f6cull,
0x6461090a30093631ull,0x2509203233732e64ull,0x7225202c36393172ull,0x347225202c343931ull,
0x09636f6c2e090a3bull,0x3009353131093731ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3938662509ull,0x382b353232647225ull,0x6461090a3b5d3233ull,0x2509203233732e64ull,
0x7225202c37393172ull,0x317225202c363931ull,0x732e747663090a3bull,0x09203233732e3436ull,
0x202c383632647225ull,0x090a3b3739317225ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,
0x32647225202c3936ull,0x090a3b34202c3836ull,0x203436752e646461ull,0x2c30373264722509ull,
0x25202c3164722520ull,0x090a3b3936326472ull,0x61626f6c672e7473ull,0x5b09203233662e6cull,
0x2d2b303732647225ull,0x386625202c5d3436ull,0x732e646c090a3b39ull,0x33662e6465726168ull,
0x2c30396625092032ull,0x3532326472255b20ull,0x090a3b5d3639382bull,0x203233732e646461ull,
0x202c383931722509ull,0x25202c3639317225ull,0x646461090a3b3472ull,0x722509203233732eull,
0x317225202c393931ull,0x3b3839317225202cull,0x36732e747663090aull,0x2509203233732e34ull,
0x25202c3137326472ull,0x6d090a3b39393172ull,0x36752e6f6c2e6c75ull,0x3732647225092034ull,
0x3732647225202c32ull,0x61090a3b34202c31ull,0x09203436752e6464ull,0x202c333732647225ull,
0x7225202c31647225ull,0x73090a3b32373264ull,0x6c61626f6c672e74ull,0x255b09203233662eull,
0x362d2b3337326472ull,0x30396625202c5d34ull,0x5f315f744c240a3bull,0x090a3a3634353231ull,
0x09373109636f6c2eull,0x65090a3009303231ull,0x444c240a3b746978ull,0x315a5f5f646e6557ull,
0x7265705f64756c33ull,0x6650726574656d69ull,0x2f207d090a3a6969ull,0x756c33315a5f202full,
0x656d697265705f64ull,0x0a69696650726574ull,0x7972746e652e090aull,0x64756c32315a5f20ull,
0x616e7265746e695full,0x0a2820696966506cull,0x6d617261702e0909ull,0x5f5f203436752e20ull,
0x6d72617061647563ull,0x64756c32315a5f5full,0x616e7265746e695full,0x2c6d5f696966506cull,
0x617261702e09090aull,0x5f203233732e206dull,0x726170616475635full,0x756c32315a5f5f6dull,
0x6e7265746e695f64ull,0x6d5f696966506c61ull,0x69645f7869727461ull,0x61702e09090a2c6dull,
0x3233732e206d6172ull,0x70616475635f5f20ull,0x32315a5f5f6d7261ull,0x65746e695f64756cull,
0x696966506c616e72ull,0x2974657366666f5full,0x65722e090a7b090aull,0x25203631752e2067ull,
0x090a3b3e343c6872ull,0x33752e206765722eull,0x3e31323c72252032ull,0x206765722e090a3bull,
0x647225203436752eull,0x2e090a3b3e35323cull,0x3233662e20676572ull,0x3b3e37343c662520ull,
0x65726168732e090aull,0x6e67696c612e2064ull,0x5f2038622e203420ull,0x65705f616475635full,
0x31346c6f635f6972ull,0x5d343230315b3434ull,0x726168732e090a3bull,0x67696c612e206465ull,
0x2038622e2034206eull,0x705f616475635f5full,0x35776f725f697265ull,0x343230315b383631ull,
0x636f6c2e090a3b5dull,0x0933323109373109ull,0x5f3142424c240a30ull,0x5f64756c32315a5full,
0x6c616e7265746e69ull,0x6d090a3a69696650ull,0x09203436752e766full,0x5f5f202c31647225ull,
0x7265705f61647563ull,0x3431346c6f635f69ull,0x2e766f6d090a3b34ull,0x6472250920343675ull,
0x6475635f5f202c32ull,0x725f697265705f61ull,0x0a3b38363135776full,0x373109636f6c2e09ull,
0x090a300934333109ull,0x203631752e766f6dull,0x25202c3168722509ull,0x3b782e6469617463ull,
0x69772e6c756d090aull,0x09203631752e6564ull,0x687225202c317225ull,0x090a3b3631202c31ull,
0x2e3233752e747663ull,0x3272250920363175ull,0x782e64697425202cull,0x752e747663090a3bull,
0x09203233752e3436ull,0x7225202c33647225ull,0x2e747663090a3b32ull,0x203631752e323375ull,
0x7425202c33722509ull,0x63090a3b792e6469ull,0x752e3436752e7476ull,0x3464722509203233ull,
0x090a3b337225202cull,0x6d617261702e646cull,0x722509203233752eull,0x75635f5f5b202c34ull,
0x5f5f6d7261706164ull,0x695f64756c32315aull,0x506c616e7265746eull,0x7366666f5f696966ull,
0x6461090a3b5d7465ull,0x2509203233752e64ull,0x2c317225202c3572ull,0x6d090a3b34722520ull,
0x36752e6f6c2e6c75ull,0x2c35647225092034ull,0x31202c3464722520ull,0x2e646461090a3b36ull,
0x6472250920343675ull,0x2c33647225202c36ull,0x090a3b3564722520ull,0x752e6f6c2e6c756dull,
0x3764722509203436ull,0x202c36647225202cull,0x702e646c090a3b34ull,0x3233752e6d617261ull,
0x5b202c3672250920ull,0x6170616475635f5full,0x6c32315a5f5f6d72ull,0x7265746e695f6475ull,
0x5f696966506c616eull,0x645f78697274616dull,0x646c090a3b5d6d69ull,0x752e6d617261702eull,
0x3864722509203436ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6e695f64756c3231ull,
0x66506c616e726574ull,0x090a3b5d6d5f6969ull,0x203233752e646461ull,0x7225202c37722509ull,
0x0a3b337225202c34ull,0x2e6f6c2e6c756d09ull,0x3872250920323375ull,0x25202c367225202cull,
0x646461090a3b3772ull,0x722509203233752eull,0x202c357225202c39ull,0x6461090a3b387225ull,
0x2509203233752e64ull,0x327225202c303172ull,0x090a3b397225202cull,0x2e3436752e747663ull,
0x6472250920323375ull,0x3b30317225202c39ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c303164ull,0x61090a3b34202c39ull,0x09203436752e6464ull,0x25202c3131647225ull,
0x647225202c386472ull,0x2e646c090a3b3031ull,0x662e6c61626f6c67ull,0x2c31662509203233ull,
0x2b31316472255b20ull,0x6461090a3b5d3436ull,0x2509203436752e64ull,0x7225202c32316472ull,
0x32647225202c3764ull,0x68732e7473090a3bull,0x3233662e64657261ull,0x32316472255b0920ull,
0x316625202c5d302bull,0x09636f6c2e090a3bull,0x3009353331093731ull,0x31752e766f6d090aull,
0x2c32687225092036ull,0x2e64696174632520ull,0x2e6c756d090a3b79ull,0x3631752e65646977ull,
0x202c313172250920ull,0x3631202c32687225ull,0x752e646461090a3bull,0x3231722509203233ull,
0x202c31317225202cull,0x6461090a3b347225ull,0x2509203233752e64ull,0x317225202c333172ull,
0x0a3b337225202c32ull,0x3233752e64646109ull,0x202c343172250920ull,0x3631202c33317225ull,
0x6c2e6c756d090a3bull,0x2509203233752e6full,0x317225202c353172ull,0x0a3b367225202c34ull,
0x3233752e64646109ull,0x202c363172250920ull,0x7225202c35317225ull,0x2e646461090a3b34ull,
0x3172250920323375ull,0x202c327225202c37ull,0x63090a3b36317225ull,0x752e3436752e7476ull,
0x3164722509203233ull,0x3b37317225202c33ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c343164ull,0x090a3b34202c3331ull,0x203436752e646461ull,0x202c353164722509ull,
0x7225202c38647225ull,0x646c090a3b343164ull,0x2e6c61626f6c672eull,0x3266250920323366ull,
0x35316472255b202cull,0x6461090a3b5d302bull,0x2509203436752e64ull,0x7225202c36316472ull,
0x31647225202c3764ull,0x68732e7473090a3bull,0x3233662e64657261ull,0x36316472255b0920ull,
0x326625202c5d302bull,0x09636f6c2e090a3bull,0x3009373331093731ull,0x79732e726162090aull,
0x090a3b300920636eull,0x09373109636f6c2eull,0x6d090a3009313431ull,0x36752e6f6c2e6c75ull,
0x3731647225092034ull,0x202c33647225202cull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x32647225202c3831ull,0x3b3731647225202cull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c393164ull,0x090a3b3436202c34ull,0x203436752e646461ull,0x202c303264722509ull,
0x7225202c31647225ull,0x6f6d090a3b393164ull,0x2509203233662e76ull,0x30306630202c3366ull,
0x203b303030303030ull,0x202f2f0920202020ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x5b202c3466250920ull,0x5d302b3831647225ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x5b202c3566250920ull,0x5d302b3032647225ull,0x662e64616d090a3bull,0x2c36662509203233ull,
0x6625202c34662520ull,0x0a3b336625202c35ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x72255b202c376625ull,0x3b5d34362b383164ull,0x6168732e646c090aull,0x203233662e646572ull,
0x255b202c38662509ull,0x3b5d342b30326472ull,0x33662e64616d090aull,0x202c396625092032ull,
0x386625202c376625ull,0x090a3b366625202cull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c303166ull,0x5d3832312b383164ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x202c313166250920ull,0x382b30326472255bull,0x2e64616d090a3b5dull,0x3166250920323366ull,
0x2c30316625202c32ull,0x25202c3131662520ull,0x2e646c090a3b3966ull,0x662e646572616873ull,
0x3331662509203233ull,0x38316472255b202cull,0x090a3b5d3239312bull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c343166ull,0x3b5d32312b303264ull,0x33662e64616d090aull,
0x2c35316625092032ull,0x25202c3331662520ull,0x316625202c343166ull,0x732e646c090a3b32ull,
0x33662e6465726168ull,0x2c36316625092032ull,0x2b38316472255b20ull,0x6c090a3b5d363532ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3731ull,0x0a3b5d36312b3032ull,
0x3233662e64616d09ull,0x202c383166250920ull,0x6625202c36316625ull,0x35316625202c3731ull,
0x68732e646c090a3bull,0x3233662e64657261ull,0x202c393166250920ull,0x332b38316472255bull,
0x646c090a3b5d3032ull,0x2e6465726168732eull,0x3266250920323366ull,0x326472255b202c30ull,
0x090a3b5d30322b30ull,0x203233662e64616dull,0x25202c3132662509ull,0x326625202c393166ull,
0x3b38316625202c30ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3232662509ull,
0x38332b3831647225ull,0x2e646c090a3b5d34ull,0x662e646572616873ull,0x3332662509203233ull,
0x30326472255b202cull,0x6d090a3b5d34322bull,0x09203233662e6461ull,0x6625202c34326625ull,
0x33326625202c3232ull,0x0a3b31326625202cull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c35326625ull,0x3834342b38316472ull,0x732e646c090a3b5dull,0x33662e6465726168ull,
0x2c36326625092032ull,0x2b30326472255b20ull,0x616d090a3b5d3832ull,0x2509203233662e64ull,
0x326625202c373266ull,0x2c36326625202c35ull,0x090a3b3432662520ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c383266ull,0x5d3231352b383164ull,0x68732e646c090a3bull,
0x3233662e64657261ull,0x202c393266250920ull,0x332b30326472255bull,0x64616d090a3b5d32ull,
0x662509203233662eull,0x38326625202c3732ull,0x202c39326625202cull,0x6c090a3b37326625ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3033ull,0x3b5d3637352b3831ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3133662509ull,0x36332b3032647225ull,
0x2e64616d090a3b5dull,0x3266250920323366ull,0x2c30336625202c37ull,0x25202c3133662520ull,
0x646c090a3b373266ull,0x2e6465726168732eull,0x3366250920323366ull,0x316472255b202c32ull,
0x0a3b5d3034362b38ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c33336625ull,
0x5d30342b30326472ull,0x662e64616d090a3bull,0x3732662509203233ull,0x202c32336625202cull,
0x6625202c33336625ull,0x2e646c090a3b3732ull,0x662e646572616873ull,0x3433662509203233ull,
0x38316472255b202cull,0x090a3b5d3430372bull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c353366ull,0x3b5d34342b303264ull,0x33662e64616d090aull,0x2c37326625092032ull,
0x25202c3433662520ull,0x326625202c353366ull,0x732e646c090a3b37ull,0x33662e6465726168ull,
0x2c36336625092032ull,0x2b38316472255b20ull,0x6c090a3b5d383637ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3733ull,0x0a3b5d38342b3032ull,0x3233662e64616d09ull,
0x202c373266250920ull,0x6625202c36336625ull,0x37326625202c3733ull,0x68732e646c090a3bull,
0x3233662e64657261ull,0x202c383366250920ull,0x382b38316472255bull,0x646c090a3b5d3233ull,
0x2e6465726168732eull,0x3366250920323366ull,0x326472255b202c39ull,0x090a3b5d32352b30ull,
0x203233662e64616dull,0x25202c3732662509ull,0x336625202c383366ull,0x3b37326625202c39ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3034662509ull,0x39382b3831647225ull,
0x2e646c090a3b5d36ull,0x662e646572616873ull,0x3134662509203233ull,0x30326472255b202cull,
0x6d090a3b5d36352bull,0x09203233662e6461ull,0x6625202c37326625ull,0x31346625202c3034ull,
0x0a3b37326625202cull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c32346625ull,
0x3036392b38316472ull,0x732e646c090a3b5dull,0x33662e6465726168ull,0x2c33346625092032ull,
0x2b30326472255b20ull,0x616d090a3b5d3036ull,0x2509203233662e64ull,0x346625202c373266ull,
0x2c33346625202c32ull,0x090a3b3732662520ull,0x09373109636f6c2eull,0x61090a3009323431ull,
0x09203233752e6464ull,0x7225202c38317225ull,0x3b35317225202c35ull,0x33752e646461090aull,
0x2c39317225092032ull,0x25202c3831722520ull,0x747663090a3b3272ull,0x3233752e3436752eull,
0x2c31326472250920ull,0x090a3b3931722520ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,
0x3132647225202c32ull,0x6461090a3b34202cull,0x2509203436752e64ull,0x7225202c33326472ull,
0x32647225202c3864ull,0x672e646c090a3b32ull,0x33662e6c61626f6cull,0x2c34346625092032ull,
0x2b33326472255b20ull,0x7573090a3b5d3436ull,0x2509203233662e62ull,0x346625202c353466ull,
0x3b37326625202c34ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b33326472255b09ull,
0x346625202c5d3436ull,0x636f6c2e090a3b35ull,0x0935343109373109ull,0x3b74697865090a30ull,
0x646e6557444c240aull,0x64756c32315a5f5full,0x616e7265746e695full,0x090a3a696966506cull,
0x315a5f202f2f207dull,0x746e695f64756c32ull,0x6966506c616e7265ull,0x00000000000a0a69ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_13", (char*)__deviceText_$sm_13$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_13$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0x2e00b786,(char*)"6873d5f28f26dee3",(char*)"lud_kernel.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x15f85d8a,&__elfEntries1};
# 2 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c" 2
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

  return __fdividef(a, b);



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
# 4717 "/home/normal/cuda/bin/../include/device_functions.h" 3
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



  return __sinf(a);



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



  return __cosf(a);
# 1962 "/home/normal/cuda/bin/../include/math_functions.h" 3
}

static __attribute__((__unused__)) float __cuda_tanf(float a)
{



  return __tanf(a);
# 1985 "/home/normal/cuda/bin/../include/math_functions.h" 3
}

static __attribute__((__unused__)) float __cuda_log2f(float a)
{



  return __log2f(a);



}

static __attribute__((__unused__)) float __cuda_expf(float a)
{



  return __expf(a);



}

static __attribute__((__unused__)) float __cuda_exp10f(float a)
{



  return __exp10f(a);



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



  return __logf(a);



}

static __attribute__((__unused__)) float __cuda_log10f(float a)
{



  return __log10f(a);



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



  return __powf(a, b);
# 3105 "/home/normal/cuda/bin/../include/math_functions.h" 3
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



  __sincosf(a, sptr, cptr);
# 3359 "/home/normal/cuda/bin/../include/math_functions.h" 3
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


# 5336 "/home/normal/cuda/bin/../include/math_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx3.h" 1 3
# 61 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
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
# 2354 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
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
# 5337 "/home/normal/cuda/bin/../include/math_functions.h" 2 3
# 94 "/home/normal/cuda/bin/../include/common_functions.h" 2
# 280 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2
# 3 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c" 2




struct __T20 {float *__par0;int __par1;int __par2;int __dummy_field;};




struct __T21 {float *__par0;int __par1;int __par2;int __dummy_field;};




struct __T22 {float *__par0;int __par1;int __par2;int __dummy_field;};
static void __sti____cudaRegisterAll_45_tmpxft_00005b58_00000000_4_lud_kernel_cpp1_ii_a8a59389(void) __attribute__((__constructor__));
void __device_stub__Z12lud_diagonalPfii(float *__par0, int __par1, int __par2){auto struct __T20 *__T23;
*(void**)(void*)&__T23 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T23->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T23->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T23->__par2) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float *, int, int))lud_diagonal__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int, int))lud_diagonal__entry))); };}
void lud_diagonal__entry( float *__cuda_0,int __cuda_1,int __cuda_2)
# 8 "lud_kernel.cu"
{__device_stub__Z12lud_diagonalPfii( __cuda_0,__cuda_1,__cuda_2);
# 46 "lud_kernel.cu"
}
# 1 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c"
void __device_stub__Z13lud_perimeterPfii( float *__par0, int __par1, int __par2) { auto struct __T21 *__T24;
*(void**)(void*)&__T24 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, int, int))lud_perimeter__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int, int))lud_perimeter__entry))); }; }
void lud_perimeter__entry( float *__cuda_0,int __cuda_1,int __cuda_2)
# 50 "lud_kernel.cu"
{__device_stub__Z13lud_perimeterPfii( __cuda_0,__cuda_1,__cuda_2);
# 120 "lud_kernel.cu"
}
# 1 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c"
void __device_stub__Z12lud_internalPfii( float *__par0, int __par1, int __par2) { auto struct __T22 *__T25;
*(void**)(void*)&__T25 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T25->__par2) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, int, int))lud_internal__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int, int))lud_internal__entry))); }; }
void lud_internal__entry( float *__cuda_0,int __cuda_1,int __cuda_2)
# 124 "lud_kernel.cu"
{__device_stub__Z12lud_internalPfii( __cuda_0,__cuda_1,__cuda_2);
# 145 "lud_kernel.cu"
}
# 1 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c"
# 10 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c"
static void __sti____cudaRegisterAll_45_tmpxft_00005b58_00000000_4_lud_kernel_cpp1_ii_a8a59389(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int, int))lud_internal__entry), (char*)"_Z12lud_internalPfii", "_Z12lud_internalPfii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int, int))lud_perimeter__entry), (char*)"_Z13lud_perimeterPfii", "_Z13lud_perimeterPfii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int, int))lud_diagonal__entry), (char*)"_Z12lud_diagonalPfii", "_Z12lud_diagonalPfii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); }
# 1 "/tmp/tmpxft_00005b58_00000000-1_lud_kernel.cudafe1.stub.c" 2

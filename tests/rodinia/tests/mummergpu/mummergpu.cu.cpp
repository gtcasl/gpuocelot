# 1 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.cpp"
# 1 "mummergpu.cu"
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
# 71 "/usr/include/assert.h" 3
extern "C" void __assert_fail(const char *, const char *, unsigned, const char *) throw() __attribute__((__noreturn__));
# 76 "/usr/include/assert.h" 3
extern "C" void __assert_perror_fail(int, const char *, unsigned, const char *) throw() __attribute__((__noreturn__));
# 84 "/usr/include/assert.h" 3
extern "C" void __assert(const char *, const char *, int) throw() __attribute__((__noreturn__));
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
# 43 "/usr/include/bits/errno.h" 3
extern "C" int *__errno_location() throw() __attribute__((__const__));
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
extern "C" int gettimeofday(timeval *__restrict__, __timezone_ptr_t) throw() __attribute__((nonnull(1)));
# 79 "/usr/include/sys/time.h" 3
extern "C" int settimeofday(const timeval *, const struct timezone *) throw() __attribute__((nonnull(1)));
# 87 "/usr/include/sys/time.h" 3
extern "C" int adjtime(const timeval *, timeval *) throw();
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
extern "C" int getitimer(__itimer_which_t, itimerval *) throw();
# 133 "/usr/include/sys/time.h" 3
extern "C" int setitimer(__itimer_which_t, const itimerval *__restrict__, itimerval *__restrict__) throw();
# 140 "/usr/include/sys/time.h" 3
extern "C" int utimes(const char *, const timeval [2]) throw() __attribute__((nonnull(1)));
# 145 "/usr/include/sys/time.h" 3
extern "C" int lutimes(const char *, const timeval [2]) throw() __attribute__((nonnull(1)));
# 149 "/usr/include/sys/time.h" 3
extern "C" int futimes(int, const timeval [2]) throw();
# 156 "/usr/include/sys/time.h" 3
extern "C" int futimesat(int, const char *, const timeval [2]) throw();
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
# 3 "./common.cu"
typedef unsigned uint32_t;
# 6 "./common.cu"
static const int basecount = 5;
# 114 "./common.cu"
struct TextureAddress {
# 115 "./common.cu"
union {
# 116 "./common.cu"
unsigned data;
# 118 "./common.cu"
struct {
# 120 "./common.cu"
unsigned short x;
# 121 "./common.cu"
unsigned short y;
# 125 "./common.cu"
};
# 126 "./common.cu"
};
# 127 "./common.cu"
};
# 130 "./common.cu"
struct PixelOfNode {
# 133 "./common.cu"
union {
# 134 "./common.cu"
uint4 data;
# 136 "./common.cu"
struct {
# 137 "./common.cu"
unsigned char parent[3];
# 138 "./common.cu"
unsigned char suffix[3];
# 140 "./common.cu"
unsigned char start[3];
# 141 "./common.cu"
unsigned char end[3];
# 142 "./common.cu"
unsigned char depth[3];
# 144 "./common.cu"
unsigned char pad;
# 145 "./common.cu"
};
# 146 "./common.cu"
};
# 147 "./common.cu"
};
# 150 "./common.cu"
struct PixelOfChildren {
# 153 "./common.cu"
union {
# 154 "./common.cu"
uint4 data;
# 157 "./common.cu"
union {
# 159 "./common.cu"
struct {
# 160 "./common.cu"
unsigned char a[3];
# 161 "./common.cu"
unsigned char c[3];
# 162 "./common.cu"
unsigned char g[3];
# 163 "./common.cu"
unsigned char t[3];
# 164 "./common.cu"
unsigned char d[3];
# 166 "./common.cu"
char leafchar;
# 167 "./common.cu"
};
# 170 "./common.cu"
struct {
# 171 "./common.cu"
unsigned char leafid[3];
# 172 "./common.cu"
unsigned char pad[12];
# 173 "./common.cu"
char leafchar0;
# 174 "./common.cu"
};
# 175 "./common.cu"
};
# 176 "./common.cu"
};
# 177 "./common.cu"
};
# 187 "./common.cu"
typedef
# 179 "./common.cu"
struct MatchInfo {
# 181 "./common.cu"
unsigned resultsoffset;
# 182 "./common.cu"
unsigned queryid;
# 183 "./common.cu"
TextureAddress matchnode;
# 184 "./common.cu"
unsigned numLeaves;
# 185 "./common.cu"
unsigned short edgematch;
# 186 "./common.cu"
unsigned short qrystartpos;
# 187 "./common.cu"
} MatchInfo;
# 193 "./common.cu"
typedef
# 189 "./common.cu"
struct Alignment {
# 191 "./common.cu"
int left_in_ref;
# 192 "./common.cu"
unsigned short matchlen;
# 193 "./common.cu"
} Alignment;
# 197 "./common.cu"
static const int MAX_TEXTURE_DIMENSION = 4096;
# 198 "./common.cu"
static const int MAX_GRID_DIMENSION = 65535;
# 199 "./common.cu"
static const int MAX_QUERY_LEN = 8192;
# 6 "./mummergpu.h"
extern "C" { struct QuerySet {
# 7 "./mummergpu.h"
int qfile;
# 9 "./mummergpu.h"
char *h_tex_array;
# 10 "./mummergpu.h"
char *d_tex_array;
# 11 "./mummergpu.h"
int *d_addrs_tex_array;
# 12 "./mummergpu.h"
int *h_addrs_tex_array;
# 13 "./mummergpu.h"
int *h_lengths_array;
# 14 "./mummergpu.h"
int *d_lengths_array;
# 16 "./mummergpu.h"
char **h_names;
# 18 "./mummergpu.h"
unsigned count;
# 19 "./mummergpu.h"
size_t texlen;
# 22 "./mummergpu.h"
size_t bytes_on_board;
# 23 "./mummergpu.h"
}; }
# 26 "./mummergpu.h"
extern "C" { struct AuxiliaryNodeData {
# 27 "./mummergpu.h"
int length;
# 28 "./mummergpu.h"
int numleaves;
# 29 "./mummergpu.h"
TextureAddress printParent;
# 30 "./mummergpu.h"
}; }
# 33 "./mummergpu.h"
extern "C" { struct Reference {
# 35 "./mummergpu.h"
char *str;
# 36 "./mummergpu.h"
size_t len;
# 37 "./mummergpu.h"
float t_load_from_disk;
# 39 "./mummergpu.h"
unsigned pitch;
# 40 "./mummergpu.h"
void *d_ref_array;
# 41 "./mummergpu.h"
char *h_ref_array;
# 44 "./mummergpu.h"
void *d_node_tex_array;
# 45 "./mummergpu.h"
void *h_node_tex_array;
# 47 "./mummergpu.h"
void *d_children_tex_array;
# 48 "./mummergpu.h"
void *h_children_tex_array;
# 50 "./mummergpu.h"
void *d_parent_tex_array;
# 51 "./mummergpu.h"
void *h_parent_tex_array;
# 61 "./mummergpu.h"
unsigned tex_node_height;
# 62 "./mummergpu.h"
unsigned tex_children_height;
# 63 "./mummergpu.h"
unsigned tex_width;
# 66 "./mummergpu.h"
size_t bytes_on_board;
# 68 "./mummergpu.h"
AuxiliaryNodeData *aux_data;
# 69 "./mummergpu.h"
int num_nodes;
# 71 "./mummergpu.h"
}; }
# 79 "./mummergpu.h"
extern "C" { struct MatchCoord {
# 81 "./mummergpu.h"
union {
# 82 "./mummergpu.h"
int2 data;
# 84 "./mummergpu.h"
struct {
# 85 "./mummergpu.h"
TextureAddress node;
# 86 "./mummergpu.h"
int edge_match_length;
# 87 "./mummergpu.h"
};
# 88 "./mummergpu.h"
};
# 89 "./mummergpu.h"
}; }
# 91 "./mummergpu.h"
extern "C" { struct MatchResults {
# 94 "./mummergpu.h"
MatchCoord *d_match_coords;
# 95 "./mummergpu.h"
MatchCoord *h_match_coords;
# 97 "./mummergpu.h"
unsigned numCoords;
# 105 "./mummergpu.h"
int *h_coord_tex_array;
# 108 "./mummergpu.h"
size_t bytes_on_board;
# 109 "./mummergpu.h"
}; }
# 112 "./mummergpu.h"
extern "C" { struct Statistics {
# 113 "./mummergpu.h"
float t_end_to_end;
# 114 "./mummergpu.h"
float t_match_kernel;
# 115 "./mummergpu.h"
float t_print_kernel;
# 116 "./mummergpu.h"
float t_results_to_disk;
# 117 "./mummergpu.h"
float t_queries_to_board;
# 118 "./mummergpu.h"
float t_match_coords_to_board;
# 119 "./mummergpu.h"
float t_match_coords_from_board;
# 120 "./mummergpu.h"
float t_tree_to_board;
# 121 "./mummergpu.h"
float t_ref_str_to_board;
# 122 "./mummergpu.h"
float t_queries_from_disk;
# 123 "./mummergpu.h"
float t_ref_from_disk;
# 124 "./mummergpu.h"
float t_tree_construction;
# 125 "./mummergpu.h"
float t_tree_reorder;
# 126 "./mummergpu.h"
float t_tree_flatten;
# 127 "./mummergpu.h"
float t_reorder_ref_str;
# 128 "./mummergpu.h"
float t_build_coord_offsets;
# 129 "./mummergpu.h"
float t_coords_to_buffers;
# 130 "./mummergpu.h"
float bp_avg_query_length;
# 137 "./mummergpu.h"
}; }
# 139 "./mummergpu.h"
extern "C" { struct MatchContext {
# 140 "./mummergpu.h"
char *full_ref;
# 141 "./mummergpu.h"
size_t full_ref_len;
# 143 "./mummergpu.h"
Reference *ref;
# 144 "./mummergpu.h"
QuerySet *queries;
# 145 "./mummergpu.h"
MatchResults results;
# 147 "./mummergpu.h"
bool on_cpu;
# 149 "./mummergpu.h"
int min_match_length;
# 151 "./mummergpu.h"
bool reverse;
# 152 "./mummergpu.h"
bool forwardreverse;
# 153 "./mummergpu.h"
bool forwardcoordinates;
# 154 "./mummergpu.h"
bool show_query_length;
# 155 "./mummergpu.h"
bool maxmatch;
# 157 "./mummergpu.h"
char *stats_file;
# 158 "./mummergpu.h"
char *dotfilename;
# 159 "./mummergpu.h"
char *texfilename;
# 160 "./mummergpu.h"
Statistics statistics;
# 161 "./mummergpu.h"
}; }
# 164 "./mummergpu.h"
extern "C" { struct ReferencePage {
# 165 "./mummergpu.h"
int begin;
# 166 "./mummergpu.h"
int end;
# 167 "./mummergpu.h"
int shadow_left;
# 168 "./mummergpu.h"
int shadow_right;
# 169 "./mummergpu.h"
MatchResults results;
# 170 "./mummergpu.h"
unsigned id;
# 171 "./mummergpu.h"
Reference ref;
# 172 "./mummergpu.h"
}; }
# 174 "./mummergpu.h"
extern "C" { static TextureAddress id2addr(int); }
# 176 "./mummergpu.h"
extern "C" int createReference(const char *, Reference *);
# 177 "./mummergpu.h"
extern "C" int destroyReference(Reference *);
# 179 "./mummergpu.h"
extern "C" int createQuerySet(const char *, QuerySet *);
# 180 "./mummergpu.h"
extern "C" int destroyQuerySet(QuerySet *);
# 182 "./mummergpu.h"
extern "C" int createMatchContext(Reference *, QuerySet *, MatchResults *, bool, int, char *, bool, bool, bool, bool, char *, char *, MatchContext *);
# 197 "./mummergpu.h"
extern "C" int destroyMatchContext(MatchContext *);
# 200 "./mummergpu.h"
extern "C" int matchQueries(MatchContext *);
# 202 "./mummergpu.h"
extern "C" void printStringForError(int);
# 205 "./mummergpu.h"
extern "C" { struct Timer_t {
# 207 "./mummergpu.h"
timeval start_m;
# 208 "./mummergpu.h"
timeval end_m;
# 209 "./mummergpu.h"
}; }
# 211 "./mummergpu.h"
extern "C" char *createTimer();
# 212 "./mummergpu.h"
extern "C" void startTimer(char *);
# 213 "./mummergpu.h"
extern "C" void stopTimer(char *);
# 214 "./mummergpu.h"
extern "C" float getTimerValue(char *);
# 215 "./mummergpu.h"
extern "C" void deleteTimer(char *);
# 131 "./mummergpu_kernel.cu"
static texture< uint4, 2, cudaReadModeElementType> nodetex;
# 132 "./mummergpu_kernel.cu"
static texture< uint4, 2, cudaReadModeElementType> childrentex;
# 142 "./mummergpu_kernel.cu"
static texture< char, 1, cudaReadModeElementType> reftex;
# 145 "./mummergpu_kernel.cu"
static texture< char, 1, cudaReadModeElementType> qrytex;
# 147 "./mummergpu_kernel.cu"
struct __attribute__((__aligned__(8))) _MatchCoord {
# 150 "./mummergpu_kernel.cu"
union {
# 151 "./mummergpu_kernel.cu"
int2 data;
# 153 "./mummergpu_kernel.cu"
struct {
# 154 "./mummergpu_kernel.cu"
int node;
# 155 "./mummergpu_kernel.cu"
int edge_match_length;
# 156 "./mummergpu_kernel.cu"
};
# 157 "./mummergpu_kernel.cu"
};
# 158 "./mummergpu_kernel.cu"
};
# 161 "./mummergpu_kernel.cu"
struct _PixelOfChildren {
# 164 "./mummergpu_kernel.cu"
union {
# 165 "./mummergpu_kernel.cu"
uint4 data;
# 168 "./mummergpu_kernel.cu"
union {
# 170 "./mummergpu_kernel.cu"
struct {
# 171 "./mummergpu_kernel.cu"
uchar3 a;
# 172 "./mummergpu_kernel.cu"
uchar3 c;
# 173 "./mummergpu_kernel.cu"
uchar3 g;
# 174 "./mummergpu_kernel.cu"
uchar3 t;
# 175 "./mummergpu_kernel.cu"
uchar3 d;
# 177 "./mummergpu_kernel.cu"
char leafchar;
# 178 "./mummergpu_kernel.cu"
};
# 181 "./mummergpu_kernel.cu"
struct {
# 182 "./mummergpu_kernel.cu"
uchar3 leafid;
# 183 "./mummergpu_kernel.cu"
unsigned char pad[12];
# 184 "./mummergpu_kernel.cu"
char leafchar0;
# 185 "./mummergpu_kernel.cu"
};
# 186 "./mummergpu_kernel.cu"
};
# 187 "./mummergpu_kernel.cu"
};
# 188 "./mummergpu_kernel.cu"
};
# 191 "./mummergpu_kernel.cu"
struct _PixelOfNode {
# 194 "./mummergpu_kernel.cu"
union {
# 195 "./mummergpu_kernel.cu"
uint4 data;
# 197 "./mummergpu_kernel.cu"
struct {
# 198 "./mummergpu_kernel.cu"
uchar3 parent;
# 199 "./mummergpu_kernel.cu"
uchar3 suffix;
# 201 "./mummergpu_kernel.cu"
uchar3 start;
# 202 "./mummergpu_kernel.cu"
uchar3 end;
# 203 "./mummergpu_kernel.cu"
uchar3 depth;
# 205 "./mummergpu_kernel.cu"
unsigned char pad;
# 206 "./mummergpu_kernel.cu"
};
# 207 "./mummergpu_kernel.cu"
};
# 208 "./mummergpu_kernel.cu"
};
# 228 "./mummergpu_kernel.cu"
static int addr2id(unsigned addr)
# 229 "./mummergpu_kernel.cu"
{exit(1);
# 252 "./mummergpu_kernel.cu"
}
# 254 "./mummergpu_kernel.cu"
static TextureAddress id2addr(int id)
# 255 "./mummergpu_kernel.cu"
{exit(1);
# 284 "./mummergpu_kernel.cu"
}
# 293 "./mummergpu_kernel.cu"
static void arrayToAddress(uchar3 arr, unsigned &addr)
# 294 "./mummergpu_kernel.cu"
{exit(1);
# 300 "./mummergpu_kernel.cu"
}
# 306 "./mummergpu_kernel.cu"
static char getRef(int refpos, char *
# 308 "./mummergpu_kernel.cu"
ref)
# 311 "./mummergpu_kernel.cu"
{exit(1);
# 330 "./mummergpu_kernel.cu"
}
# 336 "./mummergpu_kernel.cu"
static char rc(char c)
# 337 "./mummergpu_kernel.cu"
{exit(1);
# 347 "./mummergpu_kernel.cu"
}
# 353 "./mummergpu_kernel.cu"
static uint4 getNode(unsigned cur, bool
# 354 "./mummergpu_kernel.cu"
use_two_level)
# 362 "./mummergpu_kernel.cu"
{exit(1);
# 388 "./mummergpu_kernel.cu"
}
# 396 "./mummergpu_kernel.cu"
static uint4 getChildren(unsigned cur, bool
# 397 "./mummergpu_kernel.cu"
use_two_level)
# 405 "./mummergpu_kernel.cu"
{exit(1);
# 429 "./mummergpu_kernel.cu"
}
# 636 "./mummergpu_kernel.cu"
static void set_result(unsigned cur, _MatchCoord *
# 637 "./mummergpu_kernel.cu"
result, int
# 638 "./mummergpu_kernel.cu"
edge_match_length, int
# 639 "./mummergpu_kernel.cu"
qry_match_len, int
# 640 "./mummergpu_kernel.cu"
min_match_len, int
# 641 "./mummergpu_kernel.cu"
rc)
# 651 "./mummergpu_kernel.cu"
{exit(1);
# 669 "./mummergpu_kernel.cu"
}
# 678 "./mummergpu_kernel.cu"
void mummergpuKernel__entry(void *match_coords, char *
# 687 "./mummergpu_kernel.cu"
queries, char *
# 700 "./mummergpu_kernel.cu"
ref, const int *
# 702 "./mummergpu_kernel.cu"
queryAddrs, const int *
# 703 "./mummergpu_kernel.cu"
queryLengths, const int
# 704 "./mummergpu_kernel.cu"
numQueries, const int
# 705 "./mummergpu_kernel.cu"
min_match_len);
# 867 "./mummergpu_kernel.cu"
void mummergpuRCKernel__entry(MatchCoord *match_coords, char *
# 868 "./mummergpu_kernel.cu"
queries, const int *
# 869 "./mummergpu_kernel.cu"
queryAddrs, const int *
# 870 "./mummergpu_kernel.cu"
queryLengths, const int
# 871 "./mummergpu_kernel.cu"
numQueries, const int
# 872 "./mummergpu_kernel.cu"
min_match_len);
# 1043 "./mummergpu_kernel.cu"
void printKernel__entry(MatchInfo *matches, int
# 1044 "./mummergpu_kernel.cu"
totalMatches, Alignment *
# 1045 "./mummergpu_kernel.cu"
alignments, char *
# 1050 "./mummergpu_kernel.cu"
queries, const int *
# 1061 "./mummergpu_kernel.cu"
queryAddrs, const int *
# 1062 "./mummergpu_kernel.cu"
queryLengths, const int
# 1063 "./mummergpu_kernel.cu"
page_begin, const int
# 1064 "./mummergpu_kernel.cu"
page_end, const int
# 1065 "./mummergpu_kernel.cu"
page_shadow_left, const int
# 1066 "./mummergpu_kernel.cu"
page_shadow_right, const int
# 1067 "./mummergpu_kernel.cu"
min_match_length);
# 23 "mummergpu.cu"
int USE_PRINT_KERNEL = 1;
# 29 "mummergpu.cu"
unsigned cuda_calls = (0);
# 30 "mummergpu.cu"
void trap_dbg()
# 31 "mummergpu.cu"
{
# 32 "mummergpu.cu"
fprintf(stderr, "Trapped\n");
# 33 "mummergpu.cu"
}
# 78 "mummergpu.cu"
unsigned num_bind_tex_calls = (0);
# 106 "mummergpu.cu"
void runTest(int, char **);
# 109 "mummergpu.cu"
extern "C" void computeGold(MatchResults *, char *, char *, int *, int *, PixelOfNode *, PixelOfChildren *, int, int, int);
# 121 "mummergpu.cu"
extern "C" void getReferenceString(const char *, char **, size_t *);
# 124 "mummergpu.cu"
extern "C" void createTreeTexture(const char *, PixelOfNode **, PixelOfChildren **, unsigned *, unsigned *, unsigned *, AuxiliaryNodeData **, int *, int, Statistics *, const char *, const char *);
# 138 "mummergpu.cu"
extern "C" void getQueriesTexture(int, char **, size_t *, int **, char ***, int **, unsigned *, unsigned *, unsigned, int, bool);
# 151 "mummergpu.cu"
extern "C" int lookupNumLeaves(ReferencePage *, TextureAddress);
# 153 "mummergpu.cu"
void printAlignments(ReferencePage *, Alignment *, char *, int, TextureAddress, int, int, int, bool, bool);
# 164 "mummergpu.cu"
int countLeafNodes(int);
# 167 "mummergpu.cu"
extern "C" void mapQueriesEndToEnd(MatchContext *, ReferencePage *, MatchInfo *, unsigned, Alignment *, unsigned);
# 174 "mummergpu.cu"
char *createTimer()
# 175 "mummergpu.cu"
{
# 176 "mummergpu.cu"
unsigned *ptr = ((unsigned *)malloc(sizeof(Timer_t)));
# 177 "mummergpu.cu"
memset(ptr, 0, sizeof(Timer_t));
# 178 "mummergpu.cu"
return (char *)ptr;
# 179 "mummergpu.cu"
}
# 181 "mummergpu.cu"
void startTimer(char *ptr)
# 182 "mummergpu.cu"
{
# 183 "mummergpu.cu"
gettimeofday(&(((Timer_t *)ptr)->start_m), __null);
# 184 "mummergpu.cu"
}
# 186 "mummergpu.cu"
void stopTimer(char *ptr)
# 187 "mummergpu.cu"
{
# 188 "mummergpu.cu"
gettimeofday(&(((Timer_t *)ptr)->end_m), __null);
# 189 "mummergpu.cu"
}
# 191 "mummergpu.cu"
float getTimerValue(char *ptr)
# 192 "mummergpu.cu"
{
# 193 "mummergpu.cu"
Timer_t *timer = ((Timer_t *)ptr);
# 195 "mummergpu.cu"
if (timer == (__null))
# 196 "mummergpu.cu"
{
# 197 "mummergpu.cu"
fprintf(stderr, "Uninitialized timer!!!\n");
# 198 "mummergpu.cu"
return (0.0);
# 199 "mummergpu.cu"
}
# 201 "mummergpu.cu"
if (((timer->end_m).tv_sec) == (0)) { stopTimer(ptr); }
# 203 "mummergpu.cu"
return (float)(((1000.0) * (((timer->end_m).tv_sec) - ((timer->start_m).tv_sec))) + ((0.001000000000000000021) * (((timer->end_m).tv_usec) - ((timer->start_m).tv_usec))));
# 205 "mummergpu.cu"
}
# 207 "mummergpu.cu"
void deleteTimer(char *ptr)
# 208 "mummergpu.cu"
{
# 209 "mummergpu.cu"
free((Timer_t *)ptr);
# 210 "mummergpu.cu"
}
# 213 "mummergpu.cu"
extern "C" int createReference(const char *fromFile, Reference *ref)
# 214 "mummergpu.cu"
{
# 215 "mummergpu.cu"
if ((!(fromFile)) || (!(ref))) {
# 216 "mummergpu.cu"
return -1; }
# 218 "mummergpu.cu"
char *loadreftimer = createTimer();
# 219 "mummergpu.cu"
startTimer(loadreftimer);
# 221 "mummergpu.cu"
getReferenceString(fromFile, &(ref->str), &(ref->len));
# 223 "mummergpu.cu"
stopTimer(loadreftimer);
# 224 "mummergpu.cu"
(ref->t_load_from_disk) += getTimerValue(loadreftimer);
# 225 "mummergpu.cu"
deleteTimer(loadreftimer);
# 227 "mummergpu.cu"
return 0;
# 228 "mummergpu.cu"
}
# 231 "mummergpu.cu"
extern "C" int destroyReference(Reference *ref)
# 232 "mummergpu.cu"
{
# 233 "mummergpu.cu"
free(ref->h_node_tex_array);
# 234 "mummergpu.cu"
free(ref->h_children_tex_array);
# 235 "mummergpu.cu"
free(ref->str);
# 240 "mummergpu.cu"
free(ref->aux_data);
# 245 "mummergpu.cu"
(ref->str) = (__null);
# 246 "mummergpu.cu"
(ref->len) = (0);
# 248 "mummergpu.cu"
return 0;
# 249 "mummergpu.cu"
}
# 252 "mummergpu.cu"
extern "C" int createQuerySet(const char *fromFile, QuerySet *queries)
# 253 "mummergpu.cu"
{
# 255 "mummergpu.cu"
fprintf(stderr, "Opening %s...\n", fromFile);
# 256 "mummergpu.cu"
int qfile = open(fromFile, 0);
# 258 "mummergpu.cu"
if (qfile == (-1))
# 259 "mummergpu.cu"
{
# 260 "mummergpu.cu"
fprintf(stderr, "Can\'t open %s: %d\n", fromFile, *__errno_location());
# 261 "mummergpu.cu"
exit(1);
# 262 "mummergpu.cu"
}
# 264 "mummergpu.cu"
(queries->qfile) = qfile;
# 266 "mummergpu.cu"
return 0;
# 267 "mummergpu.cu"
}
# 270 "mummergpu.cu"
extern "C" int destroyQuerySet(QuerySet *queries)
# 271 "mummergpu.cu"
{
# 273 "mummergpu.cu"
if (queries->qfile) {
# 274 "mummergpu.cu"
close(queries->qfile); }
# 276 "mummergpu.cu"
return 0;
# 277 "mummergpu.cu"
}
# 280 "mummergpu.cu"
extern "C" void printStringForError(int err)
# 281 "mummergpu.cu"
{
# 283 "mummergpu.cu"
}
# 286 "mummergpu.cu"
extern "C" int createMatchContext(Reference *ref, QuerySet *
# 287 "mummergpu.cu"
queries, MatchResults *
# 288 "mummergpu.cu"
matches, bool
# 289 "mummergpu.cu"
on_cpu, int
# 290 "mummergpu.cu"
min_match_length, char *
# 291 "mummergpu.cu"
stats_file, bool
# 292 "mummergpu.cu"
reverse, bool
# 293 "mummergpu.cu"
forwardreverse, bool
# 294 "mummergpu.cu"
forwardcoordinates, bool
# 295 "mummergpu.cu"
showQueryLength, char *
# 296 "mummergpu.cu"
dotfilename, char *
# 297 "mummergpu.cu"
texfilename, MatchContext *
# 298 "mummergpu.cu"
ctx) {
# 300 "mummergpu.cu"
(ctx->queries) = queries;
# 301 "mummergpu.cu"
(ctx->ref) = ref;
# 302 "mummergpu.cu"
(ctx->full_ref) = (ref->str);
# 303 "mummergpu.cu"
(ctx->full_ref_len) = (ref->len);
# 305 "mummergpu.cu"
(ctx->on_cpu) = on_cpu;
# 306 "mummergpu.cu"
(ctx->min_match_length) = min_match_length;
# 307 "mummergpu.cu"
(ctx->stats_file) = stats_file;
# 308 "mummergpu.cu"
(ctx->reverse) = reverse;
# 309 "mummergpu.cu"
(ctx->forwardreverse) = forwardreverse;
# 310 "mummergpu.cu"
(ctx->forwardcoordinates) = forwardcoordinates;
# 311 "mummergpu.cu"
(ctx->show_query_length) = showQueryLength;
# 312 "mummergpu.cu"
(ctx->dotfilename) = dotfilename;
# 313 "mummergpu.cu"
(ctx->texfilename) = texfilename;
# 314 "mummergpu.cu"
return 0;
# 315 "mummergpu.cu"
}
# 319 "mummergpu.cu"
extern "C" int destroyMatchContext(MatchContext *ctx)
# 320 "mummergpu.cu"
{
# 321 "mummergpu.cu"
free(ctx->full_ref);
# 323 "mummergpu.cu"
destroyQuerySet(ctx->queries);
# 324 "mummergpu.cu"
return 0;
# 325 "mummergpu.cu"
}
# 327 "mummergpu.cu"
void buildReferenceTexture(Reference *ref, char *
# 328 "mummergpu.cu"
full_ref, size_t
# 329 "mummergpu.cu"
begin, size_t
# 330 "mummergpu.cu"
end, int
# 331 "mummergpu.cu"
min_match_len, char *
# 332 "mummergpu.cu"
dotfilename, char *
# 333 "mummergpu.cu"
texfilename, Statistics *
# 334 "mummergpu.cu"
statistics)
# 335 "mummergpu.cu"
{
# 336 "mummergpu.cu"
fprintf(stderr, "Building reference texture...\n");
# 338 "mummergpu.cu"
PixelOfNode *nodeTexture = (__null);
# 339 "mummergpu.cu"
PixelOfChildren *childrenTexture = (__null);
# 341 "mummergpu.cu"
unsigned width = (0);
# 342 "mummergpu.cu"
unsigned node_height = (0);
# 343 "mummergpu.cu"
unsigned children_height = (0);
# 345 "mummergpu.cu"
AuxiliaryNodeData *aux_data = (__null);
# 346 "mummergpu.cu"
int num_nodes;
# 348 "mummergpu.cu"
char *loadreftimer = createTimer();
# 349 "mummergpu.cu"
startTimer(loadreftimer);
# 351 "mummergpu.cu"
(ref->len) = ((end - begin) + (3));
# 352 "mummergpu.cu"
(ref->str) = ((char *)malloc(ref->len));
# 353 "mummergpu.cu"
((ref->str)[0]) = 's';
# 354 "mummergpu.cu"
strncpy((ref->str) + 1, full_ref + begin, (ref->len) - (3));
# 355 "mummergpu.cu"
strcpy(((ref->str) + (ref->len)) - 2, "$");
# 357 "mummergpu.cu"
stopTimer(loadreftimer);
# 358 "mummergpu.cu"
(statistics->t_ref_from_disk) += (getTimerValue(loadreftimer) + (ref->t_load_from_disk));
# 359 "mummergpu.cu"
deleteTimer(loadreftimer);
# 361 "mummergpu.cu"
createTreeTexture(ref->str, &nodeTexture, &childrenTexture, &width, &node_height, &children_height, &aux_data, &num_nodes, min_match_len, statistics, dotfilename, texfilename);
# 374 "mummergpu.cu"
(ref->h_node_tex_array) = nodeTexture;
# 375 "mummergpu.cu"
(ref->h_children_tex_array) = childrenTexture;
# 376 "mummergpu.cu"
(ref->tex_width) = width;
# 377 "mummergpu.cu"
(ref->tex_node_height) = node_height;
# 378 "mummergpu.cu"
(ref->tex_children_height) = children_height;
# 385 "mummergpu.cu"
(ref->aux_data) = aux_data;
# 386 "mummergpu.cu"
(ref->num_nodes) = num_nodes;
# 388 "mummergpu.cu"
(ref->bytes_on_board) = (((width * node_height) * sizeof(PixelOfNode)) + ((width * children_height) * sizeof(PixelOfChildren)));
# 390 "mummergpu.cu"
fprintf(stderr, "This tree will need %d bytes on the board\n", ref->bytes_on_board);
# 453 "mummergpu.cu"
fprintf(stderr, "The refstr requires %d bytes\n", ref->len);
# 454 "mummergpu.cu"
(ref->bytes_on_board) += (ref->len);
# 458 "mummergpu.cu"
}
# 460 "mummergpu.cu"
void boardMemory(unsigned *free_mem, unsigned *total_mem)
# 461 "mummergpu.cu"
{
# 465 "mummergpu.cu"
(*free_mem) = ((512 * 1024) * 1024);
# 466 "mummergpu.cu"
(*total_mem) = ((768 * 1024) * 1024);
# 470 "mummergpu.cu"
}
# 473 "mummergpu.cu"
void loadReferenceTexture(MatchContext *ctx)
# 474 "mummergpu.cu"
{
# 475 "mummergpu.cu"
Reference *ref = (ctx->ref);
# 476 "mummergpu.cu"
int numrows = (ceil((ref->len) / ((float)(ref->pitch))));
# 477 "mummergpu.cu"
int blocksize = 4;
# 478 "mummergpu.cu"
numrows += blocksize;
# 480 "mummergpu.cu"
cudaChannelFormatDesc refTextureDesc = cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindSigned);
# 483 "mummergpu.cu"
if (!(ctx->on_cpu)) {
# 484 "mummergpu.cu"
char *toboardtimer = createTimer();
# 485 "mummergpu.cu"
startTimer(toboardtimer);
# 548 "mummergpu.cu"
do { cudaMalloc((void **)(&(ref->d_ref_array)), ref->len); ++num_bind_tex_calls; } while (0);
# 549 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)(ref->d_ref_array), ref->str, ref->len, cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 552, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 554 "mummergpu.cu"
((ctx->ref)->bytes_on_board) += (ref->len);
# 557 "mummergpu.cu"
stopTimer(toboardtimer);
# 558 "mummergpu.cu"
((ctx->statistics).t_ref_str_to_board) += getTimerValue(toboardtimer);
# 559 "mummergpu.cu"
deleteTimer(toboardtimer);
# 560 "mummergpu.cu"
} else
# 561 "mummergpu.cu"
{
# 562 "mummergpu.cu"
(ref->d_ref_array) = (__null);
# 563 "mummergpu.cu"
}
# 564 "mummergpu.cu"
}
# 567 "mummergpu.cu"
void unloadReferenceString(Reference *ref)
# 568 "mummergpu.cu"
{
# 576 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(ref->d_ref_array); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 576, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 579 "mummergpu.cu"
(ref->d_ref_array) = (__null);
# 580 "mummergpu.cu"
}
# 582 "mummergpu.cu"
void unloadReferenceTree(MatchContext *ctx)
# 583 "mummergpu.cu"
{
# 584 "mummergpu.cu"
Reference *ref = (ctx->ref);
# 589 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaUnbindTexture(nodetex); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 589, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 590 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFreeArray((cudaArray *)(ref->d_node_tex_array)); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 590, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 594 "mummergpu.cu"
(ref->d_node_tex_array) = (__null);
# 597 "mummergpu.cu"
if (ref->d_children_tex_array)
# 598 "mummergpu.cu"
{
# 600 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaUnbindTexture(childrentex); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 600, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 601 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFreeArray((cudaArray *)(ref->d_children_tex_array)); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 601, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 605 "mummergpu.cu"
}
# 607 "mummergpu.cu"
(ref->d_children_tex_array) = (__null);
# 638 "mummergpu.cu"
}
# 641 "mummergpu.cu"
void loadReference(MatchContext *ctx) {
# 643 "mummergpu.cu"
Reference *ref = (ctx->ref);
# 645 "mummergpu.cu"
(ref->bytes_on_board) = (0);
# 647 "mummergpu.cu"
loadReferenceTexture(ctx);
# 649 "mummergpu.cu"
if (!(ctx->on_cpu)) {
# 650 "mummergpu.cu"
char *toboardtimer = createTimer();
# 651 "mummergpu.cu"
startTimer(toboardtimer);
# 654 "mummergpu.cu"
(ref->bytes_on_board) += (((ref->tex_width) * (ref->tex_node_height)) * sizeof(PixelOfNode));
# 657 "mummergpu.cu"
(ref->bytes_on_board) += (((ref->tex_width) * (ref->tex_children_height)) * sizeof(PixelOfChildren));
# 662 "mummergpu.cu"
cudaChannelFormatDesc nodeTextureDesc = cudaCreateChannelDesc(32, 32, 32, 32, cudaChannelFormatKindUnsigned);
# 665 "mummergpu.cu"
do { cudaMallocArray((cudaArray **)(&(ref->d_node_tex_array)), &nodeTextureDesc, ref->tex_width, ref->tex_node_height); ++num_bind_tex_calls; } while (0);
# 672 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpyToArray((cudaArray *)(ref->d_node_tex_array), 0, 0, ref->h_node_tex_array, ((ref->tex_width) * (ref->tex_node_height)) * sizeof(PixelOfNode), cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 677, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 679 "mummergpu.cu"
((nodetex.addressMode)[0]) = cudaAddressModeClamp;
# 680 "mummergpu.cu"
((nodetex.addressMode)[1]) = cudaAddressModeClamp;
# 681 "mummergpu.cu"
(nodetex.filterMode) = cudaFilterModePoint;
# 682 "mummergpu.cu"
(nodetex.normalized) = (false);
# 684 "mummergpu.cu"
do { do { cuda_calls++; cudaError err = cudaBindTextureToArray(nodetex, (cudaArray *)(ref->d_node_tex_array), nodeTextureDesc); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 685, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0); ++num_bind_tex_calls; } while (0);
# 703 "mummergpu.cu"
if (ref->tex_children_height)
# 704 "mummergpu.cu"
{
# 706 "mummergpu.cu"
cudaChannelFormatDesc childrenTextureDesc = cudaCreateChannelDesc(32, 32, 32, 32, cudaChannelFormatKindUnsigned);
# 708 "mummergpu.cu"
do { cudaMallocArray((cudaArray **)(&(ref->d_children_tex_array)), &childrenTextureDesc, ref->tex_width, ref->tex_children_height); ++num_bind_tex_calls; } while (0);
# 713 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpyToArray((cudaArray *)(ref->d_children_tex_array), 0, 0, ref->h_children_tex_array, ((ref->tex_width) * (ref->tex_children_height)) * sizeof(PixelOfChildren), cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 718, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 720 "mummergpu.cu"
((childrentex.addressMode)[0]) = cudaAddressModeClamp;
# 721 "mummergpu.cu"
((childrentex.addressMode)[1]) = cudaAddressModeClamp;
# 722 "mummergpu.cu"
(childrentex.filterMode) = cudaFilterModePoint;
# 723 "mummergpu.cu"
(childrentex.normalized) = (false);
# 725 "mummergpu.cu"
do { do { cuda_calls++; cudaError err = cudaBindTextureToArray(childrentex, (cudaArray *)(ref->d_children_tex_array), childrenTextureDesc); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 726, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0); ++num_bind_tex_calls; } while (0);
# 742 "mummergpu.cu"
}
# 883 "mummergpu.cu"
stopTimer(toboardtimer);
# 884 "mummergpu.cu"
((ctx->statistics).t_tree_to_board) += getTimerValue(toboardtimer);
# 885 "mummergpu.cu"
deleteTimer(toboardtimer);
# 887 "mummergpu.cu"
fprintf(stderr, "done\n");
# 888 "mummergpu.cu"
} else
# 889 "mummergpu.cu"
{
# 890 "mummergpu.cu"
(ref->d_node_tex_array) = (__null);
# 891 "mummergpu.cu"
(ref->d_children_tex_array) = (__null);
# 892 "mummergpu.cu"
}
# 893 "mummergpu.cu"
}
# 897 "mummergpu.cu"
void dumpQueryBlockInfo(QuerySet *queries)
# 898 "mummergpu.cu"
{
# 899 "mummergpu.cu"
fprintf(stderr, "\tProcessing queries %s to %s\n", (queries->h_names)[0], (queries->h_names)[(queries->count) - (1)]);
# 902 "mummergpu.cu"
}
# 904 "mummergpu.cu"
void loadQueries(MatchContext *ctx)
# 905 "mummergpu.cu"
{
# 906 "mummergpu.cu"
QuerySet *queries = (ctx->queries);
# 907 "mummergpu.cu"
(queries->bytes_on_board) = (0);
# 909 "mummergpu.cu"
unsigned numQueries = (queries->count);
# 911 "mummergpu.cu"
if (!(ctx->on_cpu)) {
# 912 "mummergpu.cu"
fprintf(stderr, "Allocating device memory for queries... ");
# 914 "mummergpu.cu"
char *toboardtimer = createTimer();
# 915 "mummergpu.cu"
startTimer(toboardtimer);
# 917 "mummergpu.cu"
dumpQueryBlockInfo(queries);
# 918 "mummergpu.cu"
do { cudaMalloc((void **)(&(queries->d_tex_array)), queries->texlen); ++num_bind_tex_calls; } while (0);
# 921 "mummergpu.cu"
(queries->bytes_on_board) += (queries->texlen);
# 923 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)(queries->d_tex_array), (queries->h_tex_array) + ((queries->h_addrs_tex_array)[0]), queries->texlen, cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 926, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 937 "mummergpu.cu"
do { cudaMalloc((void **)(&(queries->d_addrs_tex_array)), numQueries * sizeof(int)); ++num_bind_tex_calls; } while (0);
# 940 "mummergpu.cu"
(queries->bytes_on_board) += (numQueries * sizeof(int));
# 942 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)(queries->d_addrs_tex_array), queries->h_addrs_tex_array, numQueries * sizeof(int), cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 945, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 947 "mummergpu.cu"
do { cudaMalloc((void **)(&(queries->d_lengths_array)), numQueries * sizeof(int)); ++num_bind_tex_calls; } while (0);
# 950 "mummergpu.cu"
(queries->bytes_on_board) += (numQueries * sizeof(int));
# 952 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)(queries->d_lengths_array), queries->h_lengths_array, numQueries * sizeof(int), cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 955, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 956 "mummergpu.cu"
stopTimer(toboardtimer);
# 957 "mummergpu.cu"
((ctx->statistics).t_queries_to_board) += getTimerValue(toboardtimer);
# 958 "mummergpu.cu"
deleteTimer(toboardtimer);
# 960 "mummergpu.cu"
fprintf(stderr, "\tallocated %ld bytes\n", queries->bytes_on_board);
# 962 "mummergpu.cu"
} else
# 963 "mummergpu.cu"
{
# 964 "mummergpu.cu"
(queries->d_addrs_tex_array) = (__null);
# 965 "mummergpu.cu"
(queries->d_tex_array) = (__null);
# 966 "mummergpu.cu"
(queries->d_lengths_array) = (__null);
# 967 "mummergpu.cu"
fprintf(stderr, " allocated %ld bytes\n", (((2) * numQueries) * sizeof(int)) + (queries->texlen));
# 968 "mummergpu.cu"
}
# 971 "mummergpu.cu"
}
# 974 "mummergpu.cu"
void unloadQueries(MatchContext *ctx)
# 975 "mummergpu.cu"
{
# 976 "mummergpu.cu"
QuerySet *queries = (ctx->queries);
# 978 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(queries->d_tex_array); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 978, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 979 "mummergpu.cu"
(queries->d_tex_array) = (__null);
# 981 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(queries->d_addrs_tex_array); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 981, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 982 "mummergpu.cu"
(queries->d_addrs_tex_array) = (__null);
# 984 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(queries->d_lengths_array); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 984, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 985 "mummergpu.cu"
(queries->d_lengths_array) = (__null);
# 987 "mummergpu.cu"
(queries->bytes_on_board) = (0);
# 988 "mummergpu.cu"
}
# 992 "mummergpu.cu"
inline int match_coord_addrs(int qryid, int qry_addrs, int match_length)
# 993 "mummergpu.cu"
{
# 994 "mummergpu.cu"
return qry_addrs - (qryid * (match_length + 1));
# 995 "mummergpu.cu"
}
# 1000 "mummergpu.cu"
void buildCoordOffsetArray(MatchContext *ctx, int **
# 1001 "mummergpu.cu"
h_coord_offset_array, unsigned *
# 1002 "mummergpu.cu"
num_coords)
# 1003 "mummergpu.cu"
{
# 1004 "mummergpu.cu"
int numCoords = 0;
# 1005 "mummergpu.cu"
int match_length = (ctx->min_match_length);
# 1006 "mummergpu.cu"
int numQueries = ((ctx->queries)->count);
# 1007 "mummergpu.cu"
int *lengths = ((ctx->queries)->h_lengths_array);
# 1009 "mummergpu.cu"
int *coord_offsets = ((int *)calloc(numQueries, sizeof(int)));
# 1033 "mummergpu.cu"
for (unsigned i = (0); i < numQueries; ++i)
# 1034 "mummergpu.cu"
{
# 1035 "mummergpu.cu"
int qryoffset = (((ctx->queries)->h_addrs_tex_array)[i]);
# 1036 "mummergpu.cu"
(coord_offsets[i]) = match_coord_addrs(i, qryoffset, match_length);
# 1037 "mummergpu.cu"
}
# 1038 "mummergpu.cu"
if (numQueries > 0)
# 1039 "mummergpu.cu"
{
# 1040 "mummergpu.cu"
unsigned last_qry = (numQueries - 1);
# 1041 "mummergpu.cu"
unsigned last_qry_len = (((lengths[last_qry]) - match_length) + 1);
# 1042 "mummergpu.cu"
numCoords = ((coord_offsets[last_qry]) + last_qry_len);
# 1043 "mummergpu.cu"
fprintf(stderr, "Need %d match coords for this result array\n", numCoords);
# 1045 "mummergpu.cu"
}
# 1047 "mummergpu.cu"
(*num_coords) = numCoords;
# 1048 "mummergpu.cu"
(*h_coord_offset_array) = coord_offsets;
# 1049 "mummergpu.cu"
}
# 1052 "mummergpu.cu"
void loadResultBuffer(MatchContext *ctx)
# 1053 "mummergpu.cu"
{
# 1054 "mummergpu.cu"
unsigned numQueries = ((ctx->queries)->count);
# 1056 "mummergpu.cu"
(numQueries) ? (static_cast< void>(0)) : __assert_fail("numQueries", "mummergpu.cu", 1056, __PRETTY_FUNCTION__);
# 1058 "mummergpu.cu"
char *offsettimer = createTimer();
# 1059 "mummergpu.cu"
startTimer(offsettimer);
# 1061 "mummergpu.cu"
buildCoordOffsetArray(ctx, &((ctx->results).h_coord_tex_array), &((ctx->results).numCoords));
# 1065 "mummergpu.cu"
stopTimer(offsettimer);
# 1066 "mummergpu.cu"
((ctx->statistics).t_build_coord_offsets) += getTimerValue(offsettimer);
# 1067 "mummergpu.cu"
deleteTimer(offsettimer);
# 1069 "mummergpu.cu"
unsigned numCoords = ((ctx->results).numCoords);
# 1070 "mummergpu.cu"
fprintf(stderr, "Allocating result array for %d queries (%d bytes) ...", numQueries, numCoords * sizeof(MatchCoord));
# 1073 "mummergpu.cu"
unsigned boardFreeMemory = (0);
# 1074 "mummergpu.cu"
unsigned total_mem = (0);
# 1076 "mummergpu.cu"
boardMemory(&boardFreeMemory, &total_mem);
# 1078 "mummergpu.cu"
fprintf(stderr, "board free memory: %u total memory: %u\n", boardFreeMemory, total_mem);
# 1081 "mummergpu.cu"
((ctx->results).h_match_coords) = ((MatchCoord *)calloc(numCoords, sizeof(MatchCoord)));
# 1082 "mummergpu.cu"
if (((ctx->results).h_match_coords) == (__null))
# 1083 "mummergpu.cu"
{
# 1084 "mummergpu.cu"
trap_dbg();
# 1085 "mummergpu.cu"
exit(1);
# 1086 "mummergpu.cu"
}
# 1088 "mummergpu.cu"
if (!(ctx->on_cpu)) {
# 1089 "mummergpu.cu"
char *toboardtimer = createTimer();
# 1090 "mummergpu.cu"
startTimer(toboardtimer);
# 1092 "mummergpu.cu"
((ctx->results).bytes_on_board) = (0);
# 1094 "mummergpu.cu"
do { cudaMalloc((void **)(&((ctx->results).d_match_coords)), numCoords * sizeof(MatchCoord)); ++num_bind_tex_calls; } while (0);
# 1096 "mummergpu.cu"
((ctx->results).bytes_on_board) += (numCoords * sizeof(MatchCoord));
# 1098 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemset((void *)((ctx->results).d_match_coords), 0, numCoords * sizeof(MatchCoord)); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 1099, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1112 "mummergpu.cu"
stopTimer(toboardtimer);
# 1113 "mummergpu.cu"
((ctx->statistics).t_match_coords_to_board) += getTimerValue(toboardtimer);
# 1114 "mummergpu.cu"
deleteTimer(toboardtimer);
# 1115 "mummergpu.cu"
} else
# 1116 "mummergpu.cu"
{
# 1117 "mummergpu.cu"
((ctx->results).d_match_coords) = (__null);
# 1118 "mummergpu.cu"
}
# 1120 "mummergpu.cu"
fprintf(stderr, "done\n");
# 1121 "mummergpu.cu"
}
# 1124 "mummergpu.cu"
void unloadResultBuffer(MatchContext *ctx) {
# 1125 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree((ctx->results).d_match_coords); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 1125, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1126 "mummergpu.cu"
((ctx->results).d_match_coords) = (__null);
# 1127 "mummergpu.cu"
((ctx->results).bytes_on_board) = (0);
# 1132 "mummergpu.cu"
}
# 1134 "mummergpu.cu"
void transferResultsFromDevice(MatchContext *ctx)
# 1135 "mummergpu.cu"
{
# 1136 "mummergpu.cu"
if (!(ctx->on_cpu))
# 1137 "mummergpu.cu"
{
# 1138 "mummergpu.cu"
char *fromboardtimer = createTimer();
# 1139 "mummergpu.cu"
startTimer(fromboardtimer);
# 1141 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((ctx->results).h_match_coords, (ctx->results).d_match_coords, ((ctx->results).numCoords) * sizeof(MatchCoord), cudaMemcpyDeviceToHost); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 1144, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1189 "mummergpu.cu"
stopTimer(fromboardtimer);
# 1190 "mummergpu.cu"
((ctx->statistics).t_match_coords_from_board) += getTimerValue(fromboardtimer);
# 1191 "mummergpu.cu"
deleteTimer(fromboardtimer);
# 1192 "mummergpu.cu"
}
# 1194 "mummergpu.cu"
}
# 1197 "mummergpu.cu"
int flushOutput();
# 1198 "mummergpu.cu"
int addToBuffer(char *);
# 1200 "mummergpu.cu"
char numbuffer[32];
# 1202 "mummergpu.cu"
MatchCoord *coordForQueryChar(MatchContext *ctx, unsigned
# 1203 "mummergpu.cu"
qryid, unsigned
# 1204 "mummergpu.cu"
qrychar)
# 1205 "mummergpu.cu"
{
# 1206 "mummergpu.cu"
MatchResults *results = (&(ctx->results));
# 1207 "mummergpu.cu"
MatchCoord *coords = (results->h_match_coords);
# 1211 "mummergpu.cu"
return (coords + ((results->h_coord_tex_array)[qryid])) + qrychar;
# 1213 "mummergpu.cu"
}
# 1215 "mummergpu.cu"
void coordsToPrintBuffers(MatchContext *ctx, ReferencePage *
# 1216 "mummergpu.cu"
page, MatchInfo **
# 1217 "mummergpu.cu"
matches, Alignment **
# 1218 "mummergpu.cu"
alignments, unsigned
# 1219 "mummergpu.cu"
mem_avail, unsigned *
# 1220 "mummergpu.cu"
coord_idx, unsigned *
# 1221 "mummergpu.cu"
match_idx, unsigned *
# 1222 "mummergpu.cu"
align_idx, unsigned *
# 1223 "mummergpu.cu"
nextqry, unsigned *
# 1224 "mummergpu.cu"
nextqrychar)
# 1225 "mummergpu.cu"
{
# 1226 "mummergpu.cu"
unsigned numQueries = ((ctx->queries)->count);
# 1227 "mummergpu.cu"
int match_length = (ctx->min_match_length);
# 1228 "mummergpu.cu"
unsigned cidx = (*coord_idx);
# 1229 "mummergpu.cu"
unsigned midx = (0);
# 1231 "mummergpu.cu"
unsigned numCoords = ((ctx->results).numCoords);
# 1233 "mummergpu.cu"
unsigned numMatches = (0);
# 1234 "mummergpu.cu"
unsigned numAlignments = (0);
# 1236 "mummergpu.cu"
int DEBUG = 0;
# 1237 "mummergpu.cu"
if ((DEBUG) && (cidx == (0)))
# 1238 "mummergpu.cu"
{
# 1239 "mummergpu.cu"
for (int j = 0; j < numCoords; ++j)
# 1240 "mummergpu.cu"
{
# 1241 "mummergpu.cu"
MatchCoord *coord = (((ctx->results).h_match_coords) + j);
# 1242 "mummergpu.cu"
if ((((coord->node).data) > (0)) && (!((coord->edge_match_length) & 32768)))
# 1243 "mummergpu.cu"
{
# 1246 "mummergpu.cu"
fprintf(stdout, "node: %d leaves:%d\n", (coord->node).data, lookupNumLeaves(page, coord->node));
# 1248 "mummergpu.cu"
}
# 1249 "mummergpu.cu"
}
# 1250 "mummergpu.cu"
exit(0);
# 1251 "mummergpu.cu"
}
# 1255 "mummergpu.cu"
for (int j = (cidx); j < numCoords; ++j)
# 1256 "mummergpu.cu"
{
# 1257 "mummergpu.cu"
MatchCoord *coord = (((ctx->results).h_match_coords) + j);
# 1259 "mummergpu.cu"
int queryAlignments = 0;
# 1260 "mummergpu.cu"
int queryMatches = 0;
# 1262 "mummergpu.cu"
if ((((coord->node).data) > (0)) && (!((coord->edge_match_length) & 32768)))
# 1263 "mummergpu.cu"
{
# 1264 "mummergpu.cu"
int numLeaves = lookupNumLeaves(page, coord->node);
# 1265 "mummergpu.cu"
queryAlignments += numLeaves;
# 1266 "mummergpu.cu"
queryMatches++;
# 1267 "mummergpu.cu"
}
# 1268 "mummergpu.cu"
int allMatches = (numMatches + queryMatches);
# 1269 "mummergpu.cu"
int allAlignments = (numAlignments + queryAlignments);
# 1271 "mummergpu.cu"
int neededSize = ((allMatches * sizeof(MatchInfo)) + (allAlignments * sizeof(Alignment)));
# 1273 "mummergpu.cu"
if ((neededSize > mem_avail) || ((allMatches / 256) >= MAX_GRID_DIMENSION))
# 1274 "mummergpu.cu"
{
# 1276 "mummergpu.cu"
break;
# 1277 "mummergpu.cu"
}
# 1279 "mummergpu.cu"
++cidx;
# 1280 "mummergpu.cu"
numMatches = allMatches;
# 1281 "mummergpu.cu"
numAlignments = allAlignments;
# 1282 "mummergpu.cu"
}
# 1284 "mummergpu.cu"
MatchInfo *M = ((MatchInfo *)calloc(numMatches, sizeof(MatchInfo)));
# 1285 "mummergpu.cu"
unsigned alignmentOffset = (0);
# 1287 "mummergpu.cu"
int qry = (*nextqry);
# 1288 "mummergpu.cu"
int qrychar = (*nextqrychar);
# 1289 "mummergpu.cu"
bool set_full = false;
# 1290 "mummergpu.cu"
while (qry < numQueries)
# 1291 "mummergpu.cu"
{
# 1293 "mummergpu.cu"
int qlen = (((((ctx->queries)->h_lengths_array)[qry]) + 1) - match_length);
# 1295 "mummergpu.cu"
while (qrychar < qlen)
# 1296 "mummergpu.cu"
{
# 1297 "mummergpu.cu"
if (midx >= numMatches)
# 1298 "mummergpu.cu"
{
# 1299 "mummergpu.cu"
set_full = true;
# 1300 "mummergpu.cu"
break;
# 1301 "mummergpu.cu"
}
# 1303 "mummergpu.cu"
MatchCoord *coord = coordForQueryChar(ctx, qry, qrychar);
# 1305 "mummergpu.cu"
if ((((coord->node).data) > (0)) && (!((coord->edge_match_length) & 32768)))
# 1306 "mummergpu.cu"
{
# 1307 "mummergpu.cu"
MatchInfo m;
# 1308 "mummergpu.cu"
(m.resultsoffset) = alignmentOffset;
# 1309 "mummergpu.cu"
(m.qrystartpos) = qrychar;
# 1310 "mummergpu.cu"
(m.matchnode) = (coord->node);
# 1311 "mummergpu.cu"
(m.edgematch) = (coord->edge_match_length);
# 1312 "mummergpu.cu"
(m.numLeaves) = (lookupNumLeaves(page, m.matchnode));
# 1313 "mummergpu.cu"
(m.queryid) = qry;
# 1315 "mummergpu.cu"
alignmentOffset += (m.numLeaves);
# 1316 "mummergpu.cu"
(M[midx++]) = m;
# 1317 "mummergpu.cu"
}
# 1319 "mummergpu.cu"
++qrychar;
# 1320 "mummergpu.cu"
}
# 1322 "mummergpu.cu"
if (set_full) {
# 1323 "mummergpu.cu"
break; }
# 1325 "mummergpu.cu"
++qry;
# 1326 "mummergpu.cu"
qrychar = 0;
# 1327 "mummergpu.cu"
}
# 1329 "mummergpu.cu"
(*coord_idx) = cidx;
# 1330 "mummergpu.cu"
(*match_idx) = midx;
# 1331 "mummergpu.cu"
(*align_idx) = alignmentOffset;
# 1332 "mummergpu.cu"
(*matches) = M;
# 1333 "mummergpu.cu"
(*nextqry) = qry;
# 1334 "mummergpu.cu"
(*nextqrychar) = qrychar;
# 1335 "mummergpu.cu"
fprintf(stderr, "Allocing %d bytes of host memory for %d alignments\n", alignmentOffset * sizeof(Alignment), numAlignments);
# 1336 "mummergpu.cu"
(*alignments) = ((Alignment *)calloc(alignmentOffset, sizeof(Alignment)));
# 1338 "mummergpu.cu"
}
# 1341 "mummergpu.cu"
void runPrintKernel(MatchContext *ctx, ReferencePage *
# 1342 "mummergpu.cu"
page, MatchInfo *
# 1343 "mummergpu.cu"
h_matches, unsigned
# 1344 "mummergpu.cu"
numMatches, Alignment *
# 1345 "mummergpu.cu"
alignments, unsigned
# 1346 "mummergpu.cu"
numAlignments)
# 1347 "mummergpu.cu"
{
# 1349 "mummergpu.cu"
MatchInfo *d_matches;
# 1350 "mummergpu.cu"
size_t matchesSize = (numMatches * sizeof(MatchInfo));
# 1351 "mummergpu.cu"
do { cudaMalloc((void **)(&d_matches), matchesSize); ++num_bind_tex_calls; } while (0);
# 1353 "mummergpu.cu"
Alignment *d_alignments;
# 1354 "mummergpu.cu"
size_t alignmentSize = (numAlignments * sizeof(Alignment));
# 1355 "mummergpu.cu"
do { cudaMalloc((void **)(&d_alignments), alignmentSize); ++num_bind_tex_calls; } while (0);
# 1356 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemset((void *)d_alignments, 0, alignmentSize); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 1356, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1358 "mummergpu.cu"
char *atimer = createTimer();
# 1359 "mummergpu.cu"
startTimer(atimer);
# 1361 "mummergpu.cu"
fprintf(stderr, "prepared %d matches %d alignments\n", numMatches, numAlignments);
# 1362 "mummergpu.cu"
fprintf(stderr, "Copying %d bytes to host memory for %d alignments\n", numAlignments * sizeof(Alignment), numAlignments);
# 1364 "mummergpu.cu"
int DEBUG = 0;
# 1365 "mummergpu.cu"
if (DEBUG)
# 1366 "mummergpu.cu"
{
# 1367 "mummergpu.cu"
for (int i = 0; i < numMatches; i++)
# 1368 "mummergpu.cu"
{
# 1369 "mummergpu.cu"
printf("m[%d]:\t%d\t%d\t%d\t%d\t%d\t%d\n", i, (h_matches[i]).resultsoffset, (h_matches[i]).queryid, ((h_matches[i]).matchnode).data, (h_matches[i]).numLeaves, (h_matches[i]).edgematch, (h_matches[i]).qrystartpos);
# 1377 "mummergpu.cu"
}
# 1379 "mummergpu.cu"
exit(0);
# 1380 "mummergpu.cu"
}
# 1382 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy(d_matches, h_matches, matchesSize, cudaMemcpyHostToDevice); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 1382, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1383 "mummergpu.cu"
stopTimer(atimer);
# 1384 "mummergpu.cu"
float mtime = getTimerValue(atimer);
# 1387 "mummergpu.cu"
int blocksize = ((numMatches > (256)) ? (256) : numMatches);
# 1389 "mummergpu.cu"
dim3 dimBlock(blocksize, 1, 1);
# 1390 "mummergpu.cu"
dim3 dimGrid(ceil(numMatches / ((float)256)), 1, 1);
# 1392 "mummergpu.cu"
fprintf(stderr, "  Calling print kernel... ");
# 1394 "mummergpu.cu"
cudaConfigureCall(dimGrid, dimBlock, 0) ? ((void)0) : printKernel__entry(d_matches, numMatches, d_alignments, (ctx->queries)->d_tex_array, (ctx->queries)->d_addrs_tex_array, (ctx->queries)->d_lengths_array, page->begin, page->end, page->shadow_left, page->shadow_right, ctx->min_match_length);
# 1429 "mummergpu.cu"
cudaThreadSynchronize();
# 1433 "mummergpu.cu"
cudaError_t err = cudaGetLastError();
# 1434 "mummergpu.cu"
if ((cudaSuccess) != err)
# 1435 "mummergpu.cu"
{
# 1436 "mummergpu.cu"
fprintf(stderr, "Kernel execution failed: %s.\n", cudaGetErrorString(err));
# 1438 "mummergpu.cu"
exit(1);
# 1439 "mummergpu.cu"
}
# 1441 "mummergpu.cu"
startTimer(atimer);
# 1443 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMemcpy((void *)alignments, (void *)d_alignments, alignmentSize, cudaMemcpyDeviceToHost); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 1446, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1447 "mummergpu.cu"
cudaThreadSynchronize();
# 1448 "mummergpu.cu"
stopTimer(atimer);
# 1450 "mummergpu.cu"
float atime = getTimerValue(atimer);
# 1451 "mummergpu.cu"
fprintf(stderr, "memcpy time= %f\n", atime + mtime);
# 1452 "mummergpu.cu"
deleteTimer(atimer);
# 1454 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(d_alignments); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 1454, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1455 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(d_matches); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 1455, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 1456 "mummergpu.cu"
}
# 1459 "mummergpu.cu"
void runPrintOnCPU(MatchContext *ctx, ReferencePage *page, MatchInfo *
# 1460 "mummergpu.cu"
h_matches, unsigned
# 1461 "mummergpu.cu"
numMatches, Alignment *
# 1462 "mummergpu.cu"
alignments, unsigned
# 1463 "mummergpu.cu"
numAlignments)
# 1464 "mummergpu.cu"
{
# 1465 "mummergpu.cu"
unsigned min_match_length = (ctx->min_match_length);
# 1467 "mummergpu.cu"
int *addrs = ((ctx->queries)->h_addrs_tex_array);
# 1468 "mummergpu.cu"
int *lengths = ((ctx->queries)->h_lengths_array);
# 1469 "mummergpu.cu"
char *qrychars = ((ctx->queries)->h_tex_array);
# 1471 "mummergpu.cu"
if (!(numMatches)) {
# 1472 "mummergpu.cu"
return; }
# 1474 "mummergpu.cu"
int qry = (-1);
# 1475 "mummergpu.cu"
unsigned qrylen;
# 1477 "mummergpu.cu"
for (int i = 0; i < numMatches; ++i)
# 1478 "mummergpu.cu"
{
# 1479 "mummergpu.cu"
MatchInfo &match = (h_matches[i]);
# 1480 "mummergpu.cu"
if ((match.queryid) != qry)
# 1481 "mummergpu.cu"
{
# 1482 "mummergpu.cu"
qry = (match.queryid);
# 1483 "mummergpu.cu"
qrylen = (lengths[qry]);
# 1484 "mummergpu.cu"
}
# 1485 "mummergpu.cu"
if (!((match.edgematch) & 32768))
# 1486 "mummergpu.cu"
{
# 1487 "mummergpu.cu"
printAlignments(page, alignments + (match.resultsoffset), qrychars + (addrs[qry]), qrylen, match.matchnode, match.qrystartpos, match.edgematch, min_match_length, 0, ctx->forwardcoordinates);
# 1501 "mummergpu.cu"
}
# 1502 "mummergpu.cu"
}
# 1503 "mummergpu.cu"
}
# 1505 "mummergpu.cu"
int addMatchToBuffer(int, int, int);
# 1507 "mummergpu.cu"
void getExactAlignments(MatchContext *ctx, ReferencePage *page, bool on_cpu)
# 1508 "mummergpu.cu"
{
# 1509 "mummergpu.cu"
((!(ctx->reverse)) && (!(ctx->forwardreverse))) ? (static_cast< void>(0)) : __assert_fail("!ctx->reverse && !ctx->forwardreverse", "mummergpu.cu", 1509, __PRETTY_FUNCTION__);
# 1511 "mummergpu.cu"
unsigned boardFreeMemory;
# 1512 "mummergpu.cu"
unsigned total_mem;
# 1514 "mummergpu.cu"
if (!on_cpu)
# 1515 "mummergpu.cu"
{
# 1516 "mummergpu.cu"
boardMemory(&boardFreeMemory, &total_mem);
# 1517 "mummergpu.cu"
fprintf(stderr, "board free memory: %u total memory: %u\n", boardFreeMemory, total_mem);
# 1519 "mummergpu.cu"
} else
# 1521 "mummergpu.cu"
{
# 1522 "mummergpu.cu"
boardFreeMemory = ((256 * 1024) * 1024);
# 1523 "mummergpu.cu"
total_mem = boardFreeMemory;
# 1524 "mummergpu.cu"
}
# 1530 "mummergpu.cu"
boardFreeMemory -= ((16 * 1024) * 1024);
# 1531 "mummergpu.cu"
fprintf(stderr, "board free memory: %u\n", boardFreeMemory);
# 1533 "mummergpu.cu"
int rTotalMatches = 0;
# 1534 "mummergpu.cu"
int rTotalAlignments = 0;
# 1535 "mummergpu.cu"
int totalRounds = 0;
# 1536 "mummergpu.cu"
unsigned last_coord = ((ctx->results).numCoords);
# 1537 "mummergpu.cu"
unsigned next_coord = (0);
# 1538 "mummergpu.cu"
unsigned nextqry = (0);
# 1539 "mummergpu.cu"
unsigned nextqrychar = (0);
# 1540 "mummergpu.cu"
int lastqry = (-1);
# 1541 "mummergpu.cu"
while (next_coord < last_coord) {
# 1542 "mummergpu.cu"
{
# 1544 "mummergpu.cu"
totalRounds++;
# 1546 "mummergpu.cu"
unsigned numMatches = (0);
# 1547 "mummergpu.cu"
unsigned numAlignments = (0);
# 1548 "mummergpu.cu"
MatchInfo *h_matches = (__null);
# 1549 "mummergpu.cu"
Alignment *h_alignments = (__null);
# 1550 "mummergpu.cu"
int coord_left = (next_coord);
# 1551 "mummergpu.cu"
char *btimer = createTimer();
# 1552 "mummergpu.cu"
startTimer(btimer);
# 1553 "mummergpu.cu"
coordsToPrintBuffers(ctx, page, &h_matches, &h_alignments, boardFreeMemory, &next_coord, &numMatches, &numAlignments, &nextqry, &nextqrychar);
# 1555 "mummergpu.cu"
stopTimer(btimer);
# 1557 "mummergpu.cu"
float btime = getTimerValue(btimer);
# 1558 "mummergpu.cu"
((ctx->statistics).t_coords_to_buffers) += btime;
# 1559 "mummergpu.cu"
fprintf(stderr, "buffer prep time= %f\n", btime);
# 1560 "mummergpu.cu"
deleteTimer(btimer);
# 1562 "mummergpu.cu"
fprintf(stderr, "Round %d: Printing results for match coords [%d-%d) of %d using %d matches and %d alignments\n", totalRounds, coord_left, next_coord, last_coord, numMatches, numAlignments);
# 1565 "mummergpu.cu"
if (numMatches == (0)) {
# 1566 "mummergpu.cu"
continue; }
# 1568 "mummergpu.cu"
char buf[256];
# 1571 "mummergpu.cu"
rTotalAlignments += numAlignments;
# 1572 "mummergpu.cu"
rTotalMatches += numMatches;
# 1574 "mummergpu.cu"
if (num_bind_tex_calls > (100))
# 1575 "mummergpu.cu"
{
# 1576 "mummergpu.cu"
cudaThreadExit();
# 1577 "mummergpu.cu"
num_bind_tex_calls = (0);
# 1578 "mummergpu.cu"
loadReference(ctx);
# 1579 "mummergpu.cu"
loadQueries(ctx);
# 1580 "mummergpu.cu"
}
# 1582 "mummergpu.cu"
char *ktimer = createTimer();
# 1583 "mummergpu.cu"
startTimer(ktimer);
# 1584 "mummergpu.cu"
if (on_cpu)
# 1585 "mummergpu.cu"
{
# 1586 "mummergpu.cu"
runPrintOnCPU(ctx, page, h_matches, numMatches, h_alignments, numAlignments);
# 1588 "mummergpu.cu"
} else
# 1590 "mummergpu.cu"
{
# 1591 "mummergpu.cu"
runPrintKernel(ctx, page, h_matches, numMatches, h_alignments, numAlignments);
# 1593 "mummergpu.cu"
}
# 1594 "mummergpu.cu"
stopTimer(ktimer);
# 1596 "mummergpu.cu"
float ktime = getTimerValue(ktimer);
# 1597 "mummergpu.cu"
((ctx->statistics).t_print_kernel) += ktime;
# 1598 "mummergpu.cu"
fprintf(stderr, "print kernel time= %f\n", ktime);
# 1599 "mummergpu.cu"
deleteTimer(ktimer);
# 1619 "mummergpu.cu"
char *otimer = createTimer();
# 1620 "mummergpu.cu"
startTimer(otimer);
# 1622 "mummergpu.cu"
for (int m = 0; m < numMatches; m++)
# 1623 "mummergpu.cu"
{
# 1624 "mummergpu.cu"
int base = ((h_matches[m]).resultsoffset);
# 1625 "mummergpu.cu"
for (int i = 0; i < ((h_matches[m]).numLeaves); i++)
# 1626 "mummergpu.cu"
{
# 1628 "mummergpu.cu"
if (((h_alignments[base + i]).left_in_ref) == 0)
# 1629 "mummergpu.cu"
{
# 1630 "mummergpu.cu"
break;
# 1631 "mummergpu.cu"
}
# 1633 "mummergpu.cu"
if (((h_matches[m]).queryid) != lastqry)
# 1634 "mummergpu.cu"
{
# 1635 "mummergpu.cu"
lastqry = ((h_matches[m]).queryid);
# 1636 "mummergpu.cu"
addToBuffer((char *)("> "));
# 1637 "mummergpu.cu"
addToBuffer(*(((ctx->queries)->h_names) + lastqry));
# 1638 "mummergpu.cu"
addToBuffer((char *)("\n"));
# 1639 "mummergpu.cu"
}
# 1641 "mummergpu.cu"
sprintf(buf, "%d\t%d\t%d\n", (h_alignments[base + i]).left_in_ref, ((h_matches[m]).qrystartpos) + 1, (h_alignments[base + i]).matchlen);
# 1645 "mummergpu.cu"
addToBuffer(buf);
# 1651 "mummergpu.cu"
}
# 1652 "mummergpu.cu"
}
# 1655 "mummergpu.cu"
flushOutput();
# 1657 "mummergpu.cu"
stopTimer(otimer);
# 1658 "mummergpu.cu"
((ctx->statistics).t_results_to_disk) += getTimerValue(otimer);
# 1659 "mummergpu.cu"
deleteTimer(otimer);
# 1661 "mummergpu.cu"
free(h_matches);
# 1662 "mummergpu.cu"
free(h_alignments);
# 1665 "mummergpu.cu"
} }
# 1666 "mummergpu.cu"
free((ctx->results).h_coord_tex_array);
# 1667 "mummergpu.cu"
free((ctx->results).h_match_coords);
# 1668 "mummergpu.cu"
((ctx->results).h_coord_tex_array) = (__null);
# 1669 "mummergpu.cu"
((ctx->results).h_match_coords) = (__null);
# 1671 "mummergpu.cu"
fprintf(stderr, "Finished processing %d matches and %d potential alignments in %d rounds\n", rTotalMatches, rTotalAlignments, totalRounds);
# 1673 "mummergpu.cu"
}
# 1675 "mummergpu.cu"
int getQueryBlock(MatchContext *ctx, size_t device_mem_avail)
# 1676 "mummergpu.cu"
{
# 1677 "mummergpu.cu"
QuerySet *queries = (ctx->queries);
# 1678 "mummergpu.cu"
char *queryTex = (__null);
# 1679 "mummergpu.cu"
int *queryAddrs = (__null);
# 1680 "mummergpu.cu"
int *queryLengths = (__null);
# 1681 "mummergpu.cu"
unsigned numQueries;
# 1682 "mummergpu.cu"
unsigned num_match_coords;
# 1683 "mummergpu.cu"
size_t queryLen;
# 1684 "mummergpu.cu"
char **names;
# 1686 "mummergpu.cu"
fprintf(stderr, "Loading query block... ");
# 1688 "mummergpu.cu"
char *queryreadtimer = createTimer();
# 1689 "mummergpu.cu"
startTimer(queryreadtimer);
# 1691 "mummergpu.cu"
getQueriesTexture(queries->qfile, &queryTex, &queryLen, &queryAddrs, &names, &queryLengths, &numQueries, &num_match_coords, device_mem_avail, ctx->min_match_length, (ctx->reverse) || (ctx->forwardreverse));
# 1703 "mummergpu.cu"
stopTimer(queryreadtimer);
# 1704 "mummergpu.cu"
((ctx->statistics).t_queries_from_disk) += getTimerValue(queryreadtimer);
# 1705 "mummergpu.cu"
deleteTimer(queryreadtimer);
# 1707 "mummergpu.cu"
(queries->h_tex_array) = queryTex;
# 1708 "mummergpu.cu"
(queries->count) = numQueries;
# 1709 "mummergpu.cu"
(queries->h_addrs_tex_array) = queryAddrs;
# 1710 "mummergpu.cu"
(queries->texlen) = queryLen;
# 1711 "mummergpu.cu"
(queries->h_names) = names;
# 1712 "mummergpu.cu"
(queries->h_lengths_array) = queryLengths;
# 1714 "mummergpu.cu"
((ctx->results).numCoords) = num_match_coords;
# 1716 "mummergpu.cu"
fprintf(stderr, "done.\n");
# 1718 "mummergpu.cu"
return numQueries;
# 1719 "mummergpu.cu"
}
# 1721 "mummergpu.cu"
void destroyQueryBlock(QuerySet *queries)
# 1722 "mummergpu.cu"
{
# 1723 "mummergpu.cu"
free(queries->h_tex_array);
# 1724 "mummergpu.cu"
(queries->h_tex_array) = (__null);
# 1726 "mummergpu.cu"
for (int i = 0; i < (queries->count); ++i) {
# 1727 "mummergpu.cu"
free((queries->h_names)[i]); }
# 1729 "mummergpu.cu"
free(queries->h_names);
# 1731 "mummergpu.cu"
(queries->count) = (0);
# 1732 "mummergpu.cu"
(queries->texlen) = (0);
# 1734 "mummergpu.cu"
free(queries->h_addrs_tex_array);
# 1735 "mummergpu.cu"
(queries->h_addrs_tex_array) = (__null);
# 1737 "mummergpu.cu"
free(queries->h_lengths_array);
# 1738 "mummergpu.cu"
(queries->h_lengths_array) = (__null);
# 1739 "mummergpu.cu"
}
# 1741 "mummergpu.cu"
void resetStats(Statistics *stats)
# 1742 "mummergpu.cu"
{
# 1743 "mummergpu.cu"
(stats->t_end_to_end) = ((0.0));
# 1744 "mummergpu.cu"
(stats->t_match_kernel) = ((0.0));
# 1745 "mummergpu.cu"
(stats->t_print_kernel) = ((0.0));
# 1746 "mummergpu.cu"
(stats->t_queries_to_board) = ((0.0));
# 1747 "mummergpu.cu"
(stats->t_match_coords_to_board) = ((0.0));
# 1748 "mummergpu.cu"
(stats->t_match_coords_from_board) = ((0.0));
# 1749 "mummergpu.cu"
(stats->t_tree_to_board) = ((0.0));
# 1750 "mummergpu.cu"
(stats->t_ref_str_to_board) = ((0.0));
# 1751 "mummergpu.cu"
(stats->t_queries_from_disk) = ((0.0));
# 1752 "mummergpu.cu"
(stats->t_ref_from_disk) = ((0.0));
# 1753 "mummergpu.cu"
(stats->t_results_to_disk) = ((0.0));
# 1754 "mummergpu.cu"
(stats->t_tree_construction) = ((0.0));
# 1755 "mummergpu.cu"
(stats->t_tree_reorder) = ((0.0));
# 1756 "mummergpu.cu"
(stats->t_tree_flatten) = ((0.0));
# 1757 "mummergpu.cu"
(stats->t_reorder_ref_str) = ((0.0));
# 1758 "mummergpu.cu"
(stats->t_build_coord_offsets) = ((0.0));
# 1759 "mummergpu.cu"
(stats->t_coords_to_buffers) = ((0.0));
# 1760 "mummergpu.cu"
(stats->bp_avg_query_length) = ((0.0));
# 1777 "mummergpu.cu"
}
# 1779 "mummergpu.cu"
void writeStatisticsFile(Statistics *stats, char *
# 1780 "mummergpu.cu"
stats_filename, char *
# 1781 "mummergpu.cu"
node_hist_filename = 0, char *
# 1782 "mummergpu.cu"
child_hist_filename = 0)
# 1783 "mummergpu.cu"
{
# 1784 "mummergpu.cu"
if (stats_filename)
# 1785 "mummergpu.cu"
{
# 1786 "mummergpu.cu"
FILE *f = fopen(stats_filename, "w");
# 1788 "mummergpu.cu"
if (!(f))
# 1789 "mummergpu.cu"
{
# 1790 "mummergpu.cu"
fprintf(stderr, "WARNING: could not open %s for writing\n", stats_filename);
# 1791 "mummergpu.cu"
} else
# 1793 "mummergpu.cu"
{
# 1794 "mummergpu.cu"
fprintf(f, "Q");
# 1795 "mummergpu.cu"
fprintf(f, ",R");
# 1796 "mummergpu.cu"
fprintf(f, ",T");
# 1797 "mummergpu.cu"
fprintf(f, ",m");
# 1798 "mummergpu.cu"
fprintf(f, ",r");
# 1799 "mummergpu.cu"
fprintf(f, ",t");
# 1800 "mummergpu.cu"
fprintf(f, ",n");
# 1801 "mummergpu.cu"
fprintf(f, ",Total");
# 1802 "mummergpu.cu"
fprintf(f, ",Match kernel");
# 1803 "mummergpu.cu"
fprintf(f, ",Print Kernel");
# 1804 "mummergpu.cu"
fprintf(f, ",Queries to board");
# 1805 "mummergpu.cu"
fprintf(f, ",Match coords to board");
# 1806 "mummergpu.cu"
fprintf(f, ",Match coords from board");
# 1807 "mummergpu.cu"
fprintf(f, ",Tree to board");
# 1808 "mummergpu.cu"
fprintf(f, ",Ref str to board");
# 1809 "mummergpu.cu"
fprintf(f, ",Queries from disk");
# 1810 "mummergpu.cu"
fprintf(f, ",Ref from disk");
# 1811 "mummergpu.cu"
fprintf(f, ",Output to disk");
# 1812 "mummergpu.cu"
fprintf(f, ",Tree construction");
# 1813 "mummergpu.cu"
fprintf(f, ",Tree reorder");
# 1814 "mummergpu.cu"
fprintf(f, ",Tree flatten");
# 1815 "mummergpu.cu"
fprintf(f, ",Ref reorder");
# 1816 "mummergpu.cu"
fprintf(f, ",Build coord table");
# 1817 "mummergpu.cu"
fprintf(f, ",Coords to buffers");
# 1818 "mummergpu.cu"
fprintf(f, ",Avg qry length");
# 1819 "mummergpu.cu"
fprintf(f, "\n");
# 1821 "mummergpu.cu"
fprintf(f, "%d", 0);
# 1822 "mummergpu.cu"
fprintf(f, ",%d", 0);
# 1823 "mummergpu.cu"
fprintf(f, ",%d", 1);
# 1824 "mummergpu.cu"
fprintf(f, ",%d", 0);
# 1825 "mummergpu.cu"
fprintf(f, ",%d", 0);
# 1826 "mummergpu.cu"
fprintf(f, ",%d", 1);
# 1827 "mummergpu.cu"
fprintf(f, ",%d", 1);
# 1828 "mummergpu.cu"
fprintf(f, ",%f", stats->t_end_to_end);
# 1829 "mummergpu.cu"
fprintf(f, ",%f", stats->t_match_kernel);
# 1830 "mummergpu.cu"
fprintf(f, ",%f", stats->t_print_kernel);
# 1831 "mummergpu.cu"
fprintf(f, ",%f", stats->t_queries_to_board);
# 1832 "mummergpu.cu"
fprintf(f, ",%f", stats->t_match_coords_to_board);
# 1833 "mummergpu.cu"
fprintf(f, ",%f", stats->t_match_coords_from_board);
# 1834 "mummergpu.cu"
fprintf(f, ",%f", stats->t_tree_to_board);
# 1835 "mummergpu.cu"
fprintf(f, ",%f", stats->t_ref_str_to_board);
# 1836 "mummergpu.cu"
fprintf(f, ",%f", stats->t_queries_from_disk);
# 1837 "mummergpu.cu"
fprintf(f, ",%f", stats->t_ref_from_disk);
# 1838 "mummergpu.cu"
fprintf(f, ",%f", stats->t_results_to_disk);
# 1839 "mummergpu.cu"
fprintf(f, ",%f", stats->t_tree_construction);
# 1840 "mummergpu.cu"
fprintf(f, ",%f", stats->t_tree_reorder);
# 1841 "mummergpu.cu"
fprintf(f, ",%f", stats->t_tree_flatten);
# 1842 "mummergpu.cu"
fprintf(f, ",%f", stats->t_reorder_ref_str);
# 1843 "mummergpu.cu"
fprintf(f, ",%f", stats->t_build_coord_offsets);
# 1844 "mummergpu.cu"
fprintf(f, ",%f", stats->t_coords_to_buffers);
# 1845 "mummergpu.cu"
fprintf(f, ",%f", stats->bp_avg_query_length);
# 1846 "mummergpu.cu"
fprintf(f, "\n");
# 1848 "mummergpu.cu"
fclose(f);
# 1849 "mummergpu.cu"
}
# 1850 "mummergpu.cu"
}
# 1903 "mummergpu.cu"
}
# 1905 "mummergpu.cu"
void matchOnCPU(MatchContext *ctx, bool doRC)
# 1906 "mummergpu.cu"
{
# 1908 "mummergpu.cu"
if (doRC) {
# 1910 "mummergpu.cu"
computeGold(&(ctx->results), (ctx->ref)->str, (ctx->queries)->h_tex_array, (ctx->queries)->h_addrs_tex_array, (ctx->queries)->h_lengths_array, (PixelOfNode *)((ctx->ref)->h_node_tex_array), (PixelOfChildren *)((ctx->ref)->h_children_tex_array), (ctx->queries)->count, ctx->min_match_length, 32768);
# 1920 "mummergpu.cu"
} else
# 1921 "mummergpu.cu"
{
# 1922 "mummergpu.cu"
computeGold(&(ctx->results), (ctx->ref)->str, (ctx->queries)->h_tex_array, (ctx->queries)->h_addrs_tex_array, (ctx->queries)->h_lengths_array, (PixelOfNode *)((ctx->ref)->h_node_tex_array), (PixelOfChildren *)((ctx->ref)->h_children_tex_array), (ctx->queries)->count, ctx->min_match_length, 0);
# 1932 "mummergpu.cu"
}
# 1933 "mummergpu.cu"
}
# 1935 "mummergpu.cu"
void matchOnGPU(MatchContext *ctx, bool doRC)
# 1936 "mummergpu.cu"
{
# 1937 "mummergpu.cu"
int numQueries = ((ctx->queries)->count);
# 1938 "mummergpu.cu"
int blocksize = ((numQueries > 256) ? 256 : numQueries);
# 1940 "mummergpu.cu"
dim3 dimBlock(blocksize, 1, 1);
# 1942 "mummergpu.cu"
dim3 dimGrid(ceil(numQueries / ((float)256)), 1, 1);
# 1945 "mummergpu.cu"
if (doRC) {
# 1947 "mummergpu.cu"
cudaConfigureCall(dimGrid, dimBlock, 0) ? ((void)0) : mummergpuRCKernel__entry((ctx->results).d_match_coords, (ctx->queries)->d_tex_array, (ctx->queries)->d_addrs_tex_array, (ctx->queries)->d_lengths_array, numQueries, ctx->min_match_length);
# 1953 "mummergpu.cu"
} else
# 1954 "mummergpu.cu"
{
# 1955 "mummergpu.cu"
cudaConfigureCall(dimGrid, dimBlock, 0) ? ((void)0) : mummergpuKernel__entry((ctx->results).d_match_coords, (ctx->queries)->d_tex_array, (char *)((ctx->ref)->d_ref_array), (ctx->queries)->d_addrs_tex_array, (ctx->queries)->d_lengths_array, numQueries, ctx->min_match_length);
# 1987 "mummergpu.cu"
}
# 1990 "mummergpu.cu"
cudaError_t err = cudaGetLastError();
# 1991 "mummergpu.cu"
if ((cudaSuccess) != err) {
# 1992 "mummergpu.cu"
fprintf(stderr, "Kernel execution failed: %s.\n", cudaGetErrorString(err));
# 1994 "mummergpu.cu"
exit(1);
# 1995 "mummergpu.cu"
}
# 1996 "mummergpu.cu"
}
# 1998 "mummergpu.cu"
void getMatchResults(MatchContext *ctx, unsigned
# 1999 "mummergpu.cu"
page_num)
# 2000 "mummergpu.cu"
{
# 2001 "mummergpu.cu"
transferResultsFromDevice(ctx);
# 2002 "mummergpu.cu"
}
# 2004 "mummergpu.cu"
void matchQueryBlockToReferencePage(MatchContext *ctx, ReferencePage *
# 2005 "mummergpu.cu"
page, bool
# 2006 "mummergpu.cu"
reverse_complement)
# 2007 "mummergpu.cu"
{
# 2008 "mummergpu.cu"
char *ktimer = createTimer();
# 2010 "mummergpu.cu"
fprintf(stderr, "Memory footprint is:\n\tqueries: %d\n\tref: %d\n\tresults: %d\n", (ctx->queries)->bytes_on_board, (ctx->ref)->bytes_on_board, (ctx->results).bytes_on_board);
# 2015 "mummergpu.cu"
startTimer(ktimer);
# 2016 "mummergpu.cu"
if (ctx->on_cpu)
# 2017 "mummergpu.cu"
{
# 2018 "mummergpu.cu"
matchOnCPU(ctx, reverse_complement);
# 2019 "mummergpu.cu"
} else
# 2021 "mummergpu.cu"
{
# 2023 "mummergpu.cu"
matchOnGPU(ctx, reverse_complement);
# 2024 "mummergpu.cu"
cudaThreadSynchronize();
# 2026 "mummergpu.cu"
}
# 2027 "mummergpu.cu"
stopTimer(ktimer);
# 2029 "mummergpu.cu"
float ktime = getTimerValue(ktimer);
# 2030 "mummergpu.cu"
((ctx->statistics).t_match_kernel) += ktime;
# 2031 "mummergpu.cu"
fprintf(stderr, "match kernel time= %f\n", ktime);
# 2032 "mummergpu.cu"
deleteTimer(ktimer);
# 2034 "mummergpu.cu"
getMatchResults(ctx, page->id);
# 2035 "mummergpu.cu"
unloadResultBuffer(ctx);
# 2036 "mummergpu.cu"
}
# 2039 "mummergpu.cu"
int matchSubset(MatchContext *ctx, ReferencePage *
# 2040 "mummergpu.cu"
page)
# 2041 "mummergpu.cu"
{
# 2043 "mummergpu.cu"
loadQueries(ctx);
# 2045 "mummergpu.cu"
fprintf(stderr, "Matching queries %s - %s against ref coords %d - %d\n", ((ctx->queries)->h_names)[0], ((ctx->queries)->h_names)[((ctx->queries)->count) - (1)], page->begin, page->end);
# 2052 "mummergpu.cu"
loadResultBuffer(ctx);
# 2056 "mummergpu.cu"
matchQueryBlockToReferencePage(ctx, page, false);
# 2058 "mummergpu.cu"
if ((USE_PRINT_KERNEL) && (!(ctx->on_cpu)))
# 2059 "mummergpu.cu"
{
# 2060 "mummergpu.cu"
getExactAlignments(ctx, page, false);
# 2061 "mummergpu.cu"
} else
# 2064 "mummergpu.cu"
{
# 2065 "mummergpu.cu"
getExactAlignments(ctx, page, true);
# 2066 "mummergpu.cu"
}
# 2068 "mummergpu.cu"
flushOutput();
# 2069 "mummergpu.cu"
unloadQueries(ctx);
# 2070 "mummergpu.cu"
return 0;
# 2071 "mummergpu.cu"
}
# 2073 "mummergpu.cu"
int getFreeDeviceMemory(bool on_cpu)
# 2074 "mummergpu.cu"
{
# 2075 "mummergpu.cu"
unsigned free_mem = (0);
# 2076 "mummergpu.cu"
unsigned total_mem = (0);
# 2080 "mummergpu.cu"
int *p = (__null);
# 2081 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaMalloc((void **)(&p), sizeof(int)); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 2081, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 2082 "mummergpu.cu"
do { cuda_calls++; cudaError err = cudaFree(p); if ((cudaSuccess) != err) { fprintf(stderr, "Cuda error in file \'%s\' in line %i : %d (%s).\n", "mummergpu.cu", 2082, err, cudaGetErrorString(err)); trap_dbg(); exit(1); } } while (0);
# 2083 "mummergpu.cu"
if (!on_cpu) {
# 2085 "mummergpu.cu"
boardMemory(&free_mem, &total_mem);
# 2086 "mummergpu.cu"
fprintf(stderr, "board free memory: %u total memory: %u\n", free_mem, total_mem);
# 2088 "mummergpu.cu"
} else
# 2089 "mummergpu.cu"
{
# 2090 "mummergpu.cu"
total_mem = (free_mem = (804585472));
# 2091 "mummergpu.cu"
}
# 2093 "mummergpu.cu"
return free_mem;
# 2094 "mummergpu.cu"
}
# 2096 "mummergpu.cu"
int matchQueriesToReferencePage(MatchContext *ctx, ReferencePage *page)
# 2097 "mummergpu.cu"
{
# 2098 "mummergpu.cu"
fprintf(stderr, "Beginning reference page %p\n", page);
# 2100 "mummergpu.cu"
int free_mem = getFreeDeviceMemory(ctx->on_cpu);
# 2102 "mummergpu.cu"
int available_mem = ((free_mem - ((page->ref).bytes_on_board)) - ((16 * 1024) * 1024));
# 2103 "mummergpu.cu"
(ctx->ref) = (&(page->ref));
# 2104 "mummergpu.cu"
loadReference(ctx);
# 2106 "mummergpu.cu"
while (getQueryBlock(ctx, available_mem)) {
# 2107 "mummergpu.cu"
matchSubset(ctx, page);
# 2108 "mummergpu.cu"
((ctx->statistics).bp_avg_query_length) = ((((ctx->queries)->texlen) / ((float)((ctx->queries)->count))) - (2));
# 2110 "mummergpu.cu"
destroyQueryBlock(ctx->queries);
# 2111 "mummergpu.cu"
if (num_bind_tex_calls > (100))
# 2112 "mummergpu.cu"
{
# 2113 "mummergpu.cu"
cudaThreadExit();
# 2114 "mummergpu.cu"
num_bind_tex_calls = (0);
# 2115 "mummergpu.cu"
loadReference(ctx);
# 2116 "mummergpu.cu"
}
# 2117 "mummergpu.cu"
}
# 2119 "mummergpu.cu"
unloadReferenceString(ctx->ref);
# 2120 "mummergpu.cu"
unloadReferenceTree(ctx);
# 2121 "mummergpu.cu"
lseek((ctx->queries)->qfile, 0, 0);
# 2122 "mummergpu.cu"
return 0;
# 2123 "mummergpu.cu"
}
# 2127 "mummergpu.cu"
void initReferencePages(MatchContext *ctx, int *num_pages, ReferencePage **pages_out) {
# 2128 "mummergpu.cu"
unsigned bases_in_ref = ((ctx->full_ref_len) - (3));
# 2129 "mummergpu.cu"
unsigned page_size = (((8388608) < bases_in_ref) ? (8388608) : bases_in_ref);
# 2131 "mummergpu.cu"
unsigned num_reference_pages = (ceil((bases_in_ref + (0.0)) / page_size));
# 2132 "mummergpu.cu"
fprintf(stderr, "Stream will use %d pages for %d bases, page size = %d\n", num_reference_pages, bases_in_ref, page_size);
# 2135 "mummergpu.cu"
unsigned page_overlap = (MAX_QUERY_LEN + 1);
# 2136 "mummergpu.cu"
ReferencePage *pages = ((ReferencePage *)calloc(num_reference_pages, sizeof(ReferencePage)));
# 2139 "mummergpu.cu"
((pages[0]).begin) = 1;
# 2140 "mummergpu.cu"
((pages[0]).end) = (((((pages[0]).begin) + page_size) + ceil(page_overlap / (2.0))) + (1));
# 2143 "mummergpu.cu"
((pages[0]).shadow_left) = (-1);
# 2144 "mummergpu.cu"
((pages[0]).id) = (0);
# 2146 "mummergpu.cu"
for (int i = 1; i < (num_reference_pages - (1)); ++i) {
# 2147 "mummergpu.cu"
((pages[i]).begin) = (((pages[i - 1]).end) - page_overlap);
# 2148 "mummergpu.cu"
((pages[i]).end) = ((((pages[i]).begin) + page_size) + page_overlap);
# 2149 "mummergpu.cu"
((pages[i - 1]).shadow_right) = ((pages[i]).begin);
# 2150 "mummergpu.cu"
((pages[i]).shadow_left) = ((pages[i - 1]).end);
# 2151 "mummergpu.cu"
((pages[i]).id) = i;
# 2152 "mummergpu.cu"
}
# 2154 "mummergpu.cu"
if (num_reference_pages > (1)) {
# 2155 "mummergpu.cu"
int last_page = (num_reference_pages - (1));
# 2156 "mummergpu.cu"
((pages[last_page]).begin) = (((pages[last_page - 1]).end) - page_overlap);
# 2157 "mummergpu.cu"
((pages[last_page]).end) = ((ctx->full_ref_len) - (1));
# 2158 "mummergpu.cu"
((pages[last_page - 1]).shadow_right) = ((pages[last_page]).begin);
# 2159 "mummergpu.cu"
((pages[last_page]).shadow_right) = (-1);
# 2160 "mummergpu.cu"
((pages[last_page]).shadow_left) = ((pages[last_page - 1]).end);
# 2161 "mummergpu.cu"
((pages[last_page]).id) = last_page;
# 2162 "mummergpu.cu"
}
# 2164 "mummergpu.cu"
(*pages_out) = pages;
# 2165 "mummergpu.cu"
(*num_pages) = num_reference_pages;
# 2166 "mummergpu.cu"
}
# 2168 "mummergpu.cu"
int streamReferenceAgainstQueries(MatchContext *ctx) {
# 2169 "mummergpu.cu"
int num_reference_pages = 0;
# 2170 "mummergpu.cu"
ReferencePage *pages = (__null);
# 2171 "mummergpu.cu"
initReferencePages(ctx, &num_reference_pages, &pages);
# 2174 "mummergpu.cu"
buildReferenceTexture(&((pages[0]).ref), ctx->full_ref, (pages[0]).begin, (pages[0]).end, ctx->min_match_length, ctx->dotfilename, ctx->texfilename, &(ctx->statistics));
# 2184 "mummergpu.cu"
matchQueriesToReferencePage(ctx, &(pages[0]));
# 2185 "mummergpu.cu"
destroyReference(&((pages[0]).ref));
# 2187 "mummergpu.cu"
for (int i = 1; i < (num_reference_pages - 1); ++i) {
# 2189 "mummergpu.cu"
buildReferenceTexture(&((pages[i]).ref), ctx->full_ref, (pages[i]).begin, (pages[i]).end, ctx->min_match_length, __null, __null, &(ctx->statistics));
# 2198 "mummergpu.cu"
matchQueriesToReferencePage(ctx, &(pages[i]));
# 2199 "mummergpu.cu"
destroyReference(&((pages[i]).ref));
# 2200 "mummergpu.cu"
}
# 2202 "mummergpu.cu"
if (num_reference_pages > 1) {
# 2203 "mummergpu.cu"
int last_page = (num_reference_pages - 1);
# 2204 "mummergpu.cu"
buildReferenceTexture(&((pages[last_page]).ref), ctx->full_ref, (pages[last_page]).begin, (pages[last_page]).end, ctx->min_match_length, __null, __null, &(ctx->statistics));
# 2213 "mummergpu.cu"
matchQueriesToReferencePage(ctx, &(pages[last_page]));
# 2214 "mummergpu.cu"
destroyReference(&((pages[last_page]).ref));
# 2215 "mummergpu.cu"
}
# 2216 "mummergpu.cu"
free(pages);
# 2217 "mummergpu.cu"
return 0;
# 2218 "mummergpu.cu"
}
# 2222 "mummergpu.cu"
extern "C" int matchQueries(MatchContext *ctx) {
# 2223 "mummergpu.cu"
(sizeof(PixelOfNode) == sizeof(uint4)) ? (static_cast< void>(0)) : __assert_fail("sizeof(struct PixelOfNode) == sizeof(uint4)", "mummergpu.cu", 2223, __PRETTY_FUNCTION__);
# 2224 "mummergpu.cu"
(sizeof(PixelOfChildren) == sizeof(uint4)) ? (static_cast< void>(0)) : __assert_fail("sizeof(struct PixelOfChildren) == sizeof(uint4)", "mummergpu.cu", 2224, __PRETTY_FUNCTION__);
# 2231 "mummergpu.cu"
resetStats(&(ctx->statistics));
# 2233 "mummergpu.cu"
char *ttimer = createTimer();
# 2234 "mummergpu.cu"
startTimer(ttimer);
# 2236 "mummergpu.cu"
int ret;
# 2238 "mummergpu.cu"
fprintf(stderr, "Streaming reference pages against all queries\n");
# 2239 "mummergpu.cu"
ret = streamReferenceAgainstQueries(ctx);
# 2241 "mummergpu.cu"
stopTimer(ttimer);
# 2242 "mummergpu.cu"
((ctx->statistics).t_end_to_end) += getTimerValue(ttimer);
# 2243 "mummergpu.cu"
deleteTimer(ttimer);
# 2245 "mummergpu.cu"
writeStatisticsFile(&(ctx->statistics), ctx->stats_file, (char *)("node_hist.out"), (char *)("child_hist.out"));
# 2247 "mummergpu.cu"
return ret;
# 2248 "mummergpu.cu"
}
# 1 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_00005366_00000000-3_mummergpu.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00005366_00000000-3_mummergpu.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_10$[] = {
0x33010102464c457full,0x0000000000000000ull,0x0000000100be0002ull,0x0000000000000000ull,
0x00000000000021b8ull,0x0000000000000040ull,0x003800400000000aull,0x0001001100400007ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000300000001ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000480ull,
0x00000000000002f8ull,0x0000000000000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000030000000bull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000778ull,
0x00000000000000a7ull,0x0000000000000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x0000000200000013ull,0x0000000000000000ull,0x0000000000000000ull,0x000000000000081full,
0x0000000000000270ull,0x0000001300000002ull,0x0000000000000001ull,0x0000000000000018ull,
0x0000000100000216ull,0x0000000000000006ull,0x0000000000000000ull,0x0000000000000a8full,
0x0000000000000630ull,0x0e00000e00000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000026dull,0x0000000000000002ull,0x0000000000000000ull,0x00000000000010bfull,
0x0000000000000028ull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000029eull,0x0000000000000002ull,0x0000000000000000ull,0x00000000000010e7ull,
0x0000000000000010ull,0x0000000400000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x00000001000002ccull,0x0000000000000002ull,0x0000000000000000ull,0x00000000000010f7ull,
0x0000000000000018ull,0x0000000400000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x000000080000023full,0x0000000000000003ull,0x0000000000000000ull,0x000000000000110full,
0x0000000000000040ull,0x0000000400000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x00000001000000a1ull,0x0000000000000006ull,0x0000000000000000ull,0x000000000000110full,
0x0000000000001038ull,0x1300000800000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000158ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000002147ull,
0x0000000000000040ull,0x0000000900000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000010000019aull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000002187ull,
0x0000000000000010ull,0x0000000900000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x00000001000001d9ull,0x0000000000000002ull,0x0000000000000000ull,0x0000000000002197ull,
0x0000000000000018ull,0x0000000900000000ull,0x0000000000000001ull,0x0000000000000000ull,
0x00000008000000dbull,0x0000000000000003ull,0x0000000000000000ull,0x00000000000021afull,
0x0000000000000054ull,0x0000000900000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x000000080000011aull,0x0000000000000003ull,0x0000000000000000ull,0x00000000000021afull,
0x0000000000000020ull,0x0000000900000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000100000036ull,0x0000000000000006ull,0x0000000000000000ull,0x00000000000021afull,
0x0000000000000008ull,0x0000000600000003ull,0x0000000000000004ull,0x0000000000000000ull,
0x0000000800000069ull,0x0000000000000003ull,0x0000000000000000ull,0x00000000000021b7ull,
0x0000000000000038ull,0x0000000f00000000ull,0x0000000000000004ull,0x0000000000000000ull,
0x7472747368732e00ull,0x747274732e006261ull,0x746d79732e006261ull,0x672e766e2e006261ull,
0x6e692e6c61626f6cull,0x672e766e2e007469ull,0x742e006c61626f6cull,0x37315a5f2e747865ull,
0x706772656d6d756dull,0x656e72654b435275ull,0x6374614d3031506cull,0x635064726f6f4368ull,
0x69695f3353694b50ull,0x6168732e766e2e00ull,0x37315a5f2e646572ull,0x706772656d6d756dull,
0x656e72654b435275ull,0x6374614d3031506cull,0x635064726f6f4368ull,0x69695f3353694b50ull,
0x5f2e747865742e00ull,0x746e69727031315aull,0x39506c656e72654bull,0x666e49686374614dull,
0x67696c413950696full,0x506350746e656d6eull,0x6969695f3553694bull,0x732e766e2e006969ull,
0x5a5f2e6465726168ull,0x4b746e6972703131ull,0x4d39506c656e7265ull,0x6f666e4968637461ull,
0x6e67696c41395069ull,0x4b506350746e656dull,0x696969695f355369ull,0x6f6c2e766e2e0069ull,
0x31315a5f2e6c6163ull,0x72654b746e697270ull,0x74614d39506c656eull,0x50696f666e496863ull,
0x656d6e67696c4139ull,0x53694b506350746eull,0x0069696969695f35ull,0x736e6f632e766e2eull,
0x5a5f2e31746e6174ull,0x4b746e6972703131ull,0x4d39506c656e7265ull,0x6f666e4968637461ull,
0x6e67696c41395069ull,0x4b506350746e656dull,0x696969695f355369ull,0x6d692e766e2e0069ull,
0x315a5f2e73656761ull,0x654b746e69727031ull,0x614d39506c656e72ull,0x696f666e49686374ull,
0x6d6e67696c413950ull,0x694b506350746e65ull,0x69696969695f3553ull,0x666e692e766e2e00ull,
0x727031315a5f2e6full,0x656e72654b746e69ull,0x686374614d39506cull,0x413950696f666e49ull,
0x746e656d6e67696cull,0x5f3553694b506350ull,0x742e006969696969ull,0x35315a5f2e747865ull,
0x706772656d6d756dull,0x506c656e72654b75ull,0x4b505f3053635076ull,0x2e0069695f325369ull,
0x65726168732e766eull,0x756d35315a5f2e64ull,0x4b75706772656d6dull,0x5076506c656e7265ull,
0x53694b505f305363ull,0x766e2e0069695f32ull,0x6e6174736e6f632eull,0x6d35315a5f2e3174ull,
0x75706772656d6d75ull,0x76506c656e72654bull,0x694b505f30536350ull,0x6e2e0069695f3253ull,
0x736567616d692e76ull,0x6d756d35315a5f2eull,0x654b75706772656dull,0x635076506c656e72ull,
0x3253694b505f3053ull,0x2e766e2e0069695full,0x315a5f2e6f666e69ull,0x6772656d6d756d35ull,
0x6c656e72654b7570ull,0x505f305363507650ull,0x0069695f3253694bull,0x78657465646f6e00ull,
0x6572646c69686300ull,0x666572007865746eull,0x7479727100786574ull,0x6d37315a5f007865ull,
0x75706772656d6d75ull,0x6c656e72654b4352ull,0x686374614d303150ull,0x50635064726f6f43ull,
0x0069695f3353694bull,0x6e69727031315a5full,0x506c656e72654b74ull,0x6e49686374614d39ull,
0x696c413950696f66ull,0x6350746e656d6e67ull,0x69695f3553694b50ull,0x35315a5f00696969ull,
0x706772656d6d756dull,0x506c656e72654b75ull,0x4b505f3053635076ull,0x000069695f325369ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000010003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000020003000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000030003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x00000f0003000000ull,0x0800000000000000ull,
0x0000000000000000ull,0x0000100003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000090003000000ull,0x3800000000000000ull,0x0000000000000010ull,0x00000d0003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x00000e0003000000ull,0x0000000000000000ull,
0x0000000000000000ull,0x00000a0003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x00000b0003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x00000c0003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000040003000000ull,0x3000000000000000ull,
0x0000000000000006ull,0x0000080003000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000050003000000ull,0x0000000000000000ull,0x0000000000000000ull,0x0000060003000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000070003000000ull,0x0000000000000000ull,
0x0100000000000000ull,0x000000001a000000ull,0x0000000000000000ull,0x0900000000000000ull,
0x000000001a000000ull,0x0000000000000000ull,0x1500000000000000ull,0x000000001a000000ull,
0x0000000000000000ull,0x1c00000000000000ull,0x000000001a000000ull,0x0000000000000000ull,
0x2300000000000000ull,0x00000f1012000000ull,0x0000000000000000ull,0x5000000000000000ull,
0x0000091012000000ull,0x0000000000000000ull,0x8400000000000000ull,0x0000041012000000ull,
0x0000000000000000ull,0x0500000000000000ull,0x0904200780a0004cull,0x0104200780a00042ull,
0x0104000780a00000ull,0xfd60000780600202ull,0x036c2107c83000ddull,0x0900000500300000ull,
0x0dc4100780300200ull,0x05000000032101feull,0x05042087802000d4ull,0x0c80c00780d00e02ull,
0x012102f800404300ull,0x0980c00780d00e00ull,0x0dc4100780300302ull,0x09c4100780300306ull,
0x01042087802000c8ull,0x15042007c03000deull,0x030400c780204004ull,0x1900000980300000ull,
0x1d042047802000ccull,0x2100000003200180ull,0x250403c7801000f8ull,0x0d0403c7801000f8ull,
0x090403c7801000f8ull,0xfd0403c7801000f8ull,0xfd6c00c7c8307c13ull,0x2564008148307c05ull,
0x0d2440c680100010ull,0x090403c6801000f8ull,0x002440c680100012ull,0x0120068000200990ull,
0x3180200780d00e00ull,0x030c0187c0a00000ull,0x0300000000400b10ull,0x0100000100100a50ull,
0x0504400780d08004ull,0x03e4100780301004ull,0x0100000000a004a0ull,0x0544004780a00000ull,
0xfd44004780a00002ull,0x346c4087c8308119ull,0x0110008410100084ull,0x0300004780f64000ull,
0xfd00000280100350ull,0x036c4087c8308219ull,0xfd000002801003b0ull,0x036c4087c8308319ull,
0xfd00000280100400ull,0x036c4087c8308419ull,0x0900000280100450ull,0x050403c7801000f8ull,
0x010403c7801000f8ull,0x030403c7801000f8ull,0x05000007801004a0ull,0x09c4100780301000ull,
0x01c4100780300800ull,0x0504400780d08500ull,0x09e4100780301802ull,0x03e4100780301804ull,
0x09000007801004a0ull,0x01c4100780301002ull,0x05e4100780301800ull,0x0904400780d08502ull,
0x03e4100780301804ull,0x01000007801004a0ull,0x09c4100780300802ull,0x0504400780d08504ull,
0x01e4100780301802ull,0x03e4100780301800ull,0x01000007801004a0ull,0x05c4100780301004ull,
0x09c4100780300804ull,0x01e4100780301804ull,0x05e4100780301800ull,0x2de4100780301802ull,
0x0904400782d08704ull,0x2d04400780d08604ull,0x09c4100780300416ull,0x05c4100780300804ull,
0x0104004780d00116ull,0x0504004780d00004ull,0x09c4100780301002ull,0x01040047c0d00100ull,
0x030403c780100004ull,0xfd000002801005e0ull,0x2d6c2187c83009dfull,0x010403c780100008ull,
0x05c4100500300310ull,0x090403c5001000f8ull,0x010400050020000aull,0x010403c50010001aull,
0x25a0800500d00e04ull,0x0d0fffffff203f92ull,0x030403c7801000f8ull,0x0500000780500000ull,
0x2904400780d08000ull,0x01e4100780301000ull,0x0544004780a00002ull,0x0144004780a00014ull,
0x3100004784f44202ull,0x2dc4100780300800ull,0x29e4100780301800ull,0x01c4100780300802ull,
0x31e4100780301818ull,0x2dc4100780300816ull,0x29c4100780301002ull,0x01e4100780301814ull,
0x2d04004780d00018ull,0x31e4100780301816ull,0x29c4100780300814ull,0x0504400780d08502ull,
0x2de4100780301802ull,0x2904004780d00b18ull,0x05c4100780301014ull,0x29c4100780301002ull,
0x2d04004780d00014ull,0xfd04004780d00b02ull,0x036c0087c8307c07ull,0x0500000000a00850ull,
0x030403c780100014ull,0x0100000280100830ull,0x3100000003200196ull,0x350400c780200014ull,
0x01ac000780300c00ull,0x3104028780204016ull,0x3100000003200180ull,0x01ac000780300c06ull,
0x0104000780204006ull,0x250fffffff203f80ull,0x0d04030780200012ull,0x038c000780307c00ull,
0x2500000780100850ull,0x3500000003200192ull,0x0100000003200194ull,0x0104024782200010ull,
0x0104018780200000ull,0x3180200780d00e00ull,0xfd0c018780a00000ull,0x03640047d8300d17ull,
0xfd00000000a00a10ull,0x036c0147c8307c19ull,0x0300001280100a10ull,0x0100000100100a10ull,
0x01042347802000d0ull,0x0180200780d00e00ull,0xfd0c018780a00000ull,0x036c0087c8300019ull,
0x2d00000280100950ull,0x030403c780100008ull,0x2500000780100a70ull,0x0000000003200192ull,
0x0120068000200892ull,0x3580200780d00e00ull,0xfd0000000320019aull,0x31640047c8300d17ull,
0x030c018780a00000ull,0x0100000280100a00ull,0xfd6c0147d0307c18ull,0x030c0147c8a00001ull,
0x03000012801008e0ull,0xfd00000780100a10ull,0x016c0147c8307c19ull,0x03e0000002f00000ull,
0x2d00000280100220ull,0x030403c780100008ull,0x1000000780100a70ull,0x3510009404100096ull,
0xfd0403c7801000f8ull,0x016c2187c83009dfull,0x050400478020401aull,0x0dc4100500300310ull,
0x050403c500100000ull,0x090400450020000aull,0x05a0800500d00e02ull,0x2504024780300000ull,
0x0d0fffffff203f82ull,0x030403c780100000ull,0x0100000780500000ull,0x0504400780d08008ull,
0x01e4100780301008ull,0x0544004780a00000ull,0x0144004780a00002ull,0x0900000780f64202ull,
0x09c4100780301002ull,0x11e4100780301804ull,0x0504400780d08704ull,0x0904400780d08502ull,
0x3104400780d08604ull,0x11c4100780300408ull,0x01e4100780301800ull,0x05c4100780300804ull,
0x2104004780d00118ull,0x0100000003200190ull,0x0504004780d00400ull,0xfdc4100780301002ull,
0x096c0147c830080full,0x0304004780d00100ull,0x0100000280100180ull,0xffe0000001f00000ull,
0x43000000410000ffull,0x5400000047000000ull,0x0f000000ff000000ull,0x01000000f0000000ull,
0x1300010000000000ull,0x1400000001000000ull,0x0400000000000000ull,0x0100000013000802ull,
0x1400080204000000ull,0x0500000000000000ull,0x0904200780a0004cull,0x0104200780a00042ull,
0x0104000780a00000ull,0xfd60000780600202ull,0x036c2107c83000cdull,0x0500000500300000ull,
0x01c4100780300400ull,0x00c4100780300200ull,0x012100e828200082ull,0x0100000003200494ull,
0x0580c00780d00e00ull,0x0900000003200894ull,0x0580c00780d00e02ull,0x01c4100780300200ull,
0x0d00000003201294ull,0x0180400780d00e00ull,0x05042047802000d8ull,0x0180c00780d00e00ull,
0x1104400780d08004ull,0x01e4100780301004ull,0x2544004780a00000ull,0x05042047802000d4ull,
0x0d44004780a00008ull,0x010400c780200012ull,0x0d00008780f24000ull,0x1180200780d00e06ull,
0x11c4100780301002ull,0x19e4100780301808ull,0x15c4100780300802ull,0x1104400780d08102ull,
0x19c4100780300808ull,0x11e410078030180cull,0x1504004780d00508ull,0x01c410078030100cull,
0x1160c00780d00000ull,0x0504004780d00508ull,0xfd60c00780d00018ull,0x036c2187c83004e9ull,
0x1400000000a004a0ull,0x2d10008418100084ull,0x030c018780a0000cull,0x05000002801004a0ull,
0x05c4100780300800ull,0x09e4100780301802ull,0x0dc4100780301000ull,0x0904400780d08302ull,
0x05e4100780301804ull,0x0d04400780d08202ull,0x11c4100780300406ull,0x0104400780d08100ull,
0x05c4100780300802ull,0x0104004780d00206ull,0x0504004780d00400ull,0x09c4100780301002ull,
0x190403c78010000cull,0x0104004780d00100ull,0x0504400780d0800cull,0x01e410078030100cull,
0x0544004780a00000ull,0x0144004780a00002ull,0x0d00008780f24000ull,0x0dc4100780301002ull,
0x1de4100780301806ull,0x11c4100780300802ull,0x0d04400780d08102ull,0x1dc4100780300806ull,
0x0de410078030180eull,0x1104004780d00406ull,0x0dc410078030100eull,0x0104004780d00406ull,
0xfd60c00780d00000ull,0x056c2047c83003e9ull,0x0360c00780d00018ull,0x01000002801002a0ull,
0x0504400782d08004ull,0x01e4100780301004ull,0x0544004780a00000ull,0x0144004780a00002ull,
0x3100008784f24000ull,0x0d80c00780d00e14ull,0x0dc4100780301002ull,0x1de4100780301806ull,
0x11c4100780300802ull,0x0d04400780d08102ull,0x1dc4100780300806ull,0x01e410078030180eull,
0x0160c00780d00000ull,0x0d04004780d00406ull,0x05c410078030100eull,0x0160c00780d00018ull,
0xfd04004780d00300ull,0x03640147c8300505ull,0x1d00000000a007b0ull,0x110403c780100004ull,
0x030fffffff203f80ull,0x01000002801007a0ull,0x0d00000003201094ull,0x0380400780d00e00ull,
0xfd00000000a00770ull,0x03640087c8307c07ull,0x0100000280100770ull,0x0504400780d0800cull,
0x01e410078030100cull,0x0544004780a00000ull,0x0144004780a00002ull,0x1100008784f24000ull,
0x11c4100780301002ull,0x35e4100780301808ull,0x21c4100780300802ull,0x1104400780d08102ull,
0x35c4100780300808ull,0x11e410078030181aull,0x2104004780d00808ull,0x11c410078030101aull,
0x0104004780d00808ull,0x0160c00780d00000ull,0x0504010780200006ull,0x1160c00780d00018ull,
0x010fffffff203f80ull,0x21e0000002f00000ull,0x0300000003100180ull,0x21000007801007b0ull,
0xfd0403c7801000f8ull,0x03640087ca300605ull,0x3900000280300000ull,0x350403c7801000f8ull,
0x0100000007100180ull,0x0504400780d0800eull,0x09e410078030100eull,0x3d44004780a00000ull,
0x0044004780a00002ull,0x0110009e04100084ull,0x0d00008784f24202ull,0x450403c7801000f8ull,
0x416c014780307c1cull,0x05ec1007c0301802ull,0x0d2c014780a00022ull,0xfd2440c280100008ull,
0x03040047c8d00107ull,0x0500000000a02040ull,0x030403c780100006ull,0x0d00000100101260ull,
0x0d6c014780301016ull,0xfd2c014780a00006ull,0x03040007c8d00303ull,0x0300000000a00b20ull,
0x0500000100100b20ull,0x05c4100780301000ull,0x0de4100780301802ull,0x39c4100780300800ull,
0x0504400780d08100ull,0x01c4100780300802ull,0x05e4100780301806ull,0x0104004780d00e02ull,
0x01c4100780301000ull,0x0104004780d00100ull,0x05042007802000e0ull,0xfd0fffffff203f80ull,
0x036c2147c83001e1ull,0xfd00000280100a20ull,0x036c6147c83085e5ull,0x0100000280100b20ull,
0x0104010780200000ull,0xfd0fffffff203f80ull,0x036c2147c83000e3ull,0xfd00000280100a80ull,
0x036c6147c83085e7ull,0xfd00000280100b20ull,0xfd6c20c7c83000e5ull,0x036c2181483001e1ull,
0x0100000100100b20ull,0x0dc4100780300318ull,0x05042007802000d0ull,0x01a0c00780d00e06ull,
0x050003c780100010ull,0x0100000003200486ull,0x31a0400780d00e02ull,0x0100000003200198ull,
0x0de0000002f00000ull,0x090403c78010001eull,0x0100008780f24000ull,0x01c4100780300804ull,
0x05e4100780301800ull,0x39c4100780301004ull,0x0504400780d08300ull,0x01e4100780301802ull,
0x3904400780d08200ull,0x3dc410078030041cull,0x0104400780d08104ull,0x05c4100780300800ull,
0x0104004780d0011cull,0x0504004780d00f00ull,0x3dc4100780301002ull,0x0504004780d00100ull,
0x0104400780d0801eull,0x39e410078030101eull,0x4144004780a00002ull,0x0944004780a00000ull,
0x0060c00780d00000ull,0x0d1000a00410009cull,0x0160c00780d00018ull,0x0d00004784f64202ull,
0x0dc4100780300800ull,0x45e4100780301806ull,0x4904400780d08206ull,0x4504400780d08100ull,
0x45c4100780300822ull,0x4904004780d01222ull,0x0dc4100780301000ull,0x4904400780d08306ull,
0x0de4100780301824ull,0x0dc4100780300406ull,0x0d04004780d01206ull,0x0dc4100780301006ull,
0xfd04004780d00322ull,0x03640147c830030full,0x0c00000000a01110ull,0x0310009c08100084ull,
0x3900000280100de0ull,0x350403c7801000f8ull,0x0300000007100380ull,0x3900000780101110ull,
0x39c4100780301002ull,0x45e410078030181cull,0x4904400780d0821cull,0x01e4100780301800ull,
0x01c4100780300822ull,0x3904004780d01200ull,0x4504400780d0831cull,0x3904400780d08102ull,
0x39c410078030041cull,0x3904004780d0111cull,0x01c410078030101cull,0xfd04004780d00e00ull,
0x03640147c830000full,0x3900000280100ef0ull,0x350403c7801000f8ull,0x0300000007100780ull,
0x3900000780101110ull,0x4504400780d08106ull,0x01c4100780300802ull,0x4504400780d0821cull,
0x01e4100780301822ull,0x01c4100780300800ull,0x3904004780d01100ull,0x4504400780d0831cull,
0x05e4100780301802ull,0x05c410078030041cull,0x0504004780d01102ull,0x01c4100780301002ull,
0xfd04004780d00100ull,0x03640147c830000full,0x3900000280101000ull,0x350403c7801000f8ull,
0x0300000007101480ull,0x0100000780101110ull,0x45e4100780301806ull,0x39c4100780300806ull,
0x0504400780d08300ull,0x01c4100780301006ull,0x4504400780d08200ull,0x0de4100780301822ull,
0x05c410078030041cull,0x01e4100780301802ull,0x0dc4100780300800ull,0x0104004780d01106ull,
0x0504004780d00100ull,0x01c4100780301006ull,0xfd04004780d00100ull,0x39640147c830000full,
0x350403c5001000f8ull,0x392440c50010001eull,0xfd2440c280100008ull,0x016c0147ca307c11ull,
0x010fffffff203f90ull,0xfd0403c500100010ull,0x1c6c0147c8307c01ull,0x031000802010009eull,
0x0400000280102040ull,0x01100084001000a0ull,0x0900008784f24000ull,0x09c4100780301002ull,
0x11e4100780301804ull,0x0dc4100780300802ull,0x0904400780d08102ull,0x11c4100780300804ull,
0x09e4100780301808ull,0x0d04004780d00304ull,0x01c4100780301008ull,0x0160c00780d00000ull,
0x0504004780d00304ull,0x1160c00780d00018ull,0x030fffffff203f80ull,0x0100000780102040ull,
0xfd6c0087d0307c10ull,0x030c0147c8a00001ull,0x0400000000a01380ull,0x011000840010009eull,
0x010000c780f64202ull,0x3d60c00780d00020ull,0x050403c780100004ull,0x0960c00780d00028ull,
0x030403c780100002ull,0x0500001100101370ull,0x0500000003201294ull,0x0480400780d00e02ull,
0x0520098204200188ull,0x0500000003200182ull,0x4180200780d00e02ull,0x030c018780a00004ull,
0x4100000780101380ull,0xfd0403c7801000f8ull,0x036c4147da30861bull,0x0300000000a01bf0ull,
0xfd00001280101570ull,0x03044007d8d08701ull,0x0900001100101560ull,0x0d40800780d00020ull,
0x050fffffff101880ull,0xfd0fffffff100880ull,0xfd044207e8210007ull,0x1d044207d8210003ull,
0x0504400780d08100ull,0x3d0403c7801000f8ull,0x010fffffff101080ull,0x050403c7801000f8ull,
0xfdc4102980300804ull,0x0d044207e821001full,0x010403c7801000f8ull,0x0de4101980301802ull,
0x05c4102980301004ull,0x090403c7801000f8ull,0x3d04400780d08200ull,0x0504400780d08300ull,
0x01e4101980301806ull,0x09c4100780300804ull,0x05c410078030041eull,0x0104004780d00202ull,
0x0504004780d00700ull,0x1dc4100780301002ull,0x0304004780d00100ull,0x3500000780101bf0ull,
0xfd00000007100380ull,0x036c4147d830891bull,0x0100001280101770ull,0x4540800780d00020ull,
0xfd04400780d08a00ull,0x45640087d8307c23ull,0xfd04400780d08002ull,0x03640092d8307c23ull,
0x1d00001280101760ull,0x0dc4100780301002ull,0x3d0fffffff103080ull,0x05e4100780301000ull,
0xfd0fffffff100880ull,0x0d044207e8210007ull,0xfd04004780d00f0eull,0x05044207d8210003ull,
0x0d0403c7801000f8ull,0x050403e9801000f8ull,0x0de4101980301806ull,0x1d0403c780100002ull,
0x0504400780d08306ull,0x3d0403c7801000f8ull,0x1d04400780d08104ull,0x09c410078030040eull,
0x0504400780d08206ull,0x0de4101980301800ull,0x0104004780d00f0eull,0x01c4100780300804ull,
0x0504004780d00002ull,0x1dc4100780301006ull,0x0304004780d00100ull,0x3500000780101bf0ull,
0xfd00000007100780ull,0x036c4147d8308b1bull,0x0100001280101990ull,0x0940800780d00020ull,
0x4500000003102080ull,0xfd04400780d0811eull,0x09044307e8210005ull,0xfd0403c7801000f8ull,
0x09640147d8307c23ull,0x09e4102980301002ull,0xfd04400780d08004ull,0x0364015158307c05ull,
0x1d00001100101980ull,0x09e4100780301800ull,0x0d0fffffff103880ull,0x01c4100780300802ull,
0xfd0fffffff100880ull,0x0d044207e8210005ull,0xfd04004780d00706ull,0x01044207d8210001ull,
0x090403c7801000f8ull,0x0d0403c7801000f8ull,0x1d0403e9801000f8ull,0x0904400780d08322ull,
0x01e4101980301802ull,0x05e4101980301806ull,0x0d04400780d08222ull,0x09c410078030040eull,
0x0504004780d00304ull,0x01c4100780300802ull,0x0504004780d00100ull,0x1dc4100780301004ull,
0x0304004780d00100ull,0x3500000780101bf0ull,0xfd00000007101480ull,0x036c4147d8308d1bull,
0xfd00001280101ac0ull,0x03044007d8d08e1full,0x0100001100101ab0ull,0x0de410078030181eull,
0x09c410078030081eull,0x0504400780d08300ull,0x01c410078030101eull,0x0d04400780d08200ull,
0x09e4100780301806ull,0x05c4100780300404ull,0x01e4100780301802ull,0x09c4100780300800ull,
0x0104004780d00304ull,0x0504004780d00100ull,0x1dc4100780301004ull,0x0304004780d00100ull,
0x3500000780101bf0ull,0xfd00000003102480ull,0x036c4147d8308f1bull,0xfd00001280101be0ull,
0x03044007d8d08707ull,0x0100001100101be0ull,0x01c4100780300806ull,0x09e4100780301800ull,
0x05c4100780301006ull,0x1d04400780d08300ull,0x01e4100780301804ull,0x0904400780d08200ull,
0x05c4100780300402ull,0x0104400780d08106ull,0x09c4100780300800ull,0x0104004780d00704ull,
0x0504004780d00100ull,0x1dc4100780301004ull,0x0304004780d00100ull,0x3900000780101bf0ull,
0xfd00000003100180ull,0x036c0147da307c1dull,0x0300001280102040ull,0x0300000000a02020ull,
0xfd00000100102010ull,0x036c0147c8300d21ull,0x0100000280101ff0ull,0x0504400780d0800eull,
0x01e410078030100eull,0x0544004780a00000ull,0x0144004780a00002ull,0x0900008780f24000ull,
0x09c4100780301002ull,0x11e4100780301804ull,0x0dc4100780300802ull,0x0904400780d08102ull,
0x11c4100780300804ull,0x09e4100780301808ull,0x0d04004780d00304ull,0x01c4100780301008ull,
0x0960c00780d00000ull,0xfd04004780d00304ull,0x05640147c830070bull,0x1160c00780d00018ull,
0x030fffffff203f84ull,0x0500000280102020ull,0x0900000003201094ull,0x0380400780d00e02ull,
0xfd00000000a01fc0ull,0x03640087c8307c05ull,0x0500000280101fc0ull,0x05c4100780300800ull,
0x0de4100780301802ull,0x11c4100780301000ull,0x0d04400780d08302ull,0x05e4100780301806ull,
0x1104400780d08202ull,0x21c4100780300408ull,0x0104400780d08100ull,0x05c4100780300802ull,
0x0104004780d00308ull,0x0504004780d00800ull,0x01c4100780301002ull,0x0504004780d00100ull,
0x0d04400780d08000ull,0x01e4100780301000ull,0x0544004780a00002ull,0x0144004780a00006ull,
0x0d00008784f24000ull,0x0dc4100780301002ull,0x21e4100780301806ull,0x11c4100780300802ull,
0x0d04400780d08102ull,0x21c4100780300806ull,0x0de4100780301810ull,0x1104004780d00406ull,
0x0dc4100780301010ull,0x0104004780d00406ull,0x0160c00780d00000ull,0x050400c780200004ull,
0x1160c00780d00018ull,0x010fffffff203f80ull,0x21e0000002f00000ull,0x0300000003100180ull,
0x2100000780102020ull,0x0300000003100180ull,0x2100000780102020ull,0x0100000003200190ull,
0x35e0000002f00000ull,0xfd00000007100180ull,0x03640147ca30060full,0x01000002801007f0ull,
0xffe0000001f00000ull,0x0f000000ff0000ffull,0x01000000f0000000ull,0x41ffffffff000000ull,
0x2000ffffff000000ull,0x0000000043000000ull,0xd000000047ff0000ull,0x0000000054ffffffull,
0x1300000024ffffffull,0x1400000000000000ull,0x0400000001000000ull,0x0000000013000802ull,
0x1400080204000000ull,0x0100000001000000ull,0x00e0000001f00000ull,0x0000000500000006ull,
0x00000000000021b8ull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000188ull,
0x0000000000000188ull,0x0000000000000004ull,0x0000190560000000ull,0x0000000000000a8full,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000680ull,0x0000000000000680ull,
0x0000000000000004ull,0x0000190660000000ull,0x000000000000110full,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000040ull,0x0000000000000004ull,
0x0000180560000000ull,0x000000000000110full,0x0000000000000000ull,0x0000000000000000ull,
0x00000000000010a0ull,0x00000000000010a0ull,0x0000000000000004ull,0x0000180660000000ull,
0x00000000000021afull,0x0000000000000000ull,0x0000000000000000ull,0x0000000000000000ull,
0x0000000000000074ull,0x0000000000000004ull,0x0000170560000000ull,0x00000000000021afull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000008ull,0x0000000000000008ull,
0x0000000000000004ull,0x0000170660000000ull,0x00000000000021b7ull,0x0000000000000000ull,
0x0000000000000000ull,0x0000000000000000ull,0x0000000000000038ull,0x0000000000000004ull,
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
0x30305f3636333530ull,0x372d303030303030ull,0x6772656d6d756d5full,0x2e337070632e7570ull,
0x2f706d742f282069ull,0x69512e2349426363ull,0x2f090a2949783934ull,0x2d2d2d2d2d2d2d2full,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2f090a0a2d2d2d2dull,0x2d2d2d2d2d2d2d2full,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2f2f090a2d2d2d2dull,0x736e6f6974704f20ull,
0x2d2d2d2f2f090a3aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x615420202f2f090aull,0x7874703a74656772ull,0x6d733a415349202cull,0x646e45202c30315full,
0x7474696c3a6e6169ull,0x6e696f50202c656cull,0x657a695320726574ull,0x202f2f090a34363aull,
0x704f2809334f2d20ull,0x6974617a696d6974ull,0x6c6576656c206e6full,0x2d20202f2f090a29ull,
0x7562654428093067ull,0x296c6576656c2067ull,0x6d2d20202f2f090aull,0x726f706552280932ull,
0x6f73697664612074ull,0x2f090a2973656972ull,0x2d2d2d2d2d2d2d2full,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2e090a0a2d2d2d2dull,0x22093109656c6966ull,0x646e616d6d6f633cull,
0x0a223e656e696c2dull,0x3209656c69662e09ull,0x742f706d742f2209ull,0x30305f746678706dull,
0x305f363633353030ull,0x2d30303030303030ull,0x72656d6d756d5f36ull,0x616475632e757067ull,
0x227570672e326566ull,0x09656c69662e090aull,0x6f6d6d6f63220933ull,0x2e090a2275632e6eull,
0x22093409656c6966ull,0x706772656d6d756dull,0x662e090a22682e75ull,0x6d22093509656c69ull,
0x75706772656d6d75ull,0x2e6c656e72656b5full,0x69662e090a227563ull,0x752f22093609656cull,
0x672f62696c2f7273ull,0x365f3638782f6363ull,0x2d78756e696c2d34ull,0x2e342e342f756e67ull,
0x64756c636e692f31ull,0x6665646474732f65ull,0x69662e090a22682eull,0x682f22093709656cull,
0x6d726f6e2f656d6full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x632f6564756c636eull,
0x63697665642f7472ull,0x6d69746e75725f65ull,0x662e090a22682e65ull,0x2f22093809656c69ull,
0x726f6e2f656d6f68ull,0x616475632f6c616dull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x6665645f74736f68ull,0x0a22682e73656e69ull,0x3909656c69662e09ull,0x2f656d6f682f2209ull,
0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x746c6975622f6564ull,
0x73657079745f6e69ull,0x69662e090a22682eull,0x2f2209303109656cull,0x726f6e2f656d6f68ull,
0x616475632f6c616dull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x745f656369766564ull,
0x0a22682e73657079ull,0x3109656c69662e09ull,0x656d6f682f220931ull,0x2f6c616d726f6e2full,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x766972642f656475ull,0x73657079745f7265ull,
0x69662e090a22682eull,0x2f2209323109656cull,0x726f6e2f656d6f68ull,0x616475632f6c616dull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x5f65636166727573ull,0x22682e7365707974ull,
0x09656c69662e090aull,0x6d6f682f22093331ull,0x6c616d726f6e2f65ull,0x69622f616475632full,
0x636e692f2e2e2f6eull,0x7865742f6564756cull,0x7079745f65727574ull,0x2e090a22682e7365ull,
0x09343109656c6966ull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,
0x64756c636e692f2eull,0x726f746365762f65ull,0x682e73657079745full,0x656c69662e090a22ull,
0x6f682f2209353109ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x65642f6564756c63ull,0x75616c5f65636976ull,0x617261705f68636eull,0x682e73726574656dull,
0x656c69662e090a22ull,0x6f682f2209363109ull,0x616d726f6e2f656dull,0x622f616475632f6cull,
0x6e692f2e2e2f6e69ull,0x72632f6564756c63ull,0x6761726f74732f74ull,0x2e7373616c635f65ull,
0x6c69662e090a2268ull,0x752f220937310965ull,0x756c636e692f7273ull,0x2f737469622f6564ull,
0x22682e7365707974ull,0x09656c69662e090aull,0x7273752f22093831ull,0x6564756c636e692full,
0x22682e656d69742full,0x09656c69662e090aull,0x6d6f682f22093931ull,0x6c616d726f6e2f65ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x6d6f632f6564756cull,0x636e75665f6e6f6dull,
0x22682e736e6f6974ull,0x09656c69662e090aull,0x6d6f682f22093032ull,0x6c616d726f6e2f65ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x7472632f6564756cull,0x616d5f636e75662full,
0x090a22682e6f7263ull,0x313209656c69662eull,0x2f656d6f682f2209ull,0x632f6c616d726f6eull,
0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x5f6874616d2f6564ull,0x6e6f6974636e7566ull,
0x662e090a22682e73ull,0x2209323209656c69ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x5f6563697665642full,0x6e6f6974636e7566ull,
0x662e090a22682e73ull,0x2209333209656c69ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x6f635f6874616d2full,0x2e73746e6174736eull,
0x6c69662e090a2268ull,0x682f220934320965ull,0x6d726f6e2f656d6full,0x2f616475632f6c61ull,
0x692f2e2e2f6e6962ull,0x732f6564756c636eull,0x6f74615f31315f6dull,0x636e75665f63696dull,
0x22682e736e6f6974ull,0x09656c69662e090aull,0x6d6f682f22093532ull,0x6c616d726f6e2f65ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x5f6d732f6564756cull,0x696d6f74615f3231ull,
0x6974636e75665f63ull,0x090a22682e736e6full,0x363209656c69662eull,0x2f656d6f682f2209ull,
0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x33315f6d732f6564ull,
0x5f656c62756f645full,0x6e6f6974636e7566ull,0x662e090a22682e73ull,0x2209373209656c69ull,
0x6f6e2f656d6f682full,0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,0x6564756c636e692full,
0x5f6e6f6d6d6f632full,0x22682e7365707974ull,0x09656c69662e090aull,0x6d6f682f22093832ull,
0x6c616d726f6e2f65ull,0x69622f616475632full,0x636e692f2e2e2f6eull,0x5f6d732f6564756cull,
0x696d6f74615f3032ull,0x6974636e75665f63ull,0x090a22682e736e6full,0x393209656c69662eull,
0x2f656d6f682f2209ull,0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,
0x30325f6d732f6564ull,0x736e6972746e695full,0x090a22682e736369ull,0x303309656c69662eull,
0x2f656d6f682f2209ull,0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,
0x61667275732f6564ull,0x74636e75665f6563ull,0x0a22682e736e6f69ull,0x3309656c69662e09ull,
0x656d6f682f220931ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x747865742f656475ull,0x637465665f657275ull,0x6974636e75665f68ull,0x090a22682e736e6full,
0x323309656c69662eull,0x2f656d6f682f2209ull,0x632f6c616d726f6eull,0x2f6e69622f616475ull,
0x756c636e692f2e2eull,0x5f6874616d2f6564ull,0x6e6f6974636e7566ull,0x74705f6c62645f73ull,
0x090a0a22682e3178ull,0x36752e207865742eull,0x657465646f6e2034ull,0x7865742e090a3b78ull,
0x6863203436752e20ull,0x65746e6572646c69ull,0x7865742e090a3b78ull,0x6572203436752e20ull,
0x2e090a3b78657466ull,0x3436752e20786574ull,0x3b78657479727120ull,0x72746e652e090a0aull,
0x756d35315a5f2079ull,0x4b75706772656d6dull,0x5076506c656e7265ull,0x53694b505f305363ull,
0x090a282069695f32ull,0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,
0x6d6d756d35315a5full,0x72654b7570677265ull,0x53635076506c656eull,0x5f3253694b505f30ull,
0x686374616d5f6969ull,0x2c7364726f6f635full,0x617261702e09090aull,0x5f203436752e206dull,
0x726170616475635full,0x756d35315a5f5f6dull,0x4b75706772656d6dull,0x5076506c656e7265ull,
0x53694b505f305363ull,0x765f5f5f69695f32ull,0x6d617261705f6c61ull,0x2c73656972657571ull,
0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,0x756d35315a5f5f6dull,
0x4b75706772656d6dull,0x5076506c656e7265ull,0x53694b505f305363ull,0x6665725f69695f32ull,
0x7261702e09090a2cull,0x203436752e206d61ull,0x6170616475635f5full,0x6d35315a5f5f6d72ull,
0x75706772656d6d75ull,0x76506c656e72654bull,0x694b505f30536350ull,0x75715f69695f3253ull,
0x7372646441797265ull,0x7261702e09090a2cull,0x203436752e206d61ull,0x6170616475635f5full,
0x6d35315a5f5f6d72ull,0x75706772656d6d75ull,0x76506c656e72654bull,0x694b505f30536350ull,
0x75715f69695f3253ull,0x74676e654c797265ull,0x702e09090a2c7368ull,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x6772656d6d756d35ull,0x6c656e72654b7570ull,
0x505f305363507650ull,0x5f69695f3253694bull,0x69726575516d756eull,0x702e09090a2c7365ull,
0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x6772656d6d756d35ull,
0x6c656e72654b7570ull,0x505f305363507650ull,0x5f69695f3253694bull,0x6374616d5f6e696dull,
0x090a296e656c5f68ull,0x206765722e090a7bull,0x3c7225203233752eull,0x2e090a3b3e333431ull,
0x3436752e20676572ull,0x3e32333c64722520ull,0x206765722e090a3bull,0x3c6625203233662eull,
0x722e090a3b3e3431ull,0x646572702e206765ull,0x3b3e32323c702520ull,0x3509636f6c2e090aull,
0x240a300935303709ull,0x315a5f5f3142424cull,0x6772656d6d756d35ull,0x6c656e72654b7570ull,
0x505f305363507650ull,0x3a69695f3253694bull,0x33752e747663090aull,0x2509203631752e32ull,
0x61746325202c3172ull,0x63090a3b782e6469ull,0x752e3233752e7476ull,0x2c32722509203631ull,
0x782e6469746e2520ull,0x34326c756d090a3bull,0x203233752e6f6c2eull,0x7225202c33722509ull,
0x0a3b327225202c31ull,0x3233752e74766309ull,0x722509203631752eull,0x2e64697425202c34ull,
0x2e646461090a3b78ull,0x3572250920323375ull,0x25202c347225202cull,0x2e646c090a3b3372ull,
0x33732e6d61726170ull,0x202c367225092032ull,0x70616475635f5f5bull,0x35315a5f5f6d7261ull,
0x706772656d6d756dull,0x506c656e72654b75ull,0x4b505f3053635076ull,0x6e5f69695f325369ull,
0x6569726575516d75ull,0x746573090a3b5d73ull,0x3233732e74672e70ull,0x25202c3170250920ull,
0x3b357225202c3672ull,0x622031702540090aull,0x5f744c2409206172ull,0x3b30393431335f30ull,
0x6e752e617262090aull,0x3442424c24092069ull,0x756d35315a5f5f37ull,0x4b75706772656d6dull,
0x5076506c656e7265ull,0x53694b505f305363ull,0x4c240a3b69695f32ull,0x393431335f305f74ull,
0x636f6c2e090a3a30ull,0x3009313237093509ull,0x36752e747663090aull,0x2509203233732e34ull,
0x357225202c316472ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x647225202c326472ull,
0x6c090a3b34202c31ull,0x2e6d617261702e64ull,0x6472250920343675ull,0x75635f5f5b202c33ull,
0x5f5f6d7261706164ull,0x656d6d756d35315aull,0x6e72654b75706772ull,0x3053635076506c65ull,
0x695f3253694b505full,0x4c79726575715f69ull,0x3b5d736874676e65ull,0x36752e646461090aull,
0x2c34647225092034ull,0x25202c3364722520ull,0x646c090a3b326472ull,0x2e6c61626f6c672eull,
0x3772250920323373ull,0x2b346472255b202cull,0x6f6c2e090a3b5d30ull,0x0932323709350963ull,
0x61702e646c090a30ull,0x203436752e6d6172ull,0x5b202c3564722509ull,0x6170616475635f5full,
0x6d35315a5f5f6d72ull,0x75706772656d6d75ull,0x76506c656e72654bull,0x694b505f30536350ull,
0x75715f69695f3253ull,0x7372646441797265ull,0x2e646461090a3b5dull,0x6472250920343675ull,
0x2c35647225202c36ull,0x090a3b3264722520ull,0x61626f6c672e646cull,0x2509203233732e6cull,
0x6472255b202c3872ull,0x2e090a3b5d302b36ull,0x3337093509636f6cull,0x747663090a300931ull,
0x3233732e3436752eull,0x202c376472250920ull,0x646c090a3b387225ull,0x732e6d617261702eull,
0x2c39722509203233ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x6772656d6d756d35ull,
0x6c656e72654b7570ull,0x505f305363507650ull,0x5f69695f3253694bull,0x6374616d5f6e696dull,
0x0a3b5d6e656c5f68ull,0x617261702e646c09ull,0x2509203436752e6dull,0x5f5f5b202c386472ull,
0x6d72617061647563ull,0x6d756d35315a5f5full,0x654b75706772656dull,0x635076506c656e72ull,
0x3253694b505f3053ull,0x6374616d5f69695full,0x7364726f6f635f68ull,0x2e6c756d090a3b5dull,
0x09203436752e6f6cull,0x7225202c39647225ull,0x090a3b38202c3764ull,0x203436752e646461ull,
0x202c303164722509ull,0x7225202c38647225ull,0x646461090a3b3964ull,0x722509203233752eull,
0x2c397225202c3031ull,0x6c756d090a3b3120ull,0x33752e6f6c2e3432ull,0x2c31317225092032ull,
0x7225202c35722520ull,0x747663090a3b3031ull,0x3233752e3436752eull,0x2c31316472250920ull,
0x090a3b3131722520ull,0x752e6f6c2e6c756dull,0x3164722509203436ull,0x3131647225202c32ull,
0x7573090a3b38202cull,0x2509203436752e62ull,0x7225202c33316472ull,0x647225202c303164ull,
0x627573090a3b3231ull,0x722509203233732eull,0x2c377225202c3231ull,0x6d090a3b39722520ull,
0x09203233752e766full,0x3b30202c33317225ull,0x6c2e70746573090aull,0x2509203233732e74ull,
0x32317225202c3270ull,0x0a3b33317225202cull,0x7262203270254009ull,0x3442424c24092061ull,
0x756d35315a5f5f37ull,0x4b75706772656d6dull,0x5076506c656e7265ull,0x53694b505f305363ull,
0x6c090a3b69695f32ull,0x2e6d617261702e64ull,0x6472250920343675ull,0x635f5f5b202c3431ull,
0x5f6d726170616475ull,0x6d6d756d35315a5full,0x72654b7570677265ull,0x53635076506c656eull,
0x5f3253694b505f30ull,0x6c61765f5f5f6969ull,0x75716d617261705full,0x0a3b5d7365697265ull,
0x3436752e64646109ull,0x2c35316472250920ull,0x202c343164722520ull,0x61090a3b37647225ull,
0x09203233732e6464ull,0x7225202c34317225ull,0x090a3b31202c3231ull,0x203233732e766f6dull,
0x25202c3531722509ull,0x6f6d090a3b343172ull,0x2509203233732e76ull,0x0a3b30202c363172ull,
0x3233732e766f6d09ull,0x202c373172250920ull,0x2e766f6d090a3b30ull,0x3172250920323373ull,
0x6d090a3b30202c38ull,0x09203233752e766full,0x3b30202c39317225ull,0x33732e766f6d090aull,
0x2c30327225092032ull,0x240a3b3531722520ull,0x3532335f305f744cull,0x3c2f2f200a3a3431ull,
0x6f4c203e706f6f6cull,0x2079646f6220706full,0x31333720656e696cull,0x6e697473656e202cull,
0x3a68747065642067ull,0x69747365202c3120ull,0x746920646574616dull,0x736e6f6974617265ull,
0x776f6e6b6e75203aull,0x732e766f6d090a6eull,0x3132722509203233ull,0x6573090a3b30202cull,
0x3233752e656c2e74ull,0x722509203233732eull,0x37317225202c3232ull,0x0a3b31327225202cull,
0x3233732e67656e09ull,0x202c333272250920ull,0x6d090a3b32327225ull,0x09203233752e766full,
0x3b30202c34327225ull,0x71652e746573090aull,0x3233752e3233752eull,0x202c353272250920ull,
0x7225202c39317225ull,0x67656e090a3b3432ull,0x722509203233732eull,0x35327225202c3632ull,
0x33622e726f090a3bull,0x2c37327225092032ull,0x25202c3332722520ull,0x6f6d090a3b363272ull,
0x2509203233752e76ull,0x0a3b30202c383272ull,0x71652e7074657309ull,0x702509203233732eull,
0x2c37327225202c33ull,0x090a3b3832722520ull,0x6172622033702540ull,0x5f305f744c240920ull,
0x200a3b3037373233ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c313337ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x6d090a3431353233ull,0x09203233732e766full,0x3b31202c37317225ull,0x33732e766f6d090aull,
0x2c38317225092032ull,0x766f6d090a3b3020ull,0x722509203233752eull,0x33353536202c3931ull,
0x305f744c240a3b36ull,0x0a3a30373732335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c31333720ull,0x6c6562616c206461ull,
0x305f744c24206465ull,0x090a34313532335full,0x37093509636f6c2eull,0x6461090a30093335ull,
0x2509203233732e64ull,0x317225202c393272ull,0x3b37317225202c36ull,0x36752e747663090aull,
0x2509203233732e34ull,0x7225202c36316472ull,0x646461090a3b3932ull,0x722509203436732eull,
0x647225202c373164ull,0x31647225202c3631ull,0x672e646c090a3b35ull,0x38732e6c61626f6cull,
0x202c303372250920ull,0x302b37316472255bull,0x2e766f6d090a3b5dull,0x3372250920323375ull,
0x73090a3b30202c31ull,0x732e71652e707465ull,0x2c34702509203233ull,0x25202c3033722520ull,
0x2540090a3b313372ull,0x0920617262203470ull,0x37335f305f744c24ull,0x744c240a3b383733ull,
0x34393733335f305full,0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,
0x090a34363720656eull,0x37093509636f6c2eull,0x6f6d090a30093436ull,0x2509203233732e76ull,
0x317225202c323372ull,0x2e646e61090a3b39ull,0x3372250920323362ull,0x2c32337225202c33ull,
0x0a3b353335353620ull,0x2e6e722e74766309ull,0x203233752e323366ull,0x7225202c31662509ull,
0x726873090a3b3333ull,0x722509203233752eull,0x32337225202c3433ull,0x63090a3b3631202cull,
0x33662e6e722e7476ull,0x2509203233752e32ull,0x34337225202c3266ull,0x662e766f6d090a3bull,
0x2c33662509203233ull,0x3030303030663020ull,0x202020203b303030ull,0x090a30202f2f0920ull,
0x203233662e766f6dull,0x6630202c34662509ull,0x3030303030303030ull,0x2f0920202020203bull,
0x786574090a30202full,0x752e34762e64322eull,0x7b203233662e3233ull,0x3372252c35337225ull,
0x252c373372252c36ull,0x68635b2c7d383372ull,0x65746e6572646c69ull,0x252c3166257b2c78ull,
0x252c3366252c3266ull,0x2f200a3b5d7d3466ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3720656e696c2079ull,0x64616568202c3436ull,0x64656c6562616c20ull,
0x335f305f744c2420ull,0x6c2e090a34393733ull,0x383134093509636full,0x2e766f6d090a3009ull,
0x3372250920323373ull,0x3b35337225202c39ull,0x33732e766f6d090aull,0x2c30347225092032ull,
0x090a3b3633722520ull,0x203233732e766f6dull,0x25202c3134722509ull,0x6c2e090a3b373372ull,
0x353637093509636full,0x2e766f6d090a3009ull,0x3472250920323373ull,0x3b32337225202c32ull,
0x3509636f6c2e090aull,0x090a300937363709ull,0x203233752e766f6dull,0x36202c3334722509ull,
0x70746573090a3b35ull,0x203233732e71652eull,0x7225202c35702509ull,0x33347225202c3033ull,
0x2035702540090a3bull,0x744c240920617262ull,0x0a3b3835325f305full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c34363720ull,
0x6c6562616c206461ull,0x305f744c24206465ull,0x090a34393733335full,0x203233752e766f6dull,
0x36202c3434722509ull,0x70746573090a3b37ull,0x203233732e71652eull,0x7225202c36702509ull,
0x34347225202c3033ull,0x2036702540090a3bull,0x744c240920617262ull,0x0a3b3037375f305full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c34363720ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x090a34393733335full,
0x203233752e766f6dull,0x37202c3534722509ull,0x70746573090a3b31ull,0x203233732e71652eull,
0x7225202c37702509ull,0x35347225202c3033ull,0x2037702540090a3bull,0x744c240920617262ull,
0x3b363230315f305full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3436372065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a34393733335f30ull,0x3233752e766f6d09ull,0x202c363472250920ull,0x746573090a3b3438ull,
0x3233732e71652e70ull,0x25202c3870250920ull,0x347225202c303372ull,0x38702540090a3b36ull,
0x4c24092061726220ull,0x323832315f305f74ull,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c34363720656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34393733335f305full,0x6e752e617262090aull,0x305f744c24092069ull,
0x240a3b383335315full,0x3835325f305f744cull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c34363720656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34393733335f305full,0x3509636f6c2e090aull,0x090a300939363709ull,
0x203233622e6c6873ull,0x25202c3734722509ull,0x3b3432202c393372ull,0x33752e726873090aull,
0x2c38347225092032ull,0x32202c3734722520ull,0x2e6c6873090a3b34ull,0x3472250920323362ull,
0x2c39337225202c39ull,0x6873090a3b363120ull,0x2509203233752e72ull,0x347225202c303572ull,
0x090a3b3432202c39ull,0x203233622e6c6873ull,0x25202c3135722509ull,0x0a3b38202c393372ull,
0x3233752e72687309ull,0x202c323572250920ull,0x3432202c31357225ull,0x752e617262090a3bull,
0x5f744c240920696eull,0x240a3b3431355f30ull,0x3037375f305f744cull,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c34363720656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34393733335f305full,0x3509636f6c2e090aull,
0x090a300930373709ull,0x203233752e766f6dull,0x25202c3335722509ull,0x6873090a3b393372ull,
0x2509203233752e72ull,0x357225202c383472ull,0x090a3b3432202c33ull,0x203233622e6c6873ull,
0x25202c3435722509ull,0x3b3432202c303472ull,0x33752e726873090aull,0x2c30357225092032ull,
0x32202c3435722520ull,0x2e6c6873090a3b34ull,0x3572250920323362ull,0x2c30347225202c35ull,
0x6873090a3b363120ull,0x2509203233752e72ull,0x357225202c323572ull,0x090a3b3432202c35ull,
0x20696e752e617262ull,0x355f305f744c2409ull,0x5f744c240a3b3431ull,0x0a3a363230315f30ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c34363720ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x090a34393733335full,
0x37093509636f6c2eull,0x6873090a30093137ull,0x2509203233622e6cull,0x347225202c363572ull,
0x73090a3b38202c30ull,0x09203233752e7268ull,0x7225202c38347225ull,0x0a3b3432202c3635ull,
0x3233752e766f6d09ull,0x202c373572250920ull,0x73090a3b30347225ull,0x09203233752e7268ull,
0x7225202c30357225ull,0x0a3b3432202c3735ull,0x3233622e6c687309ull,0x202c383572250920ull,
0x3432202c31347225ull,0x752e726873090a3bull,0x3235722509203233ull,0x202c38357225202cull,
0x617262090a3b3432ull,0x4c240920696e752eull,0x3b3431355f305f74ull,0x315f305f744c240aull,
0x2f2f200a3a323832ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x363720656e696c20ull,0x2064616568202c34ull,0x2064656c6562616cull,0x33335f305f744c24ull,
0x6f6c2e090a343937ull,0x0932373709350963ull,0x622e6c6873090a30ull,0x3935722509203233ull,
0x202c31347225202cull,0x726873090a3b3631ull,0x722509203233752eull,0x39357225202c3834ull,
0x73090a3b3432202cull,0x09203233622e6c68ull,0x7225202c30367225ull,0x090a3b38202c3134ull,
0x203233752e726873ull,0x25202c3035722509ull,0x3b3432202c303672ull,0x33752e766f6d090aull,
0x2c31367225092032ull,0x090a3b3134722520ull,0x203233752e726873ull,0x25202c3235722509ull,
0x3b3432202c313672ull,0x6e752e617262090aull,0x305f744c24092069ull,0x4c240a3b3431355full,
0x383335315f305f74ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c34363720656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34393733335f305full,0x3509636f6c2e090aull,0x090a300933373709ull,0x203233752e766f6dull,
0x30202c3235722509ull,0x752e766f6d090a3bull,0x3035722509203233ull,0x6f6d090a3b30202cull,
0x2509203233752e76ull,0x0a3b30202c383472ull,0x31355f305f744c24ull,0x6c3c2f2f200a3a34ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c34363720656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x393733335f305f74ull,0x09636f6c2e090a34ull,
0x0a30093639320935ull,0x3233622e646e6109ull,0x202c323672250920ull,0x3531202c32357225ull,
0x622e646e61090a3bull,0x3336722509203233ull,0x202c32357225202cull,0x6873090a3b303432ull,
0x2509203233622e6cull,0x367225202c343672ull,0x73090a3b38202c32ull,0x09203233622e6c68ull,
0x7225202c35367225ull,0x090a3b34202c3336ull,0x09203233622e726full,0x7225202c36367225ull,
0x38347225202c3436ull,0x33622e726f090a3bull,0x2c37367225092032ull,0x25202c3536722520ull,
0x6873090a3b303572ull,0x2509203233622e6cull,0x367225202c383672ull,0x090a3b3631202c37ull,
0x09203233622e726full,0x7225202c39367225ull,0x38367225202c3636ull,0x732e766f6d090a3bull,
0x3931722509203233ull,0x0a3b39367225202cull,0x093509636f6c2e09ull,0x6d090a3009363737ull,
0x09203233752e766full,0x3b30202c30377225ull,0x6e2e70746573090aull,0x2509203233752e65ull,
0x39367225202c3970ull,0x0a3b30377225202cull,0x7262203970254009ull,0x305f744c24092061ull,
0x0a3b30353034335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c31333720ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x090a34313532335full,0x37093509636f6c2eull,0x6f6d090a30093338ull,0x2509203233732e76ull,
0x347225202c313772ull,0x636f6c2e090a3b32ull,0x3009313337093509ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5f5f5b202c397225ull,0x6d72617061647563ull,0x6d756d35315a5f5full,
0x654b75706772656dull,0x635076506c656e72ull,0x3253694b505f3053ull,0x5f6e696d5f69695full,
0x656c5f686374616dull,0x6f6c2e090a3b5d6eull,0x0933383709350963ull,0x2e70746573090a30ull,
0x09203233732e6567ull,0x7225202c30317025ull,0x3b37317225202c39ull,0x203031702540090aull,
0x744c240920617262ull,0x32363534335f305full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c31333720656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34313532335f305full,0x3509636f6c2e090aull,0x090a300935353609ull,
0x2e3436752e747663ull,0x6472250920323373ull,0x36317225202c3831ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x7225202c39316472ull,0x0a3b38202c383164ull,0x3436752e64646109ull,
0x2c30326472250920ull,0x202c333164722520ull,0x090a3b3931647225ull,0x203233732e766f6dull,
0x30202c3237722509ull,0x6c672e7473090a3bull,0x2e32762e6c61626full,0x72255b0920323373ull,
0x202c5d302b303264ull,0x72252c323372257bull,0x744c240a3b7d3237ull,0x32363534335f305full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c31333720656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34313532335f305full,
0x3509636f6c2e090aull,0x090a300935383709ull,0x203233732e627573ull,0x25202c3731722509ull,
0x0a3b31202c373172ull,0x093509636f6c2e09ull,0x6d090a3009383837ull,0x09203233732e766full,
0x3b30202c38317225ull,0x6e752e617262090aull,0x305f744c24092069ull,0x240a3b363033325full,
0x3034335f305f744cull,0x3c2f2f200a3a3035ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x34363720656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3733335f305f744cull,0x636f6c2e090a3439ull,0x3009323937093509ull,0x33622e646e61090aull,
0x2c33377225092032ull,0x36202c3936722520ull,0x63090a3b35333535ull,0x33662e6e722e7476ull,
0x2509203233752e32ull,0x33377225202c3566ull,0x752e726873090a3bull,0x3437722509203233ull,
0x202c39367225202cull,0x747663090a3b3631ull,0x2e3233662e6e722eull,0x3666250920323375ull,
0x0a3b34377225202cull,0x3233662e766f6d09ull,0x30202c3766250920ull,0x3030303030303066ull,
0x0920202020203b30ull,0x6f6d090a30202f2full,0x2509203233662e76ull,0x30306630202c3866ull,
0x203b303030303030ull,0x202f2f0920202020ull,0x322e786574090a30ull,0x3233752e34762e64ull,
0x72257b203233662eull,0x2c363772252c3537ull,0x3772252c37377225ull,0x65646f6e5b2c7d38ull,
0x3566257b2c786574ull,0x3766252c3666252cull,0x0a3b5d7d3866252cull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c34363720ull,
0x6c6562616c206461ull,0x305f744c24206465ull,0x090a34393733335full,0x33093509636f6c2eull,
0x6f6d090a30093537ull,0x2509203233732e76ull,0x377225202c393772ull,0x2e766f6d090a3b36ull,
0x3872250920323373ull,0x3b37377225202c30ull,0x3509636f6c2e090aull,0x090a300933393709ull,
0x203233752e766f6dull,0x25202c3138722509ull,0x6873090a3b393772ull,0x2509203233752e72ull,
0x387225202c323872ull,0x090a3b3432202c31ull,0x203233622e6c6873ull,0x25202c3338722509ull,
0x0a3b38202c393772ull,0x3233752e72687309ull,0x202c343872250920ull,0x3432202c33387225ull,
0x622e6c6873090a3bull,0x3538722509203233ull,0x202c30387225202cull,0x726873090a3b3432ull,
0x722509203233752eull,0x35387225202c3638ull,0x73090a3b3432202cull,0x09203233622e6c68ull,
0x7225202c37387225ull,0x090a3b38202c3238ull,0x203233622e6c6873ull,0x25202c3838722509ull,
0x3b3631202c363872ull,0x3233622e726f090aull,0x202c393872250920ull,0x7225202c37387225ull,
0x2e726f090a3b3438ull,0x3972250920323362ull,0x2c38387225202c30ull,0x090a3b3938722520ull,
0x203233732e766f6dull,0x25202c3139722509ull,0x6f6d090a3b303972ull,0x2509203233732e76ull,
0x397225202c323972ull,0x2e6c6873090a3b31ull,0x3972250920323362ull,0x2c30387225202c33ull,
0x726873090a3b3820ull,0x722509203233752eull,0x33397225202c3439ull,0x73090a3b3432202cull,
0x09203233622e6c68ull,0x7225202c35397225ull,0x0a3b3631202c3038ull,0x3233752e72687309ull,
0x202c363972250920ull,0x3432202c35397225ull,0x752e766f6d090a3bull,0x3739722509203233ull,
0x0a3b30387225202cull,0x3233752e72687309ull,0x202c383972250920ull,0x3432202c37397225ull,
0x622e6c6873090a3bull,0x3939722509203233ull,0x202c34397225202cull,0x2e6c6873090a3b38ull,
0x3172250920323362ull,0x38397225202c3030ull,0x6f090a3b3631202cull,0x2509203233622e72ull,
0x7225202c31303172ull,0x36397225202c3939ull,0x33622e726f090a3bull,0x3230317225092032ull,
0x2c3030317225202cull,0x0a3b313031722520ull,0x3233752e766f6d09ull,0x2c33303172250920ull,
0x746573090a3b3020ull,0x3233732e71652e70ull,0x202c313170250920ull,0x7225202c38317225ull,
0x2540090a3b333031ull,0x2061726220313170ull,0x335f305f744c2409ull,0x2f200a3b30333335ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3720656e696c2079ull,
0x64616568202c3436ull,0x64656c6562616c20ull,0x335f305f744c2420ull,0x6c2e090a34393733ull,
0x333038093509636full,0x2e646461090a3009ull,0x3172250920323373ull,0x30317225202c3430ull,
0x61090a3b31202c32ull,0x09203233752e6464ull,0x25202c3530317225ull,0x317225202c303972ull,
0x2e6e696d090a3b38ull,0x3172250920323373ull,0x30317225202c3630ull,0x3530317225202c34ull,
0x09636f6c2e090a3bull,0x0a30093430380935ull,0x3233752e62757309ull,0x2c37303172250920ull,
0x202c323031722520ull,0x61090a3b30397225ull,0x09203233732e6464ull,0x25202c3830317225ull,
0x3b31202c37303172ull,0x33732e6e696d090aull,0x3930317225092032ull,0x202c38317225202cull,
0x090a3b3830317225ull,0x203233732e646461ull,0x25202c3731722509ull,0x317225202c373172ull,
0x6f6c2e090a3b3930ull,0x0935303809350963ull,0x732e627573090a30ull,0x3131722509203233ull,
0x2c38317225202c30ull,0x0a3b373031722520ull,0x3233732e62757309ull,0x2c31313172250920ull,
0x202c303131722520ull,0x2e766f6d090a3b31ull,0x3172250920323373ull,0x090a3b30202c3231ull,
0x203233732e78616dull,0x25202c3831722509ull,0x7225202c31313172ull,0x7262090a3b323131ull,
0x240920696e752e61ull,0x3035335f305f744cull,0x5f744c240a3b3437ull,0x3a30333335335f30ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3436372065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a34393733335f30ull,
0x093509636f6c2e09ull,0x61090a3009393038ull,0x09203233732e6464ull,0x7225202c37317225ull,
0x090a3b31202c3731ull,0x38093509636f6c2eull,0x6461090a30093031ull,0x2509203233732e64ull,
0x7225202c36303172ull,0x240a3b31202c3039ull,0x3035335f305f744cull,0x3c2f2f200a3a3437ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x34363720656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3733335f305f744cull,0x636f6c2e090a3439ull,
0x3009343138093509ull,0x33732e646461090aull,0x3331317225092032ull,0x202c36317225202cull,
0x63090a3b37317225ull,0x732e3436752e7476ull,0x3264722509203233ull,0x3331317225202c31ull,
0x752e646461090a3bull,0x3264722509203436ull,0x3132647225202c32ull,0x3b3531647225202cull,
0x6f6c672e646c090aull,0x092038732e6c6162ull,0x255b202c30337225ull,0x3b5d302b32326472ull,
0x3509636f6c2e090aull,0x090a300936313809ull,0x203233732e766f6dull,0x202c343131722509ull,
0x70746573090a3b30ull,0x203233732e656e2eull,0x25202c3231702509ull,0x317225202c303372ull,
0x746573090a3b3431ull,0x3233752e746c2e70ull,0x202c333170250920ull,0x25202c3230317225ull,
0x40090a3b36303172ull,0x6172622033317025ull,0x5f305f744c240920ull,0x200a3b3433363733ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c343637ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x40090a3439373333ull,
0x7262203231702521ull,0x305f744c24092061ull,0x0a3b34333637335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c34363720ull,
0x6c6562616c206461ull,0x305f744c24206465ull,0x090a34393733335full,0x6d617261702e646cull,
0x722509203436752eull,0x5f5f5b202c333264ull,0x6d72617061647563ull,0x6d756d35315a5f5full,
0x654b75706772656dull,0x635076506c656e72ull,0x3253694b505f3053ull,0x5d6665725f69695full,
0x335f305f4c240a3bull,0x2f200a3a36363430ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,
0x3820656e696c2079ull,0x636f6c2e090a3831ull,0x3009383138093509ull,0x36752e747663090aull,
0x2509203233732e34ull,0x7225202c34326472ull,0x6c2e090a3b363031ull,0x363138093509636full,
0x702e646c090a3009ull,0x3436752e6d617261ull,0x2c33326472250920ull,0x616475635f5f5b20ull,
0x315a5f5f6d726170ull,0x6772656d6d756d35ull,0x6c656e72654b7570ull,0x505f305363507650ull,
0x5f69695f3253694bull,0x2e090a3b5d666572ull,0x3138093509636f6cull,0x646461090a300938ull,
0x722509203436752eull,0x647225202c353264ull,0x32647225202c3432ull,0x672e646c090a3b33ull,
0x38732e6c61626f6cull,0x2c35313172250920ull,0x2b35326472255b20ull,0x746573090a3b5d30ull,
0x3233732e71652e70ull,0x202c343170250920ull,0x7225202c30337225ull,0x2540090a3b353131ull,
0x2061726220343170ull,0x335f305f744c2409ull,0x2f200a3b36383535ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3720656e696c2079ull,0x64616568202c3133ull,
0x64656c6562616c20ull,0x335f305f744c2420ull,0x6f6d090a34313532ull,0x2509203233732e76ull,
0x347225202c313772ull,0x2e617262090a3b32ull,0x744c240920696e75ull,0x32383233335f305full,
0x5f305f744c240a3bull,0x200a3a3638353533ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c383138ull,0x656c6562616c2064ull,
0x335f305f4c242064ull,0x6c2e090a36363430ull,0x393238093509636full,0x2e646461090a3009ull,
0x3172250920323373ull,0x2c37317225202c37ull,0x6f6c2e090a3b3120ull,0x0930333809350963ull,
0x732e646461090a30ull,0x3031722509203233ull,0x3630317225202c36ull,0x6c2e090a3b31202cull,
0x323338093509636full,0x2e646461090a3009ull,0x3172250920323373ull,0x36317225202c3631ull,
0x0a3b37317225202cull,0x3436752e74766309ull,0x722509203233732eull,0x317225202c363264ull,
0x646461090a3b3631ull,0x722509203436752eull,0x647225202c373264ull,0x31647225202c3632ull,
0x672e646c090a3b35ull,0x38732e6c61626f6cull,0x202c303372250920ull,0x302b37326472255bull,
0x70746573090a3b5dull,0x203233752e746c2eull,0x25202c3531702509ull,0x7225202c32303172ull,
0x2540090a3b363031ull,0x2061726220353170ull,0x335f305f744c2409ull,0x2f200a3b36343138ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3820656e696c2079ull,
0x64616568202c3831ull,0x64656c6562616c20ull,0x30335f305f4c2420ull,0x766f6d090a363634ull,
0x722509203233732eull,0x0a3b30202c373131ull,0x656e2e7074657309ull,0x702509203233732eull,
0x30337225202c3631ull,0x3b3731317225202cull,0x72702e766f6d090aull,0x3231702509206465ull,
0x0a3b36317025202cull,0x6572702e766f6d09ull,0x2c37317025092064ull,0x090a3b3831702520ull,
0x7262203631702540ull,0x5f305f4c24092061ull,0x200a3b3636343033ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c343637ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x62090a3439373333ull,0x0920696e752e6172ull,
0x37335f305f744c24ull,0x744c240a3b343336ull,0x36343138335f305full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c34363720656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34393733335f305full,0x33732e766f6d090aull,
0x3831317225092032ull,0x6573090a3b30202cull,0x33732e656e2e7074ull,0x2c32317025092032ull,
0x25202c3033722520ull,0x4c240a3b38313172ull,0x333637335f305f74ull,0x5f305f4c240a3a34ull,
0x200a3a3232373033ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c343637ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x40090a3439373333ull,0x6172622032317025ull,0x5f305f744c240920ull,0x200a3b3439373333ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c313337ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x6d090a3431353233ull,
0x09203233732e766full,0x7225202c31377225ull,0x617262090a3b3234ull,0x4c240920696e752eull,
0x383233335f305f74ull,0x305f744c240a3b32ull,0x0a3a38373337335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c31333720ull,
0x6c6562616c206461ull,0x305f744c24206465ull,0x090a34313532335full,0x203233732e766f6dull,
0x25202c3234722509ull,0x6f6d090a3b313772ull,0x2509203233732e76ull,0x397225202c313972ull,
0x2e766f6d090a3b32ull,0x3172250920323373ull,0x240a3b30202c3630ull,0x3233335f305f744cull,
0x5f744c240a3a3238ull,0x0a3a323635325f30ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c31333720ull,0x6c6562616c206461ull,
0x305f744c24206465ull,0x090a34313532335full,0x38093509636f6c2eull,0x7573090a30093234ull,
0x2509203233752e62ull,0x7225202c39313172ull,0x397225202c363031ull,0x636f6c2e090a3b31ull,
0x3009313337093509ull,0x7261702e646c090aull,0x09203233732e6d61ull,0x5f5f5b202c397225ull,
0x6d72617061647563ull,0x6d756d35315a5f5full,0x654b75706772656dull,0x635076506c656e72ull,
0x3253694b505f3053ull,0x5f6e696d5f69695full,0x656c5f686374616dull,0x6f6c2e090a3b5d6eull,
0x0932343809350963ull,0x2e70746573090a30ull,0x09203233732e6567ull,0x7225202c39317025ull,
0x3b37317225202c39ull,0x203931702540090aull,0x744c240920617262ull,0x34353336335f305full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c31333720656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34313532335f305full,
0x3509636f6c2e090aull,0x090a300935353609ull,0x2e3436752e747663ull,0x6472250920323373ull,
0x36317225202c3832ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c39326472ull,
0x0a3b38202c383264ull,0x3436752e64646109ull,0x2c30336472250920ull,0x202c333164722520ull,
0x090a3b3932647225ull,0x61626f6c672e7473ull,0x3233732e32762e6cull,0x30336472255b0920ull,
0x72257b202c5d302bull,0x39313172252c3931ull,0x305f744c240a3b7dull,0x0a3a34353336335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c31333720ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x090a34313532335full,
0x38093509636f6c2eull,0x6f6d090a30093534ull,0x2509203233732e76ull,0x317225202c383172ull,
0x6f6c2e090a3b3931ull,0x0936343809350963ull,0x732e627573090a30ull,0x3231722509203233ull,
0x2c37317225202c30ull,0x0a3b393131722520ull,0x3233732e62757309ull,0x202c373172250920ull,
0x31202c3032317225ull,0x5f305f744c240a3bull,0x2f200a3a36303332ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3720656e696c2079ull,0x64616568202c3133ull,
0x64656c6562616c20ull,0x335f305f744c2420ull,0x6c2e090a34313532ull,0x313538093509636full,
0x2e646e61090a3009ull,0x3172250920323362ull,0x32347225202c3132ull,0x3b3533353536202cull,
0x6e722e747663090aull,0x3233752e3233662eull,0x25202c3966250920ull,0x73090a3b31323172ull,
0x09203233752e7268ull,0x25202c3232317225ull,0x3b3631202c323472ull,0x6e722e747663090aull,
0x3233752e3233662eull,0x202c303166250920ull,0x090a3b3232317225ull,0x203233662e766f6dull,
0x30202c3131662509ull,0x3030303030303066ull,0x2f09202020203b30ull,0x766f6d090a30202full,
0x662509203233662eull,0x30306630202c3231ull,0x203b303030303030ull,0x30202f2f09202020ull,
0x64322e786574090aull,0x2e3233752e34762eull,0x3172257b20323366ull,0x34323172252c3332ull,
0x252c35323172252cull,0x6e5b2c7d36323172ull,0x7b2c78657465646full,0x303166252c396625ull,
0x66252c313166252cull,0x2f200a3b5d7d3231ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3720656e696c2079ull,0x64616568202c3133ull,0x64656c6562616c20ull,
0x335f305f744c2420ull,0x6c2e090a34313532ull,0x353733093509636full,0x2e766f6d090a3009ull,
0x3172250920323373ull,0x32317225202c3732ull,0x2e766f6d090a3b33ull,0x3172250920323373ull,
0x32317225202c3832ull,0x636f6c2e090a3b34ull,0x3009363932093509ull,0x33622e6c6873090aull,
0x3932317225092032ull,0x2c3832317225202cull,0x6873090a3b363120ull,0x2509203233752e72ull,
0x7225202c30333172ull,0x3b3432202c393231ull,0x33622e646e61090aull,0x3133317225092032ull,
0x2c3033317225202cull,0x6873090a3b353120ull,0x2509203233622e6cull,0x7225202c32333172ull,
0x0a3b38202c313331ull,0x3233752e766f6d09ull,0x2c33333172250920ull,0x0a3b373231722520ull,
0x3233752e72687309ull,0x2c34333172250920ull,0x202c333331722520ull,0x2e726f090a3b3432ull,
0x3172250920323362ull,0x33317225202c3533ull,0x3433317225202c32ull,0x622e646e61090a3bull,
0x3331722509203233ull,0x3033317225202c36ull,0x090a3b303432202cull,0x203233622e6c6873ull,
0x202c373331722509ull,0x34202c3633317225ull,0x622e6c6873090a3bull,0x3331722509203233ull,
0x3832317225202c38ull,0x73090a3b3432202cull,0x09203233752e7268ull,0x25202c3933317225ull,
0x3432202c38333172ull,0x33622e726f090a3bull,0x3034317225092032ull,0x2c3733317225202cull,
0x0a3b393331722520ull,0x3233622e6c687309ull,0x2c31343172250920ull,0x202c303431722520ull,
0x2e726f090a3b3631ull,0x3172250920323362ull,0x3533317225202c39ull,0x3b3134317225202cull,
0x3509636f6c2e090aull,0x090a300932353809ull,0x203233732e646461ull,0x25202c3631722509ull,
0x0a3b31202c363172ull,0x656e2e7074657309ull,0x702509203233732eull,0x34317225202c3032ull,
0x0a3b36317225202cull,0x6220303270254009ull,0x5f744c2409206172ull,0x3b34313532335f30ull,
0x5f373442424c240aull,0x6d6d756d35315a5full,0x72654b7570677265ull,0x53635076506c656eull,
0x5f3253694b505f30ull,0x6f6c2e090a3a6969ull,0x0939353809350963ull,0x3b74697865090a30ull,
0x646e6557444c240aull,0x6d756d35315a5f5full,0x654b75706772656dull,0x635076506c656e72ull,
0x3253694b505f3053ull,0x207d090a3a69695full,0x6d35315a5f202f2full,0x75706772656d6d75ull,
0x76506c656e72654bull,0x694b505f30536350ull,0x090a0a69695f3253ull,0x5f207972746e652eull,
0x656d6d756d37315aull,0x654b435275706772ull,0x4d3031506c656e72ull,0x726f6f4368637461ull,
0x3353694b50635064ull,0x09090a282069695full,0x2e206d617261702eull,0x75635f5f20343675ull,
0x5f5f6d7261706164ull,0x656d6d756d37315aull,0x654b435275706772ull,0x4d3031506c656e72ull,
0x726f6f4368637461ull,0x3353694b50635064ull,0x6374616d5f69695full,0x7364726f6f635f68ull,
0x7261702e09090a2cull,0x203436752e206d61ull,0x6170616475635f5full,0x6d37315a5f5f6d72ull,
0x75706772656d6d75ull,0x6c656e72654b4352ull,0x686374614d303150ull,0x50635064726f6f43ull,
0x5f69695f3353694bull,0x2c73656972657571ull,0x617261702e09090aull,0x5f203436752e206dull,
0x726170616475635full,0x756d37315a5f5f6dull,0x5275706772656d6dull,0x506c656e72654b43ull,
0x43686374614d3031ull,0x4b50635064726f6full,0x715f69695f335369ull,0x7264644179726575ull,
0x61702e09090a2c73ull,0x3436752e206d6172ull,0x70616475635f5f20ull,0x37315a5f5f6d7261ull,
0x706772656d6d756dull,0x656e72654b435275ull,0x6374614d3031506cull,0x635064726f6f4368ull,
0x69695f3353694b50ull,0x654c79726575715full,0x090a2c736874676eull,0x206d617261702e09ull,
0x635f5f203233732eull,0x5f6d726170616475ull,0x6d6d756d37315a5full,0x4b43527570677265ull,
0x3031506c656e7265ull,0x6f6f43686374614dull,0x53694b5063506472ull,0x6d756e5f69695f33ull,
0x2c73656972657551ull,0x617261702e09090aull,0x5f203233732e206dull,0x726170616475635full,
0x756d37315a5f5f6dull,0x5275706772656d6dull,0x506c656e72654b43ull,0x43686374614d3031ull,
0x4b50635064726f6full,0x6d5f69695f335369ull,0x686374616d5f6e69ull,0x7b090a296e656c5full,
0x3509636f6c2e090aull,0x240a300932373809ull,0x315a5f5f3142424cull,0x6772656d6d756d37ull,
0x6e72654b43527570ull,0x74614d3031506c65ull,0x5064726f6f436863ull,0x695f3353694b5063ull,
0x636f6c2e090a3a69ull,0x0939333031093509ull,0x3b74697865090a30ull,0x646e6557444c240aull,
0x6d756d37315a5f5full,0x435275706772656dull,0x31506c656e72654bull,0x6f43686374614d30ull,
0x694b50635064726full,0x090a3a69695f3353ull,0x315a5f202f2f207dull,0x6772656d6d756d37ull,
0x6e72654b43527570ull,0x74614d3031506c65ull,0x5064726f6f436863ull,0x695f3353694b5063ull,
0x746e652e090a0a69ull,0x7031315a5f207972ull,0x6e72654b746e6972ull,0x6374614d39506c65ull,
0x3950696f666e4968ull,0x6e656d6e67696c41ull,0x3553694b50635074ull,0x282069696969695full,
0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,0x727031315a5f5f6dull,
0x656e72654b746e69ull,0x686374614d39506cull,0x413950696f666e49ull,0x746e656d6e67696cull,
0x5f3553694b506350ull,0x616d5f6969696969ull,0x090a2c7365686374ull,0x206d617261702e09ull,
0x635f5f203233732eull,0x5f6d726170616475ull,0x6e69727031315a5full,0x506c656e72654b74ull,
0x6e49686374614d39ull,0x696c413950696f66ull,0x6350746e656d6e67ull,0x69695f3553694b50ull,
0x61746f745f696969ull,0x7365686374614d6cull,0x7261702e09090a2cull,0x203436752e206d61ull,
0x6170616475635f5full,0x7031315a5f5f6d72ull,0x6e72654b746e6972ull,0x6374614d39506c65ull,
0x3950696f666e4968ull,0x6e656d6e67696c41ull,0x3553694b50635074ull,0x615f69696969695full,
0x746e656d6e67696cull,0x61702e09090a2c73ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x31315a5f5f6d7261ull,0x72654b746e697270ull,0x74614d39506c656eull,0x50696f666e496863ull,
0x656d6e67696c4139ull,0x53694b506350746eull,0x5f69696969695f35ull,0x61705f6c61765f5full,
0x69726575716d6172ull,0x702e09090a2c7365ull,0x36752e206d617261ull,0x616475635f5f2034ull,
0x315a5f5f6d726170ull,0x654b746e69727031ull,0x614d39506c656e72ull,0x696f666e49686374ull,
0x6d6e67696c413950ull,0x694b506350746e65ull,0x69696969695f3553ull,0x644179726575715full,
0x2e09090a2c737264ull,0x752e206d61726170ull,0x6475635f5f203436ull,0x5a5f5f6d72617061ull,
0x4b746e6972703131ull,0x4d39506c656e7265ull,0x6f666e4968637461ull,0x6e67696c41395069ull,
0x4b506350746e656dull,0x696969695f355369ull,0x4c79726575715f69ull,0x0a2c736874676e65ull,
0x6d617261702e0909ull,0x5f5f203233732e20ull,0x6d72617061647563ull,0x69727031315a5f5full,
0x6c656e72654b746eull,0x49686374614d3950ull,0x6c413950696f666eull,0x50746e656d6e6769ull,
0x695f3553694b5063ull,0x6761705f69696969ull,0x2c6e696765625f65ull,0x617261702e09090aull,
0x5f203233732e206dull,0x726170616475635full,0x727031315a5f5f6dull,0x656e72654b746e69ull,
0x686374614d39506cull,0x413950696f666e49ull,0x746e656d6e67696cull,0x5f3553694b506350ull,
0x61705f6969696969ull,0x0a2c646e655f6567ull,0x6d617261702e0909ull,0x5f5f203233732e20ull,
0x6d72617061647563ull,0x69727031315a5f5full,0x6c656e72654b746eull,0x49686374614d3950ull,
0x6c413950696f666eull,0x50746e656d6e6769ull,0x695f3553694b5063ull,0x6761705f69696969ull,
0x776f646168735f65ull,0x090a2c7466656c5full,0x206d617261702e09ull,0x635f5f203233732eull,
0x5f6d726170616475ull,0x6e69727031315a5full,0x506c656e72654b74ull,0x6e49686374614d39ull,
0x696c413950696f66ull,0x6350746e656d6e67ull,0x69695f3553694b50ull,0x656761705f696969ull,
0x5f776f646168735full,0x090a2c7468676972ull,0x206d617261702e09ull,0x635f5f203233732eull,
0x5f6d726170616475ull,0x6e69727031315a5full,0x506c656e72654b74ull,0x6e49686374614d39ull,
0x696c413950696f66ull,0x6350746e656d6e67ull,0x69695f3553694b50ull,0x5f6e696d5f696969ull,
0x656c5f686374616dull,0x7b090a296874676eull,0x2e206765722e090aull,0x333c722520323375ull,
0x722e090a3b3e3238ull,0x203436752e206765ull,0x3b3e38333c647225ull,0x2e206765722e090aull,
0x353c662520323366ull,0x65722e090a3b3e30ull,0x20646572702e2067ull,0x0a3b3e38333c7025ull,
0x206c61636f6c2e09ull,0x31206e67696c612eull,0x5f5f2038622e2036ull,0x646f6e5f61647563ull,
0x5d36315b36315f65ull,0x61636f6c2e090a3bull,0x6e67696c612e206cull,0x2038622e20363120ull,
0x635f616475635f5full,0x5f6e6572646c6968ull,0x0a3b5d36315b3233ull,0x093509636f6c2e09ull,
0x240a300937363031ull,0x315a5f5f3142424cull,0x654b746e69727031ull,0x614d39506c656e72ull,
0x696f666e49686374ull,0x6d6e67696c413950ull,0x694b506350746e65ull,0x69696969695f3553ull,
0x752e747663090a3aull,0x09203631752e3233ull,0x746325202c317225ull,0x090a3b782e646961ull,
0x2e3233752e747663ull,0x3272250920363175ull,0x2e6469746e25202cull,0x326c756d090a3b78ull,
0x3233752e6f6c2e34ull,0x25202c3372250920ull,0x3b327225202c3172ull,0x33752e747663090aull,
0x2509203631752e32ull,0x64697425202c3472ull,0x646461090a3b782eull,0x722509203233752eull,
0x202c347225202c35ull,0x646c090a3b337225ull,0x732e6d617261702eull,0x2c36722509203233ull,
0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x654b746e69727031ull,0x614d39506c656e72ull,
0x696f666e49686374ull,0x6d6e67696c413950ull,0x694b506350746e65ull,0x69696969695f3553ull,
0x614d6c61746f745full,0x0a3b5d7365686374ull,0x74672e7074657309ull,0x702509203233732eull,
0x202c367225202c31ull,0x2540090a3b357225ull,0x0920617262203170ull,0x36345f325f744c24ull,
0x7262090a3b343935ull,0x240920696e752e61ull,0x5a5f5f313842424cull,0x4b746e6972703131ull,
0x4d39506c656e7265ull,0x6f666e4968637461ull,0x6e67696c41395069ull,0x4b506350746e656dull,
0x696969695f355369ull,0x325f744c240a3b69ull,0x0a3a34393536345full,0x093509636f6c2e09ull,
0x090a300930383031ull,0x6d617261702e646cull,0x722509203436752eull,0x635f5f5b202c3164ull,
0x5f6d726170616475ull,0x6e69727031315a5full,0x506c656e72654b74ull,0x6e49686374614d39ull,
0x696c413950696f66ull,0x6350746e656d6e67ull,0x69695f3553694b50ull,0x6374616d5f696969ull,
0x63090a3b5d736568ull,0x732e3436752e7476ull,0x3264722509203233ull,0x090a3b357225202cull,
0x752e6f6c2e6c756dull,0x3364722509203436ull,0x202c32647225202cull,0x646461090a3b3032ull,
0x722509203436752eull,0x31647225202c3464ull,0x0a3b33647225202cull,0x617261702e646c09ull,
0x2509203436752e6dull,0x5f5f5b202c356472ull,0x6d72617061647563ull,0x69727031315a5f5full,
0x6c656e72654b746eull,0x49686374614d3950ull,0x6c413950696f666eull,0x50746e656d6e6769ull,
0x695f3553694b5063ull,0x6575715f69696969ull,0x5d73726464417972ull,0x6c672e646c090a3bull,
0x3233752e6c61626full,0x5b202c3772250920ull,0x3b5d342b34647225ull,0x36752e747663090aull,
0x2509203233752e34ull,0x377225202c366472ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x647225202c376472ull,0x61090a3b34202c36ull,0x09203436752e6464ull,0x7225202c38647225ull,
0x37647225202c3564ull,0x6c672e646c090a3bull,0x3233732e6c61626full,0x5b202c3872250920ull,
0x3b5d302b38647225ull,0x3509636f6c2e090aull,0x0a30093838303109ull,0x3436752e74766309ull,
0x722509203233732eull,0x3b387225202c3964ull,0x7261702e646c090aull,0x09203436752e6d61ull,
0x5b202c3031647225ull,0x6170616475635f5full,0x7031315a5f5f6d72ull,0x6e72654b746e6972ull,
0x6374614d39506c65ull,0x3950696f666e4968ull,0x6e656d6e67696c41ull,0x3553694b50635074ull,
0x5f5f69696969695full,0x7261705f6c61765full,0x6569726575716d61ull,0x646461090a3b5d73ull,
0x722509203436752eull,0x647225202c313164ull,0x3031647225202c39ull,0x6c672e646c090a3bull,
0x3631752e6c61626full,0x5b202c3972250920ull,0x5d38312b34647225ull,0x752e747663090a3bull,
0x09203233752e3436ull,0x25202c3231647225ull,0x646461090a3b3972ull,0x722509203436752eull,
0x647225202c333164ull,0x31647225202c3231ull,0x672e646c090a3b31ull,0x38732e6c61626f6cull,
0x202c303172250920ull,0x302b33316472255bull,0x636f6c2e090a3b5dull,0x0931393031093509ull,
0x6c672e646c090a30ull,0x3233752e6c61626full,0x202c313172250920ull,0x5d382b346472255bull,
0x09636f6c2e090a3bull,0x3009323930310935ull,0x33732e766f6d090aull,0x2c32317225092032ull,
0x090a3b3131722520ull,0x31093509636f6c2eull,0x6d090a3009333930ull,0x09203233732e766full,
0x7225202c33317225ull,0x6f6c2e090a3b3131ull,0x3639303109350963ull,0x2e646e61090a3009ull,
0x3172250920323362ull,0x2c31317225202c34ull,0x0a3b353335353620ull,0x2e6e722e74766309ull,
0x203233752e323366ull,0x7225202c31662509ull,0x726873090a3b3431ull,0x722509203233752eull,
0x31317225202c3531ull,0x63090a3b3631202cull,0x33662e6e722e7476ull,0x2509203233752e32ull,
0x35317225202c3266ull,0x662e766f6d090a3bull,0x2c33662509203233ull,0x3030303030663020ull,
0x202020203b303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,0x6630202c34662509ull,
0x3030303030303030ull,0x2f0920202020203bull,0x786574090a30202full,0x752e34762e64322eull,
0x7b203233662e3233ull,0x3172252c36317225ull,0x252c383172252c37ull,0x6f6e5b2c7d393172ull,
0x257b2c7865746564ull,0x252c3266252c3166ull,0x5d7d3466252c3366ull,0x09636f6c2e090a3bull,
0x0a30093537330935ull,0x3233732e766f6d09ull,0x202c303272250920ull,0x6d090a3b36317225ull,
0x09203233732e766full,0x7225202c31327225ull,0x6f6c2e090a3b3931ull,0x3639303109350963ull,
0x2e766f6d090a3009ull,0x3272250920323373ull,0x3b30327225202c32ull,0x636f6c2e7473090aull,
0x09203233752e6c61ull,0x5f616475635f5f5bull,0x2b36315f65646f6eull,0x32327225202c5d30ull,
0x6f6c2e7473090a3bull,0x203233752e6c6163ull,0x616475635f5f5b09ull,0x36315f65646f6e5full,
0x7225202c5d32312bull,0x2e646c090a3b3132ull,0x33732e6d61726170ull,0x2c33327225092032ull,
0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x654b746e69727031ull,0x614d39506c656e72ull,
0x696f666e49686374ull,0x6d6e67696c413950ull,0x694b506350746e65ull,0x69696969695f3553ull,
0x74616d5f6e696d5full,0x74676e656c5f6863ull,0x6c6873090a3b5d68ull,0x722509203233622eull,
0x31327225202c3432ull,0x73090a3b3631202cull,0x09203233752e7268ull,0x7225202c35327225ull,
0x0a3b3432202c3432ull,0x3233622e6c687309ull,0x202c363272250920ull,0x3b38202c35327225ull,
0x33622e6c6873090aull,0x2c37327225092032ull,0x32202c3132722520ull,0x2e726873090a3b34ull,
0x3272250920323375ull,0x2c37327225202c38ull,0x726f090a3b343220ull,0x722509203233622eull,
0x36327225202c3932ull,0x0a3b38327225202cull,0x3233622e6c687309ull,0x202c303372250920ull,
0x3b38202c31327225ull,0x33752e726873090aull,0x2c31337225092032ull,0x32202c3033722520ull,
0x2e6c6873090a3b34ull,0x3372250920323362ull,0x2c31337225202c32ull,0x726f090a3b363120ull,
0x722509203233622eull,0x39327225202c3333ull,0x0a3b32337225202cull,0x65672e7074657309ull,
0x702509203233732eull,0x2c33327225202c32ull,0x090a3b3333722520ull,0x6172622032702540ull,
0x5f325f744c240920ull,0x240a3b3630313734ull,0x3637345f325f744cull,0x3c2f2f200a3a3831ull,
0x6f4c203e706f6f6cull,0x2079646f6220706full,0x39303120656e696cull,0x697473656e202c36ull,
0x687470656420676eull,0x747365202c31203aull,0x6920646574616d69ull,0x6e6f697461726574ull,
0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,0x0932303131093509ull,0x732e766f6d090a30ull,
0x3331722509203233ull,0x0a3b32317225202cull,0x093509636f6c2e09ull,0x73090a3009363932ull,
0x09203233622e6c68ull,0x7225202c34337225ull,0x090a3b38202c3232ull,0x203233752e726873ull,
0x25202c3533722509ull,0x3b3432202c343372ull,0x33622e6c6873090aull,0x2c36337225092032ull,
0x32202c3232722520ull,0x2e726873090a3b34ull,0x3372250920323375ull,0x2c36337225202c37ull,
0x6873090a3b343220ull,0x2509203233622e6cull,0x327225202c383372ull,0x090a3b3631202c32ull,
0x203233752e726873ull,0x25202c3933722509ull,0x3b3432202c383372ull,0x33622e646e61090aull,
0x2c30347225092032ull,0x31202c3533722520ull,0x2e646e61090a3b35ull,0x3472250920323362ull,
0x2c35337225202c31ull,0x73090a3b30343220ull,0x09203233622e6c68ull,0x7225202c32347225ull,
0x090a3b38202c3034ull,0x203233622e6c6873ull,0x25202c3334722509ull,0x0a3b34202c313472ull,
0x203233622e726f09ull,0x25202c3434722509ull,0x337225202c323472ull,0x622e726f090a3b37ull,
0x3534722509203233ull,0x202c33347225202cull,0x73090a3b39337225ull,0x09203233622e6c68ull,
0x7225202c36347225ull,0x0a3b3631202c3534ull,0x203233622e726f09ull,0x25202c3734722509ull,
0x347225202c343472ull,0x2e766f6d090a3b36ull,0x3172250920323373ull,0x3b37347225202c32ull,
0x3509636f6c2e090aull,0x0a30093430313109ull,0x3233622e646e6109ull,0x202c383472250920ull,
0x3536202c37347225ull,0x7663090a3b353335ull,0x3233662e6e722e74ull,0x662509203233752eull,
0x3b38347225202c35ull,0x33752e726873090aull,0x2c39347225092032ull,0x31202c3734722520ull,
0x2e747663090a3b36ull,0x752e3233662e6e72ull,0x2c36662509203233ull,0x090a3b3934722520ull,
0x203233662e766f6dull,0x6630202c37662509ull,0x3030303030303030ull,0x2f0920202020203bull,
0x766f6d090a30202full,0x662509203233662eull,0x3030306630202c38ull,0x20203b3030303030ull,
0x30202f2f09202020ull,0x64322e786574090aull,0x2e3233752e34762eull,0x3572257b20323366ull,
0x252c313572252c30ull,0x333572252c323572ull,0x7465646f6e5b2c7dull,0x2c3566257b2c7865ull,
0x2c3766252c366625ull,0x200a3b5d7d386625ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x6568202c36393031ull,0x6c6562616c206461ull,
0x325f744c24206465ull,0x090a38313637345full,0x33093509636f6c2eull,0x6f6d090a30093537ull,
0x2509203233732e76ull,0x357225202c303272ull,0x2e766f6d090a3b30ull,0x3572250920323373ull,
0x3b33357225202c34ull,0x3509636f6c2e090aull,0x0a30093430313109ull,0x3233732e766f6d09ull,
0x202c323272250920ull,0x73090a3b30327225ull,0x2e6c61636f6c2e74ull,0x5f5f5b0920323375ull,
0x646f6e5f61647563ull,0x2c5d302b36315f65ull,0x090a3b3232722520ull,0x6c61636f6c2e7473ull,
0x5f5b09203233752eull,0x6f6e5f616475635full,0x32312b36315f6564ull,0x3b34357225202c5dull,
0x33622e6c6873090aull,0x2c35357225092032ull,0x31202c3435722520ull,0x2e726873090a3b36ull,
0x3572250920323375ull,0x2c35357225202c36ull,0x6873090a3b343220ull,0x2509203233622e6cull,
0x357225202c373572ull,0x73090a3b38202c36ull,0x09203233622e6c68ull,0x7225202c38357225ull,
0x0a3b3432202c3435ull,0x3233752e72687309ull,0x202c393572250920ull,0x3432202c38357225ull,
0x33622e726f090a3bull,0x2c30367225092032ull,0x25202c3735722520ull,0x6873090a3b393572ull,
0x2509203233622e6cull,0x357225202c313672ull,0x73090a3b38202c34ull,0x09203233752e7268ull,
0x7225202c32367225ull,0x0a3b3432202c3136ull,0x3233622e6c687309ull,0x202c333672250920ull,
0x3631202c32367225ull,0x33622e726f090a3bull,0x2c34367225092032ull,0x25202c3036722520ull,
0x6c2e090a3b333672ull,0x393031093509636full,0x2e646c090a300936ull,0x33732e6d61726170ull,
0x2c33327225092032ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x654b746e69727031ull,
0x614d39506c656e72ull,0x696f666e49686374ull,0x6d6e67696c413950ull,0x694b506350746e65ull,
0x69696969695f3553ull,0x74616d5f6e696d5full,0x74676e656c5f6863ull,0x6f6c2e090a3b5d68ull,
0x3430313109350963ull,0x70746573090a3009ull,0x203233732e746c2eull,0x7225202c33702509ull,
0x34367225202c3332ull,0x2033702540090a3bull,0x744c240920617262ull,0x38313637345f325full,
0x5f325f744c240a3bull,0x090a3a3630313734ull,0x31093509636f6c2eull,0x6d090a3009313131ull,
0x09203233732e766full,0x7225202c35367225ull,0x6f6c2e090a3b3231ull,0x3231313109350963ull,
0x2e766f6d090a3009ull,0x3172250920323373ull,0x3b33317225202c32ull,0x3509636f6c2e090aull,
0x0a30093931313109ull,0x3233622e646e6109ull,0x202c363672250920ull,0x3536202c33317225ull,
0x7663090a3b353335ull,0x3233662e6e722e74ull,0x662509203233752eull,0x3b36367225202c39ull,
0x33752e726873090aull,0x2c37367225092032ull,0x31202c3331722520ull,0x2e747663090a3b36ull,
0x752e3233662e6e72ull,0x3031662509203233ull,0x0a3b37367225202cull,0x3233662e766f6d09ull,
0x202c313166250920ull,0x3030303030306630ull,0x09202020203b3030ull,0x6f6d090a30202f2full,
0x2509203233662e76ull,0x306630202c323166ull,0x3b30303030303030ull,0x202f2f0920202020ull,
0x322e786574090a30ull,0x3233752e34762e64ull,0x72257b203233662eull,0x2c393672252c3836ull,
0x3772252c30377225ull,0x65646f6e5b2c7d31ull,0x3966257b2c786574ull,0x66252c303166252cull,
0x7d323166252c3131ull,0x636f6c2e090a3b5dull,0x3009353733093509ull,0x33732e766f6d090aull,
0x2c30327225092032ull,0x090a3b3836722520ull,0x203233732e766f6dull,0x25202c3237722509ull,
0x6c2e090a3b313772ull,0x313131093509636full,0x2e7473090a300939ull,0x33752e6c61636f6cull,
0x75635f5f5b092032ull,0x5f65646f6e5f6164ull,0x25202c5d302b3631ull,0x7473090a3b303272ull,
0x752e6c61636f6c2eull,0x635f5f5b09203233ull,0x65646f6e5f616475ull,0x2c5d32312b36315full,
0x090a3b3237722520ull,0x31093509636f6c2eull,0x73090a3009313231ull,0x09203233622e6c68ull,
0x7225202c33377225ull,0x0a3b3631202c3237ull,0x3233752e72687309ull,0x202c343772250920ull,
0x3432202c33377225ull,0x622e6c6873090a3bull,0x3537722509203233ull,0x202c34377225202cull,
0x2e6c6873090a3b38ull,0x3772250920323362ull,0x2c32377225202c36ull,0x6873090a3b343220ull,
0x2509203233752e72ull,0x377225202c373772ull,0x090a3b3432202c36ull,0x09203233622e726full,
0x7225202c38377225ull,0x37377225202c3537ull,0x622e6c6873090a3bull,0x3937722509203233ull,
0x202c32377225202cull,0x2e726873090a3b38ull,0x3872250920323375ull,0x2c39377225202c30ull,
0x6873090a3b343220ull,0x2509203233622e6cull,0x387225202c313872ull,0x090a3b3631202c30ull,
0x09203233622e726full,0x7225202c32387225ull,0x31387225202c3837ull,0x732e627573090a3bull,
0x3338722509203233ull,0x202c32387225202cull,0x636f6c2e090a3b31ull,0x0934323131093509ull,
0x6c672e646c090a30ull,0x3233732e6c61626full,0x202c343872250920ull,0x5d302b346472255bull,
0x2e70746573090a3bull,0x09203233752e656eull,0x317225202c347025ull,0x3b31317225202c33ull,
0x622034702540090aull,0x5f744c2409206172ull,0x3b36383338345f32ull,0x6f6c672e646c090aull,
0x203631752e6c6162ull,0x5b202c3538722509ull,0x5d36312b34647225ull,0x752e766f6d090a3bull,
0x3638722509203233ull,0x6573090a3b30202cull,0x33752e71652e7074ull,0x202c357025092032ull,
0x7225202c35387225ull,0x702540090a3b3638ull,0x2409206172622035ull,0x3638345f325f744cull,
0x6f6c2e090a3b3234ull,0x3133313109350963ull,0x2e646e61090a3009ull,0x3872250920323362ull,
0x2c35367225202c37ull,0x0a3b353335353620ull,0x2e6e722e74766309ull,0x203233752e323366ull,
0x25202c3331662509ull,0x6873090a3b373872ull,0x2509203233752e72ull,0x367225202c383872ull,
0x090a3b3631202c35ull,0x662e6e722e747663ull,0x09203233752e3233ull,0x7225202c34316625ull,
0x766f6d090a3b3838ull,0x662509203233662eull,0x30306630202c3531ull,0x203b303030303030ull,
0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c36316625092032ull,0x3030303030663020ull,
0x202020203b303030ull,0x74090a30202f2f09ull,0x34762e64322e7865ull,0x3233662e3233752eull,
0x252c393872257b20ull,0x313972252c303972ull,0x5b2c7d323972252cull,0x2c78657465646f6eull,
0x66252c333166257bull,0x2c353166252c3431ull,0x0a3b5d7d36316625ull,0x093509636f6c2e09ull,
0x6d090a3009353733ull,0x09203233732e766full,0x7225202c30327225ull,0x766f6d090a3b3938ull,
0x722509203233732eull,0x32397225202c3339ull,0x09636f6c2e090a3bull,0x3009313331310935ull,
0x636f6c2e7473090aull,0x09203233752e6c61ull,0x5f616475635f5f5bull,0x2b36315f65646f6eull,
0x30327225202c5d30ull,0x6f6c2e7473090a3bull,0x203233752e6c6163ull,0x616475635f5f5b09ull,
0x36315f65646f6e5full,0x7225202c5d32312bull,0x6f6c2e090a3b3339ull,0x3233313109350963ull,
0x2e6c6873090a3009ull,0x3972250920323362ull,0x2c33397225202c34ull,0x6873090a3b363120ull,
0x2509203233752e72ull,0x397225202c353972ull,0x090a3b3432202c34ull,0x203233622e6c6873ull,
0x25202c3639722509ull,0x0a3b38202c353972ull,0x3233622e6c687309ull,0x202c373972250920ull,
0x3432202c33397225ull,0x752e726873090a3bull,0x3839722509203233ull,0x202c37397225202cull,
0x2e726f090a3b3432ull,0x3972250920323362ull,0x2c36397225202c39ull,0x090a3b3839722520ull,
0x203233622e6c6873ull,0x202c303031722509ull,0x3b38202c33397225ull,0x33752e726873090aull,
0x3130317225092032ull,0x2c3030317225202cull,0x6873090a3b343220ull,0x2509203233622e6cull,
0x7225202c32303172ull,0x3b3631202c313031ull,0x3233622e726f090aull,0x2c33303172250920ull,
0x25202c3939722520ull,0x61090a3b32303172ull,0x09203233732e6464ull,0x25202c3430317225ull,
0x317225202c353872ull,0x627573090a3b3330ull,0x722509203233732eull,0x30317225202c3338ull,
0x4c240a3b31202c34ull,0x343638345f325f74ull,0x2e766f6d090a3a32ull,0x3172250920323373ull,
0x090a3b31202c3530ull,0x20696e752e617262ull,0x345f325f744c2409ull,0x4c240a3b30333138ull,
0x383338345f325f74ull,0x2e766f6d090a3a36ull,0x3172250920323373ull,0x240a3b30202c3530ull,
0x3138345f325f744cull,0x746573090a3a3033ull,0x3233752e71652e70ull,0x25202c3670250920ull,
0x367225202c333172ull,0x36702540090a3b35ull,0x4c24092061726220ull,0x315a5f5f31384242ull,
0x654b746e69727031ull,0x614d39506c656e72ull,0x696f666e49686374ull,0x6d6e67696c413950ull,
0x694b506350746e65ull,0x69696969695f3553ull,0x732e766f6d090a3bull,0x3031722509203233ull,
0x6d090a3b30202c36ull,0x09203233732e766full,0x36202c3730317225ull,0x325f744c240a3b35ull,
0x0a3a36363639345full,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x2e090a3334313120ull,0x3131093509636f6cull,0x6e61090a30093334ull,0x2509203233622e64ull,
0x7225202c38303172ull,0x33353536202c3231ull,0x2e747663090a3b35ull,0x752e3233662e6e72ull,
0x3731662509203233ull,0x3b3830317225202cull,0x33752e726873090aull,0x3930317225092032ull,
0x202c32317225202cull,0x747663090a3b3631ull,0x2e3233662e6e722eull,0x3166250920323375ull,
0x3930317225202c38ull,0x662e766f6d090a3bull,0x3931662509203233ull,0x0a3b37316625202cull,
0x3233662e766f6d09ull,0x202c303266250920ull,0x6d090a3b38316625ull,0x09203233662e766full,
0x6630202c31326625ull,0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,
0x3266250920323366ull,0x3030306630202c32ull,0x20203b3030303030ull,0x0a30202f2f092020ull,
0x2e64322e78657409ull,0x662e3233752e3476ull,0x313172257b203233ull,0x2c31313172252c30ull,
0x72252c3231317225ull,0x68635b2c7d333131ull,0x65746e6572646c69ull,0x2c393166257b2c78ull,
0x3266252c30326625ull,0x5d7d323266252c31ull,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x2c3334313120656eull,0x616c206461656820ull,
0x4c242064656c6562ull,0x363639345f325f74ull,0x09636f6c2e090a36ull,0x0a30093831340935ull,
0x3233732e766f6d09ull,0x2c34313172250920ull,0x0a3b303131722520ull,0x3233732e766f6d09ull,
0x2c35313172250920ull,0x0a3b333131722520ull,0x093509636f6c2e09ull,0x090a300933343131ull,
0x203233732e766f6dull,0x202c363131722509ull,0x090a3b3531317225ull,0x203233732e726873ull,
0x202c373131722509ull,0x32202c3631317225ull,0x2e766f6d090a3b34ull,0x3172250920323373ull,
0x090a3b30202c3831ull,0x2e656e2e70746573ull,0x3770250920323373ull,0x2c3731317225202cull,
0x0a3b383131722520ull,0x33732e706c657309ull,0x3931317225092032ull,0x202c30202c31202cull,
0x6f6d090a3b377025ull,0x2509203233732e76ull,0x3b30202c30323172ull,0x656e2e746573090aull,
0x3233732e3233752eull,0x2c31323172250920ull,0x202c363031722520ull,0x090a3b3032317225ull,
0x203233732e67656eull,0x202c323231722509ull,0x090a3b3132317225ull,0x09203233622e726full,
0x25202c3332317225ull,0x7225202c39313172ull,0x6f6d090a3b323231ull,0x2509203233752e76ull,
0x3b30202c34323172ull,0x652e70746573090aull,0x2509203233732e71ull,0x32317225202c3870ull,
0x3432317225202c33ull,0x2038702540090a3bull,0x744c240920617262ull,0x38373130355f325full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,0x363639345f325f74ull,
0x6e2e746573090a36ull,0x33732e3233752e65ull,0x3532317225092032ull,0x202c30317225202cull,
0x090a3b3731317225ull,0x203233732e67656eull,0x202c363231722509ull,0x090a3b3532317225ull,
0x203233622e646e61ull,0x202c373231722509ull,0x25202c3931317225ull,0x6d090a3b36323172ull,
0x09203233752e766full,0x30202c3832317225ull,0x2e70746573090a3bull,0x09203233732e7165ull,
0x317225202c397025ull,0x32317225202c3732ull,0x39702540090a3b38ull,0x4c24092061726220ull,
0x333233365f325f74ull,0x6c3c2f2f200a3b34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x3334313120656e69ull,0x6c2064616568202cull,0x242064656c656261ull,
0x3639345f325f744cull,0x636f6c2e090a3636ull,0x0934353131093509ull,0x622e6c6873090a30ull,
0x3231722509203233ull,0x3431317225202c39ull,0x73090a3b3631202cull,0x09203233752e7268ull,
0x25202c3033317225ull,0x3432202c39323172ull,0x622e6c6873090a3bull,0x3331722509203233ull,
0x3431317225202c31ull,0x73090a3b3432202cull,0x09203233752e7268ull,0x25202c3233317225ull,
0x3432202c31333172ull,0x622e6c6873090a3bull,0x3331722509203233ull,0x3431317225202c33ull,
0x6873090a3b38202cull,0x2509203233752e72ull,0x7225202c34333172ull,0x3b3432202c333331ull,
0x33622e6c6873090aull,0x3533317225092032ull,0x2c3033317225202cull,0x6c6873090a3b3820ull,
0x722509203233622eull,0x317225202c363331ull,0x0a3b3631202c3433ull,0x203233622e726f09ull,
0x202c373331722509ull,0x25202c3533317225ull,0x6f090a3b32333172ull,0x2509203233622e72ull,
0x7225202c38333172ull,0x317225202c363331ull,0x2e646c090a3b3733ull,0x33732e6d61726170ull,
0x3933317225092032ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4b746e6972703131ull,
0x4d39506c656e7265ull,0x6f666e4968637461ull,0x6e67696c41395069ull,0x4b506350746e656dull,
0x696969695f355369ull,0x625f656761705f69ull,0x090a3b5d6e696765ull,0x203233732e646461ull,
0x202c303431722509ull,0x25202c3833317225ull,0x73090a3b39333172ull,0x09203233732e6275ull,
0x25202c3134317225ull,0x3b31202c30343172ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x317225202c303170ull,0x33317225202c3134ull,0x31702540090a3b39ull,0x2409206172622030ull,
0x333336345f325f4cull,0x6c3c2f2f200a3b38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x3334313120656e69ull,0x6c2064616568202cull,0x242064656c656261ull,
0x3639345f325f744cull,0x702e646c090a3636ull,0x3233732e6d617261ull,0x2c32343172250920ull,
0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x654b746e69727031ull,0x614d39506c656e72ull,
0x696f666e49686374ull,0x6d6e67696c413950ull,0x694b506350746e65ull,0x69696969695f3553ull,
0x68735f656761705full,0x66656c5f776f6461ull,0x766f6d090a3b5d74ull,0x722509203233752eull,
0x3b312d202c333431ull,0x6e2e70746573090aull,0x2509203233732e65ull,0x317225202c313170ull,
0x34317225202c3234ull,0x31702540090a3b33ull,0x2409206172622031ull,0x3233365f325f744cull,
0x325f4c240a3b3433ull,0x0a3a38333336345full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x68202c3334313120ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a36363639345f32ull,0x3233732e64646109ull,0x2c34343172250920ull,
0x202c303431722520ull,0x73090a3b33387225ull,0x09203233732e6275ull,0x25202c3534317225ull,
0x3b31202c34343172ull,0x7261702e646c090aull,0x09203233732e6d61ull,0x5b202c3634317225ull,
0x6170616475635f5full,0x7031315a5f5f6d72ull,0x6e72654b746e6972ull,0x6374614d39506c65ull,
0x3950696f666e4968ull,0x6e656d6e67696c41ull,0x3553694b50635074ull,0x705f69696969695full,
0x5d646e655f656761ull,0x2e70746573090a3bull,0x09203233732e656eull,0x7225202c32317025ull,
0x317225202c363431ull,0x702540090a3b3534ull,0x0920617262203231ull,0x3036345f325f4c24ull,
0x3c2f2f200a3b3238ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x34313120656e696cull,0x2064616568202c33ull,0x2064656c6562616cull,0x39345f325f744c24ull,
0x2e646c090a363636ull,0x33732e6d61726170ull,0x3734317225092032ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x4b746e6972703131ull,0x4d39506c656e7265ull,0x6f666e4968637461ull,
0x6e67696c41395069ull,0x4b506350746e656dull,0x696969695f355369ull,0x735f656761705f69ull,
0x69725f776f646168ull,0x6d090a3b5d746867ull,0x09203233752e766full,0x2d202c3834317225ull,
0x70746573090a3b31ull,0x203233732e656e2eull,0x25202c3331702509ull,0x7225202c37343172ull,
0x2540090a3b383431ull,0x2061726220333170ull,0x365f325f744c2409ull,0x4c240a3b34333233ull,
0x32383036345f325full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,
0x363639345f325f74ull,0x61702e646c090a36ull,0x203233732e6d6172ull,0x202c393431722509ull,
0x70616475635f5f5bull,0x31315a5f5f6d7261ull,0x72654b746e697270ull,0x74614d39506c656eull,
0x50696f666e496863ull,0x656d6e67696c4139ull,0x53694b506350746eull,0x5f69696969695f35ull,
0x6168735f65676170ull,0x7466656c5f776f64ull,0x2e746573090a3b5dull,0x732e3233752e656cull,
0x3531722509203233ull,0x3934317225202c30ull,0x3b3534317225202cull,0x33732e67656e090aull,
0x3135317225092032ull,0x3b3035317225202cull,0x7261702e646c090aull,0x09203233732e6d61ull,
0x5b202c3933317225ull,0x6170616475635f5full,0x7031315a5f5f6d72ull,0x6e72654b746e6972ull,
0x6374614d39506c65ull,0x3950696f666e4968ull,0x6e656d6e67696c41ull,0x3553694b50635074ull,
0x705f69696969695full,0x696765625f656761ull,0x746573090a3b5d6eull,0x2e3233752e656c2eull,
0x3172250920323373ull,0x34317225202c3235ull,0x3933317225202c31ull,0x732e67656e090a3bull,
0x3531722509203233ull,0x3235317225202c33ull,0x33622e726f090a3bull,0x3435317225092032ull,
0x2c3135317225202cull,0x0a3b333531722520ull,0x3233752e766f6d09ull,0x2c35353172250920ull,
0x746573090a3b3020ull,0x3233732e71652e70ull,0x202c343170250920ull,0x25202c3435317225ull,
0x40090a3b35353172ull,0x6172622034317025ull,0x5f325f744c240920ull,0x200a3b3433323336ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x6568202c33343131ull,0x6c6562616c206461ull,0x325f744c24206465ull,0x090a36363639345full,
0x31093509636f6c2eull,0x6c090a3009393631ull,0x2e6d617261702e64ull,0x6472250920343675ull,
0x635f5f5b202c3431ull,0x5f6d726170616475ull,0x6e69727031315a5full,0x506c656e72654b74ull,
0x6e49686374614d39ull,0x696c413950696f66ull,0x6350746e656d6e67ull,0x69695f3553694b50ull,
0x67696c615f696969ull,0x3b5d73746e656d6eull,0x36752e747663090aull,0x2509203233732e34ull,
0x7225202c35316472ull,0x6c756d090a3b3438ull,0x203436752e6f6c2eull,0x202c363164722509ull,
0x38202c3531647225ull,0x752e646461090a3bull,0x3164722509203436ull,0x3431647225202c37ull,
0x3b3631647225202cull,0x6f6c672e7473090aull,0x203233732e6c6162ull,0x2b37316472255b09ull,
0x34317225202c5d30ull,0x636f6c2e090a3b31ull,0x0930373131093509ull,0x6c672e7473090a30ull,
0x3631752e6c61626full,0x37316472255b0920ull,0x387225202c5d342bull,0x636f6c2e090a3b33ull,
0x0931373131093509ull,0x732e646461090a30ull,0x3438722509203233ull,0x202c34387225202cull,
0x325f744c240a3b31ull,0x0a3a34333233365full,0x3835345f325f4c24ull,0x5f744c240a3a3632ull,
0x3a34333430355f32ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x202c333431312065ull,0x62616c2064616568ull,0x744c242064656c65ull,
0x36363639345f325full,0x3509636f6c2e090aull,0x0a30093038313109ull,0x3233662e766f6d09ull,
0x202c333266250920ull,0x6d090a3b37316625ull,0x09203233662e766full,0x6625202c34326625ull,
0x766f6d090a3b3831ull,0x662509203233662eull,0x30306630202c3532ull,0x203b303030303030ull,
0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c36326625092032ull,0x3030303030663020ull,
0x202020203b303030ull,0x74090a30202f2f09ull,0x34762e64322e7865ull,0x3233662e3233752eull,
0x2c36353172257b20ull,0x72252c3735317225ull,0x353172252c383531ull,0x65646f6e5b2c7d39ull,
0x3266257b2c786574ull,0x252c343266252c33ull,0x363266252c353266ull,0x3c2f2f200a3b5d7dull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x34313120656e696cull,
0x2064616568202c33ull,0x2064656c6562616cull,0x39345f325f744c24ull,0x6f6c2e090a363636ull,
0x0935373309350963ull,0x732e766f6d090a30ull,0x3631722509203233ull,0x3635317225202c30ull,
0x732e766f6d090a3bull,0x3631722509203233ull,0x3935317225202c31ull,0x09636f6c2e090a3bull,
0x3009303831310935ull,0x636f6c2e7473090aull,0x09203233752e6c61ull,0x5f616475635f5f5bull,
0x2b36315f65646f6eull,0x36317225202c5d30ull,0x6c2e7473090a3b30ull,0x3233752e6c61636full,
0x6475635f5f5b0920ull,0x315f65646f6e5f61ull,0x25202c5d32312b36ull,0x2e090a3b31363172ull,
0x3131093509636f6cull,0x6873090a30093638ull,0x2509203233622e6cull,0x7225202c32363172ull,
0x0a3b38202c303631ull,0x3233752e72687309ull,0x202c353372250920ull,0x32202c3236317225ull,
0x2e6c6873090a3b34ull,0x3172250920323362ull,0x36317225202c3336ull,0x090a3b3432202c30ull,
0x203233752e726873ull,0x25202c3733722509ull,0x3432202c33363172ull,0x622e6c6873090a3bull,
0x3631722509203233ull,0x3036317225202c34ull,0x73090a3b3631202cull,0x09203233752e7268ull,
0x7225202c39337225ull,0x3b3432202c343631ull,0x33622e646e61090aull,0x2c30347225092032ull,
0x31202c3533722520ull,0x2e646e61090a3b35ull,0x3472250920323362ull,0x2c35337225202c31ull,
0x73090a3b30343220ull,0x09203233622e6c68ull,0x7225202c32347225ull,0x090a3b38202c3034ull,
0x203233622e6c6873ull,0x25202c3334722509ull,0x0a3b34202c313472ull,0x203233622e726f09ull,
0x25202c3434722509ull,0x337225202c323472ull,0x622e726f090a3b37ull,0x3534722509203233ull,
0x202c33347225202cull,0x73090a3b39337225ull,0x09203233622e6c68ull,0x7225202c36347225ull,
0x0a3b3631202c3534ull,0x203233622e726f09ull,0x25202c3734722509ull,0x347225202c343472ull,
0x2e726873090a3b36ull,0x3172250920323375ull,0x37347225202c3536ull,0x63090a3b3631202cull,
0x33662e6e722e7476ull,0x2509203233752e32ull,0x317225202c373266ull,0x646e61090a3b3536ull,
0x722509203233622eull,0x347225202c363631ull,0x3533353536202c37ull,0x722e747663090a3bull,
0x33752e3233662e6eull,0x2c38326625092032ull,0x0a3b363631722520ull,0x3233662e766f6d09ull,
0x202c393266250920ull,0x6d090a3b38326625ull,0x09203233662e766full,0x6625202c30336625ull,
0x766f6d090a3b3732ull,0x662509203233662eull,0x30306630202c3133ull,0x203b303030303030ull,
0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c32336625092032ull,0x3030303030663020ull,
0x202020203b303030ull,0x74090a30202f2f09ull,0x34762e64322e7865ull,0x3233662e3233752eull,
0x2c37363172257b20ull,0x72252c3836317225ull,0x373172252c393631ull,0x6c6968635b2c7d30ull,
0x2c7865746e657264ull,0x66252c393266257bull,0x2c313366252c3033ull,0x0a3b5d7d32336625ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x68202c3334313120ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a36363639345f32ull,
0x093509636f6c2e09ull,0x6d090a3009383134ull,0x09203233732e766full,0x25202c3137317225ull,
0x6d090a3b37363172ull,0x09203233732e766full,0x25202c3237317225ull,0x6d090a3b38363172ull,
0x09203233732e766full,0x25202c3337317225ull,0x2e090a3b39363172ull,0x3131093509636f6cull,
0x6873090a30093239ull,0x2509203233622e6cull,0x7225202c34373172ull,0x0a3b38202c313731ull,
0x3233752e72687309ull,0x2c35373172250920ull,0x202c343731722520ull,0x646e61090a3b3432ull,
0x722509203233622eull,0x317225202c363731ull,0x0a3b3531202c3537ull,0x3233622e6c687309ull,
0x2c37373172250920ull,0x202c363731722520ull,0x2e6c6873090a3b38ull,0x3172250920323362ull,
0x37317225202c3837ull,0x090a3b3432202c31ull,0x203233752e726873ull,0x202c393731722509ull,
0x32202c3837317225ull,0x622e726f090a3b34ull,0x3831722509203233ull,0x3737317225202c30ull,
0x3b3937317225202cull,0x33622e646e61090aull,0x3138317225092032ull,0x2c3537317225202cull,
0x73090a3b30343220ull,0x09203233622e6c68ull,0x25202c3238317225ull,0x3b34202c31383172ull,
0x33622e6c6873090aull,0x3338317225092032ull,0x2c3137317225202cull,0x6873090a3b363120ull,
0x2509203233752e72ull,0x7225202c34383172ull,0x3b3432202c333831ull,0x3233622e726f090aull,
0x2c35383172250920ull,0x202c323831722520ull,0x090a3b3438317225ull,0x203233622e6c6873ull,
0x202c363831722509ull,0x31202c3538317225ull,0x622e726f090a3b36ull,0x3831722509203233ull,
0x3038317225202c37ull,0x3b3638317225202cull,0x6e2e70746573090aull,0x2509203233752e65ull,
0x317225202c353170ull,0x3738317225202c32ull,0x3531702540090a3bull,0x4c24092061726220ull,
0x313731355f325f74ull,0x6c3c2f2f200a3b34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x3334313120656e69ull,0x6c2064616568202cull,0x242064656c656261ull,
0x3639345f325f744cull,0x2e766f6d090a3636ull,0x3172250920323373ull,0x090a3b30202c3630ull,
0x203233732e766f6dull,0x202c373031722509ull,0x617262090a3b3736ull,0x4c240920696e752eull,
0x393932355f325f74ull,0x325f744c240a3b34ull,0x0a3a34313731355full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x68202c3334313120ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a36363639345f32ull,0x3233622e6c687309ull,
0x2c38383172250920ull,0x202c323731722520ull,0x726873090a3b3631ull,0x722509203233752eull,
0x317225202c393831ull,0x0a3b3432202c3838ull,0x3233622e646e6109ull,0x2c30393172250920ull,
0x202c393831722520ull,0x6c6873090a3b3531ull,0x722509203233622eull,0x317225202c313931ull,
0x090a3b38202c3039ull,0x203233752e766f6dull,0x202c323931722509ull,0x090a3b3137317225ull,
0x203233752e726873ull,0x202c333931722509ull,0x32202c3239317225ull,0x622e726f090a3b34ull,
0x3931722509203233ull,0x3139317225202c34ull,0x3b3339317225202cull,0x33622e646e61090aull,
0x3539317225092032ull,0x2c3938317225202cull,0x73090a3b30343220ull,0x09203233622e6c68ull,
0x25202c3639317225ull,0x3b34202c35393172ull,0x33622e6c6873090aull,0x3739317225092032ull,
0x2c3237317225202cull,0x6873090a3b343220ull,0x2509203233752e72ull,0x7225202c38393172ull,
0x3b3432202c373931ull,0x3233622e726f090aull,0x2c39393172250920ull,0x202c363931722520ull,
0x090a3b3839317225ull,0x203233622e6c6873ull,0x202c303032722509ull,0x31202c3939317225ull,
0x622e726f090a3b36ull,0x3032722509203233ull,0x3439317225202c31ull,0x3b3030327225202cull,
0x6e2e70746573090aull,0x2509203233752e65ull,0x317225202c363170ull,0x3130327225202c32ull,
0x3631702540090a3bull,0x4c24092061726220ull,0x323232355f325f74ull,0x6c3c2f2f200a3b36ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x3334313120656e69ull,
0x6c2064616568202cull,0x242064656c656261ull,0x3639345f325f744cull,0x2e766f6d090a3636ull,
0x3172250920323373ull,0x090a3b30202c3630ull,0x203233732e766f6dull,0x202c373031722509ull,
0x617262090a3b3137ull,0x4c240920696e752eull,0x393932355f325f74ull,0x325f744c240a3b34ull,
0x0a3a36323232355full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x68202c3334313120ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a36363639345f32ull,0x3233622e6c687309ull,0x2c32303272250920ull,0x202c333731722520ull,
0x726873090a3b3432ull,0x722509203233752eull,0x327225202c333032ull,0x0a3b3432202c3230ull,
0x3233622e646e6109ull,0x2c34303272250920ull,0x202c333032722520ull,0x6c6873090a3b3531ull,
0x722509203233622eull,0x327225202c353032ull,0x090a3b38202c3430ull,0x203233622e6c6873ull,
0x202c363032722509ull,0x38202c3237317225ull,0x752e726873090a3bull,0x3032722509203233ull,
0x3630327225202c37ull,0x6f090a3b3432202cull,0x2509203233622e72ull,0x7225202c38303272ull,
0x327225202c353032ull,0x646e61090a3b3730ull,0x722509203233622eull,0x327225202c393032ull,
0x3b303432202c3330ull,0x33622e6c6873090aull,0x3031327225092032ull,0x2c3930327225202cull,
0x766f6d090a3b3420ull,0x722509203233752eull,0x317225202c313132ull,0x726873090a3b3237ull,
0x722509203233752eull,0x327225202c323132ull,0x0a3b3432202c3131ull,0x203233622e726f09ull,
0x202c333132722509ull,0x25202c3031327225ull,0x73090a3b32313272ull,0x09203233622e6c68ull,
0x25202c3431327225ull,0x3631202c33313272ull,0x33622e726f090a3bull,0x3531327225092032ull,
0x2c3830327225202cull,0x0a3b343132722520ull,0x656e2e7074657309ull,0x702509203233752eull,
0x32317225202c3731ull,0x3b3531327225202cull,0x203731702540090aull,0x744c240920617262ull,
0x38333732355f325full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,
0x363639345f325f74ull,0x732e766f6d090a36ull,0x3031722509203233ull,0x6d090a3b30202c36ull,
0x09203233732e766full,0x38202c3730317225ull,0x2e617262090a3b34ull,0x744c240920696e75ull,
0x34393932355f325full,0x5f325f744c240a3bull,0x200a3a3833373235ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x6568202c33343131ull,
0x6c6562616c206461ull,0x325f744c24206465ull,0x090a36363639345full,0x203233752e766f6dull,
0x202c363132722509ull,0x090a3b3337317225ull,0x203233752e726873ull,0x202c373132722509ull,
0x32202c3631327225ull,0x2e646e61090a3b34ull,0x3272250920323362ull,0x31327225202c3831ull,
0x090a3b3531202c37ull,0x203233622e6c6873ull,0x202c393132722509ull,0x38202c3831327225ull,
0x622e6c6873090a3bull,0x3232722509203233ull,0x3337317225202c30ull,0x73090a3b3631202cull,
0x09203233752e7268ull,0x25202c3132327225ull,0x3432202c30323272ull,0x33622e726f090a3bull,
0x3232327225092032ull,0x2c3931327225202cull,0x0a3b313232722520ull,0x3233622e646e6109ull,
0x2c33323272250920ull,0x202c373132722520ull,0x6873090a3b303432ull,0x2509203233622e6cull,
0x7225202c34323272ull,0x0a3b34202c333232ull,0x3233622e6c687309ull,0x2c35323272250920ull,
0x202c333731722520ull,0x2e726873090a3b38ull,0x3272250920323375ull,0x32327225202c3632ull,
0x090a3b3432202c35ull,0x09203233622e726full,0x25202c3732327225ull,0x7225202c34323272ull,
0x6873090a3b363232ull,0x2509203233622e6cull,0x7225202c38323272ull,0x3b3631202c373232ull,
0x3233622e726f090aull,0x2c39323272250920ull,0x202c323232722520ull,0x090a3b3832327225ull,
0x2e656e2e70746573ull,0x3170250920323375ull,0x2c32317225202c38ull,0x0a3b393232722520ull,
0x6220383170254009ull,0x5f744c2409206172ull,0x3b30353233355f32ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x202c333431312065ull,
0x62616c2064616568ull,0x744c242064656c65ull,0x36363639345f325full,0x33732e766f6d090aull,
0x3630317225092032ull,0x6f6d090a3b30202cull,0x2509203233732e76ull,0x3633202c37303172ull,
0x752e617262090a3bull,0x5f744c240920696eull,0x3b34393932355f32ull,0x355f325f744c240aull,
0x2f200a3a30353233ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x616568202c333431ull,0x656c6562616c2064ull,0x5f325f744c242064ull,
0x2e090a3636363934ull,0x3231093509636f6cull,0x6f6d090a30093030ull,0x2509203233732e76ull,
0x3b31202c36303172ull,0x355f325f744c240aull,0x4c240a3a34393932ull,0x383432355f325f74ull,
0x325f744c240a3a32ull,0x0a3a30373931355full,0x31355f325f744c24ull,0x2f2f200a3a383534ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x313120656e696c20ull,
0x64616568202c3334ull,0x64656c6562616c20ull,0x345f325f744c2420ull,0x6c2e090a36363639ull,
0x303231093509636full,0x766f6d090a300933ull,0x722509203233732eull,0x37347225202c3231ull,
0x732e627573090a3bull,0x3332722509203233ull,0x3530317225202c30ull,0x6f6d090a3b31202cull,
0x2509203233732e76ull,0x3b30202c31333272ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x317225202c393170ull,0x33327225202c3530ull,0x706c6573090a3b31ull,0x722509203233732eull,
0x327225202c353031ull,0x30317225202c3033ull,0x3b39317025202c35ull,0x33752e766f6d090aull,
0x3233327225092032ull,0x6573090a3b30202cull,0x33732e656e2e7074ull,0x2c30327025092032ull,
0x202c353031722520ull,0x090a3b3233327225ull,0x7262203032702540ull,0x325f744c24092061ull,
0x0a3b30353639355full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x68202c3334313120ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a36363639345f32ull,0x093509636f6c2e09ull,0x090a300939303231ull,0x203233662e766f6dull,
0x25202c3333662509ull,0x6f6d090a3b383266ull,0x2509203233662e76ull,0x326625202c343366ull,
0x2e766f6d090a3b37ull,0x3366250920323366ull,0x3030306630202c35ull,0x20203b3030303030ull,
0x0a30202f2f092020ull,0x3233662e766f6d09ull,0x202c363366250920ull,0x3030303030306630ull,
0x09202020203b3030ull,0x6574090a30202f2full,0x2e34762e64322e78ull,0x203233662e323375ull,
0x252c33333272257bull,0x3272252c34333272ull,0x36333272252c3533ull,0x7465646f6e5b2c7dull,
0x333366257b2c7865ull,0x66252c343366252cull,0x7d363366252c3533ull,0x6c3c2f2f200a3b5dull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x3334313120656e69ull,
0x6c2064616568202cull,0x242064656c656261ull,0x3639345f325f744cull,0x636f6c2e090a3636ull,
0x3009353733093509ull,0x33732e766f6d090aull,0x2c30327225092032ull,0x0a3b333332722520ull,
0x3233732e766f6d09ull,0x2c37333272250920ull,0x0a3b363332722520ull,0x093509636f6c2e09ull,
0x090a300939303231ull,0x6c61636f6c2e7473ull,0x5f5b09203233752eull,0x6f6e5f616475635full,
0x5d302b36315f6564ull,0x0a3b30327225202cull,0x61636f6c2e747309ull,0x5b09203233752e6cull,
0x6e5f616475635f5full,0x312b36315f65646full,0x33327225202c5d32ull,0x636f6c2e090a3b37ull,
0x0930313231093509ull,0x622e6c6873090a30ull,0x3332722509203233ull,0x3733327225202c38ull,
0x73090a3b3631202cull,0x09203233752e7268ull,0x25202c3933327225ull,0x3432202c38333272ull,
0x622e6c6873090a3bull,0x3432722509203233ull,0x3933327225202c30ull,0x6873090a3b38202cull,
0x2509203233622e6cull,0x7225202c31343272ull,0x3b3432202c373332ull,0x33752e726873090aull,
0x3234327225092032ull,0x2c3134327225202cull,0x726f090a3b343220ull,0x722509203233622eull,
0x327225202c333432ull,0x34327225202c3034ull,0x2e6c6873090a3b32ull,0x3272250920323362ull,
0x33327225202c3434ull,0x73090a3b38202c37ull,0x09203233752e7268ull,0x25202c3534327225ull,
0x3432202c34343272ull,0x622e6c6873090a3bull,0x3432722509203233ull,0x3534327225202c36ull,
0x6f090a3b3631202cull,0x2509203233622e72ull,0x7225202c37343272ull,0x327225202c333432ull,
0x627573090a3b3634ull,0x722509203233732eull,0x34327225202c3338ull,0x62090a3b31202c37ull,
0x0920696e752e6172ull,0x39355f325f744c24ull,0x744c240a3b303536ull,0x38373130355f325full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,0x363639345f325f74ull,
0x09636f6c2e090a36ull,0x3009373132310935ull,0x33662e766f6d090aull,0x2c37336625092032ull,
0x090a3b3731662520ull,0x203233662e766f6dull,0x25202c3833662509ull,0x6f6d090a3b383166ull,
0x2509203233662e76ull,0x306630202c393366ull,0x3b30303030303030ull,0x202f2f0920202020ull,
0x662e766f6d090a30ull,0x3034662509203233ull,0x303030306630202cull,0x2020203b30303030ull,
0x090a30202f2f0920ull,0x762e64322e786574ull,0x33662e3233752e34ull,0x38343272257b2032ull,
0x252c39343272252cull,0x3272252c30353272ull,0x6968635b2c7d3135ull,0x7865746e6572646cull,
0x252c373366257b2cull,0x393366252c383366ull,0x3b5d7d303466252cull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x202c333431312065ull,
0x62616c2064616568ull,0x744c242064656c65ull,0x36363639345f325full,0x3509636f6c2e090aull,
0x090a300938313409ull,0x203233732e766f6dull,0x202c323532722509ull,0x090a3b3834327225ull,
0x203233732e766f6dull,0x202c333532722509ull,0x090a3b3934327225ull,0x203233732e766f6dull,
0x202c343532722509ull,0x090a3b3035327225ull,0x203233732e766f6dull,0x202c353532722509ull,
0x090a3b3135327225ull,0x31093509636f6c2eull,0x73090a3009373132ull,0x2e6c61636f6c2e74ull,
0x5f5f5b0920323375ull,0x6968635f61647563ull,0x32335f6e6572646cull,0x327225202c5d302bull,
0x2e7473090a3b3235ull,0x33752e6c61636f6cull,0x75635f5f5b092032ull,0x646c6968635f6164ull,
0x342b32335f6e6572ull,0x3335327225202c5dull,0x732e766f6d090a3bull,0x3532722509203233ull,
0x73090a3b30202c36ull,0x732e71652e707465ull,0x3132702509203233ull,0x2c3530317225202cull,
0x0a3b363532722520ull,0x2031327025214009ull,0x744c240920617262ull,0x34373234355f325full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,0x363639345f325f74ull,
0x09636f6c2e090a36ull,0x3009353232310935ull,0x6f6c672e646c090aull,0x203631752e6c6162ull,
0x202c373532722509ull,0x38312b346472255bull,0x2e646461090a3b5dull,0x3272250920323373ull,
0x33387225202c3835ull,0x3b3735327225202cull,0x36752e747663090aull,0x2509203233732e34ull,
0x7225202c38316472ull,0x6461090a3b383532ull,0x2509203436752e64ull,0x7225202c39316472ull,
0x647225202c383164ull,0x2e646c090a3b3131ull,0x732e6c61626f6c67ull,0x3935327225092038ull,
0x39316472255b202cull,0x7262090a3b5d312bull,0x240920696e752e61ull,0x3034355f325f744cull,
0x5f744c240a3b3831ull,0x3a34373234355f32ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x202c333431312065ull,0x62616c2064616568ull,
0x744c242064656c65ull,0x36363639345f325full,0x33732e766f6d090aull,0x3935327225092032ull,
0x744c240a3b30202cull,0x38313034355f325full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x2c3334313120656eull,0x616c206461656820ull,
0x4c242064656c6562ull,0x363639345f325f74ull,0x752e766f6d090a36ull,0x3632722509203233ull,
0x090a3b3536202c30ull,0x2e656e2e70746573ull,0x3270250920323373ull,0x3730317225202c32ull,
0x3b3036327225202cull,0x203232702540090aull,0x744c240920617262ull,0x30333534355f325full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,0x363639345f325f74ull,
0x622e646e61090a36ull,0x3632722509203233ull,0x3235327225202c31ull,0x323737373631202cull,
0x766f6d090a3b3531ull,0x722509203233752eull,0x0a3b30202c323632ull,0x71652e7074657309ull,
0x702509203233752eull,0x36327225202c3332ull,0x3236327225202c31ull,0x3332702540090a3bull,
0x4c24092061726220ull,0x343035355f325f74ull,0x6c3c2f2f200a3b32ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x3334313120656e69ull,0x6c2064616568202cull,
0x242064656c656261ull,0x3639345f325f744cull,0x636f6c2e090a3636ull,0x3009363932093509ull,
0x636f6c2e646c090aull,0x09203436752e6c61ull,0x5b202c3032647225ull,0x635f616475635f5full,
0x5f6e6572646c6968ull,0x090a3b5d302b3233ull,0x203436622e6c6873ull,0x202c313264722509ull,
0x34202c3032647225ull,0x2e726873090a3b30ull,0x6472250920343675ull,0x32647225202c3232ull,
0x090a3b3635202c31ull,0x2e3233752e747663ull,0x3272250920343675ull,0x32647225202c3336ull,
0x2e646e61090a3b32ull,0x3272250920323362ull,0x36327225202c3436ull,0x090a3b3531202c33ull,
0x203233622e6c6873ull,0x202c353632722509ull,0x38202c3436327225ull,0x622e6c6873090a3bull,
0x3632722509203233ull,0x3235327225202c36ull,0x73090a3b3432202cull,0x09203233752e7268ull,
0x25202c3736327225ull,0x3432202c36363272ull,0x33622e726f090a3bull,0x3836327225092032ull,
0x2c3536327225202cull,0x0a3b373632722520ull,0x3436622e6c687309ull,0x2c33326472250920ull,
0x202c303264722520ull,0x726873090a3b3834ull,0x722509203436752eull,0x647225202c343264ull,
0x0a3b3635202c3332ull,0x3233752e74766309ull,0x722509203436752eull,0x647225202c393632ull,
0x646e61090a3b3432ull,0x722509203233622eull,0x327225202c303732ull,0x3b303432202c3336ull,
0x33622e6c6873090aull,0x3137327225092032ull,0x2c3037327225202cull,0x2e726f090a3b3420ull,
0x3272250920323362ull,0x36327225202c3237ull,0x3137327225202c39ull,0x622e6c6873090a3bull,
0x3732722509203233ull,0x3237327225202c33ull,0x6f090a3b3631202cull,0x2509203233622e72ull,
0x327225202c323172ull,0x37327225202c3836ull,0x636f6c2e090a3b33ull,0x0936333231093509ull,
0x752e617262090a30ull,0x5f744c240920696eull,0x240a3b3835325f32ull,0x3035355f325f744cull,
0x3c2f2f200a3a3234ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x34313120656e696cull,0x2064616568202c33ull,0x2064656c6562616cull,0x39345f325f744c24ull,
0x766f6d090a363636ull,0x722509203233732eull,0x3b3736202c373031ull,0x355f325f744c240aull,
0x2f200a3a30333534ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x616568202c333431ull,0x656c6562616c2064ull,0x5f325f744c242064ull,
0x6d090a3636363934ull,0x09203233752e766full,0x36202c3437327225ull,0x70746573090a3b37ull,
0x203233732e656e2eull,0x25202c3432702509ull,0x7225202c37303172ull,0x2540090a3b343732ull,
0x2061726220343270ull,0x355f325f744c2409ull,0x2f200a3b34353535ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x616568202c333431ull,
0x656c6562616c2064ull,0x5f325f744c242064ull,0x6c090a3636363934ull,0x2e6c61636f6c2e64ull,
0x6472250920343675ull,0x635f5f5b202c3032ull,0x6c6968635f616475ull,0x2b32335f6e657264ull,
0x646e61090a3b5d30ull,0x722509203436622eull,0x647225202c353264ull,0x34313832202c3032ull,
0x3333393935393437ull,0x6f6d090a3b303434ull,0x2509203436752e76ull,0x3b30202c36326472ull,
0x652e70746573090aull,0x2509203436752e71ull,0x647225202c353270ull,0x32647225202c3532ull,
0x32702540090a3b36ull,0x2409206172622035ull,0x3036355f325f744cull,0x3c2f2f200a3b3636ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x34313120656e696cull,
0x2064616568202c33ull,0x2064656c6562616cull,0x39345f325f744c24ull,0x6f6c2e090a363636ull,
0x0936393209350963ull,0x622e6c6873090a30ull,0x3264722509203436ull,0x3032647225202c37ull,
0x73090a3b3631202cull,0x09203436752e7268ull,0x25202c3832647225ull,0x3635202c37326472ull,
0x752e747663090a3bull,0x09203436752e3233ull,0x25202c3537327225ull,0x73090a3b38326472ull,
0x09203436622e6c68ull,0x25202c3932647225ull,0x3233202c30326472ull,0x752e726873090a3bull,
0x3364722509203436ull,0x3932647225202c30ull,0x63090a3b3635202cull,0x752e3233752e7476ull,
0x3732722509203436ull,0x3033647225202c36ull,0x622e646e61090a3bull,0x3732722509203233ull,
0x3537327225202c37ull,0x73090a3b3531202cull,0x09203233622e6c68ull,0x25202c3837327225ull,
0x3b38202c37373272ull,0x3233622e726f090aull,0x2c39373272250920ull,0x202c363732722520ull,
0x090a3b3837327225ull,0x203233622e646e61ull,0x202c303832722509ull,0x32202c3537327225ull,
0x6c6873090a3b3034ull,0x722509203233622eull,0x327225202c313832ull,0x090a3b34202c3038ull,
0x203233622e6c6873ull,0x202c323832722509ull,0x32202c3335327225ull,0x2e726873090a3b34ull,
0x3272250920323375ull,0x38327225202c3338ull,0x090a3b3432202c32ull,0x09203233622e726full,
0x25202c3438327225ull,0x7225202c31383272ull,0x6873090a3b333832ull,0x2509203233622e6cull,
0x7225202c35383272ull,0x3b3631202c343832ull,0x3233622e726f090aull,0x202c323172250920ull,
0x25202c3937327225ull,0x2e090a3b35383272ull,0x3231093509636f6cull,0x7262090a30093834ull,
0x240920696e752e61ull,0x3835325f325f744cull,0x5f325f744c240a3bull,0x200a3a3636303635ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x6568202c33343131ull,0x6c6562616c206461ull,0x325f744c24206465ull,0x090a36363639345full,
0x203233732e766f6dull,0x202c373031722509ull,0x5f744c240a3b3137ull,0x3a34353535355f32ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x202c333431312065ull,0x62616c2064616568ull,0x744c242064656c65ull,0x36363639345f325full,
0x33752e766f6d090aull,0x3638327225092032ull,0x73090a3b3137202cull,0x732e656e2e707465ull,
0x3632702509203233ull,0x2c3730317225202cull,0x0a3b363832722520ull,0x6220363270254009ull,
0x5f744c2409206172ull,0x3b38373536355f32ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x202c333431312065ull,0x62616c2064616568ull,
0x744c242064656c65ull,0x36363639345f325full,0x33622e6c6873090aull,0x3738327225092032ull,
0x2c3435327225202cull,0x6873090a3b343220ull,0x2509203233752e72ull,0x7225202c38383272ull,
0x3b3432202c373832ull,0x636f6c2e646c090aull,0x09203436752e6c61ull,0x5b202c3032647225ull,
0x635f616475635f5full,0x5f6e6572646c6968ull,0x090a3b5d302b3233ull,0x203233752e766f6dull,
0x202c393832722509ull,0x2e746573090a3b30ull,0x752e3233752e656eull,0x3932722509203233ull,
0x3838327225202c30ull,0x3b3938327225202cull,0x33732e67656e090aull,0x3139327225092032ull,
0x3b3039327225202cull,0x36752e766f6d090aull,0x3133647225092034ull,0x3b3032647225202cull,
0x36752e726873090aull,0x3233647225092034ull,0x2c3133647225202cull,0x7663090a3b383420ull,
0x36752e3233752e74ull,0x3239327225092034ull,0x3b3233647225202cull,0x33622e646e61090aull,
0x3339327225092032ull,0x2c3239327225202cull,0x0a3b353335353620ull,0x3233752e766f6d09ull,
0x2c34393272250920ull,0x746573090a3b3020ull,0x2e3233752e656e2eull,0x3272250920323375ull,
0x39327225202c3539ull,0x3439327225202c33ull,0x732e67656e090a3bull,0x3932722509203233ull,
0x3539327225202c36ull,0x33622e726f090a3bull,0x3739327225092032ull,0x2c3139327225202cull,
0x0a3b363932722520ull,0x3233752e766f6d09ull,0x2c38393272250920ull,0x746573090a3b3020ull,
0x3233732e71652e70ull,0x202c373270250920ull,0x25202c3739327225ull,0x40090a3b38393272ull,
0x6172622037327025ull,0x5f325f744c240920ull,0x200a3b3039303735ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x6568202c33343131ull,
0x6c6562616c206461ull,0x325f744c24206465ull,0x090a36363639345full,0x32093509636f6c2eull,
0x6873090a30093639ull,0x2509203436622e6cull,0x7225202c33336472ull,0x0a3b38202c303264ull,
0x3436752e72687309ull,0x2c34336472250920ull,0x202c333364722520ull,0x747663090a3b3635ull,
0x3436752e3233752eull,0x2c39393272250920ull,0x0a3b343364722520ull,0x3233622e646e6109ull,
0x2c30303372250920ull,0x202c383832722520ull,0x6c6873090a3b3531ull,0x722509203233622eull,
0x337225202c313033ull,0x090a3b38202c3030ull,0x09203233622e726full,0x25202c3230337225ull,
0x7225202c39393272ull,0x6f6d090a3b313033ull,0x2509203436752e76ull,0x7225202c35336472ull,
0x6873090a3b303264ull,0x2509203436752e72ull,0x7225202c36336472ull,0x3b3635202c353364ull,
0x33752e747663090aull,0x2509203436752e32ull,0x7225202c33303372ull,0x6e61090a3b363364ull,
0x2509203233622e64ull,0x7225202c34303372ull,0x303432202c383832ull,0x622e6c6873090a3bull,
0x3033722509203233ull,0x3430337225202c35ull,0x726f090a3b34202cull,0x722509203233622eull,
0x337225202c363033ull,0x30337225202c3330ull,0x2e6c6873090a3b35ull,0x3372250920323362ull,
0x30337225202c3730ull,0x090a3b3631202c36ull,0x09203233622e726full,0x7225202c32317225ull,
0x337225202c323033ull,0x6f6c2e090a3b3730ull,0x3935323109350963ull,0x2e617262090a3009ull,
0x744c240920696e75ull,0x0a3b3835325f325full,0x37355f325f744c24ull,0x2f2f200a3a303930ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x313120656e696c20ull,
0x64616568202c3334ull,0x64656c6562616c20ull,0x345f325f744c2420ull,0x6f6d090a36363639ull,
0x2509203233732e76ull,0x3438202c37303172ull,0x5f325f744c240a3bull,0x200a3a3837353635ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x6568202c33343131ull,0x6c6562616c206461ull,0x325f744c24206465ull,0x090a36363639345full,
0x203233752e766f6dull,0x202c383033722509ull,0x746573090a3b3438ull,0x3233732e656e2e70ull,
0x202c383270250920ull,0x25202c3730317225ull,0x40090a3b38303372ull,0x6172622038327025ull,
0x5f325f744c240920ull,0x200a3b3230363735ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x6568202c33343131ull,0x6c6562616c206461ull,
0x325f744c24206465ull,0x090a36363639345full,0x203233622e646e61ull,0x202c393033722509ull,
0x2d202c3435327225ull,0x6f6d090a3b363532ull,0x2509203233752e76ull,0x3b30202c30313372ull,
0x652e70746573090aull,0x2509203233752e71ull,0x337225202c393270ull,0x31337225202c3930ull,
0x32702540090a3b30ull,0x2409206172622039ull,0x3138355f325f744cull,0x3c2f2f200a3b3431ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x34313120656e696cull,
0x2064616568202c33ull,0x2064656c6562616cull,0x39345f325f744c24ull,0x6f6c2e090a363636ull,
0x0936393209350963ull,0x752e766f6d090a30ull,0x3133722509203233ull,0x3435327225202c31ull,
0x752e726873090a3bull,0x3133722509203233ull,0x3131337225202c32ull,0x61090a3b3432202cull,
0x09203233622e646eull,0x25202c3331337225ull,0x3531202c32313372ull,0x622e6c6873090a3bull,
0x3133722509203233ull,0x3331337225202c34ull,0x6873090a3b38202cull,0x2509203233622e6cull,
0x7225202c35313372ull,0x3b3631202c343532ull,0x33752e726873090aull,0x3631337225092032ull,
0x2c3531337225202cull,0x726f090a3b343220ull,0x722509203233622eull,0x337225202c373133ull,
0x31337225202c3431ull,0x2e646e61090a3b36ull,0x3372250920323362ull,0x31337225202c3831ull,
0x0a3b303432202c32ull,0x3233622e6c687309ull,0x2c39313372250920ull,0x202c383133722520ull,
0x2e6c6873090a3b34ull,0x3372250920323362ull,0x35327225202c3032ull,0x73090a3b38202c34ull,
0x09203233752e7268ull,0x25202c3132337225ull,0x3432202c30323372ull,0x33622e726f090a3bull,
0x3232337225092032ull,0x2c3931337225202cull,0x0a3b313233722520ull,0x3233622e6c687309ull,
0x2c33323372250920ull,0x202c323233722520ull,0x2e726f090a3b3631ull,0x3172250920323362ull,
0x3731337225202c32ull,0x3b3332337225202cull,0x3509636f6c2e090aull,0x0a30093037323109ull,
0x696e752e61726209ull,0x5f325f744c240920ull,0x744c240a3b383532ull,0x34313138355f325full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,0x363639345f325f74ull,
0x732e766f6d090a36ull,0x3031722509203233ull,0x240a3b3633202c37ull,0x3637355f325f744cull,
0x3c2f2f200a3a3230ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x34313120656e696cull,0x2064616568202c33ull,0x2064656c6562616cull,0x39345f325f744c24ull,
0x766f6d090a363636ull,0x722509203233752eull,0x3b3633202c343233ull,0x6e2e70746573090aull,
0x2509203233732e65ull,0x317225202c303370ull,0x32337225202c3730ull,0x33702540090a3b34ull,
0x2409206172622030ull,0x3339355f325f744cull,0x3c2f2f200a3b3439ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x34313120656e696cull,0x2064616568202c33ull,
0x2064656c6562616cull,0x39345f325f744c24ull,0x646e61090a363636ull,0x722509203233622eull,
0x327225202c353233ull,0x37373631202c3535ull,0x6d090a3b35313237ull,0x09203233752e766full,
0x30202c3632337225ull,0x2e70746573090a3bull,0x09203233752e7165ull,0x7225202c31337025ull,
0x337225202c353233ull,0x702540090a3b3632ull,0x0920617262203133ull,0x39355f325f744c24ull,
0x2f2f200a3b343933ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x313120656e696c20ull,0x64616568202c3334ull,0x64656c6562616c20ull,0x345f325f744c2420ull,
0x6c2e090a36363639ull,0x363932093509636full,0x2e6c6873090a3009ull,0x3372250920323362ull,
0x35327225202c3732ull,0x73090a3b38202c35ull,0x09203233752e7268ull,0x25202c3832337225ull,
0x3432202c37323372ull,0x622e646e61090a3bull,0x3233722509203233ull,0x3832337225202c39ull,
0x73090a3b3531202cull,0x09203233622e6c68ull,0x25202c3033337225ull,0x3b38202c39323372ull,
0x33622e6c6873090aull,0x3133337225092032ull,0x2c3535327225202cull,0x6873090a3b343220ull,
0x2509203233752e72ull,0x7225202c32333372ull,0x3b3432202c313333ull,0x3233622e726f090aull,
0x2c33333372250920ull,0x202c303333722520ull,0x090a3b3233337225ull,0x203233622e646e61ull,
0x202c343333722509ull,0x32202c3832337225ull,0x6c6873090a3b3034ull,0x722509203233622eull,
0x337225202c353333ull,0x090a3b34202c3433ull,0x203233622e6c6873ull,0x202c363333722509ull,
0x31202c3535327225ull,0x2e726873090a3b36ull,0x3372250920323375ull,0x33337225202c3733ull,
0x090a3b3432202c36ull,0x09203233622e726full,0x25202c3833337225ull,0x7225202c35333372ull,
0x6873090a3b373333ull,0x2509203233622e6cull,0x7225202c39333372ull,0x3b3631202c383333ull,
0x3233622e726f090aull,0x202c323172250920ull,0x25202c3333337225ull,0x2e090a3b39333372ull,
0x3231093509636f6cull,0x7262090a30093138ull,0x240920696e752e61ull,0x3835325f325f744cull,
0x5f325f744c240a3bull,0x240a3a3439333935ull,0x3638355f325f744cull,0x3c2f2f200a3a3632ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x34313120656e696cull,
0x2064616568202c33ull,0x2064656c6562616cull,0x39345f325f744c24ull,0x6f6c2e090a363636ull,
0x3638323109350963ull,0x2e766f6d090a3009ull,0x3172250920323373ull,0x240a3b31202c3630ull,
0x3835325f325f744cull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,
0x363639345f325f74ull,0x09636f6c2e090a36ull,0x3009373832310935ull,0x33752e766f6d090aull,
0x3034337225092032ull,0x6573090a3b30202cull,0x33732e656e2e7074ull,0x2c32337025092032ull,
0x202c363031722520ull,0x090a3b3034337225ull,0x7262203233702540ull,0x325f744c24092061ull,
0x0a3b30353639355full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x68202c3334313120ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a36363639345f32ull,0x2031327025214009ull,0x744c240920617262ull,0x38313430365f325full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x2c3334313120656eull,0x616c206461656820ull,0x4c242064656c6562ull,0x363639345f325f74ull,
0x2e70746573090a36ull,0x09203233732e656eull,0x7225202c33337025ull,0x317225202c393532ull,
0x702540090a3b3730ull,0x0920617262203333ull,0x30365f325f744c24ull,0x2f2f200a3b303339ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x313120656e696c20ull,
0x64616568202c3334ull,0x64656c6562616c20ull,0x345f325f744c2420ull,0x6c2e090a36363639ull,
0x393231093509636full,0x646e61090a300936ull,0x722509203233622eull,0x317225202c313433ull,
0x3533353536202c32ull,0x722e747663090a3bull,0x33752e3233662e6eull,0x2c31346625092032ull,
0x0a3b313433722520ull,0x3233752e72687309ull,0x2c32343372250920ull,0x31202c3231722520ull,
0x2e747663090a3b36ull,0x752e3233662e6e72ull,0x3234662509203233ull,0x3b3234337225202cull,
0x33662e766f6d090aull,0x2c33346625092032ull,0x3030303030663020ull,0x202020203b303030ull,
0x6d090a30202f2f09ull,0x09203233662e766full,0x6630202c34346625ull,0x3030303030303030ull,
0x2f2f09202020203bull,0x2e786574090a3020ull,0x33752e34762e6432ull,0x257b203233662e32ull,
0x3372252c33343372ull,0x35343372252c3434ull,0x2c7d36343372252cull,0x78657465646f6e5bull,
0x252c313466257b2cull,0x333466252c323466ull,0x3b5d7d343466252cull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x202c333431312065ull,
0x62616c2064616568ull,0x744c242064656c65ull,0x36363639345f325full,0x3509636f6c2e090aull,
0x090a300935373309ull,0x203233732e766f6dull,0x202c373433722509ull,0x090a3b3334337225ull,
0x203233732e766f6dull,0x202c383433722509ull,0x090a3b3634337225ull,0x31093509636f6c2eull,
0x73090a3009363932ull,0x2e6c61636f6c2e74ull,0x5f5f5b0920323375ull,0x646f6e5f61647563ull,
0x2c5d302b36315f65ull,0x0a3b373433722520ull,0x61636f6c2e747309ull,0x5b09203233752e6cull,
0x6e5f616475635f5full,0x312b36315f65646full,0x34337225202c5d32ull,0x636f6c2e090a3b38ull,
0x0937393231093509ull,0x622e6c6873090a30ull,0x3433722509203233ull,0x3834337225202c39ull,
0x73090a3b3631202cull,0x09203233752e7268ull,0x25202c3035337225ull,0x3432202c39343372ull,
0x622e6c6873090a3bull,0x3533722509203233ull,0x3035337225202c31ull,0x6873090a3b38202cull,
0x2509203233622e6cull,0x7225202c32353372ull,0x3b3432202c383433ull,0x33752e726873090aull,
0x3335337225092032ull,0x2c3235337225202cull,0x726f090a3b343220ull,0x722509203233622eull,
0x337225202c343533ull,0x35337225202c3135ull,0x2e6c6873090a3b33ull,0x3372250920323362ull,
0x34337225202c3535ull,0x73090a3b38202c38ull,0x09203233752e7268ull,0x25202c3635337225ull,
0x3432202c35353372ull,0x622e6c6873090a3bull,0x3533722509203233ull,0x3635337225202c37ull,
0x6f090a3b3631202cull,0x2509203233622e72ull,0x7225202c38353372ull,0x337225202c343533ull,
0x627573090a3b3735ull,0x722509203233732eull,0x35337225202c3338ull,0x73090a3b31202c38ull,
0x752e656e2e707465ull,0x3433702509203233ull,0x202c31317225202cull,0x40090a3b32317225ull,
0x6172622034337025ull,0x5f325f744c240920ull,0x200a3b3236313036ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x6568202c33343131ull,
0x6c6562616c206461ull,0x325f744c24206465ull,0x090a36363639345full,0x61626f6c672e646cull,
0x2509203631752e6cull,0x72255b202c353872ull,0x0a3b5d36312b3464ull,0x3233752e766f6d09ull,
0x2c39353372250920ull,0x746573090a3b3020ull,0x3233752e71652e70ull,0x202c353370250920ull,
0x7225202c35387225ull,0x2540090a3b393533ull,0x2061726220353370ull,0x365f325f744c2409ull,
0x2f200a3b38393631ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x616568202c333431ull,0x656c6562616c2064ull,0x5f325f744c242064ull,
0x2e090a3636363934ull,0x3331093509636f6cull,0x6873090a30093930ull,0x2509203233622e6cull,
0x7225202c30363372ull,0x0a3b38202c373433ull,0x3233752e72687309ull,0x202c353372250920ull,
0x32202c3036337225ull,0x2e6c6873090a3b34ull,0x3372250920323362ull,0x34337225202c3136ull,
0x090a3b3432202c37ull,0x203233752e726873ull,0x25202c3733722509ull,0x3432202c31363372ull,
0x622e6c6873090a3bull,0x3633722509203233ull,0x3734337225202c32ull,0x73090a3b3631202cull,
0x09203233752e7268ull,0x7225202c39337225ull,0x3b3432202c323633ull,0x33622e646e61090aull,
0x2c30347225092032ull,0x31202c3533722520ull,0x2e646e61090a3b35ull,0x3472250920323362ull,
0x2c35337225202c31ull,0x73090a3b30343220ull,0x09203233622e6c68ull,0x7225202c32347225ull,
0x090a3b38202c3034ull,0x203233622e6c6873ull,0x25202c3334722509ull,0x0a3b34202c313472ull,
0x203233622e726f09ull,0x25202c3434722509ull,0x337225202c323472ull,0x622e726f090a3b37ull,
0x3534722509203233ull,0x202c33347225202cull,0x73090a3b39337225ull,0x09203233622e6c68ull,
0x7225202c36347225ull,0x0a3b3631202c3534ull,0x203233622e726f09ull,0x25202c3734722509ull,
0x347225202c343472ull,0x2e646e61090a3b36ull,0x3372250920323362ull,0x37347225202c3336ull,
0x3b3533353536202cull,0x6e722e747663090aull,0x3233752e3233662eull,0x202c353466250920ull,
0x090a3b3336337225ull,0x203233752e726873ull,0x202c343633722509ull,0x3631202c37347225ull,
0x722e747663090a3bull,0x33752e3233662e6eull,0x2c36346625092032ull,0x0a3b343633722520ull,
0x3233662e766f6d09ull,0x202c373466250920ull,0x3030303030306630ull,0x09202020203b3030ull,
0x6f6d090a30202f2full,0x2509203233662e76ull,0x306630202c383466ull,0x3b30303030303030ull,
0x202f2f0920202020ull,0x322e786574090a30ull,0x3233752e34762e64ull,0x72257b203233662eull,
0x363372252c353633ull,0x2c37363372252c36ull,0x5b2c7d3836337225ull,0x2c78657465646f6eull,
0x66252c353466257bull,0x2c373466252c3634ull,0x0a3b5d7d38346625ull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x68202c3334313120ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a36363639345f32ull,0x093509636f6c2e09ull,
0x6d090a3009353733ull,0x09203233732e766full,0x7225202c30327225ull,0x6f6d090a3b353633ull,
0x2509203233732e76ull,0x7225202c39363372ull,0x6c2e090a3b383633ull,0x303331093509636full,
0x2e7473090a300939ull,0x33752e6c61636f6cull,0x75635f5f5b092032ull,0x5f65646f6e5f6164ull,
0x25202c5d302b3631ull,0x7473090a3b303272ull,0x752e6c61636f6c2eull,0x635f5f5b09203233ull,
0x65646f6e5f616475ull,0x2c5d32312b36315full,0x0a3b393633722520ull,0x093509636f6c2e09ull,
0x090a300930313331ull,0x203233622e6c6873ull,0x202c303733722509ull,0x31202c3936337225ull,
0x2e726873090a3b36ull,0x3372250920323375ull,0x37337225202c3137ull,0x090a3b3432202c30ull,
0x203233622e6c6873ull,0x202c323733722509ull,0x38202c3137337225ull,0x622e6c6873090a3bull,
0x3733722509203233ull,0x3936337225202c33ull,0x73090a3b3432202cull,0x09203233752e7268ull,
0x25202c3437337225ull,0x3432202c33373372ull,0x33622e726f090a3bull,0x3537337225092032ull,
0x2c3237337225202cull,0x0a3b343733722520ull,0x3233622e6c687309ull,0x2c36373372250920ull,
0x202c393633722520ull,0x2e726873090a3b38ull,0x3372250920323375ull,0x37337225202c3737ull,
0x090a3b3432202c36ull,0x203233622e6c6873ull,0x202c383733722509ull,0x31202c3737337225ull,
0x622e726f090a3b36ull,0x3733722509203233ull,0x3537337225202c39ull,0x3b3837337225202cull,
0x33732e646461090aull,0x3038337225092032ull,0x202c35387225202cull,0x090a3b3937337225ull,
0x203233732e627573ull,0x25202c3338722509ull,0x3b31202c30383372ull,0x365f325f744c240aull,
0x2f200a3a38393631ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x616568202c333431ull,0x656c6562616c2064ull,0x5f325f744c242064ull,
0x6d090a3636363934ull,0x09203233732e766full,0x31202c3530317225ull,0x752e617262090a3bull,
0x5f744c240920696eull,0x3b32363130365f32ull,0x365f325f744c240aull,0x2f200a3a30333930ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x616568202c333431ull,0x656c6562616c2064ull,0x5f325f744c242064ull,0x2e090a3636363934ull,
0x3331093509636f6cull,0x6f6d090a30093631ull,0x2509203233732e76ull,0x3b31202c35303172ull,
0x6e752e617262090aull,0x325f744c24092069ull,0x0a3b32363130365full,0x30365f325f744c24ull,
0x2f2f200a3a383134ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x313120656e696c20ull,0x64616568202c3334ull,0x64656c6562616c20ull,0x345f325f744c2420ull,
0x6c2e090a36363639ull,0x323331093509636full,0x646461090a300931ull,0x722509203233732eull,
0x317225202c353031ull,0x240a3b31202c3530ull,0x3130365f325f744cull,0x3c2f2f200a3a3236ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x34313120656e696cull,
0x2064616568202c33ull,0x2064656c6562616cull,0x39345f325f744c24ull,0x766f6d090a363636ull,
0x722509203233732eull,0x3b3536202c373031ull,0x355f325f744c240aull,0x4c240a3a30353639ull,
0x323939345f325f74ull,0x6c3c2f2f200a3a32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x3334313120656e69ull,0x6c2064616568202cull,0x242064656c656261ull,
0x3639345f325f744cull,0x70746573090a3636ull,0x203233752e656e2eull,0x25202c3633702509ull,
0x367225202c323172ull,0x33702540090a3b35ull,0x2409206172622036ull,0x3639345f325f744cull,
0x42424c240a3b3636ull,0x7031315a5f5f3138ull,0x6e72654b746e6972ull,0x6374614d39506c65ull,
0x3950696f666e4968ull,0x6e656d6e67696c41ull,0x3553694b50635074ull,0x0a3a69696969695full,
0x093509636f6c2e09ull,0x090a300938323331ull,0x4c240a3b74697865ull,0x5a5f5f646e655744ull,
0x4b746e6972703131ull,0x4d39506c656e7265ull,0x6f666e4968637461ull,0x6e67696c41395069ull,
0x4b506350746e656dull,0x696969695f355369ull,0x2f2f207d090a3a69ull,0x69727031315a5f20ull,
0x6c656e72654b746eull,0x49686374614d3950ull,0x6c413950696f666eull,0x50746e656d6e6769ull,
0x695f3553694b5063ull,0x00000a0a69696969ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_10",(char*)__deviceText_$compute_10$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_10", (char*)__deviceText_$sm_10$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_10$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0x2e00b786,(char*)"e65a1a5d20ec83f3",(char*)"mummergpu.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x9fd0a505,&__elfEntries1};
# 2 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c" 2
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
# 3 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c" 2




struct __T20 {void *__par0;char *__par1;char *__par2;const int *__par3;const int *__par4;int __par5;int __par6;int __dummy_field;};




struct __T21 {struct MatchCoord *__par0;char *__par1;const int *__par2;const int *__par3;int __par4;int __par5;int __dummy_field;};




struct __T22 {MatchInfo *__par0;int __par1;Alignment *__par2;char *__par3;const int *__par4;const int *__par5;int __par6;int __par7;int __par8;int __par9;int __par10;int __dummy_field;};
static void __sti____cudaRegisterAll_44_tmpxft_00005366_00000000_4_mummergpu_cpp1_ii_nodetex(void) __attribute__((__constructor__));
void __device_stub__Z15mummergpuKernelPvPcS0_PKiS2_ii(void *__par0, char *__par1, char *__par2, const int *__par3, const int *__par4, const int __par5, const int __par6){auto struct __T20 *__T225;
*(void**)(void*)&__T225 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T225->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T225->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T225->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T225->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T225->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T225->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T225->__par6) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(void *, char *, char *, const int *, const int *, const int, const int))mummergpuKernel__entry)); (void)cudaLaunch(((char *)((void ( *)(void *, char *, char *, const int *, const int *, const int, const int))mummergpuKernel__entry))); };}
void mummergpuKernel__entry( void *__cuda_0,char *__cuda_1,char *__cuda_2,const int *__cuda_3,const int *__cuda_4,const int __cuda_5,const int __cuda_6)
# 711 "./mummergpu_kernel.cu"
{__device_stub__Z15mummergpuKernelPvPcS0_PKiS2_ii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 860 "./mummergpu_kernel.cu"
}
# 1 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c"
void __device_stub__Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii( struct MatchCoord *__par0, char *__par1, const int *__par2, const int *__par3, const int __par4, const int __par5) { auto struct __T21 *__T226;
*(void**)(void*)&__T226 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T226->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T226->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T226->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T226->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T226->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T226->__par5) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(struct MatchCoord *, char *, const int *, const int *, const int, const int))mummergpuRCKernel__entry)); (void)cudaLaunch(((char *)((void ( *)(struct MatchCoord *, char *, const int *, const int *, const int, const int))mummergpuRCKernel__entry))); }; }
void mummergpuRCKernel__entry( struct MatchCoord *__cuda_0,char *__cuda_1,const int *__cuda_2,const int *__cuda_3,const int __cuda_4,const int __cuda_5)
# 873 "./mummergpu_kernel.cu"
{__device_stub__Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);
# 1040 "./mummergpu_kernel.cu"
}
# 1 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c"
void __device_stub__Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii( MatchInfo *__par0, int __par1, Alignment *__par2, char *__par3, const int *__par4, const int *__par5, const int __par6, const int __par7, const int __par8, const int __par9, const int __par10) { auto struct __T22 *__T227;
*(void**)(void*)&__T227 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T227->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T227->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T227->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T227->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T227->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T227->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T227->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T227->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T227->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T227->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T227->__par10) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(MatchInfo *, int, Alignment *, char *, const int *, const int *, const int, const int, const int, const int, const int))printKernel__entry)); (void)cudaLaunch(((char *)((void ( *)(MatchInfo *, int, Alignment *, char *, const int *, const int *, const int, const int, const int, const int, const int))printKernel__entry))); }; }
void printKernel__entry( MatchInfo *__cuda_0,int __cuda_1,Alignment *__cuda_2,char *__cuda_3,const int *__cuda_4,const int *__cuda_5,const int __cuda_6,const int __cuda_7,const int __cuda_8,const int __cuda_9,const int __cuda_10)
# 1074 "./mummergpu_kernel.cu"
{__device_stub__Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10);
# 1328 "./mummergpu_kernel.cu"
}
# 1 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c"
# 10 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c"
static void __sti____cudaRegisterAll_44_tmpxft_00005366_00000000_4_mummergpu_cpp1_ii_nodetex(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(MatchInfo *, int, Alignment *, char *, const int *, const int *, const int, const int, const int, const int, const int))printKernel__entry), (char*)"_Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii", "_Z11printKernelP9MatchInfoiP9AlignmentPcPKiS5_iiiii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(struct MatchCoord *, char *, const int *, const int *, const int, const int))mummergpuRCKernel__entry), (char*)"_Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii", "_Z17mummergpuRCKernelP10MatchCoordPcPKiS3_ii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(void *, char *, char *, const int *, const int *, const int, const int))mummergpuKernel__entry), (char*)"_Z15mummergpuKernelPvPcS0_PKiS2_ii", "_Z15mummergpuKernelPvPcS0_PKiS2_ii", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&nodetex, 0, "nodetex", 2, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&childrentex, 0, "childrentex", 2, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&reftex, 0, "reftex", 1, 0, 0); __cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&qrytex, 0, "qrytex", 1, 0, 0); }
# 1 "/tmp/tmpxft_00005366_00000000-1_mummergpu.cudafe1.stub.c" 2

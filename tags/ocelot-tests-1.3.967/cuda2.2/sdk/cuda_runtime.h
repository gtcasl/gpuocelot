/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  Users and possessors of this source code 
 * are hereby granted a nonexclusive, royalty-free license to use this code 
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.   This source code is a "commercial item" as 
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer  software"  and "commercial computer software 
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein. 
 *
 * Any use of this source code in individual and commercial software must 
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */

#if !defined(__CUDA_RUNTIME_H__)
#define __CUDA_RUNTIME_H__

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "host_config.h"

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "builtin_types.h"
#include "channel_descriptor.h"
#include "cuda_runtime_api.h"
#include "driver_functions.h"
#include "host_defines.h"
#include "vector_functions.h"

#if defined(__CUDACC__)

#include "common_functions.h"
#include "cuda_texture_types.h"
#include "device_functions.h"
#include "device_launch_parameters.h"

#endif /* __CUDACC__ */

#if defined(__cplusplus)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/**
 * \ingroup CUDART_HIGHLEVEL
 * \brief \hl Configure a device launch
 *
 * Pushes \p size bytes of the argument pointed to by \p arg at \p offset
 * bytes from the start of the parameter passing area, which starts at
 * offset 0. The arguments are stored in the top of the execution stack.
 * \ref ::cudaSetupArgument(T,size_t) "cudaSetupArgument()" must be preceded
 * by a call to ::cudaConfigureCall().
 *
 * \param arg    - Argument to push for a kernel launch
 * \param offset - Offset in argument stack to push new arg
 *
 * \return
 * ::cudaSuccess
 * \notefnerr
 *
 * \sa ::cudaConfigureCall,
 * \ref ::cudaFuncGetAttributes(struct cudaFuncAttributes*, T*) "cudaFuncGetAttributes (C++ API)",
 * \ref ::cudaLaunch(T*) "cudaLaunch (C++ API)",
 * ::cudaSetDoubleForDevice,
 * ::cudaSetDoubleForHost,
 * \ref ::cudaSetupArgument(const void*, size_t, size_t) "cudaSetupArgument (C API)"
 */
template<class T>
__inline__ __host__ cudaError_t cudaSetupArgument(
  T      arg,
  size_t offset
)
{
  return cudaSetupArgument((const void*)&arg, sizeof(T), offset);
}

template<class T>
__inline__ __host__ cudaError_t cudaHostAlloc(
  T            **ptr,
  size_t         size,
  unsigned int   flags
)
{
  return cudaHostAlloc((void**)(void*)ptr, size, flags);
}

template<class T>
__inline__ __host__ cudaError_t cudaHostGetDevicePointer(
  T            **pDevice,
  void          *pHost,
  unsigned int  flags
)
{
  return cudaHostGetDevicePointer((void**)(void*)pDevice, pHost, flags);
}

template<class T>
__inline__ __host__ cudaError_t cudaMalloc(
  T      **devPtr,
  size_t   size
)
{
  return cudaMalloc((void**)(void*)devPtr, size);
}

template<class T>
__inline__ __host__ cudaError_t cudaMallocHost(
  T      **ptr,
  size_t   size
)
{
  return cudaMallocHost((void**)(void*)ptr, size);
}

template<class T>
__inline__ __host__ cudaError_t cudaMallocPitch(
  T      **devPtr,
  size_t  *pitch,
  size_t   width,
  size_t   height
)
{
  return cudaMallocPitch((void**)(void*)devPtr, pitch, width, height);
}

#if defined(__CUDACC__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/**
 * \addtogroup CUDART_HIGHLEVEL
 * @{
 */

static __inline__ __host__ cudaError_t cudaMemcpyToSymbol(
        char                *symbol,
  const void                *src,
        size_t               count,
        size_t               offset = 0,
        enum cudaMemcpyKind  kind   = cudaMemcpyHostToDevice
)
{
  return cudaMemcpyToSymbol((const char*)symbol, src, count, offset, kind);
}

template<class T>
__inline__ __host__ cudaError_t cudaMemcpyToSymbol(
  const T                   &symbol,
  const void                *src,
        size_t               count,
        size_t               offset = 0,
        enum cudaMemcpyKind  kind   = cudaMemcpyHostToDevice
)
{
  return cudaMemcpyToSymbol((const char*)&symbol, src, count, offset, kind);
}

static __inline__ __host__ cudaError_t cudaMemcpyToSymbolAsync(
        char                *symbol,
  const void                *src,
        size_t               count,
        size_t               offset,
        enum cudaMemcpyKind  kind,
        cudaStream_t         stream
)
{
  return cudaMemcpyToSymbolAsync((const char*)symbol, src, count, offset, kind, stream);
}

template<class T>
__inline__ __host__ cudaError_t cudaMemcpyToSymbolAsync(
  const T                   &symbol,
  const void                *src,
        size_t               count,
        size_t               offset,
        enum cudaMemcpyKind  kind,
        cudaStream_t         stream
)
{
  return cudaMemcpyToSymbolAsync((const char*)&symbol, src, count, offset, kind, stream);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __host__ cudaError_t cudaMemcpyFromSymbol(
  void                *dst,
  char                *symbol,
  size_t               count,
  size_t               offset = 0,
  enum cudaMemcpyKind  kind   = cudaMemcpyDeviceToHost
)
{
  return cudaMemcpyFromSymbol(dst, (const char*)symbol, count, offset, kind);
}

template<class T>
__inline__ __host__ cudaError_t cudaMemcpyFromSymbol(
        void                *dst,
  const T                   &symbol,
        size_t               count,
        size_t               offset = 0,
        enum cudaMemcpyKind  kind   = cudaMemcpyDeviceToHost
)
{
  return cudaMemcpyFromSymbol(dst, (const char*)&symbol, count, offset, kind);
}

static __inline__ __host__ cudaError_t cudaMemcpyFromSymbolAsync(
  void                *dst,
  char                *symbol,
  size_t               count,
  size_t               offset,
  enum cudaMemcpyKind  kind,
  cudaStream_t         stream
)
{
  return cudaMemcpyFromSymbolAsync(dst, (const char*)symbol, count, offset, kind, stream);
}

template<class T>
__inline__ __host__ cudaError_t cudaMemcpyFromSymbolAsync(
        void                *dst,
  const T                   &symbol,
        size_t               count,
        size_t               offset,
        enum cudaMemcpyKind  kind,
        cudaStream_t         stream
)
{
  return cudaMemcpyFromSymbolAsync(dst, (const char*)&symbol, count, offset, kind, stream);
}

static __inline__ __host__ cudaError_t cudaGetSymbolAddress(
  void **devPtr,
  char  *symbol
)
{
  return cudaGetSymbolAddress(devPtr, (const char*)symbol);
}

/**
 * \brief \hl Finds the address associated with a CUDA symbol
 *
 * Returns in \p *devPtr the address of symbol \p symbol on the device.
 * \p symbol can either be a variable that resides in global memory space, or
 * it can be a character string, naming a variable that resides in global
 * memory space. If \p symbol cannot be found, or if \p symbol is not declared
 * in the global memory space, \p *devPtr is unchanged and the error
 * ::cudaErrorInvalidSymbol is returned.
 *
 * \param devPtr - Return device pointer associated with symbol
 * \param symbol - Global variable or string symbol to search for
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidSymbol,
 * ::cudaErrorAddressOfConstant
 * \notefnerr
 *
 * \sa \ref ::cudaGetSymbolAddress(void**, const char*) "cudaGetSymbolAddress (C API)"
 * \ref ::cudaGetSymbolSize(size_t*, const T&) "cudaGetSymbolSize (C++ API)"
 */
template<class T>
__inline__ __host__ cudaError_t cudaGetSymbolAddress(
        void **devPtr,
  const T     &symbol
)
{
  return cudaGetSymbolAddress(devPtr, (const char*)&symbol);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __host__ cudaError_t cudaGetSymbolSize(
  size_t *size,
  char   *symbol
)
{
  return cudaGetSymbolSize(size, (const char*)symbol);
}

/**
 * \brief \hl Finds the size of the object associated with a CUDA symbol
 *
 * Returns in \p *size the size of symbol \p symbol. \p symbol can either be a
 * variable that resides in global or constant memory space, or it can be a
 * character string, naming a variable that resides in global or constant
 * memory space. If \p symbol cannot be found, or if \p symbol is not declared
 * in global or constant memory space, \p *size is unchanged and the error
 * ::cudaErrorInvalidSymbol is returned.
 *
 * \param size   - Size of object associated with symbol
 * \param symbol - Global variable or string symbol to find size of
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidSymbol
 * \notefnerr
 *
 * \sa \ref ::cudaGetSymbolAddress(void**, const T&) "cudaGetSymbolAddress (C++ API)"
 * \ref ::cudaGetSymbolSize(size_t*, const char*) "cudaGetSymbolSize (C API)"
 */
template<class T>
__inline__ __host__ cudaError_t cudaGetSymbolSize(
        size_t *size,
  const T      &symbol
)
{
  return cudaGetSymbolSize(size, (const char*)&symbol);
}

/** @} */ /* END CUDART_HIGHLEVEL */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/**
 * \addtogroup CUDART_HIGHLEVEL
 *
 * @{
 */

/**
 * \brief \hl Binds a memory area to a texture
 *
 * Binds \p size bytes of the memory area pointed to by \p devPtr to texture
 * reference \p tex. \p desc describes how the memory is interpreted when
 * fetching values from the texture. The \p offset parameter is an optional
 * byte offset as with the low-level
 * \ref ::cudaBindTexture(size_t*, const struct textureReference*, const void*, const struct cudaChannelFormatDesc*, size_t) "cudaBindTexture()"
 * function. Any memory previously bound to \p tex is unbound.
 *
 * \param offset - Offset in bytes
 * \param tex    - Texture to bind
 * \param devPtr - Memory area on device
 * \param desc   - Channel format
 * \param size   - Size of the memory area pointed to by devPtr
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidValue,
 * ::cudaErrorInvalidDevicePointer,
 * ::cudaErrorInvalidTexture
 * \notefnerr
 *
 * \sa \ref ::cudaCreateChannelDesc(void) "cudaCreateChannelDesc (C++ API)",
 * ::cudaGetChannelDesc, ::cudaGetTextureReference,
 * \ref ::cudaBindTexture(size_t*, const struct textureReference*, const void*, const struct cudaChannelFormatDesc*, size_t) "cudaBindTexture (C API)",
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, size_t) "cudaBindTexture (C++ API, inherited channel descriptor)",
 * \ref ::cudaBindTexture2D(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t, size_t, size_t) "cudaBindTexture2D (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*, const struct cudaChannelFormatDesc&) "cudaBindTextureToArray (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*) "cudaBindTextureToArray (C++ API, inherited channel descriptor)",
 * \ref ::cudaUnbindTexture(const struct texture< T, dim, readMode>&) "cudaUnbindTexture (C++ API)",
 * \ref ::cudaGetTextureAlignmentOffset(size_t*, const struct texture< T, dim, readMode >&) "cudaGetTextureAlignmentOffset (C++ API)"
 */
template<class T, int dim, enum cudaTextureReadMode readMode>
__inline__ __host__ cudaError_t cudaBindTexture(
        size_t                           *offset,
  const struct texture<T, dim, readMode> &tex,
  const void                             *devPtr,
  const struct cudaChannelFormatDesc     &desc,
        size_t                            size = UINT_MAX
)
{
  return cudaBindTexture(offset, &tex, devPtr, &desc, size);
}

/**
 * \brief \hl Binds a memory area to a texture
 *
 * Binds \p size bytes of the memory area pointed to by \p devPtr to texture
 * reference \p tex. The channel descriptor is inherited from the texture
 * reference type. The \p offset parameter is an optional byte offset as with
 * the low-level
 * ::cudaBindTexture(size_t*, const struct textureReference*, const void*, const struct cudaChannelFormatDesc*, size_t)
 * function. Any memory previously bound to \p tex is unbound.
 *
 * \param offset - Offset in bytes
 * \param tex    - Texture to bind
 * \param devPtr - Memory area on device
 * \param size   - Size of the memory area pointed to by devPtr
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidValue,
 * ::cudaErrorInvalidDevicePointer,
 * ::cudaErrorInvalidTexture
 * \notefnerr
 *
 * \sa \ref ::cudaCreateChannelDesc(void) "cudaCreateChannelDesc (C++ API),
 * ::cudaGetChannelDesc, ::cudaGetTextureReference,
 * \ref ::cudaBindTexture(size_t*, const struct textureReference*, const void*, const struct cudaChannelFormatDesc*, size_t) "cudaBindTexture (C API)",
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, size_t) "cudaBindTexture (C++ API, inherited channel descriptor)",
 * \ref ::cudaBindTexture2D(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t, size_t, size_t) "cudaBindTexture2D (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*, const struct cudaChannelFormatDesc&) "cudaBindTextureToArray (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*) "cudaBindTextureToArray (C++ API, inherited channel descriptor),
 * \ref ::cudaUnbindTexture(const struct texture<T, dim, readMode>&) "cudaUnbindTexture (C++ API)",
 * \ref ::cudaGetTextureAlignmentOffset(size_t*, const struct texture< T, dim, readMode>&) "cudaGetTextureAlignmentOffset (C++ API)"
 */
template<class T, int dim, enum cudaTextureReadMode readMode>
__inline__ __host__ cudaError_t cudaBindTexture(
        size_t                           *offset,
  const struct texture<T, dim, readMode> &tex,
  const void                             *devPtr,
        size_t                            size = UINT_MAX
)
{
  return cudaBindTexture(offset, tex, devPtr, tex.channelDesc, size);
}

/**
 * \brief \hl Binds a 2D memory area to a texture
 *
 * Binds the 2D memory area pointed to by \p devPtr to the
 * texture reference \p tex. The size of the area is constrained by
 * \p width in texel units, \p height in texel units, and \p pitch in byte
 * units. \p desc describes how the memory is interpreted when fetching values
 * from the texture. Any memory previously bound to \p tex is unbound.
 *
 * Since the hardware enforces an alignment requirement on texture base
 * addresses,
 * \ref ::cudaBindTexture2D(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t, size_t, size_t) "cudaBindTexture2D()"
 * returns in \p *offset a byte offset that
 * must be applied to texture fetches in order to read from the desired memory.
 * This offset must be divided by the texel size and passed to kernels that
 * read from the texture so they can be applied to the ::tex2D() function.
 * If the device memory pointer was returned from ::cudaMalloc(), the offset is
 * guaranteed to be 0 and NULL may be passed as the \p offset parameter.
 *
 * \param offset - Offset in bytes
 * \param tex    - Texture reference to bind
 * \param devPtr - 2D memory area on device
 * \param desc   - Channel format
 * \param width  - Width in texel units
 * \param height - Height in texel units
 * \param pitch  - Pitch in bytes
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidValue,
 * ::cudaErrorInvalidDevicePointer,
 * ::cudaErrorInvalidTexture
 * \notefnerr
 *
 * \sa \ref ::cudaCreateChannelDesc(void) "cudaCreateChannelDesc (C++ API),
 * ::cudaGetChannelDesc, ::cudaGetTextureReference,
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t) "cudaBindTexture (C++ API),
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, size_t) "cudaBindTexture (C++ API, inherited channel descriptor)",
 * \ref ::cudaBindTexture2D(size_t*, const struct textureReference*, const void*, const struct cudaChannelFormatDesc*, size_t, size_t, size_t) "cudaBindTexture2D (C API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*, const struct cudaChannelFormatDesc&) "cudaBindTextureToArray (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*) "cudaBindTextureToArray (C++ API, inherited channel descriptor),
 * \ref ::cudaUnbindTexture(const struct texture<T, dim, readMode>&) "cudaUnbindTexture (C++ API)",
 * \ref ::cudaGetTextureAlignmentOffset(size_t*, const struct texture< T, dim, readMode>&) "cudaGetTextureAlignmentOffset (C++ API)"
 */
template<class T, int dim, enum cudaTextureReadMode readMode>
__inline__ __host__ cudaError_t cudaBindTexture2D(
        size_t                           *offset,
  const struct texture<T, dim, readMode> &tex,
  const void                             *devPtr,
  const struct cudaChannelFormatDesc     &desc,
  size_t                                  width,
  size_t                                  height,
  size_t                                  pitch
)
{
  return cudaBindTexture2D( offset, &tex, devPtr, &desc, width, height, pitch);
}

/**
 * \brief \hl Binds an array to a texture
 *
 * Binds the CUDA array \p array to the texture reference \p tex.
 * \p desc describes how the memory is interpreted when fetching values from
 * the texture. Any CUDA array previously bound to \p tex is unbound.
 *
 * \param tex   - Texture to bind
 * \param array - Memory array on device
 * \param desc  - Channel format
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidValue,
 * ::cudaErrorInvalidDevicePointer,
 * ::cudaErrorInvalidTexture
 * \notefnerr
 *
 * \sa \ref ::cudaCreateChannelDesc(void) "cudaCreateChannelDesc (C++ API)",
 * ::cudaGetChannelDesc, ::cudaGetTextureReference,
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t) "cudaBindTexture (C++ API)",
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, size_t) "cudaBindTexture (C++ API, inherited channel descriptor)",
 * \ref ::cudaBindTexture2D(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t, size_t, size_t) "cudaBindTexture2D (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct textureReference*, const struct cudaArray*, const struct cudaChannelFormatDesc*) "cudaBindTextureToArray (C API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*) "cudaBindTextureToArray (C++ API, inherited channel descriptor)",
 * \ref ::cudaUnbindTexture(const struct texture< T, dim, readMode>&) "cudaUnbindTexture (C++ API)",
 * \ref ::cudaGetTextureAlignmentOffset(size_t*, const struct texture< T, dim, readMode >&) "cudaGetTextureAlignmentOffset (C++ API)"
 */
template<class T, int dim, enum cudaTextureReadMode readMode>
__inline__ __host__ cudaError_t cudaBindTextureToArray(
  const struct texture<T, dim, readMode> &tex,
  const struct cudaArray                 *array,
  const struct cudaChannelFormatDesc     &desc
)
{
  return cudaBindTextureToArray(&tex, array, &desc);
}

/**
 * \brief \hl Binds an array to a texture
 *
 * Binds the CUDA array \p array to the texture reference \p tex.
 * The channel descriptor is inherited from the CUDA array. Any CUDA array
 * previously bound to \p tex is unbound.
 *
 * \param tex   - Texture to bind
 * \param array - Memory array on device
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidValue,
 * ::cudaErrorInvalidDevicePointer,
 * ::cudaErrorInvalidTexture
 * \notefnerr
 *
 * \sa \ref ::cudaCreateChannelDesc(void) "cudaCreateChannelDesc (C++ API)",
 * ::cudaGetChannelDesc, ::cudaGetTextureReference,
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t) "cudaBindTexture (C++ API)",
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, size_t) "cudaBindTexture (C++ API, inherited channel descriptor)",
 * \ref ::cudaBindTexture2D(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t, size_t, size_t) "cudaBindTexture2D (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct textureReference*, const struct cudaArray*, const struct cudaChannelFormatDesc*) "cudaBindTextureToArray (C API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*, const struct cudaChannelFormatDesc&) "cudaBindTextureToArray (C++ API)",
 * \ref ::cudaUnbindTexture(const struct texture< T, dim, readMode>&) "cudaUnbindTexture (C++ API)",
 * \ref ::cudaGetTextureAlignmentOffset(size_t*, const struct texture< T, dim, readMode >&) "cudaGetTextureAlignmentOffset (C++ API)"
 */
template<class T, int dim, enum cudaTextureReadMode readMode>
__inline__ __host__ cudaError_t cudaBindTextureToArray(
  const struct texture<T, dim, readMode> &tex,
  const struct cudaArray                 *array
)
{
  struct cudaChannelFormatDesc desc;
  cudaError_t                  err = cudaGetChannelDesc(&desc, array);

  return err == cudaSuccess ? cudaBindTextureToArray(tex, array, desc) : err;
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/**
 * \brief \hl Unbinds a texture
 *
 * Unbinds the texture bound to \p tex.
 *
 * \param tex - Texture to unbind
 *
 * \return ::cudaSuccess
 * \notefnerr
 *
 * \sa \ref ::cudaCreateChannelDesc(void) "cudaCreateChannelDesc (C++ API)",
 * ::cudaGetChannelDesc, ::cudaGetTextureReference,
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t) "cudaBindTexture (C++ API)",
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, size_t) "cudaBindTexture (C++ API, inherited channel descriptor)",
 * \ref ::cudaBindTexture2D(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t, size_t, size_t) "cudaBindTexture2D (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*, const struct cudaChannelFormatDesc&) "cudaBindTextureToArray (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*) "cudaBindTextureToArray (C++ API, inherited channel descriptor)",
 * \ref ::cudaUnbindTexture(const struct textureReference*) "cudaUnbindTexture (C API)",
 * \ref ::cudaGetTextureAlignmentOffset(size_t*, const struct texture< T, dim, readMode >&) "cudaGetTextureAlignmentOffset (C++ API)"
 */
template<class T, int dim, enum cudaTextureReadMode readMode>
__inline__ __host__ cudaError_t cudaUnbindTexture(
  const struct texture<T, dim, readMode> &tex
)
{
  return cudaUnbindTexture(&tex);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/**
 * \brief \hl Get the alignment offset of a texture
 *
 * Returns in \p *offset the offset that was returned when texture reference
 * \p tex was bound.
 *
 * \param offset - Offset of texture reference in bytes
 * \param tex    - Texture to get offset of
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidTexture,
 * ::cudaErrorInvalidTextureBinding
 * \notefnerr
 *
 * \sa \ref ::cudaCreateChannelDesc(void) "cudaCreateChannelDesc (C++ API)",
 * ::cudaGetChannelDesc, ::cudaGetTextureReference,
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t) "cudaBindTexture (C++ API)",
 * \ref ::cudaBindTexture(size_t*, const struct texture< T, dim, readMode>&, const void*, size_t) "cudaBindTexture (C++ API, inherited channel descriptor)",
 * \ref ::cudaBindTexture2D(size_t*, const struct texture< T, dim, readMode>&, const void*, const struct cudaChannelFormatDesc&, size_t, size_t, size_t) "cudaBindTexture2D (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*, const struct cudaChannelFormatDesc&) "cudaBindTextureToArray (C++ API)",
 * \ref ::cudaBindTextureToArray(const struct texture< T, dim, readMode>&, const struct cudaArray*) "cudaBindTextureToArray (C++ API, inherited channel descriptor)",
 * \ref ::cudaUnbindTexture(const struct texture< T, dim, readMode>&) "cudaUnbindTexture (C++ API)",
 * \ref ::cudaGetTextureAlignmentOffset(size_t*, const struct textureReference*) "cudaGetTextureAlignmentOffset (C API)"
 */
template<class T, int dim, enum cudaTextureReadMode readMode>
__inline__ __host__ cudaError_t cudaGetTextureAlignmentOffset(
        size_t                           *offset,
  const struct texture<T, dim, readMode> &tex
)
{
  return cudaGetTextureAlignmentOffset(offset, &tex);
}

/** @} */ /* END CUDART_HIGHLEVEL */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/**
 * \ingroup CUDART_HIGHLEVEL
 * \brief \hl Launches a device function
 *
 * Launches the function \p entry on the device. The parameter \p entry can
 * either be a function that executes on the device, or it can be a character
 * string, naming a function that executes on the device. The parameter
 * specified by \p entry must be declared as a \p __global__ function.
 * \ref ::cudaLaunch(T*) "cudaLaunch()" must be preceded by a call to
 * ::cudaConfigureCall() since it pops the data that was pushed by
 * ::cudaConfigureCall() from the execution stack.
 *
 * \param entry - Device function pointer or char string naming device function
 * to execute
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidDeviceFunction,
 * ::cudaErrorInvalidConfiguration
 * \notefnerr
 *
 * \sa ::cudaConfigureCall,
 * \ref ::cudaFuncGetAttributes(struct cudaFuncAttributes*, T*) "cudaFuncGetAttributes (C++ API)",
 * \ref ::cudaLaunch(const char*) "cudaLaunch (C API)",
 * ::cudaSetDoubleForDevice,
 * ::cudaSetDoubleForHost,
 * \ref ::cudaSetupArgument(T,size_t) "cudaSetupArgument (C++ API)"
 */
template<class T>
__inline__ __host__ cudaError_t cudaLaunch(
  T *entry
)
{
  return cudaLaunch((const char*)entry);
}

/**
 * \ingroup CUDART_HIGHLEVEL
 * \brief \hl Find out attributes for a given function
 *
 * This function obtains the attributes of a function specified via \p entry.
 * The parameter \p entry can either be a function that executes on the
 * device, or it can be a character string, naming a function that executes on
 * the device. The parameter specified by \p entry must be declared as a
 * \p __global__ function. The fetched attributes are placed in \p attr. If
 * the specified function does not exist, then ::cudaErrorInvalidDeviceFunction
 * is returned.
 *
 * \param attr  - Return pointer to function's attributes
 * \param entry - Function to get attributes of
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInitializationError,
 * ::cudaErrorInvalidDeviceFunction
 * \notefnerr
 *
 * \sa ::cudaConfigureCall,
 * \ref ::cudaFuncGetAttributes(struct cudaFuncAttributes*, const char*) "cudaFuncGetAttributes (C API)",
 * \ref ::cudaLaunch(T*) "cudaLaunch (C++ API)",
 * ::cudaSetDoubleForDevice,
 * ::cudaSetDoubleForHost,
 * \ref ::cudaSetupArgument(T,size_t) "cudaSetupArgument (C++ API)"
 */
template<class T>
__inline__ __host__ cudaError_t cudaFuncGetAttributes(
  struct cudaFuncAttributes *attr,
  T *entry
)
{
  return cudaFuncGetAttributes(attr, (const char*)entry);
}

#endif /* __CUDACC__ */

#endif /* __cplusplus */

#endif /* !__CUDA_RUNTIME_H__ */

/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
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

#if !defined(__CUDA_GL_INTEROP_H__)
#define __CUDA_GL_INTEROP_H__

#include "builtin_types.h"
#include "host_defines.h"

#if defined(__APPLE__)

#include <OpenGL/gl.h>

#else /* __APPLE__ */

#include <GL/gl.h>

#endif /* __APPLE__ */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * \addtogroup CUDART_OPENGL OpenGL Interoperability
 * This section describes the OpenGL interoperability functions of the CUDA
 * runtime application programming interface.
 *
 * @{
 */

/**
 * \brief Sets the CUDA device for use with OpenGL interoperability
 *
 * Records \p device as the device on which the active host thread executes
 * the device code. Records the thread as using OpenGL interoperability. 
 * If the host thread has already initialized the CUDA runtime by
 * calling non-device management runtime functions or if there exists a CUDA 
 * driver context active on the host thread, then this call returns
 * ::cudaErrorSetOnActiveProcess.
 *
 * \param device - Device to use for OpenGL interoperability
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidDevice,
 * ::cudaErrorSetOnActiveProcess
 * \notefnerr
 *
 * \sa ::cudaGLRegisterBufferObject, ::cudaGLMapBufferObject,
 * ::cudaGLUnmapBufferObject, ::cudaGLUnregisterBufferObject,
 * ::cudaGLMapBufferObjectAsync, ::cudaGLUnmapBufferObjectAsync
 */
extern __host__ cudaError_t CUDARTAPI cudaGLSetGLDevice(int device);

/**
 * \brief Register an OpenGL texture or renderbuffer object
 *
 * Registers the texture or renderbuffer object specified by \p image for access by CUDA.  
 * \p target must match the type of the object.  
 * A handle to the registered object is returned as \p resource.  
 * The map flags \p flags specify the intended usage, as follows:
 * 
 * - ::cudaGraphicsMapFlagsNone: Specifies no hints about how this
 *   resource will be used. It is therefore assumed that this resource will be
 *   read from and written to by CUDA. This is the default value.
 * - ::cudaGraphicsMapFlagsReadOnly: Specifies that CUDA
 *   will not write to this resource.
 * - ::cudaGraphicsMapFlagsWriteDiscard: Specifies that
 *   CUDA will not read from this resource and will write over the
 *   entire contents of the resource, so none of the data previously
 *   stored in the resource will be preserved.
 *
 * The following image classes are currently disallowed:
 * - Textures with borders
 * - Multisampled renderbuffers
 *
 * \param resource - Pointer to the returned object handle
 * \param image    - name of texture or renderbuffer object to be registered
 * \param target   - Identifies the type of object specified by \p image, and must be one of 
 *                   ::GL_TEXTURE_2D, 
 *                   ::GL_TEXTURE_RECTANGLE, 
 *                   ::GL_TEXTURE_CUBE_MAP, 
 *                   ::GL_TEXTURE_3D, 
 *                   ::GL_TEXTURE_2D_ARRAY, or 
 *                   ::GL_RENDERBUFFER.
 * \param flags    - Map flags
 * 
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidDevice,
 * ::cudaErrorInvalidValue,
 * ::cudaErrorInvalidResourceHandle,
 * ::cudaErrorUnknown
 * \notefnerr
 *
 * \sa 
 * ::cudaGLSetGLDevice
 * ::cudaGraphicsUnregisterResource,
 * ::cudaGraphicsMapResources, 
 * ::cudaGraphicsSubResourceGetMappedArray
 */
extern __host__ cudaError_t CUDARTAPI cudaGraphicsGLRegisterImage(struct cudaGraphicsResource **resource, GLuint image, GLenum target, unsigned int flags);

/**
 * \brief Registers an OpenGL buffer object
 *
 * Registers the buffer object specified by \p buffer for access by
 * CUDA.  A handle to the registered object is returned as \p
 * resource.  The map flags \p flags specify the intended usage,
 * as follows:
 *
 * - ::cudaGraphicsMapFlagsNone: Specifies no hints about how this
 *   resource will be used. It is therefore assumed that this resource will be
 *   read from and written to by CUDA. This is the default value.
 * - ::cudaGraphicsMapFlagsReadOnly: Specifies that CUDA
 *   will not write to this resource.
 * - ::cudaGraphicsMapFlagsWriteDiscard: Specifies that
 *   CUDA will not read from this resource and will write over the
 *   entire contents of the resource, so none of the data previously
 *   stored in the resource will be preserved.
 *
 * \param resource - Pointer to the returned object handle
 * \param buffer   - name of buffer object to be registered
 * \param flags    - Map flags
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidDevice,
 * ::cudaErrorInvalidValue,
 * ::cudaErrorInvalidResourceHandle,
 * ::cudaErrorUnknown
 * \notefnerr
 *
 * \sa 
 * ::cudaGLCtxCreate, 
 * ::cudaGraphicsUnregisterResource,
 * ::cudaGraphicsMapResources,
 * ::cudaGraphicsResourceGetMappedPointer
 */
extern __host__ cudaError_t CUDARTAPI cudaGraphicsGLRegisterBuffer(struct cudaGraphicsResource **resource, GLuint buffer, unsigned int flags);

#ifdef _WIN32
#ifndef WGL_NV_gpu_affinity
typedef void* HGPUNV;
#endif

/**
 * \brief Gets the CUDA device associated with hGpu
 *
 * Returns the CUDA device associated with a hGpu, if applicable.
 *
 * \param device - Returns the device associated with hGpu, or -1 if hGpu is
 * not a compute device.
 * \param hGpu   - Handle to a GPU, as queried via WGL_NV_gpu_affinity()
 *
 * \return
 * ::cudaSuccess
 * \notefnerr
 *
 * \sa WGL_NV_gpu_affinity, ::cudaGLSetGLDevice
 */
extern __host__ cudaError_t CUDARTAPI cudaWGLGetDevice(int *device, HGPUNV hGpu);
#endif

/**
 * CUDA GL Map Flags
 */
enum cudaGLMapFlags
{
  cudaGLMapFlagsNone         = 0,  /**< Default; Assume resource can be read/written */
  cudaGLMapFlagsReadOnly     = 1,  /**< CUDA kernels will not write to this resource */
  cudaGLMapFlagsWriteDiscard = 2,  /**< CUDA kernels will only write to and will not read from this resource */
};

/**
 * \defgroup CUDART_OPENGL_DEPRECATED OpenGL Interoperability [DEPRECATED]
 * This section describes deprecated OpenGL interoperability functionality.
 *
 * @{
 */

/**
 * \brief Registers a buffer object for access by CUDA
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Registers the buffer object of ID \p bufObj for access by
 * CUDA. This function must be called before CUDA can map the buffer
 * object.  The OpenGL context used to create the buffer, or another
 * context from the same share group, must be bound to the current
 * thread when this is called.
 *
 * \param bufObj - Buffer object ID to register
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInitializationError
 * \notefnerr
 *
 * \sa ::cudaGraphicsGLRegisterBuffer
 */
extern __host__ cudaError_t CUDARTAPI cudaGLRegisterBufferObject(GLuint bufObj);

/**
 * \brief Maps a buffer object for access by CUDA
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Maps the buffer object of ID \p bufObj into the address space of
 * CUDA and returns in \p *devPtr the base pointer of the resulting
 * mapping.  The buffer must have previously been registered by
 * calling ::cudaGLRegisterBufferObject().  While a buffer is mapped
 * by CUDA, any OpenGL operation which references the buffer will
 * result in undefined behavior.  The OpenGL context used to create
 * the buffer, or another context from the same share group, must be
 * bound to the current thread when this is called.
 *
 * All streams in the current thread are synchronized with the current
 * GL context.
 *
 * \param devPtr - Returned device pointer to CUDA object
 * \param bufObj - Buffer object ID to map
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorMapBufferObjectFailed
 * \notefnerr
 *
 * \sa ::cudaGraphicsMapResources
 */
extern __host__ cudaError_t CUDARTAPI cudaGLMapBufferObject(void **devPtr, GLuint bufObj);

/**
 * \brief Unmaps a buffer object for access by CUDA
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Unmaps the buffer object of ID \p bufObj for access by CUDA.  When
 * a buffer is unmapped, the base address returned by
 * ::cudaGLMapBufferObject() is invalid and subsequent references to
 * the address result in undefined behavior.  The OpenGL context used
 * to create the buffer, or another context from the same share group,
 * must be bound to the current thread when this is called.
 *
 * All streams in the current thread are synchronized with the current
 * GL context.
 *
 * \param bufObj - Buffer object to unmap
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidDevicePointer,
 * ::cudaErrorUnmapBufferObjectFailed
 * \notefnerr
 *
 * \sa ::cudaGraphicsUnmapResources
 */
extern __host__ cudaError_t CUDARTAPI cudaGLUnmapBufferObject(GLuint bufObj);

/**
 * \brief Unregisters a buffer object for access by CUDA
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Unregisters the buffer object of ID \p bufObj for access by CUDA
 * and releases any CUDA resources associated with the buffer.  Once a
 * buffer is unregistered, it may no longer be mapped by CUDA.  The GL
 * context used to create the buffer, or another context from the
 * same share group, must be bound to the current thread when this is
 * called.
 *
 * \param bufObj - Buffer object to unregister
 *
 * \return
 * ::cudaSuccess
 * \notefnerr
 *
 * \sa ::cudaGraphicsUnregisterResource
 */
extern __host__ cudaError_t CUDARTAPI cudaGLUnregisterBufferObject(GLuint bufObj);

/**
 * \brief Set usage flags for mapping an OpenGL buffer
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Set flags for mapping the OpenGL buffer \p bufObj
 *
 * Changes to flags will take effect the next time \p bufObj is mapped.
 * The \p flags argument may be any of the following:
 *
 * - ::cudaGLMapFlagsNone: Specifies no hints about how this buffer will
 * be used. It is therefore assumed that this buffer will be read from and
 * written to by CUDA kernels. This is the default value.
 * - ::cudaGLMapFlagsReadOnly: Specifies that CUDA kernels which access this
 * buffer will not write to the buffer.
 * - ::cudaGLMapFlagsWriteDiscard: Specifies that CUDA kernels which access
 * this buffer will not read from the buffer and will write over the
 * entire contents of the buffer, so none of the data previously stored in
 * the buffer will be preserved.
 *
 * If \p bufObj has not been registered for use with CUDA, then
 * ::cudaErrorInvalidResourceHandle is returned. If \p bufObj is presently
 * mapped for access by CUDA, then ::cudaErrorUnknown is returned.
 *
 * \param bufObj    - Registered buffer object to set flags for
 * \param flags     - Parameters for buffer mapping
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidValue,
 * ::cudaErrorInvalidResourceHandle,
 * ::cudaErrorUnknown
 * \notefnerr
 *
 * \sa ::cudaGraphicsResourceSetMapFlags
 */
extern __host__ cudaError_t CUDARTAPI cudaGLSetBufferObjectMapFlags(GLuint bufObj, unsigned int flags); 

/**
 * \brief Maps a buffer object for access by CUDA
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Maps the buffer object of ID \p bufObj into the address space of
 * CUDA and returns in \p *devPtr the base pointer of the resulting
 * mapping.  The buffer must have previously been registered by
 * calling ::cudaGLRegisterBufferObject().  While a buffer is mapped
 * by CUDA, any OpenGL operation which references the buffer will
 * result in undefined behavior.  The OpenGL context used to create
 * the buffer, or another context from the same share group, must be
 * bound to the current thread when this is called.
 *
 * Stream /p stream is synchronized with the current GL context.
 *
 * \param devPtr - Returned device pointer to CUDA object
 * \param bufObj - Buffer object ID to map
 * \param stream - Stream to synchronize
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorMapBufferObjectFailed
 * \notefnerr
 *
 * \sa ::cudaGraphicsMapResources
 */
extern __host__ cudaError_t CUDARTAPI cudaGLMapBufferObjectAsync(void **devPtr, GLuint bufObj, cudaStream_t stream);

/**
 * \brief Unmaps a buffer object for access by CUDA
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Unmaps the buffer object of ID \p bufObj for access by CUDA.  When
 * a buffer is unmapped, the base address returned by
 * ::cudaGLMapBufferObject() is invalid and subsequent references to
 * the address result in undefined behavior.  The OpenGL context used
 * to create the buffer, or another context from the same share group,
 * must be bound to the current thread when this is called.
 *
 * Stream /p stream is synchronized with the current GL context.
 *
 * \param bufObj - Buffer object to unmap
 * \param stream - Stream to synchronize
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidDevicePointer,
 * ::cudaErrorUnmapBufferObjectFailed
 * \notefnerr
 *
 * \sa ::cudaGraphicsUnmapResources
 */
extern __host__ cudaError_t CUDARTAPI cudaGLUnmapBufferObjectAsync(GLuint bufObj, cudaStream_t stream);

/** @} */ /* END CUDART_OPENGL_DEPRECATED */

/** @} */ /* END CUDART_OPENGL */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __CUDA_GL_INTEROP_H__ */


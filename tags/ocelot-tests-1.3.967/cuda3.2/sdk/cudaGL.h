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

#ifndef CUDAGL_H
#define CUDAGL_H

/** 
 * CUDA API versioning support
 */
#if defined(CUDA_FORCE_API_VERSION)
    #if (CUDA_FORCE_API_VERSION == 3010)
        #define __CUDA_API_VERSION 3010
    #else
        #error "Unsupported value of CUDA_FORCE_API_VERSION"
    #endif
#else
    #define __CUDA_API_VERSION 3020
#endif /* CUDA_FORCE_API_VERSION */

#if defined(__CUDA_API_VERSION_INTERNAL) || __CUDA_API_VERSION >= 3020
    #define cuGLCtxCreate            cuGLCtxCreate_v2
    #define cuGLMapBufferObject      cuGLMapBufferObject_v2
    #define cuGLMapBufferObjectAsync cuGLMapBufferObjectAsync_v2
#endif /* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION >= 3020 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup CUDA_GL OpenGL Interoperability
 * \ingroup CUDA_DRIVER
 *
 * This section describes the OpenGL interoperability functions of the
 * low-level CUDA driver application programming interface.
 *
 * @{
 */

#if defined(_WIN32)
#if !defined(WGL_NV_gpu_affinity)
typedef void* HGPUNV;
#endif
#endif /* _WIN32 */

#if __CUDA_API_VERSION >= 3020
/**
 * \brief Create a CUDA context for interoperability with OpenGL
 *
 * Creates a new CUDA context, initializes OpenGL interoperability, and
 * associates the CUDA context with the calling thread. It must be called
 * before performing any other OpenGL interoperability operations. It may fail
 * if the needed OpenGL driver facilities are not available. For usage of the
 * \p Flags parameter, see ::cuCtxCreate().
 *
 * \param pCtx   - Returned CUDA context
 * \param Flags  - Options for CUDA context creation
 * \param device - Device on which to create the context
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_INVALID_VALUE,
 * ::CUDA_ERROR_OUT_OF_MEMORY
 * \notefnerr
 *
 * \sa ::cuCtxCreate, ::cuGLInit, ::cuGLMapBufferObject,
 * ::cuGLRegisterBufferObject, ::cuGLUnmapBufferObject,
 * ::cuGLUnregisterBufferObject, ::cuGLMapBufferObjectAsync,
 * ::cuGLUnmapBufferObjectAsync, ::cuGLSetBufferObjectMapFlags,
 * ::cuWGLGetDevice
 */
CUresult CUDAAPI cuGLCtxCreate(CUcontext *pCtx, unsigned int Flags, CUdevice device );
#endif /* __CUDA_API_VERSION >= 3020 */

/**
 * \brief Registers an OpenGL buffer object
 *
 * Registers the buffer object specified by \p buffer for access by
 * CUDA.  A handle to the registered object is returned as \p
 * pCudaResource.  The map flags \p Flags specify the intended usage,
 * as follows:
 *
 * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE: Specifies no hints about how this
 *   resource will be used. It is therefore assumed that this resource will be
 *   read from and written to by CUDA. This is the default value.
 * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY: Specifies that CUDA
 *   will not write to this resource.
 * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD: Specifies that
 *   CUDA will not read from this resource and will write over the
 *   entire contents of the resource, so none of the data previously
 *   stored in the resource will be preserved.
 *
 * \param pCudaResource - Pointer to the returned object handle
 * \param buffer - name of buffer object to be registered
 * \param Flags - Map flags
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_INVALID_HANDLE,
 * ::CUDA_ERROR_ALREADY_MAPPED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * \notefnerr
 *
 * \sa 
 * ::cuGLCtxCreate, 
 * ::cuGraphicsUnregisterResource,
 * ::cuGraphicsMapResources,
 * ::cuGraphicsResourceGetMappedPointer
 */
CUresult CUDAAPI cuGraphicsGLRegisterBuffer(CUgraphicsResource *pCudaResource, GLuint buffer, unsigned int Flags);

/**
 * \brief Register an OpenGL texture or renderbuffer object
 *
 * Registers the texture or renderbuffer object specified by \p image for access by CUDA.  
 * \p target must match the type of the object.  
 * A handle to the registered object is returned as \p pCudaResource.  
 * The map flags \p Flags specify the intended usage, as follows:
 *
 * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE: Specifies no hints about how this
 *   resource will be used. It is therefore assumed that this resource will be
 *   read from and written to by CUDA. This is the default value.
 * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY: Specifies that CUDA
 *   will not write to this resource.
 * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD: Specifies that
 *   CUDA will not read from this resource and will write over the
 *   entire contents of the resource, so none of the data previously
 *   stored in the resource will be preserved.
 *
 * The following image classes are currently disallowed:
 * - Textures with borders
 * - Multisampled renderbuffers
 *
 * \param pCudaResource - Pointer to the returned object handle
 * \param image - name of texture or renderbuffer object to be registered
 * \param target - Identifies the type of object specified by \p image, and must be one of 
 *                 ::GL_TEXTURE_2D, 
 *                 ::GL_TEXTURE_RECTANGLE, 
 *                 ::GL_TEXTURE_CUBE_MAP, 
 *                 ::GL_TEXTURE_3D, 
 *                 ::GL_TEXTURE_2D_ARRAY, or 
 *                 ::GL_RENDERBUFFER.
 * \param Flags - Map flags
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_INVALID_HANDLE,
 * ::CUDA_ERROR_ALREADY_MAPPED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * \notefnerr
 *
 * \sa 
 * ::cuGLCtxCreate, 
 * ::cuGraphicsUnregisterResource,
 * ::cuGraphicsMapResources,
 * ::cuGraphicsSubResourceGetMappedArray
 */
CUresult CUDAAPI cuGraphicsGLRegisterImage(CUgraphicsResource *pCudaResource, GLuint image, GLenum target, unsigned int Flags);

#ifdef _WIN32
/**
 * \brief Gets the CUDA device associated with hGpu
 *
 * Returns in \p *pDevice the CUDA device associated with a \p hGpu, if
 * applicable.
 *
 * \param pDevice - Device associated with hGpu
 * \param hGpu    - Handle to a GPU, as queried via ::WGL_NV_gpu_affinity()
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_INVALID_VALUE
 * \notefnerr
 *
 * \sa ::cuGLCtxCreate, ::cuGLInit, ::cuGLMapBufferObject,
 * ::cuGLRegisterBufferObject, ::cuGLUnmapBufferObject,
 * ::cuGLUnregisterBufferObject, ::cuGLUnmapBufferObjectAsync,
 * ::cuGLSetBufferObjectMapFlags
 */
CUresult CUDAAPI cuWGLGetDevice(CUdevice *pDevice, HGPUNV hGpu);
#endif /* _WIN32 */

/**
 * \defgroup CUDA_GL_DEPRECATED OpenGL Interoperability [DEPRECATED]
 * This section describes deprecated OpenGL interoperability functionality.
 *
 * @{
 */

/** Flags to map or unmap a resource */
typedef enum CUGLmap_flags_enum {
    CU_GL_MAP_RESOURCE_FLAGS_NONE          = 0x00,
    CU_GL_MAP_RESOURCE_FLAGS_READ_ONLY     = 0x01,
    CU_GL_MAP_RESOURCE_FLAGS_WRITE_DISCARD = 0x02,    
} CUGLmap_flags;

/**
 * \brief Initializes OpenGL interoperability
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Initializes OpenGL interoperability. This function is deprecated
 * and calling it is no longer required. It may fail if the needed
 * OpenGL driver facilities are not available.
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_UNKNOWN
 * \notefnerr
 *
 * \sa ::cuGLCtxCreate, ::cuGLMapBufferObject,
 * ::cuGLRegisterBufferObject, ::cuGLUnmapBufferObject,
 * ::cuGLUnregisterBufferObject, ::cuGLMapBufferObjectAsync,
 * ::cuGLUnmapBufferObjectAsync, ::cuGLSetBufferObjectMapFlags,
 * ::cuWGLGetDevice
 */
CUresult CUDAAPI cuGLInit(void);

/**
 * \brief Registers an OpenGL buffer object
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Registers the buffer object specified by \p buffer for access by
 * CUDA. This function must be called before CUDA can map the buffer
 * object.  There must be a valid OpenGL context bound to the current
 * thread when this function is called, and the buffer name is
 * resolved by that context.
 *
 * \param buffer - The name of the buffer object to register.
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_ALREADY_MAPPED
 * \notefnerr
 *
 * \sa ::cuGraphicsGLRegisterBuffer
 */
CUresult CUDAAPI cuGLRegisterBufferObject(GLuint buffer);

#if __CUDA_API_VERSION >= 3020
/**
 * \brief Maps an OpenGL buffer object
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Maps the buffer object specified by \p buffer into the address space of the
 * current CUDA context and returns in \p *dptr and \p *size the base pointer
 * and size of the resulting mapping.
 *
 * There must be a valid OpenGL context bound to the current thread
 * when this function is called.  This must be the same context, or a
 * member of the same shareGroup, as the context that was bound when
 * the buffer was registered.
 *
 * All streams in the current CUDA context are synchronized with the
 * current GL context.
 *
 * \param dptr   - Returned mapped base pointer
 * \param size   - Returned size of mapping
 * \param buffer - The name of the buffer object to map
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_INVALID_VALUE,
 * ::CUDA_ERROR_MAP_FAILED
 * \notefnerr
 *
 * \sa ::cuGraphicsMapResources
 */
CUresult CUDAAPI cuGLMapBufferObject(CUdeviceptr *dptr, size_t *size,  GLuint buffer);  
#endif /* __CUDA_API_VERSION >= 3020 */

/**
 * \brief Unmaps an OpenGL buffer object
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Unmaps the buffer object specified by \p buffer for access by CUDA.
 *
 * There must be a valid OpenGL context bound to the current thread
 * when this function is called.  This must be the same context, or a
 * member of the same shareGroup, as the context that was bound when
 * the buffer was registered.
 *
 * All streams in the current CUDA context are synchronized with the
 * current GL context.
 *
 * \param buffer - Buffer object to unmap
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_INVALID_VALUE
 * \notefnerr
 *
 * \sa ::cuGraphicsUnmapResources
 */
CUresult CUDAAPI cuGLUnmapBufferObject(GLuint buffer);

/**
 * \brief Unregister an OpenGL buffer object
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Unregisters the buffer object specified by \p buffer.  This
 * releases any resources associated with the registered buffer.
 * After this call, the buffer may no longer be mapped for access by
 * CUDA.
 *
 * There must be a valid OpenGL context bound to the current thread
 * when this function is called.  This must be the same context, or a
 * member of the same shareGroup, as the context that was bound when
 * the buffer was registered.
 *
 * \param buffer - Name of the buffer object to unregister
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_INVALID_VALUE
 * \notefnerr
 *
 * \sa ::cuGraphicsUnregisterResource
 */
CUresult CUDAAPI cuGLUnregisterBufferObject(GLuint buffer);

/**
 * \brief Set the map flags for an OpenGL buffer object
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Sets the map flags for the buffer object specified by \p buffer.
 *
 * Changes to \p Flags will take effect the next time \p buffer is mapped.
 * The \p Flags argument may be any of the following:
 * - ::CU_GL_MAP_RESOURCE_FLAGS_NONE: Specifies no hints about how this
 *   resource will be used. It is therefore assumed that this resource will be
 *   read from and written to by CUDA kernels. This is the default value.
 * - ::CU_GL_MAP_RESOURCE_FLAGS_READ_ONLY: Specifies that CUDA kernels which
 *   access this resource will not write to this resource.
 * - ::CU_GL_MAP_RESOURCE_FLAGS_WRITE_DISCARD: Specifies that CUDA kernels
 *   which access this resource will not read from this resource and will
 *   write over the entire contents of the resource, so none of the data
 *   previously stored in the resource will be preserved.
 *
 * If \p buffer has not been registered for use with CUDA, then
 * ::CUDA_ERROR_INVALID_HANDLE is returned. If \p buffer is presently
 * mapped for access by CUDA, then ::CUDA_ERROR_ALREADY_MAPPED is returned.
 *
 * There must be a valid OpenGL context bound to the current thread
 * when this function is called.  This must be the same context, or a
 * member of the same shareGroup, as the context that was bound when
 * the buffer was registered.
 *
 * \param buffer - Buffer object to unmap
 * \param Flags  - Map flags
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_HANDLE,
 * ::CUDA_ERROR_ALREADY_MAPPED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * \notefnerr
 *
 * \sa ::cuGraphicsResourceSetMapFlags
 */
CUresult CUDAAPI cuGLSetBufferObjectMapFlags(GLuint buffer, unsigned int Flags);

#if __CUDA_API_VERSION >= 3020
/**
 * \brief Maps an OpenGL buffer object
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Maps the buffer object specified by \p buffer into the address space of the
 * current CUDA context and returns in \p *dptr and \p *size the base pointer
 * and size of the resulting mapping.
 *
 * There must be a valid OpenGL context bound to the current thread
 * when this function is called.  This must be the same context, or a
 * member of the same shareGroup, as the context that was bound when
 * the buffer was registered.
 *
 * Stream \p hStream in the current CUDA context is synchronized with
 * the current GL context.
 *
 * \param dptr    - Returned mapped base pointer
 * \param size    - Returned size of mapping
 * \param buffer  - The name of the buffer object to map
 * \param hStream - Stream to synchronize
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_INVALID_VALUE,
 * ::CUDA_ERROR_MAP_FAILED
 * \notefnerr
 *
 * \sa ::cuGraphicsMapResources
 */
CUresult CUDAAPI cuGLMapBufferObjectAsync(CUdeviceptr *dptr, size_t *size,  GLuint buffer, CUstream hStream);
#endif /* __CUDA_API_VERSION >= 3020 */

/**
 * \brief Unmaps an OpenGL buffer object
 *
 * \deprecated This function is deprecated as of Cuda 3.0. 
 *
 * Unmaps the buffer object specified by \p buffer for access by CUDA.
 *
 * There must be a valid OpenGL context bound to the current thread
 * when this function is called.  This must be the same context, or a
 * member of the same shareGroup, as the context that was bound when
 * the buffer was registered.
 *
 * Stream \p hStream in the current CUDA context is synchronized with
 * the current GL context.
 *
 * \param buffer  - Name of the buffer object to unmap
 * \param hStream - Stream to synchronize
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_DEINITIALIZED,
 * ::CUDA_ERROR_NOT_INITIALIZED,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_INVALID_VALUE
 * \notefnerr
 *
 * \sa ::cuGraphicsUnmapResources
 */
CUresult CUDAAPI cuGLUnmapBufferObjectAsync(GLuint buffer, CUstream hStream);

/** @} */ /* END CUDA_GL_DEPRECATED */
/** @} */ /* END CUDA_GL */

/** 
 * CUDA API versioning support
 */
#if defined(__CUDA_API_VERSION_INTERNAL)
    #undef cuGLCtxCreate
    #undef cuGLMapBufferObject
    #undef cuGLMapBufferObjectAsync
#endif /* __CUDA_API_VERSION_INTERNAL */

/** 
 * CUDA API made obselete at API version 3020
 */
#if defined(__CUDA_API_VERSION_INTERNAL)
    #define CUdeviceptr CUdeviceptr_v1
#endif /* __CUDA_API_VERSION_INTERNAL */

#if defined(__CUDA_API_VERSION_INTERNAL) || __CUDA_API_VERSION < 3020
CUresult CUDAAPI cuGLCtxCreate(CUcontext *pCtx, unsigned int Flags, CUdevice device );
CUresult CUDAAPI cuGLMapBufferObject(CUdeviceptr *dptr, unsigned int *size,  GLuint buffer);  
CUresult CUDAAPI cuGLMapBufferObjectAsync(CUdeviceptr *dptr, unsigned int *size,  GLuint buffer, CUstream hStream);
#endif /* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION < 3020 */ 

#if defined(__CUDA_API_VERSION_INTERNAL)
    #undef CUdeviceptr
#endif /* __CUDA_API_VERSION_INTERNAL */

#ifdef __cplusplus
};
#endif

#undef __CUDA_API_VERSION

#endif

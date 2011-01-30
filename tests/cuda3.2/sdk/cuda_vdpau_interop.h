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

#if !defined(__CUDA_VDPAU_INTEROP_H__)
#define __CUDA_VDPAU_INTEROP_H__

#include "builtin_types.h"
#include "host_defines.h"

#include <vdpau/vdpau.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * \addtogroup CUDART_VDPAU VDPAU Interoperability
 * This section describes the VDPAU interoperability functions of the CUDA
 * runtime application programming interface.
 *
 * @{
 */

/**
 * \brief Gets the CUDA device associated with a VdpDevice.
 *
 * Returns the CUDA device associated with a VdpDevice, if applicable.
 *
 * \param device - Returns the device associated with vdpDevice, or -1 if
 * the device associated with vdpDevice is not a compute device.
 * \param vdpDevice - A VdpDevice handle
 * \param vdpGetProcAddress - VDPAU's VdpGetProcAddress function pointer
 *
 * \return
 * ::cudaSuccess
 * \notefnerr
 *
 * \sa ::cudaVDPAUSetVDPAUDevice
 */
extern __host__ cudaError_t CUDARTAPI cudaVDPAUGetDevice(int *device, VdpDevice vdpDevice, VdpGetProcAddress *vdpGetProcAddress);

/**
 * \brief Sets the CUDA device for use with VDPAU interoperability
 *
 * Records \p device as the device on which the active host thread executes
 * the device code. Records the thread as using VDPAU interoperability.
 * If the host thread has already initialized the CUDA runtime by
 * calling non-device management runtime functions or if there exists a CUDA
 * driver context active on the host thread, then this call returns
 * ::cudaErrorSetOnActiveProcess.
 *
 * \param device - Device to use for VDPAU interoperability
 * \param vdpDevice - The VdpDevice to interoperate with
 * \param vdpGetProcAddress - VDPAU's VdpGetProcAddress function pointer
 *
 * \return
 * ::cudaSuccess,
 * ::cudaErrorInvalidDevice,
 * ::cudaErrorSetOnActiveProcess
 * \notefnerr
 *
 * \sa ::cudaGraphicsVDPAURegisterVideoSurface,
 * ::cudaGraphicsVDPAURegisterOutputSurface
 */
extern __host__ cudaError_t CUDARTAPI cudaVDPAUSetVDPAUDevice(int device, VdpDevice vdpDevice, VdpGetProcAddress *vdpGetProcAddress);

/**
 * \brief Register a VdpVideoSurface object
 *
 * Registers the VdpVideoSurface specified by \p vdpSurface for access by CUDA.
 * A handle to the registered object is returned as \p resource.
 * The surface's intended usage is specified using \p flags, as follows:
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
 * \param vdpSurface - VDPAU object to be registered
 * \param flags - Map flags
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
 * ::cudaVDPAUSetVDPAUDevice
 * ::cudaGraphicsUnregisterResource,
 * ::cudaGraphicsSubResourceGetMappedArray
 */
extern __host__ cudaError_t CUDARTAPI cudaGraphicsVDPAURegisterVideoSurface(struct cudaGraphicsResource **resource, VdpVideoSurface vdpSurface, unsigned int flags);

/**
 * \brief Register a VdpOutputSurface object
 *
 * Registers the VdpOutputSurface specified by \p vdpSurface for access by CUDA.
 * A handle to the registered object is returned as \p resource.
 * The surface's intended usage is specified using \p flags, as follows:
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
 * \param vdpSurface - VDPAU object to be registered
 * \param flags - Map flags
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
 * ::cudaVDPAUSetVDPAUDevice
 * ::cudaGraphicsUnregisterResource,
 * ::cudaGraphicsSubResourceGetMappedArray
 */
extern __host__ cudaError_t CUDARTAPI cudaGraphicsVDPAURegisterOutputSurface(struct cudaGraphicsResource **resource, VdpOutputSurface vdpSurface, unsigned int flags);

/** @} */ /* END CUDART_VDPAU */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __CUDA_VDPAU_INTEROP_H__ */


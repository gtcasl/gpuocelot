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

#if !defined(__DRIVER_FUNCTIONS_H__)
#define __DRIVER_FUNCTIONS_H__

#include "builtin_types.h"
#include "host_defines.h"
#include "driver_types.h"

/**
 * \addtogroup CUDART_MEMORY
 *
 * @{
 */

/**
 * \brief Returns a ::cudaPitchedPtr based on input parameters
 *
 * Returns a ::cudaPitchedPtr based on the specified input parameters \p d,
 * \p p, \p xsz, and \p ysz.
 *
 * \param d   - Pointer to allocated memory
 * \param p   - Pitch of allocated memory in bytes
 * \param xsz - Logical width of allocation in elements
 * \param ysz - Logical height of allocation in elements
 *
 * \return
 * ::cudaPitchedPtr specified by \p d, \p p, \p xsz, and \p ysz
 *
 * \sa make_cudaExtent, make_cudaPos
 */
static __inline__ __host__ struct cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz) 
{
  struct cudaPitchedPtr s;

  s.ptr   = d;
  s.pitch = p;
  s.xsize = xsz;
  s.ysize = ysz;

  return s;
}

/**
 * \brief Returns a ::cudaPos based on input parameters
 *
 * Returns a ::cudaPos based on the specified input parameters \p x,
 * \p y, and \p z.
 *
 * \param x - X position
 * \param y - Y position
 * \param z - Z position
 *
 * \return
 * ::cudaPos specified by \p x, \p y, and \p z
 *
 * \sa make_cudaExtent, make_cudaPitchedPtr
 */
static __inline__ __host__ struct cudaPos make_cudaPos(size_t x, size_t y, size_t z) 
{
  struct cudaPos p;

  p.x = x;
  p.y = y;
  p.z = z;

  return p;
}

/**
 * \brief Returns a ::cudaExtent based on input parameters
 *
 * Returns a ::cudaExtent based on the specified input parameters \p w,
 * \p h, and \p d.
 *
 * \param w - Width in bytes
 * \param h - Height in elements
 * \param d - Depth in elements
 *
 * \return
 * ::cudaExtent specified by \p w, \p h, and \p d
 *
 * \sa make_cudaPitchedPtr, make_cudaPos
 */
static __inline__ __host__ struct cudaExtent make_cudaExtent(size_t w, size_t h, size_t d) 
{
  struct cudaExtent e;

  e.width  = w;
  e.height = h;
  e.depth  = d;

  return e;
}

/** @} */ /* END CUDART_MEMORY */

#endif /* !__DRIVER_FUNCTIONS_H__ */

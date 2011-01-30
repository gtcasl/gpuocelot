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

#if !defined(__TEXTURE_TYPES_H__)
#define __TEXTURE_TYPES_H__

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "driver_types.h"

/**
 * \addtogroup CUDART_TYPES
 *
 * @{
 */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/**
 * CUDA texture address modes
 */
/*DEVICE_BUILTIN*/
enum cudaTextureAddressMode
{
  cudaAddressModeWrap   = 0,    /**< Wrapping address mode */
  cudaAddressModeClamp  = 1,    /**< Clamp to edge address mode */
  cudaAddressModeMirror = 2,    /**< Mirror address mode */
  cudaAddressModeBorder = 3     /**< Border address mode */
};

/**
 * CUDA texture filter modes
 */
/*DEVICE_BUILTIN*/
enum cudaTextureFilterMode
{
  cudaFilterModePoint  = 0,     /**< Point filter mode */
  cudaFilterModeLinear = 1      /**< Linear filter mode */
};

/**
 * CUDA texture read modes
 */
/*DEVICE_BUILTIN*/
enum cudaTextureReadMode
{
  cudaReadModeElementType     = 0,  /**< Read texture as specified element type */
  cudaReadModeNormalizedFloat = 1   /**< Read texture as normalized float */
};

/**
 * CUDA texture reference
 */
/*DEVICE_BUILTIN*/
struct textureReference
{
  /**
   * Indicates whether texture reads are normalized or not
   */
  int                          normalized;
  /**
   * Texture filter mode
   */
  enum cudaTextureFilterMode   filterMode;
  /**
   * Texture address mode for up to 3 dimensions
   */
  enum cudaTextureAddressMode  addressMode[3];
  /**
   * Channel descriptor for the texture reference
   */
  struct cudaChannelFormatDesc channelDesc;
  int                          __cudaReserved[16];
};

/** @} */
/** @} */ /* END CUDART_TYPES */

#endif /* !__TEXTURE_TYPES_H__ */

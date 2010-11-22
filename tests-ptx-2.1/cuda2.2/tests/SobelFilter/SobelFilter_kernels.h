/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
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

#ifndef __SOBELFILTER_KERNELS_H_
#define __SOBELFILTER_KERNELS_H_

#define TILEX   36 // Sobel tile width
#define TILEY   28 // Sobel tile height
#define FTILEX  38 // Filter tile width
#define FTILEY  30 // Filter tile height
#define PTILEX  48 // TILEX + 2*RADIUS+1
#define PTILEY  40 // TILEY + 2*RADIUS+1 
#define TIDSX   48 // Threads in X
#define TIDSY   8  // Threads in Y
#define RADIUS  5  // Filter radius
#define RPIXELS  5  // Pixels per thread
#define WPIXELS  4  // Pixels per thread

typedef unsigned char Pixel;

// global determines which filter to invoke
enum SobelDisplayMode {
	SOBELDISPLAY_IMAGE = 0,
	SOBELDISPLAY_SOBELTEX,
	SOBELDISPLAY_SOBELSHARED
};

static char *filterMode[] = { 
	"Original Filter", 
	"Sobel Shared", 
	"Sobel Shared+Texture", 
	NULL 
};

extern enum SobelDisplayMode g_SobelDisplayMode;

extern "C" void sobelFilter(Pixel *odata, int iw, int ih, enum SobelDisplayMode mode, float fScale);
extern "C" void setupTexture(int iw, int ih, Pixel *data, int Bpp);
extern "C" void deleteTexture(void);
extern "C" void initFilter(void);

#endif


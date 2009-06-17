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

#ifndef DDS_H
#define DDS_H

#if !defined(MAKEFOURCC)
#    define MAKEFOURCC(ch0, ch1, ch2, ch3) \
        ( (unsigned int)(ch0)        | ((unsigned int)(ch1) << 8) | \
        ( (unsigned int)(ch2) << 16) | ((unsigned int)(ch3) << 24) )
#endif

typedef unsigned int uint;
typedef unsigned short ushort;

struct DDSPixelFormat {
    uint size;
    uint flags;
    uint fourcc;
    uint bitcount;
    uint rmask;
    uint gmask;
    uint bmask;
    uint amask;
};

struct DDSCaps {
    uint caps1;
    uint caps2;
    uint caps3;
    uint caps4;
};

/// DDS file header.
struct DDSHeader {
    uint fourcc;
    uint size;
    uint flags;
    uint height;
    uint width;
    uint pitch;
    uint depth;
    uint mipmapcount;
    uint reserved[11];
    DDSPixelFormat pf;
    DDSCaps caps;
    uint notused;
};

static const uint FOURCC_DDS = MAKEFOURCC('D', 'D', 'S', ' ');
static const uint FOURCC_DXT1 = MAKEFOURCC('D', 'X', 'T', '1');
static const uint DDSD_WIDTH = 0x00000004U;
static const uint DDSD_HEIGHT = 0x00000002U;
static const uint DDSD_CAPS = 0x00000001U;
static const uint DDSD_PIXELFORMAT = 0x00001000U;
static const uint DDSCAPS_TEXTURE = 0x00001000U;
static const uint DDPF_FOURCC = 0x00000004U;
static const uint DDSD_LINEARSIZE = 0x00080000U;


#endif // DDS_H

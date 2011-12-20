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

#include <stdio.h>
#include <stdlib.h>
#include <cutil_inline.h>

#include "SobelFilter_kernels.h"

#define SV 0.003921f
#define IV 255.f

// Texture reference for reading image
texture<unsigned char, 2> tex;
extern __shared__ unsigned char LocalBlock[];
static cudaArray *array = NULL;

#define Radius 1

#ifdef FIXED_BLOCKWIDTH
#define BlockWidth 80
#define SharedPitch 384
#endif

__device__ short __abs(short a) {
	return ((a) < 0 ? -(a) : a);
}

__device__ unsigned char
ComputeSobel(unsigned char ul, // upper left
             unsigned char um, // upper middle
             unsigned char ur, // upper right
             unsigned char ml, // middle left
             unsigned char mm, // middle (unused)
             unsigned char mr, // middle right
             unsigned char ll, // lower left
             unsigned char lm, // lower middle
             unsigned char lr, // lower right
             float fScale )
{
    short Horz = ur + 2*mr + lr - ul - 2*ml - ll;
    short Vert = ul + 2*um + ur - ll - 2*lm - lr;
    short Sum = (short) (fScale*(__abs(Horz)+__abs(Vert)));
    if ( Sum < 0 ) return 0; else if ( Sum > 0xff ) return 0xff;
    return (unsigned char) Sum;
}

__global__ void 
SobelShared( uchar4 *pSobelOriginal, unsigned short SobelPitch, 
#ifndef FIXED_BLOCKWIDTH
             short BlockWidth, short SharedPitch,
#endif
             short w, short h, float fScale )
{ 
    short u = 4*blockIdx.x*BlockWidth;
    short v = blockIdx.y*blockDim.y + threadIdx.y;
    short ib;

    int SharedIdx = threadIdx.y * SharedPitch;

    for ( ib = threadIdx.x; ib < BlockWidth+2*Radius; ib += blockDim.x ) {
        LocalBlock[SharedIdx+4*ib+0] = tex2D( tex, 
            (float) (u+4*ib-Radius+0), (float) (v-Radius) );
        LocalBlock[SharedIdx+4*ib+1] = tex2D( tex, 
            (float) (u+4*ib-Radius+1), (float) (v-Radius) );
        LocalBlock[SharedIdx+4*ib+2] = tex2D( tex, 
            (float) (u+4*ib-Radius+2), (float) (v-Radius) );
        LocalBlock[SharedIdx+4*ib+3] = tex2D( tex, 
            (float) (u+4*ib-Radius+3), (float) (v-Radius) );
    }
    if ( threadIdx.y < Radius*2 ) {
        //
        // copy trailing Radius*2 rows of pixels into shared
        //
        SharedIdx = (blockDim.y+threadIdx.y) * SharedPitch;
        for ( ib = threadIdx.x; ib < BlockWidth+2*Radius; ib += blockDim.x ) {
            LocalBlock[SharedIdx+4*ib+0] = tex2D( tex, 
                (float) (u+4*ib-Radius+0), (float) (v+blockDim.y-Radius) );
            LocalBlock[SharedIdx+4*ib+1] = tex2D( tex, 
                (float) (u+4*ib-Radius+1), (float) (v+blockDim.y-Radius) );
            LocalBlock[SharedIdx+4*ib+2] = tex2D( tex, 
                (float) (u+4*ib-Radius+2), (float) (v+blockDim.y-Radius) );
            LocalBlock[SharedIdx+4*ib+3] = tex2D( tex, 
                (float) (u+4*ib-Radius+3), (float) (v+blockDim.y-Radius) );
        }
    }

    __syncthreads();

    u >>= 2;    // index as uchar4 from here
    uchar4 *pSobel = (uchar4 *) (((char *) pSobelOriginal)+v*SobelPitch);
    SharedIdx = threadIdx.y * SharedPitch;

    for ( ib = threadIdx.x; ib < BlockWidth; ib += blockDim.x ) {

        unsigned char pix00 = LocalBlock[SharedIdx+4*ib+0*SharedPitch+0];
        unsigned char pix01 = LocalBlock[SharedIdx+4*ib+0*SharedPitch+1];
        unsigned char pix02 = LocalBlock[SharedIdx+4*ib+0*SharedPitch+2];
        unsigned char pix10 = LocalBlock[SharedIdx+4*ib+1*SharedPitch+0];
        unsigned char pix11 = LocalBlock[SharedIdx+4*ib+1*SharedPitch+1];
        unsigned char pix12 = LocalBlock[SharedIdx+4*ib+1*SharedPitch+2];
        unsigned char pix20 = LocalBlock[SharedIdx+4*ib+2*SharedPitch+0];
        unsigned char pix21 = LocalBlock[SharedIdx+4*ib+2*SharedPitch+1];
        unsigned char pix22 = LocalBlock[SharedIdx+4*ib+2*SharedPitch+2];

        uchar4 out;

        out.x = ComputeSobel(pix00, pix01, pix02, 
                             pix10, pix11, pix12, 
                             pix20, pix21, pix22, fScale );

        pix00 = LocalBlock[SharedIdx+4*ib+0*SharedPitch+3];
        pix10 = LocalBlock[SharedIdx+4*ib+1*SharedPitch+3];
        pix20 = LocalBlock[SharedIdx+4*ib+2*SharedPitch+3];
        out.y = ComputeSobel(pix01, pix02, pix00, 
                             pix11, pix12, pix10, 
                             pix21, pix22, pix20, fScale );

        pix01 = LocalBlock[SharedIdx+4*ib+0*SharedPitch+4];
        pix11 = LocalBlock[SharedIdx+4*ib+1*SharedPitch+4];
        pix21 = LocalBlock[SharedIdx+4*ib+2*SharedPitch+4];
        out.z = ComputeSobel( pix02, pix00, pix01, 
                              pix12, pix10, pix11, 
                              pix22, pix20, pix21, fScale );

        pix02 = LocalBlock[SharedIdx+4*ib+0*SharedPitch+5];
        pix12 = LocalBlock[SharedIdx+4*ib+1*SharedPitch+5];
        pix22 = LocalBlock[SharedIdx+4*ib+2*SharedPitch+5];
        out.w = ComputeSobel( pix00, pix01, pix02, 
                              pix10, pix11, pix12, 
                              pix20, pix21, pix22, fScale );
        if ( u+ib < w/4 && v < h ) {
            pSobel[u+ib] = out;
        }
    }

    __syncthreads();
}

__global__ void 
SobelCopyImage( Pixel *pSobelOriginal, unsigned int Pitch, 
                int w, int h, float fscale )
{ 
    unsigned char *pSobel = 
      (unsigned char *) (((char *) pSobelOriginal)+blockIdx.x*Pitch);
    for ( int i = threadIdx.x; i < w; i += blockDim.x ) {
        pSobel[i] = min( max((tex2D( tex, (float) i, (float) blockIdx.x ) * fscale), 0.f), 255.f);
    }
}

__global__ void 
SobelTex( Pixel *pSobelOriginal, unsigned int Pitch, 
          int w, int h, float fScale )
{ 
    unsigned char *pSobel = 
      (unsigned char *) (((char *) pSobelOriginal)+blockIdx.x*Pitch);
    for ( int i = threadIdx.x; i < w; i += blockDim.x ) {
        unsigned char pix00 = tex2D( tex, (float) i-1, (float) blockIdx.x-1 );
        unsigned char pix01 = tex2D( tex, (float) i+0, (float) blockIdx.x-1 );
        unsigned char pix02 = tex2D( tex, (float) i+1, (float) blockIdx.x-1 );
        unsigned char pix10 = tex2D( tex, (float) i-1, (float) blockIdx.x+0 );
        unsigned char pix11 = tex2D( tex, (float) i+0, (float) blockIdx.x+0 );
        unsigned char pix12 = tex2D( tex, (float) i+1, (float) blockIdx.x+0 );
        unsigned char pix20 = tex2D( tex, (float) i-1, (float) blockIdx.x+1 );
        unsigned char pix21 = tex2D( tex, (float) i+0, (float) blockIdx.x+1 );
        unsigned char pix22 = tex2D( tex, (float) i+1, (float) blockIdx.x+1 );
        pSobel[i] = ComputeSobel(pix00, pix01, pix02, 
                                 pix10, pix11, pix12,
                                 pix20, pix21, pix22, fScale );
    }
}

extern "C" void setupTexture(int iw, int ih, Pixel *data, int Bpp)
{
    cudaChannelFormatDesc desc;
    
    if (Bpp == 1) {
        desc = cudaCreateChannelDesc<unsigned char>();
    } else {
        desc = cudaCreateChannelDesc<uchar4>();
    }

    cutilSafeCall(cudaMallocArray(&array, &desc, iw, ih));
    cutilSafeCall(cudaMemcpyToArray(array, 0, 0, data, Bpp*sizeof(Pixel)*iw*ih, cudaMemcpyHostToDevice));
}

extern "C" void deleteTexture(void)
{
    cutilSafeCall(cudaFreeArray(array));
}


// Wrapper for the __global__ call that sets up the texture and threads
extern "C" void sobelFilter(Pixel *odata, int iw, int ih, enum SobelDisplayMode mode, float fScale) 
{
    cutilSafeCall(cudaBindTextureToArray(tex, array));

    switch ( mode ) {
        case  SOBELDISPLAY_IMAGE: 
            SobelCopyImage<<<ih, 384>>>(odata, iw, iw, ih, fScale );
            break;
        case SOBELDISPLAY_SOBELTEX:
            SobelTex<<<ih, 384>>>(odata, iw, iw, ih, fScale );
            break;
        case SOBELDISPLAY_SOBELSHARED:
        {
            dim3 threads(16,4);
#ifndef FIXED_BLOCKWIDTH
	          int BlockWidth = 80; // must be divisible by 16 for coalescing
#endif
        		dim3 blocks = dim3(iw/(4*BlockWidth)+(0!=iw%(4*BlockWidth)),
                               ih/threads.y+(0!=ih%threads.y));
        		int SharedPitch = ~0x3f&(4*(BlockWidth+2*Radius)+0x3f);
        		int sharedMem = SharedPitch*(threads.y+2*Radius);

        		// for the shared kernel, width must be divisible by 4
        		iw &= ~3;

        		SobelShared<<<blocks, threads, sharedMem>>>((uchar4 *) odata, 
                                                        iw, 
#ifndef FIXED_BLOCKWIDTH
                                                        BlockWidth, SharedPitch,
#endif
                                                		    iw, ih, fScale );
        }
        break;
    }

    cutilSafeCall(cudaUnbindTexture(tex));
}

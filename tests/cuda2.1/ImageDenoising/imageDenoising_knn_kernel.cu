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



////////////////////////////////////////////////////////////////////////////////
// KNN kernel
////////////////////////////////////////////////////////////////////////////////
__global__ void KNN(
    TColor *dst,
    int imageW,
    int imageH,
    float Noise,
    float lerpC
){
    const int ix = blockDim.x * blockIdx.x + threadIdx.x;
    const int iy = blockDim.y * blockIdx.y + threadIdx.y;
    //Add half of a texel to always address exact texel centers
    const float x = (float)ix + 0.5f;
    const float y = (float)iy + 0.5f;

    if(ix < imageW && iy < imageH){
        //Normalized counter for the weight threshold
        float fCount = 0;
        //Total sum of pixel weights
        float sumWeights = 0;
        //Result accumulator
        float3 clr = {0, 0, 0};
        //Center of the KNN window
        float4 clr00 = tex2D(texImage, x, y);

        //Cycle through KNN window, surrounding (x, y) texel
        for(float i = -KNN_WINDOW_RADIUS; i <= KNN_WINDOW_RADIUS; i++)
            for(float j = -KNN_WINDOW_RADIUS; j <= KNN_WINDOW_RADIUS; j++)
            {
                float4     clrIJ = tex2D(texImage, x + j, y + i);
                float distanceIJ = vecLen(clr00, clrIJ);

                //Derive final weight from color distance
                float   weightIJ = __expf( - (distanceIJ * Noise + (i * i + j * j) * INV_KNN_WINDOW_AREA) );

                //Accumulate (x + j, y + i) texel color with computed weight
                clr.x += clrIJ.x * weightIJ;
                clr.y += clrIJ.y * weightIJ;
                clr.z += clrIJ.z * weightIJ;

                //Sum of weights for color normalization to [0..1] range
                sumWeights     += weightIJ;

                //Update weight counter, if KNN weight for current window texel
                //exceeds the weight threshold
                fCount         += (weightIJ > KNN_WEIGHT_THRESHOLD) ? INV_KNN_WINDOW_AREA : 0;
            }

        //Normalize result color by sum of weights
        sumWeights = 1.0f / sumWeights;
        clr.x *= sumWeights;
        clr.y *= sumWeights;
        clr.z *= sumWeights;

        //Choose LERP quotent basing on how many texels
        //within the KNN window exceeded the weight threshold
        float lerpQ = (fCount > KNN_LERP_THRESHOLD) ? lerpC : 1.0f - lerpC;

        //Write final result to global memory
        clr.x = lerpf(clr.x, clr00.x, lerpQ);
        clr.y = lerpf(clr.y, clr00.y, lerpQ);
        clr.z = lerpf(clr.z, clr00.z, lerpQ);
        dst[imageW * iy + ix] = make_color(clr.x, clr.y, clr.z, 0);
    };
}

extern "C" 
void cuda_KNN(
    TColor *d_dst,
    int imageW,
    int imageH,
    float Noise,
    float lerpC
){
    dim3 threads(BLOCKDIM_X, BLOCKDIM_Y);
    dim3 grid(iDivUp(imageW, BLOCKDIM_X), iDivUp(imageH, BLOCKDIM_Y));

    KNN<<<grid, threads>>>(d_dst, imageW, imageH, Noise, lerpC);
}


////////////////////////////////////////////////////////////////////////////////
// Stripped KNN kernel, only highlighting areas with different LERP directions
////////////////////////////////////////////////////////////////////////////////
__global__ void KNNdiag(
    TColor *dst,
    int imageW,
    int imageH,
    float Noise,
    float lerpC
){
    const int ix = blockDim.x * blockIdx.x + threadIdx.x;
    const int iy = blockDim.y * blockIdx.y + threadIdx.y;
    //Add half of a texel to always address exact texel centers
    const float x = (float)ix + 0.5f;
    const float y = (float)iy + 0.5f;

    if(ix < imageW && iy < imageH){
        //Normalized counter for the weight threshold
        float  fCount = 0;
        //Center of the KNN window
        float4  clr00 = tex2D(texImage, x, y);

        //Cycle through KNN window, surrounding (x, y) texel
        for(float i = -KNN_WINDOW_RADIUS; i <= KNN_WINDOW_RADIUS; i++)
            for(float j = -KNN_WINDOW_RADIUS; j <= KNN_WINDOW_RADIUS; j++)
            {
                float4     clrIJ = tex2D(texImage, x + j, y + i);
                float distanceIJ = vecLen(clr00, clrIJ);

                //Derive final weight from color and geometric distance
                float weightIJ  = __expf( - (distanceIJ * Noise + (i * i + j * j) * INV_KNN_WINDOW_AREA) );

                //Update weight counter, if KNN weight for current window texel
                //exceeds the weight threshold
                fCount += (weightIJ > KNN_WEIGHT_THRESHOLD) ? INV_KNN_WINDOW_AREA : 0.0f;
            }

        //Choose LERP quotent basing on how many texels
        //within the KNN window exceeded the weight threshold
        float lerpQ = (fCount > KNN_LERP_THRESHOLD) ? 1.0f : 0;

        //Write final result to global memory
        dst[imageW * iy + ix] = make_color(lerpQ, 0, (1.0f - lerpQ), 0);
    };
}

extern "C" 
void cuda_KNNdiag(
    TColor *d_dst,
    int imageW,
    int imageH,
    float Noise,
    float lerpC
)
{
    dim3 threads(BLOCKDIM_X, BLOCKDIM_Y);
    dim3 grid(iDivUp(imageW, BLOCKDIM_X), iDivUp(imageH, BLOCKDIM_Y));

    KNNdiag<<<grid, threads>>>(d_dst, imageW, imageH, Noise, lerpC);
}

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



typedef struct{
    float x, y;
} Complex;
const Complex CPLX_ZERO = {0, 0};


//a += b * c
void complexMAD(Complex& a, Complex b, Complex c){
    Complex t = {a.x + b.x * c.x - b.y * c.y, a.y + b.x * c.y + b.y * c.x};
    a = t;
}


////////////////////////////////////////////////////////////////////////////////
// Reference straightfroward CPU convolution
////////////////////////////////////////////////////////////////////////////////
extern "C" void convolutionCPU(
    Complex *h_Result,
    Complex *h_Data,
    Complex *h_Kernel,
    int dataW,
    int dataH,
    int kernelW,
    int kernelH,
    int kernelX,
    int kernelY
){
    for(int y = 0; y < dataH; y++)
        for(int x = 0; x < dataW; x++){
            Complex sum = CPLX_ZERO;

            for(int ky = -(kernelH - kernelY - 1); ky <= kernelY; ky++)
                for(int kx = -(kernelW - kernelX - 1); kx <= kernelX; kx++){
                    int dx = x + kx;
                    int dy = y + ky;
                    if(dx < 0) dx = 0;
                    if(dy < 0) dy = 0;
                    if(dx >= dataW) dx = dataW - 1;
                    if(dy >= dataH) dy = dataH - 1;

                    complexMAD(
                        sum,
                        h_Data[dy * dataW + dx],
                        h_Kernel[(kernelY - ky) * kernelW + (kernelX - kx)]
                    );
                }

            h_Result[y * dataW + x] = sum;
        }
}

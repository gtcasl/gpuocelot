/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

#ifndef _PTXJIT_H_
#define _PTXJIT_H_

/*
 * PTX is equivalent to the following kernel:
 *
 * __global__ void myKernel(int *data)
 * {
 *     int tid = blockIdx.x * blockDim.x + threadIdx.x;
 *     data[tid] = tid;
 * }
 *
 */

char myPtx[] = "\n\
        .version 1.4\n\
        .target sm_10, map_f64_to_f32\n\
        .entry _Z8myKernelPi (\n\
                .param .u64 __cudaparm__Z8myKernelPi_data)\n\
        {\n\
        .reg .u16 %rh<4>;\n\
        .reg .u32 %r<5>;\n\
        .reg .u64 %rd<6>;\n\
        cvt.u32.u16     %r1, %tid.x;\n\
        mov.u16         %rh1, %ctaid.x;\n\
        mov.u16         %rh2, %ntid.x;\n\
        mul.wide.u16    %r2, %rh1, %rh2;\n\
        add.u32         %r3, %r1, %r2;\n\
        ld.param.u64    %rd1, [__cudaparm__Z8myKernelPi_data];\n\
        cvt.s64.s32     %rd2, %r3;\n\
        mul.wide.s32    %rd3, %r3, 4;\n\
        add.u64         %rd4, %rd1, %rd3;\n\
        st.global.s32   [%rd4+0], %r3;\n\
        exit;\n\
        }\n\
";

char myPtx32[] = "\n\
	.version 1.4\n\
	.target sm_10, map_f64_to_f32\n\
	.entry _Z8myKernelPi (\n\
		.param .u32 __cudaparm__Z8myKernelPi_data)\n\
	{\n\
        .reg .u16 %rh<4>;\n\
        .reg .u32 %r<8>;\n\
        .loc    28      14      0\n\
        .loc    28      17      0\n\
        mov.u16         %rh1, %ctaid.x;\n\
        mov.u16         %rh2, %ntid.x;\n\
        mul.wide.u16    %r1, %rh1, %rh2;\n\
        cvt.u32.u16     %r2, %tid.x;\n\
        add.u32         %r3, %r2, %r1;\n\
        ld.param.u32    %r4, [__cudaparm__Z8myKernelPi_data];\n\
        mul.lo.u32      %r5, %r3, 4;\n\
        add.u32         %r6, %r4, %r5;\n\
        st.global.s32   [%r6+0], %r3;\n\
        .loc    28      18      0\n\
        exit;\n\
        }\n\
";

#endif

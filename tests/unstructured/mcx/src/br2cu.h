#ifndef _BR2CU_H
#define _BR2CU_H

/***********************************************************
Translation unit for BrookGPU to CUDA

Qianqian Fang <fangq nmr.mgh.harvard.edu>

************************************************************/

#include <cuda.h>

#define kernel __global__
#define streamRead(a,b)  {size_t sy;cudaGetSymbolSize(&sy,b);printf("ss %d\n",sy);cudaMemcpy(a, b[0], sy, \
cudaMemcpyHostToDevice);}
#define streamWrite(a,b) {size_t sy;cudaGetSymbolSize(&sy,a);printf("ss %d\n",sy);cudaMemcpy(b[0], a, sy, \
cudaMemcpyDeviceToHost);}
#define int2(a,b) make_int2(a,b)
#define int3(a,b,c) make_int3(a,b,c)
#define uint2(a,b) make_uint2(a,b)
#define uint3(a,b,c) make_uint3(a,b,c)
#define float1(a) make_float1(a)
#define float2(a,b) make_float2(a,b)
#define float3(a,b,c) make_float3(a,b,c)
#define float4(a,b,c,d) make_float4(a,b,c,d)
typedef unsigned int uint;

#endif


/* Ocelot 0.4.72  issue.
   Steve Worley  Oct 27 2009
   sw@worley.com

   Ocelot fails when running kernels using dynamic shared memory, in 32 bit only.



   32 bit (ONLY!)  Ubuntu 9.04.
   CUDA 2.3
   
   Compile with:

nvcc ocbug.cu -lOcelotExecutive -lOcelotTrace -lOcelotIr -lOcelotParser -lhydrazine -lcudart

run, and you get the error output:

a.out: ocelot/executive/implementation/CooperativeThreadArray.cpp:1093: ir::PTXU32 executive::CooperativeThreadArray::operandAsU32(int, const ir::PTXOperand&): Assertion `0 == "invalid address mode of operand"' failed.

Likely it has to do with the dynamic shared memory. Static variables work fine.


*/

#include <cstdio>

__global__ void kernel(int *source)
{  
  extern __shared__ int s[];

  s[threadIdx.x]=source[threadIdx.x];
}


int main()
{
  int *src;
  int host[10000]={0};
    
  cudaSetDevice(0);
  cudaMalloc((void**)&src, 10000*sizeof(int));

  cudaMemcpy(src, host, 10000*sizeof(int), cudaMemcpyHostToDevice);
  
  kernel<<<128, 128, 15000>>>(src);
  printf("TEST PASSED\n");
  return 0;
}

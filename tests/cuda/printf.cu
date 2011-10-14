#include <cuda.h>
#include <stdio.h>

__global__
void
helloKernel(){
  if(threadIdx.x & 1 > 0){ //odd thread
    printf("Hello world, from odd thread %d\n", threadIdx.x);
  }else{
    printf("Hello world, from even thread %d\n", threadIdx.x);
  }
}

int
main(int argc, char* argv[]){
  dim3 grid(1,1);
  dim3 block(20,1);
  helloKernel<<<grid, block>>>();
  return 0;
  //cudaDeviceReset(); //needed to flush printf cuda buffer
}



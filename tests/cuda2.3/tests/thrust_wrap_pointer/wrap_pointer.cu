#ifdef _GLIBCXX_USE_INT128
#undef _GLIBCXX_USE_INT128
#endif 

#ifdef _GLIBCXX_ATOMIC_BUILTINS
#undef _GLIBCXX_ATOMIC_BUILTINS
#endif

#include <thrust/device_ptr.h>
#include <thrust/fill.h>
#include <cuda.h>

int main(void)
{
    size_t N = 10;

    // raw pointer to device memory
    int * raw_ptr;
    cudaMalloc((void **) &raw_ptr, N * sizeof(int));

    // wrap raw pointer with a device_ptr 
    thrust::device_ptr<int> dev_ptr(raw_ptr);

    // use device_ptr in thrust algorithms
    thrust::fill(dev_ptr, dev_ptr + N, (int) 0);

    // access device memory through device_ptr
    dev_ptr[0] = 1;

    // free memory
    cudaFree(raw_ptr);

 	std::cout << "TEST PASSED\n";

   return 0;
}

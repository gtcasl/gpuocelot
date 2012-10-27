#ifdef _GLIBCXX_USE_INT128
#undef _GLIBCXX_USE_INT128
#endif 

#ifdef _GLIBCXX_ATOMIC_BUILTINS
#undef _GLIBCXX_ATOMIC_BUILTINS
#endif

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/reduce.h>
#include <thrust/functional.h>
#include <cstdlib>

int main(void)
{
  // generate random data on the host
  thrust::host_vector<int> h_vec(100);
  thrust::generate(h_vec.begin(), h_vec.end(), rand);

  // transfer to device and compute sum
  thrust::device_vector<int> d_vec = h_vec;
  int x = thrust::reduce(d_vec.begin(), d_vec.end(), (int) 0,
                          thrust::plus<int>());
   
  std::cout << "TEST PASSED\n";

  return 0;
}

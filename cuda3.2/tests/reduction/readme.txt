Important note about warp-synchronous code:

The optimized code in this sample uses a technique known as "warp-synchronous" programming,
which depends on the fact that within a CUDA warp of threads, all threads execute instructions
synchronously.  It uses this to avoid __syncthreads() when threads within a warp are sharing
data via __shared__ memory.  

It is important to note that for this to work correctly across all current GPUs, the shared 
memory used in these warp-synchronous expressions must be declared "volatile".  If it is not
declared volatile, then in the absence of __syncthreads(), the compiler is free to replace
stores to and loads from __shared__ memory with register storage (an optimization technique),
which will result in incorrect execution.  

So heed the use of "volatile" in this sample.
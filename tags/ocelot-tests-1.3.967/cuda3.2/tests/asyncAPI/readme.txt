This sample illustrates the usage of CUDA events and streams for overlapping 
CPU and GPU execution.  Events are insterted into a stream of CUDA calls.  
Since CUDA stream calls are asynchronous, the CPU can continue with computations 
while the GPU is executing (including DMA memcopies between the host and device).
CPU can query CUDA event status to determine whether GPU has completed tasks.
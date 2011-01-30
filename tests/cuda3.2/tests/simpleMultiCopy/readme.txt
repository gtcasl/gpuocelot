This sample illustrates the usage of CUDA streams for overlapping
kernel execution with device/host memcopies.  The kernel is used to 
initialize an array to a specific value, after which the array is 
copied to the host (CPU) memory.  To increase performance, multiple 
kernel/memcopy pairs are launched asynchronously, each pair in its 
own stream.  Devices with Compute Capability 1.1 can overlap a kernel
and a memcopy as long as they are issued in different streams.  Kernels
are serialized.  Thus, if n pairs are launched, streamed approach
can reduce the memcopy cost to the (1/n)th of a single copy of the entire
data set.
 
Additionally, this sample uses CUDA events to measure elapsed time for
CUDA calls.  Events are a part of CUDA API and provide a system independent
way to measure execution times on CUDA devices with approximately 0.5 
microsecond precision.

Elapsed times are averaged over nreps repetitions (10 by default).
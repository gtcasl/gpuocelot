/*!
	\file Cuda.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday November 18, 2008
	\brief The headers for CUDA macros.
*/

#ifndef CUDA_H_INCLUDED
#define CUDA_H_INCLUDED

#include <hydrazine/cuda/include/driver_types.h>

#ifndef NUM_BANKS
#define NUM_BANKS 16
#endif

#ifndef LOG_NUM_BANKS
#define LOG_NUM_BANKS 4
#endif

/*!
	\brief Amount of shared memory reserved by the cuda compiler
*/
#ifndef RESERVED_SHARED_MEMORY
#define RESERVED_SHARED_MEMORY 256
#endif

/*!
	\brief The optimal amount of shared memory available
*/
#ifndef OPTIMAL_SHARED_MEMORY
#define OPTIMAL_SHARED_MEMORY 8192
#endif

/*!
	\brief The min amount of regs guaranteed available to a thread.
*/
#ifndef MIN_REGS
#define MIN_REGS 128
#endif

/*!
	\brief Fast integer multiply
*/
#define IMUL(a, b) __mul24(a, b)

/*!
	\brief Get the current thread id
*/
#define THREAD_ID() threadIdx.x

/*!
	\brief Get the warp size
*/
#define WARP_SIZE() warpSize

/*!
	\brief Get the block dimension
*/
#define CTA_DIMENSION() blockDim.x

/*!
	\brief Get the grid dimension
*/
#define KERNEL_DIMENSION() gridDim.x

/*!
	\brief get the block id
*/
#define CTA_ID() blockIdx.x

/*!
	\brief Get the warp ID
*/
#define WARP_ID() ( THREAD_ID() / WARP_SIZE() )

/*!
	\brief Thread ID within a warp
*/
#define INTRA_WARP_ID() ( THREAD_ID() % WARP_SIZE() )

/*!
	\brief Get the global warp ID
*/
#define GLOBAL_WARP_ID() ( GLOBAL_ID() / WARP_SIZE() )

/*!
	\brief Get the number of warps per CTA
*/
#define WARPS_PER_CTA() ( CTA_DIMENSION() / WARP_SIZE() )

/*!
	\brief Get the local id within a warp
*/
#define LOCAL_ID() ( THREAD_ID() % WARP_SIZE() )

/*!
	\brief Get the global thread id
*/
#define GLOBAL_ID() ( THREAD_ID() + IMUL( CTA_ID(), CTA_DIMENSION() ) )

/*!
	\brief Get the total number of threads
*/
#define TOTAL_THREADS() ( KERNEL_DIMENSION() * CTA_DIMENSION() )

#endif


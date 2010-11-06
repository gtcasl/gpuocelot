/*!
	\file Util.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday November 18, 2008
	\brief The headers for CUDA utility functions.
*/

#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

namespace hydrazine
{

namespace cuda
{

/*!
	\brief Compute the next highest power of 2 for 32 bit numbers
*/
inline __host__ __device__ unsigned int power2( unsigned int value )
{
	value--;
	
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;

	value++;	

	return value;
}

template< typename T >
__device__ void swap( T& a, T& b )
{
	T tmp = a;
	a = b;
	b = tmp;
}

}

}

#endif


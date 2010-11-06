/*!
	\file MinMax.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday November 18, 2008
	\brief The headers for CUDA min max.
*/

#ifndef MIN_MAX_H_INCLUDED
#define MIN_MAX_H_INCLUDED

#include <cfloat>

namespace hydrazine
{

namespace cuda
{

template< typename T >
__device__ __host__ inline T minValue();

template< typename T >
__device__ __host__ inline T maxValue();

template< >
__device__ __host__ inline unsigned int minValue< unsigned int >()
{
	return 0;
}

template< >
__device__ __host__ inline int minValue< int >()
{
	return 0x80000000;
}

template< >
__device__ __host__ inline float minValue< float >()
{
	return FLT_MIN;
}

template< >
__device__ __host__ inline double minValue< double >()
{
	return DBL_MIN;
}

template< >
__device__ __host__ inline unsigned int maxValue< unsigned int >()
{
	return 0xFFFFFFFF;
}

template< >
__device__ __host__ inline int maxValue< int >()
{
	return 0x7FFFFFFF;
}

template< >
__device__ __host__ inline float maxValue< float >()
{
	return FLT_MAX;
}

template< >
__device__ __host__ inline double maxValue< double >()
{
	return DBL_MAX;
}

}

}

#endif


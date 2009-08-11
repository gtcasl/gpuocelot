/*! \file ocelot.cpp
	\date Friday July 24, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the Ocelot API functions.
*/

#ifndef OCELOT_CPP_INCLUDED
#define OCELOT_CPP_INCLUDED

#include <ocelot/api/interface/ocelot.h>
#include <ocelot/cuda/interface/CudaRuntime.h>

namespace cuda
{
	extern CudaRuntime runtime;
}

namespace ocelot
{

	void addTraceGenerator( trace::TraceGenerator& gen, 
		bool persistent, bool safe )
	{
		if( safe )
		{
			cuda::runtime.lock();
			cuda::runtime.setContext();		
			cuda::runtime.addTraceGenerator( gen, persistent );
			cuda::runtime.unlock();
		}
		else
		{
			cuda::runtime.addTraceGenerator( gen, persistent );
		}
	}
				
	void clearTraceGenerators( bool safe )
	{
		if( safe )
		{
			cuda::runtime.lock();
			cuda::runtime.setContext();		
			cuda::runtime.clearTraceGenerators();		
			cuda::runtime.unlock();
		}
		else
		{
			cuda::runtime.clearTraceGenerators();
		}
	}
}

#endif


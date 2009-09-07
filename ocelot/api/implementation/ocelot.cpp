/*! \file ocelot.cpp
	\date Friday July 24, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the Ocelot API functions.
*/

#ifndef OCELOT_CPP_INCLUDED
#define OCELOT_CPP_INCLUDED

#include <ocelot/api/interface/ocelot.h>
#include <ocelot/cuda/interface/CudaRuntimeInterface.h>

namespace ocelot
{

	void addTraceGenerator( trace::TraceGenerator& gen, 
		bool persistent, bool safe )
	{
		cuda::CudaRuntimeInterface::entryPoint.runtime()->addTraceGenerator( 
			gen, persistent, safe );
	}
				
	void clearTraceGenerators( bool safe )
	{
		cuda::CudaRuntimeInterface::entryPoint.runtime()->clearTraceGenerators( 
			safe );
	}
}

#endif


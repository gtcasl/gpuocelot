/*! \file ocelot.cpp
	\date Friday July 24, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the Ocelot API functions.
*/

#ifndef OCELOT_CPP_INCLUDED
#define OCELOT_CPP_INCLUDED

#include <ocelot/api/interface/ocelot.h>
#include <ocelot/cuda/interface/CudaRuntimeInterface.h>
#include <hydrazine/implementation/Exception.h>

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
	
	void limitWorkerThreads( unsigned int limit )
	{
		cuda::CudaRuntimeInterface::entryPoint.runtime()->
			limitWorkerThreads( limit );
	}

	void registerPTXModule(std::istream& stream, const std::string& name)
	{
		cuda::CudaRuntimeInterface::entryPoint.runtime()->
			registerPTXModule( stream, name );
	}
	
	KernelPointer getKernelPointer(const std::string& name,
		const std::string& module)
	{
		return cuda::CudaRuntimeInterface::entryPoint.runtime()->
			getKernelPointer( name, module );
	}

}

#endif


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
	static cuda::CudaRuntimeInterface* get() {
		return cuda::CudaRuntimeInterface::get();
	}

	void addTraceGenerator( trace::TraceGenerator& gen, 
		bool persistent )
	{
		get()->addTraceGenerator(gen, persistent );
	}
				
	void clearTraceGenerators( )
	{
		get()->clearTraceGenerators( );
	}
	
	void limitWorkerThreads( unsigned int limit )
	{
		get()->limitWorkerThreads( limit );
	}

	void registerPTXModule(std::istream& stream, const std::string& name)
	{
		get()->registerPTXModule( stream, name );
	}
	
	void clearErrors()
	{
		get()->clearErrors();
	}

	void reset()
	{
		get()->reset();
	}
	
	PointerMap contextSwitch( unsigned int destinationDevice, 
		unsigned int sourceDevice )
	{
		return std::move(get()->contextSwitch( 
			destinationDevice, sourceDevice ));
	}
	
	void unregisterModule( const std::string& name )
	{
		get()->unregisterModule( name );
	}
	
	void launch(const std::string& module, const std::string& name)
	{
		get()->launch(module, name);
	}
}

#endif


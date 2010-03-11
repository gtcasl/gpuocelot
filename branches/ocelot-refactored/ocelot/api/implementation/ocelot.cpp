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

	cuda::CudaRuntimeInterface * get() {
		return cuda::CudaRuntimeInterface::get();
	}

	void addTraceGenerator( trace::TraceGenerator& gen, 
		bool persistent, bool safe )
	{
		get()->addTraceGenerator(gen, persistent, safe );
	}
				
	void clearTraceGenerators( bool safe )
	{
		get()->clearTraceGenerators( safe );
	}
	
	void limitWorkerThreads( unsigned int limit )
	{
		get()->limitWorkerThreads( limit );
	}

	void registerPTXModule(std::istream& stream, const std::string& name)
	{
		get()->registerPTXModule( stream, name );
	}
	
	KernelPointer getKernelPointer(const std::string& name,
		const std::string& module)
	{
		return get()->getKernelPointer( name, module );
	}

	void** getFatBinaryHandle(const std::string& name)
	{
		return get()->getFatBinaryHandle( name );
	}
	
	void clearErrors()
	{
		get()->clearErrors();
	}

	void reset()
	{
		get()->reset();
	}
	
	void contextSwitch( unsigned int destinationDevice, 
		unsigned int sourceDevice )
	{
		get()->contextSwitch( destinationDevice, sourceDevice );
	}
	
	void unregisterModule( const std::string& name )
	{
		get()->unregisterModule( name );
	}

}

#endif


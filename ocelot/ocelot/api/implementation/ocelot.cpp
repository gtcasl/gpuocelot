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
	
	void registerExternalKernel(ExternalKernel kernel, const std::string &name)
	{

	}

	KernelPointer getKernelPointer(const std::string& name,
		const std::string& module)
	{
		return cuda::CudaRuntimeInterface::entryPoint.runtime()->
			getKernelPointer( name, module );
	}

	void** getFatBinaryHandle(const std::string& name)
	{
		return cuda::CudaRuntimeInterface::entryPoint.runtime()->
			getFatBinaryHandle( name );
	}
	
	void clearErrors()
	{
		cuda::CudaRuntimeInterface::entryPoint.runtime()->clearErrors();
	}

	void reset()
	{
		assertM( false, "Ocelot API function reset is not implemented." );
	}
	
	void contextSwitch(unsigned int destinationDevice, 
		unsigned int sourceDevice)
	{
		assertM( false, "Ocelot API contextSwitch is not implemented." );
	}

	void callKernel(KernelPointer kernel, ...)
	{
		KernelPointer *parameters = &kernel;
		while (*(++parameters) != kernel) { }
		size_t paramSize = (size_t)(parameters - &kernel - sizeof(kernel));

		report("Paramter block size: " << paramSize);
		assertM( false, "Ocelot API callKernel not implemented.");
	}

	executive::Executive& executive()
	{
		return cuda::CudaRuntimeInterface::entryPoint.runtime()->executive();
	}
	
	void unregisterModule( const std::string& name )
	{
		assertM( false, "Ocelot API unregisterModule is not implemented." );
	}


}

#endif


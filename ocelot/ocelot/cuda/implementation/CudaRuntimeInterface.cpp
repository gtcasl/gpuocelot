/*! \file CudaRuntimeInterface.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Saturday September 5, 2009
	\brief The source file for the CudaRuntimeInterface class.
*/

#ifndef CUDA_RUNTIME_INTERFACE_CPP_INCLUDED
#define CUDA_RUNTIME_INTERFACE_CPP_INCLUDED

#include <ocelot/cuda/interface/CudaRuntimeInterface.h>
#include <ocelot/cuda/interface/CudaRuntimeBase.h>
#include <ocelot/cuda/interface/TraceGeneratingCudaRuntime.h>
#include <hydrazine/implementation/XmlParser.h>
#include <hydrazine/implementation/Exception.h>

namespace cuda
{
	CudaRuntimeInterface::EntryPoint CudaRuntimeInterface::entryPoint;
	
	CudaRuntimeInterface::EntryPoint::EntryPoint()
	{
		Configuration config;
	
		try
		{
			report( "Loading config file config.ocelot" );
			hydrazine::XmlParser parser( "config.ocelot" );
			hydrazine::XmlTree tree = parser.tree();
			hydrazine::XmlTree::iterator fi = tree.begin();
		
			fi.descend("ocelot");
			fi.descend("CudaRuntime");
		
			config = fi.map();
		}
		catch( const hydrazine::Exception& e )
		{
			report( "Failed to load config file" );
		}
	
		configure( config );
	}
	
	CudaRuntimeInterface::EntryPoint::~EntryPoint()
	{
		delete _runtime;
	}
	
	CudaRuntimeInterface* CudaRuntimeInterface::EntryPoint::runtime()
	{
		return _runtime;
	}
	
	void CudaRuntimeInterface::EntryPoint::configure( const Configuration& c )
	{
		std::string runtime;
		
		parse( "CudaRuntimeImplementation", runtime, "", c );
		
		if( runtime == "TraceGeneratingCudaRuntime" )
		{
			_runtime = new TraceGeneratingCudaRuntime;
		}
		else
		{
			_runtime = new CudaRuntimeBase;
		}
	}
	
	CudaRuntimeInterface::~CudaRuntimeInterface()
	{
	
	}
}

#endif


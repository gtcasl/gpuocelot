/*! \file ResourceMonitor.cpp
	\date Wednesday Nov 30, 2010
	\author Si Li <sli@gatech.edu>
	\brief The source file for the ResourceMonitor class.
*/

#ifndef RESOURCE_MONITOR_CPP_INCLUDED
#define RESOURCE_MONITOR_CPP_INCLUDED

// Ocelot includes
#include <ocelot/trace/interface/ResourceMonitor.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/Device.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

// hydrazine includes
#include <hydrazine/implementation/Exception.h>

#include <fstream>

namespace trace
{
	ResourceMonitor::Allocation::Allocation( bool v, ir::PTXU64 b, ir::PTXU64 e )
		: valid( v ), base( b ), extent( e )
	{
	
	}
	
//	void ResourceMonitor::_gatherGlobalAllocation()
//	{
//		if( _cache.base > *address 
//			|| *address >= _cache.base + _cache.extent
//			|| !_cache.valid )
//		{
//			const executive::Device::MemoryAllocation* allocation = 
//				_device->getMemoryAllocation( (void*)*address, 
//					executive::Device::AnyAllocation );
//			if( allocation == 0 )
//			{
//				globalMemoryError( _device, _dim,
//					thread, *address, e.memory_size, e, _kernel );
//			}
//			_cache.base = ( ir::PTXU64 ) allocation->pointer();
//			_cache.extent = allocation->size();
//			if( *address >= _cache.base + _cache.extent )
//			{
//				globalMemoryError( _device, _dim,
//					thread, *address, e.memory_size, e, _kernel );
//			}
//		}	
//	}

	
	ResourceMonitor::ResourceMonitor() : _cache( false ), _parameter( true ), 
		_shared( true ), _local( true ), _constant( true )
	{
		
	}	
	
	void ResourceMonitor::initialize( const executive::ExecutableKernel& kernel )
	{
		_dim = kernel.blockDim();
	
		_device = kernel.device;
		
		_cache.valid = false;

		_parameter.base = 0;
		_parameter.extent = kernel.parameterMemorySize();

		_constant.base = 0;
		_constant.extent = kernel.constMemorySize();
		
		_shared.base = 0;
		_shared.extent = kernel.totalSharedMemorySize();
		
		_local.base = 0;
		_local.extent = kernel.localMemorySize();
		
		_kernel = static_cast< const executive::EmulatedKernel* >( &kernel );
		unsigned int totalGlobalAllocationSize = _device->getTotalGlobalAllocation();
		
		
        out = new std::fstream("/proc/gpuinfo", std::fstream::out);

//		will get blocked on lock (acquired by _launchKernel in CudaRuntime)        
//		cudaDeviceProp deviceProp;
//		cudaGetDeviceProperties(&deviceProp, 0);
//		std::cout << deviceProp.name << "\n";

		//print to proc entry
		*out << "Total global memory usage: " << totalGlobalAllocationSize
			<< "B\n";
		out->close();
	}

	void ResourceMonitor::event(const TraceEvent& event)
	{
		//null
	}
	
	void ResourceMonitor::finish()
	{
		//clear resource usage stats in proc entry
		out = new std::fstream("/proc/gpuinfo", std::fstream::trunc);
		*out << "Total global memory usage: 0B\n";
		out->close();
	}
}

#endif


/*! \file MemoryChecker.cpp
	\date Wednesday March 17, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the MemoryChecker class.
*/

#ifndef MEMORY_CHECKER_CPP_INCLUDED
#define MEMORY_CHECKER_CPP_INCLUDED

// Ocelot includes
#include <ocelot/trace/interface/MemoryChecker.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/Device.h>

// hydrazine includes
#include <hydrazine/implementation/Exception.h>

namespace trace
{
	MemoryChecker::Allocation::Allocation( bool v, ir::PTXU64 b, ir::PTXU64 e )
		: valid( v ), base( b ), extent( e )
	{
	
	}
	
	static std::string prefix( unsigned int thread, const ir::Dim3& dim, 
		const TraceEvent& e )
	{
		const unsigned int cta = e.blockId.x + e.blockId.y * dim.x 
			+ dim.x * dim.y * e.blockId.z;
		
		std::stringstream stream;
		stream << "[PC " << e.PC << "] ";
		stream << "[thread " << thread << "] ";
		stream << "[cta " << cta << "] ";
		stream << e.instruction->toString() << " - ";
		
		return stream.str();
	}
	
	static void alignmentError( const executive::EmulatedKernel* kernel, 
		const ir::Dim3& dim, const TraceEvent& e, unsigned int thread, 
		ir::PTXU64 address, unsigned int size )
	{
		std::stringstream stream;
		stream << prefix( thread, dim, e );
		stream << "Memory access " << (void*)address 
			<< " is not aligned to the access size ( " << size << " bytes )";
		stream << "\n";
		stream << "Near " << kernel->location( e.PC ) << "\n";
		throw hydrazine::Exception( stream.str() );
	}
	
	template< unsigned int size >
	static void checkAlignment( const executive::EmulatedKernel* kernel, 
		const ir::Dim3& dim, const TraceEvent& e )
	{
		TraceEvent::U64Vector::const_iterator 
			address = e.memory_addresses.begin();
		unsigned int threads = e.active.size();
		for( unsigned int thread = 0; thread < threads; ++thread )
		{
			if( !e.active[ thread ] ) continue;
			if( *address & ( size - 1 ) )
			{
				alignmentError( kernel, dim, e, thread, *address, size );
			}
			++address;
		}
	}
	
	void MemoryChecker::_checkAlignment( const TraceEvent& e )
	{		
		switch(e.memory_size)
		{
			case 1: return;
			case 2: checkAlignment< 2 >( _kernel, _dim, e ); break;
			case 4: checkAlignment< 4 >( _kernel, _dim, e ); break;
			case 8: checkAlignment< 8 >( _kernel, _dim, e ); break;
			case 16: checkAlignment< 16 >( _kernel, _dim, e ); break;
			case 32: checkAlignment< 32 >( _kernel, _dim, e ); break;
			default: break;
		}
	}

	static void memoryError( const std::string& space, const ir::Dim3& dim, 
		unsigned int thread, ir::PTXU64 address, unsigned int size, 
		const TraceEvent& e, const executive::EmulatedKernel* kernel, 
		const MemoryChecker::Allocation& allocation )
	{
		std::stringstream stream;
		stream << prefix( thread, dim, e );
		stream << space << " memory access " << (void*) address 
			<< " (" << size << " bytes) is beyond allocated block size " 
			<< allocation.extent;
		stream << "\n";
		stream << "Near " << kernel->location( e.PC ) << "\n";
		throw hydrazine::Exception( stream.str() );
	}

	static void globalMemoryError(const executive::Device* device, 
		const ir::Dim3& dim, unsigned int thread, ir::PTXU64 address, 
		unsigned int size, const TraceEvent& event, 
		const executive::EmulatedKernel* kernel)
	{
		std::stringstream stream;
		stream << prefix( thread, dim, event );
		stream << "Global memory access " << (void*)address 
			<< " is not within any allocated or mapped range.\n\n";
		stream << "Nearby Device Allocations\n";
		stream << device->nearbyAllocationsToString( (void*)address );
		stream << "\n";
		stream << "Near " << kernel->location( event.PC ) << "\n";
		throw hydrazine::Exception( stream.str() );
	}

	static void checkLocalAccess( const std::string& space, const ir::Dim3& dim,
		const MemoryChecker::Allocation& allocation, const TraceEvent& event, 
		const executive::EmulatedKernel* kernel )
	{
		TraceEvent::U64Vector::const_iterator 
			address = event.memory_addresses.begin();

		unsigned int threads = event.active.size();
		for( unsigned int thread = 0; thread < threads; ++thread )
		{
			if( !event.active[ thread ] ) continue;
			if( allocation.base > *address 
				|| *address >= allocation.base + allocation.extent )
			{
				memoryError( space, dim, thread, 
					*address, event.memory_size, event, kernel, allocation );
			}
			++address;
		}
	}

	void MemoryChecker::_checkValidity( const TraceEvent& e )
	{
		switch( e.instruction->addressSpace )
		{
			case ir::PTXInstruction::Global:
			{
				TraceEvent::U64Vector::const_iterator 
					address = e.memory_addresses.begin();

				unsigned int threads = e.active.size();
				for( unsigned int thread = 0; thread < threads; ++thread )
				{
					if( !e.active[ thread ] ) continue;
					if( _cache.base > *address 
						|| *address >= _cache.base + _cache.extent
						|| !_cache.valid )
					{
						const executive::Device::MemoryAllocation* allocation = 
							_device->getMemoryAllocation( (void*)*address, 
								executive::Device::AnyAllocation );
						if( allocation == 0 )
						{
							globalMemoryError( _device, _dim,
								thread, *address, e.memory_size, e, _kernel );
						}
						_cache.base = ( ir::PTXU64 ) allocation->pointer();
						_cache.extent = allocation->size();
						if( *address >= _cache.base + _cache.extent )
						{
							globalMemoryError( _device, _dim,
								thread, *address, e.memory_size, e, _kernel );
						}
					}
					++address;
				}
				break;
			}
			case ir::PTXInstruction::Local: checkLocalAccess( "Local", _dim,
				_local, e, _kernel ); break;
			case ir::PTXInstruction::Param: checkLocalAccess( "Parameter", _dim, 
				_parameter, e, _kernel ); break;
			case ir::PTXInstruction::Shared: checkLocalAccess( "Shared", _dim, 	
				_shared, e, _kernel ); break;
			case ir::PTXInstruction::Const: checkLocalAccess( "Constant", _dim, 
				_constant, e, _kernel ); break;
			default: break;
		}
	}
	
	void MemoryChecker::_checkInitialized( const TraceEvent& e )
	{
		// TODO: implement this
	}
	
	MemoryChecker::MemoryChecker() : _cache( false ), _parameter( true ), 
		_shared( true ), _local( true ), _constant( true )
	{
	
	}	
	
	void MemoryChecker::initialize( const executive::ExecutableKernel& kernel )
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
	}

	void MemoryChecker::event(const TraceEvent& event)
	{
		const bool isMemoryOperation = 
			event.instruction->opcode == ir::PTXInstruction::Ld
			|| event.instruction->opcode == ir::PTXInstruction::St
			|| event.instruction->opcode == ir::PTXInstruction::Atom;
		
		if( !isMemoryOperation ) return;
		
		_checkAlignment( event );
		_checkValidity( event );
		_checkInitialized( event );
	}
	
	void MemoryChecker::finish()
	{

	}
}

#endif


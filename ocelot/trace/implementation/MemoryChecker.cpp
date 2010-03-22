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
#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/executive/interface/Executive.h>

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
	
	static void alignmentError( const ir::Dim3& dim, 
		const TraceEvent& e, unsigned int thread, ir::PTXU64 address, 
		unsigned int size )
	{
		std::stringstream stream;
		stream << prefix( thread, dim, e );
		stream << "Memory access " << (void*)address 
			<< " is not aligned to the access size ( " << size << " bytes )";
		throw hydrazine::Exception( stream.str() );
	}
	
	template< unsigned int size >
	static void checkAlignment( const ir::Dim3& dim, const TraceEvent& e )
	{
		TraceEvent::U64Vector::const_iterator 
			address = e.memory_addresses.begin();
		unsigned int threads = e.active.size();
		for( unsigned int thread = 0; thread < threads; ++thread )
		{
			if( !e.active[ thread ] ) continue;
			if( *address & ( size - 1 ) )
			{
				alignmentError( dim, e, thread, *address, size );
			}
			++address;
		}
	}
	
	void MemoryChecker::_checkAlignment( const TraceEvent& e )
	{		
		switch(e.memory_size)
		{
			case 1: return;
			case 2: checkAlignment< 2 >( _dim, e ); break;
			case 4: checkAlignment< 4 >( _dim, e ); break;
			case 8: checkAlignment< 8 >( _dim, e ); break;
			case 16: checkAlignment< 16 >( _dim, e ); break;
			case 32: checkAlignment< 32 >( _dim, e ); break;
			default: break;
		}
	}

	static void memoryError( const std::string& space, const ir::Dim3& dim, 
		unsigned int thread, ir::PTXU64 address, unsigned int size, 
		const TraceEvent& e, const MemoryChecker::Allocation& allocation )
	{
		std::stringstream stream;
		stream << prefix( thread, dim, e );
		stream << space << " memory access " << (void*) address 
			<< " (" << size << " bytes) is beyond allocated block size " 
			<< allocation.extent;
		throw hydrazine::Exception( stream.str() );
	}

	static void globalMemoryError( const executive::Executive* executive, 
		const ir::Dim3& dim, unsigned int thread, ir::PTXU64 address, 
		unsigned int size, const TraceEvent& event )
	{
		std::stringstream stream;
		stream << prefix( thread, dim, event );
		stream << "Global memory access " << address 
			<< " is not within any allocated or mapped range.";
		stream << executive::Executive::nearbyAllocationsToString( *executive, 
			(void*)address );
		throw hydrazine::Exception( stream.str() );
	}

	static void checkLocalAccess( const std::string& space, const ir::Dim3& dim,
		const MemoryChecker::Allocation& allocation, const TraceEvent& event )
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
					*address, event.memory_size, event, allocation );
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

				if( !_cache.valid )
				{
					unsigned int thread = 0;
					while( !e.active[ thread ] ) ++thread;
					globalMemoryError( _context, _dim, thread, 
						*address, e.memory_size, e );
				}

				unsigned int threads = e.active.size();
				for( unsigned int thread = 0; thread < threads; ++thread )
				{
					if( !e.active[ thread ] ) continue;
					if( _cache.base > *address 
						|| *address >= _cache.base + _cache.extent )
					{
						const executive::MemoryAllocation* allocation = 
							_context->getMemoryAllocation( (void*)*address );
						if( allocation == 0 )
						{
							globalMemoryError( _context, _dim,
								thread, *address, e.memory_size, e );
						}
						_cache.base = ( ir::PTXU64 ) allocation->get();
						_cache.extent = allocation->size();
						if( *address >= _cache.base + _cache.extent )
						{
							globalMemoryError( _context, _dim,
								thread, *address, e.memory_size, e );
						}
					}
					++address;
				}
				break;
			}
			case ir::PTXInstruction::Local: checkLocalAccess( "Local", _dim,
				_local, e ); break;
			case ir::PTXInstruction::Param: checkLocalAccess( "Parameter", _dim, 
				_parameter, e ); break;
			case ir::PTXInstruction::Shared: checkLocalAccess( "Shared", _dim, 	
				_shared, e ); break;
			case ir::PTXInstruction::Const: checkLocalAccess( "Constant", _dim, 
				_constant, e ); break;
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
	
	void MemoryChecker::initialize( const ir::ExecutableKernel& kernel )
	{
		_device = kernel.context->getSelectedDevice();
		
		const executive::MemoryAllocation* 
			allocation = kernel.context->getMemoryAllocation( 0 );
		
		_cache.valid = allocation != 0;

		if( _cache.valid )
		{
			_cache.base = ( ir::PTXU64 ) allocation->get();
			_cache.extent = allocation->size();
		}
		
		_parameter.base = 0;
		_parameter.extent = kernel.parameterMemorySize();
		
		_shared.base = 0;
		_shared.extent = kernel.totalSharedMemorySize();
		
		_local.base = 0;
		_local.extent = kernel.localMemorySize();
		
		_context = kernel.context;
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


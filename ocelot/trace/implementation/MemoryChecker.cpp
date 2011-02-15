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

	static void uninitError( const ir::Dim3& dim,
		unsigned int thread, const TraceEvent& event, 
		const executive::EmulatedKernel* kernel)
	{
		std::stringstream stream;
		stream << prefix( thread, dim, event );
		stream << "Control flow directed by undefined value";
		stream << "\n";
		stream << "Near " << kernel->location( event.PC ) << "\n";
		throw hydrazine::Exception( stream.str() );
	}
	
	static void memoryUninitError( const std::string& space, const ir::Dim3& dim, 
		const executive::Device* device, 
		unsigned int thread, ir::PTXU64 address, 
		unsigned int size, const TraceEvent& event, 
		const executive::EmulatedKernel* kernel)
	{
		std::stringstream stream;
		stream << prefix( thread, dim, event );
		stream << space << " memory access " << (void*)address 
			<< " to an uninitialized memory location.\n\n";
		stream << "Nearby Device Allocations\n";
		stream << device->nearbyAllocationsToString( (void*)address );
		stream << "\n";
		stream << "Near " << kernel->location( event.PC ) << "\n";
		throw hydrazine::Exception( stream.str() );
	}
	
	static void memoryError( const std::string& space, const ir::Dim3& dim, 
		unsigned int thread, ir::PTXU64 address, unsigned int size, 
		const TraceEvent& e, const executive::EmulatedKernel* kernel, 
		unsigned int extent )
	{
		std::stringstream stream;
		stream << prefix( thread, dim, e );
		stream << space << " memory access " << (void*) address 
			<< " (" << size << " bytes) is beyond allocated block size " 
			<< extent;
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
		ir::PTXU64 base, ir::PTXU64 extent,
		const TraceEvent& event, const executive::EmulatedKernel* kernel )
	{
		TraceEvent::U64Vector::const_iterator 
			address = event.memory_addresses.begin();

		unsigned int threads = event.active.size();
		for( unsigned int thread = 0; thread < threads; ++thread )
		{
			if( !event.active[ thread ] ) continue;
			if( base > *address || *address >= base + extent )
			{
				memoryError( space, dim, thread, 
					*address, event.memory_size, event, kernel, extent );
			}
			++address;
		}
	}

	void MemoryChecker::_checkValidity( const TraceEvent& e )
	{
		switch( e.instruction->addressSpace )
		{
			case ir::PTXInstruction::Generic:
			{
				TraceEvent::U64Vector::const_iterator 
					address = e.memory_addresses.begin();

				unsigned int threads = e.active.size();
				for( unsigned int thread = 0; thread < threads; ++thread )
				{
					if( !e.active[ thread ] ) continue;
					if(_kernel->totalSharedMemorySize() > 0)
					{
						if( (ir::PTXU64)_kernel->getSharedMemory() <= *address 
							&& *address < (ir::PTXU64)_kernel->getSharedMemory()
							+ _shared.extent )
						{
							++address;
							continue;
						}
					}
					if( (ir::PTXU64)_kernel->getLocalMemory(thread) <= *address 
						&& *address < (ir::PTXU64)_kernel->getLocalMemory(thread)
						+ _local.extent )
					{
						++address;
						continue;
					}
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
				_local.base, _local.extent, e, _kernel ); break;
			case ir::PTXInstruction::Param:
			{
				if( e.instruction->a.isArgument )
				{
					checkLocalAccess( "Argument", _dim, 
						0, _kernel->getCurrentFrameArgumentMemorySize(),
						e, _kernel );
				}
				else
				{
					checkLocalAccess( "Parameter", _dim, 
						0, _kernel->getCurrentFrameParameterMemorySize(),
						e, _kernel );
				}
				break;
			}
			case ir::PTXInstruction::Shared: checkLocalAccess( "Shared", _dim, 	
				_shared.base, _shared.extent, e, _kernel ); break;
			case ir::PTXInstruction::Const: checkLocalAccess( "Constant", _dim, 
				_constant.base, _constant.extent, e, _kernel ); break;
			default: break;
		}
	}
	
	MemoryChecker::Status MemoryChecker::ShadowMemory::checkRegion( 
		const unsigned int idx, const unsigned int size )
	{
		Status currStatus = DEFINED;
		for (unsigned int i=0; i < size; i++)
		{
			if(currStatus > map[idx+i])
				currStatus = map[idx+i];
		}
		
		return currStatus;
	}

	void MemoryChecker::ShadowMemory::setRegion(const unsigned int idx, 
		const unsigned int size, const Status stat)
	{
		if( idx+size-1 >= map.size() )
			std::cout << "idx+size-1: " << idx+size-1 << " map.size(): " 
				<< map.size() << "\n";
		for (unsigned int i=0; i < size; i++)
		{
				map[idx+i] = stat;
		}
		
	}

	MemoryChecker::Status MemoryChecker::ShadowMemory::checkRegister(
		const ir::PTXOperand::RegisterType idx)
	{
		if (map[(unsigned int)idx] < DEFINED) {
			return NOT_DEFINED;
		}
		return DEFINED;
	}

	void MemoryChecker::ShadowMemory::setRegister(
		const ir::PTXOperand::RegisterType idx, const Status stat)
	{
		assert( (unsigned int)idx < map.size() );
		map[(unsigned int)idx] = stat;
	}

	void checkInitialized( const std::string& space, const ir::Dim3& dim, 
		const TraceEvent& e, 
		MemoryChecker::ShadowMemory &shadowMem, 
		MemoryChecker::ShadowMemory &registerFileShadow )
	{
		TraceEvent::U64Vector::const_iterator 
			address = e.memory_addresses.begin();
		unsigned int threads = e.active.size();
		unsigned int regPerThread = registerFileShadow.size()/threads;	
		
		if ( e.instruction->opcode == ir::PTXInstruction::Ld )
        {	
            for( unsigned int thread = 0; thread < threads; ++thread )
		    {
			    if( !e.active[ thread ] ) continue;
			    
				unsigned int index = *address;	
				ir::PTXOperand d = e.instruction->d;
				MemoryChecker::Status varStatus = shadowMem.checkRegion(index, e.memory_size);
				unsigned int regIdx = d.reg+thread*regPerThread;
			    registerFileShadow.setRegister(regIdx, varStatus);
			    ++address;

			    if (varStatus < MemoryChecker::DEFINED)
			    {
					std::cout << prefix( thread, dim, e )
						<< "Loading uninitialized value\n";
				}
		    }
		} 
		else if( e.instruction->opcode == ir::PTXInstruction::St )
        {						

			ir::PTXOperand a = e.instruction->a;
            for( unsigned int thread = 0; thread < threads; ++thread )
		    {
			    if( !e.active[ thread ] ) continue;
			    
				unsigned int pmIndex = *address;		
				unsigned int regIdx = a.reg+thread*regPerThread;
				
				MemoryChecker::Status varStatus = registerFileShadow.checkRegister(regIdx);
				shadowMem.setRegion(pmIndex, e.memory_size, varStatus);
			    ++address;

			    if (varStatus < MemoryChecker::DEFINED)
			    {
					std::cout << prefix( thread, dim, e )
						<< "Storing uninitialized value\n";
				}
		    }
		} else {
			std::cout << space << " instruction but not load or stored";
		}
	}
	
	void MemoryChecker::_checkInitialized( const TraceEvent& e )
	{
		
		TraceEvent::U64Vector::const_iterator 
			address = e.memory_addresses.begin();
		unsigned int threads = e.active.size();
		unsigned int regPerThread = _registerFileShadow.size()/threads;	
		
		switch( e.instruction->addressSpace )
		{
			case ir::PTXInstruction::Shared:
				checkInitialized( "Shared", _dim, e, _sharedShadow, 
					_registerFileShadow);
				break;
			case ir::PTXInstruction::Local:
				checkInitialized( "Local", _dim, e, _localShadow, 
					_registerFileShadow);
				break;
			default: 	//global and constant
			{
                if ( e.instruction->opcode == ir::PTXInstruction::Ld )
                {	
                	
					ir::PTXOperand d = e.instruction->d;
				
                    for( unsigned int thread = 0; thread < threads; ++thread )
				    {
					    if( !e.active[ thread ] ) continue;

					    unsigned int regIdx = d.reg+thread*regPerThread;
					    _registerFileShadow.setRegister(regIdx, DEFINED);
					    ++address;
				    }
				}
				else if( e.instruction->opcode == ir::PTXInstruction::St )
                {	
                	for( unsigned int thread = 0; thread < threads; ++thread )
				    {
					    if( !e.active[ thread ] ) continue;
					    						
						ir::PTXOperand a = e.instruction->a;
						unsigned int regIdx = a.reg+thread*regPerThread;
						
						Status varStatus = _registerFileShadow.checkRegister(regIdx);
					    ++address;

					    if (varStatus < DEFINED)
					    {
					    	memoryUninitError( "Global", _dim, _device,
								thread, *address, e.memory_size, e, _kernel );
						}
				    }
				}
				break;
			}
		}

	}

	void setRegisterStatus( MemoryChecker::ShadowMemory &registerFile, 
		const ir::PTXInstruction &inst, unsigned int regOffset, 
		MemoryChecker::Status stat )
	{
		int regDIdx;
		if ( inst.opcode == ir::PTXInstruction::Tex)
		{
			for( int i=0; i < 4; i++ )
			{
				regDIdx = inst.d.array[i].reg + regOffset;
				registerFile.setRegister( regDIdx, stat );
			}
		}
		else
		{
			regDIdx = inst.d.reg + regOffset;
			registerFile.setRegister( regDIdx, stat );
		}
	}
	
	void MemoryChecker::_trackInstructions( const TraceEvent& e )
	{
		const unsigned int threads = e.active.size();
		const ir::PTXInstruction inst = *(e.instruction);
		unsigned int regPerThread = _registerFileShadow.size()/threads;
		bool errorFlag;
		
		switch( inst.opcode )
		{
			case ir::PTXInstruction::SetP:
			case ir::PTXInstruction::SelP:
				errorFlag = true;
				break;
			default: 
				errorFlag = false;
				break;
		}

		const ir::PTXOperand * operands[] = { &inst.a, &inst.b, &inst.c };
		unsigned int operandSize = sizeof( operands )/sizeof( operands[0] );
		
		for( unsigned int thread = 0; thread < threads; ++thread )
		{
			if( !e.active[ thread ] ) continue;
			
			if( inst.d.addressMode == ir::PTXOperand::Register )
			{
				setRegisterStatus(_registerFileShadow, inst, 
					thread*regPerThread, DEFINED);
			}

			//exception for XOR Rx Ry Ry; Rx always defined
			if( inst.opcode == ir::PTXInstruction::Xor )
			{
				if( inst.a.reg == inst.b.reg )
					return;
			}
			//check for structure (_1D, _2D, _3D == # of elem in C.array)
			unsigned int loop = 0;				
			if ( !inst.c.array.empty() )
			{
				operandSize = 2;
				switch ( inst.geometry )
				{
					case ir::PTXInstruction::_1d:
						loop = 1;
						break;
					case ir::PTXInstruction::_2d:
						loop = 2;
						break;
					case ir::PTXInstruction::_3d:
						loop = 3;
					default:
						loop = 0;
						operandSize = 3;
						break;
				}
			}
			
			for ( unsigned int i=0; i < loop; i++ )
			{
				int regIdx = inst.c.array[i].reg + thread * regPerThread;
				Status varStatus = _registerFileShadow.checkRegister(regIdx);

				if ( varStatus < DEFINED )
				{
					setRegisterStatus(_registerFileShadow, inst, 
						regPerThread*thread, NOT_DEFINED);
					
					std::cout << prefix( thread, _dim, e ) 
						<< "NOT DEFINED: register r" << regIdx << "\n";
				
					if ( errorFlag )
						uninitError( _dim, thread, e, _kernel );

					return;
				}
			}
				
			for ( unsigned int i=0; i < operandSize; i++ )
			{
				if( operands[i]->addressMode == ir::PTXOperand::Register
					&& operands[i]->reg != ir::PTXOperand::Invalid )
				{
					int regIdx = operands[i]->reg + thread * regPerThread;
					Status varStatus = _registerFileShadow.checkRegister(regIdx);

					if ( varStatus < DEFINED )
					{
						setRegisterStatus(_registerFileShadow, inst, 
							regPerThread*thread, NOT_DEFINED);
						
						std::cout << prefix( thread, _dim, e ) 
							<< "NOT DEFINED: register r" << regIdx << "\n";
					
						if ( errorFlag )
							uninitError( _dim, thread, e, _kernel );

						return;
					}
				}
			}	
		}
	}
	
	MemoryChecker::MemoryChecker() : _cache( false ),
		_shared( true ), _local( true ), _constant( true )
	{
	
	}

	void MemoryChecker::setCheckInitialization(bool toggle)
	{
		checkInitialization = toggle;
	}
	
	void MemoryChecker::initialize( const executive::ExecutableKernel& kernel )
	{
		_dim = kernel.blockDim();
	
		_device = kernel.device;
		
		_cache.valid = false;

		_constant.base = 0;
		_constant.extent = kernel.constMemorySize();
		
		_shared.base = 0;
		_shared.extent = kernel.totalSharedMemorySize();
		
		_local.base = 0;
		_local.extent = kernel.localMemorySize();
		
		_kernel = static_cast< const executive::EmulatedKernel* >( &kernel );

		ir::Dim3 blockDim = kernel.blockDim();
		int threadNum = blockDim.x * blockDim.y * blockDim.z;
		_registerFileShadow.resize(kernel.registerCount() * threadNum);
		
		_sharedShadow.resize(_shared.extent);
		_constShadow.resize(_constant.extent);
		_localShadow.resize(_local.extent);
	}

	void MemoryChecker::event(const TraceEvent& event)
	{
		const bool isMemoryOperation = 
			event.instruction->opcode == ir::PTXInstruction::Ld
			|| event.instruction->opcode == ir::PTXInstruction::Ldu
			|| event.instruction->opcode == ir::PTXInstruction::St
			|| event.instruction->opcode == ir::PTXInstruction::Atom;
			
		if( isMemoryOperation ) 
		{
			_checkAlignment( event );
			_checkValidity( event );
			if ( checkInitialization )
				_checkInitialized( event );
		} 
		else 
		{
			if ( checkInitialization )
				_trackInstructions( event );
		}
	}
	
	void MemoryChecker::finish()
	{

	}
}

#endif


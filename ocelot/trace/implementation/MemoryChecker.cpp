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
#include <hydrazine/implementation/debug.h>
#include <bitset>
#include <set>
#include <map>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1
#define REPORT_PVF 1
#define DUCHAIN 0
#define BINS 0
#define ACE 1

const bool enableLRPC = false;

#define REPORT_KERNEL_INSTRUCTIONS 0
#define MEMORY 1
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
		switch( e.memory_size )
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
		const executive::EmulatedKernel* kernel )
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
		const executive::EmulatedKernel* kernel )
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

	static void globalMemoryError( const executive::Device* device, 
		const ir::Dim3& dim, unsigned int thread, ir::PTXU64 address, 
		unsigned int size, const TraceEvent& event, 
		const executive::EmulatedKernel* kernel )
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
					if( (ir::PTXU64)_kernel->getStackBase(thread) <= *address 
						&& *address < (ir::PTXU64)_kernel->getStackBase(thread)
						+ (ir::PTXU64)_kernel->getTotalStackSize(thread))
					{
						++address;
						continue;
					}
					if( (ir::PTXU64)_kernel->getGlobalLocalMemory(thread)
						<= *address && *address
						< (ir::PTXU64)_kernel->getGlobalLocalMemory(thread)
						+ _globalLocal.extent )
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
			case ir::PTXInstruction::Local: 
			{
				bool isGlobalLocal =
					(e.instruction->opcode == ir::PTXInstruction::Ld
					&& e.instruction->a.isGlobalLocal
					&& e.instruction->a.addressMode == ir::PTXOperand::Address)
					|| (e.instruction->opcode == ir::PTXInstruction::St
					&& e.instruction->d.isGlobalLocal
					&& e.instruction->d.addressMode == ir::PTXOperand::Address);
				
				if( isGlobalLocal )
				{
					checkLocalAccess( "GlobalLocal", _dim,
						_globalLocal.base, _globalLocal.extent,
						e, _kernel );
				}
				else
				{
					checkLocalAccess( "Local", _dim,
						_local.base, _local.extent, e, _kernel );
				}
				break;
			}
			case ir::PTXInstruction::Param:
			{
				bool isArgument =
					(e.instruction->opcode == ir::PTXInstruction::Ld
					&& e.instruction->a.isArgument) ||
					(e.instruction->opcode == ir::PTXInstruction::St
					&& e.instruction->d.isArgument);
			
				if( isArgument )
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
	
	MemoryChecker::ShadowMemory::ShadowMemory( )
	{
	}

	void MemoryChecker::ShadowMemory::resize( unsigned int size )
	{
		map.resize(size, NOT_DEFINED);
	}
	
	unsigned int MemoryChecker::ShadowMemory::size()
	{
		return map.size();
	} 

	MemoryChecker::Status MemoryChecker::ShadowMemory::checkRegion( 
		const unsigned int idx, const unsigned int size)
	{
		Status currStatus = DEFINED;
		for( unsigned int i=0; i < size; i++ )
		{
			if( currStatus > map[idx+i] )
				currStatus = map[idx+i];
		}
		
		return currStatus;
	}

	void MemoryChecker::ShadowMemory::setRegion( const unsigned int idx, 
		const unsigned int size, const Status stat )
	{
		if( idx+size-1 >= map.size() )
			report( "Store address out of range by " << idx+size-1-map.size()  
				<< "\n" );
		for( unsigned int i=0; i < size; i++ )
		{
				map[idx+i] = stat;
		}
		
	}

	MemoryChecker::Status MemoryChecker::ShadowMemory::checkRegister(
		const ir::PTXOperand::RegisterType idx )
	{
		if( map[ (unsigned int) idx ] < DEFINED ) {
			return NOT_DEFINED;
		}
		return DEFINED;
	}

	void MemoryChecker::ShadowMemory::setRegister(
		const ir::PTXOperand::RegisterType idx, const Status stat )
	{
		assert( (unsigned int)idx < map.size() );
		map[ (unsigned int) idx ] = stat;
	}
	
	void setRegisterStatus( MemoryChecker::ShadowMemory &registerFile, 
		const ir::PTXInstruction &inst, unsigned int regOffset, 
		MemoryChecker::Status stat )
	{
		int regDIdx;
		if( inst.opcode == ir::PTXInstruction::Tex )
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

	MemoryChecker::Status MemoryChecker::checkInstruction( 
		const TraceEvent& e,
		bool useMemoryFlag, 
		MemoryChecker::ShadowMemory *shadowMem )
	{
		MemoryChecker::Status destStatus = MemoryChecker::DEFINED;
		TraceEvent::U64Vector::const_iterator 
			address = e.memory_addresses.begin();
			
		unsigned int threads = e.active.size();
		unsigned int regPerThread = _registerFileShadow.size()/threads;	
		const ir::PTXInstruction inst = *(e.instruction);
		std::stringstream errorOut;

		std::string space;
		switch( e.instruction->addressSpace )
		{
			case ir::PTXInstruction::Shared:
				space = "Shared";
				break;
			case ir::PTXInstruction::Local:
				space = "Local";
				break;
			default:
				break;
		}
		
		for ( unsigned int thread = 0; thread < threads; ++thread )
		{
			if ( !e.active[ thread ] ) continue;
		
			errorOut << "Undefined register:";
			ir::PTXOperand d = inst.d;
			unsigned int regD = d.reg+thread*regPerThread;
			destStatus = MemoryChecker::DEFINED;
	
			//check predicate register
			if( inst.pg.reg != ir::PTXOperand::Invalid )
			{
				MemoryChecker::Status varStatus = 
					_registerFileShadow.checkRegister(inst.pg.reg);
				if( varStatus < MemoryChecker::NOT_DEFINED )
				{
					destStatus = MemoryChecker::NOT_DEFINED;
					errorOut << "pg r" 
						<< inst.pg.reg << " ";
				}
			}

			//check register a b c
			const ir::PTXOperand * operands[] = { &inst.a, &inst.b, &inst.c };
			for ( unsigned int i=0; i < 3; i++ )
			{
				if( (operands[i]->addressMode == ir::PTXOperand::Register
					|| operands[i]->addressMode == ir::PTXOperand::Indirect) 
					&& operands[i]->reg != ir::PTXOperand::Invalid )
				{
					int regIdx = operands[i]->reg + thread * regPerThread;
					MemoryChecker::Status varStatus = 
						_registerFileShadow.checkRegister(regIdx);
				
					if( varStatus < MemoryChecker::DEFINED )
					{
						destStatus = MemoryChecker::NOT_DEFINED;
						errorOut << "r" 
							<< operands[i]->reg << " ";
					}
				}
			}	
		
			for( unsigned int i=0; i < inst.c.array.size(); i++ )
			{
				int regIdx = inst.c.array[i].reg + thread * regPerThread;
				MemoryChecker::Status varStatus = 
					_registerFileShadow.checkRegister(regIdx);

				if( varStatus < MemoryChecker::DEFINED )
				{
					destStatus = MemoryChecker::NOT_DEFINED;
					errorOut << "r" 
						<< inst.c.array[i].reg << " ";
				}
			}

			//exception for XOR Rx Ry Ry; Rx always defined
			if( inst.opcode == ir::PTXInstruction::Xor 
				&& inst.a.reg == inst.b.reg )
				return MemoryChecker::DEFINED;
			
			//check memory
			if( ( inst.opcode == ir::PTXInstruction::Ld ||
				inst.opcode == ir::PTXInstruction::Ldu ) &&
				useMemoryFlag )
			{
				MemoryChecker::Status varStatus = 
					shadowMem->checkRegion(*address, e.memory_size);
				++address;
				if( varStatus < MemoryChecker::DEFINED )
				{
					errorOut << "[thread: " << thread 
						<< "] Loading uninitialized value from " << space << 
						" address space" << "Near " << _kernel->location( e.PC ) 
						<< "\n";
					destStatus = MemoryChecker::NOT_DEFINED;
				}
			}

			//store?
			if( inst.opcode == ir::PTXInstruction::St && useMemoryFlag )
			{
				unsigned int pmIndex = *address;		
				unsigned int regIdx = inst.a.reg+thread*regPerThread;
			
				MemoryChecker::Status varStatus = 
					_registerFileShadow.checkRegister(regIdx);
				shadowMem->setRegion(pmIndex, e.memory_size, varStatus);
				++address;

				if( varStatus < MemoryChecker::DEFINED )
				{
					errorOut << "[thread: " << thread 
						<< "] Storing uninitialized value to " << space 
						<< " address space near " << "Near " << _kernel->location( e.PC ) 
						<< "\n";
				}
			}

			if( inst.opcode == ir::PTXInstruction::St 
				&& destStatus == MemoryChecker::NOT_DEFINED
				&& inst.addressSpace == ir::PTXInstruction::Global )
			{
				memoryUninitError( "Global", _dim, _device,
					thread, *address, e.memory_size, e, _kernel );
			}
			
			//store status of destination register: pg, d, or vector d
			if( inst.d.reg == ir::PTXOperand::Invalid )
			{
				if( inst.pq.addressMode == ir::PTXOperand::Invalid )
				{
					destStatus = (destStatus == MemoryChecker::NOT_DEFINED)
						? MemoryChecker::INVALID : destStatus;
					_registerFileShadow.setRegister(inst.pq.reg, destStatus);
				}
			} 
			else if( inst.d.vec != ir::PTXOperand::v1 )
			{
				for( unsigned int i=0; i < inst.d.array.size(); i++ )
				{
					_registerFileShadow.setRegister(
						inst.d.array[i].reg+thread*regPerThread, destStatus);
				}
			} else {
				_registerFileShadow.setRegister(regD, destStatus);
			}
			
			if( destStatus != MemoryChecker::DEFINED )
			{
			  
				report( prefix( thread, _dim, e ) << errorOut.str() << "\n" );
			}
			
			errorOut.str("");
		}
		return destStatus;
	}


	void MemoryChecker::_checkInitialized( const TraceEvent& e )
	{
		switch( e.instruction->addressSpace )
		{
			case ir::PTXInstruction::Shared:
				checkInstruction( e, true, &_sharedShadow );
				break;
			case ir::PTXInstruction::Local:
				checkInstruction( e, true, &_localShadow );
				break;
			default: 	//global, constant, texture
			{
				if( e.instruction->opcode == ir::PTXInstruction::Atom ||
					e.instruction->opcode == ir::PTXInstruction::Ld ||
					e.instruction->opcode == ir::PTXInstruction::Ldu )
				{	
					checkInstruction( e );
				}
				else if( e.instruction->opcode == ir::PTXInstruction::St )
				{	
					if( checkInstruction( e ) == NOT_DEFINED )
						assert(false);
				}
				break;
			}
		}
	}
	
	void MemoryChecker::_checkInstructions( const TraceEvent& e )
	{
		bool errorFlag;	
		switch( e.instruction->opcode )
		{
			case ir::PTXInstruction::Bra:
			case ir::PTXInstruction::Call:
				errorFlag = true;
				break;
			default: 
				errorFlag = false;
				break;
		}
		
		if ( checkInstruction( e ) == NOT_DEFINED && errorFlag )
			uninitError( _dim, 0, e, _kernel );
	}
	
	MemoryChecker::MemoryChecker() : _cache( false ),
		_shared( true ), _local( true ), _constant( true )
	{
	
	}

	void MemoryChecker::setCheckInitialization(bool toggle)
	{
		checkInitialization = toggle;
	}
	
			std::vector <MemoryChecker::DynInst*> MemoryChecker::DefUseChain::sharedMemInst;
			std::vector<MemoryChecker::Util> MemoryChecker::RelStructures::sharedMemory;
			std::vector<MemoryChecker::Util> MemoryChecker::RelStructures::globalMemory;
	void MemoryChecker::initialize( const executive::ExecutableKernel& kernel )
	{
		_dim = kernel.blockDim();
		_grid = kernel.gridDim();
	
		_device = kernel.device;
		
		_cache.valid = false;

		_constant.base = 0;
		
		_constant.extent = kernel.constMemorySize();
		
		_shared.base = 0;
		_shared.extent = kernel.totalSharedMemorySize();
		
		_local.base = 0;
		_local.extent = kernel.localMemorySize();
		
		_globalLocal.base = 0;
		_globalLocal.extent = kernel.globalLocalMemorySize();
		
		_kernel = static_cast< const executive::EmulatedKernel* >( &kernel );

		ir::Dim3 blockDim = kernel.blockDim();
		int threadNum = blockDim.x * blockDim.y * blockDim.z;
		_registerFileShadow.resize(kernel.registerCount() * threadNum);
		
		_sharedShadow.resize(_shared.extent);
		_constShadow.resize(_constant.extent);
		_localShadow.resize(_local.extent);

		checkPVF = true;
		//int ctaNum = _grid.x * _grid.y * _grid.z;
		//relStructures.resize(ctaNum);
		//for( auto& cta : relStructures)
		{
			relStructures.regFile.resize( threadNum);
			for( auto& threadRF : relStructures.regFile )
			{
				threadRF.clear();
				threadRF.resize(kernel.registerCount());
			}
			RelStructures::sharedMemory.resize(_shared.extent);
		}
		
		//FIXME: need to make a new duChain for each CTA
        duChain.clear();
		duChain.resize( threadNum );
		for( auto& thread : duChain )
		{
            thread.regFileInst.clear();
			thread.regFileInst.resize(kernel.registerCount(), nullptr);
		}
			DefUseChain::sharedMemInst.clear();
			DefUseChain::sharedMemInst.resize(_shared.extent);

	
//		vf.globalMemory.resize(kernel.globalMemorySize());

		_time = 0;

	}

	void MemoryChecker::event( const TraceEvent& event )
	{
		const bool isMemoryOperation = 
			event.instruction->opcode == ir::PTXInstruction::Ld
			|| event.instruction->opcode == ir::PTXInstruction::Ldu
			|| event.instruction->opcode == ir::PTXInstruction::St
			|| event.instruction->opcode == ir::PTXInstruction::Atom;

		//report( "[" << event.PC << "] " << event.instruction->toString() 
		//	<< "\n" );
			
		if( isMemoryOperation ) 
		{
			_checkAlignment( event );
			_checkValidity( event );
		}
		if( checkInitialization )
			_checkInstructions( event );
		if( checkPVF )
			_checkPVF ( event );
	}

	void MemoryChecker::incTime()
	{
		_time++;
	}

	size_t MemoryChecker::time()
	{
		return _time;
	}
	
	uint64_t MemoryChecker::getInitMask(ir::PTXOperand::DataType type)
	{
		uint64_t operandMask;
		switch (type)//e.instruction->type)
		{
			case (ir::PTXOperand::pred):
				operandMask = 0x1;
				break;
			case (ir::PTXOperand::s8):
			case (ir::PTXOperand::u8):
			case (ir::PTXOperand::b8):
				operandMask = 0xff;
				break;
			case (ir::PTXOperand::s16):
			case (ir::PTXOperand::u16):
			case (ir::PTXOperand::b16):
				operandMask = 0xffff;
				break;
			case (ir::PTXOperand::s32):
			case (ir::PTXOperand::u32):
			case (ir::PTXOperand::b32):
			case (ir::PTXOperand::f32):
				operandMask = 0xffffffff;
				break;
			case (ir::PTXOperand::s64):
			case (ir::PTXOperand::u64):
			case (ir::PTXOperand::b64):
			case (ir::PTXOperand::f64):
				operandMask = 0xffffffffffffffff;
				break;
			default:
				//may not be a valid operand, don't worry about it
				//assert(false && "not recognized operand type");
				break;
		}
		return operandMask;
	}

	void MemoryChecker::finishPVFAnalysis(const unsigned int cta, unsigned int lastCTA)
	{
		if (cta != lastCTA && cta > 0)
		{
			std::cerr << "CTA: " << lastCTA << ", " ;
			//process everything and flush data structs
			finish();

			//delete the cta
			int numRegs;
			//for(auto & CTA : relStructures)
			for( auto &threads : relStructures.regFile)
			{
                numRegs = threads.size();
				threads.clear();
				threads.resize(numRegs);
			}
			RelStructures::sharedMemory.resize(_shared.extent);

			int size = duChain.size();
			duChain.clear();
			duChain.resize(size);
			for( auto& thread : duChain )
			{
				thread.regFileInst.clear(); //need to make sure shared memory under relStructures is resized as well, and where should it be used anyway?
				thread.regFileInst.resize(numRegs, nullptr);
			}
			DefUseChain::sharedMemInst.clear();
			DefUseChain::sharedMemInst.resize(_shared.extent);
		}
	}
	uint64_t MemoryChecker::getRegister(ir::PTXOperand::DataType type, int thread, int reg,
			const TraceEvent& e)
	{
		uint64_t ret;
		switch (type)//e.instruction->type)
		{
		case (ir::PTXOperand::pred):
									ret = (uint64_t)e.execCTA->getRegAsPredicate(thread, reg);
		break;
		case (ir::PTXOperand::s8):
									ret = (uint64_t)e.execCTA->getRegAsS8(thread, reg);
		break;
		case (ir::PTXOperand::u8):
									ret = (uint64_t)e.execCTA->getRegAsU8(thread, reg);
		break;
		case (ir::PTXOperand::b8):
									ret = (uint64_t)e.execCTA->getRegAsB8(thread, reg);
		break;
		case (ir::PTXOperand::s16):
									ret = (uint64_t)e.execCTA->getRegAsS16(thread, reg);
		break;
		case (ir::PTXOperand::u16):
									ret = (uint64_t)e.execCTA->getRegAsU16(thread, reg);
		break;
		case (ir::PTXOperand::b16):
									ret = (uint64_t)e.execCTA->getRegAsB16(thread, reg);
		break;
		case (ir::PTXOperand::s32):
									ret = (uint64_t)e.execCTA->getRegAsS32(thread, reg);
		break;
		case (ir::PTXOperand::u32):
									ret = (uint64_t)e.execCTA->getRegAsU32(thread, reg);
		break;
		case (ir::PTXOperand::b32):
									ret = (uint64_t)e.execCTA->getRegAsB32(thread, reg);
		break;
		case (ir::PTXOperand::f32):
									ret = (uint64_t)e.execCTA->getRegAsF32(thread, reg);
		break;
		case (ir::PTXOperand::s64):
									ret = (uint64_t)e.execCTA->getRegAsS64(thread, reg);
		break;
		case (ir::PTXOperand::u64):
									ret = (uint64_t)e.execCTA->getRegAsU64(thread, reg);
		break;
		case (ir::PTXOperand::b64):
									ret = (uint64_t)e.execCTA->getRegAsB64(thread, reg);
		break;
		case (ir::PTXOperand::f64):
									ret = (uint64_t)e.execCTA->getRegAsF64(thread, reg);
		break;
		default:
			//don't worry about it... may not be valid operand
			//assert(false && "not recognized operand type");
			break;
		}
		return ret;
	}
	void MemoryChecker::setMask( const TraceEvent& e, unsigned int thread, Masks &ms)
	{
		const ir::PTXInstruction inst = *(e.instruction);
		std::vector<uint64_t *> ppaMasks { &ms.a, &ms.b, &ms.c, &ms.d, };
		const ir::PTXOperand * tmpOp[] = { &inst.a, &inst.b, &inst.c, &inst.d };

		//initialize masks based on operand size of instruction
		//shouldn't this be based on the operand rather than the instruction?
		uint64_t operandMask;// = getInitMask(e.instruction->type);
		for(unsigned int i=0; i<ppaMasks.size(); i++)
		{
			operandMask = getInitMask(tmpOp[i]->type);
			*ppaMasks[i] = operandMask;
		}

		uint64_t tmpA, tmpB, tmpC;
		uint64_t bitsToMaskOff, msbPos;
		uint64_t numBits;
		tmpA = getRegister(e.instruction->a.type, thread, e.instruction->a.reg, e);
		tmpB = getRegister(e.instruction->b.type, thread, e.instruction->b.reg, e);
		tmpC = getRegister(e.instruction->c.type, thread, e.instruction->c.reg, e);
		static int numOfValidOpcodes = 0;
		bool validOpcode = true;
		switch (e.instruction->opcode)
		{
			case ir::PTXInstruction::Bfe:
				ms.a = getRegister(e.instruction->a.type,
						thread, e.instruction->a.reg,e);
				ms.b = 0xff;
				ms.c = 0xff;
				//nothing from a below pos indicated by b matters
				//mask off all bits below pos
				//if tmpB = 3, then get inverse mask: 0000000111 which is 2^(3)-1, then invert
				bitsToMaskOff = ~(uint64_t)((int64_t)(pow(2.0, (double)(tmpB) )) -1);
				ms.a &= bitsToMaskOff;
				//if c is 0, then it doesn't matter what the other operands are
				if(tmpC == 0)
				{
					ms.a = 0;
					ms.b = 0;
					//always vulnerable ms.c = 0;
				}
				break;
			case ( ir::PTXInstruction::Bfi ):
				ms.b = 0xff;
				ms.c = 0xff;
				//operand b is starting position, c is length
				//get length, all bits longer then length in a is don't care
				//same as in Bfe, except no need to invert
				bitsToMaskOff = (uint64_t)((int64_t)(pow(2.0, (double)(tmpC) )) -1);
				ms.a &= bitsToMaskOff;
				break;
			case ir::PTXInstruction::Clz :
				//upper zeros and msb is important, rest are not
				if (tmpA != 0){
					//do nothing
				}
				else {
					asm ("bsr %1, %0"
							: "=r" (msbPos)
							: "r" (tmpA));
					//tmp
					ms.a = ~(uint64_t)((int64_t)(pow(2.0, (double)(tmpA-1) )) -1);
				}
				break;
			case ( ir::PTXInstruction::CNot):
				asm ("popcnt %1, %0"
						: "=r" (numBits)
						: "r" (tmpA));
				if(numBits > 1)
					ms.a = 0x0;
				else if (numBits == 1)
					ms.a = tmpA;
				//else //(numBits == 0)
				//ms.a = default
				break;
			case ir::PTXInstruction::CopySign:	//only sign bit on 32 or 64 bits
				ms.a = 0x80000000;
				if(e.instruction->a.type == ir::PTXOperand::f64)
					ms.a <<= 32;
				break;
			case ir::PTXInstruction::Mad24 :
				ms.a = 0xFFFFFF;
				ms.b = 0xFFFFFF;
				break;
			case ir::PTXInstruction::Mul24 :
				ms.a = 0xFFFFFF;
				ms.b = 0xFFFFFF;
				break;
			case ir::PTXInstruction::Or:
				tmpC = tmpA & tmpB;
				ms.a = ms.b = tmpC;
				break;
			case ir::PTXInstruction::Prmt:
				//d[15:0] indicates 4 arbitrary bytes out of 2 32bit
				//todo not yet implemented
				assert(false && "Not implemented");
				break;
			case ir::PTXInstruction::Red:
				assert(false && "Not implemented");
				break;
			case ir::PTXInstruction::SetP:
				//if equal, all ace
				//if 1 bit diff, that bit is ace
				//if both equal, all bits ACE, (nothing needs to be done)
				//if only 1 bit different, that is the ace bit
				//else no ace bits
				if(tmpA != tmpB)
				{
					tmpC = tmpA ^ tmpB;
					asm ("popcnt %1, %0"
							: "=r" (numBits)
							  : "r" (tmpC));
					if (numBits == 1)
						ms.a = tmpC;
					else if(numBits > 1)
						ms.a = ms.b = 0x0;
				}
				break;
			case ir::PTXInstruction::Shl:
				//all bits from msb to msb-len-1 are unACE
				ms.a = ms.a & (ms.a >> tmpB);
				break;
			case ir::PTXInstruction::Shr:
				//all bits from lsb to lsb+l1n-1 are unACE
				ms.a = ms.a & (ms.a << tmpB);
				break;
			case ir::PTXInstruction::SlCt:
				//tmpC is sign bit (must be signed 32bit int or float)
				ms.c = 0x80000000;
				break;
			case ( ir::PTXInstruction::Sured ):
				assert(false && "Not implemented");
				break;
			case ( ir::PTXInstruction::Vote):
				//requires knowledge of all threads values
				//if .any, as long as more than 1 thread with true, none are ace
				//if all, if more than 1 thread is false, none are ace
				//if uni, if more than 1 diff, none are ace
				//if only 1 is critical, then that one is ace
				//if all threads of critical value, all threads ace
				assert(false && "Not implemented");
				break;
			default:
				validOpcode = false;
				break;
		}
		if(validOpcode)
		{
			numOfValidOpcodes++;
			static std::set<uint64_t> pastMasks;
			static std::set<int> pastOpcodes;
			if (pastOpcodes.find(e.instruction->opcode) == pastOpcodes.end())
			{
				//std::cout << "valid opcode: " << e.instruction->opcode << std::endl;
				pastOpcodes.insert(e.instruction->opcode);
			}
			if (pastMasks.find(ms.a)==pastMasks.end() )
			{
				//std::cout
				//	  <<"a" << numOfValidOpcodes << "\n"
				//	  << std::bitset<64>(ms.a) << std::endl;
				pastMasks.insert(ms.a);
			}
			if (pastMasks.find(ms.b) == pastMasks.end())
			{
				//std::cout << "b" << numOfValidOpcodes << "\n"
				//	  << std::bitset<64>(ms.b) << std::endl;
				pastMasks.insert(ms.a);
			}
			if (pastMasks.find(ms.c) == pastMasks.end())
			{
				//std::cout << "c" << numOfValidOpcodes << "\n"
				//	  << std::bitset<64>(ms.c) << std::endl;
				pastMasks.insert(ms.a);
			}
		}
	}

	int MemoryChecker::getOperandSize(ir::PTXOperand::DataType type)
	{
		int sib = -1;
		switch(type)
		{
		case ir::PTXOperand::s8:
		case ir::PTXOperand::u8:
		case ir::PTXOperand::b8:
			sib = 8;
			break;
		case ir::PTXOperand::s16:
		case ir::PTXOperand::u16:
		case ir::PTXOperand::b16:
			sib = 16;
			break;
		case ir::PTXOperand::s32:
		case ir::PTXOperand::u32:
		case ir::PTXOperand::b32:
		case ir::PTXOperand::f32:
			sib = 32;
			break;
		case ir::PTXOperand::s64:
		case ir::PTXOperand::u64:
		case ir::PTXOperand::b64:
		case ir::PTXOperand::f64:
			sib = 64;
			break;
		case ir::PTXOperand::pred:
			sib = 1;
			break;
		default:
			sib = -1;
			break;
		}
		return sib;
	}

	void MemoryChecker::_checkPVF( const TraceEvent& e)
	{

		/* types of operations
		   readRegister = use as source operand, for ALU op or memory op (store operand, ld/st address)
		   writeRegister = destination operand, load destination
		   readMemory = load
		   writeMemory = write
		   readSharedMem = sharedLoad
		   writeSharedMem = sharedWrite
		*/
		static unsigned int lastCTA = -1;
		ir::Dim3& grid = _grid;
		const unsigned int cta = e.blockId.x + e.blockId.y * grid.x
			+ grid.x * grid.y * e.blockId.z;
		
		//FIXME temporary until bugs are ironed out
		if (cta > 1 )
			return;

		//when cta finishes execution and new one starts, finish and erase data structs to save memory
		finishPVFAnalysis(cta, lastCTA);
		lastCTA = cta;
		incTime(); //assumption: each call to _checkPVF is a new dynamic instruction (always the next one)
		
		unsigned int threads = e.active.size();

        /* For each thread within a CTA
         * For each source operand of current event.instruction
         * Create a dInst - represents current instruction
         *  Holds all reads and writes
         * Push reads and writes into corresponding per-register relEventLists
         * each dInst is pushed onto the corresponding thread's chain - a master collection of all dInsts
         * Each dInst points to other dInsts via their reads and writes
         * Other dInsts are found by getting the last action performed on a particular register
         */
		const ir::PTXInstruction inst = *(e.instruction);

		for( unsigned int thread = 0; thread < threads; ++thread )
		{
			DynInst* currDInst = new DynInst(std::string(), e.PC, time() );	//dInst
//			DynInst* currDInst = new DynInst(inst.toString(), e.PC, time() );	//dInst
			assert(currDInst);
			duChain.at(thread).chain.push_back(currDInst);

			if( !e.active[ thread ] ) continue;

			std::vector <Util>& registerFile = relStructures.regFile[thread];

			
			Masks ms;
			setMask(e, thread, ms);

			//source operands
			const ir::PTXOperand * op[] = { &inst.a, &inst.b, &inst.c };
			std::vector<uint64_t> paMask { ms.a, ms.b, ms.c, ms.d };
			
			RelEvent* it;
			for ( unsigned int i=0; i < 3; i++ )
			{
				if( op[i]->isRegister() )
				{
					int vRegID = 0;
					switch(op[i]->vec)
					{
						case ir::PTXOperand::v1:
							registerFile[op[i]->reg].lastRead = time();
							registerFile[op[i]->reg].lrPC = e.PC;
							registerFile[op[i]->reg].readCount++;
							it = new RelEvent(e.PC, time(), true, paMask[i]);
							registerFile[op[i]->reg].relEventList.push_back(it);
							registerFile[op[i]->reg].paMask = paMask[i];

							currDInst->read.push_back(new DynInst::ProgramPoint(op[i]->reg,
									duChain.at(thread).regFileInst.at(op[i]->reg), it));
							break;
						case ir::PTXOperand::v2:
						case ir::PTXOperand::v4:
							for(const auto & vReg : op[i]->array )
							{
								registerFile[vReg.reg].lastRead = time();
								registerFile[vReg.reg].lrPC = e.PC;
								registerFile[vReg.reg].readCount++;
								it = new RelEvent(e.PC, time(), true, paMask[i]);
								registerFile[vReg.reg].relEventList.push_back(it);
								registerFile[vReg.reg].paMask = paMask[i];

								currDInst->read.push_back(new DynInst::ProgramPoint(vReg.reg,
										duChain.at(thread).regFileInst.at(vReg.reg), it));
								vRegID++;
							}
							break;
						default:
							assert(false);
							break;
					}
					// uninitialized dInst in regFile!!
					assert(duChain.at(thread).regFileInst.at(op[i]->reg)->init);
				}
			}

			//destination operand
			const ir::PTXOperand d = inst.d;
			auto sib = -1;
			auto mixedType = (d.addressMode != ir::PTXOperand::Invalid) ? d.type : inst.type;

			sib = getOperandSize(mixedType);

			if(sib != -1)
			{
				if (0)//registerFile[d.reg].sizeInBits != -1)
				{
					//DEBUG
					if (registerFile[d.reg].sizeInBits != sib)
						std::cout << inst.toString()
								  << "reg prev size: " << registerFile[d.reg].sizeInBits
								  << "current size: " << sib << std::endl;
				//	assert(registerFile[d.reg].sizeInBits == sib && "reg size don't match across insts");
				}
				if (sib > registerFile[d.reg].sizeInBits)
					registerFile[d.reg].sizeInBits = sib;
			}

			//Util &regd = reg[d.reg];
			if ( d.addressMode == ir::PTXOperand::Indirect )
			{
				registerFile[d.reg].lastRead = time();
				registerFile[d.reg].lrPC = e.PC;
				registerFile[d.reg].readCount++;
				it = new RelEvent(e.PC, time(), true, ms.d);
				registerFile[d.reg].relEventList.push_back(it );

				//treat as a read
				currDInst->read.push_back(new DynInst::ProgramPoint(d.reg,
						duChain.at(thread).regFileInst.at(d.reg), it));
				assert(duChain.at(thread).regFileInst.at(d.reg)->init);
			} 
				
			if ( d.isRegister() )
			{
				currDInst->init = true;
				switch(d.vec)
				{
					case ir::PTXOperand::v1:
						registerFile[d.reg].utilization +=
							registerFile[d.reg].lastRead - registerFile[d.reg].lastWritten;
						registerFile[d.reg].lastWritten = time();
						registerFile[d.reg].lastRead = time();
						registerFile[d.reg].lwPC = e.PC;
						registerFile[d.reg].writeCount++;
						it = new RelEvent(e.PC, time(), false, 0);
						registerFile[d.reg].relEventList.push_back(it);

						currDInst->write.push_back(new DynInst::ProgramPoint(d.reg, currDInst, it));
						duChain.at(thread).regFileInst.at(d.reg) = currDInst;
						break;
					case ir::PTXOperand::v2:
					case ir::PTXOperand::v4:
						for(const auto & vReg : d.array )
						{
							registerFile[vReg.reg].utilization +=
								registerFile[vReg.reg].lastRead - registerFile[vReg.reg].lastWritten;
							registerFile[vReg.reg].lastWritten = time();
							registerFile[vReg.reg].lastRead = time();
							registerFile[vReg.reg].lwPC = e.PC;
							registerFile[vReg.reg].writeCount++;
							it = new RelEvent(e.PC, time(), false, 0);
							registerFile[vReg.reg].relEventList.push_back(it);

							currDInst->write.push_back(new DynInst::ProgramPoint(vReg.reg, currDInst, it));
							duChain.at(thread).regFileInst.at(vReg.reg) = currDInst;
						}
						break;
					default:
						assert(false);
						break;
				}
			} else {
				//if ( d.addressMode != ir::PTXOperand::Invalid )
				//	assert(false && "unexpected destination operand?");
			}

			if( e.instruction->opcode != ir::PTXInstruction::Bra &&
					e.instruction->opcode != ir::PTXInstruction::Bar &&
					e.instruction->opcode != ir::PTXInstruction::Membar &&
					e.instruction->opcode != ir::PTXInstruction::Reconverge &&
					e.instruction->opcode != ir::PTXInstruction::Exit )
			{
			}
			
			if ( e.instruction->opcode == ir::PTXInstruction::St
					&& e.instruction->addressSpace == ir::PTXInstruction::Global)
			{
					duChain.at(thread).ace.push_back(currDInst);
			}
#if 1
            if ( e.instruction->opcode == ir::PTXInstruction::SetP )
			{
				duChain.at(thread).ace.push_back(currDInst);
				currDInst->init = true;
			}
#endif

#if MEMORY	
			std::vector <Util>& sharedMemory = RelStructures::sharedMemory;
			//std::vector <Util>& globalMemory = relStructures::globalMemory;
			if ( e.instruction->opcode == ir::PTXInstruction::Ldu
					||  e.instruction->addressSpace == ir::PTXInstruction::Generic)
			{
				assert(false && "Ldu/generic address space not supported in PVF module");
			}

			if ( e.instruction->opcode == ir::PTXInstruction::Ld)
			{
				uint64_t indAddress;
				int operandSize = -1;
				//case ir::PTXInstruction::Global:
				//	globalMemory[address].lastRead = time();
				//	break;
				if (inst.addressSpace == ir::PTXInstruction::Shared)
				{
					//get content of load register (op a)
					switch (inst.a.addressMode) {
						case ir::PTXOperand::Indirect:
							indAddress = getRegister(inst.a.type, thread, inst.a.reg, e);
							break;
						case ir::PTXOperand::Address:
						case ir::PTXOperand::Immediate:
							indAddress = inst.a.imm_uint;
							break;
						default:
							assert(false && "wrong operand address mode in _checkPVF::ld.shared ");
					}
					indAddress += inst.a.offset;
					//get size of data loaded in op d
					operandSize = getOperandSize(inst.d.type);
					uint64_t mask = getInitMask(inst.d.type);
					//mark that much data in shared memory as read (add relEvent to those locations)
					int arraySize=0;
					switch(inst.d.vec)
					{
						case (ir::PTXOperand::v1):
							arraySize = 1;
							break;
						case ir::PTXOperand::v2:
							arraySize = 2;
							break;
						case ir::PTXOperand::v4:
							arraySize = 4;
							break;
						default:
							assert("invalid vec length in st.shared d reg");
					}

					//if(thread == 0)
					{
						//std::cout << "ld.shared\topt addr: " << indAddress << "  a: " <<  inst.a.reg << " + " << inst.a.offset<< " opt d: " << inst.d.reg << " " << time() << std::endl;
					}
						//
					for(int i=0; i < arraySize; i++ )
					{
						for(int byte=0; byte < operandSize/8; byte++)
						{
							uint64_t address = indAddress++;
						//std::cout << "ld.shared address " << address << std::endl;
							sharedMemory[address].lastRead = time();
							sharedMemory[address].lrPC = e.PC;
							sharedMemory[address].readCount++;
							it = new RelEvent(e.PC, time(), true, mask);
							sharedMemory[address].relEventList.push_back(it);
							sharedMemory[address].paMask = mask;

							//link up DynInsts by their read/write dependencies
							//depends on data size and size of vector
							//assumes every location is 32bits, so
							assert(DefUseChain::sharedMemInst.at(address) != nullptr
									&& "no dynInst found");

//							std::cout << "ld sharedMemInst: thread/addr " << std::dec<< thread << "/" << address
//										<< " inst " << std::hex << (uint64_t)DefUseChain::sharedMemInst.at(address)
//										<< std::dec <<  "\n";

							currDInst->read.push_back(
									new DynInst::ProgramPoint(address,
											DefUseChain::sharedMemInst.at(address), it));
						}
					}
				}
			}
			if ( e.instruction->opcode == ir::PTXInstruction::St )
			{
				uint64_t indAddress;
				int operandSize = -1;
				int arraySize = 0;
//					case ir::PTXInstruction::Global:
//						globalMemory[address].utilization +=
//							globalMemory[address].lastRead
//							- globalMemory[address].lastWrite;
//						globalMemory[address].lastWrite = time();
//						globalMemory[address].lastRead = time();
//						break;
				if( inst.addressSpace == ir::PTXInstruction::Shared)
				{
					switch(inst.a.vec)
					{
						case ir::PTXOperand::v1:
							arraySize = 1;
							break;
						case ir::PTXOperand::v2:
							arraySize = 2;
							break;
						case ir::PTXOperand::v4:
							arraySize = 4;
							break;
						default:
							assert("invalid vec length in st.shared d reg");
					}
					//get content of store register (op d)
					switch (inst.d.addressMode) {
						case ir::PTXOperand::Indirect:
							indAddress = getRegister(inst.d.type, thread, inst.d.reg, e);
							break;
						case ir::PTXOperand::Address:
						case ir::PTXOperand::Immediate:
							indAddress = inst.d.imm_uint;
							break;
						default:
							assert(false && "wrong operand address mode in _checkPVF::ld.shared ");
					}
					indAddress += inst.d.offset;
					//get size of data loaded
					operandSize = getOperandSize(inst.a.type);
					uint64_t mask = getInitMask(inst.a.type);
					//mark that much data in shared memory as read (add relEvent to those locations)
						
					//std::cout << "st.shared\topt addr: " << indAddress << " d: " << inst.d.reg << " + " << inst.d.offset<< " opt a: " << inst.a.reg << " " << time() << std::endl;
						//
						for(int i=0; i < arraySize; i++ )
						{
							for(int byte=0; byte < operandSize/8; byte++)
							{
								uint64_t address = indAddress++;
					//std::cout << "st.shared address " << address << std::endl;
								sharedMemory[address].utilization +=
										sharedMemory[address].lastRead - sharedMemory[address].lastWritten;
								sharedMemory[address].lastWritten = time();
								sharedMemory[address].lastRead= time();
								sharedMemory[address].lwPC = e.PC;
								sharedMemory[address].writeCount++;
								it = new RelEvent(e.PC, time(), false, 0);
								sharedMemory[address].relEventList.push_back(it);
								sharedMemory[address].paMask = mask;

								//link up DynInsts by their read/write dependencies
								//depends on data size and size of vector
								//assumes every location is 32bits, so
								currDInst->write.push_back(
										new DynInst::ProgramPoint(address, currDInst, it));
//								std::cout << "st sharedMemInst: thread/addr " << std::dec << thread << "/" << address
//										<< " inst " << std::hex << (uint64_t)currDInst << std::dec << "\n";
								DefUseChain::sharedMemInst.at(address) = currDInst;
							}
						}
				}
			}
#endif
		}
	}

	void MemoryChecker::postEvent( const TraceEvent& event )
	{
		if( event.instruction->opcode == ir::PTXInstruction::Call
			|| event.instruction->opcode == ir::PTXInstruction::Ret )
		{
			_local.extent = _kernel->getCurrentFrameLocalMemorySize();
		}
	}

	size_t MemoryChecker::computePVF(){
		struct LiveRangeRecord {
			LiveRangeRecord(size_t w) : writeDInst(w) {}
			size_t writeDInst;
			size_t readDInst;
			uint64_t paMask;
		};
		std::vector<std::vector<std::vector<LiveRangeRecord> > > rflrr;
		auto threadID = 0;
		auto lastReadTime = 0;
		auto lastWriteTime = 0;
		uint64_t prevReadMask = -1;

		//iterate over each register's event list to find mask size and live range
		rflrr.resize(relStructures.regFile.size());
		for(auto & thread : relStructures.regFile )
		{
			int regID = 0;
			rflrr[threadID].resize(thread.size());
			for (auto &reg : thread )
			{
				auto &lrr = rflrr[threadID][regID];
				for (const auto relEvent : reg.relEventList )
				{
					if ( !relEvent->read ) //if write
					{
						if ( lrr.size() != 0 )
						{
							auto prevLRR = --(lrr.end());
							prevLRR->readDInst = lastReadTime;
							prevLRR->paMask = prevReadMask;
						}
						lrr.push_back(LiveRangeRecord(lastWriteTime));
						lastWriteTime = relEvent->time;
						lastReadTime = relEvent->time;	//over write previous read time stamp
					} else {
						//read
						prevReadMask = relEvent->paMask;
					}
				}
				regID++;
				if ( lrr.size() != 0 )
				{
					auto prevLRR = --(lrr.end());
					prevLRR->readDInst = lastReadTime;
					prevLRR->paMask = prevReadMask;
				}
			}
			threadID++;
		}

		//sum liverange*bits in mask
		auto totalPVF = 0;
		for (auto &thread : rflrr)
		{
			for (auto &reg : thread)
			{
				for (auto &lrRecord : reg)
				{
					uint64_t numBits;
					asm ("popcnt %1, %0"
							: "=r" (numBits)
							: "r" (lrRecord.paMask));
					auto regPVF = (lrRecord.readDInst - lrRecord.writeDInst) * numBits;
					//assert(regPVF >= 0 && "regPVF is negative");
					if (regPVF < 0 )
						std::cout << "read " << lrRecord.readDInst 
							<< " -- write " << lrRecord.writeDInst << std::endl;
				}
			}
		}
		//float totalPVFinBytes = totalPVF / 8.0;
		return totalPVF;
	}

	void MemoryChecker::printLiveRangeDuration(size_t threshold)
	{
		//for(auto& cta : relStructures)
		{
		//initialize iterators
			for(auto& thread : relStructures.regFile )
			{
				for(auto& reg : thread )
				{
					reg.it = reg.trace.begin();
					reg.itPC = reg.tracePC.begin();
				}
			}
		}

        std::vector<size_t> thresholds {1,2,3,4,5,10,20,30,40,50,100,200,300};
        
		//dump to file: list of all live ranges for each register
        std::vector<std::string> lrPCFileNames(thresholds.size());
        std::vector<std::ofstream*> lrPCFiles(thresholds.size());
        if(enableLRPC)
        {
        for ( size_t i = 0; i < thresholds.size(); ++i )
        {
            lrPCFileNames[i] = "liveRangePC" + _kernel->name + "_" + std::to_string(thresholds[i]) + ".log";
            std::cout << "writing to " << lrPCFileNames[i] << "\n";
            lrPCFiles[i] = new std::ofstream( lrPCFileNames[i] );
        }
        }
		std::string lrDurationFileName = "liveRangeDuration_" + _kernel->name + ".log";
		//std::cout << "writing to " << lrDurationFileName << "\n";
		std::ofstream lrDurationFile(lrDurationFileName); 



		//per CTA
		//find live range duration for each register
		//potentially multiple values per register
		size_t totalLRPerCTA = 0;
		int threadNum = 0;
		for(auto& thread: relStructures.regFile)
		{
			//per thread
			int regID = 0;
			int nonACE = 0;
			int relEvents = 0;

			std::stringstream durationOut;
			for( auto& reg : thread)
			{
				std::vector<std::unordered_set<size_t> > prevLRStarts(thresholds.size()), prevLREnds(thresholds.size());
				std::vector<std::stringstream> lineOuts(thresholds.size());
				std::vector<bool> lineOutFlags (thresholds.size(), false);
				for (size_t i = 0; i < thresholds.size(); ++i) {
					lineOuts[i]	<< "r" << regID << ",";
				}

				if(threadNum ==0)
					durationOut << "\nr" << regID << ": ";

				size_t lastReadTime = 0;
				size_t lastReadPC = 0;
				size_t lastWriteTime = 0;
				size_t lastWritePC = 0;
				for (auto relEvent : reg.relEventList )
				{
					if ( !relEvent->read ) //if write
					{
						durationOut << "w" << relEvent->time << " ";
						//insert new live range if greater than zero
						size_t duration =  lastReadTime - lastWriteTime;
						if ( duration >= 1 )
						{
							if ( duration > 100000 )
								assert(false && "duration larger than 100,000!");

							//record previous duration
							//durationOut << duration << " " ;
							totalLRPerCTA += duration;
							assert(duration >= 0 && "live range duration is negative");

							//record PC of live ranges
							for (size_t i = 0; i < thresholds.size(); ++i) {
								if (duration >= thresholds[i]) {
									lineOutFlags[i] = true;
								}

								//check if PC already used
								//push new PCs
								if ( prevLRStarts[i].find(lastWritePC) == prevLRStarts[i].end() )
								{
									lineOuts[i] << "s" << lastWritePC<< "," ;
									prevLRStarts[i].insert(lastWritePC);
								}

								if ( prevLREnds[i].find(lastReadPC) == prevLREnds[i].end() )
								{
									lineOuts[i] << "e" << lastReadPC  << "," ;
									prevLREnds[i].insert(lastReadPC);
								}
							}

						}
						lastWriteTime = relEvent->time;
						lastWritePC = relEvent->PC;
						lastReadTime = relEvent->time;	//over write previous read time stamp
					} else {
						if ( relEvent->ace )	//incorporate ACE analysis
						{
							durationOut << "A";
						lastReadTime = relEvent->time;
						lastReadPC = relEvent->PC;
						} else {
							++nonACE;
							durationOut << "U";
						}
						durationOut << relEvent->time << " ";
					}
					++relEvents;

					//REPEAT the above to get a potential last live range
					// (that doesn't end w/ a write)
					size_t duration =  lastReadTime - lastWriteTime;


					if ( duration >= threshold )
					{
						//if(threadNum ==0)
							//durationOut << duration << " " ;

						for (size_t i = 0; i < thresholds.size(); ++i) {
							if (duration >= thresholds[i]) {
								lineOutFlags[i] = true;
							}

							//check if PC already used
							//push new PCs
							if ( prevLRStarts[i].find(lastWritePC) == prevLRStarts[i].end() )
							{
								lineOuts[i] << "s" << lastWritePC<< "," ;
								prevLRStarts[i].insert(lastWritePC);
							}

							if ( prevLREnds[i].find(lastReadPC) == prevLREnds[i].end() )
							{
								lineOuts[i] << "e" << lastReadPC  << "," ;
								prevLREnds[i].insert(lastReadPC);
							}
						}

					}
				}
				size_t duration =  lastReadTime - lastWriteTime;
				//if(threadNum ==0)
					//durationOut << duration << " " ;

				if ( duration >= threshold )
					totalLRPerCTA += duration;
				assert(duration >= 0 && "live range duration is negative");

				++regID;
				if(enableLRPC)
				{
				for (size_t i = 0; i < thresholds.size(); ++i)
				{
					if ( true == lineOutFlags[i] )
					{
						*lrPCFiles[i] << lineOuts[i].str() << "\n";
					}
				}
				//if ( true == lineOutFlags[0] )
					//lrDurationFile << durationOut.str();
				}

				if(threadNum == 0)
					lrDurationFile<< durationOut.str();
			}
			threadNum++;
		}
		auto regPerCTA = relStructures.regFile[0].size();
		//std::cout << "total register actions: " << relEvents << "\t";
		std::cout << "total live range per CTA: " << totalLRPerCTA << "\t";
		std::cout << "\nRF size: " << regPerCTA  << "\t";
		static unsigned int lastTime = 0;
		int thisTime = time();
		thisTime -= lastTime;
		lastTime = time();
		std::cout << "# of dyn insts: " << thisTime << "\t";
		std::cout << "PVF = " << totalLRPerCTA / (float)(thisTime * regPerCTA) << "\n";
		//std::cout << "nonace register actions: " << nonACE << "\n\n";

		if (enableLRPC)
        for (auto & lrPCFile : lrPCFiles)
            lrPCFile->close();
        
		//compute pvf
		//outdated, don't care, shouldn't be using anyway
		//int avgPVF = computePVF();
		//std::cout << "average register PVF is " << avgPVF << "\n";
		lrDurationFile.close();
	}

	//FIXME still using register trace, needs to use registerActionTrace and check for ACE
	void MemoryChecker::printLiveRangePC(int threshold)
	{
		//initialize iterators
		//for(auto& cta : relStructures)
		{
			for(auto& thread : relStructures.regFile )
			{
				for(auto& reg : thread )
				{
					reg.it = reg.trace.begin();
					reg.itPC = reg.tracePC.begin();
				}
			}
		}

		//dump to file: list of all live ranges for each register
		std::cout << "writing to live-ranges.txt\n";
		std::ofstream lrFile("liveRange_" + _kernel->name + ".log");

		int regID = 0;

		//for(auto& cta : relStructures)
		{
			for( auto& reg : relStructures.regFile[regID] )
			{
				std::unordered_set<size_t> prevLRStart, prevLREnd;
				std::stringstream lineOut;
				lineOut	<< "r" << regID << ",";
				bool lineOutFlag = false;

				auto lrPC = reg.itPC;
				auto lr = reg.it;
				for ( ; lrPC != reg.tracePC.end(); ++lrPC, ++lr )
				{
					int lrDuration = lr->second - lr->first;

					if ( lr->second != 0 && lrDuration >= threshold )
					{
						lineOutFlag = true;

						if ( prevLRStart.find(lr->first) == prevLRStart.end() )
						{
							lineOut << "s" << lrPC->first << "," ;
							prevLRStart.insert(lrPC->first);
						}

						if ( prevLREnd.find(lr->second) == prevLREnd.end() )
						{
							lineOut << "e" << lrPC->second << "," ;
							prevLREnd.insert(lrPC->second);
						}
						//lineOut << lrPC->first << "," << lrPC->second << ",";

					}
				}
				++regID;
				if ( true == lineOutFlag )
					lrFile << lineOut.str() << "\n";
			}
		}
		lrFile.close();
	}
	void MemoryChecker::pvfRegFileHistogram()
	{
		//produce histogram
		std::vector<size_t> bins = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,100,200,300,400,500,1000};
		std::vector<size_t> histogram;
		histogram.resize(bins.size()+1,0); //allows for bin 1000+

		//histogram
		int totalInterval = 0;
		std::vector<size_t> intervals;
		//for(auto& cta : relStructures)
		{
			for(auto & thread: relStructures.regFile)
			{
				for(auto &reg : thread)
				{
					for(auto &use : reg.trace)
					{
						auto thispvf = use.second - use.first;
						totalInterval += thispvf;
						if(thispvf > 0)
						{
#if BINS
							auto b=bins.begin();
							int h= 0;
							for( ; b!=bins.end(); ++b,++h )
							{
								if(thispvf <= *b)
								{
									histogram.at(h)++;//(*h)++;
									break;
								}
							}
							if(thispvf > *(bins.rbegin()) )//&& h == --histogram.end())
								histogram.at(h)++;//*h++;
#else
							intervals.push_back(thispvf);
#endif
						}
					}
				}
			}
		}

		bool printStats = false;
		if (printStats)
		{
			std::string histogramName = "lvIntervals" + _kernel->name + ".list";
			std::ofstream fsh(histogramName);
			std::cout << "writing to " << histogramName << "\n";
#if BINS
			auto b = 0;
			bins.push_back(9999);
			for(auto bin : histogram)
				fsh << bins.at(b++) << "," << bin << "\n";
#else
			for(auto interval : intervals)
				fsh << interval << ",\n";
#endif
			fsh.close();

			auto threadNum = relStructures.regFile.size();
			auto regNum = relStructures.regFile[0].size();
			auto totalPotUtil = threadNum * relStructures.regFile[0].size() * time();
			float avgInterval = (float)totalInterval/(float)(regNum * threadNum);
			std::cout << "total: " << totalInterval << " regs*threads: " << regNum * threadNum
					<< " average interval " << avgInterval  << "\n";

			auto totalUtil = 0;
			//for(auto& cta : relStructures)
			{
				for(auto& thread : relStructures.regFile )
				{
					size_t perThreadUtil = 0;
					for(auto& reg : thread)
					{
						perThreadUtil += reg.utilization + reg.lastRead - reg.lastWritten;
						reg.utilization = reg.lastRead = reg.lastWritten = 0;
					}
					//std::cout << "Per Thread Utilization: "
					//	<< perThreadUtil/(float)potUtil << std::endl;
					totalUtil += perThreadUtil;
				}
			}
			std::cout << "Utilization: " << totalUtil/(float)totalPotUtil
					<< std::endl;
			totalUtil = 0;
		}
	}

	void MemoryChecker::checkMismatchedLinks()
	{
		std::cout << "\nchecking for mismatched dInsts\n";
		std::set<DynInst*> allLinks;
		auto dInstCount = 0;
		for( auto & dInst: duChain[0].chain)
		{
			++dInstCount;// += allLinks.count(dInst);
			allLinks.insert(dInst);
		}
		int nomatch = 0;
		for( auto & dInst: duChain[0].ace )
			nomatch += duChain[0].check(dInst, allLinks);

		std::cout << "chain.size() " << duChain[0].chain.size()
									<< "#dInsts: " << allLinks.size()  <<  " #dInsts: "
									<< dInstCount << "  # of mismatched dInsts: " << nomatch << "\n";
	}
	void MemoryChecker::pvfRegFile()
	{
		std::multimap<int, int> startList, endList;
		uint64_t sumThreadVuln = 0;
		uint64_t sumThreadPotentialVuln = 0;
		size_t writeTime=0, readTime=0;
		bool aceLR = false;
		auto vulnerability = 0, totalVuln = 0;
		uint64_t currentMask = 0;
		//debug
		std::vector<int> regVuln;
		regVuln.resize(relStructures.regFile[0].size());

		auto calcVuln = [&](unsigned int &threadNum, int &regNum, Util& reg, bool &aceLR, size_t &readTime,
				size_t &writeTime, uint64_t &currentMask) {
			const auto vulnTime = readTime - writeTime;
			uint64_t bitsACE = 0;
			if ( vulnTime >0 && aceLR)
			{
				asm ("popcnt %1, %0"
						: "=r" (bitsACE)
						  : "r" (currentMask));
				vulnerability += vulnTime * bitsACE;
				totalVuln += reg.sizeInBits;

				//debug
				regVuln[regNum] = vulnTime * bitsACE;
/*
				if(bitsACE > (unsigned)reg.sizeInBits )
				{
					std::cout << "thread:reg=" << std::dec << threadNum << ":" << regNum << "\n";
					if (event != nullptr)
					{
						std::cout << "PC:" << event->PC
							<< " Time: " << event->time << "\n"
							<< duChain[threadNum].chain[event->time]->opcode << "\n";
					}
						std::cout << "bitsACE: " << bitsACE
							<< " vs reg size: " << reg.sizeInBits << "\n"
							<< " mask: " << std::hex << currentMask << std::endl;
					assert(false && "error: register smaller than ace bits");
				}
//*/
				//for determining max registers and bits used
				if (threadNum == 0)
				{
					startList.insert({writeTime, bitsACE});
					endList.insert({readTime, bitsACE});
				}
			}
		};
		auto registerPVF = [&](unsigned int threadNum, int regNum, Util &reg, bool & aceLR,
				size_t &readTime, size_t &writeTime,
				size_t &currentMask)
		{
			for(auto &event : reg.relEventList)
			{
				if (event->read)
				{
					readTime = event->time;
					//take union of bitmask

					currentMask |= event->paMask;
					aceLR = event->ace;
				} else {
					//finish any previous live range
					calcVuln(threadNum, regNum, reg, aceLR, readTime, writeTime, readTime);
					//start new live range
					writeTime = readTime = event->time;
					currentMask = 0;
				}
			}
		};

		auto threadPVF = [&](unsigned int threadNum)
		{
			auto regNum = 0;
			for(auto& reg : relStructures.regFile[threadNum])
			{
				aceLR = false;
				writeTime = readTime = 0;
				currentMask = 0;
				registerPVF(threadNum, regNum, reg, aceLR, readTime, writeTime, currentMask);

				//grab size of vulnerability (duration of live range and # of ace bits in register)
				calcVuln(threadNum, regNum, reg, aceLR, readTime, writeTime, currentMask);

				regNum++;
			}
			if(0)
			{
				if(totalVuln == 0)
					std::cout << "no any vuln? ";
				else
					std::cout << "thread's RF PVF: "
					<< (double)vulnerability/(double)(time()*totalVuln) << std::endl;
			}
			sumThreadVuln += vulnerability;
			sumThreadPotentialVuln += totalVuln;
		};

		auto maxRegResources= [&](int &maxSimulRegs, int &maxBitsNeeded)
		{
			int simulRegs = 1;
			auto currEnd = endList.begin();
			auto start = startList.begin();
			int currBits = start->second;
			//skip all zero's
			while((++currEnd)->first == 0);
			while((++start)->first == 0);

			int i=0;
			int j=0;
			for( ; start != startList.end(); start++)
			{
				simulRegs++;
				currBits +=start->second;
				auto tmp = start;
				if((++tmp)->first == start->first)
					continue;
				maxSimulRegs = (simulRegs > maxSimulRegs) ? simulRegs : maxSimulRegs;
				maxBitsNeeded = (currBits > maxBitsNeeded) ? currBits : maxBitsNeeded;

				//move end iterator to match start
				while( currEnd->first <= start->first && currEnd != endList.end())
				{
					simulRegs--;
					currBits -= currEnd->second;
					currEnd++;
					j++;
				}
				i++;
			}
		};


		//////////////////////////////////////////////////////////////////////////////////////
		// Start of pvfRegFile()
		//////////////////////////////////////////////////////////////////////////////////////

		auto threadSize = relStructures.regFile.size();
		for(unsigned int threadNum=0; threadNum < threadSize; threadNum++)
			threadPVF(threadNum);

		int maxSimulRegs = 0, maxBitsNeeded = 0;
		static unsigned int lastTime = 0;
		int thisTime = time();
		thisTime -= lastTime;
		lastTime = time();

		//finds maximum # of registers and max # of bits needed per thread in hardware
		//iterate over time line, for each start encountered, increment register needed
		//for each end of live-range encountered, decrement register needed
		maxRegResources(maxSimulRegs, maxBitsNeeded);

		std::cout << "max simultaneous registers: " << maxSimulRegs
				<< "\tavg bits/reg needed " << (float)maxBitsNeeded/(float)maxSimulRegs<< "\n";

		sumThreadPotentialVuln = thisTime * threadSize * maxBitsNeeded;
		double ctaPVF = sumThreadVuln/(double)(thisTime*sumThreadPotentialVuln);
		std::cout << "CTA PVF: " << ctaPVF << std::endl;

		//output regVuln to debug file
		std::ofstream rvOut("regVuln.txt");
		for ( unsigned int i=0; i < regVuln.size(); i++)
		{
			rvOut << i << ": " << regVuln[i] << std::endl;
		}
		rvOut.close();

		//print to file dynamic instruction dependency-tree
		std::ofstream dynInstsOut("dynInsts_dependencies");
		int threadNum = 0;
		for ( auto & thread : duChain )
		{
			dynInstsOut << "thread " << threadNum << "\n";
			for (auto & inst : thread.chain)
			{
				dynInstsOut << inst->time << ": ";
				for (auto & read : inst->read)
				{
					dynInstsOut << read->dynInstPtr->opcode << " ";
				}
				dynInstsOut << "\n";
			}
			dynInstsOut << "\n";
			threadNum++;
		}
		dynInstsOut.close();
	}

	void MemoryChecker::finish()
	{

		bool printStats = false;
		if ( checkPVF )
		{
			auto threadNum = relStructures.regFile.size();
			auto regNum = relStructures.regFile[0].size();
			auto totalPotUtil = threadNum * relStructures.regFile[0].size() * time();
			auto potUtil = relStructures.regFile[0].size() * time();
			if (printStats)
			{
				//print stats
				//utilization/(registers*totalInstructions executed)
				std::cout << "kernel name" << _kernel->name << "\n\n";
				std::cout << "Total cycles " << time()
						<< "\t Total Pot Util " << totalPotUtil
						<< "\t per thread pot util " << potUtil
						<< "\t threads " << threadNum << std::endl
						<< "\t registers per thread " << regNum << std::endl;
			}

			auto recoverUtilization = [&]()
			{
				for(auto& thread : relStructures.regFile )
				{
					for(auto& reg : thread)
					{
						auto& it = reg.trace.back();
						//should be iterating through history and track
						//lastREead and lastWritten as well as read's paMask
						//AND check if ace
						if(reg.trace.size() == 0 || it.first != reg.lastWritten)
						{
							reg.trace.push_back({reg.lastWritten, reg.lastRead});
							reg.tracePC.push_back({reg.lwPC, reg.lrPC});
						}
					}
				}
			};
			auto totalReadWrite = [&](size_t &totalReads, size_t &totalWrites)
			{
				for(auto& thread : relStructures.regFile )
					for(auto& reg : thread )
					{
						totalReads += reg.readCount;
						totalWrites += reg.writeCount;
					}
			};

			auto markACE = [&](int &totalCount)
			{
				int threadCount = 0;
				for( auto & thread: duChain )
				{
					reportE(DUCHAIN, "thread: " << threadCount++
							<< "  root registers: " << thread.ace.size() << "\n");
					auto reg = 0;
					for( auto & dInst: thread.ace )
					{
						reportE(DUCHAIN, "marking root reg: " << reg++ << "\n");
						uint64_t mask = -1; //all ace
						thread.mark(dInst, mask);	//mark all dInsts connected to this dInst as ace
					}
				}
			};
			auto countACE = [&](int &totalCount, int &aceCount)
			{
				for( auto & thread: duChain )
				{
					for(auto & dInst: thread.chain)
					{
						totalCount++;
						if(dInst->ace == true)
							aceCount++;
					}
				}
			};



			///////////////////////////////////////////////////////////////////////////////
			//start of body of MemoryChecker::finish() if(checkPVF)
			//////////////////////////////////////////////////////////////////////////////////
			/* recover potential utilization not captured at end of execution */
			//for(auto& cta : relStructures)
				recoverUtilization();

			/* get overall stats */
			size_t totalReads = 0;
			size_t totalWrites = 0;
			//for(auto& cta : relStructures)
				totalReadWrite(totalReads, totalWrites);

			size_t numBlocks = _dim.x * _dim.y * _dim.z;
			float avgRead = totalReads /
					(float) (relStructures.regFile.size()*relStructures.regFile[0].size());
			float avgWrite = totalWrites /
					(float) (relStructures.regFile.size()*relStructures.regFile[0].size());

#if ACE	
			//traverse backwards in duChain.ace and mark all ACE dInsts
			auto totalCount = 0, aceCount = 0;
			markACE(totalCount);
#endif

			printLiveRangeDuration(1); //FIXME uncomment this line to print liveRangePC, input to RegisterCheckPass
			pvfRegFileHistogram();

			//calculate PVF (all live ranges over life-time of all registers in all threads of CTA)
			pvfRegFile();

			if (printStats)
			{
				checkMismatchedLinks();

				std::cout << "#blocks: " << numBlocks << "\n";
				std::cout << "average reads: " << avgRead
						<< "\naverage writes: " << avgWrite << "\n";

				//count # of ace/total instructions
				countACE(totalCount, aceCount);

				std::cout << "ace/total: " << aceCount << "/" << totalCount << "\t"
						<<  aceCount/((float)totalCount) << "\n"
						<< "Kernel duration: " << time() << "\n";
			}
		}
	}

	void MemoryChecker::DefUseChain::count(DynInst * dInst)
	{
		if ( dInst == nullptr )
			return;
#if 0
		for(auto & w : dInst->write)
		{
			if (!w.dynInstPtr->write.empty() )
			{
				//follow registerActionTrace and find last ACE read before next write/end
				auto writeTime = w.relEvent->time;
				auto &rat = relStructures.regFile[thread][w.reg].relEventList; //FIXME need to pass thread variable
				for(auto raIt = w.relEvent+1; raIt != rat.end(); ++raIt)
				{
					if(raIt->read == false)
						break;
					if(raIt->ace && raIt->read == true)
						lastAceRead = raIt->time;
				}
				valueInterval = lastAceRead - writeTime;//where to store valueInterval?? FIXME
			}

			mark(w.dynInstPtr);
		}

		return;
#endif
	}
        
	int MemoryChecker::DefUseChain::check(DynInst * dInst, std::set<DynInst*> &chain)
	{
		int nomatch = 0;
		if ( dInst == nullptr )
			return 0;
	
		if (chain.find(dInst) == chain.end())
		{
			++nomatch;
			//std::cout << "can't find ace dInst &" << ptr << "\tt" << dInst->time
			//	<< "\tPC" << dInst->PC << "\t:\t" << dInst->opcode.c_str() << std::endl;
		}

		for(auto & r : dInst->read)
		{
			nomatch += check(r->dynInstPtr, chain);
		}
		return nomatch;
	}

	void MemoryChecker::DefUseChain::print(DynInst * dInst)
	{
		if ( dInst == nullptr )
			return;

		for(auto & r : dInst->read)
		{
			std::cout << "r" << r->reg;
			if ( r->dynInstPtr->read.empty() )
				std::cout << " | ";
			else
				std::cout << " <- ";
			print(r->dynInstPtr);
		}
		return;
	}

	//lastMask used to determine TDD
	void MemoryChecker::DefUseChain::mark(DynInst * dInst, uint64_t lastMask)
	{
		if ( dInst == nullptr )
			return;

		dInst->ace = true;

		reportE(DUCHAIN, "t" << dInst->time << "\tPC" << dInst->PC << "\t:\t" << dInst->opcode.c_str() << "\t" );

		//skip if has no read operands
		if (dInst->read.size() == 0)
			return;

		int count = 0;
		for(auto & r : dInst->read)
		{
			reportE(DUCHAIN, "#" << count++ << " r" << r->reg );
			
			//continue if it's mask is 0
			//or if current mask intercepted with last mask is zero
			if ( //redundant 0 == r->relEvent->paMask
					//TDD may be instruction dependent
					//my current reasoning for why it's not is as follows:
					//comparison insts produce no results, so doesn't matter
					//this works for AND
					//for other arithmetic, lower bits are always ACE...
					//FIXME need to reconsider
					0)// (uint64_t)0 == (lastMask & r->relEvent->paMask) )
			{
				std::cout << "logically masked~! -- "
						<< lastMask << " & " << r->relEvent->paMask << " = "
						<< (lastMask & r->relEvent->paMask) << "\n";
				std::cout << dInst->opcode << std::endl;
				//even if mask is 0, it may still be ACE due to the way masks are calculated
				//continue;
			}

            r->relEvent->ace = true;

            assert(r->dynInstPtr != nullptr && "no instruction found in this read event");

			if ( true == r->dynInstPtr->ace )
			{
				reportE(DUCHAIN, "this register already ace!");
					continue;
			}


			mark(r->dynInstPtr, lastMask);
		}

		return;
	}
}

#endif


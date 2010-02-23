/*! \file LLVMExecutableKernel.cpp
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMExecutableKernel class
*/

#ifndef LLVM_EXECUTABLE_KERNEL_CPP_INCLUDED
#define LLVM_EXECUTABLE_KERNEL_CPP_INCLUDED

#include <ocelot/executive/interface/LLVMExecutableKernel.h>
#include <ocelot/executive/interface/TextureOperations.h>
#include <ocelot/executive/interface/Executive.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/interface/Casts.h>
#include <ocelot/translator/interface/PTXToLLVMTranslator.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/RemoveBarrierPass.h>
#include <ocelot/analysis/interface/ConvertPredicationToSelectPass.h>
#include <fstream>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1
#define REPORT_ALL_PTX_SOURCE 0
#define REPORT_ORIGINAL_LLVM_SOURCE 0
#define REPORT_OPTIMIZED_LLVM_SOURCE 0
#define REPORT_INSIDE_TRANSLATED_CODE 0
#define REPORT_CTA_INSIDE_TRANSLATED_CODE 0
#define REPORT_ATOMIC_OPERATIONS 0
#define PRINT_OPTIMIZED_CFG 0
#define DEBUG_NTH_THREAD_ONLY 1
#define NTH_THREAD 1
#define DEBUG_PTX_INSTRUCTION_TRACE 1
#define DEBUG_PTX_BASIC_BLOCK_TRACE 1
#define DEBUG_LLVM 0

#include <configure.h>

#ifdef HAVE_LLVM
#include <llvm/LLVMContext.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/Parser.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/JIT.h> 
#include <llvm/ExecutionEngine/GenericValue.h> 
#include <llvm/Module.h>
#include <llvm/PassManager.h>
#if( DEBUG_LLVM == 1 )
#include <llvm/Support/Debug.h>
#endif
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Target/TargetData.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/Transforms/Scalar.h>
#endif

#include <unordered_set>
#include <cmath>

#ifdef isnan
#define _isnan(x) isnan(x)
#else
#define _isnan(x) std::isnan(x)
#endif
#ifdef isinf
#define _isinf(x) isinf(x)
#else
#define _isinf(x) std::isinf(x)
#endif

template < typename T >
static void __report( executive::LLVMContext* context, 
	T value, const bool read )
{
	#if(DEBUG_NTH_THREAD_ONLY == 1)
	if( context->tid.x == NTH_THREAD )
	{
	#endif		
		std::cout << "Thread (" << context->tid.x << ", " << context->tid.y 
			<< ", " << context->tid.z << ") :   ";
		if( read )
		{
			std::cout << "read ";
		}
		else
		{
			std::cout << "write ";
		}
		std::cout << value << std::endl;
	#if(DEBUG_NTH_THREAD_ONLY == 1)
	}
	#endif
}

extern "C"
{
	void setRoundingMode( unsigned int mode )
	{
		assertM( mode == 0, "No support for setting exotic rounding modes." );
	}

	float __ocelot_ex2Ftz( float f )
	{
		float value = exp( f * 0.693147f );
		if( _isnan( value ) || _isinf( value ) )
		{
			value = 0;
		}
		return value;
	}
	
	float __ocelot_ex2( float value )
	{
		return exp( value * 0.693147f );
	}

	float __ocelot_rsqrtFtz( float f )
	{
		float value = 1.0 / sqrt( f );
		if( _isnan( value ) || _isinf( value ) )
		{
			value = 0;
		}
		return value;
	}

	float __ocelot_rsqrt( float value )
	{
		return 1.0 / sqrt( value );
	}
	
	double __ocelot_sqrt( double f )
	{
		return sqrt( f );
	}
	
	float __ocelot_sqrtFtz( float f )
	{
		float value = sqrt( f );
		if( _isnan( value ) || _isinf( value ) )
		{
			value = 0;
		}
		return value;
	}
	
	float __ocelot_sqrtf( float f )
	{
		return sqrt( f );
	}
	
	float __ocelot_log2Ftz( float f )
	{
		float value = log2( f );
		if( _isnan( value ) || _isinf( value ) )
		{
			value = 0;
		}
		return value;
	}

	float __ocelot_log2f( float f )
	{
		return log2( f );
	}

	float __ocelot_sinFtz( float f )
	{
		float value = sin( f );
		if( _isnan( value ) || _isinf( value ) )
		{
			value = 0;
		}
		return value;
	}

	float __ocelot_sinf( float f )
	{
		return sin( f );
	}

	float __ocelot_cosFtz( float f )
	{
		float value = cos( f );
		if( _isnan( value ) || _isinf( value ) )
		{
			value = 0;
		}
		return value;
	}

	float __ocelot_cosf( float f )
	{
		return cos( f );
	}

	bool __ocelot_vote( bool a, ir::PTXInstruction::VoteMode mode, bool invert )
	{
		a = invert ? !a : a;
		
		switch( mode )
		{
			case ir::PTXInstruction::All:
			case ir::PTXInstruction::Any:
			{
				return a;
				break;
			}
			case ir::PTXInstruction::Uni:
			default: break;
		}
		return true;
	}

	ir::PTXF32 __ocelot_atom_f32( executive::LLVMContext* context, 
		ir::PTXInstruction::AddressSpace space, 
		ir::PTXInstruction::AtomicOperation op, ir::PTXU64 address, 
		ir::PTXF32 b )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		ir::PTXF32 d = 0;
		ir::PTXF32 result = 0;
		
		if( space == ir::PTXInstruction::Shared )
		{
			address += ( ir::PTXU64 ) context->shared;
		}
		else
		{
			state->cache->lock();
		}
		
		d = *((ir::PTXF32*) address);

		switch( op )
		{
			case ir::PTXInstruction::AtomicAdd:
			{
				result = d + b;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicAdd: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicMin:
			{
				result = std::min( d, b );
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicMin: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicMax:
			{
				result = std::max( d, b );
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicMin: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			default: assertM( false, "Atomic " 
				<< ir::PTXInstruction::toString( op ) 
				<< " not supported for f32." );
		}

		*((ir::PTXF32*) address) = result;

		if( space != ir::PTXInstruction::Shared )
		{
			state->cache->unlock();
		}
		
		return d;
	}

	ir::PTXB32 __ocelot_atom_b32( executive::LLVMContext* context, 
		ir::PTXInstruction::AddressSpace space, 
		ir::PTXInstruction::AtomicOperation op, 
		ir::PTXU64 address, ir::PTXB32 b )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		ir::PTXB32 d = 0;
		ir::PTXB32 result = 0;

		if( space == ir::PTXInstruction::Shared )
		{
			address += ( ir::PTXU64 ) context->shared;
		}
		else
		{
			state->cache->lock();
		}

		d = *((ir::PTXB32*) address);
		
		switch( op )
		{
			case ir::PTXInstruction::AtomicAnd:
			{
				result = d & b;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicAnd: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicOr:
			{
				result = d | b;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicOr: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicXor:
			{
				result = d ^ b;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicXor: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicAdd:
			{
				result = d + b;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicAdd: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicMin:
			{
				result = std::min( d, b );
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicMin: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicMax:
			{
				result = std::max( d, b );
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicMax: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicDec:
			{
				result = ((d == 0) || (d > b)) ? b : d - 1;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicDec: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicInc:
			{
				result = (d >= b) ? 0 : d + 1;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicInc: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicExch:
			{
				result = b;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicExch: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			default: assertM( false, "Atomic " 
				<< ir::PTXInstruction::toString( op ) 
				<< " not supported for b32." );
		}

		*((ir::PTXB32*) address) = result;
		
		if( space != ir::PTXInstruction::Shared )
		{
			state->cache->unlock();
		}

		return d;
	}

	ir::PTXS32 __ocelot_atom_s32( executive::LLVMContext* context, 
		ir::PTXInstruction::AddressSpace space, 
		ir::PTXInstruction::AtomicOperation op, 
		ir::PTXU64 address, ir::PTXS32 b )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		ir::PTXS32 d = 0;
		ir::PTXS32 result = 0;

		if( space == ir::PTXInstruction::Shared )
		{
			address += ( ir::PTXU64 ) context->shared;
		}
		else
		{
			state->cache->lock();
		}
		
		d = *((ir::PTXS32*) address);

		switch( op )
		{
			case ir::PTXInstruction::AtomicAdd:
			{
				result = d + b;
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicAdd: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicMin:
			{
				result = std::min( d, b );
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicMin: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			case ir::PTXInstruction::AtomicMax:
			{
				result = std::max( d, b );
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicMax: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << result );
				break;
			}
			default: assertM( false, "Atomic " 
				<< ir::PTXInstruction::toString( op ) 
				<< " not supported for s32." );
		}

		*((ir::PTXS32*) address) = result;

		if( space != ir::PTXInstruction::Shared )
		{
			state->cache->unlock();
		}
		
		return d;
	}

	ir::PTXB64 __ocelot_atom_b64( executive::LLVMContext* context, 
		ir::PTXInstruction::AddressSpace space, 
		ir::PTXInstruction::AtomicOperation op, 
		ir::PTXU64 address, ir::PTXB64 b )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		ir::PTXB64 d = 0;
		ir::PTXB64 result = 0;

		if( space == ir::PTXInstruction::Shared )
		{
			address += ( ir::PTXU64 ) context->shared;
		}
		else
		{
			state->cache->lock();
		}
				
		d = *((ir::PTXB64*) address);

		switch( op )
		{
			case ir::PTXInstruction::AtomicAdd:
			{
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicAdd: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << ( d + b ) );
				result = d + b;
				break;
			}
			case ir::PTXInstruction::AtomicExch:
			{
				d = *((ir::PTXB64*) address);
				reportE( REPORT_ATOMIC_OPERATIONS, "AtomicExch: address " 
					<< (void*) address << " from " << d << " by " << b 
					<< " to " << b );
				result = b;
				break;
			}
			default: assertM( false, "Atomic " 
				<< ir::PTXInstruction::toString( op ) 
				<< " not supported for b64." );
		}

		*((ir::PTXB64*) address) = result;

		if( space != ir::PTXInstruction::Shared )
		{
			state->cache->unlock();
		}
		
		return d;
	}

	ir::PTXB32 __ocelot_atomcas_b32( executive::LLVMContext* context, 
		ir::PTXInstruction::AddressSpace space, 
		ir::PTXInstruction::AtomicOperation op, ir::PTXU64 address, 
		ir::PTXB32 b, ir::PTXB32 c )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		ir::PTXB32 d = 0;
		
		if( space == ir::PTXInstruction::Shared )
		{
			address += ( ir::PTXU64 ) context->shared;
		}
		else
		{
			state->cache->lock();
		}
				
		d = *((ir::PTXB32*) address);

		assert( op == ir::PTXInstruction::AtomicCas );

		ir::PTXB32 result = ( d == b ) ? c : d;

		reportE( REPORT_ATOMIC_OPERATIONS, "AtomicCas: address " 
			<< (void*) address << " from " << d << " by " << b 
			<< " to " << result );

		*((ir::PTXB32*) address) = result;

		if( space != ir::PTXInstruction::Shared )
		{
			state->cache->unlock();
		}
		
		return d;
	}

	ir::PTXB64 __ocelot_atomcas_b64( executive::LLVMContext* context, 
		ir::PTXInstruction::AddressSpace space, 
		ir::PTXInstruction::AtomicOperation op, ir::PTXU64 address, 
		ir::PTXB64 b, ir::PTXB64 c )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		ir::PTXB64 d = 0;
		
		if( space == ir::PTXInstruction::Shared )
		{
			address += ( ir::PTXU64 ) context->shared;
		}
		else
		{
			state->cache->lock();
		}
				
		d = *((ir::PTXB64*) address);

		assert( op == ir::PTXInstruction::AtomicCas );

		ir::PTXB64 result = ( d == b ) ? c : d;

		reportE( REPORT_ATOMIC_OPERATIONS, "AtomicCas: address " 
			<< (void*) address << " from " << d << " by " << b 
			<< " to " << ( ( d == b ) ? c : d ) );

		*((ir::PTXB64*) address) = result;

		if( space != ir::PTXInstruction::Shared )
		{
			state->cache->unlock();
		}

		return d;
	}

	unsigned int __ocelot_clock( executive::LLVMContext* context )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		return state->timer.cycles();
	}
	
	void __ocelot_debug_block( executive::LLVMContext* context, 
		ir::ControlFlowGraph::BasicBlock::Id id )
	{
		#if(DEBUG_PTX_BASIC_BLOCK_TRACE == 1)
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		executive::LLVMExecutableKernel::OpaqueState::BlockIdMap::const_iterator
			block = state->blocks.find( id );
		assert( block != state->blocks.end() );
		
		#if(DEBUG_NTH_THREAD_ONLY == 1)
		if( context->tid.x == NTH_THREAD )
		{
		#endif
		
		std::cout << "Thread (" << context->tid.x << ", " << context->tid.y 
			<< ", " << context->tid.z << ") : Basic Block \"" << std::flush;
		std::cout << block->second->label << "\"\n";

		#if(DEBUG_NTH_THREAD_ONLY == 1)
		}
		#endif
		#endif
	}

	void __ocelot_debug_instruction( executive::LLVMContext* context, 
		ir::PTXU64 _instruction )
	{
		void* instruction = (void*) _instruction;
		#if(DEBUG_PTX_INSTRUCTION_TRACE == 1)		

		#if(DEBUG_NTH_THREAD_ONLY == 1)
		if( context->tid.x == NTH_THREAD )
		{
		#endif
		
		std::cout << "Thread (" << context->tid.x << ", " << context->tid.y 
			<< ", " << context->tid.z << ") :  " << std::flush;
		std::cout << static_cast<ir::Instruction*>(instruction)->toString() 
			<< "\n";

		#if(DEBUG_NTH_THREAD_ONLY == 1)
		}
		#endif

		#endif
	}

	void __ocelot_register_write_s8( executive::LLVMContext* context, 
		ir::PTXS8 value )
	{
		__report( context, value, false );
	}

	void __ocelot_register_write_s16( executive::LLVMContext* context, 
		ir::PTXS16 value )
	{
		__report( context, value, false );
	}

	void __ocelot_register_write_s32( executive::LLVMContext* context, 
		ir::PTXS32 value )
	{
		__report( context, value, false );
	}

	void __ocelot_register_write_s64( executive::LLVMContext* context, 
		ir::PTXS64 value )
	{
		__report( context, value, false );
	}

	void __ocelot_register_write_u8( executive::LLVMContext* context, 
		ir::PTXU8 value )
	{
		#if(DEBUG_NTH_THREAD_ONLY == 1)
		if( context->tid.x == NTH_THREAD )
		{
		#endif		
			std::cout << "Thread (" << context->tid.x << ", " << context->tid.y 
				<< ", " << context->tid.z << ") :  ";
			std::cout << " write ";
			std::cout << (unsigned int)value << std::endl;
		#if(DEBUG_NTH_THREAD_ONLY == 1)
		}
		#endif
	}

	void __ocelot_register_write_u16( executive::LLVMContext* context, 
		ir::PTXU16 value )
	{
		__report( context, value, false );
	}

	void __ocelot_register_write_u32( executive::LLVMContext* context, 
		ir::PTXU32 value )
	{
		__report( context, value, false );
	}

	void __ocelot_register_write_u64( executive::LLVMContext* context, 
		ir::PTXU64 value )
	{
		__report( context, value, false );
	}

	void __ocelot_register_write_f32( executive::LLVMContext* context, 
		ir::PTXF32 value )
	{
		__report( context, value, false );
	}

	void __ocelot_register_write_f64( executive::LLVMContext* context, 
		ir::PTXF64 value )
	{
		__report( context, value, false );
	}
	
	void __ocelot_register_read_s8( executive::LLVMContext* context, 
		ir::PTXS8 value )
	{
		__report( context, value, true );
	}

	void __ocelot_register_read_s16( executive::LLVMContext* context, 
		ir::PTXS16 value )
	{
		__report( context, value, true );
	}

	void __ocelot_register_read_s32( executive::LLVMContext* context, 
		ir::PTXS32 value )
	{
		__report( context, value, true );
	}

	void __ocelot_register_read_s64( executive::LLVMContext* context, 
		ir::PTXS64 value )
	{
		__report( context, value, true );
	}

	void __ocelot_register_read_u8( executive::LLVMContext* context, 
		ir::PTXU8 value )
	{
		#if(DEBUG_NTH_THREAD_ONLY == 1)
		if( context->tid.x == NTH_THREAD )
		{
		#endif		
			std::cout << "Thread (" << context->tid.x << ", " << context->tid.y 
				<< ", " << context->tid.z << ") :  ";
			std::cout << " read ";
			std::cout << (unsigned int)value << std::endl;
		#if(DEBUG_NTH_THREAD_ONLY == 1)
		}
		#endif
	}

	void __ocelot_register_read_u16( executive::LLVMContext* context, 
		ir::PTXU16 value )
	{
		__report( context, value, true );
	}

	void __ocelot_register_read_u32( executive::LLVMContext* context, 
		ir::PTXU32 value )
	{
		__report( context, value, true );
	}

	void __ocelot_register_read_u64( executive::LLVMContext* context, 
		ir::PTXU64 value )
	{
		__report( context, value, true );
	}

	void __ocelot_register_read_f32( executive::LLVMContext* context, 
		ir::PTXF32 value )
	{
		__report( context, value, true );
	}

	void __ocelot_register_read_f64( executive::LLVMContext* context, 
		ir::PTXF64 value )
	{
		__report( context, value, true );
	}
	
	void __ocelot_check_global_memory_access( executive::LLVMContext* context,
		ir::PTXU64 _address, unsigned int bytes, unsigned int statement )
	{
		void* address = (void*)_address;
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		if( !state->kernel->context->checkMemoryAccess( 
			state->kernel->context->getSelected(), address, bytes ) )
		{
			unsigned int thread = context->tid.x 
				+ context->ntid.x * context->tid.y 
				+ context->ntid.x * context->ntid.y * context->tid.y;
			unsigned int cta = context->ctaid.x 
				+ context->nctaid.x * context->ctaid.y 
				+ context->nctaid.x * context->nctaid.y * context->ctaid.y;
			
			std::cerr << "While executing kernel '" 
				<< state->kernel->name << "'\n";
			std::cerr << "Error in (cta " << cta << ")(thread " << thread 
				<< "): instruction '" 
				<< state->kernel->instruction( statement ) << "'\n";
			std::cerr << "Global memory address " 
				<< address << " of size " << bytes
				<< " is out of any allocated or mapped range.\n";
			std::cerr << "Memory Map:\n";
			std::cerr << executive::Executive::nearbyAllocationsToString(
				*state->kernel->context, address);
			std::cerr << "\n";
			std::cout << "\tNear: " << state->kernel->location( statement )
				<< "\n\n";
			assertM(false, "Aborting execution.");
		}
		
		bool error = bytes == 0;
		if( !error ) error = (long long unsigned int)address % bytes != 0;
		
		if( error )
		{
			unsigned int thread = context->tid.x 
				+ context->ntid.x * context->tid.y 
				+ context->ntid.x * context->ntid.y * context->tid.y;
			unsigned int cta = context->ctaid.x 
				+ context->nctaid.x * context->ctaid.y 
				+ context->nctaid.x * context->nctaid.y * context->ctaid.y;

			std::cerr << "While executing kernel '" 
				<< state->kernel->name << "'\n";
			std::cerr << "Error in (cta " << cta << ")(thread " << thread 
				<< "): instruction '" 
				<< state->kernel->instruction( statement ) << "'\n";
			std::cerr << "Global memory address " 
				<< address << " of size " << bytes
				<< " is not aligned to the access size.\n";
			std::cerr << "\n";
			std::cout << "\tNear: " << state->kernel->location( statement )
				<< "\n\n";
			assertM(false, "Aborting execution.");
		}
	}
	
	void __ocelot_check_shared_memory_access( executive::LLVMContext* context,
		ir::PTXU64 _address, unsigned int bytes, unsigned int statement )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		char* address = (char*) _address;
		char* end = address + bytes;
		char* allocationEnd = context->shared 
			+ state->kernel->totalSharedMemorySize();
		
		if( end > allocationEnd )
		{
			unsigned int thread = context->tid.x 
				+ context->ntid.x * context->tid.y 
				+ context->ntid.x * context->ntid.y * context->tid.y;
			unsigned int cta = context->ctaid.x 
				+ context->nctaid.x * context->ctaid.y 
				+ context->nctaid.x * context->nctaid.y * context->ctaid.y;
			
			std::cerr << "While executing kernel '" 
				<< state->kernel->name << "'\n";
			std::cerr << "Error in (cta " << cta << ")(thread " << thread 
				<< "): instruction '" 
				<< state->kernel->instruction( statement ) << "'\n";
			std::cerr << "Shared memory address " 
				<< _address << " is " << (end - allocationEnd)
				<< " bytes beyond the shared memory block of " 
				<< state->kernel->totalSharedMemorySize() << " bytes.\n";
			std::cout << "\tNear: " << state->kernel->location( statement )
				<< "\n\n";
			assertM(false, "Aborting execution.");
		}
	}

	void __ocelot_check_constant_memory_access( executive::LLVMContext* context,
		ir::PTXU64 _address, unsigned int bytes, unsigned int statement )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		char* address = (char*) _address;
		char* end = address + bytes;
		char* allocationEnd = context->constant + context->constantSize;
		
		if( end > allocationEnd )
		{
			unsigned int thread = context->tid.x 
				+ context->ntid.x * context->tid.y 
				+ context->ntid.x * context->ntid.y * context->tid.y;
			unsigned int cta = context->ctaid.x 
				+ context->nctaid.x * context->ctaid.y 
				+ context->nctaid.x * context->nctaid.y * context->ctaid.y;
			
			std::cerr << "While executing kernel '" 
				<< state->kernel->name << "'\n";
			std::cerr << "Error in (cta " << cta << ")(thread " << thread 
				<< "): instruction '" 
				<< state->kernel->instruction( statement ) << "'\n";
			std::cerr << "Constant memory address " 
				<< _address << " is " << (end - allocationEnd)
				<< " bytes beyond the constant memory block of " 
				<< context->constantSize << " bytes.\n";
			std::cout << "\tNear: " << state->kernel->location( statement )
				<< "\n\n";
			assertM(false, "Aborting execution.");
		}	
	}

	void __ocelot_check_local_memory_access( executive::LLVMContext* context,
		ir::PTXU64 _address, unsigned int bytes, unsigned int statement )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		char* address = (char*) _address;
		char* end = address + bytes;
		char* allocationEnd = context->local + context->localSize;
		
		if( end > allocationEnd )
		{
			unsigned int thread = context->tid.x 
				+ context->ntid.x * context->tid.y 
				+ context->ntid.x * context->ntid.y * context->tid.y;
			unsigned int cta = context->ctaid.x 
				+ context->nctaid.x * context->ctaid.y 
				+ context->nctaid.x * context->nctaid.y * context->ctaid.y;
			
			std::cerr << "While executing kernel '" 
				<< state->kernel->name << "'\n";
			std::cerr << "Error in (cta " << cta << ")(thread " << thread 
				<< "): instruction '" 
				<< state->kernel->instruction( statement ) << "'\n";
			std::cerr << "Local memory address " 
				<< _address << " is " << (end - allocationEnd)
				<< " bytes beyond the local memory block of " 
				<< context->localSize << " bytes.\n";
			std::cout << "\tNear: " << state->kernel->location( statement )
				<< "\n\n";
			assertM(false, "Aborting execution.");
		}	
	}

	void __ocelot_check_param_memory_access( executive::LLVMContext* context,
		ir::PTXU64 _address, unsigned int bytes, unsigned int statement )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		
		char* address = (char*) _address;
		char* end = address + bytes;
		char* allocationEnd = context->parameter + context->parameterSize;
				
		if( end > allocationEnd )
		{
			unsigned int thread = context->tid.x 
				+ context->ntid.x * context->tid.y 
				+ context->ntid.x * context->ntid.y * context->tid.y;
			unsigned int cta = context->ctaid.x 
				+ context->nctaid.x * context->ctaid.y 
				+ context->nctaid.x * context->nctaid.y * context->ctaid.y;
			
			std::cerr << "While executing kernel '" 
				<< state->kernel->name << "'\n";
			std::cerr << "Error in (cta " << cta << ")(thread " << thread 
				<< "): instruction '" 
				<< state->kernel->instruction( statement ) << "'\n";
			std::cerr << "Parameter memory address " 
				<< address << " is  " << (end - allocationEnd)
				<< " bytes beyond the parameter memory block of " 
				<< context->parameterSize << " bytes.\n";
			std::cout << "\tNear: " << state->kernel->location( statement )
				<< "\n\n";
			assertM(false, "Aborting execution.");
		}	
	}
		
	void __ocelot_tex_3d_fs( float* result, executive::LLVMContext* context, 
		unsigned int index, unsigned int c0, unsigned int c1, unsigned int c2,
		unsigned int c3 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, float >( 
			texture, c0, c1, c2 );
		result[1] = executive::tex::sample< 1, float >( 
			texture, c0, c1, c2 );
		result[2] = executive::tex::sample< 2, float >( 
			texture, c0, c1, c2 );
		result[3] = executive::tex::sample< 3, float >( 
			texture, c0, c1, c2 );			
	}

	void __ocelot_tex_3d_fu( float* result, executive::LLVMContext* context, 
		unsigned int index, unsigned int c0, unsigned int c1, unsigned int c2, 
		unsigned int c3 )
	{
		__ocelot_tex_3d_fs( result, context, index, c0, c1, c2, c3 );
	}

	void __ocelot_tex_3d_ff( float* result, executive::LLVMContext* context, 
		unsigned int index, float c0, float c1, float c2, float c3 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, float >( 
			texture, c0, c1, c2 );
		result[1] = executive::tex::sample< 1, float >( 
			texture, c0, c1, c2 );
		result[2] = executive::tex::sample< 2, float >( 
			texture, c0, c1, c2 );
		result[3] = executive::tex::sample< 3, float >( 
			texture, c0, c1, c2 );	
	}

	void __ocelot_tex_3d_sf( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, float c0, 
		float c1, float c2, float c3 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, int >( 
			texture, c0, c1, c2 );
		result[1] = executive::tex::sample< 1, int >( 
			texture, c0, c1, c2 );
		result[2] = executive::tex::sample< 2, int >( 
			texture, c0, c1, c2 );
		result[3] = executive::tex::sample< 3, int >( 
			texture, c0, c1, c2 );				
	}

	void __ocelot_tex_3d_uf( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, float c0, 
		float c1, float c2, float c3 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, unsigned int >( 
			texture, c0, c1, c2 );
		result[1] = executive::tex::sample< 1, unsigned int >( 
			texture, c0, c1, c2 );
		result[2] = executive::tex::sample< 2, unsigned int >( 
			texture, c0, c1, c2 );
		result[3] = executive::tex::sample< 3, unsigned int >( 
			texture, c0, c1, c2 );				
	}

	void __ocelot_tex_3d_su( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0, 
		unsigned int c1, unsigned int c2, unsigned int c3 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, int >( 
			texture, c0, c1, c2 );
		result[1] = executive::tex::sample< 1, int >( 
			texture, c0, c1, c2 );
		result[2] = executive::tex::sample< 2, int >( 
			texture, c0, c1, c2 );
		result[3] = executive::tex::sample< 3, int >( 
			texture, c0, c1, c2 );				
	}

	void __ocelot_tex_3d_ss( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0, 
		unsigned int c1, unsigned int c2, unsigned int c3 )
	{
		__ocelot_tex_3d_su( result, context, index, c0, c1, c2, c3 );
	}

	void __ocelot_tex_3d_uu( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0, 
		unsigned int c1, unsigned int c2, unsigned int c3 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, unsigned int >( 
			texture, c0, c1, c2 );
		result[1] = executive::tex::sample< 1, unsigned int >( 
			texture, c0, c1, c2 );
		result[2] = executive::tex::sample< 2, unsigned int >( 
			texture, c0, c1, c2 );
		result[3] = executive::tex::sample< 3, unsigned int >( 
			texture, c0, c1, c2 );				
	}

	void __ocelot_tex_3d_us( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0, 
		unsigned int c1, unsigned int c2, unsigned int c3 )
	{
		__ocelot_tex_3d_uu( result, context, index, c0, c1, c2, c3 );
	}

	void __ocelot_tex_2d_fu( float* result, executive::LLVMContext* context, 
		unsigned int index, unsigned int c0, unsigned int c1 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, float >( texture, c0, c1 );
		result[1] = executive::tex::sample< 1, float >( texture, c0, c1 );
		result[2] = executive::tex::sample< 2, float >( texture, c0, c1 );
		result[3] = executive::tex::sample< 3, float >( texture, c0, c1 );		
	}

	void __ocelot_tex_2d_fs( float* result, executive::LLVMContext* context, 
		unsigned int index, unsigned int c0, unsigned int c1 )
	{
		__ocelot_tex_2d_fu( result, context, index, c0, c1 );
	}

	void __ocelot_tex_2d_ff( float* result, executive::LLVMContext* context, 
		unsigned int index, float c0, float c1 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, float >( texture, c0, c1 );
		result[1] = executive::tex::sample< 1, float >( texture, c0, c1 );
		result[2] = executive::tex::sample< 2, float >( texture, c0, c1 );
		result[3] = executive::tex::sample< 3, float >( texture, c0, c1 );	
	}

	void __ocelot_tex_2d_sf( unsigned int* result, 
		executive::LLVMContext* context, 
		unsigned int index, float c0, float c1 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, int >( texture, c0, c1 );
		result[1] = executive::tex::sample< 1, int >( texture, c0, c1 );
		result[2] = executive::tex::sample< 2, int >( texture, c0, c1 );
		result[3] = executive::tex::sample< 3, int >( texture, c0, c1 );
	}

	void __ocelot_tex_2d_uf( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, 
		float c0, float c1 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, 
			unsigned int >( texture, c0, c1 );
		result[1] = executive::tex::sample< 1, 
			unsigned int >( texture, c0, c1 );
		result[2] = executive::tex::sample< 2, 
			unsigned int >( texture, c0, c1 );
		result[3] = executive::tex::sample< 3, 
			unsigned int >( texture, c0, c1 );						
	}

	void __ocelot_tex_2d_us( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0, 
		unsigned int c1 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, 
			unsigned int >( texture, c0, c1 );
		result[1] = executive::tex::sample< 1, 
			unsigned int >( texture, c0, c1 );
		result[2] = executive::tex::sample< 2, 
			unsigned int >( texture, c0, c1 );
		result[3] = executive::tex::sample< 3, 
			unsigned int >( texture, c0, c1 );						
	}

	void __ocelot_tex_2d_uu( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, 
		unsigned int c0, unsigned int c1 )
	{
		__ocelot_tex_2d_us( result, context, index, c0, c1 );
	}

	void __ocelot_tex_2d_su( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, 
		unsigned int c0, unsigned int c1 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, int >( texture, c0, c1 );
		result[1] = executive::tex::sample< 1, int >( texture, c0, c1 );
		result[2] = executive::tex::sample< 2, int >( texture, c0, c1 );
		result[3] = executive::tex::sample< 3, int >( texture, c0, c1 );	
	}

	void __ocelot_tex_2d_ss( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, 
		unsigned int c0, unsigned int c1 )
	{
		__ocelot_tex_2d_su( result, context, index, c0, c1 );
	}

	void __ocelot_tex_1d_fs( float* result, executive::LLVMContext* context, 
		int index, int c0 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, float >( texture, c0 );
		result[1] = executive::tex::sample< 1, float >( texture, c0 );
		result[2] = executive::tex::sample< 2, float >( texture, c0 );
		result[3] = executive::tex::sample< 3, float >( texture, c0 );	
	}

	void __ocelot_tex_1d_fu( float* result, executive::LLVMContext* context, 
		unsigned int index, unsigned int c0 )
	{
		__ocelot_tex_1d_fs( result, context, index, c0 );
	}

	void __ocelot_tex_1d_ff( float* result, executive::LLVMContext* context, 
		unsigned int index, float c0 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, float >( texture, c0 );
		result[1] = executive::tex::sample< 1, float >( texture, c0 );
		result[2] = executive::tex::sample< 2, float >( texture, c0 );
		result[3] = executive::tex::sample< 3, float >( texture, c0 );		
	}

	void __ocelot_tex_1d_sf( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, float c0 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, int >( texture, c0 );
		result[1] = executive::tex::sample< 1, int >( texture, c0 );
		result[2] = executive::tex::sample< 2, int >( texture, c0 );
		result[3] = executive::tex::sample< 3, int >( texture, c0 );	
	}

	void __ocelot_tex_1d_uf( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, float c0 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, unsigned int >( texture, c0 );
		result[1] = executive::tex::sample< 1, unsigned int >( texture, c0 );
		result[2] = executive::tex::sample< 2, unsigned int >( texture, c0 );
		result[3] = executive::tex::sample< 3, unsigned int >( texture, c0 );	
	}

	void __ocelot_tex_1d_ss( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, int >( texture, c0 );
		result[1] = executive::tex::sample< 1, int >( texture, c0 );
		result[2] = executive::tex::sample< 2, int >( texture, c0 );
		result[3] = executive::tex::sample< 3, int >( texture, c0 );	
	}

	void __ocelot_tex_1d_su( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0 )
	{
		__ocelot_tex_1d_ss( result, context, index, c0 );
	}

	void __ocelot_tex_1d_us( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0 )
	{
		executive::LLVMExecutableKernel::OpaqueState* state = 
			(executive::LLVMExecutableKernel::OpaqueState*) context->other;
		const ir::Texture& texture = *state->textures[ index ];
		
		result[0] = executive::tex::sample< 0, unsigned int >( texture, c0 );
		result[1] = executive::tex::sample< 1, unsigned int >( texture, c0 );
		result[2] = executive::tex::sample< 2, unsigned int >( texture, c0 );
		result[3] = executive::tex::sample< 3, unsigned int >( texture, c0 );
		
	}

	void __ocelot_tex_1d_uu( unsigned int* result, 
		executive::LLVMContext* context, unsigned int index, unsigned int c0 )
	{
		__ocelot_tex_1d_us( result, context, index, c0 );
	}

}

namespace executive
{

	LLVMExecutableKernel::LLVMState LLVMExecutableKernel::_state;

	LLVMExecutableKernel::ExecutionManager LLVMExecutableKernel::_manager;

	LLVMExecutableKernel::LLVMState::LLVMState()		
	{
		jit = 0;
	}
	
	void LLVMExecutableKernel::LLVMState::initialize()
	{
		#ifdef HAVE_LLVM
		if( jit == 0 )
		{
			report( "Bringing the LLVM JIT-Compiler online." );

			module = new llvm::Module( "Ocelot-LLVM-JIT-Blank Module", 
				llvm::getGlobalContext() );
			assertM( module != 0, "Creating global module failed." );
		
			llvm::InitializeNativeTarget();

			#if( DEBUG_LLVM == 1 )
			llvm::DebugFlag = true;
			#endif
			
			jit = llvm::EngineBuilder( module ).create();
			jit->DisableLazyCompilation( true );
		
			assertM( jit != 0, "Creating the JIT failed.");
			report( " The JIT is alive." );
		}
		#endif
	}
	
	LLVMExecutableKernel::LLVMState::~LLVMState()
	{
		#ifdef HAVE_LLVM
		reportE( jit != 0, "Deleting the LLVM JIT-Compiler." );
		delete jit;
		#endif
	}

	LLVMExecutableKernel::AtomicOperationCache::AtomicOperationCache()
	{
		pthread_mutex_init( &_mutex, 0 );
	}
	
	LLVMExecutableKernel::AtomicOperationCache::~AtomicOperationCache()
	{
		pthread_mutex_destroy( &_mutex );
	}

	void LLVMExecutableKernel::AtomicOperationCache::lock()
	{
		pthread_mutex_lock( &_mutex );
	}

	void LLVMExecutableKernel::AtomicOperationCache::unlock()
	{
		pthread_mutex_unlock( &_mutex );
	}

	LLVMExecutableKernel::Worker::Message::Message( Type t, 
		Function f, LLVMContext* c, unsigned int xb, unsigned int xe, 
		unsigned int s, unsigned int rp ) : type( t ), function( f ), context( c ), 
		begin( xb ), end( xe ), step( s ), resumePointOffset( rp )
	{
	
	}

	void LLVMExecutableKernel::Worker::execute()
	{
		Message* message;
		
		threadReceive( message );
		
		while( message->type != Message::Kill )
		{
			if( message->type == Message::LaunchKernelWithBarriers )
			{
				launchKernelWithBarriers( message->function, message->context, 
					message->begin, message->end, message->step,
					message->resumePointOffset );
			}
			else
			{
				assertM( message->type == Message::LaunchKernelWithoutBarriers,
					"Invalid message type received by worker thread." );
				launchKernelWithoutBarriers( message->function, 
					message->context, message->begin, message->end,
					message->step );				
			}
			message->type = Message::Acknowledgement;
			threadSend( message );
			threadReceive( message );
		}
		message->type = Message::Acknowledgement;
		threadSend( message );
	}

	void LLVMExecutableKernel::Worker::launchKernelWithBarriers( 
		Function f, LLVMContext* c, unsigned int begin, unsigned int end, 
		unsigned int step, unsigned int rp )
	{
		for( unsigned int i = begin; i < end; i += step )
		{
			c->ctaid.x = i % c->nctaid.x;
			c->ctaid.y = i / c->nctaid.x;
			reportE( REPORT_CTA_INSIDE_TRANSLATED_CODE,
				"  Launching CTA ( x " << (unsigned int) c->ctaid.x << ", y " 
				<< (unsigned int) c->ctaid.y << " )" );
			launchCtaWithBarriers( f, c, rp );
		}
	}

	void LLVMExecutableKernel::Worker::launchKernelWithoutBarriers( 
		Function f, LLVMContext* c, unsigned int begin, 
		unsigned int end, unsigned int step )
	{
		for( unsigned int i = begin; i < end; i += step )
		{
			c->ctaid.x = i % c->nctaid.x;
			c->ctaid.y = i / c->nctaid.x;
			reportE( REPORT_CTA_INSIDE_TRANSLATED_CODE,
				"  Launching CTA ( x " << (unsigned int) c->ctaid.x << ", y " 
				<< (unsigned int) c->ctaid.y << " )" );
			launchCtaWithoutBarriers( f, c );
		}
	}

	void LLVMExecutableKernel::Worker::launchCtaWithBarriers( 
		Function function, LLVMContext* c, unsigned int resumePointOffset )
	{
		typedef std::vector< llvm::GenericValue > ArgumentVector;
		ArgumentVector arguments( 1, llvm::GenericValue( c ) );

		char* localBase = c->local;
		bool done = false;
		unsigned int threads = c->ntid.z * c->ntid.y * c->ntid.x;
		
		for( unsigned int i = 0; i < threads; ++i )
		{
			(*(unsigned int*)(localBase
				+ i * c->localSize + resumePointOffset)) = 0;
		}
		
		while( !done )
		{
			done = true;
			for( int z = 0; z < c->ntid.z; ++z )
			{
				c->tid.z = z;
				for( int y = 0; y < c->ntid.y; ++y )
				{
					c->tid.y = y;
					for( int x = 0; x < c->ntid.x; ++x )
					{
						c->tid.x = x;
						c->local = localBase + c->localSize * threadId( *c );
						reportE( REPORT_INSIDE_TRANSLATED_CODE,
							"  Launching thread ( x " << x << ", y " << y 
							<< ", z " << z << " )" << " at resume point " 
							<< *((unsigned int*)(c->local 
							+ resumePointOffset)) );
						unsigned int resume = function( c );
						done &= resume == 0;
						*((unsigned int*)(c->local 
							+ resumePointOffset)) = resume;
						reportE( REPORT_INSIDE_TRANSLATED_CODE, 
							"   Thread blocked at " << resume );
					}
				}
			}
		}

		c->local = localBase;
	}

	void LLVMExecutableKernel::Worker::launchCtaWithoutBarriers( 
		Function function, LLVMContext* c )
	{
		char* localBase = c->local;
		bool done = true;
		for( int z = 0; z < c->ntid.z; ++z )
		{
			c->tid.z = z;
			for( int y = 0; y < c->ntid.y; ++y )
			{
				c->tid.y = y;
				for( int x = 0; x < c->ntid.x; ++x )
				{
					c->tid.x = x;
					reportE( REPORT_INSIDE_TRANSLATED_CODE, 
						"  Launching thread ( x " << x << ", y " << y 
						<< ", z " << z << " )" );
					c->local = localBase + c->localSize * threadId( *c );
					unsigned int resume = function( c );
					done &= resume == 0;
					reportE( REPORT_INSIDE_TRANSLATED_CODE, 
						"   Thread blocked at " << resume );
				}
			}
		}	

		c->local = localBase;		
		assertM( done, 
			"Not all threads finished in kernel with no context switches" );
	}
	
	LLVMExecutableKernel::ExecutionManager::ExecutionManager() 
		: _maxThreadsPerCta( 512 )
	{
	
	}

	LLVMExecutableKernel::ExecutionManager::~ExecutionManager()
	{
		report( "Tearing down " << threads() << " LLVM worker threads." );
		clear();
	}

	void LLVMExecutableKernel::ExecutionManager::launch( Function f, 
		LLVMContext* c, bool barriers, unsigned int resumePointOffset,
		unsigned int externalSharedMemory )
	{
		if( threads() == 0 ) setThreadCount( 1 );
		for( ContextVector::iterator context = _contexts.begin(); 
			context != _contexts.end(); ++context )
		{
			if( c->localSize > context->localSize )
			{
				delete[] context->local;
				context->localSize = c->localSize;
				context->local 
					= new char[ context->localSize * _maxThreadsPerCta ];
			}

			if( c->sharedSize + externalSharedMemory > context->sharedSize )
			{
				delete[] context->shared;
				context->sharedSize = c->sharedSize + externalSharedMemory;
				context->shared = new char[ context->sharedSize ];
			}
			
			context->nctaid = c->nctaid;
			context->ntid = c->ntid;

			context->constant = c->constant;
			context->parameter = c->parameter;
			context->constantSize = c->constantSize;
			context->parameterSize = c->parameterSize;

			context->other = c->other;
		}
		
		unsigned int step = _workers.size();
		unsigned int begin = 0;
		
		MessageVector::iterator message = _messages.begin();
		for( WorkerVector::iterator worker = _workers.begin(); 
			worker != _workers.end(); ++worker, ++message, ++begin )
		{
			if( barriers )
			{
				message->type = Worker::Message::LaunchKernelWithBarriers;
				message->resumePointOffset = resumePointOffset;
			}
			else
			{
				message->type = Worker::Message::LaunchKernelWithoutBarriers;
			}
			
			message->function = f;
			message->begin = begin;
			message->end = (unsigned int) c->nctaid.x * c->nctaid.y;
			message->step = step;
			
			worker->send( &(*message) );
		}

		for( WorkerVector::iterator worker = _workers.begin(); 
			worker != _workers.end(); ++worker )
		{
			Worker::Message* message;
			worker->receive( message );
			assert( message->type == Worker::Message::Acknowledgement );
		}
		
	}
	
	void LLVMExecutableKernel::ExecutionManager::setThreadCount( 
		unsigned int t )
	{
		if( t == threads() ) return;
		report( "Booting up " << t << " LLVM worker threads." );
		clear();

		_workers.resize( t );
		_messages.resize( t );
		_contexts.resize( t );

		for( WorkerVector::iterator worker = _workers.begin(); 
			worker != _workers.end(); ++worker )
		{
			worker->start();
		}
		
		MessageVector::iterator message = _messages.begin();
		for( ContextVector::iterator context = _contexts.begin(); 
			context != _contexts.end(); ++context, ++message )
		{
			context->localSize = 0;
			context->sharedSize = 0;
			context->local = 0;
			context->shared = 0;
			message->context = &(*context);
		}
	}

	void LLVMExecutableKernel::ExecutionManager::setMaxThreadsPerCta( 
		unsigned int t )
	{
		if( t > _maxThreadsPerCta )
		{
			for( ContextVector::iterator context = _contexts.begin(); 
				context != _contexts.end(); ++context )
			{
				delete context->local;
				context->local = new char[ context->localSize * t ];
			}
		}
		_maxThreadsPerCta = t;
	}
	
	void LLVMExecutableKernel::ExecutionManager::clear()
	{
		MessageVector::iterator message = _messages.begin();
		for( WorkerVector::iterator worker = _workers.begin(); 
			worker != _workers.end(); ++worker, ++message )
		{
			message->type = Worker::Message::Kill;
			worker->send( &(*message) );
			Worker::Message* ack;
			worker->receive( ack );
			assert( ack->type == Worker::Message::Acknowledgement );
			worker->join();
		}
		
		_workers.clear();
		_messages.clear();

		for( ContextVector::iterator context = _contexts.begin(); 
			context != _contexts.end(); ++context )
		{
			delete[] context->local;
			delete[] context->shared;
		}
		_contexts.clear();
	}

	unsigned int LLVMExecutableKernel::ExecutionManager::threads() const
	{
		return _workers.size();
	}
	
	LLVMExecutableKernel::OpaqueState::OpaqueState()
	{
		timer.start();
	}
	
	unsigned int LLVMExecutableKernel::_pad( size_t& size, 
		unsigned int alignment )
	{
		unsigned int padding = alignment - ( size % alignment );
		padding = ( alignment == padding ) ? 0 : padding;
		size += padding;
		return padding;
	}
	
	std::string LLVMExecutableKernel::threadIdString( const LLVMContext& c )
	{
		std::stringstream stream;
		
		unsigned int id = threadId( c );
		stream << id;
		return stream.str();
	}

	unsigned int LLVMExecutableKernel::threadId( const LLVMContext& c )
	{
		return c.ntid.x * c.ntid.y * c.tid.z + c.ntid.x * c.tid.y + c.tid.x;
	}

	void LLVMExecutableKernel::_optimizePtx()
	{
		report( " Running PTX optimizer" );

		report( "  Building dataflow graph." );
		_ptx->dfg();

		analysis::ConvertPredicationToSelectPass pass1;
		report( "  Running convert predicate to conditional select" );
		
		pass1.initialize( *module );
		pass1.runOnKernel( *_ptx );
		pass1.finalize();
		
		report( "  Running remove barrier pass." );
		
		reportE( REPORT_ALL_PTX_SOURCE, "   Code before pass:\n" << *_ptx );

		analysis::RemoveBarrierPass pass2;
		
		pass2.initialize( *module );
		pass2.runOnKernel( *_ptx );
		pass2.finalize();
		
		_barrierSupport = pass2.barriers();
		_resumePoint = pass2.resume();

		reportE( REPORT_ALL_PTX_SOURCE, "   Code after pass:\n" << *_ptx );
	}

	void LLVMExecutableKernel::_translateKernel()
	{
		#ifdef HAVE_LLVM
		if( _module == 0 )
		{
			report( "Translating PTX kernel \"" << name << "\" to LLVM" );

			#if (PRINT_OPTIMIZED_CFG > 0) && (REPORT_BASE > 0)
			std::ofstream file((name + "_cfg_original.dot").c_str());
			_ptx->cfg()->write(file, _ptx->instructions);
			file.close();
			#endif
			
			_optimizePtx();
			_buildDebuggingInformation();
			_allocateMemory();

			translator::PTXToLLVMTranslator translator( _optimizationLevel );

			#if (PRINT_OPTIMIZED_CFG > 0) && (REPORT_BASE > 0)
			file.open((name + "_cfg_optimized.dot").c_str());
			_ptx->cfg()->write(file, _ptx->instructions);
			file.close();
			#endif
							
			report( " Running translator" );
			ir::LLVMKernel* llvmKernel = static_cast< 
				ir::LLVMKernel* >( translator.translate( _ptx ) );

			report( " Assembling llvm module" );
			llvmKernel->assemble();

			report( " Parsing llvm assembly." );
			llvm::SMDiagnostic error;

			if (overrideLLVMKernel) {
				_module = llvm::ParseAssemblyFile(overrideLLVMKernelPath, error,
					llvm::getGlobalContext());
			}
			else {
				_module = new llvm::Module( name, llvm::getGlobalContext() );
				_module = llvm::ParseAssemblyString( llvmKernel->code().c_str(), 
					_module, error, llvm::getGlobalContext() );
			}

			if( _module == 0 )
			{
				report( "  Parsing kernel failed, dumping code:\n" 
					<< llvmKernel->numberedCode() );
				std::string m;
				llvm::raw_string_ostream message( m );
				message << "LLVM Parser failed: ";
				error.Print( name.c_str(), message );
				
				throw hydrazine::Exception( message.str() );
			}

			#if ( REPORT_ORIGINAL_LLVM_SOURCE > 0 ) && ( REPORT_BASE > 0 )
			std::string m;
			llvm::raw_string_ostream code( m );
			code << *_module;
			report( " The initial code is:\n" << m );
			#endif
						
			report( " Checking module for errors." );
			std::string verifyError;
			if( llvm::verifyModule( *_module, 
				llvm::ReturnStatusAction, &verifyError ) )
			{
				report( "  Checking kernel failed, dumping code:\n" 
					<< llvmKernel->numberedCode() );
				delete llvmKernel;

				throw hydrazine::Exception( "LLVM Verifier failed for kernel: " 
					+ name + " : \"" + verifyError + "\"" );
			}

			delete llvmKernel;
						
			report( " Successfully created LLVM Module from translated PTX." );
			
			_optimize();
			
		}
		#else
		assertM( false, "LLVM support not compiled into Ocelot." );
		#endif
	}

	void LLVMExecutableKernel::_optimizeLLVMFunction( 
		llvm::Module* module, unsigned int level, bool space )
	{
		#ifdef HAVE_LLVM
		llvm::PassManager manager;

        manager.add( new llvm::TargetData( *_state.jit->getTargetData() ) );
	
		if( level < 2 )
		{
		    manager.add( llvm::createInstructionCombiningPass() );
		    manager.add( llvm::createReassociatePass() );
		    manager.add( llvm::createGVNPass() );
		    manager.add( llvm::createCFGSimplificationPass() );			
		}
		else
		{
			manager.add(llvm::createSimplifyLibCallsPass());    // Library Call Optimizations
			manager.add(llvm::createInstructionCombiningPass());  // Cleanup for scalarrepl.
			manager.add(llvm::createJumpThreadingPass());         // Thread jumps.
			manager.add(llvm::createCFGSimplificationPass());     // Merge & remove BBs
			manager.add(llvm::createScalarReplAggregatesPass());  // Break up aggregate allocas
			manager.add(llvm::createInstructionCombiningPass());  // Combine silly seq's
			manager.add(llvm::createTailCallEliminationPass());   // Eliminate tail calls
			manager.add(llvm::createCFGSimplificationPass());     // Merge & remove BBs
			manager.add(llvm::createReassociatePass());           // Reassociate expressions
			manager.add(llvm::createLoopRotatePass());            // Rotate Loop
			manager.add(llvm::createLICMPass());                  // Hoist loop invariants
			manager.add(llvm::createLoopUnswitchPass(space || level < 3));
			manager.add(llvm::createInstructionCombiningPass());  
			manager.add(llvm::createIndVarSimplifyPass());        // Canonicalize indvars
			manager.add(llvm::createLoopDeletionPass());          // Delete dead loops
			if( level > 2 )
			{
				manager.add(llvm::createLoopUnrollPass());          // Unroll small loops
			}
			manager.add(llvm::createInstructionCombiningPass());  // Clean up after the unroller
			manager.add(llvm::createGVNPass());                   // Remove redundancies
			manager.add(llvm::createMemCpyOptPass());             // Remove memcpy / form memset
			manager.add(llvm::createSCCPPass());                  // Constant prop with SCCP

			// Run instcombine after redundancy elimination to exploit opportunities
			// opened up by them.
			manager.add(llvm::createInstructionCombiningPass());
			manager.add(llvm::createDeadStoreEliminationPass());  // Delete dead stores
			manager.add(llvm::createAggressiveDCEPass());         // Delete dead instructions
			manager.add(llvm::createCFGSimplificationPass());     // Merge & remove BBs

		}
		manager.run( *module );
		#endif
	}
	
	void LLVMExecutableKernel::_optimize()
	{
		#ifdef HAVE_LLVM
		report( "Optimizing LLVM Code" );
	
		if( _optimizationLevel 
			== translator::Translator::BasicOptimization )
		{
			_optimizeLLVMFunction( _module, 1, false );
		}
		else if( _optimizationLevel 
			== translator::Translator::AggressiveOptimization )
		{
			_optimizeLLVMFunction( _module, 2, false );
		}
		else if( _optimizationLevel 
			== translator::Translator::SpaceOptimization )
		{
			_optimizeLLVMFunction( _module, 2, true );
		}
		else if( _optimizationLevel 
			== translator::Translator::FullOptimization )
		{
			_optimizeLLVMFunction( _module, 3, false );
		}

		_state.jit->addModule( _module );
		
		llvm::Function* function = _module->getFunction( 
			"_Z_ocelotTranslated_" + name );

		_updateGlobalMemory();

		assertM( function != 0, 
			"Could not find function _Z_ocelotTranslated_" + name );
		_function = hydrazine::bit_cast< Function >( 
			_state.jit->getPointerToFunction( function ) );

		#if ( REPORT_OPTIMIZED_LLVM_SOURCE > 0 ) && ( REPORT_BASE > 0 )
		std::string m;
		llvm::raw_string_ostream code( m );
		code << *_module;
		report( " The optimized code is:\n" << m );
		#endif
		
		report( " Successfully jit compiled the kernel." );
		#endif
	}
	
	void LLVMExecutableKernel::_allocateParameterMemory( )
	{
		report( "  Allocating parameter memory." );
				
		_context.parameterSize = 0;
		
		AllocationMap map;
		
		for( ParameterVector::iterator parameter = _ptx->parameters.begin(); 
			parameter != _ptx->parameters.end(); ++parameter )
		{
			_pad( _context.parameterSize, parameter->getAlignment() );
			
			report( "   Allocated parameter " << parameter->name << " from "
				<< _context.parameterSize << " to " 
				<< ( _context.parameterSize + parameter->getSize() ) );
			
			parameter->offset = _context.parameterSize;
			_context.parameterSize += parameter->getSize();
			
			map.insert( std::make_pair( parameter->name, parameter->offset ) );
		}
		
		report( "  Allocated " << _context.parameterSize 
			<< " for parameter memory." );
		
		_context.parameter = new char[ _context.parameterSize ];
	
		report( "  Determining offsets of operands that use parameters" );
	
		for( ir::ControlFlowGraph::iterator block = _ptx->cfg()->begin(); 
			block != _ptx->cfg()->end(); ++block )
		{
			for( ir::ControlFlowGraph::InstructionList::iterator 
				instruction = block->instructions.begin(); 
				instruction != block->instructions.end(); ++instruction )
			{
				ir::PTXInstruction& ptx = static_cast<
					ir::PTXInstruction&>(**instruction);
			
				ir::PTXOperand* operands[] = { &ptx.d, &ptx.a, &ptx.b, &ptx.c };
		
				if( ptx.opcode == ir::PTXInstruction::Mov
					|| ptx.opcode == ir::PTXInstruction::Ld
					|| ptx.opcode == ir::PTXInstruction::St )
				{
					for( unsigned int i = 0; i != 4; ++i )
					{
						if( operands[ i ]->addressMode 
							== ir::PTXOperand::Address )
						{
							AllocationMap::iterator 
								parameter = map.find( 
								operands[ i ]->identifier );
							if( parameter != map.end() )
							{
								report( "   For instruction \"" 
									<< ptx.toString() << "\" mapping \"" 
									<< parameter->first << "\" to " 
									<< (parameter->second 
									+ operands[ i ]->offset) );
								operands[ i ]->offset += parameter->second;
							}
						}
					}
				}
			
			}
		}
	}

	void LLVMExecutableKernel::_allocateSharedMemory( )
	{
		typedef std::unordered_set< std::string > StringSet;
		typedef std::deque< ir::PTXOperand* > OperandVector;
		typedef std::unordered_map< std::string, 
			ir::Module::GlobalMap::const_iterator > GlobalMap;

		report( "  Allocating shared memory." );
	
		AllocationMap map;
		GlobalMap sharedGlobals;
		StringSet external;
		OperandVector externalOperands;

		unsigned int externalAlignment = 1;		
		_context.sharedSize = 0;
				
		assert( module != 0 ); 

		for( ir::Module::GlobalMap::const_iterator 
			global = module->globals.begin(); 
			global != module->globals.end(); ++global ) 
		{
			if( global->second.statement.directive 
				== ir::PTXStatement::Shared ) 
			{
				if( global->second.statement.attribute 
					== ir::PTXStatement::Extern )
				{
					report( "   Allocating global external shared variable " 
						<< global->second.statement.name );
					assertM( external.count( 
						global->second.statement.name ) == 0, 
						"External global " << global->second.statement.name 
						<< " more than once." );
					external.insert( global->second.statement.name );
					externalAlignment = std::max( externalAlignment, 
						(unsigned int) global->second.statement.alignment );
					externalAlignment = std::max( externalAlignment, 
						ir::PTXOperand::bytes( 
						global->second.statement.type ) );
				}
				else 
				{
					report( "   Allocating global shared variable " 
						<< global->second.statement.name );
					sharedGlobals.insert( std::make_pair( 
						global->second.statement.name, global ) );
				}
			}
		}

		LocalMap::const_iterator local = _ptx->locals.begin();
		for( ; local != _ptx->locals.end(); ++local )
		{
			if( local->second.space == ir::PTXInstruction::Shared )
			{
				if( local->second.attribute == ir::PTXStatement::Extern )
				{
					report( "    Found local external shared variable " 
						<< local->second.name );
					assert( external.count( local->second.name ) == 0 );
					external.insert( local->second.name );
					externalAlignment = std::max( externalAlignment, 
						( unsigned int ) local->second.alignment );
					externalAlignment = std::max( externalAlignment, 
						ir::PTXOperand::bytes( local->second.type ) );
				}
				else
				{
					report( "   Found local shared variable " 
						<< local->second.name << " of size " 
						<< local->second.getSize() );
					_pad( _context.sharedSize, local->second.alignment );
					map.insert( std::make_pair( local->second.name, 
						_context.sharedSize ) );
					_context.sharedSize += local->second.getSize();
				}
			}
		}
		
		for( ir::ControlFlowGraph::iterator block = _ptx->cfg()->begin(); 
			block != _ptx->cfg()->end(); ++block )
		{
			for( ir::ControlFlowGraph::InstructionList::iterator 
				instruction = block->instructions.begin(); 
				instruction != block->instructions.end(); ++instruction )
			{
				ir::PTXInstruction& ptx = static_cast<
					ir::PTXInstruction&>(**instruction);

				ir::PTXOperand* operands[] = { &ptx.d, &ptx.a, 
					&ptx.b, &ptx.c };
		
				if( ptx.opcode == ir::PTXInstruction::Mov
					|| ptx.opcode == ir::PTXInstruction::Ld
					|| ptx.opcode == ir::PTXInstruction::St )
				{
					for( unsigned int i = 0; i != 4; ++i )
					{
						if( operands[ i ]->addressMode 
							== ir::PTXOperand::Address )
						{
							StringSet::iterator si = external.find(
								operands[ i ]->identifier );
							if( si != external.end() ) 
							{
								report("   For instruction \"" 
									<< ptx.toString() 
									<< "\", mapping shared label \"" << *si 
									<< "\" to external shared memory." );
								externalOperands.push_back( operands[ i ] );
								continue;
							}
						
							GlobalMap::iterator gi = sharedGlobals.find(
								operands[ i ]->identifier );
							if( gi != sharedGlobals.end() )
							{
								ir::Module::GlobalMap::const_iterator 
									it = gi->second;
								sharedGlobals.erase( gi );
							
								report( "   Found global shared variable " 
									<< it->second.statement.name );
							
								_pad( _context.sharedSize, 
									it->second.statement.alignment );
							
								map.insert( std::make_pair( 
									it->second.statement.name, 
									_context.sharedSize ) );
								_context.sharedSize 
									+= it->second.statement.bytes();
							}				
					
							AllocationMap::iterator mapping = map.find( 
								operands[ i ]->identifier );
							if( map.end() != mapping ) 
							{
								ptx.addressSpace = ir::PTXInstruction::Shared;
								operands[ i ]->offset += mapping->second;
								report("   For instruction " 
									<< ptx.toString() 
									<< ", mapping shared label " 
									<< mapping->first 
									<< " to " << mapping->second );
							}
						}
					}
				}
			}
		}

		_pad( _context.sharedSize, externalAlignment );

		report( "   Mapping external shared variables." );
		for( OperandVector::iterator operand = externalOperands.begin(); 
			operand != externalOperands.end(); ++operand ) 
		{
			report( "    Mapping external shared label " 
				<< (*operand)->identifier << " to " << _context.sharedSize );
			(*operand)->offset += _context.sharedSize;
		}
	
		report( "   Total shared memory size is " << _context.sharedSize 
			<< " declared plus " << _externSharedMemorySize << " external." );
		_context.shared = new char[ _context.sharedSize 
			+ _externSharedMemorySize ];
		_sharedMemorySize = _context.sharedSize;
	}
	
	void LLVMExecutableKernel::_allocateGlobalMemory( )
	{
		report( " Allocating global memory" );
	}
	
	void LLVMExecutableKernel::_allocateLocalMemory( )
	{
		report( " Allocating local memory" );
		AllocationMap map;

		_context.localSize = 0;
		
		for( LocalMap::iterator local = _ptx->locals.begin(); 
			local != _ptx->locals.end(); ++local )
		{
			if( local->second.space == ir::PTXInstruction::Local )
			{
				report( "   Found local local variable " 
					<< local->second.name << " of size " 
					<< local->second.getSize() );
				_pad( _context.localSize, local->second.alignment );
				map.insert( std::make_pair( local->second.name,
					_context.localSize ) );
				_context.localSize += local->second.getSize();
			}
		}
		
		for( ir::ControlFlowGraph::iterator block = _ptx->cfg()->begin(); 
			block != _ptx->cfg()->end(); ++block )
		{
			for( ir::ControlFlowGraph::InstructionList::iterator 
				instruction = block->instructions.begin(); 
				instruction != block->instructions.end(); ++instruction )
			{
				ir::PTXInstruction& ptx = static_cast<
					ir::PTXInstruction&>(**instruction);
				ir::PTXOperand* operands[] = { &ptx.d, &ptx.a, 
					&ptx.b, &ptx.c };
		
				if( ptx.opcode == ir::PTXInstruction::Mov
					|| ptx.opcode == ir::PTXInstruction::Ld
					|| ptx.opcode == ir::PTXInstruction::St )
				{
					for( unsigned int i = 0; i != 4; ++i )
					{
						if( operands[ i ]->addressMode 
							== ir::PTXOperand::Address )
						{
							AllocationMap::iterator mapping = map.find( 
								operands[ i ]->identifier );
							if( map.end() != mapping ) 
							{
								ptx.addressSpace 
									= ir::PTXInstruction::Local;
								operands[ i ]->offset += mapping->second;
								report("   For instruction " 
									<< ptx.toString() 
									<< ", mapping local label " 
										<< mapping->first 
									<< " to " << mapping->second );
							}
						}
					}
				}
			}	
		}

		report( "   Total local memory size is " << _context.localSize 
			<< " for " << threads() << " threads." );

		_context.local = new char[ threads() * _context.localSize ];		

		if( _barrierSupport )
		{
			report( "   Adding barrier sync point mapping." );
			AllocationMap::iterator mapping = map.find( _resumePoint );
			assert( mapping != map.end() );
			report( "    Creating map from syncpoint variable " 
				<< _resumePoint << " to local memory offset " 
				<< mapping->second );
			_resumePointOffset = mapping->second;
			
		}

		_localMemorySize = _context.localSize;
	}
	
	void LLVMExecutableKernel::_allocateConstantMemory( )
	{
		report( " Allocating Constant Memory" );
		_context.constantSize = 0;
		_constants.clear();

		for( ir::Module::GlobalMap::const_iterator 
			global = module->globals.begin(); 
			global != module->globals.end(); ++global ) 
		{
			if( global->second.statement.directive 
				== ir::PTXStatement::Const ) 
			{
				report( "   Found global constant variable " 
					<< global->second.statement.name << " of size " 
					<< global->second.statement.bytes() );
				_pad( _context.constantSize, 
					global->second.statement.alignment );
				_constants.insert( std::make_pair( 
					global->second.statement.name, _context.constantSize ) );
				_context.constantSize += global->second.statement.bytes();
			}
		}
		
		for( ir::ControlFlowGraph::iterator block = _ptx->cfg()->begin(); 
			block != _ptx->cfg()->end(); ++block )
		{
			for( ir::ControlFlowGraph::InstructionList::iterator 
				instruction = block->instructions.begin(); 
				instruction != block->instructions.end(); ++instruction )
			{
				ir::PTXInstruction& ptx = static_cast<
					ir::PTXInstruction&>(**instruction);
				ir::PTXOperand* operands[] = { &ptx.d, &ptx.a, 
					&ptx.b, &ptx.c };
		
				if( ptx.opcode == ir::PTXInstruction::Mov
					|| ptx.opcode == ir::PTXInstruction::Ld
					|| ptx.opcode == ir::PTXInstruction::St )
				{
					for( unsigned int i = 0; i != 4; ++i )
					{
						if( operands[ i ]->addressMode == ir::PTXOperand::Address )
						{
							AllocationMap::iterator mapping = _constants.find( 
								operands[ i ]->identifier );
							if( _constants.end() != mapping ) 
							{
								ptx.addressSpace 
									= ir::PTXInstruction::Const;
								operands[ i ]->offset += mapping->second;
								report("   For instruction " 
									<< ptx.toString() 
									<< ", mapping constant label " << mapping->first 
									<< " to " << mapping->second );
							}
						}
					}
				}
			}	
		}

		report( "   Total constant memory size is " << _context.constantSize 
			<< "." );

		_context.constant = new char[ _context.constantSize ];
		_constMemorySize = _context.constantSize;
	}
	
	void LLVMExecutableKernel::_allocateTextureMemory( )
	{
		report( " Allocating Texture Memory" );
		_opaque.textures.clear();
		
		AllocationMap map;
		unsigned int index = 0;
		
		for( ir::ControlFlowGraph::iterator block = _ptx->cfg()->begin(); 
			block != _ptx->cfg()->end(); ++block )
		{
			for( ir::ControlFlowGraph::InstructionList::iterator 
				instruction = block->instructions.begin(); 
				instruction != block->instructions.end(); ++instruction )
			{
				ir::PTXInstruction& ptx = static_cast<
					ir::PTXInstruction&>(**instruction);
				if( ptx.opcode == ir::PTXInstruction::Tex )
				{
					report("  found texture instruction: " << ptx.toString());

					ir::Module::TextureMap::const_iterator 
						texture = module->textures.find(ptx.a.identifier);

					assert( texture != module->textures.end() );
		
					AllocationMap::iterator 
						allocation = map.find( texture->first );
					if( allocation == map.end() )
					{
						report( "  Allocating texture " << texture->first 
							<< " to index " << index << " with data " 
							<< texture->second.data << " and type " << texture->second.type);
						allocation = map.insert( 
							std::make_pair( texture->first, index++ ) ).first;
						_opaque.textures.push_back( &texture->second );
					}
					ptx.a.reg = allocation->second;
				}
			}
		}
	}
	
	void LLVMExecutableKernel::_allocateMemory()
	{
		report( " Allocating Memory" );
		
		_allocateParameterMemory();
		_allocateSharedMemory();
		_allocateGlobalMemory();
		_allocateLocalMemory();
		_allocateConstantMemory();
		_allocateTextureMemory();
	}

	void LLVMExecutableKernel::_updateGlobalMemory()
	{
		#ifdef HAVE_LLVM
		report( "Updating global memory." );
		_state.jit->clearAllGlobalMappings();
		for( ir::Module::GlobalMap::const_iterator 
			global = module->globals.begin(); 
			global != module->globals.end(); ++global ) 
		{
			switch( global->second.statement.directive ) 
			{
				case ir::PTXStatement::Global:
				{
					llvm::GlobalValue* 
						value = _module->getNamedValue( global->first );
					assertM( value != 0, "Global variable " << global->first 
						<< " not found in llvm module." );
					report( " Binding global variable " << global->first 
						<< " to " << (void*)global->second.pointer );
					_state.jit->addGlobalMapping( value, 
						global->second.pointer );
					break;
				}
				default:
				{
					break;
				}
			}
		}
		#endif
	}
	
	void LLVMExecutableKernel::_updateConstantMemory()
	{
		report( "Updating constant memory." );
		
		for( AllocationMap::iterator constant = _constants.begin(); 
			constant != _constants.end(); ++constant ) 
		{
			report( " Updating constant variable " << constant->first );
			ir::Module::GlobalMap::const_iterator 
				global = module->globals.find( constant->first );
			assert( global != module->globals.end() );
			assert( global->second.statement.directive 
				== ir::PTXStatement::Const );
			assert( global->second.statement.bytes() 
				+ constant->second <= _context.constantSize );
			memcpy( _context.constant + constant->second, 
				global->second.pointer, global->second.statement.bytes() );
		}
	}
	
	void LLVMExecutableKernel::_buildDebuggingInformation()
	{
		if( _optimizationLevel != translator::Translator::DebugOptimization
			&& _optimizationLevel 
			!= translator::Translator::ReportOptimization ) return;
		
		report( "Building debug information." );
		
		ir::ControlFlowGraph::BasicBlock::Id id = 0;
		
		for( analysis::DataflowGraph::iterator block = _ptx->dfg()->begin(); 
			block != _ptx->dfg()->end(); ++block )
		{
			block->block()->id = id++;
			_opaque.blocks.insert( std::make_pair( block->id(), 
				block->block() ) );
		}
	}
	
	LLVMExecutableKernel::LLVMExecutableKernel( ir::Kernel& k, 
		const executive::Executive* c, 
		translator::Translator::OptimizationLevel l,
		const char *_overridePath ) : 
		ExecutableKernel( k, c ), _module( 0 ), _optimizationLevel( l )
	{
		assertM( k.ISA == ir::Instruction::PTX, 
			"LLVMExecutable kernel must be constructed from a PTXKernel" );
		ISA = ir::Instruction::LLVM;
		overrideLLVMKernel = false;
		if (_overridePath) {
			overrideLLVMKernel = true;
			overrideLLVMKernelPath = _overridePath;
		}
		
		_ptx = new ir::PTXKernel( static_cast< ir::PTXKernel& >( k ) );
		
		_context.shared = 0;
		_context.local = 0;
		_context.parameter = 0;
		_context.constant = 0;
		_context.nctaid.z = 1;
		_gridDim.z = 1;
		
		_context.ntid.x = 0;
		_context.ntid.y = 0;
		_context.ntid.z = 0;
		
		_context.other = (char*) &_opaque;
		_opaque.cache = &_cache;
		_opaque.kernel = this;
		
		_state.initialize();
	}
	
	LLVMExecutableKernel::~LLVMExecutableKernel()
	{	
		#ifdef HAVE_LLVM
		if( _module != 0 )
		{
			_state.jit->removeModule( _module );
		}
		#endif
		delete[] _context.local;
		delete[] _context.constant;
		delete[] _context.parameter;
		delete[] _context.shared;
		delete _ptx;
	}

	void LLVMExecutableKernel::launchGrid( int x, int y )
	{	
		_translateKernel();
		report( "Launching kernel \"" << name << "\" on grid ( x = " 
			<< x << ", y = " << y << " )"  );
		
		_context.nctaid.x = x;
		_context.nctaid.y = y;
		_gridDim.x = x;
		_gridDim.y = y;

		{
			// dump the function to stdout
			
		}
		
		_manager.launch( _function, &_context, 
			_barrierSupport, _resumePointOffset, _externSharedMemorySize );
	}
	
	void LLVMExecutableKernel::setKernelShape( int x, int y, int z )
	{
		report( "Setting CTA shape to ( x = " << x << ", y = " 
			<< y << ", z = " << z << " ) for kernel \"" << name << "\""  );
		unsigned int previous = threads();
	
		_context.ntid.x = x;
		_context.ntid.y = y;
		_context.ntid.z = z;
		_blockDim.x = x;
		_blockDim.y = y;
		_blockDim.z = z;
		
		if( previous != threads() )
		{
			if( _context.local != 0 )
			{
				report( " Reallocating local memory of " << _context.localSize 
					<< " bytes per thread ( " 
					<< ( threads() * _context.localSize ) << " total )" );
				delete[] _context.local;
				_context.local = new char[ threads() * _context.localSize ];
			}
		}
	}

	void LLVMExecutableKernel::setExternSharedMemorySize( unsigned int bytes )
	{
		_translateKernel();
		
		if( bytes != _externSharedMemorySize )
		{
			report( "Setting external shared memory to " << bytes 
				<< " total size is " << (bytes + _context.sharedSize) );
			delete[] _context.shared;
			_externSharedMemorySize = bytes;
			_context.shared = new char[ _externSharedMemorySize
				+ _context.sharedSize ];
		}
	}

	void LLVMExecutableKernel::setDevice( const Device* device, 
		unsigned int threadLimit )
	{
		_manager.setMaxThreadsPerCta( device->maxThreadsPerBlock );
		_manager.setThreadCount( 
			std::min( (unsigned int)device->multiprocessorCount, 
			threadLimit ) );
	}
	
	void LLVMExecutableKernel::updateParameterMemory()
	{
		_translateKernel();
	
		size_t size = 0;
		for( ParameterVector::iterator parameter = parameters.begin();
			parameter != parameters.end(); ++parameter ) 
		{
			_pad( size, parameter->getAlignment() );
			for( ir::Parameter::ValueVector::iterator 
				value = parameter->arrayValues.begin(); 
				value != parameter->arrayValues.end(); ++value ) 
			{
				assertM( size < _context.parameterSize, "Size " << size 
					<< " not less than allocated parameter size " 
					<< _context.parameterSize );
				memcpy( _context.parameter + size, &value->val_b16, 
					parameter->getElementSize() );
				size += parameter->getElementSize();
			}
		}
	}

	void LLVMExecutableKernel::updateMemory()
	{
		_updateGlobalMemory();
		_updateConstantMemory();
	}

	ir::ExecutableKernel::TextureVector 
		LLVMExecutableKernel::textureReferences() const
	{
		return _opaque.textures;
	}
	
	void LLVMExecutableKernel::addTraceGenerator(
		trace::TraceGenerator *generator)
	{
		assertM(false, "No trace generation support in LLVM kernel.");
	}

	void LLVMExecutableKernel::removeTraceGenerator(
		trace::TraceGenerator *generator)
	{
		assertM(false, "No trace generation support in LLVM kernel.");	
	}

	unsigned int LLVMExecutableKernel::threads() const
	{
		return _context.ntid.x * _context.ntid.y * _context.ntid.z;
	}
	
	unsigned int LLVMExecutableKernel::threadId() const
	{
		return _context.ntid.x * _context.ntid.y * _context.tid.z 
			+ _context.ntid.x * _context.tid.y + _context.tid.x;
	}
	
	std::string LLVMExecutableKernel::location( unsigned int statement ) const
	{
		ir::Module::StatementVector::const_iterator s_it 
			= module->statements.begin();
		std::advance(s_it, statement);
		ir::Module::StatementVector::const_reverse_iterator s_rit 
			= ir::Module::StatementVector::const_reverse_iterator(s_it);
		unsigned int program = 0;
		unsigned int line = 0;
		unsigned int col = 0;
		for ( ; s_rit != module->statements.rend(); ++s_rit) {
			if (s_rit->directive == ir::PTXStatement::Loc) {
				line = s_rit->sourceLine;
				col = s_rit->sourceColumn;
				program = s_rit->sourceFile;
				break;
			}
		}
	
		std::string fileName;
		for ( s_it = module->statements.begin(); 
			s_it != module->statements.end(); ++s_it ) {
			if (s_it->directive == ir::PTXStatement::File) {
				if (s_it->sourceFile == program) {
					fileName = s_it->name;
					break;
				}
			}
		}
	
		std::stringstream stream;
		stream << fileName << ":" << line << ":" << col;
		return stream.str();
	}
	
	std::string LLVMExecutableKernel::instruction( 
		unsigned int statement ) const
	{
		ir::Module::StatementVector::const_iterator s_it 
			= module->statements.begin();
		std::advance(s_it, statement);
		return s_it->instruction.toString();
	}
}

#endif


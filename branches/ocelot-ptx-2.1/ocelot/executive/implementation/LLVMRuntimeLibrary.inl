/*! \file LLVMRuntimeLibrary.cpp
	\date Wednesday June 16, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief A source file for the library of emulation function available to 
		translated kernels
*/


#ifndef LLVM_RUNTIME_LIBRARY_INL_INCLUDED
#define LLVM_RUNTIME_LIBRARY_INL_INCLUDED

#define REPORT_ATOMIC_OPERATIONS 0

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

#ifdef isnormal
#define _isnormal(x) isnormal(x)
#else
#define _isnormal(x) std::isnormal(x)
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
	bool __ocelot_testp_finite_f32( float a )
	{
		return !_isinf( a );
	}
	
	bool __ocelot_testp_infinite_f32( float a )
	{
		return _isinf( a );
	}
	
	bool __ocelot_testp_number_f32( float a )
	{
		return !_isnan( a );
	}
	
	bool __ocelot_testp_notanumber_f32( float a )
	{
		return _isnan( a );
	}
	
	bool __ocelot_testp_normal_f32( float a )
	{
		return _isnormal( a );
	}
	
	bool __ocelot_testp_subnormal_f32( float a )
	{
		return !_isinf( a ) && !_isnan( a ) && !_isnormal( a );
	}
	
	bool __ocelot_testp_finite_f64( double a )
	{
		return !_isinf( a );
	}
	
	bool __ocelot_testp_infinite_f64( double a )
	{
		return _isinf( a );
	}
	
	bool __ocelot_testp_number_f64( double a )
	{
		return !_isnan( a );
	}
	
	bool __ocelot_testp_notanumber_f64( double a )
	{
		return _isnan( a );
	}
	
	bool __ocelot_testp_normal_f64( double a )
	{
		return _isnormal( a );
	}
	
	bool __ocelot_testp_subnormal_f64( double a )
	{
		return !_isinf( a ) && !_isnan( a ) && !_isnormal( a );
	}
	
	unsigned int __ocelot_bfi_b32( unsigned int in, unsigned int orig, 
		unsigned int position, unsigned int length )
	{
		return hydrazine::bitFieldInsert( in, orig, position, length );
	}

	unsigned int __ocelot_bfi_b64( long long unsigned int in, 
		long long unsigned int orig, unsigned int position, 
		unsigned int length )
	{
		return hydrazine::bitFieldInsert( in, orig, position, length );
	}

	unsigned int __ocelot_bfind_b32( unsigned int a, bool shift )
	{
		return hydrazine::bfind( a, shift );
	}

	unsigned int __ocelot_bfind_b64( long long unsigned int a, bool shift )
	{
		return hydrazine::bfind( a, shift );
	}

	unsigned int __ocelot_brev_b32( unsigned int a )
	{
		return hydrazine::brev( a );
	}

	long long unsigned int __ocelot_brev_b64( long long unsigned int a )
	{
		return hydrazine::brev( a );
	}

	unsigned int __ocelot_clz_b32( unsigned int a )
	{
		return hydrazine::countLeadingZeros( a );
	}

	unsigned int __ocelot_clz_b64( long long unsigned int a )
	{
		return hydrazine::countLeadingZeros( a );
	}

	unsigned int __ocelot_popc_b32( unsigned int a )
	{
		return hydrazine::popc( a );
	}

	unsigned int __ocelot_popc_b64( long long unsigned int a )
	{
		return hydrazine::popc( a );
	}

	unsigned int __ocelot_prmt( unsigned int a, unsigned int b, unsigned int c )
	{
		return hydrazine::permute< hydrazine::DefaultPermute >( a, b, c );
	}

	unsigned int __ocelot_prmt_f4e( unsigned int a, unsigned int b, 
		unsigned int c )
	{
		return hydrazine::permute< hydrazine::ForwardFourExtract >( a, b, c );
	}

	unsigned int __ocelot_prmt_b4e( unsigned int a, unsigned int b, 
		unsigned int c )
	{
		return hydrazine::permute< hydrazine::BackwardFourExtract >( a, b, c );
	}

	unsigned int __ocelot_prmt_rc8( unsigned int a, unsigned int b, 
		unsigned int c )
	{
		return hydrazine::permute< hydrazine::ReplicateEight >( a, b, c );
	}

	unsigned int __ocelot_prmt_ecl( unsigned int a, unsigned int b, 
		unsigned int c )
	{
		return hydrazine::permute< hydrazine::EdgeClampLeft >( a, b, c );
	}

	unsigned int __ocelot_prmt_ecr( unsigned int a, unsigned int b, 
		unsigned int c )
	{
		return hydrazine::permute< hydrazine::EdgeClampRight >( a, b, c );
	}

	unsigned int __ocelot_prmt_rc16( unsigned int a, unsigned int b, 
		unsigned int c )
	{
		return hydrazine::permute< hydrazine::ReplicateSixteen >( a, b, c );
	}

	long long int __ocelot_mul_hi_s64( long long int a, long long int b )
	{
		long long int hi = 0;
		long long int lo = 0;
		
		hydrazine::multiplyHiLo( hi, lo, a, b );
		
		return hi;
	}

	long long unsigned int __ocelot_mul_hi_u64( long long unsigned int a, 
		long long unsigned int b )
	{
		long long unsigned int hi = 0;
		long long unsigned int lo = 0;
		
		hydrazine::multiplyHiLo( hi, lo, a, b );
		
		return hi;
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
		#if(DEBUG_PTX_INSTRUCTION_TRACE == 1)		
		void* instruction = (void*) _instruction;

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
		
		if( !state->kernel->device->checkMemoryAccess( address, bytes ) )
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
			std::cerr << 
				state->kernel->device->nearbyAllocationsToString( address );
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
				<< _address << " = " << (void *)_address << " of size " 
					<< bytes << " bytes is " << (end - allocationEnd)
				<< " bytes beyond the constant memory block of " 
				<< context->constantSize << " bytes\n  on interval: " 
				<< (void *)context->constant 
				<< " - " << (void *)allocationEnd << "\n";
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

#endif


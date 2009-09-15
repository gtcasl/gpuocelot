/*!
	\file LLVMExecutableKernel.cpp
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMExecutableKernel class
*/

#ifndef LLVM_EXECUTABLE_KERNEL_CPP_INCLUDED
#define LLVM_EXECUTABLE_KERNEL_CPP_INCLUDED

#include <ocelot/executive/interface/LLVMExecutableKernel.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <ocelot/translator/interface/PTXToLLVMTranslator.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/RemoveBarrierPass.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1
#define REPORT_ALL_PTX_SOURCE 1
#define REPORT_ALL_LLVM_SOURCE 1
#define REPORT_INSIDE_TRANSLATED_CODE 1

#include <configure.h>

#ifdef HAVE_LLVM
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/Parser.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/JIT.h> 
#include <llvm/Module.h>
#include <llvm/ModuleProvider.h>
#include <llvm/PassManager.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Target/TargetData.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/Transforms/Scalar.h>
#endif

#include <unordered_set>

extern "C"
{
	void setRoundingMode( unsigned int mode )
	{
		assertM( mode == 0, "No support for setting exotic rounding modes." );
	}
}

namespace executive
{

	LLVMExecutableKernel::LLVMState LLVMExecutableKernel::_state;

	LLVMExecutableKernel::LLVMState::LLVMState()		
	{
		#ifdef HAVE_LLVM
		report( "Bringing the LLVM JIT-Compiler online." );

		module = new llvm::Module( "Ocelot-LLVM-JIT-Blank Module", 
			llvm::getGlobalContext() );
		
		moduleProvider = new llvm::ExistingModuleProvider( module );
		assertM( moduleProvider != 0, 
			"Creating the global module provider failed.");
		
		llvm::InitializeNativeTarget();
		
		jit = llvm::EngineBuilder( moduleProvider ).create();
	
		assertM( jit != 0, "Creating the JIT failed.");
		report( " The JIT is alive." );
		#endif
	}
	
	LLVMExecutableKernel::LLVMState::~LLVMState()
	{
		#ifdef HAVE_LLVM
		report( "Deleting the LLVM JIT-Compiler." );
		delete jit;
		#endif
	}
	
	unsigned int LLVMExecutableKernel::_pad( size_t& size, 
		unsigned int alignment )
	{
		unsigned int padding = alignment - ( size % alignment );
		padding = ( alignment == padding ) ? 0 : padding;
		size += padding;
		return padding;
	}

	void LLVMExecutableKernel::_optimizePtx()
	{
		report( " Running PTX optimizer" );

		report( "  Running remove barrier pass." );
		reportE( REPORT_ALL_PTX_SOURCE, "   Code before pass:\n" << *this );

		analysis::RemoveBarrierPass pass;
		
		pass.initialize( *module );
		pass.runOnKernel( *this );
		pass.finalize();

		reportE( REPORT_ALL_PTX_SOURCE, "   Code after pass:\n" << *this );
	}

	void LLVMExecutableKernel::_translateKernel()
	{
		#ifdef HAVE_LLVM
		if( _module == 0 )
		{
			report( "Translating PTX kernel \"" << name << "\" to LLVM" );
			
			_optimizePtx();
			_allocateMemory();

			translator::PTXToLLVMTranslator translator;
			
			report( " Running translator" );
			ir::LLVMKernel* llvmKernel = static_cast< 
				ir::LLVMKernel* >( translator.translate( this ) );

			report( " Assembling llvm module" );
			llvmKernel->assemble();

			report( " Parsing llvm assembly." );
			llvm::SMDiagnostic error;
			_module = new llvm::Module( name, llvm::getGlobalContext() );
			_module = llvm::ParseAssemblyString( llvmKernel->code().c_str(), 
				_module, error, llvm::getGlobalContext() );
			
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
			
			delete llvmKernel;
			
			report( " Checking module for errors." );
			std::string verifyError;
			if( llvm::verifyModule( *_module, 
				llvm::ReturnStatusAction, &verifyError ) )
			{
				report( "  Verifying kernel failed, dumping code:\n" 
					<< llvmKernel->numberedCode() );
				throw hydrazine::Exception( "LLVM Verifier failed for kernel: " 
					+ name + " : \"" + verifyError + "\"" );
			}
			
			report( " Successfully created LLVM Module from translated PTX." );
			
			#if ( REPORT_ALL_LLVM_SOURCE > 0 ) && ( REPORT_BASE > 0 )
			std::string m;
			llvm::raw_string_ostream code( m );
			code << *_module;
			reportE( REPORT_ALL_LLVM_SOURCE, " The initial code is:\n" << m );
			#endif
			
			_optimize();
			
		}
		#else
		assertM( false, "LLVM support not compiled into Ocelot." );
		#endif
	}

	void LLVMExecutableKernel::_optimize( )
	{
		#ifdef HAVE_LLVM
		report( "Optimizing LLVM Code" );
	
		_moduleProvider = new llvm::ExistingModuleProvider( _module );
		assertM( _moduleProvider != 0, "Creating the module provider failed.");
		
		_state.jit->addModuleProvider( _moduleProvider );
		
		llvm::FunctionPassManager manager( _moduleProvider );
		
		manager.add( new llvm::TargetData( *_state.jit->getTargetData() ) );
		manager.add( llvm::createInstructionCombiningPass() );
		manager.add( llvm::createReassociatePass() );
		manager.add( llvm::createGVNPass() );
		manager.add( llvm::createCFGSimplificationPass() );

		llvm::Function* function = 
			_module->getFunction( "_Z_ocelotTranslated_" + name );

		assertM( function != 0, 
			"Could not find function _Z_ocelotTranslated_" + name );
				
		manager.run( *function );

		#if ( REPORT_ALL_LLVM_SOURCE > 0 ) && ( REPORT_BASE > 0 )
		std::string m;
		llvm::raw_string_ostream code( m );
		code << *_module;
		report( " The optimized code is:\n" << m );
		#endif
	
		// This insanity is needed to avoid a warning on g++
		union
		{
			void* one;
			Function two;
		} cast;
	
		cast.one = _state.jit->getPointerToFunction( function );
		_function = cast.two;
		
		report( " Successfully jit compiled the kernel." );
		#endif
	}
	
	void LLVMExecutableKernel::_launchCta( unsigned int length, 
		unsigned int width )
	{
		report( " Launching cta ( " << length << ", " << width << " )" );
		_context.ctaid.x = length;
		_context.ctaid.y = width;
		
		ThreadSet set;
		
		for( int z = 0; z < _context.ntid.z; ++z )
		{
			_context.tid.z = z;
			for( int y = 0; y < _context.ntid.y; ++y )
			{
				_context.tid.y = y;
				for( int x = 0; x < _context.ntid.x; ++x )
				{
					_context.tid.x = x;
					reportE( REPORT_INSIDE_TRANSLATED_CODE, 
						"  Launching thread ( x " << x << ", y " << y 
						<< ", z " << z << " )" );
					unsigned int continuation = _function( &_context );
					if( continuation != 0 )
					{
						reportE( REPORT_INSIDE_TRANSLATED_CODE, 
							"   Thread blocked at " << continuation );
						set.push( continuation );
					}
				}
			}
		}
		
		assertM( set.empty(), 
			"No support for continuing blocked PTX threads." );
	}
	
	void LLVMExecutableKernel::_allocateParameterMemory( )
	{
		report( "  Allocating parameter memory." );
				
		_context.parameterSize = 0;
		
		AllocationMap map;
		
		for( ParameterVector::iterator parameter = parameters.begin(); 
			parameter != parameters.end(); ++parameter )
		{
			_pad( _context.parameterSize, parameter->alignment );
			
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
	
		for( PTXInstructionVector::iterator 
			instruction = instructions.begin(); 
			instruction != instructions.end(); ++instruction )
		{
			ir::PTXOperand* operands[] = { &instruction->d, &instruction->a, 
				&instruction->b, &instruction->c };
		
			if( instruction->opcode == ir::PTXInstruction::Mov
				|| instruction->opcode == ir::PTXInstruction::Ld
				|| instruction->opcode == ir::PTXInstruction::St )
			{
				for( unsigned int i = 0; i != 4; ++i )
				{
					if( operands[ i ]->addressMode == ir::PTXOperand::Address )
					{
						AllocationMap::iterator 
							parameter = map.find( operands[ i ]->identifier );
						if( parameter != map.end() )
						{
							report( "   For instruction \"" 
								<< instruction->toString() << "\" mapping \"" 
								<< parameter->first << "\" to " 
								<< parameter->second );
							operands[ i ]->offset = parameter->second;
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

		PTXStatementVector::const_iterator statement = start_iterator;
		for( ; statement != end_iterator; ++statement )
		{
			if( statement->directive == ir::PTXStatement::Shared )
			{
				if( statement->attribute == ir::PTXStatement::Extern )
				{
					report( "    Found local external shared variable " 
						<< statement->name );
					assert( external.count( statement->name ) == 0 );
					external.insert( statement->name );
					externalAlignment = std::max( externalAlignment, 
						( unsigned int ) statement->alignment );
					externalAlignment = std::max( externalAlignment, 
						ir::PTXOperand::bytes( statement->type ) );
				}
				else
				{
					report( "   Found local shared variable " 
						<< statement->name << " of size " 
						<< statement->bytes() );
					_pad( _context.sharedSize, statement->alignment );
					map.insert( std::make_pair( statement->name, 
						_context.sharedSize ) );
					_context.sharedSize += statement->bytes();
				}
			}
		}
		
		for( PTXInstructionVector::iterator 
			instruction = instructions.begin(); 
			instruction != instructions.end(); ++instruction )
		{
			ir::PTXOperand* operands[] = { &instruction->d, &instruction->a, 
				&instruction->b, &instruction->c };
		
			if( instruction->opcode == ir::PTXInstruction::Mov
				|| instruction->opcode == ir::PTXInstruction::Ld
				|| instruction->opcode == ir::PTXInstruction::St )
			{
				for( unsigned int i = 0; i != 4; ++i )
				{
					if( operands[ i ]->addressMode == ir::PTXOperand::Address )
					{
						StringSet::iterator si = external.find(
							operands[ i ]->identifier );
						if( si != external.end() ) 
						{
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
							_context.sharedSize += it->second.statement.bytes();
						}				
					
						AllocationMap::iterator mapping = map.find( 
							operands[ i ]->identifier );
						if( map.end() != mapping ) 
						{
							instruction->addressSpace 
								= ir::PTXInstruction::Shared;
							operands[ i ]->offset = mapping->second;
							report("   For instruction " 
								<< instruction->toString() 
								<< ", mapping shared label " << mapping->first 
								<< " to " << mapping->second );
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
			(*operand)->offset = _context.sharedSize;
		}
	
		report( "   Total shared memory size is " << _context.sharedSize );

	}
	
	void LLVMExecutableKernel::_allocateGlobalMemory( )
	{
		report( " Allocating global memory" );
		for( PTXInstructionVector::iterator 
			instruction = instructions.begin(); 
			instruction != instructions.end(); ++instruction )
		{
			ir::PTXOperand* operands[] = { &instruction->d, &instruction->a, 
				&instruction->b, &instruction->c };
		
			if( instruction->opcode == ir::PTXInstruction::Mov
				|| instruction->opcode == ir::PTXInstruction::Ld
				|| instruction->opcode == ir::PTXInstruction::St )
			{
				for( unsigned int i = 0; i != 4; ++i )
				{
					if( operands[ i ]->addressMode == ir::PTXOperand::Address )
					{
						ir::Module::GlobalMap::const_iterator 
							global = module->globals.find( 
							operands[ i ]->identifier );
						if( global != module->globals.end() )
						{
							operands[ i ]->imm_uint = 
								(ir::PTXU64) global->second.pointer;
							report("  Mapping global label " 
								<< operands[ i ]->identifier << " to " 
								<< operands[ i ]->imm_uint 
								<< " for instruction \"" 
								<< instruction->toString() << "\"" );
						}
					}
				}
			}
		}
	}
	
	void LLVMExecutableKernel::_allocateLocalMemory( )
	{
	
	}
	
	void LLVMExecutableKernel::_allocateConstantMemory( )
	{
	
	}
	
	void LLVMExecutableKernel::_allocateTextureMemory( )
	{
	
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
	
	LLVMExecutableKernel::LLVMExecutableKernel( ir::Kernel& k, 
		const executive::Executive* c ) : ExecutableKernel( k, c ), 
		_module( 0 ), _moduleProvider( 0 )
	{
		_context.shared = 0;
		_context.local = 0;
		_context.parameter = 0;
		_context.constant = 0;
		_context.nctaid.z = 1;
	}
	
	LLVMExecutableKernel::~LLVMExecutableKernel()
	{	
		#ifdef HAVE_LLVM
		if( _moduleProvider != 0 )
		{
			_state.jit->deleteModuleProvider( _moduleProvider );
		}
		#endif
		delete[] _context.local;
		delete[] _context.constant;
		delete[] _context.parameter;
		delete[] _context.shared;
	}

	void LLVMExecutableKernel::launchGrid( int x, int y )
	{	
		_translateKernel();
		report( "Launching kernel \"" << name << "\" on grid ( x = " 
			<< x << ", y = " << y << " )"  );
		for( int i = 0; i < x; ++i )
		{
			for( int j = 0; j < y; ++j )
			{
				_launchCta( i, j );
			}
		}
		report( " Kernel \"" << name << "\" finished successfully"  );
	}
	
	void LLVMExecutableKernel::setKernelShape( int x, int y, int z )
	{
		report( "Setting CTA shape to ( x = " << x << ", y = " 
			<< y << ", z = " << z << " ) for kernel \"" << name << "\""  );
		_context.ntid.x = x;
		_context.ntid.y = y;
		_context.ntid.z = z;
	}

	void LLVMExecutableKernel::updateParameterMemory()
	{
		_translateKernel();
	
		size_t size = 0;
		for( ParameterVector::iterator parameter = parameters.begin();
			parameter != parameters.end(); ++parameter ) {
			_pad( size, parameter->getAlignment() );
			for( ir::Parameter::ValueVector::iterator 
				value = parameter->arrayValues.begin(); 
				value != parameter->arrayValues.end(); ++value ) {
				assert( size < _context.parameterSize );
				memcpy( _context.parameter + size, &value->val_b16, 
					parameter->getElementSize() );
				size += parameter->getElementSize();
			}
		}
	}
}

#endif


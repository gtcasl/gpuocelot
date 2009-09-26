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
#include <ocelot/analysis/interface/ConvertPredicationToSelectPass.h>
#include <fstream>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1
#define REPORT_ALL_PTX_SOURCE 0
#define REPORT_ALL_LLVM_SOURCE 0
#define REPORT_INSIDE_TRANSLATED_CODE 0
#define PRINT_OPTIMIZED_CFG 0

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
	
	float ex2( float value )
	{
		return std::pow( 2.0, value );
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
			std::ofstream file("ptxcfgoriginal.dot");
			_ptx->cfg()->write(file, _ptx->instructions);
			file.close();
			#endif
			
			_optimizePtx();
			_allocateMemory();

			translator::PTXToLLVMTranslator translator;

			#if (PRINT_OPTIMIZED_CFG > 0) && (REPORT_BASE > 0)
			file.open("ptxcfgoptimized.dot");
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

			#if ( REPORT_ALL_LLVM_SOURCE > 0 ) && ( REPORT_BASE > 0 )
			std::string m;
			llvm::raw_string_ostream code( m );
			code << *_module;
			reportE( REPORT_ALL_LLVM_SOURCE, " The initial code is:\n" << m );
			#endif
						
			report( " Checking module for errors." );
			std::string verifyError;
			if( llvm::verifyModule( *_module, 
				llvm::ReturnStatusAction, &verifyError ) )
			{
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

	void LLVMExecutableKernel::_launchCtaNoBarriers( )
	{
		char* localBase = _context.local;
		bool done = true;
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
					_context.local = localBase 
						+ _context.localSize * threadId();
					unsigned int resume = _function( &_context );
					done &= resume == 0;
					reportE( REPORT_INSIDE_TRANSLATED_CODE, 
						"   Thread blocked at " << resume );
				}
			}
		}	

		_context.local = localBase;		
		assertM( done, 
			"Not all threads finished in kernel with no context switches" );
	}
	
	void LLVMExecutableKernel::_launchCtaWithBarriers( )
	{
		char* localBase = _context.local;
		bool done = false;
		
		for( unsigned int i = 0; i < threads(); ++i )
		{
			(*(unsigned int*)(localBase 
				+ i * _context.localSize + _resumePointOffset)) = 0;
		}
		
		while( !done )
		{
			done = true;
			for( int z = 0; z < _context.ntid.z; ++z )
			{
				_context.tid.z = z;
				for( int y = 0; y < _context.ntid.y; ++y )
				{
					_context.tid.y = y;
					for( int x = 0; x < _context.ntid.x; ++x )
					{
						_context.tid.x = x;
						_context.local = localBase 
							+ _context.localSize * threadId();
						reportE( REPORT_INSIDE_TRANSLATED_CODE, 
							"  Launching thread ( x " << x << ", y " << y 
							<< ", z " << z << " )" << " at resume point " 
							<< *((unsigned int*)(_context.local 
							+ _resumePointOffset)) );
						unsigned int resume = _function( &_context );
						done &= resume == 0;
						*((unsigned int*)(_context.local 
							+ _resumePointOffset)) = resume;
						reportE( REPORT_INSIDE_TRANSLATED_CODE, 
							"   Thread blocked at " << resume );
					}
				}
			}
		}

		_context.local = localBase;		
	}
	
	void LLVMExecutableKernel::_launchCta( unsigned int length, 
		unsigned int width )
	{
		report( " Launching cta ( " << length << ", " << width << " )" );
		_context.ctaid.x = length;
		_context.ctaid.y = width;
		
		if( _barrierSupport )
		{
			report( "  Barrier support enabled." );
			_launchCtaWithBarriers();
		}
		else
		{
			report( "  Barrier support disabled." );
			_launchCtaNoBarriers();
		}
	}
	
	void LLVMExecutableKernel::_allocateParameterMemory( )
	{
		report( "  Allocating parameter memory." );
				
		_context.parameterSize = 0;
		
		AllocationMap map;
		
		for( ParameterVector::iterator parameter = _ptx->parameters.begin(); 
			parameter != _ptx->parameters.end(); ++parameter )
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
			instruction = _ptx->instructions.begin(); 
			instruction != _ptx->instructions.end(); ++instruction )
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
		
		for( PTXInstructionVector::iterator 
			instruction = _ptx->instructions.begin(); 
			instruction != _ptx->instructions.end(); ++instruction )
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
	
		report( "   Total shared memory size is " << _context.sharedSize 
			<< " declared plus " << _externalSharedSize << " external." );
		_context.shared = new char[ _context.sharedSize + _externalSharedSize ];

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
		
		for( PTXInstructionVector::iterator 
			instruction = _ptx->instructions.begin(); 
			instruction != _ptx->instructions.end(); ++instruction )
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
						AllocationMap::iterator mapping = map.find( 
							operands[ i ]->identifier );
						if( map.end() != mapping ) 
						{
							instruction->addressSpace 
								= ir::PTXInstruction::Local;
							operands[ i ]->offset = mapping->second;
							report("   For instruction " 
								<< instruction->toString() 
								<< ", mapping local label " << mapping->first 
								<< " to " << mapping->second );
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
		
		for( PTXInstructionVector::iterator 
			instruction = _ptx->instructions.begin(); 
			instruction != _ptx->instructions.end(); ++instruction )
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
						AllocationMap::iterator mapping = _constants.find( 
							operands[ i ]->identifier );
						if( _constants.end() != mapping ) 
						{
							instruction->addressSpace 
								= ir::PTXInstruction::Const;
							operands[ i ]->offset = mapping->second;
							report("   For instruction " 
								<< instruction->toString() 
								<< ", mapping constant label " << mapping->first 
								<< " to " << mapping->second );
						}
					}
				}
			}
		}	

		report( "   Total constant memory size is " << _context.constantSize 
			<< "." );

		_context.constant = new char[ _context.constantSize ];
	}
	
	void LLVMExecutableKernel::_allocateTextureMemory( )
	{
		report( " Allocating Texture Memory" );
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
		_module( 0 ), _moduleProvider( 0 ), _externalSharedSize( 0 )
	{
		assertM( k.ISA == ir::Instruction::PTX, 
			"LLVMExecutable kernel must be constructed from a PTXKernel" );
		ISA = ir::Instruction::LLVM;
		
		_ptx = new ir::PTXKernel( static_cast< ir::PTXKernel& >( k ) );
		
		_context.shared = 0;
		_context.local = 0;
		_context.parameter = 0;
		_context.constant = 0;
		_context.nctaid.z = 1;
		
		_context.ntid.x = 0;
		_context.ntid.y = 0;
		_context.ntid.z = 0;
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
		delete _ptx;
	}

	void LLVMExecutableKernel::launchGrid( int x, int y )
	{	
		_translateKernel();
		report( "Launching kernel \"" << name << "\" on grid ( x = " 
			<< x << ", y = " << y << " )"  );
		
		_context.nctaid.x = x;
		_context.nctaid.y = y;
		for( int j = 0; j < y; ++j )
		{
			for( int i = 0; i < x; ++i )
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
		unsigned int previous = threads();
		
		_context.ntid.x = x;
		_context.ntid.y = y;
		_context.ntid.z = z;
		
		if( previous != threads() )
		{
			if( _context.local != 0 )
			{
				report( " Reallocating local memory of " << _context.localSize 
					<< " bytes per thread" );
				delete[] _context.local;
				_context.local = new char[ threads() * _context.localSize ];
			}
		}
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

	unsigned int LLVMExecutableKernel::constantMemorySize() const
	{
		return _context.constantSize;
	}
	
	unsigned int LLVMExecutableKernel::sharedMemorySize() const
	{
		return _context.sharedSize;
	}

	void LLVMExecutableKernel::externSharedMemory( unsigned int bytes )
	{
		_translateKernel();
		
		if( bytes != _externalSharedSize )
		{
			delete[] _context.shared;
			_externalSharedSize = bytes;
			_context.shared = new char[ _externalSharedSize
				+ _context.sharedSize ];
		}
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
	
	void LLVMExecutableKernel::updateGlobalMemory()
	{
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
					_state.jit->addGlobalMapping( value, 
						global->second.pointer );
					break;
				}
				case ir::PTXStatement::Tex:
				{
					assertM( false, 
						"No support for updating texture variables." );
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}
	
	void LLVMExecutableKernel::updateConstantMemory()
	{
		report( "Updating constant memory." );
		for( AllocationMap::iterator constant = _constants.begin(); 
			constant != _constants.end(); ++constant ) 
		{
			report( " Updating constant memory " << constant->first );
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
}

#endif


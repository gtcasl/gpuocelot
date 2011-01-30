/*! \file RemoveBarrierPass.cpp
	\date Tuesday September 15, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the RemoveBarrierPass class
*/

#ifndef REMOVE_BARRIER_PASS_CPP_INCLUDED
#define REMOVE_BARRIER_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/RemoveBarrierPass.h>
#include <ocelot/ir/interface/PTXKernel.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{
	DataflowGraph::RegisterId RemoveBarrierPass::_tempRegister()
	{
		return _kernel->dfg()->newRegister();
	}
	
	void RemoveBarrierPass::_addSpillCode( DataflowGraph::iterator block, 
		const DataflowGraph::Block::RegisterSet& alive )
	{
		unsigned int bytes = 0;
		
		ir::PTXInstruction move ( ir::PTXInstruction::Mov );
		
		move.type = ir::PTXOperand::u64;
		move.a.identifier = "__ocelot_remove_barrier_pass_stack";
		move.a.addressMode = ir::PTXOperand::Address;
		move.a.type = ir::PTXOperand::u64;
		
		move.d.reg = _tempRegister();
		move.d.addressMode = ir::PTXOperand::Register;
		move.d.type = ir::PTXOperand::u64;
		
		_kernel->dfg()->insert( block, move, block->instructions().size() - 1 );

		report( "   Saving " << alive.size() << " Registers" );
		
		for( DataflowGraph::Block::RegisterSet::const_iterator 
			reg = alive.begin(); reg != alive.end(); ++reg )
		{
			report( "    r" << reg->id );			
			ir::PTXInstruction save( 
				ir::PTXInstruction::St );
		
			save.type = reg->type;
			save.addressSpace = ir::PTXInstruction::Local;

			save.d.addressMode = ir::PTXOperand::Indirect;
			save.d.reg = move.d.reg;
			save.d.type = ir::PTXOperand::u64;
			save.d.offset = bytes;
			
			bytes += ir::PTXOperand::bytes( save.type );
		
			save.a.addressMode = ir::PTXOperand::Register;
			save.a.type = reg->type;
			save.a.reg = reg->id;
			
			_kernel->dfg()->insert( block, save, 
				block->instructions().size() - 1 );
		}
		
		_spillBytes = std::max( bytes, _spillBytes );
	}
	
	void RemoveBarrierPass::_addRestoreCode( DataflowGraph::iterator block, 
		const DataflowGraph::Block::RegisterSet& alive )
	{
		unsigned int bytes = 0;
	
		ir::PTXInstruction move ( ir::PTXInstruction::Mov );
		
		move.type = ir::PTXOperand::u64;
		move.a.identifier = "__ocelot_remove_barrier_pass_stack";
		move.a.addressMode = ir::PTXOperand::Address;
		move.a.type = ir::PTXOperand::u64;
		
		move.d.reg = _tempRegister();
		move.d.addressMode = ir::PTXOperand::Register;
		move.d.type = ir::PTXOperand::u64;
	
		for( DataflowGraph::Block::RegisterSet::const_iterator 
			reg = alive.begin(); reg != alive.end(); ++reg )
		{
			ir::PTXInstruction load( 
				ir::PTXInstruction::Ld );
		
			load.type = reg->type;
			load.addressSpace = ir::PTXInstruction::Local;
			
			load.a.addressMode = ir::PTXOperand::Indirect;
			load.a.reg = move.d.reg;
			load.a.type = ir::PTXOperand::u64;
			load.a.offset = bytes;
			
			bytes += ir::PTXOperand::bytes( load.type );
		
			load.d.addressMode = ir::PTXOperand::Register;
			load.d.type = reg->type;
			load.d.reg = reg->id;
			
			_kernel->dfg()->insert( block, load, 0 );
		}
	
		_kernel->dfg()->insert( block, move, 0 );
	}
	
	void RemoveBarrierPass::_addEntryPoint( DataflowGraph::iterator block )
	{
		std::stringstream stream;
		
		stream << "$__ocelot_remove_barrier_entry_" << _reentryPoint;
		
		DataflowGraph::iterator entry = _kernel->dfg()->insert( 
			_kernel->dfg()->begin(), stream.str() );
				
		ir::PTXInstruction move( ir::PTXInstruction::Mov );
		
		move.type = ir::PTXOperand::u64;
		move.a.identifier = "__ocelot_remove_barrier_pass_syncpoint";
		move.a.addressMode = ir::PTXOperand::Address;
		move.a.type = ir::PTXOperand::u32;
		
		move.d.reg = _tempRegister();
		move.d.addressMode = ir::PTXOperand::Register;
		move.d.type = ir::PTXOperand::u64;
		
		_kernel->dfg()->insert( entry, move, 0 );

		ir::PTXInstruction load( ir::PTXInstruction::Ld );

		load.addressSpace = ir::PTXInstruction::Local;
		load.type = ir::PTXOperand::u32;
		load.a = move.d;

		load.d.reg = _tempRegister();
		load.d.addressMode = ir::PTXOperand::Register;
		load.d.type = ir::PTXOperand::u32;
		
		_kernel->dfg()->insert( entry, load, 1 );

		ir::PTXInstruction setp( ir::PTXInstruction::SetP );
		
		setp.type = ir::PTXOperand::u32;
		setp.comparisonOperator = ir::PTXInstruction::Eq;

		setp.d.reg = _tempRegister();
		setp.d.addressMode = ir::PTXOperand::Register;
		setp.d.type = ir::PTXOperand::pred;
		
		setp.a = load.d;
		
		setp.b.addressMode = ir::PTXOperand::Immediate;
		setp.b.type = ir::PTXOperand::u32;
		setp.b.imm_uint = _reentryPoint;
		
		_kernel->dfg()->insert( entry, setp, 2 );
		
		ir::PTXInstruction branch( 
			ir::PTXInstruction::Bra );
		
		branch.d.addressMode = ir::PTXOperand::Label;
		branch.d.identifier = block->label();
		branch.pg = setp.d;

		_kernel->dfg()->insert( entry, branch, 3 );
		
		_kernel->dfg()->target( entry, block );
	}

	void RemoveBarrierPass::_removeBarrier( DataflowGraph::iterator block, 
		unsigned int id )
	{
		typedef DataflowGraph::Block::RegisterSet RegisterSet;
		
		DataflowGraph::InstructionVector::const_iterator 
			_instruction( block->instructions().begin() );
		std::advance( _instruction, id );
		DataflowGraph::iterator exitBlock( _kernel->dfg()->end() );
		std::advance( exitBlock, -1 );

		ir::PTXInstruction& instruction = static_cast< ir::PTXInstruction& >( 
			*_instruction->i );

		report( "  Converting instruction " << instruction.toString() );

		assert( instruction.opcode == ir::PTXInstruction::Bar );
		instruction.opcode = ir::PTXInstruction::Ret;
		instruction.reentryPoint = _reentryPoint;

		report( "   Converted to " << instruction.toString() );
		
		RegisterSet alive = block->alive( _instruction );
		
		DataflowGraph::iterator bottom = _kernel->dfg()->split( block, 
			id + 1, false );

		_addSpillCode( block, alive );
		_addRestoreCode( bottom, alive );
		
		_kernel->dfg()->redirect( block, bottom, exitBlock );
		
		_addEntryPoint( bottom );
	}
	
	void RemoveBarrierPass::_runOnBlock( DataflowGraph::iterator block )
	{
		for( DataflowGraph::InstructionVector::const_iterator 
			_instruction = block->instructions().begin(); 
			_instruction != block->instructions().end(); ++_instruction )
		{
			ir::PTXInstruction& instruction = static_cast< 
				ir::PTXInstruction& >( *_instruction->i );
			if( instruction.opcode == ir::PTXInstruction::Bar )
			{
				_barriers = true;
				instruction.reentryPoint = _reentryPoint;
				unsigned int bytes = _spillBytes;
				_spillBytes = 1;
				_removeBarrier( block, std::distance( 
					block->instructions().begin(), _instruction ) );
				_spillBytes = std::max( bytes, _spillBytes );
				++_reentryPoint;
				_kernel->dfg()->compute();
				break;
			}
		}
	}

	void RemoveBarrierPass::_addLocalVariables()
	{
		ir::PTXStatement syncVariable( ir::PTXStatement::Local );
		
		syncVariable.type = ir::PTXOperand::u32;
		syncVariable.name = "__ocelot_remove_barrier_pass_syncpoint";
		
		_kernel->locals.insert( std::make_pair( syncVariable.name, 
			ir::Local( syncVariable ) ) );

		ir::PTXStatement stack( ir::PTXStatement::Local );
		
		stack.type = ir::PTXOperand::u8;
		stack.name = "__ocelot_remove_barrier_pass_stack";
		stack.array.stride.push_back( _spillBytes );
		
		_kernel->locals.insert( std::make_pair( stack.name, 
			ir::Local( stack ) ) );
	}
	
	RemoveBarrierPass::RemoveBarrierPass()
		: KernelPass( DataflowGraphAnalysis, "RemoveBarriersPass" )
	{

	}

	void RemoveBarrierPass::initialize( const ir::Module& m )
	{
		_barriers = false;
	}
	
	void RemoveBarrierPass::runOnKernel( ir::Kernel& k )
	{
		report( "Removing barriers from kernel " << k.name );
		assertM( k.ISA == ir::Instruction::PTX, 
			"This pass is valid for PTX kernels only." );
		_reentryPoint = 1;
		_spillBytes = 1;
		_kernel = static_cast< ir::PTXKernel* >( &k );
		k.dfg()->compute();
		
		for( DataflowGraph::iterator block = k.dfg()->begin(); 
			block != k.dfg()->end(); ++block )
		{
			_runOnBlock( block );
		}
		
		_addLocalVariables();
	}
	
	void RemoveBarrierPass::finalize( )
	{
	
	}
	
	bool RemoveBarrierPass::barriers() const
	{
		return _barriers;
	}
	
	std::string RemoveBarrierPass::resume() const
	{
		return "__ocelot_remove_barrier_pass_syncpoint";
	}
}

#endif


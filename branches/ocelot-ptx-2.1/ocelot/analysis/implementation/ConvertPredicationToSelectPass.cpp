/*! \file ConvertPredicationToSelectPass.cpp
	\date Friday September 25, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the ConvertPredicationToSelectPass class
*/

#ifndef REMOVE_BARRIER_PASS_CPP_INCLUDED
#define REMOVE_BARRIER_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/ConvertPredicationToSelectPass.h>
#include <ocelot/ir/interface/PTXKernel.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{
	DataflowGraph::RegisterId ConvertPredicationToSelectPass::_tempRegister()
	{
		return _kernel->dfg()->newRegister();
	}

	void ConvertPredicationToSelectPass::_replacePredicate( 
		DataflowGraph::iterator block, unsigned int id )
	{
		typedef DataflowGraph::Block::RegisterSet RegisterSet;

		DataflowGraph::InstructionVector::const_iterator 
			instruction( block->instructions().begin() );
		std::advance( instruction, id );

		report( "  Converting instruction " << instruction->i->toString() );
		
		ir::PTXInstruction select( ir::PTXInstruction::SelP );

		ir::PTXInstruction& ptx = static_cast< ir::PTXInstruction& >( 
			*instruction->i );

		select.d = ptx.d;
		select.b = select.d;
		select.a = select.b;
		select.a.reg = _tempRegister();
		select.c = ptx.pg;
		
		ptx.pg.condition = ir::PTXOperand::PT;
		ptx.d.reg = select.a.reg;
			
		_kernel->dfg()->insert( block, select, id + 1 );
	}
	
	void ConvertPredicationToSelectPass::_runOnBlock( 
		DataflowGraph::iterator block )
	{
		for( DataflowGraph::InstructionVector::const_iterator 
			instruction = block->instructions().begin(); 
			instruction != block->instructions().end(); ++instruction )
		{
			ir::PTXInstruction& ptx = static_cast< ir::PTXInstruction& >( 
				*instruction->i );
		
			if( ptx.opcode != ir::PTXInstruction::Bra 
				&& ptx.opcode != ir::PTXInstruction::Call 
				&& ptx.opcode != ir::PTXInstruction::Ret )
			{
				if( ptx.pg.condition != ir::PTXOperand::PT )
				{
					_replacePredicate( block, std::distance( 
						block->instructions().begin(), instruction ) );
				}
			}
		}
	}

	
	ConvertPredicationToSelectPass::ConvertPredicationToSelectPass()
		: KernelPass( NoAnalysis, "ConvertPredicationToSelectPass" )
	{
	}

	void ConvertPredicationToSelectPass::initialize( const ir::Module& m )
	{

	}
	
	void ConvertPredicationToSelectPass::runOnKernel( ir::Kernel& k )
	{
		assertM( k.ISA == ir::Instruction::PTX, 
			"This pass is valid for PTX kernels only." );
		_kernel = static_cast< ir::PTXKernel* >( &k );
		k.dfg()->compute();
		
		for( DataflowGraph::iterator block = k.dfg()->begin(); 
			block != k.dfg()->end(); ++block )
		{
			_runOnBlock( block );
		}
	}
	
	void ConvertPredicationToSelectPass::finalize( )
	{
	
	}
	
}

#endif


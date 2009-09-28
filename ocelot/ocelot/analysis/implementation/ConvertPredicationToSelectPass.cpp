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

		report( "  Converting instruction " 
			<< _kernel->instructions[ instruction->id ].toString() );
		
		ir::PTXInstruction select( _kernel->version(), 
			ir::PTXInstruction::SelP );

		select.d = _kernel->instructions[ instruction->id ].d;
		select.b = select.d;
		select.a = select.b;
		select.a.reg = _tempRegister();
		select.c = _kernel->instructions[ instruction->id ].pg;
		
		_kernel->instructions[ instruction->id ].pg.condition 
			= ir::PTXOperand::PT;
		_kernel->instructions[ instruction->id ].d.reg = select.a.reg;
			
		_kernel->instructions.push_back( select );
		_kernel->dfg()->insert( block, _kernel->dfg()->convert( 
			_kernel->instructions.back(), 
			_kernel->instructions.size() - 1 ), id + 1 );
	}
	
	void ConvertPredicationToSelectPass::_runOnBlock( DataflowGraph::iterator block )
	{
		for( DataflowGraph::InstructionVector::const_iterator 
			instruction = block->instructions().begin(); 
			instruction != block->instructions().end(); ++instruction )
		{
			if( _kernel->instructions[ instruction->id ].opcode 
				!= ir::PTXInstruction::Bra 
				&& _kernel->instructions[ instruction->id ].opcode 
				!= ir::PTXInstruction::Call 
				&& _kernel->instructions[ instruction->id ].opcode 
				!= ir::PTXInstruction::Ret )
			{
				if( _kernel->instructions[ instruction->id ].pg.condition 
					!= ir::PTXOperand::PT )
				{
					_replacePredicate( block, std::distance( 
						block->instructions().begin(), instruction ) );
				}
			}
		}
	}

	
	ConvertPredicationToSelectPass::ConvertPredicationToSelectPass()
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


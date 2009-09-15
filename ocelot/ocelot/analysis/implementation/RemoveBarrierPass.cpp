/*! \file RemoveBarrierPass.cpp
	\date Tuesday September 15, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the RemoveBarrierPass class
*/

#ifndef REMOVE_BARRIER_PASS_CPP_INCLUDED
#define REMOVE_BARRIER_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/RemoveBarrierPass.h>
#include <ocelot/ir/interface/Kernel.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{
	RemoveBarrierPass::RemoveBarrierPass()
	{
	
	}

	void RemoveBarrierPass::initialize( const ir::Module& m )
	{
	
	}
	
	void RemoveBarrierPass::runOnKernel( ir::Kernel& k )
	{
		typedef ir::BasicBlock::BlockList BlockList;
		typedef ir::BasicBlock::InstructionList InstructionList;

		BlockList blocks = k.ptxCFG->get_blocks();
	
		k.buildDataflowGraph();
		for( BlockList::iterator block = blocks.begin(); 
			block != blocks.end(); ++block )
		{
			for( InstructionList::iterator ii = (*block)->instructions.begin();
				ii != (*block)->instructions.end(); ++ii )
			{
				ir::PTXInstruction& instruction = k.instructions[ *ii ];
				if( instruction.opcode != ir::PTXInstruction::Bar )
				{
					
				}
			}
		}
	}
	
	void RemoveBarrierPass::finalize( )
	{
	
	}
}

#endif


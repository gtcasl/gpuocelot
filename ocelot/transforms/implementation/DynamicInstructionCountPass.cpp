/*! \file DynamicInstructionCountPass.cpp
	\date Friday April 1, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the DynamicInstructionCountPass class
*/

#ifndef DYNAMIC_INSTRUCTION_COUNT_PASS_CPP_INCLUDED
#define DYNAMIC_INSTRUCTION_COUNT_PASS_CPP_INCLUDED

#include <ocelot/transforms/interface/DynamicInstructionCountPass.h>
#include <ocelot/transforms/interface/InstructionCountPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace transforms
{

    DynamicInstructionCountPass::DynamicInstructionCountPass() {

    }

    void DynamicInstructionCountPass::runOnKernel( ir::IRKernel& k )
	{
		
        analysis::DataflowGraph::RegisterId registerId = dfg().newRegister();  

        /* ensure that there is at least one basic block -- otherwise, skip this kernel */
        if(dfg().empty())
            return;
        
        analysis::DataflowGraph::iterator entry = dfg().begin();
        ++entry;

        /* instrumenting ptx at the beginning of the first basic block. */
        size_t instructionCount = entry->instructions().size();
        size_t count = calculateThreadId(entry, 0);
        size_t location = count;
        count = calculateBasicBlockCounterOffset(entry, 0, location);
        location += count;  
        countInstructions(entry, registerId, registerMap, instructionCount);

        unsigned int basicBlockId = 1;
        for( analysis::DataflowGraph::iterator block = ++(entry); 
		    block != dfg().end(); ++block )
	        {
               if(!block->instructions().empty()){
                    instructionCount = block->instructions().size();
                    count = calculateBasicBlockCounterOffset(block, basicBlockId, 0);
                    countInstructions(block, registerId, registerMap, instructionCount);
                    basicBlockId++;        
                } 
	        }
    }


}


#endif

/*! \file BasicBlockExecutionCountPass.cpp
	\date Sunday November 14, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockExecutionCountPass class
*/

#ifndef BASIC_BLOCK_EXECUTION_COUNT_PASS_CPP_INCLUDED
#define BASIC_BLOCK_EXECUTION_COUNT_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/BasicBlockExecutionCountPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis
{

    BasicBlockExecutionCountPass::BasicBlockExecutionCountPass() {

    }

    void BasicBlockExecutionCountPass::_runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId counterPtrRegId, DataflowGraph::RegisterId registerId, unsigned int offset)
	{

        /* Load, increment, and store back the result into the
            global counter */
        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.addressSpace = ir::PTXInstruction::Global; 
        ld.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);       
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.a.reg = counterPtrRegId;
        ld.a.offset = offset;
        ld.d.reg = registerId;
        ld.d.addressMode = ir::PTXOperand::Register;
		ld.d.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);		
        
        ir::PTXInstruction add(ir::PTXInstruction::Add);
        add.addressSpace = ir::PTXInstruction::Global; 
        add.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32); 
        add.a.addressMode = ir::PTXOperand::Register;    
        add.d = ld.d;
        add.a = ld.d;
        add.b.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);	
        add.b.addressMode = ir::PTXOperand::Immediate;
        add.b.imm_int = 1;
        

        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);       
        st.d = ld.a;
        st.a = ld.d;
        
        /* Need to insert in the beginning of the basic block.
            Since basic blocks usually end with branches, it
            wouldn't make sense to insert these instructions at the end. */
   
        kernel->dfg()->insert( block, ld, 0 );  
        kernel->dfg()->insert( block, add, 1 ); 
        kernel->dfg()->insert( block, st, 2 ); 

	}

}


#endif

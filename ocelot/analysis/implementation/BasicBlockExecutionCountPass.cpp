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

    void BasicBlockExecutionCountPass::_runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, std::map<std::string, DataflowGraph::RegisterId> registerMap, DataflowGraph::RegisterId registerId, unsigned int offset)
	{

	    //offset = (threadId + ntid * basic-block-id) * sizeof(size_t)
	    //mad offset, ntid, basic-block-id, threadId
	    //mul offset, offset, sizeof(size_t)	

	    ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

	    DataflowGraph::RegisterId index = kernel->dfg()->newRegister();
	    ir::PTXInstruction mad(ir::PTXInstruction::Mad);
        mad.type = ir::PTXOperand::u32;
        mad.modifier = ir::PTXInstruction::lo;

        mad.d.reg = index;        
        mad.d.addressMode = ir::PTXOperand::Register;
        mad.d.type = ir::PTXOperand::u32;
        
        mad.a.addressMode = ir::PTXOperand::Register;
        mad.a.type = ir::PTXOperand::u32;
        mad.a.reg = registerMap["ntid"];

        mad.b.addressMode = ir::PTXOperand::Immediate;
        mad.b.type = ir::PTXOperand::u32;
        mad.b.imm_int = (offset/sizeof(size_t));

        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = ir::PTXOperand::u32;
        mad.c.reg = registerMap["threadId"];

	    kernel->dfg()->insert(block, mad, 0);

        // mul offset, offset, sizeof(size_t) 
	    ir::PTXInstruction mul(ir::PTXInstruction::Mul);
        mul.type = ir::PTXOperand::u32;
        mul.modifier = ir::PTXInstruction::lo;
        mul.type = ir::PTXOperand::u32;
        mul.d.reg = index;
        mul.d.addressMode = ir::PTXOperand::Register;
	    mul.d.type = ir::PTXOperand::u32;
	    mul.a = mul.d;
        mul.b.type = ir::PTXOperand::u32;
        mul.b.addressMode = ir::PTXOperand::Immediate;
        mul.b.imm_int = sizeof(size_t);

        kernel->dfg()->insert(block, mul, 1);

	    DataflowGraph::RegisterId offset64 = kernel->dfg()->newRegister();
	    //cvt.u64 offset64, offset
	    ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
	    cvt.type = type;
	    cvt.d.addressMode = ir::PTXOperand::Register;
	    cvt.d.type = type;
	    cvt.d.reg = offset64;
        cvt.a.addressMode = ir::PTXOperand::Register;
        cvt.a.reg = index;
        cvt.a.type = ir::PTXOperand::u32;

        kernel->dfg()->insert(block, cvt, 2);

        // add counterPtr, counterPtr, offset
	    ir::PTXInstruction add(ir::PTXInstruction::Add);      
        add.type = type;
        add.d.type = type;
        add.d.addressMode = ir::PTXOperand::Register;
        add.d.reg = registerMap["counterPtrReg"];
        add.a.type = type;
        add.a.addressMode = ir::PTXOperand::Register;
        add.a.reg = registerMap["counterPtr"];
        add.b.type = type;
        add.b.addressMode = ir::PTXOperand::Register;
        add.b.reg = offset64;

        kernel->dfg()->insert(block, add, 3);

       /* Load, increment, and store back the result into the
            global counter */

        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.addressSpace = ir::PTXInstruction::Global; 
        ld.type = type;       
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.a.reg = registerMap["counterPtrReg"];
        ld.d.reg = registerId;
        ld.d.addressMode = ir::PTXOperand::Register;
	    ld.d.type = type;		
        
        add.addressSpace = ir::PTXInstruction::Global; 
        add.type = type;
        add.d = ld.d;
        add.a = ld.d;
        add.b.type = type;	
        add.b.addressMode = ir::PTXOperand::Immediate;
        add.b.imm_int = 1;
        

        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;       
        st.d.addressMode = ir::PTXOperand::Indirect;
	    st.d.reg = registerMap["counterPtrReg"];
	    st.d.type = type;
        st.a.addressMode = ir::PTXOperand::Register;
	    st.a.reg = registerId;
	    st.a.type = type;

        /* Need to insert in the beginning of the basic block.
            Since basic blocks usually end with branches, it
            wouldn't make sense to insert these instructions at the end. */
        
        kernel->dfg()->insert( block, ld, 4 );  
        kernel->dfg()->insert( block, add, 5 ); 
        kernel->dfg()->insert( block, st, 6 ); 
        
	}

}


#endif

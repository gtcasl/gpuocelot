/*! \file BasicBlockSMIDPass.cpp
	\date Sunday November 14, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockSMIDPass class
*/

#ifndef BASIC_BLOCK_SMID_PASS_CPP_INCLUDED
#define BASIC_BLOCK_SMID_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/BasicBlockSMIDPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis
{

    BasicBlockSMIDPass::BasicBlockSMIDPass() {

    }

    void BasicBlockSMIDPass::_runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId counterPtrRegId, DataflowGraph::RegisterId registerId, unsigned int offset)
	{

        /* Read the smid, and store the smid into the
            global counter */

        if(sizeof(size_t) == 8) {
            ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
            cvt.addressSpace = ir::PTXInstruction::Reg;
            cvt.type = ir::PTXOperand::u64;
            cvt.d.addressMode = ir::PTXOperand::Register;
		    cvt.d.type = ir::PTXOperand::u64;
		    cvt.d.reg = registerId;
            cvt.a.addressMode = ir::PTXOperand::Register;
            cvt.a = ir::PTXOperand(ir::PTXOperand::smId);
            cvt.a.type = ir::PTXOperand::u32;

            kernel->dfg()->insert( block, cvt, 0 ); 
        }
        else {
            ir::PTXInstruction mov(ir::PTXInstruction::Mov);
            mov.type = ir::PTXOperand::u32;
            mov.d.type = ir::PTXOperand::u32;
            mov.d.addressMode = ir::PTXOperand::Register;
            mov.d.reg = registerId;
            mov.a.addressMode = ir::PTXOperand::Register;
            mov.a = ir::PTXOperand(ir::PTXOperand::smId);
            mov.a.type = ir::PTXOperand::u32;

            kernel->dfg()->insert( block, mov, 0 );
        }
        

        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);       
        st.d.addressMode = ir::PTXOperand::Indirect;
        st.d.reg = counterPtrRegId;
        st.d.offset = offset;
        st.a.reg = registerId;
        st.a.addressMode = ir::PTXOperand::Register;
		st.a.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);	
        
        kernel->dfg()->insert( block, st, 1 ); 


	}

}


#endif

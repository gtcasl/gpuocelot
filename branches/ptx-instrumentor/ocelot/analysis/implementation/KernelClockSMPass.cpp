/*! \file KernelClockSMPass.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the KernelClockSMPass class
*/

#ifndef KERNEL_CLOCK_SM_PASS_CPP_INCLUDED
#define KERNEL_CLOCK_SM_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/KernelClockSMPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis
{

    KernelClockSMPass::KernelClockSMPass() {

    }

    void KernelClockSMPass::_runOnKernel( ir::PTXKernel* kernel)
	{

        DataflowGraph::iterator block = kernel->dfg()->begin();

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        // Convert special register tid.x to .u32 or .u64
        ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
        cvt.addressSpace = ir::PTXInstruction::Reg;
        cvt.type = type;

        DataflowGraph::RegisterId tidX = kernel->dfg()->newRegister();
        
        cvt.d.addressMode = ir::PTXOperand::Register;
		cvt.d.type = type;
		cvt.d.reg = tidX;
        cvt.a.addressMode = ir::PTXOperand::Register;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tidX);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 0);
        
        DataflowGraph::RegisterId clockStart = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId clockEnd = kernel->dfg()->newRegister();

        //setp.eq p, tidX, 0
        DataflowGraph::RegisterId pred = kernel->dfg()->newRegister();

        ir::PTXInstruction setp(ir::PTXInstruction::SetP);
        setp.type = type;
        setp.comparisonOperator = ir::PTXInstruction::Eq;
        setp.d.reg = pred;
        setp.d.type = ir::PTXOperand::pred;
        setp.d.addressMode = ir::PTXOperand::Register;
        setp.a = cvt.d;
        setp.b.addressMode = ir::PTXOperand::Immediate;
        setp.b.imm_int = 0;

        kernel->dfg()->insert(block, setp, 1);
  
        cvt.type = type;
        cvt.d.type = type;
        cvt.d.reg = clockStart;
        cvt.d.addressMode = ir::PTXOperand::Register;
        cvt.a = ir::PTXOperand(ir::PTXOperand::clock);
        cvt.a.type = ir::PTXOperand::u32;
        
        kernel->dfg()->insert(block, cvt, 2);

        ir::PTXInstruction bar(ir::PTXInstruction::Bar);
        bar.d.addressMode = ir::PTXOperand::Immediate;
        bar.d.imm_int = 0;
        
        kernel->dfg()->insert(block, bar, 3);

        cvt.d.reg = clockEnd;
    
        DataflowGraph::iterator lastBlock = --(kernel->dfg()->end());
        while(lastBlock->instructions().size() == 0) {
            lastBlock--;
        }

        kernel->dfg()->insert(lastBlock, bar, lastBlock->instructions().size() - 1);

        kernel->dfg()->insert(lastBlock, cvt, lastBlock->instructions().size() - 1);
        
        ir::PTXInstruction sub(ir::PTXInstruction::Sub);
        sub.type = type;
        sub.d.reg = clockStart;
        sub.d.type = type;
        sub.d.addressMode = ir::PTXOperand::Register;
        sub.a = cvt.d;
        sub.b = sub.d;

        kernel->dfg()->insert(lastBlock, sub, lastBlock->instructions().size() - 1);  

        DataflowGraph::RegisterId clockSMInfoAddress = kernel->dfg()->newRegister();        

        ir::PTXInstruction mov(ir::PTXInstruction::Mov);
        mov.type = type;
        mov.d.addressMode = ir::PTXOperand::Register;
        mov.d.reg = clockSMInfoAddress;
        mov.d.type = type;
        mov.a.identifier = kernelClockSMInfo();
        mov.a.type = type;
        mov.a.addressMode = ir::PTXOperand::Address;

        kernel->dfg()->insert(lastBlock, mov, lastBlock->instructions().size() - 1);

        DataflowGraph::RegisterId clockSMInfo = kernel->dfg()->newRegister();        

        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.addressSpace = ir::PTXInstruction::Global; 
        ld.type = type;
        ld.d.addressMode = ir::PTXOperand::Register;
        ld.d.type = type;
        ld.d.reg = clockSMInfo;
        ld.a = mov.d;

        kernel->dfg()->insert(lastBlock, ld, lastBlock->instructions().size() - 1);

        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;
        st.d = ld.d;
        st.a.type = type;
        st.a = sub.d;
        st.pg.condition = ir::PTXOperand::Pred;
        st.pg.reg = pred;  
        
        kernel->dfg()->insert(lastBlock, st, lastBlock->instructions().size() - 1);

        DataflowGraph::RegisterId smId = kernel->dfg()->newRegister();

        cvt.d.reg = smId;
        cvt.d.addressMode = ir::PTXOperand::Register;
        cvt.a = ir::PTXOperand(ir::PTXOperand::smId);
        cvt.a.type = ir::PTXOperand::u32;

        //kernel->dfg()->insert(lastBlock, cvt, lastBlock->instructions().size() - 1);

        st.d.offset = sizeof(size_t);
        st.a = cvt.d;
        
        //kernel->dfg()->insert(lastBlock, st, lastBlock->instructions().size() - 1);

	}

    void KernelClockSMPass::runOnModule( ir::Module& m )
	{
		report( "Adding global variable to " << m.path() );
     
		ir::PTXStatement clock_sm_info = ir::PTXStatement(ir::PTXStatement::Global);
        clock_sm_info.name = kernelClockSMInfo();
        clock_sm_info.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        for (ir::Module::KernelMap::const_iterator kernel = m.kernels().begin(); 
		    kernel != m.kernels().end(); ++kernel) {
            _runOnKernel(kernel->second);            
        }

        /* inserting the global info object into the module */
        m.insertGlobal(clock_sm_info);
	}

    void KernelClockSMPass::initialize( const ir::Module& m )
	{
    
	}

    void KernelClockSMPass::finalize( )
	{
	
	}

    std::string KernelClockSMPass::kernelClockSMInfo() const
	{
		return "__ocelot_kernel_clock_sm_info";
	}

}


#endif

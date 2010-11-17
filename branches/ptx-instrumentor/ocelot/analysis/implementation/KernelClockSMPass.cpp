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

        // Convert special registers to .u32 registers in order to use them in mad/mul/add instructions 
        ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
        cvt.addressSpace = ir::PTXInstruction::Reg;
        cvt.type = ir::PTXOperand::u32;

        DataflowGraph::RegisterId tidX = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId ntidX = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId tidY = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId ntidY = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId tidZ = kernel->dfg()->newRegister();
        
        cvt.d.addressMode = ir::PTXOperand::Register;
		cvt.d.type = ir::PTXOperand::u32;
		cvt.d.reg = tidX;
        cvt.a.addressMode = ir::PTXOperand::Register;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tidX);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 0);

        cvt.d.reg = ntidX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntidX);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 1);

        cvt.d.reg = tidY;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tidY);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 2);
          
        cvt.d.reg = ntidY;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntidY);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 3);

        cvt.d.reg = tidZ;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tidZ);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 4);
        
        // mad.lo threadId, tid.y, ntid.x, tid.x 
        ir::PTXInstruction mad(ir::PTXInstruction::Mad);
        mad.addressSpace = ir::PTXInstruction::Reg;
        mad.type = ir::PTXOperand::u32;
        mad.modifier = ir::PTXInstruction::lo;

        DataflowGraph::RegisterId threadId = kernel->dfg()->newRegister();
        mad.d.reg = threadId;        
        mad.d.addressMode = ir::PTXOperand::Register;
        mad.d.type = ir::PTXOperand::u32;
        
        mad.a.type = ir::PTXOperand::u32;
        mad.a.reg = tidY;
        mad.b.type = ir::PTXOperand::u32;
        mad.b.reg = ntidX;
        mad.c.type = ir::PTXOperand::u32;
        mad.c.reg = tidX;

        kernel->dfg()->insert(block, mad, 5);

        // mul.lo tmp1, ntid.x, ntid.y 
        ir::PTXInstruction mul(ir::PTXInstruction::Mul);
        mul.addressSpace = ir::PTXInstruction::Reg;
        mul.type = ir::PTXOperand::u32;
        mul.modifier = ir::PTXInstruction::lo;

        DataflowGraph::RegisterId tmp1 = kernel->dfg()->newRegister();
        mul.d.reg = tmp1;
        mul.d.addressMode = ir::PTXOperand::Register;
        mul.d.type = ir::PTXOperand::u32;
        
        mul.a.type = ir::PTXOperand::u32;
        mul.a.reg = ntidX;
        mul.b.type = ir::PTXOperand::u32;
        mul.b.reg = ntidY;

        kernel->dfg()->insert(block, mul, 6);

        // mul.lo tmp2, tmp1, tid.z 
        DataflowGraph::RegisterId tmp2 = kernel->dfg()->newRegister();
        mul.d.reg = tmp2;
        mul.a = ir::PTXOperand();
        mul.a.type = ir::PTXOperand::u32;
        mul.a.reg = tmp1;
        mul.b.reg = tidZ;

        kernel->dfg()->insert(block, mul, 7);

        // add threadId, threadId, tmp2 
        ir::PTXInstruction add(ir::PTXInstruction::Add);
        add.addressSpace = ir::PTXInstruction::Reg;
        add.type = ir::PTXOperand::u32;
        add.d.addressMode = ir::PTXOperand::Register;
        add.d.type = ir::PTXOperand::u32;
        add.d.reg = threadId;
        add.a.addressMode = ir::PTXOperand::Register;
        add.a.type = ir::PTXOperand::u32;
        add.a.reg = threadId;
        add.b.addressMode = ir::PTXOperand::Register;
        add.b.type = ir::PTXOperand::u32;
        add.b.reg = tmp2;

        kernel->dfg()->insert(block, add, 8);

        DataflowGraph::RegisterId clockStart = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId clockEnd = kernel->dfg()->newRegister();

        //setp.eq p, threadId, 0
        DataflowGraph::RegisterId pred = kernel->dfg()->newRegister();

        ir::PTXInstruction setp(ir::PTXInstruction::SetP);
        setp.type = ir::PTXOperand::u32;
        setp.comparisonOperator = ir::PTXInstruction::Eq;
        setp.d.reg = pred;
        setp.d.type = ir::PTXOperand::pred;
        setp.d.addressMode = ir::PTXOperand::Register;
        setp.a = add.d;
        setp.b.addressMode = ir::PTXOperand::Immediate;
        setp.b.imm_int = 0;

        kernel->dfg()->insert(block, setp, 9);
  
        cvt.type = type;
        cvt.d.type = type;
        cvt.d.reg = clockStart;
        cvt.d.addressMode = ir::PTXOperand::Register;
        cvt.a = ir::PTXOperand(ir::PTXOperand::clock);
        cvt.a.type = ir::PTXOperand::u32;
        cvt.pg.condition = ir::PTXOperand::Pred;
        cvt.pg.reg = pred;    

        kernel->dfg()->insert(block, cvt, 10);

        ir::PTXInstruction bar(ir::PTXInstruction::Bar);
        bar.d.addressMode = ir::PTXOperand::Immediate;
        bar.d.imm_int = 0;
        
        kernel->dfg()->insert(block, bar, 11);

        cvt.d.reg = clockEnd;
    
        DataflowGraph::iterator lastBlock = --(kernel->dfg()->end());
        while(lastBlock->instructions().size() == 0) {
            lastBlock--;
        }

        bar.d.imm_int = 1;
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

        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;
        st.d.addressMode = ir::PTXOperand::Address;
        st.d.identifier = kernelClockSMCounter();
        st.d.offset = 0;
        st.a.type = type;
        st.a = sub.d;
        
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
     
		ir::PTXStatement counter = ir::PTXStatement(ir::PTXStatement::Global);
        counter.name = kernelClockSMCounter();
        counter.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        for (ir::Module::KernelMap::const_iterator kernel = m.kernels().begin(); 
		    kernel != m.kernels().end(); ++kernel) {
            _runOnKernel(kernel->second);            
        }

        /* creating a global array counter, each index initialized to zero */
        counter.array.stride.push_back(2);
        counter.array.values = ir::PTXStatement::ArrayVector(2);

        /* inserting the global counter array into the module */
        m.insertGlobal(counter);
	}

    void KernelClockSMPass::initialize( const ir::Module& m )
	{
    
	}

    void KernelClockSMPass::finalize( )
	{
	
	}

    std::string KernelClockSMPass::kernelClockSMCounter() const
	{
		return "__ocelot_kernel_clock_sm_info";
	}

}


#endif

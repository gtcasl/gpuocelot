/*! \file ClockCycleCountPass.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the ClockCycleCountPass class
*/

#ifndef CLOCK_CYCLE_COUNT_PASS_CPP_INCLUDED
#define CLOCK_CYCLE_COUNT_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/ClockCycleCountPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

#include <climits>

namespace analysis
{

    ClockCycleCountPass::ClockCycleCountPass() {

    }

    void ClockCycleCountPass::_runOnKernel( ir::PTXKernel* kernel)
	{

        DataflowGraph::iterator block = kernel->dfg()->begin();

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

	    size_t loc = 0;

	    ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
	    ir::PTXInstruction mov(ir::PTXInstruction::Mov);

	    DataflowGraph::RegisterId tidX = kernel->dfg()->newRegister();

	    cvt.type = type;
        cvt.d.addressMode = ir::PTXOperand::Register;
        cvt.d.reg = tidX;
        cvt.d.type = type;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;


	    kernel->dfg()->insert(block, cvt, loc);
	    loc++;   
 
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

        kernel->dfg()->insert(block, setp, loc);
	    loc++;
  
	    if(type == ir::PTXOperand::u64){

		    mov.type = type;
		    mov.d.type = type;
		    mov.d.reg = clockStart;
		    mov.d.addressMode = ir::PTXOperand::Register;
		    mov.a = ir::PTXOperand(ir::PTXOperand::clock64);
		    mov.a.type = ir::PTXOperand::u64;

		    kernel->dfg()->insert(block, mov, loc);
		    loc++;

		    mov.d.reg = clockEnd;
            
	    }
	    else {
		    cvt.type = type;
		    cvt.d.type = type;
		    cvt.d.reg = clockStart;
		    cvt.d.addressMode = ir::PTXOperand::Register;
		    cvt.a = ir::PTXOperand(ir::PTXOperand::clock);
		    cvt.a.type = ir::PTXOperand::u32;
		
		    kernel->dfg()->insert(block, cvt, loc);
		    loc++;

		    cvt.d.reg = clockEnd;
	    }

        ir::PTXInstruction bar(ir::PTXInstruction::Bar);
        bar.d.addressMode = ir::PTXOperand::Immediate;
        bar.d.imm_int = 0;
        
        kernel->dfg()->insert(block, bar, loc);
	    loc++;
    
        DataflowGraph::iterator lastBlock = --(kernel->dfg()->end());
        while(lastBlock->instructions().size() == 0) {
            lastBlock--;
        }

        kernel->dfg()->insert(lastBlock, bar, lastBlock->instructions().size() - 1);

	    if(type == ir::PTXOperand::u64){
		    kernel->dfg()->insert(lastBlock, mov, lastBlock->instructions().size() - 1);
	    }
	    else {
            	kernel->dfg()->insert(lastBlock, cvt, lastBlock->instructions().size() - 1);
	    }

        ir::PTXInstruction sub(ir::PTXInstruction::Sub);
        sub.type = type;
        sub.d.reg = clockStart;
        sub.d.type = type;
        sub.d.addressMode = ir::PTXOperand::Register;
        sub.a.reg = clockEnd;
	    sub.a.type = type;
        sub.b = sub.d;

        kernel->dfg()->insert(lastBlock, sub, lastBlock->instructions().size() - 1);  

        DataflowGraph::RegisterId clockSMInfoAddress = kernel->dfg()->newRegister();        

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
        ld.a.addressMode = ir::PTXOperand::Indirect;

        kernel->dfg()->insert(lastBlock, ld, lastBlock->instructions().size() - 1);

        DataflowGraph::RegisterId smid = kernel->dfg()->newRegister();

        cvt.d.reg = smid;
        cvt.d.addressMode = ir::PTXOperand::Register;
        cvt.a = ir::PTXOperand(ir::PTXOperand::smId);
        cvt.a.type = ir::PTXOperand::u32;

        kernel->dfg()->insert(lastBlock, cvt, lastBlock->instructions().size() - 1);

        DataflowGraph::RegisterId ctaidX = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId nctaidX = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId ctaidY = kernel->dfg()->newRegister();

        cvt.d.reg = ctaidX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.vec = ir::PTXOperand::v1;        

        kernel->dfg()->insert(lastBlock, cvt, lastBlock->instructions().size() - 1);

        cvt.d.reg = ctaidY;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
	    cvt.a.vec = ir::PTXOperand::v1;        

        kernel->dfg()->insert(lastBlock, cvt, lastBlock->instructions().size() - 1);

        cvt.d.reg = nctaidX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.vec = ir::PTXOperand::v1;

        kernel->dfg()->insert(lastBlock, cvt, lastBlock->instructions().size() - 1);

        DataflowGraph::RegisterId ctaid = kernel->dfg()->newRegister();

        ir::PTXInstruction mad(ir::PTXInstruction::Mad);
        mad.type = type;
        mad.modifier = ir::PTXInstruction::lo;
        mad.d.addressMode = ir::PTXOperand::Register;
        mad.d.type = type;
        mad.d.reg = ctaid;
        mad.a.addressMode = ir::PTXOperand::Register;
        mad.a.type = type;
        mad.a.reg = ctaidY;
        mad.b.addressMode = ir::PTXOperand::Register;
        mad.b.type = type;
        mad.b.reg = nctaidX;
        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = type;
        mad.c.reg = ctaidX;

        kernel->dfg()->insert(lastBlock, mad, lastBlock->instructions().size() - 1);

        mad.d.reg = clockSMInfo;
        mad.a.reg = ctaid;
        mad.b.addressMode = ir::PTXOperand::Immediate;
        mad.b.imm_int = sizeof(size_t) * 2;
        mad.c = mad.d;

        kernel->dfg()->insert(lastBlock, mad, lastBlock->instructions().size() - 1);

        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;
        st.d = mad.d;
        st.d.addressMode = ir::PTXOperand::Indirect;
        st.d.offset = 0;
        st.a.type = type;
        st.a = sub.d;
        st.pg.condition = ir::PTXOperand::Pred;
        st.pg.reg = pred;  
        
        kernel->dfg()->insert(lastBlock, st, lastBlock->instructions().size() - 1);

        st.d.offset = sizeof(size_t);
        st.a.reg = smid;
        
        kernel->dfg()->insert(lastBlock, st, lastBlock->instructions().size() - 1);

	}

    void ClockCycleCountPass::runOnModule( ir::Module& m )
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

    void ClockCycleCountPass::initialize( const ir::Module& m )
	{
    
	}

    void ClockCycleCountPass::finalize( )
	{
	
	}

    std::string ClockCycleCountPass::kernelClockSMInfo() const
	{
		return "__ocelot_kernel_clock_sm_info";
	}

}


#endif

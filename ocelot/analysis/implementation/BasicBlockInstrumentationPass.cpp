/*! \file BasicBlockInstrumentationPass.cpp
	\date Sunday November 14, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockInstrumentationPass class
*/

#ifndef BASIC_BLOCK_INSTRUMENTATION_PASS_CPP_INCLUDED
#define BASIC_BLOCK_INSTRUMENTATION_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/BasicBlockInstrumentationPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{
    std::map<std::string, DataflowGraph::RegisterId> BasicBlockInstrumentationPass::_runOnEntryBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block) {

        /* The entry block adds the insrumented ptx. In order to maintain a counter-per-thread for
            each basic block, I need to calculate the thread counter offset. I do this using the following:
            
            counter = (ctaid.x + ctaid.y * nctaid.x) * ntid.x * ntid.y * ntid.z + tid
            tid = tid.x + tid.y * ntid.x + tid.z * ntid.x * ntid.y

            To perform the above calculations, I came up with the following ptx:
            mad.lo threadId, tid.y, ntid.x, tid.x
            mul.lo tmp1, ntid.x, ntid.y
            mul.lo tmp2, tmp1, tid.z
            add threadId, threadId, tmp2
            mad.lo tmp2, ctaid.y, nctaid.x, ctaid.x
            mul.lo tmp1, tmp1, ntid.z
            mad.lo threadId, tmp1, tmp2, threadId
        
        */

        DataflowGraph::RegisterId counterPtr = kernel->dfg()->newRegister();
 
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
       
        // Convert special registers to .u32 registers in order to use them in mad/mul/add instructions 
        ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
        cvt.type = type;

        DataflowGraph::RegisterId tidX = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId ntidX = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId tidY = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId ntidY = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId tidZ = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId ntidZ = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId ctaIdX = kernel->dfg()->newRegister();         
        DataflowGraph::RegisterId nctaIdX = kernel->dfg()->newRegister();
        DataflowGraph::RegisterId ctaIdY = kernel->dfg()->newRegister();

        cvt.d.addressMode = ir::PTXOperand::Register;
	    cvt.d.type = type;
	    cvt.d.reg = tidX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
    
        kernel->dfg()->insert(block, cvt, 0);

        cvt.d.reg = ntidX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, 1);

        cvt.d.reg = tidY;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iy, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, 2);
          
        cvt.d.reg = ntidY;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iy, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, 3);

        cvt.d.reg = tidZ;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iz, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, 4);
          
        cvt.d.reg = ntidZ;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iz, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, 5);

        cvt.d.reg = ctaIdX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, 6);
          
        cvt.d.reg = nctaIdX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, 7);

        cvt.d.reg = ctaIdY;
        cvt.d.reg = nctaIdX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, 8);

        DataflowGraph::RegisterId ntid = kernel->dfg()->newRegister();

        //mul ntid, ntidx, ntidy
        //mul ntid, tid, ntidz
        ir::PTXInstruction mul(ir::PTXInstruction::Mul);
        mul.type = type;
        mul.modifier = ir::PTXInstruction::lo;

        mul.d.reg = ntid;
        mul.d.addressMode = ir::PTXOperand::Register;
        mul.d.type = type;
        
        mul.a.type = type;
        mul.a.reg = ntidX;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.b.type = type;
        mul.b.addressMode = ir::PTXOperand::Register;
        mul.b.reg = ntidY;

        kernel->dfg()->insert(block, mul, 9);

        mul.a.reg = ntid;
        mul.b.reg = ntidZ;

        kernel->dfg()->insert(block, mul, 10);

        // mad.lo threadId, tid.y, ntid.x, tid.x 
        ir::PTXInstruction mad(ir::PTXInstruction::Mad);
        mad.type = type;
        mad.modifier = ir::PTXInstruction::lo;

        DataflowGraph::RegisterId threadId = kernel->dfg()->newRegister();
        mad.d.reg = threadId;        
        mad.d.addressMode = ir::PTXOperand::Register;
        mad.d.type = type;
        
        mad.a.addressMode = ir::PTXOperand::Register;
        mad.a.type = type;
        mad.a.reg = tidY;

        mad.b.addressMode = ir::PTXOperand::Register;
        mad.b.type = type;
        mad.b.reg = ntidX;

        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = type;
        mad.c.reg = tidX;

        kernel->dfg()->insert(block, mad, 11);

        // mul.lo tmp1, ntid.x, ntid.y 
        mul.type = type;
        mul.modifier = ir::PTXInstruction::lo;

        DataflowGraph::RegisterId tmp1 = kernel->dfg()->newRegister();
        mul.d.reg = tmp1;
        mul.d.addressMode = ir::PTXOperand::Register;
        mul.d.type = type;
        
        mul.a.type = type;
        mul.a.reg = ntidX;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.b.type = type;
        mul.b.addressMode = ir::PTXOperand::Register;
        mul.b.reg = ntidY;

        kernel->dfg()->insert(block, mul, 12);

        // mul.lo tmp2, tmp1, tid.z 
        DataflowGraph::RegisterId tmp2 = kernel->dfg()->newRegister();
        mul.d.reg = tmp2;
        mul.a = ir::PTXOperand();
        mul.a.type = type;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.a.reg = tmp1;
        mul.b.reg = tidZ;

        kernel->dfg()->insert(block, mul, 13);

        // add threadId, threadId, tmp2 
        ir::PTXInstruction add(ir::PTXInstruction::Add);
        add.type = type;
        add.d.addressMode = ir::PTXOperand::Register;
        add.d.type = type;
        add.d.reg = threadId;
        add.a.addressMode = ir::PTXOperand::Register;
        add.a.type = type;
        add.a.reg = threadId;
        add.b.addressMode = ir::PTXOperand::Register;
        add.b.type = type;
        add.b.reg = tmp2;

        kernel->dfg()->insert(block, add, 14);

        // mad.lo tmp2, ctaid.y, nctaid.x, ctaid.x 
        mad.d.reg = tmp2;
        mad.a.reg = ctaIdY;
        mad.b.reg = nctaIdX;
        mad.c.reg = ctaIdX;

        kernel->dfg()->insert(block, mad, 15);
       
        // mul.lo tmp1, tmp1, ntid.z 
        mul.d.reg = tmp1;
        mul.a = ir::PTXOperand();
        mul.a.type = type;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.a.reg = tmp1;
        mul.b.reg = ntidZ;

        kernel->dfg()->insert(block, mul, 16); 

        // mad.lo threadId, tmp1, tmp2, threadId 
        mad.d.reg = threadId;
        mad.a = ir::PTXOperand();
        mad.a.addressMode = ir::PTXOperand::Register;
        mad.a.type = type;
        mad.a.reg = tmp1;
        mad.b = ir::PTXOperand();
        mad.b.addressMode = ir::PTXOperand::Register;
        mad.b.type = type;
        mad.b.reg = tmp2;
        mad.c = ir::PTXOperand();
        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = type;
        mad.c.reg = threadId;

        kernel->dfg()->insert(block, mad, 17);

        DataflowGraph::RegisterId counterPtrReg = kernel->dfg()->newRegister();    

	    std::map<std::string, DataflowGraph::RegisterId> registerMap;
	    registerMap["counterPtr"] = counterPtr;	
	    registerMap["counterPtrReg"] = counterPtrReg;
	    registerMap["threadId"] = threadId;
        registerMap["ntid"] = ntid;

        return registerMap;

    }
  
}

#endif

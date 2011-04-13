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
    size_t BasicBlockInstrumentationPass::calculateThreadId( ir::PTXKernel* kernel, DataflowGraph::iterator block, size_t location) {

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

            mov counterBase, basicBlockCounterBase
            ld counterPtr, [counterBase]
        
        */

        size_t initial = location;

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
    
        kernel->dfg()->insert(block, cvt, location++);

        cvt.d.reg = ntidX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, location++);

        cvt.d.reg = tidY;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iy, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, location++);
          
        cvt.d.reg = ntidY;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iy, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, location++);

        cvt.d.reg = tidZ;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iz, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, location++);
          
        cvt.d.reg = ntidZ;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iz, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, location++);

        cvt.d.reg = ctaIdX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, location++);
          
        cvt.d.reg = nctaIdX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, location++);

        cvt.d.reg = ctaIdY;
        cvt.d.reg = nctaIdX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
	    cvt.a.addressMode = ir::PTXOperand::Special;
	    cvt.a.vec = ir::PTXOperand::v1;
        kernel->dfg()->insert(block, cvt, location++);

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

        kernel->dfg()->insert(block, mul, location++);

        mul.a.reg = ntid;
        mul.b.reg = ntidZ;

        kernel->dfg()->insert(block, mul, location++);

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

        kernel->dfg()->insert(block, mad, location++);

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

        kernel->dfg()->insert(block, mul, location++);

        // mul.lo tmp2, tmp1, tid.z 
        DataflowGraph::RegisterId tmp2 = kernel->dfg()->newRegister();
        mul.d.reg = tmp2;
        mul.a = ir::PTXOperand();
        mul.a.type = type;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.a.reg = tmp1;
        mul.b.reg = tidZ;

        kernel->dfg()->insert(block, mul, location++);

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

        kernel->dfg()->insert(block, add, location++);

        // mad.lo tmp2, ctaid.y, nctaid.x, ctaid.x 
        mad.d.reg = tmp2;
        mad.a.reg = ctaIdY;
        mad.b.reg = nctaIdX;
        mad.c.reg = ctaIdX;

        kernel->dfg()->insert(block, mad, location++);
       
        // mul.lo tmp1, tmp1, ntid.z 
        mul.d.reg = tmp1;
        mul.a = ir::PTXOperand();
        mul.a.type = type;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.a.reg = tmp1;
        mul.b.reg = ntidZ;

        kernel->dfg()->insert(block, mul, location++); 

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

        kernel->dfg()->insert(block, mad, location++);

        // mov counterBase, basicBlockCounterBase         
        DataflowGraph::RegisterId counterBase = kernel->dfg()->newRegister();
        ir::PTXInstruction mov(ir::PTXInstruction::Mov);
        mov.type = type;
        mov.d.type = type;
        mov.d.addressMode = ir::PTXOperand::Register;
        mov.d.reg = counterBase;
        mov.a.addressMode = ir::PTXOperand::Address;
        mov.a.identifier = basicBlockCounterBase();

        kernel->dfg()->insert(block, mov, location++); 

        // ld counterPtr, [counterBase] 
        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.type = type;
        ld.addressSpace = ir::PTXInstruction::Global;
        ld.a = mov.d;
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.d.addressMode = ir::PTXOperand::Register;
        ld.d.type = type;
        ld.d.reg = counterPtr;

        kernel->dfg()->insert(block, ld, location++); 

        DataflowGraph::RegisterId counterPtrReg = kernel->dfg()->newRegister();    

        registerMap["counterPtr"] = counterPtr;	
        registerMap["counterPtrReg"] = counterPtrReg;
        registerMap["threadId"] = threadId;
        registerMap["ntid"] = ntid;

        return location - initial;

    }

    size_t BasicBlockInstrumentationPass::calculateBasicBlockCounterOffset( ir::PTXKernel *kernel, DataflowGraph::iterator block, size_t basicBlockId, size_t location ) {
    
         /*

        The remaining instructions determine the thread counter offset in global memory:
            
            offset = (threadId + ntid * basic-block-id) * (entries * sizeof(size_t))
            mad offset, ntid, basic-block-id, threadId
            mul offset, offset, entries * sizeof(size_t)	

            add counterPtr, counterPtr, offset 

        */

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        size_t initial = location;

        DataflowGraph::RegisterId offset = kernel->dfg()->newRegister();

        ir::PTXInstruction mad(ir::PTXInstruction::Mad);
        mad.type = type;
        mad.modifier = ir::PTXInstruction::lo;

        mad.d.reg = offset;        
        mad.d.addressMode = ir::PTXOperand::Register;
        mad.d.type = type;
        
        mad.a.addressMode = ir::PTXOperand::Register;
        mad.a.type = type;
        mad.a.reg = registerMap["ntid"];

        mad.b.addressMode = ir::PTXOperand::Immediate;
        mad.b.type = type;
        mad.b.imm_int = basicBlockId;

        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = type;
        mad.c.reg = registerMap["threadId"];

	    kernel->dfg()->insert(block, mad, location++);


        // mul offset, offset, sizeof(size_t) 
	    ir::PTXInstruction mul(ir::PTXInstruction::Mul);
        mul.type = type;
        mul.modifier = ir::PTXInstruction::lo;
        mul.type = type;
        mul.d.reg = offset;
        mul.d.addressMode = ir::PTXOperand::Register;
	    mul.d.type = type;
	    mul.a = mul.d;
        mul.b.type = type;
        mul.b.addressMode = ir::PTXOperand::Immediate;
        mul.b.imm_int = entries * sizeof(size_t);

        kernel->dfg()->insert(block, mul, location++);
        
        // add counterPtrReg, counterPtr, offset      
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
        add.b.reg = offset;

        kernel->dfg()->insert(block, add, location++);

        return location - initial;
        
    }

    std::string BasicBlockInstrumentationPass::basicBlockCounterBase() const
	{
		return "__ocelot_basic_block_counter_base";
	}

    void BasicBlockInstrumentationPass::initialize( const ir::Module& m )
	{
    
	}

    void BasicBlockInstrumentationPass::finalize( )
	{
	
	}

    void BasicBlockInstrumentationPass::runOnModule( ir::Module& m ) 
    {

    }
  
}

#endif

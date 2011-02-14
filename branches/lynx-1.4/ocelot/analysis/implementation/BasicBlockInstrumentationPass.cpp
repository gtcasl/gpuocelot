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
    std::map<std::string, DataflowGraph::RegisterId> BasicBlockInstrumentationPass::_runOnEntryBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId) {

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

            The remaining instructions determine the thread counter offset in global memory:
            
            mul.wide offset, threadId, sizeof(size_t) * basic-block-count 
            mov counterBase, basicBlockCounterBase
            ld counterPtr, [counterBase]
            add counterPtr, counterPtr, offset 
        
        */

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        DataflowGraph::RegisterId counterPtr = kernel->dfg()->newRegister();
        
        // Convert special registers to .u32 registers in order to use them in mad/mul/add instructions 
        ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
        cvt.addressSpace = ir::PTXInstruction::Reg;
        cvt.type = ir::PTXOperand::u32;

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
          
        cvt.d.reg = ntidZ;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ntidZ);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 5);

        cvt.d.reg = ctaIdX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ctaIdX);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 6);
          
        cvt.d.reg = nctaIdX;
        cvt.a = ir::PTXOperand(ir::PTXOperand::nctaIdX);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 7);

        cvt.d.reg = ctaIdY;
        cvt.a = ir::PTXOperand(ir::PTXOperand::ctaIdY);
        cvt.a.type = ir::PTXOperand::u16;
        kernel->dfg()->insert(block, cvt, 8);

	DataflowGraph::RegisterId ntid = kernel->dfg()->newRegister();

	//mul ntid, ntidx, ntidy
	//mul ntid, tid, ntidz
	ir::PTXInstruction mul(ir::PTXInstruction::Mul);
	mul.addressSpace = ir::PTXInstruction::Reg;
        mul.type = ir::PTXOperand::u32;
        mul.modifier = ir::PTXInstruction::lo;

        mul.d.reg = ntid;
        mul.d.addressMode = ir::PTXOperand::Register;
        mul.d.type = ir::PTXOperand::u32;
        
        mul.a.type = ir::PTXOperand::u32;
        mul.a.reg = ntidX;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.b.type = ir::PTXOperand::u32;
        mul.b.addressMode = ir::PTXOperand::Register;
        mul.b.reg = ntidY;

	kernel->dfg()->insert(block, mul, 9);
	
	mul.a.reg = ntid;
	mul.b.reg = ntidZ;

	kernel->dfg()->insert(block, mul, 10);

        // mad.lo threadId, tid.y, ntid.x, tid.x 
        ir::PTXInstruction mad(ir::PTXInstruction::Mad);
        mad.addressSpace = ir::PTXInstruction::Reg;
        mad.type = ir::PTXOperand::u32;
        mad.modifier = ir::PTXInstruction::lo;

        DataflowGraph::RegisterId threadId = kernel->dfg()->newRegister();
        mad.d.reg = threadId;        
        mad.d.addressMode = ir::PTXOperand::Register;
        mad.d.type = ir::PTXOperand::u32;
        
        mad.a.addressMode = ir::PTXOperand::Register;
        mad.a.type = ir::PTXOperand::u32;
        mad.a.reg = tidY;

        mad.b.addressMode = ir::PTXOperand::Register;
        mad.b.type = ir::PTXOperand::u32;
        mad.b.reg = ntidX;

        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = ir::PTXOperand::u32;
        mad.c.reg = tidX;

        kernel->dfg()->insert(block, mad, 11);

        // mul.lo tmp1, ntid.x, ntid.y 
        mul.addressSpace = ir::PTXInstruction::Reg;
        mul.type = ir::PTXOperand::u32;
        mul.modifier = ir::PTXInstruction::lo;

        DataflowGraph::RegisterId tmp1 = kernel->dfg()->newRegister();
        mul.d.reg = tmp1;
        mul.d.addressMode = ir::PTXOperand::Register;
        mul.d.type = ir::PTXOperand::u32;
        
        mul.a.type = ir::PTXOperand::u32;
        mul.a.reg = ntidX;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.b.type = ir::PTXOperand::u32;
        mul.b.addressMode = ir::PTXOperand::Register;
        mul.b.reg = ntidY;

        kernel->dfg()->insert(block, mul, 12);

        // mul.lo tmp2, tmp1, tid.z 
        DataflowGraph::RegisterId tmp2 = kernel->dfg()->newRegister();
        mul.d.reg = tmp2;
        mul.a = ir::PTXOperand();
        mul.a.type = ir::PTXOperand::u32;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.a.reg = tmp1;
        mul.b.reg = tidZ;

        kernel->dfg()->insert(block, mul, 13);

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
        mul.a.type = ir::PTXOperand::u32;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.a.reg = tmp1;
        mul.b.reg = ntidZ;

        kernel->dfg()->insert(block, mul, 16); 

        // mad.lo threadId, tmp1, tmp2, threadId 
        mad.d.reg = threadId;
        mad.a = ir::PTXOperand();
        mad.a.addressMode = ir::PTXOperand::Register;
        mad.a.type = ir::PTXOperand::u16;
        mad.a.reg = tmp1;
        mad.b = ir::PTXOperand();
        mad.b.addressMode = ir::PTXOperand::Register;
        mad.b.type = ir::PTXOperand::u16;
        mad.b.reg = tmp2;
        mad.c = ir::PTXOperand();
        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = ir::PTXOperand::u16;
        mad.c.reg = threadId;

        kernel->dfg()->insert(block, mad, 17);

        // mov counterBase, basicBlockCounterBase         
        DataflowGraph::RegisterId counterBase = kernel->dfg()->newRegister();
        ir::PTXInstruction mov(ir::PTXInstruction::Mov);
        mov.type = type;
        mov.d.type = type;
        mov.d.addressMode = ir::PTXOperand::Register;
        mov.d.reg = counterBase;
        mov.a.addressMode = ir::PTXOperand::Address;
        mov.a.identifier = basicBlockCounterBase();

        kernel->dfg()->insert(block, mov, 18); 

        // ld counterPtr, [counterBase] 
        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.type = type;
        ld.addressSpace = ir::PTXInstruction::Global;
        ld.a = mov.d;
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.d.addressMode = ir::PTXOperand::Register;
        ld.d.type = type;
        ld.d.reg = counterPtr;
    
        kernel->dfg()->insert(block, ld, 19); 
	
	//offset = (threadId + ntid * basic-block-count) * sizeof(size_t)
	//mad offset, ntid, basic-block-count, threadId
	//mul offset, offset, sizeof(size_t)	

	DataflowGraph::RegisterId offset = kernel->dfg()->newRegister();
        mad.addressSpace = ir::PTXInstruction::Reg;
        mad.type = ir::PTXOperand::u32;
        mad.modifier = ir::PTXInstruction::lo;

        mad.d.reg = offset;        
        mad.d.addressMode = ir::PTXOperand::Register;
        mad.d.type = ir::PTXOperand::u32;
        
        mad.a.addressMode = ir::PTXOperand::Register;
        mad.a.type = ir::PTXOperand::u32;
        mad.a.reg = ntid;

        mad.b.addressMode = ir::PTXOperand::Immediate;
        mad.b.type = ir::PTXOperand::u32;
        mad.b.imm_int = 0;


        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = ir::PTXOperand::u32;
        mad.c.reg = threadId;

	kernel->dfg()->insert(block, mad, 20);

        // mul offset, offset, sizeof(size_t) 
        mul.type = ir::PTXOperand::u32;
        mul.d.reg = offset;
        mul.d.addressMode = ir::PTXOperand::Register;
	mul.d.type = ir::PTXOperand::u32;
	mul.a = mul.d;
        mul.b.type = ir::PTXOperand::u32;
        mul.b.addressMode = ir::PTXOperand::Immediate;
        mul.b.imm_int = sizeof(size_t);

        kernel->dfg()->insert(block, mul, 21);

	DataflowGraph::RegisterId offset64 = kernel->dfg()->newRegister();
	//cvt.u64 offset64, offset
	cvt.type = type;
	cvt.d.addressMode = ir::PTXOperand::Register;
	cvt.d.type = type;
	cvt.d.reg = offset64;
        cvt.a.addressMode = ir::PTXOperand::Register;
        cvt.a.reg = offset;
        cvt.a.type = ir::PTXOperand::u32;

        kernel->dfg()->insert(block, cvt, 22);

        // add counterPtrReg, counterPtr, offset     
	DataflowGraph::RegisterId counterPtrReg = kernel->dfg()->newRegister();    
        add.type = type;
        add.d.type = type;
        add.d.reg = counterPtrReg;
        add.a.type = type;
        add.a.reg = counterPtr;
        add.b.type = type;
        add.b.reg = offset64;

        kernel->dfg()->insert(block, add, 23);
        
        /* Load, increment, and store back the result into the
            global counter */

        ld.addressSpace = ir::PTXInstruction::Global; 
        ld.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);       
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.a.reg = counterPtrReg;
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
        st.d = ld.a;
        st.a = ld.d;

        kernel->dfg()->insert( block, ld, 24 );  
        kernel->dfg()->insert( block, add, 25 ); 
        kernel->dfg()->insert( block, st, 26 ); 
     

	std::map<std::string, DataflowGraph::RegisterId> registerMap;
	registerMap["counterPtr"] = counterPtr;	
	registerMap["counterPtrReg"] = counterPtrReg;
	registerMap["threadId"] = threadId;
	registerMap["ntid"] = ntid;
        return registerMap;

    }

	void BasicBlockInstrumentationPass::runOnModule( ir::Module& m )
	{
		report( "Adding global variable to " << m.path() );
     
		ir::PTXStatement counter = ir::PTXStatement(ir::PTXStatement::Global);
        counter.name = basicBlockCounterBase();
        counter.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);


        /* Since the global counter array needs to be declared per module, we need to
            traverse through all the kernels in this module and get the total number of
            basic blocks */
        for (ir::Module::KernelMap::const_iterator kernel = m.kernels().begin(); 
		    kernel != m.kernels().end(); ++kernel) {
            /* creating a new register per kernel for maintaining the count information -- 
                the same register can be reused so need to only create one per kernel and 
                pass its id along. */
            DataflowGraph::RegisterId registerId = (kernel->second)->dfg()->newRegister();  

            /* ensure that there is at least one basic block -- otherwise, skip this kernel */
            if((kernel->second)->dfg()->empty())
                continue;
            
            DataflowGraph::iterator entry = (kernel->second)->dfg()->begin();
            ++entry;
            /* instrumenting ptx at the beginning of the first basic block. */
            std::map<std::string, DataflowGraph::RegisterId> registerMap = _runOnEntryBlock((kernel->second), entry, registerId);
   
            unsigned int offset = 8;
            for( analysis::DataflowGraph::iterator block = ++(entry); 
			    block != (kernel->second)->dfg()->end(); ++block )
		        {
                   if(!block->instructions().empty()){
                        _runOnBlock( (kernel->second), block, registerMap, registerId, offset);
                        /* incrementing offset based on size_t */
                        offset = offset + sizeof(size_t);                 
                    } 
		        }
	    }

        /* inserting the global counter array into the module */
        m.insertGlobal(counter);
	}

    void BasicBlockInstrumentationPass::initialize( const ir::Module& m )
	{
    
	}

    void BasicBlockInstrumentationPass::finalize( )
	{
	
	}

    std::string BasicBlockInstrumentationPass::basicBlockCounterBase() const
	{
		return "__ocelot_basic_block_counter_base";
	}
  
}

#endif

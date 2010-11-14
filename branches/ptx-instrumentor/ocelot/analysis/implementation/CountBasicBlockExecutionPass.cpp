/*! \file CountBasicBlockExecutionPass.cpp
	\date Wednesday October 6, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the CountBasicBlockExecutionPass class
*/

#ifndef COUNT_BASIC_BLOCK_EXECUTION_PASS_CPP_INCLUDED
#define COUNT_BASIC_BLOCK_EXECUTION_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/CountBasicBlockExecutionPass.h>
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
    CountBasicBlockExecutionPass::CountBasicBlockExecutionPass()
		: ModulePass( DataflowGraphAnalysis, "CountBasicBlockExecutionPass" )
	{

	}

    DataflowGraph::RegisterId CountBasicBlockExecutionPass::_runOnEntryBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block) {

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

        /* Convert special registers to .u32 registers in order to use them in mad/mul/add instructions */
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


        /* mad.lo threadId, tid.y, ntid.x, tid.x */
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

        kernel->dfg()->insert(block, mad, 9);

        /* mul.lo tmp1, ntid.x, ntid.y */
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

        kernel->dfg()->insert(block, mul, 10);

        /* mul.lo tmp2, tmp1, tid.z */
        DataflowGraph::RegisterId tmp2 = kernel->dfg()->newRegister();
        mul.d.reg = tmp2;
        mul.a = ir::PTXOperand();
        mul.a.type = ir::PTXOperand::u32;
        mul.a.reg = tmp1;
        mul.b.reg = tidZ;

        kernel->dfg()->insert(block, mul, 11);

        /* add threadId, threadId, tmp2 */
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

        kernel->dfg()->insert(block, add, 12);

        /* mad.lo tmp2, ctaid.y, nctaid.x, ctaid.x */
        mad.d.reg = tmp2;
        mad.a.reg = ctaIdY;
        mad.b.reg = nctaIdX;
        mad.c.reg = ctaIdX;
    
        kernel->dfg()->insert(block, mad, 13);
       
        /* mul.lo tmp1, tmp1, ntid.z */
        mul.d.reg = tmp1;
        mul.a = ir::PTXOperand();
        mul.a.type = ir::PTXOperand::u32;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.a.reg = tmp1;
        mul.b.reg = ntidZ;

        kernel->dfg()->insert(block, mul, 14); 

        /* mad.lo threadId, tmp1, tmp2, threadId */
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

        kernel->dfg()->insert(block, mad, 15);

        /* mul offset, threadId, basic-block-count * sizeof(size_t) */
        mul.type = ir::PTXOperand::u32;
        if(type == ir::PTXOperand::u64) {
            mul.modifier = ir::PTXInstruction::wide;
        }
        DataflowGraph::RegisterId offset = kernel->dfg()->newRegister();
        mul.d.reg = offset;
        mul.d.addressMode = ir::PTXOperand::Register;
        mul.d.type = type;
        
        mul.a.type = ir::PTXOperand::u32;
        mul.a.reg = threadId;
        mul.b.type = ir::PTXOperand::u32;
        mul.b.addressMode = ir::PTXOperand::Immediate;
        mul.b.imm_int = kernel->dfg()->size() * sizeof(size_t);

        kernel->dfg()->insert(block, mul, 16);

        /* mov counterBase, basicBlockCounterBase */        
        DataflowGraph::RegisterId counterBase = kernel->dfg()->newRegister();
        ir::PTXInstruction mov(ir::PTXInstruction::Mov);
        mov.type = type;
        mov.d.type = type;
        mov.d.addressMode = ir::PTXOperand::Register;
        mov.d.reg = counterBase;
        mov.a.addressMode = ir::PTXOperand::Address;
        mov.a.identifier = basicBlockCounterBase();

        kernel->dfg()->insert(block, mov, 17); 

        /* ld counterPtr, [counterBase] */
        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.type = type;
        ld.addressSpace = ir::PTXInstruction::Global;
        ld.a = mov.d;
        ld.d.addressMode = ir::PTXOperand::Register;
        ld.d.type = type;
        ld.d.reg = counterPtr;
    
        kernel->dfg()->insert(block, ld, 18); 

        /* add counterPtr, counterPtr, offset */
        add.type = type;
        add.d.type = type;
        add.d.reg = counterPtr;
        add.a.type = type;
        add.a.reg = counterPtr;
        add.b.type = type;
        add.b.reg = offset;

        kernel->dfg()->insert(block, add, 19);

        return counterPtr;

    }

    void CountBasicBlockExecutionPass::_runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId counterPtrRegId, DataflowGraph::RegisterId registerId, unsigned int offset)
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
	
	void CountBasicBlockExecutionPass::runOnModule( ir::Module& m )
	{
		report( "Adding global variable to " << m.path() );
     
		ir::PTXStatement counter = ir::PTXStatement(ir::PTXStatement::Global);
        counter.name = basicBlockCounterBase();
        counter.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);


        /* Since the global counter array needs to be declared per module, we need to
            traverse through all the kernels in this module and get the total number of
            basic blocks */
        unsigned int basicBlockCount = 0;
        for (ir::Module::KernelMap::const_iterator kernel = m.kernels().begin(); 
		    kernel != m.kernels().end(); ++kernel) {
            basicBlockCount += (kernel->second)->cfg()->size();
            /* creating a new register per kernel for maintaining the count information -- 
                the same register can be reused so need to only create one per kernel and 
                pass its id along. */
            DataflowGraph::RegisterId registerId = (kernel->second)->dfg()->newRegister();  

            /* ensure that there is at least one basic block -- otherwise, skip this kernel */
            if((kernel->second)->dfg()->empty())
                continue;
            
            /* instrumenting ptx at the beginning of the first basic block. The first block only
                adds the instrumentation ptx, so we do not increment a counter for it */
            DataflowGraph::RegisterId counterPtrRegId = _runOnEntryBlock((kernel->second), (kernel->second)->dfg()->begin());

            /* need to keep track of the memory offset for the global counter array -- starting at
                zero since we do not have to keep a counter for the first block */          
            unsigned int offset = 0;
            for( analysis::DataflowGraph::iterator block = ++((kernel->second)->dfg()->begin()); 
			    block != (kernel->second)->dfg()->end(); ++block )
		        {
                   _runOnBlock( (kernel->second), block, counterPtrRegId, registerId, offset);
                    /* incrementing offset based on size_t */
                    offset = offset + sizeof(size_t);                  
		        }
	    }

        /* inserting the global counter array into the module */
        m.insertGlobal(counter);
	}

    void CountBasicBlockExecutionPass::initialize( const ir::Module& m )
	{
    
	}

    void CountBasicBlockExecutionPass::finalize( )
	{
	
	}

    std::string CountBasicBlockExecutionPass::basicBlockCounterBase() const
	{
		return "__ocelot_basic_block_counter_base";
	}
  
}

#endif

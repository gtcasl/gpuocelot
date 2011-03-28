/*! \file BasicBlockExecutionCountPass.cpp
	\date Sunday November 14, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockExecutionCountPass class
*/

#ifndef BASIC_BLOCK_EXECUTION_COUNT_PASS_CPP_INCLUDED
#define BASIC_BLOCK_EXECUTION_COUNT_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/BasicBlockExecutionCountPass.h>
#include <ocelot/analysis/interface/BasicBlockInstrumentationPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis
{

    BasicBlockExecutionCountPass::BasicBlockExecutionCountPass() {

    }

    void BasicBlockExecutionCountPass::_runOnEntryBlock( ir::PTXKernel *kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, std::map<std::string, DataflowGraph::RegisterId> registerMap) {
    
         /*

        The remaining instructions determine the thread counter offset in global memory:

            mov counterBase, basicBlockCounterBase
            ld counterPtr, [counterBase]
            
            offset = (threadId + ntid * basic-block-count) * sizeof(size_t)
            mad offset, ntid, basic-block-count, threadId
            mul offset, offset, sizeof(size_t)	

            add counterPtr, counterPtr, offset 

        */

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

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
        ld.d.reg = registerMap["counterPtr"];

        kernel->dfg()->insert(block, ld, 19); 

        //offset = (threadId + ntid * basic-block-count) * sizeof(size_t)
        //mad offset, ntid, basic-block-count, threadId
        //mul offset, offset, sizeof(size_t)	

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
        mad.b.imm_int = 0;


        mad.c.addressMode = ir::PTXOperand::Register;
        mad.c.type = type;
        mad.c.reg = registerMap["threadId"];

        kernel->dfg()->insert(block, mad, 20);

        // mul offset, offset, sizeof(size_t) 
    
        ir::PTXInstruction mul(ir::PTXInstruction::Mul);
        mul.type = type;
        mul.d.reg = offset;
        mul.d.addressMode = ir::PTXOperand::Register;
        mul.d.type = type;
        mul.a = mul.d;
        mul.b.type = type;
        mul.b.addressMode = ir::PTXOperand::Immediate;
        mul.b.imm_int = sizeof(size_t);

        kernel->dfg()->insert(block, mul, 21);

        // add counterPtrReg, counterPtr, offset  

        ir::PTXInstruction add(ir::PTXInstruction::Add);   
        add.type = type;
        add.d.type = type;
        add.d.reg = registerMap["counterPtrReg"];
        add.a.type = type;
        add.a.reg = registerMap["counterPtr"];
        add.b.type = type;
        add.b.reg = offset;

        kernel->dfg()->insert(block, add, 22);
        
        /* Load, increment, and store back the result into the
            global counter */
        
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
        st.d = ld.a;
        st.a = ld.d;

        kernel->dfg()->insert( block, ld, 23 );  
        kernel->dfg()->insert( block, add, 24 ); 
        kernel->dfg()->insert( block, st, 25 ); 

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

    void BasicBlockExecutionCountPass::runOnModule( ir::Module& m )
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

            analysis::BasicBlockInstrumentationPass instrumentationPass = analysis::BasicBlockInstrumentationPass();

            /* instrumenting ptx at the beginning of the first basic block. */
            std::map<std::string, DataflowGraph::RegisterId> registerMap = instrumentationPass._runOnEntryBlock((kernel->second), entry);      
            _runOnEntryBlock((kernel->second), entry, registerId, registerMap);
   
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

    std::string BasicBlockExecutionCountPass::basicBlockCounterBase() const
	{
		return "__ocelot_basic_block_counter_base";
	}


    void BasicBlockExecutionCountPass::initialize( const ir::Module& m )
	{
    
	}

    void BasicBlockExecutionCountPass::finalize( )
	{
	
	}
}


#endif

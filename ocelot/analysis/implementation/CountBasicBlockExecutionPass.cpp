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

    DataflowGraph::RegisterId CountBasicBlockExecutionPass::_runOnEntryBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId) {

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        DataflowGraph::RegisterId counterPtr = kernel->dfg()->newRegister();
        _runOnBlock(kernel, block, counterPtr, registerId, 0);

        ir::PTXInstruction mad(ir::PTXInstruction::Mad);
        mad.addressSpace = ir::PTXInstruction::Reg;
        mad.type = ir::PTXOperand::u16;
        mad.modifier = ir::PTXInstruction::lo;

        DataflowGraph::RegisterId tmp0 = kernel->dfg()->newRegister();
        mad.d.reg = tmp0;        
        mad.d.addressMode = ir::PTXOperand::Register;
        mad.d.type = ir::PTXOperand::u16;
        
        mad.a.type = ir::PTXOperand::u16;
        mad.a = ir::PTXOperand(ir::PTXOperand::tidY);
        mad.b.type = ir::PTXOperand::u16;
        mad.b = ir::PTXOperand(ir::PTXOperand::ntidX);
        mad.c.type = ir::PTXOperand::u16;
        mad.c = ir::PTXOperand(ir::PTXOperand::tidX);

        kernel->dfg()->insert(block, mad, 0);

        ir::PTXInstruction mul(ir::PTXInstruction::Mul);
        mul.addressSpace = ir::PTXInstruction::Reg;
        mul.type = ir::PTXOperand::u16;
        mul.modifier = ir::PTXInstruction::lo;

        DataflowGraph::RegisterId tmp1 = kernel->dfg()->newRegister();
        mul.d.reg = tmp1;
        mul.d.addressMode = ir::PTXOperand::Register;
        mul.d.type = ir::PTXOperand::u16;
        
        mul.a.type = ir::PTXOperand::u16;
        mul.a = ir::PTXOperand(ir::PTXOperand::ntidX);
        mul.b.type = ir::PTXOperand::u16;
        mul.b = ir::PTXOperand(ir::PTXOperand::ntidY);

        kernel->dfg()->insert(block, mul, 1);

        DataflowGraph::RegisterId tmp2 = kernel->dfg()->newRegister();
        mul.d.reg = tmp2;
        mul.a = ir::PTXOperand();
        mul.a.type = ir::PTXOperand::u16;
        mul.a.reg = tmp1;
        mul.b = ir::PTXOperand(ir::PTXOperand::tidZ);

        kernel->dfg()->insert(block, mul, 2);

        ir::PTXInstruction add(ir::PTXInstruction::Add);
        add.addressSpace = ir::PTXInstruction::Reg;
        add.type = ir::PTXOperand::u16;
        add.d.addressMode = ir::PTXOperand::Register;
        add.d.type = ir::PTXOperand::u16;
        add.d.reg = tmp0;
        add.a.addressMode = ir::PTXOperand::Register;
        add.a.type = ir::PTXOperand::u16;
        add.a.reg = tmp0;
        add.b.addressMode = ir::PTXOperand::Register;
        add.b.type = ir::PTXOperand::u16;
        add.b.reg = tmp2;

        kernel->dfg()->insert(block, add, 3);

        mad.d.reg = tmp2;
        mad.a = ir::PTXOperand(ir::PTXOperand::ctaIdY);
        mad.b = ir::PTXOperand(ir::PTXOperand::nctaIdX);
        mad.c = ir::PTXOperand(ir::PTXOperand::ctaIdX);
    
        kernel->dfg()->insert(block, mad, 4);
       
        mul.d.reg = tmp1;
        mul.a = ir::PTXOperand();
        mul.a.type = ir::PTXOperand::u16;
        mul.a.addressMode = ir::PTXOperand::Register;
        mul.a.reg = tmp1;
        mul.b = ir::PTXOperand(ir::PTXOperand::ntidZ);

        kernel->dfg()->insert(block, mul, 5); 

        mad.d.reg = tmp0;
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
        mad.c.reg = tmp0;

        kernel->dfg()->insert(block, mad, 6);

        ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
        cvt.addressSpace = ir::PTXInstruction::Reg;
        cvt.type = ir::PTXOperand::u32;

        DataflowGraph::RegisterId threadId = kernel->dfg()->newRegister();
        cvt.d.addressMode = ir::PTXOperand::Register;
		cvt.d.type = ir::PTXOperand::u32;
		cvt.d.reg = threadId;
        cvt.a.addressMode = ir::PTXOperand::Register;
        cvt.a.type = ir::PTXOperand::u16;
        cvt.a.reg = tmp0;

        kernel->dfg()->insert(block, cvt, 7);

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
        
        kernel->dfg()->insert(block, mul, 8);
        
        DataflowGraph::RegisterId counterBase = kernel->dfg()->newRegister();
        ir::PTXInstruction mov(ir::PTXInstruction::Mov);
        mov.type = type;
        mov.d.addressMode = ir::PTXOperand::Register;
        mov.d.reg = counterBase;
        mov.a.addressMode = ir::PTXOperand::Address;
        mov.a.identifier = basicBlockCounterBase();

        kernel->dfg()->insert(block, mov, 9); 

        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.type = type;
        ld.addressSpace = ir::PTXInstruction::Global;
        ld.a = mov.d;
        ld.d.addressMode = ir::PTXOperand::Register;
        ld.d.type = type;
        ld.d.reg = counterPtr;
    
        kernel->dfg()->insert(block, ld, 10); 

        add.type = type;
        add.d.type = type;
        add.d.reg = counterPtr;
        add.a.type = type;
        add.a.reg = counterPtr;
        add.b.type = type;
        add.b.reg = offset;

        kernel->dfg()->insert(block, add, 11);

        return counterPtr;

    }

    void CountBasicBlockExecutionPass::_runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId counterPtrRegId, DataflowGraph::RegisterId registerId, unsigned int offset)
	{

        /* Load, increment, and store back the result into the
            global counter array */
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
            wouldn't make sense to insert it at the end. */
     
        kernel->dfg()->insert( block, ld, 0 );  
        kernel->dfg()->insert( block, add, 1 ); 
        kernel->dfg()->insert( block, st, 2 ); 

	}
	
	void CountBasicBlockExecutionPass::runOnModule( ir::Module& m )
	{
		report( "Adding global variable to " << m.path() );
     
		ir::PTXStatement counter = ir::PTXStatement(ir::PTXStatement::Global);
        counter.name = basicBlockCounterBase();
        counter.type = ir::PTXOperand::u64;


        /* Since the global counter array needs to be declared per module, we need to
            traverse through all the kernels in this module and get the total number of
            basic blocks */
        unsigned int basicBlockCount = 0;
        for (ir::Module::KernelMap::const_iterator kernel = m.kernels().begin(); 
		    kernel != m.kernels().end(); ++kernel) {
            basicBlockCount += (kernel->second)->cfg()->size();
            /* creating a new register per kernel -- the same register can be reused so need to
            only create one per kernel and pass its id along. */
            DataflowGraph::RegisterId registerId = (kernel->second)->dfg()->newRegister();  
            /* instrumenting ptx at the beginning of the first basic block */
            DataflowGraph::RegisterId counterPtrRegId = _runOnEntryBlock((kernel->second), (kernel->second)->dfg()->begin(), registerId);

            /* also need to keep track of the memory offset for the global counter array */          
            unsigned int offset = sizeof(size_t);
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

    void CountBasicBlockExecutionPass::finalize( )
	{
	
	}

    std::string CountBasicBlockExecutionPass::basicBlockCounterBase() const
	{
		return "__ocelot_basic_block_counter_base";
	}
  
}

#endif

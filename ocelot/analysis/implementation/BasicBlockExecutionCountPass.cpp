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

    size_t BasicBlockExecutionCountPass::incrementBasicBlockCounter(  ir::PTXKernel *kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, std::map<std::string, DataflowGraph::RegisterId> registerMap, size_t location ) {

        /* Load, increment, and store back the result into the
            global counter */
        
        size_t initial = location;

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.addressSpace = ir::PTXInstruction::Global; 
        ld.type = type;       
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.a.reg = registerMap["counterPtrReg"];
        ld.d.reg = registerId;
        ld.d.addressMode = ir::PTXOperand::Register;
	    ld.d.type = type;		
        
        ir::PTXInstruction add(ir::PTXInstruction::Add);
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

        kernel->dfg()->insert( block, ld, location++ );  
        kernel->dfg()->insert( block, add, location++ ); 
        kernel->dfg()->insert( block, st, location++ ); 

        return location - initial;

    }

    void BasicBlockExecutionCountPass::runOnModule( ir::Module& m )
	{
		report( "Adding global variable to " << m.path() );

        analysis::BasicBlockInstrumentationPass instrumentationPass = analysis::BasicBlockInstrumentationPass();
     
		ir::PTXStatement counter = ir::PTXStatement(ir::PTXStatement::Global);
        counter.name = instrumentationPass.basicBlockCounterBase();
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
            size_t count = instrumentationPass.calculateThreadId((kernel->second), entry, 0);
            size_t location = count;
            count = instrumentationPass.calculateBasicBlockCounterOffset((kernel->second), entry, 0, location);
            location += count;  
            count = incrementBasicBlockCounter((kernel->second), entry, registerId, instrumentationPass.registerMap, location);
   
            unsigned int basicBlockId = 1;
            for( analysis::DataflowGraph::iterator block = ++(entry); 
			    block != (kernel->second)->dfg()->end(); ++block )
		        {
                   if(!block->instructions().empty()){
                        count = instrumentationPass.calculateBasicBlockCounterOffset((kernel->second), block, basicBlockId, 0);
                        count = incrementBasicBlockCounter((kernel->second), block, registerId, instrumentationPass.registerMap, count);
                        basicBlockId++;        
                    } 
		        }
	    }

        /* inserting the global counter array into the module */
        m.insertGlobal(counter);
	}


    void BasicBlockExecutionCountPass::initialize( const ir::Module& m )
	{
    
	}

    void BasicBlockExecutionCountPass::finalize( )
	{
	
	}
}


#endif

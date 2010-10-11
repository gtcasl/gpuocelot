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

    void CountBasicBlockExecutionPass::_runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, unsigned int offset)
	{
        /* Creating an atomic add instruction to atomically
            load, increment, and store back the result into the
            global counter array */
        ir::PTXInstruction atomicAdd(ir::PTXInstruction::Atom);
        atomicAdd.atomicOperation = ir::PTXInstruction::AtomicAdd;
        atomicAdd.addressSpace = ir::PTXInstruction::Global; 
        atomicAdd.type = ir::PTXOperand::u64;       
        atomicAdd.a.addressMode = ir::PTXOperand::Address;
        atomicAdd.a.identifier = basicBlockCounterName();
        atomicAdd.a.offset = offset;
        atomicAdd.d.reg = registerId;
        atomicAdd.d.addressMode = ir::PTXOperand::Register;
		atomicAdd.d.type = ir::PTXOperand::u64;		
        atomicAdd.b.addressMode = ir::PTXOperand::Immediate;
        atomicAdd.b.imm_int = 1;
        
        /* Need to insert in the beginning of the basic block.
            Since basic blocks usually end with branches, it
            wouldn't make sense to insert it at the end. */
        kernel->dfg()->insert( block, atomicAdd, 0 );

	}
	
	void CountBasicBlockExecutionPass::runOnModule( ir::Module& m )
	{
		report( "Adding global variable to " << m.path() );
       
		ir::PTXStatement statement = ir::PTXStatement(ir::PTXStatement::Global);
        statement.name = basicBlockCounterName();
        statement.type = ir::PTXOperand::u64;


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
            /* also need to keep track of the memory offset for the global counter array */          
            unsigned int offset = 0;
            for( analysis::DataflowGraph::iterator block = (kernel->second)->dfg()->begin(); 
			    block != (kernel->second)->dfg()->end(); ++block )
		        {
			        _runOnBlock( (kernel->second), block, registerId, offset);
                    /* incrementing offset by 8 since the counter is a .u64 */
                    offset = offset + 8;                  
		        }
	    }

        /* creating a global array counter, each index initialized to zero */
        statement.array.stride.push_back(basicBlockCount);
        statement.array.values = ir::PTXStatement::ArrayVector(basicBlockCount);

        /* inserting the global counter array into the module */
        m.insertGlobal(statement);
	}

    void CountBasicBlockExecutionPass::finalize( )
	{
	
	}

    std::string CountBasicBlockExecutionPass::basicBlockCounterName() const
	{
		return "__ocelot_basic_block_counter";
	}
}

#endif

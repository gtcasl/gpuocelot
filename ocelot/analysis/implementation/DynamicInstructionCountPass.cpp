/*! \file DynamicInstructionCountPass.cpp
	\date Friday April 1, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the DynamicInstructionCountPass class
*/

#ifndef DYNAMIC_INSTRUCTION_COUNT_PASS_CPP_INCLUDED
#define DYNAMIC_INSTRUCTION_COUNT_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/DynamicInstructionCountPass.h>
#include <ocelot/analysis/interface/BasicBlockInstrumentationPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis
{

    DynamicInstructionCountPass::DynamicInstructionCountPass() {

    }

    void DynamicInstructionCountPass::countInstructions(  ir::PTXKernel *kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, std::map<std::string, DataflowGraph::RegisterId> registerMap, size_t instructionCount ) {

        /* Load, count dynamic instructions, and store back the result into the
            global counter */
        
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.addressSpace = ir::PTXInstruction::Global; 
        ld.type = type;  
	    ld.a.type = type;     
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.a.reg = registerMap["counterPtrReg"];
        ld.d.reg = registerId;
        ld.d.addressMode = ir::PTXOperand::Register;
	    ld.d.type = type;		
        
        kernel->dfg()->insert( block, ld, block->instructions().size() - 1  );
        
        ir::PTXInstruction add(ir::PTXInstruction::Add);
        add.addressSpace = ir::PTXInstruction::Global; 
        add.type = type;
        add.d = ld.d;
        add.a = ld.d;
        add.b.type = type;	
        add.b.addressMode = ir::PTXOperand::Immediate;
        add.b.imm_int = instructionCount;
        
        kernel->dfg()->insert( block, add, block->instructions().size() - 1  );
        
        std::map<std::string, size_t> predicateMap;
        
        for(analysis::DataflowGraph::InstructionVector::const_iterator instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction){
		    ir::PTXInstruction *ptxInstruction = (ir::PTXInstruction *)instruction->i;
		    if(ptxInstruction->pg.condition == ir::PTXOperand::Pred)
			    predicateMap[ptxInstruction->pg.toString()]++;
	    }
	
	    DataflowGraph::RegisterId predCount = kernel->dfg()->newRegister();
	
	    ir::PTXInstruction selp(ir::PTXInstruction::SelP);
	    selp.type = type;
	    selp.d.type = type;
	    selp.d.addressMode = ir::PTXOperand::Register;
	    selp.d.reg = predCount;
	    selp.b.type = type;
	    selp.b.addressMode = ir::PTXOperand::Immediate;
	    selp.b.imm_int = 0;
	    selp.a.type = type;
	    selp.a.addressMode = ir::PTXOperand::Immediate;
	    selp.c.type = type;
	    selp.c.addressMode = ir::PTXOperand::Register;
	
	    add.b.addressMode = ir::PTXOperand::Register;
        add.b.reg = predCount;
	
	    for(std::map<std::string, size_t>::const_iterator predicateElement = predicateMap.begin(); predicateElement != predicateMap.end();
	    ++predicateElement){
		    selp.a.imm_int = predicateElement->second;
		    selp.c.identifier = predicateElement->first;
		    kernel->dfg()->insert( block, selp, block->instructions().size() - 1 );
		    kernel->dfg()->insert( block, add, block->instructions().size() - 1 );
	    }
        
        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;       
        st.d = ld.a;
        st.a = ld.d;
  
        kernel->dfg()->insert( block, st, block->instructions().size() - 1 ); 

    }

    void DynamicInstructionCountPass::runOnModule( ir::Module& m )
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
            size_t instructionCount = entry->instructions().size();
            size_t count = instrumentationPass.calculateThreadId((kernel->second), entry, 0);
            size_t location = count;
            count = instrumentationPass.calculateBasicBlockCounterOffset((kernel->second), entry, 0, location);
            location += count;  
            countInstructions((kernel->second), entry, registerId, instrumentationPass.registerMap, instructionCount);
   
            unsigned int basicBlockId = 1;
            for( analysis::DataflowGraph::iterator block = ++(entry); 
			    block != (kernel->second)->dfg()->end(); ++block )
		        {
                   if(!block->instructions().empty()){
                        instructionCount = block->instructions().size();
                        count = instrumentationPass.calculateBasicBlockCounterOffset((kernel->second), block, basicBlockId, 0);
                        countInstructions((kernel->second), block, registerId, instrumentationPass.registerMap, instructionCount);
                        basicBlockId++;        
                    } 
		        }
	    }

        /* inserting the global counter array into the module */
        m.insertGlobal(counter);
	}


    void DynamicInstructionCountPass::initialize( const ir::Module& m )
	{
    
	}

    void DynamicInstructionCountPass::finalize( )
	{
	
	}
}


#endif

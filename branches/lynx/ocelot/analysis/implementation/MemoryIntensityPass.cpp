/*! \file MemoryIntensityPass.cpp
	\date Wednesday April 13, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the MemoryIntensityPass class
*/

#ifndef MEMORY_INTENSITY_PASS_CPP_INCLUDED
#define MEMORY_INTENSITY_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/MemoryIntensityPass.h>
#include <ocelot/analysis/interface/DynamicInstructionCountPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis
{

    MemoryIntensityPass::MemoryIntensityPass() {

    }

    void MemoryIntensityPass::countMemoryOperations(  ir::PTXKernel *kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, std::map<std::string, DataflowGraph::RegisterId> registerMap, size_t memOpsCount ) {

        if(memOpsCount == 0)
            return;

        /* Load, count memory operations, and store back the result into the
            global counter */
        
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.addressSpace = ir::PTXInstruction::Global; 
        ld.type = type;  
	    ld.a.type = type;     
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.a.reg = registerMap["counterPtrReg"];
        ld.a.offset = sizeof(size_t);
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
        add.b.imm_int = memOpsCount;
        
        kernel->dfg()->insert( block, add, block->instructions().size() - 1  );
        
        std::map<std::string, size_t> predicateMap;
        
        for(analysis::DataflowGraph::InstructionVector::const_iterator instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction){
		    ir::PTXInstruction *ptxInstruction = (ir::PTXInstruction *)instruction->i;
		    if((ptxInstruction->opcode == ir::PTXInstruction::Ld || ptxInstruction->opcode == ir::PTXInstruction::St) 
                && ptxInstruction->pg.condition == ir::PTXOperand::Pred)
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

    size_t MemoryIntensityPass::_memOpsCount(DataflowGraph::iterator block) {

        size_t memOpsCount = 0;
        for(analysis::DataflowGraph::InstructionVector::const_iterator instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction){
		    ir::PTXInstruction *ptxInstruction = (ir::PTXInstruction *)instruction->i;
		    if(ptxInstruction->opcode == ir::PTXInstruction::Ld || ptxInstruction->opcode == ir::PTXInstruction::St)
			    memOpsCount++;
	    }
        return memOpsCount;
    }

    void MemoryIntensityPass::runOnModule( ir::Module& m )
	{
		report( "Adding global variable to " << m.path() );
        analysis::DynamicInstructionCountPass dynamicInstructionPass = analysis::DynamicInstructionCountPass();
     
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
    
            /* obtain instruction count and memory operations count prior to instrumenting */            
            size_t instructionCount = entry->instructions().size();
            size_t memOpsCount = _memOpsCount(entry); 

            /* instrumenting ptx at the beginning of the first basic block. */
            size_t count = calculateThreadId((kernel->second), entry, 0);
            size_t location = count;
            count = calculateBasicBlockCounterOffset((kernel->second), entry, 0, location);
            location += count;  
            dynamicInstructionPass.countInstructions((kernel->second), entry, registerId, registerMap, instructionCount);  
            countMemoryOperations((kernel->second), entry, registerId, registerMap, memOpsCount);
            

            unsigned int basicBlockId = 1;
            for( analysis::DataflowGraph::iterator block = ++(entry); 
			    block != (kernel->second)->dfg()->end(); ++block )
		        {
                   if(!block->instructions().empty()){

                        instructionCount = block->instructions().size();
                        memOpsCount = _memOpsCount(block);

                        count = calculateBasicBlockCounterOffset((kernel->second), block, basicBlockId, 0);
                        dynamicInstructionPass.countInstructions((kernel->second), block, registerId, registerMap, instructionCount);
                        countMemoryOperations((kernel->second), block, registerId, registerMap, memOpsCount);
                        basicBlockId++;        
                    } 
		        }
	    }

        /* inserting the global counter array into the module */
        m.insertGlobal(counter);
	}
}


#endif

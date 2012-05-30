/*! \file MemoryIntensityPass.cpp
	\date Wednesday April 13, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the MemoryIntensityPass class
*/

#ifndef MEMORY_INTENSITY_PASS_CPP_INCLUDED
#define MEMORY_INTENSITY_PASS_CPP_INCLUDED

#include <ocelot/transforms/interface/MemoryIntensityPass.h>
#include <ocelot/transforms/interface/InstructionCountPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace transforms
{

    void MemoryIntensityPass::countMemoryOperations(  analysis::DataflowGraph::iterator block, analysis::DataflowGraph::RegisterId registerId, std::map<std::string, analysis::DataflowGraph::RegisterId> registerMap, size_t memOpsCount ) {

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
        
        dfg().insert( block, ld, block->instructions().size() - 1  );
        
        ir::PTXInstruction add(ir::PTXInstruction::Add);
        add.addressSpace = ir::PTXInstruction::Global; 
        add.type = type;
        add.d = ld.d;
        add.a = ld.d;
        add.b.type = type;	
        add.b.addressMode = ir::PTXOperand::Immediate;
        add.b.imm_int = memOpsCount;
        
        dfg().insert( block, add, block->instructions().size() - 1  );
        
        std::map<std::string, size_t> predicateMap;
        
        for(analysis::DataflowGraph::InstructionVector::const_iterator instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction){
		    ir::PTXInstruction *ptxInstruction = (ir::PTXInstruction *)instruction->i;
		    if((ptxInstruction->opcode == ir::PTXInstruction::Ld || ptxInstruction->opcode == ir::PTXInstruction::St) 
                && ptxInstruction->addressSpace == ir::PTXInstruction::Global && ptxInstruction->pg.condition == ir::PTXOperand::Pred)
			    predicateMap[ptxInstruction->pg.toString()]++;
	    }
	
	    analysis::DataflowGraph::RegisterId predCount = dfg().newRegister();
	
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
		    dfg().insert( block, selp, block->instructions().size() - 1 );
		    dfg().insert( block, add, block->instructions().size() - 1 );
	    }
        
        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;       
        st.d = ld.a;
        st.a = ld.d;
  
        dfg().insert( block, st, block->instructions().size() - 1 ); 

    }

    size_t MemoryIntensityPass::_memOpsCount(analysis::DataflowGraph::iterator block) {

        size_t memOpsCount = 0;
        for(analysis::DataflowGraph::InstructionVector::const_iterator instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction){
		    ir::PTXInstruction *ptxInstruction = (ir::PTXInstruction *)instruction->i;
		    if((ptxInstruction->opcode == ir::PTXInstruction::Ld || ptxInstruction->opcode == ir::PTXInstruction::St) && ptxInstruction->addressSpace == ir::PTXInstruction::Global)
			    memOpsCount++;
	    }
        return memOpsCount;
    }

    void MemoryIntensityPass::runOnKernel( ir::IRKernel& k )
	{

        analysis::DataflowGraph::RegisterId registerId = dfg().newRegister();  

        /* ensure that there is at least one basic block -- otherwise, skip this kernel */
        if(dfg().empty())
            return;
        
        analysis::DataflowGraph::iterator entry = dfg().begin();
        ++entry;

        /* obtain instruction count and memory operations count prior to instrumenting */            
        size_t instructionCount = entry->instructions().size();
        size_t memOpsCount = _memOpsCount(entry); 

        /* instrumenting ptx at the beginning of the first basic block. */
        size_t count = calculateThreadId(entry, 0);
        size_t location = count;
        count = calculateBasicBlockCounterOffset(entry, 0, location);
        location += count;  
        countInstructions(entry, registerId, registerMap, instructionCount);  
        countMemoryOperations(entry, registerId, registerMap, memOpsCount);
        

        unsigned int basicBlockId = 1;
        for( analysis::DataflowGraph::iterator block = ++(entry); 
		    block != dfg().end(); ++block )
	        {
               if(!block->instructions().empty()){

                    instructionCount = block->instructions().size();
                    memOpsCount = _memOpsCount(block);

                    count = calculateBasicBlockCounterOffset(block, basicBlockId, 0);
                    countInstructions(block, registerId, registerMap, instructionCount);
                    countMemoryOperations(block, registerId, registerMap, memOpsCount);
                    basicBlockId++;        
                } 
	        }
    }

	
	MemoryIntensityPass::MemoryIntensityPass()
	{
    }    
	
}


#endif

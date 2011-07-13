/*! \file CToPTXInstrumentationPass.cpp
	\date Tuesday July 1, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the CToPTXInstrumentationPass class
*/

#ifndef C_TO_PTX_INSTRUMENTATION_PASS_CPP_INCLUDED
#define C_TO_PTX_INSTRUMENTATION_PASS_CPP_INCLUDED

#include <ocelot/transforms/interface/CToPTXInstrumentationPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace transforms
{

    analysis::DataflowGraph& CToPTXInstrumentationPass::dfg()
	{
		analysis::Analysis* graph = getAnalysis(
			analysis::Analysis::DataflowGraphAnalysis);

		assert(graph != 0);
		
		return static_cast<analysis::DataflowGraph&>(*graph);
	}

    ir::PTXStatement CToPTXInstrumentationPass::prepareStatementToInsert(ir::PTXStatement statement, unsigned int basicBlockSize, unsigned int basicBlockId) {
    
        ir::PTXStatement toInsert = statement;
        
        if(statement.instruction.d.identifier == BASIC_BLOCK_SIZE) {
            toInsert.instruction.d.reg = dfg().newRegister();
            newRegisterMap[toInsert.instruction.d.identifier] = toInsert.instruction.d.reg;
            toInsert.instruction.d.identifier.clear();
            toInsert.instruction.a.imm_int = basicBlockSize;
            return toInsert;
        }
        
        if(statement.instruction.d.identifier == BASIC_BLOCK_ID) {
            toInsert.instruction.d.reg = dfg().newRegister();
            newRegisterMap[toInsert.instruction.d.identifier] = toInsert.instruction.d.reg;
            toInsert.instruction.d.identifier.clear();
            toInsert.instruction.a.imm_int = basicBlockId;
            return toInsert;
        }
            
        if((statement.instruction.a.addressMode == ir::PTXOperand::Register || statement.instruction.a.addressMode == ir::PTXOperand::Indirect) && !statement.instruction.a.identifier.empty()) {
            toInsert.instruction.a.reg = newRegisterMap[statement.instruction.a.identifier];
            toInsert.instruction.a.identifier.clear();
        }
        if(statement.instruction.b.addressMode == ir::PTXOperand::Register && !statement.instruction.b.identifier.empty()) {
            toInsert.instruction.b.reg = newRegisterMap[statement.instruction.b.identifier];
            toInsert.instruction.b.identifier.clear();
        }
        if(statement.instruction.c.addressMode == ir::PTXOperand::Register && !statement.instruction.c.identifier.empty()) {
            toInsert.instruction.c.reg = newRegisterMap[statement.instruction.c.identifier];
            toInsert.instruction.c.identifier.clear();
        }
        if((statement.instruction.d.addressMode == ir::PTXOperand::Register || statement.instruction.d.addressMode == ir::PTXOperand::Indirect) && !statement.instruction.d.identifier.empty()) {
            toInsert.instruction.d.reg = newRegisterMap[statement.instruction.d.identifier];
            toInsert.instruction.d.identifier.clear();
        }
        if(statement.instruction.pg.condition == ir::PTXOperand::Pred && !statement.instruction.pg.identifier.empty()){
            toInsert.instruction.pg.reg = newRegisterMap[statement.instruction.pg.identifier];
            toInsert.instruction.pg.identifier.clear();
        }

        return toInsert;
    }

    void CToPTXInstrumentationPass::runOnKernel( ir::IRKernel & k)
	{
	    /* ensure that there is at least one basic block -- otherwise, skip this kernel */
        if(dfg().empty())
            return;
        
        /* by default, insert each statement to the beginning of the kernel */
	    analysis::DataflowGraph::iterator block = dfg().begin();
	    ++block;

	    for(translator::CToPTXData::RegisterVector::const_iterator reg = translation.registers.begin();
	        reg != translation.registers.end(); ++reg) {
	        newRegisterMap[*reg] = dfg().newRegister();   
	    }
	
        size_t loc = 0;
        int basicBlockInstStart = -1;
        std::string whereToInstrument;
        unsigned int basicBlockSize = block->instructions().size();
        
        for(ir::PTXKernel::PTXStatementVector::const_iterator statement = translation.statements.begin();
            statement != translation.statements.end(); ++statement) {
            
            ir::PTXStatement toInsert = prepareStatementToInsert(*statement, basicBlockSize, 0);
            
            if(statement->directive == ir::PTXStatement::Label) {
                whereToInstrument = statement->name;
                if(statement->name == EXIT_KERNEL) {
                    block = --(dfg().end());
                    while(block->instructions().size() == 0) {
                        block--;
                    }
                    loc = block->instructions().size() - 1;
                }
                else if(statement->name == ENTER_BASIC_BLOCK) {
                    basicBlockInstStart = loc;
                }   
                else if(statement->name == EXIT_BASIC_BLOCK) {
                    basicBlockInstStart = loc;
                }
                continue;
            }
            
            dfg().insert(block, toInsert.instruction, loc);
            loc++;
        }
        
        if(basicBlockInstStart > -1){
            unsigned int basicBlockId = 1;
            for( analysis::DataflowGraph::iterator basicBlock = ++(block); 
		        basicBlock != dfg().end(); ++basicBlock )
            {
               if(!basicBlock->instructions().empty()){
                    unsigned int i = 0;
                    basicBlockSize = basicBlock->instructions().size();
                    if(whereToInstrument == ENTER_BASIC_BLOCK)
                        loc = 0;
                    else if(whereToInstrument == EXIT_BASIC_BLOCK)
                        loc = basicBlock->instructions().size() - 1;
                    for(i = basicBlockInstStart; i < translation.statements.size(); i++) {
                        ir::PTXStatement toInsert = prepareStatementToInsert(translation.statements.at(i), basicBlockSize, basicBlockId);
                        if(toInsert.instruction.opcode == ir::PTXInstruction::Nop)
                            continue;
                        dfg().insert(basicBlock, toInsert.instruction, loc);
                        loc++;
                    }
                    basicBlockId++;        
                } 
            }    
        }
        
	}
	
    void CToPTXInstrumentationPass::initialize( ir::Module& m )
	{   
	    /* inserting globals into the module */
	    for(ir::PTXKernel::PTXStatementVector::const_iterator global = translation.globals.begin();
	        global != translation.globals.end(); ++global) {
            m.insertGlobalAsStatement(*global);
	    }
	}

    void CToPTXInstrumentationPass::finalize( )
	{
	
	}
	
    CToPTXInstrumentationPass::CToPTXInstrumentationPass(std::string resource)
		: KernelPass( Analysis::DataflowGraphAnalysis,
			"CToPTXInstrumentationPass" )
	{
	    translator::CToPTXTranslator translator;
	    translation = translator.generate(resource);
	    baseAddress = translation.globals.front().name;
	}

}


#endif

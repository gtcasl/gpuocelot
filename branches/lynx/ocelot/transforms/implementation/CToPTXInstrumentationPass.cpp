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

    void CToPTXInstrumentationPass::runOnKernel( ir::IRKernel & k)
	{
	
	    std::map<std::string, analysis::DataflowGraph::RegisterId> newRegisterMap;
	    for(translator::CToPTXData::RegisterVector::const_iterator reg = translation.registers.begin();
	        reg != translation.registers.end(); ++reg) {
	        newRegisterMap[*reg] = dfg().newRegister();   
	    }
	
	    /* by default, insert each statement to the beginning of the kernel */
	    analysis::DataflowGraph::iterator block = dfg().begin();
        
        size_t loc = 0;
        
        for(ir::PTXKernel::PTXStatementVector::const_iterator statement = translation.statements.begin();
            statement != translation.statements.end(); ++statement) {
            
            ir::PTXStatement toInsert = *statement;
            
            if((statement->instruction.a.addressMode == ir::PTXOperand::Register || statement->instruction.a.addressMode == ir::PTXOperand::Indirect) && !statement->instruction.a.identifier.empty()) {
                toInsert.instruction.a.reg = newRegisterMap[statement->instruction.a.identifier];
                toInsert.instruction.a.identifier.clear();
            }
            if(statement->instruction.b.addressMode == ir::PTXOperand::Register && !statement->instruction.b.identifier.empty()) {
                toInsert.instruction.b.reg = newRegisterMap[statement->instruction.b.identifier];
                toInsert.instruction.b.identifier.clear();
            }
            if(statement->instruction.c.addressMode == ir::PTXOperand::Register && !statement->instruction.c.identifier.empty()) {
                toInsert.instruction.c.reg = newRegisterMap[statement->instruction.c.identifier];
                toInsert.instruction.c.identifier.clear();
            }
            if((statement->instruction.d.addressMode == ir::PTXOperand::Register || statement->instruction.d.addressMode == ir::PTXOperand::Indirect) && !statement->instruction.d.identifier.empty()) {
                toInsert.instruction.d.reg = newRegisterMap[statement->instruction.d.identifier];
                toInsert.instruction.d.identifier.clear();
            }
            if(statement->instruction.pg.condition == ir::PTXOperand::Pred && !statement->instruction.pg.identifier.empty()){
                toInsert.instruction.pg.reg = newRegisterMap[statement->instruction.pg.identifier];
                toInsert.instruction.pg.identifier.clear();
            }
            
            if(statement->directive == ir::PTXStatement::Label) {
                if(statement->name == EXIT_KERNEL) {
                    block = --(dfg().end());
                    while(block->instructions().size() == 0) {
                        block--;
                    }
                    loc = block->instructions().size() - 1;
                }   
                continue;
            }
            
            dfg().insert(block, toInsert.instruction, loc);
            loc++;
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

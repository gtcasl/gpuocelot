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

#include <map>

namespace transforms
{

    analysis::DataflowGraph& CToPTXInstrumentationPass::dfg()
	{
		analysis::Analysis* graph = getAnalysis(
			analysis::Analysis::DataflowGraphAnalysis);

		assert(graph != 0);
		
		return static_cast<analysis::DataflowGraph&>(*graph);
	}

    ir::PTXStatement CToPTXInstrumentationPass::prepareStatementToInsert(ir::PTXStatement statement, StaticAttributes attributes) {
    
        ir::PTXStatement toInsert = statement;
        
        if(statement.instruction.d.identifier == BASIC_BLOCK_INST_COUNT) {
            toInsert.instruction.d.reg = dfg().newRegister();
            newRegisterMap[toInsert.instruction.d.identifier] = toInsert.instruction.d.reg;
            toInsert.instruction.d.identifier.clear();
            toInsert.instruction.a.imm_int = attributes.basicBlockInstructionCount;
            return toInsert;
        }
        
        if(statement.instruction.d.identifier == BASIC_BLOCK_ID) {
            toInsert.instruction.d.reg = dfg().newRegister();
            newRegisterMap[toInsert.instruction.d.identifier] = toInsert.instruction.d.reg;
            toInsert.instruction.d.identifier.clear();
            toInsert.instruction.a.imm_int = attributes.basicBlockId;
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

    void CToPTXInstrumentationPass::instrumentInstruction(std::vector<TranslationBlock> translationBlocks) 
    {
        StaticAttributes attributes;
        attributes.basicBlockId = 0;
        
        analysis::DataflowGraph::iterator block = dfg().begin();
        ++block;
        
        for( analysis::DataflowGraph::iterator basicBlock = block; 
            basicBlock != dfg().end(); ++basicBlock )
        {
           if(basicBlock->instructions().empty())
              continue;

            attributes.basicBlockInstructionCount = basicBlock->instructions().size();
            unsigned int loc = 0;
                        
            attributes.instructionId = 0;
            for( analysis::DataflowGraph::InstructionVector::const_iterator instruction = basicBlock->instructions().begin();
                instruction != basicBlock->instructions().end(); ++instruction)
            {
            
                ir::PTXInstruction *ptxInstruction = (ir::PTXInstruction *)instruction->i;
                
                unsigned int i = 0, j = 0;
                for( i = 0; i < translationBlocks.size(); i++)
                {
                    if(translationBlocks.at(i).statements.empty())
                        continue;
                  
                    if(!translationBlocks.at(i).specifier.instructionClass.empty())
                    {
                            std::pair<std::multimap<std::string, ir::PTXInstruction::Opcode>::iterator, std::multimap<std::string, ir::PTXInstruction::Opcode>::iterator> instClassMap;
                        instClassMap = instructionClassMap.equal_range(translationBlocks.at(i).specifier.instructionClass);
                        
                        for (std::multimap<std::string, ir::PTXInstruction::Opcode>::iterator instClass = instClassMap.first; instClass != instClassMap.second; ++instClass) 
                        {
                            if(instClass->second == ptxInstruction->opcode)
                            {
                                for( j = 0; j < translationBlocks.at(i).statements.size(); j++) {
                                    ir::PTXStatement toInsert = prepareStatementToInsert(translationBlocks.at(i).statements.at(j), attributes);
                                    if(toInsert.instruction.opcode == ir::PTXInstruction::Nop)
                                        continue;
                                    dfg().insert(basicBlock, toInsert.instruction, loc);
                                    loc++;
                                }
                                attributes.instructionId++;
                                break;
                            }
                            else {
                                loc++;
                            }
                        }    
                    
                    }
                    else 
                    {    
                        for( j = 0; j < translationBlocks.at(i).statements.size(); j++) 
                        {
                                ir::PTXStatement toInsert = prepareStatementToInsert(translationBlocks.at(i).statements.at(j), attributes);
                                if(toInsert.instruction.opcode == ir::PTXInstruction::Nop)
                                    continue;
                                dfg().insert(basicBlock, toInsert.instruction, loc);
                                loc++;
                        }
                        attributes.instructionId++;
                        loc++;
                    }
                }
            }
            
           attributes.basicBlockId++;          
        }    
    }

    void CToPTXInstrumentationPass::instrumentBasicBlock(std::vector<TranslationBlock> translationBlocks) 
    {
        StaticAttributes attributes;
        attributes.basicBlockId = 0;
        attributes.basicBlockInstructionCount = 0;
        
        analysis::DataflowGraph::iterator block = dfg().begin();
        ++block;
        
        for( analysis::DataflowGraph::iterator basicBlock = block; 
            basicBlock != dfg().end(); ++basicBlock )
        {        
           if(basicBlock->instructions().empty())
              continue;
        
            unsigned int i = 0, j = 0;
            for( i = 0; i < translationBlocks.size(); i++)
            {
                if(translationBlocks.at(i).statements.empty())
                    continue;
                
                attributes.basicBlockInstructionCount = 0;
                
                if(!translationBlocks.at(i).specifier.instructionClass.empty())
                {
                    for( analysis::DataflowGraph::InstructionVector::const_iterator instruction = basicBlock->instructions().begin();
                        instruction != basicBlock->instructions().end(); ++instruction)
                    {
                        ir::PTXInstruction *ptxInstruction = (ir::PTXInstruction *)instruction->i;
                        
                        std::pair<std::multimap<std::string, ir::PTXInstruction::Opcode>::iterator, std::multimap<std::string, ir::PTXInstruction::Opcode>::iterator> instClassMap;
                        instClassMap = instructionClassMap.equal_range(translationBlocks.at(i).specifier.instructionClass);
                        
                        for (std::multimap<std::string, ir::PTXInstruction::Opcode>::iterator instClass = instClassMap.first; instClass != instClassMap.second; ++instClass) 
                        {
                            if(instClass->second == ptxInstruction->opcode)
                            {
                                if(translationBlocks.at(i).specifier.addressSpace.empty() && translationBlocks.at(i).specifier.type.empty())
                                    attributes.basicBlockInstructionCount++; 
                                else if(!translationBlocks.at(i).specifier.addressSpace.empty() && addressSpaceMap[translationBlocks.at(i).specifier.addressSpace] == ptxInstruction->addressSpace)
                                    attributes.basicBlockInstructionCount++;
                                else if(!translationBlocks.at(i).specifier.type.empty())
                                {
                                    std::pair<std::multimap<std::string, ir::PTXOperand::DataType>::iterator, std::multimap<std::string, ir::PTXOperand::DataType>::iterator> typeMap;
                                    typeMap = typesMap.equal_range(translationBlocks.at(i).specifier.type);
                                    
                                    for (std::multimap<std::string, ir::PTXOperand::DataType>::iterator type = typeMap.first; type != typeMap.second; ++type)
                                    {
                                        if(type->second == ptxInstruction->type){
                                            attributes.basicBlockInstructionCount++;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        
                    }
                
                }
                else {
                    attributes.basicBlockInstructionCount = basicBlock->instructions().size();
                }
                
                unsigned int loc = 0;
                
                if(translationBlocks.at(i).label == EXIT_BASIC_BLOCK)
                    loc = basicBlock->instructions().size() - 1;
                
                for( j = 0; j < translationBlocks.at(i).statements.size(); j++) {
                    ir::PTXStatement toInsert = prepareStatementToInsert(translationBlocks.at(i).statements.at(j), attributes);
                    if(toInsert.instruction.opcode == ir::PTXInstruction::Nop)
                        continue;
                    dfg().insert(basicBlock, toInsert.instruction, loc);
                    loc++;
                }
            }
           
           attributes.basicBlockId++;          
        }    
    }

    void CToPTXInstrumentationPass::instrumentKernel(std::vector<TranslationBlock> translationBlocks) 
    {
        StaticAttributes attributes;
        attributes.basicBlockId = 0;
        attributes.instructionId = 0;
        attributes.kernelInstructionCount = 0;
                
        /* ensure that there is at least one basic block -- otherwise, skip this kernel */
        if(dfg().empty())
            return;
        
        /* by default, insert each statement to the beginning of the kernel */
	    analysis::DataflowGraph::iterator block = dfg().begin();
	    ++block;
	    
	    for( analysis::DataflowGraph::iterator basicBlock = block; 
            basicBlock != dfg().end(); ++basicBlock )
        {
            attributes.kernelInstructionCount += basicBlock->instructions().size();
        }
	    
	    unsigned int i = 0, j = 0;
        for( i = 0; i < translationBlocks.size(); i++)
        {
            if(translationBlocks.at(i).statements.empty())
                continue;
            
            unsigned int loc = 0;
            
            if(translationBlocks.at(i).label == EXIT_KERNEL) {    
                block = --(dfg().end());
                while(block->instructions().size() == 0) {
                    block--;
                }
                loc = block->instructions().size() - 1;
            }
            
            for( j = 0; j < translationBlocks.at(i).statements.size(); j++) {
                ir::PTXStatement toInsert = prepareStatementToInsert(translationBlocks.at(i).statements.at(j), attributes);
                if(toInsert.instruction.opcode == ir::PTXInstruction::Nop)
                    continue;
                dfg().insert(block, toInsert.instruction, loc);
                loc++;
            }
        }
        
    }

    void CToPTXInstrumentationPass::runOnKernel( ir::IRKernel & k)
	{
	    std::vector<TranslationBlock> translationBlocks;

	    for(translator::CToPTXData::RegisterVector::const_iterator reg = translation.registers.begin();
	        reg != translation.registers.end(); ++reg) {
	        newRegisterMap[*reg] = dfg().newRegister();   
	    }

        bool translationBlockStart = false;
        bool kernelInstrumentation = true;
        bool basicBlockInstrumentation = false;
        bool instructionInstrumentation = false;
        bool foundInstClass = false;
        bool foundAddressSpace = false;
        bool foundType = false;
        
        TranslationBlock initialBlock;
        
        for(ir::PTXKernel::PTXStatementVector::const_iterator statement = translation.statements.begin();
            statement != translation.statements.end(); ++statement) {
            
            if(statement->directive == ir::PTXStatement::Label) {
                        
                for(std::vector<std::string>::const_iterator instClass = instructionClasses.begin(); instClass != instructionClasses.end();
                    instClass++)
                {
                    if(statement->name == *instClass){
                        
                        foundInstClass = true;
                        
                        if(translationBlocks.size() > 0 && translationBlockStart){
                            transforms::TranslationBlock last = translationBlocks.back();
                            last.specifier.instructionClass = *instClass;
                            translationBlocks.pop_back();
                            translationBlocks.push_back(last);
                        }
                        else {
                            initialBlock.specifier.instructionClass = *instClass;
                        }
                        break;
                    }
                }
                
                for(std::vector<std::string>::const_iterator addressSpace = addressSpaceSpecifiers.begin(); addressSpace != addressSpaceSpecifiers.end();
                    addressSpace++)
                {
                    if(statement->name == *addressSpace){
                        
                        foundAddressSpace = true;
                        
                        if(translationBlocks.size() > 0 && translationBlockStart){
                            transforms::TranslationBlock last = translationBlocks.back();
                            last.specifier.addressSpace = *addressSpace;
                            translationBlocks.pop_back();
                            translationBlocks.push_back(last);
                        }
                        else {
                            initialBlock.specifier.addressSpace = *addressSpace;
                        }
                        break;
                    }
                }
            
                for(std::vector<std::string>::const_iterator type = types.begin(); type != types.end();
                    type++)
                {
                    if(statement->name == *type){
                        
                        foundType = true;
                        
                        if(translationBlocks.size() > 0 && translationBlockStart){
                            transforms::TranslationBlock last = translationBlocks.back();
                            last.specifier.type = *type;
                            translationBlocks.pop_back();
                            translationBlocks.push_back(last);
                        }
                        else {
                            initialBlock.specifier.type = *type;
                        }
                        break;
                    }
                
                }
            
                if(!foundInstClass && !foundAddressSpace && !foundType)
                    translationBlockStart = false;
                
                if(statement->name == ENTER_KERNEL || statement->name == EXIT_KERNEL || statement->name == ENTER_BASIC_BLOCK || statement->name == EXIT_BASIC_BLOCK ||
                    statement->name == ON_INSTRUCTION) {
                    
                    TranslationBlock translationBlock;
                    translationBlock.label = translationBlock.specifier.id = statement->name;
                    translationBlocks.push_back(translationBlock);
                    translationBlockStart = true;
                    
                    if(statement->name == ENTER_BASIC_BLOCK || statement->name == EXIT_BASIC_BLOCK)
                    {
                        basicBlockInstrumentation = true;
                        kernelInstrumentation = false;
                    }
                    else if(statement->name == ON_INSTRUCTION)
                    {
                        instructionInstrumentation = true;
                        kernelInstrumentation = false;
                    }
                    
                }
                
                continue;
            }
            
            if(translationBlocks.size() > 0 && translationBlockStart){
                transforms::TranslationBlock last = translationBlocks.back();
                last.statements.push_back(*statement);
                translationBlocks.pop_back();
                translationBlocks.push_back(last);
            }
            else {
                initialBlock.statements.push_back(*statement);
            }
        }
        
        
        if(instructionInstrumentation) {
            instrumentInstruction(translationBlocks);
        }
        else if(basicBlockInstrumentation) {
            instrumentBasicBlock(translationBlocks);
        }
        else {
            instrumentKernel(translationBlocks);
        }
            
        /* insert initial translation block at the beginning of the kernel (default) */
        analysis::DataflowGraph::iterator block = dfg().begin();
        ++block;
        StaticAttributes attributes;
        attributes.basicBlockId = 0;
        attributes.instructionId = 0;
        attributes.basicBlockInstructionCount = block->instructions().size();
        
        unsigned int j = 0, loc = 0;
        for( j = 0; j < initialBlock.statements.size(); j++) {
            ir::PTXStatement toInsert = prepareStatementToInsert(initialBlock.statements.at(j), attributes);
            if(toInsert.instruction.opcode == ir::PTXInstruction::Nop)
                continue;
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
	
	    instructionClasses.push_back(ON_MEM_RW);
	    instructionClasses.push_back(ON_MEM_READ);
	    instructionClasses.push_back(ON_MEM_WRITE);
	    instructionClasses.push_back(ON_PREDICATE); 
	    instructionClasses.push_back(ON_BRANCH);
	    instructionClasses.push_back(ON_CALL);
	    instructionClasses.push_back(ON_BARRIER);
	    instructionClasses.push_back(ON_ATOMIC);
	    instructionClasses.push_back(ON_ARITH_OP);
	    
	    addressSpaceSpecifiers.push_back(GLOBAL);
	    addressSpaceSpecifiers.push_back(LOCAL);
	    addressSpaceSpecifiers.push_back(SHARED);
	    addressSpaceSpecifiers.push_back(CONST);
	    addressSpaceSpecifiers.push_back(PARAM);
	    addressSpaceSpecifiers.push_back(TEXTURE);
	    
	    types.push_back(TYPE_INT);
	    types.push_back(TYPE_FP);
	    
	    instructionClassMap.insert( std::make_pair( ON_MEM_RW, ir::PTXInstruction::Ld ));
	    instructionClassMap.insert( std::make_pair( ON_MEM_RW, ir::PTXInstruction::St ));
	    instructionClassMap.insert( std::make_pair( ON_MEM_READ, ir::PTXInstruction::Ld ));
	    instructionClassMap.insert( std::make_pair( ON_MEM_WRITE, ir::PTXInstruction::St ));
	    
	    instructionClassMap.insert( std::make_pair( ON_PREDICATE, ir::PTXInstruction::SetP ));   
	    
	    instructionClassMap.insert( std::make_pair( ON_BRANCH, ir::PTXInstruction::Bra ));
	    
	    instructionClassMap.insert( std::make_pair( ON_CALL, ir::PTXInstruction::Call ));
	    
	    instructionClassMap.insert( std::make_pair( ON_BARRIER, ir::PTXInstruction::Bar ));
	    instructionClassMap.insert( std::make_pair( ON_BARRIER, ir::PTXInstruction::Membar ));
	    
	    instructionClassMap.insert( std::make_pair( ON_ATOMIC, ir::PTXInstruction::Atom ));
	    
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Abs ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Add ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::AddC ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Bfe ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Bfi ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Bfind ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Brev ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Clz ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Cos ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Div ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Mad24 ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Mad ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Max ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Min ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Mul24 ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Mul ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Popc ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Prmt ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Sad ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Rsqrt ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Sqrt ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Sin ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Sub ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::SubC ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::TestP ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::CopySign ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Lg2 ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Ex2 ));
	    instructionClassMap.insert( std::make_pair( ON_ARITH_OP, ir::PTXInstruction::Neg ));
	    
	    addressSpaceMap[GLOBAL] = ir::PTXInstruction::Global;
	    addressSpaceMap[LOCAL] = ir::PTXInstruction::Local;
	    addressSpaceMap[SHARED] = ir::PTXInstruction::Shared;
	    addressSpaceMap[CONST] = ir::PTXInstruction::Const;
	    addressSpaceMap[PARAM] = ir::PTXInstruction::Param;
	    addressSpaceMap[TEXTURE] = ir::PTXInstruction::Texture;
	    
	    typesMap.insert( std::make_pair( TYPE_INT, ir::PTXOperand::s8 ));
	    typesMap.insert( std::make_pair( TYPE_INT, ir::PTXOperand::s16 ));
	    typesMap.insert( std::make_pair( TYPE_INT, ir::PTXOperand::s32 ));
	    typesMap.insert( std::make_pair( TYPE_INT, ir::PTXOperand::s64 ));
	    typesMap.insert( std::make_pair( TYPE_INT, ir::PTXOperand::u8 ));
	    typesMap.insert( std::make_pair( TYPE_INT, ir::PTXOperand::u16 ));
	    typesMap.insert( std::make_pair( TYPE_INT, ir::PTXOperand::u32 ));
	    typesMap.insert( std::make_pair( TYPE_INT, ir::PTXOperand::u64 ));
	    typesMap.insert( std::make_pair( TYPE_FP, ir::PTXOperand::f16 ));
	    typesMap.insert( std::make_pair( TYPE_FP, ir::PTXOperand::f32 ));
	    typesMap.insert( std::make_pair( TYPE_FP, ir::PTXOperand::f64 ));
	       
	}
}


#endif

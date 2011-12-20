/*! \file BoundsCheckPass.cpp
    \date Friday April 1, 2011
    \author Naila Farooqui <naila@cc.gatech.edu>
    \brief The source file for the BoundsCheckPass class
*/

#ifndef BOUNDS_CHECK_PASS_CPP_INCLUDED
#define BOUNDS_CHECK_PASS_CPP_INCLUDED

#include <ocelot/transforms/interface/BoundsCheckPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace transforms
{
    analysis::DataflowGraph& BoundsCheckPass::dfg()
    {
        analysis::Analysis* graph = getAnalysis(
            analysis::Analysis::DataflowGraphAnalysis);
        assert(graph != 0);
        
        return static_cast<analysis::DataflowGraph&>(*graph);
    }
    
    void BoundsCheckPass::initialize(ir::Module &m) {
        report( "Adding global variable to " << m.path() );
     
        ir::PTXStatement counter = ir::PTXStatement(ir::PTXStatement::Global);
        counter.name = kernelReportInfo();
        counter.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
         
        /* inserting the global counter array into the module */
        m.insertGlobalAsStatement(counter);
    }
    
    void BoundsCheckPass::calcOffset( analysis::DataflowGraph::iterator block, 
        size_t& location)
    {
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        
        analysis::DataflowGraph::RegisterId offset = dfg().newRegister();
        
        // mul offset, offset, sizeof(size_t) 
	    ir::PTXInstruction mul(ir::PTXInstruction::Mul);
        mul.type = type;
        mul.modifier = ir::PTXInstruction::lo;
        mul.type = type;
        mul.d.reg = offset;
        mul.d.addressMode = ir::PTXOperand::Register;
	    mul.d.type = type;
	    mul.a.addressMode = ir::PTXOperand::Register;
	    mul.a.reg = registerMap["threadId"];
        mul.b.type = type;
        mul.b.addressMode = ir::PTXOperand::Immediate;
        mul.b.imm_int = entries * sizeof(size_t);

        dfg().insert(block, mul, location++);
        
        // add counterPtrReg, counterPtr, offset      
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
        add.b.reg = offset;

        dfg().insert(block, add, location++);
    }
    
    void BoundsCheckPass::runOnKernel( ir::IRKernel& k )
    {
        /* ensure that there is at least one basic block -- otherwise, skip this kernel */
        if( dfg().empty() )
        {
            return;
        }
        
        finalAddr = dfg().newRegister();
        //create new device function to traverse allocationMap
        ir::PTXKernel *subkernel = new ir::PTXKernel( getFuncName(), true, k.module);
        ir::ControlFlowGraph::iterator block = 
            subkernel->cfg()->insert_block(ir::ControlFlowGraph::BasicBlock("boundsCheck", subkernel->cfg()->newId()));
        _checkBounds( block );
        
        //compute address offset
        analysis::DataflowGraph::iterator entry = dfg().begin();

        /* instrumenting ptx at the beginning of the first basic block. */
        size_t location = calculateThreadId(entry, 0);
        calcOffset(entry, location);
        
        for( analysis::DataflowGraph::iterator block = (entry); 
		    block != dfg().end(); ++block )
        {
            _runOnBlock( block, location);
            location = 0;
        }
    }

    void BoundsCheckPass::_runOnBlock( analysis::DataflowGraph::iterator block,
        size_t location )
    {
        typedef analysis::DataflowGraph::InstructionVector::const_iterator
            const_iterator;
            unsigned long int loc = 0;
        const_iterator _instruction = block->instructions().begin();
        for( ; loc < location; ++loc, ++_instruction ) {}   //skip instructions of insertion
        
        for( ; _instruction != block->instructions().end(); 
            ++_instruction, ++loc )
        {
            report("testing testing testing location is ");
            ir::PTXInstruction& instruction = static_cast< 
                ir::PTXInstruction& >( *_instruction->i );
            if( instruction.opcode == ir::PTXInstruction::Ld
                || instruction.opcode == ir::PTXInstruction::Ldu
                || instruction.opcode == ir::PTXInstruction::St )
            {
                checkBounds(block, instruction, loc);
            }
        }
    }
    
    void BoundsCheckPass::_checkBounds( ir::ControlFlowGraph::iterator &block )
    {
        //get block pointer, insert instructions into it
        //transforms::BoundsCheckPass::_checkBounds(boundsCheckBlock);
        
        //loop over allocation map to see if address falls between one of the allocations
        /* 
         * set index = 0;
         * check if (address >= allocMap[index] && address <= allocMap[index+1])
         * if so, branch out of instrumentation (ret?)
         * index+=2;
         * if index < length? branch back to loop begin
         * out of loop, error, store address + tid + whatever to global memory for report
        */ 
        //ld allocMap
        //ld size, [allocMap+0]
        
        //begin_loop
        //setp.cmp.eq size, 0
        //%p bra error
        //sub size, size, 2*sizeof(size_t)              //for next iteration
        //ld base, [allocMap + 1*sizeof(size_t)]
        //setp.cmp.lt %p finalAddr, base
        //%p add allocMap, allocMap, 2*sizeof(size_t)
        //%p bra begin_loop
        //ld end, [allocMap + 2*sizeof(size_t)]
        //setp.cmp.le %p finalAddr, end
        //%p bra exit_label
        //add allocMap, allocMap, 2*sizeof(size_t)
        //bra begin_loop
        
        //error_label
        //ld idx
        //ld instruction #
        //st idx
        //st instruction #
        //st space
        //st finalAddr
        //st anything else into global error reporting memory
        
        //exit_label
        //ret
        
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        
        analysis::DataflowGraph::RegisterId allocMap = dfg().newRegister();
        analysis::DataflowGraph::RegisterId mapSize = dfg().newRegister();
        analysis::DataflowGraph::RegisterId index = dfg().newRegister();
        analysis::DataflowGraph::RegisterId pred = dfg().newRegister();
        analysis::DataflowGraph::RegisterId base = dfg().newRegister();
        analysis::DataflowGraph::RegisterId end = dfg().newRegister();
        
        //ld.global.u64 %allocMap, [allocMapAddr]
        ir::PTXInstruction *ldMapAddr = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldMapAddr->d = ir::PTXOperand(ir::PTXOperand::Register, type, allocMap);
        ldMapAddr->a = ir::PTXOperand(ir::PTXOperand::Address, getAllocMap());
//        ldMapAddr->a.offset = 0;
        ldMapAddr->type = type;
        ldMapAddr->addressSpace = ir::PTXInstruction::Global; 
        block->instructions.push_back(ldMapAddr);
        
        //ld size, [allocMap+0]
        ir::PTXInstruction *ldMapSize = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldMapSize->d = ir::PTXOperand(ir::PTXOperand::Register, type, mapSize);
        ldMapSize->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, allocMap);
        ldMapSize->type = type;
        ldMapSize->addressSpace = ir::PTXInstruction::Global; 
        block->instructions.push_back(ldMapSize);
        
        // mov index, 1 (0 is reserved for size of allocMap)
        ir::PTXInstruction *movIndex = new ir::PTXInstruction(ir::PTXInstruction::Mov);
        movIndex->d = ir::PTXOperand(ir::PTXOperand::Register, type, index);
        movIndex->a.addressMode = ir::PTXOperand::Immediate;
        movIndex->a.imm_uint = sizeof(size_t); 
        block->instructions.push_back(movIndex);

        //begin_loop
        //how to insert label?
        
        //setp.cmp.eq size, 0
        ir::PTXInstruction *setpLoopExit = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        setpLoopExit->comparisonOperator = ir::PTXInstruction::Eq;
        setpLoopExit->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
        setpLoopExit->a = ldMapSize->d;
        setpLoopExit->b.addressMode = ir::PTXOperand::Immediate;
        setpLoopExit->b.imm_uint = 0; 
        setpLoopExit->type = type;
        block->instructions.push_back(setpLoopExit);
        
        //%p bra error
        ir::PTXInstruction *braError = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        braError->d = ir::PTXOperand("exitLabel");
        braError->pg.condition = ir::PTXOperand::Pred;
        braError->pg.reg = pred;  
        block->instructions.push_back(braError);
        
        //sub size, size, 2              //for next iteration
        ir::PTXInstruction *subSize = new ir::PTXInstruction(ir::PTXInstruction::Sub);
        subSize->d = ldMapSize->d;
        subSize->a = ldMapSize->d;
        subSize->b.addressMode = ir::PTXOperand::Immediate;
        subSize->b.imm_uint = 2; 
        block->instructions.push_back(subSize);
        
        //ld base, [allocMap + 1*sizeof(size_t)]
        ir::PTXInstruction *ldBase = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldBase->d = ir::PTXOperand(ir::PTXOperand::Register, type, base);
        ldBase->a = ldMapAddr->d;
        ldBase->a.offset = sizeof(size_t);
        ldBase->type = type;
        ldBase->addressSpace = ir::PTXInstruction::Global; 
        block->instructions.push_back(ldBase);
        
        //setp.cmp.lt %p finalAddr, base
        ir::PTXInstruction *setpCmpBase = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        setpCmpBase->comparisonOperator = ir::PTXInstruction::Lt;
        setpCmpBase->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
        setpCmpBase->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, finalAddr);
        setpCmpBase->b = ldBase->d;
        setpCmpBase->type = type;
        block->instructions.push_back(setpCmpBase);
        
        //%p add allocMap, allocMap, 2*sizeof(size_t)
        ir::PTXInstruction *addMapPtr = new ir::PTXInstruction(ir::PTXInstruction::Add);
        addMapPtr->d = ldMapAddr->d;
        addMapPtr->a = ldMapAddr->d;
        addMapPtr->b.addressMode = ir::PTXOperand::Immediate;
        addMapPtr->b.imm_uint = 2*sizeof(size_t); 
        addMapPtr->pg.condition = ir::PTXOperand::Pred;
        addMapPtr->pg.reg = pred;  
        block->instructions.push_back(addMapPtr);
        
        //%p bra begin_loop
        ir::PTXInstruction *braLoopBegin = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        braLoopBegin->d = ir::PTXOperand("loopBeginLabel");
        braLoopBegin->pg.condition = ir::PTXOperand::Pred;
        braLoopBegin->pg.reg = pred;  
        block->instructions.push_back(braLoopBegin);
        
        //ld end, [allocMap + 2*sizeof(size_t)]
        ir::PTXInstruction *ldEnd = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldEnd->d = ir::PTXOperand(ir::PTXOperand::Register, type, end);
        ldEnd->a = ldMapAddr->d;
        ldEnd->a.offset = 2*sizeof(size_t);
        ldEnd->type = type;
        ldEnd->addressSpace = ir::PTXInstruction::Global; 
        block->instructions.push_back(ldEnd);
        
        //setp.cmp.le %p finalAddr, end
        ir::PTXInstruction *setpCmpEnd = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        setpCmpEnd->comparisonOperator = ir::PTXInstruction::Le;
        setpCmpEnd->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
        setpCmpEnd->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, finalAddr);
        setpCmpEnd->b = ldEnd->d;
        setpCmpEnd->type = type;
        block->instructions.push_back(setpCmpEnd);
        
        //%p bra exit_label
        ir::PTXInstruction *braLoopExit = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        braLoopExit->d = ir::PTXOperand("loopExitLabel");
        braLoopExit->pg.condition = ir::PTXOperand::Pred;
        braLoopExit->pg.reg = pred;  
        block->instructions.push_back(braLoopExit);
        
        //add allocMap, allocMap, 2*sizeof(size_t)
        ir::PTXInstruction *addMapPtr2 = new ir::PTXInstruction(ir::PTXInstruction::Add);
        addMapPtr2->d = ldMapAddr->d;
        addMapPtr2->a = ldMapAddr->d;
        addMapPtr2->b.addressMode = ir::PTXOperand::Immediate;
        addMapPtr2->b.imm_uint = 2*sizeof(size_t); 
        block->instructions.push_back(addMapPtr2);
        
        //bra begin_begin
        ir::PTXInstruction *braLoopBegin2 = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        braLoopBegin2->d = ir::PTXOperand("loopBeginLabel");
        block->instructions.push_back(braLoopBegin2);
        
        //error_label
        
        
        //ld idx
        //ld instruction #
        //st idx
        //st instruction #
        //st space
        //st finalAddr
        //st anything else into global error reporting memory
        
        //find thread id: x, y, z, blockx, blocky, blockz
        analysis::DataflowGraph::RegisterId tidX = dfg().newRegister();

        ir::PTXInstruction *cvtTidX = new ir::PTXInstruction(ir::PTXInstruction::Cvt);
        cvtTidX->type = type;
        cvtTidX->d = ir::PTXOperand(ir::PTXOperand::Register, type, tidX);
        cvtTidX->a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        cvtTidX->a.addressMode = ir::PTXOperand::Special;
        cvtTidX->a.vec = ir::PTXOperand::v1;
        
        block->instructions.push_back(cvtTidX);
        
        //ld.global.u64 %reportInfo, [reportinfoaddr]
        analysis::DataflowGraph::RegisterId reportInfo = dfg().newRegister();
        
        ir::PTXInstruction *ldReportInfo = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldReportInfo->d = ir::PTXOperand(ir::PTXOperand::Register, type, reportInfo);
        ldReportInfo->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, kernelReportInfo() );
        ldReportInfo->a.offset = 0;
        ldReportInfo->addressSpace = ir::PTXInstruction::Global; 
        
        block->instructions.push_back(ldReportInfo);
        
        //@%p st.global.u64 [reportInfoAddr + 0], tidX
        ir::PTXInstruction *stTidX = new ir::PTXInstruction(ir::PTXInstruction::St);
        stTidX->d = ir::PTXOperand(ir::PTXOperand::Indirect, type, registerMap["counterPtrReg"] ); //reportInfo
        stTidX->a = ir::PTXOperand(ir::PTXOperand::Register, type, tidX);
        stTidX->addressSpace = ir::PTXInstruction::Global; 
        block->instructions.push_back(stTidX);
        
        //        @%p st.global.u64 [reportInfoAddr + 1], finalAddr
        ir::PTXInstruction *stAddr = new ir::PTXInstruction(ir::PTXInstruction::St);
        stAddr->d = ir::PTXOperand(ir::PTXOperand::Indirect, type, registerMap["counterPtrReg"] ); //reportInfo
        stAddr->d.offset = sizeof(size_t);
        stAddr->a = ir::PTXOperand(ir::PTXOperand::Register, type, finalAddr);
        stAddr->addressSpace = ir::PTXInstruction::Global; 
        block->instructions.push_back(stAddr);
        
        //@%p st.global.u64 [reportInfoAddr + 2], offset
//        ir::PTXInstruction *stPC = new ir::PTXInstruction(ir::PTXInstruction::St);
//        stPC->d = ir::PTXOperand(ir::PTXOperand::Indirect, type, registerMap["counterPtrReg"] ); //reportInfo
//        stPC->d.offset = sizeof(size_t);
//        stPC->a = ir::PTXOperand(ir::PTXOperand::Register, type, PC);
//        stPC->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(stPC);

        //ret
        ir::PTXInstruction ret(ir::PTXInstruction::Ret);        
        block->instructions.push_back(&ret);
    }
        
    /* ! find final memory address, call bounds check function */
    void BoundsCheckPass::checkBounds( 
        const analysis::DataflowGraph::iterator block, 
        const ir::PTXInstruction& memInst, 
        unsigned long &loc ) 
    {
//        //reportInfoAddr is calculated by threadID+offset func from BasicBlockInstrumentationPass
//        mov.u64 finalAddr, addr (memInst.a or memInst.d, reg or identifier)
//        (optional) add finalAddr, finalAddr, offset
//        and.u64 masked, finalAddr, mask
//        setp.eq.u64 %p, masked, 0
//        cvt.u64.u32 tidX, special reg tid X
//        @%p st.global.u64 [reportInfoAddr + 0], tidX
//        @%p st.global.u64 [reportInfoAddr + 1], offset
//        @%p st.global.u64 [reportInfoAddr + 2], finalAddr
//        @%p st.global.u64 [reportInfoAddr + 3], addressSpace
        
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        
        
        ir::PTXOperand ir::PTXInstruction:: *operands[] = {&ir::PTXInstruction::d,
            &ir::PTXInstruction::a, &ir::PTXInstruction::b, &ir::PTXInstruction::c};
        
        int opId = -1;
        
        //for (int n = 0; n < 4; n++) 
        switch( memInst.opcode )
        {
            case ir::PTXInstruction::Ld:
            case ir::PTXInstruction::Ldu:
                opId = 1;
                break;
            case ir::PTXInstruction::St:
                opId = 0;
                break;
            default:
                assert(false);
                break;
        }
        
        //if 8, 16, 32, 64, 
        unsigned short mask=0;
        
        switch(memInst.type)
        {
            case ir::PTXOperand::s8:
            case ir::PTXOperand::u8:
            case ir::PTXOperand::b8:
                mask = 0x0;
                break;
            case ir::PTXOperand::s16:
            case ir::PTXOperand::u16:
            case ir::PTXOperand::b16:
            case ir::PTXOperand::f16:
                mask = 0x1;
                break;
            case ir::PTXOperand::s32:
            case ir::PTXOperand::u32:
            case ir::PTXOperand::f32:
            case ir::PTXOperand::b32:
                mask = 0x3;
                break;
            case ir::PTXOperand::u64:
            case ir::PTXOperand::s64:
            case ir::PTXOperand::f64:
            case ir::PTXOperand::b64:
                mask = 0x07;
                break;
            case ir::PTXOperand::pred:
            default:
                //error
                assert(false);
                break;
        }
            
//        mov.u64 finalAddr, addr (memInst.a or memInst.d, reg or identifier)
//        (optional) add finalAddr, finalAddr, offset
        ir::PTXInstruction mov(ir::PTXInstruction::Mov);
        mov.type = type;
        
        switch( (memInst.*operands[opId]).addressMode )
        {
            case ir::PTXOperand::Indirect:          //! content points to register contains address, use offset
                //move register to finalAddr -- juse use add by default?
                mov.d.type = type;      
                mov.d.addressMode = ir::PTXOperand::Register;
                mov.d.reg = finalAddr;    
                mov.a.type = type;
                mov.a.addressMode = ir::PTXOperand::Register;
                mov.a.reg = (memInst.*operands[opId]).reg;
                
                dfg().insert( block, mov, loc++ );
                
                if( (memInst.*operands[opId]).offset > 0 
                    && (memInst.*operands[opId]).offset & mask )
                {
                    ir::PTXInstruction add(ir::PTXInstruction::Add);
                    
                    add.type = type;
                    add.d.type = type;      
                    add.d.addressMode = ir::PTXOperand::Register;
                    add.d.reg = finalAddr;    
                    add.a.type = type;      
                    add.a.addressMode = ir::PTXOperand::Register;
                    add.a.reg = finalAddr;
                    add.b.addressMode = ir::PTXOperand::Immediate;
                    add.b.imm_int = (memInst.*operands[opId]).offset;
                    
                    dfg().insert( block, add, loc++ );
                }
                break;
            case ir::PTXOperand::Register:            //! use as register variable
                //move said register to finalAddr
                mov.d.type = type;          
                mov.d.addressMode = ir::PTXOperand::Register;
                mov.d.reg = finalAddr;
                mov.a.type = type;
                mov.a.addressMode = ir::PTXOperand::Register;
                mov.a.reg = (memInst.*operands[opId]).reg;
                
                dfg().insert( block, mov, loc++ );
                break;
            case ir::PTXOperand::Address:            //! treat as address, use offset
                //move said address to finalAddr
                mov.d.type = type;          
                mov.d.addressMode = ir::PTXOperand::Register;
                mov.d.reg = finalAddr;
                mov.a.type = type;
                if( memInst.addressSpace == ir::PTXInstruction::Param )
                {
                    if( (memInst.*operands[opId]).offset == 0)
                        return;
                        
                    mov.a.addressMode = ir::PTXOperand::Immediate;
                    mov.a.imm_uint = 0;
                } else {
                    mov.a.addressMode = ir::PTXOperand::Address;
                    mov.a.identifier = (memInst.*operands[opId]).identifier;
                }
                
                dfg().insert( block, mov, loc++ );
                mov.a.identifier.clear();
                
                if( (memInst.*operands[opId]).offset > 0 
                    && (memInst.*operands[opId]).offset & mask )
                {
                    ir::PTXInstruction add(ir::PTXInstruction::Add);
                    
                    add.type = type;
                    add.d.type = type;      
                    add.d.addressMode = ir::PTXOperand::Register;
                    add.d.reg = finalAddr;    
                    add.a.type = type;      
                    add.a.addressMode = ir::PTXOperand::Register;
                    add.a.reg = finalAddr;
                    add.b.addressMode = ir::PTXOperand::Immediate;
                    add.b.imm_int = (memInst.*operands[opId]).offset;
                    
                    dfg().insert( block, add, loc++ );
                }
                break;
             default:
                //error
                break;
        }
        
        //finalAddr is found
        ir::PTXInstruction call(ir::PTXInstruction::Call);
		call.tailCall = true;
		call.branchTargetInstruction = -1;
		call.a = ir::PTXOperand(ir::PTXOperand::FunctionName, 
		    getFuncName() );
		call.b = ir::PTXOperand(ir::PTXOperand::Indirect, type, finalAddr);
		call.d.addressMode = ir::PTXOperand::Invalid;
    }
    
    BoundsCheckPass::BoundsCheckPass() : entries(4)
    {
        baseAddress = kernelReportInfo();
        allocMapAddress = getAllocMap();
    }
    
    void BoundsCheckPass::finalize() {
    }
    
    std::string BoundsCheckPass::kernelReportInfo() const
    {
        return basicBlockCounterBase();//"__align_error_table";
    }
        
    std::string BoundsCheckPass::getFuncName()
    {
        return "_ZOcelotBoundsCheck";
    }
    std::string BoundsCheckPass::getAllocMap()
    {
        return "__global_allocation_map";
    }
}


#endif

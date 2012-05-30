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

#define REPORT_BASE 1

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
        
        ir::PTXStatement allocMap = ir::PTXStatement(ir::PTXStatement::Global);
        allocMap.name = getAllocMap();
        allocMap.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        
        m.insertGlobalAsStatement(allocMap);
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
    
    void BoundsCheckPass::runOnModule( ir::Module& m )
    {
        //create new device function to traverse allocationMap
        //ir::PTXKernel *checkBoundsKernel = new ir::PTXKernel( getFuncName(), true, &m);
        //ir::ControlFlowGraph::iterator block = 
            //checkBoundsKernel->cfg()->insert_block(ir::ControlFlowGraph::BasicBlock("boundsCheck", checkBoundsKernel->cfg()->newId()));
        //_checkBounds( block );
        
        //m.insertKernel( checkBoundsKernel );
    }

    void BoundsCheckPass::runOnKernel( ir::IRKernel& k )
    {
        kernelPointer = &k;
        finalAddr = dfg().newRegister();
        
        
        /* ensure that there is at least one basic block -- otherwise, skip this kernel */
        if( dfg().empty() )
            return;
        
        analysis::DataflowGraph::iterator entry = dfg().begin();
        ++entry;

        /* instrumenting ptx at the beginning of the first basic block. */
        size_t location = calculateThreadId(entry, 0);
        calcOffset(entry, location);
        for( analysis::DataflowGraph::iterator block = (entry); 
            block != dfg().end(); ++block )
        {
            report("Running BOUNDSCHECK on " << block->label());
            _runOnBlock( block, location);
            location = 0;
        }
    }

    void BoundsCheckPass::_runOnBlock( analysis::DataflowGraph::iterator &block,
        size_t location )
    {
        typedef analysis::DataflowGraph::InstructionVector::const_iterator
            const_iterator;
            unsigned long int loc = 0;
        const_iterator _instruction = block->instructions().begin();
        for( ; loc < location; ++loc, ++_instruction ) {}   //skip instrumentation instructions
        
        for( ; _instruction != block->instructions().end(); 
            ++_instruction, ++loc )
        {
            ir::PTXInstruction& instruction = static_cast< 
                ir::PTXInstruction& >( *_instruction->i );
            
            report("location:" << loc << " " << instruction.toString());
            
            if( instruction.addressSpace == ir::PTXInstruction::Global &&
                ( instruction.opcode == ir::PTXInstruction::Ld
                || instruction.opcode == ir::PTXInstruction::Ldu
                || instruction.opcode == ir::PTXInstruction::St ) )
            {
                report("inserting instrumentation");
                checkBounds(block, instruction, loc);     //FIXME debugging
                loc = 1;                                    //FIXME not sure if this works
                _instruction = block->instructions().begin();
                for(unsigned int i=0; i < loc; i++, ++_instruction){}
                    
            }
        }
    }
    
        
    /* ! find final memory address, call bounds check function */
    /* ! splits current block right before detected mem instruction
     *   block iterator will return with new block detected mem instruction as first inst
     *    */
    void BoundsCheckPass::checkBounds( 
        analysis::DataflowGraph::iterator &block, 
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
        
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64 : ir::PTXOperand::u32);
        
        ir::PTXOperand ir::PTXInstruction:: *operands[] = {&ir::PTXInstruction::d,
            &ir::PTXInstruction::a, &ir::PTXInstruction::b, &ir::PTXInstruction::c};
        
        int opId = -1;
        
        report("checkBounds(loc = " << loc << ", instructions: " 
            << block->block()->instructions.size() << ")");
//        return;

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
                mask = 0x1;
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
                
                if( (memInst.*operands[opId]).offset > 0 )
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
                
                if( (memInst.*operands[opId]).offset > 0 )
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
                assert(false);
                break;
        }
        
        //finalAddr is found
        ir::PTXInstruction call(ir::PTXInstruction::Call);
        call.tailCall = false;
        call.branchTargetInstruction = -1;
        call.a = ir::PTXOperand(ir::PTXOperand::FunctionName, 
            getFuncName() );
        call.b = ir::PTXOperand(ir::PTXOperand::Indirect, type, finalAddr);
        call.d.addressMode = ir::PTXOperand::Invalid;
//        dfg().insert( block, call, loc++ );
        
        //get block pointer, insert instructions into it
        //transforms::BoundsCheckPass::_checkBounds(boundsCheckBlock);
        
        //loop over allocation map to see if address falls between one of the allocations
        /* 
         * set length = allocMap[0] length is # of allocations*2 (base, end)
         * check if (address >= allocMap[index+1] && address <= allocMap[index+2])
         * if so, branch out of instrumentation (ret?)
         * index+=2;
         * if index < length? branch back to loop begin
         * out of loop, error, store address + tid + whatever to global memory for report
        */ 
        //ld allocMap
        //ld size, [allocMap+0]
        //add size, allocMap, size

    //BeginLoop
        //setp.cmp.eq size, allocMap
        //%p bra error
    //check base address
        //ld base, [allocMap + 1*sizeof(size_t)]
        //setp.cmp.lt %p finalAddr, base
        //%p add allocMap, allocMap, 2*sizeof(size_t)
        //%p bra begin_loop
    //check end address
        //ld end, [allocMap + 2*sizeof(size_t)]
        //setp.cmp.le %p finalAddr, end
        //%p bra exit_label
    //end loop
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
         
        
        analysis::DataflowGraph::RegisterId allocMap = dfg().newRegister();
        analysis::DataflowGraph::RegisterId mapSize = dfg().newRegister();
//        analysis::DataflowGraph::RegisterId index = dfg().newRegister();
        analysis::DataflowGraph::RegisterId pred = dfg().newRegister();
        analysis::DataflowGraph::RegisterId base = dfg().newRegister();
        analysis::DataflowGraph::RegisterId end = dfg().newRegister();
        
        //ld.global.u64 %allocMap, [allocMapAddr]
        ir::PTXInstruction *ldMapAddr = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldMapAddr->d = ir::PTXOperand(ir::PTXOperand::Register, type, allocMap);
        ldMapAddr->a = ir::PTXOperand(ir::PTXOperand::Address, getAllocMap());
        ldMapAddr->type = type;
        ldMapAddr->addressSpace = ir::PTXInstruction::Global; 
        dfg().insert( block, *ldMapAddr, loc++ );
        
        //ld size, [allocMap+0]
        ir::PTXInstruction *ldMapSize = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldMapSize->d = ir::PTXOperand(ir::PTXOperand::Register, type, mapSize);
        ldMapSize->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, allocMap);
        ldMapSize->type = type;
        ldMapSize->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(ldMapSize);
        dfg().insert( block, *ldMapSize, loc++ );
        
        //add size, allocMap, size
        ir::PTXInstruction *addMapSize = new ir::PTXInstruction(ir::PTXInstruction::Add);
        addMapSize->type = type;
        addMapSize->d = ldMapSize->d;
        addMapSize->a = ldMapAddr->d;
        addMapSize->b = ldMapSize->d;
        dfg().insert( block, *addMapSize, loc++ );
        
    
        report(" spliting block with " << 
            block->block()->instructions.size() << " instructions");

        //begin_loop (or device function)
        //desired basic blocks:
        //predecessor -> blockBeginLoop -> blockBaseCheck -> blockEndCheck -> blockEndLoop -> errorBlock -> block
        
        std::string labelBeginLoop = block->label() + "_begin_loop";
        std::string labelBaseCheck = block->label() + "_base_check";
        std::string labelEndCheck = block->label() + "_end_check";
        std::string labelEndLoop = block->label() + "_end_loop";
        std::string labelError = block->label() + "_error";
        
        analysis::DataflowGraph::iterator predecessor = block;
        block = dfg().split(block, loc, true);
        
        analysis::DataflowGraph::iterator blockBeginLoop = 
            dfg().insert(predecessor, block, labelBeginLoop);
        analysis::DataflowGraph::iterator blockBaseCheck = 
            dfg().insert(blockBeginLoop, block, labelBaseCheck);
        analysis::DataflowGraph::iterator blockEndCheck = 
            dfg().insert(blockBaseCheck, block, labelEndCheck);
        analysis::DataflowGraph::iterator blockEndLoop = 
            dfg().insert(blockEndCheck, block, labelEndLoop);
        analysis::DataflowGraph::iterator blockError = 
            dfg().insert(blockEndLoop, block, labelError);


          
        ir::BasicBlock::Edge edgeBeginLoopToError = ir::BasicBlock::Edge(blockBeginLoop->block(), blockError->block(),  ir::BasicBlock::Edge::Branch);
        dfg().cfg()->insert_edge(edgeBeginLoopToError);
        
        ir::BasicBlock::Edge edgeBaseToLoop = ir::BasicBlock::Edge(blockBaseCheck->block(), blockBeginLoop->block(), ir::BasicBlock::Edge::Branch);
        dfg().cfg()->insert_edge(edgeBaseToLoop);
        
        //edge loop to loop is the backedge
        ir::BasicBlock::Edge edgeLoopToLoop = ir::BasicBlock::Edge(blockEndLoop->block(), blockBeginLoop->block(), ir::BasicBlock::Edge::Branch);
        dfg().cfg()->insert_edge(edgeLoopToLoop);

        ir::BasicBlock::Edge edgeEndCheckToNoError = ir::BasicBlock::Edge(blockEndCheck->block(), block->block(), ir::BasicBlock::Edge::Branch);
        dfg().cfg()->insert_edge(edgeEndCheckToNoError);
        
        //begin loop block (check size of array)
        loc = 0;

        //setp.cmp.eq size, map
        ir::PTXInstruction *setpLoopExit = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        setpLoopExit->comparisonOperator = ir::PTXInstruction::Lt;
        setpLoopExit->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
        setpLoopExit->a = ldMapSize->d;
        setpLoopExit->b = ldMapSize->a;
        setpLoopExit->type = type;
        dfg().insert( blockBeginLoop, *setpLoopExit, loc++ );

        //%p bra to error
        ir::PTXInstruction *braError = new ir::PTXInstruction(ir::PTXInstruction::Bra);
        braError->d = ir::PTXOperand( blockError->label() ); //labelError );
        braError->pg.condition = ir::PTXOperand::Pred;
        braError->pg.reg = pred;  
        dfg().insert( blockBeginLoop, *braError, loc++ );
    

        //check base address
        loc = 0;
        
        //ld base, [allocMap + 1*sizeof(size_t)]
        ir::PTXInstruction *ldBase = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldBase->d = ir::PTXOperand(ir::PTXOperand::Register, type, base);
        ldBase->a = ldMapAddr->d;
        ldBase->a.addressMode = ir::PTXOperand::Indirect;
        ldBase->a.offset = sizeof(size_t);
        ldBase->type = type;
        ldBase->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(ldBase);
        dfg().insert( blockBaseCheck, *ldBase, loc++ );
        
        //setp.cmp.lt %p finalAddr, base
        ir::PTXInstruction *setpCmpBase = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        setpCmpBase->comparisonOperator = ir::PTXInstruction::Lt;
        setpCmpBase->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
        setpCmpBase->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, finalAddr);
        setpCmpBase->b = ldBase->d;
        setpCmpBase->type = type;
//        block->instructions.push_back(setpCmpBase);
        dfg().insert( blockBaseCheck, *setpCmpBase, loc++ );
        
        //%p add allocMap, allocMap, 2*sizeof(size_t)
        ir::PTXInstruction *addMapPtr = new ir::PTXInstruction(ir::PTXInstruction::Add);
        addMapPtr->type = type;
        addMapPtr->d = ldMapAddr->d;
        addMapPtr->a = ldMapAddr->d;
        addMapPtr->b.addressMode = ir::PTXOperand::Immediate;
        addMapPtr->b.imm_uint = 2*sizeof(size_t); 
        addMapPtr->pg.condition = ir::PTXOperand::Pred;
        addMapPtr->pg.reg = pred;  
//        block->instructions.push_back(addMapPtr);
        dfg().insert( blockBaseCheck, *addMapPtr, loc++ );
        
        //%p bra begin_loop
        ir::PTXInstruction *braLoopBegin = new ir::PTXInstruction(ir::PTXInstruction::Bra);
        braLoopBegin->d = ir::PTXOperand( labelBeginLoop );
        braLoopBegin->pg.condition = ir::PTXOperand::Pred;
        braLoopBegin->pg.reg = pred;  
//        block->instructions.push_back(braLoopBegin);
        dfg().insert( blockBaseCheck, *braLoopBegin, loc++ );
        

        //check end address of allocation
        loc = 0;
        
        //ld end, [allocMap + 2*sizeof(size_t)]
        ir::PTXInstruction *ldEnd = new ir::PTXInstruction(ir::PTXInstruction::Ld);
        ldEnd->d = ir::PTXOperand(ir::PTXOperand::Register, type, end);
        ldEnd->a = ldMapAddr->d;
        ldEnd->a.addressMode = ir::PTXOperand::Indirect;
        ldEnd->a.offset = 2*sizeof(size_t);
        ldEnd->type = type;
        ldEnd->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(ldEnd);
        dfg().insert( blockEndCheck, *ldEnd, loc++ );
        
        //setp.cmp.lt %p finalAddr, end
        ir::PTXInstruction *setpCmpEnd = new ir::PTXInstruction(ir::PTXInstruction::SetP);
        setpCmpEnd->comparisonOperator = ir::PTXInstruction::Lt;
        setpCmpEnd->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
        setpCmpEnd->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, finalAddr);
        setpCmpEnd->b = ldEnd->d;
        setpCmpEnd->type = type;
//        block->instructions.push_back(setpCmpEnd);
        dfg().insert( blockEndCheck, *setpCmpEnd, loc++ );
        
        //%p bra exit_label or no _error
        ir::PTXInstruction *braLoopExit = new ir::PTXInstruction(ir::PTXInstruction::Bra);
        braLoopExit->d = ir::PTXOperand( block->label());
        braLoopExit->pg.condition = ir::PTXOperand::Pred;
        braLoopExit->pg.reg = pred;  
//        block->instructions.push_back(braLoopExit);
        dfg().insert( blockEndCheck, *braLoopExit, loc++ );

#if 1
        //end loop
        loc = 0;
        
        //add allocMap, allocMap, 2*sizeof(size_t)
        ir::PTXInstruction *addMapPtr2 = new ir::PTXInstruction(ir::PTXInstruction::Add);
        addMapPtr2->type = type;
        addMapPtr2->d = ldMapAddr->d;
        addMapPtr2->a = ldMapAddr->d;
        addMapPtr2->b.addressMode = ir::PTXOperand::Immediate;
        addMapPtr2->b.imm_uint = 2*sizeof(size_t); 
        dfg().insert( blockEndLoop, *addMapPtr2, loc++ );
        
        //bra begin_loop
        ir::PTXInstruction *braLoopBegin2 = new ir::PTXInstruction(ir::PTXInstruction::Bra);
        braLoopBegin2->d = ir::PTXOperand( labelBeginLoop );
        dfg().insert( blockEndLoop, *braLoopBegin2, loc++ );

#endif

        //error_label
        loc = 0;
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
        dfg().insert( blockError, *cvtTidX, loc++ );
	    
        //@%p st.global.u64 [reportInfoAddr + 0], tidX
        ir::PTXInstruction *stTidX = new ir::PTXInstruction(ir::PTXInstruction::St);
        stTidX->type = type;
        stTidX->d = ir::PTXOperand(ir::PTXOperand::Indirect, type, registerMap["counterPtrReg"] ); //reportInfo
        stTidX->a = ir::PTXOperand(ir::PTXOperand::Register, type, tidX);
        stTidX->addressSpace = ir::PTXInstruction::Global; 
        dfg().insert( blockError, *stTidX, loc++ );
        
        //        @%p st.global.u64 [reportInfoAddr + 1], finalAddr
        ir::PTXInstruction *stAddr = new ir::PTXInstruction(ir::PTXInstruction::St);
        stAddr->type = type;
        stAddr->d = ir::PTXOperand(ir::PTXOperand::Indirect, type, registerMap["counterPtrReg"] ); //reportInfo
        stAddr->d.offset = sizeof(size_t);
        stAddr->a = ir::PTXOperand(ir::PTXOperand::Register, type, finalAddr);
        stAddr->addressSpace = ir::PTXInstruction::Global; 
        dfg().insert( blockError, *stAddr, loc++ );
        
        //ret
        ir::PTXInstruction *ret = new ir::PTXInstruction(ir::PTXInstruction::Ret);        
        dfg().insert( blockError, *ret, loc++ );
        
    }
    
    
    
    
    //inserts kernel that actually check bounds
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
        
//        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
//        
//        analysis::DataflowGraph::RegisterId allocMap = dfg().newRegister();
//        analysis::DataflowGraph::RegisterId mapSize = dfg().newRegister();
//        analysis::DataflowGraph::RegisterId index = dfg().newRegister();
//        analysis::DataflowGraph::RegisterId pred = dfg().newRegister();
//        analysis::DataflowGraph::RegisterId base = dfg().newRegister();
//        analysis::DataflowGraph::RegisterId end = dfg().newRegister();
//        
//        //ld.global.u64 %allocMap, [allocMapAddr]
//        ir::PTXInstruction *ldMapAddr = new ir::PTXInstruction(ir::PTXInstruction::Ld);
//        ldMapAddr->d = ir::PTXOperand(ir::PTXOperand::Register, type, allocMap);
//        ldMapAddr->a = ir::PTXOperand(ir::PTXOperand::Address, getAllocMap());
////        ldMapAddr->a.offset = 0;
//        ldMapAddr->type = type;
//        ldMapAddr->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(ldMapAddr);
//        
//        //ld size, [allocMap+0]
//        ir::PTXInstruction *ldMapSize = new ir::PTXInstruction(ir::PTXInstruction::Ld);
//        ldMapSize->d = ir::PTXOperand(ir::PTXOperand::Register, type, mapSize);
//        ldMapSize->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, allocMap);
//        ldMapSize->type = type;
//        ldMapSize->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(ldMapSize);
//        
//        // mov index, 1 (0 is reserved for size of allocMap)
//        ir::PTXInstruction *movIndex = new ir::PTXInstruction(ir::PTXInstruction::Mov);
//        movIndex->d = ir::PTXOperand(ir::PTXOperand::Register, type, index);
//        movIndex->a.addressMode = ir::PTXOperand::Immediate;
//        movIndex->a.imm_uint = sizeof(size_t); 
//        block->instructions.push_back(movIndex);

//        //begin_loop
//        //how to insert label?

//        
//        //setp.cmp.eq size, 0
//        ir::PTXInstruction *setpLoopExit = new ir::PTXInstruction(ir::PTXInstruction::SetP);
//        setpLoopExit->comparisonOperator = ir::PTXInstruction::Eq;
//        setpLoopExit->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
//        setpLoopExit->a = ldMapSize->d;
//        setpLoopExit->b.addressMode = ir::PTXOperand::Immediate;
//        setpLoopExit->b.imm_uint = 0; 
//        setpLoopExit->type = type;
//        block->instructions.push_back(setpLoopExit);
//        
//        //%p bra error
//        ir::PTXInstruction *braError = new ir::PTXInstruction(ir::PTXInstruction::SetP);
//        braError->d = ir::PTXOperand("exitLabel");
//        braError->pg.condition = ir::PTXOperand::Pred;
//        braError->pg.reg = pred;  
//        block->instructions.push_back(braError);
//        
//        //sub size, size, 2              //for next iteration
//        ir::PTXInstruction *subSize = new ir::PTXInstruction(ir::PTXInstruction::Sub);
//        subSize->d = ldMapSize->d;
//        subSize->a = ldMapSize->d;
//        subSize->b.addressMode = ir::PTXOperand::Immediate;
//        subSize->b.imm_uint = 2; 
//        block->instructions.push_back(subSize);
//        
//        //ld base, [allocMap + 1*sizeof(size_t)]
//        ir::PTXInstruction *ldBase = new ir::PTXInstruction(ir::PTXInstruction::Ld);
//        ldBase->d = ir::PTXOperand(ir::PTXOperand::Register, type, base);
//        ldBase->a = ldMapAddr->d;
//        ldBase->a.offset = sizeof(size_t);
//        ldBase->type = type;
//        ldBase->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(ldBase);
//        
//        //setp.cmp.lt %p finalAddr, base
//        ir::PTXInstruction *setpCmpBase = new ir::PTXInstruction(ir::PTXInstruction::SetP);
//        setpCmpBase->comparisonOperator = ir::PTXInstruction::Lt;
//        setpCmpBase->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
//        setpCmpBase->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, finalAddr);
//        setpCmpBase->b = ldBase->d;
//        setpCmpBase->type = type;
//        block->instructions.push_back(setpCmpBase);
//        
//        //%p add allocMap, allocMap, 2*sizeof(size_t)
//        ir::PTXInstruction *addMapPtr = new ir::PTXInstruction(ir::PTXInstruction::Add);
//        addMapPtr->d = ldMapAddr->d;
//        addMapPtr->a = ldMapAddr->d;
//        addMapPtr->b.addressMode = ir::PTXOperand::Immediate;
//        addMapPtr->b.imm_uint = 2*sizeof(size_t); 
//        addMapPtr->pg.condition = ir::PTXOperand::Pred;
//        addMapPtr->pg.reg = pred;  
//        block->instructions.push_back(addMapPtr);
//        
//        //%p bra begin_loop
//        ir::PTXInstruction *braLoopBegin = new ir::PTXInstruction(ir::PTXInstruction::SetP);
//        braLoopBegin->d = ir::PTXOperand("loopBeginLabel");
//        braLoopBegin->pg.condition = ir::PTXOperand::Pred;
//        braLoopBegin->pg.reg = pred;  
//        block->instructions.push_back(braLoopBegin);
//        
//        //ld end, [allocMap + 2*sizeof(size_t)]
//        ir::PTXInstruction *ldEnd = new ir::PTXInstruction(ir::PTXInstruction::Ld);
//        ldEnd->d = ir::PTXOperand(ir::PTXOperand::Register, type, end);
//        ldEnd->a = ldMapAddr->d;
//        ldEnd->a.offset = 2*sizeof(size_t);
//        ldEnd->type = type;
//        ldEnd->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(ldEnd);
//        
//        //setp.cmp.le %p finalAddr, end
//        ir::PTXInstruction *setpCmpEnd = new ir::PTXInstruction(ir::PTXInstruction::SetP);
//        setpCmpEnd->comparisonOperator = ir::PTXInstruction::Le;
//        setpCmpEnd->d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, pred);
//        setpCmpEnd->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, finalAddr);
//        setpCmpEnd->b = ldEnd->d;
//        setpCmpEnd->type = type;
//        block->instructions.push_back(setpCmpEnd);
//        
//        //%p bra exit_label
//        ir::PTXInstruction *braLoopExit = new ir::PTXInstruction(ir::PTXInstruction::SetP);
//        braLoopExit->d = ir::PTXOperand("loopExitLabel");
//        braLoopExit->pg.condition = ir::PTXOperand::Pred;
//        braLoopExit->pg.reg = pred;  
//        block->instructions.push_back(braLoopExit);
//        
//        //add allocMap, allocMap, 2*sizeof(size_t)
//        ir::PTXInstruction *addMapPtr2 = new ir::PTXInstruction(ir::PTXInstruction::Add);
//        addMapPtr2->d = ldMapAddr->d;
//        addMapPtr2->a = ldMapAddr->d;
//        addMapPtr2->b.addressMode = ir::PTXOperand::Immediate;
//        addMapPtr2->b.imm_uint = 2*sizeof(size_t); 
//        block->instructions.push_back(addMapPtr2);
//        
//        //bra begin_begin
//        ir::PTXInstruction *braLoopBegin2 = new ir::PTXInstruction(ir::PTXInstruction::SetP);
//        braLoopBegin2->d = ir::PTXOperand("loopBeginLabel");
//        block->instructions.push_back(braLoopBegin2);
//        
//        //error_label
//        
//        
//        //ld idx
//        //ld instruction #
//        //st idx
//        //st instruction #
//        //st space
//        //st finalAddr
//        //st anything else into global error reporting memory
//        
//        //find thread id: x, y, z, blockx, blocky, blockz
//        analysis::DataflowGraph::RegisterId tidX = dfg().newRegister();

//        ir::PTXInstruction *cvtTidX = new ir::PTXInstruction(ir::PTXInstruction::Cvt);
//        cvtTidX->type = type;
//        cvtTidX->d = ir::PTXOperand(ir::PTXOperand::Register, type, tidX);
//        cvtTidX->a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
//        cvtTidX->a.addressMode = ir::PTXOperand::Special;
//        cvtTidX->a.vec = ir::PTXOperand::v1;
//        
//        block->instructions.push_back(cvtTidX);
//        
//        //ld.global.u64 %reportInfo, [reportinfoaddr]
//        analysis::DataflowGraph::RegisterId reportInfo = dfg().newRegister();
//        
//        ir::PTXInstruction *ldReportInfo = new ir::PTXInstruction(ir::PTXInstruction::Ld);
//        ldReportInfo->d = ir::PTXOperand(ir::PTXOperand::Register, type, reportInfo);
//        ldReportInfo->a = ir::PTXOperand(ir::PTXOperand::Indirect, type, kernelReportInfo() );
//        ldReportInfo->a.offset = 0;
//        ldReportInfo->addressSpace = ir::PTXInstruction::Global; 
//        
//        block->instructions.push_back(ldReportInfo);
//        
//        //@%p st.global.u64 [reportInfoAddr + 0], tidX
//        ir::PTXInstruction *stTidX = new ir::PTXInstruction(ir::PTXInstruction::St);
//        stTidX->d = ir::PTXOperand(ir::PTXOperand::Indirect, type, registerMap["counterPtrReg"] ); //reportInfo
//        stTidX->a = ir::PTXOperand(ir::PTXOperand::Register, type, tidX);
//        stTidX->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(stTidX);
//        
//        //        @%p st.global.u64 [reportInfoAddr + 1], finalAddr
//        ir::PTXInstruction *stAddr = new ir::PTXInstruction(ir::PTXInstruction::St);
//        stAddr->d = ir::PTXOperand(ir::PTXOperand::Indirect, type, registerMap["counterPtrReg"] ); //reportInfo
//        stAddr->d.offset = sizeof(size_t);
//        stAddr->a = ir::PTXOperand(ir::PTXOperand::Register, type, finalAddr);
//        stAddr->addressSpace = ir::PTXInstruction::Global; 
//        block->instructions.push_back(stAddr);
//        
//        //@%p st.global.u64 [reportInfoAddr + 2], offset
////        ir::PTXInstruction *stPC = new ir::PTXInstruction(ir::PTXInstruction::St);
////        stPC->d = ir::PTXOperand(ir::PTXOperand::Indirect, type, registerMap["counterPtrReg"] ); //reportInfo
////        stPC->d.offset = sizeof(size_t);
////        stPC->a = ir::PTXOperand(ir::PTXOperand::Register, type, PC);
////        stPC->addressSpace = ir::PTXInstruction::Global; 
////        block->instructions.push_back(stPC);

//        //ret
//        ir::PTXInstruction ret(ir::PTXInstruction::Ret);        
//        block->instructions.push_back(&ret);
    }
    
    BoundsCheckPass::BoundsCheckPass() : entries(2)
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

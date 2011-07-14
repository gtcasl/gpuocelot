/*! \file CToPTXTranslator.cpp
	\date Wednesday June 8, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the CToPTXTranslator class
*/

#ifndef C_TO_PTX_TRANSLATOR_CPP_INCLUDED
#define C_TO_PTX_TRANSLATOR_CPP_INCLUDED

#include <ocelot/translator/interface/CToPTXTranslator.h>
#include <ocelot/translator/interface/CToPTXInterface.h>

#include <boost/lexical_cast.hpp>

#define REG         "r"
#define COD_REG     "\%codr"
#define COD_PRED    "\%codp"

namespace translator
{

    std::string arith3_name[] = {"addi", "addu", "addul", "addl", "subi", "subu", "subul", "subl", "muli", "mulu", "mulul", "mull", "divi", "divu", "divul", "divl", "modi",        "modu", "modul", "modl", "xori", "xoru", "xorul", "xorl", "andi", "andu", "andul", "andl", "ori", "oru", "orul", "orl", "lshi", "lshu", "lshul", "lshl", "rshi", "rshu", "rshul", "rshl", "addp", "subp", "addf", "addd", "subf", "subd", "mulf", "muld", "divf", "divd"};

    std::string branch_op_names[] = {"eqc", "equc", "eqs", "equs", "eqi", "equ", "eql", "equl", "eqp", "eqf", "eqd", "gec", "geuc", "ges", "geus", "gei", "geu", "gel", "geul", "gep", "gef", "ged", "gtc", "gtuc", "gts", "gtus", "gti", "gtu", "gtl", "gtul", "gtp", "gtf", "gtd", "lec", "leuc", "les", "leus", "lei", "leu", "lel", "leul", "lep", "lef", "led", "ltc", "ltuc", "lts", "ltus", "lti", "ltu", "ltl", "ltul", "ltp", "ltf", "ltd", "nec", "neuc", "nes", "neus", "nei", "neu", "nel", "neul", "nep", "nef", "ned"};

    translator::CToPTXTranslator translator;

    void foreign_code_generator(dill_stream s, virtual_insn *start, virtual_insn *end)
    {
        void *info;
        void *base = s->p->code_base;
        if (base == NULL) {
	        base = s->p->native.code_base;
        }
        if (base == NULL) {
	        return;
        }
     
        void *p;
	    int l;
	    int insn_count = 0;

	    if ((s->j != s->p->_virtual.mach_jump) && (s->p->fp != NULL) )
	        base = s->p->fp;
	
	    for (p =base; (char*) p < s->p->cur_ip;) {
	      
	        l = translator.translate(s, &info, (void *)p);
	        l = s->j->print_insn(s, &info, (void *)p);
	        printf("\n");
	        if (l <= 0) return;
	        p = (char*)p + l;
	        insn_count++;
	    }
    }


    std::string CToPTXTranslator::baseAddress() const
	{
		return "__ocelot_base_address_";
	}

    void CToPTXTranslator::setPredicate(ir::PTXInstruction & instruction) {

        for (PredicateList::const_iterator pred = predicateList.begin(); 
	        pred != predicateList.end(); ++pred) {

            if(pred->set && (instruction.opcode == ir::PTXInstruction::St || instruction.opcode == ir::PTXInstruction::Ld)){
                instruction.pg.condition = ir::PTXOperand::Pred;
                instruction.pg.identifier = pred->id;
                instruction.pg.type = ir::PTXOperand::pred;
                instruction.pg.addressMode = ir::PTXOperand::Register;
            }
                     
        }
    }
    
    void CToPTXTranslator::generateBlockId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;  

        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ctaidX = inst.d.identifier;

        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ctaidY = inst.d.identifier;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string nctaidX = inst.d.identifier;		 
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ctaid = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = ctaidY;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = nctaidX;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = ctaidX;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        registers.push_back(ctaidX);
        registers.push_back(ctaidY);
        registers.push_back(nctaidX);
        registers.push_back(ctaid);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = ctaid;
    
    }
    
    void CToPTXTranslator::generateSMId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;
        setPredicate(inst);
        
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a = ir::PTXOperand(ir::PTXOperand::smId);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.type = ir::PTXOperand::u32;
        
        stmt.instruction = inst;
        statements.push_back(stmt);        
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;    
    
    }
    
    void CToPTXTranslator::generateClockCounter(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.type = ir::PTXOperand::u64;
        inst.d.type = ir::PTXOperand::u64;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a = ir::PTXOperand(ir::PTXOperand::clock64);
        inst.a.type = ir::PTXOperand::u64;

        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);	
        registers.push_back(inst.d.identifier);	      
                  
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);        
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;        
    }
    
    void CToPTXTranslator::generateThreadIndexX(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;
        setPredicate(inst);

        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        
        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        statements.push_back(stmt);        
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;    
    }
    
    void CToPTXTranslator::generateBlockDim(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;  

        inst.d.addressMode = ir::PTXOperand::Register;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ntidX = inst.d.identifier;

        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ntidY = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iz, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ntidZ = inst.d.identifier;		 
        
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ntid = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = ntidX;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = ntidY;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = ntid;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = ntidZ;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = ntid;
        
        specialRegisterMap["ntid"] = ntid;
        specialRegisterMap["ntidX"] = ntidX;
        specialRegisterMap["ntidY"] = ntidY;
        specialRegisterMap["ntidZ"] = ntidZ;
    }

    void CToPTXTranslator::generateGlobalThreadId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        if(specialRegisterMap["ntidX"].empty())
            generateBlockDim(inst, stmt, type, insn);        
    
        inst.opcode = ir::PTXInstruction::Cvt;  

        inst.d.addressMode = ir::PTXOperand::Register;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string tidX = inst.d.identifier;

        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string tidY = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iz, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string tidZ = inst.d.identifier;		 
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ctaidX = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ctaidY = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string nctaidX = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        //mad tid.y * ntid.x + tid.x
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string madA = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = tidY;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidX"];
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = tidX;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        //mul ntid.x * ntid.y * tid.z
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string mulA = inst.d.identifier;	 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = specialRegisterMap["ntidX"];
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidY"];
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a.identifier = inst.d.identifier;
        inst.b.identifier = tidZ;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        
        //add (tid.y * ntid.x + tid.x) + (ntid.x * ntid.y * tid.z)
        inst.opcode = ir::PTXInstruction::Add;     
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        setPredicate(inst);
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string tid = inst.d.identifier;	 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = madA;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = mulA;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        //mad ctaid.y * nctaid.x + ctaid.x
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string madB = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = ctaidY;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = nctaidX;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = ctaidX;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        //mad ntid * (ctaid.y * nctaid.x + ctaid.x) + tid
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string globalThreadId = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = mulA;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = madB;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = tid;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);    
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;  
        
        specialRegisterMap["threadId"] = globalThreadId;
    }
    
    void CToPTXTranslator::generateSyncThreads(ir::PTXInstruction inst, ir::PTXStatement stmt)
    {
        inst.opcode = ir::PTXInstruction::Bar;
        setPredicate(inst);

        inst.d.addressMode = ir::PTXOperand::Immediate;
        inst.d.imm_int = 0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
    }
    
    void CToPTXTranslator::generateBasicBlockConstructs(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, std::string callName)
    {
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = callName;
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier; 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
    }
    

    int CToPTXTranslator::translate(dill_stream c, void *info_ptr, void *i)
    {
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        
        virtual_insn *insn = (virtual_insn *)i;
        
        ir::PTXInstruction inst;
        ir::PTXStatement stmt;
        
        stmt.directive = ir::PTXStatement::Instr;
        
        inst.type = type;
        
        switch(insn->class_code) {
        case iclass_lea:
        {
            ir::PTXStatement global(ir::PTXStatement::Global);
            global.name = baseAddress() + boost::lexical_cast<std::string>(insn->opnds.a3.src1);;
            global.type = type;
            globals.push_back(global);
            
            inst.opcode = ir::PTXInstruction::Mov;
                 
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
                 
            inst.d.type = type;          
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.identifier = global.name;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Address;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);     

            inst.opcode = ir::PTXInstruction::Ld;
            
            inst.addressSpace = ir::PTXInstruction::Global; 
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.type = type;
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            inst.a.identifier = statements.back().instruction.d.identifier;
            inst.a.addressMode = ir::PTXOperand::Indirect;
            
            baseReg = inst.d.identifier;
            registers.push_back(inst.d.identifier);
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);
            
            break;
        }
        
        case iclass_set:
        {
            inst.opcode = ir::PTXInstruction::Mov;
            inst.d.type = type;
       
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
            
            registerMap[(REG + boost::lexical_cast<std::string>(insn->opnds.a3i.dest))] = inst.d.identifier;
                      
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Immediate;
            inst.a.imm_int = insn->opnds.a3i.u.imm;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);     

            break;
        }
        case iclass_mov:
        {
            std::string src1 = (REG + boost::lexical_cast<std::string>(insn->opnds.a2.src));
        
            std::map<std::string,std::string>::iterator it = registerMap.find(src1);
            if(it != registerMap.end()) {
                registerMap[(REG + boost::lexical_cast<std::string>(insn->opnds.a2.dest))] = it->second;
                registerMap.erase(src1);
            }

            break;
        }
        case iclass_arith3:
        case iclass_arith3i:
        {
            std::string src1, src2;
            
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.addressMode = ir::PTXOperand::Register;
            inst.b.addressMode = ir::PTXOperand::Register;
            
            inst.d.type = type;
            inst.a.type = type;
            inst.b.type = type;
        
            if(insn->class_code == iclass_arith3){
                src1 = REG + boost::lexical_cast<std::string>(insn->opnds.a3.src1);
                src2 = REG + boost::lexical_cast<std::string>(insn->opnds.a3.src2);
            }
            else {
                inst.b.addressMode = ir::PTXOperand::Immediate;
                src1 = REG + boost::lexical_cast<std::string>(insn->opnds.a3i.src);
                inst.b.imm_int = insn->opnds.a3i.u.imm;
            }
        
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
            
            inst.a.identifier = registerMap[src1];	
            inst.b.identifier = registerMap[src2];	
            
            registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.a3.dest)] = inst.d.identifier;
            
            if(arith3_name[(unsigned int)insn->insn_code].find("add") != std::string::npos){

                inst.opcode = ir::PTXInstruction::Add;
            }
            else if(arith3_name[(unsigned int)insn->insn_code].find("sub") != std::string::npos){
                
                inst.opcode = ir::PTXInstruction::Sub;
            }
            else if(arith3_name[(unsigned int)insn->insn_code].find("mul") != std::string::npos){
                
                inst.opcode = ir::PTXInstruction::Mul;
                inst.modifier = ir::PTXInstruction::lo;
            }
            else if(arith3_name[(unsigned int)insn->insn_code].find("div") != std::string::npos){
                
                inst.opcode = ir::PTXInstruction::Div;
                inst.modifier = ir::PTXInstruction::lo;
            }
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);     
            
            break;
        }
        case iclass_call:
        {
            std::string call_name = insn->opnds.calli.xfer_name;
            if(!call_name.empty() && functionCalls.find(call_name) != functionCalls.end()){
                        
                       
                switch(functionCalls[call_name]) {
                    case ctaid:
                    {  
                        generateBlockId(inst, stmt, type, insn);
                    }
                    break;                  
                    case smid:
                    {    
                        generateSMId(inst, stmt, type, insn);
                    }            
                    break;
                    case clock64:
                    {   
                        generateClockCounter(inst, stmt, type, insn);    
                    }
                    break;
                    case bar:
                    {
                        
                        generateSyncThreads(inst, stmt);
                    }
                    break;
                    case tidx:
                    {
                        generateThreadIndexX(inst, stmt, type, insn);      
                    }
                    break;
                    case ntid:
                    {
                        generateBlockDim(inst, stmt, type, insn);
                    }
                    break;
                    case threadCounter: 
                    {
                        generateGlobalThreadId(inst, stmt, type, insn);
                    
                    }
                    break;
                    case basic_block_id:
                    case basic_block_size: 
                    {
                        generateBasicBlockConstructs(inst, stmt, type, insn, call_name);
                    }
                    break;
                    default:
                    break;
                }
            }
        
            break;
        }
        case iclass_branch:
        {
         
	        inst.opcode = ir::PTXInstruction::SetP;
            
            inst.d.type = ir::PTXOperand::pred;
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
            registers.push_back(inst.d.identifier);
            
            inst.comparisonOperator = ir::PTXInstruction::Eq;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Register;
            inst.a.identifier = registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.br.src1)];
            inst.b.type = type;
            inst.b.addressMode = ir::PTXOperand::Register;
            inst.b.identifier = registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.br.src2)];
            
	        PredicateInfo predicateInfo;
	        predicateInfo.id = inst.d.identifier;
	        
	        std::string label;
	        
	        int br_op = insn->insn_code;
	        struct branch_table *t = &c->p->branch_table;
            
            if (t->label_name[insn->opnds.br.label] != NULL) {
	            label = t->label_name[insn->opnds.label.label];
	        }
	        else {
	            label = "L" + boost::lexical_cast<std::string>(insn->opnds.br.label);
	        }
	        
	        predicateInfo.branchLabel = label;
	       
	        if(br_op >= 55 && br_op < 66){
	            predicateInfo.condition = PredicateInfo::NOT_TAKEN;
	            predicateInfo.set = true;
	        }
	        else if(br_op >= 0 && br_op < 11){
	            predicateInfo.condition = PredicateInfo::TAKEN;
	            predicateInfo.set = false;
	        }
	        
	        
	        stmt.instruction = inst;
	        statements.push_back(stmt);
	          
	        predicateList.push_back(predicateInfo);  
	          
            break;
        }
       
        case iclass_loadstore:
        case iclass_loadstorei:
        {
            std::string src1, dst;
        
            if(insn->class_code == iclass_loadstorei)
            {
                src1 = REG + boost::lexical_cast<std::string>(insn->opnds.a3i.src);
                dst = REG + boost::lexical_cast<std::string>(insn->opnds.a3i.dest);
                inst.d.offset = insn->opnds.a3i.u.imm;
            }
            
            inst.addressSpace = ir::PTXInstruction::Global; 
            inst.type = type;
            
	        int store = (insn->insn_code & 0x10) && 0x10;
	        if(store) {
	            
	            inst.opcode = ir::PTXInstruction::St;
	            
                inst.d.identifier = registerMap[src1];		
                inst.a.identifier = registerMap[dst];	
                
                inst.d.addressMode = ir::PTXOperand::Indirect;
                inst.a.addressMode = ir::PTXOperand::Register;
                inst.a.type = type;
	        }
	        else {
	            
	            inst.opcode = ir::PTXInstruction::Ld;
	            
                inst.a.identifier = registerMap[src1];		
                inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
                registers.push_back(inst.d.identifier);
                
                registerMap[dst] = inst.d.identifier;
                
                inst.a.addressMode = ir::PTXOperand::Indirect;
                inst.d.addressMode = ir::PTXOperand::Register;
                inst.d.type = type;
	        }
	           
	        ir::PTXInstruction prev = statements.back().instruction;
	        
            if(prev.opcode == ir::PTXInstruction::Add && (prev.d.identifier == inst.d.identifier || prev.d.identifier == inst.a.identifier)) {
                prev.b.addressMode = ir::PTXOperand::Register;
                prev.b.identifier = baseReg;
                statements.pop_back();
                stmt.instruction = prev;
                statements.push_back(stmt);
            }
               
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);   
	           
            break;
        }
        case iclass_mark_label:
        {
            std::string label;
            
            struct branch_table *t = &c->p->branch_table;
            if (t->label_name[insn->opnds.label.label] != NULL) {
	            label = t->label_name[insn->opnds.label.label];
	        }
	        else {
	            label = "L" + boost::lexical_cast<std::string>(insn->opnds.label.label);
	        }

            stmt.directive = ir::PTXStatement::Label;
            stmt.name = label;
            statements.push_back(stmt);
            
            for (PredicateList::iterator pred = predicateList.begin(); 
	        pred != predicateList.end(); ++pred) {
            
                if(pred->branchLabel == stmt.name){ 
                    if(pred->condition == PredicateInfo::TAKEN){
                        pred->set = true;
                    }
                    else {
                        pred->set = false;
                    }
                }
            }
        
	        break;
        }
        
	    case iclass_push:
        case iclass_pushi:
        case iclass_pushf:
        case iclass_nop:
	        break;
        }
        
        return sizeof(*insn);
    }
    
    CToPTXData CToPTXTranslator::generate(std::string resource) {
    
        
        std::string code;
        std::string line;
        std::ifstream codeFile( resource );

        if(codeFile.is_open()){
            while(codeFile.good()){
                getline(codeFile, line);
                code.append(line + "\n");
            }
            codeFile.close();
        }
        
	    cod_parse_context context;
	    cod_exec_context ec;
	
	    static char extern_string[] =  "unsigned long clockCounter();\
                                        unsigned long threadId();\
                                        unsigned long threadIdxX();\
                                        unsigned long threadIdxY();\
                                        unsigned long threadIdxZ();\
                                        unsigned long blockIdx();\
                                        unsigned long blockIdxX();\
                                        unsigned long blockIdxY();\
                                        unsigned long blockIdxZ();\
                                        unsigned long blockDim();\
                                        unsigned long blockDimX();\
                                        unsigned long blockDimY();\
                                        unsigned long blockDimZ();\
                                        unsigned long gridDim();\
                                        unsigned long gridDimX();\
                                        unsigned long gridDimY();\
                                        unsigned long gridDimZ();\
                                        unsigned long gridId();\
                                        unsigned long smId();\
                                        void syncThreads();\
                                        unsigned long basicBlockId();\
                                        unsigned long instructionsPerBasicBlock();\
                                        unsigned long deviceMem[2];";
                        
	    static cod_extern_entry externs[] = 
	    {
	        {(char *)"clockCounter", (void*)(unsigned long)(*clockCounter)},
	        {(char *)"threadId", (void*)(unsigned long)(*threadId)},
	        {(char *)"threadIdxX", (void*)(unsigned long)(*threadIdxX)},
	        {(char *)"threadIdxY", (void*)(unsigned long)(*threadIdxY)},
	        {(char *)"threadIdxZ", (void*)(unsigned long)(*threadIdxZ)},
	        {(char *)"blockIdx", (void*)(unsigned long)(*blockIdx)},
	        {(char *)"blockIdxX", (void*)(unsigned long)(*blockIdxX)},
	        {(char *)"blockIdxY", (void*)(unsigned long)(*blockIdxY)},
	        {(char *)"blockIdxZ", (void*)(unsigned long)(*blockIdxZ)},
	        {(char *)"blockDim", (void*)(unsigned long)(*blockDim)},
	        {(char *)"blockDimX", (void*)(unsigned long)(*blockDimX)},
	        {(char *)"blockDimY", (void*)(unsigned long)(*blockDimY)},
	        {(char *)"blockDimZ", (void*)(unsigned long)(*blockDimZ)},
	        {(char *)"gridDim", (void*)(unsigned long)(*gridDim)},
	        {(char *)"gridDimX", (void*)(unsigned long)(*gridDimX)},
	        {(char *)"gridDimY", (void*)(unsigned long)(*gridDimY)},
	        {(char *)"gridDimZ", (void*)(unsigned long)(*gridDimZ)},
            {(char *)"gridId", (void*)(unsigned long)(*gridId)},
            {(char *)"smId", (void*)(unsigned long)(*smId)},
            {(char *)"syncThreads", (void *)(*syncThreads)},
            {(char *)"basicBlockId", (void*)(unsigned long)(*basicBlockId)},
            {(char *)"instructionsPerBasicBlock", (void*)(unsigned long)(*instructionsPerBasicBlock)},
            {(char *)"deviceMem", (void *)deviceMem},
	        {NULL, (void*)0}
	    };
     
     
        cod_code gen_code;
	    void (*func)();
	
	    dill_set_foreign_cg(foreign_code_generator);

	    context = new_cod_parse_context();
	    cod_assoc_externs(context, externs);
	    cod_parse_for_context(extern_string, context);
	    gen_code = cod_code_gen((char *)code.c_str(), context);
	    ec = cod_create_exec_context(gen_code);
	    func = (void(*)()) gen_code->func;
        
        
	    cod_exec_context_free(ec);
	    cod_code_free(gen_code);
	    cod_free_parse_context(context);
	    
	    CToPTXData data;
	    
	    data.statements = translator.statements;
	    data.globals = translator.globals;
	    data.registers = translator.registers;
	    
	    return data;
    }
    
    CToPTXTranslator::CToPTXTranslator()
        : maxRegister(0), maxPredicate(0)
    {
        functionCalls["clockCounter"] = clock64;
        functionCalls["threadId"] = threadCounter;
        functionCalls["threadIdxX"] = tidx;
        functionCalls["threadIdxY"] = tidy;
        functionCalls["threadIdxZ"] = tidz;
        functionCalls["threadIdx"] = tid;
        functionCalls["blockDimX"] = ntidx;
        functionCalls["blockDimY"] = ntidy;
        functionCalls["blockDimZ"] = ntidz;
        functionCalls["blockDim"] = ntid;
        functionCalls["blockIdxX"] = ctaidx;
        functionCalls["blockIdxY"] = ctaidy;
        functionCalls["blockIdxZ"] = ctaidz;
        functionCalls["blockIdx"] = ctaid;
        functionCalls["gridDimX"] = nctaidx;
        functionCalls["gridDimY"] = nctaidy;
        functionCalls["gridDimZ"] = nctaidz;
        functionCalls["gridDim"] = nctaid;
        functionCalls["gridId"] = gridid;
        functionCalls["smId"] = smid;
        functionCalls["syncThreads"] = bar;
        functionCalls["basicBlockId"] = basic_block_id;
        functionCalls["instructionsPerBasicBlock"] = basic_block_size;
    }
}

#endif

/*! \file CToPTXTranslator.cpp
	\date Wednesday June 8, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the CToPTXTranslator class
*/

#ifndef C_TO_PTX_TRANSLATOR_CPP_INCLUDED
#define C_TO_PTX_TRANSLATOR_CPP_INCLUDED

#include <ocelot/translator/interface/CToPTXTranslator.h>

#define REG         "r"
#define COD_REG     "\%codr"
#define COD_PRED    "\%codp"

namespace translator
{

    unsigned long ptx_clock() { return 1; }
    unsigned long tid_x() { return 0; }
    unsigned long smid() { return 0; }
    unsigned long ctaid() { return 0; }
    void bar_sync() {}
    unsigned long data[2];


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
	        //l = s->j->print_insn(s, &info, (void *)p);
	        //printf("\n");
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

    int CToPTXTranslator::translate(dill_stream c, void *info_ptr, void *i)
    {
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        std::stringstream *dst, *src1, *src2;
        
        virtual_insn *insn = (virtual_insn *)i;
        
        ir::PTXInstruction inst;
        ir::PTXStatement stmt;
        
        stmt.directive = ir::PTXStatement::Instr;
        
        inst.type = type;
        
        switch(insn->class_code) {
        case iclass_lea:
        {
            src1 = new std::stringstream;
            *src1 << baseAddress() << insn->opnds.a3.src1;
            ir::PTXStatement global = ir::PTXStatement(ir::PTXStatement::Global);
            global.name = src1->str();
            global.type = type;
            globals.push_back(global);
            
            inst.opcode = ir::PTXInstruction::Mov;
                 
            dst = new std::stringstream;
            *dst << COD_REG << ++maxRegister;
            registers.push_back(dst->str());
            inst.d.identifier = dst->str();		      
            delete dst;
                 
            inst.d.type = type;          
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.identifier = src1->str();
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Address;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);     

            inst.opcode = ir::PTXInstruction::Ld;
            
            inst.addressSpace = ir::PTXInstruction::Global; 
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.type = type;
            dst = new std::stringstream;
            *dst << COD_REG << ++maxRegister;
            registers.push_back(dst->str());
            inst.d.identifier = dst->str();
            inst.a.identifier = statements.back().instruction.d.identifier;
            inst.a.addressMode = ir::PTXOperand::Indirect;
            
            baseReg = inst.d.identifier;
            delete dst;
            delete src1;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);
            
            break;
        }
        case iclass_set:
        {
            inst.opcode = ir::PTXInstruction::Mov;
            inst.d.type = type;
       
            dst = new std::stringstream;
            *dst << COD_REG << ++maxRegister;
            registers.push_back(dst->str());
            inst.d.identifier = dst->str();		      
            
            
            src1 = new std::stringstream;
            *src1 << REG << insn->opnds.a3i.dest;
            
            registerMap[src1->str()] = inst.d.identifier;
            
            delete dst;
            delete src1; 
                      
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
        
            dst = new std::stringstream;
            src1 = new std::stringstream; 
            
            *dst << REG << insn->opnds.a2.dest;
            *src1 << REG << insn->opnds.a2.src;
        
            std::map<std::string,std::string>::iterator it = registerMap.find(src1->str());
            if(it != registerMap.end()) {
                registerMap[dst->str()] = it->second;
                registerMap.erase(src1->str());
            }

            delete dst;
            delete src1;
            
            break;
        }
        case iclass_arith3:
        case iclass_arith3i:
        {
        
            src1 = new std::stringstream;
            src2 = new std::stringstream;
            
            if(insn->class_code == iclass_arith3){
                inst.b.addressMode = ir::PTXOperand::Register;
                *src1 << REG << insn->opnds.a3.src1;
                *src2 << REG << insn->opnds.a3.src2;
            }
            else {
                inst.b.addressMode = ir::PTXOperand::Immediate;
                *src1 << REG << insn->opnds.a3i.src;
                inst.b.imm_int = insn->opnds.a3i.u.imm;
            }
        
            inst.d.type = type;
            inst.a.type = type;
            inst.b.type = type;
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.addressMode = ir::PTXOperand::Register;
            
            
            dst = new std::stringstream;
            *dst << COD_REG << ++maxRegister;
            registers.push_back(dst->str());
            inst.d.identifier = dst->str();	
            delete dst;	
            
            inst.a.identifier = registerMap[src1->str()];	
            inst.b.identifier = registerMap[src2->str()];	
            
            dst = new std::stringstream;
            *dst << REG << insn->opnds.a3.dest;
            registerMap[dst->str()] = inst.d.identifier;
            delete dst;		
        
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
            
            delete src1;
            delete src2;
            
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
                    case ctaId:
                    {  
                        inst.opcode = ir::PTXInstruction::Cvt;  

                        inst.d.addressMode = ir::PTXOperand::Register;
                        dst = new std::stringstream;
                        *dst << COD_REG << ++maxRegister;
                        registers.push_back(dst->str());
                        inst.d.identifier = dst->str();
                        std::string ctaidX = inst.d.identifier;
                        delete dst;		
                        inst.d.type = type;
                        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
	                    inst.a.addressMode = ir::PTXOperand::Special;
	                    inst.a.vec = ir::PTXOperand::v1;
                        
                        stmt.instruction = inst;
                        setPredicate(inst);
                        statements.push_back(stmt);
                        
                        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
	                    inst.a.vec = ir::PTXOperand::v1;       
	                    
	                    dst = new std::stringstream;
                        *dst << COD_REG << ++maxRegister;
                        registers.push_back(dst->str());
                        inst.d.identifier = dst->str();		 
                        std::string ctaidY = inst.d.identifier;
                        delete dst;
                        
                        stmt.instruction = inst;
                        setPredicate(inst);
                        statements.push_back(stmt);
                        
                        inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
	                    inst.a.vec = ir::PTXOperand::v1;       
	                    
	                    dst = new std::stringstream;
                        *dst << COD_REG << ++maxRegister;
                        registers.push_back(dst->str());
                        inst.d.identifier = dst->str();
                        std::string nctaidX = inst.d.identifier;		 
                        delete dst;
                        
                        stmt.instruction = inst;
                        setPredicate(inst);
                        statements.push_back(stmt);
                
                        inst.opcode = ir::PTXInstruction::Mad;     
                        setPredicate(inst);
                           
                        inst.modifier = ir::PTXInstruction::lo;
                        inst.d.addressMode = ir::PTXOperand::Register;
                        inst.d.type = type;
                        
                        dst = new std::stringstream;
                        *dst << COD_REG << ++maxRegister;
                        inst.d.identifier = dst->str();
                        registers.push_back(dst->str());
                        std::string ctaid = inst.d.identifier;		 
                        delete dst;
                        
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
                                    
                        src1 = new std::stringstream;
                        *src1 << REG << insn->opnds.calli.src;
                        
                        registerMap[src1->str()] = ctaid;
                        delete src1;            
                    }
                    break;
                    case smId:
                    {    
                        inst.opcode = ir::PTXInstruction::Cvt;
                        setPredicate(inst);
                        
                        inst.d.type = type;
                        
                        dst = new std::stringstream;
                        *dst << COD_REG << ++maxRegister;
                        registers.push_back(dst->str());
                        inst.d.identifier = dst->str();
                        delete dst;
                        
                        inst.d.addressMode = ir::PTXOperand::Register;
                        inst.a = ir::PTXOperand(ir::PTXOperand::smId);
                        inst.a.type = ir::PTXOperand::u32;
                        
                        stmt.instruction = inst;
                        statements.push_back(stmt);        
                        
                        src1 = new std::stringstream;
                        *src1 << REG << insn->opnds.calli.src;
                        
                        registerMap[src1->str()] = inst.d.identifier;    
                    }            
                    break;
                    case clock64:
                    {   
                        inst.opcode = ir::PTXInstruction::Mov;
                 
                        inst.type = ir::PTXOperand::u64;
		                inst.d.type = ir::PTXOperand::u64;
		                inst.d.addressMode = ir::PTXOperand::Register;
		                inst.a = ir::PTXOperand(ir::PTXOperand::clock64);
		                inst.a.type = ir::PTXOperand::u64;
		                
		                dst = new std::stringstream;
                        *dst << COD_REG << ++maxRegister;
                        registers.push_back(dst->str());
                        inst.d.identifier = dst->str();		      
                        delete dst;
                                  
                        stmt.instruction = inst;
                        setPredicate(inst);
                        statements.push_back(stmt);        
                        
                        src1 = new std::stringstream;
                        *src1 << REG << insn->opnds.calli.src;
                        
                        registerMap[src1->str()] = inst.d.identifier;            
                    }
                    break;
                    case bar:
                    {
                        
                        inst.opcode = ir::PTXInstruction::Bar;
                        setPredicate(inst);
                
                        inst.d.addressMode = ir::PTXOperand::Immediate;
                        inst.d.imm_int = 0;
                        
                        stmt.instruction = inst;
                        statements.push_back(stmt);
                    }
                    break;
                    case tidX:
                    {
                        inst.opcode = ir::PTXInstruction::Cvt;
                        setPredicate(inst);
               
                        inst.d.addressMode = ir::PTXOperand::Register;
                        dst = new std::stringstream;
                        *dst << COD_REG << ++maxRegister;
                        registers.push_back(dst->str());
                        inst.d.identifier = dst->str();
                        delete dst;		
                        inst.d.type = type;
                        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
	                    inst.a.addressMode = ir::PTXOperand::Special;
	                    inst.a.vec = ir::PTXOperand::v1;
                        
                        stmt.instruction = inst;
                        statements.push_back(stmt);        
                        
                        src1 = new std::stringstream;
                        *src1 << REG << insn->opnds.calli.src;
                        
                        registerMap[src1->str()] = inst.d.identifier;    
                        
                        delete src1;        
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
            
            src1 = new std::stringstream;
            *src1 << REG << insn->opnds.br.src1;
                
            src2 = new std::stringstream;
            *src2 << REG << insn->opnds.br.src2;
            
            dst = new std::stringstream;
            *dst << COD_PRED << ++maxPredicate;
            registers.push_back(dst->str());
            
            inst.d.type = ir::PTXOperand::pred;
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = dst->str();
            
            inst.comparisonOperator = ir::PTXInstruction::Eq;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Register;
            inst.a.identifier = registerMap[src1->str()];
            inst.b.type = type;
            inst.b.addressMode = ir::PTXOperand::Register;
            inst.b.identifier = registerMap[src2->str()];
            
            delete dst;
            delete src1;
            delete src2;
	        
	       
	        PredicateInfo predicateInfo;
	        predicateInfo.id = inst.d.identifier;
	        
	        std::stringstream label;
	        
	        int br_op = insn->insn_code;
	        struct branch_table *t = &c->p->branch_table;
            
            if (t->label_name[insn->opnds.br.label] != NULL) {
	            label << t->label_name[insn->opnds.label.label];
	        }
	        else {
	            label << "L" << insn->opnds.br.label;
	        }
	        
	        predicateInfo.branchLabel = label.str();
	       
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
            src1 = new std::stringstream;
            dst = new std::stringstream;
        
            if(insn->class_code == iclass_loadstore){
                
            }
            else {
                *dst << REG << insn->opnds.a3i.src;
                *src1 << REG << insn->opnds.a3i.dest;
                inst.d.offset = insn->opnds.a3i.u.imm;
            }
            
	        int store = (insn->insn_code & 0x10) && 0x10;
	        if(store) {
	            
	            inst.opcode = ir::PTXInstruction::St;
	            
                inst.addressSpace = ir::PTXInstruction::Global; 
                inst.type = type;
                
                inst.d.identifier = registerMap[dst->str()];		
                inst.a.identifier = registerMap[src1->str()];	
                
                delete dst;
                delete src1;
                
             
                inst.d.addressMode = ir::PTXOperand::Indirect;
                inst.a.addressMode = ir::PTXOperand::Register;
                inst.a.type = type;
	     
	     
	            ir::PTXInstruction prev = statements.back().instruction;
                if(prev.opcode == ir::PTXInstruction::Add && prev.d.identifier == inst.d.identifier) {
                    prev.b.addressMode = ir::PTXOperand::Register;
                    prev.b.identifier = baseReg;
                    statements.pop_back();
                    stmt.instruction = prev;
                    statements.push_back(stmt);
                }
                   
                setPredicate(inst);
                stmt.instruction = inst;
	            statements.push_back(stmt);
	        
	        }
	        else {
	        
	        
	        }
	           
            break;
        }
        case iclass_mark_label:
        {
            std::stringstream label;
            
            struct branch_table *t = &c->p->branch_table;
            if (t->label_name[insn->opnds.label.label] != NULL) {
	            label << t->label_name[insn->opnds.label.label];
	        }
	        else {
	            label << "L" << insn->opnds.label.label;
	        }

            stmt.directive = ir::PTXStatement::Label;
            stmt.name = label.str();
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
    
    CToPTXData CToPTXTranslator::generate(void) {
    
        char code_string[] = "\
        {\n\
            unsigned long start;\n\
            unsigned long stop;\n\
            BEGIN_KERNEL:{\n\
                start = clock();\n\
                bar_sync();\n\
            }\n\
            END_KERNEL:{\n\
            bar_sync();\n\
            stop = clock();\n\
                if (tid_x() == 0) {\n\
                    unsigned long a = ctaid();\n\
                    data[2 * a] = stop - start;\n\
                    data[2 * a + 1] = smid();\n\
                }\n\
            }\n\
        }";

	    cod_parse_context context;
	    cod_exec_context ec;
	
	    static char extern_string[] = "unsigned long tid_x();\
					    unsigned long clock();\
                        unsigned long ctaid();\
                        unsigned long smid();\
                        void bar_sync();\
                        unsigned long data[2];";
                        
	    static cod_extern_entry externs[] = 
	    {
	        {(char *)"tid_x", (void*)(unsigned long)(*tid_x)},
	        {(char *)"clock", (void*)(unsigned long)(*ptx_clock)},
	        {(char *)"ctaid", (void*)(unsigned long)(*ctaid)},
            {(char *)"smid", (void*)(unsigned long)(*smid)},
            {(char *)"bar_sync", (void *)(*bar_sync)},
            {(char *)"data", (void *)data},
	        {NULL, (void*)0}
	    };
     
     
        cod_code gen_code;
	    void (*func)();
	
	    dill_set_foreign_cg(foreign_code_generator);

	    context = new_cod_parse_context();
	    cod_assoc_externs(context, externs);
	    cod_parse_for_context(extern_string, context);
	    gen_code = cod_code_gen(code_string, context);
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
        functionCalls["ctaid"] = ctaId;
        functionCalls["clock"] = clock64;
        functionCalls["bar_sync"] = bar;
        functionCalls["smid"] = smId;
        functionCalls["tid_x"] = tidX;
    }
}

#endif

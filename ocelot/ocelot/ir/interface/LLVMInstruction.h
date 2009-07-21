/*!
	\file LLVMInstruction.h
	\date Wednesday July 15, 2009
	\author Gregroy Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMInstruction class.
*/

#ifndef LLVM_INSTRUCTION_H_INCLUDED
#define LLVM_INSTRUCTION_H_INCLUDED

#include <ocelot/ir/interface/Instruction.h>

namespace ir
{
	/*! \brief A class used to represent any LLVM Instruction */
	class LLVMInstruction
	{
		public:
			/*! \brief The opcode of the instruction */
			enum Opcode
			{
				Alloca,
				And,
				Ashr,
				Bitcast,	
				Br,
				Call,
				Extractelement,
				Extractvalue,
				Fadd,
				Fcmp,
				Fdiv,
				Fmul,
				Fpext,	
				Fptosi,	
				Fptoui,
				Fptrunc,	
				Free,
				Frem,
				Fsub,
				Getelementptr,
				Icmp,
				Insertelement,
				Insertvalue,
				Inttoptr,
				Invoke,
				Load,
				Lshr,
				Malloc,
				Mul,
				Or,
				Phi,
				Ptrtoint,
				Ret,
				Radd,
				Sdiv,
				Select,
				Sext,
				Shl,
				Shufflevector,
				Sitofp,
				Srem,
				Store,
				Sub,
				Switch,
				Trunc,
				Udiv,
				Uitofp,	
				Unreachable,
				Unwind,
				Urem,
				Va_arg,
				Xor,
				Zext,
				InvalidOpcode	
			};
		
		public:
		    /*! \brief The opcode of the instruction */
		    Opcode opcode;
		
		public:
			/*!	\brief Returns a string representation of the instruction */
			std::string toString() const;

			/*!
				\brief Determines if the instruction is valid, returns an empty 
					string if valid otherwise an error message.
			*/
			std::string valid() const;
					
	};
}

#endif



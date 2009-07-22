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
	typedef unsigned char LLVMU8;
	typedef unsigned short LLVMU16;
	typedef unsigned int LLVMU32;
	typedef unsigned long long LLVMU64;
	
	typedef char LLVMS8;
	typedef short LLVMS16;
	typedef int LLVMS32;
	typedef long long LLVMS64;
	
	typedef float LLVMF32;
	typedef double LLVMF64;

	/*! \brief A class used to represent any LLVM Instruction */
	class LLVMInstruction : public Instruction
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
			
			/*! \brief Supported LLVM Types */
			enum DataType
			{
				S8,
				S16,
				S32,
				S64,
				U8,
				U16,
				U32,
				U64,
				F32,
				F64,
				Invalid
			};
			
			/*! \brief An llvm operand */
			class Operand
			{
				public:
					/*! \brief All possible operand modes */
					enum Mode
					{
						Register,
						Immediate,
						Label,
						Invalid
					};
					
				public:
					/*! \brief The Mode of operand */
					Mode mode;
					
					/*! \brief The DataType of the operand */
					DataType type;
					
					/*! \brief Vector width */
					unsigned int vector;
					
					/*! \brief The value of the operand */
					enum
					{
						LLVMU8 u8;
						LLVMU16 u16;
						LLVMU32 u32;
						LLVMU64 u64;
						LLVMS8 s8;
						LLVMS16 s16;
						LLVMS32 s32;
						LLVMS64 s64;
						LLVMF32 f32;
						LLVMF64 f64;
						RegisterType reg;
					};
					
					/*! \brief The label of the operand if it has one */
					std::string label;
					
				public:
					/*! \brief Default constructor */
					Operand( Mode m = Invalid, 
						DataType type = LLVMInstruction::Invalid, 
						unsigned int v = 1 );
						
					std::string toString() const;
			};
			
			/*! \brief Supported attributes */
			enum Attribute
			{
				Tail = 1,
				CCallingConvention = 2,
				FastCallingConvention = 4,
				ColdCallingConvention = 8,
				ZeroExtend = 16,
				SignExtend = 32,
				InReg = 64,
				NoReturn = 128,
				NoUnwind = 256,
				ReadOnly = 512,
				ReadNone = 1024
			};
		
		public:
		    /*! \brief The opcode of the instruction */
		    Opcode opcode;
		
			/*! \brief The destination operand */
			Operand d;
			
			/*! \brief The first source operand */
			Operand a;
			
			/*! \brief The second operand */
			Operand b;
			
			/*! \brief Alignment of operands */
			unsigned int alignment;
			
			/*! \brief Attributes */
			Attribute attributes;
		
		public:
			/*! \brief Convert a datatype to a string parsable by LLVM */
			static std::string toString( DataType d );
			/*! \brief Check a flag for the Tail attribute */
			static std::string tailToString( int attribute );
			/*! \brief Check a flag for a calling convention attribute */
			static std::string conventionToString( int attribute );
			/*! \brief Check a flag for parameter attributes */
			static std::string parameterAttributesToString( int attribute );
			/*! \brief Check a flag for function attribute */
			static std::string functionAttributesToString( int attribute );
			
		public:
			/*! \brief Default constructor */
			LLVMInstruction( Opcdode op = InvalidOpcode );
		
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



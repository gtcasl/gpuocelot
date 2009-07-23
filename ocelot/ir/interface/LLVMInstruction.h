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
			
			/*! \brief Comparison */
			enum Comparison
			{
				False, // no comparison, always returns false
				Oeq, // ordered and equal
				Ogt, // ordered and greater than
				Oge, // ordered and greater than or equal
				Olt, // ordered and less than
				Ole, // ordered and less than or equal
				One, // ordered and not equal
				Ord, // ordered (no nans)
				Ueq, // unordered or equal
				Ugt, // unordered or greater than
				Uge, // unordered or greater than or equal
				Ult, // unordered or less than
				Ule, // unordered or less than or equal
				Une, // unordered or not equal
				Uno, // unordered (either nans)
				True, // no comparison, always returns true
			};
			
		public:
		    /*! \brief The opcode of the instruction */
		    Opcode opcode;
		
			/*! \brief The destination operand/parameter, 
				this is the return value of a function call. */
			Parameter d;
			
			/*! \brief The first source operand */
			Operand a;
			
			/*! \brief The second operand */
			Operand b;
			
			union
			{
				/*! \brief Comparisons */
				Comparison comparison;
				/*! \brief Alignment of operands */
				unsigned int alignment;
				/*! \brief Attributes */
				Attribute attributes;
				/*! \brief Index for insert element instructions */
				unsigned int index;
			};
			
			/*! \brief A vector of Parameters for a function call instruction */
			ParameterVector parameters;
		
		public:
			/*! \brief Convert a datatype to a string parsable by LLVM */
			static std::string toString( DataType d );
			/*! \brief Check a flag for the Tail attribute */
			static std::string tailToString( int attribute );
			/*! \brief Check a flag for a calling convention attribute */
			static std::string conventionToString( int attribute );
			/*! \brief Check a flag for function attribute */
			static std::string functionAttributeToString( int attribute );
			/*! \brief Convert a Parameter attribute to a string */
			static std::string toString( ParameterAttribute attribute );
			/*! \brief Convert a Comprarison to a string */
			static std::string toString( Comparison comp );
			
		public:
			/*! \brief Default constructor */
			LLVMInstruction( Opcdode op = InvalidOpcode );
		
		public:
			/*!	\brief Returns a string representation of the instruction */
			virtual std::string toString() const;

			/*!
				\brief Determines if the instruction is valid, returns an empty 
					string if valid otherwise an error message.
			*/
			virtual std::string valid() const;
					
	};
	
	/*! \brief A generic 3 op arithmetic instruction */
	class LLVMArithmeticInstruction : public LLVMInstruction
	{
		public:
			/*! \brief Default constructor */
			LLVMArithmeticInstruction( Opcdode op = InvalidOpcode );
			
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



/*!
	\file LLVMStatement.h
	\date Wednesday July 29, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMStatement class.
*/

#ifndef LLVM_STATEMENT_H_INCLUDED
#define LLVM_STATEMENT_H_INCLUDED

#include <ocelot/ir/interface/LLVMInstruction.h>

namespace ir
{
	/*! \brief A class for LLVM declarations */
	class LLVMStatement
	{
		public:
			/*! \brief The type of statement */
			enum Type
			{
				Instruction,
				Label,
				InvalidType
			};
			
		public:
			/*! \brieg If this is an instruction, a pointer to the instruction 
				object.
				
				This pointer is owned by this class. */
			LLVMInstruction* instruction;
			
			/*! \brief The type of statement */
			Type type;
			
			/*! \brief The string if this is a label */
			std::string label;
			
		public:
			/*! \brief Sets out the instruction pointer and sets the type */
			LLVMStatement( Type type = InvalidType, 
				const LLVMInstruction* i = 0 );
			/*! \brief Construct a statement from an instruction */
			explicit LLVMStatement( const LLVMInstruction& i );
			/*! \brief Construction a statement from a label */
			explicit LLVMStatement( const std::string& l );
			/*! \brief Copy constructor for instruction */
			LLVMStatement( const LLVMStatement& s );
			/*! \brief Possibly cleans up the instruction pointer */
			~LLVMStatement();
			/*! \brief Assignment operator for instruction */
			const LLVMStatement& operator=( const LLVMStatement& s );
			/*! \brief Convert this statement into a string */
			std::string toString() const;
						
	};

}

#endif


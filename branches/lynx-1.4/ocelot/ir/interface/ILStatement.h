/*! \file ILStatement.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The header file for the IL Statement class.
 */

#ifndef IL_STATEMENT_H_INCLUDED
#define IL_STATEMENT_H_INCLUDED

//C++ standard library includes
#include <vector>

// Ocelot includes
#include <ocelot/ir/interface/ILInstruction.h>

namespace ir
{
	class ILStatement
	{
		public:
			/*! \brief Statement types */
			enum Type
			{
				Instruction,
				ConstantBufferDcl,
				LiteralDcl,
				OtherDeclarations,         // TODO Delete this
				InvalidType
			};

			typedef std::vector<ILOperand> operandVector;

			/*! \brief If this is an instruction, a pointer to the instruction
			 * object.
			 *
			 * The pointer is owned by this class.
			 */
			ILInstruction *instruction;
			/*! \brief Statement type */
			Type type;
			/*! \brief The operands if this is a declaration */
			operandVector operands;

			/*! \brief Default constructor */
			ILStatement(Type type = InvalidType);
			/*! \brief Construct a statement from an instruction */
			explicit ILStatement(const ILInstruction &i);

			/*! \brief Convert this statement into a string */
			std::string toString() const;
	};
}

#endif



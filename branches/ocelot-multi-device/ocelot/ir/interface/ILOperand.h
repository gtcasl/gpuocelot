/*! \file ILOperand.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 29, 2010
 *  \brief The header file for the IL Operand class.
 */

#ifndef IL_OPERAND_H_INCLUDED
#define IL_OPERAND_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/Instruction.h>

// C++ standard library includes
#include <string>

namespace ir
{
	/*! \brief A class for a basic IL Operand */
	class ILOperand {
		public:
			/*! \brief Addressing modes of operand */
			enum AddressMode {
				Register,              // use as a register variable
				Literal,               // literal value (immediate)
				ConstantBuffer,        // constant buffer (parameter)
				Special,               // special register
				Invalid
			};

			/*! \brief Special register names */
			enum SpecialRegister {
				vAbsTidFlatX,
				SpecialRegister_invalid
			};

			/*! \brief Addressing mode of operand */
			AddressMode addressMode;

			/*! \brief Value of operand */
			SpecialRegister special;

			/*! Identifier of operand */
			std::string identifier;

			std::string toString() const;
			std::string toString(SpecialRegister sr) const;
	};
}

#endif



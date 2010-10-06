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
			/*! \brief Default constructor */
			ILOperand();

		public:
			/*! \brief Addressing modes of operand */
			enum AddressMode {
				Register,              // use as a register variable
				Immediate,             // immediate value
				Literal,               // literal value (immediate)
				ConstantBuffer,        // constant buffer (parameter)
				Special,               // special register
				Invalid
			};

			/*! \brief Type specifier */
			enum DataType {
				I32,
				F32,
				InvalidDataType
			};

			/*! \brief Special register names */
			enum SpecialRegister {
				vTidInGrpX,
				vTidInGrpY,
				vTidInGrpZ,
				vNTidInGrpX,
				vNTidInGrpY,
				vNTidInGrpZ,
				vThreadGrpIdX,
				vThreadGrpIdY,
				vThreadGrpIdZ,
				vNThreadGrpIdX,
				vNThreadGrpIdY,
				vNThreadGrpIdZ,
				SpecialRegister_invalid
			};

			/*! \brief Component selection for source modifiers */
			enum ComponentSelect {
				CompSel_0,          // force this component to 0.0
				CompSel_1,          // force this component to 1.0
				CompSel_X,          // select the 1st component
				CompSel_Y,          // select the 2nd component
				CompSel_Z,          // select the 3rd component
				CompSel_W,          // select the 4th component
				CompSel_NoWrite,    // don't write this component
				CompSel_Invalid
			};

			/*! \brief Addressing mode of operand */
			AddressMode addressMode;
			/*! \brief Data type */
			DataType type;
			/*! \brief Value of operand */
			SpecialRegister special;

			/*****************************//**
			 * \name Source modifiers
			 ********************************/
			//@{
			/*! \brief Swizzle */
			ComponentSelect swizzle_x, swizzle_y, swizzle_z, swizzle_w;
			/*! \brief Negate */
			bool negate_x, negate_y, negate_z, negate_w;
			//@}

			/*! \brief Identifier of operand */
			std::string identifier;
			/*! \brief Immediate value */
			union {
			   int imm_int;
			   float imm_float;
			};

			std::string toString() const;
			std::string toString(ComponentSelect c) const;
			std::string toString(SpecialRegister sr) const;
			std::string toStringRegister() const;

			/*****************************//**
			 * \name Swizzles
			 *
			 * Returns a copy of the operand.
			 ********************************/
			//@{
			ILOperand x() const;
			ILOperand y() const;
			ILOperand xy() const;
			ILOperand xxxx() const;
			ILOperand _y__() const;
			//@}
			
			/*! \brief Negate */
			ILOperand neg() const;
	};
}

#endif



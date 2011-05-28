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
				CompSel_0,       // force this component to 0.0
				CompSel_1,       // force this component to 1.0
				CompSel_X,       // select the 1st component
				CompSel_Y,       // select the 2nd component
				CompSel_Z,       // select the 3rd component
				CompSel_W,       // select the 4th component
				CompSel_NoWrite, // dont' write this component
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
			ILOperand z() const;
			ILOperand w() const;
			ILOperand xy() const;
			ILOperand xxxx() const;
			ILOperand x___() const;
			ILOperand _y__() const;
			ILOperand __z_() const;
			ILOperand ___w() const;
			//@}
			
			/*! \brief Negate */
			ILOperand neg() const;

		public:
			/*! \brief Register type */
			enum RegType {
				RegType_Temp,
				RegType_Const_Buf,
				RegType_Literal,
				RegType_Thread_Id_In_Group,
				RegType_Thread_Group_Id,
				RegType_Invalid
			};

			/*! \brief Destination modifier */
			class Dst_Mod {
				public:
					std::string toString() const;

				private:
					/*! \brief Destination component */
					enum ModDstComponent {
						ModComp_NoWrite, // do not write this component
						ModComp_Write,   // write the result to this component
						ModComp_0,       // force the component to float 0.0
						ModComp_1,       // force the component to float 1.0
						ModComp_Invalid
					};

					/*! \brief Shift scale */
					enum ShiftScale {
						Shift_None,
						Shift_X2,        // shift value left by 1 bit
						Shift_X4,        // shift value left by 2 bits
						Shift_X8,        // shift value left by 3 bits
						Shift_D2,        // shift value right by 1 bit
						Shift_D4,        // shift value right by 2 bits
						Shift_D8,        // shift value right by 3 bits
						Shift_Invalid
					};

					static std::string toString(ModDstComponent dc);

					ModDstComponent component_x;
					ModDstComponent component_y;
					ModDstComponent component_z;
					ModDstComponent component_w;
					bool clamp;
					ShiftScale shift_scale;
			};
			
			/*! \brief Source modifier */
			class Src_Mod {
				public:
					std::string toString() const;

				private:
					std::string swizzleString() const;
					std::string negateString() const;

					/*! \brief Source component */
					enum ComponentSelect {
						CompSel_X,       // select the 1st component
						CompSel_Y,       // select the 2nd component
						CompSel_Z,       // select the 3rd component
						CompSel_W,       // select the 4th component
						CompSel_0,       // force the component to float 0.0
						CompSel_1,       // force the component to float 1.0
						CompSel_Invalid
					};

					static std::string toString(ComponentSelect c);

					ComponentSelect swizzle_x;
					ComponentSelect swizzle_y;
					ComponentSelect swizzle_z;
					ComponentSelect swizzle_w;
					bool negate_x;
					bool negate_y;
					bool negate_z;
					bool negate_w;
			};

			/*****************************//**
			 * \name Operand information
			 ********************************/
			//@{
			unsigned int num;
			RegType rtype;
			bool modifier_present;
			union {
				Dst_Mod dst_mod; // destination modifier
				Src_Mod src_mod; // source modifier
			};
			//@}

			static std::string toString(RegType rt);

			std::string dstString() const;
			std::string srcString() const;
	};
}

#endif



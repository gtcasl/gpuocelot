/*! \file ILInstruction.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The header file for the IL Instruction class.
 */

#ifndef IL_INSTRUCTION_H_INCLUDED
#define IL_INSTRUCTION_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/Instruction.h>
#include <ocelot/ir/interface/ILOperand.h>

namespace ir
{
	/*! \brief A class used to represent any IL Instruction */
	class ILInstruction : public Instruction
	{
		public:
			/*! \brief The opcode of the instruction */
			enum Opcode
			{
				Iadd,
				Imul,
				End,
				Mov,
				Uav_Raw_Load_Id,
				Uav_Raw_Store_Id,
				InvalidOpcode
			};

			/*! \brief The opcode of the instruction */
			const Opcode opcode;

			/*! \brief Convert an opcode to a string parsable by IL */
			static std::string toString(Opcode o);

			/*! \brief Default constructor */
			ILInstruction(Opcode op = InvalidOpcode);

			/*! \brief Return a pointer to a new Instruction */
			virtual Instruction* clone(bool copy=true) const = 0;
	
			virtual std::string toString() const = 0;
			virtual std::string valid() const = 0;
	};

	/*! \brief A generic 1 operand instruction */
	class ILUnaryInstruction : public ILInstruction
	{
		public:
			/*! \brief The destination operand */
			ILOperand d;
			
			/*! \brief The source operand */
			ILOperand a;
	
			/*! \brief Default constructor */
			ILUnaryInstruction(Opcode op = InvalidOpcode,
					const ILOperand &d = ILOperand(), 
					const ILOperand &a = ILOperand());
			
			virtual std::string toString() const;
			virtual std::string valid() const;

			virtual Instruction* clone(bool copy = true) const = 0;
	};
	
	/*! \brief A generic 2 operand instruction */
	class ILBinaryInstruction : public ILInstruction
	{
		public:
			/*! \brief The destination operand */
			ILOperand d;
			
			/*! \brief The first source operand */
			ILOperand a;

			/*! \brief The second source operand */
			ILOperand b;

			/*! \brief Default constructor */
			ILBinaryInstruction(Opcode op = InvalidOpcode,
					const ILOperand &_d = ILOperand(), 
					const ILOperand &_a = ILOperand(), 
					const ILOperand &_b = ILOperand());
			
			virtual std::string toString() const;
			virtual std::string valid() const;

			virtual Instruction* clone(bool copy=true) const = 0;
	};

	class ILEnd : public ILInstruction
	{
		public:
			/*! \brief Default constructor */
			ILEnd();

			std::string toString() const;
			std::string valid() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILIadd : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIadd();

			Instruction *clone(bool copy=true) const;
	};

	class ILImul : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILImul();

			Instruction *clone(bool copy=true) const;
	};

	class ILMov : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILMov();

			Instruction *clone(bool copy=true) const;
	};

	class ILUav_Raw_Load_Id : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILUav_Raw_Load_Id();

			Instruction *clone(bool copy=true) const;
	};

	class ILUav_Raw_Store_Id : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILUav_Raw_Store_Id();

			Instruction *clone(bool copy=true) const;
	};

}

#endif


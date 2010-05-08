/*! \file ILInstruction.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The header file for the IL Instruction class.
 */

#ifndef IL_INSTRUCTION_H_INCLUDED
#define IL_INSTRUCTION_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/Instruction.h>

namespace ir
{
	/*! \brief A class used to represent any IL Instruction */
	class ILInstruction : public Instruction
	{
		public:
			/*! \brief The opcode of the instruction */
			enum Opcode
			{
				Mov,
				InvalidOpcode
			};

			/*! \brief A class for a basic IL Operand */
			class Operand
			{
				public:
					/*! \brief The name of the operand */
					std::string name;

					/*! \brief Default constructor */
					Operand();

					/*! \brief Return a parsable representation of the Operand */
					std::string toString() const;
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
			Operand d;
			
			/*! \brief The source operand */
			Operand a;
	
			/*! \brief Default constructor */
			ILUnaryInstruction(Opcode op = InvalidOpcode,
					const Operand &d = Operand(), 
					const Operand &a = Operand());
			
			virtual std::string toString() const;
			virtual std::string valid() const;

			virtual Instruction* clone(bool copy = true) const = 0;
	};
	
	/*! \brief A generic 2 operand instruction */
	class ILBinaryInstruction : public ILInstruction
	{
		public:
			/*! \brief The destination operand */
			Operand d;
			
			/*! \brief The first source operand */
			Operand a;

			/*! \brief The second source operand */
			Operand b;

			/*! \brief Default constructor */
			ILBinaryInstruction(Opcode op = InvalidOpcode,
					const Operand &_d = Operand(), 
					const Operand &_a = Operand(), 
					const Operand &_b = Operand());
			
			virtual std::string toString() const;
			virtual std::string valid() const;

			virtual Instruction* clone(bool copy=true) const = 0;
	};

	class ILMov : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILMov();

			Instruction *clone(bool copy=true) const;
	};
}

#endif


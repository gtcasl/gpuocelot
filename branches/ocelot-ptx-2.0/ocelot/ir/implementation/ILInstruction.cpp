/*! \file ILInstruction.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 27, 2010
 *  \brief The source file for the IL Instruction class.
 */

// Ocelot includes
#include <ocelot/ir/interface/ILInstruction.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

namespace ir
{
	std::string ILInstruction::toString(Opcode opcode)
	{
		switch(opcode)
		{
			case Mov: return "mov"; break;
			case InvalidOpcode: return "INVALID_OPCODE"; break;
		}

		return "";
	}

	ILInstruction::ILInstruction(Opcode op) : opcode(op)
	{
	}

	ILInstruction::Operand::Operand()
	{
	}

	std::string ILInstruction::Operand::toString() const
	{
		return name;
	}

	ILUnaryInstruction::ILUnaryInstruction(Opcode op,
			const Operand &_d, const Operand &_a)
		:
			ILInstruction(op),
			d(_d),
			a(_a)
	{
	}

	std::string ILUnaryInstruction::toString() const
	{
		return ILInstruction::toString(opcode) + " " + d.toString() + ", "
			+ a.toString();
	}

	std::string ILUnaryInstruction::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	ILBinaryInstruction::ILBinaryInstruction(Opcode op,
			const Operand &_d, const Operand &_a, const Operand &_b)
		:
			ILInstruction(op), d(_d), a(_a), b(_b)
	{
	}

	std::string ILBinaryInstruction::toString() const
	{
		return ILInstruction::toString(opcode) + " " + d.toString() + ", "
			+ a.toString() + ", " + b.toString();
	}

	std::string ILBinaryInstruction::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	ILMov::ILMov() : ILUnaryInstruction(Mov)
	{
	}

	Instruction *ILMov::clone(bool copy) const
	{
		assertM(false, "Not implemented yet");
	}
}



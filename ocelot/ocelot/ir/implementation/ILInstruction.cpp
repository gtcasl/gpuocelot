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
			case Add:                return "add";
			case Break:              return "break";
			case Else:               return "else";
			case End:                return "end";
			case EndIf:              return "endif";
			case EndLoop:            return "endloop";
			case Fence:              return "fence_threads_lds";
			case Iadd:               return "iadd";
			case Iand:               return "iand";
			case IfLogicalZ:         return "if_logicalz";
			case Ige:                return "ige";
			case Ilt:                return "ilt";
			case Imul:               return "imul";
			case Ishr:               return "ishr";
			case Lds_Load_Id:        return "lds_load_id(1)";
			case Lds_Store_Id:       return "lds_store_id(1)";
			case Mad:                return "mad";
			case Mov:                return "mov";
			case Uav_Arena_Load_Id:  return "uav_arena_load_id(1)";
			case Uav_Arena_Store_Id: return "uav_arena_store_id(1)";
			case Uav_Raw_Load_Id:    return "uav_raw_load_id(0)";
			case Uav_Raw_Store_Id:   return "uav_raw_store_id(0) mem.x,";
			case WhileLoop:          return "whileloop";
			case InvalidOpcode:      return "INVALID_OPCODE";
			default:
			{
				assertM(false, "Opcode " << opcode << " not supported");
			}
		}

		assertM(false, "Unreachable line");
	}

	std::string ILInstruction::toString(DataType d)
	{
		switch(d)
		{
			case Short: return "short";
			case Byte:  return "byte";
			case Dword: return "dword";
			default:
			{
				assertM(false, "DataType " << d << " not supported");
			}
		};
	}

	ILInstruction::ILInstruction(Opcode op) : opcode(op)
	{
	}

	ILUnaryInstruction::ILUnaryInstruction(Opcode op,
			const ILOperand &_d, const ILOperand &_a)
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
			const ILOperand &_d, const ILOperand &_a, const ILOperand &_b)
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

	ILTrinaryInstruction::ILTrinaryInstruction(Opcode op,
			const ILOperand &_d, const ILOperand &_a, const ILOperand &_b,
			const ILOperand &_c)
		:
			ILInstruction(op), d(_d), a(_a), b(_b), c(_c)
	{
	}

	std::string ILTrinaryInstruction::toString() const
	{
		return ILInstruction::toString(opcode) + " " + d.toString() + ", "
			+ a.toString() + ", " + b.toString() + ", " + c.toString();
	}

	std::string ILTrinaryInstruction::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	ILAdd::ILAdd() : ILBinaryInstruction(Add)
	{
	}

	Instruction *ILAdd::clone(bool copy) const
	{
		return new ILAdd(*this);
	}

	ILBreak::ILBreak() : ILInstruction(Break)
	{
	}

	std::string ILBreak::toString() const
	{
		return ILInstruction::toString(opcode);
	}

	std::string ILBreak::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	Instruction *ILBreak::clone(bool copy) const
	{
		return new ILBreak(*this);
	}

	ILElse::ILElse() : ILInstruction(Else)
	{
	}

	std::string ILElse::toString() const
	{
		return ILInstruction::toString(opcode);
	}

	std::string ILElse::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	Instruction *ILElse::clone(bool copy) const
	{
		return new ILElse(*this);
	}

	ILEnd::ILEnd() : ILInstruction(End)
	{
	}

	std::string ILEnd::toString() const
	{
		return "end";
	}

	std::string ILEnd::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	Instruction *ILEnd::clone(bool copy) const
	{
		return new ILEnd(*this);
	}

	ILEndIf::ILEndIf() : ILInstruction(EndIf)
	{
	}

	std::string ILEndIf::toString() const
	{
		return ILInstruction::toString(opcode);
	}

	std::string ILEndIf::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	Instruction *ILEndIf::clone(bool copy) const
	{
		return new ILEndIf(*this);
	}

	ILEndLoop::ILEndLoop() : ILInstruction(EndLoop)
	{
	}

	std::string ILEndLoop::toString() const
	{
		return ILInstruction::toString(opcode);
	}

	std::string ILEndLoop::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	Instruction *ILEndLoop::clone(bool copy) const
	{
		return new ILEndLoop(*this);
	}

	ILFence::ILFence() : ILInstruction(Fence)
	{
	}

	std::string ILFence::toString() const
	{
		return ILInstruction::toString(opcode);
	}

	std::string ILFence::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	Instruction *ILFence::clone(bool copy) const
	{
		return new ILFence(*this);
	}

	ILIadd::ILIadd() : ILBinaryInstruction(Iadd)
	{
	}

	Instruction *ILIadd::clone(bool copy) const
	{
		return new ILIadd(*this);
	}

	ILIand::ILIand() : ILBinaryInstruction(Iand)
	{
	}

	Instruction *ILIand::clone(bool copy) const
	{
		return new ILIand(*this);
	}

	ILIfLogicalZ::ILIfLogicalZ() : ILInstruction(IfLogicalZ)
	{
	}

	std::string ILIfLogicalZ::toString() const
	{
		return ILInstruction::toString(opcode) + " " + a.toString();
	}

	std::string ILIfLogicalZ::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	Instruction *ILIfLogicalZ::clone(bool copy) const
	{
		return new ILIfLogicalZ(*this);
	}

	ILIge::ILIge() : ILBinaryInstruction(Ige)
	{
	}

	Instruction *ILIge::clone(bool copy) const
	{
		return new ILIge(*this);
	}

	ILIlt::ILIlt() : ILBinaryInstruction(Ilt)
	{
	}

	Instruction *ILIlt::clone(bool copy) const
	{
		return new ILIlt(*this);
	}

	ILImul::ILImul() : ILBinaryInstruction(Imul)
	{
	}

	Instruction *ILImul::clone(bool copy) const
	{
		return new ILImul(*this);
	}

	ILIshr::ILIshr() : ILBinaryInstruction(Ishr)
	{
	}

	Instruction *ILIshr::clone(bool copy) const
	{
		return new ILIshr(*this);
	}

	ILLds_Load_Id::ILLds_Load_Id() 
		: ILUnaryInstruction(Lds_Load_Id)
	{
	}

	std::string ILLds_Load_Id::toString() const
	{
		return ILInstruction::toString(opcode) + " " + d.toString() + ".x, "
			+ a.toString();
	}

	Instruction *ILLds_Load_Id::clone(bool copy) const
	{
		return new ILLds_Load_Id(*this);
	}

	ILLds_Store_Id::ILLds_Store_Id() 
		: ILUnaryInstruction(Lds_Store_Id)
	{
	}

	std::string ILLds_Store_Id::toString() const
	{
		return ILInstruction::toString(opcode) + " " + d.toString() + ", "
			+ a.toString() + ".x";
	}

	Instruction *ILLds_Store_Id::clone(bool copy) const
	{
		return new ILLds_Store_Id(*this);
	}

	ILMad::ILMad() : ILTrinaryInstruction(Mad)
	{
	}

	Instruction *ILMad::clone(bool copy) const
	{
		return new ILMad(*this);
	}

	ILMov::ILMov() : ILUnaryInstruction(Mov)
	{
	}

	Instruction *ILMov::clone(bool copy) const
	{
		return new ILMov(*this);
	}

	ILUav_Arena_Load_Id::ILUav_Arena_Load_Id() 
		: ILUnaryInstruction(Uav_Arena_Load_Id)
	{
	}

	std::string ILUav_Arena_Load_Id::toString() const
	{
		return ILInstruction::toString(opcode) + "_size(" 
			+ ILInstruction::toString(type) + ") " + d.toString() + ", " 
			+ a.toString();
	}

	Instruction *ILUav_Arena_Load_Id::clone(bool copy) const
	{
		return new ILUav_Arena_Load_Id(*this);
	}

	ILUav_Arena_Store_Id::ILUav_Arena_Store_Id() 
		: ILUnaryInstruction(Uav_Arena_Store_Id)
	{
	}

	Instruction *ILUav_Arena_Store_Id::clone(bool copy) const
	{
		return new ILUav_Arena_Store_Id(*this);
	}

	std::string ILUav_Arena_Store_Id::toString() const
	{
		return ILInstruction::toString(opcode) + "_size(" 
			+ ILInstruction::toString(type) + ") " + d.toString() + ", " 
			+ a.toString();
	}

	ILUav_Raw_Load_Id::ILUav_Raw_Load_Id() 
		: ILUnaryInstruction(Uav_Raw_Load_Id)
	{
	}

	Instruction *ILUav_Raw_Load_Id::clone(bool copy) const
	{
		return new ILUav_Raw_Load_Id(*this);
	}

	ILUav_Raw_Store_Id::ILUav_Raw_Store_Id() 
		: ILUnaryInstruction(Uav_Raw_Store_Id)
	{
	}

	Instruction *ILUav_Raw_Store_Id::clone(bool copy) const
	{
		return new ILUav_Raw_Store_Id(*this);
	}

	ILWhileLoop::ILWhileLoop() : ILInstruction(WhileLoop)
	{
	}

	std::string ILWhileLoop::toString() const
	{
		return ILInstruction::toString(opcode);
	}

	std::string ILWhileLoop::valid() const
	{
		assertM(false, "Not implemented yet");
	}

	Instruction *ILWhileLoop::clone(bool copy) const
	{
		return new ILWhileLoop(*this);
	}
}



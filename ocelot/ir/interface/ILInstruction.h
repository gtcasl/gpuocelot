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
				Add,
				And,
				Break,
				Cmov_Logical,
				Else,
				End,
				EndIf,
				EndLoop,
				Fence,
				Iadd,
				Iand,
				Ieq,
				IfLogicalZ,
				Ige,
				Ilt,
				Imul,
				Ine,
				Inegate,
				Ior,
				Ishl,
				Ishr,
				Ixor,
				Lds_And_Resource,
				Lds_Load_Id,
				Lds_Or_Resource,
				Lds_Read_Add_Resource,
				Lds_Store_Id,
				Mad,
				Mov,
				Mul,
				Sub,
				Uav_Arena_Load_Id,
				Uav_Arena_Store_Id,
				Uav_Raw_Load_Id,
				Uav_Raw_Store_Id,
				Uav_Read_Add_Id,
				Uav_Read_Xchg_Id,
				Udiv,
				Umul,
				Ushr,
				WhileLoop,
				InvalidOpcode
			};

			enum DataType
			{
				Byte,
				Short,
				Dword
			};

			/*! \brief The opcode of the instruction */
			const Opcode opcode;

			/*! \brief Convert an opcode to a string parsable by IL */
			static std::string toString(Opcode o);
			/*! \brief Convert a datatype to a string parsable by IL */
			static std::string toString(DataType d);

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

	/*! \brief A generic 3 operand instruction */
	class ILTrinaryInstruction : public ILInstruction
	{
		public:
			/*! \brief The destination operand */
			ILOperand d;
			
			/*! \brief The first source operand */
			ILOperand a;

			/*! \brief The second source operand */
			ILOperand b;

			/*! \brief The third source operand */
			ILOperand c;

			/*! \brief Default constructor */
			ILTrinaryInstruction(Opcode op = InvalidOpcode,
					const ILOperand &_d = ILOperand(), 
					const ILOperand &_a = ILOperand(), 
					const ILOperand &_b = ILOperand(),
					const ILOperand &_c = ILOperand());
			
			virtual std::string toString() const;
			virtual std::string valid() const;

			virtual Instruction* clone(bool copy=true) const = 0;
	};

	class ILBreak: public ILInstruction
	{
		public:
			/*! \brief Default constructor */
			ILBreak();

			std::string toString() const;
			std::string valid() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILCmov_Logical : public ILTrinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILCmov_Logical();

			Instruction *clone(bool copy=true) const;
	};

	class ILAdd : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILAdd();

			Instruction *clone(bool copy=true) const;
	};

	class ILAnd : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILAnd();

			Instruction *clone(bool copy=true) const;
	};

	class ILElse : public ILInstruction
	{
		public:
			/*! \brief Default constructor */
			ILElse();

			std::string toString() const;
			std::string valid() const;
			Instruction *clone(bool copy=true) const;
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

	class ILEndIf : public ILInstruction
	{
		public:
			/*! \brief Default constructor */
			ILEndIf();

			std::string toString() const;
			std::string valid() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILEndLoop : public ILInstruction
	{
		public:
			/*! \brief Default constructor */
			ILEndLoop();

			std::string toString() const;
			std::string valid() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILFence: public ILInstruction
	{
		public:
			/*! \brief Default constructor */
			ILFence();

			/*! \brief Set/unset threads flag */
			void threads(bool value = true);
			/*! \brief Set/unset lds flag */
			void lds(bool value = true);

			std::string toString() const;
			std::string valid() const;
			Instruction *clone(bool copy=true) const;

		private:
			/*! \brief threads,lds flags */
			bool _threads, _lds;
	};

	class ILIadd : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIadd();

			Instruction *clone(bool copy=true) const;
	};

	class ILIand : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIand();

			Instruction *clone(bool copy=true) const;
	};

	class ILIeq : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIeq();

			Instruction *clone(bool copy=true) const;
	};

	class ILIfLogicalZ : public ILInstruction
	{
		public:
			/*! \brief The first source operand */
			ILOperand a;

			/*! \brief Default constructor */
			ILIfLogicalZ();

			std::string toString() const;
			std::string valid() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILIge : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIge();

			Instruction *clone(bool copy=true) const;
	};

	class ILIlt : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIlt();

			Instruction *clone(bool copy=true) const;
	};

	class ILImul : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILImul();

			Instruction *clone(bool copy=true) const;
	};

	class ILIne : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIne();

			Instruction *clone(bool copy=true) const;
	};

	class ILInegate : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILInegate();

			Instruction *clone(bool copy=true) const;
	};

	class ILIor : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIor();

			Instruction *clone(bool copy=true) const;
	};

	class ILIshl : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIshl();

			Instruction *clone(bool copy=true) const;
	};

	class ILIshr : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIshr();

			Instruction *clone(bool copy=true) const;
	};

	class ILIxor : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILIxor();

			Instruction *clone(bool copy=true) const;
	};

	class ILLds_And_Resource : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILLds_And_Resource();

			std::string toString() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILLds_Load_Id : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILLds_Load_Id();

			std::string toString() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILLds_Or_Resource : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILLds_Or_Resource();

			std::string toString() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILLds_Read_Add_Resource : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILLds_Read_Add_Resource();

			Instruction *clone(bool copy=true) const;
	};

	class ILLds_Store_Id : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILLds_Store_Id();

			std::string toString() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILMad : public ILTrinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILMad();

			Instruction *clone(bool copy=true) const;
	};

	class ILMov : public ILUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILMov();

			Instruction *clone(bool copy=true) const;
	};

	class ILMul : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILMul();

			Instruction *clone(bool copy=true) const;
	};

	class ILSub : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILSub();

			Instruction *clone(bool copy=true) const;
	};

	class ILUav_Arena_Load_Id : public ILUnaryInstruction
	{
		public:
			DataType type;

			/*! \brief Default constructor */
			ILUav_Arena_Load_Id();

			std::string toString() const;
			Instruction *clone(bool copy=true) const;
	};

	class ILUav_Arena_Store_Id : public ILUnaryInstruction
	{
		public:
			DataType type;

			/*! \brief Default constructor */
			ILUav_Arena_Store_Id();

			std::string toString() const;
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

	class ILUav_Read_Add_Id : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILUav_Read_Add_Id();

			Instruction *clone(bool copy=true) const;
	};

	class ILUav_Read_Xchg_Id : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILUav_Read_Xchg_Id();

			Instruction *clone(bool copy=true) const;
	};

	class ILUdiv : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILUdiv();

			Instruction *clone(bool copy=true) const;
	};

	class ILUmul : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILUmul();

			Instruction *clone(bool copy=true) const;
	};

	class ILUshr : public ILBinaryInstruction
	{
		public:
			/*! \brief Default constructor */
			ILUshr();

			Instruction *clone(bool copy=true) const;
	};

	class ILWhileLoop : public ILInstruction
	{
		public:
			/*! \brief Default constructor */
			ILWhileLoop();

			std::string toString() const;
			std::string valid() const;
			Instruction *clone(bool copy=true) const;
	};
}
#endif

/*! \file   VIRInstruction.h
	\date   Thursday February 17, 2011
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The header file for the VIRInstruction class.
*/

// Ocelot Includes
#include <ocelot/ir/interface/Instruction.h>

namespace ir
{

/*! \brief  */
class VIRInstruction : public Instruction
{
public:
	/*! \brief A primitive data type */
	enum DataType
	{
		i1,
		i8,
		i16,
		i32,
		i64,
		f32,
		f64,
		InvalidDataType
	};

	/*! \brief Represents a single instruction operand */
	class OperandBase
	{
	public:
		/*! \brief An operand type */
		enum OperandMode
		{
			Register,
			Immediate,
			Predicate,
			Indirect,
			InvalidOperand
		};
	
		/*! \brief A type to hold a register idenfitier */
		typedef unsigned int RegisterType;

	public:
		/*! \brief The mode of the operand determines how it is accessed */
		OperandMode mode;	
	};

	/*! \brief A register operand */
	class RegisterOperand : public OperandBase
	{
	public:
		/*! \brief The register being accessed */
		RegisterType reg;
		/*! \brief The data type */
		DataType type;
	};

	/*! \brief An immediate operand */
	class ImmediateOperand : public OperandBase
	{
	public:
		/*! \brief The immediate value */
		union
		{
			long long unsigned int uint;
			double                 fp;
		};

		/*! \brief The data type */
		DataType type;
	};

	/*! \brief A predicate operand */
	class PredicateOperand : public OperandBase
	{
	public:
		/*! \brief The modifier on the predicate */
		enum PredicateModifier
		{
			StraightPredicate,
			InversePredicate,
			PredicateTrue,
			PredicateFalse,
			InvalidPredicate
		};

	public:
		/*! \brief The register being accessed */
		RegisterType reg;
		/*! \brief The predicate modifier */
		PredicateModifier modifier;
	};

	/*! \brief An indirect operand */
	class IndirectOperand : public OperandBase
	{
	public:
		/*! \brief The register being accessed */
		RegisterType reg;
		/*! \brief The offset to add to the register */
		int offset;
		/*! \brief The data type */
		DataType type;
	};

public:
	/*! \brief The set of possible instructions */
	enum Opcode
	{
		Add,
		And,
		Ashr,
		Atom,
		Bar,
		Bitcast,
		Bra,
		Fpext,
		Fptosi,
		Fptoui,
		Fptrunc,
		Ld,
		Lshr,
		Membar,
		Mul,
		Or,
		SetP,
		Sext,
		Sdiv,
		Shl,
		Sitofp,
		Srem,
		St,
		Sub,
		Trunc,
		Udiv,
		Uitofp,
		Urem,
		Xor,
		Zext,
		InvalidOpcode
	};
	
public:
	/*! \brief The instruction opcode */
	Opcode opcode;

	/*! \brief The guard predicate */
	PredicateOperand guard;

};


/*! \brief A unary instruction */
class VIRUnaryInstruction : public VIRInstruction
{
public:
	/*! \brief The destination operand. */
	Operand d;
	/*! \brief The source operand. */
	Operand a;

};

/*! \brief A binary instruction */
class VIRBinaryInstruction : public VIRInstruction
{
public:
	/*! \brief The destination operand. */
	Operand d;
	/*! \brief The first source operand. */
	Operand a;
	/*! \brief The second source operand. */
	Operand b;
};

/*! \brief An instruction involving a comparison */
class VIRComparisonInstruction : public VIRBinaryInstruction
{
public:
	/*! \brief All possible comparisons */
	enum Comparison
	{
		OrderedEqual,
		OrderedNotEqual,
		OrderedLessThan,
		OrderedLessOrEqual,
		OrderedGreater,
		OrderedGreaterOrEqual,
		UnorderedEqual,
		UnorderedNotEqual,
		UnorderedLessThan,
		UnorderedLessOrEqual,
		UnorderedGreaterThan,
		UnorderedGreaterOrEqual,
		IsANumber,
		NotANumber,
		InvalidComparison
	};
	
public:
	/*! \brief The comparison operation */
	Comparison comparison;
};

/*! \brief An add instruction */
class Add : public VIRBinaryInstruction
{
};

/*! \brief An and instruction */
class And : public VIRBinaryInstruction
{
};

/*! \brief Perform arithmetic shift right */
class Ashr : public VIRBinaryInstruction
{

};

/*! \brief An atomic operation instruction */
class Atom : public VIRBinaryInstruction
{
public:
	/*! \brief Possible atomic operations */
	enum Operation
	{
		AtomicAnd,
		AtomicOr,
		AtomicXor,
		AtomicCas,
		AtomicExch,
		AtomicAdd,
		AtomicInc,
		AtomicDec, 
		AtomicMin,
		AtomicMax,		
		InvalidOperation
	};

public:
	Operation operation;
	Operand   c;
};

/*! \brief Perform a thread group barrier */
class Bar : public VIRInstruction
{
public:
	
};

/*! \brief Perform a raw bitcast */
class Bitcast : public VIRUnaryInstruction
{

};

/*! \brief Perform a branch */
class Bra : public VIRInstruction
{
public:
	enum BranchModifier
	{
		UniformBranch,
		MultitargetBranch,
		InvalidModifier
	};

public:
	Operand target;
	BranchModifier modifier;
};

/*! \brief A floating point precision extension instruction */
class Fpext : public VIRUnaryInstruction
{

};

/*! \brief A floating point to signed integer instruction */
class Fptosi : public VIRUnaryInstruction
{

};

/*! \brief A floating point to unsigned integer instruction */
class Fptoui : public VIRUnaryInstruction
{

};

/*! \brief A floating point precision truncate instruction */
class Fptrunc : public VIRUnaryInstruction
{

};

/*! \brief Load a value from memory */
class Ld : public VIRUnaryInstruction
{

};

/*! \brief Logical shift right */
class Lshr : public VIRBinaryInstruction
{

};

/*! \brief Wait until memory operations at the specified level have completed */
class Membar : public VIRInstruction
{
public:
	enum Level
	{
		Thread,
		Cta,
		Kernel,
		InvalidLevel
	};

public:
	Level level;	
};


/*! \brief Multiply two operands together */
class Mul : public VIRBinaryInstruction
{

};

/*! \brief Perform a logical OR operation */
class Or : public VIRBinaryInstruction
{

};

/*! \brief Compare two operands and set a third predicate */
class SetP : public ComparisonInstruction
{

};

/*! \brief Sign extend an integer */
class Sext : public VIRUnaryInstruction
{

};

/*! \brief Perform signed division */
class Sdiv : public VIRUnaryInstruction
{

};

/*! \brief Perform shift left */
class Shl : public VIRBinaryInstruction
{

};

/*! \brief Convert a signed int to a floating point */
class Sitofp : public VIRUnaryInstruction
{

};

/*! \brief Perform a signed remainder operation */
class Srem : public VIRBinaryInstruction
{

};

/*! \brief Perform a store operation */
class St : public VIRUnaryInstruction
{

};

/*! \brief Perform a subtract operation */
class Sub : public VIRBinaryInstruction
{

};

/*! \brief Truncate an integer */
class Trunc : public VIRUnaryInstruction
{
	
};

/*! \brief Perform an unsigned division operation */
class Udiv : public VIRBinaryInstruction
{

};

/*! \brief Convert an unsigned int to a floating point */
class Uitofp : public VIRUnaryInstruction
{

};

/*! \brief Perform an unsigned remainder operation */
class Urem : public VIRBinaryInstruction
{

};

/*! \brief Perform a logical OR operation */
class Xor : public VIRBinaryInstruction
{

};

/*! \brief Zero extend an integer */
class Zext : public VIRUnaryInstruction
{
	
};


}


/*!
	\file PTXInstruction.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 15, 2009

	\brief base class for all instructions
*/

#ifndef IR_PTXINSTRUCTION_H_INCLUDED
#define IR_PTXINSTRUCTION_H_INCLUDED

#include <ocelot/ir/interface/Instruction.h>
#include <ocelot/ir/interface/PTXOperand.h>

namespace ir {

	class PTXInstruction: public Instruction {
	public:
		/*!
			Version number of the instruction
		*/
		enum Version {
			ptx1_0 = 0,
			ptx1_1 = 1,
			ptx1_2 = 2,
			ptx1_3 = 3,
			ptx1_4 = 4
		};
		
		/*!
			Hierarchy Level
		*/
		enum Level {
			CtaLevel,
			GlobalLevel,
			Level_Invalid
		};

		/*!
			List of opcodes for PTX instructions
		*/
		enum Opcode {
			Abs,
			Add,
			AddC,
			And,
			Atom,
			Bar,
			Bra,
			Brkpt,
			Call,
			CNot,
			Cos,
			Cvt,
			Div,
			Ex2,
			Exit,
			Ld,
			Lg2,
			Mad24,
			Mad,
			Max,
			Membar,
			Min,
			Mov,
			Mul24,
			Mul,
			Neg,
			Not,
			Or,
			Pmevent,
			Rcp,
			Red,
			Rem,
			Ret,
			Rsqrt,
			Sad,
			SelP,
			Set,
			SetP,
			Shl,
			Shr,
			Sin,
			SlCt,
			Sqrt,
			St,
			Sub,
			SubC,
			Tex,
			Trap,
			Vote,
			Xor,

			// Special instructions inserted by the analysis procedures
			Reconverge,
			Phi,
			Nop
		};

		/*!
			Modifiers for integer and floating-point instructions. The
			FP rounding-modes are mutually exclusive but compatible with
			sat.
		*/
		enum Modifier {
			hi = 1,			//< 
			lo = 2,			//<
			wide = 4,		//<
			sat = 8,		//< saturation modifier	
			rn = 32,		//< mantissa LSB rounds to nearest even
			rz = 64,		//< mantissa LSB roudns toward zero
			rm = 128,		//< mantissa LSB rounds toward negative infty
			rp = 256,		//< mantissa LSB rounds toward positive infty
			approx = 512, 	//< identify an approximate instruction
			ftz = 1024, 	//< flush to zero
			Modifier_invalid = 0
		};
			
		enum CarryFlag {
			None = 0,
			CC = 1
		};
		
		enum Volatility {
			Nonvolatile = 0,
			Volatile
		};
	
		enum AddressSpace {
			Reg = 0,
			SReg,
			Const,
			Global,
			Local,
			Param,
			Shared,
			Texture,
			AddressSpace_Invalid
		};

		enum AtomicOperation {
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
			AtomicOperation_Invalid
		};
		
		enum ReductionOperation {
			ReductionAnd,
			ReductionXor,
			ReductionOr,
			ReductionAdd,
			ReductionInc,
			ReductionDec,
			ReductionMin,
			ReductionMax,
			ReductionOperation_Invalid
		};

		enum VoteMode {
			All,
			Any,
			Uni,
			VoteMode_Invalid
		};

		/*!
			comparison operator
		*/
		enum CmpOp {
			Eq,
			Ne,
			Lt,
			Le,
			Gt,
			Ge,
			Lo,
			Ls,
			Hi,
			Hs,
			Equ,
			Neu,
			Ltu,
			Leu,
			Gtu,
			Geu,
			Num,
			Nan,
			CmpOp_Invalid
		};
		
		/*!
			Vector operation		
		*/
		typedef PTXOperand::Vec Vec;
		
		/*!
			boolean operator
		*/
		enum BoolOp {
			BoolAnd,
			BoolOr,
			BoolXor,
			BoolNop,
			BoolOp_Invalid
		};
		
		/*!
			geometry for textures		
		*/
		enum Geometry {
			_1d,
			_2d,
			_3d,
			Geometry_Invalid
		};

	public:
	
		static std::string toString( Version );
		static std::string toString( Level );
		static std::string toString( Vec );
		static std::string toString( AddressSpace );
		static std::string toString( AtomicOperation );
		static std::string toString( ReductionOperation );
		static std::string toString( CmpOp );
		static std::string toString( BoolOp );
		static std::string roundingMode( Modifier );
		static std::string toString( Modifier );
		static std::string toString( Geometry );
		static std::string modifierString( unsigned int, CarryFlag = None );
		static std::string toString( VoteMode );
		static std::string toString( Opcode );
		static bool isPt( const PTXOperand& );

	public:
		PTXInstruction( Version v = ptx1_0 );
		~PTXInstruction();

		bool operator==( const PTXInstruction& ) const;
		
		/*!
			Is this a valid instruction?
			
			return null string if valid, otherwise a description of why 
				not.
		*/
		std::string valid() const;

		/*!
			Instruction version.
		*/
		Version version;

		/*!
			Returns the guard predicate representation for the 
				instruction
		*/
		std::string guard() const;

		/*!
			Returns a parsable string representation of the instruction
		*/
		std::string toString() const;

		/*!
			Opcode of PTX instruction
		*/
		Opcode opcode;

		/*!
			indicates data type of instruction
		*/
		PTXOperand::DataType type;
	
		/*!
			optionally writes carry-out value to condition code register
		*/
		CarryFlag carry;

		union {
			/*!
				Flag containing one or more floating-point modifiers
			*/
			unsigned int modifier;

			/*!
				Comparison operator
			*/
			CmpOp comparisonOperator;

			/*!
				For load and store instructions, indicates which addressing 
					mode to use
			*/
			AddressSpace addressSpace;
			
			/*!
				For membar instructions the visibility level in the
					thread hierarchy
			*/
			Level level;
		};
	
		/*!
			If the instruction is predicated, which predicate register to use
			as a guard 
		*/
		PTXOperand pg;
				
		/*!
			Second destination register for SetP, otherwise unused
		*/
		PTXOperand pq;
		
		/*!
			Indicates whether target or source is a vector or scalar
		*/
		Vec vec;

		union {
			/*!
				If instruction type is atomic, select this atomic operation
			*/
			AtomicOperation atomicOperation;
			
			/*!
				If the instruction is a reduction, select this operation
			*/
			ReductionOperation reductionOperation;
			
			/*
				If instruction type is vote, specifies the mode of voting
			*/
			VoteMode vote;
			
			/*
				If instruction is a branch, is it .uni			
			*/
			bool uni;

			/*!
				Boolean operator
			*/
			BoolOp booleanOperator;

			/*!
				Indicates whether the target address space is volatile
			*/
			Volatility volatility;
			
			/*!
				Geometry if this is a texture instruction
			*/
			Geometry geometry;
			
			/*!
				Is this a divide full instruction?
			*/
			bool divideFull;
		};

		/*!
			Destination operand
		*/
		PTXOperand d;

		/*!
			Source operand a
		*/
		PTXOperand a;

		/*!
			Source operand b
		*/
		PTXOperand b;

		/*!
			Source operand c
		*/
		PTXOperand c;

		/* 
			Runtime annotations 
			
			The following members are used to annotate the instruction 
				at analysis time
		*/
	public:
		/*!
			Index of post dominator instruction at which possibly divergent
				branches reconverge
		*/
		int reconvergeInstruction;

		/*!
			Branch target instruction index
		*/
		int branchTargetInstruction;
	};

}

#endif


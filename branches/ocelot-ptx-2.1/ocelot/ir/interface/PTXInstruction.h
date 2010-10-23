/*! \file PTXInstruction.h
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
		/*! Hierarchy Level */
		enum Level {
			CtaLevel,
			GlobalLevel,
			Level_Invalid
		};

		/*!	List of opcodes for PTX instructions */
		enum Opcode {
			Abs,
			Add,
			AddC,
			And,
			Atom,
			Bar,
			Bfe,
			Bfi,
			Bfind,
			Bra,
			Brev,
			Brkpt,
			Call,
			Clz,
			CNot,
			CopySign,
			Cos,
			Cvt,
			Cvta,
			Div,
			Ex2,
			Exit,
			Fma,
			Isspacep,
			Ld,
			Ldu,
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
			Popc,
			Prefetch,
			Prefetchu,
			Prmt,
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
			Suld,
			Sured,
			Sust,
			Suq,
			TestP,
			Tex,
			Txq,
			Trap,
			Vabsdiff,
			Vadd,
			Vmad,
			Vmax,
			Vmin,
			Vset,
			Vshl,
			Vshr,
			Vsub,
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
			full = 2048, 	//< full division
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
			AddressSpace_Invalid = 0,
			Const,
			Global,
			Local,
			Param,
			Shared,
			Texture,
			Generic
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
		
		enum BarrierOperation {
			BarSync,
			BarArrive,
			BarReduction,
			BarrierOperation_invalid
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
			ReductionPopc,
			ReductionOperation_Invalid
		};
		
		enum CacheOperation {
			Ca,
			Cg,
			Cs,
			Cv,
			Wb,
			Wt,
			CacheOperation_Invalid
		};
		
		enum ClampOperation {
			TrapOOB,	// avoid colliding with PTXInstruction::Opcode::Trap
			Clamp,
			Zero,
			Mirror,
			ClampOperation_Invalid
		};

		/*! comparison operator */
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
		
		enum PermuteMode {
			DefaultPermute,
			ForwardFourExtract,
			BackwardFourExtract,
			ReplicateEight,
			EdgeClampLeft,
			EdgeClampRight,
			ReplicateSixteen
		};
			
		enum FloatingPointMode {
			Finite,
			Infinite,
			Number,
			NotANumber,
			Normal,
			SubNormal,
			FloatingPointMode_Invalid
		};
		
		enum FormatMode {
			Unformatted,
			Formatted,
			FormatMode_Invalid
		};
		
		/*! Vector operation */
		typedef PTXOperand::Vec Vec;
		
		/*! boolean operator */
		enum BoolOp {
			BoolAnd,
			BoolOr,
			BoolXor,
			BoolNop,
			BoolOp_Invalid
		};
		
		/*! geometry for textures */
		enum Geometry {
			_1d,
			_2d,
			_3d,
			Geometry_Invalid
		};

		enum SurfaceQuery {
			Width,
			Height,
			Depth,
			ChannelDataType,
			ChannelOrder,
			NormalizedCoordinates,
			SamplerFilterMode,
			SamplerAddrMode0,
			SamplerAddrMode1,
			SamplerAddrMode2,
			SurfaceQuery_Invalid
		};

		enum VoteMode {
			All,
			Any,
			Uni,
			VoteMode_Invalid
		};
		
	public:
		static std::string toString( Level );
		static std::string toString( PermuteMode );
		static std::string toString( FloatingPointMode );
		static std::string toString( Vec );
		static std::string toString( AddressSpace );
		static std::string toString( AtomicOperation );
		static std::string toString( BarrierOperation );
		static std::string toString( ReductionOperation );
		static std::string toString( SurfaceQuery );
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
		PTXInstruction( Opcode op = Nop, const PTXOperand& d = PTXOperand(), 
			const PTXOperand& a = PTXOperand(), 
			const PTXOperand& b = PTXOperand(), 
			const PTXOperand& c = PTXOperand() );
		~PTXInstruction();

		bool operator==( const PTXInstruction& ) const;
		
		/*! Is this a valid instruction?
			
			return null string if valid, otherwise a description of why 
				not.
		*/
		std::string valid() const;

		/*! Returns the guard predicate representation for the instruction */
		std::string guard() const;

		/*! Returns a parsable string representation of the instruction */
		std::string toString() const;

		/*! \brief Clone the instruction */
		Instruction* clone( bool copy = true ) const;

	public:
		/*! Opcode of PTX instruction */
		Opcode opcode;

		/*! indicates data type of instruction */
		PTXOperand::DataType type;

		/*! Flag containing one or more floating-point modifiers */
		unsigned int modifier;

		union {

			/*! Comparison operator */
			CmpOp comparisonOperator;

			/*! For load and store, indicates which addressing mode to use */
			AddressSpace addressSpace;
			
			/*! For membar, the visibility level in the thread hierarchy */
			Level level;
			
			/*! Shift amount flag for bfind instructions */
			bool shiftAmount;
			
			/*! Permute mode for prmt instructions */
			PermuteMode permuteMode;
			
			/*! For call instructions, indicates a tail call */
			bool tailCall;
			
			/*! For txq and suq instruction, specifies attributes */
			SurfaceQuery surfaceQuery;
			
			/*! For sust and suld instructions, indicates whether to store 
				unformatted binary datay or formatted store of a vector
				of 32-bit data */
			FormatMode formatMode;
			
			/*! Indicates which type of bar. instruction should be used */
			BarrierOperation barrierOperation;
		};
	
		/*! If the instruction is predicated, the guard */
		PTXOperand pg;
				
		/*! Second destination register for SetP, otherwise unused */
		PTXOperand pq;

		/*! Indicates whether target or source is a vector or scalar */
		Vec vec;

		union {

			/*! If instruction type is atomic, select this atomic operation */
			AtomicOperation atomicOperation;
			
			/*! If the instruction is a reduction, select this operation */
			ReductionOperation reductionOperation;
			
			/* If instruction type is vote, specifies the mode of voting */
			VoteMode vote;
			
			/* For TestP instructions, specifies the floating point mode */
			FloatingPointMode floatingPointMode;
			
			/* If instruction is a branch, is it .uni */
			bool uni;

			/*! Boolean operator */
			BoolOp booleanOperator;

			/*! Indicates whether the target address space is volatile */
			Volatility volatility;
						
			/*! Is this a divide full instruction? */
			bool divideFull;
			
			/*! If cvta instruction, indicates whether destination is 
				generic address or if source is generic address - true if 
				segmented address space, false if generic */
			bool toAddrSpace;
			
			/*! If the instruction updates the CC, what is the CC register */
			PTXOperand::RegisterType cc;
			
			/*! indicates how loads, stores, and prefetches should take place */
			CacheOperation cacheOperation;
		};
		
		/*! Geometry if this is a texture or surface instruction */
		Geometry geometry;

		union {
			/*! optionally writes carry-out value to condition code register */
			CarryFlag carry;
		
			/*! how to handle out-of-bounds accesses */
			ClampOperation clamp;
		};

		/*! Destination operand */
		PTXOperand d;

		/*! Source operand a */
		PTXOperand a;

		/*! Source operand b */
		PTXOperand b;

		/*! Source operand c */
		PTXOperand c;

	public:
	
		/*  Runtime annotations 
			
			The following members are used to annotate the instruction 
				at analysis time
		*/
		
		/*! \brief Index of post dominator instruction at which possibly 
			divergent branches reconverge */
		int reconvergeInstruction;

		union
		{
			/*! \brief Branch target instruction index */
			int branchTargetInstruction;
			/*! \brief Context switch reentry point */
			int reentryPoint;
			/*! \brief Is this a kernel argument in the parameter space? */
			bool isArgument;
		};
		/*!	The following are used for debugging information at runtime. */
	public:
		/*! \brief The index of the statement that this instruction was 
			created from */
		unsigned int statementIndex;
		/*! \brief The program counter of the instruction */
		unsigned int pc;
	};

}

#endif


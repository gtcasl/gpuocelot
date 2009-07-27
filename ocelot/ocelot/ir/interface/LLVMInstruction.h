/*!
	\file LLVMInstruction.h
	\date Wednesday July 15, 2009
	\author Gregroy Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMInstruction class.
*/

#ifndef LLVM_INSTRUCTION_H_INCLUDED
#define LLVM_INSTRUCTION_H_INCLUDED

#include <ocelot/ir/interface/Instruction.h>

namespace ir
{
	typedef bool LLVMI1;
	typedef char LLVMI8;
	typedef short LLVMI16;
	typedef int LLVMI32;
	typedef long long LLVMI64;
	
	typedef float LLVMF32;
	typedef double LLVMF64;

	/*! \brief A class used to represent any LLVM Instruction */
	class LLVMInstruction : public Instruction
	{
		public:
			/*! \brief The opcode of the instruction */
			enum Opcode
			{
				Add,
				Alloca,
				And,
				Ashr,
				Bitcast,	
				Br,
				Call,
				Extractelement,
				Extractvalue,
				Fadd,
				Fcmp,
				Fdiv,
				Fmul,
				Fpext,	
				Fptosi,	
				Fptoui,
				Fptrunc,	
				Free,
				Frem,
				Fsub,
				Getelementptr,
				Icmp,
				Insertelement,
				Insertvalue,
				Inttoptr,
				Invoke,
				Load,
				Lshr,
				Malloc,
				Mul,
				Or,
				Phi,
				Ptrtoint,
				Ret,
				Sdiv,
				Select,
				Sext,
				Shl,
				Shufflevector,
				Sitofp,
				Srem,
				Store,
				Sub,
				Switch,
				Trunc,
				Udiv,
				Uitofp,	
				Unreachable,
				Unwind,
				Urem,
				VaArg,
				Xor,
				Zext,
				InvalidOpcode
			};
			
			/*! \brief Supported LLVM Types */
			enum DataType
			{
				I1,
				I8,
				I16,
				I32,
				I64,
				F32,
				F64,
				InvalidDataType
			};
			
			/*! \brief Floating Point Comparison */
			enum Comparison
			{
				False, // no comparison, always returns false
				Oeq, // ordered and equal
				Ogt, // ordered and greater than
				Oge, // ordered and greater than or equal
				Olt, // ordered and less than
				Ole, // ordered and less than or equal
				One, // ordered and not equal
				Ord, // ordered (no nans)
				Ueq, // unordered or equal
				Ugt, // unordered or greater than
				Uge, // unordered or greater than or equal
				Ult, // unordered or less than
				Ule, // unordered or less than or equal
				Une, // unordered or not equal
				Uno, // unordered (either nans)
				True, // no comparison, always returns true
				Eq, // Integer equal
				Ne, // Integer not equal
				Sgt, // Signed greater than
				Sge, // Signed greater equal
				Slt, // Signed less than
				Sle // Signed less or equal
			};
			
			/*! \brief Valid calling conventions */
			enum CallingConvention
			{
				CCallingConvention,
				FastCallingConvention,
				ColdCallingConvention,
				DefaultCallingConvention,
				InvalidCallingConvention
			};
			
			/*! \brief Valid Parameter Attributes */
			enum ParameterAttribute
			{
				ZeroExtend,
				SignExtend,
				InRegister,
				ByValue,
				StructureReturn,
				NoAlias,
				NoCapture,
				Nested,
				InvalidParameterAttribute
			};
			
			/*! \brief Valid Function Attributes */
			enum FunctionAttribute
			{
				AlwaysInline = 1,
				NoInline = 2,
				OptimizeSize = 4,
				NoReturn = 8,
				NoUnwind = 16,
				ReadNone = 32,
				ReadOnly = 64,
				StackSmashingProtector = 128,
				StackSmashingProtectorRequired = 256,
				NoRedZone = 512,
				NoImplicitFloat = 1024,
				Naked = 2048
			};
			
			/*! \brief A class for an LLVM basic or derived type */
			class Type
			{
				public:
					/*! \brief All possible operand types */
					Category
					{
						Element, //! A single element of a base type
						Array, //! An array of elements
						Function, //! A function pointer
						Structure, //! An unconstrained ordered set of types
						PackedStructure, //! Structure with no padding
						Pointer, //! A pointer to a type
						Vector, //! A vector for use in SIMD instructions
						Opaque, //! An unknown type that has not been resolved
						InvalidCategory
					};
				
				public:
					/*! \brief A vector for a set of Types for the aggregates */
					typedef std::vector< Type > Vector;
			
				public:
					/*! \brief The datatype of the Type */
					DataType type;
					/*! \brief The category of the Type */
					Category category;
					/*! \brief The label of the operand */
					std::string label;
					/*! \brief The vector width of the operand */
					LLVMI32 vector;
				
				public:
					/*! \brief The constructor sets the type and pointer flag */
					Type( DataType t = InvalidDataType, 
						Category c = InvalidCategory, LLVMI32 v = 1 );			
				
				public:			
					/*! \brief A parsable string representation of the Type */
					std::string toString() const;
			};
			
			/*! \brief A class for a basic LLVM Operand */
			class Operand
			{
				public:
					/*! \brief The type of the operand */
					Type type;
					/*! \brief The name of the operand */
					std::string name;
					
				public:
					/*! \brief The constructor sets the type and pointer flag */
					Operand( const std::string& n = std::string(), 
						const Type& t = Type() );					
			};
			
		public:
		    /*! \brief The opcode of the instruction */
		    const Opcode opcode;
		
		public:
			/*! \brief Convert an opcode to a string parsable by LLVM */
			static std::string toString( Opcode o );
			/*! \brief Convert a datatype to a string parsable by LLVM */
			static std::string toString( DataType d );
			/*! \brief Convert a calling convention to a string */
			static std::string toString( CallingConvention cc );
			/*! \brief Convert a Parameter attribute to a string */
			static std::string toString( ParameterAttribute attribute );
			/*! \brief Convert a Comparison to a string */
			static std::string toString( Comparison comp );
			/*! \brief Convert a series of function attributes to a string */
			static std::string functionAttributesToString( int attributes );
			
		public:
			/*! \brief Default constructor */
			LLVMInstruction( Opcode op = InvalidOpcode );
			
			/*! \brief Copy constructor to prevent reassignment of opcode */
			LLVMInstruction( const LLVMInstruction& i );
			
			/*! \brief Assignment operator to prevent modification of opcode */
			const LLVMInstruction& operator=( const LLVMInstruction& i );
					
	};
	
	/*! \brief A generic 1 operand instruction */
	class LLVMUnaryInstruction : public LLVMInstruction
	{
		public:
			/*! \brief The destination operand */
			Operand d;
			
			/*! \brief The source operand */
			Operand a;
	
		public:
			/*! \brief Default constructor */
			LLVMUnaryInstruction( Opcode op = InvalidOpcode );
			
		public:
			virtual std::string toString() const;
			virtual std::string valid() const;
	};
	
	/*! \brief A generic 2 operand instruction */
	class LLVMBinaryInstruction : public LLVMInstruction
	{
		public:
			/*! \brief The destination operand */
			Operand d;
			
			/*! \brief The first source operand */
			Operand a;

			/*! \brief The second source operand */
			Operand b;

		public:
			/*! \brief Default constructor */
			LLVMBinaryInstruction( Opcode op = InvalidOpcode );
			
		public:
			virtual std::string toString() const;
			virtual std::string valid() const;
	};
	
	/*! \brief A generic conversion instruction */
	class LLVMConversionInstruction : public LLVMUnaryInstruction
	{
		public:
			/*! \brief Default constructor */
			LLVMConversionInstruction( Opcode op = InvalidOpcode );
			
		public:
			virtual std::string toString() const;
			virtual std::string valid() const;
	};
	
	/*! \brief A generic comparison instruction */
	class LLVMComparisonInstruction : public LLVMBinaryInstruction
	{
		public:
			/*! \brief Comparison operator */
			Comparison comparison;
		
		public:
			/*! \brief Default constructor */
			LLVMConversionInstruction( Opcode op = InvalidOpcode );
			
		public:
			virtual std::string toString() const;
			virtual std::string valid() const;
	};
	
	/*! \brief The LLVM add instruction */
	class LLVMAdd : public LLVMBinaryInstruction
	{
		public:
			/*! \brief No unsigned wrap */
			LLVMI1 noUnsignedWrap;
			
			/*! \brief No signed wrap */
			LLVMI1 noSignedWrap;
	
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMAdd();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM alloca instruction */
	class LLVMAlloca : public LLVMInstruction
	{
		public:
			/*! \brief The number of elements allocated */
			LLVMI32 elements;
			
			/*! \brief The alignment of elements */
			LLVMI32 alignment;
			
			/*! \brief The destination operand */
			Operand d;
			
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMAlloca( LLVMI32 e = 1, LLVMI32 a = 1);
			
		public:
			std::string toString() const;
			std::string valid() const;

	};
	
	/*! \brief The LLVM And instruction */
	class LLVMAnd : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMAnd();
	};
	
	/*! \brief The LLVM ashr instruction */
	class LLVMAshr : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMAshr();
	};
	
	/*! \brief The LLVM bitcast instruction */
	class LLVMBitcast : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMBitcast();
	};
		
	/*! \brief The LLVM br instruction */
	class LLVMBr : public LLVMInstruciton
	{
		public:
			/*! \brief The condition operand or empty if none */
			std::string condition;
			
			/*! \brief The iftrue label */
			std::string iftrue;
			
			/*! \brief The iffale label */
			std::string iffalse;
	
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMBr();
			
		public:
			std::string toString() const;
			std::string valid() const;	
	};
	
	/*! \brief The LLVM call instruction */
	class LLVMCall : public LLVMInstruction
	{
		public:
			/*! \brief Is this call eligible for tail call optimization? */
			LLVMI1 tail;
			
			/*! \brief The calling convention */
			CallingConvention convention;
			
			/*! \brief The return parameter attributes */
			ParameterAttribute returnAttributes;
			
			/*! \brief The return function call signiture if it 
				is a pointer to function */
			std::string signiture;
			
			/*! \brief The return operand */
			Operand d;
			
			/*! \brief The set of parameters */
			Operand::Vector parameters;
			
			/*! \brief Function attributes of the call */
			LLVMI32 functionAttributes;			
			
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMCall();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM extractelement instruction */
	class LLVMExtractelement : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMExtractelement();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM extractvalue instruction */
	class LLVMExtractvalue : public LLVMInstruction
	{
		public:
			/*! \brief The destination operand */
			Operand d;
			
			/*! \brief The source operand, must be an aggregate type */
			Operand a;
			
			/*! \brief Indexes within the aggregate type */
			Operand::Vector indices;
	
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMExtractvalue();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM fadd instruction */
	class LLVMFadd : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFadd();
	};
	
	/*! \brief The LLVM fcmp instruction */
	class LLVMFcmp : public LLVMComparisonInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFcmp();
	};
	
	/*! \brief The LLVM fdiv instruction */
	class LLVMFdiv : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFdiv();
	};
	
	/*! \brief The LLVM fmul instruction */
	class LLVMFmul : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFmul();
	};
	
	/*! \brief The LLVM fpext instruction */
	class LLVMFpext : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFpext();
	};
		
	/*! \brief The LLVM fptosi instruction */
	class LLVMFptosi : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFptosi();
	};
		
	/*! \brief The LLVM fptoui instruction */
	class LLVMFptoui : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFptoui();
	};
	
	/*! \brief The LLVM fptrunc instruction */
	class LLVMFptrunc : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFptrunc();
	};
		
	/*! \brief The LLVM free instruction */
	class LLVMFree : public LLVMUnaryInstruciton
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFree();
	};
	
	/*! \brief The LLVM frem instruction */
	class LLVMFrem : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFrem();
	};
	
	/*! \brief The LLVM fsub instruction */
	class LLVMFsub : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMFsub();
	};
	
	/*! \brief The LLVM getelementptr instruction */
	class LLVMGetelementptr : public LLVMInstruction
	{
		public:
			/*! \brief The destination operand */
			Operand d;
			
			/*! \brief The source operand, must be an aggregate type */
			Operand a;
			
			/*! \brief Indexes within the aggregate type */
			Operand::Vector indices;
	
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMGetelementptr();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM icmp instruction */
	class LLVMIcmp : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMIcmp();
	};
	
	/*! \brief The LLVM insertelement instruction */
	class LLVMInsertelement : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMInsertelement();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM insertvalue instruction */
	class LLVMInsertvalue : public LLVMInstruction
	{
		public:
			/*! \brief The destination operand */
			Operand d;
			
			/*! \brief The source operand, must be an aggregate type */
			Operand a;
			
			/*! \brief Indexes within the aggregate type */
			Operand::Vector indices;
			
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMInsertvalue();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM intotoptr instruction */
	class LLVMInttoptr : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMInttoptr();
	};
	
	/*! \brief The LLVM invoke instruction */
	class LLVMInvoke : public LLVMInstruction
	{
		public:
			/*! \brief The return operand */
			Operand d;
			
			/*! \brief The calling convention */
			CallingConvention convention;
			
			/*! \brief The return parameter attributes */
			ParameterAttribute returnAttributes;
			
			/*! \brief The return function call signiture if it 
				is a pointer to function */
			std::string signiture;
			
			/*! \brief The set of parameters */
			Operand::Vector parameters;
			
			/*! \brief Function attributes of the call */
			LLVMI32 functionAttributes;
			
			/*! \brief The label reached when the callee returns */
			std::string tolabel;
			
			/*! \brief The label reached when the callee hits unwind */	
			std::string unwindlabel;

		public:
			/*! \brief The default constructor sets the opcode */
			LLVMInvoke();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM load instruction */
	class LLVMLoad : public LLVMUnaryInstruction
	{
		public:
			/*! \brief Is the load volatile */
			LLVMI1 isVolatile;
	
			/*! \brief The alignment requirement of the load */
			LLVMI32 alignment;
	
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMLoad();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM lshr instruction */
	class LLVMLshr : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMLshr();
	};
	
	/*! \brief The LLVM malloc instruction */
	class LLVMMalloc : public LLVMInstruction
	{
		public:
			/*! \brief The number of elements allocated */
			LLVMI32 elements;
			
			/*! \brief The alignment of elements */
			LLVMI32 alignment;
			
			/*! \brief The destination operand */
			Operand d;

		public:
			/*! \brief The default constructor sets the opcode */
			LLVMMalloc();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM mul instruction */
	class LLVMMul : public LLVMBinaryInstruction
	{
		public:
			/*! \brief No unsigned wrap */
			LLVMI1 noUnsignedWrap;
			
			/*! \brief No signed wrap */
			LLVMI1 noSignedWrap;
		
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMMul();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM or instruction */
	class LLVMOr : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMOr();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM phi instruction */
	class LLVMPhi : public LLVMInstruction
	{
		public:
			/*! \brief Class for a combination of an operand and a label */
			class Node
			{
				public:
					/*! Operand */
					Operand operand;
					/*! Label of the BB that this operand comes from */
					std::string label; 
			};
			
			/*! \brief A vector of Nodes */
			typedef std::vector< Node > NodeVector;
		
		public:
			/*! \brief The destination operand */
			Operand d;
			
			/*! \brief The list of Phi Nodes */
			NodeVector nodes;
					
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMPhi();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM ptrtoint instruction */
	class LLVMPtrtoint : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMPtrtoint();
	};
	
	/*! \brief The LLVM Add instruction */
	class LLVMRet : public LLVMInstruction
	{
		public:
			/*! \brief The destination operand */
			Operand d;
		
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMRet();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM sdiv instruction */
	class LLVMSdiv : public LLVMBinaryInstruction
	{
		public:
			/*! \brief Should the division be gauranteed to be exact? */
			LLVMI1 exact;
			
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMSdiv();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM select instruction */
	class LLVMSelect : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The condition that determines which operand to select */
			Operand condition;
	
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMSelect();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM sext instruction */
	class LLVMSext : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMSext();
	};
	
	/*! \brief The LLVM shl instruction */
	class LLVMShl : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMShl();
	};
	
	/*! \brief The LLVM shufflevector instruction */
	class LLVMShufflevector : public LLVMBinaryInstruction
	{
		public:
			/*! \brief A Mask is a vector of indices */
			typedef std::vector< LLVMI32 > Mask;
	
		public:
			/*! \brief The shuffle mask */
			Mask mask;
		
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMShufflevector();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM sitofp instruction */
	class LLVMSitofp : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMSitofp();
	};
	
	/*! \brief The LLVM srem instruction */
	class LLVMSrem : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMSrem();
	};
	
	/*! \brief The LLVM store instruction */
	class LLVMStore: public LLVMUnaryInstruction
	{
		public:
			/*! \brief Is the load volatile */
			LLVMI1 isVolatile;
	
			/*! \brief The alignment requirement of the load */
			LLVMI32 alignment;
			
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMStore();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM sub instruction */
	class LLVMSub: public LLVMBinaryInstruction
	{
		public:
			/*! \brief No unsigned wrap */
			LLVMI1 noUnsignedWrap;
			
			/*! \brief No signed wrap */
			LLVMI1 noSignedWrap;
			
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMSub();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM switch instruction */
	class LLVMSwitch : public LLVMInstruction
	{
		public:
			/*! \brief Class for a combination of an operand and a label */
			class Node
			{
				public:
					/*! Operand */
					Operand operand;
					/*! Label of the BB that this operand comes from */
					std::string label; 
			};
			
			/*! \brief A vector of Nodes */
			typedef std::vector< Node > NodeVector;
			
		public:
			/*! \brief Comparison value */
			Operand comparison;
			
			/*! \brief Default destination label */
			std::string defaultTarget;
			
			/*! \brief List of possible other destinations */
			NodeVector targets;
		
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMSwitch();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM trunc instruction */
	class LLVMTrunc : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMTrunc();
	};
	
	/*! \brief The LLVM udiv instruction */
	class LLVMUdiv : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMUdiv();
	};
	
	/*! \brief The LLVM uitofp instruction */
	class LLVMUitofp : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMUitofp();
	};
		
	/*! \brief The LLVM unreachable instruction */
	class LLVMUnreachable : public LLVMInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMUnreachable();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM unwind instruction */
	class LLVMUnwind : public LLVMInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMUnwind();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM urem instruction */
	class LLVMUrem : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMUrem();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM va_arg instruction */
	class LLVMVaArg : public LLVMUnaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMVaArg();
			
		public:
			std::string toString() const;
			std::string valid() const;
	};
	
	/*! \brief The LLVM xor instruction */
	class LLVMXor : public LLVMBinaryInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMXor();
	};
	
	/*! \brief The LLVM zext instruction */
	class LLVMZext : public LLVMConversionInstruction
	{
		public:
			/*! \brief The default constructor sets the opcode */
			LLVMZext();
	};
	
}

#endif



/*!
	\file PTXOperand.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief internal representation of a PTX operand
*/

#ifndef IR_PTXOPERAND_H_INCLUDED
#define IR_PTXOPERAND_H_INCLUDED

#include <string>
#include <vector>
#include <functional>
#include <ocelot/ir/interface/Instruction.h>

namespace ir {

	typedef unsigned char PTXU8;
	typedef unsigned short PTXU16;
	typedef unsigned int PTXU32;
	typedef unsigned long long PTXU64;
	
	typedef char PTXS8;
	typedef short PTXS16;
	typedef int PTXS32;
	typedef long long PTXS64;
	
	typedef float PTXF32;
	typedef double PTXF64;
	
	typedef PTXU8 PTXB8;
	typedef PTXU16 PTXB16;
	typedef PTXU32 PTXB32;
	typedef PTXU64 PTXB64;

	class PTXOperand {
	public:
		//! addressing mode of operand
		enum AddressMode {
			Register,			//< use as register variable
			Indirect,			//< indirect access
			Immediate,			//< treat as immediate value
			Address,			//< treat as addressable variable
			Label,				//< operand is a label
			Special,			//< special register
			Invalid
		};

		/*! Type specifiers for instructions */
		enum DataType {
			s8 = 0,
			s16,
			s32,
			s64,
			u8 = 4,
			u16,
			u32,
			u64,
			f16 = 8,
			f32,
			f64,
			b8,
			b16,
			b32,
			b64,
			pred,
			TypeSpecifier_invalid
		};

		/*!	Special register names */
		enum SpecialRegister {
			tid,
			ntid,
			laneId,
			warpId,
			warpSize,
			ctaId,
			nctaId,
			smId,
			nsmId,
			gridId,
			clock,
			clock64,
			lanemask_eq,
			lanemask_le,
			lanemask_lt,
			lanemask_ge,
			lanemask_gt,
			pm0,
			pm1,
			pm2,
			pm3,
			SpecialRegister_invalid
		};
		
		enum PredicateCondition {
			Pred,		//< instruction executes if predicate is true
			InvPred,	//< instruction executes if predicate is false
			PT,			//< predicate is always true
			nPT			//< predicate is always false
		};
	
		enum Vec {
			v1 = 1, 			//< scalar
			v2 = 2,				//< vector2
			v4 = 4				//< vector4
		};
		
		enum VectorIndex {
			iAll = 0, //! Refers to the complete vector
			ix = 1, //! Only refers to the x index of the vector
			iy = 2, //! Only refers to the y index of the vector
			iz = 3, //! Only refers to the z index of the vector
			iw = 4 //! Only refers to the w index of the vector
		};

		typedef std::vector< PTXOperand > Array;

		typedef Instruction::RegisterType RegisterType;

	public:
		static std::string toString( VectorIndex );
		static std::string toString( DataType );
		static std::string toString( SpecialRegister );
		static std::string toString( AddressMode );
		static std::string toString( DataType, RegisterType );
		static bool isFloat( DataType );
		static bool isInt( DataType );
		static bool isSigned( DataType );
		static unsigned int bytes( DataType );
		static bool valid( DataType, DataType );
		static bool relaxedValid( DataType, DataType );
		
	public:
		PTXOperand();
		PTXOperand(SpecialRegister r, VectorIndex i = iAll);
		PTXOperand(const std::string& label);
		PTXOperand(AddressMode m, DataType t, RegisterType r = 0, 
			int o = 0, Vec v = v1);
		~PTXOperand();

		std::string toString() const;
		std::string registerName() const;
		unsigned int bytes() const;

		//! identifier of operand
		std::string identifier;
		
		//! addressing mode of operand
		AddressMode addressMode;

		//! data type for PTX instruction
		DataType type;

		//!	offset when used with an indirect addressing mode
		union {
			int offset;
			VectorIndex vIndex;
		};
		
		//! immediate-mode value of operand
		union {
			long long unsigned int imm_uint;
			long long int imm_int;
			double imm_float;
			PredicateCondition condition;
			SpecialRegister special;
		};

		/*! Identifier for register */
		RegisterType reg;
		
		//! Indicates whether target or source is a vector or scalar
		Vec vec;
		
		//! Array if this is a vector
		Array array;
		
	};

}

namespace std {
	template<> inline size_t hash<ir::PTXOperand::DataType>::operator()( 
		ir::PTXOperand::DataType t) const
	{
		return (size_t)t;
	}
}

#endif


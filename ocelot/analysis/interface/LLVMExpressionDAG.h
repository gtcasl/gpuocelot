/*!
	\file LLVMExpressionDAG.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date May 3, 2012
	\brief data structure for enumerating all dependencies for a particular instruction
*/

#ifndef OCELOT_ANALYSIS_LLVMEXPRESSIONDAG_H_INCLUDED
#define OCELOT_ANALYSIS_LLVMEXPRESSIONDAG_H_INCLUDED

// C++ includes
#include <list>
#include <map>
#include <vector>

// Ocelot includes
#include <ocelot/analysis/interface/LLVMUniformVectorization.h>

// Forward declarations
namespace llvm {
	class Constant;
	class ConstantExpr;
	class Value;
	class Instruction;
	class LoadInst;
	class BinaryOperator;
	class UnaryInstruction;
}

namespace analysis {

	/*!
		\brief 
	*/
	class LLVMExpressionDAG {
	public:
		typedef std::vector< llvm::Value *> ValueVector;
		typedef std::vector< llvm::Instruction *> InstructionVector;
	
		class Expression;
		class Instruction;
		class Constant;
		class ThreadInvariant;
		class UnaryExpression;
		class BinaryExpression;
		class AffineExpression;
	
		//! \brief base class for expression nodes
		class Expression {
		public:
			enum Type {
				expression,
				constant,
				threadInvariant,
				instruction,
				unaryExpression,
				binaryExpression,
				affineExpression,
				Type_invalid
			};
			
		public:
			Expression();
			Expression(llvm::Value *value, Type type = expression);
			~Expression();
		
			Type type() const { return _type; }
			llvm::Value * asValue() const { return _value; }
			
			bool isConstant() const;
			bool isThreadInvariant() const;
			bool isAffine() const;
			
		protected:
			Type _type;
			llvm::Value *_value;
		};
		typedef std::vector< Expression *> ExpressionVector;
		
		//!
		class Instruction: public Expression {
		public:
			Instruction();
			Instruction(llvm::Instruction *inst);
			~Instruction();
			
			static bool classof(const Expression *expression);
			
			llvm::Instruction *asInstruction() const;
		};
		
		//! \brief constant value in the program
		class Constant: public Expression {
		public:
			Constant();
			Constant(llvm::ConstantExpr *expr);
			Constant(llvm::Constant *constant);
			~Constant();
			
			static bool classof(const Expression *expression);
			
			llvm::Constant *asConstant() const;
			
			//! returns true if this is a numerical expression
			bool isNumerical() const;
			
		public:
		};
		
		//! Non-constant but thread-invariant expression
		class ThreadInvariant: public Expression {
		public:
			ThreadInvariant();
			~ThreadInvariant();
			
			static bool classof(const Expression *expression);
		};
		
		//! captures unary operations such as int and pointer casts that don't affect thread variance
		class UnaryExpression: public Expression {
		public:
			enum Operator {
				Noop,
				ZExtend,
				IntegerCast,
				IntToPointer,
				PointerToInt,
				FloatToInt,
				IntToFloat,
				Load,
				Operator_invalid
			};
		public:
		
			UnaryExpression();
			UnaryExpression(llvm::LoadInst *inst);
			UnaryExpression(llvm::UnaryInstruction *inst);
			~UnaryExpression();
			
			bool isLinear() const;
			
			static bool classof(const Expression *expression);
			
			Operator getOperator() const { return _operator; }
			
		protected:
			Operator _operator;
		};
		
		//!
		class BinaryExpression: public Expression {
		public:
			enum Operator {
				Add,
				Div,
				Mul,
				ShiftLeft,
				ShiftRight,
				Store,
				Sub,
				Operator_invalid
			};
		public:
		
			BinaryExpression();
			BinaryExpression(llvm::BinaryOperator *inst);
			BinaryExpression(llvm::StoreInst *inst);
			~BinaryExpression();
			
			static bool classof(const Expression *expression);
		
			Operator getOperator() const { return _operator; }
			const ExpressionVector & operands() const { return _operands; }
		
		protected:
			Operator _operator;
			ExpressionVector _operands;
		};
		
		/*! \brief Captures expressions of the form value(tid) = base + (tid)*sizeof(value)
			where base is ThreadInvariant */
		class AffineExpression: public Expression {
		public:
			AffineExpression();
			~AffineExpression();
			
			static bool classof(const Expression *expression);
			
			Expression *base() const;
			Expression *threadId() const;
			Constant *constant() const;
			
			BinaryExpression *threadExpression() const;
			
		protected:
		
		};
	
	public:
		LLVMExpressionDAG(const LLVMUniformVectorization::ThreadLocalArgument &threadArguments, 
			llvm::Instruction *_inst);
	
		const Expression *root() const { return _root; }
	
	protected:
		Expression * _construct(const LLVMUniformVectorization::ThreadLocalArgument &threadArguments,
			llvm::Value *_value);
	
	protected:
	
		Expression *_root;
	};
	
	/*!
		\brief analysis class that accumulates invariant information as demanded by queries
	*/
	class ThreadAffineAnalysis {
	public:
		ThreadAffineAnalysis();
		~ThreadAffineAnalysis();
		
	public:
	
		bool isThreadInvariant(llvm::Instruction *instruction);
		bool isAffinePointer(llvm::Instruction *pointer);
	
	
	protected:
		
	};

}

#endif


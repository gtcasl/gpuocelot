/*!
	\file LLVMExpressionDAG.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date March 3, 2012
	\brief analysis data structure for determining and storing thread-invariance and affine results
*/

// C++ includes
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <functional>

// System includes
#include <execinfo.h>

// boost includes
#include <boost/lexical_cast.hpp>

// Ocelot includes
#include <ocelot/analysis/interface/LLVMExpressionDAG.h>

// LLVM includes
#include <llvm/Instructions.h>
#include <llvm/Constants.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Support/CFG.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Pass.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>
#include <hydrazine/interface/Casts.h>

////////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_BASE 0

#define REPORT_INITIAL_SUBKERNEL 0
#define REPORT_FINAL_SUBKERNEL 0

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMExpressionDAG::Expression::Expression(): _type(expression), _value(0) {

}

analysis::LLVMExpressionDAG::Expression::Expression(llvm::Value *value, Type type): _type(type), _value(value) {

}

analysis::LLVMExpressionDAG::Expression::~Expression() {

}

bool analysis::LLVMExpressionDAG::Expression::isConstant() const {
	return false;
}

bool analysis::LLVMExpressionDAG::Expression::isThreadInvariant() const {
	return false;
}

bool analysis::LLVMExpressionDAG::Expression::isAffine() const {
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMExpressionDAG::Instruction::Instruction() {

}

analysis::LLVMExpressionDAG::Instruction::Instruction(llvm::Instruction *inst): 
	Expression(inst, Expression::instruction) {

}

analysis::LLVMExpressionDAG::Instruction::~Instruction() {

}

bool analysis::LLVMExpressionDAG::Instruction::classof(const Expression *expression) {
	return false;
}

llvm::Instruction *analysis::LLVMExpressionDAG::Instruction::asInstruction() const {
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMExpressionDAG::Constant::Constant() {

}

analysis::LLVMExpressionDAG::Constant::Constant(llvm::ConstantExpr *expr) {

}

analysis::LLVMExpressionDAG::Constant::Constant(llvm::Constant *constant): 
	Expression(constant, Expression::constant) {

}

analysis::LLVMExpressionDAG::Constant::~Constant() {

}

bool analysis::LLVMExpressionDAG::Constant::classof(const Expression *expression) {
	return false;
}

llvm::Constant *analysis::LLVMExpressionDAG::Constant::asConstant() const {
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMExpressionDAG::ThreadInvariant::ThreadInvariant() {

}

analysis::LLVMExpressionDAG::ThreadInvariant::~ThreadInvariant() {

}

bool analysis::LLVMExpressionDAG::ThreadInvariant::classof(const Expression *expression) {
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMExpressionDAG::UnaryExpression::UnaryExpression() {

}

analysis::LLVMExpressionDAG::UnaryExpression::UnaryExpression(llvm::LoadInst *inst):
	Expression(inst, Expression::unaryExpression), _operator(Load) {

}

analysis::LLVMExpressionDAG::UnaryExpression::UnaryExpression(llvm::UnaryInstruction *inst):
	Expression(inst, Expression::unaryExpression), _operator(Operator_invalid) {

}

analysis::LLVMExpressionDAG::UnaryExpression::~UnaryExpression() {

}

bool analysis::LLVMExpressionDAG::UnaryExpression::isLinear() const {
	return false;
}

bool analysis::LLVMExpressionDAG::UnaryExpression::classof(const Expression *expression) {
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMExpressionDAG::BinaryExpression::BinaryExpression() {

}

analysis::LLVMExpressionDAG::BinaryExpression::BinaryExpression(llvm::BinaryOperator *inst):
	Expression(inst, Expression::binaryExpression), _operator(Operator_invalid)  {

}

//analysis::LLVMExpressionDAG::BinaryExpression::BinaryExpression(llvm::StoreInst *inst);

analysis::LLVMExpressionDAG::BinaryExpression::~BinaryExpression() {

}

bool analysis::LLVMExpressionDAG::BinaryExpression::classof(const Expression *expression) {
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMExpressionDAG::AffineExpression::AffineExpression() {

}

analysis::LLVMExpressionDAG::AffineExpression::~AffineExpression() {

}

bool analysis::LLVMExpressionDAG::AffineExpression::classof(const Expression *expression) {
	return false;
}

analysis::LLVMExpressionDAG::Expression *analysis::LLVMExpressionDAG::AffineExpression::base() const {
	return 0;
}

analysis::LLVMExpressionDAG::Expression *analysis::LLVMExpressionDAG::AffineExpression::threadId() const {
	return 0;
}

analysis::LLVMExpressionDAG::Constant *analysis::LLVMExpressionDAG::AffineExpression::constant() const {
	return 0;
}

analysis::LLVMExpressionDAG::BinaryExpression *analysis::LLVMExpressionDAG::AffineExpression::threadExpression() const {
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMExpressionDAG::LLVMExpressionDAG(
	const LLVMUniformVectorization::ThreadLocalArgument &threadArguments, llvm::Instruction *_inst) {

}

analysis::LLVMExpressionDAG::Expression * analysis::LLVMExpressionDAG::_construct(
	const LLVMUniformVectorization::ThreadLocalArgument &threadArguments, llvm::Value *_value) {
	
	Expression *expression = 0;
	if (llvm::ConstantExpr *constExpr = llvm::dyn_cast<llvm::ConstantExpr>(_value)) {
		Constant *constantExpression = new Constant(constExpr);
		expression = constantExpression;
	}
	else if (llvm::Constant *constant = llvm::dyn_cast<llvm::Constant>(_value)) {
		Constant *constantValue = new Constant(constant);
		expression = constantValue;
	}
	else if (llvm::BinaryOperator *instruction = llvm::dyn_cast<llvm::BinaryOperator>(_value)) {
		BinaryExpression *binaryExpression = new BinaryExpression(instruction);
		expression = binaryExpression;
	}
	else if (llvm::LoadInst *load = llvm::dyn_cast<llvm::LoadInst>(_value)) {
		UnaryExpression *unaryLoad = new UnaryExpression(load);
		expression = unaryLoad;
	}
	else if (llvm::UnaryInstruction *instruction = llvm::dyn_cast<llvm::UnaryInstruction>(_value)) {
		UnaryExpression *unaryInstruction = new UnaryExpression(instruction);
		expression = unaryInstruction;
	}
	else if (llvm::Instruction *inst = llvm::dyn_cast<llvm::Instruction>(_value)) {
		Instruction *instruction = new Instruction(inst);
		
		expression = instruction;
	}
	else {
		expression = new Expression(_value);
	}
	return expression;
}

////////////////////////////////////////////////////////////////////////////////////////////////////


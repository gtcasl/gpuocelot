/*!
	\file AffineInstructionSet.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date May 3, 2012
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
#include <ocelot/analysis/interface/AffineInstructionSet.h>

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

#define REPORT_BASE 1

////////////////////////////////////////////////////////////////////////////////////////////////////

std::string String(llvm::Type *value);
std::string String(llvm::Value *value);
std::string String(llvm::Type *value);

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::AffineInstructionSet::AffineInstructionSet(
	llvm::Function *function,
	const LLVMUniformVectorization::ThreadLocalArgument &threadArguments) {

	// initialize some values to the invariant sets
	for (int i = 0; LLVMUniformVectorization::ThreadLocalArgumentInstances[i] !=
		&analysis::LLVMUniformVectorization::ThreadLocalArgument::ptrThreadDescriptorArray; i++) {
		
		if (!LLVMUniformVectorization::ThreadLocalArgumentVarianceMap[i]) {
			_setInvariant(threadArguments.*(LLVMUniformVectorization::ThreadLocalArgumentInstances[i]));
		}
	}
	
	if (threadArguments.threadIdUses == 1) {
		// only threadIdx.x is used
		report("  threadId.x is only thread ID used");
		_threadIds.insert(threadArguments.threadId_x);
	}
	else {
		report("  too complex");
	}
	
	// globals
	llvm::Module *module = function->getParent();
	for (llvm::Module::global_iterator global_it = module->global_begin(); 
		global_it != module->global_end(); ++global_it) {
	
		_setInvariant(&*global_it);
	}
}

analysis::AffineInstructionSet::~AffineInstructionSet() {

}

bool analysis::AffineInstructionSet::_setAffine(llvm::Value *value) {
	report("  marking " << String(value) << "; as affine");
	_affineValues.insert(value);
	return true;
}

bool analysis::AffineInstructionSet::_setInvariant(llvm::Value *value) {
	report("  marking " << String(value) << "; as invariant");
	_invariantValues.insert(value);
	return true;
}

bool analysis::AffineInstructionSet::_setVariant(llvm::Value *value) {
	report("  marking " << String(value) << "; as thread-variant");
	_variantValues.insert(value);
	return false;
}

void analysis::AffineInstructionSet::write(std::ostream &out) const {
	out << "Thread-Invariant values:\n";
	for (ValueSet::const_iterator val_it = _invariantValues.begin(); val_it != _invariantValues.end();
		++val_it) {
		
		out << "  " << String(*val_it) << "\n";
	}
	
	out << "Affine values:\n";
	for (ValueSet::const_iterator val_it = _affineValues.begin(); val_it != _affineValues.end();
		++val_it) {
		
		out << "  " << String(*val_it) << "\n";
	}
	out << std::flush;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

llvm::Value *analysis::AffineInstructionSet::_walk(llvm::Value *value) {
	bool walking = false;
	do {
		llvm::CastInst *cast = llvm::dyn_cast<llvm::CastInst>(value);
		if (cast && cast->isIntegerCast()) {
			value = cast->getOperand(0);
		}
	} while (walking);
	return value;
}

bool analysis::AffineInstructionSet::isThreadInvariant(llvm::Value *value) {
	report("isThreadInvariant(" << String(value) << ")");
	
	value = _walk(value);
	
	if (_invariantValues.find(value) != _invariantValues.end()) {
		return true;
	}
	if (_affineValues.find(value) != _affineValues.end()) {
		return false;
	}
	if (_variantValues.find(value) != _variantValues.end()) {
		return false;
	}
	if (_threadIds.find(value) != _threadIds.end()) {
		return false;
	}
	
	if (llvm::dyn_cast<llvm::Constant>(value)) {
		return _setInvariant(value);
	}
	else if (llvm::UnaryInstruction *unary = llvm::dyn_cast<llvm::UnaryInstruction>(value)) {
		if (llvm::CastInst *cast = llvm::dyn_cast<llvm::CastInst>(unary)) {
			if (isThreadInvariant(cast->getOperand(0))) {
				return _setInvariant(cast);
			}
			else {
				return false;
			}
		}
		else if (llvm::LoadInst *load = llvm::dyn_cast<llvm::LoadInst>(unary)) {
			if (isThreadInvariant(load->getPointerOperand())) {
				return _setInvariant(load);
			}
		}
	}
	else if (llvm::BinaryOperator *binary = llvm::dyn_cast<llvm::BinaryOperator>(value)) {
		bool operand0 = isThreadInvariant(binary->getOperand(0));
		bool operand1 = isThreadInvariant(binary->getOperand(1));
		if (operand0 && operand1) {
			_setInvariant(binary->getOperand(0));
			return _setInvariant(binary->getOperand(1));
		}
		else {
			return false;
		}
	}
	
	return false;
}

bool analysis::AffineInstructionSet::isAffine(llvm::Value *value) {
	report("isAffine(" << String(value) << ")");
	
	value = _walk(value);
	
	// memoize results for fast lookups
	if (_invariantValues.find(value) != _invariantValues.end()) {
		return true;
	}
	if (_affineValues.find(value) != _affineValues.end()) {
		return true;
	}
	if (_variantValues.find(value) != _variantValues.end()) {
		return false;
	}

	if (llvm::UnaryInstruction *unary = llvm::dyn_cast<llvm::UnaryInstruction>(value)) {
		if (llvm::CastInst *cast = llvm::dyn_cast<llvm::CastInst>(unary)) {
			if (isAffine(cast->getOperand(0))) {
				return _setAffine(cast);
			}
			if (isThreadInvariant(cast->getOperand(0))) {
				return _setInvariant(cast);
			}
		}
		else if (llvm::LoadInst *load = llvm::dyn_cast<llvm::LoadInst>(unary)) {
			if (isThreadInvariant(load->getPointerOperand())) {
				return _setInvariant(load);
			}
		}
	}
	else if (llvm::BinaryOperator *binary = llvm::dyn_cast<llvm::BinaryOperator>(value)) {
		if (_isBinaryOperatorAffine(binary)) {
			return true;
		}
		
		if ( isThreadInvariant(binary->getOperand(0)) && isThreadInvariant(binary->getOperand(1))) {
			return _setInvariant(binary);
		}
	}
	
	return false;
}

bool analysis::AffineInstructionSet::_isBinaryOperatorAffine(llvm::BinaryOperator *binary) {
	// tid * sizeof(int) => affine
	// invariant + affine => affine
	// invariant + invariant => invariant
	
	report("isBinaryOperatorAffine(" << String(binary) << ")");

	int constantExprIndex = -1;
	if (_threadIds.find(binary->getOperand(0)) != _threadIds.end()) {
		constantExprIndex = 1;
	}
	else if (_threadIds.find(binary->getOperand(1)) != _threadIds.end()) {
		constantExprIndex = 0;
	}
	if (constantExprIndex >= 0) {
		if (llvm::ConstantInt *constInt = llvm::dyn_cast<llvm::ConstantInt>(
			binary->getOperand(constantExprIndex))) {

			if (binary->getOpcode() == llvm::Instruction::Shl && constInt->getValue() == 2 
				&& constantExprIndex == 1) {
				
				return _setAffine(binary);
			}
			else if (binary->getOpcode() == llvm::Instruction::Mul && constInt->getValue() == 4) {

				return _setAffine(binary);
			}
		}
		
		return _setVariant(binary);
	}

	if ((isAffine(binary->getOperand(0)) && isThreadInvariant(binary->getOperand(1))) &&
		(isAffine(binary->getOperand(1)) && isThreadInvariant(binary->getOperand(0))) &&
		binary->getOpcode() == llvm::Instruction::Add) {
	
		return _setAffine(binary);
	}
	
	return _setVariant(binary);
}


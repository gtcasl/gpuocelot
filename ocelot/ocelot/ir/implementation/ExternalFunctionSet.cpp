/*! \file   ExternalFunctionSet.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Wednesday April 6, 2011
	\brief  The source file for the ExternalFunctionSet class.
*/

#ifndef EXTERNAL_FUCNTION_SET_CPP_INCLUDED
#define EXTERNAL_FUNCTION_SET_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/ir/interface/ExternalFunctionSet.h>
#include <ocelot/executive/interface/LLVMState.h>
#include <ocelot/ir/interface/PTXKernel.h>

#include <configure.h>

// Hydrazine Includes
#include <hydrazine/interface/Casts.h>

// LLVM Includes
#if HAVE_LLVM
#include <llvm/Transforms/Scalar.h>
#include <llvm/PassManager.h>
#include <llvm/Target/TargetData.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Assembly/Parser.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#endif

namespace ir
{

ExternalFunctionSet::ExternalFunction::ExternalFunction(const std::string& i,
	void* f)
: _name(i), _functionPointer(f)
{

}

void ExternalFunctionSet::ExternalFunction::call(void* parameters,
	const ir::PTXKernel::Prototype& p) const
{
	#ifdef HAVE_LLVM
	assertM(false, "Not implemented.");
	#else
	assertM(false, "LLVM required to call external host functions from PTX.");
	#endif
}

const std::string& ExternalFunctionSet::ExternalFunction::name() const
{
	return _name;
}

void* ExternalFunctionSet::ExternalFunction::externalFunctionPointer() const
{
	return _functionPointer;
}

ExternalFunctionSet::ExternalFunctionSet()
: _module(0)
{
	#if HAVE_LLVM
	_module = new llvm::Module("_ZOcelotExternalFunctionModule",
		llvm::getGlobalContext());
	#endif
}

ExternalFunctionSet::~ExternalFunctionSet()
{
	#if HAVE_LLVM
	for(FunctionSet::const_iterator external = _functions.begin();
		external != _functions.end(); ++external)
	{
		llvm::Function* function = _module->getFunction(
			external->second.name());
		executive::LLVMState::jit()->freeMachineCodeForFunction(function);
	}

	executive::LLVMState::jit()->removeModule(_module);

	delete _module;
	#endif
}

void ExternalFunctionSet::add(const std::string& name, void* pointer)
{
	assert(_functions.count(name) == 0);

	_functions.insert(std::make_pair(name, ExternalFunction()));
}

void ExternalFunctionSet::remove(const std::string& name)
{
	FunctionSet::iterator function = _functions.find(name);
	assert(function != _functions.end());
	
	_functions.erase(function);
}

const ExternalFunctionSet::ExternalFunction* ExternalFunctionSet::find(
	const std::string& name) const
{
	FunctionSet::const_iterator function = _functions.find(name);

	if(function == _functions.end()) return 0;
	
	return &function->second;
}


}

#endif


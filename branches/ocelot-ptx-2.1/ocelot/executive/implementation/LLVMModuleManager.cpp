/*!	\file LLVMModuleManager.cpp
	\date Thursday September 23, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMModuleManager class
*/

#ifndef LLVM_MODULE_MANAGER_CPP_INCLUDED
#define LLVM_MODULE_MANAGER_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/executive/interface/LLVMModuleManager.h>
#include <ocelot/executive/interface/LLVMState.h>

#include <ocelot/translator/interface/PTXToLLVMTranslator.h>

#include <ocelot/analysis/interface/SubkernelFormationPass.h>

#include <ocelot/ir/interface/LLVMKernel.h>
#include <ocelot/ir/interface/Module.h>

#include <ocelot/api/interface/OcelotConfiguration.h>

// LLVM Includes
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Assembly/Parser.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace executive
{

void LLVMModuleManager::loadModule(const ir::Module* m)
{
	_database.loadModule(m);
}

bool LLVMModuleManager::isModuleLoaded(const std::string& moduleName)
{
	return _database.isModuleLoaded(moduleName);
}

void LLVMModuleManager::unloadModule(const std::string& moduleName)
{
	_database.unloadModule(moduleName);
}

LLVMModuleManager::Function LLVMModuleManager::getFunction(const FunctionId& id)
{
	return _database.getFunction(id);
}

unsigned int LLVMModuleManager::totalFunctionCount()
{
	return _database.totalFunctionCount();
}

LLVMModuleManager::FunctionId LLVMModuleManager::getFunctionId(
	const std::string& moduleName, const std::string& kernelName)
{
	return _database.getFunctionId(moduleName, kernelName);
}


class DatabaseMessage
{
public:
	bool kill;
};

class GetFunctionMessage : public DatabaseMessage
{
public:
	std::string                   moduleName;
	std::string                   kernelName;
	LLVMModuleManager::FunctionId id;
	LLVMModuleManager::Function   function;
};

LLVMModuleManager::ModuleDatabase::ModuleDatabase() : _kernelCount(0)
{
	start();
}

LLVMModuleManager::ModuleDatabase::~ModuleDatabase()
{
	DatabaseMessage message;
	
	message.kill = true;
	
	send(&message);

	DatabaseMessage* reply;	
	receive(reply);
	
	for(ModuleMap::iterator module = _modules.begin();
		module != _modules.end(); ++module)
	{
		module->second.unload();
	}
}

void LLVMModuleManager::ModuleDatabase::loadModule(const ir::Module* module)
{
	assert(!isModuleLoaded(module->path()));
	ModuleMap::iterator newModule = _modules.insert(std::make_pair(
		module->path(), Module(module))).first;
	_kernelCount += newModule->second.kernelCount();
}

bool LLVMModuleManager::ModuleDatabase::isModuleLoaded(
	const std::string& moduleName)
{
	return _modules.count(moduleName) != 0;
}

void LLVMModuleManager::ModuleDatabase::unloadModule(
	const std::string& moduleName)
{
	ModuleMap::iterator module = _modules.find(moduleName);
	assert(module != _modules.end());
	
	_kernelCount -= module->second.kernelCount();
	module->second.unload();
	
	_modules.erase(module);
}

LLVMModuleManager::FunctionId LLVMModuleManager::ModuleDatabase::getFunctionId(
	const std::string& moduleName,
	const std::string& functionName)
{
	GetFunctionMessage message;
	
	message.kill         = false;
	message.moduleName   = moduleName;
	message.kernelName   = functionName;
	
	send(&message);
	
	GetFunctionMessage* reply = 0;
	receive(reply);
	assert(reply == &message);
	
	return message.id;
}

unsigned int LLVMModuleManager::ModuleDatabase::totalFunctionCount() const
{
	return _kernelCount;
}

LLVMModuleManager::Function LLVMModuleManager::ModuleDatabase::getFunction(
	const FunctionId& id)
{
	GetFunctionMessage message;
	
	message.kill         = false;
	message.id           = id;
	
	send(&message);
	
	GetFunctionMessage* reply = 0;
	receive(reply);
	assert(reply == &message);
	
	return message.function;
}

LLVMModuleManager::KernelAndTranslation::KernelAndTranslation(ir::PTXKernel* k,
	Function f) : kernel(k), function(f), module(0)
{

}

LLVMModuleManager::Module::Module(const ir::Module* m)
{	
	typedef analysis::SubkernelFormationPass::ExtractKernelsPass Pass;
	Pass pass;
	
	pass.initialize(*m);

	for(ir::Module::KernelMap::const_iterator kernel = m->kernels().begin(); 
		kernel != m->kernels().end(); ++kernel)
	{
		pass.runOnKernel(*kernel->second);
	}

	pass.finalize();
	
	for(Pass::KernelVectorMap::const_iterator 
		kernel = pass.kernels.begin(); 
		kernel != pass.kernels.end(); ++kernel)
	{
		for(analysis::SubkernelFormationPass::KernelVector::const_iterator 
			subkernel = kernel->second.begin();
			subkernel != kernel->second.end(); ++subkernel)
		{
			_kernels.insert(std::make_pair((*subkernel)->name,
				KernelAndTranslation(*subkernel, 0)));
		}
	}
}

ir::PTXKernel* LLVMModuleManager::Module::getKernel(
	const std::string& kernelName)
{
	PTXKernelMap::iterator kernel = _kernels.find(kernelName);
	
	if(kernel == _kernels.end()) return 0;
	
	return kernel->second.kernel;
}

unsigned int LLVMModuleManager::Module::kernelCount() const
{
	return _kernels.size();
}

static void translate(LLVMModuleManager::KernelAndTranslation& kernel)
{
	assert(kernel.function == 0);
	assert(kernel.module == 0);

	int level = api::OcelotConfiguration::get().executive.optimizationLevel;

	kernel.kernel->dfg();

	translator::PTXToLLVMTranslator translator(
		(translator::Translator::OptimizationLevel)level);
	ir::LLVMKernel* llvmKernel = static_cast<ir::LLVMKernel*>(
		translator.translate(kernel.kernel));
	
	llvmKernel->assemble();
	llvm::SMDiagnostic error;

	kernel.module = new llvm::Module(kernel.kernel->name.c_str(),
		llvm::getGlobalContext());

	kernel.module = llvm::ParseAssemblyString(llvmKernel->code().c_str(), 
		kernel.module, error, llvm::getGlobalContext());

	if(kernel.module == 0)
	{
		report("  Parsing kernel failed, dumping code:\n" 
			<< llvmKernel->numberedCode());
		std::string m;
		llvm::raw_string_ostream message(m);
		message << "LLVM Parser failed: ";
		error.Print(kernel.kernel->name.c_str(), message);

		throw hydrazine::Exception(message.str());
	}

	report(" Checking module for errors.");
	std::string verifyError;
	
	if(llvm::verifyModule(*kernel.module,
		llvm::ReturnStatusAction, &verifyError))
	{
		report("  Checking kernel failed, dumping code:\n" 
			<< llvmKernel->numberedCode());
		delete llvmKernel;

		throw hydrazine::Exception("LLVM Verifier failed for kernel: " 
			+ kernel.kernel->name + " : \"" + verifyError + "\"");
	}

	delete llvmKernel;
}

static void optimize(LLVMModuleManager::KernelAndTranslation& kernel)
{
	assertM(false, "Optimizing kernel not implemented.");
}

static void unloadTranslation(LLVMModuleManager::KernelAndTranslation& kernel)
{
	assert(kernel.function != 0);
	assert(kernel.module != 0);

	LLVMState::jit()->removeModule(kernel.module);
	delete kernel.module;

	assertM(false, "Freeing a translated kernel not implemented.");
}

void LLVMModuleManager::Module::unload()
{
	for(PTXKernelMap::iterator kernel = _kernels.begin();
		kernel != _kernels.end(); ++kernel)
	{
		delete kernel->second.kernel;
		if(kernel->second.function != 0) unloadTranslation(kernel->second);
	}
	
	_kernels.clear();
}

LLVMModuleManager::Function LLVMModuleManager::Module::getFunction(
	const std::string& kernelName)
{
	PTXKernelMap::iterator kernel = _kernels.find(kernelName);
	
	if(kernel == _kernels.end()) return 0;
	
	if(kernel->second.function == 0)
	{
		translate(kernel->second);
		optimize(kernel->second);
	}
	
	return kernel->second.function;
}

void LLVMModuleManager::ModuleDatabase::execute()
{
	DatabaseMessage* message;
	
	threadReceive(message);
	
	while(!message->kill)
	{
		GetFunctionMessage* functionMessage = static_cast<
			GetFunctionMessage*>(message);
		
		LLVMModuleManager::Function function = 0;
		
		ModuleMap::iterator module = _modules.find(functionMessage->moduleName);

		if(module != _modules.end())
		{
			function = module->second.getFunction(functionMessage->kernelName);
		}

		threadSend(reinterpret_cast<void*>(function));
	}

	threadSend(message);
}

LLVMModuleManager::ModuleDatabase LLVMModuleManager::_database;

}

#endif


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
#include <ocelot/analysis/interface/ConvertPredicationToSelectPass.h>

#include <ocelot/ir/interface/LLVMKernel.h>
#include <ocelot/ir/interface/Module.h>

#include <ocelot/api/interface/OcelotConfiguration.h>

#include <configure.h>

// Hydrazine Includes
#include <hydrazine/interface/Casts.h>

// LLVM Includes
#ifdef HAVE_LLVM
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

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace executive
{

////////////////////////////////////////////////////////////////////////////////
// LLVMModuleManager
void LLVMModuleManager::loadModule(const ir::Module* m, 
	translator::Translator::OptimizationLevel l)
{
	_database.loadModule(m, l);
}

bool LLVMModuleManager::isModuleLoaded(const std::string& moduleName)
{
	return _database.isModuleLoaded(moduleName);
}

void LLVMModuleManager::unloadModule(const std::string& moduleName)
{
	_database.unloadModule(moduleName);
}

unsigned int LLVMModuleManager::totalFunctionCount()
{
	return _database.totalFunctionCount();
}

void LLVMModuleManager::associate(hydrazine::Thread* thread)
{
	_database.associate(thread);
}

hydrazine::Thread::Id LLVMModuleManager::id()
{
	return _database.id();
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Helper Functions
static void optimizePTX(ir::PTXKernel& kernel,
	translator::Translator::OptimizationLevel optimization)
{
	report(" Building dataflow graph.");
	kernel.dfg();

	report(" Optimizing PTX");
	analysis::ConvertPredicationToSelectPass pass;
	
	report("  Running convert predication to select pass");
	pass.initialize(*kernel.module);
	pass.runOnKernel(kernel);
	pass.finalize();
}

static void translate(llvm::Module*& module, ir::PTXKernel& kernel)
{
	assert(module == 0);

	int level = api::OcelotConfiguration::get().executive.optimizationLevel;

	report(" Translating kernel.");
	translator::PTXToLLVMTranslator translator(
		(translator::Translator::OptimizationLevel)level);
	ir::LLVMKernel* llvmKernel = static_cast<ir::LLVMKernel*>(
		translator.translate(&kernel));
	
	report(" Assembling LLVM kernel.");
	llvmKernel->assemble();
	llvm::SMDiagnostic error;

	module = new llvm::Module(kernel.name.c_str(), llvm::getGlobalContext());

	report(" Parsing LLVM assembly.");
	module = llvm::ParseAssemblyString(llvmKernel->code().c_str(), 
		module, error, llvm::getGlobalContext());

	if(module == 0)
	{
		report("  Parsing kernel failed, dumping code:\n" 
			<< llvmKernel->numberedCode());
		std::string m;
		llvm::raw_string_ostream message(m);
		message << "LLVM Parser failed: ";
		error.Print(kernel.name.c_str(), message);

		throw hydrazine::Exception(message.str());
	}

	report(" Checking llvm module for errors.");
	std::string verifyError;
	
	if(llvm::verifyModule(*module, llvm::ReturnStatusAction, &verifyError))
	{
		report("  Checking kernel failed, dumping code:\n" 
			<< llvmKernel->numberedCode());
		delete llvmKernel;

		throw hydrazine::Exception("LLVM Verifier failed for kernel: " 
			+ kernel.name + " : \"" + verifyError + "\"");
	}

	delete llvmKernel;
}

static LLVMModuleManager::KernelAndTranslation::MetaData* generateMetadata(
	ir::PTXKernel& kernel, translator::Translator::OptimizationLevel level)
{
	LLVMModuleManager::KernelAndTranslation::MetaData* 
		metadata = new LLVMModuleManager::KernelAndTranslation::MetaData;
	report(" Building metadata.");
	
	if(level == translator::Translator::DebugOptimization
		|| level == translator::Translator::ReportOptimization)
	{
		report("  Adding debugging symbols");
		ir::ControlFlowGraph::BasicBlock::Id id = 0;
		
		for(analysis::DataflowGraph::iterator block = kernel.dfg()->begin();
			block != kernel.dfg()->end(); ++block)
		{
			block->block()->id = id++;
			metadata->blocks.insert(std::make_pair(block->id(), 
				block->block()));
		}
	}
	
	return metadata;
}

static void optimize(llvm::Module& module,
	translator::Translator::OptimizationLevel optimization)
{
	report(" Optimizing kernel at level " 
		<< translator::Translator::toString(optimization));
	#ifdef HAVE_LLVM
    unsigned int level = 0;
    bool space         = false;

	if(optimization == translator::Translator::BasicOptimization)
	{
		level = 1;
	}
	else if(optimization == translator::Translator::AggressiveOptimization)
	{
		level = 2;
	}
	else if(optimization == translator::Translator::SpaceOptimization)
	{
		level = 2;
		space = true;
	}
	else if(optimization == translator::Translator::FullOptimization)
	{
		level = 3;
	}

	if(level == 0) return;

	llvm::PassManager manager;

	manager.add(new llvm::TargetData(*LLVMState::jit()->getTargetData()));

	if(level < 2)
	{
		manager.add(llvm::createInstructionCombiningPass());
		manager.add(llvm::createReassociatePass());
		manager.add(llvm::createGVNPass());
		manager.add(llvm::createCFGSimplificationPass());
	}
	else
	{
		manager.add(llvm::createSimplifyLibCallsPass());
		manager.add(llvm::createInstructionCombiningPass());
		manager.add(llvm::createJumpThreadingPass());
		manager.add(llvm::createCFGSimplificationPass());
		manager.add(llvm::createScalarReplAggregatesPass());
		manager.add(llvm::createInstructionCombiningPass());
		manager.add(llvm::createTailCallEliminationPass());
		manager.add(llvm::createCFGSimplificationPass());
		manager.add(llvm::createReassociatePass());
		manager.add(llvm::createLoopRotatePass());
		manager.add(llvm::createLICMPass());
		manager.add(llvm::createLoopUnswitchPass(space || level < 3));
		manager.add(llvm::createInstructionCombiningPass());
		manager.add(llvm::createIndVarSimplifyPass());
		manager.add(llvm::createLoopDeletionPass());
		if( level > 2 )
		{
			manager.add(llvm::createLoopUnrollPass());
		}
		manager.add(llvm::createInstructionCombiningPass());
		manager.add(llvm::createGVNPass());
		manager.add(llvm::createMemCpyOptPass());
		manager.add(llvm::createSCCPPass());

		// Run instcombine after redundancy elimination to exploit opportunities
		// opened up by them.
		manager.add(llvm::createInstructionCombiningPass());
		manager.add(llvm::createDeadStoreEliminationPass());
		manager.add(llvm::createAggressiveDCEPass());
		manager.add(llvm::createCFGSimplificationPass());
	}
	manager.run(module);
	#endif
}

static void codegen(LLVMModuleManager::Function& function, llvm::Module& module,
	const ir::PTXKernel& kernel)
{
	report(" Generating native code.");
	
	LLVMState::jit()->addModule(&module);

	std::string name = "_Z_ocelotTranslated_" + kernel.name;
	
	llvm::Function* llvmFunction = module.getFunction(name);

	assertM(llvmFunction != 0, "Could not find function " + name);
	function = hydrazine::bit_cast<LLVMModuleManager::Function>(
		LLVMState::jit()->getPointerToFunction(llvmFunction));
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// KernelAndTranslation
LLVMModuleManager::KernelAndTranslation::KernelAndTranslation(ir::PTXKernel* k, 
	translator::Translator::OptimizationLevel l) : _kernel(k), _module(0),
	_optimizationLevel(l), _metadata(0)
{

}

void LLVMModuleManager::KernelAndTranslation::unload()
{
	if(_metadata == 0) return;
	assert(_module != 0);

	llvm::Function* function = _module->getFunction(_kernel->name);

	LLVMState::jit()->freeMachineCodeForFunction(function);

	LLVMState::jit()->removeModule(_module);
	delete _module;
	delete _kernel;
	delete _metadata;
}

LLVMModuleManager::KernelAndTranslation::MetaData*
	LLVMModuleManager::KernelAndTranslation::metadata()
{
	if(_metadata != 0) return _metadata;
	
	report("Translating PTX kernel '" << _kernel->name << "'");
	
	optimizePTX(*_kernel, _optimizationLevel);
	_metadata = generateMetadata(*_kernel, _optimizationLevel);
	translate(_module, *_kernel);
	optimize(*_module, _optimizationLevel);
	codegen(_metadata->function, *_module, *_kernel);
		
	return _metadata;
}

const std::string& LLVMModuleManager::KernelAndTranslation::name() const
{
	return _kernel->name;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Module
LLVMModuleManager::Module::Module(const KernelVector& kernels,
	FunctionId nextFunctionId)
{	
	for(KernelVector::const_iterator kernel = kernels.begin();
		kernel != kernels.end(); ++kernel)
	{
		_ids.insert(std::make_pair(kernel->name(), nextFunctionId++));
	}
}

LLVMModuleManager::FunctionId LLVMModuleManager::Module::getFunctionId(
	const std::string& kernelName)
{
	FunctionIdMap::iterator id = _ids.find(kernelName);
	
	assert(id != _ids.end());
	
	return id->second;
}

LLVMModuleManager::FunctionId LLVMModuleManager::Module::lowId() const
{
	LLVMModuleManager::FunctionId min = std::numeric_limits<FunctionId>::max();
	
	for(FunctionIdMap::const_iterator id = _ids.begin(); id != _ids.end(); ++id)
	{
		min = std::min(min, id->second);
	}
	
	return min;
}

LLVMModuleManager::FunctionId LLVMModuleManager::Module::highId() const
{
	LLVMModuleManager::FunctionId max = std::numeric_limits<FunctionId>::min();
	
	for(FunctionIdMap::const_iterator id = _ids.begin(); id != _ids.end(); ++id)
	{
		max = std::max(max, id->second);
	}
	
	return max;
}

bool LLVMModuleManager::Module::empty() const
{
	return _ids.empty();
}

void LLVMModuleManager::Module::shiftId(FunctionId nextId)
{
	FunctionIdMap newIds;
	
	for(FunctionIdMap::const_iterator id = _ids.begin(); id != _ids.end(); ++id)
	{
		newIds.insert(std::make_pair(id->first, id->second - nextId));
	}
	
	_ids = std::move(newIds);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// ModuleDatabase

LLVMModuleManager::ModuleDatabase::ModuleDatabase()
{
	start();
}

LLVMModuleManager::ModuleDatabase::~ModuleDatabase()
{
	DatabaseMessage message;
	
	message.type = DatabaseMessage::KillThread;
	
	send(&message);

	DatabaseMessage* reply;	
	receive(reply);
	
	for(KernelVector::iterator kernel = _kernels.begin();
		kernel != _kernels.end(); ++kernel)
	{
		kernel->unload();
	}
}

void LLVMModuleManager::ModuleDatabase::loadModule(const ir::Module* module, 
	translator::Translator::OptimizationLevel level)
{
	assert(!isModuleLoaded(module->path()));

	typedef analysis::SubkernelFormationPass::ExtractKernelsPass Pass;
	Pass pass;

	pass.initialize(*module);

	for(ir::Module::KernelMap::const_iterator
		
		kernel = module->kernels().begin(); 
		kernel != module->kernels().end(); ++kernel)
	{
		pass.runOnKernel(*kernel->second);
	}

	pass.finalize();

	KernelVector subkernels;

	for(Pass::KernelVectorMap::const_iterator 
		kernel = pass.kernels.begin(); 
		kernel != pass.kernels.end(); ++kernel)
	{
		for(analysis::SubkernelFormationPass::KernelVector::const_iterator 
			subkernel = kernel->second.begin();
			subkernel != kernel->second.end(); ++subkernel)
		{
			subkernels.push_back(KernelAndTranslation(*subkernel, level));
		}
	}

	_modules.insert(std::make_pair(module->path(),
		Module(subkernels, _kernels.size())));
	_kernels.insert(_kernels.end(), subkernels.begin(), subkernels.end());
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

	if(module->second.empty())
	{
		_modules.erase(module);
		return;
	}

	FunctionId lowId  = module->second.lowId();
	FunctionId highId = module->second.highId();

	KernelVector::iterator kernelStart = _kernels.begin();
	KernelVector::iterator kernelEnd   = _kernels.begin();
	std::advance(kernelEnd, lowId);
	
	KernelVector newKernels(kernelStart, kernelEnd);
	
	kernelStart = _kernels.begin();
	std::advance(kernelStart, highId);
	
	for(KernelVector::iterator unloaded = kernelEnd;
		unloaded != kernelStart; ++unloaded)
	{
		unloaded->unload();
	}
	
	newKernels.insert(newKernels.end(), kernelStart, _kernels.end());

	_kernels = std::move(newKernels);
	
	_modules.erase(module);
	
	for(ModuleMap::iterator module = _modules.begin();
		module != _modules.end(); ++module)
	{
		if(module->second.lowId() > lowId)
		{
			module->second.shiftId(highId - lowId);
		}
	}
}

unsigned int LLVMModuleManager::ModuleDatabase::totalFunctionCount() const
{
	return _kernels.size();
}

void LLVMModuleManager::ModuleDatabase::execute()
{
	DatabaseMessage* m;
	
	Id id = threadReceive(m);
	
	while(m->type != DatabaseMessage::KillThread)
	{
		GetFunctionMessage* message = static_cast<GetFunctionMessage*>(m);
		
		if(message->type == DatabaseMessage::GetId)
		{
			ModuleMap::iterator module = _modules.find(message->moduleName);

			if(module != _modules.end())
			{
				message->id = module->second.getFunctionId(message->kernelName);
			}
		}
		else
		{
			assert(message->id < _kernels.size());
			message->metadata = _kernels[message->id].metadata();
		}
		
		threadSend(message, id);
		id = threadReceive(m);
	}

	threadSend(m, id);
}
////////////////////////////////////////////////////////////////////////////////

LLVMModuleManager::ModuleDatabase LLVMModuleManager::_database;

}

#endif


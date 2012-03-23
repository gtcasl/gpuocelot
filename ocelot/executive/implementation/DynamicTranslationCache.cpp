/*!
	\file DynamicTranslationCache.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 11, 2011
	\brief cache of translations
*/

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/analysis/interface/KernelPartitioningPass.h>
#include <ocelot/analysis/interface/LLVMUniformVectorization.h>
#include <ocelot/executive/interface/DynamicTranslationCache.h>
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>
#include <ocelot/executive/interface/DynamicMulticoreExecutive.h>
#include <ocelot/executive/interface/DynamicMulticoreDevice.h>
#include <ocelot/executive/interface/LLVMState.h>
#include <ocelot/ir/interface/LLVMKernel.h>
#include <ocelot/transforms/interface/PassManager.h>
#include <ocelot/analysis/interface/Debug.h>

// Hydrazine includes
//#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>
#include <hydrazine/interface/Casts.h>

#define HAVE_LLVM

// LLVM Includes
#ifdef HAVE_LLVM
#include <llvm/PassManager.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/PassManager.h>
#include <llvm/Target/TargetData.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Assembly/Parser.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Instructions.h>
#include <llvm/Support/CFG.h>
#include <llvm/Support/raw_os_ostream.h>
#else
#error "LLVM MUST BE PRESENT"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_PTX_MASTER 1								// master toggle for reporting PTX kernels
#define REPORT_SOURCE_PTX_KERNELS 1				// PTX prior to transformations
#define REPORT_PARITIONED_PTX_KERNELS 1		// final output PTX ready to be translated
#define REPORT_PTX_SUBKERNELS 1

#define REPORT_LLVM_MASTER 1							// master toggle for reporting LLVM kernels
#define REPORT_SOURCE_LLVM_ASSEMBLY 1			// assembly output of translator
#define REPORT_ALL_LLVM_ASSEMBLY 0				// turns on LLOVM assembly at each state
#define REPORT_OPTIMIZED_LLVM_ASSEMBLY 0	// final output of LLVM translation and optimization
#define REPORT_LLVM_VERIFY_FAILURE 0			// emit assembly if verification fails
#define REPORT_SCHEDULE_OPERATIONS 1			// scheduling events
#define REPORT_TRANSLATION_OPERATIONS 1		// translation events
#define REPORT_LLVM_WRITE_SOURCE 0				// saves LLVM source to disk

#define REPORT_TRANSLATIONS 0

#define ALWAYS_REPORT_BROKEN_LLVM 1

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

#define REQUIRE_VERIFY_MODULE	0					// if 1, verifies LLVM modules after translation

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace llvm {

	class Instruction;

}

std::ostream &Instruction_print(std::ostream &out, llvm::Instruction * inst);
std::string String(llvm::Type *value);
std::string String(llvm::Value *value);

std::string String(llvm::Module *module) {
	
	llvm::AssemblyAnnotationWriter *annotations = 0;
	
	std::string str;
	llvm::raw_string_ostream os(str);
	module->print(os, annotations);
	
	return str;
}

static translator::Translator::OptimizationLevel getOptimizationLevel() {
	return (translator::Translator::OptimizationLevel)api::configuration().executive.optimizationLevel;
}

///////////////////////////////////////////////////////////////////////////////////////////////////



executive::DynamicTranslationCache::DynamicTranslationCache(DynamicExecutionManager *_manager):
	executionManager(_manager) {

	pthread_mutex_init(&mutex, 0);

	translationVector.resize(api::OcelotConfiguration::get().executive.warpSize);
}

executive::DynamicTranslationCache::~DynamicTranslationCache() {
	report("Destructing!");
	
	translationCache.clear();
	
	for (ModuleMap::iterator mod_it = modules.begin(); mod_it != modules.end(); ++mod_it) {
		report(" deleting module " << mod_it->first);
		for (TranslatedKernelNameMap::iterator kernel_it = mod_it->second.kernels.begin();
			kernel_it != mod_it->second.kernels.end(); ++kernel_it) {
			TranslatedKernel *kernel = kernel_it->second;
			report(" deleting TranslatedKernel: 0x" << (void *)kernel);
			delete kernel;
		}
	}
	modules.clear();
}

int Log2WarpSize(int warpSize) {
	switch (warpSize) {
		case 1: return 0;
		case 2: return 1;
		case 4: return 2;
		case 8: return 3;
		case 16: return 4;
		case 32: return 5;
		case 64: return 6;
		default:
		break;
	}
	return -1;
}

executive::DynamicTranslationCache::Translation *
executive::DynamicTranslationCache::getOrInsertTranslation(
	int warpSize, SubkernelId subkernelId, unsigned int specialization) {
	
	reportE(REPORT_SCHEDULE_OPERATIONS, " DynamicTranslationCache::getOrInsertTranslation(ws: " << warpSize 
		<< ", skId: " << subkernelId << ", specialization = " << specialization << ")");

	Translation *translation = 0;

	_lock();
		
		/*
	int lgWarpsize = Log2WarpSize(warpSize);
	assert(lgWarpsize >= 0 && lgWarpsize < (int)translationVector.size());

	if (translationVector[lgWarpsize][subkernelId]) {
		translation = translationVector[lgWarpsize][subkernelId];
		
		report(" hit translation vector");
	}
	*/
	
	if (!translation) {
		TranslationCacheMap::iterator translation_it = translationCache.find(subkernelId);
		if (translation_it != translationCache.end()) {
			WarpTranslationMap::iterator warp_it = translation_it->second.find(warpSize);
			if (warp_it != translation_it->second.end()) {
				translation = warp_it->second;
				reportE(REPORT_SCHEDULE_OPERATIONS, "  found in translation cache");
			}
		}
	
		if (!translation) {	
			translation = _specializeTranslation(*subkernelsToKernel[subkernelId], subkernelId, 
				getOptimizationLevel(), warpSize, specialization);
		
			reportE(REPORT_SCHEDULE_OPERATIONS, "  inserted in translation cache");
		}
		//translationVector[lgWarpsize][subkernelId] = translation;
	}
	_unlock();
	
	#if REPORT_BASE && REPORT_TRANSLATION_OPERATIONS
	reportNTE(REPORT_TRANSLATION_OPERATIONS, " obtained Translation: " << (void *)translation);
	#endif
	
	return translation;
}

//! \brief indicates to the translation cache a kernel is about to be executed
void executive::DynamicTranslationCache::registerKernel(DynamicMulticoreKernel *kernel) {
	report("DynamicTranslationCache::registerKernel(" << kernel->name << ")");
	
	ModuleMap::iterator module_it = modules.find(kernel->module->path());
	assert(module_it != modules.end());
	
	ModuleMetadata &module = module_it->second;
	TranslatedKernelNameMap::iterator kernel_it = module.kernels.find(kernel->name);
	if (kernel_it == module.kernels.end()) {
		TranslatedKernel *translatedKernel = new TranslatedKernel(kernel);
		translatedKernel->localMemorySize = 0;
		translatedKernel->sharedMemorySize = 0;
		module.kernels[kernel->name] = translatedKernel;
				
		_translateKernel(*translatedKernel);
		
		report("Resizing translation vectors");
		
		// resize vectors
		SubkernelIdPair subkernelIdRange = translatedKernel->getSubkernelRange();
		if (translationVector[0].size() <= subkernelIdRange.second) {
			for (size_t lgws = 0; lgws < translationVector.size(); ++lgws) {
				translationVector[lgws].resize(subkernelIdRange.second + 1, 0);
				
				report("  resized translationVector[" << lgws << "] to size " << translationVector[lgws].size());
			}
		}
		
		report("  registered new TranslatedKernel 0x" << (void *)translatedKernel);
	}
	else {
		// do nothing.
		report("  kernel already registered");
	}	
}

//! \brief loads a module into the translation cache
bool executive::DynamicTranslationCache::loadModule(const ir::Module *module, 
	executive::DynamicMulticoreDevice *_device) {
	
	report("DynamicTranslationCache::loadModule(" << module->path() << ", device = " << (void *)_device << ")");
	
	if (modules.find(module->path()) == modules.end()) {
		ModuleMetadata newModule;
		newModule.ptxModule = module;
		this->device = _device;
		modules[module->path()] = newModule;
		return true;
	}
	
	return false;
}

void executive::DynamicTranslationCache::_lock() {
	pthread_mutex_lock(&mutex);
}

void executive::DynamicTranslationCache::_unlock() {
	pthread_mutex_unlock(&mutex);
}
		
void executive::DynamicTranslationCache::getTranslationVector(
	executive::DynamicTranslationCache::WarpTranslationVector &vec) {
	
	_lock();
	vec = translationVector;
	_unlock();
}

///////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicTranslationCache::TranslatedKernel::TranslatedKernel(DynamicMulticoreKernel *_kernel):
	llvmModule(0), kernel(_kernel), metadata(0), localMemorySize(0), sharedMemorySize(0) {
	
	llvmModule = new llvm::Module(kernel->name.c_str(), llvm::getGlobalContext());
}

executive::DynamicTranslationCache::TranslatedKernel::~TranslatedKernel() {
	report("~TranslatedKernel()");
	
	for (TranslatedSubkernelMap::iterator sk_it = subkernels.begin(); sk_it != subkernels.end();
		++sk_it ) {
	
		for (WarpTranslationMap::iterator trans_it = sk_it->second.translations.begin(); 
			trans_it != sk_it->second.translations.end(); ++trans_it) {
		
			delete trans_it->second;
		}
		sk_it->second.translations.clear();
	}
	subkernels.clear();
	
	delete static_cast<executive::MetaData*>(metadata);
	delete llvmModule;
}

executive::DynamicTranslationCache::SubkernelIdPair
	executive::DynamicTranslationCache::TranslatedKernel::getSubkernelRange() const {

	SubkernelIdPair range;
	for (TranslatedSubkernelMap::const_iterator sk_it = subkernels.begin(); sk_it != subkernels.end();
		++sk_it ) {
	
		if (sk_it == subkernels.begin()) {
			range.first = sk_it->first;
			range.second = sk_it->first;
		}
		else {
			if (range.first > sk_it->first) {
				range.first = sk_it->first;
			}
			if (range.second < sk_it->first) {
				range.second = sk_it->first;
			}
		}
	}
	
	return range;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicTranslationCache::Translation::Translation(llvm::Function *_llvmFunction):
	llvmFunction(_llvmFunction), function(0) {

}

void walkCallStack();

void executive::DynamicTranslationCache::Translation::execute(LLVMContext **contexts) const {
	assert(function);
	
	function(contexts[0]);
}

std::string executive::DynamicTranslationCache::Translation::name() const {
	return llvmFunction->getName().str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef HAVE_LLVM
static unsigned int pad(unsigned int& size, unsigned int alignment) {

	unsigned int padding = alignment - (size % alignment);
	padding = (alignment == padding) ? 0 : padding;
	size += padding;
	return padding;
}

/*!
	\brief sets addres space identifier to global for uses of global variables 
*/
static void setupGlobalMemoryReferences(ir::PTXKernel& kernel) {

	for (ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block) {
		
		for (ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction ) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);

			if (ptx.opcode == ir::PTXInstruction::Mov 
				&& (ptx.a.addressMode == ir::PTXOperand::Address
				|| ptx.a.addressMode == ir::PTXOperand::Indirect)) {
				
				ir::Module::GlobalMap::const_iterator global = kernel.module->globals().find(ptx.a.identifier);
					
				if(global == kernel.module->globals().end() ||
					global->second.statement.directive != ir::PTXStatement::Global) {
					continue;
				}
					
				ptx.addressSpace = ir::PTXInstruction::Global;
						
				reportE(REPORT_TRANSLATION_OPERATIONS, "   For instruction \"" << ptx.toString() 
					<< "\" setting address space to global.");
			}
		}
	}
}

/*!
	\brief computes layout of kernel arguments
*/
static void setupArgumentMemoryReferences(ir::PTXKernel& kernel,
	executive::DynamicMulticoreExecutive::Metadata* metadata) {
	
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;
	reportE(REPORT_TRANSLATION_OPERATIONS, "  Setting up argument memory references.");

	unsigned int offset = 0;
	
	OffsetMap offsets;
	
	for(ir::Kernel::ParameterVector::const_iterator
		argument = kernel.arguments.begin();
		argument != kernel.arguments.end(); ++argument) {
		
		pad(offset, argument->getAlignment());
		offsets.insert(std::make_pair(argument->name, offset));
		
		reportE(REPORT_TRANSLATION_OPERATIONS, "   Argument " << argument->name << ", offset " << offset);
		offset += argument->getSize();
	}

	for (ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); block != kernel.cfg()->end(); 
		++block) {
		
		for (ir::ControlFlowGraph::InstructionList::iterator instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction ) {
			
			ir::PTXInstruction &ptx = static_cast<ir::PTXInstruction&>(**instruction);
			ir::PTXOperand *operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if (ptx.opcode == ir::PTXInstruction::Mov || ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St) {
				
				for (unsigned int i = 0; i != 4; ++i) {
				
					if (operands[i]->addressMode == ir::PTXOperand::Address) {
					
						OffsetMap::iterator argument = offsets.find(operands[i]->identifier);
						
						if (argument != offsets.end()) {
							reportE(REPORT_TRANSLATION_OPERATIONS, "   For instruction \"" << ptx.toString() 
								<< "\" mapping \"" << argument->first 
								<< "\" to "
								<< (operands[i]->offset + argument->second));
							operands[i]->offset     += argument->second;
							operands[i]->isArgument = true;
						}
					}
				}
			}
		}
	}
	
	metadata->argumentSize = offset;
	
	reportE(REPORT_TRANSLATION_OPERATIONS, "   total argument memory size is " 
		<< metadata->argumentSize);
}

/*!
	\brief 
*/
static void setupParameterMemoryReferences(ir::PTXKernel& kernel,
	executive::DynamicMulticoreExecutive::Metadata* metadata) {
	
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;
	reportE(REPORT_TRANSLATION_OPERATIONS, "  Setting up parameter memory references.");

	metadata->parameterSize	= 0;
	
	OffsetMap offsets;
	
	// Determine the order that parameters are passed as arguments to calls
	for (ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block) {
		
		for (ir::ControlFlowGraph::InstructionList::iterator instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);
			if (ptx.opcode != ir::PTXInstruction::Call) continue;
			
			if (ptx.a.identifier == "ptx.warp.divergent") {
				continue;
			}
			
			unsigned int offset = 0;
			
			reportE(REPORT_TRANSLATION_OPERATIONS, "   For arguments of call instruction '"
				<< ptx.toString() << "'");
				
			for (ir::PTXOperand::Array::const_iterator argument = ptx.d.array.begin();
				argument != ptx.d.array.end(); ++argument) {
				
				pad(offset, ir::PTXOperand::bytes(argument->type));
				assert(offsets.count(argument->identifier) == 0);
				offsets.insert(std::make_pair(argument->identifier, offset));
				
				reportE(REPORT_TRANSLATION_OPERATIONS, "    mapping '" << argument->identifier
					<< "' to " << offset);
					
				offset += ir::PTXOperand::bytes(argument->type);
			}
			
			for (ir::PTXOperand::Array::const_iterator argument = ptx.b.array.begin();
				argument != ptx.b.array.end(); ++argument) {
				
				pad(offset, ir::PTXOperand::bytes(argument->type));
				assert(offsets.count(argument->identifier) == 0);
				offsets.insert(std::make_pair(argument->identifier, offset));
				
				reportE(REPORT_TRANSLATION_OPERATIONS, "    mapping '" << argument->identifier
					<< "' to " << offset);
					
				offset += ir::PTXOperand::bytes(argument->type);
			}
			
			metadata->parameterSize = std::max(offset, metadata->parameterSize);
		}
	}
	
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); block != kernel.cfg()->end(); 
		++block) {
		
		for (ir::ControlFlowGraph::InstructionList::iterator instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);

			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov || ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St) {
				
				for(unsigned int i = 0; i != 4; ++i) {
				
					if(operands[i]->addressMode == ir::PTXOperand::Address) {
					
						OffsetMap::iterator parameter = offsets.find(operands[i]->identifier);
						
						if(parameter != offsets.end()) {
							reportE(REPORT_TRANSLATION_OPERATIONS, "   For instruction \"" 
								<< ptx.toString() << "\" mapping \"" 
								<< parameter->first << "\" to " 
								<< (parameter->second + operands[i]->offset));
							
							operands[i]->offset += parameter->second;
							operands[i]->isArgument = false;
						}
					}
				}
			}
		}
	}
	
	// In order to handle tail calls resuing the current stack frame, allocate 
	//  enough space for the max number of parameters in the module
	for(ir::Module::KernelMap::const_iterator function = kernel.module->kernels().begin();
		function != kernel.module->kernels().end(); ++function) {
		
		if (!function->second->function()) continue;
		
		unsigned int bytes = 0;
		
		for (ir::Kernel::ParameterVector::const_iterator argument = function->second->arguments.begin();
			argument != function->second->arguments.end(); ++argument) {
			pad(bytes, argument->getSize());
			bytes += argument->getSize();
		}
		
		metadata->parameterSize = std::max(bytes, metadata->parameterSize);
	}
	
	reportE(REPORT_TRANSLATION_OPERATIONS, "   total parameter memory size is " 
		<< metadata->parameterSize);
}

/*!
	\brief lays out shared memory
*/
static void setupSharedMemoryReferences(ir::PTXKernel& kernel, 
	executive::DynamicMulticoreExecutive::Metadata* metadata) {
	
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;
	typedef std::unordered_set<std::string> StringSet;
	typedef std::deque<ir::PTXOperand*> OperandVector;
	typedef std::unordered_map<std::string, ir::Module::GlobalMap::const_iterator> GlobalMap;

	reportE(REPORT_TRANSLATION_OPERATIONS,  "  Setting up shared memory references." );

	OffsetMap offsets;
	StringSet external;
	OperandVector externalOperands;

	unsigned int externalAlignment = 1;             
	metadata->sharedSize = 0;

	for(ir::Module::GlobalMap::const_iterator global = kernel.module->globals().begin(); 
		global != kernel.module->globals().end(); ++global) {
		
		if (global->second.statement.directive == ir::PTXStatement::Shared) {
			if (global->second.statement.attribute == ir::PTXStatement::Extern) {
				reportE(REPORT_TRANSLATION_OPERATIONS, "   Allocating global external shared variable " 
					<< global->second.statement.name);
					
				assertM(external.count(global->second.statement.name) == 0, 
					"External global " << global->second.statement.name 
					<< " more than once.");
					
				external.insert(global->second.statement.name);
				externalAlignment = std::max(externalAlignment, 
					(unsigned) global->second.statement.alignment);
				externalAlignment = std::max(externalAlignment, 
					ir::PTXOperand::bytes(global->second.statement.type));
			}
			else {
				reportE(REPORT_TRANSLATION_OPERATIONS, "   Allocating global shared variable " 
					<< global->second.statement.name);
				pad(metadata->sharedSize, global->second.statement.alignment);
				offsets.insert(std::make_pair(global->second.statement.name, 
					metadata->sharedSize));
				metadata->sharedSize += global->second.statement.bytes();
			}
		}
	}

	for(ir::Kernel::LocalMap::const_iterator local = kernel.locals.begin(); 
		local != kernel.locals.end(); ++local) {
		
		if (local->second.space == ir::PTXInstruction::Shared) {
			if (local->second.attribute == ir::PTXStatement::Extern) {
				reportE(REPORT_TRANSLATION_OPERATIONS, "    Found local external shared variable " 
					<< local->second.name);
				
				assert(external.count(local->second.name) == 0);
				
				external.insert(local->second.name);
				externalAlignment = std::max(externalAlignment, (unsigned) local->second.alignment);
				externalAlignment = std::max(externalAlignment, ir::PTXOperand::bytes(local->second.type));
			}
			else {
				reportE(REPORT_TRANSLATION_OPERATIONS, "   Found local shared variable " 
					<< local->second.name << " of size " 
					<< local->second.getSize());
				
				pad(metadata->sharedSize, local->second.alignment);
				offsets.insert(std::make_pair(local->second.name, metadata->sharedSize));
				metadata->sharedSize += local->second.getSize();
			}
		}
	}
                
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block) {
		
		for(ir::ControlFlowGraph::InstructionList::iterator instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);

			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St
				|| ptx.opcode == ir::PTXInstruction::Cvta)
			{
				for (unsigned int i = 0; i != 4; ++i) {
					if (operands[i]->addressMode == ir::PTXOperand::Address) {
						StringSet::iterator si = external.find(operands[i]->identifier);
						
						if (si != external.end()) {
							reportE(REPORT_TRANSLATION_OPERATIONS, "   For instruction \"" 
								<< ptx.toString() 
								<< "\", mapping shared label \"" << *si 
								<< "\" to external shared memory.");
							externalOperands.push_back(operands[i]);
							continue;
						}
	
						OffsetMap::iterator offset = offsets.find(operands[i]->identifier);
						if (offsets.end() != offset) {
							ptx.addressSpace = ir::PTXInstruction::Shared;
							operands[i]->offset += offset->second;
							
							reportE(REPORT_TRANSLATION_OPERATIONS, "   For instruction " 
								<< ptx.toString() << ", mapping shared label " 
								<< offset->first << " to " << offset->second);
						}
					}
				}
			}
		}
	}

	pad(metadata->sharedSize, externalAlignment);

	reportE(REPORT_TRANSLATION_OPERATIONS, "   Mapping external shared variables.");
	for(OperandVector::iterator operand = externalOperands.begin(); 
		operand != externalOperands.end(); ++operand) {
		
		reportE(REPORT_TRANSLATION_OPERATIONS, "    Mapping external shared label " 
			<< (*operand)->identifier << " to " << metadata->sharedSize);
		(*operand)->offset += metadata->sharedSize;
	}

	reportE(REPORT_TRANSLATION_OPERATIONS,  "   Total shared memory size is " 
		<< metadata->sharedSize << "." );
}

/*!
	\brief 
*/
static void setupConstantMemoryReferences(ir::PTXKernel& kernel,
	executive::DynamicMulticoreExecutive::Metadata* metadata)
{
	reportE(REPORT_TRANSLATION_OPERATIONS,  "  Setting up constant memory references." );
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;

	metadata->constantSize = 0;
	OffsetMap constants;
	
	for(ir::Module::GlobalMap::const_iterator global = kernel.module->globals().begin(); 
		global != kernel.module->globals().end(); ++global) {
		
		if (global->second.statement.directive == ir::PTXStatement::Const) {
		
			reportE(REPORT_TRANSLATION_OPERATIONS,  "   Found global constant variable " 
				<< global->second.statement.name << " of size " 
				<< global->second.statement.bytes() );
			
			pad(metadata->constantSize, global->second.statement.alignment);
			constants.insert(std::make_pair(global->second.statement.name,
				metadata->constantSize));
			metadata->constantSize += global->second.statement.bytes();
		}
	}

	reportE(REPORT_TRANSLATION_OPERATIONS, "   Total constant memory size is " 
		<< metadata->constantSize);

	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block) {
		
		for(ir::ControlFlowGraph::InstructionList::iterator instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);
			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St)
			{
				for(unsigned int i = 0; i != 4; ++i) {
					if(operands[i]->addressMode == ir::PTXOperand::Address) {
						OffsetMap::iterator mapping = constants.find(operands[i]->identifier);
						
						if(constants.end() != mapping) {
						
							ptx.addressSpace = ir::PTXInstruction::Const;
							operands[i]->offset += mapping->second;
							reportE(REPORT_TRANSLATION_OPERATIONS, "   For instruction " 
								<< ptx.toString() 
								<< ", mapping constant label " << mapping->first 
								<< " to " << mapping->second);
						}
					}
				}
			}
		}
	}
}

/*!
	\brief
*/
static void setupTextureMemoryReferences(ir::PTXKernel& kernel, 
	executive::DynamicMulticoreExecutive::Metadata* metadata, executive::Device* device) {
	
	typedef std::unordered_map<std::string, unsigned int> TextureMap;
	reportE(REPORT_TRANSLATION_OPERATIONS, " Setting up texture memory references.");
	
	TextureMap textures;
	
	for (ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block) {
		
		for (ir::ControlFlowGraph::InstructionList::iterator instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);
			
			if (ptx.opcode == ir::PTXInstruction::Tex) {
				reportE(REPORT_TRANSLATION_OPERATIONS, "  found texture instruction: " << ptx.toString());

				TextureMap::iterator reference = textures.find(ptx.a.identifier);
				if (reference != textures.end()) {
					ptx.a.reg = reference->second;
					reportE(REPORT_TRANSLATION_OPERATIONS, " recognized as as texture " << ptx.a.reg);
				}
				else {
					ptx.a.reg = textures.size();
					textures.insert(std::make_pair(ptx.a.identifier, textures.size()));
					
					report("  getting texture reference, device = " << (void *)device);
					
					ir::Texture* texture = (ir::Texture*)device->getTextureReference(
						kernel.module->path(), ptx.a.identifier);
					
					assert(texture != 0);
					
					report("   adding texture to metadata");
					metadata->textures.push_back(texture);
					reportE(REPORT_TRANSLATION_OPERATIONS, " adding as texture " << ptx.a.reg);
				}
				assert(metadata->textures.size());
			}
		}
	}
}

/*!
	\brief 
*/
static void setupLocalMemoryReferences(ir::PTXKernel& kernel,
	executive::DynamicMulticoreExecutive::Metadata* metadata) {
	
	reportE(REPORT_TRANSLATION_OPERATIONS,  "  Setting up local memory references." );
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;

	OffsetMap offsets;
	
	// Reserve the first few 32-bit words
	// [0] == kernel-id
	// [1] == call type
	// [2] == barrier resume point if it exists
	metadata->localSize = 0;
	
	// give preference to barrier resume point
	ir::Kernel::LocalMap::const_iterator local = kernel.locals.find(
		"_Zocelot_barrier_next_kernel");
	if(local != kernel.locals.end())
	{
		if(local->second.space == ir::PTXInstruction::Local)
		{
			reportE(REPORT_TRANSLATION_OPERATIONS, "   Found local local variable " 
				<< local->second.name << " of size " 
				<< local->second.getSize());
			
			pad(metadata->localSize, local->second.alignment);
			offsets.insert(std::make_pair(local->second.name,
				metadata->localSize));
			metadata->localSize += local->second.getSize();
		}
	}
	
	pad(metadata->localSize, sizeof(int));
	offsets.insert(std::make_pair("_Zocelot_resume_point", metadata->localSize));
	metadata->localSize += sizeof(int);
	
	pad(metadata->localSize, sizeof(int));
	offsets.insert(std::make_pair("_Zocelot_resume_status", metadata->localSize));
	metadata->localSize += sizeof(int);

	
	/*
	if (api::OcelotConfiguration::get().executive.yieldOverheadInstrumentation) {
		pad(metadata->localSize, sizeof(size_t));
		offsets.insert(std::make_pair("_Zocelot_entry_cycles", metadata->localSize));
		metadata->localSize += sizeof(size_t);
	
		pad(metadata->localSize, sizeof(int));
		offsets.insert(std::make_pair("_Zocelot_entry_id", metadata->localSize));
		metadata->localSize += sizeof(int);
	
		pad(metadata->localSize, sizeof(int));
		offsets.insert(std::make_pair("_Zocelot_entry_liveness", metadata->localSize));
		metadata->localSize += sizeof(int);
	
		pad(metadata->localSize, sizeof(size_t));
		offsets.insert(std::make_pair("_Zocelot_exit_cycles", metadata->localSize));
		metadata->localSize += sizeof(size_t);
	
		pad(metadata->localSize, sizeof(int));
		offsets.insert(std::make_pair("_Zocelot_exit_id", metadata->localSize));
		metadata->localSize += sizeof(int);
	
		pad(metadata->localSize, sizeof(int));
		offsets.insert(std::make_pair("_Zocelot_exit_liveness", metadata->localSize));
		metadata->localSize += sizeof(int);
		
		pad(metadata->localSize, sizeof(size_t));
		offsets.insert(std::make_pair("_Zocelot_subkernel_cycles", metadata->localSize));
		metadata->localSize += sizeof(size_t);
	}
	*/
	
	for(ir::Kernel::LocalMap::const_iterator local = kernel.locals.begin(); 
		local != kernel.locals.end(); ++local)
	{
		if(local->first == "_Zocelot_barrier_next_kernel") continue;
		if(local->first == "_Zocelot_spill_area")          continue;
		if(local->first == "_Zocelot_resume_point")        continue;
		if(local->first == "_Zocelot_resume_status")        continue;
		
		/*
		if (api::OcelotConfiguration::get().executive.yieldOverheadInstrumentation) {
			if(local->first == "_Zocelot_entry_cycles")        continue;
			if(local->first == "_Zocelot_entry_id")        continue;
			if(local->first == "_Zocelot_entry_liveness")        continue;
			if(local->first == "_Zocelot_exit_cycles")        continue;
			if(local->first == "_Zocelot_exit_id")        continue;
			if(local->first == "_Zocelot_exit_liveness")        continue;
			if (local->first == "_Zocelot_subkernel_cycles") continue;
		}
		*/
		
		if (local->second.space == ir::PTXInstruction::Local) {
			reportE(REPORT_TRANSLATION_OPERATIONS, "   Found local local variable " 
				<< local->second.name << " of size " 
				<< local->second.getSize());
			
			pad(metadata->localSize, local->second.alignment);
			offsets.insert(std::make_pair(local->second.name,
				metadata->localSize));
			metadata->localSize += local->second.getSize();
		}
	}

	// defer the spill area
	local = kernel.locals.find("_Zocelot_spill_area");
	if (local != kernel.locals.end()) {
		if (local->second.space == ir::PTXInstruction::Local) {
			reportE(REPORT_TRANSLATION_OPERATIONS, "   Found local local variable " 
				<< local->second.name << " of size " 
				<< local->second.getSize());
			
			pad(metadata->localSize, local->second.alignment);
			offsets.insert(std::make_pair(local->second.name,
				metadata->localSize));
			metadata->localSize += local->second.getSize();
		}
	}
    
	for (ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block) {
		
		for (ir::ControlFlowGraph::InstructionList::iterator instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);
			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};
	
			if (ptx.opcode == ir::PTXInstruction::Mov || ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St) {
				
				for (unsigned int i = 0; i != 4; ++i) {
					if (operands[i]->addressMode == ir::PTXOperand::Address) {
						OffsetMap::iterator offset = offsets.find(operands[i]->identifier);
						if (offsets.end() != offset) {
							ptx.addressSpace = ir::PTXInstruction::Local;
							operands[i]->offset += offset->second;
							
							reportE(REPORT_TRANSLATION_OPERATIONS, "   For instruction " 
								<< ptx.toString() << ", mapping local label " 
								<< offset->first << " to " << offset->second);
						}
					}
				}
			}
		}
	}
	reportE(REPORT_TRANSLATION_OPERATIONS, "   Total local memory size is " 
		<< metadata->localSize << ".");
}

/*!

*/
static void setupPTXMemoryReferences(ir::PTXKernel& kernel,
	executive::DynamicMulticoreExecutive::Metadata* metadata, executive::Device* device) {
	
	reportE(REPORT_TRANSLATION_OPERATIONS, " Setting up memory references for kernel variables.");
	
	setupGlobalMemoryReferences(kernel);
	setupArgumentMemoryReferences(kernel, metadata);
	setupParameterMemoryReferences(kernel, metadata);
	setupSharedMemoryReferences(kernel, metadata);
	setupConstantMemoryReferences(kernel, metadata);
	setupTextureMemoryReferences(kernel, metadata, device);
	setupLocalMemoryReferences(kernel, metadata);
}

/*!
	\brief apply a set of optimizations and transformations to the PTX representation
		of the whole kernel
*/
void DynamicTranslationCacheOptimizePTX(ir::PTXKernel& kernel, 
	translator::Translator::OptimizationLevel optimization) {

}

/*!
	\brief 
*/
static void setupCallTargets(ir::PTXKernel& kernel,
	const executive::DynamicTranslationCache & translationCache) {
	
	// replace all call instruction operands with kernel id
	reportE(REPORT_TRANSLATION_OPERATIONS, "  Setting up targets of call instructions.");
	
	for (ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block) {
		
		for (ir::ControlFlowGraph::InstructionList::iterator instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);
			
			if (ptx.opcode != ir::PTXInstruction::Call && ptx.opcode != ir::PTXInstruction::Mov) {
				continue;
			}
			if (ptx.tailCall) {
				continue;
			}
			
			if(ptx.a.addressMode == ir::PTXOperand::FunctionName) {
				if (ptx.a.identifier == "ptx.warp.divergent") {
					// this is a special intrinsic that will be lowered
				}
				else {
					assert(0 && "arbitrary function calls not yet supported");
					reportE(REPORT_TRANSLATION_OPERATIONS, "   setting target '" << ptx.a.identifier 
						<< "' of instruction '" << ptx.toString());
//					ptx.reentryPoint = id;
				}
			}
		}
	}
}

static std::string getTranslatedName(const std::string &kernelName) {
	return "_Z_ocelotTranslated_" + kernelName;
}

/*!
	\brief constructs a metadata instance
*/
static executive::DynamicMulticoreExecutive::Metadata* generateMetadata(
	ir::PTXKernel& kernel, 
	translator::Translator::OptimizationLevel level,
	int warpSize = 1)
{
	executive::DynamicMulticoreExecutive::Metadata *metadata = 
		new executive::DynamicMulticoreExecutive::Metadata;
	
	reportE(REPORT_TRANSLATION_OPERATIONS, " Building metadata.");
	
	if(level == translator::Translator::DebugOptimization
		|| level == translator::Translator::ReportOptimization) {
		
		report("  Adding debugging symbols");
		ir::ControlFlowGraph::BasicBlock::Id id = 0;
		
		for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin();
			block != kernel.cfg()->end(); ++block)
		{
			block->id = id++;
			metadata->blocks.insert(std::make_pair(block->id, block));
		}
	}
	
	metadata->kernel = &kernel;
	metadata->warpSize = warpSize;
	metadata->device = 0;
	
	return metadata;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

#if REPORT_BASE && REPORT_LLVM_VERIFY_FAILURE
static void identifyPredecessors(std::ostream &out, llvm::Function *function) {
	out << "Predecessors of function '" << function->getName().str() << "'  ";
	out << " [entry block: " << function->front().getName().str() << "]\n";
	
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		out << " block '" << bb_it->getName().str() << "' with predecessors {";
		for (llvm::pred_iterator pred_it = llvm::pred_begin(&*bb_it); pred_it != llvm::pred_end(&*bb_it); ++pred_it) {
			llvm::BasicBlock *pred = *pred_it;
			out << pred->getName().str() << ", ";
		}
		out << "}\n";
	}
}
#endif

/*!
	\brief given a translated function, apply a selection of LLVM transformation
		passes before JIT compilation
	
	\param module
	\param optimization
	\param warpSize number of threads executed per function call
*/
static void cloneAndOptimizeTranslation(
	executive::DynamicTranslationCache::TranslatedKernel &translatedKernel,
	executive::DynamicTranslationCache::TranslatedSubkernel &translatedSubkernel,
	executive::DynamicTranslationCache::SubkernelId subkernelId,
	executive::DynamicTranslationCache::Translation *translation,
	int warpSize,
	translator::Translator::OptimizationLevel optimization,
	unsigned int specialization) {
		
	reportE(REPORT_TRANSLATION_OPERATIONS, " Optimizing kernel " << translatedSubkernel.subkernelPtx->name 
		<< " for warpSize " << warpSize << ", optimziation level " << translator::Translator::toString(optimization)
		<< " and specialization " << specialization);

	unsigned int level = 0;
	bool space = false;

	switch (optimization) {
		case translator::Translator::BasicOptimization:
			level = 1;
			break;
		case translator::Translator::AggressiveOptimization:
			level = 2;
			break;
		case translator::Translator::SpaceOptimization:
			level = 2;
			space = true;
			break;
		case translator::Translator::FullOptimization:
			level = 3;
			break;
		default:
			level = 0;
			break;
	}

	std::stringstream ss;
	ss << translatedSubkernel.subkernelPtx->name << "_opt" << level << "_ws" << warpSize;
	if (specialization) {
		ss << "_spec" << specialization;
	}

	if (warpSize == 1 && specialization == 0) {
		translation->llvmFunction = translatedSubkernel.llvmFunction;
		report("  translating source subkernel");
	}
	else {
		translation->llvmFunction = llvm::CloneFunction(translatedSubkernel.llvmFunction);
		translation->llvmFunction->setName(ss.str());
		translation->llvmFunction->setLinkage(llvm::GlobalValue::InternalLinkage);
		translatedKernel.llvmModule->getFunctionList().push_back(translation->llvmFunction);
		report("  CLONED");
	}
		
	llvm::FunctionPassManager manager(translatedKernel.llvmModule);
	manager.add(new llvm::TargetData(*executive::LLVMState::jit()->getTargetData()));
	
	analysis::LLVMUniformVectorization *vectorizationPass = new
		analysis::LLVMUniformVectorization(translatedKernel.kernel->kernelGraph(), subkernelId, warpSize);
	manager.add(vectorizationPass);
	
	report("Overriding optimization level");
	level = 2;

	if (level == 0) {
		reportE(REPORT_TRANSLATION_OPERATIONS, "no optimizations");
	}
	else if (level == 1) {
		manager.add(llvm::createInstructionCombiningPass());
		manager.add(llvm::createReassociatePass());
		manager.add(llvm::createGVNPass());
		manager.add(llvm::createCFGSimplificationPass());
	}
	else {
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
		if (level > 2) {
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
	
	manager.run(*translation->llvmFunction);
	
	// we can't verify errors until this point
	reportE(REPORT_TRANSLATION_OPERATIONS, "  Checking llvm module for errors.");
	std::string verifyError;
	
	if (REQUIRE_VERIFY_MODULE && 
		llvm::verifyModule(*translatedKernel.llvmModule, llvm::ReturnStatusAction, &verifyError)) {
	
		std::cerr << "verification failed for kernel " << translatedKernel.kernel->name << " : \"" 
			<< verifyError << "\"" << std::endl;
			
#if (REPORT_BASE && REPORT_LLVM_VERIFY_FAILURE) || ALWAYS_REPORT_BROKEN_LLVM
		std::cerr << "LLVMDynamicTranslationCache.cpp:" << __LINE__ << ":" << std::endl;
		
		translatedKernel.llvmModule->dump();
		
		std::cerr << "\nerror on subkernel: " << translatedSubkernel.llvmFunction->getName().str() << std::endl;
		std::cerr << " specialization: " << translation->llvmFunction->getName().str() << std::endl;
				
#endif

		assert(0 && "due to broken LLVM module");
		
		delete translatedKernel.llvmModule;
		translatedKernel.llvmModule = 0;
				
		throw hydrazine::Exception("LLVM Verifier failed for kernel: " 
			+ translatedKernel.kernel->name + " : \"" + verifyError + "\"");
	}
	else {
		reportE(REPORT_TRANSLATION_OPERATIONS, " skipped module verification");
	}

	report("performed transformations");
}

static void linkLLVMModule(llvm::Module& module, const ir::PTXKernel& kernel, 
	executive::Device* device) {

	reportE(REPORT_TRANSLATION_OPERATIONS, "  Linking global variables.");
	executive::LLVMState::jit()->clearAllGlobalMappings();
	for(ir::Module::GlobalMap::const_iterator global = kernel.module->globals().begin(); 
		global != kernel.module->globals().end(); ++global) {
		
		if(global->second.statement.directive == ir::PTXStatement::Global) {
			assert(device != 0);

			llvm::GlobalValue* value = module.getNamedValue(global->first);
			
			assertM(value != 0, "Global variable " << global->first 
				<< " not found in llvm module.");
			executive::Device::MemoryAllocation* allocation = 
				device->getGlobalAllocation(kernel.module->path(), global->first);
			
			assert(allocation != 0);
			reportE(REPORT_TRANSLATION_OPERATIONS, "  Binding global variable " << global->first 
				<< " to " << allocation->pointer());
			
			executive::LLVMState::jit()->addGlobalMapping(value, allocation->pointer());
		}
	}
}

#endif

void executive::DynamicTranslationCache::_translateKernel(TranslatedKernel &translatedKernel) {
	
	report("__translateKernel()");
	
#ifdef HAVE_LLVM
	reportE(REPORT_TRANSLATION_OPERATIONS, "Getting metadata for kernel '" 
		<< translatedKernel.kernel->name << "'");
	
	typedef analysis::KernelPartitioningPass::SubkernelMap SubkernelMap;
	SubkernelMap &subkernels = translatedKernel.kernel->kernelGraph()->subkernels;

	// compte memory sizes and layouts
	translatedKernel.metadata = generateMetadata(*translatedKernel.kernel->kernelGraph()->ptxKernel, 
		getOptimizationLevel());
	
	size_t subkernelCount = 0;
	
	std::stringstream moduleText;
	
	for (SubkernelMap::iterator subkernel_it = subkernels.begin(); 
		subkernel_it != subkernels.end(); ++subkernel_it, ++subkernelCount) {
	
		subkernelsToKernel[subkernel_it->first] = &translatedKernel;
	
		ir::PTXKernel *subkernelPtx = subkernel_it->second.subkernel;
		
		report("  ---------------------");
		report("  translating subkernel " << subkernelPtx->name);
		
		try {
			
			report("   setting up PTX memory references");
		 
			// translate global memory references
			setupPTXMemoryReferences(*subkernelPtx, 
				(executive::DynamicMulticoreExecutive::Metadata*)translatedKernel.metadata, device);
			
			report("   setting up call targets");

			// rewrite call functions with hyperblock exits chained to target functions
			setupCallTargets(*subkernelPtx, *this);
			
			// emit PTX if need be
#if REPORT_BASE && REPORT_PTX_SUBKERNELS && REPORT_PTX_MASTER
			reportE(REPORT_PTX_SUBKERNELS, "Subkernel " << subkernelPtx->name << ":");
			subkernelPtx->write(std::cout);
			std::cout << std::endl;
#endif
	
			report("  Converting from PTX IR to LLVM IR.");
			translator::PTXToLLVMTranslator translator(getOptimizationLevel(), 0, true);

			transforms::PassManager manager(const_cast<ir::Module*>(subkernelPtx->module));

			manager.addPass(translator);
			manager.runOnKernel(*subkernelPtx);

			report("   loading LLVM kernel");
			ir::LLVMKernel* llvmKernel = static_cast<ir::LLVMKernel*>(
				translator.translatedKernel());

			reportE(REPORT_TRANSLATION_OPERATIONS, "  Assembling LLVM kernel.");
			llvmKernel->assemble(!subkernelCount);
			
		#if REPORT_LLVM_MASTER
			report("translated PTX to LLVM");
			reportE(REPORT_SOURCE_LLVM_ASSEMBLY, llvmKernel->code());
		#endif

			moduleText << llvmKernel->code() << "\n";

			delete llvmKernel;
			
			TranslatedSubkernel newSubkernel;
			newSubkernel.llvmFunction = 0;
			newSubkernel.metadata = translatedKernel.metadata;
			newSubkernel.subkernelPtx = subkernelPtx;
			translatedKernel.subkernels[subkernel_it->first] = newSubkernel;
		}
		catch(...)
		{
			throw;
		}
	
		#else
		assertM(false, "LLVM support not compiled into ocelot.");
		#endif
	}

	llvm::SMDiagnostic parseErrors;
	translatedKernel.llvmModule = llvm::ParseAssemblyString(moduleText.str().c_str(), 
		0, parseErrors, llvm::getGlobalContext());

	if (translatedKernel.llvmModule == 0) {
		reportE(REPORT_TRANSLATION_OPERATIONS, "   Parsing kernel failed, dumping code:\n");

		#if REPORT_LLVM_MASTER
			report("Invalid LLVM module:\n" << moduleText.str());
		#endif

		std::string m;
		llvm::raw_string_ostream message(m);
		message << "LLVM Parser failed: ";

		parseErrors.print(translatedKernel.kernel->name.c_str(), message);

		throw hydrazine::Exception(message.str());
	}
	else {
		reportE(REPORT_TRANSLATION_OPERATIONS, " parsed kernel");
	}
	
	for (SubkernelMap::iterator subkernel_it = subkernels.begin(); 
		subkernel_it != subkernels.end(); ++subkernel_it, ++subkernelCount) {
		
		TranslatedSubkernel &translatedSubkernel = translatedKernel.subkernels[subkernel_it->first];
		translatedSubkernel.llvmFunction = 
			translatedKernel.llvmModule->getFunction(getTranslatedName(
				translatedSubkernel.subkernelPtx->name));
	}
	
	report(" _translateKernel('" << translatedKernel.kernel->name << "') complete for " 
		<< translatedKernel.subkernels.size() << " subkernels");
}

executive::DynamicTranslationCache::Translation *
	executive::DynamicTranslationCache::_specializeTranslation(
		executive::DynamicTranslationCache::TranslatedKernel &translatedKernel, 
		SubkernelId subkernelId, 
		OptimizationLevel optimizationLevel, 
		int warpSize, 
		unsigned int specialization) {
	
	report("_specializeTranslation()");
	
	TranslatedSubkernel &subkernel = translatedKernel.subkernels[subkernelId];
	
	Translation *translation = new Translation;
	translation->metadata = subkernel.metadata;
	static_cast<executive::MetaData*>(translation->metadata)->device = device;
	
	reportNTE(REPORT_TRANSLATION_OPERATIONS, "new Translation: " << (void *)translation);
	
	#ifdef HAVE_LLVM
	try {
	
		report("  cloning and optimizing");
	
		// apply optimizations on the resulting LLVM function
		cloneAndOptimizeTranslation(translatedKernel, subkernel, subkernelId,
			translation, warpSize, getOptimizationLevel(), specialization);
		
		// dynamically compile LLVM to host ISA
		reportE(REPORT_TRANSLATION_OPERATIONS, " Generating native code.");
	
		report("  JIT compiling");
		
		executive::LLVMState::jit()->addModule(translatedKernel.llvmModule);
		linkLLVMModule(*translatedKernel.llvmModule, *subkernel.subkernelPtx, device);
		
		reportE(REPORT_TRANSLATION_OPERATIONS, "  Invoking LLVM to Native JIT");
		assertM(translation->llvmFunction != 0, "Could not find function ");
	
		translation->function = hydrazine::bit_cast<DynamicTranslationCache::ExecutableFunction>(
			executive::LLVMState::jit()->getPointerToFunction(translation->llvmFunction));

		if (translation->function) {
			reportE(REPORT_TRANSLATION_OPERATIONS, "  JIT-compiled function: " 
				<< translation->llvmFunction->getName().str());
			reportE(REPORT_TRANSLATION_OPERATIONS, "   calling convention: " 	
				<< (int)translation->llvmFunction->getCallingConv());
		}
		
#if REPORT_LLVM_MASTER && REPORT_LLVM_WRITE_SOURCE
		{
			std::string llvmText;
			llvm::raw_string_ostream llvmStream(llvmText);
			translation->llvmFunction->print(llvmStream);
			std::ofstream file(translation->llvmFunction->getName().str() + ".ll");
			
			file << llvmText;
		}
#endif
		
		report("  updating translation cache data structures");
		subkernel.translations[warpSize] = translation;
		
		// update the translation cache
		translationCache[subkernelId][warpSize] = translation;
	}
	catch(...) {
		executive::LLVMState::jit()->removeModule(translatedKernel.llvmModule);
		delete translation;
		throw;
	}
	#endif
	report("  _specializeTranslation() complete");
	return translation;
}


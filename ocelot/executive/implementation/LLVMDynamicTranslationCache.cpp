/*!
	\file LLVMDynamicTranslationCache.cpp
	\author Andrew Kerr <arkerr@gatech.edu>, Gregory Diamos <gregory.diamos@gatech.edu>
	\date March 2011
	\brief implements a dynamic execution environment 
*/

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/LLVMKernel.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/executive/interface/LLVMState.h>
#include <ocelot/executive/interface/LLVMDynamicTranslationCache.h>
#include <ocelot/executive/interface/LLVMDynamicExecutive.h>
#include <ocelot/analysis/interface/ConvertPredicationToSelectPass.h>
#include <ocelot/analysis/interface/LLVMUniformVectorization.h>
#include <ocelot/translator/interface/PTXToLLVMTranslator.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
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

/////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_ALL_LLVM_ASSEMBLY 0

#define REPORT_BASE 1

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace executive {

LLVMDynamicTranslationCache::LLVMDynamicTranslationCache() {

}

LLVMDynamicTranslationCache::~LLVMDynamicTranslationCache() {

}

/*!
	\brief gets a translation via its hyperblock ID or constructs it.
*/
const LLVMDynamicTranslationCache::Translation *
LLVMDynamicTranslationCache::getOrInsertTranslationById(HyperblockId id, int ws) {

	report("LLVMDynamicTranslationCache::getOrInsertTranslationById( id: " << id << ", ws: " << ws << ")");
		
	TranslatedSubkernelMap::const_iterator sk_it = subkernelMap.find(id);
	assert(sk_it != subkernelMap.end());
	
	TranslatedSubkernel *subkernel = sk_it->second;
	Translation *scalarTranslation = 0;
	if (subkernel->translations.find(1) == subkernel->translations.end()) {
		scalarTranslation = new Translation;
		executive::Device *device = modules[subkernel->parent->kernel->module->path()].device;
		scalarTranslation->metadata = compileTranslation(
			*subkernel->parent,
			*subkernel,
			*scalarTranslation,
			subkernel->parent->kernel,
			(translator::Translator::OptimizationLevel)api::OcelotConfiguration::get().executive.optimizationLevel,
			device
		);
		subkernel->translations[1] = scalarTranslation;
		
		assert(scalarTranslation->llvmFunction);
		assert(scalarTranslation->function);
		
		scalarTranslation->llvmFunction->dump();
	}
	assert(scalarTranslation && "failed to find scalar translation");
	if (ws > 1) {
		assert(0 && "non-scalar translation unimplemented");
	}
	
	return scalarTranslation;
}


//! \brief loads a module into the translation cache
bool LLVMDynamicTranslationCache::loadModule(const ir::Module *module, executive::Device *device) {
	ModuleMap::iterator mod_it = modules.find(module->path());
	if (mod_it == modules.end()) {
	
		report("LLVMDynamicTranslationCache::loadModule() - " << module->path());
	
		ModuleMetadata metadata;
		metadata.ptxModule = module;
		metadata.device = device;
		
		// apply PTX-level transformations to perform the hyperblock decomposition
		for(ir::Module::KernelMap::const_iterator kernel = module->kernels().begin(); 
			kernel != module->kernels().end();
			 ++kernel) {
			
			report("  transforming kernel '" << kernel->second->name << "'");
			
			TranslatedKernel *translatedKernel = new TranslatedKernel;
			translatedKernel->kernel = kernel->second;
			metadata.kernels[kernel->second->name] = translatedKernel;
			
			analysis::HyperblockFormation formationPass;
			
			formationPass.initialize(*module);
			formationPass.runOnKernel(translatedKernel->decomposition, *kernel->second);
			formationPass.finalize();

			// create subkernels
			typedef analysis::HyperblockFormation::KernelDecomposition::HyperblockMap HyperblockMap;
			for (HyperblockMap::const_iterator hb_it = translatedKernel->decomposition.hyperblocks.begin();
				hb_it != translatedKernel->decomposition.hyperblocks.end();
				++hb_it) {
				
				TranslatedSubkernel *translated = new TranslatedSubkernel;
				translatedKernel->subkernels[hb_it->second.hyperblockId] = translated;
				translated->parent = translatedKernel;
				translated->subkernel = hb_it->second.subkernel;
				translated->entryId = hb_it->second.hyperblockId;
				
				
				report("  adding hyperblock " << translated->entryId);
				
				subkernelMap[translated->entryId] = translated;
			}

		}
		
		modules.insert(std::make_pair(module->path(), metadata));
		return true;
	}
	return false;
}


/////////////////////////////////////////////////////////////////////////////////////////////////

LLVMDynamicTranslationCache::TranslatedKernel::TranslatedKernel(): kernelModule(0), kernel(0) {

}

LLVMDynamicTranslationCache::TranslatedKernel::~TranslatedKernel() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

LLVMDynamicTranslationCache::TranslatedSubkernel::TranslatedSubkernel(): parent(0), subkernel(0), entryId(0) {

}

LLVMDynamicTranslationCache::TranslatedSubkernel::~TranslatedSubkernel() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

LLVMDynamicTranslationCache::Translation::Translation():
llvmFunction(0), function(0), metadata(0), warpSize(1) {

}

LLVMDynamicTranslationCache::Translation::~Translation() {

}

void LLVMDynamicTranslationCache::Translation::execute(LLVMContext *contexts) const {
	report("Executing translation");
	function(contexts);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////
//
// This part is copied from Greg's excellent implementation and is used to complete the 
// translation to LLVM. We could probably abstract this part to enable multiple implementations
// of execution managers.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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
static void setupGlobalMemoryReferences(
	ir::PTXKernel& kernel,
	const ir::PTXKernel& parent)
{
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block) {
		
		for( ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction ) {
			
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**instruction);

			if (ptx.opcode == ir::PTXInstruction::Mov 
				&& (ptx.a.addressMode == ir::PTXOperand::Address
				|| ptx.a.addressMode == ir::PTXOperand::Indirect)) {
				
				ir::Module::GlobalMap::const_iterator global = 
					parent.module->globals().find(ptx.a.identifier);
					
				if(global == parent.module->globals().end()) {
					continue;
				}
				if(global->second.statement.directive != ir::PTXStatement::Global) {
					continue;
				}
					
				ptx.addressSpace = ir::PTXInstruction::Global;		
						
				report("   For instruction \"" << ptx.toString() 
					<< "\" setting address space to global.");
			}
		}
	}
}

/*!
	\brief computes layout of kernel arguments
*/
static void setupArgumentMemoryReferences(
	ir::PTXKernel& kernel,
	LLVMDynamicExecutive::Metadata* metadata,
	const ir::PTXKernel& parent)
{
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;
	report("  Setting up argument memory references.");

	unsigned int offset = 0;
	
	OffsetMap offsets;
	
	for(ir::Kernel::ParameterVector::const_iterator
		argument = parent.arguments.begin();
		argument != parent.arguments.end(); ++argument) {
		
		pad(offset, argument->getAlignment());
		offsets.insert(std::make_pair(argument->name, offset));
		
		report("   Argument " << argument->name << ", offset " << offset);
		offset += argument->getSize();
	}

	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); 
		++block) {
		
		for( ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction ) {
			
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);

			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St) {
				
				for(unsigned int i = 0; i != 4; ++i) {
				
					if(operands[i]->addressMode == ir::PTXOperand::Address) {
					
						OffsetMap::iterator argument = offsets.find( 
							operands[i]->identifier);
						if(argument != offsets.end()) {
						
							report("   For instruction \"" << ptx.toString() 
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
	
	report("   total argument memory size is " << metadata->argumentSize);
}

/*!
	\brief 
*/
static void setupParameterMemoryReferences(
	ir::PTXKernel& kernel,
	LLVMDynamicExecutive::Metadata* metadata,
	const ir::PTXKernel& parent)
{
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;
	report("  Setting up parameter memory references.");

	metadata->parameterSize	= 0;
	
	OffsetMap offsets;
	
	// Determine the order that parameters are passed as arguments to calls
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);
			if(ptx.opcode != ir::PTXInstruction::Call) continue;
			
			unsigned int offset = 0;
			
			report("   For arguments of call instruction '"
				<< ptx.toString() << "'");
			for (ir::PTXOperand::Array::const_iterator 
				argument = ptx.d.array.begin();
				argument != ptx.d.array.end(); ++argument) 
			{
				pad(offset, ir::PTXOperand::bytes(argument->type));
				assert(offsets.count(argument->identifier) == 0);
				offsets.insert(std::make_pair(argument->identifier, offset));
				report("    mapping '" << argument->identifier
					<< "' to " << offset);
				offset += ir::PTXOperand::bytes(argument->type);
			}
			
			for (ir::PTXOperand::Array::const_iterator 
				argument = ptx.b.array.begin();
				argument != ptx.b.array.end(); ++argument) 
			{
				pad(offset, ir::PTXOperand::bytes(argument->type));
				assert(offsets.count(argument->identifier) == 0);
				offsets.insert(std::make_pair(argument->identifier, offset));
				report("    mapping '" << argument->identifier
					<< "' to " << offset);
				offset += ir::PTXOperand::bytes(argument->type);
			}
			
			metadata->parameterSize = std::max(offset, metadata->parameterSize);
		}
	}
	
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block)
	{
		for( ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction )
		{
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);

			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St)
			{
				for(unsigned int i = 0; i != 4; ++i)
				{
					if(operands[i]->addressMode == ir::PTXOperand::Address)
					{
						OffsetMap::iterator parameter = offsets.find( 
							operands[i]->identifier);
						if(parameter != offsets.end())
						{
							report("   For instruction \"" 
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
	for(ir::Module::KernelMap::const_iterator
		function = kernel.module->kernels().begin();
		function != kernel.module->kernels().end(); ++function)
	{
		if(!function->second->function()) continue;
		
		unsigned int bytes = 0;
		
		for(ir::Kernel::ParameterVector::const_iterator
			argument = function->second->arguments.begin();
			argument != function->second->arguments.end(); ++argument)
		{
			pad(bytes, argument->getSize());
			bytes += argument->getSize();
		}
		
		metadata->parameterSize = std::max(bytes, metadata->parameterSize);
	}
	
	report("   total parameter memory size is " << metadata->parameterSize);
}

/*!
	\brief lays out shared memory
*/
static void setupSharedMemoryReferences(
	ir::PTXKernel& kernel,
	LLVMDynamicExecutive::Metadata* metadata,
	const ir::PTXKernel& parent)
{
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;
	typedef std::unordered_set<std::string> StringSet;
	typedef std::deque<ir::PTXOperand*> OperandVector;
	typedef std::unordered_map<std::string, 
		ir::Module::GlobalMap::const_iterator> GlobalMap;

	report( "  Setting up shared memory references." );

	OffsetMap offsets;
	StringSet external;
	OperandVector externalOperands;

	unsigned int externalAlignment = 1;             
	metadata->sharedSize = 0;

	for(ir::Module::GlobalMap::const_iterator 
		global = kernel.module->globals().begin(); 
		global != kernel.module->globals().end(); ++global) 
	{
		if(global->second.statement.directive == ir::PTXStatement::Shared) 
		{
			if(global->second.statement.attribute == ir::PTXStatement::Extern)
			{
				report("   Allocating global external shared variable " 
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
			else 
			{
				report("   Allocating global shared variable " 
					<< global->second.statement.name);
				pad(metadata->sharedSize, global->second.statement.alignment);
				offsets.insert(std::make_pair(global->second.statement.name, 
					metadata->sharedSize));
				metadata->sharedSize += global->second.statement.bytes();
			}
		}
	}

	ir::Kernel::LocalMap::const_iterator local = parent.locals.begin();
	for( ; local != parent.locals.end(); ++local)
	{
		if(local->second.space == ir::PTXInstruction::Shared)
		{
			if(local->second.attribute == ir::PTXStatement::Extern)
			{
				report("    Found local external shared variable " 
					<< local->second.name);
				assert( external.count(local->second.name) == 0 );
				external.insert( local->second.name);
				externalAlignment = std::max(externalAlignment, 
					(unsigned) local->second.alignment);
				externalAlignment = std::max(externalAlignment, 
				ir::PTXOperand::bytes(local->second.type));
			}
			else
			{
				report("   Found local shared variable " 
					<< local->second.name << " of size " 
					<< local->second.getSize());
				pad(metadata->sharedSize, local->second.alignment);
				offsets.insert(std::make_pair(local->second.name, 
					metadata->sharedSize));
				metadata->sharedSize += local->second.getSize();
			}
		}
	}
                
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);

			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St
				|| ptx.opcode == ir::PTXInstruction::Cvta)
			{
				for(unsigned int i = 0; i != 4; ++i)
				{
					if(operands[i]->addressMode == ir::PTXOperand::Address)
					{
						StringSet::iterator si = external.find(
							operands[i]->identifier);
						if(si != external.end()) 
						{
							report("   For instruction \"" 
								<< ptx.toString() 
								<< "\", mapping shared label \"" << *si 
								<< "\" to external shared memory.");
							externalOperands.push_back(operands[i]);
							continue;
						}
	
						OffsetMap::iterator offset = offsets.find(
							operands[i]->identifier);
						if(offsets.end() != offset) 
						{
							ptx.addressSpace = ir::PTXInstruction::Shared;
							operands[i]->offset += offset->second;
							report("   For instruction " 
								<< ptx.toString() << ", mapping shared label " 
								<< offset->first << " to " << offset->second);
						}
					}
				}
			}
		}
	}

	pad(metadata->sharedSize, externalAlignment);

	report("   Mapping external shared variables.");
	for( OperandVector::iterator operand = externalOperands.begin(); 
		operand != externalOperands.end(); ++operand) 
	{
		report("    Mapping external shared label " 
			<< (*operand)->identifier << " to " << metadata->sharedSize);
		(*operand)->offset += metadata->sharedSize;
	}

	report( "   Total shared memory size is " << metadata->sharedSize << "." );
}

/*!
	\brief 
*/
static void setupConstantMemoryReferences(
	ir::PTXKernel& kernel,
	LLVMDynamicExecutive::Metadata* metadata,
	const ir::PTXKernel& parent)
{
	report( "  Setting up constant memory references." );
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;

	metadata->constantSize = 0;
	OffsetMap constants;
	
	for(ir::Module::GlobalMap::const_iterator 
		global = parent.module->globals().begin(); 
		global != parent.module->globals().end(); ++global) 
	{
		if(global->second.statement.directive == ir::PTXStatement::Const) 
		{
			report( "   Found global constant variable " 
				<< global->second.statement.name << " of size " 
				<< global->second.statement.bytes() );
			pad(metadata->constantSize, global->second.statement.alignment);
			constants.insert(std::make_pair(global->second.statement.name,
				metadata->constantSize));
			metadata->constantSize += global->second.statement.bytes();
		}
	}

	report("   Total constant memory size is " << metadata->constantSize);

	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);
			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St)
			{
				for(unsigned int i = 0; i != 4; ++i)
				{
					if(operands[i]->addressMode == ir::PTXOperand::Address)
					{
						OffsetMap::iterator mapping = constants.find( 
							operands[i]->identifier);
						if(constants.end() != mapping) 
						{
							ptx.addressSpace = ir::PTXInstruction::Const;
							operands[i]->offset += mapping->second;
							report("   For instruction " 
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
static void setupTextureMemoryReferences(
	ir::PTXKernel& kernel,
	LLVMDynamicExecutive::Metadata* metadata,
	const ir::PTXKernel& parent, 
	executive::Device* device)
{
	typedef std::unordered_map<std::string, unsigned int> TextureMap;
	report(" Setting up texture memory references.");
	
	TextureMap textures;
	
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);
			if(ptx.opcode == ir::PTXInstruction::Tex)
			{
				report("  found texture instruction: " << ptx.toString());

				TextureMap::iterator reference =
					textures.find(ptx.a.identifier);
				if(reference != textures.end())
				{
					ptx.a.reg = reference->second;
				}
				else
				{
					ptx.a.reg = textures.size();
					textures.insert(std::make_pair(
						ptx.a.identifier, textures.size()));
						
					ir::Texture* texture = (ir::Texture*)
						device->getTextureReference(
						kernel.module->path(), ptx.a.identifier);
					assert(texture != 0);
					
					/*
						// TODO textures
					metadata->textures.push_back(texture);
					
					*/
					
					assert(0 && "unimplemented");
				}
			}
		}
	}
}

/*!
	\brief 
*/
static void setupLocalMemoryReferences(
	ir::PTXKernel& kernel,
	LLVMDynamicExecutive::Metadata* metadata,
	const ir::PTXKernel& parent)
{
	report( "  Setting up local memory references." );
	typedef std::unordered_map<std::string, unsigned int> OffsetMap;

	OffsetMap offsets;
	
	// Reserve the first few 32-bit words
	// [0] == subkernel-id
	// [1] == call type
	// [2] == barrier resume point if it exists
	metadata->localSize = 8;
	
	// give preference to barrier resume point
	ir::Kernel::LocalMap::const_iterator local = kernel.locals.find(
		"_Zocelot_barrier_next_kernel");
	if(local != kernel.locals.end())
	{
		if(local->second.space == ir::PTXInstruction::Local)
		{
			report("   Found local local variable " 
				<< local->second.name << " of size " 
				<< local->second.getSize());
			
			pad(metadata->localSize, local->second.alignment);
			offsets.insert(std::make_pair(local->second.name,
				metadata->localSize));
			metadata->localSize += local->second.getSize();
		}
	}

	// give preference to resume point
	local = kernel.locals.find("_Zocelot_resume_point");
	if(local != kernel.locals.end())
	{
		if(local->second.space == ir::PTXInstruction::Local)
		{
			report("   Found local local variable " 
				<< local->second.name << " of size " 
				<< local->second.getSize());
			
			pad(metadata->localSize, local->second.alignment);
			offsets.insert(std::make_pair(local->second.name,
				metadata->localSize));
			metadata->localSize += local->second.getSize();
		}
	}

	for(ir::Kernel::LocalMap::const_iterator local = kernel.locals.begin(); 
		local != kernel.locals.end(); ++local)
	{
		if(local->first == "_Zocelot_barrier_next_kernel") continue;
		if(local->first == "_Zocelot_spill_area")          continue;
		if(local->first == "_Zocelot_resume_point")        continue;
		
		if(local->second.space == ir::PTXInstruction::Local)
		{
			report("   Found local local variable " 
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
	if(local != kernel.locals.end())
	{
		if(local->second.space == ir::PTXInstruction::Local)
		{
			report("   Found local local variable " 
				<< local->second.name << " of size " 
				<< local->second.getSize());
			
			pad(metadata->localSize, local->second.alignment);
			offsets.insert(std::make_pair(local->second.name,
				metadata->localSize));
			metadata->localSize += local->second.getSize();
		}
	}
    
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);
			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};
	
			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St)
			{
				for(unsigned int i = 0; i != 4; ++i)
				{
					if(operands[i]->addressMode == ir::PTXOperand::Address)
					{
						OffsetMap::iterator offset = offsets.find( 
							operands[i]->identifier);
						if(offsets.end() != offset) 
						{
							ptx.addressSpace = ir::PTXInstruction::Local;
							operands[i]->offset += offset->second;
							report("   For instruction " 
								<< ptx.toString() << ", mapping local label " 
								<< offset->first << " to " << offset->second);
						}
					}
				}
			}
		}
	}

    report("   Total local memory size is " << metadata->localSize << ".");
}

/*!

*/
static void setupPTXMemoryReferences(
	ir::PTXKernel& kernel,
	LLVMDynamicExecutive::Metadata* metadata,
	const ir::PTXKernel& parent, executive::Device* device)
{
	report(" Setting up memory references for kernel variables.");
	
	setupGlobalMemoryReferences(kernel, parent);
	setupArgumentMemoryReferences(kernel, metadata, parent);
	setupParameterMemoryReferences(kernel, metadata, parent);
	setupSharedMemoryReferences(kernel, metadata, parent);
	setupConstantMemoryReferences(kernel, metadata, parent);
	setupTextureMemoryReferences(kernel, metadata, parent, device);
	setupLocalMemoryReferences(kernel, metadata, parent);
}

/*!
	\brief apply a set of optimizations and transformations to the PTX representation
		of the whole kernel
*/
static void optimizePTX(
	ir::PTXKernel& kernel,
	translator::Translator::OptimizationLevel optimization)
{
	report(" Building dataflow graph.");
	kernel.dfg();

	report(" Optimizing PTX");
	
	analysis::ConvertPredicationToSelectPass convertPredicationToSelect;
	report("  Running convert predication to select pass");
	convertPredicationToSelect.initialize(*kernel.module);
	convertPredicationToSelect.runOnKernel(kernel);
	convertPredicationToSelect.finalize();
	
	/*
	analysis::RemoveBarrierPass              removeBarriers(id);

	report("  Running remove barriers pass");
	removeBarriers.initialize(*kernel.module);
	removeBarriers.runOnKernel(kernel);
	removeBarriers.finalize();
	*/
		
	kernel.dfg()->toSsa();
}

/*!
	\brief 
*/
static void setupCallTargets(
	ir::PTXKernel& kernel,
	const LLVMDynamicTranslationCache & translationCache)
{
	// replace all call instruction operands with kernel id
	report("  Setting up targets of call instructions.");
	for(ir::ControlFlowGraph::iterator block = kernel.cfg()->begin(); 
		block != kernel.cfg()->end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);
			if(ptx.opcode != ir::PTXInstruction::Call 
				&& ptx.opcode != ir::PTXInstruction::Mov) continue;
			if(ptx.tailCall) continue;
			
			if(ptx.a.addressMode == ir::PTXOperand::FunctionName)
			{
				/*
					// TODO: setupCallTargets not implemented
				LLVMModuleManager::FunctionId id = database.getFunctionId(
					kernel.module->path(), ptx.a.identifier);
					*/
				
				assert(0 && "unimplemented");
				
				report("   setting target '" << ptx.a.identifier 
					<< "' of instruction '" << ptx.toString());
//				ptx.reentryPoint = id;
			}
		}
	}
}

/*!
	\brief 
*/
static void translate(
	llvm::Module*& module, 
	ir::PTXKernel& kernel,
	translator::Translator::OptimizationLevel optimization)
{
	assert(module == 0);

	report(" Translating kernel.");
	
	report("  Converting from PTX IR to LLVM IR.");
	translator::PTXToLLVMTranslator translator(optimization);
	ir::LLVMKernel* llvmKernel = static_cast<ir::LLVMKernel*>(translator.translate(&kernel));
	
	report("  Assembling LLVM kernel.");
	llvmKernel->assemble();
	llvm::SMDiagnostic error;

	module = new llvm::Module(kernel.name.c_str(), llvm::getGlobalContext());

	reportE(REPORT_ALL_LLVM_ASSEMBLY, llvmKernel->code());

	report("  Parsing LLVM assembly.");
	module = llvm::ParseAssemblyString(llvmKernel->code().c_str(), 
		module, error, llvm::getGlobalContext());

	if(module == 0) {
		report("   Parsing kernel failed, dumping code:\n" 
			<< llvmKernel->numberedCode());
			
		std::string m;
		llvm::raw_string_ostream message(m);
		message << "LLVM Parser failed: ";
		error.Print(kernel.name.c_str(), message);

		kernel.dfg()->fromSsa();

		throw hydrazine::Exception(message.str());
	}

	report("  Checking llvm module for errors.");
	std::string verifyError;
	
	if(llvm::verifyModule(*module, llvm::ReturnStatusAction, &verifyError)) {
	
		report("   Checking kernel failed, dumping code:\n" << llvmKernel->numberedCode());
			
		delete llvmKernel;
		delete module;
		module = 0;

		kernel.dfg()->fromSsa();

		throw hydrazine::Exception("LLVM Verifier failed for kernel: " 
			+ kernel.name + " : \"" + verifyError + "\"");
	}

	delete llvmKernel;
}

/*!
	\brief constructs a metadata instance
*/
static LLVMDynamicExecutive::Metadata* generateMetadata(
	ir::PTXKernel& kernel, 
	translator::Translator::OptimizationLevel level,
	int warpSize)
{
	LLVMDynamicExecutive::Metadata *metadata = new LLVMDynamicExecutive::Metadata;
	report(" Building metadata.");
	
	if(level == translator::Translator::DebugOptimization
		|| level == translator::Translator::ReportOptimization) {

		/*		
		report("  Adding debugging symbols");
		ir::ControlFlowGraph::BasicBlock::Id id = 0;
		
		for(
			analysis::DataflowGraph::iterator block = kernel.dfg()->begin(); 
			block != kernel.dfg()->end(); 
			++block) {
			

			block->block()->id = id++;
			metadata->blocks.insert(std::make_pair(block->id(), 
				block->block()));

		}
		*/
						
		assert(0 && "unimplemented");
	}
	
	metadata->kernel = &kernel;
	metadata->warpSize = warpSize;
	
	return metadata;
}

/*!
	\brief given a translated function, apply a selection of LLVM transformation
		passes before JIT compilation
	
	\param module
	\param optimization
	\param warpSize number of threads executed per function call
*/
static void optimize(
	llvm::Module& module,
	translator::Translator::OptimizationLevel optimization,
	int warpSize)
{
	report(" Optimizing kernel at level " 
		<< translator::Translator::toString(optimization));

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


	llvm::PassManager manager;

	manager.add(new llvm::TargetData(*LLVMState::jit()->getTargetData()));
	
	if (warpSize > 1) {
		report("\n\nAdding LLVM vectorization pass\n\n");
		manager.add(new analysis::LLVMUniformVectorization(warpSize));
	}

	if(level == 0)
	{
		report("no optimizations");
	}
	else if(level == 1)
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
}

/*!

*/
static void link(
	llvm::Module& module, 
	const ir::PTXKernel& kernel, 
	Device* device)
{
	report("  Linking global variables.");
	
	for(ir::Module::GlobalMap::const_iterator 
		global = kernel.module->globals().begin(); 
		global != kernel.module->globals().end(); ++global) 
	{
		if(global->second.statement.directive == ir::PTXStatement::Global) 
		{
			assert(device != 0);

			llvm::GlobalValue* value = module.getNamedValue(global->first);
			assertM(value != 0, "Global variable " << global->first 
				<< " not found in llvm module.");
			Device::MemoryAllocation* allocation = device->getGlobalAllocation( 
				kernel.module->path(), global->first);
			assert(allocation != 0);
			report("  Binding global variable " << global->first 
				<< " to " << allocation->pointer());
			LLVMState::jit()->addGlobalMapping(value, allocation->pointer());
		}
	}
}

/*!

*/
static llvm::Function *codegen(
	LLVMDynamicTranslationCache::TranslatedFunction &function, 
	llvm::Module& module,
	const ir::PTXKernel& kernel,
	Device* device) {
	
	report(" Generating native code.");
	
	LLVMState::jit()->addModule(&module);

	link(module, kernel, device);

	report("  Invoking LLVM to Native JIT");

	std::string name = "_Z_ocelotTranslated_" + kernel.name;
	
	llvm::Function* llvmFunction = module.getFunction(name);
	
	assertM(llvmFunction != 0, "Could not find function " + name);
	
	function = hydrazine::bit_cast<LLVMDynamicTranslationCache::TranslatedFunction>(
		LLVMState::jit()->getPointerToFunction(llvmFunction));
	
	assert(function);
	return llvmFunction;
}

#endif

/*!
	\brief entry point into PTX->LLVM translation process
	
	\param translation - existing translation instance to receive results of compilation
	\param module - pointer to module
	\param parent - pointer to parent PTX kernel
	\param optimization - optimziation level
	\param device - pointer to target device
*/
void *LLVMDynamicTranslationCache::compileTranslation(
	LLVMDynamicTranslationCache::TranslatedKernel &translatedKernel,
	LLVMDynamicTranslationCache::TranslatedSubkernel &translatedSubkernel,
	LLVMDynamicTranslationCache::Translation &translation,
	ir::PTXKernel *parent,
	translator::Translator::OptimizationLevel optimization,
	executive::Device *device) {

	#ifdef HAVE_LLVM
	report("Getting metadata for kernel '" << translatedSubkernel.subkernel->name << "'");
	
	report("Translating PTX");
	
	LLVMDynamicExecutive::Metadata *metadata = 0;
	
	// apply PTX optimizations and transformations needed to support the dynamic translation cache
	optimizePTX(*translatedSubkernel.subkernel, optimization);
		
	try {
	
		// compte memory sizes and layouts
		metadata = generateMetadata(*translatedSubkernel.subkernel, optimization, translation.warpSize);
		
		// translate global memory references
		setupPTXMemoryReferences(*translatedSubkernel.subkernel, metadata, *parent, device);

		// rewrite call functions with hyperblock exits chained to target functions
		setupCallTargets(*translatedSubkernel.subkernel, *this);
		
		// perform PTX to LLVM translation - construct a new LLVM module
		translate(translatedKernel.kernelModule, *translatedSubkernel.subkernel, optimization);

		// Converting out of ssa makes the assembly easier to read
		if(optimization == translator::Translator::ReportOptimization 
			|| optimization == translator::Translator::DebugOptimization)
		{
			translatedSubkernel.subkernel->dfg()->fromSsa();
		}
	}
	catch(...)
	{
		delete metadata;
		metadata = 0;
		throw;
	}
	
	try
	{
		// apply optimizations on the reuslting LLVM function
		optimize(*translatedKernel.kernelModule, optimization, translation.warpSize);
		
		// dynamically compile LLVM to host ISA
		translation.llvmFunction = codegen(translation.function, *translatedKernel.kernelModule, 
			*translatedSubkernel.subkernel, device);
		
		if (api::OcelotConfiguration::get().executive.printLLVMModule) {
			translatedKernel.kernelModule->dump();
		}
		
		// this step may be ellided for performance
		std::string errors;
		if (llvm::verifyModule(*translatedKernel.kernelModule, llvm::ReturnStatusAction, &errors)) {
			std::cerr << "llvm::verifyModule failed:" << errors << std::endl;
		}
	}
	catch(...)
	{
		llvm::Function* llvmFunction = translatedKernel.kernelModule->getFunction(translatedSubkernel.subkernel->name);

		LLVMState::jit()->freeMachineCodeForFunction(llvmFunction);

		LLVMState::jit()->removeModule(translatedKernel.kernelModule);
		delete translatedKernel.kernelModule;
		delete metadata;
		metadata = 0;
		
		throw;
	}

	return metadata;
	#else
	assertM(false, "LLVM support not compiled into ocelot.");
	#endif
}

////////////////////////////////////////////////////////////////////////////////


}


/*!
	\file LLVMUniformVectorization.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 2011
	\brief transformation pass on LLVM functions that performs vectorization for kernels with
			entirely uniform control flow
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
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/analysis/interface/LLVMUniformVectorization.h>
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

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_BASE 1

////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_INITIAL_SUBKERNEL 0
#define REPORT_FINAL_SUBKERNEL 1

//////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_VECTORIZING 0
#define REPORT_VECTORIZATION_STATISTICS 0

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Inserted LLVM debugging procedures for debugging execution faults
//

#define INSERT_DEBUG_CONTROL_FLOW 0
#define INSERT_DEBUG_REPORTING 0
#define DEBUG_REPORT_BLOCKS 0
#define DEBUG_REPORT_STORES 0
#define DEBUG_REPORT_LOADS 0
#define DEBUG_REPORT_RETURNS 0

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Minor compiler-inserted optimizations
//

#define OPT_PREFETCH_LOCAL_MEMORY 1

//////////////////////////////////////////////////////////////////////////////////////////////////

char analysis::LLVMUniformVectorization::ID = 127;

std::string operator+(const std::string &str, llvm::Value *value) {
	std::string valStr;
	return str + valStr;
}

std::ostream &operator<<(std::ostream &out, llvm::Value &value) {
	std::string str;
	llvm::raw_string_ostream os(str);
	value.print(os);
	out << str;
	return out;
}

std::ostream &operator<<(std::ostream &out, llvm::Value *value) {
	std::string str;
	llvm::raw_string_ostream os(str);
	value->print(os);
	out << str;
	return out;
}

std::string String(llvm::Value *value) {
	std::string str;
	llvm::raw_string_ostream os(str);
	value->print(os);
	return str;
}
std::string String(llvm::Function *func) {
	std::string str;
	llvm::raw_string_ostream os(str);
	func->print(os);
	return str;
}
std::string String(llvm::Type *value) {
	std::string str;
	llvm::raw_string_ostream os(str);
	value->print(os);
	return str;
}

std::ostream &Instruction_print(std::ostream &out, llvm::Instruction * inst) {
	std::string str;
	llvm::raw_string_ostream os(str);
	inst->print(os);
	out << str;
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! 
analysis::LLVMUniformVectorization::LLVMUniformVectorization(
	KernelGraph *_kernelGraph, 
	SubkernelId _subkernelId, 
	int _ws,
	bool _vectorize,
	int _threadInvariant,
	bool _affineMemory
):
	llvm::FunctionPass(ID), kernelGraph(_kernelGraph), subkernelId(_subkernelId), 
		warpSize(_ws), vectorizeConvergent(_vectorize), 
			threadInvariant(_threadInvariant),
			vectorizeAffineMemory(_affineMemory && 
				(_threadInvariant & (ThreadInvariant_scalarization | ThreadInvariant_sameCta)))
{
	report("LLVMUniformVectorization() on kernel " << kernelGraph->ptxKernel->name);
}

//! 
analysis::LLVMUniformVectorization::~LLVMUniformVectorization() {

}

bool analysis::LLVMUniformVectorization::doInitialize(llvm::Module &_m) {
	M = &_m;
	return false;
}

//! \brief entry point for pass
bool analysis::LLVMUniformVectorization::runOnFunction(llvm::Function &F) {
	Translation translation(&F, &kernelGraph->subkernels[subkernelId], this);
	return true;
}

//! \brief gets the name of the pass
const char *analysis::LLVMUniformVectorization::getPassName() const {
	return "Ocelot LLVM Uniform Vectorization";
}

//! \brief gets the kind of tye pass
llvm::PassKind analysis::LLVMUniformVectorization::getPassKind() const {
	return llvm::PT_Function;
}

llvm::LLVMContext & analysis::LLVMUniformVectorization::Translation::context() const {
	return function->getContext();
}

llvm::Type *analysis::LLVMUniformVectorization::Translation::getVoidTy() const {
	return llvm::Type::getVoidTy(context());
}

llvm::IntegerType *analysis::LLVMUniformVectorization::Translation::getTyInt(int n) const {
	return llvm::IntegerType::get(context(), n);
}

llvm::ConstantInt *analysis::LLVMUniformVectorization::Translation::getConstInt32(int n) const {
	return llvm::ConstantInt::get(llvm::Type::getInt32Ty(context()), n);
}

llvm::ConstantInt *analysis::LLVMUniformVectorization::Translation::getConstInt16(short n) const {
	return llvm::ConstantInt::get(llvm::Type::getInt16Ty(context()), n);
}

llvm::ConstantInt *analysis::LLVMUniformVectorization::Translation::getConstInt64(size_t n) const {
	return llvm::ConstantInt::get(getTyInt(64), n);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

namespace analysis {

//! pointers-to-member for class ThreadLocalArgument
llvm::Instruction * analysis::LLVMUniformVectorization::ThreadLocalArgument::* 
	LLVMUniformVectorization::ThreadLocalArgumentInstances[] = {
	
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::threadId_x, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::threadId_y, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::threadId_z, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::blockDim_x, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::blockDim_y, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::blockDim_z, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::blockId_x, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::blockId_y, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::blockId_z, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::gridDim_x, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::gridDim_y, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::gridDim_z, 
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::localPointer,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::sharedPointer,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::constantPointer,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::parameterPointer,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::argumentPointer,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::globallyScopedLocal,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::externalSharedSize,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::metadataPointer,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::ptrThreadDescriptorArray
};

//! pointers-to-member for just the address space pointers in class ThreadLocalArgument
llvm::Instruction * analysis::LLVMUniformVectorization::ThreadLocalArgument::* 
	*LLVMUniformVectorization::ThreadLocalArgumentPointerInstances = &ThreadLocalArgumentInstances[12];

//! Assuming threads are from the same CTA, indidcates which arguments are thread-variant
bool LLVMUniformVectorization::ThreadLocalArgumentVarianceMap[] = {
	true,		// threadId_x
	true,		// threadId_y
	true,		// threadId_z
	false,	// blockDim_x
	false,	// blockDim_y
	false,	// blockDim_z
	false,	// blockId_x
	false,	// blockId_y
	false,	// blockId_z
	false,	// gridDim_x
	false,	// gridDim_y
	false,	// gridDim_z
	true,		// localPointer
	false,	// sharedPointer
	false,	// constantPointer
	true,		// parameterPointer
	false,	// argumentPointer
	true,   // globallyScopedLocal
	false,  // externalSharedSize
	false	// metadataPointer
};

//! Thread variance map for just the address space pointers
bool *LLVMUniformVectorization::ThreadLocalArgumentPointerVarianceMap = 
	&ThreadLocalArgumentVarianceMap[12];

}

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::Translation::Translation(
	llvm::Function *f, 
	Subkernel *_subkernel,
	LLVMUniformVectorization *_pass
):
	function(f),
	subkernel(_subkernel),
	pass(_pass)
{
	report("Translation(" << f->getName().str() << ") on subkernel with warp size " << pass->warpSize);
	
	// some preliminary clean-up
	_eliminateUselessExits();
	
#if REPORT_BASE && REPORT_INITIAL_SUBKERNEL
	report(" LLVM function before vectorization\n" << String(function));
#endif

	_scalarPreprocess();
	
	if (pass->warpSize > 1) {
		_transformWarpSynchronous();
		_divergenceHandling();
		
	#if INSERT_DEBUG_REPORTING
		_debugReporting();
	#endif
	#if INSERT_DEBUG_CONTROL_FLOW
		_debugControlFlowMatrix();
	#endif
	}
	
	_eliminateEmptyBlocks();
	
	_createBackEdges();
	
	report("Translation(" << f->getName().str() << ", ws " << pass->warpSize << ") complete");
#if REPORT_BASE && REPORT_FINAL_SUBKERNEL
	report(" LLVM function:\n" << String(function));
#endif

#if REPORT_VECTORIZATION_STATISTICS
	{
		VectorizationStatistics statistics;
		_computeVectorizationStatistics(statistics);
		std::string name = f->getName().str() + ".vec-statistics";
		std::ofstream file(name);
		statistics.write(file);
	}
#endif
}

analysis::LLVMUniformVectorization::Translation::~Translation() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::_scalarPreprocess() {
	report("Scalar Preprocessing step");
	
	// identify mapping from LLVM blocks to GPU Ocelot blocks
	_computeLLVMToOcelotBlockMap();

	// identify possible entry points
	_enumerateEntries();
	
	// construct scheduler entry and load thread-local values
	_initializeSchedulerEntryBlock();

	// relocate any additional blocks created during translation
	_hoistDeclarationBlocks();
	
	// complete scheduler
	_completeSchedulerEntryBlock();
		
	// clean-up step
	_scalarOptimization();
	
	if (pass->warpSize == 1) {
#if INSERT_DEBUG_REPORTING
	_debugReporting();
#endif
#if INSERT_DEBUG_CONTROL_FLOW
	_debugControlFlowMatrix();
#endif
	}
	
	report("Scalar Preprocessing step complete");
}

void analysis::LLVMUniformVectorization::Translation::_computeLLVMToOcelotBlockMap() {

	std::map< std::string, ir::BasicBlock::Pointer > blockLabelMap;
	for (ir::ControlFlowGraph::iterator bb_it =	subkernel->subkernel->cfg()->begin();
		bb_it != subkernel->subkernel->cfg()->end(); ++bb_it) {
		
		report("   adding mapping " << bb_it->label);
		blockLabelMap[bb_it->label] = bb_it;
	}
	
	for (llvm::Function::iterator llvmbb_it = function->begin(); 
		llvmbb_it != function->end(); ++llvmbb_it) {
		
		llvm::BasicBlock *llvmBlock = &*llvmbb_it;
		
		std::string label = llvmbb_it->getName().str();
		std::map< std::string, ir::BasicBlock::Pointer >::iterator entry_it = blockLabelMap.find(label);
		if (entry_it != blockLabelMap.end()) {
		
			ir::BasicBlock::Pointer ocelotBlock = entry_it->second;
		
			llvmToOcelotBlockMap[llvmBlock] = ocelotBlock;
			ocelotToLlvmBlockMap[ocelotBlock] = llvmBlock;
		}
		else {
			report("  failed to find label '" << label << "' in Ocelot block mapping");
		}
	}
}

void analysis::LLVMUniformVectorization::Translation::_enumerateEntries() {
	typedef analysis::KernelPartitioningPass::ExternalEdgeVector ExternalEdgeVector;
	typedef analysis::KernelPartitioningPass::ExternalEdge ExternalEdge;
	
	report("_enumerateEntries()");
	
	ExternalEdgeVector Subkernel::*entryLists[] = {
		&Subkernel::inEdges,
	};
	
	for (int i = 0; i < 1; i++) {
		for (ExternalEdgeVector::iterator edge_it = (subkernel->*(entryLists[i])).begin();
			edge_it != (subkernel->*(entryLists[i])).end(); ++edge_it) {
			ExternalEdge &edge = *edge_it;
			
			schedulerEntryBlock.entries[edge.entryId] = ocelotToLlvmBlockMap[edge.handler];
			
			report("  adding entry " << edge.entryId << " to " 
				<< schedulerEntryBlock.entries[edge.entryId]->getName().str());
		}
	}
}

//! \brief replaces uses of thread-local arguments with explicit references
void analysis::LLVMUniformVectorization::Translation::_initializeSchedulerEntryBlock() {
	report(" Initializing scheduler entry block");
	
	// create scheduler
	report(" creating scheduler block");
	schedulerEntryBlock.defaultEntry = &function->getEntryBlock();
	schedulerEntryBlock.block = llvm::BasicBlock::Create(context(), "SchedulerEntry", function, 
		schedulerEntryBlock.defaultEntry);
	
	report("   extracting thread-local arguments");
	ThreadLocalArgument localArgs;
	_loadThreadLocal(localArgs, 0, 0, schedulerEntryBlock.block);
	schedulerEntryBlock.threadLocalArguments.push_back(localArgs);
	schedulerEntryBlock.threadLocalArguments.at(0).threadIdUses = 0;
	
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		if (&*bb_it == schedulerEntryBlock.block) {
			continue;
		}
		
		std::vector<llvm::GetElementPtrInst *> toVisit;
		for (llvm::BasicBlock::iterator inst_it = bb_it->begin(); inst_it != bb_it->end(); ++inst_it) {
			if (llvm::GetElementPtrInst *gemp = llvm::dyn_cast<llvm::GetElementPtrInst>(&*inst_it)) {
				if (gemp->getPointerOperand() == 
					static_cast<llvm::Value *>(schedulerEntryBlock.threadLocalArguments[0].context)) {
					toVisit.push_back(gemp);
				}
			}
		}
		
		for (auto inst_it = toVisit.begin(); inst_it != toVisit.end(); ++inst_it) {
			
			llvm::GetElementPtrInst * &gemp = *inst_it;			
			ThreadLocalArgument &local = schedulerEntryBlock.threadLocalArguments.at(0);
			
			// match GEMP indices
			llvm::Instruction *selected = 0;
			int indices[4];
			int indexCount = 0;
			for (llvm::User::op_iterator op_it = gemp->idx_begin(); 
				op_it != gemp->idx_end(); ++op_it, ++indexCount) {
				llvm::ConstantInt *constInt = llvm::dyn_cast<llvm::ConstantInt>(*op_it);
				assert(constInt && "failed to cast index to constant int");
				indices[indexCount] = constInt->getZExtValue();
			}
			if (indices[1] <= 3) {
				assert(indices[2] >= 0 && indices[2] < 3);
				int idx = indices[1] * 3 + indices[2];
				if (indices[1] == 0) {
					local.threadIdUses |= (1 << indices[2]);
				}
				selected = (local.*(ThreadLocalArgumentInstances[idx]));
			}
			else {
				int idx = indices[1] - 4;
				selected = (local.*(ThreadLocalArgumentPointerInstances[idx]));
			}
			assert(selected && "failed to identify thread-local argument");
			
			std::vector< llvm::LoadInst * > killWithFire;
			for (llvm::Value::use_iterator use_it = gemp->use_begin(); use_it != gemp->use_end(); ++use_it) {
				llvm::User *user = *use_it;
				
				llvm::LoadInst *loadInst = llvm::dyn_cast<llvm::LoadInst>(user);
				assert(loadInst && "user of GEMP must be LoadInst");
				loadInst->replaceAllUsesWith(selected);
				killWithFire.push_back(loadInst);
			}
			for (std::vector< llvm::LoadInst * >::iterator kill_it = killWithFire.begin();
				kill_it != killWithFire.end(); ++kill_it) {
				(*kill_it)->eraseFromParent();
			}
			gemp->eraseFromParent();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::_loadThreadLocal(
	ThreadLocalArgument &local, int threadId, llvm::Instruction *before, llvm::BasicBlock *block) {
		
	if (!block) {
		block = before->getParent();
	}
	
	report("  Loading thread-local arguments for thread " << threadId);
	report("  inserting into block " << block->getName().str());
	
	bool sameCta = ((pass->threadInvariant & ThreadInvariant_sameCta) && threadId);
	
	local.context = &function->getArgumentList().front();
	std::string threadSuffix = std::string(".t") + boost::lexical_cast<std::string, int>(threadId);
	
	report("  local.context = " << String(local.context));
	report("  type = " << String(local.context->getType()));
	
	ThreadLocalArgument * baseThread = (threadId ? &schedulerEntryBlock.threadLocalArguments.at(0) : 0);
	
	const char *dim3names[] = { "threadId", "blockDim", "blockId", "gridDim" };
	const char *dim3suffix[] = {"x", "y", "z"};
	
	for (int idx = 0; idx < 4; idx++) {
		for (int j = 0; j < 3; j++) {
			std::vector< llvm::Value *> ind;
			ind.push_back(getConstInt32(threadId));
			ind.push_back(getConstInt32(idx));
			ind.push_back(getConstInt32(j));
			ThreadLocalArgumentMemberPointer argument = ThreadLocalArgumentInstances[idx * 3 + j];
			
			if (ThreadLocalArgumentVarianceMap[idx * 3 + j] || !sameCta) {
			
				llvm::GetElementPtrInst *ptr = llvm::GetElementPtrInst::Create(local.context, 
					llvm::ArrayRef<llvm::Value*>(ind), "", block);
				if (before) {
					ptr->moveBefore(before);
				}
			
				std::string name = std::string(dim3names[idx]) + "." + dim3suffix[j] + threadSuffix;
				(local.*argument) = new llvm::LoadInst(ptr, name, block);
				if (before) {
					(local.*argument)->moveBefore(before);
				}
			}
			else {
				assert(baseThread && "_loadThreadLocal() must be called for threadId=0 first");
				(local.*argument) = (baseThread->*argument);
			}
		}
	}
	
	const char *ptrNames[] = {
		"localPtr", "sharedPtr", "constPtr", "paramPtr", "argumentPtr", "globallyScopedLocalPtr", 
		"externalSharedSize", "metadataPtr", 
	};
	for (int idx = 0; idx < 8; idx++) {
		ThreadLocalArgumentMemberPointer argument = ThreadLocalArgumentPointerInstances[idx];
		
		if (ThreadLocalArgumentPointerVarianceMap[idx] || !sameCta) {
			std::vector< llvm::Value *> ind;
			ind.push_back(getConstInt32(threadId));
			ind.push_back(getConstInt32(idx + 4));
		
			llvm::GetElementPtrInst *ptr = llvm::GetElementPtrInst::Create(local.context, 
				llvm::ArrayRef<llvm::Value*>(ind), std::string(ptrNames[idx]) + "Ptr" + threadSuffix, block);
			if (before) {
				ptr->moveBefore(before);
			}
		
			(local.*argument) = new llvm::LoadInst(ptr, ptrNames[idx] + threadSuffix, block);
			if (before) {
				(local.*argument)->moveBefore(before);
			}
			if (OPT_PREFETCH_LOCAL_MEMORY  && !idx) {
				_prefetchLocalMemory(local.*argument, 32);
			}
		}
		else {
			assert(baseThread && "_loadThreadLocal() must be called for threadId=0 first");
			(local.*argument) = (baseThread->*argument);
		}
	}
}

void analysis::LLVMUniformVectorization::Translation::_prefetchLocalMemory(
	llvm::Instruction *localPtr, size_t localSize) {
	
	std::vector<llvm::Type*> funcTypeArgs;
	funcTypeArgs.push_back(llvm::PointerType::get(getTyInt(8), 0));
	funcTypeArgs.push_back(getTyInt(32));
	funcTypeArgs.push_back(getTyInt(32));
	funcTypeArgs.push_back(getTyInt(32));
	llvm::FunctionType *funcType = llvm::FunctionType::get(getVoidTy(), 
		llvm::ArrayRef<llvm::Type*>(funcTypeArgs), false);
	llvm::Constant *prefetchFn = function->getParent()->getOrInsertFunction("llvm.prefetch", funcType);

	assert(prefetchFn && "Failed to get reference to llvm.prefetch() intrinsic");
	
	size_t lineSize = 64;
	for (size_t offset = 0; offset < localSize; offset += lineSize) {
		
		llvm::Instruction *ptr = localPtr;
		if (offset) {
			std::vector< llvm::Value *> args;
			args.push_back(getConstInt32(offset));
			llvm::Instruction *getPtrInst = llvm::GetElementPtrInst::Create(localPtr, 
				llvm::ArrayRef<llvm::Value*>(args), "prefetchLocalPtr", localPtr);
			getPtrInst->removeFromParent();
			getPtrInst->insertAfter(localPtr);
			ptr = getPtrInst;
		}
		std::vector< llvm::Value *> args;
		args.push_back(ptr);
		args.push_back(getConstInt32(1));		// rw: 1 - write
		args.push_back(getConstInt32(1));		// locality, 0-3
		args.push_back(getConstInt32(1));		// cache type: 0 - instruction, 1 - data
		
		llvm::CallInst *prefetchCall = llvm::CallInst::Create(prefetchFn, 
			llvm::ArrayRef<llvm::Value*>(args), "", localPtr);
		prefetchCall->removeFromParent();
		prefetchCall->insertAfter(localPtr);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::_propagateConstants() {
	report("_propagateConstants()");
	
}

void analysis::LLVMUniformVectorization::Translation::_hoistDeclarationBlocks() {
	const char *initializerBlocks[] = { 
		"$OcelotRegisterInitializerBlock", 
		"$OcelotTextureAllocateBlock", 
		0
	};
	
	report("_hoistDeclarationBlocks()");
	
	std::vector<llvm::BasicBlock *> killBlocks;
	
	for (int i = 0; initializerBlocks[i]; i++) {
		llvm::BasicBlock *block = 0;
		std::vector< llvm::Instruction * > instructions;
		for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
			if (bb_it->getName().str() == initializerBlocks[i]) {
				block = &*bb_it;
				for (llvm::BasicBlock::iterator inst_it = bb_it->begin(); inst_it != bb_it->end(); ++inst_it) {
					instructions.push_back(&*inst_it);
				}
				break;
			}
		}
	
		if (block) {
			report("  hoisting declarations in " << block->getName().str());
			
			for (std::vector< llvm::Instruction * >::iterator inst_it = instructions.begin(); 
				inst_it != instructions.end(); ++inst_it) {
				llvm::TerminatorInst *termInst = llvm::dyn_cast<llvm::TerminatorInst>(*inst_it);
				if (termInst) {
					bool found = false;
					for (int j = 0; initializerBlocks[j]; ++j) {
						if (termInst->getSuccessor(0)->getName().str() == initializerBlocks[j]) {
							found = true;
							break;
						}
					}
					if (!found) {
						schedulerEntryBlock.defaultEntry = termInst->getSuccessor(0);
					}
					termInst->eraseFromParent();
				}
				else {
					llvm::Instruction *inst = *inst_it;
					inst->removeFromParent();
					inst->insertAfter(&schedulerEntryBlock.block->back());
					
					schedulerEntryBlock.threadLocalArguments[0].declarations.push_back(inst);
					
					report("   " << String(inst));
				}
			}	
			killBlocks.push_back(block);
		}
	}
	report("  deleting " << killBlocks.size() << " blocks");
	for (auto kill_it = killBlocks.begin(); kill_it != killBlocks.end(); ++kill_it) {
		(*kill_it)->eraseFromParent();
	}
}

void analysis::LLVMUniformVectorization::Translation::_completeSchedulerEntryBlock( ) {
	report("  _completeSchedulerEntryBlock()");
	
	llvm::BitCastInst *bitcastPtr = new llvm::BitCastInst(
		schedulerEntryBlock.threadLocalArguments[0].localPointer, 
		llvm::PointerType::get(llvm::IntegerType::get(context(), 32), 0), 
		"bitcast", schedulerEntryBlock.block);
	llvm::LoadInst *encodedResumePoint = new llvm::LoadInst(bitcastPtr, "encodedResumePoint", 
		schedulerEntryBlock.block);
	
	llvm::BinaryOperator *resumePoint = llvm::BinaryOperator::Create(llvm::Instruction::And, 
		encodedResumePoint, getConstInt32(0x0ffff), "resumePoint", schedulerEntryBlock.block);
	
	for (EntryMap::const_iterator entry_it = schedulerEntryBlock.entries.begin();
		llvm::dyn_cast<llvm::PHINode>(&(schedulerEntryBlock.defaultEntry->front())); ++entry_it) {
		
		if (entry_it != schedulerEntryBlock.entries.end()) {
			schedulerEntryBlock.defaultEntry = entry_it->second;
		}
		else {
			assert(0 && "Entry block contains PHI nodes, and we have no acceptable entry handlers");
			return;
		}
	}
	
	llvm::SwitchInst *switchInst = llvm::SwitchInst::Create(resumePoint, schedulerEntryBlock.defaultEntry, 
		schedulerEntryBlock.entries.size() + 1, schedulerEntryBlock.block);
	
	report("    default entry: " << schedulerEntryBlock.defaultEntry->getName().str());
	
	unsigned int idx = 0;
	for (EntryMap::const_iterator entry_it = schedulerEntryBlock.entries.begin();
		entry_it != schedulerEntryBlock.entries.end(); ++entry_it, ++idx) {

		switchInst->addCase(getConstInt32(entry_it->first & 0x0ffff), entry_it->second);		
		report("  added successor " << idx << " -> " << entry_it->second->getName().str());
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::_scalarOptimization() {
	if (pass->warpSize == 1) {
		_eliminateEmptyBlocks();
	}
	_basicBlockPasses();
}

void analysis::LLVMUniformVectorization::Translation::_basicBlockPasses() {
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		_eliminateBitcasts(bb_it);
	}
}

void analysis::LLVMUniformVectorization::Translation::_eliminateUselessExits() {

	std::vector< llvm::BasicBlock *> killWithFire;
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		
		if (llvm::ReturnInst::classof(bb_it->getFirstNonPHI())) {
			if (llvm::pred_begin(&*bb_it) == llvm::pred_end(&*bb_it)) {
				killWithFire.push_back(&*bb_it);
			}
			else {
				// delete all but the last exit or return
				std::vector< llvm::Instruction *> killInst;
				llvm::BasicBlock::iterator next_it;
				for (llvm::BasicBlock::iterator inst_it = bb_it->begin(); inst_it != bb_it->end(); ++inst_it) {
					next_it = inst_it;
					++next_it;
					if (next_it != bb_it->end()) {
						killInst.push_back(&*inst_it);
					}
				}
				for (auto inst_it = killInst.begin(); inst_it != killInst.end(); ++inst_it) {
					(*inst_it)->eraseFromParent();
				}
			}
		}
	}
	for (auto kill_it = killWithFire.begin(); kill_it != killWithFire.end(); ++kill_it) {
		(*kill_it)->eraseFromParent();
	}
}

void analysis::LLVMUniformVectorization::Translation::_eliminateBitcasts(
	llvm::Function::iterator bb_it) {
	std::vector< llvm::Instruction *> killWithFire;
	for (llvm::BasicBlock::iterator inst_it = bb_it->begin(); inst_it != bb_it->end(); ++inst_it) {
		if (llvm::BitCastInst *bitcast = llvm::dyn_cast<llvm::BitCastInst>(&*inst_it)) {
			if (bitcast->getSrcTy() == bitcast->getDestTy()) {
				llvm::User::op_iterator op_it = bitcast->op_begin();				
				bitcast->replaceAllUsesWith(*op_it);
				killWithFire.push_back(bitcast);
			}
		}
	}
	for (std::vector< llvm::Instruction *> ::iterator kill_it = killWithFire.begin();
		kill_it != killWithFire.end(); ++kill_it) {
		(*kill_it)->eraseFromParent();
	}
}

void analysis::LLVMUniformVectorization::Translation::_promoteGempPointerArithmetic(
	llvm::Function::iterator bb_it) {
	for (llvm::BasicBlock::iterator inst_it = bb_it->begin(); inst_it != bb_it->end(); ++inst_it) {
		llvm::PtrToIntInst *ptrToInt = llvm::dyn_cast<llvm::PtrToIntInst>(&*inst_it);
		llvm::BinaryOperator *binop = 0;
		llvm::IntToPtrInst *intToPtr = 0;
		bool promoted = false;
		if (inst_it->hasOneUse() && ptrToInt) {
			// if user is single add instruction
			binop = llvm::dyn_cast<llvm::BinaryOperator>(*ptrToInt->use_begin());
			if (ptrToInt->hasOneUse() && binop && binop->getOpcode() == 9) {
				intToPtr = llvm::dyn_cast<llvm::IntToPtrInst>(*binop->use_begin());
				if (intToPtr && 
					binop->hasOneUse() && 
					ptrToInt->getParent() == binop->getParent() &&
					binop->getParent() == intToPtr->getParent()) {
					
					// replace all three with one gemp
					report("  Promoting pointer arithmetic to GEMP instruction");
					report("    src ptr type: " << String(ptrToInt->getSrcTy()));
					report("    dst ptr type: " << String(intToPtr->getDestTy()));
				}
			}
		}
		if (promoted) {
			inst_it = bb_it->begin();
		}
	}
}

void analysis::LLVMUniformVectorization::Translation::_eraseBlock(llvm::BasicBlock *block) {
	report("Translation::_eraseBlock( " << block->getName().str() << ")");
	
	LLVMtoOcelotBlockMap::iterator block_it = llvmToOcelotBlockMap.find(block);
	if (block_it != llvmToOcelotBlockMap.end()) {
		OcelotToLLVMBlockMap::iterator ocelot_it = ocelotToLlvmBlockMap.find(block_it->second);
		if (ocelot_it != ocelotToLlvmBlockMap.end()) {
			ocelotToLlvmBlockMap.erase(ocelot_it);
		}
		llvmToOcelotBlockMap.erase(block_it);
	}
	
	report("  users: ");
	
	// visit users
	for (llvm::BasicBlock::iterator inst_it = block->begin(); inst_it != block->end(); ++inst_it) {
		inst_it->replaceAllUsesWith(llvm::UndefValue::get(inst_it->getType()));
	}
	
	report("  erasing block " << block->getName().str());
	block->eraseFromParent();
}

void analysis::LLVMUniformVectorization::Translation::_eliminateEmptyBlocks() {
	report("_eliminateEmptyBlocks()");
	
	std::vector< llvm::BasicBlock *> killWithFire;
	llvm::Function::iterator bb_it = function->begin();
	++bb_it;
	for (; bb_it != function->end(); ++bb_it) {
		int count = 0;
		
		report("  visiting block: " << bb_it->getName().str());
		
		std::stringstream ss;
		
		for (llvm::pred_iterator pred_it = llvm::pred_begin(&*bb_it); 
			pred_it != llvm::pred_end(&*bb_it); ++pred_it, ++count) {
			
			ss << (count ? ", " : "") << (*pred_it)->getName().str();
		}
		if (!count) {
			report("    - no predecessors");
			killWithFire.push_back(&*bb_it);
		}
		else {
			report("    - " << count << " predecessors: " << ss.str());
		}
	}
	report("Eliminating block with no predecessors: (" << killWithFire.size() << " blocks)");
	for (std::vector< llvm::BasicBlock *>::iterator bb_it = killWithFire.begin(); 
		bb_it != killWithFire.end(); ++bb_it ) {
		report(" block: " << (*bb_it)->getName().str());
		report("  successors: ");
		
		_eraseBlock(*bb_it);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief transforms the kernel into a form that executes multiple logical threads
*/
void analysis::LLVMUniformVectorization::Translation::_transformWarpSynchronous() {
	report("Transform Warp Synchronous begin");
	if (pass->warpSize > 1) {
		_identifyScheduler();
		_packThreadLocal();
		_replicateInstructions();
		_resolveDependencies();
		
		if (pass->vectorizeAffineMemory) {
			_affineMemoryAccesses();
		}
		
		if (pass->vectorizeConvergent) {
			_vectorizeReplicated();
		}
	}
	
	_finalizeTranslation();
	report("Transform Warp Synchronous complete");
}

void analysis::LLVMUniformVectorization::Translation::_replicateInstructions() {
	report("  replicateInstructions()");
	
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		if (&*bb_it == schedulerEntryBlock.block) {
		
			// replicate declarations
			for (InstructionVector::iterator inst_it = schedulerEntryBlock.threadLocalArguments[0].declarations.begin();
				inst_it != schedulerEntryBlock.threadLocalArguments[0].declarations.end(); ++inst_it) {
			
				_replicateInstruction(*inst_it);
			}
		
			continue;
		}
		else {
			std::vector< llvm::Instruction *> instructions;
			instructions.reserve(bb_it->getInstList().size());
			
			for (llvm::BasicBlock::iterator inst_it = bb_it->begin(); inst_it != bb_it->end(); ++inst_it) {
				if (llvm::TerminatorInst *terminator = llvm::dyn_cast<llvm::TerminatorInst>(&*inst_it)) {
					assert(terminator);
				}
				else {
					instructions.push_back(&*inst_it);
				}
			}
			for (std::vector< llvm::Instruction *>::iterator inst_it = instructions.begin();
				inst_it != instructions.end(); ++inst_it) {
				_replicateInstruction(*inst_it);
			}
		}
	}
}


void analysis::LLVMUniformVectorization::Translation::_identifyScheduler() {
	report("_identifyScheduler()");
	
}

void analysis::LLVMUniformVectorization::Translation::_packThreadLocal() {
	report("  packThreadLocal()");
	
	assert(schedulerEntryBlock.block);
	
	for (int tid = 1; tid < pass->warpSize; tid++) {
		ThreadLocalArgument localArgs;
		_loadThreadLocal(localArgs, tid, schedulerEntryBlock.block->getTerminator());
		schedulerEntryBlock.threadLocalArguments.push_back(localArgs);
	}
	
	// create entries in the mapping
	for (int i = 0; 
		ThreadLocalArgumentInstances[i] != &ThreadLocalArgument::ptrThreadDescriptorArray; ++i) {
		
		VectorizedInstruction packedThreadLocal;
		for (int tid = 0; tid < pass->warpSize; tid++) {
			packedThreadLocal.replicated.push_back(
				schedulerEntryBlock.threadLocalArguments[tid].*(ThreadLocalArgumentInstances[i]));
		}
		vectorizedInstructionMap[packedThreadLocal.replicated[0]] = packedThreadLocal;
	}
}

void analysis::LLVMUniformVectorization::Translation::_replicateInstruction(llvm::Instruction *inst) {
	reportE(REPORT_VECTORIZING, "  _replicateInstruction(" << String(inst) << ")");
	
	assert(schedulerEntryBlock.threadLocalArguments.size() == (size_t)pass->warpSize);
	
	typedef std::vector< std::pair< int, llvm::Instruction * ThreadLocalArgument::*> > OperandVector;
	OperandVector operands;
	VectorizedInstruction vectorized;
	
	int operandIndex = 0;
	for (llvm::User::op_iterator op_it = inst->op_begin(); op_it != inst->op_end(); ++op_it, ++operandIndex) {
		if (llvm::Instruction *opInst = llvm::dyn_cast<llvm::Instruction>(*op_it)) {
			for (int l = 0; ThreadLocalArgumentInstances[l] != &ThreadLocalArgument::ptrThreadDescriptorArray; l++) {
				if (opInst == (schedulerEntryBlock.threadLocalArguments[0].*(ThreadLocalArgumentInstances[l]))) {

					operands.push_back(std::pair<int, llvm::Instruction * ThreadLocalArgument::*>(
						operandIndex, ThreadLocalArgumentInstances[l]));
				}
			}
		}
	}
	
	reportE(REPORT_VECTORIZING, "   packed operands");
	
	bool updateName = (!(llvm::StoreInst::classof(inst) || inst->getType()->isVoidTy()));
	std::string baseName = inst->getName().str() + ".t";
	if (updateName) {
		std::string name = baseName + boost::lexical_cast<std::string, int>(0);
		//inst->setName(name);
	}
	vectorized.replicated.push_back(inst);
	
	reportE(REPORT_VECTORIZING, "   updated name");

	llvm::Instruction *insertAfter = inst;
	
	for (int tid = 1; tid < pass->warpSize; tid++) {
		std::string name = baseName + boost::lexical_cast<std::string, int>(tid);
		llvm::Instruction *clone = inst->clone();
		
		if (updateName) {
			clone->setName(name);
		}
		
		for (OperandVector::const_iterator op_it = operands.begin(); op_it != operands.end(); ++op_it) {
			llvm::Instruction *operand = (schedulerEntryBlock.threadLocalArguments[tid].*(op_it->second));
			clone->setOperand(op_it->first, operand);
		}
		
		clone->insertAfter(insertAfter);
		insertAfter = clone;
		vectorized.replicated.push_back(clone);
	}
	vectorizedInstructionMap[inst] = vectorized;
}

void analysis::LLVMUniformVectorization::Translation::_resolveDependencies() {
	report("   _resolveDependencies()");
	
	for (VectorizedInstructionMap::iterator inst_it = vectorizedInstructionMap.begin();
		inst_it != vectorizedInstructionMap.end(); ++inst_it) {
		
		for (unsigned int i = 0; i < inst_it->first->getNumOperands(); i++) {
			if (llvm::Instruction *opInst = 
				llvm::dyn_cast<llvm::Instruction>(inst_it->first->getOperand(i))) {		
				VectorizedInstructionMap::iterator vecOp_it = vectorizedInstructionMap.find(opInst);
				if (vecOp_it != vectorizedInstructionMap.end()) {
					for (int tid = 1; tid < pass->warpSize; tid++) {
						inst_it->second.replicated[tid]->setOperand(i, vecOp_it->second.replicated[tid]);
					}
				}
				else {
					reportE(REPORT_VECTORIZING, "      operand " << i << " not in mapping: " << String(opInst));
				}
			}
		}
	}		
}

/*!

*/
void analysis::LLVMUniformVectorization::Translation::_divergenceHandling() {
	typedef analysis::KernelPartitioningPass::DivergentBranch DivergentBranch;
	typedef analysis::KernelPartitioningPass::DivergentBranchVector DivergentBranchVector;
	
	report("_divergenceHandling()");
	
	for (DivergentBranchVector::const_iterator divergence_it = subkernel->divergentBranches.begin();
	
		divergence_it != subkernel->divergentBranches.end(); ++divergence_it) {
		_updateDivergentBlock(*divergence_it, subkernel->outEdges.at(divergence_it->outEdgeIndex));
	}
	
	report("_divergenceHandling() returning");
}

/*!
	Given a divergent branch entry and a reference to the corresponding out edge,
	transforms control instructions to point to the out edge according to the type
	of divergent branch.
*/
void analysis::LLVMUniformVectorization::Translation::_updateDivergentBlock(
	const analysis::KernelPartitioningPass::DivergentBranch &divergence, 
	const analysis::KernelPartitioningPass::ExternalEdge &outEdge) {

	reportE(REPORT_VECTORIZING, "  _updateDivergentBlock(" << divergence.frontierBlock->label << ")");
	reportE(REPORT_VECTORIZING, "    handler: " << outEdge.handler->label);
	
	typedef analysis::KernelPartitioningPass::DivergentBranch DivergentBranch; 
	
	llvm::BasicBlock *llvmBlock = ocelotToLlvmBlockMap[divergence.frontierBlock];
	llvm::BasicBlock *handler = ocelotToLlvmBlockMap[outEdge.handler];
		
	assert(llvmBlock && "failed to obtain frontier block from Ocelot->LLVM mapping");
	assert(handler && "failed to obtain handler block from Ocelot->LLVM mapping");
	
	llvm::TerminatorInst *terminator = llvmBlock->getTerminator();
	
	report("   obtained llvm block for handler and frontier");
	
	// remove phi instructions in divergence handler - should only have one predecessor
	std::vector<llvm::PHINode *> killWithFire;
	for (llvm::BasicBlock::iterator inst_it = handler->begin(); inst_it != handler->end(); ++inst_it) {
		if (llvm::PHINode *phiNode = llvm::dyn_cast<llvm::PHINode>(&*inst_it)) {
			for (unsigned int i = 0; i < phiNode->getNumIncomingValues(); i++) {
				phiNode->setIncomingBlock(i, llvmBlock);
			}
			if (phiNode->getNumIncomingValues() == 1) {
				if (llvm::Constant *constant = llvm::dyn_cast<llvm::Constant>(phiNode->getIncomingValue(0))) {
					phiNode->replaceAllUsesWith(constant);
					killWithFire.push_back(phiNode);
				}
			}
		}
	}
	for (auto kill_it = killWithFire.begin(); kill_it != killWithFire.end(); ++kill_it) {
		(*kill_it)->eraseFromParent();
	}
	
	if (llvm::BranchInst *branchInst = llvm::dyn_cast<llvm::BranchInst>(terminator)) {
		if (branchInst->isConditional() && llvm::Instruction::classof(branchInst->getCondition())) {
		
			llvm::Instruction *condition = llvm::dyn_cast<llvm::Instruction>(branchInst->getCondition());
			VectorizedInstructionMap::iterator vec_it = vectorizedInstructionMap.find(condition);
			if (vec_it != vectorizedInstructionMap.end()) {
				
				reportE(REPORT_VECTORIZING, "  vectorized condition instruction (" 
					<< condition->getName().str() << ")");
				
				llvm::BasicBlock *targetTrue = branchInst->getSuccessor(0);
				llvm::BasicBlock *targetFalse = branchInst->getSuccessor(1);
				
				branchInst->eraseFromParent();
				
				llvm::Type *intTy = getTyInt(32);
				llvm::Instruction *condition = new llvm::ZExtInst(vec_it->second.replicated[0],	
					intTy, "cond", llvmBlock);
				
				for (size_t t = 1; t < vec_it->second.replicated.size(); ++t) {
					llvm::Instruction *ext = new llvm::ZExtInst(vec_it->second.replicated[t], intTy, 
						"cond", llvmBlock);
					condition = llvm::BinaryOperator::Create(llvm::Instruction::Add, condition,
						ext, "cmpws", llvmBlock);
				}
				
				// find select instruction in handler
				llvm::SelectInst *selectInst = 0;
				for (llvm::BasicBlock::iterator inst_it = handler->begin(); 
					!selectInst && inst_it != handler->end(); ++inst_it ) {
					
					selectInst = llvm::dyn_cast<llvm::SelectInst>(&*inst_it);
				}
				if (selectInst) {
					VectorizedInstructionMap::iterator vec_select_it = vectorizedInstructionMap.find(selectInst);
					if (vec_select_it != vectorizedInstructionMap.end()) {
						reportE(REPORT_VECTORIZING, " updating select instruction");
						for (size_t t = 0; t < vec_select_it->second.replicated.size(); ++t) {
							llvm::dyn_cast<llvm::SelectInst>(vec_select_it->second.replicated[t])->setOperand(
								0, vec_it->second.replicated[t]);
						}
					}
				}
				
				reportE(REPORT_VECTORIZING, "    warp-wide reduction of condition yielding: " 
					<< String(condition));
		
				llvm::TerminatorInst *terminatorInst = 0;
				
				if ((divergence.flags & DivergentBranch::Diverge_true_internal) &&
					(divergence.flags & DivergentBranch::Diverge_false_internal) && 
					!(divergence.flags & (~(DivergentBranch::Diverge_true_internal | 
						DivergentBranch::Diverge_false_internal)))) {
				
					// both branch edges are internal
					assert(handler && targetTrue && targetFalse);

					llvm::SwitchInst *switchInst = llvm::SwitchInst::Create(condition, handler, 2, llvmBlock);
					switchInst->addCase(getConstInt32(0), targetFalse);
					switchInst->addCase(getConstInt32(pass->warpSize), targetTrue);
					
					terminatorInst = switchInst;
				}
				else if ((divergence.flags & DivergentBranch::Diverge_true_external) && 
					(divergence.flags & DivergentBranch::Diverge_false_internal) && 
					!(divergence.flags & (~(DivergentBranch::Diverge_true_external | 
						DivergentBranch::Diverge_false_internal)))) {
					
					// true branch edge is external
					// false branch edge is internal
					targetTrue = handler;
					
					assert(targetTrue && targetFalse && "Failed to detect control instructions");
					assert(condition && "failed to compute branch condition");
					
					// take true branch unless predicate conditions equal zero
					llvm::CmpInst *cmpInst = new llvm::ICmpInst(*llvmBlock, llvm::ICmpInst::ICMP_EQ, condition, 
						getConstInt32(0), llvm::Twine("convergent"));
					llvm::BranchInst *newBranchInst = llvm::BranchInst::Create(targetFalse, targetTrue, 
						cmpInst, llvmBlock);
					
					terminatorInst = newBranchInst;
				}
				else if ((divergence.flags & DivergentBranch::Diverge_false_external) && 
					(divergence.flags & DivergentBranch::Diverge_true_internal) && 
					!(divergence.flags & (~(DivergentBranch::Diverge_false_external | 
						DivergentBranch::Diverge_true_internal)))) {
					
					// false branch edge is external
					// true branch edge is internal
					
					targetFalse = handler;
					assert(targetTrue && targetFalse);
					
					assert(condition && "failed to compute branch condition");
					
					// take true branch if conditions equal warp size
					llvm::ICmpInst *cmpInst = new llvm::ICmpInst(*llvmBlock, llvm::ICmpInst::ICMP_EQ, condition, 
						getConstInt32(pass->warpSize), llvm::Twine("convergent"));
					
					llvm::BranchInst *newBranchInst = llvm::BranchInst::Create(targetTrue, targetFalse, 
						cmpInst, llvmBlock);
					
					terminatorInst = newBranchInst;
				}
				else if ((divergence.flags & DivergentBranch::Diverge_true_external) && 
					(divergence.flags & DivergentBranch::Diverge_false_external) &&
					!(divergence.flags & (~(DivergentBranch::Diverge_true_external | 
						DivergentBranch::Diverge_false_external)))) {
					
					// both branch edges are external
					assert(handler);
					
					llvm::BranchInst *newBranchInst = llvm::BranchInst::Create(handler,	llvmBlock);
					terminatorInst = newBranchInst;
				}
				else {
					// unexpected divergent branch configuration
					assert(0 && "unexpected divergent branch type");
				}
				assert(terminatorInst && llvmBlock->getTerminator() == terminatorInst);
			}
			else {
				assert(0 && "failed to find replicated branch condition");
			}
		}
	}
	else {
		// ignore other control flow for now
		assert(0 && "unexpected control flow type");
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

llvm::Instruction *analysis::LLVMUniformVectorization::Translation::_getVectorizedInsertPoint(
	const VectorizedInstruction &vec) {
	
	return vec.replicated[pass->warpSize - 1];
}

/*! \brief given an instruction from the scalar set, get a set of scalar values that are 
	either replicated scalar instructions from the vectorized set or extracted vector elements */
analysis::LLVMUniformVectorization::InstructionVector 
	analysis::LLVMUniformVectorization::Translation::getInstructionAsReplicated(
		llvm::Value *inst, llvm::Instruction *before) {
	
	reportE(REPORT_VECTORIZING, "  getting instruction " << inst 
		<< " as replicated - inserting before " << before);
	assert(0 && "not yet implemented");
}

/*! \brief given an instruction from the scalar set, get a vector from the vectorized set that
	is either a promoted-to-vector instruction or a set of scalar values packed into a vector*/
llvm::Instruction *
	analysis::LLVMUniformVectorization::Translation::getInstructionAsVectorized(
		llvm::Value *value, llvm::Instruction *before) {
	
	reportE(REPORT_VECTORIZING, "_getInstructionAsVectorized(" << String(value) 
		<< ") before " << String(before));
	
	llvm::Instruction *vectorizedInstruction = 0;
	
	if (llvm::Instruction *instruction = llvm::dyn_cast<llvm::Instruction>(value)) {
		VectorizedInstructionMap::iterator vec_inst = vectorizedInstructionMap.find(instruction);
		
		if (vec_inst != vectorizedInstructionMap.end()) {
			if (vec_inst->second.vector) {
				vectorizedInstruction = vec_inst->second.vector;
			}
			else {
				vectorizedInstruction = _vectorize(vec_inst);
			}
		}
		else if (llvm::ExtractElementInst *extractInst = 
			llvm::dyn_cast<llvm::ExtractElementInst>(instruction)) {
			
			vectorizedInstruction = llvm::dyn_cast<llvm::Instruction>(extractInst->getVectorOperand());
		}
		else {
			reportE(REPORT_VECTORIZING, "  Instruction not in mapping: " << String(instruction));
			assert(0 && "asdf");
		}
	}
	else if (llvm::Constant *constant = llvm::dyn_cast<llvm::Constant>(value)) {
		llvm::VectorType *vecType = llvm::VectorType::get(value->getType(), pass->warpSize);
		llvm::Value *vectorValue = llvm::UndefValue::get(vecType);
		for (int tid = 0; tid < pass->warpSize; tid++) {
			vectorValue = llvm::InsertElementInst::Create(vectorValue, 
				constant, getConstInt32(tid), "", before);
		}
		vectorizedInstruction = static_cast<llvm::Instruction*>(vectorValue);
	}

	assert(vectorizedInstruction && "failed to vectorize instruction");
	return vectorizedInstruction;
}

void analysis::LLVMUniformVectorization::Translation::_vectorizeReplicated() {
	report("     _vectorizeReplicated()");
	for (VectorizedInstructionMap::iterator inst_it = vectorizedInstructionMap.begin();
		inst_it != vectorizedInstructionMap.end(); ++inst_it) {		
		if (inst_it->second.isVectorizable()) {
			_vectorize(inst_it);
		}
	}
}

llvm::Instruction * analysis::LLVMUniformVectorization::Translation::_vectorize(
	VectorizedInstructionMap::iterator &vec_it) {
	
	reportE(REPORT_VECTORIZING, "  vectorize()");
	
	llvm::Instruction *vectorized = vec_it->second.vector;
	if (!vectorized) {
		if (vec_it->second.isVectorizable()) {
			if (llvm::BinaryOperator *binOp = llvm::dyn_cast<llvm::BinaryOperator>(vec_it->first)) {
				vectorized = _vectorizeBinaryOperator(binOp, vec_it);
			}
			else if (llvm::CallInst *callInst = llvm::dyn_cast<llvm::CallInst>(vec_it->first)) {
				vectorized = _vectorizeCall(callInst, vec_it);
			}
			else if (llvm::dyn_cast<llvm::LoadInst>(vec_it->first) || 
				llvm::dyn_cast<llvm::StoreInst>(vec_it->first)) {
				
				vectorized = _vectorizeAffineMemory(vec_it->first, vec_it);
			}
			else if (llvm::SIToFPInst::classof(vec_it->first) || llvm::FPToSIInst::classof(vec_it->first)) {
			
				vectorized = _vectorizeFPIntConversion(vec_it->first, vec_it);
			}
			else {
				assert(0 && "unhandled vectorizable instruction");	
			}
			if (vectorized) {
				InstructionVector extracted;
				
				if (!vectorized->getType()->isVoidTy()) {
					std::string vectorName = vec_it->first->getName().str() + ".extracted.t";
					for (int tid = 0; tid < pass->warpSize; tid++) {
						std::string name = vectorName + boost::lexical_cast<std::string,int>(tid);
					
						llvm::Instruction *element = llvm::ExtractElementInst::Create(vec_it->second.vector, 
							getConstInt32(tid), name, vectorized);
						element->removeFromParent();
						element->insertAfter(vectorized);
						extracted.push_back(element);
					}
					for (int tid = 0; tid < pass->warpSize; tid++) {
						vec_it->second.replicated[tid]->replaceAllUsesWith(extracted[tid]);
						vec_it->second.replicated[tid]->eraseFromParent();
					}
					vec_it->second.replicated = extracted;
				}
				else {
					for (int tid = 0; tid < pass->warpSize; tid++) {
						vec_it->second.replicated[tid]->eraseFromParent();
					}
					vec_it->second.replicated = extracted;
				}
			}
		}
		else if (vec_it->second.isPackable()) {
			vectorized = _vectorizeUnvectorizable(vec_it->first, vec_it);
			vec_it->second.vector = vectorized;
		}
	}
	return vectorized;
}

llvm::Instruction * analysis::LLVMUniformVectorization::Translation::_vectorizeUnvectorizable(
	llvm::Instruction *inst, VectorizedInstructionMap::iterator &vec_it) {
	
	reportE(REPORT_VECTORIZING, "  vectorizeUnvectorizable: " << String(inst));
	reportE(REPORT_VECTORIZING, "     replicated:");
	
	for (int tid = 0; tid < pass->warpSize; tid++) {
		reportE(REPORT_VECTORIZING, "      [tid: " << tid << "]: " 
			<< String(vec_it->second.replicated[tid]));
	}
	
	// pack replicated instructions	
	llvm::Value *lastInserted = llvm::UndefValue::get(llvm::VectorType::get(
		inst->getType(), pass->warpSize));
	llvm::Instruction *insertInst = 0;
	
	bool moveAfter = true;
	llvm::Instruction *insertPoint = _getVectorizedInsertPoint(vec_it->second);
	if (llvm::PHINode::classof(insertPoint)) {
		insertPoint = insertPoint->getParent()->getFirstNonPHI();
		moveAfter = false;
	}
	
	reportE(REPORT_VECTORIZING, "    insert point: " << String(insertPoint));
	
	for (int tid = 0; tid < pass->warpSize; tid++) {
		llvm::ConstantInt *idx = getConstInt32(tid);
		llvm::Instruction *element = vec_it->second.replicated[tid];
		std::stringstream ss;
		ss << "insert." << element->getName().str() << ".vec";
		
		insertInst = llvm::InsertElementInst::Create(lastInserted, element, 
			idx, ss.str(), insertPoint);

		if (tid || moveAfter) { 
			insertInst->removeFromParent();
			insertInst->insertAfter(static_cast<llvm::Instruction*>(insertPoint));
		}
		
		insertPoint = insertInst;
		lastInserted = insertInst;
	}
	
	reportE(REPORT_VECTORIZING, "   packed: " << String(insertInst));
	
	return insertInst;
}

llvm::Instruction * analysis::LLVMUniformVectorization::Translation::_vectorizeBinaryOperator(
	llvm::BinaryOperator *inst, VectorizedInstructionMap::iterator &vec_it) {

	reportE(REPORT_VECTORIZING, "  vectorizeBinaryOperator(): " << String(inst));

	llvm::Instruction *op0 = getInstructionAsVectorized(vec_it->first->getOperand(0), inst);
	llvm::Instruction *op1 = getInstructionAsVectorized(vec_it->first->getOperand(1), inst);
	
	std::stringstream ss;
	ss << inst->getName().str() << ".vec";

	vec_it->second.vector = llvm::BinaryOperator::Create(inst->getOpcode(), op0, op1, ss.str(), inst);
	vec_it->second.vector->removeFromParent();
	vec_it->second.vector->insertAfter(inst);
	
	return vec_it->second.vector;
}
			
llvm::Instruction * analysis::LLVMUniformVectorization::Translation::_vectorizeCall(
	llvm::CallInst *callInst, VectorizedInstructionMap::iterator &vec_it) {
	
	llvm::Instruction *before = 0;
	
	// it's a call instruction
	std::string calleeName = callInst->getCalledFunction()->getName().str();

	reportE(REPORT_VECTORIZING, " call instruction: " << calleeName);

	assert(hydrazine::isPowerOfTwo(pass->warpSize) && 
		"warp size must be power of 2 for vectorizing function calls");

	const char *floatSuffixes[] = {
		"f32", "v2f32", "v4f32", "v8f32", "v16f32", "v32f32", "v64f32", "v128f32", "v256f32", 
		"v512f32", 0
	};
	const char *str[] = {
		"__ocelot_sqrtf", "llvm.sqrt",
		"__ocelot_sinf", "llvm.sin",
		"__ocelot_cosf", "llvm.cos",
		"llvm.sqrt.f32", "llvm.sqrt",
		"llvm.sin.f32", "llvm.sin",
		"llvm.cos.f32f", "llvm.cos",
		0, 0
	};
	llvm::Function *funcIntrinsic = 0;
	for (int n = 0; str[n]; n+=2) {
		if (calleeName == str[n]) {
			int s = 0;
			for (; floatSuffixes[s]; s++) {
				if ((1 << s) == pass->warpSize) {
					break;
				}
			}
			assert((1 << s) == pass->warpSize);
			std::string destName = std::string(str[n+1]) + "." + floatSuffixes[s];
			funcIntrinsic = function->getParent()->getFunction(destName);
			if (!funcIntrinsic) {
				reportE(REPORT_VECTORIZING, "creating intrinsic type " << calleeName);
				llvm::VectorType *vecType = llvm::VectorType::get(callInst->getType(), pass->warpSize);
				std::vector< llvm::Type *> args;
				args.push_back(vecType);
				llvm::FunctionType *funcType = llvm::FunctionType::get(vecType, args, false);
				funcIntrinsic = llvm::Function::Create(funcType, 
					llvm::GlobalValue::ExternalLinkage, destName, function->getParent());
			}
			else {
				reportE(REPORT_VECTORIZING, "using existing intrinsic definition ");
			}
			assert(funcIntrinsic && "failed to get identified intrinsic");
			break;
		}
	}
	assert(funcIntrinsic && "failed to identify intrinsic");
	
	std::vector< llvm::Value *> args;
	for (unsigned int op = 0; op < callInst->getNumOperands() - 1; ++op) {
		args.push_back(getInstructionAsVectorized(callInst->getOperand(op), before));
	}

	std::string name = callInst->getName().str() + ".vec";
	llvm::CallInst *vecCallInst = llvm::CallInst::Create(funcIntrinsic, args, name, before);
	vec_it->second.vector = vecCallInst;
	
	return vecCallInst;
}

llvm::Instruction * analysis::LLVMUniformVectorization::Translation::_vectorizeFPIntConversion(
	llvm::Instruction *inst, VectorizedInstructionMap::iterator &vec_it) {
	
	reportE(REPORT_VECTORIZING, "  vectorizeFPIntConversion(): " << String(inst));

	llvm::CastInst *castInst = llvm::dyn_cast<llvm::CastInst>(inst);
	llvm::Instruction *op0 = getInstructionAsVectorized(castInst->getOperand(0), inst);
	llvm::VectorType *vecDestTy = llvm::VectorType::get(castInst->getDestTy(), pass->warpSize);
		
	std::stringstream ss;
	ss << inst->getName().str() << ".vec";

	vec_it->second.vector = llvm::CastInst::Create(castInst->getOpcode(), op0, vecDestTy, ss.str(), inst);
	
	vec_it->second.vector->removeFromParent();
	vec_it->second.vector->insertAfter(inst);
	
	return vec_it->second.vector;
}

//////////////////////////////////////////////////////////////////////////////////////////////////


bool analysis::LLVMUniformVectorization::VectorizedInstruction::isPackable() const {
	return llvm::VectorType::isValidElementType(replicated[0]->getType());
}

bool analysis::LLVMUniformVectorization::VectorizedInstruction::isVectorizable() const {
	
	llvm::Instruction *base = replicated[0];
	
	reportE(REPORT_VECTORIZING, "  isVectorizable(" << String(base) << ")");
	
	// vectorizable instructions if marked as affine
	if (flags == Thread_affine) {
		if (llvm::StoreInst *storeInst = llvm::dyn_cast<llvm::StoreInst>(base)) {
			llvm::Type *valueType = storeInst->getValueOperand()->getType();
			if (valueType->isFloatTy() || valueType->isIntegerTy(32) || valueType->isDoubleTy()) {		
				reportE(REPORT_VECTORIZING, "    vectorizable");
				return true;
			}
		}
		else if (llvm::LoadInst *loadInst = llvm::dyn_cast<llvm::LoadInst>(base)) {
			llvm::Type *valueType = loadInst->getType();
			if (valueType->isFloatTy() || valueType->isIntegerTy(32) || valueType->isDoubleTy()) {		
				reportE(REPORT_VECTORIZING, "    vectorizable");
				return true;
			}
		}
	}
	
	// vectorizable binary operators and call instructions
	if (base->getType()->isFloatTy() ||
		base->getType()->isDoubleTy() ||
		base->getType()->isIntegerTy(32)) {
		
		if (base->isBinaryOp() || llvm::FPToSIInst::classof(base) || llvm::SIToFPInst::classof(base) || 
			llvm::CallInst::classof(base)) {
			
			reportE(REPORT_VECTORIZING, "    vectorizable");
			return true;	
		}
	}
	
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::_affineMemoryAccesses() {
	report("_affineMemoryAccesses()");
	
	AffineInstructionSet affineInstructions(function, schedulerEntryBlock.threadLocalArguments.at(0));
	
	for (VectorizedInstructionMap::iterator vec_it = vectorizedInstructionMap.begin();
		vec_it != vectorizedInstructionMap.end(); ++vec_it) {
	
		if (llvm::StoreInst *storeInst = llvm::dyn_cast<llvm::StoreInst>(vec_it->first)) {
			report(" querying store instruction: " << String(storeInst));
			
			if (affineInstructions.isThreadInvariant(storeInst->getPointerOperand())) {
				report("  " << String(vec_it->first) << " is thread-invariant");
				vec_it->second.flags = VectorizedInstruction::Thread_invariant;
			}
			else if (affineInstructions.isAffine(storeInst->getPointerOperand())) {
				report("  " << String(vec_it->first) << " is affine");
				vec_it->second.flags = VectorizedInstruction::Thread_affine;
			}
		}
		else if (llvm::LoadInst *loadInst = llvm::dyn_cast<llvm::LoadInst>(vec_it->first)) {
			report(" querying load instruction: " << String(loadInst));

			if (affineInstructions.isThreadInvariant(loadInst->getPointerOperand())) {
				report("  " << String(vec_it->first) << " is thread-invariant");
				vec_it->second.flags = VectorizedInstruction::Thread_invariant;
			}
			else if (affineInstructions.isAffine(loadInst->getPointerOperand())) {
				report("  " << String(vec_it->first) << " is affine");
				vec_it->second.flags = VectorizedInstruction::Thread_affine;
			}
		}
	}

	report("_affineMemoryAccesses() returning");
}

static llvm::Value *getPointerOperand(llvm::Instruction *inst) {
	llvm::Value *ptr = 0;
	if (llvm::StoreInst *store = llvm::dyn_cast<llvm::StoreInst>(inst)) {
		ptr = store->getPointerOperand();
	}
	else if (llvm::LoadInst *load = llvm::dyn_cast<llvm::LoadInst>(inst)) {
		ptr = load->getPointerOperand();
	}
	return ptr;
}

llvm::Instruction * analysis::LLVMUniformVectorization::Translation::_vectorizeAffineMemory(
	llvm::Instruction *inst, VectorizedInstructionMap::iterator &vec_it) {

	reportE(REPORT_VECTORIZING, "_vectorizeAffineMemory(" << String(inst) << ")");

	llvm::Value *ptrOperand = getPointerOperand(vec_it->first);
	assert(ptrOperand && "Vectorizing affine memory operation must be LoadInst or StoreInst");
	
	llvm::Instruction *before = vec_it->first;
	
	std::string ptrName = "vec." + ptrOperand->getName().str();
	std::string name = "affine." + vec_it->first->getName().str();
	
	llvm::VectorType *vecType = llvm::VectorType::get(
		llvm::dyn_cast<llvm::PointerType>(ptrOperand->getType())->getElementType(), pass->warpSize);
	
	llvm::PointerType *vecPtrType = llvm::PointerType::get(vecType, 0);
	llvm::Instruction *ptrCast = llvm::CastInst::CreatePointerCast(ptrOperand, 
		vecPtrType, ptrName, before);
	
	if (llvm::dyn_cast<llvm::LoadInst>(vec_it->first)) {
		llvm::LoadInst *vectorized = new llvm::LoadInst(ptrCast, name, before);
		vec_it->second.vector = vectorized;
	}
	else if (llvm::StoreInst *storeInst = llvm::dyn_cast<llvm::StoreInst>(vec_it->first)) {
		llvm::Instruction *vectorizedValueOperand = getInstructionAsVectorized(
			storeInst->getValueOperand(), inst);
		llvm::StoreInst *storeInst = new llvm::StoreInst(vectorizedValueOperand, ptrCast, before);
		vec_it->second.vector = storeInst;
	}
	assert(vec_it->second.vector && "Failed to construct vectorized load or store");
	
	vec_it->second.vector->removeFromParent();
	vec_it->second.vector->insertAfter(inst);
	return vec_it->second.vector;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::_finalizeTranslation() {
	report("_finalizeTranslation()");
	_eliminateUnusedVectorPacking();
}

void analysis::LLVMUniformVectorization::Translation::_eliminateUnusedVectorPacking() {
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		for (llvm::BasicBlock::iterator inst_it = bb_it->begin(); inst_it != bb_it->end(); ++inst_it) {
			if (inst_it->use_empty() && (llvm::dyn_cast<llvm::ExtractElementInst>(&*inst_it) ||
				llvm::dyn_cast<llvm::InsertElementInst>(&*inst_it))) {
				inst_it->eraseFromParent();
				inst_it = bb_it->begin();
			}
		}
	}
}

/*!
	\brief 
*/
void analysis::LLVMUniformVectorization::Translation::_createBackEdges() {
	report("_createBackEdges()");
	
	report("  creating exit branch edges");
	
	schedulerEntryBlock.warpLoopWhile = llvm::BasicBlock::Create(context(), "WarpLoopWhile", 
		function, 0);
		
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		if (&*bb_it == schedulerEntryBlock.warpLoopWhile) { continue; }
		report("  block: " << bb_it->getName().str());
		if (llvm::ReturnInst *retInst = llvm::dyn_cast<llvm::ReturnInst>(bb_it->getTerminator())) {
			llvm::BranchInst *branchInst = llvm::BranchInst::Create(schedulerEntryBlock.warpLoopWhile, retInst);
			retInst->eraseFromParent();
			assert(branchInst && "Failed to create branch instruction");
		}
	}
	
	// update previous exit blocks to branch to warpLoopWhile block instead	
	schedulerEntryBlock.warpLoopExit = llvm::BasicBlock::Create(context(), "WarpLoopExit", function, 0);
	
	report("  creating new entry block");
	
	// create an additional entry block, counter, and scheduler
	schedulerEntryBlock.warpLoopDo = llvm::BasicBlock::Create(context(), "WarpLoopEntry", 
		function, & function->getEntryBlock());
	
	report("  creating loop termination block");

	llvm::CastInst *ptrWarpCount = llvm::CastInst::CreatePointerCast(
		schedulerEntryBlock.threadLocalArguments.at(0).metadataPointer,
		llvm::PointerType::get(getTyInt(32), 0), "ptrWarpCount", schedulerEntryBlock.warpLoopDo);
	ptrWarpCount->removeFromParent();
	ptrWarpCount->insertAfter(schedulerEntryBlock.threadLocalArguments.at(0).metadataPointer);
	llvm::Instruction *numThreads = new llvm::LoadInst(ptrWarpCount, "warpCount", 
		schedulerEntryBlock.warpLoopDo);
	numThreads->removeFromParent();
	numThreads->insertAfter(ptrWarpCount);
	
	llvm::BranchInst *entryBra = llvm::BranchInst::Create(schedulerEntryBlock.block, 
		schedulerEntryBlock.warpLoopDo);
	assert(entryBra && "failed to create entryBra");
	
	llvm::PHINode *entryPhi = llvm::PHINode::Create(getTyInt(32), 2, "warpIterationIdx", 
		&schedulerEntryBlock.block->front());
	entryPhi->addIncoming(getConstInt32(0), schedulerEntryBlock.warpLoopDo);
		
	report("  incrementing warp counter");
		
	llvm::Instruction *incrementWarpIdx = llvm::BinaryOperator::CreateNSWAdd(entryPhi,
		getConstInt32(1), "incrementWarpIdx", schedulerEntryBlock.warpLoopWhile);
	entryPhi->addIncoming(incrementWarpIdx, schedulerEntryBlock.warpLoopWhile);
	
	llvm::Instruction *cmpResult = new llvm::ICmpInst(*schedulerEntryBlock.warpLoopWhile,
		llvm::ICmpInst::ICMP_EQ, incrementWarpIdx, numThreads, "eqWarpCount");
	
	llvm::BranchInst *backEdgeBra = llvm::BranchInst::Create(schedulerEntryBlock.warpLoopExit, 
		schedulerEntryBlock.block, cmpResult, schedulerEntryBlock.warpLoopWhile);
	assert(backEdgeBra && "failed to create back edge");
		
	llvm::ReturnInst *returnInst = llvm::ReturnInst::Create(context(), 0, 
		schedulerEntryBlock.warpLoopExit);
	assert(returnInst && "failed to create return instruction");
	
	report("  done");
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void walkCallStack() {
	void *entries[32] = {0};
	report("walkCallStack()");
	int addresses = backtrace(entries, 32);
	char **symbols = backtrace_symbols(entries, addresses);
	for (int i = 0; i < addresses; i++ ){
		std::cout << "    [" << i << "]: " << symbols[i] << std::endl;
	}
	report("  done");
}

/*!

*/
extern "C" void _ocelot_debug_report(size_t index, size_t value, size_t value1, int type, size_t vptr) {
	bool printNameOnly = false;
	
	bool trustPointers = true;

	std::cout << "[debug " << type << "]";
	
	switch (type) {
		case 0: std::cout << " value[" << index << "] = " << value; break;
		case 1: std::cout << " store(" << index << "): [" << (void *)value << "] = " << value1;  break;
		case 2: std::cout << " store(" << index << "): [" << (void *)value << "] = <type unknown>"; break;
		case 3: {
			std::cout << " returning (" << index << ")\n";
		}
		break;
		case 4: std::cout << " store(" << index << "): [" << (void *)value << "] = " <<
			hydrazine::bit_cast<double>(value1) << " <float>";  break;
		case 5: {
			if (true) {
				llvm::Type *llvmType = hydrazine::bit_cast<llvm::Type *>(value1);
				std::cout << " store(" << index << "): [" << (void *)value << "] (type: " << String(llvmType) << ")";
			}
			else {
				std::cout << " store(" << index << "): [" << (void *)value << "]";
			}
		}
		break;
		case 6: {
			std::cout << " entering (" << index << ")\n";
		}
		break;
		case 7: {
			std::cout << " block(" << index << ")\n";
			printNameOnly = true;
		}
		break;
		case 8: {	// vector store
			float *vecPtr = (float *)value;
			std::cout << " store(" << index << "): [" << (void *)value << "] = < ";
			for (size_t i = 0; i < value1; i++) {
				std::cout << (i ? ", " : "") << vecPtr[i];
			}
			std::cout << " >";
		}break;
		case 9: {
			std::cout << " load(" << index << "): " << value1 << " = [" << (void *)value << "]";
		} break;
		case 10: {
			std::cout << " load(" << index << "): " << hydrazine::bit_cast<double>(value1) << " = [" 
				<< (void *)value << "]   <float>";
		} break;
		case 11: {
			std::cout << " load(" << index << "): " << (void *)value1 << " = [" << (void *)value << "]";
		} break;
		default:
			std::cout << " unknown(" << index << ", " << value << ", " << value1 << ", " << type << ")";
	}
	if (vptr && trustPointers) {
		llvm::Value *value = (llvm::Value *)(void *)vptr;
		if (printNameOnly) {
			std::cout << "  block: " << value->getName().str() << std::endl;
		}
		else {
			std::cout << "  value: " << String(value);
		}
	}
	std::cout << std::endl;
}


void analysis::LLVMUniformVectorization::Translation::_debugReporting() {	
	report("_debugReporting()");
	
	std::vector< llvm::Type *> params;
	params.push_back(getTyInt(64));
	params.push_back(getTyInt(64));
	params.push_back(getTyInt(64));
	params.push_back(getTyInt(32));
	params.push_back(getTyInt(64));
	llvm::FunctionType *funcType = 
		llvm::FunctionType::get(llvm::Type::getVoidTy(context()), 
			llvm::ArrayRef<llvm::Type*>(params), false);
	
	llvm::Constant *func = 
		function->getParent()->getOrInsertFunction("_ocelot_debug_report", funcType);
	
	assert(func && "unable to insert function");
	
	size_t index = 0;
	
	report("  store instructions");
	std::vector< llvm::BasicBlock *> basicBlocks;
	std::vector< llvm::StoreInst *> storeInstructions;
	std::vector< llvm::LoadInst *> loadInstructions;
	std::vector< llvm::ReturnInst *> returnInstructions;
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
	
		if (DEBUG_REPORT_BLOCKS) {
			basicBlocks.push_back(&*bb_it);
		}
	
		for (llvm::BasicBlock::iterator inst_it = bb_it->begin(); inst_it != bb_it->end(); ++inst_it) {
			if (llvm::StoreInst *storeInst = llvm::dyn_cast<llvm::StoreInst>(&*inst_it)) {
				if (DEBUG_REPORT_STORES) {
					storeInstructions.push_back(storeInst);
				}
			}
			else if (auto retInst = llvm::dyn_cast<llvm::ReturnInst>(&*inst_it)) {
				if (DEBUG_REPORT_RETURNS) {
					returnInstructions.push_back(retInst);
				}
			}
			else if (llvm::LoadInst *loadInst = llvm::dyn_cast<llvm::LoadInst>(&*inst_it)) {
				if (DEBUG_REPORT_LOADS){
					loadInstructions.push_back(loadInst);
				}
			}
		}
	}
	
	{
		std::vector< llvm::Value *> args;
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), index));	// index
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 0));	// value
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 0)); // value1
		args.push_back(getConstInt32(6));	// type
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 0)); // llvm value-pointer
		llvm::CallInst *call = llvm::CallInst::Create(func, llvm::ArrayRef<llvm::Value*>(args),
			"", &*function->begin()->begin());
		++index;
		assert(call && "failed to insert call instruction");
	}
	
	for (std::vector< llvm::BasicBlock *>::iterator bb_it = basicBlocks.begin(); 
		bb_it != basicBlocks.end(); ++bb_it) {
		
		std::vector< llvm::Value *> args;
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), index));	// index
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 0));	// value
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 0)); // value1
		args.push_back(getConstInt32(7));	// type
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 0)); // llvm value-pointer
		llvm::CallInst *call = llvm::CallInst::Create(func, llvm::ArrayRef<llvm::Value*>(args),
			"", (*bb_it)->getFirstNonPHI());
		++index;
		assert(call && "failed to insert call instruction");
	}
	
	for (std::vector< llvm::StoreInst *>::iterator inst_it = storeInstructions.begin();
		inst_it != storeInstructions.end(); ++inst_it) {
		llvm::StoreInst *storeInst = *inst_it;
		
		_debugInsertStore(storeInst, func, index);
	}
	
	report("load instructions");
	for (std::vector< llvm::LoadInst *>::iterator inst_it = loadInstructions.begin(); 
		inst_it != loadInstructions.end(); ++inst_it) {
	
		llvm::LoadInst *loadInst = *inst_it;
		_debugInsertLoad(loadInst, func, index);
	}
	for (std::vector< llvm::ReturnInst *>::iterator inst_it = returnInstructions.begin();
		inst_it != returnInstructions.end(); ++inst_it) {
		llvm::ReturnInst *retInst = *inst_it;
		
		std::vector< llvm::Value *> args;
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), index));	// index
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 0));	// value
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 0)); // value1
		args.push_back(getConstInt32(3));	// type
		args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 
			(size_t)(void *)retInst)); // llvm value-pointer
		llvm::CallInst *call = llvm::CallInst::Create(func, llvm::ArrayRef<llvm::Value*>(args),
			"", retInst);
		++index;
		
		assert(call && "failed to insert call instruction");
	}
}


void analysis::LLVMUniformVectorization::Translation::_debugInsertStore(llvm::StoreInst *storeInst, 
	llvm::Constant *func, size_t index) {
	bool moveBack = false;
		
	// store instruction
	llvm::Value *cast = llvm::CastInst::CreatePointerCast(storeInst->getPointerOperand(),
		llvm::Type::getInt64Ty(context()), "ptrToInt", storeInst);

	llvm::Value *type = getConstInt32(1);
	llvm::Value *operand = 0;
	llvm::Type *valueType = storeInst->getValueOperand()->getType();
	if (llvm::PointerType::classof(valueType)) {
		operand = llvm::CastInst::CreatePointerCast(storeInst->getValueOperand(),
			llvm::Type::getInt64Ty(context()), "ptrCast", storeInst);
	}
	else if (llvm::IntegerType::classof(valueType)) {
		operand = llvm::CastInst::CreateIntegerCast(storeInst->getValueOperand(),
			llvm::Type::getInt64Ty(context()), false, "intCast", storeInst);
	}
	else if (valueType->isFloatTy() || valueType->isDoubleTy()) {
		report("  storing floating point value");
		operand = llvm::CastInst::CreateFPCast(storeInst->getValueOperand(),
			llvm::Type::getDoubleTy(context()), "fpCast", storeInst);
		operand = llvm::CastInst::CreateZExtOrBitCast(operand, llvm::Type::getInt64Ty(context()),
			"bitcast", storeInst);
		type = getConstInt32(4);
	}
	else if (llvm::VectorType *vectorType = llvm::dyn_cast<llvm::VectorType>(valueType)) {
		// vector stores			
		cast = llvm::CastInst::CreatePointerCast(
			storeInst->getPointerOperand(), llvm::Type::getInt64Ty(context()), "", storeInst);
		operand = getConstInt64(vectorType->getNumElements());
		type = getConstInt32(8);
		moveBack = true;
	}
	else {
		size_t ptr = hydrazine::bit_cast<size_t>(valueType);
		operand = llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), ptr);
		type = getConstInt32(5);
	}

	std::vector< llvm::Value *> args;
	args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), index));	// index
	args.push_back(cast);	// value
	args.push_back(operand); // value1
	args.push_back(type);	// type
	args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 
		(size_t)(void *)storeInst)); // llvm value-pointer
	llvm::CallInst *call = llvm::CallInst::Create(func, llvm::ArrayRef<llvm::Value*>(args),
		"", storeInst);
	++index;
	if (moveBack) {
		call->removeFromParent();
		call->insertAfter(storeInst);
	}

	assert(call && "failed to insert call instruction");
}

void analysis::LLVMUniformVectorization::Translation::_debugInsertLoad(llvm::LoadInst *loadInst, 
	llvm::Constant *func, size_t index) {
	
	llvm::Instruction *addressCast = llvm::CastInst::CreatePointerCast(loadInst->getPointerOperand(),
		llvm::Type::getInt64Ty(context()), "ptrToInt", loadInst);
	
	llvm::Instruction *lastInserted = loadInst;
	
	addressCast->removeFromParent();
	addressCast->insertAfter(lastInserted);
	lastInserted = addressCast;
	
	llvm::Value *loadedValue = loadInst;
	llvm::Value *type = getConstInt32(9);
	llvm::Type *valueType = loadInst->getType();
	if (llvm::PointerType::classof(valueType)) {
		llvm::Instruction *recentlyInserted = llvm::CastInst::CreatePointerCast(
			loadInst, llvm::Type::getInt64Ty(context()), "ptrToInt", lastInserted);
		recentlyInserted->removeFromParent();
		recentlyInserted->insertAfter(lastInserted);
		lastInserted = recentlyInserted;
		loadedValue = recentlyInserted;
		type = getConstInt32(11);
	}
	else if (llvm::IntegerType::classof(valueType)) {
		llvm::Instruction *recentlyInserted = llvm::CastInst::CreateIntegerCast(loadInst,
			llvm::Type::getInt64Ty(context()), false, "intCast", lastInserted);
		
		recentlyInserted->removeFromParent();
		recentlyInserted->insertAfter(lastInserted);
		lastInserted = recentlyInserted;
		loadedValue = recentlyInserted;
	}
	else if (valueType->isFloatTy() || valueType->isDoubleTy()) {
		type = getConstInt32(10);
		
		llvm::Instruction *recentlyInserted = llvm::CastInst::CreateFPCast(loadInst,
			llvm::Type::getDoubleTy(context()), "fpCast", lastInserted);
		recentlyInserted->removeFromParent();
		recentlyInserted->insertAfter(lastInserted);
		lastInserted = recentlyInserted;
		
		recentlyInserted = llvm::CastInst::CreateZExtOrBitCast(recentlyInserted, 
			llvm::Type::getInt64Ty(context()), "bitcast", lastInserted);
		recentlyInserted->removeFromParent();
		recentlyInserted->insertAfter(lastInserted);
		lastInserted = recentlyInserted;
		
		loadedValue = recentlyInserted;
	}
	else {
		return;
	}
	
	std::vector< llvm::Value *> args;
	args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), index));	// index
	args.push_back(addressCast);	// value
	args.push_back(loadedValue); // value1
	args.push_back(type);	// type
	args.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(context()), 
		(size_t)(void *)loadInst)); // llvm value-pointer
		
	report("  inserting load (" << args.size() << ")");
	llvm::CallInst *call = llvm::CallInst::Create(func, llvm::ArrayRef<llvm::Value*>(args),
		"", lastInserted);
	++index;

	call->removeFromParent();
	call->insertAfter(lastInserted);
	lastInserted = call;
}

extern "C" void _ocelot_debug_report_block(size_t fileHash, int tid, int kernelBlockId) {

	static size_t counter = 0;

	std::stringstream name;
	
	name << "debug-" << std::hex << fileHash << std::dec << ".log";
	std::ofstream file(name.str().c_str(), std::ios_base::app);
	
	if (file.fail()) {
		assert(0 && "failed to open file");
	}
	
	file << tid << "," << kernelBlockId << std::flush << std::endl;
	file.close();
	counter++;
}

void analysis::LLVMUniformVectorization::Translation::_debugControlFlowMatrix() {
	std::vector< llvm::Type *> params;
	params.push_back(getTyInt(64));
	params.push_back(getTyInt(32));
	params.push_back(getTyInt(32));
	llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(context()), 
		llvm::ArrayRef<llvm::Type*>(params), false);
	
	report("Translation::_debugControlFlowMatrix()");
	report("  subkernel: " << subkernel->id);
	report("  kernelGraph entryID: " << pass->kernelGraph->entrySubkernelId);
	
	size_t fileHash = std::hash<std::string>()(pass->kernelGraph->ptxKernel->name);
	
	llvm::Constant *reportFunc = function->getParent()->getOrInsertFunction(
		"_ocelot_debug_report_block", funcType);
		
	report("Blocks:");
	std::vector< std::string > blockLabels;
	
	for (ir::ControlFlowGraph::iterator bb_it = pass->kernelGraph->ptxKernel->cfg()->begin();
		bb_it != pass->kernelGraph->ptxKernel->cfg()->end(); ++bb_it) {
		
		std::string label = bb_it->label;
		
		if (label.find_first_of("handler") == std::string::npos) {
			blockLabels.push_back(label);
		}
	}
	std::sort(blockLabels.begin(), blockLabels.end());
	
	std::stringstream name;
	name << "debug-" << std::hex << fileHash << std::dec << "-kernel.log";
	std::ofstream file(name.str().c_str(), std::ios_base::out | std::ios_base::in);
	
	if (!file.is_open()) {
		std::ofstream file(name.str().c_str());
		std::ofstream ptxFile((name.str() + ".ptx").c_str());
		
		pass->kernelGraph->ptxKernel->write(ptxFile);

	}
	
	file << pass->kernelGraph->ptxKernel->name << "," << blockLabels.size() << "\n";
	
	std::map< std::string, int > blockIdMap;
	for (std::vector< std::string >::iterator label_it = blockLabels.begin(); 
		label_it != blockLabels.end(); ++label_it ) {
		
		int index = (int)blockIdMap.size() + 1;
		file << *label_it << "," << index << std::endl;
		blockIdMap[*label_it] = index;		
	}
	
	assert(schedulerEntryBlock.threadLocalArguments.size() && "no thread local arguments");
	
	llvm::Value *threadId = 0;
	
	int unexpected = (subkernel->id * 1000);
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		std::map< std::string, int >::iterator block_it = blockIdMap.find(bb_it->getName().str());
		int blockId = -unexpected;
		llvm::Instruction *insert = bb_it->getFirstNonPHI();
		if (block_it != blockIdMap.end()) {
			blockId = block_it->second;
		}
		else if (&*bb_it == schedulerEntryBlock.block) {
			insert = bb_it->getTerminator();
			blockId = -subkernel->id * 100;
		}
		else {
			++unexpected;
		}
		if (bb_it->getName().str() == "exit") {
			continue;
		}
		
		if (!threadId) {
			int tid = 0;
			llvm::Value *blockDimX = schedulerEntryBlock.threadLocalArguments[tid].blockDim_x;
			llvm::Value *blockDimY = schedulerEntryBlock.threadLocalArguments[tid].blockDim_y;
			llvm::Value *tidX = schedulerEntryBlock.threadLocalArguments[tid].threadId_x;
			llvm::Value *tidY = schedulerEntryBlock.threadLocalArguments[tid].threadId_y;
			llvm::Value *tidZ = schedulerEntryBlock.threadLocalArguments[tid].threadId_z;
		
			assert(blockDimX && blockDimY && tidX && tidY && tidZ);
		
			llvm::Value *a0 = llvm::BinaryOperator::CreateMul(blockDimX, blockDimY, "", insert);
			llvm::Value *a1 = llvm::BinaryOperator::CreateMul(a0, tidZ, "", insert);
			llvm::Value *a2 = llvm::BinaryOperator::CreateMul(blockDimX, tidY, "", insert);
			llvm::Value *a3 = llvm::BinaryOperator::CreateAdd(a1, a2, "", insert);
			threadId = llvm::BinaryOperator::CreateAdd(a3, tidX, "threadId.t0", insert);
		}
		
		std::vector< llvm::Value *> args;
		args.push_back(getConstInt64(fileHash));
		args.push_back(threadId);
		args.push_back(getConstInt32(blockId));
		llvm::CallInst *callInst = llvm::CallInst::Create(reportFunc, 
			llvm::ArrayRef<llvm::Value*>(args), "", insert);
		assert(callInst);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief increments the vectorization statistics given an instruction
void analysis::LLVMUniformVectorization::VectorizationStatistics::count(VectorizedInstruction &vec) {
	llvm::Instruction *inst = (vec.vector ? vec.vector : vec.replicated.at(0));

	llvm::Type *type = inst->getType();
	llvm::VectorType *vecType = llvm::dyn_cast<llvm::VectorType>(type);
	
	if (llvm::CallInst::classof(inst)) {
		if (vecType) {
			callInstructions.encounter();
		}
		else {
			callInstructions.notCounted();
		}
	}
	else if (llvm::StoreInst *storeInst = llvm::dyn_cast<llvm::StoreInst>(inst)) {
		vecType = llvm::dyn_cast<llvm::VectorType>(storeInst->getValueOperand()->getType());
		if (vecType) {
			storeInstructions.encounter();
		}
		else {
			storeInstructions.notCounted();			
		}
	}
	else if (llvm::LoadInst::classof(inst)) {
		if (vecType) {
			loadInstructions.encounter();
		}
		else {
			loadInstructions.notCounted();	
		}
	}
	else {
		bool vectorized = (vecType ? true: false);
		llvm::Type *element = (vecType ? vecType->getElementType() : type);
	
		if (element->isIntegerTy()) {
			integerInstructions.count(vectorized);
		}
		else if (element->isFloatTy()) {
			floatInstructions.count(vectorized);
		}
	}
}

void analysis::LLVMUniformVectorization::VectorizationStatistics::Counter::write(std::ostream &out) const {

	out << "{\"counted\": " << encountered << ", \"total\": " << total << "}";
}

void analysis::LLVMUniformVectorization::VectorizationStatistics::write(std::ostream &out) const {

	Counter VectorizationStatistics::* members[] = {
		&VectorizationStatistics::integerInstructions,
		&VectorizationStatistics::floatInstructions,
		&VectorizationStatistics::callInstructions,
		&VectorizationStatistics::storeInstructions,
		&VectorizationStatistics::loadInstructions
	};
	const char *memberNames[] = {
		"integer", "float", "call", "store", "load", 0
	};
	
	out << "{\n";
	for (int i = 0; memberNames[i]; ++i) {
		const Counter &counter = (this->*(members[i]));
		out << (i?",\n":"") << "\"" << memberNames[i] << "\": ";
		counter.write(out);
	}
	out << "\n}";
}

//! \brief visits all vectorized instructions and updates statistics accordingly
void analysis::LLVMUniformVectorization::Translation::_computeVectorizationStatistics(
	VectorizationStatistics &statistics) {

	statistics.clear();

	for (VectorizedInstructionMap::iterator vec_it = vectorizedInstructionMap.begin();
		vec_it != vectorizedInstructionMap.end(); ++vec_it) {
		
		statistics.count(vec_it->second);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////


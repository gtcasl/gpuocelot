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

#define REPORT_BASE 0

#define REPORT_FINAL_SUBKERNEL 0

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
// Controls compilation flow
//

#define ENABLE_COMPILE_TIME_VECTORIZATION 0

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
	bool _vectorize
):
	llvm::FunctionPass(ID), kernelGraph(_kernelGraph), subkernelId(_subkernelId), 
		warpSize(_ws), vectorizeConvergent(_vectorize)
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

static llvm::Instruction * analysis::LLVMUniformVectorization::ThreadLocalArgument::* 
	ThreadLocalArgumentInstances[] = {
	
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
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::metadataPointer,
	&analysis::LLVMUniformVectorization::ThreadLocalArgument::ptrThreadDescriptorArray
};

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
	
	/*
	if (pass->warpSize == 1) {
		_scalarPreprocess();
	}
	else {
		_transformWarpSynchronous();
	}
	*/
	
	_scalarPreprocess();
	if (pass->warpSize > 1) {
		_transformWarpSynchronous();
		
	#if INSERT_DEBUG_REPORTING
		_debugReporting();
	#endif
	#if INSERT_DEBUG_CONTROL_FLOW
		_debugControlFlowMatrix();
	#endif
	
	}
	
	report("Translation(" << f->getName().str() << ", ws " << pass->warpSize << ") complete");
#if REPORT_BASE && REPORT_FINAL_SUBKERNEL

	report(" Arguments: ");
	for (llvm::Function::arg_iterator arg_it = function->arg_begin(); 
		arg_it != function->arg_end(); ++arg_it) {
		report("  " << String( llvm::dyn_cast<llvm::PointerType>(arg_it->getType())->getElementType()));
	}

	report(" LLVM function:\n" << String(function));
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
			ThreadLocalArgument &local = schedulerEntryBlock.threadLocalArguments[0];
			
			llvm::Instruction **dim3Instances[] = {
				&local.threadId_x, &local.threadId_y, &local.threadId_z, 
				&local.blockDim_x, &local.blockDim_y, &local.blockDim_z, 
				&local.blockId_x, &local.blockId_y, &local.blockId_z, 
				&local.gridDim_x, &local.gridDim_y, &local.gridDim_z, 
			};
			
			// scalars
			llvm::Instruction **ptrInstances[] = {
				&local.localPointer,
				&local.sharedPointer,
				&local.constantPointer,
				&local.parameterPointer,
				&local.argumentPointer,
				&local.globallyScopedLocal,
				&local.externalSharedSize,
				&local.metadataPointer,
			};
			
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
				selected = *dim3Instances[indices[1] * 3 + indices[2]];
			}
			else {
				selected = *ptrInstances[indices[1] - 4];
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

void analysis::LLVMUniformVectorization::Translation::_loadThreadLocal(
	ThreadLocalArgument &local, int threadId, llvm::Instruction *before, llvm::BasicBlock *block) {
	
	report("  _loadThreadLocal(thread " << threadId << ")");
	
	if (!block) {
		block = before->getParent();
	}
	
	report("  Loading thread-local arguments for thread " << threadId);
	report("  inserting into block " << block->getName().str());
	
	llvm::Value *contextArrayBasePointer = &function->getArgumentList().front();
	std::string threadSuffix = std::string(".t") + boost::lexical_cast<std::string, int>(threadId);
		
	if (false) {
		std::vector< llvm::Value *> idx;
		idx.push_back(getConstInt32(threadId));
	
		llvm::GetElementPtrInst *contextGemp = llvm::GetElementPtrInst::Create(contextArrayBasePointer,
			llvm::ArrayRef<llvm::Value*>(idx), "contextPtrGemp", block);
		if (before) { 
			contextGemp->moveBefore(before);
		}
	
		llvm::LoadInst *loadInst = new llvm::LoadInst(contextGemp, "contextPtr" + threadSuffix, block);
		if (before) {
			loadInst->moveBefore(before);
		}
		local.context = loadInst;
	}
	else {
		local.context = contextArrayBasePointer;
	}
	
	// load dimensions
	llvm::Instruction **dim3Instances[] = {
		&local.threadId_x, &local.threadId_y, &local.threadId_z, 
		&local.blockDim_x, &local.blockDim_y, &local.blockDim_z, 
		&local.blockId_x, &local.blockId_y, &local.blockId_z, 
		&local.gridDim_x, &local.gridDim_y, &local.gridDim_z, 
	};
	const char *dim3names[] = { "threadId", "blockDim", "blockId", "gridDim" };
	const char *dim3suffix[] = {"x", "y", "z"};
	
	for (int idx = 0; idx < 4; idx++) {
		for (int j = 0; j < 3; j++) {
			std::vector< llvm::Value *> ind;
			ind.push_back(getConstInt32(threadId));
			ind.push_back(getConstInt32(idx));
			ind.push_back(getConstInt32(j));
			
			llvm::GetElementPtrInst *ptr = llvm::GetElementPtrInst::Create(local.context, 
				llvm::ArrayRef<llvm::Value*>(ind), "", block);
			if (before) {
				ptr->moveBefore(before);
			}
			
			std::string name = std::string(dim3names[idx]) + "." + dim3suffix[j] + threadSuffix;
			*(dim3Instances[idx * 3 + j]) = new llvm::LoadInst(ptr, name, block);
			if (before) {
				(*(dim3Instances[idx * 3 + j]))->moveBefore(before);
			}
		}
	}
	
	// scalars
	llvm::Instruction **ptrInstances[] = {
		&local.localPointer,
		&local.sharedPointer,
		&local.constantPointer,
		&local.parameterPointer,
		&local.argumentPointer,
		&local.metadataPointer,
	};
	const char *ptrNames[] = {
		"localPtr", "sharedPtr", "constPtr", "paramPtr", "argumentPtr", "metadataPtr", 
	};
	for (int idx = 0; idx < 6; idx++) {
	
		std::vector< llvm::Value *> ind;
		ind.push_back(getConstInt32(threadId));
		ind.push_back(getConstInt32(idx + 4));
		
		llvm::GetElementPtrInst *ptr = llvm::GetElementPtrInst::Create(local.context, 
			llvm::ArrayRef<llvm::Value*>(ind), std::string(ptrNames[idx]) + "Ptr" + threadSuffix, block);
		if (before) {
			ptr->moveBefore(before);
		}
		
		*(ptrInstances[idx]) = new llvm::LoadInst(ptr, ptrNames[idx] + threadSuffix, block);
		if (before) {
			(*(ptrInstances[idx]))->moveBefore(before);
		}
	}
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
	_eliminateEmptyBlocks();
	_basicBlockPasses();
}

void analysis::LLVMUniformVectorization::Translation::_basicBlockPasses() {
	for (llvm::Function::iterator bb_it = function->begin(); bb_it != function->end(); ++bb_it) {
		_eliminateBitcasts(bb_it);
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
		
		for (llvm::pred_iterator pred_it = llvm::pred_begin(&*bb_it); 
			pred_it != llvm::pred_end(&*bb_it); ++pred_it) {
			++count;
			break;
		}
		if (!count) {
			report("    - no predecessors");
			killWithFire.push_back(&*bb_it);
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
	
	bool updateName = (!llvm::StoreInst::classof(inst));
	std::string baseName = inst->getName().str() + ".t";
	if (updateName) {
		std::string name = baseName + boost::lexical_cast<std::string, int>(0);
		//inst->setName(name);
	}
	vectorized.replicated.push_back(inst);

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
		
		clone->insertAfter(inst);
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
					report("      operand " << i << " not in mapping: " << String(opInst));
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
}

/*!
	Given a divergent branch entry and a reference to the corresponding out edge,
	transforms control instructions to point to the out edge according to the type
	of divergent branch.
*/
void analysis::LLVMUniformVectorization::Translation::_updateDivergentBlock(
	const analysis::KernelPartitioningPass::DivergentBranch &divergence, 
	const analysis::KernelPartitioningPass::ExternalEdge &outEdge) {

	report("  _updateDivergentBlock(" << divergence.frontierBlock->label << ")");
	
	typedef analysis::KernelPartitioningPass::DivergentBranch DivergentBranch; 
	
	llvm::BasicBlock *llvmBlock = ocelotToLlvmBlockMap[divergence.frontierBlock];
	llvm::BasicBlock *handler = ocelotToLlvmBlockMap[outEdge.handler];
		
	assert(llvmBlock && "failed to obtain frontier block from Ocelot->LLVM mapping");
	assert(handler && "failed to obtain handler block from Ocelot->LLVM mapping");
	
	llvm::TerminatorInst *terminator = llvmBlock->getTerminator();
		
	if (llvm::BranchInst *branchInst = llvm::dyn_cast<llvm::BranchInst>(terminator)) {
		if (branchInst->isConditional() && llvm::Instruction::classof(branchInst->getCondition())) {
		
			llvm::Instruction *condition = llvm::dyn_cast<llvm::Instruction>(branchInst->getCondition());
			VectorizedInstructionMap::iterator vec_it = vectorizedInstructionMap.find(condition);
			if (vec_it != vectorizedInstructionMap.end()) {
				
				llvm::BasicBlock *targetTrue = branchInst->getSuccessor(0);
				llvm::BasicBlock *targetFalse = branchInst->getSuccessor(1);
					
				branchInst->eraseFromParent();
				
				llvm::Type *intTy = getTyInt(32);
				llvm::Instruction *condition = new llvm::ZExtInst(vec_it->second.replicated[0],	
					intTy, "cond", llvmBlock);
				
				for (size_t t = 1; t < vec_it->second.replicated.size(); ++t) {
					llvm::Instruction *ext = new llvm::ZExtInst(vec_it->second.replicated[t], intTy, 
						"cond", branchInst->getParent());
					condition = llvm::BinaryOperator::Create(llvm::Instruction::Add, condition,
						ext, "cmpws", llvmBlock);
				}
		
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

/*! \brief given an instruction from the scalar set, get a set of scalar values that are 
	either replicated scalar instructions from the vectorized set or extracted vector elements */
analysis::LLVMUniformVectorization::InstructionVector 
	analysis::LLVMUniformVectorization::Translation::getInstructionAsReplicated(
		llvm::Value *inst, llvm::Instruction *before) {
	
	report("  getting instruction " << inst << " as replicated - inserting before " << before);
	assert(0 && "not yet implemented");
}

/*! \brief given an instruction from the scalar set, get a vector from the vectorized set that
	is either a promoted-to-vector instruction or a set of scalar values packed into a vector*/
llvm::Instruction *
	analysis::LLVMUniformVectorization::Translation::getInstructionAsVectorized(
		llvm::Value *value, llvm::Instruction *before) {
	
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
		else if (llvm::ExtractElementInst *extractInst = llvm::dyn_cast<llvm::ExtractElementInst>(instruction)) {
			vectorizedInstruction = llvm::dyn_cast<llvm::Instruction>(extractInst->getVectorOperand());
		}
		else {
			report("  Instruction not in mapping: " << String(instruction));
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
	
	report("  vectorize()");
	
	llvm::Instruction *vectorized = vec_it->second.vector;
	if (!vectorized) {
		if (vec_it->second.isVectorizable()) {
			if (llvm::BinaryOperator *binOp = llvm::dyn_cast<llvm::BinaryOperator>(vec_it->first)) {
				vectorized = _vectorizeBinaryOperator(binOp, vec_it);
			}
			else if (llvm::CallInst *callInst = llvm::dyn_cast<llvm::CallInst>(vec_it->first)) {
				vectorized = _vectorizeCall(callInst, vec_it);
			}
			else {
				assert(0 && "unhandled vectorizable instruction");	
			}
			if (vectorized) {
				InstructionVector extracted;
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
	
	report("  vectorizeUnvectorizable: " << String(inst));
	report("     replicated:");
	
	for (int tid = 0; tid < pass->warpSize; tid++) {
		report("      [tid: " << tid << "]: " << String(vec_it->second.replicated[tid]));
	}
	
	// pack replicated instructions	
	llvm::Value *lastInserted = llvm::UndefValue::get(llvm::VectorType::get(
		inst->getType(), pass->warpSize));
	llvm::Instruction *insertInst = 0;
	
	for (int tid = 0; tid < pass->warpSize; tid++) {
		llvm::ConstantInt *idx = getConstInt32(tid);
		llvm::Instruction *element = vec_it->second.replicated[tid];
		std::stringstream ss;
		ss << "insert." << element->getName().str() << ".vec";
		
		if (!tid) {
			insertInst = llvm::InsertElementInst::Create(lastInserted, element, 
				idx, ss.str(), inst->getParent());
			insertInst->removeFromParent();
			insertInst->insertAfter(vec_it->second.replicated[pass->warpSize - 1]);
		}
		else {
			insertInst = llvm::InsertElementInst::Create(lastInserted, element, 
				idx, ss.str(), static_cast<llvm::Instruction*>(lastInserted));
			insertInst->removeFromParent();
			insertInst->insertAfter(static_cast<llvm::Instruction*>(lastInserted));
		}
		lastInserted = insertInst;
	}
	
	return insertInst;
}

llvm::Instruction * analysis::LLVMUniformVectorization::Translation::_vectorizeBinaryOperator(
	llvm::BinaryOperator *inst, VectorizedInstructionMap::iterator &vec_it) {

	report("  vectorizeBinaryOperator(): " << String(inst));

	llvm::Instruction *op0 = getInstructionAsVectorized(vec_it->first->getOperand(0), inst);
	llvm::Instruction *op1 = getInstructionAsVectorized(vec_it->first->getOperand(1), inst);
	
	std::stringstream ss;
	ss << inst->getName().str() << ".vec";

	vec_it->second.vector = llvm::BinaryOperator::Create(inst->getOpcode(), op0, op1, ss.str(), inst);
	
	return vec_it->second.vector;
}
			
llvm::Instruction * analysis::LLVMUniformVectorization::Translation::_vectorizeCall(
	llvm::CallInst *callInst, VectorizedInstructionMap::iterator &vec_it) {
	
	llvm::Instruction *before = 0;
	
	// it's a call instruction
	std::string calleeName = callInst->getCalledFunction()->getName().str();

	report(" call instruction: " << calleeName);

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
				report("creating intrinsic type " << calleeName);
				llvm::VectorType *vecType = llvm::VectorType::get(callInst->getType(), pass->warpSize);
				std::vector< llvm::Type *> args;
				args.push_back(vecType);
				llvm::FunctionType *funcType = llvm::FunctionType::get(vecType, args, false);
				funcIntrinsic = llvm::Function::Create(funcType, 
					llvm::GlobalValue::ExternalLinkage, destName, function->getParent());
			}
			else {
				report("using existing intrinsic definition ");
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

//////////////////////////////////////////////////////////////////////////////////////////////////


bool analysis::LLVMUniformVectorization::VectorizedInstruction::isPackable() const {
	return llvm::VectorType::isValidElementType(replicated[0]->getType());
}

bool analysis::LLVMUniformVectorization::VectorizedInstruction::isVectorizable() const {
	if (replicated[0]->getType()->isFloatTy() ||
		replicated[0]->getType()->isDoubleTy() ||
		replicated[0]->getType()->isIntegerTy(32)) {
		
		if (replicated[0]->isBinaryOp() || llvm::CallInst::classof(replicated[0])) {
			return true;	
		}
	}
	return false;
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
			std::cout << " load(" << index << "): " << hydrazine::bit_cast<double>(value1) << " = [" << (void *)value << "]   <float>";
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
		llvm::FunctionType::get(llvm::Type::getVoidTy(context()), llvm::ArrayRef<llvm::Type*>(params), false);
	
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
		
		recentlyInserted = llvm::CastInst::CreateZExtOrBitCast(recentlyInserted, llvm::Type::getInt64Ty(context()),
			"bitcast", lastInserted);
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
		llvm::CallInst *callInst = llvm::CallInst::Create(reportFunc, llvm::ArrayRef<llvm::Value*>(args), 
			"", insert);
		assert(callInst);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::AffineValue::AffineValue():
	base(0), offset(0), constant(0) {

}

analysis::LLVMUniformVectorization::AffineValue::AffineValue(llvm::Value *_base, 
	llvm::Constant *_offset, llvm::Constant *_constant): base(_base), offset(_offset), constant(_constant) {

}

bool analysis::LLVMUniformVectorization::AffineValue::invariant() const {
	return (constant ? false : true);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::AffineVarianceAnalysis::AffineVarianceAnalysis(
	llvm::Function *_function, 
	const analysis::LLVMUniformVectorization::ThreadLocalArgumentVector &_threadLocal):
		function(_function), threadLocal(_threadLocal) {
	
	_enumerateInvariants();
	_compute();
}

analysis::LLVMUniformVectorization::AffineVarianceAnalysis::~AffineVarianceAnalysis() {

}

/*!
	marks all trivial values that are thread-invariant across the CTA
*/
void analysis::LLVMUniformVectorization::AffineVarianceAnalysis::_enumerateInvariants() {

	report("_enumerateInvariants()");
	
	// global values
	report("  global values:");
	for (llvm::Module::const_global_iterator global_it = function->getParent()->global_begin();
		global_it != function->getParent()->global_end(); ++global_it) {
	
		report("   " << global_it->getName().str());
		
		// all load instructions using this are invariant
		for (llvm::Value::const_use_iterator use_it = global_it->use_begin(); 
			use_it != global_it->use_end(); ++use_it ) {
			
		}
		invariantSet.insert(&*global_it);
	}
	
	// trivial thread-invariant
	for (int i = 3; i < 12; i++) {
		invariantSet.insert((threadLocal[0]).*(ThreadLocalArgumentInstances[i]));
	}
	for (int i = 14; i < 17; i++) {
		invariantSet.insert((threadLocal[0]).*(ThreadLocalArgumentInstances[i]));
	}

#if REPORT_BASE
	report("  CTA-invariant values: ");
	for (ConstValueSet::const_iterator invariant_it = invariantSet.begin(); 
		invariant_it != invariantSet.end(); ++invariant_it) {
		report("  " << (*invariant_it)->getName().str());
	}
#endif
}

void analysis::LLVMUniformVectorization::AffineVarianceAnalysis::_compute() {

}

		
//////////////////////////////////////////////////////////////////////////////////////////////////

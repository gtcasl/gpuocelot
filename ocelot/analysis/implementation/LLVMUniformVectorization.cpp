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

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

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

std::ostream &Instruction_print(std::ostream &out, llvm::Instruction * inst) {
	std::string str;
	llvm::raw_string_ostream os(str);
	inst->print(os);
	out << str;
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! 
analysis::LLVMUniformVectorization::LLVMUniformVectorization(KernelGraph *_kernelGraph, int _ws):
	llvm::FunctionPass(ID), kernelGraph(_kernelGraph), warpSize(_ws)
{
	report("LLVMUniformVectorization() on kernel " << kernelGraph->ptxKernel->name);
}

//! 
analysis::LLVMUniformVectorization::~LLVMUniformVectorization() {

}


bool analysis::LLVMUniformVectorization::doInitialize(llvm::Module &M) {
	return false;
}

//! \brief entry point for pass
bool analysis::LLVMUniformVectorization::runOnFunction(llvm::Function &F) {
	return false;
}

//! \brief gets the name of the pass
const char *analysis::LLVMUniformVectorization::getPassName() const {
	return "Ocelot LLVM Uniform Vectorization";
}

//! \brief gets the kind of tye pass
llvm::PassKind analysis::LLVMUniformVectorization::getPassKind() const {
	return llvm::PT_Function;
}


llvm::LLVMContext & analysis::LLVMUniformVectorization::context() {
	return M->getContext();
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

	_scalarPreprocess();
	_transformWarpSynchronous();
}

analysis::LLVMUniformVectorization::Translation::~Translation() {

}

/*!
	\brief entry point to pass
*/
void analysis::LLVMUniformVectorization::Translation::runOnFunction() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

llvm::LLVMContext & analysis::LLVMUniformVectorization::Translation::context() {
	return pass->>getContext();
}

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
		llvm::Value *inst, llvm::Instruction *before) {
		
	report("  getting instruction " << inst << " as vectorized - inserting before " << before);
	assert(0 && "not yet implemented");
}


//////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::_scalarPreprocess() {

	// identify mapping from LLVM blocks to GPU Ocelot blocks
	_computeLLVMToOcelotBlockMap();

	// identify possible entry points
	_enumerateEntries();

	// create scheduler
	schedulerEntryBlock.block = llvm::BasicBlock::Create(context(), "SchedulerEntry", function, 
		&*function->begin());
	
	ThreadLocalArgument localArgs;
	_loadThreadLocal(localArgs, 0, schedulerEntryBlock.block);
	schedulerEntryBlock.threadLocalArguments.push_back(localArgs);

	// construct scheduler entry and load thread-local values
	_initializeSchedulerEntryBlock();

	// complete scheduler
	_completeSchedulerEntryBlock();
}


void analysis::LLVMUniformVectorization::Translation::_computeLLVMToOcelotBlockMap() {

	std::map< std::string, ir::BasicBlock::Pointer > blockLabelMap;
	for (ir::ControlFlowGraph::iterator bb_it =	subkernel->subkernel->cfg()->begin();
		bb_it != subkernel->subkernel->cfg()->end(); ++bb_it) {
		
		blockLabelMap[bb_it->label] = bb_it;
	}
	
	for (llvm::Function::iterator llvmbb_it = function->begin(); 
		llvmbb_it != function->end(); ++llvmbb_it) {
		
		llvm::BasicBlock *llvmBlock = &*llvm_it;
		ir::BasicBlock::Pointer ocelotBlock = blockLabelMap[llvmbb_it->getName().str()];
		
		llvmToOcelotBlockMap[llvmBlock] = ocelotBlock;
		ocelotToLlvmBlockMap[ocelotBlock] = llvmBlock;
	}
}

void analysis::LLVMUniformVectorization::Translation::_enumerateEntries() {
	typedef analysis::KernelPartitioningPass::ExternalEdgeVector ExternalEdgeVector;
	
	ExternalEdgeVector Subkernel::*entryLists[] = {
		&Subkernel::inEdges,
		&Subkernel::barrierEntries,
		&Subkernel::divergentEntries;
	};
	
	for (int i = 0; i < 3; i++) {
		for (ExternalEdgeVector::iterator edge_it = (subkernel->*(entryLists[i])).begin();
			edge_it != (subkernel->*(entryLists[i])).end(); ++edge_it) {
			ExternalEdgeVector &edge = *edge_it;
			
			schedulerEntryBlock.entries[edge->entryId] = 
		}
	}
}

//! \brief replaces uses of thread-local arguments with explicit references
void analysis::LLVMUniformVectorization::Translation::_initializeSchedulerEntryBlock() {

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
			for (llvm::op_iterator op_it = gemp->idx_begin(); 
				op_it != gemp->idx_end(); ++op_it, ++indexCount) {
				llvm::ConstantInt *constInt = llvm::dyn_cast<llvm::ConstantInt>(*op_it);
				assert(constInt && "failed to cast index to constant int");
				indices[indexCount] = constInt->get();
			}
			if (indices[1] <= 3) {
				assert(indices[2] >= 0 && indices[2] < 3);
				selected = dim3Instances[indices[1] * 3 + indices[2]];
			}
			else {
				selected = ptrInstances[indices[1] - 4];
			}
			assert(selected && "failed to identify thread-local argument");
			
			for (llvm::use_iterator use_it = gemp->use_begin(); use_it != gemp->use_end(); ++use_it) {
				assert(llvm::dyn_cast<llvm::LoadInst>(&*use_it) && "user of GEMP must be LoadInst");
				
				use_it->replaceAllUsesWith(selected);
				use_it->eraseFromParent();
			}
			gemp->eraseFromParent();
		}
	}
}

void analysis::LLVMUniformVectorization::Translation::_loadThreadLocal(
	ThreadLocalArgument &local, int threadId, llvm::BasicBlock *block) {
	
	llvm::Value *contextArrayBasePointer = &*function->getArgumentList().front();
	std::string threadSuffix = std::string(".t") + boost::lexical_cast<std::string, int>(threadId);
	
	std::vector< llvm::Value *> idx;
	idx.push_back(pass->getConstInt32(threadId));
	llvm::GetElementPtrInst *contextGemp = llvm::GetElementPtrInst::Create(contextArrayBasePointer,
		llvm::ArrayRef(idx), "contextPtrGemp", block);
	local.context = new llvm::LoadInst(contextGemp, "contextPtr" + threadSuffix, block);
	
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
			ind.push_back(pass->getConstInt32(0));
			ind.push_back(pass->getConstInt32(idx));
			ind.push_back(pass->getConstInt32(j));
			
			llvm::GetElementPtrInst *ptr = llvm::GetElementPtrInst(local.context, 
				llvm::ArrayRef(ind), "", block);
			
			*(dim3Instances[idx * 3 + j]) = new llvm::LoadInst(ptr, 
				dim3names[idx] + "." + dim3suffix[j] + threadSuffix, block);
		}
	}
	
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
	const char *ptrNames[] = {
		"local", "shared", "const", "param", "argument", "globalLocal", "externSharedSize", "metadata", 
	};
	for (int idx = 0; idx < 8; idx++) {
	
		std::vector< llvm::Value *> ind;
		ind.push_back(pass->getConstInt32(0));
		ind.push_back(pass->getConstInt32(idx + 4));
		ind.push_back(pass->getConstInt32(j));
		
		llvm::GetElementPtrInst *ptr = llvm::GetElementPtrInst(local.context, 
			llvm::ArrayRef(ind), std::string(ptrNames[idx]) + "Ptr" + threadSuffix, block);
		
		*(ptrInstances[idx]) = new llvm::LoadInst(ptr, ptrNames[idx] + threadSuffix, block);
	}
}

void analysis::LLVMUniformVectorization::Translation::_completeSchedulerEntryBlock( ) {
	
	llvm::BasicBlock *defaultEntry = &*(function->begin());
	
	llvm::BitCastInst *bitcastPtr = new llvm::BitCastInst(,
		schedulerEntryBlock.threadLocalArguments[0].localPointer, 
		llvm::PointerType::get(llvm::IntegerType::get(context(), 32), 0), 
		"bitcast", block);
	llvm::LoadInst *resumePoint = new llvm::LoadInst(bitcastPtr, "resumePoint", block);
	
	llvm::SwitchInst *switchInst = llvm::SwitchInst::Create(resumePoint, defaultEntry, 
		schedulerEntryBlock.entries.size(), schedulerEntryBlock.block);
	
	unsigned int idx = 0;
	for (EntryMap::const_iterator entry_it = schedulerEntryBlock.entries.begin();
		entry_it != schedulerEntryBlock.entries.end(); ++entry_it, ++idx) {
		
		switchInst->setSuccessor(idx, entry_it->second);
		switchInst->setSuccessorValue(idx, pass->getConstInt32(entry_it->first));
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief transforms the kernel into a form that executes multiple logical threads
*/
void analysis::LLVMUniformVectorization::Translation::_transformWarpSynchronous() {
	
	if (pass->warpSize > 1) {
		_replicateInstructions();
		_resolveDependencies();
		_vectorizeReplicated();
	}
	
	_finalizeTranslation();
}

void analysis::LLVMUniformVectorization::Translation::_replicateInstructions() {

}

void analysis::LLVMUniformVectorization::Translation::_resolveDependencies() {

}

void analysis::LLVMUniformVectorization::Translation::_vectorizeReplicated() {

}

void analysis::LLVMUniformVectorization::Translation::_finalizeTranslation() {

}


//////////////////////////////////////////////////////////////////////////////////////////////////


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

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_BASE 1

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

std::string String(llvm::Value *value) {
	std::string str;
	llvm::raw_string_ostream os(str);
	value->print(os);
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
	int _ws):
	llvm::FunctionPass(ID), kernelGraph(_kernelGraph), subkernelId(_subkernelId), warpSize(_ws)
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
	_scalarPreprocess();
	_transformWarpSynchronous();
	
	report("Translation(" << f->getName().str() << ", ws " << pass->warpSize << ") complete");
	report(" LLVM function:\n" << String(function));
}

analysis::LLVMUniformVectorization::Translation::~Translation() {

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
		llvm::Value *inst, llvm::Instruction *before) {
		
	report("  getting instruction " << inst << " as vectorized - inserting before " << before);
	assert(0 && "not yet implemented");
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

	// complete scheduler
	_completeSchedulerEntryBlock();
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
//			assert(0 && "failed to find block in mapping");
		}
	}
}

void analysis::LLVMUniformVectorization::Translation::_enumerateEntries() {
	typedef analysis::KernelPartitioningPass::ExternalEdgeVector ExternalEdgeVector;
	typedef analysis::KernelPartitioningPass::ExternalEdge ExternalEdge;
	
	ExternalEdgeVector Subkernel::*entryLists[] = {
		&Subkernel::inEdges,
		&Subkernel::barrierEntries,
		&Subkernel::divergentEntries,
	};
	
	for (int i = 0; i < 3; i++) {
		for (ExternalEdgeVector::iterator edge_it = (subkernel->*(entryLists[i])).begin();
			edge_it != (subkernel->*(entryLists[i])).end(); ++edge_it) {
			ExternalEdge &edge = *edge_it;
			
			schedulerEntryBlock.entries[edge.entryId] = ocelotToLlvmBlockMap[edge.handler];
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
	_loadThreadLocal(localArgs, 0, schedulerEntryBlock.block);
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
			
			for (llvm::Value::use_iterator use_it = gemp->use_begin(); use_it != gemp->use_end(); ++use_it) {
				llvm::User *user = *use_it;
				
				llvm::LoadInst *loadInst = llvm::dyn_cast<llvm::LoadInst>(user);
				assert(loadInst && "user of GEMP must be LoadInst");
				
				loadInst->replaceAllUsesWith(selected);
				loadInst->eraseFromParent();
			}
			gemp->eraseFromParent();
		}
	}
}

void analysis::LLVMUniformVectorization::Translation::_loadThreadLocal(
	ThreadLocalArgument &local, int threadId, llvm::BasicBlock *block) {
	
	report("  Loading thread-local arguments for thread " << threadId 
		<< ". Inserting into block " << block->getName().str());
	
	llvm::Value *contextArrayBasePointer = &function->getArgumentList().front();
	std::string threadSuffix = std::string(".t") + boost::lexical_cast<std::string, int>(threadId);
		
	if (false) {
		std::vector< llvm::Value *> idx;
		idx.push_back(getConstInt32(threadId));
	
		llvm::GetElementPtrInst *contextGemp = llvm::GetElementPtrInst::Create(contextArrayBasePointer,
			llvm::ArrayRef<llvm::Value*>(idx), "contextPtrGemp", block);
	
		local.context = new llvm::LoadInst(contextGemp, "contextPtr" + threadSuffix, block);
	}
	else {
		local.context = contextArrayBasePointer;
	}
	
	report("   structure members");
	
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
			ind.push_back(getConstInt32(0));
			ind.push_back(getConstInt32(idx));
			ind.push_back(getConstInt32(j));
			
			llvm::GetElementPtrInst *ptr = llvm::GetElementPtrInst::Create(local.context, 
				llvm::ArrayRef<llvm::Value*>(ind), "", block);
			
			std::string name = std::string(dim3names[idx]) + "." + dim3suffix[j] + threadSuffix;
			*(dim3Instances[idx * 3 + j]) = new llvm::LoadInst(ptr, name, block);
		}
	}
	
	report("   scalar members");
	
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
		"local", "shared", "const", "param", "argument", "metadata", 
	};
	for (int idx = 0; idx < 6; idx++) {
	
		std::vector< llvm::Value *> ind;
		ind.push_back(getConstInt32(0));
		ind.push_back(getConstInt32(idx + 4));
		
		llvm::GetElementPtrInst *ptr = llvm::GetElementPtrInst::Create(local.context, 
			llvm::ArrayRef<llvm::Value*>(ind), std::string(ptrNames[idx]) + "Ptr" + threadSuffix, block);
		
		*(ptrInstances[idx]) = new llvm::LoadInst(ptr, ptrNames[idx] + threadSuffix, block);
	}
}

void analysis::LLVMUniformVectorization::Translation::_completeSchedulerEntryBlock( ) {
		
	llvm::BitCastInst *bitcastPtr = new llvm::BitCastInst(
		schedulerEntryBlock.threadLocalArguments[0].localPointer, 
		llvm::PointerType::get(llvm::IntegerType::get(context(), 32), 0), 
		"bitcast", schedulerEntryBlock.block);
	llvm::LoadInst *resumePoint = new llvm::LoadInst(bitcastPtr, "resumePoint", schedulerEntryBlock.block);
	
	llvm::SwitchInst *switchInst = llvm::SwitchInst::Create(resumePoint, schedulerEntryBlock.defaultEntry, 
		schedulerEntryBlock.entries.size(), schedulerEntryBlock.block);
	
	unsigned int idx = 0;
	for (EntryMap::const_iterator entry_it = schedulerEntryBlock.entries.begin();
		entry_it != schedulerEntryBlock.entries.end(); ++entry_it, ++idx) {
		
		switchInst->setSuccessor(idx, entry_it->second);
		switchInst->setSuccessorValue(idx, getConstInt32(entry_it->first));
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


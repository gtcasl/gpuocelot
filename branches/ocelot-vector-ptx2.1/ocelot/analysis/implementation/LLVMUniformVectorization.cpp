/*!
	\file LLVMUniformVectorization.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief transformation pass on LLVM functions that performs vectorization for kernels with
			entirely uniform control flow
*/

// C++ includes
#include <vector>
#include <map>
#include <list>
#include <set>

// Ocelot includes
#include <ocelot/analysis/interface/LLVMUniformVectorization.h>

// LLVM includes
#include <llvm/Instructions.h>
#include <llvm/Constants.h>
#include <llvm/Support/raw_ostream.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; throw hydrazine::Exception(ss.str()); }

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

//////////////////////////////////////////////////////////////////////////////////////////////////

char analysis::LLVMUniformVectorization::ID = 127;

std::string operator+(const std::string &str, llvm::Value *value) {
	std::string valStr;
	/*
	llvm::raw_string_ostream os(valStr);
	value->print(os);*/
	return str + valStr;
}

std::ostream &operator<<(std::ostream &out, llvm::Value *value) {
	std::string str;
	llvm::raw_string_ostream os(str);
	value->print(os);
	out << str;
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::WarpScheduler::WarpScheduler():
	start(0),
	end(0)
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::DivergentBranch::DivergentBranch()
:
	scalarBlock(0), warpBlock(0), handler(0) {

}

//! \brief gets a warp-synchronous block from a scalar block
llvm::BasicBlock * analysis::LLVMUniformVectorization::Translation::getWarpBlockFromScalar(
	llvm::BasicBlock *scalarBlock) {

	BasicBlockMap::const_iterator bl_it = warpBlocksMap.find(scalarBlock);
	if (bl_it != warpBlocksMap.end()) {
		return bl_it->second;
	}	
	return 0;
}

//! \brief gets a scalar block corresponding to a warp-synchronous block
llvm::BasicBlock * analysis::LLVMUniformVectorization::Translation::getScalarBlockFromWarp(
	llvm::BasicBlock *warpBlock) {
	
	BasicBlockMap::const_iterator bl_it = warpBlocksMap.begin();
	for (; bl_it != warpBlocksMap.end(); ++bl_it) {
		if (bl_it->second == warpBlock) {
			return bl_it->first;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::DivergentBranch::DivergentBranch(
	llvm::BasicBlock *scBlock, llvm::BasicBlock *wsBlock)
: 
	scalarBlock(scBlock), warpBlock(wsBlock), handler(0) {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::LLVMUniformVectorization(int _warpSize):
	llvm::FunctionPass(ID),
	M(0),
	warpSize(_warpSize)
{

}

analysis::LLVMUniformVectorization::LLVMUniformVectorization(
	const EntryIdBlockLabelMap &_labelMap, int _warpSize):
	llvm::FunctionPass(ID),
	M(0),
	warpSize(_warpSize),
	labelMap(&_labelMap)
{

}

analysis::LLVMUniformVectorization::~LLVMUniformVectorization() {

}


//! \brief gets the name of the pass
const char *analysis::LLVMUniformVectorization::getPassName() const {
	return "Ocelot LLVM Uniform Vectorization";
}

//! \brief gets the kind of tye pass
llvm::PassKind analysis::LLVMUniformVectorization::getPassKind() const {
	return llvm::PT_Function;
}

/*!
	\brief runs the vectorization pass
*/
bool analysis::LLVMUniformVectorization::runOnFunction(llvm::Function &F) {
	if (!M) {
		doInitialize(*F.getParent());
	}
	
	Translation translation(&F, this);	
	translation.runOnFunction();
	
	return true;
}

bool analysis::LLVMUniformVectorization::doInitialize(llvm::Module &_M) {	
	const int w = 32;
	M = &_M;
	{
		std::vector<const llvm::Type *> types;
		types.push_back(getTyInt(w));
		types.push_back(getTyInt(w));
		types.push_back(getTyInt(w));
		tyDimension = llvm::StructType::get(_M.getContext(), types, "tyDimension");
	}
	{
		std::vector<const llvm::Type *> types;
		types.push_back(llvm::PointerType::get(getTyInt(8), 0));
		types.push_back(getTyInt(w));
		types.push_back(getTyInt(w));
		types.push_back(tyDimension);
		tyThreadDescriptor = llvm::StructType::get(_M.getContext(), types, "tyThreadDescriptor");
	}
	{
		std::vector<const llvm::Type *> types;
		types.push_back(getTyInt(w));
		types.push_back(getTyInt(w));
		types.push_back(getTyInt(w));
		types.push_back(getTyInt(w));
		types.push_back(getTyInt(w));
		types.push_back(getTyInt(w));
		types.push_back(llvm::PointerType::get(tyThreadDescriptor, 0));
		tyMetadata = llvm::StructType::get(_M.getContext(), types, "tyMetadata");
	}
	
	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const llvm::IntegerType *analysis::LLVMUniformVectorization::getTyInt(int n) const {
	assert(M);
	return llvm::IntegerType::get(M->getContext(), n);
}

llvm::ConstantInt *analysis::LLVMUniformVectorization::getConstInt32(int n) const {
	return llvm::ConstantInt::get(getTyInt(32), n, true);
}

llvm::ConstantInt *analysis::LLVMUniformVectorization::getConstInt16(short n) const {
	return llvm::ConstantInt::get(getTyInt(16), n, true);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::Translation::Translation(
	llvm::Function *f, 
	LLVMUniformVectorization *_pass
):
	pass(_pass), F(f), warpSize(_pass->warpSize) 
{

}

analysis::LLVMUniformVectorization::Translation::~Translation() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::runOnFunction() {
	
	report("Vectorization: " << F->getNameStr());
	
	// we do not use the translator's scheduler block, so this transformation must insert its own
	if (warpSize >= 1) {
		report("Creating prolog block to replace scheduler");
		createSubkernelPrologue();
		
		report("Loading thread-local values");
//		loadThreadLocalArguments();
	}
	
	// omit these transformations for scalar case
	if (warpSize > 1) {
				
		report("Breadth first traversal:");
		breadthFirstTraversal(traversal, F);
		
		report("Adding interleaved and replicated instructions:");
		addInterleavedInstructions();
				
		report("Updating data dependencies among replicated instructions");
		resolveDependencies();
		
		report("Updating control flow among warp-synchronous replicated blocks");
		resolveControlFlow();
		
		report("Vectorizing replicated instruction bundles");		
		vectorize();
	}
	
	// perform this for all warp sizes including the scalar case
	if (warpSize >= 1) {

		report("Creating scheduler block");
		updateSubkernelEntries();
	
		finalizeSubkernel();
	}
	
	report("end vectorization " << F->getNameStr() << "\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::Translation::breadthFirstTraversal(
	BasicBlockList & traversal, llvm::Function *F) {

	BasicBlockList blockList;
	
	// copy block pointers into a mutable structure
	llvm::Function::BasicBlockListType & llvmBasicBlocks = F->getBasicBlockList();
	for (llvm::Function::BasicBlockListType::iterator bb_it = llvmBasicBlocks.begin();
		bb_it != llvmBasicBlocks.end(); ++bb_it) {
		llvm::BasicBlock *bb = &*bb_it;

		blockList.push_back(bb);
	}

	BasicBlockList workList; 
	std::set< llvm::BasicBlock *> visited;
	
	workList.push_back(blockList.front());
	blockList.pop_front();

	while (traversal.size() != llvmBasicBlocks.size() - 1) {
		llvm::BasicBlock *bb;
		
		if (workList.size()) {
			bb = workList.front();
			workList.pop_front();
		}
		else {
			bb = blockList.front();
			blockList.pop_front();
		}

		if (visited.find(bb) != visited.end()) {
			continue;
		}
		if (!bb) { break; }

		if (bb != subkernelEntry.prologue) {
			traversal.push_back(bb);
		}
		visited.insert(bb);

		llvm::TerminatorInst *termInst = bb->getTerminator();
		for (unsigned int i = 0; i < termInst->getNumSuccessors(); ++i) {
			workList.push_back(termInst->getSuccessor(i));
		}
	}
}

llvm::Value * analysis::LLVMUniformVectorization::Translation::getLocalMemorySize(llvm::Instruction *insertBefore) {
	llvm::Argument & argument = F->getArgumentList().front();
	llvm::Value *argumentValue = &argument;
	const llvm::Type *tyInt32 = llvm::Type::getInt32Ty(F->getParent()->getContext());
	
	std::vector< llvm::Value *> idx;
	idx.push_back(llvm::ConstantInt::get(tyInt32, 0));
	idx.push_back(llvm::ConstantInt::get(tyInt32, 9));
	llvm::Value *metadataPtrPtr = llvm::GetElementPtrInst::Create(argumentValue, 
		idx.begin(), idx.end(), "metadataPtrPtr", insertBefore);
	
	llvm::LoadInst *metadataPtr = new llvm::LoadInst(metadataPtrPtr, "metadataPtrI8", insertBefore);
	llvm::CastInst *sharedSizePtr = llvm::CastInst::CreatePointerCast(metadataPtr, 
		tyInt32->getPointerTo(), "sharedSizePtr", insertBefore);
	llvm::LoadInst *sharedSize = new llvm::LoadInst(sharedSizePtr, "sharedSize", insertBefore);
		
	return sharedSize;
}

llvm::Value * analysis::LLVMUniformVectorization::Translation::getLocalMemoryPointer(
	llvm::Instruction *insertBefore) {
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/
void analysis::LLVMUniformVectorization::Translation::finalizeSubkernel() {
		
	llvm::TerminatorInst *termInst = subkernelEntry.prologue->getTerminator();
	llvm::BasicBlock *wsTarget = getWarpBlockFromScalar(subkernelEntry.start);
	
	assert(llvm::BranchInst::classof(termInst));
	
	llvm::BranchInst *branchInst = static_cast<llvm::BranchInst *>(termInst);
	branchInst->setSuccessor(0, wsTarget);
}
			
/*!
	
*/
void analysis::LLVMUniformVectorization::Translation::createSubkernelPrologue() {

	subkernelEntry.start = & F->front();
	subkernelEntry.prologue = llvm::BasicBlock::Create(F->getContext(), "WarpSynchronousEntry", 
		F, subkernelEntry.start);
	
/*
	llvm::BasicBlock *startBlock = subkernelEntry.start;
	if (!warpSchedulerBlocks.size()) {
		startBlock = getWarpBlockFromScalar(subkernelEntry.start);
	}
	llvm::BranchInst *braInst = llvm::BranchInst::Create(subkernelEntry.start, subkernelEntry.prologue);
	assert(braInst);
	*/
}

/*!
	\brief fetches metadata object and obtains thread local arguments
		(i.e. localMemory pointer, threadIdx.x)
*/
void analysis::LLVMUniformVectorization::Translation::loadThreadLocalArguments() {

	report("loadThreadLocalArguments");
	llvm::Value *context = &*(F->arg_begin());
	
	for (int tid = 0; tid < warpSize; tid++) {
	
		llvm::GetElementPtrInst *contextPtr = 0;
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			//idx.push_back(pass->getConstInt32(0));
			
			ss << "context." << tid;
			contextPtr = llvm::GetElementPtrInst::Create(context, idx.begin(), idx.end(), ss.str(), schedulerBlock);
		}
		
		report("thread " << tid);
		report("localMemPtr");
		
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			idx.push_back(pass->getConstInt32(0));
		
			llvm::Instruction *ptr = llvm::GetElementPtrInst::Create(contextPtr,
				idx.begin(), idx.end(), "ptrLocalMemPtr", schedulerBlock);
		
			ss << "localMemPtr." << tid;
			threadLocalArguments.localPointer.push_back(new llvm::LoadInst(ptr, ss.str(), schedulerBlock));
		}
		report(" tid_x");
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			idx.push_back(pass->getConstInt32(3));
			idx.push_back(pass->getConstInt32(0));
		
			llvm::Instruction *ptr = llvm::GetElementPtrInst::Create(contextPtr,
				idx.begin(), idx.end(), "ptrTidXptr", schedulerBlock);
		
			ss << "tid_x." << tid;
			threadLocalArguments.threadId_x.push_back(new llvm::LoadInst(ptr, ss.str(), schedulerBlock));
		}
		report(" tid_y");
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			idx.push_back(pass->getConstInt32(3));
			idx.push_back(pass->getConstInt32(1));
		
			llvm::Instruction *ptr = llvm::GetElementPtrInst::Create(contextPtr,
				idx.begin(), idx.end(), "ptrTidYptr", schedulerBlock);
		
			ss << "tid_y." << tid;
			threadLocalArguments.threadId_y.push_back(new llvm::LoadInst(ptr, ss.str(), schedulerBlock));
		}
		
		report(" tid_z");
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			idx.push_back(pass->getConstInt32(3));
			idx.push_back(pass->getConstInt32(2));
		
			llvm::Instruction *ptr = llvm::GetElementPtrInst::Create(contextPtr,
				idx.begin(), idx.end(), "ptrTidZptr", schedulerBlock);
		
			ss << "tid_z." << tid;
			threadLocalArguments.threadId_z.push_back(new llvm::LoadInst(ptr, ss.str(), schedulerBlock));
		}
	}
}

#if 0
/*!
	\brief fetches metadata object and obtains thread local arguments
		(i.e. localMemory pointer, threadIdx.x)
*/
void analysis::LLVMUniformVectorization::Translation::loadThreadLocalArguments() {

	report("loadThreadLocalArguments");

	// do this from the start of the subkernel
	llvm::Instruction *firstInst = subkernelEntry.prologue->getFirstNonPHI();
	llvm::Value *context = &*(F->arg_begin());
	
	report("metadata ptr");
	std::vector< llvm::Value *> idx;
	idx.push_back(pass->getConstInt32(0));
	idx.push_back(pass->getConstInt32(9));
	llvm::GetElementPtrInst *gempMetadataPtr = llvm::GetElementPtrInst::Create(context, idx.begin(), 
		idx.end(), "pMetadataPtrI8", firstInst);
	
	llvm::LoadInst *loadedMetadataPtr = new llvm::LoadInst(gempMetadataPtr, "metadataPtrI8", firstInst);
	
	llvm::CastInst *castedMetadataPtr = llvm::CastInst::CreatePointerCast(loadedMetadataPtr, 
		llvm::PointerType::get(pass->tyMetadata,0), "metadataPtr", firstInst );
	
	idx.clear();
	idx.push_back(pass->getConstInt32(0));
	idx.push_back(pass->getConstInt32(6));
		
	llvm::Instruction *threadDescriptorPtr = llvm::GetElementPtrInst::Create(castedMetadataPtr, 
		idx.begin(), idx.end(), "threadDescriptorPtr", firstInst);
	threadLocalArguments.ptrThreadDescriptorArray = new llvm::LoadInst(threadDescriptorPtr,
		"threadDescriptorArray", firstInst);
	
	report("getting thread local values");
	
	for (int tid = 0; tid < warpSize; tid++) {
		llvm::GetElementPtrInst *ptr = 0;
		
		report("thread " << tid);
		report("localMemPtr");
		
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			idx.push_back(pass->getConstInt32(0));
		
			ptr = llvm::GetElementPtrInst::Create(threadLocalArguments.ptrThreadDescriptorArray,
				idx.begin(), idx.end(), "", firstInst);
		
			ss << "localMemPtr." << tid;
			threadLocalArguments.localPointer.push_back(new llvm::LoadInst(ptr, ss.str(), firstInst));
		}
		report(" tid_x");
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			idx.push_back(pass->getConstInt32(3));
			idx.push_back(pass->getConstInt32(0));
		
			ptr = llvm::GetElementPtrInst::Create(threadLocalArguments.ptrThreadDescriptorArray,
				idx.begin(), idx.end(), "", firstInst);
		
			ss << "tid_x." << tid;
			threadLocalArguments.threadId_x.push_back(new llvm::LoadInst(ptr, ss.str(), firstInst));
		}
		report(" tid_y");
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			idx.push_back(pass->getConstInt32(3));
			idx.push_back(pass->getConstInt32(1));
		
			ptr = llvm::GetElementPtrInst::Create(threadLocalArguments.ptrThreadDescriptorArray,
				idx.begin(), idx.end(), "", firstInst);
		
			ss << "tid_y." << tid;
			threadLocalArguments.threadId_y.push_back(new llvm::LoadInst(ptr, ss.str(), firstInst));
		}
		
		report(" tid_z");
		{
			std::stringstream ss;
			std::vector< llvm::Value *> idx;
			idx.push_back(pass->getConstInt32(tid));
			idx.push_back(pass->getConstInt32(3));
			idx.push_back(pass->getConstInt32(2));
		
			ptr = llvm::GetElementPtrInst::Create(threadLocalArguments.ptrThreadDescriptorArray,
				idx.begin(), idx.end(), "", firstInst);
		
			ss << "tid_z." << tid;
			threadLocalArguments.threadId_z.push_back(new llvm::LoadInst(ptr, ss.str(), firstInst));
		}
	}
}
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief 
*/
void analysis::LLVMUniformVectorization::Translation::addInterleavedInstructions() {

	// create blocks	
	llvm::Function::BasicBlockListType & basicBlocks = F->getBasicBlockList();

	for (BasicBlockList::iterator bb_it = traversal.begin(); 
		bb_it != traversal.end(); ++bb_it) {
		
		llvm::BasicBlock *bb = *bb_it;
		if (bb->getNameStr() == "") { continue; }
		
		// ignore ocelot-inserted blocks for fusing thread blocks together
		if (bb->getNameStr().substr(0, 30) == "$__ocelot_remove_barrier_entry") { 
			WarpScheduler warpSched;
			warpSchedulerBlocks[bb] = warpSched;
		}

		// construct a warp-synchronous block
		std::stringstream ss;
		ss << bb->getNameStr() << "_ws_" << warpSize;
		llvm::BasicBlock *warpBlock = llvm::BasicBlock::Create(
			F->getContext(), ss.str(), 0, 0);
		warpBlocksMap[bb] = warpBlock;
	}
	
	for (BasicBlockList::iterator bb_it = traversal.begin(); 
		bb_it != traversal.end(); ++bb_it) {

		llvm::BasicBlock *srcBlock = *bb_it;

		// ignore empty blocks		
		// ignore the warp-scheduler block
		if (srcBlock->getNameStr() == "" || 
			warpSchedulerBlocks.find(srcBlock) != warpSchedulerBlocks.end()) {
			continue;
		}

		llvm::BasicBlock *warpBlock = warpBlocksMap[srcBlock];
		llvm::BasicBlock::InstListType & instList = warpBlock->getInstList();

		for (llvm::BasicBlock::iterator inst_it = srcBlock->begin(); inst_it != srcBlock->end(); 
			++inst_it) {

			if (llvm::Instruction::isTerminator(inst_it->getOpcode())) {
				// if instruction is control flow, don't replicate
			}
			else {
				// insert into the mapping so dependent instructions get the correct value
				// else, replicate over all threads in warp
				for (int tid = 0; tid < warpSize; tid++) {
					// clone instruction
					llvm::Instruction *instr = inst_it->clone();
					std::stringstream newName;
					newName << std::string(inst_it->getName()) << ".t" << tid;
					if (!instr->getType()->isVoidTy()) {
						instr->setName(newName.str());
					}
					instList.push_back(instr);

					warpInstructionMap[(&*inst_it)].replicated.push_back(instr);
					
					if (llvm::GetElementPtrInst *ptrInst = llvm::dyn_cast<llvm::GetElementPtrInst>(instr)) {
						if (ptrInst->getPointerOperand()->getNameStr() == "__ctaContext") {
							ptrInst->setOperand(1, pass->getConstInt32(tid));
						}
					}
				}
			}
		}

		// insert a dummy terminator
		llvm::ReturnInst::Create(F->getContext(), 0, warpBlock);	
		basicBlocks.push_back(warpBlock);
	}
}

/*!
	\brief visits all cloned instructions and resolves dependencies
*/
void analysis::LLVMUniformVectorization::Translation::resolveDependencies() {
	
	for (BasicBlockList::iterator bb_it = traversal.begin(); 
		bb_it != traversal.end(); ++bb_it) {

		llvm::BasicBlock *srcBlock = *bb_it;
		
		// ignore empty blocks		
		// ignore the warp-scheduler block
		if (srcBlock->getNameStr() == "" ||
			warpSchedulerBlocks.find(srcBlock) != warpSchedulerBlocks.end()) {
			continue;
		}

		for (llvm::BasicBlock::iterator inst_it = srcBlock->begin(); inst_it != srcBlock->end(); 
			++inst_it) {

			if (llvm::Instruction::isTerminator(inst_it->getOpcode())) {
				// if instruction is control flow, don't replicate
			}
			else {
				// insert into the mapping so dependent instructions get the correct value
				// else, replicate over all threads in warp
				llvm::Instruction *scalarInst = &*inst_it;
				
				for (int tid = 0; tid < warpSize; tid++) {
					// clone instruction
					if (warpInstructionMap.find(scalarInst) == warpInstructionMap.end()) {
						break;
					}
					
					llvm::Instruction *instr = warpInstructionMap[scalarInst].replicated[tid];
					updateDependencies(instr, tid);		
				}
			}
		}
	}
}

/*!

*/
void analysis::LLVMUniformVectorization::Translation::updateThreadLocalUses() {

	for (WarpInstructionMap::iterator warp_it = warpInstructionMap.begin();
		warp_it != warpInstructionMap.end(); ++warp_it) {
			
		if (llvm::GetElementPtrInst::classof(warp_it->first)) {
			llvm::GetElementPtrInst *scalarInst = static_cast<llvm::GetElementPtrInst *>(warp_it->first);
			
			if (scalarInst->getPointerOperand()->getNameStr() != "__ctaContext") {
				continue;
			}
			
			int indices[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
			for (unsigned int idx = 1; idx < scalarInst->getNumOperands() && idx < 8; idx++) {
			
				if (llvm::ConstantInt::classof(scalarInst->getOperand(idx))) {
					llvm::ConstantInt *constInt = static_cast<llvm::ConstantInt *>(
						scalarInst->getOperand(idx));
					
					indices[idx] = (int)constInt->getZExtValue();
				}
			}
			
			if (indices[1] == 0 && (indices[2] == 0 || indices[2] == 4)) {
				int selector = (indices[2] == 0 ? indices[3] : 3);
				ThreadLocalArgument::ThreadLocalArgumentVector ThreadLocalArgument::*threadId[] = {
					&ThreadLocalArgument::threadId_x,
					&ThreadLocalArgument::threadId_y,
					&ThreadLocalArgument::threadId_z,
					&ThreadLocalArgument::localPointer
				};
			
				for (llvm::Value::use_iterator use_it = scalarInst->use_begin(); 
					use_it != scalarInst->use_end(); ++use_it) {
					
					WarpInstructionMap::iterator warp_it = warpInstructionMap.find(*use_it);
					
					assert(warp_it != warpInstructionMap.end());
						
					for (int tid = 0; tid < warpSize; tid++) {
						llvm::Instruction *loadedValue = (threadLocalArguments.*threadId[selector])[tid];
	
						warp_it->second.replicated[tid]->replaceAllUsesWith(loadedValue);
						warp_it->second.replicated[tid]->removeFromParent();
						
						warpInstructionMap[scalarInst].replicated[tid]->removeFromParent();
					}
					warpInstructionMap.erase(warp_it);
				}
				warpInstructionMap.erase(warpInstructionMap.find(scalarInst));
				scalarInst->removeFromParent();
			}
		}
	}
}

/*!
	\brief update dependencies to other instructions in the logical thread
	
	\param translation translation object
	\param instr cloned instruction
	\param tid thread ID within warp to which cloned instruction belongs
*/	
void analysis::LLVMUniformVectorization::Translation::updateDependencies(
	llvm::Instruction *instr, int tid) {
		
	for (unsigned int i = 0; i < instr->getNumOperands(); ++i) {
		llvm::Value *operand = instr->getOperand(i);
		
		if (llvm::BasicBlock::classof(operand)) {
			instr->setOperand(i, getWarpBlockFromScalar(
				static_cast<llvm::BasicBlock *>(operand)));
		}
		else if (llvm::Instruction::classof(operand)) {
			WarpInstructionMap::iterator op_it = warpInstructionMap.find(operand);
			
			if (op_it != warpInstructionMap.end()) {
				instr->setOperand(i, op_it->second.replicated[tid]);
			}
			else if (llvm::PHINode::classof(operand)) {
				// update phi nodes
				llvm::PHINode *phiNode = static_cast<llvm::PHINode *>(operand);
				llvm::PHINode *phiClone = llvm::PHINode::Create(phiNode->getType(), 
					phiNode->getNameStr(), instr);
				
				for (unsigned int j = 0; j < phiNode->getNumIncomingValues(); ++j) {
					op_it = warpInstructionMap.find(phiNode->getIncomingValue(j));
					if (op_it != warpInstructionMap.end()) {
						llvm::Value *incoming = op_it->second.replicated[tid];
						if (llvm::Instruction::classof(incoming)) {
							llvm::BasicBlock *scalar = static_cast<llvm::Instruction*>(incoming)->getParent();
							llvm::BasicBlock *warpBlock = getWarpBlockFromScalar(scalar);
							if (!warpBlock) {
								warpBlock = scalar;
							}
							phiClone->addIncoming(incoming, warpBlock );
						}
						else {
							// why does this happen
							phiNode->dump();
							
							Ocelot_Exception("PHI NODE operand present but not an instruction (op " << j << ")");
						}
					}
					else {
							// why does this happen
						std::cerr << "operand " << j << ": ";
						phiNode->getIncomingValue(j)->dump();
						Ocelot_Exception("PHI NODE operand not present (operand " << j << ")");
					}
				}
				instr->setOperand(i, phiClone);
			}
			else {
				// problem
				operand->getType()->dump();
				operand->dump();
				Ocelot_Exception("undefined operand encountered");
			}
		}
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief replace dummy terminators in warp-synchronous block structure with
		tests for warp-synchronous behavior and either branches to successor blocks
		or returns to Ocelot multicore runtime
*/
void analysis::LLVMUniformVectorization::Translation::resolveControlFlow() {
		
	for (BasicBlockMap::iterator bb_it = warpBlocksMap.begin();
		bb_it != warpBlocksMap.end(); ++bb_it) {
		
		if (warpSchedulerBlocks.find(bb_it->first) != warpSchedulerBlocks.end()) {
			continue;
		}
		
		llvm::TerminatorInst *termInst = static_cast<llvm::TerminatorInst *>(
			bb_it->first->getTerminator());
		
		if (llvm::BranchInst::classof(termInst)) {
			llvm::BranchInst *braInst = static_cast<llvm::BranchInst *>(termInst);
			if (braInst->isConditional()) {
				llvm::Value *condition = braInst->getCondition();
				if (llvm::Constant::classof(condition)) {
					// constant expressions are warp synchronous
					llvm::BranchInst *clonedBr = static_cast<llvm::BranchInst *>(braInst->clone());
					for (unsigned int n = 0; n < clonedBr->getNumSuccessors(); n++) {
						clonedBr->setSuccessor(n, warpBlocksMap[clonedBr->getSuccessor(n)]);
					}
					bb_it->second->getTerminator()->eraseFromParent(); // erase dummy
					bb_it->second->getInstList().push_back(clonedBr);
				}
				else {
					// potentially divergent branch - add to map for subsequent handling
					divergingBranchMap[bb_it->second] = DivergentBranch(bb_it->first, bb_it->second);
				}
			}
			else if (braInst->isUnconditional()) {
				// erase dummy terminator
				bb_it->second->getTerminator()->eraseFromParent();
				
				// insert uniform branch to successor
				llvm::BasicBlock *succ = warpBlocksMap[braInst->getSuccessor(0)];
				llvm::BranchInst::Create(succ, bb_it->second);
			}
			else {
				// how is this possible?
				Ocelot_Exception("branch instruction is neither conditional nor uncondional");
			}
		}
		else if (llvm::ReturnInst::classof(termInst)) {
			llvm::Instruction *clonedInst = termInst->clone();
			bb_it->second->getTerminator()->eraseFromParent();	// erase dummy
			bb_it->second->getInstList().push_back(clonedInst);
		}
		else {
			// what othe rkind of terminators are there?
			Ocelot_Exception("unexpected terminator of type " << termInst->getNameStr() 
				<< " encountered");
		}
	}
	
	// insert handling code for potentially diverging branches
	for (DivergentBranchMap::iterator div_br_it = divergingBranchMap.begin();
		div_br_it != divergingBranchMap.end(); ++div_br_it) {
		handleDivergentBranch(div_br_it->second);
	}
}

/*!
	\brief deals with a particular divergent branch
*/
void analysis::LLVMUniformVectorization::Translation::handleDivergentBranch(
	DivergentBranch &divergent) {
	
	// we only know how to handle 1-bit integer conditions
	llvm::TerminatorInst *scTerm = divergent.scalarBlock->getTerminator();
	if (llvm::BranchInst::classof(scTerm)) {
		llvm::BranchInst *scBranch = static_cast<llvm::BranchInst*>(scTerm);
		llvm::Value *condition = scBranch->getCondition();
		if (!condition->getType()->isIntegerTy(1)) {
			Ocelot_Exception("condition was expected to be of type integer-1");
		}
	
		WarpInstructionMap::iterator ws_it = warpInstructionMap.find(condition);
		if (ws_it == warpInstructionMap.end()) {
			Ocelot_Exception("divergent branch condition does not appear in the warp instruction map");
		}
		
		divergent.warpBlock->getTerminator()->removeFromParent();	 // remove dummy
		
		// construct reduction
		const llvm::Type *intTy = pass->getTyInt(32);
		llvm::Instruction *branchConditional = new llvm::ZExtInst(ws_it->second.replicated[0], intTy, "condZ", 
			divergent.warpBlock);
		
		// insert reduction code 
		for (int n = 1; n < warpSize; n++) {
			/*
			llvm::BinaryOperator *shlOp = llvm::BinaryOperator::Create(llvm::Instruction::Shl, branchConditional, 
				constOne, "condZsl", divergent.warpBlock);
			llvm::Instruction *cmpInt16 = new llvm::ZExtInst(ws_it->second.replicated[n], int16ty, "cmpws",
				divergent.warpBlock);
			branchConditional = llvm::BinaryOperator::Create(llvm::Instruction::Or, shlOp, cmpInt16, "condZ", 
				divergent.warpBlock);
			*/
			llvm::Instruction *cmpInt16 = new llvm::ZExtInst(ws_it->second.replicated[n], intTy, "cmpws",
				divergent.warpBlock);
			branchConditional = llvm::BinaryOperator::Create(llvm::Instruction::Add, branchConditional, cmpInt16, "cmpws", divergent.warpBlock);
		}
		
		// if branchConditional is 0, all conditions were 0s. if z is (warpSize), all conditions were 1
		// else, diverge!

		llvm::ConstantInt *constZero = pass->getConstInt32(0);
		llvm::ConstantInt *constFull = pass->getConstInt32(warpSize);
		
#if 0
		std::stringstream ss;
		ss << divergent.warpBlock->getNameStr() << "_diverge";		
		divergent.handler = llvm::BasicBlock::Create(F->getContext(), ss.str(), F);
		
		// insert dummy return statement
		llvm::ReturnInst::Create(F->getContext(), divergent.handler);
		
		// and insert a call to abort on divergence
		divergenceHandlerBranch(divergent, ws_it->second);
#else
		// find the existing divergence handler by convention
		std::stringstream suffix;
		suffix << "_exit_ws_" << warpSize;
		std::string divergenceHandlerLabel = divergent.scalarBlock->getNameStr() + suffix.str();
		divergent.handler = 0;
		for (llvm::Function::iterator bb_it = F->begin(); bb_it != F->end(); ++bb_it) {
			if (bb_it->getNameStr() == divergenceHandlerLabel) {
				divergent.handler = &*bb_it;
				break;
			}
		}
		assert(divergent.handler && "Failed in finding existing divergence handler");
		
#endif
			
		llvm::BasicBlock *succZero = warpBlocksMap[scBranch->getSuccessor(1)];
		llvm::BasicBlock *succFull = warpBlocksMap[scBranch->getSuccessor(0)];
		
		llvm::SwitchInst *switchInst = llvm::SwitchInst::Create(
			branchConditional, divergent.handler, 2, divergent.warpBlock);
		switchInst->addCase(constFull, succFull);
		switchInst->addCase(constZero, succZero);
		
	}
	else {
		Ocelot_Exception("unexpected divergent terminator");
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief emit spill code or handler for a branch known to be divergent
*/
void analysis::LLVMUniformVectorization::Translation::divergenceHandlerBranch(
	DivergentBranch &divergent, 
	VectorizedInstruction &condition) {

	// trap to host environment on reaching a divergent region
	std::vector< const llvm::Type *> argTypes;
	argTypes.push_back(pass->getTyInt(32));
	argTypes.push_back(pass->getTyInt(32));
	llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(
		F->getParent()->getContext()), argTypes, false);
		
	std::vector< llvm::Value *> args;
	args.push_back(pass->getConstInt32(1));
	args.push_back(pass->getConstInt32(0));
	llvm::CallInst::Create(F->getParent()->getOrInsertFunction("__ocelot_abort", funcType), 
		args.begin(), args.end(), "", divergent.handler->getTerminator());
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief inserts a schedular block that handles control flow
*/
void analysis::LLVMUniformVectorization::Translation::createSchedulerBlock() {
	llvm::BasicBlock *entry = & F->front();
	schedulerBlock = llvm::BasicBlock::Create(F->getContext(), "WarpSyncScheduler", F, entry);
	
	// for now, have scheduler block chain to previous entry point
	llvm::BasicBlock *startBlock = entry;
	if (!warpSchedulerBlocks.size()) {
		startBlock = getWarpBlockFromScalar(entry);
	}
	llvm::BranchInst *braInst = llvm::BranchInst::Create(startBlock, schedulerBlock);
	assert(braInst);
}

/*
	\brief visits each of the warp scheduler blocks and changes control flow to point
		to warp-synchronous regions
*/
void analysis::LLVMUniformVectorization::Translation::updateSchedulerBlocks() {
	WarpSchedulerMap::const_iterator ws_it = warpSchedulerBlocks.begin();
	for (; ws_it != warpSchedulerBlocks.end(); ++ws_it) {
		llvm::BasicBlock *scalar = ws_it->first;
		llvm::TerminatorInst *termInst = scalar->getTerminator();

		if (llvm::BranchInst::classof(termInst)) {
			llvm::BranchInst *braInst = static_cast<llvm::BranchInst *>(termInst);
			for (unsigned int i = 0; i < braInst->getNumSuccessors(); i++) {
				if (warpSchedulerBlocks.find(braInst->getSuccessor(i)) ==
					warpSchedulerBlocks.end()) {

					llvm::BasicBlock *wsBlock = getWarpBlockFromScalar(braInst->getSuccessor(i));
					braInst->setSuccessor(i, wsBlock);
				}
			}
		}
		else {
			throw hydrazine::Exception("updateSchedulerBlock() - expected terminator to be branch instruction");
		}		
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief prints a .dot file of the function's control flow graph - no instrucitons, just bb labels
*/
void analysis::LLVMUniformVectorization::Translation::debugEmitCFG() {
	std::ostream & out = std::cout;
	
	std::map< llvm::BasicBlock *, int > blockMap;
	
	out << " digraph G {\n";
	
	int bbn = 1;
	for (llvm::Function::iterator bb_it = F->begin(); 
		bb_it != F->end(); ++bb_it) {
		llvm::BasicBlock *block = &*bb_it;
		
		out << "  bb_" << bbn << " [label=\"" << std::string(block->getName()) << "\"]\n";
		blockMap[block] = bbn;
		++bbn;
	}
	
	bbn = 1;
	int errors = 1;
	for (llvm::Function::iterator bb_it = F->begin(); 
		bb_it != F->end(); ++bb_it) {
		llvm::BasicBlock *block = &*bb_it;
		llvm::TerminatorInst *terminator = block->getTerminator();
		
		for (unsigned int i = 0; i < terminator->getNumSuccessors(); ++i) {
			llvm::BasicBlock *succ = terminator->getSuccessor(i);
			if (blockMap.find(succ) != blockMap.end()) {
				out << "  bb_" << blockMap[block] << " -> bb_" 
					<< blockMap[succ] << ";\n";
			}
			else {
				std::cerr << "bad terminator in block " << std::string(block->getName()) << ":" << std::endl;
				terminator->dump();
				std::cerr << std::endl;
				
				out << "  bb_error_" << (errors) << " [label=\"" << std::string(block->getName()) <<
					" - successor " << i << " not found\"];\n";
				out << "  bb_" << blockMap[block] << " -> bb_error_" << errors << ";\n";
				++errors;
			}
		}
	}
	
	out << "}\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////

bool analysis::LLVMUniformVectorization::VectorizedInstruction::isVectorizable() const {
	if (replicated.size()) {
		llvm::Instruction *inst = replicated[0];
		bool isFloatOrDouble = inst->getType()->isFloatTy() || inst->getType()->isDoubleTy();
		bool isVectorizableBaseType = (isFloatOrDouble);
		
		if (isVectorizableBaseType) {
			if (llvm::BinaryOperator::classof(inst)) {
				return true;
			}
			else if (llvm::PHINode::classof(inst)) {
				return true;
			}
			else if (llvm::CallInst *callInst = llvm::dyn_cast<llvm::CallInst>(inst)) {
				// it's probably vectorizable
				const char *str[] = {
					"__ocelot_sqrtf",
					"__ocelot_sinf",
					"__ocelot_cosf",
					"llvm.sqrt.f32",
					"llvm.sin.f32",
					"llvm.cos.f32f",
					0, 0
				};

				std::string calleeName = callInst->getCalledFunction()->getNameStr();
				for (int n = 0; str[n]; n++) {
					if (str[n] == calleeName) {
						return true;
					}
				}
			}
		}
	}
	return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief given an instruction from the scalar set, get a set of scalar values that are 
	either replicated scalar instructions from the vectorized set or extracted vector elements */
analysis::LLVMUniformVectorization::InstructionVector 
	analysis::LLVMUniformVectorization::Translation::getInstructionAsReplicated(
		llvm::Value *inst, llvm::Instruction *before) {

	WarpInstructionMap::iterator ws_it = warpInstructionMap.find(inst);
	if (ws_it == warpInstructionMap.end()) {
		throw hydrazine::Exception(std::string("getInstructionAsReplicated() - instruction ") + inst + 
			" not in warpTranslationMap");
	}

	InstructionVector replicated;

	return replicated;
}

/*! \brief given an instruction from the scalar set, get a vector from the vectorized set that
	is either a promoted-to-vector instruction or a set of scalar values packed into a vector*/
llvm::Instruction *analysis::LLVMUniformVectorization::Translation::getInstructionAsVectorized(
	llvm::Value *inst, llvm::Instruction *before) {

	const llvm::Type *tyInt32 = llvm::Type::getInt32Ty(F->getContext());
	llvm::Instruction *vectorInstruction = 0;

	llvm::Instruction *instruction = llvm::dyn_cast<llvm::Instruction>(inst);
	llvm::Constant *constant = llvm::dyn_cast<llvm::Constant>(inst);
	if (instruction) {
		WarpInstructionMap::iterator ws_it = warpInstructionMap.find(inst);
		if (ws_it == warpInstructionMap.end()) {

			throw hydrazine::Exception(std::string("getInstructionAsVectorized() - instruction ") + inst + 
				" not in warpTranslationMap");
		}
		if (!ws_it->second.vector) {			
			vectorize(instruction);
			ws_it = warpInstructionMap.find(inst);
			
		}
		vectorInstruction = ws_it->second.vector;
	}
	else if (constant) {
		// it's a constant, so pack it into a vector
				// it's already replicated, so pack into a vector
		llvm::VectorType *vecType = llvm::VectorType::get(inst->getType(), warpSize);
		llvm::Value *vectorValue = llvm::UndefValue::get(vecType);
		for (int tid = 0; tid < warpSize; tid++) {
			llvm::Constant *idx = llvm::ConstantInt::get(tyInt32, tid);
			vectorValue = llvm::InsertElementInst::Create(vectorValue, 
				constant, idx, "", before);
		}
		vectorInstruction = static_cast<llvm::Instruction*>(vectorValue);
	}
	else {
		throw hydrazine::Exception("Failed to get instruction as vector type");
	}

	assert(vectorInstruction);

	return vectorInstruction;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief visit an instruction and either promotes to vector, or packs results into a vector
*/
void analysis::LLVMUniformVectorization::Translation::vectorize(llvm::Instruction *inst) {
	WarpInstructionMap::iterator ws_it = warpInstructionMap.find(inst);
	if (ws_it == warpInstructionMap.end()) {
		return;
		throw hydrazine::Exception(std::string("getInstructionAsVectorized() - instruction ") + inst + 
			" not in warpTranslationMap");
	}

	if (ws_it->second.vector) {
		return;
	}
	if (llvm::TerminatorInst::classof(inst)) {
		return;
	}

	llvm::Instruction *before = 0; // TODO - it seems like LLVM should have a good way of inserting
																	//	an instruction AFTER another instruction

	// this is terrible, I know. 
	llvm::Instruction *after = ws_it->second.replicated[warpSize - 1];
	llvm::BasicBlock *block = after->getParent();
	llvm::BasicBlock::iterator inst_it = block->begin();
	bool found = false;
	
	for (; llvm::PHINode::classof(&*inst_it); ++inst_it) { }

	if (!llvm::PHINode::classof(after)) {
		for (; inst_it != block->end(); ++inst_it) {
			if (&*inst_it == after) {
				++inst_it;
				assert(inst_it != block->end());
				found = true;
				before = &*inst_it;
				break;
			}
		}
	}
	else {
		before = &*inst_it;
		found = true;
	}

	assert(found && before);
	const llvm::Type *tyInt32 = llvm::Type::getInt32Ty(F->getContext());
	
	if (ws_it->second.isVectorizable()) {
		if (llvm::BinaryOperator *binOp = llvm::dyn_cast<llvm::BinaryOperator>(inst)) {
			vectorizeBinaryOperator(binOp, ws_it->second, before);
		}
		else if (llvm::CallInst *callInst = llvm::dyn_cast<llvm::CallInst>(inst)) {
			vectorizeCall(callInst, ws_it->second, before);
		}
		else if (llvm::PHINode *phiNode = llvm::dyn_cast<llvm::PHINode>(inst)) {
			vectorizePhiNode(phiNode, ws_it->second, before);
		}
		else {
			throw hydrazine::Exception("Unhandled vectorizable LLVM instruction");
		}

		InstructionVector extracted;
		for (int tid = 0; tid < warpSize; tid++) {
			llvm::Constant *idx = llvm::ConstantInt::get(tyInt32, tid);
			llvm::Instruction *element = llvm::ExtractElementInst::Create(ws_it->second.vector, 
				idx, "", before);
			extracted.push_back(element);
		}

		// update uses
		for (int tid = 0; tid < warpSize; tid++) {
			ws_it->second.replicated[tid]->replaceAllUsesWith(extracted[tid]);
			ws_it->second.replicated[tid]->eraseFromParent();
		}
		ws_it->second.replicated = extracted;
	}
	else {
		const llvm::Type *instType = inst->getType();
		if (!llvm::SequentialType::classof(instType) && !instType->isVoidTy()) {

			// it's already replicated, so pack into a vector
			llvm::VectorType *vecType = llvm::VectorType::get(inst->getType(), warpSize);
			llvm::Value *vectorValue = llvm::UndefValue::get(vecType);
			for (int tid = 0; tid < warpSize; tid++) {
				llvm::Constant *idx = llvm::ConstantInt::get(tyInt32, tid);
				vectorValue = llvm::InsertElementInst::Create(vectorValue, 
					ws_it->second.replicated[tid], idx, "", before);
			}
			ws_it->second.vector = static_cast<llvm::Instruction *>(vectorValue);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/
void analysis::LLVMUniformVectorization::Translation::vectorizeBinaryOperator(
	llvm::BinaryOperator *binOp, 
	VectorizedInstruction &vecInstr, 
	llvm::Instruction *before) {

	InstructionVector operands;
	for (unsigned int op = 0; op < binOp->getNumOperands(); ++op) {
		operands.push_back(getInstructionAsVectorized(binOp->getOperand(op), before));
	}
	llvm::BinaryOperator *vecOp = llvm::BinaryOperator::Create(binOp->getOpcode(), 
		operands[0], operands[1], "", before);
	vecInstr.vector = vecOp;
}

/*!

*/
void analysis::LLVMUniformVectorization::Translation::vectorizeCall(
	llvm::CallInst *callInst, 
	VectorizedInstruction &vecInstr, 
	llvm::Instruction *before) {
	
	// it's a call instruction
	std::string calleeName = callInst->getCalledFunction()->getNameStr();

	report(" call instruction: " << calleeName);

	assert(hydrazine::isPowerOfTwo(warpSize) && 
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
				if ((1 << s) == warpSize) {
					break;
				}
			}
			assert((1 << s) == warpSize);
			std::string destName = std::string(str[n+1]) + "." + floatSuffixes[s];
			funcIntrinsic = F->getParent()->getFunction(destName);
			if (!funcIntrinsic) {
				report("creating intrinsic type " << calleeName);
				llvm::VectorType *vecType = llvm::VectorType::get(callInst->getType(), warpSize);
				std::vector< const llvm::Type *> args;
				args.push_back(vecType);
				llvm::FunctionType *funcType = llvm::FunctionType::get(vecType, args, false);
				funcIntrinsic = llvm::Function::Create(funcType, 
					llvm::GlobalValue::ExternalLinkage, destName, F->getParent());
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
	
	report("  vectorizing call to function type " << funcIntrinsic << " with " << args.size() << " arguments");
	
	llvm::CallInst *vecCallInst = llvm::CallInst::Create(funcIntrinsic, args.begin(), args.end(), "", before);
	vecInstr.vector = vecCallInst;
}

/*!

*/
void analysis::LLVMUniformVectorization::Translation::vectorizePhiNode(
	llvm::PHINode *phiNode, 
	VectorizedInstruction &vecInstr, 
	llvm::Instruction *before) {

	report("vectorizingPhiNode " << phiNode->getNameStr() 
		<< " - vector instruction to appear in block " << before->getParent()->getNameStr() 
		<< " before \"" << before->getNameStr() << "\"");

	// phi nodes are special little creatures
	std::string s = phiNode->getNameStr() + ".vec";
	llvm::VectorType *vecType = llvm::VectorType::get(phiNode->getType(), warpSize);
	llvm::PHINode *vecPhi = llvm::PHINode::Create(vecType, s, before);
	
	vecInstr.vector = vecPhi;
	
	unsigned int numPreds = phiNode->getNumIncomingValues();
	for (unsigned int i = 0; i < numPreds; i++) {
		if (phiNode->getIncomingValue(i) == phiNode) {
			vecPhi->addIncoming(vecPhi, before->getParent());
		}
		else {
			llvm::BasicBlock *incomingBlock = warpBlocksMap[phiNode->getIncomingBlock(i)];
			vecPhi->addIncoming(
				getInstructionAsVectorized(
					phiNode->getIncomingValue(i), 
					incomingBlock->getTerminator()),
				incomingBlock);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
/*!
	\brief this could probably be implemented as a second function pass, but examine
		collections of instructions of size <warpSize>, hoist or sink instructions, and
		make into vectors for vector processing
*/
void analysis::LLVMUniformVectorization::Translation::vectorize() {

	report("vectorize(translation)");

	for (BasicBlockList::iterator bb_it = traversal.begin(); 
		bb_it != traversal.end(); ++bb_it) {
		llvm::BasicBlock *block = *bb_it;

		report("  vectorizing block " << block->getNameStr());
		
		for (llvm::BasicBlock::iterator inst_it = block->begin(); inst_it != block->end(); ++inst_it) {
			report("  vectorizing scalar instruction " << &*inst_it);
		
			vectorize(&*inst_it);
		}		
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief creates a scheduler block in 'WarpSynchronousEntry' with an indirect branch to each
		subkernel entry point
*/
void analysis::LLVMUniformVectorization::Translation::updateSubkernelEntries() {
	report("Updating subkernel entries");
	
	assert(schedulerBlock);
	assert(threadLocalArguments.localPointer.size());
	assert(threadLocalArguments.localPointer[0]);
	
	std::cerr << "local pointer:\n";
	threadLocalArguments.localPointer[0]->dump();
	threadLocalArguments.localPointer[0]->getType()->dump();
	
	std::cerr << "\n.. creating gemp" << std::endl;
	// get the warp entry ID from one of the thread's resume point
	const llvm::IntegerType *int32Ty = pass->getTyInt(32);
	std::vector<llvm::Value *> idx;
	idx.push_back(llvm::ConstantInt::get(int32Ty, 4));
	llvm::GetElementPtrInst *gempInst = llvm::GetElementPtrInst::Create(
		threadLocalArguments.localPointer[0], 
		idx.begin(),
		idx.end(),
		"ptr", 
		schedulerBlock);
	
	report("created GEMP");
	
	llvm::CastInst *castInst = llvm::CastInst::CreatePointerCast(gempInst, 
		llvm::PointerType::get(int32Ty, 0), "ptrEntryPoint", schedulerBlock);
	llvm::LoadInst *loadedEntryId = new llvm::LoadInst(castInst, "warpEntryId", schedulerBlock);
	llvm::BinaryOperator *warpEntryId = llvm::BinaryOperator::Create(llvm::Instruction::And, 
		loadedEntryId, llvm::ConstantInt::get(int32Ty, 0x0ffff), "warpEntryPoint", schedulerBlock );
	assert(warpEntryId);
	
	report("counting indirect branch successors");
	
	// construct an indirect branch to the entry points
	unsigned int maxEntries = 0;
	for (EntryIdBlockLabelMap::const_iterator entry_it = pass->labelMap->begin();
		entry_it != pass->labelMap->end();
		++entry_it) {
		if (maxEntries < (entry_it->first & 0x0ffff)) {
			maxEntries = (entry_it->first & 0x0ffff);
		}
	}
	maxEntries ++;
	
	report("setting indirect branch successors");
		
	llvm::IndirectBrInst *indirectBr = llvm::IndirectBrInst::Create(warpEntryId, 
		maxEntries, schedulerBlock);
	for (EntryIdBlockLabelMap::const_iterator entry_it = pass->labelMap->begin();
		entry_it != pass->labelMap->end();
		++entry_it) {
		
		unsigned int entryId = (unsigned int)(entry_it->first & 0x0ffff);
		EntryIdBlockLabelMap::const_iterator entryLabel_it = pass->labelMap->find(entryId);
		assert(entryLabel_it != pass->labelMap->end());
		
		llvm::BasicBlock *successor = 0;
		std::string label = entryLabel_it->second;
		assert(successor);
		indirectBr->setSuccessor(entryId, successor);
	}
}

/*!
	\brief visits all subkernel exits
*/
void analysis::LLVMUniformVectorization::Translation::updateSubkernelExits() {
	for (BasicBlockMap::const_iterator ws_bb_it = warpBlocksMap.begin(); 
		ws_bb_it != warpBlocksMap.end(); ++ws_bb_it) {
		
		llvm::BasicBlock * const wsBlock = ws_bb_it->second;
		for (llvm::BasicBlock::iterator inst_it = wsBlock->begin(); inst_it != wsBlock->end(); 
			++inst_it) {
			if (llvm::BitCastInst *castInst = llvm::dyn_cast<llvm::BitCastInst>(&*inst_it)) {
				// bitcast i8* to i32*
				// source is localMemPtr
				// user of bitcast instruction is a store instruction
				// store source value is a constant integer
				//
				const llvm::Type *sourceType = castInst->getOperand(0)->getType();
				const llvm::Type *destType = castInst->getType();
				
				const llvm::Type *sourceElementType = 0;
				const llvm::Type *destElementType = 0;

				if (sourceType->isPointerTy() && 
					(sourceElementType = static_cast<const llvm::PointerType *>(sourceType)->getElementType())
						->isIntegerTy(8) && 
					destType->isPointerTy() &&
						(destElementType = static_cast<const llvm::PointerType *>(destType)->getElementType())
						->isIntegerTy(32)) {
					
					for (ThreadLocalArgument::ThreadLocalArgumentVector::const_iterator 
						localMemPtr_it = threadLocalArguments.localPointer.begin();
						localMemPtr_it != threadLocalArguments.localPointer.end(); ++localMemPtr_it) {
						
						if (static_cast<const llvm::Value *>(*localMemPtr_it) == castInst->getOperand(0)) {
							// if all users are in this block and store constants
							for (llvm::Value::use_iterator use_it = castInst->use_begin(); 
								use_it != castInst->use_end(); ++use_it) {
								
								if (llvm::StoreInst *storeInst = llvm::dyn_cast<llvm::StoreInst>(*use_it)) {
									assert(storeInst);
								}
							}
						}
					}
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////


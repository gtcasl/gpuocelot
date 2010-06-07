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

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define Ocelot_Exception(x) { std::stringstream ss; ss << x; throw hydrazine::Exception(ss.str()); }

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::WarpScheduler::WarpScheduler():
	start(0),
	end(0)
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::Translation::~Translation() {

}

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
	llvm::FunctionPass(this),
	warpSize(_warpSize)
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
	\brief
*/
bool analysis::LLVMUniformVectorization::runOnFunction(llvm::Function &F) {

	addWarpSynchronous(F);
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////


void analysis::LLVMUniformVectorization::addWarpSynchronous(llvm::Function &F) {
	Translation translation(&F);
	
	breadthFirstTraversal(translation.traversal, translation.F);
	addInterleavedInstructions(translation);
	resolveControlFlow(translation);
	createSchedulerBlock(translation);
	updateSchedulerBlocks(translation);
	
	// debugging
	translation.F->getParent()->dump();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::LLVMUniformVectorization::breadthFirstTraversal(
	BasicBlockList & traversal, llvm::Function *F) {

	BasicBlockList blockList;
	
	// copy block pointers into a mutable structure
	llvm::Function::BasicBlockListType & llvmBasicBlocks = F->getBasicBlockList();
	for (llvm::Function::BasicBlockListType::iterator bb_it = llvmBasicBlocks.begin();
		bb_it != llvmBasicBlocks.end(); ++bb_it) {
		blockList.push_back(&*bb_it);
	}

	BasicBlockList workList; 
	std::set< llvm::BasicBlock *> visited;
	
	workList.push_back(blockList.front());
	blockList.pop_front();

	while (traversal.size() != llvmBasicBlocks.size()) {
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

		traversal.push_back(bb);
		visited.insert(bb);

		llvm::TerminatorInst *termInst = bb->getTerminator();
		for (unsigned int i = 0; i < termInst->getNumSuccessors(); ++i) {
			workList.push_back(termInst->getSuccessor(i));
		}
	}
	
}

/*!
	\brief 
*/
void analysis::LLVMUniformVectorization::addInterleavedInstructions(Translation &translation) {

	llvm::Function::BasicBlockListType & basicBlocks = translation.F->getBasicBlockList();

	breadthFirstTraversal(translation.traversal, translation.F);

	report("Vectorization: " << translation.F->getNameStr());

	// create blocks
	for (BasicBlockList::iterator bb_it = translation.traversal.begin(); 
		bb_it != translation.traversal.end(); ++bb_it) {
		
		llvm::BasicBlock *bb = *bb_it;
		if (bb->getNameStr() == "") { continue; }
		
		// ignore ocelot-inserted blocks for fusing thread blocks together
		if (bb->getNameStr().substr(0, 30) == "$__ocelot_remove_barrier_entry") { 
			WarpScheduler warpSched;
			translation.warpSchedulerBlocks[bb] = warpSched;
		}

		// construct a warp-synchronous block
		std::stringstream ss;
		ss << bb->getNameStr() << "_ws_" << warpSize;
		llvm::BasicBlock *warpBlock = llvm::BasicBlock::Create(
			translation.F->getContext(), ss.str(), 0, 0);
		translation.warpBlocksMap[bb] = warpBlock;
	}

	// breadth-first traversal
	for (BasicBlockList::iterator bb_it = translation.traversal.begin(); 
		bb_it != translation.traversal.end(); ++bb_it) {

		llvm::BasicBlock *srcBlock = *bb_it;

		// ignore empty blocks
		if (srcBlock->getNameStr() == "") { continue; }
		
		// ignore the warp-scheduler block
		if (translation.warpSchedulerBlocks.find(srcBlock) != translation.warpSchedulerBlocks.end()) {
			continue;
		}

		llvm::BasicBlock *warpBlock = translation.warpBlocksMap[srcBlock];
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
					instList.push_back(instr);

					updateDependencies(translation, instr, tid);
					
					// replace element ptr instructions with computations of thread idx
					if (llvm::GetElementPtrInst::classof(instr)) {
						llvm::GetElementPtrInst *ptrInst = static_cast<llvm::GetElementPtrInst *>(instr);
						
						if (ptrInst->getPointerOperand()->getNameStr() == "__ctaContext") {
							//ptrInst->dump();
							
							bool allZeros = (ptrInst->getNumOperands() == 4);
							for (unsigned int idx = 1; allZeros && idx < ptrInst->getNumOperands(); idx++) {
							
								if (llvm::ConstantInt::classof(ptrInst->getOperand(idx))) {
									llvm::ConstantInt *constInt = static_cast<llvm::ConstantInt *>(
										ptrInst->getOperand(idx));
									
									allZeros = constInt->isZero();
								}
							}
							
							if (allZeros) {
								// tidx
								translation.threadIdxMap[ptrInst] = tid;
							}
						}
					}
					
					translation.warpInstructionMap[(&*inst_it)].push_back(instr);
				}
			}
		}

		// insert a dummy terminator
		llvm::ReturnInst::Create(translation.F->getContext(), 0, warpBlock);	
		basicBlocks.push_back(warpBlock);
	}

	updateThreadIdxUses(translation);

	report("end vectorization " << translation.F->getNameStr() << "\n");
}

/*!
	\brief visits all uses of tidx and replaces with a computed value
*/
void analysis::LLVMUniformVectorization::updateThreadIdxUses(Translation &translation) {
	// visit all tidx dereferences and add threadID to result
	for (std::map< llvm::Instruction *, int >::iterator ptr_it = translation.threadIdxMap.begin();
		ptr_it != translation.threadIdxMap.end(); ++ptr_it) {

		// visit all users
		for (llvm::Value::use_iterator use_it = ptr_it->first->use_begin(); 
			use_it != ptr_it->first->use_end(); ++use_it) {
		
			if (llvm::LoadInst::classof(*use_it)) {
				std::stringstream ss;
				ss << "tidx" << ptr_it->second << "w";
				llvm::LoadInst *loadInst = static_cast<llvm::LoadInst *>(*use_it);
				// now replace all uses of loadInst with
				llvm::ConstantInt *tidxInst = llvm::ConstantInt::get(
					llvm::Type::getInt16Ty(translation.F->getContext()), ptr_it->second);
				llvm::BinaryOperator *addInst = llvm::BinaryOperator::CreateNSWAdd(
					loadInst, tidxInst, ss.str(), loadInst);
				loadInst->moveBefore(addInst);
				loadInst->replaceAllUsesWith(addInst);
				addInst->setOperand(0, loadInst);
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
void analysis::LLVMUniformVectorization::updateDependencies(Translation &translation, 
	llvm::Instruction *instr, int tid) {
		
	for (unsigned int i = 0; i < instr->getNumOperands(); ++i) {
		llvm::Value *operand = instr->getOperand(i);
		
		if (llvm::BasicBlock::classof(operand)) {
			instr->setOperand(i, translation.getWarpBlockFromScalar(
				static_cast<llvm::BasicBlock *>(operand)));
		}
		else if (llvm::Instruction::classof(operand)) {
			WarpInstructionMap::iterator op_it = translation.warpInstructionMap.find(operand);
			
			if (op_it != translation.warpInstructionMap.end()) {
				instr->setOperand(i, op_it->second[tid]);
			}
			else if (llvm::PHINode::classof(operand)) {
				// update phi nodes
				llvm::PHINode *phiNode = static_cast<llvm::PHINode *>(operand);
				llvm::PHINode *phiClone = llvm::PHINode::Create(phiNode->getType(), 
					phiNode->getNameStr(), instr);
				
				for (unsigned int j = 0; j < phiNode->getNumIncomingValues(); ++j) {
					op_it = translation.warpInstructionMap.find(phiNode->getIncomingValue(j));
					if (op_it != translation.warpInstructionMap.end()) {
						llvm::Value *incoming = op_it->second[tid];
						if (llvm::Instruction::classof(incoming)) {
							llvm::BasicBlock *scalar = static_cast<llvm::Instruction*>(incoming)->getParent();
							llvm::BasicBlock *warpBlock = translation.getWarpBlockFromScalar(scalar);
							if (!warpBlock) {
								warpBlock = scalar;
							}
							phiClone->addIncoming(incoming, warpBlock );
						}
						else {
							Ocelot_Exception("unhandled PHI NODE operand");
						}
					}
					else {
						Ocelot_Exception("unhandled PHI NODE operand");
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

/*!
	\brief replace dummy terminators in warp-synchronous block structure with
		tests for warp-synchronous behavior and either branches to successor blocks
		or returns to Ocelot multicore runtime
*/
void analysis::LLVMUniformVectorization::resolveControlFlow(Translation &translation) {
		
	for (BasicBlockMap::iterator bb_it = translation.warpBlocksMap.begin();
		bb_it != translation.warpBlocksMap.end(); ++bb_it) {
		
		if (translation.warpSchedulerBlocks.find(bb_it->first) != translation.warpSchedulerBlocks.end()) {
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
						clonedBr->setSuccessor(n, translation.warpBlocksMap[clonedBr->getSuccessor(n)]);
					}
					bb_it->second->getTerminator()->eraseFromParent(); // erase dummy
					bb_it->second->getInstList().push_back(clonedBr);
				}
				else {
					// potentially divergent branch - add to map for subsequent handling
					translation.divergingBranchMap[bb_it->second] = DivergentBranch(bb_it->first, 
						bb_it->second);
				}
			}
			else if (braInst->isUnconditional()) {
				// erase dummy terminator
				bb_it->second->getTerminator()->eraseFromParent();
				
				// insert uniform branch to successor
				llvm::BasicBlock *succ = translation.warpBlocksMap[braInst->getSuccessor(0)];
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
	for (DivergentBranchMap::iterator div_br_it = translation.divergingBranchMap.begin();
		div_br_it != translation.divergingBranchMap.end(); ++div_br_it) {
		handleDivergentBranch(translation, div_br_it->second);
	}
}

/*!
	\brief deals with a particular divergent branch
*/
void analysis::LLVMUniformVectorization::handleDivergentBranch(Translation &translation, 
	DivergentBranch &divergent) {
	
	// we only know how to handle 1-bit integer conditions
	llvm::TerminatorInst *scTerm = divergent.scalarBlock->getTerminator();
	if (llvm::BranchInst::classof(scTerm)) {
		llvm::BranchInst *scBranch = static_cast<llvm::BranchInst*>(scTerm);
		llvm::Value *condition = scBranch->getCondition();
		if (!condition->getType()->isIntegerTy(1)) {
			Ocelot_Exception("condition was expected to be of type integer-1");
		}
	
		WarpInstructionMap::iterator ws_it = translation.warpInstructionMap.find(condition);
		if (ws_it == translation.warpInstructionMap.end()) {
			Ocelot_Exception("divergent branch condition does not appear in the warp instruction map");
		}
		
		divergent.warpBlock->getTerminator()->removeFromParent();	 // remove dummy
		
		// construct reduction
		const llvm::Type *int16ty = llvm::Type::getInt16Ty(translation.F->getContext());
		const llvm::Type *int32ty = llvm::Type::getInt32Ty(translation.F->getContext());
		llvm::Constant *constOne = llvm::ConstantInt::get(int16ty, 1);
		llvm::Instruction *z = new llvm::ZExtInst(ws_it->second[0], int16ty, "condZ", 
			divergent.warpBlock);
		
		// insert reduction code 
		for (int n = 1; n < warpSize; n++) {
			llvm::BinaryOperator *shlOp = llvm::BinaryOperator::Create(llvm::Instruction::Shl, z, 
				constOne, "condZsl", divergent.warpBlock);
			llvm::Instruction *cmpInt16 = new llvm::ZExtInst(ws_it->second[n], int16ty, "cmpws",
				divergent.warpBlock);
			z = llvm::BinaryOperator::Create(llvm::Instruction::Or, shlOp, cmpInt16, "condZ", 
				divergent.warpBlock);
		}
		
		// if z is 0, all conditions were 0s. if z is (warpSize-1), all conditions were 1
		// else, diverge!
		
		llvm::ConstantInt *constZero = static_cast<llvm::ConstantInt *>(
			llvm::ConstantInt::get(int16ty, 0));
		llvm::ConstantInt *constFull = static_cast<llvm::ConstantInt *>(
			llvm::ConstantInt::get(int16ty, (1<<warpSize)-1));
		llvm::ConstantInt *constZero32 = static_cast<llvm::ConstantInt *>(
			llvm::ConstantInt::get(int32ty, 0));
		
		std::stringstream ss;
		ss << divergent.warpBlock->getNameStr() << "_diverge";
		divergent.handler = llvm::BasicBlock::Create(
			translation.F->getContext(), ss.str(), translation.F);
			
		llvm::BasicBlock *succZero = translation.warpBlocksMap[scBranch->getSuccessor(1)];
		llvm::BasicBlock *succFull = translation.warpBlocksMap[scBranch->getSuccessor(0)];
		
		llvm::SwitchInst *switchInst = llvm::SwitchInst::Create(
			z, divergent.handler, 2, divergent.warpBlock);
		switchInst->addCase(constFull, succFull);
		switchInst->addCase(constZero, succZero);
		
		// insert dummy return statement
		llvm::ReturnInst::Create(translation.F->getContext(), constZero32, divergent.handler);
		
		divergenceHandlerBranch(translation, divergent);
	}
	else {
		Ocelot_Exception("unexpected divergent terminator");
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief emit spill code or handler for a branch known to be divergent
*/
void analysis::LLVMUniformVectorization::divergenceHandlerBranch(Translation &translation, 
	DivergentBranch &divergent) {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief inserts a schedular block that handles control flow
*/
void analysis::LLVMUniformVectorization::createSchedulerBlock(Translation &translation) {
	llvm::BasicBlock *entry = & translation.F->front();
	translation.schedulerBlock = llvm::BasicBlock::Create(translation.F->getContext(),
		"WarpSyncScheduler", 
		translation.F, 
		entry);
	
	// for now, have scheduler block chain to previous entry point
	llvm::BasicBlock *startBlock = entry;
	if (!translation.warpSchedulerBlocks.size()) {
		startBlock = translation.getWarpBlockFromScalar(entry);
	}
	llvm::BranchInst *braInst = llvm::BranchInst::Create(
		startBlock, translation.schedulerBlock);
	assert(braInst);
}

/*
	\brief visits each of the warp scheduler blocks and changes control flow to point
		to warp-synchronous regions
*/
void analysis::LLVMUniformVectorization::updateSchedulerBlocks(Translation &translation) {
	WarpSchedulerMap::const_iterator ws_it = translation.warpSchedulerBlocks.begin();
	for (; ws_it != translation.warpSchedulerBlocks.end(); ++ws_it) {
		llvm::BasicBlock *scalar = ws_it->first;
		llvm::TerminatorInst *termInst = scalar->getTerminator();

		if (llvm::BranchInst::classof(termInst)) {
			llvm::BranchInst *braInst = static_cast<llvm::BranchInst *>(termInst);
			for (unsigned int i = 0; i < braInst->getNumSuccessors(); i++) {
				llvm::BasicBlock *wsBlock = translation.getWarpBlockFromScalar(braInst->getSuccessor(i));
				braInst->setSuccessor(i, wsBlock);
			}
		}
		else {
			throw hydrazine::Exception("updateSchedulerBlock() - expected terminator to be branch instruction");
		}		
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief this could probably be implemented as a second function pass, but examine
		collections of instructions of size <warpSize>, hoist or sink instructions, and
		make into vectors for vector processing
*/
void analysis::LLVMUniformVectorization::vectorize(Translation &translation) {

}

//////////////////////////////////////////////////////////////////////////////////////////////////


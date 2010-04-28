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

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1


//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::Translation::~Translation() {

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

void analysis::LLVMUniformVectorization::addInterleavedInstructions(Translation &translation) {

	llvm::Function::BasicBlockListType & basicBlocks = translation.F->getBasicBlockList();

	breadthFirstTraversal(translation.traversal, translation.F);

	report("Vectorization: " << translation.F->getNameStr());

	// create blocks
	for (BasicBlockList::iterator bb_it = translation.traversal.begin(); 
		bb_it != translation.traversal.end(); ++bb_it) {
		
		llvm::BasicBlock *bb = *bb_it;
		if (bb->getNameStr() == "") { continue; }

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

		if (srcBlock->getNameStr() == "") { continue; }

		llvm::BasicBlock *warpBlock = translation.warpBlocksMap[srcBlock];
		llvm::BasicBlock::InstListType & instList = warpBlock->getInstList();

		for (llvm::BasicBlock::iterator inst_it = srcBlock->begin(); inst_it != srcBlock->end(); 
			++inst_it) {

			// if instruction is control flow, don't replicate
			if (llvm::Instruction::isTerminator(inst_it->getOpcode())) {
				
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

	// debugging
	translation.F->getParent()->dump();

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
				llvm::BinaryOperator *addInst = llvm::BinaryOperator::CreateNSWAdd(loadInst, tidxInst, ss.str(), loadInst);
				loadInst->moveBefore(addInst);
				loadInst->replaceAllUsesWith(addInst);
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
		
		if (llvm::Instruction::classof(operand)) {
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
							phiClone->addIncoming(incoming, 
								static_cast<llvm::Instruction*>(incoming)->getParent() );
						}
						else {
							report("**** BIG PROBLEM - unhandled PHI NODE operand *** ");
						}
					}
					else {
						report("**** BIG PROBLEM - unhandled PHI NODE operand *** ");
					}
				}
				instr->setOperand(i, phiClone);
			}
			else {
				// problem
				operand->getType()->dump();
				operand->dump();
				report("**** BIG PROBLEM *** ");
			}
		}
	}	
}

void analysis::LLVMUniformVectorization::resolveControlFlow(Translation &translation) {

}

void analysis::LLVMUniformVectorization::vectorize(Translation &translation) {

}

//////////////////////////////////////////////////////////////////////////////////////////////////


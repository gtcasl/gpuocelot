//===- Ocelot.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements an Structural Transform based on Zhang's paper
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "structural-transform"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/Ocelot/StructuralAnalysis.h"
#include "llvm/Instructions.h"
#include "llvm/Transforms/Utils/Cloning.h"

using namespace llvm;
using namespace std;

namespace {
  // StructuralTransform - This class holds all the methods and data structures 
  class StructuralTransform : public FunctionPass {
  public:
    static char ID; // Pass ID, replacement for typeid

    StructuralTransform() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F);

    virtual void getAnalysisUsage(AnalysisUsage &AU) const {
//      AU.addRequired<StructuralAnalysis>();
    }

  private:
    StructuralAnalysis SA;
    // Change the value according to the ValueMap
    void RemapValue(Instruction *I, ValueToValueMapTy &ValueMap); 

    // Algorithm 2 of Zhang's paper -- elimination of outgoing branches
    bool Cut(NodeTy *N, Function &F); 

    // Algorithm 3 of Zhang's paper -- elimination of backward branches
    bool BackwardCopy(NodeTy *N, Function &F);

    // Algorithm 4 of Zhang's paper -- elimination of Forward branches
    bool ForwardCopy(NodeTy *N, Function &F);

    // SA -- used to retrieve the control tree result from structural analysis
    //StructuralAnalysis *SA; 
  };
}

char StructuralTransform::ID = 0;
static RegisterPass<StructuralTransform> X("structural-transform", "Structural transform");

void StructuralTransform::RemapValue(Instruction *I, ValueToValueMapTy &ValueMap) {
  // For some reason, RemapInstruction in ValueMapper.cpp asserts
  // if Value does not exists in ValueMap, but we should skip
  for (unsigned op = 0, E = I->getNumOperands(); op != E; ++op) {
    Value *Op = I->getOperand(op);
    ValueToValueMapTy::iterator It = ValueMap.find(Op);
    if (It != ValueMap.end()) Op = It->second;
    I->setOperand(op, Op);
  }
}

// Algorithm 2 of Zhang's paper -- elimination of outgoing branches
bool StructuralTransform::Cut(NodeTy *N, Function &F) {
  bool change = false; 

  for (NodeSetTy::iterator i = N->childNode.begin(), e = N->childNode.end(); i != e; ++i) 
    change |= Cut(*i, F);
  
  if (N->isCombined && (N->nodeType == NaturalLoop || N->nodeType == SelfLoop) && N->containedBB.size() > 1 && N->outgoingBR.size() > 0) {
    change = true;

    SmallVector <BasicBlock *, 4> EntryBlocks;

    for (pred_iterator PI = pred_begin(N->entryBB); PI != pred_end(N->entryBB); ++PI) {
      if (N->containedBB.count(*PI) == 0)
        EntryBlocks.push_back(*PI);
    }

    // This function saves us from having correct PHI and updating analysis
    BasicBlock *PreHeader = SplitBlockPredecessors(N->entryBB, &EntryBlocks[0],
                                      EntryBlocks.size(), ".preheader", this);
    BasicBlock *TopExitBB = N->exitBB;
   
    for (EdgeVecTy::iterator i = N->outgoingBR.begin(), e = N->outgoingBR.end(); i != e; ++i) {
      // 1. Before loop, insert fp = false
      AllocaInst *fp = new AllocaInst(Type::getInt32Ty(N->entryBB->getContext()), ConstantInt::get(Type::getInt8Ty(N->entryBB->getContext()), 1), "fp", F.getEntryBlock().getTerminator());
 
      new StoreInst(ConstantInt::get(Type::getInt32Ty(N->entryBB->getContext()), 0), fp, PreHeader->getTerminator());

      // 2. replace branch to targe t by if (B) then {fp = true; exit}
      new StoreInst(ConstantInt::get(Type::getInt32Ty(N->entryBB->getContext()), 1), fp, i->first->getTerminator());

      // 3. After loop, insert if (fp) goto t
      BasicBlock *NewCmpBB = BasicBlock::Create(N->entryBB->getContext(), "", &F);

      if (i->first->hasName()) NewCmpBB->setName(i->first->getName() + ".cmp");

      LoadInst *LdI = new LoadInst(fp, "", NewCmpBB);

      CmpInst *CmpI = CmpInst::Create(Instruction::ICmp, CmpInst::ICMP_EQ,
                 LdI, ConstantInt::get(Type::getInt32Ty(N->entryBB->getContext()), 1), "", NewCmpBB);

      if (TopExitBB)
        BranchInst::Create(i->second, TopExitBB, CmpI, NewCmpBB);
      else 
        BranchInst::Create(i->second, NewCmpBB);

      TerminatorInst *TermI = i->first->getTerminator();

      for (unsigned ii = 0; ii < TermI->getNumSuccessors(); ii++) 
        if (TermI->getSuccessor(ii) == i->second) 
          TermI->setSuccessor(ii, NewCmpBB);
 
      if (TopExitBB) {
        // ValueMap
        ValueToValueMapTy ValueMap;
        ValueMap[TopExitBB] = NewCmpBB;
  
        // For each contained BasicBlock
        // Remap Values here for Instructions 
        for (BBSetTy::iterator BB = N->containedBB.begin(), BBE = N->containedBB.end(); BB != BBE; BB++)
          for (BasicBlock::iterator I = (*BB)->begin(), E = (*BB)->end(); I != E; ++I)
            RemapValue(I, ValueMap);
      }
 
      TopExitBB = NewCmpBB;
    }

    if (!N->exitBB) {
      TerminatorInst *TermI = N->entryBB->getTerminator();

      if (BranchInst *oldTermI = dyn_cast<BranchInst>(TermI)) {
        if (oldTermI->isUnconditional()) {
          BasicBlock *oldDest = oldTermI->getSuccessor(0);

          AllocaInst *fakeCond = new AllocaInst(Type::getInt32Ty(N->entryBB->getContext()), ConstantInt::get(Type::getInt8Ty(N->entryBB->getContext()), 1), "fakeCond", F.getEntryBlock().getTerminator());
          new StoreInst(ConstantInt::get(Type::getInt32Ty(N->entryBB->getContext()), 0), fakeCond, oldTermI);
          LoadInst *LdI = new LoadInst(fakeCond, "", oldTermI);
          CmpInst *fakeCmpI = CmpInst::Create(Instruction::ICmp, CmpInst::ICMP_EQ,
                   LdI, ConstantInt::get(Type::getInt32Ty(N->entryBB->getContext()), 1), "", oldTermI);
          BranchInst::Create(TopExitBB, oldDest, fakeCmpI, oldTermI);

          oldTermI->eraseFromParent();
        } else {
          BasicBlock *oldDest1 = oldTermI->getSuccessor(0);
          BasicBlock *oldDest2 = oldTermI->getSuccessor(1);
          Value *oldCond = oldTermI->getCondition();

          SwitchInst *newTermI = SwitchInst::Create(oldCond, TopExitBB, 2, oldTermI);
          newTermI->addCase(ConstantInt::get(Type::getInt1Ty(N->entryBB->getContext()), 0), oldDest1);
          newTermI->addCase(ConstantInt::get(Type::getInt1Ty(N->entryBB->getContext()), 1), oldDest2);
           
          oldTermI->eraseFromParent();
        } 
      } else if (SwitchInst *oldTermI = dyn_cast<SwitchInst>(TermI)) {
        SmallVector<unsigned, 4> oldValueVect;
 
        for (unsigned i = 0; i < oldTermI->getNumCases(); ++i) {
          ConstantInt *oldConst = oldTermI->getCaseValue(i);
          oldValueVect.push_back(oldTermI->findCaseValue(oldConst));
        }
 
        unsigned fakeValue = 19039;
    
        do {
          bool found = false;
 
          for (SmallVector<unsigned, 4>::iterator i = oldValueVect.begin(), e = oldValueVect.end(); i != e; ++i) 
            if (*i == fakeValue) {
             found = true;
 
             break; 
            }
 
          if (!found) {
            ConstantInt *FakeConst = ConstantInt::get(Type::getInt32Ty(N->entryBB->getContext()), fakeValue);
            oldTermI->addCase(FakeConst, TopExitBB);
 
            break;
          }

          fakeValue++;
        } while(1);
      }
    }

    return change;
  } 

  return change;  
}

// Algorithm 3 of Zhang's paper -- elimination of backward branches
bool StructuralTransform::BackwardCopy(NodeTy *N, Function &F) {
  bool change = false; 

  for (NodeSetTy::iterator i = N->childNode.begin(), e = N->childNode.end(); i != e; ++i) 
    change |= BackwardCopy(*i, F);
  
  if (N->isCombined && (N->nodeType == NaturalLoop || N->nodeType == SelfLoop) && N->containedBB.size() > 1 && N->incomingBR.size() > 0) {
    change = true;

    SmallVector <BasicBlock *, 4> EntryBlocks;

    for (pred_iterator PI = pred_begin(N->entryBB); PI != pred_end(N->entryBB); ++PI) {
      if (N->containedBB.count(*PI) == 0)
        EntryBlocks.push_back(*PI);
    }

    // This function saves us from having correct PHI and updating analysis
    BasicBlock *PreHeader = SplitBlockPredecessors(N->entryBB, &EntryBlocks[0],
                                      EntryBlocks.size(), ".preheader", this);
 

    // ValueMap
    ValueToValueMapTy ValueMap;
    BBVecTy clonedBBVec;
    BasicBlock *clonedEntryBB;

    // Clone BasicBlocks to unroll the loop for one iteration 
    for (BBSetTy::iterator BI = N->containedBB.begin(), BE = N->containedBB.end(); BI != BE; ++BI){
      BasicBlock *BB = *BI;
      BasicBlock *ClonedBB = CloneBasicBlock(BB, ValueMap, ".backward", &F);
      ValueMap[BB] = ClonedBB;
      clonedBBVec.push_back(ClonedBB);

      if (BB == N->entryBB) clonedEntryBB = ClonedBB;
    }

    ValueMap.erase(N->entryBB);

    // For each cloned BasicBlock
    // Remap Values here for Instructions 
    for (BBVecTy::iterator BB = clonedBBVec.begin(), BBE = clonedBBVec.end(); BB != BBE; BB++)
      for (BasicBlock::iterator I = (*BB)->begin(), E = (*BB)->end(); I != E; ++I)
        RemapValue(I, ValueMap);

   TerminatorInst *TermI = PreHeader->getTerminator();
   TermI->setSuccessor(0, clonedEntryBB); 

    // point the incoming edges to the unrolled iteration
    for (EdgeVecTy::iterator i = N->incomingBR.begin(), e = N->incomingBR.end(); i != e; ++i) {
      TerminatorInst *TermI = i->first->getTerminator();

      for (unsigned ii = 0; ii < TermI->getNumSuccessors(); ii++) 
        if (TermI->getSuccessor(ii) == i->second) 
          TermI->setSuccessor(ii, dyn_cast<BasicBlock>(ValueMap[i->second]));
    }

    return change;
  } 

  return change;  
}


// Algorithm 4 of Zhang's paper -- elimination of Forward branches
bool StructuralTransform::ForwardCopy(NodeTy *N, Function &F) {
  bool change = false; 

  for (NodeSetTy::iterator i = N->childNode.begin(), e = N->childNode.end(); i != e; ++i) 
    change |= ForwardCopy(*i, F);
  
  if (N->incomingForwardBR.size() > 0) {
    change = true;

    for (EdgeVecTy::iterator i = N->incomingForwardBR.begin(), e = N->incomingForwardBR.end(); i != e; ++i) {
      // ValueMap
      ValueToValueMapTy ValueMap;
      BBVecTy ClonedBBVec;
  
      // Clone BasicBlocks to the new function
      for (BBSetTy::iterator BI = N->containedBB.begin(), BE = N->containedBB.end(); BI != BE; ++BI){
        BasicBlock *BB = *BI;
        BasicBlock *ClonedBB = CloneBasicBlock(BB, ValueMap, ".forward", &F);
        ValueMap[BB] = ClonedBB;
        ClonedBBVec.push_back(ClonedBB);
      }
  
      // For each BasicBlock
      // Remap Values here for Instructions
      for (BBVecTy::iterator BB = ClonedBBVec.begin(), BBE = ClonedBBVec.end(); BB != BBE; BB++) 
        for (BasicBlock::iterator I = (*BB)->begin(), E = (*BB)->end(); I != E; ++I)
          RemapValue(I, ValueMap);

      TerminatorInst *TermI = i->first->getTerminator();

      for (unsigned ii = 0; ii < TermI->getNumSuccessors(); ii++) 
        if (TermI->getSuccessor(ii) == i->second) 
          TermI->setSuccessor(ii, dyn_cast<BasicBlock>(ValueMap[i->second]));
    } 

    return change;
  }

  return change;  
} 

bool StructuralTransform::runOnFunction(Function &F) {
  bool change = false;
   
//  SA = &getAnalysis<StructuralAnalysis>(F);

  SA.runOnFunction(F);

  while (unstructuredBRVec.size() > 0) {
    NodeTy *entry = *(Net.begin()); 

    if (Cut(entry, F)) {
      change = true;
      errs() << "After Cut:\n";
      F.dump();

      goto ANALYSIS;
    }

    if (BackwardCopy(entry, F)) {
      change = true;
      errs() << "After BackwardCopy:\n";
      F.dump();

      goto ANALYSIS;
    }

    if (ForwardCopy(entry, F)) {
      change = true;
      errs() << "After ForwarCopy:\n";
      F.dump();

      goto ANALYSIS;
    }

ANALYSIS:
    unstructuredBRVec.clear();

    Net.clear();
 
    SA.runOnFunction(F);
  }

//  F.dump();

  return change;
}


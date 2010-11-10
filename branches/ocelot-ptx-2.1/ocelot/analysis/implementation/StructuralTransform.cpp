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

#include <ocelot/analysis/interface/StructuralTransform.h> 
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis {
  void StructuralTransform::RemapValue(ir::ControlFlowGraph::iterator BB, ValueToValueMapTy &ValueMap) {
    ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>(BB->instructions.back());

    if (bra->opcode == ir::PTXInstruction::Bra) {
      ir::BasicBlock::EdgePointerVector edges = BB->out_edges;

      for (ir::BasicBlock::EdgePointerVector::iterator i = edges.begin(), e = edges.end(); i != e; ++i) {
        ValueToValueMapTy::iterator it = ValueMap.find((*i)->tail);
 
        if (it != ValueMap.end()) {
          (*i)->tail = ValueMap[(*i)->tail];

          if ((*i)->type == ir::Edge::Branch) {
            bra->d = std::move(ir::PTXOperand(ValueMap[(*i)->tail]->label));
          }
        }
      } 
    }
  }

  ir::ControlFlowGraph::iterator StructuralTransform::SplitBlockPredecessors(ir::ControlFlowGraph::iterator BB, BBVecTy::iterator iter, int size) {
    int i = 1;

    ir::ControlFlowGraph::edge_iterator firstEdge = (*iter)->get_edge(BB);
    ir::Edge::Type firstEdgeType = firstEdge->type; 
    ir::ControlFlowGraph::iterator NewBB = _kernel->cfg()->insert_block(ir::BasicBlock(BB->label + "_splitpredecessor",
            _kernel->cfg()->newId()));
    ir::ControlFlowGraph::EdgePair splitEdge = _kernel->cfg()->split_edge(firstEdge, *NewBB);
    splitEdge.second->type = ir::Edge::Branch;
    splitEdge.first->type = firstEdgeType;

    ir::PTXInstruction* branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
    branch->uni = true;
    branch->d = std::move(ir::PTXOperand(BB->label));
    NewBB->instructions.push_back(branch);
    
    ++iter;

    while (i < size) {
      ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>((*iter)->instructions.back());

      if (bra->opcode == ir::PTXInstruction::Bra) {
        if (bra->d.identifier == BB->label) {
          bra->d = std::move(ir::PTXOperand(BB->label));
          _kernel->cfg()->remove_edge((*iter)->get_branch_edge());
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(*iter, BB, ir::Edge::Branch)); 
        } else if ((*iter)->get_fallthrough_edge()->tail == BB) {
          switch(bra->pg.condition) {
          case ir::PTXOperand::Pred:
            bra->pg.condition = ir::PTXOperand::InvPred;
            break;
          case ir::PTXOperand::InvPred:
            bra->pg.condition = ir::PTXOperand::Pred;
            break;
          case ir::PTXOperand::PT:
            bra->pg.condition = ir::PTXOperand::nPT;
            break;
          case ir::PTXOperand::nPT:
            bra->pg.condition = ir::PTXOperand::PT;
            break;
          }

          bra->d = std::move(ir::PTXOperand(BB->label));

          _kernel->cfg()->remove_edge((*iter)->get_fallthrough_edge());
          ir::BasicBlock::EdgeList::iterator tmpEdge = (*iter)->get_branch_edge();
          tmpEdge->type = ir::Edge::FallThrough;
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(*iter, BB, ir::Edge::Branch)); 
        }
      }

      ++i;
      ++iter;
    }
 
    return NewBB;
  }
  
  // Algorithm 2 of Zhang's paper -- elimination of outgoing branches
  bool StructuralTransform::Cut(NodeTy *N) {
    bool change = false; 
  
    for (NodeSetTy::iterator i = N->childNode.begin(), e = N->childNode.end(); i != e; ++i) 
      change |= Cut(*i);
    
    if (N->isCombined && (N->nodeType == NaturalLoop || N->nodeType == SelfLoop) && N->containedBB.size() > 1 && N->outgoingBR.size() > 0) {
      change = true;
  
      BBVecTy EntryBlocks;
      ir::ControlFlowGraph::BlockPointerVector PredVec = N->entryBB->predecessors;

      for (ir::ControlFlowGraph::BlockPointerVector::iterator PI = PredVec.begin(), E = PredVec.end(); PI != E; ++PI) {
        if (N->containedBB.count(*PI) == 0)
          EntryBlocks.push_back(*PI);
      }

      // This function saves us from having correct PHI and updating analysis
      ir::ControlFlowGraph::iterator PreHeader = SplitBlockPredecessors(N->entryBB, EntryBlocks.begin(),
                                        EntryBlocks.size());

      ir::ControlFlowGraph::iterator TopExitBB = N->exitBB;
     
      for (EdgeVecTy::iterator i = N->outgoingBR.begin(), e = N->outgoingBR.end(); i != e; ++i) {
        // 1. Before loop, insert fp = false
        DataflowGraph::RegisterId fp = _kernel->dfg()->newRegister();  

        ir::PTXInstruction* move1 = new ir::PTXInstruction(ir::PTXInstruction::Mov);
        move1->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate,
                ir::PTXOperand::u32, 0));
        move1->d = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                ir::PTXOperand::u32, fp));
        move1->type = ir::PTXOperand::u32;
        ir::BasicBlock::InstructionList ILEntry = _kernel->cfg()->get_entry_block()->instructions;
        ir::BasicBlock::InstructionList::iterator ILi = ILEntry.end();
        ILi--;
        ILEntry.insert(ILi, move1);
         
        // 2. replace branch to targe t by if (B) then {fp = true; exit}
        ir::PTXInstruction* move2 = new ir::PTXInstruction(ir::PTXInstruction::Mov);
        move2->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate,
                ir::PTXOperand::u32, 1));
        move2->d = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                ir::PTXOperand::u32, fp));
        move2->type = ir::PTXOperand::u32;
        ir::ControlFlowGraph::InstructionList ILBR = i->first->instructions;
        ir::BasicBlock::InstructionList::iterator ILBRi = ILEntry.end();
        ILBRi--;
        ILBR.insert(ILBRi, move2);
  
        // 3. After loop, insert if (fp) goto t
        ir::ControlFlowGraph::iterator NewCmpBB = _kernel->cfg()->insert_block(ir::BasicBlock(i->first->label + "_cmp",
                  _kernel->cfg()->newId()));

        if (TopExitBB != _kernel->cfg()->end()) {
          ir::ControlFlowGraph::edge_iterator exitEdge = N->exitBB->get_edge(TopExitBB);
          ir::Edge::Type exitEdgeType = exitEdge->type; 
          ir::ControlFlowGraph::EdgePair splitEdge =
                  _kernel->cfg()->split_edge(exitEdge, *NewCmpBB);
          splitEdge.second->type = ir::Edge::FallThrough;
          splitEdge.first->type = exitEdgeType;
  
          ir::PTXInstruction* setp = new ir::PTXInstruction(ir::PTXInstruction::SetP);
          setp->a = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                  ir::PTXOperand::u32, fp));
          setp->b = std::move(ir::PTXOperand(ir::PTXOperand::Immediate,
                  ir::PTXOperand::u32, 1));
          setp->d = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                  ir::PTXOperand::u32, _kernel->dfg()->newRegister()));
          setp->type = ir::PTXOperand::u32;
          setp->comparisonOperator = ir::PTXInstruction::Eq;
          NewCmpBB->instructions.push_back(setp);

          ir::PTXInstruction* bra = new ir::PTXInstruction(ir::PTXInstruction::Bra);
          bra->d = std::move(ir::PTXOperand(i->second->label));
          bra->pg = setp->d;
          NewCmpBB->instructions.push_back(bra);
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(NewCmpBB, i->second, ir::Edge::Branch));
        }
        else {
          ir::PTXInstruction* bra = new ir::PTXInstruction(ir::PTXInstruction::Bra);
          bra->d = std::move(ir::PTXOperand(i->second->label));
          bra->uni = true;
          NewCmpBB->instructions.push_back(bra);
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(NewCmpBB, i->second, ir::Edge::Branch));
        }
  
        ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>(i->first->instructions.back());

        if (bra->opcode == ir::PTXInstruction::Bra) {
          if (bra->d.identifier == i->second->label) {
            bra->d = std::move(ir::PTXOperand(NewCmpBB->label));
            _kernel->cfg()->remove_edge(i->first->get_branch_edge());
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, NewCmpBB, ir::Edge::Branch)); 
          } else if (i->first->get_fallthrough_edge()->tail == i->second) {
            switch(bra->pg.condition) {
            case ir::PTXOperand::Pred:
              bra->pg.condition = ir::PTXOperand::InvPred;
              break;
            case ir::PTXOperand::InvPred:
              bra->pg.condition = ir::PTXOperand::Pred;
              break;
            case ir::PTXOperand::PT:
              bra->pg.condition = ir::PTXOperand::nPT;
              break;
            case ir::PTXOperand::nPT:
              bra->pg.condition = ir::PTXOperand::PT;
              break;
            }

            bra->d = std::move(ir::PTXOperand(NewCmpBB->label));

            _kernel->cfg()->remove_edge(i->first->get_fallthrough_edge());
            ir::BasicBlock::EdgeList::iterator tmpEdge = i->first->get_branch_edge();
            tmpEdge->type = ir::Edge::FallThrough;
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, NewCmpBB, ir::Edge::Branch)); 
          }
        }
  
        if (TopExitBB != _kernel->cfg()->end()) {
          // ValueMap
          ValueToValueMapTy ValueMap;
          ValueMap[TopExitBB] = NewCmpBB;
    
          // For each contained BasicBlock
          // Remap Values here for Instructions 
          for (BBSetTy::iterator BB = N->containedBB.begin(), BBE = N->containedBB.end(); BB != BBE; BB++)
            RemapValue(*BB, ValueMap);
        }
   
        TopExitBB = NewCmpBB;
      }
  
      if (!&*N->exitBB) 
        _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(N->entryBB, TopExitBB, ir::Edge::Dummy)); 

      return change;
    } 
  
    return change;  
  }
  
  // Algorithm 3 of Zhang's paper -- elimination of backward branches
  bool StructuralTransform::BackwardCopy(NodeTy *N) {
    bool change = false; 
  
    for (NodeSetTy::iterator i = N->childNode.begin(), e = N->childNode.end(); i != e; ++i) 
      change |= BackwardCopy(*i);
    
    if (N->isCombined && (N->nodeType == NaturalLoop || N->nodeType == SelfLoop) && N->containedBB.size() > 1 && N->incomingBR.size() > 0) {
      change = true;

      std::vector<ir::ControlFlowGraph::iterator> EntryBlocks;
      ir::ControlFlowGraph::BlockPointerVector PredVec = N->entryBB->predecessors;

      for (ir::ControlFlowGraph::BlockPointerVector::iterator PI = PredVec.begin(), E = PredVec.end(); PI != E; ++PI) {
        if (N->containedBB.count(*PI) == 0)
          EntryBlocks.push_back(*PI);
      }
  
      // This function saves us from having correct PHI and updating analysis
      ir::ControlFlowGraph::iterator PreHeader = SplitBlockPredecessors(N->entryBB, EntryBlocks.begin(),
                                        EntryBlocks.size());
 
      // ValueMap
      ValueToValueMapTy ValueMap;
      BBSetTy clonedBBSet;
      ir::ControlFlowGraph::iterator clonedEntryBB;
  
      // Clone BasicBlocks to unroll the loop for one iteration 
      for (BBSetTy::iterator BI = N->containedBB.begin(), BE = N->containedBB.end(); BI != BE; ++BI){
        ir::ControlFlowGraph::iterator BB = *BI;
        ir::ControlFlowGraph::iterator ClonedBB = _kernel->cfg()->clone_block(BB);
        ValueMap[BB] = ClonedBB;
        clonedBBSet.insert(ClonedBB);
  
        if (BB == N->entryBB) clonedEntryBB = ClonedBB;
      }
  
      ValueMap.erase(N->entryBB);
  
      // For each cloned BasicBlock
      // Remap Values here for Instructions 
      for (BBSetTy::iterator BB = clonedBBSet.begin(), BBE = clonedBBSet.end(); BB != BBE; BB++)
        RemapValue(*BB, ValueMap);

      ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>(PreHeader->instructions.back());

      if (bra->opcode == ir::PTXInstruction::Bra) {
        bra->d = std::move(ir::PTXOperand(clonedEntryBB->label));
        _kernel->cfg()->remove_edge(PreHeader->get_branch_edge());
        _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(PreHeader, clonedEntryBB, ir::Edge::Branch)); 
      }         
  
      // point the incoming edges to the unrolled iteration
      for (EdgeVecTy::iterator i = N->incomingBR.begin(), e = N->incomingBR.end(); i != e; ++i) {
        ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>(i->first->instructions.back());

        if (bra->opcode == ir::PTXInstruction::Bra) {
          if (bra->d.identifier == i->second->label) {
            bra->d = std::move(ir::PTXOperand(ValueMap[i->second]->label));
            _kernel->cfg()->remove_edge(i->first->get_branch_edge());
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, i->second, ir::Edge::Branch)); 
          } else if (i->first->get_fallthrough_edge()->tail == i->second) {
            switch(bra->pg.condition) {
            case ir::PTXOperand::Pred:
              bra->pg.condition = ir::PTXOperand::InvPred;
              break;
            case ir::PTXOperand::InvPred:
              bra->pg.condition = ir::PTXOperand::Pred;
              break;
            case ir::PTXOperand::PT:
              bra->pg.condition = ir::PTXOperand::nPT;
              break;
            case ir::PTXOperand::nPT:
              bra->pg.condition = ir::PTXOperand::PT;
              break;
            }

            bra->d = std::move(ir::PTXOperand(ValueMap[i->second]->label));

            _kernel->cfg()->remove_edge(i->first->get_fallthrough_edge());
            ir::BasicBlock::EdgeList::iterator tmpEdge = i->first->get_branch_edge();
            tmpEdge->type = ir::Edge::FallThrough;
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, ValueMap[i->second], ir::Edge::Branch)); 
          }
        }
      }
  
      return change;
    } 
  
    return change;  
  }
  
  
  // Algorithm 4 of Zhang's paper -- elimination of Forward branches
  bool StructuralTransform::ForwardCopy(NodeTy *N) {
    bool change = false; 
  
    for (NodeSetTy::iterator i = N->childNode.begin(), e = N->childNode.end(); i != e; ++i) 
      change |= ForwardCopy(*i);
    
    if (N->incomingForwardBR.size() > 0) {
      change = true;
  
      for (EdgeVecTy::iterator i = N->incomingForwardBR.begin(), e = N->incomingForwardBR.end(); i != e; ++i) {
        // ValueMap
        ValueToValueMapTy ValueMap;
        BBSetTy ClonedBBSet;
   
        // Clone BasicBlocks to the new function
        for (BBSetTy::iterator BI = N->containedBB.begin(), BE = N->containedBB.end(); BI != BE; ++BI){
          ir::ControlFlowGraph::iterator BB = *BI;
          ir::ControlFlowGraph::iterator ClonedBB = _kernel->cfg()->clone_block(BB);
          ValueMap[BB] = ClonedBB;
          ClonedBBSet.insert(ClonedBB);
        }
    
        // For each BasicBlock
        // Remap Values here for Instructions
        for (BBSetTy::iterator BB = ClonedBBSet.begin(), BBE = ClonedBBSet.end(); BB != BBE; BB++) 
          RemapValue(*BB, ValueMap);
 
        ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>(i->first->instructions.back());

        if (bra->opcode == ir::PTXInstruction::Bra) {
          if (bra->d.identifier == i->second->label) {
            bra->d = std::move(ir::PTXOperand(ValueMap[i->second]->label));
            _kernel->cfg()->remove_edge(i->first->get_branch_edge());
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, i->second, ir::Edge::Branch)); 
          } else if (i->first->get_fallthrough_edge()->tail == i->second) {
            switch(bra->pg.condition) {
            case ir::PTXOperand::Pred:
              bra->pg.condition = ir::PTXOperand::InvPred;
              break;
            case ir::PTXOperand::InvPred:
              bra->pg.condition = ir::PTXOperand::Pred;
              break;
            case ir::PTXOperand::PT:
              bra->pg.condition = ir::PTXOperand::nPT;
              break;
            case ir::PTXOperand::nPT:
              bra->pg.condition = ir::PTXOperand::PT;
              break;
            }

            bra->d = std::move(ir::PTXOperand(ValueMap[i->second]->label));

            _kernel->cfg()->remove_edge(i->first->get_fallthrough_edge());
            ir::BasicBlock::EdgeList::iterator tmpEdge = i->first->get_branch_edge();
            tmpEdge->type = ir::Edge::FallThrough;
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, ValueMap[i->second], ir::Edge::Branch)); 
          }
        }
      } 
  
      return change;
    }
  
    return change;  
  } 
  
  void StructuralTransform::runOnKernel(ir::Kernel& k) {
    bool change = false;
    _kernel = static_cast<ir::PTXKernel *>(&k);
  
    SA.runOnKernel(_kernel);
  
    while (SA.unstructuredBRVec.size() > 0) {
      NodeTy *entry = *(SA.Net.begin()); 
  
      if (Cut(entry)) {
        change = true;
  
        goto ANALYSIS;
      }
  
      if (BackwardCopy(entry)) {
        change = true;
  
        goto ANALYSIS;
      }
  
      if (ForwardCopy(entry)) {
        change = true;
  
        goto ANALYSIS;
      }
  
  ANALYSIS:
      SA.unstructuredBRVec.clear();
  
      SA.Net.clear();
   
      SA.runOnKernel(_kernel);
    }
  }
}

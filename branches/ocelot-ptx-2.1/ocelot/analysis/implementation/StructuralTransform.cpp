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
    if (!stopCut)
    if (N->isCombined && (N->nodeType == NaturalLoop || N->nodeType == SelfLoop) && N->containedBB.size() > 1 && N->outgoingBR.size() > 0) {
      change = true;
  
      ir::ControlFlowGraph::iterator TopExitBB = N->exitBB;

      for (BBSetTy::iterator i = N->entryNode->containedBB.begin(), e = N->entryNode->containedBB.end(); i != e; ++i) {
        ir::ControlFlowGraph::iterator BB = *i;
        ir::BasicBlock::EdgePointerVector edges = BB->out_edges;
    
        if (edges.size() == 2) {
          ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>(BB->instructions.back());
      
          if (bra->opcode == ir::PTXInstruction::Bra) {
            if (BB->get_fallthrough_edge()->tail == TopExitBB) {
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
      
              bra->d = std::move(ir::PTXOperand(TopExitBB->label));
      
              _kernel->cfg()->remove_edge(BB->get_fallthrough_edge());
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, BB->get_branch_edge()->tail, ir::Edge::FallThrough));
              _kernel->cfg()->remove_edge(BB->get_branch_edge());
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, TopExitBB, ir::Edge::Branch)); 
            }
          }
        }
      }
    
      for (EdgeVecTy::iterator i = N->outgoingBR.begin(), e = N->outgoingBR.end(); i != e; ++i) {
        if (SA.BB2NodeMap[(i->first)]->isBackEdge) continue;

        ir::ControlFlowGraph::iterator BB = i->first;
        ir::BasicBlock::EdgePointerVector edges = BB->out_edges;
    
        if (edges.size() == 2) {
          ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>(BB->instructions.back());
      
          if (bra->opcode == ir::PTXInstruction::Bra) {
            if (BB->get_fallthrough_edge()->tail == i->second) {
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
      
              bra->d = std::move(ir::PTXOperand(i->second->label));
      
              _kernel->cfg()->remove_edge(BB->get_fallthrough_edge());
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, BB->get_branch_edge()->tail, ir::Edge::FallThrough));
              _kernel->cfg()->remove_edge(BB->get_branch_edge());
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, i->second, ir::Edge::Branch)); 
            }
          }
        }
      }
 
      for (EdgeVecTy::iterator i = N->outgoingBR.begin(), e = N->outgoingBR.end(); i != e; ++i) {
        // 1. Before loop, insert fp = false
        DataflowGraph::RegisterId fp = _kernel->dfg()->newRegister();  

        ir::PTXInstruction* move1 = new ir::PTXInstruction(ir::PTXInstruction::Mov);
        move1->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate,
                ir::PTXOperand::u32, 0x0));
        move1->a.imm_uint = 0;
        move1->d = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                ir::PTXOperand::u32, fp));
        move1->type = ir::PTXOperand::u32;
        ir::BasicBlock::InstructionList& ILEntry = _kernel->cfg()->get_entry_block()->instructions;
        ILEntry.push_front(move1); 
         
        // 2. replace branch to targe t by if (B) then {fp = true; exit}
        ir::PTXInstruction* move2 = new ir::PTXInstruction(ir::PTXInstruction::Mov);
        move2->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate,
                ir::PTXOperand::u32, 0x1));
        move2->a.imm_uint = 1;
        move2->d = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                ir::PTXOperand::u32, fp));
        move2->type = ir::PTXOperand::u32;
        ir::ControlFlowGraph::InstructionList &ILBR = i->first->instructions;
        ILBR.push_front(move2);

        ir::ControlFlowGraph::BlockPointerVector SuccVec = i->first->successors;
  
        for (ir::ControlFlowGraph::BlockPointerVector::iterator SI = SuccVec.begin(), E = SuccVec.end(); SI != E; ++SI) {
          if (N->containedBB.count(*SI) == 0) continue;

          ir::PTXInstruction* move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
          move->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate,
                  ir::PTXOperand::u32, 0x0));
          move->a.imm_uint = 0;
          move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                  ir::PTXOperand::u32, fp));
          move->type = ir::PTXOperand::u32;
          ir::BasicBlock::InstructionList& ILSucc = (*SI)->instructions;
          ILSucc.push_front(move); 
        }
  
        // 3. After loop, insert if (fp) goto t
        ir::ControlFlowGraph::iterator NewCmpBB = _kernel->cfg()->insert_block(ir::BasicBlock(i->first->label + "_cmp",
                  _kernel->cfg()->newId()));
 
        // ValueMap
        ValueToValueMapTy ValueMap;
        ValueMap[i->second] = NewCmpBB;    

        if (TopExitBB != _kernel->cfg()->end()) ValueMap[TopExitBB] = NewCmpBB;

        // For each BasicBlock
        // Remap Values here for Instructions
        for (BBSetTy::iterator BBI = N->containedBB.begin(), BBE = N->containedBB.end(); BBI != BBE; ++BBI) { 
          ir::ControlFlowGraph::iterator BB = *BBI;
          ir::BasicBlock::EdgePointerVector edges = BB->out_edges;
  
          if (edges.size() == 1) {
            ir::BasicBlock::EdgePointerVector::iterator ei = edges.begin();
            ValueToValueMapTy::iterator it = ValueMap.find((*ei)->tail);
  
            // found in ValueMap
            if (it != ValueMap.end()) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, (*it).second, (*ei)->type));
  
              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(BB->instructions.back());
  
              if (term->opcode == ir::PTXInstruction::Bra && term->d.identifier == (*ei)->tail->label)
                term->d = std::move(ir::PTXOperand((*it).second->label));

              _kernel->cfg()->remove_edge(*ei);
            } 
          } else if (edges.size() == 2) {
            ir::BasicBlock::EdgePointerVector::iterator ei = edges.begin();
            ir::BasicBlock::EdgePointerVector::iterator ei1 = ei;
            ++ei;
            ir::BasicBlock::EdgePointerVector::iterator ei2 = ei;
  
            ValueToValueMapTy::iterator it1 = ValueMap.find((*ei1)->tail);
            ValueToValueMapTy::iterator it2 = ValueMap.find((*ei2)->tail);
  
            bool found1 = (it1 != ValueMap.end());
            bool found2 = (it2 != ValueMap.end());
  
            // both found in ValueMap
            if (found1 && found2) {
              _kernel->cfg()->remove_edge(*ei1);
              _kernel->cfg()->remove_edge(*ei2);
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, (*it1).second, ir::Edge::Branch)); 
 
              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(BB->instructions.back());
  
              if (term->opcode == ir::PTXInstruction::Bra) {
                term->d = std::move(ir::PTXOperand((*it1).second->label));
                term->uni = true;
              }
            } 
            // edge 1 is found in ValueMap & edge 2 is not
            else if (found1 && !found2) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, (*it1).second, (*ei1)->type));
  
              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(BB->instructions.back());
  
              if (term->opcode == ir::PTXInstruction::Bra) {
                if (term->d.identifier == (*ei1)->tail->label)
                  term->d = std::move(ir::PTXOperand((*it1).second->label));
              }
              
              _kernel->cfg()->remove_edge(*ei1);
            }
            // edge 2 is found in ValueMap & edge 1 is not
            else if (!found1 && found2) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, (*it2).second, (*ei2)->type));
  
              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(BB->instructions.back());
  
              if (term->opcode == ir::PTXInstruction::Bra) {
                if (term->d.identifier == (*ei2)->tail->label)
                  term->d = std::move(ir::PTXOperand((*it2).second->label));
              }
              
              _kernel->cfg()->remove_edge(*ei2);
            }
          }
        }
 
        if (TopExitBB != _kernel->cfg()->end()) {
          ir::PTXInstruction* setp = new ir::PTXInstruction(ir::PTXInstruction::SetP);
          setp->a = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                  ir::PTXOperand::u32, fp));
          setp->b = std::move(ir::PTXOperand(ir::PTXOperand::Immediate,
                  ir::PTXOperand::u32, 1));
          setp->b.imm_uint = 1;
          setp->d = std::move(ir::PTXOperand(ir::PTXOperand::Register,
                  ir::PTXOperand::u32, _kernel->dfg()->newRegister()));
          setp->d.type = ir::PTXOperand::pred;
          setp->type = ir::PTXOperand::u32;
          setp->comparisonOperator = ir::PTXInstruction::Eq;
          NewCmpBB->instructions.push_back(setp);

          ir::PTXInstruction* bra = new ir::PTXInstruction(ir::PTXInstruction::Bra);
          bra->d = std::move(ir::PTXOperand(i->second->label));
          bra->pg = setp->d;
          NewCmpBB->instructions.push_back(bra);
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(NewCmpBB, i->second, ir::Edge::Branch));
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(NewCmpBB, TopExitBB, ir::Edge::FallThrough));
        }
        else {
          ir::PTXInstruction* bra = new ir::PTXInstruction(ir::PTXInstruction::Bra);
          bra->d = std::move(ir::PTXOperand(i->second->label));
          bra->uni = true;
          NewCmpBB->instructions.push_back(bra);
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(NewCmpBB, i->second, ir::Edge::Branch));
        }
 
 
        TopExitBB = NewCmpBB;
      }
  
      if (N->exitBB == _kernel->cfg()->end()) 
        _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(N->entryBB, TopExitBB, ir::Edge::Dummy)); 
      stopCut = true;
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

      // Clone BasicBlocks to the new function
      for (BBSetTy::iterator BI = N->containedBB.begin(), BE = N->containedBB.end(); BI != BE; ++BI){
        ir::ControlFlowGraph::iterator BB = *BI;
        char tmp[20];
        sprintf(tmp, "_backward%d", index++);
        ir::ControlFlowGraph::iterator ClonedBB = _kernel->cfg()->clone_block(BB, tmp);
        ValueMap[BB] = ClonedBB;
        
        if (BB == N->entryBB) clonedEntryBB = ClonedBB;
      }
  
      // For each BasicBlock
      // Remap Values here for Instructions
      for (ValueToValueMapTy::iterator VMI = ValueMap.begin(), VME = ValueMap.end(); VMI != VME; ++VMI) { 
        std::pair<ir::ControlFlowGraph::iterator, ir::ControlFlowGraph::iterator> ValuePair = *VMI;
        ir::BasicBlock::EdgePointerVector edges = ValuePair.first->out_edges;

        if (edges.size() == 1) {
          ir::BasicBlock::EdgePointerVector::iterator ei = edges.begin();
          ValueToValueMapTy::iterator it = ValueMap.find((*ei)->tail);

          // found in ValueMap
          if (it != ValueMap.end() && (*ei)->tail != N->entryBB) {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it).second, (*ei)->type));

            ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

            if (term->opcode == ir::PTXInstruction::Bra && term->d.identifier == (*ei)->tail->label)
              term->d = std::move(ir::PTXOperand((*it).second->label));
          } 
          // not found in ValueMap
          else {
            ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei)->tail, ir::Edge::Branch));

            if ((*ei)->type == ir::Edge::FallThrough) {
              if (term->opcode != ir::PTXInstruction::Bra) { 
                ir::PTXInstruction* branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
                branch->uni = true;
                branch->d = std::move(ir::PTXOperand((*ei)->tail->label));
                ValuePair.second->instructions.push_back(branch);
              }
            } 
          }
        } else if (edges.size() == 2) {
          ir::BasicBlock::EdgePointerVector::iterator ei = edges.begin();
          ir::BasicBlock::EdgePointerVector::iterator ei1 = ei;
          ++ei;
          ir::BasicBlock::EdgePointerVector::iterator ei2 = ei;

          ValueToValueMapTy::iterator it1 = ValueMap.find((*ei1)->tail);
          ValueToValueMapTy::iterator it2 = ValueMap.find((*ei2)->tail);

          bool found1 = (it1 != ValueMap.end() && (*ei1)->tail != N->entryBB);
          bool found2 = (it2 != ValueMap.end() && (*ei2)->tail != N->entryBB);

          // both found in ValueMap
          if (found1 && found2) {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it1).second, (*ei1)->type));
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it2).second, (*ei2)->type));

            ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

            if (term->opcode == ir::PTXInstruction::Bra) {
              if (term->d.identifier == (*ei1)->tail->label)
                term->d = std::move(ir::PTXOperand((*it1).second->label));
              else if (term->d.identifier == (*ei2)->tail->label)
                term->d = std::move(ir::PTXOperand((*it2).second->label));
            }
          } 
          // edge 1 is found in ValueMap & edge 2 is not
          else if (found1 && !found2) {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it1).second, ir::Edge::FallThrough));
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei2)->tail, ir::Edge::Branch));

            ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

            if (term->opcode == ir::PTXInstruction::Bra) {
              if (term->d.identifier == (*ei1)->tail->label)
                term->d = std::move(ir::PTXOperand((*ei2)->tail->label));
           }
          }
          // edge 2 is found in ValueMap & edge 1 is not
          else if (!found1 && found2) {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it2).second, ir::Edge::FallThrough));
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei1)->tail, ir::Edge::Branch));

            ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

            if (term->opcode == ir::PTXInstruction::Bra) {
              if (term->d.identifier == (*ei2)->tail->label)
                term->d = std::move(ir::PTXOperand((*ei1)->tail->label));
            }
          }
          // neither is in ValueMap 
          else if (!found1 && !found2) {
            ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

            if ((*ei1)->type == ir::Edge::Branch && (*ei2)->type == ir::Edge::FallThrough) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei1)->tail, ir::Edge::FallThrough));
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei2)->tail, ir::Edge::Branch));

              if (term->opcode == ir::PTXInstruction::Bra) {
                if (term->d.identifier == (*ei1)->tail->label)
                  term->d = std::move(ir::PTXOperand((*ei2)->tail->label));
              }
            }
            else if ((*ei1)->type == ir::Edge::FallThrough && (*ei2)->type == ir::Edge::Branch) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei1)->tail, ir::Edge::Branch));
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei2)->tail, ir::Edge::FallThrough));

              if (term->opcode == ir::PTXInstruction::Bra) {
                if (term->d.identifier == (*ei2)->tail->label)
                  term->d = std::move(ir::PTXOperand((*ei1)->tail->label));
              }
            }
          }
        }
      }

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
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, ValueMap[i->second], ir::Edge::Branch)); 
          } else if (i->first->get_fallthrough_edge()->tail == i->second) {
            _kernel->cfg()->remove_edge(i->first->get_fallthrough_edge());
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, ValueMap[i->second], ir::Edge::FallThrough)); 
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
   
        // Clone BasicBlocks to the new function
        for (BBSetTy::iterator BI = N->containedBB.begin(), BE = N->containedBB.end(); BI != BE; ++BI){
          ir::ControlFlowGraph::iterator BB = *BI;
          char tmp[20];
          sprintf(tmp, "_forward%d", index++);
          ir::ControlFlowGraph::iterator ClonedBB = _kernel->cfg()->clone_block(BB, tmp);
          ValueMap[BB] = ClonedBB;
        }
    
        // For each BasicBlock
        // Remap Values here for Instructions
        for (ValueToValueMapTy::iterator VMI = ValueMap.begin(), VME = ValueMap.end(); VMI != VME; ++VMI) { 
          std::pair<ir::ControlFlowGraph::iterator, ir::ControlFlowGraph::iterator> ValuePair = *VMI;
          ir::BasicBlock::EdgePointerVector edges = ValuePair.first->out_edges;

          if (edges.size() == 1) {
            ir::BasicBlock::EdgePointerVector::iterator ei = edges.begin();
            ValueToValueMapTy::iterator it = ValueMap.find((*ei)->tail);

            // found in ValueMap
            if (it != ValueMap.end()) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it).second, (*ei)->type));

              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

              if (term->opcode == ir::PTXInstruction::Bra && term->d.identifier == (*ei)->tail->label)
                term->d = std::move(ir::PTXOperand((*it).second->label));
            } 
            // not found in ValueMap
            else {
              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei)->tail, ir::Edge::Branch));

              if ((*ei)->type == ir::Edge::FallThrough) {
                if (term->opcode != ir::PTXInstruction::Bra) { 
                  ir::PTXInstruction* branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
                  branch->uni = true;
                  branch->d = std::move(ir::PTXOperand((*ei)->tail->label));
                  ValuePair.second->instructions.push_back(branch);
                }
              } 
            }
          } else if (edges.size() == 2) {
            ir::BasicBlock::EdgePointerVector::iterator ei = edges.begin();
            ir::BasicBlock::EdgePointerVector::iterator ei1 = ei;
            ++ei;
            ir::BasicBlock::EdgePointerVector::iterator ei2 = ei;

            ValueToValueMapTy::iterator it1 = ValueMap.find((*ei1)->tail);
            ValueToValueMapTy::iterator it2 = ValueMap.find((*ei2)->tail);

            // both found in ValueMap
            if (it1 != ValueMap.end() && it2 != ValueMap.end()) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it1).second, (*ei1)->type));
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it2).second, (*ei2)->type));

              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

              if (term->opcode == ir::PTXInstruction::Bra) {
                if (term->d.identifier == (*ei1)->tail->label)
                  term->d = std::move(ir::PTXOperand((*it1).second->label));
                else if (term->d.identifier == (*ei2)->tail->label)
                  term->d = std::move(ir::PTXOperand((*it2).second->label));
              }
            } 
            // edge 1 is found in ValueMap & edge 2 is not
            else if (it1 != ValueMap.end() && it2 == ValueMap.end()) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it1).second, ir::Edge::FallThrough));
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei2)->tail, ir::Edge::Branch));

              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

              if (term->opcode == ir::PTXInstruction::Bra) {
                if (term->d.identifier == (*ei1)->tail->label)
                  term->d = std::move(ir::PTXOperand((*ei2)->tail->label));
             }
            }
            // edge 2 is found in ValueMap & edge 1 is not
            else if (it1 == ValueMap.end() && it2 != ValueMap.end()) {
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*it2).second, ir::Edge::FallThrough));
              _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei1)->tail, ir::Edge::Branch));

              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

              if (term->opcode == ir::PTXInstruction::Bra) {
                if (term->d.identifier == (*ei2)->tail->label)
                  term->d = std::move(ir::PTXOperand((*ei1)->tail->label));
              }
            }
            // neither is in ValueMap 
            else if (it1 == ValueMap.end() && it2 == ValueMap.end()) {
              ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(ValuePair.second->instructions.back());

              if ((*ei1)->type == ir::Edge::Branch && (*ei2)->type == ir::Edge::FallThrough) {
                _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei1)->tail, ir::Edge::FallThrough));
                _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei2)->tail, ir::Edge::Branch));

                if (term->opcode == ir::PTXInstruction::Bra) {
                  if (term->d.identifier == (*ei1)->tail->label)
                    term->d = std::move(ir::PTXOperand((*ei2)->tail->label));
                }
              }
              else if ((*ei1)->type == ir::Edge::FallThrough && (*ei2)->type == ir::Edge::Branch) {
                _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei1)->tail, ir::Edge::Branch));
                _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(ValuePair.second, (*ei2)->tail, ir::Edge::FallThrough));

                if (term->opcode == ir::PTXInstruction::Bra) {
                  if (term->d.identifier == (*ei2)->tail->label)
                    term->d = std::move(ir::PTXOperand((*ei1)->tail->label));
                }
              }
            }
          }
        }
 
        ir::PTXInstruction *bra = static_cast<ir::PTXInstruction *>(i->first->instructions.back());

        if (bra->opcode == ir::PTXInstruction::Bra) {
          if (bra->d.identifier == i->second->label) {
            bra->d = std::move(ir::PTXOperand(ValueMap[i->second]->label));
            _kernel->cfg()->remove_edge(i->first->get_branch_edge());
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, ValueMap[i->second], ir::Edge::Branch)); 
          } else if (i->first->get_fallthrough_edge()->tail == i->second) {
            _kernel->cfg()->remove_edge(i->first->get_fallthrough_edge());
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, ValueMap[i->second], ir::Edge::FallThrough)); 
          }
        } else {
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i->first, ValueMap[i->second], ir::Edge::Branch));

          ir::PTXInstruction* branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
          branch->uni = true;
          branch->d = std::move(ir::PTXOperand(ValueMap[i->second]->label));
          i->first->instructions.push_back(branch);
          _kernel->cfg()->remove_edge(i->first->get_fallthrough_edge()); 
        }
      } 
  
      return change;
    }
  
    return change;  
  } 
  
  void StructuralTransform::runOnKernel(ir::Kernel& k) {
    bool change = false;
    _kernel = static_cast<ir::PTXKernel *>(&k);
    index = 0;
  
    SA.runOnKernel(_kernel);
  
    while (SA.unstructuredBRVec.size() > 0) {
      for (ir::ControlFlowGraph::iterator i = _kernel->cfg()->begin(), e = _kernel->cfg()->end(); i != e; ++i) {
        ir::BasicBlock::EdgePointerVector edges = i->out_edges;
    
        if (edges.size() == 1) {
          ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(i->instructions.back());
      
          if (term->opcode != ir::PTXInstruction::Bra) {
            ir::PTXInstruction* branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
            branch->uni = true;
            branch->d = std::move(ir::PTXOperand((*(edges.begin()))->tail->label));
            i->instructions.push_back(branch);
     
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i, (*(edges.begin()))->tail, ir::Edge::Branch)); 
            _kernel->cfg()->remove_edge(i->get_fallthrough_edge());
          }
        }
      }

      NodeTy *entry = *(SA.Net.begin()); 

      stopCut = false;  

      for (NodeSetTy::iterator i = SA.unreachableNodeSet.begin(), e = SA.unreachableNodeSet.end(); i != e; ++i) {
        if (Cut(*i)) {
          change = true;

          goto ANALYSIS;
        }
      }

      if (ForwardCopy(entry)) {
        change = true;
  
        goto ANALYSIS;
      }

      if (Cut(entry)) {
        change = true;

        goto ANALYSIS;
      }
  
      if (BackwardCopy(entry)) {
        change = true;
  
        goto ANALYSIS;
      }
  
  
  ANALYSIS:
      SA.unstructuredBRVec.clear();
  
      SA.unreachableNodeSet.clear();

      SA.Net.clear();
   
      SA.runOnKernel(_kernel);
    }
  }
}

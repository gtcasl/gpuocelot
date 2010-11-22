//- llvm/Transform/Ocelot/StructuralAnalysis.h - Structural Analysis - *C++ -*-// 
// 
//                     The LLVM Compiler Infrastructure 
// 
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details. 
// 
//===----------------------------------------------------------------------===// 
// 
// This file defines the class of Structural Analysis which will return the 
// control tree and unstructured branches of a function 
// 
//===----------------------------------------------------------------------===// 
 
#include <ocelot/analysis/interface/AssignFallThroughEdge.h>

namespace analysis {  
  void AssignFallThroughEdge::replaceWithDummyEdge() {
    for(ir::ControlFlowGraph::iterator i = _kernel->cfg()->begin(),
                                       e = _kernel->cfg()->end();
                                       i != e; ++i) {
      ir::BasicBlock::EdgePointerVector edges = i->out_edges;

      for (ir::BasicBlock::EdgePointerVector::iterator ei = edges.begin(), ee = edges.end(); ei != ee; ++ei) {
        ir::ControlFlowGraph::edge_iterator oldEdge = *ei;

        if (oldEdge->type == ir::Edge::Branch || oldEdge->type == ir::Edge::FallThrough) {
          ir::ControlFlowGraph::iterator oldDest = oldEdge->tail;
          _kernel->cfg()->remove_edge(oldEdge);
          _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(i, oldDest, ir::Edge::Dummy));
        }
      }
    }
  }

  void AssignFallThroughEdge::buildSimpleCFG() {
    for(ir::ControlFlowGraph::iterator i = _kernel->cfg()->begin(),
                                       e = _kernel->cfg()->end();
                                       i != e; ++i) {
      NodeTy *n = new NodeTy;
      n->BB = i;
      N.insert(n);
      BB2NodeMap[i] = n;
    }

    for(ir::ControlFlowGraph::iterator i = _kernel->cfg()->begin(),
                                       e = _kernel->cfg()->end();
                                       i != e; ++i) {
      NodeTy *n = BB2NodeMap[i];

      ir::ControlFlowGraph::BlockPointerVector PredVec = i->predecessors;

      for (ir::ControlFlowGraph::BlockPointerVector::iterator PI = PredVec.begin(), E = PredVec.end(); PI != E; ++PI) {
        NodeTy *p = BB2NodeMap[*PI];
        n->predNode.insert(p);
      }

      ir::ControlFlowGraph::BlockPointerVector SuccVec = i->successors;

      for (ir::ControlFlowGraph::BlockPointerVector::iterator SI = SuccVec.begin(), E = SuccVec.end(); SI != E; ++SI) {
        NodeTy *s = BB2NodeMap[*SI];
        n->succNode.insert(s);
      }
    }
  }

  void AssignFallThroughEdge::DFSPostorder(NodeTy *x) {
    visit[x] = true;
    preTree[x] = ++preMax;

    for (NodeSetTy::iterator i = x->succNode.begin(),
                             e = x->succNode.end();
                             i != e; ++i) {
      NodeTy *y = *i;

      if (visit.count(y) == 0) 
        DFSPostorder(y);
      else if (postTree[y] == 0 || preTree[x] == preTree[y])
        backEdgeVec.push_back(std::make_pair(x, y));
    }

    postMax++;
    postTree[x] = postMax;
  }

  void AssignFallThroughEdge::assignBackEdge() {
    for (EdgeVecTy::iterator i = backEdgeVec.begin(), e = backEdgeVec.end(); i != e; ++i) {
      NodeTy *srcNode = i->first;
      NodeTy *dstNode = i->second;
      ir::ControlFlowGraph::iterator srcBB = srcNode->BB;
      ir::ControlFlowGraph::iterator dstBB = dstNode->BB;

      srcNode->succNode.erase(dstNode);
      dstNode->predNode.erase(srcNode);
      
      ir::ControlFlowGraph::edge_iterator edge = srcBB->get_edge(dstBB); 
      _kernel->cfg()->remove_edge(edge);
      _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(srcBB, dstBB, ir::Edge::Branch));
    }
  }

  void AssignFallThroughEdge::findEntryNode(NodeSetTy &S) {
    for (NodeSetTy::iterator i = N.begin(), e = N.end(); i != e; ++i) {
      if ((*i)->predNode.size() == 0)
        S.insert(*i); 
    }
  }

  NodeTy * AssignFallThroughEdge::pickOneNode(NodeSetTy &S) {
    int min = preMax + 1;
    NodeTy *tmpNode = NULL;

    for (NodeSetTy::iterator i = S.begin(), e = S.end(); i != e; ++i) {
      if (preTree[*i] < min) {
        min = preTree[*i];
        tmpNode = *i;
      }
    }

    return tmpNode;
  }

  void AssignFallThroughEdge::topoSort() {
    NodeSetTy S;

    findEntryNode(S);
    sortedNodes.clear();
  
    while (S.size() > 0) { 
      NodeTy *n = pickOneNode(S);
      
      sortedNodes.push_back(n);
      sortedVal[n] = sortedMax++;

      for (NodeSetTy::iterator i = n->succNode.begin(),
                               e = n->succNode.end();
                               i != e; ++i) { 
        NodeTy *succ = *i;

        succ->predNode.erase(n); 

        if (succ->predNode.size() == 0) 
          S.insert(succ);
      }
      
      n->succNode.clear(); 
    }
  }

  void AssignFallThroughEdge::adjustBraInst() {
    for(ir::ControlFlowGraph::iterator i = _kernel->cfg()->begin(),
                                       e = _kernel->cfg()->end();
                                       i != e; ++i) {
      ir::PTXInstruction *term = static_cast<ir::PTXInstruction *>(i->instructions.back());

      if (term->opcode == ir::PTXInstruction::Bra) {
        if (!term->uni) {
          ir::ControlFlowGraph::edge_iterator braEdge = i->get_branch_edge();
          ir::ControlFlowGraph::iterator braDst = braEdge->tail;

          if (braDst->label != term->d.identifier) {
            term->d = std::move(ir::PTXOperand(braDst->label));

            switch(term->pg.condition) {
            case ir::PTXOperand::Pred:
              term->pg.condition = ir::PTXOperand::InvPred;
              break;
            case ir::PTXOperand::InvPred:
              term->pg.condition = ir::PTXOperand::Pred;
              break;
            case ir::PTXOperand::PT:
              term->pg.condition = ir::PTXOperand::nPT;
              break;
            case ir::PTXOperand::nPT:
              term->pg.condition = ir::PTXOperand::PT;
              break;
            }
          } 
        } else {
          if (i->has_branch_edge()) { 
            ir::ControlFlowGraph::edge_iterator braEdge = i->get_branch_edge();
            ir::ControlFlowGraph::iterator braDst = braEdge->tail;
            term->d = std::move(ir::PTXOperand(braDst->label));
          } else {
            i->instructions.pop_back();
          }
        }
      } else {
        if (i->has_branch_edge()) { 
          ir::ControlFlowGraph::edge_iterator braEdge = i->get_branch_edge();
          ir::ControlFlowGraph::iterator braDst = braEdge->tail;
          term->d = std::move(ir::PTXOperand(braDst->label));
        } else {
          i->instructions.pop_back();
        }
      }
    }
  }

  void AssignFallThroughEdge::assignEdges() {
    buildSimpleCFG();

    NodeTy *entry = BB2NodeMap[_kernel->cfg()->get_entry_block()];

    postMax = preMax = 0;

    DFSPostorder(entry);

    assignBackEdge();

    sortedMax = 0;

    topoSort();

    hasIncomingFallThroughNode.clear();

    for (NodeVecTy::iterator i = sortedNodes.begin(), e = sortedNodes.end(); i != e; ++i) {
      NodeTy *node = *i;
      ir::ControlFlowGraph::iterator BB = node->BB;
      ir::BasicBlock::EdgePointerVector edges = BB->out_edges;

      if (edges.size() == 2) {
        ir::BasicBlock::EdgePointerVector::iterator ei = edges.begin();
        ir::ControlFlowGraph::edge_iterator edge1 = *ei;
        ++ei;
        ir::ControlFlowGraph::edge_iterator edge2 = *ei;

        if (edge1->type == ir::Edge::Dummy && edge2->type == ir::Edge::Dummy) {
          ir::ControlFlowGraph::iterator dstBB1 = edge1->tail;
          NodeTy *dstNode1 = BB2NodeMap[dstBB1];
          ir::ControlFlowGraph::iterator dstBB2 = edge2->tail;
          NodeTy *dstNode2 = BB2NodeMap[dstBB2];
    
          ir::ControlFlowGraph::iterator closeBB, remoteBB;
    
          if (sortedVal[dstNode1] < sortedVal[dstNode2]) {
            closeBB = dstBB1;
            remoteBB = dstBB2;
          } else {
            closeBB = dstBB2;
            remoteBB = dstBB1;
          }
    
          _kernel->cfg()->remove_edge(edge1);
          _kernel->cfg()->remove_edge(edge2);
      
          if (hasIncomingFallThroughNode.count(closeBB) == 0) {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, closeBB, ir::Edge::FallThrough));
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, remoteBB, ir::Edge::Branch));
            hasIncomingFallThroughNode.insert(closeBB); 
          } else if (hasIncomingFallThroughNode.count(remoteBB) == 0) {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, remoteBB, ir::Edge::FallThrough));
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, closeBB, ir::Edge::Branch));
            hasIncomingFallThroughNode.insert(remoteBB); 
          } else {
            ir::ControlFlowGraph::iterator NewBB = _kernel->cfg()->insert_block(ir::BasicBlock(BB->label + "_fallthrough",
                    _kernel->cfg()->newId()));
            ir::PTXInstruction* branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
            branch->uni = true;
            branch->d = std::move(ir::PTXOperand(closeBB->label));
            NewBB->instructions.push_back(branch);

            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(NewBB, closeBB, ir::Edge::Branch));
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, NewBB, ir::Edge::FallThrough));
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, NewBB, ir::Edge::Branch));
          }
        } else {
          ir::ControlFlowGraph::iterator remainBB;

          if (edge1->type == ir::Edge::Branch) {
            remainBB = edge2->tail;
            _kernel->cfg()->remove_edge(edge2);
          }
          else if (edge2->type == ir::Edge::Branch) {
            remainBB = edge1->tail;          
            _kernel->cfg()->remove_edge(edge1);
          }

          if (hasIncomingFallThroughNode.count(remainBB) == 0) {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, remainBB, ir::Edge::FallThrough));
            hasIncomingFallThroughNode.insert(remainBB); 
          } else {
            ir::ControlFlowGraph::iterator NewBB = _kernel->cfg()->insert_block(ir::BasicBlock(BB->label + "_fallthrough",
                    _kernel->cfg()->newId()));
            ir::PTXInstruction* branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
            branch->uni = true;
            branch->d = std::move(ir::PTXOperand(remainBB->label));
            NewBB->instructions.push_back(branch);

            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(NewBB, remainBB, ir::Edge::Branch));
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, NewBB, ir::Edge::FallThrough));
          }
        }
      } else if (edges.size() == 1) {
        ir::ControlFlowGraph::edge_iterator edge = *(edges.begin());

        if (edge->type != ir::Edge::Branch) {
          ir::ControlFlowGraph::iterator dstBB = edge->tail;
          _kernel->cfg()->remove_edge(edge);

          if (hasIncomingFallThroughNode.count(dstBB) == 0) {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, dstBB, ir::Edge::FallThrough));
            hasIncomingFallThroughNode.insert(dstBB); 
          } else {
            _kernel->cfg()->insert_edge(ir::ControlFlowGraph::Edge(BB, dstBB, ir::Edge::Branch));
            hasIncomingFallThroughNode.insert(dstBB); 
          }
        }
      }
    } 

    adjustBraInst(); 
  } 
}

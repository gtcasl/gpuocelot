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
 
#ifndef LLVM_ANALYSIS_ASSIGNFALLTHROUGHEDGE_H 
#define LLVM_ANALYSIS_ASSIGNFALLTHROUGHEDGE_H

#include <ocelot/analysis/interface/Pass.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>

#include <hydrazine/implementation/debug.h>

#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

namespace ir {
  class PTXKernel;
}

namespace analysis {
  typedef struct Node {
    ir::ControlFlowGraph::iterator BB;  // Map to the corresponding ir::BasicBlock * if it is original
    std::set<struct Node *> predNode; // Predecessor of the node
    std::set<struct Node *> succNode; // Successor of the node
  } NodeTy;

  typedef std::unordered_map<ir::ControlFlowGraph::iterator, NodeTy *> BB2NodeMapTy;
  typedef std::set<NodeTy *> NodeSetTy;
  typedef std::vector<NodeTy *> NodeVecTy;
  typedef std::pair<NodeTy *, NodeTy *> EdgeTy;
  typedef std::vector<EdgeTy> EdgeVecTy;
  typedef std::map<NodeTy *, bool> VisitMapTy;

  class AssignFallThroughEdge {
  public:
    AssignFallThroughEdge(ir::PTXKernel *k) {_kernel = k;}

    void replaceWithDummyEdge();

    void assignEdges();

  private:
    ir::PTXKernel* _kernel;

    BB2NodeMapTy BB2NodeMap;    

    NodeSetTy N;

    int postMax, preMax, sortedMax;

    VisitMapTy visit;
    
    std::unordered_set<ir::ControlFlowGraph::iterator> hasIncomingFallThroughNode;

    std::map<NodeTy *, int> preTree, postTree, sortedVal;

    EdgeVecTy backEdgeVec;

    NodeVecTy sortedNodes;
 
    void buildSimpleCFG();

    void DFSPostorder(NodeTy *x);

    void assignBackEdge();

    void topoSort();

    void findEntryNode(NodeSetTy &S);

    NodeTy *pickOneNode(NodeSetTy &S);

    void adjustBraInst();
  };
}

#endif

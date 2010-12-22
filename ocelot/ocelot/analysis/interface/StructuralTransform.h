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
 
#ifndef LLVM_ANALYSIS_STRUCTURALTRANSFORM_H 
#define LLVM_ANALYSIS_STRUCTURALTRANSFORM_H

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/analysis/interface/StructuralAnalysis.h> 
#include <ocelot/analysis/interface/AssignFallThroughEdge.h>

#include <unordered_map>

namespace ir {
  class PTXKernel;
}

namespace analysis {
  // StructuralTransform - This class holds all the methods and data structures 
  class StructuralTransform : public KernelPass {
  public:
    StructuralTransform() : KernelPass() {}
    void initialize(const ir::Module& m) {};
    void runOnKernel(ir::Kernel& k);
    void finalize() {};

  private:
    int index;

    typedef std::unordered_map<ir::ControlFlowGraph::iterator, ir::ControlFlowGraph::iterator> ValueToValueMapTy;

    ir::PTXKernel* _kernel;

    ir::ControlFlowGraph::iterator SplitBlockPredecessors(ir::ControlFlowGraph::iterator BB, BBVecTy::iterator begin, int size);

    // Algorithm 2 of Zhang's paper -- elimination of outgoing branches
    bool Cut(NodeTy *N); 

    // Algorithm 3 of Zhang's paper -- elimination of backward branches
    bool BackwardCopy(NodeTy *N);

    // Algorithm 4 of Zhang's paper -- elimination of Forward branches
    bool ForwardCopy(NodeTy *N);

    bool stopCut;

    class StructuralAnalysis SA;

    class AssignFallThroughEdge *AF;
  };
}

#endif

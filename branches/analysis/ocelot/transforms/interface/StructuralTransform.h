/*! \file   StructuralTransform.h
	\author Haicheng Wu <hwu36@gatech.edu>
	\date   Monday April 4, 2011
	\brief  The header file for the StructuralTransform pass.
*/


//===----------------------------------------------------------------------===// 
// 
// This file defines the class of Structural Analysis which will return the 
// control tree and unstructured branches of a function 
// 
//===----------------------------------------------------------------------===// 
 
#ifndef LLVM_ANALYSIS_STRUCTURALTRANSFORM_H 
#define LLVM_ANALYSIS_STRUCTURALTRANSFORM_H

// Ocelot Includes
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/analysis/interface/StructuralAnalysis.h> 
#include <ocelot/analysis/interface/AssignFallThroughEdge.h>

// Stanard Library Includes
#include <unordered_map>
#include <list>

namespace ir {
  class PTXKernel;
}

namespace analysis {
  // StructuralTransform - This class holds all the methods and data structures 
  class StructuralTransform : public KernelPass {
  public:
    StructuralTransform() : KernelPass() {}
    void initialize(const ir::Module& m) {};
    void runOnKernel(ir::IRKernel& k);
    void finalize() {};

  private:
    int index;

    typedef std::unordered_map<ir::ControlFlowGraph::iterator,
    	ir::ControlFlowGraph::iterator> ValueToValueMapTy;

    ir::PTXKernel* _kernel;

    ir::ControlFlowGraph::iterator SplitBlockPredecessors(
    	ir::ControlFlowGraph::iterator BB, BBVecTy::iterator begin, int size);

    // Algorithm 2 of Zhang's paper -- elimination of outgoing branches
    bool Cut(NodeTy *N); 

    // Algorithm 3 of Zhang's paper -- elimination of backward branches
    bool BackwardCopy(NodeTy *N);

    // Algorithm 4 of Zhang's paper -- elimination of Forward branches
    bool ForwardCopy(NodeTy *N);

    bool stopCut;

    class StructuralAnalysis SA;

    class AssignFallThroughEdge *AF;

    const NodeTy* get_root_node() const;

    ///*! \brief Get iterator to the basic block in the cfg */
    const ir::ControlFlowGraph::const_iterator bb(NodeTy *node) const;
    
    typedef std::list<const NodeTy *> NodeListTy;
    
    ///*! \brief Get the children
    // *
    // * It should return an ordered container so PTXToILTranslator can emit 
    // blocks in order.
    // */
    const NodeListTy& children(const NodeTy *node) const;
    
    ///*! \brief Get condition node from IfThen and IfThenElse
    // *
    // * The last instruction of the condition node should be branch. 
    // */
    const NodeTy* cond(const NodeTy *node) const;
    ///*! \brief Get if-true node from IfThen and IfThenElse */
    const NodeTy* ifTrue(const NodeTy *node) const;
    ///*! \brief Get if-false node from IfThenElse */
    const NodeTy* ifFalse(const NodeTy *node) const;
  };
}

#endif

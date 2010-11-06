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
 
#ifndef LLVM_ANALYSIS_STRUCTURALANALYSIS_H 
#define LLVM_ANALYSIS_STRUCTURALANALYSIS_H

#include "llvm/Pass.h"
#include "llvm/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CFG.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/DenseMap.h"
#include <set>

using namespace llvm;
using namespace std;

typedef enum {TREE, FORWARD, BACK, CROSS} EdgeClass;

typedef pair<BasicBlock *, BasicBlock *> EdgeLLVMTy;


typedef SmallVector<EdgeLLVMTy, 16> EdgeVecTy;

typedef set<BasicBlock *> BBSetTy;

typedef SmallVector<BasicBlock *, 8> BBVecTy;

// Types defined in Fig 7.38 of Muchnick book
typedef enum {
  Nil,
  Block,
  IfThen,
  IfThenElse,
  Case,
  SelfLoop,
  NaturalLoop,
  Improper
} RegionTy;

// NodeTy - This type is used for the CFG node
typedef struct Node {
  bool isCombined; // Whether it is an original or combined from original 
  BasicBlock *BB;  // Map to the corresponding BasicBlock if it is original
  set<struct Node *> predNode; // Predecessor of the node
  set<struct Node *> succNode; // Successor of the node
  struct Node *entryNode;                 // If isCombined is true,it points to the entry of the nodeset
  struct Node *parentNode;                 // Parent Node in Control Tree
  set<struct Node *> childNode; // Child Nodes in Control Tree
  EdgeVecTy outgoingBR;  // Outgoing Branches of a loop
  EdgeVecTy incomingBR;  // Incoming Branches of a loop
  BasicBlock *entryBB;   // The entry Basic Block
  BasicBlock *exitBB;    // The exit Basic Block
  BBSetTy containedBB;            // BasicBlocks contained in this node
  EdgeVecTy incomingForwardBR;      // The shared code of an unstructured branch 
  RegionTy nodeType;        // The type of the node
  bool isLoopHeader;
  struct Node *loopExitNode;
} NodeTy;

// NodeSetTy - used to holds nodes in a set 
typedef set<NodeTy *> NodeSetTy;

// BB2NodeMapTy - Map BasicBlock to NodeTy
typedef DenseMap<BasicBlock *, NodeTy *> BB2NodeMapTy;

typedef DenseMap<NodeTy *, NodeTy *> Node2NodeMapTy;

typedef DenseMap<NodeTy *, RegionTy> Node2RegionTyMapTy;

typedef DenseMap<NodeTy *, NodeSetTy *> Node2NodeSetMapTy;

typedef pair<NodeTy *, NodeTy *> EdgeTy;

typedef DenseMap<EdgeTy, EdgeClass> Edge2ClassMapTy;

typedef set<EdgeTy> EdgeSetTy;

typedef DenseMap<NodeTy *, bool> VisitMapTy;

namespace {
  // StructuralAnalysis - This class holds all the methods and data structures 
  class StructuralAnalysis {
  public:
//    static char ID; // Pass ID, replacement for typeid

    StructuralAnalysis() {}

    bool runOnFunction(Function &F);

//    virtual void getAnalysisUsage(AnalysisUsage &AU) const {
//      AU.setPreservesAll();
//    }

  private:
    // Global data structure defined in Fig 7.38 of Muchnick book
    // structOf(n) - The region containing node n
    Node2NodeMapTy structOf;

    // structType(n) - The member of RegionTy that is the type of 
    // the region denoted by node n
    Node2RegionTyMapTy structType;

    // structures - The set of all region nodes
    NodeSetTy structures;

    // structNodes - The set of nodes making up the region
    // abstracted to node n
    Node2NodeSetMapTy structNodes;

    // postorder traversal of the flowgraph
    int postCtr, postMax, preMax;
    DenseMap<int, NodeTy *> post;
    VisitMapTy visit, visitPath;
    DenseMap<NodeTy *, int> preTree, postTree;

    // domin - Set of dominators of each node
    Node2NodeSetMapTy domin;

    // iDomin - Set of immediate dominators of each node
    Node2NodeMapTy iDom;

    // edge2ClassMap - map the edge to its class
    Edge2ClassMapTy edge2ClassMap;

    // BB2NodeMap - This var is used to find the Node from BasicBlock;
    BB2NodeMapTy BB2NodeMap;

    // buildSimpleCFG - Build a Simple CFG out of the LLVM CFG
    void buildSimpleCFG(Function &F, NodeSetTy &N);

    // structuralAnalysis - Follow Fig 7.39 of Muchnick book
    void structuralAnalysis(NodeSetTy &N, NodeTy *entry, bool debug);

    // DFSPostorder - Follow Fig 7.40 of Muchnick book 
    void DFSPostorder(NodeSetTy &N, NodeTy *x);

    // acyclicRegionType - Follow Fig 7.41 of Muchnick book
    RegionTy acyclicRegionType(NodeSetTy &N, NodeTy *node, NodeSetTy &nset, NodeTy **entryNode, NodeTy **exitNode, NodeTy *entry);

    // cyclicRegionType - Follow Fig 7.42 of Muchnick book
    RegionTy cyclicRegionType(NodeSetTy &N, NodeSetTy &nset, NodeTy *loopHeaderNode, NodeTy *backEdgeNode, NodeTy **exitNode, NodeTy *entry);

    // reduce - Follow Fig 7.43 of Muchnick book
    NodeTy * reduce(NodeSetTy &N, RegionTy rType, NodeSetTy &nodeSet, NodeTy *entryNode, NodeTy *exitNode);

    // replace - Follow Fig 7.44 of Muchnick book
    void replace(NodeSetTy &N, NodeTy *node, NodeSetTy &nodeSet/*, bool addSelfEdge*/);

    // isImproper - Follow Fig 7.45 of Muchnick book
    bool isImproper(NodeSetTy &N, NodeSetTy &nset, NodeTy *loopHeaderNode, NodeTy *backEdgeNode, NodeTy **exitNode, NodeTy *entry);

    // pathBack - Check if there is a node k such that there is a path from
    // m to k that does not pass through n and an edge k->n that is a back edge
    NodeTy* pathBack(NodeTy *n, NodeSetTy &N, NodeSetTy &reachUnder);

    // isCaseWithDefault - Check if node leads a case block
    bool isCaseWithDefault(NodeSetTy &N, NodeTy * entryNode, NodeTy **exitNode, NodeTy *entry);

    // isCaseWithoutDefault - Check if node leads a case block
    bool isCaseWithoutDefault(NodeSetTy &N, NodeTy * entryNode, NodeTy **exitNode, NodeTy *entry);

    // isImproperCaseWithDefault - Check if node leads a case block with incoming edges
    bool isImproperCaseWithDefault(NodeSetTy &N, NodeTy * entryNode, NodeTy *entry);

    // isImproperCaseoutWithDefault - Check if node leads a case block with incoming edges
    bool isImproperCaseWithoutDefault(NodeSetTy &N, NodeTy * entryNode, NodeTy **exitNode, NodeTy *entry);

    // path(n, m, I) - Return true if there is a path from from n to m 
    //such that all the nodes in it are in I and false otherwise
    bool path(NodeTy *n, NodeTy *m, NodeSetTy &I, NodeTy *esc);

    // compact - Compact nodes in nset into n;
    void compact(NodeSetTy &N, NodeTy *n, NodeSetTy &nset/*, bool addSelfEdge*/);

    // MECEntries(n, nset, N) - Return the set of entry nodes of the smallest
    // multiple-entry cycle of which n is one of the entries
    NodeSetTy MECEntries(NodeSetTy &nset);

    //NCDomin(I, N) - Return the nearest common dominator of the nodes in I
    NodeTy * NCDomin(NodeSetTy &I);

    //mapNode2BB - Return the corresponding BasicBlock of the node
    BasicBlock * mapNode2BB(NodeTy *node);

    // mapBB2Node - Return the corresponding sturcture node of the basic block
    NodeTy *mapBB2Node(BasicBlock *bb); 

    // dumpCTNode - Dump one Control Node
    void dumpCTNode(NodeTy *n);

    // dumpNode - Dump one node
    void dumpNode(NodeTy *node);

    // dominates - Whether node1 dominates node2
    bool dominates(NodeTy *node1, NodeTy *node2);

    // findNearestCommonDominator - Find the nearest common dominator of node1 and node2
    NodeTy *findNearestCommonDominator(NodeTy *node1, NodeTy *node2);

    // domComp(N, r) - Compute all the dominators of each node in a flowgraph
    void domComp(NodeSetTy &N, NodeTy *r);

    // idomComp(N, r) - Compute all the dominators of each node in a flowgraph
    void idomComp(NodeSetTy &N, NodeTy *r);

    // findUnstructuredBR - Record the branch and remove it from CFG 
    void findUnstructuredBR(NodeSetTy &N, NodeTy *srcNode, NodeTy *dstNode, bool needForwardCopy, bool isGoto);

    // findBB - put all Basic Blocks in node into nodeVec
    void findBB (NodeTy *node, BBSetTy *nodeVec);

    // findEntryBB - find the entry Basic Block of the node
    BasicBlock *findEntryBB (NodeTy *node);

    // dumpUnstructuredBR - Dump all found unstructured branches
    void dumpUnstructuredBR();
 
    // isStillReachableFrom entry -Return true if after erasing edge src->dst, dst is still reachable from entry
    bool isStillReachableFromEntry(NodeSetTy &N, NodeTy *entry, NodeTy *dstNode, NodeTy *srcNode);

    // clean - fill in the element of incoming branches and outgoing branches
    void cleanup(NodeTy *node);

    // deleteUnreachableNode - delete nodes that is no longer reachable from the entry
    void deleteUnreachableNodes(NodeSetTy &N, NodeTy *entry);
  };
}

static NodeSetTy Net;

// unstructuredBRVec - store the detected unstructured branches
static EdgeVecTy unstructuredBRVec;

//char StructuralAnalysis::ID = 0;
//static RegisterPass<StructuralAnalysis> Y("structural-analysis", "Structural analysis");

// buildSimpleCFG - Build a Simple CFG out of the LLVM CFG
void StructuralAnalysis::buildSimpleCFG(Function &F, NodeSetTy &N) {
  // Create a simple CFG node for every Basic Block
  for (Function::iterator i = F.begin(), e = F.end(); i != e; ++i) {
    NodeTy *n = new NodeTy;
    n->isCombined = false;
    n->BB = i;
    n->containedBB.insert(i);
    n->isLoopHeader = false;
    n->loopExitNode = NULL;
    n->parentNode = NULL;
 
    N.insert(n);
    BB2NodeMap[i] = n;
  }

  // Setup the edges of the simple CFG
  for (Function::iterator i = F.begin(), e = F.end(); i != e; ++i) {
    NodeTy *n = BB2NodeMap[i];

    // Setup the predecessor of every node
    for (pred_iterator PI = pred_begin(i), E = pred_end(i); PI != E; ++PI) {
      NodeTy *p = BB2NodeMap[*PI];
      n->predNode.insert(p);
    }

    // Setup the successor of every node
    for (succ_iterator SI = succ_begin(i), E = succ_end(i); SI != E; ++SI) {
      NodeTy *s = BB2NodeMap[*SI];
      n->succNode.insert(s);
    }
  }

  // Remove unreachable node
  NodeTy *entry = BB2NodeMap[&(F.getEntryBlock())];

  deleteUnreachableNodes(N, entry); 
}

// structuralAnalysis - Follow Fig 7.39 of Muchnick book
void StructuralAnalysis::structuralAnalysis(NodeSetTy &N, NodeTy *entry, bool debug) {
  NodeTy *n, *p, *entryNode, *exitNode;
  RegionTy rType;
  NodeSetTy nodeSet, reachUnder;

  structOf.clear();
  structType.clear();
  structures.clear();
  structNodes.clear();
  unstructuredBRVec.clear();

  // Handle the case if the Function has only one Basic Block
  if (N.size() == 1) {
    NodeTy *node = new NodeTy;
    NodeTy *singleNode = *(N.begin());
    node->isCombined = true;
    node->childNode.insert(singleNode);
    node->entryNode = singleNode;
    node->exitBB = singleNode->BB;
    node->containedBB.insert(singleNode->BB);
    node->nodeType = Block;
    structType[node] = Block;
    structures.insert(node);
    structNodes[node] = new NodeSetTy;
    structNodes[node]->insert(singleNode);

    singleNode->parentNode = node;
    structures.insert(singleNode);

    N.erase(singleNode);
    N.insert(node);

    return;
  }

  do {
    bool change = false;

    post.clear();
    preTree.clear();
    postTree.clear();

    visit.clear();
    postMax = 0;
    postCtr = 1;
    preMax = 0;

    DFSPostorder(N, entry);

    while (N.size() > 1 && postCtr <= postMax) {

      n = post[postCtr];
//  dumpCTNode(entry);

      if (N.count(n) == 0) continue;
//  dumpUnstructuredBR();
 
      // Locate an acyclic region, if present
      if (n->isLoopHeader && n->loopExitNode) {
        NodeTy *tmpNode = n->loopExitNode;

        while(tmpNode->parentNode) tmpNode = tmpNode->parentNode;

        n->succNode.erase(tmpNode);
        tmpNode->predNode.erase(n);
        n->loopExitNode = tmpNode;
      }
        
      rType = acyclicRegionType(N, n, nodeSet, &entryNode, &exitNode, entry);

      if (n->isLoopHeader && n->loopExitNode) {
        n->succNode.insert(n->loopExitNode);
        n->loopExitNode->predNode.insert(n);
      }

      if (rType == Improper) {
        change = true;

        break;
      }
      else if (rType != Nil) {
        p = reduce(N, rType, nodeSet, entryNode, exitNode);
        change = true;

        if (nodeSet.count(entry)) 
          entry = p;
 
        break; 
      } 
      else {
        NodeTy *backEdgeNode;

        if ((backEdgeNode = pathBack(n, N, reachUnder))) {
          rType = cyclicRegionType(N, reachUnder, n, backEdgeNode, &exitNode, entry);

          if (rType == Improper) {
            change = true;

            break;
          } else if (rType != Nil) {
            change = true;
            p = reduce(N, rType, reachUnder, n, exitNode);

            if (reachUnder.count(entry)) entry = p;

            break;
          } else
            postCtr++;
        } 
        else 
          postCtr++;
      }
    }
    
    if (!change) {
      for (int i = 1; i <= postMax; i++) {
        NodeTy *node = post[i];

        if (node->predNode.size() > 1 && node->succNode.size() == 0) {
          int min = postMax + 1;

          for (NodeSetTy::iterator pi = node->predNode.begin(),
                                   pe = node->predNode.end();
                                   pi != pe; ++pi) {
            NodeTy *preNode = *pi;

            if (postTree[preNode] < min) min = postTree[preNode];
          }

          for (NodeSetTy::iterator pi = node->predNode.begin(),
                                   pe = node->predNode.end();
                                   pi != pe; ++pi) {
            NodeTy *preNode = *pi;

            if (postTree[preNode] != min) {
              if (isStillReachableFromEntry(N, entry, node, preNode)) {
                findUnstructuredBR(N, preNode, node, true, true);
                change = true;
              }
            }
          }

          break;
        }
      } 
    }
    if (debug) {
      dumpCTNode(p);
      dumpUnstructuredBR();
      errs() << "********************\n";
    }

    assert(change != false);
  } while (N.size() != 1);
}

// DFSPostorder - Follow Fig 7.40 of Muchnick book 
void StructuralAnalysis::DFSPostorder(NodeSetTy &N, NodeTy *x) {
  visit[x] = true;
  preTree[x] = ++preMax;
 
  for (NodeSetTy::iterator i = x->succNode.begin(),
                           e = x->succNode.end();
                           i != e; ++i) { 
    NodeTy *y = *i;

    if (visit.count(y) == 0) {
      DFSPostorder(N, y);
      edge2ClassMap[make_pair(x, y)] = TREE;
    }
    else if (preTree[x] < preTree[y])
      edge2ClassMap[make_pair(x, y)] = FORWARD;
    else if (postTree[y] == 0 || preTree[x] == preTree[y])
      edge2ClassMap[make_pair(x, y)] = BACK;
    else 
      edge2ClassMap[make_pair(x, y)] = CROSS;
  }

  postMax++;
  post[postMax] = x;
  postTree[x] = postMax;
}

// acyclicRegionType - Follow Fig 7.41 of Muchnick book
RegionTy StructuralAnalysis::acyclicRegionType(NodeSetTy &N, NodeTy *node, NodeSetTy &nset, NodeTy **entryNode, NodeTy **exitNode, NodeTy *entry) {
  NodeTy *m, *n;
  bool p, s;

  nset.clear();

  // Check for a block containing node
  NodeTy *firstNode, *lastNode;
  firstNode = lastNode = n = node;
  p = true;
  s = (n->succNode.size() == 1);

  while (p && s) {
    lastNode = n;

    if (nset.count(n) == 0) 
      nset.insert(n);
    else 
      return Nil;

    n = *(n->succNode.begin());
    p = (n->predNode.size() == 1);
    s = (n->succNode.size() == 1);
  }

  if (p) { 
    if (nset.count(n) == 0) {
      nset.insert(n);
      lastNode = n;
    }
    else
      return Nil;
  }

  n = node;
  p = (n->predNode.size() == 1);
  s = true;

  while (p && s) {
    firstNode = n;

    if (nset.count(n) == 0  || n == node)
      nset.insert(n);
    else
      return Nil;
    n = *(n->predNode.begin());
    p = (n->predNode.size() == 1);
    s = (n->succNode.size() == 1);
  }

  if (s) {
    if (nset.count(n) == 0 || n == node) {
      firstNode = n; 
      nset.insert(n);
    }
    else
      return Nil;
  }

  if (firstNode->predNode.count(lastNode) > 0) {
    if (nset.size() == 2)
      return Nil;
    else
      nset.erase(firstNode);
  } 

  *entryNode = n;

  if (nset.size() >= 2) {
    if (nset.count(*entryNode) == 0)
      for (NodeSetTy::iterator i = (*entryNode)->succNode.begin(), 
                               e = (*entryNode)->succNode.end();
                               i != e; ++i) 
        if (nset.count(*i) > 0) 
          *entryNode = *i;

    *exitNode = lastNode;

    return Block; 
  }

  *entryNode = node;

  if ((*entryNode)->succNode.size() == 2) {
    NodeSetTy::iterator i = (*entryNode)->succNode.begin();
    m = *i;
    ++i;
    n = *i;

    if (m == *entryNode || n == *entryNode) return Nil;

    if (edge2ClassMap[make_pair(*entryNode, m)] == BACK) return Nil;
    if (edge2ClassMap[make_pair(*entryNode, n)] == BACK) return Nil;
//    if (edge2ClassMap[make_pair(m, *entryNode)] == BACK) return Nil;
//    if (edge2ClassMap[make_pair(n, *entryNode)] == BACK) return Nil;

    // Check for an normal IfThenElse
    if (m->succNode.size() == 1 && n->succNode.size() == 1  
      && m->predNode.size() == 1 && n->predNode.size() == 1
      && *(m->succNode.begin()) == *(n->succNode.begin())
      && *(m->succNode.begin()) != *entryNode) { 
    
//        if (edge2ClassMap[make_pair(n, *(n->succNode.begin()))] != BACK &&
//          edge2ClassMap[make_pair(m, *(m->succNode.begin()))] != BACK) {
      if (edge2ClassMap[make_pair(m, *entryNode)] == BACK) return Nil;
      if (edge2ClassMap[make_pair(n, *entryNode)] == BACK) return Nil;
 
          nset.insert(*entryNode);
          nset.insert(m);
          nset.insert(n);
          *exitNode = *(m->succNode.begin());
 
          return IfThenElse;
        }
    // Check for an IfThenElse with no exit block
    if (m->succNode.size() == 0 && n->succNode.size() == 0  
      && m->predNode.size() == 1 && n->predNode.size() == 1) {
      nset.insert(*entryNode);
      nset.insert(m);
      nset.insert(n);
      *exitNode = NULL;

      return IfThenElse;
    }
    // Check for an IfThen
    // n is the Then part
    else if (n->succNode.size() == 1 && n->predNode.size() == 1 && m == *(n->succNode.begin())) {
      if (edge2ClassMap[make_pair(n, m)] != BACK) {
        if (edge2ClassMap[make_pair(n, *entryNode)] == BACK) return Nil;

        nset.insert(*entryNode);
        nset.insert(n);
        *exitNode = m;
  
        return IfThen;
      }
    } 
    // m is the Then part
    else if (m->succNode.size() == 1 && m->predNode.size() == 1 && n == *(m->succNode.begin())) {
      if (edge2ClassMap[make_pair(m, n)] != BACK) {
        if (edge2ClassMap[make_pair(m, *entryNode)] == BACK) return Nil;

        nset.insert(*entryNode);
        nset.insert(m);
        *exitNode = n;
  
        return IfThen;
      }
    }
    // n is the Then part w/o exiting edge
    else if (n->succNode.size() == 0 && n->predNode.size() == 1) {
      visitPath.clear();

      if (!path(m, *entryNode, N, NULL)) {
        nset.insert(*entryNode);
        nset.insert(n);
        *exitNode = NULL;

        return IfThen;
      } 
    }
    // m is the Then part w/o exiting edge
    else if (m->succNode.size() == 0 && m->predNode.size() == 1) {
      visitPath.clear();

      if (!path(n, *entryNode, N, NULL)) {
        nset.insert(*entryNode);
        nset.insert(m);
        *exitNode = NULL;

        return IfThen;
      }
    }
    // Check for an IfThenElse with incoming edges
    else if (m->succNode.size() == 1 && n->succNode.size() == 1  
      && *(m->succNode.begin()) == *(n->succNode.begin()) 
      && *(m->succNode.begin()) != *entryNode) {
//      if (edge2ClassMap[make_pair(n, *(n->succNode.begin()))] != BACK &&
//        edge2ClassMap[make_pair(m, *(m->succNode.begin()))] != BACK) {

      if (edge2ClassMap[make_pair(m, *entryNode)] == BACK) return Nil;
      if (edge2ClassMap[make_pair(n, *entryNode)] == BACK) return Nil;

      if (n->predNode.count(*(n->succNode.begin())) == 0 &&
        m->predNode.count(*(m->succNode.begin())) == 0) {
      
        if (m->predNode.count(*(m->succNode.begin())) > 0 || n->predNode.count(*(n->succNode.begin())) > 0)
          return Nil;

        bool improperFlag = false;

        if (m->predNode.size() > 1) {
          for (NodeSetTy::iterator pi = m->predNode.begin(), pe = m->predNode.end(); pi != pe; ++pi)  
            if (*pi != *entryNode && isStillReachableFromEntry(N, entry, m, *pi) 
              && edge2ClassMap[make_pair(*pi, m)] != BACK) {
              findUnstructuredBR(N, *pi, m, true, true);          
              improperFlag = true;
            }
        }
  
        if (n->predNode.size() > 1) {
          for (NodeSetTy::iterator pi = n->predNode.begin(), pe = n->predNode.end(); pi != pe; ++pi)  
            if (*pi != *entryNode && isStillReachableFromEntry(N, entry, n, *pi) 
              && edge2ClassMap[make_pair(*pi, n)] != BACK) {
              findUnstructuredBR(N, *pi, n, true, true);          
              improperFlag = true;
            }
        }
   
        if(improperFlag) return Improper;
//      }
      }
    }
    // Check for an IfThen with incoming edges
    // n is the Then part
    else if (n->succNode.size() == 1 && n->predNode.size() > 1 && m == *(n->succNode.begin())) {
      if (edge2ClassMap[make_pair(n, *entryNode)] == BACK) return Nil;

      if (edge2ClassMap[make_pair(n, m)] != BACK) {
        if (n->predNode.count(m) > 0)
          return Nil;

        bool improperFlag = false;

        for (NodeSetTy::iterator pi = n->predNode.begin(), pe = n->predNode.end(); pi != pe; ++pi)  
          if (*pi != *entryNode && isStillReachableFromEntry(N, entry, n, *pi) 
              && edge2ClassMap[make_pair(*pi, n)] != BACK) {
            findUnstructuredBR(N, *pi, n, true, true);          
            improperFlag = true;
          }
        
        if(improperFlag) return Improper;
      }
    } 
    // m is the Then part
    else if (m->succNode.size() == 1 && m->predNode.size() > 1 && n == *(m->succNode.begin())) {
      if (edge2ClassMap[make_pair(m, *entryNode)] == BACK) return Nil;

      if (edge2ClassMap[make_pair(m, n)] != BACK) {
        if (m->predNode.count(n) > 0)
          return Nil;

        bool improperFlag = false;

        for (NodeSetTy::iterator pi = m->predNode.begin(), pe = m->predNode.end(); pi != pe; ++pi)  
          if (*pi != *entryNode && isStillReachableFromEntry(N, entry, m, *pi) 
              && edge2ClassMap[make_pair(*pi, m)] != BACK) {
            findUnstructuredBR(N, *pi, m, true, true);          
            improperFlag = true;
          }
        
        if(improperFlag) return Improper;
      }
    }
    // Check for an IfThenElse (w/o exit block) with incoming edges
    else if (m->succNode.size() == 0 && n->succNode.size() == 0) {
      bool improperFlag = false;

      if (m->predNode.size() > 1) {
        for (NodeSetTy::iterator pi = m->predNode.begin(), pe = m->predNode.end(); pi != pe; ++pi)  
          if (*pi != *entryNode && isStillReachableFromEntry(N, entry, m, *pi)) {
            findUnstructuredBR(N, *pi, m, true, true);          
            improperFlag = true;
          }
      }

      if (n->predNode.size() > 1) {
        for (NodeSetTy::iterator pi = n->predNode.begin(), pe = n->predNode.end(); pi != pe; ++pi)  
          if (*pi != *entryNode && isStillReachableFromEntry(N, entry, n, *pi)) {
            findUnstructuredBR(N, *pi, n, true, true);          
            improperFlag = true;
          }
      }
 
      if(improperFlag) return Improper;
    }
    // n is the Then part (w/o exiting edge) with incoming edges
    else if (n->succNode.size() == 0 && n->predNode.size() > 1) {
      visitPath.clear();

      if (!path(m, *entryNode, N, NULL)) {
        if (n->predNode.count(m) > 0)
          return Nil;

        bool improperFlag = false;

        for (NodeSetTy::iterator pi = n->predNode.begin(), pe = n->predNode.end(); pi != pe; ++pi)
          if (*pi != *entryNode && isStillReachableFromEntry(N, entry, n, *pi)) {
            findUnstructuredBR(N, *pi, n, true, true);
            improperFlag = true;
          }
   
        if(improperFlag) return Improper;
      }
    }
    // m is the Then part w/o exiting edge with incoming edges
    else if (m->succNode.size() == 0 && m->predNode.size() > 1) {
      visitPath.clear();

      if (!path(n, *entryNode, N, NULL)) {
        if (m->predNode.count(n) > 0)
          return Nil;

        bool improperFlag = false;

        for (NodeSetTy::iterator pi = m->predNode.begin(), pe = m->predNode.end(); pi != pe; ++pi)
          if (*pi != *entryNode && isStillReachableFromEntry(N, entry, n, *pi)) {
            findUnstructuredBR(N, *pi, m, true, true);
            improperFlag = true;
          }
   
        if(improperFlag) return Improper;
      }
    }
  }
  // Check for Case
  else if ((*entryNode)->succNode.size() > 2) {
    if(isCaseWithDefault(N, *entryNode, exitNode, entry)) {
      nset.insert(*entryNode);
      
      for (NodeSetTy::iterator i = (*entryNode)->succNode.begin(),
                               e = (*entryNode)->succNode.end();
                               i != e; ++i) 
        nset.insert(*i);
  
      return Case;
    }
    else if(isCaseWithoutDefault(N, *entryNode, exitNode, entry)) {
      nset.insert(*entryNode);
      
      for (NodeSetTy::iterator i = (*entryNode)->succNode.begin(),
                               e = (*entryNode)->succNode.end();
                               i != e; ++i) 
        if(*i != *exitNode) nset.insert(*i);
  
      return Case;
    }
    else if (isImproperCaseWithDefault(N, *entryNode, entry)) 
      return Improper;
    else if (isImproperCaseWithoutDefault(N, *entryNode, exitNode, entry))
      return Improper;
  }

  return Nil; 
}

// isCaseWithDefault - Check if node leads a case block
bool StructuralAnalysis::isCaseWithDefault(NodeSetTy &N, NodeTy * entryNode, NodeTy **exitNode, NodeTy *entry) {
  *exitNode = NULL; 

  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) { 
    // Check if every successor node has only one successor   
    if ((*i)->succNode.size() > 1) return false;

    if (edge2ClassMap[make_pair(entryNode, *i)] == BACK) return false;
 
    // If successor has only one predessor, it has to be the entry node    
    if ((*i)->predNode.size() == 1) { 
      if (entryNode != *((*i)->predNode.begin())) 
        return false;
    }
    // If successor has two predessors, one has to be the entry node
    // and the other has to be another successor node
    else if ((*i)->predNode.size() == 2) {
      NodeSetTy::iterator pi = (*i)->predNode.begin();
      NodeTy *predNode1 = *pi;
      ++pi;
      NodeTy *predNode2 = *pi;

      if (predNode1 != entryNode || entryNode->succNode.count(predNode2) == 0)
        if (entryNode->succNode.count(predNode1) == 0 || predNode2 != entryNode)
          return false;
    }
    // The predecessor node number has to be less than 3
    else 
      return false;   

    NodeTy *succNode = *((*i)->succNode.begin());

    if (succNode == NULL) continue;
    
//    if (edge2ClassMap[make_pair(*i, succNode)] == BACK) return false; 

    if (succNode == entryNode) return false;

    // Check if the successor of the successor node is not another successor node
    if (entryNode->succNode.count(succNode) == 0) {
      // Check if the successor of the successor node is the only exit node
      if (!*exitNode) *exitNode = succNode;
      else if (*exitNode != succNode) return false; 
    }
    // There is no loop between successors
    else if (succNode->succNode.count(*i) > 0) return false;

  }

  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) { 
    if ((*i)->succNode.size() == 0) {
      visitPath.clear();
 
      if (path(*exitNode, entryNode, N, NULL))
        return false;
    }
  }

  return true; 
}

// isImproperCaseWithDefault - Check if node leads a case block
bool StructuralAnalysis::isImproperCaseWithDefault(NodeSetTy &N, NodeTy *entryNode, NodeTy *entry) {
  NodeTy *exitNode = NULL; 
  EdgeSetTy improperEdgeSet;  

  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) { 
    // Check if every successor node has only one successor   
    if ((*i)->succNode.size() > 1) return false;

    if (edge2ClassMap[make_pair(entryNode, *i)] == BACK) return false;

    NodeTy *succNode = *((*i)->succNode.begin());

    if (succNode) { 
      if (succNode == entryNode) return false;
  
   
  //    if (edge2ClassMap[make_pair(*i, succNode)] == BACK) return false;
  
      // Check if the successor of the successor node is not another successor node
      if (entryNode->succNode.count(succNode) == 0) {
        // Check if the successor of the successor node is the only exit node
        if (!exitNode) exitNode = succNode;
        else if (exitNode != succNode) return false; 
      }
      // There is no loop between successors
      else if (succNode->succNode.count(*i) > 0) 
  //      if (improperEdgeSet.count(make_pair(succNode, *i)) == 0)
  //        improperEdgeSet.insert(make_pair(*i, succNode));
        return false;
    }

    // If successor has only one predessor, it has to be the entry node    
    if ((*i)->predNode.size() == 1) { 
      if (entryNode != *((*i)->predNode.begin())) 
        return false;
    }
    // If successor has two predessors, one has to be the entry node
    // and the other has to be another successor node
    else if ((*i)->predNode.size() == 2) {
      NodeSetTy::iterator pi = (*i)->predNode.begin();
      NodeTy *predNode1 = *pi;
      ++pi;
      NodeTy *predNode2 = *pi;

      if (predNode1 != entryNode || entryNode->succNode.count(predNode2) == 0)
        if (entryNode->succNode.count(predNode1) == 0 || predNode2 != entryNode)
          return false;
    }
    // The predecessor node number has to be less than 3
    else { 
      int insideIncomingNum = 0;

      for (NodeSetTy::iterator pi = (*i)->predNode.begin(),
                               pe = (*i)->predNode.end();
                               pi != pe; ++pi) {

        if (edge2ClassMap[make_pair(*pi, *i)] != BACK && *pi != exitNode && *pi != entryNode) { 
          if (entryNode->succNode.count(*pi) == 0) 
            improperEdgeSet.insert(make_pair(*pi, *i));
          else {
            insideIncomingNum++;
  
            if (insideIncomingNum > 1)
              improperEdgeSet.insert(make_pair(*pi, *i));
          }        
        } else 
          return false;
      }
    }
  }

  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) { 
    if ((*i)->succNode.size() == 0) {
      visitPath.clear();
 
      if (path(exitNode, entryNode, N, NULL))
        return false;
    }
  }

  bool improperFlag = false;

  for (EdgeSetTy::iterator i = improperEdgeSet.begin(), e = improperEdgeSet.end(); i != e; ++i) 
    if (isStillReachableFromEntry(N, entry, i->second, i->first)) {
      findUnstructuredBR(N, i->first, i->second, true, true);
      improperFlag = true;
    }

  return improperFlag; 
}

// isCaseWithoutDefault - Check if node leads a case block
bool StructuralAnalysis::isCaseWithoutDefault(NodeSetTy &N, NodeTy * entryNode, NodeTy **exitNode, NodeTy *entry) {
  // Find the exit node first
  *exitNode = NULL; 

  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) {
    NodeTy *node1 = *i;
    bool foundExit = true;
 
    // all of successors of exit node are not within the switch block
    for (NodeSetTy::iterator si = node1->succNode.begin(),
                             se = node1->succNode.end();
                             si != se; ++si) {
      NodeTy *succNode = *si;

      if (succNode) {
        if (entryNode->succNode.count(succNode) > 0) {
          foundExit = false;
  
          break;
        } else if (succNode == entryNode) 
            return false;
      }
    }

    if (!foundExit) continue;

    foundExit = false;

    // at least one of predcessors of exit node comes from switch block
    for (NodeSetTy::iterator pi = node1->predNode.begin(),
                             pe = node1->predNode.end();
                             pi != pe; ++pi) {
      NodeTy *predNode = *pi;

      if (predNode != entryNode  && entryNode->succNode.count(predNode) > 0) {
        foundExit = true;

//        if (edge2ClassMap[make_pair(predNode, node1)] == BACK) return false;
      }
    }

    if (foundExit) {
      *exitNode = node1;

      break;
    } 
  }

  if (!(*exitNode)) return false;
 
  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) {
    if (*i == *exitNode) continue; 
 
    // Check if every successor node has only one successor   
    if ((*i)->succNode.size() > 1) return false;

    NodeTy *succNode = *((*i)->succNode.begin());

    if (succNode) {
      if (succNode == NULL) continue;
      
      if (edge2ClassMap[make_pair(entryNode, *i)] == BACK) return false;
  
      // The successor of the successor node should be the the another successor node of node
      if (entryNode->succNode.count(succNode) == 0) return false;
      // There is no loop between successors
      else if (succNode != *exitNode && succNode->succNode.count(*i) > 0) return false;
    }

    // If successor has only one predessor, it has to be the entry node    
    if ((*i)->predNode.size() == 1) { 
      if (entryNode != *((*i)->predNode.begin())) 
        return false;
    }
    // If successor has two predessors, one has to be the entry node
    // and the other has to be another successor node
    else if ((*i)->predNode.size() == 2) {
      NodeSetTy::iterator pi = (*i)->predNode.begin();
      NodeTy *predNode1 = *pi;
      ++pi;
      NodeTy *predNode2 = *pi;

      if (predNode1 != entryNode || entryNode->succNode.count(predNode2) == 0)
        if (entryNode->succNode.count(predNode1) == 0 || predNode2 != entryNode)
          return false;
    }
    // The predecessor node number has to be less than 3
    else 
      return false;   
  }

  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) { 
    if ((*i)->succNode.size() == 0) {
      visitPath.clear();
 
      if (path(*exitNode, entryNode, N, NULL))
        return false;
    }
  }

  return true; 
}

// isImproperCaseoutWithDefault - Check if node leads a case block with incoming edges
bool StructuralAnalysis::isImproperCaseWithoutDefault(NodeSetTy &N, NodeTy *entryNode, NodeTy **exitNode, NodeTy *entry) {
  EdgeSetTy improperEdgeSet;

  // Find the exit node first
  *exitNode = NULL; 

  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) {
    NodeTy *node1 = *i;
    bool foundExit = true;

    // all of successors of exit node are not within the switch block
    for (NodeSetTy::iterator si = node1->succNode.begin(),
                             se = node1->succNode.end();
                             si != se; ++si) {
      NodeTy *succNode = *si;

      if (succNode ) {
        if (entryNode->succNode.count(succNode) > 0) {
          foundExit = false;
  
          break;
        } else if (succNode == entryNode)
          return false;
      }
    }

    if (!foundExit) continue;

    foundExit = false;

    // at least one of predcessors of exit node comes from switch block
    for (NodeSetTy::iterator pi = node1->predNode.begin(),
                             pe = node1->predNode.end();
                             pi != pe; ++pi) {
      NodeTy *predNode = *pi;

      if (predNode != entryNode  && entryNode->succNode.count(predNode) > 0) {
        foundExit = true;

//        if (edge2ClassMap[make_pair(predNode, node1)] == BACK) return false;
      }
    }

    if (foundExit) {
      *exitNode = node1;

      break;
    } 
  }

  if (!(*exitNode)) return false;
 
  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) {
    if (*i == *exitNode) continue; 
 
    // Check if every successor node has only one successor   
    if ((*i)->succNode.size() > 1) return false;

    if (edge2ClassMap[make_pair(entryNode, *i)] == BACK) return false;

    NodeTy *succNode = *((*i)->succNode.begin());

    if (succNode) {
      if (succNode == NULL) continue;
  
      // The successor of the successor node should be the the another successor node of node
      if (entryNode->succNode.count(succNode) == 0) return false;
      // There is no loop between successors
      else if (succNode != *exitNode && succNode->succNode.count(*i) > 0) 
  //      if (improperEdgeSet.count(make_pair(succNode, *i)) == 0)
  //        improperEdgeSet.insert(make_pair(*i, succNode));
        return false;
    }

    // If successor has only one predessor, it has to be the entry node    
    if ((*i)->predNode.size() == 1) { 
      if (entryNode != *((*i)->predNode.begin())) 
        return false;
    }
    // If successor has two predessors, one has to be the entry node
    // and the other has to be another successor node
    else if ((*i)->predNode.size() == 2) {
      NodeSetTy::iterator pi = (*i)->predNode.begin();
      NodeTy *predNode1 = *pi;
      ++pi;
      NodeTy *predNode2 = *pi;

      if (predNode1 != entryNode || entryNode->succNode.count(predNode2) == 0)
        if (entryNode->succNode.count(predNode1) == 0|| predNode2 != entryNode)
          return false;

      if (predNode1 == *exitNode) 
//        improperEdgeSet.insert(make_pair(predNode1, *i));
        return false;

      if (predNode2 == *exitNode)
//        improperEdgeSet.insert(make_pair(predNode2, *i));
        return false;
    }
    // The predecessor node number has to be less than 3
    else {
      int insideIncomingNum = 0;

      for (NodeSetTy::iterator pi = (*i)->predNode.begin(),
                               pe = (*i)->predNode.end();
                               pi != pe; ++pi) {

        if (edge2ClassMap[make_pair(*pi, *i)] != BACK && (*i) != *exitNode && (*pi) != entryNode && (*pi) != *exitNode) {
          if (entryNode->succNode.count(*pi) == 0)
            improperEdgeSet.insert(make_pair(*pi, *i));
//          else if (*pi == *exitNode)
//            improperEdgeSet.insert(make_pair(*pi, *i));
          else {
            insideIncomingNum++;
  
            if (insideIncomingNum > 1)
              improperEdgeSet.insert(make_pair(*pi, *i));
          }
        } else
         return false;
      }
    }
  }

  for (NodeSetTy::iterator i = entryNode->succNode.begin(),
                           e = entryNode->succNode.end();
                           i != e; ++i) { 
    if ((*i)->succNode.size() == 0) {
      visitPath.clear();
 
      if (path(*exitNode, entryNode, N, NULL))
        return false;
    }
  }

  bool improperFlag = false;

  for (EdgeSetTy::iterator i = improperEdgeSet.begin(), e = improperEdgeSet.end(); i != e; ++i) 
    if (isStillReachableFromEntry(N, entry, i->second, i->first)) {
      findUnstructuredBR(N, i->first, i->second, true, true);
      improperFlag = true;
    }

  return improperFlag; 
}

// cyclicRegionType - Follow Fig 7.42 of Muchnick book
RegionTy StructuralAnalysis::cyclicRegionType(NodeSetTy &N, NodeSetTy &nset, NodeTy *loopHeaderNode, NodeTy *backEdgeNode, NodeTy **exitNode, NodeTy *entry) {
  // Check for a SelfLoop
  if (nset.size() == 1) { 
    if (loopHeaderNode == backEdgeNode) {
      *exitNode = *(backEdgeNode->succNode.begin());

      return SelfLoop;
    } else 
      return Nil;
  }

  if (isImproper(N, nset, loopHeaderNode, backEdgeNode, exitNode, entry)) 
    // It is an Improper region
    return Improper;

  if (nset.size() == 2) {
    if (backEdgeNode->succNode.size() == 1) {
      for (NodeSetTy::iterator i = loopHeaderNode->predNode.begin(), e = loopHeaderNode->predNode.end(); i != e; ++i) {
        NodeTy *pred = *i;
     
        if (pred != backEdgeNode) {
          if (edge2ClassMap[make_pair(pred, loopHeaderNode)] == BACK)
            return Nil;
        }
      }
  
      for (NodeSetTy::iterator i = loopHeaderNode->succNode.begin(), e = loopHeaderNode->succNode.end(); i != e; ++i) {
        NodeTy *succ = *i;
     
        if (succ != backEdgeNode) {
          if (edge2ClassMap[make_pair(loopHeaderNode, succ)] == BACK)
            return Nil;
        }
      }
  
      if (backEdgeNode->predNode.size() != 1 || backEdgeNode->succNode.size() != 1 )
        return Nil;
  
      return NaturalLoop;
    } else if (backEdgeNode->succNode.size() > 1) {
      for (NodeSetTy::iterator i = loopHeaderNode->predNode.begin(), e = loopHeaderNode->predNode.end(); i != e; ++i) {
        NodeTy *pred = *i;
     
        if (pred != backEdgeNode) {
          if (edge2ClassMap[make_pair(pred, loopHeaderNode)] == BACK)
            return Nil;
        }
      }
  
      for (NodeSetTy::iterator i = loopHeaderNode->succNode.begin(), e = loopHeaderNode->succNode.end(); i != e; ++i) {
        NodeTy *succ = *i;
     
        if (succ != backEdgeNode) {
          if (edge2ClassMap[make_pair(loopHeaderNode, succ)] == BACK)
            return Nil;
        }
      }
  
      if (backEdgeNode->predNode.size() != 1)
        return Nil;
  
      return NaturalLoop;
    }
  }
 
  return Nil;
}

// reduce - Follow Fig 7.43 of Muchnick book
NodeTy * StructuralAnalysis::reduce(NodeSetTy &N, RegionTy rType, NodeSetTy &nodeSet, NodeTy *entryNode, NodeTy *exitNode) {
  NodeTy *node = new NodeTy;
//  bool addSelfEdge = false;

//  if (rType == Block && entryNode->predNode.count(exitNode) > 0)
//    addSelfEdge = true;

  // Replace node set by an abstract region node and 
  // set data structures

  replace(N, node, nodeSet/*, addSelfEdge*/);
  node->isCombined = true;
  node->entryNode = entryNode;
  node->entryBB = findEntryBB(entryNode);
  node->isLoopHeader = false;
  node->loopExitNode = NULL;
  node->parentNode = NULL;

  if (exitNode) node->exitBB = findEntryBB(exitNode);

  for (NodeSetTy::iterator i = nodeSet.begin(), e = nodeSet.end(); i != e; ++i)
    findBB(*i, &(node->containedBB));

  node->nodeType = rType;
  structType[node] = rType;
  structures.insert(node);

  for (NodeSetTy::iterator i = nodeSet.begin(), e = nodeSet.end(); i != e; ++i) 
    structOf[*i] = node;

  NodeSetTy *set = new NodeSetTy;
  *set = nodeSet;
  structNodes[node] = set;

  return node;
}

// replace - Follow Fig 7.44 of Muchnick book
void StructuralAnalysis::replace(NodeSetTy &N, NodeTy *node, NodeSetTy &nodeSet/*, bool addSelfEdge*/) {
  // Link region node into abstract flowgraph, adjust the postorder traversal
  // and predecessor and successor functions, and augment the control tree
  compact(N, node, nodeSet/*, addSelfEdge*/);

  for (NodeSetTy::iterator i = nodeSet.begin(), e = nodeSet.end(); i != e; ++i) { 
    node->childNode.insert(*i);
    (*i)->parentNode = node;
  }
}

// isImproper - Follow Fig 7.45 of Muchnick book
bool StructuralAnalysis::isImproper(NodeSetTy &N, NodeSetTy &nset, NodeTy *loopHeaderNode, NodeTy *backEdgeNode, NodeTy **exitNode, NodeTy *entry) {
  bool improperFlag = false;  

  // Check loopHeaderNode first
  for (NodeSetTy::iterator i = loopHeaderNode->predNode.begin(),
                           e = loopHeaderNode->predNode.end();
                           i != e; ++i) {
    NodeTy *predNode = *i;

    if (edge2ClassMap[make_pair(predNode, loopHeaderNode)] == BACK) {
      if (nset.count(predNode) == 0 && isStillReachableFromEntry(N, entry, loopHeaderNode, predNode)) {
        findUnstructuredBR(N, predNode, loopHeaderNode, true, true);
        improperFlag = true;
      } else if (nset.count(predNode) > 0 && predNode != backEdgeNode) { 
        findUnstructuredBR(N, predNode, loopHeaderNode, false, false);
        improperFlag = true;
      }
    }
  }

  // Check the incoming edges
  for (NodeSetTy::iterator i = nset.begin(), e = nset.end(); i != e; ++i) {
    NodeTy *node = *i;

    if (node != loopHeaderNode) 
      for (NodeSetTy::iterator ii = node->predNode.begin(),
                               ee = node->predNode.end();
                               ii != ee; ++ii) {
        if (nset.count(*ii) == 0 /*&& isStillReachableFromEntry(N, entry, node, *ii)*/) {
          improperFlag = true;

//          if (edge2ClassMap[make_pair(*ii, node)] != BACK) 
            findUnstructuredBR(N, *ii, node, false, true);
          deleteUnreachableNodes(N, entry);
        }
      }
  }

  EdgeSetTy exitEdgeSet;
  NodeTy *exitNodeOfHeader = NULL;
  NodeTy *exitNodeOfBackEdge = NULL;
  NodeTy *mainExitNode = NULL;

  for (NodeSetTy::iterator i = nset.begin(), e = nset.end(); i != e; ++i) {
    NodeTy *node = *i;

    for (NodeSetTy::iterator ii = node->succNode.begin(),
                             ee = node->succNode.end();
                             ii != ee; ++ii) {
      if (nset.count(*ii) == 0) {
        exitEdgeSet.insert(make_pair(node, *ii)); 

        if (node == loopHeaderNode) {
          if (exitNodeOfHeader == NULL)
            exitNodeOfHeader = *ii;
        } else if (node == backEdgeNode) {
          if (exitNodeOfBackEdge == NULL)
            exitNodeOfBackEdge = *ii;
        }
      }
    } 
  }

  if (exitNodeOfHeader)
    mainExitNode = exitNodeOfHeader; 
  else if (exitNodeOfBackEdge)
    mainExitNode = exitNodeOfBackEdge;

  for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
    EdgeTy exitEdge = *i;

    if (exitEdge.second != mainExitNode 
      /*&& isStillReachableFromEntry(N, entry, exitEdge.second, exitEdge.first)
      && edge2ClassMap[make_pair(exitEdge.first, exitEdge.second)] != BACK*/) {
      findUnstructuredBR(N, exitEdge.first, exitEdge.second, false, true);
      deleteUnreachableNodes(N, entry);
      improperFlag = true;
    } 
  }

  if (exitNodeOfHeader) {
    for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
      if (i->first != loopHeaderNode && (*i).second == mainExitNode) {
        findUnstructuredBR(N, i->first, i->second, false, false);
        improperFlag = true;
      }
    }  
  } else if (exitNodeOfBackEdge) {
    for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
      if (i->first != backEdgeNode && i->second == mainExitNode) {
        findUnstructuredBR(N, i->first, i->second, false, false);
        improperFlag = true;
      }
    }  
  }
 
  // Check the outgoing edges
/*  EdgeSetTy exitEdgeSet;
  NodeTy *exitNodeOfHeader = NULL;
  NodeTy *exitNodeOfBackEdge = NULL;
  NodeTy *mainExitNode = NULL;
  bool useHeader = true;
  bool useBackEdge = true;

  for (NodeSetTy::iterator i = nset.begin(), e = nset.end(); i != e; ++i) {
    NodeTy *node = *i;

    for (NodeSetTy::iterator ii = node->succNode.begin(),
                             ee = node->succNode.end();
                             ii != ee; ++ii) {
      if (nset.count(*ii) == 0) {
        exitEdgeSet.insert(make_pair(node, *ii)); 

        if (node == loopHeaderNode) {
          if (exitNodeOfHeader == NULL)
            exitNodeOfHeader = *ii;
          else
            useHeader = false;
        } else if (node == backEdgeNode) {
          if (exitNodeOfBackEdge == NULL)
            exitNodeOfBackEdge = *ii;
          else
            useBackEdge = false;
        }
      }
    } 
  }*/

//  if (exitEdgeSet.size() > 1) {
//    if (exitNodeOfHeader && exitNodeOfHeader->predNode.size() == 1 && useHeader)
//      mainExitNode = exitNodeOfHeader; 
//    else if (exitNodeOfBackEdge && exitNodeOfBackEdge->predNode.size() == 1 && useBackEdge)
//      mainExitNode = exitNodeOfBackEdge;
//    else {
//      for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
//        if (i->second->predNode.size() == 1) {
//          mainExitNode = i->second;
//
//          break;
//        } 
//      }
//    }
//
//    if (!mainExitNode) {
//      for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
//          if (!mainExitNode)
//            mainExitNode = i->second;
//          else if (mainExitNode != i->second)
//            return improperFlag;
//      }
//    }
//
//    EdgeSetTy mainExitEdgeSet;
//    bool exitFromLoopHeader = false;
//    bool exitFromBackEdge = false;
//
//    for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
//      EdgeTy exitEdge = *i;
//
//      if (exitEdge.second != mainExitNode 
//        && isStillReachableFromEntry(N, entry, exitEdge.second, exitEdge.first)
//        /*&& edge2ClassMap[make_pair(exitEdge.first, exitEdge.second)] != BACK*/) {
//        findUnstructuredBR(N, exitEdge.first, exitEdge.second, false, true);
//        improperFlag = true;
//      } else if (exitEdge.second == mainExitNode) {
//        if (exitEdge.first == loopHeaderNode)
//          exitFromLoopHeader = true;
//        else if (exitEdge.first == backEdgeNode)
//          exitFromBackEdge = true;
//      }
//    }
//
//    int num = 0;
//
//    if (exitFromLoopHeader) {
//      for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
//        if (i->first != loopHeaderNode && (*i).second == mainExitNode)
//          findUnstructuredBR(N, i->first, i->second, false, false);
//      }  
//    } else if (exitFromBackEdge) {
//      for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
//        if (i->first != backEdgeNode && i->second == mainExitNode)
//          findUnstructuredBR(N, i->first, i->second, false, false);
//      }  
//    } else {
//      for (EdgeSetTy::iterator i = exitEdgeSet.begin(), e = exitEdgeSet.end(); i != e; ++i) {
//        if (i->second == mainExitNode)
//          if (++num > 1)
//            findUnstructuredBR(N, i->first, i->second, false, false);
//      }  
//    }
//  } else if (exitEdgeSet.size() == 1)
//    mainExitNode = (exitEdgeSet.begin())->second; 

  *exitNode = mainExitNode;
  loopHeaderNode->isLoopHeader = true;
  loopHeaderNode->loopExitNode = mainExitNode;

  return improperFlag; 
}

// pathBack - Check if there is a node k such that there is a path from
// m to k that does not pass through n and an edge k->n that is a back edge
NodeTy *StructuralAnalysis::pathBack(NodeTy *n, NodeSetTy &N, NodeSetTy &reachUnder) {
  NodeTy *backEdgeNode = NULL;

  reachUnder.clear();

  // Find backedge first
  for (NodeSetTy::iterator i = n->predNode.begin(),
                           e = n->predNode.end(); 
                           i != e; ++i) { 
    NodeTy *predNode = *i;

    if (edge2ClassMap[make_pair(predNode, n)] == BACK) {
      if (reachUnder.count(predNode) == 0) {
        backEdgeNode = predNode;

        //Locate a cyclic region, if present
        reachUnder.clear();
        reachUnder.insert(n);
        reachUnder.insert(backEdgeNode);
      
        for (NodeSetTy::iterator ii = N.begin(), ee = N.end(); ii != ee; ++ii) {
          NodeTy *m = *ii;

          // Check if there is a path from m to loop exit node
          visitPath.clear();
          if (path(m, backEdgeNode, N, n)) {
            visitPath.clear();
 
            if (path(n, m, N, backEdgeNode)) 
              reachUnder.insert(m);
          } 
        }
      }
    }
  }

  return backEdgeNode;
}

// path(n, m, I) - Return true if there is a path from from n to m 
// such that all the nodes in it are in I and false otherwise
bool StructuralAnalysis::path(NodeTy *n, NodeTy *m, NodeSetTy &I, NodeTy *esc) {
  visitPath[n] = true;

  if (n == esc || m == esc) return false;

  if (n == m) return true;

  for (NodeSetTy::iterator i = n->succNode.begin(),
                           e = n->succNode.end();
                           i != e; ++i) 
    if (I.count(*i) > 0 && *i != esc && !visitPath[*i]) {
      if (*i == m) 
        return true;
      else 
        if (path(*i, m, I, esc)) return true;
    }

  return false;
}

// compact - Compact nodes in nset into n;
void StructuralAnalysis::compact(NodeSetTy &N, NodeTy *n, NodeSetTy &nset/*, bool addSelfEdge*/) {
  // Adds node n to N
  N.insert(n);

//  // Insert n into post() in the highest-numbered position of a node in nset  
//  int max = 1;
//
//  for (int ii = 1; ii <= postMax; ii++) 
//    if (nset.count(post[ii]) > 0) max = ii;
// 
//  post[max] = n;

  // Remove the nodes in nset from both N and post()
  for (NodeSetTy::iterator i = nset.begin(), e = nset.end(); i != e; ++i) {
    for (NodeSetTy::iterator si = (*i)->succNode.begin(), se = (*i)->succNode.end(); si != se; ++si) 
      if(nset.count(*si) == 0) {
        n->succNode.insert(*si);
        (*si)->predNode.insert(n);
        (*si)->predNode.erase(*i);
      }
   
    for (NodeSetTy::iterator pi = (*i)->predNode.begin(), pe = (*i)->predNode.end(); pi != pe; ++pi) 
      if(nset.count(*pi) == 0) {
        n->predNode.insert(*pi);
        (*pi)->succNode.insert(n);
        (*pi)->succNode.erase(*i);
      }

    N.erase(*i);
  }

//  if (addSelfEdge) {
//    n->predNode.insert(n);
//    n->succNode.insert(n);
//  }
//  for (int i = 1; i <= postMax; i++ ) 
//    if (nset.count(post[i]) > 0)
//      post.erase(i);
//
//  // Compact the remaining nodes at the beginning of post() 
//  for (int i = 1; i <= postMax; i++ ) 
//    // Set postCtr to the index of n in the resulting postorder
//    if (post[i] == n) {
//      postCtr = i;
//
//      continue;
//    }
//    else if (post[i] != NULL) 
//      continue;
//    else {
//      int ii = i + 1;
//
//      while (ii <= postMax) {
//        if (post[ii] != NULL) break;
//
//        ii++;
//      }
//
//      if (ii <= postMax) {
//        post[i] = post[ii];
// 
//        // Set postCtr to the index of n in the resulting postorder
//        if (post[i] == n) postCtr = i;
//  
//        post.erase(ii);
//      }
//    }
//    
//   // Set postMax accordingly
//   int i = postMax;
//
//   while (post[i] == NULL) 
//     i--;
//
//   postMax = i;
}

// MECEntries(n, nset, N) - Return the set of entry nodes of the smallest
// multiple-entry cycle of which n is one of the entries
NodeSetTy StructuralAnalysis::MECEntries(NodeSetTy &nset) {
  NodeSetTy I;
 
  for (NodeSetTy::iterator i = nset.begin(), e = nset.end(); i != e; ++i)
    for (NodeSetTy::iterator ii = (*i)->predNode.begin(),
                             ee = (*i)->predNode.end();
                             ii != ee; ++ii) 
      if (nset.count(*ii) == 0) {
        I.insert(*i);
        break;
      } 

  return I;
}

// NCDomin(I, N) - Return the nearest common dominator of the nodes in I
NodeTy * StructuralAnalysis::NCDomin(NodeSetTy &I) {
  NodeTy *dominNode = NULL;

  for (NodeSetTy::iterator i = I.begin(), e = I.end(); i != e; ++i) 
    dominNode = findNearestCommonDominator(dominNode, *i);     

  return dominNode;
}

// mapNode2BB - Return the corresponding BasicBlock of the node
BasicBlock * StructuralAnalysis::mapNode2BB(NodeTy *node) {
  NodeTy *tmpNode = node;
  BasicBlock *bb;

  while (tmpNode->isCombined) 
    tmpNode = tmpNode->entryNode;
  
  bb = tmpNode->BB;
  
  return bb; 
}

// mapBB2Node - Return the corresponding sturcture node of the basic block
NodeTy * StructuralAnalysis::mapBB2Node(BasicBlock *bb) {
  NodeTy *node, *tmpNode;

  node = BB2NodeMap[bb];

  while ((tmpNode = structOf[node]) != NULL) 
    node = tmpNode;
  
  return node; 
}

// dumpCTNode - dump one CT node
void StructuralAnalysis::dumpCTNode(NodeTy *node) {
  if(!node->isCombined) return;

  errs() << "\t"; 

  switch (structType[node]) {
  case Block:
    errs() << "Block      ";
    break;
  case IfThen:
    errs() << "IfThen     ";
    break;
  case IfThenElse:
    errs() << "IfThenElse ";
    break;
  case Case:
    errs() << "Case       ";
    break;
  case SelfLoop:
    errs() << "SelfLoop   ";
    break;
  case NaturalLoop:
    errs() << "NaturalLoop";
    break;
  default:
    break;
  }
  
  errs() << "\t";

  dumpNode(node);

  errs() << '\n';

  for (NodeSetTy::iterator i = node->childNode.begin(),
                           e = node->childNode.end();
                           i != e; ++i)
    dumpCTNode(*i);
}

// dumpNode - dump one node
void StructuralAnalysis::dumpNode(NodeTy *node) {
  BBSetTy *BBVec = new BBSetTy;

  findBB(node, BBVec);

  for (BBSetTy::iterator i = BBVec->begin(), e = BBVec->end(); i != e; ++i)
    errs() << (*i)->getName() << "\t";
}

// domComp(N, r) - Compute all the dominators of each node in a flowgraph
void StructuralAnalysis::domComp(NodeSetTy &N, NodeTy *r) {
  NodeSetTy D, T;
  bool change = true;

  for (NodeSetTy::iterator i = N.begin(), e = N.end(); i != e; ++i) { 
    NodeTy *n = *i;

    if (!domin[n]) domin[n] = new NodeSetTy;

    if (n != r) *(domin[n]) = N;
    else domin[n]->insert(r);
  }

  do {
    change = false;

    for (NodeSetTy::iterator i = N.begin(), e = N.end(); i != e; ++i) { 
      NodeTy *n = *i;

      if (n != r) {
        T = N;

        for (NodeSetTy::iterator pi = n->predNode.begin(),
                                 pe = n->predNode.end();
                                 pi != pe; ++pi) {
          NodeSetTy tmpSet;
          NodeTy *pred = *pi;

          for (NodeSetTy::iterator ti = T.begin(),te = T.end(); ti != te; ++ti)
            if (domin[pred]->count(*ti) > 0) tmpSet.insert(*ti);

          T = tmpSet; 
        }

        D = T;
        D.insert(n);

        if (D != *(domin[n])) {
          change = true;
          *(domin[n]) = D;
        }
      }
    }
  } while (change);
}

// idomComp(N, r) - Compute all the immediate dominators of each node in a flowgraph
void StructuralAnalysis::idomComp(NodeSetTy &N, NodeTy *r) {
  Node2NodeSetMapTy tmp;

  for (NodeSetTy::iterator i = N.begin(), e = N.end(); i != e; ++i) {
    tmp[*i] = new NodeSetTy;
    *(tmp[*i]) = *(domin[*i]);
    tmp[*i]->erase(*i);
  }

  for (NodeSetTy::iterator i = N.begin(), e = N.end(); i != e; ++i) { 
    NodeTy *n = *i;

    if (n != r) {
      for (NodeSetTy::iterator ii = tmp[n]->begin(), ee = tmp[n]->end(); ii != ee; ++ii) {
        NodeTy *s = *ii;

        for (NodeSetTy::iterator iii = tmp[n]->begin(), eee = tmp[n]->end(); iii != eee; ++iii) {
          NodeTy *t = *iii;
         
          if (t != s) {
            if (tmp[s]->count(t)) tmp[n]->erase(t);
          }
        }
      }
    }
  }

  for (NodeSetTy::iterator i = N.begin(), e = N.end(); i != e; ++i) { 
    NodeTy *n = *i;

    if (n != r) 
      iDom[n] = *(tmp[n]->begin());
    else
      iDom[n] = NULL;
  }
}

// dominates - Whether node1 dominates node2
bool StructuralAnalysis::dominates(NodeTy *node1, NodeTy *node2) {
  return (domin[node2]->count(node1) > 0);
}

// findNearestCommonDominator - Find the nearest common dominator of node1 and node2
NodeTy * StructuralAnalysis::findNearestCommonDominator(NodeTy *node1, NodeTy *node2) {
  if (node1 == NULL) return node2;

  if (node2 == NULL) return node1;

  if (dominates(node1, node2)) return node1;

  if (dominates(node2, node1)) return node2;

  NodeTy *tmpNode = iDom[node1];

  do {
    if (dominates(tmpNode, node2)) 
      return tmpNode;
    else 
      tmpNode = iDom[tmpNode];
  } while(tmpNode);

  return NULL;
}

// findUnstructuredBR - Record the branch and remove it from CFG 
void StructuralAnalysis::findUnstructuredBR(NodeSetTy &N, NodeTy *srcNode, NodeTy *dstNode, bool needForwardCopy, bool isGoto) {
  BBSetTy *srcNodeVec = new BBSetTy;
  BBSetTy *dstNodeVec = new BBSetTy;

  findBB(srcNode, srcNodeVec);
  findBB(dstNode, dstNodeVec);

  for (BBSetTy::iterator SRCI = srcNodeVec->begin(), SRCE = srcNodeVec->end(); SRCI != SRCE; ++SRCI) {
    BasicBlock *srcBB= *SRCI;

    for (succ_iterator SI = succ_begin(srcBB), SE = succ_end(srcBB); SI != SE; ++SI) {
      BasicBlock *succ = *SI;

      for (BBSetTy::iterator DSTI = dstNodeVec->begin(), DSTE = dstNodeVec->end(); DSTI != DSTE; ++DSTI) {
        BasicBlock *dstBB = *DSTI;

        if (*DSTI == succ) {
          if (isGoto)
            unstructuredBRVec.push_back(make_pair(srcBB, dstBB));

          if (needForwardCopy)
            dstNode->incomingForwardBR.push_back(make_pair(srcBB, dstBB));
        }
      }
    }
  }   

  srcNode->succNode.erase(dstNode);
  dstNode->predNode.erase(srcNode);

  if (edge2ClassMap[make_pair(srcNode, dstNode)] == BACK) {
    dstNode->isLoopHeader = false;
    dstNode->loopExitNode = NULL;
  }
}

// findBB - put all Basic Blocks in node into nodeVec
void StructuralAnalysis::findBB(NodeTy *node, BBSetTy *nodeVec) {
  if (!node->isCombined) 
    nodeVec->insert(node->BB);
  else {
    NodeSetTy *nodeSet = structNodes[node];

    for (NodeSetTy::iterator i = nodeSet->begin(), e = nodeSet->end(); i != e; ++i) 
      findBB(*i, nodeVec);    
  }
}

// dumpUnstructuredBR - Dump all found unstructured branches
void StructuralAnalysis::dumpUnstructuredBR() {
  errs() << "\nUnstructured Branches:\n";
  
  for (EdgeVecTy::iterator i = unstructuredBRVec.begin(), e = unstructuredBRVec.end(); i != e; ++i) 
    errs() << "\t" << i->first->getName() << "\t" << i->second->getName() << "\n";

  errs() << "\n";
}

//Return true if after erasing edge src->dst, dst is still reachable from entry
bool StructuralAnalysis::isStillReachableFromEntry(NodeSetTy &N, NodeTy *entry, NodeTy *dstNode, NodeTy *srcNode) {
  if (srcNode != entry) {
    visitPath.clear();

    return path(entry, dstNode, N, srcNode);
  } else {
    if (entry->succNode.size() <= 1)
      return false;
    else {
      for (NodeSetTy::iterator i = entry->succNode.begin(),
                               e = entry->succNode.end();
                               i != e; ++i)
        if (path(*i, dstNode, N, entry)) 
          return true; 
    }
  }
   
  return false;
}

//findEntryBB - find the entry Basic Block of the node
BasicBlock *StructuralAnalysis::findEntryBB (NodeTy *node) {
  if (!node->isCombined) 
    return node->BB;
  else 
    return findEntryBB(node->entryNode);
}

// clean - fill in the element of incoming branches and outgoing branches
void StructuralAnalysis::cleanup(NodeTy *node) {
  if (!node->isCombined) 
    return;
  else {
    if ((node->nodeType == NaturalLoop || node->nodeType == SelfLoop) && node->containedBB.size() > 1) {
      for (BBSetTy::iterator i = node->containedBB.begin(), e = node->containedBB.end(); i != e; ++i) {
        BasicBlock *BB = *i;

        if (BB != node->entryBB)
          for (pred_iterator PI = pred_begin(BB), E = pred_end(BB); PI != E; ++PI) {
            BasicBlock *Pred = *PI;
 
             if (node->containedBB.count(Pred) == 0)
               node->incomingBR.push_back(make_pair(Pred, BB));
          }
       
//        if (node->exitBB)
          for (succ_iterator SI = succ_begin(BB), E = succ_end(BB); SI != E; ++SI) {
            BasicBlock *Succ = *SI;

            if (node->containedBB.count(Succ) == 0 && Succ != node->exitBB)
              node->outgoingBR.push_back(make_pair(BB, Succ));
          }
      }
    }

    NodeSetTy *nodeSet = structNodes[node];

    for (NodeSetTy::iterator i = nodeSet->begin(), e = nodeSet->end(); i != e; ++i) 
      cleanup(*i);   
  }
}

// deleteUnreachableNode - delete nodes that is no longer reachable from the entry
void StructuralAnalysis::deleteUnreachableNodes(NodeSetTy &N, NodeTy *entry) {
  for(NodeSetTy::iterator i = N.begin(), e = N.end(); i != e; i++) {
    visitPath.clear();
    NodeTy *node = *i;

    if (!path(entry, node, N, NULL)) {

      for (NodeSetTy::iterator pi = node->predNode.begin(),
                               pe = node->predNode.end();
                               pi != pe; ++pi)
        (*pi)->succNode.erase(node);

      for (NodeSetTy::iterator si = node->succNode.begin(),
                               se = node->succNode.end();
                               si != se; ++si)

        (*si)->predNode.erase(node);

      N.erase(node);
    }
  }
}

bool StructuralAnalysis::runOnFunction(Function &F) {
  // N - This var holds a simple CFG
  //NodeSetTy N;

  errs() << F.getName() << '\n';

  // build a Simple CFG out of the LLVM CFG
  buildSimpleCFG(F, Net);

  NodeTy *entry = BB2NodeMap[&(F.getEntryBlock())];

  bool debug = false;
//  if (F.getName() == "CrossExpand" || F.getName() == "ReadDefinitions" || F.getName() == "LanguageDefine") 
//    debug = true;

//  domComp(N, entry); 
//  idomComp(N, entry);
 
  // Follow the Fig 7.39 of Muchnick book
  structuralAnalysis(Net, entry, debug);

  cleanup(*(Net.begin()));

  dumpCTNode(*(Net.begin()));

  dumpUnstructuredBR();

  return false;
}
#endif

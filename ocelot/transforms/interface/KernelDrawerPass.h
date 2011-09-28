/*! \file KernelDrawer.h
 \author Diogo Sampaio <sampaio@dcc.ufmg.br>
 \brief The header file for the KernelDrawerPass class.
 */
#ifndef DIVERGENCEDRAWER_H_
#define DIVERGENCEDRAWER_H_

#include <ocelot/analysis/interface/DivergenceAnalysis.h>
#include <ocelot/transforms/interface/Pass.h>
#include <string>
using namespace std;
namespace transforms {
/* This class draws many graphs for a kernel. */
class KernelDrawerPass: KernelPass
{
  private:
    string _kernelName;
    string _path;
    analysis::DivergenceAnalysis *_div;
    void _sanityTest() const;
    string _edges(const analysis::DataflowGraph::Block &block,
        const bool isFullGraph = false) const;
    uint _graphs;
    string _getBGColor(const unsigned int id) const;

  public:
    enum GraphsTypes
    {
      noGraphs = 0,
      varsGraph = 1,
      cfgGraph = 2,
      divGraph = 4,
      fullGraph = 8,
      allGraphs = (unsigned char) (-1)
    };
    virtual void initialize(const ir::Module& m);

    virtual void runOnKernel(ir::IRKernel& k);

    virtual void finalize();

    void drawVariablesGraph() const;
    void drawDivergenceGraph() const;
    void drawControlFlowGraph() const;
    void drawFullGraph() const;
    void draw() const;
    KernelDrawerPass(const string &path, const unsigned short &graphs);
};
}
#endif /* DIVERGENCEDRAWER_H_ */

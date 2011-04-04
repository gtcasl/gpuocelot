/*! \file DivergenceDrawer.h
	\author Diogo Sampaio <dnsampaio@gmail.com>
	\brief The header file for the DivergenceDrawer class.
*/
#ifndef DIVERGENCEDRAWER_H_
#define DIVERGENCEDRAWER_H_

#include <ocelot/analysis/interface/DivergenceAnalysis.h>

namespace graph_utils{
/* This class draws many graphs, such as cfg, dfg and data dependency, and how divergency is spread. */
class DivergenceDrawer
{
	private:
		/*!\brief kernel name analyzed */
		string _kernelName;
		/*!\brief ptx path, for writing dot graph */
		string _path;
		/*!\brief The static divergence analysis of the kernel */
		analysis::DivergenceAnalysis *divAnalysis;
		/*!\brief Prints all graphs */
		bool _all;
		/*!\brief Draw divergence variables graph */
		bool _divergence;
		/*!\brief Draw variables graph */
		bool _vars;
		/*!\brief Draw (data+control)flow graph  - (D+C)FG */
		bool _dfg;
		/*!\brief Draw controlflow graph */
		bool _cfg;

		inline void _sanityTest() const;
		inline string _edges ( const analysis::DataflowGraph::Block &block, const bool isFullGraph = false ) const;

	public:
		void drawVariablesGraph() const;
		void drawDivergenceGraph() const;
		void drawControlFlowGraph() const;
		void drawFullGraph() const;
		void draw() const;
		DivergenceDrawer( const string &kernelName, const string &path, analysis::DivergenceAnalysis *divergenceAnalysis,
				const bool &allGraphs, const bool &divergenceGraph = false,
				const bool &varsGraph = false, const bool &dfgGraph = false, const bool &cfgGraph = false);

		DivergenceDrawer( const string &kernelName, const string &path, analysis::DivergenceAnalysis *divergenceAnalysis,
						const bool &allGraphs = true);
};
}
#endif /* DIVERGENCEDRAWER_H_ */

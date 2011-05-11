/*! \file   Analysis.h
	\author Gregory Diamos <gdiamos@gatech.edu>
	\date   Saturday May 7, 2011
	\brief  The header file for the Analysis class.
*/

#ifndef ANALYSIS_H_INCLUDED
#define ANALYSIS_H_INCLUDED

namespace analysis
{

/*! \brief An analysis that can be constructed for aiding IR transforms */
class Analysis
{
public:	
	/*! \brief Analysis type */
	enum Type
	{
		NoAnalysis                = 0x0,
		ControlTreeAnalysis       = 0x1,
		DominatorTreeAnalysis     = 0x2,
		PostDominatorTreeAnalysis = 0x4,
		DataflowGraphAnalysis     = 0x8,
		StaticSingleAssignment    = 0x10,
		DivergenceAnalysis        = 0x20,
		ThreadFrontierAnalysis    = 0x40
	};

public:
	Analysis(Type t = NoAnalysis);

public:
	Type type() const;

private:
	Type _type;

};

}

#endif


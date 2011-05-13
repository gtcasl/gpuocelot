/*! \file   Analysis.cpp
	\author Gregory Diamos <gdiamos@gatech.edu>
	\date   Saturday May 7, 2011
	\brief  The source file for the Analysis class.
*/

#ifndef ANALYSIS_CPP_INCLUDED
#define ANALYSIS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/Analysis.h>

namespace analysis
{

Analysis::Analysis(Type t, const std::string& n,
	int r, transforms::PassManager* m)
: type(t), name(n), _required(r), _manager(m)
{

}


KernelAnalysis::KernelAnalysis(Type t, const std::string& n,
	int r, transforms::PassManager* m)
: Analysis(t, n, r, m)
{

}

ModuleAnalysis::ModuleAnalysis(Type t, const std::string& n,
	int r, transforms::PassManager* m)
: Analysis(t, n, r, m)
{

}

}

#endif


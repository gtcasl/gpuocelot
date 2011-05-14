/*! \file   Analysis.cpp
	\author Gregory Diamos <gdiamos@gatech.edu>
	\date   Saturday May 7, 2011
	\brief  The source file for the Analysis class.
*/

#ifndef ANALYSIS_CPP_INCLUDED
#define ANALYSIS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/Analysis.h>

#include <ocelot/transforms/interface/PassManager.h>

// Standard Library Includes
#include <cassert>

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

Analysis* Analysis::getAnalysis(Analysis::Type type)
{
	assert(_manager != 0);
	return _manager->getAnalysis(type);
}

const Analysis* Analysis::getAnalysis(Analysis::Type type) const
{
	assert(_manager != 0);
	return _manager->getAnalysis(type);
}

void Analysis::invalidateAnalysis(Analysis::Type type)
{
	assert(_manager != 0);
	_manager->invalidateAnalysis(type);
}

}

#endif


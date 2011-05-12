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

Analysis::Analysis(Type t, transforms::PassManager* m)
: _type(t), _manager(m)
{

}

Analysis::Type Analysis::type() const
{
	return _type;
}

KernelAnalysis::KernelAnalysis(Type t, transforms::PassManager* m)
: Analysis(t, m)
{

}

ModuleAnalysis::ModuleAnalysis(Type t, transforms::PassManager* m)
: Analysis(t, m)
{

}

}

#endif


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

Analysis::Analysis(Type t)
: _type(t)
{

}

Analysis::Type Analysis::type() const
{
	return _type;
}

}

#endif


/*!
	\file DynamicTranslationCache.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 11, 2011
	\brief cache of translations
*/

// Ocelot includes
#include <ocelot/executive/interface/DynamicTranslationCache.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

///////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicTranslationCache::DynamicTranslationCache() {

}

executive::DynamicTranslationCache::~DynamicTranslationCache() {

}


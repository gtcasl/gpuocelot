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

executive::DynamicTranslationCache::Translation *
executive::DynamicTranslationCache::getOrInsertTranslation(
	int warpsize, SubkernelId subkernel, unsigned int specialization) {
	
	report(" DynamicTranslationCache::getOrInsertTranslation(ws: " << warpsize 
		<< ", skId: " << subkernel << ", specialization = " << specialization << ")");
		
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicTranslationCache::Translation::Translation(llvm::Function *_llvmFunction):
	llvmFunction(_llvmFunction), function(0) {

}

void executive::DynamicTranslationCache::Translation::execute() {
	assert(function);
}

///////////////////////////////////////////////////////////////////////////////////////////////////


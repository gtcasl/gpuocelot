/*!
	\file Debug.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date February 19, 2012
	\brief enhances several trace tools to provide additional feedback for debugging
*/

#ifndef OCELOT_ANALYSIS_DEBUG_H_INCLUDED
#define OCELOT_ANALYSIS_DEBUG_H_INCLUDED

// C++ includes
#include <execinfo.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

namespace hydrazine {

	int getNestingDepth(int maxDepth = 0) {
		void *symbols[64] = {0};
		int symbolCount = backtrace(symbols, 64);
		if (maxDepth && maxDepth < symbolCount) {
			return maxDepth;
		}
		return symbolCount;
	}
}

#ifndef NDEBUG
	#define reportNTE(x, y) \
		if(REPORT_BASE >= REPORT_ERROR_LEVEL && (x) >= REPORT_ERROR_LEVEL)\
		{ \
			{\
			std::cout << hydrazine::_debugFile( __FILE__, __LINE__ ) \
				<< " " << y << "\n";\
			}\
		 \
		}
#else
	#define reportNTE(x, y)
#endif

#ifndef NDEBUG
#define reportNested(flag, x, depth) if (REPORT_BASE && flag >= REPORT_BASE)\
	{ int w = 2*hydrazine::getNestingDepth(depth); \
	std::streamsize old = std::cout.width(); \
	std::cout.width(w); std::cout.fill(' '); std::cout.width(old); \
	{\
		std::cout << "(" << hydrazine::_debugTime() << ") " \
			<< hydrazine::_debugFile( __FILE__, __LINE__ ) << " " << x << "\n";\
	 } }
#else
#define reportNested(flag, x, caller)
#endif

#endif


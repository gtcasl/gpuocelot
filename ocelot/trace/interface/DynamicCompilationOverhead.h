/*!
	\file DynamicCompilationOverhead.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date August 16, 2011
	\brief accumulates time spent in each of Ocelot's dynamic JIT compilation components
*/

#ifndef OCELOT_TRACE_DYNAMICCOMPILATIONOVERHEAD_H_INCLUDED
#define OCELOT_TRACE_DYNAMICCOMPILATIONOVERHEAD_H_INCLUDED

// Hydrazine includes
#include <hydrazine/implementation/Timer.h>

namespace trace {
	class DynamicCompilationOverhead {
	
	public:
		DynamicCompilationOverhead();
		~DynamicCompilationOverhead();
		
		//! starts a timer
		void start();
		
		//! stops the timer and adds time to a selected accumulator
		void stop(double DynamicCompilationOverhead::* accumulator);
	
	private:
		hydrazine::Timer timer;
		
	public:
		//! accumulates time spent in Ocelot's parser
		double ptxParseOcelot;
		
		//! accumulates time spent instrumenting PTX kernels
		double instrumentPtx;
		
		//! accumulates time spent emitting PTX kernels to a string
		double ptxEmitOcelot;
		
		//! accumulates time spent 
		double ptxRegister;
		
		//! accumulates time to execute an empty kernel
		double kernelExecute;
		
	public:
		static DynamicCompilationOverhead instance;
	};

}
#endif


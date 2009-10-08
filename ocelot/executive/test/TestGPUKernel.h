/*!

	\file TestGPUKernel.h
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\date 21 Jan 2009
	
	\brief Tests the GPUKernel object by loading a PTX module and invoking several kernels on
		the GPU

*/

#ifndef TEST_GPUKERNEL_H_INCLUDED
#define TEST_GPUKERNEL_H_INCLUDED

#include <cmath>

#include <sstream>
#include <fstream>

#include <hydrazine/interface/Test.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/implementation/debug.h>

#include <ocelot/executive/interface/Executive.h>
#include <ocelot/executive/interface/GPUExecutableKernel.h>
#include <ocelot/executive/interface/RuntimeException.h>
#include <ocelot/executive/interface/CooperativeThreadArray.h>

#include <ocelot/trace/interface/TraceGenerator.h>
#include <hydrazine/implementation/Timer.h>

#include <iostream>
#include <deque>

namespace test
{

	/*!
	
		\brief A test for the Executive and GPUKernel classes
		
		Test Points:
		
			1) Load a PTX module. Translate to GPUKernel using the Executive and the GPU device. 
				Configure and launch kernel grid. Compare results to expectations.
	
	*/
	class TestGPUKernel : public Test {
	
		private:
			executive::GPUExecutableKernel *kernelDivergence;
			executive::GPUExecutableKernel *kernelLooping;
			executive::GPUExecutableKernel *kernelMVProduct;

			executive::Executive context;

			int ThreadCount;
		
		private:
			bool loadKernels();	
			virtual bool doTest();
		
		public:
		
			TestGPUKernel();
	};
}

int main( int arch, char** argv );

#endif




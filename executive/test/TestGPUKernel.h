/*!

	\file TestGPUKernel.h
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\date 21 Jan 2009
	
	\brief Tests the GPUKernel object by loading a PTX module and invoking several kernels on
		the GPU

*/

#ifndef TEST_GPUKERNEL_H_INCLUDED
#define TEST_GPUKERNEL_H_INCLUDED

#include <common/interface/Test.h>
#include <deque>

namespace test
{

	/*!
	
		\brief A test for the Executive and GPUKernel classes
		
		Test Points:
		
			1) Load a PTX module. Translate to GPUKernel using the Executive and the GPU device. 
				Configure and launch kernel grid. Compare results to expectations.
	
	*/
	class TestGPUKernel : public Test
	{
				
		private:
			
			bool doTest( std::string& status );
		
		public:
		
			TestGPUKernel();
	
	};

}

int main( int arch, char** argv );

#endif


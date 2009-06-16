/*!

	\file TestCapModel3.h
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>

	\date Saturday December 13, 2008

	\brief The header file for the TestCapModel3 class.

*/

#ifndef TEST_CAP_MODEL_3_H_INCLUDED
#define TEST_CAP_MODEL_3_H_INCLUDED

#include "Test.h"
#include "SimulationParameters.h"

namespace test
{

	/*!
	
		\brief A test for the CapModel3 class.
		
		Test Points:
		
			1) Run the simulation using the CPU C version and the GPU CUDA
				version, comparing the results.
	
	*/
	class TestCapModel3 : public Test
	{
	
		private:
		
			bool _testCpuGpu( );
		
			bool doTest();
	
		public:
		
			sim::SimulationParameters parameters;
			
			std::string ratingsFileName;
			std::string industryFileName;
			std::string portfolioFileName;
			std::string obligorsFileName;
			std::string twistersFileName;
			
			bool useGpu;
			int device;
	
		public:
		
			TestCapModel3();
	
	};


}

int main( int argc, char** argv );

#endif


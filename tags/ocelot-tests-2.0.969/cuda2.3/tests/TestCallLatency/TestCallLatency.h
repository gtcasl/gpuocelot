/*!	\file TestCallLatency.h
	\date Saturday November 21, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for a test for cuda call latency.
*/

#ifndef TEST_CALL_LATENCY_H_INCLUDED
#define TEST_CALL_LATENCY_H_INCLUDED

#include <hydrazine/interface/Test.h>

namespace test
{
	class TestCallLatency : public Test
	{
		private:
			bool testKernelLaunchLatency();
		
			bool doTest();
	
		public:
			unsigned int iterations;
			unsigned int ctas;
			unsigned int threads;
	
		public:
			TestCallLatency();
	};
}

int main( int argc, char** argv );

#endif


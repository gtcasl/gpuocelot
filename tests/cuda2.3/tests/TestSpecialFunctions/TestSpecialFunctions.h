/*!	\file TestSpecialFunctions.h
	\date Friday November 13, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief A test for special function thoughput.
*/

#ifndef TEST_SPECIAL_FUNCTIONS_H_INCLUDED
#define TEST_SPECIAL_FUNCTIONS_H_INCLUDED

#include <hydrazine/interface/Test.h>

namespace test
{
	class TestSpecialFunctions : public Test
	{
		private:
			bool testRcp();
			bool testSqrt();
			bool testRsqrt();
			bool testSin();
			bool testCos();
			bool testLg2();
			bool testEx2();
			bool doTest();
		
		public:
			TestSpecialFunctions();
		
		public:
			long long unsigned int threads;
			long long unsigned int ctas;
			long long unsigned int unroll;
			long long unsigned int iterations;
	};
}

int main(int argc, char** argv);

#endif


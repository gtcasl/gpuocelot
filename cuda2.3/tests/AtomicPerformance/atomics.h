/*! \file atomics.h
	\date Tuesday November 10, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the set of atomic operation benchmarks
*/

#ifndef ATOMICS_H_INCLUDED
#define ATOMICS_H_INCLUDED

#include <hydrazine/interface/Test.h>

namespace test
{
	class TestAtomics : public Test
	{
		private:
			bool doTest();
		
		public:
			TestAtomics();
			
		public:
			long long unsigned int iterations;
			unsigned int threads;
			unsigned int ctas;
	};
}

long long unsigned int atomic_increment(long long unsigned int iterations, 
	unsigned int threads, unsigned int ctas);
long long unsigned int serial_increment(long long unsigned int iterations);

int main(int argc, char** argv);

#endif


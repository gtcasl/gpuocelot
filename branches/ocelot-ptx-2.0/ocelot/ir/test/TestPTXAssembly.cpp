/*! \file TestPTXAssembly.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday May 11, 2010
	\brief The source file for the TestPTXAssembly class.
*/

#ifndef TEST_PTX_ASSEMBLY_CPP_INCLUDED
#define TEST_PTX_ASSEMBLY_CPP_INCLUDED

#include <ocelot/ir/test/TestPTXAssembly.h>
#include <ocelot/api/interface/ocelot.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/Exception.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#define ADD_TEST(x) add( #x, x##_REF, x##_PTX, x##_OUT, \
	x##_IN, x##_THREADS, x##_CTAS);

template<typename T>
T getParameter(void* in, unsigned int offset)
{
	return *(T*)((char*)in + offset);
}

template<typename T>
void setParameter(void* output, unsigned int offset, T value)
{
	*(T*)((char*)output + offset) = value;
}

////////////////////////////////////////////////////////////////////////////////
// TEST ADD U8
const char* testAddU16_PTX = 
".version 2.0 \n\
.entry test(.param .u64 out, .param .u64 in) \n\
{	\n\
	.reg .u64 %rIn, %rOut; \n\
	.reg .u16 %r<3>; \n\
	ld.param.u64 %rIn, [in]; \n\
	ld.param.u64 %rOut, [out]; \n\
	ld.global.u16 %r0, [%rIn]; \n\
	ld.global.u16 %r1, [%rIn + 2]; \n\
	add.u16 %r2, %r0, %r1; \n\
	st.global.u16 [%rOut], %r2; \n\
	exit; \n\
}";

void testAddU16_REF(void* output, void* input)
{
	unsigned short r0 = getParameter<unsigned short>(input, 0);
	unsigned short r1 = getParameter<unsigned short>(input, 2);

	unsigned short result = r0 + r1;
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testAddU16_IN = {test::TestPTXAssembly::I16, 
	test::TestPTXAssembly::I16};

test::TestPTXAssembly::TypeVector testAddU16_OUT = {test::TestPTXAssembly::I16};

unsigned int testAddU16_THREADS = 1;

unsigned int testAddU16_CTAS = 1;

////////////////////////////////////////////////////////////////////////////////

namespace test
{
	unsigned int TestPTXAssembly::bytes(DataType t)
	{
		switch(t)
		{
			case I8: return 1;
			case I16: return 2;
			case I32: return 4;
			case I64: return 8;
			case FP32: return 4;
			case FP64: return 8;
		}
		return 1;
	}
	
	bool TestPTXAssembly::_doOneTest(const TestHandle& test, unsigned int seed)
	{
		random.seed(seed);
		
		unsigned int inputSize = 0;
		unsigned int outputSize = 0;
		
		for(TypeVector::const_iterator type = test.inputTypes.begin(); 
			type != test.inputTypes.end(); ++type)
		{
			inputSize += bytes(*type);
		}
		
		for(TypeVector::const_iterator type = test.outputTypes.begin(); 
			type != test.outputTypes.end(); ++type)
		{
			outputSize += bytes(*type);
		}
		
		char* inputBlock = new char[inputSize];
		char* outputBlock = new char[outputSize];
		char* referenceBlock = new char[outputSize];
		
		for(unsigned int i = 0; i < inputSize; ++i)
		{
			inputBlock[i] = random();
		}
		
		bool pass = true;
		int devices = 0;
		
		cudaGetDeviceCount(&devices);
		
		try
		{
			std::stringstream stream(test.ptx);
			ocelot::registerPTXModule(stream, test.name);
			
			char* deviceInput;
			char* deviceOutput;
			
			int device = 0;
			
			if(devices > 0) device = random() % devices;
			cudaSetDevice(device);
			
			cudaMalloc((void**)&deviceInput, inputSize);
			cudaMalloc((void**)&deviceOutput, outputSize);
			
			cudaMemcpy(deviceInput, inputBlock, 
				inputSize, cudaMemcpyHostToDevice);
				
			cudaSetupArgument(&deviceOutput, 8, 0);
			cudaSetupArgument(&deviceInput, 8, 8);
			cudaConfigureCall( dim3( test.ctas, 1, 1 ), 
				dim3( test.threads, 1, 1 ), 0, 0 );
			ocelot::launch(test.name, "test");
			
			cudaMemcpy(outputBlock, deviceOutput, 
				outputSize, cudaMemcpyDeviceToHost);
			
			cudaFree(deviceInput);
			cudaFree(deviceOutput);
			
			ocelot::unregisterModule(test.name);
		}
		catch(const std::exception& e)
		{
			status << " Failed during CUDA run with exception - " 
				<< e.what() << "\n";
			pass = false;
		}
		
		if(pass)
		{
			try
			{
				(*test.reference)(referenceBlock, inputBlock);
			}
			catch(const hydrazine::Exception& e)
			{
				status << " Failed during reference run with exception - " 
					<< e.what() << "\n";
				pass = false;
			}
		}
		
		unsigned int index = 0;
		for(TypeVector::const_iterator type = test.outputTypes.begin(); 
			type != test.outputTypes.end() && pass; ++type)
		{
			switch(*type)
			{
				case I8:
				{
					char computed = getParameter<char>(outputBlock, index);
					char reference = getParameter<char>(referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << " Output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (I8) computed value - " << (int)computed 
							<< " does not match reference value - " 
							<< (int)reference << "\n";
					}
					break;
				}
				case I16:
				{
					short computed = getParameter<short>(outputBlock, index);
					short reference = getParameter<short>(
						referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << " Output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (I16) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
					}
					break;
				}				
				case I32:
				{
					int computed = getParameter<int>(outputBlock, index);
					int reference = getParameter<int>(referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << "Test '" << test.name << "' (seed " 
							<< seed << "): failed, output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (I32) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
					}
					break;
				}
				case I64:
				{
					long long int computed = getParameter<long long int>(
						outputBlock, index);
					long long int reference = getParameter<long long int>(
						referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << "Test '" << test.name << "' (seed " 
							<< seed << "): failed, output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (I64) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
					}
					break;
				}
				case FP32:
				{
					float computed = getParameter<float>(outputBlock, index);
					float reference = getParameter<float>(
						referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << " Output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (F32) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
					}
					break;
				}
				case FP64:
				{
					double computed = getParameter<double>(outputBlock, index);
					double reference = getParameter<double>(
						referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << " Output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (F64) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
					}
					break;
				}

			}
			index += bytes(*type);
		}
		
		delete[] inputBlock;
		delete[] outputBlock;
		delete[] referenceBlock;
	
		return pass;
	}

	TestPTXAssembly::TestPTXAssembly(hydrazine::Timer::Second l, 
		unsigned int t) : _timeLimit(l), _tolerableFailures(t)
	{
		name = "TestPTXAssembly";
		
		description = "A unit test framework for PTX. Runs random inputs ";
		description += "through unit tests on all available devices until ";
		description += "a timer expires.";
		
		ADD_TEST(testAddU16);
	}
			
	void TestPTXAssembly::add(const std::string& name, 
		ReferenceFunction function, const std::string& ptx, 
		const TypeVector& out, const TypeVector& in, unsigned int threads, 
		unsigned int ctas)
	{
		TestHandle test;
		test.name = name;
		test.reference = function;
		test.ptx = ptx;
		test.inputTypes = in;
		test.outputTypes = out;
		test.threads = threads;
		test.ctas = ctas;
		
		_tests.push_back(std::move(test));
	}
		
	bool TestPTXAssembly::doTest()
	{
		hydrazine::Timer::Second perTestTimeLimit = _timeLimit / _tests.size();
		hydrazine::Timer timer;
		
		unsigned int failures = 0;
		
		for(TestVector::iterator test = _tests.begin(); 
			test != _tests.end(); ++test)
		{
			timer.stop();
			timer.start();

			for(unsigned int i = 0; timer.seconds() < perTestTimeLimit; ++i)
			{
				bool result = _doOneTest(*test, seed + i);
				
				if(!result)
				{
					status << "Test '" << test->name << "' seed '" 
						<< (seed + i) << "' failed.\n";
					if(++failures > _tolerableFailures) return 0;
				}
				
				timer.stop();
			}			
		}
		
		return failures == 0;
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser(argc, argv);
	test::TestPTXAssembly test;
	parser.description(test.testDescription());

	parser.parse("-v", "--verbose", test.verbose, false,
		"Print out status info after the test.");
	parser.parse("-s", "--seed", test.seed, 0,
		"Random seed for generating input data. 0 implies seed with time.");
	parser.parse();

	test.test();
	
	return test.passed();
}

#endif


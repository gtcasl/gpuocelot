/*! \file TestDeviceSwitching.cpp
	\date Saturday January 23, 2010
	\author Gregory Diamos
	\brief The source file for the TestDeviceSwitching class.
*/

#ifndef TEST_DEVICE_SWITCHING_CPP_INCLUDED
#define TEST_DEVICE_SWITCHING_CPP_INCLUDED

#include <tests/TestDeviceSwitching/TestDeviceSwitching.h>
#include <ocelot/api/interface/ocelot.h>

#include <cuda_runtime_api.h>

#include <hydrazine/interface/Thread.h>
#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/debug.h>

#include <vector>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace test
{
	typedef std::vector< unsigned int* > PointerVector;		

	static ocelot::KernelPointer registerKernel()
	{
		std::string ptx = ".version 1.4\n";
		ptx += ".target sm_13, map_f64_to_f32\n\n";
		ptx += ".entry increment( .param .u64 memory )\n";
		ptx += "{\n";
		ptx += "	.reg .u64 %lr;\n";
		ptx += "	.reg .u32 %r<2>;\n";
		ptx += "	Entry:\n";
		ptx += "		ld.param.u64 %lr0, [memory];\n";
		ptx += "		ld.global.u32 %r0, [%lr0];\n";
		ptx += "		add.u32 %r1, %r0, 1;\n";
		ptx += "		st.global.u32 [%lr0], %r1;\n";
		ptx += "	Exit:\n";
		ptx += "		exit;\n";
		ptx += "}\n";
		
		std::stringstream stream( ptx );
		ocelot::registerPTXModule( stream, "simpleKernels" );
		return ocelot::getKernelPointer( "increment", "simpleKernels" );
	}

	static std::string getDeviceName( int device )
	{
		cudaDeviceProp deviceProp;
        cudaGetDeviceProperties( &deviceProp, device );
        return deviceProp.name;
	}

	class Thread : public hydrazine::Thread
	{
		public:
			unsigned int device;
			unsigned int* pointer;
			ocelot::KernelPointer kernel;
		
		private:
			void execute()
			{
				cudaSetDevice( device );
				cudaMemset( pointer, 0, sizeof( unsigned int ) );
			
				cudaConfigureCall( dim3( 1, 1, 1 ), dim3( 1, 1, 1 ), 0, 0 );
				cudaSetupArgument( &pointer, 
					sizeof( long long unsigned int ), 0 );
				cudaLaunch( kernel );
			}
	};

	static void launchThreads( PointerVector& pointers, 
		ocelot::KernelPointer kernel )
	{
		typedef std::vector< Thread > ThreadVector;
	
		ThreadVector threads( pointers.size() );
		
		for( ThreadVector::iterator thread = threads.begin(); 
			thread != threads.end(); ++thread )
		{
			unsigned int index = std::distance( threads.begin(), thread );
			thread->device = index;
			thread->pointer = pointers[ index ];
			thread->kernel = kernel;
			thread->start();
		}
		
		for( ThreadVector::iterator thread = threads.begin(); 
			thread != threads.end(); ++thread )
		{
			thread->join();
		}
	}

	bool TestDeviceSwitching::testSwitching()
	{
		ocelot::reset();
		ocelot::KernelPointer kernel = registerKernel();
		
		int devices;
		cudaGetDeviceCount( &devices );
		
		PointerVector pointers( devices );
		
		for( int device = 0; device != devices; ++device )
		{
			cudaSetDevice( device );
			cudaMalloc( (void**) &pointers[ device ], sizeof( unsigned int ) );
			cudaMemset( pointers[ device ], 0, sizeof( unsigned int ) );
			
			cudaConfigureCall( dim3( 1, 1, 1 ), dim3( 1, 1, 1 ), 0, 0 );
			cudaSetupArgument( &pointers[device], 
				sizeof( long long unsigned int ), 0 );
			cudaLaunch( kernel );
		}
		
		for( int device = 0; device != devices; ++device )
		{
			cudaSetDevice( device );
			unsigned int result = 0;
			cudaMemcpy( &result, pointers[ device ], 
				sizeof( unsigned int ), cudaMemcpyDeviceToHost );
			if( result != 1 )
			{
				status << "Test Point 1 FAILED:\n";
				status << " Expected result 1 for device " << device << " (" 
					<< getDeviceName(device) << "), but got " << result << "\n";
				return false;
			}			
			cudaFree( pointers[ device ] );
		}
		
		status << "Test Point 1 Passed\n";
		return true;
	}
	
	bool TestDeviceSwitching::testContextSwitching()
	{
		ocelot::reset();
		ocelot::KernelPointer kernel = registerKernel();
		
		int devices;
		cudaGetDeviceCount( &devices );

		unsigned int* pointer = 0;
		
		for( int device = 0; device != devices; ++device )
		{
			cudaSetDevice( device );
			if( device == 0 )
			{
				cudaMalloc( (void**) &pointer, sizeof( unsigned int ) );
				cudaMemset( pointer, 0, sizeof( unsigned int ) );
			} 
			else
			{
				ocelot::contextSwitch( device, device - 1 );
			}
			
			cudaConfigureCall( dim3( 1, 1, 1 ), dim3( 1, 1, 1 ), 0, 0 );
			cudaSetupArgument( &pointer, sizeof( long long unsigned int ), 0 );
			cudaLaunch( kernel );
			cudaThreadSynchronize();
		}
		
		if( devices > 0 )
		{
			unsigned int result = 0;
			cudaMemcpy( &result, pointer, 
				sizeof( unsigned int ), cudaMemcpyDeviceToHost );
			++result;
			if( result != (unsigned int) devices )
			{
				status << "Test Point 2 FAILED:\n";
				status << " Expected result " << devices << ", but got " 
					<< result << "\n";
				return false;
			}
			cudaFree( pointer );
		}
		
		status << "Test Point 2 Passed\n";
		return true;
	}

	bool TestDeviceSwitching::testThreads()
	{
		ocelot::reset();
		ocelot::KernelPointer kernel = registerKernel();
		
		int devices;
		cudaGetDeviceCount( &devices );
		
		PointerVector pointers( devices );
		
		for( int device = 0; device != devices; ++device )
		{
			cudaSetDevice( device );
			cudaMalloc( (void**) &pointers[ device ], sizeof( unsigned int ) );
		}

		launchThreads( pointers, kernel );
		
		for( int device = 0; device != devices; ++device )
		{
			cudaSetDevice( device );
			unsigned int result = 0;
			cudaMemcpy( &result, pointers[ device ], 
				sizeof( unsigned int ), cudaMemcpyDeviceToHost );
			if( result != 1 )
			{
				status << "Test Point 3 FAILED:\n";
				status << " Expected result 3 for device " << device << " (" 
					<< getDeviceName(device) << "), but got " << result << "\n";
				return false;
			}			
			cudaFree( pointers[ device ] );
		}
		
		status << "Test Point 3 Passed\n";
		return true;
	}
	
	bool TestDeviceSwitching::doTest()
	{
		return testSwitching() && testContextSwitching() && testThreads();
	}

	TestDeviceSwitching::TestDeviceSwitching()
	{
		name = "TestDeviceSwitching";
		
		description = "A unit test for the ability of the CUDA runtime to \
			switch between devices and use multiple threads \
		\
		Test Points:\
			1) In a single threaded application, iterate across all devices\
				launching the same simple kernel each time\
			2) Test context migration support in ocelot.  Iterate across\
				all devices, launching a simple kernel that updates shared\
				variable.  Use the context switch mechanism to migrate\
				the shared data.\
			3) Test multi-threading support.  Launch one host thread to\
				allocate memory, pass pointers to worker threads, each of which\
				should launch independent kernels in parallel.";
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestDeviceSwitching test;
	parser.description( test.testDescription() );

	parser.parse( "-s", "--seed", test.seed, 0, 
		"Random number generator seed, 0 implies seed with time." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out information after the test has finished." );
	parser.parse();
	
	test.test();
	
	return test.passed();	
}

#endif


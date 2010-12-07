#include <fstream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <iostream>

#include <cuda_runtime_api.h>


#include <Exception.h>
#include <json.h>

using namespace std;
using namespace hydrazine;

string removeSpaces( string stringIn )
{
	string::size_type pos = 0;
	bool spacesLeft = true;

	while( spacesLeft )
	{
		pos = stringIn.find(" ");
		if( pos != string::npos )
			stringIn.erase( pos, 1 );
		else
			spacesLeft = false;
	}

	return stringIn;
}

void jsonEmitter(cudaDeviceProp &deviceProp, int driverVersion, int runtimeVersion)
{
	//int size = ctaNum*threadNum*bbcount;
	json::Object *table = new json::Object;
	json::Object *column;

	/* per thread BB execution count */
	column = new json::Object;
	json::Number *value;
	table->dictionary["GPU"] = column;
	
	
	value = new json::Number(deviceProp.major);
	column->dictionary["Major"] = value;

	
	value = new json::Number(deviceProp.minor);
	column->dictionary["Minor"] = value;

	
	value = new json::Number(driverVersion);
	column->dictionary["Driver Version"] = value;

	
	value = new json::Number(runtimeVersion);
	column->dictionary["Runtime Version"] = value;

	
	value = new json::Number((int)deviceProp.totalGlobalMem);
	column->dictionary["Total Global Memory"] = value;

	
	value = new json::Number(deviceProp.regsPerBlock);
	column->dictionary["multiProcessorCount"] = value;

	
	value = new json::Number((int)deviceProp.sharedMemPerBlock);
	column->dictionary["Shared Memory Per Block"] = value;

	
	value = new json::Number(deviceProp.regsPerBlock);
	column->dictionary["Registers Per Block"] = value;

	
	value = new json::Number(deviceProp.warpSize);
	column->dictionary["Warp Size"] = value;

	
	value = new json::Number((int)deviceProp.memPitch);
	column->dictionary["Total Memory Pitch"] = value;

	
	value = new json::Number((int)deviceProp.maxThreadsDim[0]);
	column->dictionary["Maximum block dimension.x"] = value;

	
	value = new json::Number((int)deviceProp.maxThreadsDim[1]);
	column->dictionary["Maximum block dimension.y"] = value;
	
	
	value = new json::Number((int)deviceProp.maxThreadsDim[2]);
	column->dictionary["Maximum block dimension.z"] = value;

	
	value = new json::Number((int)deviceProp.maxGridSize[0]);
	column->dictionary["Maximum grid dimension.x"] = value;

	
	value = new json::Number((int)deviceProp.maxGridSize[1]);
	column->dictionary["Maximum grid dimension.y"] = value;
	
	
	value = new json::Number((int)deviceProp.maxGridSize[2]);
	column->dictionary["Maximum grid dimension.z"] = value;
	
	
	value = new json::Number((int)deviceProp.maxThreadsPerBlock);
	column->dictionary["Maximum Threads Per Block"] = value;
		
	
	value = new json::Number((int)deviceProp.totalConstMem);
	column->dictionary["Total Constant Memory"] = value;
		
	
	value = new json::Number((int)deviceProp.clockRate);
	column->dictionary["Clock rate"] = value;
			
	
	value = new json::Number((int)deviceProp.textureAlignment);
	column->dictionary["Texture alignment"] = value;
			
	
	value = new json::Number((int)deviceProp.deviceOverlap);
	column->dictionary["concurrent copy and execution"] = value;
			
	
	value = new json::Number((int)deviceProp.kernelExecTimeoutEnabled);
	column->dictionary["Run time limit on kernels"] = value;

	
	value = new json::Number((int)deviceProp.integrated);
	column->dictionary["Integrated"] = value;
	
	
	value = new json::Number((int)deviceProp.canMapHostMemory);
	column->dictionary["Support  host page-locked memory mapping"] = value;
	
	
	value = new json::Number((int)deviceProp.computeMode);
	column->dictionary["Compute Mode"] = value;

	//start emitter
	ofstream outFile;
	string devName(deviceProp.name);
	devName = removeSpaces(devName);

	string tmpStr = "deviceList." + devName;
	int i=1;
	bool alreadyExists;
	do {
		outFile.open((tmpStr + ".json").c_str(), ios::in);	
		if( outFile.is_open() )
		{
			cout<<"file exists"<<endl;
			alreadyExists=true;
			stringstream out;
			out << "deviceList." << devName << "." << i;
			tmpStr = out.str();
			i++;
		} else {
			alreadyExists=false;
		}
		outFile.close();
	}while(alreadyExists);
		
	
	outFile.open((tmpStr + ".json").c_str());
	json::Emitter emitter;
	emitter.use_tabs = false;
	emitter.emit_pretty(outFile, table, 2);

	return;
}

int main( int argc, const char** argv) 
{
    int deviceCount = 0;
	cudaGetDeviceCount( &deviceCount); 
	
    if (deviceCount == 0)
        cout << "There is no device supporting CUDA\n";

    int dev;
	int driverVersion = 0, runtimeVersion = 0;     
    for (dev = 0; dev < deviceCount; ++dev) {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, dev);

        if (dev == 0) {
			// This function call returns 9999 for both major & minor fields, if no CUDA capable devices are present
            if (deviceProp.major == 9999 && deviceProp.minor == 9999)
                cout << "There is no device supporting CUDA.\n";
            else if (deviceCount == 1)
                cout << "There is 1 device supporting CUDA\n";
            else
                cout << "There are " << deviceCount << " devices supporting CUDA\n";
        }
        cout << "\nDevice " << dev << ": " << deviceProp.name << "\n";


    #if CUDART_VERSION >= 2020
        // Console log
		cudaDriverGetVersion(&driverVersion);
		cout << "  CUDA Driver Version:                           " 
			<< driverVersion/1000 << " " << driverVersion%100 << "\n";
		cudaRuntimeGetVersion(&runtimeVersion);
		cout << "  CUDA Runtime Version:                          " 
			<< runtimeVersion/1000 << " " << runtimeVersion%100 << "\n";
    #endif
        cout << "  CUDA Capability Major revision number:         " << deviceProp.major << "\n";
        cout << "  CUDA Capability Minor revision number:         " << deviceProp.minor << "\n";

		printf("  Total amount of global memory:                 %u bytes\n", (unsigned int)deviceProp.totalGlobalMem);
    #if CUDART_VERSION >= 2000
        printf("  Number of multiprocessors:                     %d\n", deviceProp.multiProcessorCount);
    #endif
        printf("  Total amount of constant memory:               %u bytes\n", deviceProp.totalConstMem); 
        printf("  Total amount of shared memory per block:       %u bytes\n", deviceProp.sharedMemPerBlock);
        printf("  Total number of registers available per block: %d\n", deviceProp.regsPerBlock);
        printf("  Warp size:                                     %d\n", deviceProp.warpSize);
        printf("  Maximum number of threads per block:           %d\n", deviceProp.maxThreadsPerBlock);
        printf("  Maximum sizes of each dimension of a block:    %d x %d x %d\n",
               deviceProp.maxThreadsDim[0],
               deviceProp.maxThreadsDim[1],
               deviceProp.maxThreadsDim[2]);
        printf("  Maximum sizes of each dimension of a grid:     %d x %d x %d\n",
               deviceProp.maxGridSize[0],
               deviceProp.maxGridSize[1],
               deviceProp.maxGridSize[2]);
        printf("  Maximum memory pitch:                          %u bytes\n", deviceProp.memPitch);
        printf("  Texture alignment:                             %u bytes\n", deviceProp.textureAlignment);
        printf("  Clock rate:                                    %.2f GHz\n", deviceProp.clockRate * 1e-6f);
    #if CUDART_VERSION >= 2000
        printf("  Concurrent copy and execution:                 %s\n", deviceProp.deviceOverlap ? "Yes" : "No");
    #endif
    #if CUDART_VERSION >= 2020
        printf("  Run time limit on kernels:                     %s\n", deviceProp.kernelExecTimeoutEnabled ? "Yes" : "No");
        printf("  Integrated:                                    %s\n", deviceProp.integrated ? "Yes" : "No");
        printf("  Support host page-locked memory mapping:       %s\n", deviceProp.canMapHostMemory ? "Yes" : "No");
        printf("  Compute mode:                                  %s\n", deviceProp.computeMode == cudaComputeModeDefault ?
			                                                            "Default (multiple host threads can use this device simultaneously)" :
		                                                                deviceProp.computeMode == cudaComputeModeExclusive ?
																		"Exclusive (only one host thread at a time can use this device)" :
		                                                                deviceProp.computeMode == cudaComputeModeProhibited ?
																		"Prohibited (no host thread can use this device)" :
																		"Unknown");
    #endif
	
		jsonEmitter(deviceProp, driverVersion, runtimeVersion);
	}
}

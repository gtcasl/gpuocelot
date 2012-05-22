#include <stdio.h>
#include <CL/cl.h>
#include <string.h>

#define DATA_SIZE 13

char* myLoadProgSource(const char* cFilename, const char* cPreamble, size_t* szFinalLength)
{
    // locals 
    FILE* pFileStream = NULL;
    size_t szSourceLength;

    pFileStream = fopen(cFilename, "rb");
    if(pFileStream == 0) 
    {       
        return NULL;
    }

    size_t szPreambleLength = strlen(cPreamble);

    // get the length of the source code
    fseek(pFileStream, 0, SEEK_END); 
    szSourceLength = ftell(pFileStream);
    fseek(pFileStream, 0, SEEK_SET); 

    // allocate a buffer for the source code string and read it in
    char* cSourceString = (char *)malloc(szSourceLength + szPreambleLength + 1); 
    memcpy(cSourceString, cPreamble, szPreambleLength);
    if (fread((cSourceString) + szPreambleLength, szSourceLength, 1, pFileStream) != 1)
    {
        fclose(pFileStream);
        free(cSourceString);
        return 0;
    }

    // close the file and return the total length of the combined (preamble + source) string
    fclose(pFileStream);
    if(szFinalLength != 0)
    {
        *szFinalLength = szSourceLength + szPreambleLength;
    }
    cSourceString[szSourceLength + szPreambleLength] = '\0';

    return cSourceString;
}

int main(void)
{
	cl_context context;
	cl_context_properties properties[3];
	cl_kernel kernel;
	cl_command_queue command_queue;
	cl_program program;
	cl_int err;
	cl_uint num_of_platforms;
	cl_platform_id platform_id = NULL;
	cl_device_id device_id[2];
	cl_uint num_of_devices;
	cl_mem clInput, clOutput;	
	size_t global;

	char inputData[DATA_SIZE]="Hello World!";
	char results[DATA_SIZE]="";

	int i;

	// retreive a list of platforms avaible
	if (clGetPlatformIDs(1, &platform_id, &num_of_platforms) != CL_SUCCESS)
	{
		printf("Unable to get platform_id\n");
		return 1;
	}
	
	printf("Platform number: %d\n", num_of_platforms);

	char tmpBuffer[1024];
	if ((err = clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, sizeof(tmpBuffer), tmpBuffer, NULL)) != CL_SUCCESS)
	{
		printf("%d, Unable to get platform name!\n", err);
		return 1;
	}

	printf("Platform name: %s\n", tmpBuffer);
  
	if (clGetPlatformInfo(platform_id, CL_PLATFORM_VERSION, sizeof(tmpBuffer), tmpBuffer, NULL) != CL_SUCCESS)
	{
		printf("Unable to get platform version!\n");
		return 1;
	}

	printf("Platform version: %s\n", tmpBuffer);
 
	// try to get a supported GPU device
	if ((err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ALL, 1, device_id, &num_of_devices)) != CL_SUCCESS)
	{
		printf("Unable to get device_id, %d\n", err);
		return 1;
	}

	if(num_of_devices == 0)
	{
		printf("No devices found!\n");
		return 1;
	}

	printf("Device Number: %d\n", num_of_devices);

	if (clGetDeviceInfo(device_id[0], CL_DEVICE_NAME, sizeof(tmpBuffer), &tmpBuffer, NULL) != CL_SUCCESS)
	{
		printf("Unable to get device name\n");
		return 1;
	} 

	printf("Device Name: %s\n", tmpBuffer);

	cl_ulong tmpLong;
	if(clGetDeviceInfo(device_id[0], CL_DEVICE_LOCAL_MEM_SIZE, sizeof(tmpLong), &tmpLong, NULL) != CL_SUCCESS) {
		printf("Unable to get local memory size\n");
		return 1;
	}
	printf("Device local mem size: %ld\n", tmpLong);

	// context properties list - must be terminated with 0
	properties[0]= CL_CONTEXT_PLATFORM;
	properties[1]= (cl_context_properties) platform_id;
	properties[2]= 0;

	// create a context with the GPU device
	context = clCreateContext(properties,1,&device_id[0],NULL,NULL,&err);
	printf("context, %x, err %d, \n", context, err);

	// create command queue using the context and device
	command_queue = clCreateCommandQueue(context, device_id[0], 0, &err);
	printf("command queue, %x, err %d, \n", command_queue, err);
	
	//Get Source code
	char * ProgramSource = myLoadProgSource("hello_world.cl", "", NULL);
	if(!ProgramSource)
	{
		printf("Failed to load program source!\n");
		return 1;	
	}

	// create a program from the kernel source code
	program = clCreateProgramWithSource(context,1,(const char **) &ProgramSource, NULL, &err);
//	free(ProgramSource);
	printf("program, %x, err %d, \n", program, err);

	// compile the program
	if ((err = clBuildProgram(program, 1, device_id, NULL, NULL, NULL)) != CL_SUCCESS)
	{
		printf("Error building program, err %d\n", err);
		return 1;
	}

	//Get Binary
	char out_name[] = "hello_world.cl.ptx";
	unsigned char * binaryProgram;
	size_t binarySize;
	err = clGetProgramInfo(program, CL_PROGRAM_BINARY_SIZES, sizeof(size_t), &binarySize, NULL);
	printf("binary size %d, err %d\n", binarySize, err);
	binaryProgram = (unsigned char *)malloc(binarySize * sizeof(unsigned char));
	size_t returnSize;
	clGetProgramInfo(program, CL_PROGRAM_BINARIES, binarySize*sizeof(char), &binaryProgram, &returnSize); 
	printf("return binary size %d, err %d\n", returnSize, err);
	FILE * fBinary = fopen(out_name, "wb");
	fwrite(binaryProgram, 1, binarySize, fBinary);
	fclose(fBinary);
	
	// specify which kernel from the program to execute
	kernel = clCreateKernel(program, "hello", &err);
	printf("return kernel %lx, err %d\n", kernel, err);
	// create buffers for the input and ouput
	clInput = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(char) * DATA_SIZE, NULL, &err);
	printf("return input %lx, err %d\n", clInput, err);
	clOutput = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(char) * DATA_SIZE, NULL, &err);
	printf("return output %lx, err %d\n", clOutput, err);

	// load data into the input buffer
	err = clEnqueueWriteBuffer(command_queue, clInput, CL_TRUE, 0, sizeof(char) * DATA_SIZE, inputData, 0, NULL, NULL);
	printf("writing buffer err %d\n", err);

	// set the argument list for the kernel command
	err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &clInput);
	printf("Set arg err %d\n", err);
	err = clSetKernelArg(kernel, 1, sizeof(cl_mem), &clOutput);
	printf("Set arg err %d\n", err);
	global=DATA_SIZE;

	// enqueue the kernel command for execution
	err = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
	printf("launch kernel err %d\n", err);
	clFinish(command_queue);

	// clear the results
	for(int i=0; i<DATA_SIZE; i++)
		results[i]=0;

	// copy the results from out of the output buffer
	err = clEnqueueReadBuffer(command_queue, clOutput, CL_FALSE, 0, sizeof(char) *DATA_SIZE, results, 0, NULL, NULL);
	printf("reading buffer err %d\n", err);
	clFinish(command_queue);

	// print the results
	for(int i=0; i<DATA_SIZE; i++)
		results[i]--;
	printf("output: %s\n", results);
	
	// cleanup - release OpenCL resources
	clReleaseMemObject(clInput);
	clReleaseMemObject(clOutput);
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	return 0;
}




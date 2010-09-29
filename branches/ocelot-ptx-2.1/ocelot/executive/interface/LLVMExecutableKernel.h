/*! \file LLVMExecutableKernel.h
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMRuntime class
*/

#ifndef LLVM_EXECUTABLE_KERNEL_H_INCLUDED
#define LLVM_EXECUTABLE_KERNEL_H_INCLUDED

// Ocelot Includes
#include <ocelot/translator/interface/Translator.h>
#include <ocelot/executive/interface/ExecutableKernel.h>

// Forward Declarations
namespace ir
{
	class PTXKernel;
}

namespace executive
{

/*! \brief Executes an LLVMKernel using the LLVM JIT */
class LLVMExecutableKernel : public executive::ExecutableKernel
{
public:
	/*! \brief Types of call instructions */
	enum CallType
	{
		TailCall,
		ReturnCall,
		NormalCall,
		InvalidCallType
	};

public:
	/*! \brief Creates a new instance of the runtime bound to a kernel*/
	LLVMExecutableKernel(const ir::Kernel& kernel, Device* d = 0,
		translator::Translator::OptimizationLevel 
		l = translator::Translator::NoOptimization);
	/*! \brief Clean up the runtime */
	~LLVMExecutableKernel();

public:
	/*! \brief Launch a kernel on a 2D grid */
	void launchGrid(int width, int height);
	/*! \brief Sets the shape of a cta in the kernel */
	void setKernelShape(int x, int y, int z);
	/*! \brief Declare an amount of external shared memory */
	void setExternSharedMemorySize(unsigned int bytes);
	/*! \brief Describes the device used to execute the kernel */
	void setWorkerThreads(unsigned int threadLimit);
	/*! \brief Reload parameter memory */
	void updateParameterMemory();
	/*! \brief Indicate that other memory has been updated */
	void updateMemory();
	/*! \brief Get a vector of all textures references by the kernel */
	TextureVector textureReferences() const;

public:
	/*! \brief Get the block of parameter memory associated with the kernel */
	char* parameterMemory() const;
	/*! \brief Get the block of constant memory associated with the kernel */
	char* constantMemory() const;

public:
	/*!	adds a trace generator to the EmulatedKernel */
	void addTraceGenerator(trace::TraceGenerator *generator);
	/*!	removes a trace generator from an EmulatedKernel */
	void removeTraceGenerator(trace::TraceGenerator *generator);
	
public:
	/*! \brief Get the number of threads per cta */
	unsigned int threads() const;
	/*! \brief Get the local id of the current thread */
	unsigned int threadId() const;
	/*! \brief Determine the location of a given PTX statement 
		in the original source file */
	std::string location(unsigned int statement) const;
	/*! \brieg Get the instruction contained in a given statement */
	std::string instruction(unsigned int statement) const;

private:
	typedef translator::Translator::OptimizationLevel OptimizationLevel;

private:
	const ir::PTXKernel* _kernel;
	const Device*        _device;
	OptimizationLevel    _optimizationLevel;
};

}

#endif


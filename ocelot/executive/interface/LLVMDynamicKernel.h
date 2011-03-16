/*! 
	\file LLVMDynamicKernel.h
	\author Andrew Kerr <arkerr@gatech.edu>, Gregory Diamos <gregory.diamos@gatech.edu>
	\date March 2011
	\brief impelements a dynamic execution environment for LLVM kernels
*/

#ifndef OCELOT_EXECUTIVE_LLVMDYNAMICEXECUTABLE_H_INCLUDED
#define OCELOT_EXECUTIVE_LLVMDYNAMICEXECUTABLE_H_INCLUDED

// Ocelot Includes
#include <ocelot/translator/interface/Translator.h>
#include <ocelot/executive/interface/ExecutableKernel.h>

// Standard Library Includes
#include <unordered_map>

// Forward Declarations
namespace ir
{
	class PTXKernel;
}

namespace executive
{

/*! \brief Executes an LLVMKernel using the LLVM JIT */
class LLVMDynamicKernel : public executive::ExecutableKernel {
public:

	typedef translator::Translator::OptimizationLevel OptimizationLevel;

public:
	/*! \brief Creates a new instance of the runtime bound to a kernel*/
	LLVMDynamicKernel(const ir::Kernel& kernel, Device* d = 0,
		OptimizationLevel l = translator::Translator::NoOptimization);
	/*! \brief Clean up the runtime */
	~LLVMDynamicKernel();

public:
	/*! \brief Launch a kernel on a 2D grid */
	void launchGrid(int width, int height);
	/*! \brief Sets the shape of a cta in the kernel */
	void setKernelShape(int x, int y, int z);
	/*! \brief Declare an amount of external shared memory */
	void setExternSharedMemorySize(unsigned int bytes);
	/*! \brief Describes the device used to execute the kernel */
	void setWorkerThreads(unsigned int threadLimit);
	/*! \brief Reload argument memory */
	void updateArgumentMemory();
	/*! \brief Indicate that other memory has been updated */
	void updateMemory();
	/*! \brief Get a vector of all textures references by the kernel */
	TextureVector textureReferences() const;

public:
	/*! \brief Get the block of argument memory associated with the kernel */
	char* argumentMemory() const;
	/*! \brief Get the block of constant memory associated with the kernel */
	char* constantMemory() const;
	/*! \brief Get the optimization level of the kernel */
	OptimizationLevel optimization() const;

public:
	/*!	adds a trace generator to the EmulatedKernel */
	void addTraceGenerator(trace::TraceGenerator *generator);
	/*!	removes a trace generator from an EmulatedKernel */
	void removeTraceGenerator(trace::TraceGenerator *generator);

private:
	typedef std::unordered_map<std::string, size_t> AllocationMap;
                        
private:
	/*! \brief Allocate memory for the kernel */
	void _allocateMemory();
	/*! \brief Allocate argument memory for the kernel */
	void _allocateArgumentMemory();
	/*! \brief Allocate constant memory for the kernel */
	void _allocateConstantMemory();

private:
	const ir::PTXKernel* _kernel;
	const Device*        _device;
	OptimizationLevel    _optimizationLevel;
	char*                _argumentMemory;
	char*                _constantMemory;
};

}

#endif

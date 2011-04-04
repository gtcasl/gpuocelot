/*! \file ocelot.h
	\date Friday July 24, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the Ocelot API functions.
*/

#ifndef OCELOT_H_INCLUDED
#define OCELOT_H_INCLUDED

// C++ includes
#include <istream>
#include <unordered_map>

// Ocelot includes
#include <ocelot/analysis/interface/Pass.h>

namespace trace
{
	class TraceGenerator;
}

namespace analysis 
{
    class PTXInstrumentor;
    class KernelProfile;
}

/*! \brief A namespace for ocelot API functions */
namespace ocelot
{
	/*! \brief A map between pointer types */
	typedef std::unordered_map<void*, void*> PointerMap;

	/*! \brief Adds a trace generator for the next kernel invocation 
	
		\param gen A reference to the generator being added, it must not
			be destroyed until the next kernel is executed.
		\param persistent The trace generator will be associated with all
			subsequent kernels until clear is called, otherwise it will
			only be associated with the next kernel.
		\param safe Make this a thread safe call
	*/
	void addTraceGenerator(trace::TraceGenerator& gen, 
		bool persistent = false);
				
	/*! \brief Clear all trace generators 
		\param safe Make this a thread safe call*/
	void clearTraceGenerators();

    void addInstrumentor(analysis::PTXInstrumentor& instrumentor);
    void clearInstrumentors();

    analysis::KernelProfile kernelProfile();
		
	/*! \brief Adds a PTX->PTX pass active for the next *Module load*
	
		\param pass reference to the PTX pass to be added
	*/
	void addPTXPass(analysis::Pass &pass);
	
	/*! \brief removes the specified pass */
	void removePTXPass(analysis::Pass &pass);
	
	/*! \brief clears all PTX->PTX passes */
	void clearPTXPasses();
	
	/*! \brief Sets a limit on the number of host worker threads to launch
		when executing a CUDA kernel on a Multi-Core CPU.
		\param limit The max number of worker threads to launch per kernel.
	*/
	void limitWorkerThreads(unsigned int limit = 1024);
	
	/*! \brief Register an istream containing a PTX module.
		
		\param stream An input stream containing a PTX module
		\param The name of the module being registered.  Must be Unique.
	*/
	void registerPTXModule(std::istream& stream, const std::string& name);
	
	/*! \brief Register a texture with the cuda runtime */
	void registerTexture(const void* texref,
		const std::string& moduleName,
		const std::string& textureName, bool normalize);
	
	/*! \brief Clear all errors in the Cuda Runtime */
	void clearErrors();
	
	/*! \brief Reset all CUDA runtime state */
	void reset();

	/*! \brief Perform a device context switch */
	PointerMap contextSwitch(unsigned int destinationDevice, 
		unsigned int sourceDevice);
	
	/*! \brief Unregister a module, either PTX or LLVM, not a fatbinary */
	void unregisterModule(const std::string& name);

	/*! \brief Launch a cuda kernel by name */
	void launch(const std::string& moduleName, const std::string& kernelName);
}

#endif


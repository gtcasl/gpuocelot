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
#include <ocelot/executive/interface/DeviceProperties.h>

// Forward Declarations
namespace trace
{
	class TraceGenerator;
}

namespace transforms
{
	class Pass;
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
		
	/*! \brief Adds a PTX->PTX pass active for the next *Module load*
	
		\param pass reference to the PTX pass to be added
	*/
	void addPTXPass(transforms::Pass& pass);
	
	/*! \brief removes the specified pass */
	void removePTXPass(transforms::Pass& pass);
	
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

	/*! \brief Register a callable host function with Ocelot 

		This function will be callable as a PTX function.
	*/
	void registerExternalFunction(const std::string& name, void* function);

	/*! \brief Remove a previously registered host function */
	void removeExternalFunction(const std::string& name);
	
	/*! \brief gets the Ocelot device properties of either the current device 
		(deviceIndex = -1) or the indexed device */
	void getDeviceProperties(executive::DeviceProperties &properties, int deviceIndex = -1);


	/*! \brief Abstract Ocelot Interface for all kinds of runtime frontend.
	Inherited by different runtime frontend with individual implementation of
	the ocelot runtime functions*/	
	class OcelotInterface {
	public:

	/*! \brief Adds a trace generator for the next kernel invocation 
	
		\param gen A reference to the generator being added, it must not
			be destroyed until the next kernel is executed.
		\param persistent The trace generator will be associated with all
			subsequent kernels until clear is called, otherwise it will
			only be associated with the next kernel.
		\param safe Make this a thread safe call
	*/
	virtual void addTraceGenerator(trace::TraceGenerator& gen, 
		bool persistent = false) {}
				
	/*! \brief Clear all trace generators 
		\param safe Make this a thread safe call*/
	virtual void clearTraceGenerators() {}
		
	/*! \brief Adds a PTX->PTX pass active for the next *Module load*
	
		\param pass reference to the PTX pass to be added
	*/
	virtual void addPTXPass(transforms::Pass& pass) {}
	
	/*! \brief removes the specified pass */
	virtual void removePTXPass(transforms::Pass& pass) {}
	
	/*! \brief clears all PTX->PTX passes */
	virtual void clearPTXPasses() {}
	
	/*! \brief Sets a limit on the number of host worker threads to launch
		when executing a CUDA kernel on a Multi-Core CPU.
		\param limit The max number of worker threads to launch per kernel.
	*/
	virtual void limitWorkerThreads(unsigned int limit = 1024) {}
	
	/*! \brief Register an istream containing a PTX module.
		
		\param stream An input stream containing a PTX module
		\param The name of the module being registered.  Must be Unique.
	*/
	virtual void registerPTXModule(std::istream& stream, const std::string& name) {}
	
	/*! \brief Register a texture with the cuda runtime */
	virtual void registerTexture(const void* texref,
		const std::string& moduleName,
		const std::string& textureName, bool normalize) {}
	
	/*! \brief Clear all errors in the Cuda Runtime */
	virtual void clearErrors() {}
	
	/*! \brief Reset all CUDA runtime state */
	virtual void reset() {}

	/*! \brief Perform a device context switch */
	virtual PointerMap contextSwitch(unsigned int destinationDevice, 
		unsigned int sourceDevice) {return PointerMap();}
	
	/*! \brief Unregister a module, either PTX or LLVM, not a fatbinary */
	virtual void unregisterModule(const std::string& name) {}

	/*! \brief Launch a cuda kernel by name */
	virtual void launch(const std::string& moduleName, const std::string& kernelName) {}

	/*! \brief Register a callable host function with Ocelot 

		This function will be callable as a PTX function.
	*/
	virtual void registerExternalFunction(const std::string& name, void* function) {}

	/*! \brief Remove a previously registered host function */
	virtual void removeExternalFunction(const std::string& name) {}
	
	/*! \brief gets the Ocelot device properties of either the current device 
		(deviceIndex = -1) or the indexed device */
	virtual void getDeviceProperties(executive::DeviceProperties &properties, int deviceIndex = -1) {}


		
	};
}

#endif


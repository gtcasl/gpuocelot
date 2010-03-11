/*! \file ocelot.h
	\date Friday July 24, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the Ocelot API functions.
*/

#ifndef OCELOT_H_INCLUDED
#define OCELOT_H_INCLUDED

#include <istream>

namespace trace
{
	class TraceGenerator;
}

/*! \brief A namespace for ocelot API functions */
namespace ocelot
{

	/*! \brief Adds a trace generator for the next kernel invocation 
	
		\param gen A reference to the generator being added, it must not
			be destroyed until the next kernel is executed.
		\param persistent The trace generator will be associated with all
			subsequent kernels until clear is called, otherwise it will
			only be associated with the next kernel.
		\param safe Make this a thread safe call
	*/
	void addTraceGenerator( trace::TraceGenerator& gen, 
		bool persistent = false, bool safe = true );
				
	/*! \brief Clear all trace generators 
		\param safe Make this a thread safe call*/
	void clearTraceGenerators( bool safe = true );
	
	/*! \brief Sets a limit on the number of host worker threads to launch
		when executing a CUDA kernel on a Multi-Core CPU.
		\param limit The max number of worker threads to launch per kernel.
	*/
	void limitWorkerThreads( unsigned int limit = 1024 );
	
	/*! \brief Register an istream containing a PTX module.
		
		\param stream An input stream containing a PTX module
		\param The name of the module being registered.  Must be Unique.
	*/
	void registerPTXModule(std::istream& stream, const std::string& name);
	
	typedef const char* KernelPointer;

	/*! \brief Get a function pointer to a kernel in a registered module 
		that can be passed directly to cudaLaunch
		
		This function will throw an exception if the kernel does not exist.
		
		\param name The name of the kernel to find. 
		\param module The name of the module to find the kernel in.
		
		\return A function pointer that can be passed to cudaLaunch.
	*/
	KernelPointer getKernelPointer(const std::string& name, 
		const std::string& module);

	/*! \brief Get a handle to a fat binary from its name
		
		\param name The fat binary's name
		\return A handle to the named fat binary
	*/
	void** getFatBinaryHandle(const std::string& name);

	/*! \brief Clear all errors in the Cuda Runtime */
	void clearErrors();
	
	/*! \brief Reset all CUDA runtime state */
	void reset();
	
	/*! \brief Perform a device context switch */
	void contextSwitch( unsigned int destinationDevice, 
		unsigned int sourceDevice );
	
	/*! \brief Unregister a module, either PTX or LLVM */
	void unregisterModule( const std::string& name );

}

#endif


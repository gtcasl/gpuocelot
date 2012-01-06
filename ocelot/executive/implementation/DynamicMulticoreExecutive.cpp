/*!
	\file DynamicMulticoreExecutive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 20, 2011
	\brief executes a kernel over one or more CTAs
*/


#include <ocelot/executive/interface/DynamicMulticoreExecutive.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::DynamicMulticoreExecutive(
	executive::DynamicMulticoreKernel &kernel, size_t _sharedMemorySize) {
	
	// allocate memory for Cooperative Thread array
	localMemorySize = kernel.localMemorySize();
	localMemory = new char[localMemorySize];
	
	sharedMemorySize = _sharedMemorySize;
	sharedMemory = new char[sharedMemorySize];
	
	parameterMemorySize = kernel.parameterMemorySize();
	parameterMemory = new char[parameterMemorySize];
	
	report("DynamicMulticoreExecutve('" << kernel.name << "', shared mem size: " << sharedMemorySize);
	report("  localMemorySize: " << localMemorySize);
	report("  paramMemorySize: " << parameterMemorySize);
}

executive::DynamicMulticoreExecutive::~DynamicMulticoreExecutive() {
	delete [] localMemory;
	delete [] sharedMemory;
	delete [] parameterMemory;
}

void executive::DynamicMulticoreExecutive::execute(ir::Dim3 block) {
	report("DynamicMulticoreExecutive::execute(" << block.x << ", " << block.y << ")");
	
	// initialize thread contexts
	//
	// while threads not done {
	//   form largest warp possible
	//   execute subkernel
	//   update contexts
	// }
	//
  // exit
}

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreExecutive::Metadata::Metadata() {

}

executive::DynamicMulticoreExecutive::Metadata::~Metadata() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////


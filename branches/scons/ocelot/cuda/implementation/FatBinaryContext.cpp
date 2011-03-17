/*!
	\file FatBinaryContext.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief object for interacting with CUDA Fat Binaries
*/

// Ocelot Includes
#include <ocelot/cuda/interface/FatBinaryContext.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

////////////////////////////////////////////////////////////////////////////////


cuda::FatBinaryContext::FatBinaryContext(const void *ptr): cubin_ptr(ptr) {

	if(*(int*)cubin_ptr == __cudaFatMAGIC) {
		__cudaFatCudaBinary *binary = (__cudaFatCudaBinary *)cubin_ptr;

		_name = binary->ident;

		assertM(binary->ptx != 0, "binary contains no PTX");
		assertM(binary->ptx->ptx != 0, "binary contains no PTX");

		unsigned int ptxVersion = 0;

		report("Getting the highest PTX version");

		for(unsigned int i = 0; ; ++i)
		{
			if((binary->ptx[i].ptx) == 0) break;
	
			std::string computeCapability = binary->ptx[i].gpuProfileName;
			std::string versionString(computeCapability.begin() + 8,
				computeCapability.end());
	
			std::stringstream version;
			unsigned int thisVersion = 0;
		
			version << versionString;
			version >> thisVersion;
			if(thisVersion > ptxVersion)
			{
				ptxVersion = thisVersion;
				_ptx = binary->ptx[i].ptx;
			}
		}		
		report(" Selected version " << ptxVersion);
	}
	else if (*(int*)cubin_ptr == __cudaFatMAGIC2) {
		report("Found new fat binary format!");
		__cudaFatCudaBinary2* binary = (__cudaFatCudaBinary2*) cubin_ptr;
		__cudaFatCudaBinary2Header* header =
			(__cudaFatCudaBinary2Header*) binary->fatbinData;
		_name = header->name;
		_ptx = (const char*)(header + 1);
	}
	else {
		assertM(false, "unknown fat binary magic number "
			<< std::hex << *(int*)cubin_ptr);		
		_name = 0;
		_ptx = 0;
	}

}

cuda::FatBinaryContext::FatBinaryContext(): cubin_ptr(0), _name(0), _ptx(0) {

}

const char* cuda::FatBinaryContext::name() const {
	return _name;
}	

const char* cuda::FatBinaryContext::ptx() const {
	return _ptx;
}

/////////////////////////////////////////////////////////////////////////////////////////////////


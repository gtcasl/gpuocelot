/*!
	\file FatBinaryContext.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief object for interacting with CUDA Fat Binaries
*/

#include <ocelot/cuda/interface/FatBinaryContext.h>

/////////////////////////////////////////////////////////////////////////////////////////////////


cuda::FatBinaryContext::FatBinaryContext(const void *ptr): cubin_ptr(ptr) {

}
cuda::FatBinaryContext::FatBinaryContext(): cubin_ptr(0) {

}

const char *cuda::FatBinaryContext::name() const {
	if (!cubin_ptr) return "";
	const __cudaFatCudaBinary *binary = (const __cudaFatCudaBinary *)cubin_ptr;
	return binary->ident;
}	

const char *cuda::FatBinaryContext::ptx() const {
	if (!cubin_ptr) return "";
	const __cudaFatCudaBinary *binary = (const __cudaFatCudaBinary *)cubin_ptr;
	return binary->ptx->ptx;
}

/////////////////////////////////////////////////////////////////////////////////////////////////


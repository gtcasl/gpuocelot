#ifndef _CUTIL_INLINE_H_
#define _CUTIL_INLINE_H_

#include <cuda.h>
#include <cutil.h>
#include <cuda_runtime_api.h>

#include <cutil_inline_bankchecker.h>
#include <cutil_inline_runtime.h>
#include <cutil_inline_drvapi.h>

inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
{
    printf("CUDA %d.%02d Toolkit built this project.\n", CUDART_VERSION/1000, (CUDART_VERSION%100));
    printf("  [ %s ] requirements:\n", sSDKsample);
    printf(" -> CUDA %s Toolkit\n"  , sNVCCReq);
    printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
}


#endif // _CUTIL_INLINE_H_

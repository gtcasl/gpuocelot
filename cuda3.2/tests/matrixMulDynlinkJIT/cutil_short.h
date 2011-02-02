/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */
  
#ifndef __cutil_short_h__
#define __cutil_short_h__

// taken from the "cutil_inline_runtime.h"
inline void cutilExit()
{
    exit(EXIT_SUCCESS);
}


inline void __cuSafeCallSync(CUresult err, const char *file, const int line)
{
    if (CUDA_SUCCESS != err) 
    {
        fprintf(stderr, "cuSafeCallSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
        exit(-1);
    }
    if (CUDA_SUCCESS != cuCtxSynchronize()) 
    {
        fprintf(stderr, "cuSafeCallNoSync() Driver API error at synchronization = %04d from file <%s>, line %i.\n", err, file, line);
        exit(-1);
    }
}


inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
{
    if (CUDA_SUCCESS != err) 
    {
        fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
        exit(-1);
    }
}


inline void __cutilCheckError(int err, const char *file, const int line)
{
    if (!err) 
    {
        fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n", file, line);
        exit(-1);
    }
}


#define cutilDrvSafeCallSync(err)    __cuSafeCallSync    (err, __FILE__, __LINE__)
#define cutilDrvSafeCallNoSync(err)  __cuSafeCallNoSync  (err, __FILE__, __LINE__)
#define cutilCheckError(err)         __cutilCheckError   (err, __FILE__, __LINE__)


#endif //__cutil_short_h__

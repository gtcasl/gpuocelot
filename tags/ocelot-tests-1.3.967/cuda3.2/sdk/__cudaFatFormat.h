/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  Users and possessors of this source code 
 * are hereby granted a nonexclusive, royalty-free license to use this code 
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.   This source code is a "commercial item" as 
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer  software"  and "commercial computer software 
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein. 
 *
 * Any use of this source code in individual and commercial software must 
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 *
 *  Module name              : __cudaFatFormat.h
 *
 *  Last update              :
 *
 *  Description              :
 * 
 *          This module defines the cuda compiled device code format
 *          that is able to hold a collection of compiled binaries corresponding
 *          with the same GPU source code: load images (cubins) for zero or more
 *          nVidia GPU architectures, plus PTX intermediate representations, possibly
 *          tuned for zero or more GPU architectures.
 * 
 *          It is the purpose of the cuda compilation driver (nvcc) to generate 
 *          __cudaFatCudaBinaries with actual contents depending on nvcc command line options
 *          selected by the user.
 *
 *          During runtime, the cuda driver can use function fatGetCubinForGpu for 
 *          retrieving an appropriate cubin load image, depending on the GPU
 *          architecture that is to run the device code. 
 *          fatGetCubinForGpu might employ any combination of the following strategegies
 *          for retrieving an appropriate cubin:
 *
 *          - Selected a matching one that is directly available in the __cudaFatCudaBinary.
 *          - Locate it in a resource file, or resource directory corresponding with the
 *            current executable. For this purpose, the __cudaFatCudaBinary provides a 'key' 
 *            string that can be considered as a unique name of the device code from 
 *            which __cudaFatCudaBinary was compiled.
 *          - Dynamically recompile an appropriate ptx intermediate representation for
 *            the current GPU architecture. The result of such compilation can be stored
 *            into a global CUDA compilation cache on the current computer platform.
 *           
 *          Note that the above allows for __cudaFatCudaBinaries that hold a large collection
 *          of chip specific cubins (which make the executable quite self contained),
 *          as well as completely empty __cudaFatCudaBinaries, with cubin or ptx intermediates
 *          located in resource files via the key string.
 *
 *          Note: This module needs to be completed with parameters that influence its
 *                recompilation strategy.
 */

#ifndef __cudaFatFormat_INCLUDED
#define __cudaFatFormat_INCLUDED

/*--------------------------------- Includes ---------------------------------*/



#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------- Types ----------------------------------*/

/*
 * Cubin entry type for __cudaFat binary. 
 * Cubins are specific to a particular gpu profile,
 * although the gpuInfo module might 'know'
 * that cubins will also run on other gpus.
 * Based on the recompilation strategy, 
 * fatGetCubinForGpu will return an existing
 * compatible load image, or attempt a recompilation.
 */
typedef struct {
    char*            gpuProfileName;
    char*            cubin;
} __cudaFatCubinEntry;


/*
 * Ptx entry type for __cudaFat binary.
 * PTX might use particular chip features
 * (such as double precision floating points).
 * When attempting to recompile for a certain 
 * gpu architecture, a ptx needs to be available
 * that depends on features that are either 
 * implemented by the gpu, or for which the ptx
 * translator can provide an emulation. 
 */
typedef struct {
    char*            gpuProfileName;            
    char*            ptx;
} __cudaFatPtxEntry;


/*
 * Debug entry type for __cudaFat binary.
 * Such information might, but need not be available
 * for Cubin entries (ptx files compiled in debug mode
 * will contain their own debugging information) 
 */
typedef struct __cudaFatDebugEntryRec {
    char*                   gpuProfileName;            
    char*                   debug;
    struct __cudaFatDebugEntryRec *next;
    unsigned int                   size;
} __cudaFatDebugEntry;

typedef struct __cudaFatElfEntryRec {
    char*                 gpuProfileName;            
    char*                 elf;
    struct __cudaFatElfEntryRec *next;
    unsigned int                 size;
} __cudaFatElfEntry;

typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag  = (1 << 1),
      __cudaFatSassDebugFlag  = (1 << 2)
} __cudaFatCudaBinaryFlag;


/*
 * Imported/exported symbol descriptor, needed for 
 * __cudaFat binary linking. Not much information is needed,
 * because this is only an index: full symbol information 
 * is contained by the binaries.
 */
typedef struct {
    char* name;
} __cudaFatSymbol;

/*
 * Fat binary container.
 * A mix of ptx intermediate programs and cubins,
 * plus a global identifier that can be used for 
 * further lookup in a translation cache or a resource
 * file. This key is a checksum over the device text.
 * The ptx and cubin array are each terminated with 
 * entries that have NULL components.
 */
 
typedef struct __cudaFatCudaBinaryRec {
    unsigned long            magic;
    unsigned long            version;
    unsigned long            gpuInfoVersion;
    char*                   key;
    char*                   ident;
    char*                   usageMode;
    __cudaFatPtxEntry             *ptx;
    __cudaFatCubinEntry           *cubin;
    __cudaFatDebugEntry           *debug;
    void*                  debugInfo;
    unsigned int                   flags;
    __cudaFatSymbol               *exported;
    __cudaFatSymbol               *imported;
    struct __cudaFatCudaBinaryRec *dependends;
    unsigned int                   characteristic;
    __cudaFatElfEntry             *elf;
} __cudaFatCudaBinary;


/*
 * Current version and magic numbers:
 */
#define __cudaFatVERSION   0x00000004
#define __cudaFatMAGIC     0x1ee55a01

/*
 * Version history log:
 *    1  : __cudaFatDebugEntry field added to __cudaFatCudaBinary struct
 *    2  : flags and debugInfo field added.
 *    3  : import/export symbol list
 *    4  : characteristic added, elf added
 */


/*--------------------------------- Functions --------------------------------*/

    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode,
        __cudaFatForcePTX
    } __cudaFatCompilationPolicy;

/*
 * Function        : Select a load image from the __cudaFat binary
 *                   that will run on the specified GPU.
 * Parameters      : binary  (I) Fat binary
 *                   policy  (I) Parameter influencing the selection process in case no
 *                               fully matching cubin can be found, but instead a choice can
 *                               be made between ptx compilation or selection of a
 *                               cubin for a less capable GPU.
 *                   gpuName (I) Name of target GPU
 *                   cubin   (O) Returned cubin text string, or NULL when 
 *                               no matching cubin for the specified gpu
 *                               could be found.
 *                   dbgInfo (O) If this parameter is not NULL upon entry, then
 *                               the name of a file containing debug information
 *                               on the returned cubin will be returned, or NULL 
 *                               will be returned when cubin or such debug info 
 *                               cannot be found.
 */
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );

#define fatGetCubinForGpu(binary,gpuName,cubin,dbgInfoFile) \
          fatGetCubinForGpuWithPolicy(binary,__cudaFatAvoidPTX,gpuName,cubin,dbgInfoFile)

/*
 * Function        : Check if a binary will be JITed for the specified target architecture
 * Parameters      : binary  (I) Fat binary
 *                   policy  (I) Compilation policy, as described by fatGetCubinForGpuWithPolicy
 *                   gpuName (I) Name of target GPU
 *                   ptx     (O) PTX string to be JITed. Must be freed by caller.
 * Function Result : True if the given binary will be JITed; otherwise, False
 */
unsigned char fatCheckJitForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *ptx );

#define fatCheckJitForGpu(binary,gpuName,ptx) \
          fatCheckJitForGpuWithPolicy(binary,__cudaFatAvoidPTX,gpuName,ptx)

/*
 * Function        : Free information previously obtained via function fatGetCubinForGpu.
 * Parameters      : cubin   (I) Cubin text string to free
 *                   dbgInfo (I) Debug info filename to free, or NULL
 */
void fatFreeCubin( char* cubin, char* dbgInfoFile );

/*
 * Function        : Free information previously obtained via function fatCheckJitForGpuWithPolicy.
 * Parameters      : ptx (I) PTX text string to free
 */
void __cudaFatFreePTX( char* ptx );

#ifdef __cplusplus
}
#endif

#endif

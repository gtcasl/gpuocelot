/*
 *  renderer - A simple implementation of polygon-based 3D algorithms.
 *  Copyright (C) 2004  Thanassis Tsiodras (ttsiodras@gmail.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __CUDA_RENDERER_H__
#define __CUDA_RENDERER_H__

#include <config.h>

#include "Types.h"
#include "Keyboard.h"
#include "Base3d.h"
#include "Camera.h" 
#include "BVH.h" 

// Constants

// I cannot use C++ constants for these, since I am using them to allocate
// stack arrays or shared memory in CUDA kernels.

#define MAXX		800
#define MAXY		600
#define SCREEN_DIST     (MAXY*2)

#define AMBIENT		96.f
#define DIFFUSE		128.f
#define SPECULAR	192.f

#define FOV		1024

// Maximum allowed depth of BVH
// Checked at BVH build time, no runtime crash possible, see CreateCFBVH()
#define BVH_STACK_SIZE 32

// Debugging helpers

#define DEBUG_LEVEL 0

#define DBG_PRINTF(level, fmt, ...) \
    do { if (level <= DEBUG_LEVEL) { printf(fmt, __VA_ARGS__); fflush(stdout); }} while (0)

#define DBG_PUTS(level, msg) \
    do { if (level <= DEBUG_LEVEL) { puts(msg); fflush(stdout); }} while (0)

#  define SAFE_NO_SYNC( call ) {                                     \
    cudaError_t err = call;                                                  \
    if( cudaSuccess != err) {                                               \
        fprintf(stderr, "Cuda driver error %x in file '%s' in line %i.\n",   \
                err, __FILE__, __LINE__ );                                   \
        exit(EXIT_FAILURE);                                                  \
    } }

#  define SAFE( call )       SAFE_NO_SYNC(call);

// Macro for global variables

#ifdef DEFINE_GLOBALS
#define DECLARE_DEFINE_GLOBAL(t,var,val) t var = val;
#else
#define DECLARE_DEFINE_GLOBAL(t,var,val) extern t var;
#endif

// Global variables

DECLARE_DEFINE_GLOBAL(unsigned, g_bUsePoints, false)
DECLARE_DEFINE_GLOBAL(unsigned, g_bUseSpecular, true)
DECLARE_DEFINE_GLOBAL(unsigned, g_bUsePhongInterp, true)
DECLARE_DEFINE_GLOBAL(unsigned, g_bUseReflections, true)
DECLARE_DEFINE_GLOBAL(unsigned, g_bUseShadows, true)
DECLARE_DEFINE_GLOBAL(unsigned, g_bUseAntialiasing, false)

DECLARE_DEFINE_GLOBAL(unsigned, g_verticesNo, 0)
DECLARE_DEFINE_GLOBAL(Vertex *, g_vertices, NULL)
DECLARE_DEFINE_GLOBAL(unsigned, g_trianglesNo, 0)
DECLARE_DEFINE_GLOBAL(Triangle *, g_triangles, NULL)

// The OpenGL texture for frame drawing
DECLARE_DEFINE_GLOBAL(GLuint,buffer,0);
DECLARE_DEFINE_GLOBAL(GLuint,tex,0);

// The BVH
DECLARE_DEFINE_GLOBAL(BVHNode*, g_pSceneBVH, NULL);

// the cache-friendly version of the BVH
DECLARE_DEFINE_GLOBAL(unsigned, g_triIndexListNo, 0);
DECLARE_DEFINE_GLOBAL(int*, g_triIndexList, NULL);
DECLARE_DEFINE_GLOBAL(unsigned, g_pCFBVH_No, 0);
DECLARE_DEFINE_GLOBAL(CacheFriendlyBVHNode*, g_pCFBVH, NULL);

// The gateway to CUDA, called from C++ (src/main.cpp)
void CudaRender(
    Matrix3 *pMv,
    Vertex *cudaPtrVertices, Triangle *cudaPtrTriangles, float *cudaTriangleIntersectionData,
    int *cudaTriIdxList, float *cudaBVHlimits, int *cudaBVHindexesOrTrilists,
    Vector3 *eye, Vector3 *pLightInWorldSpace,
    unsigned *cudaMortonTable);

#endif

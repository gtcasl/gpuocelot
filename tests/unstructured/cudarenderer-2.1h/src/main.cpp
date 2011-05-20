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

#include <config.h>

#ifdef _WIN32
#include <windows.h>
#include <GL/glew.h>
#include <sstream>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/glew.h>
#include <GL/gl.h>
#endif
#include <GL/glut.h>

#include <iostream>

#include <math.h>

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>

#include <SDL.h>

#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_gl_interop.h>

#define DEFINE_GLOBALS
#include "cudarenderer.h"

#include "Clock.h"
#include "Loader.h"
#include "Utility.h"

#ifndef M_PI
#define M_PI 3.14156265
#endif

using namespace std;

// The CUDA kernels will draw directly inside an OpenGL buffer (PBO)
// which will be displayed via an OpenGL texture.

// OpenGL buffer and texture helper functions

void create_buffer(GLuint* buffer)
{
    glGenBuffersARB(1, buffer);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, *buffer);
    glBufferData(GL_PIXEL_PACK_BUFFER, MAXX*MAXY*4, NULL, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
}

void destroy_buffer(GLuint* buffer)
{
    glBindBuffer(GL_TEXTURE_2D, 0);
    glDeleteBuffers(1, buffer);
    *buffer = 0;
}

void create_texture(GLuint* tex)
{
    glGenTextures(1, tex);
    glBindTexture(GL_TEXTURE_2D, *tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, MAXX, MAXY, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void destroy_texture(GLuint* tex)
{
    glBindTexture(GL_TEXTURE_2D, *tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDeleteTextures(1, tex);
}

void ModeDescription()
{
    string result;
    result += "Points(F4):"; result += g_bUsePoints?"ON,":"OFF,";
    result += " Specular(F5):"; result += g_bUseSpecular?"ON,":"OFF,";
    result += " NrmIntrp(F6):"; result += g_bUsePhongInterp?"ON,":"OFF,";
    result += " Reflect(F7):"; result += g_bUseReflections?"ON,":"OFF,";
    result += " Shadows(F8):"; result += g_bUseShadows?"ON,":"OFF,";
    result += " Antialias(F9):"; result += g_bUseAntialiasing?"ON":"OFF";
    SDL_WM_SetCaption(result.c_str(), result.c_str());
}

bool g_benchmark = false;

int main(int argc, char *argv[])
{
    bool bench = false;
    int benchFrames = 0;

    // GLUT may remove from args
    glutInit(&argc,argv);

#ifndef PACKAGE_STRING
#define PACKAGE_STRING "Renderer 2.x"
#endif

#ifndef __TIMESTAMP__
#define __TIMESTAMP__ "Unknown"
#endif
    if (argc < 2)
	panic("%s\nBuilt on: %s\nUsage: %s [-b frames] <filenameOf3dObject.ply>\n",
	    PACKAGE_STRING, __TIMESTAMP__, argv[0]);

    printf("%s\nBuilt on: %s\n", PACKAGE_STRING, __TIMESTAMP__);

    // In case we want to benchmark
    if (!strcmp(argv[1], "-b")) {
	bench = true;
	benchFrames = atoi(argv[2]);
    }

    float maxi = load_object(argv[argc-1]);

    UpdateBoundingVolumeHierarchy(argv[argc-1]);

    // SDL startup

    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
        panic("Couldn't initialize SDL: %s\n", SDL_GetError());
    atexit(SDL_Quit); // Clean up on exit
    if (!SDL_SetVideoMode( MAXX, MAXY, 0, SDL_OPENGL))
        panic("Couldn't set video mode: %s\n", SDL_GetError());
    // Ignore mice, we love keyboards
    SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);

    // OpenGL startup

    // We need an OpenGL PBO...
    cout << "Loading extensions: " << glewGetErrorString(glewInit()) << endl;
    if (!glewIsSupported( "GL_VERSION_1_5 GL_ARB_pixel_buffer_object" ))
	panic("Missing GL_ARB_pixel_buffer_object\n");

    glViewport(0, 0, MAXX, MAXY);
    glClearColor(0.3f, 0.3f, 0.3f, 0.5f);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();

    create_buffer(&buffer);
    create_texture(&tex);
    SAFE( cudaGLRegisterBufferObject(buffer) ); // Tell CUDA about the PBO

    // Now, allocate the CUDA side of the data (in CUDA global memory,
    // in preparation for the textures that will store them...)

    Vertex *cudaVertices;
    Triangle *cudaTriangles;

    float *pVerticesData = (float*)malloc(g_verticesNo*8*sizeof(float));
    for(unsigned f=0; f<g_verticesNo; f++) {
	// Texture-wise:
	//
	// first float4
	pVerticesData[f*8+0]=g_vertices[f]._x;
	pVerticesData[f*8+1]=g_vertices[f]._y;
	pVerticesData[f*8+2]=g_vertices[f]._z;
	pVerticesData[f*8+3]=g_vertices[f]._ambientOcclusionCoeff;
	// second float4
	pVerticesData[f*8+4]=g_vertices[f]._normal._x;
	pVerticesData[f*8+5]=g_vertices[f]._normal._y;
	pVerticesData[f*8+6]=g_vertices[f]._normal._z;
	pVerticesData[f*8+7]=0.f;
    }
    SAFE( cudaMalloc((void**)&cudaVertices, g_verticesNo*8*sizeof(float)) );
    SAFE( cudaMemcpy(cudaVertices, pVerticesData, g_verticesNo*8*sizeof(float), cudaMemcpyHostToDevice) );

    float *pTrianglesIntersectionData = (float *)malloc(g_trianglesNo*20*sizeof(float));
    for(unsigned e=0; e<g_trianglesNo; e++) {
	// Texture-wise:
	//
	// first float4
	pTrianglesIntersectionData[20*e+0]  = g_triangles[e]._center._x;
	pTrianglesIntersectionData[20*e+1]  = g_triangles[e]._center._y;
	pTrianglesIntersectionData[20*e+2]  = g_triangles[e]._center._z;
	pTrianglesIntersectionData[20*e+3]  = g_triangles[e]._twoSided?1.0f:0.0f;
	// second float4
	pTrianglesIntersectionData[20*e+4]  = g_triangles[e]._normal._x;
	pTrianglesIntersectionData[20*e+5]  = g_triangles[e]._normal._y;
	pTrianglesIntersectionData[20*e+6]  = g_triangles[e]._normal._z;
	pTrianglesIntersectionData[20*e+7]  = g_triangles[e]._d;
	// third float4
	pTrianglesIntersectionData[20*e+8]  = g_triangles[e]._e1._x;
	pTrianglesIntersectionData[20*e+9]  = g_triangles[e]._e1._y;
	pTrianglesIntersectionData[20*e+10] = g_triangles[e]._e1._z;
	pTrianglesIntersectionData[20*e+11] = g_triangles[e]._d1;
	// fourth float4
	pTrianglesIntersectionData[20*e+12] = g_triangles[e]._e2._x;
	pTrianglesIntersectionData[20*e+13] = g_triangles[e]._e2._y;
	pTrianglesIntersectionData[20*e+14] = g_triangles[e]._e2._z;
	pTrianglesIntersectionData[20*e+15] = g_triangles[e]._d2;
	// fifth float4
	pTrianglesIntersectionData[20*e+16] = g_triangles[e]._e3._x;
	pTrianglesIntersectionData[20*e+17] = g_triangles[e]._e3._y;
	pTrianglesIntersectionData[20*e+18] = g_triangles[e]._e3._z;
	pTrianglesIntersectionData[20*e+19] = g_triangles[e]._d3;
    }
    float *cudaTriangleIntersectionData;
    SAFE( cudaMalloc((void**)&cudaTriangleIntersectionData, g_trianglesNo*20*sizeof(float)) );
    SAFE( cudaMemcpy(cudaTriangleIntersectionData, pTrianglesIntersectionData, g_trianglesNo*20*sizeof(float), cudaMemcpyHostToDevice) );

    SAFE( cudaMalloc((void**)&cudaTriangles, g_trianglesNo*sizeof(Triangle)) );
    SAFE( cudaMemcpy(cudaTriangles, g_triangles, g_trianglesNo*sizeof(Triangle), cudaMemcpyHostToDevice) );
    SAFE( cudaMemcpyToSymbol("VERTICES", &g_verticesNo, sizeof(int)) );
    SAFE( cudaMemcpyToSymbol("TRIANGLES", &g_trianglesNo, sizeof(int)) );

    float angle1=0.0f;
    float angle2=0.0f;
    float angle3=45.0f*M_PI/180.f;
    const coord EyeDistanceFactor = 4.0;
    const coord LightDistanceFactor = 4.0;

    Vector3 light(LightDistanceFactor*maxi, LightDistanceFactor*maxi, LightDistanceFactor*maxi);
    Vector3 *pLight = &light;

    int framesDrawn = 0;
    bool autoRotate = true;

    Keyboard keys;
    Vector3 eye(maxi*EyeDistanceFactor, 0.0, 0.0);
    Vector3 lookat(eye._x + 1.0f*cos(angle2)*cos(angle1),
		 eye._y + 1.0f*cos(angle2)*sin(angle1),
		 eye._z + 1.0f*sin(angle2));

    Camera sony(eye, lookat);

    Clock watch;

#define DEGREES_TO_RADIANS(x) ((coord)((x)*M_PI/180.0))
    coord dAngle = DEGREES_TO_RADIANS(0.3f);

    keys.poll();

    // Allocate CUDA-side data (global memory) for positions and transformations matrices
    Matrix3 *cudaSony = NULL;
    SAFE( cudaMalloc((void**)&cudaSony, sizeof(sony._mv)) );
    Vector3 *cudaEye = NULL;
    SAFE( cudaMalloc((void**)&cudaEye, sizeof(Vector3)) );
    Vector3 *cudaLightInWorldSpace = NULL;
    SAFE( cudaMalloc((void**)&cudaLightInWorldSpace, sizeof(Vector3)) );

    // Allocate CUDA-side data (global memory for corresponding textures) for Bounding Volume Hierarchy data
    // See BVH.h for the data we are storing (from CacheFriendlyBVHNode)
    //
    // Leaf nodes triangle lists (indices to global triangle list)
    int *cudaTriIdxList = NULL;
    SAFE( cudaMalloc((void**)&cudaTriIdxList, g_triIndexListNo*sizeof(int)) );
    SAFE( cudaMemcpy(cudaTriIdxList, g_triIndexList, g_triIndexListNo*sizeof(int), cudaMemcpyHostToDevice) );

    // Bounding box checks need bottom._x,top._x,bottom._y,top._y,bottom._z,top._z...
    float *pLimits = (float *)malloc(g_pCFBVH_No*6*sizeof(float));
    for(unsigned h=0; h<g_pCFBVH_No; h++) {
	// Texture-wise:
	//
	// First float2
	pLimits[6*h+0] = g_pCFBVH[h]._bottom._x;
	pLimits[6*h+1] = g_pCFBVH[h]._top._x;
	// Second float2
	pLimits[6*h+2] = g_pCFBVH[h]._bottom._y;
	pLimits[6*h+3] = g_pCFBVH[h]._top._y;
	// Third float2
	pLimits[6*h+4] = g_pCFBVH[h]._bottom._z;
	pLimits[6*h+5] = g_pCFBVH[h]._top._z;
    }
    float *cudaBVHlimits = NULL;
    SAFE( cudaMalloc((void**)&cudaBVHlimits, g_pCFBVH_No*6*sizeof(float)) );
    SAFE( cudaMemcpy(cudaBVHlimits, pLimits, g_pCFBVH_No*6*sizeof(float), cudaMemcpyHostToDevice) );

    // ..and finally, from CacheFriendlyBVHNode, the 4 integer values:
    int *pIndexesOrTrilists = (int *)malloc(g_pCFBVH_No*4*sizeof(unsigned));
    for(unsigned g=0; g<g_pCFBVH_No; g++) {
	// Texture-wise:
	//
	// A single uint4
	pIndexesOrTrilists[4*g+0] = g_pCFBVH[g].u.leaf._count;
	pIndexesOrTrilists[4*g+1] = g_pCFBVH[g].u.inner._idxRight;
	pIndexesOrTrilists[4*g+2] = g_pCFBVH[g].u.inner._idxLeft;
	pIndexesOrTrilists[4*g+3] = g_pCFBVH[g].u.leaf._startIndexInTriIndexList;
    }
    int *cudaBVHindexesOrTrilists = NULL;
    SAFE( cudaMalloc((void**)&cudaBVHindexesOrTrilists, g_pCFBVH_No*4*sizeof(unsigned)) );
    SAFE( cudaMemcpy(cudaBVHindexesOrTrilists, pIndexesOrTrilists, g_pCFBVH_No*4*sizeof(unsigned), cudaMemcpyHostToDevice) );

    // Allocate and calculate CUDA-side data (global memory) for Morton-order table
    //
    unsigned *cudaMortonTable = NULL;
    SAFE( cudaMalloc((void**)&cudaMortonTable, MAXX*MAXY*sizeof(unsigned)) );
    unsigned *pMortonTable = (unsigned *)malloc(MAXX*MAXY*sizeof(unsigned));
    // Final largest dimension
    unsigned maxDim = MAXX;
    if (maxDim<MAXY) maxDim = MAXY;
    // Find minimum power of two >= maxDim
    maxDim--;
    maxDim |= maxDim >> 1;
    maxDim |= maxDim >> 2;
    maxDim |= maxDim >> 4;
    maxDim |= maxDim >> 8;
    maxDim |= maxDim >> 16;
    maxDim++;
    // Build morton table for our pixels
    int ofs = 0;
    for(unsigned work=0; work<maxDim*maxDim; work++) {
	unsigned topBit = 0x80000000;
	unsigned w = work;
	int x=0, y=0;
	for(unsigned i=0; i<32; i+=2) {
	    y = (y<<1) | ((w&topBit)?1:0);
	    w<<=1;
	    x = (x<<1) | ((w&topBit)?1:0);
	    w<<=1;
	}
	if (x>=0 && y>=0 && x<MAXX && y<MAXY) {
	    unsigned value = x | (y<<16);
	    pMortonTable[ofs++] = value;
	    if (ofs == MAXX*MAXY)
		break;
	}
    }
    SAFE( cudaMemcpy(cudaMortonTable, pMortonTable, ofs*sizeof(unsigned), cudaMemcpyHostToDevice) );

    //
    // Game time...
    //

    pLight->_x = LightDistanceFactor*maxi*cos(angle3);
    pLight->_y = LightDistanceFactor*maxi*sin(angle3);

    g_benchmark = bench;

    ModeDescription();
    watch.reset();
    while(!keys.Abort()) {
	framesDrawn++;
	if (bench && framesDrawn>benchFrames)
	    break;
	if (!bench) {
	    // Only allow keyboard control if we are not benchmarking
	    if (keys.Left())
		angle1-=dAngle;
	    if (keys.Right())
		angle1+=dAngle;
	    if (keys.Up())
		angle2=min(angle2+dAngle, DEGREES_TO_RADIANS(89.0f));
	    if (keys.Down())
		angle2=max(angle2-dAngle, DEGREES_TO_RADIANS(-89.0f));
	    if (keys.Forward() || keys.Backward()) {
		Vector3 fromEyeToLookat(lookat);
		fromEyeToLookat -= eye;
		if (autoRotate)
		    fromEyeToLookat *= 0.05f;
		else
		    fromEyeToLookat *= 0.05f*maxi;
		/*
		cout << "At " << eye._x << " " << eye._y << " " << eye._z << endl;
		cout << "Looking at " << lookat._x << " " << lookat._y << " " << lookat._z << endl;
		cout << "Adding " << fromEyeToLookat._x << " " << fromEyeToLookat._y << " " << fromEyeToLookat._z << endl;
		*/
		if (keys.Forward())
		    eye += fromEyeToLookat;
		else
		    eye -= fromEyeToLookat;
	    }
	    if (keys.isF4()) {
		watch.reset(); framesDrawn = 1;
		while (keys.isF4()) keys.poll(); g_bUsePoints       = !g_bUsePoints;       ModeDescription(); }
	    if (keys.isF5()) {
		watch.reset(); framesDrawn = 1;
		while (keys.isF5()) keys.poll(); g_bUseSpecular     = !g_bUseSpecular;     ModeDescription(); }
	    if (keys.isF6()) {
		watch.reset(); framesDrawn = 1;
		while (keys.isF6()) keys.poll(); g_bUsePhongInterp  = !g_bUsePhongInterp;  ModeDescription(); }
	    if (keys.isF7()) {
		watch.reset(); framesDrawn = 1;
		while (keys.isF7()) keys.poll(); g_bUseReflections  = !g_bUseReflections;  ModeDescription(); }
	    if (keys.isF8()) {
		watch.reset(); framesDrawn = 1;
		while (keys.isF8()) keys.poll(); g_bUseShadows      = !g_bUseShadows;      ModeDescription(); }
	    if (keys.isF9()) {
		watch.reset(); framesDrawn = 1;
		while (keys.isF9()) keys.poll(); g_bUseAntialiasing = !g_bUseAntialiasing; ModeDescription(); }

	    if (keys.isS() || keys.isF() || keys.isE() || keys.isD()) {
		Vector3 eyeToLookatPoint = lookat;
		eyeToLookatPoint -= eye;
		eyeToLookatPoint.normalize();
		Vector3 zenith(0., 0., 1.);
		Vector3 rightAxis = cross(eyeToLookatPoint, zenith);
		rightAxis.normalize();
		Vector3 upAxis = cross(rightAxis, eyeToLookatPoint);
		upAxis.normalize();
		if (keys.isS()) { rightAxis *= 0.05f*maxi; eye -= rightAxis; }
		if (keys.isF()) { rightAxis *= 0.05f*maxi; eye += rightAxis; }
		if (keys.isD()) { upAxis *= 0.05f*maxi; eye -= upAxis; }
		if (keys.isE()) { upAxis *= 0.05f*maxi; eye += upAxis; }
	    }
	    if (keys.isR()) {
		while(keys.isR())
		    keys.poll();
		autoRotate = !autoRotate;
		if (!autoRotate) {
		    Vector3 eyeToAxes = eye;
		    eyeToAxes.normalize();
#if defined(__GNUC__)
		    // Hideous GCC code generation bug - unless I print them, eyeToAxes are not normalized!
		    cout << "Moving to " << eyeToAxes._x << "," <<
			eyeToAxes._y << "," << eyeToAxes._z << endl;
#endif
		    angle2 = asin(-eyeToAxes._z);
		    angle1 = (eye._y<0)?acos(eyeToAxes._x/cos(angle2)):-acos(eyeToAxes._x/cos(angle2));
		} else {
		    angle1 = -angle1;
		    angle2 = -angle2;
		}
		watch.reset();
		framesDrawn = 1;
	    }
	    if (keys.Light()) {
		angle3 += 4*dAngle;
		pLight->_x = LightDistanceFactor*maxi*cos(angle3);
		pLight->_y = LightDistanceFactor*maxi*sin(angle3);
	    }
	    if (keys.Light2()) {
		angle3 -= 4*dAngle;
		pLight->_x = LightDistanceFactor*maxi*cos(angle3);
		pLight->_y = LightDistanceFactor*maxi*sin(angle3);
	    }
	    if (keys.isH()) {
		while(keys.isH()) keys.poll();
		glClear(GL_COLOR_BUFFER_BIT);
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glColor3f(1.f, 1.f, 1.f);
		const char *help =
		    "KEYS: (available only when not benchmarking)\n"
		    "\n"
		    "- Hit 'R' to stop/start auto-rotation of the camera around the object.\n"
		    "- Fly using the cursor keys,A,Z - and rotate the light with W and Q.\n"
		    "- S and F are 'strafe' left/right\n"
		    "- E and D are 'strafe' up/down\n"
		    "  (strafe keys don't work in auto-rotation mode).\n"
		    "- F4 toggles points mode\n"
		    "- F5 toggles specular lighting\n"
		    "- F6 toggles phong normal interpolation\n"
		    "- F7 toggles reflections\n"
		    "- F8 toggles shadows\n"
		    "- F9 toggles anti-aliasing\n"
		    "- ESC quits.\n\n"
		    "Now press H to get out of this help screen\n";

		glRasterPos2f(-0.95, 0.9);
		int lines = 0;
		for(const char *p=help; *p; p++) {
		    if (*p == '\n')
			// 12 point helvetica => 12+3=15 points per line
			glRasterPos2f(-0.95, 0.9 - ((12+3)*2.f/MAXY)*lines++);
		    else
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p);
		}
		SDL_GL_SwapBuffers();
		while(!keys.isH() && !keys.Abort()) keys.poll();
		while(keys.isH() || keys.Abort()) keys.poll();
		framesDrawn = 1;
		watch.reset();
	    }
	}
	if (!autoRotate) {
	    lookat._x = eye._x - 1.0f*cos(angle2)*cos(angle1);
	    lookat._y = eye._y + 1.0f*cos(angle2)*sin(angle1);
	    lookat._z = eye._z + 1.0f*sin(angle2);
	} else {
	    angle1-=dAngle;
	    lookat._x = 0;
	    lookat._y = 0;
	    lookat._z = 0;
	    coord distance = sqrt(eye._x*eye._x + eye._y*eye._y + eye._z*eye._z);
	    eye._x = distance*cos(angle2)*cos(angle1);
	    eye._y = distance*cos(angle2)*sin(angle1);
	    eye._z = distance*sin(angle2);
	}

	sony.set(eye, lookat);

	// Update the CUDA side of the eye/light positions and x-form matrix
	SAFE( cudaMemcpy(cudaEye, (Vector3*)&sony, sizeof(Vector3), cudaMemcpyHostToDevice) );
	SAFE( cudaMemcpy(cudaLightInWorldSpace, pLight, sizeof(Vector3), cudaMemcpyHostToDevice) );
	SAFE( cudaMemcpy(cudaSony, &sony._mv, sizeof(sony._mv), cudaMemcpyHostToDevice) );

	// ...and render!
	CudaRender(
	    cudaSony,
	    cudaVertices, cudaTriangles, cudaTriangleIntersectionData,
	    cudaTriIdxList, cudaBVHlimits, cudaBVHindexesOrTrilists,
	    cudaEye, cudaLightInWorldSpace,
	    cudaMortonTable);

	keys.poll();

	// The more frames per sec, the smaller the dAngle should be
	// The less frames per sec, the larger  the dAngle should be
	//   so...
	// Move dAngle towards 36/framesPerSec in 15 frames (steps)
	//   for 100fps, dAngle = 0.36
	//   for 10 fps, dAngle = 3.6
	// In both cases, we rotate 360 degrees in 10 seconds
	//dAngle += ((36.0/(framesDrawn/(watch.readMS()/1000.0)))-dAngle)/15.;
	//
	// Changed to 18/framesPerSec (20 seconds needed for a 360 rotation)
	dAngle += (DEGREES_TO_RADIANS(9.0f/(framesDrawn/(watch.readMS()/1000.0f)))-dAngle)/15.0f;
    }
    framesDrawn--;

#ifdef _WIN32
    stringstream speed;
    speed << "Rendering " << framesDrawn << " frames in " << (watch.readMS()/1000.0) << " seconds. (" << framesDrawn/(watch.readMS()/1000.0) << " fps)\n";
    MessageBoxA(0, (LPCSTR) speed.str().c_str(), (const char *)"Speed of rendering", MB_OK);
#else
    cout << "Rendering " << framesDrawn << " frames in ";
    cout << (watch.readMS()/1000.0) << " seconds. (";
    cout << framesDrawn/(watch.readMS()/1000.0) << " fps)\n";
#endif

    SAFE(cudaFree(cudaMortonTable));
    SAFE(cudaFree(cudaBVHindexesOrTrilists));
    SAFE(cudaFree(cudaBVHlimits));
    SAFE(cudaFree(cudaTriIdxList));
    SAFE(cudaFree(cudaLightInWorldSpace));
    SAFE(cudaFree(cudaEye));
    SAFE(cudaFree(cudaSony));
    SAFE(cudaFree(cudaTriangles));
    SAFE(cudaFree(cudaTriangleIntersectionData));
    SAFE(cudaFree(cudaVertices));
    SAFE(cudaGLUnregisterBufferObject(buffer));
    destroy_texture(&tex);
    destroy_buffer(&buffer);

    cudaThreadExit();

    return 0;
}

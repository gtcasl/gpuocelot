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

#ifdef _WIN32
#include <windows.h>
#include <GL/glew.h>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#endif
#include <GL/glut.h>

#include <SDL.h>

#include <cstdio>
#include <cfloat>

#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_gl_interop.h>
#include <vector_types.h>

#include "Types.h"
#include "Base3d.h"
#include "Camera.h"

#include "cudarenderer.h"

/////////////////////////////////
// Raytracing configuration
#define THREADS_PER_BLOCK   64

// What depth to stop reflections and refractions?
#define MAX_RAY_DEPTH	    2

// Ray intersections of a distance <=NUDGE_FACTOR (from the origin) don't count
#define NUDGE_FACTOR     1e-5f

// How much the reflected color contributes to the overall
#define REFLECTIONS_RATE 0.375f

//////////////////////////////
// Enable ambient occlusion?
//#define AMBIENT_OCCLUSION
// How many ambient rays to spawn per ray intersection?
#define AMBIENT_SAMPLES  32
// How close to check for ambient occlusion?
#define AMBIENT_RANGE    0.15f

__constant__ unsigned VERTICES;
__constant__ unsigned TRIANGLES;

// Textures for vertices, triangles and BVH data
// (see CudaRender() below, as well as main() to see the data setup process)
texture<uint1, 1, cudaReadModeElementType> g_triIdxListTexture;
texture<float2, 1, cudaReadModeElementType> g_pCFBVHlimitsTexture;
texture<uint4, 1, cudaReadModeElementType> g_pCFBVHindexesOrTrilistsTexture;
texture<float4, 1, cudaReadModeElementType> g_verticesTexture;
texture<float4, 1, cudaReadModeElementType> g_trianglesTexture;

// Utility functions

// CUDA dot product
__device__ coord dotCUDA(const Vector3& l, const Vector3& r)
{
    return l._x*r._x +l._y*r._y +l._z*r._z;
}

__device__ coord dotCUDA(const float4& l, const Vector3& r)
{
    return l.x*r._x +l.y*r._y +l.z*r._z;
}

__device__ coord dotCUDA(const Vector3& l, const float4& r)
{
    return l._x*r.x +l._y*r.y +l._z*r.z;
}

// CUDA cross
__device__ Vector3 crossCUDA(const Vector3& l, const Vector3& r)
{
    coord x,y,z;
    const coord &aax=l._x;
    const coord &aay=l._y;
    const coord &aaz=l._z;
    const coord &bbx=r._x;
    const coord &bby=r._y;
    const coord &bbz=r._z;
    x=aay*bbz-bby*aaz;
    y=bbx*aaz-aax*bbz;
    z=aax*bby-aay*bbx;
    return Vector3(x,y,z);
}

// CUDA distance of two points
__device__ coord distanceCUDA(const Vector3& a, const Vector3& b)
{
    coord dx=a._x - b._x;
    coord dy=a._y - b._y;
    coord dz=a._z - b._z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Sometime you just want to compare, so no sqrt is needed
__device__ coord distancesqCUDA(const Vector3& a, const Vector3& b)
{
    coord dx=a._x - b._x;
    coord dy=a._y - b._y;
    coord dz=a._z - b._z;
    return dx*dx + dy*dy + dz*dz;
}

// Matrix3x3 multipled by Vector3
__device__ Vector3 multiplyRightWith(const Matrix3& mv, const Vector3& r)
{
    coord xnew = mv._row1._x*r._x + mv._row1._y*r._y + mv._row1._z*r._z;
    coord ynew = mv._row2._x*r._x + mv._row2._y*r._y + mv._row2._z*r._z;
    coord znew = mv._row3._x*r._x + mv._row3._y*r._y + mv._row3._z*r._z;
    return Vector3(xnew, ynew, znew);
}

// Transform Vector3 to any space, given Matrix3 and origin
__device__ Vector3 inline TransformToSomeSpace(Vector3 point, Matrix3 *mv, Vector3 *origin)
{
    point -= *origin;
    return multiplyRightWith(*mv, point);
}

// After transformation in camera space, project and plot (used for point rendering)
#define CLIPPLANEDISTANCE 0.2f

__device__ void inline ProjectAndPlot(const Vector3& xformed, int *pixels, int defaultColor=0x00FFFFFF )
{
    if (xformed._z>CLIPPLANEDISTANCE) {
	int x = (int)(MAXX/2.f  + FOV * xformed._y/xformed._z);
	int y = (int)(MAXY/2.f - FOV * xformed._x/xformed._z);
	if (y>=0.f && y<(int)MAXY && x>=0.f && x<(int)MAXX)
	    pixels[y*MAXX + x] = defaultColor;
    }
}

////////////////////////////////////////
// Rendering kernel for MODE_POINTS
////////////////////////////////////////

__global__ void CoreLoopVertices(int *pixels, Matrix3 *cudaWorldToCameraSpace, Vector3 *eye)
{
    unsigned idx = blockIdx.x*blockDim.x + threadIdx.x;

    if (idx >= VERTICES)
	return;

    // Simple projection and ploting of a white point per vertex

    // Plot projected coordinates (on screen)
    Vector3 v(tex1Dfetch(g_verticesTexture, 2*idx));
    ProjectAndPlot(
	TransformToSomeSpace(v, cudaWorldToCameraSpace, eye),
	pixels);
}

//////////////////////////////////////////////
// Rendering kernel for MODE_POINTSHIDDEN
//////////////////////////////////////////////

// Create OpenGL BGR value for assignment in PBO buffer
__device__ int getColor(Pixel& p)
{
    return (((unsigned)p._b) << 16) | (((unsigned)p._g) << 8) | (((unsigned)p._r));
}

__global__ void CoreLoopTriangles(int *pixels, Matrix3 *cudaWorldToCameraSpace, Triangle *pTriangles, Vector3 *eye)
{
    unsigned idx = blockIdx.x*blockDim.x + threadIdx.x;

    if (idx >= TRIANGLES)
	return;

    // First check if the triangle is visible from where we stand
    // (closed objects only)

    float4 center = tex1Dfetch(g_trianglesTexture, 5*idx);
    float4 normal = tex1Dfetch(g_trianglesTexture, 5*idx+1);

    Vector3 triToEye = *eye;
    triToEye -= center;
    // Normally we would normalize, but since we just need the sign
    // of the dot product (to determine if it facing us or not)...
    //triToEye.normalize();
    //if (!pTriangles[idx]._twoSided && dotCUDA(triToEye, pTriangles[idx]._normal)<0.f)
    if (center.w == 0.f && dotCUDA(triToEye, normal)<0.f)
	return;

    int color = getColor(pTriangles[idx]._colorf);

    // For each of the 3 vertices of triangle j of object i,
    // transform to camera space, project and plot them
    Vector3 v1(tex1Dfetch(g_verticesTexture, 2*pTriangles[idx]._idx1));
    Vector3 v2(tex1Dfetch(g_verticesTexture, 2*pTriangles[idx]._idx2));
    Vector3 v3(tex1Dfetch(g_verticesTexture, 2*pTriangles[idx]._idx3));
    ProjectAndPlot( TransformToSomeSpace(v1, cudaWorldToCameraSpace, eye), pixels, color);
    ProjectAndPlot( TransformToSomeSpace(v2, cudaWorldToCameraSpace, eye), pixels, color);
    ProjectAndPlot( TransformToSomeSpace(v3, cudaWorldToCameraSpace, eye), pixels, color);
}

///////////////////////////////////////////////
// Raytracing modes
///////////////////////////////////////////////

// Helper function, that checks whether a ray intersects a bbox
__device__ bool RayIntersectsBox(
    const Vector3& originInWorldSpace, const Vector3& rayInWorldSpace, int boxIdx)
{
    // set Tnear = - infinity, Tfar = infinity
    //
    // For each pair of planes P associated with X, Y, and Z do:
    //     (example using X planes)
    //     if direction Xd = 0 then the ray is parallel to the X planes, so
    //         if origin Xo is not between the slabs ( Xo < Xl or Xo > Xh) then
    //             return false
    //     else, if the ray is not parallel to the plane then
    //     begin
    //         compute the intersection distance of the planes
    //         T1 = (Xl - Xo) / Xd
    //         T2 = (Xh - Xo) / Xd
    //         If T1 > T2 swap (T1, T2) /* since T1 intersection with near plane */
    //         If T1 > Tnear set Tnear =T1 /* want largest Tnear */
    //         If T2 < Tfar set Tfar="T2" /* want smallest Tfar */
    //         If Tnear > Tfar box is missed so
    //             return false
    //         If Tfar < 0 box is behind ray
    //             return false
    //     end
    // end of for loop
    //
    // If Box survived all above tests, return true with intersection point Tnear and exit point Tfar.

    coord Tnear, Tfar;
    Tnear = -FLT_MAX;
    Tfar = FLT_MAX;

    float2 limits;

#define CHECK_NEAR_AND_FAR_INTERSECTION(c)							    \
    if (rayInWorldSpace._ ## c == 0.f) {							    \
	if (originInWorldSpace._##c < limits.x) return false;					    \
	if (originInWorldSpace._##c > limits.y) return false;					    \
    } else {											    \
	coord T1 = (limits.x - originInWorldSpace._##c)/rayInWorldSpace._##c;			    \
	coord T2 = (limits.y - originInWorldSpace._##c)/rayInWorldSpace._##c;			    \
	if (T1>T2) { coord tmp=T1; T1=T2; T2=tmp; }						    \
	if (T1 > Tnear) Tnear = T1;								    \
	if (T2 < Tfar)  Tfar = T2;								    \
	if (Tnear > Tfar)									    \
	    return false;									    \
	if (Tfar < 0.f)										    \
	    return false;									    \
    }

    limits = tex1Dfetch(g_pCFBVHlimitsTexture, 3*boxIdx); // box.bottom._x/top._x placed in limits.x/limits.y
    CHECK_NEAR_AND_FAR_INTERSECTION(x)
    limits = tex1Dfetch(g_pCFBVHlimitsTexture, 3*boxIdx+1); // box.bottom._y/top._y placed in limits.x/limits.y
    CHECK_NEAR_AND_FAR_INTERSECTION(y)
    limits = tex1Dfetch(g_pCFBVHlimitsTexture, 3*boxIdx+2); // box.bottom._z/top._z placed in limits.x/limits.y
    CHECK_NEAR_AND_FAR_INTERSECTION(z)

    return true;
}

// Templated ray/triangle intersection function - offers two compile-time options:
//
// The first one is used to discriminate between shadow rays (that stop at the first hit)
// and normal rays, that have to find the closest hit.
//
// The second one enables or disables culling of backfacing triangles, and is...
// (a) enabled for the refraction call (which needs both front and back-faces), but
// (b) disabled for reflections and shadow rays.
//
// C++ compile-time power... all lesser languages bow down... :-)
//
template <bool stopAtfirstRayHit, bool doCulling>
__device__ bool BVH_IntersectTriangles(
    // Inputs
    //Triangle *pTriangles,
    const Vector3& origin, const Vector3& ray, unsigned avoidSelf,
    // outputs
    int& pBestTriIdx,
    //
    // both inputs and outputs!
    //
    // for normal rays:
    //  pointHitInWorldSpace (output)
    //  kXX (outputs) perpendicular distances of intersection point from the 3 triangle edges
    //     (used for PhongNormal calculations)
    //
    // for shadow rays:
    //  pointHitInWorldSpace (input) provides the light position
    Vector3& pointHitInWorldSpace,
    coord& kAB, coord& kBC, coord& kCA)
{
    // in the loop below, maintain the closest triangle and the point where we hit it:
    pBestTriIdx = -1;
    coord bestTriDist;

    // light position passed-in pointHitInWorldSpace (only in shadow mode - i.e. stopAtfirstRayHit=true)
    Vector3& lightPos = pointHitInWorldSpace;

    // Compile-time work (stopAtfirstRayHit is template param)
    if (stopAtfirstRayHit)
	// In shadow ray mode, start from light distance
	bestTriDist = distancesqCUDA(origin, lightPos);
    else
	// In normal mode, start from infinity
	bestTriDist = FLT_MAX;

    int stack[BVH_STACK_SIZE];
    int stackIdx = 0;
    stack[stackIdx++] = 0;
    while(stackIdx) {
	int boxIdx = stack[stackIdx-1];
	//CacheFriendlyBVHNode *pCurrent = &cudaBVHNodes[boxIdx];
	stackIdx--;

	uint4 data = tex1Dfetch(g_pCFBVHindexesOrTrilistsTexture, boxIdx);

	// original, "pure" BVH form...
	//if (!pCurrent->IsLeaf()) {

	// cache-friendly BVH form...
	//if (!(pCurrent->u.leaf._count & 0x80000000)) {

	// textured BVH form...
	if (!(data.x & 0x80000000)) {
	    if (RayIntersectsBox(origin, ray, boxIdx)) {
		//stack[stackIdx++] = pCurrent->u.inner._idxRight;
		stack[stackIdx++] = data.y;
		//stack[stackIdx++] = pCurrent->u.inner._idxLeft;
		stack[stackIdx++] = data.z;
		if(stackIdx>BVH_STACK_SIZE)
		{
		    return false; // XXX
		}
	    }
	} else {
	    // original, "pure" BVH form...
	    //BVHLeaf *p = dynamic_cast<BVHLeaf*>(pCurrent);
	    //for(std::list<const Triangle*>::iterator it=p->_triangles.begin();
	    //    it != p->_triangles.end();
	    //    it++)

	    // cache-friendly BVH form...
	    //for(unsigned i=pCurrent->u.leaf._startIndexInTriIndexList;
	    //    i<pCurrent->u.leaf._startIndexInTriIndexList + (pCurrent->u.leaf._count & 0x7fffffff);

	    // textured BVH form...
	    for(unsigned i=data.w; i<data.w + (data.x & 0x7fffffff); i++) {
		// original, "pure" BVH form...
		//const Triangle& triangle = *(*it);

		// cache-friendly BVH form...
		//const Triangle& triangle = pTriangles[cudaTriIdxList[i]];

		// textured BVH form...
		int idx = tex1Dfetch(g_triIdxListTexture, i).x;

		if (avoidSelf == idx)
		    continue; // avoid self-reflections/refractions

		float4 center = tex1Dfetch(g_trianglesTexture, 5*idx);
		float4 normal = tex1Dfetch(g_trianglesTexture, 5*idx+1);

		// doCulling is a compile-time param, this code will be "codegenerated"
		// at compile time only for reflection-related calls to Raytrace (see below)
		//if (doCulling && !triangle._twoSided) {
		if (doCulling && (center.w == 0.f)) { // template-param, compile-time check
		    // Check visibility of triangle via dot product
		    Vector3 fromTriToOrigin = origin;
		    //fromTriToOrigin -= triangle._center;
		    fromTriToOrigin -= center;
		    // Normally we would normalize, but since we just need the sign
		    // of the dot product (to determine if it facing us or not)...
		    //fromTriToOrigin.normalize();
		    if (dotCUDA(fromTriToOrigin, normal)<0)
			continue;
		}

		// Use the pre-computed triangle intersection data: normal, d, e1/d1, e2/d2, e3/d3
		coord k = dotCUDA(normal, ray);
		if (k == 0.0f)
		    continue; // this triangle is parallel to the ray, ignore it.

		coord s = (normal.w - dotCUDA(normal, origin))/k;
		if (s <= 0.0f) // this triangle is "behind" the origin.
		    continue;
		if (s <= NUDGE_FACTOR)
		    continue;
		Vector3 hit = ray*s;
		hit += origin;

		// Is the intersection of the ray with the triangle's plane INSIDE the triangle?
		float4 ee1 = tex1Dfetch(g_trianglesTexture, 5*idx+2);
		coord kt1 = dotCUDA(ee1, hit) - ee1.w; if (kt1<0.0f) continue;
		float4 ee2 = tex1Dfetch(g_trianglesTexture, 5*idx+3);
		coord kt2 = dotCUDA(ee2, hit) - ee2.w; if (kt2<0.0f) continue;
		float4 ee3 = tex1Dfetch(g_trianglesTexture, 5*idx+4);
		coord kt3 = dotCUDA(ee3, hit) - ee3.w; if (kt3<0.0f) continue;

		// It is, "hit" is the world space coordinate of the intersection.

		// Was this a normal ray or a shadow ray? (template param)
		if (stopAtfirstRayHit) {
		    // Shadow ray, check whether the triangle obstructs the light
		    coord dist = distancesqCUDA(lightPos, hit);
		    if (dist < bestTriDist) // distance to light (squared) passed in kAB
			return true; // we found a triangle obstructing the light, return true
		} else {
		    // Normal ray - it this intersection closer than all the others?
		    coord hitZ = distancesqCUDA(origin, hit);
		    if (hitZ < bestTriDist) {
			// maintain the closest hit
			bestTriDist = hitZ;
			pBestTriIdx = idx;
			pointHitInWorldSpace = hit;
			kAB = kt1;
			kBC = kt2;
			kCA = kt3;
		    }
		}
	    }
	}
    }
    // Normal ray or shadow ray? (compile-time template param)
    if (!stopAtfirstRayHit)
	// for normal ray, return true if we pierced a triangle
	return pBestTriIdx != -1;
    else
	// for shadow ray, return true if we found a triangle obstructing the light.
	return false;
}

// CUDA 1.2 has no recursion - I therefore use the magic of C++ templates:
// Compile-time recursion using the "depth" param!
template <int depth, bool doSpecular, bool doPhongInterp, bool doReflections, bool doShadows, bool doCulling>
__device__ Pixel Raytrace(
    Vector3 originInWorldSpace, Vector3 rayInWorldSpace, int avoidSelf,
    Triangle *pTriangles,
    Vector3 *cudaEyePosInWorldSpace, Vector3 *cudaLightPosInWorldSpace)
{
    int pBestTriIdx = -1;
    const Triangle *pBestTri = NULL;
    Vector3 pointHitInWorldSpace;
    coord kAB=0.f, kBC=0.f, kCA=0.f; // distances from the 3 edges of the triangle (from where we hit it)

    // Use the surface-area heuristic based, bounding volume hierarchy of axis-aligned bounding boxes
    // (keywords: SAH, BVH, AABB)
    if (!BVH_IntersectTriangles<false,doCulling>(
	    //pTriangles,
	    originInWorldSpace, rayInWorldSpace, avoidSelf,
	    pBestTriIdx, pointHitInWorldSpace, kAB, kBC, kCA))
	// We pierced no triangle, return with no contribution (ambient is black)
	return Pixel(0.f,0.f,0.f);

    // Set this to pass to recursive calls below, so that we don't get self-shadow or self-reflection
    // from this triangle...
    avoidSelf = pBestTriIdx;
    pBestTri = &pTriangles[pBestTriIdx];

    // We'll also calculate the color contributed from this intersection
    // Start from the triangle's color
    Pixel color = pBestTri->_colorf;

    // Phong interpolation of normal vector: these values are only set if
    // the doPhongInterp template param is set
    Vector3 phongNormal;
    coord ABx,BCx,CAx,area;
    float4 V1;
    float4 N1;
    float4 V2;
    float4 N2;
    float4 V3;
    float4 N3;
    V1 = tex1Dfetch(g_verticesTexture, 2*pBestTri->_idx1);
    V2 = tex1Dfetch(g_verticesTexture, 2*pBestTri->_idx2);
    V3 = tex1Dfetch(g_verticesTexture, 2*pBestTri->_idx3);
    if (doPhongInterp) { // template-param, compile-time check
	// These are the closest triangle's vertices...
	N1 = tex1Dfetch(g_verticesTexture, 2*pBestTri->_idx1+1);
	N2 = tex1Dfetch(g_verticesTexture, 2*pBestTri->_idx2+1);
	N3 = tex1Dfetch(g_verticesTexture, 2*pBestTri->_idx3+1);
	const Vector3 bestTriA = Vector3(V1.x,V1.y,V1.z);
	const Vector3 bestTriB = Vector3(V2.x,V2.y,V2.z);
	const Vector3 bestTriC = Vector3(V3.x,V3.y,V3.z);
	// ...and their normal vectors:
	const Vector3 bestTriNrmA = Vector3(N1.x,N1.y,N1.z);
	const Vector3 bestTriNrmB = Vector3(N2.x,N2.y,N2.z);
	const Vector3 bestTriNrmC = Vector3(N3.x,N3.y,N3.z);

	// We now want to interpolate the triangle's normal,
	// so that as the "pointHitInWorldSpace" gets closer to
	// a vertex X, the interpolated normal becomes closer to bestTriNrmX,
	// and becomes EXACTLY bestTriNrmX, if the pointHitInWorldSpace is X.
	//
	// To do that, we use the 3 areas of the triangle, as it is divided
	// by the pointHitInWorldSpace.
	//
	// This is the total triangle's area: cross product of two edges
	// (in fact, we should divide by 2, but since we're only interested
	//  in ratios (see below), there is no need)
	Vector3 AB = bestTriB; AB-= bestTriA;  // edge AB
	Vector3 BC = bestTriC; BC-= bestTriB;  // edge BC
	Vector3 crossAB_BC = crossCUDA(AB, BC);
	area = crossAB_BC.length();      // 2*area(ABC)

	// And these are the three sub-triangles - kAB,kBC,kCA were found above...
	ABx = kAB*distanceCUDA(bestTriA, bestTriB);
	BCx = kBC*distanceCUDA(bestTriB, bestTriC);
	CAx = kCA*distanceCUDA(bestTriC, bestTriA);

	// use the area of the sub-triangle ACROSS a point, to scale!
	// (which means that if pointHitInCameraSpace is exactly on a vertex,
	//  the area of the sub-triangle becomes the area of the triangle!)
	Vector3 phongNormalA = bestTriNrmA; phongNormalA *= BCx / area;
	Vector3 phongNormalB = bestTriNrmB; phongNormalB *= CAx / area;
	Vector3 phongNormalC = bestTriNrmC; phongNormalC *= ABx / area;

	// and finally, accumulate the three contributions and normalize.
	phongNormal = phongNormalA + phongNormalB + phongNormalC;
	phongNormal.normalize();
    } else
	phongNormal = pBestTri->_normal;

#ifdef AMBIENT_OCCLUSION
    // Calculate ambient occlusion - throw AMBIENT_SAMPLES number of random rays
    // in the hemisphere formed from the pointHitInWorldSpace and the normal vector...
    int i=0;
    coord totalLight = 0.f, maxLight = 0.f;
    while (i<AMBIENT_SAMPLES) {
	Vector3 ambientRay = phongNormal;
	ambientRay._x += float(rand()-RAND_MAX/2)/(RAND_MAX/2);
	ambientRay._y += float(rand()-RAND_MAX/2)/(RAND_MAX/2);
	ambientRay._z += float(rand()-RAND_MAX/2)/(RAND_MAX/2);
	float cosangle = dotCUDA(ambientRay, phongNormal);
	if (cosangle<0.f) continue;
	i++;
	maxLight += cosangle;
	ambientRay.normalize();
	Vector3 temp(pointHitInWorldSpace);
	temp += ambientRay*AMBIENT_RANGE;
	const Triangle *dummy;
	// Some objects needs a "nudge", to avoid self-shadowing
	//Vector3 nudgedPointHitInWorldSpace = pointHitInWorldSpace;
	//nudgedPointHitInWorldSpace += ambientRay*.005f;
	//if (!BVH_IntersectTriangles<true,true>(
	//	    nudgedPointHitInWorldSpace, ambientRay, avoidSelf,
	if (!BVH_IntersectTriangles<true,true>(
		pTriangles,
		pointHitInWorldSpace, ambientRay, avoidSelf,
		dummy, temp, kAB, kAB, kAB)) {
	    // Accumulate contribution of this random ray
	    totalLight += cosangle;
	}
    }
    // total ambient light, averaged over all random rays
    color *= (AMBIENT/255.0f)*(totalLight/maxLight);
#else
    // Dont calculate ambient occlusion, use the pre-calculated value from the model
    // (assuming it exists!)
    coord ambientOcclusionCoeff;
    if (doPhongInterp) { // template-param, compile-time check
	// we have a phong normal, so use the subtriangle areas
	// to interpolate the 3 ambientOcclusionCoeff values
	ambientOcclusionCoeff =
	    V1.w*BCx/area +
	    V2.w*CAx/area +
	    V3.w*ABx/area;
	    /*pVertices[pBestTri->_idx1]._ambientOcclusionCoeff*BCx/area +
	    pVertices[pBestTri->_idx2]._ambientOcclusionCoeff*CAx/area +
	    pVertices[pBestTri->_idx3]._ambientOcclusionCoeff*ABx/area;*/
    } else {
	// we dont have a phong normal, just average the 3 values of the vertices
	ambientOcclusionCoeff = (V1.w + V2.w + V3.w)/3.f;
	    /*pVertices[pBestTri->_idx1]._ambientOcclusionCoeff +
	    pVertices[pBestTri->_idx2]._ambientOcclusionCoeff +
	    pVertices[pBestTri->_idx3]._ambientOcclusionCoeff)/3.f;*/
    }
    coord ambientFactor = (coord) ((AMBIENT*ambientOcclusionCoeff/255.0f)/255.0f);
    color *= ambientFactor;
#endif // AMBIENT_OCCLUSION

/*
    // Now, for all the lights...
    for(unsigned i=0; i<scene._lights.size(); i++) {
	Light& light = *scene._lights[i];
*/

    Vector3& light = *cudaLightPosInWorldSpace;

    // This light's diffuse and specular contribution
    Pixel dColor = Pixel(); // start with black

    // We calculate the vector from point hit, to light (both in world space).
    Vector3 pointToLight = light;
    pointToLight -= pointHitInWorldSpace;

    bool inShadow = false;

    if (doShadows) { // template-param, compile-time check
	// this is our distance from the light (squared, i.e. we didnt use an sqrt)
	coord distanceFromLightSq = pointToLight.lengthsq();

	Vector3 shadowrayInWorldSpace = pointToLight;
	shadowrayInWorldSpace /= sqrt(distanceFromLightSq);

	int pDummy; // just to fill-in the param, not used for shadowrays
	if (BVH_IntersectTriangles<true,doCulling>(
	    //pTriangles,
	    pointHitInWorldSpace, shadowrayInWorldSpace, avoidSelf,
	    pDummy, // dummy
	    light,
	    kAB, kAB, kAB)) // dummies
	{
	    //continue; // we were in shadow, go to next light
	    inShadow = true;
	}
    }

    if (!inShadow) {
	// Diffuse color
	pointToLight.normalize();  // vector from point to light (in world space)

	coord intensity = dotCUDA(phongNormal, pointToLight);
	if (intensity<0.f) {
	    ; // in shadow, let it be in ambient
	} else {
	    Pixel diffuse = pBestTri->_colorf;
	    diffuse *= (coord) (DIFFUSE*intensity/255.f);   // diffuse set to a maximum of 130/255
	    dColor += diffuse;

	    if (doSpecular) { // template-param, compile-time check
		// Specular color
		// We will use the half vector: pointToLight + point to camera
		Vector3 pointToCamera = *cudaEyePosInWorldSpace;
		pointToCamera -= pointHitInWorldSpace;
		pointToCamera.normalize();

		Vector3 half = pointToLight;
		half += pointToCamera;
		half.normalize();

		// use the interpolated phong normal!
		coord intensity2 = dotCUDA(half, phongNormal);
		if (intensity2>0.f) {
		    intensity2 *= intensity2;
		    intensity2 *= intensity2;
		    intensity2 *= intensity2;
		    intensity2 *= intensity2;
		    intensity2 *= intensity2;
		    dColor += Pixel(
			(unsigned char)(SPECULAR*intensity2),
			(unsigned char)(SPECULAR*intensity2),
			(unsigned char)(SPECULAR*intensity2));
		}
	    }
	}
	color += dColor;
    }

    // } for each light

    if (!doReflections)
	return color;
    else {
	originInWorldSpace = pointHitInWorldSpace;
	const Vector3& nrm = phongNormal;
	float c1 = -dotCUDA(rayInWorldSpace, nrm);

	// Reflections:
	//
	// ray = ray - 2 (ray dot normal) normal
	Vector3 reflectedRay = rayInWorldSpace;
	reflectedRay += nrm*(2.0f*c1);
	reflectedRay.normalize();

	return
	    color
	    /* use backface culling for reflection rays: <true> */
	    + Raytrace<depth+1, doSpecular, doPhongInterp, doReflections, doShadows, true>(
		originInWorldSpace, reflectedRay, avoidSelf,
		pTriangles,
		cudaEyePosInWorldSpace, cudaLightPosInWorldSpace) * REFLECTIONS_RATE
	    /* ...but not for refraction rays: <false>
	      REMOVED, 2011/02/04
	    */
	    ;
    }
}

// CUDA 1.2 has no recursion - I therefore use the magic of C++ templates:
// Compile-time recursion using the "depth" param!
//
// These are the template specializations that stop the compile-time recursion
// at MAX_RAY_DEPTH level.

#define STOP_RECURSION(a,b,c,d,e)							    \
template <>										    \
__device__ Pixel Raytrace<MAX_RAY_DEPTH,a,b,c,d,e>(					    \
    Vector3 originInWorldSpace, Vector3 rayInWorldSpace, int avoidSelf,			    \
    Triangle *pTriangles,								    \
    Vector3 *cudaEyePosInWorldSpace, Vector3 *cudaLightPosInWorldSpace)			    \
{											    \
    return Pixel(0.f,0.f,0.f);								    \
}

#define f false
#define t true
STOP_RECURSION(f,f,f,f,f)
STOP_RECURSION(f,f,f,f,t)
STOP_RECURSION(f,f,f,t,f)
STOP_RECURSION(f,f,f,t,t)
STOP_RECURSION(f,f,t,f,f)
STOP_RECURSION(f,f,t,f,t)
STOP_RECURSION(f,f,t,t,f)
STOP_RECURSION(f,f,t,t,t)
STOP_RECURSION(f,t,f,f,f)
STOP_RECURSION(f,t,f,f,t)
STOP_RECURSION(f,t,f,t,f)
STOP_RECURSION(f,t,f,t,t)
STOP_RECURSION(f,t,t,f,f)
STOP_RECURSION(f,t,t,f,t)
STOP_RECURSION(f,t,t,t,f)
STOP_RECURSION(f,t,t,t,t)
STOP_RECURSION(t,f,f,f,f)
STOP_RECURSION(t,f,f,f,t)
STOP_RECURSION(t,f,f,t,f)
STOP_RECURSION(t,f,f,t,t)
STOP_RECURSION(t,f,t,f,f)
STOP_RECURSION(t,f,t,f,t)
STOP_RECURSION(t,f,t,t,f)
STOP_RECURSION(t,f,t,t,t)
STOP_RECURSION(t,t,f,f,f)
STOP_RECURSION(t,t,f,f,t)
STOP_RECURSION(t,t,f,t,f)
STOP_RECURSION(t,t,f,t,t)
STOP_RECURSION(t,t,t,f,f)
STOP_RECURSION(t,t,t,f,t)
STOP_RECURSION(t,t,t,t,f)
STOP_RECURSION(t,t,t,t,t)
#undef f
#undef t

// Main CUDA kernel, templated, to support each of the desired features:
//
// - using specular lights or not
// - doing Phong normal interpolation or not
// - doing reflections or not
// - doing shadows or not
// - doing anti-alias or not
//
template <bool doSpecular, bool doPhongInterp, bool doReflections, bool doShadows, bool antialias>
__global__ void CoreLoopTrianglesRaycaster(
    int *pixels,
    Matrix3 *cudaWorldToCameraSpace,
    Triangle *pTriangles,
    Vector3 *cudaEyePosInWorldSpace, Vector3 *cudaLightPosInWorldSpace,
    unsigned *cudaMortonTable)
{
    unsigned int idx = blockIdx.x*blockDim.x + threadIdx.x;
    if (idx>=MAXX*MAXY)
	return;
    // without MORTON_ORDER
    // int x = idx % MAXX;
    // int y = idx / MAXX;

    // This code will not allocate idx to a normal, left-to-right, top-to-bottom
    // allocation of pixels. Instead, it will use the pre-calculated Morton order
    // of pixels in screen space, to make threads end up reading the same (hopefully)
    // BVH and triangle data (more co-alesced, cache-friendly accesses).
    int x = int(cudaMortonTable[idx] & 0xFFFF);
    int y = int((cudaMortonTable[idx] & 0xFFFF0000)>>16);

    Pixel finalColor(0,0,0);
    int pixelsTraced = 1;
    if (antialias)
	pixelsTraced = 4;

    while(pixelsTraced--) {
	// We will shoot a ray in camera space (from Eye to the screen point, so in camera
	// space, from (0,0,0) to this:
	coord xx = (coord)x;
	coord yy = (coord)y;

	if (antialias) {
	    // nudge in a cross pattern around the pixel center
	    xx += 0.25f - .5f*(pixelsTraced&1);
	    yy += 0.25f - .5f*((pixelsTraced&2)>>1);
	}
	coord lx = coord((MAXY/2)-yy)/SCREEN_DIST;
	coord ly = coord(xx-(MAXX/2))/SCREEN_DIST;
	coord lz = 1.0f;
	Vector3 rayInCameraSpace(lx,ly,lz);
	rayInCameraSpace.normalize();

	// We will need the origin in world space
	Vector3 originInWorldSpace = *cudaEyePosInWorldSpace;

	// We have a rayInCameraSpace, and we want to use the BVH, which was constructed
	// in World space, so we convert the ray in World space
	Vector3 rayInWorldSpace = cudaWorldToCameraSpace->_row1 * rayInCameraSpace._x;
	rayInWorldSpace += cudaWorldToCameraSpace->_row2 * rayInCameraSpace._y;
	rayInWorldSpace += cudaWorldToCameraSpace->_row3 * rayInCameraSpace._z;
	// in theory, this should not be required
	rayInWorldSpace.normalize();

	// Primary ray, level 0, and we want backface culling: <true>
	finalColor += Raytrace<0, doSpecular, doPhongInterp, doReflections, doShadows, true>(
	    originInWorldSpace, rayInWorldSpace, -1,
	    pTriangles,
	    cudaEyePosInWorldSpace, cudaLightPosInWorldSpace);
    }
    if (antialias)
	finalColor /= 4.f;
    if (finalColor._r>255.0f) finalColor._r=255.0f;
    if (finalColor._g>255.0f) finalColor._g=255.0f;
    if (finalColor._b>255.0f) finalColor._b=255.0f;

    int color = getColor(finalColor);
    // without MORTON_ORDER
    //pixels[idx] = color;
    pixels[y*MAXX+x] = color;
}

// The bridge to the normal C++ world: templated, to include only the mode-specific code in each incantation

bool g_bFirstTime = true;

void CudaRender(
    Matrix3 *cudaWorldToCameraSpace,
    Vertex *cudaPtrVertices, Triangle *cudaPtrTriangles, float *cudaTriangleIntersectionData,
    int *cudaTriIdxList, float *cudaBVHlimits, int *cudaBVHindexesOrTrilists,
    Vector3 *cudaEyePosInWorldSpace, Vector3 *cudaLightPosInWorldSpace,
    unsigned *cudaMortonTable)
{
    if (g_bFirstTime) {
	// The first time any of the CudaRender templates is called,
	// bind the texture data!
	g_bFirstTime = false;

	cudaChannelFormatDesc channel1desc = cudaCreateChannelDesc<uint1>();
	cudaBindTexture(NULL, &g_triIdxListTexture, cudaTriIdxList, &channel1desc, g_triIndexListNo*sizeof(uint1));

	cudaChannelFormatDesc channel2desc = cudaCreateChannelDesc<float2>();
	cudaBindTexture(NULL, &g_pCFBVHlimitsTexture, cudaBVHlimits, &channel2desc, g_pCFBVH_No*6*sizeof(float));

	cudaChannelFormatDesc channel3desc = cudaCreateChannelDesc<int4>();
	cudaBindTexture(NULL, &g_pCFBVHindexesOrTrilistsTexture, cudaBVHindexesOrTrilists, &channel3desc,
	    g_pCFBVH_No*sizeof(uint4));

	cudaChannelFormatDesc channel4desc = cudaCreateChannelDesc<float4>();
	cudaBindTexture(NULL, &g_verticesTexture, cudaPtrVertices, &channel4desc, g_verticesNo*8*sizeof(float));

	cudaChannelFormatDesc channel5desc = cudaCreateChannelDesc<float4>();
	cudaBindTexture(NULL, &g_trianglesTexture, cudaTriangleIntersectionData, &channel5desc, g_trianglesNo*20*sizeof(float));
    }

    int *pixels;
    glBindTexture(GL_TEXTURE_2D, tex);
    SAFE(cudaGLMapBufferObject((void**)&pixels, buffer));

    if (g_bUsePoints) {
	cudaMemset(pixels, 0x40, MAXX*MAXY*sizeof(unsigned)); // Clear all pixels to ambient
	int blocksVertices = (g_verticesNo + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;
	CoreLoopVertices<<< blocksVertices, THREADS_PER_BLOCK >>>(
	    pixels, cudaWorldToCameraSpace, cudaEyePosInWorldSpace);
    /*
	cudaMemset(pixels, 0x40, MAXX*MAXY*sizeof(unsigned)); // Clear all pixels to ambient
	int blocksTriangles = (g_trianglesNo + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;
	CoreLoopTriangles<<< blocksTriangles, THREADS_PER_BLOCK >>>(
	    pixels, cudaWorldToCameraSpace, cudaPtrTriangles, cudaEyePosInWorldSpace);*/
    } else {
	int blockPixels = (MAXY*MAXX + THREADS_PER_BLOCK - 1)/THREADS_PER_BLOCK;
	DBG_PUTS(1, "CoreLoopTrianglesRaycaster begins");

	#define PAINT(bDoSpecular,bDoPhongInterp,bDoReflections,bDoShadows,bDoAntialias)				\
	    CoreLoopTrianglesRaycaster<bDoSpecular,bDoPhongInterp,bDoReflections,bDoShadows,bDoAntialias>		\
	    <<< blockPixels, THREADS_PER_BLOCK >>>(									\
		pixels,													\
		cudaWorldToCameraSpace,											\
		cudaPtrTriangles,											\
		cudaEyePosInWorldSpace, cudaLightPosInWorldSpace,							\
		cudaMortonTable);

	// Being templated, one can use the CoreLoopTrianglesRaycaster in any form one wants.
	// In theory, C++ compilers don't need this expansion (which I wrote with a simple Python script)
	// Unfortunately, we can't pass runtime vars in template params, not even when they are enumerants
	// or booleans...

	PAINT( true , true , true , true , true )
    }
    cudaError_t error = cudaGetLastError();
    if(error != cudaSuccess) {
	printf("CUDA error: %s\n", cudaGetErrorString(error));
	exit(-1);
    }

    SAFE(cudaThreadSynchronize());
    SAFE(cudaGLUnmapBufferObject(buffer));

    // Use OpenGL texture to display the generated frame at lightning speed
    // (the PBO buffer is already on the card, no useless PCI bus criss-cross)
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, buffer);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, MAXX, MAXY, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, 1.0f);
    glEnd();

    // hack:
    extern bool g_benchmark;
    if (!g_benchmark) {
	// Display the "Press H for help" message
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glColor3f(1.f, 1.f, 1.f);
	glRasterPos2f(-0.95, 0.9);
	const char *help = "Press H for help";
	for(unsigned o=0;o<strlen(help); o++)
	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, help[o]);
    }
    SDL_GL_SwapBuffers();
}

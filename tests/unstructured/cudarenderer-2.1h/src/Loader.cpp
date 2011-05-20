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
#include <GL/glew.h>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cfloat>

#include <string.h>
#include <assert.h>

#include "lib3ds/types.h"
#include "lib3ds/material.h"
#include "lib3ds/mesh.h"
#include "lib3ds/file.h"

#include "3d.h"
#include "cudarenderer.h"
#include "Utility.h"

#define TRI_MAGIC	0xDEADBEEF
#define TRI_MAGICNORMAL 0xDEADC0DE

using std::string;

namespace enums {
    enum ColorComponent {
	Red = 0,
	Green = 1,
	Blue = 2
    };
}

using namespace enums;

// Helper struct for lib3ds materials
struct MaterialColors {

    MaterialColors(
	const Lib3dsRgba& ambient, const Lib3dsRgba& diffuse, const Lib3dsRgba& specular, bool twoSided)
	:
	_ambient(ambient), _diffuse(diffuse), _specular(specular), _twoSided(twoSided)
	{}

    template <ColorComponent c>
    float getByteAmbient() const { return 255.0f*_ambient[c]; }

    template <ColorComponent c>
    float getByteDiffuse() const { return 255.0f*_diffuse[c]; }

    template <ColorComponent c>
    float getByteSpecularRed() const { return 255.0f*_specular[c]; }

    const Lib3dsRgba& _ambient;
    const Lib3dsRgba& _diffuse;
    const Lib3dsRgba& _specular;
    bool _twoSided;
};

// Helper that calculates vertex normals.
// Should only be called for objects missing this information.
void fix_normals(void)
{
    for(unsigned j=0; j<g_trianglesNo; j++) {
	Vector3 worldPointA = g_vertices[g_triangles[j]._idx1];
	Vector3 worldPointB = g_vertices[g_triangles[j]._idx2];
	Vector3 worldPointC = g_vertices[g_triangles[j]._idx3];
	Vector3 AB = worldPointB;
	AB -= worldPointA;
	Vector3 AC = worldPointC;
	AC -= worldPointA;
	Vector3 cr = cross(AB, AC);
	cr.normalize();
	g_triangles[j]._normal = cr;
	g_vertices[g_triangles[j]._idx1]._normal += cr;
	g_vertices[g_triangles[j]._idx2]._normal += cr;
	g_vertices[g_triangles[j]._idx3]._normal += cr;
    }
    for(unsigned j=0; j<g_trianglesNo; j++) {
	g_vertices[g_triangles[j]._idx1]._normal.normalize();
	g_vertices[g_triangles[j]._idx2]._normal.normalize();
	g_vertices[g_triangles[j]._idx3]._normal.normalize();
    }
}

// Rescale input objects to have this size...
const coord MaxCoordAfterRescale = 1.2f;

coord load_object(const char *filename)
{
    std::cout << "Loading object..." << std::endl;
    const char *edot = strrchr(filename, '.');
    if (edot) {
	edot++;
	if (!strcmp(edot, "tri")) {
	    // Simple binary format:
	    //
	    // Basically:
	    //    <magic (uint32)>  TRI_MAGIC, TRI_MAGICNORMAL or missing
	    //    one or more of these blocks:
	    //        no_of_vertices (uint32)
	    //        x1,y1,z1 (float coordinates of vertex)
	    //        ...
	    //        xn,yn,zn (float coordinates of vertex)
	    //        (magic == TRI_MAGICNORMAL)? nx1, ny1, nz1 (float coordinates of normal)
	    //        no_of_triangles (uint32)
	    //        idx,idx,idx (uint32 indices into the vertex array)
	    //        (magic == TRI_MAGIC | TRI_MAGICNORMAL)? r,g,b (floats)
	    //        ...
	    //        idx,idx,idx (uint32 indices into the vertex array)
	    //        (magic == TRI_MAGIC | TRI_MAGICNORMAL)? r,g,b (floats)
	    FILE *fp = fopen(filename, "rb");
	    if (!fp)
		panic("File '%s' not found!\n", filename);

	    Uint32 totalPoints = 0, totalTris = 0;
	    Uint32 magic;

	    fread(&magic, 1, sizeof(Uint32), fp);
	    if (magic != TRI_MAGIC && magic != TRI_MAGICNORMAL) {
		// No magic, just vertices and points (no normals, no colors)
		fseek(fp, 0, SEEK_SET);
	    }

	    // Calculate total number of vertices in order to reserve the vectors memory
	    unsigned currentOffset = ftell(fp);
	    unsigned currentTotalPoints = 0;
	    unsigned currentTotalTris = 0;
	    while(1) {
		unsigned temp;
		fread(&temp, 1, sizeof(Uint32), fp);
		if (feof(fp))
		    break;
		currentTotalPoints += temp;
		fseek(fp, temp*(magic==TRI_MAGICNORMAL?24:12), SEEK_CUR);
		fread(&temp, 1, sizeof(Uint32), fp);
		if (feof(fp))
		    break;
		currentTotalTris += temp;
		fseek(fp, temp*24, SEEK_CUR);
	    }

	    // Reserve the space, now that you know
	    if (magic == TRI_MAGICNORMAL || magic == TRI_MAGIC) {
		g_vertices = (Vertex *) malloc(currentTotalPoints*sizeof(Vertex));
		g_verticesNo = currentTotalPoints;
	    } else {
		// when we have no normals, we'll need extra space for fix_normals()...
		g_vertices = (Vertex *) malloc(currentTotalTris*3*sizeof(Vertex));
		g_verticesNo = currentTotalTris*3;
	    }

	    g_triangles = (Triangle *) malloc(currentTotalTris*sizeof(Triangle));
	    g_trianglesNo = currentTotalTris;

	    Vertex *pCurrentVertex = g_vertices;
	    Triangle *pCurrentTriangle = g_triangles;

	    // Now load them inside the allocated space
	    fseek(fp, currentOffset, SEEK_SET);
	    do {
		Uint32 noOfPoints;
		fread(&noOfPoints, 1, sizeof(Uint32), fp);
		if (feof(fp))
		    break;

		for(Uint32 i=0; i<noOfPoints; i++) {
		    float x,y,z;
		    fread(&x,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		    fread(&y,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		    fread(&z,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }

		    float nx=0.,ny=0.,nz=0.;
		    if (magic == TRI_MAGICNORMAL) {
			fread(&nx,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
			fread(&ny,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
			fread(&nz,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		    } else {
			nx = ny = nz = 0; // Will be calculated in fix_normals()
		    }
		    pCurrentVertex->_x = x;
		    pCurrentVertex->_y = y;
		    pCurrentVertex->_z = z;
		    pCurrentVertex->_normal._x = nx;
		    pCurrentVertex->_normal._y = ny;
		    pCurrentVertex->_normal._z = nz;
		    pCurrentVertex->_ambientOcclusionCoeff = 60.f;
		    pCurrentVertex++;
		}

		Uint32 noOfTris;
		fread(&noOfTris, 1, sizeof(Uint32), fp);
		if (feof(fp)) { panic("Malformed 3D file"); }

		for(Uint32 i=0; i<noOfTris; i++) {
		    Uint32 idx1,idx2,idx3;
		    fread(&idx1,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		    fread(&idx2,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		    fread(&idx3,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		    if (idx1>=(totalPoints+noOfPoints)) { panic("Malformed 3D file (idx1)"); }
		    if (idx2>=(totalPoints+noOfPoints)) { panic("Malformed 3D file (idx2)"); }
		    if (idx3>=(totalPoints+noOfPoints)) { panic("Malformed 3D file (idx3)"); }

		    float r,g,b;
		    if (magic == TRI_MAGIC || magic == TRI_MAGICNORMAL) {
			fread(&r,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
			fread(&g,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
			fread(&b,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
			r*=255.; g*=255.; b*=255.;
		    } else {
			r = g = b = 255.0; // No colors? White, then... :-(
		    }

		    pCurrentTriangle->_idx1 = idx1;
		    pCurrentTriangle->_idx2 = idx2;
		    pCurrentTriangle->_idx3 = idx3;
		    pCurrentTriangle->_colorf._r = r;
		    pCurrentTriangle->_colorf._g = g;
		    pCurrentTriangle->_colorf._b = b;
		    pCurrentTriangle->_twoSided = false;
		    Vertex *vertexA = &g_vertices[idx1];
		    Vertex *vertexB = &g_vertices[idx2];
		    Vertex *vertexC = &g_vertices[idx3];
		    if (magic == TRI_MAGICNORMAL) {
			assert(vertexA < pCurrentVertex);
			assert(vertexB < pCurrentVertex);
			assert(vertexC < pCurrentVertex);
			pCurrentTriangle->_normal = Vector3(
			    (vertexA->_normal._x + vertexB->_normal._x + vertexC->_normal._x)/3.0f,
			    (vertexA->_normal._y + vertexB->_normal._y + vertexC->_normal._y)/3.0f,
			    (vertexA->_normal._z + vertexB->_normal._z + vertexC->_normal._z)/3.0f);
			pCurrentTriangle->_normal.normalize();
		    } else {
			pCurrentTriangle->_normal = Vector3();
		    }
		    pCurrentTriangle->_bottom = Vector3(FLT_MAX,FLT_MAX,FLT_MAX);
		    pCurrentTriangle->_top = Vector3(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		    pCurrentTriangle->_center = Vector3( 
			    (vertexA->_x + vertexB->_x + vertexC->_x)/3.0f,
			    (vertexA->_y + vertexB->_y + vertexC->_y)/3.0f,
			    (vertexA->_z + vertexB->_z + vertexC->_z)/3.0f);
		    pCurrentTriangle++;
		}
		totalPoints += noOfPoints;
		totalTris   += noOfTris;
	    } while(!feof(fp));

	    fclose(fp);
	    if (magic != TRI_MAGICNORMAL)
		fix_normals();

	} else if (!strcmp(edot, "ra2")) {
	    // http://ompf.org/forum/viewtopic.php?t=64
	    FILE *fp = fopen(filename, "rb");
	    if (!fp)
		panic((string("File '") + string(filename) + string("' not found!")).c_str());

	    Uint32 totalTriangles = 0;

	    fseek(fp, 0, SEEK_END);
	    totalTriangles = ftell(fp)/36;
	    fseek(fp, 0, SEEK_SET);

	    g_vertices = (Vertex *) malloc(totalTriangles*3*sizeof(Vertex));
	    g_verticesNo = totalTriangles*3;

	    g_triangles = (Triangle *) malloc(totalTriangles*sizeof(Triangle));
	    g_trianglesNo = totalTriangles;

	    Vertex *pCurrentVertex = g_vertices;
	    Triangle *pCurrentTriangle = g_triangles;

	    for(Uint32 i=0; i<g_verticesNo; i++) {
		float x,y,z;
		fread(&y,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		fread(&z,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		fread(&x,1,4,fp); if (feof(fp)) { panic("Malformed 3D file"); }
		float nx=0.,ny=0.,nz=0.;

		pCurrentVertex->_x = x;
		pCurrentVertex->_y = y;
		pCurrentVertex->_z = z;
		pCurrentVertex->_normal._x = nx;
		pCurrentVertex->_normal._y = ny;
		pCurrentVertex->_normal._z = nz;
		pCurrentVertex->_ambientOcclusionCoeff = 60.f;
		pCurrentVertex++;
	    }

	    for(Uint32 i=0; i<g_trianglesNo; i++) {
		Uint32 idx1,idx2,idx3;
		idx1 = 3*i + 0;
		if (getenv("RA2")!=NULL) {
		    idx2 = 3*i + 2;
		    idx3 = 3*i + 1;
		} else {
		    idx2 = 3*i + 1;
		    idx3 = 3*i + 2;
		}
		if (idx1>=(g_verticesNo)) { panic("Malformed 3D file (idx1)"); }
		if (idx2>=(g_verticesNo)) { panic("Malformed 3D file (idx2)"); }
		if (idx3>=(g_verticesNo)) { panic("Malformed 3D file (idx3)"); }

		float r,g,b;
		r = g = b = 255.0; // No colors? White, then... :-(

		pCurrentTriangle->_idx1 = idx1;
		pCurrentTriangle->_idx2 = idx2;
		pCurrentTriangle->_idx3 = idx3;
		pCurrentTriangle->_colorf._r = r;
		pCurrentTriangle->_colorf._g = g;
		pCurrentTriangle->_colorf._b = b;
		pCurrentTriangle->_twoSided = false;
		Vertex *vertexA = &g_vertices[idx1];
		Vertex *vertexB = &g_vertices[idx2];
		Vertex *vertexC = &g_vertices[idx3];
		pCurrentTriangle->_normal = Vector3();
		pCurrentTriangle->_bottom = Vector3(FLT_MAX,FLT_MAX,FLT_MAX);
		pCurrentTriangle->_top = Vector3(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		pCurrentTriangle->_center = Vector3(
			(vertexA->_x + vertexB->_x + vertexC->_x)/3.0f,
			(vertexA->_y + vertexB->_y + vertexC->_y)/3.0f,
			(vertexA->_z + vertexB->_z + vertexC->_z)/3.0f);
		pCurrentTriangle++;
	    }
	    fclose(fp);
	    fix_normals();
	} else if (!strcmp(edot, "3ds") || !strcmp(edot, "3DS")) {
	    int i = 0;
	    Lib3dsFile* p3DS = lib3ds_file_load(filename);
	    if (!p3DS)
		panic("Lib3DS couldn't load this .3ds file");
	    lib3ds_file_eval(p3DS, 0);

	    Lib3dsDword currentTotalTris = 0;
	    Lib3dsMesh *pMesh = p3DS->meshes;
	    if (!pMesh)
		panic("This .3ds file has no meshes");
	    std::map<Lib3dsMesh*, Lib3dsVector*> normals;
	    while(pMesh) {
		currentTotalTris   += pMesh->faces;
		Lib3dsVector *pMeshNormals = new Lib3dsVector[3*pMesh->faces];
		lib3ds_mesh_calculate_normals(pMesh, pMeshNormals);
		normals[pMesh] = pMeshNormals;
		pMesh = pMesh->next;
	    }

	    g_vertices = (Vertex *) malloc(3*currentTotalTris*sizeof(Vertex));
	    g_verticesNo = 3*currentTotalTris;
	    g_triangles = (Triangle *) malloc(currentTotalTris*sizeof(Triangle));
	    g_trianglesNo = currentTotalTris;
	    Vertex *pCurrentVertex = g_vertices;
	    Triangle *pCurrentTriangle = g_triangles;

	    std::map<string, MaterialColors> colors;
	    Lib3dsMaterial *pMaterial = p3DS->materials;
	    while(pMaterial) {
		colors.insert(
		    std::map<string, MaterialColors>::value_type(
			string(pMaterial->name),
			MaterialColors(
			    pMaterial->ambient, pMaterial->diffuse,  pMaterial->specular, 
			    pMaterial->two_sided!=0)));
		pMaterial = pMaterial->next;
	    }
	    pMesh = p3DS->meshes;
	    int currentTotalPoints = 0;
	    while(pMesh) {
		if (!pMesh->pointL) { pMesh=pMesh->next; continue; }
		if (!pMesh->faceL)  { pMesh=pMesh->next; continue; }
		for(i=0; i<(int)pMesh->faces; i++) {
		    std::map<string, MaterialColors>::iterator pMat = colors.find(string(pMesh->faceL[i].material));
		    float r, g, b;
		    if (pMat != colors.end()) {
			r = pMat->second.getByteDiffuse<Red>();
			g = pMat->second.getByteDiffuse<Green>();
			b = pMat->second.getByteDiffuse<Blue>();
		    } else {
			r = g = b = 255;
		    }
		    for (int k=0; k<3; k++) {
			int pointIdx = pMesh->faceL[i].points[k];
			Vector3 nr(
			    normals[pMesh][3*i+k][0],
			    normals[pMesh][3*i+k][1],
			    normals[pMesh][3*i+k][2]);
			pCurrentVertex->_x = pMesh->pointL[pointIdx].pos[0];
			pCurrentVertex->_y = pMesh->pointL[pointIdx].pos[1];
			pCurrentVertex->_z = pMesh->pointL[pointIdx].pos[2];
			pCurrentVertex->_normal._x = nr._x;
			pCurrentVertex->_normal._y = nr._y;
			pCurrentVertex->_normal._z = nr._z;
			pCurrentVertex->_ambientOcclusionCoeff = 60.f;
			pCurrentVertex++;
		    }
		    Uint32 idx1,idx2,idx3;
		    idx1 = currentTotalPoints + 3*i;
		    idx2 = idx1 + 1;
		    idx3 = idx1 + 2;
		    pCurrentTriangle->_idx1 = idx1;
		    pCurrentTriangle->_idx2 = idx2;
		    pCurrentTriangle->_idx3 = idx3;
		    pCurrentTriangle->_colorf._r = r;
		    pCurrentTriangle->_colorf._g = g;
		    pCurrentTriangle->_colorf._b = b;
		    pCurrentTriangle->_twoSided = pMat->second._twoSided;
		    pCurrentTriangle->_normal = Vector3(
			pMesh->faceL[i].normal[0],
			pMesh->faceL[i].normal[1],
			pMesh->faceL[i].normal[2]);
		    pCurrentTriangle->_bottom = Vector3(FLT_MAX,FLT_MAX,FLT_MAX);
		    pCurrentTriangle->_top = Vector3(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		    Vertex *vertexA = &g_vertices[idx1];
		    Vertex *vertexB = &g_vertices[idx2];
		    Vertex *vertexC = &g_vertices[idx3];
		    pCurrentTriangle->_center = Vector3( 
			    (vertexA->_x + vertexB->_x + vertexC->_x)/3.0f,
			    (vertexA->_y + vertexB->_y + vertexC->_y)/3.0f,
			    (vertexA->_z + vertexB->_z + vertexC->_z)/3.0f);
		    pCurrentTriangle++;
		}
		currentTotalPoints += 3*pMesh->faces;
		pMesh = pMesh->next;
	    }
	} else if (!strcmp(edot, "PLY") || !strcmp(edot, "ply")) {
	    // Only shadevis generated objects, not full blown parser!
	    std::ifstream file(filename, std::ios::in);
	    if (!file) {
		panic((string("Missing ")+string(filename)).c_str());
	    }

	    Vertex *pCurrentVertex = NULL;
	    Triangle *pCurrentTriangle = NULL;

	    string line;
	    unsigned totalVertices, totalTriangles, lineNo=0;
	    bool inside = false;
	    while(getline(file, line)) {
		lineNo++;
		if (!inside) {
		    if (line.substr(0, 14) == "element vertex") {
			std::istringstream str(line);
			string word1;
			str >> word1;
			str >> word1;
			str >> totalVertices;
			g_vertices = (Vertex *) malloc(totalVertices*sizeof(Vertex));
			g_verticesNo = totalVertices;
			pCurrentVertex = g_vertices;
		    } else if (line.substr(0, 12) == "element face") {
			std::istringstream str(line);
			string word1;
			str >> word1;
			str >> word1;
			str >> totalTriangles;
			g_triangles = (Triangle *) malloc(totalTriangles*sizeof(Triangle));
			g_trianglesNo = totalTriangles;
			pCurrentTriangle = g_triangles;
		    } else if (line.substr(0, 10) == "end_header")
			inside = true;
		} else {
		    if (totalVertices) {
			totalVertices--;
			float x,y,z;
			float ambientOcclusionCoeff;
			std::istringstream str(line);
			str >> x >> y >> z;
			if (str >> ambientOcclusionCoeff)
			    ;
			else
			    ambientOcclusionCoeff = 60;
			pCurrentVertex->_x = x;
			pCurrentVertex->_y = y;
			pCurrentVertex->_z = z;
			pCurrentVertex->_normal._x = 0.;
			pCurrentVertex->_normal._y = 0.;
			pCurrentVertex->_normal._z = 0.;
			pCurrentVertex->_ambientOcclusionCoeff = ambientOcclusionCoeff;
			pCurrentVertex++;
		    } else if (totalTriangles) {
			totalTriangles--;
			unsigned dummy;
			float r, g, b;
			unsigned idx1, idx2, idx3;
			std::istringstream str(line);
			if (str >> dummy >> idx1 >> idx2 >> idx3)
			{
			    if (str >> r >> g >> b)
				;
			    else {
				r = 255; g = 255; b = 255;
			    }
			    pCurrentTriangle->_idx1 = idx1;
			    pCurrentTriangle->_idx2 = idx2;
			    pCurrentTriangle->_idx3 = idx3;
			    pCurrentTriangle->_colorf._r = r;
			    pCurrentTriangle->_colorf._g = g;
			    pCurrentTriangle->_colorf._b = b;
			    pCurrentTriangle->_twoSided = false;
			    pCurrentTriangle->_normal = Vector3();
			    pCurrentTriangle->_bottom = Vector3(FLT_MAX,FLT_MAX,FLT_MAX);
			    pCurrentTriangle->_top = Vector3(-FLT_MAX,-FLT_MAX,-FLT_MAX);
			    Vertex *vertexA = &g_vertices[idx1];
			    Vertex *vertexB = &g_vertices[idx2];
			    Vertex *vertexC = &g_vertices[idx3];
			    pCurrentTriangle->_center = Vector3( 
				(vertexA->_x + vertexB->_x + vertexC->_x)/3.0f,
				(vertexA->_y + vertexB->_y + vertexC->_y)/3.0f,
				(vertexA->_z + vertexB->_z + vertexC->_z)/3.0f);
			    pCurrentTriangle++;
			}
		    }
		}
	    }
	    fix_normals();
	} else
	    panic("Unknown extension (only .tri .3ds or .ply accepted)");
    } else
	panic("No extension in filename (only .tri .3ds or .ply accepted)");

    std::cout << "Vertexes: " << g_verticesNo;
    std::cout << " Triangles: " << g_trianglesNo << std::endl;

    // Center scene at world's center

    Vector3 minp(FLT_MAX,FLT_MAX,FLT_MAX), maxp(-FLT_MAX,-FLT_MAX,-FLT_MAX);
    for(unsigned i=0; i<g_trianglesNo; i++) {
	minp.assignSmaller(g_vertices[g_triangles[i]._idx1]);
	minp.assignSmaller(g_vertices[g_triangles[i]._idx2]);
	minp.assignSmaller(g_vertices[g_triangles[i]._idx3]);
	maxp.assignBigger(g_vertices[g_triangles[i]._idx1]);
	maxp.assignBigger(g_vertices[g_triangles[i]._idx2]);
	maxp.assignBigger(g_vertices[g_triangles[i]._idx3]);
    }
    Vector3 origCenter = Vector3(
	(maxp._x+minp._x)/2,
	(maxp._y+minp._y)/2,
	(maxp._z+minp._z)/2);

    minp -= origCenter;
    maxp -= origCenter;

    // Scale scene so max(abs x,y,z coordinates) = MaxCoordAfterRescale

    coord maxi = 0;
    maxi = std::max(maxi, (coord) fabs(minp._x));
    maxi = std::max(maxi, (coord) fabs(minp._y));
    maxi = std::max(maxi, (coord) fabs(minp._z));
    maxi = std::max(maxi, (coord) fabs(maxp._x));
    maxi = std::max(maxi, (coord) fabs(maxp._y));
    maxi = std::max(maxi, (coord) fabs(maxp._z));

    std::cout << "Centering and scaling vertices..." << std::endl;
    for(unsigned i=0; i<g_verticesNo; i++) {
	g_vertices[i] -= origCenter;
	g_vertices[i] *= MaxCoordAfterRescale/maxi;
    }
    std::cout << "Centering and scaling triangles..." << std::endl;
    for(unsigned i=0; i<g_trianglesNo; i++) {
	g_triangles[i]._center -= origCenter;
	g_triangles[i]._center *= MaxCoordAfterRescale/maxi;
    }
    std::cout << "Updating triangle bounding boxes (used by BVH)..." << std::endl;
    for(unsigned i=0; i<g_trianglesNo; i++) {
	g_triangles[i]._bottom.assignSmaller(g_vertices[g_triangles[i]._idx1]);
	g_triangles[i]._bottom.assignSmaller(g_vertices[g_triangles[i]._idx2]);
	g_triangles[i]._bottom.assignSmaller(g_vertices[g_triangles[i]._idx3]);
	g_triangles[i]._top.assignBigger(g_vertices[g_triangles[i]._idx1]);
	g_triangles[i]._top.assignBigger(g_vertices[g_triangles[i]._idx2]);
	g_triangles[i]._top.assignBigger(g_vertices[g_triangles[i]._idx3]);
    }
    std::cout << "Pre-computing triangle intersection data (used by raytracer)..." << std::endl;
    for(unsigned i=0; i<g_trianglesNo; i++) {
	Triangle& triangle = g_triangles[i];

	// Algorithm for triangle intersection is taken from Roman Kuchkuda's paper.
	// edge vectors
	Vector3 vc1=g_vertices[triangle._idx2]; vc1-=g_vertices[triangle._idx1];
	Vector3 vc2=g_vertices[triangle._idx3]; vc2-=g_vertices[triangle._idx2];
	Vector3 vc3=g_vertices[triangle._idx1]; vc3-=g_vertices[triangle._idx3];

	// plane of triangle
	triangle._normal = cross(vc1, vc2); 
	Vector3 alt1 = cross(vc2, vc3);
	if (alt1.length() > triangle._normal.length()) triangle._normal = alt1;
	Vector3 alt2 = cross(vc3, vc1);
	if (alt2.length() > triangle._normal.length()) triangle._normal = alt2;
	triangle._normal.normalize();
	triangle._d = dot(triangle._normal, g_vertices[triangle._idx1]);

	// edge planes
	triangle._e1 = cross(triangle._normal, vc1); 
	triangle._e1.normalize();
	triangle._d1 = dot(triangle._e1, g_vertices[triangle._idx1]);
	triangle._e2 = cross(triangle._normal, vc2); 
	triangle._e2.normalize();
	triangle._d2 = dot(triangle._e2, g_vertices[triangle._idx2]);
	triangle._e3 = cross(triangle._normal, vc3); 
	triangle._e3.normalize();
	triangle._d3 = dot(triangle._e3, g_vertices[triangle._idx3]);
    }
    return MaxCoordAfterRescale;
}

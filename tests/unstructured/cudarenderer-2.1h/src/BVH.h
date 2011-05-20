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

#ifndef __BVH_H__
#define __BVH_H__

#include <list>

#include "Types.h"

// The nice version of the BVH - a shallow hierarchy of inner and leaf nodes
struct BVHNode {
    Vector3 _bottom;
    Vector3 _top;
    virtual bool IsLeaf() = 0;
};

struct BVHInner : BVHNode {
    BVHNode *_left;
    BVHNode *_right;
    virtual bool IsLeaf() { return false; }
};

struct Triangle;
struct BVHLeaf : BVHNode {
    std::list<const Triangle*> _triangles;
    virtual bool IsLeaf() { return true; }
};

BVHNode *CreateBVH();

// The ugly, cache-friendly form of the BVH: 32 bytes

struct CacheFriendlyBVHNode {
    // bounding box
    Vector3 _bottom;
    Vector3 _top;
    union {
	// inner node - indexes to array of CacheFriendlyBVHNode
	struct {
	    unsigned _idxLeft;
	    unsigned _idxRight;
	} inner;
	// leaf node: count, and starting index in triangle list
	struct {
	    unsigned _count; // Top-most bit set
	    unsigned _startIndexInTriIndexList;
	} leaf;
    } u;
};

void CreateCFBVH();

// The single-point entrance to the BVH - call only this
void UpdateBoundingVolumeHierarchy(const char *filename);

#endif

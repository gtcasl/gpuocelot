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

#ifndef __types_h__
#define __types_h__

#include <config.h>

#include <math.h>

#include <vector_types.h>

// The main floating point type, used everywhere
typedef float coord;

struct Vector3
{
    union {
	struct {
	    coord _x, _y, _z;
	};
	coord _v[3];
    };

   __device__  Vector3(coord x=0, coord y=0, coord z=0)
	:
	_x(x), _y(y), _z(z) {}

    __device__ Vector3(const Vector3& rhs)
	:
	_x(rhs._x),
	_y(rhs._y),
	_z(rhs._z) {}

    __device__ Vector3(const float4& rhs)
	:
	_x(rhs.x),
	_y(rhs.y),
	_z(rhs.z) {}

/* An abandoned experiment with intrinsics
 * (GCC proved to do just as good a job in optimizing with SSE)

        __m128 tmp = _mm_loadu_ps(&_x);
	__m128 l = _mm_mul_ps(tmp, tmp);
	l = _mm_add_ps(l, _mm_shuffle_ps(l, l, 0x4E));
	_mm_storeu_ps(&_x, _mm_mul_ps(tmp, _mm_rsqrt_ps(_mm_add_ps(l, _mm_shuffle_ps(l, l, 0x11)))));

 */
#ifdef CUDA_VERSION
    __device__ __host__ 
#endif
    inline coord length()
    {
	return sqrt(_x*_x +_y*_y + _z*_z);
    }

    // in some place, we dont need the sqrt, we are just comparing one length with another
#ifdef CUDA_VERSION
    __device__ __host__ 
#endif
    inline coord lengthsq()
    {
	return _x*_x +_y*_y + _z*_z;
    }

#ifdef CUDA_VERSION
    __device__ __host__ 
#endif
    inline void normalize()
    {
	coord norm = sqrt(_x*_x +_y*_y + _z*_z);
	_x /= norm;
	_y /= norm;
	_z /= norm;
    }

   __device__  Vector3& operator+=(const Vector3& rhs)
    {
	_x += rhs._x; _y += rhs._y; _z += rhs._z; return *this;
    }

   __device__  Vector3& operator-=(const Vector3& rhs)
    {
	_x -= rhs._x; _y -= rhs._y; _z -= rhs._z; return *this;
    }

   __device__  Vector3& operator*=(const coord& rhs)
    {
	_x *= rhs; _y *= rhs; _z *= rhs; return *this;
    }

    __device__ inline Vector3 operator*(coord rhs) const
    {
	return Vector3(_x*rhs, _y*rhs, _z*rhs);
    }

    __device__ inline Vector3 operator+(Vector3& rhs) const
    {
	return Vector3(_x+rhs._x, _y+rhs._y, _z+rhs._z);
    }

   __device__  Vector3& operator/=(const coord& rhs)
    {
	_x /= rhs; _y /= rhs; _z /= rhs; return *this;
    }

    __device__ inline bool operator!=(const Vector3& rhs)
    {
	return _x!=rhs._x || _y!=rhs._y || _z!=rhs._z;
    }

    // MSVC2008 for some reason gets confused if I include <algorithm>
    // and use std::max. GCC is fine... Oh well... macros always work:
    //
#define mymin(x,y) ((x)<(y))?(x):(y)
    __inline void assignSmaller(const Vector3& rhs)
    {
	_x = mymin(_x, rhs._x); _y = mymin(_y, rhs._y); _z = mymin(_z, rhs._z);
    }

#define mymax(x,y) ((x)<(y))?(y):(x)
    __inline void assignBigger(const Vector3& rhs)
    {
	_x = mymax(_x, rhs._x); _y = mymax(_y, rhs._y); _z = mymax(_z, rhs._z);
    }
};

// We need floating point components for the colors
struct Pixel {
    float _b;
    float _g;
    float _r;
    __device__ Pixel(float r=0.f, float g=0.f, float b=0.f)
	:
	_b(b), _g(g), _r(r) {}

    __device__ Pixel& operator+=(const Pixel& rhs) { _b += rhs._b; _g += rhs._g; _r += rhs._r; return *this; }
    __device__ Pixel& operator-=(const Pixel& rhs) { _b -= rhs._b; _g -= rhs._g; _r -= rhs._r; return *this; }
    __device__ Pixel& operator*=(const coord& rhs) {
	_b = rhs*_b;
	_g = rhs*_g;
	_r = rhs*_r;
	return *this;
    }
    __device__ Pixel& operator/=(const coord& rhs) {
	_b = _b/rhs;
	_g = _g/rhs;
	_r = _r/rhs;
	return *this;
    }

    __device__ Pixel operator+(const Pixel& rhs) {
	float r = _r+rhs._r; if (r<0.f) r=0.f; if (r>255.f) r=255.f;
	float g = _g+rhs._g; if (g<0.f) g=0.f; if (g>255.f) g=255.f;
	float b = _b+rhs._b; if (b<0.f) b=0.f; if (b>255.f) b=255.f;
	return Pixel(r,g,b);
    }
   __device__ Pixel operator*(const coord& rhs) { return Pixel(rhs*_r, rhs*_g, rhs*_b); }
};

#endif

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

#ifndef __camera_h__
#define __camera_h__

#include <config.h>

#include "3d.h"
#include "Algebra.h"

struct Camera : public Vector3 {
    // this->_x,_y,_z : where the camera is
    coord _tox, _toy, _toz; // where the camera looks at
    // transformation matrix from world space to camera space
    Matrix3 _mv;

    Camera(coord x, coord y, coord z, coord tox, coord toy, coord toz)
	:
	Vector3(x,y,z),
	_tox(tox), _toy(toy), _toz(toz)
    {
	UpdateMV();
    }

    Camera(const Vector3& from, const Vector3& to)
	:
	Vector3(from)
    {
	set(from._x, from._y, from._z, to._x, to._y, to._z);
    }

    void set(coord x, coord y, coord z, coord tox, coord toy, coord toz)
    {
	_x = x; _y = y; _z = z;
	_tox = tox; _toy = toy; _toz = toz;
	UpdateMV();
    }

    void set(const Vector3& from, const Vector3& to)
    {
	set(from._x, from._y, from._z, to._x, to._y, to._z);
    }

    void UpdateMV();
};

#endif

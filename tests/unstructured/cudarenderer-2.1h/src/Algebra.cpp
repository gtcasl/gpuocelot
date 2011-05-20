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

#include "Algebra.h"

Vector3 Matrix3::multiplyRightWith(const Vector3& r) const
{
    coord xnew = _row1._x*r._x + _row1._y*r._y + _row1._z*r._z;
    coord ynew = _row2._x*r._x + _row2._y*r._y + _row2._z*r._z;
    coord znew = _row3._x*r._x + _row3._y*r._y + _row3._z*r._z;
    return Vector3(xnew, ynew, znew);
}

Vector3 cross(const Vector3& l, const Vector3& r)
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

coord dot(const Vector3& l, const Vector3& r)
{
    return l._x*r._x +l._y*r._y +l._z*r._z;
}

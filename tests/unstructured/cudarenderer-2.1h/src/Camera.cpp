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

#include "Camera.h"

void Camera::UpdateMV()
{
    Vector3 eyeToLookatPoint(_tox-_x, _toy-_y, _toz-_z);
    eyeToLookatPoint.normalize();
    Vector3 zenith(0., 0., 1.);
    Vector3 rightAxis = cross(eyeToLookatPoint, zenith);
    rightAxis.normalize();
    Vector3 upAxis = cross(rightAxis, eyeToLookatPoint);
    upAxis.normalize();

    // Now that we have the three axes, create the transformation matrix
    // for this camera. The world coordinates must be xformed into the 
    // eye's view frustrum, located at _x,_y,_z and having the three axis 
    // that we just calc'ed

    _mv._row1 = upAxis;
    _mv._row2 = rightAxis;
    _mv._row3 = eyeToLookatPoint;
}

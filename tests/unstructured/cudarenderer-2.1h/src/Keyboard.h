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

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <config.h>

#include <SDL.h>

class Keyboard {
    Uint32 _isDown, _isUp, _isLeft, _isRight;
    Uint32 _isForward, _isBackward, _isLight, _isLight2;
    Uint32 _abortFlag, _isPgUp, _isPgDown;
    Uint32 _isS, _isD, _isE, _isF, _isR, _isH;
    Uint32 _isF4, _isF5, _isF6, _isF7, _isF8, _isF9;
public:
    Keyboard();
    ~Keyboard();

    void poll();
    Uint32 Down() { return _isDown; }
    Uint32 Up(){ return _isUp; }
    Uint32 Left() { return _isLeft; }
    Uint32 Right() { return _isRight; }
    Uint32 Forward() { return _isForward; }
    Uint32 Backward() { return _isBackward; }
    Uint32 Light() { return _isLight; }
    Uint32 Light2() { return _isLight2; }
    Uint32 Abort() { return _abortFlag; }
    Uint32 isS() { return _isS; }
    Uint32 isD() { return _isD; }
    Uint32 isE() { return _isE; }
    Uint32 isF() { return _isF; }
    Uint32 isR() { return _isR; }
    Uint32 isH() { return _isH; }
    Uint32 isPgDown() { return _isPgDown; }
    Uint32 isPgUp() { return _isPgUp; }
    Uint32 isF4() { return _isF4; }
    Uint32 isF5() { return _isF5; }
    Uint32 isF6() { return _isF6; }
    Uint32 isF7() { return _isF7; }
    Uint32 isF8() { return _isF8; }
    Uint32 isF9() { return _isF9; }
};

#endif

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

#include "Keyboard.h"

Keyboard::Keyboard()
{
    _isDown=_isUp=_isLeft=_isRight=_isPgUp=_isPgDown=_isS=_isD=_isE=_isF=
	_isR=_isH=_isForward=_isBackward=_isLight=_isLight2=_abortFlag=
	_isF4=_isF5=_isF6=_isF7=_isF8=_isF9=0;
}

Keyboard::~Keyboard()
{
}

void Keyboard::poll()
{
    SDL_Event event;

    if(SDL_PollEvent(&event)) {

        switch(event.type) {
        case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym) {
                case SDLK_UP: _isUp = 1; break;
                case SDLK_DOWN: _isDown = 1; break;
                case SDLK_LEFT: _isLeft = 1; break;
                case SDLK_RIGHT: _isRight = 1; break;
                case SDLK_a: _isForward = 1; break;
                case SDLK_z: _isBackward = 1; break;
                case SDLK_w: _isLight = 1; break;
                case SDLK_q: _isLight2 = 1; break;
                case SDLK_s: _isS = 1; break;
                case SDLK_d: _isD = 1; break;
                case SDLK_f: _isF = 1; break;
                case SDLK_e: _isE = 1; break;
                case SDLK_r: _isR = 1; break;
                case SDLK_h: _isH = 1; break;
                case SDLK_ESCAPE: _abortFlag = 1; break;
                case SDLK_PAGEDOWN: _isPgDown = 1; break;
                case SDLK_PAGEUP: _isPgUp = 1; break;
                case SDLK_F4: _isF4 = 1; break;
                case SDLK_F5: _isF5 = 1; break;
                case SDLK_F6: _isF6 = 1; break;
                case SDLK_F7: _isF7 = 1; break;
                case SDLK_F8: _isF8 = 1; break;
                case SDLK_F9: _isF9 = 1; break;
                default: break;
                }
            }
            break;
        case SDL_KEYUP:
            {
                switch(event.key.keysym.sym) {
                case SDLK_UP: _isUp = 0; break;
                case SDLK_DOWN: _isDown = 0; break;
                case SDLK_LEFT: _isLeft = 0; break;
                case SDLK_RIGHT: _isRight = 0; break;
                case SDLK_a: _isForward = 0; break;
                case SDLK_z: _isBackward = 0; break;
                case SDLK_w: _isLight = 0; break;
                case SDLK_q: _isLight2 = 0; break;
                case SDLK_s: _isS = 0; break;
                case SDLK_d: _isD = 0; break;
                case SDLK_f: _isF = 0; break;
                case SDLK_e: _isE = 0; break;
                case SDLK_r: _isR = 0; break;
                case SDLK_h: _isH = 0; break;
                case SDLK_ESCAPE: _abortFlag = 0; break;
                case SDLK_PAGEDOWN: _isPgDown = 0; break;
                case SDLK_PAGEUP: _isPgUp = 0; break;
                case SDLK_F4: _isF4 = 0; break;
                case SDLK_F5: _isF5 = 0; break;
                case SDLK_F6: _isF6 = 0; break;
                case SDLK_F7: _isF7 = 0; break;
                case SDLK_F8: _isF8 = 0; break;
                case SDLK_F9: _isF9 = 0; break;
                default: break;
                }
            }
            break;
        default:
            break;
        } // switch(event.type)
    } // if (SDL_PollEvent(...))
}

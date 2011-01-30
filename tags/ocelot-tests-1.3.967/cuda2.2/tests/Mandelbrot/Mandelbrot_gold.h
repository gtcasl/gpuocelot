#ifndef _MANDELBROT_GOLD_h_
#define _MANDELBROT_GOLD_h_

#include <vector_types.h>

extern "C" void RunMandelbrotGold0(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff, const float yOff, 
								   const float xJParam, const float yJParam, const float scale, const uchar4 colors, const int frame, const int animationFrame, const bool isJulia);
extern "C" void RunMandelbrotDSGold0(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, 
									 const double xJParam, const double yJParam, const double scale, const uchar4 colors, const int frame, const int animationFrame, const bool isJulia);
extern "C" void RunMandelbrotGold1(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff, const float yOff, 
								   const float xJParam, const float yJParam, const float scale, const uchar4 colors, const int frame, const int animationFrame, const bool isJulia);
extern "C" void RunMandelbrotDSGold1(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, 
									 const double xJParam, const double yJParam, const double scale, const uchar4 colors, const int frame, const int animationFrame, const bool isJulia);

#endif

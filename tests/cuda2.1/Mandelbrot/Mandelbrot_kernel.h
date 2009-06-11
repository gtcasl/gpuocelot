#ifndef _MANDELBROT_KERNAL_h_
#define _MANDELBROT_KERNAL_h_

#include <vector_types.h>

extern "C" void RunMandelbrot0_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double scale, const uchar4 colors, const int frame, const int animationFrame, const int mode);
extern "C" void RunMandelbrot1_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double scale, const uchar4 colors, const int frame, const int animationFrame, const int mode);

extern "C" void RunMandelbrot0_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double scale, const uchar4 colors, const int frame, const int animationFrame, const int mode, const int numSMs);
extern "C" void RunMandelbrot1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double scale, const uchar4 colors, const int frame, const int animationFrame, const int mode, const int numSMs);

#endif

/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */
 
#include "Mandelbrot_gold.h"

#define ABS(n) ((n) < 0 ? -(n) : (n))
typedef float dfloat[2];

// This function sets the DS number A equal to the double precision floating point number B. 
inline void dsdeq(dfloat a, double b)
{
    a[0] = (float)b;
    a[1] = (float)(b - a[0]);
} // dsdcp

// This function sets the DS number A equal to the DS number B. 
inline void dseq(dfloat a, const dfloat b)
{
    a[0] = b[0];
    a[1] = b[1];
} // dseq

// This function computes dsc = dsa + dsb.
inline void dsadd(dfloat dsc, const dfloat dsa, const dfloat dsb)
{
    // Compute dsa + dsb using Knuth's trick.
    float t1 = dsa[0] + dsb[0];
    float e = t1 - dsa[0];
    float t2 = ((dsb[0] - e) + (dsa[0] - (t1 - e))) + dsa[1] + dsb[1];

    // The result is t1 + t2, after normalization.
    dsc[0] = e = t1 + t2;
    dsc[1] = t2 - (e - t1);
} // dsadd

// This function computes dsc = dsa - dsb.
inline void dssub(dfloat dsc, const dfloat dsa, const dfloat dsb)
{
    // Compute dsa - dsb using Knuth's trick.
    float t1 = dsa[0] - dsb[0];
    float e = t1 - dsa[0];
    float t2 = ((-dsb[0] - e) + (dsa[0] - (t1 - e))) + dsa[1] - dsb[1];

    // The result is t1 + t2, after normalization.
    dsc[0] = e = t1 + t2;
    dsc[1] = t2 - (e - t1);
} // dssub

// This function multiplies DS numbers DSA and DSB to yield the DS product DSC.
inline void dsmul(dfloat dsc, const dfloat dsa, const dfloat dsb)
{
    // This splits dsa(1) and dsb(1) into high-order and low-order words.
    float c11 = dsa[0] * dsb[0];
    float c21 = dsa[0] * dsb[0] - c11;

    // Compute dsa[0] * dsb[1] + dsa[1] * dsb[0] (only high-order word is needed).
    float c2 = dsa[0] * dsb[1] + dsa[1] * dsb[0];

    // Compute (c11, c21) + c2 using Knuth's trick, also adding low-order product.
    float t1 = c11 + c2;
    float e = t1 - c11;
    float t2 = ((c2 - e) + (c11 - (t1 - e))) + c21 + dsa[1] * dsb[1];

    // The result is t1 + t2, after normalization.
    dsc[0] = e = t1 + t2;
    dsc[1] = t2 - (e - t1);
} // dsmul

// The core Mandelbrot calculation function
inline int CalcMandelbrot(const float xPos, const float yPos, const float xJParam, const float yJParam, const int crunch, 
						  const bool isJulia)
{
	float x, y, xx, yy, xC, yC ; 
	if(isJulia) {
		xC = xJParam ;
		yC = yJParam ;
		y = yPos;
		x = xPos;
		yy = y * y;
		xx = x * x;

	}
	else {
		xC = xPos ;
		yC = yPos ;
		y = 0 ;
		x = 0 ;
		yy = 0 ;
		xx = 0 ;
	}
    int i = crunch;

    while (--i && (xx + yy < 4.0f)) {
        y = x * y * 2.0f + yC ;
        x = xx - yy + xC ;
        yy = y * y;
        xx = x * x;
    }
    return i;
} // CalcMandelbrot

// The core Mandelbrot calculation function in double precision
inline int CalcMandelbrotDS(const dfloat xPos, const dfloat yPos, 
							const dfloat xJParam, const dfloat yJParam, const int crunch, const bool isJulia)
{
    dfloat x, y, xx, yy, sum;
    int i = crunch;

	dfloat xC, yC ;
	if(isJulia) {
		dseq(xC, xJParam) ;     // xC0 = xJParam ;
		dseq(yC, yJParam) ;     // yC0 = yJParam ;
		dseq(y, yPos);      // y = yPos;
		dseq(x, xPos);      // x = xPos;
		dsmul(yy, y, y);    // yy = y * y;
		dsmul(xx, x, x);	// xx = x * x;
		dsadd(sum, xx, yy); // sum = xx + yy;
	}
	else {
		dseq(xC, xPos) ;     // xC = xPos ;
		dseq(yC, yPos) ;     // yC = yPos ;
		dsdeq(y, 0.0) ;	// y = 0 ;
		dsdeq(x, 0.0) ;	// x = 0 ;
		dsdeq(yy, 0.0) ;   // yy = 0 ;
		dsdeq(xx, 0.0) ;   // xx = 0 ;
		dsdeq(sum, 0.0) ;   // sum = 0 ;
	}
    while (--i && (sum[0] < 4.0f)) {
        dsmul(y, x, y);     // y = x * y * 2.0f + yC ;
        dsadd(y, y, y);
        dsadd(y, y, yC);

        dssub(x, xx, yy);   //  x = xx - yy + xC ;
        dsadd(x, x, xC);

        dsmul(yy, y, y);    // yy = y * y;
        dsmul(xx, x, x);    // xx = x * x;
        dsadd(sum, xx, yy); // sum = xx + yy;
    }
    return i;
} // CalcMandelbrotDS

void RunMandelbrotGold0(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff, const float yOff, 
						const float xJParam, const float yJParam, const float scale, const uchar4 colors, const int frame, 
						const int animationFrame, const bool isJulia)
{
    for (int iy = 0; iy < imageH; iy++)
        for (int ix = 0; ix < imageW; ix++) {
		    // Calculate the location
		    const float xPos = (float)ix * scale + xOff;
		    const float yPos = (float)iy * scale + yOff;
    		      
            // Calculate the Mandelbrot index for the current location
            int m = CalcMandelbrot(xPos, yPos, xJParam, yJParam, crunch, isJulia) ;
            m = m > 0 ? crunch - m : 0;

            // Convert the Madelbrot index into a color
            uchar4 color;
            if (m) {
			    m += animationFrame;
			    color.x = m * colors.x;
			    color.y = m * colors.y;
			    color.z = m * colors.z;
		    } else {
			    color.x = 0;
			    color.y = 0;
			    color.z = 0;
		    }
    		
            // Output the pixel
 		    int pixel = imageW * iy + ix;
            if (frame == 0) {
			    color.w = 0;
			    dst[pixel] = color;
            } else {
			    int frame1 = frame + 1;
			    int frame2 = frame1 / 2;
			    dst[pixel].x = (dst[pixel].x * frame + color.x + frame2) / frame1;
			    dst[pixel].y = (dst[pixel].y * frame + color.y + frame2) / frame1;
			    dst[pixel].z = (dst[pixel].z * frame + color.z + frame2) / frame1;
            }
        }
} // RunMandelbrotGold0

void RunMandelbrotDSGold0(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, 
						  const double xJParam, const double yJParam, const double scale, const uchar4 colors, const int frame, 
						  const int animationFrame, const bool isJulia)
{
    for (int iy = 0; iy < imageH; iy++)
        for (int ix = 0; ix < imageW; ix++) {
		    // Calculate the location
		    const double xPos = (double)ix * scale + xOff;
		    const double yPos = (double)iy * scale + yOff;
    		dfloat dsx, dsy, djx, djy ;
            dsdeq(dsx, xPos);
            dsdeq(dsy, yPos);
            dsdeq(djx, xJParam) ;
            dsdeq(djy, yJParam);

            // Calculate the Mandelbrot index for the current location
            int m = CalcMandelbrotDS(dsx, dsy, djx, djy, crunch, isJulia);
            m = m > 0 ? crunch - m : 0;

            // Convert the Madelbrot index into a color
            uchar4 color;
            if (m) {
			    m += animationFrame;
			    color.x = m * colors.x;
			    color.y = m * colors.y;
			    color.z = m * colors.z;
		    } else {
			    color.x = 0;
			    color.y = 0;
			    color.z = 0;
		    }
    		
            // Output the pixel
 		    int pixel = imageW * iy + ix;
            if (frame == 0) {
			    color.w = 0;
			    dst[pixel] = color;
            } else {
			    int frame1 = frame + 1;
			    int frame2 = frame1 / 2;
			    dst[pixel].x = (dst[pixel].x * frame + color.x + frame2) / frame1;
			    dst[pixel].y = (dst[pixel].y * frame + color.y + frame2) / frame1;
			    dst[pixel].z = (dst[pixel].z * frame + color.z + frame2) / frame1;
            }
        }
} // RunMandelbrotDSGold0

// Determine if two pixel colors are within tolerance
inline int CheckColors(const uchar4 &color0, const uchar4 &color1)
{
	int x = color1.x - color0.x;
	int y = color1.y - color0.y;
	int z = color1.z - color0.z;
	return (ABS(x) > 10) || (ABS(y) > 10) || (ABS(z) > 10);
} // CheckColors

void RunMandelbrotGold1(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff, const float yOff, 
						const float xJParam, const float yJParam, const float scale, const uchar4 colors, const int frame, 
						const int animationFrame, const bool isJulia)
{
    for (int iy = 0; iy < imageH; iy++)
        for (int ix = 0; ix < imageW; ix++) {
		    // Get the current pixel color
 		    int pixel = imageW * iy + ix;
		    uchar4 pixelColor = dst[pixel];
		    int count = 0;
    		
		    // Search for pixels out of tolerance surrounding the current pixel
		    if (ix > 0)
			    count += CheckColors(pixelColor, dst[pixel - 1]);
		    if (ix + 1 < imageW)
			    count += CheckColors(pixelColor, dst[pixel + 1]);
		    if (iy > 0)
			    count += CheckColors(pixelColor, dst[pixel - imageW]);
		    if (iy + 1 < imageH)
			    count += CheckColors(pixelColor, dst[pixel + imageW]);
		    if (count) {
			    // Calculate the location
			    const float xPos = (float)ix * scale + xOff;
			    const float yPos = (float)iy * scale + yOff;
    			      
			    // Calculate the Mandelbrot index for the current location
			    int m = CalcMandelbrot(xPos, yPos, xJParam, yJParam, crunch, isJulia) ;
                m = m > 0 ? crunch - m : 0;
    	        
			    // Convert the Madelbrot index into a color
			    uchar4 color;
			    if (m) {
				    m += animationFrame;
				    color.x = m * colors.x;
				    color.y = m * colors.y;
				    color.z = m * colors.z;
			    } else {
				    color.x = 0;
				    color.y = 0;
				    color.z = 0;
			    }
    			
			    // Output the pixel
			    int frame1 = frame + 1;
			    int frame2 = frame1 / 2;
			    dst[pixel].x = (pixelColor.x * frame + color.x + frame2) / frame1;
			    dst[pixel].y = (pixelColor.y * frame + color.y + frame2) / frame1;
			    dst[pixel].z = (pixelColor.z * frame + color.z + frame2) / frame1;
		    }
        }
} // RunMandelbrotGold1

void RunMandelbrotDSGold1(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, 
						  const double xJParam, const double yJParam, const double scale, const uchar4 colors, const int frame, 
						  const int animationFrame, const bool isJulia)
{
    for (int iy = 0; iy < imageH; iy++)
        for (int ix = 0; ix < imageW; ix++) {
		    // Get the current pixel color
 		    int pixel = imageW * iy + ix;
		    uchar4 pixelColor = dst[pixel];
		    int count = 0;
    		
		    // Search for pixels out of tolerance surrounding the current pixel
		    if (ix > 0)
			    count += CheckColors(pixelColor, dst[pixel - 1]);
		    if (ix + 1 < imageW)
			    count += CheckColors(pixelColor, dst[pixel + 1]);
		    if (iy > 0)
			    count += CheckColors(pixelColor, dst[pixel - imageW]);
		    if (iy + 1 < imageH)
			    count += CheckColors(pixelColor, dst[pixel + imageW]);
		    if (count) {
			    // Calculate the location
				const double xPos = (double)ix * scale + xOff;
				const double yPos = (double)iy * scale + yOff;
				dfloat dsx, dsy, djx, djy ;
				dsdeq(dsx, xPos);
				dsdeq(dsy, yPos);
				dsdeq(djx, xJParam) ;
				dsdeq(djy, yJParam);

			    // Calculate the Mandelbrot index for the current location
			    int m = CalcMandelbrotDS(dsx, dsy, djx, djy, crunch, isJulia);
                m = m > 0 ? crunch - m : 0;
    	        
			    // Convert the Madelbrot index into a color
			    uchar4 color;
			    if (m) {
				    m += animationFrame;
				    color.x = m * colors.x;
				    color.y = m * colors.y;
				    color.z = m * colors.z;
			    } else {
				    color.x = 0;
				    color.y = 0;
				    color.z = 0;
			    }
    			
			    // Output the pixel
			    int frame1 = frame + 1;
			    int frame2 = frame1 / 2;
			    dst[pixel].x = (pixelColor.x * frame + color.x + frame2) / frame1;
			    dst[pixel].y = (pixelColor.y * frame + color.y + frame2) / frame1;
			    dst[pixel].z = (pixelColor.z * frame + color.z + frame2) / frame1;
		    }
        }
} // RunMandelbrotDSGold1

/*
 * Copyright 1993-2006 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.   
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.  This source code is a "commercial item" as 
 * that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer software" and "commercial computer software 
 * documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein.
 */

////////////////////////////////////////////////////////////////////////////////
// export C interface
extern "C" 
void computeGold(float *id, float *od, int w, int h, int r);

// CPU implementation
void hboxfilter_x(float *id, float *od, int w, int h, int r)
{
    float scale = 1.0f / (2*r+1);
    
    for (int y = 0; y < h; y++) {
    
        float t;
        // do left edge
        t = id[y*w] * r;
        for (int x = 0; x < r+1; x++) {
            t += id[y*w+x];
        }
        od[y*w] = t * scale;

        for(int x = 1; x < r+1; x++) {
            int c = y*w+x;
            t += id[c+r];
            t -= id[y*w];
            od[c] = t * scale;
        }
        
        // main loop
        for(int x = r+1; x < w-r; x++) {
            int c = y*w+x;
            t += id[c+r];
            t -= id[c-r-1];
            od[c] = t * scale;
        }

        // do right edge
        for (int x = w-r; x < w; x++) {
            int c = y*w+x;
            t += id[(y*w)+w-1];
            t -= id[c-r-1];
            od[c] = t * scale;
        }
        
    }
}

void hboxfilter_y(float *id, float *od, int w, int h, int r)
{
    float scale = 1.0f / (2*r+1);
    
    for (int x = 0; x < w; x++) {
    
        float t;
        // do left edge
        t = id[x] * r;
        for (int y = 0; y < r+1; y++) {
            t += id[y*w+x];
        }
        od[x] = t * scale;

        for(int y = 1; y < r+1; y++) {
            int c = y*w+x;
            t += id[c+r*w];
            t -= id[x];
            od[c] = t * scale;
        }
        
        // main loop
        for(int y = r+1; y < h-r; y++) {
            int c = y*w+x;
            t += id[c+r*w];
            t -= id[c-(r*w)-w];
            od[c] = t * scale;
        }

        // do right edge
        for (int y = h-r; y < h; y++) {
            int c = y*w+x;
            t += id[(h-1)*w+x];
            t -= id[c-(r*w)-w];
            od[c] = t * scale;
        }
        
    }
}

////////////////////////////////////////////////////////////////////////////////
//! Compute reference data set
//! @param image      pointer to input data
//! @param temp       pointer to temporary store
//! @param w          width of image
//! @param h          height of image
//! @param r          radius of filter
////////////////////////////////////////////////////////////////////////////////

void computeGold(float *image, float *temp, int w, int h, int r)
{
    hboxfilter_x(image, temp, w, h, r);
    hboxfilter_y(temp, image, w, h, r);
}

/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "bmp.h"

// This function takes an HSV value and converts it to BMP.
// We use this function to generate colored images with
// Smooth spectrum traversal for the input and output images.
RGB HSVtoRGB( float h, float s, float v )
{
    int i;
    float f, p, q, t;
    float r, g, b;
    RGB value={0,0,0};

    if( s == 0 ) {
        r = g = b = v;
        return value;
    }
    h /= 60;
    i = floor( h );
    f = h - i;
    p = v * ( 1 - s );
    q = v * ( 1 - s * f );
    t = v * ( 1 - s * ( 1 - f ) );
    switch( i ) {
        case 0:
            r = v; g = t; b = p;
            break;
        case 1:
            r = q; g = v; b = p;
            break;
        case 2:
            r = p; g = v; b = t;
            break;
        case 3:
            r = p; g = q; b = v;
            break;
        case 4:
            r = t; g = p; b = v;
            break;
        default:
            r = v; g = p; b = q;
            break;
    }

    unsigned int temp = r*255;
    value.R = temp;
    temp = g*255;
    value.G = temp;
    temp = b*255;
    value.B = temp;

    return value;
}

void dump_histo_img(unsigned char* histo, unsigned int height, unsigned int width, const char *filename)
{
    RGB* pixel_map = (RGB*) malloc (height*width*sizeof(RGB));

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            unsigned char value = histo[y * width + x];

            if (value == 0){
                pixel_map[y*width+x].R = 0;
                pixel_map[y*width+x].G = 0;
                pixel_map[y*width+x].B = 0;
            } else {
                pixel_map[y*width+x] = HSVtoRGB(0.0,1.0,cbrt(1+ 63.0*((float)value)/((float)UINT8_MAX))/4);
            }
        }
    }
    create_bmp(pixel_map, height, width, filename);
    free(pixel_map);
}

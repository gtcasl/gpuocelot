/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  Users and possessors of this source code
 * are hereby granted a nonexclusive, royalty-free license to use this code
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 *
 * U.S. Government End Users.   This source code is a "commercial item" as
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
 * "commercial computer  software"  and "commercial computer software
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
 * and is provided to the U.S. Government only as a commercial end item.
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
 * source code with only those rights set forth herein.
 *
 * Any use of this source code in individual and commercial software must
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */


#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#   pragma warning( disable : 4996 ) // disable deprecated warning 
#endif

#pragma pack(1)

typedef struct{
    short type;
    int size;
    short reserved1;
    short reserved2;
    int offset;
} BMPHeader;

typedef struct{
    int size;
    int width;
    int height;
    short planes;
    short bitsPerPixel;
    unsigned compression;
    unsigned imageSize;
    int xPelsPerMeter;
    int yPelsPerMeter;
    int clrUsed;
    int clrImportant;
} BMPInfoHeader;



//Isolated definition
typedef struct{
    unsigned char x, y, z, w;
} uchar4;



extern "C" void LoadBMPFile(uchar4 **dst, int *width, int *height, const char *name){
    BMPHeader hdr;
    BMPInfoHeader infoHdr;
    int x, y;

    FILE *fd;


    printf("Loading %s...\n", name);
    if(sizeof(uchar4) != 4){
        printf("***Bad uchar4 size***\n");
        exit(0);
    }

    if( !(fd = fopen(name,"rb")) ){
        printf("***BMP load error: file access denied***\n");
        exit(0);
    }

    fread(&hdr, sizeof(hdr), 1, fd);
    if(hdr.type != 0x4D42){
        printf("***BMP load error: bad file format***\n");
        exit(0);
    }
    fread(&infoHdr, sizeof(infoHdr), 1, fd);

    if(infoHdr.bitsPerPixel != 24){
        printf("***BMP load error: invalid color depth***\n");
        exit(0);
    }

    if(infoHdr.compression){
        printf("***BMP load error: compressed image***\n");
        exit(0);
    }

    *width  = infoHdr.width;
    *height = infoHdr.height;
    *dst    = (uchar4 *)malloc(*width * *height * 4);

    printf("BMP width: %u\n", infoHdr.width);
    printf("BMP height: %u\n", infoHdr.height);

    fseek(fd, hdr.offset - sizeof(hdr) - sizeof(infoHdr), SEEK_CUR);

    for(y = 0; y < infoHdr.height; y++){
        for(x = 0; x < infoHdr.width; x++){
            (*dst)[(y * infoHdr.width + x)].z = fgetc(fd);
            (*dst)[(y * infoHdr.width + x)].y = fgetc(fd);
            (*dst)[(y * infoHdr.width + x)].x = fgetc(fd);
        }

        for(x = 0; x < (4 - (3 * infoHdr.width) % 4) % 4; x++)
            fgetc(fd);
    }


    if(ferror(fd)){
        printf("***Unknown BMP load error.***\n");
        free(*dst);
        exit(0);
    }else
        printf("BMP file loaded successfully!\n");

    fclose(fd);
}

/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include "stdio.h"
#include "stdlib.h"

typedef struct{
  unsigned char B;
  unsigned char G;
  unsigned char R;
} RGB;

typedef struct {
  unsigned int filesz;
  unsigned short creator1;
  unsigned short creator2;
  unsigned int bmp_offset;
} bmpfile_header_t;

typedef struct {
  unsigned int header_sz;
  unsigned int width;
  unsigned int height;
  unsigned short nplanes;
  unsigned short bitspp;
  unsigned int compress_type;
  unsigned int bmp_bytesz;
  unsigned int hres;
  unsigned int vres;
  unsigned int ncolors;
  unsigned int nimpcolors;
} bmp_dib_header_t;

typedef enum {
  BI_RGB = 0,
  BI_RLE8,
  BI_RLE4,
  BI_BITFIELDS,
  BI_JPEG,
  BI_PNG,
} bmp_compression_method_t;

typedef struct{
  unsigned char magic[2];
  bmpfile_header_t file_header;
  bmp_dib_header_t dib_header;
  unsigned int* palette;
  void* pixel_map;
} bmp_image;

void create_bmp(RGB* bitmap, int height, int width, const char* filename){
    bmp_image image;

    int padded_width = 4*(((width*24)+31)/32);
    padded_width -= width*sizeof(RGB);

    char* pad = (char*) calloc (padded_width, sizeof(char));

    image.magic[0]='B';
    image.magic[1]='M';

    image.file_header.filesz = 2*sizeof(char) + sizeof(bmpfile_header_t) + sizeof(bmp_dib_header_t) + height*width*sizeof(RGB);
    image.file_header.creator1 = image.file_header.creator2 = 0;
    image.file_header.bmp_offset = 2*sizeof(char) + sizeof(bmpfile_header_t) + sizeof(bmp_dib_header_t);

    image.dib_header.header_sz = 40;//sizeof(bmp_dib_header_t);
    image.dib_header.width = width;
    image.dib_header.height = height;
    image.dib_header.nplanes = 1;
    image.dib_header.bitspp = 24;
    image.dib_header.compress_type = 0;
    image.dib_header.bmp_bytesz = width*height*sizeof(RGB);
    image.dib_header.hres = 0;
    image.dib_header.vres = 0;
    image.dib_header.ncolors = 0;
    image.dib_header.nimpcolors = 0;

    FILE* out_file = fopen(filename,"wb");

    fwrite(image.magic,sizeof(char),2,out_file);
    fwrite(&(image.file_header),sizeof(char),sizeof(bmpfile_header_t),out_file);
    fwrite(&(image.dib_header),sizeof(char),sizeof(bmp_dib_header_t),out_file);

    int h;
    for (h = height-1; h >= 0; h--){
      fwrite(&bitmap[h*width],sizeof(RGB),width,out_file);
      fwrite(pad,sizeof(char),padded_width,out_file);
    }

    fclose(out_file);
}

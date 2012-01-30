/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#define KB                      24
#define BINS_PER_BLOCK          (KB * 1024)
#define BLOCK_X         14

#define PRESCAN_THREADS     512
#define PRESCAN_BLOCKS_X    64

#if KB == 24
        #define THREADS         768
#elif KB == 48
        #define THREADS         1024
#else //KB == 16 or other
        #define THREADS         512
#endif

#define UNROLL 16
#define UINT8_MAX 255
#define UINT32_MAX 4294967295

void dump_histo_img(unsigned char* histo, unsigned int height, unsigned int width, const char *filename);

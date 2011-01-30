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

/**
**************************************************************************
* \file BmpUtil.h
* \brief Contains basic image operations declaration.
*
* This file contains declaration of basic bitmap loading, saving, 
* conversions to different representations and memory management routines.
*/

#pragma once

#ifdef _WIN32
    #pragma pack(push)
#endif

#pragma pack(1)

typedef char                            int8;
typedef short                           int16;
typedef int                             int32;
typedef unsigned char                   uint8;
typedef unsigned short                  uint16;
typedef unsigned int                    uint32;

/**
* \brief Bitmap file header structure
*
*  Bitmap file header structure
*/
typedef struct
{
	uint16 _bm_signature;					//!< File signature, must be "BM"
	uint32 _bm_file_size;					//!< File size
	uint32 _bm_reserved;					//!< Reserved, must be zero
	uint32 _bm_bitmap_data;				//!< Bitmap data
} BMPFileHeader;


/**
* \brief Bitmap info header structure
*
*  Bitmap info header structure
*/
typedef struct
{
	uint32 _bm_info_header_size;			//!< Info header size, must be 40
	uint32 _bm_image_width;				//!< Image width
	uint32 _bm_image_height;				//!< Image height
	uint16 _bm_num_of_planes;				//!< Amount of image planes, must be 1
	uint16 _bm_color_depth;				//!< Color depth
	uint32 _bm_compressed;				//!< Image compression, must be none
	uint32 _bm_bitmap_size;				//!< Size of bitmap data
	uint32 _bm_hor_resolution;			//!< Horizontal resolution, assumed to be 0
	uint32 _bm_ver_resolution;			//!< Vertical resolution, assumed to be 0
	uint32 _bm_num_colors_used;			//!< Number of colors used, assumed to be 0
	uint32 _bm_num_important_colors;		//!< Number of important colors, assumed to be 0
} BMPInfoHeader;


#ifdef _WIN32
    #pragma pack(pop)
#endif


/**
* \brief Simple 2D size / region_of_interest structure
*
*  Simple 2D size / region_of_interest structure
*/
typedef struct  
{
	int width;			//!< ROI width
	int height;			//!< ROI height
} ROI;


/**
*  One-byte unsigned integer type
*/
typedef unsigned char byte;


extern "C" 
{
	int clamp_0_255(int x);
	float round_f(float num);
	byte *MallocPlaneByte(int width, int height, int *pStepBytes);
	short *MallocPlaneShort(int width, int height, int *pStepBytes);
	float *MallocPlaneFloat(int width, int height, int *pStepBytes);
	void CopyByte2Float(byte *ImgSrc, int StrideB, float *ImgDst, int StrideF, ROI Size);
	void CopyFloat2Byte(float *ImgSrc, int StrideF, byte *ImgDst, int StrideB, ROI Size);
	void FreePlane(void *ptr);
	void AddFloatPlane(float Value, float *ImgSrcDst, int StrideF, ROI Size);
	void MulFloatPlane(float Value, float *ImgSrcDst, int StrideF, ROI Size);
	int PreLoadBmp(char *FileName, int *Width, int *Height);
	void LoadBmpAsGray(char *FileName, int Stride, ROI ImSize, byte *Img);
	void DumpBmpAsGray(char *FileName, byte *Img, int Stride, ROI ImSize);
	void DumpBlockF(float *PlaneF, int StrideF, char *Fname);
	void DumpBlock(byte *Plane, int Stride, char *Fname);
	float CalculateMSE(byte *Img1, byte *Img2, int Stride, ROI Size);
	float CalculatePSNR(byte *Img1, byte *Img2, int Stride, ROI Size);
}

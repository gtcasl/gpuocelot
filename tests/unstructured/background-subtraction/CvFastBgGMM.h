///////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Implementation on CUDA of the Gaussian mixture model background subtraction from:
//
//  "GPU implementation of GMM for Background Subtraction"
//  Vu Pham, Phong Vo, Vu Thanh Hung, Le Hoai Bac
//  IEEE-RIVF, Nov 2010
//
//  This is the GPU implementation of Zivkovic's algorithm. For more details:
//
//  "Efficient Adaptive Density Estimation per Image Pixel for the Task of Background Subtraction"
//  Z.Zivkovic, F. van der Heijden 
//  Pattern Recognition Letters, vol. 27, no. 7, pages 773-780, 2006.
//
//  and
//
//  "Recursive unsupervised learning of finite mixture models "
//  Z.Zivkovic, F.van der Heijden 
//  IEEE Trans. on Pattern Analysis and Machine Intelligence, vol.26, no.5, pages 651-656, 2004 
//
//
//  Author: Vu Pham, http://phvureseach.wordpress.com
//  University of Science, Ho Chi Minh City, Viet Nam
//  Date: 28-August-2010, Version: 0.9
//
/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Usage:
//
//  CvFastBgGMMParams* params = cvCreateFastBgGMMParams(FRAME_WIDTH, FRAME_HEIGHT);
//  // modify some parameters in params struct here... 
//  CvFastBgGMM* gmm = cvCreateFastBgGMM(params, frame0, frame1, frame2)
//  // use 3 first frames to initialize
//
//  for each new frame...
//  cvUpdateFastBgGMM(gmm, new_frame);
//  or use the following function to get the processing time:
//  float time = cvUpdateFastBgGMMTimer(gmm, new_frame);
//
//  Finally, call cvReleaseFastBgGMM() to release the memory
//  cvReleaseFastBgGMM(&gmm);
//  delete params;
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CV_FASTBGGMM_1FDF3B87_918D_42ef_97B8_249FE74AD689
#define CV_FASTBGGMM_1FDF3B87_918D_42ef_97B8_249FE74AD689

#if _MSC_VER > 1000
#pragma once
#endif

#include <stdlib.h>
#include <memory.h>

#include <cuda_runtime.h>


//////////////////////////////////////////////////////////////////////////////////////////
//
//  CUDAGMM versions:
//  1: __constant__ device memory
//  2: memory coalescing on input image (4-channels input), output image, usedModes array
//  3: SoA: Structure of arrays, pinned memory when transfer input/output frame,
//  	  memory coalescing on SoA (Gaussian data)
//  4: asynchronous execution
//  5: template kernel function <- nearly useless since we 'template' on the BLOCK_SIZE.
//
//  We only have 3, 4, 5 here.
//
//////////////////////////////////////////////////////////////////////////////////////
#define CUDAGMM_VERSION 5

#ifdef _DEBUG
#define	CUDAGMM_SAFE_CALL(x)	CUDA_SAFE_CALL(x)
#else
#define	CUDAGMM_SAFE_CALL(x)	x
#endif

enum ImageInfo
{
#if(CUDAGMM_VERSION >= 2)
	ImageInfoPixelCount = 0,		//
	ImageInfoPixelsPerThread = 1,	//
	ImageInfoCount = 2
#else
	ImageInfoInpWidth = 0,
	ImageInfoInpHeight = 1,
	ImageInfoInpWidthStep = 2,
	ImageInfoOutWidth = 3,
	ImageInfoOutHeight = 4,
	ImageInfoOutWidthStep = 5,
	ImageInfoPixelCount = 6,		//
	ImageInfoPixelsPerThread = 7,	//
	ImageInfoCount = 8
#endif
};

// algorithm parameters
typedef struct CvFastBgGMMParams
{
	/////////////////////////
	//very important parameters - things you will change
	////////////////////////
	float fAlphaT;
	//alpha - speed of update - if the time interval you want to average over is T
	//set alpha=1/T. It is also useful at start to make T slowly increase
	//from 1 until the desired T
	float fTb;
	//Tb - threshold on the squared Mahalan. dist. to decide if it is well described
	//by the background model or not. Related to Cthr from the paper.
	//This does not influence the update of the background. A typical value could be 4 sigma
	//and that is Tb=4*4=16;

	/////////////////////////
	//less important parameters - things you might change but be carefull
	////////////////////////
	float fTg;
	//Tg - threshold on the squared Mahalan. dist. to decide 
	//when a sample is close to the existing components. If it is not close
	//to any a new component will be generated. I use 3 sigma => Tg=3*3=9.
	//Smaller Tg leads to more generated components and higher Tg might make
	//lead to small number of components but they can grow too large
	float fTB;//1-cf from the paper
	//TB - threshold when the component becomes significant enough to be included into
	//the background model. It is the TB=1-cf from the paper. So I use cf=0.1 => TB=0.
	//For alpha=0.001 it means that the mode should exist for approximately 105 frames before
	//it is considered foreground
	float fSigma;
	//initial standard deviation  for the newly generated components. 
	//It will will influence the speed of adaptation. A good guess should be made. 
	//A simple way is to estimate the typical standard deviation from the images.
	//I used here 10 as a reasonable value
	float fCT;//CT - complexity reduction prior
	//this is related to the number of samples needed to accept that a component
	//actually exists. We use CT=0.05 of all the samples. By setting CT=0 you get
	//the standard Stauffer&Grimson algorithm (maybe not exact but very similar)

	//even less important parameters
	int nM;//max number of modes - const - 4 is usually enough

	//shadow detection parameters
	int bShadowDetection;//do shadow detection
	float fTau;
	// Tau - shadow threshold. The shadow is detected if the pixel is darker
	//version of the background. Tau is a threshold on how much darker the shadow can be.
	//Tau= 0.5 means that if pixel is more than 2 times darker then it is not shadow
	//See: Prati,Mikic,Trivedi,Cucchiarra,"Detecting Moving Shadows...",IEEE PAMI,2003.

	float fPrune;	//=-m_fAlphaT*m_fCT;

	//data
	int nNBands;//only RGB now ==3
	int nWidth;//image size
	int nHeight;
	int nSize;
	int bRemoveForeground;
} CvFastBgGMMParams;

// calculation data
#if(CUDAGMM_VERSION >= 3)

typedef struct CvFastBgGMMData
{
	float4* ucGaussian;
	float* rWeight;
	int* rnUsedModes;

} CvFastBgGMMData;

#else

typedef struct CvFastBgGMMData
{
	float* rSigma;
	float* rMuR;
	float* rMuG;
	float* rMuB;
	float* rWeight;

	//number of Gaussian components per pixel
	int* rnUsedModes;
} CvFastBgGMMData;

#endif

typedef struct CvFastBgGMM
{
#	if(CUDAGMM_VERSION >= 2)

	// the 4-channels input image
	IplImage* inputFrame;

#	endif

	// the output image
	IplImage* h_outputImg;

	// on device memory, just for fast data transfer
	unsigned char* d_outputImg;
	int nOutputImgSize;
	unsigned char* d_inputImg;
	int nInputImgSize;

	// for deallocation only.
	CvFastBgGMMData* internal_data;

	// number of threads per block
	// this will be determine automatically.
	// You SHOULD NOT modify it manually.
	int nThreadsPerBlock;

	// number of blocks per grid
	// this will be determine automatically.
	// You SHOULD NOT modify it manually.
	int nBlocksPerGrid;

#	if(CUDAGMM_VERSION >= 3)
	
	// Page-locked host memory
	unsigned char* h_pinnedIn;
	unsigned char* h_pinnedOut;

	cudaStream_t copyStream;

#	endif

#	if(CUDAGMM_VERSION >= 4)
	
	// CUDA streams
	cudaStream_t execStream;

	// double buffer
	unsigned char* d_outputImg2;
	unsigned char* d_inputImg2;

#	endif

} CvFastBgGMM;

////////////////
//
//  Input:
//	  pGMM - a pointer to an already initialized GMM
//    data - a pointer to an OpenCV 3-channels image
//  Output:
//    pGMM->h_outputImg - an OpenCV single channel image
//    values: 255-foreground, 125-shadow, 0-background
///////////

void cvUpdateFastBgGMM(CvFastBgGMM* pGMM, IplImage* inputImg);

//  This is the same with cvUpdateFastBgGMM
//  Return the time running the algorithm, measured by CUDA's utilities
////////////
float cvUpdateFastBgGMMTimer(CvFastBgGMM* pGMM, IplImage* inputImg);

//  Initialize an GMM structure.
//  Input: width and height of video frames.
///////////
CvFastBgGMMParams* cvCreateFastBgGMMParams(int width, int height);

CvFastBgGMM* cvCreateFastBgGMM(CvFastBgGMMParams* pGMMParams, IplImage* initFrame);

void cvReleaseFastBgGMM(CvFastBgGMM** h_ppGMM);

#endif

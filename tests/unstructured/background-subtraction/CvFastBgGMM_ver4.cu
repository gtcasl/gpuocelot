#include <stdlib.h>
#include "CvFastBgGMM.h"

#if(CUDAGMM_VERSION == 4)

#define SWAP(a, b, t)	t = (a); a = (b); b = (t)

__constant__ CvFastBgGMMParams d_GMMParams;
__constant__ CvFastBgGMMData d_GMMData;
__constant__ int d_arrImageInfo[ImageInfoCount];

/*====================================================================================*/
// forward declarations
/*====================================================================================*/

int InitCUDA(CvFastBgGMM* pGMM);
__global__ void cudaUpdateFastBgGMM(unsigned char* data, unsigned char* output);

/*====================================================================================*/

/*====================================================================================*/

CvFastBgGMMParams* cvCreateFastBgGMMParams(int width, int height)
{
	CvFastBgGMMParams* pGMMParams = new CvFastBgGMMParams();

	int size = width*height;
	pGMMParams->nWidth = width;
	pGMMParams->nHeight = height;
	pGMMParams->nSize = size;

	pGMMParams->nNBands=3;	//always 3 - not implemented for other values!

	//set parameters
	// K - max number of Gaussians per pixel
	pGMMParams->nM = 4;			
	// Tb - the threshold - n var
	pGMMParams->fTb = 4*4;
	// Tbf - the threshold
	pGMMParams->fTB = 0.9f;//1-cf from the paper 
	// Tgenerate - the threshold
	pGMMParams->fTg = 3.0f*3.0f;//update the mode or generate new
	pGMMParams->fSigma= 11.0f;//sigma for the new mode
	// alpha - the learning factor
	pGMMParams->fAlphaT=0.001f;
	// complexity reduction prior constant
	pGMMParams->fCT=0.05f;

	//shadow
	// Shadow detection
	pGMMParams->bShadowDetection = 0;//turn on
	pGMMParams->fTau = 0.5f;// Tau - shadow threshold

	pGMMParams->bRemoveForeground = 0;
	return pGMMParams;
}
/*====================================================================================*/

/*====================================================================================*/

template <bool toPinned>
void copyImageData(IplImage* h_img, unsigned char* d_pinnedMem, int channels)
{
	if(h_img->widthStep == channels*h_img->width)
	{
		memcpy(
			toPinned ? (d_pinnedMem) : (unsigned char*)(h_img->imageData), 
			toPinned ? (unsigned char*)(h_img->imageData) : (d_pinnedMem),
			h_img->widthStep*h_img->height);
	}
	else
	{
		unsigned char* d_curData = d_pinnedMem;
		if(toPinned)
		{
			for(int i = 0; i < h_img->height; ++i)
			{
				memcpy(
					d_curData,
					&CV_IMAGE_ELEM(h_img, unsigned char, i, 0),
					channels*h_img->width);
				d_curData += (channels*h_img->width);
			}
		}
		else
		{
			for(int i = 0; i < h_img->height; ++i)
			{
				memcpy(
					&CV_IMAGE_ELEM(h_img, unsigned char, i, 0),
					d_curData,
					channels*h_img->width);
				d_curData += (channels*h_img->width);
			}
		}
	}
}

/*====================================================================================*/

/*====================================================================================*/

CvFastBgGMM* cvCreateFastBgGMM(CvFastBgGMMParams* pGMMParams, IplImage* frame0)
{
	CvFastBgGMM* h_pGMMRet = new CvFastBgGMM();

	if(InitCUDA(h_pGMMRet) < 0)
	{
		delete h_pGMMRet;
		return NULL;
	}

	CvFastBgGMMData* h_pGMMData = new CvFastBgGMMData();

	// allocate device global memory
	int iElemCount = pGMMParams->nSize * pGMMParams->nM * sizeof(float);
	int iSizeCount = pGMMParams->nSize * sizeof(int);

	CUDAGMM_SAFE_CALL(cudaMalloc((void**)&(h_pGMMData->ucGaussian), 4*iElemCount));
	CUDAGMM_SAFE_CALL(cudaMalloc((void**)&(h_pGMMData->rWeight), iElemCount));
	CUDAGMM_SAFE_CALL(cudaMalloc((void**)&(h_pGMMData->rnUsedModes), iSizeCount));
	CUDAGMM_SAFE_CALL(cudaMemset(h_pGMMData->rnUsedModes, 0, iSizeCount));

	CUDAGMM_SAFE_CALL(cudaMemcpyToSymbol(d_GMMData, h_pGMMData, sizeof(CvFastBgGMMData), 0, cudaMemcpyHostToDevice));

	h_pGMMRet->internal_data = h_pGMMData;

	// we will use 4-channels image as input data!
	h_pGMMRet->inputFrame = cvCreateImage(cvSize(pGMMParams->nWidth, pGMMParams->nHeight), IPL_DEPTH_8U, 4);
	h_pGMMRet->nInputImgSize = 4 * frame0->width *  pGMMParams->nHeight;
	CUDAGMM_SAFE_CALL(cudaMalloc((void**)&(h_pGMMRet->d_inputImg), h_pGMMRet->nInputImgSize));
	h_pGMMRet->h_outputImg = cvCreateImage(cvSize(pGMMParams->nWidth, pGMMParams->nHeight), IPL_DEPTH_8U, 1);
	h_pGMMRet->nOutputImgSize = pGMMParams->nWidth *  pGMMParams->nHeight;
	CUDAGMM_SAFE_CALL(cudaMalloc((void**)&(h_pGMMRet->d_outputImg), h_pGMMRet->nOutputImgSize));
	
	// d_arrImageInfo constant (device mem.)
	int inpPixelCnt = pGMMParams->nWidth * pGMMParams->nHeight;

	// number of pixels per thread must be 4k, i.e. 4, 8, 12, 16, 20...
	int iPixelsPerThread = min(32, (int)ceil(inpPixelCnt *1.0 / (h_pGMMRet->nBlocksPerGrid * h_pGMMRet->nThreadsPerBlock)));
	iPixelsPerThread = 4*(int)ceil(iPixelsPerThread/4.0f);
	h_pGMMRet->nBlocksPerGrid = (int)ceil(inpPixelCnt*1.0 / ((h_pGMMRet->nThreadsPerBlock) * iPixelsPerThread));

	printf("%d pixels/thread, %d threads/block, %d blocks\r\n", 
		iPixelsPerThread, h_pGMMRet->nThreadsPerBlock, h_pGMMRet->nBlocksPerGrid);

	int arrImgInfo[ImageInfoCount] = {	inpPixelCnt, iPixelsPerThread };
	CUDAGMM_SAFE_CALL(cudaMemcpyToSymbol(d_arrImageInfo, arrImgInfo, ImageInfoCount*sizeof(int),
		0, cudaMemcpyHostToDevice));

	CUDAGMM_SAFE_CALL(cudaStreamCreate(&(h_pGMMRet->copyStream)));
	CUDAGMM_SAFE_CALL(cudaStreamCreate(&(h_pGMMRet->execStream)));

	// cudaHostAllocMapped might fail
	CUDAGMM_SAFE_CALL(cudaHostAlloc((void**)&(h_pGMMRet->h_pinnedIn), 
		h_pGMMRet->nInputImgSize, cudaHostAllocWriteCombined));
	CUDAGMM_SAFE_CALL(cudaHostAlloc((void**)&(h_pGMMRet->h_pinnedOut), 
		h_pGMMRet->nOutputImgSize, cudaHostAllocDefault));
	CUDAGMM_SAFE_CALL(cudaMalloc((void**)&(h_pGMMRet->d_inputImg2), h_pGMMRet->nInputImgSize));
	CUDAGMM_SAFE_CALL(cudaMalloc((void**)&(h_pGMMRet->d_outputImg2), h_pGMMRet->nOutputImgSize));

	// copy the algorithm parameters to Constant memory
	pGMMParams->fPrune = -(pGMMParams->fAlphaT) * (pGMMParams->fCT);
	CUDAGMM_SAFE_CALL(cudaMemcpyToSymbol(d_GMMParams, pGMMParams, sizeof(CvFastBgGMMParams),
		0, cudaMemcpyHostToDevice));

	// setup the initial state for asynchronous execution
	cvCvtColor(frame0, h_pGMMRet->inputFrame, CV_BGR2BGRA);
	copyImageData<true>(h_pGMMRet->inputFrame, h_pGMMRet->h_pinnedIn, 4);
	CUDAGMM_SAFE_CALL(cudaMemcpy(h_pGMMRet->d_inputImg2, h_pGMMRet->h_pinnedIn, h_pGMMRet->nInputImgSize, cudaMemcpyHostToDevice));
	cudaUpdateFastBgGMM<<< (h_pGMMRet->nBlocksPerGrid), (h_pGMMRet->nThreadsPerBlock), 4, h_pGMMRet->execStream >>>
		( h_pGMMRet->d_inputImg2, h_pGMMRet->d_outputImg2 );

	CUDAGMM_SAFE_CALL(cudaMemcpyAsync(h_pGMMRet->d_inputImg, h_pGMMRet->h_pinnedIn, h_pGMMRet->nInputImgSize, 
		cudaMemcpyHostToDevice, h_pGMMRet->copyStream));
	CUDAGMM_SAFE_CALL(cudaStreamSynchronize(h_pGMMRet->execStream));
	CUDAGMM_SAFE_CALL(cudaMemcpy(h_pGMMRet->h_pinnedOut, h_pGMMRet->d_outputImg2, h_pGMMRet->nOutputImgSize, cudaMemcpyDeviceToHost));

	CUDAGMM_SAFE_CALL(cudaStreamSynchronize(h_pGMMRet->copyStream));
	cudaUpdateFastBgGMM<<< (h_pGMMRet->nBlocksPerGrid), (h_pGMMRet->nThreadsPerBlock), 4, h_pGMMRet->execStream >>>
		( h_pGMMRet->d_inputImg, h_pGMMRet->d_outputImg );

	CUDAGMM_SAFE_CALL(cudaMemcpyAsync(h_pGMMRet->d_inputImg2, h_pGMMRet->h_pinnedIn, h_pGMMRet->nInputImgSize, 
		cudaMemcpyHostToDevice, h_pGMMRet->copyStream));

	return h_pGMMRet;
}

/*====================================================================================*/

/*====================================================================================*/

void cvReleaseFastBgGMM(CvFastBgGMM** h_ppGMM)
{
	CvFastBgGMM* h_pGMM = *h_ppGMM;

	cvReleaseImage(&(h_pGMM->h_outputImg));
	cvReleaseImage(&(h_pGMM->inputFrame));
	CUDAGMM_SAFE_CALL( cudaStreamSynchronize(h_pGMM->copyStream));
	CUDAGMM_SAFE_CALL( cudaStreamSynchronize(h_pGMM->execStream));
	CUDAGMM_SAFE_CALL( cudaFree(h_pGMM->d_inputImg));
	CUDAGMM_SAFE_CALL( cudaFree(h_pGMM->d_outputImg));
	CUDAGMM_SAFE_CALL( cudaFree(h_pGMM->d_inputImg2));
	CUDAGMM_SAFE_CALL( cudaFree(h_pGMM->d_outputImg2));
	CUDAGMM_SAFE_CALL( cudaFreeHost(h_pGMM->h_pinnedIn));
	CUDAGMM_SAFE_CALL( cudaFreeHost(h_pGMM->h_pinnedOut));
	CUDAGMM_SAFE_CALL( cudaStreamDestroy(h_pGMM->copyStream));
	CUDAGMM_SAFE_CALL( cudaStreamDestroy(h_pGMM->execStream));

	CvFastBgGMMData* h_pGMMData = h_pGMM->internal_data;
	CUDAGMM_SAFE_CALL( cudaFree(h_pGMMData->ucGaussian));
	CUDAGMM_SAFE_CALL( cudaFree(h_pGMMData->rWeight));
	CUDAGMM_SAFE_CALL( cudaFree(h_pGMMData->rnUsedModes));
	
	delete h_pGMM->internal_data;
	delete h_pGMM;
	(*h_ppGMM) = 0;
}

/*====================================================================================*/

/*====================================================================================*/

void cvUpdateFastBgGMM(CvFastBgGMM* pGMM, IplImage* inputImg)
{
	cvCvtColor(inputImg, pGMM->inputFrame, CV_BGR2BGRA);
	CUDAGMM_SAFE_CALL(cudaStreamSynchronize(pGMM->copyStream));
	copyImageData<true>(pGMM->inputFrame, pGMM->h_pinnedIn, 4);
	copyImageData<false>(pGMM->h_outputImg, pGMM->h_pinnedOut, 1);
	
	CUDAGMM_SAFE_CALL(cudaStreamSynchronize(pGMM->execStream));
	unsigned char* pTmp;
	SWAP(pGMM->d_inputImg, pGMM->d_inputImg2, pTmp);
	SWAP(pGMM->d_outputImg, pGMM->d_outputImg2, pTmp);

	CUDAGMM_SAFE_CALL(cudaMemcpyAsync(pGMM->d_inputImg, pGMM->h_pinnedIn, pGMM->nInputImgSize, cudaMemcpyHostToDevice, pGMM->copyStream));
	CUDAGMM_SAFE_CALL(cudaMemcpyAsync(pGMM->h_pinnedOut, pGMM->d_outputImg, pGMM->nOutputImgSize, cudaMemcpyDeviceToHost, pGMM->copyStream));

	cudaUpdateFastBgGMM<<< (pGMM->nBlocksPerGrid), (pGMM->nThreadsPerBlock), 4, pGMM->execStream >>>
		( pGMM->d_inputImg2, pGMM->d_outputImg2 );

#ifdef _DEBUG
	cudaError_t error = cudaGetLastError();
	if(error != cudaSuccess)
	{
		printf("CUDA error: %d: %s\r\n", error, cudaGetErrorString(error));
	}
#endif
}

float cvUpdateFastBgGMMTimer(CvFastBgGMM* pGMM, IplImage* inputImg)
{
	cudaEvent_t start, stop;
	float time = 0;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord( start, 0 );
	
	cvUpdateFastBgGMM(pGMM, inputImg);

	cudaEventRecord( stop, 0 );
	cudaEventSynchronize( stop );
	cudaEventElapsedTime( &time, start, stop );
	cudaEventDestroy( start );
	cudaEventDestroy( stop );
	return time;
}

/*============================================================================*/
// CUDA-related functions
/*============================================================================*/

int InitCUDA(CvFastBgGMM* pGMM)
{
#if __DEVICE_EMULATION__

	pGMM->nThreadsPerBlock = pGMM->nBlocksPerGrid = 256;
	return 0;

#else

	int count = 0;
	int i = 0;

	cudaGetDeviceCount(&count);
	if(count == 0)
	{
		fprintf(stderr, "There is no device.\n");
		return -1;
	}

	for(i = 0; i < count; i++)
	{
		cudaDeviceProp prop;
		if(cudaGetDeviceProperties(&prop, i) == cudaSuccess)
		{
			if(prop.major >= 1)
			{
				pGMM->nThreadsPerBlock = prop.maxThreadsPerBlock / 4;

				// temporarily hard-code a little here...
				pGMM->nBlocksPerGrid = 256;
				break;
			}
		}
	}
	if(i == count) {
		fprintf(stderr, "There is no device supporting CUDA.\n");
		return -1;
	}
	cudaSetDevice(i);
	return i;

#endif
}

/*=======================================================================================*/

/*=======================================================================================*/

__device__ int _cudaUpdateFastBgGMM(int pixel, 
									float red, float green, float blue,
									int* pModesUsed
									)
{
	//calculate distances to the modes (+ sort???)
	//here we need to go in descending order!!!

	int pos;
	bool bFitsPDF = 0;
	int bBackground = 0;
	float m_fOneMinAlpha = 1 - d_GMMParams.fAlphaT;
	int nModes = (*pModesUsed);
	float weight, totalWeight = 0.0f;
	float dR, dG, dB;
	float dist, k, sigmanew;

	//go through all modes
	for (int iModes = 0; iModes < nModes; iModes++)
	{
		pos = pixel + iModes*d_arrImageInfo[ImageInfoPixelCount];
		weight = d_GMMData.rWeight[pos];

		//fit not found yet
		if (!bFitsPDF)
		{
			//check if it belongs to some of the modes
			//calculate distance
			float4 cGauss = d_GMMData.ucGaussian[pos];

			dR = cGauss.x - red;
			dG = cGauss.y - green;
			dB = cGauss.z - blue;

			//check if it fits the current mode (Factor * sigma)

			//square distance -slower and less accurate
			//float maxDistance = cvSqrt(m_fTg*var);
			//if ((fabs(dR) <= maxDistance) && (fabs(dG) <= maxDistance) && (fabs(dB) <= maxDistance))
			//circle
			dist = dR*dR + dG*dG + dB*dB;

			//background? - m_fTb
			if ((totalWeight < d_GMMParams.fTB) && (dist < d_GMMParams.fTb * cGauss.w))
				bBackground = 1;

			//check fit
			if (dist < d_GMMParams.fTg * cGauss.w)
			{
				//belongs to the mode
				bFitsPDF = 1;

				//update distribution
				k = d_GMMParams.fAlphaT/weight;
				weight = m_fOneMinAlpha * weight + d_GMMParams.fPrune;
				weight += d_GMMParams.fAlphaT;
				cGauss.x -= k*(dR);
				cGauss.y -= k*(dG);
				cGauss.z -= k*(dB);

				//limit update speed for cov matrice
				//not needed
				sigmanew = cGauss.w + k*(dist - cGauss.w);

				//limit the variance
				cGauss.w = sigmanew < 4 ? 4 : 
					sigmanew > 5 * d_GMMParams.fSigma ? 5 * d_GMMParams.fSigma : sigmanew;

				d_GMMData.ucGaussian[pos] = cGauss;

				//sort
				//all other weights are at the same place and 
				//only the matched (iModes) is higher -> just find the new place for it

				for (int iLocal = iModes; iLocal > 0; iLocal--)
				{
					int posLocal = pixel + iLocal*d_arrImageInfo[ImageInfoPixelCount];
					if (weight < (d_GMMData.rWeight[posLocal-d_arrImageInfo[ImageInfoPixelCount]]))
					{
						break;
					}
					else
					{
						//swap
						float tmpVal;
						float4 tmpuChar;
						SWAP(d_GMMData.ucGaussian[posLocal],
							d_GMMData.ucGaussian[posLocal - d_arrImageInfo[ImageInfoPixelCount]],
							tmpuChar);
						SWAP(d_GMMData.rWeight[posLocal],
							d_GMMData.rWeight[posLocal - d_arrImageInfo[ImageInfoPixelCount]],
							tmpVal);
					}
				}

				//belongs to the mode
			}
			else
			{
				weight = m_fOneMinAlpha * weight + d_GMMParams.fPrune;

				//check prune
				if (weight < -(d_GMMParams.fPrune))
				{
					weight = 0.0f;
					nModes--;
					//	bPrune=1;
					//break;//the components are sorted so we can skip the rest
				}
			}
			//check if it fits the current mode (2.5 sigma)
			///////
		}	//fit not found yet
		else
		{
			weight = m_fOneMinAlpha * weight + d_GMMParams.fPrune;

			if (weight < -(d_GMMParams.fPrune))
			{
				weight=0.0;
				nModes--;
				//bPrune=1;
				//break;//the components are sorted so we can skip the rest
			}
		}
		totalWeight += weight;
		d_GMMData.rWeight[pos] = weight;
	}
	//go through all modes
	//////

	//renormalize weights
	for (int iLocal = 0; iLocal < nModes; iLocal++)
	{
		d_GMMData.rWeight[pixel + iLocal*d_arrImageInfo[ImageInfoPixelCount]] /= totalWeight;
	}

	//make new mode if needed and exit
	if (!bFitsPDF)
	{
		if (nModes == d_GMMParams.nM)
		{
			//replace the weakest
		}
		else
		{
			//add a new one
			//totalWeight+=m_fAlphaT;
			//pos++;
			nModes++;
		}
		pos = pixel + (nModes-1)*d_arrImageInfo[ImageInfoPixelCount];

		if (nModes == 1)
			d_GMMData.rWeight[pos] = 1;
		else
			d_GMMData.rWeight[pos] = d_GMMParams.fAlphaT;

		//renormalize weights
		for (int iLocal = 0; iLocal < nModes-1; iLocal++)
		{
			d_GMMData.rWeight[pixel + iLocal*d_arrImageInfo[ImageInfoPixelCount]] *= m_fOneMinAlpha;
		}

		float4 cGauss;
		cGauss.x = red;
		cGauss.y = green;
		cGauss.z = blue;
		cGauss.w = d_GMMParams.fSigma;
		d_GMMData.ucGaussian[pos] = cGauss;

		//sort
		//find the new place for it
		for (int iLocal = nModes - 1; iLocal>0; iLocal--)
		{
			int posLocal = pixel + iLocal*d_arrImageInfo[ImageInfoPixelCount];
			if (d_GMMParams.fAlphaT < (d_GMMData.rWeight[posLocal - d_arrImageInfo[ImageInfoPixelCount]]))
			{
				break;
			}
			else
			{
				//swap
				float4 tmpuChar;
				float tmpVal;
				SWAP(d_GMMData.ucGaussian[posLocal],
					d_GMMData.ucGaussian[posLocal - d_arrImageInfo[ImageInfoPixelCount]],
					tmpuChar);
				SWAP(d_GMMData.rWeight[posLocal],
					d_GMMData.rWeight[posLocal - d_arrImageInfo[ImageInfoPixelCount]],
					tmpVal);
			}
		}
	}

	//set the number of modes
	*pModesUsed=nModes;

	return bBackground;
}

/*=======================================================================================*/

/*=======================================================================================*/
__device__ int _cudaRemoveShadowGMM(int pixel, 
									float red, float green, float blue, 
									int nModes)
{
	//calculate distances to the modes (+ sort???)
	//here we need to go in descending order!!!
	//	long posPixel = pixel * m_nM;
	int pos;
	float tWeight = 0;
	float numerator, denominator;

	// check all the distributions, marked as background:
	for (int iModes=0;iModes<nModes;iModes++)
	{
		pos=pixel+iModes*d_arrImageInfo[ImageInfoPixelCount];
		float4 cGauss = d_GMMData.ucGaussian[pos];
		float weight = d_GMMData.rWeight[pos];
		tWeight += weight;

		numerator = red * cGauss.x + green * cGauss.y + blue * cGauss.z;
		denominator = cGauss.x * cGauss.x + cGauss.y * cGauss.y + cGauss.z * cGauss.z;
		// no division by zero allowed
		if (denominator == 0)
		{
			break;
		}
		float a = numerator / denominator;

		// if tau < a < 1 then also check the color distortion
		if ((a <= 1) && (a >= d_GMMParams.fTau))//m_nBeta=1
		{
			float dR=a * cGauss.x - red;
			float dG=a * cGauss.y - green;
			float dB=a * cGauss.z - blue;

			//square distance -slower and less accurate
			//float maxDistance = cvSqrt(m_fTb*var);
			//if ((fabs(dR) <= maxDistance) && (fabs(dG) <= maxDistance) && (fabs(dB) <= maxDistance))
			//circle
			float dist=(dR*dR+dG*dG+dB*dB);
			if (dist<d_GMMParams.fTb*cGauss.w*a*a)
			{
				return 2;
			}
		}
		if (tWeight > d_GMMParams.fTB)
		{
			break;
		}
	}
	return 0;
}

/*=======================================================================================*/

/*=======================================================================================*/

__device__ void _cudaReplacePixelBackgroundGMM(int pixel, uchar4* pData)
{
	uchar4 tmp;
	float4 cGauss = d_GMMData.ucGaussian[pixel];
	tmp.z = (unsigned char) cGauss.x;
	tmp.y = (unsigned char) cGauss.y;
	tmp.x = (unsigned char) cGauss.z;
	(*pData) = tmp;
}
/*=======================================================================================*/

/*=======================================================================================*/
extern __shared__ int sharedInfo[];

__global__ void cudaUpdateFastBgGMM(unsigned char* data, unsigned char* output)
{
	if(threadIdx.x == 0)
	{
		// the start pixel for current block
		sharedInfo[0] = (blockIdx.x * blockDim.x)*d_arrImageInfo[ImageInfoPixelsPerThread];
	}
	__syncthreads();

	int iPxStart = sharedInfo[0] + threadIdx.x;
	int iPxEnd = min( d_arrImageInfo[ImageInfoPixelCount], 
		sharedInfo[0] + (blockDim.x * d_arrImageInfo[ImageInfoPixelsPerThread]));

	uchar4* pGlobalInput = ((uchar4*)data) + iPxStart;
	unsigned char* pGlobalOutput = output + iPxStart;

	int* pUsedModes = d_GMMData.rnUsedModes + iPxStart;
	uchar fRed, fGreen, fBlue;
	uchar4 currentInputPx;

	for(int i = iPxStart; i < iPxEnd; i += blockDim.x)
	{
		// retrieves the color
		currentInputPx = *pGlobalInput;
		fBlue = currentInputPx.x;
		fGreen = currentInputPx.y;
		fRed = currentInputPx.z;
		pGlobalInput += blockDim.x;

		// update model + background subtract
		int result = _cudaUpdateFastBgGMM(i, fRed, fGreen, fBlue, pUsedModes);
		int nMLocal = *pUsedModes;
		pUsedModes += blockDim.x;

		if (d_GMMParams.bShadowDetection)
		{
			if (!result)
			{
				result= _cudaRemoveShadowGMM(i, fRed, fGreen, fBlue, nMLocal);
			}
		}

		switch (result)
		{
		case 0:

			//foreground
			(*pGlobalOutput) = 255;
			if (d_GMMParams.bRemoveForeground) 
			{
				_cudaReplacePixelBackgroundGMM(i, pGlobalInput-blockDim.x);
			}
			break;

		case 1:

			//background
			(*pGlobalOutput) = 0;
			break;

		case 2:

			//shadow
			(*pGlobalOutput) = 128;
			if (d_GMMParams.bRemoveForeground) 
			{
				_cudaReplacePixelBackgroundGMM(i, pGlobalInput-blockDim.x);
			}

			break;
		}
		pGlobalOutput += blockDim.x;
	}
}

#endif
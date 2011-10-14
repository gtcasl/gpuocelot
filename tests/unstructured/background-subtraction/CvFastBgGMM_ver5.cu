#include <stdlib.h>

#define CUDAGMM_VERSION 5
 
#if(CUDAGMM_VERSION == 5)

#define SWAP(a, b, t)	t = (a); a = (b); b = (t)


typedef struct CvFastBgGMMData
{
	float4* ucGaussian;
	float* rWeight;
	int* rnUsedModes;

} CvFastBgGMMData;


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


__constant__ CvFastBgGMMParams d_GMMParams;
__constant__ CvFastBgGMMData d_GMMData;
__constant__ int d_arrImageInfo[ImageInfoCount];

/*=======================================================================================*/

__device__ int _cudaUpdateFastBgGMM(int pixel, 
									float red, float green, float blue,
									int* pModesUsed
									)
{
	//calculate distances to the modes (+ sort)
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
	//calculate distances to the modes (+ sort)
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

template <int BLOCK_SIZE>
__global__ void cudaUpdateFastBgGMM(unsigned char* data, unsigned char* output)
{
	if(threadIdx.x == 0)
	{
		// the start pixel for current block
		sharedInfo[0] = (blockIdx.x * BLOCK_SIZE)*d_arrImageInfo[ImageInfoPixelsPerThread];
	}
	__syncthreads();

	int iPxStart = sharedInfo[0] + threadIdx.x;
	int iPxEnd = min( d_arrImageInfo[ImageInfoPixelCount], 
		sharedInfo[0] + (BLOCK_SIZE * d_arrImageInfo[ImageInfoPixelsPerThread]));

	uchar4* pGlobalInput = ((uchar4*)data) + iPxStart;
	unsigned char* pGlobalOutput = output + iPxStart;

	int* pUsedModes = d_GMMData.rnUsedModes + iPxStart;
	unsigned char fRed, fGreen, fBlue;
	uchar4 currentInputPx;

	for(int i = iPxStart; i < iPxEnd; i += BLOCK_SIZE)
	{
		// retrieves the color
		currentInputPx = *pGlobalInput;
		fBlue = currentInputPx.x;
		fGreen = currentInputPx.y;
		fRed = currentInputPx.z;
		pGlobalInput += BLOCK_SIZE;

		// update model + background subtract
		int result = _cudaUpdateFastBgGMM(i, fRed, fGreen, fBlue, pUsedModes);
		int nMLocal = *pUsedModes;
		pUsedModes += BLOCK_SIZE;

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
				_cudaReplacePixelBackgroundGMM(i, pGlobalInput-BLOCK_SIZE);
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
				_cudaReplacePixelBackgroundGMM(i, pGlobalInput-BLOCK_SIZE);
			}

			break;
		}
		pGlobalOutput += BLOCK_SIZE;
	}
}
#endif

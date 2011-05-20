#include <stdio.h>
#include <stdlib.h>
#include "cv.h"
#include "cvaux.h"
#include "highgui.h"
#include <ml.h>
#include <ctype.h>
#include "conio.h"
#include "CvFastBgGMM.h"

#define TIMER_CUDA	TRUE

#define TEST_VIDEO "..\\..\\data\\vid\\video7_long.avi"

int main(int argc, char** argv)
{
	int key = -1;
	float fTotalTime = 0;
	unsigned int iFrameCnt, iFrameStart;
	iFrameStart = iFrameCnt = 0;
	
	CvCapture* capture = 0;
	capture = cvCaptureFromAVI(TEST_VIDEO);
	if( !capture )
	{
		fprintf(stderr,"Could not initialize...\n");
		return -1;
	}

	IplImage* videoFrame = NULL;
	videoFrame = cvQueryFrame(capture);

	if(!videoFrame)
	{
		printf("Bad frame \n");
		exit(0);
	}

	cvNamedWindow("BG", 1);
	cvNamedWindow("FG", 1);

	CvFastBgGMMParams* pGMMParams = 0;
	CvFastBgGMM* pGMM = NULL;
	pGMMParams = cvCreateFastBgGMMParams(videoFrame->width, videoFrame->height);

	// modify other params in pGMMParams
	//pGMMParams->fAlphaT = 0.0001f;
	pGMMParams->fAlphaT = 0.008f;

	// officially create the parameter (on device memory)
	pGMM = cvCreateFastBgGMM(pGMMParams, videoFrame);

#if(!TIMER_CUDA)
	LARGE_INTEGER lFrequency, lStart, lEnd;
	QueryPerformanceFrequency(&lFrequency);
#endif

	while(key != 'q')
	{
		videoFrame = cvQueryFrame(capture);

		if( !videoFrame)
			break;

		iFrameCnt++;
		double fEllapsed;

#if(!TIMER_CUDA)
		QueryPerformanceCounter(&lStart);
#endif

		// Update model
#if(TIMER_CUDA)
		fEllapsed = cvUpdateFastBgGMMTimer(pGMM, videoFrame);
#else
		cvUpdateFastBgGMM(pGMM, videoFrame);
		QueryPerformanceCounter(&lEnd);
		fEllapsed = 1000.0*(lEnd.QuadPart - lStart.QuadPart)/(double)lFrequency.QuadPart;
#endif

		fTotalTime += (float)fEllapsed;

		char sOutput[MAX_PATH];
		sprintf_s(sOutput, "K:\\Ret\\gpu\\ret%05d.png", iFrameCnt);
		cvSaveImage(sOutput, pGMM->h_outputImg);
		sprintf_s(sOutput, "K:\\Ret\\original\\ret%05d.png", iFrameCnt);
		cvSaveImage(sOutput, videoFrame);

		cvShowImage("BG", videoFrame);
		cvShowImage("FG", pGMM->h_outputImg);	

		key = cvWaitKey(10);
	}

	iFrameCnt -= iFrameStart;
	printf("Average %.1f ms/frame, %.1f FPS\r\n", fTotalTime / (float)iFrameCnt, 1000.0f*(float)iFrameCnt/fTotalTime);

	cvDestroyWindow("BG");
	cvDestroyWindow("FG");

	cvReleaseFastBgGMM(&pGMM);
	delete pGMMParams;
	cvReleaseCapture(&capture);

	return 0;
}
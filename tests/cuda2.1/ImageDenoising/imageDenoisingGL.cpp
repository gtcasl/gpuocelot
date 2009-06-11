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



/*
 * This sample demonstrates two adaptive image denoising technqiues: 
 * KNN and NLM, based on computation of both geometric and color distance 
 * between texels. While both techniques are already implemented in the 
 * DirectX SDK using shaders, massively speeded up variation 
 * of the latter techique, taking advantage of shared memory, is implemented
 * in addition to DirectX counterparts.
 * See supplied whitepaper for more explanations.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <cuda_runtime.h>
#include <cutil_inline.h>
#include <cutil_gl_error.h>
#include <cuda_gl_interop.h>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "imageDenoising.h"

#include <rendercheck_gl.h>

static char *filterMode[] = {
    "Passthrough",
    "KNN method",
    "NLM method",
    "Quick NLM(NLM2) method",
    NULL
};

// Define the files that are to be save and the reference images for validation
const char *sOriginal[] =
{
    "image_passthru.ppm",
    "image_knn.ppm",
    "image_nlm.ppm",
    "image_nlm2.ppm",
    NULL
};

const char *sReference[] =
{
    "ref_passthru.ppm",
    "ref_knn.ppm",
    "ref_nlm.ppm",
    "ref_nlm2.ppm",
    NULL
};

////////////////////////////////////////////////////////////////////////////////
// Global data handlers and parameters
////////////////////////////////////////////////////////////////////////////////
//OpenGL PBO and texture "names"
GLuint gl_PBO, gl_Tex;
//Source image on the host side
uchar4 *h_Src;
int imageW, imageH;

////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////
int  g_Kernel = 0;
bool    g_FPS = false;
bool   g_Diag = false;
unsigned int hTimer;

//Algorithms global parameters
const float noiseStep = 0.025f;
const float  lerpStep = 0.025f;
static float knnNoise = 0.32f;
static float nlmNoise = 1.45f;
static float    lerpC = 0.2f;


const int frameN = 24;
int frameCounter = 0;


#define BUFFER_DATA(i) ((char *)0 + i)

// Auto-Verification Code
const int frameCheckNumber = 2;
int fpsCount = 0;        // FPS count for averaging
int fpsLimit = 1;        // FPS limit for sampling
unsigned int frameCount = 0;
unsigned int g_TotalErrors = 0;
bool g_Verify = false, g_AutoQuit = false;

// CheckFBO/BackBuffer class objects
CheckRender       *g_CheckRender = NULL;

#define MAX_EPSILON 1

void AutoQATest()
{
    if (g_CheckRender && g_CheckRender->IsQAReadback()) {
        char temp[256];
        sprintf(temp, "%s <%s>", "AutoTest:", filterMode[g_Kernel]);  
	    glutSetWindowTitle(temp);

        g_Kernel++;

        if (g_Kernel > 3) {
            g_Kernel = 0;
            printf("Summary: %d errors!\n", g_TotalErrors);
            printf("Test %s!\n", (g_TotalErrors==0) ? "PASSED" : "FAILED");
//            cudaThreadExit();
            exit(0);
        }
    }
}


void computeFPS()
{
    frameCount++;
    fpsCount++;
    if (fpsCount == fpsLimit-1) {
        g_Verify = true;
    }
    if (fpsCount == fpsLimit) {
        char fps[256];
   		float ifps = 1.f / (cutGetAverageTimerValue(hTimer) / 1000.f);
        sprintf(fps, "%s <%s>: %3.1f fps", 
                ((g_CheckRender && g_CheckRender->IsQAReadback()) ? "AutoTest:" : ""),
				filterMode[g_Kernel], ifps);  

        glutSetWindowTitle(fps);
        fpsCount = 0; 
        if (g_CheckRender && !g_CheckRender->IsQAReadback()) fpsLimit = (int)MAX(ifps, 1.f);

        cutilCheckError(cutResetTimer(hTimer));  
        AutoQATest();
    }
}

void displayFunc(void){
	cutStartTimer(hTimer);
    TColor *d_dst = NULL;

//    if(frameCounter++ == 0) cutResetTimer(hTimer);
    cutilSafeCall( cudaGLMapBufferObject((void**)&d_dst, gl_PBO) );

    cutilSafeCall( CUDA_Bind2TextureArray()                      );

    switch(g_Kernel){
        case 0:
            cuda_Copy(d_dst, imageW, imageH);
        break;
        case 1:
            if(!g_Diag)
                cuda_KNN(d_dst, imageW, imageH, 1.0f / (knnNoise * knnNoise), lerpC);
            else
                cuda_KNNdiag(d_dst, imageW, imageH, 1.0f / (knnNoise * knnNoise), lerpC);
        break;
        case 2:
            if(!g_Diag)
                cuda_NLM(d_dst, imageW, imageH, 1.0f / (nlmNoise * nlmNoise), lerpC); 
            else
                cuda_NLMdiag(d_dst, imageW, imageH, 1.0f / (nlmNoise * nlmNoise), lerpC);
        break;
        case 3:
            if(!g_Diag)
                cuda_NLM2(d_dst, imageW, imageH, 1.0f / (nlmNoise * nlmNoise), lerpC); 
            else
                cuda_NLM2diag(d_dst, imageW, imageH, 1.0f / (nlmNoise * nlmNoise), lerpC);
        break;
    }
    cutilCheckMsg("Filtering kernel execution failed.\n");

    cutilSafeCall( CUDA_UnbindTexture()     );
    cutilSafeCall( cudaGLUnmapBufferObject(gl_PBO) );

    glTexSubImage2D( GL_TEXTURE_2D, 0, 0, 0, imageW, imageH, GL_RGBA, GL_UNSIGNED_BYTE, BUFFER_DATA(0) );
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0, 0); glVertex2f(-1, -1);
        glTexCoord2f(2, 0); glVertex2f(+3, -1);
        glTexCoord2f(0, 2); glVertex2f(-1, +3);
    glEnd();
    glFinish();

    if (g_CheckRender && g_CheckRender->IsQAReadback() && g_Verify) {
        printf("> (Frame %d) readback BackBuffer\n", frameCount);
        g_CheckRender->readback( imageW, imageH, NULL );
        g_CheckRender->savePPM ( sOriginal[g_Kernel], true, NULL );
        if (!g_CheckRender->PPMvsPPM(sOriginal[g_Kernel], sReference[g_Kernel], MAX_EPSILON)) {
            g_TotalErrors++;
        }
        g_Verify = false;
    }

    if(frameCounter == frameN){
        frameCounter = 0;
        if(g_FPS){
            printf("FPS: %3.1f\n", frameN / (cutGetTimerValue(hTimer) * 0.001) );
            g_FPS = false;
        }
    }

	glutSwapBuffers();

	cutStopTimer(hTimer);
	computeFPS();

	glutPostRedisplay();
}



void shutDown(unsigned char k, int /*x*/, int /*y*/)
{
    switch (k){
        case '\033':
        case 'q':
        case 'Q':
            printf("Shutting down...\n");
                cutilCheckError( cutStopTimer(hTimer)   );
                cutilCheckError( cutDeleteTimer(hTimer) );
                cutilSafeCall( cudaGLUnregisterBufferObject(gl_PBO) );
                glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, 0);
                glDeleteBuffers(1, &gl_PBO);
                glDeleteTextures(1, &gl_Tex);

                cutilSafeCall( CUDA_FreeArray() );
                free(h_Src);
            printf("Shutdown done.\n");
            cudaThreadExit();
            exit(0);
        break;

        case '1':
            printf("Passthrough.\n");
            g_Kernel = 0;
        break;

        case '2':
            printf("KNN method \n");
            g_Kernel = 1;
        break;

        case '3':
            printf("NLM method\n");
            g_Kernel = 2;
        break;

        case '4':
            printf("Quick NLM(NLM2) method\n");
            g_Kernel = 3;
        break;

        case ' ':
            printf(g_Diag ? "LERP highlighting mode.\n" : "Normal mode.\n");
            g_Diag = !g_Diag;
        break;

        case 'n':
            printf("Decrease noise level.\n");
            knnNoise -= noiseStep;
            nlmNoise -= noiseStep;
        break;

        case 'N':
            printf("Increase noise level.\n");
            knnNoise += noiseStep;
            nlmNoise += noiseStep;
        break;

        case 'l':
            printf("Decrease LERP quotent.\n");
            lerpC = MAX(lerpC - lerpStep, 0.0f);
        break;

        case 'L':
            printf("Increase LERP quotent.\n");
            lerpC = MIN(lerpC + lerpStep, 1.0f);
        break;

        case 'f' : case 'F':
            g_FPS = true;
        break;

        case '?':
            printf("lerpC = %5.5f\n", lerpC);
            printf("knnNoise = %5.5f\n", knnNoise);
            printf("nlmNoise = %5.5f\n", nlmNoise);
        break;
    }
}



int main(int argc, char **argv){

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s

    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device"))
	    cutilDeviceInit(argc, argv);
    else
    	cudaSetDevice( cutGetMaxGflopsDeviceId() );

    // check for command line arguments
    bool bQAReadback = false;
    bool bFBODisplay = false;

    if (!cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest")) {
        bQAReadback = true;
        fpsLimit = frameCheckNumber;
    }
    if (argc > 1) {
        if (cutCheckCmdLineFlag(argc, (const char **)argv, "fbo")) {
            bFBODisplay = true;
            fpsLimit = frameCheckNumber;
        }
    }

    printf("Allocating host and CUDA memory and loading image file...\n");
        const char *image_path = cutFindFilePath("portrait_noise.bmp", argv[0]);
        LoadBMPFile(&h_Src, &imageW, &imageH, image_path);
        
    

        cutilSafeCall( CUDA_MallocArray(&h_Src, imageW, imageH) );
    printf("Data init done.\n");

    printf("Initializing GLUT...\n");
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
        glutInitWindowSize(imageW, imageH);
        glutInitWindowPosition(512 - imageW / 2, 384 - imageH / 2);
        glutCreateWindow(argv[0]);
        printf("Loading extensions: %s\n", glewGetErrorString(glewInit()));
        if(!glewIsSupported(
            "GL_VERSION_2_0 " 
            "GL_ARB_pixel_buffer_object "
            "GL_EXT_framebuffer_object "
        )){
            fprintf(stderr, "ERROR: Support for necessary OpenGL extensions missing.");
            fflush(stderr);
            return CUTFalse;
        }
    printf("OpenGL window created.\n");

    printf("Creating GL texture...\n");
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &gl_Tex);
        glBindTexture(GL_TEXTURE_2D, gl_Tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, imageW, imageH, 0, GL_RGBA, GL_UNSIGNED_BYTE, h_Src);
    printf("Texture created.\n");

    printf("Creating PBO...\n");
        glGenBuffers(1, &gl_PBO);
        glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, gl_PBO);
        glBufferData(GL_PIXEL_UNPACK_BUFFER_ARB, imageW * imageH * 4, h_Src, GL_STREAM_COPY);
        //While a PBO is registered to CUDA, it can't be used 
        //as the destination for OpenGL drawing calls.
        //But in our particular case OpenGL is only used 
        //to display the content of the PBO, specified by CUDA kernels,
        //so we need to register/unregister it only once.
        cutilSafeCall( cudaGLRegisterBufferObject(gl_PBO) );
        CUT_CHECK_ERROR_GL();
    printf("PBO created.\n");

    // Creating the Auto-Validation Code
    if (bQAReadback) {
        if (bFBODisplay) {
            g_CheckRender = new CheckFBO(imageW, imageH, 4);
        } else {
            g_CheckRender = new CheckBackBuffer(imageW, imageH, 4);
        }
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(bQAReadback);
    }

    printf("Starting GLUT main loop...\n");
    printf("Press [1] to view noisy image\n");
    printf("Press [2] to view image restored with knn filter\n");
    printf("Press [3] to view image restored with nlm filter\n");
    printf("Press [4] to view image restored with modified nlm filter\n");
    printf("Press [ ] to view smooth/edgy areas [RED/BLUE] Ct's\n");
    printf("Press [f] to print frame rate\n");
    printf("Press [?] to print Noise and Lerp Ct's\n");
    printf("Press [q] to exit\n");

    glutIdleFunc(displayFunc);
    glutDisplayFunc(displayFunc);
    glutKeyboardFunc(shutDown);
    cutilCheckError( cutCreateTimer(&hTimer) );
    cutilCheckError( cutStartTimer(hTimer)   );
    glutMainLoop();

    cutilExit(argc, argv);

    cudaThreadExit();
}

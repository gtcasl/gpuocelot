/*
 * Copyright 1993-2006 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.   
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.  This source code is a "commercial item" as 
 * that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer software" and "commercial computer software 
 * documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein.
 */

#include <GL/glew.h>

#if defined(WIN32)
#include <GL/wglew.h>
#endif

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <paramgl.h>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <assert.h>
#include <math.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <sys/time.h>

#include "bodysystemcuda.h"
#include "bodysystemcpu.h"
#include "render_particles.h"

#include "cuda_runtime_api.h"

// view params
int ox = 0, oy = 0;
int buttonState          = 0;
float camera_trans[]     = {0, -2, -100};
float camera_rot[]       = {0, 0, 0};
float camera_trans_lag[] = {0, -2, -100};
float camera_rot_lag[]   = {0, 0, 0};
const float inertia      = 0.1;

ParticleRenderer::DisplayMode displayMode = 
  ParticleRenderer::PARTICLE_SPRITES_COLOR;

bool displayEnabled = true;
bool bPause = false;
enum { M_VIEW = 0, M_MOVE };

#ifdef __DEVICE_EMULATION__
int numBodies = 1024;
#else
int numBodies = 16384;
#endif

int numIterations = 0; // run until exit

////////////////////////////////////////
// Demo Parameters
////////////////////////////////////////
struct NBodyParams
{       
    float m_timestep;
    float m_clusterScale;
    float m_velocityScale;
    float m_softening;
    float m_damping;
    float m_pointSize;
    float m_x, m_y, m_z;

    void print() { printf("{ %f, %f, %f, %f, %f, %f, %f, %f, %f },\n", 
                   m_timestep, m_clusterScale, m_velocityScale, 
                   m_softening, m_damping, m_pointSize, m_x, m_y, m_z); }
};

NBodyParams demoParams[] = 
{
    { 0.016f, 1.54f, 8.0f, 0.1f, 1.0f, 1.0f, 0, -2, -100},
    { 0.016f, 0.68f, 20.0f, 0.1f, 1.0f, 0.8f, 0, -2, -30},
    { 0.0006f, 0.16f, 1000.0f, 1.0f, 1.0f, 0.07f, 0, 0, -1.5f},
    { 0.0006f, 0.16f, 1000.0f, 1.0f, 1.0f, 0.07f, 0, 0, -1.5f},
    { 0.0019f, 0.32f, 276.0f, 1.0f, 1.0f, 0.07f, 0, 0, -5},
    { 0.0016f, 0.32f, 272.0f, 0.145f, 1.0f, 0.08f, 0, 0, -5},
    { 0.016000, 6.040000, 0.000000, 1.000000, 1.000000, 0.760000, 0, 0, -50},
};

int numDemos = sizeof(demoParams) / sizeof(NBodyParams);
bool cycleDemo = true;
int activeDemo = 0;
float demoTime = 40000.0f; // ms
unsigned int demoTimer = 0;
// run multiple iterations to compute an average sort time

NBodyParams activeParams = demoParams[activeDemo];


BodySystem *nbody         = 0;
BodySystemCUDA *nbodyCUDA = 0;
BodySystemCPU  *nbodyCPU  = 0;

float* hPos = 0;
float* hVel = 0;
float* hColor = 0;

// The UI.
ParamListGL *paramlist;  // parameter list
bool bShowSliders = true;

// fps
static int fpsCount = 0;
static int fpsLimit = 20;

//unsigned int timer = 0;
cudaEvent_t startEvent, stopEvent;

struct timeval startTime, stopTime;

ParticleRenderer *renderer = 0;


void reset(BodySystem *system, int numBodies, 
	   NBodyConfig config, bool useGL = true)
{
    // initalize the memory
    randomizeBodies(config, hPos, hVel, hColor, activeParams.m_clusterScale, 
		            activeParams.m_velocityScale, numBodies);

    system->setArray(BodySystem::BODYSYSTEM_POSITION, hPos);
    system->setArray(BodySystem::BODYSYSTEM_VELOCITY, hVel);
    if (useGL)
    {
        renderer->setColors(hColor, nbody->getNumBodies());
        renderer->setSpriteSize(activeParams.m_pointSize);
    }
}

void init(int numBodies, int p, int q, bool bUsePBO)
{
    nbodyCUDA = new BodySystemCUDA(numBodies, p, q, bUsePBO);
    nbody = nbodyCUDA;

    // allocate host memory
    hPos = new float[numBodies*4];
    hVel = new float[numBodies*4];
    hColor = new float[numBodies*4];

    nbody->setSoftening(activeParams.m_softening);
    nbody->setDamping(activeParams.m_damping);

    //cutilCheckError(cutCreateTimer(&timer));
    cutilSafeCall( cudaEventCreate(&startEvent) );
    cutilSafeCall( cudaEventCreate(&stopEvent) );

    cutilCheckError(cutCreateTimer(&demoTimer));

    cutilCheckError(cutStartTimer(demoTimer));
}

void selectDemo(int index)
{
    assert(index < numDemos);

    activeParams = demoParams[index];
    camera_trans[0] = camera_trans_lag[0] = activeParams.m_x;
    camera_trans[1] = camera_trans_lag[1] = activeParams.m_y;
    camera_trans[2] = camera_trans_lag[2] = activeParams.m_z;
    reset(nbody, numBodies, NBODY_CONFIG_SHELL);
    cutilCheckError(cutResetTimer(demoTimer));
}


void compareResults(bool regression, int numBodies)
{
    nbodyCUDA->update(0.001f);

    // check result
    if(regression) 
    {
        // write file for regression test
        cutilCheckError( cutWriteFilef( "./data/regression.dat",
            nbodyCUDA->getArray(BodySystem::BODYSYSTEM_POSITION), 
            numBodies, 0.0));
    }
    else
    {
        nbodyCPU = new BodySystemCPU(numBodies);

        nbodyCPU->setArray(BodySystem::BODYSYSTEM_POSITION, hPos);
        nbodyCPU->setArray(BodySystem::BODYSYSTEM_VELOCITY, hVel);

        nbodyCPU->update(0.001f);

        float* cudaPos = nbodyCUDA->getArray(BodySystem::BODYSYSTEM_POSITION);
        float* cpuPos  = nbodyCPU->getArray(BodySystem::BODYSYSTEM_POSITION);

        // custom output handling when no regression test running
        // in this case check if the result is equivalent to the expected 
	    // solution
        CUTBoolean res = cutComparefe( cpuPos, cudaPos, numBodies, .0005f);
        printf( "Test %s\n", (1 == res) ? "PASSED" : "FAILED");
    }
}

// check for OpenGL errors
void checkGLErrors(char *s)
{
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR) {
        fprintf(stderr, "%s: error - %s\n", s, (char *) gluErrorString(error));
    }
}

void initGL()
{  
    glewInit();
    if (!glewIsSupported("GL_VERSION_2_0 "
                         "GL_VERSION_1_5 "
			             "GL_ARB_multitexture "
                         "GL_ARB_vertex_buffer_object")) 
    {
        fprintf(stderr, "Required OpenGL extensions missing.");
        cudaThreadExit();
        exit(-1);
    }

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    renderer = new ParticleRenderer;
    
    checkGLErrors("initGL");
}

void initParameters()
{
    // create a new parameter list
    paramlist = new ParamListGL("sliders");
    paramlist->SetBarColorInner(0.8f, 0.8f, 0.0f);
    
    // add some parameters to the list

    // Point Size
    paramlist->AddParam(new Param<float>("Point Size", activeParams.m_pointSize, 
        0.0f, 10.0f, 0.01f, &activeParams.m_pointSize));

    // Velocity Damping
    paramlist->AddParam(new Param<float>("Velocity Damping", activeParams.m_damping, 
					 0.5f, 1.0f, .0001f, &(activeParams.m_damping)));
    // Softening Factor
    paramlist->AddParam(new Param<float>("Softening Factor", activeParams.m_softening,
					 0.001f, 1.0f, .0001f, &(activeParams.m_softening)));
    // Time step size
    paramlist->AddParam(new Param<float>("Time Step", activeParams.m_timestep, 
					 0.0f, 1.0f, .0001f, &(activeParams.m_timestep)));
    // Cluster scale (only affects starting configuration
    paramlist->AddParam(new Param<float>("Cluster Scale", activeParams.m_clusterScale, 
					 0.0f, 10.0f, 0.01f, &(activeParams.m_clusterScale)));
    
    // Velocity scale (only affects starting configuration)
    paramlist->AddParam(new Param<float>("Velocity Scale", activeParams.m_velocityScale, 
					 0.0f, 1000.0f, 0.1f, &activeParams.m_velocityScale));
}

void computePerfStats(double &interactionsPerSecond, double &gflops, 
		      float milliseconds, int iterations)
{
    const int flopsPerInteraction = 20;
    interactionsPerSecond = (float)numBodies * (float)numBodies;
    interactionsPerSecond *= 1e-9 * iterations * 1000 / milliseconds;
    gflops = interactionsPerSecond * (float)flopsPerInteraction;
}

void runBenchmark(int iterations)
{
    // once without timing to prime the GPU
    nbody->update(activeParams.m_timestep);

    cutilSafeCall(cudaEventRecord(startEvent, 0));

    for (int i = 0; i < iterations; ++i)
    {
        nbody->update(activeParams.m_timestep);
    }

    cutilSafeCall(cudaEventRecord(stopEvent, 0));  
    cudaEventSynchronize(stopEvent);

    float milliseconds = 0;
    cutilSafeCall( cudaEventElapsedTime(&milliseconds, startEvent, stopEvent));
    double interactionsPerSecond = 0;
    double gflops = 0;
    computePerfStats(interactionsPerSecond, gflops, milliseconds, iterations);
    
    printf("%d bodies, total time for %d iterations: %0.3f ms\n", 
           numBodies, iterations, milliseconds);
    printf("= %0.3f billion interactions per second\n", interactionsPerSecond);
    printf("= %0.3f GFLOP/s at %d flops per interaction\n", gflops, 20);   
}

void display()
{
    // update the simulation
    if (!bPause)
    {
        if (cycleDemo && (cutGetTimerValue(demoTimer) > demoTime))
        {
            activeDemo = (activeDemo + 1) % numDemos;
            selectDemo(activeDemo);
        }

        nbody->update(activeParams.m_timestep); 

        renderer->setPBO(nbody->getCurrentReadBuffer(), nbody->getNumBodies());
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    if (displayEnabled)
    {
        // view transform
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        for (int c = 0; c < 3; ++c)
        {
            camera_trans_lag[c] += (camera_trans[c] - camera_trans_lag[c]) * 
	      inertia;
            camera_rot_lag[c] += (camera_rot[c] - camera_rot_lag[c]) * inertia;
        }
        glTranslatef(camera_trans_lag[0], 
		     camera_trans_lag[1], 
		     camera_trans_lag[2]);
        glRotatef(camera_rot_lag[0], 1.0, 0.0, 0.0);
        glRotatef(camera_rot_lag[1], 0.0, 1.0, 0.0);

        renderer->setSpriteSize(activeParams.m_pointSize);
        renderer->display(displayMode);

        // display user interface.
        if (bShowSliders)
        {
            glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO); // invert color
            glEnable(GL_BLEND);
            paramlist->Render(0, 0);
            glDisable(GL_BLEND);
        }

        glutSwapBuffers();
    }

    fpsCount++;
    // this displays the frame rate updated every second (independent of frame rate)
    if (fpsCount >= fpsLimit) 
    {
        char fps[256];
        float milliseconds = 0;
    
        // stop timer
        /*
        cutilSafeCall(cudaEventRecord(stopEvent, 0));  
        cutilSafeCall(cudaEventSynchronize(stopEvent));
        cutilSafeCall( cudaEventElapsedTime(&milliseconds, startEvent, stopEvent));
        */
        
        gettimeofday(&stopTime, 0);
        milliseconds = (float)(stopTime.tv_sec - startTime.tv_sec) * 1000.0f + 
        	(float)(stopTime.tv_usec - startTime.tv_usec) / 1000.0f;

        
        milliseconds /= (float)fpsCount;
        double interactionsPerSecond = 0;
        double gflops = 0;
        computePerfStats(interactionsPerSecond, gflops, milliseconds, 1);

        float ifps = 1.f / (milliseconds / 1000.f);
        sprintf(fps, 
		"CUDA N-Body (%d bodies): "
		"%0.1f fps | %0.1f BIPS | %0.1f GFLOP/s", 
		numBodies, ifps, interactionsPerSecond, gflops);  
        glutSetWindowTitle(fps);
        fpsCount = 0; 
        fpsLimit = (ifps > 1.f) ? (int)ifps : 1;
        if (bPause) fpsLimit = 0;
        
        // restart timer
        //cutilSafeCall(cudaEventRecord(startEvent, 0));
        gettimeofday(&startTime, 0);
    }

    glutReportErrors();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float) w / (float) h, 0.1, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);
}

void mouse(int button, int state, int x, int y)
{
    if (bShowSliders) 
    {
	    // call list mouse function
        if (paramlist->Mouse(x, y, button, state))
        {
            nbody->setSoftening(activeParams.m_softening);
            nbody->setDamping(activeParams.m_damping);
        }
    }
    
    int mods;

    if (state == GLUT_DOWN)
        buttonState |= 1<<button;
    else if (state == GLUT_UP)
        buttonState = 0;

    mods = glutGetModifiers();
    if (mods & GLUT_ACTIVE_SHIFT) 
    {
        buttonState = 2;
    } 
    else if (mods & GLUT_ACTIVE_CTRL) 
    {
        buttonState = 3;
    }

    ox = x; oy = y;

    glutPostRedisplay();
}

void motion(int x, int y)
{

    if (bShowSliders) 
    {
        // call parameter list motion function
        if (paramlist->Motion(x, y))
	    {
            nbody->setSoftening(activeParams.m_softening);
            nbody->setDamping(activeParams.m_damping);
            glutPostRedisplay();
	        return;
        }
    }

    float dx = x - ox;
    float dy = y - oy;

    if (buttonState == 3) 
    {
        // left+middle = zoom
        camera_trans[2] += (dy / 100.0) * 0.5 * fabs(camera_trans[2]);
    } 
    else if (buttonState & 2) 
    {
        // middle = translate
        camera_trans[0] += dx / 100.0;
        camera_trans[1] -= dy / 100.0;
    }
    else if (buttonState & 1) 
    {
        // left = rotate
        camera_rot[0] += dy / 5.0;
        camera_rot[1] += dx / 5.0;
    }
    
    ox = x; oy = y;
    glutPostRedisplay();
}

// commented out to remove unused parameter warnings in Linux
void key(unsigned char key, int /*x*/, int /*y*/)
{
    switch (key) 
    {
    case ' ':
        bPause = !bPause;
        break;
    case '\033':
    case 'q':
        exit(0);
        break;
    case '`':
        bShowSliders = !bShowSliders;
        break;
    case 'p':
        displayMode = (ParticleRenderer::DisplayMode)
                      ((displayMode + 1) % ParticleRenderer::PARTICLE_NUM_MODES);
        break;
    case 'c':
        cycleDemo = !cycleDemo;
        printf("Cycle Demo Parameters: %s\n", cycleDemo ? "ON" : "OFF");
        break;
    case '[':
        activeDemo = (activeDemo == 0) ? numDemos - 1 : (activeDemo - 1) % numDemos;
        selectDemo(activeDemo);
        break;
    case ']':
        activeDemo = (activeDemo + 1) % numDemos;
        selectDemo(activeDemo);
        break;
    case 'd':
        displayEnabled = !displayEnabled;
        break;
    case 'O':
        activeParams.print();
        break;
    case '1':
        reset(nbody, numBodies, NBODY_CONFIG_SHELL);
        break;
    case '2':
        reset(nbody, numBodies, NBODY_CONFIG_RANDOM);
        break;
    case '3':
        reset(nbody, numBodies, NBODY_CONFIG_EXPAND);
        break;
    }

    glutPostRedisplay();
}

void special(int key, int x, int y)
{
    paramlist->Special(key, x, y);
    glutPostRedisplay();
}

void idle(void)
{
    glutPostRedisplay();
}


//////////////////////////////////////////////////////////////////////////////
// Program main
//////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    printf("Run \"nbody -benchmark [-n=<numBodies>]\" to measure perfomance.\n\n");
    
    bool benchmark = 
        (cutCheckCmdLineFlag(argc, (const char**) argv, "benchmark") != 0);

    bool compareToCPU = 
        ((cutCheckCmdLineFlag(argc, (const char**) argv, "compare") != 0) ||
        !(cutCheckCmdLineFlag(argc, (const char**) argv, "noqatest")  != 0));

    bool regression = 
        (cutCheckCmdLineFlag(argc, (const char**) argv, "regression") != 0);

    int devID;
    cudaDeviceProp props;

    // nBody has a mode that allows it to be run without using GL interop
    if (benchmark || compareToCPU || regression) {
				/*
        if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
            cutilDeviceInit(argc, argv);
        } else {
            devID = cutGetMaxGflopsDeviceId();
            cudaSetDevice( devID );
        } */
    } 
    else 
    { 
        // This mode shows the OpenGL results rendered
        // First initialize OpenGL context, so we can properly set the GL for CUDA.
        // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
        glutInitWindowSize(720, 480);
        glutCreateWindow("CUDA n-body system");

        GLenum err = glewInit();
        if (GLEW_OK != err)
        {
            printf("GLEW Error: %s\n", glewGetErrorString(err));
        }
        else
        {
#if   defined(WIN32)
            wglSwapIntervalEXT(0);
#elif defined(LINUX)
            glxSwapIntervalSGI(0);
#endif      
        }
    	
        initGL();
        initParameters();
    	
        if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
            cutilGLDeviceInit(argc, argv);
        } else {
            devID = cutGetMaxGflopsDeviceId();
            cudaGLSetGLDevice( devID );
        }
    }


    // get number of SMs on this GPU
    cutilSafeCall(cudaGetDevice(&devID));
    cutilSafeCall(cudaGetDeviceProperties(&props, devID));

    numIterations = 0;
    int p = 256;
    int q = 1;

    cutGetCmdLineArgumenti(argc, (const char**) argv, "i", &numIterations);
    cutGetCmdLineArgumenti(argc, (const char**) argv, "p", &p);
    cutGetCmdLineArgumenti(argc, (const char**) argv, "q", &q);


    // default number of bodies is #SMs * 4 * CTA size
    numBodies = compareToCPU ? 4096 : p*q*4*props.multiProcessorCount;

    cutGetCmdLineArgumenti(argc, (const char**) argv, "n", &numBodies);

    switch (numBodies)
    {
    case 1024:
        activeParams.m_clusterScale = 1.52f;
        activeParams.m_velocityScale = 2.f;
        break;
    case 2048:
        activeParams.m_clusterScale = 1.56f;
        activeParams.m_velocityScale = 2.64f;
        break;
    case 4096:
        activeParams.m_clusterScale = 1.68f;
        activeParams.m_velocityScale = 2.98f;
        break;
    case 8192:
        activeParams.m_clusterScale = 1.98f;
        activeParams.m_velocityScale = 2.9f;
        break;
    default:
    case 16384:
        activeParams.m_clusterScale = 1.54f;
        activeParams.m_velocityScale = 8.f;
        break;
    case 32768:
        activeParams.m_clusterScale = 1.44f;
        activeParams.m_velocityScale = 11.f;
        break;
    }

    if (q * p > 256)
    {
        p = 256 / q;
        printf("Setting p=%d, q=%d to maintain %d threads per block\n", p, q, 256);
    }

    if (q == 1 && numBodies < p)
    {
        p = numBodies;
    }

    init(numBodies, p, q, !(benchmark || compareToCPU));
    
    reset(nbody, numBodies, NBODY_CONFIG_SHELL, !(benchmark || compareToCPU));


    if (benchmark)
    {
        if (numIterations <= 0) 
            numIterations = 100;
        runBenchmark(numIterations);
    }
    else if (compareToCPU || regression)
    {
        compareResults(regression, numBodies);
    }
    else
    {
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
        glutMotionFunc(motion);
        glutKeyboardFunc(key);
        glutSpecialFunc(special);
        glutIdleFunc(idle);

        cutilSafeCall(cudaEventRecord(startEvent, 0));
        glutMainLoop();
    }

    if (nbodyCPU)
        delete nbodyCPU;
    if (nbodyCUDA)
        delete nbodyCUDA;

    if (hPos)
        delete [] hPos;
    if (hVel)
        delete [] hVel;
    if (hColor)
        delete [] hColor;

    cutilSafeCall(cudaEventDestroy(startEvent));
    cutilSafeCall(cudaEventDestroy(stopEvent));
    cutilCheckError(cutDeleteTimer(demoTimer));

    return 0;
}

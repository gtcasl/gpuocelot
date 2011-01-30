/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
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
#include <shrUtils.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>

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

int g_SMVersion = 0x10;
bool benchmark = false;
bool compareToCPU = false;
int p = 256;
int q = 1;
bool useHostMem = false;
bool fp64 = false;
bool useCpu = false;
bool displayEnabled = true;
bool bPause = false;
bool bFullscreen = false;
bool bDispInteractions = false;
bool bSupportDouble = false;
int flopsPerInteraction = 20;

char deviceName[100];

enum { M_VIEW = 0, M_MOVE };

#ifdef __DEVICE_EMULATION__
int numBodies = 1024;
#else
int numBodies = 16384;
#endif

int numIterations = 0; // run until exit

void computePerfStats(double &interactionsPerSecond, double &gflops, 
                      float milliseconds, int iterations)
{
    // double precision uses intrinsic operation followed by refinement,
    // resulting in higher operation count per interaction.
    // (Note Astrophysicists use 38 flops per interaction no matter what,
    // based on "historical precident", but they are using FLOP/s as a 
    // measure of "science throughput". We are using it as a measure of 
    // hardware throughput.  They should really use interactions/s...
    // const int flopsPerInteraction = fp64 ? 30 : 20; 
    interactionsPerSecond = (float)numBodies * (float)numBodies;
    interactionsPerSecond *= 1e-9 * iterations * 1000 / milliseconds;
    gflops = interactionsPerSecond * (float)flopsPerInteraction;
}


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

    void print() { shrLog("{ %f, %f, %f, %f, %f, %f, %f, %f, %f },\n", 
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
float demoTime = 10000.0f; // ms
unsigned int demoTimer = 0;
unsigned int timer;

// run multiple iterations to compute an average sort time

NBodyParams activeParams = demoParams[activeDemo];

// The UI.
ParamListGL *paramlist;  // parameter list
bool bShowSliders = true;

// fps
static int fpsCount = 0;
static int fpsLimit = 5;
//unsigned int timer = 0;
cudaEvent_t startEvent, stopEvent;
cudaEvent_t hostMemSyncEvent;

template <typename T>
class NBodyDemo
{
public:
    static void Create()
    {
        m_singleton = new NBodyDemo;
    }
    static void Destroy()
    {
        delete m_singleton;
    }

    static void init(int numBodies, int p, int q, bool usePBO, bool useHostMem, bool useCpu)
    {
        m_singleton->_init(numBodies, p, q, usePBO, useHostMem, useCpu);
    }

    static void reset(int numBodies, NBodyConfig config)
    {
        m_singleton->_reset(numBodies, config);
    }

    static void selectDemo(int index)
    {
        m_singleton->_selectDemo(index);
    }

    static void compareResults(int numBodies)
    {
        m_singleton->_compareResults(numBodies);
    }

    static void runBenchmark(int iterations)
    {
        m_singleton->_runBenchmark(iterations);
    }

    static void updateParams()
    {
        m_singleton->m_nbody->setSoftening(activeParams.m_softening);
        m_singleton->m_nbody->setDamping(activeParams.m_damping);
    }
    
    static void updateSimulation()
    {
        m_singleton->m_nbody->update(activeParams.m_timestep);
    }

    static void display()
    {
        m_singleton->m_renderer->setSpriteSize(activeParams.m_pointSize);

        if (useHostMem)
        {
            // This event sync is required because we are rendering from the host memory that CUDA is 
            // writing.  If we don't wait until CUDA is done updating it, we will render partially 
            // updated data, resulting in a jerky frame rate.
            if (!useCpu)
                cudaEventSynchronize(hostMemSyncEvent);
            m_singleton->m_renderer->setPositions(
                m_singleton->m_nbody->getArray(BODYSYSTEM_POSITION), 
                m_singleton->m_nbody->getNumBodies());
        }
        else
        {
            m_singleton->m_renderer->setPBO(m_singleton->m_nbody->getCurrentReadBuffer(), 
                                            m_singleton->m_nbody->getNumBodies(),
                                            (sizeof(T) > 4));
        }

        // display particles
        m_singleton->m_renderer->display(displayMode);
    }

    static void getArrays(T *pos, T *vel)
    {
        T* _pos = m_singleton->m_nbody->getArray(BODYSYSTEM_POSITION);
        T* _vel = m_singleton->m_nbody->getArray(BODYSYSTEM_VELOCITY);
        memcpy(pos, _pos, m_singleton->m_nbody->getNumBodies() * 4 * sizeof(T));
        memcpy(vel, _vel, m_singleton->m_nbody->getNumBodies() * 4 * sizeof(T));
    }

    static void setArrays(const T *pos, const T *vel)
    {
        if (pos != m_singleton->m_hPos)
            memcpy(m_singleton->m_hPos, pos, numBodies * 4 * sizeof(T));
        if (vel != m_singleton->m_hVel)
            memcpy(m_singleton->m_hVel, vel, numBodies * 4 * sizeof(T));
        m_singleton->m_nbody->setArray(BODYSYSTEM_POSITION, m_singleton->m_hPos);
        m_singleton->m_nbody->setArray(BODYSYSTEM_VELOCITY, m_singleton->m_hVel);
        
        if (!benchmark && !useCpu && !compareToCPU)
            m_singleton->_resetRenderer();
    }

private:
    static NBodyDemo *m_singleton;

    BodySystem<T>     *m_nbody;
    BodySystemCUDA<T> *m_nbodyCuda;
    BodySystemCPU<T>  *m_nbodyCpu;

    ParticleRenderer *m_renderer;

    T* m_hPos;
    T* m_hVel;
    float* m_hColor;

private:
    NBodyDemo() 
        : m_nbody(0),
        m_nbodyCuda(0),
        m_nbodyCpu(0),
        m_hPos(0),
        m_hVel(0),
        m_hColor(0)
    {

    }

    ~NBodyDemo() 
    {
        if (m_nbodyCpu)
            delete m_nbodyCpu;
        if (m_nbodyCuda)
            delete m_nbodyCuda;

        if (m_hPos)
            delete [] m_hPos;
        if (m_hVel)
            delete [] m_hVel;
        if (m_hColor)
            delete [] m_hColor;

        cutilSafeCall(cudaEventDestroy(startEvent));
        cutilSafeCall(cudaEventDestroy(stopEvent));
        cutilSafeCall(cudaEventDestroy(hostMemSyncEvent));
        cutilCheckError(cutDeleteTimer(demoTimer));

        delete m_renderer;
    }

    void _init(int numBodies, int p, int q, bool bUsePBO, bool useHostMem, bool useCpu)
    {
        if (useCpu)
        {
            m_nbodyCpu = new BodySystemCPU<T>(numBodies);
            m_nbody = m_nbodyCpu;
            m_nbodyCuda = 0;
        }
        else
        {
            m_nbodyCuda = new BodySystemCUDA<T>(numBodies, p, q, bUsePBO, useHostMem);
            m_nbody = m_nbodyCuda;
            m_nbodyCpu = 0;
        }

        // allocate host memory
        m_hPos = new T[numBodies*4];
        m_hVel = new T[numBodies*4];
        m_hColor = new float[numBodies*4];

        m_nbody->setSoftening(activeParams.m_softening);
        m_nbody->setDamping(activeParams.m_damping);
		
        if (useCpu) {
            cutilCheckError(cutCreateTimer(&timer));
            cutilCheckError(cutStartTimer(timer));
        } else {
            cutilSafeCall( cudaEventCreate(&startEvent) );
            cutilSafeCall( cudaEventCreate(&stopEvent) );
            cutilSafeCall( cudaEventCreate(&hostMemSyncEvent) );
        }

        if (!benchmark && !compareToCPU)
        {
            m_renderer = new ParticleRenderer;
            _resetRenderer();
        }

        cutilCheckError(cutCreateTimer(&demoTimer));
        cutilCheckError(cutStartTimer(demoTimer));
    }

    void _reset(int numBodies, NBodyConfig config)
    {
        randomizeBodies(config, m_hPos, m_hVel, m_hColor, 
            activeParams.m_clusterScale, 
            activeParams.m_velocityScale, 
            numBodies, true);

        setArrays(m_hPos, m_hVel);
    }

    void _reset(int numBodies, T* pos, T* vel)
    {
        setArrays(pos, vel);
    }

    void _resetRenderer()
    {
        if (fp64)
        {
            float color[4] = { 0.4f, 0.8f, 0.1f, 1.0f};
            m_renderer->setBaseColor(color);
        }
        else
        {
            float color[4] = { 1.0f, 0.6f, 0.3f, 1.0f};
            m_renderer->setBaseColor(color);
        }

        m_renderer->setColors(m_hColor, m_nbody->getNumBodies());
        m_renderer->setSpriteSize(activeParams.m_pointSize);  
    }

    void _selectDemo(int index)
    {
        assert(index < numDemos);

        activeParams = demoParams[index];
        camera_trans[0] = camera_trans_lag[0] = activeParams.m_x;
        camera_trans[1] = camera_trans_lag[1] = activeParams.m_y;
        camera_trans[2] = camera_trans_lag[2] = activeParams.m_z;
        reset(numBodies, NBODY_CONFIG_SHELL);
        cutilCheckError(cutResetTimer(demoTimer));
    }

    void _compareResults(int numBodies)
    {
        assert(m_nbodyCuda);

        m_nbody->update(0.001f);

        {
            m_nbodyCpu = new BodySystemCPU<T>(numBodies);

            m_nbodyCpu->setArray(BODYSYSTEM_POSITION, m_hPos);
            m_nbodyCpu->setArray(BODYSYSTEM_VELOCITY, m_hVel);

            m_nbodyCpu->update(0.001f);

            T* cudaPos = m_nbodyCuda->getArray(BODYSYSTEM_POSITION);
            T* cpuPos  = m_nbodyCpu->getArray(BODYSYSTEM_POSITION);

            T tolerance = 0.0005;
            bool passed = true;
            for (int i = 0; i < numBodies; i++)
            {
                if (abs(cpuPos[i] - cudaPos[i]) > tolerance)
                {
                    passed = false;
                    shrLog("Error: (host)%lf != (device)%lf\n", cpuPos[i], cudaPos[i]);
                }
            }
            shrLog( "Test %s\n", passed ? "PASSED" : "FAILED");
        }
    }

    void _runBenchmark(int iterations)
    {
        // once without timing to prime the GPU
        if (!useCpu)
            m_nbody->update(activeParams.m_timestep);

        if (useCpu)
        {
            cutCreateTimer(&timer);
            cutStartTimer(timer);
        }
        else
        {
            cutilSafeCall(cudaEventRecord(startEvent, 0));
        }

        for (int i = 0; i < iterations; ++i)
        {
            m_nbody->update(activeParams.m_timestep);
        }

        float milliseconds = 0;

        if (useCpu)
        {
            cutStopTimer(timer);
            milliseconds = cutGetTimerValue(timer);
            cutDeleteTimer(timer);
        }
        else
        {
            cutilSafeCall(cudaEventRecord(stopEvent, 0));  
            cutilSafeCall(cudaEventSynchronize(stopEvent));
            cutilSafeCall( cudaEventElapsedTime(&milliseconds, startEvent, stopEvent));
        }
        
        double interactionsPerSecond = 0;
        double gflops = 0;
        computePerfStats(interactionsPerSecond, gflops, milliseconds, iterations);

        shrLog("%d bodies, total time for %d iterations: %.3f ms\n", 
            numBodies, iterations, milliseconds);
        shrLog("= %.3f billion interactions per second\n", interactionsPerSecond);
        shrLog("= %.3f %s-precision GFLOP/s at %d flops per interaction\n", gflops, 
               (sizeof(T) > 4) ? "double" : "single", flopsPerInteraction);   
    }


};

template <> NBodyDemo<double> *NBodyDemo<double>::m_singleton = 0;
template <> NBodyDemo<float> *NBodyDemo<float>::m_singleton = 0;

template <typename T_new, typename T_old>
void switchDemoPrecision()
{
    cudaThreadSynchronize();

    fp64 = !fp64;
    flopsPerInteraction = fp64 ? 30 : 20;
    
    T_old *oldPos = new T_old[numBodies * 4];
    T_old *oldVel = new T_old[numBodies * 4];
    
    NBodyDemo<T_old>::getArrays(oldPos, oldVel);
   
    // convert float to double
    T_new *newPos = new T_new[numBodies * 4];
    T_new *newVel = new T_new[numBodies * 4];

    for (int i = 0; i < numBodies * 4; i++)
    {
        newPos[i] = oldPos[i];
        newVel[i] = oldVel[i];
    }
    
    NBodyDemo<T_new>::setArrays(newPos, newVel);

    cudaThreadSynchronize();

    delete [] oldPos;
    delete [] oldVel;
    delete [] newPos;
    delete [] newVel;
}


// check for OpenGL errors
void checkGLErrors(const char *s)
{
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR) {
        fprintf(stderr, "%s: error - %s\n", s, (char *) gluErrorString(error));
    }
}

void initGL(int *argc, char** argv)
{  
    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(720, 480);
    glutCreateWindow("CUDA n-body system");
    if (bFullscreen)
        glutFullScreen();
    GLenum err = glewInit();

    if (GLEW_OK != err)
    {
        shrLog("GLEW Error: %s\n", glewGetErrorString(err));
        exit(-1);
    }
    else if (!glewIsSupported("GL_VERSION_2_0 "
                         "GL_VERSION_1_5 "
			             "GL_ARB_multitexture "
                         "GL_ARB_vertex_buffer_object")) 
    {
        fprintf(stderr, "Required OpenGL extensions missing.");
        cudaThreadExit();
        exit(-1);
    }
    else
    {
#if   defined(WIN32)
        wglSwapIntervalEXT(0);
#elif defined(LINUX)
        glxSwapIntervalSGI(0);
#endif      
    }

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
   
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

void selectDemo(int activeDemo)
{
    if (fp64)
        NBodyDemo<double>::selectDemo(activeDemo);
    else
        NBodyDemo<float>::selectDemo(activeDemo);
}

void updateSimulation()
{
    if (fp64)
        NBodyDemo<double>::updateSimulation();
    else
        NBodyDemo<float>::updateSimulation();
}

void displayNBodySystem()
{
    if (fp64)
        NBodyDemo<double>::display();
    else
        NBodyDemo<float>::display();
}

void display()
{
    static double gflops = 0;
    static double ifps = 0;
    static double interactionsPerSecond = 0;

    // update the simulation
    if (!bPause)
    {
        if (cycleDemo && (cutGetTimerValue(demoTimer) > demoTime))
        {
            activeDemo = (activeDemo + 1) % numDemos;
            selectDemo(activeDemo);
        }

        updateSimulation(); 
        if (!useCpu)
            cudaEventRecord(hostMemSyncEvent, 0);  // insert an event to wait on before rendering
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    if (displayEnabled)
    {
        // view transform
        {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            for (int c = 0; c < 3; ++c)
            {
                camera_trans_lag[c] += (camera_trans[c] - camera_trans_lag[c]) * inertia;
                camera_rot_lag[c] += (camera_rot[c] - camera_rot_lag[c]) * inertia;
            }

            glTranslatef(camera_trans_lag[0], camera_trans_lag[1], camera_trans_lag[2]);
            glRotatef(camera_rot_lag[0], 1.0, 0.0, 0.0);
            glRotatef(camera_rot_lag[1], 0.0, 1.0, 0.0);
        }

        displayNBodySystem();

        // display user interface
        if (bShowSliders)
        {
            glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO); // invert color
            glEnable(GL_BLEND);
            paramlist->Render(0, 0);
            glDisable(GL_BLEND);
        }

        if (bFullscreen)
        {
            beginWinCoords();
            char msg0[256], msg1[256], msg2[256];

            if (bDispInteractions) {
               sprintf(msg1, "%0.2f billion interactions per second", interactionsPerSecond);
            } else {
               sprintf(msg1, "%0.2f GFLOP/s", gflops);
            }
            sprintf(msg0, "%s", deviceName);
            sprintf(msg2, "%0.2f FPS [%s | %d bodies]", 
                    ifps, fp64 ? "double precision" : "single precision", numBodies);  

            glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO); // invert color
            glEnable(GL_BLEND);
            glColor3f(0.46f, 0.73f, 0.0f);
            glPrint(80, glutGet(GLUT_WINDOW_HEIGHT) - 122, msg0, GLUT_BITMAP_TIMES_ROMAN_24);
            glColor3f(1.0f, 1.0f, 1.0f);
            glPrint(80, glutGet(GLUT_WINDOW_HEIGHT) - 96, msg2, GLUT_BITMAP_TIMES_ROMAN_24);
            glColor3f(1.0f, 1.0f, 1.0f);
            glPrint(80, glutGet(GLUT_WINDOW_HEIGHT) - 70, msg1, GLUT_BITMAP_TIMES_ROMAN_24);
            glDisable(GL_BLEND);

            endWinCoords();          
        }

        glutSwapBuffers();
    }

    fpsCount++;
    // this displays the frame rate updated every second (independent of frame rate)
    if (fpsCount >= fpsLimit) 
    {
        char fps[256];
    
        float milliseconds = 1;
        // stop timer
        if (useCpu) {
            milliseconds = cutGetTimerValue(timer);
            cutilCheckError(cutResetTimer(timer));
        } else {
            cutilSafeCall(cudaEventRecord(stopEvent, 0));  
            cutilSafeCall(cudaEventSynchronize(stopEvent));
            cutilSafeCall( cudaEventElapsedTime(&milliseconds, startEvent, stopEvent));
        }
        
        milliseconds /= (float)fpsCount;
        computePerfStats(interactionsPerSecond, gflops, milliseconds, 1);

        ifps = 1.f / (milliseconds / 1000.f);
        sprintf(fps, 
		        "CUDA N-Body (%d bodies): "
		        "%0.1f fps | %0.1f BIPS | %0.1f GFLOP/s | %s", 
		        numBodies, ifps, interactionsPerSecond, gflops,
                fp64 ? "double precision" : "single precision");  

        glutSetWindowTitle(fps);
        fpsCount = 0; 
        fpsLimit = (ifps > 1.f) ? (int)ifps : 1;
        if (bPause) fpsLimit = 0;
        
        // restart timer
        if (!useCpu) {
            cutilSafeCall(cudaEventRecord(startEvent, 0));
        }
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

void updateParams()
{
    if (fp64)
        NBodyDemo<double>::updateParams();
    else
        NBodyDemo<float>::updateParams();
}

void mouse(int button, int state, int x, int y)
{
    if (bShowSliders) 
    {
	    // call list mouse function
        if (paramlist->Mouse(x, y, button, state))
        {
           updateParams();
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
            updateParams();
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
    case 27: // escape
    case 'q':
    case 'Q':
        exit(0);
        break;
    case 13: // return
        if (bSupportDouble)
        {
            if (fp64)
                switchDemoPrecision<float, double>();
            else
                switchDemoPrecision<double, float>();

			shrLog("> %s precision floating point simulation\n", fp64 ? "Double" : "Single");
        }

		break;
    case '`':
        bShowSliders = !bShowSliders;
        break;
	case 'g':
	case 'G':
		bDispInteractions = !bDispInteractions;
		break;
    case 'p':
    case 'P':
        displayMode = (ParticleRenderer::DisplayMode)
                      ((displayMode + 1) % ParticleRenderer::PARTICLE_NUM_MODES);
        break;
    case 'c':
    case 'C':
        cycleDemo = !cycleDemo;
        shrLog("Cycle Demo Parameters: %s\n", cycleDemo ? "ON" : "OFF");
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
    case 'D':
        displayEnabled = !displayEnabled;
        break;
    case 'o':
    case 'O':
        activeParams.print();
        break;
    case '1':
        if (fp64)
            NBodyDemo<double>::reset(numBodies, NBODY_CONFIG_SHELL);
        else
            NBodyDemo<float>::reset(numBodies, NBODY_CONFIG_SHELL);
        break;
    case '2':
        if (fp64)
            NBodyDemo<double>::reset(numBodies, NBODY_CONFIG_RANDOM);
        else
            NBodyDemo<float>::reset(numBodies, NBODY_CONFIG_RANDOM);
        break;
    case '3':
        if (fp64)
            NBodyDemo<double>::reset(numBodies, NBODY_CONFIG_EXPAND);
        else
            NBodyDemo<float>::reset(numBodies, NBODY_CONFIG_EXPAND);
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

void
showHelp()
{
    shrLog("\n> Command line options\n");
    shrLog("\t-fullscreen (run n-body simulation in fullscreen mode)\n");
    shrLog("\t-fp64       (use double precision floating point values for simulation)\n");
    shrLog("\t-hostmem  (stores simulation data in host memory)\n");
    shrLog("\t-benchmark (run benchmark to measure perfomance) \n");
    shrLog("\t-n=<numBodies> (set particle number) \n"); 
    shrLog("\t-compare  (compare to CPU results)\n");
    shrLog("\t-device=n          (where n=0,1,2.... for the GPU device)\n\n");
    shrLog("\t-cpu (run n-body simulation on the CPU)");
}

//////////////////////////////////////////////////////////////////////////////
// Program main
//////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "help") ) {
        showHelp();
        return 0;
    }

    shrLog("Run \"nbody -benchmark [-n=<numBodies>]\" to measure perfomance.\n");
	shrLog("\t-fullscreen (run n-body simulation in fullscreen mode)\n");
	shrLog("\t-fp64       (use double precision floating point values for simulation)\n");
//    shrLog("\t-hostmem  (stores simulation data in host memory)\n");
//    shrLog("\t-cpu      (performs simulation on the host)\n");
    shrLog("\n");

	bFullscreen = 
        (cutCheckCmdLineFlag(argc, (const char**) argv, "fullscreen") != 0);
    if (bFullscreen)
        bShowSliders = false;

    benchmark = 
        (cutCheckCmdLineFlag(argc, (const char**) argv, "benchmark") != 0);

    compareToCPU = 
        ((cutCheckCmdLineFlag(argc, (const char**) argv, "compare") != 0) ||
        (cutCheckCmdLineFlag(argc, (const char**) argv, "qatest")  != 0));

    useHostMem = 
        (cutCheckCmdLineFlag(argc, (const char**) argv, "hostmem") != 0);

    fp64 = 
        (cutCheckCmdLineFlag(argc, (const char**) argv, "fp64") != 0);

    flopsPerInteraction = fp64 ? 30 : 20;

    useCpu = 
        (cutCheckCmdLineFlag(argc, (const char**) argv, "cpu") != 0);

	shrLog("> %s mode\n", bFullscreen ? "Fullscreen" : "Windowed");
	shrLog("> Simulation data stored in %s memory\n", useHostMem ? "system" : "video" );
	shrLog("> %s precision floating point simulation\n", fp64 ? "Double" : "Single");

    int devID;
    cudaDeviceProp props;

    // Initialize GL and GLUT if necessary
    if (!benchmark && !compareToCPU)
    {
        initGL(&argc, argv);
        initParameters();
    }
    
    if (useCpu) 
    {
        useHostMem = true;
        compareToCPU = false;
        bSupportDouble = true;

#ifdef OPENMP
        shrLog("> Simulation with CPU using OpenMP\n");
#else
        shrLog("> Simulation with CPU\n");
#endif
    }
    else
    {
        // Now choose the CUDA Device
        // Either without GL interop:
        if (benchmark || compareToCPU || useHostMem) 
        {
            // Note if we are using host memory for the body system, we
            // don't use CUDA-GL interop.

            if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) 
            {
                cutilDeviceInit(argc, argv);
            } 
            else 
            {
                devID = cutGetMaxGflopsDeviceId();
                cudaSetDevice( devID );
            }
        } 
        else // or with GL interop:
        {    	
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

        strcpy(deviceName, props.name);
        shrLog("> Compute %d.%d CUDA device: [%s]\n", props.major, props.minor, props.name);

        if (useHostMem)
        {
#if CUDART_VERSION >= 2020
            if(!props.canMapHostMemory)
            {
                fprintf(stderr, "Device %d cannot map host memory!\n", devID);
                shrLog("Test PASSED");
                cutilExit(argc, argv);
            }
            cutilSafeCall(cudaSetDeviceFlags(cudaDeviceMapHost));
#else
            fprintf(stderr, "This CUDART version does not support <cudaDeviceProp.canMapHostMemory> field\n");
            shrLog("Test PASSED");
            cutilExit(argc, argv);
#endif
        }

        g_SMVersion = (props.major * 0x10) + (props.minor);

        if (props.major > 1 || props.minor >= 3)
            bSupportDouble = true;
        else if (fp64)
        {
            fprintf(stderr, "Device %d does not support double precision floating-point\n", devID);
            shrLog("Test PASSED\n");
            cutilExit(argc, argv);
        }
    }
	
    numIterations = 0;
    p = 0;
    q = 1;

    cutGetCmdLineArgumenti(argc, (const char**) argv, "i", &numIterations);
    cutGetCmdLineArgumenti(argc, (const char**) argv, "p", &p);
    cutGetCmdLineArgumenti(argc, (const char**) argv, "q", &q);

    if (p == 0) // p not set on command line
    {
        p = 256;
        if (q * p > 256)
        {
            p = 256 / q;
            shrLog("Setting p=%d, q=%d to maintain %d threads per block\n", p, q, 256);
        }
    }

    // default number of bodies is #SMs * 4 * CTA size
    if (useCpu)
#ifdef OPENMP
        numBodies = 8192;
#else
        numBodies = 4096;
#endif
    else
        numBodies = compareToCPU ? 4096 : p*q*4*props.multiProcessorCount;
    
    cutGetCmdLineArgumenti(argc, (const char**) argv, "n", &numBodies);

    if (q == 1 && numBodies < p)
    {
        p = numBodies;
    }


    if (numBodies <= 1024)
    {
        activeParams.m_clusterScale = 1.52f;
        activeParams.m_velocityScale = 2.f;
    }
    else if (numBodies <= 2048)
    {
        activeParams.m_clusterScale = 1.56f;
        activeParams.m_velocityScale = 2.64f;
    }
    else if (numBodies <= 4096)
    {
        activeParams.m_clusterScale = 1.68f;
        activeParams.m_velocityScale = 2.98f;
    }
    else if (numBodies <= 8192)
    {
        activeParams.m_clusterScale = 1.98f;
        activeParams.m_velocityScale = 2.9f;
    }
    else if (numBodies <= 16384)
    {
        activeParams.m_clusterScale = 1.54f;
        activeParams.m_velocityScale = 8.f;
    }
    else if (numBodies <= 32768)
    {
        activeParams.m_clusterScale = 1.44f;
        activeParams.m_velocityScale = 11.f;
    }

    // Create the demo -- either double (fp64) or float (fp32, default) implementation
    NBodyDemo<float>::Create();
    NBodyDemo<float>::init(numBodies, p, q, !(benchmark || compareToCPU || useHostMem), useHostMem, useCpu);
    NBodyDemo<float>::reset(numBodies, NBODY_CONFIG_SHELL);

    if (bSupportDouble)
    {
        NBodyDemo<double>::Create();
        NBodyDemo<double>::init(numBodies, p, q, !(benchmark || compareToCPU || useHostMem), useHostMem, useCpu);
        NBodyDemo<double>::reset(numBodies, NBODY_CONFIG_SHELL);
    }

    if (fp64)
    {
        if (benchmark)
        {
            if (numIterations <= 0) 
                numIterations = 10;
            else if (numIterations > 10)
            {
                printf("Advisory: setting a high number of iterations\n");
                printf("in benchmark mode may cause failure on Windows\n");
                printf("Vista and Win7. On these OSes, set iterations <= 10\n");
            }
            NBodyDemo<double>::runBenchmark(numIterations);
        }
        else if (compareToCPU)
        {
            NBodyDemo<double>::compareResults(numBodies);
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

            if (!useCpu) {
                cutilSafeCall(cudaEventRecord(startEvent, 0));
            }
            glutMainLoop();
        }

    }
    else
    {
        if (benchmark)
        {
            if (numIterations <= 0) 
                numIterations = 10;
            NBodyDemo<float>::runBenchmark(numIterations);
        }
        else if (compareToCPU)
        {
            NBodyDemo<float>::compareResults(numBodies);
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

            if (!useCpu)
                cutilSafeCall(cudaEventRecord(startEvent, 0));
            glutMainLoop();
        }
    }

    
    
    return 0;
}

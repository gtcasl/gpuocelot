/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation. 
 * Any use, reproduction, disclosure, or distribution of this software 
 * and related documentation without an express license agreement from
 * NVIDIA Corporation is strictly prohibited.
 *
 * Please refer to the applicable NVIDIA end user license agreement (EULA) 
 * associated with this source code for terms and conditions that govern 
 * your use of this NVIDIA software.
 * 
 */

#include "bodysystemcpu.h"

#include <assert.h>
#include <memory.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <cutil_inline.h>
#include <algorithm>

BodySystemCPU::BodySystemCPU(int numBodies)
: BodySystem(numBodies),
  m_force(0),
  m_softeningSquared(.00125f),
  m_damping(0.995f),
  m_currentRead(0),
  m_currentWrite(0)
{
    m_pos[0] = m_pos[1] = 0;
    m_vel[0] = m_vel[1] = 0;

    _initialize(numBodies);
}

BodySystemCPU::~BodySystemCPU()
{
    _finalize();
    m_numBodies = 0;
}

void
BodySystemCPU::_initialize(int numBodies)
{
    assert(!m_bInitialized);

    m_numBodies = numBodies;

    m_pos[0] = new float[m_numBodies*4];
    m_pos[1] = new float[m_numBodies*4];
    m_vel[0] = new float[m_numBodies*4];
    m_vel[1] = new float[m_numBodies*4];
    m_force  = new float[m_numBodies*4];

    memset(m_pos[0], 0, m_numBodies*4*sizeof(float));
    memset(m_pos[1], 0, m_numBodies*4*sizeof(float));
    memset(m_vel[0], 0, m_numBodies*4*sizeof(float));
    memset(m_vel[1], 0, m_numBodies*4*sizeof(float));
    memset(m_force, 0, m_numBodies*4*sizeof(float));
    
    m_bInitialized = true;
}

void
BodySystemCPU::_finalize()
{
    assert(m_bInitialized);

    delete [] m_pos[0];
    delete [] m_pos[1];
    delete [] m_vel[0];
    delete [] m_vel[1];
    delete [] m_force;
}


void 
BodySystemCPU::update(float deltaTime)
{
    assert(m_bInitialized);

    _integrateNBodySystem(deltaTime);

    std::swap(m_currentRead, m_currentWrite);
}

float* 
BodySystemCPU::getArray(BodyArray array)
{
    assert(m_bInitialized);
 
    float* data = 0;
    switch (array)
    {
    default:
    case BODYSYSTEM_POSITION:
        data = m_pos[m_currentRead];
        break;
    case BODYSYSTEM_VELOCITY:
        data = m_vel[m_currentRead];
        break;
    }

    return data;
}

void 
BodySystemCPU::setArray(BodyArray array, const float* data)
{
    assert(m_bInitialized);

    float* target = 0;

    switch (array)
    {
    default:
    case BODYSYSTEM_POSITION:
        target = m_pos[m_currentRead];
        break;
    case BODYSYSTEM_VELOCITY:
        target = m_vel[m_currentRead];
        break;
    }

    memcpy(target, data, m_numBodies*4*sizeof(float));
}

const float TOLERANCE = 3e-7f;
const float FUDGE_FACTOR = 0.025f;

extern void normalize(float vector[3]);
extern void bodyBodyInteraction(float accel[3], float posMass0[4], float posMass1[4], 
				float softeningSquared);

void
BodySystemCPU::_computeNBodyGravitation() 
{
    for(int i = 0; i < m_numBodies; ++i) 
    {
        m_force[i*4] = m_force[i*4+1] = m_force[i*4+2] = 0;

	    for(int j = 0; j < m_numBodies; ++j) 
	    {
	        float acc[3] = {0, 0, 0};		
	        bodyBodyInteraction(acc, &m_pos[m_currentRead][j*4], &m_pos[m_currentRead][i*4], 
				    m_softeningSquared);	
	        for (int k = 0; k < 3; ++k)
	        {
	            m_force[i*4+k] += acc[k];
	        }
	    }
    }
}

void 
BodySystemCPU::_integrateNBodySystem(float deltaTime)
{
    _computeNBodyGravitation();

    for (int i = 0; i < m_numBodies; ++i)
    {
        int index = 4*i;
        float pos[3], vel[3], force[3];
        pos[0] = m_pos[m_currentRead][index+0];
        pos[1] = m_pos[m_currentRead][index+1];
        pos[2] = m_pos[m_currentRead][index+2];
        float mass = m_pos[m_currentRead][index+3];
        
        vel[0] = m_vel[m_currentRead][index+0];
        vel[1] = m_vel[m_currentRead][index+1];
        vel[2] = m_vel[m_currentRead][index+2];
        float invMass = m_vel[m_currentRead][index+3];

        force[0] = m_force[index+0];
        force[1] = m_force[index+1];
        force[2] = m_force[index+2];
    
        // acceleration = force / mass; 
        // new velocity = old velocity + acceleration * deltaTime
        vel[0] += (force[0] * invMass) * deltaTime;
        vel[1] += (force[1] * invMass) * deltaTime;
        vel[2] += (force[2] * invMass) * deltaTime;

        vel[0] *= m_damping;
        vel[1] *= m_damping;
        vel[2] *= m_damping;

        // new position = old position + velocity * deltaTime
        pos[0] += vel[0] * deltaTime;
        pos[1] += vel[1] * deltaTime;
        pos[2] += vel[2] * deltaTime;

        m_pos[m_currentWrite][index+0] = pos[0];
        m_pos[m_currentWrite][index+1] = pos[1];
        m_pos[m_currentWrite][index+2] = pos[2];
        m_pos[m_currentWrite][index+3] = mass;

        m_vel[m_currentWrite][index+0] = vel[0];
        m_vel[m_currentWrite][index+1] = vel[1];
        m_vel[m_currentWrite][index+2] = vel[2];
        m_vel[m_currentWrite][index+3] = invMass;
    }

}

//struct float3 { float x, y, z; };

float3
scalevec(float3& vector, float scalar)
{
    float3 rt = vector;
    rt.x *= scalar;
    rt.y *= scalar;
    rt.z *= scalar;
    return rt;
}

float
normalize(float3& vector)
{
    float dist = sqrtf(vector.x*vector.x + vector.y*vector.y + vector.z*vector.z);
    if (dist > 1e-6)
    {
        vector.x /= dist;
	vector.y /= dist;
        vector.z /= dist;
    }
    return dist;
}

float 
dot(float3 v0, float3 v1)
{
    return v0.x*v1.x+v0.y*v1.y+v0.z*v1.z;
}

float3
cross(float3 v0, float3 v1)
{
    float3 rt;
    rt.x = v0.y*v1.z-v0.z*v1.y;
    rt.y = v0.z*v1.x-v0.x*v1.z;
    rt.z = v0.x*v1.y-v0.y*v1.x;	
    return rt;
}

// utility function
void randomizeBodies(NBodyConfig config, float* pos, float* vel, float* color, float clusterScale, float velocityScale, int numBodies)
{
    switch(config)
    {
    default:
    case NBODY_CONFIG_RANDOM:
        {
	    float scale = clusterScale * std::max(1.0f, numBodies / (1024.f));
            float vscale = velocityScale * scale;

	    int p = 0, v = 0;
            int i = 0;
	    while (i < numBodies) 
	    {
	        float3 point;
		//const int scale = 16;
		point.x = rand() / (float) RAND_MAX * 2 - 1;
		point.y = rand() / (float) RAND_MAX * 2 - 1;
		point.z = rand() / (float) RAND_MAX * 2 - 1;
                float lenSqr = dot(point, point);
                if (lenSqr > 1)
		    continue;
                float3 velocity;
                velocity.x = rand() / (float) RAND_MAX * 2 - 1;
		velocity.y = rand() / (float) RAND_MAX * 2 - 1;
		velocity.z = rand() / (float) RAND_MAX * 2 - 1;
                lenSqr = dot(velocity, velocity);
                if (lenSqr > 1)
                    continue;

		pos[p++] = point.x * scale; // pos.x
		pos[p++] = point.y * scale; // pos.y
		pos[p++] = point.z * scale; // pos.z
		pos[p++] = 1.0f; // mass
                
		vel[v++] = velocity.x * vscale; // pos.x
		vel[v++] = velocity.y * vscale; // pos.x
		vel[v++] = velocity.z * vscale; // pos.x
		vel[v++] = 1.0f; // inverse mass

                i++;
	    }
	}
	break;
    case NBODY_CONFIG_SHELL:
        {
            float scale = clusterScale;
            float vscale = scale * velocityScale;
            float inner = 2.5f * scale;
            float outer = 4.0f * scale;

            int p = 0, v=0;
            int i = 0;
            while (i < numBodies)//for(int i=0; i < numBodies; i++) 
            {
                float x, y, z;
                x = rand() / (float) RAND_MAX * 2 - 1;
                y = rand() / (float) RAND_MAX * 2 - 1;
                z = rand() / (float) RAND_MAX * 2 - 1;

                float3 point = {x, y, z};
                float len = normalize(point);
                if (len > 1)
                    continue;

                pos[p++] =  point.x * (inner + (outer - inner) * rand() / (float) RAND_MAX);
                pos[p++] =  point.y * (inner + (outer - inner) * rand() / (float) RAND_MAX);
                pos[p++] =  point.z * (inner + (outer - inner) * rand() / (float) RAND_MAX);
                pos[p++] = 1.0f;
                
                x = 0.0f; // * (rand() / (float) RAND_MAX * 2 - 1);
                y = 0.0f; // * (rand() / (float) RAND_MAX * 2 - 1);
                z = 1.0f; // * (rand() / (float) RAND_MAX * 2 - 1);
                float3 axis = {x, y, z};
                normalize(axis);
                                        
                if (1 - dot(point, axis) < 1e-6)
                {
                    axis.x = point.y;
                    axis.y = point.x;
                    normalize(axis);
                }
                //if (point.y < 0) axis = scalevec(axis, -1);
                float3 vv = {pos[4*i], pos[4*i+1], pos[4*i+2]};
                vv = cross(vv, axis);
                vel[v++] = vv.x * vscale;
                vel[v++] = vv.y * vscale;
                vel[v++] = vv.z * vscale;
                vel[v++] = 1.0f;

                i++;
            }
        }
        break;
    case NBODY_CONFIG_EXPAND:
        {
            float scale = clusterScale * std::max(1.0f, numBodies / (1024.f));
            float vscale = scale * velocityScale;

	    int p = 0, v = 0;
	    for(int i=0; i < numBodies;) 
	    {
		float3 point;
				
		point.x = rand() / (float) RAND_MAX * 2 - 1;
		point.y = rand() / (float) RAND_MAX * 2 - 1;
		point.z = rand() / (float) RAND_MAX * 2 - 1;

                float lenSqr = dot(point, point);
                if (lenSqr > 1)
                    continue;

		pos[p++] = point.x * scale; // pos.x
		pos[p++] = point.y * scale; // pos.y
		pos[p++] = point.z * scale; // pos.z
		pos[p++] = 1.0f; // mass
		vel[v++] = point.x * vscale; // pos.x
		vel[v++] = point.y * vscale; // pos.x
		vel[v++] = point.z * vscale; // pos.x
		vel[v++] = 1.0f; // inverse mass

                i++;
	    }
	}
	break;
    }

    if (color)
    {
        int v = 0;
        for(int i=0; i < numBodies; i++) 
        {
	    //const int scale = 16;
	    color[v++] = rand() / (float) RAND_MAX;
	    color[v++] = rand() / (float) RAND_MAX;
	    color[v++] = rand() / (float) RAND_MAX;
            color[v++] = 1.0f;
        }
    }

}

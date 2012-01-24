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

// These are helper functions for the SDK samples (string parsing, timers, etc)
#ifndef SDK_HELPER_H
#define SDK_HELPER_H

#pragma warning(disable:4996)

// includes, project
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <assert.h>
#include <exception.h>
#include <math.h>

#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

// includes, timer
#include <stopwatch_functions.h>
#include <string_helper.h>

#define MIN(a,b) ((a < b) ? a : b)
#define MAX(a,b) ((a > b) ? a : b)


// Beginning of GPU Architecture definitions
inline int _ConvertSMVer2Cores(int major, int minor)
{
    // Defines for GPU Architecture types (using the SM version to determine the # of cores per SM
    typedef struct {
       int SM; // 0xMm (hexidecimal notation), M = SM Major version, and m = SM minor version
       int Cores;
    } sSMtoCores;

    sSMtoCores nGpuArchCoresPerSM[] = 
    { { 0x10,  8 }, // Tesla Generation (SM 1.0) G80 class
      { 0x11,  8 }, // Tesla Generation (SM 1.1) G8x class
      { 0x12,  8 }, // Tesla Generation (SM 1.2) G9x class
      { 0x13,  8 }, // Tesla Generation (SM 1.3) GT200 class
      { 0x20, 32 }, // Fermi Generation (SM 2.0) GF100 class
      { 0x21, 48 }, // Fermi Generation (SM 2.1) GF10x class
      {   -1, -1 }
    };

    int index = 0;
    while (nGpuArchCoresPerSM[index].SM != -1) {
       if (nGpuArchCoresPerSM[index].SM == ((major << 4) + minor) ) {
          return nGpuArchCoresPerSM[index].Cores;
       }	
       index++;
    }
    printf("MapSMtoCores undefined SM %d.%d is undefined (please update to the latest SDK)!\n", major, minor);
    return -1;
}
// end of GPU Architecture definitions

// namespace unnamed (internal)
namespace 
{
    //! size of PGM file header 
    const unsigned int PGMHeaderSize = 0x40;

    // types

    //! Data converter from unsigned char / unsigned byte to type T
    template<class T>
    struct ConverterFromUByte;

    //! Data converter from unsigned char / unsigned byte to float
    template<>
	struct ConverterFromUByte<float> 
	{
		//! Conversion operator
		//! @return converted value
		//! @param  val  value to convert
		float operator()( const unsigned char& val) 
		{
			return static_cast<float>( val) / 255.0f;
		}
	};

    //! Data converter from unsigned char / unsigned byte to type T
    template<class T>
    struct ConverterToUByte;

    //! Data converter from unsigned char / unsigned byte to unsigned int
    template<>
    struct ConverterToUByte<float> 
    {
        //! Conversion operator
        //! @return converted value
        //! @param  val  value to convert
        unsigned char operator()( const float& val) 
        {
            return static_cast<unsigned char>( val * 255.0f);
        }
    };
}

#ifdef _WIN32
	#define FOPEN(fHandle,filename,mode) fopen_s(&fHandle, filename, mode)
	#define FOPEN_FAIL(result) (result != 0)
	#define SSCANF sscanf_s
#else
	#define FOPEN(fHandle,filename,mode) (fHandle = fopen(filename, mode))
	#define FOPEN_FAIL(result) (result == NULL)
	#define SSCANF sscanf
#endif

inline bool
__loadPPM( const char* file, unsigned char** data, 
         unsigned int *w, unsigned int *h, unsigned int *channels ) 
{
    FILE *fp = NULL;
    if( FOPEN_FAIL(FOPEN(fp, file, "rb")) ) 
    {
        std::cerr << "__LoadPPM() : Failed to open file: " << file << std::endl;
        return false;
    }

    // check header
    char header[PGMHeaderSize];
    fgets( header, PGMHeaderSize, fp);
    if (strncmp(header, "P5", 2) == 0)
    {
        *channels = 1;
    }
    else if (strncmp(header, "P6", 2) == 0)
    {
        *channels = 3;
    }
    else {
        std::cerr << "__LoadPPM() : File is not a PPM or PGM image" << std::endl;
        *channels = 0;
        return false;
    }

    // parse header, read maxval, width and height
    unsigned int width = 0;
    unsigned int height = 0;
    unsigned int maxval = 0;
    unsigned int i = 0;
    while(i < 3) 
    {
        fgets(header, PGMHeaderSize, fp);
        if(header[0] == '#') 
            continue;

		if(i == 0) 
        {
            i += SSCANF( header, "%u %u %u", &width, &height, &maxval);
        }
        else if (i == 1) 
        {
            i += SSCANF( header, "%u %u", &height, &maxval);
        }
        else if (i == 2) 
        {
            i += SSCANF(header, "%u", &maxval);
        }
    }

    // check if given handle for the data is initialized
    if( NULL != *data) 
    {
        if (*w != width || *h != height) 
        {
            std::cerr << "__LoadPPM() : Invalid image dimensions." << std::endl;
            return false;
        }
    } 
    else 
    {
        *data = (unsigned char*) malloc( sizeof( unsigned char) * width * height * *channels);
        *w = width;
        *h = height;
    }

    // read and close file
    fread( *data, sizeof(unsigned char), width * height * *channels, fp);
    fclose(fp);

    return true;
}

template <class T>
bool
sdkLoadPGM( const char* file, T** data, unsigned int *w, unsigned int *h) 
{
    unsigned char* idata = NULL;
    unsigned int channels;
    if( true != __loadPPM(file, &idata, w, h, &channels)) 
    {
        return false;
    }

    unsigned int size = *w * *h * channels;

    // initialize mem if necessary
    // the correct size is checked / set in loadPGMc()
    if( NULL == *data) 
    {
        *data = (T*) malloc( sizeof(T) * size );
    }

    // copy and cast data
    std::transform( idata, idata + size, *data, ConverterFromUByte<T>());

    free( idata );

    return true;
}

inline bool
__savePPM( const char* file, unsigned char *data, 
         unsigned int w, unsigned int h, unsigned int channels) 
{
    assert( NULL != data);
    assert( w > 0);
    assert( h > 0);

    std::fstream fh( file, std::fstream::out | std::fstream::binary );
    if( fh.bad()) 
    {
        std::cerr << "__savePPM() : Opening file failed." << std::endl;
        return false;
    }

    if (channels == 1)
    {
        fh << "P5\n";
    }
    else if (channels == 3) {
        fh << "P6\n";
    }
    else {
        std::cerr << "__savePPM() : Invalid number of channels." << std::endl;
        return false;
    }

    fh << w << "\n" << h << "\n" << 0xff << std::endl;

    for( unsigned int i = 0; (i < (w*h*channels)) && fh.good(); ++i) 
    {
        fh << data[i];
    }
    fh.flush();

    if( fh.bad()) 
    {
        std::cerr << "__savePPM() : Writing data failed." << std::endl;
        return false;
    } 
    fh.close();

    return true;
}

template<class T>
bool
sdkSavePGM( const char* file, T *data, unsigned int w, unsigned int h) 
{
    unsigned int size = w * h;
    unsigned char* idata = 
      (unsigned char*) malloc( sizeof(unsigned char) * size);

    std::transform( data, data + size, idata, ConverterToUByte<T>());

    // write file
    bool result = __savePPM(file, idata, w, h, 1);

    // cleanup
    free( idata );

    return result;
}


//////////////////////////////////////////////////////////////////////////////
//! Write a data file \filename 
//! @return true if writing the file succeeded, otherwise false
//! @param filename name of the source file
//! @param data  data to write
//! @param len  number of data elements in data, -1 on error
//! @param epsilon  epsilon for comparison
//////////////////////////////////////////////////////////////////////////////
template<class T, class S>
bool
sdkWriteFile( const char* filename, const T* data, unsigned int len,
              const S epsilon, bool verbose) 
{
    assert( NULL != filename);
    assert( NULL != data);

    // open file for writing
    std::fstream fh( filename, std::fstream::out);
    // check if filestream is valid
    if( ! fh.good()) 
    {
        if (verbose)
            std::cerr << "cutWriteFile() : Opening file failed." << std::endl;
        return false;
    }

    // first write epsilon
    fh << "# " << epsilon << "\n";

    // write data
    for( unsigned int i = 0; (i < len) && (fh.good()); ++i) 
    {
        fh << data[i] << ' ';
    }

    // Check if writing succeeded
    if( ! fh.good()) 
    {
        if (verbose)
            std::cerr << "cutWriteFile() : Writing file failed." << std::endl;
        return false;
    }

    // file ends with nl
    fh << std::endl;

    return true;
}

////////////////////////////////////////////////////////////////////////////// 
//! Compare two arrays of arbitrary type       
//! @return  true if \a reference and \a data are identical, otherwise false
//! @param reference  timer_interface to the reference data / gold image
//! @param data       handle to the computed data
//! @param len        number of elements in reference and data
//! @param epsilon    epsilon to use for the comparison
//////////////////////////////////////////////////////////////////////////////
template<class T, class S>
bool
compareData( const T* reference, const T* data, const unsigned int len, 
             const S epsilon, const float threshold) 
{
    assert( epsilon >= 0);

    bool result = true;
    unsigned int error_count = 0;

    for( unsigned int i = 0; i < len; ++i) {
        T diff = reference[i] - data[i];
        bool comp = (diff <= epsilon) && (diff >= -epsilon);
        result &= comp;

        error_count += !comp;

#ifdef _DEBUG
        if( ! comp) 
        {
            std::cerr << "ERROR, i = " << i << ",\t " 
                << reference[i] << " / "
                << data[i] 
                << " (reference / data)\n";
        }
#endif
    }

    if (threshold == 0.0f) {
        return (result) ? true : false;
    } else {
        if (error_count) {
            printf("%4.2f(%%) of bytes mismatched (count=%d)\n", (float)error_count*100/(float)len, error_count);
        }
        return (len*threshold > error_count) ? true : false;
    }
}

bool
sdkCompareL2fe( const float* reference, const float* data,
                const unsigned int len, const float epsilon ) 
{
    assert( epsilon >= 0);

    float error = 0;
    float ref = 0;

    for( unsigned int i = 0; i < len; ++i) {

        float diff = reference[i] - data[i];
        error += diff * diff;
        ref += reference[i] * reference[i];
    }

    float normRef = sqrtf(ref);
    if (fabs(ref) < 1e-7) {
#ifdef _DEBUG
        std::cerr << "ERROR, reference l2-norm is 0\n";
#endif
        return false;
    }
    float normError = sqrtf(error);
    error = normError / normRef;
    bool result = error < epsilon;
#ifdef _DEBUG
    if( ! result) 
    {
        std::cerr << "ERROR, l2-norm error " 
            << error << " is greater than epsilon " << epsilon << "\n";
    }
#endif

    return result;
}



////////////////////////////////////////////////////////////////////////////////
//! Timer functionality

////////////////////////////////////////////////////////////////////////////////
//! Create a new timer
//! @return true if a time has been created, otherwise false
//! @param  name of the new timer, 0 if the creation failed
////////////////////////////////////////////////////////////////////////////////
bool
sdkCreateTimer( StopWatchInterface **timer_interface ) 
{
#ifdef _WIN32
	*timer_interface = (StopWatchInterface *)new StopWatchWin();
#else
	*timer_interface = (StopWatchInterface *)new StopWatchLinux();
#endif
	return (*timer_interface != NULL) ? true : false;
}


////////////////////////////////////////////////////////////////////////////////
//! Delete a timer
//! @return true if a time has been deleted, otherwise false
//! @param  name of the timer to delete
////////////////////////////////////////////////////////////////////////////////
bool
sdkDeleteTimer( StopWatchInterface **timer_interface ) 
{
	if (*timer_interface) delete *timer_interface;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Start the time with name \a name
//! @param name  name of the timer to start
////////////////////////////////////////////////////////////////////////////////
bool
sdkStartTimer( StopWatchInterface **timer_interface ) 
{
	if (*timer_interface) (*timer_interface)->start();
    return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Stop the time with name \a name. Does not reset.
//! @param name  name of the timer to stop
////////////////////////////////////////////////////////////////////////////////
bool
sdkStopTimer( StopWatchInterface **timer_interface ) 
{
	if (*timer_interface) (*timer_interface)->stop();
    return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Resets the timer's counter.
//! @param name  name of the timer to reset.
////////////////////////////////////////////////////////////////////////////////
bool
sdkResetTimer( StopWatchInterface **timer_interface )
{
	if (*timer_interface) (*timer_interface)->reset();
    return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Return the average time for timer execution as the total time
//! for the timer dividied by the number of completed (stopped) runs the timer 
//! has made.
//! Excludes the current running time if the timer is currently running.
//! @param name  name of the timer to return the time of
////////////////////////////////////////////////////////////////////////////////
float
sdkGetAverageTimerValue( StopWatchInterface **timer_interface )
{
	if (*timer_interface) 
		return (*timer_interface)->getAverageTime();
	else
		return 0.0f;
}

////////////////////////////////////////////////////////////////////////////////
//! Total execution time for the timer over all runs since the last reset
//! or timer creation.
//! @param name  name of the timer to obtain the value of.
////////////////////////////////////////////////////////////////////////////////
float
sdkGetTimerValue( StopWatchInterface **timer_interface )
{  
	if (*timer_interface) 
		return (*timer_interface)->getTime();
	else 
		return 0.0f;
}

#endif //  SDK_HELPER_H

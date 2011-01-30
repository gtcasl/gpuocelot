/*
 * Sobol Quasi-random Number Generator example
 *
 * Based on CUDA code submitted by Mike Giles, Oxford University, United Kingdom
 * http://people.maths.ox.ac.uk/~gilesm/
 *
 * and C code developed by Stephen Joe, University of Waikato, New Zealand
 * and Frances Kuo, University of New South Wales, Australia
 * http://web.maths.unsw.edu.au/~fkuo/sobol/
 *
 * For theoretical background see:
 *
 * P. Bratley and B.L. Fox.
 * Implementing Sobol's quasirandom sequence generator
 * http://portal.acm.org/citation.cfm?id=42288
 * ACM Trans. on Math. Software, 14(1):88-100, 1988
 *
 * S. Joe and F. Kuo.
 * Remark on algorithm 659: implementing Sobol's quasirandom sequence generator.
 * http://portal.acm.org/citation.cfm?id=641879
 * ACM Trans. on Math. Software, 29(1):49-57, 2003
 *
 * NOTICE TO USER:
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

#include <iostream>
#include <cutil_inline.h>
#include <math.h>

#include "sobol.h"
#include "sobol_gold.h"
#include "sobol_gpu.h"

#define L1ERROR_TOLERANCE (1e-6)

void printHelp(int argc, char *argv[])
{
    if (argc > 0)
    {
        std::cout << "\nUsage: " << argv[0] << " <options>\n\n";
    }
    else
    {
        std::cout << "\nUsage: <program name> <options>\n\n";
    }
    
    std::cout << "\t--vectors=M     specify number of vectors    (required)\n";
    std::cout << "\t                The generator will output M vectors\n\n";
    std::cout << "\t--dimensions=N  specify number of dimensions (required)\n";
    std::cout << "\t                Each vector will consist of N components\n\n";
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    bool ok = true;

    // We will generate n_vectors vectors of n_dimensions numbers
    int n_vectors;
    int n_dimensions;

    // Print help if requested
    if (cutCheckCmdLineFlag(argc, (const char **)argv, "help"))
    {
        printHelp(argc, argv);
        return 0;
    }

    if (!cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest"))
    {
        // For QA testing set a default number of vectors and dimensions
        n_vectors = 100000;
        n_dimensions = 100;
    }
    else
    {
        // Parse the command line to determine the required number of vectors
        if (cutGetCmdLineArgumenti(argc, (const char**)argv, "vectors", &n_vectors))
        {
            if (n_vectors < 1)
            {
                std::cerr << "Illegal argument: number of vectors must be positive (--vectors=N)" << std::endl;
                ok = false;
            }
        }
        else
        {
            std::cerr << "Missing argument: number of vectors must be specified (--vectors=N)" << std::endl;
            ok = false;
        }

        // Parse the command line to determine the number of dimensions in each vector
        if (cutGetCmdLineArgumenti(argc, (const char**)argv, "dimensions", &n_dimensions))
        {
            if (n_dimensions < 1)
            {
                std::cerr << "Illegal argument: number of dimensions must be positive (--dimensions=N)" << std::endl;
                ok = false;
            }
        }
        else
        {
            std::cerr << "Missing argument: number of dimensions must be specified (--dimensions=N)" << std::endl;
            ok = false;
        }
    }

    // If any of the command line checks failed, exit
    if (! ok)
        return -1;

    // Use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if (cutCheckCmdLineFlag(argc, (const char**)argv, "device"))
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice(cutGetMaxGflopsDeviceId());

    // Create a timer to measure performance
    unsigned int hTimer;
    double       time;
    cutilCheckError(cutCreateTimer(&hTimer));

    // Allocate memory for the arrays
    std::cout << "Allocating CPU memory..." << std::endl;
    unsigned int *h_directions = new unsigned int [n_dimensions * n_directions];
    float        *h_outputCPU  = new float [n_vectors * n_dimensions];
    float        *h_outputGPU  = new float [n_vectors * n_dimensions];
    std::cout << "Allocating GPU memory..." << std::endl;
    unsigned int *d_directions;
    float        *d_output;
    cutilSafeCall(cudaMalloc((void **)&d_directions, n_dimensions * n_directions * sizeof(unsigned int)));
    cutilSafeCall(cudaMalloc((void **)&d_output, n_vectors * n_dimensions * sizeof(float)));

    // Initialize the direction numbers (done on the host)
    std::cout << "Initializing direction numbers..." << std::endl;
    initSobolDirectionVectors(n_dimensions, h_directions);

    // Copy the direction numbers to the device
    std::cout << "Copying direction numbers to device..." << std::endl;
    cutilSafeCall(cudaMemcpy(d_directions, h_directions, n_dimensions * n_directions * sizeof(unsigned int), cudaMemcpyHostToDevice));
    cutilSafeCall(cudaThreadSynchronize());

    // Execute the QRNG on the device
    std::cout << "Executing QRNG on GPU..." << std::endl;
    cutilCheckError(cutResetTimer(hTimer));
    cutilCheckError(cutStartTimer(hTimer));
    sobolGPU(n_vectors, n_dimensions, d_directions, d_output);
    cutilSafeCall(cudaThreadSynchronize());
    cutilCheckError(cutStopTimer(hTimer));
    time = cutGetTimerValue(hTimer);
    if (time < 1e-6)
    {
        std::cout << "Gsamples/s: problem size too small to measure, try increasing number of vectors or dimensions" << std::endl;
    }
    else
    {
        std::cout << "Gsamples/s: " << (double)n_vectors * (double)n_dimensions * 1E-9 / (time * 1E-3) << std::endl;
    }
    std::cout << "Reading results from GPU..." << std::endl;
    cutilSafeCall(cudaMemcpy(h_outputGPU, d_output, n_vectors * n_dimensions * sizeof(float), cudaMemcpyDeviceToHost));

    std::cout << std::endl;
    // Execute the QRNG on the host
    std::cout << "Executing QRNG on CPU..." << std::endl;
    cutilCheckError(cutResetTimer(hTimer));
    cutilCheckError(cutStartTimer(hTimer));
    sobolCPU(n_vectors, n_dimensions, h_directions, h_outputCPU);
    cutilCheckError(cutStopTimer(hTimer));
    time = cutGetTimerValue(hTimer);
    if (time < 1e-6)
    {
        std::cout << "Gsamples/s: problem size too small to measure, try increasing number of vectors or dimensions" << std::endl;
    }
    else
    {
        std::cout << "Gsamples/s: " << (double)n_vectors * (double)n_dimensions * 1E-9 / (time * 1E-3) << std::endl;
    }
    
    // Check the results
    std::cout << "Checking results..." << std::endl;
    float l1norm_diff = 0.0F;
    float l1norm_ref  = 0.0F;
    float l1error;
    // Special case if n_vectors is 1, when the vector should be exactly 0
    if (n_vectors == 1)
    {
        for (int d = 0, v = 0 ; d < n_dimensions ; d++)
        {
            float ref = h_outputCPU[d * n_vectors + v];
            l1norm_diff += fabs(h_outputGPU[d * n_vectors + v] - ref);
            l1norm_ref  += fabs(ref);
        }

        // Output the L1-Error
        l1error = l1norm_diff;

        if (l1norm_ref != 0)
        {
            std::cerr << "Error: L1-Norm of the reference is not zero (for single vector), golden generator appears broken\n";
        }
        else
        {
            std::cout << "L1-Error: " << l1error << std::endl;
        }
    }
    else
    {
        for (int d = 0 ; d < n_dimensions ; d++)
        {
            for (int v = 0 ; v < n_vectors ; v++)
            {
                float ref = h_outputCPU[d * n_vectors + v];
                l1norm_diff += fabs(h_outputGPU[d * n_vectors + v] - ref);
                l1norm_ref  += fabs(ref);
            }
        }

        // Output the L1-Error
        l1error = l1norm_diff / l1norm_ref;

        if (l1norm_ref == 0)
        {
            std::cerr << "Error: L1-Norm of the reference is zero, golden generator appears broken\n";
        }
        else
        {
            std::cout << "L1-Error: " << l1error << std::endl;
        }
    }
    
    // Check pass/fail using L1 error
    std::cout << std::endl << "TEST " << ((l1error < L1ERROR_TOLERANCE) ? "PASSED" : "FAILED") << std::endl << std::endl;

    // Cleanup and terminate
    std::cout << "Shutting down..." << std::endl;
    cutilCheckError(cutDeleteTimer(hTimer));
    delete h_directions;
    delete h_outputCPU;
    delete h_outputGPU;
    cutilSafeCall(cudaFree(d_directions));
    cutilSafeCall(cudaFree(d_output));
    cudaThreadExit();
    cutilExit(argc,argv);
    return 0;
}

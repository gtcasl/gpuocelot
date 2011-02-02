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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "sobol.h"
#include "sobol_gold.h"
#include "sobol_primitives.h"

#define k_2powneg32 2.3283064E-10F

// Windows does not provide ffs (find first set) so here is a
// fairly simple implementation.
// _WIN32 is defined on 32 and 64 bit Windows
#ifdef _WIN32
int ffs(const unsigned int &i)
{
    unsigned int v = i;
    unsigned int count;

    if (! v)
    {
	    count = 0;
    }
    else
    {
	count = 2;
	if ((v & 0xffff) == 0)
	{
	    v >>= 16;
	    count += 16;
	}
	if ((v & 0xff) == 0)
	{
	    v >>= 8;
	    count += 8;
	}
	if ((v & 0xf) == 0)
	{
	    v >>= 4;
	    count += 4;
	}
	if ((v & 0x3) == 0)
	{
	    v >>= 2;
	    count += 2;
	}
	count -= v & 0x1;
    }
    return count;
}
#endif

// Create the direction numbers, based on the primitive polynomials.
void initSobolDirectionVectors(int n_dimensions, unsigned int *directions)
{
    unsigned int *v = directions;

    for (int dim = 0 ; dim < n_dimensions ; dim++)
    {
        // First dimension is a special case
        if (dim == 0)
        {
            for (int i = 0 ; i < n_directions ; i++)
            {
                // All m's are 1
                v[i] = 1 << (31 - i);
            }
        }
        else
        {
            int d = sobol_primitives[dim].degree;
            // The first direction numbers (up to the degree of the polynomial)
            // are simply v[i] = m[i] / 2^i (stored in Q0.32 format)
            for (int i = 0 ; i < d ; i++)
            {
                v[i] = sobol_primitives[dim].m[i] << (31 - i);
            }
            // The remaining direction numbers are computed as described in
            // the Bratley and Fox paper.
            // v[i] = a[1]v[i-1] ^ a[2]v[i-2] ^ ... ^ a[v-1]v[i-d+1] ^ v[i-d] ^ v[i-d]/2^d
            for (int i = d ; i < n_directions ; i++)
            {
                // First do the v[i-d] ^ v[i-d]/2^d part
                v[i] = v[i - d] ^ (v[i - d] >> d);
                // Now do the a[1]v[i-1] ^ a[2]v[i-2] ^ ... part
                // Note that the coefficients a[] are zero or one and for compactness in
                // the input tables they are stored as bits of a single integer. To extract
                // the relevant bit we use right shift and mask with 1.
                // For example, for a 10 degree polynomial there are ten useful bits in a,
                // so to get a[2] we need to right shift 7 times (to get the 8th bit into
                // the LSB) and then mask with 1.
                for (int j = 1 ; j < d ; j++)
                {
                    v[i] ^= (((sobol_primitives[dim].a >> (d - 1 - j)) & 1) * v[i - j]);
                }
            }
        }
        v += n_directions;
    }
}

// Reference model for generating Sobol numbers on the host
void sobolCPU(int n_vectors, int n_dimensions, unsigned int *directions, float *output)
{
    unsigned int *v = directions;

    for (int d = 0 ; d < n_dimensions ; d++)
    {
        unsigned int X = 0;
        // x[0] is zero (in all dimensions)
        output[n_vectors * d] = 0.0;        
        for (int i = 1 ; i < n_vectors ; i++)
        {
            // x[i] = x[i-1] ^ v[c]
            //  where c is the index of the rightmost zero bit in i
            //  minus 1 (since C arrays count from zero)
            // In the Bratley and Fox paper this is equation (**)
            X ^= v[ffs(~(i - 1)) - 1];
            output[i + n_vectors * d] = (float)X * k_2powneg32;
        }
        v += n_directions;
    }
}

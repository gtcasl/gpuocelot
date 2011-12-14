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



#include <stdio.h>
#include <math.h>
#include "quasirandomGenerator_common.h"



////////////////////////////////////////////////////////////////////////////////
// Table generation functions
////////////////////////////////////////////////////////////////////////////////
// Internal 64(63)-bit table
static INT64 cjn[63][QRNG_DIMENSIONS];

static int GeneratePolynomials(int buffer[QRNG_DIMENSIONS], bool primitive){
    int i, j, n, p1, p2, l;
    int e_p1, e_p2, e_b;

    //generate all polynomials to buffer
    for(n = 1, buffer[0] = 0x2, p2 = 0, l = 0; n < QRNG_DIMENSIONS; ++n){
        //search for the next irreducable polynomial
        for(p1 = buffer[n - 1] + 1; ; ++p1){
            //find degree of polynomial p1
            for(e_p1 = 30; (p1 & (1 << e_p1)) == 0; --e_p1) {} 

            // try to divide p1 by all polynomials in buffer
            for(i = 0; i < n; ++i){
                // find the degree of buffer[i]
                for(e_b = e_p1; (buffer[i] & (1 << e_b)) == 0; --e_b) {} 

                // divide p2 by buffer[i] until the end
                for(p2 = (buffer[i] << ((e_p2 = e_p1) - e_b)) ^ p1; p2 >= buffer[i]; p2 = (buffer[i] << (e_p2 - e_b)) ^ p2){
                    for( ; (p2 & (1 << e_p2)) == 0; --e_p2) {} 
                }// compute new degree of p2

                // division without remainder!!! p1 is not irreducable
                if(p2 == 0){
                    break; 
                }
            }

            //all divisions were with remainder - p1 is irreducable
            if(p2 != 0){
                e_p2 = 0;
                if(primitive){
                    //check that p1 has only one cycle (i.e. is monic, or primitive)
                    j = ~(0xffffffff << (e_p1 + 1));
                    e_b = (1 << e_p1) | 0x1;
                    for(p2 = e_b, e_p2 = (1 << e_p1) - 2; e_p2 > 0; --e_p2){
                        p2 <<= 1;
                        i = p2 & p1;
                        i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
                        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
                        i = (i & 0x07070707) + ((i >> 4) & 0x07070707);
                        p2 |= (i % 255) & 1;
                        if ((p2 & j) == e_b) break;
                    }
                }
                //it is monic - add it to the list of polynomials
                if(e_p2 == 0){
                    buffer[n] = p1;
                    l += e_p1;
                    break;
                }
            }
        }
    }
    return l + 1;
}



////////////////////////////////////////////////////////////////////////////////
//  @misc{Bratley92:LDS,
//    author = "B. Fox and P. Bratley and H. Niederreiter",
//    title = "Implementation and test of low discrepancy sequences",
//    text = "B. L. Fox, P. Bratley, and H. Niederreiter. Implementation and test of
//      low discrepancy sequences. ACM Trans. Model. Comput. Simul., 2(3):195--213,
//      July 1992.",
//    year = "1992" }
////////////////////////////////////////////////////////////////////////////////
static void GenerateCJ(){
    int buffer[QRNG_DIMENSIONS];
    int *polynomials;
    int n, p1, l, e_p1;

    // Niederreiter (in contrast to Sobol) allows to use not primitive, but just irreducable polynomials
    l = GeneratePolynomials(buffer, false);

    // convert all polynomials from buffer to polynomials table
    polynomials = new int[l + 2 * QRNG_DIMENSIONS + 1];
    for(n = 0, l = 0; n < QRNG_DIMENSIONS; ++n){
        //find degree of polynomial p1
        for(p1 = buffer[n], e_p1 = 30; (p1 & (1 << e_p1)) == 0; --e_p1) {} 

        //fill polynomials table with values for this polynomial
        polynomials[l++] = 1;
        for(--e_p1; e_p1 >= 0; --e_p1){
            polynomials[l++] = (p1 >> e_p1) & 1;
        }
        polynomials[l++] = -1;
    }
    polynomials[l] = -1;

    // irreducable polynomial p
    int *p = polynomials, e, d;
    // polynomial b
    int b_arr[1024], *b, m;
    // v array
    int v_arr[1024], *v;
    // temporary polynomial, required to do multiplication of p and b
    int t_arr[1024], *t;
    // subsidiary variables
    int i, j, u, m1, ip, it;

    // cycle over monic irreducible polynomials
    for(d = 0; p[0] != -1; p += e + 2){
        // allocate memory for cj array for dimention (ip + 1)
        for(i = 0; i < 63; ++i){
            cjn[i][d] = 0; 
        }

        // determine the power of irreducable polynomial
        for(e = 0; p[e + 1] != -1; ++e) {} 
        // polynomial b in the beginning is just '1'
        (b = b_arr + 1023)[m = 0] = 1;
        // v array needs only (63 + e - 2) length
        v = v_arr + 1023 - (63 + e - 2);

        // cycle over all coefficients
        for(j = 63 - 1, u = e; j >= 0; --j, ++u){
            if(u == e){
                u = 0;
                // multiply b by p (polynomials multiplication)
                for(i = 0, t = t_arr + 1023 - (m1 = m); i <= m; ++i){
                    t[i] = b[i]; 
                }
                b = b_arr + 1023 - (m += e);

                for(i = 0; i <= m; ++i){
                    b[i] = 0;
                    for(ip = e - (m - i), it = m1; ip <= e && it >= 0; ++ip, --it){
                        if(ip >= 0){
                            b[i] ^= p[ip] & t[it];
                        }
                    }
                }
                // multiplication of polynomials finished

                // calculate v
                for(i = 0; i < m1; ++i){
                    v[i] = 0;
                }
                for(; i < m; ++i){
                    v[i] = 1;
                }
                for(; i <= 63 + e - 2; ++i){
                    v[i] = 0;
                    for (it = 1; it <= m; ++it){
                        v[i] ^= v[i - it] & b[it]; 
                    }
                }
            }

            // copy calculated v to cj
            for(i = 0; i < 63; i++){
                cjn[i][d] |= (INT64)v[i + u] << j; 
            }
        }
        ++d;
    }

    delete []polynomials;
}

//Generate 63-bit quasirandom number for given index and dimension and normalize
extern "C" double getQuasirandomValue63(INT64 i, int dim){
    const double INT63_SCALE = (1.0 / (double)0x8000000000000001ULL);
    INT64 result = 0;

    for(int bit = 0; bit < 63; bit++, i >>= 1)
        if(i & 1) result ^= cjn[bit][dim];

    return (double)(result + 1) * INT63_SCALE;
}



////////////////////////////////////////////////////////////////////////////////
// Initialization (table setup)
////////////////////////////////////////////////////////////////////////////////
extern "C" void initQuasirandomGenerator(
    unsigned int table[QRNG_DIMENSIONS][QRNG_RESOLUTION]
){
    GenerateCJ();

    for(int dim = 0; dim < QRNG_DIMENSIONS; dim++)
        for(int bit = 0; bit < QRNG_RESOLUTION; bit++)
            table[dim][bit] = (int)((cjn[bit][dim] >> 32) & 0x7FFFFFFF);
}



////////////////////////////////////////////////////////////////////////////////
// Generate 31-bit quasirandom number for given index and dimension
////////////////////////////////////////////////////////////////////////////////
extern "C" float getQuasirandomValue(
    unsigned int table[QRNG_DIMENSIONS][QRNG_RESOLUTION],
    int i,
    int dim
){
    int result = 0;

    for(int bit = 0; bit < QRNG_RESOLUTION; bit++, i >>= 1)
        if(i & 1) result ^= table[dim][bit];

    return (float)(result + 1) * INT_SCALE;
}



////////////////////////////////////////////////////////////////////////////////
// Moro's Inverse Cumulative Normal Distribution function approximation
////////////////////////////////////////////////////////////////////////////////
extern "C" double MoroInvCNDcpu(double P){
    const double a1 = 2.50662823884;
    const double a2 = -18.61500062529;
    const double a3 = 41.39119773534;
    const double a4 = -25.44106049637;
    const double b1 = -8.4735109309;
    const double b2 = 23.08336743743;
    const double b3 = -21.06224101826;
    const double b4 = 3.13082909833;
    const double c1 = 0.337475482272615;
    const double c2 = 0.976169019091719;
    const double c3 = 0.160797971491821;
    const double c4 = 2.76438810333863E-02;
    const double c5 = 3.8405729373609E-03;
    const double c6 = 3.951896511919E-04;
    const double c7 = 3.21767881768E-05;
    const double c8 = 2.888167364E-07;
    const double c9 = 3.960315187E-07;
    double y, z;

    if(P <= 0 || P >= 1.0){
        printf("MoroInvCND(): bad parameter\n");
    }

    y = P - 0.5;
    if(fabs(y) < 0.42){
        z = y * y;
        z = y * (((a4 * z + a3) * z + a2) * z + a1) / ((((b4 * z + b3) * z + b2) * z + b1) * z + 1.0);
    }else{
        if(y > 0)
            z = log(-log(1.0 - P));
        else
            z = log(-log(P));

        z = c1 + z * (c2 + z * (c3 + z * (c4 + z * (c5 + z * (c6 + z * (c7 + z * (c8 + z * c9)))))));
        if(y < 0) z = -z;
    }

    return z;
}



////////////////////////////////////////////////////////////////////////////////
// Acklam's Inverse Cumulative Normal Distribution function approximation
////////////////////////////////////////////////////////////////////////////////
extern "C" double AcklamInvCNDcpu(double P){
    const double   a1 = -39.6968302866538;
    const double   a2 = 220.946098424521;
    const double   a3 = -275.928510446969;
    const double   a4 = 138.357751867269;
    const double   a5 = -30.6647980661472;
    const double   a6 = 2.50662827745924;
    const double   b1 = -54.4760987982241;
    const double   b2 = 161.585836858041;
    const double   b3 = -155.698979859887;
    const double   b4 = 66.8013118877197;
    const double   b5 = -13.2806815528857;
    const double   c1 = -7.78489400243029E-03;
    const double   c2 = -0.322396458041136;
    const double   c3 = -2.40075827716184;
    const double   c4 = -2.54973253934373;
    const double   c5 = 4.37466414146497;
    const double   c6 = 2.93816398269878;
    const double   d1 = 7.78469570904146E-03;
    const double   d2 = 0.32246712907004;
    const double   d3 = 2.445134137143;
    const double   d4 = 3.75440866190742;
    const double  low = 0.02425;
    const double high = 1.0 - low;
    double z, R;

    if(P <= 0 || P >= 1.0){
        printf("AcklamInvCND(): bad parameter.\n");
    }

    if(P < low){
        z = sqrt(-2.0 * log(P));
        z = (((((c1 * z + c2) * z + c3) * z + c4) * z + c5) * z + c6) /
            ((((d1 * z + d2) * z + d3) * z + d4) * z + 1.0);
    }else{
        if(P > high){
            z = sqrt(-2.0 * log(1.0 - P));
            z = -(((((c1 * z + c2) * z + c3) * z + c4) * z + c5) * z + c6) /
                 ((((d1 * z + d2) * z + d3) * z + d4) * z + 1.0);
        }else{
            z = P - 0.5;
            R = z * z;
            z = (((((a1 * R + a2) * R + a3) * R + a4) * R + a5) * R + a6) * z /
                (((((b1 * R + b2) * R + b3) * R + b4) * R + b5) * R + 1.0);
        }
    }

    return z;
}

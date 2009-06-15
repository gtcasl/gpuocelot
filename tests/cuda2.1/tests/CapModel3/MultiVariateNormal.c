#ifndef MULTIVARIATE_NORMAL_CPP_INCLUDED
#define MULTIVARIATE_NORMAL_CPP_INCLUDED

#include "MultiVariateNormal.h"
#include <math.h>
#include <stdlib.h>

#ifndef M_2_SQRTPI  
#define M_2_SQRTPI  1.12837916709551257390
#endif

#ifndef M_SQRT1_2
#define M_SQRT1_2   0.70710678118654752440
#endif

#ifndef M_SQRT2
#define M_SQRT2     1.41421356237309504880
#endif

#ifndef M_1_SQRT2PI
#define M_1_SQRT2PI (M_2_SQRTPI * M_SQRT1_2 / 2.0)
#endif


#define SQRT32 (4.0 * M_SQRT2)

#define GSL_DBL_EPSILON 2.2204460492503131e-16
#define GAUSS_EPSILON  (GSL_DBL_EPSILON / 2)
#define GAUSS_XUPPER (8.572)
#define GAUSS_XLOWER (-37.519)

#define GAUSS_SCALE (16.0)

#define PARAM_R 3.44428647676

static const double ytab[128] = {
  1, 0.963598623011, 0.936280813353, 0.913041104253,
  0.892278506696, 0.873239356919, 0.855496407634, 0.838778928349,
  0.822902083699, 0.807732738234, 0.793171045519, 0.779139726505,
  0.765577436082, 0.752434456248, 0.739669787677, 0.727249120285,
  0.715143377413, 0.703327646455, 0.691780377035, 0.68048276891,
  0.669418297233, 0.65857233912, 0.647931876189, 0.637485254896,
  0.62722199145, 0.617132611532, 0.607208517467, 0.597441877296,
  0.587825531465, 0.578352913803, 0.569017984198, 0.559815170911,
  0.550739320877, 0.541785656682, 0.532949739145, 0.524227434628,
  0.515614886373, 0.507108489253, 0.498704867478, 0.490400854812,
  0.482193476986, 0.47407993601, 0.466057596125, 0.458123971214,
  0.450276713467, 0.442513603171, 0.434832539473, 0.427231532022,
  0.419708693379, 0.41226223212, 0.404890446548, 0.397591718955,
  0.390364510382, 0.383207355816, 0.376118859788, 0.369097692334,
  0.362142585282, 0.355252328834, 0.348425768415, 0.341661801776,
  0.334959376311, 0.328317486588, 0.321735172063, 0.31521151497,
  0.308745638367, 0.302336704338, 0.29598391232, 0.289686497571,
  0.283443729739, 0.27725491156, 0.271119377649, 0.265036493387,
  0.259005653912, 0.253026283183, 0.247097833139, 0.241219782932,
  0.235391638239, 0.229612930649, 0.223883217122, 0.218202079518,
  0.212569124201, 0.206983981709, 0.201446306496, 0.195955776745,
  0.190512094256, 0.185114984406, 0.179764196185, 0.174459502324,
  0.169200699492, 0.1639876086, 0.158820075195, 0.153697969964,
  0.148621189348, 0.143589656295, 0.138603321143, 0.133662162669,
  0.128766189309, 0.123915440582, 0.119109988745, 0.114349940703,
  0.10963544023, 0.104966670533, 0.100343857232, 0.0957672718266,
  0.0912372357329, 0.0867541250127, 0.082318375932, 0.0779304915295,
  0.0735910494266, 0.0693007111742, 0.065060233529, 0.0608704821745,
  0.056732448584, 0.05264727098, 0.0486162607163, 0.0446409359769,
  0.0407230655415, 0.0368647267386, 0.0330683839378, 0.0293369977411,
  0.0256741818288, 0.0220844372634, 0.0185735200577, 0.0151490552854,
  0.0118216532614, 0.00860719483079, 0.00553245272614, 0.00265435214565
};

static const unsigned long ktab[128] = {
  0, 12590644, 14272653, 14988939,
  15384584, 15635009, 15807561, 15933577,
  16029594, 16105155, 16166147, 16216399,
  16258508, 16294295, 16325078, 16351831,
  16375291, 16396026, 16414479, 16431002,
  16445880, 16459343, 16471578, 16482744,
  16492970, 16502368, 16511031, 16519039,
  16526459, 16533352, 16539769, 16545755,
  16551348, 16556584, 16561493, 16566101,
  16570433, 16574511, 16578353, 16581977,
  16585398, 16588629, 16591685, 16594575,
  16597311, 16599901, 16602354, 16604679,
  16606881, 16608968, 16610945, 16612818,
  16614592, 16616272, 16617861, 16619363,
  16620782, 16622121, 16623383, 16624570,
  16625685, 16626730, 16627708, 16628619,
  16629465, 16630248, 16630969, 16631628,
  16632228, 16632768, 16633248, 16633671,
  16634034, 16634340, 16634586, 16634774,
  16634903, 16634972, 16634980, 16634926,
  16634810, 16634628, 16634381, 16634066,
  16633680, 16633222, 16632688, 16632075,
  16631380, 16630598, 16629726, 16628757,
  16627686, 16626507, 16625212, 16623794,
  16622243, 16620548, 16618698, 16616679,
  16614476, 16612071, 16609444, 16606571,
  16603425, 16599973, 16596178, 16591995,
  16587369, 16582237, 16576520, 16570120,
  16562917, 16554758, 16545450, 16534739,
  16522287, 16507638, 16490152, 16468907,
  16442518, 16408804, 16364095, 16301683,
  16207738, 16047994, 15704248, 15472926
};

static const double wtab[128] = {
  1.62318314817e-08, 2.16291505214e-08, 2.54246305087e-08, 2.84579525938e-08,
  3.10340022482e-08, 3.33011726243e-08, 3.53439060345e-08, 3.72152672658e-08,
  3.8950989572e-08, 4.05763964764e-08, 4.21101548915e-08, 4.35664624904e-08,
  4.49563968336e-08, 4.62887864029e-08, 4.75707945735e-08, 4.88083237257e-08,
  5.00063025384e-08, 5.11688950428e-08, 5.22996558616e-08, 5.34016475624e-08,
  5.44775307871e-08, 5.55296344581e-08, 5.65600111659e-08, 5.75704813695e-08,
  5.85626690412e-08, 5.95380306862e-08, 6.04978791776e-08, 6.14434034901e-08,
  6.23756851626e-08, 6.32957121259e-08, 6.42043903937e-08, 6.51025540077e-08,
  6.59909735447e-08, 6.68703634341e-08, 6.77413882848e-08, 6.8604668381e-08,
  6.94607844804e-08, 7.03102820203e-08, 7.11536748229e-08, 7.1991448372e-08,
  7.2824062723e-08, 7.36519550992e-08, 7.44755422158e-08, 7.52952223703e-08,
  7.61113773308e-08, 7.69243740467e-08, 7.77345662086e-08, 7.85422956743e-08,
  7.93478937793e-08, 8.01516825471e-08, 8.09539758128e-08, 8.17550802699e-08,
  8.25552964535e-08, 8.33549196661e-08, 8.41542408569e-08, 8.49535474601e-08,
  8.57531242006e-08, 8.65532538723e-08, 8.73542180955e-08, 8.8156298059e-08,
  8.89597752521e-08, 8.97649321908e-08, 9.05720531451e-08, 9.138142487e-08,
  9.21933373471e-08, 9.30080845407e-08, 9.38259651738e-08, 9.46472835298e-08,
  9.54723502847e-08, 9.63014833769e-08, 9.71350089201e-08, 9.79732621669e-08,
  9.88165885297e-08, 9.96653446693e-08, 1.00519899658e-07, 1.0138063623e-07,
  1.02247952126e-07, 1.03122261554e-07, 1.04003996769e-07, 1.04893609795e-07,
  1.05791574313e-07, 1.06698387725e-07, 1.07614573423e-07, 1.08540683296e-07,
  1.09477300508e-07, 1.1042504257e-07, 1.11384564771e-07, 1.12356564007e-07,
  1.13341783071e-07, 1.14341015475e-07, 1.15355110887e-07, 1.16384981291e-07,
  1.17431607977e-07, 1.18496049514e-07, 1.19579450872e-07, 1.20683053909e-07,
  1.21808209468e-07, 1.2295639141e-07, 1.24129212952e-07, 1.25328445797e-07,
  1.26556042658e-07, 1.27814163916e-07, 1.29105209375e-07, 1.30431856341e-07,
  1.31797105598e-07, 1.3320433736e-07, 1.34657379914e-07, 1.36160594606e-07,
  1.37718982103e-07, 1.39338316679e-07, 1.41025317971e-07, 1.42787873535e-07,
  1.44635331499e-07, 1.4657889173e-07, 1.48632138436e-07, 1.50811780719e-07,
  1.53138707402e-07, 1.55639532047e-07, 1.58348931426e-07, 1.61313325908e-07,
  1.64596952856e-07, 1.68292495203e-07, 1.72541128694e-07, 1.77574279496e-07,
  1.83813550477e-07, 1.92166040885e-07, 2.05295471952e-07, 2.22600839893e-07
};


#ifdef __cplusplus
extern "C" 
{
#endif

    static type get_del (type x, type rational)
    {

        type xsq = 0.0;
        type del = 0.0;
        type result = 0.0;

        xsq = floor (x * GAUSS_SCALE) / GAUSS_SCALE;
        del = (x - xsq) * (x + xsq);
        del *= 0.5;

        result = exp (-0.5 * xsq * xsq) * exp (-1.0 * del) * rational;

        return result;

    }

    static type gauss_small (const type x)
    {

        unsigned int i;
        type result = 0.0;
        type xsq;
        type xnum;
        type xden;

        const type a[5] = 
        {
            2.2352520354606839287,
            161.02823106855587881,
            1067.6894854603709582,
            18154.981253343561249,
            0.065682337918207449113
        };
        
        const type b[4] = 
        {
            47.20258190468824187,
            976.09855173777669322,
            10260.932208618978205,
            45507.789335026729956
        };

        xsq = x * x;
        xnum = a[4] * xsq;
        xden = xsq;

        for (i = 0; i < 3; i++)
        {

            xnum = (xnum + a[i]) * xsq;
            xden = (xden + b[i]) * xsq;

        }

        result = x * (xnum + a[3]) / (xden + b[3]);

        return result;

    }

    static type gauss_medium (const type x)
    {

        unsigned int i;
        type temp = 0.0;
        type result = 0.0;
        type xnum;
        type xden;
        type absx;

        const type c[9] = 
        {
            0.39894151208813466764,
            8.8831497943883759412,
            93.506656132177855979,
            597.27027639480026226,
            2494.5375852903726711,
            6848.1904505362823326,
            11602.651437647350124,
            9842.7148383839780218,
            1.0765576773720192317e-8
        };
        
        const type d[8] = 
        {
            22.266688044328115691,
            235.38790178262499861,
            1519.377599407554805,
            6485.558298266760755,
            18615.571640885098091,
            34900.952721145977266,
            38912.003286093271411,
            19685.429676859990727
        };

        absx = fabs (x);

        xnum = c[8] * absx;
        xden = absx;

        for (i = 0; i < 7; i++)
        {

            xnum = (xnum + c[i]) * absx;
            xden = (xden + d[i]) * absx;

        }

        temp = (xnum + c[7]) / (xden + d[7]);

        result = get_del (x, temp);

        return result;

    }

    static type gauss_large (const type x)
    {
        
        int i;
        type result;
        type xsq;
        type temp;
        type xnum;
        type xden;
        type absx;

        const type p[6] = 
        {
            0.21589853405795699,
            0.1274011611602473639,
            0.022235277870649807,
            0.001421619193227893466,
            2.9112874951168792e-5,
            0.02307344176494017303
        };
        const type q[5] = 
        {
            1.28426009614491121,
            0.468238212480865118,
            0.0659881378689285515,
            0.00378239633202758244,
            7.29751555083966205e-5
        };

        absx = fabs (x);
        xsq = 1.0 / (x * x);
        xnum = p[5] * xsq;
        xden = xsq;

        for (i = 0; i < 4; i++)
        {

            xnum = (xnum + p[i]) * xsq;
            xden = (xden + q[i]) * xsq;

        }

        temp = xsq * (xnum + p[4]) / (xden + q[4]);
        temp = (M_1_SQRT2PI - temp) / absx;

        result = get_del (x, temp);

        return result;
    }

    type normalCdfSingle( type X, type u, type sigma )
    {

        X = ( X - u ) / sigma;

        type result;
        type absx = fabs (X);

        if (absx < GAUSS_EPSILON)
        {
            
            result = .5;

        }
        else if (absx < 0.66291)
        {

            result = 0.5 + gauss_small (X);

        }
        else if (absx < SQRT32)
        {

            result = gauss_medium (X);

            if (X > 0.0)
            {

                result = 1.0 - result;

            }


        }
        else if (X > GAUSS_XUPPER)
        {

            result = 1.0;

        }
        else if (X < GAUSS_XLOWER)
        {

            result = 0.0;

        }
        else
        {

            result = gauss_large (X);

            if (X > 0.0)
            {

                result = 1.0 - result;

            }

        }

        return result;
    
    }
    
    static type uniform()
    {
    
    	long unsigned int value = rand();
    	
    	return ( ( value + 0.0 ) / ( RAND_MAX ) );
    
    }
    
    static type normalSample( const type sigma )
    {
    
    	type x;
    	type y;
    	type rSquared;
    	
    	do
    	{
    	
    		x = -1.0 + 2.0 * uniform();
    		y = -1.0 + 2.0 * uniform();
    		
    		rSquared = x * x + y * y;
    	
    	}
    	while( rSquared > 1.0 || rSquared == 0 );
    	
    	return sigma * y * sqrt( -2.0 * log( rSquared )/ rSquared );
    
    }
    
    #define index( x, y, N ) ( ( ( x ) * ( N ) ) + ( y ) )
    
    void choleskyDecomposition( type* matrix, unsigned int N )
    {
    
    	unsigned int i;
    	unsigned int j;
    	unsigned int k;
    	
    	type A00 = matrix[0];
    	type L00 = sqrt( A00 );
    	
    	matrix[0] = L00;
    	
    	if( N > 1 )
    	{
    	
    		type A10 = matrix[ index( 1, 0, N ) ];
    		type A11 = matrix[ index( 1, 1, N ) ];
    		
    		type L10 = A10 / L00;
    		type diag = A11 - L10 * L10;
    		type L11 = sqrt( diag );
    		
    		matrix[ index( 1, 0, N ) ] = L10;
    		matrix[ index( 1, 1, N ) ] = L11;
    	
    	}
    	
    	for( k = 2; k < N; ++k )
		{
		
			type Akk = matrix[ index( k, k, N ) ];
			
			for( i = 0; i < k; ++i )
			{
			
				type sum = 0;
				
				type Aki = matrix[ index( k, i, N ) ];
				type Aii = matrix[ index( i, i, N ) ];
				
				int l;
				
				for( l = 0; l < i; ++l )
				{
				
					sum += matrix[ index( i, l, N ) ] * 
						matrix[ index( k, l, N ) ];
				
				}
				
				Aki = ( Aki - sum ) / Aii;
				matrix[ index( k, i, N ) ] = Aki;
			
			}
			
			type sum = 0;
			
			int l;
			
			for( l = 0; l < k; ++l )
			{
			
				sum += matrix[ index( k, l, N ) ] * matrix[ index( k, l, N ) ];
			
			}
			
			type diag = Akk - sum;
			type Lkk = sqrt( diag );
			matrix[ index( k, k, N ) ] = Lkk;
		
		}
		
		for( i = 1; i < N; ++i )
		{
		
			for( j = 0; j < i; ++j )
			{
			
				double Aij = matrix[ index( i, j, N ) ];
				matrix[ index( j, i, N ) ] = Aij;
			
			}
		
		}
    
    }
    
    void multivariateNormal( type* samples, const type* mean, type* cov, 
		unsigned int N )
	{

		type* random = (type*) malloc( sizeof(type) * N );

		for( unsigned int i = 0; i < N; ++i )
		{
		
			random[i] = normalSample(1);			
				
		}
	
		for( unsigned int i = 0; i < N; ++i )
		{
		
			samples[i] = mean[i];
			type total = 0;
			
			for( unsigned int j = 0; j < N; ++j )
			{
			
				samples[i] += cov[ j * N + i ] * random[i];
				total += cov[ j * N + i ];
			
			}
			
			samples[i] /= total;		
		
		}
		
		free( random );
		
	}
	
	void normalCdf( type* samples, type mean, type variance, unsigned int N )
	{
	
		int i;
		
		for( i = 0; i < N; ++i )
		{
		
			samples[i] = normalCdfSingle( samples[i], mean, variance );
		
		}
	
	}
	
	void transpose( type* matrix, unsigned int N )
	{
	
		int i;
		int j;
		
		for( i = 0; i < N; ++i )
		{
		
			for( j = 0; j < i; ++j )
			{
			
				type temp = matrix[ index( i, j, N ) ];
				matrix[ index( i, j, N ) ] = matrix[ index( j, i, N ) ];
				matrix[ index( j, i, N ) ] = temp;
			
			}
		
		}
	
	}
    
    #undef index
	
	static type gaussianZiggurat( type sigma )
	{
	
		unsigned long int i, j;
		int sign;
		type x, y;

		while(1)
		{
			
			i = uniform() * 256; 
			j = uniform() * 16777216;
			sign = (i & 0x80) ? +1 : -1;
			i &= 0x7f;

			x = j * wtab[i];

			if ( j < ktab[i] )
			{
			
				break;

			}

			if (i < 127)
			{
			
				type y0, y1, U1;
				y0 = ytab[i];
				y1 = ytab[i + 1];
				U1 = uniform();
				y = y1 + (y0 - y1) * U1;
				
			}
			else
			{
			
				double U1, U2;
				U1 = 1.0 - uniform();
				U2 = uniform();
				x = PARAM_R - log (U1) / PARAM_R;
				y = exp (-PARAM_R * (x - 0.5 * PARAM_R)) * U2;
			
			}

			if (y < exp (-0.5 * x * x))
			{
				break;
			
			}
			
		}

		return sign * sigma * x;
	
	}

	static type gamma( type a, type b )
	{
	
		if( a < 1 )
		{
		
			type u = uniform();
			return gamma( 1.0 + a, b ) * pow( u, 1.0 / a );
		
		}
		else
		{
		
			type x, v, u;
			type d = a - 1.0 / 3.0;
			type c = ( 1.0 / 3.0 ) / sqrt( d );
			
			while( 1 )
			{
			
				do
				{
				
					x = gaussianZiggurat( 1.0 );
					v = 1.0 + c * x;
				
				}
				while( v <= 0 );
				
				v = v * v * v;
				
				u = uniform();
				
				if( u < 1 - 0.0331 * x * x * x * x )
				{
				
					break;
				
				}
				
				if( log(u) < 0.5 * x * x + d * ( 1 - v + log ( v ) ) )
				{
				
					break;
				
				}
			
			}
			
			return b * d * v;
		
		}
	
	}

	static type beta( type a, type b )
	{
	
		type x1 = gamma( a, 1.0 );
		type x2 = gamma( b, 1.0 );
		
		return x1 / ( x1 + x2 );
	
	}

	type betaDistributionFromNormal( type mean, type stdev )
	{
	
		type y = stdev / mean;
		type y2 = y * y;
		
		type alpha = ( 1.0 - mean - mean * y2 ) / y2;
		type b = alpha * ( 1.0 / mean - 1.0 );
	
		return beta( alpha, b );
	
	}
    
#ifdef __cplusplus
}
#endif

#endif


/*!

	\file capModel3.cu
	
	\date Thursday December 18, 2008
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	
	\brief The source file for the CUDA CapModel3 simulation functions

*/

#ifndef CAP_MODEL_3_CU_INCLUDED
#define CAP_MODEL_3_CU_INCLUDED

#include "capModel3.hu"
#include "Cuda.h"
#include "CudaException.h"
#include "macros.h"
#include <stdint.h>

#define MAX_THREADS 64
#define MAX_CTAS 65535

////////////////////////////////////////////////////////////////////////////////
// Mersenne twister

static __device__ float mersenneTwister( CudaMersenneTwisterData* data )
{

	int iState, iState1, iStateM;
	unsigned int mti, mti1, mtiM, x;
	unsigned int mt[MT_NN];

	//Load bit-vector Mersenne Twister parameters
	CudaMersenneTwisterData config = *data;
	data->seed++;

	//Initialize current state
	mt[0] = config.seed;
	for(iState = 1; iState < MT_NN; iState++)
	{

		mt[iState] = (1812433253U * (mt[iState - 1] ^ 
			(mt[iState - 1] >> 30)) + iState) & MT_WMASK;

	}

	iState = 0;
	mti1 = mt[0];		

	iState1 = iState + 1;
	iStateM = iState + MT_MM;

	if(iState1 >= MT_NN)
	{
	
		iState1 -= MT_NN;
	
	}
	
	if(iStateM >= MT_NN)
	{
	
		iStateM -= MT_NN;
	
	}

	mti  = mti1;
	mti1 = mt[iState1];
	mtiM = mt[iStateM];

	x    = (mti & MT_UMASK) | (mti1 & MT_LMASK);
	x    =  mtiM ^ (x >> 1) ^ ((x & 1) ? config.matrix_a : 0);
	mt[iState] = x;
	iState = iState1;

	//Tempering transformation
	x ^= (x >> MT_SHIFT0);
	x ^= (x << MT_SHIFTB) & config.mask_b;
	x ^= (x << MT_SHIFTC) & config.mask_c;
	x ^= (x >> MT_SHIFT1);

	//Convert to (0, 1] float and write to global memory
	return ((float)x + 1.0f) / 4294967296.0f;	
	
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Random Number Generation

__device__ __constant__ FLOAT wtab[128];
__device__ __constant__ unsigned long ktab[128];
__device__ __constant__ FLOAT ytab[128];

static __device__  FLOAT get_del( FLOAT x, FLOAT rational)
{

    FLOAT xsq = 0.0;
    FLOAT del = 0.0;
    FLOAT result = 0.0;

    xsq = floor (x * GAUSS_SCALE) / GAUSS_SCALE;
    del = (x - xsq) * (x + xsq);
    del *= 0.5;

    result = exp (-0.5 * xsq * xsq) * exp (-1.0 * del) * rational;

    return result;

}

static __device__ FLOAT gauss_small (const FLOAT x)
{

    unsigned int i;
    FLOAT result = 0.0;
    FLOAT xsq;
    FLOAT xnum;
    FLOAT xden;

    const FLOAT a[5] = 
    {
        2.2352520354606839287,
        161.02823106855587881,
        1067.6894854603709582,
        18154.981253343561249,
        0.065682337918207449113
    };
    
    const FLOAT b[4] = 
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

static __device__ FLOAT gauss_medium (const FLOAT x)
{

    unsigned int i;
    FLOAT temp = 0.0;
    FLOAT result = 0.0;
    FLOAT xnum;
    FLOAT xden;
    FLOAT absx;

    const FLOAT c[9] = 
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
    
    const FLOAT d[8] = 
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

static __device__ FLOAT gauss_large (const FLOAT x)
{
    
    int i;
    FLOAT result;
    FLOAT xsq;
    FLOAT temp;
    FLOAT xnum;
    FLOAT xden;
    FLOAT absx;

    const FLOAT p[6] = 
    {
        0.21589853405795699,
        0.1274011611602473639,
        0.022235277870649807,
        0.001421619193227893466,
        2.9112874951168792e-5,
        0.02307344176494017303
    };
    const FLOAT q[5] = 
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

static __device__ FLOAT normalCdfSingle( FLOAT X, FLOAT u, FLOAT sigma )
{

    X = ( X - u ) / sigma;

    FLOAT result;
    FLOAT absx = fabs (X);

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

static __device__ FLOAT normalSample( CudaMersenneTwisterData* data, 
	const FLOAT sigma )
{

	FLOAT x;
	FLOAT y;
	FLOAT rSquared;
	
	do
	{
	
		x = -1.0 + 2.0 * mersenneTwister(data);
		y = -1.0 + 2.0 * mersenneTwister(data);
		
		rSquared = x * x + y * y;
	
	}
	while( rSquared > 1.0 || rSquared == 0 );
	
	return sigma * y * sqrt( -2.0 * log( rSquared )/ rSquared );

}

__device__ void multivariateNormal( CudaMersenneTwisterData* data, 
	FLOAT* samples, const FLOAT* mean, FLOAT* cov, unsigned int N, 
	FLOAT* random )
{

	for( unsigned int i = 0; i < N; ++i )
	{
	
		random[i] = normalSample( data, 1 );			
			
	}

	for( unsigned int i = 0; i < N; ++i )
	{
	
		samples[i] = mean[i];
		FLOAT total = 0;
		
		for( unsigned int j = 0; j < N; ++j )
		{
		
			samples[i] += cov[ j * N + i ] * random[i];
			total += cov[ j * N + i ];
		
		}
		
		samples[i] /= total;		
	
	}
	
}

__device__ void normalCdf( CudaMersenneTwisterData* data, FLOAT* samples, 
	FLOAT mean, FLOAT variance, unsigned int N )
{

	int i;
	
	for( i = 0; i < N; ++i )
	{
	
		samples[i] = normalCdfSingle( samples[i], mean, variance );
	
	}

}

static __device__ FLOAT gaussianZiggurat( CudaMersenneTwisterData* data, 
	FLOAT sigma )
{

	unsigned long int i, j;
	int sign;
	FLOAT x, y;

	while(1)
	{
		
		i = mersenneTwister(data) * 256; 
		j = mersenneTwister(data) * 16777216;
		sign = (i & 0x80) ? +1 : -1;
		i &= 0x7f;

		x = j * wtab[i];

		if ( j < ktab[i] )
		{
		
			break;

		}

		if (i < 127)
		{
		
			FLOAT y0, y1, U1;
			y0 = ytab[i];
			y1 = ytab[i + 1];
			U1 = mersenneTwister(data);
			y = y1 + (y0 - y1) * U1;
			
		}
		else
		{
		
			double U1, U2;
			U1 = 1.0 - mersenneTwister(data);
			U2 = mersenneTwister(data);
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

static __device__ FLOAT gammaBase( CudaMersenneTwisterData* data, FLOAT a, 
	FLOAT b )
{

	FLOAT x, v, u;
	FLOAT d = a - 1.0 / 3.0;
	FLOAT c = ( 1.0 / 3.0 ) / sqrt( d );
	
	while( 1 )
	{
	
		do
		{
		
			x = gaussianZiggurat( data, 1.0 );
			v = 1.0 + c * x;
		
		}
		while( v <= 0 );
		
		v = v * v * v;
		
		u = mersenneTwister(data);
		
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

static __device__ FLOAT gamma( CudaMersenneTwisterData* data, FLOAT a, FLOAT b )
{

	FLOAT factor = 1.0;

	while( a < 1 )
	{
	
		FLOAT u = mersenneTwister(data);
		a += 1.0;
		factor *= pow( u, (float) ( 1.0 / a ) );
	
	}
	
	return gammaBase( data, a, b ) * factor;

}

static __device__ FLOAT beta( CudaMersenneTwisterData* data, FLOAT a, FLOAT b )
{

	FLOAT x1 = gamma( data, a, 1.0 );
	FLOAT x2 = gamma( data, b, 1.0 );
	
	return x1 / ( x1 + x2 );

}

static __device__ FLOAT betaDistributionFromNormal( 
	CudaMersenneTwisterData* data, FLOAT mean, FLOAT stdev )
{

	FLOAT y = stdev / mean;
	FLOAT y2 = y * y;
	
	FLOAT alpha = ( 1.0 - mean - mean * y2 ) / y2;
	FLOAT b = alpha * ( 1.0 / mean - 1.0 );

	return beta( data, alpha, b );

}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// DEVICE FUNCTIONS
static __host__ __device__ unsigned int scratchSize( CudaInvariants* 
	invariants )
{

	// scratch object
	unsigned int size = sizeof( CudaScratch );

	// samples
	size += invariants->parameters->chunkSize * invariants->obligorSize * 
		sizeof( FLOAT );

	// counter cf
	size += ( 3 * sizeof( FLOAT ) * invariants->quarterSize + 
		sizeof( CudaCounterCf ) ) * invariants->counterPartySize;

	//cdsIncomeCf;
	//cdsExpenseCf;
	//marketPrice;
	//coupons;
	//discount;
	//capitalBalance;
	//premium;
	//investIncrement;
	//income;
	//claims;
	//paid;
	//operatingExpense;
	//debtService;
	//managementFee;
	//expense;
	//loss;
	//debtLoss;
	
	size += sizeof( FLOAT ) * invariants->quarterSize * 17;
	
	// random
	size += invariants->obligorSize * sizeof( FLOAT );
	
	return size;

}

static __host__ __device__ unsigned int invariantSize( CudaInvariants* 
	invariants, unsigned int threads )
{

	unsigned int size = sizeof( CudaInvariants );
	
	size += threads * sizeof( CudaMersenneTwisterData );
	size += sizeof( CudaSimulationParameters );
	size += invariants->obligorSize * sizeof( CudaObligor );
	size += invariants->portfolioSize * sizeof( CudaPortfolio );
	size += invariants->quarterSize * sizeof( unsigned int );
	
	size += invariants->obligorSize * sizeof( FLOAT );
	size += invariants->obligorSize * invariants->obligorSize * sizeof( FLOAT );
	size += invariants->obligorSize * sizeof( FLOAT );

	return size;

}

static __device__ void initializeScratch( CudaInvariants* 
	invariants, CudaScratch* scratch )
{

	uint8_t* data = (uint8_t*) scratch;

	// samples
	data += sizeof( CudaScratch );
	scratch->samples = ( FLOAT* ) ( data );

	//countercf
	data += invariants->parameters->chunkSize * invariants->obligorSize * 
		sizeof( FLOAT );
	scratch->countercf = ( CudaCounterCf* ) data;
	
	data += invariants->counterPartySize * sizeof( CudaCounterCf );
	
	for( unsigned int i = 0; i < invariants->counterPartySize; ++i )
	{
	
		// income
		scratch->countercf[i].income = (FLOAT*) data;
		
		// expense
		data += sizeof( FLOAT ) * invariants->quarterSize;
		scratch->countercf[i].expense = (FLOAT*) data;
		
		// loss
		data += sizeof( FLOAT ) * invariants->quarterSize;
		scratch->countercf[i].loss = (FLOAT*) data;
		
		data += sizeof( FLOAT ) * invariants->quarterSize;
	
	}

	//cdsIncomeCf;
	scratch->cdsIncomeCf = (FLOAT*) data;

	//cdsExpenseCf;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->cdsExpenseCf = (FLOAT*) data;

	//marketPrice;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->marketPrice = (FLOAT*) data;

	//coupons;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->coupons = (FLOAT*) data;

	//discount;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->discount = (FLOAT*) data;

	//capitalBalance;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->capitalBalance = (FLOAT*) data;

	//premium;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->premium = (FLOAT*) data;

	//investIncrement;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->investIncrement = (FLOAT*) data;

	//income;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->income = (FLOAT*) data;

	//claims;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->claims = (FLOAT*) data;

	//paid;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->paid = (FLOAT*) data;

	//operatingExpense;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->operatingExpense = (FLOAT*) data;

	//debtService;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->debtService = (FLOAT*) data;

	//managementFee;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->managementFee = (FLOAT*) data;

	//expense;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->expense = (FLOAT*) data;

	//loss;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->loss = (FLOAT*) data;

	//debtLoss;
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->debtLoss = (FLOAT*) data;
	
	// random
	data += sizeof( FLOAT ) * invariants->quarterSize;
	scratch->random = (FLOAT*) data;

}

static __device__ void initializeInvariants( CudaInvariants* invariants )
{

	uint8_t* data = ( uint8_t* ) invariants;
	
	data += sizeof( CudaInvariants );
	invariants->twisters = ( CudaMersenneTwisterData* ) data;
	
	data += TOTAL_THREADS() * sizeof( CudaMersenneTwisterData );
	invariants->parameters = ( CudaSimulationParameters* ) data;
	
	data += sizeof( CudaSimulationParameters );
	invariants->obligors = ( CudaObligor* ) data;
	
	data += invariants->obligorSize * sizeof( CudaObligor );
	invariants->portfolios = ( CudaPortfolio* ) data;
	
	data += invariants->portfolioSize * sizeof( CudaPortfolio );
	invariants->quarters = ( unsigned int* ) data;
	
	data += invariants->quarterSize * sizeof( unsigned int );
	invariants->mean = ( FLOAT* ) data;
	
	
	data += invariants->obligorSize * sizeof( FLOAT );
	invariants->correlation = ( FLOAT* ) data;
	
	data += invariants->obligorSize * invariants->obligorSize * sizeof( FLOAT );
	invariants->defaultProbability = ( FLOAT* ) data;
	
}

static __device__ void clearResult( CudaResult* result )
{

	result->claimProbability = 0.0;
	result->defaultProbability = 0.0;
	result->expectedClaim = 0.0;
	result->expectedLoss = 0.0;
	result->expectedLossPercent = 0.0;

	result->maxClaim = 0.0;
	result->maxClaimPv = 0.0;

}

static __device__ void capModel3Thread( void* shared, CudaInvariants* 
	invariants, CudaScratch* scratch, CudaResult* results )
{

	// initialize scratch
	initializeScratch( invariants, scratch );

	// clear results
	for( unsigned int i = 0; i < ( invariants->counterPartySize + 1); ++i )
	{
	
		clearResult( results + i );
	
	}
	
	// step 2 - generate random numbers
	
	// set seed
	invariants->twisters[ GLOBAL_ID() ].seed = invariants->seed;
	
	// assume the correlation has already been passed through the 
	// cholesky decomposition
	
	for( unsigned int i = 0; i < invariants->parameters->chunkSize; ++i )
	{
	
		multivariateNormal( invariants->twisters + GLOBAL_ID(), 
			scratch->samples + ( i * invariants->obligorSize ), 
			invariants->mean, invariants->correlation, 
			invariants->obligorSize, scratch->random );			
		normalCdf( invariants->twisters + GLOBAL_ID(),
			scratch->samples + ( i * invariants->obligorSize ), 0, 1, 
			invariants->obligorSize );
	
	}
	
	for( unsigned int i = 0; i < invariants->parameters->chunkSize; ++i )
	{
	
		for( unsigned int j = 0; j < invariants->obligorSize; ++j )
		{

			scratch->samples[i * invariants->obligorSize + j] = 10.0 * log( 
				scratch->samples[i * invariants->obligorSize + j] ) / 
				log( 1.0 - invariants->defaultProbability[j] );
			
		}
	
	}
	
	// main simulation loop
	for( unsigned int simNumber = 0; simNumber < 
		invariants->parameters->chunkSize; 
		++simNumber )
	{
	
		// step 3
	
		// zero out counter parties
		for( unsigned int i = 0; i < invariants->counterPartySize; ++i )
		{
		
			for( unsigned int j = 0; j < invariants->quarterSize; ++j )
			{
			
				scratch->countercf[i].income[j] = 0.0;
				scratch->countercf[i].expense[j] = 0.0;
				scratch->countercf[i].loss[j] = 0.0;
			
			}
		
		}
		
		// for each portfolio
		for( unsigned int portfolioId = 0; 
			portfolioId < invariants->portfolioSize; ++portfolioId )
		{
		
			// zero out cds stats
			for( unsigned int j = 0; j < invariants->quarterSize; ++j )
			{
			
				scratch->cdsIncomeCf[j] = 0.0;
				scratch->cdsExpenseCf[j] = 0.0;
			
			}
			
			const CudaPortfolio* portfolio = 
				invariants->portfolios + portfolioId;
			
			for( unsigned int i = 0; 
				i < MIN( portfolio->quartersToMaturity + 1, 
				invariants->quarterSize ); ++i )
			{
			
				scratch->cdsIncomeCf[i] = portfolio->quantity * 
					portfolio->spread / 4.0;
			
			}
			
			FLOAT value = scratch->samples[ simNumber * 
				invariants->obligorSize + portfolio->obligorId ];
				
			if( value < portfolio->yearsToMaturity )
			{
			
				unsigned int defaultQuarter = 0;
				bool found = false;
					
				for( ; defaultQuarter < invariants->quarterSize - 1; 
					++defaultQuarter )
				{
				
					if( (invariants->quarters)[defaultQuarter + 1] > value )
					{
					
						found = true;
						break;
					
					}
				
				}
						
				if( !found )
				{
		
					++defaultQuarter;
		
				}
				
				for( unsigned int i = defaultQuarter; 
					i < invariants->quarterSize; ++i )
				{
				
					scratch->cdsIncomeCf[i] = 0.0;
				
				}
				
				scratch->cdsExpenseCf[ defaultQuarter ] = 
					portfolio->quantity * 
					betaDistributionFromNormal( 
					invariants->twisters + GLOBAL_ID(), 
					invariants->parameters->lgdMean, 
					invariants->parameters->lgdStdev );
			
			}
			
			__syncthreads();
			
			CudaCounterCf* counter = scratch->countercf + portfolio->counterId;
			
			if( portfolio->quantity > 0 )
			{
				
				for( unsigned int i = 0; i < invariants->quarterSize; ++i )
				{
				
					counter->income[i] += scratch->cdsIncomeCf[i];
					counter->expense[i] += scratch->cdsExpenseCf[i];
				
				}
			
			}
			else
			{
			
				for( unsigned int i = 0; i < invariants->quarterSize; ++i )
				{
				
					counter->income[i] -= scratch->cdsExpenseCf[i];
					counter->expense[i] -= scratch->cdsIncomeCf[i];
				
				}
			
			}
		
		}
			
		// iterate over all counters
		for( unsigned int counterId = 0; 
			counterId < invariants->counterPartySize; ++counterId )
		{
		
			unsigned int defaultQuarter = 0;
			bool found = false;
			FLOAT value = scratch->samples[ simNumber * 
				invariants->obligorSize + counterId ];
				
			for( ; defaultQuarter < invariants->quarterSize - 1; 
				++defaultQuarter )
			{
			
				if( (invariants->quarters)[defaultQuarter + 1] > value )
				{
				
					found = true;
					break;
				
				}
			
			}
					
			if( !found )
			{
	
				++defaultQuarter;
	
			}
			
			for( unsigned int i = defaultQuarter; 
				i < invariants->quarterSize; ++i )
			{
			
				scratch->countercf[counterId].income[i] = 0.0;
			
			}
		
		}
			
		__syncthreads();
		
		//step 4
		for( unsigned int j = 0; j < invariants->quarterSize; ++j )
		{
		
			scratch->marketPrice[j] = 1.0;
			scratch->coupons[j] = invariants->parameters->investRate / 4.0;
			scratch->discount[j] = ( 1.0 / pow( (float) ( 1 + 
				invariants->parameters->investRate / 4.0 ), 
				(float)( j + 1 ) ) );
		
		}
		
		// step 5
		FLOAT capital = invariants->parameters->initialEquity + 
			invariants->parameters->debtParameter;
		
		for( unsigned int j = 0; j < invariants->quarterSize; ++j )
		{
		
			scratch->capitalBalance[j] = 0.0;
			scratch->premium[j] = 0.0;
			scratch->investIncrement[j] = 0.0;

			scratch->income[j] = 0.0;
			scratch->claims[j] = 0.0;
			scratch->paid[j] = 0.0;

			scratch->debtService[j] = 0.0;
			scratch->expense[j] = 0.0;
			scratch->loss[j] = 0.0;

			scratch->debtLoss[j] = 0.0;
			scratch->managementFee[j] = 0.0;
			
			scratch->operatingExpense[j] = 
				( invariants->parameters->optionExpense / 4.0 ) * 
				pow( (float) ( 1.0 + invariants->parameters->optionInflation 
				/ 4.0 ) , (float) (j + 1) );
		
		}
		
		bool inRunOff = false;
		
		for( unsigned int quarter = 0; 
			quarter < invariants->quarterSize; ++quarter )
		{
		
			// premium and recoveries
			for( unsigned int i = 0; i < invariants->counterPartySize; ++i )
			{
		
				scratch->premium[ quarter ] += 
					scratch->countercf[i].income[ quarter ];
		
			}
			
			// investment income
			scratch->investIncrement[ quarter ] = MAX( 0.0, capital * 
				scratch->coupons[ quarter ] / scratch->marketPrice[ quarter ] );
				
			// total income
			scratch->income[ quarter ] += scratch->premium[ quarter ] + 
				scratch->investIncrement[ quarter ];
			capital += scratch->income[ quarter ];
		
			// 1st claims
			for( unsigned int i = 0; i < invariants->counterPartySize; ++i )
			{
		
				scratch->claims[ quarter ] += 
					scratch->countercf[i].expense[ quarter ];
		
			}
			
			scratch->paid[ quarter ] = MIN( capital, 
				scratch->claims[ quarter ] );
			capital -= scratch->paid[ quarter ];
			scratch->expense[ quarter ] += scratch->paid[ quarter ];
			
			if( scratch->paid[ quarter ] < scratch->claims[ quarter ] )
			{
			
				inRunOff = true;
				
				for( unsigned int j = 0; j < invariants->counterPartySize; ++j )
				{
		
					if( scratch->countercf[j].expense[ quarter ] > 0 )
					{
					
						for( unsigned int i = quarter + 1; 
							i < invariants->quarterSize; ++i )
						{
						
							scratch->countercf[j].income[i] = 0;
						
						}
					
					}
		
				}
				
				scratch->loss[ quarter ] = scratch->claims[ quarter ] - 
					scratch->paid[ quarter ];
				FLOAT percentPaid = scratch->paid[ quarter ] / 
					scratch->claims[ quarter ];
			
				for( unsigned int j = 0; j < invariants->counterPartySize; ++j )
				{
				
					scratch->countercf[j].loss[ quarter ] = 
						scratch->countercf[j].expense[ quarter ] * 
						( 1.0 - percentPaid );
				
				}
			
			}
			
			__syncthreads();
			
			// debt service
			scratch->debtService[ quarter ] = 
				invariants->parameters->debtParameter * 
				invariants->parameters->debtRate;
			scratch->debtService[ quarter ] = MAX( 0, 
				MIN( scratch->debtService[ quarter ], capital ) );
			capital -= scratch->debtService[ quarter ];
			scratch->expense[ quarter ] += scratch->debtService[ quarter ];
			
			if( capital < invariants->parameters->debtParameter )
			{
			
				scratch->debtLoss[quarter] = MAX( 0, 
					invariants->parameters->debtParameter - capital );
			
			}
			
			__syncthreads();
			
			// operating expenses
			scratch->operatingExpense[ quarter ] = 
				MIN( scratch->operatingExpense[ quarter ], MAX( capital, 0 ) );
			capital -= scratch->operatingExpense[ quarter ];
			scratch->expense[ quarter ] += scratch->operatingExpense[ quarter ];
			
			// management fee
			if( !inRunOff )
			{
			
				FLOAT assetBase;
			
				if( quarter == 0 )
				{
				
					assetBase = invariants->parameters->initialEquity + 
						invariants->parameters->debtParameter;
				
				}
				else
				{
				
					assetBase = scratch->capitalBalance[ quarter - 1 ];
				
				}
				
				FLOAT assetFee = 0.25 * 
					invariants->parameters->assetManagementFeeRate * assetBase;
					
				FLOAT sum = 0;
				
				for( unsigned int portfolioId = 0; 
					portfolioId < invariants->portfolioSize; ++portfolioId )
				{
				
					sum += invariants->portfolios[portfolioId].quantity;
				
				}
				
				scratch->managementFee[quarter] = 
					MIN( MAX( capital, 0 ), assetFee + 
					MIN( 0.25 * invariants->parameters->managementFeeRate 
					* sum, 0.25 * invariants->parameters->managementFeeCap ) );
									
			}
			
			__syncthreads();
			
			capital -= scratch->managementFee[ quarter ];
			scratch->expense[ quarter ] += scratch->managementFee[ quarter ];
			scratch->capitalBalance[ quarter ] = capital;
			capital = MAX( capital, 0 );
		
		}
		
		// step 6
		
		for( unsigned int j = 0; j < invariants->counterPartySize; ++j )
		{
		
			CudaCounterCf* v = scratch->countercf + j;
			CudaResult* r = results + j;
			
			FLOAT pvClaim = 0;
			FLOAT pvLoss = 0;
			FLOAT cpClaim = 0;
			FLOAT cpLoss = 0;
			
			for( unsigned int i = 0; i < invariants->quarterSize; ++i )
			{
			
				pvClaim += v->expense[i] * scratch->discount[i];
				pvLoss += v->loss[i] * scratch->discount[i];
				cpClaim += v->expense[i];
				cpLoss += v->loss[i];
			
			}
							
			if( pvClaim > 0 )
			{
			
				
				r->claimProbability += 1;
				r->expectedClaim += pvClaim;
				r->maxClaim = MAX( r->maxClaim, cpClaim );
				r->maxClaimPv = MAX( r->maxClaimPv, pvClaim );
				
				if( pvLoss > 0 )
				{
				
					r->defaultProbability += 1;
					r->expectedClaim += pvLoss;
					r->expectedLossPercent += ( pvLoss / pvClaim );
				
				}
				
			}
			
			__syncthreads();
		
		}
		
		FLOAT pvClaim = 0;
		FLOAT pvLoss = 0;
		FLOAT cpClaim = 0;
		FLOAT cpLoss = 0;
		
		for( unsigned int i = 0; i < invariants->quarterSize; ++i )
		{
		
			pvClaim += scratch->claims[i] * scratch->discount[i];
			pvLoss += scratch->loss[i] * scratch->discount[i];
			cpClaim += scratch->claims[i];
			cpLoss += scratch->loss[i];
		
		}
		
		CudaResult* r = &results[invariants->counterPartySize];
		
		if( pvClaim > 0 )
		{
		
			r->claimProbability += 1;
			r->expectedClaim += pvClaim;
			r->maxClaim = MAX( r->maxClaim, cpClaim );
			r->maxClaimPv = MAX( r->maxClaimPv, pvClaim );
			
			if( pvLoss > 0 )
			{
			
				r->defaultProbability += 1;
				r->expectedClaim += pvLoss;
				r->expectedLossPercent += ( pvLoss / pvClaim );
			
			}
			
		}
		
		__syncthreads();
	
	}

}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
__global__ void capModel3Kernel( CudaInvariants* invariants, 
	CudaScratch* scratch, CudaResult* results )
{

	unsigned int id = GLOBAL_ID();
	
	extern __shared__ int shared[];
	
	// initialize invariants
	// this is not normally thread safe, but okay since every grid 
	// writes the same data
	if( THREAD_ID() == 0 )
	{
	
		initializeInvariants( invariants );
	
	}
	
	__syncthreads();
	
	uint8_t* scratchData = (uint8_t*) scratch;
	unsigned int scratchBytes = scratchSize( invariants );
	CudaScratch* scratchPointer = ( CudaScratch* ) ( scratchData + 
		IMUL( scratchBytes, id ) );
		
	uint8_t* resultData = (uint8_t*) results;
	unsigned int resultBytes = sizeof( CudaResult ) * 
		( invariants->counterPartySize + 1);
	CudaResult* resultPointer = ( CudaResult* ) ( IMUL( id, resultBytes ) + 
		resultData );
	
	capModel3Thread( (void*)shared, invariants, scratchPointer, resultPointer );
	
}

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// C FUNCTIONS

static void packInvariants( CudaInvariants* result, 
	const CudaInvariants* source, unsigned int threads )
{

	uint8_t* data = ( uint8_t* ) result;
	
	data += sizeof( CudaInvariants );
	memcpy( data, source->twisters, threads * 
		sizeof( CudaMersenneTwisterData ) );
	result->twisters = ( CudaMersenneTwisterData* ) data;
	
	data += threads * sizeof( CudaMersenneTwisterData );
	memcpy( data, source->parameters, sizeof( CudaSimulationParameters ) );
	result->parameters = ( CudaSimulationParameters* ) data;
	
	data += sizeof( CudaSimulationParameters );
	memcpy( data, source->obligors, 
		source->obligorSize * sizeof( CudaObligor ) );
	result->obligors = ( CudaObligor* ) data;
	
	data += source->obligorSize * sizeof( CudaObligor );
	memcpy( data, source->portfolios, 
		source->portfolioSize * sizeof( CudaPortfolio ) );
	result->portfolios = ( CudaPortfolio* ) data;
	
	data += source->portfolioSize * sizeof( CudaPortfolio );
	memcpy( data, source->quarters, 
		source->quarterSize * sizeof( unsigned int ) );
	result->quarters = ( unsigned int* ) data;
	
	data += source->quarterSize * sizeof( unsigned int );
	memcpy( data, source->mean, 
		source->obligorSize * sizeof( FLOAT ) );
	result->mean = ( FLOAT* ) data;
	
	data += source->obligorSize * sizeof( FLOAT );
	memcpy( data, source->correlation, 
		source->obligorSize * source->obligorSize * sizeof( FLOAT ) );
	result->correlation = ( FLOAT* ) data;
	
	data += source->obligorSize * source->obligorSize * sizeof( FLOAT );
	memcpy( data, source->defaultProbability, 
		source->obligorSize * sizeof( FLOAT ) );
	result->defaultProbability = ( FLOAT* ) data;
		
	// size parameters
	result->device = source->device;
	result->seed = source->seed;
	
	result->maxTwisters = source->maxTwisters;
	
	result->obligorSize = source->obligorSize;
	result->portfolioSize = source->portfolioSize;
	
	result->counterPartySize = source->counterPartySize;
	result->quarterSize = source->quarterSize;
	
}

static void reduceResults( CudaResult* results, CudaResult* expandedResults, 
	CudaInvariants* invariants, unsigned int threads, FLOAT correction )
{

	unsigned int step = ( invariants->counterPartySize + 1);

	// clear results
	for( unsigned int j = 0; j < step; ++j )
	{
	
		results[j].claimProbability = 0.0;
		results[j].defaultProbability = 0.0;
		results[j].expectedClaim = 0.0;
		results[j].expectedLoss = 0.0;
		results[j].expectedLossPercent = 0.0;

		results[j].maxClaim = 0.0;
		results[j].maxClaimPv = 0.0;
	
	}

	// reduce the expanded results
	for( unsigned int i = 0; i < threads; ++i )
	{
	
		for( unsigned int j = 0; j < step; ++j )
		{
		
			results[j].claimProbability += 
				expandedResults[ i*step + j ].claimProbability;
			results[j].defaultProbability += 
				expandedResults[ i*step + j ].defaultProbability;
			results[j].expectedClaim +=  
				expandedResults[ i*step + j ].expectedClaim;
			results[j].expectedLoss += 
				expandedResults[ i*step + j ].expectedLoss;
			results[j].expectedLossPercent += 
				expandedResults[ i*step + j ].expectedLossPercent;

			results[j].maxClaim = MAX( results[j].maxClaim, 
				expandedResults[ i*step + j ].maxClaim );
			results[j].maxClaimPv = MAX( results[j].maxClaimPv, 
				expandedResults[ i*step + j ].maxClaimPv );
		
		}
	
	}
	
	// correct
	if( correction == 1.0 )
	{
	
		return;
	
	}
	
	for( unsigned int j = 0; j < step; ++j )
	{
	
		results[j].claimProbability *= correction;
		results[j].defaultProbability *= correction;
		results[j].expectedClaim *= correction;
		results[j].expectedLoss *= correction;
		results[j].expectedLossPercent *= correction;

		results[j].maxClaim *= correction;
		results[j].maxClaimPv *= correction;
	
	}

}

void capModel3Cuda( CudaInvariants* invariants, CudaResult* results )
{

	// configuration
	hydrazine::cudaCheck( cudaGetDevice( &invariants->device ) );

	// streams
	cudaStream_t stream;
	hydrazine::cudaCheck( cudaStreamCreate( &stream ) );
/*
	// symbols
	hydrazine::cudaCheck( cudaMemcpyToSymbol( wtab, hostWtab, 128 * sizeof(FLOAT), 
		0, cudaMemcpyHostToDevice ) );
	hydrazine::cudaCheck( cudaMemcpyToSymbol( ytab, hostYtab, 128 * sizeof(FLOAT), 
		0, cudaMemcpyHostToDevice ) );
	hydrazine::cudaCheck( cudaMemcpyToSymbol( ktab, hostKtab, 
		128 * sizeof(unsigned long), 
		0, cudaMemcpyHostToDevice ) );	
*/
	cudaDeviceProp properties;
	hydrazine::cudaCheck( cudaGetDeviceProperties( &properties, 
		invariants->device ) );

	unsigned int totalMemory = properties.totalGlobalMem;
	unsigned int maxThreads = totalMemory - invariantSize( invariants, 0 );
	maxThreads = MIN( maxThreads, MAX_THREADS );
	maxThreads = MIN( maxThreads, 
		(unsigned int)properties.regsPerBlock / MIN_REGS );
	maxThreads = MIN( maxThreads, (unsigned int)properties.maxThreadsDim[0] );
	
	unsigned int maxCtas = MAX_CTAS;
	maxCtas = MIN( maxCtas, CEIL_DIV( invariants->parameters->chunkSize, 
		maxThreads ) );
	
	unsigned int threads = maxCtas * maxThreads;

	unsigned int chunkSize = invariants->parameters->chunkSize;

	invariants->parameters->chunkSize = 
		CEIL_DIV( invariants->parameters->chunkSize, threads );
	
	// memory
	CudaScratch* deviceScratch;
	CudaInvariants* hostInvariants;
	CudaInvariants* deviceInvariants;
	CudaResult* deviceResults;
	CudaResult* hostResults;
	
	unsigned int scratchBytes = threads * scratchSize( invariants );
	unsigned int invariantBytes = invariantSize( invariants, threads );
	unsigned int resultBytes = threads * 
		( invariants->counterPartySize + 1) * sizeof( CudaResult );
	
	hydrazine::cudaCheck( cudaMallocHost( (void**) &hostInvariants, invariantBytes ) );
	hydrazine::cudaCheck( cudaMallocHost( (void**) &hostResults, resultBytes ) );
	
	hydrazine::cudaCheck( cudaMalloc( (void**) &deviceResults, resultBytes ) );
	hydrazine::cudaCheck( cudaMalloc( (void**) &deviceScratch, scratchBytes ) );
	hydrazine::cudaCheck( cudaMalloc( (void**) &deviceInvariants, invariantBytes ) );
	
	// compute iterations
	
	packInvariants( hostInvariants, invariants, threads );
	
	// copy
	hydrazine::cudaCheck( cudaMemcpyAsync( deviceInvariants, hostInvariants, 
		invariantBytes, cudaMemcpyHostToDevice, stream ) );
			
	// compute
	capModel3Kernel<<< maxCtas, maxThreads, 0, stream >>>( deviceInvariants, 
		deviceScratch, deviceResults );
	
	// copy
	hydrazine::cudaCheck( cudaMemcpyAsync( hostResults, deviceResults, 
		resultBytes, cudaMemcpyDeviceToHost, stream ) );
	
	FLOAT correctionFactor = ( chunkSize + 0.0 ) / 
		( threads * invariants->parameters->chunkSize );
	
	hydrazine::cudaCheck( cudaStreamSynchronize( stream ) );
	
	// reduction
	reduceResults( results, hostResults, invariants, threads, 
		correctionFactor );
	
	// cleanup
	hydrazine::cudaCheck( cudaStreamDestroy( stream ) );
	
	hydrazine::cudaCheck( cudaFreeHost( hostResults ) );
	hydrazine::cudaCheck( cudaFreeHost( hostInvariants ) );
	
	hydrazine::cudaCheck( cudaFree( deviceInvariants ) );
	hydrazine::cudaCheck( cudaFree( deviceScratch ) );
	hydrazine::cudaCheck( cudaFree( deviceResults ) );

}

////////////////////////////////////////////////////////////////////////////////

#endif


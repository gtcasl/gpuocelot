#ifndef MULTIVARIATE_NORMAL_H_INCLUDED
#define MULTIVARIATE_NORMAL_H_INCLUDED

#ifndef type
#define type float
#endif

#ifdef __cplusplus
extern "C" 
{
#endif

	/*!
	
		\brief Cholesky decomposition on a positive square definite matrix
		
		\param matrix the matrix being converted to L and Lt
		
		\param N the size of the matrix
	
	*/
	void choleskyDecomposition( type* matrix, unsigned int N );
	
	/*!

		\brief Compute a set of samples from the multivaraite normal distribution
	
		\param samples The generated sames, vector of length N
	
		\param mean The means for each distribution, vector of length N
	
		\param cov The covariance matrix, matrix of N*N, should be already
			run through the cholesky
	
		\param N, the number of variables

	*/
	void multivariateNormal( type* samples, const type* mean, type* cov, 
		unsigned int N );
		
	/*!
	
		\brief Compute the normal CDF of a vector
		
		\param samples, the samples to update
		
		\param mean the mean of the cdf
		
		\param the variance of the cdf
		\N the number of samples
		
	
	*/
	void normalCdf( type* samples, type mean, type variance, unsigned int N );

	/*!
	
		\brief Transpose a square matrix
	
		\param matrix The matrix being transposed
		
		\param N the size of the matrix
	
	*/
	void transpose( type* matrix, unsigned int N );
	
	/*!
	
		\brief Sample a beta distribution drawn from a normal
	
	*/
	type betaDistributionFromNormal( type mean, type stdev );

#ifdef __cplusplus
}
#endif

#endif


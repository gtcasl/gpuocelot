/*!

	\file CapModel3.h
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>

	\date Saturday December 13, 2008

	\brief The header file for the CapModel3 class.

*/

#ifndef CAP_MODEL_3_H_INCLUDED
#define CAP_MODEL_3_H_INCLUDED

#include "SimulationParameters.h"
#include "capModel3.hu"
#include <map>
#include <set>
#include <fstream>
#include <deque>

/*!
	
	\brief A namespace for cap model simulation classes and functions

*/
namespace sim
{

	/*!
	
		\brief A class for performing the cap model level 3 simulation 
			in C++ only.
	
	*/
	class CapModel3 : hydrazine::Stringable
	{
	
		private:
		
			class Rating: public hydrazine::Stringable
			{
			
				public:
				
					typedef std::deque< FLOAT > Probabilities;
					
				public:
				
					Probabilities defaultProbabilities;
					unsigned int id;
					std::string name;
					FLOAT warf;
					
				public:
				
					std::string toString() const; 
			
			};
			
			class Industry: public hydrazine::Stringable
			{
			
				public:
				
					unsigned int id;
					
					std::string name;
					std::string regionFactor;
					std::string lmhFactor;
					std::string superSector;
					
				public:
				
					std::string toString() const; 
			
			};
			
			class Obligor
			{
			
				public:
				
					unsigned int id;
					unsigned int index;
					
					std::string ticker;
					std::string name;
					std::string country;
					std::string ccy;
					
					unsigned int ratingId;
					unsigned int industryId;
					
					std::string seniority;
					std::string restructuring;
					std::string cuspip;
					
					unsigned int fiveYearSpread;
				
				public:
				
					std::string toString() const;					
			
			};
			
			class Result : public hydrazine::Stringable
			{
			
				public:
				
					FLOAT claimProbability;
					FLOAT defaultProbability;
					FLOAT expectedClaim;
					FLOAT expectedLoss;
					FLOAT expectedLossPercent;
					
					FLOAT maxClaim;
					FLOAT maxClaimPv;
					
				public:
				
					void merge( const Result& result );
					void clear();		
			
					std::string toString() const;
			
			};
			
			class Portfolio: public hydrazine::Stringable
			{
			
				public:
				
					unsigned int obligorId;
					unsigned int counterId;
					
					unsigned int quantity;
					FLOAT spread;
					
					Date expirationYear;
					
					FLOAT yearsToMaturity;
					FLOAT quartersToMaturity;
			
				public:
				
					std::string toString() const; 					
			
			};
			
			typedef std::map< unsigned int, Rating > RatingMap;
			typedef std::map< unsigned int, Industry >
				IndustryMap;
			typedef std::map< unsigned int, Obligor > 	
				ObligorMap;
			typedef std::map< unsigned int, Portfolio > 	
				PortfolioMap;
			typedef std::map< unsigned int, unsigned int > 	
				ReverseCounterMap;
			typedef std::set< unsigned int > IdSet;
			typedef std::deque<unsigned int> ReverseMap;
			typedef std::deque< Date > DateVector;
			typedef std::deque< unsigned int > Vector;
			typedef std::deque< Result > ResultVector;

			class SimulationData
			{
			
				public:
				
					unsigned int index;
					
					CudaMersenneTwisterData* twisters;
					unsigned int twisterSize;
					
					const SimulationParameters* parameters;
					const ObligorMap* obligors;
					const ReverseMap* obligorMap;
					const PortfolioMap* portfolios;
					
					const Vector* counterParties;
					const Vector* quarters;
					const FLOAT* correlation;
					const FLOAT* mean;
					const FLOAT* defaultProbability;
					
					ResultVector results;
					
			};
			
			class CounterCf
			{
			
				public:
					
					unsigned int index;
						
					FLOAT* income;
					FLOAT* expense;
					FLOAT* loss;
			
			};
			
			typedef std::deque< SimulationData > DataVector;
	
		private:
	
			SimulationParameters _parameters;
			
			std::string _ratingsFileName;
			std::string _industryFileName;
			std::string _portfolioFileName;
			std::string _obligorsFileName;
			std::string _twisterFileName;
			
			RatingMap _ratings;
			IndustryMap _industries;
			ObligorMap _obligors;
			ReverseMap _reverseObligors;
			PortfolioMap _portfolios;
			Vector _counterParties;
			ReverseCounterMap _reverseCounterMap;
			
			bool _initialized;
			
			DateVector _quarterDates;
			Vector _quarters;
			
			FLOAT* _correlation;
			FLOAT* _mean;
			FLOAT* _defaultProbability;
			
			CudaMersenneTwisterData* _twisters;
			unsigned int _twisterSize;
			
		private:
		
			template<typename T> 
			static T _nextCsv( std::ifstream& input );
			static void _eatDelimiters( std::ifstream& input );
			
			static void _skipLine( std::ifstream& input );
		
			static FLOAT* _identity( unsigned int size );
		
		private:
		
			static void* _simulateChunk( void* data );
						
			static void _allocateInvariantsFromData( 
				CudaInvariants*& invariants, const SimulationData& data );
			static void _copyResults( ResultVector& results, 
				const CudaResult* cudaResults );
			static void _destroyInvariants( CudaInvariants* invariants );
			static void* _simulateChunkGpu( void* data );
		
		private:
		
			void _readRatings();
			void _readIndustry();
			void _readPortfolio();
			void _readObligors();
			void _readTwisters();
		
			void _adjustPortfolios();
			void _setupObligors();
			void _createCorrelation();
			void _initMean();
			Date _computeMaxDate();
			void _computeQuarters();
			void _computeDefaultProbabilties();
			void _initCounterParties();
			
			void _runSimulation();
		
			void _handleResults( ResultVector& results );
			
			FLOAT _calculateMoodysMetric( FLOAT loss, FLOAT wal );
		
		public:
	
			CapModel3(  );
			CapModel3( const SimulationParameters& parameters );
			CapModel3( const SimulationParameters& parameters,
				const std::string& ratingsFileName,
				const std::string& industryFileName,
				const std::string& portfolioFileName,
				const std::string& obligorsFileName,
				const std::string& twistersFileName );
			~CapModel3();
			
			void parameters( const SimulationParameters& params );
			void ratings( const std::string& file );
			void industry( const std::string& file );
			void portfolio( const std::string& file );
			void obligors( const std::string& file );
			void twisters( const std::string& file );

			bool useGpu;

			const SimulationParameters& parameters() const;
			void run();
			void clear();
			
			std::string toString() const;
			
	};

}

#endif


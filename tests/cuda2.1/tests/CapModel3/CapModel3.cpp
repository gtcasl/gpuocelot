/*!

	\file CapModel3.cpp
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>

	\date Saturday December 13, 2008

	\brief The source file for the CapModel3 class.

*/

#ifndef CAP_MODEL_3_CPP_INCLUDED
#define CAP_MODEL_3_CPP_INCLUDED

#include "CapModel3.h"
#include "Exception.h"
#include "debug.h"
#include "macros.h"
#include <cstring>
#include <pthread.h>
#include <cmath>
#include <algorithm>

extern "C"
{
	
	#include "MultiVariateNormal.h"

}

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace sim
{

	std::string CapModel3::Rating::toString() const
	{
	
		std::stringstream stream;
		
		stream << "Rating " << name << "\n";
		stream << " id: " << id << "\n";
		stream << " warf: " << warf << "\n";
		
		stream << " probabilities:\n";
		for( Probabilities::const_iterator fi =  defaultProbabilities.begin(); 	
			fi != defaultProbabilities.end(); ++fi )
		{
		
			stream << "  " << *fi << "\n";
		
		}
		
		return stream.str();
	
	}

	std::string CapModel3::Industry::toString() const
	{
	
		std::stringstream stream;
		
		stream << "Industry " << name << "\n";
		stream << " id: " << id << "\n";
		stream << " region factor: " << regionFactor << "\n";
		stream << " lmh factor: " << lmhFactor << "\n";
		stream << " superSecot: " << superSector << "\n";
		
		return stream.str();
	
	}
		
	std::string CapModel3::Obligor::toString() const
	{
	
		std::stringstream stream;
		
		stream << "Obligor " << name << "\n";
		stream << " id: " << id << "\n";
		stream << " ticker: " << ticker << "\n";
		stream << " country: " << country << "\n";
		stream << " ccy: " << ccy << "\n";
		
		stream << " rating id: " << ratingId << "\n";
		stream << " industry id: " << industryId << "\n";
		
		stream << " seniority: " << seniority << "\n";
		stream << " restructuring: " << restructuring << "\n";
		stream << " cuspip: " << cuspip << "\n";
		
		stream << " five year spread: " << fiveYearSpread << "\n";
		
		return stream.str();
	
	}

	void CapModel3::Result::merge( const Result& result )
	{
	
		claimProbability += result.claimProbability;
		defaultProbability += result.defaultProbability;
		expectedClaim += result.expectedClaim;
		expectedLoss += result.expectedLoss;
		expectedLossPercent += result.expectedLossPercent;
		
		maxClaim = MAX( maxClaim, result.maxClaim );
		maxClaimPv = MAX( maxClaimPv, result.maxClaimPv );
	
	}
	
	void CapModel3::Result::clear()
	{
	
		claimProbability = 0.0;
		defaultProbability = 0.0;
		expectedClaim = 0.0;
		expectedLoss = 0.0;
		expectedLossPercent = 0.0;
		
		maxClaim = 0.0;
		maxClaimPv = 0.0;
	
	}

	std::string CapModel3::Result::toString() const
	{
	
		std::stringstream stream;
		
		stream << "Result \n";
		stream << " claim probability: " << claimProbability << "\n";
		stream << " default probability: " << defaultProbability << "\n";
		stream << " expected claim: " << expectedClaim << "\n";
		stream << " expected loss: " << expectedLoss << "\n";
		stream << " expected loss(%): " << expectedLossPercent << "\n";

		stream << " max claim: " << maxClaim << "\n";
		stream << " max claim probability: " << maxClaimPv << "\n";
	
		return stream.str();
	
	}

	std::string CapModel3::Portfolio::toString() const
	{
	
		std::stringstream stream;
		
		stream << "Portfolio\n";
		stream << " obligor id: " << obligorId << "\n";
		stream << " counter id: " << counterId << "\n";
		stream << " quantity: " << quantity << "\n";
		stream << " spread: " << spread << "\n";
		
		stream << " expiration year: " << expirationYear.toString() << "\n";
		stream << " years to maturity: " << yearsToMaturity << "\n";
		stream << " quarters to maturity: " << quartersToMaturity << "\n";
		
		return stream.str();
	
	}
	
	template<typename T> 
	T CapModel3::_nextCsv( std::ifstream& input )
	{
	
		T value = 0;
		
		// eat delimiters
		_eatDelimiters( input );
		
		// parse the next value
		std::stringstream stream;
		
		bool hitDelimiter = false;
		bool stringMode = false;
		
		while( !hitDelimiter && input.good() )
		{
		
			char next;
			input.get( next );
			
			switch( next )
			{
			
				case '\"':
				{
				
					stringMode = !stringMode;
					break;
				
				}

				case '\n':
				case ',':
				{

					if( !stringMode )
					{
					
						hitDelimiter = true;
						input.unget();
						break;
					
					}
					
				}
								
				default:
				{
					
					stream << next;
					break;
				
				}
			
			}
		
		}
		
		if( !stream.str().empty() )
		{
		
			stream >> value;
		
		}
		
		return value;
	
	}

	template<> 
	std::string CapModel3::_nextCsv<std::string>( std::ifstream& input )
	{
	
		// eat delimiters
		_eatDelimiters( input );
		
		// parse the next value
		std::stringstream stream;
		
		bool hitDelimiter = false;
		bool stringMode = false;
		
		while( !hitDelimiter && input.good() )
		{
		
			char next;
			input.get( next );
			
			switch( next )
			{
			
				case '\"':
				{
				
					stringMode = !stringMode;
					break;
				
				}

				case '\n':
				case ',':
				{

					if( !stringMode )
					{
					
						hitDelimiter = true;
						input.unget();
						break;
					
					}
					
				}
				
				default:
				{
					
					stream << next;
					break;
				
				}
			
			}
		
		}
		
		return stream.str();
	
	}

	void CapModel3::_eatDelimiters( std::ifstream& input )
	{
	
		bool hitDelimiter = true;
		
		while( hitDelimiter && input.good() )
		{
		
			char next;
			input.get( next );
			
			switch( next )
			{
			
				case ' ':
				case '\t':
				case '\n':
				case ',':
				{
				
					break;
				
				}
				
				default:
				{
				
					input.unget();
					hitDelimiter = false;
					break;
				
				}
			
			}
		
		}
			
	}

	void CapModel3::_skipLine( std::ifstream& input )
	{
	
		while( input.good() )
		{
		
			char next;
			input.get( next );
			if( next == '\n' )
			{
			
				break;
			
			}
		
		}
		
	}

	FLOAT* CapModel3::_identity( unsigned int size )
	{
	
		FLOAT* matrix = new FLOAT[size * size];
		
		for( unsigned int i = 0; i < size; ++i )
		{
		
			for( unsigned int j = 0; j < size; ++j )
			{
			
				if( i == j )
				{
				
					matrix[ i * size + j ] =  1.0;
				
				}
				else
				{
				
					matrix[ i * size + j ] =  0.0;
				
				}
			
			}
		
		}
		
		return matrix;
	
	}

	void* CapModel3::_simulateChunk( void* __data )
	{
	
		SimulationData* _data = static_cast< SimulationData* >( __data );
		SimulationData& data = static_cast< SimulationData& >( *_data );
	
		assert( data.results.size() == data.counterParties->size() + 1 );
	
		report( "Simulating chunk " << data.index );
	
		// clear results
		for( ResultVector::iterator fi = data.results.begin(); 
			fi != data.results.end(); ++fi )
		{
		
			fi->clear();
		
		}
		
		// step 2
		unsigned int size = data.obligors->size();
		unsigned int maxQuarter = data.quarters->size();
		unsigned int chunkSize = MIN( data.parameters->chunkSize, 
			data.parameters->numberOfSimulations - ( data.index ) * 
			data.parameters->chunkSize );
		
		FLOAT* correlation = new FLOAT[ size * size ];
		memcpy( correlation, data.correlation, sizeof( FLOAT ) * size * size );
		FLOAT* samples = new FLOAT[ size * chunkSize ];
		
		choleskyDecomposition( correlation, size );
		
		for( unsigned int i = 0; i < chunkSize; ++i )
		{
			
			multivariateNormal( samples + ( i * size ), data.mean, 
				correlation, size );			
			normalCdf( samples + ( i * size ), 0, 1, size );
		
		}
		
		for( unsigned int i = 0; i < chunkSize; ++i )
		{
		
			for( unsigned int j = 0; j < size; ++j )
			{

				samples[i * size + j] = 10.0 * log( samples[i * size + j] ) / 
					log( 1.0 - data.defaultProbability[j] );
				
			}
		
		}
		
		typedef std::unordered_map< unsigned int, CounterCf > 
			CounterCfVector;
		
		for( unsigned int simNumber = 0; 
			simNumber < chunkSize; ++simNumber )
		{
		
			// step 3
			CounterCfVector countercf;
			
			unsigned int counterIndex = 0;
			
			for( Vector::const_iterator fi = data.counterParties->begin(); 
				fi != data.counterParties->end(); ++fi, ++counterIndex )
			{
			
				CounterCf counter;
				
				counter.index = counterIndex;
				
				counter.income = new FLOAT[ maxQuarter ];
				memset( counter.income, 0, sizeof( FLOAT ) * maxQuarter );
				counter.expense = new FLOAT[ maxQuarter ];
				memset( counter.expense, 0, sizeof( FLOAT ) * maxQuarter );
				counter.loss = new FLOAT[ maxQuarter ];
				memset( counter.loss, 0, sizeof( FLOAT ) *
					 maxQuarter );
					 
				countercf.insert( std::make_pair( *fi, counter ) );
					
			}
			
			for( PortfolioMap::const_iterator portfolio = 
				data.portfolios->begin(); portfolio != data.portfolios->end(); 
				++portfolio )
			{
						
				FLOAT* cdsIncomeCf = new FLOAT[ maxQuarter ];
				FLOAT* cdsExpenseCf = new FLOAT[ maxQuarter ];
				
				memset( cdsIncomeCf, 0, sizeof( FLOAT ) * maxQuarter );
				memset( cdsExpenseCf, 0, sizeof( FLOAT ) * maxQuarter );
				
				for( unsigned int i = 0; 
					i < MIN( portfolio->second.quartersToMaturity + 1, 
					maxQuarter); ++i )
				{
				
					cdsIncomeCf[i] = portfolio->second.quantity * 
						portfolio->second.spread / 4.0;
				
				}
				
				assert( portfolio->second.obligorId < 
					data.obligorMap->size() );
				unsigned int obligorIndex = 
					(*data.obligorMap)[ portfolio->second.obligorId ];
				assert( obligorIndex < size );
				
				FLOAT value = samples[ simNumber * size + obligorIndex ];
				if( value < portfolio->second.yearsToMaturity )
				{
				
					unsigned int defaultQuarter = 0;
					bool found = false;
					
					for( ; defaultQuarter < data.quarters->size() - 1; 
						++defaultQuarter )
					{
					
						if( (*data.quarters)[defaultQuarter + 1] > value )
						{
						
							found = true;
							break;
						
						}
					
					}				
					
					if( !found )
					{
			
						++defaultQuarter;
			
					}
					
					for( unsigned int i = defaultQuarter; i < maxQuarter; ++i )
					{
					
						cdsIncomeCf[i] = 0.0;
					
					}
					
					cdsExpenseCf[ defaultQuarter ] = 
						portfolio->second.quantity * 
						betaDistributionFromNormal( data.parameters->lgdMean, 
						data.parameters->lgdStdev );
										
				}
				
				CounterCfVector::iterator counter = 
					countercf.find( portfolio->second.counterId );
				assert( counter != countercf.end() );
				
				if( portfolio->second.quantity > 0 )
				{
				
					for( unsigned int i = 0; i < maxQuarter; ++i )
					{
					
						counter->second.income[i] += cdsIncomeCf[i];
						counter->second.expense[i] += cdsExpenseCf[i];
					
					}
				
				}
				else
				{
				
					for( unsigned int i = 0; i < maxQuarter; ++i )
					{
					
						counter->second.income[i] -= cdsExpenseCf[i];
						counter->second.expense[i] -= cdsIncomeCf[i];
					
					}
				
				}
				
				delete[] cdsIncomeCf;
				delete[] cdsExpenseCf;
			
			}
			
			for( CounterCfVector::iterator fi = countercf.begin(); 
				fi != countercf.end(); ++fi )
			{
			
				unsigned int defaultQuarter = 0;
				FLOAT value = samples[ simNumber * size + 
					( fi->second.index ) ];
				bool found = false;
				
				for( ; defaultQuarter < maxQuarter - 1; 
					++defaultQuarter )
				{
				
					if( (*data.quarters)[defaultQuarter + 1] > value )
					{
					
						found = true;
						break;
					
					}
				
				}
				
				if( !found )
				{
				
					++defaultQuarter;
				
				}
				
				for( unsigned int i = defaultQuarter; i < maxQuarter; ++i )
				{
				
					fi->second.income[i] = 0.0;
				
				}

				#if 0

				std::stringstream stream;
				
				stream << " " << fi->first << " income:  ";
				
				for( unsigned int i = 0; i < maxQuarter; ++i )
				{
				

					stream << fi->second.income[i] << " ";
				
				}
				
				report( stream.str() );
				
				std::stringstream stream1;
				
				stream1 << " " << fi->first << " expense:  ";
				
				for( unsigned int i = 0; i < maxQuarter; ++i )
				{
				

					stream1 << fi->second.expense[i] << " ";
				
				}
				
				report( stream1.str() );
				
				#endif
						
			}
			
			// step 4
			
			FLOAT* marketPrice = new FLOAT[ maxQuarter ];
			FLOAT* coupons = new FLOAT[ maxQuarter ];
			FLOAT* discount = new FLOAT[ maxQuarter ];
			
			for( unsigned int i = 0; i < maxQuarter; ++i )
			{
			
				marketPrice[i] = 1.0;
				coupons[i] = data.parameters->investRate / 4.0;
				discount[i] = 1.0 / pow( ( 1 + data.parameters->investRate 
					/ 4.0 ), ( 1 + i ) );
			
			}
			
			// step 5
			FLOAT capital = data.parameters->initialEquity + 
				data.parameters->debtParameter;
			
			FLOAT* capitalBalance = new FLOAT[ maxQuarter ];
			FLOAT* premium = new FLOAT[ maxQuarter ];
			FLOAT* investIncrement = new FLOAT[ maxQuarter ];
			FLOAT* income = new FLOAT[ maxQuarter ];
			
			FLOAT* claims = new FLOAT[ maxQuarter ];
			
			FLOAT* paid = new FLOAT[ maxQuarter ];
			FLOAT* operatingExpense = new FLOAT[ maxQuarter ];
			FLOAT* debtService = new FLOAT[ maxQuarter ];
			FLOAT* managementFee = new FLOAT[ maxQuarter ];
			FLOAT* expense = new FLOAT[ maxQuarter ];
			
			FLOAT* loss = new FLOAT[ maxQuarter ];
			FLOAT* debtLoss = new FLOAT[ maxQuarter ];
			
			memset( capitalBalance, 0, sizeof( FLOAT ) * maxQuarter );
			memset( premium, 0, sizeof( FLOAT ) * maxQuarter );
			memset( investIncrement, 0, sizeof( FLOAT ) * maxQuarter );
			memset( income, 0, sizeof( FLOAT ) * maxQuarter );
			memset( claims, 0, sizeof( FLOAT ) * maxQuarter );
			memset( paid, 0, sizeof( FLOAT ) * maxQuarter );
			memset( debtService, 0, sizeof( FLOAT ) * maxQuarter );
			memset( expense, 0, sizeof( FLOAT ) * maxQuarter );
			memset( loss, 0, sizeof( FLOAT ) * maxQuarter );
			memset( debtLoss, 0, sizeof( FLOAT ) * maxQuarter );
			memset( managementFee, 0, sizeof( FLOAT ) * maxQuarter );
			
			for( unsigned int i = 0; i < maxQuarter; ++i )
			{
			
				operatingExpense[i] = ( data.parameters->optionExpense / 4.0 ) 
					* pow( ( 1.0 + data.parameters->optionInflation/4.0 ), 
					i + 1 );
			
			}
			
			bool inRunOff = false;
			
			for( unsigned int quarter = 0; quarter < maxQuarter; ++quarter )
			{
			
				// premium and recoveries
				for( CounterCfVector::iterator fi = countercf.begin(); 
				fi != countercf.end(); ++fi )
				{
			
					premium[ quarter ] += fi->second.income[ quarter ];
			
				}
				
				// investment income
				investIncrement[ quarter ] = MAX( 0.0, capital * 
					coupons[ quarter ] / marketPrice[ quarter ] );
					
				// total income
				income[ quarter ] += premium[ quarter ] + 
					investIncrement[ quarter ];
				capital += income[ quarter ];
			
				// 1st claims
				for( CounterCfVector::iterator fi = countercf.begin(); 
					fi != countercf.end(); ++fi )
				{
			
					claims[ quarter ] += fi->second.expense[ quarter ];
			
				}
				
				paid[ quarter ] = MIN( capital, claims[ quarter ] );
				capital -= paid[ quarter ];
				expense[ quarter ] += paid[ quarter ];
				
				if( paid[ quarter ] < claims[ quarter ] )
				{
				
					inRunOff = true;
					
					for( CounterCfVector::iterator fi = countercf.begin(); 
						fi != countercf.end(); ++fi )
					{
			
						if( fi->second.expense[ quarter ] > 0 )
						{
						
							for( unsigned int i = quarter + 1; i < maxQuarter; 
								++i )
							{
							
								fi->second.income[i] = 0;
							
							}
						
						}
			
					}
					
					loss[ quarter ] = claims[ quarter ] - paid[ quarter ];
					FLOAT percentPaid = paid[ quarter ] / claims[ quarter ];
				
					for( CounterCfVector::iterator fi = countercf.begin(); 
						fi != countercf.end(); ++fi )
					{
					
						fi->second.loss[ quarter ] = 
							fi->second.expense[ quarter ] * 
							( 1.0 - percentPaid );
					
					}
				
				}
				
				// debt service
				debtService[ quarter ] = data.parameters->debtParameter * 
					data.parameters->debtRate;
				debtService[ quarter ] = MAX( 0, MIN( debtService[ quarter ], 
					capital ) );
				capital -= debtService[ quarter ];
				expense[ quarter ] += debtService[ quarter ];
				
				if( capital < data.parameters->debtParameter )
				{
				
					debtLoss[quarter] = MAX( 0, data.parameters->debtParameter 
						- capital );
				
				}
				
				// operating expenses
				operatingExpense[ quarter ] = MIN( operatingExpense[ quarter ], 
					MAX( capital, 0 ) );
				capital -= operatingExpense[ quarter ];
				expense[ quarter ] += operatingExpense[ quarter ];
				
				// management fee
				if( !inRunOff )
				{
				
					FLOAT assetBase;
				
					if( quarter == 0 )
					{
					
						assetBase = data.parameters->initialEquity + 
							data.parameters->debtParameter;
					
					}
					else
					{
					
						assetBase = capitalBalance[ quarter - 1 ];
					
					}
					
					FLOAT assetFee = 0.25 * 
						data.parameters->assetManagementFeeRate * assetBase;
						
					FLOAT sum = 0;
					
					for( PortfolioMap::const_iterator portfolio = 
						data.portfolios->begin(); 
						portfolio != data.portfolios->end(); 
						++portfolio )
					{
					
						sum += portfolio->second.quantity;
					
					}
					
					managementFee[quarter] = MIN( MAX( capital, 0 ), assetFee + 
						MIN( 0.25 * data.parameters->managementFeeRate * sum, 
						0.25 * data.parameters->managementFeeCap ) );
										
				}
				
				capital -= managementFee[ quarter ];
				expense[ quarter ] += managementFee[ quarter ];
				capitalBalance[ quarter ] = capital;
				capital = MAX( capital, 0 );
			
			}
			
			// step 6
			
			unsigned int counterSize = data.counterParties->size();
			
			for( CounterCfVector::iterator fi = countercf.begin(); 
				fi != countercf.end(); ++fi )
			{
			
				CounterCf& v = fi->second;
				Result& r = data.results[v.index];
				
				FLOAT pvClaim = 0;
				FLOAT pvLoss = 0;
				FLOAT cpClaim = 0;
				FLOAT cpLoss = 0;
				
				for( unsigned int i = 0; i < maxQuarter; ++i )
				{
				
					pvClaim += v.expense[i] * discount[i];
					pvLoss += v.loss[i] * discount[i];
					cpClaim += v.expense[i];
					cpLoss += v.loss[i];
				
				}
								
				if( pvClaim > 0 )
				{
				
					
					r.claimProbability += 1;
					r.expectedClaim += pvClaim;
					r.maxClaim = MAX( r.maxClaim, cpClaim );
					r.maxClaimPv = MAX( r.maxClaimPv, pvClaim );
					
					if( pvLoss > 0 )
					{
					
						r.defaultProbability += 1;
						r.expectedClaim += pvLoss;
						r.expectedLossPercent += ( pvLoss / pvClaim );
					
					}
					
				}
			
			}
			
			FLOAT pvClaim = 0;
			FLOAT pvLoss = 0;
			FLOAT cpClaim = 0;
			FLOAT cpLoss = 0;
			
			for( unsigned int i = 0; i < maxQuarter; ++i )
			{
			
				pvClaim += claims[i] * discount[i];
				pvLoss += loss[i] * discount[i];
				cpClaim += claims[i];
				cpLoss += loss[i];
			
			}
			
			Result& r = data.results[counterSize];
			
			if( pvClaim > 0 )
			{
			
				r.claimProbability += 1;
				r.expectedClaim += pvClaim;
				r.maxClaim = MAX( r.maxClaim, cpClaim );
				r.maxClaimPv = MAX( r.maxClaimPv, pvClaim );
				
				if( pvLoss > 0 )
				{
				
					r.defaultProbability += 1;
					r.expectedClaim += pvLoss;
					r.expectedLossPercent += ( pvLoss / pvClaim );
				
				}
				
			}
			
			// clean up
			
			for( CounterCfVector::iterator fi = countercf.begin(); 
				fi != countercf.end(); ++fi )
			{
			
				delete[] fi->second.income;
				delete[] fi->second.expense;
				delete[] fi->second.loss;
							
			}
			
			delete[] marketPrice;
			delete[] coupons;
			delete[] discount;
			
			delete[] capitalBalance;
			delete[] premium;
			delete[] investIncrement;
			delete[] income;

			delete[] claims;

			delete[] paid;
			delete[] operatingExpense;
			delete[] debtService;
			delete[] managementFee;
			delete[] expense;

			delete[] loss;
			delete[] debtLoss;
		
		}
	
		report( " Done" );
	
		delete[] correlation;
		delete[] samples;
		
		return 0;
	
	}

	void CapModel3::_allocateInvariantsFromData( 
		CudaInvariants*& invariants, const SimulationData& data )
	{
	
		invariants = new CudaInvariants;
		
		// device config
		
		invariants->device = data.index;
		invariants->seed = data.parameters->chunkSize * data.index;
		
		// twisters
		invariants->twisters = data.twisters;
		invariants->maxTwisters = data.twisterSize;
		
		// parameters
		invariants->parameters = new CudaSimulationParameters;
		
		invariants->parameters->numberOfSimulations = 
			data.parameters->numberOfSimulations;
		invariants->parameters->chunkSize = 
			data.parameters->chunkSize;
		invariants->parameters->investRate = 
			data.parameters->investRate;
		invariants->parameters->initialEquity = 
			data.parameters->initialEquity;
		invariants->parameters->debtParameter = 
			data.parameters->debtParameter;
		invariants->parameters->debtRate = 
			data.parameters->debtRate;
		invariants->parameters->optionExpense = 
			data.parameters->optionExpense;
		invariants->parameters->optionInflation = 
			data.parameters->optionInflation;
		invariants->parameters->managementFeeRate = 
			data.parameters->managementFeeRate;
		invariants->parameters->assetManagementFeeRate = 
			data.parameters->assetManagementFeeRate;
		invariants->parameters->managementFeeCap = 
			data.parameters->managementFeeCap;
		invariants->parameters->targetPointSpread = 
			data.parameters->targetPointSpread;
		invariants->parameters->lgdMean = 
			data.parameters->lgdMean;
		invariants->parameters->lgdStdev = 
			data.parameters->lgdStdev;
		
		//obligors
		invariants->obligorSize = data.obligors->size();
		invariants->obligors = new CudaObligor[ invariants->obligorSize ];
		
		typedef std::unordered_map< unsigned int, unsigned int > IdMap;
		
		IdMap obligorIds;
		IdMap counterIds;
		
		unsigned int index = 0;
		
		for( ObligorMap::const_iterator fi = data.obligors->begin(); 
			fi != data.obligors->end(); ++fi, ++index )
		{
		
			invariants->obligors[index].id = index;
			obligorIds.insert( std::make_pair( fi->first, index ) );
			invariants->obligors[index].ratingId = fi->second.ratingId;
			invariants->obligors[index].industryId = fi->second.industryId;
			invariants->obligors[index].fiveYearSpread = 
				fi->second.fiveYearSpread;
					
		}
		
		assert( index == data.obligors->size() );
		
		// counter parties
		invariants->counterPartySize = data.counterParties->size();
		
		index = 0;
		for( Vector::const_iterator fi = data.counterParties->begin(); 
			fi != data.counterParties->end(); ++fi, ++index )
		{
		
			counterIds.insert( std::make_pair( *fi, index ) );
		
		}
		
		assert( index == data.counterParties->size() );
		
		//portfolios
		invariants->portfolioSize = data.portfolios->size();
		invariants->portfolios = new CudaPortfolio[ invariants->portfolioSize ];
		
		index = 0;
		for( PortfolioMap::const_iterator fi = data.portfolios->begin(); 
			fi != data.portfolios->end(); ++fi, ++index )
		{
		
			IdMap::iterator obligor = obligorIds.find( fi->second.obligorId );
			assert( obligor != obligorIds.end() );
		
			invariants->portfolios[index].obligorId = obligor->second;

			IdMap::iterator counter = counterIds.find( fi->second.counterId );
			assert( counter != counterIds.end() );
		
			invariants->portfolios[index].counterId = counter->second;
			
			invariants->portfolios[index].quantity = fi->second.quantity;
			invariants->portfolios[index].spread = fi->second.spread;
			invariants->portfolios[index].yearsToMaturity = 
				fi->second.yearsToMaturity;
			invariants->portfolios[index].quartersToMaturity = 
				fi->second.quartersToMaturity;

		}
		
		assert( index == data.portfolios->size() );
		
		// quarters
		invariants->quarterSize = data.quarters->size();
		invariants->quarters = new unsigned int[ invariants->quarterSize ];
		
		for( unsigned int i = 0; i < invariants->quarterSize; ++i )
		{
		
			invariants->quarters[i] = (*data.quarters)[i];
		
		}
		
		// statistics
		invariants->mean = new FLOAT[ invariants->obligorSize ];
		invariants->defaultProbability = new FLOAT[ invariants->obligorSize ];
		invariants->correlation = new FLOAT[ invariants->obligorSize * 
			invariants->obligorSize ];
			
		for( unsigned int i = 0; i < invariants->obligorSize; ++i )
		{
		
			invariants->mean[i] = data.mean[i];
			invariants->defaultProbability[i] = data.defaultProbability[i];
			
			for( unsigned int j = 0; j < invariants->obligorSize; ++j )
			{
		
				invariants->correlation[ i * invariants->obligorSize + j ] = 
					data.correlation[ i * invariants->obligorSize + j ];
		
			}
		
		}
		
		// compute cholesky
		choleskyDecomposition( invariants->correlation, 
			invariants->obligorSize );
		
	}
	
	void CapModel3::_copyResults( ResultVector& results, 
		const CudaResult* cudaResults )
	{
	
		unsigned int size = results.size();
		
		for( unsigned int i = 0; i < size; ++i )
		{
		
			results[i].claimProbability = cudaResults[i].claimProbability;
			results[i].defaultProbability = cudaResults[i].defaultProbability;
			results[i].expectedClaim = cudaResults[i].expectedClaim;
			results[i].expectedLoss = cudaResults[i].expectedLoss;
			results[i].expectedLossPercent = cudaResults[i].expectedLossPercent;

			results[i].maxClaim = cudaResults[i].maxClaim;
			results[i].maxClaimPv = cudaResults[i].maxClaimPv;
		
		}
	
	}

	void CapModel3::_destroyInvariants( CudaInvariants* invariants )
	{
	
		delete invariants->parameters;
		
		delete[] invariants->obligors;
		delete[] invariants->portfolios;
		delete[] invariants->quarters;
		delete[] invariants->mean;
		delete[] invariants->correlation;
		delete[] invariants->defaultProbability;
		
		delete invariants;
	
	}
	
	
	void* CapModel3::_simulateChunkGpu( void* __data )
	{
	
		SimulationData* _data = static_cast< SimulationData* >( __data );
		SimulationData& data = static_cast< SimulationData& >( *_data );
	
		assert( data.results.size() == data.counterParties->size() + 1 );
	
		report( "Simulating chunk " << data.index << " on GPU." );
		
		CudaInvariants* cudaInvariants;
		CudaResult* cudaResults = new CudaResult[ data.results.size() ];
		
		_allocateInvariantsFromData( cudaInvariants, data );
		
		capModel3Cuda( cudaInvariants, cudaResults );
		
		_copyResults( data.results, cudaResults );
		
		_destroyInvariants( cudaInvariants );
		
		delete[] cudaResults;
		
		return 0;
	
	}

	void CapModel3::_readRatings()
	{
	
		report( "Reading in ratings file " << _ratingsFileName );
	
		std::ifstream file( _ratingsFileName.c_str() );
		
		if( !file.is_open() )
		{
		
			throw hydrazine::Exception( "Could not open ratings file " 
				+ _ratingsFileName );
		
		}
		
		while( file.good() )
		{
		
			// skip comments
			if( file.peek() == '#' )
			{
			
				_skipLine( file );
				continue;
				
			}
			
			Rating rating;
			
			rating.id = _nextCsv<unsigned int>( file );
			rating.name = _nextCsv<std::string>( file );
			
			while( file.good() )
			{
			
				if( file.peek() == '\n' )
				{
				
					break;
				
				}
			
				rating.defaultProbabilities.push_back( 
					_nextCsv<FLOAT>( file ) );
			
			}

			if( !file.good() )
			{
			
				break;
			
			}	
			
			rating.warf = rating.defaultProbabilities.back() * 10000;
			
			_ratings.insert( std::make_pair( rating.id, rating ) );
		
		}
		
		file.close();
	
	}

	void CapModel3::_readIndustry()
	{

		report( "Reading in industry file " << _industryFileName );
	
		std::ifstream file( _industryFileName.c_str() );
		
		if( !file.is_open() )
		{
		
			throw hydrazine::Exception( "Could not open industry file " 
				+ _industryFileName );
		
		}
		
		while( file.good() )
		{
		
			// skip comments
			if( file.peek() == '#' )
			{
			
				_skipLine( file );
				continue;
				
			}
			
			Industry industry;
			
			industry.id = _nextCsv<unsigned int>( file );	
			industry.name = _nextCsv<std::string>( file );
			industry.regionFactor = _nextCsv<std::string>( file );
			industry.lmhFactor = _nextCsv<std::string>( file );
			industry.superSector = _nextCsv<std::string>( file );
		
			if( !file.good() )
			{
			
				break;
			
			}	
			
			_industries.insert( std::make_pair( industry.id, industry ) );
		
		}
		
		file.close();
		
	}
	
	void CapModel3::_readObligors()
	{
	
		std::ifstream file( _obligorsFileName.c_str() );

		report( "Reading in obligors file " << _obligorsFileName );
		
		if( !file.is_open() )
		{
		
			throw hydrazine::Exception( "Could not open obligors file " 
				+ _obligorsFileName );
		
		}
		
		while( file.good() )
		{
		
			// skip comments
			if( file.peek() == '#' )
			{
			
				_skipLine( file );
				continue;
				
			}
			
			Obligor obligor;
			
			obligor.id = _nextCsv<unsigned int>( file );
			
			obligor.ticker = _nextCsv<std::string>( file );
			obligor.name = _nextCsv<std::string>( file );
			obligor.country = _nextCsv<std::string>( file );
			obligor.ccy = _nextCsv<std::string>( file );
			
			obligor.ratingId = _nextCsv<unsigned int>( file );
			obligor.industryId = _nextCsv<unsigned int>( file );
			
			obligor.seniority = _nextCsv<std::string>( file );
			obligor.restructuring = _nextCsv<std::string>( file );
			obligor.cuspip = _nextCsv<std::string>( file );
			
			obligor.fiveYearSpread = _nextCsv<unsigned int>( file );

			if( !file.good() )
			{
			
				break;
			
			}	
			
			_obligors.insert( std::make_pair( obligor.id, obligor ) );
		
		}
		
		file.close();
	
	}

	void CapModel3::_readPortfolio()
	{
	
		std::ifstream file( _portfolioFileName.c_str() );

		report( "Reading in portfolio file " << _portfolioFileName );
		
		if( !file.is_open() )
		{
		
			throw hydrazine::Exception( "Could not open portfolio file " 
				+ _portfolioFileName );
		
		}
		
		while( file.good() )
		{
		
			// skip comments
			if( file.peek() == '#' )
			{
			
				_skipLine( file );
				continue;
				
			}
			
			Portfolio portfolio;
			
			portfolio.obligorId = _nextCsv<unsigned int>( file );
			portfolio.quantity = _nextCsv<unsigned int>( file );

			portfolio.counterId = _nextCsv<unsigned int>( file );			
			portfolio.spread = _nextCsv<unsigned int>( file ) / 10000.0;
			
			if( !file.good() )
			{
			
				break;
			
			}

			portfolio.expirationYear = _nextCsv<std::string>( file );

			if( _parameters.date < portfolio.expirationYear )
			{
			
				portfolio.yearsToMaturity = ( portfolio.expirationYear - 
					_parameters.date ).value() / ( 365.25 );
				
				Date quarterCounter = _parameters.date;
				
				unsigned int count = 1;
				for( unsigned int i = 0; i < 24; ++i )
				{
				
					Date next = quarterCounter;
					next.addMonths( 3 );	
				
					if( portfolio.expirationYear < next )
					{
					
						break;
					
					}
					else
					{
					
						quarterCounter = next;
						++count;
					
					}
				
				}
				
				portfolio.quartersToMaturity = count;
			
				_portfolios.insert( std::make_pair( portfolio.obligorId, 
					portfolio ) );
			
			}
		
		}
		
		file.close();
	
	}
	
	void CapModel3::_readTwisters()
	{
	
		std::ifstream file( _twisterFileName.c_str(), std::ios::binary );

		report( "Reading in twisters file " << _twisterFileName );
		
		if( !file.is_open() )
		{
		
			throw hydrazine::Exception( "Could not open twister file " 
				+ _twisterFileName );
		
		}
		
		// get the file length in bytes
		file.seekg( 0, std::ios::end );
		unsigned int bytes = file.tellg();
		file.seekg( 0, std::ios::beg );
		
		// create twisters
		assert( _twisters == 0 );
		assert( _twisterSize == 0 );
		assert( bytes % sizeof( CudaMersenneTwisterData ) == 0 );
		
		_twisterSize = bytes / sizeof( CudaMersenneTwisterData );
		_twisters = new CudaMersenneTwisterData[ _twisterSize ];
		
		file.read( (char*) _twisters, bytes );
		
		file.close();
		
		report( " Successfulyy read " << _twisterSize 
			<< " mersenne twister parameter sets." );
	
	}

	void CapModel3::_adjustPortfolios()
	{
	
		if( _parameters.targetPointSpread > 0 )
		{
		
			FLOAT was = 0.0;
			FLOAT notational = 0.0;
			
			for( PortfolioMap::iterator fi = _portfolios.begin(); 
				fi != _portfolios.end(); ++fi )
			{
			
				notational += fi->second.quantity;
				was += fi->second.quantity * fi->second.spread;
			
			}
			
			was /= notational;
			
			FLOAT adjustment = ( _parameters.targetPointSpread / 10000.0 ) 
				/ was;
		
			for( PortfolioMap::iterator fi = _portfolios.begin(); 
				fi != _portfolios.end(); ++fi )
			{
			
				fi->second.spread *= adjustment;
			
			}
		
		}
	
	}

	void CapModel3::_setupObligors()
	{

		IdSet ids;
		
		// create a set of obligors referenced by portfolios
		for( PortfolioMap::iterator fi = _portfolios.begin(); 
			fi != _portfolios.end(); ++fi )
		{
		
			ids.insert( fi->second.obligorId );
			ids.insert( fi->second.counterId );
		
		}
		
		// delete all obligors not in the set
		unsigned int index = 0;
		
		for( ObligorMap::iterator fi = _obligors.begin(); 
			fi != _obligors.end(); )
		{
		
			IdSet::iterator ii = ids.find( fi->second.id );
			
			if( ii == ids.end() )
			{
			
				ObligorMap::iterator oi = fi;
				++oi;
				report( "Removing obligor " << fi->second.toString() );
				_obligors.erase( fi );
				fi = oi;
			
			}
			else
			{
			
				_reverseObligors.push_back( fi->second.id );
				fi->second.index = index++;
				++fi;
			
			}
		
		}
		
		_createCorrelation();
		_initMean();
		
	}
	
	void CapModel3::_createCorrelation()
	{
	
		// create correlation matrix
		assert( _correlation == 0 );
		_correlation = _identity( _reverseObligors.size() );
		
		for( ReverseMap::iterator fi = _reverseObligors.begin(); 
			fi != _reverseObligors.end(); ++fi )
		{
		
			ObligorMap::iterator obligor = _obligors.find( *fi );
			assert( obligor != _obligors.end() );
			
			IndustryMap::iterator industry = 
				_industries.find( obligor->second.industryId );
			assert( industry != _industries.end() );
			
			unsigned int i = fi - _reverseObligors.begin();
			
			for( unsigned int j = 0; j < i; ++j )
			{
			
				ObligorMap::iterator obligorCol = 
					_obligors.find( _reverseObligors[ j ] );
				assert( obligorCol != _obligors.end() );
				
				IndustryMap::iterator industryCol = 
					_industries.find( obligorCol->second.industryId );
				assert( industryCol != _industries.end() );
				
				FLOAT pairCorrelation;
				
				if( industry->second.superSector != 
					industryCol->second.superSector )
				{
				
					pairCorrelation = 0.01;
				
				}
				else if( industry != industryCol )
				{
				
					pairCorrelation = 0.03;
				
				}
				else if( obligor->second.country != obligorCol->second.country )
				{
				
					if( industry->second.regionFactor == "LOCAL" )
					{
					
						pairCorrelation = 0.03;
					
					}
					else if( industry->second.regionFactor == "GLOBAL" )
					{
					
						pairCorrelation = 0.09;
					
					}
					else 
					{
					
						pairCorrelation = 0.06;
					
					}
				
				}
				else 
				{
				
					if( industry->second.lmhFactor == "LOW" )
					{
					
						pairCorrelation = 0.10;
					
					}
					else if( industry->second.lmhFactor == "HIGH" )
					{
					
						pairCorrelation = 0.20;
					
					}
					else 
					{
					
						pairCorrelation = 0.15;
					
					}
				
				}
				
				_correlation[ i * _reverseObligors.size() + j ] =  
					pairCorrelation;
				_correlation[ j * _reverseObligors.size() + i ] =  
					pairCorrelation;
			
			}
		
		}
	
	}
	
	void CapModel3::_initMean()
	{
	
		assert( _mean == 0 );
		unsigned int size = _reverseObligors.size();
	
		_mean = new FLOAT[size];
		
		for( unsigned int i = 0; i < size; ++i )
		{
		
			_mean[ i ] = 0.0;
			
		}
	
	}
	
	Date CapModel3::_computeMaxDate()
	{
	
		Date maxDate;
	
		maxDate.value( 0 );
		
		for( PortfolioMap::iterator fi = _portfolios.begin(); 
			fi != _portfolios.end(); ++fi )
		{
		
			if( maxDate < fi->second.expirationYear )
			{
			
				maxDate = fi->second.expirationYear;
			
			}
		
		}
		
		return maxDate;
	
	}
	
	void CapModel3::_computeQuarters()
	{
	
		Date max = _computeMaxDate();
		Date date = _parameters.date;
		
		while( date < max )
		{
		
			date.addMonths(3);
			Date::Day days = date.value() - _parameters.date.value();
			Date::Year years = (Date::Year) ( days / 365.25 );
			_quarters.push_back( years );
			_quarterDates.push_back( date );
		
		}
	
	}
	
	void CapModel3::_computeDefaultProbabilties()
	{
	
		assert( _defaultProbability == 0 );
	
		_defaultProbability = new FLOAT[ _obligors.size() ];
		unsigned int index = 0;
	
		for( ObligorMap::iterator fi = _obligors.begin(); 
			fi != _obligors.end(); ++fi, ++index )
		{
		
			RatingMap::iterator rating = _ratings.find( fi->second.ratingId );
			assert( rating != _ratings.end() );
			_defaultProbability[index] = rating->second.warf / 10000.0;
		
		}
	
	}

	void CapModel3::_initCounterParties()
	{
	
		IdSet ids;
	
		for( PortfolioMap::iterator fi = _portfolios.begin(); 
			fi != _portfolios.end(); ++fi )
		{
		
			ids.insert( fi->second.counterId );
		
		}
		
		for( IdSet::iterator fi = ids.begin(); fi != ids.end(); ++fi )
		{
		
			assert( _reverseCounterMap.count( *fi ) == 0 );
			_reverseCounterMap.insert( 
				std::make_pair( *fi, _counterParties.size() ) );
			_counterParties.push_back( *fi );		
		
		}
			
	}
	
	void CapModel3::_runSimulation()
	{
	
		unsigned int chunks = CEIL_DIV( _parameters.numberOfSimulations, 
			_parameters.chunkSize );
		
		DataVector data( chunks );
		ResultVector results( _counterParties.size() + 1 );
		
		for( ResultVector::iterator ri = results.begin(); 
			ri != results.end(); ++ri )
		{
		
			ri->clear();
		
		}
		
		report( "Simulating " << chunks << " chunks of size " 
			<< _parameters.chunkSize );
		
		// TODO replace with parallel gpu code
		for( DataVector::iterator fi = data.begin(); fi != data.end(); ++fi )
		{
		
			fi->index = fi - data.begin();
			fi->parameters = &_parameters;
			fi->obligors = &_obligors;
			fi->portfolios = &_portfolios;
			fi->counterParties = &_counterParties;
			fi->quarters = &_quarters;
			fi->obligorMap = &_reverseObligors;
			
			fi->correlation = _correlation;
			fi->mean = _mean;
			fi->defaultProbability = _defaultProbability;
			
			fi->twisters = _twisters;
			fi->twisterSize = _twisterSize;
			
			fi->results.resize( _counterParties.size() + 1 );
			
			if( useGpu )
			{
			
				_simulateChunkGpu( &(*fi) );
	
			}
			else
			{
			
				_simulateChunk( &(*fi) );
			
			}
		
		}
		
		// merge results		
		for( DataVector::iterator fi = data.begin(); fi != data.end(); ++fi )
		{
		
			for( ResultVector::iterator ri = results.begin(), 
				fri = fi->results.begin(); ri != results.end() && 
				fri != fi->results.end(); ++ri, ++fri )
			{
	
				ri->merge( *fri );
				
			}
			
		}
		
		_handleResults( results );
		
	}
	
	void CapModel3::_handleResults( ResultVector& results )
	{
	
		assert( results.size() == ( _counterParties.size() + 1 ) );
	
		for( ResultVector::iterator fi = results.begin(); 
			fi != results.end(); ++fi )
		{
				
			fi->claimProbability /= _parameters.numberOfSimulations;
			fi->defaultProbability /= _parameters.numberOfSimulations;
			fi->expectedClaim /= _parameters.numberOfSimulations;
			fi->expectedLoss /= _parameters.numberOfSimulations;
			fi->expectedLossPercent /= _parameters.numberOfSimulations;
		
		}
		
		typedef std::deque< FLOAT > FloatVector;
	
		std::cout << "Simulation Results\n\n";
		
		assert( results.size() > 1 );
		
		FloatVector notional( results.size(), 0 );
		FloatVector was( results.size(), 0 );
		FloatVector wal( results.size(), 0 );
		FloatVector warf( results.size(), 0 );
		Vector positionCount( results.size(), 0 );
		
		for( PortfolioMap::iterator fi = _portfolios.begin(); 
			fi != _portfolios.end(); ++fi )
		{
			
			ReverseCounterMap::iterator ri = 
				_reverseCounterMap.find( fi->second.counterId );
			assert( ri != _reverseCounterMap.end() );
			
			++positionCount[ ri->second ];
			notional[ ri->second ] += fi->second.quantity;
			was[ ri->second ] += fi->second.quantity * fi->second.spread;
			wal[ ri->second ] += fi->second.quantity * 
				fi->second.yearsToMaturity;
			
			ObligorMap::iterator obligor = 
				_obligors.find( fi->second.obligorId );
			assert( obligor != _obligors.end() );
			
			RatingMap::iterator rating = 
				_ratings.find( obligor->second.ratingId );
			assert( rating != _ratings.end() );
		
			warf[ ri->second ] += fi->second.quantity * rating->second.warf;
		
		}
		
		// compute the total sum
		unsigned int size = results.size() - 1;
		
		for( unsigned int i = 0; i < size; ++i )
		{
		
			positionCount.back() += positionCount[i];
			notional.back() += notional[i];
			was.back() += was[i];
			wal.back() += wal[i];
			warf.back() += warf[i];
		
		}
		
		// divide by corresponding notional
		for( unsigned int i = 0; i < size + 1; ++i )
		{
		
			was[i] /= notional[i];
			wal[i] /= notional[i];
			warf[i] /= notional[i];
		
		}
		
		Obligor portfolio;
		
		portfolio.id = 0;
		portfolio.ticker = "Portfolio";
		portfolio.name = "Portfolio";
		portfolio.country = "United States";
		portfolio.ccy = "USD";
		portfolio.ratingId = 1;
		portfolio.industryId = 14;
		portfolio.seniority = "";
		portfolio.restructuring = "";
		portfolio.cuspip = "";
		portfolio.fiveYearSpread = 0;
		
		_obligors.insert( std::make_pair( 0, portfolio ) );
		_counterParties.push_back( 0 );
		
		std::cout << "\n\n";
		std::cout << "Num sims:     " << _parameters.numberOfSimulations 
			<< "\n";
		std::cout << "Equity:       " << _parameters.initialEquity << "\n";
		std::cout << "Target Spread:" << _parameters.targetPointSpread << "\n";
		std::cout << "\n\n";
		
		std::cout << "id obid counterparty           cnt  not    was  warf  ";
		std::cout << "wal        EL%      ELC%      ELD%       DProb       EL";
		std::cout << "       LGD        Cprob       EC       CGC    ";
		std::cout << "max_claim max_claim(pv)     MM \n";
		
		std::cout << "-- ---- --------------------   --- ----- ------ ---- ";
		std::cout << "-----   --------- --------- ---------   --------- ";
		std::cout << "--------- ---------   --------- --------- --------- ";
		std::cout << "--------- ---------       -----\n";
		
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		
		for( unsigned int i = 0; i < size + 1; ++i )
		{
		
			std::cout.width( 2 );
			std::cout << i << " ";
			std::cout.width( 4 );
			std::cout << _counterParties[i] << " ";
			
			ObligorMap::iterator obligor = _obligors.find( _counterParties[i] );
			assert( obligor != _obligors.end() );
			
			std::cout.setf(std::ios::left, std::ios::adjustfield);
			std::cout.width( 20 );
			if( obligor->second.name.size() > 20 )
			{
				
				obligor->second.name.resize( 20 );
			
			}
			else
			{
			
				obligor->second.name.append( 20 - obligor->second.name.size(),
					 ' ' );
			
			}

			std::cout << obligor->second.name << "   ";
			
			std::cout.setf(std::ios::right, std::ios::adjustfield);
			std::cout.width( 3 );
			std::cout.precision( 0 );
			std::cout << positionCount[i] << " ";
			std::cout.width( 5 );
			std::cout << ( notional[i] / 1000 ) << " ";
			std::cout.precision( 2 );
			std::cout.width( 6 );
			std::cout << ( was[i] * 10000.0 ) << " ";
			std::cout.width( 4 );
			std::cout << (unsigned int)warf[i] << " ";
			std::cout.width( 5 );
			std::cout.precision( 2 );
			std::cout << wal[i] << "   ";
			
			std::cout.width( 8 );
			std::cout.precision( 5 );
			std::cout << results[i].expectedLossPercent << "% ";
			std::cout.width( 8 );
			std::cout.precision( 5 );
			std::cout << ( results[i].expectedLossPercent / ( MAX( 
				results[i].claimProbability, 0.0000001 ) ) ) << "% ";
			std::cout.width( 8 );
			std::cout.precision( 5 );
			std::cout << ( results[i].expectedLossPercent / ( MAX( 
				results[i].defaultProbability, 0.0000001 ) ) ) << "%   ";
			
			std::cout.width( 8 );
			std::cout.precision( 5 );
			std::cout << ( 100.0 * results[i].defaultProbability ) << "% ";
			std::cout.width( 9 );
			std::cout.precision( 3 );
			std::cout << results[i].expectedLoss << " ";
			std::cout.width( 9 );
			std::cout.precision( 3 );
			std::cout << ( results[i].expectedLoss / ( MAX( 
				results[i].defaultProbability, 0.0000001 ) ) ) << "   ";
			
			std::cout.width( 8 );
			std::cout.precision( 4 );
			std::cout << ( 100.0 * results[i].claimProbability ) << "% ";
			std::cout.width( 9 );
			std::cout.precision( 2 );
			std::cout << results[i].expectedClaim << " ";
			std::cout.width( 9 );
			std::cout.precision( 2 );
			std::cout << ( results[i].expectedClaim / ( MAX( 
				results[i].claimProbability, 0.0000001 ) ) ) << " ";
			std::cout.width( 9 );
			std::cout.precision( 0 );
			std::cout << results[i].maxClaim << " ";
			std::cout.width( 9 );
			std::cout.precision( 0 );
			std::cout << results[i].maxClaimPv << "       ";
			
			std::cout.width( 5 );
			std::cout.precision( 2 );
			std::cout << _calculateMoodysMetric( results[i].expectedLossPercent,
				wal[i] ) << "\n";
		
		}
	
	}

	FLOAT CapModel3::_calculateMoodysMetric( FLOAT expectedLoss, FLOAT wal )
	{
	
		if( expectedLoss == 0.0 )
		{
		
			return 0.0;
		
		}
		
		typedef std::deque< FLOAT > FloatVector;
		
		unsigned int walLow = (unsigned int) wal;
		FloatVector elossLow;
		
		if( walLow > 0 )
		{
		
			for( RatingMap::iterator rating = _ratings.begin(); 
				rating != _ratings.end(); ++rating )
			{
			
				assert( walLow - 1 < 
					rating->second.defaultProbabilities.size() );
				elossLow.push_back( 
					rating->second.defaultProbabilities[ walLow - 1 ] * 0.55 );
			
			}
			
			std::sort( elossLow.begin(), elossLow.end() );
		
		}
		else
		{
		
			elossLow.assign( _ratings.size(), 0 );
		
		}
		
		FloatVector elossHigh;
		FloatVector elossDelta;
		
		if( walLow < 10 )
		{
		
			FLOAT walHigh = walLow + 1;
		
			unsigned int index = 0;
		
			for( RatingMap::iterator rating = _ratings.begin(); 
				rating != _ratings.end(); ++rating, ++index )
			{
			
				assert( walHigh - 1
					< rating->second.defaultProbabilities.size() );
				elossHigh.push_back( 
					rating->second.defaultProbabilities[ walHigh - 1 ] * 0.55 );
				elossDelta.push_back( elossHigh[index] - elossLow[index] );
			
			}
		
		}
		else
		{
		
			unsigned int index = 0;
			for( RatingMap::iterator rating = _ratings.begin(); 
				rating != _ratings.end(); ++rating, ++index )
			{
			
				Rating::Probabilities::iterator prob = 
					rating->second.defaultProbabilities.end();
					
				prob -= 2;
				
				assert( prob != rating->second.defaultProbabilities.end() );
				
				elossHigh.push_back( *prob * 0.55 );
			
				elossDelta.push_back( elossLow[index] - elossHigh[index] );
			
			}
		
		}
		
		FloatVector interpolatedEloss;
		
		for( unsigned int i = 0, size = elossLow.size(); i < size; ++i )
		{
		
			interpolatedEloss.push_back( elossLow[i] + 
				( wal - walLow ) * elossDelta[i] );
		
			interpolatedEloss.back() = log( interpolatedEloss.back() ) / 
				log(10.0);
		
		}
		
		expectedLoss = log( expectedLoss ) / log( 10.0 );
		
		FloatVector deltaEloss;
		
		for( unsigned int i = 0, size = interpolatedEloss.size() - 1; 
			i < size; ++i )
		{
		
			deltaEloss.push_back( 
				interpolatedEloss[ i + 1 ] - interpolatedEloss[ i ] );
		
		}
		
		deltaEloss.push_back( deltaEloss.back() );
		
		FloatVector::iterator fi = std::upper_bound( interpolatedEloss.begin(), 
			interpolatedEloss.end(), expectedLoss );
		unsigned int i = fi - interpolatedEloss.begin();
		
		FLOAT log0 = log( 0.00000003 ) / log(10.0);
		
		if( i == 0.0 )
		{
		
			if( expectedLoss < log0 )
			{
			
				return 0.0;
			
			}
			else
			{
			
				return ( expectedLoss - log0 ) / 
					( interpolatedEloss[0] - log0 );
			
			}
		
		}
		
		return ( i + ( expectedLoss - interpolatedEloss[ i - 1 ] ) * 
			deltaEloss[ i - 1 ] );
	
	}

	CapModel3::CapModel3(  )
	{
	
		_ratingsFileName = "ratings.csv";
		_industryFileName = "industry.csv";
		_portfolioFileName = "portfolio.csv";
		_obligorsFileName = "obligors.csv";
		_twisterFileName = "twisters.dat";
		_initialized = false;
		_correlation = 0;
		_mean = 0;
		_defaultProbability = 0;
		
		_twisters = 0;
		_twisterSize = 0;
		
		useGpu = false;		
	
	}
	
	CapModel3::CapModel3( const SimulationParameters& parameters ):
		_parameters( parameters )
	{
	
		_ratingsFileName = "ratings.csv";
		_industryFileName = "industry.csv";
		_portfolioFileName = "portfolio.csv";
		_obligorsFileName = "obligors.csv";
		_twisterFileName = "twisters.dat";
		_initialized = false;
		_correlation = 0;
		_mean = 0;
		_defaultProbability = 0;
		
		_twisters = 0;
		_twisterSize = 0;

		useGpu = false;
	
	}
	
	CapModel3::CapModel3( const SimulationParameters& parameters,
				const std::string& ratingsFileName,
				const std::string& industryFileName,
				const std::string& portfolioFileName,
				const std::string& obligorsFileName,
				const std::string& twisterFileName ):
		_parameters( parameters ),
		_ratingsFileName( ratingsFileName ),
		_industryFileName( industryFileName ),
		_portfolioFileName( portfolioFileName ),
		_obligorsFileName( obligorsFileName ),
		_twisterFileName( twisterFileName )
	{
	
		_initialized = false;
		_correlation = 0;
		_mean = 0;
		_defaultProbability = 0;
		
		_twisters = 0;
		_twisterSize = 0;
		
		useGpu = false;
	
	}
	
	CapModel3::~CapModel3()
	{
	
		if( _correlation != 0 )
		{
		
			delete[] _correlation;
		
		}
		
		if( _mean != 0 )
		{
		
			delete[] _mean;
		
		}
		
		if( _defaultProbability != 0 )
		{
		
			delete[] _defaultProbability;
		
		}
		
		if( _twisters != 0 )
		{
		
			delete[] _twisters;
		
		}
	
	}
	
	void CapModel3::parameters( const SimulationParameters& params )
	{
	
		_parameters = params;
	
	}
	
	void CapModel3::ratings( const std::string& file )
	{
	
		_ratingsFileName = file;
	
	}
	
	void CapModel3::industry( const std::string& file )
	{
	
		_industryFileName = file;
	
	}
	
	void CapModel3::portfolio( const std::string& file )
	{
	
		_portfolioFileName = file;
	
	}
	
	void CapModel3::obligors( const std::string& file )
	{
	
		_obligorsFileName = file;
	
	}
	
	void CapModel3::twisters( const std::string& file )
	{
	
		_twisterFileName = file;
	
	}

	const SimulationParameters& CapModel3::parameters() const
	{
	
		return _parameters;
	
	}

	void CapModel3::run()
	{

		report( "Running CapModel3" );
	
		if( !_initialized )
		{
		
			report( "Not initialized, loading files." );
		
			_initialized = true;
			
			// read files
			_readRatings();
			_readIndustry();
			_readPortfolio();
			_readObligors();
			_readTwisters();

			report( "Computing invariants." );
			
			// compute invairants
			_adjustPortfolios();
			_setupObligors();
			_computeQuarters();
			_computeDefaultProbabilties();
			_initCounterParties();
			
		}
	
		report( "Starting simulation." );

		_runSimulation();

		report( "Simulation finished." );
	
	}
	
	void CapModel3::clear()
	{
	
		_ratings.clear();
		_industries.clear();
		_obligors.clear();
		_portfolios.clear();
		_initialized = false;
	
	}
	
	std::string CapModel3::toString() const
	{
	
		std::stringstream stream;
				
		stream << "\nRatings\n\n";
		for( RatingMap::const_iterator fi = _ratings.begin(); 
			fi != _ratings.end(); ++fi )
		{
		
			stream << fi->second.toString();
		
		}
		
		stream << "\nIndustries\n\n";
		for( IndustryMap::const_iterator fi = _industries.begin(); 
			fi != _industries.end(); ++fi )
		{
		
			stream << fi->second.toString();
		
		}
		
		stream << "\nObligors\n\n";
		for( ObligorMap::const_iterator fi = _obligors.begin(); 
			fi != _obligors.end(); ++fi )
		{
		
			stream << fi->second.toString();
		
		}
		
		stream << "\nPortfolios\n\n";
		for( PortfolioMap::const_iterator fi = _portfolios.begin(); 
			fi != _portfolios.end(); ++fi )
		{
		
			stream << fi->second.toString();
		
		}

		stream << "Parameters";
		stream << _parameters.toString();
		
		return stream.str();
	
	}

}

#endif


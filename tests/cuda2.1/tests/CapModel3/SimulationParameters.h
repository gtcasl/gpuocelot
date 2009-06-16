/*!

	\file SimulationParameters.h
	
	\date Saturday December 13, 2008
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	
	\brief The header file for the SimulationParameters class

*/

#ifndef SIMULATION_PARAMETERS_H_INCLUDED
#define SIMULATION_PARAMETERS_H_INCLUDED

#include "Stringable.h"
#include "Date.h"

#ifndef FLOAT
#define FLOAT float
#endif

/*!

	\brief A namespace for classes related to the cap simlation.

*/
namespace sim
{

	class SimulationParameters : public hydrazine::Stringable
	{
	
		public:
		
			// inputs
		
			Date date;
			unsigned int numberOfSimulations;
			unsigned int chunkSize;
			
			FLOAT investRate;
			unsigned int initialEquity;

			FLOAT debtParameter;			
			FLOAT debtRate;
			
			unsigned int optionExpense;
			FLOAT optionInflation;
			FLOAT managementFeeRate;
			FLOAT assetManagementFeeRate;
			unsigned int managementFeeCap;			

			int targetPointSpread;

			FLOAT lgdMean;
			FLOAT lgdStdev;
			
		public:
		
			std::string toString() const;
	
	};


}

#endif


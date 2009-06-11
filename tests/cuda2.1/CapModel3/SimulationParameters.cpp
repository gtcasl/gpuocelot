/*!

	\file SimulationParameters.cpp
	
	\date Saturday December 13, 2008
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	
	\brief The source file for the SimulationParameters class

*/

#ifndef SIMULATION_PARAMETERS_CPP_INCLUDED
#define SIMULATION_PARAMETERS_CPP_INCLUDED

#include "SimulationParameters.h"

namespace sim
{

	std::string SimulationParameters::toString() const
	{
	
		std::stringstream stream;
		
		stream << "Input Parameters:\n";
		
		stream << " date: " << date.toString() << "\n";
		stream << " simulations: " << numberOfSimulations << "\n";
		stream << " chunk size: " << chunkSize << "\n";
		stream << " invest rate: " << investRate << "\n";
		stream << " initial equity: " << initialEquity << "\n";
		stream << " debt parameter: " << debtParameter << "\n";
		stream << " debt rate: " << debtRate << "\n";
		stream << " option expense: " << optionExpense << "\n";
		stream << " option inflation: " << optionInflation << "\n";
		stream << " management fee rate: " << managementFeeRate << "\n";
		stream << " asset management fee rate: " << assetManagementFeeRate 
			<< "\n";
		stream << " management fee cap: " << managementFeeCap << "\n";
		stream << " lgd mean: " << lgdMean << "\n";
		stream << " lgd stanard deviation: " << lgdStdev << "\n";

		stream << " target point spread: " << targetPointSpread << "\n";
		
		return stream.str();
	
	}
	
}

#endif


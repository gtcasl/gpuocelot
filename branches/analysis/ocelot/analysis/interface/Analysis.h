/*! \file   Analysis.h
	\author Gregory Diamos <gdiamos@gatech.edu>
	\date   Saturday May 7, 2011
	\brief  The header file for the Analysis class.
*/

#ifndef ANALYSIS_H_INCLUDED
#define ANALYSIS_H_INCLUDED

// Standard Library Includes
#include <string>

// Forward Declarations
namespace transforms { class PassManager; }
namespace ir         { class IRKernel;    }
namespace ir         { class Module;      }

namespace analysis
{

/*! \brief An analysis that can be constructed for aiding IR transforms */
class Analysis
{
public:	
	/*! \brief Analysis type */
	enum Type
	{
		NoAnalysis                = 0x0,
		ControlTreeAnalysis       = 0x1,
		DominatorTreeAnalysis     = 0x2,
		PostDominatorTreeAnalysis = 0x4,
		DataflowGraphAnalysis     = 0x8,
		StaticSingleAssignment    = 0x10,
		DivergenceAnalysis        = 0x20,
		ThreadFrontierAnalysis    = 0x40
	};

public:
	/*! \brief Initialize the analysis, register it with a pass manager */
	Analysis(Type t = NoAnalysis, const std::string& name = "",
		int required = NoAnalysis);

public:
	/*! \brief Get the analysis type */
	const Type type;

	/*! \brief The name of the analysis */
	const std::string name;

public:
	/*! \brief Set the pass manager used to supply dependent analyses */
	void setPassManager(transforms::PassManager* m);
	
	/*! \brief Get an up to date analysis by type */
	Analysis* getAnalysis(Analysis::Type type);

	/*! \brief Get an up to date analysis by type (const) */
	const Analysis* getAnalysis(Analysis::Type type) const;
	
	/*! \brief Invalidate the analysis, the pass manager will
		need to generate it again for other users */
	void invalidateAnalysis(Analysis::Type type);

private:
	int                      _required;
	transforms::PassManager* _manager;

};

/*! \brief An analysis over a single kernel */
class KernelAnalysis : public Analysis
{

public:
	/*! \brief Initialize the analysis, register it with a pass manager */
	KernelAnalysis(Type t = NoAnalysis, const std::string& name = "",
		int required = NoAnalysis);

public:
	virtual void analyze(ir::IRKernel& kernel) = 0;

};

/*! \brief An analysis over a complete module */
class ModuleAnalysis : public Analysis
{

public:
	/*! \brief Initialize the analysis, register it with a pass manager */
	ModuleAnalysis(Type t = NoAnalysis, const std::string& name = "",
		int required = NoAnalysis);

public:
	virtual void analyze(ir::Module& module) = 0;

};


}

#endif


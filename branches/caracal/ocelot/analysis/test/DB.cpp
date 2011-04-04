#include <sys/time.h>
#include <cxxabi.h>
#include <hydrazine/implementation/ArgumentParser.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DivergenceAnalysis.h>
#include <ocelot/graphs/interface/DivergenceDrawer.h>

/* This application generates control, data / divergence flow graphs on dot language for a input ptx file */
int main ( int argc, char** argv )
{
	hydrazine::ArgumentParser parser(argc, argv);
	parser.description("Tests diverging branches analysis");

	std::string ptxFilename, currentPath;
	bool divergenceGraph = false;
	bool varsGraph = false;
	bool dfgGraph = false;
	bool cfgGraph = false;
	bool allGraphs = false;
	bool cfgPropagation = true;

	parser.parse("-i", "--input", ptxFilename, "", "Input PTX file.");

	parser.parse("-a", "--all", allGraphs, false, "Prints all graphs");

	parser.parse("-d", "--data", varsGraph, false, "Prints data propagation graph");
	parser.parse("-v", "--div", divergenceGraph, false, "Prints divergent data propagation graph");
	parser.parse("-c", "--cfg", cfgGraph, false, "Prints control flow graph");
	parser.parse("-f", "--dfg", dfgGraph, false, "Prints complete data & control flow graph with divergences");
	parser.parse("", "--nocda", cfgPropagation, true, "Make the control dependency analysis");

	parser.parse();

	if(ptxFilename == ""){
		cerr << "No input ptx file" << std::endl;
		parser.help();
		exit(EXIT_FAILURE);
	}

	ir::Module module(ptxFilename);
	ir::Module::KernelMap::const_iterator k_it = module.kernels().begin();

	for ( ; k_it != module.kernels().end(); ++k_it )
	{
		ir::PTXKernel* kernel = static_cast<ir::PTXKernel*> (k_it->second);

		if(kernel == NULL)
		{
			std::cerr << "Invalid kernel" << std::endl;
			exit(EXIT_FAILURE);
		}

		int status = -1;
		std::string kernelName = abi::__cxa_demangle(kernel->name.c_str(), 0, 0, &status);
		if ( status < 0 )
		{
			std::cerr << "Error: could not demangle kernel name " << kernel->name << std::endl;
			exit(EXIT_FAILURE);
		}

		/* Remove arguments types */
		kernelName = kernelName.substr(0, kernelName.find("("));

		analysis::DivergenceAnalysis divergenceAnalysis;

		if(!cfgPropagation){
			divergenceAnalysis.setControlFlowAnalysis(false);
		}
		divergenceAnalysis.runOnKernel(*k_it->second);

		if(ptxFilename.find('/') != std::string::npos){
			currentPath = ptxFilename.substr(0, 1 + ptxFilename.find_last_of('/'));
		} else {
			currentPath = "";
		}

		graph_utils::DivergenceDrawer drawer(kernelName, currentPath, &divergenceAnalysis, allGraphs, divergenceGraph, varsGraph, dfgGraph, cfgGraph);

		if(allGraphs || divergenceGraph || varsGraph || dfgGraph || cfgGraph){
			drawer.draw();
		}
	}

	return EXIT_SUCCESS;
}

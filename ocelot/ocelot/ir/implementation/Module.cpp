/*!
	\file Module.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief declares a Module loadable from a PTX source file and runable
*/

#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/interface/Version.h>
#include <ocelot/parser/interface/PTXParser.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>
#include <cassert>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

ir::Module::Module(std::string path): cuModuleState(Invalid) {
	load(path);
}

ir::Module::Module(std::istream& stream): cuModuleState(Invalid) {
	load(stream);
}

ir::Module::Module(): cuModuleState(Invalid) {
	PTXStatement version;
	PTXStatement target;
	version.directive = PTXStatement::Version;
	version.major = 1; version.minor = 3;
	target.targets.push_back("sm_13");
	statements.push_back(version);
	statements.push_back(target);
}

ir::Module::~Module() {
	unload();
}


ir::Module::Module(std::string name, const StatementVector & statements): cuModuleState(Invalid) {
	modulePath = name;
	this->statements = statements;
	extractPTXKernels();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Deletes everything associated with this particular module
*/
void ir::Module::unload() {
	// delete all available kernels
	for (KernelMap::iterator it = kernels.begin(); it != kernels.end(); ++it) {
		KernelVector& vec = it->second;
		
		for (KernelVector::iterator kern_it = vec.begin(); 
			kern_it != vec.end(); ++kern_it) {
			delete *kern_it;
		}
		vec.clear();
	}
	kernels.clear();
	modulePath = "::unloaded::";
}

/*!
	Unloads module and loads everything in path
*/
bool ir::Module::load(std::string path) {
	using namespace std;

	unload();
	modulePath = path;

	{
		// open file, parse file, extract statements vector

		ifstream file(modulePath.c_str());

		if (file.is_open()) {
			parser::PTXParser parser;
			parser.fileName = string(modulePath.c_str());

			ir::Module module = parser.parse( file );
	
			statements = module.statements;
			extractPTXKernels();
		}
		else {
			return false;
		}
	}


	return true;
}

/*!
	Unloads module and loads everything in path
*/
bool ir::Module::load(std::istream& stream, std::string path) {
	using namespace std;

	unload();
	
	{
		parser::PTXParser parser;
		modulePath = path;
		parser.fileName = modulePath;
		
		ir::Module module = parser.parse( stream );
		statements = module.statements;
		extractPTXKernels();
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/
void ir::Module::write( std::ostream& stream ) const {

	if( statements.empty() ) {
		return;
	}
		
	PTXStatement::Directive previous = PTXStatement::Directive_invalid;
	
	if(false && statements[0].version == PTXInstruction::ptx1_4 ) {
		for( StatementVector::const_iterator statement = statements.begin(); 
			statement != statements.end(); ++statement ) {
			report( "Line " << ( statement - statements.begin() ) 
				<< ": " << statement->toString() );
			if( statement->directive == PTXStatement::Param )
			{
				if( previous != PTXStatement::StartParam )
				{
					stream << ",\n\t" << statement->toString();
				}
				else
				{
					stream << "\n\t" << statement->toString();
				}
			}
			else
			{
				stream << "\n";
				if( statement->directive == PTXStatement::Instr 
					|| statement->directive == PTXStatement::Loc ) {
					stream << "\t";
				}
				stream << statement->toString();
			}
			previous = statement->directive;
		}
		stream << "\n";
	}
	else {
		/*
		for( StatementVector::const_iterator statement = statements.begin(); 
			statement != statements.end(); ++statement ) {
			report( "Line " << ( statement - statements.begin() ) 
				<< ": " << statement->toString() );
			stream << statement->toString() << "\n";
		}
		stream << "\n";
		
		*/
		
		// header
		for (int i = 0; i < 2; i++) {
			stream << statements[i].toString() << "\n";
		}

		stream << "\n\n/*\n* AUTO GENERATED OCELOT PTX FILE\n";
		stream << "* Ocelot Version : " << hydrazine::Version().toString() << "\n";
		stream << "* From file : " << modulePath << "\n";
		stream << "*/\n";
		
		// textures
		
		/*
		stream << "\n// Textures\n";
		for (TextureMap::const_iterator tex_it = this->textures.begin(); tex_it != this->textures.end(); ++tex_it ) {
			stream << ".tex " << Texture::toString(tex_it->second.type) << " " << tex_it->first << ";\n";
		}
		*/
		
		// globals
		stream << "\n// Globals\n";
		for (GlobalMap::const_iterator glb_it = globals.begin(); glb_it != globals.end(); ++glb_it) {
		
			const Global &global = glb_it->second;
			stream << global.statement.toString() << "\n";
		}
		stream << "\n";
		
		// kernels
		KernelMap::const_iterator ptxKernelsIt = kernels.find(ir::Instruction::PTX);
		if (ptxKernelsIt != kernels.end()) {
			const KernelVector &kernelVector = ptxKernelsIt->second;
			KernelVector::const_iterator ptxKernels = kernelVector.begin();
			for (; ptxKernels != kernelVector.end(); ++ptxKernels) {
			
				ir::Kernel *kernel = *ptxKernels;
				
				// cast away constness so we can perform data flow
				PTXKernel *ptxKernel = static_cast<PTXKernel *>(kernel);
				
				ptxKernel->dfg();
				ptxKernel->write(stream);
				stream << "\n";	
			}
		}
	}
}

/*!
	After parsing, construct a set of Kernels with ISA equal to PTX from the statements vector.
*/
void ir::Module::extractPTXKernels() {
	using namespace std;
	StatementVector::const_iterator startIterator = statements.end(), 
		endIterator = statements.end();

	bool inKernel = false;
	int instructionCount = 0;
	int kernelInstance = 1;

	/*
	// KERRDEBUG
	static int moduleIndex = 0;
	std::stringstream ss;
	ss << "raw_modules/module" << moduleIndex << ".ptx";
	std::string str = ss.str();
	std::ofstream moduleStream(str.c_str());
	moduleIndex ++;

	// temporary debugging
	{
		// get parameters/locals, extract kernel name
		for( StatementVector::const_iterator it = statements.begin(); it != statements.end(); ++it ) 
		{
			moduleStream << (*it).toString() << "\n";
		}					
	}
	// end KERRDEBUG
	*/

	for (StatementVector::const_iterator it = statements.begin(); 
		it != statements.end(); ++it) {
		const PTXStatement &statement = (*it);
		if (statement.directive == PTXStatement::Entry) {
			// new kernel
			startIterator = it;
			inKernel = true;
			instructionCount = 0;
		}
		else if (statement.directive == PTXStatement::EndEntry) {
			// construct the kernel and push it onto something
			inKernel = false;
			endIterator = ++StatementVector::const_iterator(it);
			if (instructionCount) {
				PTXKernel *kernel = new PTXKernel(startIterator, endIterator);
				
				// you may not always want to perform data flow
				//kernel->dfg();
				
				kernel->module = this;
				kernels[PTXInstruction::PTX].push_back(kernel);
				kernel->canonicalBlockLabels(kernelInstance++);
			}
		}
		if (inKernel) {
			if (statement.directive == PTXStatement::Instr) {
				instructionCount ++;
			}
		}
		else if (statement.directive == PTXStatement::Const
			|| statement.directive == PTXStatement::Global
			|| statement.directive == PTXStatement::Shared) {
			assert(globals.count(statement.name) == 0);
			globals.insert(std::make_pair(statement.name, Global(statement)));
		}
		else if (statement.directive == PTXStatement::Tex) {
			assert(globals.count(statement.name) == 0);
			globals.insert(std::make_pair(statement.name, Global(statement)));
			textures.insert(std::make_pair(statement.name, Texture()));
		}
	}
}

/*!
	Gets a kernel instance by ISA and name. Returned kernel is guaranteed to have ISA requested.

	\param isa instruction set architecture of desired kernel
	\param kernelName [mangled] name of kernel

	\return pointer to kernel instance with (isa, name) or 0 if kernel does not exist
*/
ir::Kernel * ir::Module::getKernel(ir::Instruction::Architecture isa, std::string kernelName) {
	using namespace std;
	if (kernels.find(isa) != kernels.end()) {
		for (KernelVector::const_iterator it = kernels[isa].begin(); 
			it != kernels[isa].end(); ++it) {
			if ((*it)->name == kernelName) {
				return (*it);
			}
		}
	}
	return 0;
}


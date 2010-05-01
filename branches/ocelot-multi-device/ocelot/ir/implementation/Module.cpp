/*! \file Module.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief declares a Module loadable from a PTX source file and runable
*/


#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/parser/interface/PTXParser.h>

#include <hydrazine/implementation/debug.h>
#include <hydrazine/interface/Version.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>
#include <cassert>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

ir::Module::Module(std::string path) {
	load(path);
}

ir::Module::Module(std::istream& stream, const std::string& path) {
	load(stream, path);
}

ir::Module::Module() {
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


ir::Module::Module(std::string name, const StatementVector & _statements) {
	modulePath = name;
	statements = _statements;
	extractPTXKernels();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Deletes everything associated with this particular module
*/
void ir::Module::unload() {
	// delete all available kernels
	for (KernelMap::iterator kern_it = kernels.begin(); kern_it != kernels.end(); ++kern_it) {
		delete kern_it->second;
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
bool ir::Module::load(std::istream& stream, const std::string& path) {
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

void ir::Module::write( std::ostream& stream ) const {

	report("Writing module (statements) - " << modulePath 
		<< " - to output stream.");

	if( statements.empty() ) {
		return;
	}
		
	PTXStatement::Directive previous = PTXStatement::Directive_invalid;
	
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

void ir::Module::writeIR( std::ostream& stream ) const {
	report("Writing module (IR) - " << modulePath 
		<< " - to output stream.");

	stream << ".version 1.4\n";
	stream << ".target sm_13\n";

	stream << "/* Module " << modulePath << " */\n\n";
	
	stream << "/* Globals */\n";
	for (GlobalMap::const_iterator global = globals.begin(); 
		global != globals.end(); ++global) {
		stream << global->second.statement.toString() << "\n";
	}
	stream << "\n";

	stream << "/* Textures */\n";
	for (TextureMap::const_iterator texture = textures.begin(); 
		texture != textures.end(); ++texture) {
		stream << texture->second.toString() << "\n";
	}
	stream << "\n";
	
	for (KernelMap::const_iterator kernel = kernels.begin(); 
		kernel != kernels.end(); ++kernel) {
		(kernel->second)->write(stream);
	}
}

void ir::Module::createDataStructures() {
	for (KernelMap::iterator kernel = kernels.begin(); 
		kernel != kernels.end(); ++kernel) {
		(kernel->second)->dfg();
	}
}

static ir::Texture::Type convert(ir::PTXOperand::DataType t) {
	switch(t) {
		case ir::PTXOperand::s32: return ir::Texture::Signed; break;
		case ir::PTXOperand::u32: return ir::Texture::Unsigned; break;
		case ir::PTXOperand::f32: return ir::Texture::Float; break;
		default: break;
	}
	return ir::Texture::Invalid;
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
				
				kernel->module = this;
				kernels[kernel->name] = (kernel);
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
			assert(textures.count(statement.name) == 0);
			textures.insert(std::make_pair(statement.name, 
				Texture(statement.name, convert(statement.type))));
		}
	}
}

/*!
	Gets a kernel instance by ISA and name. Returned kernel is guaranteed to have ISA requested.

	\param isa instruction set architecture of desired kernel
	\param kernelName [mangled] name of kernel

	\return pointer to kernel instance with (isa, name) or 0 if kernel does not exist
*/
ir::Kernel * ir::Module::getKernel(std::string kernelName) {
	if (kernels.find(kernelName) != kernels.end()) {
		return kernels[kernelName];
	}
	return 0;
}


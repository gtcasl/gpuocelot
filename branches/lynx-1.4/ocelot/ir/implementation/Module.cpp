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

ir::Module::Module(const std::string& path) : _ptxPointer(0) {
	load(path);
}

ir::Module::Module(std::istream& stream, 
	const std::string& path) : _ptxPointer(0) {
	load(stream, path);
}

ir::Module::Module() : _ptxPointer(0) {
	PTXStatement version;
	PTXStatement target;
	version.directive = PTXStatement::Version;
	version.major = 1; version.minor = 4;
	target.targets.push_back("sm_13");
	_statements.push_back(version);
	_statements.push_back(target);
	_target = ".target sm_13";
}

ir::Module::~Module() {
	unload();
}


ir::Module::Module(const std::string& name, 
	const StatementVector& statements) {
	_modulePath = name;
	_statements = statements;
	extractPTXKernels();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Deletes everything associated with this particular module
*/
void ir::Module::unload() {
	// delete all available kernels
	for (KernelMap::iterator kern_it = _kernels.begin(); 
		kern_it != _kernels.end(); ++kern_it) {
		delete kern_it->second;
	}
	_kernels.clear();
	_statements.clear();
	_textures.clear();
	_globals.clear();
	_modulePath = "::unloaded::";
}

/*!
	Unloads module and loads everything in path
*/
bool ir::Module::load(const std::string& path) {
	using namespace std;

	unload();
	_modulePath = path;

	// open file, parse file, extract statements vector

	ifstream file(_modulePath.c_str());

	if (file.is_open()) {
		parser::PTXParser parser;
		parser.fileName = _modulePath;

		parser.parse( file );

		_statements = std::move( parser.statements() );
		extractPTXKernels();
	}
	else {
		return false;
	}

	return true;
}

/*!
	Unloads module and loads everything in path
*/
bool ir::Module::load(std::istream& stream, const std::string& path) {
	
	unload();
	
	parser::PTXParser parser;
	_modulePath = path;
	parser.fileName = _modulePath;
	
	parser.parse( stream );
	_statements = std::move( parser.statements() );
	extractPTXKernels();

	return true;
}

bool ir::Module::lazyLoad(std::string& source, const std::string& path) {
	unload();
	
	_ptx = std::move( source );
	_modulePath = path;
	
	return true;
}

bool ir::Module::lazyLoad(const char* source, const std::string& path) {
	unload();
	
	_ptxPointer = source;
	_modulePath = path;
	
	return true;
}

void ir::Module::loadNow() {
	if( loaded() ) return;
	if( !_ptx.empty() )
	{
		std::stringstream stream( std::move( _ptx ) );
		_ptx.clear();
	
		parser::PTXParser parser;
		parser.fileName = path();
	
		parser.parse( stream );
		_statements = std::move( parser.statements() );
		extractPTXKernels();
	}
	else
	{
		std::stringstream stream( _ptxPointer );
		_ptxPointer = 0;
	
		parser::PTXParser parser;
		parser.fileName = path();
	
		parser.parse( stream );
		_statements = std::move( parser.statements() );
		extractPTXKernels();
	}
}	
	
bool ir::Module::loaded() const {
	return _ptx.empty() && ( _ptxPointer == 0 );
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ir::Module::write( std::ostream& stream ) const {
	assert( loaded() );

	report("Writing module (statements) - " << _modulePath 
		<< " - to output stream.");

	if( _statements.empty() ) {
		return;
	}
		
	PTXStatement::Directive previous = PTXStatement::Directive_invalid;
	
	for( StatementVector::const_iterator statement = _statements.begin(); 
		statement != _statements.end(); ++statement ) {
		report( "Line " << ( statement - _statements.begin() ) 
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
	assert( loaded() );
	report("Writing module (IR) - " << _modulePath 
		<< " - to output stream.");

	stream << ".version 1.4\n";
	stream << _target << "\n";

	stream << "/* Module " << _modulePath << " */\n\n";
	
	stream << "/* Globals */\n";
	for (GlobalMap::const_iterator global = _globals.begin(); 
		global != _globals.end(); ++global) {
		stream << global->second.statement.toString() << "\n";
	}
	stream << "\n";

	stream << "/* Textures */\n";
	for (TextureMap::const_iterator texture = _textures.begin(); 
		texture != _textures.end(); ++texture) {
		stream << texture->second.toString() << "\n";
	}
	stream << "\n";
	
	for (KernelMap::const_iterator kernel = _kernels.begin(); 
		kernel != _kernels.end(); ++kernel) {
		(kernel->second)->write(stream);
	}
}

ir::Texture* ir::Module::getTexture(const std::string& name) {
	loadNow();
	TextureMap::iterator texture = _textures.find(name);
	if (texture != _textures.end()) {
		return &texture->second;
	}
	return 0;
}

ir::Global* ir::Module::getGlobal(const std::string& name) {
	loadNow();
	GlobalMap::iterator global = _globals.find(name);
	if (global != _globals.end()) {
		return &global->second;
	}
	return 0;
}

const std::string& ir::Module::path() const {
	assert( loaded() );
	return _modulePath;
}

const ir::Module::KernelMap& ir::Module::kernels() const {
	assert( loaded() );
	return _kernels;
}

const ir::Module::GlobalMap& ir::Module::globals() const {
	assert( loaded() );
	return _globals;
}

const ir::Module::TextureMap& ir::Module::textures() const {
	assert( loaded() );
	return _textures;
}

const ir::Module::StatementVector& ir::Module::statements() const {
	assert( loaded() );
	return _statements;
}

void ir::Module::insertGlobal(const PTXStatement &statement) {
	loadNow();
	if(!_globals.insert(std::make_pair(statement.name, Global(statement))).second) {
		throw hydrazine::Exception("Inserted duplicated global - " 
			+ statement.name);
	}
}		

ir::PTXKernel* ir::Module::getKernel(const std::string& kernelName) {
	loadNow();
	KernelMap::iterator kernel = _kernels.find(kernelName);
	if (kernel != _kernels.end()) {
		return kernel->second;
	}
	return 0;
}

void ir::Module::removeKernel(const std::string& name) {
	loadNow();
	KernelMap::iterator kernel = _kernels.find(name);
	if (kernel != _kernels.end()) {
		delete kernel->second;
		_kernels.erase(kernel);
	}
}

void ir::Module::insertKernel(PTXKernel* kernel) {
	loadNow();
	if(!_kernels.insert(std::make_pair(kernel->name, kernel)).second) {
		throw hydrazine::Exception("Inserted duplicated kernel - " 
			+ kernel->name);
	}
}

/*!
	After parsing, construct a set of Kernels with ISA equal to PTX from the statements vector.
*/
void ir::Module::extractPTXKernels() {
	using namespace std;
	StatementVector::const_iterator startIterator = _statements.end(), 
		endIterator = _statements.end();

	bool inKernel = false;
	int instructionCount = 0;
	int kernelInstance = 1;
	bool isFunction = false;

	for (StatementVector::const_iterator it = _statements.begin(); 
		it != _statements.end(); ++it) {
		const PTXStatement &statement = (*it);
		if (statement.directive == PTXStatement::Entry 
			|| statement.directive == PTXStatement::Func) {
			// new kernel
			assert(!inKernel);
			startIterator = it;
			inKernel = true;
			instructionCount = 0;
		}
		else if (statement.directive == PTXStatement::EndEntry) {
			// construct the kernel and push it onto something
			inKernel = false;
			endIterator = ++StatementVector::const_iterator(it);
			if (instructionCount) {
				PTXKernel *kernel = new PTXKernel(startIterator, 
					endIterator, isFunction);
				
				kernel->module = this;
				_kernels[kernel->name] = (kernel);
				kernel->canonicalBlockLabels(kernelInstance++);
			}
		}
		else if (statement.directive == PTXStatement::Target) {
			_target = statement.toString();
		}
		if (inKernel) {
			if (statement.directive == PTXStatement::Instr) {
				instructionCount++;
			}
		}
		else if (statement.directive == PTXStatement::Const
			|| statement.directive == PTXStatement::Global
			|| statement.directive == PTXStatement::Shared) {
			assertM(_globals.count(statement.name) == 0, "Global operand '" 
				<< statement.name << "' declared more than once." );

			_globals.insert(std::make_pair(statement.name, Global(statement)));
		}
		else if (statement.directive == PTXStatement::Tex) {
			assert(_textures.count(statement.name) == 0);
			_textures.insert(std::make_pair(statement.name, 
				Texture(statement.name)));
		}
	}
}


#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if( argc < 3 ) return 0;
	
	std::string out = argv[1];
	std::string in = argv[2];
	
	std::ifstream stream( in.c_str() );
	std::ofstream outStream( out.c_str() );
	
	if( !stream.is_open() ) return 0;
	
	unsigned int maxsize = 1 << 16;
	char* line = new char[ maxsize ];
	
	while( stream.good() )
	{
		stream.getline( line, maxsize );
		unsigned int count = stream.gcount();
		
		std::string newLine = line;
		
		if( newLine.find( "class istream;" ) != std::string::npos )
		{
			std::string include("#include <iostream>\nusing namespace std;\n");
			outStream.write(include.c_str(), include.size());
		}
		else
		{
			if( count > 1 )
			{
				line[count - 1] = '\n';
				outStream.write(line, count);
			}
		}
	}
	
	outStream.close();
	
	delete[] line;
	
	return 0;
}

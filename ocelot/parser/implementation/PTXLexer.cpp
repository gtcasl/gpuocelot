/*! \file PTXLexer.cpp
	\date Monday January 19, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the PTXLexer class.
*/

#ifndef PTX_LEXER_CPP_INCLUDED
#define PTX_LEXER_CPP_INCLUDED

#undef yyFlexLexer
#define yyFlexLexer ptxFlexLexer
#include <FlexLexer.h>
#include <ocelot/parser/interface/PTXLexer.h>

#include <cstring>
#include <cassert>

#define CASE(x) case x: { return #x; break; }

namespace parser
{
	PTXLexer::PTXLexer( std::istream* arg_yyin, std::ostream* arg_yyout ):
		yyFlexLexer( arg_yyin, arg_yyout ), yylval( 0 ), column( 0 ), 
		nextColumn( 0 )
	{
	
	}
	
	int PTXLexer::yylexPosition()
	{
		int token = yylex();
		column = nextColumn;
		nextColumn = column + strlen( YYText() );
		return token;
	}
	
	std::string PTXLexer::toString( int token )
	{
		switch( token )
		{			
			case TOKEN_SPECIAL_REGISTER:
			{
				return "SPECIAL_REGISTER";
				break;
			}
			case TOKEN_ALIGN:
			{
				return "ALIGN";
				break;
			}
			case TOKEN_BYTE:
			{
				return "BYTE";
				break;
			}
			case TOKEN_CLOCK:
			{
				return "CLOCK";
				break;
			}
			case TOKEN_ENTRY:
			{
				return "ENTRY";
				break;
			}
			case OPCODE_EXIT:
			{
				return "EXIT";
				break;
			}
			case TOKEN_EXTERN:
			{
				return "EXTERN";
				break;
			}
			case TOKEN_FILE:
			{
				return "FILE";
				break;
			}
			case TOKEN_FUNCTION:
			{
				return "FUNCTION";
				break;
			}
			case TOKEN_LOC:
			{
				return "LOC";
				break;
			}
			case TOKEN_SECTION:
			{
				return "SECTION";
				break;
			}
			case TOKEN_STRUCT:
			{
				return "STRUCT";
				break;
			}
			case TOKEN_TARGET:
			{
				return "TARGET";
				break;
			}
			case TOKEN_UNION:
			{
				return "UNION";
				break;
			}
			case TOKEN_VERSION:
			{
				return "VERSION";
				break;
			}
			case TOKEN_VISIBLE:
			{
				return "VISIBLE";
				break;
			}
			case TOKEN_MAXNREG:
			{
				return "MAXNREG";
				break;
			}
			case TOKEN_MAXNTID:
			{
				return "MAXNTID";
				break;
			}
			case TOKEN_MAXNCTAPERSM:
			{
				return "MAXNCTAPERSM";
				break;
			}
			case TOKEN_SM10:
			{
				return "SM10";
				break;
			}
			case TOKEN_SM11:
			{
				return "SM11";
				break;
			}
			case TOKEN_SM12:
			{
				return "SM12";
				break;
			}
			case TOKEN_SM13:
			{
				return "SM13";
				break;
			}
			case TOKEN_SM20:
			{
				return "SM20";
				break;
			}
			case TOKEN_MAP_F64_TO_F32:
			{
				return "TOKEN_MAP_F64_TO_F32";
				break;
			}
			case TOKEN_AND:
			{
				return "AND";
				break;
			}
			case TOKEN_OR:
			{
				return "OR";
				break;
			}
			case TOKEN_XOR:
			{
				return "XOR";
				break;
			}
			case TOKEN_EQ:
			{
				return "EQ";
				break;
			}
			case TOKEN_NE:
			{
				return "NE";
				break;
			}
			case TOKEN_LT:
			{
				return "LT";
				break;
			}
			case TOKEN_LE:
			{
				return "LE";
				break;
			}
			case TOKEN_GT:
			{
				return "GT";
				break;
			}
			case TOKEN_GE:
			{
				return "GE";
				break;
			}
			case TOKEN_LS:
			{
				return "LS";
				break;
			}
			case TOKEN_HS:
			{
				return "HS";
				break;
			}
			case TOKEN_EQU:
			{
				return "EQU";
				break;
			}
			case TOKEN_NEU:
			{
				return "NEU";
				break;
			}
			case TOKEN_LTU:
			{
				return "LTU";
				break;
			}
			case TOKEN_LEU:
			{
				return "LEU";
				break;
			}
			case TOKEN_GTU:
			{
				return "GTU";
				break;
			}
			case TOKEN_GEU:
			{
				return "GEU";
				break;
			}
			case TOKEN_NUM:
			{
				return "NUM";
				break;
			}
			case TOKEN_NAN:
			{
				return "NAN";
				break;
			}
			case TOKEN_HI:
			{
				return "HI";
				break;
			}
			case TOKEN_LO:
			{
				return "LO";
				break;
			}
			case TOKEN_RN:
			{
				return "RN";
				break;
			}
			case TOKEN_RM:
			{
				return "RM";
				break;
			}
			case TOKEN_RZ:
			{
				return "RZ";
				break;
			}
			case TOKEN_RP:
			{
				return "RP";
				break;
			}
			case TOKEN_RNI:
			{
				return "RNI";
				break;
			}
			case TOKEN_RMI:
			{
				return "RMI";
				break;
			}
			case TOKEN_RZI:
			{
				return "RZI";
				break;
			}
			case TOKEN_RPI:
			{
				return "RPI";
				break;
			}
			case TOKEN_FTZ:
			{
				return "FTZ";
				break;
			}
			case TOKEN_FULL:
			{
				return "FULL";
				break;
			}
			case TOKEN_APPROX:
			{
				return "APPROX";
				break;
			}
			case TOKEN_LABEL:
			{
				return "LABEL";
				break;
			}
			case TOKEN_IDENTIFIER:
			{
				return "IDENTIFIER";
				break;
			}
			case TOKEN_STRING:
			{
				return "STRING";
				break;
			}
			case TOKEN_SAT:
			{
				return "SAT";
				break;
			}
			case TOKEN_CARRY:
			{
				return "CARRY";
				break;
			}
			case TOKEN_WIDE:
			{
				return "WIDE";
				break;
			}	
			case TOKEN_1D:
			{
				return "1D";
				break;
			}
			case TOKEN_2D:
			{
				return "2D";
				break;
			}
			case TOKEN_3D:
			{
				return "3D";
				break;
			}
			case TOKEN_V2:
			{
				return "V2";
				break;
			}
			case TOKEN_V4:
			{
				return "V4";
				break;
			}
			case TOKEN_ANY:
			{
				return "ANY";
				break;
			}
			case TOKEN_ALL:
			{
				return "ALL";
				break;
			}
			case TOKEN_PREDICATE_IDENTIFIER:
			{
				return "PREDICATE_IDENTIFIER";
				break;
			}
			case TOKEN_INV_PREDICATE_IDENTIFIER:
			{
				return "INV_PREDICATE_IDENTIFIER";
				break;
			}
			case TOKEN_ADD:
			{
				return "ADD";
				break;
			}
			case TOKEN_MIN:
			{
				return "MIN";
				break;
			}
			case TOKEN_MAX:
			{
				return "MAX";
				break;
			}
			case TOKEN_INC:
			{
				return "INC";
				break;
			}
			case TOKEN_DEC:
			{
				return "DEC";
				break;
			}
			case TOKEN_CAS:
			{
				return "CAS";
				break;
			}
			case TOKEN_EXCH:
			{
				return "EXCH";
				break;
			}
			case OPCODE_MOV:
			{
				return "OPCODE_MOV";
				break;
			}
			case TOKEN_VOLATILE:
			{
				return "VOLATILE";
				break;
			}
			case OPCODE_ST:
			{
				return "OPCODE_ST";
				break;
			}
			case OPCODE_CVT:
			{
				return "OPCODE_CVT";
				break;
			}
			case OPCODE_LD:
			{
				return "OPCODE_LD";
				break;
			}
			case TOKEN_SINGLE_CONSTANT:
			{
				return "SINGLE_CONSTANT";
				break;
			}
			case TOKEN_DECIMAL_CONSTANT:
			{
				return "DECIMAL_CONSTANT";
				break;
			}
			case TOKEN_DOUBLE_CONSTANT:
			{
				return "DOUBLE_CONSTANT";
				break;
			}
			case TOKEN_UNSIGNED_DECIMAL_CONSTANT:
			{
				return "UNSIGNED_DECIMAL_CONSTANT";
				break;
			}
			case OPCODE_BRA:
			{
				return "OPCODE_BRA";
				break;
			}
			case OPCODE_CALL:
			{
				return "OPCODE_CALL";
				break;
			}
			case OPCODE_RET:
			{
				return "OPCODE_RET";
				break;
			}
			case OPCODE_TRAP:
			{
				return "OPCODE_TRAP";
				break;
			}
			case OPCODE_BRKPT:
			{
				return "OPCODE_BRKPT";
				break;
			}
			case OPCODE_TEX:
			{
				return "OPCODE_TEX";
				break;
			}
			case OPCODE_SHL:
			{
				return "OPCODE_SHL";
				break;
			}
			case OPCODE_SHR:
			{
				return "OPCODE_SHR";
				break;
			}
			case OPCODE_AND:
			{
				return "OPCODE_AND";
				break;
			}
			case OPCODE_OR:
			{
				return "OPCODE_OR";
				break;
			}
			case OPCODE_XOR:
			{
				return "OPCODE_XOR";
				break;
			}
			case OPCODE_FMA:
			{
				return "FMA";
				break;
			}
			case OPCODE_MEMBAR:
			{
				return "MEMBAR";
				break;
			}
			case OPCODE_PMEVENT:
			{
				return "PMEVENT";
				break;
			}
			case TOKEN_UNI:
			{
				return "UNI";
				break;
			}
			case PREPROCESSOR_INCLUDE:
			{
				return "PREPROCESSOR_INCLUDE";
				break;
			}
			case PREPROCESSOR_DEFINE:
			{
				return "PREPROCESSOR_DEFINE";
				break;
			}
			case PREPROCESSOR_IF:
			{
				return "PREPROCESSOR_IF";
				break;
			}
			case PREPROCESSOR_IFDEF:
			{
				return "PREPROCESSOR_IFDEF";
				break;
			}
			case PREPROCESSOR_ELSE:
			{
				return "PREPROCESSOR_ELSE";
				break;
			}
			case PREPROCESSOR_ENDIF:
			{
				return "PREPROCESSOR_ENDIF";
				break;
			}
			case PREPROCESSOR_LINE:
			{
				return "PREPROCESSOR_LINE";
				break;
			}
			case PREPROCESSOR_FILE:
			{
				return "PREPROCESSOR_FILE";
				break;
			}
			case OPCODE_BARSYNC:
			{
				return "OPCODE_BARSYNC";
				break;
			}
			case OPCODE_ATOM:
			{
				return "OPCODE_ATOM";
				break;
			}
			case OPCODE_RED:
			{
				return "OPCODE_RED";
				break;
			}
			case OPCODE_VOTE:
			{
				return "OPCODE_VOTE";
				break;
			}
			case TOKEN_REG:
			{
				return "REG";
				break;
			}
			case TOKEN_SREG:
			{
				return "SREG";
				break;
			}
			case TOKEN_SURF:
			{
				return "SURF";
				break;
			}
			case TOKEN_CTA:
			{
				return "CTA";
				break;
			}
			case TOKEN_GL:
			{
				return "GL";
				break;
			}
			case TOKEN_CONST:
			{
				return "CONST";
				break;
			}
			case TOKEN_PARAM:
			{
				return "PARAM";
				break;
			}
			case TOKEN_LOCAL:
			{
				return "LOCAL";
				break;
			}
			case TOKEN_SHARED:
			{
				return "SHARED";
				break;
			}
			case TOKEN_GLOBAL:
			{
				return "GLOBAL";
				break;
			}
			case TOKEN_PRED:
			{
				return "PRED";
				break;
			}
			case TOKEN_TEX:
			{
				return "TEX";
				break;
			}
			case TOKEN_U32:
			{
				return "U32";
				break;
			}
			case TOKEN_S32:
			{
				return "S32";
				break;
			}
			case TOKEN_S8:
			{
				return "S8";
				break;
			}
			case TOKEN_S16:
			{
				return "S16";
				break;
			}
			case TOKEN_S64:
			{
				return "S64";
				break;
			}
			case TOKEN_U8:
			{
				return "U8";
				break;
			}
			case TOKEN_U16:
			{
				return "U16";
				break;
			}
			case TOKEN_U64:
			{
				return "U64";
				break;
			}
			case TOKEN_B8:
			{
				return "B8";
				break;
			}
			case TOKEN_B16:
			{
				return "B16";
				break;
			}
			case TOKEN_B32:
			{
				return "B32";
				break;
			}
			case TOKEN_B64:
			{
				return "B64";
				break;
			}
			case TOKEN_F16:
			{
				return "F16";
				break;
			}
			case TOKEN_F64:
			{
				return "F64";
				break;
			}
			case TOKEN_F32:
			{
				return "F32";
				break;
			}
			case OPCODE_COS:
			{
				return "OPCODE_COS";
				break;
			}
			case OPCODE_SQRT:
			{
				return "OPCODE_SQRT";
				break;
			}
			case OPCODE_ADD:
			{
				return "OPCODE_ADD";
				break;
			}
			case OPCODE_RSQRT:
			{
				return "OPCODE_RSQRT";
				break;
			}
			case OPCODE_ADDC:
			{
				return "OPCODE_ADDC";
				break;
			}
			case OPCODE_MUL:
			{
				return "OPCODE_MUL";
				break;
			}
			case OPCODE_SAD:
			{
				return "OPCODE_SAD";
				break;
			}
			case OPCODE_SUB:
			{
				return "OPCODE_SUB";
				break;
			}
			case OPCODE_EX2:
			{
				return "OPCODE_EX2";
				break;
			}
			case OPCODE_LG2:
			{
				return "OPCODE_LG2";
				break;
			}
			case OPCODE_RCP:
			{
				return "OPCODE_RCP";
				break;
			}
			case OPCODE_SIN:
			{
				return "OPCODE_SIN";
				break;
			}
			case OPCODE_REM:
			{
				return "OPCODE_REM";
				break;
			}
			case OPCODE_MUL24:
			{
				return "OPCODE_MUL24";
				break;
			}
			case OPCODE_MAD24:
			{
				return "OPCODE_MAD24";
				break;
			}
			case OPCODE_DIV:
			{
				return "OPCODE_DIV";
				break;
			}
			case OPCODE_ABS:
			{
				return "OPCODE_ABS";
				break;
			}
			case OPCODE_NEG:
			{
				return "OPCODE_NEG";
				break;
			}
			case OPCODE_MIN:
			{
				return "OPCODE_MIN";
				break;
			}
			case OPCODE_MAX:
			{
				return "OPCODE_MAX";
				break;
			}
			case OPCODE_MAD:
			{
				return "OPCODE_MAD";
				break;
			}
			case OPCODE_SET:
			{
				return "OPCODE_SET";
				break;
			}
			case OPCODE_SETP:
			{
				return "OPCODE_SETP";
				break;
			}
			case OPCODE_SELP:
			{
				return "OPCODE_SELP";
				break;
			}
			case OPCODE_NOT:
			{
				return "OPCODE_NOT";
				break;
			}
			case OPCODE_SLCT:
			{
				return "OPCODE_SLCT";
				break;
			}
			case OPCODE_CNOT:
			{
				return "OPCODE_CNOT";
				break;
			}
			case ',':
			{
				return ",";
				break;
			}
			case ';':
			{
				return ";";
				break;
			}
			case '.':
			{
				return ".";
				break;
			}
			case '{':
			{
				return "{";
				break;
			}
			case '}':
			{
				return "}";
				break;
			}
			case '[':
			{
				return "[";
				break;
			}
			case ']':
			{
				return "]";
				break;
			}
			case '(':
			{
				return "(";
				break;
			}
			case ')':
			{
				return ")";
				break;
			}
			case '+':
			{
				return "+";
				break;
			}
			case '<':
			{
				return "<";
				break;
			}
			case '>':
			{
				return ">";
				break;
			}
			case '=':
			{
				return "=";
				break;
			}
			case '-':
			{
				return "-";
				break;
			}
			case '_':
			{
				return "_";
				break;
			}
			default:
			{
				return "INVALID";
			}
		}
		
		return "";
	}
}

#endif


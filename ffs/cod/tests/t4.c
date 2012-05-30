#include "config.h"
#include "cod.h"
#include "assert.h"
#include <stdio.h>

int
main()
{
    {
	/* test the basics */
	char code_string[] = "\
{\n\
    static int j = 4;\n\
    static long k = 10;\n\
    static hort l = 3;\n\
\n\
    j = j + 1;\n\
    k = k + 2;\n\
/*    l = l + 3;*/\n\
\n\
    return j + k/* + l*/;\n\
}";

	cod_parse_context context = new_cod_parse_context();
	int ret;

	ret = cod_code_verify(code_string, context);
	assert(ret == 0);
	cod_free_parse_context(context);
    }

    {

	/* test the ability to have a parameter */
	char code_string[] = "\
{\n\
    static int j = 4;\n\
    static long k = 10;\n\
    static short l = 3;\n\
\n\
    return l.l * (j + k + i.j);\n\
}";

	cod_parse_context context = new_cod_parse_context();
    	int ret;

	cod_subroutine_declaration("int proc(int i)", context);
	ret = cod_code_verify(code_string, context);
	assert(ret == 0);
	cod_free_parse_context(context);
    }
    {
	/* structured types */
	char code_string[] = "\
{\n\
    return input * (input.j + input.k + input.m);\n\
}";
	char code_string2[] = "\
{\n\
    return input * (output.j + input.k + input.m);\n\
}";

	char code_string3[] = "\
{\n\
    return input * (input.j + input.k + input.i);\n\
}";
	char code_string4[] = "\
{\n\
     input = 5;\n\
    return 2;\n\
}";
	char code_string5[] = "\
{\n\
     void int j = 5;\n\
    return 2;\n\
}";
	char code_string6[] = "\
{\n\
     string int j = 5;\n\
    return 2;\n\
}";

	char code_string7[] = "\
{\n\
     long short j = 5;\n\
    return 2;\n\
}";

	char code_string8[] = "\
{\n\
     unsigned signed int j = 5;\n\
    return 2;\n\
}";

	char code_string9[] = "\
{\n\
     short double j = 5;\n\
    return 2;\n\
}";

	char code_string10[] = "\
{\n\
     short float j = 5;\n\
    return 2;\n\
}";

	char code_string11[] = "\
{\n\
     long float int j = 5;\n\
    return 2;\n\
}";

	char code_string12[] = "\
{\n\
     float j = 5.0;\n\
    return 2 && j;\n\
}";

	char code_string13[] = "\
{\n\
     int j;\n\
    return j();\n\
}";

	char code_string14[] = "\
{\n\
    return j();\n\
}";

	char code_string15[] = "\
{\n\
    short char j;\n\
    return 1;\n\
}";

	char code_string16[] = "\
{\n\
    int j;\n\
    int j;\n\
    return 1;\n\
}";

	char code_string17[] = "\
{\n\
/*\n\
a long\n\
comment\n\
*/\n\
     static int j = input.i;\n\
}";

	char code_string18[] = "\
{\n\
     int j = input.i[14];\n\
     return 1;\n\
}";

	char code_string19[] = "\
{\n\
/*\n\
a long\n\
comment\n\
*/\n\
     string j = \" stuff here \n\";\
     return 1;\n\
}";

	char code_string20[] = "\
{\n\
     string j = \"\\406\";\n\
     return 1;\n\
}";

	char code_string21[] = "\
{\n\
     string j = \"\\948\";\n\
     return 1;\n\
}";

	char code_string22[] = "\
{\n\
     int *pi = 3.14;\n\
     return 1;\n\
}";

	typedef struct test {
	    int i;
	    int j;
	    long k;
	    short l;
	} test_struct, *test_struct_p;

	FMField struct_fields[] = {
	    {"i", "integer", sizeof(int), FMOffset(test_struct_p, i)},
	    {"j", "integer", sizeof(int), FMOffset(test_struct_p, j)},
	    {"k", "integer", sizeof(long), FMOffset(test_struct_p, k)},
	    {"l", "integer", sizeof(short), FMOffset(test_struct_p, l)},
	    {(void*)0, (void*)0, 0, 0}};

    	int ret;
	cod_parse_context context = new_cod_parse_context();

	cod_add_struct_type("struct_type", struct_fields, context);
	cod_subroutine_declaration("void proc(struct_type *input)", context);

	ret = cod_code_verify(code_string, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string2, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string3, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string4, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string5, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string6, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string7, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string8, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string9, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string10, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string11, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string12, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string13, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string14, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string15, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string16, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string17, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string18, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string19, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string20, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string21, context);
	assert(ret == 0);
	ret = cod_code_verify(code_string22, context);
	assert(ret == 0);
	cod_free_parse_context(context);
    }
    {
	static char extern_string[] = "int printf(string format, ...);";

#ifndef PRINTF_DEFINED
	extern int printf();
#endif
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {(void*)0, (void*)0}
	};
	int ret;
	/* test external call */
	static char code[] = "{\
			printf(\"values are is %d, %g\\n\", i, d);\
		}";

	static char code2[] = "{\
			printf(i, \"values are is %d, %g\\n\", i, d);\
		}";

	cod_parse_context context = new_cod_parse_context();

	cod_parse_for_context(extern_string, context);

	cod_subroutine_declaration("int proc(int i, double d)", context);

	ret = cod_code_verify(code, context);
	assert (ret == 0);
	cod_free_parse_context(context);

	context = new_cod_parse_context();

	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);

	cod_subroutine_declaration("int proc(int i, double d)", context);

	ret = cod_code_verify(code2, context);
	assert (ret == 0);
	cod_free_parse_context(context);
    }
    {
	static char extern_string[] = "int junk(int i, float j);";
#ifndef PRINTF_DEFINED
	extern int printf();
#endif

	static cod_extern_entry externs[] = 
	{
	    {"junk", (void*)(long)printf},
	    {(void*)0, (void*)0}
	};
	int ret;
	/* test external call */
	static char code[] = "{\
			junk(1, 3.5, 4);\
		}";

	cod_parse_context context = new_cod_parse_context();
	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);

	cod_subroutine_declaration("int proc(int i, double d)", context);

	ret = cod_code_verify(code, context);
	assert (ret == 0);
	cod_free_parse_context(context);

    }

    {
	static char code[] = "{\n\
		    int i;\n\
		    int j;\n\
		    double sum = 0.0;\n\
		    double average = 0.0;\n\
		    for(i = 0; i<37; i= i+1) {\n\
		        for(j = 0; j<253; j=j+1) {\n\
			sum = sum + input.levels[sum];\n\
			sum = sum + input.levels;\n\
		        }\n\
		    }\n\
		    average = sum / (37 * 253);\
		    return average;\
		}";

	static FMField input_field_list[] =
	{
	    {"levels", "float[253][37]", sizeof(double), 0},
	    {(void*)0, (void*)0, 0, 0}
	};

	cod_parse_context context = new_cod_parse_context();
	int ret;

	cod_add_struct_type("input_type", input_field_list, context);
	cod_subroutine_declaration("int proc(input_type *input)", context);

	ret = cod_code_verify(code, context);
	assert(ret == 0);
	cod_free_parse_context(context);
    }

    {
        /*
         * test operators inapplicable to pointers and operator
         * arguments mixing pointers w/ incompatible other arguments
         */

        char code_string[] ="\
{\n\
    int * p;\n\
    int * q;\n\
    long * r;\n\
    int i;\n\
    float f;\n\
    double d;\n\
\n\
    /* unary plus/minus */\n\
    p = - q;\n\
    p = + q;\n\
\n\
    /* pointer addition */\n\
    p = p + q;\n\
    /* subtraction of mismatching type of pointers */\n\
    p = p - r;\n\
\n\
    /* arithmetic between pointers and floating point numbers */\n\
    p = p + f;\n\
    p = p - f;\n\
    p = p + d;\n\
    p = p - d;\n\
\n\
    /* disallowed operators: modulus, all bitwise ops, shifts */\n\
    p = p % i;\n\
    p = p | i;\n\
    p = p ^ i;\n\
    p = p & i;\n\
    p = p >> 1;\n\
    p = p >> i;\n\
    p = p << 1;\n\
    p = p << i;\n\
    return 1;\n\
}";

	cod_parse_context context = new_cod_parse_context();
	int ret;

	ret = cod_code_verify(code_string, context);
	assert(ret == 0);
	cod_free_parse_context(context);
    }

    {
        /*
         * tests validity of address operator's operand
         */

        char code_string[] ="\
{\n\
    return &(2+3);\n\
}";

	cod_parse_context context = new_cod_parse_context();
	int ret;

	ret = cod_code_verify(code_string, context);
	assert(ret == 0);
	cod_free_parse_context(context);
    }

    return 0;
}

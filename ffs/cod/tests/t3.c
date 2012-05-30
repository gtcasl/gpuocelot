#include "config.h"
#include "cod.h"
#include "assert.h"
#include <stdio.h>

static double testd(){return 1.0;}

#ifdef NO_EMULATION
#define GEN_PARSE_CONTEXT(x) \
x = new_cod_parse_context();
#define EC_param0
#define EC_param1
#else
#define GEN_PARSE_CONTEXT(x) \
x = new_cod_parse_context();\
cod_add_param("ec", "cod_exec_context", 0, x);
#define EC_param0 ec
#define EC_param1 ec,
#endif

int
main(int argc, char **argv)
{
    int test_to_run = -1;
    if (argc > 1) {
	sscanf(argv[1], "%d", &test_to_run);
    }

    if ((test_to_run == 1) || (test_to_run == -1)) {
	/* test the basics */
	char code_string[] = "\
{\n\
    static int j = 4;\n\
    static long k = 10;\n\
    static short l = 3;\n\
    static int m = 0;\n\
\n\
    j = j + 1;\n\
    k = k + 2;\n\
    l = l + 3;\n\
\n\
    return j + k + l + m;\n\
}";

	cod_parse_context context;
	cod_exec_context ec;
	static char extern_string[] = "int printf(string format, ...);";
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {(void*)0, (void*)0}
	};
	cod_code gen_code;
	long ret;
	long (*func)();

	GEN_PARSE_CONTEXT(context);
	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);
	gen_code = cod_code_gen(code_string, context);
	ec = cod_create_exec_context(gen_code);
	func = (long(*)()) (long) gen_code->func;
	ret = func(EC_param0);
	assert(ret == 23);
	ret = func(EC_param0);
	assert(ret == 29);
	ret = func(EC_param0);
	assert(ret == 35);
	cod_exec_context_free(ec);
	cod_code_free(gen_code);
	cod_free_parse_context(context);
    }

    if ((test_to_run == 2) || (test_to_run == -1)) {

	/* test the ability to have a parameter */
	char code_string[] = "\
{\n\
    static int j = 4;\n\
    static long k = 10;\n\
    static short l = 3;\n\
\n\
    return l * (j + k + i);\n\
}";

	cod_parse_context context = new_cod_parse_context();
	cod_exec_context ec;
	cod_code gen_code;
    	long (*func)();

#ifdef NO_EMULATION
	cod_subroutine_declaration("int proc(int i)", context);
#else
	cod_subroutine_declaration("int proc(cod_exec_context ec, int i)", context);
#endif
	gen_code = cod_code_gen(code_string, context);
	ec = cod_create_exec_context(gen_code);
	func = (long(*)(int)) (long) gen_code->func;
        assert(func(EC_param1 15) == 87);
	cod_exec_context_free(ec);
	cod_code_free(gen_code);
	cod_free_parse_context(context);
    }

    if ((test_to_run == 3) || (test_to_run == -1)) {
	/* structured types */
	char code_string[] = "\
{\n\
    return input.l * (input.j + input.k + input.i);\n\
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

	cod_parse_context context = new_cod_parse_context();
	cod_exec_context ec;
	test_struct str;
	cod_code gen_code;
	long (*func)();

	cod_add_struct_type("struct_type", struct_fields, context);
#ifdef NO_EMULATION
	cod_subroutine_declaration("int proc(struct_type *input)", context);
#else
	cod_subroutine_declaration("int proc(cod_exec_context ec, struct_type *input)", context);
#endif

	gen_code = cod_code_gen(code_string, context);
	ec = cod_create_exec_context(gen_code);
	func = (long(*)(test_struct_p)) (long) gen_code->func;

	str.i = 15;
	str.j = 4;
	str.k = 10;
	str.l = 3;
	assert(func(EC_param1 &str) == 87);
	cod_exec_context_free(ec);
	cod_code_free(gen_code);
	cod_free_parse_context(context);
    }
    if ((test_to_run == 4) || (test_to_run == -1)) {
	/* structured types */
	static char extern_string[] = "int printf(string format, ...);";
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {(void*)0, (void*)0}
	};
char code_string[] = {"\
  {\n\
    static int localSum = 0;\n\
    localSum = localSum + input.i;\n\
    input.i = localSum;\n\
    return 1;\n\
  }\n\
"};
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

	cod_parse_context context = new_cod_parse_context();
	cod_exec_context ec;
	test_struct str;
	cod_code gen_code;
	long (*func)();

	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);

	cod_add_struct_type("struct_type", struct_fields, context);
#ifdef NO_EMULATION
	cod_subroutine_declaration("int proc(struct_type *input)", context);
#else
	cod_subroutine_declaration("int proc(cod_exec_context ec, struct_type *input)", context);
#endif

	gen_code = cod_code_gen(code_string, context);
	ec = cod_create_exec_context(gen_code);
	func = (long(*)(test_struct_p)) (long) gen_code->func;

	str.i = 15;
	str.j = 4;
	str.k = 10;
	str.l = 3;
	func(EC_param1 &str);
	assert(func(EC_param1 &str) == 1);
	cod_exec_context_free(ec);
	cod_code_free(gen_code);
	cod_free_parse_context(context);
    }
    if ((test_to_run == 5) || (test_to_run == -1)) {
	static char extern_string[] = "int printf(string format, ...);";
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {(void*)0, (void*)0}
	};
	static char code[] = "{\
		    int i;\
		    int j;\
		    double sum = 0.0;\
		    double average = 0.0;\
		    for(i = 0; i<37; i= i+1) {\
		        for(j = 0; j<253; j=j+1) {\
			sum = sum + input.levels[j][i];\
		        }\
		    }\
		    average = sum / (37 * 253);\
		    return average;\
		}";

	static FMField input_field_list[] =
	{
	    {"levels", "float[253][37]", sizeof(double), 0},
	    {(void*)0, (void*)0, 0, 0}
	};

	cod_parse_context context = new_cod_parse_context();
	cod_exec_context ec;
	int i, j;
	double levels[253][37], result;
	cod_code gen_code;
	double (*func)();


	cod_add_struct_type("input_type", input_field_list, context);
#ifdef NO_EMULATION
	cod_subroutine_declaration("double proc(input_type *input)", context);
#else
	cod_subroutine_declaration("double proc(cod_exec_context ec, input_type *input)", context);
#endif

	for(i=0; i< 253; i++) {
	    for (j=0; j< 37; j++) {
	        levels[i][j] = i + 1000*j;
	    }
	}

	gen_code = cod_code_gen(code, context);
	ec = cod_create_exec_context(gen_code);
	func = (double (*)(double*))(long) gen_code->func;
	result = (func)(EC_param1 &levels[0][0]);
	if (result != 18126.00) {
	    printf("Expected %g, got %g\n", 18126.0, result);
	}
	cod_exec_context_free(ec);
	cod_code_free(gen_code);
	cod_free_parse_context(context);
    }
    if ((test_to_run == 6) || (test_to_run == -1)) {
	static char extern_string[] = "int printf(string format, ...);\
					double testd();";
	static cod_extern_entry externs[] = 
	{
	    {"testd", (void*)(long)testd},
	    {"printf", (void*)(long)printf},
	    {(void*)0, (void*)0}
	};
	static char code[] = "{\
				   double b = testd();\n\
				   return b;\
		}";

	cod_parse_context context = new_cod_parse_context();
	cod_exec_context ec;
	int i, j;
	double levels[253][37], result;
	cod_code gen_code;
	double (*func)();

	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);

#ifdef NO_EMULATION
	cod_subroutine_declaration("double proc()", context);
#else
	cod_subroutine_declaration("double proc(cod_exec_context ec)", context);
#endif
	gen_code = cod_code_gen(code, context);
	ec = cod_create_exec_context(gen_code);
	func = (double (*)())(long) gen_code->func;
	result = (func)(EC_param0);
	if (result != 1.0) {
	    printf("Expected %g, got %g\n", 1.0, result);
	}
	cod_exec_context_free(ec);
	cod_code_free(gen_code);
	cod_free_parse_context(context);
    }

    if ((test_to_run == 7) || (test_to_run == -1)) {
	/* test static arrays */
	char code_string[] = "\
{\n\
    static int n[4];\n\
    if (n[0] + n[1] + n[2] + n[3] == 0) {\n\
        /* first time */\n\
        n[0] = 4;\n\
        n[1] = 10;\n\
        n[2] = 3;\n\
        n[3] = 0;\n\
    }\n\
    n[0] = n[0] + 1;\n\
    n[1] = n[1] + 2;\n\
    n[2] = n[2] + 3;\n\
    return n[0] + n[1] + n[2] + n[3];\n\
}";

	cod_parse_context context;
	cod_exec_context ec;
	static char extern_string[] = "int printf(string format, ...);";
	static cod_extern_entry externs[] = 
	{
	    {"printf", (void*)(long)printf},
	    {(void*)0, (void*)0}
	};
	cod_code gen_code;
	long (*func)();
	int ret;

	GEN_PARSE_CONTEXT(context);
	cod_assoc_externs(context, externs);
	cod_parse_for_context(extern_string, context);
	gen_code = cod_code_gen(code_string, context);
	ec = cod_create_exec_context(gen_code);
	func = (long(*)()) (long) gen_code->func;
	assert(func(EC_param0) == 23);
	assert(func(EC_param0) == 29);
	assert(func(EC_param0) == 35);
	cod_exec_context_free(ec);
	cod_code_free(gen_code);
	cod_free_parse_context(context);
    }

    return 0;
}

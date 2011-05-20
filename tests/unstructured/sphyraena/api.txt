
Sphyraena API

Written Spring 2010 by Peter Brownlee Bakkum (pbb7c@virginia.edu)

--------
Overview
--------

The Sphyraena API is built on top of SQLite, and we have attempted to conform
to the style of C development used in SQLite. The state of the library is
held in the sphyraena data struct, and passed to each API function, as in 
SQLite. SQLite should be initialized and cleaned up independently of Sphyraena.
An example program using the API is provided below, with detailed documentation
about all the functions and data structures you will need, and the error codes
you may encounter. The most important compile-time variables are documented,
and can be tweaked to improve performance for specific queries. There are a
number of undocumented aspects of this program that represent decisions made
during implementation and may affect performance for a certain application in
some way, so further manipulation of Sphyraena can be done at a level below the
API, though this will certainly be more difficult.

The API is intended for research purposes rather than production database use.
As discussed, it only performs read-only queries once data has been explicitly
loaded on to the GPU. However, if your application involves multiple queries
over large data sets in SQLite, it should be very easy to add the API to your
code and achieve significant acceleration.

-------
Example
-------

This example demonstrates the C code necessary to open a SQLite database and
execute a simple query on the GPU. It is documented with comments but more
information on each step can be found in the API documentation. This example
assumes that the sphyraena.h header file has been included. Understanding
it also assumes some knowledge of the SQLite API, which is documented on the
SQLite website.

sqlite3 *db;
sphyraena sphy;

// initialize SQLite using dbfile.db as the database file
sqlite3_open("dbfile.db", &db);

// initialize Sphyraena with data and results blocks of 10 MB and using pinned
// 	memory
sphyraena_init(&sphy, db, 10485760, 10485760, 1);

// transform the data in test_table to row-column format so that it can be
//	quickly moved to the GPU
sphyraena_prepare_data(&sphy, "SELECT * FROM test_table");

// move the data from main memory to GPU memory
sphyraena_transfer_data(&sphy);

// execute a query on the GPU, without using streaming
sphyraena_select(&sphy, 
	"SELECT column1, column2 FROM test_table WHERE column1 < column2", 0);

// transfer the results of the query from the GPU to main memory
sphyraena_transfer_results(&sphy);

// get data from the tenth row and second column of the results.
sphyraena_results *res = sphy->results_cpu;
int value = ((int*)(res->r + 10 * res->stride + res->offsets[1]))[0];

---------
Functions
---------

This is a list of all the functions needed to execute queries on the GPU, in no
particular order. The function declaration is given, followed by a description
of the functions action and a list describing each argument and the return 
value of each function.

  int sphyraena_init(
	sphyraena *s,
	sqlite3 *db,
	size_t data_size,
	size_t results_size,
	int pinned_memory );

This function is used to initialize the Sphyraena library, and needs to
be called before any other functions. This should be called with a valid
sqlite3* variable, meaning after sqlite3_open() has been called.

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	* db - A pointer to the sqlite3 object associated with the SQLite
	instance initialized.

	* data_size - The size in bytes of the data block used to store data
	selected from SQLite for GPU execution. This block is allocated in both
	main and GPU memory, and should be larger than the size of the data
	you want to select.

	* results_size - The size of the results storage block, allocated in
	both main and GPU memory.

	* pinned_memory - An integer value indicating whether or not to use
	pinned memory when allocating the data and results blocks. Pinned
	memory enables 2x faster memory transfers to and from the GPU, but
	comes with some restrictions. For example: if you allocate 80% of your
	memory as pinned, you will probably lock your machine, assuming your
	OS even allows the allocation.

	return value: an int with a value of SPHYRAENA_SUCCESS indicating a
	successful execution or any of SPHYRAENA_ERR_* for an unsuccessful
	execution.



  int sphyraena_cleanup(
	sphyraena *s );

This function frees the memory allocations made by the sphyraena_init()
function. It has no effect on the state of SQLite.

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	return value: an int with a value of SPHYRAENA_SUCCESS indicating a
	successful execution or any of SPHYRAENA_ERR_* for an unsuccessful
	execution.



  int sphyraena_prepare_data(
	sphyraena *s,
	const char* sql_stmt );

This function selects data from SQLite and loads it into the Sphyraena main
memory data block. Since SQLite stores this data in B+Tree format, this step
is the most expensive part of staging data to the GPU, where it is stored in
row-column format. The data is selected with a SQL statement, so to prepare an
entire table for GPU execution use "SELECT * FROM tablename". You must call
this before sphyraena_transfer_data().

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	* sql_stmt - The SELECT statement used to select records from a SQLite
	table which is prepared by moving it into Sphyraena memory.

	return value: an int with a value of SPHYRAENA_SUCCESS indicating a
	successful execution or any of SPHYRAENA_ERR_* for an unsuccessful
	execution.

	

  int sphyraena_transfer_data(
	sphyraena *s );

Transfers data from from the main memory data block to the GPU data block. This
is relatively quick, especially with pinned memory. Note that if
sphyraena_select(), is called with streaming set to 1, then this step does not
need to be performed.

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	return value: an int with a value of SPHYRAENA_SUCCESS indicating a
	successful execution or any of SPHYRAENA_ERR_* for an unsuccessful
	execution.



  int sphyraena_transfer_results(
	sphyraena *s );

Transfers data from the results block of GPU memory to the results block of
main memory. As with sphyraena_transfer_data(), this step is fairly quick,
especially with pinned memory. This function still needs to be called with
a streaming select of data, however. Note that this is a two-step procedure,
we first contact the GPU to discover the size of the results block, since this
varies with the query and data-set. Next we perform the actual transfer. This
means that transfers for smaller results blocks will be faster, particularly
for results of size 0, in which case only 1 transfer is needed.

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	return value: an int with a value of SPHYRAENA_SUCCESS indicating a
	successful execution or any of SPHYRAENA_ERR_* for an unsuccessful
	execution.



  int sphyraena_select(
	sphyraena *s,
	const char* sql_stmt,
	int streaming );

This function performs GPU query execution. Only a subset of SELECT queries can
be used. This subset includes specifying the columns selected, math operations
such as equality and inequality and operations, logical operations, and several
aggregate operations (i.e. COUNT, MIN, MAX, SUM, AVG). Joins and groups are not
supported, and you may encounter problems with more complex combinations of
these, such as using multiple aggregate operations in the same query, because
of how thread-block synchronization is performed. There are a number of 
arbitrary limits to queries and data blocks, such as the number of columns
that can be used, and the complexity of the query, because there are limited
allocations for these on the GPU. Many of these limitations can be changed by
tweaking the compile-time variables in sphyraena.h, but these may affect
performance.

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	* sql_stmt - The SQL statement being executed.

	* streaming - An int value with 1 or 0 to turn streaming on or off,
	respectively. Streaming overlaps data transfer with query execution,
	and means that sphyraena_transfer_data() does not need to be called
	before this function. Streaming is probably only faster for very large
	data sets.

	return value: an int with a value of SPHYRAENA_SUCCESS indicating a
	successful execution or any of SPHYRAENA_ERR_* for an unsuccessful
	execution.



  int sphyraena_print_results(
	sphyraena *s,
	int n );

This function prints the first n rows of the results set. This should only be
called after a query has been executed and the result set has been transferred
back from the GPU.

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	* n - The maxixmum number of rows to print. This function will stop if
	the result set contains less than this number.

	return value: none



  int sphyraena_vm(
	sphyraena *s );

This function is called by sphyraena_select() and directly calls the kernel.
It is located in vm.cu, and consequently compiled by gcc through nvcc. This
function should not be directly called under normal API use.

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	return value: an int with a value of SPHYRAENA_SUCCESS indicating a
	successful execution or any of SPHYRAENA_ERR_* for an unsuccessful
	execution.



  int sphyraena_vm_streaming(
	sphyraena *s );

This function is exactly like sphyraena_vm, except it implements streaming.
It is also called by sphyraena_select(), based on whether or not its streaming
argument is set to 1.

	* s - A pointer to a sphyraena struct, used to store the state of the
	library.

	return value: an int with a value of SPHYRAENA_SUCCESS indicating a
	successful execution or any of SPHYRAENA_ERR_* for an unsuccessful
	execution.




----------
Data Types
----------

Because multiple numeric data types are supported, it is necessary to keep
track of the type of data in a particular column. These types are stored as
ints. You can check values by using our defined variables. 

  SPHYRAENA_INT
  SPHYRAENA_INT64
  SPHYRAENA_FLOAT
  SPHYRAENA_DOUBLE


----------------------
Compile-time Variables
----------------------

Sphyraena has a number of variables that are used at compile time to define
certain operational parameters. Most have been loosely optimized through
experimentation, but you may be able to increase performance on specific
queries by tweaking these variables. They are all found in the sphyraena.h
header file.


  SPHYRAENA_MAX_OPS

Defines the maximum number of SQLite opcodes that can be included in a program.
This variable controls the size of the program information block that is sent
to the GPU and stored in constant memory. Simple and medium complexity queries
should have no trouble fitting in this block.


  SPHYRAENA_MAX_COLUMNS

Defines the maximum number of table columns that can be included in the table
loaded onto the GPU. This is important because each column data type and byte
width must be tracked. This information is also stored in the constant memory
block of the GPU.


  SPHYRAENA_REGISTERS

Defines the maximum number of SQLite registers that can be used in a query.
This is similar to the max ops variable in that simple queries should have no
trouble fitting into this many registers.


  SPHYRAENA_GLOBAL_REGISTERS

A set of separate SQLite registers used for global synchronization among
threadblocks. These are used primarily for the aggregation functions, which
require extensive coordination among threadblocks.


  SPHYRAENA_THREADSPERBLOCK

The standard CUDA number of threads per threadblock. The default is 192
threads, but there are probably other optima depending upon the characteristics
of the query, including the processing time per row and the number of result
rows. Remember that this number should be a multiple of a larger power of 2.
This variable is loaded into the sphyraena state struct during sphyraena_init()
and can thus be changed at run time.


  SPHYRAENA_STREAMWIDTH

The number of sections that the program should be split into when using
streaming. Like the threads per block variable, this variable can be tweaked
at run time, and probably has separate optima for specific queries.


---------------
Data Structures
---------------

This is a short list of the data structures that you may want or need to
manipulate to run queries. There are a number of other data structure used in
the library, but they are not necessary to directly use if an application only
runs queries through the API.


  struct sphyraena {
	sqlite3 *db;
	sphyraena_data *data_cpu;
	char *data_gpu;
	sphyraena_results *results_cpu;
	sphyraena_results *results_gpu;
	sphyraena_stmt *stmt_cpu;
	size_t data_size;
	size_t results_size;
	int pinned_memory;
	int threads_per_block;
	int stream_width;
  };

This is the primary data structure used to store the state of Sphyraena. All
of the variables in this struct are set by the sphyraena_init() function, and
other than the last two, should probably not be altered at run time. This
reference is provided because of these last two variables, and because you may
want to build the individual components yourself for more advanced query
manipulation outside the scope of the API. Note that this can be declared
directly as sphyraena statevar, without the struct keyword.


	* db - A pointer to the state struct used by SQLite. This is 
	initialized with the sqlite3_open() function.

	* data_cpu - A pointer to the structure used to manage the data block
	in main memory. The sphyraena_data struct is very similar to the 
	sphyraena_results struct, and is initialized with data when the 
	sphyraena_prepare_data() function is called.

	* data_gpu - A pointer to the data block on the GPU. The
	sphyraena_transfer_data() function moves data from the block in the
	data_cpu struct to this data block, moving the meta data to the GPU's
	constant memory rather than storing it next to the data block. Note
	that this pointer has no meaning on the CPU, it points to device
	memory.

	* results_cpu - A pointer to the struct that holds query results in
	main memory. This struct is not initialized until a call to 
	sphyraena_transfer_results().

	* results_gpu - A pointer to the struct that holds query results in
	GPU memory. As with the data_gpu pointer, this pointer has no meaning
	on the CPU.

	* data_size - This variable stores the total amount of memory allocated
	for the data block. This memory has been allocated on both the CPU and
	the GPU.

	* results_size - Like data_size but for the results block. Note that
	these blocks can have arbitrarily different sizes.

	* pinned_memory - A variable with a value of 1 if the data and results
	blocks have been allocated using pinned memory and 0 otherwise.

	* threads_per_block - The number of threads run per block when the
	query execution kernel is called. This can be tweaked at run-time.

	* stream_width - The number of blocks that the memory transfer and
	kernel launch should be broken into when using the streaming feature.



  struct sphyraena_results {
	int rows;
	int columns;
	int stride;
	int types[];
	int offsets[];
	char r[];
  };


This struct is how the results block is stored, and using it is necessary to
access the returned results. This is accessed through the sphyraena object,
and will not be initialized until after sphyraena_transfer_results() has been
called. The data is stored in a single block, which the r[] array begins. Note
that because data types of different sizes are used, you need to use the stride
and offsets variables to find the location of a particular piece of data. For
example, to access the third column in the fifth row of results, you would look
at r[5 * stride + offsets[2]];


	* rows - An integer representing the number of rows in the result set.

	* columns - An integer denoting the number of columns in the result 
	set.

	* stride - The width in bytes of a single row of results.

	* types[] - An array of integers which represent the type of data in
	each column. These values are described in the Data Types section.

	* offset[] - The difference in bytes between the beginning of the row
	and each column. 

	* r[] - The beginning of the actual results data block.



-----------
Error Codes
-----------
These are compile-time integer values that are returned from certain functions
in the event of normal execution or an error. Note that certain error codes
can be returned only by certain functions.

  SPHYRAENA_SUCCESS

This is the standard return values, and indicates successful execution.


  SPHYRAENA_ERR_MEM

This indicates a failed memory allocation on the host-side.


  SPHYRAENA_ERR_STMT

This indicates that there was a problem with the SQL statement used to select
data in sphyraena_prepare_data(). This will get returned if the query failed or
if it returned zero rows.


  SPHYRAENA_ERR_CUDAMEMCPY

Indicates a failed memory copy in either sphyraena_transfer_data() or
sphyraena_transfer_results(). Check that cleanup has not been called and that
the memory has not been freed for some other reason.


  SPHYRAENA_ERR_CUDAMALLOC

This indicates a failed memory allocation on the GPU. To troubleshoot this,
check both the sizes of allocations you have chosen and if other programs are
using the GPU.


  SPHYRAENA_ERR_DEVICE

This is returned when a CUDA capable device can not be found and selected by
sphyraena_init(). Check that the device is installed properly and that
Sphyraena knows where the drivers are.


  SPHYRAENA_ERR_CUDAFREE

This is returned when GPU-side memory can not be freed in sphyraena_cleanup().


  SPHYRAENA_ERR_CUDAFREEHOST

This is returned when pinned memory on the host side can not be freed in
sphyraena_cleanup().


  SPHYRAENA_ERR_KERNEL

This indicates that the CUDA kernel that handles query execution has failed for
some reason, and the query has not been completely executed. This could be the
result of a badly formed query, a query that is too complex, a device that is
busy with something else, a bug in the code, or a device of insufficient
compute capability. We recommend that you try executing again before digging
deeper, and even try rebooting. We have seen situations where previous kernels
have failed, and affect query execution for some reason. It is also possible
for cards to get wedged, in which case they either refuse to execute kernels or
never return from kernel executions, in which case a reboot is the only fix. 
This could also be an indication that the query being executed is not
supported in our code, although these queries won't necessarily fail, they are
more likely to complete execution with incorrect results.


  SPHYRAENA_ERR_TYPE

This indicates that you have tried to select an unsupported data type in
sphyraena_prepare_data(). Sphyraena only supports 32 and 64 bit ints and 
floats.

 

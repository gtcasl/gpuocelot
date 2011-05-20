


SPHYRAENA DATABASE

Written Spring 2010 by Peter Brownlee Bakkum (pbb7c@virginia.edu)


LICENSE

This code is currently under copyright by Peter Brownlee Bakkum. Permission is
provided to use the code and documentation for research only.


Disclaimer

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES, 
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


About

This is an API for executing certain SQLite queries on NVIDIA GPUs. This is 
intended exclusively for research purposes, and we make no guarantees about
the performance. This said, with a Unix machine and a recent NVIDIA card,
you should be able to execute SELECT queries on tables with 10,000+ records
anywhere between 30 to 100x faster. These results were published and presented
in the General Purpose Graphics Processing Units Workshop at the Architectural
Support For Programming Languages and Operating Systems 2010 Conference under
the title "Accelerating SQL Database Operations on a GPU with CUDA". The paper
(under ACM copyright) is available at http://pbbakkum.com/db .

This document contains a description of the environment used to test the
project, instructions for making and running it, instructions for generating
data sets similar to the ones used in testing, and general suggestions for
getting a working build. A description of the actual programming API can be
found in the api.txt document in the same directory as this file. Questions, 
suggestions, etc. should be sent to pbb7c@virginia.edu.


Environment

This project was written and tested on several Ubuntu Linux 2.6 machines with
Intel processors. We used CUDA 2.2, 2.3, and 3.0, and a Tesla C1060 and a GTX
280. We used gcc 4.2 for debug builds and icc 11.1 release builds, and SQLite 
3.6.22 was used. Like SQLite, this project has been developed with C. It can
probably be compiled in C and linked with C++, but we have not attempted this.

As stated, this library is provided for research purposes, and we have not
tested on any machines other than those used for development. You should be
able to get the library working on any Unix machine with a relatively recent
NVIDIA GPU. Running on Windows will probably be a little bit more difficult,
but we have not attempted this and can't speak to the effort required.


Building

As stated, we have not had time to test this project outside the development
environment. Consequently, we only have our own very simple makefiles, and 
have not provided a way to build a shared object library or such, so the best
way to add this code to your own project is to compile it directly with the
source, as you would with SQLite. All of our source files are in the 
sphyraena/ directory. Assuming a compiler similar to GCC and your CUDA paths
set up correctly, you should have little trouble with this approach.

If you would like to duplicate our test build, we have provided our Makefiles
and driver to make this as painless as possible. Below are instructions for
setting up the scripts and duplicating our tests.

	1. Go to the sphyraena/ directory and open Makefile. You will probably
	need to edit the CUDA variable, to point to the directory where you
	have installed CUDA. You may also need to change the CUDA_LIBRARY
	variable to lib64 if you want to compile for 64-bit. The other
	variables should be relatively self explanatory.

	2. Go back to the root project directory and run make. This should
	download and build a version of SQLite, make Sphyraena, and run the
	test program for a 100,000 row data set.

The default build setting is debug, which has very different results than
those that we published, since SQLite is significantly slower without
optimization. To build and test in a release setting, run 'make rrun' in the
sphyraena/ directory. Our release build uses icc, so you may have to change the
RCC variable in sphyraena/Makefile. If you do not have icc, you will have to
write your own build instructions, since we use icc-specific optimization
flags.


Generating Data Sets

We have included the code we used for generating random data sets in the db/
directory, and included a sample 100,000 row data set. Randomization is
provided through the GNU Scientific Library. Each row contains a uniform random
value between -100 and 100, a normal random value with sigma 5, a normal random
value with sigma 20, and a t distribution random value with sigma 20. To
generate data sets we insert rows into SQLite, so the output file is in the
SQLite format that can be accessed through the SQLite console. Doing so is a
good way to quickly check the results you get for queries when using Sphyraena.
Instructions for generating data sets are below.

	1. (This step is in case your machine does not have the GSL) In the
	root project directory run 'make gsl' to download and build GSL
	in the project directory. For some reason GSL requires roughly
	forever to build, so if you are running this remotely you will
	probably want to start a screen session so that your terminal does not
	time out.

	2. In the db/ directory, run 'make' to make the gendb program. If you
	already had GSL installed and did not run step 1, you will have to
	edit the Makefile to point to the correct location of GSL.

	3. In the same directory run './gendb <db file> <rows>' to output a
	SQLite data file with the name and size of your choice.


KNOWN ISSUES

There is currently a read bug for the int64 and double datatypes that may be
hardware related. This may give you trouble if you attempt to query using these
datatypes.


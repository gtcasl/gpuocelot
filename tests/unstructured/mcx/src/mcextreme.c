/*******************************************************************************
**
**  Monte Carlo eXtreme - GPU accelerated Monte Carlo Photon Migration
**  
**  Author     : Qianqian Fang
**  Email      : <fangq at nmr.mgh.harvard.edu>
**  Institution: Massachusetts General Hospital / Harvard Medical School
**  Address    : Bldg. 149, 13th Street, Charlestown, MA 02148, USA
**  Homepage   : http://nmr.mgh.harvard.edu/~fangq/
**
**  MCX Web    : http://mcx.sourceforge.net
**
**  License    : GNU General Public License version 3 (GPLv3), see LICENSE.txt
**
*******************************************************************************/

#include <stdio.h>
#include "tictoc.h"
#include "mcx_utils.h"
#include "mcx_core.h"

int main (int argc, char *argv[]) {
     Config mcxconfig;
     mcx_initcfg(&mcxconfig);
     
     // parse command line options to initialize the configurations
     mcx_parsecmd(argc,argv,&mcxconfig);
     
     // identify gpu number and set one gpu active
     if(!mcx_set_gpu(&mcxconfig)){
         mcx_error(-1,"No GPU device found\n",__FILE__,__LINE__);
     }
          
     // this launches the MC simulation
     mcx_run_simulation(&mcxconfig);
     
     // clean up the allocated memory in the config
     mcx_clearcfg(&mcxconfig);
     return 0;
}

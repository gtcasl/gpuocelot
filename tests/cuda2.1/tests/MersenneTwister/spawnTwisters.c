#include <stdio.h>
#include <stdlib.h>
#include "dc.h"



////////////////////////////////////////////////////////////////////////////////
// Generator utility, spawning Mersenne Twister configurations 
// for each Compute thread. Compiled only from Linux32 yet.
// Use dcmt0.4 template makefile.
////////////////////////////////////////////////////////////////////////////////
typedef struct{
    unsigned int matrix_a;
    unsigned int mask_b;
    unsigned int mask_c;
    unsigned int seed;
} mt_struct_stripped;

#define     DCMT_SEED 4172
#define MT_RNG_PERIOD 607
#define  MT_RNG_COUNT 4096
mt_struct MT[MT_RNG_COUNT];



int main(void){
    int i, flag;
    mt_struct *mts;
    mt_struct_stripped mt_strip;
    FILE *fd, *flog;


    if( sizeof(mt_struct) != 64 || sizeof(mt_struct_stripped) != 16 ){
        printf("***BAD STRUCTURE ALIGNMENT!!!***\n");
        goto brk;
    }

    if( !(flog = fopen("log.txt", "w+")) ){
        printf("***FAILED TO CREATE LOG FILE!!!***n");
        goto brk;
    }

    fprintf(flog, "Generating Mersenne Twisters...\n"); fflush(flog);
        init_dc(DCMT_SEED);
        for(i = 0; i < MT_RNG_COUNT; i++){
            fprintf(flog, "...%i\n", i); fflush(flog);
            mts = get_mt_parameter_id(32, MT_RNG_PERIOD, i);
            if(!mts){
                fprintf(flog, "***FAILED TO FIND RNG!!!***\n");
                goto brk;
            }
            MT[i] = *mts;
            //We don't need the contents of the state,
            //which anyway wasn't yet initialized by sgenrand_mt()
            MT[i].i     = 0;
            MT[i].state = NULL;
            free_mt_struct(mts);
        }

    fprintf(flog, "Inspecting configurations...\n"); fflush(flog);
        flag = 1;
        for(i = 1; i < MT_RNG_COUNT; i++)
            if(
                (MT[i].mm != MT[0].mm) ||
                (MT[i].nn != MT[0].nn) ||
                (MT[i].rr != MT[0].rr) ||
                (MT[i].ww != MT[0].ww) ||
                (MT[i].wmask != MT[0].wmask) ||
                (MT[i].umask != MT[0].umask) ||
                (MT[i].lmask != MT[0].lmask) ||
                (MT[i].shift0 != MT[0].shift0) ||
                (MT[i].shift1 != MT[0].shift1) ||
                (MT[i].shiftB != MT[0].shiftB) ||
                (MT[i].shiftC != MT[0].shiftC)
            ) flag = 0;

        if(!flag){
            fprintf(flog, "***INCONSISTENT CONFIGURATIONS!!!***\n");
            goto brk;
        }


    fprintf(flog, "Creating raw MT file...\n"); fflush(flog);
        if( !(fd = fopen("MersenneTwister.raw", "wb+")) ){
            fprintf(flog, "***FAILED TO CREATE RAW MT FILE!!!***\n");
            goto brk;
        }
        fwrite(&MT, sizeof(mt_struct), MT_RNG_COUNT, fd);
        fclose(fd);


    fprintf(flog, "Creating stripped MT file...\n"); fflush(flog);
        if( !(fd = fopen("MersenneTwister.dat", "wb+")) ){
            fprintf(flog, "***FAILED TO CREATE STRIPPED FILE!!!***\n");
            goto brk;
        }
        for(i = 0; i < MT_RNG_COUNT; i++){
            mt_strip.matrix_a = MT[i].aaa;
            mt_strip.mask_b   = MT[i].maskB;
            mt_strip.mask_c   = MT[i].maskC;
            mt_strip.seed     = 0;
            fwrite(&mt_strip, sizeof(mt_struct_stripped), 1, fd);
        }
        fclose(fd);



    fprintf(flog, "Creating MT header file...\n"); fflush(flog);
        if( !(fd = fopen("MersenneTwister.h", "w+")) ){
            fprintf(flog, "***FAILED TO CREATE MersenneTwister.h!!!***\n");
            goto brk;
        }

        fprintf(fd, "#ifndef MERSENNETWISTER_H\n"                   );
        fprintf(fd, "#define MERSENNETWISTER_H\n"                   );
        fprintf(fd, "#ifndef mersennetwister_h\n"                   );
        fprintf(fd, "#define mersennetwister_h\n"                   );
        fprintf(fd, "\n\n\n");
        fprintf(fd, "#define      DCMT_SEED %i\n",    DCMT_SEED     );
        fprintf(fd, "#define  MT_RNG_PERIOD %i\n",    MT_RNG_PERIOD );
        fprintf(fd, "\n\n");
        fprintf(fd, "typedef struct{\n"                             );
        fprintf(fd, "    unsigned int matrix_a;\n"                  );
        fprintf(fd, "    unsigned int mask_b;\n"                    );
        fprintf(fd, "    unsigned int mask_c;\n"                    );
        fprintf(fd, "    unsigned int seed;\n"                      );
        fprintf(fd, "} mt_struct_stripped;\n"                       );
        fprintf(fd, "\n\n");
        fprintf(fd, "#define   MT_RNG_COUNT %i\n",    MT_RNG_COUNT  );
        fprintf(fd, "#define          MT_MM %i\n",    MT[0].mm      );
        fprintf(fd, "#define          MT_NN %i\n",    MT[0].nn      );
        fprintf(fd, "#define       MT_WMASK 0x%XU\n", 0xFFFFFFFFU   );
        fprintf(fd, "#define       MT_UMASK 0x%XU\n", MT[0].umask   );
        fprintf(fd, "#define       MT_LMASK 0x%XU\n", MT[0].lmask   );
        fprintf(fd, "#define      MT_SHIFT0 %i\n",    MT[0].shift0  );
        fprintf(fd, "#define      MT_SHIFTB %i\n",    MT[0].shiftB  );
        fprintf(fd, "#define      MT_SHIFTC %i\n",    MT[0].shiftC  );
        fprintf(fd, "#define      MT_SHIFT1 %i\n",    MT[0].shift1  );
        fprintf(fd, "\n\n\n");
        fprintf(fd, "#endif\n");
        fprintf(fd, "#endif\n");
        fclose(fd);

    fprintf(flog, "All done.\n");

brk:
    fclose(flog);
    return 0;
}

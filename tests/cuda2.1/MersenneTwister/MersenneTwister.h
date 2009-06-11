#ifndef MERSENNETWISTER_H
#define MERSENNETWISTER_H
#ifndef mersennetwister_h
#define mersennetwister_h



#define      DCMT_SEED 4172
#define  MT_RNG_PERIOD 607


typedef struct{
    unsigned int matrix_a;
    unsigned int mask_b;
    unsigned int mask_c;
    unsigned int seed;
} mt_struct_stripped;


#define   MT_RNG_COUNT 4096
#define          MT_MM 9
#define          MT_NN 19
#define       MT_WMASK 0xFFFFFFFFU
#define       MT_UMASK 0xFFFFFFFEU
#define       MT_LMASK 0x1U
#define      MT_SHIFT0 12
#define      MT_SHIFTB 7
#define      MT_SHIFTC 15
#define      MT_SHIFT1 18



#endif
#endif

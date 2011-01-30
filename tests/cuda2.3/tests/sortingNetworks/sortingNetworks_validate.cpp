/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation and 
 * any modifications thereto.  Any use, reproduction, disclosure, or distribution 
 * of this software and related documentation without an express license 
 * agreement from NVIDIA Corporation is strictly prohibited.
 * 
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortingNetworks_common.h"



////////////////////////////////////////////////////////////////////////////////
// Validate sorted keys array (check for integrity and proper order)
////////////////////////////////////////////////////////////////////////////////
extern "C" uint validateSortedKeys(
    uint *resKey,
    uint *srcKey,
    uint batchSize,
    uint arrayLength,
    uint numValues,
    uint dir
){
    uint *srcHist;
    uint *resHist;
    if(arrayLength < 2){
        printf("validateSortedKeys(): arrayLength too short, exiting...\n");
        return 1;
    }

    srcHist = (uint *)malloc(numValues * sizeof(uint));
    resHist = (uint *)malloc(numValues * sizeof(uint));

    int flag = 1;
    for(uint j = 0; j < batchSize; j++, srcKey += arrayLength, resKey += arrayLength){
        //Build histograms for keys arrays
        memset(srcHist, 0, numValues * sizeof(uint));
        memset(resHist, 0, numValues * sizeof(uint));
        for(uint i = 0; i < arrayLength; i++){
            if( srcKey[i] < numValues && resKey[i] < numValues ){
                srcHist[srcKey[i]]++;
                resHist[resKey[i]]++;
            }else{
                flag = 0;
                break;
            }
        }

        if(!flag){
            printf("validateSortedKeys(): ***Set %u source/result key arrays are not limited properly***\n", j);
            goto brk;
        }

        //Compare the histograms
        for(uint i = 0; i < numValues; i++)
            if(srcHist[i] != resHist[i]){
                flag = 0;
                break;
            }

        if(!flag){
            printf("validateSortedKeys(): ***Set %u source/result keys histograms do not match***\n", j);
            goto brk;
        }

        if(dir){
            //Ascending order
            for(uint i = 0; i < arrayLength - 1; i++)
                if(resKey[i + 1] < resKey[i]){
                    flag = 0;
                    break;
                }
        }else{
            //Descending order
            for(uint i = 0; i < arrayLength - 1; i++)
                if(resKey[i + 1] > resKey[i]){
                    flag = 0;
                    break;
                }
        }

        if(!flag){
            printf("validateSortedKeys(): ***Set %u result key array is not ordered properly***\n", j);
            goto brk;
        }
    }

brk:
    free(resHist);
    free(srcHist);

    if(flag) printf("validateSortedKeys(): result key array is ordered correctly\n");
    return flag;
}



////////////////////////////////////////////////////////////////////////////////
// Generate input values from input keys
// Check output values to match output keys by the same translation function
////////////////////////////////////////////////////////////////////////////////
static uint translateKey(uint r){
    const uint log2N = 32;

    r = ((r >>  1) & 0x55555555) | ((r & 0x55555555) <<  1);
    r = ((r >>  2) & 0x33333333) | ((r & 0x33333333) <<  2);
    r = ((r >>  4) & 0x0F0F0F0F) | ((r & 0x0F0F0F0F) <<  4);
    r = ((r >>  8) & 0x00FF00FF) | ((r & 0x00FF00FF) <<  8);
    r = ((r >> 16) & 0x0000FFFF) | ((r & 0x0000FFFF) << 16);
    return r >> (32 - log2N);
}

extern "C" void generateValuesFromKeys(
    uint *ival,
    uint *ikey,
    uint N
){
    for(uint i = 0; i < N; i++)
        ival[i] = translateKey(ikey[i]);
}

extern "C" int validateValues(
    uint *oval,
    uint *okey,
    uint N
){
    int flag = 1;
    for(uint i = 0; i < N; i++)
        if( oval[i] != translateKey(okey[i]) ){
            printf("validateValues(): ***val array doesn't match key array***\n");
            flag = 0;
            break;
        }

    if(flag) printf("validateValues(): key and val arrays match\n");
    return flag;
}

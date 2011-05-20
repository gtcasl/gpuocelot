#!/bin/sh
echo ============================================================
echo "running MT RNG using only registers"
make clean mt
../../bin/rngspeed 128 128 100000

echo ============================================================
echo "running LL5 RNG using only registers"
make clean logistic
../../bin/rngspeed 128 128 100000

#echo ============================================================
#echo "running MT RNG with global write (bottleneck)"
#make clean mtw
#../../bin/rngspeed 128 128 100000

#echo ============================================================
#echo "running LL5 RNG with global write (bottleneck)"
#make clean logisticw
#../../bin/rngspeed 128 128 100000


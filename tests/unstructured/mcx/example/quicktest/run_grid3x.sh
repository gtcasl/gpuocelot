#!/bin/sh
if [ ! -e semi180x180x180.bin ]; then
  dd if=/dev/zero of=semi180x180x180.bin bs=1000 count=5832
  perl -pi -e 's/\x0/\x1/g' semi180x180x180.bin
fi

time ../../bin/mcx -A 1 -g 10 -n 1e7 -f grid3x.inp -s grid3x -r 1 -a 0 -b 0 -G 1 -u 0.33333333333333333


#!/bin/sh
if [ ! -e semi120x120x120.bin ]; then
  dd if=/dev/zero of=semi120x120x120.bin bs=1000 count=1728
  perl -pi -e 's/\x0/\x1/g' semi120x120x120.bin
fi

time ../../bin/mcx -A 1 -g 10 -n 1e7 -f grid2x.inp -s grid2x -r 1 -a 0 -b 0 -G 1 -u 0.5


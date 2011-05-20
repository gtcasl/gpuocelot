#!/bin/sh
if [ ! -e semi60x60x60.bin ]; then
  dd if=/dev/zero of=semi60x60x60.bin bs=1000 count=216
  perl -pi -e 's/\x0/\x1/g' semi60x60x60.bin
fi

time ../../bin/mcx --thread 1792 --blocksize 256 --gategroup 10 \
 --move 100000 --input bubble.inp --session bubble0 --repeat 1 \
 --array 0 --reflect 0 --skipradius 0
 
time ../../bin/mcx --thread 1792 --blocksize 256 --gategroup 10 \
 --move 100000 --input bubble.inp --session bubble3 --repeat 1 \
 --array 0 --reflect 0 --skipradius 3
 
time ../../bin/mcx --thread 1792 --blocksize 256 --gategroup 10 \
 --move 100000 --input bubble.inp --session bubble5 --repeat 1 \
 --array 0 --reflect 0 --skipradius 5

#!/bin/sh
if [ ! -e semi60x60x60.bin ]; then
  dd if=/dev/zero of=semi60x60x60.bin bs=1000 count=216
  perl -pi -e 's/\x0/\x1/g' semi60x60x60.bin
fi

time ../../bin/mcx -A -g 10 -n 1e7 -f qtest.inp -s qtest -r 1 -a 0 -b 0 -G 1


#!/bin/sh
if [ ! -e semi60x60x60.bin ]; then
  dd if=/dev/zero of=semi60x60x60.bin bs=1000 count=216
  perl -pi -e 's/\x0/\x1/g' semi60x60x60.bin
fi

../../bin/mcx -t 1792 -g 10 -m 100000 -f qtest.inp -s qtest -r 1 -a 0 -b 0 -p 18 -l

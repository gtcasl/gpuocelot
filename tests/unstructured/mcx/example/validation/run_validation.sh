#!/bin/sh
time ../../bin/mcx -t 1792 -g 50 -n 1e8 -f validation.inp -s semi_infinite -r 12 -a 0 -b 0 -U 1
#time ../../bin/mcx -A -n 1e8 -f validation_dark.inp -s semi_infinite_dark -r 1 -a 0 -b 0 -U 1

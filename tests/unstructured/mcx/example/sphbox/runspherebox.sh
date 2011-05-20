#!/bin/sh

# you need to fist add the path to mcx to PATH environment variable

## this works on GTX 470, please change -t and -T accordingly if you run on a different hardware
time mcx -t 46000 -T 64 -g 50 -n  104221548 -f spherebox.inp -s spherebox -a 0 -b 0 -G 1 -d 0


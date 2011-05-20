#!/bin/sh
grep '<mcx_se' $1 > res1.txt
grep '^expected' $1 | awk '{print $NF}' > res2.txt
paste res1.txt res2.txt

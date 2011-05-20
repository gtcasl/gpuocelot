#!/bin/sh
grep '^simulat' $1 | sed -e :a -e '/ms$/N; s/ms\n/ /; ta' -e 's/[a-zA-Z\.]//g' | \
  awk '{print $4 "\t" $5 "\t" $6 "\t" $7}' | sed -e 's/[\)\(]//g'

#!/bin/bash

# (c) Copyright 2010 The Board of Trustees of the University of Illinois.

cmp $1 $2 &> /dev/null

if [ $? -eq 0 ]         # Test exit status of "cmp" command.
then
  echo "Pass"
else  
  echo "Mismatch"
  exit 1
fi

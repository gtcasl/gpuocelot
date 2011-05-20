#!/usr/bin/env python
import os, sys
template = open("cudarenderer.cu.template", "w")
for line in open("../src/cudarenderer.cu"):
    if "define THREADS_PER_BLOCK" in line:
	template.write("#define THREADS_PER_BLOCK ##THREADS##\n")
    else:
	template.write(line)
template.close()

for t in (32*x for x in xrange(1,9)):
    cu = open("../src/cudarenderer.cu", "w")
    for line in open("cudarenderer.cu.template",'r').readlines():
	cu.write(line.replace('##THREADS##', str(t)))
    cu.close()

    if 0 == os.system("cd .. ; make >/dev/null 2>&1"):
	print "Running with", t, "threads"
	sys.stdout.flush()
	os.system("sync ; ../src/cudaRenderer -b 50 ../3D-objects/trainColor.ply")

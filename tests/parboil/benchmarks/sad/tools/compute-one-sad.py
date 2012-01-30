#! /usr/bin/env python

# (c) Copyright 2007 The Board of Trustees of the University of Illinois.

# This tool computes the 4x4 SADs for the first macroblock in an image
# for one search offset and prints it.  It's useful primarily for
# diagnosing incorrect program output.

import binaryfilecompare as bfc

class Img:
    def __init__(self, (w, h), d):
        self.width = w
	self.height = h
	self.data = d

def load_image(f):
    width = bfc.uint16(f)
    height = bfc.uint16(f)
    lines = [bfc.many_uint16(width)(f) for n in range(height)]
    return Img((width, height), lines)

frm = load_image(file('input/default/frame.bin'))
ref = load_image(file('input/default/reference.bin'))

def getpix(img, x, y):
    if x < 0: x = 0
    if x >= img.width: x = img.width - 1
    if y < 0: y = 0
    if y >= img.height: y = img.height - 1
    return img.data[y][x]
    
def pixdif(x, y, xoff, yoff):
    return abs(getpix(frm,x,y) - getpix(ref,x+xoff,y+yoff))

# Compute 4x4 SADs for this search offset in the reference frame
searchoff = (1,1)

print "Search position: %d" % (searchoff[0] + 16 + 33 * (searchoff[1] + 16))

print [[sum([sum([pixdif(4*bx+x, 4*by+y, searchoff[0], searchoff[1])
                  for x in range(4)])
             for y in range(4)])
        for bx in range(4)]
       for by in range(4)]

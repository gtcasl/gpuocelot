/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
struct Shell
{
	char Type[2];
	int numPrimitives;
	float Alpha[20];
	float Coeff[20];
	int inList[20];
	int myAtom;
};

struct Atom
{
	char Type[1];
	int numShells;
	Shell AtomShell[10];
	float X;
	float Y;
	float Z;
};

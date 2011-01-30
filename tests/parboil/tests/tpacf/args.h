/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#ifndef __ARGS_H__
#define __ARGS_H__

typedef struct _options_
{
  char *data_name;
  char *random_name;
  int random_count;
  int npoints;
  char *output_name;
} options;

void usage(char *name);
void parse_args(int argc, char **argv, options* args);

#endif

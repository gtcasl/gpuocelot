/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation and 
 * any modifications thereto.  Any use, reproduction, disclosure, or distribution 
 * of this software and related documentation without an express license 
 * agreement from NVIDIA Corporation is strictly prohibited.
 * 
 */

/* CUda UTility Library */

// includes, file
#include <stopwatch_linux.h>


////////////////////////////////////////////////////////////////////////////////
//! Constructor, default
////////////////////////////////////////////////////////////////////////////////
StopWatchLinux::StopWatchLinux() :
  start_time(),
  diff_time( 0.0),
  total_time(0.0),
  running( false),
  clock_sessions(0)
{ }

////////////////////////////////////////////////////////////////////////////////
// Destructor
////////////////////////////////////////////////////////////////////////////////
StopWatchLinux::~StopWatchLinux() { }


//
// Copyright (c) 2017-2019, Manticore Software LTD (http://manticoresearch.com)
// Copyright (c) 2001-2016, Andrew Aksyonoff
// Copyright (c) 2008-2016, Sphinx Technologies Inc
// All rights reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org/
//
/// @file taskflushmutable.h
/// Task to check and flush mutable indexes (rt, precloate) when necessary or by timeout

#ifndef MANTICORE_TASKFLUSHMUTABLE_H
#define MANTICORE_TASKFLUSHMUTABLE_H

#include "sphinxstd.h"

/* this cb attached to local indexes hash table 'add-or-replace' function. It is called for all new arrived indexes,
 * and if it suitable for flushing (i.e. if it exists and is mutable), engages flushing task by timer for it.*/
void HookSubscribeMutableFlush ( ISphRefcountedMT* pCounter, const CSphString& sName );

// set from param `rt_flush_period`, see conf_options_reference/searchd_program_configuration_options.html
void SetRtFlushPeriod ( int64_t iPeriod );

void ShutdownFlushingMutable();

#endif //MANTICORE_TASKFLUSHMUTABLE_H

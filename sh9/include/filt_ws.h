/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************
* File:     filt_ws.h
* Purpose:  Filter
* Create:   1998.03.20 Rev. 1.0
***********************************************************/

#ifndef FILT_WS
#define FILT_WS

#include <_dspc_type.h>

#ifndef WS_SIZE
#define WS_SIZE 1024          /* Set Global workspace buffer size=1024 shorts (2048 bytes) */
#endif

#define MEMSIZE WS_SIZE*sizeof(_TYPE__FIXED)

#ifndef _DSPC
#pragma section Y                  /*need to equate DYRAM with link.cmd file*/
#endif

_QUALIFY__Y _TYPE__FIXED ws_mem[WS_SIZE];
_QUALIFY__Y _TYPE__FIXED * _QUALIFY__Y ws_ptr=ws_mem;
_QUALIFY__Y long ws_left=MEMSIZE;

#ifndef _DSPC
#pragma section
#endif

#endif

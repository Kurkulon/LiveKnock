/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = fixed.h :                                                   */
/*                                                                     */
/*  FUNC = this module do the following functions                      */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/

#ifndef  _FIXED
#define _FIXED

#define   FIXED_BIT       16
#define   FIXED_MIN       (-0.5r-0.5r)
#define   FIXED_MAX       0.999969482421875r
#define   FIXED_EPSILON   0.000030517578125r
#define   LFIXED_BIT      32
#define   LFIXED_MIN      (-0.5R-0.5R)
#define   LFIXED_MAX      0.9999999995343387126922607421875R
#define   LFIXED_EPSILON  0.0000000004656612873077392578125R
#define   ACCUM_BIT       24
#define   ACCUM_MIN       (-128.0a-128.0a)
#define   ACCUM_MAX       255.999969482421875a
#define   ACCUM_EPSILON   0.000030517578125a
#define   LACCUM_BIT      40
#define   LACCUM_MIN      (-128.0A-128.0A)
#define   LACCUM_MAX      255.9999999995343387126922607421875A
#define   LACCUM_EPSILON  0.0000000004656612873077392578125A

#endif

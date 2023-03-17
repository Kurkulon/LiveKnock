/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = assert.h : debug macro define          ;                    */
/*                                                                     */
/*  FUNC = this module do the following functions;                     */
/*         (1) if NDEBUG defined assert(x) = (void)0;                  */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/
#ifndef _ASSERT
#define _ASSERT

#include <stdio.h>
#ifdef NDEBUG
#ifdef assert
#undef assert
#endif
#define assert(x) ((void)0)
#else
#ifdef assert
#undef assert
#endif
#define       assert(x) ( x ? (void) 0 : (fprintf(stderr,\
              "ASSERTION FAILED: "#x" FILE %s,LINE %d \n", \
              __FILE__,__LINE__),abort(),(void)0))
#endif
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
void abort(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

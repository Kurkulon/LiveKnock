/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = stddef :                                                    */
/*                                                                     */
/*  FUNC = this module do the following functions                      */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/
#ifndef _STDDEF
#define _STDDEF

#ifndef _PTRDIFF_T
#define _PTRDIFF_T
typedef int ptrdiff_t;
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;
#endif

#ifndef  NULL
#ifdef  __cplusplus
#define  NULL           (0)
#else
#define  NULL           ((void *)0)
#endif
#endif

#ifndef  offsetof
#ifdef __cplusplus
#define offsetof(t, memb) ((size_t)(&(((t *)0)->memb)))
#else
#define offsetof(type,id) ((char *)(&(((type *)NULL)->id))  -    \
                           (char *)((type *)NULL))
#endif
#endif

#ifndef  errno
#define  errno          _errno
#endif

#endif

/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = _dspc_type.h :                                              */
/*                                                                     */
/*  FUNC = this module do the following functions                      */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/

#ifndef  __DSPC_TYPE
#define __DSPC_TYPE

#ifdef _DSPC

#define _QUALIFY__X __X
#define _QUALIFY__Y __Y
#define _TYPE__FIXED __fixed
#define _TYPE_L__FIXED long __fixed

#else

#define _QUALIFY__X /* none */
#define _QUALIFY__Y /* none */
#define _TYPE__FIXED short
#define _TYPE_L__FIXED long

#endif /* _DSPC */

#endif /* __DSPC_TYPE */

/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and	   */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = _h_c_lib.h :                                                */
/*                                                                     */
/*  FUNC = Include file for SH SERIES C/C++ Compiler environment       */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/

#ifndef _H_C_LIB
#define _H_C_LIB

#ifdef __cplusplus
extern "C"{
#endif
extern void _CALL_INIT(void); /* for global class object initial processing */
extern void _CALL_END(void);  /* for global class object post-processing */
extern void _INITSCT(void);   /* Clear BSS, and copy DATA from ROM to RAM */
#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

#endif /* #ifndef _H_C_LIB */

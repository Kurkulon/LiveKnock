/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = setjmp.h :                                ;                 */
/*                                                                     */
/*  FUNC = this module do the following functions    ;                 */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/
#ifndef _SETJMP
#define _SETJMP

#if defined(_SH2E)|defined(_SH3E)|defined(_SH4)|defined(_SH4A)|defined(_SH2AFPU)
typedef int jmp_buf[38];
#else
typedef int jmp_buf[20];
#endif
#if defined(_SH4)|defined(_SH4A)
typedef int jmp_buf_a[54];
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int);
#if defined(_SH4)|defined(_SH4A)
extern int setjmp_a(jmp_buf);
extern void longjmp_a(jmp_buf, int);
#endif

#ifndef _REENTRANT
extern volatile int _errno;
#else
#define _errno (*errno_addr())
int  *errno_addr(void);
#endif

#ifdef __cplusplus
}
#endif

#ifndef SEQERR
#define SEQERR     1108
#endif

#endif

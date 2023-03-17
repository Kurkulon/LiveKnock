/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2011) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = math :                                               */
/*   FUNC =                                                      */
/*          ;                                                    */
/*                                                               */
/*                                                               */
/*                                                               */
/*   CLAS = UNIT ;                                               */
/*   END ;                                                       */
/*****************************************************************/
#ifndef _MATH
#define _MATH

#include <builtin.h>

#ifndef ERANGE
#define ERANGE  1100
#endif

#ifndef EDOM
#define EDOM    1101
#endif

#ifndef ENUM
#define ENUM    1208
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _REENTRANT
extern volatile int _errno;
#else
extern  int *errno_addr(void);
#define _errno (*errno_addr())
#endif

#ifndef HUGE_VAL
#if defined(_FPS)|defined(_FLT)
extern const float _HUGE_VALF;
#define HUGE_VAL  _HUGE_VALF
#else
extern const double _HUGE_VAL;
#define HUGE_VAL  _HUGE_VAL
#endif
#endif

extern double frexp(double, int *);
extern double ldexp(double, int );
extern double modf(double, double *);
extern double ceil(double);

extern double (fabs)(double);
#if defined(_SH4)|defined(_SH4A)|defined(_SH2AFPU)
#ifdef _FPS
#define  fabs(x)  _builtin_fabsf(x)
#else
#define  fabs(x)  _builtin_fabs(x)
#endif
#else
#if defined(_SH2E)|defined(_SH3E)
#ifdef _FLT
#define  fabs(x)  _builtin_fabsf(x)
#endif
#endif
#endif

extern double floor(double);
extern double fmod(double, double);

extern double acos(double);
extern double asin(double);
extern double atan(double);
extern double atan2(double,double);
extern double cos(double);
extern double sin(double);
extern double tan(double);
extern double cosh(double);
extern double tanh(double);
extern double sinh(double);
extern double exp(double);
extern double log(double);
extern double log10(double);
extern double pow(double,double);

extern double (sqrt)(double);
#if defined(_SH4)|defined(_SH4A)|defined(_SH2AFPU)
#ifdef _FPS
#define  sqrt(x)  _builtin_sqrtf(x)
#else
#define  sqrt(x)  _builtin_sqrt(x)
#endif
#else
#ifdef _SH3E
#ifdef _FLT
#define  sqrt(x)  _builtin_sqrtf(x)
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif

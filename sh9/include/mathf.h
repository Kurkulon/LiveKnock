/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2011) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = mathf                                                */
/*   FUNC =                                                      */
/*          ;                                                    */
/*                                                               */
/*                                                               */
/*                                                               */
/*   CLAS = UNIT ;                                               */
/*   END ;                                                       */
/*****************************************************************/
#ifndef _MATHF
#define _MATHF

#include <builtin.h>
#ifdef __cplusplus
extern "C" {
#endif

#ifndef ERANGE
#define ERANGE  1100
#endif

#ifndef EDOM
#define EDOM    1101
#endif

#ifdef _FPD
extern const double _HUGE_VAL;
#define HUGE_VALF  _HUGE_VAL
#else
extern const float _HUGE_VALF;
#define HUGE_VALF  _HUGE_VALF
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

extern float frexpf(float, int *);
extern float ldexpf(float, int);
extern float modff(float, float *);
extern float ceilf(float);
extern float (fabsf)(float);
#if defined(_SH2E)|defined(_SH3E)|defined(_SH4)|defined(_SH4A)|defined(_SH2AFPU)
#ifdef _FPD
#define  fabsf(x)  _builtin_fabs(x)
#else
#define  fabsf(x)  _builtin_fabsf(x)
#endif
#endif
extern float floorf(float);
extern float fmodf(float, float);
extern float acosf(float);
extern float asinf(float);
extern float atanf(float);
extern float atan2f(float,float);
extern float cosf(float);
extern float sinf(float);
extern float tanf(float);
extern float coshf(float);
extern float tanhf(float);
extern float sinhf(float);
extern float expf(float);
extern float logf(float);
extern float log10f(float);
extern float powf(float,float);
extern float (sqrtf)(float);
#if defined(_SH3E)|defined(_SH4)|defined(_SH4A)|defined(_SH2AFPU)
#ifdef _FPD
#define  sqrtf(x)  _builtin_sqrt(x)
#else
#define  sqrtf(x)  _builtin_sqrtf(x)
#endif
#endif
#ifdef __cplusplus
}
#endif

#endif

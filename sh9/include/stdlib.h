/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = stdlib :                                             */
/*   FUNC =                                                      */
/*          ;                                                    */
/*                                                               */
/*                                                               */
/*                                                               */
/*   CLAS = UNIT ;                                               */
/*   END ;                                                       */
/*****************************************************************/
#ifndef _STDLIB
#define _STDLIB

#include <stddef.h>

struct _DIV_T_TAG {          /* tag define for div_t   */
    int quot;                /*  quotient              */
    int rem;                 /*  remainder             */
};                           /*                        */
struct _LDIV_T_TAG {         /* tag define for ldiv_t  */
    long quot;               /*  quotient              */
    long rem;                /*  remainder             */
};                           /*                        */
struct _LLDIV_T_TAG {        /* tag define for ldiv_t  */
    long long quot;          /*  quotient              */
    long long rem;           /*  remainder             */
};                           /*                        */

typedef struct _DIV_T_TAG div_t ;
/* int quot; int rem */
typedef struct _LDIV_T_TAG ldiv_t ;
/* long quot; long rem; */
typedef struct _LLDIV_T_TAG lldiv_t ;
/* long long quot; long long rem; */

#ifndef RAND_MAX
#define RAND_MAX  32767
#endif

#ifndef ERANGE
#define ERANGE  1100
#endif

#ifndef EDOM
#define EDOM    1101
#endif

#ifndef EDIV
#define EDIV    1102
#endif

#ifndef ESTRN
#define ESTRN   1104
#endif

#ifndef ECBASE
#define ECBASE  1200
#endif

#ifndef ETLN
#define ETLN    1202
#endif

#ifndef EEXP
#define EEXP    1204
#endif

#ifndef EEXPN
#define EEXPN   1206
#endif

#ifndef EFLOATO
#define EFLOATO 1210
#endif

#ifndef EFLOATU
#define EFLOATU 1220
#endif

#ifndef EDBLO
#define EDBLO   1250
#endif

#ifndef EDBLU
#define EDBLU   1260
#endif

#ifndef ELDBLO
#define ELDBLO  1270
#endif

#ifndef ELDBLU
#define ELDBLU  1280
#endif

#ifdef _DSPC
#ifndef EFIXEDO
#define EFIXEDO  1400
#endif
#ifndef EFIXEDU
#define EFIXEDU  1410
#endif
#ifndef EACCUMO
#define EACCUMO  1420
#endif
#ifndef EACCUMU
#define EACCUMU  1430
#endif
#ifndef ELFIXEDO
#define ELFIXEDO 1440
#endif
#ifndef ELFIXEDU
#define ELFIXEDU 1450
#endif
#ifndef ELACCUMO
#define ELACCUMO 1460
#endif
#ifndef ELACCUMU
#define ELACCUMU 1470
#endif
#endif /* _DSPC */

#ifndef EMALRESM
#define EMALRESM 2100
#endif
#ifndef ETOKRESM
#define ETOKRESM 2110
#endif
#ifndef EIOBRESM
#define EIOBRESM 2120
#endif
#ifndef EMALFRSM
#define EMALFRSM 2101
#endif
#ifndef ETOKFRSM
#define ETOKFRSM 2111
#endif
#ifndef EIOBFRSM
#define EIOBFRSM 2121
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

extern const size_t _sbrk_size;

extern double atof(const char *) ;
extern int atoi(const char *) ;
extern long int atol(const char *) ;
extern long long int atoll(const char *) ;
extern double strtod(const char *, char **) ;
extern long int strtol(const char *, char **, int);
extern unsigned long int strtoul(const char *, char **, int);
extern long long int strtoll(const char *, char **, int);
extern unsigned long long int strtoull(const char *, char **, int);
#ifdef _DSPC
extern long __fixed atolfixed(const char *);
extern long __fixed strtolfixed(const char *, char **);
extern long __accum atolaccum(const char *);
extern long __accum strtolaccum(const char *, char **);
#endif /* _DSPC */
extern int rand(void) ;
extern void srand(unsigned int);
extern void *calloc(size_t, size_t);
extern void free(void *) ;
extern void *malloc(size_t);
extern void *realloc(void *, size_t) ;
#ifdef _DSPC
extern void __X *calloc__X(size_t, size_t);
extern void free__X(void __X *);
extern void __X *malloc__X(size_t);
extern void __X *realloc__X(void __X *, size_t);
extern void __Y *calloc__Y(size_t, size_t);
extern void free__Y(void __Y *);
extern void __Y *malloc__Y(size_t);
extern void __Y *realloc__Y(void __Y *, size_t);
#endif /* _DSPC */
extern void *bsearch(const void *, const void *, size_t, size_t,
                                  int(*)(const void*,const void*) ) ;
extern void qsort(void *, size_t, size_t,
                                  int(*)(const void*,const void*) );

extern int abs(int);
extern div_t div(int, int);
extern long int labs(long int);
extern long long int llabs(long long int);
extern ldiv_t ldiv(long int, long int);
extern lldiv_t lldiv(long long int, long long int);
#ifdef __cplusplus
}
#endif

#endif

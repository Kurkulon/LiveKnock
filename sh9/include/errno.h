/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = errno :                                              */
/*   FUNC =                                                      */
/*          ;                                                    */
/*                                                               */
/*                                                               */
/*                                                               */
/*   CLAS = UNIT ;                                               */
/*   END ;                                                       */
/*****************************************************************/
#ifndef _ERRNO
#define _ERRNO

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

#ifndef PTRERR
#define PTRERR  1106
#endif

#ifndef SEQERR
#define SEQERR  1108
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

#ifndef ENUM
#define ENUM    1208
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

#ifndef NOTOPN
#define NOTOPN  1300
#endif

#ifndef EBADF
#define EBADF   1302
#endif

#ifndef ECSPEC
#define ECSPEC  1304
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
#define _errno (*errno_addr())
int  *errno_addr(void);
#endif

#ifdef __cplusplus
}
#endif

#ifndef  errno
#define  errno          _errno
#endif

#endif

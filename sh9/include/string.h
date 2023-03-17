/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = string :                                             */
/*   FUNC =                                                      */
/*          ;                                                    */
/*                                                               */
/*                                                               */
/*                                                               */
/*   CLAS = UNIT ;                                               */
/*   LINK =                                                      */
/*   NOTE =                                                      */
/*          ;                                                    */
/*                                                               */
/*   END ;                                                       */
/*****************************************************************/
#ifndef _STRING
#define _STRING

#include <stddef.h>

#include <builtin.h>
#ifdef __cplusplus
extern "C" {
#endif
#ifndef _REENTRANT
#else
#define _errno (*errno_addr())
int  *errno_addr(void);
#endif
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
extern void *memcpy(void *, const void *, size_t);
extern void *memmove(void *, const void *, size_t);
#ifdef _DSPC
extern void __X *memcpy__X__X(void __X *, const void __X *, size_t);
extern void __X *memcpy__X__Y(void __X *, const void __Y *, size_t);
extern void __Y *memcpy__Y__X(void __Y *, const void __X *, size_t);
extern void __Y *memcpy__Y__Y(void __Y *, const void __Y *, size_t);
#endif /* _DSPC */
extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern char *strncat(char *, const char *,size_t);
extern int  memcmp(const void *, const void *,size_t);
extern int  strcmp(const char *, const char *);
extern int  strncmp(const char *, const char *, size_t);
extern void *memchr(const void *, int, size_t);
extern char *strchr(const char *, int);
extern size_t strcspn(const char *, const char *);
extern char *strpbrk(const char *, const char *);
extern char *strrchr(const char *, int);
extern size_t strspn(const char *, const char *);
extern char *strstr(const char *, const char *);
extern char *strtok(char *, const char *);
extern void *memset(void *, int, size_t);
extern char *strerror(int);
extern size_t strlen(const char *);
#ifdef __cplusplus
}
#endif

#define strcpy(s1,s2) _builtin_strcpy(s1,s2)
#define strcmp(s1,s2) _builtin_strcmp(s1,s2)

#endif

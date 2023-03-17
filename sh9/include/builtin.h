/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = builtin :                                            */
/*                                                               */
/*   FUNC = this header file do the following functions;         */
/*          (1)builtin function prototype define;                */
/*                                                               */
/*   CLAS = UNIT ;                                               */
/*                                                               */
/*   END ;                                                       */
/*****************************************************************/

#ifndef _BUILTIN
#define _BUILTIN

#ifdef __cplusplus
extern "C" {
#endif
/* follow math.h & mathf.h */
extern float _builtin_fabsf(float);
extern double _builtin_fabs(double);
extern float _builtin_sqrtf(float);
extern double _builtin_sqrt(double);

/* follow smachine.h */
extern void _builtin_set_imask(int);
extern int _builtin_get_imask(void);
extern void _builtin_set_cr(int);
extern int _builtin_get_cr(void);
extern void _builtin_set_vbr(void *);
extern void *_builtin_get_vbr(void);
extern void _builtin_sleep(void);
extern void _builtin_ldtlb(void);

/* follow string.h */
extern char *_builtin_strcpy(char *, const char *);
extern int _builtin_strcmp(const char *, const char *);

/* follow umachine.h */
extern void _builtin_set_gbr(void *);
extern void *_builtin_get_gbr(void);
extern unsigned char _builtin_gbr_read_byte(int);
extern unsigned short _builtin_gbr_read_word(int);
extern unsigned long _builtin_gbr_read_long(int);
extern void _builtin_gbr_write_byte(int, unsigned char);
extern void _builtin_gbr_write_word(int, unsigned short);
extern void _builtin_gbr_write_long(int, unsigned long);
extern void _builtin_gbr_and_byte(int, unsigned char);
extern void _builtin_gbr_or_byte(int, unsigned char);
extern void _builtin_gbr_xor_byte(int, unsigned char);
extern int _builtin_gbr_tst_byte(int, unsigned char);
extern int _builtin_tas(char *);
extern int _builtin_trapa(int);
extern int _builtin_macw(short *, short *, unsigned int);
extern int _builtin_macwl(short *, short *, unsigned int, unsigned int);
extern int _builtin_macl(int *, int *, unsigned int);
extern int _builtin_macll(int *, int *, unsigned int, unsigned int);
extern int _builtin_trapa_svc(int, int, ...);
extern void _builtin_prefetch(void *);
extern void _builtin_set_fpscr(int);
extern int _builtin_get_fpscr(void);
extern float _builtin_fipr(float a1[], float b1[]);
extern void _builtin_ftrv(float a1[], float b1[]);
extern void _builtin_ftrvadd(float a1[], float b1[], float c1[]);
extern void _builtin_ftrvsub(float a1[], float b1[], float c1[]);
extern void _builtin_mtrx4mul(float [][4], float [][4]);
extern void _builtin_mtrx4muladd(float [][4], float [][4], float [][4]);
extern void _builtin_mtrx4mulsub(float [][4], float [][4], float [][4]);
extern void _builtin_ld_ext(float [][4]);
extern void _builtin_st_ext(float [][4]);
extern void _builtin_add4(float a1[], float b1[], float c1[]);
extern void _builtin_sub4(float a1[], float b1[], float c1[]);
extern void _builtin_trace(long);
extern void _builtin_nop(void);
extern unsigned short _builtin_swapb(unsigned short);
extern unsigned long _builtin_swapw(unsigned long);
extern unsigned long _builtin_end_cnvl(unsigned long);
extern unsigned long _builtin_dmulu_h(unsigned long, unsigned long);
extern unsigned long _builtin_dmulu_l(unsigned long, unsigned long);
extern long _builtin_dmuls_h(long, long);
extern unsigned long _builtin_dmuls_l(long, long);
extern void _builtin_fsca(long ,float *,float *);
extern float _builtin_fsrra(float);
extern float _builtin_fsina(int);
extern float _builtin_fcosa(int);
extern void _builtin_icbi(void *);
extern void _builtin_ocbi(void *);
extern void _builtin_ocbp(void *);
extern void _builtin_ocbwb(void *);
extern void _builtin_prefi(void *);
extern void _builtin_sleep_i(unsigned int);
extern void _builtin_synco(void);
extern int _builtin_movt(void);
extern unsigned long _builtin_xtrct(unsigned long, unsigned long);
extern long _builtin_addc(long, long);
extern int _builtin_ovf_addc(long, long);
extern long _builtin_addv(long, long);
extern int _builtin_ovf_addv(long, long);
extern long _builtin_subc(long, long);
extern int _builtin_unf_subc(long, long);
extern long _builtin_subv(long, long);
extern int _builtin_unf_subv(long, long);
extern long _builtin_negc(long);
extern unsigned long _builtin_div1(unsigned long, unsigned long);
extern int _builtin_div0s(long, long);
extern void _builtin_div0u(void);
extern unsigned long _builtin_rotl(unsigned long);
extern unsigned long _builtin_rotr(unsigned long);
extern unsigned long _builtin_rotcl(unsigned long);
extern unsigned long _builtin_rotcr(unsigned long);
extern unsigned long _builtin_shll(unsigned long);
extern unsigned long _builtin_shlr(unsigned long);
extern long _builtin_shar(long);
extern void _builtin_clrt(void);
extern void _builtin_sett(void);
extern long _builtin_clipsb(long);
extern long _builtin_clipsw(long);
extern unsigned long _builtin_clipub(unsigned long);
extern unsigned long _builtin_clipuw(unsigned long);
extern void _builtin_set_tbr(void *);
extern void *_builtin_get_tbr(void);
extern void _builtin_sr_jsr(void *, int);
extern void _builtin_bset(unsigned char *, unsigned char);
extern void _builtin_bclr(unsigned char *, unsigned char);
extern void _builtin_bcopy(unsigned char *, unsigned char,
                           unsigned char *, unsigned char);
extern void _builtin_bnotcopy(unsigned char *, unsigned char,
                              unsigned char *, unsigned char);

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

#endif /* #ifndef _BUILTIN */

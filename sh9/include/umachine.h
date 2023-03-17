/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = umachine.h :                                         */
/*   FUNC = ;                                                    */
/*   CLAS = UNIT ;                                               */
/*   END ;                                                       */
/*****************************************************************/
#ifndef _UMACHINE
#define _UMACHINE

#include <builtin.h>

#define set_gbr(base)               _builtin_set_gbr(base)
#define get_gbr()                   _builtin_get_gbr()
#define gbr_read_byte(offset)       _builtin_gbr_read_byte(offset)
#define gbr_read_word(offset)       _builtin_gbr_read_word(offset)
#define gbr_read_long(offset)       _builtin_gbr_read_long(offset)
#define gbr_write_byte(offset,data) _builtin_gbr_write_byte(offset,data)
#define gbr_write_word(offset,data) _builtin_gbr_write_word(offset,data)
#define gbr_write_long(offset,data) _builtin_gbr_write_long(offset,data)
#define gbr_and_byte(offset,mask)   _builtin_gbr_and_byte(offset,mask)
#define gbr_or_byte(offset,mask)    _builtin_gbr_or_byte(offset,mask)
#define gbr_xor_byte(offset,mask)   _builtin_gbr_xor_byte(offset,mask)
#define gbr_tst_byte(offset,mask)   _builtin_gbr_tst_byte(offset,mask)
#define tas(addr)                   _builtin_tas(addr)
#define trapa(trap_no)              _builtin_trapa(trap_no)
#define macw(ptr1, ptr2, count)        _builtin_macw(ptr1, ptr2, count)
#define macwl(ptr1, ptr2, count, mask) _builtin_macwl(ptr1, ptr2, count, mask)
#define macl(ptr1, ptr2, count)        _builtin_macl(ptr1, ptr2, count)
#define macll(ptr1, ptr2, count, mask) _builtin_macll(ptr1, ptr2, count, mask)
#define trapa_svc                      _builtin_trapa_svc
#define prefetch                       _builtin_prefetch
#define set_fpscr(cr)                  _builtin_set_fpscr(cr)
#define get_fpscr()                    _builtin_get_fpscr()
#define fipr(vect1, vect2)             _builtin_fipr(vect1, vect2)
#define ftrv(vec1, vec2)               _builtin_ftrv(vec1, vec2)
#define ftrvadd(vec1, vec2, vec3)      _builtin_ftrvadd(vec1, vec2, vec3)
#define ftrvsub(vec1, vec2, vec3)      _builtin_ftrvsub(vec1, vec2, vec3)
#define mtrx4mul(mat1, mat2)           _builtin_mtrx4mul(mat1, mat2)
#define mtrx4muladd(mat1, mat2, mat3)  _builtin_mtrx4muladd(mat1, mat2, mat3)
#define mtrx4mulsub(mat1, mat2, mat3)  _builtin_mtrx4mulsub(mat1, mat2, mat3)
#define ld_ext(mat)                    _builtin_ld_ext(mat)
#define st_ext(mat)                    _builtin_st_ext(mat)
#define add4(vec1, vec2, vec3)         _builtin_add4(vec1, vec2, vec3)
#define sub4(vec1, vec2, vec3)         _builtin_sub4(vec1, vec2, vec3)
#define trace(v)                       _builtin_trace(v)
#define nop()                          _builtin_nop()
#define swapb(data)                    _builtin_swapb(data)
#define end_cnvw(rm)                   _builtin_swapb(rm)
#define swapw(data)                    _builtin_swapw(data)
#define end_cnvl(data)                 _builtin_end_cnvl(data)
#define dmulu_h(data1, data2)          _builtin_dmulu_h(data1, data2)
#define dmulu_l(data1, data2)          _builtin_dmulu_l(data1, data2)
#define dmuls_h(data1, data2)          _builtin_dmuls_h(data1, data2)
#define dmuls_l(data1, data2)          _builtin_dmuls_l(data1, data2)
#define fsca(angle,sinv,cosv)          _builtin_fsca(angle,sinv,cosv)
#define fsrra(data)                    _builtin_fsrra(data)

#define pabs_lf(data)             _builtin_pabs_lf(data)
#define pabs_la(data)             _builtin_pabs_la(data)
#define pdmsb_lf(data)            _builtin_pdmsb_lf(data)
#define pdmsb_la(data)            _builtin_pdmsb_la(data)
#define psha_lf(data, count)      _builtin_psha_lf(data, count)
#define psha_la(data, count)      _builtin_psha_la(data, count)
#define long_as_lfixed(data)      _builtin_long_as_lfixed(data)
#define lfixed_as_long(data)      _builtin_lfixed_as_long(data)
#define rndtoa(data)              _builtin_rndtoa(data)
#define rndtof(data)              _builtin_rndtof(data)
#define set_cs(mode)              _builtin_set_cs(mode)

#define icbi(p)                   _builtin_icbi(p)
#define ocbi(p)                   _builtin_ocbi(p)
#define ocbp(p)                   _builtin_ocbp(p)
#define ocbwb(p)                  _builtin_ocbwb(p)
#define prefi(p)                  _builtin_prefi(p)
#define sleep_i(size)             _builtin_sleep_i(size)
#define synco()                   _builtin_synco()

#define movt()                    _builtin_movt()
#define xtrct(data1, data2)       _builtin_xtrct(data1, data2)
#define addc(data1, data2)        _builtin_addc(data1, data2)
#define ovf_addc(data1, data2)    _builtin_ovf_addc(data1, data2)
#define addv(data1, data2)        _builtin_addv(data1, data2)
#define ovf_addv(data1, data2)    _builtin_ovf_addv(data1, data2)
#define subc(data1, data2)        _builtin_subc(data1, data2)
#define unf_subc(data1, data2)    _builtin_unf_subc(data1, data2)
#define subv(data1, data2)        _builtin_subv(data1, data2)
#define unf_subv(data1, data2)    _builtin_unf_subv(data1, data2)
#define negc(data)                _builtin_negc(data)
#define div1(data1, data2)        _builtin_div1(data1, data2)
#define div0s(data1, data2)       _builtin_div0s(data1, data2)
#define div0u()                   _builtin_div0u()
#define rotl(data)                _builtin_rotl(data)
#define rotr(data)                _builtin_rotr(data)
#define rotcl(data)               _builtin_rotcl(data)
#define rotcr(data)               _builtin_rotcr(data)
#define shll(data)                _builtin_shll(data)
#define shlr(data)                _builtin_shlr(data)
#define shar(data)                _builtin_shar(data)

#define clrt()                    _builtin_clrt()
#define sett()                    _builtin_sett()
#define clipsb(data)              _builtin_clipsb(data)
#define clipsw(data)              _builtin_clipsw(data)
#define clipub(data)              _builtin_clipub(data)
#define clipuw(data)              _builtin_clipuw(data)
#define set_tbr(data)             _builtin_set_tbr(data)
#define get_tbr()                 _builtin_get_tbr()

#define bset(data, offset)        _builtin_bset(data, offset)
#define bclr(data, offset)        _builtin_bclr(data, offset)
#define bcopy(data1, offset1, data2, offset2) \
                                  _builtin_bcopy(data1, offset1, data2, offset2)
#define bnotcopy(data1, offset1, data2, offset2) \
                                  _builtin_bnotcopy(data1, offset1, data2, offset2)
#endif

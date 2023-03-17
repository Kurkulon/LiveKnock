/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = smachine.h :                                        */
/*   FUNC = ;                                                    */
/*   CLAS = UNIT ;                                               */
/*   END ;                                                       */
/*****************************************************************/
#ifndef _SMACHINE
#define _SMACHINE

#include <builtin.h>

#define set_imask(mask)             _builtin_set_imask(mask)
#define get_imask()                 _builtin_get_imask()
#define set_cr(cr)                  _builtin_set_cr(cr)
#define get_cr()                    _builtin_get_cr()
#define set_vbr(base)               _builtin_set_vbr(base)
#define get_vbr()                   _builtin_get_vbr()
#define sleep()                     _builtin_sleep()
#define ldtlb()                     _builtin_ldtlb()

#define set_circ_x(array, size)   _builtin_set_circ_x(array, size)
#define set_circ_y(array, size)   _builtin_set_circ_y(array, size)
#define clr_circ()                _builtin_clr_circ()

#define sr_jsr(func, imask)       _builtin_sr_jsr(func, imask)

#endif

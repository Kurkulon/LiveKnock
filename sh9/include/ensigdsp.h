/***************************************************************************/
/* Copyright (C) 1992 (1995 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************
* File:     ensigdsp.h
* Purpose:  Common
* Create:   1998.03.20 Rev. 1.0
***********************************************************/

/*
** Copyright Ensigma Ltd. 1995
**
** Unauthorised copying or distribution of this software is prohibited.
**
** Version 1.0.
**
*/

#include <_dspc_type.h>

/*
** ENSIGMA DSP Library
*/

/* Constants */
#ifndef _ENSIGDSP
#define _ENSIGDSP

#define BIQUAD_SIZE     6       /* no. coefficients in an IIR biquad */

#define EDSP_OK         0
#define EDSP_BAD_ARG    1
#define EDSP_NO_HEAP    2

#define EFFTALLSCALE    (-1L)
#define EFFTMIDSCALE    0x55555555L
#define EFFTNOSCALE     0x00000000L

#ifdef __cplusplus            /*A-10-014-01*/
extern"C"{                    /*A-10-014-01*/
#endif                        /*A-10-014-01*/

/*
** Fourier transforms
*/
int FftComplex(_QUALIFY__X _TYPE__FIXED op_x[],
               _QUALIFY__Y _TYPE__FIXED op_y[],
               const _QUALIFY__X _TYPE__FIXED ip_x[],
               const _QUALIFY__Y _TYPE__FIXED ip_y[],
               long size,
               long scale);
int FftInComplex(_QUALIFY__X _TYPE__FIXED data_x[],
                 _QUALIFY__Y _TYPE__FIXED data_y[],
                 long size,
                 long scale);
int FftReal(_QUALIFY__X _TYPE__FIXED op_x[],
            _QUALIFY__Y _TYPE__FIXED op_y[],
            const _TYPE__FIXED ip[],
            long size,
            long scale);
            /* int ip_is_x);*/
int FftInReal(_QUALIFY__X _TYPE__FIXED data_x[],
              _QUALIFY__Y _TYPE__FIXED data_y[],
              long size,
              long scale,
              int ip_all_x);
int IfftComplex(_QUALIFY__X _TYPE__FIXED op_x[],
                _QUALIFY__Y _TYPE__FIXED op_y[],
                const _QUALIFY__X _TYPE__FIXED ip_x[],
                const _QUALIFY__Y _TYPE__FIXED ip_y[],
                long size,
                long scale);
int IfftInComplex(_QUALIFY__X _TYPE__FIXED data_x[],
                  _QUALIFY__Y _TYPE__FIXED data_y[],
                  long size,
                  long scale);
int IfftReal(_QUALIFY__X _TYPE__FIXED op_x[],
             _QUALIFY__Y _TYPE__FIXED op_y[],
             const _QUALIFY__X _TYPE__FIXED ip_x[],
             const _QUALIFY__Y _TYPE__FIXED ip_y[],
             long size,
             long scale,
             int op_all_x);
int IfftInReal(_QUALIFY__X _TYPE__FIXED data_x[],
               _QUALIFY__Y _TYPE__FIXED data_y[],
               long size,
               long scale,
               int op_all_x);
int InitFft(long max_size);
void FreeFft(void);          /*A-10-015-01*/
int LogMagnitude(_TYPE__FIXED output[],
                 const _QUALIFY__X _TYPE__FIXED ip_x[],
                 const _QUALIFY__Y _TYPE__FIXED ip_y[],
                 long no_elements,
                 float fscale);

/*
** These three variables are for the internal use of the library FFT
** functions only. They should not be accessed by user programs.
*/
extern long max_fft_size;
extern short *twtble;

/*
** Window functions
*/
int GenBlackman(_TYPE__FIXED output[], long win_size);
int GenHamming(_TYPE__FIXED output[], long win_size);
int GenHanning(_TYPE__FIXED output[], long win_size);
int GenTriangle(_TYPE__FIXED output[], long win_size);

/*
** Filters. The coefficients must be supplied in X and the workspace in Y.
** If it is straightforward we can support the opposite, ie Xworkspace and
** Ycoeff.
*/
int FreeFir(_QUALIFY__Y _TYPE__FIXED **workspace, long no_coeffs);
int InitFir(_QUALIFY__Y _TYPE__FIXED **workspace, long no_coeffs);
int InitIir(_QUALIFY__Y _TYPE__FIXED **workspace, long no_sections);
int FreeIir(_QUALIFY__Y _TYPE__FIXED **workspace, long no_sections);
int InitDIir(_QUALIFY__Y _TYPE_L__FIXED **workspace, long no_sections);
int FreeDIir(_QUALIFY__Y _TYPE_L__FIXED **workspace, long no_sections);
int InitLms(_QUALIFY__Y _TYPE__FIXED **workspace, long no_coeffs);
int FreeLms(_QUALIFY__Y _TYPE__FIXED **workspace, long no_coeffs);
int Fir(_TYPE__FIXED output[],
        const _TYPE__FIXED input[],
        long no_samples,
        const _QUALIFY__X _TYPE__FIXED coeff[],
        long no_coeffs,
        int res_shift,
        _QUALIFY__Y _TYPE__FIXED *workspace);
int Fir1(short *output,
         short input,
         const short coeff[],   /* X memory */
         long no_coeffs,
         int res_shift,
         short *workspace);     /* Y memory */
int Iir(_TYPE__FIXED output[],
        const _TYPE__FIXED input[],
        long no_samples,
        const _QUALIFY__X _TYPE__FIXED coeff[],
        long no_sections,
        _QUALIFY__Y _TYPE__FIXED *workspace);
int Iir1(short *output,
         short input,
         const short coeff[],    /* X memory */
         long no_sections,
         short *workspace);      /* Y memory */
int DIir(_TYPE__FIXED output[],
         const _TYPE__FIXED input[],
         long no_samples,
         const _QUALIFY__X _TYPE_L__FIXED coeff[],
         long no_sections,
         _QUALIFY__Y _TYPE_L__FIXED *workspace);
int DIir1(short *output,
          const short input, /*98.01.09        C-10-005-01 */ 
          /*    short input,    98.01.09             D-10-005-01 */
          const long coeff[],    /* X memory */
          long no_sections,
          long *workspace);      /* Y memory */
int Lms(_TYPE__FIXED output[],
        const _TYPE__FIXED input[],
        const _TYPE__FIXED ref_output[],
        long no_samples,
        _QUALIFY__X _TYPE__FIXED coeff[],
        long no_coeffs,
        int res_shift,
        short conv_fact,
        _QUALIFY__Y _TYPE__FIXED *workspace);
int Lms1(short *output,
         short input,
         short ref_output,
         short coeff[],        /* X memory */
         long no_coeffs,
         int res_shift,
         short conv_fact,
         short *workspace);    /* Y memory */

/*
** Convolution and Correlation
*/
int ConvComplete(_TYPE__FIXED output[],
                 const _QUALIFY__X _TYPE__FIXED ip_x[],
                 const _QUALIFY__Y _TYPE__FIXED ip_y[],
                 long x_size,
                 long y_size,
                 int res_shift);
int ConvCyclic(_TYPE__FIXED output[],
               const _QUALIFY__X _TYPE__FIXED ip_x[],
               const _QUALIFY__Y _TYPE__FIXED ip_y[],
               long size,
               int res_shift);
int ConvPartial(_TYPE__FIXED output[],
                const _QUALIFY__X _TYPE__FIXED ip_x[],
                const _QUALIFY__Y _TYPE__FIXED ip_y[],
                long x_size,
                long y_size,
                int res_shift);
int Correlate(_TYPE__FIXED output[],
              const _QUALIFY__X _TYPE__FIXED ip_x[],
              const _QUALIFY__Y _TYPE__FIXED ip_y[],
              long x_size,
              long y_size,
              long no_corr,
              int x_is_larger,
              int res_shift);
int CorrCyclic(_TYPE__FIXED output[],
               const _QUALIFY__X _TYPE__FIXED ip_x[],
               const _QUALIFY__Y _TYPE__FIXED ip_y[],
               long size,
               int reverse,
               int res_shift);


/*
** Miscellaneous
*/
int GenGWnoise(_TYPE__FIXED output[], long no_samples, float variance);

int MinI(_TYPE__FIXED **min_ptr,
         _TYPE__FIXED input[],
         long no_elements,
         int src_is_x);
int MaxI(_TYPE__FIXED **max_ptr,
         _TYPE__FIXED input[],
         long no_elements,
         int src_is_x);
int PeakI(_TYPE__FIXED **peak_ptr,
          _TYPE__FIXED input[],
          long no_elements,
          int src_is_x);

int Mean(_TYPE__FIXED *mean,
         const _TYPE__FIXED input[],
         long no_elements,
         int src_is_x);
int Variance(_TYPE_L__FIXED *variance,
             _TYPE__FIXED *mean,
             const _TYPE__FIXED input[],
             long no_elements,
             int src_is_x);

int VectorMult(_TYPE__FIXED output[],
               const _QUALIFY__X _TYPE__FIXED ip_x[],
               const _QUALIFY__Y _TYPE__FIXED ip_y[],
               long no_elements,
               int res_shift);
int MatrixMult(void *op_matrix,
               const _QUALIFY__X void *ip_x,
               const _QUALIFY__Y void *ip_y,
               long m,
               long n,
               long p,
               int x_first,
               int res_shift);
int MsPower(_TYPE_L__FIXED *output,
            const _TYPE__FIXED input[],
            long no_elements,
            int src_is_x);

int CopyXtoY(_QUALIFY__Y _TYPE__FIXED op_y[],
             const _QUALIFY__X _TYPE__FIXED ip_x[],
             long n);
int CopyYtoX(_QUALIFY__X _TYPE__FIXED op_x[],
             const _QUALIFY__Y _TYPE__FIXED op_y[],
             long n);
int CopyToX(_QUALIFY__X _TYPE__FIXED op_x[],
            const _TYPE__FIXED input[],
            long n);
int CopyToY(_QUALIFY__Y _TYPE__FIXED op_y[],
            const _TYPE__FIXED input[],
            long n);
int CopyFromX(_TYPE__FIXED output[],
              const _QUALIFY__X _TYPE__FIXED ip_x[],
              long n);
int CopyFromY(_TYPE__FIXED output[],
              const _QUALIFY__Y _TYPE__FIXED ip_y[],
              long n);

int Limit(_TYPE__FIXED data_xy[],
          long no_elements,
          int data_is_x);

#ifdef __cplusplus           /*A-10-014-01*/
}                            /*A-10-014-01*/
#endif                       /*A-10-014-01*/

#endif

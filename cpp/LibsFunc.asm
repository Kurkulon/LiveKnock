	.CPU   SH2                                  
	
	
;+++++++++++++++++++++++++++++++++++++++++++++++

StatusRegisterStack:	.EQU	H'FFFFABA0

wMUT34_Map_Index:		.EQU	H'FFFF89E0 

;+++++++++++++++++++++++++++++++++++++++++++++++

	.EXPORT __disable_irq, __enable_irq, Set_Intterupt_Mask, Add_Lim_FFFF, Add_R4w_R5w, Add_Lim_FFFFFFFF
	.EXPORT memsetz, mem_decr, mem_incr, Lim_FF, Lim_FFFF, Lim16, Lim32, Mul_Div, Mul_DW_Div, Mul_Div_R 
	.EXPORT Mul_R4_R5w_Div_R6w_Round_R0, Mul_R4_R5_Div_128_Into_R0, Mul_Fix7_R, Mul32_Fix7, Mul_R4_R5w_Div_128_Round_R0
	.EXPORT Mul_Fix8_Lim_FFFF, Mul32_Fix8, Mul_Fix8_R, Mul_R4_R5w_Div_256_Round_R0, SHLR8
	.EXPORT R4_Div_65536_ZeroExtendWord_Into_R0_sub_86A, R4_Mult_256_ZeroExtendWord_Into_R0_sub_870, Mult_R4_65536
	.EXPORT Div_256_R, Div_65536_R, SwapBytes16, Div_R4_R5__R0, Div_DW, Div_WW, DIV_DW_R, Interpolate_256, sub_AE0
	.EXPORT interpolate_r4_r5_r6, sub_B68, Table_Lookup_byte_2D_3D, Table_Lookup_Axis, Interpolate, GET_FROM_MASSIVE_byte
	.EXPORT GET_FROM_MASSIVE_word, Query_byte_2D_3D_Table, GET_LOC_DIM_sub_DF6, Table_Lookup_word_2D_3D, sub_EA6, sub_EBC, Mul_Lim_FFFF, Mul16, Mul32_lim, Sub_Lim_0

	.EXPORT ___disable_irq, ___enable_irq, _Set_Intterupt_Mask, _Add_Lim_FFFF, _Add_R4w_R5w, _Add_Lim_FFFFFFFF
	.EXPORT _memsetz, _mem_decr, _mem_incr, _Lim_FF, _Lim_FFFF, _Lim16, _Lim32, _Mul_Div, _Mul_DW_Div, _Mul_Div_R
	.EXPORT _Mul_R4_R5w_Div_R6w_Round_R0, _Mul_R4_R5_Div_128_Into_R0, _Mul_Fix7_R, _Mul32_Fix7, _Mul_R4_R5w_Div_128_Round_R0
	.EXPORT _Mul_Fix8_Lim_FFFF, _Mul32_Fix8, _Mul_Fix8_R, _Mul_R4_R5w_Div_256_Round_R0, _SHLR8
	.EXPORT _R4_Div_65536_ZeroExtendWord_Into_R0_sub_86A, _R4_Mult_256_ZeroExtendWord_Into_R0_sub_870, _Mult_R4_65536
	.EXPORT _Div_256_R, _Div_65536_R, _SwapBytes16, _Div_R4_R5__R0, _Div_DW, _Div_WW, _DIV_DW_R, _Interpolate_256, _sub_AE0
	.EXPORT _interpolate_r4_r5_r6, _sub_B68, _Table_Lookup_byte_2D_3D, _Table_Lookup_Axis, _Interpolate, _GET_FROM_MASSIVE_byte
	.EXPORT _GET_FROM_MASSIVE_word, _Query_byte_2D_3D_Table, _GET_LOC_DIM_sub_DF6, _Table_Lookup_word_2D_3D, _sub_EA6, _sub_EBC, _Mul_Lim_FFFF, _Mul16, _Mul32_lim, _Sub_Lim_0

;+++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    P_LIBSFUNC, CODE, LOCATE=H'400

; =============== S U B	R O U T	I N E ==========


__disable_irq:									
___disable_irq:									
												
				mov.l	r0, @-r15				
				mov.l	r3, @-r15				
				mov.l	r4, @-r15				
				stc	sr, r0						
				mov	r0, r4						
				or	#h'F0, r0                   
				ldc	r0, sr						

loc_40E:										
				mov.l	#StatusRegisterStack, r0
				mov.l	@r0, r3					
				mov.l	r4, @-r3				
				mov.l	r3, @r0					
				mov.l	@r15+, r4				
				mov.l	@r15+, r3				
				rts								
				mov.l	@r15+, r0				

; End of function __disable_irq

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


__enable_irq:									
___enable_irq:									
												
				mov.l	r0, @-r15				
				mov.l	r1, @-r15				
				mov.l	#StatusRegisterStack, r0
				mov.l	@r0, r1					
				ldc.l	@r1+, sr				
				mov.l	r1, @r0					
				mov.l	@r15+, r1				
				rts								
				mov.l	@r15+, r0				

; End of function __enable_irq


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; SR = (SR & ~0xF0) | ((R4 & 0xF) << 4)

Set_Intterupt_Mask:								
_Set_Intterupt_Mask:								
												
				mov.l	r0, @-r15				
				mov.l	r1, @-r15				
				stc	sr, r0						
				or	#h'F0, r0                   
				ldc	r0, sr						
				mov.l	#~h'F0, r1              
				and	r1, r0						
				mov	#h'F, r1                    
				and	r1, r4						
				shll2	r4						
				shll2	r4						
				or	r4, r0						
				ldc	r0, sr						
				mov.l	@r15+, r1				
				rts								
				mov.l	@r15+, r0				

; End of function Set_Intterupt_Mask

; ----------------------------------------------

;+++++++++++++++++++++++++++++++++++++++++++++++
;	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++

	.align 256


; =============== S U B	R O U T	I N E ==========

; R0 = Min(R4w + R5w, 0xFFFF)

Add_Lim_FFFF:									
_Add_Lim_FFFF:									
												
				extu.w	r5, r5					
				extu.w	r4, r0					
				add	r5, r0						
				mov	#h'FFFFFFFF, r4             
				extu.w	r4, r4					
				cmp/hs	r4, r0					
												
				bf	locret_510					

				mov	r4, r0						


locret_510:										
				rts								
				nop								

; End of function Add_Lim_FFFF


;+++++++++++++++++++++++++++++++++++++++++++++++
;	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = R4w + R5w

Add_R4w_R5w:									
_Add_R4w_R5w:									
												
				extu.w	r5, r5					
				extu.w	r4, r0					
				rts								
				add	r5, r0						

; End of function Add_R4w_R5w

;+++++++++++++++++++++++++++++++++++++++++++++++
;	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++



; =============== S U B	R O U T	I N E ==========

; R0 = Min(R4+R5, 0xFFFFFFFF)

Add_Lim_FFFFFFFF:								
_Add_Lim_FFFFFFFF:								
												
				mov	r4, r0						
				clrt							
				addc	r5, r0					
				bf	locret_526					

				mov	#h'FFFFFFFF, r0             


locret_526:										
				rts								
				nop								

; End of function Add_Lim_FFFFFFFF

; ----------------------------------------------

				.data.w h'FFFF
				

; =============== S U B	R O U T	I N E ==========

; while	(R4 < R5) { *(u16*)R4++	= 0 };

memsetz:										
_memsetz:										
												
				mov.l	r10, @-r15				
				mov	#0, r10						


loc_530:										
				cmp/hs	r5, r4					
				bt	locret_53A					

				mov.w	r10, @r4				
				bra	loc_530						
				add	#2, r4						

; ----------------------------------------------

locret_53A:										
				rts								
				mov.l	@r15+, r10				

; End of function memsetz


;+++++++++++++++++++++++++++++++++++++++++++++++
;	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; while	(R4 < R5) { if (*R4 != 0) *R4 -= 1; R4++; };

mem_decr:										
_mem_decr:										
												
				mov.l	r0, @-r15				


loc_540:										
				cmp/hs	r5, r4					
				bt	locret_55E					

				stc	sr, r0						
				mov.l	r0, @-r15				
				or	#h'F0, r0                   
				ldc	r0, sr						
				mov.w	@r4, r0					
				extu.w	r0, r0					
				cmp/eq	#0, r0					
				bt	loc_558						

				add	#-1, r0						
				mov.w	r0, @r4					


loc_558:										
				ldc.l	@r15+, sr				
				bra	loc_540						
				add	#2, r4						

; ----------------------------------------------

locret_55E:										
				rts								
				mov.l	@r15+, r0				

; End of function mem_decr


;+++++++++++++++++++++++++++++++++++++++++++++++
;	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++



; =============== S U B	R O U T	I N E ==========

; while	(R4 < R5) { if (*R4 < 0xFFFF) *R4 += 1;	R4++; };

mem_incr:										
_mem_incr:										
												
				mov.l	r0, @-r15				
				mov.l	r10, @-r15				
				mov	#h'FFFFFFFF, r10            
				extu.w	r10, r10				


loc_56A:										
				cmp/hs	r5, r4					
				bt	loc_588						

				stc	sr, r0						
				mov.l	r0, @-r15				
				or	#h'F0, r0                   
				ldc	r0, sr						
				mov.w	@r4, r0					
				extu.w	r0, r0					
				cmp/eq	r10, r0					
				bt	loc_582						

				add	#1, r0						
				mov.w	r0, @r4					


loc_582:										
				ldc.l	@r15+, sr				
				bra	loc_56A						
				add	#2, r4						

; ----------------------------------------------

loc_588:										
				mov.l	@r15+, r10				
				rts								
				mov.l	@r15+, r0				

; End of function mem_incr

; ----------------------------------------------


				.data.w h'FFFF
				

; =============== S U B	R O U T	I N E ==========

; R0 = (R4 < 0xFF) ? R4	: 0xFF;

Lim_FF:											
_Lim_FF:											
												
				extu.w	r4, r0					
				mov	#h'FFFFFFFF, r4             
												
				bra	loc_59E						
				extu.b	r4, r4					
												

; End of function Lim_FF


;+++++++++++++++++++++++++++++++++++++++++++++++
;	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++



; =============== S U B	R O U T	I N E ==========

; R0 = (R4 < 0xFFFF) ? R4 : 0xFFFF;

Lim_FFFF:										
_Lim_FFFF:										
												
				mov	r4, r0						
				mov	#h'FFFFFFFF, r4             
												
				extu.w	r4, r4					


loc_59E:										
				cmp/hs	r4, r0					
				bf	locret_5A4					

				mov	r4, r0						


locret_5A4:										
				rts								
				nop								

; End of function Lim_FFFF


;+++++++++++++++++++++++++++++++++++++++++++++++
;	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = R4w Lim[R6w...R5w];

Lim16:											
_Lim16:											
												
				extu.w	r4, r0					
				extu.w	r6, r6					
				bra	loc_5B2						
				extu.w	r5, r5					

; End of function Lim16


; =============== S U B	R O U T	I N E ==========

; R0 = R4 Lim[R6...R5];

Lim32:											
_Lim32:											
												
												
				mov	r4, r0						


loc_5B2:										
				cmp/hs	r6, r5					
				bt	loc_5BC						


; if (R5 < R6) { t = R5; R5 = R6; R6 = t; };


				mov	r5, r4						
				mov	r6, r5						
				mov	r4, r6						


loc_5BC:										
				cmp/hs	r5, r0					
				bf	loc_5C4						

				bra	locret_5CA					
				mov	r5, r0						

; ----------------------------------------------

loc_5C4:										
				cmp/hs	r6, r0					
				bt	locret_5CA					

				mov	r6, r0						


locret_5CA:										
												
				rts								
				nop								

; End of function Lim32

; ----------------------------------------------

				.data.w h'FFFF
				
;+++++++++++++++++++++++++++++++++++++++++++++++
;	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = R4w * R5w / R6w

Mul_Div:										
_Mul_Div:										
												
				sts.l	pr, @-r15				
				extu.w	r4, r4					
				extu.w	r5, r5					
				mulu	r4, r5					
				sts	macl, r4					
				extu.w	r6, r5					
				mov.l	#Div_DW, r6				
				jsr	@r6 ; Div_DW				
				nop								

				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Mul_Div


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = (R4 * R5w) / R6w;

Mul_DW_Div:										
_Mul_DW_Div:										
												
				extu.w	r5, r5					
				extu.w	r6, r6					
				mov	r6, r0						
				cmp/eq	#0, r0					
				bt	loc_684						

				dmulu.l	r4, r5					
				sts	mach, r4					
				sts	macl, r5					
				cmp/hs	r6, r4					
				bt	loc_684						

				div0u							
				rotcl	r5						

loc_600:										
				div1	r6, r4
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				bra	locret_686					
				mov	r5, r0						

				.NOPOOL

; ----------------------------------------------

loc_684:										
												
				mov	#h'FFFFFFFF, r0             


locret_686:										
				rts								
				nop								

; End of function Mul_DW_Div


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++



; =============== S U B	R O U T	I N E ==========

; R0 = (R4w * R5w + R6w/2) / R6w

Mul_Div_R:										
_Mul_Div_R:										
												
				sts.l	pr, @-r15				
				extu.w	r4, r4					
				extu.w	r5, r5					
				mulu	r4, r5					
				sts	macl, r4					
				extu.w	r6, r5					
				mov.l	#DIV_DW_R, r6			
				jsr	@r6 ; DIV_DW_R				
				nop								

				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Mul_Div_R


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = (R4 * R5w + R6w/2) / R6w;

Mul_R4_R5w_Div_R6w_Round_R0:					
_Mul_R4_R5w_Div_R6w_Round_R0:					
												
				mov.l	r11, @-r15				
				extu.w	r5, r5					
				extu.w	r6, r6					
				mov	r6, r0						
				cmp/eq	#0, r0					
				bt	loc_74C						

				mov	r6, r11						
				shlr	r11						
				mov	#0, r0						
				dmulu.l	r4, r5					
				sts	mach, r4					
				sts	macl, r5					
				clrt							
				addc	r11, r5					
				addc	r0, r4					
				cmp/hs	r6, r4					
				bt	loc_74C						

				div0u							
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				div1	r6, r4					
				rotcl	r5						
				bra	locret_74E					
				mov	r5, r0						

				.NOPOOL
; ----------------------------------------------

loc_74C:										
												
				mov	#h'FFFFFFFF, r0             


locret_74E:										
				rts								
				mov.l	@r15+, r11				

; End of function Mul_R4_R5w_Div_R6w_Round_R0


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = R4w * R5w / 128;	Без округления

Mul_R4_R5_Div_128_Into_R0:						
_Mul_R4_R5_Div_128_Into_R0:						
												
				extu.w	r5, r5					
				extu.w	r4, r4					
				mulu	r4, r5					
				sts	macl, r0					
				shlr2	r0						
				shlr2	r0						
				bra	loc_772						
				shlr2	r0						

; End of function Mul_R4_R5_Div_128_Into_R0


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = (R4w * R5w + 64)	/ 128; С округлением

Mul_Fix7_R:										
_Mul_Fix7_R:										
												
				extu.w	r5, r5					
				extu.w	r4, r4					
				mulu	r4, r5					
				sts	macl, r0					
				shlr2	r0						
				shlr2	r0						
				shlr2	r0						
				add	#1, r0						


loc_772:										
				shlr	r0						
				mov.l	#H'FFFF, r4				
				cmp/hi	r4, r0					
				bf	locret_77C					

				mov	r4, r0						


locret_77C:										
				rts								
				nop								

; End of function Mul_Fix7_R

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++



; =============== S U B	R O U T	I N E ==========

; R0 = R4 * R5w	/ 128;

Mul32_Fix7:										
_Mul32_Fix7:										
												
				extu.w	r5, r5					
				dmulu.l	r4, r5					
				sts	mach, r5					
				sts	macl, r0					
				mov.l	#128, r4				
				cmp/hs	r4, r5					
				bt	loc_7A0						

				shll16	r5						
				shll8	r5						
				shll	r5						
				shlr2	r0						
				shlr2	r0						
				shlr2	r0						
				shlr	r0						
				bra	locret_7A2					
				or	r5, r0						

				.NOPOOL
				
; ----------------------------------------------

loc_7A0:										
				mov	#h'FFFFFFFF, r0             


locret_7A2:										
				rts								
				nop								

; End of function Mul32_Fix7

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++



; =============== S U B	R O U T	I N E ==========

; R0 = (R4 * R5w + 64) / 128;

Mul_R4_R5w_Div_128_Round_R0:					
_Mul_R4_R5w_Div_128_Round_R0:					
												
				extu.w	r5, r5					
				dmulu.l	r4, r5					
				sts	mach, r5					
				sts	macl, r0					
				mov.l	#128, r4				
				cmp/hs	r4, r5					
				bt	loc_7CA						

				shll16	r5						
				shll8	r5						
				shll	r5						
				shlr2	r0						
				shlr2	r0						
				shlr2	r0						
				add	#1, r0						
				shlr	r0						
				clrt							
				addc	r5, r0					
				bf	locret_7CC					


loc_7CA:										
				mov	#h'FFFFFFFF, r0             


locret_7CC:										
				rts								
				nop								

; End of function Mul_R4_R5w_Div_128_Round_R0


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = R4w * R5w / 256;

Mul_Fix8_Lim_FFFF:								
_Mul_Fix8_Lim_FFFF:								
												
				extu.w	r5, r5					
				extu.w	r4, r4					
				mulu	r4, r5					
				sts	macl, r0					
				shlr8	r0						
				mov.l	#H'FFFF, r4				
				cmp/hi	r0, r4					
				bt	locret_7E2					

				mov	r4, r0						


locret_7E2:										
				rts								
				nop								

; End of function Mul_Fix8_Lim_FFFF

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++



; =============== S U B	R O U T	I N E ==========

; R0 = R4 * R5w	/ 256;

Mul32_Fix8:										
_Mul32_Fix8:										
												
				extu.w	r5, r5					
				dmulu.l	r4, r5					
				sts	mach, r4					
				sts	macl, r0					
				mov.l	#255, r5				
				cmp/hi	r5, r4					
				bt	loc_7FE						

				shll16	r4						
				shll8	r4						
				shlr8	r0						
				bra	locret_800					
				add	r4, r0						

				.NOPOOL

; ----------------------------------------------

loc_7FE:										
				mov	#h'FFFFFFFF, r0             


locret_800:										
				rts								
				nop								

; End of function Mul32_Fix8


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = (R4w * R5w + 128) / 256

Mul_Fix8_R:										
_Mul_Fix8_R:										
												
				extu.w	r5, r5					
				extu.w	r4, r4					
				mulu	r4, r5					
				sts	macl, r0					
				shlr2	r0						
				shlr2	r0						
				shlr2	r0						
				shlr	r0						
				add	#1, r0						
				shlr	r0						
				mov.l	#h'FFFF, r4             
				cmp/hi	r4, r0					
				bf	locret_820					

				mov	r4, r0						


locret_820:										
				rts								
				nop								

; End of function Mul_Fix8_R


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = (R4 * R5w + 128)	/ 256;

Mul_R4_R5w_Div_256_Round_R0:
_Mul_R4_R5w_Div_256_Round_R0:

				mov.l	r1, @-r15				
				extu.w	r5, r5					
				dmulu.l	r4, r5					
				sts	mach, r1					
				sts	macl, r0					
				mov.l	#255, r4				
				cmp/hi	r4, r1					
				bt	loc_84A						

				shll16	r1						
				shll8	r1						
				shlr2	r0						
				shlr2	r0						
				shlr2	r0						
				shlr	r0						
				add	#1, r0						
				shlr	r0						
				clrt							
				addc	r1, r0					
				bf	locret_84C					


loc_84A:										
				mov	#h'FFFFFFFF, r0             


locret_84C:										
				rts								
				mov.l	@r15+, r1				

; End of function Mul_R4_R5w_Div_256_Round_R0

; ----------------------------------------------


;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = (byte)(R4 >> 8);

SHLR8:											
_SHLR8:											
												
				shlr8	r4						
				rts								
				extu.b	r4, r0					

; End of function SHLR8


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========


R4_Div_65536_ZeroExtendWord_Into_R0_sub_86A:	
_R4_Div_65536_ZeroExtendWord_Into_R0_sub_86A:	
												
				shlr16	r4						
				rts								
				extu.w	r4, r0					

; End of function R4_Div_65536_ZeroExtendWord_Into_R0_sub_86A


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========


R4_Mult_256_ZeroExtendWord_Into_R0_sub_870:		
_R4_Mult_256_ZeroExtendWord_Into_R0_sub_870:		
												
				shll8	r4						
				rts								
				extu.w	r4, r0					

; End of function R4_Mult_256_ZeroExtendWord_Into_R0_sub_870

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++



; =============== S U B	R O U T	I N E ==========

; R4 *=	65536;

Mult_R4_65536:									
_Mult_R4_65536:									
												
				shll16	r4						
				rts								
				mov	r4, r0						

; End of function Mult_R4_65536


;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; R0 = Min((R4+128)/256, 0xFF)

Div_256_R:										
_Div_256_R:										
												
												
				swap.b	r4, r0					
				extu.b	r0, r0					
				shll16	r4						
				shll8	r4						
				shll	r4						
				bf	loc_88A						

				add	#1, r0						


loc_88A:										
				mov	#h'FFFFFFFF, r4             
				extu.b	r4, r4					
				cmp/hs	r4, r0					
				bf	locret_894					

				mov	r4, r0						


locret_894:										
				rts								
				nop								

; End of function Div_256_R

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R0 = (R4 < 0xFFFF0000) ? (R4 + 32768)/65536 :	0xFFFF;

Div_65536_R:									
_Div_65536_R:									
				swap.w	r4, r0					
				extu.w	r0, r0					
				shll16	r4						
				shll	r4						
				bf	loc_8A4						

				add	#1, r0						
loc_8A4:										
				mov	#h'FFFFFFFF, r4             
				extu.w	r4, r4					
				cmp/hs	r4, r0					
				bf	locret_8AE					

				mov	r4, r0						
locret_8AE:										
				rts								
				nop								

; End of function Div_65536_R

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; ----------------------------------------------
				extu.w	r4, r0					
				rts								
				swap.b	r0, r0					

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


SwapBytes16:									
_SwapBytes16:									
				extu.b	r4, r0					
				not	r4, r4						
				extu.b	r4, r4					
				shll8	r4						
				rts								
				or	r4, r0						

; End of function SwapBytes16

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R0 = (R5w > 0) ? R4w / R5w : 0xFFFF;

Div_R4_R5__R0:									
_Div_R4_R5__R0:									
												
				extu.w	r5, r5					
				mov	r5, r0						
				cmp/eq	#0, r0					
				bt	Division_By_Zero_Handler_loc_8FC
				
				extu.w	r4, r0						
				shll16	r5							
				cmp/hs	r5, r0						
				bt	Division_By_Zero_Handler_loc_8FC

				div0u							
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				rotcl	r0						
												
				bra	locret_8FE					
				extu.w	r0, r0					

				.NOPOOL

; ----------------------------------------------

Division_By_Zero_Handler_loc_8FC:				
												
				mov.l	#H'FFFF, r0				


locret_8FE:										
				rts								
				nop								

; End of function Div_R4_R5__R0

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R0 = R4 / R5w

Div_DW:											
_Div_DW:											
												
				mov.l	r10, @-r15				
				bra	loc_90C						
				mov	#h'7F, r10 ; ''            

				.NOPOOL

; ----------------------------------------------
				mov.l	r10, @-r15				
				mov	#0, r10						


loc_90C:										
				extu.w	r5, r5					
				mov	#0, r0						
				cmp/eq	r0, r5					
				bt	loc_9A4						

				div0u							
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				mov	r4, r0						
				cmp/pl	r10						
				bf	locret_9AC					

				mov.l	#h'FFFF, r4             
				cmp/hi	r4, r0					
				bf	locret_9AC					

;Handle	case where division by zero would occur.

loc_9A4:										
				mov	#h'FFFFFFFF, r0             
				cmp/pl	r10						
				bf	locret_9AC					

				extu.w	r0, r0					


locret_9AC:										
												
				rts								
				mov.l	@r15+, r10				

; End of function Div_DW

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R0=R4/R5

Div_WW:											
_Div_WW:											
												
				extu.w	r5, r5					
				extu.w	r4, r4					
				mov	r5, r0						
				cmp/eq	#0, r0					
				bt	loc_9EC						

				shlr	r0						
				add	r4, r0						
				shll16	r5						
				cmp/hs	r5, r0					
				bt	loc_9EC						

				div0u							
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				div1	r5, r0					
				rotcl	r0						
				bra	locret_9EE					
				extu.w	r0, r0					


				.NOPOOL

; ----------------------------------------------

loc_9EC:										
												
				mov.l	#H'FFFF, r0				


locret_9EE:										
				rts								
				nop								

; End of function Div_WW

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R0 = (R4 + R5w / 2) /	R5w

DIV_DW_R:										
_DIV_DW_R:										
												
				mov.l	r10, @-r15				
				mov.l	r11, @-r15				
				bra	loc_A00						
				mov	#h'7F, r10 ; ''            

				.NOPOOL


; ----------------------------------------------

loc_9FA:										
				mov.l	r10, @-r15				
				mov.l	r11, @-r15				
				mov	#0, r10						


loc_A00:										
				extu.w	r5, r5					
				mov	#0, r0						
				cmp/eq	r0, r5					
												
				bt	loc_AA6						

				mov	r5, r11						
				shlr	r11						
				clrt							
				addc	r11, r4					
				addc	r0, r0					
				cmp/hs	r5, r0					
				bt	loc_AA6						

				div0u							
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				div1	r5, r0					
				rotcl	r4						
				mov	r4, r0						
				cmp/pl	r10						
				bf	loc_AAE						

				mov.l	#H'FFFF, r4				
				cmp/hi	r4, r0					
				bf	loc_AAE						


loc_AA6:										
												
				mov	#h'FFFFFFFF, r0             
				cmp/pl	r10						
				bf	loc_AAE						

				extu.w	r0, r0					


loc_AAE:										
												
				mov.l	@r15+, r11				
				rts								
				mov.l	@r15+, r10				

; End of function DIV_DW_R

; ----------------------------------------------

;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++
												

; =============== S U B	R O U T	I N E ==========


Interpolate_256:								
_Interpolate_256:								
												
				extu.w	r4, r4					
				extu.w	r5, r5					
				extu.w	r6, r6					
				mov.l	#256, r0				
				cmp/hi	r0, r6					
				bf	loc_AC6						

				mov	r0, r6						


loc_AC6:										
				sub	r6, r0						
				mul.l	r5, r0					
				sts	macl, r0					
				mulu	r4, r6					
				sts	macl, r4					
				add	r4, r0						
				shlr8	r0						
				mov.l	#H'FFFF, r4				
				cmp/hi	r4, r0					
				bf	locret_ADC					

				mov	r4, r0						


locret_ADC:										
				rts								
				nop								

; End of function Interpolate_256

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


sub_AE0:
_sub_AE0:
				mov.l	r1, @-r15				
				extu.w	r6, r6					
				mov.l	#256, r1				
				cmp/hi	r1, r6					
				bf	loc_AEC						

				mov	r1, r6						


loc_AEC:										
				sub	r6, r1						
				dmulu.l	r5, r1					
				sts	mach, r1					
				sts	macl, r0					
				dmulu.l	r4, r6					
				sts	mach, r5					
				sts	macl, r6					
				clrt							
				addc	r6, r0					
				addc	r5, r1					
				mov.l	#256, r4				
				cmp/hs	r4, r1					
				bt	loc_B10						

				shlr8	r0						
				shll16	r1						
				shll8	r1						
				bra	locret_B12					
				or	r1, r0						

				.NOPOOL


; ----------------------------------------------

loc_B10:										
				mov	#h'FFFFFFFF, r0             


locret_B12:										
				rts								
				mov.l	@r15+, r1				

; End of function sub_AE0

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R0 = R5 + (R4*R6 - R5*R6) / 255; R6 =	[0 ... 255]

interpolate_r4_r5_r6:							
_interpolate_r4_r5_r6:							
												
				mov.l	r10, @-r15				
				extu.w	r4, r4					
				extu.w	r5, r5					
				extu.w	r6, r6					
				mov.l	#255, r10				
				cmp/hi	r10, r6					
				bf	loc_B26						

				mov	r10, r6						


; // (R5*(255-R6) + R4*R6) / 255 = (R5*255 - R5*

loc_B26:										
				mov	r10, r0						
				sub	r6, r0						
				mulu	r5, r0					
				sts	macl, r0					
				mulu	r4, r6					
				sts	macl, r4					
				add	r4, r0						
				shll16	r10						

				cmp/hs	r10, r0					
				bf	loc_B3E						

				bra	locret_B64					

				mov		#-1, r0					


				.NOPOOL

; ----------------------------------------------


loc_B3E:										
				div0u							
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				div1	r10, r0					
				rotcl	r0						
				extu.w	r0, r0					


locret_B64:										
				rts								
				mov.l	@r15+, r10				

; End of function interpolate_r4_r5_r6

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


sub_B68:
_sub_B68:
				mov.l	r1, @-r15				
				extu.w	r6, r6					
				mov.l	#255, r1				
				cmp/hi	r1, r6					
				bf	loc_B74						

				mov	r1, r6						


loc_B74:										
				dmulu.l	r4, r6					
				sts	mach, r4					
				sts	macl, r0					
				sub	r6, r1						
				dmulu.l	r5, r1					
				sts	macl, r5					
				sts	mach, r6					
				mov	r4, r1						
				clrt							
				addc	r5, r0					
				addc	r6, r1					
				mov.l	#255, r6				
				cmp/hs	r6, r1					
				bf	loc_B94						

				bra	locret_C18					
				mov	#h'FFFFFFFF, r0             

				.NOPOOL


; ----------------------------------------------

loc_B94:										
				div0u							
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						


loc_C00:										
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						
				div1	r6, r1					
				rotcl	r0						


locret_C18:										
				rts								
				mov.l	@r15+, r1				

; End of function sub_B68

;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; ----------------------------------------------
;off_C1C:			.data.l	v_int_irq0			
												
;dword_C20:			.data.l	255					
												
;dword_C24:			.data.l	65535				

; =============== S U B	R O U T	I N E ==========


Table_Lookup_byte_2D_3D:						
_Table_Lookup_byte_2D_3D:						
												
				sts.l	pr, @-r15				
				mov.l	r1, @-r15				
				mov.l	r5, @-r15				
				mov.l	r6, @-r15				
				mov.l	r8, @-r15				
				mov.l	r9, @-r15				
				mov.l	r10, @-r15				
				mov.l	r11, @-r15				
				mov	r4, r1						

				mov.b	@(1,r1), r0				
				extu.b	r0, r9					

				mov.w	@(4,r1), r0				
				mov.l	#h'FFFF0000, r4         
				or	r4, r0						
				mov.w	@r0, r6					
				extu.b	r6, r8					

				extu.w	r6, r6					
				shlr8	r6						

				mov.b	@(0,r1), r0				
				extu.b	r0, r0					
				cmp/eq	#3, r0					
				bt	loc_C66						

				add	#6, r1						
				add	r8, r1						
				mov.b	@r1, r4					
				add	r9, r4						
				extu.b	r4, r4					

				mov.b	@(1,r1), r0				
				add	r9, r0						
				bra	loc_CAE						
				extu.b	r0, r5					

				.NOPOOL


loc_C66:										
				mov.w	@(8,r1), r0				
				or	r4, r0						
				mov.w	@r0, r10				

				extu.b	r10, r4					
				extu.w	r10, r10				
				shlr8	r10						

				mov.b	@(10,r1), r0			
				extu.b	r0, r0					
				mulu	r0, r4					
				sts	macl, r4					
				add	#h'B, r4                    
				add	r1, r4						
				add	r4, r8						
				mov	r6, r11						

				mov.b	@r8, r4					
				add	r9, r4						
				extu.b	r4, r4					

				mov.b	@(1,r8), r0				
				add	r9, r0						

				bsr	Interpolate					
				extu.b	r0, r5					

				mov	r11, r6						
				mov	r0, r11						

				mov.b	@(10,r1), r0			
				extu.b	r0, r0					
				add	r0, r8						

				mov.b	@r8, r4					
				add	r9, r4						
				extu.b	r4, r4					

				mov.b	@(1,r8), r0				
				add	r9, r0						

				bsr	Interpolate					
				extu.b	r0, r5					

				mov	r11, r4						
				mov	r0, r5						

				mov	r10, r6						

loc_CAE:										
				bsr	Interpolate					
				nop								

				mov.l	@r15+, r11				
				mov.l	@r15+, r10				
				mov.l	@r15+, r9				
				mov.l	@r15+, r8				
				mov.l	@r15+, r6				
				mov.l	@r15+, r5				
				mov.l	@r15+, r1				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Table_Lookup_byte_2D_3D

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; Table_Lookup_Axis(AxisTable *tbl)

Table_Lookup_Axis:								
_Table_Lookup_Axis:								
												
				sts.l	pr, @-r15				
												
				mov.l	r0, @-r15				
				mov.l	r1, @-r15				
				mov.l	r5, @-r15				
				mov.l	r6, @-r15				
				mov.l	r9, @-r15				
				mov.l	r12, @-r15				
				mov	r4, r1						

				mov.w	@(8,r1), r0				
				extu.w	r0, r5					

				mov.l	#255, r0				
				cmp/hi	r0, r5					
				bf	loc_CE2	
				
				mov     r0, r5 					

loc_CE2:										
				add	#-1, r5						

				mov.w	@(2,r1), r0				
				mov.l	#h'FFFF0000, r4         
				or	r4, r0						
				mov.w	@r0, r9					
				extu.b	r9, r9					

				cmp/hi	r5, r9					
				bf	loc_CF4						

				mov	r5, r9						

loc_CF4:										
				mov.w	@(6,r1), r0				
				or	r4, r0						
				mov.w	@r0, r4					
				extu.w	r4, r4					

				mov	r9, r12						
				shll	r12						
				add	#10, r12					
				add	r1, r12						
				mov.w	@r12, r6				

				extu.w	r6, r6					
				cmp/hi	r6, r4					
				bt	loc_D20						

loc_D0C:										
				mov.w	@r12, r6				
				extu.w	r6, r6					
				cmp/hi	r4, r6					
				bf	loc_D3C						

				mov	r9, r0						
				cmp/eq	#0, r0					
				bt	loc_D3C						

				add	#-1, r9						
				bra	loc_D0C						
				add	#-2, r12					


				.NOPOOL

; ----------------------------------------------

loc_D20:										
												
				mov.w	@r12, r6				
				extu.w	r6, r6					
				cmp/hi	r4, r6					
				bt	loc_D32						

				cmp/hs	r5, r9					
				bt	loc_D3C						

				add	#1, r9						
				bra	loc_D20						
				add	#2, r12						

				.NOPOOL


; ----------------------------------------------

loc_D32:										
				mov	r9, r0						
				cmp/eq	#0, r0					
				bt	loc_D3C						

				add	#-1, r9						
				add	#-2, r12					

loc_D3C:										
												
				mov.w	@(10,r1), r0			
				extu.w	r0, r0					
				cmp/hi	r4, r0					
				bt	loc_D60						

				cmp/eq	r5, r9					
				bt	loc_D60						

				mov.w	@r12, r5				
				extu.w	r5, r5					
				sub	r5, r4						

				mov.w	@(2,r12), r0			
				extu.w	r0, r6					
				sub	r5, r6						

				mov.l	#255, r5				
				mov.l	#Mul_Div_R, r0			
				jsr	@r0 ; Mul_Div_R				
				nop								

				shll8	r0						
				or	r0, r9						

loc_D60:										
												
				mov.w	@(2,r1), r0				
				mov.l	#h'FFFF0000, r4         
				or	r4, r0						
				mov.w	r9, @r0					
				mov.l	@r15+, r12				
				mov.l	@r15+, r9				
				mov.l	@r15+, r6				
				mov.l	@r15+, r5				
				mov.l	@r15+, r1				
				mov.l	@r15+, r0				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Table_Lookup_Axis

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R4 - v1; R5 -	v2; R6 - interpolator;

Interpolate:									
_Interpolate:									
												
				sts.l	pr, @-r15				
				mov.l	r11, @-r15				
				mov.l	r12, @-r15				
				extu.w	r4, r4					
				mov	r4, r12						
				extu.w	r5, r5					
				extu.w	r6, r6					
				xor	r11, r11					
				cmp/eq	r11, r6					
				bf	loc_D92						

				bra	loc_DBC						
				mov	r4, r0						

				.NOPOOL

; ----------------------------------------------

loc_D92:										
				mov.l	#h'FF, r0               
				cmp/hi	r0, r6					
				bf	loc_D9C						

				bra	loc_DBC						
				mov	r5, r0						

				.NOPOOL

; ----------------------------------------------

loc_D9C:										
				cmp/hi	r5, r4					
				bf	loc_DA6						

				sub	r5, r4						
				bra	loc_DAA						
				mov	#1, r11						

				.NOPOOL

; ----------------------------------------------

loc_DA6:										
				sub	r4, r5						
				mov	r5, r4						


loc_DAA:										
				mov	r6, r5						
				mov	r0, r6						
				mov.l	#Mul_Div_R, r0			
				jsr	@r0 ; Mul_Div_R				
				nop								

				cmp/pl	r11						
				bf	loc_DBA						

				neg	r0, r0						


loc_DBA:										
				add	r12, r0						


loc_DBC:										
												
				mov.l	@r15+, r12				
				mov.l	@r15+, r11				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Interpolate

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R0 = (byte)R4[MUT34_Map_Index	& 7];

GET_FROM_MASSIVE_byte:							
_GET_FROM_MASSIVE_byte:							
												
				mov.l	#wMUT34_Map_Index, r0	
				mov.w	@r0, r0					
				and	#7, r0						
				mov.b	@(r0,r4), r0			
				rts								
				extu.b	r0, r0					

; End of function GET_FROM_MASSIVE_byte

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========

; R0 = (word)R4[MUT34_Map_Index	& 7];

GET_FROM_MASSIVE_word:							
_GET_FROM_MASSIVE_word:							
												
				mov.l	#wMUT34_Map_Index, r0	
				mov.w	@r0, r0					
				and	#7, r0						
				shll	r0						
				mov.w	@(r0,r4), r0			
				rts								
				extu.w	r0, r0					

; End of function GET_FROM_MASSIVE_word

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


Query_byte_2D_3D_Table:							
_Query_byte_2D_3D_Table:							
												
				sts.l	pr, @-r15				
				mov.l	#wMUT34_Map_Index, r0	
				mov.w	@r0, r0					
				and	#7, r0						
				shll2	r0						
				mov.l	@(r0,r4), r4			
				bsr	Table_Lookup_byte_2D_3D		
				nop								

				lds.l	@r15+, pr				

locret_DF2:										
				rts
				nop								

; End of function Query_byte_2D_3D_Table

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


GET_LOC_DIM_sub_DF6:							
_GET_LOC_DIM_sub_DF6:							
												
				mov.l	#wMUT34_Map_Index, r0	
				mov.w	@r0, r0					
				and	#7, r0						
				shll2	r0						
				rts								
				mov.l	@(r0,r4), r0			

; End of function GET_LOC_DIM_sub_DF6

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


Table_Lookup_word_2D_3D:						
_Table_Lookup_word_2D_3D:						
												
				sts.l	pr, @-r15				
				mov.l	r1, @-r15				
				mov.l	r5, @-r15				
				mov.l	r6, @-r15				
				mov.l	r8, @-r15				
				mov.l	r9, @-r15				
				mov.l	r10, @-r15				
				mov.l	r11, @-r15				
				mov	r4, r1						
				mov.w	@(2,r1), r0				
				extu.w	r0, r9					
				mov.w	@(6,r1), r0				
				mov.l	#h'FFFF0000, r4         
				or	r4, r0						
				mov.w	@r0, r6					
				extu.b	r6, r8					
				shll	r8						
				extu.w	r6, r6					
				shlr8	r6						
				mov.w	@r1, r0					
				extu.w	r0, r0					
				cmp/eq	#3, r0					
				bt	loc_E42						

				add	#8, r1						
				add	r8, r1						
				mov.w	@r1, r4					
				add	r9, r4						
				extu.w	r4, r4					
				mov.w	@(2,r1), r0				
				add	r9, r0						
				bra	loc_E8E						
				extu.w	r0, r5					

				.NOPOOL


; ----------------------------------------------

loc_E42:										
				mov.w	@(h'A,r1), r0           
				or	r4, r0						
				mov.w	@r0, r10				
				extu.b	r10, r4					
				shll	r4						
				extu.w	r10, r10				
				shlr8	r10						
				mov.w	@(h'C,r1), r0           
				extu.w	r0, r0					
				mulu	r0, r4					
				sts	macl, r4					
				add	#h'E, r4                    
				add	r1, r4						
				add	r4, r8						
				mov	r6, r11						
				mov.w	@r8, r4					
				add	r9, r4						
				extu.w	r4, r4					
				mov.w	@(2,r8), r0				
				add	r9, r0						
				bsr	Interpolate					
				extu.w	r0, r5					

				mov	r11, r6						
				mov	r0, r11						
				mov.w	@(h'C,r1), r0           
				extu.w	r0, r0					
				shll	r0						
				add	r0, r8						
				mov.w	@r8, r4					
				add	r9, r4						
				extu.w	r4, r4					
				mov.w	@(2,r8), r0				
				add	r9, r0						
				bsr	Interpolate					
				extu.w	r0, r5					

				mov	r11, r4						
				mov	r0, r5						
				mov	r10, r6						


loc_E8E:										
				bsr	Interpolate					
				nop								

				mov.l	@r15+, r11				
				mov.l	@r15+, r10				
				mov.l	@r15+, r9				
				mov.l	@r15+, r8				
				mov.l	@r15+, r6				
				mov.l	@r15+, r5				
				mov.l	@r15+, r1				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Table_Lookup_word_2D_3D

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


sub_EA6:
_sub_EA6:
				sts.l	pr, @-r15				
				mov.l	#wMUT34_Map_Index, r0	
				mov.w	@r0, r0					
				and	#7, r0						
				shll2	r0						
				mov.l	@(r0,r4), r4			
				bsr	Table_Lookup_word_2D_3D		
				nop								

				lds.l	@r15+, pr				
				rts								
				nop								

; End of function sub_EA6

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


sub_EBC:
_sub_EBC:
				mov.l	#wMUT34_Map_Index, r0	
				mov.w	@r0, r0					
				and	#7, r0						
				shll2	r0						
				rts								
				mov.l	@(r0,r4), r0			

; End of function sub_EBC

;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; ----------------------------------------------
;dword_EC8:			.data.l	h'FFFF0000          
												
;off_ECC:			.data.l	off_FC+3			
												
;off_ED0:			.data.l	Mul_Div_R			
												
												
;off_ED4:			.data.l	wMUT34_Map_Index	
												
												

; =============== S U B	R O U T	I N E ==========


Mul_Lim_FFFF:									
_Mul_Lim_FFFF:									
												
				extu.w	r4, r4					
				extu.w	r5, r5					
				mulu	r4, r5					
				sts	macl, r0					
				mov	#h'FFFFFFFF, r4             
				extu.w	r4, r4					
				cmp/hs	r4, r0					
												
				bf	locret_EEA					

				mov	r4, r0						


locret_EEA:										
				rts								
				nop								; No Operation

; End of function Mul_Lim_FFFF

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E =======================================


Mul16:											
_Mul16:											
												
				extu.w	r4, r4					
				extu.w	r5, r5					
				mulu	r4, r5					
				rts								
				sts	macl, r0					

; End of function Mul16

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


Mul32_lim:										
_Mul32_lim:										
												
				dmulu.l	r5, r4					
				sts	macl, r0					
				sts	mach, r4					
				mov	#0, r5						
				cmp/hi	r5, r4					
				bf	locret_F06					

				mov	#h'FFFFFFFF, r0             


locret_F06:										
				rts								
				nop								

; End of function Mul32_lim

; ----------------------------------------------
				.data.w	h'FFFF

; =============== S U B	R O U T	I N E ==========

; R0 = (R4 >= R5) ? (R4-R5) : 0

Sub_Lim_0:										
_Sub_Lim_0:										
												
				extu.w	r5, r5					
				bra	loc_F14						
				extu.w	r4, r0					

; ----------------------------------------------
				mov	r4, r0						


loc_F14:										
				clrt							
				subc	r5, r0					
				bf	locret_F1C					

				mov	#0, r0						


locret_F1C:										
				rts								
				nop								

; End of function Sub_Lim_0

;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++

	.END

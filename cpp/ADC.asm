	.CPU   SH2                                   ; Assembles program for the SH-2. 
	
	.INCLUDE "cpp\ram_asm.inc"
	.INCLUDE "cpp\hwreg_asm.inc"
	.INCLUDE "cpp\libsfunc_exp.inc"

	.IMPORT HUGE_Method_801_6_Hz
	.IMPORT word_1BF8
	
;+++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    P_ADC, CODE, LOCATE=H'B284


; =============== S U B	R O U T	I N E =======================================


SysInit_ADC:									
												
				mov.l	r14, @-r15				
				mov		r15, r14					
				mov		#0, r10						
				mov.l	#reg_ADCSR1, r11		
				mov.b	r10, @r11				
				mov.l	#reg_ADCSR0, r11		
				mov.b	r10, @r11				
				mov		#8, r10						
				mov.l	#unk_FFFFF858, r11		
				mov.b	r10, @r11				
				mov		#h'4F, r10 ; 'O'            
				mov.l	#unk_FFFFF859, r11		
				mov.b	r10, @r11				
				mov.l	#reg_ADCR1, r11			
				mov.b	r10, @r11				
				mov.l	#reg_ADCR0, r11			
				mov.b	r10, @r11				
				mov.l	@r15+, r14				
				rts								
				nop								

; End of function SysInit_ADC

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E =======================================


Nop3:											
												
				mov.l	r14, @-r15				
				mov	r15, r14					
				mov.l	@r15+, r14				
				rts								
				nop								

; End of function Nop3

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E =======================================

; R0 = *R6 = result; R4	= channel num; *R5 = result>>2;

GetADC:											
												
				add	#-4, r15					
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov		r15, r14					
				mov.l	r1, @-r15				
				mov.l	r2, @-r15				
				mov.l	r8, @-r15				
				mov		r6, r8						
				mov		r5, r2						
				mov		r4, r1						
				mov.l	#__disable_irq,	r10		
				jsr		@r10 ; __disable_irq		
				nop								

				extu.b	r1, r0					
				tst	#h'20, r0                   
				bt	loc_B2E2					

				mov.l	#reg_PHDRL, r10			
				mov.b	@r10, r0				
				or	#2, r0						
				mov.b	r0, @r10				
				bra	loc_B2EA					
				nop								

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++
; ---------------------------------------------------------------------------

loc_B2E2:										
				mov.l	#reg_PHDRL, r10			
				mov.b	@r10, r0				
				and	#~h'FFFFFF02, r0            
				mov.b	r0, @r10				


loc_B2EA:										
				extu.b	r1, r0					
				tst	#h'40, r0                   
				bt	loc_B2FC					

				mov.l	#reg_PHDRL, r10			
				mov.b	@r10, r0				
				or	#1, r0						
				mov.b	r0, @r10				
				bra	loc_B304					
				nop								

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++
; ---------------------------------------------------------------------------

loc_B2FC:											
				mov.l	#reg_PHDRL, r10				
				mov.b	@r10, r0					
				and	#~h'FFFFFF01, r0                
				mov.b	r0, @r10					


loc_B304:											
				mov	#1, r0							
				mov.b	r0, @(8,r14)				


loc_B308:											
				mov.b	@(8,r14), r0				
				extu.b	r0, r10						
				add	#-1, r10						
				mov	r10, r0							
				mov.b	r0, @(8,r14)				
				extu.b	r10, r10					
				tst	r10, r10						
				bf	loc_B308						

				mov	#h'1F, r10                      
				and	r10, r1							
				mov	#11, r10						
				cmp/hi	r10, r1						
				bt	loc_B32E						

				mov	r1, r4							
				bsr	GetADC0							
				nop								

				extu.w	r0, r1					
				bra	loc_B33A					
				nop								

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++
; ---------------------------------------------------------------------------

loc_B32E:										
				extu.b	r1, r10					
				add	#-h'C, r10                  
				mov	r10, r4						
				bsr	GetADC1						
				nop								

				extu.w	r0, r1					


loc_B33A:										
				mov.w	r1, @r8					
				shlr2	r1						
				mov.w	r1, @r2					
				mov.l	#__enable_irq, r10		
				jsr	@r10 ; __enable_irq			
				nop								

				mov.l	@r15+, r8				
				mov.l	@r15+, r2				
				mov.l	@r15+, r1				
				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				add	#4, r15						
				rts								
				nop								

; End of function GetADC

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E =======================================

; R0 = result; R4 = channel num

GetADC0:											
				add	#-4, r15						
				sts.l	pr, @-r15					
				mov.l	r14, @-r15					
				mov	r15, r14						
				mov.l	r1, @-r15					
				mov.l	r2, @-r15					
				mov.l	r8, @-r15					
				mov.l	r9, @-r15					
				mov	r4, r1							
				mov.l	#reg_ADDR0H, r8				
				extu.b	r1, r10						
				shll	r10							
				mov	r8, r2							
				add	r10, r2							

				mov	#h'4F, r10 ; 'O'                
				mov.l	#reg_ADCR0, r11				
				mov.b	r10, @r11					

				mov.l	#reg_ADCSR0, r10			
				mov.b	r1, @r10					

		;		mov.l	#reg_ADCR0, r11				
				mov.b	@r11, r0						
				or		#h'20, r0                       
		;		mov.l	#reg_ADCR0, r11				
				mov.b	r0, @r11					

				mov	#1, r0							
				mov.b	r0, @(8,r14)				


loc_B38A:											
				mov.b	@(8,r14), r0				
				extu.b	r0, r10						
				add	#-1, r10						
				mov	r10, r0							
				mov.b	r0, @(8,r14)				
				extu.b	r10, r10					
				tst	r10, r10						
				bf	loc_B38A						


loc_B39A:											
				mov.l	#reg_ADCSR0, r10				
				mov.b	@r10, r0						
				tst	#h'80, r0                       
				bt	loc_B39A						


			;	mov.l	#reg_ADCSR0, r10				
				mov.b	@r10, r0						
				and		#h'7F, r0                       
			;	mov.l	#reg_ADCSR0, r10			
				mov.b	r0, @r10					


				mov.b	@r2, r10					
				extu.b	r10, r10					
				shll8	r10							
				mov.b	@(1,r2), r0					
				extu.b	r0, r0						
				or	r0, r10							
				extu.w	r10, r10					
				shll2	r10							
				shlr8	r10							
				mov		r10, r0							
				mov.l	@r15+, r9					
				mov.l	@r15+, r8					
				mov.l	@r15+, r2					
				mov.l	@r15+, r1					
				mov.l	@r15+, r14					
				lds.l	@r15+, pr					
				add		#4, r15							
				rts								
				nop								

; End of function GetADC0
;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==============

; R0 = result; R4 = channel num

GetADC1:											
				add	#-4, r15						
				sts.l	pr, @-r15					
				mov.l	r14, @-r15					
				mov	r15, r14						
				mov.l	r1, @-r15					
				mov.l	r2, @-r15					
				mov.l	r8, @-r15					
				mov.l	r9, @-r15					
				mov	r4, r1							
				mov.l	#reg_ADDR0H, r2				
				add	#h'20, r2 ; ' '                 
				extu.b	r1, r1						
				mov	#3, r10							
				cmp/hs	r10, r1						
				bf	loc_B3F2						

				mov	#3, r1							


loc_B3F2:											
				extu.b	r1, r10						
				shll	r10							
				add		r10, r2							
				mov		#h'4F, r10 ; 'O'                
				mov.l	#reg_ADCR1, r11				
				mov.b	r10, @r11					
				mov.l	#reg_ADCSR1, r10			
				mov.b	r1, @r10					
			;	mov.l	#reg_ADCR1, r11				
				mov.b	@r11, r0						
				or	#h'20, r0                       
			;	mov.l	#reg_ADCR1, r11				
				mov.b	r0, @r11					
				mov	#1, r0							
				mov.b	r0, @(8,r14)				


loc_B410:											
				mov.b	@(8,r14), r0				
				extu.b	r0, r10						
				add	#-1, r10						
				mov	r10, r0							
				mov.b	r0, @(8,r14)				
				extu.b	r10, r10					
				tst	r10, r10						
				bf	loc_B410						


loc_B420:											
				mov.l	#reg_ADCSR1, r10				
				mov.b	@r10, r0						
				tst	#h'80, r0                       
				bt	loc_B420						

		;		mov.l	#reg_ADCSR1, r10				
				mov.b	@r10, r0						
				and		#h'7F, r0                       
		;		mov.l	#reg_ADCSR1, r10			
				mov.b	r0, @r10					
				mov.b	@r2, r10					
				extu.b	r10, r10					
				shll8	r10							
				mov.b	@(1,r2), r0					
				extu.b	r0, r0						
				or	r0, r10							
				extu.w	r10, r10					
				shll2	r10							
				shlr8	r10							
				mov	r10, r0							
				mov.l	@r15+, r9					
				mov.l	@r15+, r8					
				mov.l	@r15+, r2					
				mov.l	@r15+, r1					
				mov.l	@r15+, r14					
				lds.l	@r15+, pr					
				add	#4, r15							
				rts								
				nop								

; End of function GetADC1

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==============

; Input	capture	in ICR0B on falling edge
; ICI0B	interrupt requested by ICF0B is	disabled
; Disable DMA Ch2

SysInit_ATU_0_DMA_2:							
												
												
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov	r15, r14					
				mov.l	#__disable_irq,	r10		
				jsr	@r10 ; __disable_irq		
				nop								

				mov		#~2, r0						
				mov.l	#reg_TSR0, r11			
				mov.w	@r11, r10				
				and		r0, r10						
		;		mov.l	#reg_TSR0, r11			
				mov.w	r10, @r11				
				mov.l	#reg_TIOR0, r10			
				mov.b	@r10, r0					
				and		#h'F3, r0                   
				or		#8, r0						
		;		mov.l	#reg_TIOR0, r10			
				mov.b	r0, @r10				


				mov	#~2, r0						
				mov.l	#reg_TIER0, r11			
				mov.w	@r11, r10				
				and		r0, r10						
			;	mov.l	#reg_TIER0, r11			
				mov.w	r10, @r11				


				mov		#h'FFFFFFFA, r0             
				mov.l	#reg_CHCR2, r11			
				mov.l	@r11, r10				
				and		r0, r10						
			;	mov.l	#reg_CHCR2, r11			
				mov.l	r10, @r11				


				mov		#0, r10						
				mov.l	#word_FFFF898C,	r11		
				mov.w	r10, @r11				
				mov.l	#word_FFFF89B6,	r11		
				mov.w	r10, @r11				
				mov.l	#word_FFFF9AB0,	r10		
				mov.w	@r10, r10				
				mov.l	#word_FFFF89AE,	r11		
				mov.w	r10, @r11				
				mov.l	#__enable_irq, r10		
				jsr	@r10 ; __enable_irq			
				nop								

				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function SysInit_ATU_0_DMA_2

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++


; =============== S U B	R O U T	I N E ==========

; Input	capture	in ICR0B on falling edge
; ICI0B	interrupt requested by ICF0B is	disabled
; Disable DMA Ch2

Init_ATU_0_DMA_2:								
												
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov	r15, r14					
				mov.l	#__disable_irq,	r10		
				jsr	@r10 ; __disable_irq		
				nop								

				mov		#~2, r0						
				mov.l	#reg_TIER0, r11			
				mov.w	@r11, r10				
				and	r0, r10						
			;	mov.l	#reg_TIER0, r11			
				mov.w	r10, @r11				
				mov		#h'FFFFFFFA, r0             
				mov.l	#reg_CHCR2, r11			
				mov.l	@r11, r10				
				and		r0, r10						
			;	mov.l	#reg_CHCR2, r11			
				mov.l	r10, @r11				
				mov.l	#reg_TIOR0, r10			
				mov.b	@r10, r0					
				and		#h'F3, r0                   
				or		#8, r0						
			;	mov.l	#reg_TIOR0, r10			
				mov.b	r0, @r10				
				mov.l	#__enable_irq, r10		
				jsr	@r10 ; __enable_irq			
				nop								

				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Init_ATU_0_DMA_2

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E =============


sub_B4F2:
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov	r15, r14					
				mov.l	r1, @-r15				
				mov.l	r2, @-r15				
				mov.l	r8, @-r15				
				mov.l	r9, @-r15				
				mov	r4, r1						
				mov.l	#dword_FFFF9A60, r2		
				mov	#4, r9						
				add	r2, r9						
				bsr	dmac2_dei2_B618				
				nop								

				mov.l	@r2, r10				
				mov.l	@r9, r11				
				sub	r10, r11					
				shlr2	r11						
				shlr2	r11						
				mov	r11, r4						
				mov.l	#Lim_FFFF, r10			
				jsr	@r10 ; Lim_FFFF				
				nop								

				mov.l	#word_FFFF89B2,	r11		
				mov.w	r0, @r11				
				mov.l	@r9, r10				
				mov	r10, r8						
				sub	r1, r8						
				mov	r1, r11						
				sub	r10, r11					
				mov.l	#h'80000000, r10        
				tst	r11, r10					
				bt	loc_B5C4					

				mov.w	#h'4B0, r10             
				cmp/hs	r10, r8					
				bt	loc_B5C4					

				bra	loc_B590					
				nop								

; ---------------------------------------------------------------------------
;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; ---------------------------------------------------------------------------

loc_B590:											
				mov.l	#word_FFFF9AB0,	r10			
				mov.w	@r10, r10					
				extu.w	r10, r10					
				add	#-1, r10						
				mov.l	#word_FFFF89AE,	r11			
				mov.w	@r11, r11					
				extu.w	r11, r11					
				sub	r11, r10						
				mov.l	#word_FFFF89AC,	r11			
				mov.w	r10, @r11					
				mov.l	#word_FFFF9AB0,	r10			
				mov.w	@r10, r10					
				add	#-1, r10						
				mov.l	#word_FFFF89AE,	r11			
				mov.w	r10, @r11					
				mov.l	@r2, r10					
				sub	r10, r1							
				shlr2	r1							
				shlr2	r1							
				mov	r1, r4							
				bra	loc_B5E4						
				nop								

; -----------------------------------------------
;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; -----------------------------------------------

loc_B5C4:										
												
				mov.l	#word_FFFF9AB0,	r10		
				mov.w	@r10, r10				
				mov.l	#word_FFFF89AE,	r11		
				mov.w	@r11, r11				
				sub	r11, r10					
				mov.l	#word_FFFF89AC,	r12		
				mov.w	r10, @r12				
				mov.l	#word_FFFF9AB0,	r10		
				mov.w	@r10, r10				
				mov.l	#word_FFFF89AE,	r11		
				mov.w	r10, @r11				
				mov.l	@r9, r10				
				sub	r10, r1						
				shlr2	r1						
				shlr2	r1						
				mov	r1, r4						


loc_B5E4:										
				mov.l	#Lim_FFFF, r10			
				jsr	@r10 ; Lim_FFFF				
				nop								

				mov.l	#word_FFFF89B4,	r11		
				mov.w	r0, @r11				
				mov.l	#timer_up_FFFF8520, r10	
				mov.w	@r10, r10				
				mov	#h'32, r11 ; '2'            
				cmp/hs	r11, r10				
				bf	loc_B602					

				mov	#h'FFFFFFFF, r10            
				mov.l	#word_FFFF89B2,	r11		
				mov.w	r10, @r11				
				mov.l	#word_FFFF89B4,	r11		
				mov.w	r10, @r11				


loc_B602:										
				mov.l	@r15+, r9				
				mov.l	@r15+, r8				
				mov.l	@r15+, r2				
				mov.l	@r15+, r1				
				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function sub_B4F2

; ----------------------------------------------

;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++
												

; =============== S U B	R O U T	I N E ==========


dmac2_dei2_B618:								
												
				add	#-4, r15					
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov	r15, r14					
				mov.l	r1, @-r15				
				mov.l	r2, @-r15				
				mov.l	#dword_FFFF9A60, r2		
				mov.l	#__disable_irq,	r10		
				jsr	@r10 ; __disable_irq		
				nop								

				mov	#h'FFFFFFFC, r0             
				mov.l	#reg_CHCR2, r10			
				mov.l	@r10, r10				
				and	r0, r10						
				mov.l	#reg_CHCR2, r11			
				mov.l	r10, @r11				
				mov	#1, r0						
				mov.b	r0, @(8,r14)			


loc_B63C:										
				mov.b	@(8,r14), r0			
				extu.b	r0, r10					
				add	#-1, r10					
				mov	r10, r0						
				mov.b	r0, @(8,r14)			
				extu.b	r10, r10				
				tst	r10, r10					
				bf	loc_B63C					

				mov.l	#reg_DMATCR2, r13		
				mov.l	@r13, r13				
				extu.w	r13, r13				
				mov.l	#word_FFFF9AB2,	r10		
				mov.w	@r10, r10				
				extu.w	r10, r10				
				cmp/hs	r13, r10				
				bf	loc_B66C					

				mov.l	#word_FFFF9AB2,	r10		
				mov.w	@r10, r10				
				sub	r13, r10					
				mov.l	#word_FFFF9AB0,	r11		
				mov.w	@r11, r11				
				add	r11, r10					
				mov.l	#word_FFFF9AB0,	r12		
				mov.w	r10, @r12				


loc_B66C:										
				mov	r13, r1						
				mov	#h'10, r10                  
				cmp/hi	r10, r13				
				bt	loc_B69C					

				extu.w	r13, r13				
				sub	r13, r10					
				extu.w	r10, r10				
				shll2	r10						
				mov.l	#dword_FFFF9A60, r0		
				mov.l	@(r0,r10), r11			
				mov.l	#dword_FFFF9A60, r12	
				mov.l	r11, @r12				
				add	#4, r10						
				mov.l	#dword_FFFF9A60, r0		
				mov.l	@(r0,r10), r11			
				mov.l	#(dword_FFFF9A60+4), r12
				mov.l	r11, @r12				
				add	#8, r2						
				mov.l	#reg_DAR2, r10			
				mov.l	r2, @r10				
				mov	#h'10, r10                  
				mov.l	#reg_DMATCR2, r11		
				mov.l	r10, @r11				
				mov	#h'10, r1                   


loc_B69C:										
				mov.l	#word_FFFF9AB2,	r10		
				mov.w	r1, @r10				
				mov.l	#word_FFFF9AB4,	r10		
				mov.w	r1, @r10				
				mov.l	#reg_ICR0DH, r10		
				add	#h'18, r10                  
				mov.l	#reg_SAR2, r11			
				mov.l	r10, @r11				
				mov.l	#h'120124, r10          
				mov.l	#reg_CHCR2, r11			
				mov.l	r10, @r11				
				mov.l	#reg_CHCR2, r0			
				mov.l	@r0, r0					
				or	#1, r0						
				mov.l	#reg_CHCR2, r10			
				mov.l	r0, @r10				
				mov.l	#__enable_irq, r10		
				jsr	@r10 ; __enable_irq			
				nop								

				mov.l	@r15+, r2				
				mov.l	@r15+, r1				
				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				add	#4, r15						
				rts								
				nop								

; End of function dmac2_dei2_B618

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


sub_B6D0:
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov	r15, r14					
				mov.l	#__disable_irq,	r10		
				jsr	@r10 ; __disable_irq		
				nop								

				mov.l	#reg_DMATCR2, r13		
				mov.l	@r13, r13				
				extu.w	r13, r13				
				mov.l	#word_FFFF9AB0,	r10		
				mov.w	@r10, r10				
				mov.l	#word_FFFF89B0,	r11		
				mov.w	@r11, r11				
				cmp/eq	r11, r10				
				bf	loc_B6FA					

				extu.w	r13, r13				
				mov.l	#word_FFFF9AB4,	r10		
				mov.w	@r10, r10				
				extu.w	r10, r10				
				cmp/eq	r10, r13				
				bt	loc_B714					


loc_B6FA:										
				mov	#0, r10						
				mov.l	#timer_up_FFFF8520, r11	
				mov.w	r10, @r11				
				mov.l	#word_1BF8, r10			
				mov.w	@r10, r10				
				mov.l	#timer_FFFF8580, r11	
				mov.w	r10, @r11				
				mov.l	#word_FFFF9AB0,	r10		
				mov.w	@r10, r10				
				mov.l	#word_FFFF89B0,	r11		
				mov.w	r10, @r11				
				mov.l	#word_FFFF9AB4,	r10		
				mov.w	r13, @r10				


loc_B714:										
				mov.l	#__enable_irq, r10		
				jsr	@r10 ; __enable_irq			
				nop								

				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function sub_B6D0

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


dmac2_dei2:										
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov	r15, r14					
				sts.l	macl, @-r15				
				sts.l	mach, @-r15				
				mov.l	r10, @-r15				
				mov.l	r11, @-r15				
				mov.l	r12, @-r15				
				mov.l	r13, @-r15				
				mov.l	r3, @-r15				
				mov.l	r4, @-r15				
				mov.l	r5, @-r15				
				mov.l	r6, @-r15				
				mov.l	r7, @-r15				
				mov.l	r0, @-r15				
				mov.l	#__disable_irq,	r10		
				jsr	@r10 ; __disable_irq		
				nop								

				mov	#h'FFFFFFFD, r0             
				mov.l	#reg_CHCR2, r10			
				mov.l	@r10, r10				
				and	r0, r10						
				mov.l	#reg_CHCR2, r11			
				mov.l	r10, @r11				
				mov.l	#__enable_irq, r10		
				jsr	@r10 ; __enable_irq			
				nop								

				bsr	dmac2_dei2_B618				
				nop								

				mov.l	@r15+, r0				
				mov.l	@r15+, r7				
				mov.l	@r15+, r6				
				mov.l	@r15+, r5				
				mov.l	@r15+, r4				
				mov.l	@r15+, r3				
				mov.l	@r15+, r13				
				mov.l	@r15+, r12				
				mov.l	@r15+, r11				
				mov.l	@r15+, r10				
				lds.l	@r15+, mach				
				lds.l	@r15+, macl				
				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rte								
				nop								

; End of function dmac2_dei2

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


SysInit_HCAN:									
												
				mov.l	r14, @-r15				
				mov		r15, r14					
				mov.l	#reg_MCR, r10			
				mov.b	@r10, r0					
				and		#h'7F, r0                   
				or		#h'20, r0                   
				mov.b	r0, @r10				
				mov.w	#h'FFFFFEFF, r10        
				mov.l	#reg_IMR, r11			
				mov.w	r10, @r11				
				mov		#h'FFFFFFFF, r10            
				mov.l	#reg_MBIMR, r11			
				mov.w	r10, @r11				
				mov.l	@r15+, r14				
				rts								
				nop								

; End of function SysInit_HCAN

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


Init_HCAN:										
												
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov		r15, r14					
				mov.l	#__disable_irq,	r10		
				jsr		@r10 ; __disable_irq		
				nop								

				mov.l	#reg_MCR, r10			
				mov.b	@r10, r0					
				and		#h'7F, r0                   
				or		#h'20, r0                   
				mov.b	r0, @r10
								
				mov.w	#h'FFFFFEFF, r10        
				mov.l	#reg_IMR, r11			
				mov.w	r10, @r11				
				mov		#h'FFFFFFFF, r10            
				mov.l	#reg_MBIMR, r11			
				mov.w	r10, @r11				
				mov.l	#__enable_irq, r10		
				jsr		@r10 ; __enable_irq			
				nop								

				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Init_HCAN

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==========


SysInit_ATU_2A_2B_3_4_5_8_10:					
												
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov		r15, r14					
				mov.l	#__disable_irq,	r10		
				jsr		@r10 ; __disable_irq		
				nop								


;PSCR1=PSCR4 = 4	MHz
				mov		#3, r10						
				mov.l	#reg_PSCR1, r11			
				mov.b	r10, @r11				
				mov.l	#reg_PSCR4, r11			
				mov.b	r10, @r11				

;TCR2A=TCR2B=TCR3=TCR4=TCR5 = internal clock 250	kHz

				mov		#h'34, r10 ; '4'          
				mov.l	#reg_TCR2A, r11		
				mov.b	r10, @r11			
				mov.l	#reg_TCR2B, r11		
				mov.b	r10, @r11			
				mov.l	#reg_TCR3, r11		
				mov.b	r10, @r11			
				mov.l	#reg_TCR4, r11		
				mov.b	r10, @r11			
				mov.l	#reg_TCR5, r11		
				mov.b	r10, @r11			

				mov.l	#reg_TCR8, r0		
				mov.b	@r0, r0				
				and		#h'F, r0                  
				or		#h'50, r0                 
				mov.l	#reg_TCR8, r10		
				mov.b	r0, @r10			
				mov		#h'30, r10 ; '0'          
				mov.l	#reg_TIOR10, r11	
				mov.b	r10, @r11			
				mov		#0, r10					
				mov.l	#reg_TCR10, r11		
				mov.b	r10, @r11			
				mov		#h'10, r10                
				mov.l	#reg_TIER10, r11	
				mov.w	r10, @r11			
				mov		#0, r10					
				mov.l	#reg_TMDR, r11		
				mov.b	r10, @r11			
				mov.l	#reg_TSTR1, r0		
				mov.b	@r0, r0				
				and		#2, r0					
				or		#h'7D, r0                 
				mov.l	#reg_TSTR1, r10		
				mov.b	r0, @r10			

;peripheral clock = 16MHz
;CMT0 CLK = 2 MHz
;CMT0 Period = 2000000 /	2495 = 801.6 Hz

				mov.w	#2495, r10				
				mov.l	#reg_CMCOR0, r11		
				mov.w	r10, @r11				
				mov		#h'40, r10 ; '@'            
				mov.l	#reg_CMCSR0, r11		
				mov.w	r10, @r11				
				mov.w	#~h'80, r0              
				mov.l	#reg_CMCSR0, r10		
				mov.w	@r10, r10				
				and		r0, r10						
				mov.l	#reg_CMCSR0, r11		
				mov.w	r10, @r11				
				mov.l	#reg_CMSTR, r0			
				mov.w	@r0, r0					
				or		#1, r0						
				mov.l	#reg_CMSTR, r10			
				mov.w	r0, @r10				

				mov.l	#reg_TCNT2A, r10		
				mov.w	@r10, r10				
				mov.w	#312, r11				
				add		r11, r10					
				mov.l	#word_FFFF9AD2,	r12		
				mov.w	r10, @r12				
				mov.w	#~h'3A0, r0             
				mov.l	#reg_TIER3, r10			
				mov.w	@r10, r10				
				and		r0, r10						
				mov.l	#reg_TIER3, r11			
				mov.w	r10, @r11				
				mov		#h'11, r10                  
				mov.l	#reg_TIOR4A, r11		
				mov.b	r10, @r11				
				mov.l	#reg_TIOR4B, r11		
				mov.b	r10, @r11				
				mov		#~h'40, r0                  
				mov.l	#reg_TIER3, r10			
				mov.w	@r10, r10				
				and		r0, r10						
				mov.l	#reg_TIER3, r11			
				mov.w	r10, @r11				
				mov		#1, r10						
				mov.l	#downTimer_801,	r11		
				mov.w	r10, @r11				
				mov.l	#__enable_irq, r10		
				jsr		@r10 ; __enable_irq			
				nop								

				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function SysInit_ATU_2A_2B_3_4_5_8_10

;+++++++++++++++++++++++++++++++++++++++++++++++
	.NOPOOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ==============


Init_ATU_2A_2B_3_4_5_8_10:						
												
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov	r15, r14					
				mov.l	#__disable_irq,	r10		
				jsr	@r10 ; __disable_irq		
				nop								


;PSCR1=PSCR4 = 4	MHz

				mov		#3, r10						
				mov.l	#reg_PSCR1, r11			
				mov.b	r10, @r11				
				mov.l	#reg_PSCR4, r11			
				mov.b	r10, @r11				


;TCR2A=TCR2B=TCR3=TCR4=TCR5 = internal clock 250	kHz

				mov		#h'34, r10 ; '4'                 
				mov.l	#reg_TCR2A, r11				
				mov.b	r10, @r11					
				mov.l	#reg_TCR2B, r11				
				mov.b	r10, @r11					
				mov.l	#reg_TCR3, r11				
				mov.b	r10, @r11					
				mov.l	#reg_TCR4, r11				
				mov.b	r10, @r11					
				mov.l	#reg_TCR5, r11				
				mov.b	r10, @r11					

				mov.l	#reg_TCR8, r0				
				mov.b	@r0, r0						
				and		#h'F, r0                         
				or		#h'50, r0                        
				mov.l	#reg_TCR8, r10				
				mov.b	r0, @r10					
				mov		#h'30, r10 ; '0'                 
				mov.l	#reg_TIOR10, r11			
				mov.b	r10, @r11				
				mov		#0, r10						
				mov.l	#reg_TCR10, r11			
				mov.b	r10, @r11				
				mov		#h'10, r10                  
				mov.l	#reg_TIER10, r11		
				mov.w	r10, @r11				
				mov		#0, r10						
				mov.l	#reg_TMDR, r11			
				mov.b	r10, @r11				
				mov.l	#reg_TSTR1, r0			

loc_B8F2:										
				mov.b	@r0, r0					
				and		#2, r0						
				or		#h'7D, r0                   
				mov.l	#reg_TSTR1, r10			
				mov.b	r0, @r10				
				mov.w	#2495, r10				
				mov.l	#reg_CMCOR0, r11		
				mov.w	r10, @r11				
				mov.l	#reg_CMCSR0, r10		
				mov.w	@r10, r10				
				mov.l	#~h'FFFF0043, r11       
				and		r11, r10					
				mov		r10, r0						
				or		#h'40, r0                   
				mov.l	#reg_CMCSR0, r10		
				mov.w	r0, @r10				
				mov.l	#reg_CMSTR, r0			
				mov.w	@r0, r0					
				or		#1, r0						
				mov.l	#reg_CMSTR, r10			
				mov.w	r0, @r10				
				mov.w	#h'FFFFFC5F, r0         
				mov.l	#reg_TIER3, r10			
				mov.w	@r10, r10				
				and		r0, r10						
				mov.l	#reg_TIER3, r11			
				mov.w	r10, @r11				
				mov		#h'11, r10                  
				mov.l	#reg_TIOR4A, r11		
				mov.b	r10, @r11				
				mov.l	#reg_TIOR4B, r11		
				mov.b	r10, @r11				
				mov		#h'FFFFFFBF, r0             
				mov.l	#reg_TIER3, r10			
				mov.w	@r10, r10				
				and		r0, r10						
				mov.l	#reg_TIER3, r11			
				mov.w	r10, @r11				
				mov.l	#__enable_irq, r10		
				jsr		@r10 ; __enable_irq			
				nop								

				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rts								
				nop								

; End of function Init_ATU_2A_2B_3_4_5_8_10

; ----------------------------------------------

;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++

; =============== S U B	R O U T	I N E ============

; 801.6	Hz

cmti0:											
				sts.l	pr, @-r15				
				mov.l	r14, @-r15				
				mov		r15, r14					
				sts.l	macl, @-r15				
				sts.l	mach, @-r15				
				mov.l	r10, @-r15				
				mov.l	r11, @-r15				
				mov.l	r12, @-r15				
				mov.l	r13, @-r15				
				mov.l	r3, @-r15				
				mov.l	r4, @-r15				
				mov.l	r5, @-r15				
				mov.l	r6, @-r15				
				mov.l	r7, @-r15				
				mov.l	r0, @-r15				
				mov.l	#__disable_irq,	r10		
				jsr		@r10 ; __disable_irq		
				nop								; 

				mov.l	#reg_TCNT2A, r10		
				mov.w	@r10, r10				
				mov.l	#word_FFFF9AD6,	r11		
				mov.w	r10, @r11				
				mov.w	#~h'80, r0                
				mov.l	#reg_CMCSR0, r10		
				mov.w	@r10, r10				
				and		r0, r10						
				mov.l	#reg_CMCSR0, r11		
				mov.w	r10, @r11				
				mov.l	#downTimer_801,	r10		
				mov.w	@r10, r10				
				tst		r10, r10					
				bt		loc_BA20					

				mov.l	#downTimer_801,	r10		
				mov.w	@r10, r0				
				add		#-1, r0						
				mov.w	r0, @r10				


loc_BA20:										
				mov.l	#word_FFFF9AD2,	r10		
				mov.w	@r10, r0				
				mov.w	#312, r11				
				add		r11, r0						
				mov.w	r0, @r10				
				mov.l	#word_FFFF9AD2,	r10		
				mov.w	@r10, r10				
				mov.l	#reg_TCNT2A, r11		
				mov.w	@r11, r11				
				sub		r11, r10					
				extu.w	r10, r0					
				shlr8	r0						
				tst		#h'80, r0                     
				bt		loc_BA5C					

				mov.l	#word_FFFF9AD2,	r10		
				mov.w	@r10, r0				
				mov.w	#312, r11				
				add		r11, r0						
				mov.w	r0, @r10				
				mov.l	#__enable_irq, r10		
				jsr		@r10 ; __enable_irq			
				nop								 

				mov.l	#HUGE_Method_801_6_Hz, r10
				jsr		@r10 ; HUGE_Method_801_6_Hz	
				nop								

				mov.l	#HUGE_Method_801_6_Hz, r10
				jsr		@r10 ; HUGE_Method_801_6_Hz	
				nop								 

				bra	loc_BA76					
				nop								 

				.NOPOOL

; -------------------------------------------------

loc_BA5C:										
				mov.l	#__enable_irq, r10		
				jsr		@r10 ; __enable_irq			
				nop								

				mov.l	#HUGE_Method_801_6_Hz, r10
				jsr		@r10 ; HUGE_Method_801_6_Hz	
				nop								

				mov.l	#reg_TCNT2A, r10		
				mov.w	@r10, r10				
				mov.l	#word_FFFF9AD6,	r11		
				mov.w	@r11, r11				
				sub		r11, r10					
				mov.l	#word_FFFF9AD4,	r12		
				mov.w	r10, @r12				


loc_BA76:										
				mov.l	@r15+, r0				
				mov.l	@r15+, r7				
				mov.l	@r15+, r6				
				mov.l	@r15+, r5				
				mov.l	@r15+, r4				
				mov.l	@r15+, r3				
				mov.l	@r15+, r13				
				mov.l	@r15+, r12				
				mov.l	@r15+, r11				
				mov.l	@r15+, r10				
				lds.l	@r15+, mach				
				lds.l	@r15+, macl				
				mov.l	@r15+, r14				
				lds.l	@r15+, pr				
				rte								
				nop								

; End of function cmti0

; -------------------------------------------------

;+++++++++++++++++++++++++++++++++++++++++++++++
	.POOL
;+++++++++++++++++++++++++++++++++++++++++++++++

;+++++++++++++++++++++++++++++++++++++++++++++++

		.END
		
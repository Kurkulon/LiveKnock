
	.IMPORT	_Main_Engine_Control_Loop

;reset_stack_pointer:						.EQU	H'FFFFAB00
;StatusRegisterStack:						.EQU	H'FFFFABA0
dword_FFFF9AF8:								.EQU	H'FFFF9AF8
reg_DMAOR:									.EQU	H'FFFFECB0

	.AIFDEF	DEF_STACK_REPLACE

stack_end:									.EQU	H'FFFFAFFF
stack_size:									.EQU	H'200
status_stack_size:							.EQU	H'80
	
	.AELSE

stack_end:									.EQU	H'FFFFABA3
stack_size:									.EQU	H'300
status_stack_size:							.EQU	H'A4

	.AENDI

stack_start:								.EQU	(stack_end - stack_size - status_stack_size + 3) & H'FFFFFFFC

	.AIFDEF DEF_RESET
	.AENDI

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	.SECTION    B_STACK, STACK, LOCATE=stack_start
	
	.RES.L	(stack_size+3)/4
	
reset_stack_pointer:

	.RES.L	(status_stack_size+3)/4-1
	
StatusRegisterStack:

	.RES.L	1	
	

;	.SECTION C_9CBC, CODE, LOCATE=H'9CBC	;++++++++++++++++++++++++++++
;	
;		.DATA.L		reset_stack_pointer
;		.DATA.L		StatusRegisterStack
;		.DATA.L		StatusRegisterStack
;
;
;	.SECTION C_450, CODE, LOCATE=H'450	;+++++++++++++++++++++++++++++++
;	
;		.DATA.L		StatusRegisterStack
		

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;+++++++++++++++++++++++++++++++++++++++++++++++

	.EXPORT __disable_irq, ___disable_irq, __enable_irq, ___enable_irq, Set_Intterupt_Mask, _Set_Intterupt_Mask
	
	.SECTION    P_IRQ_FUNC, CODE, LOCATE=H'400

	.ORG H'400

__disable_irq:		; =============== S U B	R O U T	I N E ==========
___disable_irq:									
												
	mov.l	r0, @-r15				
	mov.l	r3, @-r15				
	mov.l	r4, @-r15				
	stc	sr, r0						
	mov	r0, r4						
	or	#h'F0, r0                   
	ldc	r0, sr						
							
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

	.ORG H'41E

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

	.ORG H'430

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


	.SECTION INIT_9CA4, CODE, LOCATE=H'9CA4

init:

    mov.l   #reset_stack_pointer, r15                              
    mov.l   #StatusRegisterStack, r0                               
;   mov.l   #StatusRegisterStack, r1                               
    mov.l   r0, @r0                                                
    mov     #0, r0                                                 
    ldc     r0, vbr                                                
    ldc     r0, gbr 
                                                   
    mov.l   #_Main_Engine_Control_Loop, r0                          
    jsr     @r0                       
    nop      
    
    bra		reset_ADIO 
    nop
                                
    .POOL                                                      

	.ORG H'9CCC
	
reset_ADIO:                                                                                    
                                                                                               
    mov		#H'F0, r0                                           
    ldc		r0, sr                                               
    mov.l   #init, r0                                              
    jmp     @r0 ; init                                             
    nop                                                            

; End of function init

; ---------------------------------------------------------------------------

	.POOL

; =============== S U B R O U T I N E =======================================


	.ORG H'9CE0

cpu_addr_err:                                                                                  
                                                                                               
    mov.l   r0, @-r15                                              
    mov.l   r4, @-r15                                              
    mov.l   r5, @-r15                                              
    mov     r15, r0                                                
    add     #h'C, r0                                               
    mov.l   @r0, r4                                                
    mov.w	#dword_FFFF9AF8, r5                                    
    mov.l   @r5, r0                                                
    cmp/eq  #0, r0                                                 
    bf      ?0001                                               

    mov.l   r4, @r5                                                

?0001:                                                                      

    mov		#h'FFFFFFFB, r5                                        
	mov.w	#reg_DMAOR, r4 
    mov.w   @r4, r0                                                
    and     r5, r0                                                 
    mov.w   r0, @r4                                                
    mov.l   @r15+, r5                                              
    mov.l   @r15+, r4                                              
    mov.l   @r15+, r0                                              
    rte                                                            
    nop                                                            

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.END
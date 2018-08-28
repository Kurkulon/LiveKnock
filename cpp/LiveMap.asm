	.PROGRAM  asd

	.CPU   SH2                                   ; Assembles program for the SH-2. 
	
	.IMPORT	ROM
	
	.INCLUDE "cpp\def.inc"
	
	.EXPORT _LiveMap
	.EXPORT ___DMAOPFLAG
	.EXPORT DMAEND, RXI0, TEIE


;DEF_XREFS:				.DEFINE		"1"
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    B_LIVEMAP, DATA, LOCATE=H'FFFF8400

___DMAOPFLAG:					.RES.L 1	; H'ffff8480
DMAOPFLAG2:						.RES.L 1	; H'ffff8484
DMAadr:							.RES.L 1	; H'ffff8488
DMAlength:						.RES.W 1	; H'ffff848c

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_10A0_13FF_LIM, CODE, LOCATE=H'13FF

					.DATA.B      H'FF

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

								
								
serialreceivewithoutdma:		.EQU	H'D34A		;/*TO BE CHANGED FOR EACH ROM*/
bit7allowslogging:				.EQU	H'ffff8E42 	;/*TO BE CHANGED FOR EACH ROM*/
mutorobd:						.EQU	H'ffff8E08 	;/*TO BE CHANGED FOR EACH ROM*/
receive_transmit_status_bits:	.EQU	H'ffff8E3E 	;/*TO BE CHANGED FOR EACH ROM*/
mut_timeout:					.EQU	H'ffff8EAC 	;/*TO BE CHANGED FOR EACH ROM*/
SAR3:							.EQU	H'ffffecf0
DAR3:							.EQU	H'ffffecf4
DMATCR3:						.EQU	H'ffffecf8
CHCR3:							.EQU	H'ffffecfc
DMA3CONFIGread:					.EQU	H'20105
DMA3CONFIGwriteindirect:		.EQU	H'10011005
DMA3CONFIGwritedirect:			.EQU	H'11005

SCR0:							.EQU	H'fffff002
TDR0:							.EQU	H'fffff003
SSR0:							.EQU	H'fffff004
RDR0:							.EQU	H'fffff005


SCR0_CLRTIE_SETTEIE:			.EQU	H'24
SCR0_SETRE_CLRTEIE:				.EQU	H'70
SCR0_CLRRE_SETTIE:				.EQU	H'a0

DEADloc:						.EQU	H'ffffA800

tephra:							.EQU	H'3E000		;	/*CHANGE FOR 256K ECUS*/
;ROM:							.EQU	altMUT		; H'37b00
;RAM:							.EQU	H'FFFFA000
;LENGTH:						.EQU	H'800
;DEADval:						.EQU	H'DEAD

HookedProc:						.EQU	H'A98A

								.IMPORT	_LiveKnock ;, _DMAEND, _RXI0, _TEIE


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	.AIFDEF	DEF_XREFS

	;Baudrate

			.SECTION C_D0D0, CODE, LOCATE=H'D0D0

				 mov     #h'3, r13                                  

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.SECTION C_D0F6, DATA, LOCATE=H'D0F6

				.DATA.B		H'88, H'37		;	cmp/eq  #h'37, r0
				.DATA.B		H'89			;	bt		#h'D12E                                  

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		;	.SECTION C_EC28, DATA, LOCATE=H'EC28

		;		.DATA.L		COPY                                    

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.SECTION C_D314, DATA, LOCATE=H'D314

				.DATA.L		___DMAOPFLAG		;	0xD316=0x84,0x80                               

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.SECTION C_D8D8, CODE, LOCATE=H'D8D8

				nop							;	0xD8D8=0,9                               

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.SECTION C_E5A2, DATA, LOCATE=H'E5A2

				.DATA.B		H'9A, H'6A		;	 mov.w   #h'70B, r10 ; 0XE5A2=0X9A,0X6A                              

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.SECTION C_E5E2, CODE, LOCATE=H'E5E2

				nop							;	0XE5E2=0,9                              

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.SECTION C_E60E, DATA, LOCATE=H'E60E

				.DATA.B		H'9A, H'34		;	 mov.w   #h'70B, r10 ; 0XE60E=0X9A,0X34                              

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.SECTION C_E64E, CODE, LOCATE=H'E64E

				nop							;	0XE64E=0,9                              

		;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.SECTION C_E67A, DATA, LOCATE=H'E67A

				.DATA.W		H'70B			;	0XE67A=7,0X0B                             

	.AENDI

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_138, DATA, LOCATE=H'138

		.DATA.L		DMAEND                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_324, DATA, LOCATE=H'324

		.DATA.L		RXI0                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_32C, DATA, LOCATE=H'32C

		.DATA.L		TEIE                                    


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
	.SECTION P_LIVEDMA, CODE, LOCATE=H'10A0 ;H'3E000

; !!! PATCH this address to 0x324

RXI0:

	add  	#-4, r15		;SORT OUT THE STACK
	sts.l	pr, @-r15
	mov.l	r14, @-r15
	mov  	r15, r14
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

	mov.l	#int_disable,r10
	jsr		@r10
	nop             

	mov.l	#RDR0,r10							;READ SERIAL PORT
	mov.b	@r10,r10
	extu.b	r10,r10
	mov.w	#H'E0,r3		
	cmp/hs	r3,r10								;EXIT IF NOT E0,E1,E2
	bf		exitformut
	
	mov.w	#H'E2,r3
	cmp/hi	r3,r10
	bt		exitformut
	
	mov.l   #bit7allowslogging, r0
	mov.w   @r0, r0
	tst     #H'80, r0							;EXIT IF NOT LOGGING
	bt      exitformut
	
	mov.l   #mutorobd, r0
	mov.w   @r0, r0
	tst     #H'80, r0 ;EXIT IF NOT IN MUT MODE
	bt      exitformut
	
	mov.l   #receive_transmit_status_bits, r0
	mov.w   @r0, r0
	tst     #H'80, r0							;CHECK WE ARE NOT GETTING AN ECHO OF SOMETHING WE JUST SENT
	bf      exitformut

brE012: ;FOR SETTING UP FIRST DMA TRANSFER

	mov.l 	#DMAOPFLAG2,r11
	mov.l 	r10,@r11
	mov		#0,r0
	mov.l	#mut_timeout,r10 ;STOP MUT TIMEOUT
	mov.w	r0,@r10
	mov		#H'fffffffc,r0
	mov.l 	#CHCR3,r10 ;RESET DMA
	mov.l 	@r10,r10
	and		r0,r10
	mov.l 	#CHCR3,r11
	mov.l 	r10,@r11
	mov.l 	#RDR0,r0
	mov.l 	#SAR3,r11			;SOURCE IS SERIAL PORT
	mov.l 	r0,@r11
	mov.l 	#DMAadr,r0
	mov.l 	#DAR3,r11			;DESTINATION IS OUR OWN...
	mov.l 	r0,@r11
	mov		#6,r0				;...6 BYTE MEMORY BLOCK - FOUR BYTES ADDRESS, TWO BYTES LENGTH
	mov.l 	#DMATCR3,r11
	mov.l 	r0,@r11
	mov		#H'37,r0			; 0X37	IS THE NUMBER OF MY CHILDHOOD HOME - SUITABLE RANDOM NON ZERO NUMBER THAT WE CAN SET WHEN WE DON'T WANT THE ECU TO KILL OUR DMA PROCESS
	mov.l 	#___DMAOPFLAG,r10
	mov.l 	r0,@r10
	mov.l 	#SSR0,r10
	mov.b 	@r10,r0
	and		#H'87,r0 ;RESET SERIAL PORT
	mov.b 	r0,@r10
	mov.l 	#DMA3CONFIGread,r0				;SET DMA CHANNEL 3 TO READ FROM SERIAL PORT
	mov.l 	#CHCR3,r10
	mov.l 	r0,@r10
	mov.l 	#int_enable,r10
	jsr		@r10
	nop
	bra		exit
	nop

	.NOPOOL

exitformut:

	mov.l #int_enable,r10
	jsr @r10
	nop
  
	mov.l #serialreceivewithoutdma,r10		;BACK TO NORMAL SERIAL INTERRUPT, NONE OF OUR BUSINESS!
	jsr @r10
	nop

exit:

  mov.l   @r15+, r0 ;STACK
  mov.l   @r15+, r7
  mov.l   @r15+, r6
  mov.l   @r15+, r5
  mov.l   @r15+, r4
  mov.l   @r15+, r3
  mov.l   @r15+, r13
  mov.l   @r15+, r12
  mov.l   @r15+, r11
  mov.l   @r15+, r10
  lds.l   @r15+, mach
  lds.l   @r15+, macl
  mov.l   @r15+, r14
  lds.l   @r15+, pr
  add     #4, r15
  rte				;RETURN FROM EXCEPTION/INTERRUPT
  nop

	.NOPOOL

	.ALIGN 2

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;	.align 16

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; !!! PATCH this address to 0x138
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

DMAEND: 

	sts.l 	pr,@-r15			;STACK
	mov.l 	r0,@-r15
	mov.l 	r10,@-r15
	mov.l 	#int_disable,r10	;STOP INTERRUPTS
	jsr		@r10
	nop

	mov		#H'fffffffc,r0
	mov.l	#CHCR3,r10 ;CLEAR DMA PROCESS
	mov.l 	@r10,r10
	and		r10,r0
	mov.l 	#CHCR3,r10
	mov.l 	r0,@r10

	mov.l	#DMAOPFLAG2,r0 ;SINCE WE USE TWO CONSECUTIVE DMA PROCESSES, I USE THIS VARIABLE TO KEEP TRACK OF WHAT WE'RE DOING - READ, WRITE ETC.
	mov.l	@r0,r0
	mov		#1,r10
	cmp/eq	r10,r0
	bt		brwrite
	nop
	
	mov.w	#H'E0,r10
	cmp/eq	r10,r0
	bt		brE0
	nop
	
	mov.w	#H'E1,r10
	cmp/eq	r10,r0
	bt		brE1
	nop
	
	mov.w	#H'E2,r10
	cmp/eq	r10,r0
	bt		brE2
	nop
	
	bra		TEIEinvade
	nop
	
	.NOPOOL

brwrite:

	mov.l	#SSR0,r10
	mov.b	@r10,r0
	tst		#4,r0
	bf		TEIEinvade ;DMA MAY HAVE ENDED BUT SERIAL PORT TRANSMISSION MAY NOT HAVE
	nop

	mov.w 	#SCR0_CLRTIE_SETTEIE,r0 ;SETUP TRANSMIT END INTERRUPT IF NOT YET FINISHED
	mov.l 	#SCR0,r10
	mov.b 	r0,@r10

	mov.l	#int_enable,r10
	jsr		@r10
	nop
	mov.l 	@r15+,r10
	mov.l 	@r15+,r0
	lds.l 	@r15+,pr
	rte
	nop

	.NOPOOL

brE0: ;USES EARLIER 4 BYTE ADDRESS AND 2 BYTE LENGTH TO LOG THE MUT TABLE

	mov		#1,r0
	mov.l 	#DMAOPFLAG2,r10
	mov.l 	r0,@r10
	mov.l 	#DMAadr,r0
	mov.l 	@r0,r0
	mov.l 	#SAR3,r10
	mov.l 	r0,@r10
	mov.l 	#TDR0,r0
	mov.l 	#DAR3,r10
	mov.l 	r0,@r10
	mov.l 	#DMAlength,r0
	mov.w 	@r0,r0
	mov.l 	#DMATCR3,r10
	mov.l 	r0,@r10
	mov		#H'37,r0
	mov.l 	#___DMAOPFLAG,r10
	mov.l 	r0,@r10
	mov.w 	#SCR0_CLRRE_SETTIE,r0
	mov.l 	#SCR0,r10
	mov.b 	r0,@r10
	mov.l 	#DMA3CONFIGwriteindirect,r0
	mov.l 	#CHCR3,r10
	mov.l 	r0,@r10
	mov.l 	#int_enable,r10
	jsr		@r10
	nop
	mov.l 	@r15+,r10
	mov.l 	@r15+,r0
	lds.l 	@r15+,pr
	rte
	nop

	.NOPOOL

brE1: ;USES PREVIOUS 4 BYTE ADDRESS AND 2 BYTE LENGTH TO WRITE A BLOCK OF RAM TO THE SERIAL PORT

	mov		#1,r0
	mov.l 	#DMAOPFLAG2,r10
	mov.l 	r0,@r10
	mov.l 	#DMAadr,r0
	mov.l 	@r0,r0
	mov.l	#SAR3,r10
	mov.l 	r0,@r10
	mov.l 	#TDR0,r0
	mov.l 	#DAR3,r10
	mov.l 	r0,@r10
	mov.l 	#DMAlength,r0
	mov.w 	@r0,r0
	mov.l 	#DMATCR3,r10
	mov.l 	r0,@r10
	mov		#H'37,r0
	mov.l 	#___DMAOPFLAG,r10
	mov.l 	r0,@r10
	mov.w 	#SCR0_CLRRE_SETTIE,r0
	mov.l 	#SCR0,r10
	mov.b 	r0,@r10
	mov.l 	#DMA3CONFIGwritedirect,r0
	mov.l 	#CHCR3,r10
	mov.l 	r0,@r10
	mov.l 	#int_enable,r10
	jsr		@r10
	nop
	mov.l 	@r15+,r10
	mov.l 	@r15+,r0
	lds.l 	@r15+,pr
	rte
	nop

	.NOPOOL

brE2: ;USES PREVIOUS 4 BYTE ADDRESS AND 2 BYTE LENGTH TO READ A BLOCK FROM SERIAL PORT AND WRITE IT TO RAM

	mov		#2,r0
	mov.l 	#DMAOPFLAG2,r10
	mov.l 	r0,@r10
	mov.l 	#RDR0,r0
	mov.l 	#SAR3,r10
	mov.l 	r0,@r10
	mov.l 	#DMAadr,r0
	mov.l 	@r0,r0
	mov.l 	#DAR3,r10
	mov.l 	r0,@r10
	mov.l 	#DMAlength,r0
	mov.w	@r0,r0
	mov.l	#DMATCR3,r10
	mov.l	r0,@r10
	mov		#H'37,r0
	mov.l 	#___DMAOPFLAG,r10
	mov.l 	r0,@r10
	mov.l 	#SSR0,r10
	mov.b 	@r10,r0
	and		#H'87,r0
	mov.b 	r0,@r10
	mov.l 	#DMA3CONFIGread,r0
	mov.l 	#CHCR3,r10
	mov.l 	r0,@r10
	mov.l 	r0,@r10
	mov.l 	#int_enable,r10
	jsr		@r10
	nop
	mov.l 	@r15+,r10 ;STACK
	mov.l 	@r15+,r0
	lds.l 	@r15+,pr
	rte				;RETURN FROM EXCEPTION/INTERRUPT
	nop

	.NOPOOL

;	.align 16


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; !!! PATCH this address to 0x32C
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEIE: ;TRANSMIT END INTERRUPT

	sts.l 	pr,@-r15
	mov.l 	r0,@-r15
	mov.l 	r10,@-r15
	mov.l 	#int_disable,r10
	jsr		@r10
	nop
	
TEIEinvade: ;JUMP HERE FROM EARLIER IF TRANSMISSION HAS ALREADY FINISHED

	mov		#0,r0
	mov.l 	#___DMAOPFLAG,r10 ;CLEAR OUR 0X37 VARIABLE
	mov.l 	r0,@r10
	mov.w 	#SCR0_SETRE_CLRTEIE,r0 ;RESET SERIAL PORT INTERRUPT CONFIG
	mov.l 	#SCR0,r10
	mov.b	r0,@r10

	mov.l 	#SSR0,r10 ;RESET SERIAL PORT STATUS FOR NEXT COMMS
	mov.b 	@r10,r0
	and		#H'87,r0
	mov.b	r0,@r10

	mov.l	#int_enable,r10
	jsr		@r10
	nop
	mov.l 	@r15+,r10 ;STACK
	mov.l 	@r15+,r0
	lds.l 	@r15+,pr
	rte
	nop

;	.align 2
	
	.POOL

	
;	.align 16
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; !!! 932700xx PATCH this address to 0xEC28
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
_LiveMap: ;COPY ROM TO RAM IF TEPHRA'S DEAD VARIABLE IS NOT 0XDEAD

	sts.l   pr, @-r15                                               
	mov.l   r14, @-r15                                              
	mov     r15, r14                                                
	
	mov.w 	#DEADval,r0
	mov.w 	#DEADloc,r1
	mov.w	@r1,r1
	cmp/eq	r1,r0
	bt		TIMEOUT
	nop

	mov.l 	#ROM,r10
	mov.w 	#RAM,r11
	mov.w 	#LENGTH,r1
	mov		#0,r0
	
loop:

	mov.l 	@(r0,r10),r2
	mov.l 	r2,@(r0,r11)
	add		#4,r0
	cmp/hs	r1,r0
	bf		loop
	nop

TIMEOUT: ;KILLS DMA IF COMMS HAVE BEEN KILLED

	mov.w	#int_disable,r10
	jsr		@r10
	nop

	mov.w	#bit7allowslogging,r10
	mov.w	@r10,r0
	tst		#H'80,r0
	bf		__exit
	nop

	mov		#H'fffffffc,r0
	mov.w 	#CHCR3,r10
	mov.l 	@r10,r10
	and		r10,r0
	mov.w 	#CHCR3,r10
	mov.l 	r0,@r10

	mov		#0,r0
	mov.w 	#___DMAOPFLAG,r10
	mov.l 	r0,@r10

__exit:

	mov.w	#int_enable,r10
	jsr		@r10
	nop
	
;	mov.l	#_LiveKnock,r10
;	jsr		@r10
;	nop
	
;	mov.l	#HookedProc, r10
;	jsr		@r10
;	nop
	
	mov.l   @r15+, r14                                              
	lds.l   @r15+, pr                                               
	rts                                                             
	nop    	

	.POOL

	.align 2
	

	.END
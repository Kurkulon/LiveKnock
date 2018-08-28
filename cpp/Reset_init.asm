
	.IMPORT	_Main_Engine_Control_Loop

reset_stack_pointer:						.EQU	H'FFFFAB00
StatusRegisterStack:						.EQU	H'FFFFABA0
dword_FFFF9AF8:								.EQU	H'FFFF9AF8
reg_DMAOR:									.EQU	H'FFFFECB0

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	.SECTION INIT_9CA4, CODE, LOCATE=H'9CA4

init:

                                mov.l   #reset_stack_pointer, r15                              
                                mov.l   #StatusRegisterStack, r0                               
                                mov.l   #StatusRegisterStack, r1                               
                                mov.l   r1, @r0                                                
                                mov     #0, r0                                                 
                                ldc     r0, vbr                                                
                                ldc     r0, gbr 
                                                                               
                                mov.l   #_Main_Engine_Control_Loop, r0                          
                                jsr     @r0                       
                                nop                                                            

reset_ADIO:                                                                                    
                                                                                               
                                mov		#H'F0, r0                                             ;
                                ldc		r0, sr                                               
                                mov.l   #init, r0                                              
                                jmp     @r0 ; init                                             
                                nop                                                            

; End of function init

; ---------------------------------------------------------------------------

	.POOL

; =============== S U B R O U T I N E =======================================


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
	
	.IMPORT	_int_nmi_E9AE, _dmac2_dei2, DMAEND, _atu02_ici0A, _atu11_imi1A, _atu11_imi1B, _atu11_imi1C, _atu12_imi1E
	.IMPORT	_atu21_imi2A, _atu21_imi2C, _atu21_imi2D, _atu22_imi2E, _atu22_imi2F, _atu22_imi2G, _atu22_imi2H, _atu41_imi4B, _atu82_osi8G 
	.IMPORT	_atu11_imi11B, _cmti0, _cmti1, _sci0_eri0, RXI0, TEIE, _sci1_eri1, _sci2_txi2
	


	.SECTION VTBL, DATA, LOCATE=0
	
v_power_on_pc:                  .data.l init                                                    
                                                                                                
v_power_on_sp:                  .data.l reset_stack_pointer
v_reset_pc:                     .data.l init
v_reset_sp:                     .data.l reset_stack_pointer
v_gen_ill_inst:                 .data.l reset_ADIO
                                .data.l reset_ADIO
v_slot_ill_inst:                .data.l reset_ADIO
                                .data.l reset_ADIO
off_20:                         .data.l reset_ADIO                                              
v_cpu_addr_err:                 .data.l cpu_addr_err
v_dmac_addr_err:                .data.l cpu_addr_err
v_int_nmi_2C:                   .data.l _int_nmi_E9AE
v_int_userbreak:                .data.l reset_ADIO                                              
                                                                                                
                                .data.l reset_ADIO
                                .data.l reset_ADIO
off_3C:                         .data.l reset_ADIO                                              
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
off_50:                         .data.l reset_ADIO                                              
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
off_60:                         .data.l reset_ADIO                                              
                                                                                                
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
off_78:                         .data.l reset_ADIO                                              
                                .data.l reset_ADIO
off_80:                         .data.l reset_ADIO                                              
                                                                                                
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
off_90:                         .data.l reset_ADIO                                              
off_94:                         .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
off_F0:                         .data.l reset_ADIO                                              
                                                                                                
                                .data.l reset_ADIO
                                .data.l reset_ADIO
off_FC:                         .data.l reset_ADIO                                              
                                                                                                
v_int_irq0:                     .data.l reset_ADIO                                              
v_int_irq1:                     .data.l reset_ADIO
v_int_irq2:                     .data.l reset_ADIO
v_int_irq3:                     .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_dmac0_dei0:                   .data.l reset_ADIO
                                .data.l reset_ADIO
v_dmac1_dei1:                   .data.l reset_ADIO
                                .data.l reset_ADIO
v_dmac2_dei2:                   .data.l _dmac2_dei2
                                .data.l reset_ADIO
v_dmac3_dei3:                   .data.l DMAEND
                                .data.l reset_ADIO
v_atu01_itv1:                   .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu02_ici0A:                  .data.l _atu02_ici0A
                                .data.l reset_ADIO
v_atu02_ici0B:                  .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu03_ici0C:                  .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu03_ici0D:                  .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu04_ovi0:                   .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu11_imi1A:                  .data.l _atu11_imi1A
v_atu11_imi1B:                  .data.l _atu11_imi1B
v_atu11_imi1C:                  .data.l _atu11_imi1C
v_atu11_imi1D:                  .data.l reset_ADIO
v_atu12_imi1E:                  .data.l _atu12_imi1E
v_atu12_imi1F:                  .data.l reset_ADIO
v_atu12_imi1G:                  .data.l reset_ADIO
v_atu12_imi1H:                  .data.l reset_ADIO
v_atu13_ovi1AB:                 .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu21_imi2A:                  .data.l _atu21_imi2A
v_atu21_imi2B:                  .data.l reset_ADIO
v_atu21_imi2C:                  .data.l _atu21_imi2C
v_atu21_imi2D:                  .data.l _atu21_imi2D
v_atu22_imi2E:                  .data.l _atu22_imi2E
v_atu22_imi2F:                  .data.l _atu22_imi2F
v_atu22_imi2G:                  .data.l _atu22_imi2G
v_atu22_imi2H:                  .data.l _atu22_imi2H
v_atu23_ovi2AB:                 .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu31_imi3A:                  .data.l reset_ADIO
v_atu31_imi3B:                  .data.l reset_ADIO
v_atu31_imi3C:                  .data.l reset_ADIO
v_atu31_imi3D:                  .data.l reset_ADIO
v_atu32_ovi3:                   .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu41_imi4A:                  .data.l reset_ADIO                                              
                                                                                                
v_atu41_imi4B:                  .data.l _atu41_imi4B
v_atu41_imi4C:                  .data.l reset_ADIO
v_atu41_imi4D:                  .data.l reset_ADIO
v_atu42_ovi4:                   .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu51_imi5A:                  .data.l reset_ADIO
v_atu51_imi5B:                  .data.l reset_ADIO
v_atu51_imi5C:                  .data.l reset_ADIO
v_atu51_imi5D:                  .data.l reset_ADIO
v_atu52_ovi5:                   .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu6_cmi6A:                   .data.l reset_ADIO
v_atu6_cmi6B:                   .data.l reset_ADIO
v_atu6_cmi6C:                   .data.l reset_ADIO
v_atu6_cmi6D:                   .data.l reset_ADIO
v_atu7_cmi7A:                   .data.l reset_ADIO
v_atu7_cmi7B:                   .data.l reset_ADIO
v_atu7_cmi7C:                   .data.l reset_ADIO
v_atu7_cmi7D:                   .data.l reset_ADIO
v_atu81_osi8A:                  .data.l reset_ADIO
v_atu81_osi8B:                  .data.l reset_ADIO
v_atu81_osi8C:                  .data.l reset_ADIO
v_atu81_osi8D:                  .data.l reset_ADIO
v_atu82_osi8E:                  .data.l reset_ADIO
v_atu82_osi8F:                  .data.l reset_ADIO
v_atu82_osi8G:                  .data.l _atu82_osi8G
v_atu82_osi8H:                  .data.l reset_ADIO
v_atu83_osi8I:                  .data.l reset_ADIO
v_atu83_osi8J:                  .data.l reset_ADIO
v_atu83_osi8K:                  .data.l reset_ADIO
v_atu83_osi8L:                  .data.l reset_ADIO
v_atu84_osi8M:                  .data.l reset_ADIO
v_atu84_osi8N:                  .data.l reset_ADIO
v_atu84_osi8O:                  .data.l reset_ADIO
v_atu84_osi8P:                  .data.l reset_ADIO
v_atu91_cmi9A:                  .data.l reset_ADIO
v_atu91_cmi9B:                  .data.l reset_ADIO
v_atu91_cmi9C:                  .data.l reset_ADIO
v_atu91_cmi9D:                  .data.l reset_ADIO
v_atu92_cmi9E:                  .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu92_cmi9F:                  .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu101_cmi10A:                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu101_cmi10B:                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu102_ici10A:                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu11_imi11A:                 .data.l reset_ADIO
                                .data.l reset_ADIO
v_atu11_imi11B:                 .data.l _atu11_imi11B
v_atu11_ovi11:                  .data.l reset_ADIO
v_cmti0:                        .data.l _cmti0                                                   
                                .data.l reset_ADIO
v_adi0:                         .data.l reset_ADIO
                                .data.l reset_ADIO
v_cmti1:                        .data.l _cmti1                                                   
                                .data.l reset_ADIO
v_adi1:                         .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
v_sci0_eri0:                    .data.l _sci0_eri0                                               
v_sci0_rxi0:                    .data.l RXI0
v_sci0_txi0:                    .data.l reset_ADIO
v_sci0_tei0:                    .data.l TEIE
v_sci1_eri1:                    .data.l _sci1_eri1
v_sci1_rxi1:                    .data.l _sci1_eri1
v_sci1_txi1:                    .data.l reset_ADIO
v_sci1_tei1:                    .data.l reset_ADIO
v_sci2_eri2:                    .data.l reset_ADIO
v_sci2_rxi2:                    .data.l reset_ADIO
v_sci2_txi2:                    .data.l _sci2_txi2
v_sci2_tei2:                    .data.l reset_ADIO
v_sci3_eri3:                    .data.l reset_ADIO
v_sci3_rxi3:                    .data.l reset_ADIO
v_sci3_txi3:                    .data.l reset_ADIO
v_sci3_tei3:                    .data.l reset_ADIO
v_sci4_eri4:                    .data.l reset_ADIO
v_sci4_rxi4:                    .data.l reset_ADIO
v_sci4_txi4:                    .data.l reset_ADIO
v_sci4_tei4:                    .data.l reset_ADIO
v_hcan_ers:                     .data.l reset_ADIO
v_hcan_ovr:                     .data.l reset_ADIO
v_hcan_rm:                      .data.l reset_ADIO
v_hcan_sle:                     .data.l reset_ADIO
v_wdt_iti:                      .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO
                                .data.l reset_ADIO


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.END
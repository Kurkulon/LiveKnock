
	.INCLUDE "cpp\def.inc"

;DEF_ENRICH_COOL_AIR_MAPS:	.DEFINE		"1"
TEST_INTERPOLATE:			.DEFINE		"1"
;DEF_NO_KNOCK_RETARD:		.DEFINE		"1"

;DEF_SIMULATION:				.DEFINE		"1"

;DEF_VEMAP16:				.DEFINE		"1"
;DEF_IGNMAP16:				.DEFINE		"1"

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF	DEF_SIMULATION

;Simulation test 

	.SECTION P_B3A0, CODE, LOCATE=H'B3A0

			nop   	                                                        

	.SECTION P_B426, CODE, LOCATE=H'B426

			nop   	                                                        

	.SECTION P_BB50, CODE, LOCATE=H'BB50

			nop   	                                                        

	.SECTION P_BF1C, CODE, LOCATE=H'BF1C

			nop   	                                                        

	.SECTION P_BF4C, CODE, LOCATE=H'BF4C

			nop   	                                                        

	.SECTION P_BF7C, CODE, LOCATE=H'BF7C

			nop  
			
	.AENDI 	                                                        

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    B_ALTMAPS, DATA, LOCATE=H'FFFF8420
	
	.EXPORT		_hiIgnMapIndex, _hiFuelMapIndex, _veMapIndex, _fixAFR, _openLoop, _forcedIdleRPM
	
_hiIgnMapIndex:		.RES.B      1					
_hiFuelMapIndex:	.RES.B      1					
_veMapIndex:		.RES.B      1					
_fixAFR:			.RES.B      1					
_openLoop:			.RES.B      1					
_forcedIdleRPM:		.RES.B      1					

	.ALIGN 2	
	
	.EXPORT		_axis_ig_RPM, _axis_ig_LOAD, _axis_fu_RPM, _axis_fu_LOAD, _axis_ve_RPM, _axis_ve_LOAD, _ve_index, _fb_VE, _ve_timer, _timeRPM, _no_knock_retard

_axis_ig_RPM:		.RES.W      1					
_axis_ig_LOAD:		.RES.W      1					
_axis_fu_RPM:		.RES.W      1					
_axis_fu_LOAD:		.RES.W      1					
_axis_ve_RPM:		.RES.W      1					
_axis_ve_LOAD:		.RES.W      1					
_fb_VE				.RES.B      1					
_ve_index:			.RES.B      1					
_ve_timer:			.RES.B      1					
_no_knock_retard:	.RES.B      1					
_timeRPM:			.RES.W      1					

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    B_ALTMAPS_LIM, DATA, LOCATE=H'FFFF8500
	
					.RES.B		1
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    C_2CC0_2FFF_LIM, DATA, LOCATE=H'2FFF

					.DATA.B      H'FF

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

IG04_GetLoadCorrectedDeltaTPS					.EQU	H'181DC
RPM21_6788_IGN									.EQU	H'6788
Table_Lookup_Axis								.EQU	H'CC6
LOAD12_67BC_IGN									.EQU	H'67BC
RT_FLAG1_FFFF8888								.EQU	H'FFFF8888
LowIgn_7C68										.EQU	H'7C68
Query_byte_2D_3D_Table							.EQU	H'DE0
LOWOCTIGNEGR_7AC8								.EQU	H'7AC8
ZERO_8_IGNITION_FLAGS							.EQU	H'FFFF8A0C
HIOCTIGNEGR_38CA								.EQU	H'38CA
Add_Lim_FFFF									.EQU	H'500
egrLowOctIgn									.EQU	H'FFFF8BC0
egrHighOctIgn									.EQU	H'FFFF8BC2
interpolate_r4_r5_r6							.EQU	H'B16
octanEgrIgnTiming								.EQU	H'FFFF8BC8
Sub_Lim_0										.EQU	H'F0C
Lim_FF											.EQU	H'590
ignition_FFFF8BC4								.EQU	H'FFFF8BC4
axisIndex_10_CoolTempSc							.EQU	H'FFFF8848
axisIndex_7_InAirTemp							.EQU	H'FFFF8852

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	.SECTION    B_FFFF851C,DATA, LOCATE=H'FFFF851C

	.EXPORT		_frameCount

_frameCount:		.RES.L      1					;	.EQU H'FFFF8462

;	.SECTION C_F0D4, DATA, LOCATE=H'F0D4

;	.DATA.L		_frameCount                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.IMPORT	_IG04_Update_OctanEgrIgnTiming

	.SECTION P_1801E, CODE, LOCATE=H'1801E
	
			mov.l	#_IG04_Update_OctanEgrIgnTiming, r0                           
			jmp   	@r0                                                             
			nop   	                                                        

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;	.IMPORT	_SysInit_NVRAM_OctaneNum, _SysInit_sub_16D74, _IG04_root_Update_Ignition

;	.SECTION P_ED48, DATA, LOCATE=H'ED48
	
;			.DATA.L _SysInit_NVRAM_OctaneNum
	
;	.SECTION P_F128, DATA, LOCATE=H'F128
	
;			.DATA.L _SysInit_sub_16D74
	
;	.SECTION P_EBF4, DATA, LOCATE=H'EBF4
	
;			.DATA.L _IG04_root_Update_Ignition

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;	.SECTION P_F506, CODE, LOCATE=H'F506

;			nop   	                                                        


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.IMPORT	_FU03_HI_LO_Octan

	.SECTION P_141C8, CODE, LOCATE=H'141C8

			mov.l	#_FU03_HI_LO_Octan, r0                           
			jmp   	@r0                                                             
			nop   	                                                        
	
	.EXPORT	_Mul32_Fix15
	
_Mul32_Fix15:										
												
			extu.w	r5, r5	
							
			dmulu.l	r4, r5					
			
			sts		mach, r4					
			sts		macl, r0
			
			mov.w	#16384, r5				

			clrt
			addc	r5, r0
			mov		#0, r5
			addc	r5, r4		

			mov.w	#32767, r5				
			cmp/hi	r5, r4					
			bt		?0001	
					
			shll	r0
			rotcl	r4
			
			rts								
			xtrct	r4, r0			
?0001:										
			rts								
			mov	#h'FFFFFFFF, r0             

	.EXPORT	_Mul_Fix30
	
_Mul_Fix30:										
			dmulu.l	r4, r5					
			
			sts		mach, r0					
			sts		macl, r4
			
			mov.l	#H'10000000, r5				

			clrt
			addc	r5, r4
			mov		#0, r5
			addc	r5, r0		
			bt		?0001	

			mov.l	#H'20000000, r5				
			cmp/hi	r5, r0					
			bt		?0001	
					
			shll	r4
			rotcl	r0
			
			shll	r4

			rts		
			rotcl	r0
?0001:										
			rts								
			mov	#h'FFFFFFFF, r0             

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.IMPORT	_FU03_VE_map_sub_14620

	.SECTION P_14620, CODE, LOCATE=H'14620
	
			mov.l	#_FU03_VE_map_sub_14620, r0                           
			jmp   	@r0                                                             
			nop   	                                                        
	
	.EXPORT	_Mul32_Fix14
	
_Mul32_Fix14:										
												
			extu.w	r5, r5	
							
			dmulu.l	r4, r5					
			
			sts		mach, r4					
			sts		macl, r0
			
			mov.w	#8192, r5				
			
			clrt
			addc	r5, r0
			mov		#0, r5
			addc	r5, r4		
			
			mov.w	#16383, r5				
			cmp/hi	r5, r4					
			bt		?0001	
					
			shll	r0
			rotcl	r4			
			shll	r0
			rotcl	r4	
					
			rts								
			xtrct	r4, r0			
?0001:										
			rts								
			mov	#h'FFFFFFFF, r0             

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.IMPORT	_Hook_ForcedIdleRPM

	.SECTION C_19454, CODE, LOCATE=H'19454
	
		.DATA.L		_Hook_ForcedIdleRPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.IMPORT	_FU03_sub_149E0_Hook
	
	.AIFDEF DEF_FU03_sub_149E0_Hook

	.SECTION P_149E0, CODE, LOCATE=H'149E0
	
			mov.l	#_FU03_sub_149E0_Hook, r0                           
			jmp   	@r0                                                             
			nop  
			
	.EXPORT	_Mul32_Fix23
	
_Mul32_Fix23:										
												
			extu.w	r5, r5	
							
			dmulu.l	r4, r5					
			
			sts		mach, r4					
			sts		macl, r0
			
			mov.l	#H'400000, r5				
			
			clrt
			addc	r5, r0
			mov		#0, r5
			addc	r5, r4		
			
			mov.l	#H'800000, r5				
			cmp/hi	r5, r4					
			bt		?0001	
					
			shll	r0
			rotcl	r4			
			
			shlr16	r0
			shlr8	r0
			
			shll8	r4
					
			rts								
			or		r4, r0			
?0001:										
			rts								
			mov	#h'FFFFFFFF, r0             

	.EXPORT	_Mul32_Fix24
	
_Mul32_Fix24:										
												
			extu.w	r5, r5	
							
			dmulu.l	r4, r5					
			
			sts		mach, r4					
			sts		macl, r0
			
			mov.l	#H'800000, r5				
			
			clrt
			addc	r5, r0
			mov		#0, r5
			addc	r5, r4		
			
			mov.l	#H'1000000, r5				
			cmp/hi	r5, r4					
			bt		?0001	
					
			shlr16	r0
			shlr8	r0
			
			shll8	r4
					
			rts								
			or		r4, r0			
?0001:										
			rts								
			mov	#h'FFFFFFFF, r0     
			
	.AENDI        

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;	.IMPORT	_Hook_Update_IAT_Sensor

;	.SECTION C_100DC, CODE, LOCATE=H'100DC
	
;			mov.l	#_Hook_Update_IAT_Sensor, r0                           
;			jmp   	@r0                                                             
;			nop   	                                                        

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF	DEF_NO_KNOCK_RETARD
	
	.SECTION P_Knock_retard_hook, CODE, LOCATE=H'458

Knock_retard_hook:

			MOV.L	#_no_knock_retard, R0  ; _no_knock_retard
			MOV.B   @R0, R0     ; no_knock_retard
			TST     R0, R0
			BT		Knock_retard_hook_loc1
			MOV     #0, R4      ; H'00000000

Knock_retard_hook_loc1:

			rts	
			mov     r4, r0                           

	.SECTION C_248F0, CODE, LOCATE=H'248F0
	
		.DATA.L		Knock_retard_hook                                    

	.AENDI
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_6746, DATA, LOCATE=H'6748

		.DATA.W		_axis_fu_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_676C, DATA, LOCATE=H'676C

		.DATA.L		_axis_fu_LOAD                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_5380, DATA, LOCATE=H'5380

		.DATA.L		_axis_fu_LOAD                                    
		.DATA.L		_axis_fu_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_540A, DATA, LOCATE=H'540C

		.DATA.W		_axis_ig_LOAD 
		.DATA.W		H'FFFF                                   
		.DATA.W		_axis_ig_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_6788, DATA, LOCATE=H'6788

		.DATA.L		_axis_ig_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_67BC, DATA, LOCATE=H'67BC

		.DATA.L		_axis_ig_LOAD                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_6CEE, DATA, LOCATE=H'6CEE

		.DATA.W		H'FFFF                                   
		.DATA.W		_axis_ve_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_6D1E, DATA, LOCATE=H'6D1E

		.DATA.W		H'FFFF                                   
		.DATA.W		_axis_ve_LOAD                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C_MUT, DATA, LOCATE=H'1400
	
			.align 4

altMUT:		
			.DATA.L		wMUT1C_ECU_Load+1
			.DATA.L		MUT21_RPM_x125div4+1                                    
			.DATA.L		wMUT26_Knock_Retard+1                                   
			.DATA.L		wMUT06_Timing_Advance+1                                 
			.DATA.L		wMUT3A_AirTemp_ADC8bit+1
			.DATA.L		wMUT10_Coolant_Temperature_Scaled+1
			.DATA.L		wMUT3C_Rear_O2_ADC8bit+1
			.DATA.L		_ve_index                   
			.DATA.L		wMUT17_TPS_ADC8bit+1
			.DATA.L		wMUT2A_Injector_Pulse_Width_us                          
			.DATA.L		wMUT27_Octane_Number+1
			.DATA.L		_fb_VE
			.DATA.L		wMUT32_Air_To_Fuel_Ratio+1
			.DATA.L		wMUT2F_Vehicle_Speed+1  
			.DATA.L		_ve_timer
			.DATA.L		wMUT0F_Oxygen_Feedback_Trim
			.DATA.L		wMUT13_Front_O2_ADC8bit+1
			.DATA.L		wMUT31_Volumetric_Efficiency+1
			.DATA.L		wMUT6A_Knock_ADC_Processed+1
			.DATA.L		wMUT6B_Knock_Base+1
			.DATA.L		_timeRPM
			.DATA.L		_timeRPM+1
			
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION C, DATA, LOCATE=H'38000
	
	.EXPORT	 ROM

			.align 4
ROM:

			.DATA.W		H'FFFF

hiFuelMap:
			.DATA.W 	H'300                                                   
			.DATA.L 	_axis_fu_RPM
			.DATA.L 	_axis_fu_LOAD
			.DATA.B 	14
hiFuelMapData:
			.DATA.B 	134,128,128,128,128,128,128,128,128,126,126,126,126,126
			.DATA.B 	134,128,128,128,128,128,128,128,128,130,132,138,140,142
			.DATA.B 	134,128,128,128,128,128,128,129,130,135,139,139,141,143
			.DATA.B 	134,128,128,128,128,128,133,133,138,143,143,143,145,147
			.DATA.B 	134,134,134,134,134,134,145,149,149,149,149,149,149,149
			.DATA.B 	139,139,139,139,139,139,147,149,149,149,149,149,149,149
			.DATA.B 	149,149,149,149,149,149,149,149,149,149,149,149,149,149
			.DATA.B 	149,149,149,149,149,149,149,149,149,149,149,149,149,149
			.DATA.B 	149,149,149,149,149,149,149,149,149,149,149,149,149,149
			
hiFuelMapRAM .EQU hiFuelMapData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	.EXPORT	 _hiIgnMapData

	.AIFDEF DEF_IGNMAP16
	
			.align 4
hiIgnMap:
			.DATA.W 	3                                                  
			.DATA.W 	0                                                  
			.DATA.L 	_axis_ig_RPM
			.DATA.L 	_axis_ig_LOAD
			.DATA.W 	21
_hiIgnMapData:
            .DATA.W  H'1C00, H'1D00, H'1D00, H'1D00, H'1D00, H'2000, H'2400, H'2B00, H'3400, H'3500, H'3500, H'3500, H'3600, H'3700, H'3900, H'3A00, H'3B00, H'3B00, H'3B00, H'3B00, H'3B00
            .DATA.W  H'1D00, H'1E00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2C00, H'3500, H'3600, H'3600, H'3600, H'3600, H'3700, H'3900, H'3B00, H'3C00, H'3C00, H'3C00, H'3C00, H'3C00
            .DATA.W  H'1D00, H'1E00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2C00, H'3500, H'3600, H'3600, H'3700, H'3700, H'3700, H'3800, H'3A00, H'3D00, H'3D00, H'3D00, H'3D00, H'3C00
            .DATA.W  H'1D00, H'1E00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2C00, H'3300, H'3400, H'3400, H'3400, H'3400, H'3400, H'3700, H'3A00, H'3C00, H'3C00, H'3C00, H'3C00, H'3C00
            .DATA.W  H'1D00, H'1E00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2C00, H'2E00, H'3200, H'3200, H'3200, H'3200, H'3200, H'3400, H'3600, H'3800, H'3A00, H'3A00, H'3A00, H'3A00
            .DATA.W  H'1B00, H'1C00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2800, H'2800, H'2B00, H'2E00, H'2F00, H'2F00, H'3000, H'3000, H'3100, H'3200, H'3400, H'3400, H'3400, H'3400
            .DATA.W  H'1600, H'1700, H'1900, H'1B00, H'1D00, H'1F00, H'2200, H'2400, H'2700, H'2900, H'2B00, H'2C00, H'2D00, H'2E00, H'2D00, H'2E00, H'2F00, H'3400, H'3400, H'3400, H'3400
            .DATA.W  H'0D00, H'0E00, H'1300, H'1500, H'1700, H'1A00, H'1D00, H'1E00, H'2300, H'2500, H'2800, H'2B00, H'2B00, H'2B00, H'2A00, H'2B00, H'2D00, H'3300, H'3300, H'3300, H'3300
            .DATA.W  H'0C00, H'0D00, H'1200, H'1400, H'1600, H'1900, H'1C00, H'1E00, H'2200, H'2300, H'2600, H'2900, H'2900, H'2900, H'2800, H'2800, H'2B00, H'3200, H'3200, H'3200, H'3200
            .DATA.W  H'0C00, H'0D00, H'1200, H'1400, H'1600, H'1800, H'1A00, H'1C00, H'2200, H'2200, H'2500, H'2800, H'2800, H'2800, H'2700, H'2700, H'2A00, H'3100, H'3100, H'3100, H'3100
            .DATA.W  H'0A00, H'0B00, H'1000, H'1200, H'1400, H'1600, H'1800, H'1A00, H'1E00, H'1E00, H'2100, H'2600, H'2600, H'2600, H'2500, H'2500, H'2800, H'2F00, H'2F00, H'2F00, H'2F00
            .DATA.W  H'0A00, H'0A00, H'0D00, H'0F00, H'1100, H'1300, H'1500, H'1800, H'1800, H'1A00, H'1D00, H'2200, H'2200, H'2200, H'2100, H'2100, H'2400, H'2C00, H'2C00, H'2C00, H'2C00
            
	.AELSE
	
			.align 4
			.DATA.W		H'FFFF
			
hiIgnMap:
			.DATA.W 	H'300                                                   
			.DATA.L 	_axis_ig_RPM
			.DATA.L 	_axis_ig_LOAD
			.DATA.B 	21
_hiIgnMapData:
            .DATA.B  H'1C, H'1D, H'1D, H'1D, H'1D, H'20, H'24, H'2B, H'34, H'35, H'35, H'35, H'36, H'37, H'39, H'3A, H'3B, H'3B, H'3B, H'3B, H'3B
            .DATA.B  H'1D, H'1E, H'1E, H'1E, H'1E, H'21, H'25, H'2C, H'35, H'36, H'36, H'36, H'36, H'37, H'39, H'3B, H'3C, H'3C, H'3C, H'3C, H'3C
            .DATA.B  H'1D, H'1E, H'1E, H'1E, H'1E, H'21, H'25, H'2C, H'35, H'36, H'36, H'37, H'37, H'37, H'38, H'3A, H'3D, H'3D, H'3D, H'3D, H'3C
            .DATA.B  H'1D, H'1E, H'1E, H'1E, H'1E, H'21, H'25, H'2C, H'33, H'34, H'34, H'34, H'34, H'34, H'37, H'3A, H'3C, H'3C, H'3C, H'3C, H'3C
            .DATA.B  H'1D, H'1E, H'1E, H'1E, H'1E, H'21, H'25, H'2C, H'2E, H'32, H'32, H'32, H'32, H'32, H'34, H'36, H'38, H'3A, H'3A, H'3A, H'3A
            .DATA.B  H'1B, H'1C, H'1E, H'1E, H'1E, H'21, H'25, H'28, H'28, H'2B, H'2E, H'2F, H'2F, H'30, H'30, H'31, H'32, H'34, H'34, H'34, H'34
            .DATA.B  H'16, H'17, H'19, H'1B, H'1D, H'1F, H'22, H'24, H'27, H'29, H'2B, H'2C, H'2D, H'2E, H'2D, H'2E, H'2F, H'34, H'34, H'34, H'34
            .DATA.B  H'0D, H'0E, H'13, H'15, H'17, H'1A, H'1D, H'1E, H'23, H'25, H'28, H'2B, H'2B, H'2B, H'2A, H'2B, H'2D, H'33, H'33, H'33, H'33
            .DATA.B  H'0C, H'0D, H'12, H'14, H'16, H'19, H'1C, H'1E, H'22, H'23, H'26, H'29, H'29, H'29, H'28, H'28, H'2B, H'32, H'32, H'32, H'32
            .DATA.B  H'0C, H'0D, H'12, H'14, H'16, H'18, H'1A, H'1C, H'22, H'22, H'25, H'28, H'28, H'28, H'27, H'27, H'2A, H'31, H'31, H'31, H'31
            .DATA.B  H'0A, H'0B, H'10, H'12, H'14, H'16, H'18, H'1A, H'1E, H'1E, H'21, H'26, H'26, H'26, H'25, H'25, H'28, H'2F, H'2F, H'2F, H'2F
            .DATA.B  H'0A, H'0A, H'0D, H'0F, H'11, H'13, H'15, H'18, H'18, H'1A, H'1D, H'22, H'22, H'22, H'21, H'21, H'24, H'2C, H'2C, H'2C, H'2C
	.AENDI	

hiIgnMapRAM .EQU _hiIgnMapData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	.AIFDEF DEF_VEMAP16
	
			.align 4
			
veMap:                    
			.DATA.W 	3
			.DATA.W 	0                                                  
			.DATA.L 	_axis_ve_RPM
			.DATA.L 	_axis_ve_LOAD
			.DATA.W 	19
veMapData:                    
            .DATA.W  H'5831, H'5831, H'5A3D, H'5E14, H'57AE, H'8810, H'81EC, H'7D0E, H'749C, H'9106, H'7C08, H'6CEE, H'84FE, H'951F, H'97F0, H'951F, H'7C08, H'7000, H'63F8
            .DATA.W  H'5A3D, H'5A3D, H'5A3D, H'64BC, H'670A, H'8BE7, H'75A2, H'82F2, H'8DF4, H'88D5, H'9C8B, H'76E9, H'8AE1, H'98F6, H'A0E5, H'9B02, H'8A1D, H'7D0E, H'7000
            .DATA.W  H'5CCD, H'647B, H'670A, H'64BC, H'6F7D, H'878D, H'8BE7, H'7FDF, H'7AC1, H'951F, H'9E98, H'924E, H'9106, H'9D0E, H'AA1D, H'A2F2, H'97F0, H'8A1D, H'7C08
            .DATA.W  H'63F8, H'6EB8, H'7148, H'6BA6, H'77F0, H'9042, H'972B, H'8333, H'84BC, H'97F0, H'9F5C, H'8CAC, H'928F, H'A3F8, H'B20C, H'ADF4, H'A1EC, H'96E9, H'8BE7
            .DATA.W  H'73D7, H'73D7, H'7666, H'7B85, H'80A4, H'945A, H'9B02, H'8C29, H'9189, H'A127, H'A78D, H'9083, H'A0E5, H'AAE1, H'B8F6, H'B312, H'A70A, H'9D0E, H'9312
            .DATA.W  H'7666, H'7666, H'7979, H'8127, H'8917, H'9AC1, H'A2F2, H'8E77, H'9D91, H'AAA0, H'A852, H'A958, H'AC6A, H'B5E3, H'C1EC, H'BE98, H'AEFA, H'A4FE, H'9B02
            .DATA.W  H'78B4, H'78B4, H'7C8B, H'853F, H'A127, H'A127, H'AA5E, H'9BC7, H'A333, H'B3D7, H'A917, H'AA5E, H'B3D7, H'B2D1, H'C4FE, H'BF1B, H'B5E3, H'A917, H'9C08
            .DATA.W  H'7B44, H'7B44, H'7F9E, H'8917, H'A47B, H'A78D, H'AA5E, H'A375, H'A917, H'B979, H'B666, H'B042, H'BB44, H'C021, H'C604, H'C2F2, H'B8F6, H'ABE7, H'9F1B
            .DATA.W  H'7DD3, H'7DD3, H'82B0, H'8D2F, H'B4DD, H'A78D, H'AA5E, H'AB23, H'AEB8, H'BF5C, H'BE98, H'BB02, H'BB44, H'BE56, H'C810, H'C4FE, H'C168, H'AEFA, H'A3F8
            .DATA.W  H'8021, H'8021, H'82B0, H'8D2F, H'B4DD, H'A78D, H'AA5E, H'AB23, H'B45A, H'C4FE, H'C687, H'CCEE, H'BB44, H'BE56, H'C810, H'C70A, H'C168, H'AEFA, H'A3F8
            .DATA.W  H'82B0, H'82B0, H'82B0, H'8D2F, H'B4DD, H'A78D, H'AA5E, H'AB23, H'B45A, H'C4FE, H'C687, H'CCEE, H'BB44, H'BE56, H'C810, H'C70A, H'C168, H'AEFA, H'A3F8
            
	.AELSE
	
			.align 4
			.DATA.W		H'FFFF
			
veMap:                    
			.DATA.W 	H'300                                                   
			.DATA.L 	_axis_ve_RPM
			.DATA.L 	_axis_ve_LOAD
			.DATA.B 	19
veMapData:                    
            .DATA.B  H'58, H'58, H'5A, H'5E, H'57, H'88, H'81, H'7D, H'74, H'91, H'7C, H'6C, H'84, H'95, H'97, H'95, H'7C, H'70, H'63
            .DATA.B  H'5A, H'5A, H'5A, H'64, H'67, H'8B, H'75, H'82, H'8D, H'88, H'9C, H'76, H'8A, H'98, H'A0, H'9B, H'8A, H'7D, H'70
            .DATA.B  H'5C, H'64, H'67, H'64, H'6F, H'87, H'8B, H'7F, H'7A, H'95, H'9E, H'92, H'91, H'9D, H'AA, H'A2, H'97, H'8A, H'7C
            .DATA.B  H'63, H'6E, H'71, H'6B, H'77, H'90, H'97, H'83, H'84, H'97, H'9F, H'8C, H'92, H'A3, H'B2, H'AD, H'A1, H'96, H'8B
            .DATA.B  H'73, H'73, H'76, H'7B, H'80, H'94, H'9B, H'8C, H'91, H'A1, H'A7, H'90, H'A0, H'AA, H'B8, H'B3, H'A7, H'9D, H'93
            .DATA.B  H'76, H'76, H'79, H'81, H'89, H'9A, H'A2, H'8E, H'9D, H'AA, H'A8, H'A9, H'AC, H'B5, H'C1, H'BE, H'AE, H'A4, H'9B
            .DATA.B  H'78, H'78, H'7C, H'85, H'A1, H'A1, H'AA, H'9B, H'A3, H'B3, H'A9, H'AA, H'B3, H'B2, H'C4, H'BF, H'B5, H'A9, H'9C
            .DATA.B  H'7B, H'7B, H'7F, H'89, H'A4, H'A7, H'AA, H'A3, H'A9, H'B9, H'B6, H'B0, H'BB, H'C0, H'C6, H'C2, H'B8, H'AB, H'9F
            .DATA.B  H'7D, H'7D, H'82, H'8D, H'B4, H'A7, H'AA, H'AB, H'AE, H'BF, H'BE, H'BB, H'BB, H'BE, H'C8, H'C4, H'C1, H'AE, H'A3
            .DATA.B  H'80, H'80, H'82, H'8D, H'B4, H'A7, H'AA, H'AB, H'B4, H'C4, H'C6, H'CC, H'BB, H'BE, H'C8, H'C7, H'C1, H'AE, H'A3
            .DATA.B  H'82, H'82, H'82, H'8D, H'B4, H'A7, H'AA, H'AB, H'B4, H'C4, H'C6, H'CC, H'BB, H'BE, H'C8, H'C7, H'C1, H'AE, H'A3
				  
	.AENDI
				  
veMapRAM .EQU veMapData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.align 2
			
rpmTimeData:                    
            .DATAB.W  21, 0
			
rpmTimeRAM .EQU rpmTimeData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF DEF_ENRICH_COOL_AIR_MAPS


			.align 4

			.DATA.W		H'FFFF
			
enrichCoolantMap:           

			.DATA.B 2                                                    
			.DATA.B 0                   
                                                                            
            .DATA.L axisIndex_10_CoolTempSc
            
enrichCoolantMapData:
            
            .DATA.B  189, 178, 169, 166, 158, 141, 137, 133, 128, 128

enrichCoolantMapRAM		.EQU enrichCoolantMap + RAM - ROM
enrichCoolantMapDataRAM .EQU enrichCoolantMapData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.EXPORT	_kAirMap
	
			.align 4

_kAirMap:
			.DATA.W 	3
			.DATA.W 	0                                                  
			.DATA.L 	_axis_fu_RPM
			.DATA.L 	axisIndex_7_InAirTemp
			.DATA.W 	14
kAirMapData:
			.DATA.W 	H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
			.DATA.W 	H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
			.DATA.W 	H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
			.DATA.W 	H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
			.DATA.W 	H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
			.DATA.W 	H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
			.DATA.W 	H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
						
kAirMapRAM		.EQU _kAirMap + RAM - ROM
kAirMapDataRAM	.EQU kAirMapData + RAM - ROM

	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.EXPORT	_trimVeMap
	
			.align 4
			
_trimVeMap:                    

			.DATA.W 	3
			.DATA.W 	0                                                  
			.DATA.L 	_axis_ve_RPM
			.DATA.L 	_axis_ve_LOAD
			.DATA.W 	19
trimVeMapData:                    
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            .DATA.W  H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000, H'8000
            
trimVeMapRAM		.EQU _trimVeMap + RAM - ROM
trimVeMapDataRAM	.EQU trimVeMapData + RAM - ROM

	.AENDI

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.EXPORT		_hiFuelMapRAM, _hiIgnMapRAM, _veMapRAM, _rpmTimeRAM

	.SECTION    sec_hiFuelMapRAM,	DATA, LOCATE=hiFuelMapRAM
	
_hiFuelMapRAM:		.RES.B      1
	
	.SECTION    sec_hiIgnMapRAM,	DATA, LOCATE=hiIgnMapRAM

_hiIgnMapRAM:		.RES.B      1

	.SECTION    sec_veMapRAM,		DATA, LOCATE=veMapRAM

_veMapRAM:			.RES.B      1

	.SECTION    sec_rpmTimeRAM,		DATA, LOCATE=rpmTimeRAM

_rpmTimeRAM:		.RES.B      1


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF DEF_ENRICH_COOL_AIR_MAPS
	
	.EXPORT		_enrichCoolantMapRAM, _kAirMapRAM, _enrichCoolantMapDataRAM, _kAirMapDataRAM, _trimVeMapRAM, _trimVeMapDataRAM

	.SECTION    sec_enrichCoolantMapRAM, DATA, LOCATE=enrichCoolantMapRAM

_enrichCoolantMapRAM:		.RES.w      5
							.RES.B      1
_enrichCoolantMapDataRAM:	.RES.B      1

	.SECTION    sec_kAirMapRAM,		DATA, LOCATE=kAirMapRAM

_kAirMapRAM:		.RES.w      5
					.RES.B      1
_kAirMapDataRAM:	.RES.B      1

	.SECTION    sec_trimVeMapRAM,		DATA, LOCATE=trimVeMapRAM

_trimVeMapRAM:		.RES.w      5
					.RES.B      1
_trimVeMapDataRAM:	.RES.B      1

	.AENDI
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;ROM:0001421A 00C     mov.l   #HIGHOKTF_7A88, r4                                      ; Move Immediate Long Data
;ROM:0001421C 00C     mov.l   #Query_byte_2D_3D_Table, r10                            ; Move Immediate Long Data
;ROM:0001421E 00C     jsr     @r10 ; Query_byte_2D_3D_Table                           ; Jump to Subroutine
;ROM:00014220 00C     nop                                                             ; No Operation

	.SECTION C_7A88, DATA, LOCATE=H'7A88

	.EXPORT		_HIGHOKTF_7A88

_HIGHOKTF_7A88:

		.DATA.L		hiFuelMap                                    
		.DATA.L		hiFuelMap                                    
		.DATA.L		hiFuelMap                                    
		.DATA.L		hiFuelMap                                    
		.DATA.L		hiFuelMap                                    
		.DATA.L		hiFuelMap                                    
		.DATA.L		hiFuelMap                                    
		.DATA.L		hiFuelMap + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;ROM:0001810C 010 		mov.l   #HighIgn_7C48, r4                                       ; Move Immediate Long Data
;ROM:0001810E 010 		mov.l   #Query_byte_2D_3D_Table, r10                            ; Move Immediate Long Data
;ROM:00018110 010 		jsr     @r10 ; Query_byte_2D_3D_Table                           ; Jump to Subroutine
;ROM:00018112 010 		nop                                                             ; No Operation

	.SECTION C_7C48, DATA, LOCATE=H'7C48

	.EXPORT		_HighIgn_7C48

_HighIgn_7C48:									;.EQU	H'7C48

		.DATA.L		hiIgnMap                                    
		.DATA.L		hiIgnMap                                    
		.DATA.L		hiIgnMap                                    
		.DATA.L		hiIgnMap                                    
		.DATA.L		hiIgnMap                                    
		.DATA.L		hiIgnMap                                    
		.DATA.L		hiIgnMap                                    
		.DATA.L		hiIgnMap + RAM - ROM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION P, CODE, ALIGN=4		; LOCATE=H'7C48

	.EXPORT		_veMapArray

_veMapArray:

		.DATA.L		veMap                                    
		.DATA.L		veMap                                    
		.DATA.L		veMap                                    
		.DATA.L		veMap                                    
		.DATA.L		veMap                                    
		.DATA.L		veMap                                    
		.DATA.L		veMap                                    
		.DATA.L		veMap + RAM - ROM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;TEST_INTERPOLATE:	.DEFINE		"1"

	.AIFDEF TEST_INTERPOLATE

	.SECTION P_D7A, CODE, LOCATE=H'D7A
;	.SECTION P, CODE

	.EXPORT	_Interpolate_my

; R0 = R4 + ((R5 - R4) * R6 + 127) / 255; R6 = [0 ... 255]
	
_Interpolate_my:                                                                                    
                                                                                                
								extu.w  r6, r6                                                  
								mov		#-1, r0                                               
								extu.w  r5, r5
								extu.b	r0, r0
								cmp/hs  r0, r6                                                 
								bf      loc_D9C

								rts
								mov     r5, r0                                                 

loc_D9C:                                                                                        
								extu.w  r4, r4  

								add		#2, r0		; r0 = 257      

								sub     r4, r5

								mulu    r6, r0  
								shll	r6
								sts     macl, r0	; r0 = r6*257

								shlr8	r6
								add		r6, r0

								shll16	r4

								mov		#64, r6		;mov.l	#32768, r6
								
								mul.l	r5, r0	
								
								shll	r6
								
								sts     macl, r0   
								
								shll8	r6

								add		r4, r0
								add		r6, r0

								rts                                                             
								shlr16  r0  

 ;                               .DATAB.W 19, H'FFFF                                                            

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	.SECTION P_B16, CODE, LOCATE=H'B16
;	.SECTION P, CODE

	.EXPORT	_interpolate_r4_r5_r6_my
	
; R0 = R5 + (R4*R6 - R5*R6) / 255; R6 = [0 ... 255]

; R0 = R5 + (R4 - R5) * (R6 * 257 + 1) / 65536; R6 = [0 ... 255]

_interpolate_r4_r5_r6_my:                                                                           
                                                                                                
								extu.w  r6, r6                                                  
								mov		#-1, r0                                               
								extu.w  r5, r5
								extu.b	r0, r0
								cmp/hs  r0, r6                                                 
								bf      loc_B26

								rts
								mov     r4, r0                                                 

loc_B26:                                                                                        
								extu.w  r4, r4  

								add		#2, r0		; r0 = 257      

								sub     r5, r4

								mulu    r6, r0  
								shll	r6
								sts     macl, r0	; r0 = r6*257

								shlr8	r6
								add		r6, r0

								shll16	r5

								mov		#64, r6		;mov.l	#32768, r6
								
								mul.l	r4, r0	
								
								shll	r6
								
								sts     macl, r0   
								
								shll8	r6

								add		r5, r0
;								add		r6, r0

								rts                                                             
								shlr16  r0  

;                                .DATAB.W 19, H'FFFF                                                            

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;	.IMPORT	_Test_Interpolate
	
;	.SECTION C_9CC8, DATA, LOCATE=H'9CC8

;		.DATA.L		_Test_Interpolate                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AENDI
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;TEST_INTERPOLATE:	.DEFINE		"1"

	.AIFDEF TEST_MEM_DECR

	.SECTION P_53E_mem_decr, CODE, LOCATE=H'53E

mem_decr:                                                                                       
                                mov.l   r0, @-r15                                               

                                stc     sr, r0                                                  
                                mov.l   r0, @-r15                                               
                                or      #h'F0, r0                                               
                                
                                bra		loc_mem_decr_558
                                ldc     r0, sr     
loc_mem_decr_540:                        
                                mov.w   @r4, r0                                                 
                                extu.w  r0, r0                                                  
                                cmp/eq  #0, r0                                                  
                                bt      loc_mem_decr_558                                                 

                                add     #-1, r0                                                 
                                mov.w   r0, @r4                                                 
loc_mem_decr_558:                                                                                        
                                add     #2, r4                                                  
                                cmp/hs  r5, r4                                                  
                                bf      loc_mem_decr_540    
                                                                          
                                ldc.l   @r15+, sr                                               

; ---------------------------------------------------------------------------

locret_55E:                                                                                     
                                rts                                                             
                                mov.l   @r15+, r0                                               

; End of function mem_decr

	.AENDI

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.END
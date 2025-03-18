
	.INCLUDE "cpp\def.inc"

DEF_ENRICH_COOL_AIR_MAPS:	.DEFINE		"1"
TEST_INTERPOLATE:			.DEFINE		"1"
;DEF_NO_KNOCK_RETARD:		.DEFINE		"1"

;DEF_SIMULATION:				.DEFINE		"1"

;DEF_VEMAP16:				.DEFINE		"1"
;DEF_IGNMAP16:				.DEFINE		"1"

;DEF_IGNITION_HOOKS:			.DEFINE		"1"
;DEF_FU03_HOOKS:			.DEFINE		"1"
;DEF_IDLE_HOOKS:				.DEFINE		"1"

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF	DEF_SIMULATION

;Simulation test 

	.SECTION SIM_P_B3A0, CODE, LOCATE=H'B3A0

			nop   	                                                        

	.SECTION SIM_P_B426, CODE, LOCATE=H'B426

			nop   	                                                        

	.SECTION SIM_P_BB50, CODE, LOCATE=H'BB50

			nop   	                                                        

	.SECTION SIM_P_BF1C, CODE, LOCATE=H'BF1C

			nop   	                                                        

	.SECTION SIM_P_BF4C, CODE, LOCATE=H'BF4C

			nop   	                                                        

	.SECTION SIM_P_BF7C, CODE, LOCATE=H'BF7C

			nop  

	.SECTION SIM_P_BE60, CODE, LOCATE=H'BE60

			nop  

	.SECTION SIM_P_BE8A, CODE, LOCATE=H'BE90

			nop  
			
	.SECTION    SIM_C_FAA, DATA, LOCATE=H'FAA

			.DATA.W      H'56C2

	.SECTION    SIM_C_FCA, DATA, LOCATE=H'FCA

			.DATA.W      H'81F7

		.AIFDEF	DEF_HARDWARE
		
		.AELSE
		
			.SECTION SIM_P_B2B6, CODE, LOCATE=H'B2B6

				.IMPORT	_GetADC_hook

				mov.l	#_GetADC_hook, r0                           
				jmp   	@r0                                                             
				nop   	
				
		.AENDI
			
			
	.AENDI 	                                                        

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    B_ALTMAPS, DATA, LOCATE=H'FFFF8420
	
	.EXPORT		_hiIgnMapIndex, _hiFuelMapIndex, _veMapIndex, _fixAFR, _openLoop, _forcedIdleRPM, _disableTrims, _no_knock_retard
	
_hiIgnMapIndex:		.RES.B      1					
_hiFuelMapIndex:	.RES.B      1					
_veMapIndex:		.RES.B      1					
_fixAFR:			.RES.B      1					
_openLoop:			.RES.B      1					
_forcedIdleRPM:		.RES.B      1					
_disableTrims:		.RES.B      1					
_no_knock_retard:	.RES.B      1					

	.ALIGN 2	
	
	.EXPORT		_axis_ig_RPM, _axis_ig_LOAD, _axis_fu_RPM, _axis_fu_LOAD, _axis_ve_RPM, _axis_ve_LOAD, _ve_index, _fb_VE, _ve_timer, _timeRPM
	.EXPORT		_knock_mul_low, _knock_mul_high

_axis_ig_RPM:		.RES.W      1					
_axis_ig_LOAD:		.RES.W      1					
_axis_fu_RPM:		.RES.W      1					
_axis_fu_LOAD:		.RES.W      1					
_axis_ve_RPM:		.RES.W      1					
_axis_ve_LOAD:		.RES.W      1					
_fb_VE				.RES.B      1					
_ve_index:			.RES.B      1					
_ve_timer:			.RES.B      1					
_timeRPM:			.RES.W      1					
_knock_mul_low:		.RES.W      1					
_knock_mul_high:	.RES.W      1					

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    B_ALTMAPS_LIM, DATA, LOCATE=H'FFFF8500
	
					.RES.B		1
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    HOOKS_C_2CC0_2FFF_LIM, DATA, LOCATE=H'2FFF

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
transaxle_state								.EQU	H'FFFF8A3C

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	.SECTION    B_FFFF851C,DATA, LOCATE=H'FFFF851C

	.EXPORT		_frameCount

_frameCount:		.RES.L      1					;	.EQU H'FFFF8462

;	.SECTION C_F0D4, DATA, LOCATE=H'F0D4

;	.DATA.L		_frameCount                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF DEF_IGNITION_HOOKS
	
	.IMPORT	_IG04_Update_OctanEgrIgnTiming

	.SECTION HOOKS_P_1801E, CODE, LOCATE=H'1801E
	
			mov.l	#_IG04_Update_OctanEgrIgnTiming, r0                           
			jmp   	@r0                                                             
			nop   	                                                        
			
	.AENDI

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

	.AIFDEF DEF_CRANK

	.AELSE
	
		.SECTION ALTMAPS_C_24208, DATA, LOCATE=H'24208

			.DATA.L		_knock_mul_high                                    
			.DATA.L		_knock_mul_low                                    

	.AENDI

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF DEF_FU03_sub_149E0_Hook
	
	.SECTION HOOKS_P_35500, CODE, LOCATE=H'35500
	
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

	.AIFDEF	DEF_FU03_HOOKS

	.IMPORT	_FU03_HI_LO_Octan

	.SECTION HOOKS_P_141C8, CODE, LOCATE=H'141C8

			mov.l	#_FU03_HI_LO_Octan, r0                           
			jmp   	@r0                                                             
			nop   	                                                        
	

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.IMPORT	_FU03_VE_map_sub_14620

	.SECTION HOOKS_P_14620, CODE, LOCATE=H'14620
	
			mov.l	#_FU03_VE_map_sub_14620, r0                           
			jmp   	@r0                                                             
			nop   	                                                        

	.AENDI

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF	DEF_IDLE_HOOKS

	.IMPORT	_Hook_ForcedIdleRPM

	.SECTION HOOKS_C_19454, CODE, LOCATE=H'19454
	
		.DATA.L		_Hook_ForcedIdleRPM                                    

	.AENDI
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	.AIFDEF DEF_FU03_sub_149E0_Hook
	
	.IMPORT	_FU03_sub_149E0_Hook

	.SECTION HOOKS_P_149E0, CODE, LOCATE=H'149E0
	
			mov.l	#_FU03_sub_149E0_Hook, r0                           
			jmp   	@r0                                                             
			nop  
			
	.AENDI        

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;	.IMPORT	_Hook_Update_IAT_Sensor

;	.SECTION HOOKS_C_100DC, CODE, LOCATE=H'100DC
	
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

	.SECTION ALTMAPS_C_6746, DATA, LOCATE=H'6748

		.DATA.W		_axis_fu_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C_676C, DATA, LOCATE=H'676C

		.DATA.L		_axis_fu_LOAD                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C_5380, DATA, LOCATE=H'5380

		.DATA.L		_axis_fu_LOAD                                    
		.DATA.L		_axis_fu_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C_540A, DATA, LOCATE=H'540C

		.DATA.W		_axis_ig_LOAD 
		.DATA.W		H'FFFF                                   
		.DATA.W		_axis_ig_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C_6788, DATA, LOCATE=H'6788

		.DATA.L		_axis_ig_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C_67BC, DATA, LOCATE=H'67BC

		.DATA.L		_axis_ig_LOAD                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C_6CEE, DATA, LOCATE=H'6CEE

		.DATA.W		H'FFFF                                   
		.DATA.W		_axis_ve_RPM                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C_6D1E, DATA, LOCATE=H'6D1E

		.DATA.W		H'FFFF                                   
		.DATA.W		_axis_ve_LOAD                                    

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C_MUT, DATA, LOCATE=H'1400
	
			.align 4

altMUT:		
			.DATA.L		wMUT1C_ECU_Load+1
			.DATA.L		MUT21_RPM_x125div4+1                                    
			.DATA.L		wMUT26_Knock_Retard+1                                   
			.DATA.L		wMUT06_Timing_Advance+1                                 
			.DATA.L		wMUT3A_AirTemp_ADC8bit+1
			.DATA.L		wMUT10_Coolant_Temperature_Scaled+1
			.DATA.L		wMUT3C_Rear_O2_ADC8bit+1
			.DATA.L		transaxle_state                   
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
			.DATA.L		wMUT25_Target_Idle_Steps+1
			.DATA.L		wMUT24_Target_Idle_RPM+1
			.DATA.L		wMUT04_Timing_Advance_Interpolated+1
			.DATA.L		wMUT33_Corrected_Timing_Advance+1
			.DATA.L		octanEgrIgnTiming+1
			.DATA.L		wMUT9A_Ligths_Bit_Array+1
			
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION ALTMAPS_C, DATA, LOCATE=H'38000
	
	.EXPORT	 ROM

			.align 4
ROM:

			.DATA.W		H'FFFF

hiFuelMap:
			.DATA.W 	H'300                                                   
			.DATA.L 	_axis_fu_RPM
			.DATA.L 	_axis_fu_LOAD
			.DATA.B 	14
hiFuelMapData:	;RPM	750		1000	1250	1500	1750	2000	3000	3500	4000	5000	5500	6000	6500	7000	;Load (kPa)
			.DATA.B 	134,	128,	128,	128,	128,	128,	128,	128,	128,	126,	126,	126,	126,	126		;22
			.DATA.B 	134,	128,	128,	128,	128,	128,	128,	128,	128,	130,	132,	138,	140,	142		;35
			.DATA.B 	134,	128,	128,	128,	128,	128,	128,	129,	130,	135,	139,	139,	141,	143		;49
			.DATA.B 	134,	128,	128,	128,	128,	128,	133,	133,	138,	143,	143,	143,	145,	147		;62
			.DATA.B 	134,	134,	134,	134,	134,	134,	145,	149,	149,	149,	149,	149,	149,	149		;75
			.DATA.B 	139,	139,	139,	139,	139,	139,	147,	149,	149,	149,	149,	149,	149,	149		;89
			.DATA.B 	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149		;96
			.DATA.B 	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149		;102
			.DATA.B 	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149,	149		;116
																																		
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
_hiIgnMapData: ;RPM		0		500		750		898		1000	1148	1250	1500	1750	2000	2500	3000	3500	4000	4500	5000	5500	6000	6500	7000	11000	;Load (kPa)
			.DATA.W		H'1C00,	H'1D00,	H'1D00,	H'1D00,	H'1D00,	H'2000,	H'2400,	H'2B00,	H'3400,	H'3500,	H'3500,	H'3500,	H'3600,	H'3700,	H'3900,	H'3A00,	H'3B00,	H'3B00,	H'3B00,	H'3B00,	H'3B00	;0
			.DATA.W		H'1D00,	H'1E00,	H'1E00,	H'1E00,	H'1E00,	H'2100,	H'2400,	H'2400,	H'2400,	H'2400,	H'2500,	H'2600,	H'2700,	H'2500,	H'2700,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800	;22
			.DATA.W		H'1D00,	H'1E00,	H'1E00,	H'1E00,	H'1E00,	H'2100,	H'2400,	H'2400,	H'2400,	H'2400,	H'2500,	H'2600,	H'2700,	H'2500,	H'2700,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800	;28
			.DATA.W		H'1D00,	H'1E00,	H'1E00,	H'1E00,	H'1E00,	H'2100,	H'2400,	H'2400,	H'2400,	H'2400,	H'2500,	H'2600,	H'2700,	H'2500,	H'2700,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800	;35
			.DATA.W		H'1C00,	H'1D00,	H'1E00,	H'1E00,	H'1E00,	H'2100,	H'2400,	H'2400,	H'2400,	H'2400,	H'2500,	H'2600,	H'2700,	H'2500,	H'2700,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800	;49
			.DATA.W		H'1B00,	H'1C00,	H'1E00,	H'1E00,	H'1E00,	H'2100,	H'2500,	H'2800,	H'2800,	H'2400,	H'2600,	H'2800,	H'2700,	H'2500,	H'2700,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800,	H'2800	;62
			.DATA.W		H'1600,	H'1700,	H'1900,	H'1B00,	H'1D00,	H'1F00,	H'2200,	H'2400,	H'2700,	H'2400,	H'2600,	H'2B00,	H'2B00,	H'2C00,	H'2C00,	H'2C00,	H'2D00,	H'2D00,	H'2E00,	H'2E00,	H'2E00	;75
			.DATA.W		H'0D00,	H'0E00,	H'1300,	H'1500,	H'1700,	H'1A00,	H'1D00,	H'1E00,	H'2300,	H'2500,	H'2800,	H'2B00,	H'2B00,	H'2B00,	H'2A00,	H'2B00,	H'2D00,	H'3300,	H'3300,	H'3300,	H'3300	;89
			.DATA.W		H'0C00,	H'0D00,	H'1200,	H'1400,	H'1600,	H'1900,	H'1C00,	H'1E00,	H'2200,	H'2300,	H'2600,	H'2900,	H'2900,	H'2900,	H'2800,	H'2800,	H'2B00,	H'3200,	H'3200,	H'3200,	H'3200	;96
			.DATA.W		H'0C00,	H'0D00,	H'1200,	H'1400,	H'1600,	H'1800,	H'1A00,	H'1C00,	H'2200,	H'2200,	H'2500,	H'2800,	H'2800,	H'2800,	H'2700,	H'2700,	H'2A00,	H'3100,	H'3100,	H'3100,	H'3100	;102
			.DATA.W		H'0A00,	H'0B00,	H'1000,	H'1200,	H'1400,	H'1600,	H'1800,	H'1A00,	H'2000,	H'2000,	H'2300,	H'2600,	H'2600,	H'2600,	H'2500,	H'2500,	H'2800,	H'2F00,	H'2F00,	H'2F00,	H'2F00	;109
			.DATA.W		H'0A00,	H'0A00,	H'0D00,	H'0F00,	H'1100,	H'1300,	H'1500,	H'1800,	H'1D00,	H'1D00,	H'1F00,	H'2200,	H'2200,	H'2200,	H'2100,	H'2100,	H'2400,	H'2C00,	H'2C00,	H'2C00,	H'2C00	;128

	.AELSE
	
			.align 4
			.DATA.W		H'FFFF
			
hiIgnMap:
			.DATA.W 	H'300                                                   
			.DATA.L 	_axis_ig_RPM
			.DATA.L 	_axis_ig_LOAD
			.DATA.B 	21
_hiIgnMapData: ;RPM		0		500		750		898		1000	1148	1250	1500	1750	2000	2500	3000	3500	4000	4500	5000	5500	6000	6500	7000	11000	;Load (kPa)
			.DATA.B		H'1C,	H'1D,	H'1D,	H'1D,	H'1D,	H'20,	H'24,	H'2B,	H'34,	H'35,	H'35,	H'35,	H'36,	H'37,	H'39,	H'3A,	H'3B,	H'3B,	H'3B,	H'3B,	H'3B	;0
			.DATA.B		H'1D,	H'1E,	H'1E,	H'1E,	H'1E,	H'21,	H'24,	H'24,	H'24,	H'24,	H'25,	H'26,	H'27,	H'25,	H'27,	H'28,	H'28,	H'28,	H'28,	H'28,	H'28	;22
			.DATA.B		H'1D,	H'1E,	H'1E,	H'1E,	H'1E,	H'21,	H'24,	H'24,	H'24,	H'24,	H'25,	H'26,	H'27,	H'25,	H'27,	H'28,	H'28,	H'28,	H'28,	H'28,	H'28	;28
			.DATA.B		H'1D,	H'1E,	H'1E,	H'1E,	H'1E,	H'21,	H'24,	H'24,	H'24,	H'24,	H'25,	H'26,	H'27,	H'25,	H'27,	H'28,	H'28,	H'28,	H'28,	H'28,	H'28	;35
			.DATA.B		H'1C,	H'1D,	H'1E,	H'1E,	H'1E,	H'21,	H'24,	H'24,	H'24,	H'24,	H'25,	H'26,	H'27,	H'25,	H'27,	H'28,	H'28,	H'28,	H'28,	H'28,	H'28	;49
			.DATA.B		H'1B,	H'1C,	H'1E,	H'1E,	H'1E,	H'21,	H'25,	H'28,	H'28,	H'24,	H'26,	H'28,	H'27,	H'25,	H'27,	H'28,	H'28,	H'28,	H'28,	H'28,	H'28	;62
			.DATA.B		H'16,	H'17,	H'19,	H'1B,	H'1D,	H'1F,	H'22,	H'24,	H'27,	H'24,	H'26,	H'2B,	H'2B,	H'2C,	H'2C,	H'2C,	H'2D,	H'2D,	H'2E,	H'2E,	H'2E	;75
			.DATA.B		H'0D,	H'0E,	H'13,	H'15,	H'17,	H'1A,	H'1D,	H'1E,	H'23,	H'25,	H'28,	H'2B,	H'2B,	H'2B,	H'2A,	H'2B,	H'2D,	H'33,	H'33,	H'33,	H'33	;89
			.DATA.B		H'0C,	H'0D,	H'12,	H'14,	H'16,	H'19,	H'1C,	H'1E,	H'22,	H'23,	H'26,	H'29,	H'29,	H'29,	H'28,	H'28,	H'2B,	H'32,	H'32,	H'32,	H'32	;96
			.DATA.B		H'0C,	H'0D,	H'12,	H'14,	H'16,	H'18,	H'1A,	H'1C,	H'22,	H'22,	H'25,	H'28,	H'28,	H'28,	H'27,	H'27,	H'2A,	H'31,	H'31,	H'31,	H'31	;102
			.DATA.B		H'0A,	H'0B,	H'10,	H'12,	H'14,	H'16,	H'18,	H'1A,	H'20,	H'20,	H'23,	H'26,	H'26,	H'26,	H'25,	H'25,	H'28,	H'2F,	H'2F,	H'2F,	H'2F	;109
			.DATA.B		H'0A,	H'0A,	H'0D,	H'0F,	H'11,	H'13,	H'15,	H'18,	H'1D,	H'1D,	H'1F,	H'22,	H'22,	H'22,	H'21,	H'21,	H'24,	H'2C,	H'2C,	H'2C,	H'2C	;128
 			
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
veMapData:  ;	RPM		500		750		1000	1250	1500	1750	2000	2250	2500	2750	3000	3500	4000	4500	5000	5500	6000	6500	7000	;Load (kPa)
			.DATA.W  	H'5810,	H'67EF,	H'7020,	H'7A1C,	H'73F7,	H'7810,	H'8418,	H'7BE7,	H'6E14,	H'7A1C,	H'820C,	H'93F7,	H'A8F5,	H'A000,	H'9810,	H'8418,	H'7A1C,	H'6E14,	H'69FB	;22
			.DATA.W  	H'67EF,	H'7604,	H'820C,	H'7BE7,	H'7AE1,	H'7CED,	H'8C08,	H'85E3,	H'7A1C,	H'820C,	H'89FB,	H'9BE7,	H'B3F7,	H'AB02,	H'A5E3,	H'8E14,	H'7CED,	H'7020,	H'66E9	;28
			.DATA.W  	H'68F5,	H'7810,	H'86E9,	H'85E3,	H'851E,	H'8312,	H'92F1,	H'8FDF,	H'820C,	H'87EF,	H'8C08,	H'A5E3,	H'B916,	H'B916,	H'B1EB,	H'9916,	H'851E,	H'770A,	H'68F5	;35
			.DATA.W  	H'73F7,	H'8000,	H'8C08,	H'89FB,	H'89FB,	H'87EF,	H'970A,	H'9604,	H'87EF,	H'8E14,	H'93F7,	H'AC08,	H'C20C,	H'C106,	H'BBE7,	H'A20C,	H'8B02,	H'7A1C,	H'68F5	;42
			.DATA.W  	H'7604,	H'820C,	H'8FDF,	H'8E14,	H'8F1A,	H'8F1A,	H'9AE1,	H'9AE1,	H'91EB,	H'93F7,	H'9BE7,	H'B1EB,	H'C8F5,	H'C6E9,	H'BEF9,	H'A5E3,	H'93F7,	H'8000,	H'6C08	;49
			.DATA.W  	H'8418,	H'8C08,	H'93F7,	H'94FD,	H'9916,	H'970A,	H'A106,	H'A20C,	H'9A1C,	H'9A1C,	H'A312,	H'B604,	H'CD0E,	H'CD0E,	H'C8F5,	H'B3F7,	H'9AE1,	H'85E3,	H'70E5	;62
			.DATA.W  	H'8C08,	H'91EB,	H'9810,	H'9A1C,	H'9DF3,	H'9A1C,	H'B687,	H'B4FD,	H'BA5E,	H'C041,	H'BD2F,	H'C560,	H'D3B6,	H'D2F1,	H'C8B4,	H'B604,	H'9DF3,	H'8C08,	H'7A1C	;76
			.DATA.W  	H'92F1,	H'92F1,	H'9916,	H'9CED,	H'9EF9,	H'9A1C,	H'B687,	H'B4FD,	H'BA5E,	H'C041,	H'BD2F,	H'C560,	H'D3B6,	H'D2F1,	H'C8B4,	H'BA1C,	H'A106,	H'8D0E,	H'7A1C	;89
			.DATA.W  	H'94FD,	H'94FD,	H'9AE1,	H'9DF3,	H'A106,	H'9A1C,	H'B687,	H'B4FD,	H'BA5E,	H'C041,	H'BD2F,	H'C560,	H'D3B6,	H'D2F1,	H'C8B4,	H'BBE7,	H'A20C,	H'90E5,	H'8000	;96
			.DATA.W  	H'94FD,	H'94FD,	H'9AE1,	H'9DF3,	H'A106,	H'9A1C,	H'B687,	H'B4FD,	H'BA5E,	H'C041,	H'BD2F,	H'C560,	H'D3B6,	H'D2F1,	H'C8B4,	H'BEF9,	H'A20C,	H'90E5,	H'8000	;103
			.DATA.W  	H'94FD,	H'94FD,	H'9AE1,	H'9DF3,	H'A106,	H'9A1C,	H'B687,	H'B4FD,	H'BA5E,	H'C041,	H'BD2F,	H'C560,	H'D3B6,	H'D2F1,	H'C8B4,	H'BEF9,	H'A20C,	H'90E5,	H'8000	;116
            
	.AELSE
	
			.align 4
			.DATA.W		H'FFFF
			
veMap:                    
			.DATA.W 	H'300                                                   
			.DATA.L 	_axis_ve_RPM
			.DATA.L 	_axis_ve_LOAD
			.DATA.B 	19
veMapData:  ;	RPM		500		750		1000	1250	1500	1750	2000	2250	2500	2750	3000	3500	4000	4500	5000	5500	6000	6500	7000	;Load (kPa)
			.DATA.B 	H'58,	H'67,	H'70,	H'7A,	H'73,	H'78,	H'84,	H'7B,	H'6E,	H'7A,	H'82,	H'93,	H'A8,	H'A0,	H'98,	H'84,	H'7A,	H'6E,	H'69	;22
			.DATA.B 	H'67,	H'76,	H'82,	H'7B,	H'7A,	H'7C,	H'8C,	H'85,	H'7A,	H'82,	H'89,	H'9B,	H'B3,	H'AB,	H'A5,	H'8E,	H'7C,	H'70,	H'66	;28
			.DATA.B 	H'68,	H'78,	H'86,	H'85,	H'85,	H'83,	H'92,	H'8F,	H'82,	H'87,	H'8C,	H'A5,	H'B9,	H'B9,	H'B1,	H'99,	H'85,	H'77,	H'68	;35
			.DATA.B 	H'73,	H'80,	H'8C,	H'89,	H'89,	H'87,	H'97,	H'96,	H'87,	H'8E,	H'93,	H'AC,	H'C2,	H'C1,	H'BB,	H'A2,	H'8B,	H'7A,	H'68	;42
			.DATA.B 	H'76,	H'82,	H'8F,	H'8E,	H'8F,	H'8F,	H'9A,	H'9A,	H'91,	H'93,	H'9B,	H'B1,	H'C8,	H'C6,	H'BE,	H'A5,	H'93,	H'80,	H'6C	;49
			.DATA.B 	H'84,	H'8C,	H'93,	H'94,	H'99,	H'97,	H'A1,	H'A2,	H'9A,	H'9A,	H'A3,	H'B6,	H'CD,	H'CD,	H'C8,	H'B3,	H'9A,	H'85,	H'70	;62
			.DATA.B 	H'8C,	H'91,	H'98,	H'9A,	H'9D,	H'9A,	H'B6,	H'B4,	H'BA,	H'C0,	H'BD,	H'C5,	H'D3,	H'D2,	H'C8,	H'B6,	H'9D,	H'8C,	H'7A	;76
			.DATA.B 	H'92,	H'92,	H'99,	H'9C,	H'9E,	H'9A,	H'B6,	H'B4,	H'BA,	H'C0,	H'BD,	H'C5,	H'D3,	H'D2,	H'C8,	H'BA,	H'A1,	H'8D,	H'7A	;89
			.DATA.B 	H'94,	H'94,	H'9A,	H'9D,	H'A1,	H'9A,	H'B6,	H'B4,	H'BA,	H'C0,	H'BD,	H'C5,	H'D3,	H'D2,	H'C8,	H'BB,	H'A2,	H'90,	H'80	;96
			.DATA.B 	H'94,	H'94,	H'9A,	H'9D,	H'A1,	H'9A,	H'B6,	H'B4,	H'BA,	H'C0,	H'BD,	H'C5,	H'D3,	H'D2,	H'C8,	H'BE,	H'A2,	H'90,	H'80	;103
			.DATA.B 	H'94,	H'94,	H'9A,	H'9D,	H'A1,	H'9A,	H'B6,	H'B4,	H'BA,	H'C0,	H'BD,	H'C5,	H'D3,	H'D2,	H'C8,	H'BE,	H'A2,	H'90,	H'80	;116
				  
	.AENDI
				  
veMapRAM .EQU veMapData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.align 2
			
rpmTimeData:                    
            .DATAB.W  21, 0
			
rpmTimeRAM .EQU rpmTimeData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF DEF_ENRICH_COOL_AIR_MAPS

	.EXPORT	_kAirMap
	
			.align 4
			
			.DATA.W		H'FFFF

_kAirMap:
			.DATA.B 	3
			.DATA.B 	0                                                  
			.DATA.L 	_axis_fu_RPM
			.DATA.L 	axisIndex_7_InAirTemp
			.DATA.B 	14
kAirMapData:
			.DATA.B 	H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80
			.DATA.B 	H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80
			.DATA.B 	H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80
			.DATA.B 	H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80
			.DATA.B 	H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80
			.DATA.B 	H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80
			.DATA.B 	H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80, H'80
						
kAirMapRAM		.EQU _kAirMap + RAM - ROM
kAirMapDataRAM	.EQU kAirMapData + RAM - ROM


	.AENDI

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.EXPORT		_hiFuelMapRAM, _hiIgnMapRAM, _veMapRAM, _rpmTimeRAM

	.SECTION    ALTMAPS_hiFuelMapRAM,	DATA, LOCATE=hiFuelMapRAM
	
_hiFuelMapRAM:		.RES.B      1
	
	.SECTION    ALTMAPS_hiIgnMapRAM,	DATA, LOCATE=hiIgnMapRAM

_hiIgnMapRAM:		.RES.B      1

	.SECTION    ALTMAPS_veMapRAM,		DATA, LOCATE=veMapRAM

_veMapRAM:			.RES.B      1

	.SECTION    ALTMAPS_rpmTimeRAM,		DATA, LOCATE=rpmTimeRAM

_rpmTimeRAM:		.RES.B      1


;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.AIFDEF DEF_ENRICH_COOL_AIR_MAPS
	
	.EXPORT		_kAirMapRAM, _kAirMapDataRAM

	.SECTION    ALTMAPS_kAirMapRAM,		DATA, LOCATE=kAirMapRAM

_kAirMapRAM:		.RES.w      5
					.RES.B      1
_kAirMapDataRAM:	.RES.B      1

	.AENDI
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;ROM:0001421A 00C     mov.l   #HIGHOKTF_7A88, r4                                      ; Move Immediate Long Data
;ROM:0001421C 00C     mov.l   #Query_byte_2D_3D_Table, r10                            ; Move Immediate Long Data
;ROM:0001421E 00C     jsr     @r10 ; Query_byte_2D_3D_Table                           ; Jump to Subroutine
;ROM:00014220 00C     nop                                                             ; No Operation

	.SECTION ALTMAPS_C_7A88, DATA, LOCATE=H'7A88

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

	.SECTION ALTMAPS_C_7C48, DATA, LOCATE=H'7C48

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

	.SECTION TEST_INTERPOLATE_P_D7A, CODE, LOCATE=H'D7A

	.EXPORT	_Interpolate_my

; R0 = R4 + ((R5 - R4) * R6 + 127) / 255; R6 = [0 ... 255]
	
_Interpolate_my:                                                                                    
                                                                                                
								extu.w  r6, r6                                                  
								mov		#-1, r0                                               
								extu.w  r5, r5
								extu.b	r0, r0
								cmp/hs  r0, r6                                                 
								bf      ?0001

								rts
								mov     r5, r0                                                 

?0001:                                                                                        
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


	.SECTION TEST_INTERPOLATE_P_B16, CODE, LOCATE=H'B16

	.EXPORT	_interpolate_r4_r5_r6_my
	
; R0 = R5 + (R4*R6 - R5*R6) / 255; R6 = [0 ... 255]

; R0 = R5 + (R4 - R5) * (R6 * 257 + 1) / 65536; R6 = [0 ... 255]

_interpolate_r4_r5_r6_my:                                                                           
                                                                                                
								extu.w  r6, r6                                                  
								mov		#-1, r0                                               
								extu.w  r5, r5
								extu.b	r0, r0
								cmp/hs  r0, r6                                                 
								bf      ?0001

								rts
								mov     r4, r0                                                 

?0001:                                                                      
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
	
;	.SECTION TEST_INTERPOLATE_C_9CC8, DATA, LOCATE=H'9CC8

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
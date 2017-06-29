
	.INCLUDE "cpp\def.inc"

	.SECTION    B_ALTMAPS, DATA, LOCATE=H'FFFF8278
	
	.EXPORT		_hiIgnMapIndex, _hiFuelMapIndex, _veMapIndex, _fixAFR, _openLoop, _veFeedBackO2R
	
_hiIgnMapIndex:		.RES.B      1					
_hiFuelMapIndex:	.RES.B      1					
_veMapIndex:		.RES.B      1					
_fixAFR:			.RES.B      1					
_openLoop:			.RES.B      1					
_veFeedBackO2R:		.RES.B      1					

	.ALIGN 2	
	
	.EXPORT		_axis_ig_RPM, _axis_ig_LOAD, _axis_fu_RPM, _axis_fu_LOAD, _axis_ve_RPM, _axis_ve_LOAD

_axis_ig_RPM:		.RES.W      1					
_axis_ig_LOAD:		.RES.W      1					
_axis_fu_RPM:		.RES.W      1					
_axis_fu_LOAD:		.RES.W      1					
_axis_ve_RPM:		.RES.W      1					
_axis_ve_LOAD:		.RES.W      1					

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    B_ALTMAPS_LIM, DATA, LOCATE=H'FFFF82A0
	
					.RES.B		1
	
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.SECTION    C_2CC0_2FFF_LIM, DATA, LOCATE=H'2FFF

					.DATA.B      H'FF

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

IG04_GetLoadCorrectedDeltaTPS					.EQU	H'181DC
RPM21_6788_IGN									.EQU	H'6788
Table_Lookup_Axis								.EQU	H'CC6
LOAD12_67BC_IGN									.EQU	H'67BC
RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888		.EQU	H'FFFF8888
LowIgn_7C68										.EQU	H'7C68
Query_byte_2D_3D_Table							.EQU	H'DE0
LOWOCTIGNEGR_7AC8								.EQU	H'7AC8
ZERO_8_IGNITION_FLAGS							.EQU	H'FFFF8A0C
HIOCTIGNEGR_38CA								.EQU	H'38CA
Add_R4w_R5w_Lim_FFFF							.EQU	H'500
egrLowOctIgn									.EQU	H'FFFF8BC0
egrHighOctIgn									.EQU	H'FFFF8BC2
interpolate_r4_r5_r6							.EQU	H'B16
octanEgrIgnTiming								.EQU	H'FFFF8BC8
Sub_R4w_R5w_liml_0								.EQU	H'F0C
Lim_R4_max_FF									.EQU	H'590
ignition_FFFF8BC4								.EQU	H'FFFF8BC4

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	.SECTION    B_FFFF851C,DATA, LOCATE=H'FFFF851C

	.EXPORT		_frameCount

_frameCount:		.RES.L      1					;	.EQU H'FFFF8462

	.SECTION C_F0D4, DATA, LOCATE=H'F0D4

	.DATA.L		_frameCount                                    

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

	.IMPORT	_FU03_HI_LO_Octan

	.SECTION P_141C8, CODE, LOCATE=H'141C8

			mov.l	#_FU03_HI_LO_Octan, r0                           
			jmp   	@r0                                                             
			nop   	                                                        
	

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.IMPORT	_FU03_VE_map_sub_14620

	.SECTION P_14620, CODE, LOCATE=H'14620
	
			mov.l	#_FU03_VE_map_sub_14620, r0                           
			jmp   	@r0                                                             
			nop   	                                                        
	

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
			.DATA.L		wMUT1A_Manifold_AbsPressure_ADC8bit+1                   
			.DATA.L		wMUT17_TPS_ADC8bit+1
			.DATA.L		wMUT2A_Injector_Pulse_Width_us                          
			.DATA.L		wMUT27_Octane_Number+1
			.DATA.L		wMUT33_Corrected_Timing_Advance+1
			.DATA.L		wMUT32_Air_To_Fuel_Ratio+1
			.DATA.L		wMUT2F_Vehicle_Speed+1  
			.DATA.L		wMUT0C_Fuel_Trim_Low+1
			.DATA.L		wMUT0F_Oxygen_Feedback_Trim+1
			.DATA.L		_axis_fu_RPM+1
			.DATA.L		_axis_fu_LOAD+1
			.DATA.L		_axis_ve_RPM+1
			.DATA.L		_axis_ve_LOAD+1
			
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

			.align 4

hiIgnMap:
			.DATA.W 	3                                                  
			.DATA.W 	0                                                  
			.DATA.L 	_axis_ig_RPM
			.DATA.L 	_axis_ig_LOAD
			.DATA.W 	21
hiIgnMapData:
            .DATA.W  H'1C00, H'1D00, H'1D00, H'1D00, H'1D00, H'2000, H'2400, H'2B00, H'3400, H'3500, H'3500, H'3500, H'3600, H'3700, H'3900, H'3A00, H'3B00, H'3B00, H'3B00, H'3B00, H'3B00
            .DATA.W  H'1D00, H'1E00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2C00, H'3500, H'3600, H'3600, H'3600, H'3600, H'3700, H'3900, H'3B00, H'3C00, H'3C00, H'3C00, H'3C00, H'3C00
            .DATA.W  H'1D00, H'1E00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2C00, H'3500, H'3600, H'3600, H'3700, H'3700, H'3700, H'3800, H'3A00, H'3D00, H'3D00, H'3D00, H'3D00, H'3C00
            .DATA.W  H'1D00, H'1E00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2C00, H'3300, H'3400, H'3400, H'3400, H'3400, H'3400, H'3700, H'3A00, H'3C00, H'3C00, H'3C00, H'3C00, H'3C00
            .DATA.W  H'1D00, H'1E00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2C00, H'2E00, H'3200, H'3200, H'3200, H'3200, H'3200, H'3400, H'3600, H'3800, H'3A00, H'3A00, H'3A00, H'3A00
            .DATA.W  H'1B00, H'1C00, H'1E00, H'1E00, H'1E00, H'2100, H'2500, H'2800, H'2800, H'2B00, H'2E00, H'2F00, H'2F00, H'3000, H'3000, H'3100, H'3200, H'3400, H'3400, H'3400, H'3400
            .DATA.W  H'1600, H'1700, H'1900, H'1B00, H'1D00, H'1F00, H'2200, H'2400, H'2700, H'2900, H'2B00, H'2C00, H'2D00, H'2E00, H'2D00, H'2E00, H'2F00, H'3400, H'3400, H'3400, H'3400
            .DATA.W   H'D00,  H'E00, H'1300, H'1500, H'1700, H'1A00, H'1D00, H'1E00, H'2300, H'2500, H'2800, H'2B00, H'2B00, H'2B00, H'2A00, H'2B00, H'2D00, H'3300, H'3300, H'3300, H'3300
            .DATA.W   H'C00,  H'D00, H'1200, H'1400, H'1600, H'1900, H'1C00, H'1E00, H'2200, H'2300, H'2600, H'2900, H'2900, H'2900, H'2800, H'2800, H'2B00, H'3200, H'3200, H'3200, H'3200
            .DATA.W   H'C00,  H'D00, H'1200, H'1400, H'1600, H'1800, H'1A00, H'1C00, H'2200, H'2200, H'2500, H'2800, H'2800, H'2800, H'2700, H'2700, H'2A00, H'3100, H'3100, H'3100, H'3100
            .DATA.W   H'A00,  H'B00, H'1000, H'1200, H'1400, H'1600, H'1800, H'1A00, H'2000, H'2000, H'2300, H'2600, H'2600, H'2600, H'2500, H'2500, H'2800, H'2F00, H'2F00, H'2F00, H'2F00
            .DATA.W   H'A00,  H'A00,  H'D00,  H'F00, H'1100, H'1300, H'1500, H'1800, H'1D00, H'1D00, H'1F00, H'2200, H'2200, H'2200, H'2100, H'2100, H'2400, H'2C00, H'2C00, H'2C00, H'2C00

hiIgnMapRAM .EQU hiIgnMapData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			.align 4
			
veMap:                    
			.DATA.W 	3
			.DATA.W 	0                                                  
			.DATA.L 	_axis_ve_RPM
			.DATA.L 	_axis_ve_LOAD
			.DATA.W 	19
veMapData:                    
			.DATA.W  H'5800, H'6800, H'7000, H'7A00, H'7400, H'7800, H'8400, H'7C00, H'6E00, H'7A00, H'8200, H'9400, H'A900, H'A000, H'9800, H'8400, H'7A00, H'6E00, H'6A00
			.DATA.W  H'6800, H'7600, H'8200, H'7C00, H'7B00, H'7D00, H'8C00, H'8600, H'7A00, H'8200, H'8A00, H'9C00, H'B400, H'AB00, H'A600, H'8E00, H'7D00, H'7000, H'6700
			.DATA.W  H'6900, H'7800, H'8700, H'8600, H'8500, H'8300, H'9300, H'9000, H'8200, H'8800, H'8C00, H'A600, H'B900, H'B900, H'B200, H'9900, H'8500, H'7700, H'6900
			.DATA.W  H'7400, H'8000, H'8C00, H'8A00, H'8A00, H'8800, H'9700, H'9600, H'8800, H'8E00, H'9400, H'AC00, H'C200, H'C100, H'BC00, H'A200, H'8B00, H'7A00, H'6900
			.DATA.W  H'7600, H'8200, H'9000, H'8E00, H'8F00, H'8F00, H'9B00, H'9B00, H'9200, H'9400, H'9C00, H'B200, H'C900, H'C700, H'BF00, H'A600, H'9400, H'8000, H'6C00
			.DATA.W  H'8400, H'8C00, H'9400, H'9500, H'9900, H'9700, H'A100, H'A200, H'9A00, H'9A00, H'A300, H'B600, H'CD00, H'CD00, H'C900, H'B400, H'9B00, H'8600, H'7100
			.DATA.W  H'8C00, H'9200, H'9800, H'9A00, H'9E00, H'9A00, H'A400, H'A600, H'9F00, H'9D00, H'A500, H'B900, H'CE00, H'D000, H'CE00, H'B600, H'9E00, H'8C00, H'7A00
			.DATA.W  H'9300, H'9300, H'9900, H'9D00, H'9F00, H'9A00, H'A400, H'A700, H'A100, H'A100, H'A900, H'BE00, H'CF00, H'D200, H'CE00, H'BA00, H'A100, H'8D00, H'7A00
			.DATA.W  H'9500, H'9500, H'9B00, H'9E00, H'A100, H'9A00, H'A400, H'A900, H'A600, H'A800, H'AC00, H'BE00, H'D000, H'D200, H'D100, H'BC00, H'A200, H'9100, H'8000
			.DATA.W  H'9500, H'9500, H'9B00, H'9E00, H'A100, H'9A00, H'A400, H'AD00, H'BA00, H'BC00, H'B000, H'BE00, H'D000, H'D200, H'D500, H'BF00, H'A200, H'9100, H'8000
			.DATA.W  H'9500, H'9500, H'9B00, H'9E00, H'A100, H'9A00, H'A400, H'AD00, H'BA00, H'BC00, H'B000, H'BE00, H'D000, H'D200, H'D500, H'BF00, H'A200, H'9100, H'8000
				  
veMapRAM .EQU veMapData + RAM - ROM

;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	.EXPORT		_hiFuelMapRAM, _hiIgnMapRAM, _veMapRAM

	.SECTION    sec_hiFuelMapRAM,	DATA, LOCATE=hiFuelMapRAM
	
_hiFuelMapRAM:		.RES.B      1
	
	.SECTION    sec_hiIgnMapRAM,	DATA, LOCATE=hiIgnMapRAM

_hiIgnMapRAM:		.RES.W      1

	.SECTION    sec_veMapRAM,		DATA, LOCATE=veMapRAM

_veMapRAM:			.RES.B      1

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

	.END
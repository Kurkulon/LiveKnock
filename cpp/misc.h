#ifndef MISC_H__26_04_2016__22_59
#define MISC_H__26_04_2016__22_59

#include "types.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma pack 4

struct IndexResult
{
	byte interpolator;
	byte index;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Axis
{
	IndexResult	*result; 
	u16			*value;

	u16 		len;
	i16 		data[2];
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Map3D_B
{
	byte type; // 2 - 2D, 3 - 3D
	byte add;

	u16 ptrRowIndHi;
	u16 ptrRowIndLo;

	union
	{
		struct
		{
			i8 data[8];
		} m2d;

		struct
		{
			u16 ptrColIndHi;
			u16 ptrColIndLo;

			byte rowLen;

			i8 data[3];
		} m3d;
	};
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Map3D_W
{
	u16 type; // 2 - 2D, 3 - 3D
	u16	add;

	u16 ptrRowIndHi;
	u16 ptrRowIndLo;
	u16 ptrColIndHi;
	u16 ptrColIndLo;

	u16 rowLen;

	i16 data[4];
};

#pragma unpack

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define CRANKING				0x01 
#define MAP_error				0x02
#define DECELERATION_FUEL_CUT	0x04
#define FUEL_CUT				0x08
#define STALL					0x10
#define CLOSED_LOOP_GENERIC		0x80

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define Tephra ((void(*)(void))0x3ec00)
#define sub_A98A ((void(*)(void))0xA98A)

#define Table_Lookup_byte_2D_3D ((u16(*)(Map3D_B*))0xC28)
#define Table_Lookup_word_2D_3D ((u32(*)(Map3D_W*))0xE02)


//#define IG04_GetLoadCorrectedDeltaTPS					((u16(*)(void))0x181DC)
#define Table_Lookup_Axis								((void(*)(Axis*))0xCC6)
#define Query_byte_2D_3D_Table							((u32(*)(Map3D_B**))0xDE0)

#define GET_FROM_MASSIVE_byte							((u32(*)(const byte*))0xDC6)
#define GET_LOC_DIM_sub_DF6								((u32(*)(void*))0xDF6)


#define Lim_R4_max_FF									((u32(*)(u16))0x590)
#define sub_21E14										((u16(*)(u16))0x21E14)

#define Add_R4w_R5w_Lim_FFFF							((u32(*)(u16,u16))0x500)
#define Sub_R4w_R5w_liml_0								((u32(*)(u16,u16))0xF0C)
#define R4_Mul_R5_Div_256_round							((u32(*)(u16,u16))0x804)
#define Div_R4_R5_R0									((u16(*)(u16,u16))0x9B0)
#define Mul_R4w_R5w_Div_128_Round_Into_R0				((u32(*)(u16,u16))0x762)

#define interpolate_r4_r5_r6							((u16(*)(u16,u16,u16))0xB16)
#define Lim16_R4w__R5_R6								((u32(*)(u16,u16,u16))0x5A8)
#define MUL_R4w_R5w_DIV_R6w_Round_R0					((u32(*)(u16,u16,u16))0x68A)

#define FU03_sub_142DC									((u16(*)(void))0x142DC)

#define __disable_irq									((void(*)(void))0x400)
#define __enable_irq									((void(*)(void))0x41e)

#define Timer_Counter_Related_sub_C928					((void(*)(void))0xC928)
#define Knock_Output_Calc_sub_AC96						((void(*)(void))0xAC96)

#define sub_21E84										((bool(*)(void))0x21E84)
#define BC06_sub_1E2D0									((void(*)(void))0x1E2D0)
	

//#pragma address wMUT26_Knock_Sum=0xFFFF8C32
//static u16 wMUT26_Knock_Sum;

//#define wMUTB4_lookup_value								(*(u16*)0xFFFF8836)
//#define RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888		(*(u16*)0xFFFF8888)
//#define RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_COPY_FFFF888A	(*(u16*)0xFFFF888A)
//#define INTAKE_AIR_TEMPERATURE_COPY_FFFF88BA			(*(u16*)0xFFFF88BA)
//#define ZERO_8_IGNITION_FLAGS							(*(u16*)0xFFFF8A0C)
//#define egrLowOctIgn									(*(u16*)0xFFFF8BC0)
//#define egrHighOctIgn									(*(u16*)0xFFFF8BC2)
//#define octanEgrIgnTiming								(*(u16*)0xFFFF8BC8)
//#define ignition_FFFF8BC4								(*(u16*)0xFFFF8BC4)
//#define abs_Delta_TPS									(*(u16*)0xFFFF8BE2)
#define TPS_Multiplier_Delta							(*(u16*)0x17A4)
//#define load_x2_deltaTPS_corrected						(*(u16*)0xFFFF8BDA)
//#define ECU_Load_x2_FFFF895C							(*(u16*)0xFFFF895C)
//#define RPM_DELTA_FFFF8948								(*(u16*)0xFFFF8948)
//#define timingAdvScaled									(*(u16*)0xFFFF8BE0)

//#define ignCoilTime_3									(*(u16*)0xFFFF8C0E)
//#define ignCoilTime_1									(*(u16*)0xFFFF8C10)
//#define ignCoilTime_Fin									(*(u16*)0xFFFF8C12)
//#define crankHT_x_4us_3									(*(u16*)0xFFFF8F04)
//#define max_Knock_Retard								(*(u16*)0xFFFF8C42)
//#define word_FFFF8BCA									(*(u16*)0xFFFF8BCA)
//#define coolantTempScld_COPY_1							(*(u16*)0xFFFF88B0)
//#define rpm_x125div32_B									(*(u16*)0xFFFF893A)

//#define RPM_x_4_096__1									(*(u16*)0xFFFF894A)
//#define RPM_x_4_096__2									(*(u16*)0xFFFF894C)
//#define RPM_x_4_096__3									(*(u16*)0xFFFF894E)


#define RPM21_6788_IGN									((Axis*)0x6788)
#define LOAD12_67BC_IGN									((Axis*)0x67BC)
#define LowIgn_7C68										((Map3D_B**)0x7C68)
#define LOWOCTIGNEGR_7AC8								((Map3D_B**)0x7AC8)
#define HIOCTIGNEGR_38CA								((Map3D_B*)0x38CA)
#define table_2D_39D2									((Map3D_B*)0x39D2)


extern Map3D_W* HighIgn_7C48[8];		//#define HighIgn_7C48	((void*)0x7C48)

#define RPM14_6746										((Axis*)0x6746)
#define LOAD9_676C										((Axis*)0x676C)
#define LowOctFMp_7AA8									((Map3D_B**)0x7AA8)

extern Map3D_B* HIGHOKTF_7A88[8];		//#define HIGHOKTF_7A88	((void*)0x7A88)
extern Map3D_B* veMapArray[8];		

#define AFR_OctanInt									(*(u16*)0xFFFF8ACA)

#define RPM19_6CEE										((Axis*)0x6CEE)
#define LOAD11_6D1E										((Axis*)0x6D1E)
//#define bMUTD3_BitMap4_FCA_Store_FFFF89D8				(*(u16*)0xFFFF89D8)
#define EGRONOFF_103D									(*(const byte*)0x103D)
#define VE1Map_3032										((Map3D_B*)0x3032)
#define VE2Map_310E										((Map3D_B*)0x310E)
#define VE3Map_31EA										((Map3D_B*)0x31EA)

#define sub_21BC4										((u16(*)(u16))0x21BC4)
#define sub_21E4C										((u16(*)(u16))0x21E4C)




//#define	MUT20_RPM_Idle_x125div16 									(*(u16*)0xFFFF8942) 
//#define	MUT21_RPM_x125div4 											(*(u16*)0xFFFF8944) 
//#define	MUTB4_672E 													(*(u16*)0x0000672E) 
//#define MUTD3_faults 												(*(u16*)0xFFFF80E4) 
//#define MUT_00_01_FLAGS 											(*(u16*)0xFFFF8886) 
//#define	MUT_03_FLAGS 												(*(u16*)0xFFFF888E) 
//#define MUT_2B 														(*(u16*)0xFFFF9996) 
//#define	wMUT04_Timing_Advance_Interpolated 							(*(u16*)0xFFFF8BBC) 
//#define wMUT05_Timing_Advance_Scaled 								(*(u16*)0xFFFF8BDE) 
//#define wMUT06_Timing_Advance 										(*(u16*)0xFFFF8BDC) 
//#define wMUT07_CoolTemp_ADC8bit 									(*(u16*)0xFFFF88A4) 
//#define wMUT09 														(*(u16*)0xFFFF8C9C) 
//#define wMUT0B 														(*(u16*)0xFFFF8C9E) 
//#define wMUT0C_Fuel_Trim_Low 										(*(u16*)0xFFFF8088) 
//#define wMUT0D_Fuel_Trim_Middle 									(*(u16*)0xFFFF808A) 
//#define wMUT0E_Fuel_Trim_High 										(*(u16*)0xFFFF808C) 
//#define wMUT0F_Oxygen_Feedback_Trim 								(*(u16*)0xFFFF8A70) 
//#define wMUT10_Coolant_Temperature_Scaled 							(*(u16*)0xFFFF88AA) 
//#define	wMUT11_Intake_Air_Temperature_Scaled 						(*(u16*)0xFFFF88B6) 
//#define	wMUT12_Coolant_Temperature_Min_81 							(*(u16*)0xFFFF88AC) 
//#define	wMUT13_Front_O2_ADC8bit 									(*(u16*)0xFFFF88BC) 
//#define wMUT14_Battery_Level_ADC8bit 								(*(u16*)0xFFFF88E6) 
//#define wMUT15_Barometric_Pressure 									(*(u16*)0xFFFF88DC) 
//#define	wMUT16_ISC_Steps 											(*(u16*)0xFFFF80CA) 
//#define wMUT17_TPS_ADC8bit 											(*(u16*)0xFFFF88E8) 
//#define	wMUT18_Open_Loop_Bit_Array 									(*(u16*)0xFFFF8A02) 
//#define wMUT19_Startup_Check_Bits 									(*(u16*)0xFFFF89FC) 
//#define wMUT1A_Manifold_AbsPressure_ADC8bit 						(*(u16*)0xFFFF88D8) 
//#define wMUT1B_TPS_Idle_Adder 										(*(u16*)0xFFFF8022) 
//#define wMUT1C_ECU_Load 											(*(u16*)0xFFFF8952) 
//#define wMUT1D_Manifold_Absolute_Pressure_Mean 						(*(u16*)0xFFFF8968) 
//#define wMUT1E_MAF_RESET_FLAG 										(*(u16*)0xFFFF89F4) 
//#define wMUT1F_ECU_Load_Previous 									(*(u16*)0xFFFF8954) 
//#define wMUT22 														(*(u16*)0xFFFF80C6) 
//#define wMUT23 														(*(u16*)0xFFFF8C92) 
//#define wMUT24_Target_Idle_RPM 										(*(u16*)0xFFFF8CA2) 
//#define	wMUT25_Idle_Stepper_Value 									(*(u16*)0xFFFF8CAC) 
//#define	wMUT26_Knock_Retard 										(*(u16*)0xFFFF8C32) 
//#define wMUT26_Knock_Sum											(*(u16*)0xFFFF8C32)
//#define	wMUT27_Octane_Number 										(*(u16*)0xFFFF80B8) 
//#define wMUT2A_Injector_Pulse_Width_us 								(*(u16*)0xFFFF9994) 
//#define wMUT2D_Ignition_Battery_Trim 								(*(u16*)0xFFFF9982) 
//#define	wMUT2E_Vehicle_Speed_Frequency 								(*(u16*)0xFFFF89C6) 
//#define wMUT2F_Vehicle_Speed 										(*(u16*)0xFFFF89C8) 
//#define	wMUT30_Knock_Voltage 										(*(u16*)0xFFFF8908) 
//#define wMUT31_Volumetric_Efficiency 								(*(u16*)0xFFFF8AB8) 
//#define wMUT32_Air_To_Fuel_Ratio 									(*(u16*)0xFFFF8AC6) 
//#define wMUT33_Corrected_Timing_Advance 							(*(u16*)0xFFFF8BBE) 
//#define wMUT34_Map_Index 											(*(u16*)0xFFFF89E0) 
//#define wMUT35_Limp_Home_Fuel_Throttle_Position_Based 				(*(u16*)0xFFFF8B04) 
//#define wMUT36_Active_Fault_Count 									(*(u16*)0xFFFF80EA) 
//#define wMUT37_Stored_Fault_Count 									(*(u16*)0xFFFF80EE) 
//#define wMUT38_Manifold_DiffPressure_ADC8bit 						(*(u16*)0xFFFF890A) 
//#define wMUT39_Fuel_Tank_Pressure_ADC8bit 							(*(u16*)0xFFFF890C) 
//#define wMUT3A_AirTemp_ADC8bit 										(*(u16*)0xFFFF88B2) 
//#define	wMUT3B_Masked_Map_Index 									(*(u16*)0xFFFF8906) 
//#define	wMUT3C_Rear_O2_ADC8bit 										(*(u16*)0xFFFF88C0) 
//#define	wMUT3F_Short_Term_Fuel_Feedback_Trim_O2_Map_Index 			(*(u16*)0xFFFF8EF6) 
//#define wMUT40_Stored_Faults_Lo 									(*(u16*)0xFFFF80CE) 
//#define wMUT41_Stored_Faults_Hi 									(*(u16*)0xFFFF80D0) 
//#define	wMUT42_Stored_Faults_Lo_1 									(*(u16*)0xFFFF80D2) 
//#define wMUT43_Stored_Faults_Hi_1 									(*(u16*)0xFFFF80D4) 
//#define	wMUT44_Stored_Faults_Lo_2 									(*(u16*)0xFFFF80D6) 
//#define wMUT45_Stored_Faults_Lo_3 									(*(u16*)0xFFFF80DA) 
//#define wMUT46_Stored_Faults_Hi_3 									(*(u16*)0xFFFF80DC) 
//#define wMUT47_Active_Fault_Lo 										(*(u16*)0xFFFF80DE) 
//#define wMUT48_Active_Faults_Hi 									(*(u16*)0xFFFF80E0) 
//#define wMUT49_faults 												(*(u16*)0xFFFF80E2) 
//#define wMUT4A_Purge_Control_Duty 									(*(u16*)0xFFFF8D22) 
//#define wMUT4B 														(*(u16*)0xFFFF8AC8) 
//#define wMUT4C_Fuel_Trim_Low_Bank_2 								(*(u16*)0xFFFF809E) 
//#define wMUT4D_Fuel_Trim_Mid_Bank_2 								(*(u16*)0xFFFF80A0) 
//#define wMUT4E_Fuel_Trim_High_Bank_2 								(*(u16*)0xFFFF80A2) 
//#define	wMUT4F_Oxygen_Feedback_Trim_Bank_2 							(*(u16*)0xFFFF8A72) 
//#define	wMUT50_Long_Fuel_Trim_Bank_1 								(*(u16*)0xFFFF8A80) 
//#define	wMUT50_Long_Fuel_Trim_Bank_1_COPY 							(*(u16*)0xFFFF8A82) 
//#define wMUT51_Long_Fuel_Trim_Bank_2 								(*(u16*)0xFFFF8A84) 
//#define wMUT51_Long_Fuel_Trim_Bank_2_COPY 							(*(u16*)0xFFFF8A86) 
//#define	wMUT52 														(*(u16*)0xFFFF8A88) 
//#define wMUT52_COPY 												(*(u16*)0xFFFF8A8A) 
//#define	wMUT53 														(*(u16*)0xFFFF8A8C) 
//#define wMUT56_MAX_MAP_FALL_CHANGE 									(*(u16*)0xFFFF89A0) 
//#define wMUT57_MAX_MAP_RISE_CHANGE 									(*(u16*)0xFFFF89A4) 
//#define wMUT58_AFR_CT_Adder 										(*(u16*)0xFFFF8EF8) 
//#define wMUT59 														(*(u16*)0xFFFF8A04) 
//#define wMUT5A 														(*(u16*)0xFFFF8A18) 
//#define wMUT5B_Rear_02_Voltage 										(*(u16*)0xFFFF8A1A) 
//#define wMUT5C_ADC_Rear_02_Voltage 									(*(u16*)0xFFFF88CC) 
//#define wMUT5E_FUEL_CUT_FLAG 										(*(u16*)0xFFFF8A30) 
//#define wMUT5F 														(*(u16*)0xFFFF8A32) 
//#define wMUT66 														(*(u16*)0xFFFF8A28) 
//#define	wMUT67 														(*(u16*)0xFFFF8A2A) 
//#define	wMUT6A_Knock_ADC_Processed 									(*(u16*)0xFFFF8C38) 
//#define	wMUT6B_Knock_Base 											(*(u16*)0xFFFF998A) 
//#define wMUT6C_Knock_Sum_Addition 									(*(u16*)0xFFFF9986) 
//#define wMUT6D_Knock_Change 										(*(u16*)0xFFFF998C) 
//#define	wMUT6E_Knock_Dynamics 										(*(u16*)0xFFFF8C46) 
//#define wMUT6F_Knock_Acceleration 									(*(u16*)0xFFFF85B6) 
//#define	wMUT70_Array_of_Serial_Receive_Data_Register_2_RDR2_Values 	(*(u16*)0xFFFF8D96) 
//#define wMUT71_Sensor_Error 										(*(u16*)0xFFFF89E2) 
//#define wMUT72_Knock_Present 										(*(u16*)0xFFFF89E6) 
//#define wMUT73_TPS_Open_Delta 										(*(u16*)0xFFFF88F8) 
//#define wMUT74_TPS_Close_Delta 										(*(u16*)0xFFFF88FC) 
//#define wMUT75 														(*(u16*)0xFFFF8CA6) 
//#define wMUT76_Idle_Stepper_Y_Axis 									(*(u16*)0xFFFF8CAE) 
//#define wMUT77 														(*(u16*)0xFFFF8D6C) 
//#define wMUT78 														(*(u16*)0xFFFF8D6A) 
//#define wMUT79_Injector_Latency 									(*(u16*)0xFFFF8AF8) 
//#define wMUT7A_Continuous_Monitor_Completion_Status_1 				(*(u16*)0xFFFF9258) 
//#define	wMUT7B_Continuous_Monitor_Completion_Status_2 				(*(u16*)0xFFFF925C) 
//#define	wMUT7C_Continuous_Monitor_Completion_Status_3 				(*(u16*)0xFFFF9260) 
//#define	wMUT7D_Non_Continuous_Monitor_Completion_Status_OBD 		(*(u16*)0xFFFF9264) 
//#define wMUT7E_Continuous_Monitor_Completion_Status_Low_4 			(*(u16*)0xFFFF9268) 
//#define wMUT7F_Continuous_Monitor_Completion_Status_High_4 			(*(u16*)0xFFFF926A) 
//#define	wMUT80_ECU_ID_Type 											(*(u16*)0xFFFF8EFA) 
//#define wMUT82_ECU_ID_Version 										(*(u16*)0xFFFF8EFC) 
//#define	wMUT83_ADC_15_8bit 											(*(u16*)0xFFFF8928) 
//#define wMUT84_Thermo_Fan_Duty 										(*(u16*)0xFFFF8D64) 
//#define wMUT85_EGR_Solenoid 										(*(u16*)0xFFFF8D08) 
//#define wMUT86_Waste_Gate_Duty_Cycle 								(*(u16*)0xFFFF8D0C) 
//#define wMUT87_Fuel_Temp_ADC8bit 									(*(u16*)0xFFFF8910) 
//#define wMUT88_Fuel_Level_ADC8bit 									(*(u16*)0xFFFF891E) 
//#define wMUT89_ADC_Channel_8_2 										(*(u16*)0xFFFF8920) 
//#define wMUT8A_TPS_Corrected 										(*(u16*)0xFFFF88EA) 
//#define wMUT8B 														(*(u16*)0xFFFF8D7C) 
//#define wMUT8C_Manifold_AbsPressure_ADC8bit 						(*(u16*)0xFFFF9964) 
//#define wMUT8D 														(*(u16*)0xFFFF80F6) 
//#define	wMUT8F 														(*(u16*)0xFFFF8DC2) 
//#define	wMUT90_ECNT9A 												(*(u16*)0xFFFF8DCA) 
//#define	wMUT91_Timer_Status_Register_9_TSR9_Scaled 					(*(u16*)0xFFFF8DCC) 
//#define wMUT92_Timer_Status_Register_9_TSR9_Scaled_Checked 			(*(u16*)0xFFFF8DD0) 
//#define wMUT93_Fadout_Timer_Value 									(*(u16*)0xFFFF8DC0) 
//#define	wMUT97_ADC_8_8bit 											(*(u16*)0xFFFF8922) 
//#define wMUT98_MUT99 												(*(u16*)0xFFFF91E8) 
//#define	wMUT9A_Ligths_Bit_Array 									(*(u16*)0xFFFF8872) 
//#define wMUT9B_Output_Pins 											(*(u16*)0xFFFF8878) 
//#define wMUT9C_MAF_UNKNOWN 											(*(u16*)0xFFFF8EDA) 
//#define wMUT9D_IGN_ADDITION 										(*(u16*)0xFFFF8EDC) 
//#define wMUT9E 														(*(u16*)0xFFFF8EDE) 
//#define wMUT9F 														(*(u16*)0xFFFF8EE0) 
//#define wMUTA0_Sensor_Pins 											(*(u16*)0xFFFF8F02) 
//#define wMUTA5_Port_B_Data_Register_Low 							(*(u16*)0xFFFF8D2A) 
//#define wMUTB2_Port_J_Data_Register_Low 							(*(u16*)0xFFFF8FF8) 
//#define wMUTB4_lookup_value 										(*(u16*)0xFFFF8836) 
//#define wMUTC0_bMUT54_Acceleration_Enrichment 						(*(u16*)0xFFFF8B08) 
//#define	wMUTC1_bMUT55_Deceleration_Enleanment 						(*(u16*)0xFFFF8B0A) 
//#define	wMUTD0_BitMap1 												(*(u16*)0xFFFF89D2) 
//#define	wMUTD1_BitMap_FAA 											(*(u16*)0xFFFF89D4) 
//#define bMUT02 														(*(u16*)0xFFFF888F) 
//#define bMUT2B 														(*(u16*)0xFFFF808F) 
//#define	bMUT2C_Air_Volume 											(*(u16*)0xFFFF80A5) 
//#define bMUT3D_Front_Oxygen_Sensor_2 								(*(u16*)0xFFFF8091) 
//#define	bMUT3E_Rear_Oxygen_Sensor_2 								(*(u16*)0xFFFF80A7) 
//#define bMUT5D_ADC_UNK_PORT_08_COPY 								(*(u16*)0xFFFF88CE) 
//#define bMUT60 														(*(u16*)0xFFFF803C) 
//#define bMUT61 														(*(u16*)0xFFFF803E) 
//#define bMUT62 														(*(u16*)0xFFFF8040) 
//#define bMUT63 														(*(u16*)0xFFFF8093) 
//#define bMUT64 														(*(u16*)0xFFFF80A9) 
//#define bMUT65 														(*(u16*)0xFFFF9002) 
//#define bMUT68 														(*(u16*)0xFFFF8095) 
//#define bMUT69 														(*(u16*)0xFFFF80AB) 
//#define bMUT8E_Solenoid_Duty 										(*(u16*)0xFFFF8DC4) 
//#define	bMUTA2_Port_A_Data_Register_Low 							(*(u16*)0xFFFF8762) 
//#define	bMUTA6_Port_C_Data_Register_Low 							(*(u16*)0xFFFF8D2E) 
//#define	bMUTA8_Port_D_Data_Register_Low 							(*(u16*)0xFFFF8D3E) 
//#define bMUTAC_Port_F_Data_Register_Low 							(*(u16*)0xFFFF8D38) 
//#define bMUTAE_Port_G_Data_Register_Low 							(*(u16*)0xFFFF87BE) 
//#define	bMUTB0_Port_H_Data_Register_Low 							(*(u16*)0xFFFF8D42) 
//#define bMUTB7 														(*(u16*)0xFFFF8864) 
//#define	bMUTB8 														(*(u16*)0xFFFF8865) 
//#define bMUTB9 														(*(u16*)0xFFFF8866) 
//#define bMUTBA 														(*(u16*)0xFFFF8867) 
//#define bMUTBB 														(*(u16*)0xFFFF9144) 
//#define bMUTBC 														(*(u16*)0xFFFF81DA) 
//#define bMUTBD 														(*(u16*)0xFFFF81DC) 
//#define bMUTBE 														(*(u16*)0xFFFF90BE) 
//#define bMUTC2 														(*(u16*)0xFFFF9966) 
//#define bMUTC3 														(*(u16*)0xFFFF9968) 
//#define bMUTC4 														(*(u16*)0xFFFF996A) 
//#define bMUTC5_InjPulseW_8us 										(*(u16*)0xFFFF8A50) 
//#define	bMUTC6 														(*(u16*)0xFFFF8A52) 
//#define	bMUTC7 														(*(u16*)0xFFFF8A68) 
//#define	bMUTC8 														(*(u16*)0xFFFF8A6C) 
//#define bMUTCA_KNOCK 												(*(u16*)0xFFFF9988) 
//#define bMUTCB_KNOCK 												(*(u16*)0xFFFF8C54) 
//#define	bMUTCC_KNOCK 												(*(u16*)0xFFFF8C56) 
//#define bMUTCD_KNOCK_PRECOUNT_1 									(*(u16*)0xFFFF8C4E) 
//#define	bMUTCE_KNOCK_PRECOUNT_2 									(*(u16*)0xFFFF8C50) 
//#define bMUTD2_MAF_MAP_FLAG 										(*(u16*)0xFFFF89D6) 
//#define bMUTD3_BitMap4_FCA_Store 									(*(u16*)0xFFFF89D8) 
//#define bMUTD4_BitMap5_FDA_Store 									(*(u16*)0xFFFF89DA) 
//#define bMUTD5 														(*(u16*)0xFFFF8EFE) 
//#define bMUTD6 														(*(u16*)0xFFFF8F64) 
//#define bMUTD7 														(*(u16*)0xFFFF8F6E) 
//#define bMUTD8 														(*(u16*)0xFFFF8104) 
//#define bMUTD9 														(*(u16*)0xFFFF8108) 
//#define bMUTDA 														(*(u16*)0xFFFF810C) 
//#define bMUTDB 														(*(u16*)0xFFFF8110) 
//#define	bMUTDC 														(*(u16*)0xFFFF8112) 
//#define	bMUTDD 														(*(u16*)0xFFFF86E0) 
//#define	bMUTDE 														(*(u16*)0xFFFF8F74) 
//#define bMUTDF 														(*(u16*)0xFFFF86E2) 
//#define bMUTE0 														(*(u16*)0xFFFF8F76) 
//#define	bMUTF9 														(*(u16*)0xFFFF8B64) 






//#define	KNOCK_FLAG_FFFF8C34				(*(u16*)0xFFFF8C34) // 0x40 - enabled knock retard;

//#define SAR3							(*(void**)0xFFFFecf0)
//#define DAR3							(*(void**)0xFFFFecf4)
//#define DMATCR3							(*(u32*)0xFFFFecf8)
//#define CHCR3							(*(u32*)0xFFFFecfc)

//#define DMAOPFLAG						(*(u32*)0xFFFF8480)
//#define DMAOPFLAG2						(*(u32*)0xFFFF8484)
//#define DMAaddress						(*(void**)0xFFFF8488)
//#define DMAlength						(*(u16*)0xFFFF848c)

//#define serialreceivewithoutdma			((void(*)(void))0xD34A)	/*TO BE CHANGED FOR EACH ROM*/
//#define bit7allowslogging				(*(u16*)0xFFFF8E42)
//#define mutorobd						(*(u16*)0xFFFF8E08)
//#define receive_transmit_status_bits	(*(u16*)0xFFFF8E3E) 	/*TO BE CHANGED FOR EACH ROM*/
//#define mut_timeout						(*(u16*)0xFFFF8EAC) 	/*TO BE CHANGED FOR EACH ROM*/
//
//#define SCR0							(*(byte*)0xFFFFf002)
//#define TDR0							(*(byte*)0xFFFFf003)
//#define SSR0							(*(byte*)0xFFFFf004)
//#define RDR0							(*(byte*)0xFFFFf005)

#define CEL8_7100						((Axis*)0x7100)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define __byte_FFFF8400					(*(byte*)0xFFFF8400) // 1 - Alt maps
//#define hiIgnMapIndex					(*(byte*)0xFFFF8401) // 0..7
//#define hiFuelMapIndex					(*(byte*)0xFFFF8402) // 0..7
//#define veMapIndex						(*(byte*)0xFFFF8403) // 0..7

extern byte _byte_FFFF8400;
extern byte hiIgnMapIndex;					
extern byte hiFuelMapIndex;					
extern byte veMapIndex;						


//#define __axis_res_RPM25				(*(u16*)0xFFFF8460)
//#define __axis_res_LOAD30				(*(u16*)0xFFFF8462)

extern u16 axis_ig_RPM;	
extern u16 axis_ig_LOAD;	
extern u16 axis_fu_RPM;	
extern u16 axis_fu_LOAD;	
extern u16 axis_ve_RPM;	
extern u16 axis_ve_LOAD;	
extern u32 frameCount;

extern byte hiFuelMapRAM[];
extern i16	hiIgnMapRAM[];
extern byte veMapRAM[];

#define __DEADloc						(*(u16*)0xFFFFA800)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define loIgnMapData						((const i8*)0x05413)

#define array_OctanNum						((const byte*)0x3AAA)

//#define romHiIgnMap						(*(Map3D_W*)0x38d42)

//#define ramHiIgnMap						(*(Map3D_W*)0xFFFFA000)

#define kPa2load(v) (v*2)

#define rpm2mut(v) (v*4/125)

#define SET(v, m) (v |= m)
#define CLR(v, m) (v &= ~m)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif // MISC_H__26_04_2016__22_59

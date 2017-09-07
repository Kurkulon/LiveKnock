#pragma section _F500

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"

#undef F500_Init_Load_ECU_Info_And_BitMap_Flags

//#define sub_A374			((void(*)(void))0xA374)
#define F500_Get_All_ADC	((void(*)(void))0xA7F0)
#define F500_sub_21C80		((bool(*)(void))0x21C80)

#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

void F500_root_sub();
void F500_Init_Load_ECU_Info_And_BitMap_Flags();
void F500_sub_F6E6();
void F500_sub_F7E4();
void F500_sub_F834();
void F500_sub_FBB4();
void F500_sub_FD34();
void F500_sub_FDB6();
void F500_sub_FDF4();
void F500_Coolant_Temp_Threshold_Tests();
void F500_Coolant_Calc1_sub_FF2C();
void F500_Coolant_Calibration_Calc();
void F500_Update_IAT_Sensor();
void F500_Update_Air_Temp_Scaled();
void F500_sub_10188();
void F500_sub_10220();
void F500_O22_Manipulations_sub_1023C(EnVars* ev);
void F500_TPS_Load_RPM_Calcs();
void F500_TPS_sub_103DA();
void F500_sub_1044C();
bool F500_CheckIdleRPM();
void F500_MAP_Coolant_Calcs();
bool F500_sub_10820();
void F500_sub_10878();
void F500_sub_108AA();
void F500_sub_108FE();
void F500_sub_10984();
void F500_sub_10A80();
void F500_sub_10AA6();
bool F500_Check_MAP_Fault();
void F500_Load_sub_10B72();
void F500_sub_10C6E();
void F500_sub_10E10();
void F500_MAP_Hz_Calc_sub_10E54();
void F500_sub_10F08();
void F500_Countdown_Timers_sub_10F5C();
void F500_Battery_Calcs_sub_1101A();
void sub_A374();


#define CEL8_685C							((Axis*)0x685C)
#define CEL9_6876							((Axis*)0x6876)
#define CEL10_68B2							((Axis*)0x68B2)
#define CEL12_68D0							((Axis*)0x68D0)
#define CEL8_6D98							((Axis*)0x6D98)
#define CEL9_75BA							((Axis*)0x75BA)
#define BAR5_6D66							((Axis*)0x6D66)
#define LOAD9_65C0							((Axis*)0x65C0)
#define RPM11_64AC							((Axis*)0x64AC)
#define LOAD9_65F8							((Axis*)0x65F8)
#define mapInletAirTemp_Scaling				((Axis*)0x9B82)
#define CEL7_692E							((Axis*)0x692E)
#define map_Coolant_Temp_Scaling			((Axis*)0x99A8)








#define AFRRPM_4C1A							((Map3D_B *)0x4C1A)
#define AIRTEMPCOMPAFR1_33C4				((Map3D_B *)0x33C4)
#define AIRTEMPCOMPAFR1_45D8				((Map3D_B *)0x45D8)
#define LOADAFR_33B4						((Map3D_B *)0x33B4)
#define TPS_2D_3ED6							((Map3D_B *)0x3ED6)
#define MAP_2D_3EE8							((Map3D_B *)0x3EE8)
#define byte_9B00							((Map3D_B *)0x9B00)
#define CORFUELAIR_33A6						((Map3D_B *)0x33A6)
#define COOLTEMSCAL_98FA					((Map3D_B *)0x98FA)




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_InitManifoldVars()
{
	u32 r1 = wMUT1A_Manifold_AbsPressure_ADC8bit;

	__disable_irq();

	Manifold_ADC8bit_1 = r1;
	Manifold_ADC8bit_2 = r1;
	Manifold_ADC8bit_3 = r1;
	Manifold_ADC8bit_4 = r1;
	Manifold_AbsPressure_ADC8bit_avrg = r1;
	Manifold_AbsPressure_ADC8bit_x256_avrg = r1 << 8;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_root_sub()
{
	F500_Init_Load_ECU_Info_And_BitMap_Flags();

	F500_sub_F6E6();

	F500_sub_F7E4();

	F500_sub_FDF4();

	F500_MAP_Coolant_Calcs();

	F500_sub_10878();

	F500_sub_10AA6();

	F500_sub_10C6E();

	F500_MAP_Hz_Calc_sub_10E54();

	F500_sub_10F08();

	F500_Countdown_Timers_sub_10F5C();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Init_Load_ECU_Info_And_BitMap_Flags()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_F6E6()
{
	if (RT_FLAG1_FFFF8888 & STARTER)
	{
		starter_timer_up = 0;
	};

	if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{
		cranking_end_timer_up = 0;
	};

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		cranking_stall_timer_up = 0;

		coolantTempDuringCranking = wMUT10_Coolant_Temperature_Scaled;

		airTempDuringCranking = wMUT11_Intake_Air_Temperature_Scaled;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_F7E4()
{
	word_FFFF8898 = word_FFFF8896;
	word_FFFF8894 = MUT_03_FLAGS;
	word_FFFF888C = MUT_00_01_FLAGS;

	sub_A374();

	RT_FLAG1_COPY_FFFF888A = RT_FLAG1_FFFF8888;

	word_FFFF8892 = word_FFFF8890;
	LAUNCH_TEST_FLAG_1_COPY_FFFF889C = LAUNCH_TEST_FLAG_1_FFFF889A;

	F500_sub_F834();

	F500_sub_FD34();

	F500_sub_FDB6();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_F834()
{
	const u32 r9 = 0x100;

	u32 rtf = MUT_00_01_FLAGS;
	u32 r2 = MUT_03_FLAGS;

	u32 r8 = word_FFFF8896;

	if (byte_102D == 0)
	{
		CLR(rtf, RT_14_bit|RT_10_bit);
	};

	if ((byte_1046 & 2) == 0)
	{
		SET(rtf, FIX_TIMING);
	};

	if (byte_102A == 0)
	{
		CLR(rtf, RT_9_bit);
	};

	if (byte_1041 == 0)
	{
		CLR(r2, 0x10);
	};

	if ((wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL)) || starter_timer_up < word_18B6/*20*/)
	{
		SET(rtf, RT_5_ALWAYS_1);
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_18BA)
	{
		CLR(rtf, POWER_STEERING);
	};


	TRG(word_FFFF8D60, r9, wMUT12_Coolant_Temperature_Min_81, word_1A86, word_1A88);


	if ((wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL)) || cranking_end_timer_up < word_18B8 || (word_FFFF8D60 & 0x100))
	{
		CLR(rtf, AC_SWITCH);
	};

	CLR(word_FFFF8CE4, 0x8000);

	if (byte_102E == 2)
	{
		if ((rtf & AC_SWITCH) && (cranking_end_timer_up < (word_19F6 * 20)))
		{
			SET(r2, r9);
		}
		else
		{
			CLR(r2, 0x100);

			if ((rtf & AC_SWITCH) && (rtf & RT_0_bit))
			{
				SET(r2, r9);
			};
		};
	};

	if (byte_102E == 2)
	{
		if (wMUT15_Barometric_Pressure > word_19F0)
		{
			timer_FFFF8784 = word_19FC;
		};

		u32 r13 = (byte)(fix8_FFFF8DCE>>8);


		TRG(wMUT19_Startup_Check_Bits, 0x2000, r13, word_2110, word_210E);


		if ((rtf & (AC_SWITCH|RT_0_bit)) == (AC_SWITCH|RT_0_bit))
		{
			if (wMUT11_Intake_Air_Temperature_Scaled > word_19F8 || (IATONOFF_105E != 0 && (wMUT19_Startup_Check_Bits & 0x2000)) 
				|| timer_FFFF8784 == 0 || wMUT10_Coolant_Temperature_Scaled < word_19FA || cranking_end_timer_up < (word_19F4*20))
			{
				CLR(rtf, RT_0_bit);
			};
		};
	};

	if ((bMUTD2_FBA_MAF_MAP_FLAG & 0x10) == 0 && ((rtf & AC_SWITCH) == 0 || byte_102E == 0))
	{
		CLR(rtf, RT_0_bit);
		CLR(r2, 0x100);
		CLR(r8, 0x3000);
	};

	if (byte_102B != 0)
	{
		CLR(rtf, FIX_TIMING);
	};

	if (MUT_CMD_0 & 1) // MUT_D9 Fix timing at 5 degrees
	{
		SET(rtf, FIX_TIMING);
		CLR(rtf, SPEED_ADJUST);
	};

	if (MUT_CMD_1 & 0x40) // MUT_C3 SAS (Speed Adjusting Screw)
	{
		SET(rtf, FIX_TIMING|SPEED_ADJUST);
	};

	CLR(rtf, RACING);

	if (timer_down_FFFF89CE != 0)
	{
		SET(rtf, RACING);
	};

	if (bMUTD2_FBA_MAF_MAP_FLAG & 8) // AYC/ACD
	{
		if ((wMUT40_Stored_Faults_Lo & 8) || (wMUT44_Stored_Faults_Lo_2 & 0xEF)) {};

		WFLAG(rtf, RT_7_bit, NVRAM_FFFF802C & 1);
	};

	RT_FLAG1_FFFF8888 = rtf;

	word_FFFF8890 = r2;

	LAUNCH_TEST_FLAG_1_FFFF889A = r8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

u16 F500_sub_FBB4(u32 v)
{
	const u32 r2 = 0x2000;

	if (wMUT15_Barometric_Pressure > word_19F0)
	{
		timer_FFFF8784 = word_19FC;
	};

	u32 r13 = SHLR8(fix8_FFFF8DCE);

	TRG(wMUT19_Startup_Check_Bits, 0x2000, r13, word_2110, word_210E);

	if ((v & 0x11) == 0x11)
	{
		if (wMUT11_Intake_Air_Temperature_Scaled > word_19F8 
			|| (IATONOFF_105E != 0 && (wMUT19_Startup_Check_Bits & r2))
			|| timer_FFFF8784 == 0
			|| wMUT10_Coolant_Temperature_Scaled < word_19FA
			|| cranking_end_timer_up < (word_19F4 * 20))
		{
			v &= ~1;
		};
	};

	return v;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_FD34()
{
	timer_FFFF8576 = timer_down_TXFLAG3_FFFF8574;

	if (RT_FLAG1_FFFF8888 & RT_1_bit)
	{
		timer_down_TXFLAG3_FFFF8574 = t1_unk_18BC;
	};

	if (timer_down_TXFLAG3_FFFF8574 == 0)
	{
		timer_up_FFFF852C = 0;
	};

	if (PEDR_LO_Check_sub_A790())
	{
		timer_FFFF8582 = 280;
	};

	if (timer_up_FFFF852C > 4)
	{
		SET(SPEED_FLAGS, SPD_8_100);
	};

	if (timer_down_TXFLAG3_FFFF8574 != 0)
	{
		SET(word_FFFF93D2, 0x400);
	}
	else
	{
		CLR(word_FFFF93D2, 0x400);
		SET(word_FFFF8A10, 0x80);
	};


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_FDB6()
{
	if (timer_down_TXFLAG3_FFFF8574 != 0)
	{
		if ((RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888) & RT_FLAG1_COPY_FFFF888A & STARTER)
		{
			SET(BOOSTCHECK2_FFFF8A0E, 0x80);
		};
	}
	else
	{
		CLR(BOOSTCHECK2_FFFF8A0E, 0x80);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_FDF4()
{
	F500_Get_All_ADC();

	F500_Coolant_Temp_Threshold_Tests();

	F500_Update_IAT_Sensor();
	F500_sub_10188();
	F500_sub_10220();
	F500_TPS_Load_RPM_Calcs();
	F500_TPS_sub_103DA();
	F500_sub_1044C();

	if ((bMUTD2_FBA_MAF_MAP_FLAG & 0x40) || (bMUTD4_BitMap5_FDA_Store_FFFF89DA & 0x800))
	{
		F500_Battery_Calcs_sub_1101A();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Coolant_Temp_Threshold_Tests()
{
	WFLAG(wMUT71_Sensor_Error, MUT71_0_COOLANT, wMUT07_CoolTemp_ADC8bit < word_1BFE || wMUT07_CoolTemp_ADC8bit > word_1BFC);

	F500_Coolant_Calc1_sub_FF2C();

	F500_Coolant_Calibration_Calc();

	Table_Lookup_Axis(CEL8_685C);
	Table_Lookup_Axis(CEL9_6876);
	Table_Lookup_Axis(CEL10_68B2);
	Table_Lookup_Axis(CEL12_68D0);
	Table_Lookup_Axis(CEL8_6D98);
	Table_Lookup_Axis(CEL9_75BA);

	if (timer_down_TXFLAG3_FFFF8574 == 0 && (SPEED_FLAGS & 0x400))
	{
		coolantTempScld_COPY_2 = wMUT10_Coolant_Temperature_Scaled;
	};
}	

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Coolant_Calc1_sub_FF2C()
{
	u32 r1 = adc_CoolTemp_10bit_MUTCF;


	u32 r2 = map_Coolant_Temp_Scaling->data[map_Coolant_Temp_Scaling->len - 1 - t1_unk_1C08];

	if (wMUT71_Sensor_Error & (0x10|MUT71_0_COOLANT))
	{
		r1 = map_Coolant_Temp_Scaling->data[map_Coolant_Temp_Scaling->len - 1 - coolTemp_sensor_err_val];
	};

	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		COOLANT_TEMPERATURE_2BYTE_FFFF88A8 = r1;
	}
	else if (Bitmap_Store_A_FFFF89EE & 8)
	{
		r1 = Lim16(r1, Sub_Lim_0(COOLANT_TEMPERATURE_2BYTE_FFFF88A8, 12), COOLANT_TEMPERATURE_2BYTE_FFFF88A8 + 4);

		if ((SPEED_FLAGS & 0x1000) && r2 <= r1)
		{
			r1 = r2;
		};

		COOLANT_TEMPERATURE_2BYTE_FFFF88A8 = r1;
	};

	WFLAG(SPEED_FLAGS, 0x1000, COOLANT_TEMPERATURE_2BYTE_FFFF88A8 <= r2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Coolant_Calibration_Calc()
{
	wMUTB4_lookup_value = adc_CoolTemp_10bit_MUTCF;

	Table_Lookup_Axis(map_Coolant_Temp_Scaling);

	coolTempScaledSensor = Table_Lookup_byte_2D_3D(COOLTEMSCAL_98FA);

	wMUT12_Coolant_Temperature_Min_81 = (wMUT71_Sensor_Error & (MUT71_4_bit|MUT71_0_COOLANT)) ? coolTemp_sensor_err_val : coolTempScaledSensor;

	if (adc_CoolTemp_10bit_MUTCF == COOLANT_TEMPERATURE_2BYTE_FFFF88A8)
	{
		wMUT10_Coolant_Temperature_Scaled = coolTempScaledSensor;
	}
	else
	{
		wMUTB4_lookup_value = COOLANT_TEMPERATURE_2BYTE_FFFF88A8;

		Table_Lookup_Axis(map_Coolant_Temp_Scaling);

		wMUT10_Coolant_Temperature_Scaled = Table_Lookup_byte_2D_3D(COOLTEMSCAL_98FA);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Update_IAT_Sensor()
{
	WFLAG(wMUT71_Sensor_Error, MUT71_1_IAT, wMUT3A_AirTemp_ADC8bit < word_1C0E || wMUT3A_AirTemp_ADC8bit > word_1C0C);

	F500_Update_Air_Temp_Scaled();
	
	Table_Lookup_Axis(CEL7_692E);
													
	k_InAirTemp = Table_Lookup_byte_2D_3D(CORFUELAIR_33A6);

	if (timer_down_TXFLAG3_FFFF8574 == 0 && (SPEED_FLAGS & 0x400))
	{
		NVRAM_Intake_Air_Temperature_Scaled = wMUT11_Intake_Air_Temperature_Scaled;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Update_Air_Temp_Scaled()
{
	Table_Lookup_Axis(mapInletAirTemp_Scaling);

	inletAirTempScaledInternal = Table_Lookup_byte_2D_3D(byte_9B00);

	wMUT11_Intake_Air_Temperature_Scaled = (wMUT71_Sensor_Error & MUT71_1_IAT) ? IAT_sensor_err_val/*84*/ : inletAirTempScaledInternal;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10188()
{
	CLR(wMUT71_Sensor_Error, MUT71_2_BARO);

	wMUT15_Barometric_Pressure = Barometric_FFFF8024;

	air_Density = 0x80;

	TPS_MAP_Addition =	Table_Lookup_byte_2D_3D(TPS_2D_3ED6);
	MAP_Addition =		Table_Lookup_byte_2D_3D(MAP_2D_3EE8);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10220()
{
	if (Bitmap_Store_A_FFFF89EE & 1)
	{
		F500_O22_Manipulations_sub_1023C(ENGINE_MAIN_VARIABLES_DIM_off_9198);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_O22_Manipulations_sub_1023C(EnVars* ev)
{
	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 8) == 0 || (*ev->_176_word_FFFF9296 & 4) == 0)
	{
		O2_SECONDARY_SENSOR_VOLTAGE_SHLL8_CLIPPED_FFFF88D0 = Interpolate_256(O2_SECONDARY_SENSOR_VOLTAGE_SHLL8_CLIPPED_FFFF88D0, wMUT3C_Rear_O2_ADC8bit << 8, t1_unk_16FE);

		*ev->_40_wMUT5C_ADC_Rear_02_Voltage = Div_256_R(O2_SECONDARY_SENSOR_VOLTAGE_SHLL8_CLIPPED_FFFF88D0);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_TPS_Load_RPM_Calcs()
{
	u32 TPS = wMUT17_TPS_ADC8bit;

	if (bMUTD2_FBA_MAF_MAP_FLAG & 8)
	{
		bool c =		(wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL)) 
					||	(wMUT71_Sensor_Error & MUT71_3_MAP) 
					||	TPS <= t1_unk_some_TPS_2116/*236*/ 
					||	wMUT1C_ECU_Load >= t1_unk_some_LOAD_2114/*124*/ 
					||	MUT21_RPM_x125div4 >= t1_unk_some_RPM_2232/*32(1000)*/;

		if (c && TPS >= word_2118)
		{	
			timer_FFFF8786 = word_211A/*8*/;
			CLR(wMUT71_Sensor_Error, MUT71_6_TPS);
			CLR(wMUT71_Sensor_Error, MUT71_12_bit);
		}
		else
		{
			if (timer_FFFF8786 == 0)
			{
				SET(wMUT71_Sensor_Error, MUT71_6_TPS);
			};

			SET(wMUT71_Sensor_Error, MUT71_12_bit);
		};
	}
	else
	{
		WFLAG(wMUT71_Sensor_Error, MUT71_6_TPS, ((RT_FLAG1_FFFF8888 & RT_7_bit) && TPS > word_1C12/*102*/) || TPS < word_1C14/*10*/);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_TPS_sub_103DA()
{
	__disable_irq();

	wMUT73_TPS_Open_Delta = TPS_Open_Delta;

	wMUT74_TPS_Close_Delta = TPS_Close_Delta;

	TPS_Close_Delta = 0;

	TPS_Open_Delta = 0;

	__enable_irq();

	if (Bitmap_Store_A_FFFF89EE & 1)
	{
		word_FFFF8904 = Sub_Lim_0(prev_TPS_sub_103DA, wMUT17_TPS_ADC8bit);

		prev_TPS_sub_103DA = wMUT17_TPS_ADC8bit;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_1044C()
{
	u32 r1 = wMUT1B_TPS_Idle_Adder;

	if (F500_CheckIdleRPM())
	{
		SET(wMUT1E_MAF_RESET_FLAG, IDLE);
	}
	else
	{
		timer_FFFF857A = word_198E;

		CLR(wMUT1E_MAF_RESET_FLAG, IDLE);
	};

	if (timer_FFFF857A == 0)
	{
		u32 r13 = wMUT8A_TPS_Corrected;

		timer_FFFF857A = word_198E;

		if (r13 > 33)
		{
			r1 -= 1;
		}
		else if (r13 < 33)
		{
			r1 += 1;
		};
	};

	if (bMUTD2_FBA_MAF_MAP_FLAG & 8)
	{
		r1 = Sub_Lim_0(161, TPS_NVRAM_FFFF802A >> 2);

		if (FLAGS_FFFF8EB0 & 0x80)
		{
			r1 = 0x80;
		};
	};

	wMUT1B_TPS_Idle_Adder = Lim16(r1, word_1994/*113*/, word_1992/*143*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool F500_CheckIdleRPM()
{
	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		return false;
	};

	if ((wMUT23 & 0x10) == 0)
	{
		return false;
	};

	if (RT_FLAG1_FFFF8888 & AC_SWITCH)
	{
		return false;
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_1986)
	{
		return false;
	};

	if (wMUT73_TPS_Open_Delta > word_198C)
	{
		return false;
	};

	u32 r13 = wMUT17_TPS_ADC8bit;

	if (r13 < word_198A || r13 > word_1988)
	{
		return false;
	};

	if (MUT20_RPM_Idle_x125div16 >= wMUT24_Target_Idle_RPM)
	{
		r13 = MUT20_RPM_Idle_x125div16 - wMUT24_Target_Idle_RPM;
	}
	else
	{
		r13 = wMUT24_Target_Idle_RPM - MUT20_RPM_Idle_x125div16;
	};

	if (r13 > word_1990)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define RTF ((RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888) & RT_FLAG1_COPY_FFFF888A)

void F500_MAP_Coolant_Calcs()
{																	//cool -32, -18, -10,  -8,   7,  20,  34,  50,  77, 82
	u32 enrichCoolant = Table_Lookup_byte_2D_3D(AIRTEMPCOMPAFR1_33C4); //  189, 178, 169, 166, 158, 141, 137, 133, 128, 128

	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		word_FFFF8AE2 = 0;
		fuelTrim_FFFF8AE4 = 0x80;
	}
	else
	{	
		u32 RTF = ((RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888) & RT_FLAG1_COPY_FFFF888A);

		if (word_FFFF8AE2 != 0 
			|| ((RTF & RT_7_bit) == 0 && (RTF & RT_5_ALWAYS_1) == 0 && (byte_105C/*0*/ == 0 || (RTF & POWER_STEERING) == 0))
			|| (enrichmentWarmUp >= enrichCoolant && COOLANT_REL_6_FFFF8AC2 == 0 && COOLANT_REL_7_FFFF8AEC == 0))
		{
			if (tm_10ms_FFFF86EA == 0)
			{
				if (fuelTrim_FFFF8AE4 > 0x80 && (Bitmap_Store_A_FFFF89EE & 2))
				{
					fuelTrim_FFFF8AE4 = Sub_Lim_0(fuelTrim_FFFF8AE4, t1_unk_20A8/*6*/);
				};
			}
			else
			{
				fuelTrim_FFFF8AE4 = t1_unk_20AA/*128*/;
			};
		}
		else
		{
			tm_10ms_FFFF86EA = t1_unk_20AC;
			fuelTrim_FFFF8AE4 = t1_unk_20AA;
		};

		if (fuelTrim_FFFF8AE4 < 0x80) { fuelTrim_FFFF8AE4 = 0x80; };

		if (F500_sub_10820() && fuelTrim_FFFF8AE4 == 0x80 && (Bitmap_Store_A_FFFF89EE & 2))
		{
			word_FFFF8AE2 = Sub_Lim_0(word_FFFF8AE2, t1_unk_20AE/*6*/);
		}
		else
		{
			word_FFFF8AE2 = 0xFF;
		};
	};

	enrichCoolant = interpolate_r4_r5_r6(enrichCoolant, Table_Lookup_byte_2D_3D(AIRTEMPCOMPAFR1_45D8), word_FFFF8AE2);

	if ((wMUT1E_MAF_RESET_FLAG & MAP_error) == 0)
	{
		u32 enrichRPM = 0x80;

		enrichCoolant = Sub_Lim_0(enrichCoolant, 0x80);

		if (MUT21_RPM_x125div4 > t1_unk_1776/*16(500)*/)
		{
			Table_Lookup_Axis(LOAD9_65F8);
			enrichRPM= Table_Lookup_byte_2D_3D(LOADAFR_33B4);
		};

		enrichCoolant = Lim_FF(Mul_Div_R(enrichCoolant * enrichRPM, 0x80, 0x4000) + 0x80);
	};

	enrichmentWarmUp = enrichCoolant;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool F500_sub_10820()
{
	bool r13 = ((stored_DTC_5 & 1) || (last_Drive_DTC[5] & 1));


	if ((RT_FLAG1_FFFF8888 & RT_7_bit) == 0)
	{
		return false;
	};

	if ((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) == 0) // Engine Running
	{
		return false;
	};
	
	if (r13)
	{
		return false;
	};

	if ((RT_FLAG1_FFFF8888 & RACING)) // timer_down_FFFF89CE != 0
	{
		return false;
	};

	if (byte_105C == 0)
	{
		return true;
	};

	if ((RT_FLAG1_FFFF8888 & POWER_STEERING)) // 0: wMUT10_Coolant_Temperature_Scaled <= word_18BA(60)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10878()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		F500_sub_108AA();
	}
	else
	{
		F500_sub_108FE();
		F500_sub_10984();
	};

	F500_sub_10A80();

	Table_Lookup_Axis(RPM11_64AC);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_108AA()
{
	__disable_irq();

	crankHT_x_4us_3 = 0xFFFF;

	RPM_x_4_096__3 = 0;
	RPM_x_4_096__2 = 0;
	RPM_x_4_096__1 = 0;

	__enable_irq();

	MUT21_RPM_x125div4 = 0;

	MUT20_RPM_Idle_x125div16 = 0;

	rpm_x125div32_B = 0;

	prev_RPM_x125div4 = 0;
	
	rpm_x125div32_A = 0;
	
	dif_rpm_x125div32_AB = 0;
	
	RPM_DELTA_FFFF8948 = 128;
	
	null_RPM_x125div256 = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_108FE()
{
	__disable_irq();

	u32 r1 = crankHT_x_4us_3;
	u32 r2 = crankHT_x_4us_4;

	__enable_irq();

	rpm_x125div32_A = DIV_DW_R(1920000, r2);

	rpm_x125div32_B = DIV_DW_R(1920000, r1);

	MUT20_RPM_Idle_x125div16 = Lim_FF((rpm_x125div32_B + 1) >> 1);
	
	MUT21_RPM_x125div4 = Lim_FF((rpm_x125div32_B + 4) >> 3);
	
	null_RPM_x125div256 = DIV_DW_R(15360000, r1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10984()
{
	if (cranking_end_timer_up >= word_16BC)
	{
		dif_rpm_x125div32_AB = Lim_FF(Sub_Lim_0(rpm_x125div32_A, rpm_x125div32_B));

		if (Bitmap_Store_A_FFFF89EE & 4)
		{
			return;
		};

		RPM_DELTA_FFFF8948 = Lim_FF(Sub_Lim_0(MUT21_RPM_x125div4 + 128, prev_RPM_x125div4));
	}
	else
	{
		dif_rpm_x125div32_AB = 0;
		RPM_DELTA_FFFF8948 = 128;
	};

	prev_RPM_x125div4 = MUT21_RPM_x125div4;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10A80()
{
	word_FFFF8950 = (RT_FLAG1_FFFF8888 & RACING) ? word_17B0/*232*/ : t1_unk_17AE/*232*/;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10AA6()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		F500_InitManifoldVars();
	};

	WFLAG(wMUT71_Sensor_Error, MUT71_3_MAP, F500_Check_MAP_Fault() || F500_sub_21C80());

	F500_sub_10E10();

	F500_Load_sub_10B72();

	Table_Lookup_Axis(LOAD9_65C0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool F500_Check_MAP_Fault()
{
	u32 r13 = wMUT1A_Manifold_AbsPressure_ADC8bit;

	TRG(ZERO_8_IGNITION_FLAGS, 0x10, wMUT8A_TPS_Corrected, word_1C68, word_1C6A);

	return (r13 >= word_1C66 || ((timer_down_FFFF89CE == 0 || (ZERO_8_IGNITION_FLAGS & 0x10)) && r13 < word_1C64));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Load_sub_10B72()
{
	__disable_irq();

	u32 r1 = Manifold_AbsPressure_ADC8bit_avrg;
	u32 r2 = Manifold_AbsPressure_ADC8bit_x256_avrg >> 7;
	u32 r8 = wMUT1A_Manifold_AbsPressure_ADC8bit;

	__enable_irq();

	wMUT1D_Manifold_Absolute_Pressure_Mean = r1;

	if ((wMUT1E_MAF_RESET_FLAG & MAP_error) == 0)
	{
		if (wMUTC0_bMUT54_Acceleration_Enrichment != 0 || wMUTC1_bMUT55_Deceleration_Enleanment != 0)
		{
			r1 = r8;
			r2 = r8 << 1;
		};
	};

	r1 = Lim_FF(r1);

	wMUT1C_ECU_Load = r1;
	ECU_Load_1 = r1;
	ECU_Load_null = r1;
	wMUT1F_ECU_Load_Previous = r1;
	wMUT1C_ECU_Load = r1;
	ECU_Load_x2_FFFF8962 = r2;
	null_ECU_Load_x2_FFFF8960 = r2;
	null_ECU_Load_x2_FFFF895E = r2;
	ECU_Load_x2_FFFF895C = r2;
	Manifold_AbsPressure_null = r8;

	wMUTB4_lookup_value = Lim_FF(Table_Lookup_byte_2D_3D(TEMPCOMP_3BEE) + wMUT8A_TPS_Corrected);

	Table_Lookup_Axis(RPM5_6830);

	Table_Lookup_Axis(VOLT7_6844_Throttle);

	load_vs_tps = sub_21CA8(Table_Lookup_byte_2D_3D(LIMPHOME_33F4));

	r1 = wMUT1C_ECU_Load;

	if ((wMUT1E_MAF_RESET_FLAG & MAP_error) == 0)
	{
		r1 = Sub_Lim_0(r1 + 205 , wMUT15_Barometric_Pressure);
	};

	load_FFFF8976 = Lim_FF(r1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10C6E()
{
	if ((wMUT1E_MAF_RESET_FLAG & STALL) == 0)
	{
		Table_Lookup_Axis(BAR5_6D66);

		u32 r1 = Table_Lookup_byte_2D_3D(AFRRPM_4C1A);

		u32 r2 = wMUT31_Volumetric_Efficiency + word_1524/*48*/;

		word_FFFF89C0 = Div_65536_R(Mul_DW_Div(Mul32_Fix8(MUT21_RPM_x125div4 * word_223E/*101*/ * 1067, r2), wMUT1C_ECU_Load * r1, 26240));
	}
	else
	{
		word_FFFF89C0 = 0;
	};

	MAF_MAP__Hz_FFFF89BC = Lim_FF(Mul_Div_R(word_FFFF89C0, 1024, word_223C /*18*/ * 100));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10E10()
{
	__disable_irq();

	wMUT56_MAX_MAP_FALL_CHANGE = Lim_FF(MAX_MAP_FALL_CHANGE);
	wMUT57_MAX_MAP_RISE_CHANGE = Lim_FF(MAX_MAP_RISE_CHANGE);

	MAX_MAP_FALL_CHANGE = 0;
	MAX_MAP_RISE_CHANGE = 0;


	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_MAP_Hz_Calc_sub_10E54()
{
	u32 r1 = SPEED_PULSES_FFFF89C4; // 2496 us

	u32 r13 = Div_WW(2260, r1);

	wMUT2E_Vehicle_Speed_Frequency = (r13 < 254) ? r13 : 254;

	// 4665 - 1 gear
	// 2535 - 2 gear
	// 1748 - 3 gear
	// 1270 - 4 gear
	// 1046 - 5 gear

	transmission_state = Lim_FFFF((rpm_x125div32_B * r1) >> 2);

	if (timer_down_TXFLAG3_FFFF8574 == 0)
	{
		CLR(SPEED_FLAGS, SPD_3_08);
	}
	else
	{
		if (wMUT2E_Vehicle_Speed_Frequency >= word_1D7E/*20*/)
		{
			SET(SPEED_FLAGS, SPD_3_08);
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10F08()
{
	if (wMUTD1_BitMap_FAA & 2)
	{
		wMUT5A = word_FFFF8A20;
		wMUT5B_Rear_02_Voltage = word_FFFF8A22;
	}
	else
	{
		u32 r13 = t1_unk_158A/*26*/;

		wMUT5B_Rear_02_Voltage = wMUT5A = (wMUT15_Barometric_Pressure <= word_158C/*183*/) ? Sub_Lim_0(r13, word_158E/*0*/) : r13;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Countdown_Timers_sub_10F5C()
{
	__disable_irq();

	CLR(Bitmap_Store_A_FFFF89EE, 0x1FF);

	Bitmap_Store_A_FFFF89EE |= (Bitmap_Store_B_FFFF89F0 & 0x1FF);

	CLR(Bitmap_Store_B_FFFF89F0, 0x1FF);

	__enable_irq();

	if (Bitmap_Store_A_FFFF89EE & 1)
	{
		mem_incr(&cranking_end_timer_up, &timer_up_FFFF8548);
		mem_decr(&timer_down_TXFLAG3_FFFF8574, &word_FFFF86A0);
	};

	if (Bitmap_Store_A_FFFF89EE & 1)
	{
		mem_incr(&timer_up_FFFF8548, &timer_up_FFFF8548);
		mem_decr(&word_FFFF86A0, &bMUTDD);
	};

	if (Bitmap_Store_A_FFFF89EE & 4)
	{
		mem_incr(&timer_up_FFFF8548, &timer_up_FFFF8548);
		mem_decr(&bMUTDD, &timer_FFFF8784);
	};

	if (Bitmap_Store_A_FFFF89EE & 8)
	{
		mem_incr(&timer_up_FFFF8548, &word_FFFF8550);
		mem_decr(&timer_FFFF8784, &word_FFFF8834);
	};

	if (timer_down_TXFLAG3_FFFF8574 == 0)
	{
		timer_up_FFFF852C = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Battery_Calcs_sub_1101A()
{
	Mul_Lim_FFFF(wMUT88_Fuel_Level_ADC8bit, 191);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void sub_A374()
{
	const u32 r9 = ~0x10;
	const u32 r8 = ~2;
	const u32 r2 = 0x200;
	const u32 r1 = ~0x200;

	__disable_irq();

	u32 r13 = MUT_00_01_FLAGS;

	WBIT(r13, 1, ZRO(bMUTB7, 1));

	WBIT(r13, 2, ZRO(reg_PEDRL, 2));

	WBIT(r13, POWER_STEERING, bMUTB8 & 4);

	WBIT(r13, AC_SWITCH, ZRO(bMUTB8, 1));

	SET(r13, 0x20);

	WBIT(r13, STARTER, ZRO(reg_PEDRL, 4));

	WBIT(r13, 0x80, bMUTBA & 4);
	
	WBIT(r13, r2, ZRO(reg_PJDRH, 4));

	WBIT(r13, 0x400, ZRO(word_FFFF8868, 0x20));

	WBIT(r13, 0x800, bMUTB9 & 1);

	WBIT(r13, 0x1000, bMUTB9 & 4);

	WBIT(r13, 0x2000, word_FFFF8868 & 0x40);

	WBIT(r13, 0x4000, ZRO(word_FFFF8868, 0x10));

	WBIT(r13, 0x8000, bMUTB7 & 4);

	MUT_00_01_FLAGS = r13;

	__enable_irq();

	__disable_irq();

	r13 = MUT_03_FLAGS;

	WBIT(r13, 2, bMUTB7 & 2);

	WBIT(r13, 4, ZRO(bMUTB8, 2));

	WBIT(r13, 0x10, word_FFFF8868 & 0x80);

	WBIT(r13, 0x20, reg_PADRH & 0x80);

	WBIT(r13, 0x40, ZRO(word_FFFF8868, 4));

	WBIT(r13, 0x80, ZRO(word_FFFF8868, 1));

	WBIT(r13, 0x200, word_FFFF8868 & 1);

	MUT_03_FLAGS = r13;

	__enable_irq();

	__disable_irq();

	r13 = word_FFFF8896;

	WBIT(r13, 0x10, bMUTB7 & 2);

	WBIT(r13, 0x100, bMUTB7 & 8);

	WBIT(r13, 0x200, bMUTB8 & 8);

	WBIT(r13, 0x400, bMUTB9 & 8);

	WBIT(r13, 0x800, bMUTBA & 8);

	WBIT(r13, 2, reg_PJDRH & 8);

	word_FFFF8896 = r13;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

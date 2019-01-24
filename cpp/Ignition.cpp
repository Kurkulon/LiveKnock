//#pragma section _Ignition
#pragma section _main

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "hardware.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_NVRAM_OctaneNum();
extern "C" void SysInit_sub_16D74();
extern "C" void IG04_root_Update_Ignition();

static void	IG04_Init_knock_sub_16DB2();
static void IG04_Set_Load_ECU_Ignintion();
static void IG04_Check_Ign_16F1A();
static void IG04_Check_Fix_timing_5_degrees();
static bool IG04_Is_Fix_timing_5_degrees();
static void IG04_sub_16FA6();
static void IG04_sub_1700A();
static void IG04_sub_1702A();
static bool IG04_Check_17074();
static void IG04_sub_1714C();
static bool IG04_KNOCKLOAD_sub_1718E();
static void IG04_sub_1726C();
static bool IG04_sub_1729C();
static void IG04_sub_172D6();
static void IG04_sub_173F2();
static void IG04_OctaneNumKnockUpdate();
static bool IG04_Check_octane_update();
static void IG04_Update_MUT27_Octane_Number();
static void IG04_Update_MUT6F_Knock_Acceleration();
static void IG04_sub_17684();
static void IG04_sub_176B6();
static bool IG04_sub_17770();
static void IG04_sub_178D0();
static void IG04_sub_179B0();

//static bool	IG04_sub_179C4(); // no call

static void IG04_sub_17A3A();
static void IG04_sub_17A4E();
static bool IG04_sub_17A7E();
static void IG04_sub_17B9A();
static bool IG04_sub_17BEC();
static void IG04_sub_17C6E();
static bool IG04_sub_17C9C();
static void IG04_sub_17D04();
static void IG04_Update_MUT04_Timing_Advance_Interpolated();
static void Update_MUT33_Corrected_Timing_Advance();
static u16 	IG04_Update_OctanEgrIgnTiming();
static u16 	GetLoadCorrectedDeltaTPS();
//static u16 	IG04_GetLoad_sub_1821E(); // inlined in GetLoadCorrectedDeltaTPS
static u16 	IG04_Ign_Temp_Correct(u16 v);
static u16 	IG04_IGNIT_TESTS_183E8(u16 v);
static bool IG04_sub_18464();
static u16 	IG04_Lim_Deceleration_Fuel_Cut();
static u16 	IG04_sub_18570();
static u16 	IG04_sub_1859E();
static u16 	IG04_useless_sub_185EA();
static u16 	IG04_Airtemp_Ignition_Compensation_sub_185FC();
static bool IG04_sub_18728();
static u16 	IG04_sub_1876E();
static u16 	IG04_RPM_CORR_sub_18952();
static u16 	IG04_SET0x80IGNPAR2_sub_18A1C();
static u16 	IG04_sub_18A2E();
static void IG04_sub_18B48();
static void IG04_SetMaxKnockSumControl();
static void IG04_Ignition_coil_charge_sub_18BD4();
static void IG04_UpdateTimingMUT();
static void IG04_UpdateStartIgnInterpolator();
static void IG04_sub_18D84();

static u16 	IG04_sub_21DCE(u16 v);

//static u16 	Barometric_Correction_sub_22084();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//#define IGN_TEST_FLAG_0_F32					(*(const byte*)0xF32)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define unk119_59DE							((const byte*)0x59DE)
#define unk120_59F2							((const byte*)0x59F2)
#define unk121_59F8							((const byte*)0x59F8)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define VOLT9_66C6							((Axis*)0x66C6)
#define RPM8_6570							((Axis*)0x6570)
#define LOAD9_65DC							((Axis*)0x65DC)
#define BAR4_66F6							((Axis*)0x66F6)
#define CEL8_6914							((Axis*)0x6914)
#define CEL8_79AE							((Axis*)0x79AE)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define arr_Load_2D_RPM11					((Map3D_B**)0x7AE8)
#define unk048_6354							((Map3D_B*)0x6354)
#define KNOCKLOAD_3A6E						((Map3D_B*)0x3A6E)
#define knockLoad_OctaneUpdate				((Map3D_B*)0x3A80)
#define IGNCOILCHGTIME1_3A3E				((Map3D_B*)0x3A3E)
#define IGNCOILCHGTIME2_3A4E				((Map3D_B*)0x3A4E)
#define IGNCOILCHGTIME3_3A5E				((Map3D_B*)0x3A5E)
#define unk023_59E4							((Map3D_B*)0x59E4)
#define unk028_5FFE							((Map3D_B*)0x5FFE)
#define unk118_59CE							((Map3D_B*)0x59CE)
#define unk033_589E							((Map3D_B*)0x589E)
#define unk032_588E							((Map3D_B*)0x588E)
#define unk115_58AE							((Map3D_B*)0x58AE)
#define unk116_58B8							((Map3D_B*)0x58B8)
#define LOWTRMTEMPCOOL_3A30					((Map3D_B*)0x3A30)
#define AFRAIRTEMP1_630A					((Map3D_B*)0x630A)
#define IGNTRMAIRTEMPLOAD_3A1E				((Map3D_B*)0x3A1E)
#define IGNTRMAIRTEMP_3A04					((Map3D_B*)0x3A04)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_NVRAM_OctaneNum()
{
	wMUT27_Octane_Number = octaneNum = GET_FROM_MASSIVE_byte(array_OctanNum);

	KNOCK_FLAG_FFFF8C34 = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_sub_16D74()
{
	timingAdv_75 = 160;

	ignCoilTime_4us = IGNCOILCHGTIME1_3A3E->m2d.data[0] << 4; // byte_3A44 << 4;
	ignCoil_MaxCrankDegrees = IGNCOILCHGTIME3_3A5E->m2d.data[0]; // byte_3A64;

	IG04_Init_knock_sub_16DB2();

	IGN_PAR2_FFFF8BF0 = 0x80;
	max_Knock_Retard = const_24;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Init_knock_sub_16DB2()
{
	u16 t = 0x4000;

	if ((FLAGS_FFFF8EB0 & 0x80) == 0)
	{
		t = 0x1000;
	};

	__disable_irq();

	knock_filtered_x256 = t;
	wMUTC9_knock_ADC_proc_filtered = t;

	knock_base_final = knockAdder_TripleGain/*5*/;

	CLR(KNOCK_FLAG2_FFFF887A, KNOCK_GAIN_3);

	__enable_irq();

	KNOCK_FLAG_FFFF8C34 &= KNOCK_RPM_HI;

	Knock_Output_Calc_sub_AC96();

	KNOCK_PRECOUNT_MAX_FFFF8C4A = word_1818/*180*/;

	KNOCK_REL_1_FFFF8C4C = word_1812/*3*/;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void IG04_root_Update_Ignition()
{
	IG04_Set_Load_ECU_Ignintion();

	IG04_Check_Ign_16F1A();

	IG04_Check_Fix_timing_5_degrees();

	IG04_sub_16FA6();

	IG04_sub_17684();

	BC06_sub_1E2D0();

	IG04_Update_MUT04_Timing_Advance_Interpolated();

	IG04_sub_18B48();

	IG04_SetMaxKnockSumControl();

	IG04_Ignition_coil_charge_sub_18BD4();

	IG04_UpdateTimingMUT();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Set_Load_ECU_Ignintion()
{
	load_ECU_Ignintion = wMUT1C_ECU_Load;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Check_Ign_16F1A()
{
	WFLAG(IGN_FLAG9_FFFF8BB6, IGN_F9_40, load_ECU_Ignintion >= Query_byte_2D_3D_Table(arr_Load_2D_RPM11));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Check_Fix_timing_5_degrees()
{
	WFLAG(IGN_FLAG9_FFFF8BB6, IGN_F9_FIX5, IG04_Is_Fix_timing_5_degrees());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_Is_Fix_timing_5_degrees()
{
	return (RT_FLAG1_FFFF8888 & (FIX_TIMING|SPEED_ADJUST)) == FIX_TIMING;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_16FA6()
{
	if (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN)
	{
		IG04_sub_1700A();

		IG04_sub_1702A();

		IG04_sub_1714C();

		IG04_sub_1726C();

		IG04_sub_172D6();

		IG04_sub_173F2();

		IG04_OctaneNumKnockUpdate();

		IG04_Update_MUT27_Octane_Number();

		IG04_Update_MUT6F_Knock_Acceleration();
	}
	else
	{
		__disable_irq();

		wMUT26_Knock_Retard = 0;

		CLR(wMUT72_Knock_Present, 1);

		__enable_irq();

		octaneNum = 0;

		wMUT27_Octane_Number = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_1700A()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		IG04_Init_knock_sub_16DB2();

		Timer_Counter_Related_sub_C928();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_1702A()
{
	KNOCK_FLAG_FFFF8C34 |= KNOCK_F1_4000;

	if (IG04_Check_17074())
	{
		SET(KNOCK_FLAG_FFFF8C34, KNOCK_RETARD_ENABLED);
	}
	else
	{
		CLR(KNOCK_FLAG_FFFF8C34, KNOCK_RETARD_ENABLED);

		__disable_irq();

		wMUT26_Knock_Retard = 0;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregsave(IG04_Check_17074)

static bool IG04_Check_17074()
{
	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		Table_Lookup_Axis(CEL8_7100);

		word_FFFF9942 = Table_Lookup_byte_2D_3D(unk048_6354);
	};

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		return false;
	};

	if (IGN_FLAG9_FFFF8BB6 & IGN_F9_FIX5) // Fix timing at 5 degrees;
	{
		return false;
	};

	if (MUT21_RPM_x125div4 < word_17CA/*16*/)
	{
		return false;
	};

	if ((KNOCK_FLAG_FFFF8C34 & KNOCK_F1_4000) == 0)
	{
		return false;
	};

	if (cranking_end_timer_up < (word_FFFF9942 << 2))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_1714C()
{
	if (IG04_KNOCKLOAD_sub_1718E())
	{
		SET(KNOCK_FLAG_FFFF8C34, KNOCK_F1_80);
	}
	else
	{
		CLR(KNOCK_FLAG_FFFF8C34, KNOCK_F1_80);

		__disable_irq();

		word_FFFF855E &= 3;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_KNOCKLOAD_sub_1718E()
{
	WFLAG(KNOCK_FLAG_FFFF8C34, KNOCK_F1_1000, wMUT1C_ECU_Load >= Table_Lookup_byte_2D_3D(KNOCKLOAD_3A6E));

	WFLAG(KNOCK_FLAG_FFFF8C34, KNOCK_F1_2000, !((wMUT71_Sensor_Error & MUT71_3_MAP) || (RT_FLAG1_FFFF8888 & RT_7_bit) || (KNOCK_FLAG_FFFF8C34 & KNOCK_F1_1000) == 0));

	if (wMUT71_Sensor_Error & MUT71_3_MAP)
	{
		return true;
	};

	if ((KNOCK_FLAG_FFFF8C34 & KNOCK_F1_1000) == 0)
	{
		return false;
	};

	if (sub_21E84())
	{
		return true;
	};

	if (Mul_Fix8_R(Sub_Lim_0(coolTempCorrectedIgnTiming, egrLowOctIgn), 728) >= wMUT26_Knock_Retard)
	{
		return true;
	};

	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_1726C()
{
	WFLAG(KNOCK_FLAG_FFFF8C34, KNOCK_FAULT_CHECK, IG04_sub_1729C());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_1729C()
{
	u16 r13 = (KNOCK_FLAG2_FFFF887A & KNOCK_GAIN_3) ? word_1C28/*64(2000)*/ : word_1C2A/*64(2000)*/;

	return (MUT21_RPM_x125div4 >= r13 && wMUT1C_ECU_Load >= word_1C26/*110(55kPa)*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_172D6()
{
	KNOCK_PRECOUNT_MAX_FFFF8C4A = word_1818/*180*/;

	TRG(KNOCK_FLAG_FFFF8C34, KNOCK_F1_800, MUT21_RPM_x125div4, word_1816/*96(3000)*/, word_1814/*106(3312)*/);

	KNOCK_REL_1_FFFF8C4C = (KNOCK_FLAG_FFFF8C34 & KNOCK_F1_800) ? word_1810/*4*/ : word_1812/*3*/;

	WFLAG(KNOCK_FLAG_FFFF8C34, KNOCK_F1_200, MUT21_RPM_x125div4 >= word_181C/*16(500)*/ && MUT21_RPM_x125div4 <= word_181A/*255*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_173F2()
{
	TRG(KNOCK_FLAG_FFFF8C34, KNOCK_RPM_HI, MUT21_RPM_x125div4, word_17F2/*151(4718)*/, word_17F4/*160(5000)*/);

	TRG(KNOCK_FLAG_FFFF8C34, KNOCK_RPM_LOW, MUT21_RPM_x125div4, word_2504/*64(2000)*/, word_2502/*74(2312)*/);

	TRG(KNOCK_FLAG_FFFF8C34, KNOCK_RPM_MID, MUT21_RPM_x125div4, word_2508/*96(3000)*/, word_2506/*106(3312)*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_OctaneNumKnockUpdate()
{
	if (IG04_Check_octane_update())
	{
		bool r13 = (wMUT26_Knock_Retard < minKnockLim);

		if (!r13 && wMUT26_Knock_Retard <= maxKnockLim)
		{
			return;
		};

		if (timer_Knock != 0)
		{
			return;
		};

		if (r13)
		{
			octaneNum += 1;

			if (octaneNum == 0) octaneNum -= 1;

			timer_Knock = word_1802;
		}
		else
		{
			DECLIM(octaneNum);

			timer_Knock = word_1804;
		};

		octaneNum = Lim16(octaneNum, 0, 0xFF);

	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_Check_octane_update()
{
	if (wMUT10_Coolant_Temperature_Scaled < minCoolTempOctanUpdate)
	{
		return false;
	};

	if (wMUT72_Knock_Present & 1)
	{
		return false;
	};

	if (wMUT71_Sensor_Error & MUT71_3_MAP)
	{
		return false;
	};

	if ((KNOCK_FLAG_FFFF8C34 & KNOCK_RETARD_ENABLED) == 0)
	{
		return false;
	};

	if (wMUT1C_ECU_Load < Table_Lookup_byte_2D_3D(knockLoad_OctaneUpdate))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Update_MUT27_Octane_Number()
{
	wMUT27_Octane_Number = sub_21E4C(((wMUT71_Sensor_Error & MUT71_3_MAP) || (wMUT72_Knock_Present & 1)) ? 0 : octaneNum);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Update_MUT6F_Knock_Acceleration()
{
	if (RPM_DELTA_per_100ms >= 0x80 && (RPM_DELTA_per_100ms - 0x80) >= word_17E4/*6(187)*/)
	{
		__disable_irq();

		wMUT6F_Knock_Accel_timer = t1_knock_control_accel_delta_17E6/*40*/;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17684()
{
	IG04_sub_176B6();

	IG04_sub_179B0();

	IG04_sub_17A3A();

	IG04_sub_17A4E();

	IG04_sub_17B9A();

	IG04_sub_17C6E();

	if (byte_1064/*0*/ != 0)
	{
		IG04_sub_17D04();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_176B6()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		CLR(IGN_FLAG9_FFFF8BB6, IGN_F9_04);

		word_FFFF8BF8 = 0;

		__disable_irq();

		word_FFFF8BF4 = 0;
		word_FFFF8BF6 = 0;
		word_FFFF8BFA = 0;

		__enable_irq();
	}
	else
	{
		if (byte_1036/*1*/ != 0 && IG04_sub_17770())
		{
			SET(IGN_FLAG9_FFFF8BB6, IGN_F9_04);

			if (byte_1077/*0*/ != 0)
			{
				IG04_sub_18D84();
			};

			__disable_irq();

			if (byte_1077/*0*/ == 0)
			{
				Table_Lookup_Axis(RPM8_6570);

				word_FFFF8BF4 = Table_Lookup_byte_2D_3D(unk023_59E4);

				word_FFFF8BFE = Table_Lookup_byte_2D_3D(unk028_5FFE);
			};

			word_FFFF8BF6 = 0;

			__enable_irq();
		}
		else
		{
			CLR(IGN_FLAG9_FFFF8BB6, IGN_F9_04);
		};
	};

	IG04_sub_178D0();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17770()
{
	if (RT_FLAG1_FFFF8888 & RT_7_bit)
	{
		word_FFFF85BA = word_2C96/*255*/;

		SET(word_FFFF8BB8, 2);
	}
	else if (word_FFFF85BA == 0)
	{
		CLR(word_FFFF8BB8, 2);
	}
	else
	{
		SET(word_FFFF8BB8, 2);
	};


	if (wMUT73_TPS_Open_Delta <= word_186A/*2*/)
	{
		return false;
	};

	if (load_ECU_Ignintion > word_1870/*54*/)
	{
		return false;
	};

	if ((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) == 0 && byte_1036/*1*/ != 2)
	{
		return false;
	};
	
	if (wMUT10_Coolant_Temperature_Scaled < word_186C/*104*/)
	{
		return false;
	};

	if (wMUT2E_Vehicle_Speed_Frequency < word_186E/*60*/)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 < word_1872/*29*/ || MUT21_RPM_x125div4 > word_1874/*160*/)
	{
		return false;
	};

	if ((word_FFFF8BB8 & 2) == 0)
	{
		return false;
	};

	u16 r1 = transmission_state;

	if (r1 >= word_1876/*1808*/ || r1 <= word_1878/*603*/)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_178D0()
{
	if ((IGN_FLAG9_FFFF8BB6 & IGN_F9_04) || word_FFFF8BF4 != 0)
	{
		u16 r1;

		if (byte_1077/*0*/ != 0)
		{
			r1 = word_FFFF8C90;
		}
		else
		{
			Table_Lookup_Axis(LOAD9_65DC);

			r1 = Table_Lookup_byte_2D_3D((MUT21_RPM_x125div4 >= word_2B64) ? unk032_588E : unk033_589E);
		};

		Table_Lookup_Axis(BAR4_66F6);

		u16 r2 = Table_Lookup_byte_2D_3D(unk115_58AE);

		__disable_irq();

		word_FFFF8BFA = Lim_FF(Mul_Div_R(r1, r2 * Table_Lookup_byte_2D_3D(unk116_58B8), 0x4000));

		__enable_irq();

	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_179B0()
{
	CLR(IGN_FLAG9_FFFF8BB6, IGN_F9_08);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//static bool IG04_sub_179C4()
//{
//	return false;
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17A3A()
{
	CLR(IGN_FLAG9_FFFF8BB6, IGN_F9_1000);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17A4E()
{
	WFLAG(BOOSTCHECK2_FFFF8A0E, 0x1000, IG04_sub_17A7E());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17A7E()
{
	if ((RT_FLAG1_FFFF8888 & RT_7_bit) || (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) == 0)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 <= word_2338/*28(875)*/ || MUT21_RPM_x125div4 > word_2336/*48(1500)*/)
	{
		return false;
	};

	if (wMUT2E_Vehicle_Speed_Frequency < word_2346/*10*/)
	{
		return false;
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_233E/*90*/)
	{
		return false;
	};

	if (transmission_state > word_233C/*7234*/ || transmission_state < word_233A/*2261*/)
	{
		return false;
	};

	if (load_ECU_Ignintion <= word_234A/*54*/ || load_ECU_Ignintion > word_2348/*135*/)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17B9A()
{
	WFLAG(wMUT1E_MAF_RESET_FLAG, TIMING_KNOCKDOWN, (wMUTD1_BitMap_FAA & FAA_10_KNOCK_LIGHT) && IG04_sub_17BEC()); // timing knockdown on light acceleration and less than 3000rpm
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17BEC()
{
	if (RT_FLAG1_FFFF8888 & RT_7_bit)
	{
		return false;
	};

	if ((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) == 0 && byte_1074/*0*/ == 0)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 >= word_1838/*128*/)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 <= word_183A/*0*/)
	{
		return false;
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_1840/*40*/)
	{
		return false;
	};

	if (wMUT2E_Vehicle_Speed_Frequency <= word_1A54/*10*/)
	{
		return false;
	};

	if (wMUT22_ISCV & M22_SPEED_ADJUST)
	{
		return false;
	};

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		return false;
	};

	if (transmission_state >= word_183C/*3288*/)
	{
		return false;
	};

	if (transmission_state <= word_183E/*0*/)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17C6E()
{
	WFLAG(IGN_FLAG9_FFFF8BB6, IGN_F9_10, IG04_sub_17C9C())
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17C9C()
{
	TRG(IGN_FLAG9_FFFF8BB6, IGN_F9_02, MUT21_RPM_x125div4, word_17B4/*58(1812)*/, word_17B2/*64(2000)*/);

	if (ZRO(RT_FLAG1_FFFF8888, RT_7_bit))
	{
		return false;
	};

	if (IGN_FLAG9_FFFF8BB6 & IGN_F9_02)
	{
		return false;
	};

	if (wMUT22_ISCV & M22_SPEED_ADJUST)
	{
		return false;
	};

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL|FUEL_CUT))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17D04()
{
	if (byte_1064/*0*/ != 0 && (wMUT1E_MAF_RESET_FLAG & STALL) == 0)
	{
		u16 rpm, load;

		if (IGN_FLAG9_FFFF8BB6 & IGN_F9_2000)
		{
			rpm = word_18A6/*64*/;
			load = word_18AA/*137*/;
		}
		else
		{
			rpm = word_18A8/*58*/;
			load = word_18AC/*88*/;
		};

		if (wMUT2E_Vehicle_Speed_Frequency >= word_18B4/*12*/)
		{
			SET(IGN_FLAG9_FFFF8BB6, IGN_F9_4000);
		};

		WFLAG(IGN_FLAG9_FFFF8BB6, IGN_F9_2000, coolantTempDuringCranking < word_18B2/*39*/ 
			&& wMUT10_Coolant_Temperature_Scaled < word_18AE/*115*/ 
			&& (IGN_FLAG9_FFFF8BB6 & IGN_F9_4000) == 0 
			&& (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) 
			&& MUT21_RPM_x125div4 < rpm 
			&& load_ECU_Ignintion < load);
	}
	else
	{
		CLR(IGN_FLAG9_FFFF8BB6, IGN_F9_4000|IGN_F9_2000);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 Barometric_Correction_sub_22084()
{
	return IGN_BARO_COMP_FFFF8BD6 = 0x80; //Sub_Lim_0(0x80, 0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_StartIgnInterpolator(u16 tAdv)
{
	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		startIgnInterpolator = (wMUT10_Coolant_Temperature_Scaled > word_24F8/*50(10)*/) ? 0xFF : 0;
	}
	else
	{
		if (timeEvents & EVT_1_50ms)
		{
			startIgnInterpolator = Add_Lim_FFFF(startIgnInterpolator, word_24FA/*6*/);

			if (startIgnInterpolator >= 0xFF)
			{
				startIgnInterpolator = 0xFF;
			};
		};

		tAdv = interpolate_r4_r5_r6(tAdv, 25, startIgnInterpolator);

		if (startIgnInterpolator != 255 && tAdv < 25)
		{
			tAdv = 25;
		};
	};

	return tAdv;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Update_MUT04_Timing_Advance_Interpolated()
{
	Update_MUT33_Corrected_Timing_Advance();

	u16 tAdv = wMUT33_Corrected_Timing_Advance;

	if ((IGN_FLAG9_FFFF8BB6 & IGN_F9_2000) && tAdv >= (word_18B0/*10*/+20))
	{
		tAdv = word_18B0/*10*/ + 20;
	};

	//+++++++++++++++++++++

	{
		u16 ldfc = IG04_Lim_Deceleration_Fuel_Cut();

		if (byte_1052/*1*/ != 0)
		{
			u16 t = IG04_sub_18570();

			if (ldfc >= t)
			{
				ldfc = t;
			};
		};

		tAdv = ((ldfc > tAdv) ? tAdv : ldfc) + 0x8000;

		//+++++++++++++++++++++

		u16 t1 = IG04_sub_1859E();

		u16 t2 = IG04_useless_sub_185EA();

		tAdv += ((t1 >= t2) ? t1 : t2) - 0x80;

		tAdv += IG04_Airtemp_Ignition_Compensation_sub_185FC() - 0x80;

		tAdv += IG04_sub_1876E() - 0x80;

		tAdv += Barometric_Correction_sub_22084() - 0x80;

		tAdv += IG04_RPM_CORR_sub_18952() - 0x80;

		//+++++++++++++++++++++

		if (Some_IGN_RES_FFFF8BD2 < 0x80)
		{
			u16 x = word_17B8/*0*/ + 0x8000;

			if (tAdv < x) { tAdv = x; };
		};

		//+++++++++++++++++++++

		tAdv = Sub_Lim_0(tAdv + IG04_SET0x80IGNPAR2_sub_18A1C() - 0x80, 0x8000);
	};

	//+++++++++++++++++++++

	{
		u16 x = IG04_sub_18A2E();

		if (tAdv >= x) { tAdv = x; };
	};

	//+++++++++++++++++++++

	if (IGN_CORR_RPM_FFFF8BD4 != 0x80)
	{
		if (tAdv < word_1852/*0*/)
		{
			tAdv = word_1852/*0*/;
		};
	};

	//+++++++++++++++++++++

	if ((IGN_FLAG9_FFFF8BB6 & IGN_F9_FIX5) || (wMUT1E_MAF_RESET_FLAG  & (CRANKING|STALL)))
	{
		tAdv = fixTimingValue + 20;
	};

	tAdv = Lim16(tAdv, 0, 70);

	IGNITION_FINAL3_FFFF8C0C = tAdv;

	IG04_UpdateStartIgnInterpolator(); // update startIgnInterpolator

	if ((wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL)) == 0)
	{
		tAdv = interpolate_r4_r5_r6(tAdv, 25, startIgnInterpolator);

		if (startIgnInterpolator != 255 && tAdv < 25)
		{
			tAdv = 25;
		};
	};

	wMUT04_Timing_Advance_Interpolated = tAdv;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Update_MUT33_Corrected_Timing_Advance()
{
	u16 t = IG04_Update_OctanEgrIgnTiming();

	t = IG04_Ign_Temp_Correct(t);

	t = IG04_IGNIT_TESTS_183E8(t);

	wMUT33_Corrected_Timing_Advance = IG04_sub_21DCE(t);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 Lookup_HiIgnMap()
{
	return ((u32)(Table_Lookup_word_2D_3D(HighIgn_7C48[hiIgnMapIndex&7]) + 0x80)) >> 8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 GetLoadCorrectedDeltaTPS()
{
	return load_x2_deltaTPS_corrected = ECU_Load_x2_FFFF895C + Mul_Fix8_R(abs_Delta_TPS * TPS_Multiplier_Delta, Table_Lookup_byte_2D_3D(table_2D_39D2));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_Update_OctanEgrIgnTiming()
{
	wMUTB4_lookup_value = GetLoadCorrectedDeltaTPS();

	Table_Lookup_Axis(RPM21_6788_IGN);

	Table_Lookup_Axis(LOAD12_67BC_IGN);

	ignition_FFFF8BC4 = egrHighOctIgn = Lookup_HiIgnMap();

	return octanEgrIgnTiming = interpolate_r4_r5_r6(egrHighOctIgn, egrLowOctIgn = Query_byte_2D_3D_Table(LowIgn_7C68), (no_knock_retard != 0) ? 255 : wMUT27_Octane_Number);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_Update_OctanEgrIgnTiming_stock()
{
	register u16 loIgn, /*ignAdd,*/ hiIgn, octIgn, ign; 

	wMUTB4_lookup_value = GetLoadCorrectedDeltaTPS();

	Table_Lookup_Axis(RPM21_6788_IGN);

	Table_Lookup_Axis(LOAD12_67BC_IGN);

	loIgn = Query_byte_2D_3D_Table(LowIgn_7C68);

	if (ZERO_8_IGNITION_FLAGS & 8)
	{
		egrLowOctIgn = Add_Lim_FFFF(loIgn, Table_Lookup_byte_2D_3D(HIOCTIGNEGR_38CA));
	}
	else
	{
		egrLowOctIgn = loIgn;
	};

	if (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN)
	{
		hiIgn = Query_byte_2D_3D_Table((Map3D_B**)HighIgn_7C48);

		if (ZERO_8_IGNITION_FLAGS & 8)
		{
			egrHighOctIgn = Add_Lim_FFFF(hiIgn, Table_Lookup_byte_2D_3D(HIOCTIGNEGR_38CA));
		}
		else
		{
			egrHighOctIgn = hiIgn;
		};

		octIgn = interpolate_r4_r5_r6(egrHighOctIgn, egrLowOctIgn, wMUT27_Octane_Number);

		ign = hiIgn;
	}
	else
	{
		octIgn = egrLowOctIgn;

		ign = loIgn;
	};

	octanEgrIgnTiming = octIgn;

	ignition_FFFF8BC4 = Lim_FF(Sub_Lim_0(ign + Query_byte_2D_3D_Table(LOWOCTIGNEGR_7AC8), 128));

	return octanEgrIgnTiming;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// stock version

//static u16 GetLoadCorrectedDeltaTPS()
//{
//	return load_x2_deltaTPS_corrected = IG04_GetLoad_sub_1821E() /*ECU_Load_x2_FFFF895C*/ + Mul_Fix8_R(abs_Delta_TPS * TPS_Multiplier_Delta, Table_Lookup_byte_2D_3D(table_2D_39D2));
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// stock version

//static u16 	IG04_GetLoad_sub_1821E()
//{
//	return ECU_Load_x2_FFFF895C;
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define w_1822E_loc1		(*(u16*)0xFFFF86F6)
//#define w_1822E_loc2		(*(u16*)0xFFFF86BE)
//#define w_1822E_loc3		(*(u16*)0xFFFF8C88)
//#define w_1822E_loc4		(*(u16*)0xFFFF8C8A)


static u16 IG04_Ign_Temp_Correct(u16 v)
{

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		w_1822E_loc3 = 0xff;
	}
	else if ((RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888) & RT_FLAG1_COPY_FFFF888A & RT_7_bit)
	{
		w_1822E_loc1 = word_20B0/*20*/;
		w_1822E_loc3 = 0;
	}
	else if (w_1822E_loc1 != 0)
	{
		w_1822E_loc2 = word_20B4/*1*/ * 2;
	}
	else if (w_1822E_loc2 == 0)
	{
		w_1822E_loc2 = word_20B4/*1*/ * 2;
		w_1822E_loc3 = Lim_FF(w_1822E_loc3 + word_20B2/*13*/);
	};

	w_1822E_loc4 = 0;

	u16 r13 = 0;

	if (w_1822E_loc4 == 0
		&& (wMUTD1_BitMap_FAA & FAA_9_WARMUP_RETARD) // Enable Warmup Ign Retard
		&& cranking_end_timer_up >= word_1836)
	{
		Table_Lookup_Axis(CEL8_6914);

		u16 r3 = Table_Lookup_byte_2D_3D((byte_105A/*0*/ != 0 && airTempDuringCranking < word_207A/*22*/ && coolantTempDuringCranking < word_207C/*25*/) ? LOWTRMTEMPCOOL_3A30 : LOWTRMTEMPCOOL_3A30);

		r13 = (byte_1060/*0*/ != 0 && r3 >= w_1822E_loc3) ? w_1822E_loc3 : r3;
	};

	r13 = interpolate_r4_r5_r6(ignition_FFFF8BC4, v, r13);

	if (v >= r13)
	{
		v = r13;
	};

	return coolTempCorrectedIgnTiming = v;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_IGNIT_TESTS_183E8(u16 v)
{
	u16 r = v;

	if (IGN_TEST_FLAG_1044 && IG04_sub_18464() && r >= 20)
	{
		 r = 20 + Mul_Fix7_R(r - 20, (IGN_MULT_FLAG_FFFF8DBC & 0x40) ? t1_1B08/*0*/ : word_1B0A/*64*/);
	};

	if (r >= v)
	{
		r = v;
	};

	return r;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_18464()
{
	if (RT_FLAG1_FFFF8888 & STARTER)
	{
		return false;
	};

	if (starter_timer_up < word_1B02)
	{
		return false;
	};

	if ((IGN_MULT_FLAG_FFFF8DBC & 0x23) != 0x23)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_Lim_Deceleration_Fuel_Cut()
{
	if ((wMUT1E_MAF_RESET_FLAG & STALL) || MUT20_RPM_Idle_x125div16 < word_17C6 || wMUT73_TPS_Open_Delta >= asyncAccelMinTPS_Delta || wMUT56_MAX_MAP_FALL_CHANGE >= word_17C4)
	{
		__disable_irq();

		ign_lim_dec_fuel_cut = 0x80;

		__enable_irq();
	};

	if (((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) || byte_1075/*0*/ != 0) && (wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT))
	{
		u16 r1 = word_17BE/*0*/ + 20;

		u16 r2 = Sub_Lim_0(wMUT33_Corrected_Timing_Advance, word_17BC/*13*/);

		__disable_irq();

		ign_lim_dec_fuel_cut = (r2 >= r1) ? r2 : r1;

		IGN_0xA_FFFF8BE8 = word_17C0/*15*/;

		__enable_irq();
	};

	return ign_lim_dec_fuel_cut;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_sub_18570()
{
	timer_up_useless_IGN_BOOL_FLAG2_FFFF8530 = (IGN_FLAG1_FFFF85B8 != 0) ? -1 : 0;

	return IGNP_FFFF8C06 = 128;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_sub_1859E()
{
	u16 r = 0x80;

	if ((IGN_FLAG9_FFFF8BB6 & IGN_F9_2000) == 0)
	{
		//Map3D_B *t;

		//if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)
		//{
		//	Table_Lookup_Axis(CEL8_79AE);
		//	t = AFRAIRTEMP1_630A;
		//}
		//else
		//{
		//	Table_Lookup_Axis(CEL8_79AE);
		//	t = AFRAIRTEMP1_630A;
		//};

		//r = Table_Lookup_byte_2D_3D(t);
		
		Table_Lookup_Axis(CEL8_79AE);
		r = Table_Lookup_byte_2D_3D(AFRAIRTEMP1_630A);
	};

	return word_FFFF8BCC = r;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_useless_sub_185EA()
{
	return word_FFFF8BCE = 128;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_Airtemp_Ignition_Compensation_sub_185FC()
{
	u16 r1 = 0x80;

	if (load_ECU_Ignintion > Table_Lookup_byte_2D_3D(IGNTRMAIRTEMPLOAD_3A1E))
	{
		r1 = Table_Lookup_byte_2D_3D(IGNTRMAIRTEMP_3A04);
	};

	if (ZERO_8_IGNITION_FLAGS & 2)
	{
		r1 = Sub_Lim_0(r1, t1_unk_1758);
	};

	if (IGN_FLAG9_FFFF8BB6 & IGN_F9_100)
	{
		r1 = Sub_Lim_0(r1, word_1868);
	};

	if (byte_1034/*0*/ != 0 && load_ECU_Ignintion >= word_1854 && wMUT10_Coolant_Temperature_Scaled >= CTEMPER38_1858)
	{
		r1 = Sub_Lim_0(r1, (wMUT10_Coolant_Temperature_Scaled >= CTEMPER39_1856) ? word_185A : word_185C);
	};

	if (IG04_sub_18728())
	{
		r1 = Sub_Lim_0(r1, word_21A0);
	};


	return word_FFFF8BD0 = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_18728()
{
	TRG(IGN_FLAG9_FFFF8BB6, IGN_F9_8000, MUT21_RPM_x125div4, word_2196/*70(2187)*/, word_2198/*70(2187)*/);

	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_sub_1876E()
{
	u16 r1 = 0x80;

	if (IGN_FLAG9_FFFF8BB6 & IGN_F9_10)
	{
		r1 = Mul_Fix7_R(wMUT24_Target_Idle_RPM, word_17B6/*0*/);

		u16 r8 = 0;

		u16 r2 = ((RPM_x_4_096__1 >> 3) + 1) >> 1;

		if (r1 < r2) { r1 = r2; };

		u16 absdeltarpm;  
		
		if (r1 >= rpm_x125div32_B)
		{
			absdeltarpm = r1 - rpm_x125div32_B;
		}
		else
		{
			absdeltarpm = rpm_x125div32_B - r1;
			r8 = 1;
		};

		u16 r13 = Mul_Fix8_R((wMUT2E_Vehicle_Speed_Frequency > word_262C/*40*/) ? word_262A/*20*/ : word_17A8/*128*/, absdeltarpm);

		if (r13 > word_17AA/*8*/)
		{
			r13 = word_17AA/*8*/;
		};

		r1 = (r8 != 0) ? Sub_Lim_0(0x80, r13) : Lim_FF(r13 + 0x80);
	}
	else
	{
		if (BOOSTCHECK2_FFFF8A0E & 0x1000)
		{
			u16 drpm = Sub_Lim_0(rpm_x125div32_B, ((RPM_x_4_096__3 >> 3) + 1) >> 1);

			if (drpm > word_2342/*1*/)
			{
				r1 = Sub_Lim_0(0x80, Mul_Fix8_R(word_2344/*80*/, drpm));
			};
		}
		else if (wMUT1E_MAF_RESET_FLAG & TIMING_KNOCKDOWN) // timing knockdown on light acceleration and less than 3000rpm
		{
			u16 drpm = Sub_Lim_0(rpm_x125div32_B, ((RPM_x_4_096__2 >> 3) + 1) >> 1);

			if (drpm > word_1844/*16*/)
			{
				r1 = Sub_Lim_0(0x80, Mul_Fix8_R(word_1846/*80*/, drpm));
			};
		};
	};

	return Some_IGN_RES_FFFF8BD2 = sub_21E14(r1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_RPM_CORR_sub_18952()
{
	u16 r13 = 0x80;

	if (byte_1035/*1*/ != 0 && cranking_end_timer_up < word_184A && wMUT10_Coolant_Temperature_Scaled >= CTEMPER40_1848 

		&& (RT_FLAG1_FFFF8888 & RT_7_bit))
	{
		u16 r3 = Mul_Fix8_R(Sub_Lim_0(rpm_x125div32_B, word_184C), word_1850);

		r13 = (r3 >= word_184E) ? word_184E : r3;

		r13 = Sub_Lim_0(0x80, r13);
	};

	return IGN_CORR_RPM_FFFF8BD4 = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_SET0x80IGNPAR2_sub_18A1C()
{
	return IGN_PAR2_FFFF8BF0 = 128;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_sub_18A2E()
{
	if ( byte_1037/*0*/ == 0 
		|| (wMUT1E_MAF_RESET_FLAG & STALL)
		|| load_ECU_Ignintion < word_188A 
		|| load_ECU_Ignintion > word_1888 
		|| MUT21_RPM_x125div4 < word_188E 
		|| MUT21_RPM_x125div4 > word_188C 
		|| (RT_FLAG1_FFFF8888 & RT_7_bit) == 0)
	{
		__disable_irq();

		word_FFFF8BEA = 0x80;

		__enable_irq();
	}
	else if ((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) 
			&& wMUT10_Coolant_Temperature_Scaled >= word_1890 
			&& (RT_FLAG1_FFFF8888 & RACING)
			&& Sub_Lim_0(RPM_DELTA_per_100ms, 0x80) >= word_1892)
	{
		__disable_irq();

		word_FFFF8BEC = word_1896;
		word_FFFF8BEA = word_1894;

		__enable_irq();
		
	};

	return word_FFFF8BEA;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_18B48()
{
	timingAdv_75 = Sub_Lim_0(word_178A/*174*/ + 57, Div_WW(wMUT04_Timing_Advance_Interpolated*256, 90));
	word_FFFF96C8 = Sub_Lim_0(word_178A/*174*/ + 57, Div_WW(word_FFFF96CA * 256, 90));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_SetMaxKnockSumControl()
{
	max_Knock_Retard = const_24;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Ignition_coil_charge_sub_18BD4()
{
	Table_Lookup_Axis(VOLT9_66C6);

	ignCoil_MaxCrankDegrees = Table_Lookup_byte_2D_3D(IGNCOILCHGTIME3_3A5E);

	u16 t = Table_Lookup_byte_2D_3D(IGNCOILCHGTIME1_3A3E) * 16;

	if (crankHT_75_4us_3 <= word_17A0/*2679*/)
	{
		t = Sub_Lim_0(t, Mul_Fix8_R(word_17A0 - crankHT_75_4us_3, Table_Lookup_byte_2D_3D(IGNCOILCHGTIME2_3A4E)));
	};

	ignCoilTime_4us = t;

	wMUT2D_Ignition_Battery_Trim = t / 16;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_UpdateTimingMUT()
{
	wMUT06_Timing_Advance = Sub_Lim_0(81, Mul_Fix8_R(timingAdvScaled, 90));

	wMUT05_Timing_Advance_Scaled = wMUT06_Timing_Advance - 20;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_UpdateStartIgnInterpolator()
{
	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		startIgnInterpolator = (wMUT10_Coolant_Temperature_Scaled > word_24F8/*50(10)*/) ? 0xFF : 0;
	}
	else if (timeEvents & EVT_1_50ms)
	{
		startIgnInterpolator = Add_Lim_FFFF(startIgnInterpolator, word_24FA/*6*/);

		if (startIgnInterpolator >= 0xFF)
		{
			startIgnInterpolator = 0xFF;
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma regsave(IG04_sub_18D84)

static void IG04_sub_18D84()
{
	u16 t = word_FFFF8D9E & 7;

	if (t != 0)
	{
		if (t == 1)
		{
			t = 0;
		}
		else if (t == 2)
		{
			t = (word_FFFF8DA0 & 0x60) ? 2 : 1;
		}
		else 
		{
			t = (word_FFFF8DA0 & 0x60) ? 4 : 3;
		};

		u16 t1 = unk119_59DE[t];
		u16 t2 = unk120_59F2[t];
		u16 t3 = unk121_59F8[t];

		Table_Lookup_Axis(LOAD9_65DC);

		t = Table_Lookup_byte_2D_3D((t != 0) ? unk118_59CE : unk033_589E);

		__disable_irq();

		word_FFFF8BF4 = t1;

		word_FFFF8C8E = t2;

		word_FFFF8C8C = t3;

		__enable_irq();

		word_FFFF8C90 = t;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_sub_21DCE(u16 v)
{
	if (IGN_TEST_FLAG_0_F32 == 1)
	{
		return Sub_Lim_0(((u32)wMUT9D_IGN_ADDITION >> 1) + v, 0x40);
	}
	else if (IGN_TEST_FLAG_0_F32 == 2)
	{
		return wMUT9D_IGN_ADDITION;
	}
	else
	{
		return v;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//static u16 Barometric_Correction_sub_22084()
//{
//	return IGN_BARO_COMP_FFFF8BD6 = Sub_Lim_0(0x80, 0);
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


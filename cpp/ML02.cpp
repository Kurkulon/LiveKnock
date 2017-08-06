#pragma section _ML02

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
//#include "EnVars.h"

//#undef F500_Init_Load_ECU_Info_And_BitMap_Flags
//
//#define sub_A374			((void(*)(void))0xA374)
//#define F500_Get_All_ADC	((void(*)(void))0xA7F0)
//#define F500_sub_21C80		((bool(*)(void))0x21C80)
//
//#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)






//#define CEL8_685C							((Axis*)0x685C)
//#define CEL9_6876							((Axis*)0x6876)
//#define CEL10_68B2							((Axis*)0x68B2)
//#define CEL12_68D0							((Axis*)0x68D0)
//#define CEL8_6D98							((Axis*)0x6D98)
//#define CEL9_75BA							((Axis*)0x75BA)
//#define BAR5_6D66							((Axis*)0x6D66)
//#define LOAD9_65C0							((Axis*)0x65C0)
//#define RPM11_64AC							((Axis*)0x64AC)
//#define LOAD9_65F8							((Axis*)0x65F8)
//#define mapInletAirTemp_Scaling				((Axis*)0x9B82)
//#define CEL7_692E							((Axis*)0x692E)
//#define map_Coolant_Temp_Scaling			((Axis*)0x99A8)








//#define AFRRPM_4C1A							((Map3D_B *)0x4C1A)
//#define AIRTEMPCOMPAFR1_33C4				((Map3D_B *)0x33C4)
//#define AIRTEMPCOMPAFR1_45D8				((Map3D_B *)0x45D8)
//#define LOADAFR_33B4						((Map3D_B *)0x33B4)
//#define TPS_2D_3ED6							((Map3D_B *)0x3ED6)
//#define MAP_2D_3EE8							((Map3D_B *)0x3EE8)
//#define byte_9B00							((Map3D_B *)0x9B00)
//#define CORFUELAIR_33A6						((Map3D_B *)0x33A6)
//#define COOLTEMSCAL_98FA					((Map3D_B *)0x98FA)

static void SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG();
static void ML02_root_sub_1123E();
static void ML02_sub_11300();
static void ML02_sub_11332();
static void ML02_sub_11390();
static bool ML02_sub_113C6();
static void ML02_sub_114B4();
static bool ML02_sub_114E2();
static void ML02_sub_11528();
static void ML02_sub_11570();
static void ML02_sub_118B0();
static void ML02_sub_118E2();
static void ML02_sub_11910();
static void ML02_Return_0();
static void ML02_sub_119DC();
static void ML02_sub_11A4E();
static void ML02_sub_11A98();
static void ML02_sub_11AEC();
static void ML02_sub_11B36();
static void ML02_sub_11B74();
static void ML02_sub_11D48();
static void ML02_sub_11D82();
static void ML02_sub_11DBA();
static void ML02_sub_11E00();
static void ML02_sub_11E14();
static void ML02_sub_11EE8();
static void ML02_sub_11F88();
static void ML02_sub_11FD8();
static bool ML02_Check_STALL();
static void ML02_Check_12030();
static bool ML02_Check_CRANKING();
static void ML02_sub_12180();
static void ML02_Return_0_0();
static void ML02_sub_1228C();
static void ML02_sub_122BA();
static void ML02_SPEED_LIM_sub_12316();
static void ML02_W2D();
static void ML02_sub_123E0();
static void ML02_sub_124AE();
static void ML02_sub_1262C();
static void ML02_sub_1268C();
static void ML02_O2_Closed_Loop();
static void ML02_O2_Heater_Tests();
static void ML02_Open_And_Closed_Loop_Calcs();
static void ML02_Open_andor_Closed_Loop_Fuel_Calcs();
static void ML02_Open_Loop_Calc();
static void ML02_sub_12BC0();
static void ML02_Closed_Loop_Error();
static void ML02_Open_Closed_Loop_Some_Check();
static void ML02_MAP_Change_Calcs();
static void ML02_sub_12D9C();
static void ML02_sub_13088();
static void ML02_sub_130BC();
static void ML02_sub_13120();
static void ML02_sub_131EC();
static void ML02_sub_13320();
static void ML02_sub_13398();
static void ML02_sub_133BC();
static void ML02_sub_1359C();
static void ML02_sub_13602();
static void ML02_sub_1364C();
static void ML02_sub_1376C();
static void ML02_Fuel_Knock_Reaction();
static void ML02_sub_139A8();
static void ML02_sub_139C4();



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG()
{
	wMUT1E_MAF_RESET_FLAG = STALL;

	word_FFFF8A16 = 0xFFFF;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_root_sub_1123E()
{
	ML02_sub_11300();                    
	ML02_sub_11332();                    
	ML02_sub_11390();                    
	ML02_sub_114B4();                    
	ML02_sub_11528();                    
	ML02_sub_11570();                    
	ML02_sub_118B0();                    
	ML02_sub_118E2();                    
	ML02_sub_11A98();                    
	ML02_sub_11AEC();                    
	ML02_sub_11B36();                    
	ML02_sub_11D82();   

	ML02_sub_11E00();
	ML02_sub_11E14();
	ML02_sub_11EE8();
	ML02_sub_11F88();

	if (wMUTD1_BitMap_FAA & 2/*rear oxigen*/)
	{
		ML02_sub_13398();
	};

	ML02_sub_139A8();
	ML02_sub_139C4();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11300()
{
	prev_MUT1E_FLAGS = wMUT1E_MAF_RESET_FLAG;

	word_FFFF89FA = word_FFFF89F6;

	prev_MUT18_Open_Loop_Bit_Array = wMUT18_Open_Loop_Bit_Array;

	prev_MUT59 = wMUT59;

	prev_FUEL_CUT_FLAG_FFFF8A5E = FUEL_CUT_FLAG_FFFF8A5E;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11332()
{
	if (byte_105B == 0 || (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 4))
	{
		CLR(LAUNCH_TEST_FLAG_2_FFFF822E, 0x400);

		word_FFFF8830 = word_20D8;
	}
	else if (MUT21_RPM_x125div4 <= word_20DA/*64(2000)*/ || wMUT1C_ECU_Load <= word_20DC/*150(75)*/)
	{
		word_FFFF8830 = word_20D8;
	}
	else if (word_FFFF8830 == 0)
	{
		SET(LAUNCH_TEST_FLAG_2_FFFF822E, 0x400);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11390()
{
	if (byte_102C != 0 && ML02_sub_113C6())
	{
		SET(wMUT19_Startup_Check_Bits, 0x40);
	}
	else
	{
		CLR(wMUT19_Startup_Check_Bits, 0x40);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_113C6()
{
	TRG(wMUT19_Startup_Check_Bits, 0x800, wMUT2E_Vehicle_Speed_Frequency, word_19B2/*255*/, word_19B0/*255*/);

	return (wMUT19_Startup_Check_Bits & 0x800) && (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x8000) && (portA_state & 0x1000) && (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x20);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_114B4()
{
	if (ML02_sub_114E2())
	{
		SET(IGN_FLAG9_FFFF8BB6, 1);
	}
	else
	{
		CLR(IGN_FLAG9_FFFF8BB6, 1);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_114E2()
{
	return (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 2) 
		&& ZRO(wMUT1E_MAF_RESET_FLAG, STALL|CRANKING) 
		&& MUT21_RPM_x125div4 < word_182E/*0*/ 
		&& wMUT14_Battery_Level_ADC8bit > word_1834 
		&& wMUT14_Battery_Level_ADC8bit < word_1832;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11528()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11570()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_118B0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_118E2()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11910()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Return_0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_119DC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11A4E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11A98()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11AEC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11B36()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11B74()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11D48()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11D82()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11DBA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11E00()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11E14()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11EE8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11F88()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11FD8()
{
	if (ML02_Check_STALL())
	{
		SET(wMUT1E_MAF_RESET_FLAG, STALL);
	}
	else
	{
		CLR(wMUT1E_MAF_RESET_FLAG, STALL);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_Check_STALL()
{
	return ZRO(prev_MUT1E_FLAGS, 0x20) || (timer_FFFF8592 == 0) || (timer_down_TXFLAG3_FFFF8574 == 0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Check_12030()
{
	if (ML02_Check_CRANKING())
	{
		SET(wMUT1E_MAF_RESET_FLAG, CRANKING);
	}
	else
	{
		CLR(wMUT1E_MAF_RESET_FLAG, CRANKING);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_Check_CRANKING()
{
	bool res = false;

	if (prev_MUT1E_FLAGS & STALL)
	{
		if (wMUT10_Coolant_Temperature_Scaled <= word_1530/*50(10)*/)
		{
			FUEL_CUT_FLAG_FFFF8A5E |= 0x2000;
		}
		else
		{
			FUEL_CUT_FLAG_FFFF8A5E &= ~0x2000;
		};
	};

	if (wMUT10_Coolant_Temperature_Scaled < word_1556/*22(-18)*/)
	{
		FUEL_CUT_FLAG_FFFF8A5E |= 0x1000;
	}
	else
	{
		FUEL_CUT_FLAG_FFFF8A5E &= ~0x1000;
	};

	if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x40)
	{
		u32 rpm = word_152A/*15(468)*/;

		if ((SPEED_FLAGS & 4) == 0)
		{
			rpm = word_2180/*15(468)*/;

			if ((prev_MUT1E_FLAGS & 1) == 0)
			{
				rpm = word_217E/*13(406)*/;
			};

			if (FUEL_CUT_FLAG_FFFF8A5E & 0x2000)
			{
				rpm += word_2182/*3(93)*/;
			};
		}
		else
		{
			if ((prev_MUT1E_FLAGS & 1) == 0)
			{
				rpm = word_1526/*13(406)*/;
			};

			if (FUEL_CUT_FLAG_FFFF8A5E & 0x2000)
			{
				rpm += word_152E/*3(93)*/;
			};

		};

		res = (MUT21_RPM_x125div4 < rpm);

		if ((prev_MUT1E_FLAGS & 1) && !res)
		{
			coolant_temp_FFFF8038 = wMUT10_Coolant_Temperature_Scaled;
		};

	};

	return res;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_12180()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Return_0_0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1228C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_122BA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_SPEED_LIM_sub_12316()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_W2D()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_123E0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_124AE()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1262C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1268C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_O2_Closed_Loop()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_O2_Heater_Tests()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Open_And_Closed_Loop_Calcs()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Open_andor_Closed_Loop_Fuel_Calcs()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Open_Loop_Calc()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_12BC0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Closed_Loop_Error()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Open_Closed_Loop_Some_Check()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_MAP_Change_Calcs()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_12D9C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13088()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_130BC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13120()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_131EC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13320()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13398()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_133BC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1359C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13602()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1364C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1376C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Fuel_Knock_Reaction()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_139A8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_139C4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


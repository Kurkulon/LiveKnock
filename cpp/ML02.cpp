#pragma section _ML02

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"

//#undef F500_Init_Load_ECU_Info_And_BitMap_Flags

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define sub_A374			((void(*)(void))0xA374)
//#define F500_Get_All_ADC	((void(*)(void))0xA7F0)
#define sub_21D9C		((bool(*)(void))0x21D9C)

#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define RPMINGD_32DC					((const byte*)0x32DC)
#define byte_32EE						((const byte*)0x32EE)
#define unk113_524E						((const byte*)0x524E)

//#define byte_32F2						(*(const byte*)0x32F2)
//#define byte_32F3						(*(const byte*)0x32F3)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define off_7136							((Axis*)0x7136)
#define RPM13_64CC							((Axis*)0x64CC)
#define RPM14_79C8							((Axis*)0x79C8)
#define CEL13_6614							((Axis*)0x6614)







//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define unk007_32E0							((Map3D_B *)0x32E0)
#define OPLOPLOAD1_6318						((Map3D_B *)0x6318)
#define OPLOPLOAD2_632C						((Map3D_B *)0x632C)
#define OPENLOOPLOV_332E					((Map3D_B *)0x332E)
#define OPENLOOPHIV_3342					((Map3D_B *)0x3342)

#define STFUELTRIM1_41D4					((Map3D_B *)0x41D4)
#define  STFUELTRIM_3356					((Map3D_B *)0x3356)

#define AFRTOCOOL2_366C						((Map3D_B *)0x366C)
#define AFRTOCOOL3_3680						((Map3D_B *)0x3680)
#define AFRTOCOOL4_3694						((Map3D_B *)0x3694)
#define AFRTOCOOL1_3658						((Map3D_B *)0x3658)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define off_7B08							((Map3D_B**)0x7B08)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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
static bool ML02_Return_0();
static bool ML02_sub_119DC();
static bool ML02_sub_11A4E();
static void ML02_sub_11A98();
static void ML02_sub_11AEC();
static void ML02_sub_11B36();
static bool ML02_sub_11B74();
static bool ML02_sub_11D48();
static void ML02_sub_11D82();
static bool ML02_sub_11DBA();
static void ML02_sub_11E00();
static void ML02_sub_11E14();
static void ML02_sub_11EE8();
static void ML02_sub_11F88();
static void ML02_sub_11FD8();
static bool ML02_Check_STALL();
static void ML02_Check_12030();
static bool ML02_Check_CRANKING();
static void ML02_sub_12180();
static bool ML02_Return_0_0();
static bool ML02_sub_1228C();
static bool ML02_sub_122BA();
static bool ML02_SPEED_LIM_sub_12316();
static bool ML02_W2D(bool);
static u16 ML02_Get_Idle_RPM_lim_123E0();
static bool ML02_sub_124AE(u16 rpm);
static bool ML02_sub_1262C(u16 rpm);
static void ML02_sub_1268C();
static void ML02_O2_Closed_Loop();
static void ML02_O2_Heater_Tests();
static void ML02_Open_And_Closed_Loop_Calcs();
static void ML02_Open_andor_Closed_Loop_Fuel_Calcs();
static void ML02_Open_Loop_Calc();
static bool ML02_sub_12BC0();
static void ML02_Closed_Loop_Error();
static bool ML02_Open_Closed_Loop_Some_Check();
static void ML02_MAP_Change_Calcs();
static void ML02_sub_12D9C(EnVars* ev);
static void ML02_sub_13088(EnVars* ev);
static bool ML02_sub_130BC(EnVars* ev);
static void ML02_sub_13120();
static void ML02_sub_131EC();
static void ML02_sub_13320();
static void ML02_sub_13398();
static void ML02_sub_133BC();
static bool ML02_sub_1359C(EnVars* ev);
static bool ML02_sub_13602();
static void ML02_sub_1364C(EnVars* ev);
static void ML02_sub_1376C(EnVars* ev);
static void ML02_Fuel_Knock_Reaction(EnVars* ev);
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

	if (wMUTD1_BitMap_FAA & FAA_1_REAR_O2/*rear oxigen*/)
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
	if (byte_105B == 0 || (RT_FLAG1_FFFF8888 & RACING))
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

	return (wMUT19_Startup_Check_Bits & 0x800) && (RT_FLAG1_FFFF8888 & RT_15_bit) && (portA_state & 0x1000) && (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_114B4()
{
	if (ML02_sub_114E2())
	{
		SET(IGN_FLAG9_FFFF8BB6, IGN_F9_01);
	}
	else
	{
		CLR(IGN_FLAG9_FFFF8BB6, IGN_F9_01);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_114E2()
{
	return (RT_FLAG1_FFFF8888 & RT_1_bit) 
		&& ZRO(wMUT1E_MAF_RESET_FLAG, STALL|CRANKING) 
		&& MUT21_RPM_x125div4 < word_182E/*0*/ 
		&& wMUT14_Battery_Level_ADC8bit > word_1834 
		&& wMUT14_Battery_Level_ADC8bit < word_1832;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11528()
{
	u32 r13 = 0;

	if (wMUT19_Startup_Check_Bits & 0x10)
	{
		r13 = 1;
	};

	if (ZRO(RT_FLAG1_FFFF8888, RT_5_ALWAYS_1))
	{
		r13 +=2;
	};

	if (MUT21_RPM_x125div4 >= RPMINGD_32DC[r13])
	{
		SET(wMUT19_Startup_Check_Bits, 0x10);
	}
	else
	{
		CLR(wMUT19_Startup_Check_Bits, 0x10);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11570()
{
	u32 r13 = 0;

	if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)
	{
		TRG(RPM_FLAGS_FFFF8A00, RPM1125, 	MUT21_RPM_x125div4, word_1608/*34*/, word_160A/*37*/); // 1125 
		TRG(RPM_FLAGS_FFFF8A00, RPM1250, 	MUT21_RPM_x125div4, word_160C/*38*/, word_160E/*41*/); // 1250
		TRG(RPM_FLAGS_FFFF8A00, RPM2125, 	MUT21_RPM_x125div4, word_1610/*64*/, word_1612/*70*/); // 2125

		TRG(RPM_FLAGS_FFFF8A00, LOAD32, 	wMUT1C_ECU_Load, word_1614/*59*/, word_1616/*67*/);	   // 32 kPa
		TRG(RPM_FLAGS_FFFF8A00, LOAD64,		wMUT1C_ECU_Load, word_1618/*121*/, word_161A/*127*/);  // 62 kPa
	}
	else
	{
		TRG(RPM_FLAGS_FFFF8A00, RPM1125, 	MUT21_RPM_x125div4, word_161C/*28*/, word_161E/*31*/); // 938
		TRG(RPM_FLAGS_FFFF8A00, RPM1250, 	MUT21_RPM_x125div4, word_1620/*35*/, word_1622/*38*/); // 1156
		TRG(RPM_FLAGS_FFFF8A00, RPM2125, 	MUT21_RPM_x125div4, word_1624/*58*/, word_1626/*64*/); // 1906

		TRG(RPM_FLAGS_FFFF8A00, LOAD32, 	wMUT1C_ECU_Load, word_1628/*59*/, word_162A/*67*/);	   // 32 kPa
		TRG(RPM_FLAGS_FFFF8A00, LOAD64,		wMUT1C_ECU_Load, word_162C/*127*/, word_162E/*135*/);  // 66 kPa
	};

	// loc_11814


	if (ZRO(RT_FLAG1_FFFF8888, RT_7_bit) || (RPM_FLAGS_FFFF8A00 & RPM1125))
	{
		r13 = 1;
	
		if (RPM_FLAGS_FFFF8A00 & RPM1250)
		{
			r13 = 2;
		};

		if (RPM_FLAGS_FFFF8A00 & RPM2125)
		{
			r13 = 3;
		};

		if (RPM_FLAGS_FFFF8A00 & LOAD32)
		{
			r13 += 3;
		};

		if (RPM_FLAGS_FFFF8A00 & LOAD64)
		{
			r13 += 3;
		};
	};

	// loc_1184E

	if (	((wMUT19_Startup_Check_Bits ^ r13) & 0xF) 
		||	(ZRO(wMUT19_Startup_Check_Bits, 0xF) && timer_FFFF85A4 != 0))
	{
		timer_FFFF85B2 = word_2478/*0*/;
	}
	else if (timer_FFFF85B2 == 0)
	{
		word_FFFF8A4A = r13 & 0xF;
	};

	wMUT19_Startup_Check_Bits = (wMUT19_Startup_Check_Bits & ~0xF) | (r13 & 0xF);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_118B0()
{
	u32 r1 = wMUT19_Startup_Check_Bits & 0xF;

	if (r1 >= 1)
	{
		r1 = 1;
	};

	ERROR_FLAG_FFFF89FE = (ERROR_FLAG_FFFF89FE << 4) | r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_118E2()
{
	ML02_sub_11910();
	
	if (ML02_Return_0());

	ML02_sub_119DC();
	ML02_sub_11A4E();

	CLR(wMUT19_Startup_Check_Bits, 0x700);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11910()
{
	u32 r13 = 0;

	if (transmission_state < word_1A50/*0*/)
	{
		r13 = SPD_6_40;
	};

	if (transmission_state < word_1A4E/*0*/)
	{
		r13 |= SPD_5_20;
	};

	if (transmission_state < word_1A4C/*3958*/)
	{
		r13 |= SPD_4_10;
	};

	if ((SPEED_FLAGS ^ r13 ) & (SPD_6_40|SPD_5_20|SPD_4_10))
	{
		r13 |= SPD_7_80;
	};
	
	const u32 mask = SPD_7_80|SPD_6_40|SPD_5_20|SPD_4_10;

	SPEED_FLAGS = (SPEED_FLAGS & ~mask) | (r13 & mask);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_Return_0()
{
	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_119DC()
{
	if (ZRO(RT_FLAG1_FFFF8888, RT_5_ALWAYS_1) || wMUT73_TPS_Open_Delta >= word_1A58 || rpm_x125div32_B >= (rpm_1A5C/*192*/<<2) 
		|| wMUT2E_Vehicle_Speed_Frequency >= word_1A54/*10*/ || (SPEED_FLAGS & SPD_6_40) || wMUT1C_ECU_Load >= word_1A5A/*255*/)
	{
		timer_FFFF858E = word_1A56/*80*/;
	};

	return timer_FFFF858E == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_11A4E()
{
	u32 r13 = (SPEED_FLAGS & SPD_4_10) ? word_1A56 : timer_FFFF858E;

	if (timer_FFFF8590 < r13)
	{
		timer_FFFF8590 = r13;
	};

	return timer_FFFF8590 == 0 && ZRO(SPEED_FLAGS, SPD_4_10);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11A98()
{
	if (byte_1054/*0*/ != 0 && ZRO(word_FFFF8D74, 0x80) && (wMUT1E_MAF_RESET_FLAG & FUEL_CUT))
	{
		if (ZRO(ZERO_8_IGNITION_FLAGS, 0x80) && (word_FFFF8DA0 & 0x60) == 0x40)
		{
			SET(ZERO_8_IGNITION_FLAGS, 0x80);
		};
	}
	else
	{
		CLR(ZERO_8_IGNITION_FLAGS, 0x80);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11AEC()
{
	u32 r13 = word_FFFF8D9E & 7;
	
	if (byte_1058/*0*/ != 0 && ZRO(word_FFFF8D74, 0x8080) && r13 != 0 && r13 <= word_2080/*2*/)
	{
		SET(ZERO_8_IGNITION_FLAGS, 0x100);
	}
	else
	{
		CLR(ZERO_8_IGNITION_FLAGS, 0x100);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11B36()
{
	if (open_Loop_disable && ML02_sub_11B74())
	{
		SET(FUEL_CUT_FLAG_FFFF8A5E, FCF_40);

		timer_FFFF8596 = word_173A/*80*/;
	}
	else
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, FCF_40);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_11B74()
{
	TRG(FUEL_CUT_FLAG_FFFF8A5E, FCF_10, wMUT1C_ECU_Load, word_1736/*0*/, word_1734/*1*/);

	u32 r0 = Table_Lookup_byte_2D_3D(unk007_32E0);

	u32 r2 = byte_32EE[5]/*5*/ + r0;
	u32 r1 = byte_32EE[4]/*16*/ + r0;

	if (ML02_sub_11D48())
	{
		r1 += word_1564;
		r2 += word_1564;
	};

	r1 = Lim_FF(r1);
	r2 = Lim_FF(r2);

	bool r8 = false;

	if (((open_Loop_disable/*1*/ != 2 && (RT_FLAG1_FFFF8888 & (RT_7_bit|RT_5_ALWAYS_1|AC_SWITCH)) == RT_7_bit) || (open_Loop_disable == 2 && (RT_FLAG1_FFFF8888 & (RT_7_bit|AC_SWITCH)) == RT_7_bit)) && MUT21_RPM_x125div4 > r2)
	{
		if (ZRO(RT_FLAG1_COPY_FFFF888A, RT_7_bit))
		{
			SET(FUEL_CUT_FLAG_FFFF8A5E, FCF_20);
		};

		if (ZRO(FUEL_CUT_FLAG_FFFF8A5E, FCF_10) && cranking_end_timer_up >= (word_1738/*20*/ * 20) && MUT21_RPM_x125div4 <= r1 && (FUEL_CUT_FLAG_FFFF8A5E & FCF_20))
		{
			r8 = true;
		};
	}
	else
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, FCF_20);
	};

	return r8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_11D48()
{
	if (RT_FLAG1_FFFF8888 & RACING)
	{
		return false;
	};

	return (byte_105B/*1*/ == 0 && (SPEED_FLAGS & SPD_3_08)) || (byte_105B/*1*/ != 0 && ZRO(LAUNCH_TEST_FLAG_2_FFFF822E, 0x400));
}	

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11D82()
{
	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_200, (byte_103C/*7*/ & 1) && ML02_sub_11DBA());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_11DBA()
{
	if (ZRO(wMUT1E_MAF_RESET_FLAG, DECELERATION_FUEL_CUT))
	{
		word_FFFF85FC = word_1B9C/*20*/;
	};

	return (ZRO(byte_103C/*7*/, 2) || (RT_FLAG1_FFFF8888 & RT_7_bit)) 
		&& (wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) 
		&& MUT21_RPM_x125div4 >= word_1B98/*64(2000)*/;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11E00()
{
	CLR(SPEED_FLAGS, SPD_2_ALWAYS_0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11E14()
{
	TRG(ZERO_8_IGNITION_FLAGS, 1, wMUT2F_Vehicle_Speed, word_1754/*70(140)*/, word_1752/*75(150)*/);

	if ((bMUTD2_FBA_MAF_MAP_FLAG & 2) && (ZERO_8_IGNITION_FLAGS & 1) && MUT21_RPM_x125div4 > word_1756/*112(3500)*/)
	{
		SET(ZERO_8_IGNITION_FLAGS, 2);
	}
	else
	{
		CLR(ZERO_8_IGNITION_FLAGS, 2);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11EE8()
{
	TRG(word_FFFF8A10, 2, wMUT2F_Vehicle_Speed, word_FFFF947A, word_FFFF947C);

	if (byte_107E/*0*/ != 0 && (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) 
		&& ZRO(wMUT71_Sensor_Error, MUT71_4_bit|MUT71_0_COOLANT) 
		&& (RT_FLAG1_FFFF8888 & RACING) 
		&& ZRO(word_FFFF8A10, 2)
		&& wMUT10_Coolant_Temperature_Scaled < word_2724/*0*/)
	{
		SET(word_FFFF8A10, 4);
	}
	else
	{
		CLR(word_FFFF8A10, 4);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11F88()
{
	ML02_sub_11FD8();
	ML02_Check_12030();
	ML02_sub_12180();
	ML02_sub_1268C();
	ML02_O2_Closed_Loop();
	ML02_sub_13120();
	ML02_sub_131EC();
	ML02_sub_13320();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_11FD8()
{
	WFLAG(wMUT1E_MAF_RESET_FLAG, STALL, ML02_Check_STALL());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_Check_STALL()
{
	return ZRO(prev_MUT1E_FLAGS, MUT1E_5_ALWAYS_1) || (timer_FFFF8592 == 0) || (timer_down_TXFLAG3_FFFF8574 == 0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Check_12030()
{
	WFLAG(wMUT1E_MAF_RESET_FLAG, CRANKING, ML02_Check_CRANKING());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_Check_CRANKING()
{
	bool res = false;

	if (prev_MUT1E_FLAGS & STALL)
	{
		WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_2000, wMUT10_Coolant_Temperature_Scaled <= word_1530/*50(10)*/);
	};

	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_1000, wMUT10_Coolant_Temperature_Scaled < word_1556/*22(-18)*/);

	if (RT_FLAG1_FFFF8888 & STARTER)
	{
		u32 rpm = word_152A/*15(468)*/;

		if ((SPEED_FLAGS & SPD_2_ALWAYS_0) == 0)
		{
			rpm = word_2180/*15(468)*/;

			if ((prev_MUT1E_FLAGS & CRANKING) == 0)
			{
				rpm = word_217E/*13(406)*/;
			};

			if (FUEL_CUT_FLAG_FFFF8A5E & FCF_2000)
			{
				rpm += word_2182/*3(93)*/;
			};
		}
		else
		{
			if ((prev_MUT1E_FLAGS & CRANKING) == 0)
			{
				rpm = word_1526/*13(406)*/;
			};

			if (FUEL_CUT_FLAG_FFFF8A5E & FCF_2000)
			{
				rpm += word_152E/*3(93)*/;
			};

		};

		res = (MUT21_RPM_x125div4 < rpm);

		if ((prev_MUT1E_FLAGS & CRANKING) && !res)
		{
			coolant_temp_FFFF8038 = wMUT10_Coolant_Temperature_Scaled;
		};

	};

	return res;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_12180()
{
	u32 r1 = 0;

	if (ML02_Return_0_0())
	{
		r1 = MUT1E_9_bit|FUEL_CUT;
	};

	if (ML02_sub_1228C())
	{
		r1 |= MUT1E_8_bit|FUEL_CUT;
	};

	if (PEDR_LO_Check_sub_A790())
	{
		r1 |= MUT1E_9_bit|FUEL_CUT;
	};

	if (ML02_SPEED_LIM_sub_12316())
	{
		r1 |= MUT1E_10_bit|MUT1E_9_bit|FUEL_CUT;
	};

	idle_RPM_lim = ML02_Get_Idle_RPM_lim_123E0();

	if (ML02_sub_124AE(idle_RPM_lim))
	{
		r1 |= FUEL_CUT|DECELERATION_FUEL_CUT;
	};

	if (ML02_sub_1262C(idle_RPM_lim))
	{
		r1 |= FUEL_CUT|DECELERATION_FUEL_CUT;
	};

	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x2000) && (word_FFFF80E6 & 0x300))
	{
		CLR(r1, MUT1E_9_bit|MUT1E_8_bit|FUEL_CUT|DECELERATION_FUEL_CUT);
	};

	const u32 mask = MUT1E_14_bit|MUT1E_10_bit|MUT1E_9_bit|MUT1E_8_bit|FUEL_CUT|DECELERATION_FUEL_CUT;

	wMUT1E_MAF_RESET_FLAG = (wMUT1E_MAF_RESET_FLAG & ~mask) | (r1 & mask);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_Return_0_0()
{
	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_1228C()
{
	return starter_timer_up >= word_1586/*80*/ && (wMUT40_Stored_Faults_Lo & 0x80) && ZRO(camShaftFlags, 1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_122BA()
{
	u32 r1 = ECU_Load_x2_FFFF8962;

	Table_Lookup_Axis(off_7136);

	u32 r13 = Query_byte_2D_3D_Table(off_7B08);

	if (r1 > ECU_Load_x2_FFFF895C)
	{
		r1 = ECU_Load_x2_FFFF895C;
	};

	if (ZRO(wMUT1E_MAF_RESET_FLAG, STALL|CRANKING) || r1 < (r13 << 2))
	{
		word_FFFF86A4 = fuelCutLoadTriggerDelay;
	};

	return word_FFFF86A4 == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_SPEED_LIM_sub_12316()
{
	TRG(SPEED_FLAGS, SPD_13_2000, wMUT2F_Vehicle_Speed, SPEEDLIM_157A/*250(500)*/, SPEEDLIM_1578/*255(510)*/);

	if (ZRO(wMUTD1_BitMap_FAA, FAA_6_40))
	{
		return false;
	};
	
	return ML02_W2D((SPEED_FLAGS & SPD_13_2000) && MUT21_RPM_x125div4 <= word_1582/*255*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_W2D(bool v)
{
	return v;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 ML02_Get_Idle_RPM_lim_123E0()
{
	u32 rpm = Table_Lookup_byte_2D_3D(unk007_32E0);
	
	u32 r1 = 0;

	if (ZRO(RT_FLAG1_FFFF8888, RT_7_bit))
	{
		timer_FFFF8788 = word_1562/*1*/;
	};

	if (ZRO(RT_FLAG1_FFFF8888, RT_5_ALWAYS_1))
	{
		r1 = 4;
	}
	else if (SPEED_FLAGS & SPD_2_ALWAYS_0)
	{
		r1 = 2;
	};

	if ((RT_FLAG1_FFFF8888 & AC_SWITCH) || word_FFFF8CCC != 0)
	{
		r1 += 6;
	};

	if ((wMUT23 & 0x20) || timer_FFFF8788 != 0 || ZRO(RPM_FLAGS, RPM_14_bit))
	{
		if (prev_MUT1E_FLAGS & DECELERATION_FUEL_CUT)
		{
			r1 += 1;
		};
	}
	else
	{
		__disable_irq();

		CLR(RPM_FLAGS, RPM_14_bit);

		__enable_irq();

		if (ZRO(RT_FLAG1_FFFF8888, RT_5_ALWAYS_1) || (prev_MUT1E_FLAGS & DECELERATION_FUEL_CUT))
		{
			r1 += 1;
		};
	};

	rpm += byte_32EE[r1];

	if (ML02_sub_11D48())
	{
		rpm += word_1564/*24(750)*/;
	};

	return Lim_FF(rpm);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_124AE(u16 rpm)
{
	TRG(wMUT19_Startup_Check_Bits, 0x80, wMUT1A_Manifold_AbsPressure_ADC8bit, word_156A/*35(17.5)*/, word_156C/*46(23)*/);

	TRG(wMUT19_Startup_Check_Bits, 0x8000, MUT21_RPM_x125div4, word_15BE/*0*/, word_15BC/*0*/);

	if (wMUT19_Startup_Check_Bits & 0x80)
	{
		timer_down_FFFF86B4 = word_1566 * 20;
	};

	u32 r13 = word_156E/*37*/;

	if (timer_down_FFFF86B4 == 0)
	{
		r13 = word_1570/*35*/;
	};

	return (byte_102F == 0 || (RT_FLAG1_FFFF8888 & RACING)) 
		&& ZRO(wMUT19_Startup_Check_Bits, 0x40) 
		&& ZRO(wMUT71_Sensor_Error, MUT71_3_MAP) 
		&& MUT21_RPM_x125div4 > rpm 
		&& timer_down_FFFF86B4 == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_1262C(u16 rpm)
{
	return MUT21_RPM_x125div4 > rpm
		&& ZRO(wMUT19_Startup_Check_Bits, 0x40) 
		&& cranking_end_timer_up >= (word_155A * 20)
		&& ZRO(wMUT23, 0x20)
		&& (RT_FLAG1_COPY_FFFF888A & RT_FLAG1_FFFF8888 & RT_7_bit)
		&& crank5_FFFF8A36 == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1268C()
{
	WFLAG(wMUT1E_MAF_RESET_FLAG, MAP_error, wMUT71_Sensor_Error & MUT71_3_MAP); // MAP fault
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_O2_Closed_Loop()
{
	ML02_O2_Heater_Tests();
	ML02_Open_And_Closed_Loop_Calcs();
	ML02_Closed_Loop_Error();
	ML02_MAP_Change_Calcs();

	ML02_sub_12D9C(ENGINE_MAIN_VARIABLES_DIM_off_9198);
	ML02_sub_13088(ENGINE_MAIN_VARIABLES_DIM_off_9198);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_O2_Heater_Tests()
{
	if (prev_MUT1E_FLAGS & (STALL|CRANKING))
	{
		RAM_VAR_15A0_FFFF879C = t1_unk_15A0/*14*/;
		RAM_VAR_15A2_FFFF8A38 = t1_unk_15A2/*50*/;
		word_FFFF8A3A = 0;
	};

	if (prev_MUT1E_FLAGS & CRANKING)
	{
		word_FFFF8828 = word_FFFF882A = ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1) && wMUT10_Coolant_Temperature_Scaled > word_1EC2/*60*/) ? Mul_Lim_FFFF(2, Table_Lookup_byte_2D_3D(STFUELTRIM1_41D4)) : 0;

		// loc_127D6

		timer_FFFF8792 = Mul_Lim_FFFF(2, Table_Lookup_byte_2D_3D(STFUELTRIM_3356)); 
	}
	else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1) && cranking_end_timer_up >= t1_off_1592/*1*/*20)
	{
		if (wMUT13_Front_O2_ADC8bit > t1_Primary_O2_Voltage_Check1_1EC0/*26*/)
		{
			word_FFFF8828 = 0;
		};

		if (ADC_07_8bit > t1_Primary_O2_Voltage_Check1_1EC0/*26*/)
		{
			word_FFFF882A = 0;
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Open_And_Closed_Loop_Calcs()
{
	ML02_Open_andor_Closed_Loop_Fuel_Calcs();
	ML02_Open_Loop_Calc();

	WFLAG(wMUT18_Open_Loop_Bit_Array, MUT18_12_1000, ML02_sub_12BC0());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Open_andor_Closed_Loop_Fuel_Calcs()
{
	u32 load = wMUT1C_ECU_Load;

	if (ZRO(wMUTD0_BitMap1, 1) && wMUT15_Barometric_Pressure >= Closed_Loop_Minimal_Pressure_Const)
	{
		load = ECU_Load_1;
	};

	Table_Lookup_Axis(RPM13_64CC);
	Table_Lookup_Axis(RPM14_79C8);

	u32 r1 = Table_Lookup_byte_2D_3D(OPLOPLOAD1_6318);
	u32 r2 = r1;

	u32 r3 = Sub_Lim_0(r1, MINTEMPCLOSEDLOOP_159C);

	TRG(wMUT18_Open_Loop_Bit_Array, MUT18_9_200, load, r3, r2);

	if (byte_1031/*1*/ != 0)
	{
		if (wMUT18_Open_Loop_Bit_Array & MUT18_0_01)
		{
			r1 = r3;
		};

		if (load <= r1)
		{
			if (RAM_VAR_15A0_FFFF879C != 0)
			{
				if (RAM_VAR_15A2_FFFF8A38 < t1_unk_15A2/*50*/ && t1_unk_15A0/*14*/ != 0)
				{
					RAM_VAR_15A2_FFFF8A38 += 1;
				}
				else
				{
					RAM_VAR_15A2_FFFF8A38 = t1_unk_15A2;
				};

				RAM_VAR_15A0_FFFF879C = t1_unk_15A0/*14*/;
			};
		}
		else
		{
			// loc_12A0C

			if (wMUT71_Sensor_Error & MUT71_9_bit)
			{
				r3 = Sub_Lim_0(r2, MINTEMPCLOSEDLOOP_159C/*8*/);
			}
			else
			{
				RAM_VAR_15A0_FFFF879C = t1_unk_15A0/*14*/;
			
				if (timeEvents & EVT_3_500ms)
				{
					DECLIM(RAM_VAR_15A2_FFFF8A38);
				};

				if (RAM_VAR_15A2_FFFF8A38 != 0)
				{
					if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)
					{
						Table_Lookup_Axis(RPM14_79C8);

						r2 = Table_Lookup_byte_2D_3D(OPLOPLOAD2_632C);
					}
					else
					{
						Table_Lookup_Axis(RPM14_79C8);

						r2 = Table_Lookup_byte_2D_3D(OPLOPLOAD2_632C);
					};

					// loc_12A7C

					r3 = Sub_Lim_0(r2, MINTEMPCLOSEDLOOP_159C/*8*/);
				};
			};
		};
	};

	// loc_12A8E

	TRG(wMUT18_Open_Loop_Bit_Array, MUT18_0_01, load, r3, r2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Open_Loop_Calc()
{
	Table_Lookup_Axis(RPM13_64CC);

	u32 r13 = Table_Lookup_byte_2D_3D((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? OPENLOOPLOV_332E : OPENLOOPHIV_3342);

	TRG(wMUT18_Open_Loop_Bit_Array, MUT18_8_100, wMUT8A_TPS_Corrected, Sub_Lim_0(r13, Open_Loop_TPS_FallBack_Const/*13*/), r13)
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_12BC0()
{
	if (ZRO(wMUTD1_BitMap_FAA, FAA_4_CLOSED_LOOP) || (wMUT18_Open_Loop_Bit_Array & MUT18_0_01))
	{
		return true;
	};

	if (ZRO(wMUT71_Sensor_Error, MUT71_9_bit) && (wMUT18_Open_Loop_Bit_Array & MUT18_8_100))
	{
		return true;
	};

	if ((wMUT1E_MAF_RESET_FLAG & (STALL|FUEL_CUT|MAP_error|CRANKING)) || (RPM_FLAGS & RPM_5_REVLIM))
	{
		return true;
	};

	if ((word_FFFF8BBA & 1) || (wMUT19_Startup_Check_Bits & 0x400) || timer_FFFF8792 != 0 || (FUEL_CUT_FLAG_FFFF8A5E & FCF_100))
	{
		return true;
	};

	if (open_Loop_disable/*1*/ != 0 && timer_FFFF8596 != 0)
	{
		return true;
	};

	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Closed_Loop_Error()
{
	WFLAG(wMUT18_Open_Loop_Bit_Array, MUT18_1_02, ML02_Open_Closed_Loop_Some_Check());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_Open_Closed_Loop_Some_Check()
{
	return ZRO(wMUT18_Open_Loop_Bit_Array, MUT18_12_1000) && (wMUT19_Startup_Check_Bits & 0x80);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_MAP_Change_Calcs()
{
	u32 r8 = SPEED_FLAGS;

	TRG(SPEED_FLAGS, SPD_0_01, wMUT10_Coolant_Temperature_Scaled, t1_unk_15D2_Some_Coolant/*112*/, t1_unk_15D4_Some_Coolant/*121*/);

	__disable_irq();

	u32 r2 = wMUT1A_Manifold_AbsPressure_ADC8bit;
	u32 r1 = Manifold_ADC8bit_1;

	__enable_irq();

	u32 r13 = ABSDIF(r1, r2);

	if (r13 >= 0xff) r13 = 0xFF;

	WFLAG(SPEED_FLAGS, SPD_1_02, r13 >= t1_MAF_CHANGE_SENSOR_15D6);

	if ((r8 ^ SPEED_FLAGS) & SPEED_FLAGS & SPD_1_02)
	{
		timer_FFFF8598 = t1_unk_15D8/*80*/;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_12D9C(EnVars* ev)
{
	u32 r2 = *ev->_12_wMUT18_Open_Loop_Bit_Array;
	u32 O2F = *ev->_28_wMUT13_Front_O2_ADC8bit;
	u16* p = ev->_292_word_FFFF8A12;

	u32 r13 = *p;
	u32 r9 = r13;

	if (O2F >= word_1700/*26*/)
	{
		*p = r13 | 0x40;
	}
	else
	{
		*p = r13 & ~0x40;

		wMUT0C_Fuel_Trim_Low = word_2902/*20*/;
	};

	if (ZRO(prev_MUT1E_FLAGS, STALL) && (((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 8) && (*ev->_176_word_FFFF9296 & 4)) || cranking_end_timer_up <= (t1_off_1592*20)))
	{
		CLR(r2, MUT18_13_2000);

		*ev->_288_word_FFFF8714 = word_2902/*20*/;
	}
	else
	{
		// loc_12E24

		CLR(r2, MUT18_7_80|MUT18_4_10|MUT18_3_08);

		if (O2F >= *ev->_36_wMUT5A)
		{
			SET(r2, MUT18_7_80);
		};

		if (O2F >= word_1588/*31*/)
		{
			SET(r2, MUT18_4_10);
		};

		if ((wMUTD1_BitMap_FAA & FAA_1_REAR_O2) && O2F >= word_1700/*26*/)
		{
			SET(r2, MUT18_3_08);
		};

		// loc_12E60

		if (prev_MUT1E_FLAGS & STALL)
		{
			SET(r2, MUT18_15_8000|MUT18_5_20);

			if (ZRO(wMUTD1_BitMap_FAA, FAA_1_REAR_O2))
			{
				SET(r2, MUT18_14_4000);
			};

			CLR(r2, MUT18_13_2000);

			*ev->_288_word_FFFF8714 = word_2902/*20*/;

			CLR(*ev->_292_word_FFFF8A12, 0x80);
		}
		else
		{
			// loc_12E96

			u32 r3 = *ev->_16_prev_MUT18_Open_Loop_Bit_Array ^ r2;

			if ((wMUTD1_BitMap_FAA & FAA_1_REAR_O2) || r3 & MUT18_4_10)
			{
				CLR(r2, MUT18_14_4000);

				*ev->_68_timer_FFFF878E = word_1590;
			}
			else if (ZRO(*ev->_8_prev_MUT1E_FLAGS, UPDATE_OXIGEN_TRIM))
			{
				*ev->_68_timer_FFFF878E = word_1590/*255*/;
			}
			else if (*ev->_68_timer_FFFF878E == 0)
			{
				SET(r2, MUT18_14_4000);
			};

			// loc_12F26

			if ((wMUTD1_BitMap_FAA & FAA_1_REAR_O2) && (*ev->_16_prev_MUT18_Open_Loop_Bit_Array & MUT18_15_8000))
			{
				CLR(r2, MUT18_15_8000|MUT18_5_20);

				*ev->_72_timer_FFFF878A = word_1590/*255*/;

				// loc_12FA2

				SET(r2, MUT18_13_2000);
			}
			else if (r3 & MUT18_7_80)
			{
				if (ZRO(wMUTD1_BitMap_FAA, FAA_1_REAR_O2))
				{
					CLR(r2, MUT18_15_8000);
				};
				
				// loc_12F5C

				*ev->_72_timer_FFFF878A = word_1590/*255*/;

				CLR(r2, MUT18_5_20);
				SET(r2, MUT18_13_2000);
			}
			else if (*ev->_8_prev_MUT1E_FLAGS & UPDATE_OXIGEN_TRIM)
			{
				if (*ev->_16_prev_MUT18_Open_Loop_Bit_Array & MUT18_5_20)
				{
					*ev->_72_timer_FFFF878A = word_1590/*255*/;
				};

				// loc_12F8C

				if (*ev->_72_timer_FFFF878A == 0)
				{
					SET(r2, MUT18_5_20);
				};

				// loc_12F9A

				CLR(r2, MUT18_13_2000);
			}
			else
			{
				// loc_12FA2

				SET(r2, MUT18_13_2000);
			};

			// loc_12FA6

			r13 = *ev->_292_word_FFFF8A12;

			r9 ^= r13;

			if (ZRO(r9, 0x40) || ((r13 & 0x40) && *ev->_288_word_FFFF8714 == 0))
			{
				// loc_12FC4

				SET(*ev->_292_word_FFFF8A12, 0x80);
			};
		};
	};

	// loc_12FCE

	WFLAG(r2, MUT18_2_04, O2F >= *ev->_36_wMUT5A);

	u32 r3 = *ev->_16_prev_MUT18_Open_Loop_Bit_Array ^ r2;

	if (r3 & MUT18_2_04)
	{
		*ev->_76_word_FFFF8552 = unk113_524E[word_FFFF8A4A];
	};

	if (*ev->_76_word_FFFF8552 == 0)
	{
		WFLAG(r2, MUT18_6_40, r2 & MUT18_2_04);
	};

	// loc_13020

	*ev->_12_wMUT18_Open_Loop_Bit_Array = r2;

	p = ev->_196_word_FFFF928E;

	if (prev_MUT1E_FLAGS & STALL)
	{
		SET(*p, 4);
	}
	else if (r3 & MUT18_3_08)
	{
		CLR(*p, 4);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13088(EnVars* ev)
{
	WFLAG(*ev->_4_wMUT1E_MAF_RESET_FLAG, UPDATE_OXIGEN_TRIM, ML02_sub_130BC(ev));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_130BC(EnVars* ev)
{
	if (ZRO(wMUT18_Open_Loop_Bit_Array, MUT18_1_02) || (*ev->_12_wMUT18_Open_Loop_Bit_Array & MUT18_5_20) || wMUT10_Coolant_Temperature_Scaled < Closed_Loop_Min_Engine_Temp/*47*/)
	{
		return false;
	};
	
	if ((wMUTD1_BitMap_FAA & FAA_1_REAR_O2) && *ev->_160_word_FFFF87D2 != 0)
	{
		return false;
	};

	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1) && *ev->_180_word_FFFF8828 != 0)
	{
		return false;
	};

	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1) && (*ev->_176_word_FFFF9296 & 0xF2))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13120()
{
//	const u32 r8 = 0x800;
	u32 r1 = wMUT1E_MAF_RESET_FLAG;
	u32 r2 = word_FFFF89F6;

	if (r1 & STALL)
	{
		CLR(r1, UPDATE_OXIGEN_TRIM|MUT1E_9_bit|MUT1E_8_bit|CLOSED_LOOP_GENERIC|FUEL_CUT|DECELERATION_FUEL_CUT|CRANKING);
		CLR(r2, 0x800);
	};

	// loc_13142

	if (r1 & 0x100)
	{
		CLR(r1, UPDATE_OXIGEN_TRIM|MUT1E_9_bit|CLOSED_LOOP_GENERIC|STALL|DECELERATION_FUEL_CUT|CRANKING);
		CLR(r2, 0x800);
	};

	// loc_13150

	if (r1 & CRANKING)
	{
		CLR(r1, UPDATE_OXIGEN_TRIM|MUT1E_9_bit|MUT1E_8_bit|CLOSED_LOOP_GENERIC|STALL|FUEL_CUT|DECELERATION_FUEL_CUT);
		CLR(r2, 0x800);
	};

	// loc_1315C

	if (r1 & 0x200)
	{
		CLR(r1, UPDATE_OXIGEN_TRIM|MUT1E_8_bit|CLOSED_LOOP_GENERIC|STALL|DECELERATION_FUEL_CUT|CRANKING);
		CLR(r2, 0x800);
	};

	// loc_1316A

	if (r1 & DECELERATION_FUEL_CUT)
	{
		CLR(r1, UPDATE_OXIGEN_TRIM|MUT1E_9_bit|MUT1E_8_bit|CLOSED_LOOP_GENERIC|STALL|CRANKING);
		CLR(r2, 0x800);
	};

	if (r1 & MAP_error)
	{
		CLR(r1, UPDATE_OXIGEN_TRIM|CLOSED_LOOP_GENERIC);
		CLR(r2, 0x800);
	};

	// loc_131AA

	SET(r1, MUT1E_5_ALWAYS_1);

	if (sub_21D9C())
	{
		CLR(r1, UPDATE_OXIGEN_TRIM|CLOSED_LOOP_GENERIC);
		CLR(r2, 0x800);
		SET(wMUT18_Open_Loop_Bit_Array, MUT18_12_1000);
	};

	wMUT1E_MAF_RESET_FLAG = r1;

	word_FFFF89F6 = r2;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_131EC()
{
	if (wMUT1E_MAF_RESET_FLAG & FUEL_CUT)
	{
		if (word_FFFF86B0 == 0)
		{
			RAM_VAR_1065_FFFF86B2 = (byte_1065/*1*/ != 0) ? word_216E/*80*/ : word_1598/*80*/;
		};
	}
	else
	{
		// loc_13220

		word_FFFF86B0 = (byte_1065/*1*/ != 0 && (SPEED_FLAGS & SPD_2_ALWAYS_0)) ? word_216A/*40*/ : word_1596/*40*/;
	};

	// loc_13244

	if (byte_1065 != 0 && RAM_VAR_1065_FFFF86B2 != 0 && word_FFFF86AC == 0 && (ZRO(wMUTD1_BitMap_FAA, FAA_1_REAR_O2) || wMUT3C_Rear_O2_ADC8bit < word_216C))
	{
		SET(ZERO_8_IGNITION_FLAGS, 0x2000);
	}
	else
	{
		if (ZERO_8_IGNITION_FLAGS & 0x2000)
		{
			RAM_VAR_1065_FFFF86B2 = 0;
		};

		CLR(ZERO_8_IGNITION_FLAGS, 0x2000);
	};

	// loc_13298

	if (byte_1065 != 0 && ZRO(wMUTD1_BitMap_FAA, FAA_1_REAR_O2) && (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)))
	{
		word_FFFF86AC = 80 * ((wMUT10_Coolant_Temperature_Scaled >= word_16E2) ? word_16E4/*20*/ : word_16E6/*100*/);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13320()
{
	WFLAG(word_FFFF928E, 2, (wMUT1E_MAF_RESET_FLAG & 0x800) && ZRO(word_FFFF928E, 4));

	WFLAG(word_FFFF9290, 2, (word_FFFF89F6 & 0x800) && ZRO(word_FFFF9290, 4));
	
	WFLAG(word_FFFF928E, 1, word_FFFF928E & 2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_13398()
{
	ML02_sub_133BC();
	ML02_sub_1364C(ENGINE_MAIN_VARIABLES_DIM_off_9198);
	ML02_sub_1376C(ENGINE_MAIN_VARIABLES_DIM_off_9198);
	ML02_Fuel_Knock_Reaction(ENGINE_MAIN_VARIABLES_DIM_off_9198);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_133BC()
{
	u32 r1 = 0;

	if (coolantTempDuringCranking < word_16DC && wMUT10_Coolant_Temperature_Scaled < word_15DA)
	{
		r1 = 0x40;
	};

	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		word_FFFF86AC = 80 * ((wMUT10_Coolant_Temperature_Scaled >= word_16E2) ? word_16E4/*20*/ : word_16E6/*100*/);
	};

	if (wMUT19_Startup_Check_Bits & 0xF)
	{
		if ((wMUT19_Startup_Check_Bits & 0xF) > 3)
		{
			SET(r1, 2);
		}
		else
		{
			SET(r1, 1);
		};
	};

	// loc_13484

	if (ZRO(wMUT5E_FUEL_CUT_FLAG, 3) && (r1 & 3))
	{
		word_FFFF882C = word_1D94;
		word_FFFF882E = word_1D96;
	}
	else if (ZRO(r1, 3))
	{
		word_FFFF882C = 0;
		word_FFFF882E = 0;
	};

	// loc_134B6

	if (word_FFFF8A34 != 0 && (timeEvents & EVT_3_500ms) && (byte_1062 == 0 || (wMUT5E_FUEL_CUT_FLAG & 3)))
	{
		DECLIM(word_FFFF8A34);
	};

	// loc_134E6

	if (word_FFFF86B0 == 0)
	{
		word_FFFF8A34 = word_16E8/*20*/;
	};

	// loc_134F6

	if (ML02_sub_1359C(ENGINE_MAIN_VARIABLES_DIM_off_9198))
	{
		SET(r1, 0x80);
	};

	// loc_13506

	CLR(wMUT5F, 0x80);

	if (wMUT1E_MAF_RESET_FLAG & UPDATE_OXIGEN_TRIM)
	{
		word_FFFF86AE = word_1704/*40*/;
	};

	// loc_13522

	if (word_FFFF86AE == 0)
	{
		timer_FFFF8796 = word_1706/*40*/;
	};

	if (ML02_sub_13602())
	{
		SET(r1, 0x10);
	};

	if (wMUT2F_Vehicle_Speed >= word_23B4/*255*/)
	{
		SET(r1, 0x100);
	};

	wMUT5E_FUEL_CUT_FLAG = (wMUT5E_FUEL_CUT_FLAG & ~0x1D3) | (r1 & 0x1D3);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_1359C(EnVars* ev)
{
	bool r13 = word_FFFF86AC == 0 && (*ev->_196_word_FFFF928E & 2) && (ZRO(bMUTD3_BitMap4_FCA_Store_FFFF89D8, 0xC) || ZRO(*ev->_176_word_FFFF9296, 0xC));

	WFLAG(*ev->_24_wMUT5E_FUEL_CUT_FLAG, 0x20, r13);

	return word_FFFF8A34 == 0 && r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool ML02_sub_13602()
{
	return (ZRO(bMUTD3_BitMap4_FCA_Store_FFFF89D8, 0xC) || ZRO(word_FFFF9296, 0xC)) 
		&& word_FFFF86AC == 0 
		&& timer_FFFF8796 == 0 
		&& (word_FFFF928E & 2) 
		&& (wMUT19_Startup_Check_Bits & 0xF) 
		&& RAM_VAR_1065_FFFF86B2 == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1364C(EnVars* ev)
{
	Map3D_B *r8 = AFRTOCOOL2_366C;

	u32 r2 = word_16F8;
	u32 r13 = *ev->_40_wMUT5C_ADC_Rear_02_Voltage;

	if (wMUT5E_FUEL_CUT_FLAG & 1)
	{
		r8 = AFRTOCOOL3_3680;
		r2 = word_16FA/*26*/;
	}
	else if (wMUT5E_FUEL_CUT_FLAG & 2)
	{
		r8 = AFRTOCOOL4_3694;
		r2 = (wMUT5E_FUEL_CUT_FLAG & 0x100) ? word_23B8/*26*/ : word_16FC/*26*/;
	};

	if (ZRO(*ev->_24_wMUT5E_FUEL_CUT_FLAG, 0x80))
	{
		r8 = AFRTOCOOL1_3658;
	};

	if (word_FFFF882E == 0)
	{
		wMUTB4_lookup_value = Sub_Lim_0(Add_Lim_FFFF(r13, 0x80), r2);

		Table_Lookup_Axis(CEL13_6614);

		*ev->_52_wMUT66 = Table_Lookup_byte_2D_3D(r8);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_1376C(EnVars* ev)
{
	u32 r14 = word_16F2;

	u32 r9 = word_16F0;
	u32 r6 = word_16EA;
	u32 r13 = word_16F8;

	u16 *r1 = ev->_56_bMUT60;

	if (wMUT5E_FUEL_CUT_FLAG & 1)
	{
		r6 = word_16EC;
		r13 = word_16FA;
		r1 = ev->_60_bMUT61;
	}
	else if (wMUT5E_FUEL_CUT_FLAG & 2)
	{
		r6 = word_16EE;

		r13 = (wMUT5E_FUEL_CUT_FLAG & 0x100) ? word_23B8 : word_16FC;
		r1 = ev->_64_bMUT62;
	}	
	else
	{
		r14 = word_16F6;
		r9 = word_16F4;
	};

	u32 r3 = *r1;

	if ((*ev->_24_wMUT5E_FUEL_CUT_FLAG & 0x80) && word_FFFF882C == 0 && (timeEvents & EVT_5_2s))
	{
		u32 r8 = 0;
		
		u32 r7 = *ev->_40_wMUT5C_ADC_Rear_02_Voltage;

		u32 r2;

		if (r7 >= r13)
		{
			r2 = r7 - r13;
		}
		else
		{
			r2 = r13 - r7;
			r8 = 1;
		};
		
		// loc_13810

		if (r2 > word_16E0)
		{
			if (r8 == 0)
			{
				if (*ev->_48_word_FFFF8A20 > word_16DA)
				{
					r3 = Sub_Lim_0(r3, r6);
				}
			}
			else
			{
				if (*ev->_48_word_FFFF8A20 < word_16D8)
				{
					r3 = Add_Lim_FFFF(r3, r6);
				}
			};
		};
	};

	// loc_1385A

	*r1 = Lim16(r3, r14, r9);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_Fuel_Knock_Reaction(EnVars* ev)
{
	const u32 r9 = 0x100;

	u32 r2 = t1_unk_16D2/*26*/;

	u32 r8 = 0x80;

	u32 r13 = *ev->_56_bMUT60;

	if (wMUT5E_FUEL_CUT_FLAG & 1)
	{
		r2 = word_16D4;

		r13 = *ev->_60_bMUT61;
	}
	else if (wMUT5E_FUEL_CUT_FLAG & 2)
	{
		r2 = (wMUT5E_FUEL_CUT_FLAG & r9) ? word_23B6/*26*/ : word_16D6/*26*/;

		r13 = *ev->_64_bMUT62;
	};

	if (word_FFFF882C != 0)
	{
		r13 = *ev->_56_bMUT60;
	};

	r13 = r2 + (r13 >> 8);

	if (*ev->_4_wMUT1E_MAF_RESET_FLAG & 0x800)
	{
		r13 += *ev->_52_wMUT66;

		r8 = r9;

		if (wMUT5E_FUEL_CUT_FLAG & 0x40)
		{
			r8 = word_16DE/*4*/ + r9;
		};
	};

	// loc_1390C

	r13 = (byte_1053 == 3 && (*ev->_432_word_8DB0->_204_word_FFFF81E0 & 0x80)) ? r2 : Sub_Lim_0(r13, r8);

	// loc_13938

	*ev->_48_word_FFFF8A20 = Lim16(r13, word_16DA, word_16D8);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_139A8()
{
	if (ZRO(wMUT1E_MAF_RESET_FLAG, STALL|CRANKING))
	{
		SET(SPEED_FLAGS, SPD_10_400);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ML02_sub_139C4()
{
	if ((RT_FLAG1_FFFF8888 & STARTER) 
		&& wMUT10_Coolant_Temperature_Scaled <= word_25E4 
		&& ZRO(BOOSTCHECK2_FFFF8A0E, 0x80)
		&& Sub_Lim_0(coolantTempScld_COPY_2, wMUT10_Coolant_Temperature_Scaled) <= word_25E6
		&& ABSDIF(coolantTempScld_COPY_2, coolant_temp_FFFF8038) <= word_25E8)
	{
		SET(word_FFFF8A48, 0x20);
	}
	else
	{
		CLR(word_FFFF8A48, 0x20);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


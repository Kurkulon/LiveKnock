#pragma section _BC06

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"

#undef BC06_sub_1E2D0

//#undef F500_Init_Load_ECU_Info_And_BitMap_Flags

//#define sub_A374			((void(*)(void))0xA374)
//#define F500_Get_All_ADC	((void(*)(void))0xA7F0)
//#define F500_sub_21C80		((bool(*)(void))0x21C80)

#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

#define sub_21F4E			((u16(*)(u16))0x21F4E)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#define RPM9_6AB4							((Axis*)0x6AB4)



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#define unk018_3D90							((Map3D_B *)0x3D90)



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_sub_1BEFE();
static void BC06_root_sub_1BF7A();
static void BC06_sub_1C0BC();
static bool BC06_sub_1C0EA();
static void BC06_sub_1C11C();
static bool BC06_sub_1C14A();
static void BC06_sub_1C5EC();
static void BC06_sub_1C68A();
static bool BC06_sub_1C8C4();
static bool BC06_sub_1CACC();
static void BC06_sub_1CAFE();
static u16 BC06_sub_1CB66();
static void BC06_sub_1CB88();
static void BC06_sub_1CDE6();
static void BC06_sub_1CED4();
static void BC06_sub_1D178();
static void BC06_sub_1D1BE();
static void BC06_sub_1D268();
static void BC06_sub_1D2BC();
static void BC06_sub_1D42C();
static void BC06_sub_1D474();
static void BC06_sub_1D49E();
static void BC06_sub_1D628();
static void BC06_sub_1D670();
static void BC06_EGR_sub_1D6D0();
static void BC06_sub_1D77A();
static void BC06_EGR_HI_LO();
static void BC06_sub_1DC08();
static void BC06_sub_1DC1A();
static void BC06_sub_1DCDC();
static void BC06_sub_1DD12();
static void BC06_TERMOFANDUTY_sub_1DF8A();
static void BC06_sub_1E0EC();
static void BC06_sub_1E122();
static void BC06_sub_1E22C();
static void BC06_sub_1E240();
static void BC06_Nop8();
static void BC06_sub_1E260();
static void BC06_sub_1E2A8();
static void BC06_Nop9();
static void BC06_sub_1E2D0();
static void BC06_sub_1E3FC();
static void BC06_sub_1E42C();
static void BC06_sub_1E5B0();
static void BC06_sub_1E772();
static void BC06_Open_Loop_Throttle_sub_1E87A();
static void BC06_sub_1E92E();
static void BC06_sub_1EB0C();
static void BC06_sub_1EB2E();
static void BC06_sub_1EB7C();
static void BC06_sub_1EBEA();
static void BC06_sub_1EE08();
static void BC06_sub_1EE64();
static void BC06_sub_1EEBC();
static void BC06_sub_1EF74();
static void BC06_sub_1F24C();
static void BC06_sub_1F334();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_sub_1BEFE()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_root_sub_1BF7A()
{
	BC06_sub_1C0BC();
	BC06_sub_1C11C();
	BC06_sub_1C5EC();

	if (byte_1040 != 0)
	{
		BC06_sub_1D42C();
	};

	BC06_sub_1D628();
	BC06_EGR_sub_1D6D0();
	BC06_sub_1DC08();
	BC06_sub_1E0EC();
	BC06_sub_1E22C();
	BC06_sub_1E240();
	BC06_Nop8();
	BC06_sub_1E260();
	BC06_sub_1E2A8();
	BC06_Nop9();
	BC06_sub_1E3FC();
	BC06_sub_1E42C();
	BC06_sub_1E5B0();
	BC06_sub_1EB0C();

	if(bMUTD2_FBA_MAF_MAP_FLAG & 0x40)
	{
		BC06_sub_1D49E();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1C0BC()
{
	WFLAG(wMUT9A_Ligths_Bit_Array, 0x80, BC06_sub_1C0EA());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1C0EA()
{
	return ZRO(wMUT1E_MAF_RESET_FLAG, STALL) || (MUT_CMD_0 & 2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1C11C()
{
	WFLAG(wMUT9A_Ligths_Bit_Array, AC_LOAD, BC06_sub_1C14A());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1C14A()
{
	u32 r13 = Bitmap_Store_I_FFFF8CFE;
	u32 tps = wMUT17_TPS_ADC8bit;
	u32 r6 = 1;

	if (byte_1069/*1*/ != 0 && (RT_FLAG1_FFFF8888 & RT_FLAG1_COPY_FFFF888A & AC_SWITCH) && word_FFFF85E6 == 0)
	{
		r6 = 1;
		word_FFFF860C = word_2248/*20*/;
	};
	
	if (ZRO(RT_FLAG1_FFFF8888 | RT_FLAG1_COPY_FFFF888A, AC_SWITCH) && word_FFFF860C == 0)
	{
		r6 = 0;
		word_FFFF85E6 = word_1A7A/*30*/;
	};

	if (((RT_FLAG1_FFFF8888 ^ RT_FLAG1_COPY_FFFF888A) & RT_FLAG1_COPY_FFFF888A & AC_SWITCH) && word_FFFF8704 != 0)
	{
		r6 = 0;
		word_FFFF860C = 0;
	};

	if (MUT21_RPM_x125div4 < word_1A80/*13(406)*/)
	{
		r6 = 0;
		word_FFFF85E8 = word_1A7C/*32*/;
	};

	// loc_1C1E8

	TRG(r13, 4, wMUT2E_Vehicle_Speed_Frequency, word_1A90/*40*/, word_1A8E/*40*/);

	// loc_1C224

	TRG(r13, 2, tps, word_1A8C/*76*/, word_1A8A/*97*/);

	// loc_1C24E

	if (byte_1048/*0xF*/ == 0 || (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) || ((byte_1048/*0xF*/ & 4) && wMUT11_Intake_Air_Temperature_Scaled > word_20F0))
	{
		// loc_1C292

		word_FFFF86D2 = 0;
	}
	else if (ZRO(r13, 4) && ((Bitmap_Store_I_FFFF8CFE ^ r13) & r13 & 2))
	{
		word_FFFF86D2 = word_1A92;
	};

	// loc_1C298

	TRG(r13, 1, tps, word_1A84/*199*/, word_1A82/*210*/);

	// loc_1C2C2

	if ((ZRO(byte_1048, 8) && (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1))
		|| ZRO(r13, 1) 
		|| (ZRO(byte_1048, 2) && word_FFFF86D2 != 0))
	{
		word_FFFF86D0 = 0;
	}
	else if (ZRO(Bitmap_Store_I_FFFF8CFE, 1))
	{
		word_FFFF86D0 = word_1A7E;
	};

	// loc_1C37A

	Bitmap_Store_I_FFFF8CFE = r13;

	WFLAG(word_FFFF8A10, 8, word_FFFF8A10 & 0x10);

	// loc_1C39C

	WFLAG(word_FFFF8A10, 0x10, word_FFFF86D0 != 0 || word_FFFF86D2 != 0);

	// loc_1C3C2

	if ((RT_FLAG1_FFFF8888 & AC_SWITCH) 
		&& ZRO(RT_FLAG1_FFFF8888, RT_7_bit)
		&& (wMUT12_Coolant_Temperature_Min_81 >= word_267C || (MUT21_RPM_x125div4 >= word_2C7E && wMUT11_Intake_Air_Temperature_Scaled >= word_2C80)))
	{
		if ((wMUT9A_Ligths_Bit_Array & AC_LOAD) || (word_FFFF8A10 & 8))
		{
			if (word_FFFF8702 == 0)
			{
				word_FFFF8702 = word_2678;
				word_FFFF8704 = word_267A;
			}
			else if (word_FFFF8704 != 0)
			{
				// loc_1C42A

				word_FFFF8702 = word_2678;
			};
		}
		else
		{
			// loc_1C42A

			word_FFFF8702 = word_2678;
		};
	}
	else
	{
		// loc_1C436

		word_FFFF8702 = word_2678;
		word_FFFF8704 = 0;
	};


	// loc_1C444

	TRG(Bitmap_Store_I_FFFF8CFE, 0x4000, wMUT2E_Vehicle_Speed_Frequency, word_2C86, word_2C84);

	// loc_1C47E

	TRG(Bitmap_Store_I_FFFF8CFE, 0x2000, tps, word_2C8A, word_2C88);

	// loc_1C4B8

	TRG(Bitmap_Store_I_FFFF8CFE, 0x1000, MUT21_RPM_x125div4, word_2C8E, word_2C8C);

	// loc_1C4F2

	if ((r13 & 0x4000) || ZRO(r13, 0x2000) ||  ZRO(r13, 0x1000) || word_FFFF85E6 != 0)
	{
		word_FFFF85E4 = word_2C82;
	};

	
	return r6 != 0 
		&& ((FLAGS_FFFF8EB0 & 0x80) || (word_FFFF85E6 == 0 && word_FFFF85E8 == 0 && word_FFFF86D0 == 0 && word_FFFF86D2 == 0 && word_FFFF8704 == 0)) 
		&& word_FFFF85E4 != 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1C5EC()
{
	word_FFFF8D24 = wMUT4A_Purge_Control_Duty;

	if (wMUTD1_BitMap_FAA & FAA_12_EVAP)
	{
		BC06_sub_1C68A();
		BC06_sub_1CAFE();

		u32 r1 = BC06_sub_1CB66();

		if ((wMUT1E_MAF_RESET_FLAG & STALL) && ((MUT_CMD_0 & 4) || (MUT_CMD_1 & 8)))
		{
			r1 = 0xFF;
		};

		if (ZRO(flags_FFFF92C0, 1))
		{
			u32 r2 = r1 = sub_21F4E(r1);

			__disable_irq();

			wMUT4A_Purge_Control_Duty = MIN(r1, 0xFF);

			word_FFFF8D20 = word_FFFF8D1E;

			__enable_irq();
		};
	}
	else
	{
		wMUT4A_Purge_Control_Duty = 0;
	};

	word_FFFF87C0 = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1C68A()
{
	u32 r1 = 0;

	TRG(word_FFFF8D1E, 8, MUT21_RPM_x125div4, word_1A72, word_1A70);

	TRG(word_FFFF8D1E, 2, wMUT1C_ECU_Load, word_1A6C, word_1A6A);

	Table_Lookup_Axis(RPM9_6AB4);

	u32 r13 = Table_Lookup_byte_2D_3D(unk018_3D90);

	TRG(word_FFFF8D1E, 4, ECU_Load_1, Mul_Fix8_Lim_FFFF(r13, word_1A6E), r13);
	
	CLR(word_FFFF8D1E, 0x800);

	if (ZRO(wMUT1E_MAF_RESET_FLAG, FUEL_CUT))
	{
		word_FFFF8600 = word_1DA0;
	};

	if (bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x2000)
	{
		WFLAG(Bitmap_Store_I_FFFF8CFE, 0x20, (Bitmap_Store_I_FFFF8CFE & 0x40));

		WFLAG(Bitmap_Store_I_FFFF8CFE, 0x40, (Bitmap_Store_F_FFFF91B0 & 8) && (word_FFFF89E8 & 0xEF));
	}
	else
	{
		CLR(Bitmap_Store_I_FFFF8CFE, 0x60);
	};

	if (BC06_sub_1C8C4())
	{
		r1 = 0x20;
	}
	else if (BC06_sub_1CACC())
	{
		r1 = 0x40;
	};

	word_FFFF8D1E = word_FFFF8D1E & ~0x60 | (r1 & 0x60);

	WFLAG(word_FFFF8D1E, 0x1000, (word_FFFF8D1E & 0x840) == 0x840 && ZRO(wMUT1E_MAF_RESET_FLAG, CLOSED_LOOP_GENERIC));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1C8C4()
{
	u32 r1 = (coolantTempDuringCranking >= word_1DB0) ? word_1DB2 : word_1DB4;

	r1 *= 80;

	u32 r2 = wMUT1E_MAF_RESET_FLAG & MUT1E_11_bit;

	WFLAG(word_FFFF8D1E, 0x4000, wMUT0F_Oxygen_Feedback_Trim <= R4_Mult_256_ZeroExtendWord_Into_R0_sub_870(word_1DB6));

	WFLAG(word_FFFF8D1E, 0x2000, r2 != 0 && timer_FFFF878A < Sub_Lim_0(word_1590, word_1DBE));

	// loc_1C9B2




	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1CACC()
{
	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CAFE()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_sub_1CB66()
{
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CB88()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CDE6()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CED4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D178()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D1BE()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D268()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D2BC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D42C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D474()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D49E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D628()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D670()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_EGR_sub_1D6D0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D77A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_EGR_HI_LO()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1DC08()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1DC1A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1DCDC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1DD12()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_TERMOFANDUTY_sub_1DF8A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E0EC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E122()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E22C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E240()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_Nop8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E260()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E2A8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_Nop9()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E2D0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E3FC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E42C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E5B0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E772()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_Open_Loop_Throttle_sub_1E87A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E92E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EB0C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EB2E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EB7C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EBEA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EE08()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EE64()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EEBC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EF74()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1F24C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1F334()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


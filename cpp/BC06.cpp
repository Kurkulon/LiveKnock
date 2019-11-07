//#pragma section _BC06
#pragma section _main

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"

//#undef BC06_sub_1E2D0

//#undef F500_Init_Load_ECU_Info_And_BitMap_Flags

//#define sub_A374			((void(*)(void))0xA374)
//#define F500_Get_All_ADC	((void(*)(void))0xA7F0)
//#define F500_sub_21C80		((bool(*)(void))0x21C80)

#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

inline u16 sub_21F4E(u16 v) { return (v); }

#define _OBD_P0031_P0032_P0037_P0038_sub_2EF5A	((u16(*)(void))0x2EF5A)
#pragma regsave(OBD_P0031_P0032_P0037_P0038_sub_2EF5A)
static u16 OBD_P0031_P0032_P0037_P0038_sub_2EF5A() { return _OBD_P0031_P0032_P0037_P0038_sub_2EF5A(); }

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool sub_E294()
{
	__disable_irq();

	bool r1 = word_FFFF9ADA & 1;

	CLR(word_FFFF9ADA, 1);

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_A324()
{
	__disable_irq();

	if (ZRO(wMUT9B_Output_Pins, 0x8000))
	{
		SET(word_FFFF9ADA, 4);
		SET(reg_PJCRL, 0x10);
	}
	else
	{
		CLR(word_FFFF9ADA, 4);
		CLR(reg_PJCRL, 0x10);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_B0BC(u16 r1)
{
	const u16 r2 = 25000;

	if (r1 != 0 && r1 < 5)	{ r1 = 5; };

	word_FFFF8D28 = r1;

	r1 = Mul_Fix8_Lim_FFFF(r1, r2);

	if (r1 > r2) { r1 = r2; };

	__disable_irq();

	ufix8_FFFF9ADE = r2;

	ufix8_FFFF9AE0 = r1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_E356()
{
	__disable_irq();

	reg_GR2C = reg_TCNT2A + 250;

	reg_TIOR2B = (reg_TIOR2B & ~7) | ((word_FFFF9ADA & 2) ? 2 : 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_E300()
{
	__disable_irq();

	reg_GR2C = reg_TCNT2A + 250;

	CLR(word_FFFF9ADA, 8);

	reg_TIOR2B = (reg_TIOR2B & ~7) | ((word_FFFF9ADA & 2) ? 2 : 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define _sub_21F0C		((u16(*)(u16))0x21F0C)
//#pragma regsave(sub_21F0C)
inline u16 sub_21F0C(u16 v) { return (v); }


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#define RPM9_6AB4							((Axis*)0x6AB4)
#define RPM8_6C70							((Axis*)0x6C70)
#define LOAD9_6CBE							((Axis*)0x6CBE)
#define RPM10_6AD0							((Axis*)0x6AD0)
#define LOAD9_6AEE							((Axis*)0x6AEE)
#define RPM10_6552							((Axis*)0x6552)
#define RPM13_64CC							((Axis*)0x64CC)
#define CEL12_68F2							((Axis*)0x68F2)
#define UN5_6CDA							((Axis*)0x6CDA)
#define RPM7_6C8A							((Axis*)0x6C8A)
#define off_6E0C							((Axis*)0x6E0C)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#define unk018_3D90							((Map3D_B *)0x3D90)
#define unk_41FA							((Map3D_B *)0x41FA)
#define EGR_LO_3E06							((Map3D_B *)0x3E06)
#define EGR_HI_3DA0							((Map3D_B *)0x3DA0)
#define word_3E72							((Map3D_B *)0x3E72)
#define GENTERMDEADZON_3D80					((Map3D_B *)0x3D80)

#define OPLOOPTROTT1_3D06					((Map3D_B *)0x3D06)
#define OPLOOPTROTT2_45F8					((Map3D_B *)0x45F8)

#define unk023_58C6							((Map3D_B *)0x58C6)

#define unk0451_41E2						((Map3D_B *)0x41E2)
#define unk0452_41EE						((Map3D_B *)0x41EE)

#define unk5_4250							((Map3D_B *)0x4250)
#define unk4_4206							((Map3D_B *)0x4206)

#define table_2D_3E8A						((Map3D_B *)0x3E8A)
#define table_2D_3EAE						((Map3D_B *)0x3EAE)
#define table_2D_3E9C						((Map3D_B *)0x3E9C)
#define unk058_3EC0							((Map3D_B *)0x3EC0)
#define byte_4BC4							((Map3D_B *)0x4BC4)
		
		



#define TERMFAN_8B04						((byte**)0x8B04)
#define TERMFAN_8B34						((byte**)0x8B34)


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SysInit_sub_1BEFE();
void BC06_root_sub_1BF7A();
void BC06_sub_1E2D0();
void BC06_sub_1D2BC();

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
static u16 BC06_sub_1CED4();
static u16 BC06_sub_1D178(u16 v);
static void BC06_sub_1D1BE();
static u16 BC06_sub_1D268();
static void BC06_sub_1D42C();
static bool BC06_sub_1D474();
static void BC06_sub_1D49E();
static void BC06_sub_1D628();
static bool BC06_sub_1D670();
static void BC06_EGR_sub_1D6D0();
static bool BC06_sub_1D77A();
static u16 BC06_EGR_HI_LO();
static void BC06_sub_1DC08();
static bool BC06_sub_1DC1A();
static u16 BC06_sub_1DCDC();
static void BC06_sub_1DD12();
static u16 BC06_TERMOFANDUTY_sub_1DF8A();
static void BC06_sub_1E0EC();
static bool BC06_sub_1E122();
static void BC06_sub_1E22C();
static void BC06_sub_1E240();
static void BC06_Nop8();
static void BC06_sub_1E260();
static void BC06_sub_1E2A8();
static void BC06_Nop9();
static void BC06_sub_1E3FC();
static void BC06_sub_1E42C();
static void BC06_sub_1E5B0();
static bool BC06_sub_1E772();
static bool BC06_Open_Loop_Throttle_sub_1E87A();
static u16 BC06_sub_1E92E(EnVars* ev, u16 r1);
static void BC06_sub_1EB0C();
static void BC06_sub_1EB2E();
static void BC06_sub_1EB7C();
static void BC06_sub_1EBEA();
static void BC06_sub_1EE08();
static bool BC06_sub_1EE64();
static bool BC06_sub_1EEBC();
static void BC06_sub_1EF74();
static void BC06_sub_1F24C();
static bool BC06_sub_1F334();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SysInit_sub_1BEFE()
{
	SET(word_FFFF8D68, 0xC080);

	word_FFFF8D6E = word_1ADC;

	wMUT77 = word_1ADA;
	wMUT78 = word_1ADA;

	SET(word_FFFF8D80, 0xC0);

	wMUT8B = 0xFF;

	word_FFFF85EE = word_1B00;

	SET(wMUT9A_Ligths_Bit_Array, 2);

	word_FFFF8DD6 = 1;

	word_FFFF8DD2 = word_1BA4;

	gen_G_timer = 0xFFFF;

	word_FFFF8D30 = 0xFF;

	word_FFFF87BC = word_1B90;

	word_FFFF8702 = word_2678;

	word_FFFF85E4 = word_2C82;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void BC06_root_sub_1BF7A()
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

	if (byte_1048/*0xF*/ == 0 || (RT_FLAG1_FFFF8888 & DRIVE_ALWAYS_1) || ((byte_1048/*0xF*/ & 4) && wMUT11_Intake_Air_Temperature_Scaled > word_20F0))
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

	if ((ZRO(byte_1048, 8) && (RT_FLAG1_FFFF8888 & DRIVE_ALWAYS_1))
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

	u32 r2 = wMUT1E_MAF_RESET_FLAG & UPDATE_OXIGEN_TRIM;

	WFLAG(word_FFFF8D1E, 0x4000, wMUT0F_Oxygen_Feedback_Trim <= R4_Mult_256_ZeroExtendWord_Into_R0_sub_870(word_1DB6));

	WFLAG(word_FFFF8D1E, 0x2000, r2 != 0 && timer_FFFF878A < Sub_Lim_0(word_1590, word_1DBE));

	// loc_1C9B2

	if ((wMUT71_Sensor_Error & MUT71_3_MAP) && (MUT21_RPM_x125div4 <= word_1DA2 || wMUT17_TPS_ADC8bit <= word_1DA4))
	{
		return true;
	};

	if (ZRO(wMUT71_Sensor_Error, MUT71_3_MAP) && (ZRO(wMUT19_Startup_Check_Bits, 0x80) || ZRO(word_FFFF8D1E, 4) || (word_FFFF8D1E & 2)))
	{
		return true;
	};

	if ((wMUT1E_MAF_RESET_FLAG & FUEL_CUT))
	{
		return true;
	};

	if (open_Loop_disable != 0 && byte_1063 != 0)
	{
		if ((FUEL_CUT_FLAG_FFFF8A5E & FCF_40) || timer_FFFF8596 != 0)
		{
			return true;
		};
	};

	// loc_1CA2A

	if ((Bitmap_Store_I_FFFF8CFE & 0x40) 
		|| (word_FFFF8D1E & 0x4000) 
		|| (word_FFFF8D1E & 0x2000) 
		|| ZRO(word_FFFF8D1E, 8) 
		|| cranking_end_timer_up < r1 
		|| (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
		|| wMUT10_Coolant_Temperature_Scaled < word_1A62)
	{
		return true;
	};

	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1CACC()
{
	return ZRO(wMUT1E_MAF_RESET_FLAG, CLOSED_LOOP_GENERIC) || wMUT15_Barometric_Pressure < word_15E0 || wMUT11_Intake_Air_Temperature_Scaled >= word_15DC;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CAFE()
{
	if ((wMUT1E_MAF_RESET_FLAG & STALL))
	{
		word_FFFF86CC = word_1A64 * 80;
		
		CLR(word_FFFF8D1E, 0x80);
	}
	else if (word_FFFF86CC == 0)
	{
		if ((word_FFFF8D1E & 0x80) && ZRO(word_FFFF8D1E, 0x20))
		{
			word_FFFF86CC = word_1A64 * 80;
			
			CLR(word_FFFF8D1E, 0x80);
		}
		else if (ZRO(word_FFFF8D1E, 0xC0))
		{
			word_FFFF86CC = word_1A66 * 80;
			
			SET(word_FFFF8D1E, 0x80);
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_sub_1CB66()
{
	BC06_sub_1CB88();

	BC06_sub_1CDE6();

	return BC06_sub_1D178(BC06_sub_1CED4());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CB88()
{
	u32 r1 = wMUTA5_Port_B_Data_Register_Low;
	u32 r2 = 0x2000;

	u32 r13;

	if ((wMUT1E_MAF_RESET_FLAG & FUEL_CUT) || ZRO(wMUT19_Startup_Check_Bits, 0x80))
	{
		r13 = 1;
	}
	else
	{
		r13 = 0;
		word_FFFF86FA = word_1DAC/*255*/;
	};

	// loc_1CBDE

	if (ZRO(Bitmap_Store_I_FFFF8CFE, 0x40))
	{
		if ((Bitmap_Store_I_FFFF8CFE & 0x20) && (Bitmap_Store_H_FFFF92BE & 0x20))
		{
			wMUTA5_Port_B_Data_Register_Low = word_FFFF8D2C;

			r1 = word_FFFF8D2C;
		};

		word_FFFF8D2C = wMUTA5_Port_B_Data_Register_Low;
	};

	// loc_1CC0A

	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || (Bitmap_Store_I_FFFF8CFE & 0x40))
	{
		r1 = 0;
	}
	else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & r2) && (Bitmap_Store_H_FFFF92BE & 0x20) && (word_FFFF80E6 & 0x300))
	{
		r1 = 0xFF;
	}
	else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & r2) && (Bitmap_Store_H_FFFF92BE & 0x10) && (word_FFFF80E6 & 0x300))
	{
		r1 = 0;
	}
	else if (r13 != 0) // loc_1CC44
	{
		if (word_FFFF86FA == 0)
		{
			r1 = 0;
		};
	}
	else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & r2) && (Bitmap_Store_H_FFFF92BE & 0x10) && (wMUT4A_Purge_Control_Duty <= word_2142/*26*/))
	{
		r1 = 0;
	}
	else if (timeEvents & EVT_3_500ms)
	{
		// loc_1CCE2

		u32 r3;

		if (Bitmap_Store_H_FFFF92BE & 0x30)
		{
			r3 = word_1ED0;
			r13 = word_1ECE;
		}
		else if (RT_FLAG1_FFFF8888 & RT_7_bit)
		{
			r3 = word_1D9C;
			r13 = word_1D9E;
		}
		else
		{
			r3 = word_1D9A;
			r13 = word_1D9A;
		};

		// loc_1CD60

		if ((Bitmap_Store_H_FFFF92BE & 0x20) || (ZRO(Bitmap_Store_H_FFFF92BE, 0x10) && (ZRO(word_FFFF8D1E, 0xA0) || (word_FFFF8D1E & 0x40))))
		{
			r1 = Add_Lim_FFFF(r1, r3);
		}
		else
		{
			r1 = Sub_Lim_0(r1, r13);
		};
	};

	// loc_1CDB0

	wMUTA5_Port_B_Data_Register_Low = (r1 < 0xFF) ? r1 : 0xFF;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CDE6()
{
	u32 r13 = bMUTA6_Port_C_Data_Register_Low;

	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		CLR(word_FFFF8D1E, 0x200);
	};

	if (((wMUT1E_MAF_RESET_FLAG|word_FFFF89F6) & UPDATE_OXIGEN_TRIM) && wMUTA5_Port_B_Data_Register_Low != 0 && wMUTA5_Port_B_Data_Register_Low < 0xFF)
	{
		if (word_FFFF87BA == 0)
		{
			SET(word_FFFF8D1E, 0x200);
		};
	}
	else
	{
		word_FFFF87BA = word_1DC4;
	};

	// loc_1CE44

	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		r13 = 0xFF;
	}
	else if ((Bitmap_Store_H_FFFF92BE & 0x30) || (word_FFFF8D1E & 0x200) || (word_FFFF8D1E & 0x40))
	{
		// loc_1CE6C

		if (timeEvents & EVT_2_100ms)
		{
			Sub_Lim_0(r13, word_1DC0/*3*/);
		};
	}
	else if (ZRO(word_FFFF8D1E, 0xE0) || (timeEvents & EVT_2_100ms))
	{
		r13 = Add_Lim_FFFF(r13, word_1DC0/*3*/);
	};

	// loc_1CEAC

	bMUTA6_Port_C_Data_Register_Low = (r13 < 0xFF) ? r13 : 0xFF;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_sub_1CED4()
{
	WFLAG(word_FFFF8D1E, 0x400, wMUT19_Startup_Check_Bits & 0xF);

	WFLAG(word_FFFF8D1E, 0x100, (ZRO(wMUT71_Sensor_Error, 8) && (word_FFFF8D1E & 0x400)) || ((word_FFFF80E6 & 0x300) && (Bitmap_Store_H_FFFF92BE & 0x30)));

	// loc_1CF42

	Table_Lookup_Axis(UN5_6CDA);

	u32 r1 = word_FFFF8D5E = Table_Lookup_byte_2D_3D((coolantTempDuringCranking >= word_1DB8/*50*/) ? unk0451_41E2 : unk0452_41EE);

	Map3D_B *p;

	if (word_FFFF8D1E & 0x100)
	{
		Table_Lookup_Axis(RPM8_6C70);
		Table_Lookup_Axis(LOAD9_6CBE);
		p = unk5_4250;
	}
	else
	{
		Table_Lookup_Axis(RPM7_6C8A);
		Table_Lookup_Axis(LOAD9_6CBE);
		p = unk4_4206;
	};

	u32 r2 = Table_Lookup_byte_2D_3D(p);

	u32 r0 = Sub_Lim_0(r2, word_1DAE/*9*/);

	r0 = Mul_Fix8_Lim_FFFF(r0, r1 << 3);

	r0 = Add_Lim_FFFF(r0, word_1DAE/*9*/);

	r1 = interpolate_r4_r5_r6(r0, r2, bMUTA6_Port_C_Data_Register_Low);

	if (r1 >= r0)
	{
		r1 = r0;
	};

	word_FFFF8D5A = MIN(r1, 0xFF);

	// loc_1D0A8

	if ((wMUT1E_MAF_RESET_FLAG & FUEL_CUT) || ZRO(wMUT19_Startup_Check_Bits, 0x80) || (open_Loop_disable/*1*/ != 0 && byte_1063/*0*/ != 0 && ((FUEL_CUT_FLAG_FFFF8A5E & 0x40) || timer_FFFF8596 != 0)))
	{
		r1 = 0;
	}
	else
	{
		r1 = Mul_Div_R(r1, wMUTA5_Port_B_Data_Register_Low, 255);
	};

	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x2000) && (word_FFFF80E6 & 0x300) && (Bitmap_Store_H_FFFF92BE & 0x30))
	{
		r1 = Mul_Div_R((word_FFFF80E6 & 0x100) ? word_21BA/*120*/ : word_21C4/*120*/, wMUTA5_Port_B_Data_Register_Low, 255);
	};

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_sub_1D178(u16 v)
{
	if (((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 4) && (Bitmap_Store_H_FFFF92BE & 8))
		|| ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x80) && (Bitmap_Store_H_FFFF92BE & 4)))
	{
		v = 0;
	};

	if (wMUT71_Sensor_Error & MUT71_3_MAP)
	{
		v = 0;

		if (word_FFFF8D1E & 0x40)
		{
			v = word_1D98;
		};
	};

	return v;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D1BE()
{
	u32 r13 = wMUTA5_Port_B_Data_Register_Low;

	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || (word_FFFF8D1E & 0x20))
	{
		r13 = 0;
	}
	else if (timeEvents & EVT_2_100ms)
	{
		r13 = ((word_FFFF8D1E & 0xA0) && ZRO(word_FFFF8D1E, 0x40)) ? Sub_Lim_0(r13, word_1D9A) : Add_Lim_FFFF(r13, word_1D9A);
	};

	// loc_1D21E

	wMUTA5_Port_B_Data_Register_Low = MIN(r13, 0xFF);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_sub_1D268()
{
	Table_Lookup_Axis(RPM8_6C70);
	Table_Lookup_Axis(LOAD9_6CBE);

	return Mul_Div_R(Table_Lookup_byte_2D_3D(unk_41FA), wMUTA5_Port_B_Data_Register_Low, 0xFF);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void BC06_sub_1D2BC()
{
	//u32 r9 = 0x8000;
	//u32 r8 = 0x100;

	u32 r2 = sub_E294();

	u32 r1 = wMUT9B_Output_Pins;

	if ((flags_FFFF92C0 & 1) || (MUT_CMD_0 & 4) || (MUT_CMD_1 & 8) || wMUT4A_Purge_Control_Duty == 0 || ((word_FFFF8D20 & 0x100) && wMUT4A_Purge_Control_Duty == 0xFF))
	{
		SET(wMUT9B_Output_Pins, 0x8000);

		sub_A324();
		sub_B0BC(0);

		word_FFFF8D30 = 0xFF;

		if (ZRO(r1, 0x8000))
		{
			sub_E356();
		};
	}
	else
	{
		if (r1 & 0x8000)
		{
			sub_E300();
		};

		CLR(wMUT9B_Output_Pins, 0x8000);

		sub_A324();

		if (r2 != 0 || (r1 & 0x8000))
		{
			// loc_1D364
			
			u32 r3 = 2;

			if (word_FFFF8D1E & 0x100)
			{
				r3 = 1;
			};

			// loc_1D372
			
			u32 r13 = word_FFFF8D30;

			INCLIM(r13);

			if (r13 > r3)
			{
				r13 = 0;
			};

			word_FFFF8D30 = r13;
		};

		// loc_1D38E

		if (word_FFFF8D30 == 0)
		{
			word_FFFF8D26 = wMUT4A_Purge_Control_Duty;
		};

		// loc_1D39E

		u32 r1 = Sub_Lim_0(Mul_Div(word_FFFF8D26, 0x100, 255), word_FFFF8D30 << 8);

		sub_B0BC( MIN(r1, 0x100) );
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D42C()
{
	if (ZRO(flags_FFFF92C0, 1))
	{
		bool r1 = BC06_sub_1D474();

		__disable_irq();

		WFLAG(wMUT9B_Output_Pins, 0x40, r1);

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1D474()
{
	return ((wMUT1E_MAF_RESET_FLAG & STALL) && (MUT_CMD_1 & 0x10)) || (Bitmap_Store_H_FFFF92BE & 0x40);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D49E()
{
	if (ZRO(FLAGS_FFFF8EB0, 0x80))
	{
		if (timer_up_FFFF852C <= t1_unk_22F6 || timer_down_TXFLAG3_FFFF8574 == 0)
		{
			// loc_1D4D4

			CLR(OutPort_FFFF8876, 0x10);

			word_FFFF8820 = 0;
			word_FFFF8822 = 0;

			SET(MDP_EXIST_FLAG_FFFF90B8, 0x80);
		}
		else
		{
			u32 r1 = (u32)BATTERY_8_FFFF91D4 >> 8;

			TRG(MDP_EXIST_FLAG_FFFF90B8, 0x80, r1, word_22F4, word_22F2);

			u32 r3, r13;

			if (wMUT2E_Vehicle_Speed_Frequency > t1_Speed_Frequency_2368)
			{
				r3 = word_236C;
				r13 = word_2370;
			}
			else
			{
				r3 = word_236A;
				r13 = word_236E;
			};

			if (MDP_EXIST_FLAG_FFFF90B8 & 0x80)
			{
				word_FFFF8822 = r3;

				if (word_FFFF8820 > r13) word_FFFF8820 = r13;

				if (word_FFFF8820 == 0)
				{
					CLR(OutPort_FFFF8876, 0x10);
				};
			}
			else
			{
				word_FFFF8820 = r13;

				if (word_FFFF8822 > r3) word_FFFF8822 = r3;

				if (word_FFFF8822 == 0)
				{
					SET(OutPort_FFFF8876, 0x10);
				};
			};
		};
	}
	else
	{
		WFLAG(OutPort_FFFF8876, 0x10, BATTERY_L_FFFF91D2 <= 0x4F);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1D628()
{
	if (ZRO(RT_FLAG1_FFFF8888, 0x100))
	{
		word_FFFF85EA = word_1AF8;
	};

	WFLAG(wMUT9A_Ligths_Bit_Array, 2, byte_1047 != 0 && BC06_sub_1D670());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1D670()
{
	return timer_down_TXFLAG3_FFFF8574 != 0 && (timer_up_FFFF852C <= word_1A94*20 || word_FFFF85EA == 0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_EGR_sub_1D6D0()
{
	u32 r1 = 0;

	if (EGRONOFF_103D != 0)
	{	
		if ((wMUT1E_MAF_RESET_FLAG & STALL) && (MUT_CMD_0 & 0x10))
		{
			r1 = 0x80;
		}
		else if (ZRO(MDP_EXIST_FLAG_FFFF90B8, 0x1800))
		{
			if (!BC06_sub_1D77A())
			{
				r1 = sub_21F0C(BC06_EGR_HI_LO());
			};
		}
		else if (MDP_EXIST_FLAG_FFFF90B8 & 0x1000)
		{
			r1 = 0x80;
		};
	};

	// loc_1D724

	if (ZRO(flags_FFFF92C0, 1))
	{
		wMUT85_EGR_Solenoid = r1;
	};

	u32 r13 = wMUT8A_TPS_Corrected;

	WFLAG(ZERO_8_IGNITION_FLAGS, 8, EGRONOFF_103D != 0 && wMUT85_EGR_Solenoid != 0 && r13 >= word_1B94/*41*/ && r13 <= word_1B96/*255*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1D77A()
{
	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		CLR(flags_FFFF8D00, 0x1800);
	}
	else
	{
		// loc_1D7AA

		if (airTempDuringCranking < word_2C9C || coolantTempDuringCranking < word_2C9E || (ZRO(flags_FFFF8D00, 0x800) && wMUT11_Intake_Air_Temperature_Scaled < word_2CA0))
		{
			SET(flags_FFFF8D00, 0x1000);
		};
	};

	// loc_1D7E2

	bool r13;

	if (wMUTD1_BitMap_FAA & FAA_11_IGN_ADV)
	{
		// loc_1D7F0

		u32 r14_8 = (wMUT85_EGR_Solenoid != 0) ? word_1B82 : word_1B84;
		u32 r1, r2;

		if (RT_FLAG1_FFFF8888 & DRIVE_ALWAYS_1)
		{
			r1 = Table_Lookup_byte_2D_3D(table_2D_3E8A);
			r2 = Table_Lookup_byte_2D_3D(table_2D_3EAE);
		}
		else
		{
			r1 = Table_Lookup_byte_2D_3D(table_2D_3E9C);
			r2 = Table_Lookup_byte_2D_3D(unk058_3EC0);
		};

		r1 = Sub_Lim_0(wMUT15_Barometric_Pressure, r1);
		r2 = Sub_Lim_0(wMUT15_Barometric_Pressure, r2);

		u32 r8, r9;

		if (flags_FFFF8D00 & 0x4000)
		{
			r8 = word_1B88;
			r9 = word_1B8E;

			r1 = Sub_Lim_0(r1, word_1B86);
		}
		else
		{
			r8 = word_1B8A;
			r9 = word_1B8C;

			r2 = Sub_Lim_0(r2, word_1B86);
		};

		if (MUT21_RPM_x125div4 < r9 && MUT21_RPM_x125div4 >= r8 && wMUT1C_ECU_Load < r2 && wMUT1C_ECU_Load >= r1)
		{
			SET(flags_FFFF8D00, 0x4000);
		}
		else
		{
			CLR(flags_FFFF8D00, 0x4000);

			word_FFFF87BC = word_1B90;
		};

		Table_Lookup_Axis(off_6E0C);

		r1 = Table_Lookup_byte_2D_3D(byte_4BC4);

		TRG(flags_FFFF8D00, 0x2000, wMUT11_Intake_Air_Temperature_Scaled, Sub_Lim_0(r1, word_2186), r1);

		if (flags_FFFF8D00 & 0x2000)
		{
			word_FFFF860A = word_1B92 * 80;
		};

		r13 = (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING|MAP_error)) 
					|| ZRO(flags_FFFF8D00, 0x4000) 
					|| word_FFFF87BC != 0 
					|| (word_FFFF860A == 0 && ZRO(flags_FFFF8D00, 0x2000)) 
					|| wMUT10_Coolant_Temperature_Scaled <= r14_8
					|| (flags_FFFF8D00 & 0x1000);
	}
	else
	{
		// loc_1DA60

		TRG(flags_FFFF8D00, 0x8000, wMUT10_Coolant_Temperature_Scaled, word_1B7E, word_1B7C);
		
		r13 = (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) 
					|| (wMUT71_Sensor_Error & MUT71_3_MAP) 
					|| wMUT11_Intake_Air_Temperature_Scaled <= word_1B7A
					|| ZRO(flags_FFFF8D00, 0x8000) 
					|| MUT21_RPM_x125div4 > word_1B80/*128*/
					|| (flags_FFFF8D00 & 0x1000);
	};

	if (!r13)
	{
		SET(flags_FFFF8D00, 0x800);
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_EGR_HI_LO()
{
	u32 r13 = 0x80;

	if (ZRO(wMUTD1_BitMap_FAA, 0x800))
	{
		Map3D_B *r1 = EGR_LO_3E06;

		if (RT_FLAG1_FFFF8888 & DRIVE_ALWAYS_1)
		{
			r1 = EGR_HI_3DA0;
		};

		Table_Lookup_Axis(RPM10_6AD0);
		Table_Lookup_Axis(LOAD9_6AEE);

		r13 = Mul_Fix7_R(Table_Lookup_byte_2D_3D(r1), 0x80);

		if ((FUEL_CUT_FLAG_FFFF8A5E & FCF_200) && word_FFFF85FC == 0 && ZRO(byte_103C, 4))
		{
			r13 = Table_Lookup_byte_2D_3D(word_3E72);
		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1DC08()
{
	BC06_sub_1DD12();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1DC1A()
{
	u32 r3 = 0x400;
	u32 r13 = 0x1000;

	TRG(word_FFFF8D60, r3, wMUT12_Coolant_Temperature_Min_81, word_1B3C, word_1B3E);
	TRG(word_FFFF8D60, r13, wMUT17_TPS_ADC8bit, word_1B38, word_1B3A);

	if (ZRO(word_FFFF8D60, r13))
	{
		word_FFFF85F8 = word_1B40;
	};

	if (byte_102E == 2)
	{
	};

	return ZRO(word_FFFF8D60, r3) && (word_FFFF8D60 & r13) && word_FFFF85F8 != 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_sub_1DCDC()
{
	u32 r13 = 0;

	if ((wMUT1E_MAF_RESET_FLAG & STALL) && (MUT_CMD_0 & 0x1800))
	{
		word_FFFF85FA = 0;
		word_FFFF85F6 = 0;

		r13 = 1;

		if (MUT_CMD_0 & 0x800)
		{
			r13 = 3;
		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1DD12()
{
	TRG(word_FFFF8D62, 0x10,	wMUT2F_Vehicle_Speed, word_2398, word_239A);
	TRG(word_FFFF8D62, 1,		wMUT2F_Vehicle_Speed, word_1B44, word_1B46);
	TRG(word_FFFF8D62, 2,		wMUT2F_Vehicle_Speed, word_1B48, word_1B4A);
	TRG(word_FFFF8D62, 0x20,	wMUT2F_Vehicle_Speed, word_239C, word_239E);
	TRG(word_FFFF8D62, 4,		wMUT2F_Vehicle_Speed, word_1B4C, word_1B4E);
	TRG(word_FFFF8D62, 8,		wMUT2F_Vehicle_Speed, word_1B50, word_1B52);

	u32 r1 = BC06_TERMOFANDUTY_sub_1DF8A();

	if (BC06_sub_1DC1A() != 0)
	{
		r1 = word_1B42;
	};

	if (wMUT71_Sensor_Error & (MUT71_0_COOLANT|MUT71_4_bit))
	{
		r1 = word_1B36;
	};

	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || cranking_end_timer_up < word_1B54)
	{
		r1 = (BC06_sub_1DCDC()) ? word_1B28 : 0;

		CLR(word_FFFF8D60, 4);
	}
	else if ((wMUT84_Thermo_Fan_Duty == 0 && r1 != 0) || (wMUT84_Thermo_Fan_Duty != 0 && r1 == 0))
	{
		SET(word_FFFF8D60, 4);
	}
	else
	{
		CLR(word_FFFF8D60, 4);
	};

	if (r1 > word_1B56 && r1 < word_1B58)
	{
		r1 = word_1B56;
	};

	wMUT84_Thermo_Fan_Duty = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_TERMOFANDUTY_sub_1DF8A()
{
	byte r1 = 0;

	Table_Lookup_Axis(CEL12_68F2);

	if (lookup_axis_result != 0)
	{
		r1 = lookup_axis_result.index;

		if (word_FFFF8D66 > r1)
		{
			r1 += 1;
		};

	};

	word_FFFF8D66 = r1;

	u32 r13;

	if (RT_FLAG1_FFFF8888 & AC_SWITCH)
	{
		if (word_FFFF8890 & 0x100)
		{
			if (ZRO(word_FFFF8D62, 0x20))
			{
				r13 = 8;
			}
			else if (ZRO(word_FFFF8D62, 4))
			{
				r13 = 9;
			}
			else
			{
				r13 = 11;

				if (ZRO(word_FFFF8D62, 8))
				{
					r13 = 10;
				};
			};
		}
		else
		{
			// loc_1DFFC

			if (ZRO(word_FFFF8D62, 0x20))
			{
				r13 = 4;
			}
			else if (ZRO(word_FFFF8D62, 4))
			{
				r13 = 5;
			}
			else
			{
				r13 = 7;

				if (ZRO(word_FFFF8D62, 8))
				{
					r13 = 6;
				};
			};
		};
	}
	else
	{
		if (ZRO(word_FFFF8D62, 0x10))
		{
			r13 = 0;
		}
		else if (ZRO(word_FFFF8D62, 1))
		{
			r13 = 1;
		}
		else
		{
			r13 = 3;

			if (ZRO(word_FFFF8D62, 2))
			{
				r13 = 2;
			};
		};
	};

	// loc_1E050

	byte *p = (bMUTD2_FBA_MAF_MAP_FLAG & 0x20) ? TERMFAN_8B34[r13] : TERMFAN_8B04[r13];

	return p[word_FFFF8D66];
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E0EC()
{
	WFLAG(wMUT9A_Ligths_Bit_Array, 4, byte_1046 != 0 && BC06_sub_1E122());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1E122()
{
	u32 r6 = word_1ACA;
	u32 r3 = word_1AD2;
	u32 r7 = word_1ACE;

	if (wMUT9A_Ligths_Bit_Array & 4)
	{
		r6 = word_1ACC;
		r3 = word_1AD4;
		r7 = word_1AD0;
	};

	bool r13 = false;

	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || cranking_end_timer_up <= word_1AD6)
	{
		// loc_1E15C

		if (((wMUT1E_MAF_RESET_FLAG & STALL) && (MUT_CMD_0 & 0x100)) || ZRO(wMUT1E_MAF_RESET_FLAG, STALL|CRANKING))
		{
			r13 = true;
		};

		if (byte_1046 & 4)
		{
			r13 = !r13;
		};
	}
	else
	{
		// loc_1E18E

		if (MUT21_RPM_x125div4 > r3 && wMUT8A_TPS_Corrected > r7)
		{
			word_FFFF85F0 = word_1AD8;
		};

		if (wMUT8A_TPS_Corrected > r6 || (MUT21_RPM_x125div4 > r3 && word_FFFF85F0 == 0) || ZRO(RT_FLAG1_FFFF8888, RT_13_bit)) 
		{
			r13 = true;
		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E22C()
{
	wMUT86_Waste_Gate_Duty_Cycle = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E240()
{
	word_FFFF8D10 = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_Nop8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E260()
{
	__disable_irq();

	CLR(wMUT9B_Output_Pins, 0x80);

	__enable_irq();

	CLR(Bitmap_Store_I_FFFF8CFE, 8);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E2A8()
{
	CLR(wMUT9A_Ligths_Bit_Array, 0x40);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_Nop9()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void BC06_sub_1E2D0()
{
	u32 r13 = 0;

	if (IGN_TEST_FLAG_1044 != 0)
	{
		// loc_1E2E2

		r13 = IGN_MULT_FLAG_FFFF8DBC & 4;

		u32 r3 = word_FFFF8890 & 2;

		if ((word_FFFF8C98 & 0x80) && ZRO(IGN_MULT_FLAG_FFFF8DBC, 4))
		{
			if (wMUT10_Coolant_Temperature_Scaled >= word_1AFE)
			{
				SET(r13, 1);

				if (r3 != 0)
				{
					SET(r13, 0x82);

					if (word_FFFF8890 & 4)
					{
						SET(r13, 0x40);
					};
				};
			}
			else if (wMUT10_Coolant_Temperature_Scaled >= word_1F52)
			{
				SET(r13, 0x10);
			};
		};

		// loc_1E33A

		if ((wMUT1E_MAF_RESET_FLAG & STALL) || (RT_FLAG1_FFFF8888 & STARTER) || r3 == 0)
		{
			word_FFFF85EE = word_1B00;
		};

		// loc_1E358

		if ((r13 & 0x80) && word_FFFF85EE == 0)
		{
			SET(r13, 4);
			CLR(r13, 0x13);
		};

		// loc_1E36E
		
		if (timer_down_TXFLAG3_FFFF8574 == 0)
		{
			CLR(r13, 4);
		};

		if (load_ECU_Ignintion > word_1B04 || MUT21_RPM_x125div4 > word_1B06)
		{
			SET(r13, 0x20);
		};
	};

	// loc_1E396

	IGN_MULT_FLAG_FFFF8DBC = IGN_MULT_FLAG_FFFF8DBC & ~0xF7 | (r13 & 0xF7);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E3FC()
{
	CLR(word_FFFF8D72, 0x80);
	CLR(word_FFFF8D80, 0xCF);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E42C()
{
	u32 r13 = 0;
	u32 r3 = 0;

	if ((wMUT40_Stored_Faults_Lo & 0xEE) || (wMUT41_Stored_Faults_Hi & 0xCA) || (wMUT42_Stored_Faults_Lo_1 & 1))
	{
		r13 = 0x80;
	};

	if (RT_FLAG1_FFFF8888 & RT_7_bit)
	{
		SET(r13, 0x40);
		r3 = 0x40;
	};

	if (IGN_MULT_FLAG_FFFF8DBC & 2)
	{
		SET(r13, 0x20);
		SET(r3,  0x20);
	};

	if (IGN_MULT_FLAG_FFFF8DBC & 1)
	{
		SET(r13, 0x10);
		SET(r3,  0x10);
	};

	if (RT_FLAG1_FFFF8888 & RT_1_bit)
	{
		SET(r13, 4);
		SET(r3,  4);
	};

	if (word_FFFF8D80 & 0xF)
	{
		SET(r13, 2);
		SET(r3,  2);
	};

	if (wMUT1E_MAF_RESET_FLAG & IDLE)
	{
		SET(r13, 1);
	};

	word_FFFF8D86 = r13;
	word_FFFF8D8A = r3;

	r13 = word_1AFA | word_1AFC;

	if (wMUTD0_BitMap1 & 0xC)
	{
		SET(r13, 2);
	}
	else if (wMUTD0_BitMap1 & 2)
	{
		SET(r13, 1);
	}
	else if (ZRO(wMUTD0_BitMap1, 1) || (wMUTD0_BitMap1 & 0x20))
	{
		SET(r13, 3);
	};

	// loc_1E4E8

	flags_FFFF8D8C = r13;

	r13 = 0x80;

	if (word_FFFF8D74 & 0xC0)
	{
		r13 = 0xC0;
	};

	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1) && (wMUT10_Coolant_Temperature_Scaled >= word_1F52 || (wMUT71_Sensor_Error & MUT71_0_COOLANT)))
	{
		SET(r13, 4);
	};

	word_FFFF8D90 = r13;

	word_FFFF8966 = ECU_Load_1;

	WFLAG(word_FFFF93D2, 0x800, MUT_00_01_FLAGS & 0x10);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1E5B0()
{
	u32 r9 = 0;
	u32 r1 = 0;
	u32 r2 = 0;

	u32 r14_8 = 0;
	u32 r8 = 0;

	if (wMUTD1_BitMap_FAA & FAA_14_HEATER_O2)
	{
		u32 r13 = BC06_sub_1E92E(ENGINE_MAIN_VARIABLES_DIM_off_9198, 0);

		if (r13 == 1)
		{
			r1 = 0x80;
		}
		else if (r13 == 2)
		{
			r1 = word_20BC;
		};

		// loc_1E5FC

		if (r1 >= 0x80)
		{
			r9 = 0x100;
		};

		if (BC06_Open_Loop_Throttle_sub_1E87A())
		{
			SET(r9, 0xC00);

			r8 = 0x80;
			r2 = 0x80;
		};

		// loc_1E618

		if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
		{
			Table_Lookup_Axis(CEL8_7100);

			word_FFFF87C2 = Table_Lookup_byte_2D_3D(unk023_58C6);
		};

		if (ZRO(MUT_CMD_0, 0x2000))
		{
			if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || word_FFFF87C2 != 0)
			{
				if ((word_FFFF9150 & 4) || OBD_P0031_P0032_P0037_P0038_sub_2EF5A() == 0)
				{
					r8 = 0;
					r2 = 0;

					CLR(r9, 0xC00);
				};
			};
		};

		// loc_1E66A

		if (ZRO(word_FFFF9150, 1))
		{
			if (word_FFFF9150 & 0x300)
			{
				r1 = 0x80;
			}
			else if (word_FFFF9150 & 0x400)
			{
				r1 = 0;
			};
		};

		// loc_1E6A0

		if (ZRO(word_FFFF9150, 4))
		{
			if (word_FFFF9150 & 0x300)
			{
				r2 = 0x80;
			}
			else if (word_FFFF9150 & 0x400)
			{
				r2 = 0;
			};
		};

		// loc_1E6C4

		if (ZRO(word_FFFF9150, 2))
		{
			if (word_FFFF9150 & 0x300)
			{
				r14_8 = 0x80;
			}
			else if (word_FFFF9150 & 0x400)
			{
				r14_8 = 0;
			};
		};

		// loc_1E6EC

		if (ZRO(word_FFFF9150, 8))
		{
			if (word_FFFF9150 & 0x300)
			{
				r8 = 0x80;
			}
			else if (word_FFFF9150 & 0x400)
			{
				r8 = 0;
			};
		};

		// loc_1E710

		if (FLAGS_FFFF8EB0 & 0x80)
		{
			if (r1 != 0)
			{
				r1 = 0x80;
			};

			if (r2 != 0)
			{
				r2 = 0x80;
			};

			if (r14_8 != 0)
			{
				r14_8 = 0x80;
			};

			if (r8 != 0)
			{
				r8 = 0x80;
			};
		};
	};

	// loc_1E73C

	wMUT9A_Ligths_Bit_Array = wMUT9A_Ligths_Bit_Array & ~0xF00 | (r9 & 0xF00);

	O2F_Heater_Duty = r1;
	O2R_Heater_Duty = r2;

	word_FFFF8D1A = r14_8;
	word_FFFF8D1C = r8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1E772()
{
	u32 r2 = word_1B5C;

	Table_Lookup_Axis(RPM13_64CC);

	u32 r1 = Table_Lookup_byte_2D_3D(OPLOOPTROTT1_3D06);

	if (ZRO(wMUT9A_Ligths_Bit_Array, 0x300))
	{
		r1 = Sub_Lim_0(r1, bc06_word_1B60);

		r2 = word_1B5E;
	};

	if ((wMUT1E_MAF_RESET_FLAG & STALL) && (MUT_CMD_0 & 0x2000))
	{
		return true;
	};

	if ((wMUT1E_MAF_RESET_FLAG & STALL) || (wMUT71_Sensor_Error & MUT71_3_MAP))
	{
		return false;
	};

	if ((wMUT1E_MAF_RESET_FLAG & CRANKING) || cranking_end_timer_up <= word_1B5A * 20 || (wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) || wMUT1C_ECU_Load <= r1 || wMUT10_Coolant_Temperature_Scaled < r2)
	{
		return true;
	}
	else
	{
		return false;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_Open_Loop_Throttle_sub_1E87A()
{
	u32 r2 = word_1B5C;

	Table_Lookup_Axis(RPM13_64CC);

	u32 r1 = Table_Lookup_byte_2D_3D(OPLOOPTROTT1_3D06);

	if (ZRO(wMUT9A_Ligths_Bit_Array, 0xC00))
	{
		r1 = Sub_Lim_0(r1, bc06_word_1B60);

		r2 = word_1B5E;
	};

	if ((wMUT1E_MAF_RESET_FLAG & STALL) && (MUT_CMD_0 & 0x2000))
	{
		return true;
	};

	if ((wMUT1E_MAF_RESET_FLAG & STALL) || (wMUT71_Sensor_Error & MUT71_3_MAP))
	{
		return false;
	};

	if ((wMUT1E_MAF_RESET_FLAG & CRANKING) || cranking_end_timer_up <= word_1B5A * 20 || (wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) || wMUT1C_ECU_Load <= r1 || wMUT10_Coolant_Temperature_Scaled < r2)
	{
		return true;
	}
	else
	{
		return false;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 BC06_sub_1E92E(EnVars* ev, u16 r1)
{
	u32 r13 = (*ev->_196_word_FFFF928E & 4) ? 1 : 0;

	if (ZRO(wMUT1E_MAF_RESET_FLAG, STALL))
	{
		if ((wMUT1E_MAF_RESET_FLAG & CRANKING) || (cranking_end_timer_up <= word_1B5A * 20 && r13 != 0))
		{
			// loc_1E9B2

			if (Sub_Lim_0(coolantTempScld_COPY_2, coolantTempDuringCranking) <= word_20B6 || coolantTempDuringCranking <= word_20B8 || coolantTempDuringCranking >= word_20BA)
			{
				return 2;
			}
			else
			{
				return 1;
			};
		}
		else
		{
			// loc_1E9FC

			Table_Lookup_Axis(RPM13_64CC);

			if (r1 == 0)
			{
				r1 = word_1B5C;

				Table_Lookup_byte_2D_3D(OPLOOPTROTT1_3D06);

				if (O2F_Heater_Duty == 0)
				{
					r13 = Sub_Lim_0(r13, bc06_word_1B60);

					r1 = word_1B5E;
				};
			}
			else
			{
				r1 = word_20C0;

				Table_Lookup_byte_2D_3D(OPLOOPTROTT2_45F8);

				if (O2F_Heater_Duty == 0)
				{
					r13 = Sub_Lim_0(r13, word_20C4);

					r1 = word_20C2;
				};
			};

			// loc_1EA66

			if (wMUT71_Sensor_Error & MUT71_3_MAP)
			{
				return 0;
			}
			else if ((wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) || wMUT1C_ECU_Load <= r13 || wMUT10_Coolant_Temperature_Scaled < r1)
			{
				return 2;
			}
			else
			{
				return 0;
			};
		};
	}
	else if (MUT_CMD_0 & 0x2000)
	{
		return 1;
	}
	else
	{
		return 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EB0C()
{
	BC06_sub_1EB2E();

	BC06_sub_1EB7C();

	BC06_sub_1EF74();

	BC06_sub_1EBEA();

	BC06_sub_1EE08();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EB2E()
{
	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || wMUT91_Timer_Status_Register_9_TSR9_Scaled != 0)
	{
		timer_FFFF87B0 = word_1BC0/*10*/ << 2;
	};

	if (timer_down_TXFLAG3_FFFF8574 != 0)
	{
		if (timer_FFFF87B0 == 0)
		{
			SET(wMUT71_Sensor_Error, MUT71_5_ALTERNATOR);
		};
	}
	else
	{
		CLR(wMUT71_Sensor_Error, MUT71_5_ALTERNATOR);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EB7C()
{
	u32 r13 = 1;

	if (MUT21_RPM_x125div4 > word_1BA2)
	{
		r13 = 8;
	}
	else if (MUT21_RPM_x125div4 > word_1BA0)
	{
		r13 = 4;
	}
	else if (MUT21_RPM_x125div4 > word_1B9E)
	{
		r13 = 2;
	};

	word_FFFF8DD6 = r13;

	r13 = word_1BA4;

	if (bMUT8E_Solenoid_Duty > word_1BAC)
	{
		r13 = word_1BA8;
	}
	else if (bMUT8E_Solenoid_Duty > word_1BAA)
	{
		r13 = word_1BA6;
	};

	word_FFFF8DD2 = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EBEA()
{
	TRG(word_FFFF8DBE, 1, wMUT1C_ECU_Load, word_1BBC, word_1BBA);

	TRG(word_FFFF8DBE, 2, MUT21_RPM_x125div4, word_1BB8, word_1BB6);

	if (byte_1045 == 0 || MUT21_RPM_x125div4 > word_1BE8 || cranking_end_timer_up >= word_1BEA * 20 || (wMUT1E_MAF_RESET_FLAG & STALL))
	{
		CLR(word_FFFF8DBE, 0x8000);
	}
	else if (wMUT10_Coolant_Temperature_Scaled <= word_1BE4)
	{
		SET(word_FFFF8DBE, 0x8000);
	};

	// loc_1ED36

	BC06_sub_1F24C();

	if (word_FFFF86D4 == 0)
	{
		u32 r1 = 0xFF;

		u32 r2 = Lim_FF(wMUT93_Fadout_Timer_Value + word_1BB2);

		if (BC06_sub_1EE64())
		{
			r1 = wMUT92_Timer_Status_Register_9_TSR9_Scaled_Checked;
		};

		if (word_FFFF8DBE & 0x400)
		{
			r1 = word_1BE2;
		};

		if (word_FFFF8DBE & 0x800)
		{
			r1 = word_1BE0;
		};

		if (word_FFFF8DBE & 0x1000)
		{
			r1 = word_1BDE;
		};

		if (word_FFFF8DBE & 0x8000)
		{
			r1 = word_1BE6;
		};

		wMUT93_Fadout_Timer_Value = Lim_FF( MIN(r1, r2) );

		word_FFFF86D4 = (wMUT23 & M23_IDLE_MODE_RPM) ? word_1BB0 : word_1BAE;
	};

	// loc_1EDD8

	if (BC06_sub_1EEBC())
	{
		wMUT93_Fadout_Timer_Value = 0xFF;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EE08()
{
	Table_Lookup_Axis(RPM10_6552);

	wMUT8F = Lim_FF(Table_Lookup_byte_2D_3D(GENTERMDEADZON_3D80) + wMUT93_Fadout_Timer_Value);

	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		u32 r1 = 0xFF;

		if (MUT_CMD_1 & 1)
		{
			r1 = 0;
		};

		__disable_irq();

		gen_G_timer = r1;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1EE64()
{
	if ((word_FFFF8DBE & 1) || (word_FFFF8DBE & 2))
	{
		return false;
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_1BBE || (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)))
	{
		return false;
	};

	if (cranking_end_timer_up <= word_1BB4 * 20 || (wMUT71_Sensor_Error & MUT71_5_ALTERNATOR))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1EEBC()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		return true;
	};

	if (ZRO(word_FFFF8DBE, 0x8000) && (wMUT1E_MAF_RESET_FLAG & CRANKING))
	{
		return true;
	};

	if ((wMUT71_Sensor_Error & MUT71_5_ALTERNATOR) || (RT_FLAG1_FFFF8888 & AC_SWITCH) || (wMUT1E_MAF_RESET_FLAG & FUEL_CUT))
	{
		return true;
	};

	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1EF74()
{
	if (timeEvents & EVT_2_100ms)
	{
		u32 r1 = wMUT17_TPS_ADC8bit;

		WFLAG(word_FFFF8DBE, 4, Sub_Lim_0(r1, word_FFFF8902) >= word_2090);

		word_FFFF8902 = r1;
	};

	// loc_1EFC6

	if (timeEvents & EVT_3_500ms)
	{
		if (Sub_Lim_0(rpm_x125div32_B, word_FFFF8940) >= word_2088)
		{
			word_FFFF8604 = word_208A;
		};

		word_FFFF8940 = rpm_x125div32_B;
	};

	// loc_1EFFE

	if ((huge_timeEvents & 0x2000) || (word_FFFF8DBE & 4))
	{
		SET(word_FFFF8DBE, 8);

		word_FFFF8604 = word_208A;
	};

	if (word_FFFF8604 == 0)
	{
		CLR(word_FFFF8DBE, 8);
	};

	// loc_1F032

	WFLAG(word_FFFF8DBE, 0x10, ((RT_FLAG1_FFFF8888 & RACING) && word_FFFF8606 != 0) || (word_FFFF8DBE & 8));

	// loc_1F08A

	if (ZRO(RT_FLAG1_FFFF8888, RACING))
	{
		word_FFFF8606 = word_208E;
		word_FFFF87B8 = word_208C << 2;
	};

	// loc_1F0A4

	if (word_FFFF8DBE & 0x10)
	{
		word_FFFF86FC = word_1BD2;
		word_FFFF8608 = word_1BD8;
		word_FFFF87B6 = word_1BDC;
	}
	else
	{
		word_FFFF87B2 = word_1BD4;
		word_FFFF86FE = word_1BD6;

		if (ZRO(RT_FLAG1_FFFF8888, 0x80) || (wMUT1E_MAF_RESET_FLAG & FUEL_CUT))
		{
			word_FFFF87B6 = word_1BDC;
		};
	};

	// loc_1F0E8

	if (word_FFFF8608 != 0)
	{
		word_FFFF87B4 = word_1BDA;
	};

	// loc_1F0F8

	u32 r13 = word_FFFF8DBE;
	
	if (r13 & 0x40) 
	{
		CLR(r13, 0x20);
	}
	else if (word_FFFF86FC == 0)
	{
		SET(r13, 0x20);
	};

	// loc_1F116

	if (ZRO(word_FFFF8DBE, 0x10) || word_FFFF87B2 == 0)
	{
		CLR(r13, 0x40);
	}
	else if (r13 & 0x20)
	{
		SET(r13, 0x40);
	};

	// loc_1F138

	if (word_FFFF86FE == 0)
	{
		SET(r13, 0x80);
	};

	// loc_1F144

	if (word_FFFF87B4 == 0)
	{
		CLR(r13, 0x180);
	}
	else if (word_FFFF8DBE & 0x10)
	{
		if (r13 & 0x100)
		{
			CLR(r13, 0x180);
		};
	}
	else if ((r13 & 0x80) && word_FFFF8608 == 0)
	{
		SET(r13, 0x100);
	};

	// loc_1F176

	word_FFFF8DBE = (word_FFFF8DBE & ~0x1E0) | (r13 & 0x1E0); 

	TRG(word_FFFF8DBE, 0x4000, wMUT10_Coolant_Temperature_Scaled, word_218A, word_2188);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1F24C()
{
	u32 r13 = word_2092;

	if (word_FFFF8DBE & 0x1C00)
	{
		r13 = word_2096;
	}
	else if (word_FFFF8DBE & 0x200)
	{
		r13 = word_2094;
	};

	// loc_1F276

	WFLAG(word_FFFF8DBE, 0x200, bMUT8E_Solenoid_Duty >= r13);

	// loc_1F29A

	if (BC06_sub_1F334())
	{
		WFLAG(word_FFFF8DBE, 0x1000, (word_FFFF8DBE & 0x40) && ZRO(RT_FLAG1_FFFF8888, RT_7_bit));

		// loc_1F2CC

		WFLAG(word_FFFF8DBE, 0x800, (word_FFFF8DBE & 0x100) && ZRO(RT_FLAG1_FFFF8888, RT_7_bit));

		WFLAG(word_FFFF8DBE, 0x400, (RT_FLAG1_FFFF8888 & RT_7_bit) && word_FFFF87B6 != 0);
	}
	else
	{
		// loc_1F322

		CLR(word_FFFF8DBE, 0x1C00);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool BC06_sub_1F334()
{
	if ((word_FFFF8DBE & 0x203) || ZRO(word_FFFF8DBE, 0x40) || word_FFFF87B8 == 0)
	{
		return false;
	};

	if ((RT_FLAG1_FFFF8888 & (POWER_STEERING|AC_SWITCH)) || (wMUT1E_MAF_RESET_FLAG & (STALL||CRANKING)) || cranking_end_timer_up <= word_218C)
	{
		return false;
	};

	if ((wMUT71_Sensor_Error & (MUT71_0_COOLANT|MUT71_3_MAP|MUT71_5_ALTERNATOR)) || (wMUT40_Stored_Faults_Lo & 8))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


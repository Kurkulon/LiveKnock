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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_sub_1BEFE();
static void BC06_root_sub_1BF7A();
static void BC06_sub_1C0BC();
static void BC06_sub_1C0EA();
static void BC06_sub_1C11C();
static bool BC06_sub_1C14A();
static void BC06_sub_1C5EC();
static void BC06_sub_1C68A();
static void BC06_sub_1C8C4();
static void BC06_sub_1CACC();
static void BC06_sub_1CAFE();
static void BC06_sub_1CB66();
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

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1C0BC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1C0EA()
{

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
	u32 r3 = wMUT17_TPS_ADC8bit;
	u32 r6 = 1;

	if (byte_1069 != 0 && (RT_FLAG1_FFFF8888 & RT_FLAG1_COPY_FFFF888A & AC_SWITCH) && word_FFFF85E6 == 0)
	{
		r6 = 1;
		word_FFFF860C = word_2248;
	};

	
	if (ZRO(RT_FLAG1_FFFF8888 | RT_FLAG1_COPY_FFFF888A, AC_SWITCH) && word_FFFF860C == 0)
	{
		r6 = 0;
		word_FFFF85E6 = word_1A7A;
	};

	if (((RT_FLAG1_FFFF8888 & RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_COPY_FFFF888A) & AC_SWITCH) && word_FFFF8704 != 0)
	{
		r6 = 0;
		word_FFFF860C = 0;
	};

	if (MUT21_RPM_x125div4 < word_1A80)
	{
		r6 = 0;
		word_FFFF85E8 = word_1A7C;
	};

	// loc_1C1E8

	TRG(r13, 4, wMUT2E_Vehicle_Speed_Frequency, word_1A90, word_1A8E);

	// loc_1C224

	TRG(r13, 2, r3, word_1A8C, word_1A8A);

	// loc_1C24E

	if (byte_1048/*0xF*/ == 0 || (RT_FLAG1_FFFF8888 & 0x20) || ((byte_1048/*0xF*/ & 4) && wMUT11_Intake_Air_Temperature_Scaled > word_20F0))
	{
		// loc_1C292

		word_FFFF86D2 = 0;
	}
	else if (ZRO(r13, 4) && ((Bitmap_Store_I_FFFF8CFE ^ r13) & r13 & 2))
	{
		word_FFFF86D2 = word_1A92;
	};

	// loc_1C298

	TRG(r13, 1, r3, word_1A84, word_1A82);

	// loc_1C2C2

	if ((ZRO(byte_1048, 8) && (RT_FLAG1_FFFF8888 & 0x20))
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
		&& ZRO(RT_FLAG1_FFFF8888, 0x80)
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

	TRG(Bitmap_Store_I_FFFF8CFE, 0x2000, r3, word_2C8A, word_2C88);

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

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1C68A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1C8C4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CACC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CAFE()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void BC06_sub_1CB66()
{

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


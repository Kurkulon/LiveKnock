#pragma section _HUGE

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
//#define F500_sub_21C80		((bool(*)(void))0x21C80)

#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

#define Get_ADC_Bat_TPS_oxigen	((void(*)(void))0xA8DC)


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


static void HUGE_Method_801_6_Hz();
static void Huge_400_Hz();

static void Huge_200_Hz();



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_ATU_2A_2B_3_4_5_8_10()
{
	__disable_irq();

	reg_PSCR1 = 3; // 4 MHz

	reg_PSCR4 = 3; // 4 MHz

	reg_TCR2A = 0x34; // 250kHz
	reg_TCR2B = 0x34;
	reg_TCR3 = 0x34;
	reg_TCR4 = 0x34;
	reg_TCR5 = 0x34;

	reg_TCR8 = reg_TCR8 & 0xF | 0x50;

	reg_TIOR10 = 0x30;
	reg_TCR10 = 0;
	reg_TIER10 = 0x10;
	reg_TMDR = 0;
	reg_TSTR1 = reg_TSTR1 & 2 | 0x7D;

	reg_CMCOR0 = 2495; // period
	reg_CMCSR0 = 0x40; // Pô/8 = 2MHz
	CLR(reg_CMCSR0, 0x80); // reset irq
	SET(reg_CMSTR, 1);		// start CMT0

	word_FFFF9AD2 = reg_TCNT2A + 312;

	CLR(reg_TIER3, 0x3A0);

	reg_TIOR4A = 0x11;
	reg_TIOR4B = 0x11;
	CLR(reg_TIER3, 0x40);

	downTimer_801 = 1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(cmti0)

extern "C" void cmti0()
{
	__disable_irq();

	word_FFFF9AD6 = reg_TCNT2A;

	CLR(reg_CMCSR0, 0x80);

	DECLIM(downTimer_801);

	word_FFFF9AD2 += 312;

	if ((word_FFFF9AD2 - reg_TCNT2A) & 0x8000)
	{
		word_FFFF9AD2 += 312;

		__enable_irq();

		HUGE_Method_801_6_Hz();

		HUGE_Method_801_6_Hz();
	}
	else
	{
		__enable_irq();

		HUGE_Method_801_6_Hz();

		word_FFFF9AD4 = reg_TCNT2A - word_FFFF9AD6;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void HUGE_Method_801_6_Hz()
{
	
	Huge_400_Hz();

	Huge_200_Hz();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Huge_400_Hz()
{
	if (hugeCallCounter & 1) 
	{
		return;
	};

	// loc_26BB0
		


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Huge_200_Hz()
{
	if (hugeCallCounter & 3) 
	{
		return;
	};

	// loc_26E90

	Get_ADC_Bat_TPS_oxigen();

	prev_TPS_Corrected = wMUT8A_TPS_Corrected;

	wMUT8A_TPS_Corrected = Lim_FF(Sub_Lim_0(wMUT1B_TPS_Idle_Adder + wMUT17_TPS_ADC8bit, 0x80));

	if (bMUTD2_FBA_MAF_MAP_FLAG & 8)
	{
		// loc_26ECE

		u32 r1 = TPS_ADC10bit;

		if (r1 > const_TPS_206C/*192*/)
		{
			CLR(NVRAM_FFFF802C, 4);
		};

		u32 r2;

		if (  (RPM_FLAGS & (RPM_0_CRANKING|RPM_4_STALL)) 
			|| cranking_end_timer_up <= word_2074/*200*/
			|| wMUT14_Battery_Level_ADC8bit <= word_2072/*136*/
			|| r1 < const_TPS_206E/*40*/
			|| r1 > const_TPS_206C/*192*/
			|| RT_FLAG1_FFFF8888 & RACING	)
		{
			r2 = 0;	
		}
		else
		{
			r2 = 1;

			if (ZRO(NVRAM_FFFF802C, 2) && ZRO(hugeCallCounter, 0x7F) && r1 >= TPS_NVRAM_FFFF802A)
			{
				u32 r13 = Sub_Lim_0(TPS_NVRAM_FFFF802A, word_2078/*12*/);

				TPS_NVRAM_FFFF802A = (r13 >= r1) ? r13 : r1; 
			};
		};

		// loc_26FA4

		u32 r13 = Add_Lim_FFFF(word_FFFF8924, word_2076/*4*/);

		if (r2 == 0 || word_FFFF8924 > r1 || r1 > r13)
		{
			timer_FFFF8584 = t1_unk_2070/*120*/;
			
			// loc_2703A
			
			word_FFFF8924 = r1;
		}
		else if (timer_FFFF8584 == 0)
		{	
			timer_FFFF8584 = t1_unk_2070/*120*/;

			if (TPS_NVRAM_FFFF802A >= word_FFFF8924)
			{
				// loc_2701E

				SET(NVRAM_FFFF802C, 2);

				TPS_NVRAM_FFFF802A = word_FFFF8924;

				// loc_2703A
				
				word_FFFF8924 = r1;
			}
			else if (ZRO(NVRAM_FFFF802C, 4))
			{
				SET(NVRAM_FFFF802C, 6);

				r13 = Add_Lim_FFFF(TPS_NVRAM_FFFF802A, 4);

				TPS_NVRAM_FFFF802A = (r13 > word_FFFF8924) ? word_FFFF8924 : r13;

				// loc_2703A
				
				word_FFFF8924 = r1;
			};
		};

		// loc_2703E

		r2 = Add_Lim_FFFF(TPS_NVRAM_FFFF802A, word_2068);


	};

	// loc_271D6
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
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

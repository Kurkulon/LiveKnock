#pragma section _idle

#include <umachine.h>

#include "ram.h"
#include "misc.h"


static void AA05_IDLE_sub_192FC();
static void AA05_sub_1945C();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define byte_102E							(*(const byte*)0x102E)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define word_19E6							(*(const u16*)0x19E6)
#define word_18C0							(*(const u16*)0x18C0)
#define word_18C2							(*(const u16*)0x18C2)
#define word_18C4							(*(const u16*)0x18C4)
#define Desired_Idle_RPM_with_AC_on_18BE	(*(const u16*)0x18BE)
#define word_1A20							(*(const u16*)0x1A20)
#define word_1A22							(*(const u16*)0x1A22)
#define word_1A24							(*(const u16*)0x1A24)
#define word_1A26							(*(const u16*)0x1A26)

#define CEL8_6DA0							(*(const u16*)0x6DA0)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define SPEED_FLAGS						(*(u16*)0xFFFF8A0A)
#define word_FFFF8CBC					(*(u16*)0xFFFF8CBC)
#define word_FFFF8CBE					(*(u16*)0xFFFF8CBE)
#define word_FFFF86C2					(*(u16*)0xFFFF86C2)
#define u16_FLAGS_FFFF8C96				(*(u16*)0xFFFF8C96)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define VOLT9_66C6							((Axis*)0x66C6)
#define RPM8_6570							((Axis*)0x6570)
#define LOAD9_65DC							((Axis*)0x65DC)
#define BAR4_66F6							((Axis*)0x66F6)
#define CEL8_6914							((Axis*)0x6914)
#define CEL8_79AE							((Axis*)0x79AE)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define IDLERPMDRV_7A08						((Map3D_B**)0x7A08)
#define IDLERPMNEYT_7A28					((Map3D_B**)0x7A28)



#define IDLERPMNS_485E						((Map3D_B*)0x485E)

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


#define sub_21ECC							((u16(*)(u16))0x21ECC)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
static void F500_sub_10C6E()
{
	if ((wMUT1E_MAF_RESET_FLAG & STALL) == 0)
	{
		Table_Lookup_Axis(BAR5_6D66);

		u32 r1 = Table_Lookup_byte_2D_3D(AFRRPM_4C1A);

		u32 r2 = wMUT31_Volumetric_Efficiency + word_1524;

		Mul_R4_R5w_Div_R6w_R0(Mul_R4_R5w_div256__R0(MUT21_RPM_x125div4 * word_223E * 1067, r2), wMUT1C_ECU_Load * r1, 26240);

		
	}
	else
	{

	};
}
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static void AA05_IDLE_sub_192FC()
{
	u16 r1;

	if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x20) // Engine Running
	{
		if (SPEED_FLAGS & 4)
		{
			r1 = Query_byte_2D_3D_Table(IDLERPMDRV_7A08);
		}
		else
		{
			r1 = Table_Lookup_byte_2D_3D(IDLERPMNS_485E);
		};

		if ((RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x4000) && r1 < word_19E6)
		{
			r1 = word_19E6;
		};
	}
	else
	{
		r1 = Query_byte_2D_3D_Table(IDLERPMNEYT_7A28);
	};

	word_FFFF8CBC = r1;

	AA05_sub_1945C();

	if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x10) 
	{
		u16 r13;

		if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x20) 
		{
			if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 1) 
			{
				r13 = word_18C2;
			}
			else
			{
				r13 = Desired_Idle_RPM_with_AC_on_18BE;
			};
		}
		else
		{
			if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 1) 
			{
				r13 = word_18C4;
			}
			else
			{
				r13 = word_18C0;
			};
		};

		if (r13 >= r1)
		{
			r1 = r13;
		};
	};

	if (r1 < word_FFFF8CBE)
	{
		r1 = word_FFFF8CBE;
	};

	wMUT24_Target_Idle_RPM = sub_21ECC(Lim_R4_max_FF(r1));


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1945C()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		SET(u16_FLAGS_FFFF8C96, 0x20);

		word_FFFF86C2 = 0;
	};

	if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{
		if (wMUT11_Intake_Air_Temperature_Scaled > word_1A26)
		{
			SET(u16_FLAGS_FFFF8C96, 0x20);
		}
		else
		{
			CLR(u16_FLAGS_FFFF8C96, 0x20);
		};

	};

	word_FFFF86C2 = (wMUT11_Intake_Air_Temperature_Scaled > word_1A20) ? word_1A24 * 80 : 0;

	if (word_FFFF86C2 != 0 && (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x20))
	{
		u16 r1 = 0;

		if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x10)
		{		
			if (byte_102E == 2 && (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 1))
			{
				r1 = word_18C2 + MUL_R4w_R5w_DIV_R6w_Round_R0(word_FFFF86C2, word_1A22, word_1A24 * 80);
			};
		}
		else
		{
			r1 = MUL_R4w_R5w_DIV_R6w_Round_R0(word_FFFF86C2, word_1A22, word_1A24 * 80);

			u16 r2 = CEL8_6DA0 - 1;

			Map3D_B *p = (SPEED_FLAGS & 4) ? (Map3D_B*)GET_LOC_DIM_sub_DF6(IDLERPMDRV_7A08) : IDLERPMNS_485E;

			r1 += p->m2d.data[r2];
		};

		word_FFFF8CBE = Lim_R4_max_FF(r1);
	}
	else
	{
		word_FFFF8CBE = 0;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

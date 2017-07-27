#pragma section _idle

#include <umachine.h>

#include "ram.h"
#include "misc.h"
#include "constbyte.h"
#include "constword.h"




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define byte_102E							(*(const byte*)0x102E)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define word_19E6							(*(const u16*)0x19E6)
//#define word_18C0							(*(const u16*)0x18C0)
//#define word_18C2							(*(const u16*)0x18C2)
//#define word_18C4							(*(const u16*)0x18C4)
//#define Desired_Idle_RPM_with_AC_on_18BE	(*(const u16*)0x18BE)
//#define word_1A20							(*(const u16*)0x1A20)
//#define word_1A22							(*(const u16*)0x1A22)
//#define word_1A24							(*(const u16*)0x1A24)
//#define word_1A26							(*(const u16*)0x1A26)

#define CEL8_6DA0							(*(const u16*)0x6DA0)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define SPEED_FLAGS						(*(u16*)0xFFFF8A0A)
//#define word_FFFF8CBC					(*(u16*)0xFFFF8CBC)
//#define word_FFFF8CBE					(*(u16*)0xFFFF8CBE)
//#define word_FFFF86C2					(*(u16*)0xFFFF86C2)
//#define u16_FLAGS_FFFF8C96				(*(u16*)0xFFFF8C96)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define VOLT9_66C6							((Axis*)0x66C6)
#define RPM8_6570							((Axis*)0x6570)
#define LOAD9_65DC							((Axis*)0x65DC)
#define BAR4_66F6							((Axis*)0x66F6)
#define CEL8_6914							((Axis*)0x6914)
#define CEL8_79AE							((Axis*)0x79AE)

#define CEL8_6946_IDLE						((Axis*)0x6946)
#define RPM27_6960_IDLE						((Axis*)0x6960)





//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define IDLERPMDRV_7A08						((Map3D_B**)0x7A08)
#define IDLERPMNEYT_7A28					((Map3D_B**)0x7A28)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define IDLERPMNS_485E						((Map3D_B*)0x485E)
#define IDLESTEPLOOKtab_476C				((Map3D_B*)0x476C)

//#define KNOCKLOAD_3A6E						((Map3D_B*)0x3A6E)
//#define knockLoad_OctaneUpdate				((Map3D_B*)0x3A80)
//#define IGNCOILCHGTIME1_3A3E				((Map3D_B*)0x3A3E)
//#define IGNCOILCHGTIME2_3A4E				((Map3D_B*)0x3A4E)
//#define IGNCOILCHGTIME3_3A5E				((Map3D_B*)0x3A5E)
//#define unk023_59E4							((Map3D_B*)0x59E4)
//#define unk028_5FFE							((Map3D_B*)0x5FFE)
//#define unk118_59CE							((Map3D_B*)0x59CE)
//#define unk033_589E							((Map3D_B*)0x589E)
//#define unk032_588E							((Map3D_B*)0x588E)
//#define unk115_58AE							((Map3D_B*)0x58AE)
//#define unk116_58B8							((Map3D_B*)0x58B8)
//#define LOWTRMTEMPCOOL_3A30					((Map3D_B*)0x3A30)
//#define AFRAIRTEMP1_630A					((Map3D_B*)0x630A)
//#define IGNTRMAIRTEMPLOAD_3A1E				((Map3D_B*)0x3A1E)
//#define IGNTRMAIRTEMP_3A04					((Map3D_B*)0x3A04)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define sub_21ECC							((u16(*)(u16))0x21ECC)
#define sub_21EF8							((u16(*)(void))0x21EF8)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_NVRAM_18F80();
static void SysInit_sub_19014();
extern "C" void AA05_root_sub_19096();
static void AA05_sub_19188();
static void AA05_sub_19260();
static void AA05_sub_1929C();
static void AA05_sub_192CA();
static void AA05_IDLE_sub_192FC();
static void AA05_sub_1945C();
static void AA05_sub_195A2();
static void AA05_sub_19804();
static void AA05_sub_1997C();
static void AA05_GENERATOR_CHARGING_sub_19A2C();
static void AA05_sub_19B98();
static void AA05_sub_19E10();
static void AA05_Init_sub_19E2A();
static u16 AA05_IDLESTEPLOOKtab_sub_19E5A(u16);
static void AA05_sub_19E8C();
static void AA05_sub_19EEC();
static void AA05_sub_19F0E();
static void AA05_sub_19F22();
static void AA05_sub_1A068();
static void AA05_sub_1A0BA();
static void AA05_sub_1A0E8();
static void AA05_sub_1A11C();
static void AA05_sub_1A304();
static void AA05_sub_1A3F8();
static void AA05_sub_1A448();
static void AA05_sub_1A462();
static void AA05_sub_1A476();
static void AA05_sub_1A4A6();
static void AA05_sub_1A4F2();
static void AA05_sub_1A58E();
static void AA05_sub_1A5A8();
static void AA05_sub_1A74E();
static void AA05_sub_1A7E0();
static void AA05_sub_1A8CA();
static void AA05_sub_1A99C();
static void AA05_sub_1A9D0();
static void AA05_sub_1AAB4();
static void AA05_sub_1AB00();
static void AA05_sub_1AB72();
static void AA05_sub_1ABA4();
static void AA05_sub_1ABEC();
static void AA05_Set_MUT22_0x04();
static void AA05_sub_1AD34();
static void AA05_sub_1ADF4();
static void AA05_sub_1AE26();
static void AA05_sub_1AE76();
static void AA05_sub_1AE90();
static void AA05_sub_1AEC6();
static void AA05_sub_1AF30();
static void AA05_sub_1B178();
static void AA05_sub_1B196();
static void AA05_sub_1B260();
static void AA05_sub_1B282();
static void AA05_sub_1B470();
static void AA05_sub_1B4C2();
static void AA05_sub_1B588();
static void AA05_sub_1B652();
static void AA05_sub_1B67E();
static void AA05_sub_1B7C0();
static void AA05_sub_1B7EA();
static void AA05_sub_1B81C();
static void AA05_sub_1B876();
static void AA05_sub_1B89C();
static void AA05_Return_0_1();
static void AA05_sub_1B8CA();
static void AA05_sub_1B8F2();
static void AA05_sub_1B934();
static void AA05_sub_1BA2C();
static void AA05_sub_1BAC6();
static void AA05_sub_1BAFE();
static void AA05_sub_1BB1A();
static void AA05_sub_1BB96();
static void AA05_sub_1BC6E();
static void AA05_sub_1BD34();
static void AA05_sub_1BD6C();
static void AA05_sub_1BDA0();
static void AA05_sub_1BDC6();
static void AA05_sub_1BE74();


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_NVRAM_18F80()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_sub_19014()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void AA05_root_sub_19096()
{
	AA05_sub_19188();
	AA05_sub_1A7E0();
	AA05_sub_1AD34();

	if (sub_21EF8() != 0 && (wMUT22 & 0xB0) == 0)
	{
		word_FFFF8CA8 = AA05_IDLESTEPLOOKtab_sub_19E5A(word_FFFF8CAA = wMUT9E);
		CLR(wMUT22, 0x3F);
		CLR(wMUT23, 0xB5);
	};

	AA05_sub_1BD6C();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19188()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19260()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1929C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_192CA()
{

}

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

	wMUT24_Target_Idle_RPM = sub_21ECC(Lim_FF(r1));


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
				r1 = word_18C2 + Mul_Div_R(word_FFFF86C2, word_1A22, word_1A24 * 80);
			};
		}
		else
		{
			r1 = Mul_Div_R(word_FFFF86C2, word_1A22, word_1A24 * 80);

			u16 r2 = CEL8_6DA0 - 1;

			Map3D_B *p = (SPEED_FLAGS & 4) ? (Map3D_B*)GET_LOC_DIM_sub_DF6(IDLERPMDRV_7A08) : IDLERPMNS_485E;

			r1 += p->m2d.data[r2];
		};

		word_FFFF8CBE = Lim_FF(r1);
	}
	else
	{
		word_FFFF8CBE = 0;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_195A2()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19804()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1997C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_GENERATOR_CHARGING_sub_19A2C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19B98()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19E10()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_Init_sub_19E2A()
{
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_IDLESTEPLOOKtab_sub_19E5A(u16 v)
{
	Table_Lookup_Axis(CEL8_6946_IDLE);

	wMUTB4_lookup_value = v;

	Table_Lookup_Axis(RPM27_6960_IDLE);

	return Table_Lookup_byte_2D_3D(IDLESTEPLOOKtab_476C);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19E8C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19EEC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19F0E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19F22()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A068()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A0BA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A0E8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A11C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A304()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A3F8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A448()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A462()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A476()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A4A6()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A4F2()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A58E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A5A8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A74E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A7E0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A8CA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A99C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A9D0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AAB4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AB00()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AB72()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1ABA4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1ABEC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_Set_MUT22_0x04()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AD34()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1ADF4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AE26()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AE76()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AE90()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AEC6()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AF30()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B178()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B196()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B260()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B282()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B470()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B4C2()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B588()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B652()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B67E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B7C0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B7EA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B81C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B876()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B89C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_Return_0_1()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B8CA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B8F2()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B934()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BA2C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BAC6()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BAFE()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BB1A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BB96()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BC6E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BD34()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BD6C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BDA0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BDC6()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BE74()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#pragma section _Ignition

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"

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

static bool	IG04_sub_179C4(); // no call

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
static u16 	IG04_GetLoad_sub_1821E(); // inlined in GetLoadCorrectedDeltaTPS
static u16 	IG04_Ign_Temp_Correct(u16 v);
static u16 	IG04_IGNIT_TESTS_183E8(u16 v);
static bool IG04_sub_18464();
static u16 	IG04_Ignition_Fuel_Timing_Calcs_sub_18494();
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
static void IG04_sub_18C86();
static void IG04_sub_18D84();

static u16 	IG04_sub_21DCE(u16 v);

static u16 	Barometric_Correction_sub_22084();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define IGN_TEST_FLAG_0_F32					(*(const byte*)0xF32)

#define byte_1034							(*(const byte*)0x1034)
#define byte_1035							(*(const byte*)0x1035)
#define byte_1036							(*(const byte*)0x1036)
#define byte_1037							(*(const byte*)0x1037)
#define IGN_TEST_FLAG_1044					(*(const byte*)0x1044)
#define byte_1052							(*(const byte*)0x1052)
#define byte_105A							(*(const byte*)0x105A)
#define byte_1060							(*(const byte*)0x1060)
#define byte_1064							(*(const byte*)0x1064)
#define byte_1074							(*(const byte*)0x1074)
#define byte_1075							(*(const byte*)0x1075)
#define byte_1077							(*(const byte*)0x1077)

//#define byte_3A44							(*(const byte*)0x3A44)
//#define byte_3A64							(*(const byte*)0x3A64)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define unk119_59DE							((const byte*)0x59DE)
#define unk120_59F2							((const byte*)0x59F2)
#define unk121_59F8							((const byte*)0x59F8)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define asyncAccelMinTPS_Delta				(*(const u16*)0x169A)
//
//#define t1_unk_1758							(*(const u16*)0x1758)
//
//#define word_178A							(*(const u16*)0x178A)
//#define fixTimingValue						(*(const u16*)0x178C)
//#define word_17A0							(*(const u16*)0x17A0)
//
//#define word_17A8							(*(const u16*)0x17A8)
//#define word_17AA							(*(const u16*)0x17AA)
//
//#define word_17B2							(*(const u16*)0x17B2)
//#define word_17B4							(*(const u16*)0x17B4)
//#define word_17B6							(*(const u16*)0x17B6)
//#define word_17B8							(*(const u16*)0x17B8)
//#define word_17BA							(*(const u16*)0x17BA)
//#define word_17BC							(*(const u16*)0x17BC)
//#define word_17BE							(*(const u16*)0x17BE)
//#define word_17C0							(*(const u16*)0x17C0)
//#define word_17C2							(*(const u16*)0x17C2)
//#define word_17C4							(*(const u16*)0x17C4)
//#define word_17C6							(*(const u16*)0x17C6)
//#define word_17C8							(*(const u16*)0x17C8)
//#define word_17CA							(*(const u16*)0x17CA)
//
//#define knockAdder_TripleGain				(*(const u16*)0x17D8)
//#define knockAdder_SingleGain				(*(const u16*)0x17DA)
//#define const_24							(*(const u16*)0x17DC)
//
//#define word_17E4							(*(const u16*)0x17E4)
//#define t1_knock_control_accel_delta_17E6	(*(const u16*)0x17E6)
//#define word_17F2							(*(const u16*)0x17F2)
//#define word_17F4							(*(const u16*)0x17F4)
//#define minCoolTempOctanUpdate				(*(const u16*)0x17FC)
//#define minKnockLim							(*(const u16*)0x17FE)
//#define maxKnockLim							(*(const u16*)0x1800)
//#define word_1802							(*(const u16*)0x1802)
//#define word_1804							(*(const u16*)0x1804)
//#define word_1810							(*(const u16*)0x1810)
//#define word_1812							(*(const u16*)0x1812)
//#define word_1814							(*(const u16*)0x1814)
//#define word_1816							(*(const u16*)0x1816)
//#define word_1818							(*(const u16*)0x1818)
//#define word_181A							(*(const u16*)0x181A)
//#define word_181C							(*(const u16*)0x181C)
//
//
//#define word_1836							(*(const u16*)0x1836)
//#define word_1838							(*(const u16*)0x1838)
//#define word_183A							(*(const u16*)0x183A)
//#define word_183C							(*(const u16*)0x183C)
//#define word_183E							(*(const u16*)0x183E)
//#define word_1840							(*(const u16*)0x1840)
//#define word_1842     						(*(const u16*)0x1842)
//#define word_1844     						(*(const u16*)0x1844)
//#define word_1846     						(*(const u16*)0x1846)
//#define CTEMPER40_1848						(*(const u16*)0x1848)
//#define word_184A     						(*(const u16*)0x184A)
//#define word_184C     						(*(const u16*)0x184C)
//#define word_184E     						(*(const u16*)0x184E)
//#define word_1850     						(*(const u16*)0x1850)
//#define word_1852							(*(const u16*)0x1852)
//#define word_1854     						(*(const u16*)0x1854)
//#define CTEMPER39_1856						(*(const u16*)0x1856)
//#define CTEMPER38_1858						(*(const u16*)0x1858)
//#define word_185A     						(*(const u16*)0x185A)
//#define word_185C     						(*(const u16*)0x185C)
//#define word_1868     						(*(const u16*)0x1868)
//#define word_186A     						(*(const u16*)0x186A)
//#define word_186C     						(*(const u16*)0x186C)
//#define word_186E     						(*(const u16*)0x186E)
//#define word_1870     						(*(const u16*)0x1870)
//#define word_1872     						(*(const u16*)0x1872)
//#define word_1874     						(*(const u16*)0x1874)
//#define word_1876     						(*(const u16*)0x1876)
//#define word_1878     						(*(const u16*)0x1878)
//#define word_187C     						(*(const u16*)0x187C)
//#define word_187E     						(*(const u16*)0x187E)
//#define word_1880     						(*(const u16*)0x1880)
//#define word_1882     						(*(const u16*)0x1882)
//#define word_1884     						(*(const u16*)0x1884)
//#define word_1886     						(*(const u16*)0x1886)
//#define word_1888							(*(const u16*)0x1888)
//#define word_188A							(*(const u16*)0x188A)
//#define word_188C							(*(const u16*)0x188C)
//#define word_188E							(*(const u16*)0x188E)
//#define word_1890							(*(const u16*)0x1890)
//#define word_1892							(*(const u16*)0x1892)
//#define word_1894							(*(const u16*)0x1894)
//#define word_1896							(*(const u16*)0x1896)
//
//
//#define word_18A6							(*(const u16*)0x18A6)
//#define word_18A8							(*(const u16*)0x18A8)
//#define word_18AA							(*(const u16*)0x18AA)
//#define word_18AC							(*(const u16*)0x18AC)
//#define word_18AE							(*(const u16*)0x18AE)
//
//#define word_18B0							(*(const u16*)0x18B0)
//#define word_18B2							(*(const u16*)0x18B2)
//#define word_18B4							(*(const u16*)0x18B4)
//
//#define word_1A54							(*(const u16*)0x1A54)
//#define word_1B02							(*(const u16*)0x1B02)
//#define t1_1B08								(*(const u16*)0x1B08)
//#define word_1B0A							(*(const u16*)0x1B0A)
//
//#define word_1C26							(*(const u16*)0x1C26)
//#define word_1C28							(*(const u16*)0x1C28)
//#define word_1C2A							(*(const u16*)0x1C2A)
//
//#define word_207A							(*(const u16*)0x207A)
//#define word_207C							(*(const u16*)0x207C)
//
//#define word_20B0							(*(const u16*)0x20B0)
//#define word_20B2							(*(const u16*)0x20B2)
//#define word_20B4							(*(const u16*)0x20B4)
//
//#define word_2196							(*(const u16*)0x2196)
//#define word_2198							(*(const u16*)0x2198)
//
//#define word_21A0							(*(const u16*)0x21A0)
//
//#define word_2336							(*(const u16*)0x2336)
//#define word_2338							(*(const u16*)0x2338)
//#define word_233A							(*(const u16*)0x233A)
//#define word_233C							(*(const u16*)0x233C)
//#define word_233E							(*(const u16*)0x233E)
//#define word_2340							(*(const u16*)0x2340)
//#define word_2342							(*(const u16*)0x2342)
//#define word_2344							(*(const u16*)0x2344)
//#define word_2346							(*(const u16*)0x2346)
//#define word_2348							(*(const u16*)0x2348)
//#define word_234A							(*(const u16*)0x234A)
//
//#define word_24F8							(*(const u16*)0x24F8)
//#define word_24FA							(*(const u16*)0x24FA)
//
//#define word_2502							(*(const u16*)0x2502)
//#define word_2504							(*(const u16*)0x2504)
//#define word_2506							(*(const u16*)0x2506)
//#define word_2508							(*(const u16*)0x2508)
//
//#define word_262A							(*(const u16*)0x262A)
//#define word_262C							(*(const u16*)0x262C)
//
//#define word_2B64							(*(const u16*)0x2B64)
//
//
//#define word_2C96							(*(const u16*)0x2C96)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define KNOCK_REL_1_FFFF8C4C						(*(u16*)0xFFFF8C4C)
//#define word_FFFF9942								(*(u16*)0xFFFF9942)
//#define load_ECU_Ignintion							(*(u16*)0xFFFF895A)
//#define IGN_FLAG9_FFFF8BB6							(*(u16*)0xFFFF8BB6)
//#define octaneNum									(*(u16*)0xFFFF80B6)
//#define FLAGS_FFFF8EB0								(*(u16*)0xFFFF8EB0)
//#define KNOCK_VAR2_FFFF8C3E							(*(u16*)0xFFFF8C3E)
//#define KNOCK_VAR1_bMUTC9_FFFF8C3C					(*(u16*)0xFFFF8C3C)
//#define KNOCK_BASE_FFFF8C3A							(*(u16*)0xFFFF8C3A)
//#define KNOCK_FLAG2_FFFF887A						(*(u16*)0xFFFF887A)
//#define KNOCK_FLAG_FFFF8C34							(*(u16*)0xFFFF8C34)
//#define KNOCK_PRECOUNT_MAX_FFFF8C4A					(*(u16*)0xFFFF8C4A)
//#define cranking_end_timer_up						(*(u16*)0xFFFF8528)
//#define word_FFFF855E								(*(u16*)0xFFFF855E)
//#define coolTempCorrectedIgnTiming					(*(u16*)0xFFFF8BC6)
//#define timer_Knock									(*(u16*)0xFFFF85B4)
//#define BOOSTCHECK2_FFFF8A0E						(*(u16*)0xFFFF8A0E)
//#define VEHICLE_SPEED_0_FFFF8A3C					(*(u16*)0xFFFF8A3C)
//#define word_FFFF8BF4								(*(u16*)0xFFFF8BF4)
//#define word_FFFF8BF6								(*(u16*)0xFFFF8BF6)
//#define word_FFFF8BF8								(*(u16*)0xFFFF8BF8)
//#define word_FFFF8BFA								(*(u16*)0xFFFF8BFA)
//#define word_FFFF8BFC								(*(u16*)0xFFFF8BFC)
//#define word_FFFF8BFE								(*(u16*)0xFFFF8BFE)
//
//#define word_FFFF8D9E								(*(u16*)0xFFFF8D9E)
//#define word_FFFF8DA0								(*(u16*)0xFFFF8DA0)
//
//#define word_FFFF8C8C								(*(u16*)0xFFFF8C8C)
//#define word_FFFF8C8E								(*(u16*)0xFFFF8C8E)
//#define word_FFFF8C90								(*(u16*)0xFFFF8C90)
//#define IGN_MULT_FLAG_FFFF8DBC						(*(u16*)0xFFFF8DBC)
//#define Some_IGN_RES_FFFF8BD2						(*(u16*)0xFFFF8BD2)
//#define IGN_CORR_RPM_FFFF8BD4						(*(u16*)0xFFFF8BD4)
//#define IGNITION_FINAL3_FFFF8C0C					(*(u16*)0xFFFF8C0C)
//#define word_FFFF8C0A								(*(u16*)0xFFFF8C0A)
//#define word_FFFF8BCE								(*(u16*)0xFFFF8BCE)
//#define IGN_FLAG1_FFFF85B8							(*(u16*)0xFFFF85B8)
//#define IGNP_FFFF8C06								(*(u16*)0xFFFF8C06)
//#define IGN_PAR2_FFFF8BF0							(*(u16*)0xFFFF8BF0)
//#define Bitmap_Store_A_FFFF89EE						(*(u16*)0xFFFF89EE)
//#define word_FFFF8BCC								(*(u16*)0xFFFF8BCC)
//#define IGNITION_FINAL2_FFFF8BE6					(*(u16*)0xFFFF8BE6)
//#define IGN_0xA_FFFF8BE8							(*(u16*)0xFFFF8BE8)
//#define IGN_BARO_COMP_FFFF8BD6						(*(u16*)0xFFFF8BD6)
//#define word_FFFF8BEA								(*(u16*)0xFFFF8BEA)
//#define word_FFFF8BEC								(*(u16*)0xFFFF8BEC)
//#define word_FFFF85BA								(*(u16*)0xFFFF85BA)
//#define word_FFFF8BB8								(*(u16*)0xFFFF85B8)
//#define word_FFFF8BD0								(*(u16*)0xFFFF8BD0)
//
//#define timer_up_useless_IGN_BOOL_FLAG2_FFFF8530	(*(u16*)0xFFFF8530)
//
//#define starter_timer_up							(*(u16*)0xFFFF852A)

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
	word_FFFF8BCA = 160;

	ignCoilTime_1 = IGNCOILCHGTIME1_3A3E->m2d.data[0] << 4; // byte_3A44 << 4;
	ignCoilTime_3 = IGNCOILCHGTIME3_3A5E->m2d.data[0] << 4; // byte_3A64 << 4;

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

	KNOCK_VAR2_FFFF8C3E = t;
	KNOCK_VAR1_bMUTC9_FFFF8C3C = t;

	KNOCK_BASE_FFFF8C3A = knockAdder_TripleGain;

	KNOCK_FLAG2_FFFF887A &= ~2;

	__enable_irq();

	KNOCK_FLAG_FFFF8C34 &= 0x100;

	Knock_Output_Calc_sub_AC96();

	KNOCK_PRECOUNT_MAX_FFFF8C4A = word_1818;

	KNOCK_REL_1_FFFF8C4C = word_1812;
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
	if (Query_byte_2D_3D_Table(arr_Load_2D_RPM11) >= load_ECU_Ignintion)
	{
		IGN_FLAG9_FFFF8BB6 |= 0x40;
	}
	else
	{
		IGN_FLAG9_FFFF8BB6 &= ~0x40;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Check_Fix_timing_5_degrees()
{
	if (IG04_Is_Fix_timing_5_degrees())
	{
		IGN_FLAG9_FFFF8BB6 |= 0x80;
	}
	else
	{
		IGN_FLAG9_FFFF8BB6 &= ~0x80;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_Is_Fix_timing_5_degrees()
{
	return (RT_FLAG1_FFFF8888 & (FIX_TIMING|SPEED_ADJUST)) == FIX_TIMING;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_16FA6()
{
	if (wMUTD1_BitMap_FAA & 0x80)
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

		wMUT72_Knock_Present &= ~1;

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
	KNOCK_FLAG_FFFF8C34 |= 0x4000;

	if (IG04_Check_17074())
	{
		KNOCK_FLAG_FFFF8C34 |= 0x40;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x40;

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

		return false;
	};

	if (IGN_FLAG9_FFFF8BB6 & 0x80)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 >= word_17CA)
	{
		return false;
	};

	if ((KNOCK_FLAG_FFFF8C34 & 0x4000) == 0)
	{
		return false;
	};

	if (cranking_end_timer_up >= (word_FFFF9942 << 2))
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
		KNOCK_FLAG_FFFF8C34 |= 0x80;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x80;

		__disable_irq();

		word_FFFF855E &= 3;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_KNOCKLOAD_sub_1718E()
{
	if (wMUT1C_ECU_Load >= Table_Lookup_byte_2D_3D(KNOCKLOAD_3A6E))
	{
		KNOCK_FLAG_FFFF8C34 |= 0x1000;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x1000;
	};

	if ((wMUT71_Sensor_Error & 8) || (RT_FLAG1_FFFF8888 & 0x80) || (KNOCK_FLAG_FFFF8C34 & 0x1000) == 0)
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x2000;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 |= 0x2000;
	};

	if (wMUT71_Sensor_Error & 8)
	{
		return true;
	};

	if ((KNOCK_FLAG_FFFF8C34 & 0x1000) == 0)
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
	if (IG04_sub_1729C())
	{
		KNOCK_FLAG_FFFF8C34 |= 0x400;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x400;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_1729C()
{
	u16 r13 = (KNOCK_FLAG2_FFFF887A & 2) ? word_1C28 : word_1C2A;

	return (MUT21_RPM_x125div4 >= r13 && wMUT1C_ECU_Load >= word_1C26);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_172D6()
{
	KNOCK_PRECOUNT_MAX_FFFF8C4A = word_1818;


	TRG(KNOCK_FLAG_FFFF8C34, 0x800, MUT21_RPM_x125div4, word_1816, word_1814);


	if (KNOCK_FLAG_FFFF8C34 & 0x800)
	{	
		KNOCK_REL_1_FFFF8C4C = word_1810;
	}
	else
	{
		KNOCK_REL_1_FFFF8C4C = word_1812;
	};

	if (MUT21_RPM_x125div4 >= word_181C && MUT21_RPM_x125div4 <= word_181A)
	{
		SET(KNOCK_FLAG_FFFF8C34, 0x200);
	}
	else
	{
		CLR(KNOCK_FLAG_FFFF8C34, 0x200);
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_173F2()
{
	TRG(KNOCK_FLAG_FFFF8C34, 0x100, MUT21_RPM_x125div4, word_17F2, word_17F4);

	TRG(KNOCK_FLAG_FFFF8C34, 0x10, MUT21_RPM_x125div4, word_2504, word_2502);

	TRG(KNOCK_FLAG_FFFF8C34, 1, MUT21_RPM_x125div4, word_2508, word_2506);
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
			if (octaneNum > 0)
			{
				octaneNum -= 1;
			};

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

	if (wMUT71_Sensor_Error & 8)
	{
		return false;
	};

	if ((KNOCK_FLAG_FFFF8C34 & 0x40) == 0)
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
	wMUT27_Octane_Number = sub_21E4C(((wMUT71_Sensor_Error & 8 ) || (wMUT72_Knock_Present & 1)) ? 0 : octaneNum);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Update_MUT6F_Knock_Acceleration()
{
	if (RPM_DELTA_FFFF8948 >= 0x80 && (RPM_DELTA_FFFF8948 - 0x80) >= word_17E4)
	{
		__disable_irq();

		wMUT6F_Knock_Acceleration = t1_knock_control_accel_delta_17E6;

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

	if (byte_1064 != 0)
	{
		IG04_sub_17D04();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_176B6()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		CLR(IGN_FLAG9_FFFF8BB6, 4);

		word_FFFF8BF8 = 0;

		__disable_irq();

		word_FFFF8BF4 = 0;
		word_FFFF8BF6 = 0;
		word_FFFF8BFA = 0;

		__enable_irq();
	}
	else
	{
		if (byte_1036 != 0 && IG04_sub_17770())
		{
			SET(IGN_FLAG9_FFFF8BB6, 4);

			if (byte_1077 != 0)
			{
				IG04_sub_18D84();
			};

			__disable_irq();

			if (byte_1077 == 0)
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
			CLR(IGN_FLAG9_FFFF8BB6, 4);
		};
	};

	IG04_sub_178D0();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17770()
{
	if (RT_FLAG1_FFFF8888 & 0x80)
	{
		word_FFFF85BA = word_2C96;

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


	if (wMUT73_TPS_Open_Delta <= word_186A)
	{
		return false;
	};

	if (load_ECU_Ignintion > word_1870)
	{
		return false;
	};

	if ((RT_FLAG1_FFFF8888 & 0x20) == 0 && byte_1036 != 2)
	{
		return false;
	};
	
	if (wMUT10_Coolant_Temperature_Scaled < word_186C)
	{
		return false;
	};

	if (wMUT2E_Vehicle_Speed_Frequency < word_186E)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 < word_1872 || MUT21_RPM_x125div4 > word_1874)
	{
		return false;
	};

	if ((word_FFFF8BB8 & 2) == 0)
	{
		return false;
	};

	u16 r1 = VEHICLE_SPEED_0_FFFF8A3C;

	if (r1 >= word_1876 || r1 <= word_1878)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_178D0()
{
	if ((IGN_FLAG9_FFFF8BB6 & 4) || word_FFFF8BF4 != 0)
	{
		u16 r1;

		if (byte_1077 != 0)
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
	CLR(IGN_FLAG9_FFFF8BB6, 8);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_179C4()
{
	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17A3A()
{
	CLR(IGN_FLAG9_FFFF8BB6, 0x1000);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17A4E()
{
	if (IG04_sub_17A7E())
	{
		SET(BOOSTCHECK2_FFFF8A0E, 0x1000);
	}
	else
	{
		CLR(BOOSTCHECK2_FFFF8A0E, 0x1000);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17A7E()
{
	if ((RT_FLAG1_FFFF8888 & 0x80) || (RT_FLAG1_FFFF8888 & 0x20) == 0)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 <= word_2338 || MUT21_RPM_x125div4 > word_2336)
	{
		return false;
	};

	if (wMUT2E_Vehicle_Speed_Frequency < word_2346)
	{
		return false;
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_233E)
	{
		return false;
	};

	if (VEHICLE_SPEED_0_FFFF8A3C > word_233C || VEHICLE_SPEED_0_FFFF8A3C < word_233A)
	{
		return false;
	};

	if (load_ECU_Ignintion <= word_234A || load_ECU_Ignintion > word_2348)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17B9A()
{
	if ((wMUTD1_BitMap_FAA & 0x400) && IG04_sub_17BEC()) // timing knockdown on light acceleration and less than 3000rpm
	{
		SET(wMUT1E_MAF_RESET_FLAG, 0x8000);
	}
	else
	{
		CLR(wMUT1E_MAF_RESET_FLAG, 0x8000);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17BEC()
{
	if (RT_FLAG1_FFFF8888 & 0x80)
	{
		return false;
	};

	if ((RT_FLAG1_FFFF8888 & 0x20) == 0 && byte_1074 == 0)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 >= word_1838)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 <= word_183A)
	{
		return false;
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_1840)
	{
		return false;
	};

	if (wMUT2E_Vehicle_Speed_Frequency <= word_1A54)
	{
		return false;
	};

	if (wMUT22 & 4)
	{
		return false;
	};

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		return false;
	};

	if (VEHICLE_SPEED_0_FFFF8A3C >= word_183C)
	{
		return false;
	};

	if (VEHICLE_SPEED_0_FFFF8A3C <= word_183E)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17C6E()
{
	if (IG04_sub_17C9C())
	{
		SET(IGN_FLAG9_FFFF8BB6, 0x10);
	}
	else
	{
		CLR(IGN_FLAG9_FFFF8BB6, 0x10);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17C9C()
{
	TRG(IGN_FLAG9_FFFF8BB6, 2, MUT21_RPM_x125div4, word_17B4, word_17B2);

	if (RT_FLAG1_FFFF8888 & 0x80)
	{
		return false;
	};

	if (IGN_FLAG9_FFFF8BB6 & 2)
	{
		return false;
	};

	if (wMUT22 & 4)
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
	if (byte_1064 != 0 && (wMUT1E_MAF_RESET_FLAG & STALL) == 0)
	{
		u16 r3, r13;

		if (IGN_FLAG9_FFFF8BB6 & 0x2000)
		{
			r3 = word_18A6;
			r13 = word_18AA;
		}
		else
		{
			r3 = word_18A8;
			r13 = word_18AC;
		};

		if (wMUT2E_Vehicle_Speed_Frequency >= word_18B4)
		{
			SET(IGN_FLAG9_FFFF8BB6, 0x4000);
		};

		if (coolantTempScld_COPY_1 < word_18B2 
			&& wMUT10_Coolant_Temperature_Scaled < word_18AE 
			&& (IGN_FLAG9_FFFF8BB6 & 0x4000) == 0 
			&& (RT_FLAG1_FFFF8888 & 0x20) 
			&& MUT21_RPM_x125div4 < r3 
			&& load_ECU_Ignintion < r13)
		{
			SET(IGN_FLAG9_FFFF8BB6, 0x2000);
		}
		else
		{
			CLR(IGN_FLAG9_FFFF8BB6, 0x2000);
		};
	}
	else
	{
		CLR(IGN_FLAG9_FFFF8BB6, 0x6000);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Update_MUT04_Timing_Advance_Interpolated()
{
	Update_MUT33_Corrected_Timing_Advance();

	u16 tAdv = wMUT33_Corrected_Timing_Advance;

	if (IGN_FLAG9_FFFF8BB6 & 0x2000 && tAdv >= (word_18B0+20))
	{
		tAdv = word_18B0 + 20;
	};

	u16 r2 = IG04_Ignition_Fuel_Timing_Calcs_sub_18494();

	u16 r13;

	if (byte_1052 != 0)
	{
		r13 = IG04_sub_18570();

		if (r2 >= r13)
		{
			r2 = r13;
		};
	};

	r13 = r2;

	if (r2 < tAdv)
	{
		r13 = tAdv;
	};

	tAdv = r13 + 0x8000;

	r2 = IG04_sub_1859E();

	r13 = IG04_useless_sub_185EA();

	u16 r3;

	if (r2 >= r13)
	{
		r3 = r2;
	}
	else
	{
		r3 = r13;
	};

	r2 = tAdv + r3 - 0x80;

	r2 = r2 + IG04_Airtemp_Ignition_Compensation_sub_185FC() - 0x80;

	r2 = r2 + IG04_sub_1876E() - 0x80;

	r2 = r2 + Barometric_Correction_sub_22084() - 0x80;

	tAdv = r2 + IG04_RPM_CORR_sub_18952() - 0x80;

	if (Some_IGN_RES_FFFF8BD2 < 0x80)
	{
		r2 = word_17B8 + 0x8000;

		if (tAdv < r2) { tAdv = r2; };
	};

	tAdv = Sub_Lim_0(tAdv + IG04_SET0x80IGNPAR2_sub_18A1C() - 0x80, 0x8000);

	r2 = IG04_sub_18A2E();

	if (tAdv >= r2) { tAdv = r2; };

	if (IGN_CORR_RPM_FFFF8BD4 != 0x80)
	{
		if (tAdv < word_1852)
		{
			tAdv = word_1852;
		};
	};

	if ((IGN_FLAG9_FFFF8BB6 & 0x80) // Fix timing at 5 degrees
		|| (wMUT1E_MAF_RESET_FLAG  & 0x11))
	{
		tAdv = fixTimingValue + 20;
	};

	tAdv = Lim16(tAdv, 0, 70);

	IGNITION_FINAL3_FFFF8C0C = tAdv;

	IG04_sub_18C86(); // update word_FFFF8C0A

	if ((wMUT1E_MAF_RESET_FLAG & 0x11) == 0)
	{
		tAdv = interpolate_r4_r5_r6(tAdv, 25, word_FFFF8C0A);

		if (word_FFFF8C0A != 255 && tAdv < 25)
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

	t = IG04_sub_21DCE(t);

	wMUT33_Corrected_Timing_Advance = t;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_Update_OctanEgrIgnTiming()
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

	if (wMUTD1_BitMap_FAA & 0x80)
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

static u16 GetLoadCorrectedDeltaTPS()
{
	return load_x2_deltaTPS_corrected = IG04_GetLoad_sub_1821E() /*ECU_Load_x2_FFFF895C*/ + Mul_Fix8_R(abs_Delta_TPS * TPS_Multiplier_Delta, Table_Lookup_byte_2D_3D(table_2D_39D2));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 	IG04_GetLoad_sub_1821E()
{
	return ECU_Load_x2_FFFF895C;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define w_1822E_loc1		(*(u16*)0xFFFF86F6)
#define w_1822E_loc2		(*(u16*)0xFFFF86BE)
#define w_1822E_loc3		(*(u16*)0xFFFF8C88)
#define w_1822E_loc4		(*(u16*)0xFFFF8C8A)


static u16 IG04_Ign_Temp_Correct(u16 v)
{

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		w_1822E_loc3 = 0xff;
	}
	else if ((RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888) & RT_FLAG1_COPY_FFFF888A & 0x80)
	{
		w_1822E_loc1 = word_20B0;
		w_1822E_loc3 = 0;
	}
	else if (w_1822E_loc1 != 0)
	{
		w_1822E_loc2 = word_20B4 * 2;
	}
	else if (w_1822E_loc2 == 0)
	{
		w_1822E_loc2 = word_20B4 * 2;
		w_1822E_loc3 = Lim_FF(w_1822E_loc3 + word_20B2);
	};

	w_1822E_loc4 = 0;

	u16 r13 = 0;

	if (w_1822E_loc4 == 0
		&& (wMUTD1_BitMap_FAA & 0x200) // Enable Warmup Ign Retard
		&& cranking_end_timer_up >= word_1836)
	{
		Table_Lookup_Axis(CEL8_6914);

		u16 r3 = Table_Lookup_byte_2D_3D((byte_105A != 0 && INTAKE_AIR_TEMPERATURE_COPY_FFFF88BA < word_207A && coolantTempScld_COPY_1 < word_207C) ? LOWTRMTEMPCOOL_3A30 : LOWTRMTEMPCOOL_3A30);

		r13 = (byte_1060 != 0 && r3 >= w_1822E_loc3) ? w_1822E_loc3 : r3;
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
		 r = 20 + Mul_Fix7_R(r - 20, (IGN_MULT_FLAG_FFFF8DBC & 0x40) ? t1_1B08 : word_1B0A);
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

static u16 IG04_Ignition_Fuel_Timing_Calcs_sub_18494()
{
	if ((wMUT1E_MAF_RESET_FLAG & STALL) || MUT20_RPM_Idle_x125div16 < word_17C6 || wMUT73_TPS_Open_Delta >= asyncAccelMinTPS_Delta || wMUT56_MAX_MAP_FALL_CHANGE >= word_17C4)
	{
		__disable_irq();

		IGNITION_FINAL2_FFFF8BE6 = 0x80;

		__enable_irq();
	};

	if (((RT_FLAG1_FFFF8888 & 0x20) || byte_1075 != 0) && (wMUT1E_MAF_RESET_FLAG & 4))
	{
		u16 r1 = word_17BE + 20;

		u16 r2 = Sub_Lim_0(wMUT33_Corrected_Timing_Advance, word_17BC);

		__disable_irq();

		IGNITION_FINAL2_FFFF8BE6 = (r2 >= r1) ? r2 : r1;

		IGN_0xA_FFFF8BE8 = word_17C0;

		__enable_irq();
	};

	return IGNITION_FINAL2_FFFF8BE6;
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

	if ((IGN_FLAG9_FFFF8BB6 & 0x2000) == 0)
	{
		Map3D_B *t;

		if (RT_FLAG1_FFFF8888 & 0x20)
		{
			Table_Lookup_Axis(CEL8_79AE);
			t = AFRAIRTEMP1_630A;
		}
		else
		{
			Table_Lookup_Axis(CEL8_79AE);
			t = AFRAIRTEMP1_630A;
		};

		r = Table_Lookup_byte_2D_3D(t);
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

	if (IGN_FLAG9_FFFF8BB6 & 0x10)
	{
		r1 = Sub_Lim_0(r1, word_1868);
	};

	if (byte_1034 != 0 && load_ECU_Ignintion >= word_1854 && wMUT10_Coolant_Temperature_Scaled >= CTEMPER38_1858)
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
	if (IGN_FLAG9_FFFF8BB6 & 0x8000)
	{
		if (MUT21_RPM_x125div4 <= word_2196)
		{
			CLR(IGN_FLAG9_FFFF8BB6, 0x8000);
		};
	}
	else
	{
		if (MUT21_RPM_x125div4 > word_2198)
		{
			SET(IGN_FLAG9_FFFF8BB6, 0x8000);
		};
	};

	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_sub_1876E()
{
	u16 r1 = 0x80;

	if (IGN_FLAG9_FFFF8BB6 & 0x10)
	{
		r1 = Mul_Fix7_R(wMUT24_Target_Idle_RPM, word_17B6);

		u16 r8 = 0;

		u16 r2 = ((RPM_x_4_096__1 >> 3) + 1) >> 1;

		if (r1 < r2) { r1 = r2; };

		u16 r3;  
		
		if (r1 >= rpm_x125div32_B)
		{
			r3 = r1 - rpm_x125div32_B;
		}
		else
		{
			rpm_x125div32_B - r1;
			r8 = 1;
		};

		u16 r13 = Mul_Fix8_R((wMUT2E_Vehicle_Speed_Frequency > word_262C) ? word_262A : word_17A8, r3);

		if (r13 > word_17AA)
		{
			r13 = word_17AA;
		};

		r1 = (r8 != 0) ? Sub_Lim_0(0x80, r13) : Lim_FF(r13 + 0x80);
	}
	else
	{
		if (BOOSTCHECK2_FFFF8A0E & 0x1000)
		{
			u16 r2 = Sub_Lim_0(rpm_x125div32_B, ((RPM_x_4_096__3 >> 3) + 1) >> 1);

			if (r2 > word_2342)
			{
				r1 = Sub_Lim_0(0x80, Mul_Fix8_R(word_2344, r2));
			};
		}
		else if (wMUT1E_MAF_RESET_FLAG & 0x8000) // timing knockdown on light acceleration and less than 3000rpm
		{
			u16 r2 = Sub_Lim_0(rpm_x125div32_B, ((RPM_x_4_096__2 >> 3) + 1) >> 1);

			if (r2 > word_1844)
			{
				r1 = Sub_Lim_0(0x80, Mul_Fix8_R(word_1846, r2));
			};
		};
	};

	return Some_IGN_RES_FFFF8BD2 = sub_21E14(r1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 IG04_RPM_CORR_sub_18952()
{
	u16 r13 = 0x80;

	if (byte_1035 != 0 && cranking_end_timer_up < word_184A && wMUT10_Coolant_Temperature_Scaled >= CTEMPER40_1848 

		&& (RT_FLAG1_FFFF8888 & 0x80))
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
	if ( byte_1037 == 0 
		|| (wMUT1E_MAF_RESET_FLAG & STALL)
		|| load_ECU_Ignintion < word_188A 
		|| load_ECU_Ignintion > word_1888 
		|| MUT21_RPM_x125div4 < word_188E 
		|| MUT21_RPM_x125div4 > word_188C 
		|| (RT_FLAG1_FFFF8888 & 0x80) == 0)
	{
		__disable_irq();

		word_FFFF8BEA = 0x80;

		__enable_irq();
	}
	else if ((RT_FLAG1_FFFF8888 & 0x20) 
			&& wMUT10_Coolant_Temperature_Scaled >= word_1890 
			&& (RT_FLAG1_FFFF8888 & RACING)
			&& Sub_Lim_0(RPM_DELTA_FFFF8948, 0x80) >= word_1892)
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
	word_FFFF8BCA = Sub_Lim_0(word_178A + 57, Div_WW(wMUT04_Timing_Advance_Interpolated*256, 90));
//	word_FFFF96C8 = Sub_Lim_0(word_178A + 57, Div_WW(word_FFFF96CA * 256, 90));
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

	ignCoilTime_3 = Table_Lookup_byte_2D_3D(IGNCOILCHGTIME3_3A5E);

	u16 t = Table_Lookup_byte_2D_3D(IGNCOILCHGTIME1_3A3E) * 16;

	if (crankHT_x_4us_3 <= word_17A0)
	{
		t = Sub_Lim_0(t, Mul_Fix8_R(word_17A0 - crankHT_x_4us_3, Table_Lookup_byte_2D_3D(IGNCOILCHGTIME2_3A4E)));
	};

	ignCoilTime_1 = t;

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

static void IG04_sub_18C86()
{
	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		word_FFFF8C0A = (wMUT10_Coolant_Temperature_Scaled > word_24F8) ? 0xFF : 0;
	}
	else if (Bitmap_Store_A_FFFF89EE & 2)
	{
		word_FFFF8C0A = Add_Lim_FFFF(word_FFFF8C0A, word_24FA);

		if (word_FFFF8C0A >= 0xFF)
		{
			word_FFFF8C0A = 0xFF;
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

static u16 Barometric_Correction_sub_22084()
{
	return IGN_BARO_COMP_FFFF8BD6 = Sub_Lim_0(0x80, 0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


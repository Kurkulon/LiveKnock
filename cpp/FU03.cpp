//#pragma section _FU03
#pragma section _main

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
//#include "EnVars.h"

//#include "FU03.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define sub_21E2A									((bool(*)(void))0x21E2A)
//#define sub_21C0C									((u16(*)(u16))0x21C0C)
//#define sub_21D9C									((bool(*)(void))0x21D9C)
//#define sub_21D6C									((u16(*)(u16))0x21D6C)


//#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

#define RPM14_6708								((Axis*)0x6708)
#define RPM15_6D3E								((Axis*)0x6D3E)
#define RPM14_6746								((Axis*)0x6746)
#define LOAD9_676C								((Axis*)0x676C)
#define MUTB4_672E								((Axis*)0x672E)
#define BAR5_6D66								((Axis*)0x6D66)
#define VOLT7_66AE								((Axis*)0x66AE)
#define CEL12_68D0								((Axis*)0x68D0)
#define CEL11_6892								((Axis*)0x6892)
#define RPM8_658A								((Axis*)0x658A)
#define RPM11_798E								((Axis*)0x798E)
#define RPM11_6DEC								((Axis*)0x798E)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define STFUELMINT_45CA							((Map3D_B *)0x45CA)
#define STFUELMAXT_45BC							((Map3D_B *)0x45BC)
#define INJBATVOLTCOMP_3422						((Map3D_B *)0x3422)
#define leanSpoolLoadThreshold					((Map3D_B *)0x364C)
#define LeanSpoolTrailingTime_RichSide			((Map3D_B *)0x3646)
#define AFRRFM_32C6								((Map3D_B *)0x32C6)
#define unk090_33E4								((Map3D_B *)0x33E4)
#define unk091_45E8								((Map3D_B *)0x45E8)
#define unk092_48A2								((Map3D_B *)0x48A2)
#define unk93_48B2 								((Map3D_B *)0x48B2)
#define POSTCRANKENRICH_33D4					((Map3D_B *)0x33D4)
#define POSTCRANKENRICH1_4892					((Map3D_B *)0x4892)
#define leanspoolafradjustment_3652				((Map3D_B *)0x3652)
#define unk034_3EFA								((Map3D_B *)0x3EFA)
#define INJBATVOLTCOMP_3422						((Map3D_B *)0x3422)
#define unk114_57A6								((Map3D_B *)0x57A6)
#define unk066_5856								((Map3D_B *)0x5856)
#define STIPWRPMCOR2_3492						((Map3D_B *)0x3492)
#define word_3484								((Map3D_B *)0x3484)


#define unk126_62B2								((Map3D_B *)0x62B2)
#define unk130_62EE								((Map3D_B *)0x62EE)
#define unk124_6284								((Map3D_B *)0x6284)
#define unk127_62C0								((Map3D_B *)0x62C0)
#define unk049_62A0								((Map3D_B *)0x62A0)
#define unk125_6292								((Map3D_B *)0x6292)
#define unk129_62DC								((Map3D_B *)0x62DC)
#define unk128_62CE								((Map3D_B *)0x62CE)
#define unk122_6260								((Map3D_B *)0x6260)
#define unk123_6272								((Map3D_B *)0x6272)

#define	tps_rpm11_351C							((Map3D_B *)0x351C)
#define	unk0522_352E							((Map3D_B *)0x352E)
#define	unk0523_361E							((Map3D_B *)0x361E)
#define	unk0524_362C							((Map3D_B *)0x362C)
#define	unk117_59B0								((Map3D_B *)0x59B0)

#define	asyncAccelCoolantTempAdder				((Map3D_B *)0x3574)
#define	asyncAccelRPMAdder						((Map3D_B *)0x3582)
#define	asyncAccelTPSenrichCutoff				((Map3D_B *)0x3562)

#define	unk068_35BE								((Map3D_B *)0x35BE)
#define	unk069_4BA8								((Map3D_B *)0x4BA8)

#define	unk080_34E8								((Map3D_B *)0x34E8)
#define	unk081_3548								((Map3D_B *)0x3548)
#define	ICSVACONNEYT_34DA						((Map3D_B *)0x34DA)
#define	Accel_Enrich_vs_CoolTemp				((Map3D_B *)0x34FA)

#define unk085_35E0								((Map3D_B *)0x35E0)
#define unk084_35F2								((Map3D_B *)0x35F2)
#define unk083_35D2								((Map3D_B *)0x35D2)
#define unk087_3602								((Map3D_B *)0x3602)
#define unk086_3610								((Map3D_B *)0x3610)

#define unk019_4940								((Map3D_B *)0x4940)
#define unk020_4952								((Map3D_B *)0x4952)





//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define COLD1ST_3594							((Map3D_W *)0x3594)
#define IPW_Adder_for_Cold_Start2_5362			((Map3D_W *)0x5362)
 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define AFRTMP_302A								((const byte*)0x302A)
#define unk137_35AE								((const byte*)0x35AE)
#define	byte_342F								((const byte*)0x342F)                                                     

#define    off_7B48								((const byte**)0x7B48)
#define    off_7B68								((const byte**)0x7B68)
#define    off_7C88								((const byte**)0x7C88)
#define    off_7CA8								((const byte**)0x7CA8)
#define    off_7B88								((const byte**)0x7B88)
#define    off_7BA8								((const byte**)0x7BA8)
#define unk131_7BC8								((const byte**)0x7BC8)
#define unk132_7BE8								((const byte**)0x7BE8)
#define unk135_7CC8								((const byte**)0x7CC8)
#define unk136_7CE8								((const byte**)0x7CE8)









#define word_98E6								((const u16*)0x98E6)

#define byte_3378								(*(const byte*)0x3378)
#define byte_3379								(*(const byte*)0x3379)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#undef FU03_sub_142DC

#define _INJECTOR_RESCALED_sub_26174						((u16(*)(u16))0x26174)
#define _StartInjectAsync									((void(*)(u16,u16))0x261CA)
#define _StartInjectSync									((void(*)(u16,u16))0x26218)

#define InjOpenStart									((void(*)(u16,u16))0xC698)

//extern u16 INJECTOR_RESCALED_sub_26174(u16 v);
//extern void StartInjectAsync(u16 v, u16 mask);
//extern void StartInjectSync(u16 v, u16 mask);

extern "C" void SysInit_NVRAM_Trims();
extern "C" void FU03_Init_Trims();
extern "C" void SysInit_sub_13B04();
extern "C" void FU03_root_sub();
static void FU03_sub_13CE4_hook();
static void FU03_sub_13CE4();
static void FU03_sub_13D8C();
static void FU03_sub_13DA2();
static void FU03_sub_13DCA();
static void FU03_Check_13E12();
static bool FU03_Check_13E4A();
static void FU03_Check_13EAE();
static bool FU03_sub_13EE6();
static void FU03_Coolant_Air_Calcs_sub_14088(/*EnVars**/);
static void FU03_sub_14108();
static bool FU03_sub_14138();
static void FU03_sub_14174();
static void FU03_sub_141B6();
static void FU03_HI_LO_Octan();
static u16 FU03_sub_142DC();
static void FU03_sub_14300();
static void FU03_sub_14380();
static void FU03_sub_14454();
static void FU03_sub_1449A();
static void FU03_sub_144E0();
static void FU03_sub_14610();
static void FU03_VE_map_sub_14620();
static void FU03_Fuel_Knock_Reaction(/*EnVars**/);
static u16 FU03_Lean_Spool_Calcs_sub_148DA(u16);
static void FU03_sub_149E0(/*EnVars**/);
static void FU03_Oxygen_root();
static void FU03_sub_14B68();
static void FU03_sub_14B7E();
static u16 FU03_sub_14C9A();
static void FU03_sub_14CBC();
static bool FU03_sub_14CDC();
static void FU03_sub_14EE0(/*EnVars**/);
static void FU03_Calc_Limits_O2FT(/*EnVars* ev*/);
static void FU03_sub_Oxygen_Feedback_Trim(/*EnVars* ev*/);
static u16 FU03_sub_1525A(/*EnVars* ev*/);
static void FU03_sub_15300(/*Vars *v*/);
static void FU03_Calc_MUT52(/*EnVars* ev*/);
static void FU03_Calc_MUT50_LFTB(/*EnVars* ev*/);
static void FU03_sub_15740(/*EnVars* ev*/);
static bool FU03_sub_15870(/*EnVars* ev*/);
static void FU03_InjPulseWidthLimpHome();
static void FU03_sub_159DC();
static u16 FU03_STIPWRPMCOR();
static u16 FU03_sub_15C22();
static u16 FU03_IPW_compensation();
static void FU03_InjLatencyUpdate();
static void FU03_sub_15E14();
static void FU03_sub_15E48();
static void FU03_sub_15F28();
static void FU03_sub_15F42();
static void FU03_sub_1611C();
static void FU03_sub_161FC();
static void FU03_ASYNHACCELENRICH_sub_1623E();
static void FU03_Cranking_Inject();
static void FU03_sub_16750();
static void FU03_sub_167EC();
static void FU03_O2_B1_B2_sub_16958();
static void FU03_sub_16AA8();
static void FU03_sub_16BFE();
static void FU03_sub_16C60();

static u16 INJECTOR_RESCALED_sub_26174(u32 v);
static void StartInjectAsync(u16 v, u16 mask);
static void StartInjectSync(u16 v, u16 mask);


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//static void Fuel_calcs()
//{
//	//FU03_sub_13DCA();
//
//	if (MUT21_RPM_x125div4 <= word_1A42/*64(2000)*/ || wMUT1C_ECU_Load <= word_1A40/*88(44)*/ || wMUT10_Coolant_Temperature_Scaled <= word_1A44/*151(111)*/ || wMUT11_Intake_Air_Temperature_Scaled <= word_1A46/*90(50)*/)
//	{
//		timer_FFFF879A = word_1A48/*5(2500ms)*/ << 1;
//	};
//
//	//FU03_Check_13E12();
//
//	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_400, (wMUTD1_BitMap_FAA & FAA_4_CLOSED_LOOP) == 0 && FU03_Check_13E4A());
//
//	//FU03_Check_13EAE();
//
//	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_800, (bMUTD2_FBA_MAF_MAP_FLAG & 1) && FU03_sub_13EE6());
//
//	FU03_Coolant_Air_Calcs_sub_14088(ENGINE_MAIN_VARIABLES_DIM_off_9198);
//
//	//FU03_sub_14108();
//
//	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_100, FU03_sub_14138());
//
//	//FU03_sub_14174();
//
//	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_4000, (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN) && wMUT1C_ECU_Load >= word_180C/*80*/ && MUT21_RPM_x125div4 >= word_180A/*128*/);
//
//	FU03_HI_LO_Octan();
//
//	// FU03_sub_14300()
//
//	word_FFFF8AB0 = word_1502/*867*/ * GET_FROM_MASSIVE_byte(AFRTMP_302A)/*131*/ * INJSZ_150C / 0x8000; // 406
//
//	FU03_sub_14380();
//
//	FU03_sub_144E0();
//
//	// FU03_sub_14610();
//
//	word_FFFF8AF0 = 0x80;
//
//	// FU03_VE_map_sub_14620();
//
//	wMUT31_Volumetric_Efficiency = Table_Lookup_byte_2D_3D(VE1Map_3032);
//
//	FU03_Fuel_Knock_Reaction(ENGINE_MAIN_VARIABLES_DIM_off_9198);
//
//	// FU03_sub_149E0(EnVars* ev)
//
//	TRG(ZERO_8_IGNITION_FLAGS, 0x20, wMUT15_Barometric_Pressure, word_1772/*189(94.5)*/, Add_Lim_FFFF(word_1772/*189(94.5)*/, word_1774/*3*/));
//
//	u32 r2 = 0x80;
//
//	if (ZRO(ZERO_8_IGNITION_FLAGS, 0x20))
//	{
//		Table_Lookup_Axis(BAR5_6D66);				// 125,141,157,173,189
//		r2 = Table_Lookup_byte_2D_3D(unk034_3EFA);	// 151,142,140,136,130
//	};
//
//	u32 r0 = word_FFFF8AB0/*406*/ * 65536 * (wMUT31_Volumetric_Efficiency/*210(82)*/ + word_1524/*48(18.75)*/) / 128; // 26815488
//
//	r0 = r0 * k_InAirTemp/*128*/ * r2/*128*/ / 0x4000; // 26815488
//
//	r0 = r0 * fuelTrim_FFFF8ADC/*128*/ * enrichmentWarmUp/*128*/ / 0x4000; // 26815488
//
//	r0 = r0 * (word_FFFF8AEE/*0*/ * 2 + 0x80) / 128;  // 26815488
//
//	r0 = r0 * fuelTrim_FFFF8AE4/*128*/ / 128; // 26815488
//
//	r0 = r0 * wMUT32_Air_To_Fuel_Ratio/*150(12.5)*/ / 128; // 31424400 
//
//	bMUTC7 = r0 / 65536; // 479
//
//	wMUT58_AFR_CT_Adder = Lim_FF(Mul_Div_R(wMUT32_Air_To_Fuel_Ratio * enrichmentWarmUp, (word_FFFF8AEE << 1) + 0x80, 0x4000));
//
//
//	FU03_sub_16BFE();
//
//	FU03_sub_14B7E();
//
//	//FU03_sub_14CBC();
//
//	if (FU03_sub_14CDC())
//	{
//		timer_FFFF85A2 = word_15EA;
//	};
//
//	FU03_Calc_Limits_O2FT(ENGINE_MAIN_VARIABLES_DIM_off_9198);
//	FU03_sub_Oxygen_Feedback_Trim(ENGINE_MAIN_VARIABLES_DIM_off_9198);
//
//	FU03_sub_15300(ENGINE_MAIN_VARIABLES_DIM_off_9198->_432_word_8DB0);
//
//	FU03_Calc_MUT52(ENGINE_MAIN_VARIABLES_DIM_off_9198);
//	FU03_Calc_MUT50_LFTB(ENGINE_MAIN_VARIABLES_DIM_off_9198);
//
//
//	FU03_InjPulseWidthLimpHome();
//
//	FU03_sub_159DC();
//	FU03_InjLatencyUpdate();
//	FU03_sub_15E14();
//	FU03_sub_15E48();
//	FU03_sub_15F28();
//	FU03_ASYNHACCELENRICH_sub_1623E();
//	FU03_sub_16750();
//	FU03_Cranking_Inject();
//	FU03_sub_167EC();
//	FU03_O2_B1_B2_sub_16958();
//	FU03_sub_16AA8();
//	FU03_sub_16C60();
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_NVRAM_Trims()
{
	FU03_Init_Trims();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Init_Trims()
{
	u16 *r7 = &wMUT0C_Fuel_Trim_Low;
	u16 *r1 = &wMUT4C_Fuel_Trim_Low_Bank_2word_FFFF809E;
	//u16 *r6 = &wMUT0C_Fuel_Trim_Low;
	//u16 *r3 = &wMUT4C_Fuel_Trim_Low_Bank_2word_FFFF809E;

	for (u32 r13 = 10; r13 != 0; r13--)
	{
		*(r7++) = 0x80;
		*(r1++) = 0x80;
		//r6++;
		//r3++;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_sub_13B04()
{
	u32 r10 = word_1636;

	word_FFFF8B26 = r10;
	word_FFFF8B20 = r10;
	word_FFFF8B1E = r10;
	word_FFFF8B24 = r10;
	word_FFFF8B22 = r10;

	RPM_FLAGS = RPM_4_STALL;

	r10 = STFUELMINT_45CA->m2d.data[0] << 8;

	word_FFFF8A7A = r10;
	limLo_O2_Feedback_Trim = r10;

	r10 = STFUELMAXT_45BC->m2d.data[0] << 8;

	word_FFFF8A7E = r10;
	limHi_O2_Feedback_Trim = r10;

	injectorLatencyRescaled = (INJBATVOLTCOMP_3422->m2d.data[0] * INJLATBASE) >> 3;

	word_FFFF8B72 = 0x80;
	word_FFFF8B70 = 0x80;

	u16 *r6 = &wMUT4C_Fuel_Trim_Low_Bank_2word_FFFF809E;
	u16 *r3 = &wMUT4C_Fuel_Trim_Low_Bank_2word_FFFF809E;

	for (u32 r13 = 10; r13 != 0; r13--)
	{
		*(r6++) = 0x80;
		r3++;
	};

	afr_closed_loop_interpolator = 0x80;
	afr_closed_loop = 0x80;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void FU03_root_sub()
{
	FU03_sub_13CE4_hook();
	FU03_Oxygen_root();
	FU03_InjPulseWidthLimpHome();
	FU03_sub_159DC();
	FU03_InjLatencyUpdate();
	FU03_sub_15E14();
	FU03_sub_15E48();
	FU03_sub_15F28();
	FU03_ASYNHACCELENRICH_sub_1623E();
	FU03_sub_16750();
	FU03_Cranking_Inject();
	FU03_sub_167EC();
	FU03_O2_B1_B2_sub_16958();
	FU03_sub_16AA8();
	FU03_sub_16C60();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_13CE4_hook()
{
	FU03_sub_13DCA();
		
	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_400, (wMUTD1_BitMap_FAA & FAA_4_CLOSED_LOOP) == 0 && FU03_Check_13E4A()); //FU03_Check_13E12();
	
	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_800, (bMUTD2_FBA_MAF_MAP_FLAG & 1) && FU03_sub_13EE6()); //FU03_Check_13EAE();

	FU03_Coolant_Air_Calcs_sub_14088(/*ENGINE_MAIN_VARIABLES_DIM_off_9198*/);

	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_100, FU03_sub_14138()); //FU03_sub_14108();
	
	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_4000, (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN) && wMUT1C_ECU_Load >= word_180C/*80*/ && MUT21_RPM_x125div4 >= word_180A/*128*/); //FU03_sub_14174();

	FU03_HI_LO_Octan();

	word_FFFF8AB0 = Mul_Div_R(word_1502/*867*/, GET_FROM_MASSIVE_byte(AFRTMP_302A)/*131*/ * INJSZ_150C, 0x8000); // 406 //FU03_sub_14300();
	
	FU03_sub_14380();
	FU03_sub_144E0();
	
	word_FFFF8AF0 = 0x80; //FU03_sub_14610();
	
	FU03_VE_map_sub_14620();

	FU03_Fuel_Knock_Reaction(/*ENGINE_MAIN_VARIABLES_DIM_off_9198*/);
	FU03_sub_149E0(/*ENGINE_MAIN_VARIABLES_DIM_off_9198*/);

	wMUT58_AFR_CT_Adder = Lim_FF(Mul_Div_R(wMUT32_Air_To_Fuel_Ratio * enrichmentWarmUp, (word_FFFF8AEE << 1) + 0x80, 0x4000));
	
	FU03_sub_16BFE();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_13CE4()
{
	FU03_sub_13D8C();
	FU03_sub_14300();
	FU03_sub_14380();
	FU03_sub_144E0();
	FU03_sub_14610();
	FU03_VE_map_sub_14620();
	FU03_Fuel_Knock_Reaction(/*ENGINE_MAIN_VARIABLES_DIM_off_9198*/);
	FU03_sub_149E0(/*ENGINE_MAIN_VARIABLES_DIM_off_9198*/);

	wMUT58_AFR_CT_Adder = Lim_FF(Mul_Div_R(wMUT32_Air_To_Fuel_Ratio * enrichmentWarmUp, (word_FFFF8AEE << 1) + 0x80, 0x4000));
	
	FU03_sub_16BFE();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_13D8C()
{
	FU03_sub_13DA2();
	FU03_sub_141B6();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_13DA2()
{
	FU03_sub_13DCA();
	FU03_Check_13E12();
	FU03_Check_13EAE();
	FU03_Coolant_Air_Calcs_sub_14088(/*ENGINE_MAIN_VARIABLES_DIM_off_9198*/);
	FU03_sub_14108();
	FU03_sub_14174();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_13DCA()
{
	if (MUT21_RPM_x125div4 <= word_1A42/*64(2000)*/ || wMUT1C_ECU_Load <= word_1A40/*88(44)*/ || wMUT10_Coolant_Temperature_Scaled <= word_1A44/*151(111)*/ || wMUT11_Intake_Air_Temperature_Scaled <= word_1A46/*90(50)*/)
	{
		timer_FFFF879A = word_1A48/*5(2500ms)*/ << 1;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Check_13E12()
{
	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_400, (wMUTD1_BitMap_FAA & FAA_4_CLOSED_LOOP) == 0 && FU03_Check_13E4A());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool FU03_Check_13E4A()
{
	TRG(wMUT19_Startup_Check_Bits, 0x20, ECU_Load_1, word_16AE, word_16AC);

	return (wMUT19_Startup_Check_Bits & 0x20) == 0 && (wMUT19_Startup_Check_Bits & 0xF) == 0 && (wMUT10_Coolant_Temperature_Scaled > word_16AA);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Check_13EAE()
{
	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_800, (bMUTD2_FBA_MAF_MAP_FLAG & 1) && FU03_sub_13EE6());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool FU03_sub_13EE6()
{
	u32 r1 = AFR_CONST_FFFF8AD8;
	const u32 r2 = 0x800;

	Table_Lookup_Axis(RPM14_6708);

	u32 r8 = Table_Lookup_byte_2D_3D(leanSpoolLoadThreshold);
	u32 r9 = Table_Lookup_byte_2D_3D(LeanSpoolTrailingTime_RichSide);

	u32 r13 = Sub_Lim_0(r8, leanSpoolEnableLoadHysteresis);

	TRG(SPEED_FLAGS, SPD_11_800, ECU_Load_1, r13, r8);

	if (SPEED_FLAGS & SPD_11_800)
	{
		if (MUT21_RPM_x125div4 >= leanSpoolStopRPM)
		{
			r1 = 0xFF;

			timer_FFFF85A8 = r9;
		}
		else if (timer_FFFF85A8 == 0)
		{
			r1 = Add_Lim_FFFF(r1, 1);

			if (r1 > 0xFF) { r1 = 0xFF; };

			timer_FFFF85A8 = r9;
		};
	}
	else
	{
		if (timer_FFFF85AA == 0)
		{
			r1 = Sub_Lim_0(r1, 1);

			timer_FFFF85AA = Table_Lookup_byte_2D_3D(LeanSpoolTrailingTime_RichSide);
		};

		timer_FFFF85A8 = r9;
	};

	AFR_CONST_FFFF8AD8 = r1;

	return wMUT10_Coolant_Temperature_Scaled >= minTempLeanSpool && (wMUT1E_MAF_RESET_FLAG & MAP_error) == 0 && (SPEED_FLAGS & SPD_11_800);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Coolant_Air_Calcs_sub_14088(/*EnVars* ev*/)
{
	u32 r13 = FUEL_CUT_FLAG_FFFF8A5E;


	if (byte_104E == 0 || (wMUT1E_MAF_RESET_FLAG & STALL) || (wMUT1E_MAF_RESET_FLAG & UPDATE_OXIGEN_TRIM) || ((wMUTD1_BitMap_FAA & FAA_4_CLOSED_LOOP) == 0 && cranking_end_timer_up >= (word_1A1E * 20)))
	{
		CLR(r13, FCF_08);
	}
	else if (wMUT1E_MAF_RESET_FLAG & CRANKING) 
	{
		WFLAG(r13, FCF_08, wMUT10_Coolant_Temperature_Scaled > t1_unk_some_Coolant_Temp_1A16 && wMUT11_Intake_Air_Temperature_Scaled > t1_unk_some_Air_Temperature_1A18);
	};

	FUEL_CUT_FLAG_FFFF8A5E = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14108()
{
	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_100, FU03_sub_14138());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool FU03_sub_14138()
{
	u32 r13 = word_16CE/*255*/;

	if (FUEL_CUT_FLAG_FFFF8A5E & FCF_100)
	{
		r13 = word_16D0/*255*/;
	};

	return wMUT12_Coolant_Temperature_Min_81 >= r13 && MUT21_RPM_x125div4 >= word_16CC/*255*/; 
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14174()
{
	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_4000, (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN) && wMUT1C_ECU_Load >= word_180C/*80*/ && MUT21_RPM_x125div4 >= word_180A/*128*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_141B6()
{
	FU03_HI_LO_Octan();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//static void FU03_HI_LO_Octan()
//{
//	wMUTB4_lookup_value = FU03_sub_142DC();
//
//	Table_Lookup_Axis(RPM14_6746);
//	Table_Lookup_Axis(LOAD9_676C);
//
//	u32 r13 = Query_byte_2D_3D_Table((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? LowOctFMp_7AA8 : LowOctFMp_7AA8);
//
//	if (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN)
//	{
//		u32 rh = Query_byte_2D_3D_Table((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? HIGHOKTF_7A88 : HIGHOKTF_7A88);
//
//		r13 = interpolate_r4_r5_r6(rh, r13, wMUT27_Octane_Number);
//	};
//
//	AFR_OctanInt = r13;
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_HI_LO_Octan()
{
	wMUTB4_lookup_value = FU03_sub_142DC();

	Table_Lookup_Axis(RPM14_6746);

	Table_Lookup_Axis(LOAD9_676C);

	AFR_OctanInt = (fixAFR) ? AFR(14.7) : interpolate_r4_r5_r6(Table_Lookup_byte_2D_3D(HIGHOKTF_7A88[hiFuelMapIndex&7]), Query_byte_2D_3D_Table(LowOctFMp_7AA8), (no_knock_retard != 0) ? 255 : wMUT27_Octane_Number);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_sub_142DC()
{
	return ((wMUTD0_BitMap1 & 0x11) == 0 && (wMUT18_Open_Loop_Bit_Array & MUT18_1_02)) ? ECU_Load_x2_FFFF8962 : ECU_Load_x2_FFFF895C;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14300()
{
	word_FFFF8AB0 = Mul_Div_R(word_1502/*867*/, GET_FROM_MASSIVE_byte(AFRTMP_302A)/*131*/ * INJSZ_150C/*117*/, 0x8000); // 406
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14380()
{
	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{														//cool	-32, -18, -8,  7, 20, 34, 50, 77, 82 
		word_FFFF8AC4 = Table_Lookup_byte_2D_3D(unk090_33E4); //     80,  42, 48, 72, 40, 40, 56, 72, 72		
		word_FFFF8AE6 = Table_Lookup_byte_2D_3D(unk091_45E8); //	 80,  42, 48, 72, 40, 40, 56, 72, 72		
		word_FFFF8AE8 = Table_Lookup_byte_2D_3D(unk092_48A2); //	 80,  42,  2,  2,  2,  2,  2,  2,  2		
		word_FFFF8AEA = Table_Lookup_byte_2D_3D(unk93_48B2);  //	 80,  42,  2,  2,  2,  2,  2,  2,  2				
	};
	
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		COOLANT_REL_6_FFFF8AC2 = 0;
		COOLANT_REL_7_FFFF8AEC = 0;
	}
	else if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{																		//cool -32, -18, -10, -8, 7, 20, 34, 50, 77, 82
		COOLANT_REL_6_FFFF8AC2 = Table_Lookup_byte_2D_3D(POSTCRANKENRICH_33D4);	// 184, 154, 136,128,80, 25, 17, 13,  6,  6	
		COOLANT_REL_7_FFFF8AEC = Table_Lookup_byte_2D_3D(POSTCRANKENRICH1_4892);// 184, 154, 136,128,80, 25, 17, 13,  6,  6		
	};

	if (COOLANT_REL_6_FFFF8AC2 != 0 && tm100_FFFF85AE == 0)
	{
		COOLANT_REL_6_FFFF8AC2 -= 1;

		FU03_sub_14454();
	};

	if (COOLANT_REL_7_FFFF8AEC != 0 && tm100_FFFF85B0 == 0)
	{
		COOLANT_REL_7_FFFF8AEC -= 1;

		FU03_sub_1449A();
	};

	word_FFFF8AEE = interpolate_r4_r5_r6(COOLANT_REL_6_FFFF8AC2, COOLANT_REL_7_FFFF8AEC, word_FFFF8AE2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14454()
{
	u32 r13 = word_FFFF8AC4;

	if (COOLANT_REL_6_FFFF8AC2 > word_1536/*64*/)
	{
		r13 = word_153E/*2*/;

		if (wMUT10_Coolant_Temperature_Scaled <= word_1542/*35(-5)*/)
		{
			r13 = word_1540/*2*/;
		};
	}
	else if (COOLANT_REL_6_FFFF8AC2 > word_1538/*32*/)
	{
		r13 = word_FFFF8AE8;
	};

	tm100_FFFF85AE = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_1449A()
{
	u32 r13 = word_FFFF8AE6;

	if (COOLANT_REL_7_FFFF8AEC > word_209A)
	{
		r13 = word_20A2;

		if (wMUT10_Coolant_Temperature_Scaled <= word_20A6)
		{
			r13 = word_20A4;
		};
	}
	else if (COOLANT_REL_7_FFFF8AEC > word_209C)
	{
		r13 = word_FFFF8AEA;
	};

	tm100_FFFF85B0 = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_144E0()
{
	u32 r1 = 0x80;

	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		// loc_14512
		__disable_irq();

		word_FFFF8AC0 = 0;

		__enable_irq();
	}
	else if (wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT)
	{
		if (wMUT10_Coolant_Temperature_Scaled <= word_16BA || MUT21_RPM_x125div4 >= word_16BE)
		{
			// loc_14512
			__disable_irq();

			word_FFFF8AC0 = 0;

			__enable_irq();
		}
		else if (dif_rpm_x125div32_AB > const_255)
		{
			__disable_irq();

			word_FFFF8AC0 = 8;

			__enable_irq();
		};
	};

	if ((wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) == 0 && (RT_FLAG1_FFFF8888 & RT_7_bit) && (RT_FLAG1_FFFF8888 & AC_SWITCH) == 0 )
	{
		u32 r3 = word_FFFF8AC0;

		if (r3 != 0)
		{
			if (r3 > 8)
			{
				r3 = 8;
			};

			r1 = unk137_35AE[r3]; // 128,128,128,128,128,166,166,166,166
		};
	};

	fuelTrim_FFFF8ADC = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14610()
{
	word_FFFF8AF0 = 0x80;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//static void FU03_VE_map_sub_14620()
//{
//	Table_Lookup_Axis(RPM19_6CEE);
//
//	Table_Lookup_Axis(LOAD11_6D1E);
//
//	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x200) && EGRONOFF_103D == 0);
//
//	Map3D_B *p;
//
//	if ((ZERO_8_IGNITION_FLAGS & 8) == 0) // EGR
//	{
//		p = VE1Map_3032;	
//	}
//	else if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)
//	{
//		p = VE2Map_310E;	
//	}
//	else
//	{
//		p = VE3Map_31EA;	
//	};
//
//	wMUT31_Volumetric_Efficiency = sub_21BC4(Table_Lookup_byte_2D_3D(p));
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregsave(FU03_VE_map_sub_14620)

static void FU03_VE_map_sub_14620()
{
	Table_Lookup_Axis(RPM19_6CEE);

	Table_Lookup_Axis(LOAD11_6D1E);

	wMUT31_Volumetric_Efficiency = Table_Lookup_word_2D_3D(veMapArray[veMapIndex&7]) >> 8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Fuel_Knock_Reaction(/*EnVars* ev*/)
{
	u32 afr;

	if (wMUT1E_MAF_RESET_FLAG & UPDATE_OXIGEN_TRIM)
	{
		afr = afr_closed_loop;
	}
	else 
	{
		if (FUEL_CUT_FLAG_FFFF8A5E & FCF_400)
		{
			u32 r13 = wMUT13_Front_O2_ADC8bit;

			if (r13 < t1_Primary_O2_Voltage_Check2_16B6/*10*/)
			{
				r13 = 0x80;
			};

			afr = Lim_FF((Lim16(r13, word_16B2/*230*/, word_16B4/*26*/) >> 2) + word_16B0/*104*/);
		}
		else
		{
			afr = AFR_OctanInt;

			Table_Lookup_Axis(RPM15_6D3E);

			u32 r13 = Table_Lookup_byte_2D_3D(AFRRFM_32C6);

			if (afr < r13)
			{
				afr = r13;
			};

			// loc_14776

			if ((FUEL_CUT_FLAG_FFFF8A5E & FCF_4000)/* && !sub_21E2A()*/)
			{
				afr += (word_1808/*160*/ * Sub_Lim_0(wMUT26_Knock_Retard, HiPower_KnockSum_Subtractor)) >> 8;
			};

			if (byte_1032/*0*/ != 0 && timer_FFFF879A == 0)
			{
				afr = Mul_Fix7_R(afr, t1_Fuel_Multiplier_1A4A/*141(1.1)*/);
			};
		};

		// loc_147D4

		if (ZERO_8_IGNITION_FLAGS & 2) // Vehicle_Speed > 150 km/h && RPM > 3500
		{
			afr = Lim_FF(afr + t1_Fuel_Addition_175A/*20*/);
		};

		if (afr >= word_177E/*188(10.0)*/)
		{
			afr = word_177E/*188(10.0)*/;
		};

		if (FUEL_CUT_FLAG_FFFF8A5E & FCF_800)
		{
			afr = FU03_Lean_Spool_Calcs_sub_148DA(afr);
		};

		if ((FUEL_CUT_FLAG_FFFF8A5E & FCF_100) && afr < leanSpoolClipValue/*128(14.7)*/)
		{
			afr = leanSpoolClipValue/*128(14.7)*/;
		};

		if (FUEL_CUT_FLAG_FFFF8A5E & FCF_08)
		{
			u32 r9 = word_1A1E * 20;

			r9 = Mul_Div_R(Sub_Lim_0(r9, cranking_end_timer_up), word_1A1A, r9 << 2);

			r9 += 0x80;

			if (r9 >= afr)
			{
				afr = r9;
			};
		};

		// loc_1487C

		if ((wMUT71_Sensor_Error & MUT71_3_MAP/* MAP fault */) && afr < min_AFR_MAP_error/*145(13.0)*/)
		{
			afr = min_AFR_MAP_error/*145(13.0)*/;
		};

		// loc_14894

		if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 8/*P0132, P0136 O2 Sensor Circuit*/) && (word_FFFF9296 & 0x200) && afr < word_1F44/*147(12.8)*/)
		{
			afr = word_1F44/*147(12.8)*/;	
		};
	};

	// loc_148B8

	wMUT32_Air_To_Fuel_Ratio = afr; //sub_21C0C(afr);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_Lean_Spool_Calcs_sub_148DA(u16 afr)
{
	u32 r13 = leanSpoolAFRbelowEnable;
	
	if (MUT21_RPM_x125div4 >= leanSpoolStartRPM)
	{
		wMUTB4_lookup_value = afr;

		Table_Lookup_Axis(MUTB4_672E);

		r13 = Table_Lookup_byte_2D_3D(leanspoolafradjustment_3652);
	};

	if (afr >= r13)
	{
		afr = interpolate_r4_r5_r6(afr, r13, AFR_CONST_FFFF8AD8);
	};

	return afr;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_149E0(/*EnVars* ev*/)
{
//	u32 r9 = enrichmentWarmUp;
	u32 r8 = Mult_R4_65536(word_FFFF8AB0/*406*/); // 26607616

	TRG(ZERO_8_IGNITION_FLAGS, 0x20, wMUT15_Barometric_Pressure, word_1772/*189(94.5)*/, Add_Lim_FFFF(word_1772/*189(94.5)*/, word_1774/*3*/));

	u32 r2 = 0x80;

	if (ZRO(ZERO_8_IGNITION_FLAGS, 0x20))
	{
		Table_Lookup_Axis(BAR5_6D66);				// 125,141,157,173,189
		r2 = Table_Lookup_byte_2D_3D(unk034_3EFA);	// 151,142,140,136,130
	};

	u32 r0 = Mul32_Fix8(r8, Add_Lim_FFFF(wMUT31_Volumetric_Efficiency/*210(82)*/, word_1524/*48(18.75)*/)); // 26815488

	r0 = Mul_DW_Div(r0, k_InAirTemp/*128*/ * r2/*128*/, 0x4000); // 26815488

	r0 = Mul_DW_Div(r0, fuelTrim_FFFF8ADC/*128*/ * enrichmentWarmUp/*128*/, 0x4000); // 26815488

	r0 = Mul32_Fix7(r0, (word_FFFF8AEE/*0*/ << 1) + 0x80);  // 26815488

	r0 = Mul32_Fix7(r0, fuelTrim_FFFF8AE4/*128*/); // 26815488

	r0 = Mul32_Fix7(r0, wMUT32_Air_To_Fuel_Ratio/*150(12.5)*/); // 31424400 

	bMUTC7 = bMUTC7 = Div_65536_R(r0); // 479
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef _DEBUG

static void EVO_sub_150A0(/*EnVars* ev*/) //FU03_sub_149E0(EnVars* ev)
{
	u32 r8 = 0x4000;

	u32 r0 = Mult_R4_65536(word_FFFF8AAC);

	r0 = Mul_DW_Div(r0, k_InAirTemp * air_Density, 0x4000);

	u32 r2 = Mul32_Fix7(r0, word_FFFF8AD8);

	r0 = Mul_Div_R(enrichmentWarmUp * word_FFFF8AEC, (word_FFFF8AEA << 1) + 0x80, 0x4000);

	if (r0 <= 0x80)
	{
		r0 = Mul_Div_R(0x80, 0x80, word_FFFF8ABA);
	}
	else
	{
		r0 = Mul_Div_R(word_FFFF8AEC << 7, (word_FFFF8AEA << 1) + 0x80, 0x4000);
	};

	r0 = Mul32_Fix7(r2, r0);

	r0 = Mul32_Fix7(r0, word_FFFF8AE0);

	Mul_DW_Div(r0, Add_Lim_FFFF(MUT_1A8, 0x180), 0x200);

	r0 = Mul32_Fix7(r0, *ev->_80_wMUT32_Air_To_Fuel_Ratio);

	*ev->_84_bMUTC7 = bMUTC7 = Div_65536_R(r0);
}

#endif

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Oxygen_root_Hook()
{
	FU03_sub_14B7E();
	FU03_sub_14CBC();

	FU03_Calc_Limits_O2FT(/*ev*/);
	FU03_sub_Oxygen_Feedback_Trim(/*ev*/);

	FU03_sub_15300(/*ev->_432_word_8DB0*/);

	FU03_Calc_MUT52(/*ev*/);
	FU03_Calc_MUT50_LFTB(/*ev*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Oxygen_root()
{
	FU03_sub_14B68();

	FU03_sub_14EE0(/*ENGINE_MAIN_VARIABLES_DIM_off_9198*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14B68()
{
	FU03_sub_14B7E();
	FU03_sub_14CBC();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14B7E()
{
	u32 index = 0x18;

	if (wMUT19_Startup_Check_Bits & 0xF)
	{
		timer_FFFF85A4 = word_15C0/*160*/;
	};

	u32 inc, dec;

	if ((byte_1065 == 0 && RAM_VAR_1065_FFFF86B2 != 0) || (byte_1065 != 0 && (ZERO_8_IGNITION_FLAGS & 0x2000)))
	{
		// loc_14BC2

		dec = byte_3378/*11*/;
		inc = byte_3379/*7*/;
	}
	else
	{
		// loc_14BD2

		index = FU03_sub_14C9A();

		u32 r14 = index;

		if (ZRO(RT_FLAG1_FFFF8888, RT_5_ALWAYS_1))
		{
			index += 10;
		};

		dec = ((const byte*)GET_LOC_DIM_sub_DF6(off_7B48))[index];

		inc = ((const byte*)GET_LOC_DIM_sub_DF6(off_7B68))[index];

		if (wMUT10_Coolant_Temperature_Scaled < word_210A)
		{
			dec = ((const byte*)GET_LOC_DIM_sub_DF6(off_7C88))[index];

			inc = ((const byte*)GET_LOC_DIM_sub_DF6(off_7CA8))[index];
		};

		if (r14 != 0 && word_FFFF8232 >= word_2124/*20*/)
		{
			Table_Lookup_Axis(RPM11_6DEC);

			dec = Lim_FF(Mul_Fix7_R(dec, Table_Lookup_byte_2D_3D(unk019_4940)));

			inc = Lim_FF(Mul_Fix7_R(inc, Table_Lookup_byte_2D_3D(unk020_4952)));
		};
	};

	dec_Oxygen_Trim = dec;
	inc_Oxygen_Trim = inc;

	wMUT3F_Short_Term_Fuel_Feedback_Trim_O2_Map_Index = index;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_sub_14C9A()
{
	u32 r13 = 0xF;

	r13 &= wMUT19_Startup_Check_Bits;

	if (r13 == 0 && timer_FFFF85A4 != 0)
	{
		r13 = 1;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14CBC()
{
	if (FU03_sub_14CDC())
	{
		timer_FFFF85A2 = word_15EA;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool FU03_sub_14CDC()
{
	u32 r1 = 0;
	u32 r2 = word_FFFF928E & 1;

	if (ERROR_FLAG_FFFF89FE & 0xF)
	{
		word_FFFF879E = word_15F8 << 2;
	};

	if (word_FFFF995C & 1)
	{
		r1 = 1;
	};

	if ((((ERROR_FLAG_FFFF89FE >> 4) ^ ERROR_FLAG_FFFF89FE) & 0xF) || r2 == 0)
	{
		return true;
	};

	if ((wMUT71_Sensor_Error & (MUT71_4_bit|MUT71_2_BARO|MUT71_1_IAT|MUT71_0_COOLANT)) || (wMUT18_Open_Loop_Bit_Array & MUT18_14_4000))
	{
		return true;
	};

	if (wMUT10_Coolant_Temperature_Scaled < word_15DA/*117(77)*/ || wMUT11_Intake_Air_Temperature_Scaled >= word_15DC/*113(73)*/)
	{
		return true;
	};

	if (wMUT1F_ECU_Load_Previous < word_15E2/*43*/ || wMUT15_Barometric_Pressure < word_15E0/*100*/ || wMUT15_Barometric_Pressure >= word_15DE/*228(114)*/)
	{
		return true;
	};

	if (wMUT1F_ECU_Load_Previous < word_15E2/*43*/ || wMUT15_Barometric_Pressure < word_15E0/*100*/ || wMUT15_Barometric_Pressure >= word_15DE/*228(114)*/)
	{
		return true;
	};

	if ((wMUT19_Startup_Check_Bits & 0x700) || word_FFFF86C2 != 0)
	{
		return true;
	};

	if ((wMUTD1_BitMap_FAA & FAA_5_20) && (ERROR_FLAG_FFFF89FE & 0xF))
	{
		return true;
	};

	if (ZRO(ERROR_FLAG_FFFF89FE, 0xF) && word_FFFF879E != 0)
	{
		return true;
	};

	if ((wMUTD1_BitMap_FAA & FAA_12_EVAP) && wMUT4A_Purge_Control_Duty != 0)
	{
		return true;
	};

	if (r1 != 0 || wMUTC0_bMUT54_Acceleration_Enrichment != 0 || wMUTC1_bMUT55_Deceleration_Enleanment != 0)
	{
		return true;
	};

	if (AC_Enabled_disabled == 0)
	{
		return false;
	};

	if (byte_1065/*1*/ == 0 && RAM_VAR_1065_FFFF86B2 != 0)
	{
		return true;
	};

	if (byte_1065/*1*/ == 0 || ZRO(ZERO_8_IGNITION_FLAGS, 0x2000))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14EE0(/*EnVars* ev*/)
{
	FU03_Calc_Limits_O2FT(/*ev*/);
	FU03_sub_Oxygen_Feedback_Trim(/*ev*/);

	FU03_sub_15300(/*ev->_432_word_8DB0*/);

	FU03_Calc_MUT52(/*ev*/);
	FU03_Calc_MUT50_LFTB(/*ev*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Calc_Limits_O2FT(/*EnVars* ev*/)
{
	u32 r8 = Table_Lookup_byte_2D_3D(STFUELMINT_45CA);
	u32 r2 = Table_Lookup_byte_2D_3D(STFUELMAXT_45BC);

	if (wMUT18_Open_Loop_Bit_Array & MUT18_6_40)
	{
		r2 = word_15B2;
	};

	limLo_O2_Feedback_Trim = r8 << 8;
	limHi_O2_Feedback_Trim = r2 << 8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_Oxygen_Feedback_Trim(/*EnVars* ev*/)
{
	u16 *r2 = &wMUT0F_Oxygen_Feedback_Trim;
	u16 *r9 = &word_FFFF8A74;


	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		word_FFFF92B6 = 0x8080;
	}
	else if ((timeEvents & EVT_2_100ms) && (word_FFFF928E & 2))
	{
		word_FFFF92B6 = Interpolate_256(word_FFFF92B6, *r2, (word_FFFF8D58 & 0x2000) ? word_215A : word_1DAA);
	};

	// loc_14FE8

//	u32 r8 = (!sub_21D9C()) ? FU03_sub_1525A(ev) : 4;
	u32 r8 = FU03_sub_1525A(/*ev*/);

	// loc_15094

	__disable_irq();

	if (r8 == 2)
	{
		*r2 = (word_15B6 << 8) + 0x80;
	}
	else if (r8 == 4)
	{
		*r2 = 0x8080;
	}
	else if (r8 == 8)
	{
		*r2 = (word_15B4 << 8) + 0x80;
	}
	else if (r8 == 16)
	{
		*r2 = (word_15B8 << 8) + 0x80;
	};

	// loc_150EE

	__enable_irq();

	if (wMUT1E_MAF_RESET_FLAG & FUEL_CUT)
	{
		if ((prev_MUT1E_FLAGS & FUEL_CUT) == 0)
		{
			__disable_irq();

			*r2 = *r9;

			__enable_irq();
		};

		// loc_15118

		*r9 = *r2;
	}
	else
	{
		r8 = 0;
		u32 r13 = 0x8080;
		u32 r3 = word_FFFF929A;

		if (wMUT1E_MAF_RESET_FLAG & STALL)
		{
			r13 = 0x8080;
		}
		else if (open_Loop_disable != 0 && timer_FFFF8596 != 0)
		{
			r8 = 1;
		}
		else if (FUEL_CUT_FLAG_FFFF8A5E & FCF_08)
		{
			u32 r0 = limLo_O2_Feedback_Trim;

			u32 r2 = (word_1A1C << 8) + 128;

			r13 = (r2 >= r0) ? r2 : r0;
		}
		else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 4) && r3 == 3)
		{
			r13 = word_FFFF92A2;
		}
		else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 4) && r3 >= 3  && r3 <= 12)
		{
			r13 = word_FFFF929E;
		}
		else if (bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1)
		{
			if (((wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) || (wMUT19_Startup_Check_Bits & 0x80) == 0) && ((word_FFFF928E & 0x1000) || word_FFFF86FA != 0))
			{
				r13 = word_FFFF92B6;
			}
			else
			{
				r13 = 0x8080;
			};
		}
		else
		{
			if ((wMUTD0_BitMap1 & 1) == 0 || (wMUT19_Startup_Check_Bits & 0x80))
			{
				r13 = 0x8080;
			}
			else
			{
				r8 = 1;
			};
		};

		// loc_15240

		if (r8 == 0)
		{
			*r9 = r13;
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_sub_1525A(/*EnVars* ev*/)
{
	u32 r13;

	if (wMUT1E_MAF_RESET_FLAG & UPDATE_OXIGEN_TRIM)
	{
		r13 = 1;
	}
	else if (wMUT10_Coolant_Temperature_Scaled <= Closed_Loop_Min_Engine_Temp 
			|| (wMUT18_Open_Loop_Bit_Array & MUT18_12_1000) 
			|| (wMUT18_Open_Loop_Bit_Array & MUT18_15_8000)
			|| ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1) && word_FFFF8828 != 0)
			|| (word_FFFF9296 & 0xF2))
	{
		r13 = 4;
	}
	else if (wMUT19_Startup_Check_Bits & 0x80)
	{
		r13 = 8;
	}
	else if (ZRO(wMUT19_Startup_Check_Bits, 0x8000))
	{
		r13 = 4;
	}
	else
	{
		r13 = 2;

		if (wMUT10_Coolant_Temperature_Scaled < word_15BA/*90(50)*/)
		{
			r13 = 16;
		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15300(/*Vars *v*/)
{
//	const u32 r7 = 0x200;

	u32 r6 = bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 4;

	u32 r3 = bMUTBC;

	u32 r13 = word_FFFF81E0;

	if (r13 & 0x40)
	{
		TRG(word_FFFF81E0, 0x200, r3, word_1E90/*254*/, word_1E8E/*255*/);
	}
	else
	{
		WFLAG(word_FFFF81E0, 0x200, byte_1061/*1*/ == 0)
	};

	// loc_15364

	bool c = byte_1053 == 0 
		|| (byte_1053 == 2 && word_247A < 64) 
		|| byte_1053 == 3 
		|| r6 == 0 
		|| ZRO(word_FFFF81E0, 0x200) 
		|| timer_FFFF85A4 == 0
		|| (byte_1065 == 0 && RAM_VAR_1065_FFFF86B2 != 0)
		|| (byte_1065 != 0 && (ZERO_8_IGNITION_FLAGS & 0x2000));

	WFLAG(word_FFFF81E0, 0x100, !c);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Calc_MUT52(/*EnVars* ev*/)
{
	u32 r13, r2;

	if (ZRO(wMUT1E_MAF_RESET_FLAG, UPDATE_OXIGEN_TRIM))
	{
		r13 = 0x80;
	}
	else
	{	
		if ((byte_1065 == 0 && RAM_VAR_1065_FFFF86B2 != 0) || (byte_1065 != 0 && (ZERO_8_IGNITION_FLAGS & 0x2000)))
		{
			// loc_1545E

			r2 = r13 = (byte_1065 != 0) ? word_2170 : word_15C4;
		}
		else if (wMUT19_Startup_Check_Bits & 0x100)
		{
			r2 = r13 = word_15C2;
		}
		else if (byte_105D == 0)
		{
			void *r4;

			if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)
			{
				r4 = (wMUT10_Coolant_Temperature_Scaled >= word_210A) ? off_7B88 : unk131_7BC8;
			}
			else
			{
				r4 = (wMUT10_Coolant_Temperature_Scaled >= word_210A) ? off_7BA8 : unk132_7BE8;
			};

			byte *p = (byte*)GET_LOC_DIM_sub_DF6(r4);

			r2 = r13 = p[FU03_sub_14C9A()];
		}
		else
		{
			u32 i = FU03_sub_14C9A();

			if (ZRO(RT_FLAG1_FFFF8888, RT_5_ALWAYS_1))
			{
				i += 10;
			};

			// loc_154F8

			r2 = ((byte*)GET_LOC_DIM_sub_DF6(unk135_7CC8))[i];

			r13 = ((byte*)GET_LOC_DIM_sub_DF6(unk136_7CE8))[i];

		};

		// loc_15512

		r13 = (wMUT18_Open_Loop_Bit_Array & MUT18_6_40) ? Sub_Lim_0(0x80, r2) : Lim_FF(r13 + 0x80);
	};

	// loc_1553A

	wMUT52 = wMUT52 = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Calc_MUT50_LFTB(/*EnVars* ev*/)
{
	u32 r9 = word_FFFF995C;

	FU03_sub_15740(/*ev*/);

	if (((((u32)ERROR_FLAG_FFFF89FE >> 4) ^ ERROR_FLAG_FFFF89FE) & 0xF) && ZRO(ERROR_FLAG_FFFF89FE, 0xF))
	{
		word_FFFF995A = wMUT10_Coolant_Temperature_Scaled;
	};

	if (FU03_sub_15870(/*ev*/))
	{
		u32 r2, r8;

		if (wMUTD1_BitMap_FAA & FAA_5_20)
		{
			r2 = 0;
		}
		else
		{
			// loc_155FE

			r2 = ERROR_FLAG_FFFF89FE & 0xF;

			r8 = (word_2C98 < word_15DA) ? word_2C98 : word_15DA;

			u32 r13 = Sub_Lim_0(wMUT0D_Fuel_Trim_Middle, wMUT0C_Fuel_Trim_Low);

			if (ZRO(ERROR_FLAG_FFFF89FE, 0xF) && word_FFFF995A < r8 && r13 >= word_2C9A)
			{
				r2 = 1;

				SET(r9, 1);
			}
			else
			{
				CLR(r9, 1);
			};
		};

		// loc_15678

		r8 = Lim16(((u16*)&wMUT4C_Fuel_Trim_Low_Bank_2word_FFFF809E)[r2], word_15F0, word_15F2);

		u32 r0 = Lim16(((u16*)&wMUT0C_Fuel_Trim_Low)[r2], SOME_FUEL_TRIM_CONST_15F6, SOME_FUEL_TRIM_CONST_15F4);

		r0 = Add_Lim_FFFF(r0, r8);

		r2 = Sub_Lim_0(r0, 0x80);

		if (ZRO(wMUT1E_MAF_RESET_FLAG, UPDATE_OXIGEN_TRIM) && (wMUTD1_BitMap_FAA & FAA_5_20) && ((ERROR_FLAG_FFFF89FE & 0xF) || ZRO(wMUT18_Open_Loop_Bit_Array, MUT18_1_02)))
		{
			r2 = 0x80;
		};

		wMUT50_Long_Fuel_Trim_Bank_1 = r2;
	}
	else
	{
		// loc_15706

		wMUT50_Long_Fuel_Trim_Bank_1 = 0x80;

		CLR(r9, 1);
	};

	// loc_15712

	word_FFFF995C = (word_FFFF995C & ~1) | (r9 & 1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15740(/*EnVars* ev*/)
{
	u32 r8 = ERROR_FLAG_FFFF89FE & 0xF;

	u32 r2 = ((u16*)&wMUT0C_Fuel_Trim_Low)[r8];

	if (timer_FFFF85A2 != 0)
	{
		word_FFFF809C = 0x80;
	}
	else if (timeEvents & EVT_0_25ms)
	{
		u32 r9 = wMUT0F_Oxygen_Feedback_Trim & 0xFF00;

		if (r9 != 0x8000)
		{
			r2 = word_FFFF809C + (r2 << 8);

			if (r9 <= 0x8000)
			{
				r2 = Sub_Lim_0(r2, (r8 != 0) ? word_1D80/*12*/ : word_15EC/*5*/);
			}
			else
			{
				// loc_157CC

				r2 = Add_Lim_FFFF(r2, (r8 != 0) ? word_1D82/*12*/ : word_15EE/*5*/);
			};

			// loc_157F2

			word_FFFF809C = (byte)r2;

			r2 >>= 8;
		};
	};

	// loc_157FE

	//if (sub_21D9C())
	//{
	//	FU03_Init_Trims();
	//}
	//else
	{
		r2 = Lim16(r2, SOME_FUEL_TRIM_CONST_15F6, SOME_FUEL_TRIM_CONST_15F4);

		((u16*)&wMUT0C_Fuel_Trim_Low)[r8] = r2;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool FU03_sub_15870(/*EnVars* ev*/)
{
	//u32 r13;

	//if (ev->_0_ == 0)
	//{
	//	r13 = wMUT40_Stored_Faults_Lo & 1;
	//}
	//else
	//{
	//	r13 = wMUT40_Stored_Faults_Lo & 2;
	//};

	return ZRO(wMUT71_Sensor_Error, MUT71_3_MAP) && (wMUTD1_BitMap_FAA & FAA_4_CLOSED_LOOP);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_InjPulseWidthLimpHome()
{
	wMUTB4_lookup_value = Lim_FF(wMUT8A_TPS_Corrected + Table_Lookup_byte_2D_3D(TEMPCOMP_3BEE));

	Table_Lookup_Axis(RPM5_6830);
	Table_Lookup_Axis(VOLT7_6844_Throttle);
	
	wMUT35_Limp_Home_Fuel_Throttle_Position_Based = sub_21CA8(Table_Lookup_byte_2D_3D(LIMPHOME_33F4));

	u32 r0 = Mult_R4_65536(wMUT35_Limp_Home_Fuel_Throttle_Position_Based * t1_unk_1516/*72*/);

	r0 = Mul_DW_Div(r0, air_Density * k_InAirTemp, 0x8000);
	
	r0 = Mul32_Fix8(r0, enrichmentWarmUp);

	r0 = Mul32_Fix8(r0, (word_FFFF8AEE << 1) + 0x80);

	ipwLimpHome = Div_65536_R(r0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_159DC()
{
	u32 r8 = FU03_STIPWRPMCOR();

	u32 r9 = FU03_sub_15C22();

	u32 var_10 = FU03_IPW_compensation();

	Table_Lookup_Axis(CEL11_6892);

	u32 var_C = Mult_R4_65536(Table_Lookup_byte_2D_3D(unk066_5856));

	u32 r1 = Mult_R4_65536(unk066_5856->m2d.data[CEL12_68D0->len - 1]);

	r8 = Mul_DW_Div(var_C, r8 * r9, 0x4000);

	u32 r2 = Mul_DW_Div(r8, var_10 << 7, 0x4000);

	if (r2 < r1)
	{
		r2 = r1;
	};

	if (word_FFFF8A48 & 0x20)
	{
		r2 = Mul_R4_R5w_Div_128_Round_R0(r2, word_25E0);
	};

	u32 r0 = Mul_Fix8_R(wMUT15_Barometric_Pressure, 0xA0) * word_25EA;

	r0 = Mul_DW_Div(r2, r0, 0x400);

	r0 = Mul32_lim(r0, 4);

	r2 = Div_65536_R(r0);

	if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{
		u32 r1 = t1_unk_154E;
		u32 r13 = t1_unk_1550;

		if (FUEL_CUT_FLAG_FFFF8A5E & FCF_8000)
		{
			r1 = r13;
		};

		u32 r8 = r1 << 8;

		r1 = r2;

		r1 >>= 1;

		if (r1 >= r8)
		{
			SET(FUEL_CUT_FLAG_FFFF8A5E, FCF_8000|FCF_04);

			r2 = r1;
		}
		else
		{
			r1 = t1_unk_1546;
			r13 = t1_unk_154A;

			if (FUEL_CUT_FLAG_FFFF8A5E & FCF_04)
			{
				r1 = r13;
			};

			r1 <<= 8;

			if (r2 >= r1)
			{
				SET(FUEL_CUT_FLAG_FFFF8A5E, FCF_04);
			}
			else
			{
				CLR(FUEL_CUT_FLAG_FFFF8A5E, FCF_04);

				r2 = Mul_Lim_FFFF(r2, 4);
			};
		};

		CLR(FUEL_CUT_FLAG_FFFF8A5E, FCF_8000);
	}
	else
	{
		// loc_15B3A

		CLR(FUEL_CUT_FLAG_FFFF8A5E, FCF_8000|FCF_04);

		r2 = Mul_Lim_FFFF(r2, 4);
	};

	ipw_FFFF8AFC = r2;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_STIPWRPMCOR()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		__disable_irq();

		RPM8_FFFF8B00 = 0;
		RPM8_FFFF8B02 = 0;

		__enable_irq();
	};

	Table_Lookup_Axis(RPM8_658A);

	return Table_Lookup_byte_2D_3D((SPEED_FLAGS & SPD_2_ALWAYS_0) ? STIPWRPMCOR2_3492 : word_3484);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_sub_15C22()
{
	if (ZRO(wMUT1E_MAF_RESET_FLAG, STALL) || ZRO(RT_FLAG1_FFFF8888, STARTER))
	{
		timer_FFFF8798 = word_1534/*38*/;
	};

	return 0x80;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_IPW_compensation()
{
	u32 r13 = 0x80;

	return word_FFFF8B06 = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_InjLatencyUpdate()
{
	Table_Lookup_Axis(VOLT7_66AE);
	
//	wMUT79_Injector_Latency = sub_21D6C(Table_Lookup_byte_2D_3D(INJBATVOLTCOMP_3422));
	wMUT79_Injector_Latency = Table_Lookup_byte_2D_3D(INJBATVOLTCOMP_3422);

	injectorLatencyRescaled = Mul_Div_R(wMUT79_Injector_Latency, INJLATBASE, 8);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15E14()
{
	if (RPM_FLAGS & (RPM_5_REVLIM|RPM_3_FUEL_CUT))
	{
		__disable_irq();

		bMUTC6_FFFF8A52 = 0;
		bMUTC5_InjPulseW_8us = 0;
		MUT_2B_FFFF9996 = 0;
		wMUT2A_Injector_Pulse_Width_us = 0;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15E48()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		__disable_irq();

		bMUTC6_FFFF8A52 = 0;
		bMUTC5_InjPulseW_8us = 0;

		word_FFFF8A4E = 0;
		injPulseWidth_null = 0;

		MUT_2B_FFFF9996 = 0;
		wMUT2A_Injector_Pulse_Width_us = 0;

		word_FFFF8B7C[6] = 0;
		word_FFFF8B7C[5] = 0;
		word_FFFF8B7C[4] = 0;
		word_FFFF8B7C[3] = 0;
		word_FFFF8B7C[2] = 0;
		word_FFFF8B7C[1] = 0;
		word_FFFF8B7C[0] = 0;
		word_FFFF8B8A[6] = 0;
		word_FFFF8B8A[5] = 0;
		word_FFFF8B8A[4] = 0;
		word_FFFF8B8A[3] = 0;
		word_FFFF8B8A[2] = 0;
		word_FFFF8B8A[1] = 0;
		word_FFFF8B8A[0] = 0;
		word_FFFF8B9C = 0;
		word_FFFF8B9A = 0;
		word_FFFF8B98 = 0;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15F28()
{
	FU03_sub_15F42();
	FU03_sub_1611C();
	FU03_sub_161FC();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15F42()
{
	u32 r1 = 0;

	if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{
		word_FFFF8B32 = Table_Lookup_byte_2D_3D(unk068_35BE);
		word_FFFF8B3A = Table_Lookup_byte_2D_3D(unk069_4BA8);
	};

	WFLAG(wMUT1E_MAF_RESET_FLAG, CRANKING_TIMED, cranking_end_timer_up < word_FFFF8B32*80);

	if (ZRO(RT_FLAG1_FFFF8888, STARTER))
	{
		u32 r2;

		if (Async_Disabled != 0)
		{
			r2 = 0x20;
			r1 = 0x20;
		}
		else
		{
			r2 = 0x80;
			r1 = 0x80;
		};
		
		// loc_16012

		if (wMUT1E_MAF_RESET_FLAG & CRANKING_TIMED)
		{
			r1 = (Async_Disabled != 0) ? word_211C/*32*/ : word_1632/*166*/;
		};

		// loc_16030

		u32 r8 = GET_FROM_MASSIVE_byte(AFRTMP_302A);

		u32 r0 = Mul16(word_1660/*0*/, INJSZ_150C/*117*/);

		r8 = Mul_R4_R5w_Div_128_Round_R0(r0, r8) >> 1;

		r8 = Mul_R4_R5w_Div_R6w_Round_R0(r8, Table_Lookup_byte_2D_3D(unk080_34E8) * air_Density, 0x4000);

		r2 *= word_1630/*16*/;

		r1 = Mul_R4_R5w_Div_R6w_Round_R0(r8, Table_Lookup_byte_2D_3D(ICSVACONNEYT_34DA) * r1, r2);

		if (Async_Disabled == 0)
		{
			r1 = Lim_FFFF(r1);
		};
	};

	// loc_160B2

	dword_FFFF8B14 = r1;

	enrichCoolTemp = Table_Lookup_byte_2D_3D(Accel_Enrich_vs_CoolTemp);

	baro_FFFF8B0C = word_163A/*205*/;

	baro_FFFF8B10 = baro_FFFF8B0C;

	word_FFFF8B28 = Table_Lookup_byte_2D_3D(unk081_3548);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_1611C()
{
	u32 r1 = 0;

	if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{
		__disable_irq();

		timer_FFFF85A6 = t1_unk_164A;

		__enable_irq();
	};

	if (timer_FFFF85A6 == 0)
	{
		u32 r2 = GET_FROM_MASSIVE_byte(AFRTMP_302A);

		u32 r0 = Mul_Lim_FFFF(word_1682/*0*/, INJSZ_150C/*117*/);

		r0 = Mult_R4_65536(r0);

		r2 = Mul_R4_R5w_Div_128_Round_R0(r0, r2) >> 1;

		r2 = Mul_DW_Div(r2, Table_Lookup_byte_2D_3D(unk085_35E0) * air_Density, 0x4000);

		r0 = Table_Lookup_byte_2D_3D(unk084_35F2);

		r0 = Mul_DW_Div(r2, r0 * Table_Lookup_byte_2D_3D(unk083_35D2), 0x800);

		r1 = Div_65536_R(r0);
	};

	// loc_161CA

	word_FFFF8B18 = r1;

	word_FFFF8B1C = Table_Lookup_byte_2D_3D(unk087_3602);

	null_baro_FFFF8B0E = baro_FFFF8B0C;

	word_FFFF8B2A = Table_Lookup_byte_2D_3D(unk086_3610);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_161FC()
{
	word_FFFF8B34 = Table_Lookup_byte_2D_3D(tps_rpm11_351C);
	word_FFFF8B36 = Table_Lookup_byte_2D_3D(unk0522_352E);

	word_FFFF8B20 = Table_Lookup_byte_2D_3D((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? unk0523_361E : unk0524_362C);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_ASYNHACCELENRICH_sub_1623E()
{
	u32 r1 = Table_Lookup_byte_2D_3D(asyncAccelCoolantTempAdder);

	if (wMUT1E_MAF_RESET_FLAG & CRANKING_TIMED)
	{
		r1 = (Async_Disabled) ? Mul_Div_R(r1, word_2146/*32*/, 32) : Mul_Fix7_R(r1, asyncAccelMultCoolantTempAdder/*128*/);
	};

	r1 += Table_Lookup_byte_2D_3D(asyncAccelRPMAdder);

	ASYNC_ENRICHMENT_FFFF8B42 = Lim_FF(r1);

	word_FFFF8B3E = Lim_FF(Mul_Fix7_R(ASYNC_ENRICHMENT_FFFF8B42, asyncAccelMaxContribution/*60*/));

	ASYNC_INJECTION_FFFF8B44 = Table_Lookup_byte_2D_3D(asyncAccelTPSenrichCutoff);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Cranking_Inject()
{
//	const u32 r8 = 0x2000;

	if (MUT21_RPM_x125div4 >= word_152A/*15(468)*/)
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, FCF_02);
	};

	if ((wMUT1E_MAF_RESET_FLAG & STALL) &&  (FUEL_CUT_FLAG_FFFF8A5E & FCF_02) == 0)
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, FCF_01);
	};

	// loc_16428

	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		CLR(BOOSTCHECK2_FFFF8A0E, 0x40);

		__disable_irq();

		CLR(word_FFFF89F2, 0x400);

		__enable_irq();

		if (wMUT10_Coolant_Temperature_Scaled <= word_1782/*255*/ && wMUT10_Coolant_Temperature_Scaled <= word_24F6/*255*/)
		{
			__disable_irq();

			timer_CrankingInjectSync = word_2576/*0*/;

			if (wMUT10_Coolant_Temperature_Scaled <= word_25EE/*0*/)
			{
				timer_CrankingInjectSync = word_25EC/*0*/;
			};

			__enable_irq();
		};
	};

	// loc_1649C

	WFLAG(FUEL_CUT_FLAG_FFFF8A5E, FCF_80, wMUT10_Coolant_Temperature_Scaled > word_1782/*255(215)*/);

	// loc_164BE

	WFLAG(word_FFFF8A48, 0x40, wMUT10_Coolant_Temperature_Scaled <= word_24F6/*255(215)*/);	

	// loc_16502

	__disable_irq();

	WFLAG(RPM_FLAGS, RPM_13_CRANKING_SYNC_INJECT, (wMUT1E_MAF_RESET_FLAG & CRANKING) && timer_CrankingInjectSync != 0);

	// loc_16538

	__enable_irq();

	if (ONE(wMUT1E_MAF_RESET_FLAG, CRANKING) && ZRO(FUEL_CUT_FLAG_FFFF8A5E, FCF_01))
	{
		// loc_16560

		u32 r1;

		if (ONE(FUEL_CUT_FLAG_FFFF8A5E, FCF_80))
		{
			r1 = Table_Lookup_word_2D_3D(COLD1ST_3594);
		}
		else
		{
			r1 = Table_Lookup_word_2D_3D(IPW_Adder_for_Cold_Start2_5362);

			if (ONE(word_FFFF8A48, 0x20))
			{
				r1 = Mul_Fix7_R(r1, word_25E2/*90(0.7)*/);
			};

			ipwDuringCranking = r1;
		};
	
		// loc_1659E

		if (r1 != 0)
		{
			r1 = INJECTOR_RESCALED_sub_26174(r1);
		};

		// loc_165AE

		u32 r11;

		if (ONE(RPM_FLAGS, RPM_13_CRANKING_SYNC_INJECT))
		{
			__disable_irq();

			bMUTC6_FFFF8A52 = r1;
			bMUTC5_InjPulseW_8us = r1;

			r11 = word_98E6[word_FFFF8F28];

			word_FFFF8F28 ^= 1;
		}
		else
		{
			__disable_irq();

			bMUTC6_FFFF8A52 = r1;
			bMUTC5_InjPulseW_8us = r1;

			r11 = 0xF;
		};

		// loc_165F6

		StartInjectAsync(r1, r11);

		__enable_irq();

		SET(FUEL_CUT_FLAG_FFFF8A5E, FCF_01|FCF_02);
		SET(BOOSTCHECK2_FFFF8A0E, 0x40);
	};

	// loc_16612

	if (ONE(RPM_FLAGS, RPM_13_CRANKING_SYNC_INJECT) && ONE(word_FFFF8A48, 0x80) && ZRO(word_FFFF89F2, 0x400))
	{
		// loc_1663A

		u32 r1 = ipwDuringCranking;

		__disable_irq();

		SET(word_FFFF89F2, 0x400);
		
		__enable_irq();

		if (r1 != 0)
		{
			r1 = INJECTOR_RESCALED_sub_26174(r1);
		};

		// loc_16664

		__disable_irq();

		bMUTC6_FFFF8A52 = r1;
		bMUTC5_InjPulseW_8us = r1;
	
		if (ZRO(BOOSTCHECK2_FFFF8A0E, 0x40))
		{
			word_FFFF8F28 ^= 1;
		};

		// loc_16682

		u32 r2 = word_98E6[word_FFFF8F28];

		word_FFFF8F28 ^= 1;

		if (timer_CrankingInjectSync != 0)
		{
			DECLIM(timer_CrankingInjectSync);

			if (timer_CrankingInjectSync == 0)
			{
				CLR(RPM_FLAGS, RPM_13_CRANKING_SYNC_INJECT);
			};

			StartInjectSync(r1, r2);
		};
		
		// loc_1673C

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma regsave(INJECTOR_RESCALED_sub_26174)

static u16 INJECTOR_RESCALED_sub_26174(u32 v)
{
	if (v <= 260)
	{
		v += byte_342F[v>>2] / 2;
	};

	// loc_261AC

	return Add_Lim_FFFF(v, injectorLatencyRescaled);

//	return _INJECTOR_RESCALED_sub_26174(v);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma regsave(StartInjectAsync)

static void StartInjectAsync(u16 v, u16 mask)
{
	mask &= enInjMask & injectors_mask_FFFF8C72 & 0xF;

	if (bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x30) // Random Misfire Detected
	{
		mask &= injectors_misfire_mask;
	};

	if (v != 0 && mask != 0)
	{
		InjOpenStart(v, mask);
	};

	CLR(word_FFFF8B4E, INJ_5_SYNC_INJECT);

//	_StartInjectAsync(v, mask);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma regsave(StartInjectSync)

static void StartInjectSync(u16 v, u16 mask)
{
	mask &= enInjMask & injectors_mask_FFFF8C72 & 0xF;

	if (bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x30) // Random Misfire Detected
	{
		mask &= injectors_misfire_mask;
	};

	SET(word_FFFF8B4E, INJ_5_SYNC_INJECT);

	injPW_final = v;
	injPW_chnl = mask;

//	_StartInjectSync(v, mask);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_16750()
{
	__disable_irq();

	SET(word_FFFF8B4E, INJ_7_80);
	CLR(word_FFFF8B4E, INJ_6_40);

	__enable_irq();

	u32 r1 = word_FFFF8A48;

	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		if (wMUT10_Coolant_Temperature_Scaled <= word_1720/*0*/)
		{
			SET(r1, 0x80);

			word_FFFF8BB0 = Table_Lookup_byte_2D_3D(unk114_57A6) * 20;
		}
		else
		{
			CLR(r1, 0x80);

			word_FFFF8BB0 = 0;
		};
	}
	else if (ZRO(wMUT1E_MAF_RESET_FLAG, CRANKING)) 
	{
		if ((byte_1071/*0*/ != 0 && (wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT)) || cranking_stall_timer_up >= word_FFFF8BB0)
		{
			CLR(r1, 0x80);
		};
	};

	word_FFFF8A48 = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_167EC()
{
	u32 rpm_flags = wMUT1E_MAF_RESET_FLAG & (UPDATE_OXIGEN_TRIM|CLOSED_LOOP_GENERIC|STALL|FUEL_CUT|DECELERATION_FUEL_CUT|MAP_error|CRANKING); //0x89F;

	u32 r8 = 0x800;

	r8 &= word_FFFF89F6;

	u32 ipw = ipw_FFFF8AFC;

	if (FUEL_CUT_FLAG_FFFF8A5E & FCF_04) 
	{
		SET(rpm_flags, RPM_15_bit);
	};

	if (FUEL_CUT_FLAG_FFFF8A5E & FCF_8000) 
	{
		SET(rpm_flags, RPM_9_wtf_cranking);
	};

	if (ZRO(wMUT1E_MAF_RESET_FLAG, CRANKING))
	{
		ipw = ipwLimpHome;
	};

	__disable_irq();

	ipw_crank_DuringCranking = ipw;

	ipw_crank_DuringCrankingSync = ipwDuringCranking;

	RPM_FLAGS = (RPM_FLAGS & ~(RPM_15_bit|UPDATE_OXIGEN_TRIM|RPM_9_wtf_cranking|CLOSED_LOOP_GENERIC|STALL|FUEL_CUT|DECELERATION_FUEL_CUT|MAP_error|CRANKING)/*0x7560*/) | rpm_flags;

	word_FFFF8A5C = (word_FFFF8A5C & ~0x800) | r8;

	MUTC7_copy = bMUTC7/*479*/;

	MUTC8_copy = bMUTC8;

	wMUT50_Long_Fuel_Trim_Bank_1_COPY = wMUT50_Long_Fuel_Trim_Bank_1/*128*/;
	wMUT51_Long_Fuel_Trim_Bank_2_COPY = wMUT51_Long_Fuel_Trim_Bank_2;

	wMUT52_COPY = wMUT52/*128*/;
	null_MUT53_COPY = wMUT53;

	if (word_FFFF929A == 5 || word_FFFF929A == 8)
	{
		word_FFFF929A += 1;
	};

	if (word_FFFF929C == 5 || word_FFFF929C == 8)
	{
		word_FFFF929C += 1;
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_O2_B1_B2_sub_16958()
{
	u32 r1 = Div_R4_R5__R0(wMUT53, 2);

	r1 = Sub_Lim_0(r1 + SHLR8(wMUT4F_Oxygen_Feedback_Trim_Bank_2), 64);

	u32 r2 = Div_R4_R5__R0(wMUT52/*128*/, 2);

	r2 = Sub_Lim_0(r2 + SHLR8(wMUT0F_Oxygen_Feedback_Trim), 64);

	u32 r8 = Sub_Lim_0((SHLR8(wMUT4F_Oxygen_Feedback_Trim_Bank_2) << 1) + wMUT51_Long_Fuel_Trim_Bank_2, 128);

	r8 = Div_R4_R5__R0(r8, 2);

	u32 r9 = Sub_Lim_0((SHLR8(wMUT0F_Oxygen_Feedback_Trim) << 1) + wMUT50_Long_Fuel_Trim_Bank_1, 128);

	r9 = Div_R4_R5__R0(r9, 2);

	word_FFFF996E = Lim16(r1, 0xFF, 0);
	word_FFFF996C = Lim16(r2, 0xFF, 0);
	word_FFFF9972 = Lim16(r8, 0xFF, 0);
	word_FFFF9970 = Lim16(r9, 0xFF, 0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_16AA8()
{
	word_FFFF8B76 = Table_Lookup_byte_2D_3D(unk126_62B2);

	word_FFFF8B7A = Table_Lookup_byte_2D_3D(unk130_62EE);

	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		Table_Lookup_Axis(CEL8_7100);
		
		word_FFFF8B74 = word_FFFF994E = Table_Lookup_byte_2D_3D(unk124_6284);
	
		word_FFFF8B78 = word_FFFF9952 = Table_Lookup_byte_2D_3D(unk127_62C0);

		word_FFFF9950 = 0;
		word_FFFF9954 = 0;
	}
	else
	{
		Table_Lookup_Axis(RPM11_798E);

		u32 r1 = Table_Lookup_byte_2D_3D(unk049_62A0);

		word_FFFF9950 = Table_Lookup_byte_2D_3D(unk125_6292);

		word_FFFF8B74 = interpolate_r4_r5_r6(word_FFFF9950, word_FFFF994E, Mul_Lim_FFFF(r1, 2));

		r1 = Table_Lookup_byte_2D_3D(unk129_62DC);

		word_FFFF9954 = Table_Lookup_byte_2D_3D(unk128_62CE);

		word_FFFF8B78 = interpolate_r4_r5_r6(word_FFFF9954, word_FFFF9952, Mul_Lim_FFFF(r1, 2));
	};

	// loc_16B86

	u32 r3, r13;

	if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)
	{
		r3 = word_229E/*0*/;
		r13 = word_22A0/*0*/;
	}
	else
	{
		r3 = word_2626/*75*/;
		r13 = word_2628/*46*/;
	};

	TRG(BOOSTCHECK2_FFFF8A0E, 0x400, ECU_Load_1, r13, r3);

	word_FFFF8B9E = Table_Lookup_byte_2D_3D(unk122_6260);

	word_FFFF8BA0 = Table_Lookup_byte_2D_3D(unk123_6272);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_16BFE()
{
	if (wMUT1E_MAF_RESET_FLAG & CLOSED_LOOP_GENERIC)
	{
		if (timeEvents & EVT_2_100ms)
		{
			afr_closed_loop_interpolator = Sub_Lim_0(afr_closed_loop_interpolator, word_2546/*13*/);
		};

		afr_closed_loop = interpolate_r4_r5_r6(AFR_OctanInt, 0x80, afr_closed_loop_interpolator);
	}
	else
	{
		afr_closed_loop_interpolator = 0x80;

		afr_closed_loop = AFR_OctanInt;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_16C60()
{
	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		word_FFFF86F4 = Table_Lookup_byte_2D_3D(unk117_59B0);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void MAF_air_flow_rate_EVO()
{
//	Mul_DW_Div(word_FFFF8AB8 * word_FFFF8AB6 * word_FFFF89E2, MUT28 * 118, 6400) >> 16;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#pragma section _FU03

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define sub_21E2A									((bool(*)(void))0x21E2A)
#define sub_21C0C									((u16(*)(u16))0x21C0C)
#define sub_21D9C									((bool(*)(void))0x21D9C)
#define sub_21D6C									((u16(*)(u16))0x21D6C)


#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define COLD1ST_3594							((Map3D_W *)0x3594)
#define IPW_Adder_for_Cold_Start2_5362			((Map3D_W *)0x5362)
 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define AFRTMP_302A								((const byte*)0x302A)
#define unk137_35AE								((const byte*)0x35AE)

#define word_98E6								((const u16*)0x98E6)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#undef FU03_sub_142DC

extern u16 INJECTOR_RESCALED_sub_26174(u16 v);
extern void StartInjectAsync(u16 v, u16 mask);
extern void StartInjectSync(u16 v, u16 mask);

static void SysInit_NVRAM_Trims();
static void FU03_Init_Trims();
static void SysInit_sub_13B04();
extern "C" void FU03_root_sub();
static void FU03_sub_13CE4();
static void FU03_sub_13D8C();
static void FU03_sub_13DA2();
static void FU03_sub_13DCA();
static void FU03_Check_13E12();
static bool FU03_Check_13E4A();
static void FU03_Check_13EAE();
static bool FU03_sub_13EE6();
static void FU03_Coolant_Air_Calcs_sub_14088(EnVars*);
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
static void FU03_Fuel_Knock_Reaction(EnVars*);
static u16 FU03_Lean_Spool_Calcs_sub_148DA(u16);
static void FU03_sub_149E0(EnVars*);
static void FU03_sub_14B50();
static void FU03_sub_14B68();
static void FU03_sub_14B7E();
static u16 FU03_sub_14C9A();
static void FU03_sub_14CBC();
static bool FU03_sub_14CDC();
static void FU03_sub_14EE0(EnVars*);
static void FU03_sub_14F14(EnVars* ev);
static void FU03_sub_Oxygen_Feedback_Trim(EnVars* ev);
static u16 FU03_sub_1525A(EnVars* ev);
static void FU03_sub_15300();
static void FU03_sub_153E4();
static void FU03_sub_1559C();
static void FU03_sub_15740();
static void FU03_sub_15870();
static void FU03_sub_158AC();
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
static void FU03_sub_162D8();
static void FU03_sub_16750();
static void FU03_sub_167EC();
static void FU03_O2_B1_B2_sub_16958();
static void FU03_sub_16AA8();
static void FU03_sub_16BFE();
static void FU03_sub_16C60();


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_NVRAM_Trims()
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

static void SysInit_sub_13B04()
{
	u32 r10 = word_1636;

	word_FFFF8B26 = r10;
	word_FFFF8B20 = r10;
	word_FFFF8B1E = r10;
	word_FFFF8B24 = r10;
	word_FFFF8B22 = r10;

	RPM_FLAGS = STALL;

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

	afr_FFFF8ACE = 0x80;
	afr_FFFF8ACC = 0x80;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void FU03_root_sub()
{
	FU03_sub_13CE4();
	FU03_sub_14B50();
	FU03_sub_158AC();
	FU03_sub_159DC();
	FU03_InjLatencyUpdate();
	FU03_sub_15E14();
	FU03_sub_15E48();
	FU03_sub_15F28();
	FU03_ASYNHACCELENRICH_sub_1623E();
	FU03_sub_16750();
	FU03_sub_162D8();
	FU03_sub_167EC();
	FU03_O2_B1_B2_sub_16958();
	FU03_sub_16AA8();
	FU03_sub_16C60();
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
	FU03_Fuel_Knock_Reaction(ENGINE_MAIN_VARIABLES_DIM_off_9198);
	FU03_sub_149E0(ENGINE_MAIN_VARIABLES_DIM_off_9198);

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
	FU03_Coolant_Air_Calcs_sub_14088(ENGINE_MAIN_VARIABLES_DIM_off_9198);
	FU03_sub_14108();
	FU03_sub_14174();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_13DCA()
{
	if (MUT21_RPM_x125div4 <= word_1A42/*64(2000)*/ || wMUT1C_ECU_Load <= word_1A40/*88(44)*/ || wMUT10_Coolant_Temperature_Scaled <= word_1A44/*151(111)*/ || wMUT11_Intake_Air_Temperature_Scaled <= word_1A46/*90(50)*/)
	{
		timer_FFFF879A = word_1A48 << 1;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Check_13E12()
{
	if ((wMUTD1_BitMap_FAA & 0x10) == 0 && FU03_Check_13E4A())
	{
		SET(FUEL_CUT_FLAG_FFFF8A5E, 0x400);
	}
	else
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, 0x400);
	};
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
	if ((bMUTD2_FBA_MAF_MAP_FLAG & 1) && FU03_sub_13EE6())
	{
		SET(FUEL_CUT_FLAG_FFFF8A5E, 0x800);
	}
	else
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, 0x800);
	};
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

	TRG(SPEED_FLAGS, 0x800, ECU_Load_1, r13, r8);

	if (SPEED_FLAGS & r2)
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

	return wMUT10_Coolant_Temperature_Scaled >= minTempLeanSpool && (wMUT1E_MAF_RESET_FLAG & MAP_error) == 0 && (SPEED_FLAGS & r2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Coolant_Air_Calcs_sub_14088(EnVars* ev)
{
	u32 r13 = *ev->_20_FUEL_CUT_FLAG_FFFF8A5E;


	if (byte_104E == 0 || (wMUT1E_MAF_RESET_FLAG & STALL) || (*ev->_4_wMUT1E_MAF_RESET_FLAG & 0x800) || ((wMUTD1_BitMap_FAA & 0x10) == 0 && cranking_end_timer_up >= (word_1A1E * 20)))
	{
		CLR(r13, 8);
	}
	else if (wMUT1E_MAF_RESET_FLAG & CRANKING) 
	{
		if (wMUT10_Coolant_Temperature_Scaled > t1_unk_some_Coolant_Temp_1A16 && wMUT11_Intake_Air_Temperature_Scaled > t1_unk_some_Air_Temperature_1A18)
		{
			SET(r13, 8);
		}
		else
		{
			CLR(r13, 8);
		};
	};

	*ev->_20_FUEL_CUT_FLAG_FFFF8A5E = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14108()
{
	if (FU03_sub_14138())
	{
		SET(FUEL_CUT_FLAG_FFFF8A5E, 0x100);
	}
	else
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, 0x100);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool FU03_sub_14138()
{
	u32 r13 = word_16CE/*255*/;

	if (FUEL_CUT_FLAG_FFFF8A5E & 0x100)
	{
		r13 = word_16D0/*255*/;
	};

	return wMUT12_Coolant_Temperature_Min_81 >= r13 && MUT21_RPM_x125div4 >= word_16CC/*255*/; 
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14174()
{
	if ((wMUTD1_BitMap_FAA & 0x80/*Enable High Oct Ign Map Lookup and other*/) && wMUT1C_ECU_Load >= word_180C/*80*/ && MUT21_RPM_x125div4 >= word_180A/*128*/)
	{
		SET(FUEL_CUT_FLAG_FFFF8A5E, 0x4000);
	}
	else
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, 0x4000);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_141B6()
{
	FU03_HI_LO_Octan();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_HI_LO_Octan()
{
	wMUTB4_lookup_value = FU03_sub_142DC();

	Table_Lookup_Axis(RPM14_6746);
	Table_Lookup_Axis(LOAD9_676C);

	u32 r13 = Query_byte_2D_3D_Table((RT_FLAG1_FFFF8888 & 0x20) ? LowOctFMp_7AA8 : LowOctFMp_7AA8);

	if (wMUTD1_BitMap_FAA & 0x80)
	{
		u32 rh = Query_byte_2D_3D_Table((RT_FLAG1_FFFF8888 & 0x20) ? HIGHOKTF_7A88 : HIGHOKTF_7A88);

		r13 = interpolate_r4_r5_r6(rh, r13, wMUT27_Octane_Number);
	};

	AFR_OctanInt = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_sub_142DC()
{
	return ((wMUTD0_BitMap1 & 0x11) == 0 && (wMUT18_Open_Loop_Bit_Array & 2)) ? ECU_Load_x2_FFFF8962 : ECU_Load_x2_FFFF895C;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14300()
{
	word_FFFF8AB0 = Mul_Div_R(word_1502, GET_FROM_MASSIVE_byte(AFRTMP_302A) * INJSZ_150C, 0x8000);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14380()
{
	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		word_FFFF8AC4 = Table_Lookup_byte_2D_3D(unk090_33E4);		
		word_FFFF8AE6 = Table_Lookup_byte_2D_3D(unk091_45E8);		
		word_FFFF8AE8 = Table_Lookup_byte_2D_3D(unk092_48A2);		
		word_FFFF8AEA = Table_Lookup_byte_2D_3D(unk93_48B2);		
	};
	
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		COOLANT_REL_6_FFFF8AC2 = 0;
		COOLANT_REL_7_FFFF8AEC = 0;
	}
	else if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{
		COOLANT_REL_6_FFFF8AC2 = Table_Lookup_byte_2D_3D(POSTCRANKENRICH_33D4);		
		COOLANT_REL_7_FFFF8AEC = Table_Lookup_byte_2D_3D(POSTCRANKENRICH1_4892);		
	};

	if (COOLANT_REL_6_FFFF8AC2 != 0 && timer_FFFF85AE == 0)
	{
		COOLANT_REL_6_FFFF8AC2 -= 1;

		FU03_sub_14454();
	};

	if (COOLANT_REL_7_FFFF8AEC != 0 && timer_FFFF85B0 == 0)
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

	if (COOLANT_REL_6_FFFF8AC2 > word_1536)
	{
		r13 = word_153E;

		if (wMUT10_Coolant_Temperature_Scaled <= word_1542)
		{
			r13 = word_1540;
		};
	}
	else if (COOLANT_REL_6_FFFF8AC2 > word_1538)
	{
		r13 = word_FFFF8AE8;
	};

	timer_FFFF85AE = r13;
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

	timer_FFFF85B0 = r13;
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

	if ((wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) == 0 && (RT_FLAG1_FFFF8888 & 0x80) && (RT_FLAG1_FFFF8888 & AC_SWITCH) == 0 )
	{
		u32 r3 = word_FFFF8AC0;

		if (r3 != 0)
		{
			if (r3 > 8)
			{
				r3 = 8;
			};

			r1 = unk137_35AE[r3];
		};
	};

	word_FFFF8ADC = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14610()
{
	word_FFFF8AF0 = 0x80;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_VE_map_sub_14620()
{
	Table_Lookup_Axis(RPM19_6CEE);

	Table_Lookup_Axis(LOAD11_6D1E);

	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x200) && EGRONOFF_103D == 0);

	Map3D_B *p;

	if ((ZERO_8_IGNITION_FLAGS & 8) == 0) // EGR
	{
		p = VE1Map_3032;	
	}
	else if (RT_FLAG1_FFFF8888 & 0x20)
	{
		p = VE2Map_310E;	
	}
	else
	{
		p = VE3Map_31EA;	
	};

	wMUT31_Volumetric_Efficiency = sub_21BC4(Table_Lookup_byte_2D_3D(p));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_Fuel_Knock_Reaction(EnVars* ev)
{
	u32 r2;

	if (*ev->_4_wMUT1E_MAF_RESET_FLAG & 0x800)
	{
		r2 = afr_FFFF8ACC;
	}
	else 
	{
		if (FUEL_CUT_FLAG_FFFF8A5E & 0x400)
		{
			u32 r13 = wMUT13_Front_O2_ADC8bit;

			if (r13 < t1_Primary_O2_Voltage_Check2_16B6)
			{
				r13 = 0x80;
			};

			r2 = Lim_FF((Lim16(r13, word_16B2/*230*/, word_16B4/*26*/) >> 2) + word_16B0);
		}
		else
		{
			r2 = AFR_OctanInt;

			Table_Lookup_Axis(RPM15_6D3E);

			u32 r13 = Table_Lookup_byte_2D_3D(AFRRFM_32C6);

			if (r2 < r13)
			{
				r2 = r13;
			};

			// loc_14776

			if ((FUEL_CUT_FLAG_FFFF8A5E & 0x4000) && sub_21E2A())
			{
				r2 += (word_1808 * Sub_Lim_0(wMUT26_Knock_Retard, HiPower_KnockSum_Subtractor)) >> 8;
			};

			if (byte_1032 != 0 && timer_FFFF879A == 0)
			{
				r2 = Mul_Fix7_R(r2, t1_Fuel_Multiplier_1A4A/*141(0.55)*/);
			};
		};

		// loc_147D4

		if (ZERO_8_IGNITION_FLAGS & 2) // Vehicle_Speed > 150 km/h && RPM > 3500
		{
			r2 = Lim_FF(r2 + t1_Fuel_Addition_175A);
		};

		if (r2 >= word_177E)
		{
			r2 = word_177E;
		};

		if (FUEL_CUT_FLAG_FFFF8A5E & 0x800)
		{
			r2 = FU03_Lean_Spool_Calcs_sub_148DA(r2);
		};

		if ((FUEL_CUT_FLAG_FFFF8A5E & 0x100) && r2 < leanSpoolClipValue)
		{
			r2 = leanSpoolClipValue;
		};

		if (*ev->_20_FUEL_CUT_FLAG_FFFF8A5E & 8)
		{
			u32 r9 = word_1A1E * 20;

			r9 = Mul_Div_R(Sub_Lim_0(r9, cranking_end_timer_up), word_1A1A, r9 << 2);

			r9 += 0x80;

			if (r9 >= r2)
			{
				r2 = r9;
			};
		};

		// loc_1487C

		if ((wMUT71_Sensor_Error & 8/* MAP fault */) && r2 < min_AFR_MAP_error)
		{
			r2 = min_AFR_MAP_error;
		};

		// loc_14894

		if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 8/*P0132, P0136 O2 Sensor Circuit*/) && (*ev->_176_word_FFFF9296 & 0x200) && r2 < word_1F44)
		{
			r2 = word_1F44;	
		};
	};

	// loc_148B8

	*ev->_80_wMUT32_Air_To_Fuel_Ratio = sub_21C0C(r2);
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

static void FU03_sub_149E0(EnVars* ev)
{
//	u32 r9 = enrichmentWarmUp;
	u32 r8 = Mult_R4_65536(word_FFFF8AB0);

	TRG(ZERO_8_IGNITION_FLAGS, 0x20, wMUT15_Barometric_Pressure, word_1772/*189(94.5)*/, Add_Lim_FFFF(word_1772/*189(94.5)*/, word_1774/*3*/));

	u32 r2 = 0x80;

	if ((ZERO_8_IGNITION_FLAGS & 0x20) == 0)
	{
		Table_Lookup_Axis(BAR5_6D66);

		r2 = Table_Lookup_byte_2D_3D(unk034_3EFA);
	};

	u32 r0 = Mul32_Fix8(r8, Add_Lim_FFFF(wMUT31_Volumetric_Efficiency, word_1524));

	r0 = Mul_DW_Div(r0, k_InAirTemp * r2, 0x4000);

	r0 = Mul_DW_Div(r0, word_FFFF8ADC * enrichmentWarmUp, 0x4000);

	r0 = Mul_R4_R5w_Div_128_Into_R0(r0, (word_FFFF8AEE << 1) + 0x80);

	r0 = Mul_R4_R5w_Div_128_Into_R0(r0, word_FFFF8AE4);

	r0 = Mul_R4_R5w_Div_128_Into_R0(r0, *ev->_80_wMUT32_Air_To_Fuel_Ratio);

	*ev->_84_bMUTC7 = Div_65536_R(r0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14B50()
{
	FU03_sub_14B68();

	FU03_sub_14EE0(ENGINE_MAIN_VARIABLES_DIM_off_9198);
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
	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14EE0(EnVars* ev)
{
	FU03_sub_14F14(ev);
	FU03_sub_Oxygen_Feedback_Trim(ev);

	//ev->_432_word_8DB0

	//FU03_sub_15300();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_14F14(EnVars* ev)
{
	u32 r8 = Table_Lookup_byte_2D_3D(STFUELMINT_45CA);
	u32 r2 = Table_Lookup_byte_2D_3D(STFUELMAXT_45BC);

	if (*ev->_12_wMUT18_Open_Loop_Bit_Array & 0x40)
	{
		r2 = word_15B2;
	};

	*ev->_132_limLo_O2_Feedback_Trim = r8 << 8;
	*ev->_136_limHi_O2_Feedback_Trim = r2 << 8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_Oxygen_Feedback_Trim(EnVars* ev)
{
	u16 *r2 = ev->_96_wMUT0F_Oxygen_Feedback_Trim;
	u16 *r9 = ev->_100_word_FFFF8A74;


	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		*ev->_200_word_FFFF92B6 = 0x8080;
	}
	else if ((Bitmap_Store_A_FFFF89EE & 4) && (*ev->_196_word_FFFF928E & 2))
	{
		*ev->_200_word_FFFF92B6 = Interpolate_256(*ev->_200_word_FFFF92B6, *r2, (word_FFFF8D58 & 0x2000) ? word_215A : word_1DAA);
	};

	// loc_14FE8

	u32 r8 = (sub_21D9C()) ? FU03_sub_1525A(ev) : 4;

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

	if (*ev->_4_wMUT1E_MAF_RESET_FLAG & FUEL_CUT)
	{
		if ((*ev->_8_prev_MUT1E_FLAGS & FUEL_CUT) == 0)
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
		u32 r3 = *ev->_184_word_FFFF929A;

		if (wMUT1E_MAF_RESET_FLAG & STALL)
		{
			r13 = 0x8080;
		}
		else if (open_Loop_disable != 0 && timer_FFFF8596 != 0)
		{
			r8 = 1;
		}
		else if (*ev->_20_FUEL_CUT_FLAG_FFFF8A5E & 8)
		{
			u32 r0 = *ev->_132_limLo_O2_Feedback_Trim;

			u32 r2 = (word_1A1C << 8) + 128;

			r13 = (r2 >= r0) ? r2 : r0;
		}
		else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 4) && r3 == 3)
		{
			r13 = *ev->_192_word_FFFF92A2;
		}
		else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 4) && r3 >= 3  && r3 <= 12)
		{
			r13 = *ev->_188_word_FFFF929E;
		}
		else if (bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1)
		{
			if (((wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) || (wMUT19_Startup_Check_Bits & 0x80) == 0) && ((*ev->_196_word_FFFF928E & 0x1000) || word_FFFF86FA != 0))
			{
				r13 = *ev->_200_word_FFFF92B6;
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

static u16 FU03_sub_1525A(EnVars* ev)
{
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15300()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_153E4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_1559C()
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

		if (FUEL_CUT_FLAG_FFFF8A5E & 0x8000)
		{
			r1 = r13;
		};

		u32 r8 = r1 << 8;

		r1 = r2;

		r1 >>= 1;

		if (r1 >= r8)
		{
			SET(FUEL_CUT_FLAG_FFFF8A5E, 0x8004);

			r2 = r1;
		}
		else
		{
			r1 = t1_unk_1546;
			r13 = t1_unk_154A;

			if (FUEL_CUT_FLAG_FFFF8A5E & 4)
			{
				r1 = r13;
			};

			r1 <<= 8;

			if (r2 >= r1)
			{
				SET(FUEL_CUT_FLAG_FFFF8A5E, 4);
			}
			else
			{
				CLR(FUEL_CUT_FLAG_FFFF8A5E, 4);

				r2 = Mul_Lim_FFFF(r2, 4);
			};
		};

		CLR(FUEL_CUT_FLAG_FFFF8A5E, 0x8000);
	}
	else
	{
		// loc_15B3A

		CLR(FUEL_CUT_FLAG_FFFF8A5E, 0x8004);

		r2 = Mul_Lim_FFFF(r2, 4);
	};

	word_FFFF8AFC = r2;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15740()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15870()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_158AC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_159DC()
{

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

	return Table_Lookup_byte_2D_3D((SPEED_FLAGS & 4) ? STIPWRPMCOR2_3492 : word_3484);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_sub_15C22()
{
//	if (wMUT1E_MAF_RESET_FLAG
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 FU03_IPW_compensation()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_InjLatencyUpdate()
{
	Table_Lookup_Axis(VOLT7_66AE);
	
	wMUT79_Injector_Latency = sub_21D6C(Table_Lookup_byte_2D_3D(INJBATVOLTCOMP_3422));

	injectorLatencyRescaled = Mul_Div_R(wMUT79_Injector_Latency, INJLATBASE, 8);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15E14()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15E48()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15F28()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_15F42()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_1611C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_161FC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_ASYNHACCELENRICH_sub_1623E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_162D8()
{
//	const u32 r8 = 0x2000;

	if (MUT21_RPM_x125div4 >= word_152A/*15(468)*/)
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, 2);
	};

	if ((wMUT1E_MAF_RESET_FLAG & STALL) &&  (FUEL_CUT_FLAG_FFFF8A5E & 2) == 0)
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, 1);
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

			word_FFFF8BAA = word_2576/*0*/;

			if (wMUT10_Coolant_Temperature_Scaled <= word_25EE/*0*/)
			{
				word_FFFF8BAA = word_25EC/*0*/;
			};

			__enable_irq();
		};
	};

	// loc_1649C

	if (wMUT10_Coolant_Temperature_Scaled > word_1782/*255(215)*/)
	{
		SET(FUEL_CUT_FLAG_FFFF8A5E, 0x80);
	}
	else
	{
		CLR(FUEL_CUT_FLAG_FFFF8A5E, 0x80);
	};

	// loc_164BE

	if (wMUT10_Coolant_Temperature_Scaled <= word_24F6/*255(215)*/)	
	{
		SET(word_FFFF8A48, 0x40);
	}
	else
	{
		CLR(word_FFFF8A48, 0x40);
	};

	// loc_16502

	__disable_irq();

	if ((wMUT1E_MAF_RESET_FLAG & CRANKING) && word_FFFF8BAA != 0)	
	{
		SET(RPM_FLAGS, 0x2000);
	}
	else
	{
		CLR(RPM_FLAGS, 0x2000);
	};

	// loc_16538

	__enable_irq();


	if (ONE(wMUT1E_MAF_RESET_FLAG, CRANKING) && ZRO(FUEL_CUT_FLAG_FFFF8A5E, 1))
	{
		// loc_16560

		u32 r1;

		if (ONE(FUEL_CUT_FLAG_FFFF8A5E, 0x80))
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

			word_FFFF8BAC = r1;
		};
	
		// loc_1659E

		if (r1 != 0)
		{
			r1 = INJECTOR_RESCALED_sub_26174(r1);
		};

		// loc_165AE

		u32 r11;

		if (ONE(RPM_FLAGS, 0x2000))
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

		SET(FUEL_CUT_FLAG_FFFF8A5E, 3);
		SET(BOOSTCHECK2_FFFF8A0E, 0x40);
	};

	// loc_16612

	if (ONE(RPM_FLAGS, 0x2000) && ONE(word_FFFF8A48, 0x80) && ZRO(word_FFFF89F2, 0x400))
	{
		// loc_1663A

		u32 r1 = word_FFFF8BAC;

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

		if (word_FFFF8BAA != 0)
		{
			DECLIM(word_FFFF8BAA);

			if (word_FFFF8BAA == 0)
			{
				CLR(RPM_FLAGS, 0x2000);
			};

			StartInjectSync(r1, r2);
		};
		
		// loc_1673C

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_16750()
{
	__disable_irq();

	SET(word_FFFF8B4E, 0x80);
	CLR(word_FFFF8B4E, 0x40);

	__enable_irq();

	u32 r1 = word_FFFF8A48;

	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		if (wMUT10_Coolant_Temperature_Scaled <= word_1720)
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
		if ((byte_1071 != 0 && (wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT)) || cranking_stall_timer_up >= word_FFFF8BB0)
		{
			CLR(r1, 0x80);
		};
	};

	word_FFFF8A48 = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_167EC()
{
	u32 r1 = 0x89F;

	r1 &= wMUT1E_MAF_RESET_FLAG;

	u32 r8 = 0x800;

	r8 &= word_FFFF89F6;

	u32 r2 = word_FFFF8AFC;

	if (FUEL_CUT_FLAG_FFFF8A5E & 4) 
	{
		SET(r1, 0x8000);
	};

	if (FUEL_CUT_FLAG_FFFF8A5E & 0x8000) 
	{
		SET(r1, 0x200);
	};

	if (ZRO(wMUT1E_MAF_RESET_FLAG, CRANKING))
	{
		r2 = word_FFFF8AFA;
	};

	__disable_irq();

	word_FFFF8AFE = r2;

	word_FFFF8BAE = word_FFFF8BAC;

	RPM_FLAGS = (RPM_FLAGS & 0x7560) | r1;

	word_FFFF8A5C = (word_FFFF8A5C & ~0x800) | r8;

	MUTC7_copy = bMUTC7;

	MUTC8_copy = bMUTC8;

	wMUT50_Long_Fuel_Trim_Bank_1_COPY = wMUT50_Long_Fuel_Trim_Bank_1;
	wMUT51_Long_Fuel_Trim_Bank_2_COPY = wMUT51_Long_Fuel_Trim_Bank_2;

	wMUT52_COPY = wMUT52;
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

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_16AA8()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_16BFE()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void FU03_sub_16C60()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void MAF_air_flow_rate_EVO()
{
//	Mul_DW_Div(word_FFFF8AB8 * word_FFFF8AB6 * word_FFFF89E2, MUT28 * 118, 6400) >> 16;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


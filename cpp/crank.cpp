#pragma section _crank

#include <machine.h>
#include <umachine.h>

#include "misc.h"
#include "hwreg.h"

#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define Get_ADC_Knock				((void(*)(void))0xA92C)
#define atu22_Get_DSTR_0x3C00		((u16(*)(void))0xC850)
#define Reset_IRQ0F					((u16(*)(void))0xC258)




//#define CRANK75_Knock_sub_24AC0		((void(*)(void))0x24AC0)

#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define CEL8_7974			((Axis*)0x7974)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define unk100_62FC			((Map3D_B *)0x62FC)
#define unk112_5240			((Map3D_B *)0x5240)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define	word_98BA				((const u16*)0x98BA)                                                     
#define	word_98C4				((const u16*)0x98C4)                                                     
#define	word_98CC				((const u16*)0x98CC)                                                     
#define	word_98E6				((const u16*)0x98E6)                                                     
#define	word_98D4				((const u16*)0x98D4)                                                     
#define	byte_342F				((const byte*)0x342F)                                                     
#define	byte_35B7				((const byte*)0x35B7)                                                     

#define	word_98C2				(*(const u16*)0x98BA)                                                     
#define	word_98EA				(*(const u16*)0x98EA)                                                     
#define	word_98EC				(*(const u16*)0x98EC)                                                     
#define	word_98EE				(*(const u16*)0x98EE)                                                     

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


static void CRANK5_root_sub_DC18(u16 osbr, u32 icr);
static void CRANK75_root_sub_DB40(u16 osbr, u32 icr);

static void SetIgnCoilChargeStartTime(u16 mask, u16 v);
static void SetIgnSparkStartTime(u16 mask, u16 v);

void StartInjectSync(u16 v, u16 mask);
void StartInjectAsync(u16 v, u16 mask);
void InjOpenStart(u16 v, u16 mask);

u16 INJECTOR_RESCALED_sub_26174(u16 v);
u16 atu22_Get_ECNT9A();




static u16 CRANK75_FiltrCrankHT_2494E(u16 v1, u16 v2);
static u16 CRANK75_Get_IgnCoilTime(u16 v);
static void CRANK75_Knock_sub_23F8C();
static void CRANK75_Knock_sub_24AC0();
static void CRANK75_MainUpdateTiming();
static void CRANK75_sub_232A0();
static bool CRANK75_sub_24636();
static void CRANK75_sub_2467E();
static void CRANK75_sub_260B8();
static void CRANK75_sub_2941C();
static void CRANK75_sub_2B168();


static bool CRANK_CheckCamshaft_sub_A7C0();
static void CRANK_MAF_MAP_Calcs_sub_250F8(u16 v1, u16 v2);
static void CRANK_sub_262D0();


static void CRANK5_SetIgnCoilTime_Fin();
static void CRANK5_sub_24AF0();
static void CRANK5_sub_2504A();
static void CRANK5_sub_2506E();
static void CRANK5_sub_21A04();
static void CRANK5_sub_29438();
static void CRANK5_sub_29558();
static void CRANK5_sub_29750();
static void CRANK5_sub_2A684();
static void CRANK5_sub_2AAA2();
static void CRANK5_sub_2AC5C();
static void CRANK5_sub_2AEE4();
static void CRANK5_sub_C990(u16 v);





static u16 sub_2640E(u16 v);
static void Update_Gen_G_output();


static void atu22_IMF2G_event();
static void atu22_CMF2G_event();
static void ClearTSR_2E_2F_2G(u16 v);
static bool Check_PEDRL_4();
static bool Check_PEDRL_1();

static void Ign_handler(u16 v);
static u16 Get_2E_2F_2G_status();

static void Pulse_TIO2_E_F_G_out_1(u16 mask);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(atu02_ici0A)

extern "C" void atu02_ici0A()
{
	u16 r1 = 0;

	__disable_irq();

	ici0A_TCNT2A = reg_TCNT2A;

	CLR(reg_TSR0, 1);

	crank_OSBR2_4us = reg_OSBR2;

	crank_ICR0AH_250ns = reg_ICR0A;

	if (crank_Flags & 1)
	{
		if ((reg_PADRL & 1) == 0)
		{
			r1 = 1;
		};
	}
	else
	{
		if ((reg_PADRL & 1) != 0)
		{
			r1 = 1;
		};
	};

	if (r1 != 0) // ((crank_Flags ^ reg_PADRL) & 1)
	{
		reg_OCR2G = reg_TCNT2B + 13;

		SET(crank_Flags, 2);
	}
	else
	{
		reg_OCR2G = reg_TCNT2B - 1;

		CLR(crank_Flags, 2);
	};

	CLR(reg_TSR2B, 0x40);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(atu22_imi2G)

extern "C" void atu22_imi2G()
{
	if (reg_TSR2A & 0x40)
	{
		__disable_irq();

		CLR(reg_TSR2A, 0x40);

		__enable_irq();

		atu22_IMF2G_event();
	};

	if (reg_TSR2B & 0x40)
	{
		__disable_irq();

		CLR(reg_TSR2B, 0x40);

		__enable_irq();

		atu22_CMF2G_event();
	};
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#pragma interrupt(atu22_imi2H) 

extern "C" void atu22_imi2H()
{
	__disable_irq();

	CLR(reg_TSR2B, 0x80);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(atu22_imi2E)

extern "C" void atu22_imi2E()
{
	__disable_irq();

	CLR(reg_TSR2A, 0x10);

	__enable_irq();

	Ign_handler(1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(atu22_imi2F)

extern "C" void atu22_imi2F()
{
	__disable_irq();

	CLR(reg_TSR2A, 0x20);

	__enable_irq();

	Ign_handler(2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void atu22_IMF2G_event()
{
	__disable_irq();

	ClearTSR_2E_2F_2G(4);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void atu22_CMF2G_event()
{
	__disable_irq();

	u32 r3 = crank_ICR0AH_250ns;
	u32 r6 = crank_OSBR2_4us;

	if (crank_Flags & 2)
	{
		CLR(crank_Flags, 2);

		if (crank_Flags & 1)
		{
			CRANK75_root_sub_DB40(r6, r3);
		}
		else
		{
			CRANK5_root_sub_DC18(r6, r3);
		};
	}
	else
	{
		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Ign_handler(u16 mask)
{
	u16 r1 = mask;

	ClearTSR_2E_2F_2G(r1);

	SET(local_2636C, timerMask_1_2E_2F & r1);

	r1 = timerMask_1_2E_2F & local_2636C;

	if (timerMask_1_2E_2F == r1)
	{
		if (state_FFFF8C60 == 2)
		{
			state_FFFF8C60 = 1;

			if ((word_FFFF8C5E & 1) == 0)
			{
				SetIgnSparkStartTime(r1, timerValue_1_2E_2F);
			};
		}
		else if (state_FFFF8C60 == 1 && (word_FFFF8C5E & 1) == 0)
		{
			// loc_263CE

			state_FFFF8C60 = 0;

			SetIgnCoilChargeStartTime(timerMask_0_2E_2F, timerValue_0_2E_2F);
		};

		local_2636C &= ~r1;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 Get_2E_2F_2G_status()
{
	__disable_irq();

	u32 r1 = reg_PHDRH;

	__enable_irq();

	return (~(r1 >> 4)) & 7;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Pulse_TIO2_E_F_G_out_1(u16 mask)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_root_sub_DC18(u16 osbr, u32 icr)
{
	if ((osbr - crankPrevOSBR2_A) >= 162 || timer_up_FFFF8522 >= 40)
	{
		if (timer_up_FFFF8522 >= 39)
		{
			crank_dt_ICR0AH_B = 0xFFFFFFFF;

			crankHT_B = 0xFFFF;
		}
		else
		{
			crankHT_B = osbr - crankPrev_OSBR2_B;

			crank_dt_ICR0AH_B = icr - dword_FFFF9ABC;
		};

		crankPrev_OSBR2_B = osbr;

		dword_FFFF9ABC = icr;

		timer_up_FFFF8524 = 0;

		__enable_irq();

		CRANK5_sub_24AF0();

		word_FFFF8870 = reg_TCNT2A - ici0A_TCNT2A;

		SET(crank_Flags, 1);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK75_root_sub_DB40(u16 osbr, u32 icr)
{
    if ((osbr - crankPrev_OSBR2_B) >= 254 || timer_up_FFFF8524 >= 40)
	{
		if (timer_up_FFFF8522 >= 39)
		{
			crankPrevOSBR2_A = osbr;

			crankPrevICR0AH_A = icr;

			null_crank_dt_ICR0AH_A = (u32)-1;

			crankHT_A = (u16)-1;
		}
		else
		{
			crankHT_A = osbr - crankPrevOSBR2_A;

			crankPrevOSBR2_A = osbr;

			null_crank_dt_ICR0AH_A = icr - crankPrevICR0AH_A;

			crankPrevICR0AH_A = icr;
		};

		timer_up_FFFF8522 = 0;

		__enable_irq();

		CRANK75_sub_232A0();

		word_FFFF886E = reg_TCNT2A - ici0A_TCNT2A;

		__disable_irq();

		CLR(crank_Flags, 1);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void ClearTSR_2E_2F_2G(u16 v)
{
	__disable_irq();

	u32 r13 = reg_TCNT2A;

	r13 -= 1;

	if (v & 1)
	{
		reg_GR2E = r13;

		CLR(reg_TSR2A, 0x10);
	};

	if (v & 2)
	{
		reg_GR2F = r13;

		CLR(reg_TSR2A, 0x20);
	};

	if (v & 4)
	{
		reg_GR2G = r13;

		CLR(reg_TSR2A, 0x40);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK75_sub_232A0()
{
	const u32 r9 = 0x8000;

	__disable_irq();

	camshaft_Shift <<= 1;

	if (CRANK_CheckCamshaft_sub_A7C0())
	{
		camshaft_Shift |= 1;
	};

	if (word_FFFF8F2A & 1)
	{
		stroke_FFFF8F22 += 1;

		if (stroke_FFFF8F22 >= 4)
		{
			stroke_FFFF8F22 = 0;
		};
	}
	else
	{
		stroke_FFFF8F22 = 1;
	};

	word_FFFF8F32 += 1;

	if (word_FFFF8F32 == 0)
	{
		word_FFFF8F32 -= 1;
	};

	u32 r1 = word_98BA[stroke_FFFF8F22] ^ camshaft_Shift;

	if (word_FFFF8F32 < 4)
	{
		CLR(word_FFFF8F2A, 1);
		word_FFFF8F2C = 2;
	}
	else
	{
		if (word_98C2 & r1)
		{
			if (word_FFFF8F2C != 0)
			{
				word_FFFF8F2C -= 1;
			}
			else if ((camshaft_Shift & 0xF) != 0 && (camshaft_Shift & 0xF) != 0xF)
			{
				CLR(word_FFFF8F2A, 1);
			}
		}
		else 
		{
			if ((r1 & 0xF) == 0)
			{
				SET(word_FFFF8F2A, 1);
			};

			word_FFFF8F2C = 2;
		};
	};

	if (Check_PEDRL_4())
	{
		if ((word_FFFF8F34 += 1) == 0)
		{
			word_FFFF8F34 -= 1;
		};
	}
	else
	{
		word_FFFF8F34 = 0;
	};

	if ((word_FFFF8F2A & 1) && (word_FFFF8F34 == 0 || word_FFFF8F34 >= 5))
	{
		SET(word_FFFF8F2A, 0x10);
	}
	else
	{
		CLR(word_FFFF8F2A, 0x10);
	};

	r1 = (word_FFFF8F34 & 0x10) ? word_98BA[stroke_FFFF8F22] : camshaft_Shift;

	timerMask_1_2E_2F = word_98C4[r1 & 3];
	timerMask_0_2E_2F = word_98CC[r1 & 3];

	word_FFFF8C62 <<= 1;

	if (Check_PEDRL_1())
	{
		word_FFFF8C62 |= 1;
	};

	u32 r8 = crankHT_x_4us = crankHT_A;

	u32 r2 = ((word_FFFF8C5C & 5) << 1) | 0x35;

	if (IGN_FLAG9_FFFF8BB6 & 0x80) // Fix timing at 5 degrees;
	{
		SET(r2, 0x40);
	};

	if (r8 >= t1_crankHT_1798/*1562*/)
	{
		CLR(r2, 0x20);

		if (r8 >= 4225)
		{
			CLR(r2, 4);
		};

		if (r8 >= 4870)
		{
			CLR(r2, 0x10);
		};

		r1 = 14848;

		if (word_FFFF8C5C & 1)
		{
			r1 = 18688;
		};

		if (r8 >= r1)
		{
			CLR(r2, 1);
		};
	};

	word_FFFF8C5C = r2;

	CLR(word_FFFF8C5E, 1);
	
	u32 r4;

	if (timer_FFFF8594 == 0)
	{
		word_FFFF8C5C = 0;

		r4 = 0;
	}
	else
	{
		if (Check_PEDRL_4() || (word_FFFF8C5C & 0x40) || (word_FFFF8F2A & 1) == 0)
		{
			timingAdvInternal1 = 202;
			timingAdvInternal2 = 202;
			timingAdvScaled = 160;
		}
		else
		{
			CRANK75_MainUpdateTiming();
		};

		if ((Check_PEDRL_4() && (wMUT14_Battery_Level_ADC8bit < 0xFF)) || (word_FFFF8C5C & 1) == 0)
		{
			word_FFFF8C5C = 0;

			r4 = 1;
		}
		else if ((word_FFFF8C5C & 2) == 0)
		{
			if (CRANK75_sub_24636())
			{
				word_FFFF8C5C = 0;
				r4 = 1;
			}
			else
			{
				word_FFFF8C5C = 1;
				r4 = 1;
			};
		}
		else
		{
			u32 r2 = filtred_crankHT_x_4us = CRANK75_FiltrCrankHT_2494E(r8, crankHT_x_4us_2);

			if ((r8 > 6250 && timingAdvInternal1 <= 202 && !CRANK75_sub_24636()) || (r2 & r9) || r2 < 326)
			{
				word_FFFF8C5C = 0;
				r4 = 1;
			}
			else
			{
				word_FFFF8C20 = Sub_Lim_0(Mul_Div(timingAdvInternal1 , r2, 512), word_179E/*15*/);
				word_FFFF8C22 = Sub_Lim_0(Mul_Div(timingAdvInternal2 , r2, 512), word_179E/*15*/);

				if ((Get_2E_2F_2G_status() & timerMask_1_2E_2F) == timerMask_1_2E_2F)
				{
					state_FFFF8C60 = 1;

					ClearTSR_2E_2F_2G(timerMask_1_2E_2F);
				}
				else
				{
					// loc_23704

					state_FFFF8C60 = 2;

					u32 r13 = crankPrevOSBR2_A + word_FFFF8C20 - CRANK75_Get_IgnCoilTime(r1);
					
					r1 = timerValue_1_2E_2F + word_179C/*250*/;

					if ((r13 - r1) & r9)
					{
						r13 = r1;
					};

					if ((r13 - reg_TCNT2A) & r9)
					{
						r13 = reg_TCNT2A;
					};

					ignCoilChargeStartTime_x4us = r13;

					SetIgnCoilChargeStartTime(timerMask_1_2E_2F, r13);
				};

				// loc_2376E

				timerValue_1_2E_2F = crankPrevOSBR2_A + word_FFFF8C20;


				if ((timingAdvInternal1 >= 202 && (word_FFFF8C5C & 0x40)) || (word_FFFF8C5C & 0x10) == 0)
				{
					// loc_23796

					SET(word_FFFF8C5E, 1);
				}
				else
				{
					// loc_237A2

					if (state_FFFF8C60 != 2)
					{
						if (timerValue_1_2E_2F < reg_TCNT2A)
						{
							timerValue_1_2E_2F = reg_TCNT2A;
						};

						SetIgnSparkStartTime(timerMask_1_2E_2F, timerValue_1_2E_2F);
					};
				};

				// loc_237D6

				if (timingAdvInternal1 <= 199)
				{
					// loc_23834
					word_FFFF8C24 = 0;
				}
				else if (word_FFFF8C5C & 0x40)
				{
					// loc_2382A
					word_FFFF8C24 = 50;
				}
				else
				{
					u32 r13 = Sub_Lim_0(Mul_Div(r2, (timingAdvInternal1 - 199), 512), word_179E);

					word_FFFF8C24 = (r13 >= 1) ? r13 : 1;
				};

				// loc_2383A
				
				r2 += crankPrevOSBR2_A;

				r2 += word_FFFF8C22;

				u16 r13 = r2 - ignCoilTime_Fin;

				u32 r1 = timerValue_1_2E_2F + word_179C;

				if (r13 < r1)
				{
					r13 = r1;
				};

				timerValue_0_2E_2F = r13;
			};
		};
	};

	// loc_23872

	crankHT_x_4us_2 = crankHT_x_4us;

	crankHT_x_512us = crankHT_x_4us >> 7;

	__enable_irq();

	/*u32*/ r2 = word_1830;

	/*u32*/ r1 = word_FFFF8C62 & 0xF;

	if (ZRO(IGN_FLAG9_FFFF8BB6, 1) || r1 == 0 || r1 == 0xF || ZRO(word_FFFF8F2A, 1))
	{
		// loc_23932

		if (word_FFFF8C66 != 0)
		{
			word_FFFF8C66 = r2;
		};

		if (word_FFFF8C68 != 0)
		{
			word_FFFF8C68 = r2;
		};

		if (word_FFFF8C6A != 0)
		{
			word_FFFF8C6A = r2;
		};
	}
	else
	{
		// loc_2396C

		u16* p = (timerMask_1_2E_2F == 1) ? &word_FFFF8C68 : &word_FFFF8C66;

		r1 &= 3;

		if (r1 == 2 || r1 != 1)
		{
			*p = r2;
		}
		else if (*p != 0)
		{
			*p -= 1;
		};

		u32 r13 = 0xFFFF;

		if (word_FFFF8C66 == 0)
		{
			r13 = ~word_98EA/*9*/ & 0xFFFF;
		};

		if (word_FFFF8C68 == 0)
		{
			r13 &= ~word_98EC/*6*/;
		};

		if (word_FFFF8C6A == 0)
		{
			r13 &= ~word_98EE/*0*/;
		};

		injectors_mask_FFFF8C72 = r13;

		if ((r13 & 0xF) == 0xF)
		{
			CLR(word_FFFF8BBA, 1);
		}
		else
		{
			SET(word_FFFF8BBA, 1);
		};
	};

	// loc_239F4

	if (ZRO(wMUTD1_BitMap_FAA, 8) || (word_FFFF80FA & 0x80) || word_FFFF8EBA != 0 || (FLAGS_FFFF8EB0 & 0x80))
	{
		timer_FFFF8594 = 51;
	};

	null_CrankHT_x_4us_1 = null_CrankHT_x_4us_2;
	null_CrankHT_x_4us_2 = crankHT_x_4us_4;
	crankHT_x_4us_4 = crankHT_x_4us_3;
	crankHT_x_4us_3 = crankHT_x_4us;

	r1 = DIV_DW_R(30720000, crankHT_x_4us_3);

	if ((RPM_FLAGS & CRANKING) || cranking_end_timer_up < word_17BA)
	{
		RPM_x_4_096__1 = r1;
		RPM_x_4_096__2 = r1;
		RPM_x_4_096__3 = r1;
	}
	else
	{
		RPM_x_4_096__1 = Interpolate_256(RPM_x_4_096__1, r1, word_FFFF8950);
		RPM_x_4_096__2 = Interpolate_256(RPM_x_4_096__2, r1, word_1842/*230*/);
		RPM_x_4_096__3 = Interpolate_256(RPM_x_4_096__3, r1, word_2340/*205*/);
	};

	// loc_23ABE

	DECLIM(IGN_0xA_FFFF8BE8);

	// loc_23ACE

	if (IGN_0xA_FFFF8BE8 == 0 && IGNITION_FINAL2_FFFF8BE6 < 0x80)
	{
		IGNITION_FINAL2_FFFF8BE6 += 1;

		IGN_0xA_FFFF8BE8 = word_17C2;
	};

	DECLIM(timer_Delta_TPS);
		
	if (timer_Delta_TPS == 0)
	{
		abs_Delta_TPS = 0;
	};

	// loc_23B0E

	word_FFFF8BF2 = Sub_Lim_0(word_FFFF8BF2, word_1B1A/*8*/);

	DECLIM(word_FFFF8BEC);
	
	DECLIM(word_FFFF8BEE);

	if (word_FFFF8BEC == 0 && word_FFFF8BEE == 0)
	{
		INCLIM80(word_FFFF8BEA);

		word_FFFF8BEE = word_1898/*1*/;
	};

	// loc_23B70

	RPM8_FFFF8B02 = RPM8_FFFF8B00;
	RPM8_FFFF8B00 = 960;

	if ((word_FFFF8ADA += 1) == 0)
	{
		word_FFFF8ADA -= 1;
	};

	if (RPM_FLAGS & 0x800)
	{
		u32 r13;

		if (wMUT18_Open_Loop_Bit_Array & 0x40)
		{
			u32 r1;

			if (word_FFFF81E0 & 0x100)
			{
				r1 = (byte_1053/*0*/ == 1) ? (dec_Oxygen_Trim << 1) : Div_R4_R5__R0(dec_Oxygen_Trim << 7, word_247A/*128*/);
			}
			else
			{
				r1 = dec_Oxygen_Trim << 2;
			};

			r13 = Sub_Lim_0(wMUT0F_Oxygen_Feedback_Trim, r1);
		}
		else
		{
			u32 r1;

			if (word_FFFF81E0 & 0x100)
			{
				r1 = (byte_1053/*0*/ == 1) ? (inc_Oxygen_Trim << 1) : Div_R4_R5__R0(inc_Oxygen_Trim << 7, word_247A/*128*/);
			}
			else
			{
				r1 = inc_Oxygen_Trim << 2;
			};
			
			r13 = Add_Lim_FFFF(wMUT0F_Oxygen_Feedback_Trim, r1);
		};

		wMUT0F_Oxygen_Feedback_Trim = Lim16(r13, limLo_O2_Feedback_Trim, limHi_O2_Feedback_Trim);
	};

	// loc_23D48

	CRANK75_sub_260B8();

	if (	(wMUT1E_MAF_RESET_FLAG & CRANKING) 
		&&	(word_FFFF8A48 & 0x80) 
		&&	ZRO(word_FFFF8B4E, 0x20)
		&&	ZRO(word_FFFF89F2, 0x400)
		&&	ZRO(word_FFFF89F2, 0x800))
	{
		CRANK_MAF_MAP_Calcs_sub_250F8(0, 0);
	};

	// loc_23D98

	if ((RPM_FLAGS & 0x200) && ZRO(RPM_FLAGS, CRANKING_TIMED))
	{
		CRANK_MAF_MAP_Calcs_sub_250F8(1, 0);
	}
	else if (word_FFFF8B4E & 0x20)
	{
		if (injPW_final != 0 && injPW_chnl != 0)
		{
			InjOpenStart(injPW_final, injPW_chnl);
		};

		CLR(word_FFFF8B4E, 0x20);

		CRANK_sub_262D0();
	};

	// loc_23E34

	word_FFFF8DD4 += crankHT_A >> 3;

	DECLIM(word_FFFF8DD8);

	if (word_FFFF8DD8 == 0)
	{
		wMUT90_ECNT9A = atu22_Get_ECNT9A();

		r1 = Mul_Div_R(wMUT90_ECNT9A, 2048, word_FFFF8DD4);

		wMUT91_Timer_Status_Register_9_TSR9_Scaled = r1 = (r1 >= 0xFF) ? 0xFF : r1;

		if (RPM_FLAGS & CRANKING)
		{
			fix8_FFFF8DCE = r1 << 8;

			wMUT92_Timer_Status_Register_9_TSR9_Scaled_Checked = r1;
		}
		else
		{
			wMUT92_Timer_Status_Register_9_TSR9_Scaled_Checked = Div_256_R(fix8_FFFF8DCE = Interpolate_256(fix8_FFFF8DCE, r1 << 8, word_FFFF8DD2));
		};

		word_FFFF8DD4 = 0;
		word_FFFF8DD6 = 0;
		word_FFFF8DD8 = 0;
	};

	// loc_23EE6

	r1 = 0xFFFF;

	if (wMUT8F < 0xFF)
	{
		r1 = DIV_DW_R(Mul16(wMUT8F, crankHT_A), 40000);
	};

	gen_G_timer = (r1 >= 1) ? r1 : 1;

	SET(KNOCK_FLAG2_FFFF887A, 1);

	Update_Gen_G_output();

	CRANK75_sub_2941C();

	CRANK75_Knock_sub_23F8C();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool CRANK75_sub_24636()
{
	u32 r1 = (crankHT_x_4us >= crankHT_x_4us_2) ? (crankHT_x_4us - crankHT_x_4us_2) : (crankHT_x_4us_2 - crankHT_x_4us);

	return r1 >= Mul_Fix8_Lim_FFFF(crankHT_x_4us, word_1792/*0.125*256*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool CRANK_CheckCamshaft_sub_A7C0()
{
	return (reg_PADRL & 4) == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool Check_PEDRL_4()
{
	return (reg_PEDRL & 4) == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool Check_PEDRL_1()
{
	return (reg_PEDRL & 1) != 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void CRANK75_Knock_sub_23F8C()
{
	const u32 r8 = 0x8000;

	if ((wMUTD1_BitMap_FAA & 0x80) == 0) // 0x80 - Enable High Oct Ign Map Lookup and other
	{
		return;
	};

	Get_ADC_Knock();

	u32 r1 = wMUT30_Knock_Voltage;

	if (r1 > 100)
	{
		r1 = (r1-100)*435/256+55;
	}
	else
	{
		if (r1 > 92)
		{
			r1 = (r1-92)*0xC0/256+49;
		}
		else
		{
			r1 = r1 * 136 / 256;
		};
	};

	if (r1 >= 255)
	{
		r1 = 255;
	};

	u32 r2 = wMUT6A_Knock_ADC_Processed;

	wMUT6A_Knock_ADC_Processed = r1;

	r1 = r2;

	if ((KNOCK_FLAG_FFFF8C34 & 0x400) // 0x400 - (MUT21_RPM_x125div4 >= word_1C28(2000))&&(wMUT1C_ECU_Load >= word_1C26(55kPa))
		&& (KNOCK_FLAG1_FFFF8C36 & 1) == 0)
	{
		u32 r13, r3;

		if (wMUT6A_Knock_ADC_Processed >= r1)
		{
			r13 = wMUT6A_Knock_ADC_Processed - r1;
		}
		else
		{
			r13 = r1 -= wMUT6A_Knock_ADC_Processed;
		};

		if (KNOCK_FLAG2_FFFF887A & 2)
		{
			r3 = t1_knock_signal_change_check_1C2E;
		}
		else
		{
			r3 = t1_knock_signal_change_check_1C2C;
		};

		if (r13 >= r3)
		{
			wMUT72_Knock_Present &= ~1;

			wMUT6E_KnockFaultCheckTimer = 0;
		}
		else
		{
			if (wMUT6E_KnockFaultCheckTimer < 0xFFFFFFFF)
			{
				wMUT6E_KnockFaultCheckTimer += 1;
			};

			if (wMUT6E_KnockFaultCheckTimer > word_1C30)
			{
				wMUT72_Knock_Present |= 1;

				wMUT6E_KnockFaultCheckTimer = word_1C30;
			};
		};

		wMUT6D_Knock_Change = r13;

	} // if (KNOCK_FLAG_FFFF8C34 & 0x400)
	else
	{
		wMUT6E_KnockFaultCheckTimer = 0;

		wMUT6D_Knock_Change = 0;
	};

	Timer_Counter_Related_sub_C928();

	KNOCK_BASE_MINUS_ADC_FFFF8C40 = Sub_Lim_0(wMUT6A_Knock_ADC_Processed, KNOCK_BASE_FFFF8C3A);




	if ((KNOCK_FLAG_FFFF8C34 & 0x40) == 0) // 0x40 - enabled knock retard; IG04_Check_17074()
	{
		wMUT26_Knock_Retard = 0;

		CRANK75_Knock_sub_24AC0();

		r1 = 0;
	}
	else if (wMUT72_Knock_Present & 1) // 1 - ? Knock sensor fault; (wMUT6E_Knock_Dynamics >= word_1C30)
	{

		if (KNOCK_FLAG_FFFF8C34 & 0x80)
		{
			wMUT26_Knock_Retard = t1_knock_control_ign_retard_faulty_sensor_17E8;
		}
		else
		{
			wMUT26_Knock_Retard = t1_knock_control_ign_retard_faulty_sensor_17EA;
		};

		CRANK75_Knock_sub_24AC0();

		r1 = 0;
	}
	else
	{
		// loc_2417A:                                                                                     

		if (KNOCK_BASE_MINUS_ADC_FFFF8C40 != 0)
		{
			if (KNOCK_FLAG_FFFF8C34 & 0x80)
			{
				r1 = t1_knock_control__17CC;
			}
			else
			{
				r1 = t1_knock_control__17CE;
			};

			r1 = 1 + Mul_Div_R(KNOCK_BASE_MINUS_ADC_FFFF8C40, r1, KNOCK_BASE_FFFF8C3A << 3);

			if (r1 >= 0xFF)
			{
				r1 = 0xFF;
			};
		}
		else
		{
			r1 = 0;
		}; //  if (KNOCK_BASE_MINUS_ADC_FFFF8C40 != 0)


		// loc_2421E:                                                                                      ; CODE XREF: CRANK75_Knock_sub_23F8C+230j

		if (KNOCK_FLAG_FFFF8C34 & 0x200)
		{
			bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E += 1;

			if (bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E >= KNOCK_PRECOUNT_MAX_FFFF8C4A)
			{
				bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E = KNOCK_PRECOUNT_MAX_FFFF8C4A;

				bMUTCB_KNOCK_U_FFF8C54 = 0x8000;
			};

			bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 += 1;

			if (bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 >= KNOCK_PRECOUNT_MAX_FFFF8C4A)
			{
				bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 = KNOCK_PRECOUNT_MAX_FFFF8C4A;

				bMUTCC_KNOCK_UB_FFFF8C56 = 0x8000;
			};

			KNOCK_REL_compare_to_10_FFFF8C5A <<= 1;


			if (r1 >= t1_unk_180E)
			{
				if (r1 <= KNOCK_REL_1_FFFF8C4C)
				{
					KNOCK_REL_compare_to_10_FFFF8C5A |= 1;

					if (bMUTCB_KNOCK_U_FFF8C54 == strokeNumber)
					{
						bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E = 0;

						r1 = 0;
					}
					else
					{
						if (bMUTCC_KNOCK_UB_FFFF8C56 == strokeNumber)
						{
							bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 = 0;

							r1 = 0;
						}
						else
						{
							if (KNOCK_PRECOUNT_1033 == 0 || (KNOCK_REL_compare_to_10_FFFF8C5A & 0x10))
							{
								if (r8 == bMUTCB_KNOCK_U_FFF8C54)
								{
									bMUTCB_KNOCK_U_FFF8C54 = strokeNumber;

									bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E = 0;

									if (KNOCK_PRECOUNT_1033 != 0)

									{
										r1 = 0;
									};
								}
								else
								{
									if (bMUTCC_KNOCK_UB_FFFF8C56 == r8)
									{
										bMUTCC_KNOCK_UB_FFFF8C56 = strokeNumber;

										bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 = 0;

										if (KNOCK_PRECOUNT_1033 != 0)
										{
											r1 = 0;
										};
									};
								};
							};
						};
					};
				};
			};
		}
		else  // if (KNOCK_FLAG_FFFF8C34 & 0x200)
		{
			CRANK75_Knock_sub_24AC0();
		}; //     if (KNOCK_FLAG_FFFF8C34 & 0x200)

		// loc_2432C:                                                                                      ; CODE XREF: CRANK75_Knock_sub_23F8C+2F8j

		max_Retard = max_Knock_Retard;

		u32 r13;

		if (KNOCK_FLAG_FFFF8C34 & 0x80)
		{
			r13 = t1_knock_control__17D0;
		}
		else
		{
			r13 = t1_knock_control__17D2;
		};

		if (r1 > r13)
		{
			r1 = r13;
		};

		r2 = wMUT26_Knock_Retard + r1;

		if (r2 < max_Retard)
		{
			wMUT26_Knock_Retard = r2;
		}
		else
		{
			wMUT26_Knock_Retard = max_Retard;
		};

	};



	// loc_243A8:                                                                                      ; CODE XREF: CRANK75_Knock_sub_23F8C+1EAj

	wMUT6C_Knock_Sum_Addition = r1;

	bMUTCA_KNOCK_VAR22_FFFF9988 = KNOCK_VAR2_FFFF8C3E;

	wMUT6B_Knock_Base = KNOCK_BASE_FFFF8C3A;

	if (wMUT6A_Knock_ADC_Processed >= (KNOCK_VAR2_FFFF8C3E>>8))
	{
		if (KNOCK_DYNAMICS2_FFFF8C48 < 0xFFFF)
		{
			KNOCK_DYNAMICS2_FFFF8C48 += 1;
		};
	}
	else
	{
		KNOCK_DYNAMICS2_FFFF8C48 = 0;
	};

	r2 = 0x20;

	if (wMUT6F_Knock_Acceleration != 0)
	{
		r2 = 0xF000;
		r1 = wMUT6A_Knock_ADC_Processed << 4;
	}
	else 
	{
		if (KNOCK_BASE_MINUS_ADC_FFFF8C40 != 0)
		{
			r2 = 0x100;
		}
		else if (KNOCK_DYNAMICS2_FFFF8C48 >= t1_knock_dynamics_1820)
		{
			r2 = 0x10;
		}
		else if ((KNOCK_VAR2_FFFF8C3E >> 8) != 0 && ((KNOCK_VAR2_FFFF8C3E >> 8) * t1_knock_multiplier_1822 <= (wMUT6A_Knock_ADC_Processed << 3)))
		{
			r2 = 0x100;
		};

		if (r2 == 0x10)
		{
			r2 = 0xF000;
			r1 = wMUT6A_Knock_ADC_Processed << 4;
		}
		else if (r2 == 0x20)
		{
			r2 = 0xF800;

			r1 = wMUT6A_Knock_ADC_Processed << 3;
		}
		else
		{
			r2 = 0xFF00;

			r1 = wMUT6A_Knock_ADC_Processed * 1;
		};
	};

	//++++++++++++++++++++++++++++++++++++++++++++++

	r1 <<= 16;

	KNOCK_VAR1_bMUTC9_FFFF8C3C = Div_65536_R(Add_Lim_FFFFFFFF(KNOCK_VAR1_bMUTC9_FFFF8C3C * r2, r1));

	if ((KNOCK_FLAG2_FFFF887A & 2) == 0)
	{
		if (KNOCK_BASE_FFFF8C3A >= t1_knock_base_compare_17EE)
		{
			KNOCK_FLAG1_FFFF8C36 |= 0x10;

			KNOCK_RPM_FFFF8C74 = MUT21_RPM_x125div4;
		};
	}
	else
	{
		if (MUT21_RPM_x125div4 < Sub_Lim_0(KNOCK_RPM_FFFF8C74, t1_knock_rpm_17F0) || KNOCK_BASE_FFFF8C3A < t1_knock_base_compare_17EC)
		{
			KNOCK_FLAG1_FFFF8C36 &= ~0x10;
		};
	};

	//++++++++++++++++++++++++++++++++++++++++++++++

	KNOCK_FLAG1_FFFF8C36 &= ~1;

	if (((KNOCK_FLAG1_FFFF8C36 & 0x10) && (FLAGS_FFFF8EB0 & 0x80) == 0) || ((FLAGS_FFFF8EB0 & 0x80) && (KNOCK_FLAG_FFFF8C34 & 0x100)))
	{
		if ((KNOCK_FLAG2_FFFF887A & 2) == 0)
		{
			KNOCK_VAR1_bMUTC9_FFFF8C3C /= 3;

			KNOCK_VAR2_FFFF8C3E /= 3;

			KNOCK_BASE_FFFF8C3A = Lim16(KNOCK_BASE_FFFF8C3A/3, 1, 0xFF);

			KNOCK_FLAG1_FFFF8C36 |= 1;
		};

		KNOCK_FLAG2_FFFF887A |= 2;
	}
	else
	{
		if ((KNOCK_FLAG2_FFFF887A & 2) != 0)
		{
			KNOCK_VAR1_bMUTC9_FFFF8C3C *= 3;

			KNOCK_VAR2_FFFF8C3E *= 3;

			KNOCK_BASE_FFFF8C3A = Lim16(KNOCK_BASE_FFFF8C3A*3, 1, 0xFF);

			KNOCK_FLAG1_FFFF8C36 |= 1;
		};

		KNOCK_FLAG2_FFFF887A &= ~2;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK75_MainUpdateTiming()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 CRANK75_FiltrCrankHT_2494E(u16 v1, u16 v2)
{
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 CRANK75_Get_IgnCoilTime(u16 v)
{
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK75_Knock_sub_24AC0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_24AF0()
{
//	u32 r8 = 0x8000;

	__disable_irq();

	camshaft_Shift <<= 1;

	if (CRANK_CheckCamshaft_sub_A7C0())
	{
		SET(camshaft_Shift, 1);
	};

	u32 r13 = word_FFFF8C16 = crankHT_B;


	if (timer_FFFF8594 == 0 || (r13 & 0x8000))
	{
		word_FFFF8C5C = 0;

		// loc_24B50

		CRANK5_sub_2504A();
		CRANK5_SetIgnCoilTime_Fin();
	}
	else if (ZRO(word_FFFF8C5C, 2))
	{
		// loc_24B50

		CRANK5_sub_2504A();
		CRANK5_SetIgnCoilTime_Fin();
	}
	else
	{
		// loc_24B5C

		u32 r1 = word_FFFF8C24;

		if (r1 != 0)
		{
			if (Get_2E_2F_2G_status() & timerMask_1_2E_2F)
			{
				// loc_24B7E

				do
				{
					u32 r13 = Get_2E_2F_2G_status() & timerMask_1_2E_2F;
				}
				while (r13 != timerMask_1_2E_2F && r13 != 0);

				if (state_FFFF8C60 != 0
					&& ((word_FFFF8C5E & 1) || ABSDIF(timerValue_1_2E_2F - crankPrev_OSBR2_B, r1) > crankHT_x_512us))
				{
					CRANK5_sub_2506E();
				};
			}
			else
			{
				// loc_24C30

				if (state_FFFF8C60 == 2)
				{
					u32 r2 = crankPrev_OSBR2_B + r1 - ignCoilTime_Fin - crankHT_x_512us;

					if ((r2 - reg_TCNT2A) & 0x8000)
					{
						r2 = reg_TCNT2A;

						Pulse_TIO2_E_F_G_out_1(timerMask_1_2E_2F);

						ignCoilChargeStartTime_x4us = r2;

						CRANK5_sub_2506E();
					}
					else
					{
						// loc_24C80

						SetIgnCoilChargeStartTime(timerMask_1_2E_2F, r2);

						ignCoilChargeStartTime_x4us = r2;
					
						if (((word_FFFF8C5E & 1) || ABSDIF(timerValue_1_2E_2F - crankPrev_OSBR2_B, r1) > crankHT_x_512us))
						{
							timerValue_1_2E_2F = r1 + crankPrev_OSBR2_B;
						};
					};
				};
			};
		};

		// loc_24CD0

		if (ZRO(word_FFFF8F2A, 1) || ZRO(word_FFFF8F2A, 0x10)
			|| (ZRO(word_FFFF8C5C, 0x40/*Fix timing*/) && timingAdvInternal1 < 200 && (Get_2E_2F_2G_status() & timerMask_1_2E_2F) && state_FFFF8C60 != 0))
		{
			// loc_24D0A

			CRANK5_sub_2504A();
		};


		// loc_24D0E

		CRANK5_SetIgnCoilTime_Fin();

		u32 r2 = Mul_Fix8_Lim_FFFF(156, word_FFFF8C16) + crankPrev_OSBR2_B + word_FFFF8C22 - ignCoilTime_Fin;

		r1 = timerValue_1_2E_2F + word_179C/*250*/;

		if ((r2 - r1) & 0x8000)
		{
			r2 = r1;
		};

		// loc_24D54

		if (Get_2E_2F_2G_status() & timerMask_1_2E_2F)
		{
			if (state_FFFF8C60 != 0)
			{
				timerValue_0_2E_2F = r2;
			};
		}
		else
		{
			if (state_FFFF8C60 != 2)
			{
				state_FFFF8C60 = 0;

				SetIgnCoilChargeStartTime(timerMask_0_2E_2F, r2);
			};
			
			timerValue_0_2E_2F = r2;
		};
	};

	// loc_24DBE

	CLR(word_FFFF8C5E, 1);

	SET(word_FFFF8BBA, 0x80);

	if (wMUTD1_BitMap_FAA & 0x80/*Enable High Oct Ign Map Lookup and other*/)
	{
		CRANK5_sub_C990(25 + ((timerValue_1_2E_2F - crankPrev_OSBR2_B) & 0x8000) ? crankPrev_OSBR2_B : timerValue_1_2E_2F);
	};
	
	// loc_24DFE

	__enable_irq();

	if (timer_down_TXFLAG3_FFFF8574 == 0 || timer_FFFF8592 == 0)
	{
		word_FFFF8F2A = 0;

		SET(camshaft_Shift, ~1);

		word_FFFF8F28 = (camshaft_Shift & 1) ? 1 : 0;
	};

	// loc_24E3C

	u32 r1 = word_177A/*24*/;

	if (Check_PEDRL_4())
	{
		r1 <<= 1;
	};

	if (ZRO(wMUTD1_BitMap_FAA, 8) || (word_FFFF80FA & 0x80) || word_FFFF8EBA != 0 || (FLAGS_FFFF8EB0 & 0x80))
	{
		timer_FFFF8592 = r1;
	};
	
	// loc_24EE8


	if (RT_FLAG1_FFFF8888 & 0x80)
	{
		if (crank5_FFFF8A36 != 0)
		{
			crank5_FFFF8A36 -= 1;

			if (crank5_FFFF8A36 == 0)
			{
				SET(RPM_FLAGS, 0x4000);
			};
		};
	}
	else if (ZRO(RT_FLAG1_FFFF8888, 0x20))
	{
		crank5_FFFF8A36 = word_155E/*16*/;
	}
	else if (SPEED_FLAGS & 4)
	{
		crank5_FFFF8A36 = word_155C/*16*/;
	}
	else
	{
		crank5_FFFF8A36 = word_1560/*16*/;
	};

	// loc_24F58

	if (ZRO(RPM_FLAGS, DECELERATION_FUEL_CUT))
	{
		DECLIM(word_FFFF8AC0);	
	};

	DECLIM(word_FFFF8BF4);	

	DECLIM(word_FFFF8BF6);	

	if (word_FFFF8BF4 == 0 && word_FFFF8BF6 == 0 && word_FFFF8BFA != 0)
	{
		word_FFFF8BFA = Sub_Lim_0(word_FFFF8BFA, word_FFFF8BFE);

		word_FFFF8BF6 = (byte_1077/*0*/ != 0) ? word_FFFF8C8E : word_246C/*1*/;
	};

	// loc_24FDC	

	if ((word_FFFF8A48 & 0x80) && (RPM_FLAGS & 0x200))
	{
		CRANK_MAF_MAP_Calcs_sub_250F8(2, 1);
	}
	else
	{
		CRANK_MAF_MAP_Calcs_sub_250F8(0, 1);
	};

	stroke_FFFF8F26 = strokeNumber;

	CRANK5_sub_29438();

	if (word_FFFF89F2 & 1)
	{
		SET(word_FFFF89F2, 2);
	}
	else
	{
		SET(word_FFFF89F2, 1);

		curMaxMAP = 0;

		word_FFFF8556 = word_1764/*20*/;
	};

	CRANK5_sub_21A04();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_2504A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_2506E()
{
	u16 r1 = crankPrev_OSBR2_B + word_FFFF8C24;

	if (r1 < reg_TCNT2A)
	{
		r1 = reg_TCNT2A;
	};

	state_FFFF8C60 = 1;

	SetIgnSparkStartTime(timerMask_1_2E_2F, r1);

	timerValue_1_2E_2F = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_SetIgnCoilTime_Fin()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK_MAF_MAP_Calcs_sub_250F8(u16 v1, u16 v2)
{
	u32 r2, ipw, r9 = 0;

	if (v1 == 1)
	{
		// async_25DE6

		if (ONE(FUEL_CUT_FLAG_FFFF8A5E, 0x80) && ONE(RPM_FLAGS, CRANKING) && (word_FFFF8AD6 != 0 || ZRO(word_FFFF8F2A, 2)))
		{
			// loc_25E06

			r2 = 0;
		}
		else
		{
			// loc_25E0C

			r2 = 2;
		};

		// loc_25E0E

		ipw = word_FFFF8A4E;
	}
	else
	{
		// loc_25120

		if (crankHT_x_4us_3 < Rev_Limit_Sensor_Error_1576)
		{
			SET(RPM_FLAGS, REVLIM);
		}
		else
		{
			CLR(RPM_FLAGS, REVLIM);
		};
		
		// loc_25142

		u32 r13 = Add_Lim_FFFF(manifold_SumCount, manifold_SumCount_prev);

		if (r13 != 0)
		{
			Manifold_AbsPressure_ADC8bit_x256_avrg = Div_DW(Add_R4w_R5w(manifold_Sum, manifold_Sum_prev) << 8, r13);

			Manifold_AbsPressure_ADC8bit_avrg = Manifold_AbsPressure_ADC8bit_x256_avrg >> 8;
		};

		// loc_25192

		manifold_SumCount_prev = manifold_SumCount;

		manifold_SumCount = 0;

		manifold_Sum_prev = manifold_Sum;

		manifold_Sum = 0;

		if (RPM_FLAGS & MAP_error)
		{
			// loc_251BA
	
			Manifold_ADC8bit_1 = wMUT1A_Manifold_AbsPressure_ADC8bit;
			Manifold_ADC8bit_2 = Manifold_ADC8bit_1;
			Manifold_ADC8bit_3 = Manifold_ADC8bit_1;
			Manifold_ADC8bit_4 = Manifold_ADC8bit_1;

			Manifold_AbsPressure_ADC8bit_x256_avrg = (Manifold_AbsPressure_ADC8bit_avrg = load_vs_tps) << 8;
		};

		// loc_252C0

		if (load_FFFF8976 < baro_FFFF8B10 && word_FFFF86F4 == 0 && ABSDIF(wMUT1A_Manifold_AbsPressure_ADC8bit, Manifold_ADC8bit_1) >= word_2AB2/*2*/)
		{
			u32 r2;

			if (wMUT1A_Manifold_AbsPressure_ADC8bit >= Manifold_ADC8bit_1)
			{
				r2 = Add_Lim_FFFF(Manifold_AbsPressure_ADC8bit_x256_avrg, Mul_Div((wMUT1A_Manifold_AbsPressure_ADC8bit - Manifold_ADC8bit_1) << 8 , word_2542/*122*/, 32));
			}
			else
			{
				// loc_25368

				r2 = Sub_Lim_0(Manifold_AbsPressure_ADC8bit_x256_avrg, Mul_Div((Manifold_ADC8bit_1 - wMUT1A_Manifold_AbsPressure_ADC8bit) << 8 , word_2544/*122*/, 32));
			};

			// loc_2539A

			MAFSxMAF_MULTIPLIER_1_FFFF89A8 = Lim16(r2, word_254A << 8,  wMUT15_Barometric_Pressure << 8);
		}
		else
		{
			// loc_253C0

			MAFSxMAF_MULTIPLIER_1_FFFF89A8 = Manifold_AbsPressure_ADC8bit_x256_avrg;
		};

		// loc_253C8

		if (wMUT1A_Manifold_AbsPressure_ADC8bit >= Manifold_ADC8bit_4)
		{
			r13 = wMUT1A_Manifold_AbsPressure_ADC8bit - Manifold_ADC8bit_4;

			if (MAX_MAP_FALL_CHANGE < r13)
			{
				MAX_MAP_FALL_CHANGE = r13;
			};
		}
		else
		{
			// loc_253F6

			r13 = Manifold_ADC8bit_4 - wMUT1A_Manifold_AbsPressure_ADC8bit;

			if (MAX_MAP_RISE_CHANGE < r13)
			{
				MAX_MAP_RISE_CHANGE = r13;
			};
		};

		// loc_25414

		manifold_FFFF8988 = wMUT1A_Manifold_AbsPressure_ADC8bit;
		manifold_FFFF898E = Manifold_ADC8bit_4;

		bool c = true;

		if (wMUTC0_bMUT54_Acceleration_Enrichment != 0)
		{
			if (wMUTC0_bMUT54_Acceleration_Enrichment > word_1672)
			{
				r13 = Mul_Fix8_Lim_FFFF(wMUTC0_bMUT54_Acceleration_Enrichment, enrichCoolTemp);

				wMUTC0_bMUT54_Acceleration_Enrichment = (r13 >= word_1672) ? r13 : word_1672;
			}
			else if (word_FFFF8B2C == 0)
			{
				wMUTC0_bMUT54_Acceleration_Enrichment = Mul_Fix8_Lim_FFFF(wMUTC0_bMUT54_Acceleration_Enrichment, word_1674);
			}
			else
			{
				// loc_25492

				c = false;
			};
		};

		// loc_25494

		if (c && wMUT10_Coolant_Temperature_Scaled < word_167A)
		{
			word_FFFF8B2C = word_1678;
		};

		// loc_254AE

		if(word_FFFF8B2C != 0)
		{
			word_FFFF8B2C -= 1;
		};

		if(word_FFFF8B30 != 0)
		{
			word_FFFF8B30 -= 1;
		};

		// loc_254CE

		c = true;

		if (wMUTC1_bMUT55_Deceleration_Enleanment != 0)
		{
			if (wMUTC1_bMUT55_Deceleration_Enleanment > word_168C)
			{
				r13 = Mul_Fix8_Lim_FFFF(wMUTC1_bMUT55_Deceleration_Enleanment, word_FFFF8B1C);

				wMUTC1_bMUT55_Deceleration_Enleanment = (r13 >= word_168C) ? r13 : word_168C;
			}
			else if (word_FFFF8B2E == 0)
			{
				wMUTC1_bMUT55_Deceleration_Enleanment = Mul_Fix8_Lim_FFFF(wMUTC1_bMUT55_Deceleration_Enleanment, word_168E);
			}
			else
			{
				// loc_2553C

				c = false;
			};
		};

		// loc_2553E

		if (c && wMUT10_Coolant_Temperature_Scaled < word_1690)
		{
			word_FFFF8B2E = word_1692;
		};

		// loc_255F4

		if(word_FFFF8B2E != 0)
		{
			word_FFFF8B2E -= 1;
		};

		// loc_25604

		if ((RPM_FLAGS & (STALL|MAP_error|CRANKING)) || cranking_end_timer_up < word_1664)
		{
			wMUTC0_bMUT54_Acceleration_Enrichment = 0;
			wMUTC1_bMUT55_Deceleration_Enleanment = 0;
		}
		else if (PEDR_LO_Check_sub_A790() || (RPM_FLAGS & (REVLIM|FUEL_CUT)) || (FUEL_CUT_FLAG_FFFF8A5E & 0x40))
		{
			wMUTC0_bMUT54_Acceleration_Enrichment = 0;
		}
		else if (manifold_FFFF8988 < manifold_FFFF898E)
		{
			u32 r2 = Sub_Lim_0(manifold_FFFF898E, manifold_FFFF8988);

			if (r2 >= word_FFFF8B2A)
			{
				word_FFFF8B2A = r2;
			};

			u32 r13 = (wMUT10_Coolant_Temperature_Scaled >= word_167E && wMUT10_Coolant_Temperature_Scaled < word_1680 && word_FFFF86B8 != 0) ? word_166A : ((word_FFFF855A != 0) ? word_1666 : word_1668);

			// loc_25798

			if (r2 > r13)
			{
				r2 <<= 1;

				if (r2 >= 0xFF)
				{
					r2 = 0xFF;
				};

				// loc_257B0

				if (r2 >= wMUTC1_bMUT55_Deceleration_Enleanment)
				{
					wMUTC1_bMUT55_Deceleration_Enleanment = r2;
				};

				wMUTC0_bMUT54_Acceleration_Enrichment = 0;
			};
		}
		else // (manifold_FFFF8988 < manifold_FFFF898E)
		{
			u32 r2 = Sub_Lim_0(manifold_FFFF8988, manifold_FFFF898E);

			if (r2 >= word_FFFF8B28)
			{
				word_FFFF8B28 = r2;
			};

			u32 r13 = (wMUT10_Coolant_Temperature_Scaled >= word_167E && wMUT10_Coolant_Temperature_Scaled < word_1680 && word_FFFF86BA != 0) ? word_1684 : word_FFFF8B20;

			// loc_256C0

			if (r2 > r13)
			{
				if (wMUT10_Coolant_Temperature_Scaled >= word_167C)
				{
					if (wMUTC0_bMUT54_Acceleration_Enrichment == 0)
					{
						word_FFFF8B30 = word_1676;
					};

					if (word_FFFF8B30 != 0)
					{
						r2 = Mul_Div(r2, word_FFFF8B38, 32);

						if (r2 >= word_FFFF8B28)
						{
							word_FFFF8B28 = r2;
						};
					};
				};

				// loc_25714

				r2 <<= 2;

				if (r2 >= 0xFF)
				{
					r2 = 0xFF;
				};

				// loc_257B0

				if (r2 >= wMUTC0_bMUT54_Acceleration_Enrichment)
				{
					wMUTC0_bMUT54_Acceleration_Enrichment = r2;
				};

				wMUTC1_bMUT55_Deceleration_Enleanment = 0;
			};
		};

		// loc_257CA

		ipw_Enrichment = (wMUTC0_bMUT54_Acceleration_Enrichment != 0) ? Lim_FFFF(Mul_DW_Div(dword_FFFF8B14, wMUTC0_bMUT54_Acceleration_Enrichment, 2048)) : 0;

		ipw_Enleanment = (wMUTC1_bMUT55_Deceleration_Enleanment != 0) ? Mul_Div(wMUTC1_bMUT55_Deceleration_Enleanment, word_FFFF8B18, 2048) : 0;

		// loc_25826

		Manifold_ADC8bit_4 = Manifold_ADC8bit_3;
		Manifold_ADC8bit_3 = Manifold_ADC8bit_2;
		Manifold_ADC8bit_2 = Manifold_ADC8bit_1;
		Manifold_ADC8bit_1 = wMUT1A_Manifold_AbsPressure_ADC8bit;

		if (FLAGS_FFFF8EB0 & 0x80)
		{
			ipw_Enrichment = 0;
			ipw_Enleanment = 0;
		};

		if (PEDR_LO_Check_sub_A790() || (RPM_FLAGS & STALL))
		{
			// loc_25914

			ipw = 0;

			sub_2640E(0);
		}
		else if (RPM_FLAGS & (REVLIM|FUEL_CUT))
		{
			// loc_25940

			ipw = 0;

			if (byte_1090/*0*/ != 0)
			{
				// loc_259D4

				u32 r13 = word_FFFF8B82;
				u32 r3 = word_FFFF8B90;

				word_FFFF8B98 = 0;
				
				if (word_FFFF8AF2 != 0 || word_FFFF86F2 != 0)
				{
					r3 = 0;
					r13 = 0;
				};

				r2 = word_FFFF8B74;

				word_FFFF8B9A = Interpolate_256(0, Interpolate_256(r13, r3, word_FFFF8B76), r2);

				word_FFFF8B9C = 0;
				word_FFFF8B88 = word_FFFF8B86;
				word_FFFF8B86 = word_FFFF8B84;
				word_FFFF8B84 = word_FFFF8B82;
				word_FFFF8B82 = word_FFFF8B80;
				word_FFFF8B80 = word_FFFF8B7E;
				word_FFFF8B7E = word_FFFF8B7C;

				word_FFFF8B7C = Interpolate_256(0, r13, word_FFFF8B78);

				word_FFFF8B96 = word_FFFF8B94;
				word_FFFF8B94 = word_FFFF8B92;
				word_FFFF8B92 =	word_FFFF8B90;
				word_FFFF8B90 =	word_FFFF8B8E;
				word_FFFF8B8E =	word_FFFF8B8C;
				word_FFFF8B8C = word_FFFF8B8A;

				word_FFFF8B8A = Interpolate_256(0, r3, word_FFFF8B7A);
			}
			else
			{
				// loc_25954

				if (word_FFFF8B7C > word_2972 && word_FFFF8B8A > word_2974)
				{
					sub_2640E(0);
				}
				else
				{
					word_FFFF8B88 = 0;
					word_FFFF8B86 = 0;
					word_FFFF8B84 = 0;
					word_FFFF8B82 = 0;
					word_FFFF8B80 = 0;
					word_FFFF8B7E = 0;
					word_FFFF8B7C = 0;
					word_FFFF8B96 = 0;
					word_FFFF8B94 = 0;
					word_FFFF8B92 = 0;
					word_FFFF8B90 = 0;
					word_FFFF8B8E = 0;
					word_FFFF8B8C = 0;
					word_FFFF8B8A = 0;

					word_FFFF8B9C = 0;
					word_FFFF8B9A = 0;
					word_FFFF8B98 = 0;
				};
			};
		}
		else if (RPM_FLAGS & CRANKING)
		{
			ipw = word_FFFF8AFE;

			word_FFFF8B88 = ipw;
			word_FFFF8B86 = ipw; 
			word_FFFF8B84 = ipw; 
			word_FFFF8B82 = ipw; 
			word_FFFF8B80 = ipw; 
			word_FFFF8B7E = ipw; 
			word_FFFF8B7C = ipw; 
			word_FFFF8B96 = ipw; 
			word_FFFF8B94 = ipw; 
			word_FFFF8B92 = ipw; 
			word_FFFF8B90 = ipw; 
			word_FFFF8B8E = ipw; 
			word_FFFF8B8C = ipw; 
			word_FFFF8B8A = ipw; 
			word_FFFF8B9C = ipw; 
			word_FFFF8B9A = ipw; 
			word_FFFF8B98 = ipw;

			Table_Lookup_Axis(CEL8_7974);

			word_FFFF86F2 = Table_Lookup_byte_2D_3D(unk100_62FC);

			word_FFFF86F0 = Table_Lookup_byte_2D_3D(unk112_5240);

			word_FFFF8AF2 = 4;
		}
		else
		{
			// loc_25B36

			if (wMUTC0_bMUT54_Acceleration_Enrichment != 0 || wMUTC1_bMUT55_Deceleration_Enleanment != 0);

			r2 = MAFSxMAF_MULTIPLIER_1_FFFF89A8;

			u32 r0 = SHLR8(wMUT0F_Oxygen_Feedback_Trim) << 1;

			r0 += wMUT52_COPY + wMUT50_Long_Fuel_Trim_Bank_1_COPY;

			r0 = Mul_Div(MUTC7_copy, r0, 512);

			r0 = Mul_Div(r0, r2, 0x4000);

			word_FFFF9956 = ipw = sub_2640E(r0);

			if (ipw_Enrichment != 0)
			{
				ipw = Add_Lim_FFFF(ipw, ipw_Enrichment);
			};

			if (ipw_Enleanment != 0)
			{
				ipw = Sub_Lim_0(ipw, ipw_Enleanment);

				if (ipw == 0)
				{
					ipw = 1;
				};
			};
		};

		// loc_25BCC

		if (FUEL_CUT_FLAG_FFFF8A5E & 0x40)
		{
			if (byte_35B7[word_FFFF8AD0] == 0)
			{
				ipw = 0;
			};

			INCLIM(word_FFFF8AD0);

			if (word_FFFF8AD0 >= 4)
			{
				word_FFFF8AD0 = 0;
			};
		}
		else
		{
			word_FFFF8AD0 = 0;
		};

		INCLIM(word_FFFF8F30);

		if (word_FFFF8F30 >= 2)
		{
			word_FFFF8F30 = 0;
		};

		if (word_FFFF8F2A & 2)
		{
			word_FFFF8F30 = 1;
		};

		if (RPM_FLAGS & CRANKING_TIMED)
		{
			r2 = 3;

			ipw = word_FFFF8BAE;

			DECLIM(word_FFFF8BAA);

			if (word_FFFF8BAA == 0)
			{
				CLR(RPM_FLAGS, CRANKING_TIMED);
			};
		}
		else if (RPM_FLAGS & CRANKING_TIMED)
		{
			r2 = 2;

			ipw = word_FFFF8BAE;

			DECLIM(word_FFFF8BAA)

			if (word_FFFF8BAA == 0)
			{
				CLR(RPM_FLAGS, CRANKING_TIMED);
			};
		}
		else if ((FUEL_CUT_FLAG_FFFF8A5E & 0x80) && (RPM_FLAGS & CRANKING) && (word_FFFF8AD6 != 0 || ZRO(word_FFFF8F2A, 2)))
		{
			r2 = 0;
		}
		else if (RPM_FLAGS & 0x8000)
		{
			r2 = 2;
		}
		else if ((word_FFFF8F2A & 2) || (word_FFFF8F2A & 6))
		{
			r2 = 1;
		}
		else 
		{
			r2 = 2;

			ipw = Div_R4_R5__R0(ipw , 4);
		};

		// loc_25DCE

		if (word_FFFF8AD6 != 0)
		{
			word_FFFF8AD6 -= 1;
		};

		word_FFFF8A4E = ipw;
	};

	// loc_25E12

	if (r2 != 0 && ipw != 0)
	{
		// loc_25E26

		r9 = 0;

		if (MUT21_RPM_x125div4 <= rpm_1508/*255(7968)*/)
		{
			r9 = word_1504/*5*/ << 5;
		};

		bMUTC5_InjPulseW_8us = injPulseWidth_null = ipw = Lim16(INJECTOR_RESCALED_sub_26174(ipw), 65000, r9);

		wMUT2A_Injector_Pulse_Width_us = Mul_Lim_FFFF(ipw, 8);

		if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 4) && (word_FFFF929A == 6 || word_FFFF929A == 9))
		{
			// loc_25E82

			word_FFFF929A += 1;
		};

		// loc_25E8A

		bMUTC6_FFFF8A52 = ipw;

		MUT_2B_FFFF9996 = Mul_Lim_FFFF(ipw, 8);

		if (r2 == 1)
		{
			if (ZRO(word_FFFF8B4E, 0x80))
			{
				// loc_25F98

				r2 = word_98D4[strokeNumber+1];

				if (word_FFFF8B4E & 0x40)
				{
					r2 |= word_98D4[strokeNumber];
				};

			}
			else if (ZRO(word_FFFF8B4E, 0x40))
			{
				r2 = 0;
			}
			else
			{
				// loc_25EC0

				u32 r13 = 3;

				if (strokeNumber != 0)
				{
					r13 = Sub_Lim_0(strokeNumber, 1);
				};

				if ((wMUT1E_MAF_RESET_FLAG & CRANKING) && (word_FFFF8A48 & 0x80) && ZRO(word_FFFF8B4E, 0x20) && ZRO(word_FFFF89F2, 0x400) && ZRO(word_FFFF89F2, 0x800))
				{
					SET(word_FFFF89F2, 0x800);

					r2 = word_98D4[r13];
				}
				else
				{
					// loc_25F88
					r2 = word_98D4[strokeNumber];
				};
			};

		}
		else if (r2 == 3)
		{
			if (ZRO(BOOSTCHECK2_FFFF8A0E, 0x40) && ZRO(word_FFFF89F2, 0x400))
			{
				SET(word_FFFF89F2, 0x400);
				word_FFFF8F28 ^= 1;
			};

			// loc_25FEA

			r2 = word_98E6[word_FFFF8F28];
			word_FFFF8F28 ^= 1;
		}
		else
		{
			// loc_26002
			r2 = 0xF;
		};

		// loc_26004

		CLR(word_FFFF8B4E, 0x40);

		if ((word_FFFF8A48 & 0x80) && v1 == 0)
		{
			StartInjectSync(ipw, r2);

			r9 = 0;
		}
		else
		{
			// inj_async_2602C
			StartInjectAsync(ipw, r2);

			r9 = 1;
		};

		// loc_26038

		ipw = 0;

		for (u32 r1 = 1; r1 <= 8; r1 <<= 1)
		{
			if (r2 & r1)
			{
				ipw += 1;
			};
		};

		dword_FFFF8B68 = Add_Lim_FFFFFFFF(dword_FFFF8B68, Mul16(ipw, word_FFFF8A4E) << 1);
	}
	else
	{
		// loc_2607E
		injPulseWidth_null = 0;
	};

	// loc_26084

	if (r9 != 0)
	{
		CRANK_sub_262D0();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK75_sub_260B8()
{
	strokeNumber += 1;

	if (strokeNumber >= 4)
	{
		strokeNumber = 0;
	};

	if (word_FFFF8F2A & 1)
	{
		SET(word_FFFF8F2A, 6);

		word_FFFF8F2E = 5;

		word_FFFF8F2E -= 1;
	}
	else
	{
		if (ZRO(word_FFFF8F2A, 4))
		{
			strokeNumber = ((camshaft_Shift & 3) - 1) & 3;

			SET(word_FFFF8F2A, 2);

			word_FFFF8F2E = 5;
		};

		DECLIM(word_FFFF8F2E);
	};
	
	if (word_FFFF8F2E == 0)
	{
		CLR(word_FFFF8F2A, 2);
		SET(word_FFFF8F2A, 4);
	};

	if (word_FFFF8F2A & 1)
	{
		strokeNumber = stroke_FFFF8F22;
	};

	DECLIM(word_FFFF8DE6);

	if ((camshaft_Shift & 3) == 1)
	{
		word_FFFF8DE6 = word_1C22/*8*/;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK_sub_262D0()
{
	u32 r1 = atu22_Get_DSTR_0x3C00();

	u32 r13 = Reset_IRQ0F();

	if ((word_FFFF8DF2 ^ r1) & word_FFFF8DF2 & word_FFFF8DF4)
	{
		if (r13 != 0)
		{
			CLR(wMUT72_Knock_Present, 2);

			word_FFFF8DF4 <<= 1;
		}	
		else
		{
			SET(wMUT72_Knock_Present, 2);

			word_FFFF922E = word_FFFF8DF4;
		};
	};

	if (ZRO(word_FFFF8DF4, 0xF))
	{
		word_FFFF8DF4 = 1;
	};

	word_FFFF8DF2 = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK75_sub_2941C()
{
	CRANK75_sub_2B168();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK75_sub_2B168()
{
	CLR(word_FFFF8F7A, 0xC);

	word_FFFF9990 = 0xFFFF;

	u32 r13 = word_FFFF8C62;

	if (MUT21_RPM_x125div4 >= word_182E/*0*/ || wMUT14_Battery_Level_ADC8bit < word_1834/*109*/ || wMUT14_Battery_Level_ADC8bit >= word_1832/*245*/)
	{
		return;
	};

	if (r13 == 0xFF || r13 == 0 || (flags_FFFF8FFC & 8) || ZRO(misfire_word_FFFF8F7C, 0x10) || ZRO(bMUTD3_BitMap4_FCA_Store_FFFF89D8, 0x20))
	{
		return;
	};

	r13 = word_FFFF8C62 & 3;

	if (r13 != 3 && r13 != 0)
	{
		return;
	};

	SET(word_FFFF8F7A, 8);

	r13 = word_FFFF8C62 & 7;

	if (r13 == 7 || r13 == 0)
	{
		SET(word_FFFF8F7A, 4);
	};

	word_FFFF9990 = stroke_FFFF8F22 << 4;

	if (ZRO(word_FFFF8F7A, 0x8000))
	{
		SET(word_FFFF8F7A, 0x4000);
	};

	if (ZRO(word_FFFF8F7A, 0x2000))
	{
		SET(word_FFFF8F7A, 0x1000);
	};

	SET(word_FFFF8F7A, 0xA000);

	u16 **p = &ENGINE_MAIN_VARIABLES_DIM_off_9198->_1064_word_FFFF901E;

	u16 *r2 = p[stroke_FFFF8F22];

	p = &ENGINE_MAIN_VARIABLES_DIM_off_9198->_1144_word_FFFF9036;

	u16 *r1 = p[stroke_FFFF8F22];

	*r2 += 1;

	if (*r2 == 0) { *r2 -= 1; };

	*r1 += 1;

	if (*r1 == 0) { *r1 -= 1; };
}	

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Update_Gen_G_output()
{
	__disable_irq();

	if (ZRO(KNOCK_FLAG2_FFFF887A, 1))
	{
		SET(reg_PFDRL, 0x80);
	}
	else
	{
		CLR(reg_PFDRL, 0x80);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SetIgnCoilChargeStartTime(u16 mask, u16 v)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SetIgnSparkStartTime(u16 mask, u16 v)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void StartInjectSync(u16 v, u16 mask)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void StartInjectAsync(u16 v, u16 mask)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void InjOpenStart(u16 v, u16 mask)
{
	__disable_irq();

	if (v != 0)
	{
		u32 r13 = 0xFFFFFFFF + v;

		if (mask & 1) 	{	reg_DCNT8K = r13; 	};
		if (mask & 2) 	{	reg_DCNT8L = r13; 	};
		if (mask & 4) 	{	reg_DCNT8M = r13; 	};
		if (mask & 8) 	{	reg_DCNT8N = r13; 	};
		if (mask & 16) 	{	reg_DCNT8O = r13; 	};
		if (mask & 32) 	{	reg_DCNT8P = r13; 	};

		SET(reg_DSTR, (mask & 63) << 10);
	};
	
	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

u16 atu22_Get_ECNT9A()
{
	__disable_irq();

	u32 r1 = reg_ECNT9A;

	reg_ECNT9A = 0;

	if (reg_TSR9 & 1)
	{
		r1 = 0xFF;

		CLR(reg_TSR9, 1);
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

u16 INJECTOR_RESCALED_sub_26174(u16 v)
{
	if (v <= 260)
	{
		v = Add_Lim_FFFF(v, Div_R4_R5__R0(byte_342F[v>>2], 2));
	};

	// loc_261AC

	return Add_Lim_FFFF(v, injectorLatencyRescaled);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 sub_2640E(u16 v)
{
	u32 r9 = word_FFFF8B82;
	u32 r8 = word_FFFF8B90;

	word_FFFF8B98 = v;

	if (word_FFFF8AF2 != 0 || word_FFFF86F2 != 0)
	{
		r8 = v;
		r9 = v;
	};

	u32 r13 = Interpolate_256(v, Interpolate_256(r9, r8, word_FFFF8B76), word_FFFF8B74);

	u32 r2 = v;

	word_FFFF8B9A = r13;

	if (v >= r13)
	{
		word_FFFF8BA2 = Sub_Lim_0(r2, r13);

		word_FFFF8BA4 = Mul_Div_R(Mul_R4_R5_Div_128_Into_R0(word_FFFF8BA2, word_FFFF8B9E), 256, word_FFFF8B74);

		r2 = Add_Lim_FFFF(r2, word_FFFF8BA4);
	}
	else
	{
		// loc_264C6

		word_FFFF8BA2 = Sub_Lim_0(r13, r2);

		if (word_FFFF86F0 != 0)
		{
			word_FFFF8BA0 = 0;
		};

		word_FFFF8BA4 = Mul_Div_R(Mul_R4_R5_Div_128_Into_R0(word_FFFF8BA2, word_FFFF8BA0), 256, word_FFFF8B74);

		r2 = Sub_Lim_0(v, word_FFFF8BA4);

		if (r2 == 0)
		{
			r2 = 1;
		};
	};

	// loc_26526

	word_FFFF8B9C = r2;

	word_FFFF8B88 = word_FFFF8B86;
	word_FFFF8B86 = word_FFFF8B84;
	word_FFFF8B84 = word_FFFF8B82;
	word_FFFF8B82 = word_FFFF8B80;
	word_FFFF8B80 = word_FFFF8B7E;
	word_FFFF8B7E = word_FFFF8B7C;

	word_FFFF8B7C = Interpolate_256(r2, r9, word_FFFF8B78);

	word_FFFF8B96 = word_FFFF8B94;
	word_FFFF8B94 = word_FFFF8B92;
	word_FFFF8B92 =	word_FFFF8B90;
	word_FFFF8B90 =	word_FFFF8B8E;
	word_FFFF8B8E =	word_FFFF8B8C;
	word_FFFF8B8C = word_FFFF8B8A;

	word_FFFF8B8A = Interpolate_256(r2, r8, word_FFFF8B7A);

	if (cranking_end_timer_up >= word_22A2 && ONE(BOOSTCHECK2_FFFF8A0E, 0x400) && word_FFFF8BA2 >= word_2970 && ZRO(FLAGS_FFFF8EB0, 0x80))
	{
		v = r2;
	};

	if (word_FFFF8AF2 != 0)
	{
		word_FFFF8AF2 -= 1;
	};

	return v;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_21A04()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_29438()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_29558()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_29750()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_2A684()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_2AAA2()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_2AC5C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_2AEE4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_C990(u16 v)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


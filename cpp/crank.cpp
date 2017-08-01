#pragma section _crank

#include <machine.h>
#include <umachine.h>

#include "misc.h"
#include "hwreg.h"

#include "constbyte.h"
#include "constword.h"
#include "ram.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define Get_ADC_Knock				((void(*)(void))0xA92C)
#define INJECTOR_RESCALED_sub_26174	((u16(*)(u16))0x26174)
//#define CRANK75_Knock_sub_24AC0		((void(*)(void))0x24AC0)

//#define crankPrevICR0AH_A       (*(u32*)0xFFFF9AB8)
//
//#define ici0A_TCNT2A           	(*(u16*)0xFFFF9AC0)
//#define crank_ICR0AH_250ns     	(*(u32*)0xFFFF9AC4)
//#define crank_OSBR2_4us        	(*(u16*)0xFFFF9AC8)
//#define crank_Flags            	(*(u16*)0xFFFF9ACA)
//
//
//
//#define	crankHT_x_4us_4        	(*(u16*)0xFFFF8F06)        //Время полуоборота коленвала                
//#define	null_CrankHT_x_4us_2   	(*(u16*)0xFFFF8F08)                                                     
//#define	null_CrankHT_x_4us_1   	(*(u16*)0xFFFF8F0A)                                                     
//#define	null_crank_dt_ICR0AH_A 	(*(u32*)0xFFFF8F0C)                                                     
//#define	crank_dt_ICR0AH_B      	(*(u32*)0xFFFF8F10)                                                     
//#define	crankHT_A              	(*(u16*)0xFFFF8F18)                                                     
//#define	crankHT_B              	(*(u16*)0xFFFF8F1A)                                                     
//#define	crankPrevOSBR2_A       	(*(u16*)0xFFFF8F1C)                                                     
//#define	crankPrev_OSBR2_B      	(*(u16*)0xFFFF8F1E)                                                     
//#define	camshaft_Shift         	(*(u16*)0xFFFF8F20)                                                     
//#define	stroke_FFFF8F22        	(*(u16*)0xFFFF8F22)                                                     
//#define	strokeNumber           	(*(u16*)0xFFFF8F24)                                                     
//#define	stroke_FFFF8F26        	(*(u16*)0xFFFF8F26)                                                     
//#define	word_FFFF8F28          	(*(u16*)0xFFFF8F28)                                                     
//#define	word_FFFF8F2A          	(*(u16*)0xFFFF8F2A)                                                     
//#define	word_FFFF8F2C          	(*(u16*)0xFFFF8F2C)                                                     
//#define	word_FFFF8F2E          	(*(u16*)0xFFFF8F2E)                                                     
//#define	word_FFFF8F30          	(*(u16*)0xFFFF8F30)                                                     
//#define	word_FFFF8F32          	(*(u16*)0xFFFF8F32)                                                     
//#define	word_FFFF8F34          	(*(u16*)0xFFFF8F34)                                                     
//
//#define	timer_up_FFFF8522      	(*(u16*)0xFFFF8522)                                                     
//#define	timer_up_FFFF8524      	(*(u16*)0xFFFF8524)                                                     
//
//#define	word_FFFF886E          	(*(u16*)0xFFFF886E)                                                     
//#define	word_FFFF8870			(*(u16*)0xFFFF8870)                                                     
//

#define	word_98BA				((const u16*)0x98BA)                                                     
#define	word_98C4				((const u16*)0x98C4)                                                     
#define	word_98CC				((const u16*)0x98CC)                                                     
#define	word_98E6				((const u16*)0x98E6)                                                     
#define	word_98D4				((const u16*)0x98D4)                                                     

#define	word_98C2				(*(const u16*)0x98BA)                                                     


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool CRANK_CheckCamshaft_sub_A7C0();

static void CRANK5_root_sub_DC18(u16 osbr, u32 icr);
static void CRANK75_root_sub_DB40(u16 osbr, u32 icr);

static void SetIgnCoilChargeStartTime(u16 mask, u16 v);
static void SetIgnSparkStartTime(u16 mask, u16 v);
static void StartInjectSync(u16 mask, u16 v);
static void StartInjectAsync(u16 mask, u16 v);

static void CRANK75_sub_232A0();
static void CRANK75_Knock_sub_23F8C();
static bool CRANK75_sub_24636();

static void CRANK75_sub_2467E();
static void CRANK75_MainUpdateTiming();
static u16 CRANK75_FiltrCrankHT_2494E(u16 v1, u16 v2);
static u16 CRANK75_Get_IgnCoilTime(u16 v);
static void CRANK75_Knock_sub_24AC0();
static void CRANK5_sub_24AF0();
static void CRANK5_sub_2504A();
static void CRANK5_sub_2506E();
static void CRANK5_SetIgnCoilTime_Fin();
static void CRANK_MAF_MAP_Calcs_sub_250F8(u16 v1, u16 v2);
static void CRANK75_sub_260B8();
static void CRANK_sub_262D0();


static void atu22_IMF2G_event();
static void atu22_CMF2G_event();
static void ClearTSR_2E_2F_2G(u16 v);
static bool Check_PEDRL_4();
static bool Check_PEDRL_1();

static void Ign_handler(u16 v);
static u16 Get_2E_2F_2G_status();

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

static void CRANK5_root_sub_DC18(u16 osbr, u32 icr)
{

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


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool CRANK75_sub_24636()
{
	u32 r1 = (crankHT_x_4us >= crankHT_x_4us_2) ? (crankHT_x_4us - crankHT_x_4us_2) : (crankHT_x_4us_2 - crankHT_x_4us);

	return r1 >= Mul_Fix8_Lim_FFFF(crankHT_x_4us, word_1792/*0.125*256*/);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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
	u32 r2, r8, r9 = 0, r1 = v1;

	if (v1 == 1)
	{
		// async_25DE6

		if ((FUEL_CUT_FLAG_FFFF8A5E & 0x80) && (RPM_FLAGS & 1) && (word_FFFF8AD6 != 0 || (word_FFFF8F2A & 2) == 0))
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

		r8 = word_FFFF8A4E;
	}
	else
	{
		// loc_25120
	};


	// loc_25E12

	if (r2 != 0 && r8 != 0)
	{
		// loc_25E26

		r9 = 0;

		if (MUT21_RPM_x125div4 <= rpm_1508/*255(7968)*/)
		{
			r9 = word_1504/*5*/ << 5;
		};

		bMUTC5_InjPulseW_8us = injPulseWidth_null = r8 = Lim16(INJECTOR_RESCALED_sub_26174(r8), 65000, r9);

		wMUT2A_Injector_Pulse_Width_us = Mul_Lim_FFFF(r8, 8);

		if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 4) && (word_FFFF929A == 6 || word_FFFF929A == 9))
		{
			// loc_25E82

			word_FFFF929A += 1;
		};

		// loc_25E8A

		bMUTC6_FFFF8A52 = r8;

		MUT_2B_FFFF9996 = Mul_Lim_FFFF(r8, 8);

		if (r2 == 1)
		{
			if ((word_FFFF8B4E & 0x80) == 0)
			{
				// loc_25F98

			}
			else if ((word_FFFF8B4E & 0x40) == 0)
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

				if ((wMUT1E_MAF_RESET_FLAG & CRANKING) && (word_FFFF8A48 & 0x80) && (word_FFFF8B4E & 0x20) == 0 && (word_FFFF89F2 & 0x400) == 0 && (word_FFFF89F2 & 0x800) == 0)
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
			if ((BOOSTCHECK2_FFFF8A0E & 0x40) == 0 && (word_FFFF89F2 & 0x400) == 0)
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

		if ((word_FFFF8A48 & 0x80) && r1 == 0)
		{
			StartInjectSync(r8, r2);

			r9 = 0;
		}
		else
		{
			// inj_async_2602C
			StartInjectAsync(r8, r2);

			r9 = 1;
		};

		// loc_26038

		r8 = 0;

		for (u32 r1 = 1; r1 <= 8; r1 <<= 1)
		{
			if (r2 & r1)
			{
				r8 += 1;
			};
		};

		dword_FFFF8B68 = Add_Lim_FFFFFFFF(dword_FFFF8B68, Mul16(r8, word_FFFF8A4E) << 1);
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

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK_sub_262D0()
{

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

static void StartInjectSync(u16 mask, u16 v)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void StartInjectAsync(u16 mask, u16 v)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



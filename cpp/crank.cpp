#pragma section _crank

#include <machine.h>
#include <umachine.h>

#include "misc.h"
#include "hwreg.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#define crankPrevICR0AH_A       (*(u32*)0xFFFF9AB8)

#define ici0A_TCNT2A           	(*(u16*)0xFFFF9AC0)
#define crank_ICR0AH_250ns     	(*(u32*)0xFFFF9AC4)
#define crank_OSBR2_4us        	(*(u16*)0xFFFF9AC8)
#define crank_Flags            	(*(u16*)0xFFFF9ACA)



#define	crankHT_x_4us_4        	(*(u16*)0xFFFF8F06)        //Время полуоборота коленвала                
#define	null_CrankHT_x_4us_2   	(*(u16*)0xFFFF8F08)                                                     
#define	null_CrankHT_x_4us_1   	(*(u16*)0xFFFF8F0A)                                                     
#define	null_crank_dt_ICR0AH_A 	(*(u32*)0xFFFF8F0C)                                                     
#define	crank_dt_ICR0AH_B      	(*(u32*)0xFFFF8F10)                                                     
#define	crankHT_A              	(*(u16*)0xFFFF8F18)                                                     
#define	crankHT_B              	(*(u16*)0xFFFF8F1A)                                                     
#define	crankPrevOSBR2_A       	(*(u16*)0xFFFF8F1C)                                                     
#define	crankPrev_OSBR2_B      	(*(u16*)0xFFFF8F1E)                                                     
#define	camshaft_Shift         	(*(u16*)0xFFFF8F20)                                                     
#define	stroke_FFFF8F22        	(*(u16*)0xFFFF8F22)                                                     
#define	strokeNumber           	(*(u16*)0xFFFF8F24)                                                     
#define	stroke_FFFF8F26        	(*(u16*)0xFFFF8F26)                                                     
#define	word_FFFF8F28          	(*(u16*)0xFFFF8F28)                                                     
#define	word_FFFF8F2A          	(*(u16*)0xFFFF8F2A)                                                     
#define	word_FFFF8F2C          	(*(u16*)0xFFFF8F2C)                                                     
#define	word_FFFF8F2E          	(*(u16*)0xFFFF8F2E)                                                     
#define	word_FFFF8F30          	(*(u16*)0xFFFF8F30)                                                     
#define	word_FFFF8F32          	(*(u16*)0xFFFF8F32)                                                     
#define	word_FFFF8F34          	(*(u16*)0xFFFF8F34)                                                     

#define	timer_up_FFFF8522      	(*(u16*)0xFFFF8522)                                                     
#define	timer_up_FFFF8524      	(*(u16*)0xFFFF8524)                                                     

#define	word_FFFF886E          	(*(u16*)0xFFFF886E)                                                     
#define	word_FFFF8870			(*(u16*)0xFFFF8870)                                                     

#define	word_98BA				((const u16*)0x98BA)                                                     

#define	word_98C2				(*(const u16*)0x98BA)                                                     


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void atu22_IMF2G_event();
static void atu22_CMF2G_event();
static void Ign_handler(u16 v);
static void ClearTSR_2E_2F_2G(u16 v);
static void CRANK5_root_sub_DC18(u16 osbr, u32 icr);
static void CRANK75_root_sub_DB40(u16 osbr, u32 icr);
static void CRANK75_sub_232A0();
static bool CRANK_CheckCamshaft_sub_A7C0();
static bool Check_PEDRL_4();


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

static void Ign_handler(u16 v)
{

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
			if (word_FFFF8F2C > 0)
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

	}



	if (Check_PEDRL_4())
	{

	};
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

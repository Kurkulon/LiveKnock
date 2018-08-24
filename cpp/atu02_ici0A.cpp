#pragma section _atu02_ici0A

#include <smachine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"


#pragma interrupt(atu02_ici0A)
#pragma interrupt(atu21_imi2C)
#pragma interrupt(atu21_imi2D)
#pragma interrupt(atu11_imi1A)
#pragma interrupt(atu11_imi1B)
#pragma interrupt(atu11_imi1C)
#pragma interrupt(atu12_imi1E)
#pragma interrupt(atu82_osi8G)
#pragma interrupt(cmti1)
#pragma interrupt(atu11_imi11B)
#pragma interrupt(int_nmi_E9AE)
#pragma interrupt(atu22_imi2G)
#pragma interrupt(atu22_imi2H)


#define Read_Ports_And_Registers_sub_B114				((void(*)(void))0xB114)

extern "C" void atu22_IMF2G_event();


static void CRANK75_root_sub_DB40(u16 osbr, u32 icr);
static void CRANK5_root_sub_DC18(u16 osbr, u32 icr);

extern void CRANK5_Main_sub_24AF0();
extern void CRANK75_Main_sub_232A0();


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu02_ici0A()
{
	__disable_irq();

	ici0A_TCNT2A = reg_TCNT2A;

	CLR(reg_TSR0, 1);

	crank_OSBR2_4us = reg_OSBR2;

	crank_ICR0AH_250ns = reg_ICR0A;

	if ((crank_Flags ^ reg_PADRL) & 1)
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

static void CRANK75_root_sub_DB40(u16 osbr, u32 icr)
{
    if ((osbr - crank_OSBR2_5) >= 254 || timer_up_FFFF8524 >= 40)
	{
		if (timer_up_FFFF8522 >= 39)
		{
			crank_OSBR2_75 = osbr;

			crankPrev_ICR0AH_75 = icr;

			null_crank_dt_ICR0AH_5 = (u32)-1;

			crankHT_75 = (u16)-1;
		}
		else
		{
			crankHT_75 = osbr - crank_OSBR2_75;

			crank_OSBR2_75 = osbr;

			null_crank_dt_ICR0AH_5 = icr - crankPrev_ICR0AH_75;

			crankPrev_ICR0AH_75 = icr;
		};

		timer_up_FFFF8522 = 0;

		__enable_irq();

		CRANK75_Main_sub_232A0();

		word_FFFF886E = reg_TCNT2A - ici0A_TCNT2A;

		__disable_irq();

		CLR(crank_Flags, 1);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_root_sub_DC18(u16 osbr, u32 icr)
{
	if ((osbr - crank_OSBR2_75) >= 162 || timer_up_FFFF8522 >= 40)
	{
		if (timer_up_FFFF8524 >= 39)
		{
			crank_dt_ICR0AH_5 = 0xFFFFFFFF;

			crankHT_5 = 0xFFFF;
		}
		else
		{
			crankHT_5 = osbr - crank_OSBR2_5;

			crank_dt_ICR0AH_5 = icr - crankPrev_ICR0AH_5;
		};

		crank_OSBR2_5 = osbr;

		crankPrev_ICR0AH_5 = icr;

		timer_up_FFFF8524 = 0;

		__enable_irq();

		CRANK5_Main_sub_24AF0();

		word_FFFF8870 = reg_TCNT2A - ici0A_TCNT2A;

		SET(crank_Flags, 1);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool sub_DCB4()
{
	return ZRO(reg_TSR0, 1) && ZRO(crank_Flags, 2) && ZRO(reg_TSR2B, 0x40);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_ATU_Misc_1_sub_DCDC()
{
	__disable_irq();

	word_FFFF9ADA = 0xAE;

	word_FFFF9AE8 = 0;

	ufix8_FFFF9AE0 = 0;

	word_FFFF9AEC = 0;

	word_FFFF9AE4 = 0;

	word_FFFF9AE6 = 0xFFFF;

	ufix8_FFFF9ADE = 0xFFFF;

	word_FFFF9AEA = 0xFFFF;

	word_FFFF9AE2 = 0xFFFF;

	reg_GR2C = reg_TCNT2A + 6250;

	reg_GR2D = reg_TCNT2A + 7000;

	CLR(reg_TSR2A, 0xC);

	reg_TIOR2B = (reg_TIOR2B & ~7) | ((word_FFFF9ADA & 2) ? 1 : 2);

	SET(reg_TIER2A, 4);

	reg_TIOR2B = (reg_TIOR2B & ~0x70) | ((word_FFFF9ADA & 0x20) ? 0x10 : 0x20);

	CLR(reg_TIER2A, 8);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_DE24()
{
	__disable_irq();

	SET(word_FFFF9ADA, 0x22);

	CLR(word_FFFF9ADA, 0x40);

	CLR(reg_TIOR2B, 0xBB);

	SET(reg_TIER2A, 4);

	CLR(reg_TIER2A, 8);
	
	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu21_imi2C()
{
	__disable_irq();

	CLR(reg_TSR2A, 4);

	if (word_FFFF9ADA & 4)
	{
		bool r2 = false;

		SET(reg_PJCRL, 0x10);

		u32 r1;

		if (word_FFFF9ADA & 8)
		{
			if (word_FFFF9AE4 == 0 || word_FFFF9AE4 >= word_FFFF9AE2)
			{
				r1 = word_FFFF9AE2 - ((u32)word_FFFF9AE2 >> 1);
			}
			else
			{
				r1 = word_FFFF9AE2 - word_FFFF9AE4;
			};

			word_FFFF9AE4 = ufix8_FFFF9AE0;

			word_FFFF9AE2 = ufix8_FFFF9ADE;

			if (word_FFFF9AE4 != 0)
			{
				r2 = true;
			};
		}
		else
		{
			// loc_DF12

			SET(word_FFFF9ADA, 1);

			word_FFFF9AE4 = ufix8_FFFF9AE0;

			word_FFFF9AE2 = ufix8_FFFF9ADE;

			r1 = word_FFFF9AE4;

			if (word_FFFF9AE4 == 0 || (r2 = word_FFFF9AE4 >= word_FFFF9AE2))
			{
				r1 = (u32)word_FFFF9AE2 >> 1;
			};
			//else if (word_FFFF9AE4 >= word_FFFF9AE2)
			//{
			//	r2 = true;

			//	r1 = (u32)word_FFFF9AE2 >> 1;
			//};

		};

		// loc_DF4C

		if (r1 < 500)
		{
			u32 r13 = reg_GR2C + r1;
			u32 r10 = reg_TCNT2A + 2;

			if ((r13 - r10) & 0x8000)
			{
				r13 = r10;
			};

			reg_GR2C = r13;
		}
		else
		{
			reg_GR2C += r1;
		};

		// loc_DFAE

		if (ZRO(word_FFFF9ADA, 2))
		{
			r2 = !r2;
		};

		// loc_DFC4

		reg_TIOR2B = (reg_TIOR2B & ~7) | ((r2) ? 2 : 1);

		// loc_DFE8

		NOT(word_FFFF9ADA, 8);
	}
	else
	{
		// loc_E00A

		CLR(reg_PJCRL, 0x10);

		reg_GR2C += word_FFFF9AE2;

		SET(word_FFFF9ADA, 8);
		CLR(word_FFFF9ADA, 1);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu21_imi2D()
{
	__disable_irq();

	CLR(reg_TSR2A, 8);

	if (word_FFFF9ADA & 0x40)
	{
		bool r2 = false;

		SET(reg_PJCRL, 0x40);

		u32 r1;

		if (word_FFFF9ADA & 0x80)
		{
			if (word_FFFF9AEC == 0 || word_FFFF9AEC >= word_FFFF9AEA)
			{
				r1 = word_FFFF9AEA - ((u32)word_FFFF9AEA >> 1);
			}
			else
			{
				r1 = word_FFFF9AEA - word_FFFF9AEC;
			};

			word_FFFF9AEC = word_FFFF9AE8;

			word_FFFF9AEA = word_FFFF9AE6;

			if (word_FFFF9AEC != 0)
			{
				r2 = true;
			};
		}
		else
		{
			// loc_E116

			SET(word_FFFF9ADA, 0x10);

			if ((word_FFFF9AE8 != 0 && word_FFFF9AEC != 0) || (word_FFFF9AE8 == 0 && word_FFFF9AEC == 0))
			{
				word_FFFF9AEC = word_FFFF9AE8;

				word_FFFF9AEA = word_FFFF9AE6;
			};

			// loc_E14E


			r1 = word_FFFF9AEC;

			if (word_FFFF9AEC == 0 || (r2 = word_FFFF9AEC >= word_FFFF9AEA))
			{
				r1 = (u32)word_FFFF9AEA >> 1;
			};
			//else if (word_FFFF9AEC >= word_FFFF9AEA)
			//{
			//	r2 = true;

			//	r1 = (u32)word_FFFF9AEA >> 1;
			//};

		};

		// loc_E170

		if (r1 < 500)
		{
			u32 r13 = reg_GR2D + r1;
			u32 r10 = reg_TCNT2A + 2;

			if ((r13 - r10) & 0x8000)
			{
				r13 = r10;
			};

			reg_GR2D = r13;
		}
		else
		{
			reg_GR2D += r1;
		};

		// loc_DFAE

		if (ZRO(word_FFFF9ADA, 0x20))
		{
			r2 = !r2;
		};

		// loc_DFC4

		reg_TIOR2B = (reg_TIOR2B & ~0x70) | ((r2) ? 0x20 : 0x10);

		// loc_DFE8

		NOT(word_FFFF9ADA, 0x80);
	}
	else
	{
		// loc_E204

		CLR(reg_PJCRL, 0x40);

		reg_GR2D += word_FFFF9AEA;

		SET(word_FFFF9ADA, 0x80);
		CLR(word_FFFF9ADA, 0x10);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool sub_E294()
{
	__disable_irq();

	bool r1 = word_FFFF9ADA & 1;

	CLR(word_FFFF9ADA, 1);

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool sub_E2CA()
{
	__disable_irq();

	bool r1 = word_FFFF9ADA & 0x10;

	CLR(word_FFFF9ADA, 0x10);

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_E300()
{
	__disable_irq();

	reg_GR2C = reg_TCNT2A + 250;

	CLR(word_FFFF9ADA, 8);

	reg_TIOR2B = (reg_TIOR2B & ~7) | ((word_FFFF9ADA & 2) ? 2 : 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_E356()
{
	__disable_irq();

	reg_GR2C = reg_TCNT2A + 250;

	reg_TIOR2B = (reg_TIOR2B & ~7) | ((word_FFFF9ADA & 2) ? 2 : 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_ATU_Misc_2_sub_E3A2()
{
	__disable_irq();

	CLR(reg_TIER3, 0x18);

	reg_TIOR3B = reg_TIOR3B & 0xF | 0x50;

	CLR(reg_TSR3, 8);

	word_FFFF9ACC = 0;

	word_FFFF9ACE = 0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_E3EA()
{
	__disable_irq();

	CLR(reg_TIER3, 0x18);

	reg_TIOR3B = reg_TIOR3B & 0xF | 0x50;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" u16 sub_E44C()
{
	__disable_irq();

	u32 r1 = word_FFFF9ACC;

	word_FFFF9ACC = 0;

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_E478()
{
	__disable_irq();

	if (reg_TSR3 & 8)
	{
		CLR(reg_TSR3, 8);

		if (word_FFFF9ACC < 255)
		{
			word_FFFF9ACC += 1;
		};

		word_FFFF9ACE += 1;
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" u16 sub_E4C0()
{
	return reg_GR3D;
}	

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Init_ATU_Counters_Control_sub_E4D0()
{
	__disable_irq();

	CLR(reg_TSTR1, 2);

	reg_TCR1A = 0x35;
	reg_TCR1B = 0x35;

	reg_TIOR1A = 0x44;
	reg_TIOR1B = 4;
	reg_TIOR1C = 0x40;
	reg_TIOR1D = 0x44;

	reg_TIER1A = 0;
	reg_TIER1B = 0;
	reg_DCNT8E = 0;
	reg_DCNT8D = 0;
	reg_DNCT8C = 0;
	reg_DNCT8B = 0;
	reg_DCNT8A = 0;
	reg_DCNT8J = 0;
	reg_DCNT8I = 0;
	reg_DCNT8H = 0;
	reg_DCNT8G = 0;
	reg_DCNT8F = 0;

	reg_TCR8 = reg_TCR8 & 0xF0 | 5;

	CLR(reg_TIER8, 0x3FF);

	reg_TSTR3 = 0;

	reg_TCR11 = 0x35;

	reg_TIOR11 = 0;
	reg_TIER11 = 0;

	CLR(reg_CMSTR, 2);

	CLR(reg_CMCSR1, 0x40);
	SET(reg_CMCSR1, 3);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_INTC_sub_E598()
{
	reg_IPRA = 0;

	reg_IPRC = 0x70B;

	reg_IPRD = 0;

	reg_IPRE = 0x980;

	reg_IPRF = 0;
	reg_IPRG = 0;
	reg_IPRH = 0;
	reg_IPRI = 0;

	reg_IPRJ = 0x500;
	reg_IPRK = 0x3330;
	reg_IPRL = 0;

//	CLR(reg_CHCR3, 7); // Comment for Live Map DMA

	reg_ITVRR1 = 0;
	reg_ITVRR2A = 0;
	reg_ITVRR2B = 0;
	reg_POPCR = 0; 
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_E5FC()
{
	__disable_irq();

	reg_IPRA = 0;

	reg_IPRC = 0x70B;

	reg_IPRD = 0;

	reg_IPRE = 0x980;

	reg_IPRF = 0;
	reg_IPRG = 0;
	reg_IPRH = 0;
	reg_IPRI = 0;

	reg_IPRJ = 0x500;
	reg_IPRK = 0x3330;
	reg_IPRL = 0;

//	CLR(reg_CHCR3, 7); // Comment for Live Map DMA

	reg_ITVRR1 = 0;
	reg_ITVRR2A = 0;
	reg_ITVRR2B = 0;
	reg_POPCR = 0; 

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu11_imi1A()
{
	__disable_irq();

	CLR(reg_TSR1A, 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu11_imi1B()
{
	__disable_irq();

	CLR(reg_TSR1A, 2);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu11_imi1C()
{
	__disable_irq();

	CLR(reg_TSR1A, 4);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu12_imi1E()
{
	__disable_irq();

	CLR(reg_TSR1A, 0x10);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu82_osi8G()
{
	__disable_irq();

	CLR(reg_TSR8, 0x40);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void cmti1()
{
	__disable_irq();

	CLR(reg_CMCSR1, 0x80);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu11_imi11B()
{
	__disable_irq();

	CLR(reg_TSR11, 2);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void int_nmi_E9AE()
{
	Read_Ports_And_Registers_sub_B114();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

extern "C" void atu22_imi2H()
{
	//__disable_irq();

	u32 sr = get_cr();

	set_cr(sr|0xF0);

	CLR(reg_TSR2B, 0x80);

	set_cr(sr);

	//__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//#pragma section _F500
#pragma section _main

//#include <umachine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"
#include "hardware.h"


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static void Misfire_CRANK75_root()
{
	Misfire_CRANK75_sub_2B168();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK75_sub_2B168()
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

	word_FFFF9990 = stroke_75 << 4;

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

	u16 *r2 = p[stroke_75];

	p = &ENGINE_MAIN_VARIABLES_DIM_off_9198->_1144_word_FFFF9036;

	u16 *r1 = p[stroke_75];

	*r2 += 1;

	if (*r2 == 0) { *r2 -= 1; };

	*r1 += 1;

	if (*r1 == 0) { *r1 -= 1; };
}	

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK5_root()
{
	Misfire_CRANK5_sub_29558(Div_DW(crank_dt_ICR0AH_5, 4), 0);

	Misfire_CRANK5_sub_29750();

	Misfire_CRANK5_sub_2AC5C();

	if (byte_1056/*0*/ != 0)
	{
		Misfire_CRANK5_sub_2AEE4();
	};

	DECLIM(bMUTDE);

	DECLIM(bMUTE0);

	DECLIM(misfire_word_FFFF9072);
	DECLIM(misfire_word_FFFF8FE4);
	DECLIM(misfire_word_FFFF8FE6);
	DECLIM(word_FFFF8FE8);
	DECLIM(misfire_word_FFFF8FEA);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK5_sub_29558(u16 v1, u16 v2)
{
	null_crank_dt_ICR0AH_B_div_4_6 = null_crank_dt_ICR0AH_B_div_4_5;
	null_crank_dt_ICR0AH_B_div_4_5 = null_crank_dt_ICR0AH_B_div_4_4;
	null_crank_dt_ICR0AH_B_div_4_4 = null_crank_dt_ICR0AH_B_div_4_3;
	null_crank_dt_ICR0AH_B_div_4_3 = null_crank_dt_ICR0AH_B_div_4_2;

	null_crank_dt_ICR0AH_B_div_4_2 = crank_dt_ICR0AH_B_div_4;

	crank_dt_ICR0AH_B_div_4 = v1;

	misfire_word_FFFF8FE2 = misfire_word_FFFF8FE0;
	misfire_word_FFFF8FE0 = misfire_word_FFFF8FDE;
	misfire_word_FFFF8FDE = misfire_word_FFFF8FDC;
	misfire_word_FFFF8FDC = misfire_word_FFFF8FDA;
	misfire_word_FFFF8FDA = misfire_word_FFFF8FD8;
	misfire_word_FFFF8FD8 = misfire_word_FFFF8FD6;
	misfire_word_FFFF8FD6 = misfire_word_FFFF8FD4;
	misfire_word_FFFF8FD4 = word_FFFF8FD2;
	word_FFFF8FD2 = v2;


	u16 r13 = (byte_1056/*0*/ != 0 && (flags_FFFF8FFC & 0x80)) ? word_FFFF8FD2 : crank_dt_ICR0AH_B_div_4;

	word_FFFF8F60 = Div_DW(0x8000000, r13);

	u16 r2 = word_FFFF8F62;

	u32 **p = (byte_1056/*0*/ != 0 && (flags_FFFF8FFC & 0x80)) ? &ENGINE_MAIN_VARIABLES_DIM_off_9198->_952_dword_FFFF8124 : &ENGINE_MAIN_VARIABLES_DIM_off_9198->_872_bMUTD9;

	r13 = Div_65536_R(*p[stroke_75]);

	word_FFFF8F62 = Mul_Div(word_FFFF8F60, r13, 0x8000);

	misfire_word_FFFF8F6C = misfire_word_FFFF8F6A;
	misfire_word_FFFF8F6A = misfire_word_FFFF8F68;
	misfire_word_FFFF8F68 = misfire_word_FFFF8F66;
	misfire_word_FFFF8F66 = bMUTD6;

	r13 = word_FFFF8F62;

	bool r1;

	if (r1 = (r13 >= r2))
	{
		r13 -= r2;
	}
	else
	{
		r13 = r2 - r13;
	};

	if (r13 >= 0x7FFF)
	{
		r13 = 0x7FFF;
	};

	word_FFFF9992 = r13 = Div_DW(Mul32_Fix8(r13, word_FFFF8F60), misfire_word_FFFF8F78);

	if (r1 || r13 == 0)
	{
		bMUTD6 = (r13 < word_1CCC) ? r13 : word_1CCC;
	}
	else
	{
		r13 = -r13;

		bMUTD6 = (r13 >= word_1CCA) ? r13 : word_1CCA;
	};

	misfire_word_FFFF8F72 = misfire_word_FFFF8F70;
	misfire_word_FFFF8F70 = bMUTD7;

	r13 = bMUTD6 - misfire_word_FFFF8F68;

	if (r13 & 0x8000)
	{
		bMUTD7 = (r13 >= word_1CCA) ? r13 : word_1CCA;
	}
	else
	{
		bMUTD7 = (r13 < word_1CCC) ? r13 : word_1CCC;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK5_sub_29750()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK5_sub_2A684()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK5_sub_2AAA2(u16 v)
{
	if (v & 1)
	{
		word_FFFF9000 = word_1C8A;

		word_FFFF9000 = 0;
		word_FFFF9014 = 0;
		word_FFFF9012 = 0;
		word_FFFF9010 = 0;
		word_FFFF901A = 0;
		word_FFFF9018 = 0;
		word_FFFF9016 = 0;
		word_FFFF9020 = 0;
		word_FFFF901E = 0;
		word_FFFF901C = 0;
		word_FFFF9026 = 0;
		word_FFFF9024 = 0;
		word_FFFF9022 = 0;

		if (byte_1026/*0*/ != 0)
		{
			word_FFFF9332 = 0;
			word_FFFF9334 = 0;
			word_FFFF9336 = 0;
			word_FFFF9338 = 0;
		};

		CLR(word_FFFF8F7A, 0x80);
		SET(word_FFFF900C, 0x40);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK5_sub_2AC5C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK5_sub_2AEE4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

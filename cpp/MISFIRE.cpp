//#pragma section _F500

//#include <umachine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"
#include "hardware.h"
#include "MISFIRE.h"

//#define DEF_MISFIRE


#ifndef DEF_MISFIRE	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define _Misfire_NVRAM_Init		((void(*)(void))0x28054)
#define _Misfire_Init_280E4		((void(*)(void))0x280E4)
#define _Misfire_root_28320		((void(*)(void))0x28320)
#define _Misfire_CRANK5_root	((void(*)(void))0x29438)
#define _Misfire_CRANK75_root	((void(*)(void))0x2941C)


#pragma regsave(Misfire_NVRAM_Init			)			
#pragma regsave(Misfire_Init_280E4			)
#pragma regsave(Misfire_root_28320			)	
#pragma regsave(Misfire_CRANK5_root			)
#pragma regsave(Misfire_CRANK75_root		)

void Misfire_NVRAM_Init()							{	_Misfire_NVRAM_Init();		}						
void Misfire_Init_280E4()							{	_Misfire_Init_280E4();		}		
void Misfire_root_28320()							{	_Misfire_root_28320(); 		}		
void Misfire_CRANK5_root()							{	_Misfire_CRANK5_root(); 		}		
void Misfire_CRANK75_root()							{	_Misfire_CRANK75_root(); 		}		


#else	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_CRANK75_sub_2B168();
static void Misfire_CRANK5_root();
static void Misfire_CRANK5_sub_29558(u16 v1, u16 v2);
static void Misfire_CRANK5_sub_29750();
static void Misfire_CRANK5_sub_2A684();
static void Misfire_CRANK5_sub_2AAA2(u16 v);
static void Misfire_CRANK5_sub_2AC5C();
static void Misfire_CRANK5_sub_2AEE4();
static void Misfire_Knock_Load_Filter_Tables_sub_283E8();
static void Misfire_sub_28588();
static void Misfire_sub_28606();
static void Misfire_sub_28B74(u16 r4);
static void Misfire_sub_28BDC();
static void Misfire_sub_28BF2();
static u16 Misfire_sub_28F88(u16 r4);
static void Misfire_sub_29158();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define RPM11_6B0A							((Axis*)0x6B0A)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define unk110_3F3C							((Map3D_B *)0x3F3C)
#define unk109_3F2A							((Map3D_B *)0x3F2A)
#define unk108_3F18							((Map3D_B *)0x3F18)
#define unk107_3F06							((Map3D_B *)0x3F06)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define word_989A							((const u16*)0x989A)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

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

	if (r13 == 0xFF || r13 == 0 || (flags_FFFF8FFC & 8) || ZRO(misfire_word_FFFF8F7C, 0x10) || ZRO(bMUTD3_BitMap4_FCA_Store_FFFF89D8, FCA_5_20))
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

	u16 **p = &(ENGINE_MAIN_VARIABLES_DIM_off_9198->_1064_word_FFFF901E);

	u16 *r2 = p[stroke_75];

	p = &(ENGINE_MAIN_VARIABLES_DIM_off_9198->_1144_word_FFFF9036);

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

static void Misfire_CRANK5_sub_29558(u16 v1/*(crank_dt_ICR0AH_5 / 4)*/, u16 v2 /*0*/)
{
	// Misfire_CRANK5_sub_29558(Div_DW(crank_dt_ICR0AH_5, 4), 0);

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
		bMUTD6 = (r13 < word_1CCC/*0x3FFF*/) ? r13 : word_1CCC/*0x3FFF*/;
	}
	else
	{
		r13 = -r13;

		bMUTD6 = (r13 >= word_1CCA/*0xC000*/) ? r13 : word_1CCA/*0xC000*/;
	};

	misfire_word_FFFF8F72 = misfire_word_FFFF8F70;
	misfire_word_FFFF8F70 = bMUTD7;

	r13 = bMUTD6 - misfire_word_FFFF8F68;

	if (r13 & 0x8000)
	{
		bMUTD7 = (r13 >= word_1CCA/*0xC000*/) ? r13 : word_1CCA/*0xC000*/;
	}
	else
	{
		bMUTD7 = (r13 < word_1CCC/*0x3FFF*/) ? r13 : word_1CCC/*0x3FFF*/;
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

void Misfire_root_28320()
{
	Misfire_Knock_Load_Filter_Tables_sub_283E8();

	Misfire_sub_28606();

	if (bMUTD3_BitMap4_FCA_Store_FFFF89D8 & (FCA_4_10|FCA_5_20))
	{
		Misfire_sub_28BDC();
	}
	else
	{
		CLR(ZERO_8_IGNITION_FLAGS, 0x8000|0x4000);

		injectors_misfire_mask = ~0;

		faults_FFFF80F4 = 0;
		wMUT8D = 0;
	};

	if ((injectors_misfire_mask & 0xF) != 0xF)
	{
		SET(word_FFFF9296, 0x80);
		SET(word_FFFF9298, 0x80);
	}
	else
	{
		CLR(word_FFFF9296, 0x80);
		CLR(word_FFFF9298, 0x80);
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_Knock_Load_Filter_Tables_sub_283E8()
{


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28588()
{


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28606()
{


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28B74(u16 r4)
{
	if (bMUTDD < r4) bMUTDD = r4;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28B8E(u16 r4)
{
	if (misfire_timer_FFFF86E6 < r4) misfire_timer_FFFF86E6 = r4;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28BA8(u16 r4)
{
	if (bMUTDF < r4) bMUTDF = r4;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28BC2(u16 r4)
{
	if (misfire_timer_FFFF86E8 < r4) misfire_timer_FFFF86E8 = r4;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28BDC()
{
	Misfire_sub_28BF2();		

	Misfire_sub_29158();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28BF2()
{


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 Misfire_sub_28F88(u16 r4)
{
	Table_Lookup_Axis(RPM11_6B0A);

	Map3D_B *map;

	if (r4 >= word_1C84/*0x50*/)
	{
		map = unk110_3F3C;
	}
	else if (r4 >= word_1C82/*0x3C*/)
	{
		map = unk109_3F2A;
	}
	else if (r4 >= word_1C80/*0x28*/)
	{
		map = unk108_3F18;
	}
	else if (r4 >= word_1C7E/*0xA*/)
	{
		map = unk107_3F06;
	}
	else
	{
		return ~0;
	};

	return Table_Lookup_byte_2D_3D(map);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_28FF8(u16 *r4)
{
	u16 r2 = 0, r8 = 0;

	u16 r9 = word_1C88/*40*/ / 4;

	if (r9 > word_1C8E/*9*/) r9 = word_1C8E/*9*/;

	u16 *r6 = r4;

	const u16 *r3 = word_989A; // word_989A: .data.w      1, 2, 4, 8, h'10, h'20, h'40, h'80, h'100, h'200, h'400, h'800,h'1000,h'2000,h'4000,h'8000

	u16 r13 = 6;

	do
	{
		if (*r6 > r9) r2 |= *r3, r8 += 1;

		r6++;
		r3++;
		r13--;
	}
	while (r13 != 0);

	if (r8 != 1) r2 = 0x80;

	if ((stored_DTC_2 & 0xC000) == 0)
	{
		faults_FFFF80F4 = (faults_FFFF80F4 & 0xFF40) | (r2 & ~0xFF40);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 Misfire_sub_29110(u16 *r4, u16 r5)
{
	u16 r1 = r4[1];

	u16 r7 = 2;

	u16 r13 = r4[2];

	if (r13 >= r1) r1 = r13, r7 = 4;

	u16 r6 = r4[0];

	u16 r3 = 1;

	r13 = r4[3];

	if (r13 >= r6) r6 = r13, r3 = 8;

	if (r5 == 1 || r1 < r6) r7 = r3;

	return ~r7;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Misfire_sub_29158()
{


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif // DEF_MISFIRE	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

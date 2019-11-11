#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"
#include "FU03.h"
#include "BC06.h"
#include "hardware.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void cmti0();
#pragma address v_cmti0=0x2F0
const void * v_cmti0 = cmti0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma section _HUGE


#define _IMMO_sub_2212E						((void(*)(void))0x2212E)
#define _COM_MUT_sub_207F0					((void(*)(void))0x207F0)
#define _sub_34664							((void(*)(void))0x34664)
#define _MUT2B_800Hz_root					((void(*)(void))0x2192E)

#pragma regsave(IMMO_sub_2212E		)			
#pragma regsave(COM_MUT_sub_207F0	)
#pragma regsave(sub_34664			)	
#pragma regsave(MUT2B_800Hz_root	)

static void IMMO_sub_2212E()		{	_IMMO_sub_2212E();		}						
static void COM_MUT_sub_207F0()		{	_COM_MUT_sub_207F0();	}						
static void sub_34664()				{	_sub_34664();			}						
static void MUT2B_800Hz_root()		{	_MUT2B_800Hz_root();	}						

//#undef BC06_sub_1E2D0

//#undef F500_Init_Load_ECU_Info_And_BitMap_Flags

//#define sub_A374			((void(*)(void))0xA374)
//#define F500_sub_21C80		((bool(*)(void))0x21C80)

//#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

//#define Get_ADC_Bat_TPS_oxigen				((void(*)(void))0xA8DC)
//#define Read_Ports_And_Registers_sub_B114	((void(*)(void))0xB114)

//#define PDIOR_Stuff_sub_AD3C				((void(*)(void))0xAD3C)
//extern "C" void PDIOR_Stuff_sub_AD3C();

//#define PHDR_Stuff_sub_C388					((void(*)(void))0xC388)
//extern "C" void PHDR_Stuff_sub_C388();

//#define sub_D3E4							((void(*)(void))0xD3E4)
//#define PADR_Stuff_sub_A5F8					((void(*)(void))0xA5F8)
//#define sub_E478							((void(*)(void))0xE478)
//#define sub_DCB4							((bool(*)(void))0xDCB4)
//#define sub_D4E4							((bool(*)(void))0xD4E4)
//#define Start_Coil_Charge					((void(*)(u16))0xBE1C)
//#define sub_AD94							((void(*)(void))0xAD94)

//extern "C" void Update_Gen_G_output();

//#define Update_Gen_G_output					((void(*)(void))0xAD06)
//#define Get_Manifold_AbsPressure			((void(*)(void))0xA95A)

//#define sub_21A72							((u16(*)(u16))0x21A72)
//#define sub_21A52							((u16(*)(u16))0x21A52)
//#define atu22_Get_DSTR_0x3C00				((u16(*)(void))0x3C00)

//#define BC06_sub_1D2BC						((void(*)(void))0x1D2BC)
//#define UpdateOutputSync					((void(*)(void))0xAB3C)
//#define PWM_EGR_EVAP_O2H					((void(*)(void))0xAE08)

#define	off_8AE4							((u16**)0x8AE4)  
#define	word_8AD4							((const u16*)0x8AD4)                                                     

#define ASSACCELTPSDELTA_353F				((const byte*)0x353F)
#define word_98DE							((const u16*)0x98DE)
#define asyncAccelMulTPS_Delta				((const byte*)0x3559)

//#define GetADC								((u16(*)(byte, u16*, u16*))0xB2B6)


//#define CEL8_685C							((Axis*)0x685C)
//#define CEL9_6876							((Axis*)0x6876)
//#define CEL10_68B2							((Axis*)0x68B2)
//#define CEL12_68D0							((Axis*)0x68D0)
//#define CEL8_6D98							((Axis*)0x6D98)
//#define CEL9_75BA							((Axis*)0x75BA)
//#define BAR5_6D66							((Axis*)0x6D66)
//#define LOAD9_65C0							((Axis*)0x65C0)
//#define RPM11_64AC							((Axis*)0x64AC)
//#define LOAD9_65F8							((Axis*)0x65F8)
//#define mapInletAirTemp_Scaling				((Axis*)0x9B82)
//#define CEL7_692E							((Axis*)0x692E)
//#define map_Coolant_Temp_Scaling			((Axis*)0x99A8)


//#define AFRRPM_4C1A							((Map3D_B *)0x4C1A)
//#define AIRTEMPCOMPAFR1_33C4				((Map3D_B *)0x33C4)
//#define AIRTEMPCOMPAFR1_45D8				((Map3D_B *)0x45D8)
//#define LOADAFR_33B4						((Map3D_B *)0x33B4)
//#define TPS_2D_3ED6							((Map3D_B *)0x3ED6)
//#define MAP_2D_3EE8							((Map3D_B *)0x3EE8)
//#define byte_9B00							((Map3D_B *)0x9B00)
//#define CORFUELAIR_33A6						((Map3D_B *)0x33A6)
//#define COOLTEMSCAL_98FA					((Map3D_B *)0x98FA)


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern u16 INJECTOR_RESCALED_sub_26174(u16 v);
//extern void StartInjectAsync(u16 v, u16 mask);
//extern void StartInjectSync(u16 v, u16 mask);

//#define INJECTOR_RESCALED_sub_26174						((u16(*)(u16))0x26174)
//#define StartInjectAsync								((void(*)(u16,u16))0x261CA)
//#define StartInjectSync									((void(*)(u16,u16))0x26218)


//#pragma noregsave(HUGE_Method_801_6_Hz)
//#pragma noregsave(Huge_400_Hz)
//#pragma noregsave(Huge_200_Hz)
//#pragma noregsave(Huge_100_Hz)
//#pragma noregsave(sub_27C6C)
//#pragma noregsave(Huge_100_Hz_27C7A)
//#pragma noregsave(Huge_50_Hz)
//#pragma noregsave(Huge_800_Hz_27F62)

inline u16 sub_21A72(u16 v) { return v; }
inline u16 sub_21A52(u16 v) { return v; }

static void HUGE_Method_801_6_Hz();

static void Huge_400_Hz();
static void Huge_200_Hz();
static void Huge_100_Hz();
static void sub_27C6C();
static void Huge_100_Hz_27C7A();
static void Huge_50_Hz();
static void Huge_800_Hz_27F62();

static void Update_MAP_Avrg();
//static u16 sub_E44C();
//static void MUT98_sub_329C6();
#define MUT98_sub_329C6						((void(*)(void))0x329C6)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void SysInit_ATU_2A_2B_3_4_5_8_10()
//{
//	__disable_irq();
//
//	reg_PSCR1 = 3; // 4 MHz
//
//	reg_PSCR4 = 3; // 4 MHz
//
//	reg_TCR2A = 0x34; // 250kHz
//	reg_TCR2B = 0x34;
//	reg_TCR3 = 0x34;
//	reg_TCR4 = 0x34;
//	reg_TCR5 = 0x34;
//
//	reg_TCR8 = reg_TCR8 & 0xF | 0x50;
//
//	reg_TIOR10 = 0x30;
//	reg_TCR10 = 0;
//	reg_TIER10 = 0x10;
//	reg_TMDR = 0;
//	reg_TSTR1 = reg_TSTR1 & 2 | 0x7D;
//
//	reg_CMCOR0 = 2495; // period
//	reg_CMCSR0 = 0x40; // Pô/8 = 2MHz
//	CLR(reg_CMCSR0, 0x80); // reset irq
//	SET(reg_CMSTR, 1);		// start CMT0
//
//	word_FFFF9AD2 = reg_TCNT2A + 312;
//
//	CLR(reg_TIER3, 0x3A0);
//
//	reg_TIOR4A = 0x11;
//	reg_TIOR4B = 0x11;
//	CLR(reg_TIER3, 0x40);
//
//	downTimer_801 = 1;
//
//	__enable_irq();
//}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(cmti0)
#pragma regsave(cmti0)

void cmti0()
{
	__disable_irq();

	/*i32 b = */word_FFFF9AD6 = reg_TCNT2A;

	CLR(reg_CMCSR0, 0x80);

	DECLIM(downTimer_801);

	/*i32 a = */word_FFFF9AD2 += 312;

	if ((word_FFFF9AD2 - reg_TCNT2A) & 0x8000) // if ((i16)(a - b) < 0)
	{
		word_FFFF9AD2 += 312;

		__enable_irq();

		HUGE_Method_801_6_Hz();

		HUGE_Method_801_6_Hz();
	}
	else
	{
		__enable_irq();

		HUGE_Method_801_6_Hz();

		word_FFFF9AD4 = reg_TCNT2A - word_FFFF9AD6;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define _Start_Coil_Charge					((void(*)(u16))0xBE1C)
//#pragma regsave(Start_Coil_Charge					)
//void Start_Coil_Charge(u16 mask)			{	_Start_Coil_Charge(mask);				}		


void Start_Coil_Charge(u16 mask)
{
	__disable_irq();

	if (mask & 1)
	{
		reg_GR2E = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x10);

		reg_TIOR2C = reg_TIOR2C & 0xF8 | 1; // 0 output on GR compare-match

#ifndef DEF_SIMULATION
		while(ZRO(reg_TSR2A, 0x10)) ;
#endif
	};

	if (mask & 2)
	{
		reg_GR2F = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x20);

		reg_TIOR2C = reg_TIOR2C & 0x8F | 0x10; // 0 output on GR compare-match

#ifndef DEF_SIMULATION
		while(ZRO(reg_TSR2A, 0x20)) ;
#endif
	};

	if (mask & 4)
	{
		reg_GR2G = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x40);

		reg_TIOR2D = reg_TIOR2D & 0xF8 | 1; // 0 output on GR compare-match

#ifndef DEF_SIMULATION
		while(ZRO(reg_TSR2A, 0x40)) ;
#endif
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SysInit_NVRAM_266DC()
{
	Barometric_FFFF8024 = barometric_sens_err_val;
	TPS_NVRAM_FFFF802A = const_TPS_206C;
	NVRAM_FFFF802C = 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SysInit_sub_266FC()
{
	SPEED_PULSES_FFFF89C4 = ~0;

	if (portA_state & 2)
	{
		SET(huge_timeEvents, EVT_15_8000);
	};

	word_FFFF8566 = 6;

	SET(huge_timeEvents, EVT_0_25ms);

	word_FFFF856A = 100;

	prev_TPS_Corrected = wMUT8A_TPS_Corrected = Lim_FF(Sub_Lim_0(wMUT1B_TPS_Idle_Adder + wMUT17_TPS_ADC8bit, 128));

	word_FFFF8B48 = prev_TPS_1 = prev_TPS_2 = prev_TPS_3 = prev_TPS_4 = prev_TPS_5 = wMUT17_TPS_ADC8bit;

	word_FFFF8DB6 = 0xFF;

	word_FFFF85F4 = 20;

	word_FFFF8DDE = 0x80;

	word_FFFF8DE2 = 0;

	word_FFFF8DE0 = ~0;

	word_FFFF8D80 = 0xC0;

	word_FFFF8D78 = 24;

	enInjMask = ~0;

	word_FFFF8556 = word_1764;

	word_FFFF8558 = word_175E;

	curMinMAP = 255;

	SET(NVRAM_FFFF802C, 1);

	word_FFFF8924 = const_TPS_206C;

	timer_FFFF8584 = t1_unk_2070;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//static void PDIOR_Stuff_sub_AD3C()
//{
//	__disable_irq();
//
//	//u32 r11 = reg_PDDRH & 1 ^ 1;
//
//	//u32 r12 = reg_PDDRH & ~1;
//
//	//reg_PDDRH = r11 & 1 | r12;
//	
//	reg_PDDRH ^= 1;
//
//	__enable_irq();
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//extern "C" void PHDR_Stuff_sub_C388()
//{
//	__disable_irq();
//
//	CLR(reg_PHDRL, 2);
//
//	u32 t = 1;
//
//	while (--t);
//
//	bMUTB7 = ((u32)(RPDR16(reg_PHDRH)) << 1) >> 8;
//
//	SET(reg_PHDRL, 2);
//	CLR(reg_PHDRL, 1);
//
//	t = 1;
//
//	while (--t);
//
//	bMUTB8 = ((u32)(RPDR16(reg_PHDRH)) << 1) >> 8;
//
//	CLR(reg_PHDRL, 2);
//	SET(reg_PHDRL, 1);
//
//	t = 1;
//
//	while (--t);
//
//	bMUTB9 = ((u32)(RPDR16(reg_PHDRH)) << 1) >> 8;
//
//	SET(reg_PHDRL, 3);
//
//	t = 1;
//
//	while (--t);
//
//	bMUTBA = ((u32)(RPDR16(reg_PHDRH)) << 1) >> 8;
//
//	__enable_irq();
//}
//
////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_AD94()
{
	__disable_irq();

	WPDR16(reg_PEDRH, RPDR16(reg_PEDRH) & 0xF3FF | word_8AD4[stepperPinOutIndex & 3]);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool sub_C2CC()
{
	bool r1 = false;

	__disable_irq();

	if (reg_ISR & 0x40)
	{
		CLR(reg_ISR, 0x40);

		r1 = true;
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool sub_C304()
{
	bool r1 = false;

	__disable_irq();

	if (reg_ISR & 0x20)
	{
		CLR(reg_ISR, 0x20);

		r1 = true;
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool sub_C33C()
{
	bool r1 = false;

	__disable_irq();

	if (reg_ISR & 0x10)
	{
		CLR(reg_ISR, 0x10);

		r1 = true;
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_D3E4()
{
	__disable_irq();

	u32 r11 = **off_8AE4;

	reg_SCI2->TDR = r11;

	CLR(reg_SCI2->SSR, 0x80);

	reg_SCI2->SCR = 0xB0;

	word_FFFF8D94 = r11;

	word_FFFF8DB6 = 1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool sub_DCB4()
{
	return ZRO(reg_TSR0, 1) && ZRO(crank_Flags, 2) && ZRO(reg_TSR2B, 0x40);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_D4E4()
{
	__disable_irq();

	u32 r3 = reg_SCI2->SSR;

	if (r3 & 0x78)
	{
		byte r1 = reg_SCI2->RDR;

		CLR(reg_SCI2->SSR, 0x78);

		u32 r13 = word_FFFF8DB4;

		if (r13 < 5 && ZRO(r3, 0x38))
		{
			word_FFFF8DA8[r13] = r1;

			word_FFFF8DB4 += 1;
		};
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//static void PADR_Stuff_sub_A5F8()
//{
//	__disable_irq();
//
//	u32 r1 = portA_state;
//
//	WBIT(r1, 1, ZRO(reg_PADRL, 1));
//
//	WBIT(r1, 2, ZRO(reg_PADRL, 0x80));
//
//	WBIT(r1, 8, ZRO(bMUTB7, 2));
//
//	WBIT(r1, 4, ZRO(bMUTB8, 2));
//
//	WBIT(r1, 0x20, ONE(reg_PADRH, 0x80));
//
//	WBIT(r1, 0x40, ZRO(reg_PEDRL, 4));
//
//	WBIT(r1, 0x80, ONE(bMUTBA, 4));
//
//	WBIT(r1, 0x100, ONE(bMUTB9, 2));
//
//	WBIT(r1, 0x400, sub_C2CC());
//
//	WBIT(r1, 0x800, sub_C304());
//
//	WBIT(r1, 0x1000, ONE(bMUTB7, 4));
//
//	WBIT(r1, 0x2000, true);
//
//	portA_state = r1;
//
//	__enable_irq();
//
//	__disable_irq();
//
//	WBIT(word_FFFF93CC, 0x800, sub_C33C());
//
//	__enable_irq();
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Read_Ports_And_Registers_sub_B114()
{
	__disable_irq();

	reg_DCNT8P = 0;
	reg_DCNT8O = 0;
	reg_DCNT8N = 0;
	reg_DCNT8M = 0;
	reg_DCNT8L = 0;
	reg_DCNT8K = 0;

	CLR(reg_SYSCR, 1);

	reg_PJIOR = 0;
	reg_PHIOR = 0;
	reg_PGIOR = 0;
	reg_PFIOR = 0;
	reg_PEIOR = 0;
	reg_PDIOR = 0;
	reg_PCIOR = 0;
	reg_PBIOR = 0;
	reg_PAIOR = 0;

	reg_PKCRL = 0;
	reg_PKCRH = 0;
	reg_PJCRL = 0;
	reg_PJCRH = 0;

	reg_PJCRL = 0;
	reg_PJCRH = 0;

	reg_PHCR = 0;
	reg_PGCR = 0;

	reg_PFCRL = 0;
	reg_PFCRH = 0;

	reg_PECR = 0;
	reg_PCCR = 0;

	reg_PDCRL = 0;
	reg_PDCRH = 0;

	reg_PBCRL = 0;
	reg_PBCRH = 0;

	reg_PACRL = 0;
	reg_PACRH = 0;

	for (;;);

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 sub_E44C()
{
	__disable_irq();

	u32 r1 = word_FFFF9ACC;

	word_FFFF9ACC = 0;

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_E478()
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

//#pragma regsave(Get_ADC_Bat_TPS_oxigen)
//
//static void Get_ADC_Bat_TPS_oxigen()
//{
//	u16 res;//, res1, res2;
//
//	GetADC(1, &wMUT14_Battery_Level_ADC8bit, &res);
//
////	GetADC(5, &res1, &res);
//
////	wMUT17_TPS_ADC8bit = res1;
//
////	TPS_ADC10bit = res;
//
//	GetADC(5, &wMUT17_TPS_ADC8bit, &TPS_ADC10bit);
//
//	GetADC(9, &oxigen_ADC8bit, &res);
//
//	GetADC(7, &null_ADC_7_8bit, &res);
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma regsave(Get_Manifold_AbsPressure)
//
//static void Get_Manifold_AbsPressure()
//{
//	u16 res;
//
//	GetADC(4, &wMUT1A_Manifold_AbsPressure_ADC8bit, &res);
//
//	wMUT8C_Manifold_AbsPressure_ADC8bit = wMUT1A_Manifold_AbsPressure_ADC8bit;
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma regsave(HUGE_Method_801_6_Hz)

static void HUGE_Method_801_6_Hz()
{
	__disable_irq();

	hugeCallCounter += 1;

	DECLIM(RPM8_FFFF8B00);

	PHDR_Stuff_sub_C388();

	portA_state_pr2 = portA_state_pr1;

	portA_state_pr1 = portA_state;

	word_FFFF93CE = word_FFFF93CC;

	PADR_Stuff_sub_A5F8();

	sub_E478();

	if ((portA_state & 0x40) && (portA_state & 1) && (word_FFFF8BBA & 0x80) && wMUT14_Battery_Level_ADC8bit < 0xFF)
	{
		word_FFFF8C5C = 0;

		CLR(word_FFFF8C5E, 1);

		if (sub_DCB4())
		{
			Start_Coil_Charge(curTimingMask_75);
		};
	};

	// loc_2690C

	if (byte_1029/*0*/ != 0)
	{
		// loc_26918

		DECLIM(word_FFFF8DE2);

		word_FFFF8DE0 <<= 1;

		if (portA_state & 0x10)
		{
			SET(word_FFFF8DE0, 1);
		};

		if (ZRO(portA_state, 0x4000) ^ ZRO(word_FFFF8DDE, 0x20))
		{
			INCLIM(word_FFFF8DE4);
		}
		else
		{
			word_FFFF8DE4 = 0;
		};

		u32 r13;

		if (ZRO(word_FFFF8DDE, 0x20))
		{
			if (word_FFFF8DE4 > 40)
			{
				// loc_26A0E

				r13 = 6;
			}
			else if (ZRO(word_FFFF8DDE, 0x80))
			{
				if (word_FFFF8DDE & 0x40)
				{
					if (word_FFFF8DE0 != 0xFFFF)
					{
						// loc_26A7C

						r13 = 0;
					}
					else if (word_FFFF8DE2 == 0)
					{
						// loc_26A76

						r13 = 2;
					}
					else
					{
						r13 = 3;
					};
				}
				else if (word_FFFF8DE0 == 0 || word_FFFF8DE0 == 0xFFFF)
				{
					// loc_26A76

					r13 = 2;
				}
				else
				{
					// loc_26A7C

					r13 = 0;
				};
			}
			else if (word_FFFF8DE2 != 0)
			{
				r13 = 1;
			}
			else if (word_FFFF8DE4 != 0)
			{
				// loc_26A0E

				r13 = 6;
			}
			else
			{
				// loc_26A14

				r13 = 4;
			};
		}
		else
		{
			r13 = (word_FFFF8DE4 > 40) ? 2 : 5;
		};

		// loc_26A7E

		if (r13 == 6)
		{
			word_FFFF8DDE = 0x20;
			word_FFFF8DE4 = 0;

			SET(wMUT9B_Output_Pins, 0x10);
			CLR(wMUT9B_Output_Pins, 0x20);
		}
		else if (r13 == 5)
		{
			word_FFFF8DDE = 0x20;

			CLR(wMUT9B_Output_Pins, 0x10);
			CLR(wMUT9B_Output_Pins, 0x20);
		}
		else if (r13 == 2)
		{
			word_FFFF8DE2 = 8;
			word_FFFF8DDE = 0x80;

			SET(wMUT9B_Output_Pins, 0x10);
			CLR(wMUT9B_Output_Pins, 0x20);
		}
		else if (r13 == 1)
		{
			word_FFFF8DDE = 0x80;

			SET(wMUT9B_Output_Pins, 0x10);
			CLR(wMUT9B_Output_Pins, 0x20);
		}
		else  if (r13 == 4)
		{
			word_FFFF8DE0 = 0xFFFF;
			word_FFFF8DE2 = 0xC;
			word_FFFF8DDE = 0x40;

			CLR(wMUT9B_Output_Pins, 0x10);
			CLR(wMUT9B_Output_Pins, 0x20);
		}
		else   if (r13 == 3)
		{
			word_FFFF8DDE = 0x40;

			CLR(wMUT9B_Output_Pins, 0x10);
			CLR(wMUT9B_Output_Pins, 0x20);
		}
		else
		{
			word_FFFF8DDE = 0;

			CLR(wMUT9B_Output_Pins, 0x10);
			SET(wMUT9B_Output_Pins, 0x20);
		};

	};

	// loc_26B32

	__enable_irq();

	if (wMUTD1_BitMap_FAA & FAA_13_2000)
	{
		__disable_irq();

		sub_D4E4();

		__enable_irq();
	};

	// loc_26B54

	__disable_irq();

	WFLAG(KNOCK_FLAG2_FFFF887A, KNOCK_F2_01, gen_G_timer != 0);

	Update_Gen_G_output();

	DECLIM(gen_G_timer);

	__enable_irq();

	if (bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x8000)
	{
		MUT98_sub_329C6();
	};

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	Huge_400_Hz();

	Huge_200_Hz();

	Huge_100_Hz();

	sub_27C6C();

	Huge_100_Hz_27C7A();

	Huge_50_Hz();

	Huge_800_Hz_27F62();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Huge_400_Hz()
{
	if (hugeCallCounter & 1) 
	{
		return;
	};

	// loc_26BB0
		
	Update_MAP_Avrg();

	DECLIM(timer_down_FFFF89CE);

	DECLIM(word_FFFF89C2);

	DECLIM(word_FFFF89D0);

	u32 r1 = huge_timeEvents;

	WFLAG(r1, EVT_15_8000, portA_state & 2);

	if ((huge_timeEvents ^ r1) & EVT_15_8000)
	{
		timer_down_FFFF89CE = t1_unk_1778/*200*/;
	
		if (r1 & EVT_15_8000)
		{
			SPEED_PULSES_FFFF89C4 = Sub_Lim_0(226, word_FFFF89C2);

			word_FFFF89C2 = 226;
		};
	}
	else if (word_FFFF89C2 == 0)
	{
		SPEED_PULSES_FFFF89C4 = 0xFFFF;
	};

	// loc_26C50

	huge_timeEvents = r1;

	if (word_FFFF89D0 == 0)
	{
		// loc_26C60

		word_FFFF89D0 = 283;

		obd_Add_Vehicle_Speed = wMUT2F_Vehicle_Speed;

		wMUT2F_Vehicle_Speed = sub_E44C();

		SET(huge_timeEvents, EVT_8_100);

		if (word_FFFF90B6 & 0x200)
		{
			// loc_26C90

			word_FFFF8380 = Add_Lim_FFFF(word_FFFF8380, wMUT2F_Vehicle_Speed);

			DECLIM(word_FFFF8382);

			if (word_FFFF8382 == 0)
			{
				word_FFFF9960 = Div_WW(word_FFFF8380, word_2CA2/*15*/);

				word_FFFF8380 = 0;

				word_FFFF837C = Add_Lim_FFFF(word_FFFF837C, word_FFFF9960);

				if (word_FFFF837C >= word_2CA4/*169*/)
				{
					word_FFFF837C = Sub_Lim_0(word_FFFF837C, word_2CA4);

					distance_with_malfunction += 1;

					word_FFFF8386 = Lim_FF(Div_R4_R5__R0(distance_with_malfunction, 4));

					word_FFFF8384 = Lim_FF(distance_with_malfunction);
				};

				// loc_26D5E

				word_FFFF8382 = word_2CA2/*15*/;
			};
		};
	};

	// loc_26D66

	INCLIM(mut_timeout);

	INCLIM(word_FFFF8EAE);

	DECLIM(word_FFFF8EB4);

	if (wMUTD1_BitMap_FAA & FAA_3_IMMO)
	{
		IMMO_sub_2212E();
	};
	
	COM_MUT_sub_207F0();

	if (bMUTD4_BitMap5_FDA_Store_FFFF89DA & 0x2000)
	{
		sub_34664();
	};

	word_FFFF8D74 &= 0x3FF;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline void Huge_200_loc_26E90()
{
	// loc_26E90

	Get_ADC_Bat_TPS_oxigen();

	prev_TPS_Corrected = wMUT8A_TPS_Corrected;

	wMUT8A_TPS_Corrected = Lim_FF(Sub_Lim_0(wMUT1B_TPS_Idle_Adder + wMUT17_TPS_ADC8bit, 0x80));

	if (bMUTD2_FBA_MAF_MAP_FLAG & 8)
	{
		// loc_26ECE

		u32 r1 = TPS_ADC10bit;

		if (r1 > const_TPS_206C/*192*/)
		{
			CLR(NVRAM_FFFF802C, 4);
		};

		u32 r2;

		if (  (RPM_FLAGS & (RPM_0_CRANKING|RPM_4_STALL)) 
			|| cranking_end_timer_up <= word_2074/*200*/
			|| wMUT14_Battery_Level_ADC8bit <= word_2072/*136*/
			|| r1 < const_TPS_206E/*40*/
			|| r1 > const_TPS_206C/*192*/
			|| RT_FLAG1_FFFF8888 & RACING	)
		{
			r2 = 0;	
		}
		else
		{
			r2 = 1;

			if (ZRO(NVRAM_FFFF802C, 2) && ZRO(hugeCallCounter, 0x7F) && r1 >= TPS_NVRAM_FFFF802A)
			{
				u32 r13 = Sub_Lim_0(TPS_NVRAM_FFFF802A, word_2078/*12*/);

				TPS_NVRAM_FFFF802A = (r13 >= r1) ? r13 : r1; 
			};
		};

		// loc_26FA4

		u32 r13 = Add_Lim_FFFF(word_FFFF8924, word_2076/*4*/);

		if (r2 == 0 || word_FFFF8924 > r1 || r1 > r13)
		{
			timer_FFFF8584 = t1_unk_2070/*120*/;
			
			// loc_2703A
			
			word_FFFF8924 = r1;
		}
		else if (timer_FFFF8584 == 0)
		{	
			timer_FFFF8584 = t1_unk_2070/*120*/;

			if (TPS_NVRAM_FFFF802A >= word_FFFF8924)
			{
				// loc_2701E

				SET(NVRAM_FFFF802C, 2);

				TPS_NVRAM_FFFF802A = word_FFFF8924;

				// loc_2703A
				
				word_FFFF8924 = r1;
			}
			else if (ZRO(NVRAM_FFFF802C, 4))
			{
				SET(NVRAM_FFFF802C, 6);

				r13 = Add_Lim_FFFF(TPS_NVRAM_FFFF802A, 4);

				TPS_NVRAM_FFFF802A = (r13 > word_FFFF8924) ? word_FFFF8924 : r13;

				// loc_2703A
				
				word_FFFF8924 = r1;
			};
		};

		// loc_2703E

		r2 = Add_Lim_FFFF(TPS_NVRAM_FFFF802A, word_2068/*7*/);

		u32 r8 = Sub_Lim_0(r2, word_206A/*4*/);

		u32 r9 = Add_Lim_FFFF(TPS_NVRAM_FFFF802A, word_2CA6/*7*/);

		r13 = Sub_Lim_0(r9, word_2CA8/*4*/);

		TRG(NVRAM_FFFF802C, 8, r1, r8, r2);

		// loc_27124

		TRG(NVRAM_FFFF802C, 0x400, r1, r13, r9);

		// loc_27156


		if (wMUT71_Sensor_Error & MUT71_6_TPS)
		{
			CLR(NVRAM_FFFF802C, 1);

			WFLAG(wMUT9B_Output_Pins, 0x400, wMUT17_TPS_ADC8bit > t1_unk_some_TPS_2116/*236*/);
		}
		else
		{
			if (ZRO(NVRAM_FFFF802C,8))
			{
				SET(NVRAM_FFFF802C, 1);
				SET(wMUT9B_Output_Pins, 0x400);
			}
			else
			{
				CLR(NVRAM_FFFF802C, 1);
				CLR(wMUT9B_Output_Pins, 0x400);
			};
		};


	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline void Huge_200_loc_271D6()
{
	// loc_271D6

	mem_incr(&timer_up_FFFF8520, &cranking_end_timer_up);

	mem_decr(&word_FFFF8550, &timer_down_TXFLAG3_FFFF8574);

	if (word_FFFF8566 == 0)
	{
		word_FFFF8566 = 5;

		word_FFFF9076 += 1;

		SET(huge_timeEvents, EVT_0_25ms);

		if (ZRO(word_FFFF9076, 1))
		{
			SET(huge_timeEvents, EVT_1_50ms);
		};

		if (ZRO(word_FFFF9076, 3))
		{
			SET(huge_timeEvents, EVT_2_100ms);
		};

		if (ZRO(word_FFFF9076, 7))
		{
			SET(huge_timeEvents, EVT_6_200ms);
		};
	};

	// loc_27238

	if (word_FFFF8568 == 0)
	{
		word_FFFF8568 = 8;

		SET(huge_timeEvents, EVT_7_40ms);
	};

	// loc_2724E

	if (word_FFFF856A == 0)
	{
		word_FFFF856A = 100;

		word_FFFF9078 += 1;

		SET(huge_timeEvents, EVT_3_500ms);

		if (ZRO(word_FFFF9078, 1))
		{
			SET(huge_timeEvents, EVT_4_1s);
		};
		
		if (ZRO(word_FFFF9078, 3))
		{
			SET(huge_timeEvents, EVT_5_2s);
		};

		__disable_irq();
	
		dword_FFFF8B6C = dword_FFFF8B68;

		dword_FFFF8B68 = 0;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline void Huge_200_loc_272A6()
{
	// loc_272A6

	if (timer_FFFF8582 == 0)
	{
		__disable_irq();

		// no return
		Read_Ports_And_Registers_sub_B114();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef DEF_HARDWARE
#pragma regsave(Huge_200_loc_272BA)
static void Huge_200_loc_272BA()
#else
inline void Huge_200_loc_272BA()
#endif
{	
	// loc_272BA

	if (word_FFFF8550 != 0)
	{
		PDIOR_Stuff_sub_AD3C();
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline void Huge_200_Knock()
{
	// loc_272C8

	if (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN) // Enable High Oct Ign Map Lookup and other
	{
		if (word_FFFF855E == 0)
		{
			__disable_irq();

			DECLIM(wMUT26_Knock_Retard);

			__enable_irq();
		};

		u32 r13 = knockSum_decay_timer/*160*/;

		if (wMUT6F_Knock_Accel_timer != 0)
		{
			r13 = t1_knock_control_advance_time_17E0/*70*/;
		};

		if (ZRO(KNOCK_FLAG_FFFF8C34, KNOCK_F1_80))
		{
			r13 = 2;
		};

		if (word_FFFF855E == 0 || r13 < word_FFFF855E)
		{
			word_FFFF855E = r13;
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline void Huge_200_Idle_Stepper()
{
	// loc_27326

	TRG(word_FFFF93DC, 1, wMUT14_Battery_Level_ADC8bit, word_26A4/*109*/, word_26A6/*113*/);

	TRG(word_FFFF93DC, 2, wMUT14_Battery_Level_ADC8bit, word_26CE/*123*/, word_26CC/*150*/);

	TRG(word_FFFF8C98, 0x80, wMUT14_Battery_Level_ADC8bit, word_1A0C/*136*/, word_1A0E/*141*/);

	if (word_FFFF8C98 & 0x80)
	{
		// loc_2746C

		u32 r13 = 3;

		if (wMUT22_ISCV & M22_FORCED_OPEN)
		{
			r13 = 4;
		};

		INCLIM(word_FFFF8C9A);

		if (word_FFFF8C9A >= r13)
		{
			u32 m16 = wMUT16_cur_Idle_Steps;
			u32 r1 = (byte)m16;
			
			if (SwapBytes16(r1) == m16 && r1 != wMUT25_Target_Idle_Steps)
			{
				if (r1 < wMUT25_Target_Idle_Steps)
				{
					r1 += 1;

					stepperPinOutIndex += 1;
				}
				else
				{
					r1 -= 1;

					stepperPinOutIndex -= 1;
				};

				// loc_274DC

				__disable_irq();

				wMUT16_cur_Idle_Steps = SwapBytes16(r1);

				sub_AD94();

				__enable_irq();

				word_FFFF8C9A = 1;
			};
		};
	}
	else
	{
		// loc_2752C

		word_FFFF8C9A = 0;
	};
	
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline void Huge_200_loc_27532()
{
	// loc_27532

	if ((wMUTD1_BitMap_FAA & FAA_5_20) && word_FFFF8560 == 0)
	{
		word_FFFF8560 = 4;

		INC32(word_FFFF8DB8);

		// loc_2756A

		if (ZRO(word_FFFF8D74, 0x80) && word_FFFF8DB4 == 5 && (word_FFFF8DA8[0] + word_FFFF8DA8[1] + word_FFFF8DA8[2] + word_FFFF8DA8[3]) == word_FFFF8DA8[4])
		{
			wMUT70_Array_of_Serial_Receive_Data_Register_2_RDR2_Values = word_FFFF8DA8[0];

			word_FFFF8D9A = word_FFFF8DA8[1];
			word_FFFF8D9E = word_FFFF8DA8[2];
			word_FFFF8DA0 = word_FFFF8DA8[3];
			word_FFFF8DB8 = 0;

			if (ZRO(word_FFFF8D9E, 7))
			{
				SET(word_FFFF8D74, 1);
			};

			u32 r13;

			if (word_FFFF8D74 & 1)
			{
				word_FFFF9162 = 0;
				word_FFFF916A = 0;
			}
			else if ((r13 = word_FFFF8DA0 & 0xF) == 0)
			{
				word_FFFF916A = 0;
			}
			else
			{
				INC32(word_FFFF916A);

				if (word_FFFF916A != r13)
				{
					word_FFFF9162 = 1;
				}
				else if (word_FFFF9162 >= word_1F50)
				{
					SET(word_FFFF8D74, 1);
					word_FFFF9168 = r13;
				};

				// loc_27638

				word_FFFF916A = r13;
			};

		};

		// loc_2764C

		if (ZRO(RT_FLAG1_FFFF8888, RT_1_bit) || (RT_FLAG1_FFFF8888 & STARTER) || ZRO(word_FFFF8C98, 0x80))
		{
			word_FFFF85F4 = 20;
			word_FFFF8DB8 = 0;
		}
		else if (word_FFFF85F4 != 0)
		{
			word_FFFF8DB8 = 0;
		};

		if (word_FFFF8DB8 >= 0xFF)
		{
			SET(word_FFFF8D74, 0x80);

			wMUT70_Array_of_Serial_Receive_Data_Register_2_RDR2_Values = 0x80;

			word_FFFF8D9E = 0;
			word_FFFF8DA0 = 0;
		};

		// loc_2769E

		if (timer_down_TXFLAG3_FFFF8574 == 0)
		{
			CLR(word_FFFF8D74, 0x80|0x40|1);
		};

		word_FFFF8DB4 = 0;

		sub_D3E4();
	};

	// loc_276BC

	if (wMUT8A_TPS_Corrected <= word_FFFF8B34)
	{
		word_FFFF855A = word_FFFF8B36;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline void Huge_200_Update_Baro()
{
	// loc_276D0 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	u32 baro = Barometric_FFFF8024;

	bool r2 = wMUT14_Battery_Level_ADC8bit >= word_1762/*109*/;

	u32 r13 = wMUT8A_TPS_Corrected;


	if (wMUT71_Sensor_Error & MUT71_3_MAP)
	{
		if (ZRO(RPM_FLAGS, RPM_0_CRANKING|RPM_4_STALL))
		{
			baro = barometric_sens_err_val;
		};

		word_FFFF8558 = word_175E/*40*/;

		SET(huge_timeEvents, 0x4000);
	}
	else
	{
		if ((RPM_FLAGS & (RPM_0_CRANKING|RPM_4_STALL)) || r13 < TPS_MAP_Addition)
		{
			// loc_277DA

			word_FFFF8558 = word_175E;
		}
		else if (word_FFFF8558 == 0)
		{
			baro = Add_Lim_FFFF(Manifold_AbsPressure_ADC8bit_avrg, MAP_Addition);
		};

		// loc_277E2

		__disable_irq();

		if (ZRO(word_FFFF89F2, 1))
		{
			// loc_277F4

			if (r2)
			{
				if (wMUT1A_Manifold_AbsPressure_ADC8bit >= curMaxMAP)
				{
					curMaxMAP = wMUT1A_Manifold_AbsPressure_ADC8bit;
				};

				if (wMUT1A_Manifold_AbsPressure_ADC8bit < curMinMAP)
				{
					curMinMAP = wMUT1A_Manifold_AbsPressure_ADC8bit;
				};
			};

			// loc_2782A

			if ((huge_timeEvents & 0x4000) || (portA_state & 0x40) || !r2)
			{
				// loc_27882

				word_FFFF8556 = word_1764/*20*/;
			}
			else if (word_FFFF8556 == 0 && (curMaxMAP - curMinMAP) <= word_1768/*5*/)
			{
				// loc_2784E

				baro = Sub_Lim_0(wMUT1A_Manifold_AbsPressure_ADC8bit, word_1766/*0*/);

				// loc_27928

				SET(huge_timeEvents, 0x4000);
			};
		}
		else
		{
			// loc_2788E

			if (r2 && MUT21_RPM_x125div4 >= word_1760/*48*/ && Manifold_AbsPressure_ADC8bit_avrg >= baro)
			{
				baro = Manifold_AbsPressure_ADC8bit_avrg;
			};

			// loc_278B0

			if (ZRO(huge_timeEvents, 0x4000) && ZRO(word_FFFF89F2, 2))
			{
				if (r2 && wMUT1A_Manifold_AbsPressure_ADC8bit >= curMaxMAP)
				{
					curMaxMAP = wMUT1A_Manifold_AbsPressure_ADC8bit;
				};
			};

			if (word_FFFF8556 == 0 && curMaxMAP != 0 && curMaxMAP >= curMinMAP && (curMaxMAP - curMinMAP) <= word_176C/*11*/)
			{
				baro = Add_Lim_FFFF(curMaxMAP, word_176A/*0*/);

				// loc_27928

				SET(huge_timeEvents, 0x4000);
			};
		};

		// loc_27932

		__enable_irq();
	};

	// loc_27938

	Barometric_FFFF8024 = Lim16(baro, hiBaroLim, loBaroLim);

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Huge_200_Hz()
{
	if (hugeCallCounter & 3) 
	{
		return;
	};

	// loc_26E90

	Huge_200_loc_26E90();

	// loc_271D6

	Huge_200_loc_271D6();

	// loc_272A6

	Huge_200_loc_272A6();

	// loc_272BA

	Huge_200_loc_272BA();

	// loc_272C8

	Huge_200_Knock();

	// loc_27326

	Huge_200_Idle_Stepper();

	// loc_27532

	Huge_200_loc_27532();

	// loc_276D0 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	Huge_200_Update_Baro();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Update_MAP_Avrg()
{
	__disable_irq();

	Get_Manifold_AbsPressure();

	u16 r13 = manifold_SumCount + 1;

	if (r13 != 0)
	{
		u16 r3 = manifold_Sum + wMUT1A_Manifold_AbsPressure_ADC8bit;

		if (r3 >= manifold_Sum)
		{
			manifold_SumCount = r13;
			manifold_Sum = r3;
		};
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//static void MUT98_sub_329C6()
//{
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Huge_100_Hz()
{
	if (hugeCallCounter & 7) 
	{
		return;
	};

	// loc_27960

	if (IGN_TEST_FLAG_1044 != 0)
	{
		u32 r13 = IGN_MULT_FLAG_FFFF8DBC;

		if (r13 & 0x10)
		{
			DECLIM(word_FFFF8DBA);
		}
		else
		{
			word_FFFF8DBA = 0;
		};

		if (ZRO(r13, 0x13))
		{
			CLR(wMUT9B_Output_Pins, 2);
		}
		else if (r13 & 2)
		{
			SET(wMUT9B_Output_Pins, 2);
		}
		else if (word_FFFF8DBA == 0)
		{
			wMUT9B_Output_Pins ^= 2;

			if (r13 & 0x10)
			{
				word_FFFF8DBA = 3;
			};
		};
	};

	// loc_27A48

	if (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN)
	{
		__disable_irq();

		// knock_filtered_x256 += (wMUTC9_knock_ADC_proc_filtered - knock_filtered_x256) / 8;
		// knock_filtered_x256 = (knock_filtered_x256 * 7 + wMUTC9_knock_ADC_proc_filtered) / 8;

		u32 r0 = Mul16(knock_filtered_x256, 7);
		
		knock_filtered_x256 = DIV_DW_R(r0 + wMUTC9_knock_ADC_proc_filtered, 8);

		u32 r1 = (KNOCK_FLAG2_FFFF887A & KNOCK_GAIN_3) ? knockAdder_SingleGain/*3*/ : knockAdder_TripleGain/*5*/;

		r1 = sub_21A72(r1);

		u32 r13 = knockMul_lowRPM/*15(1.875)*/;

		if (KNOCK_FLAG_FFFF8C34 & KNOCK_RPM_LOW)
		{
			r13 = (KNOCK_FLAG_FFFF8C34 & KNOCK_RPM_MID) ? knockMul_midRPM/*19(2.375)*/ : knockMul_highRPM/*16(2.0)*/;
		};

		// knock_filtered_x256 * r13 * 32 / 65536 + r1

		r0 = Mul16(knock_filtered_x256, sub_21A52(r13) << 5);
		
		r0 = Div_65536_R(r0) + r1;

		knock_base_final = Lim16(r0, 0xFF, 1);

		__enable_irq();
	};

	// loc_27AF6 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	u32 r13;

	if (wMUT17_TPS_ADC8bit >= prev_TPS_1)
	{
		// loc_27B6C

		r13 = wMUT17_TPS_ADC8bit - prev_TPS_1;

		if (r13 > TPS_Open_Delta)
		{
			TPS_Open_Delta = r13;
		};
	}
	else
	{
		// loc_27BA8

		r13 = prev_TPS_1 - wMUT17_TPS_ADC8bit;

		if (r13 > TPS_Close_Delta)
		{
			TPS_Close_Delta = r13;
		};

		r13 = 0;
	};

	// loc_27BC4

	if (r13 >= t1_knock_control_accel_delta_17E2/*51*/)
	{
		wMUT6F_Knock_Accel_timer = t1_knock_control_accel_delta_17E6/*40*/;
	};

	if (ZRO(IGN_FLAG9_FFFF8BB6, IGN_F9_40) && r13 >= t1_some_load_17A2/*5*/ && r13 >= abs_Delta_TPS)
	{
		abs_Delta_TPS = r13;

		timer_Delta_TPS = t1_unk_17A6/*4*/;
	};

	// loc_27C02 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	CLR(huge_timeEvents, EVT_11_800);

	if (ABSDIF(prev_TPS_5, wMUT17_TPS_ADC8bit) >= word_174E/*3*/)
	{
		word_FFFF86B6 = word_1750/*40*/;
	};

	// loc_27C44

	prev_TPS_5 = prev_TPS_4;
	prev_TPS_4 = prev_TPS_3;
	prev_TPS_3 = prev_TPS_2;
	prev_TPS_2 = prev_TPS_1;
	prev_TPS_1 = wMUT17_TPS_ADC8bit;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_27C6C()
{
	if (word_FFFF855C == 0)
	{
		word_FFFF8B40 = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Huge_100_Hz_27C7A()
{
	if (hugeCallCounter & 7) 
	{
		return;
	};

	// loc_27C86

	word_FFFF8B46 = Sub_Lim_0(wMUT17_TPS_ADC8bit, word_FFFF8B48);

	CLR(huge_timeEvents, EVT_13_2000);

	word_FFFF8B4C += 1;

	u32 r13;
	bool r3;

	if (word_FFFF8B46 >= asyncAccelMinTPS_Delta/*3*/)
	{
		r13 = word_FFFF8B48;
		r3 = true;
	}
	else if (word_FFFF8B4C >= word_2548/*2*/)
	{
		word_FFFF8B46 = Sub_Lim_0(wMUT17_TPS_ADC8bit, word_FFFF8B4A);

		r13 = word_FFFF8B4A;
		r3 = true;
	}
	else
	{
		r13 = 0;
		r3 = false;
	};

	if (r3)
	{
		if (word_FFFF8B46 >= asyncAccelMinTPS_Delta && r13 < ASYNC_INJECTION_FFFF8B44 && word_FFFF8B40 < word_FFFF8B3E && ZRO(RPM_FLAGS, RPM_0_CRANKING|RPM_4_STALL))
		{
			if (((bMUTD2_FBA_MAF_MAP_FLAG & 8) && ZRO(NVRAM_FFFF802C, 1)) || (ZRO(bMUTD2_FBA_MAF_MAP_FLAG, 8) && ZRO(portA_state, 0x80)))
			{	
				word_FFFF855C = asyncAccelPausePeriod;

				SET(huge_timeEvents, EVT_13_2000);

				u32 r1 = word_FFFF8B46 >> 2;

				if (r1 >= 8)
				{
					r1 = 8;
				};

				r1 = (ASSACCELTPSDELTA_353F[r1] * ASYNC_ENRICHMENT_FFFF8B42) >> 7;

				if (r1 >= asyncAccelMaxPulsewidth/*33*/)
				{
					r1 = asyncAccelMaxPulsewidth;
				};

				word_FFFF8B3C = r1;

				word_FFFF8B40 += r1;

				if (r1 != 0)
				{
					r1 = INJECTOR_RESCALED_sub_26174(r1<<5);

					__disable_irq();

					StartInjectAsync(r1, word_98DE[stroke_FFFF8F26] & (~atu22_Get_DSTR_0x3C00()));

					__enable_irq();
				};
			};
		};

		// loc_27DF8

		word_FFFF8B4C = 0;

		word_FFFF8B4A = wMUT17_TPS_ADC8bit;
	};

	// loc_27E06

	word_FFFF8B48 = wMUT17_TPS_ADC8bit;

	if (word_FFFF8B46 >= asyncAccelMinTPS_Delta/*3*/)
	{
		word_FFFF86B6 = word_1750/*40*/;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Huge_50_Hz()
{
	if (hugeCallCounter & 0xF) 
	{
		return;
	};

	// loc_27E2E

	u32 r13;
	bool r6;
	u32 r3;

	if (prev_TPS_1 >= prev_TPS_3)
	{
		r13 = prev_TPS_1 - prev_TPS_3;
		r6 = true;

		r3 = 8;

		if (r13 < r3)
		{
			r3 = r13;
		};
	}
	else
	{
		r13 = prev_TPS_3 - prev_TPS_1;
		r6 = false;

		r3 = 0;
	};

	word_FFFF8B38 = asyncAccelMulTPS_Delta[r3];// 32, 32, 48, 64, 81, 96,111,129,145

	if (r6)
	{
		if (r13 >= word_166E/*2*/)
		{
			fall_TPS_timer = 0;
		};

		if (r13 >= word_1686/*2*/)
		{
			rise_TPS_timer = word_168A/*120*/;
		};
	}
	else
	{
		if (r13 >= word_166C/*6*/)
		{
			fall_TPS_timer = word_1670/*0*/;
		};

		if (r13 >= word_1688/*2*/)
		{
			rise_TPS_timer = 0;
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Huge_800_Hz_27F62()
{
	BC06_sub_1D2BC();

	UpdateOutputSync();

	PWM_EGR_EVAP_O2H();

	MUT2B_800Hz_root();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

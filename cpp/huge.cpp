#pragma section _HUGE

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"

//#undef BC06_sub_1E2D0

//#undef F500_Init_Load_ECU_Info_And_BitMap_Flags

//#define sub_A374			((void(*)(void))0xA374)
//#define F500_sub_21C80		((bool(*)(void))0x21C80)

#define ENGINE_MAIN_VARIABLES_DIM_off_9198		((EnVars*)0x9198)

#define Get_ADC_Bat_TPS_oxigen				((void(*)(void))0xA8DC)
#define Read_Ports_And_Registers_sub_B114	((void(*)(void))0xB114)
#define PDIOR_Stuff_sub_AD3C				((void(*)(void))0xAD3C)
#define PHDR_Stuff_sub_C388					((void(*)(void))0xC388)
#define sub_D3E4							((void(*)(void))0xD3E4)
#define PADR_Stuff_sub_A5F8					((void(*)(void))0xA5F8)
#define sub_E478							((void(*)(void))0xE478)
#define sub_DCB4							((bool(*)(void))0xDCB4)
#define sub_D4E4							((bool(*)(void))0xD4E4)
#define Start_Coil_Charge				((void(*)(u16))0xBE1C)

extern void Update_Gen_G_output();

//#define Update_Gen_G_output					((void(*)(void))0xAD06)
//#define MUT98_sub_329C6						((void(*)(void))0x329C6)
#define IMMO_sub_2212E						((void(*)(void))0x2212E)
#define COM_MUT_sub_207F0					((void(*)(void))0x207F0)
#define sub_34664							((void(*)(void))0x34664)
#define Get_Manifold_AbsPressure			((void(*)(void))0xA95A)

#define sub_21A72							((u16(*)(u16))0x21A72)
#define sub_21A52							((u16(*)(u16))0x21A52)
#define atu22_Get_DSTR_0x3C00				((u16(*)(void))0x3C00)

#define BC06_sub_1D2BC						((void(*)(void))0x1D2BC)
#define UpdateOutputSync					((void(*)(void))0xAB3C)
#define PWM_EGR_EVAP_O2H					((void(*)(void))0xAE08)
#define MUT2B_800Hz_root					((void(*)(void))0x2192E)



#define ASSACCELTPSDELTA_353F				((const byte*)0x353F)
#define word_98DE							((const u16*)0x98DE)
#define asyncAccelMulTPS_Delta				((const byte*)0x3559)



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

extern u16 INJECTOR_RESCALED_sub_26174(u16 v);
extern void StartInjectAsync(u16 v, u16 mask);
extern void StartInjectSync(u16 v, u16 mask);


static void HUGE_Method_801_6_Hz();
static void Huge_400_Hz();
static void Huge_200_Hz();
static void Huge_100_Hz();
static void sub_27C6C();
static void Huge_100_Hz_27C7A();
static void Huge_50_Hz();
static void Huge_800_Hz_27F62();

static void Update_MAP_Avrg();
static u16 sub_E44C();
static void MUT98_sub_329C6();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_ATU_2A_2B_3_4_5_8_10()
{
	__disable_irq();

	reg_PSCR1 = 3; // 4 MHz

	reg_PSCR4 = 3; // 4 MHz

	reg_TCR2A = 0x34; // 250kHz
	reg_TCR2B = 0x34;
	reg_TCR3 = 0x34;
	reg_TCR4 = 0x34;
	reg_TCR5 = 0x34;

	reg_TCR8 = reg_TCR8 & 0xF | 0x50;

	reg_TIOR10 = 0x30;
	reg_TCR10 = 0;
	reg_TIER10 = 0x10;
	reg_TMDR = 0;
	reg_TSTR1 = reg_TSTR1 & 2 | 0x7D;

	reg_CMCOR0 = 2495; // period
	reg_CMCSR0 = 0x40; // Pô/8 = 2MHz
	CLR(reg_CMCSR0, 0x80); // reset irq
	SET(reg_CMSTR, 1);		// start CMT0

	word_FFFF9AD2 = reg_TCNT2A + 312;

	CLR(reg_TIER3, 0x3A0);

	reg_TIOR4A = 0x11;
	reg_TIOR4B = 0x11;
	CLR(reg_TIER3, 0x40);

	downTimer_801 = 1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(cmti0)

extern "C" void cmti0()
{
	__disable_irq();

	word_FFFF9AD6 = reg_TCNT2A;

	CLR(reg_CMCSR0, 0x80);

	DECLIM(downTimer_801);

	word_FFFF9AD2 += 312;

	if ((word_FFFF9AD2 - reg_TCNT2A) & 0x8000)
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

	if ((portA_state & 0x40) && (portA_state & 1) && (word_FFFF8BBA & 0x80) && wMUT14_Battery_Level_ADC8bit >= 0xFF)
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
			if (NVRAM_FFFF802C & 8)
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

inline void Huge_200_loc_272BA()
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

inline void Huge_200_loc_27326()
{
	// loc_27326

	TRG(word_FFFF93DC, 1, wMUT14_Battery_Level_ADC8bit, word_26A4/*109*/, word_26A6/*113*/);

	TRG(word_FFFF93DC, 2, wMUT14_Battery_Level_ADC8bit, word_26CE/*123*/, word_26CC/*150*/);

	TRG(word_FFFF8C98, 0x80, wMUT14_Battery_Level_ADC8bit, word_1A0C/*136*/, word_1A0E/*141*/);

	if (word_FFFF8C98 & 0x80)
	{
		// loc_2746C

		u32 r13 = 3;

		if (wMUT22 & 0x80)
		{
			r13 = 4;
		};

		INCLIM(word_FFFF8C9A);

		if (word_FFFF8C9A >= r13)
		{
			u32 r1 = wMUT16_ISC_Steps;
			
			if (SwapBytes16(r1) == r1 && r1 != wMUT25_Idle_Stepper_Value)
			{
				if (r1 < wMUT25_Idle_Stepper_Value)
				{
					r1 += 1;

					POTEPINS1011_FFFF80C8 += 1;
				}
				else
				{
					r1 -= 1;

					POTEPINS1011_FFFF80C8 -= 1;
				};

				// loc_274DC

				__disable_irq();

				wMUT16_ISC_Steps = SwapBytes16(r1);

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

		if (ZRO(word_FFFF8D74, 0x80) && word_FFFF8DB4 == 5 && (word_FFFF8DA8 + word_FFFF8DAA + word_FFFF8DAC + word_FFFF8DAE) == word_FFFF8DB0)
		{
			wMUT70_Array_of_Serial_Receive_Data_Register_2_RDR2_Values = word_FFFF8DA8;

			word_FFFF8D9A = word_FFFF8DAA;
			word_FFFF8D9E = word_FFFF8DAC;
			word_FFFF8DA0 = word_FFFF8DAE;
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

	Huge_200_loc_27326();

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

static u16 sub_E44C()
{
	__disable_irq();

	u32 r1 = word_FFFF9ACC;

	word_FFFF9ACC = 0;

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void MUT98_sub_329C6()
{

}

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
					r1 = INJECTOR_RESCALED_sub_26174(r1<<7);

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

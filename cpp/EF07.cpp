//#pragma section _EF07
#pragma section _main

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"
#include "hardware.h"



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct FLT
{
	byte mask[4];
	u16 (*func)();
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define dword_8B64 ((const FLT*)0x8B64)
#define dword_8BC4 ((const FLT*)0x8BC4)

#define OBD_Set_DTC_sub_2C1FC ((void(*)(u16,u16,u16))0x2C1FC)
#define OBD_Set_DTC_sub_2C22A ((void(*)(u16,u16,u16,u16))0x2C22A)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void EF07_sub_1F468();
static void EF07_sub_1F4FC();
static void EF07_sub_1F53A();
static void EF07_sub_1F6C4();
static void EF07_sub_1F86C();
static void EF07_sub_1F882();
static void EF07_sub_1F9B4(u16 r4);
static u16 EF07_sub_1FA16();
static u16 EF07_sub_1FA22();
static u16 EF07_sub_1FA9C();
static u16 EF07_sub_1FAD2();
static u16 EF07_sub_1FB14();
static u16 EF07_sub_1FBE4();
static u16 EF07_sub_1FC2C();
static u16 EF07_sub_1FC5E();
static u16 EF07_sub_1FC6A();
static u16 EF07_sub_1FC76();
static u16 EF07_sub_1FDD6();
static u16 EF07_sub_1FDF2();
static u16 EF07_sub_1FE22();
static u16 EF07_sub_1FE5C();
static u16 EF07_sub_1FE8A();
static u16 EF07_sub_1FE96();
static u16 EF07_sub_1FECC();
static u16 EF07_sub_1FED8();
static u16 EF07_sub_1FEE4();
static u16 EF07_sub_1FEF0();
static u16 EF07_sub_1FF2A();
static void EF07_sub_1FF36();
static void EF07_sub_1FF94();
static void Init_Clear_active_faults();
static void EF07_sub_20308();
static void EF07_sub_204AC();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_NVRAM_1F3E0()
{
	Init_Clear_active_faults();

	CLR(word_FFFF80E6, 0x8000);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_sub_1F408()
{
	word_FFFF8718 = t1_unk_253E/*20*/;

	FLAGS_FFFF8EB0 = 0x41;

	SET(wMUT9A_Ligths_Bit_Array, 8);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


extern "C" void EF07_root_sub_1F428()
{
	EF07_sub_1F468();
	EF07_sub_1F4FC();
	EF07_sub_1F53A();
	EF07_sub_1F6C4();
	EF07_sub_1F86C();
	EF07_sub_1FF94();
	EF07_sub_20308();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void EF07_sub_1F468()
{
	if (timer_up_FFFF852C < 4)
	{
		CLR(word_FFFF80E6, 0x6A);
		CLR(word_FFFF80E8, 0x2A);
		SET(word_FFFF80E6, 1);
		word_FFFF8DE8 = 0;
		word_FFFF8718 = t1_unk_253E/*20*/;
		word_FFFF854E = 0;

		u32 r1 = SwapBytes16(0);

		wMUT40_Stored_Faults_Lo = SwapBytes16(wMUT40_Stored_Faults_Lo & 0x11);
		wMUT41_Stored_Faults_Hi = r1;

		wMUT42_Stored_Faults_Lo_1 = SwapBytes16(wMUT42_Stored_Faults_Lo_1 & 0x82);
		wMUT43_Stored_Faults_Hi_1 = r1;
		wMUT44_Stored_Faults_Lo_2 = r1;
		Stored_Faults_Hi_2 = r1;

		CLR(wMUT71_Sensor_Error, MUT71_4_bit);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_1F4FC()
{
	if (timer_FFFF8592 == 0)
	{
		SET(word_FFFF80E6, 1);
	}
	else if ((word_FFFF80E6 & 1) || (wMUT1E_MAF_RESET_FLAG & CRANKING))
	{
		CLR(word_FFFF80E6, 1);
		word_FFFF854E = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_1F53A()
{
    if (timer_up_FFFF852C <= 32)
    {
		if (ZRO(wMUT1E_MAF_RESET_FLAG, STALL) || wMUT07_CoolTemp_ADC8bit >= 5 || wMUT14_Battery_Level_ADC8bit < (18.03918/0.07333))
		{
			// loc_1F568

			CLR(FLAGS_FFFF8EB0, 0x40);
		};
	}
	else
	{
		if (FLAGS_FFFF8EB0 & 1)
		{
			if (wMUT2F_Vehicle_Speed < 180/2)
			{
				CLR(FLAGS_FFFF8EB0, 0x40);
			};

			if (FLAGS_FFFF8EB0 & 0x40)
			{
				SET(FLAGS_FFFF8EB0, 0x80);
			};
		};

		// loc_1F5A2

		CLR(FLAGS_FFFF8EB0, 0x41);

		if (wMUT14_Battery_Level_ADC8bit < 177/*12.98/0.07333*/)
		{
			CLR(FLAGS_FFFF8EB0, 0x80);
		};
	};

	// loc_1F5C0

	if ((FLAGS_FFFF8EB0 & 0x80) && ZRO(FLAGS_FFFF8EB0, 2))
	{
		u32 r1 = ChkSum(0, 0x8000);

		r1 += ChkSum((void*)0x8000, 0x8000);
		r1 += ChkSum((void*)0x10000, 0x8000);
		r1 += ChkSum((void*)0x18000, 0x8000);
		r1 += ChkSum((void*)0x20000, 0x8000);
		r1 += ChkSum((void*)0x28000, 0x8000);
		r1 += ChkSum((void*)0x30000, 0x8000);
		r1 += ChkSum((void*)0x38000, 0x8000);

		bMUTFD_MUT_RES1_FFFF8EB2 = r1;

		SET(FLAGS_FFFF8EB0, 2);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_1F6C4()
{
	__disable_irq();

	u32 r1 = MUT_VAR_9_FFFF8DFC;

	CLR(MUT_VAR_9_FFFF8DFC, 0x565);

	__enable_irq();

	if (ZRO(word_FFFF80E6, 0x80))
	{
		if ((r1 & 0x40) || byte_F3A/*0*/ != 0 || (FLAGS_FFFF8EB0 & 0x80))
		{
			SET(word_FFFF80E6, 0x80);

			if (word_FFFF8DE8 != 1)
			{
				word_FFFF8718 = word_2540/*10*/;
			};
		}
	}
	else
	{
		// loc_1F724

		if (byte_F3A == 0 && ((r1 & 0x20) || timer_up_FFFF852C < 4))
		{
			CLR(word_FFFF80E6, 0x80);
			word_FFFF8718 = t1_unk_253E/*20*/;
		};
	};

	// loc_1F74E

	if (ZRO(word_FFFF80E6, 0x100))
	{
		if (r1 & 0x100)
		{
			SET(word_FFFF80E6, 0x100);

			CLR(Bitmap_Store_F_FFFF91B0, 0xFB);
		};
	}
	else
	{
		// loc_1F7C8

		if ((r1 & 4) || timer_up_FFFF852C < 4 || ZRO(RT_FLAG1_FFFF8888, DRIVE_ALWAYS_1) || (RT_FLAG1_FFFF8888 & RACING))
		{
			CLR(word_FFFF80E6, 0x100);
		};
	};

	// loc_1F7F2

	if (ZRO(word_FFFF80E6, 0x200))
	{
		if (r1 & 0x400)
		{
			SET(word_FFFF80E6, 0x200);

			CLR(Bitmap_Store_F_FFFF91B0, 0xFB);
		};
	}
	else
	{
		// loc_1F81C

		if ((r1 & 1) || timer_up_FFFF852C < 4 || ZRO(RT_FLAG1_FFFF8888, DRIVE_ALWAYS_1) || (RT_FLAG1_FFFF8888 & RACING))
		{
			CLR(word_FFFF80E6, 0x200);
		};

	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_1F86C()
{
	EF07_sub_1F882();
	EF07_sub_1FF36();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_1F882()
{
	EF07_sub_1F9B4(0);

	u32 r10 = word_FFFF8DE8;

	const FLT *r1 = (r10 < 12) ? (dword_8B64 + r10) : (dword_8BC4 - 12 + r10);

	u32 r13 = r1->func();

	if (r13 == 1)
	{
		u32 r2 = r1->mask[0];
		u32 m = r1->mask[1];

		u16 *r8 = ((u16*)&wMUT40_Stored_Faults_Lo) + r2;

		*r8 = SwapBytes16(*r8 & ~m);

		if (ZRO(r2, 1))
		{
			m <<= 8;
		};

		OBD_Set_DTC_sub_2C1FC(m, (r2>>1)+5, 0);

		EF07_sub_1F9B4(1);
	}
	else if (r13 == 0)
	{
		u32 r2 = r1->mask[0];
		u32 m = r1->mask[1];

		u16 *r8 = ((u16*)&wMUT40_Stored_Faults_Lo) + r2;

		if (word_FFFF8718 == 0)
		{
			*r8 = SwapBytes16(*r8 | m);

			if (ZRO(r2, 1))
			{
				m <<= 8;
			};

			OBD_Set_DTC_sub_2C22A(m, (r2>>1)+5, 0, 1);

			if (r2 == 1 && m == 8 && ZRO(stored_DTC_5, 8))
			{
				word_FFFF81E8 = word_FFFF922E;
			};

			EF07_sub_1F9B4(1);
		}
		else if (*r8 & m)
		{
			EF07_sub_1F9B4(1);
		};
	}
	else
	{
		EF07_sub_1F9B4(1);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_1F9B4(u16 r4)
{
	u32 r3 = word_FFFF8DE8;

	if (r4 != 0)
	{
		r3 += 1;
	};

	u32 r13 = 20;

	if (word_FFFF854E < word_1BF0/*4*/)
	{
		r13 = 11;
	};

	if (r3 > r13)
	{
		r3 = 0;
	};

	if (word_FFFF8DE8 != r3)
	{
		word_FFFF8718 = ((word_FFFF80E6 & 0x80) && (r3 != 1)) ? word_2540/*10*/ : t1_unk_253E/*20*/;
	};

	word_FFFF8DE8 = r3;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FA16()
{
	return 2;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FA22()
{
	u32 r13;

	if (ZRO(wMUT71_Sensor_Error, MUT71_3_MAP))
	{
		r13 = 1;
	}
	else 
	{
		r13 = 0;

		if ((wMUT71_Sensor_Error & MUT71_3_MAP) && (wMUT1A_Manifold_AbsPressure_ADC8bit >= word_1C66))
		{

		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FA9C()
{
	u32 r13 = 2;

	if (timer_FFFF8592 != 0)
	{
		r13 = 1;
	}
	else if (RT_FLAG1_FFFF8888 & STARTER)
	{
		if (ZRO(wMUTD1_BitMap_FAA, FAA_3_IMMO) || (word_FFFF80FA & 0x80))
		{
			r13 = 0;
		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FAD2()
{
	u32 r1 = 2;

	if (timer_FFFF8592 != 0)
	{
		if (word_FFFF8DE6 == 0)
		{
			r1 = 0;
		}
		else if (camShaftFlags & 1)
		{
			r1 = 1;
		}
		else if (!Check_Starter_signal())
		{
			r1 = 0;
		};
	};

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FB14()
{
	u16 r13 = 2;

	u32 r6 = word_1C16/*80*/;
	u32 r3 = word_1C18/*124*/;

	if (ZRO(RT_FLAG1_FFFF8888, DRIVE_ALWAYS_1))
	{
		r6 = word_2332/*80*/;
		r3 = word_2334/*124*/;
	};
	
	if (word_FFFF854E >= word_1BF0/*4*/)
	{
		if (timer_down_FFFF89CE != 0)
		{
			r13 = 1;
		}
		else if (	ZRO(RT_FLAG1_FFFF8888, RT_7_bit) 
					&& MUT21_RPM_x125div4 < word_226A/*128*/ && MUT21_RPM_x125div4 > r6 
					&& wMUT1D_Manifold_Absolute_Pressure_Mean < word_226C/*191*/ && wMUT1D_Manifold_Absolute_Pressure_Mean > r3
					&& ZRO(wMUT1E_MAF_RESET_FLAG, MAP_error) && ZRO(RPM_FLAGS, RPM_5_REVLIM))
		{
			r13 = 0;
		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FBE4()
{
	u16 r13 = 2;

	if (timer_FFFF8592 != 0 && MUT21_RPM_x125div4 < word_1C1E/*32*/ && wMUT17_TPS_ADC8bit < word_1C20/*50*/ && enInjMask == 0xFFFF)
	{
		r13 = (wMUT72_Knock_Present & 2) ? 0 : 1;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FC2C()
{
	u16 r13 = 1;

	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || MUT21_RPM_x125div4 >= word_182E/*0*/)
	{
		r13 = 2;
	}
	else if (word_FFFF8BBA & 1)
	{
		r13 = 0;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FC5E()
{
	return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FC6A()
{
	return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FC76()
{
	u32 r13 = 2;

	if ((wMUT1E_MAF_RESET_FLAG & STALL) || wMUT10_Coolant_Temperature_Scaled != t1_unk_1C08/*80*/ || adc_CoolTemp_10bit_MUTCF <= COOLANT_TEMPERATURE_2BYTE_FFFF88A8)
	{
		word_FFFF8626 = word_1C06/*150*/ * 80;
	};

	// loc_1FCAC

	if (ZRO(wMUT1E_MAF_RESET_FLAG, STALL) && ZRO(word_FFFF90BC, 0x80) && wMUT10_Coolant_Temperature_Scaled > word_2598/*121*/)
	{
		CLR(word_FFFF8230, 4);
	};
	
	// loc_1FCD2
	
	if (wMUT71_Sensor_Error & MUT71_4_bit)
	{
		r13 = 0;
	}
	else if (wMUT71_Sensor_Error & MUT71_0_COOLANT)
	{
		if (word_FFFF854E >= word_1BF0/*4*/)
		{
			r13 = 0;

			if (wMUT07_CoolTemp_ADC8bit >= word_1BFE/*5*/)
			{
			};

			if (word_FFFF8718 == 0)
			{
				SET(wMUT71_Sensor_Error, MUT71_4_bit);
			};
		};
	}
	else if (ZRO(wMUT1E_MAF_RESET_FLAG, STALL))
	{
		if (word_FFFF8626 == 0)
		{
			r13 = 0;

			SET(word_FFFF8230, 4);
			SET(word_FFFF90BC, 0x80);
		}
		else if (wMUT10_Coolant_Temperature_Scaled > t1_unk_1C08/*80*/ && ZRO(word_FFFF8230, 4))
		{
			r13 = 1;
		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FDD6()
{
	u32 r13 = 1;

	if (wMUT71_Sensor_Error & MUT71_5_ALTERNATOR)
	{
		word_FFFF8718 = r13 = 0;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FDF2()
{
	u16 r13 = 2;

	if (ZRO(wMUTD1_BitMap_FAA, FAA_7_HIGH_IGN))
	{
		r13 = 1;
	}
	else if (KNOCK_FLAG_FFFF8C34 & KNOCK_FAULT_CHECK)
	{
		r13 = (wMUT72_Knock_Present & 1) ? 0 : 1;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FE22()
{
	if (ZRO(wMUT71_Sensor_Error, MUT71_1_IAT))
	{
		return 1;
	};

	if (wMUT3A_AirTemp_ADC8bit >= word_1C0E/*10*/)
	{

	};

	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FE5C()
{
	u32 r13 = 2;

	if (wMUT71_Sensor_Error & MUT71_11_bit)
	{
		r13 = 1;
	}
	else if (wMUT71_Sensor_Error & MUT71_9_bit)
	{
		word_FFFF8718 = r13 = 0;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FE8A()
{
	return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FE96()
{
	u16 r13 = 2;

	if (IGN_TEST_FLAG_1044/*0*/ == 0)
	{
		r13 = 1;
	}
	else if (ZRO(wMUT1E_MAF_RESET_FLAG, STALL) && ZRO(RT_FLAG1_FFFF8888, DRIVE_ALWAYS_1))
	{
		r13 = (IGN_MULT_FLAG_FFFF8DBC & 4) ? 0 : 1;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FECC()
{
	return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FED8()
{
	return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FEE4()
{
	return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FEF0()
{
	u16 r13 = 1;

	if (wMUTD1_BitMap_FAA & FAA_3_IMMO)
	{
		r13 = ((word_FFFF80FA & 0x80) || (faults_FFFF8ED2 >= word_1BEE/*10*/) || (word_FFFF8ED6 & 0x20)) ? 0 : 2;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static u16 EF07_sub_1FF2A()
{
	return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_1FF36()
{
	if (RT_FLAG1_FFFF8888 & FIX_TIMING)
	{
		wMUT47_Active_Fault_Lo = SwapBytes16(wMUT47_Active_Fault_Lo | 0x40);
		wMUT42_Stored_Faults_Lo_1 = SwapBytes16(wMUT42_Stored_Faults_Lo_1 | 0x40);
	}
	else
	{
		wMUT47_Active_Fault_Lo = SwapBytes16(wMUT47_Active_Fault_Lo & (~0x40));
		wMUT42_Stored_Faults_Lo_1 = SwapBytes16(wMUT42_Stored_Faults_Lo_1 & (~0x40));
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_1FF94()
{
	if (ZRO(wMUTD1_BitMap_FAA, FAA_15_8000))
	{
		wMUT36_Active_Fault_Count = 0;

		wMUT47_Active_Fault_Lo = SwapBytes16(wMUT47_Active_Fault_Lo & ~1);
		wMUT40_Stored_Faults_Lo = SwapBytes16(wMUT40_Stored_Faults_Lo & ~1);
	};

	// loc_1FFD8

	if (!AND(wMUTD1_BitMap_FAA, FAA_15_8000|FAA_2_REAR_O2_B2))
	{
		faults_FFFF80EC = 0;

		wMUT45_Stored_Faults_Lo_3 = SwapBytes16(wMUT45_Stored_Faults_Lo_3 & ~2);
		wMUT42_Stored_Faults_Lo_1 = SwapBytes16(wMUT42_Stored_Faults_Lo_1 & ~2);
	};

	// loc_20010

	if (!AND(wMUTD1_BitMap_FAA, FAA_15_8000|FAA_1_REAR_O2))
	{
		wMUT37_Stored_Fault_Count = 0;

		wMUT47_Active_Fault_Lo = SwapBytes16(wMUT47_Active_Fault_Lo & ~0x80);
		wMUT42_Stored_Faults_Lo_1 = SwapBytes16(wMUT42_Stored_Faults_Lo_1 & ~0x80);
	};

	// loc_20048

	if (!AND(wMUTD1_BitMap_FAA, FAA_15_8000|FAA_2_REAR_O2_B2|FAA_1_REAR_O2))
	{
		faults_FFFF80F0 = 0;

		wMUT45_Stored_Faults_Lo_3 = SwapBytes16(wMUT45_Stored_Faults_Lo_3 & ~0x10);
		wMUT40_Stored_Faults_Lo = SwapBytes16(wMUT40_Stored_Faults_Lo & ~0x10);
	};

	// loc_20080

	if ((wMUTD1_BitMap_FAA & FAA_3_IMMO) && (word_FFFF80FA & 0x80) && word_FFFF8100 == 0)
	{
		wMUT46_Stored_Faults_Hi_3 = SwapBytes16(wMUT46_Stored_Faults_Hi_3 & ~0x20);
		wMUT41_Stored_Faults_Hi = SwapBytes16(wMUT41_Stored_Faults_Hi & ~0x20);
	};

	// loc_20144

	wMUT45_Stored_Faults_Lo_3	= SwapBytes16(wMUT45_Stored_Faults_Lo_3);
	wMUT46_Stored_Faults_Hi_3	= SwapBytes16(wMUT46_Stored_Faults_Hi_3);
	wMUT47_Active_Fault_Lo		= SwapBytes16(wMUT47_Active_Fault_Lo);
	wMUT48_Active_Faults_Hi		= SwapBytes16(wMUT48_Active_Faults_Hi & 1);
	wMUT49_faults				= SwapBytes16(wMUT49_faults & 0);
	MUTD3_faults				= SwapBytes16(MUTD3_faults & 0);

	__disable_irq();

	if (MUT_VAR_9_FFFF8DFC & 0x80)
	{
		Init_Clear_active_faults();
	};

	if ((wMUTD1_BitMap_FAA & FAA_3_IMMO) && (MUT_VAR_9_FFFF8DFC & 2))
	{
		wMUT46_Stored_Faults_Hi_3 = SwapBytes16(wMUT46_Stored_Faults_Hi_3 & ~0x20);
		wMUT41_Stored_Faults_Hi = SwapBytes16(wMUT41_Stored_Faults_Hi & ~0x20);

		faults_FFFF8ED2 = 0;

		CLR(word_FFFF8ED6, 0x20);

		CLR(last_Drive_DTC[5], 0x20);
		CLR(current_DTC[5], 0x20);
		CLR(stored_DTC_5, 0x20);
	};

	// loc_20228

	CLR(MUT_VAR_9_FFFF8DFC, 0x82);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void Init_Clear_active_faults()
{
	u32 r0 = SwapBytes16(0);

	wMUT40_Stored_Faults_Lo = r0;

	wMUT41_Stored_Faults_Hi = r0;
	wMUT42_Stored_Faults_Lo_1 = r0;
	wMUT43_Stored_Faults_Hi_1 = r0;
	wMUT44_Stored_Faults_Lo_2 = r0;
	Stored_Faults_Hi_2 = r0;
	wMUT45_Stored_Faults_Lo_3 = r0;
	wMUT46_Stored_Faults_Hi_3 = r0;
	wMUT47_Active_Fault_Lo = r0;
	wMUT48_Active_Faults_Hi = r0;
	wMUT49_faults = r0;
	MUTD3_faults = r0;

	wMUT36_Active_Fault_Count = 0;
	faults_FFFF80EC = 0;
	wMUT37_Stored_Fault_Count = 0;
	faults_FFFF80F0 = 0;
	faults_FFFF80F2 = 0;
	faults_FFFF8ED2 = 0;
	CLR(word_FFFF8ED6, 0x20);
	faults_FFFF80F4 = 0;
	wMUT8D = 0;

	__disable_irq();

	CLR(word_FFFF8D80, 0xF);
	CLR(word_FFFF8D82, 0xF);

	__enable_irq();

	wMUT71_Sensor_Error = 0;

	CLR(word_FFFF80E6, 0x40);

	CLR(IGN_MULT_FLAG_FFFF8DBC, 4);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
static void EF07_sub_20308()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           
static void EF07_sub_204AC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
           

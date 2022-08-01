#include <machine.h>

#include "ram.h"
#include "misc.h"
#include "constword.h"

// Disable Front/Rear O2 heater check: clear bit 11 address 0xFCA

static void FeedBack_WBO2();
static void TimeRPM();
static void FeedBack_WBO2_v2();

static void FeedBack_O2F();
static void FeedBack_WBO2_O2F();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
#pragma noregsave(Test_Interpolate)

extern "C" void Test_Interpolate()
{
	Interpolate(65534, 0, 254);
	Interpolate(65534, 0, 1);

	Interpolate_my(65534, 0, 254);
	Interpolate_my(65534, 0, 1);

	interpolate_r4_r5_r6(65534, 0, 254);
	interpolate_r4_r5_r6(65534, 0, 1);

	interpolate_r4_r5_r6_my(65534, 0, 254);
	interpolate_r4_r5_r6_my(65534, 0, 1);

	interpolate_r4_r5_r6_my(0, 65534, 254);
	interpolate_r4_r5_r6_my(0, 65534, 1);





//	interpolate_r4_r5_r6(10, 20, 255);
//	interpolate_r4_r5_r6(10, 20, 0);


//	Interpolate_my(0, 65535, 255);

//	Interpolate_my(65535, 0, 255);
}
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregsave(LiveKnock)

extern "C" void LiveKnock()
{
//	__disable_irq();

//	F500_Init_Load_ECU_Info_And_BitMap_Flags();

	if (__DEADloc != 0xDEAD)
	{
		__DEADloc = 0xDEAD;

		hiIgnMapIndex = 0;	
		hiFuelMapIndex = 0;	
		veMapIndex = 0;	

		fixAFR = false;
		openLoop = false;
		forcedIdleRPM = 112;
		no_knock_retard = 0;

		knock_mul_high = 8;//t1_knock_control__17CC;
		knock_mul_low = 4;//t1_knock_control__17CE;

		wMUT27_Octane_Number = 255;
	};

	//if (openLoop)
	//{
	//	CLR(wMUTD1_BitMap_FAA, FAA_4_CLOSED_LOOP); // Closed loop
	//}
	//else
	//{
	//	SET(wMUTD1_BitMap_FAA, FAA_4_CLOSED_LOOP);  // Closed loop

	//	wMUT0C_Fuel_Trim_Low = 0x80;   
	//	wMUT0D_Fuel_Trim_Middle = 0x80;
	//	wMUT0E_Fuel_Trim_High = 0x80;
	//};

	//if (no_knock_retard != 0)
	//{
	//	CLR(wMUTD1_BitMap_FAA, FAA_7_HIGH_IGN); 
	//};

	//CLR(bMUTD3_BitMap4_FCA_Store_FFFF89D8, 0x808); // Disable Front/Rear O2 heater check: clear bit 11 address 0xFCA 

	//__enable_irq();
	
	frameCount += 1;

	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) == 0)
	{
		u32 al = ((u32)(swapb(axis_ig_LOAD)+128)>>8);
		u32 ar = ((u32)(swapb(axis_ig_RPM)+128)>>8);

		if ((frameCount&3) == 0 && hiIgnMapIndex == 15 && (KNOCK_FLAG_FFFF8C34 & KNOCK_RETARD_ENABLED) && ((wMUT72_Knock_Present & 1) == 0) && ar > 8 && al > 3 && wMUT17_TPS_ADC8bit >= TPS(11))
		{
			u32 ind = ar + al*21;

			u16 &p = hiIgnMapRAM[ind];

			u32 timing = p;

			i32 dt = wMUT06_Timing_Advance + 2 - wMUT33_Corrected_Timing_Advance;

			const u32 loign = hiIgnMapData[ind];
			const u32 hiign = (hiIgnMapStockData[ind]+20)*256;

			timing += dt;

			if (timing < loign)
			{
				timing = loign;
			}
			else if (timing > hiign)
			{
				timing = hiign;
			};

			p = timing;
		};

		FeedBack_WBO2_O2F();

		TimeRPM();

	}; // if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) == 0)

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FeedBack_WBO2_O2F)

static void FeedBack_WBO2_O2F()
{
	const byte LDT = 32;

	if (veMapIndex == 15 && wMUT4A_Purge_Control_Duty == 0 && (wMUT1E_MAF_RESET_FLAG & (DECELERATION_FUEL_CUT|FUEL_CUT|MAP_error)) == 0)
	{
		if (ve_timer == 0)
		{
			i16 d;
			
			if (wMUTD1_BitMap_FAA & FAA_4_CLOSED_LOOP)
			{
				d = ((u32)wMUT0F_Oxygen_Feedback_Trim >> 8) - 128;
			}
			else
			{
				fb_VE = d = Div_WW(32027, 125 + wMUT3C_Rear_O2_ADC8bit);

				if (d > AFR(18) && d < AFR(9))
				{
					d = wMUT32_Air_To_Fuel_Ratio - d;

					//if (d < -5) d = -5; else if (d > 5) d = 5;
				}
				else
				{
					d = 0;
				};
			};

			if (d != 0)
			{
				byte al = axis_ve_LOAD;
				byte ar = axis_ve_RPM;
				u32 ind = ar + al * 19;

				byte kl1 = (u32)axis_ve_LOAD >> 8;
				byte kr1 = (u32)axis_ve_RPM >> 8;

				byte kl0 = 255 - kl1;
				byte kr0 = 255 - kr1;

				i32	 kl0d = kl0 * d;
				i32	 kl1d = kl1 * d;

				if (al >= 10) 
				{
					kr1 = 0;
					kl1d = 0;
				}
				else if (ar >= 18)
				{
					kr1 = 0;
				};

				if (kl0d != 0)
				{
					if (kr0 != 0)
					{
						veMapRAM[ind] = Lim16(veMapRAM[ind] + (i16)((kr0 * kl0d) >> 16), VE16(118), VE16(40)); 
					};

					if (kr1 != 0)
					{
						veMapRAM[ind+1] = Lim16(veMapRAM[ind+1] + (i16)((kr1 * kl0d) >> 16), VE16(118), VE16(40));
					};
				};

				if (kl1d != 0)
				{
					if (kr0 != 0)
					{
						veMapRAM[ind+19] = Lim16(veMapRAM[ind+19] + (i16)((kr0 * kl1d) >> 16), VE16(118), VE16(40));
					};

					if (kr1 != 0)
					{
						veMapRAM[ind+20] = Lim16(veMapRAM[ind+20] + (i16)((kr1 * kl1d) >> 16), VE16(118), VE16(40));
					};
				};
			};

			ve_timer = LDT - ((u32)MUT21_RPM_x125div4 >> 3);
		}
		else
		{
			ve_timer -= 1;
		};
	}
	else
	{
		ve_timer = LDT;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(TimeRPM)

static void TimeRPM()
{
	static u16 timer;
	static byte pi;

	byte ar = (byte)axis_ig_RPM;

	if (ar > pi)
	{
		pi = ar;

		rpmTimeRAM[ar] = timer;
		timeRPM = timer;

		timer = 0;
	}
	else if (ar < 5)
	{
		pi = ar;

		timer = 0xFFFF;
	}
	else if (timer < 0xFFFF)
	{
		timer += 1;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
#pragma noregsave(FeedBack_WBO2_v2)

static void FeedBack_WBO2_v2()
{
//	static u16 timer;
//	static TM32 tm;
	static byte pi;
	const byte LDT = 200;
	

	if (veMapIndex == 15 && wMUT4A_Purge_Control_Duty == 0 && (wMUT1E_MAF_RESET_FLAG & (DECELERATION_FUEL_CUT|FUEL_CUT|MAP_error)) == 0)
	{
		u32	al = axis_ve_LOAD & 0xFF;
		u32 ar = axis_ve_RPM & 0xFF;
		u32 ind = ar + al * 19;

		//u32 kl = axis_ve_LOAD >> 8;
		//u32 kr = axis_ve_RPM >> 8;

		//u32 k00 = (255 - kr) * (255 - kl);
		//u32 k01 = kr * (255 - kl);
		//u32 k10 = (255 - kr) * kl;
		//u32 k11 = kr * kl;

		ve_index = ind;

		if (ind != pi || al >= 11 || ar >= 19)
		{
			ve_timer = LDT;
			pi = ind;
		}
		else if (ve_timer == 0)
		{
			i32 d = Div_WW(32027, 125 + wMUT3C_Rear_O2_ADC8bit);

			if (d > AFR(18) && d < AFR(9))
			{
				d -= wMUT32_Air_To_Fuel_Ratio;

				if (d < -5) d = -5; else if (d > 5) d = 5;

				if (d != 0)
				{
					byte kl1 = axis_ve_LOAD >> 8;
					byte kr1 = axis_ve_RPM >> 8;

					byte kl0 = 255 - kl1;
					byte kr0 = 255 - kr1;

					if (kl0 != 0)
					{
						if (kr0 != 0)
						{
							veMapRAM[ind] = Lim16(veMapRAM[ind] + ((u32)(kr0 * kl0 * d)) / 4096, VE16(118), VE16(40));
						};

						if (kr1 != 0)
						{
							veMapRAM[ind+1] = Lim16(veMapRAM[ind+1] + ((u32)(kr1 * kl0 * d)) / 4096, VE16(118), VE16(40));
						};
					};

					if (kl1 != 0)
					{
						if (kr0 != 0)
						{
							veMapRAM[ind+19] = Lim16(veMapRAM[ind+19] + ((u32)(kr0 * kl1 * d)) / 4096, VE16(118), VE16(40));
						};

						if (kr1 != 0)
						{
							veMapRAM[ind+20] = Lim16(veMapRAM[ind+20] + ((u32)(kr1 * kl1 * d)) / 4096, VE16(118), VE16(40));
						};
					};

					//u16 &p = veMapRAM[ind];

					//d = Lim32(Div_DW(p * wMUT32_Air_To_Fuel_Ratio, d), VE16(118), VE16(40));

					//fb_VE = d >> 8;

					//if (veMapIndex == 15) { p = d; };
				};
			};

			ve_timer = LDT;
		}
		else
		{
			ve_timer -= 1;
		};
	}
	else
	{
		ve_timer = LDT;
	};
}
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FeedBack_O2F)

static void FeedBack_O2F()
{
//	static u16 timer;
//	static TM32 tm;
//	static byte pi;
	const byte LDT = 20;

	if (veMapIndex == 15 && wMUT4A_Purge_Control_Duty == 0 && (wMUT1E_MAF_RESET_FLAG & (DECELERATION_FUEL_CUT|FUEL_CUT|MAP_error)) == 0)
	{
		if (ve_timer == 0)
		{
			i16 d = ((u32)wMUT0F_Oxygen_Feedback_Trim >> 8) - 128;

			fb_VE = d;

			if (d != 0)
			{
				byte al = axis_ve_LOAD;
				byte ar = axis_ve_RPM;
				u32 ind = ar + al * 19;

				byte kl1 = (u32)axis_ve_LOAD >> 8;
				byte kr1 = (u32)axis_ve_RPM >> 8;

				byte kl0 = 255 - kl1;
				byte kr0 = 255 - kr1;

				i32	 kl0d = kl0 * d;
				i32	 kl1d = kl1 * d;

				if (al >= 10) 
				{
					kr1 = 0;
					kl1d = 0;
				}
				else if (ar >= 18)
				{
					kr1 = 0;
				};

				if (kl0d != 0)
				{
					if (kr0 != 0)
					{
						veMapRAM[ind] = Lim16(veMapRAM[ind] + (i16)((kr0 * kl0d) >> 16), VE16(118), VE16(40)); 
					};

					if (kr1 != 0)
					{
						veMapRAM[ind+1] = Lim16(veMapRAM[ind+1] + (i16)((kr1 * kl0d) >> 16), VE16(118), VE16(40));
					};
				};

				if (kl1d != 0)
				{
					if (kr0 != 0)
					{
						veMapRAM[ind+19] = Lim16(veMapRAM[ind+19] + (i16)((kr0 * kl1d) >> 16), VE16(118), VE16(40));
					};

					if (kr1 != 0)
					{
						veMapRAM[ind+20] = Lim16(veMapRAM[ind+20] + (i16)((kr1 * kl1d) >> 16), VE16(118), VE16(40));
					};
				};
			};

			ve_timer = LDT;
		}
		else
		{
			ve_timer -= 1;
		};
	}
	else
	{
		ve_timer = LDT;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
u16 Interpolate_B16(u16 v1, u16 v2, u16 i)
{
	if (i >= 255)
	{
		return v2;
	};

	u32 r0 = i * 257 + (i >> 7);

	u32 r4 = (u32)v1 - (u32)v2;

	r0 *= r4;

	r0 += (u32)v2 << 16;
	r0 += 32768;

	return r0 >> 16;
}
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
u16 Interpolate(u16 v1, u16 v2, u16 i)
{
	bool r11 = false;

	if (i == 0)
	{
		return v1;
	};

	u32 r0 = 0xFF;

	if (i > r0)
	{
		return v2;
	};


	if (v1 > v2)
	{
		v2 = v1 - v2;
		r11 = true;
	}
	else
	{
		v2 -= v1;
	};

	r0 = Mul_Div_R(v2, i, 255);

	if (r11) r0 = -r0;

	return v1 + r0;
}
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
#pragma noregsave(FeedBack_WBO2)

static void FeedBack_WBO2()
{
	static u16 timer;
	static TM32 tm;
	static u16 prevLoad;
	
	u16 deltaLoad = 0;

	if (tm.Check(10))
	{
		deltaLoad = (wMUT1C_ECU_Load > prevLoad) ? (wMUT1C_ECU_Load - prevLoad) : (prevLoad - wMUT1C_ECU_Load);

		prevLoad = wMUT1C_ECU_Load;
	};

	if (veMapIndex == 15 && (wMUT1E_MAF_RESET_FLAG & (DECELERATION_FUEL_CUT|FUEL_CUT|MAP_error)) == 0 && deltaLoad <= kPa2load(1))
	{
		if (timer == 0)
		{
			u32	al = ((u32)(swapb((u32)axis_ve_LOAD)+127)>>8);
			u32 ar = ((u32)(swapb((u32)axis_ve_RPM)+127)>>8);

			if (al < 11 && ar < 19)
			{
				u16 *p = &veMapRAM[ar + al * 19];

				u32 ve = *p;

				i32 d = Div_WW(32027, 125 + wMUT3C_Rear_O2_ADC8bit);

				if (d > AFR(18) && d < AFR(9))
				{
					d -= wMUT32_Air_To_Fuel_Ratio;

					ve -= d * veFeedBackMul;

					if (ve < VE16(40))
					{
						ve = VE16(40);
					}
					else if (ve > VE16(118))
					{
						ve = VE16(118);
					};

					*p = ve;
				}
				else
				{
					timer = 100;
				};
			};
		}
		else
		{
			timer -= 1;
		};
	}
	else
	{
		timer = 100;
	};
}
*/

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


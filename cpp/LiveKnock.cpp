#include <umachine.h>

#include "ram.h"
#include "misc.h"

// Disable Front/Rear O2 heater check: clear bit 11 address 0xFCA

#pragma noregsave(FeedBack_WBO2)
static void FeedBack_WBO2();
static void TimeRPM();
static void FeedBack_WBO2_v2();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(LiveKnock)

extern "C" void LiveKnock()
{
	__disable_irq();

	F500_Init_Load_ECU_Info_And_BitMap_Flags();

	if (__DEADloc != 0xDEAD)
	{
		__DEADloc = 0xDEAD;

		hiIgnMapIndex = 15;	
		hiFuelMapIndex = 0;	
		veMapIndex = 7;	

		fixAFR = false;
		openLoop = true;
		forcedIdleRPM = 0;
	};

	if (openLoop)
	{
		CLR(wMUTD1_BitMap_FAA, 0x10); // Closed loop
	}
	else
	{
		wMUTD1_BitMap_FAA |= Periphery_FAA & 0x10; // Closed loop
	};

	CLR(bMUTD3_BitMap4_FCA_Store_FFFF89D8, 0x800); // Disable Front/Rear O2 heater check: clear bit 11 address 0xFCA 

	__enable_irq();

	
	frameCount += 1;




	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) == 0)
	{
		u32 al = ((u32)(swapb(axis_ig_LOAD)+128)>>8);
		u32 ar = ((u32)(swapb(axis_ig_RPM)+128)>>8);

		if (hiIgnMapIndex == 15 && (KNOCK_FLAG_FFFF8C34 & 0x40) && ((wMUT72_Knock_Present & 1) == 0) && ar > 7 && wMUT17_TPS_ADC8bit >= TPS(11))
		{
			u32 ind = ar + al*21;

			u16 &p = hiIgnMapRAM[ind];

			u32 timing = p;

			const u32 knock = wMUT26_Knock_Retard;

			if (knock > 3)
			{
				const u32 loign = (loIgnMapData[ind]+20)*256;

				timing = Sub_Lim_0(timing, knock>>2);

				p = (timing < loign) ? loign : timing;
			};
			//else 
			//{
			//	if (timing < hiIgnMapData[ind]) p = timing + 1;
			//};
		};

		FeedBack_WBO2_v2();

		TimeRPM();

	}; // if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) == 0)

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FeedBack_WBO2)

static void FeedBack_WBO2()
{
//	static u16 timer;
//	static TM32 tm;
	static byte pi;
	const byte LDT = 200;
	

	if ((wMUT1E_MAF_RESET_FLAG & (DECELERATION_FUEL_CUT|FUEL_CUT|MAP_error)) == 0)
	{
		u32	al = ((u32)(swapb((u32)axis_ve_LOAD)+128)>>8);
		u32 ar = ((u32)(swapb((u32)axis_ve_RPM)+128)>>8);
		u32 ind = ar + al * 19;

		ve_index = ind;

		if (ind != pi || al >= 11 || ar >= 19)
		{
			ve_timer = LDT;
			pi = ind;
		}
		else if (ve_timer == 0)
		{
			u32 d = Div_WW(32027, 125 + wMUT3C_Rear_O2_ADC8bit);

			if (d > AFR(18) && d < AFR(9))
			{
				u32 min = wMUT32_Air_To_Fuel_Ratio - 20;
				u32 max = wMUT32_Air_To_Fuel_Ratio + 20;

				if (d < min) d = min; else if (d > max) d = max;

				u16 &p = veMapRAM[ind];

				d = Lim32(Div_DW(p * wMUT32_Air_To_Fuel_Ratio, d), VE16(118), VE16(40));

				fb_VE = d >> 8;

				if (veMapIndex == 15) { p = d; };
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

#pragma noregsave(FeedBack_WBO2_v2)

static void FeedBack_WBO2_v2()
{
//	static u16 timer;
//	static TM32 tm;
	static byte pi;
	const byte LDT = 200;
	

	if ((wMUT1E_MAF_RESET_FLAG & (DECELERATION_FUEL_CUT|FUEL_CUT|MAP_error)) == 0)
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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
static void FeedBack_O2R()
{
	if ((wMUT1E_MAF_RESET_FLAG & (DECELERATION_FUEL_CUT|FUEL_CUT)) == 0 && veMapIndex == 15 
		&& wMUT32_Air_To_Fuel_Ratio > LAMBDA(0.98) && wMUT32_Air_To_Fuel_Ratio < LAMBDA(1.02))
	{
		u32	al = ((u32)(swapb((u32)axis_ve_LOAD)+127)>>8);
		u32 ar = ((u32)(swapb((u32)axis_ve_RPM)+127)>>8);

		if (al < 11 && ar < 19)
		{
			u16 *p = &veMapRAM[ar + al * 19];

			u32 ve = *p;

			i32 d = wMUT13_Front_O2_ADC8bit;  //wMUT3C_Rear_O2_ADC8bit;

			d -= OXIGEN(0.5);

			ve -= d/2;

			if (ve < VE16(20))
			{
				ve = VE16(20);
			}
			else if (ve > VE16(115))
			{
				ve = VE16(115);
			};

			*p = ve;
		};
	};
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


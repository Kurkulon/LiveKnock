#include <umachine.h>

#include "ram.h"
#include "misc.h"

// Disable Front/Rear O2 heater check: clear bit 11 address 0xFCA


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

				i32 d = Div_R4_R5_R0(32027, 125 + wMUT3C_Rear_O2_ADC8bit);

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

#pragma noregsave(FeedBack_WBO2)

static void FeedBack_WBO2()
{
//	static u16 timer;
//	static TM32 tm;
	static byte pi;
	const byte LDT = 200;
	

	if (veMapIndex == 15 && (wMUT1E_MAF_RESET_FLAG & (DECELERATION_FUEL_CUT|FUEL_CUT|MAP_error)) == 0)
	{
		u32	al = ((u32)(swapb((u32)axis_ve_LOAD)+128)>>8);
		u32 ar = ((u32)(swapb((u32)axis_ve_RPM)+128)>>8);
		u32 ind = ar + al * 19;

		ve_index = ind;

		if (ind != pi || al >= 11 || ar >= 19)
		{
			ve_timer == LDT;
			pi = ind;
		}
		else if (ve_timer == 0)
		{
			u32 d = Div_R4_R5_R0(32027, 125 + wMUT3C_Rear_O2_ADC8bit);

			if (d > AFR(18) && d < AFR(9))
			{
				u32 min = wMUT32_Air_To_Fuel_Ratio - 20;
				u32 max = wMUT32_Air_To_Fuel_Ratio + 20;

				if (d < min) d = min; else if (d > max) d = max;

				u16 &p = veMapRAM[ind];

				d = Lim_R4__R5_R6(Div_R4_R5w(p * wMUT32_Air_To_Fuel_Ratio, d), VE16(118), VE16(40));

				fb_VE = d >> 8; //p = d;
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
		veMapIndex = 15;	

		fixAFR = false;
		openLoop = true;
//		veFeedBackMul = 5;
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
			
			const u32 loign = (loIgnMapData[ind]+20)*256;

			u32 timing = p;

			const u32 knock = wMUT26_Knock_Retard;

			if (knock > 3)
			{
				timing = Sub_R4w_R5w_liml_0(timing, knock);

				p = (timing < loign) ? loign : timing;
			}
			else 
			{
				if (timing < 65*256) p = timing + 1;
			};
		};

		FeedBack_WBO2();

	}; // if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) == 0)

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


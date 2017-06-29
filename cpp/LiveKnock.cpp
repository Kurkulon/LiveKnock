#include <umachine.h>

#include "ram.h"
#include "misc.h"


//extern "C" void IG04_root_Update_Ignition();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 Lookup_HiIgnMap()
{
	return ((u32)(Table_Lookup_word_2D_3D(HighIgn_7C48[hiIgnMapIndex&7]) + 0x80)) >> 8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 GetLoadCorrectedDeltaTPS()
{
	return load_x2_deltaTPS_corrected = ECU_Load_x2_FFFF895C + R4_Mul_R5_Div_256_round(abs_Delta_TPS * TPS_Multiplier_Delta, Table_Lookup_byte_2D_3D(table_2D_39D2));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(IG04_Update_OctanEgrIgnTiming)

extern "C" u16 IG04_Update_OctanEgrIgnTiming()
{
	wMUTB4_lookup_value = GetLoadCorrectedDeltaTPS();

	Table_Lookup_Axis(RPM21_6788_IGN);

	Table_Lookup_Axis(LOAD12_67BC_IGN);

	ignition_FFFF8BC4 = egrHighOctIgn = Lookup_HiIgnMap();

	return octanEgrIgnTiming = interpolate_r4_r5_r6(egrHighOctIgn, egrLowOctIgn = Query_byte_2D_3D_Table(LowIgn_7C68), wMUT27_Octane_Number);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FU03_HI_LO_Octan)

extern "C" void FU03_HI_LO_Octan()
{
	wMUTB4_lookup_value = FU03_sub_142DC();

	Table_Lookup_Axis(RPM14_6746);

	Table_Lookup_Axis(LOAD9_676C);

	AFR_OctanInt = (fixAFR) ? AFR(14.7) : interpolate_r4_r5_r6(Table_Lookup_byte_2D_3D(HIGHOKTF_7A88[hiFuelMapIndex&7]), Query_byte_2D_3D_Table(LowOctFMp_7AA8), wMUT27_Octane_Number);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FU03_VE_map_sub_14620)

extern "C" void FU03_VE_map_sub_14620()
{
	Table_Lookup_Axis(RPM19_6CEE);

	Table_Lookup_Axis(LOAD11_6D1E);

	wMUT31_Volumetric_Efficiency = Table_Lookup_word_2D_3D(veMapArray[veMapIndex&7]) >> 8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(LiveKnock)

extern "C" void LiveKnock()
{
	if (__DEADloc != 0xDEAD)
	{
		__DEADloc = 0xDEAD;

		hiIgnMapIndex = 0;	
		hiFuelMapIndex = 0;	
		veMapIndex = 0;	

		fixAFR = false;
		openLoop = false;
		veFeedBackO2R = false;
	};

	frameCount += 1;


	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) == 0)
	{
		if (openLoop)
		{
			CLR(wMUTD1_BitMap_FAA, 0x10); // Closed loop
		}
		else
		{
			wMUTD1_BitMap_FAA |= Periphery_FAA & 0x10; // Closed loop
		};



		u32 al = ((u32)(swapb(axis_ig_LOAD)+127)>>8);

		if (hiIgnMapIndex == 7 && (KNOCK_FLAG_FFFF8C34 & 0x40) && ((wMUT72_Knock_Present & 1) == 0) && al > 4)
		{
			u32 ind = ((u32)(swapb(axis_ig_RPM)+127)>>8) + al*21;

			u16 *p = &hiIgnMapRAM[ind];
			
			const u32 loign = (loIgnMapData[ind]+20)*256;

			u32 timing = *p;

			const u32 knock = wMUT26_Knock_Retard;

			if (knock > 3)
			{
				timing -= knock >> 1;

				*p = (timing < loign) ? loign : timing;
			}
			else 
			{
				if (timing < 40*256) *p = timing + 1;
			};
		};


		if (/*openLoop && */veFeedBackO2R && veMapIndex == 7 && wMUT32_Air_To_Fuel_Ratio > LAMBDA(0.98) && wMUT32_Air_To_Fuel_Ratio < LAMBDA(1.02))
		{
			u32	al = ((u32)(swapb((u32)axis_ve_LOAD)+127)>>8);
			u32 ar = ((u32)(swapb((u32)axis_ve_RPM)+127)>>8);

			if (al < 11 && ar < 19)
			{
				u16 *p = &veMapRAM[ar + al * 19];

				u32 ve = *p;

				i32 d = wMUT13_Front_O2_ADC8bit;  //wMUT3C_Rear_O2_ADC8bit;

				d -= OXIGEN(0.5);

				ve -= d/4;

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
	}; // if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) == 0)

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


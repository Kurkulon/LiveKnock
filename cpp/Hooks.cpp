#pragma section _Hooks

#include <umachine.h>

#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "misc.h"

#define CEL7_692E							((Axis*)0x692E)

#define CORFUELAIR_33A6						((Map3D_B *)0x33A6)

#define F500_Update_Air_Temp_Scaled	((void(*)(void))0x1014A)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 Lookup_HiIgnMap()
{
	return ((u32)(Table_Lookup_word_2D_3D(HighIgn_7C48[hiIgnMapIndex&7]) + 0x80)) >> 8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 GetLoadCorrectedDeltaTPS()
{
	return load_x2_deltaTPS_corrected = ECU_Load_x2_FFFF895C + Mul_Fix8_R(abs_Delta_TPS * TPS_Multiplier_Delta, Table_Lookup_byte_2D_3D(table_2D_39D2));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(IG04_Update_OctanEgrIgnTiming)

extern "C" u16 IG04_Update_OctanEgrIgnTiming()
{
	wMUTB4_lookup_value = GetLoadCorrectedDeltaTPS();

	Table_Lookup_Axis(RPM21_6788_IGN);

	Table_Lookup_Axis(LOAD12_67BC_IGN);

	ignition_FFFF8BC4 = egrHighOctIgn = Lookup_HiIgnMap();

	return octanEgrIgnTiming = interpolate_r4_r5_r6(egrHighOctIgn, egrLowOctIgn = Query_byte_2D_3D_Table(LowIgn_7C68), (no_knock_retard != 0) ? 255 : wMUT27_Octane_Number);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FU03_HI_LO_Octan)

extern "C" void FU03_HI_LO_Octan()
{
	wMUTB4_lookup_value = FU03_sub_142DC();

	Table_Lookup_Axis(RPM14_6746);

	Table_Lookup_Axis(LOAD9_676C);

	AFR_OctanInt = (fixAFR) ? AFR(14.7) : interpolate_r4_r5_r6(Table_Lookup_byte_2D_3D(HIGHOKTF_7A88[hiFuelMapIndex&7]), Query_byte_2D_3D_Table(LowOctFMp_7AA8), (no_knock_retard != 0) ? 255 : wMUT27_Octane_Number);

																//	8,  33,  49,  63,  78,  96, 125				
	k_InAirTemp = Table_Lookup_byte_2D_3D(&kAirMapRAM) >> 8;	// 143, 136, 132, 128, 125, 122, 118
																//			, 1.252, 1.192, 

	//EVO
	//   8,  33,  49,  63,  78,  96, 125, 155
	// 158, 143, 135, 129, 122, 115, 106, 106
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

#pragma noregsave(Hook_ForcedIdleRPM)

extern "C" u16 Hook_ForcedIdleRPM(u16 v)
{
	return (forcedIdleRPM != 0) ? forcedIdleRPM : v;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma section _Hooks

#include <umachine.h>

#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "misc.h"

#define CEL7_692E							((Axis*)0x692E)
#define mapInletAirTemp_Scaling				((Axis*)0x9B82)
#define BAR5_6D66							((Axis*)0x6D66)

#define CORFUELAIR_33A6						((Map3D_B *)0x33A6)
#define byte_9B00							((Map3D_B *)0x9B00)
#define unk034_3EFA							((Map3D_B *)0x3EFA)

//#define F500_Update_Air_Temp_Scaled	((void(*)(void))0x1014A)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 Lookup_HiIgnMap()
{
#ifdef DEF_IGNMAP16
	return ((u32)(Table_Lookup_word_2D_3D(HighIgn_7C48[hiIgnMapIndex&7]) + 0x80)) >> 8;
#else
	return Table_Lookup_byte_2D_3D(HighIgn_7C48[hiIgnMapIndex&7]);
#endif
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
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FU03_VE_map_sub_14620)

extern "C" void FU03_VE_map_sub_14620()
{
	Table_Lookup_Axis(RPM19_6CEE);

	Table_Lookup_Axis(LOAD11_6D1E);

	#ifdef DEF_VEMAP16
		wMUT31_Volumetric_Efficiency = Table_Lookup_word_2D_3D(veMapArray[veMapIndex&7]) >> 8;
	#else
		wMUT31_Volumetric_Efficiency = Table_Lookup_byte_2D_3D(veMapArray[veMapIndex&7]);
	#endif

	//__k_trimVE = Table_Lookup_word_2D_3D((__DEADloc != 0xDEAD) ? &trimVeMap : &trimVeMapRAM);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(Hook_ForcedIdleRPM)

extern "C" u16 Hook_ForcedIdleRPM(u16 v)
{
	return (forcedIdleRPM != 0) ? forcedIdleRPM : v;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregalloc(FU03_sub_149E0_Hook)

//extern "C" void FU03_sub_149E0_Hook()
//{
////	u32 r9 = enrichmentWarmUp;
//	//u32 r8 = word_FFFF8AB0 << 16; //Mult_R4_65536(word_FFFF8AB0/*406*/); // 26607616
//
//	TRG(ZERO_8_IGNITION_FLAGS, 0x20, wMUT15_Barometric_Pressure, word_1772/*189(94.5)*/, word_1772/*189(94.5)*/ + word_1774/*3*/);
//
//	u32 r2 = 0x80;
//
//	if (ZRO(ZERO_8_IGNITION_FLAGS, 0x20))
//	{
//		Table_Lookup_Axis(BAR5_6D66);				// 125,141,157,173,189
//		r2 = Table_Lookup_byte_2D_3D(unk034_3EFA);	// 151,142,140,136,130
//	};
//
//	u32 r0 = Mul32_Fix8(word_FFFF8AB0 << 16, Add_Lim_FFFF(wMUT31_Volumetric_Efficiency/*210(82)*/, word_1524/*48(18.75)*/)); // 26815488
//
//	r0 = Mul_Fix30(r0, __k_trimVE * __k_AirMult);
//
//	r0 = Mul32_Fix14(r0, k_InAirTemp/*128*/ * r2/*128*/); //Mul_DW_Div(r0, k_InAirTemp/*128*/ * r2/*128*/, 0x4000); // 26815488
//
//	r0 = Mul32_Fix14(r0, fuelTrim_FFFF8ADC/*128*/ * enrichmentWarmUp/*128*/);//Mul_DW_Div(r0, fuelTrim_FFFF8ADC/*128*/ * enrichmentWarmUp/*128*/, 0x4000); // 26815488
//
//	r0 = Mul32_Fix7(r0, (word_FFFF8AEE/*0*/ << 1) + 0x80);  // 26815488
//
//	r0 = Mul32_Fix7(r0, fuelTrim_FFFF8AE4/*128*/); // 26815488
//
//	bMUTC7 = Mul32_Fix23(r0, wMUT32_Air_To_Fuel_Ratio/*150(12.5)*/); // 31424400 
//
//	//bMUTC7 = Div_65536_R(r0); // 479
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregsave(Hook_Update_IAT_Sensor)
//
//extern "C" void Hook_Update_IAT_Sensor()
//{
//	WFLAG(wMUT71_Sensor_Error, MUT71_1_IAT, wMUT3A_AirTemp_ADC8bit < word_1C0E/*10*/ || wMUT3A_AirTemp_ADC8bit > word_1C0C/*234*/);
//
//	//F500_Update_Air_Temp_Scaled();
//	
//	Table_Lookup_Axis(mapInletAirTemp_Scaling);
//
//	inletAirTempScaledInternal = Table_Lookup_byte_2D_3D(byte_9B00);
//
//	wMUT11_Intake_Air_Temperature_Scaled = (wMUT71_Sensor_Error & MUT71_1_IAT) ? IAT_sensor_err_val/*84*/ : inletAirTempScaledInternal;
//
//
//	Table_Lookup_Axis(CEL7_692E);
//														//		 8,  33,  49,  63,  78,  96, 125				
//	k_InAirTemp = Table_Lookup_byte_2D_3D(CORFUELAIR_33A6);	// 143, 136, 132, 128, 125, 122, 118
//															//			, 1.252, 1.192, 
//
//	//EVO
//	//   8,  33,  49,  63,  78,  96, 125, 155
//	// 158, 143, 135, 129, 122, 115, 106, 106
//
//	if (timer_down_TXFLAG3_FFFF8574 == 0 && (SPEED_FLAGS & 0x400))
//	{
//		NVRAM_Intake_Air_Temperature_Scaled = wMUT11_Intake_Air_Temperature_Scaled;
//	};
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

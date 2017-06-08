#ifndef MISC_H__26_04_2016__22_59
#define MISC_H__26_04_2016__22_59

#include "types.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma pack 1

struct IndexResult
{
	byte interpolator;
	byte index;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Axis
{
	IndexResult	*result; 
	u16			*value;

	u16 		len;
	i16 		data[2];
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Map3D_B
{
	byte type; // 2 - 2D, 3 - 3D
	byte add;

	u16 *ptrRowInd;
	u16 *ptrColInd;

	byte rowLen;

	i8 data[4];
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Map3D_W
{
	u16 type; // 2 - 2D, 3 - 3D
	u16	add;

	u16 *ptrRowInd;
	u16 *ptrColInd;

	u16 rowLen;

	i16 data[4];
};

#pragma unpack

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define Tephra ((void(*)(void))0x3ec00)
#define sub_A98A ((void(*)(void))0xA98A)

#define Table_Lookup_byte_2D_3D ((u16(*)(Map3D_B*))0xC28)
#define Table_Lookup_word_2D_3D ((u16(*)(Map3D_W*))0xE02)


#define IG04_GetLoadCorrectedDeltaTPS					((u16(*)(void))0x181DC)
#define Table_Lookup_Axis								((void(*)(Axis*))0xCC6)
#define Query_byte_2D_3D_Table							((u16(*)(Map3D_B**))0xDE0)
#define Add_R4w_R5w_Lim_FFFF							((u16(*)(u16,u16))0x500)
#define interpolate_r4_r5_r6							((u16(*)(u16,u16,u16))0xB16)
#define Sub_R4w_R5w_liml_0								((u16(*)(u16,u16))0xF0C)
#define Lim_R4_max_FF									((u16(*)(u16))0x590)
#define R4_Mul_R5_Div_256_round							((u16(*)(u16,u16))0x804)

#define FU03_sub_142DC									((u16(*)(void))0x142DC)

#define IG04_GetLoad_sub_1821E							((u16(*)(void))0x1821E)


#define __disable_irq ((void(*)(void))0x400)
#define __enable_irq ((void(*)(void))0x41e)

//#pragma address wMUT26_Knock_Sum=0xFFFF8C32
//static u16 wMUT26_Knock_Sum;

#define wMUTB4_lookup_value								(*(u16*)0xFFFF8836)
#define RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888		(*(u16*)0xFFFF8888)
#define ZERO_8_IGNITION_FLAGS							(*(u16*)0xFFFF8A0C)
#define egrLowOctIgn									(*(u16*)0xFFFF8BC0)
#define egrHighOctIgn									(*(u16*)0xFFFF8BC2)
#define octanEgrIgnTiming								(*(u16*)0xFFFF8BC8)
#define ignition_FFFF8BC4								(*(u16*)0xFFFF8BC4)
#define abs_Delta_TPS									(*(u16*)0xFFFF8BE2)
#define TPS_Multiplier_Delta							(*(u16*)0x17A4)
#define load_x2_deltaTPS_corrected						(*(u16*)0xFFFF8BDA)
#define ECU_Load_x2_FFFF895C							(*(u16*)0xFFFF895C)



#define RPM21_6788_IGN									((Axis*)0x6788)
#define LOAD12_67BC_IGN									((Axis*)0x67BC)
#define LowIgn_7C68										((Map3D_B**)0x7C68)
#define LOWOCTIGNEGR_7AC8								((Map3D_B**)0x7AC8)
#define HIOCTIGNEGR_38CA								((Map3D_B*)0x38CA)
#define table_2D_39D2									((Map3D_B*)0x39D2)


extern Map3D_B* HighIgn_7C48[8];		//#define HighIgn_7C48	((void*)0x7C48)

#define RPM14_6746										((Axis*)0x6746)
#define LOAD9_676C										((Axis*)0x676C)
#define LowOctFMp_7AA8									((Map3D_B**)0x7AA8)

extern Map3D_B* HIGHOKTF_7A88[8];		//#define HIGHOKTF_7A88	((void*)0x7A88)
extern Map3D_B* veMapArray[8];		

#define AFR_OctanInt									(*(u16*)0xFFFF8ACA)

#define RPM19_6CEE										((Axis*)0x6CEE)
#define LOAD11_6D1E										((Axis*)0x6D1E)
#define bMUTD3_BitMap4_FCA_Store_FFFF89D8				(*(u16*)0xFFFF89D8)
#define EGRONOFF_103D									(*(const byte*)0x103D)
#define VE1Map_3032										((Map3D_B*)0x3032)
#define VE2Map_310E										((Map3D_B*)0x310E)
#define VE3Map_31EA										((Map3D_B*)0x31EA)

#define sub_21BC4										((u16(*)(u16))0x21BC4)


#define wMUT26_Knock_Sum						(*(u16*)0xFFFF8C32)
#define wMUT27_Octane_Number					(*(u16*)0xFFFF80B8)
#define wMUT31_Volumetric_Efficiency			(*(u16*)0xFFFF8AB8)

//#define wMUT1C_ECU_Load					(*(u16*)0xFFFF8952)
//#define	wMUT06_Timing_Advance			(*(u16*)0xFFFF8BDC)
//#define	wMUT33_Corrected_Timing_Advance	(*(u16*)0xFFFF8BBE)
//#define	MUT21_RPM_x125div4				(*(u16*)0xFFFF8944)
#define	wMUTD1_BitMap_FAA				(*(u16*)0xFFFF89D4)
#define	KNOCK_FLAG_FFFF8C34				(*(u16*)0xFFFF8C34) // 0x40 - enabled knock retard;
//#define	wMUT04_Timing					(*(u16*)0xFFFF8BBC) // wMUT04_Timing_Advance_Interpolated
//#define	wMUT1E_MAF_RESET_FLAG			(*(u16*)0xFFFF89F4) 
#define	wMUT72_Knock_Present			(*(u16*)0xFFFF89E6) // 1 - ? Knock sensor fault;


#define SAR3							(*(void**)0xFFFFecf0)
#define DAR3							(*(void**)0xFFFFecf4)
#define DMATCR3							(*(u32*)0xFFFFecf8)
#define CHCR3							(*(u32*)0xFFFFecfc)

#define DMAOPFLAG						(*(u32*)0xFFFF8480)
#define DMAOPFLAG2						(*(u32*)0xFFFF8484)
#define DMAaddress						(*(void**)0xFFFF8488)
#define DMAlength						(*(u16*)0xFFFF848c)

#define serialreceivewithoutdma			((void(*)(void))0xD34A)	/*TO BE CHANGED FOR EACH ROM*/
#define bit7allowslogging				(*(u16*)0xFFFF8E42)
#define mutorobd						(*(u16*)0xFFFF8E08)
#define receive_transmit_status_bits	(*(u16*)0xFFFF8E3E) 	/*TO BE CHANGED FOR EACH ROM*/
#define mut_timeout						(*(u16*)0xFFFF8EAC) 	/*TO BE CHANGED FOR EACH ROM*/

#define SCR0							(*(byte*)0xFFFFf002)
#define TDR0							(*(byte*)0xFFFFf003)
#define SSR0							(*(byte*)0xFFFFf004)
#define RDR0							(*(byte*)0xFFFFf005)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define __byte_FFFF8400					(*(byte*)0xFFFF8400) // 1 - Alt maps
//#define hiIgnMapIndex					(*(byte*)0xFFFF8401) // 0..7
//#define hiFuelMapIndex					(*(byte*)0xFFFF8402) // 0..7
//#define veMapIndex						(*(byte*)0xFFFF8403) // 0..7

extern byte _byte_FFFF8400;
extern byte hiIgnMapIndex;					
extern byte hiFuelMapIndex;					
extern byte veMapIndex;						


//#define __axis_res_RPM25				(*(u16*)0xFFFF8460)
//#define __axis_res_LOAD30				(*(u16*)0xFFFF8462)

extern u16 axis_ig_RPM;	
extern u16 axis_ig_LOAD;	
extern u16 axis_fu_RPM;	
extern u16 axis_fu_LOAD;	
extern u16 axis_ve_RPM;	
extern u16 axis_ve_LOAD;	

#define __DEADloc						(*(u16*)0xFFFFA800)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define romHiIgnMap						(*(Map3D_W*)0x38d42)

#define ramHiIgnMap						(*(Map3D_W*)0xFFFFA000)

#define kPa2load(v) (v*2)

#define rpm2mut(v) (v*4/125)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif // MISC_H__26_04_2016__22_59

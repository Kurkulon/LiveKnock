#ifndef MISC_H__26_04_2016__22_59
#define MISC_H__26_04_2016__22_59

#include "types.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma pack 4

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

	u16 ptrRowIndHi;
	u16 ptrRowIndLo;

	union
	{
		struct
		{
			i8 data[8];
		} m2d;

		struct
		{
			u16 ptrColIndHi;
			u16 ptrColIndLo;

			byte rowLen;

			i8 data[3];
		} m3d;
	};
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Map3D_W
{
	u16 type; // 2 - 2D, 3 - 3D
	u16	add;

	u16 ptrRowIndHi;
	u16 ptrRowIndLo;
	u16 ptrColIndHi;
	u16 ptrColIndLo;

	u16 rowLen;

	i16 data[4];
};

#pragma unpack

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define CRANKING				0x01 
#define MAP_error				0x02
#define DECELERATION_FUEL_CUT	0x04
#define FUEL_CUT				0x08
#define STALL					0x10
#define CLOSED_LOOP_GENERIC		0x80

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define Tephra ((void(*)(void))0x3ec00)
#define sub_A98A ((void(*)(void))0xA98A)

#define Table_Lookup_byte_2D_3D ((u16(*)(Map3D_B*))0xC28)
#define Table_Lookup_word_2D_3D ((u32(*)(Map3D_W*))0xE02)

#define Table_Lookup_Axis								((void(*)(Axis*))0xCC6)
#define Query_byte_2D_3D_Table							((u32(*)(Map3D_B**))0xDE0)

#define GET_FROM_MASSIVE_byte							((u32(*)(const byte*))0xDC6)
#define GET_LOC_DIM_sub_DF6								((u32(*)(void*))0xDF6)


#define Lim_R4_max_FF									((u32(*)(u16))0x590)
#define sub_21E14										((u16(*)(u16))0x21E14)
#define Trunc_R4_byte_R0								((u16(*)(u32))0x864)

#define Add_R4w_R5w_Lim_FFFF							((u32(*)(u16,u16))0x500)
#define Sub_R4w_R5w_liml_0								((u32(*)(u16,u16))0xF0C)
#define R4_Mul_R5_Div_256_round							((u32(*)(u16,u16))0x804)
#define Div_R4_R5_R0									((u32(*)(u16,u16))0x9B0)
#define Div_R4_R5w										((u32(*)(u32,u16))0x902)
#define Mul_R4w_R5w_Div_128_Round_Into_R0				((u32(*)(u16,u16))0x762)

#define interpolate_r4_r5_r6							((u16(*)(u16,u16,u16))0xB16)
#define Lim16_R4w__R5_R6								((u32(*)(u16, u16 max, u16 min))0x5A8)
#define Lim_R4__R5_R6									((u32(*)(u32 v, u32 max, u32 min))0x5B0)
#define MUL_R4w_R5w_DIV_R6w_Round_R0					((u32(*)(u16,u16,u16))0x68A)

#define R4_Complex_Into_R0_sub_898						((u16(*)(u32))0x898)
#define Add_R4_R5_Lim_FFFFFFFF							((u32(*)(u32,u32))0x51C)



#define FU03_sub_142DC									((u16(*)(void))0x142DC)

#define __disable_irq									((void(*)(void))0x400)
#define __enable_irq									((void(*)(void))0x41e)
#define F500_Init_Load_ECU_Info_And_BitMap_Flags		((void(*)(void))0xF58C)

#define Timer_Counter_Related_sub_C928					((void(*)(void))0xC928)
#define Knock_Output_Calc_sub_AC96						((void(*)(void))0xAC96)

#define sub_21E84										((bool(*)(void))0x21E84)
#define BC06_sub_1E2D0									((void(*)(void))0x1E2D0)
#define PEDR_LO_Check_sub_A790							((bool(*)(void))0xA790)
	


#define RPM21_6788_IGN									((Axis*)0x6788)
#define LOAD12_67BC_IGN									((Axis*)0x67BC)
#define LowIgn_7C68										((Map3D_B**)0x7C68)
#define LOWOCTIGNEGR_7AC8								((Map3D_B**)0x7AC8)
#define HIOCTIGNEGR_38CA								((Map3D_B*)0x38CA)
#define table_2D_39D2									((Map3D_B*)0x39D2)


extern Map3D_W* HighIgn_7C48[8];		//#define HighIgn_7C48	((void*)0x7C48)

#define RPM14_6746										((Axis*)0x6746)
#define LOAD9_676C										((Axis*)0x676C)
#define LowOctFMp_7AA8									((Map3D_B**)0x7AA8)

extern Map3D_B* HIGHOKTF_7A88[8];		//#define HIGHOKTF_7A88	((void*)0x7A88)
extern Map3D_W* veMapArray[8];		

#define AFR_OctanInt									(*(u16*)0xFFFF8ACA)

#define RPM19_6CEE										((Axis*)0x6CEE)
#define LOAD11_6D1E										((Axis*)0x6D1E)
//#define bMUTD3_BitMap4_FCA_Store_FFFF89D8				(*(u16*)0xFFFF89D8)
#define EGRONOFF_103D									(*(const byte*)0x103D)
#define VE1Map_3032										((Map3D_B*)0x3032)
#define VE2Map_310E										((Map3D_B*)0x310E)
#define VE3Map_31EA										((Map3D_B*)0x31EA)

#define sub_21BC4										((u16(*)(u16))0x21BC4)
#define sub_21E4C										((u16(*)(u16))0x21E4C)

#define Periphery_FAA									(*(const u16*)0xFAA)




#define CEL8_7100						((Axis*)0x7100)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define __byte_FFFF8400					(*(byte*)0xFFFF8400) // 1 - Alt maps
//#define hiIgnMapIndex					(*(byte*)0xFFFF8401) // 0..7
//#define hiFuelMapIndex					(*(byte*)0xFFFF8402) // 0..7
//#define veMapIndex						(*(byte*)0xFFFF8403) // 0..7

extern byte _byte_FFFF8400;
extern byte hiIgnMapIndex;					
extern byte hiFuelMapIndex;					
extern byte veMapIndex;						
extern byte fixAFR;						
extern byte openLoop;						
extern byte veFeedBackMul;						


//#define __axis_res_RPM25				(*(u16*)0xFFFF8460)
//#define __axis_res_LOAD30				(*(u16*)0xFFFF8462)

extern u16 axis_ig_RPM;	
extern u16 axis_ig_LOAD;	
extern u16 axis_fu_RPM;	
extern u16 axis_fu_LOAD;	
extern u16 axis_ve_RPM;	
extern u16 axis_ve_LOAD;	
extern byte ve_index;	
extern byte ve_timer;	
extern byte fb_VE;	
extern u32 frameCount;

extern byte hiFuelMapRAM[];
extern u16	hiIgnMapRAM[];
extern u16	veMapRAM[];
extern const u16 hiIgnMapData[];

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct TM32
{
	u32 pt;

	bool Check(u32 v) { if ((frameCount - pt) >= v) { pt = frameCount; return true; } else { return false; }; }
	void Reset() { pt = frameCount; }
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define __DEADloc						(*(u16*)0xFFFFA800)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define loIgnMapData						((const i8*)0x05413)

#define array_OctanNum						((const byte*)0x3AAA)

//#define romHiIgnMap						(*(Map3D_W*)0x38d42)

//#define ramHiIgnMap						(*(Map3D_W*)0xFFFFA000)

#define kPa2load(v) (v*2)

#define rpm2mut(v) (v*4/125)

#define TPS(v) ((u32)(v*255/100+0.5))

#define AFR(v) ((u32)(14.7*128/v+0.5))
#define WB02(v) ((u32)((v-7.35)*255/(22.39-7.35)+0.5))

#define LAMBDA(v) ((u32)(128*v+0.5))

#define OXIGEN(v) ((u32)(v/0.0195+0.5))

#define VE8(v)	((u32)(v*2.56-48))
#define VE16(v) ((u32)((v*2.56-48)*256))

#define SET(v, m) (v |= m)
#define CLR(v, m) (v &= ~m)

#define TRG(f, m, v, l, h) { if (f & m) { if (v <= l) { CLR(f, m);	}; } else {	if (v > h) { SET(f, m);	};};}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif // MISC_H__26_04_2016__22_59

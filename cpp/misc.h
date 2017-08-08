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
#define REVLIM					0x20
#define CLOSED_LOOP_GENERIC		0x80
#define IDLE					0x1000


#define POWER_STEERING			0x08
#define AC_SWITCH				0x10
#define STARTER					0x40
#define SPEED_ADJUST			0x800
#define FIX_TIMING				0x1000

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define Tephra ((void(*)(void))0x3ec00)
#define sub_A98A ((void(*)(void))0xA98A)

#define Table_Lookup_byte_2D_3D ((u16(*)(Map3D_B*))0xC28)
#define Table_Lookup_word_2D_3D ((u32(*)(Map3D_W*))0xE02)

#define Table_Lookup_Axis								((void(*)(Axis*))0xCC6)
#define Query_byte_2D_3D_Table							((u32(*)(Map3D_B**))0xDE0)

#define GET_FROM_MASSIVE_byte							((u32(*)(const byte*))0xDC6)
#define GET_LOC_DIM_sub_DF6								((u32(*)(void*))0xDF6)


#define Lim_FF											((u32(*)(u16))0x590)
#define Lim_FFFF										((u32(*)(u32))0x598)
#define sub_21E14										((u16(*)(u16))0x21E14)
#define SHLR8											((byte(*)(u32))0x864)
#define Mult_R4_65536									((u32(*)(u16))0x876)

#define Add_Lim_FFFF									((u32(*)(u16,u16))0x500)
#define Add_Lim_FFFFFFFF								((u32(*)(u32,u32))0x51C)
#define Add_R4w_R5w										((u32(*)(u16,u16))0x514)
#define Sub_Lim_0										((u32(*)(u16,u16))0xF0C)
#define Mul_Fix8_R										((u32(*)(u16,u16))0x804)
#define Div_WW											((u32(*)(u16,u16))0x9B0)
#define Div_DW											((u32(*)(u32,u16))0x902)
#define DIV_DW_R										((u32(*)(u32,u16))0x9F2)
#define Div_R4_R5__R0									((u16(*)(u16,u16))0x8C4)
#define Mul_Fix7_R										((u32(*)(u16,u16))0x762)
#define Mul_DW_Div										((u32(*)(u32,u16,u16))0x5E8)
#define Mul_Div											((u32(*)(u16,u16,u16))0x5D0)
#define Mul32_Fix8										((u32(*)(u32,u16))0x7E6)
#define Mul_R4_R5w_Div_128_Into_R0						((u32(*)(u32,u16))0x780)
#define Mul_R4_R5_Div_128_Into_R0						((u32(*)(u16,u16))0x752)
#define Mul16											((u32(*)(u16,u16))0xEEE)
#define Mul_Lim_FFFF									((u32(*)(u16,u16))0xED8)
#define Mul_Fix8_Lim_FFFF								((u32(*)(u16,u16))0x7D0)
#define Mul32_lim										((u32(*)(u32,u32))0xEF8)
#define Mul_R4_R5w_Div_128_Round_R0						((u32(*)(u32,u16))0x7A6)

#define mem_incr										((void(*)(void*,void*))0x562)
#define mem_decr										((void(*)(void*,void*))0x53E)
#define memsetz											((void(*)(void*,void*))0x52C)

#define interpolate_r4_r5_r6							((u16(*)(u16,u16,u16))0xB16)
#define Lim16											((u32(*)(u16, u16 max, u16 min))0x5A8)
#define Lim32											((u32(*)(u32 v, u32 max, u32 min))0x5B0)
#define Mul_Div_R										((u32(*)(u16,u16,u16))0x68A)

#define Div_65536_R										((u16(*)(u32))0x898)

#define Interpolate_256									((u16(*)(u16,u16,u16))0xAB8)
#define Div_256_R										((byte(*)(u16))0x87C)


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


#define RPM5_6830										((Axis*)0x6830)
#define VOLT7_6844_Throttle								((Axis*)0x6844)

#define TEMPCOMP_3BEE									((Map3D_B*)0x3BEE)
#define LIMPHOME_33F4									((Map3D_B*)0x33F4)






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
#define sub_21CA8										((u16(*)(u16))0x21CA8)

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
extern byte forcedIdleRPM;	
extern u32 frameCount;
extern u16 timeRPM;	

extern byte hiFuelMapRAM[];
extern u16	hiIgnMapRAM[];
extern u16	veMapRAM[];
extern u16	rpmTimeRAM[];
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

#define ONE(v, m) ((v & m) != 0)
#define ZRO(v, m) ((v & m) == 0)

#define WBIT(v, m, c) { v &= ~m; if (c) v |= m; }


#define INCLIM(v) { if (v < 0xFFFF) {v += 1;}; }
#define DECLIM(v) { if (v != 0) {v -= 1;}; }


#define ABSDIF(a, b) (((a) >= (b)) ? ((a) - (b)) : ((b) - (a)))

#define TRG(f, m, v, l, h) { if (f & m) { if (v <= l) { CLR(f, m);	}; } else {	if (v > h) { SET(f, m);	};};}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif // MISC_H__26_04_2016__22_59

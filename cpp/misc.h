#ifndef MISC_H__26_04_2016__22_59
#define MISC_H__26_04_2016__22_59

#include "types.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#pragma pack 1

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

//#define Table_Lookup_byte_2D_3D ((u8(*)(Map3D_B*))0xC28)
#define Table_Lookup_word_2D_3D ((u16(*)(Map3D_W*))0xE02)


#define __disable_irq ((void(*)(void))0x400)
#define __enable_irq ((void(*)(void))0x41e)

//#pragma address wMUT26_Knock_Sum=0xFFFF8C32
//static u16 wMUT26_Knock_Sum;

#define wMUT26_Knock_Sum				(*(u16*)0xFFFF8C32)
//#define wMUT1C_ECU_Load					(*(u16*)0xFFFF8952)
//#define	wMUT06_Timing_Advance			(*(u16*)0xFFFF8BDC)
//#define	wMUT33_Corrected_Timing_Advance	(*(u16*)0xFFFF8BBE)
//#define	MUT21_RPM_x125div4				(*(u16*)0xFFFF8944)
//#define	wMUTD1_BitMap_FAA				(*(u16*)0xFFFF89D4)
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

#define __byte_FFFF8400					(*(byte*)0xFFFF8400) // 1 - Alt maps

#define hiIgnMapIndex					(*(byte*)0xFFFF8401) // 0..7
#define hiFuelMapIndex					(*(byte*)0xFFFF8402) // 0..7
#define veMapIndex						(*(byte*)0xFFFF8403) // 0..7



#define __axis_res_RPM25				(*(u16*)0xFFFF8460)
#define __axis_res_LOAD30				(*(u16*)0xFFFF8462)
#define __DEADloc						(*(u16*)0xFFFFA800)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define romHiIgnMap						(*(Map3D_W*)0x38d42)

#define ramHiIgnMap						(*(Map3D_W*)0xFFFFA000)

#define kPa2load(v) (v*2)

#define rpm2mut(v) (v*4/125)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif // MISC_H__26_04_2016__22_59

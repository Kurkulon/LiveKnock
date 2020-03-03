#include <machine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"

#ifndef DEF_COM	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define _sub_206A4									((void(*)(void))	0x206A4)
#define _COM_MUT_sub_207F0							((void(*)(void))	0x207F0)
#define _MUT3_sub_20910								((void(*)(void))	0x20910)
#define _COM_MUT_COMMANDS_COMPARE_sub_20968			((void(*)(void))	0x20968)
#define _COM_MUT_sub_20DD4							((void(*)(void))	0x20DD4)
#define _COM_MUT_Cancel_PrevActive_cmd				((void(*)(void))	0x20E2C)
#define _COM_MUT_Connect_20E4A						((void(*)(void))	0x20E4A)
#define _OBD10_sub_21314							((void(*)(void))	0x21314)
#define _OBD10_sub_21386							((void(*)(void))	0x21386)
#define _COM_root_sub_21564							((void(*)(void))	0x21564)
#define _MUT2B_800Hz_root							((void(*)(void))	0x2192E)
#define _CRANK5_sub_21A04							((void(*)(void))	0x21A04)

#define _sub_21A52                      			((u16(*)(u16))	0x21A52)
#define _sub_21A72                      			((u16(*)(u16))	0x21A72)
#define _sub_21AAA                      			((u16(*)(u16))	0x21AAA)
#define _sub_21ACC                      			((u16(*)(u16))	0x21ACC)
#define _sub_21B50                      			((u16(*)(u16))	0x21B50)
#define _sub_21BC4                      			((u16(*)(u16))	0x21BC4)
#define _sub_21C0C                      			((u16(*)(u16))	0x21C0C)
#define _F500_sub_21C80                 			((u16(*)(u16))	0x21C80)
#define _sub_21CA8                      			((u16(*)(u16))	0x21CA8)
#define _sub_21D6C                      			((u16(*)(u16))	0x21D6C)
#define _sub_21D9C                      			((u16(*)(u16))	0x21D9C)
#define _IG04_sub_21DCE                 			((u16(*)(u16))	0x21DCE)
#define _sub_21E14                      			((u16(*)(u16))	0x21E14)
#define _sub_21E2A                      			((u16(*)(u16))	0x21E2A)
#define _sub_21E4C                      			((u16(*)(u16))	0x21E4C)
#define _sub_21E84                      			((u16(*)(u16))	0x21E84)
#define _sub_21E9C                      			((u16(*)(u16))	0x21E9C)
#define _sub_21EB4                      			((u16(*)(u16))	0x21EB4)
#define _sub_21ECC                      			((u16(*)(u16))	0x21ECC)
#define _sub_21EE4                      			((u16(*)(u16))	0x21EE4)
#define _sub_21EF8                      			((u16(*)(u16))	0x21EF8)
#define _sub_21F0C                      			((u16(*)(u16))	0x21F0C)
#define _sub_21F4E                      			((u16(*)(u16))	0x21F4E)
#define _sub_21F66                      			((u16(*)(u16))	0x21F66)
#define _sub_21F7E                      			((u16(*)(u16))	0x21F7E)
#define _sub_21F96                      			((u16(*)(u16))	0x21F96)
#define _sub_21FB8                      			((u16(*)(u16))	0x21FB8)
#define _Barometric_Correction_sub_22084			((u16(*)(u16))	0x22084)
#define _sub_220A2                      			((u16(*)(u16))	0x220A2)
#define _sub_220B4                      			((u16(*)(u16))	0x220B4)

#pragma regsave(sub_206A4							)			
#pragma regsave(COM_MUT_sub_207F0					)
#pragma regsave(MUT3_sub_20910						)	
#pragma regsave(COM_MUT_COMMANDS_COMPARE_sub_20968	)
#pragma regsave(COM_MUT_sub_20DD4					)
#pragma regsave(COM_MUT_Cancel_PrevActive_cmd		)
#pragma regsave(COM_MUT_Connect_20E4A				)			
#pragma regsave(OBD10_sub_21314						)
#pragma regsave(OBD10_sub_21386						)	
#pragma regsave(COM_root_sub_21564					)
#pragma regsave(MUT2B_800Hz_root					)
#pragma regsave(CRANK5_sub_21A04					)

#pragma regsave(sub_21A52                      		)
#pragma regsave(sub_21A72                      		)
#pragma regsave(sub_21AAA                      		)
#pragma regsave(sub_21ACC                      		)
#pragma regsave(sub_21B50                      		)
#pragma regsave(sub_21BC4                      		)
#pragma regsave(sub_21C0C                      		)
#pragma regsave(F500_sub_21C80                 		)
#pragma regsave(sub_21CA8                      		)
#pragma regsave(sub_21D6C                      		)
#pragma regsave(sub_21D9C                      		)
#pragma regsave(IG04_sub_21DCE                 		)
#pragma regsave(sub_21E14                      		)
#pragma regsave(sub_21E2A                      		)
#pragma regsave(sub_21E4C                      		)
#pragma regsave(sub_21E84                      		)
#pragma regsave(sub_21E9C                      		)
#pragma regsave(sub_21EB4                      		)
#pragma regsave(sub_21ECC                      		)
#pragma regsave(sub_21EE4                      		)
#pragma regsave(sub_21EF8                      		)
#pragma regsave(sub_21F0C                      		)
#pragma regsave(sub_21F4E                      		)
#pragma regsave(sub_21F66                      		)
#pragma regsave(sub_21F7E                      		)
#pragma regsave(sub_21F96                      		)
#pragma regsave(sub_21FB8                      		)
#pragma regsave(Barometric_Correction_sub_22084		)
#pragma regsave(sub_220A2                      		)
#pragma regsave(sub_220B4                      		)




void sub_206A4							()			{	_sub_206A4							();			}						
void COM_MUT_sub_207F0					()			{	_COM_MUT_sub_207F0					();			}						
void MUT3_sub_20910						()			{	_MUT3_sub_20910						();			}						
void COM_MUT_COMMANDS_COMPARE_sub_20968	()			{	_COM_MUT_COMMANDS_COMPARE_sub_20968	();			}						
void COM_MUT_sub_20DD4					()			{	_COM_MUT_sub_20DD4					();			}						
void COM_MUT_Cancel_PrevActive_cmd		()			{	_COM_MUT_Cancel_PrevActive_cmd		();			}						
void COM_MUT_Connect_20E4A				()			{	_COM_MUT_Connect_20E4A				();			}						
void OBD10_sub_21314					()			{	_OBD10_sub_21314					();			}						
void OBD10_sub_21386					()			{	_OBD10_sub_21386					();			}						
void COM_root_sub_21564					()			{	_COM_root_sub_21564					();			}						
void MUT2B_800Hz_root					()			{	_MUT2B_800Hz_root					();			}						
void CRANK5_sub_21A04					()			{	_CRANK5_sub_21A04					();			}						

u16 sub_21A52                      		(u16 v)		{	return _sub_21A52                      	(v);		}						
u16 sub_21A72                      		(u16 v)		{	return _sub_21A72                      	(v);		}						
u16 sub_21AAA                      		(u16 v)		{	return _sub_21AAA                      	(v);		}						
u16 sub_21ACC                      		(u16 v)		{	return _sub_21ACC                      	(v);		}						
u16 sub_21B50                      		(u16 v)		{	return _sub_21B50                      	(v);		}						
u16 sub_21BC4                      		(u16 v)		{	return _sub_21BC4                      	(v);		}						
u16 sub_21C0C                      		(u16 v)		{	return _sub_21C0C                      	(v);		}						
u16 F500_sub_21C80                 		(u16 v)		{	return _F500_sub_21C80                 	(v);		}						
u16 sub_21CA8                      		(u16 v)		{	return _sub_21CA8                      	(v);		}						
u16 sub_21D6C                      		(u16 v)		{	return _sub_21D6C                      	(v);		}						
u16 sub_21D9C                      		(u16 v)		{	return _sub_21D9C                      	(v);		}						
u16 IG04_sub_21DCE                 		(u16 v)		{	return _IG04_sub_21DCE                 	(v);		}						
u16 sub_21E14                      		(u16 v)		{	return _sub_21E14                      	(v);		}						
u16 sub_21E2A                      		(u16 v)		{	return _sub_21E2A                      	(v);		}						
u16 sub_21E4C                      		(u16 v)		{	return _sub_21E4C                      	(v);		}						
u16 sub_21E84                      		(u16 v)		{	return _sub_21E84                      	(v);		}						
u16 sub_21E9C                      		(u16 v)		{	return _sub_21E9C                      	(v);		}						
u16 sub_21EB4                      		(u16 v)		{	return _sub_21EB4                      	(v);		}						
u16 sub_21ECC                      		(u16 v)		{	return _sub_21ECC                      	(v);		}						
u16 sub_21EE4                      		(u16 v)		{	return _sub_21EE4                      	(v);		}						
u16 sub_21EF8                      		(u16 v)		{	return _sub_21EF8                      	(v);		}						
u16 sub_21F0C                      		(u16 v)		{	return _sub_21F0C                      	(v);		}						
u16 sub_21F4E                      		(u16 v)		{	return _sub_21F4E                      	(v);		}						
u16 sub_21F66                      		(u16 v)		{	return _sub_21F66                      	(v);		}						
u16 sub_21F7E                      		(u16 v)		{	return _sub_21F7E                      	(v);		}						
u16 sub_21F96                      		(u16 v)		{	return _sub_21F96                      	(v);		}						
u16 sub_21FB8                      		(u16 v)		{	return _sub_21FB8                      	(v);		}						
u16 Barometric_Correction_sub_22084		(u16 v)		{	return _Barometric_Correction_sub_22084	(v);		}						
u16 sub_220A2                      		(u16 v)		{	return _sub_220A2                      	(v);		}						
u16 sub_220B4                      		(u16 v)		{	return _sub_220B4                      	(v);		}						

#else	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define MUT_Request_2Byte				((u16(*)(u16))0x34B66)

#define	word_8AD4				((const u16*)0x8AD4)                                                     

#define	off_8AE4				((u16**)0x8AE4)  

#define	byte_3FB40				((byte*)0x3FB40)                                                     
#define	word_3FB3C				(*(u16*)0x3FB3C)  

struct S9884 { u16 v1; byte v2; byte v3; byte v4; byte v5;  };

#define	byte_9884				((S9884*)0x9884)                                                     

#define  MUT_sub_34A2C							((void(*)(byte*,byte*,u16))0x34A2C)
#define  sub_34C2C								((byte(*)(byte*,u16))0x34C2C)
#define  COM_SCI0_Disable_Transmit_sub_D8C4		((void(*)())0xD8C4)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SCI0_Recieve_DMA0_Enable(u16 r1);
extern "C" void SCI0_Transmit_DMA0_Enable(u16 r1, u16 r2);
extern "C" bool SCI0_Check_Transfer_End();
extern "C" bool SCI0_Check_Errors();
extern "C" bool SCI0_Check_PA7();

struct SCI0_func
{
	void (*Recieve)(u16);
	void (*Transmit)(u16,u16);
	bool (*Check_Errors)();
	bool (*Check_PA7)();
	bool (*Check_Transfer_End)();
};

#pragma address sci0_func_table=0x9870
const SCI0_func sci0_func_table = { SCI0_Recieve_DMA0_Enable, SCI0_Transmit_DMA0_Enable, SCI0_Check_Errors, SCI0_Check_PA7, SCI0_Check_Transfer_End };

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
extern "C" void SysInit_sub_8000()
{
	recieve_buffer_1_2 = 0;

	memcpy(byte_3FB40, byte_FFFF9C00, word_3FB3C);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     
extern "C" void COM_sub_8026(u16 r1)
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
         
extern "C" void MUT2B_800Hz_sub_85E0(u16 r1)
{
	if (r1 >= 1) return;

	u32 r8 = recieve_buffer_1_2;

	//bool c1 = r8 & 0x101;
	//bool c2 = sci0_func_table.Check_PA7();
	//bool c3 = r8 & 0x200;
	//bool c4 = r8 & 0x400;
	//bool c5 = sci0_func_table.Check_Errors();

	if (ZRO(r8, 0x101) && !sci0_func_table.Check_PA7() && (ZRO(r8, 0x200) || (ZRO(r8, 0x400) && sci0_func_table.Check_Errors())))
	{
		sci0_func_table.Recieve(r1);
		r8 = 0x200;
	};

	recieve_buffer_1_2 = r8;

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
extern "C" void COM_sub_86BC(u16 r1, u16 r5)
{
//	byte *var_10;

	u32 r8 = r1;

	byte *r9 = sci0_transmit_buf + 52 * r1;

	S9884 *r2 = byte_9884 + r5;

	if (r1 >= 1) return;

	if ((reg_TCNT2A - recieve_buffer_1) < r2->v1) return;

	if (sci0_func_table.Check_PA7())
	{
		recieve_buffer_1_2 = 0;
	}
	else
	{
//		u32 r10 = r2->v4;
//		u32 r11 = r10;
//		u32 r12 = r2->v3;

//		r10 *= r12;

		u16 var_1C = r2->v4 * r2->v3;
//		u32 var_18 = r11;

//		u32 var_14 = r12;

	//	byte *var_10 = r9 + 2;

		MUT_sub_34A2C(recieve_buffer_0 + 2, r9 + 2, r2->v4);

		r9[1] = r2->v2;

		//u32 var_C = var_1C + 1;

		r9[var_1C + 2] = sub_34C2C(r9 + 1, var_1C + 1);

		r9[var_1C + 3] = 13;

		__disable_irq();

		sci0_func_table.Transmit(r8, var_1C + 2);

		recieve_buffer_1 = reg_TCNT2A;

		__enable_irq();
	};



	
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
         
extern "C" void MUT2B_800Hz_sub_87CC(u16 r1)
{
	if (r1 >= 1) return;

	if ((reg_TCNT2A - recieve_buffer_1) < 580) return;

	u32 r2 = r1;

	if (sci0_func_table.Check_PA7())
	{
		recieve_buffer_1_2 = 0;
	}
	else
	{
		byte *r14_8 = sci0_transmit_buf;

		byte *r8 = r14_8 + 2;

		byte *r9 = recieve_buffer_0 + 2;

		r2 = word_FFFF9A5E + 1;

		if (r2 >= 8)
		{
			r2 = 0;
		};

		u32 var_10 = r1 << 1;

		word_FFFF9A5E = r2;

		*(u16*)r8 = MUT_Request_2Byte(*(u16*)r9);

		*(u16*)(r8+2) = MUT_Request_2Byte(*(u16*)(r9+2));

		r8[4] = MUT_Request_2Byte(*(u16*)(r9+4)) >> 8;

		r8[5] = MUT_Request_2Byte(*(u16*)(r9+6)) >> 8;
		
		r8[6] = MUT_Request_2Byte(*(u16*)(r9+8)) >> 8;

		r8[7] = MUT_Request_2Byte(*(u16*)(r9+10)) >> 8;

		r9 += 12+(r2<<2);

		r8[8] = MUT_Request_2Byte(*(u16*)r9) >> 8;

		r8[9] = MUT_Request_2Byte(*(u16*)(r9+2)) >> 8;

		r14_8[1] = r2 | 0x20;

		r14_8[12] = sub_34C2C(r14_8+1, 11);

		r14_8[13] = 13;

		__disable_irq();

		SCI0_Transmit_DMA0_Enable(r1, 12);

		recieve_buffer_1 = reg_TCNT2A;

		__enable_irq();
	};


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
extern "C" void COM_MUT2B_sub_895C(u16 r1)
{

}
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_206A4()
{
	__disable_irq();

	u32 r1 = MUT_VAR_9_FFFF8DFC;

	CLR(MUT_VAR_9_FFFF8DFC, 0xF800);
	CLR(word_FFFF8DFE, 0xF800);

	__enable_irq();

	u32 r13 = mutorobd_FFFF8E08 & 0x1FF;

	if (FLAGS_FFFF8EB0 & 0x80)
	{
		r13 = 0x80;
	}
	else if (r1 & 0x800)
	{
		r13 = 0;
	}
	else if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 1) && (r1 & 0x4000))
	{
		r13 = 0x40;
	}
	else if (r1 & 0x8000)
	{
		r13 = 0x80;
	}
	else if (r1 & 0x2000)
	{
		r13 = 0x20;
	}
	else if (r1 & 0x1000)
	{
		r13 = 8;
	};

	r13 &= 0x1FF;

	mutorobd_FFFF8E08 = mutorobd_FFFF8E08 & ~0x1FF | r13;

	if (mutorobd_FFFF8E08 & 0x10)
	{
		r13 = 1;
	}
	else if (mutorobd_FFFF8E08 & 0x1AC)
	{
		r13 = 4;
	}
	else if (mutorobd_FFFF8E08 & 0x43)
	{
		r13 = 2;
	}
	else if (HIGHBAUDFLAG_FFFF93D8 & 1)
	{
		r13 = 8;
	}
	else
	{
		r13 = 1;
	};

	if ((baudrateFlags_FFFF8882 ^ r13) & 0xF)
	{
		SET(r13, 0x80);
	};

	baudrateFlags_FFFF8882 = baudrateFlags_FFFF8882 & ~0x8F | (r13 & 0x8F);

	r13 = 8;

	if (wMUTD1_BitMap_FAA & FAA_3_IMMO)
	{
		r13 = 1;
	};

	if ((word_FFFF8884 ^ r13) & 0xF)
	{
		SET(r13, 0x80);
	};

	word_FFFF8884 = word_FFFF8884 & ~0x8F | (r13 & 0x8F);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                          
extern "C" void COM_MUT_sub_207F0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                  
extern "C" void MUT3_sub_20910()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                     
extern "C" void COM_MUT_COMMANDS_COMPARE_sub_20968()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 
extern "C" void COM_MUT_sub_20DD4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                  
extern "C" void COM_MUT_Cancel_PrevActive_cmd()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

      
extern "C" void COM_MUT_Connect_20E4A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

              
extern "C" void OBD10_sub_21314()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                    
extern "C" void OBD10_sub_21386()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                    
extern "C" void COM_root_sub_21564()
{
	wMUT80_ECU_ID_Type = word_F44[wMUT34_Map_Index];
	wMUT82_ECU_ID_Version = ECU_Internal_ID_1;
	bMUTD5 = word_F56;
	bMUTFF_END_MUT = word_F3C;

	if (byte_1076/*0*/ != 0)
	{
		// loc_215A0

		if (timer_down_TXFLAG3_FFFF8574 == 0)
		{
			CLR(mutorobd_FFFF8E08, 0x4000);
		}
		else if (timer_up_FFFF852C > 200)
		{
			WFLAG(mutorobd_FFFF8E08, 0x8000, mutorobd_FFFF8E08 & 0x4000);
		}
		else
		{
			if (recieve_buffer_1_2 & 1)
			{
				SET(mutorobd_FFFF8E08, 0x4000);
			};

			SET(mutorobd_FFFF8E08, 0x8000);
		};

		// loc_215F8

		if (_highbaudflag_F30 & 1)
		{
			HIGHBAUDFLAG_FFFF93D8 = _highbaudflag_F30/*2*/;
		}
		else
		{
			byte r13 = _highbaudflag_F30;

			WFLAG(r13, 1, mutorobd_FFFF8E08 & 0x8000);

			HIGHBAUDFLAG_FFFF93D8 = r13;
		};
	}
	else
	{
		// loc_21624

		CLR(mutorobd_FFFF8E08, 0xC000);

		HIGHBAUDFLAG_FFFF93D8 = _highbaudflag_F30/*2*/;
	};

	// loc_21638

	if (HIGHBAUDFLAG_FFFF93D8 & 1)
	{
		if (mutorobd_FFFF8E08 & 0x1FF)
		{
			recieve_buffer_1_2 = 0;

			COM_SCI0_Disable_Transmit_sub_D8C4();
		}
		else
		{
			COM_sub_8026(0);

			if (AND(recieve_buffer_1_2, 3))
			{
				COM_sub_86BC(0, 0);
			}
			else if (rpm_x125div32_B < 102 && AND(recieve_buffer_1_2, 0x21))
			{
				COM_MUT2B_sub_895C(0);
			};
		};
	}
	else
	{
		COM_SCI0_Disable_Transmit_sub_D8C4();
	};

	// loc_216F2

	if (HIGHBAUDFLAG_FFFF93D8 & 2)
	{
		if (wMUTD1_BitMap_FAA & FAA_3_IMMO)
		{
			word_FFFF9A5E = 0;
		}
		else
		{
			COM_sub_8026(1);

			if (AND(word_FFFF9A5E, 3))
			{
				COM_sub_86BC(1, 0);
			}
			else if (rpm_x125div32_B < 102 && AND(word_FFFF9A5E, 0x21))
			{
				COM_MUT2B_sub_895C(1);
			};
		};
	};

	// loc_2174E

	WFLAG(wMUTA0_Sensor_Pins, 0x10, wMUT9A_Ligths_Bit_Array & 1);

	WFLAG(wMUTA0_Sensor_Pins, 2, wMUT9B_Output_Pins & 1);

	// loc_2178A

	if (recieve_buffer_1_2 & 0xE)
	{
		u16 *p = (u16*)recieve_buffer_0;

		word_FFFF99E4 = swapb(p[1]);//(p[1] >> 8) | (p[1] << 8);
		word_FFFF99E6 = swapb(p[2]);//(p[2] >> 8) | (p[2] << 8);
		word_FFFF99E8 = swapb(p[3]);//(p[3] >> 8) | (p[3] << 8);
		word_FFFF99EA = swapb(p[4]);//(p[4] >> 8) | (p[4] << 8);
		word_FFFF99EC = swapb(p[5]);//(p[5] >> 8) | (p[5] << 8);
		word_FFFF99EE = swapb(p[6]);//(p[6] >> 8) | (p[6] << 8);

		word_FFFF99D8 = swapb(p[13]);//(p[13] >> 8) | (p[13] << 8);
		word_FFFF99DA = swapb(p[14]);//(p[14] >> 8) | (p[14] << 8);
		word_FFFF99DC = swapb(p[15]);//(p[15] >> 8) | (p[15] << 8);
		word_FFFF99DE = swapb(p[16]);//(p[16] >> 8) | (p[16] << 8);
		word_FFFF99E0 = swapb(p[17]);//(p[17] >> 8) | (p[17] << 8);
		word_FFFF99E2 = swapb(p[18]);//(p[18] >> 8) | (p[18] << 8);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                 
extern "C" void MUT2B_800Hz_root()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                   
extern "C" void CRANK5_sub_21A04()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif //DEF_COM	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                   
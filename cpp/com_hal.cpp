#include <machine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"
#include "com_hal.h"

#ifndef DEF_COM_HAL	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//extern void SysInit_sub_8000		();
//extern void COM_sub_8026			(u16 r1			);
//extern void MUT2B_800Hz_sub_85E0	(u16 r1			);
//extern void COM_sub_86BC			(u16 r1, u16 r5	);
//extern void MUT2B_800Hz_sub_87CC	(u16 r1			);
//extern void COM_MUT2B_sub_895C		(u16 r1			);


#define _SysInit_sub_8000		((void(*)(void))	0x28054)
#define _COM_sub_8026			((void(*)(u16))		0x280E4)
#define _MUT2B_800Hz_sub_85E0	((void(*)(u16))		0x28320)
#define _COM_sub_86BC			((void(*)(u16, u16))0x29438)
#define _MUT2B_800Hz_sub_87CC	((void(*)(u16))		0x2941C)
#define _COM_MUT2B_sub_895C		((void(*)(u16))		0x2941C)

#pragma regsave(SysInit_sub_8000				)			
#pragma regsave(COM_sub_8026					)
#pragma regsave(MUT2B_800Hz_sub_85E0			)	
#pragma regsave(COM_sub_86BC					)
#pragma regsave(MUT2B_800Hz_sub_87CC			)
#pragma regsave(COM_MUT2B_sub_895C				)

void SysInit_sub_8000		()										{	_SysInit_sub_8000		();			}						
void COM_sub_8026			(u16 r1			)						{	_COM_sub_8026			(r1);		}		
void MUT2B_800Hz_sub_85E0	(u16 r1			)						{	_MUT2B_800Hz_sub_85E0	(r1); 		}		
void COM_sub_86BC			(u16 r1, u16 r5	)						{	_COM_sub_86BC			(r1,r5); 	}		
void MUT2B_800Hz_sub_87CC	(u16 r1			)						{	_MUT2B_800Hz_sub_87CC	(r1); 		}		
void COM_MUT2B_sub_895C		(u16 r1			)						{	_COM_MUT2B_sub_895C		(r1); 		}		




#else	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif // DEF_COM_HAL	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                   
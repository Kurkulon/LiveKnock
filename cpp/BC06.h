#ifndef BC06_H__27_11_2018__17_18
#define BC06_H__27_11_2018__17_18

#include "types.h"

#ifdef DEF_BC06

extern void SysInit_sub_1BEFE();
extern void BC06_root_sub_1BF7A();
extern void BC06_sub_1E2D0();
extern void BC06_sub_1D2BC();

#else

#define _SysInit_sub_1BEFE			((void(*)(void))0x1BEFE)
#define _BC06_root_sub_1BF7A		((void(*)(void))0x1BF7A)
#define _BC06_sub_1E2D0				((void(*)(void))0x1E2D0)
#define _BC06_sub_1D2BC				((void(*)(void))0x1D2BC)

#pragma regsave(SysInit_sub_1BEFE	)			
#pragma regsave(BC06_root_sub_1BF7A	)
#pragma regsave(BC06_sub_1E2D0		)	
#pragma regsave(BC06_sub_1D2BC		)	

static void SysInit_sub_1BEFE()		{	_SysInit_sub_1BEFE();	}						
static void BC06_root_sub_1BF7A()	{	_BC06_root_sub_1BF7A();	}		
static void BC06_sub_1E2D0()		{	_BC06_sub_1E2D0();		}		
static void BC06_sub_1D2BC()		{	_BC06_sub_1D2BC();		}		

#endif

#endif // BC06_H__27_11_2018__17_18

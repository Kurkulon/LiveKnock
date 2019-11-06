#ifndef EF07_H__23_12_2018__11_50
#define EF07_H__23_12_2018__11_50

#include "types.h"

#ifdef DEF_EF07

extern void SysInit_NVRAM_1F3E0();
extern void SysInit_sub_1F408();
extern void EF07_root_sub_1F428();

#else

#define _SysInit_NVRAM_1F3E0		((void(*)(void))0x1F3E0)
#define _SysInit_sub_1F408			((void(*)(void))0x1F408)
#define _EF07_root_sub_1F428		((void(*)(void))0x1F428)

#pragma regsave(SysInit_NVRAM_1F3E0		)			
#pragma regsave(SysInit_sub_1F408		)
#pragma regsave(EF07_root_sub_1F428		)	

static void SysInit_NVRAM_1F3E0()	{	_SysInit_NVRAM_1F3E0();	}						
static void SysInit_sub_1F408()		{	_SysInit_sub_1F408();	}		
static void EF07_root_sub_1F428()	{	_EF07_root_sub_1F428();	}		

#endif

#endif // EF07_H__23_12_2018__11_50

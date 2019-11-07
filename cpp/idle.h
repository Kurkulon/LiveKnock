#ifndef IDLE_H__14_11_2018__10_52
#define IDLE_H__14_11_2018__10_52

#include "types.h"

#ifdef __MVS
#define DEF_IDLE
#endif

#ifdef DEF_IDLE

extern void SysInit_NVRAM_18F80();
extern void SysInit_sub_19014();
extern void AA05_root_sub_19096();

#else

#define _AA05_root_sub_19096		((void(*)(void))0x19096)
#define _SysInit_NVRAM_18F80		((void(*)(void))0x18F80)
#define _SysInit_sub_19014			((void(*)(void))0x19014)

#pragma regsave(AA05_root_sub_19096	)			
#pragma regsave(SysInit_NVRAM_18F80	)
#pragma regsave(SysInit_sub_19014	)	

static void AA05_root_sub_19096()	{	_AA05_root_sub_19096();	}						
static void SysInit_NVRAM_18F80()	{	_SysInit_NVRAM_18F80();	}		
static void SysInit_sub_19014()		{	_SysInit_sub_19014();	}		

#endif

#endif // IDLE_H__14_11_2018__10_52


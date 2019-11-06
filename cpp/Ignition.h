#ifndef IGNITION_H__14_11_2018__10_53
#define IGNITION_H__14_11_2018__10_53

#include "types.h"

#ifdef DEF_IGNITION

extern void SysInit_NVRAM_OctaneNum();
extern void SysInit_sub_16D74();
extern void IG04_root_Update_Ignition();

#else

#define _SysInit_NVRAM_OctaneNum		((void(*)(void))0x16D50)
#define _SysInit_sub_16D74			((void(*)(void))0x16D74)
#define _IG04_root_Update_Ignition	((void(*)(void))0x16E90)

#pragma regsave(SysInit_NVRAM_OctaneNum		)			
#pragma regsave(SysInit_sub_16D74			)
#pragma regsave(IG04_root_Update_Ignition	)	

static void SysInit_NVRAM_OctaneNum()	{	_SysInit_NVRAM_OctaneNum();		}						
static void SysInit_sub_16D74()			{	_SysInit_sub_16D74();			}		
static void IG04_root_Update_Ignition()	{	_IG04_root_Update_Ignition();	}		

#endif


#endif // IGNITION_H__14_11_2018__10_53


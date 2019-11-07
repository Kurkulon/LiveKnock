#ifndef ML02_H__13_08_2018__22_08
#define ML02_H__13_08_2018__22_08

#include "types.h"

#ifdef __MVS
#define DEF_ML02
#endif

#ifdef DEF_ML02

extern void SysInit_NVRAM_111C8();
extern void SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG();
extern void ML02_root_sub_1123E();

#else

#define _SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG		((void(*)(void))0x11228)
#define _ML02_root_sub_1123E						((void(*)(void))0x1123E)
#define _SysInit_NVRAM_111C8						((void(*)(void))0x111C8)

#pragma regsave(SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG	)			
#pragma regsave(ML02_root_sub_1123E						)
#pragma regsave(SysInit_NVRAM_111C8						)	

static void SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG()	{	_SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG();	}						
static void ML02_root_sub_1123E()					{	_ML02_root_sub_1123E();						}		
static void SysInit_NVRAM_111C8()					{	_SysInit_NVRAM_111C8(); 					}		

#endif 

#endif // ML02_H__13_08_2018__22_08

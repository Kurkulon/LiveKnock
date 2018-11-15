#ifndef ML02_H__13_08_2018__22_08
#define ML02_H__13_08_2018__22_08

#include "types.h"

#ifdef DEF_ML02

extern void SysInit_NVRAM_111C8();
extern void SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG();
extern void ML02_root_sub_1123E();

#else

#define SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG		((void(*)(void))0x11228)
#define ML02_root_sub_1123E							((void(*)(void))0x1123E)
#define SysInit_NVRAM_111C8							((void(*)(void))0x111C8)

#endif 

#endif // ML02_H__13_08_2018__22_08

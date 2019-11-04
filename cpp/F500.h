#ifndef F500_H__13_08_2018__08_53
#define F500_H__13_08_2018__08_53

#include "types.h"

#ifdef DEF_F500

extern void SysInit_NVRAM_F234();
extern void SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C();

extern void F500_root_sub();
extern void F500_Init_BitMap_Flags_New();
extern void sub_A374();

#else

#define SysInit_NVRAM_F234								((void(*)(void))0xF234)
#define SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C	((void(*)(void))0xF26C)
#define F500_root_sub									((void(*)(void))0xF500)
#define F500_Init_BitMap_Flags_New						((void(*)(void))0xF58C)
#define sub_A374										((void(*)(void))0xA374)

#endif



#endif // F500_H__13_08_2018__08_53


#ifndef F500_H__13_08_2018__08_53
#define F500_H__13_08_2018__08_53

#include "types.h"

#ifdef __MVS
#define DEF_F500
#endif

extern void SysInit_NVRAM_F234();
extern void SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C();

extern void F500_root_sub();
extern void F500_Init_BitMap_Flags_New();

#endif // F500_H__13_08_2018__08_53


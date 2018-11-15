#ifndef IGNITION_H__14_11_2018__10_53
#define IGNITION_H__14_11_2018__10_53

#include "types.h"

#ifdef DEF_IGNITION

extern "C" void SysInit_NVRAM_OctaneNum();
extern "C" void SysInit_sub_16D74();
extern "C" void IG04_root_Update_Ignition();

#else

#define SysInit_NVRAM_OctaneNum		((void(*)(void))0x16D50)
#define SysInit_sub_16D74			((void(*)(void))0x16D74)
#define IG04_root_Update_Ignition	((void(*)(void))0x16E90)

#endif


#endif // IGNITION_H__14_11_2018__10_53


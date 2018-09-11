#ifndef FU03_H__11_09_2018__14_48
#define FU03_H__11_09_2018__14_48

#include "types.h"

//extern "C" void SysInit_NVRAM_Trims();
//extern "C" void SysInit_sub_13B04();
//extern "C" void FU03_root_sub();

#define SysInit_NVRAM_Trims		((void(*)(void))0x13AB8)
#define SysInit_sub_13B04			((void(*)(void))0x13B04)
#define FU03_root_sub				((void(*)(void))0x13BF4)

#endif // FU03_H__11_09_2018__14_48

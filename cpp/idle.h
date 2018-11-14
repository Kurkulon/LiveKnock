#ifndef IDLE_H__14_11_2018__10_52
#define IDLE_H__14_11_2018__10_52

#include "types.h"

//extern "C" void SysInit_NVRAM_18F80();
//extern "C" void SysInit_sub_19014();
//extern "C" void AA05_root_sub_19096();

#define AA05_root_sub_19096			((void(*)(void))0x19096)
#define SysInit_NVRAM_18F80			((void(*)(void))0x18F80)
#define SysInit_sub_19014			((void(*)(void))0x19014)


#endif // IDLE_H__14_11_2018__10_52


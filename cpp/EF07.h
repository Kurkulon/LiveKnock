#ifndef EF07_H__23_12_2018__11_50
#define EF07_H__23_12_2018__11_50

#include "types.h"

#ifdef DEF_EF07

extern "C" void SysInit_NVRAM_1F3E0();
extern "C" void SysInit_sub_1F408();
extern "C" void EF07_root_sub_1F428();

#else

#define SysInit_NVRAM_1F3E0			((void(*)(void))0x1F3E0)
#define SysInit_sub_1F408			((void(*)(void))0x1F408)
#define EF07_root_sub_1F428			((void(*)(void))0x1F428)

#endif

#endif // EF07_H__23_12_2018__11_50

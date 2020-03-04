#ifndef EF07_H__23_12_2018__11_50
#define EF07_H__23_12_2018__11_50

#include "types.h"

#ifdef __MVS
#define DEF_EF07
#endif

extern void SysInit_NVRAM_1F3E0();
extern void SysInit_sub_1F408();
extern void EF07_root_sub_1F428();

#endif // EF07_H__23_12_2018__11_50

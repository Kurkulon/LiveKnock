#ifndef FU03_H__11_09_2018__14_48
#define FU03_H__11_09_2018__14_48

#include "types.h"

#ifdef __MVS
#define DEF_FU03
#endif

extern void SysInit_NVRAM_Trims();
extern void SysInit_sub_13B04();
extern void FU03_root_sub();

#endif // FU03_H__11_09_2018__14_48

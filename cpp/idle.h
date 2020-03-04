#ifndef IDLE_H__14_11_2018__10_52
#define IDLE_H__14_11_2018__10_52

#include "types.h"

#ifdef __MVS
#define DEF_IDLE
#endif

extern void SysInit_NVRAM_18F80();
extern void SysInit_sub_19014();
extern void AA05_root_sub_19096();

#endif // IDLE_H__14_11_2018__10_52


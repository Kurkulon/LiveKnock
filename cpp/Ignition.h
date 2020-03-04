#ifndef IGNITION_H__14_11_2018__10_53
#define IGNITION_H__14_11_2018__10_53

#include "types.h"

#ifdef __MVS
#define DEF_IGNITION
#endif

extern void SysInit_NVRAM_OctaneNum();
extern void SysInit_sub_16D74();
extern void IG04_root_Update_Ignition();

#endif // IGNITION_H__14_11_2018__10_53


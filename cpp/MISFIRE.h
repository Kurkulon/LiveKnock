#ifndef MISFIRE_H__02_03_2020__18_07
#define MISFIRE_H__02_03_2020__18_07

#include "types.h"

#ifdef __MVS
#define DEF_MISFIRE
#endif

extern void Misfire_NVRAM_Init();
extern void Misfire_Init_280E4();

extern void Misfire_root_28320();
extern void Misfire_CRANK5_root();
extern void Misfire_CRANK75_root();

#endif // MISFIRE_H__02_03_2020__18_07


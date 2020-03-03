#ifndef CRANK_H__03_03_2020__11_26
#define CRANK_H__03_03_2020__11_26

#include "types.h"

#ifdef __MVS
#define DEF_CRANK
#endif

extern void sub_23180();	
extern void SysInit_sub_230FA();	
extern u16 INJECTOR_RESCALED_sub_26174(u32 v);
extern void StartInjectAsync(u16 v, u16 mask);
extern void StartInjectSync(u16 v, u16 mask);
extern void F500_InitManifoldVars();

#endif // CRANK_H__03_03_2020__11_26


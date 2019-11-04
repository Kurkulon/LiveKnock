#ifndef BC06_H__27_11_2018__17_18
#define BC06_H__27_11_2018__17_18

#include "types.h"

#ifdef DEF_BC06

extern "C" void SysInit_sub_1BEFE();
extern "C" void BC06_root_sub_1BF7A();
extern "C" void BC06_sub_1E2D0();
extern "C" void sub_A324();

#else

#define SysInit_sub_1BEFE			((void(*)(void))0x1BEFE)
#define BC06_root_sub_1BF7A			((void(*)(void))0x1BF7A)
#define BC06_sub_1E2D0				((void(*)(void))0x1E2D0)
#define sub_A324					((void(*)(void))0xA324)

#endif

#endif // BC06_H__27_11_2018__17_18

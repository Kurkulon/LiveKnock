#ifndef COM_HAL_H__03_03_2020__10_48
#define COM_HAL_H__03_03_2020__10_48

#include "types.h"

#ifdef __MVS
#define DEF_COM_HAL
#endif


extern void SysInit_sub_8000();
extern void COM_sub_8026(u16 r1);
extern void MUT2B_800Hz_sub_85E0(u16 r1);
extern void COM_sub_86BC(u16 r1, u16 r5);
extern void MUT2B_800Hz_sub_87CC(u16 r1);
extern void COM_MUT2B_sub_895C(u16 r1);


#endif // COM_HAL_H__03_03_2020__10_48


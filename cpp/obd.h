#ifndef OBD_H__03_03_2020__11_05
#define OBD_H__03_03_2020__11_05

#include "types.h"

#ifdef __MVS
#define DEF_OBD
#endif

extern void OBD_root_sub_2B8AC();	
extern void Init_NVRAM_2B364();	
extern void Init_sub_2B474();	
extern void sub_34664();
extern void MUT98_sub_329C6();
extern void OBD_Set_DTC_sub_2C1FC(u16 v1, u16 v2, u16 v3);			
extern void OBD_Set_DTC_sub_2C22A(u16 v1, u16 v2, u16 v3, u16 v4);

#endif // OBD_H__03_03_2020__11_05


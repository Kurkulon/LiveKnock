#include <machine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"


#define _OBD_root_sub_2B8AC			((void(*)(void))			0x2B8AC)
#define _Init_NVRAM_2B364			((void(*)(void))			0x2B364)
#define _Init_sub_2B474				((void(*)(void))			0x2B474)
#define _sub_34664					((void(*)(void))			0x34664)
#define _MUT98_sub_329C6			((void(*)(void))			0x329C6)
#define _OBD_Set_DTC_sub_2C1FC 		((void(*)(u16,u16,u16))		0x2C1FC)
#define _OBD_Set_DTC_sub_2C22A 		((void(*)(u16,u16,u16,u16))	0x2C22A)


#pragma regsave(OBD_root_sub_2B8AC)	
#pragma regsave(Init_NVRAM_2B364)	
#pragma regsave(Init_sub_2B474)
#pragma regsave(sub_34664)	
#pragma regsave(MUT98_sub_329C6)	
#pragma regsave(OBD_Set_DTC_sub_2C1FC)	
#pragma regsave(OBD_Set_DTC_sub_2C22A)	

void OBD_root_sub_2B8AC()									{	_OBD_root_sub_2B8AC(); 					}		
void Init_NVRAM_2B364()										{	_Init_NVRAM_2B364();					}				
void Init_sub_2B474()										{	_Init_sub_2B474();						}				
void sub_34664()											{	_sub_34664();							}						
void MUT98_sub_329C6()										{	_MUT98_sub_329C6();						}						
void OBD_Set_DTC_sub_2C1FC(u16 v1, u16 v2, u16 v3)			{	_OBD_Set_DTC_sub_2C1FC(v1, v2, v3);		}						
void OBD_Set_DTC_sub_2C22A(u16 v1, u16 v2, u16 v3, u16 v4)	{	_OBD_Set_DTC_sub_2C22A(v1, v2, v3, v4);	}						






                   
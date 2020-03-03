#include <machine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"


#define _OBD_root_sub_2B8AC			((void(*)(void))0x2B8AC)
#define _Init_NVRAM_2B364			((void(*)(void))0x2B364)
#define _Init_sub_2B474				((void(*)(void))0x2B474)
#define _sub_34664					((void(*)(void))0x34664)
#define _MUT98_sub_329C6			((void(*)(void))0x329C6)


#pragma regsave(OBD_root_sub_2B8AC)	
#pragma regsave(Init_NVRAM_2B364)	
#pragma regsave(Init_sub_2B474)
#pragma regsave(sub_34664)	
#pragma regsave(MUT98_sub_329C6)	

void OBD_root_sub_2B8AC()	{	_OBD_root_sub_2B8AC(); 	}		
void Init_NVRAM_2B364()		{	_Init_NVRAM_2B364();	}				
void Init_sub_2B474()		{	_Init_sub_2B474();		}				
void sub_34664()			{	_sub_34664();			}						
void MUT98_sub_329C6()		{	_MUT98_sub_329C6();		}						






                   
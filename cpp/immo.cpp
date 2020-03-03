#include <machine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"



#define _IMMO_root_sub_226E4		((void(*)(void))0x226E4)
#define _SysInit_NVRAM_220D8		((void(*)(void))0x220D8)
#define _SysInit_sub_22100			((void(*)(void))0x22100)
#define _IMMO_sub_2212E						((void(*)(void))0x2212E)

#pragma regsave(IMMO_root_sub_226E4)
#pragma regsave(SysInit_NVRAM_220D8)
#pragma regsave(SysInit_sub_22100)	
#pragma regsave(IMMO_sub_2212E		)			

void IMMO_root_sub_226E4()	{	_IMMO_root_sub_226E4();	}	
void SysInit_NVRAM_220D8()	{	_SysInit_NVRAM_220D8(); }	
void SysInit_sub_22100()	{	_SysInit_sub_22100(); 	}		
void IMMO_sub_2212E()		{	_IMMO_sub_2212E();		}						







                   
#ifndef HUGE_H__19_11_2018__20_33
#define HUGE_H__19_11_2018__20_33

#include "types.h"

#ifdef DEF_HUGE

extern void SysInit_NVRAM_266DC();
extern void SysInit_sub_266FC();
extern void Read_Ports_And_Registers_sub_B114();
extern void Start_Coil_Charge(u16 mask);

#else

#define _SysInit_NVRAM_266DC				((void(*)(void))0x266DC)
#define _SysInit_sub_266FC					((void(*)(void))0x266FC)
#define _Read_Ports_And_Registers_sub_B114	((void(*)(void))0xB114)
#define _Start_Coil_Charge					((void(*)(u16))0xBE1C)

#pragma regsave(SysInit_NVRAM_266DC					)			
#pragma regsave(SysInit_sub_266FC					)
#pragma regsave(Read_Ports_And_Registers_sub_B114	)	
#pragma regsave(Start_Coil_Charge					)

static void SysInit_NVRAM_266DC()				{	_SysInit_NVRAM_266DC();					}						
static void SysInit_sub_266FC()					{	_SysInit_sub_266FC();					}		
static void Read_Ports_And_Registers_sub_B114()	{	_Read_Ports_And_Registers_sub_B114();	}		
static void Start_Coil_Charge(u16 mask)			{	_Start_Coil_Charge(mask);				}		


#endif


#endif // HUGE_H__19_11_2018__20_33


#ifndef HUGE_H__19_11_2018__20_33
#define HUGE_H__19_11_2018__20_33

#include "types.h"

#ifdef DEF_HUGE

extern "C" void SysInit_NVRAM_266DC();
extern "C" void SysInit_sub_266FC();
extern "C" void PHDR_Stuff_sub_C388();
extern "C" void PADR_Stuff_sub_A5F8();
extern "C" void PDIOR_Stuff_sub_AD3C();
extern "C" void Read_Ports_And_Registers_sub_B114();
extern "C" void Get_ADC_Bat_TPS_oxigen();

#else

#define SysInit_NVRAM_266DC			((void(*)(void))0x266DC)
#define SysInit_sub_266FC			((void(*)(void))0x266FC)
#define PHDR_Stuff_sub_C388								((void(*)(void))0xC388)
#define PADR_Stuff_sub_A5F8								((void(*)(void))0xA5F8)
#define PDIOR_Stuff_sub_AD3C				((void(*)(void))0xAD3C)
#define Read_Ports_And_Registers_sub_B114	((void(*)(void))0xB114)
#define Get_ADC_Bat_TPS_oxigen							((void(*)(void))0xA8DC)


#endif


#endif // HUGE_H__19_11_2018__20_33


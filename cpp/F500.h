#ifndef F500_H__13_08_2018__08_53
#define F500_H__13_08_2018__08_53

#include "types.h"

#ifdef DEF_F500

extern void SysInit_NVRAM_F234();
extern void SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C();

extern void F500_root_sub();
extern void F500_Init_BitMap_Flags_New();
extern void F500_InitManifoldVars();


#else

#define _SysInit_NVRAM_F234								((void(*)(void))0xF234)
#define _SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C	((void(*)(void))0xF26C)
#define _F500_root_sub									((void(*)(void))0xF500)
#define _F500_Init_BitMap_Flags_New						((void(*)(void))0xF58C)
#define _F500_InitManifoldVars							((void(*)(void))0x23244)


#pragma regsave(SysInit_NVRAM_F234								)			
#pragma regsave(SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C	)
#pragma regsave(F500_root_sub									)	
#pragma regsave(F500_Init_BitMap_Flags_New						)
#pragma regsave(F500_InitManifoldVars							)	

static void SysInit_NVRAM_F234()							{	_SysInit_NVRAM_F234();							}						
static void SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C()	{	_SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C();}		
static void F500_root_sub()									{	_F500_root_sub(); 								}		
static void F500_Init_BitMap_Flags_New()					{	_F500_Init_BitMap_Flags_New();					}	
static void F500_InitManifoldVars()							{	_F500_InitManifoldVars();						}				

#endif



#endif // F500_H__13_08_2018__08_53


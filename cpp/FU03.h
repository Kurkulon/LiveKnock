#ifndef FU03_H__11_09_2018__14_48
#define FU03_H__11_09_2018__14_48

#include "types.h"

#ifdef __MVS
#define DEF_FU03
#endif

#ifdef DEF_FU03

extern void SysInit_NVRAM_Trims();
extern void SysInit_sub_13B04();
extern void FU03_root_sub();
//extern void InjOpenStart(u16 v, u16 mask);
//extern u16 INJECTOR_RESCALED_sub_26174(u32 v);
//extern void StartInjectAsync(u16 v, u16 mask);
//extern void StartInjectSync(u16 v, u16 mask);

#else

#define _SysInit_NVRAM_Trims			((void(*)(void))0x13AB8)
#define _SysInit_sub_13B04				((void(*)(void))0x13B04)
#define _FU03_root_sub					((void(*)(void))0x13BF4)
//#define _InjOpenStart					((void(*)(u16,u16))0xC698)
//#define _INJECTOR_RESCALED_sub_26174	((u16(*)(u16))0x26174)
//#define _StartInjectAsync				((void(*)(u16,u16))0x261CA)
//#define _StartInjectSync				((void(*)(u16,u16))0x26218)

#pragma regsave(SysInit_NVRAM_Trims			)			
#pragma regsave(SysInit_sub_13B04			)
#pragma regsave(FU03_root_sub				)	
//#pragma regsave(InjOpenStart				)			
//#pragma regsave(INJECTOR_RESCALED_sub_26174	)
//#pragma regsave(StartInjectAsync			)	
//#pragma regsave(StartInjectSync				)			

static void	SysInit_NVRAM_Trims()				{	_SysInit_NVRAM_Trims();			}						
static void	SysInit_sub_13B04()					{	_SysInit_sub_13B04();			}						
static void	FU03_root_sub()						{	_FU03_root_sub();				}						
//static void	InjOpenStart(u16 v, u16 mask)		{	_InjOpenStart(v, mask);			}						
//static u16	INJECTOR_RESCALED_sub_26174(u32 v)	{	return _INJECTOR_RESCALED_sub_26174(v);}						
//static void	StartInjectAsync(u16 v, u16 mask)	{	_StartInjectAsync(v, mask);		}						
//static void	StartInjectSync(u16 v, u16 mask)	{	_StartInjectSync(v, mask);		}						

#endif

#endif // FU03_H__11_09_2018__14_48

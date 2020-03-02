#ifndef MISFIRE_H__02_03_2020__18_07
#define MISFIRE_H__02_03_2020__18_07

#include "types.h"

#ifdef __MVS
#define DEF_MISFIRE
#endif

#ifdef DEF_MISFIRE

extern void Misfire_NVRAM_Init();
extern void Misfire_Init_280E4();

extern void Misfire_root_28320();
extern void Misfire_CRANK5_root();
extern void Misfire_CRANK75_root();


#else

#define _Misfire_NVRAM_Init		((void(*)(void))0x28054)
#define _Misfire_Init_280E4		((void(*)(void))0x280E4)
#define _Misfire_root_28320		((void(*)(void))0x28320)
#define _Misfire_CRANK5_root	((void(*)(void))0x29438)
#define _Misfire_CRANK75_root	((void(*)(void))0x2941C)


#pragma regsave(Misfire_NVRAM_Init			)			
#pragma regsave(Misfire_Init_280E4			)
#pragma regsave(Misfire_root_28320			)	
#pragma regsave(Misfire_CRANK5_root			)
#pragma regsave(Misfire_CRANK75_root			)

static void Misfire_NVRAM_Init()							{	_Misfire_NVRAM_Init();		}						
static void Misfire_Init_280E4()							{	_Misfire_Init_280E4();		}		
static void Misfire_root_28320()							{	_Misfire_root_28320(); 		}		
static void Misfire_CRANK5_root()							{	_Misfire_CRANK5_root(); 		}		
static void Misfire_CRANK75_root()							{	_Misfire_CRANK75_root(); 		}		

#endif



#endif // MISFIRE_H__02_03_2020__18_07


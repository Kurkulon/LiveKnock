//#include <machine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "hwreg.h"
#include "hardware.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define	off_8AE4				((u16**)0x8AE4)  

//#define SysInit_HW_C0CC						((void(*)(void))0xC0CC)

//#define SysInit_ADC							((void(*)(void))0xB284)


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef DEF_HARDWARE	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define _SysInit_sub_9D2C					((void(*)(void))0x9D2C)
#define _sub_A078							((void(*)(void))0xA078)
#define _sub_A374							((void(*)(void))0xA374)
#define _PADR_Stuff_sub_A5F8				((void(*)(void))0xA5F8)
#define _PHDR_Stuff_sub_C388				((void(*)(void))0xC388)
#define _WaitDownTimer801					((void(*)(void))0xBB36)
#define _Init_ATU_sub_C5D2					((void(*)(void))0xC5D2)
#define _Init_ATU_0_2B						((void(*)(void))0xD918)
#define _Disable_Coil_Charge				((void(*)(u16))0xBED8)
#define _Timer_Counter_Related_sub_C928		((void(*)(void))0xC928)
#define _F500_Get_All_ADC					((void(*)(void))0xA7F0)
#define _Get_ADC_Bat_TPS_oxigen				((void(*)(void))0xA8DC)
#define _Get_ADC_Knock						((void(*)(void))0xA92C)
#define _Get_Manifold_AbsPressure			((void(*)(void))0xA95A)
#define _UpdateOutputAsync					((void(*)(void))0xA98A)
#define _UpdateOutputSync					((void(*)(void))0xAB3C)
#define _Knock_Output_Calc_sub_AC96			((void(*)(void))0xAC96)
#define _Update_Gen_G_output				((void(*)(void))0xAD06)
#define _PDIOR_Stuff_sub_AD3C				((void(*)(void))0xAD3C)
#define _UpdateFanOutputDuty				((void(*)(void))0xB096)
#define _SysInit_ATU_0_DMA_2				((void(*)(void))0xB458)
#define _atu22_Get_DSTR_0x3C00				((u16(*)(void))0xC850)
#define _PWM_EGR_EVAP_O2H					((void(*)(void))0xAE08)
#define _GetADC								((u16(*)(byte, u16*, u16*))0xB2B6)
#define _SetIgnCoilChargeStartTime			((void(*)(u16,u16))0x0000BC24)
#define _SetIgnSparkStartTime				((void(*)(u16,u16))0x0000BCC8)
#define _atu22_Get_ECNT9A					((u16(*)(void))0x0000C590)
#define _InjOpenStart						((void(*)(u16,u16))0xC698)




#pragma regsave(SysInit_sub_9D2C				)			
#pragma regsave(sub_A078						)
#pragma regsave(sub_A374						)	
#pragma regsave(PADR_Stuff_sub_A5F8				)			
#pragma regsave(PHDR_Stuff_sub_C388				)
#pragma regsave(WaitDownTimer801				)	
#pragma regsave(Init_ATU_sub_C5D2				)			
#pragma regsave(Init_ATU_0_2B					)
#pragma regsave(Disable_Coil_Charge				)	
#pragma regsave(Timer_Counter_Related_sub_C928	)			
#pragma regsave(F500_Get_All_ADC				)
#pragma regsave(Get_ADC_Bat_TPS_oxigen			)	
#pragma regsave(Get_ADC_Knock					)			
#pragma regsave(Get_Manifold_AbsPressure		)
#pragma regsave(UpdateOutputAsync				)	
#pragma regsave(UpdateOutputSync				)			
#pragma regsave(Knock_Output_Calc_sub_AC96		)
#pragma regsave(Update_Gen_G_output				)	
#pragma regsave(PDIOR_Stuff_sub_AD3C			)			
#pragma regsave(UpdateFanOutputDuty				)
#pragma regsave(SysInit_ATU_0_DMA_2				)	
#pragma regsave(atu22_Get_DSTR_0x3C00			)			
#pragma regsave(PWM_EGR_EVAP_O2H				)			
#pragma regsave(SetIgnCoilChargeStartTime		)			
#pragma regsave(SetIgnSparkStartTime			)			
#pragma regsave(atu22_Get_ECNT9A			)			
#pragma regsave(InjOpenStart				)			


void SysInit_sub_9D2C				()									{ _SysInit_sub_9D2C					();					}
void sub_A078						() 									{ _sub_A078							(); 				}
void sub_A374						() 									{ _sub_A374							(); 				}
void PADR_Stuff_sub_A5F8			() 									{ _PADR_Stuff_sub_A5F8				(); 				}
void PHDR_Stuff_sub_C388			() 									{ _PHDR_Stuff_sub_C388				(); 				}
void WaitDownTimer801				()									{ _WaitDownTimer801					();					}
void Init_ATU_sub_C5D2				()									{ _Init_ATU_sub_C5D2				();					}
void Init_ATU_0_2B					()									{ _Init_ATU_0_2B					();					}
void Disable_Coil_Charge			(u16 mask)							{ _Disable_Coil_Charge				(mask);				}
void Timer_Counter_Related_sub_C928	()									{ _Timer_Counter_Related_sub_C928	();					}				
void F500_Get_All_ADC				()									{ _F500_Get_All_ADC					();					}
void Get_ADC_Bat_TPS_oxigen			()									{ _Get_ADC_Bat_TPS_oxigen			();					}
void Get_ADC_Knock					()									{ _Get_ADC_Knock					();					}
void Get_Manifold_AbsPressure		()									{ _Get_Manifold_AbsPressure			();					}	
void UpdateOutputAsync				()									{ _UpdateOutputAsync				();					}
void UpdateOutputSync				()									{ _UpdateOutputSync					();					}
void Knock_Output_Calc_sub_AC96		()									{ _Knock_Output_Calc_sub_AC96		();					}		
void Update_Gen_G_output			()									{ _Update_Gen_G_output				();					}
void PDIOR_Stuff_sub_AD3C			()									{ _PDIOR_Stuff_sub_AD3C				();					}
void UpdateFanOutputDuty			() 									{ _UpdateFanOutputDuty				(); 				}
void SysInit_ATU_0_DMA_2			() 									{ _SysInit_ATU_0_DMA_2				(); 				}
u16	atu22_Get_DSTR_0x3C00			()									{ return _atu22_Get_DSTR_0x3C00		();					}	
void PWM_EGR_EVAP_O2H				() 									{ _PWM_EGR_EVAP_O2H					(); 				}
void GetADC							(byte ch, u16 *res8, u16 *res10) 	{ _GetADC							(ch, res8, res10);	}

void SetIgnCoilChargeStartTime		(u16 mask, u16 v) 					{ _SetIgnCoilChargeStartTime		(mask, v); 			}
void SetIgnSparkStartTime			(u16 mask, u16 v) 					{ _SetIgnSparkStartTime				(mask, v); 			}
u16	atu22_Get_ECNT9A				()									{ return _atu22_Get_ECNT9A			();					}	
void	InjOpenStart				(u16 v, u16 mask)					{	_InjOpenStart(v, mask);					}						



#else	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


static void SysInit_ADC();
static void SysInit_HW_C0CC();
static void SysInit_ATU_2E_2F_2G_out();
static void SysInit_ICR_C204();
static void SysInit_ATU_C476();
//static void Init_ATU_sub_C5D2();
static void SysInit_sub_C87C();
static void SysInit_ATU_CA34();
static void sub_CAA8();
static void SysInit_ATU_6_7();
static void SysInit_SCI_CF6C();
static void SysInit_Reset_Crank_Flags();
//static void Init_ATU_0_2B();
static void SysInit_ATU_Misc_1_sub_DCDC();
static void SysInit_ATU_Misc_2_sub_E3A2();
static void Init_ATU_Counters_Control_sub_E4D0();
static void SysInit_INTC_sub_E598();
static void Init_HW_C164();
static void Init_ATU_2E_2F_2G_out();

static void sub_C234();                                          
static void sub_C4EE();                                          
static void sub_C646();                                          
static void sub_C8E0();                                          
static void sub_CAA8();                                          
static void Init_ATU_6_7();                                      
static void sub_D008();                                          
static void sub_D99A();                                          
static void sub_DE24();                                          
static void sub_E3EA();                                          
static void Init_ATU_Counters_Control_sub_E4D0();                
static void sub_E5FC();   
static bool sub_C2CC();
static bool sub_C304();
static bool sub_C33C();


//#define SysInit_ATU_0_DMA_2					((void(*)(void))0xB458)
//#define SysInit_HCAN						((void(*)(void))0xB77C)
static void SysInit_HCAN();
//#define SysInit_ATU_2A_2B_3_4_5_8_10		((void(*)(void))0xB7E0)
static void SysInit_ATU_2A_2B_3_4_5_8_10();
static void sub_D56E();
static void COM_TX_Get();
//#define SysInit_ATU_2E_2F_2G_out			((void(*)(void))0xBB6C)
//
//#define  SysInit_ICR_C204					((void(*)(void))0xC204)
//#define  SysInit_ATU_C476					((void(*)(void))0xC476)
//#define Init_ATU_sub_C5D2					((void(*)(void))0xC5D2)
//#define  SysInit_sub_C87C					((void(*)(void))0xC87C)
//#define  SysInit_ATU_CA34					((void(*)(void))0xCA34)
//
//#define SysInit_ATU_6_7						((void(*)(void))0xCC3E)
//
//#define SysInit_SCI_CF6C					((void(*)(void))0xCF6C)
//#define SysInit_Reset_Crank_Flags			((void(*)(void))0xD908)
//#define Init_ATU_0_2B						((void(*)(void))0xD918)
//#define SysInit_ATU_Misc_1_sub_DCDC			((void(*)(void))0xDCDC)
//#define SysInit_ATU_Misc_2_sub_E3A2			((void(*)(void))0xE3A2)
//#define Init_ATU_Counters_Control_sub_E4D0	((void(*)(void))0xE4D0)
//#define SysInit_INTC_sub_E598				((void(*)(void))0xE598)


//#define sub_C2CC							((bool(*)(void))0xC2CC)
//#define sub_C304							((bool(*)(void))0xC304)
//#define sub_C33C							((bool(*)(void))0xC33C)




//#define sub_C234							((void(*)(void))0xC234)
//#define sub_C4EE							((void(*)(void))0xC4EE)
//#define sub_C646							((void(*)(void))0xC646)
//#define sub_C8E0							((void(*)(void))0xC8E0)
//#define sub_CAA8							((void(*)(void))0xCAA8)
//#define sub_D008							((void(*)(void))0xD008)
//#define sub_D99A							((void(*)(void))0xD99A)
//#define sub_DE24							((void(*)(void))0xDE24)
//#define sub_E3EA							((void(*)(void))0xE3EA)
//#define sub_E5FC							((void(*)(void))0xE5FC)
//#define Init_ATU_Counters_Control_sub_E4D0	((void(*)(void))0xE4D0)
//#define Init_HW_C164						((void(*)(void))0xC164)
	
//#define Init_ATU_0_DMA_2         			((void(*)(void))0xB4B4)
static void Init_ATU_0_DMA_2();

//#define Init_HCAN                			((void(*)(void))0xB7A6)
static void Init_HCAN();
//#define Init_ATU_2A_2B_3_4_5_8_10			((void(*)(void))0xB8A0)
static void Init_ATU_2A_2B_3_4_5_8_10();
//#define Init_ATU_2E_2F_2G_out 				((void(*)(void))0xBBD6)
//#define Init_ATU_6_7						((void(*)(void))0xCD58)

//#define GetADC								((void(*)(byte,u16*,u16*))0xB2B6)
static void GetADC(byte r1, u16 *r2, u16 *r8);
static u16 GetADC0(byte r1);
static u16 GetADC1(byte r1);
	
//static void HUGE_Method_801_6_Hz();
//#define  HUGE_Method_801_6_Hz		((void(*)(void))0x2686C)

#ifdef __GNUC__
static void SysInit_sub_9D2C() __attribute__ ((section ("P_HARDWARE")));
#endif

#define	word_8AD4				((const u16*)0x8AD4)                                                     

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
//#define sub_A324							((void(*)(void))0xA324)
extern  void sub_A324();
#pragma address off_1D414=0x1D414
const void *off_1D414 = (const void *)sub_A324;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void PADR_Stuff_sub_A5F8();
#pragma address off_269A8=0x269A8
const void *off_269A8 = (const void *)PADR_Stuff_sub_A5F8;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool PEDR_LO_Check_sub_A790();
#pragma address off_2587C=0x2587C
const void *off_2587C = (const void *)PEDR_LO_Check_sub_A790;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool Check_Starter_signal();

#pragma address off_1FBBC=0x1FBBC
#pragma address off_235C0=0x235C0
#pragma address off_24EC8=0x24EC8

const void *off_1FBBC = (const void *)Check_Starter_signal;
const void *off_235C0 = (const void *)Check_Starter_signal;
const void *off_24EC8 = (const void *)Check_Starter_signal;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool CRANK_CheckCamshaft_sub_A7C0();

#pragma address off_234D8=0x234D8
#pragma address off_24BEC=0x24BEC

const void *off_234D8 = (const void *)CRANK_CheckCamshaft_sub_A7C0;
const void *off_24BEC = (const void *)CRANK_CheckCamshaft_sub_A7C0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool Check_PEDRL_1();
#pragma address off_23504=0x23504
const void *off_23504 = (const void *)Check_PEDRL_1;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Get_ADC_Bat_TPS_oxigen();
#pragma address off_270BC=0x270BC
const void *off_270BC = (const void *)Get_ADC_Bat_TPS_oxigen;
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#if (defined(DEF_SIMULATION) && !defined(DEF_CRANK))

void Get_ADC_Knock();
#pragma regsave(Get_ADC_Knock)			
#pragma address off_2409C=0x2409C
const void *off_2409C = (const void *)Get_ADC_Knock;

#endif 

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
static void Get_Manifold_AbsPressure();
#pragma address off_2803C=0x2803C
const void *off_2803C = (const void *)Get_Manifold_AbsPressure;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void UpdateOutputSync();
#pragma address off_28034=0x28034
const void *off_28034 = (const void *)UpdateOutputSync;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Knock_Output_Calc_sub_AC96();
#pragma address off_24734=0x24734
const void *off_24734 = (const void *)Knock_Output_Calc_sub_AC96;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Update_Gen_G_output();

#pragma address off_2408C=0x2408C
#pragma address off_26DA8=0x26DA8

const void *off_2408C = (const void *)Update_Gen_G_output;
const void *off_26DA8 = (const void *)Update_Gen_G_output;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void PDIOR_Stuff_sub_AD3C();
#pragma address off_27404=0x27404
const void *off_27404 = (const void *)PDIOR_Stuff_sub_AD3C;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_AD94();
#pragma address off_27524=0x27524
const void *off_27524 = (const void *)sub_AD94;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void PWM_EGR_EVAP_O2H();
#pragma address off_28030=0x28030
const void *off_28030 = (const void *)PWM_EGR_EVAP_O2H;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_B0BC(u16 r1);
#pragma address off_1D404=0x1D404
const void *off_1D404 = (const void *)sub_B0BC;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Read_Ports_And_Registers_sub_B114();
#pragma address off_273FC=0x273FC
#pragma address off_E9D8=0xE9D8
const void *off_273FC = (const void *)Read_Ports_And_Registers_sub_B114;
const void *off_E9D8 = (const void *)Read_Ports_And_Registers_sub_B114;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void dmac2_dei2();
#pragma address v_dmac2_dei2=0x130
const void *v_dmac2_dei2 = dmac2_dei2;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void cmti0();
#pragma address v_cmti0=0x2F0
const void *v_cmti0 = cmti0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void atu41_imi4B();
#pragma address v_atu41_imi4B=0x204
const void *v_atu41_imi4B = atu41_imi4B;
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma section _HARDWARE

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*
#ifndef __GNUC__

#pragma inline_asm(__push_regs)

static void __push_regs()
{
	MOV.L       R1,@-R15
	MOV.L       R2,@-R15
	MOV.L       R3,@-R15
	MOV.L       R7,@-R15
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma inline_asm(__pop_regs)

static void __pop_regs()
{
	MOV.L       @R15+, R7
	MOV.L       @R15+, R3
	MOV.L       @R15+, R2
	MOV.L       @R15+, R1
}

#else

inline void __push_regs()
{
	asm("MOV.L       R1,@-R15");
	asm("MOV.L       R2,@-R15");
	asm("MOV.L       R3,@-R15");
	asm("MOV.L       R7,@-R15");
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline void __pop_regs()
{
	asm("MOV.L       @R15+, R7");
	asm("MOV.L       @R15+, R3");
	asm("MOV.L       @R15+, R2");
	asm("MOV.L       @R15+, R1");
}

#endif 
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*#pragma inline_asm(__push_r8_r14)

static void __push_r8_r14()
{
	MOV.L       R8,@-R15
	MOV.L       R9,@-R15
	MOV.L       R10,@-R15
	MOV.L       R11,@-R15
	MOV.L       R12,@-R15
	MOV.L       R13,@-R15
	MOV.L       R14,@-R15
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma inline_asm(__pop_r8_r14)

static void __pop_r8_r14()
{
	MOV.L       @R15+, R14
	MOV.L       @R15+, R13
	MOV.L       @R15+, R12
	MOV.L       @R15+, R11
	MOV.L       @R15+, R10
	MOV.L       @R15+, R9
	MOV.L       @R15+, R8
}*/

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma regsave(SysInit_sub_9D2C)

void SysInit_sub_9D2C()
{
	SysInit_HW_C0CC();

	WPDR16(reg_PADRH, 0x4800);

	WPDR16(reg_PBDRH, 0x5500);

	reg_PCDR = 5;

	WPDR16(reg_PDDRH, 0x108);

	WPDR16(reg_PEDRH, 0xC00);

	WPDR16(reg_PFDRH, 0x6000);

	WPDR16(reg_PGDRH, 0);
	WPDR16(reg_PHDRH, 0x4000);
	WPDR16(reg_PJDRH, 0x10F0);
	WPDR16(reg_PKDRH, 0x3F);

	if (byte_1046 != 0)
	{
		WFLAG(reg_PFDRL, 1, ZRO(byte_1046, 0xC) || AND(byte_1046, 0xC));
	};

	SET(reg_PBDRL, 8);

	reg_PAIOR = 0x7F00;

	reg_PBIOR = 0xF5FF;

	reg_PCIOR = 5;

	reg_PDIOR = 0x3FFF;

	reg_PEIOR = 0xFFF8;

	reg_PFIOR = 0xFFFF;
	reg_PGIOR = 1;
	reg_PHIOR = 0xF80F;

	reg_PJIOR = 0x13FF;

	reg_PKIOR = 0xFEFF;

	reg_PBIR = 8;
	reg_PKIR = 0x3F;

	reg_PACRH = 0x5100;
	reg_PACRL = 0x4055;

	reg_PBCRH = 0x0055;
	reg_PBCRL = 0x5515;

	SET(reg_PBCRL, 0x40);

	reg_PCCR = 0x155;

	reg_PDCRH = 0;
	reg_PDCRL = 0x15;

	reg_PECR = 0;

	reg_PFCRH = 0x8000;
	reg_PFCRL = 0;

	reg_PGCR = 0x54;

	reg_PHCR = 0;

	reg_PJCRH = 0x5400;

	SET(reg_PJCRH, 0x10);

	reg_PJCRL = 0x5540;

	SET(reg_PJCRL, 0x10);

	reg_PKCRH = 0x5550;
	reg_PKCRL = 0x555;

	SysInit_ADC();

	SysInit_ATU_0_DMA_2();

	SysInit_HCAN();

	SysInit_ATU_2A_2B_3_4_5_8_10();

	SysInit_ATU_2E_2F_2G_out();

	SysInit_ICR_C204();

	SysInit_ATU_C476();

	Init_ATU_sub_C5D2();

	SysInit_sub_C87C();

	SysInit_ATU_CA34();

	SysInit_ATU_6_7();

	SysInit_SCI_CF6C();

	SysInit_Reset_Crank_Flags();

	Init_ATU_0_2B();

	SysInit_ATU_Misc_1_sub_DCDC();

	SysInit_ATU_Misc_2_sub_E3A2();

	Init_ATU_Counters_Control_sub_E4D0();

	SysInit_INTC_sub_E598();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma regsave(sub_A078)

void sub_A078()
{
	Init_HW_C164();                                      
	Init_ATU_0_DMA_2();                                  
	Init_HCAN();                                         
	Init_ATU_2A_2B_3_4_5_8_10();                         
	Init_ATU_2E_2F_2G_out();                             
	sub_C234();                                          
	sub_C4EE();                                          
	sub_C646();                                          
	sub_C8E0();                                          
	sub_CAA8();                                          
	Init_ATU_6_7();                                      
	sub_D008();                                          
	sub_D99A();                                          
	sub_DE24();                                          
	sub_E3EA();                                          
	Init_ATU_Counters_Control_sub_E4D0();                
	sub_E5FC();   

	__disable_irq();  

	reg_PAIOR = 0x7F00;

	reg_PBIOR = 0xF5FF;

	reg_PCIOR = 5;

	reg_PDIOR = 0x3FFF;

	reg_PEIOR = 0xFFF8;

	reg_PFIOR = 0xFFFF;

	reg_PGIOR = 1;

	reg_PHIOR = 0xF80F;

	reg_PJIOR = 0x13FF;

	reg_PKIOR = 0xFEFF;

	__enable_irq();

	__disable_irq();

	reg_PBIR = 8;

	reg_PKIR = 0x3F;

	__enable_irq();

	__disable_irq();

	reg_PACRH = 0x5100;

	reg_PACRL = 0x4055;

	reg_PBCRH = 0x55;

	reg_PBCRL = 0x5515;

	SET(reg_PBCRL, 0x40);

	reg_PCCR = 0x155;

	reg_PDCRH = 0;

	reg_PDCRL = 0x15;

	reg_PECR = 0;

	reg_PFCRH = 0x8000;

	reg_PFCRL = 0;

	reg_PGCR = 0x54;

	reg_PHCR = 0;

	reg_PJCRH = 0x5400;

	SET(reg_PJCRH, 0x10);

	SET(reg_PJCRL, 0x5540);

	reg_PKCRH = 0x5550;

	reg_PKCRL = 0x555;

	__enable_irq();

	sub_A324();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregsave(sub_A324)

static void sub_A324()
{
//	__push_regs();

	__disable_irq();

	if (ZRO(wMUT9B_Output_Pins, 0x8000))
	{
		SET(word_FFFF9ADA, 4);
		SET(reg_PJCRL, 0x10);
	}
	else
	{
		CLR(word_FFFF9ADA, 4);
		CLR(reg_PJCRL, 0x10);
	};

	__enable_irq();

//	__pop_regs();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void sub_A374()
{
//	const u32 r9 = ~0x10;
//	const u32 r8 = ~2;
//	const u32 r2 = 0x200;
//	const u32 r1 = ~0x200;

	__disable_irq();

	u32 r13 = MUT_00_01_FLAGS;

	WBIT(r13, RT_0_bit, ZRO(bMUTB7, 1));

	WBIT(r13, RT_1_bit, ZRO(reg_PEDRL, 2));

	WBIT(r13, POWER_STEERING, bMUTB8 & 4);

	WBIT(r13, AC_SWITCH, ZRO(bMUTB8, 1));

	SET(r13, DRIVE_ALWAYS_1);

	WBIT(r13, STARTER, ZRO(reg_PEDRL, 4));

	WBIT(r13, RT_7_bit, bMUTBA & 4);
	
	WBIT(r13, RT_FR, ZRO(reg_PJDRH, 4));

	WBIT(r13, RT_10_bit, ZRO(word_FFFF8868, 0x20));

	WBIT(r13, SPEED_ADJUST, bMUTB9 & 1);

	WBIT(r13, FIX_TIMING, bMUTB9 & 4);

	WBIT(r13, RT_13_bit, word_FFFF8868 & 0x40);

	WBIT(r13, RT_14_bit, ZRO(word_FFFF8868, 0x10));

	WBIT(r13, RT_15_bit, bMUTB7 & 4);

	MUT_00_01_FLAGS = r13;

	__enable_irq();

	__disable_irq();

	r13 = MUT_03_FLAGS;

	WBIT(r13, 2, bMUTB7 & 2);

	WBIT(r13, 4, ZRO(bMUTB8, 2));

	WBIT(r13, 0x10, word_FFFF8868 & 0x80);

	WBIT(r13, 0x20, reg_PADRH & 0x80);

	WBIT(r13, 0x40, ZRO(word_FFFF8868, 4));

	WBIT(r13, 0x80, ZRO(word_FFFF8868, 1));

	WBIT(r13, 0x200, word_FFFF8868 & 1);

	MUT_03_FLAGS = r13;

	__enable_irq();

	__disable_irq();

	r13 = word_FFFF8896;

	WBIT(r13, 0x10, bMUTB7 & 2);

	WBIT(r13, 0x100, bMUTB7 & 8);

	WBIT(r13, 0x200, bMUTB8 & 8);

	WBIT(r13, 0x400, bMUTB9 & 8);

	WBIT(r13, 0x800, bMUTBA & 8);

	WBIT(r13, 2, reg_PJDRH & 8);

	word_FFFF8896 = r13;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PADR_Stuff_sub_A5F8()
{
	__disable_irq();

	u32 r1 = portA_state;

	WBIT(r1, 1, ZRO(reg_PADRL, 1));

	WBIT(r1, 2, ZRO(reg_PADRL, 0x80));

	WBIT(r1, 8, ZRO(bMUTB7, 2));

	WBIT(r1, 4, ZRO(bMUTB8, 2));

	WBIT(r1, 0x20, ONE(reg_PADRH, 0x80));

	WBIT(r1, 0x40, ZRO(reg_PEDRL, 4));

	WBIT(r1, 0x80, ONE(bMUTBA, 4));

	WBIT(r1, 0x100, ONE(bMUTB9, 2));

	WBIT(r1, 0x400, sub_C2CC());

	WBIT(r1, 0x800, sub_C304());

	WBIT(r1, 0x1000, ONE(bMUTB7, 4));

	WBIT(r1, 0x2000, true);

	portA_state = r1;

	__enable_irq();

	__disable_irq();

	WBIT(word_FFFF93CC, 0x800, sub_C33C());

	__enable_irq();

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Get_All_ADC()
{
	u16 res;

	GetADC(2, &wMUT07_CoolTemp_ADC8bit, &adc_CoolTemp_10bit_MUTCF);

	GetADC(3, &wMUT3A_AirTemp_ADC8bit, &adc_AirTemp_10bit);

	GetADC(9, &wMUT13_Front_O2_ADC8bit, &res);

	GetADC(10, &wMUT3C_Rear_O2_ADC8bit, &res);

	GetADC(7, &ADC_07_8bit, &res);

	GetADC(8, &ADC_08_8bit, &res);

	GetADC(11, &wMUT38_Manifold_DiffPressure_ADC8bit, &res);

	GetADC(12, &wMUT39_Fuel_Tank_Pressure_ADC8bit, &fuel_Tank_Pressure_ADC10bit);

	GetADC(14, &wMUT87_Fuel_Temp_ADC8bit, &fuel_Temp_ADC10bit);

	GetADC(13, &wMUT88_Fuel_Level_ADC8bit, &res);

	GetADC(8, &wMUT97_ADC_8_8bit, &res);

	GetADC(15, &wMUT83_ADC_15_8bit, &res);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Get_ADC_Bat_TPS_oxigen()
{
	u16 res;//, res1, res2;

	GetADC(1, &wMUT14_Battery_Level_ADC8bit, &res);

//	GetADC(5, &res1, &res);

//	wMUT17_TPS_ADC8bit = res1;

//	TPS_ADC10bit = res;

	GetADC(5, &wMUT17_TPS_ADC8bit, &TPS_ADC10bit);

	GetADC(9, &oxigen_ADC8bit, &res);

	GetADC(7, &null_ADC_7_8bit, &res);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Get_ADC_Knock()
{
	u16 res;

	GetADC(6, &wMUT30_Knock_Voltage, &res);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Zero_MUT3B()
{
	wMUT3B_Masked_Map_Index = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Get_Manifold_AbsPressure()
{
	u16 res;

	GetADC(4, &wMUT1A_Manifold_AbsPressure_ADC8bit, &res);

	wMUT8C_Manifold_AbsPressure_ADC8bit = wMUT1A_Manifold_AbsPressure_ADC8bit;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void UpdateOutputAsync()
{
	__disable_irq();

	WFLAG(reg_PFDRL, 0x20, wMUT9A_Ligths_Bit_Array & 0x80);

	__enable_irq();

	__disable_irq();

	WFLAG(reg_PFDRL, 2, wMUT9A_Ligths_Bit_Array & 1);

	__enable_irq();

	__disable_irq();

	WFLAG(reg_PGDRL, 1, ZRO(wMUT9A_Ligths_Bit_Array, 8));

	__enable_irq();

	if (byte_1046/*0*/ != 0)
	{
		__disable_irq();

		bool c1 = !(wMUT9A_Ligths_Bit_Array & 4);
		bool c2 = !(byte_1046 & 8);

		WFLAG(reg_PFDRL, 1, c1 ^ c2);

		__enable_irq();
	};

	if (bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 8)
	{
		__disable_irq();

		WFLAG(reg_PBDRH, 0x40, ZRO(wMUT9A_Ligths_Bit_Array, 0x2000));

		__enable_irq();
	};

	if (wMUTD1_BitMap_FAA & FAA_3_IMMO)
	{
		__disable_irq();

		WFLAG(reg_PFDRL, 4, OutPort_FFFF8876 & 8);

		__enable_irq();
	};

	if (bMUTD2_FBA_MAF_MAP_FLAG & 0x40)
	{
		__disable_irq();

		WFLAG(reg_PJDRL, 1, OutPort_FFFF8876 & 0x10);

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void UpdateOutputSync()
{
	__disable_irq();

	WFLAG(reg_PFDRH, 0x80, ZRO(wMUT9B_Output_Pins, 2));

	__enable_irq();

	if (wMUTD1_BitMap_FAA & FAA_13_2000)
	{
		__disable_irq();

		WFLAG(reg_PFDRH, 1, ONE(wMUT9B_Output_Pins, 4));

		__enable_irq();

		__disable_irq();

		WFLAG(reg_PFDRH, 2, ONE(wMUT9B_Output_Pins, 8));

		__enable_irq();
	};

	if (byte_1040/*0*/ != 0)
	{
		__disable_irq();

		WFLAG(reg_PFDRH, 0x10, ONE(wMUT9B_Output_Pins, 0x40));

		__enable_irq();
	};

	if (byte_104C/*0*/ != 0)
	{
		__disable_irq();

		WFLAG(reg_PJDRH, 1, ONE(wMUT9B_Output_Pins, 0x200));

		__enable_irq();

		__disable_irq();

		WFLAG(reg_PJDRH, 2, ONE(wMUT9B_Output_Pins, 0x100));

		__enable_irq();
	};

	if (bMUTD2_FBA_MAF_MAP_FLAG & 8)
	{
		__disable_irq();

		WFLAG(reg_PADRH, 8, ONE(wMUT9B_Output_Pins, 0x400));

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Knock_Output_Calc_sub_AC96()
{
	if (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN)
	{
		__disable_irq();
	
//		WFLAG(reg_PHDRL, 4, KNOCK_FLAG2_FFFF887A & 2);

		reg_PHDRL = (reg_PHDRL & ~4) | ((KNOCK_FLAG2_FFFF887A << 1) & 4);

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Update_Gen_G_output()
{
	__disable_irq();

	WFLAG(reg_PFDRL, 0x80, ZRO(KNOCK_FLAG2_FFFF887A, KNOCK_F2_01));

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PDIOR_Stuff_sub_AD3C()
{
	__disable_irq();

	//u32 r11 = reg_PDDRH & 1 ^ 1;

	//u32 r12 = reg_PDDRH & ~1;

	//reg_PDDRH = r11 & 1 | r12;
	
	reg_PDDRH ^= 1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_AD72()
{
	__disable_irq();

	CLR(reg_PBDRH, 0x80);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_AD94()
{
	__disable_irq();

	WPDR16(reg_PEDRH, RPDR16(reg_PEDRH) & 0xF3FF | word_8AD4[stepperPinOutIndex & 3]);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PWM_EGR_EVAP_O2H()
{
	u32 r13 = pwm_Counter + 1;

	if (r13 >= 48)
	{
		r13 = 0;
	};

	pwm_Counter = r13;

	if (EGRONOFF_103D != 0)
	{
		u32 r1 = wMUT85_EGR_Solenoid * 3 >> 2;

		r1 = (r1 + 1) >> 1;

		__disable_irq();

		WFLAG(reg_PEDRH, 1, r1 > pwm_Counter);

		__enable_irq();
	};

	if ((wMUTD1_BitMap_FAA & FAA_12_EVAP) && (wMUT9B_Output_Pins & 0x8000))
	{
		u32 r1 = wMUT4A_Purge_Control_Duty * 3 >> 2;

		r1 = (r1 + 1) >> 1;

		__disable_irq();

		WFLAG(reg_PJDRL, 4, r1 > pwm_Counter);

		__enable_irq();
	};

	if (wMUTD1_BitMap_FAA & FAA_14_HEATER_O2)
	{
		u32 r1 = O2F_Heater_Duty * 3 >> 2;

		r1 = (r1 + 1) >> 1;

		__disable_irq();

		WFLAG(reg_PEDRH, 0x10, r1 > pwm_Counter);

		__enable_irq();

		if (wMUTD1_BitMap_FAA & FAA_2_REAR_O2_B2)
		{
			u32 r1 = word_FFFF8D1A * 3 >> 2;

			r1 = (r1 + 1) >> 1;

			__disable_irq();

			WFLAG(reg_PEDRH, 0x40, r1 > pwm_Counter);

			__enable_irq();
		};

		if (wMUTD1_BitMap_FAA & FAA_1_REAR_O2)
		{
			u32 r1 = O2R_Heater_Duty * 3 >> 2;

			r1 = (r1 + 1) >> 1;

			__disable_irq();

			WFLAG(reg_PEDRH, 0x20, r1 > pwm_Counter);

			__enable_irq();
		};

		if (wMUTD1_BitMap_FAA & FAA_2_REAR_O2_B2)
		{
			u32 r1 = word_FFFF8D1C * 3 >> 2;

			r1 = (r1 + 1) >> 1;

			__disable_irq();

			WFLAG(reg_PEDRH, 0x80, r1 > pwm_Counter);

			__enable_irq();
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SetDuty_6D(u16 v)
{
	__disable_irq();

	reg_BFR6D = (u32)v >> 1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void UpdateFanOutputDuty()
{
	SetDuty_6D(wMUT84_Thermo_Fan_Duty << 1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_B0BC(u16 r1)
{
//	__push_regs();

	const u16 r2 = 25000;

	if (r1 != 0 && r1 < 5)	{ r1 = 5; };

	word_FFFF8D28 = r1;

	r1 = Mul_Fix8_Lim_FFFF(r1, r2);

	if (r1 > r2) { r1 = r2; };

	__disable_irq();

	ufix8_FFFF9ADE = r2;

	ufix8_FFFF9AE0 = r1;

	__enable_irq();

//	__pop_regs();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Read_Ports_And_Registers_sub_B114()
{
	__disable_irq();

	reg_DCNT8P = 0;
	reg_DCNT8O = 0;
	reg_DCNT8N = 0;
	reg_DCNT8M = 0;
	reg_DCNT8L = 0;
	reg_DCNT8K = 0;

	CLR(reg_SYSCR, 1);

	reg_PJIOR = 0;
	reg_PHIOR = 0;
	reg_PGIOR = 0;
	reg_PFIOR = 0;
	reg_PEIOR = 0;
	reg_PDIOR = 0;
	reg_PCIOR = 0;
	reg_PBIOR = 0;
	reg_PAIOR = 0;

	reg_PKCRL = 0;
	reg_PKCRH = 0;
	reg_PJCRL = 0;
	reg_PJCRH = 0;

	reg_PJCRL = 0;
	reg_PJCRH = 0;

	reg_PHCR = 0;
	reg_PGCR = 0;

	reg_PFCRL = 0;
	reg_PFCRH = 0;

	reg_PECR = 0;
	reg_PCCR = 0;

	reg_PDCRL = 0;
	reg_PDCRH = 0;

	reg_PBCRL = 0;
	reg_PBCRH = 0;

	reg_PACRL = 0;
	reg_PACRH = 0;

	for (;;);

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ADC()
{
	reg_ADCSR1 = 0;

	reg_ADCSR0 = 0;

	unk_FFFFF858 = 8;

	reg_ADCR0 = reg_ADCR1 = unk_FFFFF859 = 0x4F;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void GetADC(byte ch, u16 *res8, u16 *res10)
{
#ifdef DEF_SIMULATION

	u16 *v = adc_Hooked_value;

	*res8 = (*res10 = v[ch]) >> 2;

#else

	__disable_irq();

	WFLAG(reg_PHDRL, 2, ch & 0x20);

	WFLAG(reg_PHDRL, 1, ch & 0x40);
	
	byte r0 = 1;

	while(--r0) {};

	ch &= 0x1F;

	u32 v = (ch < 12) ? GetADC0(ch) : GetADC1(ch - 12);

	*res10 = v;

	*res8 = (u32)v >> 2;

	__enable_irq();

#endif
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 GetADC0(byte r1)
{
//	u16 *r2 = reg_ADDR + r1;

	reg_ADCR0 = 0x4F;

	reg_ADCSR0 = r1;

	SET(reg_ADCR0, 0x20);

	u32 t = 5;

	while(--t) {};

	while(ZRO(reg_ADCSR0, 0x80)) {};

	CLR(reg_ADCSR0, 0x80);

	return ((u32)reg_ADDR[r1] << 8) >> 2;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


static u16 GetADC1(byte r1)
{
//	u16 *r2 = reg_ADDR + r1;

	reg_ADCR1 = 0x4F;

	reg_ADCSR1 = r1;

	SET(reg_ADCR1, 0x20);

	u32 t = 5;

	while(--t) {};

	while(ZRO(reg_ADCSR1, 0x80)) {};

	CLR(reg_ADCSR1, 0x80);

	return ((u32)reg_ADDR[r1] << 8) >> 2;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SysInit_ATU_0_DMA_2()
{
	__disable_irq();

	CLR(reg_TSR0, 2);

	reg_TIOR0 = reg_TIOR0 & 0xC | 8;

	CLR(reg_TIER0, 2);

	CLR(reg_CHCR2, 5);

	word_FFFF898C = 0;

	word_FFFF89B6 = 0;

	word_FFFF9AB0 = 0;

	word_FFFF89AE = 0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Init_ATU_0_DMA_2()
{
	__disable_irq();

	CLR(reg_TIER0, 2);

	CLR(reg_CHCR2, 5);

	reg_TIOR0 = reg_TIOR0 & 0xC | 8;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void dmac2_dei2_B618()
{
//	void *r2 = dword_FFFF9A60;

	__disable_irq();

	CLR(reg_CHCR2, 3);

	u32 r14_8 = 1;

	while(--r14_8);

	u16 r13 = reg_DMATCR2;

	if (r13 >= word_FFFF9AB2)
	{
		word_FFFF9AB0 += word_FFFF9AB2 - r13;	
	};

	u32 r1 = r13;

	if (r13 <= 16)
	{
		u32 r10 = 16 - r13;

		dword_FFFF9A60[0] = dword_FFFF9A60[r10];
		dword_FFFF9A60[1] = dword_FFFF9A60[r10+1];
		reg_DAR2 = dword_FFFF9A60 + 2;

		reg_DMATCR2 = 16;

		r1 = 16;
	};

	word_FFFF9AB2 = r1;

	word_FFFF9AB4 = r1;

	reg_SAR2 = &reg_ICR0BH;

	reg_CHCR2 = 0x120124;

	SET(reg_CHCR2, 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_HCAN()
{
	CLR(reg_MCR, 0x80);

	SET(reg_MCR, 0x20);

	reg_IMR = ~0x100;

	reg_MBIMR = ~0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Init_HCAN()
{
	__disable_irq();

	CLR(reg_MCR, 0x80);

	SET(reg_MCR, 0x20);

	reg_IMR = ~0x100;

	reg_MBIMR = ~0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ATU_2A_2B_3_4_5_8_10()
{
	__disable_irq();

	reg_PSCR1 = 3; // 4 MHz (Channel: 0, 1, 2, 3, 4, 5, 8, 11)

	reg_PSCR4 = 3; // 4 MHz (Channel: 10)

	reg_TCR2A = 0x34; // 250kHz
	reg_TCR2B = 0x34;
	reg_TCR3 = 0x34;
	reg_TCR4 = 0x34;
	reg_TCR5 = 0x34;

	reg_TCR8 = reg_TCR8 & 0xF | 0x50;

	reg_TIOR10 = 0x30;
	reg_TCR10 = 0;
	reg_TIER10 = 0x10;
	reg_TMDR = 0;
	reg_TSTR1 = reg_TSTR1 & 2 | 0x7D;

	reg_CMCOR0 = 2495; // period
	reg_CMCSR0 = 0x40; // Pô/8 = 2MHz
	CLR(reg_CMCSR0, 0x80); // reset irq
	SET(reg_CMSTR, 1);		// start CMT0

	word_FFFF9AD2 = reg_TCNT2A + 312;

	CLR(reg_TIER3, 0x3A0);

	reg_TIOR4A = 0x11;
	reg_TIOR4B = 0x11;
	CLR(reg_TIER3, 0x40);

	downTimer_801 = 1;

	__enable_irq();

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Init_ATU_2A_2B_3_4_5_8_10()
{
	__disable_irq();

	reg_PSCR1 = reg_PSCR4 = 3;	// 4 MHz

	reg_TCR2A = 0x34;	// internal clock 250 kHz
	reg_TCR2B = 0x34;
	reg_TCR3 = 0x34;
	reg_TCR4 = 0x34;
	reg_TCR5 = 0x34;

	reg_TCR8 = reg_TCR8 & 0xF | 0x50;

	reg_TIOR10 = 0x30;

	reg_TCR10 = 0;

	reg_TIER10 = 0x10;

	reg_TMDR = 0;

	reg_TSTR1 = reg_TSTR1 & 2 | 0x7D;

    // peripheral clock = 16MHz
    // CMT0 CLK = 2 MHz
    // CMT0 Period = 2000000 / 2495 = 801.6 Hz

	reg_CMCOR0 = 2495;

	reg_CMCSR0 = reg_CMCSR0 & ~0x43 | 0x40;

	SET(reg_CMSTR, 1);

	CLR(reg_TIER3, 0x3A0);

	reg_TIOR4A = 0x11;
	reg_TIOR4B = 0x11;

	CLR(reg_TIER3, 0x40);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void WaitDownTimer801()
{
#ifndef DEF_SIMULATION
	for(;;)
	{
		if (downTimer_801 == 0 || downTimer_801 > 8) break;
	};
#endif

	__disable_irq();

	downTimer_801 = 8;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ATU_2E_2F_2G_out()
{
	__disable_irq();

	reg_TIOR2C = 0x22;
	
	reg_TIOR2D = reg_TIOR2D & ~7 | 2;

	u32 t = reg_TCNT2A + 2;

	reg_GR2G = t;
	reg_GR2F = t;
	reg_GR2E = t;

	CLR(reg_TSR2A, 0x70);

	SET(reg_TIER2A, 0x10);
	SET(reg_TIER2A, 0x20);
	CLR(reg_TIER2A, 0x40);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Init_ATU_2E_2F_2G_out()
{
	__disable_irq();

	CLR(reg_TIOR2C, 0x44);
	
	CLR(reg_TIOR2D, 4);

	SET(reg_TIER2A, 0x10);
	SET(reg_TIER2A, 0x20);
	CLR(reg_TIER2A, 0x40);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SetIgnCoilChargeStartTime(u16 mask, u16 v)
{
	__disable_irq();

	u32 r13 = v;

	v -= reg_TCNT2A + 2;

	if (v & 0x8000)
	{
		r13 = reg_TCNT2A + 2;
	};

	// 0 output on GR compare-match

	if (mask & 1) { reg_GR2E = r13; CLR(reg_TSR2A, 0x10); reg_TIOR2C = reg_TIOR2C & 0xF8 | 1; };	
	if (mask & 2) { reg_GR2F = r13; CLR(reg_TSR2A, 0x20); reg_TIOR2C = reg_TIOR2C & 0x8F | 0x10; };
	if (mask & 4) { reg_GR2G = r13; CLR(reg_TSR2A, 0x40); reg_TIOR2D = reg_TIOR2D & 0xF8 | 1; };

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void SetIgnSparkStartTime(u16 mask, u16 v)
{
	__disable_irq();

	u32 r13 = v;

	v -= reg_TCNT2A + 2;

	if (v & 0x8000)
	{
		r13 = reg_TCNT2A + 2;
	};

	// 1 output on GR compare-match

	if (mask & 1) { reg_GR2E = r13; CLR(reg_TSR2A, 0x10); reg_TIOR2C = reg_TIOR2C & 0xF8 | 2; };
	if (mask & 2) { reg_GR2F = r13; CLR(reg_TSR2A, 0x20); reg_TIOR2C = reg_TIOR2C & 0x8F | 0x20; };
	if (mask & 4) { reg_GR2G = r13; CLR(reg_TSR2A, 0x40); reg_TIOR2D = reg_TIOR2D & 0xF8 | 2; };

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Disable_Ign_Handler(u16 v)
{
	__disable_irq();

	u32 r13 = reg_TCNT2A;

	r13 -= 1;

	if (v & 1)
	{
		reg_GR2E = r13;

		CLR(reg_TSR2A, 0x10);
	};

	if (v & 2)
	{
		reg_GR2F = r13;

		CLR(reg_TSR2A, 0x20);
	};

	if (v & 4)
	{
		reg_GR2G = r13;

		CLR(reg_TSR2A, 0x40);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Disable_Coil_Charge(u16 mask)
{
	__disable_irq();

	if (mask & 1)
	{
		reg_GR2E = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x10);

		reg_TIOR2C = reg_TIOR2C & 0xF8 | 2;

#ifndef DEF_SIMULATION
		while(ZRO(reg_TSR2A, 0x10)) ;
#endif
	};

	if (mask & 2)
	{
		reg_GR2F = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x20);

		reg_TIOR2C = reg_TIOR2C & 0x8F | 0x20;

#ifndef DEF_SIMULATION
		while(ZRO(reg_TSR2A, 0x20)) ;
#endif
	};

	if (mask & 4)
	{
		reg_GR2G = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x40);

		reg_TIOR2D = reg_TIOR2D & 0xF8 | 2;

#ifndef DEF_SIMULATION
		while(ZRO(reg_TSR2A, 0x40)) ;
#endif
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void atu22_IMF2G_event()
{
	__disable_irq();

	Disable_Ign_Handler(4);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 Get_Coil_charge_status()
{
	__disable_irq();

	u32 r1 = reg_PHDRH;

	__enable_irq();

	return (~(r1 >> 4)) & 7;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_HW_C0CC()
{
	reg_SYSCR = 3;

	CLR(reg_ICR, 0x100);

	CLR(reg_DMAOR, 2);
	SET(reg_DMAOR, 1);

	reg_SBYCR = 0x1F;

	WPDR16(reg_MSTCR_wr, 0x3C09);

	u32 r14_4 = reg_TCSR;

	WPDR16(reg_TCSR, 0xA51F);

	WPDR16(reg_TCSR, 0x5A00);

	r14_4 = reg_RSTCSR_rd;

	WPDR16(reg_RSTCSR_wr, 0xA500);

	WPDR16(reg_RSTCSR_wr, 0x5A1F);

	reg_UBBR = 0;

	SET(reg_UBCR, 1);

	reg_FLMCR1 = 0;

	reg_FLMCR2 = 0;

	CLR(reg_RAMER, 8);

	dword_FFFF9AF8 = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Init_HW_C164()
{
	__disable_irq();

	reg_SYSCR = 3;

	CLR(reg_ICR, 0x100);

	SET(reg_DMAOR, 1);

	reg_SBYCR = 0x1F;

	WPDR16(reg_MSTCR_wr, 0x3C09);

	u32 r14_4 = reg_TCSR;

	WPDR16(reg_TCSR, 0xA51F);

	WPDR16(reg_TCSR, 0x5A00);

	r14_4 = reg_RSTCSR_rd;

	WPDR16(reg_RSTCSR_wr, 0xA500);

	WPDR16(reg_RSTCSR_wr, 0x5A1F);

	reg_UBBR = 0;

	SET(reg_UBCR, 1);

	reg_FLMCR1 = 0;

	reg_FLMCR2 = 0;

	CLR(reg_RAMER, 8);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ICR_C204()
{
	__disable_irq();

	SET(reg_ICR, 0xF0);

	CLR(reg_ISR, 0xF0);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_C234()
{
	__disable_irq();

	SET(reg_ICR, 0xF0);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool Reset_IRQ0F()
{
	bool r1 = false;

	__disable_irq();

	if (reg_ISR & 0x80)
	{
		CLR(reg_ISR, 0x80);

		r1 = true;
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool sub_C2CC()
{
	bool r1 = false;

	__disable_irq();

	if (reg_ISR & 0x40)
	{
		CLR(reg_ISR, 0x40);

		r1 = true;
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool sub_C304()
{
	bool r1 = false;

	__disable_irq();

	if (reg_ISR & 0x20)
	{
		CLR(reg_ISR, 0x20);

		r1 = true;
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool sub_C33C()
{
	bool r1 = false;

	__disable_irq();

	if (reg_ISR & 0x10)
	{
		CLR(reg_ISR, 0x10);

		r1 = true;
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PHDR_Stuff_sub_C388()
{
	__disable_irq();

	CLR(reg_PHDRL, 2);

	u32 t = 1;

	while (--t);

	bMUTB7 = ((u32)(RPDR16(reg_PHDRH)) << 1) >> 8;

	SET(reg_PHDRL, 2);
	CLR(reg_PHDRL, 1);

	t = 1;

	while (--t);

	bMUTB8 = ((u32)(RPDR16(reg_PHDRH)) << 1) >> 8;

	CLR(reg_PHDRL, 2);
	SET(reg_PHDRL, 1);

	t = 1;

	while (--t);

	bMUTB9 = ((u32)(RPDR16(reg_PHDRH)) << 1) >> 8;

	SET(reg_PHDRL, 3);

	t = 1;

	while (--t);

	bMUTBA = ((u32)(RPDR16(reg_PHDRH)) << 1) >> 8;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ATU_C476()
{
	__disable_irq();

	CLR(reg_TIER3, 0x7C00);

	// TIO5C (53:Secondary Air System solenoid)
	// TIO5D (57:IC spray relay USDM)


	reg_TCNT5 = 0;

	reg_GR5A = 0x1F;

	reg_TIOR5B = 0x11;

	reg_TIOR5A = (byte_102A/*0*/ != 0) ? 0x1A : 0x1B;

	CLR(reg_TIER9, 1); // CMI9A interrupt requested by CMF9A is disabled

	reg_TCR9A = 2; // falling edge TI9A (41:Alternator FR terminal)

	reg_GR9A = ~0;

	reg_ECNT9A = 0;

	CLR(reg_TSR9, 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_C4EE()
{
	__disable_irq();

	CLR(reg_TIER3, 0x7C00);

	reg_TCNT5 = 0;

	reg_GR5A = 0x1F;

	reg_TIOR5B = 0x11;

	reg_TIOR5A = (byte_102A/*0*/ != 0) ? 0x1A : 0x1B;

	CLR(reg_TIER9, 1);

	reg_TCR9A = 2;

	reg_GR9A = ~0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

u16 atu22_Get_ECNT9A()
{
	__disable_irq();

	u32 r1 = reg_ECNT9A;

	reg_ECNT9A = 0;

	if (reg_TSR9 & 1)
	{
		r1 = 0xFF;

		CLR(reg_TSR9, 1);
	};

	__enable_irq();

	return r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Init_ATU_sub_C5D2()
{
	__disable_irq();

	reg_TIOR2A = 0x11;

	CLR(reg_TSR2A, 1);

	CLR(reg_TIER2A, 1);
	CLR(reg_TIER2A, 2);

	CLR(reg_TIER8, 0xFC00);

	reg_TCNR = 0;
	reg_OTR = 0;
	reg_RLDENR = 0;
	reg_DCNT8P = 0;
	reg_DCNT8O = 0;
	reg_DCNT8N = 0;
	reg_DCNT8M = 0;
	reg_DCNT8L = 0;
	reg_DCNT8K = 0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_C646()
{
	__disable_irq();

	reg_TIOR2A = 0x11;

	CLR(reg_TIER2A, 1);
	CLR(reg_TIER2A, 2);

	CLR(reg_TIER8, 0xFC00);

	reg_TCNR = 0;
	reg_OTR = 0;
	reg_RLDENR = 0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void InjOpenStart(u16 v, u16 mask)
{
	__disable_irq();

	if (v != 0)
	{
		u32 r13 = 0xFFFFFFFF + v;

		if (mask & 1) 	{	reg_DCNT8K = r13; 	};
		if (mask & 2) 	{	reg_DCNT8L = r13; 	};
		if (mask & 4) 	{	reg_DCNT8M = r13; 	};
		if (mask & 8) 	{	reg_DCNT8N = r13; 	};
		if (mask & 16) 	{	reg_DCNT8O = r13; 	};
		if (mask & 32) 	{	reg_DCNT8P = r13; 	};

		SET(reg_DSTR, (mask & 63) << 10);
	};
	
	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

u16 atu22_Get_DSTR_0x3C00()
{
	__disable_irq();

	u32 r1 = reg_DSTR;

	__enable_irq();

	return (r1 >> 10) & 0xF;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_sub_C87C()
{
	__disable_irq();

	CLR(reg_TIER2A, 0x180);

	reg_GR2H = reg_TCNT2A + 2;

	reg_TIOR2D = reg_TIOR2D & 0x8F | 0x20;

	CLR(reg_TSR2B, 0x80);

	CLR(reg_TIER2B, 0x80);

	CLR(reg_TIER2B, 0x13F);

	word_FFFF9AFC = 0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_C8E0()
{
	__disable_irq();

	CLR(reg_TIOR2D, 0x40);

	CLR(reg_TIER2A, 0x180);

	CLR(reg_TIER2B, 0x80);

	CLR(reg_TIER2B, 0x13F);


	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Timer_Counter_Related_sub_C928()
{
	__disable_irq();

	reg_GR2H = reg_TCNT2A + 2;

	CLR(reg_TSR2A, 0x80);

	reg_TIOR2D = reg_TIOR2D & 0x8F | 0x20;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void CRANK5_sub_C990(u16 v)
{
	__disable_irq();

	u32 r13 = v;

	v -= reg_TCNT2A + 2;

	if (v & 0x8000)
	{
		r13 = reg_TCNT2A + 2;
	};

	reg_GR2H = r13;

	CLR(reg_TSR2A, 0x80);

	reg_TIOR2D = reg_TIOR2D & 0x8F | 0x10;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ATU_CA34()
{
	CLR(reg_TIER3, 7);

	reg_TIOR3A = 0x44;

	reg_TIOR3B = reg_TIOR3B & 0xF0 | 4;

	CLR(reg_TSR3, 7);

	CLR(reg_TIER9, 0x3E);

	reg_TCR9B = 0x20;

	reg_TCR9C = 0x22;

	reg_GR9F = ~0;

	reg_GR9E = ~0;

	reg_GR9D = ~0;

	reg_ECNT9F = 0;
	reg_ECNT9E = 0;
	reg_ECNT9D = 0;

	CLR(reg_TSR9, 0x38);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_CAA8()
{
	__disable_irq();

	CLR(reg_TIER3, 7);

	reg_TIOR3A = 0x44;

	reg_TIOR3B = reg_TIOR3B & 0xF0 | 4;

	CLR(reg_TIER9, 0x3E);

	reg_TCR9B = 0x20;

	reg_TCR9C = 0x22;

	reg_GR9F = ~0;

	reg_GR9E = ~0;

	reg_GR9D = ~0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ATU_6_7()
{
	__disable_irq();

    // peripheral clock = 16MHz
    // PSCR2 = PSCR3 = 16MHz;

	reg_PSCR2 = 0;
	reg_PSCR3 = 0;

	// TCLK6A = TCLK6B = 16MHz

	reg_TCR6A = 0;

	// TCLK6C = TCLK7A = 16MHz; TCLK6D = TCLK7B = 500kHz

	reg_TCR6B = 0x50;
	reg_TCR7A = 0x50;

	// TCLK7C = TCLK7D = 500kHz

	reg_TCR7B = 0x55;

	reg_PMDR = 0;
	reg_TIER6 = 0;
	reg_TIER7 = 0;

	// CYLR6A = CYLR6B = CYLR6C = CYLR7A = 4096; 3906.25Hz

	reg_CYLR6C = 4096;
	reg_CYLR6B = 4096;
	reg_CYLR6A = 4096;
	reg_CYLR7A = 4096;

	// CYLR6D = 128; 3906.25Hz

	reg_CYLR6D = 0x80;

	reg_DTR6C = 0;
	reg_DTR6B = 0;
	reg_DTR6A = 0;
	reg_DTR7C = 0;
	reg_DTR7B = 0;
	reg_DTR7A = 0;
	reg_DTR6D = 0;
	reg_DTR7D = 0;

	reg_BFR6C = 0;
	reg_BFR6B = 0;
	reg_BFR6A = 0;
	reg_BFR7C = 0;
	reg_BFR7B = 0;
	reg_BFR7A = 0;
	reg_BFR6D = 0;
	reg_BFR7D = 0;

	reg_TCNT6A = 0;
	reg_TCNT6B = 683;
	reg_TCNT6C = 1366;
	reg_TCNT6D = 0;
	reg_TCNT7A = 2049;
	reg_TCNT7B = 2732;
	reg_TCNT7C = 3415;
	reg_TCNT7D = 0;

	reg_TSTR2 = ~0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Init_ATU_6_7()
{
	__disable_irq();

    // peripheral clock = 16MHz
    // PSCR2 = PSCR3 = 16MHz;

	reg_PSCR2 = 0;
	reg_PSCR3 = 0;

	// TCLK6A = TCLK6B = 16MHz

	reg_TCR6A = 0;

	// TCLK6C = TCLK7A = 16MHz; TCLK6D = TCLK7B = 500kHz

	reg_TCR6B = 0x50;
	reg_TCR7A = 0x50;

	// TCLK7C = TCLK7D = 500kHz

	reg_TCR7B = 0x55;

	reg_PMDR = 0;
	reg_TIER6 = 0;
	reg_TIER7 = 0;

	// CYLR6A = CYLR6B = CYLR6C = CYLR7A = 4096; 3906.25Hz

	reg_CYLR6C = 4096;
	reg_CYLR6B = 4096;
	reg_CYLR6A = 4096;
	reg_CYLR7A = 4096;

	// CYLR6D = 128; 3906.25Hz

	reg_CYLR6D = 0x80;

	reg_TSTR2 = ~0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_SCI_CF6C()
{
	reg_SCI0->SCR = 0;

	CLR(reg_SCI0->SDCR, 8);

	reg_SCI0->SMR_BRR = 0x13F;

	reg_SCI0->SCR = 0x30;


	reg_SCI1->SCR = 0;

	CLR(reg_SCI1->SDCR, 8);

	reg_SCI1->SMR_BRR = 0x13F;

	reg_SCI1->SCR = 0x70;


	reg_SCI2->SCR = 0;

	CLR(reg_SCI2->SDCR, 8);

	reg_SCI2->SMR_BRR = 0x1F;

	reg_SCI2->SCR = 0xB0;


	reg_SCI3->SCR = 0;

	CLR(reg_SCI3->SDCR, 8);

	reg_SCI3->SMR_BRR = 0x13F;

	reg_SCI3->SCR = 0;


	reg_SCI4->SCR = 0;

	CLR(reg_SCI4->SDCR, 8);

	reg_SCI4->SMR_BRR = 0x13F;

	reg_SCI4->SCR = 0;

	reg_DMATCR0 = 0;
	reg_DMATCR1 = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_D008()
{
	u32 r1 = 0x13F;

	u32 r13 = 0x13F;

	u32 r14_8;

	__disable_irq();

	CLR(reg_SCI0->SDCR, 8);
	CLR(reg_SCI1->SDCR, 8);
	CLR(reg_SCI2->SDCR, 8);
	CLR(reg_SCI3->SDCR, 8);
	CLR(reg_SCI4->SDCR, 8);

	if (baudrateFlags_FFFF8882 & 2)
	{
		r13 = 0x2F;
	}
	else if (baudrateFlags_FFFF8882 & 4)
	{
		r13 = 0x1F;
	}
	else if (baudrateFlags_FFFF8882 & 8)
	{
		r13 = 7;
	};

	if (reg_SCI0->SMR_BRR != r13)
	{
		reg_SCI0->SMR_BRR = r13;
	};

	// loc_D0F2

	if (__DMAOPFLAG != 0x37 && ZRO(reg_CHCR1, 1)) 
	{
		r13 = 0x70;

		if (ZRO(TRANSMIT_FLAG_FFFF8E3E, 1))
		{
			r14_8 = reg_SCI0->RDR;
			CLR(reg_SCI0->SSR, 0x78);

			r13 = 0x30;
		};

		if (reg_SCI0->SCR != r13)
		{
			reg_SCI0->SCR = r13;
		};
	};

	// loc_D12E

	if (reg_SCI1->SMR_BRR != r1)
	{
		reg_SCI1->SMR_BRR = r1;
	};

	if (reg_SCI1->SCR != 0x70)
	{
		reg_SCI1->SCR = 0x70;
	};

	if (reg_SCI2->SMR_BRR != 0x1F)
	{
		reg_SCI2->SMR_BRR = 0x1F;
	};

	if (reg_SCI3->SMR_BRR != r1)
	{
		reg_SCI3->SMR_BRR = r1;
	};

	if (reg_SCI3->SCR != 0)
	{
		reg_SCI3->SCR = 0;
	};

	if (reg_SCI4->SMR_BRR != r1)
	{
		reg_SCI4->SMR_BRR = r1;
	};

	if (reg_SCI4->SCR != 0)
	{
		reg_SCI4->SCR = 0;
	};

	if (ZRO(MUT_VAR_9_FFFF8DFC, 0xF000) && ZRO(word_FFFF8DFE, 0x8080))
	{
		CLR(MUT_VAR_9_FFFF8DFC, 0x200);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void COM_sub_D1CC()
{
	mut_sended_len = 0;

	COM_TX_Get();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void COM_Update_TX()
{
	if (reg_SCI0->SSR & 0x80)
	{
		COM_TX_Get();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void COM_TX_Get()
{
	u32 len = mut_sended_len;

	if ((TRANSMIT_FLAG_FFFF8E3E & 1) && len < mut_max_send_len && len < 15)
	{
		reg_SCI0->TDR = mut_send_buf[len];

		CLR(reg_SCI0->SSR, 0x80);

		mut_sended_len += 1;

		SET(TRANSMIT_FLAG_FFFF8E3E, 0x80);

		mut_timeout = 0;
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void COM_SCI0_RXI0()
{
	__disable_irq();

	byte r13 = reg_SCI0->SSR;

	byte r1 = reg_SCI0->RDR;

	CLR(reg_SCI0->SSR, 0x78);

	if(ZRO(TRANSMIT_FLAG_FFFF8E3E, 1))
	{
		CLR(TRANSMIT_FLAG_FFFF8E3E, 0xA0);

		mut_received_Len = 0;
		mut_timeout = 0;
	}
	else
	{
		if (r13 & 0x38)
		{
			SET(TRANSMIT_FLAG_FFFF8E3E, 0x20);
		};

		if (TRANSMIT_FLAG_FFFF8E3E & 0x80)
		{
			CLR(TRANSMIT_FLAG_FFFF8E3E, 0x80);

			mut_received_Len = 0;
			mut_timeout = 0;
		}
		else
		{
			u32 len = mut_received_Len;

			if (len < 11)
			{
				mut_receive_buf[len] = r1;

				SET(TRANSMIT_FLAG_FFFF8E3E, 0x40);

				mut_received_Len += 1;
				mut_timeout = 0;
			};
		};
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_D3E4()
{
	__disable_irq();

	u32 r11 = **off_8AE4;

	reg_SCI2->TDR = r11;

	CLR(reg_SCI2->SSR, 0x80);

	reg_SCI2->SCR = 0xB0;

	word_FFFF8D94 = r11;

	word_FFFF8DB6 = 1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_D4E4()
{
	__disable_irq();

	u32 r3 = reg_SCI2->SSR;

	if (r3 & 0x78)
	{
		byte r1 = reg_SCI2->RDR;

		CLR(reg_SCI2->SSR, 0x78);

		u32 r13 = word_FFFF8DB4;

		if (r13 < 5 && ZRO(r3, 0x38))
		{
			word_FFFF8DA8[r13] = r1;

			word_FFFF8DB4 += 1;
		};
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SCI1_TransStart()
{
	sci1_transCount = 0;

	sub_D56E();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SCI1_TransNext()
{
	if (reg_SCI1->SSR & 0x80)
	{
		sub_D56E();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_D56E()
{
	if (word_FFFF8E40 & 1)
	{
		u32 r13 = sci1_transCount;

		if (r13 < word_FFFF8EAA && r13 < 7)
		{
			reg_SCI1->TDR = word_FFFF8E92[r13];

			CLR(reg_SCI1->SSR, 0x80);

			sci1_transCount += 1;

			SET(word_FFFF8E40, 0x80);

			word_FFFF8EAE = 0;
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SCI0_Transmit_DMA0_Enable(u16 r1, u16 r2)
{
	__disable_irq();

	CLR(reg_CHCR0, 3);

	reg_SAR0 = sci0_transmit_buf + r1 * 52 + 2;

	reg_DAR0 = &reg_SCI0->TDR;

	reg_DMATCR0 = r2;

	reg_SCI0->SCR = reg_SCI0->SCR & 0x1B | 0xA0;


	CLR(reg_CHCR1, 1);

	reg_CHCR0 = 0x11000;

	reg_SCI0->TDR = sci0_transmit_buf[r1 * 52 + 1];

	CLR(reg_SCI0->SSR, 0x80);

	SET(reg_CHCR0, 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SCI0_Recieve_DMA0_Enable(u16 r1)
{
	__disable_irq();

	SET(reg_SCI0->SCR , 0x10);

	u32 r14_8 = reg_SCI0->RDR;

	CLR(reg_SCI0->SSR, 0x78);

	word_FFFF9AD0 = 0;

	CLR(reg_CHCR1, 3);

	reg_SAR1 = &reg_SCI0->RDR;

	reg_DAR1 = recieve_buffer_0 + r1 * 52 + 1;

	reg_DMATCR1 = 0x33;

	reg_SCI0->SCR = reg_SCI0->SCR & 0x3B | 0x40;

	CLR(reg_CHCR0, 1);
	
	reg_CHCR1 = 0x20100;

	SET(reg_CHCR1, 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool SCI0_Check_Transfer_End()
{
	return reg_DMATCR0 == 0 && reg_DMATCR1 == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool SCI0_Check_Errors()
{
	return (reg_SCI0->SSR & 0x38) || word_FFFF9AD0 != 0; 
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool SCI0_Check_PA7()
{
	return ZRO(reg_PADRH, 0x80);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void COM_SCI0_Disable_Transmit_sub_D8C4()
{
	__disable_irq();

	CLR(reg_SCI0->SCR , 0x80);

	CLR(reg_CHCR0, 1);

	CLR(reg_CHCR1, 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_Reset_Crank_Flags()
{
	crank_Flags = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Init_ATU_0_2B()
{
	__disable_irq();

	CLR(crank_Flags, 3);

	CLR(reg_TSR0, 1);

	CLR(reg_TSR2B, 0x40);

	reg_TIOR0 = reg_TIOR0 & ~0x33 | 3;

	SET(reg_TIER0, 1);

	CLR(reg_TIER0, 0x14);

	SET(reg_TIER2B, 0x40);

	crankHT_75 = ~0;

	crankHT_5 = ~0;

	null_crank_dt_ICR0AH_5 = ~0;

	crank_dt_ICR0AH_5 = ~0;

	timer_up_FFFF8522 = ~0;

	timer_up_FFFF8524 = ~0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_D99A()
{
	__disable_irq();

	reg_TIOR0 = reg_TIOR0 & ~0x33 | 3;

	SET(reg_TIER0, 1);

	CLR(reg_TIER0, 0x14);

	SET(reg_TIER2B, 0x40);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ATU_Misc_1_sub_DCDC()
{
	__disable_irq();

	word_FFFF9ADA = 0xAE;

	word_FFFF9AE8 = 0;

	ufix8_FFFF9AE0 = 0;

	word_FFFF9AEC = 0;

	word_FFFF9AE4 = 0;

	word_FFFF9AE6 = 0xFFFF;

	ufix8_FFFF9ADE = 0xFFFF;

	word_FFFF9AEA = 0xFFFF;

	word_FFFF9AE2 = 0xFFFF;

	reg_GR2C = reg_TCNT2A + 6250;

	reg_GR2D = reg_TCNT2A + 7000;

	CLR(reg_TSR2A, 0xC);

	reg_TIOR2B = (reg_TIOR2B & ~7) | ((word_FFFF9ADA & 2) ? 1 : 2);

	SET(reg_TIER2A, 4);

	reg_TIOR2B = (reg_TIOR2B & ~0x70) | ((word_FFFF9ADA & 0x20) ? 0x10 : 0x20);

	CLR(reg_TIER2A, 8);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_ATU_Misc_2_sub_E3A2()
{
	__disable_irq();

	CLR(reg_TIER3, 0x18);

	reg_TIOR3B = reg_TIOR3B & 0xF | 0x50;

	CLR(reg_TSR3, 8);

	word_FFFF9ACC = 0;

	word_FFFF9ACE = 0;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Init_ATU_Counters_Control_sub_E4D0()
{
	__disable_irq();

	CLR(reg_TSTR1, 2);

	reg_TCR1A = 0x35;
	reg_TCR1B = 0x35;

	reg_TIOR1A = 0x44;
	reg_TIOR1B = 4;
	reg_TIOR1C = 0x40;
	reg_TIOR1D = 0x44;

	reg_TIER1A = 0;
	reg_TIER1B = 0;
	reg_DCNT8E = 0;
	reg_DCNT8D = 0;
	reg_DNCT8C = 0;
	reg_DNCT8B = 0;
	reg_DCNT8A = 0;
	reg_DCNT8J = 0;
	reg_DCNT8I = 0;
	reg_DCNT8H = 0;
	reg_DCNT8G = 0;
	reg_DCNT8F = 0;

	reg_TCR8 = reg_TCR8 & 0xF0 | 5;

	CLR(reg_TIER8, 0x3FF);

	reg_TSTR3 = 0;

	reg_TCR11 = 0x35;

	reg_TIOR11 = 0;
	reg_TIER11 = 0;

	CLR(reg_CMSTR, 2);

	CLR(reg_CMCSR1, 0x40);
	SET(reg_CMCSR1, 3);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_INTC_sub_E598()
{
	reg_IPRA = 0;

	reg_IPRC = 0x70B;

	reg_IPRD = 0;

	reg_IPRE = 0x980;

	reg_IPRF = 0;
	reg_IPRG = 0;
	reg_IPRH = 0;
	reg_IPRI = 0;

	reg_IPRJ = 0x500;
	reg_IPRK = 0x3330;
	reg_IPRL = 0;

//	CLR(reg_CHCR3, 7); // Comment for Live Map DMA

	reg_ITVRR1 = 0;
	reg_ITVRR2A = 0;
	reg_ITVRR2B = 0;
	reg_POPCR = 0; 
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_DE24()
{
	__disable_irq();

	SET(word_FFFF9ADA, 0x22);

	CLR(word_FFFF9ADA, 0x40);

	CLR(reg_TIOR2B, 0x44);

	SET(reg_TIER2A, 4);

	CLR(reg_TIER2A, 8);
	
	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_E3EA()
{
	__disable_irq();

	CLR(reg_TIER3, 0x18);

	reg_TIOR3B = reg_TIOR3B & 0xF | 0x50;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_E5FC()
{
	__disable_irq();

	reg_IPRA = 0;

	reg_IPRC = 0x70B;

	reg_IPRD = 0;

	reg_IPRE = 0x980;

	reg_IPRF = 0;
	reg_IPRG = 0;
	reg_IPRH = 0;
	reg_IPRI = 0;

	reg_IPRJ = 0x500;
	reg_IPRK = 0x3330;
	reg_IPRL = 0;

//	CLR(reg_CHCR3, 7); // Comment for Live Map DMA

	reg_ITVRR1 = 0;
	reg_ITVRR2A = 0;
	reg_ITVRR2B = 0;
	reg_POPCR = 0; 

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif // #ifndef DEF_HARDWARE	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

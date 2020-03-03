#ifndef HARDWARE_H__23_11_2018__23_02
#define HARDWARE_H__23_11_2018__23_02

#include "hwreg.h"

#ifdef __MVS
#define DEF_HARDWARE
#endif

//#ifdef DEF_HARDWARE

extern void SysInit_sub_9D2C();
extern void sub_A078();
extern void sub_A324();
extern void sub_A374();
extern void PADR_Stuff_sub_A5F8();
extern bool PEDR_LO_Check_sub_A790();
extern bool Check_Starter_signal();
extern bool CRANK_CheckCamshaft_sub_A7C0();
extern bool Check_PEDRL_1();
extern void F500_Get_All_ADC();
extern void Get_ADC_Bat_TPS_oxigen();
extern void Get_ADC_Knock();
extern void Get_Manifold_AbsPressure();
extern void UpdateOutputAsync();
extern void UpdateOutputSync();
extern void Knock_Output_Calc_sub_AC96();
extern void Update_Gen_G_output();
extern void PDIOR_Stuff_sub_AD3C();
extern void sub_AD72();
extern void sub_AD94();
extern void PWM_EGR_EVAP_O2H();
extern void UpdateFanOutputDuty();
extern void sub_B0BC(u16 r1);
extern void Read_Ports_And_Registers_sub_B114();
extern void SysInit_ATU_0_DMA_2();
extern void PHDR_Stuff_sub_C388();
extern void WaitDownTimer801();
extern void Init_ATU_sub_C5D2();
extern void Init_ATU_0_2B();
extern void Disable_Coil_Charge(u16 mask);
extern void Timer_Counter_Related_sub_C928();
extern u16 atu22_Get_DSTR_0x3C00();
extern void PWM_EGR_EVAP_O2H();
extern void GetADC(byte ch, u16 *res8, u16 *res10);
extern void SetIgnCoilChargeStartTime(u16 mask, u16 v);
extern void SetIgnSparkStartTime(u16 mask, u16 v);
extern u16 atu22_Get_ECNT9A();
extern void InjOpenStart(u16 v, u16 mask);

//#else

/*
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


static void SysInit_sub_9D2C()						{ _SysInit_sub_9D2C();					}
static void sub_A078() 								{ _sub_A078(); 							}
static void sub_A374() 								{ _sub_A374(); 							}
static void PADR_Stuff_sub_A5F8() 					{ _PADR_Stuff_sub_A5F8(); 				}
static void PHDR_Stuff_sub_C388() 					{ _PHDR_Stuff_sub_C388(); 				}
static void WaitDownTimer801()						{ _WaitDownTimer801();					}
static void Init_ATU_sub_C5D2()						{ _Init_ATU_sub_C5D2();					}
static void Init_ATU_0_2B()							{ _Init_ATU_0_2B();						}
static void Disable_Coil_Charge(u16 mask)			{ _Disable_Coil_Charge(mask);			}
static void Timer_Counter_Related_sub_C928()		{ _Timer_Counter_Related_sub_C928();	}				
static void F500_Get_All_ADC()						{ _F500_Get_All_ADC();					}
static void Get_ADC_Bat_TPS_oxigen()				{ _Get_ADC_Bat_TPS_oxigen();			}
static void Get_ADC_Knock()							{ _Get_ADC_Knock();						}
static void Get_Manifold_AbsPressure()				{ _Get_Manifold_AbsPressure();			}	
static void UpdateOutputAsync()						{ _UpdateOutputAsync();					}
static void UpdateOutputSync()						{ _UpdateOutputSync();					}
static void Knock_Output_Calc_sub_AC96()			{ _Knock_Output_Calc_sub_AC96();		}		
static void Update_Gen_G_output()					{ _Update_Gen_G_output();				}
static void PDIOR_Stuff_sub_AD3C()					{ _PDIOR_Stuff_sub_AD3C();				}
static void UpdateFanOutputDuty() 					{ _UpdateFanOutputDuty(); 				}
static void SysInit_ATU_0_DMA_2() 					{ _SysInit_ATU_0_DMA_2(); 				}
static u16	atu22_Get_DSTR_0x3C00()					{ return _atu22_Get_DSTR_0x3C00();		}	
static void PWM_EGR_EVAP_O2H() 						{ _PWM_EGR_EVAP_O2H(); 					}
static void GetADC(byte ch, u16 *res8, u16 *res10) 	{ _GetADC(ch, res8, res10);				}








//#define sub_B0BC							((void(*)(u16))0xB0BC)
//#define Read_Ports_And_Registers_sub_B114	((void(*)(void))0xB114)
//#define sub_AD94							((void(*)(void))0xAD94)
//#define Zero_MUT3B							((void(*)(void))0xA94A)
//#define PEDR_LO_Check_sub_A790				((bool(*)(void))0xA790)
//#define Check_Starter_signal				((bool(*)(void))0xA7A8)
//#define CRANK_CheckCamshaft_sub_A7C0		((bool(*)(void))0xA7C0)
//#define Check_PEDRL_1						((bool(*)(void))0xA7D8)

#endif */

//#define sub_A324							((void(*)(void))0xA324)
//#define sub_AD72							((void(*)(void))0xAD72)


//#define Get_ADC_Knock						((void(*)(void))0xA92C)
//#define Get_Manifold_AbsPressure			((void(*)(void))0xA95A)
//#define F500_Get_All_ADC					((void(*)(void))0xA7F0)
//#define Get_ADC_Bat_TPS_oxigen			((void(*)(void))0xA8DC)

#define      adc_Hooked_value ((u16*)0xFFFF8000)                                                        
#define      cam_sim (*((u32*)0xFFFF8030))

inline bool PEDR_LO_Check_sub_A790()		{ return ZRO(reg_PEDRL, 2); }
inline bool Check_Starter_signal()			{ return (reg_PEDRL & 4) == 0; }
inline bool CRANK_CheckCamshaft_sub_A7C0()	{ return (reg_PADRL & 4) == 0; }
inline bool Check_PEDRL_1()					{ return (reg_PEDRL & 1) != 0; }

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif // HARDWARE_H__23_11_2018__23_02

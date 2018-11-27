#ifndef HARDWARE_H__23_11_2018__23_02
#define HARDWARE_H__23_11_2018__23_02

#include "types.h"

#ifdef DEF_HARDWARE

extern "C" void SysInit_sub_9D2C();
extern "C" void sub_A078();
extern "C" void sub_A324();
extern "C" void sub_A374();
extern "C" void PADR_Stuff_sub_A5F8();
extern "C" bool PEDR_LO_Check_sub_A790();
extern "C" bool Check_Starter_signal();
extern "C" bool CRANK_CheckCamshaft_sub_A7C0();
extern "C" bool Check_PEDRL_1();
extern "C" void F500_Get_All_ADC();
extern "C" void Get_ADC_Bat_TPS_oxigen();
extern "C" void Get_ADC_Knock();
extern "C" void Get_Manifold_AbsPressure();
extern "C" void UpdateOutputAsync();
extern "C" void UpdateOutputSync();
extern "C" void Knock_Output_Calc_sub_AC96();
extern "C" void Update_Gen_G_output();
extern "C" void PDIOR_Stuff_sub_AD3C();
extern "C" void sub_AD72();
extern "C" void sub_AD94();
extern "C" void PWM_EGR_EVAP_O2H();
extern "C" void UpdateFanOutputDuty();
extern "C" void sub_B0BC(u16 r1);
extern "C" void Read_Ports_And_Registers_sub_B114();
extern "C" void SysInit_ATU_0_DMA_2();

#else

#define SysInit_sub_9D2C					((void(*)(void))0x9D2C)
#define sub_A078							((void(*)(void))0xA078)
#define sub_A324							((void(*)(void))0xA324)
#define sub_A374							((void(*)(void))0xA374)
#define PADR_Stuff_sub_A5F8					((void(*)(void))0xA5F8)

#define PEDR_LO_Check_sub_A790				((bool(*)(void))0xA790)

#define Check_Starter_signal				((bool(*)(void))0xA7A8)
#define CRANK_CheckCamshaft_sub_A7C0		((bool(*)(void))0xA7C0)
#define Check_PEDRL_1						((bool(*)(void))0xA7D8)

#define F500_Get_All_ADC					((void(*)(void))0xA7F0)
#define Get_ADC_Bat_TPS_oxigen				((void(*)(void))0xA8DC)
#define Get_ADC_Knock						((void(*)(void))0xA92C)
#define Zero_MUT3B							((void(*)(void))0xA94A)
#define Get_Manifold_AbsPressure			((void(*)(void))0xA95A)
#define UpdateOutputAsync					((void(*)(void))0xA98A)
#define UpdateOutputSync					((void(*)(void))0xAB3C)
#define Knock_Output_Calc_sub_AC96			((void(*)(void))0xAC96)
#define Update_Gen_G_output					((void(*)(void))0xAD06)
#define PDIOR_Stuff_sub_AD3C				((void(*)(void))0xAD3C)
#define sub_AD72							((void(*)(void))0xAD72)
#define sub_AD94							((void(*)(void))0xAD94)
#define UpdateFanOutputDuty					((void(*)(void))0xB096)
#define sub_B0BC							((void(*)(u16))0xB0BC)
#define Read_Ports_And_Registers_sub_B114	((void(*)(void))0xB114)
#define SysInit_ATU_0_DMA_2					((void(*)(void))0xB458)

#endif



#define WaitDownTimer801					((void(*)(void))0xBB36)
#define Init_ATU_sub_C5D2					((void(*)(void))0xC5D2)
#define Init_ATU_0_2B						((void(*)(void))0xD918)
//#define Get_ADC_Knock						((void(*)(void))0xA92C)
//#define Get_Manifold_AbsPressure			((void(*)(void))0xA95A)
#define Disable_Coil_Charge					((void(*)(u16))0xBED8)
//#define F500_Get_All_ADC					((void(*)(void))0xA7F0)
//#define Get_ADC_Bat_TPS_oxigen			((void(*)(void))0xA8DC)

#define      adc_Hooked_value ((u16*)0xFFFF8000)                                                        


#endif // HARDWARE_H__23_11_2018__23_02

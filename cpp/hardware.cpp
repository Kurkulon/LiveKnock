//#include <machine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "hwreg.h"
#include "hardware.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define SysInit_HW_C0CC						((void(*)(void))0xC0CC)

//#define SysInit_ADC							((void(*)(void))0xB284)
static void SysInit_ADC();

//#define SysInit_ATU_0_DMA_2					((void(*)(void))0xB458)
//#define SysInit_HCAN						((void(*)(void))0xB77C)
static void SysInit_HCAN();
//#define SysInit_ATU_2A_2B_3_4_5_8_10		((void(*)(void))0xB7E0)
static void SysInit_ATU_2A_2B_3_4_5_8_10();
#define SysInit_ATU_2E_2F_2G_out			((void(*)(void))0xBB6C)

#define  SysInit_ICR_C204					((void(*)(void))0xC204)
#define  SysInit_ATU_C476					((void(*)(void))0xC476)
#define Init_ATU_sub_C5D2					((void(*)(void))0xC5D2)
#define  SysInit_sub_C87C					((void(*)(void))0xC87C)
#define  SysInit_ATU_CA34					((void(*)(void))0xCA34)

#define SysInit_ATU_6_7						((void(*)(void))0xCC3E)

#define SysInit_SCI_CF6C					((void(*)(void))0xCF6C)
#define SysInit_Reset_Crank_Flags			((void(*)(void))0xD908)
#define Init_ATU_0_2B						((void(*)(void))0xD918)
#define SysInit_ATU_Misc_1_sub_DCDC			((void(*)(void))0xDCDC)
#define SysInit_ATU_Misc_2_sub_E3A2			((void(*)(void))0xE3A2)
#define Init_ATU_Counters_Control_sub_E4D0	((void(*)(void))0xE4D0)
#define SysInit_INTC_sub_E598				((void(*)(void))0xE598)


#define sub_C2CC							((bool(*)(void))0xC2CC)
#define sub_C304							((bool(*)(void))0xC304)
#define sub_C33C							((bool(*)(void))0xC33C)




#define sub_C234							((void(*)(void))0xC234)
#define sub_C4EE							((void(*)(void))0xC4EE)
#define sub_C646							((void(*)(void))0xC646)
#define sub_C8E0							((void(*)(void))0xC8E0)
#define sub_CAA8							((void(*)(void))0xCAA8)
#define sub_D008							((void(*)(void))0xD008)
#define sub_D99A							((void(*)(void))0xD99A)
#define sub_DE24							((void(*)(void))0xDE24)
#define sub_E3EA							((void(*)(void))0xE3EA)
#define sub_E5FC							((void(*)(void))0xE5FC)
#define Init_ATU_Counters_Control_sub_E4D0	((void(*)(void))0xE4D0)
#define Init_HW_C164						((void(*)(void))0xC164)
	
//#define Init_ATU_0_DMA_2         			((void(*)(void))0xB4B4)
static void Init_ATU_0_DMA_2();

//#define Init_HCAN                			((void(*)(void))0xB7A6)
static void Init_HCAN();
//#define Init_ATU_2A_2B_3_4_5_8_10			((void(*)(void))0xB8A0)
static void Init_ATU_2A_2B_3_4_5_8_10();
#define Init_ATU_2E_2F_2G_out 				((void(*)(void))0xBBD6)
#define Init_ATU_6_7						((void(*)(void))0xCD58)

//#define GetADC								((void(*)(byte,u16*,u16*))0xB2B6)
static void GetADC(byte r1, u16 *r2, u16 *r8);
static u16 GetADC0(byte r1);
static u16 GetADC1(byte r1);
	
//extern "C" void HUGE_Method_801_6_Hz();
#define  HUGE_Method_801_6_Hz		((void(*)(void))0x2686C)

#ifdef __GNUC__
extern "C" void SysInit_sub_9D2C() __attribute__ ((section ("P_HARDWARE")));
#endif

#define	word_8AD4				((const u16*)0x8AD4)                                                     

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define sub_A324							((void(*)(void))0xA324)
extern  void sub_A324();
#pragma address off_1D414=0x1D414
const void *off_1D414 = (const void *)sub_A324;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PADR_Stuff_sub_A5F8();
#pragma address off_269A8=0x269A8
const void *off_269A8 = (const void *)PADR_Stuff_sub_A5F8;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool PEDR_LO_Check_sub_A790();
#pragma address off_2587C=0x2587C
const void *off_2587C = (const void *)PEDR_LO_Check_sub_A790;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool Check_Starter_signal();

#pragma address off_1FBBC=0x1FBBC
#pragma address off_235C0=0x235C0
#pragma address off_24EC8=0x24EC8

const void *off_1FBBC = (const void *)Check_Starter_signal;
const void *off_235C0 = (const void *)Check_Starter_signal;
const void *off_24EC8 = (const void *)Check_Starter_signal;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool CRANK_CheckCamshaft_sub_A7C0();

#pragma address off_234D8=0x234D8
#pragma address off_24BEC=0x24BEC

const void *off_234D8 = (const void *)CRANK_CheckCamshaft_sub_A7C0;
const void *off_24BEC = (const void *)CRANK_CheckCamshaft_sub_A7C0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool Check_PEDRL_1();
#pragma address off_23504=0x23504
const void *off_23504 = (const void *)Check_PEDRL_1;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Get_ADC_Bat_TPS_oxigen();
#pragma address off_270BC=0x270BC
const void *off_270BC = (const void *)Get_ADC_Bat_TPS_oxigen;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Get_ADC_Knock();
#pragma address off_2409C=0x2409C
const void *off_2409C = (const void *)Get_ADC_Knock;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Get_Manifold_AbsPressure();
#pragma address off_2803C=0x2803C
const void *off_2803C = (const void *)Get_Manifold_AbsPressure;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void UpdateOutputSync();
#pragma address off_28034=0x28034
const void *off_28034 = (const void *)UpdateOutputSync;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Knock_Output_Calc_sub_AC96();
#pragma address off_24734=0x24734
const void *off_24734 = (const void *)Knock_Output_Calc_sub_AC96;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Update_Gen_G_output();

#pragma address off_2408C=0x2408C
#pragma address off_26DA8=0x26DA8

const void *off_2408C = (const void *)Update_Gen_G_output;
const void *off_26DA8 = (const void *)Update_Gen_G_output;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PDIOR_Stuff_sub_AD3C();
#pragma address off_27404=0x27404
const void *off_27404 = (const void *)PDIOR_Stuff_sub_AD3C;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_AD94();
#pragma address off_27524=0x27524
const void *off_27524 = (const void *)sub_AD94;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PWM_EGR_EVAP_O2H();
#pragma address off_28030=0x28030
const void *off_28030 = (const void *)PWM_EGR_EVAP_O2H;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_B0BC(u16 r1);
#pragma address off_1D404=0x1D404
const void *off_1D404 = (const void *)sub_B0BC;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Read_Ports_And_Registers_sub_B114();
#pragma address off_273FC=0x273FC
#pragma address off_E9D8=0xE9D8
const void *off_273FC = (const void *)Read_Ports_And_Registers_sub_B114;
const void *off_E9D8 = (const void *)Read_Ports_And_Registers_sub_B114;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void dmac2_dei2();
#pragma address v_dmac2_dei2=0x130
const void *v_dmac2_dei2 = dmac2_dei2;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void cmti0();
#pragma address v_cmti0=0x2F0
const void *v_cmti0 = cmti0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu41_imi4B();
#pragma address v_atu41_imi4B=0x204
const void *v_atu41_imi4B = atu41_imi4B;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma section _HARDWARE

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

extern "C" void SysInit_sub_9D2C()
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

#pragma noregalloc(sub_xxx)

static void sub_xxx()
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
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma regsave(sub_A078)

extern "C" void sub_A078()
{
	sub_xxx();

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

extern "C" void sub_A324()
{
	__push_regs();

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

	__pop_regs();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_A374()
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

	SET(r13, RT_5_ALWAYS_1);

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

extern "C" void PADR_Stuff_sub_A5F8()
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

extern "C" bool PEDR_LO_Check_sub_A790()
{
	return (reg_PEDRL & 2) == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool Check_Starter_signal()
{
	return (reg_PEDRL & 4) == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool CRANK_CheckCamshaft_sub_A7C0()
{
	return (reg_PADRL & 4) == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool Check_PEDRL_1()
{
	return (reg_PEDRL & 1) != 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void F500_Get_All_ADC()
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

extern "C" void Get_ADC_Bat_TPS_oxigen()
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

extern "C" void Get_ADC_Knock()
{
	u16 res;

	GetADC(6, &wMUT30_Knock_Voltage, &res);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Zero_MUT3B()
{
	wMUT3B_Masked_Map_Index = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Get_Manifold_AbsPressure()
{
	u16 res;

	GetADC(4, &wMUT1A_Manifold_AbsPressure_ADC8bit, &res);

	wMUT8C_Manifold_AbsPressure_ADC8bit = wMUT1A_Manifold_AbsPressure_ADC8bit;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void UpdateOutputAsync()
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

extern "C" void UpdateOutputSync()
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

extern "C" void Knock_Output_Calc_sub_AC96()
{
	if (wMUTD1_BitMap_FAA & FAA_7_HIGH_IGN)
	{
		__disable_irq();
	
//		WFLAG(reg_PHDRL, 4, KNOCK_FLAG2_FFFF887A & 2);

		reg_PHDRL = (reg_PHDRL & 4) | ((KNOCK_FLAG2_FFFF887A << 1) & 4);

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void sub_ACD4()
//{
//	__disable_irq();
//
////	word_FFFF8868 = (KNOCK_FLAG2_FFFF887A & 4) ? 1 : 0;
//
//	word_FFFF8868 = ((u32)KNOCK_FLAG2_FFFF887A >> 2) & 1;
//
//	__enable_irq();
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Update_Gen_G_output()
{
	__disable_irq();

	WFLAG(reg_PFDRL, 0x80, ZRO(KNOCK_FLAG2_FFFF887A, KNOCK_F2_01));

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PDIOR_Stuff_sub_AD3C()
{
	__disable_irq();

	//u32 r11 = reg_PDDRH & 1 ^ 1;

	//u32 r12 = reg_PDDRH & ~1;

	//reg_PDDRH = r11 & 1 | r12;
	
	reg_PDDRH ^= 1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_AD72()
{
	__disable_irq();

	CLR(reg_PBDRH, 0x80);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_AD94()
{
	__disable_irq();

	WPDR16(reg_PEDRH, RPDR16(reg_PEDRH) & 0xF3FF | word_8AD4[stepperPinOutIndex & 3]);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PWM_EGR_EVAP_O2H()
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

extern "C" void UpdateFanOutputDuty()
{
	SetDuty_6D(wMUT84_Thermo_Fan_Duty << 1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_B0BC(u16 r1)
{
	__push_regs();

	const u16 r2 = 25000;

	if (r1 != 0 && r1 < 5)	{ r1 = 5; };

	word_FFFF8D28 = r1;

	r1 = Mul_Fix8_Lim_FFFF(r1, r2);

	if (r1 > r2) { r1 = r2; };

	__disable_irq();

	ufix8_FFFF9ADE = r2;

	ufix8_FFFF9AE0 = r1;

	__enable_irq();

	__pop_regs();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Read_Ports_And_Registers_sub_B114()
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

static void GetADC(byte ch, u16 *res8, u16 *res10)
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

extern "C" void SysInit_ATU_0_DMA_2()
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

//extern "C" void sub_B4F2()
//{
//
//}

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


//extern "C" void sub_B6D0()
//{
//
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#pragma interrupt(dmac2_dei2)

extern "C" void dmac2_dei2()
{
	__disable_irq();

	CLR(reg_CHCR2, 3);

	__enable_irq();

	dmac2_dei2_B618();
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

	reg_PSCR1 = 3; // 4 MHz

	reg_PSCR4 = 3; // 4 MHz

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

#pragma interrupt(cmti0)
#pragma regsave(cmti0)

extern "C" void cmti0()
{
	__disable_irq();

	word_FFFF9AD6 = reg_TCNT2A;

	CLR(reg_CMCSR0, 0x80);

	DECLIM(downTimer_801);

	word_FFFF9AD2 += 312;

	if ((word_FFFF9AD2 - reg_TCNT2A) & 0x8000)
	{
		word_FFFF9AD2 += 312;

		__enable_irq();

		HUGE_Method_801_6_Hz();

		HUGE_Method_801_6_Hz();
	}
	else
	{
		__enable_irq();

		HUGE_Method_801_6_Hz();

		word_FFFF9AD4 = reg_TCNT2A - word_FFFF9AD6;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(atu41_imi4B)

extern "C" void atu41_imi4B()
{
	__disable_irq();

	CLR(reg_TSR3, 64);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

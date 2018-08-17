#pragma section _9D18

#include <smachine.h>

//#include "ext_ram_vars.h"

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#undef PEDR_LO_Check_sub_A790
#undef Knock_Output_Calc_sub_AC96

#define SysInit_HW_C0CC				((void(*)(void))0xC0CC)

#define	word_8AD4				((const u16*)0x8AD4)                                                     

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SysInit_ADC();
extern "C" void SysInit_ATU_0_DMA_2();
extern "C" void SysInit_HCAN();
extern "C" void SysInit_ATU_2A_2B_3_4_5_8_10();
extern "C" void SysInit_ATU_2E_2F_2G_out();
extern "C" void SysInit_ICR_C204();
extern "C" void SysInit_ATU_C476();
extern "C" void Init_ATU_sub_C5D2();
extern "C" void SysInit_sub_C87C();
extern "C" void SysInit_ATU_CA34();
extern "C" void SysInit_ATU_6_7();
extern "C" void SysInit_SCI_CF6C();
extern "C" void SysInit_Reset_Crank_Flags();
extern "C" void Init_ATU_0_2B();
extern "C" void SysInit_ATU_Misc_1_sub_DCDC();
extern "C" void SysInit_ATU_Misc_2_sub_E3A2();
extern "C" void Init_ATU_Counters_Control_sub_E4D0();
extern "C" void SysInit_INTC_sub_E598();

extern "C" void Init_HW_C164();                                      
extern "C" void Init_ATU_0_DMA_2();                                  
extern "C" void Init_HCAN();                                         
extern "C" void Init_ATU_2A_2B_3_4_5_8_10();                         
extern "C" void Init_ATU_2E_2F_2G_out();                             
extern "C" void sub_C234();                                          
extern "C" void sub_C4EE();                                          
extern "C" void sub_C646();                                          
extern "C" void sub_C8E0();                                          
extern "C" void sub_CAA8();                                          
extern "C" void Init_ATU_6_7();                                      
extern "C" void sub_D008();                                          
extern "C" void sub_D99A();                                          
extern "C" void sub_DE24();                                          
extern "C" void sub_E3EA();                                          
extern "C" void Init_ATU_Counters_Control_sub_E4D0();                
extern "C" void sub_E5FC();                                          
extern "C" void sub_A324();                                          
extern "C" void GetADC(byte r1, u16 *r2, u16 *r8);
extern "C" void SetDuty_6D(u16 v);












//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

extern "C" void sub_A078()
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

extern "C" void sub_A324()
{
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
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_A374()
{
	const u32 r9 = ~0x10;
	const u32 r8 = ~2;
//	const u32 r2 = 0x200;
	const u32 r1 = ~0x200;

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

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PEDR_LO_Check_sub_A790()
{

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
	u16 res, res1, res2;

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

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void UpdateOutputSync()
{

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

extern "C" void sub_ACD4()
{
	__disable_irq();

//	word_FFFF8868 = (KNOCK_FLAG2_FFFF887A & 4) ? 1 : 0;

	word_FFFF8868 = ((u32)KNOCK_FLAG2_FFFF887A >> 2) & 1;

	__enable_irq();
}

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

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void UpdateFanOutputDuty()
{
	SetDuty_6D(wMUT84_Thermo_Fan_Duty << 1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_B0BC()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Read_Ports_And_Registers_sub_B114()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

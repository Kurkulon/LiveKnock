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
#undef Timer_Counter_Related_sub_C928

//#define SysInit_HW_C0CC				((void(*)(void))0xC0CC)

//#define MUT_Request_2Byte				((u16(*)(u16))0x34B66)

#define	word_8AD4				((const u16*)0x8AD4)                                                     

#define	off_8AE4				((u16**)0x8AE4)  

//#define	byte_3FB40				((byte*)0x3FB40)                                                     
//#define	word_3FB3C				(*(u16*)0x3FB3C)  

//struct S9884 { u16 v1; byte v2; byte v3; byte v4; byte v5;  };

//#define	byte_9884				((S9884*)0x9884)                                                     

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
static void sub_D99A();                                          
extern "C" void sub_DE24();                                          
extern "C" void sub_E3EA();                                          
extern "C" void Init_ATU_Counters_Control_sub_E4D0();                
extern "C" void sub_E5FC();                                          
extern "C" void sub_A324();                                          
extern "C" void GetADC(byte r1, u16 *r2, u16 *r8);

//extern "C" void SetDuty_6D(u16 v);
static void SetDuty_6D(u16 v);

extern "C" bool sub_C2CC();
extern "C" bool sub_C304();
extern "C" bool sub_C33C();

//extern "C" void HUGE_Method_801_6_Hz();
#define  HUGE_Method_801_6_Hz		((void(*)(void))0x2686C)

extern "C" void SysInit_HW_C0CC();

//extern "C" void Ign_handler(u16 mask);
#define  Ign_handler		((void(*)(u16))0x2636C)
//#define  MUT_sub_34A2C		((void(*)(byte*,byte*,u16))0x34A2C)
//#define  sub_34C2C			((byte(*)(byte*,u16))0x34C2C)

static u16 GetADC0(byte r1);
static u16 GetADC1(byte r1);

extern "C" void COM_TX_Get();
extern "C" void COM_SCI0_RXI0();

extern "C" void sub_D56E();


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_A324();
#pragma address off_1D414=0x1D414
const void *off_1D414 = sub_A324;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PADR_Stuff_sub_A5F8();
#pragma address off_269A8=0x269A8
const void *off_269A8 = PADR_Stuff_sub_A5F8;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool PEDR_LO_Check_sub_A790();

#pragma address off_12268=0x12268
#pragma address off_2587C=0x2587C

const void *off_12268 = PEDR_LO_Check_sub_A790;
const void *off_2587C = PEDR_LO_Check_sub_A790;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool Check_Starter_signal();

#pragma address off_1FBBC=0x1FBBC
#pragma address off_235C0=0x235C0
#pragma address off_24EC8=0x24EC8

const void *off_1FBBC = Check_Starter_signal;
const void *off_235C0 = Check_Starter_signal;
const void *off_24EC8 = Check_Starter_signal;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool CRANK_CheckCamshaft_sub_A7C0();

#pragma address off_234D8=0x234D8
#pragma address off_24BEC=0x24BEC

const void *off_234D8 = CRANK_CheckCamshaft_sub_A7C0;
const void *off_24BEC = CRANK_CheckCamshaft_sub_A7C0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool Check_PEDRL_1();
#pragma address off_23504=0x23504
const void *off_23504 = Check_PEDRL_1;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Get_ADC_Bat_TPS_oxigen();
#pragma address off_270BC=0x270BC
const void *off_270BC = Get_ADC_Bat_TPS_oxigen;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Get_ADC_Knock();
#pragma address off_2409C=0x2409C
const void *off_2409C = Get_ADC_Knock;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Get_Manifold_AbsPressure();
#pragma address off_2803C=0x2803C
const void *off_2803C = Get_Manifold_AbsPressure;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void UpdateOutputSync();
#pragma address off_28034=0x28034
const void *off_28034 = UpdateOutputSync;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Knock_Output_Calc_sub_AC96();

#pragma address off_16E7C=0x16E7C
#pragma address off_24734=0x24734

const void *off_16E7C = Knock_Output_Calc_sub_AC96;
const void *off_24734 = Knock_Output_Calc_sub_AC96;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Update_Gen_G_output();

#pragma address off_2408C=0x2408C
#pragma address off_26DA8=0x26DA8

const void *off_2408C = Update_Gen_G_output;
const void *off_26DA8 = Update_Gen_G_output;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PDIOR_Stuff_sub_AD3C();
#pragma address off_27404=0x27404
const void *off_27404 = PDIOR_Stuff_sub_AD3C;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_AD94();
#pragma address off_27524=0x27524
const void *off_27524 = sub_AD94;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PWM_EGR_EVAP_O2H();
#pragma address off_28030=0x28030
const void *off_28030 = PWM_EGR_EVAP_O2H;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_B0BC(u16 r1);
#pragma address off_1D404=0x1D404
const void *off_1D404 = sub_B0BC;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Read_Ports_And_Registers_sub_B114();
#pragma address off_273FC=0x273FC
const void *off_273FC = Read_Ports_And_Registers_sub_B114;

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

extern "C" void SetIgnCoilChargeStartTime(u16 mask, u16 v);
#pragma address off_238B4=0x238B4
const void *off_238B4 = SetIgnCoilChargeStartTime;
#pragma address off_24E8C=0x24E8C
const void *off_24E8C = SetIgnCoilChargeStartTime;
#pragma address off_26630=0x26630
const void *off_26630 = SetIgnCoilChargeStartTime;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SetIgnSparkStartTime(u16 mask, u16 v);
#pragma address off_238CC=0x238CC
const void *off_238CC = SetIgnSparkStartTime;
#pragma address off_25268=0x25268
const void *off_25268 = SetIgnSparkStartTime;
#pragma address off_26624=0x26624
const void *off_26624 = SetIgnSparkStartTime;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Disable_Ign_Handler(u16 v);
#pragma address off_238B0=0x238B0
const void *off_238B0 = Disable_Ign_Handler;
#pragma address off_26620=0x26620
const void *off_26620 = Disable_Ign_Handler;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Start_Coil_Charge(u16 mask);
#pragma address off_24744=0x24744
const void *off_24744 = Start_Coil_Charge;
#pragma address off_24D88=0x24D88
const void *off_24D88 = Start_Coil_Charge;
#pragma address off_26A50=0x26A50
const void *off_26A50 = Start_Coil_Charge;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Disable_Coil_Charge(u16 mask);
#pragma address off_25254=0x25254
const void *off_25254 = Disable_Coil_Charge;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu22_imi2E();
#pragma address v_atu22_imi2E=0x1C0
const void *v_atu22_imi2E = atu22_imi2E;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu22_imi2F();
#pragma address v_atu22_imi2F=0x1C4
const void *v_atu22_imi2F = atu22_imi2F;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" u16 Get_Coil_charge_status();
#pragma address off_236FC=0x236FC
const void *off_236FC = Get_Coil_charge_status;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool Reset_IRQ0F();
#pragma address off_26350=0x26350
const void *off_26350 = Reset_IRQ0F;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PHDR_Stuff_sub_C388();
#pragma address off_269BC=0x269BC
const void *off_269BC = PHDR_Stuff_sub_C388;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" u16 atu22_Get_ECNT9A();
#pragma address off_23F88=0x23F88
const void *off_23F88 = atu22_Get_ECNT9A;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void InjOpenStart(u16 v, u16 mask);
#pragma address off_23F6C=0x23F6C
const void *off_23F6C = InjOpenStart;
#pragma address off_262B0=0x262B0
const void *off_262B0 = InjOpenStart;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu21_imi2A();
#pragma address v_atu21_imi2A=0x1B0
const void *v_atu21_imi2A = atu21_imi2A;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" u16 atu22_Get_DSTR_0x3C00();
#pragma address off_26354=0x26354
const void *off_26354 = atu22_Get_DSTR_0x3C00;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Timer_Counter_Related_sub_C928();
#pragma address off_170D4=0x170D4
const void *off_170D4 = Timer_Counter_Related_sub_C928;
#pragma address off_241F4=0x241F4
const void *off_241F4 = Timer_Counter_Related_sub_C928;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void CRANK5_sub_C990(u16 v);
#pragma address off_24EAC=0x24EAC
const void *off_24EAC = CRANK5_sub_C990;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void COM_sub_D1CC();
#pragma address off_209EC=0x209EC
#pragma address off_214D0=0x214D0
#pragma address off_230E0=0x230E0
#pragma address off_339A4=0x339A4
const void *off_209EC = COM_sub_D1CC;
const void *off_214D0 = COM_sub_D1CC;
const void *off_230E0 = COM_sub_D1CC;
const void *off_339A4 = COM_sub_D1CC;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void COM_Update_TX();
#pragma address off_20898=0x20898
const void *off_20898 = COM_Update_TX;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sci0_eri0();
#pragma address v_sci0_eri0=0x320
const void *v_sci0_eri0 = sci0_eri0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_D3E4();
#pragma address off_27778=0x27778
const void *off_27778 = sub_D3E4;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sci2_txi2();
#pragma address v_sci2_txi2=0x348
const void *v_sci2_txi2 = sci2_txi2;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_D4E4();
#pragma address off_26D98=0x26D98
const void *off_26D98 = sub_D4E4;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SCI1_TransStart();
#pragma address off_223EC=0x223EC
#pragma address off_22E70=0x22E70
const void *off_223EC = SCI1_TransStart;
const void *off_22E70 = SCI1_TransStart;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SCI1_TransNext();
#pragma address off_223F4=0x223F4
#pragma address off_22DF0=0x22DF0
const void *off_223F4 = SCI1_TransNext;
const void *off_22DF0 = SCI1_TransNext;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sci1_eri1();
#pragma address v_sci1_eri1=0x330
#pragma address v_sci1_rxi1=0x334
const void *v_sci1_eri1 = sci1_eri1;
const void *v_sci1_rxi1 = sci1_eri1;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void COM_SCI0_Disable_Transmit_sub_D8C4();
#pragma address off_218A8=0x218A8
const void *off_218A8 = COM_SCI0_Disable_Transmit_sub_D8C4;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma section _9D18


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

	WFLAG(reg_PGDRL, 1, wMUT9A_Ligths_Bit_Array & 8);

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

extern "C" void UpdateFanOutputDuty()
{
	SetDuty_6D(wMUT84_Thermo_Fan_Duty << 1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_B0BC(u16 r1)
{
	const u16 r2 = 25000;

	if (r1 < 5)	{ r1 = 5; };

	word_FFFF8D28 = r1;

	r1 = Mul_Fix8_Lim_FFFF(r1, r2);

	if (r1 > r2) { r1 = r2; };

	__disable_irq();

	ufix8_FFFF9ADE = r2;

	ufix8_FFFF9AE0 = r1;

	__enable_irq();
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


#pragma noregalloc(GetADC)

extern "C" void GetADC(byte r1, u16 *r2, u16 *r8)
{
	__disable_irq();

	WFLAG(reg_PHDRL, 2, r1 & 0x20);

	WFLAG(reg_PHDRL, 1, r1 & 0x40);
	
	byte r0 = 1;

	while(--r0) {};

	r1 &= 0x1F;

	u32 v = (r1 < 12) ? GetADC0(r1) : GetADC1(r1 - 12);

	*r8 = v;

	*r2 = (u32)v >> 2;

	__enable_irq();
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

	word_FFFF9AD2 = reg_TCNT2A + 312;

	CLR(reg_TIER3, 0x3A0);

	reg_TIOR4A = 0x11;
	reg_TIOR4B = 0x11;

	CLR(reg_TIER3, 0x40);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(cmti0)

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

extern "C" void WaitDownTimer801()
{
	for(;;)
	{
		if (downTimer_801 == 0 || downTimer_801 > 8) break;
	};

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

extern "C" void SetIgnCoilChargeStartTime(u16 mask, u16 v)
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

extern "C" void SetIgnSparkStartTime(u16 mask, u16 v)
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

extern "C" void Disable_Ign_Handler(u16 v)
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

extern "C" void Start_Coil_Charge(u16 mask)
{
	__disable_irq();

	if (mask & 1)
	{
		reg_GR2E = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x10);

		reg_TIOR2C = reg_TIOR2C & 0xF8 | 1; // 0 output on GR compare-match

		while(ZRO(reg_TSR2A, 0x10)) ;
	};

	if (mask & 2)
	{
		reg_GR2F = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x20);

		reg_TIOR2C = reg_TIOR2C & 0x8F | 0x10; // 0 output on GR compare-match

		while(ZRO(reg_TSR2A, 0x20)) ;
	};

	if (mask & 4)
	{
		reg_GR2G = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x40);

		reg_TIOR2D = reg_TIOR2D & 0xF8 | 1; // 0 output on GR compare-match

		while(ZRO(reg_TSR2A, 0x40)) ;
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Disable_Coil_Charge(u16 mask)
{
	__disable_irq();

	if (mask & 1)
	{
		reg_GR2E = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x10);

		reg_TIOR2C = reg_TIOR2C & 0xF8 | 2;

		while(ZRO(reg_TSR2A, 0x10)) ;
	};

	if (mask & 2)
	{
		reg_GR2F = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x20);

		reg_TIOR2C = reg_TIOR2C & 0x8F | 0x20;

		while(ZRO(reg_TSR2A, 0x20)) ;
	};

	if (mask & 4)
	{
		reg_GR2G = reg_TCNT2A + 2;

		CLR(reg_TSR2A, 0x40);

		reg_TIOR2D = reg_TIOR2D & 0xF8 | 2;

		while(ZRO(reg_TSR2A, 0x40)) ;
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(atu22_imi2E)

extern "C" void atu22_imi2E()
{
	__disable_irq();

	CLR(reg_TSR2A, 0x10);

	__enable_irq();

	Ign_handler(1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma interrupt(atu22_imi2F)

extern "C" void atu22_imi2F()
{
	__disable_irq();

	CLR(reg_TSR2A, 0x20);

	__enable_irq();

	Ign_handler(2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void atu22_IMF2G_event()
{
	__disable_irq();

	Disable_Ign_Handler(4);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" u16 Get_Coil_charge_status()
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

extern "C" bool Reset_IRQ0F()
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

static void Nop4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Nop5()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void PHDR_Stuff_sub_C388()
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

	reg_TCNT5 = 0;

	reg_GR5A = 0x1F;

	reg_TIOR5B = 0x11;

	reg_TIOR5A = (byte_102A/*0*/ != 0) ? 0x1A : 0x1B;

	CLR(reg_TIER9, 1);

	reg_TCR9A = 2;

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

extern "C" u16 atu22_Get_ECNT9A()
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

extern "C" void Init_ATU_sub_C5D2()
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

extern "C" void InjOpenStart(u16 v, u16 mask)
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

#pragma interrupt(atu21_imi2A)

extern "C" void atu21_imi2A()
{
	__disable_irq();

	CLR(reg_TSR2A, 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" u16 atu22_Get_DSTR_0x3C00()
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

extern "C" void Timer_Counter_Related_sub_C928()
{
	__disable_irq();

	reg_GR2H = reg_TCNT2A + 2;

	CLR(reg_TSR2A, 0x80);

	reg_TIOR2D = reg_TIOR2D & 0x8F | 0x20;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void CRANK5_sub_C990(u16 v)
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

//extern "C" void sub_C9E4(u16 v)
//{
//	__disable_irq();
//
//	u32 r13 = v;
//
//	v -= reg_TCNT2A + 2;
//
//	if (v & 0x8000)
//	{
//		r13 = reg_TCNT2A + 2;
//	};
//
//	reg_GR2H = r13;
//
//	CLR(reg_TSR2A, 0x80);
//
//	SET(word_FFFF9AFC, 1);
//
//	__enable_irq();
//}

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

//extern "C" u16 sub_CB06()
//{
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void sub_CB9C()
//{
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void sub_CBE8()
//{
//
//}

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

//extern "C" void sub_CE28()
//{
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void sub_CE56()
//{
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void sub_CE84()
//{
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SetDuty_6D(u16 v)
{
	__disable_irq();

	reg_BFR6D = v >> 1;

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void sub_CEE2()
//{
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void sub_CF10()
//{
//
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" void sub_CF3E()
//{
//
//}

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

	reg_SCI2->SMR_BRR = 0x13F;

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

extern "C" void COM_sub_D1CC()
{
	mut_sended_len = 0;

	COM_TX_Get();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void COM_Update_TX()
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

#pragma interrupt(sci0_eri0)

extern "C" void sci0_eri0()
{
	u32 r14_8;

	if ((__DMAOPFLAG & 1) || (reg_CHCR1 & 1))
	{
		__disable_irq();

		r14_8 = reg_SCI0->RDR;

		CLR(reg_SCI0->SSR, 0x78);

		CLR(reg_SCI0->SCR, 0x40);

		word_FFFF9AD0 = 1;

		__enable_irq();
	}
	else
	{
		COM_SCI0_RXI0();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void COM_SCI0_RXI0()
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

extern "C" void sub_D3E4()
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

#pragma interrupt(sci2_txi2)

extern "C" void sci2_txi2()
{
	__disable_irq();

	if (word_FFFF8DB6 < 7)
	{
		u32 r12 = *(off_8AE4[word_FFFF8DB6]);

		reg_SCI2->TDR = r12;

		CLR(reg_SCI2->SCR, 0x80);

		word_FFFF8D94 += r12;

		word_FFFF8DB6 += 1;
	}
	else
	{
		CLR(reg_SCI2->SCR, 0x80);
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void sub_D4E4()
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

extern "C" void SCI1_TransStart()
{
	sci1_transCount = 0;

	sub_D56E();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SCI1_TransNext()
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

#pragma interrupt(sci1_eri1)

extern "C" void sci1_eri1()
{
	__disable_irq();

	byte r13 = reg_SCI1->SSR;

	byte r1 = reg_SCI1->RDR;

	CLR(reg_SCI1->SSR, 0x78);

	if(ZRO(word_FFFF8E40, 1))
	{
		CLR(word_FFFF8E40, 0xA0);

		word_FFFF8EA2 = 0;
		word_FFFF8EAE = 0;
	}
	else
	{
		if (r13 & 0x38)
		{
			SET(word_FFFF8E40, 0x20);
		};

		if (word_FFFF8E40 & 0x80)
		{
			CLR(word_FFFF8E40, 0x80);

			word_FFFF8EA2 = 0;
			word_FFFF8EAE = 0;
		}
		else
		{
			u32 len = word_FFFF8EA2;

			if (len < 7)
			{
				word_FFFF8E84[len] = r1;

				SET(word_FFFF8E40, 0x40);

				word_FFFF8EA2 += 1;
				word_FFFF8EAE = 0;
			};
		};
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void SCI0_Transmit_DMA0_Enable(u16 r1, u16 r2)
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

extern "C" void SCI0_Recieve_DMA0_Enable(u16 r1)
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

extern "C" bool SCI0_Check_Transfer_End()
{
	return reg_DMATCR0 == 0 && reg_DMATCR1 == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool SCI0_Check_Errors()
{
	return (reg_SCI0->SSR & 0x38) || word_FFFF9AD0 != 0; 
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" bool SCI0_Check_PA7()
{
	return ZRO(reg_PADRH, 0x80);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void COM_SCI0_Disable_Transmit_sub_D8C4()
{
	__disable_irq();

	CLR(reg_SCI0->SCR , 0x80);

	CLR(reg_CHCR0, 1);

	CLR(reg_CHCR1, 1);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Nop6()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_Reset_Crank_Flags()
{
	crank_Flags = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void Init_ATU_0_2B()
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

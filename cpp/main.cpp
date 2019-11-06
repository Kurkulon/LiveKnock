#ifdef DEF_F500
#pragma section _main
#endif

#include <umachine.h>

//#include "ext_ram_vars.h" 

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"
#include "EnVars.h"
#include "hwreg.h"
#include "F500.h"
#include "ML02.h"
#include "FU03.h"
#include "Ignition.h"
#include "idle.h"
#include "huge.h"
#include "hardware.h"
#include "BC06.h"
#include "EF07.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define      adc_Hooked_value ((u16*)0xFFFF8000)                                                        



#define _sub_206A4					((void(*)(void))0x206A4)
#define _COM_root_sub_21564			((void(*)(void))0x21564)
#define _OBD_root_sub_2B8AC			((void(*)(void))0x2B8AC)
#define _IMMO_root_sub_226E4		((void(*)(void))0x226E4)
#define _Init_NVRAM_2B364			((void(*)(void))0x2B364)
#define _SysInit_NVRAM_220D8		((void(*)(void))0x220D8)
#define _sub_23180					((void(*)(void))0x23180)
#define _Init_sub_2B474				((void(*)(void))0x2B474)
#define _SysInit_sub_230FA			((void(*)(void))0x230FA)
#define _SysInit_sub_22100			((void(*)(void))0x22100)
#define _SysInit_sub_8000			((void(*)(void))0x8000)


#pragma regsave(sub_206A4)			
#pragma regsave(COM_root_sub_21564)
#pragma regsave(OBD_root_sub_2B8AC)	
#pragma regsave(IMMO_root_sub_226E4)
#pragma regsave(Init_NVRAM_2B364)	
#pragma regsave(SysInit_NVRAM_220D8)
#pragma regsave(sub_23180)			
#pragma regsave(Init_sub_2B474)
#pragma regsave(SysInit_sub_230FA)
#pragma regsave(SysInit_sub_22100)	
#pragma regsave(SysInit_sub_8000)	

static void sub_206A4()				{	_sub_206A4();			}						
static void COM_root_sub_21564()	{	_COM_root_sub_21564(); 	}		
static void OBD_root_sub_2B8AC()	{	_OBD_root_sub_2B8AC(); 	}		
static void IMMO_root_sub_226E4()	{	_IMMO_root_sub_226E4();	}	
static void Init_NVRAM_2B364()		{	_Init_NVRAM_2B364();	}				
static void SysInit_NVRAM_220D8()	{	_SysInit_NVRAM_220D8(); }	
static void sub_23180()				{	_sub_23180();			}						
static void Init_sub_2B474()		{	_Init_sub_2B474();		}				
static void SysInit_sub_230FA()		{	_SysInit_sub_230FA(); 	}		
static void SysInit_sub_22100()		{	_SysInit_sub_22100(); 	}		
static void SysInit_sub_8000()		{	_SysInit_sub_8000();	}			

//#define AA05_root_sub_19096			((void(*)(void))0x19096)
//#define EF07_root_sub_1F428			((void(*)(void))0x1F428)
//#define SysInit_NVRAM_266DC			((void(*)(void))0x266DC)
//#define SysInit_NVRAM_18F80			((void(*)(void))0x18F80)
//#define SysInit_NVRAM_1F3E0			((void(*)(void))0x1F3E0)
//#define SysInit_sub_266FC								((void(*)(void))0x266FC)
//#define SysInit_sub_16D74								((void(*)(void))0x16D74)
//#define SysInit_sub_19014								((void(*)(void))0x19014)
//#define SysInit_sub_1F408								((void(*)(void))0x1F408)


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_EBB0();
static void System_Setup();
static void SysInit_Saved_Params();
static bool SysInit_Check_Saved_Params();
static void SysInit_sub_EFB2();
static void SysInit_sub_F148();
static void sub_F164();

extern "C" void LiveMap();
extern "C" void LiveKnock();

static void WaitTimer();

static void Simulation();



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(Main_Engine_Control_Loop)

extern "C" void Main_Engine_Control_Loop()
{
	System_Setup();

    Set_Intterupt_Mask(0);

	while(1)
	{
#ifdef DEF_SIMULATION

		if (frameCount == 0x400)
		{
			while(1);
		};

#endif
		sub_206A4();

		deltaTimer_FFFF886A = reg_TCNT2A - prevTimer_FFFF886C;

		WaitDownTimer801();

		prevTimer_FFFF886C = reg_TCNT2A;

		//WaitTimer();

		sub_F164();

		COM_root_sub_21564();

		F500_root_sub();                                     

		ML02_root_sub_1123E();                               

		FU03_root_sub();                                     

		IG04_root_Update_Ignition();                         

		sub_EBB0();                                                

		AA05_root_sub_19096();                               

		BC06_root_sub_1BF7A();                               

		EF07_root_sub_1F428();                               

		OBD_root_sub_2B8AC();                                

		if (wMUTD1_BitMap_FAA & FAA_3_IMMO)
		{
			IMMO_root_sub_226E4();
		};

		LiveMap();

		LiveKnock();

		UpdateOutputAsync();

		UpdateFanOutputDuty();

#ifdef DEF_SIMULATION

		Simulation();

#endif
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef DEF_SIMULATION

static void Simulation()
{
	// atu02_ici0A

	reg_TCNT2A += 3750000/750;
	reg_OSBR2 = reg_TCNT2A;

	reg_ICR0A += 3750000*16/750;

	reg_PADRL ^= 1;

	trapa(84);

	// atu22_CMF2G_event

	SET(reg_TSR2B, 0x40);
	trapa(114);

	//HUGE_Method_801_6_Hz

	reg_PADRL ^= 0x80; reg_TSR3 |= 8;	trapa(188); 
		trapa(188); 
	reg_PADRL ^= 0x80; reg_TSR3 |= 8;	trapa(188); 
		trapa(188); 
	reg_PADRL ^= 0x80; reg_TSR3 |= 8;	trapa(188); 
		trapa(188); 
	reg_PADRL ^= 0x80; reg_TSR3 |= 8;	trapa(188); 
		trapa(188); 

	adc_Hooked_value[0] = 0;
	adc_Hooked_value[1] = 13.8/0.0733*4;			// wMUT14_Battery_Level_ADC8bit
	adc_Hooked_value[2] = (139.74 - 80)/1.468*4;	// wMUT07_CoolTemp_ADC8bit
	adc_Hooked_value[3] = (139.74 - 20)/1.468*4;	// wMUT3A_AirTemp_ADC8bit
	adc_Hooked_value[4] = 70*4;					// wMUT1A_Manifold_AbsPressure_ADC8bit
	adc_Hooked_value[5] = 25*4;					// wMUT17_TPS_ADC8bit
	adc_Hooked_value[6] = 0;					// wMUT30_Knock_Voltage
	adc_Hooked_value[7] = 0;					// null_ADC_7_8bit
	adc_Hooked_value[8] = 0;					// ADC_08_8bit
	adc_Hooked_value[9] = 0;					// oxigen_ADC8bit
	adc_Hooked_value[10] = 0;					// wMUT3C_Rear_O2_ADC8bit
	adc_Hooked_value[11] = 0;					// wMUT38_Manifold_DiffPressure_ADC8bit
	adc_Hooked_value[12] = 0;					// wMUT39_Fuel_Tank_Pressure_ADC8bit
	adc_Hooked_value[13] = 0;					// wMUT88_Fuel_Level_ADC8bit
	adc_Hooked_value[14] = 0;					// wMUT87_Fuel_Temp_ADC8bit
	adc_Hooked_value[15] = 0;					// wMUT83_ADC_15_8bit

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef DEF_HARDWARE

extern "C" u16 GetADC_hook(byte ch, u16 *res8, u16 *res10)
{
	u16 *v = adc_Hooked_value;

	return *res8 = (*res10 = v[ch]) >> 2;
}

#endif

#endif // #ifdef DEF_SIMULATION

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregsave(WaitTimer)

static void WaitTimer()
{
	deltaTimer_FFFF886A = reg_TCNT2A - prevTimer_FFFF886C;

	WaitDownTimer801();

	//for(;;)
	//{
	//	if (downTimer_801 == 0 || downTimer_801 > 8) break;
	//};

	//__disable_irq();

	//downTimer_801 = 8;

	//__enable_irq();

	prevTimer_FFFF886C = reg_TCNT2A;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_EBB0()
{
	word_FFFF9478 = 0;

	CLR(word_FFFF80E6, 0x8000);
	CLR(word_FFFF9624, 0xE0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void System_Setup()               
{
#ifdef DEF_SIMULATION
	memsetz((void*)0xFFFF8000, (void*)0xFFFFA810);
	memsetz((void*)0xFFFFE400, (void*)0xFFFFF860);
#endif

	SysInit_sub_F148();

	F500_Init_BitMap_Flags_New();

	CLR(word_FFFF8DFE, 0x4000);

	SysInit_Saved_Params();                                    

	SysInit_sub_EFB2();                                        

	if (timer_FFFF8582 != 0)
	{
		PDIOR_Stuff_sub_AD3C();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregalloc(SysInit_Saved_Params)

static void SysInit_Saved_Params()       
{
	if (SysInit_Check_Saved_Params())
	{
		NVRAM_CheckWord_1 = 0xA5A5;

		memsetz(&byte_FFFF82A0, &NVRAM_CheckWord_3);

		SysInit_NVRAM_F234();

		SysInit_NVRAM_266DC();

		SysInit_NVRAM_111C8();

		SysInit_NVRAM_Trims();

		SysInit_NVRAM_OctaneNum();

		SysInit_NVRAM_18F80();

		SysInit_NVRAM_1F3E0();

		Init_NVRAM_2B364();

		SysInit_NVRAM_220D8();

		NVRAM_CheckWord_4 = 0xA5A5;

		NVRAM_CheckWord_3 = 0x5A5A;

		NVRAM_CheckWord_2 = 0xA5A5;

		NVRAM_CheckWord_1 = 0x5A5A;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool SysInit_Check_Saved_Params() 
{
	u32 r6 = ufix8_COOLANT_TEMP_CONST_1934;
	u32 r7 = ufix8_COOLANT_TEMP_CONST_1932;

	u32 r13 = SOME_FUEL_TRIM_CONST_15F4;
	u32 r3 = SOME_FUEL_TRIM_CONST_15F6;


	if (wMUT0C_Fuel_Trim_Low < r13 || wMUT0C_Fuel_Trim_Low > r3)
	{
		return true;
	}
	else if (wMUT0D_Fuel_Trim_Middle < r13 || wMUT0D_Fuel_Trim_Middle > r3)
	{
		return true;
	}
	else if (wMUT0E_Fuel_Trim_High < r13 || wMUT0E_Fuel_Trim_High > r3)
	{
		return true;
	}
	else if (trim_Idle_Control_main < r6 || trim_Idle_Control_main > r7)
	{
		return true;
	}
	else if (trim_Idle_Control_AC_1 < r6 || trim_Idle_Control_AC_1 > r7)
	{
		return true;
	}
	else if (trim_Idle_Control_AC_2 < r6 || trim_Idle_Control_AC_2 > r7)
	{
		return true;
	}
	else if (SwapBytes16(wMUT16_cur_Idle_Steps) != wMUT16_cur_Idle_Steps)
	{
		return true;
	}
	else if (SwapBytes16(wMUT40_Stored_Faults_Lo) != wMUT40_Stored_Faults_Lo)
	{
		return true;
	}
	else if (SwapBytes16(wMUT41_Stored_Faults_Hi) != wMUT41_Stored_Faults_Hi)
	{
		return true;
	}
	else if (SwapBytes16(wMUT42_Stored_Faults_Lo_1) != wMUT42_Stored_Faults_Lo_1)
	{
		return true;
	}
	else if (SwapBytes16(wMUT43_Stored_Faults_Hi_1) != wMUT43_Stored_Faults_Hi_1)
	{
		return true;
	}
	else if (SwapBytes16(wMUT44_Stored_Faults_Lo_2) != wMUT44_Stored_Faults_Lo_2)
	{
		return true;
	}
	else if (SwapBytes16(wMUT45_Stored_Faults_Lo_3) != wMUT45_Stored_Faults_Lo_3)
	{
		return true;
	}
	else if (SwapBytes16(wMUT46_Stored_Faults_Hi_3) != wMUT46_Stored_Faults_Hi_3)
	{
		return true;
	}
	else if (SwapBytes16(wMUT47_Active_Fault_Lo) != wMUT47_Active_Fault_Lo)
	{
		return true;
	}
	else if (SwapBytes16(wMUT48_Active_Faults_Hi) != wMUT48_Active_Faults_Hi)
	{
		return true;
	}
	else if (SwapBytes16(wMUT49_faults) != wMUT49_faults)
	{
		return true;
	}
	else if (word_FFFF8DFE & 0x4000)
	{
		return true;
	}
	else if (NVRAM_CheckWord_4 != 0xA5A5 || NVRAM_CheckWord_3 != 0x5A5A)
	{
		return true;
	}
	else if (NVRAM_CheckWord_2 != 0xA5A5 || NVRAM_CheckWord_1 != 0x5A5A)
	{
		return true;
	}
	else
	{
		return false;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma noregalloc(SysInit_sub_EFB2)

static void SysInit_sub_EFB2()           
{
	memsetz(&__word_FFFF851E, dword_FFFF9A60);

	HIGHBAUDFLAG_FFFF93D8 = _highbaudflag_F30;

	F500_Init_BitMap_Flags_New();

	F500_Get_All_ADC();

	Get_ADC_Bat_TPS_oxigen();

	Get_ADC_Knock();

	Get_Manifold_AbsPressure();

	PHDR_Stuff_sub_C388();

	PADR_Stuff_sub_A5F8();

	portA_state_pr1 = portA_state;

	portA_state_pr2 = portA_state;

	sub_A374();

	SysInit_Copy_ADC_To_Local_Vars_More_sub_F26C();

	SysInit_sub_266FC();

	SysInit_Set_0x10_MUT1E_MAF_RESET_FLAG();

	SysInit_sub_13B04();

	SysInit_sub_16D74();

	SysInit_sub_19014();

	SysInit_sub_1BEFE();

	SysInit_sub_1F408();

	Init_sub_2B474();

	SysInit_sub_230FA();

	SysInit_sub_22100();

	SysInit_sub_8000();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_sub_F148()           
{
	SysInit_sub_9D2C();

	word_FFFF8550 = word_8B00;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_AD72()
{
	__disable_irq();

	CLR(reg_PBDRH, 0x80);

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void sub_F164()                   
{
	sub_AD72();

	word_FFFF8550 = word_8B00;

	sub_A078();

	if (timer_FFFF8592 == 0 || timer_down_TXFLAG3_FFFF8574 == 0)
	{
		__disable_irq();
		Init_ATU_sub_C5D2();
		SysInit_ATU_0_DMA_2();
		Init_ATU_0_2B();
		sub_23180();
		__enable_irq();
	};

	__disable_irq();

	if (timer_FFFF8594 == 0 && (timer_FFFF8592 == 0 || ZRO(RT_FLAG1_FFFF8888, STARTER)))
	{
		Disable_Coil_Charge(0xFF);
		local_2636C = 0;
	};

	__enable_irq();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

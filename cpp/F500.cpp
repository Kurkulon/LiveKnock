#pragma section _F500

#include <umachine.h>

#include "misc.h"
#include "constbyte.h"
#include "constword.h"
#include "ram.h"

#undef F500_Init_Load_ECU_Info_And_BitMap_Flags

#define sub_A374	((void(*)(void))0xA374)


void F500_root_sub();
void F500_Init_Load_ECU_Info_And_BitMap_Flags();
void F500_sub_F6E6();
void F500_sub_F7E4();
void F500_sub_F834();
void F500_sub_FBB4();
void F500_sub_FD34();
void F500_sub_FDB6();
void F500_sub_FDF4();
void F500_Coolant_Temp_Threshold_Tests();
void F500_Coolant_Calc1_sub_FF2C();
void F500_Coolant_Calibration_Calc();
void F500_Update_IAT_Sensor();
void F500_Update_Air_Temp_Scaled();
void F500_sub_10188();
void F500_sub_10220();
void F500_O22_Manipulations_sub_1023C();
void F500_TPS_Load_RPM_Calcs();
void F500_TPS_sub_103DA();
void F500_sub_1044C();
bool F500_CheckIdleRPM();
void F500_MAP_Coolant_Calcs();
void F500_sub_10820();
void F500_sub_10878();
void F500_sub_108AA();
void F500_sub_108FE();
void F500_sub_10984();
void F500_sub_10A80();
void F500_sub_10AA6();
void F500_Check_MAP_Fault();
void F500_Load_sub_10B72();
void F500_sub_10C6E();
void F500_sub_10E10();
void F500_MAP_Hz_Calc_sub_10E54();
void F500_sub_10F08();
void F500_Countdown_Timers_sub_10F5C();
void F500_Battery_Calcs_sub_1101A();



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_root_sub()
{
	F500_Init_Load_ECU_Info_And_BitMap_Flags();

	F500_sub_F6E6();

	F500_sub_F7E4();

	F500_sub_FDF4();

	F500_MAP_Coolant_Calcs();

	F500_sub_10878();

	F500_sub_10AA6();

	F500_sub_10C6E();

	F500_MAP_Hz_Calc_sub_10E54();

	F500_sub_10F08();

	F500_Countdown_Timers_sub_10F5C();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Init_Load_ECU_Info_And_BitMap_Flags()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_F6E6()
{
	if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x40)
	{
		timer_up_FFFF852A = 0;
	};

	if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{
		cranking_end_timer_up = 0;
	};

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		timer_up_FFFF852E = 0;

		coolantTempScld_COPY_1 = wMUT10_Coolant_Temperature_Scaled;

		INTAKE_AIR_TEMPERATURE_COPY_FFFF88BA = wMUT11_Intake_Air_Temperature_Scaled;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_F7E4()
{
	word_FFFF8898 = word_FFFF8896;
	word_FFFF8894 = MUT_03_FLAGS;
	word_FFFF888C = MUT_00_01_FLAGS;

	sub_A374();

	RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_COPY_FFFF888A = RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888;

	word_FFFF8892 = word_FFFF8890;
	LAUNCH_TEST_FLAG_1_COPY_FFFF889C = LAUNCH_TEST_FLAG_1_FFFF889A;

	F500_sub_F834();

	F500_sub_FD34();

	F500_sub_FDB6();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_F834()
{
	const u32 r9 = 0x100;

	u32 r1 = MUT_00_01_FLAGS;
	u32 r2 = MUT_03_FLAGS;

	u32 r8 = word_FFFF8896;

	if (byte_102D == 0)
	{
		CLR(r1, 0x4400);
	};

	if ((byte_1046 & 2) == 0)
	{
		SET(r1, 0x1000);
	};

	if (byte_102A == 0)
	{
		CLR(r1, 0x200);
	};

	if (byte_1041 == 0)
	{
		CLR(r2, 0x10);
	};

	if ((wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL)) || timer_up_FFFF852A < word_18B6)
	{
		SET(r1, 0x20);
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_18BA)
	{
		CLR(r1, 8);
	};

	if (word_FFFF8D60 & r9)
	{
		if (wMUT12_Coolant_Temperature_Min_81 <= word_1A86)
		{
			CLR(word_FFFF8D60, 0x100);
		};
	}
	else
	{
		if (wMUT12_Coolant_Temperature_Min_81 > word_1A88)
		{
			SET(word_FFFF8D60, 0x100);
		};
	};

	if ((wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL)) || cranking_end_timer_up < word_18B8 || (word_FFFF8D60 & 0x100))
	{
		CLR(r1, 0x10);
	};

	CLR(word_FFFF8CE4, 0x8000);

	if (byte_102E == 2)
	{
		if ((r1 & 0x10) && (cranking_end_timer_up < (word_19F6 * 20)))
		{
			SET(r2, r9);
		}
		else
		{
			CLR(r2, 0x100);

			if ((r1 & 0x10) && (r1 & 1))
			{
				SET(r2, r9);
			};
		};
	};

	if (byte_102E == 2)
	{
		if (wMUT15_Barometric_Pressure > word_19F0)
		{
			timer_FFFF8784 = word_19FC;
		};

		u32 r13 = (byte)(fix8_FFFF8DCE>>8);

		if (wMUT19_Startup_Check_Bits & 0x2000)
		{
			if (r13 <= word_2110)
			{
				CLR(wMUT19_Startup_Check_Bits, 0x2000);
			};
		}
		else
		{
			if (r13 > word_210E)
			{
				SET(wMUT19_Startup_Check_Bits, 0x2000);
			};
		};

		if ((r1 & 0x11) == 0x11)
		{
			if (wMUT11_Intake_Air_Temperature_Scaled > word_19F8 || (IATONOFF_105E != 0 && (wMUT19_Startup_Check_Bits & 0x2000)) 
				|| timer_FFFF8784 == 0 || wMUT10_Coolant_Temperature_Scaled < word_19FA || cranking_end_timer_up < (word_19F4*20))
			{
				CLR(r1, 1);
			};
		};
	};

	if ((bMUTD2_FBA_MAF_MAP_FLAG & 0x10) == 0 && ((r1 & 0x10) == 0 || byte_102E == 0))
	{
		CLR(r1, 1);
		CLR(r2, 0x100);
		CLR(r8, 0x3000);
	};

	if (byte_102B != 0)
	{
		CLR(r1, 0x1000);
	};

	if (MUT_CMD_0 & 1) // MUT_D9 Fix timing at 5 degrees
	{
		SET(r1, 0x1000);
		CLR(r1, 0x800);
	};

	if (MUT_CMD_1 & 0x40) // MUT_C3 SAS (Speed Adjusting Screw)
	{
		SET(r1, 0x1800);
	};

	CLR(r1, 4);

	if (timer_down_FFFF89CE != 0)
	{
		SET(r1, 4);
	};

	if (bMUTD2_FBA_MAF_MAP_FLAG & 8) // AYC/ACD
	{
//		if ((wMUT40_Stored_Faults_Lo & 8) || (wMUT44_Stored_Faults_Lo_2 & 0xEF))

		if (NVRAM_FFFF802C & 1)
		{
			SET(r1, 0x80);
		}
		else
		{
			CLR(r1, 0x80);
		};
	};

	RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 = r1;

	word_FFFF8890 = r2;

	LAUNCH_TEST_FLAG_1_FFFF889A = r8;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_FBB4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_FD34()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_FDB6()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_FDF4()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Coolant_Temp_Threshold_Tests()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Coolant_Calc1_sub_FF2C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Coolant_Calibration_Calc()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Update_IAT_Sensor()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Update_Air_Temp_Scaled()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10188()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10220()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_O22_Manipulations_sub_1023C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_TPS_Load_RPM_Calcs()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_TPS_sub_103DA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_1044C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool F500_CheckIdleRPM()
{
	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_MAP_Coolant_Calcs()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10820()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10878()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_108AA()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_108FE()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10984()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10A80()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10AA6()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Check_MAP_Fault()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Load_sub_10B72()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10C6E()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10E10()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_MAP_Hz_Calc_sub_10E54()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_sub_10F08()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Countdown_Timers_sub_10F5C()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void F500_Battery_Calcs_sub_1101A()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


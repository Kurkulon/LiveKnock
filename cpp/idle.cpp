#pragma section _idle

#include <umachine.h>

#include "ram.h"
#include "misc.h"
#include "constbyte.h"
#include "constword.h"




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define byte_102E							(*(const byte*)0x102E)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define word_19E6							(*(const u16*)0x19E6)
//#define word_18C0							(*(const u16*)0x18C0)
//#define word_18C2							(*(const u16*)0x18C2)
//#define word_18C4							(*(const u16*)0x18C4)
//#define Desired_Idle_RPM_with_AC_on_18BE	(*(const u16*)0x18BE)
//#define word_1A20							(*(const u16*)0x1A20)
//#define word_1A22							(*(const u16*)0x1A22)
//#define word_1A24							(*(const u16*)0x1A24)
//#define word_1A26							(*(const u16*)0x1A26)

#define CEL8_6DA0							(*(const u16*)0x6DA0)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#define SPEED_FLAGS						(*(u16*)0xFFFF8A0A)
//#define word_FFFF8CBC					(*(u16*)0xFFFF8CBC)
//#define word_FFFF8CBE					(*(u16*)0xFFFF8CBE)
//#define word_FFFF86C2					(*(u16*)0xFFFF86C2)
//#define u16_FLAGS_FFFF8C96				(*(u16*)0xFFFF8C96)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define VOLT9_66C6							((Axis*)0x66C6)
#define RPM8_6570							((Axis*)0x6570)
#define LOAD9_65DC							((Axis*)0x65DC)
#define BAR4_66F6							((Axis*)0x66F6)
#define CEL8_6914							((Axis*)0x6914)
#define CEL8_79AE							((Axis*)0x79AE)

#define CEL8_6946_IDLE						((Axis*)0x6946)
#define RPM27_6960_IDLE						((Axis*)0x6960)
#define BAR5_66E2							((Axis*)0x66E2)

#define RPM10_67DE							((Axis*)0x67DE)
#define LOAD9_67FC							((Axis*)0x67FC)
#define CEL8_6D98							((Axis*)0x6D98)
#define RPM9_65A4							((Axis*)0x65A4)

#define CEL7_6818							((Axis*)0x6818)
#define RPM8_79EE							((Axis*)0x79EE)



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define IDLERPMDRV_7A08						((Map3D_B**)0x7A08)
#define IDLERPMNEYT_7A28					((Map3D_B**)0x7A28)
#define IDLERPMNEYTACOFF_7A48				((Map3D_B**)0x7A48)
#define unk0067ICSVACOFFDRV1_7A68			((Map3D_B**)0x7A68)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define IDLERPMNS_485E						((Map3D_B*)0x485E)
#define IDLESTEPLOOKtab_476C				((Map3D_B*)0x476C)
#define unk111_4850							((Map3D_B*)0x4850)
#define ICSVADDBARO_3BB4					((Map3D_B*)0x3BB4)
#define ICSVSTARTUPADD2_3B30				((Map3D_B*)0x3B30)
#define ICSVSTARTUPADD1_4924				((Map3D_B*)0x4924)
#define GENCHARG_3D1A						((Map3D_B*)0x3D1A)
#define ISCVAD1_3B06						((Map3D_B*)0x3B06)
#define ICSVACOFFDRV_3ADC					((Map3D_B*)0x3ADC)
#define ICSVAD2_3B22						((Map3D_B*)0x3B22)
#define ISCVAD3_3AF8						((Map3D_B*)0x3AF8)
#define ISCVAD4_3B14						((Map3D_B*)0x3B14)
#define EGRRPM_3E78							((Map3D_B*)0x3E78)
#define IDLEERRNORM_3BC0					((Map3D_B*)0x3BC0)
#define IDLEERRA_CON_3BD0					((Map3D_B*)0x3BD0)
#define unk070_4884							((Map3D_B*)0x4884)

#define DECFUCUTDEL3_63EA					((Map3D_B*)0x63EA)
#define DECFUCUTDEL1_6362					((Map3D_B*)0x6362)
#define DECFUCUTDEL4_642E					((Map3D_B*)0x642E)
#define DECFUCUTDEL2_63A6					((Map3D_B*)0x63A6)
#define DECFUELCUTDEL5_4BB6					((Map3D_B*)0x4BB6)

#define unk140_6472							((Map3D_B*)0x6472)
#define unk142_648E							((Map3D_B*)0x648E)
#define unk141_6480							((Map3D_B*)0x6480)
#define unk143_649C							((Map3D_B*)0x649C)

#define unk041_3B92							((Map3D_B*)0x3B92)
#define unk042_3BA0							((Map3D_B*)0x3BA0)

 


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
#define unk0064_486C						((Map3D_W*)0x486C)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define sub_21ECC							((u16(*)(u16))0x21ECC)
#define sub_21EF8							((u16(*)(void))0x21EF8)
#define sub_21EE4							((bool(*)(void))0x21EE4)
#define sub_21E9C							((u16(*)(u16))0x21E9C)
#define sub_21EB4							((u16(*)(u16))0x21EB4)




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_NVRAM_18F80();
static void SysInit_sub_19014();
extern "C" void AA05_root_sub_19096();
static void AA05_sub_19188();
static void AA05_sub_19260();
static void AA05_sub_1929C();
static void AA05_sub_192CA();
static void AA05_IDLE_sub_192FC();
static void AA05_sub_1945C();
static void AA05_sub_195A2();
static void AA05_sub_19804();
static void AA05_sub_1997C();
static void AA05_GENERATOR_CHARGING_sub_19A2C();
static void AA05_sub_19B98();
static void AA05_sub_19E10(u16 v);
static void AA05_Init_sub_19E2A();
static u16 AA05_IDLESTEPLOOKtab_sub_19E5A(u16);
static void AA05_sub_19E8C();
static void AA05_sub_19EEC();
static void AA05_sub_19F0E();
static void AA05_sub_19F22();
static u16 AA05_sub_1A068();
static void AA05_sub_1A0BA();
static bool AA05_sub_1A0E8();
static void AA05_sub_1A11C();
static void AA05_sub_1A304();
static void AA05_sub_1A3F8();
static void AA05_sub_1A448();
static void AA05_sub_1A462();
static void AA05_sub_1A476();
static void AA05_sub_1A4A6();
static bool AA05_sub_1A4F2();
static void AA05_sub_1A58E();
static void AA05_sub_1A5A8();
static void AA05_sub_1A74E();
static void AA05_sub_1A7E0();
static bool AA05_sub_1A8CA();
static void AA05_sub_1A99C();
static void AA05_sub_1A9D0();
static void AA05_sub_1AAB4(u16 v);
static void AA05_sub_1AB00();
static void AA05_sub_1AB72();
static void AA05_sub_1ABA4();
static bool AA05_sub_1ABEC();
static void AA05_Set_MUT22_0x04();
static void AA05_sub_1AD34();
static void AA05_sub_1ADF4();
static bool AA05_sub_1AE26();
static void AA05_sub_1AE76();
static void AA05_sub_1AE90();
static void AA05_sub_1AEC6();
static void AA05_sub_1AF30();
static u16  AA05_sub_1B0BC();
static u16 AA05_sub_1B0DC(u16 v);
static void AA05_sub_1B178();
static bool AA05_sub_1B196();
static void AA05_sub_1B260();
static void AA05_sub_1B282();
static u16 AA05_sub_1B470();
static u16 AA05_sub_1B4C2();
static bool AA05_sub_1B588();
static u16  AA05_sub_1B652();
static u16 AA05_sub_1B67E();
static u16  AA05_sub_1B7C0();
static u16  AA05_sub_1B7EA();
static u16 AA05_sub_1B81C();
static u16  AA05_sub_1B876();
static u16  AA05_sub_1B89C();
static u16  AA05_Return_0_1();
static u16  AA05_sub_1B8CA();
static void AA05_sub_1B8F2();
static bool AA05_sub_1B934();
static void AA05_sub_1BA2C();
static u16 AA05_sub_1BAC6();
static void AA05_sub_1BAFE();
static bool AA05_sub_1BB1A();
static void AA05_sub_1BB96();
static void AA05_sub_1BC6E();
static u16 AA05_sub_1BD34();
static void AA05_sub_1BD6C();
static void AA05_sub_1BDA0();
static void AA05_sub_1BDC6();
static void AA05_sub_1BE74();

static u16 sub_220A2();
static u16 sub_220B4();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_NVRAM_18F80()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void SysInit_sub_19014()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C" void AA05_root_sub_19096()
{
	AA05_sub_19188();
	AA05_sub_1A7E0();
	AA05_sub_1AD34();

	if (sub_21EF8() != 0 && (wMUT22 & 0xB0) == 0)
	{
		word_FFFF8CA8 = AA05_IDLESTEPLOOKtab_sub_19E5A(word_FFFF8CAA = wMUT9E);
		CLR(wMUT22, 0x3F);
		CLR(wMUT23, 0xB5);
	};

	AA05_sub_1BD6C();
	AA05_sub_1BE74();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19188()
{
	AA05_sub_19260();
	AA05_sub_1929C();
	AA05_IDLE_sub_192FC();
	AA05_sub_195A2();
	AA05_sub_1997C();
	AA05_GENERATOR_CHARGING_sub_19A2C();
	AA05_sub_19B98();
	AA05_Init_sub_19E2A();
	AA05_sub_19E8C();
	AA05_sub_19EEC();
	AA05_sub_1A3F8();
	AA05_sub_1A448();
	AA05_sub_1A462();
	AA05_sub_1A476();
	AA05_sub_1A4A6();
	AA05_sub_1A58E();
	AA05_sub_1A5A8();
	AA05_sub_1A74E();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19260()
{
	word_FFFF8CDC = wMUT0D_Fuel_Trim_Middle;

	if ((RT_FLAG1_FFFF8888 & RT_7_bit) == 0)
	{
		word_FFFF85D8 = word_194C/*20*/;
	};

	word_FFFF8CE0 = Table_Lookup_byte_2D_3D(unk111_4850);

	CLR(u16_FLAGS_FFFF8C96, 0x100);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1929C()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		AA05_sub_192CA();

		word_FFFF8CB8 = 0;
		word_FFFF8CDE = 0;

		CLR(u16_FLAGS_FFFF8C96, 0x1E);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_192CA()
{
	u32 r3, r13;

	if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) // Engine Running
	{
		r3 = word_1926;
		r13 = word_1928;
	}
	else
	{
		r3 = word_192A;
		r13 = word_192A;
	};

	wMUT09 = r3;
	word_FFFF8CA0 = r13;
	wMUT0B = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_IDLE_sub_192FC()
{
	u16 r1;

	if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) // Engine Running
	{
		if (SPEED_FLAGS & SPD_2_ALWAYS_0)
		{
			r1 = Query_byte_2D_3D_Table(IDLERPMDRV_7A08);
		}
		else
		{
			r1 = Table_Lookup_byte_2D_3D(IDLERPMNS_485E);
		};

		if ((RT_FLAG1_FFFF8888 & RT_14_bit) && r1 < word_19E6)
		{
			r1 = word_19E6;
		};
	}
	else
	{
		r1 = Query_byte_2D_3D_Table(IDLERPMNEYT_7A28);
	};

	word_FFFF8CBC = r1;

	AA05_sub_1945C();

	if (RT_FLAG1_FFFF8888 & AC_SWITCH) 
	{
		u16 r13;

		if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) 
		{
			if (RT_FLAG1_FFFF8888 & RT_0_bit) 
			{
				r13 = word_18C2;
			}
			else
			{
				r13 = Desired_Idle_RPM_with_AC_on_18BE;
			};
		}
		else
		{
			if (RT_FLAG1_FFFF8888 & RT_0_bit) 
			{
				r13 = word_18C4;
			}
			else
			{
				r13 = word_18C0;
			};
		};

		if (r13 >= r1)
		{
			r1 = r13;
		};
	};

	if (r1 < word_FFFF8CBE)
	{
		r1 = word_FFFF8CBE;
	};

	wMUT24_Target_Idle_RPM = sub_21ECC(Lim_FF(r1));


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1945C()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		SET(u16_FLAGS_FFFF8C96, 0x20);

		word_FFFF86C2 = 0;
	};

	if (wMUT1E_MAF_RESET_FLAG & CRANKING)
	{
		if (wMUT11_Intake_Air_Temperature_Scaled > word_1A26)
		{
			SET(u16_FLAGS_FFFF8C96, 0x20);
		}
		else
		{
			CLR(u16_FLAGS_FFFF8C96, 0x20);
		};

	};

	word_FFFF86C2 = (wMUT11_Intake_Air_Temperature_Scaled > word_1A20) ? word_1A24 * 80 : 0;

	if (word_FFFF86C2 != 0 && (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1))
	{
		u16 r1 = 0;

		if (RT_FLAG1_FFFF8888 & AC_SWITCH)
		{		
			if (byte_102E == 2 && (RT_FLAG1_FFFF8888 & RT_0_bit))
			{
				r1 = word_18C2 + Mul_Div_R(word_FFFF86C2, word_1A22, word_1A24 * 80);
			};
		}
		else
		{
			r1 = Mul_Div_R(word_FFFF86C2, word_1A22, word_1A24 * 80);

			u16 r2 = CEL8_6DA0 - 1;

			Map3D_B *p = (SPEED_FLAGS & SPD_2_ALWAYS_0) ? (Map3D_B*)GET_LOC_DIM_sub_DF6(IDLERPMDRV_7A08) : IDLERPMNS_485E;

			r1 += p->m2d.data[r2];
		};

		word_FFFF8CBE = Lim_FF(r1);
	}
	else
	{
		word_FFFF8CBE = 0;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_195A2()
{
	if (byte_1039/*0*/ == 1)
	{
		u32 RTF = ((RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888) & RT_FLAG1_COPY_FFFF888A);

		if (RTF & POWER_STEERING)
		{
			word_FFFF854A = 0;
		};

		if (wMUT2E_Vehicle_Speed_Frequency >= word_18D8/*28*/)
		{
			SET(wMUT23, 0x400);
		}
		else
		{
			CLR(wMUT23, 0x400);
		};

		if (RTF & POWER_STEERING)
		{
			if (wMUT23 & 0x400)
			{
				SET(wMUT23, 0x200);
			}
			else
			{
				CLR(wMUT23, 0x200);
			};
		};

		u32 r13;

		if ((wMUT23 & 0x200) == 0 && ZRO(RT_FLAG1_FFFF8888, AC_SWITCH|POWER_STEERING))
		{
			SET(wMUT23, 0x1000);

			r13 = (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1/*Engine Running*/) ? word_18D0 : word_18D2;

			if (r13 > word_FFFF854A)
			{
				CLR(wMUT23, 0x800);
			}
			else
			{
				SET(wMUT23, 0x800);
			};
		}
		else
		{
			CLR(wMUT23, 0x1800);
		};


		if ((RT_FLAG1_FFFF8888 & POWER_STEERING) == 0)
		{
			r13 = word_FFFF8CD2;
		}
		else if ((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) == 0)
		{
			r13 = word_18CA/*33*/;
		}
		else
		{
			r13 = word_18C8/*31*/;
		};

		if (word_FFFF85D0 != 0)
		{
			if ((wMUT23 & 0x1800) == 0x1000)
			{
				if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)
				{
					word_FFFF85D0 = word_18DA/*6*/;
				}
				else
				{
					word_FFFF85D0 = word_18DC/*3*/;
				};
			}
			else
			{
				word_FFFF85D0 = word_18CC/*1*/;
			};

			r13 = Sub_Lim_0(r13, word_18CE/*1*/);
		};

		if (wMUT23 & 0x800)
		{
			u32 r3 = (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? word_18D4/*7*/ : word_18D6/*7*/;
			
			if (r13 < r3)
			{
				r13 = r3;
			};
		};

		word_FFFF8CD2 = r13;
	}
	else if (byte_1039 == 2/*0*/)
	{
		AA05_sub_19804();
	}
	else
	{
		word_FFFF8CD2 = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19804()
{
	u32 RTF = ((RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888) & RT_FLAG1_FFFF8888);

	if (wMUT23 & 1)
	{
		timer_up_FFFF8534 = 0xFFFF;
		timer_up_FFFF8536 = 0xFFFF;
	}
	else if (RTF & POWER_STEERING)
	{
		timer_up_FFFF8534 = 0;
	}
	else if (RTF & POWER_STEERING) 
	{
		timer_up_FFFF8536 = 0;

		CLR(word_FFFF8C94, 0x10);
	};

	u32 r1;

	if (RT_FLAG1_FFFF8888 & AC_SWITCH)
	{
		if (RT_FLAG1_FFFF8888 & AC_SWITCH)
		{
			r1 = word_2BD2;
		}
		else
		{
			r1 = word_2BD4;
		};
	}
	else
	{
		if (RT_FLAG1_FFFF8888 & AC_SWITCH)
		{
			r1 = word_2BCE;
		}
		else
		{
			r1 = word_2BD0;
		};
	};

	u32 r3;

	if (RT_FLAG1_FFFF8888 & POWER_STEERING)
	{
		if (timer_up_FFFF8536 <= word_2BDA)
		{
			r3 = r1;
		}
		else
		{
			u32 r13 = (RT_FLAG1_FFFF8888 & AC_SWITCH) ? word_2BCC : word_2BCA;

			if (timer_up_FFFF8534 <= r13)
			{
				if (RT_FLAG1_FFFF8888 & AC_SWITCH)
				{
					r3 = word_2BC8;
				}
				else
				{
					r3 = word_2BC6;
				};
			};
		};
	};

	if (word_FFFF8C94& 0x10)
	{
		r1 = r3;
	}
	else if (word_FFFF85D0 == 0)
	{
		r3 = Sub_Lim_0(r3, word_18CE);

		if ((RT_FLAG1_FFFF8888 & POWER_STEERING) && r3 < r1)
		{
			r3 = r1;
		};

		u32 r13; 

		if (RT_FLAG1_FFFF8888 & POWER_STEERING)
		{
			r13 = word_18CC;
		}
		else if (RT_FLAG1_FFFF8888 & AC_SWITCH)
		{
			r13 = word_2BD8;
		}
		else
		{
			r13 = word_2BD6;
		};

		word_FFFF85D0 = r13;
	};

	if ((RT_FLAG1_FFFF8888 & POWER_STEERING) && r3 == r1)
	{
		SET(word_FFFF8C94, 0x10);
	};

	word_FFFF8CD2 = r3;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1997C()
{
	if (tm_10ms_FFFF86C8 == 0)
	{
		DECLIM(word_FFFF8CCA);

		tm_10ms_FFFF86C8 = word_19DC/*4*/;
	};

	tm_10ms_FFFF86C8 = 0;
	word_FFFF8CCA = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_GENERATOR_CHARGING_sub_19A2C()
{
	wMUTB4_lookup_value = RPM_x_4_096__1 >> 4;

	Table_Lookup_Axis(RPM10_67DE);
	Table_Lookup_Axis(LOAD9_67FC);

	bMUT8E_Solenoid_Duty = (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) ? 0 : Table_Lookup_byte_2D_3D(GENCHARG_3D1A);

	word_FFFF8DC8 = word_FFFF8DC6;

	u32 r3 = word_FFFF8DC8 * word_1BC6 + word_1BC2;
	u32 r13 = 0;

	if (word_FFFF8DC8 != 0)
	{
		r13 = (word_FFFF8DC8 - 1) * word_1BC6 + word_1BC4;
	};

	if (bMUT8E_Solenoid_Duty >= r3)
	{
		r3 = 0;

		if (bMUT8E_Solenoid_Duty >= word_1BC2)
		{
			r3 = 1 + Div_R4_R5__R0(bMUT8E_Solenoid_Duty - word_1BC2, word_1BC6);
		};

		r13 = r3;
	}
	else if (bMUT8E_Solenoid_Duty < r13)
	{
		r3 = 0;

		if (bMUT8E_Solenoid_Duty >= word_1BC4)
		{
			r3 = 1 + Div_R4_R5__R0(bMUT8E_Solenoid_Duty - word_1BC4, word_1BC6);
		};

		r13 = r3;
	}
	else
	{
		r13 = word_FFFF8DC6;
	};

	// loc_19B5E

	word_FFFF8DC6 = (r13 < word_1BC8) ? r13 : word_1BC8;

	if (sub_21EE4())
	{
		word_FFFF8DC8 = 0;
		word_FFFF8DC6 = 0;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19B98()
{
	u32 r1 = RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888;


	if (r1 & POWER_STEERING)
	{
		AA05_sub_19E10(word_18F4/*80*/);
	};

	if (r1 & AC_SWITCH)
	{
		AA05_sub_19E10(word_18EC/*80*/);
	};

	if (r1 & RT_5_ALWAYS_1)
	{
		AA05_sub_19E10((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? word_18F2/*80*/ : word_18F0/*80*/);
	};

	if (wMUT73_TPS_Open_Delta >= word_18FA/*4*/)
	{
		AA05_sub_19E10(word_18F8/*40*/);
	};

	if (r1 & RT_9_bit)
	{
		AA05_sub_19E10(word_190E/*80*/);
	};

	if (RT_FLAG1_FFFF8888 & RT_7_bit)
	{
		if (MUT21_RPM_x125div4 > (wMUT24_Target_Idle_RPM + word_1902/*6*/))
		{
			word_FFFF85CC = word_1900;
		};
	}
	else
	{
		word_FFFF85CC = word_1900;
		word_FFFF85CE = word_1906;
	};

	// loc_19C52

	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || (word_FFFF8BBA & 1))
	{
		AA05_sub_19E10(word_18EA/*120*/);
	};

	if (wMUT23 & 0x20)
	{
		AA05_sub_19E10(word_18EE/*80*/);
	};

	if (wMUT19_Startup_Check_Bits & 0x40)
	{
		AA05_sub_19E10(word_18FC/*80*/);
	};

	if (word_FFFF8D60 & 4)
	{
		AA05_sub_19E10(word_18F6/*80*/);
	};

	if (FUEL_CUT_FLAG_FFFF8A5E & 0x200)
	{
		AA05_sub_19E10(word_1B9A/*40*/);
	};

	if (r1 & RT_14_bit)
	{
		AA05_sub_19E10(word_19EE/*0*/);
	};

	// loc_19D60

	if (word_FFFF8DC6 != word_FFFF8DC8)
	{
		if (cranking_end_timer_up >= word_1BD0/*0*/)
		{
			AA05_sub_19E10(word_1BCE/*0*/);
		};

		if (word_FFFF86CA < word_1BCC)
		{
			word_FFFF86CA = word_1BCC;
		};
	};

	if (r1 & RT_0_bit)
	{
		if (word_FFFF86CA < (word_19FE/*20*/ << 2))
		{
			word_FFFF86CA = (word_19FE/*20*/ << 2);
		};
	};


	if (word_FFFF8CD2 != 0)
	{
		if (ZRO(RT_FLAG1_FFFF8888, POWER_STEERING))
		{
			AA05_sub_19E10(word_190A/*40*/);
		};
	};

	if (byte_1050 != 0 && word_FFFF8CD8 != 0)
	{
		AA05_sub_19E10(word_19E2/*0*/);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19E10(u16 v)
{
	if (v >= AA05_word_FFFF85CA)
	{
		AA05_word_FFFF85CA = v;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_Init_sub_19E2A()
{
	word_FFFF8CB0 = (wMUT10_Coolant_Temperature_Scaled >= word_1A14 && ZRO(word_FFFF80E6, 0x300)) ? word_1A10 : word_1A12;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_IDLESTEPLOOKtab_sub_19E5A(u16 v)
{
	Table_Lookup_Axis(CEL8_6946_IDLE);

	wMUTB4_lookup_value = v;

	Table_Lookup_Axis(RPM27_6960_IDLE);

	return Table_Lookup_byte_2D_3D(IDLESTEPLOOKtab_476C);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19E8C()
{
	if ((wMUT1E_MAF_RESET_FLAG & CRANKING) || (wMUT22 & 0xA0))
	{
		word_FFFF8CC8 = Table_Lookup_byte_2D_3D(unk041_3B92);
	}
	else if (word_FFFF8CC8 != 0 && word_FFFF86C4 == 0)
	{
		word_FFFF8CC8 -= 1;

		word_FFFF86C4 = Table_Lookup_byte_2D_3D(unk042_3BA0);
	};

	if (FLAGS_FFFF8EB0 & 0x80)
	{
		word_FFFF8CC8 = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19EEC()
{
	AA05_sub_19F0E();
	AA05_sub_19F22();
	AA05_sub_1A0BA();
	AA05_sub_1A11C();
	AA05_sub_1A304();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19F0E()
{	
	CLR(wMUT23, 0x40);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_19F22()
{
	if (word_FFFF8CB8 != 0)
	{
		u32 r1 = word_FFFF85BC;

		u32 r13 = sub_21EB4(AA05_sub_1A068());

		if (r1 == 0 || r1 > r13)
		{
			r1 = r13;
		};

		if (word_FFFF85BC == 0)
		{
			if (word_FFFF8C94 & 0x4000)
			{
				word_FFFF8CB8 = Sub_Lim_0(word_FFFF8CB8, word_2984);
				word_FFFF8CDE = Sub_Lim_0(word_FFFF8CDE, word_2984);
			}
			else
			{
				word_FFFF8CB8 = Sub_Lim_0(word_FFFF8CB8, word_FFFF9962);
				word_FFFF8CDE = Sub_Lim_0(word_FFFF8CDE, word_FFFF9962);
			};
		};

		word_FFFF85BC = r1;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1A068()
{
	if (word_FFFF8C94 & 0x4000)
	{
		return word_2986;
	};

	if (RT_FLAG1_FFFF8888 & RT_7_bit)
	{
		return (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? word_1940 : word_1942;
	}
	else
	{
		return (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? word_193A : word_193C;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A0BA()
{
	WFLAG(u16_FLAGS_FFFF8C96, 0x80, AA05_sub_1A0E8());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1A0E8()
{
	if (wMUT17_TPS_ADC8bit <= word_1A04 || wMUT1C_ECU_Load > word_1A06)
	{
		word_FFFF85BE = word_1A08;
	};

	return word_FFFF85BE == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A11C()
{
	TRG(word_FFFF8C94, 4, wMUT10_Coolant_Temperature_Scaled, word_196C, word_196A);

	if (ZRO(RT_FLAG1_FFFF8888, RT_7_bit) && ZRO(u16_FLAGS_FFFF8C96, 0x80) && MUT20_RPM_Idle_x125div16 > word_1938)
	{
		u32 r1;

		if (wMUT23 & 0x40)
		{
			r1 = word_1968;
		}	
		else
		{
			Map3D_B *p;

			if (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)
			{
				p = (RT_FLAG1_FFFF8888 & AC_SWITCH) ? DECFUCUTDEL3_63EA : DECFUCUTDEL1_6362;
			}
			else
			{
				p = (RT_FLAG1_FFFF8888 & AC_SWITCH) ? DECFUCUTDEL4_642E : DECFUCUTDEL2_63A6;
			};

			Table_Lookup_Axis(CEL7_6818);
			Table_Lookup_Axis(RPM8_79EE);

			r1 = Table_Lookup_byte_2D_3D(p);
		};

		u32 r13 = Table_Lookup_byte_2D_3D(DECFUELCUTDEL5_4BB6);
	
		if (ZRO(word_FFFF8C94, 4) && r13 < word_196E)
		{
			r13 = word_196E;
		};

		r1 = sub_21E9C(r13 + r1);

		CLR(word_FFFF8C94, 0x4000);

		if (word_FFFF8CB8 < r1)
		{
			Table_Lookup_Axis(RPM8_79EE);

			Map3D_B *p;

			if (wMUT2E_Vehicle_Speed_Frequency >= word_2CAC/*6*/)
			{
				p = (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? unk140_6472 : unk141_6480;
			}
			else
			{
				p = (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? unk142_648E : unk143_649C;
			};

			word_FFFF9962 = Table_Lookup_byte_2D_3D(p);
		};

		// loc_1A2AC

		if (word_FFFF8CB8 < r1)
		{
			word_FFFF8CB8 = r1;
		};

		if (ZRO(word_FFFF8C94, 0x8000))
		{
			r13 = 0;
		}
		else if (RT_FLAG1_FFFF8888 & AC_SWITCH)
		{
			r13 = word_2980;
		}
		else
		{
			r13 = word_2982;
		};

		if (word_FFFF8CB8 < r13)
		{
			word_FFFF8CB8 = r13;
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A304()
{
	if ((byte_103B == 0 || (RT_FLAG1_FFFF8888 & RACING)) 
		&& ((RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888) & RT_FLAG1_FFFF8888 & RT_7_bit))
	{
		u32 r13 = Sub_Lim_0(wMUT16_ISC_Steps + word_FFFF8CB8, wMUT25_Idle_Stepper_Value);

		if (word_FFFF8CB8 > r13)
		{
			word_FFFF8CB8 = r13;
		};
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A3F8()
{
	if (byte_1038 != 0)
	{
		if (RT_FLAG1_FFFF8888 & AC_SWITCH)
		{
			word_FFFF85C8 = word_18EC;
		};

		if (ZRO(RT_FLAG1_FFFF8888, AC_SWITCH) && word_FFFF85C8 != 0 && wMUT10_Coolant_Temperature_Scaled >= word_18E6/*72*/)
		{
			word_FFFF8CCC = word_18E8/*10*/;
		}
		else
		{
			word_FFFF8CCC = 0;
		};
	}
	else
	{
		word_FFFF8CCC = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A448()
{
	word_FFFF8CC6 = 0;
	CLR(word_FFFF8C94, 0x80);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A462()
{
	CLR(wMUT23, 0x100);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A476()
{
	Table_Lookup_Axis(BAR5_66E2);

	word_FFFF8CCE = Table_Lookup_byte_2D_3D((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? ICSVADDBARO_3BB4 : ICSVADDBARO_3BB4);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A4A6()
{
	if (AA05_sub_1A4F2())
	{
		word_FFFF8CD0 = word_1974/*33*/;
		word_FFFF85D4 = word_197C/*0*/;
	}
	else if (word_FFFF85D4 == 0)
	{
		word_FFFF8CD0 = Sub_Lim_0(word_FFFF8CD0, word_1974/*33*/);
		word_FFFF85D4 = word_197C/*0*/;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1A4F2()
{
	u32 RTF = RT_FLAG1_COPY_FFFF888A ^ RT_FLAG1_FFFF8888;

	if ((RTF & RT_FLAG1_FFFF8888 & AC_SWITCH) || (RTF & RT_FLAG1_COPY_FFFF888A & RT_5_ALWAYS_1))
	{
		word_FFFF85C2 = word_1976/*4*/;
	};


	if (word_FFFF85C2 != 0 
		|| wMUT10_Coolant_Temperature_Scaled <= word_1972/*93*/ 
		|| MUT20_RPM_Idle_x125div16 >= word_1970 
		|| (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL)) 
		|| cranking_stall_timer_up < word_1978/*0*/)
	{
		CLR(wMUT23, 4);
	}
	else
	{
		if (ZRO(wMUT23, 4))
		{
			word_FFFF85C4 = 0;
		};

		SET(wMUT23, 4);
	};

	return wMUT23 & 4;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A58E()
{
	if (ZRO(word_FFFF8D60, 3))
	{
		word_FFFF86D6 = word_18E4/*80*/;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A5A8()
{
	u32 r1 = ((RPM_x_4_096__1 >> 3) + 1) >> 1;

	WFLAG(wMUT23, 8, r1 >= rpm_x125div32_B && (r1 - rpm_x125div32_B) >= word_19E4);

	if ((byte_1050 == 1 && (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1)) 
		|| ZRO(RT_FLAG1_FFFF8888, RT_7_bit) 
		|| (byte_1050 == 2 && (MUT21_RPM_x125div4 <= word_298A || wMUT2E_Vehicle_Speed_Frequency > word_298C || ZRO(RT_FLAG1_FFFF8888, 8))))
	{
		word_FFFF85D6 = 0;
	}
	else
	{
		word_FFFF85D6 = word_19DE;
	};

	word_FFFF8CD8 = (byte_1050 != 0 && word_FFFF85D6 != 0) ? word_19E0 : 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A74E()
{
	TRG(u16_FLAGS_FFFF8C96, 0x40, wMUT10_Coolant_Temperature_Scaled, word_2106, word_2104);

	if (u16_FLAGS_FFFF8C96 & 0x40)
	{
		if (word_FFFF87AE == 0)
		{
			DECLIM(word_FFFF8CE2);

			word_FFFF87AE = word_2108;
		};
	}
	else
	{
		word_FFFF87AE = word_2108;

		word_FFFF8CE2 = Table_Lookup_byte_2D_3D(unk070_4884);
	};

	if (FLAGS_FFFF8EB0 & 0x80)
	{
		word_FFFF8CE2 = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A7E0()
{
	if (AA05_sub_1A8CA())
	{
		AA05_sub_1A99C();
	};

	if (wMUT22 & 0x20)
	{
		AA05_sub_1A9D0();
	};

	if (((RT_FLAG1_FFFF8888 & 0x40) && timer_down_TXFLAG3_FFFF8574 != 0) || (wMUT22 & 0x20))
	{
		CLR(wMUT22, 0x40);
	};

	if(ZRO(wMUT22, 0x20))
	{
		if ((wMUT22 & 0x80) || (timer_down_TXFLAG3_FFFF8574 == 0 && ZRO(wMUT22, 0x40)))
		{
			AA05_sub_1AB00();
		};
	};

	if (ZRO(wMUT22, 0xA0) && timer_down_TXFLAG3_FFFF8574 == 0)
	{
		AA05_sub_1AB72();
	}
	else
	{
		CLR(wMUT22, 0x10);
	};

	if ((wMUT1E_MAF_RESET_FLAG & MAP_error) && ZRO(wMUT1E_MAF_RESET_FLAG, CRANKING|STALL) && ZRO(wMUT22, 0xB0))
	{
		AA05_sub_1ABA4();
	}
	else
	{
		CLR(wMUT22, 8);
	};

	if (AA05_sub_1ABEC() || ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x2000) && (word_FFFF80E6 & 0x300)))
	{
		AA05_Set_MUT22_0x04();
	}
	else
	{
		CLR(wMUT22, 4);
	}

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1A8CA()
{
	u32 r1 = wMUT16_ISC_Steps;

	return SwapBytes16(r1) != r1
			|| ufix8_MUT08_Coolant_Temperature > ufix8_COOLANT_TEMP_CONST_1932 
			|| ufix8_MUT0A_FFFF80BC > ufix8_COOLANT_TEMP_CONST_1932 
			|| ufix8_RAM_VAR_1936_FFFF80BE > ufix8_COOLANT_TEMP_CONST_1932
			|| ufix8_MUT08_Coolant_Temperature < ufix8_COOLANT_TEMP_CONST_1934 
			|| ufix8_MUT0A_FFFF80BC < ufix8_COOLANT_TEMP_CONST_1934 
			|| ufix8_RAM_VAR_1936_FFFF80BE < ufix8_COOLANT_TEMP_CONST_1934;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A99C()
{
	u32 r10 = word_1936;
	wMUT22 = r10 * 32;

	ufix8_RAM_VAR_1936_FFFF80BE = r10;
	ufix8_MUT0A_FFFF80BC = r10;
	ufix8_MUT08_Coolant_Temperature = r10;

	AA05_sub_192CA();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1A9D0()
{
	if (ZRO(wMUT22, 3))
	{
		__disable_irq();

		wMUT16_ISC_Steps = SwapBytes16(word_197E/*136*/);

		__enable_irq();

		SET(wMUT22, 2);
	};

	if (wMUT22 & 2)
	{
		if (wMUT16_ISC_Steps & 0xFF)
		{
			word_FFFF8CA8 = 0;

			AA05_sub_1AAB4(word_18EA/*120*/);
		}
		else
		{
			CLR(wMUT22, 2);
			SET(wMUT22, 1);
		};
	};

	if (wMUT22 & 1)
	{
		if (wMUT16_ISC_Steps == word_1984/*6*/)
		{
			__disable_irq();

			wMUT16_ISC_Steps = SwapBytes16(0);

			__enable_irq();

			CLR(wMUT22, 0x23);
		}
		else
		{
			word_FFFF8CA8 = word_1984/*6*/;

			AA05_sub_1AAB4(word_18EA/*120*/);
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AAB4(u16 v)
{
	AA05_sub_19E10(v);

	SET(u16_FLAGS_FFFF8C96, 1);

	CLR(wMUT23, 0xB5);

	word_FFFF8CB8 = 0;
	word_FFFF8CDE = 0;

	AA05_sub_192CA();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AB00()
{
	SET(wMUT22, 0x80);

	if (wMUT16_ISC_Steps == word_197E/*136*/)
	{
		__disable_irq();

		wMUT25_Idle_Stepper_Value = word_1980;

		wMUT16_ISC_Steps = SwapBytes16(wMUT25_Idle_Stepper_Value);

		CLR(wMUT22, 0x80);

		SET(wMUT22, 0x40);
		
		__enable_irq();
	}
	else
	{
		AA05_sub_1AAB4(word_18EA/*120*/);

		word_FFFF8CA8 = word_197E/*136*/;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AB72()
{
	CLR(wMUT22, 0xAF);
	SET(wMUT22, 0x10);

	AA05_sub_1AAB4(word_18EA);

	word_FFFF8CA8 = some_iscstep_const_1982;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1ABA4()
{
	CLR(wMUT22, 0xB7);
	SET(wMUT22, 8);

	AA05_sub_1AAB4(word_18EA);

	word_FFFF8CA8 = AA05_IDLESTEPLOOKtab_sub_19E5A(word_FFFF8CAA = word_1A00);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1ABEC()
{
	if ((wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING)) || (wMUT22 & 0xB8) || (RT_FLAG1_FFFF8888 & (RT_5_ALWAYS_1|RACING) ) != RT_5_ALWAYS_1 || (RT_FLAG1_FFFF8888 & (SPEED_ADJUST|FIX_TIMING)) != (SPEED_ADJUST|FIX_TIMING))
	{
		tm100_FFFF85C6 = word_1A02;
	};

	return tm100_FFFF85C6 == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_Set_MUT22_0x04()
{
	SET(wMUT22, 4);

	AA05_sub_1AAB4(word_18FE/*80*/);

	u32 r13;

	if (word_FFFF80E6 & 0x300)
	{
		r13 = word_21B8;
	}
	else if (ZRO(SPEED_FLAGS, SPD_2_ALWAYS_0))
	{
		r13 = Table_Lookup_byte_2D_3D(ICSVACOFFDRV_3ADC);
	}
	else
	{
		r13 = Query_byte_2D_3D_Table(IDLERPMNEYTACOFF_7A48);
	};

	word_FFFF8CA8 = AA05_IDLESTEPLOOKtab_sub_19E5A(word_FFFF8CAA = r13 + word_FFFF8CCE + word_FFFF8CE0);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AD34()
{
	if (ZRO(wMUT22, 0xBC))
	{
		AA05_sub_1ADF4();
		
		if (AA05_sub_1AE26())
		{
			AA05_sub_1AE76();
		}
		else if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
		{
			AA05_sub_1B178();
		}
		else if (AA05_sub_1B196())
		{
			SET(wMUT23, 0x10);

			AA05_sub_1B260();
		}
		else
		{
			CLR(wMUT23, 0x10);

			word_FFFF85C0 = word_192E/*200*/;

			AA05_sub_1BC6E();
		};

		word_FFFF8CA8 = AA05_IDLESTEPLOOKtab_sub_19E5A(word_FFFF8CAA);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1ADF4()
{
	if (wMUT1E_MAF_RESET_FLAG & (STALL|CRANKING))
	{
		CLR(wMUT23, 0xB4);
		SET(wMUT23, 1);
	}
	else
	{
		CLR(wMUT23, 1);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1AE26()
{
	if (ZRO(wMUT1E_MAF_RESET_FLAG, CRANKING|STALL))
	{
		SET(u16_FLAGS_FFFF8C96, 1);
	}
	else if (wMUT16_ISC_Steps == wMUT25_Idle_Stepper_Value)
	{
		CLR(u16_FLAGS_FFFF8C96, 1);
	};

	return ZRO(u16_FLAGS_FFFF8C96, 1) && (wMUT1E_MAF_RESET_FLAG & CRANKING);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AE76()
{
	AA05_sub_1AE90();
	AA05_sub_1AEC6();
	AA05_sub_1AF30();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AE90()
{
	word_FFFF8CA4 = Table_Lookup_byte_2D_3D((SPEED_FLAGS & SPD_2_ALWAYS_0) ? ICSVSTARTUPADD2_3B30 : ICSVSTARTUPADD1_4924) + word_FFFF8CCE + word_FFFF8CE0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AEC6()
{
	if (ZRO(RT_FLAG1_FFFF8888, AC_SWITCH) 
		&& ZRO(wMUT23, 1) 
		&& (ZRO(bMUTD3_BitMap4_FCA_Store_FFFF89D8, 0x100) || ZRO(word_FFFF90B6, 1)))
	{
		u32 r0 = Add_Lim_FFFF(0x80, Table_Lookup_word_2D_3D(unk0064_486C));

		word_FFFF8CB6 = Sub_Lim_0(u16_Coolant_Temperature + word_FFFF8CA4, r0);
	}
	else
	{
		word_FFFF8CB6 = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1AF30()
{
	u32 r1 = MAX(word_FFFF8CB6, wMUT76_Idle_Stepper_Y_Axis);

	if (word_FFFF85C4 == 0)
	{
		bool r2 = false;

		if (MUT20_RPM_Idle_x125div16 >= wMUT24_Target_Idle_RPM)
		{
			wMUTB4_lookup_value = MUT20_RPM_Idle_x125div16 - wMUT24_Target_Idle_RPM;
		}
		else
		{
			wMUTB4_lookup_value = wMUT24_Target_Idle_RPM - MUT20_RPM_Idle_x125div16;
			r2 = true;
		};	

		if (wMUTB4_lookup_value > Mul_Fix8_Lim_FFFF(wMUT24_Target_Idle_RPM, AA05_sub_1B0BC()))
		{
			word_FFFF85C4 = word_1920/*40*/;

			Table_Lookup_Axis(RPM9_65A4);

			u32 r3 = Table_Lookup_byte_2D_3D((RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? IDLEERRNORM_3BC0 : IDLEERRA_CON_3BD0);

			u32 r13 = wMUT25_Idle_Stepper_Value;

			if (r2)
			{
				if (r13 < word_FFFF8CB0)
				{
					r1 = AA05_sub_1B0DC(r3 + wMUT76_Idle_Stepper_Y_Axis);
				};
			}
			else if (r13 != 0)
			{
				r1 = AA05_sub_1B0DC(Sub_Lim_0(wMUT76_Idle_Stepper_Y_Axis, r3));
			};	
		};
	};

	word_FFFF8CAA = r1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B0BC()
{
	return (RT_FLAG1_FFFF8888 & RT_5_ALWAYS_1) ? word_1910 : word_1912;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B0DC(u16 v)
{
	if (wMUT23 & 1)
	{
		v = Lim16(v, Sub_Lim_0(word_1904 + word_FFFF8CA4, 0x80), Sub_Lim_0(word_1926 + word_FFFF8CA4, 0x80));
	}
	else if (word_FFFF8CB6 >= v)
	{
		v = word_FFFF8CB6;
	};

	return v;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B178()
{
	AA05_sub_1AE90();
	AA05_sub_1AEC6();

	word_FFFF8CAA = word_FFFF8CA4;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1B196()
{
	return (ZRO(NVRAM_FFFF802C, 0x400) || MUT20_RPM_Idle_x125div16 < wMUT24_Target_Idle_RPM || wMUT10_Coolant_Temperature_Scaled < word_2CAA/*120*/)
		&& (RT_FLAG1_FFFF8888 & RT_7_bit)
		&& ZRO(RT_FLAG1_FFFF8888, RACING) 
		&& AA05_word_FFFF85CA == 0 
		&& word_FFFF8CC6 == 0
		&& word_FFFF8CCA == 0
		&& (word_FFFF85CC == 0 || word_FFFF85CE == 0)
		&& MUT20_RPM_Idle_x125div16 > word_1908/*42*/;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B260()
{
	AA05_sub_1B282();                                       
	AA05_sub_1AEC6();                                       
	AA05_sub_1AF30();                                        
	AA05_sub_1B8F2();                                        
	AA05_sub_1BAFE();                                        
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B282()
{
	u32 r1 = AA05_sub_1B470() + word_FFFF8CCC;

	u32 r13 = AA05_sub_1B4C2();

	if (r1 < r13)
	{
		r1 = r13;
	};

	CLR(u16_FLAGS_FFFF8C96, 2);

	r1 += word_FFFF8CE2;

	r13 = AA05_sub_1B67E();

	if (r1 < r13)
	{
		r1 = r13;
	};

	r13 = AA05_sub_1B7C0();

	if (r1 < r13)
	{
		r1 = r13;
	};

	r1 += word_FFFF8CCE + word_FFFF8CC8;

	u32 r2 = word_FFFF8CC8;

	r13 = word_FFFF8CB8;

	if (r13 > r1)
	{
		SET(wMUT23, 0x20);

		r1 = word_FFFF8CB8;
	}
	else
	{
		CLR(wMUT23, 0x20);

		word_FFFF8CB8 = 0;
		word_FFFF8CDE = 0;
	};

	if (r13 > r2)
	{
		r2 = r13;
	};

	if (FUEL_CUT_FLAG_FFFF8A5E & 0x200)
	{
		r13 = Table_Lookup_byte_2D_3D(EGRRPM_3E78);

		if (r1 < r13)
		{
			r1 = r13;
		};

		if (r2 < r13)
		{
			r2 = r13;
		};
	};

	u32 r8 = AA05_sub_1B7EA() + r1;
	u32 r9 = AA05_sub_1B7EA() + r2;

	r8 += AA05_sub_1B81C();
	r9 += AA05_sub_1B81C();

	r1 = AA05_sub_1B876() + r8;
	r2 = AA05_sub_1B876() + r9;

	if (ZRO(wMUT23, 0x10))
	{
		r1 += word_FFFF8CD0;
		r2 += word_FFFF8CD0;
	};

	r1 += AA05_sub_1B89C();
	r2 += AA05_sub_1B89C();

	r1 += word_FFFF8CC6;
	r2 += word_FFFF8CC6;

	r1 += AA05_Return_0_1();
	r2 += AA05_Return_0_1();

	r1 += sub_220A2();
	r2 += sub_220A2();

	r1 += sub_220B4();
	r2 += sub_220B4();

	r1 += AA05_sub_1B8CA();
	r2 += AA05_sub_1B8CA();

	r1 += word_FFFF8CCA;
	r2 += word_FFFF8CCA;

	r1 += word_FFFF8CD8;
	r2 += word_FFFF8CD8;

	word_FFFF8CA4 = r1;
	word_FFFF8CE6 = r2;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B470()
{
	u32 r13;

	if (ZRO(RT_FLAG1_FFFF8888, RT_5_ALWAYS_1))
	{
		r13 = Query_byte_2D_3D_Table(unk0067ICSVACOFFDRV1_7A68);
	}
	else if (SPEED_FLAGS & SPD_2_ALWAYS_0)
	{
		r13 = Query_byte_2D_3D_Table(IDLERPMNEYTACOFF_7A48);
	}
	else
	{
		r13 = Table_Lookup_byte_2D_3D(ICSVACOFFDRV_3ADC);
	};

	return word_FFFF8CC0 = r13 + word_FFFF8CE0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B4C2()
{
	u32 r13;

	if (RT_FLAG1_FFFF8888 & RPM_4_STALL)
	{
		Map3D_B *p;

		if (RT_FLAG1_FFFF8888 & RPM_0_CRANKING)
		{
			p = (RT_FLAG1_FFFF8888 & RPM_5_REVLIM) ? ISCVAD1_3B06 : ICSVAD2_3B22;
		}
		else
		{
			p = (RT_FLAG1_FFFF8888 & RPM_5_REVLIM) ? ISCVAD3_3AF8 : ISCVAD4_3B14;
		};

		r13 = Table_Lookup_byte_2D_3D(p) + word_FFFF8CE0;
	}
	else
	{
		r13 = 0;
	};

	if ((RT_FLAG1_FFFF8888 & (RPM_14_bit|RPM_5_REVLIM|RPM_2_DECELERATION_FUEL_CUT)) == (RPM_14_bit|RPM_5_REVLIM))
	{
		u32 r3 = word_19EA;

		if (RT_FLAG1_FFFF8888 & RPM_10_bit)
		{
			r3 = word_19E8;
		};

		r3 += word_FFFF8CE0;

		if (r13 < r3)
		{
			r13 = r3;
		};
	};

	return word_FFFF8CC2 = r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1B588()
{
	TRG(u16_FLAGS_FFFF8C96, 0x10, wMUT2E_Vehicle_Speed_Frequency, word_199C, word_199A);

	TRG(u16_FLAGS_FFFF8C96, 8, MUT21_RPM_x125div4, word_19A0, word_199E);

	TRG(u16_FLAGS_FFFF8C96, 4, wMUT10_Coolant_Temperature_Scaled, word_19A2, word_19A4);

	return ((u16_FLAGS_FFFF8C96 & 0x1C) == 0x1C && (RT_FLAG1_FFFF8888 & (RPM_7_CLOSED_LOOP_GENERIC|RPM_5_REVLIM)) == RPM_7_CLOSED_LOOP_GENERIC);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B652()
{
	u32 r13 = word_19A6;

	if (RT_FLAG1_FFFF8888 & AC_SWITCH)
	{
		r13 = (RT_FLAG1_FFFF8888 & RT_0_bit) ? word_19AA : word_19A8;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B67E()
{
	if (word_FFFF86C2 != 0)
	{
		u32 r1 = (u16_FLAGS_FFFF8C96 & 0x20) ? word_1A28 : word_1A2A;

		r1 = Mul_Div_R(word_FFFF86C2, r1, word_1A24*80);

		if (byte_102E/*2*/ == 2 && (RT_FLAG1_FFFF8888 & (AC_SWITCH|RT_0_bit)) == (AC_SWITCH|RT_0_bit))
		{
			r1 += ISCVAD1_3B06->m2d.data[CEL8_6D98->len - 1];
		}
		else
		{
			Map3D_B *p = (SPEED_FLAGS & SPD_2_ALWAYS_0) ? (Map3D_B*)GET_LOC_DIM_sub_DF6(IDLERPMNEYTACOFF_7A48) : ICSVACOFFDRV_3ADC;

			r1 += p->m2d.data[CEL8_6D98->len - 1];
		};

		word_FFFF8CC4 = word_FFFF8CE0 + r1;
	}
	else
	{
		word_FFFF8CC4 = 0;
	};

	return word_FFFF8CC4;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B7C0()
{
	u32 r13 = 0;

	if (wMUT19_Startup_Check_Bits & 0x40)
	{
		r13 = (RT_FLAG1_FFFF8888 & AC_SWITCH) ? word_20F4 : word_20F2;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B7EA()
{
	u32 r13 = 0;

	if (byte_1039 == 1 || byte_1039 == 2)
	{
		r13 = word_FFFF8CD2;
	}
	else if (RT_FLAG1_FFFF8888 & POWER_STEERING)
	{
		r13 = word_18C6;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B81C()
{
	u32 r13 = 0;

	if (byte_103A/*0*/ != 0)
	{
		if (ZRO(RT_FLAG1_FFFF8888, RT_7_bit))
		{
			r13 = word_FFFF86C6;
		}
		else if ((wMUT1E_MAF_RESET_FLAG & DECELERATION_FUEL_CUT) && word_FFFF8AC0 != 0)
		{
			word_FFFF86C6 = word_19B8;

			if (word_FFFF86C6 != 0)
			{
				r13 = (RT_FLAG1_FFFF8888 & STALL) ? word_19B6 : word_19B4;
			};
		};
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B876()
{
	return Lim_FF(word_1BCA * word_FFFF8DC6);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B89C()
{
	u32 r13 = 0;

	if (wMUT84_Thermo_Fan_Duty != 0 && ZRO(RT_FLAG1_FFFF8888, AC_SWITCH))
	{
		r13 = word_18E0;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_Return_0_1()
{
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1B8CA()
{
	u32 r13 = 0;

	if (byte_102D != 0 && (RT_FLAG1_FFFF8888 & (RT_10_bit|AC_SWITCH|RACING)) == (RT_10_bit|RACING))
	{
		r13 = word_19EC;
	};

	return r13;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1B8F2()
{
	if (AA05_sub_1B934())
	{
		AA05_sub_1BA2C();
	};

	if (MUT20_RPM_Idle_x125div16 >= word_1922 && wMUT2E_Vehicle_Speed_Frequency > word_1924)
	{
		AA05_sub_192CA();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1B934()
{
	CLR(word_FFFF987E, 0x80);

	return (wMUT23 & 0x10)
		&& ZRO(wMUT23, 1)
		&& word_FFFF8CC8 == 0
		&& ZRO(RT_FLAG1_FFFF8888, POWER_STEERING) 
		&& word_FFFF86CA == 0
		&& word_FFFF8CA8 != 0
		&& word_FFFF8CA8 < word_FFFF8CB0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BA2C()
{
	u32 r13 = Sub_Lim_0(word_FFFF8CAA + 0x100, word_FFFF8CA4);
	
	r13 = Sub_Lim_0(r13, SHLR8(AA05_sub_1BAC6()));
	
	r13 = Lim_FF(r13);


	if (ZRO(RT_FLAG1_FFFF8888, AC_SWITCH))
	{
		wMUT09 = r13;
	}
	else if (byte_102E != 1 || ZRO(RT_FLAG1_FFFF8888, RT_0_bit))
	{
		wMUT0B = r13;
	}
	else
	{
		word_FFFF8CA0 = r13;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1BAC6()
{
	if (ZRO(RT_FLAG1_FFFF8888, AC_SWITCH))
	{
		return ufix8_MUT08_Coolant_Temperature;
	}
	else if (byte_102E != 1 || ZRO(RT_FLAG1_FFFF8888, RT_0_bit))
	{
		return ufix8_MUT0A_FFFF80BC;
	}
	else
	{
		return ufix8_RAM_VAR_1936_FFFF80BE;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BAFE()
{
	if (AA05_sub_1BB1A())
	{
		AA05_sub_1BB96();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool AA05_sub_1BB1A()
{
	u32 r1 = word_FFFF8CA8;
	u32 r2 = word_FFFF8CB0;

	return AA05_sub_1B934() 
		&& word_FFFF86C2 == 0 
		&& wMUT10_Coolant_Temperature_Scaled > word_1930 
		&& ZRO(RT_FLAG1_FFFF8888, FIX_TIMING)
		&& (byte_102D/*0*/ == 0 || ZRO(RT_FLAG1_FFFF8888, RT_14_bit))
		&& r1 < r2
		&& r1 != 0
		&& word_FFFF85C0 == 0
		&& word_FFFF8CE2 == 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BB96()
{
	u32 r2 = AA05_sub_1BAC6();

	word_FFFF85C0 = word_192C;

	u32 r13 = Sub_Lim_0(word_FFFF8CA4 + SHLR8(r2), 0x80);

	if (word_FFFF8CAA >= r13)
	{
		r13 = word_FFFF8CAA - r13;

		r13 = Add_Lim_FFFF(r2, Mul_Lim_FFFF(r13, 5));
	}
	else
	{
		r13 -= word_FFFF8CAA;

		r13 = Sub_Lim_0(r2, Mul_Lim_FFFF(r13, 5));
	};

	r13 = Lim16(r13, ufix8_COOLANT_TEMP_CONST_1934, ufix8_COOLANT_TEMP_CONST_1932);

	if (ZRO(RT_FLAG1_FFFF8888, AC_SWITCH))
	{
		ufix8_MUT08_Coolant_Temperature = r13;
	}
	else if (byte_102E != 1 || ZRO(RT_FLAG1_FFFF8888, RT_0_bit))
	{
		ufix8_MUT0A_FFFF80BC = r13;
	}
	else
	{
		ufix8_RAM_VAR_1936_FFFF80BE = r13;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BC6E()
{
	AA05_sub_1B282();
	AA05_sub_1AEC6();
	AA05_sub_1B8F2();

	word_FFFF8CAA = Sub_Lim_0(word_FFFF8CA4 + SHLR8(AA05_sub_1BAC6()) + AA05_sub_1BD34(), 0x100);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 AA05_sub_1BD34()
{
	if (ZRO(RT_FLAG1_FFFF8888, AC_SWITCH))
	{
		return wMUT09;
	}
	else if (byte_102E != 1 || ZRO(RT_FLAG1_FFFF8888, RT_0_bit))
	{
		return wMUT0B;
	}
	else
	{
		return word_FFFF8CA0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BD6C()
{
	if (ZRO(wMUT22, 0xA0))
	{
		word_FFFF8CA8 = Lim16(word_FFFF8CA8, 0, word_FFFF8CB0);
	};

	AA05_sub_1BDC6();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// no call

static void AA05_sub_1BDA0()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BDC6()
{
	if (u16_Coolant_Temperature > SHLR8(ufix8_COOLANT_TEMP_CONST_1932))
	{
		u16_Coolant_Temperature = SHLR8(ufix8_MUT08_Coolant_Temperature);
	};


	if ((RT_FLAG1_FFFF8888 & (AC_SWITCH|POWER_STEERING)) 
		|| ZRO(wMUT23, 0x10)
		|| (wMUT23 & 1)
		|| word_FFFF8CA8 == 0
		|| word_FFFF8CB6 < word_FFFF8CAA
		|| (RPM_x_4_096__1 >> 5) < wMUT24_Target_Idle_RPM
		|| ((RPM_x_4_096__1 >> 5) - wMUT24_Target_Idle_RPM) <= word_1998)
	{
		// loc_1BE62

		word_FFFF87AA = word_1996;
	}
	else if (word_FFFF87AA == 0)
	{
		DECLIM(u16_Coolant_Temperature);

		// loc_1BE62

		word_FFFF87AA = word_1996;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void AA05_sub_1BE74()
{
	wMUT25_Idle_Stepper_Value = word_FFFF8CA8;
	wMUT76_Idle_Stepper_Y_Axis = word_FFFF8CAA;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 sub_220A2()
{
	return word_FFFF8CD4 = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static u16 sub_220B4()
{
	return word_FFFF8CD6 = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


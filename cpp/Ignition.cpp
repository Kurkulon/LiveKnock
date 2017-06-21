#pragma section _Ignition

#include <umachine.h>

#include "misc.h"


#define CRANKING				0x01 
#define MAP_error				0x02
#define DECELERATION_FUEL_CUT	0x04
#define FUEL_CUT				0x08
#define STALL					0x10
#define CLOSED_LOOP_GENERIC		0x80

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define byte_1036							(*(const byte*)0x1036)
#define byte_1064							(*(const byte*)0x1064)
#define byte_1074							(*(const byte*)0x1074)
#define byte_1077							(*(const byte*)0x1077)


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define unk119_59DE							((const byte*)0x59DE)
#define unk120_59F2							((const byte*)0x59F2)
#define unk121_59F8							((const byte*)0x59F8)






//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define knockAdder_TripleGain				(*(const u16*)0x17D8)
#define knockAdder_SingleGain				(*(const u16*)0x17DA)
#define word_178A							(*(const u16*)0x178A)
#define word_17A0							(*(const u16*)0x17A0)
#define word_17B2							(*(const u16*)0x17B2)
#define word_17B4							(*(const u16*)0x17B4)
#define word_17CA							(*(const u16*)0x17CA)
#define const_24							(*(const u16*)0x17DC)
#define word_17E4							(*(const u16*)0x17E4)
#define t1_knock_control_accel_delta_17E6	(*(const u16*)0x17E6)
#define word_17F2							(*(const u16*)0x17F2)
#define word_17F4							(*(const u16*)0x17F4)
#define minCoolTempOctanUpdate				(*(const u16*)0x17FC)
#define minKnockLim							(*(const u16*)0x17FE)
#define maxKnockLim							(*(const u16*)0x1800)
#define word_1802							(*(const u16*)0x1802)
#define word_1804							(*(const u16*)0x1804)
#define word_1810							(*(const u16*)0x1810)
#define word_1812							(*(const u16*)0x1812)
#define word_1814							(*(const u16*)0x1814)
#define word_1816							(*(const u16*)0x1816)
#define word_1818							(*(const u16*)0x1818)
#define word_181A							(*(const u16*)0x181A)
#define word_181C							(*(const u16*)0x181C)
#define word_1838							(*(const u16*)0x1838)
#define word_183A							(*(const u16*)0x183A)
#define word_183C							(*(const u16*)0x183C)
#define word_183E							(*(const u16*)0x183E)
#define word_1840							(*(const u16*)0x1840)

#define word_18A6							(*(const u16*)0x18A6)
#define word_18A8							(*(const u16*)0x18A8)
#define word_18AA							(*(const u16*)0x18AA)
#define word_18AC							(*(const u16*)0x18AC)
#define word_18AE							(*(const u16*)0x18AE)

#define word_18B2							(*(const u16*)0x18B2)
#define word_18B4							(*(const u16*)0x18B4)

#define word_1A54							(*(const u16*)0x1A54)

#define word_1C26							(*(const u16*)0x1C26)
#define word_1C28							(*(const u16*)0x1C28)
#define word_1C2A							(*(const u16*)0x1C2A)
#define word_2502							(*(const u16*)0x2502)
#define word_2504							(*(const u16*)0x2504)
#define word_2506							(*(const u16*)0x2506)
#define word_2508							(*(const u16*)0x2508)

#define word_2B64							(*(const u16*)0x2B64)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++













//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define KNOCK_REL_1_FFFF8C4C				(*(u16*)0xFFFF8C4C)
#define word_FFFF9942						(*(u16*)0xFFFF9942)
#define load_ECU_Ignintion					(*(u16*)0xFFFF895A)
#define IGN_FLAG9_FFFF8BB6					(*(u16*)0xFFFF8BB6)
#define octaneNum							(*(u16*)0xFFFF80B6)
#define FLAGS_FFFF8EB0						(*(u16*)0xFFFF8EB0)
#define KNOCK_VAR2_FFFF8C3E					(*(u16*)0xFFFF8C3E)
#define KNOCK_VAR1_bMUTC9_FFFF8C3C			(*(u16*)0xFFFF8C3C)
#define KNOCK_BASE_FFFF8C3A					(*(u16*)0xFFFF8C3A)
#define KNOCK_FLAG2_FFFF887A				(*(u16*)0xFFFF887A)
#define KNOCK_FLAG_FFFF8C34					(*(u16*)0xFFFF8C34)
#define KNOCK_PRECOUNT_MAX_FFFF8C4A			(*(u16*)0xFFFF8C4A)
#define cranking_end_timer_up				(*(u16*)0xFFFF8528)
#define word_FFFF855E						(*(u16*)0xFFFF855E)
#define coolTempCorrectedIgnTiming			(*(u16*)0xFFFF8BC6)
#define timer_Knock							(*(u16*)0xFFFF85B4)
#define BOOSTCHECK2_FFFF8A0E				(*(u16*)0xFFFF8A0E)
#define VEHICLE_SPEED_0_FFFF8A3C			(*(u16*)0xFFFF8A3C)
#define word_FFFF8BF4						(*(u16*)0xFFFF8BF4)
#define word_FFFF8BF6						(*(u16*)0xFFFF8BF6)
#define word_FFFF8BF8						(*(u16*)0xFFFF8BF8)
#define word_FFFF8BFA						(*(u16*)0xFFFF8BFA)
#define word_FFFF8BFC						(*(u16*)0xFFFF8BFC)
#define word_FFFF8BFE						(*(u16*)0xFFFF8BFE)

#define word_FFFF8D9E						(*(u16*)0xFFFF8D9E)
#define word_FFFF8DA0						(*(u16*)0xFFFF8DA0)

#define word_FFFF8C8C						(*(u16*)0xFFFF8C8C)
#define word_FFFF8C8E						(*(u16*)0xFFFF8C8E)
#define word_FFFF8C90						(*(u16*)0xFFFF8C90)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define VOLT9_66C6							((Axis*)0x66C6)
#define RPM8_6570							((Axis*)0x6570)
#define LOAD9_65DC							((Axis*)0x65DC)
#define BAR4_66F6							((Axis*)0x66F6)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define arr_Load_2D_RPM11					((Map3D_B**)0x7AE8)
#define unk048_6354							((Map3D_B*)0x6354)
#define KNOCKLOAD_3A6E						((Map3D_B*)0x3A6E)
#define knockLoad_OctaneUpdate				((Map3D_B*)0x3A80)
#define IGNCOILCHGTIME1_3A3E				((Map3D_B*)0x3A3E)
#define IGNCOILCHGTIME2_3A4E				((Map3D_B*)0x3A4E)
#define IGNCOILCHGTIME3_3A5E				((Map3D_B*)0x3A5E)
#define unk023_59E4							((Map3D_B*)0x59E4)
#define unk028_5FFE							((Map3D_B*)0x5FFE)
#define unk118_59CE							((Map3D_B*)0x59CE)
#define unk033_589E							((Map3D_B*)0x589E)
#define unk032_588E							((Map3D_B*)0x588E)
#define unk115_58AE							((Map3D_B*)0x58AE)
#define unk116_58B8							((Map3D_B*)0x58B8)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Set_Load_ECU_Ignintion()
{
	load_ECU_Ignintion = wMUT1C_ECU_Load;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Check_Ign_16F1A()
{
	if (Query_byte_2D_3D_Table(arr_Load_2D_RPM11) >= load_ECU_Ignintion)
	{
		IGN_FLAG9_FFFF8BB6 |= 0x40;
	}
	else
	{
		IGN_FLAG9_FFFF8BB6 &= ~0x40;
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_Is_Fix_timing_5_degrees()
{
	return (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x1800) == 0x1000;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Check_Fix_timing_5_degrees()
{
	if (IG04_Is_Fix_timing_5_degrees())
	{
		IGN_FLAG9_FFFF8BB6 |= 0x80;
	}
	else
	{
		IGN_FLAG9_FFFF8BB6 &= ~0x80;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Init_knock_sub_16DB2()
{
	u16 t = 0x4000;

	if ((FLAGS_FFFF8EB0 & 0x80) == 0)
	{
		t = 0x1000;
	};

	__disable_irq();

	KNOCK_VAR2_FFFF8C3E = t;
	KNOCK_VAR1_bMUTC9_FFFF8C3C = t;

	KNOCK_BASE_FFFF8C3A = knockAdder_TripleGain;

	KNOCK_FLAG2_FFFF887A &= ~2;

	__enable_irq();

	KNOCK_FLAG_FFFF8C34 &= 0x100;

	Knock_Output_Calc_sub_AC96();

	KNOCK_PRECOUNT_MAX_FFFF8C4A = word_1818;

	KNOCK_REL_1_FFFF8C4C = word_1812;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_1700A()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		IG04_Init_knock_sub_16DB2();

		Timer_Counter_Related_sub_C928();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(IG04_Check_17074)

static bool IG04_Check_17074()
{
	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		Table_Lookup_Axis(CEL8_7100);

		word_FFFF9942 = Table_Lookup_byte_2D_3D(unk048_6354);

		return false;
	};

	if (IGN_FLAG9_FFFF8BB6 & 0x80)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 >= word_17CA)
	{
		return false;
	};

	if ((KNOCK_FLAG_FFFF8C34 & 0x4000) == 0)
	{
		return false;
	};

	if (cranking_end_timer_up >= (word_FFFF9942 << 2))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_1702A()
{
	KNOCK_FLAG_FFFF8C34 |= 0x4000;

	if (IG04_Check_17074())
	{
		KNOCK_FLAG_FFFF8C34 |= 0x40;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x40;

		__disable_irq();

		wMUT26_Knock_Retard = 0;

		__enable_irq();
	};


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_KNOCKLOAD_sub_1718E()
{
	if (wMUT1C_ECU_Load >= Table_Lookup_byte_2D_3D(KNOCKLOAD_3A6E))
	{
		KNOCK_FLAG_FFFF8C34 |= 0x1000;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x1000;
	};

	if ((wMUT71_Sensor_Error & 8) | (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x80) | (KNOCK_FLAG_FFFF8C34 & 0x1000) == 0)
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x2000;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 |= 0x2000;
	};

	if (wMUT71_Sensor_Error & 8)
	{
		return true;
	};

	if ((KNOCK_FLAG_FFFF8C34 & 0x1000) == 0)
	{
		return false;
	};

	if (sub_21E84())
	{
		return true;
	};

	if (R4_Mul_R5_Div_256_round(Sub_R4w_R5w_liml_0(coolTempCorrectedIgnTiming, egrLowOctIgn), 728) >= wMUT26_Knock_Retard)
	{
		return true;
	};

	return false;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_1714C()
{
	if (IG04_KNOCKLOAD_sub_1718E())
	{
		KNOCK_FLAG_FFFF8C34 |= 0x80;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x80;

		__disable_irq();

		word_FFFF855E &= 3;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_1729C()
{
	u16 r13 = (KNOCK_FLAG2_FFFF887A & 2) ? word_1C28 : word_1C2A;

	return (MUT21_RPM_x125div4 >= r13 && wMUT1C_ECU_Load >= word_1C26);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_1726C()
{
	if (IG04_sub_1729C())
	{
		KNOCK_FLAG_FFFF8C34 |= 0x400;
	}
	else
	{
		KNOCK_FLAG_FFFF8C34 &= ~0x400;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_172D6()
{
	KNOCK_PRECOUNT_MAX_FFFF8C4A = word_1818;

	if (KNOCK_FLAG_FFFF8C34 & 0x800)
	{	
		if (MUT21_RPM_x125div4 < word_1816)
		{
			CLR(KNOCK_FLAG_FFFF8C34, 0x800);
		};
	}
	else
	{
		if (MUT21_RPM_x125div4 > word_1814)
		{
			SET(KNOCK_FLAG_FFFF8C34, 0x800);
		};

	};

	if (KNOCK_FLAG_FFFF8C34 & 0x800)
	{	
		KNOCK_REL_1_FFFF8C4C = word_1810;
	}
	else
	{
		KNOCK_REL_1_FFFF8C4C = word_1812;
	};

	if (MUT21_RPM_x125div4 >= word_181C && MUT21_RPM_x125div4 <= word_181A)
	{
		SET(KNOCK_FLAG_FFFF8C34, 0x200);
	}
	else
	{
		CLR(KNOCK_FLAG_FFFF8C34, 0x200);
	};

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_173F2()
{
	if (KNOCK_FLAG_FFFF8C34 & 0x100)
	{
		if (MUT21_RPM_x125div4 <= word_17F2)
		{
			CLR(KNOCK_FLAG_FFFF8C34, 0x100);
		};
	}
	else
	{
		if (MUT21_RPM_x125div4 > word_17F4)
		{
			SET(KNOCK_FLAG_FFFF8C34, 0x100);
		};
	};

	if (KNOCK_FLAG_FFFF8C34 & 0x10)
	{
		if (MUT21_RPM_x125div4 <= word_2504)
		{
			CLR(KNOCK_FLAG_FFFF8C34, 0x10);
		};
	}
	else
	{
		if (MUT21_RPM_x125div4 > word_2502)
		{
			SET(KNOCK_FLAG_FFFF8C34, 0x10);
		};
	};

	if (KNOCK_FLAG_FFFF8C34 & 1)
	{
		if (MUT21_RPM_x125div4 <= word_2508)
		{
			CLR(KNOCK_FLAG_FFFF8C34, 1);
		};
	}
	else
	{
		if (MUT21_RPM_x125div4 > word_2506)
		{
			SET(KNOCK_FLAG_FFFF8C34, 1);
		};
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_Check_octane_update()
{
	if (wMUT10_Coolant_Temperature_Scaled < minCoolTempOctanUpdate)
	{
		return false;
	};

	if (wMUT72_Knock_Present & 1)
	{
		return false;
	};

	if (wMUT71_Sensor_Error & 8)
	{
		return false;
	};

	if ((KNOCK_FLAG_FFFF8C34 & 0x40) == 0)
	{
		return false;
	};

	if (wMUT1C_ECU_Load < Table_Lookup_byte_2D_3D(knockLoad_OctaneUpdate))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_OctaneNumKnockUpdate()
{
	if (IG04_Check_octane_update())
	{
		bool r13 = (wMUT26_Knock_Sum < minKnockLim);

		if (!r13 && wMUT26_Knock_Sum <= maxKnockLim)
		{
			return;
		};

		if (timer_Knock != 0)
		{
			return;
		};

		if (r13)
		{
			octaneNum += 1;

			if (octaneNum == 0) octaneNum -= 1;

			timer_Knock = word_1802;
		}
		else
		{
			if (octaneNum > 0)
			{
				octaneNum -= 1;
			};

			timer_Knock = word_1804;
		};

		octaneNum = Lim16_R4w__R5_R6(octaneNum, 0, 0xFF);

	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Update_MUT27_Octane_Number()
{
	wMUT27_Octane_Number = sub_21E4C(((wMUT71_Sensor_Error & 8 ) || (wMUT72_Knock_Present & 1)) ? 0 : octaneNum);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Update_MUT6F_Knock_Acceleration()
{
	if (RPM_DELTA_FFFF8948 >= 0x80 && (RPM_DELTA_FFFF8948 - 0x80) >= word_17E4)
	{
		__disable_irq();

		wMUT6F_Knock_Acceleration = t1_knock_control_accel_delta_17E6;

		__enable_irq();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_16FA6()
{
	if (wMUTD1_BitMap_FAA & 0x80)
	{
		IG04_sub_1700A();

		IG04_sub_1702A();

		IG04_sub_1714C();

		IG04_sub_1726C();

		IG04_sub_172D6();

		IG04_sub_173F2();

		IG04_OctaneNumKnockUpdate();

		IG04_Update_MUT27_Octane_Number();

		IG04_Update_MUT6F_Knock_Acceleration();
	}
	else
	{
		__disable_irq();

		wMUT26_Knock_Retard = 0;

		wMUT72_Knock_Present &= ~1;

		__enable_irq();

		octaneNum = 0;

		wMUT27_Octane_Number = 0;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void Update_MUT33_Corrected_Timing_Advance()
{

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Update_MUT04_Timing_Advance_Interpolated()
{
	Update_MUT33_Corrected_Timing_Advance();


}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17770()
{
	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma regsave(IG04_sub_18D84)

static void IG04_sub_18D84()
{
	u16 t = word_FFFF8D9E & 7;

	if (t != 0)
	{
		if (t == 1)
		{
			t = 0;
		}
		else if (t == 2)
		{
			t = (word_FFFF8DA0 & 0x60) ? 2 : 1;
		}
		else 
		{
			t = (word_FFFF8DA0 & 0x60) ? 4 : 3;
		};

		u16 t1 = unk119_59DE[t];
		u16 t2 = unk120_59F2[t];
		u16 t3 = unk121_59F8[t];

		Table_Lookup_Axis(LOAD9_65DC);

		t = Table_Lookup_byte_2D_3D((t != 0) ? unk118_59CE : unk033_589E);

		__disable_irq();

		word_FFFF8BF4 = t1;

		word_FFFF8C8E = t2;

		word_FFFF8C8C = t3;

		__enable_irq();

		word_FFFF8C90 = t;
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_178D0()
{
	if ((IGN_FLAG9_FFFF8BB6 & 4) || word_FFFF8BF4 != 0)
	{
		u16 r1;

		if (byte_1077 != 0)
		{
			r1 = word_FFFF8C90;
		}
		else
		{
			Table_Lookup_Axis(LOAD9_65DC);

			r1 = Table_Lookup_byte_2D_3D((MUT21_RPM_x125div4 >= word_2B64) ? unk032_588E : unk033_589E);
		};

		Table_Lookup_Axis(BAR4_66F6);

		u16 r2 = Table_Lookup_byte_2D_3D(unk115_58AE);

		__disable_irq();

		word_FFFF8BFA = Lim_R4_max_FF(MUL_R4w_R5w_DIV_R6w_Round_R0(r1, r2 * Table_Lookup_byte_2D_3D(unk116_58B8), 0x4000));

		__enable_irq();

	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_176B6()
{
	if (wMUT1E_MAF_RESET_FLAG & STALL)
	{
		CLR(IGN_FLAG9_FFFF8BB6, 4);

		word_FFFF8BF8 = 0;

		__disable_irq();

		word_FFFF8BF4 = 0;
		word_FFFF8BF6 = 0;
		word_FFFF8BFA = 0;

		__enable_irq();
	}
	else
	{
		if (byte_1036 != 0 && IG04_sub_17770())
		{
			SET(IGN_FLAG9_FFFF8BB6, 4);

			if (byte_1077 != 0)
			{
				IG04_sub_18D84();
			};

			__disable_irq();

			if (byte_1077 == 0)
			{
				Table_Lookup_Axis(RPM8_6570);

				word_FFFF8BF4 = Table_Lookup_byte_2D_3D(unk023_59E4);

				word_FFFF8BFE = Table_Lookup_byte_2D_3D(unk028_5FFE);
			};

			word_FFFF8BF6 = 0;

			__enable_irq();
		}
		else
		{
			CLR(IGN_FLAG9_FFFF8BB6, 4);
		};
	};

	IG04_sub_178D0();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_179B0()
{
	CLR(IGN_FLAG9_FFFF8BB6, 8);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17A3A()
{
	CLR(IGN_FLAG9_FFFF8BB6, 0x1000);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17A7E()
{
	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17A4E()
{
	if (IG04_sub_17A7E())
	{
		SET(BOOSTCHECK2_FFFF8A0E, 0x1000);
	}
	else
	{
		CLR(BOOSTCHECK2_FFFF8A0E, 0x1000);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17BEC()
{
	if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x80)
	{
		return false;
	};

	if ((RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x20) == 0 && byte_1074 == 0)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 >= word_1838)
	{
		return false;
	};

	if (MUT21_RPM_x125div4 <= word_183A)
	{
		return false;
	};

	if (wMUT10_Coolant_Temperature_Scaled <= word_1840)
	{
		return false;
	};

	if (wMUT2E_Vehicle_Speed_Frequency <= word_1A54)
	{
		return false;
	};

	if (wMUT22 & 4)
	{
		return false;
	};

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL))
	{
		return false;
	};

	if (VEHICLE_SPEED_0_FFFF8A3C >= word_183C)
	{
		return false;
	};

	if (VEHICLE_SPEED_0_FFFF8A3C <= word_183E)
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17B9A()
{
	if ((wMUTD1_BitMap_FAA & 0x400) && IG04_sub_17BEC()) // timing knockdown on light acceleration and less than 3000rpm
	{
		SET(wMUT1E_MAF_RESET_FLAG, 0x8000);
	}
	else
	{
		CLR(wMUT1E_MAF_RESET_FLAG, 0x8000);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static bool IG04_sub_17C9C()
{
	if (IGN_FLAG9_FFFF8BB6 & 2)
	{
		if (MUT21_RPM_x125div4 < word_17B4)
		{
			CLR(IGN_FLAG9_FFFF8BB6, 2);
		};
	}
	else
	{
		if (MUT21_RPM_x125div4 > word_17B2)
		{
			SET(IGN_FLAG9_FFFF8BB6, 2);
		};
	};

	if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x80)
	{
		return false;
	};

	if (IGN_FLAG9_FFFF8BB6 & 2)
	{
		return false;
	};

	if (wMUT22 & 4)
	{
		return false;
	};

	if (wMUT1E_MAF_RESET_FLAG & (CRANKING|STALL|FUEL_CUT))
	{
		return false;
	};

	return true;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17C6E()
{
	if (IG04_sub_17C9C())
	{
		SET(IGN_FLAG9_FFFF8BB6, 0x10);
	}
	else
	{
		CLR(IGN_FLAG9_FFFF8BB6, 0x10);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17D04()
{
	if (byte_1064 != 0 && (wMUT1E_MAF_RESET_FLAG & STALL) == 0)
	{
		u16 r3, r13;

		if (IGN_FLAG9_FFFF8BB6 & 0x2000)
		{
			r3 = word_18A6;
			r13 = word_18AA;
		}
		else
		{
			r3 = word_18A8;
			r13 = word_18AC;
		};

		if (wMUT2E_Vehicle_Speed_Frequency >= word_18B4)
		{
			SET(IGN_FLAG9_FFFF8BB6, 0x4000);
		};

		if (coolantTempScld_COPY_1 < word_18B2 
			&& wMUT10_Coolant_Temperature_Scaled < word_18AE 
			&& (IGN_FLAG9_FFFF8BB6 & 0x4000) == 0 
			&& (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x20) 
			&& MUT21_RPM_x125div4 < r3 
			&& load_ECU_Ignintion < r13)
		{
			SET(IGN_FLAG9_FFFF8BB6, 0x2000);
		}
		else
		{
			CLR(IGN_FLAG9_FFFF8BB6, 0x2000);
		};
	}
	else
	{
		CLR(IGN_FLAG9_FFFF8BB6, 0x6000);
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_17684()
{
	IG04_sub_176B6();

	IG04_sub_179B0();

	IG04_sub_17A3A();

	IG04_sub_17A4E();

	IG04_sub_17B9A();

	IG04_sub_17C6E();

	if (byte_1064 != 0)
	{
		IG04_sub_17D04();
	};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_sub_18B48()
{
	word_FFFF8BCA = Sub_R4w_R5w_liml_0(word_178A + 57, Div_R4_R5_R0(wMUT04_Timing_Advance_Interpolated*256, 90));
//	word_FFFF96C8 = Sub_R4w_R5w_liml_0(word_178A + 57, Div_R4_R5_R0(word_FFFF96CA * 256, 90));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_SetMaxKnockSumControl()
{
	max_Knock_Retard = const_24;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_Ignition_coil_charge_sub_18BD4()
{
	Table_Lookup_Axis(VOLT9_66C6);

	ignCoilTime_3 = Table_Lookup_byte_2D_3D(IGNCOILCHGTIME3_3A5E);

	u16 t = Table_Lookup_byte_2D_3D(IGNCOILCHGTIME1_3A3E) * 16;

	if (crankHT_x_4us_3 <= word_17A0)
	{
		t = Sub_R4w_R5w_liml_0(t, R4_Mul_R5_Div_256_round(word_17A0 - crankHT_x_4us_3, Table_Lookup_byte_2D_3D(IGNCOILCHGTIME2_3A4E)));
	};

	ignCoilTime_1 = t;

	wMUT2D_Ignition_Battery_Trim = t / 16;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void IG04_UpdateTimingMUT()
{
	wMUT06_Timing_Advance = Sub_R4w_R5w_liml_0(81, R4_Mul_R5_Div_256_round(timingAdvScaled, 90));

	wMUT05_Timing_Advance_Scaled = wMUT06_Timing_Advance - 20;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void IG04_root_Update_Ignition()
{
	IG04_Set_Load_ECU_Ignintion();

	IG04_Check_Ign_16F1A();

	IG04_Check_Fix_timing_5_degrees();

	IG04_sub_16FA6();

	IG04_sub_17684();

	BC06_sub_1E2D0();

	IG04_Update_MUT04_Timing_Advance_Interpolated();

	IG04_sub_18B48();

	IG04_SetMaxKnockSumControl();

	IG04_Ignition_coil_charge_sub_18BD4();

	IG04_UpdateTimingMUT();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

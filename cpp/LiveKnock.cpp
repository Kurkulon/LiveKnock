#include "misc.h"


#define DMA3CONFIGread				0x20105
#define DMA3CONFIGwriteindirect		0x10011005
#define DMA3CONFIGwritedirect		0x11005
#define SCR0_CLRTIE_SETTEIE			0x24
#define SCR0_SETRE_CLRTEIE			0x70
#define SCR0_CLRRE_SETTIE			0xa0

//static void TEIEinvade();

const char str[] = __DATE__;

//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//extern "C" byte Lookup_HiIgnMap(Map3D_W** p)
//{
//	u32 t = Table_Lookup_word_2D_3D(p[hiIgnMapIndex&1]);
//
//	t += 0x80;
//
//	return (byte)(t >> 8);
//
////	return ((u32)(Table_Lookup_word_2D_3D(p[hiIgnMapIndex&1])) + 0x80) >> 8;
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

inline u16 Lookup_HiIgnMap(Map3D_B** p)
{
	//u32 t = Table_Lookup_word_2D_3D(p[hiIgnMapIndex&1]);

	//t += 0x80;

	//return (byte)(t >> 8);

//	return ((u32)(Table_Lookup_word_2D_3D(p[hiIgnMapIndex&7])) + 0x80) >> 8;
	return Table_Lookup_byte_2D_3D(p[0]);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(GetLoadCorrectedDeltaTPS)

inline u16 GetLoadCorrectedDeltaTPS()
{
	return load_x2_deltaTPS_corrected = /*IG04_GetLoad_sub_1821E()*/ ECU_Load_x2_FFFF895C + R4_Mul_R5_Div_256_round(abs_Delta_TPS * TPS_Multiplier_Delta, Table_Lookup_byte_2D_3D(table_2D_39D2));

//	return IG04_GetLoadCorrectedDeltaTPS();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(IG04_Update_OctanEgrIgnTiming)

extern "C" u16 IG04_Update_OctanEgrIgnTiming()
{
	register u16 loIgn, /*ignAdd,*/ hiIgn, octIgn, ign; 

	wMUTB4_lookup_value = GetLoadCorrectedDeltaTPS();

	Table_Lookup_Axis(RPM21_6788_IGN);

	Table_Lookup_Axis(LOAD12_67BC_IGN);

	loIgn = Query_byte_2D_3D_Table(LowIgn_7C68);

	if (ZERO_8_IGNITION_FLAGS & 8)
	{
		egrLowOctIgn = Add_R4w_R5w_Lim_FFFF(loIgn, Table_Lookup_byte_2D_3D(HIOCTIGNEGR_38CA));
	}
	else
	{
		egrLowOctIgn = loIgn;
	};

	if (wMUTD1_BitMap_FAA & 0x80)
	{
		hiIgn = Table_Lookup_byte_2D_3D(HighIgn_7C48[hiIgnMapIndex&7]);//(Table_Lookup_word_2D_3D(((void**)HighIgn_7C48)[hiIgnMapIndex&7]) + 0x80) >> 8;
		//hiIgn = Query_byte_2D_3D_Table(HighIgn_7C48);

		if (ZERO_8_IGNITION_FLAGS & 8)
		{
			egrHighOctIgn = Add_R4w_R5w_Lim_FFFF(hiIgn, Table_Lookup_byte_2D_3D(HIOCTIGNEGR_38CA));
		}
		else
		{
			egrHighOctIgn = hiIgn;
		};

		octIgn = interpolate_r4_r5_r6(egrHighOctIgn, egrLowOctIgn, wMUT27_Octane_Number);

		ign = hiIgn;

	}
	else
	{
		octIgn = egrLowOctIgn;

		ign = loIgn;
	};

	octanEgrIgnTiming = octIgn;

	ignition_FFFF8BC4 = Lim_R4_max_FF(Sub_R4w_R5w_liml_0(ign + Query_byte_2D_3D_Table(LOWOCTIGNEGR_7AC8), 128));

	return octanEgrIgnTiming;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FU03_HI_LO_Octan)

extern "C" void FU03_HI_LO_Octan()
{
//	u16 r1, r13;

	wMUTB4_lookup_value = FU03_sub_142DC();

	Table_Lookup_Axis(RPM14_6746);

	Table_Lookup_Axis(LOAD9_676C);

	AFR_OctanInt = interpolate_r4_r5_r6(Query_byte_2D_3D_Table(HIGHOKTF_7A88), Query_byte_2D_3D_Table(LowOctFMp_7AA8), wMUT27_Octane_Number);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(FU03_VE_map_sub_14620)

extern "C" void FU03_VE_map_sub_14620()
{
	Table_Lookup_Axis(RPM19_6CEE);

	Table_Lookup_Axis(LOAD11_6D1E);

	if ((bMUTD3_BitMap4_FCA_Store_FFFF89D8 & 0x200) || (EGRONOFF_103D == 0))
	{

	};

	Map3D_B *p;
	
	if (ZERO_8_IGNITION_FLAGS & 8)
	{
		if (RT_AIRCON_DRIVE_NEUTRAL_F20_FLAG1_FFFF8888 & 0x20)
		{
			p = VE2Map_310E;
		}
		else
		{
			p = VE3Map_31EA;
		};
	}
	else
	{
		p = VE1Map_3032;
	};

	wMUT31_Volumetric_Efficiency = Table_Lookup_byte_2D_3D(veMapArray[veMapIndex&7]);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma noregsave(LiveKnock)

extern "C" void LiveKnock()
{
	if (__DEADloc != 0xDEAD)
	{
		__DEADloc = 0xDEAD;

		hiIgnMapIndex = 0;	
		hiFuelMapIndex = 0;	
		veMapIndex = 0;		
	};

	//IG04_Update_OctanEgrIgnTiming();

	//FU03_HI_LO_Octan();

	//FU03_VE_map_sub_14620();

	//static i16 timing;

	//u16 ind = (byte)axis_ig_RPM + (byte)axis_ig_LOAD*25;

	//i16 *p = &ramHiIgnMap.data[ind];

	//timing = *p;

	//if ((_byte_FFFF8400 & 1) && (KNOCK_FLAG_FFFF8C34 & 0x40) && ((wMUT72_Knock_Present & 1) == 0) && (byte)axis_ig_LOAD > 10 && ind < 25*30)
	//{
	//	const u16 knock = wMUT26_Knock_Sum;

	//	if (knock > 5)
	//	{
	//		u16 dt = knock >> 1;

	//		i16 t = timing - dt;

	//		*p = (t < -20*256) ? -20*256 : t;
	//	}
	//	else 
	//	{
	//		if (knock < 3 &&  timing < 40*256)
	//		{
	//			*p = timing += 1;
	//		};
	//	};
	//};
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*

void CRANK75_Knock_sub_23F8C()
{
	if ((wMUTD1_BitMap2 & 0x80) == 0) // 0x80 - Enable High Oct Ign Map Lookup and other
	{
		return;
	};

	Get_ADC_Knock();

	r1 = wMUT30_Knock_Voltage;

	if (r1 > 100)
	{
		r1 = (r1-100)*435/256+55;
	}
	else
	{
		if (r1 > 92)
		{
			r1 = (r1-92)*0xC0/256+49;
		}
		else
		{
			r1 = r1 * 136 / 256;
		};
	};

	if (r1 >= 255)
	{
		r1 = 255;
	};

	r2 = wMUT6A_Knock_ADC_Processed;

	wMUT6A_Knock_ADC_Processed = r1;

	r1 = r2;

	if ((KNOCK_FLAG_FFFF8C34 & 0x400) // 0x400 - (MUT21_RPM_x125div4 >= word_1C28(2000))&&(wMUT1C_ECU_Load >= word_1C26(55kPa))
		&& (KNOCK_FLAG1_FFFF8C36 & 1) == 0)
	{
		if (wMUT6A_Knock_ADC_Processed >= r1)
		{
			r13 = wMUT6A_Knock_ADC_Processed - r1;
		}
		else
		{
			r13 = r1 -= wMUT6A_Knock_ADC_Processed;
		};

		if (KNOCK_FLAG2_FFFF887A & 2)
		{
			r3 = t1_knock_signal_change_check_1C2E;
		}
		else
		{
			r3 = t1_knock_signal_change_check_1C2C;
		};

		if (r13 >= r3)
		{
			wMUT72_Knock_Present &= ~1;

			wMUT6E_Knock_Dynamics = 0;
		}
		else
		{
			if (wMUT6E_Knock_Dynamics < 0xFFFFFFFF)
			{
				wMUT6E_Knock_Dynamics += 1;
			};

			if (wMUT6E_Knock_Dynamics > word_1C30)
			{
				wMUT72_Knock_Present |= 1;

				wMUT6E_Knock_Dynamics = word_1C30;
			};
		};

		wMUT6D_Knock_Change = r13;

	} // if (KNOCK_FLAG_FFFF8C34 & 0x400)
	else
	{
		wMUT6E_Knock_Dynamics = 0;

		wMUT6D_Knock_Change = 0;
	};

	Timer_Counter_Related_sub_C928();

	KNOCK_BASE_MINUS_ADC_FFFF8C40 = Sub_R4w_R5w_liml_0(wMUT6A_Knock_ADC_Processed, KNOCK_BASE_FFFF8C3A);




	if ((KNOCK_FLAG_FFFF8C34 & 0x40) == 0) // 0x40 - enabled knock retard; IG04_Check_17074()
	{
		wMUT26_Knock_Sum = 0;

		CRANK75_Knock_sub_24AC0();

		r1 = 0;
	}
	else if ((wMUT72_Knock_Present & 1) // 1 - ? Knock sensor fault; (wMUT6E_Knock_Dynamics >= word_1C30)
	{

		if (KNOCK_FLAG_FFFF8C34 & 0x80)
		{
			wMUT26_Knock_Retard = t1_knock_control_ign_retard_faulty_sensor_17E8
		}
		else
		{
			wMUT26_Knock_Retard = t1_knock_control_ign_retard_faulty_sensor_17EA
		};

		CRANK75_Knock_sub_24AC0();

		r1 = 0;
	}
	else
	{
		// loc_2417A:                                                                                     

		if (KNOCK_BASE_MINUS_ADC_FFFF8C40 != 0)
		{
			if (KNOCK_FLAG_FFFF8C34 & 0x80)
			{
				r1 = t1_knock_control_?_17CC;
			}
			else
			{
				r1 = t1_knock_control_?_17CE;
			};

			r1 = 1 + MUL_R4w_R5w_DIV_R6w_Round_R0(KNOCK_BASE_MINUS_ADC_FFFF8C40, r1, KNOCK_BASE_FFFF8C3A << 3);

			if (r1 >= 0xFF)
			{
				r1 = 0xFF;
			};
		}
		else
		{
			r1 = 0;
		}; //  if (KNOCK_BASE_MINUS_ADC_FFFF8C40 != 0)


		// loc_2421E:                                                                                      ; CODE XREF: CRANK75_Knock_sub_23F8C+230j

		if (KNOCK_FLAG_FFFF8C34 & 0x200)
		{
			bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E += 1;

			if (bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E >= KNOCK_PRECOUNT_MAX_FFFF8C4A)
			{
				bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E = KNOCK_PRECOUNT_MAX_FFFF8C4A;

				bMUTCB_KNOCK_U_FFF8C54 = 0x8000;
			};

			bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 += 1;

			if (bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 >= KNOCK_PRECOUNT_MAX_FFFF8C4A)
			{
				bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 = KNOCK_PRECOUNT_MAX_FFFF8C4A;

				bMUTCC_KNOCK_UB_FFFF8C56 = 0x8000;
			};

			KNOCK_REL_compare_to_10_FFFF8C5A <<= 1;


			if (r1 >= t1_unk_180E)
			{
				if (r1 <= KNOCK_REL_1_FFFF8C4C)
				{
					KNOCK_REL_compare_to_10_FFFF8C5A |= 1;

					if (bMUTCB_KNOCK_U_FFF8C54 == strokeNumber)
					{
						bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E = 0;

						r1 = 0;
					}
					else
					{
						if (bMUTCC_KNOCK_UB_FFFF8C56 == strokeNumber)
						{
							bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 = 0;

							r1 = 0;
						}
						else
						{
							if (KNOCK_PRECOUNT_1033 == 0 || (KNOCK_REL_compare_to_10_FFFF8C5A & 0x10))
							{
								if (r8 == bMUTCB_KNOCK_U_FFF8C54)
								{
									bMUTCB_KNOCK_U_FFF8C54 = strokeNumber;

									bMUTCD_KNOCK_PRECOUNT_1_FFFF8C4E = 0;

									if (KNOCK_PRECOUNT_1033 != 0)

									{
										r1 = 0;
									};
								}
								else
								{
									if (bMUTCC_KNOCK_UB_FFFF8C56 == r8)
									{
										bMUTCC_KNOCK_UB_FFFF8C56 = strokeNumber;

										bMUTCE_KNOCK_PRECOUNT_2_FFFF8C50 = 0;

										if (KNOCK_PRECOUNT_1033 != 0)
										{
											r1 = 0;
										};
									};
								};
							};
						};
					};
				};
			};
		}
		else  // if (KNOCK_FLAG_FFFF8C34 & 0x200)
		{
			CRANK75_Knock_sub_24AC0();
		}; //     if (KNOCK_FLAG_FFFF8C34 & 0x200)

		// loc_2432C:                                                                                      ; CODE XREF: CRANK75_Knock_sub_23F8C+2F8j

		max_Retard = max_Knock_Retard;

		if (KNOCK_FLAG_FFFF8C34 & 0x80)
		{
			r13 = t1_knock_control_?_17D0;
		}
		else
		{
			r13 = t1_knock_control_?_17D2;
		};

		if (r1 > r13)
		{
			r1 = r13;
		};

		r2 = wMUT26_Knock_Retard + r1;

		if (r2 < max_Retard)
		{
			wMUT26_Knock_Retard = r2;
		}
		else
		{
			wMUT26_Knock_Retard = max_Retard;
		};

	};



	// loc_243A8:                                                                                      ; CODE XREF: CRANK75_Knock_sub_23F8C+1EAj

	wMUT6C_Knock_Sum_Addition = r1;

	bMUTCA_KNOCK_VAR22_FFFF9988 = KNOCK_VAR2_FFFF8C3E;

	wMUT6B_Knock_Base = KNOCK_BASE_FFFF8C3A;

	if (wMUT6A_Knock_ADC_Processed >= (KNOCK_VAR2_FFFF8C3E>>8))
	{
		if (KNOCK_DYNAMICS2_FFFF8C48 < 0xFFFF)
		{
			KNOCK_DYNAMICS2_FFFF8C48 += 1;
		};
	}
	else
	{
		KNOCK_DYNAMICS2_FFFF8C48 = 0;
	};

	r2 = 0x20;

	if (wMUT6F_Knock_Acceleration != 0)
	{
		r2 = 0xF000;
		r1 = wMUT6A_Knock_ADC_Processed << 4;
	}
	else 
	{
		if ((KNOCK_BASE_MINUS_ADC_FFFF8C40 != 0)
		{
			r2 = 0x100;
		}
		else if (KNOCK_DYNAMICS2_FFFF8C48 >= t1_knock_dynamics_1820)
		{
			r2 = 0x10;
		}
		else if ((KNOCK_VAR2_FFFF8C3E >> 8) != 0) && ((KNOCK_VAR2_FFFF8C3E >> 8) * t1_knock_multiplier_1822 <= (wMUT6A_Knock_ADC_Processed << 3)))
		{
			r2 = 0x100;
		};

		if (r2 == 0x10)
		{
			r2 = 0xF000;
			r1 = wMUT6A_Knock_ADC_Processed << 4;
		}
		else if (r2 == 0x20)
		{
			r2 = 0xF800;

			r1 = wMUT6A_Knock_ADC_Processed << 3;
		}
		else
		{
			r2 = 0xFF00;

			r1 = wMUT6A_Knock_ADC_Processed * 1;
		};
	};

	//++++++++++++++++++++++++++++++++++++++++++++++

	r1 <<= 16;

	KNOCK_VAR1_bMUTC9_FFFF8C3C = R4_Complex_Into_R0_sub_898(Add_R4_R5_Lim_FFFFFFFF(KNOCK_VAR1_bMUTC9_FFFF8C3C * r2, r1));

	if ((KNOCK_FLAG2_FFFF887A & 2) == 0)
	{
		if (KNOCK_BASE_FFFF8C3A >= t1_knock_base_compare_17EE)
		{
			KNOCK_FLAG1_FFFF8C36 |= 0x10;

			KNOCK_RPM_FFFF8C74 = MUT21_RPM_x125div4;
		};
	}
	else
	{
		if (MUT21_RPM_x125div4 < Sub_R4w_R5w_liml_0(KNOCK_RPM_FFFF8C74, t1_knock_rpm_17F0) || KNOCK_BASE_FFFF8C3A < t1_knock_base_compare_17EC)
		{
			KNOCK_FLAG1_FFFF8C36 &= ~0x10;
		};
	};

	//++++++++++++++++++++++++++++++++++++++++++++++

	KNOCK_FLAG1_FFFF8C36 &= ~1;

	if (((KNOCK_FLAG1_FFFF8C36 & 0x10) && (FLAGS_FFFF8EB0 & 0x80) == 0) || ((FLAGS_FFFF8EB0 & 0x80) && (KNOCK_FLAG_FFFF8C34 & 0x100)))
	{
		if ((KNOCK_FLAG2_FFFF887A & 2) == 0)
		{
			KNOCK_VAR1_bMUTC9_FFFF8C3C /= 3;

			KNOCK_VAR2_FFFF8C3E /= 3;

			KNOCK_BASE_FFFF8C3A = Lim16_R4w__R5_R6(KNOCK_BASE_FFFF8C3A/3, 1, 0xFF);

			KNOCK_FLAG1_FFFF8C36 |= 1;
		};

		KNOCK_FLAG2_FFFF887A |= 2;
	}
	else
	{
		if ((KNOCK_FLAG2_FFFF887A & 2) != 0)
		{
			KNOCK_VAR1_bMUTC9_FFFF8C3C *= 3;

			KNOCK_VAR2_FFFF8C3E *= 3;

			KNOCK_BASE_FFFF8C3A = Lim16_R4w__R5_R6(KNOCK_BASE_FFFF8C3A*3, 1, 0xFF);

			KNOCK_FLAG1_FFFF8C36 |= 1;
		};

		KNOCK_FLAG2_FFFF887A &= ~2;
	};

}
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma interrupt RXI0
//
//extern "C" void RXI0()
//{
//	__disable_irq();
//
//	byte t = RDR0;
//
//	if (t >= 0xE0 && t <= 0xE2 && (bit7allowslogging & 0x80) && (mutorobd & 0x80) && (receive_transmit_status_bits & 0x80) == 0)
//	{
//		DMAOPFLAG2 = t;
//		mut_timeout = 0;
//		CHCR3 &= ~3;
//		
//		SAR3 = &RDR0;
//		DAR3 = &DMAaddress;
//		DMATCR3 = 6;
//
//		DMAOPFLAG = 0x37;
//
//		SSR0 &= 0x87;
//
//		CHCR3 = DMA3CONFIGread;
//
//		__enable_irq();
//	}
//	else
//	{
//		__enable_irq();
//
//		serialreceivewithoutdma();
//	};
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//inline void TEIEinvade()
//{
//	DMAOPFLAG = 0;
//	SCR0 = SCR0_SETRE_CLRTEIE;
//	SSR0 &= 0x87;
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma interrupt DMAEND
//
//extern "C" void DMAEND()
//{
//	__disable_irq();
//
//	CHCR3 &= ~3;
//
//	if (DMAOPFLAG2 == 1)
//	{
//		if (SSR0 & 4)
//		{
//			TEIEinvade();
//		}
//		else
//		{
//			SCR0 = SCR0_CLRTIE_SETTEIE;
//		};
//	}
//	else if (DMAOPFLAG2 == 0xE0)
//	{
//		DMAOPFLAG2 = 1;
//		SAR3 = DMAaddress;
//		DAR3 = &TDR0;
//		DMATCR3 = DMAlength;
//		DMAOPFLAG = 0x37;
//		SCR0 = SCR0_CLRRE_SETTIE;
//		CHCR3 = DMA3CONFIGwriteindirect;
//	}
//	else if (DMAOPFLAG2 == 0xE1)
//	{
//		DMAOPFLAG2 = 1;
//		SAR3 = DMAaddress;
//		DAR3 = &TDR0;
//		DMATCR3 = DMAlength;
//		DMAOPFLAG = 0x37;
//		SCR0 = SCR0_CLRRE_SETTIE;
//		CHCR3 = DMA3CONFIGwritedirect;
//	}
//	else if (DMAOPFLAG2 == 0xE2)
//	{
//		DMAOPFLAG2 = 2;
//		SAR3 = &RDR0;;
//		DAR3 = DMAaddress;
//		DMATCR3 = DMAlength;
//		DMAOPFLAG = 0x37;
//		SSR0 &= 0x87;
//		CHCR3 = DMA3CONFIGread;
//	}
//	else
//	{
//		TEIEinvade();
//	};
//
//	__enable_irq();
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//#pragma interrupt TEIE
//
//extern "C" void TEIE()
//{
//	__disable_irq();
//
//	TEIEinvade();
//
//	__enable_irq();
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//void LiveKnock()
//{
//	static u16 maxRetard;
//	static u16 prevInd;
//	static u16 count_inc;
//
//	static i8 timing;
//
//	u16 ind = (byte)__axis_res_RPM25 + (byte)__axis_res_LOAD30*25;
//
//	i8 *p = &altHiIgnMap.data[ind];
//
//	if (prevInd != ind)
//	{
//		timing = *p;
//
//		//count_inc = 0;
//
//		//maxRetard = 0;
//	};
//
//	if ((__byte_FFFF8400 & 1) && (KNOCK_FLAG_FFFF8C34 & 0x40) && ((wMUT72_Knock_Present & 1) == 0) && (byte)__axis_res_LOAD30 > 10 && ind < 25*30)
//	{
//		const u16 knock = wMUT26_Knock_Sum;
//
//		if (knock > maxRetard)
//		{
//			maxRetard = knock;
//		};
//
//		if (maxRetard > 5 && count_inc >= 10)
//		{
//			u16 dt = 1 + (knock >> 4);
//
//			i8 t = timing - dt;
//
//			*p = (t < -20) ? -20 : t;
//			
//			count_inc = 0;
//
//			maxRetard = 0;
//		}
//		else if (count_inc >= 30)
//		{
//			if (maxRetard < 3 &&  timing < 40)
//			{
//				*p = timing += 1;
//			};
//			
//			count_inc = 0;
//
//			maxRetard = 0;
//		};
//
//		count_inc += 1;
//	}
//	else
//	{
//		maxRetard = 0;
//		
//		count_inc = 0;
//	};
//
//	prevInd = ind;
//
//	sub_A98A();
//}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

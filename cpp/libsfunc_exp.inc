
	.IMPORT __disable_irq, __enable_irq, Set_Intterupt_Mask, Add_Lim_FFFF, Add_R4w_R5w, Add_Lim_FFFFFFFF
	.IMPORT memsetz, mem_decr, mem_incr, Lim_FF, Lim_FFFF, Lim16, Lim32, Mul_Div, Mul_DW_Div, Mul_Div_R 
	.IMPORT Mul_R4_R5w_Div_R6w_Round_R0, Mul_R4_R5_Div_128_Into_R0, Mul_Fix7_R, Mul32_Fix7, Mul_R4_R5w_Div_128_Round_R0
	.IMPORT Mul_Fix8_Lim_FFFF, Mul32_Fix8, Mul_Fix8_R, Mul_R4_R5w_Div_256_Round_R0, SHLR8
	.IMPORT R4_Div_65536_ZeroExtendWord_Into_R0_sub_86A, R4_Mult_256_ZeroExtendWord_Into_R0_sub_870, Mult_R4_65536
	.IMPORT Div_256_R, Div_65536_R, SwapBytes16, Div_R4_R5__R0, Div_DW, Div_WW, DIV_DW_R, Interpolate_256, sub_AE0
	.IMPORT interpolate_r4_r5_r6, sub_B68, Table_Lookup_byte_2D_3D, Table_Lookup_Axis, Interpolate, GET_FROM_MASSIVE_byte
	.IMPORT GET_FROM_MASSIVE_word, Query_byte_2D_3D_Table, GET_LOC_DIM_sub_DF6, Table_Lookup_word_2D_3D, sub_EA6, sub_EBC, Mul_Lim_FFFF, Mul16, Mul32_lim, Sub_Lim_0

	.IMPORT ___disable_irq, ___enable_irq, _Set_Intterupt_Mask, _Add_Lim_FFFF, _Add_R4w_R5w, _Add_Lim_FFFFFFFF
	.IMPORT _memsetz, _mem_decr, _mem_incr, _Lim_FF, _Lim_FFFF, _Lim16, _Lim32, _Mul_Div, _Mul_DW_Div, _Mul_Div_R
	.IMPORT _Mul_R4_R5w_Div_R6w_Round_R0, _Mul_R4_R5_Div_128_Into_R0, _Mul_Fix7_R, _Mul32_Fix7, _Mul_R4_R5w_Div_128_Round_R0
	.IMPORT _Mul_Fix8_Lim_FFFF, _Mul32_Fix8, _Mul_Fix8_R, _Mul_R4_R5w_Div_256_Round_R0, _SHLR8
	.IMPORT _R4_Div_65536_ZeroExtendWord_Into_R0_sub_86A, _R4_Mult_256_ZeroExtendWord_Into_R0_sub_870, _Mult_R4_65536
	.IMPORT _Div_256_R, _Div_65536_R, _SwapBytes16, _Div_R4_R5__R0, _Div_DW, _Div_WW, _DIV_DW_R, _Interpolate_256, _sub_AE0
	.IMPORT _interpolate_r4_r5_r6, _sub_B68, _Table_Lookup_byte_2D_3D, _Table_Lookup_Axis, _Interpolate, _GET_FROM_MASSIVE_byte
	.IMPORT _GET_FROM_MASSIVE_word, _Query_byte_2D_3D_Table, _GET_LOC_DIM_sub_DF6, _Table_Lookup_word_2D_3D, _sub_EA6, _sub_EBC, _Mul_Lim_FFFF, _Mul16, _Mul32_lim, _Sub_Lim_0

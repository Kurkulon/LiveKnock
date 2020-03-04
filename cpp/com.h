#ifndef COM_H__03_03_2020__16_43
#define COM_H__03_03_2020__16_43

#include "types.h"

#ifdef __MVS
#define DEF_COM
#endif

extern void sub_206A4							();
extern void COM_MUT_sub_207F0					();
extern void MUT3_sub_20910						();
extern void COM_MUT_COMMANDS_COMPARE_sub_20968	();
extern void COM_MUT_sub_20DD4					();
extern void COM_MUT_Cancel_PrevActive_cmd		();
extern void COM_MUT_Connect_20E4A				();
extern void OBD10_sub_21314						();
extern void OBD10_sub_21386						();
extern void COM_root_sub_21564					();
extern void MUT2B_800Hz_root					();
extern void CRANK5_sub_21A04					();

extern u16 sub_21A52                      		(u16 v);
extern u16 sub_21A72                      		(u16 v);
extern u16 sub_21AAA                      		(u16 v);
extern u16 sub_21ACC                      		(u16 v);
extern u16 sub_21B50                      		(u16 v);
extern u16 sub_21BC4                      		(u16 v);
extern u16 sub_21C0C                      		(u16 v);
extern u16 F500_sub_21C80                 		();
extern u16 sub_21CA8                      		(u16 v);
extern u16 sub_21D6C                      		(u16 v);
extern u16 sub_21D9C                      		(u16 v);
extern u16 IG04_sub_21DCE                 		(u16 v);
extern u16 sub_21E14                      		(u16 v);
extern u16 sub_21E2A                      		(u16 v);
extern u16 sub_21E4C                      		(u16 v);
extern u16 sub_21E84                      		(u16 v);
extern u16 sub_21E9C                      		(u16 v);
extern u16 sub_21EB4                      		(u16 v);
extern u16 sub_21ECC                      		(u16 v);
extern u16 sub_21EE4                      		(u16 v);
extern u16 sub_21EF8                      		(u16 v);
extern u16 sub_21F0C                      		(u16 v);
extern u16 sub_21F4E                      		(u16 v);
extern u16 sub_21F66                      		(u16 v);
extern u16 sub_21F7E                      		(u16 v);
extern u16 sub_21F96                      		(u16 v);
extern u16 sub_21FB8                      		(u16 v);
extern u16 Barometric_Correction_sub_22084		(u16 v);
extern u16 sub_220A2                      		(u16 v);
extern u16 sub_220B4                      		(u16 v);

#endif // COM_H__03_03_2020__16_43


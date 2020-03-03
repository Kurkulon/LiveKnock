##################################################################################################

variant = MAIN

STACK_REPLACE = 1
GNU_HARDWARE = 0
CODE_ASM = 0

##################################################################################################

!ifndef version
version = Release
!endif

##################################################################################################

curdir = $+ $(%cdrive):$(%cwd) $-
cppdir = cpp
objdir = $(version)
hdir = $(cppdir)
#libdir = ..\LowLevel\libs
#bindir = $(%ARMCC50BIN)

gnu_compiler_options =  -fno-show-column -m2 -c -fno-diagnostics-show-option -Os

!ifeq version Debug

# -SPeed 

debug_compiler_options =  -OPtimize=1 -SIze -SHIft=Inline
debug_linker_options = 
lbgsh_options = 
libsuffix=d
define_options = DEF_SIMULATION="1"

!else

debug_compiler_options = -OPtimize=1 -SIze -SHIft=Inline
debug_linker_options = 
lbgsh_options = 
libsuffix=r
define_options = DEF_RELEASE="1"

!endif

##################################################################################################

var_opt = DEF_IGNMAP16="1",DEF_VEMAP16="1"
var_obj = 

!ifeq variant MAIN

var_opt = $(var_opt),DEF_IGNITION_HOOKS="1",DEF_FU03_HOOKS="1",DEF_IDLE_HOOKS="1"
var_obj = $(var_obj) Hooks.o

!else ifeq variant F500

var_opt = $(var_opt),DEF_F500="1",DEF_IGNITION_HOOKS="1",DEF_FU03_HOOKS="1",DEF_IDLE_HOOKS="1"
var_obj = $(var_obj) F500.o Hooks.o

!else ifeq variant ML02

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_IGNITION_HOOKS="1",DEF_FU03_HOOKS="1",DEF_IDLE_HOOKS="1"
var_obj = $(var_obj) F500.o Hooks.o ML02.o

!else ifeq variant FU03

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_FU03="1",DEF_IGNITION_HOOKS="1",DEF_IDLE_HOOKS="1"
var_obj = $(var_obj) F500.o Hooks.o ML02.o FU03.o

!else ifeq variant IGNITION

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_FU03="1",DEF_IGNITION="1",DEF_IDLE_HOOKS="1"
var_obj = $(var_obj) F500.o Hooks.o ML02.o FU03.o ignition.o

!else ifeq variant IDLE

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_FU03="1",DEF_IGNITION="1",DEF_IDLE="1"
var_obj = $(var_obj) F500.o ML02.o FU03.o ignition.o idle.o

!else ifeq variant BC06

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_FU03="1",DEF_IGNITION="1",DEF_IDLE="1",DEF_BC06="1"
var_obj = $(var_obj) F500.o ML02.o FU03.o ignition.o idle.o bc06.o

!else ifeq variant CRANK

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_FU03="1",DEF_IGNITION="1",DEF_IDLE="1",DEF_BC06="1",DEF_CRANK="1"
var_obj = $(var_obj) F500.o ML02.o FU03.o ignition.o idle.o bc06.o

!else ifeq variant HUGE

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_FU03="1",DEF_IGNITION="1",DEF_IDLE="1",DEF_BC06="1",DEF_CRANK="1",DEF_HUGE="1"
var_obj = $(var_obj) F500.o ML02.o FU03.o ignition.o idle.o bc06.o

!else ifeq variant HARDWARE

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_FU03="1",DEF_IGNITION="1",DEF_IDLE="1",DEF_BC06="1",DEF_CRANK="1",DEF_HUGE="1",DEF_HARDWARE="1"
var_obj = $(var_obj) F500.o ML02.o FU03.o ignition.o idle.o bc06.o

!else ifeq variant EF07

var_opt = $(var_opt),DEF_F500="1",DEF_ML02="1",DEF_FU03="1",DEF_IGNITION="1",DEF_IDLE="1",DEF_BC06="1",DEF_CRANK="1",DEF_HUGE="1",DEF_HARDWARE="1",DEF_EF07="1"
var_obj = $(var_obj) F500.o ML02.o FU03.o ignition.o idle.o bc06.o EF07.o

!endif

!ifeq STACK_REPLACE 1

#var_opt = $(var_opt),DEF_STACK_REPLACE="1"
var_obj = $(var_obj) Reset_init.o

!endif

##################################################################################################

libname = $(objdir)\sh2_$(libsuffix).lib

##################################################################################################

.ERASE
.EXTENSIONS:
.EXTENSIONS: .o .s .cpp .h .asm 

##################################################################################################

.cpp:	$(cppdir)
.asm:	$(cppdir)
.o:	$(objdir)
.h:	$(hdir)
.s:	$(objdir)

##################################################################################################

delimiter = _____________________________________________________________________

##################################################################################################

.BEFORE
	@if NOT EXIST $(objdir) @md $(objdir) >nul
	@echo -Head=RUNTIME -OUTput=$(libname) –CPu=SH2 –SPeed >$(objdir)\lbgsh.sub
	@if NOT EXIST $(libname) @lbgsh -sub=$(objdir)\lbgsh.sub
	@call echo Building $(version) version ...
	@call buildnum.bat
	@echo $(delimiter)	

################################################################################################## -ENAble_register

compiler_options = $(debug_compiler_options) -NOLOGO -CPu=sh2 -RTnext  -macsave=0 -ALIAS=ANSI -DEFIne=$(define_options),$(var_opt)

##################################################################################################

asm_options = -NOLOGO -CPu=sh2 -DEFIne=$(define_options),$(var_opt)

##################################################################################################

link_options = -NOLOGO -FOrm=Binary -LISt -SHow=SY -LIBrary=$(libname) 
  
##################################################################################################

$(objdir)\9327_mod.hex : $(objdir)\LiveKnock.abs $(objdir)\stock.abs  
	@echo Patch ROM...
	@copy /Y bin\orig_93270019.hex $^@
	@bin\elfpatch $^@ $[@
	@echo $(delimiter)	

##################################################################################################

$(objdir)\LiveKnock.abs : LiveMap.o AltMaps.o LiveKnock.o com_hal.o com.o obd.o immo.o misfire.o crank.o hardware.o huge.o f500.o ml02.o main.o $(var_obj)
	@echo Linking $^@ ...
	@optlnk	-NOLOGO -LISt -SHow=SY -FOrm=Absolute -start=P_main/EB04,P_Hooks/2CC0,P_HARDWARE/9D18,P_CRANK/230F0,P_HUGE/266DC,P/39000,B/FFFF8480 -LIBrary=$(libname) -OUtput="$^@" $<
	@echo $(delimiter)	

##################################################################################################

!ifeq CODE_ASM 1

.cpp.s:
	@echo Compiling asm $[. ...
	@shcpp $(compiler_options) -code=asmcode -SHow=SOurce -List="$(objdir)\$^&.lst" -OBjectfile="$(objdir)\$^." $[@
	@echo $(delimiter)	

##################################################################################################

.s.o: 
	@echo Compiling $[. ...
	@asmsh $(asm_options)  -OBject="$(objdir)\$^." $[@
	@echo $(delimiter)	

!else

##################################################################################################

.cpp.o:
	@echo Compiling $[. ...
	@shcpp $(compiler_options) -Listfile="$(objdir)\$^&.lst" -SHow=SOurce -OBjectfile="$(objdir)\$^." $[@
	@echo $(delimiter)	

!endif

##################################################################################################

.asm.o:
	@echo Compiling $[. ...
	@asmsh $(asm_options) -List="$(objdir)\$^&.lst" -OBject="$(objdir)\$^." $[@
	@echo $(delimiter)	

##################################################################################################

$(objdir)\stock.abs : F500.o ML02.o FU03.o Ignition.o crank.o idle.o  BC06.o EF07.o huge.o LibsFunc.o  Reset_init.o  atu02_ici0A.o c_9D18.o com.o adc.o #LiveMap.o AltMaps.o Hooks.o LiveKnock.o
	@echo Linking $^@ ...
	@copy /Y $[@ $^@
	@rem optlnk	-NOLOGO -LISt -SHow=SY -FOrm=Binary -start=P_main/EB04,P_Hooks/2CC0,P/39000,B/FFFF8480,HWREG/FFFFE400,P_Ignition/16E90,P_idle/18F80,P_crank/23244,P_FU03/13AB8 -LIBrary=$(libname) -OUtput="$^@" $<
	@echo $(delimiter)	

##################################################################################################

# -map="$(objdir)\$^&.bls"

$(objdir)\F500.abs : F500.o # ext_ram_vars.o
	@echo Linking $^@ ...
	@optlnk	-NOLOGO -LISt -SHow=SY -FOrm=Absolute -start=P/F500,B_EXT_RAM_VARS/FFFF8000 -LIBrary=$(libname) -OUtput="$^@" $< 
	@echo $(delimiter)	

##################################################################################################



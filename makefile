
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

!else

debug_compiler_options = -OPtimize=1 -SIze -SHIft=Inline
debug_linker_options = 
lbgsh_options = 
libsuffix=r

!endif

##################################################################################################

libname = $(objdir)\sh2_$(libsuffix).lib

##################################################################################################

.ERASE
.EXTENSIONS:
.EXTENSIONS: .o .cpp .h .asm

##################################################################################################

.cpp:	$(cppdir)
.asm:	$(cppdir)
.o:	$(objdir)
.h:	$(hdir)

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

##################################################################################################

compiler_options = $(debug_compiler_options) -NOLOGO -CPu=sh2 -RTnext -ENAble_register -macsave=0 -ALIAS=ANSI

##################################################################################################

asm_options = -NOLOGO -CPu=sh2

##################################################################################################

link_options = -NOLOGO -FOrm=Binary -LISt -SHow=SY -LIBrary=$(libname) 
  
##################################################################################################

$(objdir)\9327_mod.hex : $(objdir)\LiveKnock.abs $(objdir)\stock.abs
	@echo Patch ROM...
	@copy /Y bin\orig_93270019.hex $^@
	@bin\elfpatch $^@ $[@
	@echo $(delimiter)	

##################################################################################################

$(objdir)\LiveKnock.abs : LiveMap.o AltMaps.o Hooks.o LiveKnock.o main.o F500.o ML02.o #FU03.o # Ignition.o crank.o ,P_Ignition/39000,P_crank/3C000
	@echo Linking $^@ ...
	@optlnk	-NOLOGO -LISt -SHow=SY -FOrm=Absolute -start=P_main/EB04,P_Hooks/2CC0,P/39000,B/FFFF8480,P_9D18/9D18 -LIBrary=$(libname) -OUtput="$^@" $<
	@echo $(delimiter)	

##################################################################################################

.cpp.o:
	@echo Compiling $[. ...
	@shcpp $(compiler_options) -Listfile="$(objdir)\$^&.lst" -SHow=SOurce -OBjectfile="$(objdir)\$^." $[@
	@echo $(delimiter)	

##################################################################################################

.asm.o:
	@echo Compiling $[. ...
	@asmsh $(asm_options) -List="$(objdir)\$^&.lst" -OBject="$(objdir)\$^." $[@
	@echo $(delimiter)	

##################################################################################################

$(objdir)\stock.abs : main.o F500.o	ML02.o FU03.o Ignition.o crank.o idle.o  BC06.o huge.o LibsFunc.o  Reset_init.o  atu02_ici0A.o c_9D18.o com.o #LiveMap.o AltMaps.o Hooks.o LiveKnock.o
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



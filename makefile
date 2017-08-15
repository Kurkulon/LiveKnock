
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

debug_compiler_options =  -OPtimize=1 -SIze 
debug_linker_options = 
lbgsh_options = 
libsuffix=d

!else

debug_compiler_options = -O3 -Otime --debug
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

compiler_options = $(debug_compiler_options) -NOLOGO -CPu=sh2 -RTnext -ENAble_register -macsave=0 -Goptimize

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

$(objdir)\LiveKnock.abs : LiveMap.o AltMaps.o Hooks.o LiveKnock.o # Ignition.o crank.o ,P_Ignition/39000,P_crank/3C000
	@echo Linking $^@ ...
	@optlnk	-NOLOGO -LISt -SHow=SY -FOrm=Absolute -start=P_Hooks/2CC0,P/39000,B/FFFF8480 -LIBrary=$(libname) -OUtput="$^@" $<
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
##################################################################################################

$(objdir)\stock.abs : Ignition.o crank.o idle.o F500.o FU03.o ML02.o
	@echo Linking $^@ ...
	@copy /Y $[@ $^@
	@rem optlnk	-NOLOGO -LISt -SHow=SY -FOrm=Binary -start=ROM/0,RAM/FFFF6000,HWREG/FFFFE400,P_Ignition/39000,P_crank/3C000,B/FFFF8480 -LIBrary=$(libname) -OUtput="$^@" $<
	@echo $(delimiter)	

##################################################################################################



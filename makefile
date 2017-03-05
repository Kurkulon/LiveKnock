
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

!ifeq version Debug

# -SIze -SPeed 

debug_compiler_options =  -OPtimize=1 
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

#	@call shv9420env.bat
##################################################################################################
# -PACK=1

compiler_options = $(debug_compiler_options) -CPu=sh2  -NOLOGO

#--asm -g -c  --thumb --diag_style=ide &
#	 --fpmode=std --feedback "$(objdir)\bootloader.fed" --diag_suppress=68,368,1299,3017 &
#	 --apcs=/interwork --no_depend_system_headers --reduce_paths -I$(libdir)\cpp

##################################################################################################

asm_options = -NOLOGO -CPu=sh2

##################################################################################################

# -start=A,B,E/400,C,D*:F:G/8000

link_options = -NOLOGO -FOrm=Binary -LISt -SHow=SY -LIBrary=$(libname) 
  
##################################################################################################

#dma_patch = 0x37900=bin\altmaps.bin, 0x3EC00=$(objdir)\livemap.bin, 0x3E800=$(objdir)\LiveKnock.bin, &
#		0x3E900=$(objdir)\LookupHiIgnMap.bin, 0x138=0,3,0xed,0x10, 0x324=0,3,0xec,0, 0x32C=0,3,0xee,0x30, &
#		0xD0F6=0x88,0x37,0x89, 0xD316=0x84,0x80, 0xD8D8=0,9, 0XE5A2=0X9A,0X6A, 0XE5E2=0,9, 0XE60E=0X9A,0X34, 0XE64E=0,9, 0XE67A=7,0X0B, &
#		0XEC28=0,3,0XE8,0X00

dma_patch = 0x37900=$(objdir)\altmaps.bin, &
			0x3EC00=$(objdir)\livemap.bin, &
			0x138=0,3,0xed,0x10, &
			0x324=0,3,0xec,0, &
			0x32C=0,3,0xee,0x30, &
			0XEC28=0,3,0XEE,0Xb0, &
			0xD0F6=0x88,0x37,0x89, &
			0xD316=0x84,0x80, &
			0xD8D8=0,9, &
			0XE5A2=0X9A,0X6A, 0XE5E2=0,9, &
			0XE60E=0X9A,0X34, 0XE64E=0,9, &
			0XE67A=7,0X0B

##################################################################################################

#live_map_patch =	0X1802E=0X4A,0X0B, 0X180AC=0,3,0XF0,0, &					#Tephra_Lookup_Axis_RPM25_LOAD30
#					0X181B4=0XFF,0XFF,0X84,0X28, 0X181BC=0XFF,0XFF,0X84,0X28	#Lookup_HiIgnMap

##################################################################################################

patch2 = 0x37900=bin\altmaps.bin, &
		0x3EC00=$(objdir)\livemap.bin, &
			0x138=0,3,0xed,0x10, &
			0x324=0,3,0xec,0, &
			0x32C=0,3,0xee,0x30, &
			0XEC28=0,3,0XEE,0XB0, &
			0xD0F6=0x88,0x37,0x89, &
			0xD316=0x84,0x80, &
			0xD8D8=0,9, &
			0XE5A2=0X9A,0X6A, 0XE5E2=0,9, &
			0XE60E=0X9A,0X34, 0XE64E=0,9, &
			0XE67A=7,0X0B, &
		0x3E800=$(objdir)\LiveKnock.bin, &
		0x3E900=$(objdir)\LookupHiIgnMap.bin, &
		0XFAA=0X50,0XD8, &
		0x7C68=0,3,0x90,0x42, 0,3,0x90,0x42, 0,3,0x90,0x42, 0,3,0x90,0x42, 0,3,0x90,0x42, 0,3,0x90,0x42, 0,3,0x90,0x42, 0,3,0x90,0x42, &
		0xA8B2=0x84,8,        &
		  0XF0D7=0X1E, 0X14340=0XFF,0XFF,0X84,0X24, 0X1802E=0X4A,0X0B, 0X180AC=0,3,0XF0,0, &
		0X181B4=0XFF,0XFF,0X84,0X28, 0X181BC=0XFF,0XFF,0X84,0X28

##################################################################################################
# $(objdir)\LiveKnock.bin $(objdir)\LookupHiIgnMap.bin 

$(objdir)\9327_mod.hex : $(objdir)\LiveKnock.abs 
	@echo Patch ROM...
	@copy /Y bin\orig_93270019.hex $^@
	@bin\elfpatch $^@ $[@
	@echo $(delimiter)	

##################################################################################################
# -start=P,C/3E800,D,B/FFFF8490
##################################################################################################

#$(objdir)\LiveMap.bin : LiveMap.o
#	@echo Linking $^@ ...
#	@optlnk	$(link_options) -start=P/3EC00 -OUtput="$^@" $[@
#	@optlnk	-NOLOGO -FOrm=Absolute -LIBrary=$(libname) $[@

##################################################################################################

$(objdir)\LiveKnock.abs : LiveKnock.o LiveMap.o AltMaps.o
	@echo Linking $^@ ...
	@optlnk	-NOLOGO -FOrm=Absolute -start=P/3E800,B/FFFF8490 -LIBrary=$(libname) -OUtput="$^@" $<
	@echo $(delimiter)	

#	@optlnk	$(link_options) -start=P/3E800,B/FFFF8490 -OUtput="$^@" $[@
##################################################################################################

#$(objdir)\LookupHiIgnMap.bin : LookupHiIgnMap.o
#	@echo Linking $^@ ...
#	@optlnk	$(link_options) -start=P/3E800 -OUtput="$^@" $[@

##################################################################################################

#$(objdir)\AltMaps.bin : AltMaps.o
#	@echo Linking $^@ ...
#	@optlnk	$(link_options) -start=C/37B00 -OUtput="$^@" $[@

##################################################################################################

#$(objdir)\93270019.bin : 93270019.o
#	@echo Linking $^@ ...
#	@optlnk	$(link_options) -start=C/0 -OUtput="$^@" $[@

##################################################################################################

.cpp.o:
	@echo Compiling $[. ...
	@shcpp $(compiler_options) -Listfile="$(objdir)\$^&.lst" -SHow=SOurce -OBjectfile="$(objdir)\$^." $[@
	@echo $(delimiter)	

#--depend="$(objdir)\$^&.d"  
##################################################################################################

.asm.o:
	@echo Compiling $[. ...
	@asmsh $(asm_options) -List="$(objdir)\$^&.lst" -OBject="$(objdir)\$^." $[@
	@echo $(delimiter)	

# -SHow=SOurce
##################################################################################################



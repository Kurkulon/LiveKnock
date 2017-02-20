@if NOT EXIST buildnum echo 0 >buildnum
@set /p buildnumvar=<buildnum
@set /a buildnumvar=buildnumvar+1 >nul
@echo %buildnumvar% >buildnum
@echo Build number  %buildnumvar%
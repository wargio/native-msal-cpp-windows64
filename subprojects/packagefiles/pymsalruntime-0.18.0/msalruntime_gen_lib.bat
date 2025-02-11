@echo off

if [%~1]==[] goto :noarch
if [%~2]==[] goto :nodllname

echo Arch: %~1
echo Name: %~2

echo LIBRARY %~2 > pymsalruntime\%~2.def
echo EXPORTS >> pymsalruntime\%~2.def

for /f "skip=19 tokens=4" %%A in ('dumpbin /exports pymsalruntime\%~2.dll') do echo %%A | findstr /V /R "^Dll" >> pymsalruntime\%~2.def
lib /NOLOGO /VERBOSE /def:pymsalruntime\%~2.def /out:pymsalruntime\%~2.lib /machine:%~1
goto :done

:noarch
echo Missing arg1 arch (ARM, ARM64, ARM64X, EBC, X64, X86)
goto :done

:nodllname
echo Missing arg2 dllname

:done


cd .

if "%1"=="" ("F:\00_Programs\MATLAB\R2023b\bin\win64\gmake"  -f wrapper.mk all) else ("F:\00_Programs\MATLAB\R2023b\bin\win64\gmake"  -f wrapper.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1
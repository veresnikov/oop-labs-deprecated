@echo off

set PROGRAM="%~1"
if %PROGRAM%=="" (
	echo Please specify path to the program
	exit /B 1
)

set TEMPOUTPUT="%TEMP%\output.txt"

echo %CD%
echo Test invalid argument
%PROGRAM% > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestInvalidArgument-Output.txt || goto :err

echo Test empty input byte
%PROGRAM% /'' > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestErrorConverting-Output.txt || goto :err

echo Test incorrect input
%PROGRAM% abcd > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestErrorConverting-Output.txt || goto :err

echo Test incorrect type input byte
%PROGRAM% 1.2 > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestErrorConverting-Output.txt || goto :err

echo Test unsupported range (input < 0)
%PROGRAM% -1 > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestErrorConverting-Output.txt || goto :err

echo Test unsupported range (input > 255)
%PROGRAM% 256 > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestErrorConverting-Output.txt || goto :err

echo Test lower range
%PROGRAM% 0 > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestLowerRange-Output.txt || goto :err

echo Test upper range
%PROGRAM% 255 > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestUpperRange-Output.txt || goto :err

echo Test result
%PROGRAM% 6 > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestResult-Output.txt || goto :err

echo All test passed
exit /B 0

:err
echo Test failed
exit /B 1
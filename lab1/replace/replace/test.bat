@echo off

set PROGRAM="%~1"
if %PROGRAM%=="" (
	echo Please specify path to the program
	exit /B 1
)

set TEMPRESULT="%TEMP%\result.txt"
set TEMPOUTPUT="%TEMP%\output.txt"

echo %CD%
echo Test invalid argument
%PROGRAM% > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestInvalidArgument-Output.txt || goto :err

echo Test invalid input filename
%PROGRAM% "" %TEMPRESULT% test test > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestInvalidInputFilename-Output.txt || goto :err

echo Test invalid output filename
%PROGRAM% %CD%\test-data\TestInvalidOutputFilename-Input.txt "" test test > %TEMPOUTPUT% 2>&1
fc %TEMPOUTPUT% %CD%\test-data\TestInvalidOutputFilename-Output.txt || goto :err

echo Test empty search string
%PROGRAM% %CD%\test-data\TestEmptySearchString-Input.txt %TEMPRESULT% "" test > %TEMPOUTPUT% 2>&1
fc %TEMPRESULT% %CD%\test-data\TestEmptySearchString-Output.txt || goto :err

echo Test empty replace string
%PROGRAM% %CD%\test-data\TestEmptyReplaceString-Input.txt %TEMPRESULT% " " "" > %TEMPOUTPUT% 2>&1
fc %TEMPRESULT% %CD%\test-data\TestEmptyReplaceString-Output.txt || goto :err

echo Test multiple occurrences
%PROGRAM% %CD%\test-data\TestMultipleOccurrences-Input.txt %TEMPRESULT% ma mama > %TEMPOUTPUT% 2>&1
fc %TEMPRESULT% %CD%\test-data\TestMultipleOccurrences-Output.txt || goto :err

echo Test equal search and replace
%PROGRAM% %CD%\test-data\TestEqualSearchAndReplace-Input.txt %TEMPRESULT% test test > %TEMPOUTPUT% 2>&1
fc %TEMPRESULT% %CD%\test-data\TestEqualSearchAndReplace-Output.txt || goto :err

echo Test phrase-to-phrase replacement
%PROGRAM% %CD%\test-data\TestPhraseToPhraseReplacement-Input.txt %TEMPRESULT% "test test" "42 42" > %TEMPOUTPUT% 2>&1
fc %TEMPRESULT% %CD%\test-data\TestPhraseToPhraseReplacement-Output.txt || goto :err

echo Test stress
echo Time start: %time%
%PROGRAM% %CD%\test-data\TestStress-Input.txt %TEMPRESULT% a BB > %TEMPOUTPUT% 2>&1
echo Time stop: %time%
fc %TEMPOUTPUT% %CD%\test-data\TestStress-Output.txt || goto :err

echo All test passed
exit /B 0

:err
echo Test failed
exit /B 1
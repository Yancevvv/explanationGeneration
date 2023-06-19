@echo off
set program=explanationGeneration.exe

echo. > results.txt
echo 01 - Simple expression >> results.txt
echo.  >> results.txt
%program% input1.xml output.txt >> results.txt
echo Input data: >> results.txt
type input1.xml >> results.txt
echo.  >> results.txt
echo Output data: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 02 - Function and operation increment >> results.txt
echo.  >> results.txt
%program% input2.xml output.txt >> results.txt
echo Input data: >> results.txt
type input2.xml >> results.txt
echo.  >> results.txt
echo Output data: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 03 - Function with multiple arguments >> results.txt
echo.  >> results.txt
%program% input3.xml output.txt >> results.txt
echo Input data: >> results.txt
type input3.xml >> results.txt
echo.  >> results.txt
echo Output data: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 04 - Logical operation and negation operation >> results.txt
echo.  >> results.txt
%program% input4.xml output.txt >> results.txt
echo Input data: >> results.txt
type input4.xml >> results.txt
echo.  >> results.txt
echo Output data: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 05 - Incorrect operation >> results.txt
echo Input data: >> results.txt
type input5.xml >> results.txt
echo.  >> results.txt
%program% input5.xml output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 06 - Invalid tag >> results.txt
echo Input data: >> results.txt
type input6.xml >> results.txt
echo.  >> results.txt
%program% input6.xml output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 07 - Invalid xml syntax >> results.txt
echo Input data: >> results.txt
type input7.xml >> results.txt
echo.  >> results.txt
%program% input7.xml output.txt >> results.txt

@echo off
REM DSA Judge - Windows Installation Script
REM Supports: Windows 10/11 with MinGW or MSYS2

echo ========================================
echo DSA Judge - Windows Installer
echo ========================================
echo.

REM Check for Python
python --version >nul 2>&1
if %errorlevel% neq 0 (
    echo ERROR: Python not found. Please install Python 3.8+ from python.org
    echo Make sure to check "Add Python to PATH" during installation.
    pause
    exit /b 1
)

echo Python found: 
python --version

REM Check for g++ (MinGW)
g++ --version >nul 2>&1
if %errorlevel% neq 0 (
    echo WARNING: g++ not found in PATH.
    echo Please install MinGW-w64 or MSYS2 and add to PATH.
    echo.
    echo MinGW-w64: https://www.mingw-w64.org/downloads/
    echo MSYS2:     https://www.msys2.org/
    echo.
    echo After installation, add the bin folder to PATH (e.g., C:\mingw64\bin)
    pause
)

echo.
echo Installing Python dependencies...
python -m pip install --upgrade pip
python -m pip install -e .

echo.
echo ========================================
echo Installation complete!
echo ========================================
echo.
echo To use DSA Judge:
echo   1. Run interactive mode: dsa-judge
echo   2. Or direct mode: dsa-judge -s submission.cpp -p .\problem -v
echo.
echo To generate test cases for a problem:
echo   cd LAB-01\R14-2\<problem>\dataset
echo   g++ -std=c++17 -O3 -static -s test_generator.cpp -o test_generator.exe
echo   test_generator.exe
echo.
echo To generate expected outputs:
echo   g++ -std=c++17 -O3 -static -s output_generator.cpp -o output_generator.exe
echo   output_generator.exe
echo.
pause
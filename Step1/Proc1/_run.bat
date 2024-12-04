@echo off
:: Directory containing the C files
set src_dir=D:\projects\WooSongUniv\GitHub\Codyssey_c\Step1\Proc1

:: Directory for output executables
set out_dir=D:\projects\WooSongUniv\GitHub\Codyssey_c\Step1\Proc1

:: Create output directory if it doesn't exist
if not exist "%out_dir%" mkdir "%out_dir%"

:: Compile each .c file in the source directory
for %%f in ("%src_dir%\*.c") do (
    set "filename=%%~nf"
    setlocal enabledelayedexpansion
    :: Extract the character after '_'
    for /f "tokens=2 delims=_." %%a in ("!filename!") do (
        set "newname=%%a"
        gcc %%f -o "%out_dir%\!newname!.exe"
        if !ERRORLEVEL! equ 0 (
            echo %%~nf.c compiled successfully as !newname!.exe.
        ) else (
            echo Error compiling %%~nf.c
        )
    )
    endlocal
)
pause
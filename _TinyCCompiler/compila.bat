@ECHO OFF

IF [%1]==[] (
   SET /p program=Executar o algoritmo: 
) ELSE (
   SET program=%1
)

CLS
TITLE %program%

C:\tcc\tcc.exe -run %program%.c

PAUSE

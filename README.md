***************************************************************************************************
Compilacion from terminal:

g++ main.cpp ResourceFile.cpp -o main

add standar C++11 (the minimum requirement for override):

g++ main.cpp ResourceFile.cpp -o main -std=c++11

****************************************************************************************************
Execution from:

.\main.exe

****************************************************************************************************
Compilation with Debug form terminal:

g++ main.cpp ResourceFile.cpp -o main -std=c++11 -g

O:

Linux o macOS (En Windows, ni CMD ni PowerShell expanden automáticamente *.cpp )
g++ *.cpp -o main.exe -std=c++11 -g

Para Windows en PowerShell
g++ (Get-ChildItem *.cpp | ForEach-Object { $_.Name }) -o main.exe -std=c++11 -g

****************************************************************************************************
Execution debug from terminal with GDB-GNU Debugger(depurador estándar de GNU para programas escritos en C, C++ y otros lenguajes compatibles.):

gdb main.exe
---------------------------------------------------------------------------------------------------
GDB:
break main          # pone un breakpoint al inicio de main()
run                 # ejecuta el programa
next                # avanza a la siguiente línea
step                # entra en funciones
print variable_name # imprime valor de variable
continue            # continúa hasta el siguiente breakpoint
quit                # sale de gdb
---------------------------------------------------------------------------------------------------
****************************************************************************************************
Debug setup in VSC:
---------------------------------------------------------------------------------------------------
add debug configuration

C/C++:g++.exe build and debug active file preLaunchTask:C/C++:g++.exe build active file

Genera los archivos:

\.vscode\task.json
\.vscode\launch.json


//****************************************************************************************************

# The-Operating-System-Shell
This is a project for the class ECSE 427/COMP 310
I used mimi.cs.mcgill.ca to test it

## Compiling the shell
  ### Compiling manualy 
  ```bash
  gcc -c shell.c interpreter.c shellmemory.c kernel.c cpu.c pcb.c ram.c
  gcc -o mykernel shell.o interpreter.o shellmemory.o kernel.o cpu.o pcb.o ram.o
  ```
  ### Compiling with make file
  ```bash
  make
  ```
## Running the shell
```bash
./mysh
```
## The promtline
```bash
Kernel 1.0 loaded!
Welcome to the Irmak's shell!
Shell version 2.0 Updated February 2020
$
```
## Testing Shell
```bash
./mysh < testfile.txt
```
## Commands:
  * **help**: Displays all the commands
  * **quit**: Exits / terminates the shell with “Bye!”
  * **set** <VAR> <STRING> : Assigns a value to shell memory
  * **print** <VAR> : Prints the STRING assigned to VAR
  * **run** SCRIPT.TXT : Executes the file SCRIPT.TXT
  * **exec** <P1> <P2> <P3> : Executes concurrent programs


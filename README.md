# The-Operating-System-Shell
This is a project for the class ECSE 427/COMP 310


## Compiling the shell
  ### Compiling manualy 
  ```bash
  gcc -c shell.c interpreter.c shellmemory.c
  gcc -o mysh shell.o interpreter.o shellmemory.o
  ```
  ### Compiling the shell with make file
  ```bash
  make
  ```
## Running the shell
```bash
./mysh
```
## The promtline
```bash
Welcome to the Irmak's shell!
Version 1.0 Created January 2020
$
```
## Testing Shell
```bash
./mysh < testfile.txt
```

#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include "shellmemory.h"
#include "shell.h"
#include "pcb.h"
#include "kernel.h"
#include "cpu.h"
#include "ram.h"

int interpreter(char *words[], int size);
int help();
int quit();
int set(char *words[]);
int printKey(char *words[]);
int runFile(char *fileName);
int exec(char *words[], int size);

#define INVALID_COMMAND 100
#define WRONG_NUMBER_OF_ARGUMENTS 101
#define QUIT_SHELL 102
#define MEMORY_EXCEED 103
#define VARIABLE_DOES_NOT_EXISTS 104
#define FILE_NOT_FOUND 105
#define RAM_MEMORY_EXCEED 106

#endif //INTERPRETER_H_
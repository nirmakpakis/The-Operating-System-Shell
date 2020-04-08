#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include "shellmemory.h"
#include "shell.h"
#include "pcb.h"
#include "cpu.h"
#include "kernel.h"
#include "common.h"

int interpreter(char *words[], int size);
int help();
int quit();
int set(char *words[]);
int printKey(char *words[]);
int runFile(char *fileName);
int exec(char *words[], int size);

#endif //INTERPRETER_H_
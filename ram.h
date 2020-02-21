#ifndef RAM_H_
#define RAM_H_
#include "shellmemory.h"
#include "interpreter.h"
#include "shell.h"
#include "pcb.h"
#include "kernel.h"
#include "cpu.h"

int addToRAM(FILE *file, int *start, int *end);
void clearRAM();
char *getInstructionFromRAM(int IP);
void printRAM();
extern char *ram[1000];
#endif //RAM_H_
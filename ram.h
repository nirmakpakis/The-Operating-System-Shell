#ifndef RAM_H_
#define RAM_H_
#include "shell.h"
#include "common.h"

int addToRAM(FILE *file, int *start, int *end);
void clearRAM();
void printRAM();

extern char *ram[40];

#endif //RAM_H_
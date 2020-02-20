#ifndef SHELLMEMORY_H_
#define SHELLMEMORY_H_
#include "interpreter.h"
#include "shell.h"
#include "pcb.h"
#include "kernel.h"
#include "cpu.h"
#include "ram.h"

#define MEMORY_SIZE 1000

int get(char *key);
int insert(char *key, char *value);
void printMemory();

#endif //SHELLMEMORY_H_
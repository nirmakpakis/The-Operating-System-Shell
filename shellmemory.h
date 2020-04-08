#ifndef SHELLMEMORY_H_
#define SHELLMEMORY_H_
#include "shell.h"
#include "common.h"

#define MEMORY_SIZE 1000

int get(char *key);
int insert(char *key, char *value);
void printMemory();

#endif //SHELLMEMORY_H_
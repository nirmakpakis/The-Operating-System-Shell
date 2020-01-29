#ifndef SHELLMEMORY_H_
#define SHELLMEMORY_H_
#include "interpreter.h"
#include "shell.h"

#define MEMORY_SIZE 1000

typedef struct node
{
    char *key;
    char *value;
} node;

int get(char *key);
int insert(char *key, char *value);
void printMemory();

#endif //SHELLMEMORY_H_
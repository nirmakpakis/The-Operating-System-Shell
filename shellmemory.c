/**
 *
 * @author Irmak Pakis
 * @dateCreated  29th January 2020
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shellmemory.h"

typedef struct node
{
    char *key;
    char *value;
} node;

node memory[MEMORY_SIZE] = {0};
int memoryIndex = 0;

//Get value
int get(char *key)
{
    for (int i = 0; i < memoryIndex; i++)
    {
        if (strcmp(memory[i].key, key) == 0)
        {
            printf("%s\n", strdup(memory[i].value));
            return 0;
        }
    }
    return VARIABLE_DOES_NOT_EXISTS;
}

// Add node
int insert(char *key, char *value)
{
    if (memoryIndex > MEMORY_SIZE)
    {
        return MEMORY_EXCEED;
    }
    for (int i = 0; i < memoryIndex; i++)
    {
        if (strcmp(memory[i].key, key) == 0)
        {
            memory[i].value = strdup(value);
            return 0;
        }
    }
    node p1 = {p1.key = key, p1.value = value};
    memory[memoryIndex] = p1;
    memoryIndex++;
    return 0;
}

void printMemory()
{
    for (int i = 0; i < memoryIndex; i++)
    {
        printf("(%s,%s)", strdup(memory[i].key), strdup(memory[i].value));
        printf("\n");
    }
}

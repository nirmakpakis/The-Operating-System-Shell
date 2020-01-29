/**
* Nihal Irmak Pakis
* 260733837
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char *key;
    char *value;
} node;

node memory[1000] = {0};
int memoryIndex = 0;

//Get value
void get(char *key)
{
    for (int i = 0; i < memoryIndex; i++)
    {
        if (strcmp(memory[i].key, key) == 0)
        {
            printf("%s\n", strdup(memory[i].value));
            return;
        }
    }
    printf("ERROR: Variable does not exist\n");
    return;
}

// Add node
void insert(char *key, char *value)
{
    for (int i = 0; i < memoryIndex; i++)
    {
        if (strcmp(memory[i].key, key) == 0)
        {
            memory[i].value = strdup(value);
            return;
        }
    }
    node p1 = {p1.key = key, p1.value = value};
    memory[memoryIndex] = p1;
    memoryIndex++;
    return;
}

void printMemory()
{
    for (int i = 0; i < memoryIndex; i++)
    {
        printf("(%s,%s)", strdup(memory[i].key), strdup(memory[i].value));
        printf("\n");
    }
}

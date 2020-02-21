/**
 *
 * @author Irmak Pakis
 * @dateCreated  18th February 2020
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ram.h"

char *ram[1000];

int addToRAM(FILE *file, int *start, int *end)
{
    int i = 0;
    while (ram[i] != NULL && i < 1000)
        i++;

    if (i == 1000)
        return RAM_MEMORY_EXCEED;

    *start = i;

    char line[256];

    while (fgets(line, sizeof(line), file) && i < 1000)
    {
        ram[i] = (char *)malloc(sizeof(char) * 10000);
        strcpy(ram[i], line);
        i = i + 1;
    }

    if (i == 1000)
        return RAM_MEMORY_EXCEED;

    *end = i - 1;

    return 0;
}

char *getInstructionFromRAM(int IP)
{
    return ram[IP];
}

void clearRAM()
{
    for (int i = 0; i < 1000; i++)
    {
        ram[i] = NULL;
    }
}

void printRAM()
{
    printf("RAM:\n");
    int i = 0;
    while (ram[i] != NULL)
    {
        printf("%s\n", ram[i]);
        i++;
    }
}
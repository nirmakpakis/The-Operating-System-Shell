/**
 *
 * @author Irmak Pakis
 * @dateCreated  18th February 2020
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cpu.h"

CPU *cpu = NULL;

void initCPU()
{
    cpu = (CPU *)malloc(sizeof(CPU));
    cpu->quanta = 0;
}

void fillCPU(int IP, int quanta)
{
    cpu->IP = IP;
    cpu->IR = getInstructionFromRAM(IP);
    cpu->quanta = quanta;
}

void run(int quanta)
{
    while (quanta-- > 0)
    {
        parse(cpu->IR);
    }
}

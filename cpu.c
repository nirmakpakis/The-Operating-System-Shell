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

CPU *cpu_instance = NULL;

void clearCPU()
{
    cpu_instance = (CPU *)malloc(sizeof(CPU));
    cpu_instance->quanta = 0;
    cpu_instance->IP = 0;
}

void fillCPU(int IP, int quanta)
{
    cpu_instance->IP = IP;
    cpu_instance->IP = (char *)malloc(sizeof(char) * 10000);
    strcpy(cpu_instance->IP, getInstructionFromRAM(cpu_instance->IP));
    cpu_instance->quanta = quanta;
}

void run(int quanta, int endOfFile)
{
    while (quanta-- > 0)
    {
        parse(cpu_instance->IR);
        cpu_instance->IP = cpu_instance->IP + 1;
        if (cpu_instance->IP > endOfFile)
        {
            printf("This program terminated!");
            cpu_instance->IP = cpu_instance->IP - 1;
            break;
        }
        else
        {
            strcpy(cpu_instance->IR, ram[cpu_instance->IP]);
            cpu_instance->quanta = cpu_instance->quanta - 1;
        }
    }
}

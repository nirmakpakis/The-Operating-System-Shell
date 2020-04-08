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

int run(int quanta, PCB *pcb)
{
    while (quanta-- > 0)
    {
        int nextPosition = pcb->pageTable[pcb->PC_page] * FRAMESIZE + pcb->PC_offset;
        updateCPU(quanta, nextPosition);
        int errorCode = updatePCB(1, pcb);
        if (errorCode != END_OF_FILE)
        {
            parse(cpu_instance->IR);
        }
        else
        {
            cpu_instance->quanta = 0;
            return END_OF_FILE;
        }
    }
    cpu_instance->quanta = 0;
    return 0;
}

void updateCPU(int quanta, int nextPosition)
{
    cpu_instance->quanta = quanta;
    cpu_instance->IP = nextPosition;
    strcpy(cpu_instance->IR, ram[nextPosition]);
    cpu_instance->offset = nextPosition % 4;
}

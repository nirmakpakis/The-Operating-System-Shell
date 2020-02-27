/**
 *
 * @author Irmak Pakis
 * @dateCreated  18th February 2020
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kernel.h"

int main()
{
    clearRAM();
    clearReadyQueue();
    clearCPU();

    printf("Kernel 1.0 loaded!\n");
    shellUI();
}

int myinit(char *filename)
{
    int *start = malloc(sizeof(int));
    int *end = malloc(sizeof(int));
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        return FILE_NOT_FOUND;
    }

    // Add file to ram
    addToRAM(file, start, end);

    // make pcb
    PCB *pcb = makePCB(*start, *end);

    // add to ready queue
    addToReadyQueue(pcb);

    fclose(file);
    free(start);
    free(end);
}

void addToReadyQueue(PCB *pcb)
{
    push(pcb);
}

void scheduler()
{
    while (!readyQueueIsEmpty())
    {
        if (cpu_instance->quanta == 0)
        {
            PCB *pcb = pop();
            cpu_instance->IP = pcb->PC;
            strcpy(cpu_instance->IR, ram[cpu_instance->IP]);
            cpu_instance->quanta = 2;
            run(2, pcb->end);
            pcb->PC = cpu_instance->IP;
            if (pcb->PC != pcb->end)
            {
                addToReadyQueue(pcb);
            }
        }
    }
}

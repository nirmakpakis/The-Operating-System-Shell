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
    //clean cpus

    printf("Kernel 1.0 loaded!\n");
    shellUI();
}

int myinit(char *filename)
{
    int *start = malloc(sizeof(int));
    int *end = malloc(sizeof(int));
    FILE *file = fopen(filename, "r");

    // Add file to ram
    int errorCode = addToRAM(file, start, end);

    // make pcb
    PCB *pcb = makePCB(*start, *end);

    // add to ready queue
    addToReadyQueue(pcb);

    // // maybe yes maybe no
    // fclose(file);
    // free(start);
    // free(end);
}

void addToReadyQueue(PCB *pcb)
{
    insertNode(pcb);
}

void scheduler()
{
    while (!readyQueueIsEmpty())
    {
        //Check if quanta is finished
        if (cpu->quanta == 0)
        {
            PCB *pcb = pop();
            fillCPU(pcb->PC, 2);
            run(2);
            pcb->PC = cpu->IP;
            addToReadyQueue(pcb);
        }
        else
        {
            return;
        }
    }
}

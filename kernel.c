/**
 *
 * @author Irmak Pakis
 * @dateCreated  18th February 2020
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include "kernel.h"

int main()
{
    printf("Kernel 1.1 loaded!\n");

    int errorCode = 0;
    boot();
    errorCode = shellUI();
    return errorCode;
}

int myinit(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        return FILE_NOT_FOUND;
    }

    // make pcb
    PCB *pcb = makePCB(file, filename);

    // Add file to ram
    int errorcode = launcher(file, filename, pcb);

    if (errorcode == 0)
    {
        return FILE_NOT_FOUND;
    }

    // add to ready queue
    addToReadyQueue(pcb);

    return 0;
}

void addToReadyQueue(PCB *pcb)
{
    push(pcb);
}

void scheduler()
{
    int quanta = 2;
    while (!readyQueueIsEmpty())
    {
        if (cpu_instance->quanta == 0)
        {
            PCB *pcb = pop();
            if (pcb->pageTable[pcb->PC_page] == PAGE_NOT_INITIALIZED)
            {
                pageFault(pcb);
            }
            else
            {
                int errorCode = run(quanta, pcb);
                if (errorCode != END_OF_FILE)
                {
                    addToReadyQueue(pcb);
                }
            }
        }
    }
}

void clearBackingStore()
{
    DIR *dir = opendir("BackingStore");

    if (dir)
    {
        system("rm -rf BackingStore");
    }
    system("mkdir BackingStore");
    return;
}

void boot()
{
    clearRAM();
    clearReadyQueue();
    clearCPU();
    clearBackingStore();
    return;
}

void pageFault(PCB *pcb)
{
    int currentPage = pcb->PC_page;
    if (currentPage > pcb->pages_max - 1)
    {
        return;
    }
    else
    {
        char *filePath = malloc(strlen("BackingStore/") + strlen(pcb->fileName) + 1);
        strcpy(filePath, "BackingStore/");
        strcat(filePath, pcb->fileName);
        FILE *file_copy = fopen(filePath, "r");

        if (findFrame() != -1)
        {
            int emptyFrameNumber = findFrame();
            loadPage(currentPage, file_copy, emptyFrameNumber);
            pcb->pageTable[currentPage] = emptyFrameNumber;
            pcb->PC_offset = 0;
            addToReadyQueue(pcb);
        }
        else
        {
            int victimFrameNumber = findVictim(pcb);
            updateVictimsPageTable(victimFrameNumber);
            loadPage(currentPage, file_copy, victimFrameNumber);
            pcb->pageTable[currentPage] = victimFrameNumber;
            pcb->PC_offset = 0;
            addToReadyQueue(pcb);
        }

        fclose(file_copy);
    }
}

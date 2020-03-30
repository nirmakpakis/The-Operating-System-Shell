#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include "memorymanager.h"

int launcher(FILE *p, char name[])
{

    //Copy the entire file into the backing store.
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "cp %s BackingStore/", name);
    system(buffer);

    //Close the file pointer pointing to the original file
    fclose(p);

    //Open the file in the backing store
    FILE *file = fopen(name, "r");

    // make pcb and add to ready queue
    PCB *pcb = makePCB(file, -1);
    addToReady(pcb);

    // figure our the total number of pages
    int totalPages = countTotalPages(file);

    for (int i = 0; i < 2; i++)
    {
        if (totalPages < 2 && i == 1)
        {
            break;
        }
        //find an empty frame
        int emptyFrameNumber = findFrame(file);

        if (emptyFrameNumber == -1)
        {
            emptyFrameNumber == findVictim(pcb);
        }

        //load the page into ram
        loadPage(i, file, emptyFrameNumber);

        //update pbc's page table
        updatePageTable(pcb, i, emptyFrameNumber, -1);
    }

    pcb->pages_max = totalPages;
}

int countTotalPages(FILE *file)
{
    FILE *f = fdopen(dup(fileno(file)), "r");
    int count = 1;
    int ch = 0;
    while (!feof(f))
    {
        ch = fgetc(f);
        if (ch == '\n')
        {
            count++;
        }
    }

    if (count % 4 != 0)
        return count / 4 + 1;
    else
        return count / 4;
}

void loadPage(int pageNumber, FILE *file, int frameNumber)
{
    int index_BackingStore = pageNumber * 4;
    int maxIndex_BackingStore = index_BackingStore + 4;
    int index_RAM = frameNumber * 4;

    char line[256];
    int i = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (i >= index_BackingStore && i < maxIndex_BackingStore)
        {
            ram[i] = (char *)malloc(sizeof(char) * 10000);
            strcpy(ram[index_RAM], line);
            index_RAM++;
            index_BackingStore++;
        }
        i++;
    }

    fclose(file);
}

int findFrame()
{
    for (int i = 0; i < 40; i += 4)
    {
        if (ram[i] == NULL)
        {
            return i / 4;
        }
    }
    return -1;
}

int findVictim(PCB *pcb)
{
    srand(time(0));
    int randomFrameNumber = rand() % 10;
    while (true)
    {
        if (frameNumberDoesNotBelongToPCB(randomFrameNumber, pcb))
        {
            return randomFrameNumber;
        }
        randomFrameNumber++;
    }
    return -1;
}

bool frameNumberDoesNotBelongToPCB(int frameNumber, PCB *pcb)
{
    for (int i = 0; i < 10; i++)
    {
        if (pcb->pageTable[i] == frameNumber)
            return false;
    }
    return true;
}

int updatePageTable(PCB *pcb, int pageNumber, int frameNumber, int victimFrame)
{
    pcb->pageTable[pageNumber] = frameNumber;
}

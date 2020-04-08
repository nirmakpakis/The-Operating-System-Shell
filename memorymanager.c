#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "memorymanager.h"

int launcher(FILE *p, char *fileName, PCB *pcb)
{
    //Copy the entire file into the backing store.
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "cp %s BackingStore/", fileName);
    system(buffer);

    //close the file
    fclose(p);

    //Open the file from backing store
    char *filePath = malloc(strlen("BackingStore/") + strlen(pcb->fileName) + 1);
    strcpy(filePath, "BackingStore/");
    strcat(filePath, pcb->fileName);
    FILE *file = fopen(filePath, "r");

    if (file == NULL)
    {
        printf("file is not backedup!\n");
        return 0;
    }

    // figure our the total number of pages
    int totalPages = countTotalPages(file);

    for (int i = 0; i < 2; i++)
    {
        if (totalPages < 2 && i == 1)
        {
            return 1;
        }
        //find an empty frame
        int emptyFrameNumber = findFrame();

        //load the page into ram
        loadPage(i, file, emptyFrameNumber);

        //update pbc's page table
        updatePageTable(pcb, i, emptyFrameNumber, -1);
    }

    return 1;
}

int countTotalPages(FILE *f)
{
    rewind(f);
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
    rewind(file);
    int index_BackingStore = pageNumber * 4;
    int maxIndex_BackingStore = index_BackingStore + 4;
    int index_RAM = frameNumber * 4;

    char line[256];
    int i = 0;
    while (fgets(line, sizeof(line), file) && (line != '/0' || line != '/n' || line != '/r' || line != NULL))
    {
        if (i >= index_BackingStore && i < maxIndex_BackingStore)
        {
            ram[index_RAM] = (char *)malloc(sizeof(char) * 10000);
            strcpy(ram[index_RAM], line);
            index_RAM++;
            index_BackingStore++;
        }
        i++;
    }
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
    if (victimFrame == -1)
    {
        pcb->pageTable[pageNumber] = frameNumber;
    }
    else
    {
        pcb->pageTable[pageNumber] = victimFrame;
    }
}

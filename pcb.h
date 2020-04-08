#ifndef PCB_H_
#define PCB_H_
#include <stdbool.h>
#include "common.h"

typedef struct pcb_object
{
    // Program counter = PC_frame + PC_offset
    int PC;
    // Which Page we are in
    int PC_page;
    // Where we are in the page
    int PC_offset;
    // Total number of pages
    int pages_max;
    // Filename
    char *fileName;
    // end
    int end;
    // Where the shows which frames the pcb's pages stored
    int pageTable[10];
} PCB;

PCB *makePCB(FILE *file, char *filename);
void clearReadyQueue();
bool readyQueueIsEmpty();
void push(PCB *pcb);
PCB *pop();
void printReadyQueue();
void initializePageTable(int pageTable[]);
int updatePCB(int quanta, PCB *pcb);
int countTotalLines(FILE *f);

#endif //PCB_H_
#ifndef PCB_H_
#define PCB_H_
#include <stdbool.h>
#include "common.h"

typedef struct pcb_object
{
    int PC;
    int PC_page;
    int PC_offset;
    int pages_max;
    char *fileName;
    int end;
    int pageTable[10];
} PCB;

PCB *makePCB(FILE *file, char *filename);
void clearReadyQueue();
bool readyQueueIsEmpty();
void push(PCB *pcb);
PCB *pop();
void initializePageTable(int pageTable[]);
int updatePCB(int quanta, PCB *pcb);
int countTotalLines(FILE *f);

#endif //PCB_H_
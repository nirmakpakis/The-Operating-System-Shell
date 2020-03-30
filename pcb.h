#ifndef PCB_H_
#define PCB_H_
#include <stdbool.h>

typedef struct pcb_object
{
    int PC;
    int start;
    int end;
    int pageTable[10];
    int PC_page;
    int PC_offset;
    int pages_max;
} PCB;

PCB *makePCB(int start, int end);
void clearReadyQueue();
bool readyQueueIsEmpty();
void push(PCB *pcb);
PCB *pop();

#endif //PCB_H_
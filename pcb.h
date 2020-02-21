#ifndef PCB_H_
#define PCB_H_
#include <stdbool.h>

typedef struct pcb_object
{
    int PC;
    int start;
    int end;
} PCB;

PCB *makePCB(int start, int end);
void clearReadyQueue();
bool readyQueueIsEmpty();
void push(PCB *);
PCB *pop();

#endif //PCB_H_
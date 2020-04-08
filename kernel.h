#ifndef KERNAL_H_
#define KERNAL_H_

#include <stdbool.h>
#include "shell.h"
#include "cpu.h"
#include "pcb.h"
#include "ram.h"
#include "memorymanager.h"
#include "common.h"

int myinit(char *filename);
void addToReadyQueue(PCB *pcb);
void scheduler();
void clearBackingStore();
void boot();
void pageFault(PCB *pcb);
bool frameNumberBelongsToPCB(int frameNumber, PCB *pcb);

#endif //KERNAL_H_
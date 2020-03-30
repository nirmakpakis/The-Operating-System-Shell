#ifndef KERNAL_H_
#define KERNAL_H_
#include "shellmemory.h"
#include "interpreter.h"
#include "shell.h"
#include "pcb.h"
#include "ram.h"

int myinit(char *filename);
void addToReadyQueue(PCB *pcb);
void scheduler();
void boot();
void clearBackingStore();

#endif //KERNAL_H_
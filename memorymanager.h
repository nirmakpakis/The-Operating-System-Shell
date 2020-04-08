#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include "pcb.h"
#include "ram.h"
#include "common.h"

int launcher(FILE *p, char *fileName, PCB *pcb);
int countTotalPages(FILE *f);
void loadPage(int pageNumber, FILE *file, int frameNumber);
int findFrame();
int findVictim(PCB *pcb);
bool frameNumberDoesNotBelongToPCB(int frameNumber, PCB *pcb);
int updatePageTable(PCB *pcb, int pageNumber, int frameNumber, int victimFrame);

#endif //MEMORYMANAGER_H_
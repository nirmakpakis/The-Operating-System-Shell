#ifndef CPU_H_
#define CPU_H_

#include "shell.h"
#include "ram.h"
#include "pcb.h"
#include "common.h"

typedef struct cpu_object
{
    // instruction pointer
    int IP;
    // instruction register (the command)
    char IR[1000];
    // runtime
    int quanta;
    // Offset
    int offset;
} CPU;

void clearCPU();
int run(int quanta, PCB *pcb);
void updateCPU(int quanta, int nextPosition);

extern CPU *cpu_instance;

#endif //CPU_H_
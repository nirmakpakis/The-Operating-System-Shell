#ifndef CPU_H_
#define CPU_H_
#include "shellmemory.h"
#include "interpreter.h"
#include "shell.h"
#include "pcb.h"
#include "kernel.h"
#include "ram.h"

typedef struct cpu_object
{
    int IP;
    char IR[1000];
    int quanta;
} CPU;

extern CPU *cpu = NULL;

void initCPU();
void run(int quanta);
void fillCPU(int IP, int quanta);

#endif //CPU_H_
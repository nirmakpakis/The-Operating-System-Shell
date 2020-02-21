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

void clearCPU();
void run(int quanta, int endOfFile);

extern CPU *cpu_instance;

#endif //CPU_H_
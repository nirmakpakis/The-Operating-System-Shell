#ifndef SHELL_H_
#define SHELL_H_
#include "shellmemory.h"
#include "interpreter.h"
#include "pcb.h"
#include "kernel.h"
#include "cpu.h"
#include "ram.h"

int parse(char ui[]);
int printShell();

#endif //SHELL_H_